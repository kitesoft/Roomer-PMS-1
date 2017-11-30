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
    procedure FormCreate(Sender : TObject);
    procedure FormShow(Sender : TObject);
    procedure btnOKClick(Sender : TObject);
    procedure edRoomPriceChange(Sender: TObject);
    procedure HandleChanged(Sender: TObject);
  private
    procedure RecalcAmount(Sender : TObject);
    { Private declarations }
  protected
    procedure DoUpdateControls; override;
  public
    { Public declarations }
    zPersons : integer;
    zNights : integer;
    zRooms : integer;
    RoomPrice : TAmount;
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
    frm.zPersons   :=  Persons;
    frm.zRooms     :=  Rooms;
    frm.zNights    :=  Nights;
    frm.RoomPrice :=  roomPrice;

    frm.ShowModal;
    if frm.modalresult = mrOk then
    begin
      result := true;
      Persons   := frm.zPersons   ;
      Rooms     := frm.zRooms     ;
      Nights    := frm.zNights    ;
      roomPrice := frm.RoomPrice ;
    end
  finally
    frm.free;
  end;
end;


procedure TfrmAddAccommodation.btnOKClick(Sender : TObject);
begin
  zPersons := edPersons.Value;
  zNights := edNights.Value;
  zRooms := edRooms.Value;
end;

procedure TfrmAddAccommodation.DoUpdateControls;
begin
  inherited;
  btnOK.Enabled := fraCurrencyPanel.IsValid and (edPersons.Value > 0) and (edNights.Value > 0) and (edRooms.Value > 0);
end;

procedure TfrmAddAccommodation.HandleChanged(Sender: TObject);
begin
  inherited;
  UpdateControls;
end;

procedure TfrmAddAccommodation.edRoomPriceChange(Sender: TObject);
begin
  if fraCurrencyPanel.IsValid then
    RoomPrice := TAmount.Create(edRoomPrice.Value, fraCurrencyPanel.CurrencyCode);
  HandleChanged(Sender);
end;

procedure TfrmAddAccommodation.FormCreate(Sender : TObject);
begin
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
  fraCurrencyPanel.OnCurrencyChange := HandleChanged;
  edPersons.Value := zPersons;
  edNights.Value := zNights;
  edRooms.Value := zRooms;
  edRoomPrice.value := RoomPrice;
  edRoomprice.SetFocus;
  DialogButtons := mbOKCancel;
end;

procedure TfrmAddAccommodation.RecalcAmount(Sender : TObject);
begin
  if (RoomPrice <> TAmount.ZERO) and fraCurrencyPanel.IsValid and (RoomPrice.CurrencyCode <> fraCurrencyPanel.CurrencyCode) then
  begin
    edRoomPrice.Value := RoomPrice.ToCurrency(fraCurrencyPanel.CurrencyCode)
  end;
end;

end.
