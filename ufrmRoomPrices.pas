unit ufrmRoomPrices;

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Variants,
  System.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  uRoomerForm,
  cxGraphics,
  cxControls,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  cxStyles,
  dxSkinsCore,
  dxSkinCaramel,
  dxSkinCoffee,
  dxSkinDarkSide,
  dxSkinTheAsphaltWorld,
  dxSkinsDefaultPainters,
  dxSkinscxPCPainter,
  cxCustomData,
  cxFilter,
  cxData,
  cxDataStorage,
  cxEdit,
  cxNavigator,
  Data.DB,
  cxDBData,
  cxButtonEdit,
  cxSpinEdit,
  cxCalc,
  dxmdaset,
  cxGridLevel,
  cxGridCustomTableView,
  cxGridTableView,
  cxGridDBTableView,
  cxGridCustomView,
  cxGrid,
  Vcl.StdCtrls,
  sCheckBox,
  sButton,
  sGroupBox,
  Vcl.ExtCtrls,
  sPanel,
  dxPScxCommon,
  dxPScxGridLnk,
  cxClasses,
  cxPropertiesStore,
  Vcl.ComCtrls,
  sStatusBar,
  sLabel,
  cxCurrencyEdit,
  uCurrencyHandler, cxCheckBox, uDImages;

type
  ERoomPricesException = class(Exception);

  TfrmRoomPrices = class(TfrmBaseRoomerForm)
    pnlTopRoomRates: TsPanel;
    cxGroupBox4: TsGroupBox;
    btnRatePerDate: TsButton;
    btnApplyAllRoomtypes: TsButton;
    btnApplySameRoomType: TsButton;
    sGroupBox2: TsGroupBox;
    chkAutoUpdateNullPrice: TsCheckBox;
    pnlButtons: TsPanel;
    btnCancel: TsButton;
    btnApply: TsButton;
    grRoomRes: TcxGrid;
    tvRoomRes: TcxGridDBTableView;
    tvRoomResEditButton: TcxGridDBColumn;
    tvRoomResRoom: TcxGridDBColumn;
    tvRoomResRoomDescription: TcxGridDBColumn;
    tvRoomResRoomType: TcxGridDBColumn;
    tvRoomResRoomTypeDescription: TcxGridDBColumn;
    tvRoomResGuestName: TcxGridDBColumn;
    tvRoomResArrival: TcxGridDBColumn;
    tvRoomResDeparture: TcxGridDBColumn;
    tvRoomResGuests: TcxGridDBColumn;
    tvRoomResChildrenCount: TcxGridDBColumn;
    tvRoomResinfantCount: TcxGridDBColumn;
    tvRoomResAveragePrice: TcxGridDBColumn;
    tvRoomResPackage: TcxGridDBColumn;
    tvRoomResRateCount: TcxGridDBColumn;
    tvRoomResPriceCode: TcxGridDBColumn;
    tvRoomResAverageDiscount: TcxGridDBColumn;
    tvRoomResRoomReservation: TcxGridDBColumn;
    tvRoomRates: TcxGridDBTableView;
    tvRoomRatesReservation: TcxGridDBColumn;
    tvRoomRatesRoomReservation: TcxGridDBColumn;
    tvRoomRatesRoomNumber: TcxGridDBColumn;
    tvRoomRatesRateDate: TcxGridDBColumn;
    tvRoomRatesPriceCode: TcxGridDBColumn;
    tvRoomRatesRate: TcxGridDBColumn;
    tvRoomRatesDiscount: TcxGridDBColumn;
    tvRoomRatesisPercentage: TcxGridDBColumn;
    tvRoomRatesShowDiscount: TcxGridDBColumn;
    tvRoomRatesisPaid: TcxGridDBColumn;
    tvRoomRatesDiscountAmount: TcxGridDBColumn;
    tvRoomRatesRentAmount: TcxGridDBColumn;
    tvRoomRatesNativeAmount: TcxGridDBColumn;
    lvRoomRes: TcxGridLevel;
    lvRoomRates: TcxGridLevel;
    mRoomRes: TdxMemData;
    mRoomResReservation: TIntegerField;
    mRoomResroomreservation: TIntegerField;
    mRoomResRoom: TWideStringField;
    mRoomResRoomType: TWideStringField;
    mRoomResGuests: TIntegerField;
    mRoomResAveragePrice: TFloatField;
    mRoomResRateCount: TIntegerField;
    mRoomResRoomDescription: TWideStringField;
    mRoomResRoomTypeDescription: TWideStringField;
    mRoomResArrival: TDateField;
    mRoomResDeparture: TDateField;
    mRoomResChildrenCount: TIntegerField;
    mRoomResinfantCount: TIntegerField;
    mRoomResPriceCode: TWideStringField;
    mRoomResAverageDiscount: TFloatField;
    mRoomResPackage: TWideStringField;
    mRoomResInvoiceIndex: TIntegerField;
    mRoomResGroupAccount: TBooleanField;
    mRoomResGuestName: TWideStringField;
    mRoomResDS: TDataSource;
    mRoomRates: TdxMemData;
    mRoomRatesReservation: TIntegerField;
    mRoomRatesroomreservation: TIntegerField;
    mRoomRatesRoomNumber: TWideStringField;
    mRoomRatesRateDate: TDateField;
    mRoomRatesPriceCode: TWideStringField;
    mRoomRatesRate: TFloatField;
    mRoomRatesDiscount: TFloatField;
    mRoomRatesisPercentage: TBooleanField;
    mRoomRatesShowDiscount: TBooleanField;
    mRoomRatesisPaid: TBooleanField;
    mRoomRatesDiscountAmount: TFloatField;
    mRoomRatesRentAmount: TFloatField;
    mRoomRatesNativeAmount: TFloatField;
    mRoomRatesGuestName: TWideStringField;
    kbmRoomRatesDS: TDataSource;
    mRR_: TdxMemData;
    IntegerField3: TIntegerField;
    IntegerField4: TIntegerField;
    StringField3: TWideStringField;
    DateTimeField2: TDateField;
    StringField4: TWideStringField;
    FloatField6: TFloatField;
    FloatField7: TFloatField;
    BooleanField4: TBooleanField;
    BooleanField5: TBooleanField;
    BooleanField6: TBooleanField;
    FloatField8: TFloatField;
    FloatField9: TFloatField;
    FloatField10: TFloatField;
    mRoomRatesTmp: TdxMemData;
    IntegerField1: TIntegerField;
    IntegerField2: TIntegerField;
    StringField1: TWideStringField;
    DateTimeField1: TDateField;
    StringField2: TWideStringField;
    FloatField1: TFloatField;
    FloatField2: TFloatField;
    BooleanField1: TBooleanField;
    BooleanField2: TBooleanField;
    BooleanField3: TBooleanField;
    FloatField3: TFloatField;
    FloatField4: TFloatField;
    FloatField5: TFloatField;
    gbxCurrency: TsGroupBox;
    lblCurrency: TsLabel;
    procedure btnApplyClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
    procedure tvRoomResEditColumnButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure tvRoomResAveragePricePropertiesEditValueChanged(Sender: TObject);
    procedure btnRatePerDateClick(Sender: TObject);
    procedure btnApplyAllRoomtypesClick(Sender: TObject);
    procedure btnApplySameRoomTypeClick(Sender: TObject);
    procedure tvRoomResAveragePriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure FormShow(Sender: TObject);
    procedure tvRoomRatesNativeAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
  private
    FRoomReservations: TStringlist;
    FCurrency: string;
    FCurrencyRate: double;
    FCurrencyhandler: TCurrencyhandler;
    FInvoiceIndex: Integer;
    FStartAtRoomRes: integer;
    procedure EditRoomRateOneRoom(aRoomRes: Integer);
    procedure ApplyRateToOther(RoomReservation: Integer; const RoomType: string);
    procedure ApplyChanges;
    procedure CalcOnePrice(RoomReservation: Integer; NewRate: double = 0);
    procedure ApplyNettoRateToNullPrice(NewRate: double; RoomReservation: Integer; RoomType: string);
    procedure SetCurrency(const Value: string);
    { Private declarations }
  protected
    procedure DoLoadData; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    property RoomReservations: TStringlist read FRoomReservations write FRoomReservations;
    property InvoiceIndex: Integer read FInvoiceIndex write FInvoiceIndex;
    property Currency: string read FCurrency write SetCurrency;
    property StartAtRoomRes: integer read FStartAtRoomRes write FStartAtRoomRes;
  end;

