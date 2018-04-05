unit uInvoiceEntities;

interface

uses
  Generics.Collections, uBreakfastTypeDefinitions, uAmount
  ;

type
  TInvoiceRoomEntity = class
  private
    FReservation: integer;
    FRoomReservation: integer;
    FRoomItem: String;
    FName: string;
    FRoom: string;
    FFrom: TDateTime;
    FTo: TDateTime;
    FNights: integer;
    FVatPerNight: Double;
    FNumPersons: integer;
    FNumChildren: integer;
    FPrice: Double;
    FDiscount: Double;
    FCurrency: string;
    FCurrencyRate: double;
  private
    FBreakfast: TBreakfastType;
    FBreakfastPrice: TAmount;
    function GetNumberOfNights: integer;
  public
    constructor Create; overload;
    constructor Create(_RoomItem: String; _Guests: Integer; _Children: Integer; _Nights: integer; _Price: Double; _Currency: string;
      _CurrencyRate: double; _Vat: Double; _Discount: Double; _BreakFast: TBreakfastType); overload;

    property Reservation: integer read FReservation write FReservation;
    property RoomReservation: integer read FRoomReservation write FRoomreservation;
    property Room: string read FRoom write FRoom;
    property RoomItem: string read FRoomItem;
    property Name: string read FName write FName;
    property Arrival: TDateTime read FFrom write FFrom;
    property Departure: TDateTime read FTo write FTo;
    property Price: double read FPrice write FPrice;
    property Currency: string read FCurrency write FCurrency;
    property CurrencyRate: double read FCurrencyRate write FCurrencyRate;
    property DiscountAmount: double read FDiscount write FDiscount;
    property VatPerNight: double read FVatPerNight write FVatPerNight;
    property Breakfast: TBreakfastType read FBreakfast write FBreakfast;
    property BreakfastPrice: TAmount read FBreakfastPrice write FBreakfastPrice;
    property NumGuests: integer read FNumPersons write FNumPersons;
    property NumChildren: integer read FNumChildren write FNUmChildren;
    /// <summary>
    ///   Defaults to Departure - Arrival when not set, otherwise this is overriden by the set value
    /// </summary>
    property UnpaidNights: integer read GetNumberOfNights write FNights;
  end;

  TInvoiceItemEntity = class
  private
    FItem: String;
    FNumItems, FPrice, FVat: Double;
    function GetPriceExcl: Double;
  public
    constructor Create(_Item: String; _NumItems, _Price, _Vat: Double);

    property Item: string read FItem;
    property Price: double read FPrice;
    property NumItems: double read FNumItems;
    property VAT: double read FVat;
    property TotalWOVat: Double read GetPriceExcl;
  end;

  TInvoiceItemEntityDictionary = TObjectDictionary<String, TInvoiceItemEntity>;

  TInvoiceRoomEntityList = class(TObjectList<TInvoiceRoomEntity>)
  private
    function GetIncludedBreakfastCount: integer;
  public
    property IncludedBreakfastCount: integer read GetIncludedBreakfastCount;
  end;

  TInvoiceItemEntityList = class(TObjectList<TInvoiceItemEntity>)
  private
    function GetTotalPrice(aItem: string): double;
    function GetTotalVat(aItem: string): double;
  public
    property TotalPrice[aItem: string]: double read GetTotalPrice;
    property TotalVat[aItem: string]: double read GetTotalVat;
  end;

  TInvoiceIndexTotal = class(TObject)
  private
    FIndex: integer;
    FInvoiceIndexTotal: double;
    FRoomRentIndexTotal: double;
    FPaymentsIndexTotal: double;
    function GetHasInvoiceLines: boolean;
    function GetHasRoomRentItems: boolean;
    function GetHasPayments: boolean;
  public
    constructor Create(aIndex: integer; aRoomRentTotal: double; aInvoiceLinesTotal: double; aPaymentsTotal: double);
    property HasInvoiceLines: boolean read GetHasInvoiceLines;
    property HasRoomRentItems: boolean read GetHasRoomRentItems;
    property HasPayments: boolean read GetHasPayments;
    property InvoiceIndexTotal: double read FInvoiceIndexTotal write FInvoiceIndexTotal;
    property RoomRentIndexTotal: double read FRoomRentIndexTotal write FRoomRentIndexTotal;
    property PaymentsIndexTotal: double read FPaymentsIndexTotal write FPaymentsIndexTotal;
  end;

  TInvoiceIndexTotalList = class(TObjectDictionary<integer, TInvoiceIndexTotal>)
  private
    function GetHasInvoiceLines(aIndex: integer): boolean;
    function GetHasRoomRentItems(aIndex: integer): boolean;
    function GetTotalInvoiceLinesOnIndex(aIndex: integer): double;
    function GetTotalRoomRentOnIndex(aIndex: integer): double;
    function GetHasPaymentItems(aIndex: integer): boolean;
    function GetTotalPaymentsOnIndex(aIndex: integer): double;
  public
    constructor Create; reintroduce;
    procedure UpdateIndexTotals(aReservation: integer; aRoomReservation: Integer);
    property HasInvoiceLines[aIndex: integer]: boolean read GetHasInvoiceLines;
    property HasRoomRentItems[aIndex: integer]: boolean read GetHasRoomRentItems;
    property HasPaymentItems[aIndex: integer]: boolean read GetHasPaymentItems;
    property TotalInvoiceLinesOnIndex[aIndex: integer]: double read GetTotalInvoiceLinesOnIndex;
    property TotalRoomRentOnIndex[aIndex: integer]: double read GetTotalRoomRentOnIndex;
    property TotalPaymentsOnIndex[aIndex: integer]: double read GetTotalPaymentsOnIndex;
  end;

