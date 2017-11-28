unit uAddAccommodation;

interface

uses
  Windows,
  Messages,
  SysUtils,
  Variants,
  Classes,
  Graphics,
  Controls,
  Forms,
  Dialogs,
  ExtCtrls,
  Menus,
  StdCtrls,
  Vcl.Mask,

  _Glob,
  uAppGlobal,

  sMaskEdit,
  sCustomComboEdit,
  sCurrEdit,
  sPanel,
  sLabel,
  sEdit,
  sSpinEdit,
  sButton,

  cxClasses,
  cxPropertiesStore, ufraCurrencyPanel
  , uAmount
  ;

type
  TfrmAddAccommodation = class(TForm)
    edPersons: TsSpinEdit;
    cxLabel1: TsLabel;
    cxLabel2: TsLabel;
    edNights: TsSpinEdit;
    cxLabel3: TsLabel;
    edRooms: TsSpinEdit;
    cxLabel4: TsLabel;
    FormStore: TcxPropertiesStore;
    sPanel1: TsPanel;
    edRoomPrice: TsCalcEdit;
    BtnOk: TsButton;
    btnCancel: TsButton;
    fraCurrencyPanel: TfraCurrencyPanel;
    procedure FormCreate(Sender : TObject);
    procedure FormShow(Sender : TObject);
    procedure btnOKClick(Sender : TObject);
    procedure edRoomPriceChange(Sender: TObject);
  private
    procedure RecalcAmount(Sender : TObject);
    { Private declarations }

  public
    { Public declarations }
    zPersons : integer;
    zNights : integer;
    zRooms : integer;
    RoomPrice : TAmount;
  end;

var
  frmAddAccommodation : TfrmAddAccommodation;

implementation

{$R *.dfm}

uses
    uRoomerLanguage
  , uUtils
  , uDImages
  , uMain
  , uG
  , Math;

procedure TfrmAddAccommodation.btnOKClick(Sender : TObject);
begin
  zPersons := edPersons.Value;
  zNights := edNights.Value;
  zRooms := edRooms.Value;
end;

procedure TfrmAddAccommodation.edRoomPriceChange(Sender: TObject);
begin
  RoomPrice := TAmount.Create(edRoomPrice.Value, fraCurrencyPanel.CurrencyCode);
end;

procedure TfrmAddAccommodation.FormCreate(Sender : TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);

  // **
  zPersons := 1;
  zNights := 1;
  zRooms := 1;
end;

procedure TfrmAddAccommodation.FormShow(Sender : TObject);
begin
  fraCurrencyPanel.CurrencyCode := g.qNativeCurrency;
  fraCurrencyPanel.ShowCurrencyName := false;
  fraCurrencyPanel.OnCurrencyChangeAndValid := reCalcAmount;
  edPersons.Value := zPersons;
  edNights.Value := zNights;
  edRooms.Value := zRooms;
  edRoomPrice.value := RoomPrice;
  edRoomprice.SetFocus;
end;

procedure TfrmAddAccommodation.RecalcAmount(Sender : TObject);
begin
  if (RoomPrice <> TAmount.ZERO) and (RoomPrice.CurrencyCode <> fraCurrencyPanel.CurrencyCode) then
  begin
    edRoomPrice.Value := RoomPrice.ToCurrency(fraCurrencyPanel.CurrencyCode)
  end;
end;

end.
