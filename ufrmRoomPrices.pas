unit ufrmRoomPrices;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  cxStyles, dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData,
  cxButtonEdit, cxSpinEdit, cxCalc, dxmdaset, cxGridLevel, cxGridCustomTableView, cxGridTableView, cxGridDBTableView,
  cxGridCustomView, cxGrid, Vcl.StdCtrls, sCheckBox, sButton, sGroupBox, Vcl.ExtCtrls, sPanel, dxPScxCommon,
  dxPScxGridLnk, cxClasses, cxPropertiesStore, Vcl.ComCtrls, sStatusBar, sLabel, cxCurrencyEdit
  , uCurrencyHandler
  ;

type
  TfrmRoomPrices = class(TfrmBaseRoomerForm)
    pnlTopRoomRates: TsPanel;
    cxGroupBox4: TsGroupBox;
    btnRatePerDate: TsButton;
    btnApplyAllRoomtypes: TsButton;
    btnApplySameRoomType: TsButton;
    sGroupBox2: TsGroupBox;
    chkReCalcPrices: TsCheckBox;
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
    tvRoomResAvragePrice: TcxGridDBColumn;
    tvRoomResPackage: TcxGridDBColumn;
    tvRoomResRateCount: TcxGridDBColumn;
    tvRoomResPriceCode: TcxGridDBColumn;
    tvRoomResAvrageDiscount: TcxGridDBColumn;
    tvRoomResisPercentage: TcxGridDBColumn;
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
    mRoomResRoom: TStringField;
    mRoomResRoomType: TStringField;
    mRoomResGuests: TIntegerField;
    mRoomResAvragePrice: TFloatField;
    mRoomResRateCount: TIntegerField;
    mRoomResRoomDescription: TStringField;
    mRoomResRoomTypeDescription: TStringField;
    mRoomResArrival: TDateTimeField;
    mRoomResDeparture: TDateTimeField;
    mRoomResChildrenCount: TIntegerField;
    mRoomResinfantCount: TIntegerField;
    mRoomResPriceCode: TStringField;
    mRoomResAvrageDiscount: TFloatField;
    mRoomResisPercentage: TBooleanField;
    mRoomResPackage: TWideStringField;
    mRoomResInvoiceIndex: TIntegerField;
    mRoomResGroupAccount: TBooleanField;
    mRoomResGuestName: TWideStringField;
    mRoomResDS: TDataSource;
    mRoomRates: TdxMemData;
    mRoomRatesReservation: TIntegerField;
    mRoomRatesroomreservation: TIntegerField;
    mRoomRatesRoomNumber: TStringField;
    mRoomRatesRateDate: TDateTimeField;
    mRoomRatesPriceCode: TStringField;
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
    StringField3: TStringField;
    DateTimeField2: TDateTimeField;
    StringField4: TStringField;
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
    StringField1: TStringField;
    DateTimeField1: TDateTimeField;
    StringField2: TStringField;
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
    procedure tvRoomResGuestsPropertiesEditValueChanged(Sender: TObject);
    procedure tvRoomResChildrenCountPropertiesEditValueChanged(Sender: TObject);
    procedure tvRoomResinfantCountPropertiesEditValueChanged(Sender: TObject);
    procedure tvRoomResAvragePricePropertiesEditValueChanged(Sender: TObject);
    procedure btnRatePerDateClick(Sender: TObject);
    procedure btnApplyAllRoomtypesClick(Sender: TObject);
    procedure btnApplySameRoomTypeClick(Sender: TObject);
    procedure tvRoomResAvragePriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
  private
    FReservation: integer;
    FCurrency: string;
    FCurrencyRate: double;
    FCurrencyhandler: TCurrencyhandler;
    procedure EditRoomRateOneRoom(aRoomRes: integer);
    procedure ApplyRateToOther(RoomReservation: integer; const RoomType: string);
    procedure ApplyChanges;
    procedure CalcOnePrice(RoomReservation: integer; NewRate: Double = 0);
    procedure ApplyNettoRateToNullPrice(NewRate: Double; RoomReservation: integer; RoomType: string);
    procedure SetCurrency(const Value: string);
    { Private declarations }
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    property Reservation: integer read FReservation write FReservation;
    property Currency: string read FCurrency write SetCurrency;
  end;


  procedure EditRoomRates(aReservation: integer; const aCurrency: string);

