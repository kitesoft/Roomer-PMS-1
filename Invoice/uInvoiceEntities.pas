unit uInvoiceEntities;

interface

uses
  Generics.Collections
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
    FNights: double;       // should be integer
    FVat: Double;
    FNumPersons: integer;
    FNumChildren: integer;
    FPrice: Double;
    FDiscount: Double;
    FBreakfastIncluded: boolean;
  public
    constructor Create; overload;
    constructor Create(_RoomItem: String; _Guests: Integer; _Children: Integer; _Nights: double; _Price: Double;
      _Vat: Double; _Discount: Double; _BreakfastIncluded: boolean); overload;

    function NumberOfNights: integer;

    property Reservation: integer read FReservation write FReservation;
    property RoomReservation: integer read FRoomReservation write FRoomreservation;
    property Room: string read FRoom write FRoom;
    property RoomItem: string read FRoomItem;
    property Name: string read FName write FName;
    property Arrival: TDateTime read FFrom write FFrom;
    property Departure: TDateTime read FTo write FTo;

    property Price: double read FPrice write FPrice;
    property Discount: double read FDiscount write FDiscount;
    property Vat: double read FVat write FVat;
    property BreakfastIncluded: boolean read FBreakfastIncluded write FBreakfastIncluded;
    property NumGuests: integer read FNumPersons write FNumPersons;
    property NumChildren: integer read FNumChildren write FNUmChildren;
    property Nights: double read FNights write FNights;
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
    FHasRoomRent: boolean;
    FInvoicelinesTotal: double;
    function GetHasInvoiceLines: boolean;
    function GetHasRoomRentItems: boolean;
  public
    constructor Create(aIndex: integer; aHasRoomRent: boolean; aInvoiceLinesTotal: double);
    property HasInvoiceLines: boolean read GetHasInvoiceLines;
    property HasRoomRentItems: boolean read GetHasRoomRentItems;
  end;

  TInvoiceIndexTotalList = class(TObjectDictionary<integer, TInvoiceIndexTotal>)
  private
    function GetHasInvoiceLines(aIndex: integer): boolean;
    function GetHasRoomRentItems(aIndex: integer): boolean;
  public
    constructor Create; reintroduce;
    procedure UpdateIndexTotals(aReservation: integer; aRoomReservation: Integer);
    property HasInvoiceLines[aIndex: integer]: boolean read GetHasInvoiceLines;
    property HasRoomRentItems[aIndex: integer]: boolean read GetHasRoomRentItems;
  end;

implementation

uses
  SysUtils
  , cmpRoomerDataset
  , hData
  , Math, uD;

constructor TInvoiceRoomEntity.Create(_RoomItem: String; _Guests: Integer; _Children: Integer; _Nights: double;
  _Price: double; _Vat, _Discount: Double; _BreakFastIncluded: boolean);
begin
  FRoomItem := _RoomItem;
  FNumPersons:= _Guests;
  FNumChildren := _Children;
  FNights := _Nights;
  FPrice := _Price;
  FDiscount := _Discount;
  FVat := _Vat;
  FBreakFastIncluded := _BreakFastIncluded;
end;

function TInvoiceRoomEntity.NumberOfNights: integer;
begin
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
    if lRoomEnt.BreakfastIncluded then
      inc(Result, lRoomEnt.NumGuests * trunc(lRoomEnt.Nights));
end;

{ TInvoiceIndexTotal }

constructor TInvoiceIndexTotal.Create(aIndex: integer; aHasRoomRent: boolean; aInvoiceLinesTotal: double);
begin
  FIndex := aIndex;
  FHasRoomRent := aHasRoomRent;
  FInvoicelinesTotal := aInvoiceLinesTotal;
end;

function TInvoiceIndexTotal.GetHasInvoiceLines: boolean;
begin
  Result := SameValue(FInvoicelinesTotal, 0.00); // TODO
end;

function TInvoiceIndexTotal.GetHasRoomRentItems: boolean;
begin
  Result := FHasRoomRent;
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

function TInvoiceIndexTotalList.GetHasRoomRentItems(aIndex: integer): boolean;
begin
  Result := ContainsKey(aIndex) and Items[aIndex].HasRoomRentItems;
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
    sql := sql + '     invoiceindex, '#10;
    sql := sql + '     sum(invoicelinesTotal) as invoicelinestotal, '#10;
    sql := sql + '     max(hasRoomRent) as hasroomrent '#10;
    sql := sql + ' from '#10;
    sql := sql + '  (select '#10;
    sql := sql + '       il.InvoiceIndex, '#10;
    sql := sql + '       sum(coalesce(il.total, 0)) as invoiceLinesTotal, '#10;
    sql := sql + '       false as hasRoomRent '#10;
    sql := sql + '   from invoicelines il '#10;
    sql := sql + '   where il.invoicenumber = -1 '#10;
    sql := sql + '   and il.reservation = %d '#10;
    sql := sql + '   and il.roomreservation = %d '#10;
    sql := sql + '   group by invoiceindex '#10;
    sql := sql + '   union '#10;
    sql := sql + '   select '#10;
    sql := sql + '       DISTINCT coalesce(rd.invoiceindex, rr.invoiceindex) as invoiceindex, '#10;
    sql := sql + '       0, '#10;
    sql := sql + '       true '#10;
    sql := sql + '   FROM roomreservations rr '#10;
    sql := sql + '   JOIN roomsdate rd on (rr.roomreservation = rd.roomreservation) or (rd.paidBy=rr.roomreservation) '#10;
    sql := sql + '   where rr.reservation = %d '#10;
    sql := sql + '   and rr.roomreservation = %d '#10;
    sql := sql + '   and not rd.paid '#10;
    sql := sql + '     ) u '#10;
    sql := sql + ' group by invoiceindex '#10;

    sql := format(sql, [aReservation, aRoomReservation, aReservation, aRoomReservation]);

    hData.rSet_bySQL(rSet, sql);
    rSet.First;
    while not rSet.Eof do
    begin
      Add(rSet.FieldByName('invoiceindex').AsInteger,
            TInvoiceIndexTotal.Create(rSet.FieldByName('invoiceindex').AsInteger,
                                      rSet.FieldByName('hasroomrent').AsInteger > 0,
                                      rSet.FieldByName('invoicelinestotal').AsFloat));
      rSet.next;
    end;

  finally
     rSet.Free;
  end;
end;

end.
