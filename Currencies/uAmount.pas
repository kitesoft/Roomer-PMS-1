unit uAmount;

interface

uses
  SysUtils
  , uAmountConfigurator
  , uCurrencyHandler
  ;

type
  EAmountException = class(Exception);

  TAmount = record
  strict private
    FValue: Currency;
    FCurCode: TCurrencyCode;
  private
    class procedure CheckSameCurrency(a1, a2: TAmount); static;
    class function IsSameCurrency(a1, a2: TAmount): boolean; static;
    class function IsValidCurrencyCode(const c: TCurrencyCode): boolean; static;
    class procedure CheckValidCurrencyCode(const c: TCurrencyCode); static;
    function GetCurrencyHandler: TCurrencyHandler;

    property CurrencyHandler: TCurrencyHandler read GetCurrencyHandler;
  public
    class function Create(const a: Currency; const c: TCurrencyCode): TAmount; overload; static; inline;
    class function Create(const a: integer; const c: TCurrencyCode): TAmount; overload; static; inline;
    class function Create(const a: double; const c: TCurrencyCode): TAmount; overload; static; inline;
    class function Create(const a: Extended; const c: TCurrencyCode): TAmount; overload; static; inline;

    class operator Implicit(a: TAmount): Currency;
    class operator Implicit(a: Currency): TAmount;
    class operator Implicit(a: Extended): TAmount;
    class operator Implicit(a: Double): TAmount;
    class operator Implicit(a: TAmount): double;
    class operator Implicit(a: TAmount): integer;

    class operator Add(a, b: TAmount): TAmount;
    class operator Subtract(a, b: TAmount): TAmount;
    class operator Multiply(a: TAmount; d: double): TAmount;
    class operator Divide(a: TAmount; d: double): TAmount;
    class operator Multiply(a: TAmount; d: integer): TAmount;
    class operator Multiply(d: integer; a: TAmount): TAmount;
    class operator Divide(a: TAmount; d: integer): TAmount;

    class operator Equal(a, b: TAmount): boolean;
    class operator NotEqual(a, b: TAmount): boolean;
    class operator GreaterThan(a, b: TAmount): boolean;
    class operator GreaterThanOrEqual(a, b: TAmount): boolean;
    class operator LessThan(a, b: TAmount): boolean;
    class operator LessThan(a: TAmount; b: integer): boolean;
    class operator LessThanOrEqual(a, b: TAmount): boolean;

    function AsDisplayString: string;
    function ToCurrency(const aCurrCode: TCurrencyCode): TAmount;
    property CurrencyCode: TCurrencyCode read FCurCode;
  end;

implementation


{ TAmount }

uses uFloatUtils;

class operator TAmount.Add(a, b: TAmount): TAmount;
begin
  CheckSameCurrency(a, b);
  Result.FValue := a.FValue + b.FValue;
  Result.FCurCode := a.FCurCode;
end;

class function TAmount.Create(const a: Currency; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.FValue := a;
  Result.FCurCode := c;
end;

class function TAmount.Create(const a: integer; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.FValue := a;
  Result.FCurCode := c;
end;

function TAmount.AsDisplayString: string;
begin
  Result := CurrencyHandler.FormattedValue(FValue);
end;

class procedure TAmount.CheckSameCurrency(a1, a2: TAmount);
begin
  if a1.FCurCode <> a2.FCurCode then
    raise EAmountException.CreateFmt('Currencies are not equal [%s, %s]', [a1.FCurCode, a2.FCurCode]);
end;

class procedure TAmount.CheckValidCurrencyCode(const c: TCurrencyCode);
begin
  if not IsValidCurrencyCode(c) then
    raise EAmountException.CreateFmt('Currence not valid [%s]', [c]);
end;

class function TAmount.Create(const a: double; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.FValue := a;
  Result.FCurCode := c;
end;

class operator TAmount.Divide(a: TAmount; d: double): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue / d;
end;

class operator TAmount.Divide(a: TAmount; d: integer): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue / d;
end;

class operator TAmount.Equal(a, b: TAmount): boolean;
begin
  Result := IsSameCurrency(a,b) and (a.FValue = b.FValue);
end;


function TAmount.GetCurrencyHandler: TCurrencyHandler;
begin
  Result := TCurrencyHandlerFactory.CurrencyHandler[string(FCurCode)];
end;

class operator TAmount.GreaterThan(a, b: TAmount): boolean;
begin
  CheckSameCurrency(a, b);
  Result := a.FValue > b.FValue;
end;

class operator TAmount.GreaterThanOrEqual(a, b: TAmount): boolean;
begin
  CheckSameCurrency(a, b);
  Result := a.FValue >= b.FValue;
end;

class operator TAmount.Implicit(a: TAmount): Currency;
begin
  Result := a.FValue;
end;

class operator TAmount.Implicit(a: Currency): TAmount;
begin
  Result.FValue := a;
  Result.FCurCode := TAmountConfigurator.DefaultCurrency;
end;

class operator TAmount.Implicit(a: TAmount): double;
begin
  Result := a.FValue;
end;

class operator TAmount.Implicit(a: TAmount): integer;
begin
  Result := trunc(a.FValue);
end;

class operator TAmount.Implicit(a: Extended): TAmount;
begin
  Result := TAmount.Create(a, TAmountConfigurator.DefaultCurrency);
end;

class operator TAmount.Implicit(a: Double): TAmount;
begin
  Result := TAmount.Create(a, TAmountConfigurator.DefaultCurrency);
end;


class function TAmount.IsSameCurrency(a1, a2: TAmount): boolean;
begin
  Result := a1.FCurCode = a2.FCurCode;
end;

class function TAmount.IsValidCurrencyCode(const c: TCurrencyCode): boolean;
begin
  Result := not Trim(string(c)).IsEmpty;
end;

class operator TAmount.LessThan(a, b: TAmount): boolean;
begin
  CheckSameCurrency(a, b);
  Result := a.FValue < b.FValue;
end;

class operator TAmount.LessThan(a: TAmount; b: integer): boolean;
begin
  Result := (a.FValue < b)
end;

class operator TAmount.LessThanOrEqual(a, b: TAmount): boolean;
begin
  CheckSameCurrency(a, b);
  Result := a.FValue <= b.FValue;
end;

class operator TAmount.Multiply(a: TAmount; d: double): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue * d;
end;

class operator TAmount.Multiply(a: TAmount; d: integer): TAmount;
begin
  Result.FCurCode := a.FCurCode;
  Result.FValue := a.FValue * d;
end;

class operator TAmount.Multiply(d: integer; a: TAmount): TAmount;
begin
  Result := a * d;
end;



class operator TAmount.NotEqual(a, b: TAmount): boolean;
begin
  Result := not (a = b);
end;

class operator TAmount.Subtract(a, b: TAmount): TAmount;
begin
  CheckSameCurrency(a,b);
  Result.FValue := a.FValue - b.FValue;
  Result.FCurCode := a.FCurCode;
end;

function TAmount.ToCurrency(const aCurrCode: TCurrencyCode): TAmount;
begin
  Result.FCurCode := aCurrCode;
  Result.FValue := CurrencyHandler.ConvertTo(FValue, aCurrCode);
end;

class function TAmount.Create(const a: Extended; const c: TCurrencyCode): TAmount;
begin
  Result.FCurCode := c;
  Result.FValue := RoundDecimals(a, 4);
end;

initialization

end.
