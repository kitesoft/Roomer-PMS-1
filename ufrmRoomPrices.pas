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
  uCurrencyHandler, cxCheckBox, uDImages, kbmMemTable;

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
    tvRoomResAveragePriceDisplay: TcxGridDBColumn;
    tvRoomResPackage: TcxGridDBColumn;
    tvRoomResRateCount: TcxGridDBColumn;
    tvRoomResPriceCode: TcxGridDBColumn;
    tvRoomResAverageDiscount: TcxGridDBColumn;
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
    kbmRoomRatesDS: TDataSource;
    mRR_: TdxMemData;
    mRR_Reservation: TIntegerField;
    mRR_RoomReservation: TIntegerField;
    mRR_Roomnumber: TWideStringField;
    mRR_Ratedate: TDateField;
    mRR_Pricecode: TWideStringField;
    mRR_Rate: TFloatField;
    mRR_Discount: TFloatField;
    mRR_IsPercentage: TBooleanField;
    mRR_ShowDiscount: TBooleanField;
    mRR_IsPaid: TBooleanField;
    mRR_DiscountAmount: TFloatField;
    mRR_RentAmount: TFloatField;
    mRR_NativeAmount: TFloatField;
    gbxCurrency: TsGroupBox;
    lblCurrency: TsLabel;
    mRoomRatesDiscountAmount: TFloatField;
    mRoomRatesRentAmount: TFloatField;
    mRoomRatesNativeAmount: TFloatField;
    mRoomResAverageDiscount: TFloatField;
    mRoomResAveragePriceDisplay: TFloatField;
    tvRoomResroomreservation: TcxGridDBColumn;
    tvRoomResAveragePriceDB: TcxGridDBColumn;
    procedure btnApplyClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
    procedure tvRoomResEditColumnButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure tvRoomResAveragePricePropertiesEditValueChanged(Sender: TObject);
    procedure btnRatePerDateClick(Sender: TObject);
    procedure btnApplyAllRoomtypesClick(Sender: TObject);
    procedure btnApplySameRoomTypeClick(Sender: TObject);
    procedure tvRoomResAveragePriceDisplayGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure FormShow(Sender: TObject);
    procedure tvRoomRatesNativeAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvRoomRatesDiscountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure mRoomRatesCalcFields(DataSet: TDataSet);
    procedure mRoomResCalcFields(DataSet: TDataSet);
    procedure tvRoomResAveragepriceDisplayGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
  private
    FRoomReservations: TStringlist;
    FCurrency: string;
    FCurrencyhandler: TCurrencyhandler;
    FInvoiceIndex: Integer;
    FStartAtRoomRes: integer;
    procedure EditRoomRateOneRoom(aRoomRes: Integer);
    procedure ApplyRateToOther(aSourceRoomReservation: Integer; const aApplyToRoomType: string);
    procedure ApplyChanges;
    procedure CalcOnePrice(RoomReservation: Integer; NewRate: double = 0);
    procedure ApplyNettoRateToNullPrice(NewRate: double; RoomReservation: Integer; RoomType: string);
    procedure SetCurrency(const Value: string);
    function RoomResHasConstantRate(aRoomReservation: integer): boolean;
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
  uUtils
  , uD
  , Math
  , Generics.Collections
  , PrjConst
  , UITypes;

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
    ' ,(SELECT AVG(rd1.RoomRate) FROM roomsdate rd1 WHERE rd1.RoomReservation=rr.RoomReservation AND (rd1.ResFlag NOT IN (''X'',''C''))) AS AveragePrice '#10 +
    ' ,rr.RateCount '#10 +
    ' ,rr.Discount as AverageDiscount '#10 +
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
  ApplyRateToOther(mRoomResRoomReservation.asinteger, '');
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
  ApplyRateToOther(mRoomResRoomReservation.asinteger, mRoomResRoomType.asString)
end;

procedure TfrmRoomPrices.btnCancelClick(Sender: TObject);
begin
  inherited;
  Close;
end;

procedure TfrmRoomPrices.btnRatePerDateClick(Sender: TObject);
begin
  EditRoomRateOneRoom(mRoomResRoomreservation.asInteger);
end;