function EditRoomRates(aRoomReservations: TStringlist; aInvoiceindex: Integer = -1; const aCurrency: string = ''; aGotoRoomRes: integer = -1): boolean;

implementation

uses
  uEditRoomPrice,
  hData,
  uG,
  uSQLUtils,
  uReservationStateDefinitions,
  cmpRoomerDataset,
  uUtils, uD;

const
  // Params: Roomreservation, roomreservation and invoiceindex
  cSQL_GetRoomRes = ' SELECT DISTINCT '#10 +
    '  rr.Reservation '#10 +
    ' ,rr.Roomreservation '#10 +
    ' ,rr.Room '#10 +
    ' ,rr.Roomtype '#10 +
    ' ,r.Description as RoomDescription '#10 +
    ' ,rt.Description as RoomTypeDescription '#10 +
    ' ,(SELECT COUNT(id) FROM persons WHERE RoomReservation=rr.RoomReservation) AS Guests '#10 +
    ' ,IF(ISNULL((SELECT name FROM persons pe WHERE pe.MainName AND pe.roomreservation = rd.roomreservation LIMIT 1)), '#10+
    '   (SELECT name FROM persons pe WHERE pe.roomreservation = rd.roomreservation LIMIT 1), '#10 +
    '   (SELECT name FROM persons pe WHERE pe.MainName AND pe.roomreservation = rd.roomreservation LIMIT 1)) AS GuestName '#10+
    ' ,rr.numChildren as ChildrenCount '#10 +
    ' ,rr.numInfants as InfantCount '#10 +
    ' ,rr.AvrageRate as AveragePrice '#10 +
    ' ,rr.RateCount '#10 +
    ' ,rr.Discount as AverageDiscount '#10 +
