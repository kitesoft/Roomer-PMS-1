unit uInvoicePayment;

interface

uses
    Windows
  , Messages
  , SysUtils
  , Classes
  , Graphics
  , Controls
  , Forms
  , Dialogs
  , StdCtrls
  , Buttons
  , ExtCtrls
  , ComCtrls
  , ADODB
  , Grids

  , hdata
  , _glob
  , ug

  , cmpRoomerDataSet
  , cmpRoomerConnection

  , sLabel
  , sBitBtn
  , sPanel
  , PlannerDatePicker
  , AdvEdit
  , AdvEdBtn

  , sButton
  , Vcl.Mask
  , sMaskEdit
  , sCustomComboEdit
  , sTooledit
  , sEdit
  , sSkinProvider
  , AdvObj
  , BaseGrid
  , AdvGrid, sComboBox, AdvUtil
  , uD, uAmount
  , Spring.Collections.Dictionaries
  ;

type


  TfrmInvoicePayment = class(TForm)
    Panel1: TsPanel;
    Panel2: TsPanel;
    Panel3: TsPanel;
    edtCustomer: TsEdit;
    lblCustomername: TsLabel;
    agrPayTypes: TAdvStringGrid;
    Panel5: TsPanel;
    Label2: TsLabel;
    Label3: TsLabel;
    lblSelected: TsLabel;
    lblLeft: TsLabel;
    lblAmount: TsLabel;
    edtAmount: TsEdit;
    sPanel1: TsPanel;
    dtInvDate: TsDateEdit;
    sLabel1: TsLabel;
    dtPayDate: TsDateEdit;
    sLabel2: TsLabel;
    BtnOk: TsButton;
    btnCancel: TsButton;
    sSkinProvider1: TsSkinProvider;
    sLabel3: TsLabel;
    cbxLocation: TsComboBox;
    __pnlCurrencies: TsPanel;
    LblForeignCurrencyAmount: TsLabel;
    LblLocalCurrencyAmount: TsLabel;
    __LblForeignCurrency: TsLabel;
    __LblLocalCurrency: TsLabel;
    pnlPayCard: TsPanel;
    btnManagePaycards: TsButton;
    btnChargePayCard: TsButton;
    procedure FormShow(Sender: TObject);
    procedure agrPayTypesSelectCell(Sender: TObject; ACol, ARow: Integer;
      var CanSelect: Boolean);
    procedure agrPayTypesKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure agrPayTypesEnter(Sender: TObject);
    procedure edtAmountExit(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure BtnOkClick(Sender: TObject);
    procedure agrPayTypesGetAlignment(Sender: TObject; ARow, ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
    procedure agrPayTypesClickCell(Sender: TObject; ARow, ACol: Integer);
    procedure btnManagePaycardsClick(Sender: TObject);
    procedure btnChargePayCardClick(Sender: TObject);
    procedure agrPayTypesEditCellDone(Sender: TObject; ACol, ARow: Integer);

  private
    { Private declarations }
    CloseOK : boolean;
    err : integer;

    FNativeAmount : TAmount;
    FCustomer : string;
    FReservation: Integer;
    FRoomReservation: Integer;
    FCurrency: String;
    FCurrencyRate: Double;
    FInvoiceIndex: Integer;
    FAllowPaycardCharge: boolean;
    FAmountLeft: TAmount;
    procedure Recalc;
    procedure FillPayGrid;
    function AlreadyProvidedPayments: TAmount;
    procedure EnabledChargepaycard;
    procedure SetAmountLeft(const Value: TAmount);
    property AmountLeft: TAmount read FAmountLeft write SetAmountLeft;
  public
    { Public declarations }
     procedure WndProc(var Message: TMessage); override;
     property Reservation : Integer read FReservation write FReservation;
     property RoomReservation : Integer read FRoomReservation write FRoomReservation;
     property InvocieIndex: Integer read FInvoiceIndex write FInvoiceIndex;
     property Currency: String read FCurrency write FCurrency;
     property CurrencyRate: Double read FCurrencyRate write FCurrencyRate;
     property AllowPaycardCharge: boolean read FAllowPaycardCharge write FAllowPaycardCharge;
  end;


// --
function SelectPaymentTypes( NativeAmount : TAmount;
                            Customer : string;
                            PaymentType : hdata.TPaymentTypes;
                            Currency : String;
                            CurrencyRate : Double;
                            Reservation : Integer;
                            RoomReservation : Integer;
                            InvoiceIndex: integer;
                            AllowPaycardCharging: boolean;
                            var lst : TstringList;
                            var aInvoiceDate : TDate;
                            var aPayDate : TDate;
                            var aLocation : string) : boolean;

var
    sSelectedCustomer  : string;
    fSelectedAmount    : Double;
    stlPaySelections   : TDictionary<string, TAmount>;
    COnfirmation       : string;


implementation

uses
   uSqlDefinitions
   , uAppGlobal
   , PrjConst
   , uUtils
   , uFrmPayCardView
   , UITypes
   , uFrmChargePayCard
   , uTokenHelpers
   , uFrmManagePCIConnection
  , uFrmTokenChargeHistory;

{$R *.DFM}

function SelectPaymentTypes( NativeAmount : TAmount;
                             Customer : string;
                             PaymentType : hdata.TPaymentTypes;
                             Currency : String;
                             CurrencyRate : Double;
                             Reservation : Integer;
                             RoomReservation : Integer;
                             InvoiceIndex: integer;
                             AllowPaycardCharging: boolean;
                             var lst : TstringList;
                             var aInvoiceDate : TDate;
                             var aPayDate : TDate;
                             var aLocation : string) : boolean;
var
  i : integer;
  selected : string;
  frm: TfrmInvoicePayment;
  sTemp: string;
begin
  // --
  frm := TfrmInvoicePayment.Create(nil);
  try
//    Confirmation := '';
    frm.FNativeAmount := NativeAmount;
    frm.edtAmount.text := frm.FNativeAmount.AsDisplayString;
    frm.FCustomer := Customer;
    frm.lblSelected.caption := '0';
    frm.AmountLeft := NativeAmount;
    frm.dtInvDate.Date := Date;
    frm.dtPayDate.Date := Date;
    frm.Currency := Currency;
    frm.CUrrencyRate := CurrencyRate;

    // TODO: Extend backend to allow specifying invoiceindex to store payment in
    frm.AllowPaycardCharge := AllowPaycardCharging and (InvoiceIndex <= 0);
    sSelectedCustomer := Customer;
    stlPaySelections.clear;

    // get all locations from data
    glb.Locations.First;
    while not glb.Locations.Eof do begin
      frm.cbxLocation.items.Add(glb.Locations.FieldByName('Location').asstring);
      glb.Locations.Next;
    end;


    if lst.Count = 1 then
    begin
      selected := lst[0];
      for i := 0 to frm.cbxLocation.Items.Count-1 do
      begin
        if frm.cbxLocation.Items[i].ToLower.Equals(selected.ToLower) then break;
      end;
      frm.cbxLocation.ItemIndex := i;
    end else
    begin
      frm.cbxLocation.ItemIndex := frm.cbxLocation.Items.Count-1;
    end;


    if PaymentType = ptDownPayment then
    begin
      frm.Caption := GetTranslatedText('shTx_InvoicePayment_DownPayment');
      frm.panel2.visible := true;
      frm.__pnlCurrencies.Visible := False;
    end else
    begin
	    frm.Caption := GetTranslatedText('shTx_InvoicePayment_InvoicePayment');
      frm.panel2.visible := false;
      frm.LblForeignCurrencyAmount.Visible := UpperCase(Currency) <> UpperCase(ctrlGetString('NativeCurrency'));
      frm.__pnlCurrencies.Visible := true;
      frm.__LblLocalCurrency.Caption := NativeAmount.AsDisplayStringWithCode;
      frm.__LblForeignCurrency.Caption := NativeAmount.ToCurrency(Currency).AsDisplayStringWithCode;
    end;

    frm.Reservation := Reservation;
    frm.RoomReservation := RoomReservation;
    if frm.ShowModal <> mrOK then
    begin
      result := false;
    end else
    begin
      result := true;
      sSelectedCustomer := frm.edtCustomer.text;
      fSelectedAmount   := _StrToFloat( frm.edtAmount.text );
      aInvoiceDate      := frm.dtInvDate.date;
      aPayDate          := frm.dtPayDate.date;


      aLocation := '';

      if frm.cbxLocation.itemindex > 0 then
      begin
        aLocation := frm.cbxLocation.items[frm.cbxLocation.itemindex];
      end;

//      for i := 0 to frm.agrPayTypes.RowCount - 1  do
//      begin
//        if GridCellFloatValue( frm.agrPayTypes, 1, i ) <> 0 then
//        begin
//          sTemp := frm.agrPayTypes.Cells[ 0, i ];
//          glb.LocateSpecificRecordAndGetValue('paytypes', 'PayType', sTemp, 'Description', sTemp);
//          stlPaySelections.add( frm.agrPayTypes.Cells[ 0, i ] + '|' + frm.agrPayTypes.Cells[ 1, i ] + '|' + sTemp );
//        end;
//      end;
    end;
  finally
    frm.free;
  end;
end;



const WM_ActivateAmount = WM_User + 381;

procedure TfrmInvoicePayment.WndProc(var Message: TMessage);
begin
  if Message.Msg = WM_ActivateAmount then
  begin
    Recalc;
  end else
    inherited;
end;


procedure TfrmInvoicePayment.FillPayGrid;
var
  l : integer;
begin
    l := 0;
    glb.PaytypesSet.First;
    while not glb.PaytypesSet.eof do
    begin
      if glb.PaytypesSet.FieldByName('active').AsBoolean then
      begin
        inc(l);
        agrPayTypes.RowCount := l;
        agrPayTypes.Cells[ 0, l - 1 ] := glb.PaytypesSet.FieldByName( 'PayType' ).AsString;
        stlPaySelections.Add(glb.PaytypesSet.FieldByName( 'PayType' ).AsString, 0);
      end;
      glb.PaytypesSet.next;
    end;
end;

procedure TfrmInvoicePayment.Recalc;
var
  i : integer;
  lPaid: TAmount;

  maxDays : integer;
  payType : string;
  days : integer;
begin
  // --
  maxDays   := 0;
  lPaid := 0;

  for i := 0 to agrPayTypes.RowCount - 1 do
  begin
    payType := agrPayTypes.Cells[0,i];

    lPaid := lPaid + stlPaySelections.Items[agrPayTypes.cells[0, i]];
 //GridCellFloatValue( agrPayTypes, 1, i );

    if GridCellFloatValue( agrPayTypes, 1, i ) <> 0 then
    begin
      days := PayTypesDays(payType);
      if days > maxDays then Maxdays := days;
    end;

  end;

  AmountLeft         := FNativeAmount - lPaid;
  lblSelected.caption := lPaid.AsDisplayStringWithCode;
  if AmountLeft = 0.0 then beep;

  dtpayDate.Date := MaxDays + dtInvDate.Date
end;

procedure TfrmInvoicePayment.SetAmountLeft(const Value: TAmount);
begin
  FAmountLeft := Value;
  lblLeft.Caption := FAmountLeft.ToNative.AsDisplayStringWithCode;
end;

function TfrmInvoicePayment.AlreadyProvidedPayments : TAmount;
var
  amount: TAmount;
begin
  result := 0;
  for amount in stlPaySelections.Values do
    Result := Result + amount;
end;


procedure TfrmInvoicePayment.FormShow(Sender: TObject);
begin
  edtCustomer.text := FCustomer;
  FillPayGrid;
  lblSelected.caption := _FloatToStr( 0, 12, 2 );
  EnabledChargepaycard;
  postmessage( handle, WM_ActivateAmount, 0, 0 );
end;

procedure TfrmInvoicePayment.EnabledChargepaycard;
var
  channelId: integer;
begin
  channelId := -1;
  btnManagePaycards.Enabled := AllowPaycardCharge;
  btnChargePAyCard.Enabled := AllowPaycardCharge and ReservationHasPaycard(FReservation, FRoomReservation, channelId);
end;

procedure TfrmInvoicePayment.agrPayTypesGetAlignment(Sender: TObject; ARow, ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  HAlign := taRightJustify;
end;

procedure TfrmInvoicePayment.agrPayTypesSelectCell(Sender: TObject; ACol, ARow: Integer; var CanSelect: Boolean);
var
  amount: TAmount;
begin
  if (AmountLeft <> 0.00) and stlPaySelections.TryGetValue(agrPayTypes.cells[0, aRow], amount) and (amount = 0) then
  begin
    amount := AmountLeft.ToNative;
    stlPaySelections.AddOrSetValue(agrPayTypes.cells[0, aRow], amount);
    agrPayTypes.Cells[ 1, ARow ] := amount;
    Recalc;
  end;
  agrPayTypes.Options := agrPayTypes.Options  + [goEditing];
end;

procedure TfrmInvoicePayment.btnChargePayCardClick(Sender: TObject);
var charge : TTokenCharge;
begin
  charge := ChargePayCardForPayment(Reservation,
            Roomreservation,
            (FNativeAmount - AlreadyProvidedPayments).ToCurrency(Currency),
            Currency,
            PCO_CHARGE,
            True);
  if Assigned(charge) then
  begin
    // Dont add to list otherwise it will be save twice
    BtnOk.click;
    //TODO: Improve this so form isnt closed if balance <> 0
  end;
end;

procedure TfrmInvoicePayment.BtnOkClick(Sender: TObject);
begin
  if cbxLocation.itemindex = 0 then
  begin
    closeok := false;
    err := 2;
  end;

  if not closeOk then
  begin
    case err of
      1 : MessageDlg(GetTranslatedText('shTx_InvoicePayment_ExceedsInvoice'), mtError, [mbOk], 0);
      2 : MessageDlg('Select Location', mtError, [mbOk], 0);
    end;
  end;
end;

procedure TfrmInvoicePayment.btnManagePaycardsClick(Sender: TObject);
begin
  ManagePaymentCards(FReservation, FRoomReservation, pcmCardsOnly);
end;

procedure TfrmInvoicePayment.agrPayTypesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = vk_Return then
      Recalc;
end;

procedure TfrmInvoicePayment.agrPayTypesClickCell(Sender: TObject; ARow,
  ACol: Integer);
begin
  postMessage( handle, WM_ActivateAmount, 0, 0 );
end;

procedure TfrmInvoicePayment.agrPayTypesEditCellDone(Sender: TObject; ACol, ARow: Integer);
var
  amount: TAmount;
begin
  amount := TAmount(_strToFloat(agrPaytypes.Cells[aCol, aRow]));
  stlPaySelections.AddOrSetValue(agrPayTypes.Cells[0, aRow], amount);
  agrPaytypes.Cells[aCol, aRow] := amount;
  agrPayTypes.Options := agrPayTypes.Options - [goEditing];
  Recalc;
end;

procedure TfrmInvoicePayment.agrPayTypesEnter(Sender: TObject);
begin
  if (FNativeAmount = 0) and edtAmount.CanFocus then
    ActiveControl := edtAmount;
  //postMessage( handle, WM_ActivateAmount, 0, 0 );
end;

procedure TfrmInvoicePayment.edtAmountExit(Sender: TObject);
begin
  // --
  FNativeAmount := _StrToFloat( edtAmount.text );
  fSelectedAmount := FNativeAmount;
  // --
  postMessage( handle, WM_ActivateAmount, 0, 0 );
end;

procedure TfrmInvoicePayment.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);
  closeOk := true;
end;

procedure TfrmInvoicePayment.FormCloseQuery(Sender: TObject;
  var CanClose: Boolean);
begin
  canClose := closeOk;
  closeOk  := true;
end;

initialization
begin
   stlPaySelections := TDictionary<string, TAmount>.create;
end;

finalization
begin
   stlPaySelections.free;
end;

end.