implementation

uses
  uEditRoomPrice
  , hData, uG, uSQLUtils, uReservationStateDefinitions;

{$R *.dfm}

procedure EditRoomRates(aReservation: integer; const aCurrency: string);
var
  frm: TfrmRoomPrices;
begin
  frm := TfrmRoomPrices.Create(nil);
  try
    frm.Reservation := aReservation;
    frm.Currency := aCurrency;
    frm.ShowModal;
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
  Close;
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

procedure TfrmRoomPrices.tvRoomResAvragePriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  inherited;
  aProperties := FCurrencyhandler.GetcxEditProperties;
end;

procedure TfrmRoomPrices.tvRoomResAvragePricePropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: integer;
  RoomType: string;
  oldRate: Double;
  NewRate: Double;
begin
  RoomReservation := mRoomRes.FieldByName('RoomReservation').asinteger;
  oldRate := mRoomRes.FieldByName('avragePrice').asfloat;
  RoomType := mRoomRes.FieldByName('RoomType').asString;

  mRoomRes.post;
  NewRate := mRoomRes.FieldByName('avragePrice').asfloat;

  if oldRate <> NewRate then
    CalcOnePrice(RoomReservation, NewRate);

  if chkAutoUpdateNullPrice.checked then
    ApplyNettoRateToNullPrice(NewRate, RoomReservation, RoomType);

end;

procedure TfrmRoomPrices.tvRoomResChildrenCountPropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: integer;
  oldValue: integer;
  newValue: integer;
begin
  oldValue := mRoomRes.FieldByName('ChildrenCount').asinteger;
  RoomReservation := mRoomRes.FieldByName('RoomReservation').asinteger;
  mRoomRes.post;
  newValue := mRoomRes.FieldByName('ChildrenCount').asinteger;
  if newValue <> oldValue then
    CalcOnePrice(RoomReservation);

end;

procedure TfrmRoomPrices.tvRoomResEditColumnButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  EditRoomRateOneRoom(mRoomRes.FieldByName('roomreservation').asinteger);
end;

procedure TfrmRoomPrices.tvRoomResGuestsPropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: integer;
  oldValue: integer;
  newValue: integer;
begin
  oldValue := mRoomRes.FieldByName('guests').asinteger;
  RoomReservation := mRoomRes.FieldByName('RoomReservation').asinteger;
  mRoomRes.post;
  newValue := mRoomRes.FieldByName('guests').asinteger;
  if newValue <> oldValue then
    CalcOnePrice(RoomReservation);


end;

procedure TfrmRoomPrices.tvRoomResinfantCountPropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: integer;
  oldValue: integer;
  newValue: integer;
begin
  oldValue := mRoomRes.FieldByName('infantCount').asinteger;
  RoomReservation := mRoomRes.FieldByName('RoomReservation').asinteger;
  mRoomRes.post;
  newValue := mRoomRes.FieldByName('InfantCount').asinteger;
  if newValue <> oldValue then
  begin
    CalcOnePrice(RoomReservation);
  end;
end;

procedure TfrmRoomPrices.EditRoomRateOneRoom(aRoomRes: integer);
var
  theData: recEditRoomPriceHolder;

  reservation: integer;
  RoomReservation: integer;
  RoomNumber: string;
  PriceCode: string;
  RateDate: TDateTime;
  Rate: Double;
  Discount: Double;
  isPercentage: boolean;
  ShowDiscount: boolean;
  isPaid: boolean;
  DiscountAmount: Double;
  rentAmount: Double;
  NativeAmount: Double;
  AvrageAmount: Double;
  ttAmount: Double;
  AmountCount: integer;
  lstPrices: TStringList;
  RateCount: integer;

  ttDiscount: Double;
  AvrageDiscount: Double;

  applyType: integer;