//    ' ,rr.Percentage as IsPercentage '#10 +
    ' ,rr.Groupaccount '#10 +
    ' ,rr.Package '#10 +
    ' ,CAST(rr.Arrival as DATE) as Arrival '#10 +
    ' ,CAST(rr.Departure as Date) Departure '#10 +
    ' ,rr.PriceType as PriceCode '#10 +
    ' FROM roomreservations rr '#10 +
    ' JOIN (SELECT %d as Invoiceindex) params '#10+
    ' JOIN roomsdate rd on (rr.roomreservation=rd.roomreservation or rd.paidby=rr.roomreservation) and rd.paid=0 '#10+
    ' LEFT OUTER JOIN roomtypes rt ON rt.RoomType = rr.RoomType '#10 +
    ' LEFT OUTER JOIN rooms r ON r.Room = rr.room '#10 + ' WHERE rr.RoomReservation IN %s '#10 +
//    '      AND rr.GroupAccount = 0  '#10 +
    '      AND (params.InvoiceIndex=-1 or rr.InvoiceIndex = params.InvoiceIndex) '#10;

  cSQL_GetRoomRates = ' SELECT '#10 +
    '   rd.Reservation '#10 +
    '  ,rd.Roomreservation '#10 +
    '  ,rd.Room as Roomnumber '#10 +
    '  ,cast(aDate as DATE) as RateDate '#10 +
    '  ,PriceCode '#10 +
    '  ,Roomrate as Rate'#10 +
    '  ,rd.Discount '#10 +
    '  ,rd.IsPercentage '#10 +
    '  ,ShowDiscount '#10 +
    '  ,IF(rd.isPercentage, Roomrate * rd.Discount / 100, rd.Discount ) as DiscountAmount '#10 +
    '  ,Roomrate - IF(rd.isPercentage, Roomrate * rd.Discount / 100, rd.Discount ) as Rentamount '#10 +
    '  ,c.AValue * (Roomrate - IF(isPercentage, Roomrate * rd.Discount / 100, rd.Discount)) as NativeAmount '#10 +
    '  ,IF(ISNULL((SELECT name FROM persons pe WHERE pe.MainName AND pe.roomreservation = rd.roomreservation LIMIT 1)), '#10+
    '   (SELECT name FROM persons pe WHERE pe.roomreservation = rd.roomreservation LIMIT 1), '#10 +
    '   (SELECT name FROM persons pe WHERE pe.MainName AND pe.roomreservation = rd.roomreservation LIMIT 1)) AS GuestName '#10+
    ' FROM roomsdate rd '#10 +
    ' JOIN (SELECT %d as Invoiceindex) params '#10 +
    ' JOIN roomreservations rr on rr.roomreservation=rd.roomreservation AND (params.InvoiceIndex=-1 or rr.InvoiceIndex = params.InvoiceIndex) '#10+
    ' JOIN currencies c on c.currency=rd.currency '#10+
    ' WHERE rd.roomreservation in %s '#10 +
    '     and rd.paid = 0 '#10 +
    '     and rd.resflag <> ''X'' '#10;

{$R *.dfm}

function EditRoomRates(aRoomReservations: TStringlist; aInvoiceindex: Integer = -1; const aCurrency: string = ''; aGotoRoomRes: integer = -1): boolean;
var
  frm: TfrmRoomPrices;
  mr: integer;
begin
  if aRoomReservations.Count = 0 then
    raise ERoomPricesException.Create('No roomreservations specified to edit roomrates.');

  frm := TfrmRoomPrices.Create(nil);
  try
    frm.RoomReservations := aRoomReservations;
    frm.InvoiceIndex := aInvoiceindex;
    frm.Currency := iif(aCurrency = '', g.qNativeCurrency, aCurrency);
    frm.StartAtRoomRes := aGotoRoomRes;
    mr := frm.ShowModal;
    result := (mr = mrok);
  finally
    frm.Free;
  end;
end;

procedure TfrmRoomPrices.btnApplyAllRoomtypesClick(Sender: TObject);
begin
  inherited;
  ApplyRateToOther(mRoomRes.FieldByName('RoomReservation').asinteger, '');
end;

procedure TfrmRoomPrices.btnApplyClick(Sender: TObject);
begin
  inherited;
  ApplyChanges;
  // Form closed by Modalresult
end;

procedure TfrmRoomPrices.btnApplySameRoomTypeClick(Sender: TObject);
begin
  inherited;
  ApplyRateToOther(mRoomRes.FieldByName('RoomReservation').asinteger, mRoomRes.FieldByName('RoomType').asString)
end;

procedure TfrmRoomPrices.btnCancelClick(Sender: TObject);
begin
  inherited;
  Close;
end;

procedure TfrmRoomPrices.btnRatePerDateClick(Sender: TObject);
begin
  EditRoomRateOneRoom(mRoomRes.FieldByName('roomreservation').asinteger);
end;

procedure TfrmRoomPrices.tvRoomRatesNativeAmountGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  inherited;
  aProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmRoomPrices.tvRoomResAveragePriceGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  inherited;
  AProperties := FCurrencyhandler.GetcxEditPropertiesKeepEvents(aProperties);
end;

procedure TfrmRoomPrices.tvRoomResAveragePricePropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: Integer;
  RoomType: string;
  oldRate: double;
  NewRate: double;