implementation

uses
  SysUtils
  , cmpRoomerDataset
  , hData
  , Math, uD;

constructor TInvoiceRoomEntity.Create(_RoomItem: String; _Guests: Integer; _Children: Integer; _Nights: integer;
  _Price: double; _Currency: string; _CurrencyRate: double; _Vat, _Discount: Double; _BreakFast: TBreakfastType);
begin
  FRoomItem := _RoomItem;
  FNumPersons:= _Guests;
  FNumChildren := _Children;
  FPrice := _Price;
  FNights := _Nights;
  FCurrency := _Currency;
  FCUrrencyRate := _CurrencyRate;
  FDiscount := _Discount;
  FVatPerNight := _Vat;
  FBreakfast := _BreakFast;
end;

function TInvoiceRoomEntity.GetNumberOfNights: integer;
begin
  if FNights > 0 then
    Result := FNights
  else
    Result := trunc(Departure - Arrival);
end;

{ TInvoiceItemEntity }

constructor TInvoiceItemEntity.Create(_Item: String; _NumItems, _Price, _Vat: Double);
begin
  FItem := _Item;
  FNumItems := _NumItems;
  FPrice := _Price;
  FVat := _Vat;
end;

function TInvoiceItemEntity.GetPriceExcl: Double;
begin
  result := FPrice - FVat;
end;

{ TInvoiceItemEntityList }

function TInvoiceItemEntityList.GetTotalPrice(aItem: string): double;
var
  lItem: TInvoiceItemEntity;
begin
  Result := 0.0;
  for lItem in Self do
    if aItem.Equals(lItem.Item) then
      Result := Result + (lItem.Price * lItem.NumItems);
end;

function TInvoiceItemEntityList.GetTotalVat(aItem: string): double;
var
  lItem: TInvoiceItemEntity;
begin
  Result := 0.0;
  for lItem in Self do
    if aItem.Equals(lItem.Item) then
      Result := Result + (lItem.Vat* lItem.NumItems);
end;

constructor TInvoiceRoomEntity.Create;
begin

end;

{ TInvoiceRoomEntityList }

function TInvoiceRoomEntityList.GetIncludedBreakfastCount: integer;
var
  lRoomEnt: TInvoiceRoomEntity;
begin
  Result := 0;
  for lRoomEnt in Self do
    if lRoomEnt.Breakfast = TBreakfastType.Included then
      inc(Result, lRoomEnt.NumGuests * trunc(lRoomEnt.UnpaidNights));
end;

{ TInvoiceIndexTotal }

constructor TInvoiceIndexTotal.Create(aIndex: integer; aRoomRentTotal: double; aInvoiceLinesTotal: double; aPaymentsTotal: double);
begin
  FIndex := aIndex;
  FInvoiceIndexTotal := aInvoiceLinesTotal;
  FRoomRentIndexTotal := aRoomRentTotal;
  FPaymentsIndexTotal := aPaymentsTotal;
end;

function TInvoiceIndexTotal.GetHasInvoiceLines: boolean;
begin
  Result := not SameValue(FInvoiceIndexTotal, 0.00); // TODO
end;

function TInvoiceIndexTotal.GetHasPayments: boolean;
begin
  Result := not SameValue(FPaymentsIndexTotal, 0.00);
end;

function TInvoiceIndexTotal.GetHasRoomRentItems: boolean;
begin
  Result := not SameValue(FRoomRentIndexTotal, 0.00);
end;

{ TInvoiceIndexTotalList }

constructor TInvoiceIndexTotalList.Create;
begin
  inherited Create([doOwnsValues]);
end;

function TInvoiceIndexTotalList.GetHasInvoiceLines(aIndex: integer): boolean;
begin
  Result := ContainsKey(aIndex) and Items[aIndex].HasInvoiceLines;
end;

function TInvoiceIndexTotalList.GetHasPaymentItems(aIndex: integer): boolean;
begin
  Result := ContainsKey(aIndex) and Items[aIndex].HasPayments;
end;

function TInvoiceIndexTotalList.GetHasRoomRentItems(aIndex: integer): boolean;
begin
  Result := ContainsKey(aIndex) and Items[aIndex].HasRoomRentItems;
end;

