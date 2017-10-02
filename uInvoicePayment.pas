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
  , uD
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
    LblForeignCurrency: TsLabel;
    LblLocalCurrency: TsLabel;
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

  private
    { Private declarations }
    CloseOK : boolean;
    err : integer;

    FAmount : Double;
    FCustomer : string;
    FReservation: Integer;
    FRoomReservation: Integer;
    procedure Recalc;
    procedure FillPayGrid;
    function AlreadyProvidedPayments: Double;
    procedure EnabledChargepaycard;
  public
    { Public declarations }
     procedure WndProc(var Message: TMessage); override;
     property Reservation : Integer read FReservation write FReservation;
     property RoomReservation : Integer read FRoomReservation write FRoomReservation;
  end;


// --
function SelectPaymentTypes( Amount : Double;
                            Customer : string;
                            PaymentType : hdata.TPaymentTypes;
                            Currency : String;
                            CurrencyRate : Double;
                            Reservation : Integer;
                            RoomReservation : Integer;
                            var lst : TstringList;
                            var aInvoiceDate : TDate;
                            var aPayDate : TDate;
                            var aLocation : string) : boolean;

var
    sSelectedCustomer  : string;
    fSelectedAmount    : Double;
    stlPaySelections   : TStringlist;
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

function SelectPaymentTypes( Amount : Double;
                             Customer : string;
                             PaymentType : hdata.TPaymentTypes;
                             Currency : String;
                             CurrencyRate : Double;
                             Reservation : Integer;
                             RoomReservation : Integer;
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
    frm.FAmount := Amount;
    frm.edtAmount.text := trim( _FloatToStr( Amount, 9, 2 ) );
    frm.FCustomer := Customer;
    frm.lblSelected.caption := '0';
    frm.lblLeft.caption := trim( _FloatToStr( Amount, 9, 2 ) );
    frm.dtInvDate.Date := Date;
    frm.dtPayDate.Date := Date;
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
      frm.LblForeignCurrency.Visible := UpperCase(Currency) <> UpperCase(ctrlGetString('NativeCurrency'));
      frm.LblForeignCurrencyAmount.Visible := frm.LblForeignCurrency.Visible;
      frm.__LblForeignCurrency.Visible := frm.LblForeignCurrency.Visible;
      frm.__pnlCurrencies.Visible := true;
      frm.__LblLocalCurrency.Caption := trim(_floattostr(Amount, 10, 2));
      frm.__LblForeignCurrency.Caption := trim(_floattostr(Amount / CurrencyRate, 10, 2));
      frm.LblLocalCurrency.Caption := ctrlGetString('NativeCurrency');
      frm.LblForeignCurrency.Caption := Currency;
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

      for i := 0 to frm.agrPayTypes.RowCount - 1  do
      begin
        if GridCellFloatValue( frm.agrPayTypes, 1, i ) <> 0 then
        begin
          sTemp := frm.agrPayTypes.Cells[ 0, i ];
          glb.LocateSpecificRecordAndGetValue('paytypes', 'PayType', sTemp, 'Description', sTemp);
          stlPaySelections.add( frm.agrPayTypes.Cells[ 0, i ] + '|' + frm.agrPayTypes.Cells[ 1, i ] + '|' + sTemp );
//          if d.AskApproval( frm.agrPayTypes.Cells[ 0, i ] ) then
//            // FConfirmation := InputBox( 'Confirm code', 'Code :', '' );
//    			 Confirmation := InputBox( GetTranslatedText('shTx_InvoicePayment_ConfirmCode'), GetTranslatedText('shTx_InvoicePayment_Code'), '' );
        end;
      end;
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
      end;
      glb.PaytypesSet.next;
    end;
end;

procedure TfrmInvoicePayment.Recalc;
var
  i : integer;
      fSelected,
      fLeft : Double;

  maxDays : integer;
  payType : string;
  days : integer;
begin
  // --
  maxDays   := 0;
  fSelected := 0;

  for i := 0 to agrPayTypes.RowCount - 1 do
  begin
    payType := agrPayTypes.Cells[0,i];

    fSelected := fSelected + GridCellFloatValue( agrPayTypes, 1, i );

    if GridCellFloatValue( agrPayTypes, 1, i ) <> 0 then
    begin
      days := PayTypesDays(payType);
      if days > maxDays then Maxdays := days;
    end;

  end;

  fLeft               := FAmount - fSelected;
  lblSelected.caption := _FloatToStr( fSelected, 12, 2 );
  lblLeft.caption     := _FloatToStr( fLeft,     12, 2 );
  if fLeft = 0 then beep;

  dtpayDate.Date := MaxDays + dtInvDate.Date
end;

function TfrmInvoicePayment.AlreadyProvidedPayments : Double;
var
  i : integer;
begin
  result := 0.00;
  // --
  for i := 0 to agrPayTypes.RowCount - 1 do
    result := result + GridCellFloatValue( agrPayTypes, 1, i );
end;


procedure TfrmInvoicePayment.FormShow(Sender: TObject);
begin
  edtCustomer.text := FCustomer;
  recalc;
  FillPayGrid;
  lblSelected.caption := _FloatToStr( 0, 12, 2 );
  lblLeft.caption     := _FloatToStr( FAmount, 12, 2 );
  postmessage( handle, WM_ActivateAmount, 0, 0 );

  EnabledChargepaycard;
end;

procedure TfrmInvoicePayment.EnabledChargepaycard;
var
  channelId: integer;
begin
  channelId := -1;
  btnChargePAyCard.Enabled := ReservationHasPaycard(FReservation, FRoomReservation, channelId);
end;

procedure TfrmInvoicePayment.agrPayTypesGetAlignment(Sender: TObject; ARow, ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  HAlign := taRightJustify;
end;

procedure TfrmInvoicePayment.agrPayTypesSelectCell(Sender: TObject; ACol, ARow: Integer; var CanSelect: Boolean);
begin
  // --
   Recalc;
   agrPayTypes.Options := [goFixedVertLine,goFixedHorzLine,goVertLine,goHorzLine,goRangeSelect,goEditing];
  // --
   agrPayTypes.OnSelectCell := nil;
   try
      if trunc( GridCellFloatValue( agrPayTypes, 1, ARow ) ) = 0 then
      begin
        agrPayTypes.Cells[ ACol, ARow ] := lblLeft.caption;
      end;
   finally
      agrPayTypes.OnSelectCell := agrPayTypesSelectCell;
   end;
end;

procedure TfrmInvoicePayment.btnChargePayCardClick(Sender: TObject);
var charge : TTokenCharge;
    PayType : String;
    i : Integer;
begin
  charge := ChargePayCardForPayment(Reservation,
            Roomreservation,
            FAmount - AlreadyProvidedPayments,
            LblForeignCurrency.Caption,
            PCO_CHARGE,
            True);
  if Assigned(charge) then
  begin
    PayType := getMapForCardType(charge.token.CardType);
    if PayType <> '' then
      for i := 1 to agrPayTypes.RowCount - 1 do
        if LowerCase(agrPayTypes.Cells[0, i]) = LowerCase(PayType) then
        begin
          agrPayTypes.Cells[1, i] := FloatToStr(charge.amount);
          ReCalc;
          BtnOk.Click;
        end;
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
  ManagePaymentCards(FReservation, FRoomReservation);
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

procedure TfrmInvoicePayment.agrPayTypesEnter(Sender: TObject);
begin
  if (FAmount = 0) and edtAmount.CanFocus then
    ActiveControl := edtAmount;
  postMessage( handle, WM_ActivateAmount, 0, 0 );
end;

procedure TfrmInvoicePayment.edtAmountExit(Sender: TObject);
begin
  // --
  FAmount := _StrToFloat( edtAmount.text );
  fSelectedAmount := FAmount;
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
   stlPaySelections := TStringlist.create;
end;

finalization
begin
   stlPaySelections.free;
end;

end.



