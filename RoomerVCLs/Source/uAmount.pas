unit uAmount;

interface

uses
  SysUtils
  , uCurrencyConstants
  , uCurrencyDefinition
  ;

type

  EAmountException = class(Exception);
  EAmountInvalidCastException = class(EAmountException);

  ///	<summary>
  ///	  <para>
  ///	  An Amount is an immutable value in a certain currency.<br />
  ///   Values are stored as a Delphi Currency type, which has 4 fixed decimal places. It makes use of the global CurrencyManager
  ///   to retrieve the properties of the set CurrencyCode
  ///	  </para>
  ///	  <para>
  ///   Different amounts can be added or subtracted and will have the currencycode of the first term<br />
  ///   Mulitplying an amount or dividing an amount will always return a result of the same currency of the first factor<br />
  ///	  When an integer or decimal value is implicitly converted to an amount, then the native
  ///	  currency will be used, provided by the global CurrencyManager
  ///	  </para>
  ///	  <para>
  ///   Implicit casting to an Integer will raise an exception, to avoid unintentional truncating.<br />
  ///   Explicit casting to Integer is allowed. This will return the rounded value of the amount
  ///	  </para>
  ///	  <para>
  ///   .<br />
  ///   The CurrrencyRate of the currency of the amount is retrieved from the global CurrencyManager, unless an explicit CurrencyRate is
  ///   set for the Amount. If the CurrencyRate is set to any value <> 0 then this will override the rate defined in CurrencyManager.
  ///	  </para>
  ///	</summary>
  ///	<remarks>
  ///	  <para>
  ///	    Future enhancements may include using a BigDecimal implementation in stead of the Currency type.
  ///     This will allow for greater precision if needed
  ///	  </para>
  ///	  <para>
  ///	    Unittests are available in <c>..\Unittests\CurrencyTests</c>
  ///	  </para>
  ///	</remarks>
  TAmount = record
  strict private type
    //Internal storage format of the value
    TAmountValueType = Currency;

  strict private
    FValue: TAmountValueType;
    FCurCode: TCurrencyCode;
    FCurrencyRate: double;
    function GetCurrencyDefinition: TCurrencyDefinition;
  private
    class function IsSameCurrency(a1, a2: TAmount): boolean; static;
    class function IsValidCurrencyCode(const c: TCurrencyCode): boolean; static;
    class procedure CheckValidCurrencyCode(const c: TCurrencyCode); static;
    class function CheckValidCurrencyID(id: integer): TCurrencyCode; static;
    function GetCurrencyRate: double;
    procedure SetCurrencyRate(const Value: double);
    property CurrencyDefinition: TCurrencyDefinition read GetCurrencyDefinition;
    function GetValue: Currency;
  public
    class function Create(): TAmount; overload; static; inline;

    class function Create(const a: Currency; const c: TCurrencyCode): TAmount; overload; static; inline;
    class function Create(const a: integer; const c: TCurrencyCode): TAmount; overload; static; inline;
    class function Create(const a: double; const c: TCurrencyCode): TAmount; overload; static; inline;
    class function Create(const a: Extended; const c: TCurrencyCode): TAmount; overload; static; inline;
    class function Create(const c: TCurrencyCode): TAmount; overload; static; inline;

    class function Create(const a: Currency; const id: integer): TAmount; overload; static; inline;
    class function Create(const a: integer; const id: integer): TAmount; overload; static; inline;
    class function Create(const a: double; const id: integer): TAmount; overload; static; inline;
    class function Create(const a: Extended; const id: integer): TAmount; overload; static; inline;

    class operator Implicit(a: TAmount): Currency;
    class operator Implicit(a: Currency): TAmount;
    class operator Implicit(a: Extended): TAmount;
    class operator Implicit(a: integer): TAmount;
    class operator Implicit(a: Double): TAmount;
    class operator Implicit(a: TAmount): double;
    class operator Implicit(a: TAmount): extended;
    class operator Implicit(a: TAmount): integer;
    class operator Implicit(a: TAmount): string;

    class operator Explicit(a: TAmount): integer;

    class function ZERO(): TAmount; static; inline;

    class operator Add(a, b: TAmount): TAmount;
    class operator Add(a: TAmount; c: Currency): TAmount;
    class operator Add(a: TAmount; c: extended): TAmount;

    class operator Subtract(a, b: TAmount): TAmount;
    class operator Subtract(a: TAmount; c: Currency): TAmount;
    class operator Subtract(a: TAmount; c: extended): TAmount;

    class operator Multiply(a: TAmount; d: double): TAmount;
    class operator Multiply(a: TAmount; c: currency): TAmount;
    class operator Multiply(a: TAmount; d: integer): TAmount;
    class operator Multiply(a: TAmount; e: Extended): TAmount;
    class operator Multiply(d: integer; a: TAmount): TAmount;
    class operator Multiply(a: TAmount; b: TAmount): TAmount;

    class operator Divide(a: TAmount; d: double): TAmount;
    class operator Divide(a: TAmount; d: integer): TAmount;
    class operator Divide(a: TAmount; b: TAmount): TAmount;

    class operator Equal(a, b: TAmount): boolean;
    class operator NotEqual(a, b: TAmount): boolean;
    class operator GreaterThan(a, b: TAmount): boolean;
    class operator GreaterThanOrEqual(a, b: TAmount): boolean;
    class operator LessThan(a, b: TAmount): boolean;
    class operator LessThan(a: TAmount; b: integer): boolean;
    class operator LessThanOrEqual(a, b: TAmount): boolean;

    class operator Negative(a: TAmount): TAmount;
    /// <summary>
    ///   Returns a string with the rounded and formatted value, using the format settings
    ///  of the CurrencyDefinition in Currencymanager
    /// </summary>
    function AsDisplayString: string;
    /// <summary>
    ///   Returns a string with the rounded and formatted value, followed by the 3-letter CurrencyCode
    /// </summary>
    function AsDisplayStringWithCode: string;
    function AsEditString: string;
    function ToCurrency(const aCurrCode: TCurrencyCode): TAmount; overload;
    function ToCurrency(aCurrDef: TCurrencyDefinition): TAmount; overload;
    function ToCurrency(aCurId: integer): TAmount; overload;
    /// <summary>
    ///   Convert this amount to the native amount set in CurrencyManager
    /// </summary>
    function ToNative(): TAmount;

    /// <summary>
    ///   Returns a TAmount rounded to the number of decimals set for the CurrencyCode in CurrencyManager
    /// </summary>
    function Rounded(): TAmount;
    /// <summary>
    ///   Returns the largest actual value of Self and b
    /// </summary>
    function Max(b: TAmount): TAmount;
    /// <summary>
    ///   Returns the smallest actual value of Self and b
    /// </summary>
    function Min(b: TAmount): TAmount;

    property Value: Currency read GetValue;
    property CurrencyCode: TCurrencyCode read FCurCode;
    /// <summary>
    ///   CurrencyRate to use conversions of this amount. If not set explicitly (or set to 0) then the active
    ///   currencyrate is used from the CurrencyManager.
    ///  This can be used for calculation with amounts that are already handled using a historic currency rate
    /// </summary>
    property CurrencyRate: double read GetCurrencyRate write SetCurrencyRate;
  end;

  /// <summary>
  ///   Workaround for using TAmount records in TList<> and TDictionary<>
  /// </summary>
  TAmountClass = class(TObject)
  public
    Amount: TAmount;
    constructor Create(aAmount: TAmount);
  end;

