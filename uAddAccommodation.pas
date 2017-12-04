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
  , uAmount, uRoomerDialogForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, Vcl.ComCtrls, sStatusBar

  ;

type
  TfrmAddAccommodation = class(TfrmBaseRoomerDialogForm)
    edPersons: TsSpinEdit;
    cxLabel1: TsLabel;
    cxLabel2: TsLabel;
    edNights: TsSpinEdit;
    cxLabel3: TsLabel;
    edRooms: TsSpinEdit;
    cxLabel4: TsLabel;
    edRoomPrice: TsCalcEdit;
    fraCurrencyPanel: TfraCurrencyPanel;
    procedure FormShow(Sender : TObject);
    procedure edRoomPriceChange(Sender: TObject);
    procedure HandleChanged(Sender: TObject);
  private
    FRoomPrice: TAmount;
    procedure RecalcAmount(Sender : TObject);
    procedure SetNights(const Value: integer);
    procedure SetPersons(const Value: integer);
    procedure SetRooms(const Value: integer);
    procedure SetRoomPrice(const Value: TAmount);
    function GetNights: integer;
    function GetPersons: integer;
    function GetRooms: integer;
    { Private declarations }
  protected
    procedure DoUpdateControls; override;
  public
    { Public declarations }
    property Persons: integer read GetPersons write SetPersons;
    property Nights: integer read GetNights write SetNights;
    property Rooms: integer read GetRooms write SetRooms;
    property RoomPrice: TAmount read FRoomPrice write SetRoomPrice;
  end;

  function AddAccommodation(var Persons,rooms,nights : integer; var roomPrice : TAmount) : boolean;

implementation

{$R *.dfm}

uses
    uRoomerLanguage
  , uUtils
  , uDImages
  , uMain
  , uG
  , Math;


function AddAccommodation(var Persons,rooms,nights : integer; var roomPrice : TAmount) : boolean;
var
  frm: TfrmAddAccommodation;
begin
  result := false;
  frm := TfrmAddAccommodation.Create(nil);
  try
    frm.Persons   :=  Persons;
    frm.Rooms     :=  Rooms;
    frm.Nights    :=  Nights;
    frm.RoomPrice :=  roomPrice;

    frm.ShowModal;
    if frm.modalresult = mrOk then
    begin
      result := true;
      Persons   := frm.Persons   ;
      Rooms     := frm.Rooms     ;
      Nights    := frm.Nights    ;
      roomPrice := frm.RoomPrice ;
    end
  finally
    frm.free;
  end;
end;


procedure TfrmAddAccommodation.DoUpdateControls;
begin
  inherited;
  btnOK.Enabled := fraCurrencyPanel.IsValid and (Persons > 0) and (Nights > 0) and (Rooms > 0);
end;

procedure TfrmAddAccommodation.HandleChanged(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TfrmAddAccommodation.edRoomPriceChange(Sender: TObject);
begin
  if fraCurrencyPanel.IsValid then
    FRoomPrice := TAmount.Create(edRoomPrice.Value, fraCurrencyPanel.CurrencyCode);
  HandleChanged(Sender);
end;

procedure TfrmAddAccommodation.FormShow(Sender : TObject);
begin
  fraCurrencyPanel.CurrencyCode := g.qNativeCurrency;
  fraCurrencyPanel.ShowCurrencyName := false;
  fraCurrencyPanel.OnCurrencyChangeAndValid := reCalcAmount;
  fraCurrencyPanel.OnCurrencyChange := HandleChanged;
  FRoomPrice := 0;
  edRoomprice.SetFocus;
  DialogButtons := mbOKCancel;
end;

function TfrmAddAccommodation.GetNights: integer;
begin
  Result := edNights.Value;
end;

function TfrmAddAccommodation.GetPersons: integer;
begin
  Result := edPersons.Value;
end;

function TfrmAddAccommodation.GetRooms: integer;
begin
  Result := edRooms.Value;
end;

procedure TfrmAddAccommodation.RecalcAmount(Sender : TObject);
begin
  if (RoomPrice <> TAmount.ZERO) and fraCurrencyPanel.IsValid and (RoomPrice.CurrencyCode <> fraCurrencyPanel.CurrencyCode) then
  begin
    edRoomPrice.Value := RoomPrice.ToCurrency(fraCurrencyPanel.CurrencyCode)
  end;
end;

procedure TfrmAddAccommodation.SetNights(const Value: integer);
begin
  edNights.value := Value;
end;

procedure TfrmAddAccommodation.SetPersons(const Value: integer);
begin
  edPersons.Value := value;
end;

procedure TfrmAddAccommodation.SetRoomPrice(const Value: TAmount);
begin
  edRoomPrice.Value := Value;
end;

procedure TfrmAddAccommodation.SetRooms(const Value: integer);
begin
  edRooms.Value := Value;
end;

end.
