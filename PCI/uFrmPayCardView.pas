unit uFrmPayCardView;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.OleCtrls, SHDocVw, acWebBrowser, Vcl.ExtCtrls, sPanel,
  uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls,
  sStatusBar, uDImages, Vcl.StdCtrls, sButton, acPNG, acImage, HTMLabel, uRoomerForm;

type
  TFrmPayCardView = class(TfrmBaseRoomerDialogForm)
    pnlHead: TsPanel;
    pnlClient: TsPanel;
    browser: TsWebBrowser;
    lblPleaseRead: THTMLabel;
    imgWarning: TsImage;
    procedure btnOKClick(Sender: TObject);
  private
    { Private declarations }
    FHotelId: String;
    FUsername: String;
    FReservation: Integer;
    FConfirmed: boolean;
    procedure SetHotelId(const Value: String);
    procedure SetUserName(const Value: String);
    procedure SetReservation(const Value: Integer);
    procedure GoToUri(uri: String);
    function openLogin(var userName, password: string): boolean;
  protected
    procedure DoShow; override;
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
  public
    { Public declarations }
    property UserName : String read FUsername write SetUserName;
    property HotelId : String read FHotelId write SetHotelId;
    property Reservation : Integer read FReservation write SetReservation;
  end;

procedure ShowPayCardInformation(Reservation: Integer; openContract: integer);

implementation

{$R *.dfm}

uses uG,
     RoomerLoginForm,
     uD,
     uUtils,
     cmpRoomerDataSet,
     PrjConst,
     uActivityLogs,
     uFrmOptInMessage;

procedure ShowPayCardInformation(Reservation: Integer; openContract: integer);
var _FrmPayCardView : TFrmPayCardView;
begin
  if (openContract = 1) then
  begin
    _FrmPayCardView := TFrmPayCardView.Create(nil);
    try
      _FrmPayCardView.Reservation := Reservation;
      _FrmPayCardView.ShowModal;
    finally
      _FrmPayCardView.free;
    end;
  end else
    OpenOptInDialog(OITPCI);
end;

{ TFrmPayCardView }

function TFrmPayCardView.openLogin(var userName, password : string) : boolean;
var
  hotelcode: string;
begin
  hotelcode := g.qhotelCode;
  result := (AskUserForCredentials(userName, password, hotelCode, '', 7) in cLoginFormSuccesfull);
end;

procedure TFrmPayCardView.GoToUri(uri : String);
var Flags: OleVariant;
begin
//  Flags := 'navNoHistory,navNoReadFromCache,navNoWriteToCache';
  Flags:=4;
  browser.Navigate(uri, Flags);
end;


procedure TFrmPayCardView.btnOKClick(Sender: TObject);
var
  gUserName, gPassword : String;
begin
  if openLogin(gUserName, gPassword) then
  begin
    AddReservationActivityLog(gUsername,
                              Reservation,
                              0,
                              VIEW_PAY_CARD,
                              '',
                              '',
                              '');
    UserName := gUserName;
    HotelId := g.qHotelCode;
    FConfirmed := true;
    RefreshData;
  end;

end;

procedure TFrmPayCardView.DoLoadData;
var uri : String;
    iFrameUri : String;
    rSet : TRoomerDataSet;
    xml : String;
    iViews : Integer;
    sTemp : String;
begin
  inherited;
  if not FConfirmed then
  begin
    xml := d.roomerMainDataSet.downloadUrlAsString(  d.roomerMainDataSet.RoomerUri + 'resapi/token/costs/' + inttostr(Reservation));
    rSet := d.roomerMainDataSet.ActivateNewDataset(xml);
    iViews := 0;
    rSet.First;
    if NOT rSet.Eof then
      iViews := rSet['VIEWS'];
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{PLEASE_NOTE}', GetTranslatedText('PCI_VIEW_Warning_PleaseNote'));
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{CHARGE_PER_VIEW}', GetTranslatedText('PCI_VIEW_Warning_ChargePerView'));
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{SECURITY_CODE_ONCE_VISIBLE}', GetTranslatedText('PCI_VIEW_Warning_SecurityCodeOnceVisible'));
    sTemp := ReplaceString(GetTranslatedText('PCI_VIEW_Warning_NumberOfViews'), '{VIEWS}', inttostr(iViews));
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{NUMBER_OF_VIEWS}', sTemp);
  end
  else
  begin
    uri := d.roomerMainDataSet.RoomerUri + format('resapi/bookings/%d/paycarddisplayuri', [FReservation]);

    // Get Token via webservice
    iFrameUri := d.roomerMainDataSet.downloadUrlAsString(uri);
    GoToUri(iFrameUri);
  end;
end;

procedure TFrmPayCardView.DoShow;
begin
  inherited;
  btnOK.ModalResult := 0;
end;

procedure TFrmPayCardView.DoUpdateControls;
begin
  inherited;

  if FConfirmed then
    DialogButtons := [mbClose]
  else
    DialogButtons := mbOKCancel;

  AutoSize := not FConfirmed;
  pnlHead.Visible := not FConfirmed;
  browser.visible := FConfirmed;
end;

procedure TFrmPayCardView.SetHotelId(const Value: String);
begin
  FHotelId := Value;
end;

procedure TFrmPayCardView.SetReservation(const Value: Integer);
begin
  FReservation := Value;
end;

procedure TFrmPayCardView.SetUserName(const Value: String);
begin
  FUsername := Value;
end;

end.
