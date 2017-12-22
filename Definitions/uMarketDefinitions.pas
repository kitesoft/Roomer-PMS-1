unit uMarketDefinitions;

interface

uses
  Graphics
  , CLasses
  , uRoomerDefinitions
  ;

type
  ///	<summary>
  ///	  Possible states of market as part of a reservation
  ///	</summary>
  TReservationMarketType= (
    mtUnknown = -1,
    mtLeisure = 0,
    mtBusiness = 1
  );

    TReservationMarketTypeHelper = record helper for TReservationMarketType
    private const
      MARKETTYPE_NAMES : Array[low(TReservationMarketType)..high(TReservationMarketType)] of String =
        ( '',
          'LEISURE',
          'BUSINESS'
        );
    public
      /// <summary>
      ///   Return a TReservationMarketType based in index.
      /// </summary>
      class function FromItemIndex(aIndex: integer) : TReservationMarketType; static;

      /// <summary>
      ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
      /// </summary>
      class procedure AsStrings(aItemList: TStrings); static;
      /// <summary>
      ///   Return the itemindex of TReservationMarketType as it would have in the itemlist created by AsStrings
      /// </summary>
      function ToItemIndex: integer;

      /// <summary>
      ///   Return the translated displaystring for a TReservationMarketType
      /// </summary>
      function AsReadableString : string;

      class function FromDBString(const Value: string; aDefault: TReservationMarketType): TReservationMarketType; static;
      function ToDBString: string;

    end;


implementation

uses
    PrjConst
  , SysUtils
  , uUtils;


class procedure TReservationMarketTypeHelper.AsStrings(aItemList: TStrings);
var
  s: TReservationMarketType;
begin
  aItemList.Clear;
  for s := low(s) to high(s) do
    if s <> mtUnknown then
      aItemList.Add(s.AsReadableString);
end;

class function TReservationMarketTypeHelper.FromItemIndex(aIndex: integer): TReservationMarketType;
begin
  Result := TReservationMarketType(aIndex);
end;

function TReservationMarketTypeHelper.AsReadableString : string;
begin
  case Self of
    mtUnknown:    Result := '';
    mtBusiness:   Result := GetTranslatedText('shTx_MarketType_Business');
    mtLeisure:    Result := GetTranslatedText('shTx_MarketType_Leisure');
  else
    Result := '';
  end;
end;

function TReservationMarketTypeHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;

class function TReservationMarketTypeHelper.FromDBString(const Value: string; aDefault: TReservationMarketType): TReservationMarketType;
var
  c: TReservationMarketType;
begin
  Result := aDefault;
  for c := low(c) to high(c) do
    if MARKETTYPE_NAMES[c].ToUpper.Equals(Value.ToUpper) then
    begin
      Result := c;
      Break;
    end;
end;


function TReservationMarketTypeHelper.ToDBString: string;
begin
  Result := MARKETTYPE_NAMES[Self];
end;

end.
