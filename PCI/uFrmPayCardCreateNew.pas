unit uFrmPayCardCreateNew;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.OleCtrls, SHDocVw, acWebBrowser, Vcl.ExtCtrls, sPanel,
  uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls,
  sStatusBar, uDImages, Vcl.StdCtrls, sButton, acPNG, acImage, HTMLabel, uRoomerForm;

type
  TFrmPayCardCreateNew = class(TfrmBaseRoomerDialogForm)
    pnlHead: TsPanel;
    lblPleaseRead: THTMLabel;
    imgWarning: TsImage;
    procedure btnOKClick(Sender: TObject);
  private
    { Private declarations }
    FHotelId: String;
    FUsername: String;
    FReservation: Integer;
    FConfirmed: boolean;
    FRoomReservation: Integer;
    procedure SetHotelId(const Value: String);
    procedure SetUserName(const Value: String);
    procedure SetReservation(const Value: Integer);
    procedure GoToUri(uri: String);
    function openLogin(var userName, password: string): boolean;
    procedure SetRoomReservation(const Value: Integer);
  protected
    procedure DoShow; override;
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
  public
    { Public declarations }
    property UserName : String read FUsername write SetUserName;
    property HotelId : String read FHotelId write SetHotelId;
    property Reservation : Integer read FReservation write SetReservation;
    property RoomReservation : Integer read FRoomReservation write SetRoomReservation;
  end;

procedure CreatePayCardInformation(Reservation: Integer; RoomReservation : Integer; openContract: integer);

implementation

{$R *.dfm}

uses uG,
     RoomerLoginForm,
     uD,
     uUtils,
     cmpRoomerDataSet,
     PrjConst,
     uActivityLogs,
     uFrmOptInMessage,
     ShellApi;

procedure CreatePayCardInformation(Reservation: Integer; RoomReservation : Integer; openContract: integer);
var _FrmPayCardCreateNew : TFrmPayCardCreateNew;
begin
  if (openContract = 1) then
  begin
    _FrmPayCardCreateNew := TFrmPayCardCreateNew.Create(nil);
    try
      _FrmPayCardCreateNew.Reservation := Reservation;
      _FrmPayCardCreateNew.RoomReservation := RoomReservation;
      _FrmPayCardCreateNew.ShowModal;
    finally
      _FrmPayCardCreateNew.free;
    end;
  end else
    OpenOptInDialog(OITPCI);
end;

{ TFrmPayCardCreateNew }

function TFrmPayCardCreateNew.openLogin(var userName, password : string) : boolean;
var
  hotelcode: string;
begin
  hotelcode := g.qhotelCode;
  result := (AskUserForCredentials(userName, password, hotelCode, '', 7) in cLoginFormSuccesfull);
end;

procedure TFrmPayCardCreateNew.GoToUri(uri : String);
var Flags: OleVariant;
begin
//  Flags := 'navNoHistory,navNoReadFromCache,navNoWriteToCache';
//  Flags:=4;
//  browser.Navigate(uri, Flags);
end;


procedure TFrmPayCardCreateNew.btnOKClick(Sender: TObject);
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

procedure TFrmPayCardCreateNew.DoLoadData;
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
    xml := d.roomerMainDataSet.downloadUrlAsString(  d.roomerMainDataSet.RoomerUri + 'paycard/token/costs/' + inttostr(Reservation));
    rSet := d.roomerMainDataSet.ActivateNewDataset(xml);
    iViews := 0;
    rSet.First;
    if NOT rSet.Eof then
      iViews := rSet['VIEWS'];
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{PLEASE_NOTE}', GetTranslatedText('PCI_VIEW_Warning_PleaseNote'));
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{CHARGE_PER_CREATE}', GetTranslatedText('PCI_CREATE_Warning_ChargePerCreate'));
    sTemp := ReplaceString(GetTranslatedText('PCI_VIEW_Warning_NumberOfViews'), '{VIEWS}', inttostr(iViews));
    lblPleaseRead.HTMLText.Text := ReplaceString(lblPleaseRead.HTMLText.Text, '{NUMBER_OF_VIEWS}', sTemp);
  end
  else
  begin
    uri := d.roomerMainDataSet.RoomerUri + format('paycard/bookings/%d/%d/cardentryuri', [FReservation, FRoomReservation]);

    // Get Token via webservice
    iFrameUri := d.roomerMainDataSet.downloadUrlAsString(uri);
    ShellExecute(Self.WindowHandle, 'open', PChar(iFrameUri), nil, nil, SW_SHOWNORMAL);
    GoToUri(iFrameUri);

  end;
end;

procedure TFrmPayCardCreateNew.DoShow;
begin
  inherited;
  btnOK.ModalResult := 0;
end;

procedure TFrmPayCardCreateNew.DoUpdateControls;
begin
  inherited;

  if FConfirmed then
    DialogButtons := [mbClose]
  else
    DialogButtons := mbOKCancel;

  AutoSize := not FConfirmed;
  pnlHead.Visible := not FConfirmed;
//  browser.visible := FConfirmed;
end;

procedure TFrmPayCardCreateNew.SetHotelId(const Value: String);
begin
  FHotelId := Value;
end;

procedure TFrmPayCardCreateNew.SetReservation(const Value: Integer);
begin
  FReservation := Value;
end;

procedure TFrmPayCardCreateNew.SetRoomReservation(const Value: Integer);
begin
  FRoomReservation := Value;
end;

procedure TFrmPayCardCreateNew.SetUserName(const Value: String);
begin
  FUsername := Value;
end;

end.
