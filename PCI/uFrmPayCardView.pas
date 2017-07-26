unit uFrmPayCardView;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.OleCtrls, SHDocVw, acWebBrowser, Vcl.ExtCtrls, sPanel,
  uRoomerForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls,
  sStatusBar, uDImages, Vcl.StdCtrls, sButton, acPNG, acImage, HTMLabel;

type
  TFrmPayCardView = class(TfrmBaseRoomerForm)
    pnlHead: TsPanel;
    pnlClient: TsPanel;
    browser: TsWebBrowser;
    lblPleaseRead: THTMLabel;
    imgWarning: TsImage;
    btnContinue: TsButton;
    sButton1: TsButton;
    procedure btnContinueClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
    FHotelId: String;
    FUsername: String;
    FReservation: Integer;
    procedure SetHotelId(const Value: String);
    procedure SetUserName(const Value: String);
    procedure SetReservation(const Value: Integer);
    procedure GoToUri(uri: String);
  protected
    procedure DoLoadData; override;
  public
    { Public declarations }
    property UserName : String read FUsername write SetUserName;
    property HotelId : String read FHotelId write SetHotelId;
    property Reservation : Integer read FReservation write SetReservation;
  end;

procedure ShowPayCardInformation(Reservation : Integer);

implementation

{$R *.dfm}

uses uG,
     RoomerLoginForm,
     uD,
     uUtils,
     cmpRoomerDataSet,
     PrjConst,
     uActivityLogs;

function openLogin(var userName, password : string) : boolean;
var hotelId : String;
begin
  hotelId     := g.qHotelCode;
  result := (AskUserForCredentials(userName, password, hotelId, '', 7) in cLoginFormSuccesfull);
end;

procedure ShowPayCardInformation(Reservation : Integer);
var _FrmPayCardView : TFrmPayCardView;
    gUserName, gPassword : String;
begin
  _FrmPayCardView := TFrmPayCardView.Create(nil);
  try
    _FrmPayCardView.Reservation := Reservation;
    _FrmPayCardView.ShowModal;
  finally
    _FrmPayCardView.free;
  end;
end;

{ TFrmPayCardView }

procedure TFrmPayCardView.GoToUri(uri : String);
var Flags: OleVariant;
begin
//  Flags := 'navNoHistory,navNoReadFromCache,navNoWriteToCache';
  Flags:=4;
  browser.Navigate(uri, Flags);
end;


procedure TFrmPayCardView.btnContinueClick(Sender: TObject);
var gUserName, gPassword : String;
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
    pnlHead.Visible := False;
    RefreshData;
  end;
end;

procedure TFrmPayCardView.DoLoadData;
var uri : String;
    iFrameUri : String;
begin
  inherited;
  uri := d.roomerMainDataSet.RoomerUri + format('resapi/bookings/%d/paycarddisplayuri', [FReservation]);

  // Get Token via webservice
  iFrameUri := d.roomerMainDataSet.downloadUrlAsString(uri);
  CopyToClipboard(iFrameUri);
  GoToUri(iFrameUri);
end;

procedure TFrmPayCardView.FormShow(Sender: TObject);
var rSet : TRoomerDataSet;
    xml : String;
    iViews : Integer;
    sTemp : String;
begin
  xml := d.roomerMainDataSet.downloadUrlAsString(  d.roomerMainDataSet.RoomerUri + 'resapi/tokencosts/' + inttostr(Reservation));
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
