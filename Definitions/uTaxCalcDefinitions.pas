unit uTaxCalcDefinitions;

interface

uses
  Graphics
  , CLasses
  , uRoomerDefinitions, RoomerExceptionHandling
  ;

type

  {$SCOPEDENUMS ON}
  ETaxCalcDefinitionException = class(ERoomerException);

  ///	<summary>
  ///	  Possible Probedates for tax calculations
  ///	</summary>
  TTaxProbeDate = (InvoiceDate, StayDate);

  TTaxProbeDateHelper = record helper for TTaxProbeDate
    private const
      TAXPROBEDATE_NAMES : Array[low(TTaxProbeDate)..high(TTaxProbeDate)] of String =
        ( 'INVOICEDATE',
          'STAYDATE'
        );
    public
      /// <summary>
      ///   Return a TTaxProbeDate based in string used in database.
      /// </summary>
      class function FromDBString(const Value: string; aDefault: TTaxProbeDate = TTaxProbeDate.InvoiceDate): TTaxProbeDate; static;
      /// <summary>
      ///   Return a TTaxProbeDate based in index.
      /// </summary>
      class function FromItemIndex(aIndex: integer) : TTaxProbeDate; static;

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
      ///   Return the translated displaystring for a TTaxProbeDate
      /// </summary>
      function AsReadableString : string;
    end;


implementation

uses
    PrjConst
  , SysUtils
  , uUtils;


class procedure TTaxProbeDateHelper.AsStrings(aItemList: TStrings);
var
  s: TTaxProbeDate;
begin
  aItemList.Clear;
  for s := low(s) to high(s) do
    aItemList.Add(s.AsReadableString);
end;

class function TTaxProbeDateHelper.FromDBString(const Value: string; aDefault: TTaxProbeDate): TTaxProbeDate;
var
  c: TTaxProbeDate;
begin
  Result := aDefault;
  for c := low(c) to high(c) do
    if TAXPROBEDATE_NAMES[c].ToUpper.Equals(Value.ToUpper) then
    begin
      Result := c;
      Break;
    end;
end;

class function TTaxProbeDateHelper.FromItemIndex(aIndex: integer): TTaxProbeDate;
begin
  if (aIndex >= ord(low(TTaxProbeDate))) and (aIndex <= ord(high(TTaxProbeDate))) then
    Result := TTaxProbeDate(aIndex)
  else
    raise ETaxCalcDefinitionException.CreateFmt('Invalid itemindex [%d] for TTaxProbeDate', [aIndex]);
end;

function TTaxProbeDateHelper.AsReadableString : string;
begin
  case Self of
    TTaxProbeDate.InvoiceDate:  Result := GetTranslatedText('shTx_TaxProbeDate_InvoiceDate');
    TTaxProbeDate.StayDate:     Result := GetTranslatedText('shTx_TaxprobeDate_StayDate');
  else
    Result := '';
  end;
end;

function TTaxProbeDateHelper.ToDBString: string;
begin
  Result := TAXPROBEDATE_NAMES[Self];
end;

function TTaxProbeDateHelper.ToItemIndex: integer;
begin
  Result := ord(Self);
end;

end.
