unit uDownPayment;

interface

uses
    Windows
  , Messages
  , SysUtils
  , Variants
  , Classes
  , Graphics
  , Controls
  , Forms
  , Dialogs
  , ExtCtrls
  , Menus
  , StdCtrls
  , Data.DB

  , uG
  , hData
  , _glob

  , uUtils
  , kbmMemTable

  , cmpRoomerDataSet
  , cmpRoomerConnection

  , sMemo
  , sEdit
  , sSpinEdit
  , sLabel
  , sGroupBox
  , sButton
  , sScrollBox

  , cxStyles
  , dxSkinscxPCPainter
  , dxSkinsCore, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin,
  dxSkinOffice2013White, dxSkinsDefaultPainters, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, cxDBData,
  cxPropertiesStore, cxGridLevel, cxGridCustomTableView, cxGridTableView, cxGridDBTableView, cxClasses, cxGridCustomView, cxGrid, Vcl.Mask,
  sMaskEdit, sCustomComboEdit, sCurrEdit, Vcl.Buttons, sSpeedButton, sPanel, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld,
  dxSkinBlack, dxSkinBlue, dxSkinBlueprint, dxSkinDarkRoom, dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast,
  dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky, dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black, dxSkinOffice2007Blue,
  dxSkinOffice2007Green, dxSkinOffice2007Pink, dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue, dxSkinOffice2010Silver,
  dxSkinPumpkin, dxSkinSeven, dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver, dxSkinSpringTime, dxSkinStardust,
  dxSkinSummer2008, dxSkinValentine, dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue

  ;

type
  TfrmDownPayment = class(TForm)
    Panel1: TsPanel;
    cxGroupBox1: TsGroupBox;
    btnOk: TsButton;
    btnCancel: TsButton;
    sGroupBox1: TsGroupBox;
    memNotes: TsMemo;
    sScrollBox1: TsScrollBox;
    kbmPayType: TkbmMemTable;
    tvPayType: TcxGridDBTableView;
    lvPayType: TcxGridLevel;
    grPayType: TcxGrid;
    PayTypeDS: TDataSource;
    tvPayTypePayType: TcxGridDBColumn;
    tvPayTypeDescription: TcxGridDBColumn;
    tvPayTypePayGroup: TcxGridDBColumn;
    edDescription: TsEdit;
    labPayment: TsLabel;
    labDescription: TsLabel;
    edAmount: TsCalcEdit;
    sSpeedButton1: TsButton;
    FormStore: TcxPropertiesStore;
    pnlCCButtons: TsPanel;
    btnManagePaycards: TsButton;
    btnChargePAyCard: TsButton;
    lbCurrency: TsLabel;
    procedure btnOkClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure btnCancelClick(Sender: TObject);
    procedure btnGetInvoiceBalanceClick(Sender: TObject);
    procedure tvPayTypeDblClick(Sender: TObject);
    procedure btnManagePaycardsClick(Sender: TObject);
    procedure btnChargePAyCardClick(Sender: TObject);
  private
    { Private declarations }
    zCanClose : boolean;
    FAllowPaycardCharge: boolean;
    procedure EnableDisableButtonViewPayCard;
  public
    { Public declarations }
    rec : recDownPayment;
    property AllowPaycardCharge: boolean read FAllowPaycardCharge write FAllowPaycardCharge;
  end;

implementation

{$R *.dfm}

uses uAppGlobal, uD, uDImages, uSQLUtils, uFrmPayCardView, uTokenHelpers, uFrmChargePayCard
    , uFrmTokenChargeHistory
    , Math
    , uFloatUtils;

procedure TfrmDownPayment.btnCancelClick(Sender: TObject);
begin
  //
  zCanClose := true;
end;

procedure TfrmDownPayment.btnChargePayCardClick(Sender: TObject);
var charge : TTokenCharge;
begin
  charge := ChargePayCardForPayment(rec.Reservation,
                  rec.Roomreservation,
                  iif(edAmount.Value = 0, rec.InvoiceBalanceInCurrency, edAmount.Value),
                  rec.Currency,
                  PCO_CHARGE,
                  False);
  if Assigned(charge) then
  begin
    edAmount.Value := charge.amount;
    rec.IsStored := true;
    btnOK.Click; // Payment is already registered
  end;
end;

procedure TfrmDownPayment.btnOkClick(Sender: TObject);
var
  balance : double;

begin
  zCanClose := true;

  balance := RoundDecimals(rec.InvoiceBalanceInCurrency-edAmount.value, 2);

  if edAmount.value = 0 then
  begin
    showmessage('Payment can not be 0');
    edAmount.SetFocus;
    zCanClose := false;
    exit;
  end;

  if NOT rec.NotInvoice then
    if (balance < 0) AND (NOT ctrlGetBoolean('AllowNegativeInvoice')) then
    begin
      showmessage('Payments can not be higher than the invoice amount');
      edAmount.SetFocus;
      zCanClose := false;
      exit;
    end;

  rec.AmountInCurrency          := edAmount.value;
  rec.Description     := edDescription.text;
  rec.Notes           := memNotes.Text;
  rec.PaymentType     := kbmPayType.FieldByName('payType').asstring;
  rec.InvoiceBalanceInCurrency  := balance;
end;


procedure TfrmDownPayment.btnManagePaycardsClick(Sender: TObject);
begin
  ManagePaymentCards(rec.Reservation, rec.RoomReservation, pcmCardsOnly);
  EnableDisableButtonViewPayCard;
end;

procedure TfrmDownPayment.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  canClose := zCanClose;
end;

procedure TfrmDownPayment.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
     glb.PerformAuthenticationAssertion(self); PlaceFormOnVisibleMonitor(self);
  g.initRecDownPayment(rec);
  zCanClose := true;
end;

procedure TfrmDownPayment.EnableDisableButtonViewPayCard;
var
  channelId: integer;
begin
  channelId := -1;
  btnManagePaycards.Enabled := AllowPaycardCharge and (rec.InvoiceIndex <= 0);
  btnChargePAyCard.Enabled := (rec.InvoiceIndex <= 0) and  ReservationHasPaycard(rec.Reservation, rec.RoomReservation, channelId);
end;

procedure TfrmDownPayment.FormShow(Sender: TObject);
var
   rSet : TRoomerDataset;
   s : string;

   defaultType : string;

begin
  lbCurrency.Caption             := rec.Currency;
  edAmount.Value                 := rec.AmountInCurrency;
  edDescription.text             := rec.Description;
  memNotes.Text                  := rec.Notes;

  defaultType := rec.PaymentType;
  //InvPriceGroup

  rSet := CreateNewDataSet;
  try
		s := '';
    s := s+'Select paytype,description,paygroup From paytypes where (active=true) and PayGroup <> '+_db(g.qInvPriceGroup)+' order by paygroup ';

//    _db(g.qInvPriceGroup)

    if rSet_bySQL(rSet,s) then
    begin
      LoadKbmMemtableFromDataSetQuiet(kbmPaytype,rSet,[]);
      if not kbmPaytype.Locate('Paytype',defaultType,[]) then
      begin
        kbmPaytype.First;
      end;
    end;
  finally
    freeandnil(rSet);
  end;

  EnableDisableButtonViewPayCard;
end;

procedure TfrmDownPayment.btnGetInvoiceBalanceClick(Sender: TObject);
begin
  edAmount.value := rec.InvoiceBalanceInCurrency;
end;

procedure TfrmDownPayment.tvPayTypeDblClick(Sender: TObject);
begin
  if (not SameValue(edAmount.Value, 0, 2)) AND (NOT kbmPayType.Eof) then
    btnOk.Click;
end;

end.
