unit uCalculationTypeDefinitions;

interface

uses
  Graphics
  , CLasses
  , uRoomerDefinitions, RoomerExceptionHandling
  ;

type

  {$SCOPEDENUMS ON}

  ECalculationTypeException = class(ERoomerException);

  ///	<summary>
  ///	  Possible states of a breakfast as part of a reservation
  ///	</summary>
  TCalculationType = (
    ctFixedAmount,
    ctPercentage
  );

    TCalculationTypeHelper = record helper for TCalculationType
    private const
      CALCULATION_TYPE_NAMES : Array[low(TCalculationType)..high(TCalculationType)] of String =
        ( 'FIXED_AMOUNT',
          'PERCENTAGE'
        );
    public
      /// <summary>
      ///   Return a TCalculationType based in string used in database.
      /// </summary>
      class function FromDBString(const Value: string; aDefault: TCalculationType = TCalculationType.ctFixedAmount): TCalculationType; static;
      /// <summary>
      ///   Return a TCalculationType based in index.
      /// </summary>
      class function FromItemIndex(aIndex: integer) : TCalculationType; static;

      /// <summary>
      ///   Fill a TStrings with translated descriptions in order of enumeration. Can by used to populate a TCombobox
      /// </summary>
      class procedure AsStrings(aItemList: TStrings); static;
      /// <summary>
      ///   Return the itemindex of TReservationState as it would have in the itemlist created by AsStrings
      /// </summary>
      function ToItemIndex: integer;
      /// <summary>
      ///   Return the string value used in the db to store a CaclulationType
      /// </summary>
      function ToDBString:string;

      /// <summary>
      ///   Return the translated displaystring for a TCalculationType
      /// </summary>
      function AsReadableString : string;
    end;


implementation

uses
    PrjConst
  , SysUtils
  , uUtils;


class procedure TCalculationTypeHelper.AsStrings(aItemList: TStrings);
var
  s: TCalculationType;
begin
  aItemList.Clear;
  for s := low(s) to high(s) do
    aItemList.Add(s.AsReadableString);
end;

class function TCalculationTypeHelper.FromDBString(const Value: string; aDefault: TCalculationType): TCalculationType;
var
  c: TCalculationType;
begin
  Result := aDefault;
  for c := low(c) to high(c) do
    if CALCULATION_TYPE_NAMES[c].ToUpper.Equals(Value.ToUpper) then
    begin
      Result := c;
      Break;
    end;
end;

class function TCalculationTypeHelper.FromItemIndex(aIndex: integer): TCalculationType;
begin
  Result := TCalculationType(aIndex);
end;

function TCalculationTypeHelper.AsReadableString : string;
begin
  case Self of
    TCalculationType.ctFixedAmount:     Result := GetTranslatedText('shTx_CalculationType_FixedAmount');
    TCalculationType.ctPercentage:  Result := GetTranslatedText('shTx_CalculationType_Percentage');
  else
    Result := '';
  end;
end;

function TCalculationTypeHelper.ToDBString: string;
begin
  Result := CALCULATION_TYPE_NAMES[Self];
end;

function TCalculationTypeHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;

end.