procedure TfrmRoomPrices.tvRoomRatesDiscountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  inherited;
  if not aRecord.Values[tvRoomRatesisPercentage.Index] then
    aProperties := FCurrencyhandler.GetcxEditProperties;
end;

procedure TfrmRoomPrices.tvRoomRatesNativeAmountGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  inherited;
  aProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmRoomPrices.tvRoomResAveragepriceDisplayGetDisplayText(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  inherited;
  if not VarIsNull(aRecord.Values[tvRoomResAveragePriceDB.Index]) then
    aText := FCurrencyhandler.FormattedValue(aRecord.Values[tvRoomResAveragePriceDB.Index]);
end;

procedure TfrmRoomPrices.tvRoomResAveragePriceDisplayGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  inherited;
  AProperties := FCurrencyhandler.GetcxEditPropertiesKeepEvents(aProperties);
end;

procedure TfrmRoomPrices.tvRoomResAveragePricePropertiesEditValueChanged(Sender: TObject);
var
  NewRate: double;
begin
  mRoomRes.post;
  NewRate := mRoomResAveragePriceDisplay.asfloat;

  if not SameValue(mRoomResAveragePrice.AsFloat, NewRate, 0.01) then
    CalcOnePrice(mRoomResRoomReservation.Asinteger, NewRate);

  if chkAutoUpdateNullPrice.checked then
    ApplyNettoRateToNullPrice(NewRate, mRoomResRoomReservation.Asinteger, mRoomResRoomType.asString);
end;

procedure TfrmRoomPrices.tvRoomResEditColumnButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  EditRoomRateOneRoom(mRoomResroomreservation.asinteger);
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

    RoomReservation := mRoomResroomreservation.asinteger;
    theData.RoomType := mRoomResRoomType.asString;
    theData.Guests := mRoomResGuests.asinteger;
    theData.ChildrenCount := mRoomReschildrenCount.asinteger;
    theData.infantCount := mRoomResinfantCount.asinteger;

    mRR_.Open;

    mRoomRates.first;
    while not mRoomRates.eof do
    begin
      if mRoomRatesroomreservation.asinteger = RoomReservation then
      begin
        mRR_.append;
        mRR_Reservation.asinteger := mRoomRatesReservation.asinteger;
        mRR_RoomReservation.asinteger := mRoomRatesRoomReservation.asinteger;
        mRR_RoomNumber.asString := mRoomRatesRoomNumber.asString;
        mRR_PriceCode.asString := mRoomRatesPriceCode.asString;
        mRR_RateDate.asdateTime := mRoomRatesRateDate.asdateTime;
        mRR_Rate.asfloat := mRoomRatesRate.asfloat;
        mRR_Discount.asfloat := mRoomRatesDiscount.asfloat;
        mRR_isPercentage.asBoolean := mRoomRatesisPercentage.asBoolean;
        mRR_ShowDiscount.asBoolean := mRoomRatesShowDiscount.asBoolean;
        mRR_isPaid.asBoolean := mRoomRatesisPaid.asBoolean;
        mRR_DiscountAmount.asfloat := mRoomRatesDiscountAmount.asfloat;
        mRR_RentAmount.asfloat := mRoomRatesRentAmount.asfloat;
        mRR_NativeAmount.asfloat := mRoomRatesNativeAmount.asfloat;
        mRR_.post;
      end;
      mRoomRates.Next;
    end;

    mRR_.first;

    theData.Room := mRR_.FieldByName('roomNumber').asString;

    if editRoomPrice(actNone, theData, mRR_, applyType) then
    begin
      mRoomRates.DisableControls;
      try
        mRR_.first;
        while not mRR_.eof do
        begin
          reservation := mRR_Reservation.asinteger;
          RoomReservation := mRR_RoomReservation.asinteger;
          RoomNumber := mRR_RoomNumber.asString;
          PriceCode := mRR_PriceCode.asString;
          RateDate := mRR_RateDate.asdateTime;
          Rate := mRR_Rate.asfloat;
          Discount := mRR_Discount.asfloat;
          isPercentage := mRR_isPercentage.asBoolean;
          ShowDiscount := mRR_ShowDiscount.asBoolean;
          isPaid := mRR_isPaid.asBoolean;

          if mRoomRates.Locate('RoomReservation;rateDate', VarArrayOf([RoomReservation, RateDate]), []) then
          begin
            mRoomRates.edit;
            mRoomRatesReservation.asinteger := reservation;
            mRoomRatesRoomReservation.asinteger := RoomReservation;
            mRoomRatesRoomNumber.asString := RoomNumber;
            mRoomRatesPriceCode.asString := PriceCode;
            mRoomRatesRateDate.asdateTime := RateDate;
            mRoomRatesRate.asfloat := Rate;
            mRoomRatesDiscount.asfloat := Discount;
            mRoomRatesisPercentage.asBoolean := isPercentage;
            mRoomRatesShowDiscount.asBoolean := ShowDiscount;
            mRoomRatesisPaid.asBoolean := isPaid;
            mRoomRates.post;
          end;
          mRR_.Next;
        end;
      finally
        mRoomRates.EnableControls;
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

  mRoomRes.Refresh;
end;

procedure TfrmRoomPrices.FormShow(Sender: TObject);
begin
  inherited;
  RefreshData;
end;

procedure TfrmRoomPrices.mRoomRatesCalcFields(DataSet: TDataSet);
begin
  inherited;

  mRoomRatesDiscountAmount.AsFloat := (IIF(mRoomRatesIsPercentage.AsBoolean,
                                           mRoomRatesRate.AsFloat* mRoomRatesDiscount.AsFloat /100,
                                           mRoomRatesDiscount.AsFloat));
  mRoomRatesRentAmount.AsFloat := mRoomRatesRate.AsFloat - mRoomRatesDiscountAmount.AsFloat;
  mRoomRatesNativeAmount.AsFloat := FCurrencyhandler.Rate * mRoomRatesRentAmount.AsFloat;
end;

procedure TfrmRoomPrices.mRoomResCalcFields(DataSet: TDataSet);
var
  bm: TBookMark;
  lTotalRent: double;
  lTotalDiscount: double;
  lCount: integer;
begin
  inherited;

  bm := mRoomRates.Bookmark;
  mRoomRates.DisableControls;
  try
    lTotalRent := 0;
    lTotalDiscount :=0;
    lCount := 0;
    if mROomRates.Active and mRoomRates.Locate('roomreservation', mRoomResroomreservation.AsInteger, []) then
      while not mRoomRates.Eof and (mRoomRatesroomreservation.AsInteger = mRoomResroomreservation.AsInteger) do
      begin
        lTotalRent := lTotalRent + mRoomRatesRate.AsFloat;
        lTotalDiscount := lTotalDiscount + mRoomRatesDiscountAmount.AsFloat;
        inc(lCount);
        mRoomRates.Next;
      end;

    if lCount > 0 then
    begin
      mRoomResAverageDiscount.AsFloat := lTotalDiscount / lCount;
      mRoomResAveragePrice.AsFloat := (lTotalRent - lTotalDiscount) / lCount;
      mRoomResRateCount.AsInteger := lCount;
    end;
  finally
    mRoomRates.Bookmark := bm;
    mRoomRates.EnableControls;
  end;

end;

procedure TfrmRoomPrices.SetCurrency(const Value: string);
begin
  if FCurrency <> Value then
  begin
    FCurrency := Value;
    FCurrencyhandler.Free;
    FCurrencyhandler := TCurrencyhandler.Create(FCurrency);
    lblCurrency.Caption := FCurrencyhandler.ShortDescription;
  end;
end;

function TfrmRoomPrices.RoomResHasConstantRate(aRoomReservation: integer): boolean;
var
  bm: TBookMark;
  lRate: double;
  lDiscount: double;
  lIsPercentage: boolean;
begin
  Result := True;
  bm := mRoomRates.Bookmark;
  mRoomRates.DisableControls;
  try
    if mRoomRates.Locate('roomreservation', aRoomReservation, []) then
    begin
      lRate := mRoomRatesRate.AsFloat;
      lDiscount := mRoomRatesDiscount.AsFloat;
      lIsPercentage := mRoomRatesisPercentage.AsBoolean;
      while not mRoomRates.Eof and (mRoomRatesroomreservation.AsInteger = aRoomReservation) do
      begin
        Result := SameValue(lRate, mRoomRatesRate.AsFloat, 0.01) and
                  SameValue(lDiscount, mRoomRatesDiscount.AsFloat, 0.01) and
                  (lIsPercentage = mRoomRatesisPercentage.AsBoolean);
        if not Result then
          Break
        else
          mRoomRates.Next;
      end;
    end;
  finally
    mRoomRates.Bookmark := bm;
    mROomRates.EnableControls;
  end;
end;


procedure TfrmRoomPrices.ApplyRateToOther(aSourceRoomReservation: Integer; const aApplyToRoomType: string);
var
  Arrival: TDate;
  Departure: TDate;

  lHasConstantRate: boolean;
  lSomeRoomsNotUpdated: boolean;
  lRoomResList: TList<integer>;
  lRoomResbm: TBookmark;

  lOrgRoomRates: TdxMemData;

begin

  mRoomRes.Locate('roomreservation', aSourceRoomReservation, []);
  Arrival := mRoomResArrival.AsDateTime;
  Departure := mRoomResDeparture.asDateTime;
  lSomeRoomsNotUpdated := false;

  lRoomResList := TList<integer>.Create;
  lRoomResbm := mRoomRes.Bookmark;
  mRoomRates.DisableControls;
  mRoomRes.DisableControls;
  try
    lHasConstantRate := RoomResHasConstantRate(aSourceRoomReservation);

    // Determine which roomreservations can be updated
    mRoomRes.First;
    while not mRoomRes.Eof do
    begin
      if (mRoomResroomreservation.AsInteger <> aSourceRoomReservation) and
         (aApplyToRoomType.IsEmpty or (aApplyToRoomType = mRoomResRoomType.AsString)) then

        if lHasConstantRate or (Arrival = mRoomResArrival.asDateTime) and (Departure =  mRoomResDeparture.asDateTime) then
          lRoomResList.Add(mRoomResroomreservation.AsInteger)
        else
          lSomeRoomsNotUpdated := true;

      mRoomRes.Next;
    end;

    if lSomeRoomsNotUpdated and (MessageDlg(GetTranslatedText('shRoomPrices_NotAllRoomsUpdated'), mtConfirmation, mbOKCancel, 0) = mrCancel) then
      Exit;


    lOrgRoomRates := TdxMemData.Create(nil);
    try
      lOrgRoomRates.CopyFromDataSet(mRoomRates);
      lOrgRoomRates.Locate('roomreservation', aSourceRoomReservation, []);

      mRoomRates.First;
      while not mRoomRates.Eof do
      begin
        if lRoomresList.Contains(mRoomRatesroomreservation.AsInteger) then
        begin
          if lHasConstantRate or lOrgRoomRates.Locate('roomreservation;ratedate', VarArrayOf([aSourceRoomReservation, mRoomRatesRateDate.AsDateTime]), []) then
          begin
            mRoomRates.Edit;
            try
              mRoomRatesRate.AsFloat := lOrgRoomRates.FieldByName('Rate').asFLoat;
              mRoomRatesDiscount.AsFloat := lOrgRoomRates.FieldByName('Discount').asFloat;
              mRoomRatesisPercentage.AsBoolean := lOrgRoomRates.FieldByName('IsPercentage').asBoolean;
              mRoomRates.Post;
            except
              mRoomRates.Cancel;
              raise;
            end;
          end;
        end;

        mRoomRates.Next;
      end;

    finally
      lOrgRoomRates.Free;
    end;

  finally
    lRoomResList.Free;
    mRoomRes.Bookmark := lRoomResbm;
    mRoomRates.EnableControls;
    mRoomRes.EnableControls;
  end;

end;

procedure TfrmRoomPrices.ApplyChanges;
var
  RoomReservation: Integer;
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
      // reservation   := mRoomResReservation.Asinteger;
      RoomReservation := mRoomResroomreservation.asinteger;
      RateCount := mRoomResrateCount.asinteger;
      Guests := mRoomResguests.asinteger;
      ChildrenCount := mRoomReschildrenCount.asinteger;
      infantCount := mRoomResinfantCount.asinteger;
      PriceCode := mRoomRespriceCode.asString;
      AverageDiscount := mRoomResAverageDiscount.asfloat;

      s := '';
      s := s + 'UPDATE `roomreservations` '#10;
      s := s + 'SET '#10;
      s := s + ' `Currency`    = ' + _db(Currency) + ' '#10;
      s := s + ',`PriceType`   = ' + _db(PriceCode) + ' '#10;
      s := s + ',`numGuests`   = ' + _db(Guests) + ' '#10;
      s := s + ',`numChildren` = ' + _db(ChildrenCount) + ' '#10;
      s := s + ',`numInfants`  = ' + _db(infantCount) + ' '#10;
      s := s + ',`RateCount`   = ' + _db(RateCount) + ' '#10;
      s := s + ',`AvrageRate`  = ' + _db(mRoomResAveragePrice.AsFloat) + ' '#10;
      s := s + ',`Discount`    = ' + _db(AverageDiscount) + ' '#10;
      s := s + 'WHERE `roomreservation` = %d ';
      s := format(s, [RoomReservation]);

      lExecPlan.AddExec(s);
      mRoomRes.Next;
    end;

    mRoomRates.first;
    while not mRoomRates.eof do
    begin
      RoomReservation := mRoomRatesroomreservation.asinteger;
      PriceCode := mRoomRatesPriceCode.asString;
      RoomRate := mRoomRatesRate.asfloat;
      Discount := mRoomRatesDiscount.asfloat;
      isPercentage := mRoomRatesisPercentage.asBoolean;
      ShowDiscount := mRoomRatesshowDiscount.asBoolean;
      RateDate := mRoomRatesRateDate.asdateTime;

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
      s := s + '   AND (ResFlag <> ' + _db(rsRemoved.AsStatusChar) + ' ) ';

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
  RoomDescription: string;
  RoomTypeDescription: string;
  Arrival: TDateTime;
  Departure: TDateTime;
  ChildrenCount: Integer;
  infantCount: Integer;

  priceID: Integer;
  PriceCode: string;

  dayCount: Integer;
  aDate: TDateTime;

  Rate: double;

  isPercentage: boolean;
  isPaid: boolean;

  Currency: string;
  Discount: double;
  ShowDiscount: boolean;
  found: boolean;

begin
  Currency := FCurrency;

  Discount := 0;
  ShowDiscount := false;
  isPercentage := false;
  isPaid := false;

  if mRoomRates.RecordCount <> 0 then
  begin
    mRoomRates.first;
    Discount := mRoomRatesDiscount.asfloat;
    ShowDiscount := mRoomRatesisPercentage.asBoolean;
    isPercentage := mRoomRatesShowDiscount.asBoolean;
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

    Room := mRoomResroom.asString;
    Arrival := mRoomResarrival.asdateTime;
    Departure := mRoomResdeparture.asdateTime;
    RoomType := mRoomResRoomType.asString;
    RoomTypeDescription := mRoomResRoomTypeDescription.asString;
    RoomDescription := mRoomResRoomDescription.asString;
    Guests := mRoomResGuests.asinteger;
    ChildrenCount := mRoomResChildrenCount.asinteger;
    infantCount := mRoomResinfantCount.asinteger;
    PriceCode := mRoomResPriceCode.asString;
    priceID := hData.PriceCode_ID(PriceCode);

    dayCount := trunc(Departure) - trunc(Arrival);
    aDate := trunc(Arrival);
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

      mRoomRates.append;
      mRoomRatesReservation.asinteger := -1;
      mRoomRatesRoomReservation.asinteger := RoomReservation;
      mRoomRatesRoomNumber.asString := Room;
      mRoomRatesRateDate.asdateTime := aDate;
      mRoomRatesPriceCode.asString := PriceCode;
      mRoomRatesRate.asfloat := Rate;
      mRoomRatesDiscount.asfloat := Discount;
      mRoomRatesisPercentage.asBoolean := isPercentage;
      mRoomRatesShowDiscount.asBoolean := ShowDiscount;
      mRoomRatesisPaid.asBoolean := isPaid;
      mRoomRates.post;

      aDate := aDate + 1
    end;
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
        if (mRoomResRoomType.asString <> RoomType) then
        begin
          mRoomRes.Next;
          continue;
        end;
      end;
      if (mRoomResRoomReservation.asinteger <> RoomReservation) then
      begin
        currentRoomReservation := mRoomResRoomReservation.asinteger;
        if mRoomResAveragePrice.asfloat = 0 then
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