begin
  RoomReservation := mRoomRes.FieldByName('RoomReservation').asinteger;
  oldRate := mRoomRes.FieldByName('AveragePrice').asfloat;
  RoomType := mRoomRes.FieldByName('RoomType').asString;

  mRoomRes.post;
  NewRate := mRoomRes.FieldByName('AveragePrice').asfloat;

  if oldRate <> NewRate then
    CalcOnePrice(RoomReservation, NewRate);

  if chkAutoUpdateNullPrice.checked then
    ApplyNettoRateToNullPrice(NewRate, RoomReservation, RoomType);

end;

procedure TfrmRoomPrices.tvRoomResEditColumnButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  EditRoomRateOneRoom(mRoomRes.FieldByName('roomreservation').asinteger);
end;

procedure TfrmRoomPrices.EditRoomRateOneRoom(aRoomRes: Integer);
var
  theData: recEditRoomPriceHolder;

  reservation: Integer;
  RoomReservation: Integer;
  RoomNumber: string;
  PriceCode: string;
  RateDate: TDateTime;
  Rate: double;
  Discount: double;
  isPercentage: boolean;
  ShowDiscount: boolean;
  isPaid: boolean;
  DiscountAmount: double;
  rentAmount: double;
  NativeAmount: double;
  AverageAmount: double;
  ttAmount: double;
  AmountCount: Integer;

  ttDiscountAmount: double;
  AverageDiscount: double;

  applyType: Integer;

begin
  applyType := 0;
  if mRR_.active then
    mRR_.Close;
  try
    initEditRoomPriceHolder(theData);
    theData.isCreateRes := True;

    theData.Currency := FCurrency; // edtCurrency.Text;
    theData.CurrencyRate := FCurrencyhandler.Rate;

    RoomReservation := mRoomRes.FieldByName('roomreservation').asinteger;
    theData.RoomType := mRoomRes.FieldByName('RoomType').asString;
    theData.Guests := mRoomRes.FieldByName('Guests').asinteger;
    theData.ChildrenCount := mRoomRes.FieldByName('childrenCount').asinteger;
    theData.infantCount := mRoomRes.FieldByName('infantCount').asinteger;

    mRR_.Open;

    mRoomRates.first;
    while not mRoomRates.eof do
    begin
      if mRoomRates.FieldByName('roomreservation').asinteger = RoomReservation then
      begin
        mRR_.append;
        mRR_.FieldByName('Reservation').asinteger := mRoomRates.FieldByName('Reservation').asinteger;
        mRR_.FieldByName('RoomReservation').asinteger := mRoomRates.FieldByName('RoomReservation').asinteger;
        mRR_.FieldByName('RoomNumber').asString := mRoomRates.FieldByName('RoomNumber').asString;
        mRR_.FieldByName('PriceCode').asString := mRoomRates.FieldByName('PriceCode').asString;
        mRR_.FieldByName('RateDate').asdateTime := mRoomRates.FieldByName('RateDate').asdateTime;
        mRR_.FieldByName('Rate').asfloat := mRoomRates.FieldByName('Rate').asfloat;
        mRR_.FieldByName('Discount').asfloat := mRoomRates.FieldByName('Discount').asfloat;
        mRR_.FieldByName('isPercentage').asBoolean := mRoomRates.FieldByName('isPercentage').asBoolean;
        mRR_.FieldByName('ShowDiscount').asBoolean := mRoomRates.FieldByName('ShowDiscount').asBoolean;
        mRR_.FieldByName('isPaid').asBoolean := mRoomRates.FieldByName('isPaid').asBoolean;
        mRR_.FieldByName('DiscountAmount').asfloat := mRoomRates.FieldByName('DiscountAmount').asfloat;
        mRR_.FieldByName('RentAmount').asfloat := mRoomRates.FieldByName('RentAmount').asfloat;
        mRR_.FieldByName('NativeAmount').asfloat := mRoomRates.FieldByName('NativeAmount').asfloat;
        mRR_.post;
      end;
      mRoomRates.Next;
    end;

    mRR_.first;

    theData.Room := mRR_.FieldByName('roomNumber').asString;
    ttAmount := 0;
    AmountCount := 0;
    ttDiscountAmount := 0;

    if editRoomPrice(actNone, theData, mRR_, applyType) then
    begin
      mRoomRates.DisableControls;
      try
        mRR_.first;
        while not mRR_.eof do
        begin
          reservation := mRR_.FieldByName('Reservation').asinteger;
          RoomReservation := mRR_.FieldByName('RoomReservation').asinteger;
          RoomNumber := mRR_.FieldByName('RoomNumber').asString;
          PriceCode := mRR_.FieldByName('PriceCode').asString;
          RateDate := mRR_.FieldByName('RateDate').asdateTime;
          Rate := mRR_.FieldByName('Rate').asfloat;
          Discount := mRR_.FieldByName('Discount').asfloat;
          isPercentage := mRR_.FieldByName('isPercentage').asBoolean;
          ShowDiscount := mRR_.FieldByName('ShowDiscount').asBoolean;
          isPaid := mRR_.FieldByName('isPaid').asBoolean;
          DiscountAmount := mRR_.FieldByName('DiscountAmount').asfloat;
          rentAmount := mRR_.FieldByName('RentAmount').asfloat;
          NativeAmount := mRR_.FieldByName('NativeAmount').asfloat;

          inc(AmountCount);
          ttAmount := ttAmount + rentAmount;
          ttDiscountAmount := ttDiscountAmount + DiscountAmount;

          if mRoomRates.Locate('RoomReservation;rateDate', VarArrayOf([RoomReservation, RateDate]), []) then
          begin
            mRoomRates.edit;
            mRoomRates.FieldByName('Reservation').asinteger := reservation;
            mRoomRates.FieldByName('RoomReservation').asinteger := RoomReservation;
            mRoomRates.FieldByName('RoomNumber').asString := RoomNumber;
            mRoomRates.FieldByName('PriceCode').asString := PriceCode;
            mRoomRates.FieldByName('RateDate').asdateTime := RateDate;
            mRoomRates.FieldByName('Rate').asfloat := Rate;
            mRoomRates.FieldByName('Discount').asfloat := Discount;
            mRoomRates.FieldByName('isPercentage').asBoolean := isPercentage;
            mRoomRates.FieldByName('ShowDiscount').asBoolean := ShowDiscount;
            mRoomRates.FieldByName('isPaid').asBoolean := isPaid;
            mRoomRates.FieldByName('DiscountAmount').asfloat := DiscountAmount;
            mRoomRates.FieldByName('RentAmount').asfloat := rentAmount;
            mRoomRates.FieldByName('NativeAmount').asfloat := NativeAmount;
            mRoomRates.post;
          end;
          mRR_.Next;
        end;
      finally
        mRoomRates.EnableControls;
      end;
      if mRoomRes.Locate('RoomReservation', RoomReservation, []) then
      begin
        if AmountCount <> 0 then
        begin
          AverageAmount := ttAmount / AmountCount;
          AverageDiscount := ttDiscountAmount / AmountCount;

          mRoomRes.edit;
          mRoomRes.FieldByName('AveragePrice').asfloat := AverageAmount;
          mRoomRes.FieldByName('RateCount').asinteger := AmountCount;
          mRoomRes.FieldByName('PriceCode').asString := PriceCode;
          mRoomRes.FieldByName('AverageDiscount').asfloat := AverageDiscount;
          mRoomRes.post;
        end;
      end;
    end;
  finally
    if mRR_.active then
      mRR_.Close;
  end;

  if applyType = 2 then
    ApplyRateToOther(RoomReservation, theData.RoomType)
  else if applyType = 3 then
    ApplyRateToOther(RoomReservation, '');