begin
  applyType := 0;
  if mRR_.active then
    mRR_.close;
  lstPrices := TStringList.create;
  try
    lstPrices.Sorted := True;
    lstPrices.Duplicates := dupIgnore;

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
      if mRoomRates.FieldByName('roomreservation').asinteger = RoomReservation
      then
      begin
        mRR_.append;
        mRR_.FieldByName('Reservation').asinteger :=
          mRoomRates.FieldByName('Reservation').asinteger;
        mRR_.FieldByName('RoomReservation').asinteger :=
          mRoomRates.FieldByName('RoomReservation').asinteger;
        mRR_.FieldByName('RoomNumber').asString :=
          mRoomRates.FieldByName('RoomNumber').asString;
        mRR_.FieldByName('PriceCode').asString :=
          mRoomRates.FieldByName('PriceCode').asString;
        mRR_.FieldByName('RateDate').asdateTime :=
          mRoomRates.FieldByName('RateDate').asdateTime;
        mRR_.FieldByName('Rate').asfloat :=
          mRoomRates.FieldByName('Rate').asfloat;
        mRR_.FieldByName('Discount').asfloat :=
          mRoomRates.FieldByName('Discount').asfloat;
        mRR_.FieldByName('isPercentage').asBoolean :=
          mRoomRates.FieldByName('isPercentage').asBoolean;
        mRR_.FieldByName('ShowDiscount').asBoolean :=
          mRoomRates.FieldByName('ShowDiscount').asBoolean;
        mRR_.FieldByName('isPaid').asBoolean := mRoomRates.FieldByName('isPaid')
          .asBoolean;
        mRR_.FieldByName('DiscountAmount').asfloat :=
          mRoomRates.FieldByName('DiscountAmount').asfloat;
        mRR_.FieldByName('RentAmount').asfloat :=
          mRoomRates.FieldByName('RentAmount').asfloat;
        mRR_.FieldByName('NativeAmount').asfloat :=
          mRoomRates.FieldByName('NativeAmount').asfloat;
        mRR_.post;
      end;
      mRoomRates.Next;
    end;

    mRR_.first;

    theData.Room := mRR_.FieldByName('roomNumber').asString;
    ttAmount := 0;
    AmountCount := 0;
    ttDiscount := 0;
    isPercentage := false;

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

        lstPrices.add(floattostr(rentAmount));
        inc(AmountCount);
        ttAmount := ttAmount + rentAmount;
        ttDiscount := ttDiscount + Discount;

        if mRoomRates.Locate('RoomReservation;rateDate',
          VarArrayOf([RoomReservation, RateDate]), []) then
        begin
          mRoomRates.edit;
          mRoomRates.FieldByName('Reservation').asinteger := reservation;
          mRoomRates.FieldByName('RoomReservation').asinteger :=
            RoomReservation;
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
          AvrageAmount := ttAmount / AmountCount;
          AvrageDiscount := ttDiscount / AmountCount;

          RateCount := lstPrices.Count;
          mRoomRes.edit;
          mRoomRes.FieldByName('AvragePrice').asfloat := AvrageAmount;
          mRoomRes.FieldByName('RateCount').asinteger := RateCount;
          mRoomRes.FieldByName('PriceCode').asString := PriceCode;
          mRoomRes.FieldByName('AvrageDiscount').asfloat := AvrageDiscount;
          mRoomRes.FieldByName('isPercentage').asBoolean := isPercentage;
          mRoomRes.post;
        end;
      end;
    end;
  finally
    FreeAndNil(lstPrices);
    if mRR_.active then
      mRR_.close;
  end;

  if applyType = 2 then
    ApplyRateToOther(RoomReservation, theData.RoomType)
  else if applyType = 3 then
    ApplyRateToOther(RoomReservation, '');

end;

procedure TfrmRoomPrices.SetCurrency(const Value: string);
begin
  if FCurrency <> Value then
  begin
    FCurrency := Value;
    if assigned(FCurrencyhandler) then
      FCurrencyhandler.Free;

    FCurrencyhandler := TCurrencyHandler.Create(FCurrency);

    lblCurrency.Caption := FCurrencyhandler.CurrencyCode
  end;
end;

procedure TfrmRoomPrices.ApplyRateToOther(RoomReservation: integer; const RoomType: string);
var
  RateDate: TDateTime;
  PriceCode: string;
  Rate: Double;
  Discount: Double;
  isPercentage: boolean;
  ShowDiscount: boolean;
  isPaid: boolean;
  DiscountAmount: Double;
  rentAmount: Double;
  NativeAmount: Double;

  Arrival: TDateTime;
  Departure: TDateTime;

  AvragePrice: Double;
  RateCount: integer;
  AvrageDiscount: Double;
  Room: string;

  found: boolean;
  currentRoomReservation: integer;

