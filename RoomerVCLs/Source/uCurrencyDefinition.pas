unit uCurrencyDefinition;

interface

uses
  SysUtils
  , uCurrencyConstants
  ;

type
  ECurrencyDefinitionException = class(Exception);


  /// <summary>
  ///   Object to handle definitions of currencies and display of amounts in a certain currency <br />
  ///  This base class is and should not be dependent on any part of Roomer PMS1
  /// </summary>
  ///	<remarks>
  ///	  <para>
  ///	    Unittests are available in <c>Roomer-PMS-1\Unittests\CurrencyTests</c>
  ///	  </para>
  ///	</remarks>
  TCurrencyDefinition = class
  private
    FRate: double;
    FCode: TCurrencyCode;
    FFormatSettings: TFormatSettings;
    FDescription: string;
    function GetRate: double;
    function GetCurrencyCode: string;
    function GetFormatSettings: TFormatSettings;
    procedure SetFormatSettings(const Value: TFormatSettings);
    procedure SetRate(const Value: double);
    function GetSymbol: string;
    procedure SetSymbol(const Value: string);
    /// <summary>
    ///   Construct a displayformat string based on the supplied formatSettings, using fixed decimal and thousandsseparator
    ///  This format can be used as a DisplayFormat setting in a TcxCurrencyEditProperties
    /// </summary>
    function AddCurrencySymbol(const Value, CurrSymbol: string; const CurrFormat: Byte): string;
    function AddNegCurrencySymbol(const Value, CurrSymbol: string; const CurrFormat: Byte): string;
  protected
    FID: integer;
    function DisplayCurrencyFormat(aFormatSettings: TFormatSettings; aAddSymbol: boolean = true): String;
  public
    constructor Create(const aCurrencyCode: TCurrencyCode); overload; virtual;
    constructor Create(const aCurrencyCode: string; aCurID: integer); overload; virtual;

    property ID: integer read FId write FId;
    property CurrencyCode: string read GetCurrencyCode;
    property Description: string read FDescription write FDescription;
    property Symbol: string read GetSymbol write SetSymbol;
    property Rate: double read GetRate write SetRate;
    property CurrencyFormatSettings: TFormatSettings read GetFormatSettings write SetFormatSettings;

    /// <summary>
    ///   Round aAmount to the number of decimals defined for the currency
    /// </summary>
    function RoundedValue(aAmount: double): double;
    /// <summary>
    ///   Format aAmount according to the formatsettings of the currency
    /// </summary>
    function FormattedValue(aAmount: double; aIncludeCurrencySymbol: boolean = false): string;
    /// <summary>
    ///   Format aAmount according to the formatsettings of the currency, including the 3 letter currencycode
    /// </summary>
    function FormattedValueWithCode(aAmount: double): string;
    /// <summary>
    ///   Format aAmount according to the formatsettings of the currency for editing purposes, so exclusing currencySign but with
    ///  correct number of decimals
    /// </summary>
    function EditValue(aAmount: double): string;
    /// <summary>
    ///   Returns a formatted string with the currency description and the exchange rate, used to display active currency in i.e. a labelcaption
    /// </summary>
    function ShortDescription: string; virtual;
    /// <summary>
    ///   Returns a DisplayformatString that can be used in grids and reports
    /// </summary>
    function DisplayFormat(aInclCurrencySymbol: boolean): string;
  end;

  TCurrencyDefinitionClass = class of TCurrencyDefinition;


implementation

uses
  uFloatUtils
  ;

constructor TCurrencyDefinition.Create(const aCurrencyCode: TCurrencyCode);
begin
  if String(aCurrencyCode).Trim.IsEmpty then
    raise ECurrencyDefinitionException.Create('Cannot create a currencydefinition with empty currencycode');
  FCode := UpperCase(String(aCurrencyCode));
  FDescription := FCode;
  FRate := 1.0;
  FID := -1;
  FFormatSettings := TFormatSettings.Create; // System defaults
end;

constructor TCurrencyDefinition.Create(const aCurrencyCode: string; aCurID: integer);
begin
  Create(aCurrencyCode);
  FId := aCurId;
end;

function TCurrencyDefinition.DisplayFormat(aInclCurrencySymbol: boolean): string;
begin
  Result := DisplayCurrencyFormat(FFormatSettings, aInclCurrencySymbol);
end;

function TCurrencyDefinition.EditValue(aAmount: double): string;
begin
  Result := FloatToStrF(RoundedValue(aAmount), ffFixed, 10, FFormatsettings.CurrencyDecimals, FFormatSettings);
end;

function TCurrencyDefinition.FormattedValue(aAmount: double; aIncludeCurrencySymbol: boolean = false): string;
begin
  if aIncludeCurrencySymbol then
  begin
    Result := CurrToStrF(aAMount, ffCurrency, FFormatSettings.CurrencyDecimals, FFormatSettings);
  end
  else
    Result := CurrToStrF(aAmount, ffFixed, FFormatSettings.CurrencyDecimals, FFormatSettings);
end;

function TCurrencyDefinition.FormattedValueWithCode(aAmount: double): string;
begin
  Result := Format('%s %s', [FormattedValue(aAmount), string(CurrencyCode)]);
end;

function TCurrencyDefinition.GetCurrencyCode: string;
begin
  Result := String(FCode);
end;