implementation


{ TAmount }

uses
    uFloatUtils
  , uCurrencyManager
  , Math
  ;


class function TAmount.Create(const a: Currency; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.FValue := a;
  Result.FCurCode := c;
  Result.FCurrencyRate := 0.0000;
end;

class function TAmount.Create(const a: integer; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.FValue := a;
  Result.FCurCode := c;
  Result.FCurrencyRate := 0.0000;
end;


class operator TAmount.Add(a, b: TAmount): TAmount;
begin
  if not IsSameCurrency(a, b) then
    Result := a + b.ToCurrency(a.CurrencyCode)
  else
  begin
    Result.FValue := a.FValue + b.FValue;
    Result.FCurCode := a.FCurCode;
    Result.FCurrencyRate := a.FCurrencyRate;
  end;
end;

class operator TAmount.Add(a: TAmount; c: Currency): TAmount;
begin
  Result.FValue := a.FValue + c;
  Result.FCurCode := a.FCurCode;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

class operator TAmount.Add(a: TAmount; c: extended): TAmount;
begin
  Result.FValue := a.FValue + c;
  Result.FCurCode := a.FCurCode;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

function TAmount.AsDisplayString: string;
begin
  Result := CurrencyDefinition.FormattedValue(FValue);
end;

function TAmount.AsDisplayStringWithCode: string;
begin
  Result := CurrencyDefinition.FormattedValueWithCode(FValue);
end;

function TAmount.AsEditString: string;
begin
  Result := CurrencyDefinition.EditValue(FValue);
end;


class procedure TAmount.CheckValidCurrencyCode(const c: TCurrencyCode);
begin
  if not IsValidCurrencyCode(c) then
    raise ECurrencyException.CreateFmt('Currency not valid [%s]', [c]);
end;

class function TAmount.CheckValidCurrencyID(id: integer): TCurrencyCode;
begin
  try
    result := CurrencyManager.CurrencyDefinitionById[id].CurrencyCode;
  except
    raise ECurrencyException.CreateFmt('CurrencyId not valid [%d]', [id]);
  end;
end;

class function TAmount.Create(const a: double; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.FValue := a;
  Result.FCurCode := c;
  Result.FCurrencyRate := 0.0000;
end;

class operator TAmount.Divide(a: TAmount; d: double): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue / d;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

class operator TAmount.Divide(a: TAmount; d: integer): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue / d;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

class operator TAmount.Equal(a, b: TAmount): boolean;
begin
  Result := IsSameCurrency(a,b) and (a.FValue = b.FValue);
end;

class operator TAmount.Explicit(a: TAmount): integer;
begin
  Result := round(a.Value);
end;

function TAmount.GetCurrencyDefinition: TCurrencyDefinition;
begin
  Result := CurrencyManager.CurrencyDefinition[FCurCode];
end;

function TAmount.GetCurrencyRate: double;
begin
  if SameValue(FCurrencyRate, 0.0000) then
    Result := CurrencyDefinition.Rate
  else
    Result := FCurrencyRate;
end;

function TAmount.GetValue: Currency;
begin
  Result := FValue;
end;

class operator TAmount.GreaterThan(a, b: TAmount): boolean;
begin
  if not isSameCurrency(a, b) then
    Result := a > b.ToCurrency(a.CurrencyDefinition)
  else
    Result := a.FValue > b.FValue;
end;

class operator TAmount.GreaterThanOrEqual(a, b: TAmount): boolean;
begin
  if not isSameCurrency(a, b) then
    Result := a >= b.ToCurrency(a.CurrencyDefinition)
  else
  Result := a.FValue >= b.FValue;
end;

class operator TAmount.Implicit(a: TAmount): Currency;
begin
  Result := a.FValue;
end;

class operator TAmount.Implicit(a: Currency): TAmount;
begin
  Result := TAmount.Create(a, CurrencyManager.DefaultCurrency);
end;

class operator TAmount.Implicit(a: TAmount): double;
begin
  Result := a.FValue;
end;

class operator TAmount.Implicit(a: TAmount): integer;
begin
  // Not allowed because of unseen and maybe unwanted truncation.
  raise EAmountInvalidCastException.Create('Invalid cast from TAmount to Integer. Use explicit casting instead.');
end;

class operator TAmount.Implicit(a: Extended): TAmount;
begin
  Result := TAmount.Create(a, CurrencyManager.DefaultCurrency);
end;

class operator TAmount.Implicit(a: Double): TAmount;
begin
  Result := TAmount.Create(a, CurrencyManager.DefaultCurrency);
end;


class operator TAmount.Implicit(a: TAmount): extended;
begin
  Result := a.FValue;
end;

class operator TAmount.Implicit(a: integer): TAmount;
begin
  Result := TAmount.Create(a, CurrencyManager.DefaultCurrency)
end;

class function TAmount.IsSameCurrency(a1, a2: TAmount): boolean;
begin
  Result := (a1.FCurCode = a2.FCurCode) and SameValue(a1.CurrencyRate, a2.CurrencyRate, 0.0000);
end;

class function TAmount.IsValidCurrencyCode(const c: TCurrencyCode): boolean;
begin
  Result := not Trim(string(c)).IsEmpty and CurrencyManager.DefinitionExists(c);
end;

class operator TAmount.LessThan(a, b: TAmount): boolean;
begin
  if not isSameCurrency(a, b) then
    Result := a < b.ToCurrency(a.CurrencyDefinition)
  else
    Result := a.FValue < b.FValue;
end;

class operator TAmount.LessThan(a: TAmount; b: integer): boolean;
begin
  Result := (a.FValue < b)
end;

class operator TAmount.LessThanOrEqual(a, b: TAmount): boolean;
begin
  if not isSameCurrency(a, b) then
    Result := a <= b.ToCurrency(a.CurrencyDefinition)
  else
    Result := a.FValue <= b.FValue;
end;

class operator TAmount.Multiply(a: TAmount; e: Extended): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue * e;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

function TAmount.Max(b: TAmount): TAmount;
begin
  if (Self >= b) then
    Result := Self
  else
    Result := b;
end;

function TAmount.Min(b: TAmount): TAmount;
begin
  if (Self <= b) then
    Result := Self
  else
    Result := b;
end;

class operator TAmount.Multiply(a, b: TAmount): TAmount;
begin
  if not isSameCurrency(a, b) then
    Result := a * b.ToCurrency(a.CurrencyCode)
  else
    Result := TAmount.Create(a.FValue * b.FValue, a.CurrencyCode);
end;

class operator TAmount.Multiply(a: TAmount; d: double): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue * d;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

class operator TAmount.Multiply(a: TAmount; d: integer): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue * d;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

class operator TAmount.Multiply(d: integer; a: TAmount): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue * d;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

class operator TAmount.Multiply(a: TAmount; c: Currency): TAmount;
begin
  Result := a;
  Result.FValue := Result.Value * c;
end;

class operator TAmount.Negative(a: TAmount): TAmount;
begin
  Result := a * -1;
end;

class operator TAmount.NotEqual(a, b: TAmount): boolean;
begin
  Result := not (a = b);
end;

function TAmount.Rounded: TAmount;
begin
  Result.FCurCode := Self.CurrencyCode;
  Result.FValue := CurrencyDefinition.RoundedValue(Self.Value);
  Result.FCurrencyRate := Self.FCurrencyRate;
end;

procedure TAmount.SetCurrencyRate(const Value: double);
begin
  FCurrencyRate := Value;
end;

class operator TAmount.Subtract(a: TAmount; c: extended): TAmount;
begin
  Result.FValue := a.Value - c;
  Result.FCurCode := a.FCurCode;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

function TAmount.ToCurrency(aCurId: integer): TAmount;
begin
  Result := ToCurrency(CurrencyManager.CurrencyDefinitionByID[aCurID]);
end;

function TAmount.ToNative: TAmount;
begin
  Result := CurrencyManager.ConvertAmountToDefault(Self);
end;

class function TAmount.ZERO: TAmount;
begin
  Result := TAmount(0.0000);
end;

function TAmount.ToCurrency(aCurrDef: TCurrencyDefinition): TAmount;
begin
  Result := ToCurrency(aCurrDef.CurrencyCode);
end;

class operator TAmount.Subtract(a: TAmount; c: Currency): TAmount;
begin
  Result.FValue := a.Value - c;
  Result.FCurCode := a.FCurCode;
  Result.FCurrencyRate := a.FCurrencyRate;
end;

class operator TAmount.Subtract(a, b: TAmount): TAmount;
begin
  if not IsSameCurrency(a,b) then
    Result := a - b.ToCurrency(a.CurrencyCode)
  else
  begin
    Result.FValue := a.FValue - b.FValue;
    Result.FCurCode := a.FCurCode;
    Result.FCurrencyRate := a.FCurrencyRate;
  end;
end;

function TAmount.ToCurrency(const aCurrCode: TCurrencyCode): TAmount;
begin
  if FCurCode <> aCurrCOde then
    Result := CurrencyManager.ConvertAmount(Self, aCurrCode)
  else
    Result := Self;
end;

class function TAmount.Create(const a: Extended; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.FCurCode := c;
  Result.FValue := a;
  Result.FCurrencyRate := 0.0000;
end;

class function TAmount.Create(const c: TCurrencyCode): TAmount;
begin
  Result := TAmount.Create(0, c);
end;

class function TAmount.Create: TAmount;
begin
  Result := TAmount.Create(0, CurrencyManager.DefaultCurrency);
end;

class function TAmount.Create(const a, id: integer): TAmount;
begin
  Result := Create(a, CheckValidCurrencyID(id));
end;

class function TAmount.Create(const a: Currency; const id: integer): TAmount;
begin
  Result := Create(a, CheckValidCurrencyID(id));
end;

class function TAmount.Create(const a: double; const id: integer): TAmount;
begin
  Result := Create(a, CheckValidCurrencyID(id));
end;

class function TAmount.Create(const a: Extended; const id: integer): TAmount;
begin
  Result := Create(a, CheckValidCurrencyID(id));
end;

class operator TAmount.Divide(a, b: TAmount): TAmount;
begin
  if not IsSameCurrency(a,b) then
    Result := a / b.ToCurrency(a.CurrencyCode)
  else
  begin
    Result.FValue := a.FValue / b.FValue;
    Result.FCurCode := a.FCurCode;
    Result.FCurrencyRate := a.FCurrencyRate;
  end;

end;

class operator TAmount.Implicit(a: TAmount): string;
begin
  Result := a.AsDisplayString;
end;

{ TAmountClass }

constructor TAmountClass.Create(aAmount: TAmount);
begin
  Amount := aAmount;
end;


initialization

end.