begin
  // RoomReservation := mRoomRes.FieldByName('RoomReservation').AsInteger;
  // roomType        := mRoomRes.FieldByName('RoomType').AsString;

  Arrival := mRoomRes.FieldByName('Arrival').asdateTime;
  Departure := mRoomRes.FieldByName('Departure').asdateTime;
  AvragePrice := mRoomRes.FieldByName('AvragePrice').asfloat;
  RateCount := mRoomRes.FieldByName('RateCount').asinteger;
  PriceCode := mRoomRes.FieldByName('PriceCode').asString;
  AvrageDiscount := mRoomRes.FieldByName('AvrageDiscount').asfloat;
  isPercentage := mRoomRes.FieldByName('isPercentage').asBoolean;

  if mRoomRatesTmp.active then
    mRoomRatesTmp.close;
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
      if (mRoomRes.FieldByName('RoomReservation').asinteger <> RoomReservation)
        AND (mRoomRes.FieldByName('Arrival').asdateTime = Arrival) AND
        (mRoomRes.FieldByName('Departure').asdateTime = Departure) then
      begin
        currentRoomReservation := mRoomRes.FieldByName('RoomReservation')
          .asinteger;
        repeat
          found := mRoomRates.Locate('roomreservation',
            currentRoomReservation, []);
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
            DiscountAmount := mRoomRatesTmp.FieldByName
              ('DiscountAmount').asfloat;
            rentAmount := mRoomRatesTmp.FieldByName('RentAmount').asfloat;
            NativeAmount := mRoomRatesTmp.FieldByName('NativeAmount').asfloat;

            mRoomRates.append;
            mRoomRates.FieldByName('Reservation').asinteger := -1;
            mRoomRates.FieldByName('RoomReservation').asinteger :=
              currentRoomReservation;
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
        mRoomRes.FieldByName('AvragePrice').asfloat := AvragePrice;
        mRoomRes.FieldByName('RateCount').asinteger := RateCount;
        mRoomRes.FieldByName('PriceCode').asString := PriceCode;
        mRoomRes.FieldByName('AvrageDiscount').asfloat := AvrageDiscount;
        mRoomRes.FieldByName('isPercentage').asBoolean := isPercentage;
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
  RoomReservation: integer;
  AvragePrice: Double;
  RateCount: integer;
  Guests: integer;
  ChildrenCount: integer;
  infantCount: integer;
  PriceCode: string;
  Currency: string;

  AvrageDiscount: Double;

  RoomRate: Double;
  Discount: Double;
  isPercentage: boolean;
  ShowDiscount: boolean;
  RateDate: TDate;

  sDate: string;

  s: string;

begin
  // Apply changes and return
  Currency := FCurrency;

  mRoomRes.DisableControls;
  mRoomRates.DisableControls;
  try
    mRoomRes.first;
    while not mRoomRes.eof do
    begin
      // update values
      // reservation   := mRoomRes.FieldByName('Reservation').Asinteger;
      RoomReservation := mRoomRes.FieldByName('roomreservation').asinteger;
      AvragePrice := mRoomRes.FieldByName('avragePrice').asfloat;
      RateCount := mRoomRes.FieldByName('rateCount').asinteger;
      Guests := mRoomRes.FieldByName('guests').asinteger;
      ChildrenCount := mRoomRes.FieldByName('childrenCount').asinteger;
      infantCount := mRoomRes.FieldByName('infantCount').asinteger;
      PriceCode := mRoomRes.FieldByName('priceCode').asString;
      AvrageDiscount := mRoomRes.FieldByName('avrageDiscount').asfloat;
      isPercentage := mRoomRes.FieldByName('isPercentage').asBoolean;

      s := '';
      s := s + 'UPDATE `roomreservations` '#10;
      s := s + 'SET '#10;
      s := s + ' `Currency`    = ' + _db(Currency) + ' '#10;
      s := s + ',`PriceType`   = ' + _db(PriceCode) + ' '#10;
      s := s + ',`numGuests`   = ' + _db(Guests) + ' '#10;
      s := s + ',`numChildren` = ' + _db(ChildrenCount) + ' '#10;
      s := s + ',`numInfants`  = ' + _db(infantCount) + ' '#10;
      s := s + ',`AvrageRate`  = ' + _db(AvragePrice) + ' '#10;
      s := s + ',`RateCount`   = ' + _db(RateCount) + ' '#10;
      s := s + ',`Discount`    = ' + _db(AvrageDiscount) + ' '#10;
      s := s + ',`Percentage`  = ' + _db(isPercentage) + ' '#10;
      s := s + 'WHERE `roomreservation` = %d ';
      s := format(s, [RoomReservation]);
      cmd_bySQL(s);
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
      cmd_bySQL(s);
      mRoomRates.Next;
    end;
  finally
    mRoomRates.EnableControls;
    mRoomRes.EnableControls;
  end;