function TCurrencyDefinition.GetFormatSettings: TFormatSettings;
begin
  Result := FFormatSettings;
end;

function TCurrencyDefinition.GetRate: double;
begin
  Result := FRate;
end;

function TCurrencyDefinition.GetSymbol: string;
begin
  Result := FFormatSettings.CurrencyString;
end;

function TCurrencyDefinition.ShortDescription: string;
const
  cFormat = '%s (%s)';
begin
  Result := Format(cFormat, [Description, FloatToStr(RoundDecimals(Rate, 4))]);
end;

procedure TCurrencyDefinition.SetFormatSettings(const Value: TFormatSettings);
begin
  FFormatSettings := Value;
end;

procedure TCurrencyDefinition.SetRate(const Value: double);
begin
  FRate := Value;
end;

procedure TCurrencyDefinition.SetSymbol(const Value: string);
begin
  FFormatSettings.CurrencyString := Value;
end;

function TCurrencyDefinition.RoundedValue(aAmount: double): double;
begin
  Result := RoundDecimals(aAmount, FFormatSettings.CurrencyDecimals);
end;


function TCurrencyDefinition.AddCurrencySymbol(const Value, CurrSymbol: string; const CurrFormat: Byte): string;
begin
  if CurrSymbol.IsEmpty then
    Result := Value
  else
    case CurrFormat of
      0: Result := Format('%s%s', [CurrSymbol, Value]);
      1: Result := Format('%s%s', [Value, CurrSymbol]);
      2: Result := Format('%s %s', [CurrSymbol, Value]);
      3: Result := Format('%s %s', [Value, CurrSymbol]);
    end;
end;

{   0 = '($1)'      4 = '(1$)'      8 = '-1 $'      12 = '$ -1'
    1 = '-$1'       5 = '-1$'       9 = '-$ 1'      13 = '1- $'
    2 = '$-1'       6 = '1-$'      10 = '1 $-'      14 = '($ 1)'
    3 = '$1-'       7 = '1$-'      11 = '$ 1-'      15 = '(1 $)'  }
function TCurrencyDefinition.AddNegCurrencySymbol(const Value, CurrSymbol: string; const CurrFormat: Byte): string;
begin
  if CurrSymbol.IsEmpty then
    case CurrFormat of
      0: Result := Format('(%s)', [ Value]);
      1: Result := Format('-%s', [Value]);
      2: Result := Format('-%s', [Value]);
      3: Result := Format('%s-', [Value]);
      4: Result := Format('(%s)', [Value]);
      5: Result := Format('-%s', [Value]);
      6: Result := Format('%s-', [Value]);
      7: Result := Format('%s-', [Value]);
      8: Result := Format('-%s', [Value]);
      9: Result := Format('- %s', [Value]);
     10: Result := Format('%s -', [Value]);
     11: Result := Format('%s-', [Value]);
     12: Result := Format('-%s', [Value]);
     13: Result := Format('%s-', [Value]);
     14: Result := Format('(- %s)', [Value]);
     15: Result := Format('(%s)', [Value]);
    end
  else
    case CurrFormat of
      0: Result := Format('(%s%s)', [CurrSymbol, Value]);
      1: Result := Format('-%s%s', [CurrSymbol, Value]);
      2: Result := Format('%s-%s', [CurrSymbol, Value]);
      3: Result := Format('%s%s-', [CurrSymbol, Value]);
      4: Result := Format('(%s%s)', [Value, CurrSymbol]);
      5: Result := Format('-%s%s', [Value, CurrSymbol]);
      6: Result := Format('%s-%s', [Value, CurrSymbol]);
      7: Result := Format('%s%s-', [Value, CurrSymbol]);
      8: Result := Format('-%s %s', [Value, CurrSymbol]);
      9: Result := Format('-%s %s', [CurrSymbol, Value]);
     10: Result := Format('%s %s-', [Value, CurrSymbol]);
     11: Result := Format('%s %s-', [CurrSymbol, Value]);
     12: Result := Format('%s %s', [CurrSymbol, Value]);
     13: Result := Format('%s -%s', [Value, CurrSymbol]);
     14: Result := Format('(%s- %s)', [CurrSymbol, Value]);
     15: Result := Format('(%s %s)', [Value, CurrSymbol]);
  end;
end;

function TCurrencyDefinition.DisplayCurrencyFormat(aFormatSettings: TFormatSettings; aAddSymbol: boolean = true): String;
begin
  aFormatSettings.DecimalSeparator := '.';
  aFormatSettings.ThousandSeparator := ',';

 if aFormatSettings.CurrencyDecimals > 0 then
   Result := '0' + aFormatSettings.DecimalSeparator + StringOfChar('0', aFormatSettings.CurrencyDecimals)
 else
   Result := '0';

 Result := aFormatSettings.ThousandSeparator + Result;

 if aAddSymbol then
   Result := AddCurrencySymbol(Result, aFormatSettings.CurrencyString, aFormatSettings.CurrencyFormat)
          + ';' + AddNegCurrencySymbol(Result, aFormatSettings.CurrencyString, aFormatSettings.NegCurrFormat)
 else
   Result := AddCurrencySymbol(Result, '', aFormatSettings.CurrencyFormat)
          + ';' + AddNegCurrencySymbol(Result, '', aFormatSettings.NegCurrFormat)

end;

end.
