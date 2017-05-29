unit uFrmPayCardView;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.OleCtrls, SHDocVw, acWebBrowser, Vcl.ExtCtrls, sPanel,
  uRoomerForm;

type
  TFrmPayCardView = class(TfrmBaseRoomerForm)
    sPanel1: TsPanel;
    sPanel2: TsPanel;
    browser: TsWebBrowser;
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
    FHotelId: String;
    FUsername: String;
    FReservation: Integer;
    procedure SetHotelId(const Value: String);
    procedure SetUserName(const Value: String);
    procedure GetToken;
    procedure SetReservation(const Value: Integer);
    procedure GoToUri(uri: String);
  public
    { Public declarations }
    property UserName : String read FUsername write SetUserName;
    property HotelId : String read FHotelId write SetHotelId;
    property Reservation : Integer read FReservation write SetReservation;
  end;

procedure ShowPayCardInformation(Reservation : Integer);

var
  FrmPayCardView: TFrmPayCardView;

implementation

{$R *.dfm}

uses uG,
     RoomerLoginForm,
     uD;

function openLogin(var userName, password : string) : boolean;
var hotelId : String;
begin
  hotelId     := g.qHotelCode;
  result := (AskUserForCredentials(userName, password, hotelId, '', 7)  in cLoginFormSuccesfull);
end;

procedure ShowPayCardInformation(Reservation : Integer);
var _FrmPayCardView : TFrmPayCardView;
    gUserName, gPassword : String;
begin
  if openLogin(gUserName, gPassword) then
  begin
    _FrmPayCardView := TFrmPayCardView.Create(nil);
    try
      _FrmPayCardView.UserName := gUserName;
      _FrmPayCardView.HotelId := g.qHotelCode;
      _FrmPayCardView.Reservation := Reservation;
      _FrmPayCardView.ShowModal;
    finally
      _FrmPayCardView.free;
    end;
  end;
end;

{ TFrmPayCardView }

procedure TFrmPayCardView.FormShow(Sender: TObject);
begin
  inherited;
  GetToken;
end;

procedure TFrmPayCardView.GoToUri(uri : String);
var Flags: OleVariant;
begin
  Flags := 'navNoHistory,navNoReadFromCache,navNoWriteToCache';
  browser.Navigate2(uri, Flags);
end;


procedure TFrmPayCardView.GetToken;
var uri : String;
    iFrameUri : String;
begin
  uri := d.roomerMainDataSet.RoomerUri + format('resapi/bookings/%d/paycarddisplayuri', [FReservation]);

// Get Token via webservice
  iFrameUri := d.roomerMainDataSet.downloadUrlAsString(uri);
  GoToUri(iFrameUri);
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
