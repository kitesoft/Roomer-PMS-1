unit uCalculationTypeExtraDefinitions;

interface

uses
  Graphics
  , CLasses
  , uRoomerDefinitions, RoomerExceptionHandling
  ;

type

  {$SCOPEDENUMS ON}

  ECalculationTypeExtraException = class(ERoomerException);

  ///	<summary>
  ///	  Possible states of a breakfast as part of a reservation
  ///	</summary>
  TCalculationTypeExtra = (
    cteFixedAmount,
    ctePercentage,
    cteDeviatedPercentage
  );

    TCalculationTypeExtraHelper = record helper for TCalculationTypeExtra
    private const
      CALCULATION_TYPE__EXTRA_NAMES : Array[low(TCalculationTypeExtra)..high(TCalculationTypeExtra)] of String =
        ( 'FIXED_AMOUNT',
          'PERCENTAGE',
          'DEVIATED_PERCENTAGE'
        );
    public
      /// <summary>
      ///   Return a TCalculationTypeExtra based in string used in database.
      /// </summary>
      class function FromDBString(const Value: string; aDefault: TCalculationTypeExtra = TCalculationTypeExtra.cteFixedAmount): TCalculationTypeExtra; static;
      /// <summary>
      ///   Return a TCalculationTypeExtra based in index.
      /// </summary>
      class function FromItemIndex(aIndex: integer) : TCalculationTypeExtra; static;

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
      ///   Return the translated displaystring for a TCalculationTypeExtra
      /// </summary>
      function AsReadableString : string;
    end;


implementation

uses
    PrjConst
  , SysUtils
  , uUtils;


class procedure TCalculationTypeExtraHelper.AsStrings(aItemList: TStrings);
var
  s: TCalculationTypeExtra;
begin
  aItemList.Clear;
  for s := low(s) to high(s) do
    aItemList.Add(s.AsReadableString);
end;

class function TCalculationTypeExtraHelper.FromDBString(const Value: string; aDefault: TCalculationTypeExtra): TCalculationTypeExtra;
var
  c: TCalculationTypeExtra;
begin
  Result := aDefault;
  for c := low(c) to high(c) do
    if CALCULATION_TYPE__EXTRA_NAMES[c].ToUpper.Equals(Value.ToUpper) then
    begin
      Result := c;
      Break;
    end;
end;

class function TCalculationTypeExtraHelper.FromItemIndex(aIndex: integer): TCalculationTypeExtra;
begin
  Result := TCalculationTypeExtra(aIndex);
end;

function TCalculationTypeExtraHelper.AsReadableString : string;
begin
  case Self of
    TCalculationTypeExtra.cteFixedAmount:        Result := GetTranslatedText('shTx_CalculationType_FixedAmount');
    TCalculationTypeExtra.ctePercentage:         Result := GetTranslatedText('shTx_CalculationType_Percentage');
    TCalculationTypeExtra.cteDeviatedPercentage: Result := GetTranslatedText('shTx_CalculationType_DeviatedPercentage');
  else
    Result := '';
  end;
end;

function TCalculationTypeExtraHelper.ToDBString: string;
begin
  Result := CALCULATION_TYPE__EXTRA_NAMES[Self];
end;

function TCalculationTypeExtraHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;

end.