end;

procedure TfrmRoomPrices.CalcOnePrice(RoomReservation: integer; NewRate: Double = 0);
var
  lstPrices: TStringList;
  // RoomReservation : integer;

  ii: integer;

  Room: string;
  RoomType: string;
  Guests: integer;
  RateCount: integer;
  RoomDescription: string;
  RoomTypeDescription: string;
  Arrival: TDateTime;
  Departure: TDateTime;
  ChildrenCount: integer;
  infantCount: integer;
  DiscountAmount: Double;
  rentAmount: Double;
  NativeAmount: Double;

  priceID: integer;
  PriceCode: string;

  rateTotal: Double;
  rateAvrage: Double;

  DiscountTotal: Double;
  DiscountAvrage: Double;

  dayCount: integer;
  aDate: TDateTime;

  Rate: Double;

  isPercentage: boolean;
  isPaid: boolean;

  Currency: string;
  CurrencyRate: Double;
  Discount: Double;
  ShowDiscount: boolean;
  found: boolean;

begin
  lstPrices := TStringList.create;
  try
    lstPrices.Sorted := True;
    lstPrices.Duplicates := dupIgnore;

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
      RoomTypeDescription := mRoomRes.FieldByName
        ('RoomTypeDescription').asString;
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
      lstPrices.Clear;
      for ii := 0 to dayCount - 1 do
      begin
        if NewRate <> 0 then
        begin
          Rate := NewRate;
        end
        else
        begin
          Rate := GetDayRate(RoomType, Room, aDate, Guests, ChildrenCount,
            infantCount, Currency, priceID, Discount, ShowDiscount,
            isPercentage, isPaid, false);
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

        lstPrices.add(floattostr(rentAmount));
        rateTotal := rateTotal + rentAmount;
        DiscountTotal := DiscountTotal + Discount;
        aDate := aDate + 1
      end;

      if dayCount <> 0 then
      begin
        rateAvrage := rateTotal / dayCount;
        DiscountAvrage := DiscountTotal / dayCount;
      end
      else
      begin
        rateAvrage := 0;
        DiscountAvrage := 0;
      end;
      RateCount := lstPrices.Count;
      mRoomRes.edit;
      mRoomRes.FieldByName('AvragePrice').asfloat := rateAvrage;
      mRoomRes.FieldByName('RateCount').asfloat := RateCount;
      mRoomRes.FieldByName('AvrageDiscount').asfloat := DiscountAvrage;
      mRoomRes.post;
    end;
  finally
    FreeAndNil(lstPrices);
  end;
end;


constructor TfrmRoomPrices.Create(aOwner: TComponent);
begin
  inherited;
  FCurrencyhandler := TCurrencyHandler.Create(g.qNativeCurrency);
end;

destructor TfrmRoomPrices.Destroy;
begin
  FCurrencyhandler.Free;
  inherited;
end;

procedure TfrmRoomPrices.ApplyNettoRateToNullPrice(NewRate: Double; RoomReservation: integer; RoomType: string);
var
  currentRoomReservation: integer;
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
      if (mRoomRes.FieldByName('RoomReservation').asinteger <> RoomReservation)
      then
      begin
        currentRoomReservation := mRoomRes.FieldByName('RoomReservation')
          .asinteger;
        if mRoomRes.FieldByName('AvragePrice').asfloat = 0 then
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
