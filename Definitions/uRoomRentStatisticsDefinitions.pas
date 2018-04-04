unit uRoomRentStatisticsDefinitions;

interface

uses
  Classes
  ;

type
  {$SCOPEDENUMS ON}
  TRoomRentComparePeriod = (PreviousYear, PreviousMonth, NextYear, NextMonth);

  TRoomRentComparePeriodHelper = record helper for TRoomRentComparePeriod
  public
    /// <summary>
    ///   Return a Type based in index.
    /// </summary>
    class function FromItemIndex(aIndex: integer) : TRoomRentComparePeriod; static;

    /// <summary>
    ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
    /// </summary>
    class procedure AsStrings(aItemList: TStrings); static;
    /// <summary>
    ///   Return the itemindex of Type as it would have in the itemlist created by AsStrings
    /// </summary>
    function ToItemIndex: integer;

    /// <summary>
    ///   Return the translated displaystring for a type
    /// </summary>
    function AsReadableString : string;
  end;


  TRoomRentCompareData = (Revenue=1, Occupancy, ADR, RevPar, TotalDiscount, HighestRate, LowestRate, TotalGuests, SellableRooms, OutOfOrder, SoldRooms);
  TRoomRentCompareDataSet = set of TRoomRentCompareData;
  TRoomRentCompareDataHelper = record helper for TRoomRentCompareData
  public
    /// <summary>
    ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
    ///  Items.Objects is filled with TObject(ord())
    /// </summary>
    class procedure AsStrings(aItemList: TStrings); static;
    /// <summary>
    ///   Return the itemindex of Type as it would have in the itemlist created by AsStrings
    /// </summary>
    function ToItemIndex: integer;
    /// <summary>
    ///   Return the translated displaystring for a type
    /// </summary>
    function AsReadableString : string;
  end;

implementation

uses
  PrjConst
  ;

{ TRoomRentComparePeriodHelper }

function TRoomRentComparePeriodHelper.AsReadableString: string;
begin
  case Self of
    TRoomRentComparePeriod.PreviousYear:    Result := GetTranslatedText('shTx_RoomRentComparePeriod_PreviousYear');
    TRoomRentComparePeriod.PreviousMonth:   Result := GetTranslatedText('shTx_RoomRentComparePeriod_PreviousMonth');
    TRoomRentComparePeriod.NextYear:    Result := GetTranslatedText('shTx_RoomRentComparePeriod_NextYear');
    TRoomRentComparePeriod.NextMonth:   Result := GetTranslatedText('shTx_RoomRentComparePeriod_NextMonth');
  else
    Result := '';
  end;
end;

class procedure TRoomRentComparePeriodHelper.AsStrings(aItemList: TStrings);
var
  s: TRoomRentComparePeriod;
begin
  aItemList.BeginUpdate;
  try
    aItemList.Clear;
    for s := low(s) to high(s) do
      aItemList.Add(s.AsReadableString);
  finally
    aItemList.EndUpdate;
  end;
end;

class function TRoomRentComparePeriodHelper.FromItemIndex(aIndex: integer): TRoomRentComparePeriod;
begin
  Result := TRoomRentComparePeriod(aIndex);
end;

function TRoomRentComparePeriodHelper.ToItemIndex: integer;
begin
  Result := ord(self);
end;

{ TRoomRentCompareDataHelper }

function TRoomRentCompareDataHelper.AsReadableString: string;
begin
  case Self of
    TRoomRentCompareData.Revenue:       Result := GetTranslatedText('shTx_RoomRentCompareData_Revenue');
    TRoomRentCompareData.Occupancy:     Result := GetTranslatedText('shTx_RoomRentCompareData_Occupancy');
    TRoomRentCompareData.ADR:           Result := GetTranslatedText('shTx_RoomRentCompareData_ADR');
    TRoomRentCompareData.RevPar:        Result := GetTranslatedText('shTx_RoomRentCompareData_RevPar');
    TRoomRentCompareData.TotalDiscount: Result := GetTranslatedText('shTx_RoomRentCompareData_TotalDiscount');
    TRoomRentCompareData.HighestRate:   Result := GetTranslatedText('shTx_RoomRentCompareData_Highestrate');
    TRoomRentCompareData.LowestRate:    Result := GetTranslatedText('shTx_RoomRentCompareData_LowestRate');
    TRoomRentCompareData.TotalGuests:   Result := GetTranslatedText('shTx_RoomRentCompareData_TotalGuests');
    TRoomRentCompareData.SellableRooms:    Result := GetTranslatedText('shTx_RoomRentCompareData_TotalRooms');
    TRoomRentCompareData.OutOfOrder:    Result := GetTranslatedText('shTx_RoomRentCompareData_OutOfOrder');
    TRoomRentCompareData.SoldRooms:     Result := GetTranslatedText('shTx_RoomRentCompareData_SoldRooms');
  end;
end;

class procedure TRoomRentCompareDataHelper.AsStrings(aItemList: TStrings);
var
  s: TRoomRentCompareData;
begin
  aItemList.BeginUpdate;
  try
    aItemList.Clear;
    for s := low(s) to high(s) do
      aItemList.AddObject(s.AsReadableString, TObject(ord(s)));
  finally
    aItemList.EndUpdate;
  end;
end;

function TRoomRentCompareDataHelper.ToItemIndex: integer;
begin
  Result := ord(Self) -1;
end;

end.