end;

procedure TfrmRoomPrices.FormShow(Sender: TObject);
begin
  inherited;
  RefreshData;
end;

procedure TfrmRoomPrices.SetCurrency(const Value: string);
begin
  if FCurrency <> Value then
  begin
    FCurrency := Value;
    if assigned(FCurrencyhandler) then
      FCurrencyhandler.Free;

    FCurrencyhandler := TCurrencyhandler.Create(FCurrency);

    lblCurrency.Caption := FCurrencyhandler.ShortDescription;
  end;
end;

procedure TfrmRoomPrices.ApplyRateToOther(RoomReservation: Integer; const RoomType: string);
var
  RateDate: TDateTime;
  PriceCode: string;
  Rate: double;
  Discount: double;
  isPercentage: boolean;
  ShowDiscount: boolean;
  isPaid: boolean;
  DiscountAmount: double;
  rentAmount: double;
  NativeAmount: double;

  Arrival: TDateTime;
  Departure: TDateTime;

  AveragePrice: double;
  RateCount: Integer;
  AverageDiscount: double;
  Room: string;

  found: boolean;
  currentRoomReservation: Integer;

begin
  // RoomReservation := mRoomRes.FieldByName('RoomReservation').AsInteger;
  // roomType        := mRoomRes.FieldByName('RoomType').AsString;

  Arrival := mRoomRes.FieldByName('Arrival').asdateTime;
  Departure := mRoomRes.FieldByName('Departure').asdateTime;
  AveragePrice := mRoomRes.FieldByName('AveragePrice').asfloat;
  RateCount := mRoomRes.FieldByName('RateCount').asinteger;
  PriceCode := mRoomRes.FieldByName('PriceCode').asString;
  AverageDiscount := mRoomRes.FieldByName('AverageDiscount').asfloat;

  if mRoomRatesTmp.active then
    mRoomRatesTmp.Close;
  mRoomRatesTmp.Open;
  mRoomRatesTmp.LoadFromDataSet(mRoomRates);

  // apply to same roomtype
  mRoomRates.DisableControls;
  mRoomRes.DisableControls;
  try
    mRoomRes.first;
    while not mRoomRes.eof do
    begin
      if RoomType <> '' then
      begin
        if (mRoomRes.FieldByName('RoomType').asString <> RoomType) then
        begin
          mRoomRes.Next;
          continue;
        end;
      end;
      if (mRoomRes.FieldByName('RoomReservation').asinteger <> RoomReservation) AND
        (mRoomRes.FieldByName('Arrival').asdateTime = Arrival) AND
        (mRoomRes.FieldByName('Departure').asdateTime = Departure) then
      begin
        currentRoomReservation := mRoomRes.FieldByName('RoomReservation').asinteger;
        repeat
          found := mRoomRates.Locate('roomreservation', currentRoomReservation, []);
          if found then
          begin
            mRoomRates.delete;
          end;
        until not found;
        mRoomRatesTmp.first;
        while not mRoomRatesTmp.eof do
        begin
          if mRoomRatesTmp['Roomreservation'] = RoomReservation then
          begin
            RateDate := mRoomRatesTmp.FieldByName('RateDate').asdateTime;
            Room := mRoomRatesTmp.FieldByName('RoomNumber').asString;
            PriceCode := mRoomRatesTmp.FieldByName('PriceCode').asString;
            Rate := mRoomRatesTmp.FieldByName('Rate').asfloat;
            Discount := mRoomRatesTmp.FieldByName('Discount').asfloat;
            isPercentage := mRoomRatesTmp.FieldByName('isPercentage').asBoolean;
            ShowDiscount := mRoomRatesTmp.FieldByName('ShowDiscount').asBoolean;
            isPaid := mRoomRatesTmp.FieldByName('isPaid').asBoolean;
            DiscountAmount := mRoomRatesTmp.FieldByName('DiscountAmount').asfloat;
            rentAmount := mRoomRatesTmp.FieldByName('RentAmount').asfloat;
            NativeAmount := mRoomRatesTmp.FieldByName('NativeAmount').asfloat;

            mRoomRates.append;
            mRoomRates.FieldByName('Reservation').asinteger := -1;
            mRoomRates.FieldByName('RoomReservation').asinteger := currentRoomReservation;
            mRoomRates.FieldByName('RoomNumber').asString := Room;
            mRoomRates.FieldByName('RateDate').asdateTime := RateDate;
            mRoomRates.FieldByName('PriceCode').asString := PriceCode;
            mRoomRates.FieldByName('Rate').asfloat := Rate;
            mRoomRates.FieldByName('Discount').asfloat := Discount;
            mRoomRates.FieldByName('isPercentage').asBoolean := isPercentage;
            mRoomRates.FieldByName('ShowDiscount').asBoolean := ShowDiscount;
            mRoomRates.FieldByName('isPaid').asBoolean := isPaid;
            mRoomRates.FieldByName('DiscountAmount').asfloat := DiscountAmount;
            mRoomRates.FieldByName('RentAmount').asfloat := rentAmount;
            mRoomRates.FieldByName('NativeAmount').asfloat := NativeAmount;
            mRoomRates.post;
          end;
          mRoomRatesTmp.Next;
        end;

        mRoomRes.edit;
        mRoomRes.FieldByName('AveragePrice').asfloat := AveragePrice;
        mRoomRes.FieldByName('RateCount').asinteger := RateCount;
        mRoomRes.FieldByName('PriceCode').asString := PriceCode;
        mRoomRes.FieldByName('AverageDiscount').asfloat := AverageDiscount;
        mRoomRes.post;
      end;
      mRoomRes.Next;
    end;
    mRoomRes.Locate('roomReservation', RoomReservation, []);
  finally
    mRoomRates.EnableControls;
    mRoomRes.EnableControls;
  end;