function TInvoiceIndexTotalList.GetTotalInvoiceLinesOnIndex(aIndex: integer): double;
begin
  if ContainsKey(aIndex) then
    Result := Items[aIndex].InvoiceIndexTotal
  else
    Result := 0;
end;

function TInvoiceIndexTotalList.GetTotalPaymentsOnIndex(aIndex: integer): double;
begin
  if ContainsKey(aIndex) then
    Result := Items[aIndex].PaymentsIndexTotal
  else
    Result := 0;
end;

function TInvoiceIndexTotalList.GetTotalRoomRentOnIndex(aIndex: integer): double;
begin
  if ContainsKey(aIndex) then
    Result := Items[aIndex].RoomRentIndexTotal
  else
    Result := 0;
end;

procedure TInvoiceIndexTotalList.UpdateIndexTotals(aReservation: integer; aRoomReservation: Integer);
var
  sql: string;
  rSet: TRoomerDataset;
begin

  Clear;

  rSet := CreateNewDataset;
  try
    sql := '';

    sql := sql + ' select '#10;
    sql := sql + '     invoiceindex '#10;
    sql := sql + '     ,sum(coalesce(invoicelinesTotal,0)) as invoicelinestotal '#10;
    sql := sql + '     ,sum(coalesce(RoomrentTotal,0)) as RoomrentTotal  '#10;
    sql := sql + '     ,sum(coalesce(PaymentsTotal,0)) as PaymentsTotal  '#10;
    sql := sql + ' from '#10;
    sql := sql + '  (   select '#10;
    sql := sql + '       il.InvoiceIndex as invoiceindex '#10;
    sql := sql + '       ,sum(coalesce(il.total, 0)) as invoiceLinesTotal '#10;
    sql := sql + '       ,0 as Roomrenttotal '#10;
    sql := sql + '       ,0 as PaymentsTotal '#10;
    sql := sql + '     from invoicelines il '#10;
    sql := sql + '     where il.invoicenumber = -1 '#10;
    sql := sql + '     and il.reservation = %d '#10;
    sql := sql + '     and il.roomreservation = %d '#10;
    sql := sql + '     group by invoiceindex '#10;
    sql := sql + '   union '#10;
    sql := sql + '    select '#10;
    sql := sql + '         coalesce(rd.invoiceindex, rr.invoiceindex) as rateInvIndex '#10;
    sql := sql + '         ,0 '#10;
    sql := sql + '         ,sum(coalesce(rd.roomrate,0)) '#10;
    sql := sql + '         ,0 as PaymentsTotal '#10;
    sql := sql + '    from roomreservations rr '#10;
    sql := sql + '    join roomsdate rd on rd.roomreservation=rr.roomreservation and not rd.paid '#10;
    sql := sql + '    where (%d<>0 and ((rr.reservation=%d and rr.roomreservation = %d) or rd.paidBy=%d) or '#10;
    sql := sql + '           (%d=0 and rr.reservation=%d and rr.groupaccount)) '#10;
    sql := sql + '    group by rateInvIndex '#10;
    sql := sql + '   union '#10;
    sql := sql + '    select '#10;
    sql := sql + '         coalesce(p.invoiceindex, rr.invoiceindex) as PaymentsInvIndex '#10;
    sql := sql + '         ,0 '#10;
    sql := sql + '         ,0 '#10;
    sql := sql + '         ,sum(coalesce(p.Amount,0)) as PaymentsTotal '#10;
    sql := sql + '    from roomreservations rr '#10;
    sql := sql + '    join payments p on p.reservation=rr.reservation and p.invoicenumber <= 0'#10;
    sql := sql + '    where (%d<>0 and p.reservation=%d and p.roomreservation = %d) or '#10;
    sql := sql + '           (%d=0 and p.reservation=%d and rr.groupaccount) '#10;
    sql := sql + '    group by PaymentsInvIndex '#10;
    sql := sql + '     ) u '#10;
    sql := sql + ' where invoicelinestotal <> 0 or roomrenttotal <> 0 or paymentstotal <> 0 '#10;
    sql := sql + ' group by invoiceindex '#10;

    sql := format(sql, [aReservation, aRoomReservation,
                        aRoomReservation, aReservation, aRoomReservation, aRoomReservation, aRoomReservation, aReservation,
                        aRoomReservation, aReservation, aRoomReservation, aRoomReservation, aReservation]);

    hData.rSet_bySQL(rSet, sql);
    rSet.First;
    while not rSet.Eof do
    begin
      Add(rSet.FieldByName('invoiceindex').AsInteger,
            TInvoiceIndexTotal.Create(rSet.FieldByName('invoiceindex').AsInteger,
                                      rSet.FieldByName('RoomRentTotal').AsFloat,
                                      rSet.FieldByName('invoicelinestotal').AsFloat,
                                      rSet.FieldByName('Paymentstotal').AsFloat)
                                     );
      rSet.next;
    end;
  finally
     rSet.Free;
  end;
end;

end.
