unit uBreakfastTypeDefinitions;

interface

uses
  Graphics
  , CLasses
  , uRoomerDefinitions
  ;

type
  {$SCOPEDENUMS ON}
  ///	<summary>
  ///	  Possible states of a breakfast as part of a reservation
  ///	</summary>
  TBreakfastType= (
    None,
    Included,
    Excluded
  );

    TBreakfastTypeHelper = record helper for TBreakfastType
    private const
      BREAKFAST_NAMES : Array[low(TBreakfastType)..high(TBreakfastType)] of String =
        ( 'NONE',
          'INCLUDED',
          'EXCLUDED'
        );
    public
      class function FromBool(const aBreakfast: boolean): TBreakfastType; static; deprecated;

      class function FromDBString(const Value: string; aDefault: TBreakfastType = TBreakfastType.None): TBreakfastType; static;
      function ToDBString: string;

      /// <summary>
      ///   Return a TBreakfastType based in index.
      /// </summary>
      class function FromItemIndex(aIndex: integer) : TBreakfastType; static;

      /// <summary>
      ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
      /// </summary>
      class procedure AsStrings(aItemList: TStrings); static;
      /// <summary>
      ///   Return the itemindex of TReservationState as it would have in the itemlist created by AsStrings
      /// </summary>
      function ToItemIndex: integer;

      /// <summary>
      ///   Return a single character statusstring
      /// </summary>
      function AsBoolean: boolean; deprecated;

      /// <summary>
      ///   Return the translated displaystring for a TBreakfastType
      /// </summary>
      function AsReadableString : string;

    end;


implementation

uses
    PrjConst
  , SysUtils
  , uUtils;


class procedure TBreakfastTypeHelper.AsStrings(aItemList: TStrings);
var
  s: TBreakfastType;
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

class function TBreakfastTypeHelper.FromItemIndex(aIndex: integer): TBreakfastType;
begin
  Result := TBreakfastType(aIndex);
end;

class function TBreakfastTypeHelper.FromBool(const aBreakfast: boolean): TBreakfastType;
begin
  if aBreakfast then
    Result := TBreakfastType.Included
  else
    Result := TBreakfastType.None;
end;

function TBreakfastTypeHelper.AsBoolean: boolean;
begin
  Result := Self = TBreakfastType.Included;
end;

function TBreakfastTypeHelper.AsReadableString : string;
begin
  case Self of
    TBreakfastType.None:         Result := GetTranslatedText('shTx_ReservationProfile_NoBreakfast');
    TBreakfastType.Included:     Result := GetTranslatedText('shTx_ReservationProfile_Included');
    TBreakfastType.Excluded:  Result := GetTranslatedText('shTx_ReservationProfile_NotIncluded');
  else
    Result := '';
  end;
end;


function TBreakfastTypeHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;

class function TBreakfastTypeHelper.FromDBString(const Value: string; aDefault: TBreakfastType): TBreakfastType;
var
  c: TBreakfastType;
begin
  Result := aDefault;
  for c := low(c) to high(c) do
    if BREAKFAST_NAMES[c].ToUpper.Equals(Value.ToUpper) then
    begin
      Result := c;
      Break;
    end;
end;


function TBreakfastTypeHelper.ToDBString: string;
begin
  Result := BREAKFAST_NAMES[Self];
end;

end.