end;

procedure TfrmRoomPrices.ApplyChanges;
var
  RoomReservation: Integer;
  AveragePrice: double;
  RateCount: Integer;
  Guests: Integer;
  ChildrenCount: Integer;
  infantCount: Integer;
  PriceCode: string;
  Currency: string;

  AverageDiscount: double;

  RoomRate: double;
  Discount: double;
  isPercentage: boolean;
  ShowDiscount: boolean;
  RateDate: TDate;

  sDate: string;

  s: string;

  lExecPlan: TRoomerexecutionPlan;
begin
  // Apply changes and return
  Currency := FCurrency;

  mRoomRes.DisableControls;
  mRoomRates.DisableControls;
  lExecplan := d.roomerMainDataSet.CreateExecutionPlan;
  try

    mRoomRes.first;
    while not mRoomRes.eof do
    begin
      // update values
      // reservation   := mRoomRes.FieldByName('Reservation').Asinteger;
      RoomReservation := mRoomRes.FieldByName('roomreservation').asinteger;
      AveragePrice := mRoomRes.FieldByName('AveragePrice').asfloat;
      RateCount := mRoomRes.FieldByName('rateCount').asinteger;
      Guests := mRoomRes.FieldByName('guests').asinteger;
      ChildrenCount := mRoomRes.FieldByName('childrenCount').asinteger;
      infantCount := mRoomRes.FieldByName('infantCount').asinteger;
      PriceCode := mRoomRes.FieldByName('priceCode').asString;
      AverageDiscount := mRoomRes.FieldByName('AverageDiscount').asfloat;

      s := '';
      s := s + 'UPDATE `roomreservations` '#10;
      s := s + 'SET '#10;
      s := s + ' `Currency`    = ' + _db(Currency) + ' '#10;
      s := s + ',`PriceType`   = ' + _db(PriceCode) + ' '#10;
      s := s + ',`numGuests`   = ' + _db(Guests) + ' '#10;
      s := s + ',`numChildren` = ' + _db(ChildrenCount) + ' '#10;
      s := s + ',`numInfants`  = ' + _db(infantCount) + ' '#10;
      s := s + ',`AvrageRate`  = ' + _db(AveragePrice) + ' '#10;
      s := s + ',`RateCount`   = ' + _db(RateCount) + ' '#10;
      s := s + ',`Discount`    = ' + _db(AverageDiscount) + ' '#10;
      s := s + 'WHERE `roomreservation` = %d ';
      s := format(s, [RoomReservation]);

      lExecPlan.AddExec(s);
      mRoomRes.Next;
    end;

    mRoomRates.first;
    while not mRoomRates.eof do
    begin
      RoomReservation := mRoomRates.FieldByName('roomreservation').asinteger;
      PriceCode := mRoomRates.FieldByName('PriceCode').asString;
      RoomRate := mRoomRates.FieldByName('Rate').asfloat;
      Discount := mRoomRates.FieldByName('Discount').asfloat;
      isPercentage := mRoomRates.FieldByName('isPercentage').asBoolean;
      ShowDiscount := mRoomRates.FieldByName('showDiscount').asBoolean;
      RateDate := mRoomRates.FieldByName('RateDate').asdateTime;

      sDate := _db(RateDate, True);

      s := '';
      s := s + 'UPDATE `roomsdate` '#10;
      s := s + 'SET '#10;
      s := s + '`PriceCode`     =' + _db(PriceCode) + ' '#10;
      s := s + ',`RoomRate`     =' + _db(RoomRate) + ' '#10;
      s := s + ',`Currency`     =' + _db(Currency) + ' '#10;
      s := s + ',`Discount`     =' + _db(Discount) + ' '#10;
      s := s + ',`isPercentage` =' + _db(isPercentage) + ' '#10;
      s := s + ',`showDiscount` =' + _db(ShowDiscount) + ' '#10;
      s := s + 'WHERE '#10;
      s := s + ' (aDate = %s) '#10;
      s := s + 'AND (roomreservation = %d) '#10;
      s := s + '   AND (ResFlag <> ' + _db(rsDeleted.AsStatusChar) + ' ) ';

      s := format(s, [sDate, RoomReservation]);
      lExecPLan.AddExec(s);
      mRoomRates.Next;
    end;

    try
      lExecPlan.Execute(ptExec, True, True);
    except
      on E: Exception do
        raise ERoomPricesException.Create('Applying roomrates failed. Changes are not saved.'+ #10 + 'Error: ' + E.Message);
    end;
  finally
    lExecplan.Free;
    mRoomRates.EnableControls;
    mRoomRes.EnableControls;
  end;
end;

procedure TfrmRoomPrices.CalcOnePrice(RoomReservation: Integer; NewRate: double = 0);
var
  ii: Integer;

  Room: string;
  RoomType: string;
  Guests: Integer;
  RateCount: Integer;
  RoomDescription: string;
  RoomTypeDescription: string;
  Arrival: TDateTime;
  Departure: TDateTime;
  ChildrenCount: Integer;
  infantCount: Integer;
  DiscountAmount: double;
  rentAmount: double;
  NativeAmount: double;

  priceID: Integer;
  PriceCode: string;

  rateTotal: double;
  rateAverage: double;

  DiscountTotal: double;
  DiscountAverage: double;

  dayCount: Integer;
  aDate: TDateTime;

  Rate: double;

  isPercentage: boolean;
  isPaid: boolean;

  Currency: string;
  CurrencyRate: double;
  Discount: double;
  ShowDiscount: boolean;
  found: boolean;

begin
  Currency := FCurrency;
  CurrencyRate := FCurrencyRate;

  Discount := 0;
  ShowDiscount := false;
  isPercentage := false;
  isPaid := false;

  if mRoomRates.RecordCount <> 0 then
  begin
    mRoomRates.first;
    Discount := mRoomRates.FieldByName('Discount').asfloat;
    ShowDiscount := mRoomRates.FieldByName('isPercentage').asBoolean;
    isPercentage := mRoomRates.FieldByName('ShowDiscount').asBoolean;
  end;

  if mRoomRes.Locate('roomreservation', RoomReservation, []) then
  begin
    repeat
      found := mRoomRates.Locate('roomreservation', RoomReservation, []);
      if found then
      begin
        mRoomRates.delete;
      end;
    until not found;

    Room := mRoomRes.FieldByName('room').asString;
    Arrival := mRoomRes.FieldByName('arrival').asdateTime;
    Departure := mRoomRes.FieldByName('departure').asdateTime;
    RoomType := mRoomRes.FieldByName('RoomType').asString;
    RoomTypeDescription := mRoomRes.FieldByName('RoomTypeDescription').asString;
    RoomDescription := mRoomRes.FieldByName('RoomDescription').asString;
    Guests := mRoomRes.FieldByName('Guests').asinteger;
    ChildrenCount := mRoomRes.FieldByName('ChildrenCount').asinteger;
    infantCount := mRoomRes.FieldByName('infantCount').asinteger;
    PriceCode := mRoomRes.FieldByName('PriceCode').asString;
    priceID := hData.PriceCode_ID(PriceCode);

    dayCount := trunc(Departure) - trunc(Arrival);
    aDate := trunc(Arrival);
    rateTotal := 0;
    DiscountTotal := 0;
    RateCount := 0;
    for ii := 0 to dayCount - 1 do
    begin
      if NewRate <> 0 then
      begin
        Rate := NewRate;
      end
      else
      begin
        Rate := GetDayRate(RoomType, Room, aDate, Guests, ChildrenCount, infantCount, Currency, priceID, Discount,
          ShowDiscount, isPercentage, isPaid, false);
      end;

      DiscountAmount := 0;

      if Rate <> 0 then
      begin
        if Discount <> 0 then
        begin
          if isPercentage then
          begin
            DiscountAmount := Rate * Discount / 100;
          end
          else
          begin
            DiscountAmount := Discount;
          end;
        end;
      end;
      rentAmount := Rate - DiscountAmount;
      if CurrencyRate = 0 then
        CurrencyRate := 1;
      NativeAmount := rentAmount * CurrencyRate;

      mRoomRates.append;
      mRoomRates.FieldByName('Reservation').asinteger := -1;
      mRoomRates.FieldByName('RoomReservation').asinteger := RoomReservation;
      mRoomRates.FieldByName('RoomNumber').asString := Room;
      mRoomRates.FieldByName('RateDate').asdateTime := aDate;
      mRoomRates.FieldByName('PriceCode').asString := PriceCode;
      mRoomRates.FieldByName('Rate').asfloat := Rate;
      mRoomRates.FieldByName('Discount').asfloat := Discount;
      mRoomRates.FieldByName('isPercentage').asBoolean := isPercentage;
      mRoomRates.FieldByName('ShowDiscount').asBoolean := ShowDiscount;
      mRoomRates.FieldByName('isPaid').asBoolean := isPaid;
      mRoomRates.FieldByName('DiscountAmount').asfloat := DiscountAmount;
      mRoomRates.FieldByName('RentAmount').asfloat := rentAmount;
      mRoomRates.FieldByName('NativeAmount').asfloat := NativeAmount;
      mRoomRates.post;

      inc(RateCount);
      rateTotal := rateTotal + rentAmount;
      DiscountTotal := DiscountTotal + Discount;
      aDate := aDate + 1
    end;

    if dayCount <> 0 then
    begin
      rateAverage := rateTotal / dayCount;
      DiscountAverage := DiscountTotal / dayCount;
    end
    else
    begin
      rateAverage := 0;
      DiscountAverage := 0;
    end;
    mRoomRes.edit;
    mRoomRes.FieldByName('AveragePrice').asfloat := rateAverage;
    mRoomRes.FieldByName('RateCount').asfloat := RateCount;
    mRoomRes.FieldByName('AverageDiscount').asfloat := DiscountAverage;
    mRoomRes.post;
  end;

end;

constructor TfrmRoomPrices.Create(aOwner: TComponent);
begin
  inherited;
  FCurrencyhandler := TCurrencyhandler.Create(g.qNativeCurrency);
  FStartAtRoomRes := -1;
end;

destructor TfrmRoomPrices.Destroy;
begin
  FCurrencyhandler.Free;
  inherited;
end;

procedure TfrmRoomPrices.DoLoadData;
var
  lExecPlan: TRoomerExecutionPlan;
  lSQL: string;
  lRoomResList: string;
begin
  inherited;

  mRoomRates.DisableControls;
  mRoomRes.DisableControls;
  lExecPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    mRoomRates.Close;
    mRoomRes.Close;

    lRoomResList := '(' + FRoomReservations.CommaText + ')';
    lSQL := format(cSQL_GetRoomRes, [FInvoiceIndex, lRoomresList]);
    CopyToClipboard(lSQL);
    lExecPlan.AddQuery(lSQL);

    lSQL := format(cSQL_GetRoomRates, [FInvoiceIndex, lRoomresList]);
    CopyToClipboard(lSQL);
    lExecPlan.AddQuery(lSQL);

    lExecPlan.Execute(ptQuery);

    mRoomRes.LoadFromDataSet(lExecPlan.Results[0]);
    mRoomRates.LoadFromDataSet(lExecPlan.Results[1]);

    if StartAtRoomRes >= 0 then
      mRoomRes.Locate('roomreservation', StartAtRoomRes, []);

  finally
    lExecPlan.Free;
    mRoomRates.EnableControls;
    mRoomRes.EnableControls;
  end;
end;

procedure TfrmRoomPrices.ApplyNettoRateToNullPrice(NewRate: double; RoomReservation: Integer; RoomType: string);
var
  currentRoomReservation: Integer;
begin
  mRoomRates.DisableControls;
  mRoomRes.DisableControls;
  try
    mRoomRes.first;
    while not mRoomRes.eof do
    begin
      if RoomType <> '' then
      begin
        if (mRoomRes.FieldByName('RoomType').asString <> RoomType) then
        begin
          mRoomRes.Next;
          continue;
        end;
      end;
      if (mRoomRes.FieldByName('RoomReservation').asinteger <> RoomReservation) then
      begin
        currentRoomReservation := mRoomRes.FieldByName('RoomReservation').asinteger;
        if mRoomRes.FieldByName('AveragePrice').asfloat = 0 then
        begin
          CalcOnePrice(currentRoomReservation, NewRate);
        end;
      end;
      mRoomRes.Next;
    end;
    mRoomRes.Locate('roomReservation', RoomReservation, []);
  finally
    mRoomRates.EnableControls;
    mRoomRes.EnableControls;
  end;
end;

end.
