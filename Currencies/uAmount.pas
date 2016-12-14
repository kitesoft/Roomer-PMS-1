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
    Value: Currency;
    CurCode: TCurrencyCode;
    CurHandler: TCurrencyHandler;
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

    class operator Implicit(a: TAmount): Currency;
    class operator Implicit(a: Currency): TAmount;
    class operator Implicit(a: TAmount): double;
    class operator Implicit(a: TAmount): integer;

    class operator Add(a, b: TAmount): TAmount;
    class operator Subtract(a, b: TAmount): TAmount;
    class operator Multiply(a: TAmount; d: double): TAmount;
    class operator Divide(a: TAmount; d: double): TAmount;
    class operator Multiply(a: TAmount; d: integer): TAmount;
    class operator Divide(a: TAmount; d: integer): TAmount;

    class operator Equal(a, b: TAmount): boolean;
    class operator NotEqual(a, b: TAmount): boolean;
    class operator GreaterThan(a, b: TAmount): boolean;
    class operator GreaterThanOrEqual(a, b: TAmount): boolean;
    class operator LessThan(a, b: TAmount): boolean;
    class operator LessThanOrEqual(a, b: TAmount): boolean;

    function AsDisplayString: string;
    property CurrencyCode: TCurrencyCode read CurCode;
  end;

implementation


{ TAmount }

uses uFloatUtils;

class operator TAmount.Add(a, b: TAmount): TAmount;
begin
  CheckSameCurrency(a, b);
  Result.Value := a.Value + b.Value;
  Result.CurCode := a.CurCode;
end;

class function TAmount.Create(const a: Currency; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.Value := a;
  Result.CurCode := c;
end;

class function TAmount.Create(const a: integer; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.Value := a;
  Result.CurCode := c;
end;

function TAmount.AsDisplayString: string;
begin
  Result := CurrencyHandler.FormattedValue(Value);
end;

class procedure TAmount.CheckSameCurrency(a1, a2: TAmount);
begin
  if a1.CurCode <> a2.CurCode then
    raise EAmountException.CreateFmt('Currencies are not equal [%s, %s]', [a1.CurCode, a2.CurCode]);
end;

class procedure TAmount.CheckValidCurrencyCode(const c: TCurrencyCode);
begin
  if not IsValidCurrencyCode(c) then
    raise EAmountException.CreateFmt('Currence not valid [%s]', [c]);
end;

class function TAmount.Create(const a: double; const c: TCurrencyCode): TAmount;
begin
  CheckValidCurrencyCode(c);
  Result.Value := a;
  Result.CurCode := c;
end;

class operator TAmount.Divide(a: TAmount; d: double): TAmount;
begin
  Result.CurCode := a.CurCode;
  Result.Value := a.Value / d;
end;

class operator TAmount.Divide(a: TAmount; d: integer): TAmount;
begin
  Result.CurCode := a.CurCode;
  Result.Value := a.Value / d;
end;

class operator TAmount.Equal(a, b: TAmount): boolean;
begin
  Result := IsSameCurrency(a,b) and (a.Value = b.Value);
end;


function TAmount.GetCurrencyHandler: TCurrencyHandler;
begin
  if not Assigned(CurHandler) then
    Curhandler := TCurrencyHandlerFactory.CurrencyHandler[string(CurCode)];
  Result := CurHandler
end;

class operator TAmount.GreaterThan(a, b: TAmount): boolean;
begin
  CheckSameCurrency(a, b);
  Result := a.Value > b.Value;
end;

class operator TAmount.GreaterThanOrEqual(a, b: TAmount): boolean;
begin
  CheckSameCurrency(a, b);
  Result := a.Value >= b.Value;
end;

class operator TAmount.Implicit(a: TAmount): Currency;
begin
  Result := a.Value;
end;

class operator TAmount.Implicit(a: Currency): TAmount;
begin
  Result.Value := a;
  Result.CurCode := TAmountConfigurator.DefaultCurrency;
end;

class operator TAmount.Implicit(a: TAmount): double;
begin
  Result := a.Value;
end;

class operator TAmount.Implicit(a: TAmount): integer;
begin
  Result := trunc(a.Value);
end;

class function TAmount.IsSameCurrency(a1, a2: TAmount): boolean;
begin
  Result := a1.CurCode = a2.CurCode;
end;

class function TAmount.IsValidCurrencyCode(const c: TCurrencyCode): boolean;
begin
  Result := not Trim(string(c)).IsEmpty;
end;

class operator TAmount.LessThan(a, b: TAmount): boolean;
begin
  CheckSameCurrency(a, b);
  Result := a.Value < b.Value;
end;

class operator TAmount.LessThanOrEqual(a, b: TAmount): boolean;
begin
  CheckSameCurrency(a, b);
  Result := a.Value <= b.Value;
end;

class operator TAmount.Multiply(a: TAmount; d: double): TAmount;
begin
  Result.CurCode := a.CurCode;
  Result.Value := a.Value * d;
end;

class operator TAmount.Multiply(a: TAmount; d: integer): TAmount;
begin
  Result.CurCode := a.CurCode;
  Result.Value := a.Value * d;
end;

class operator TAmount.NotEqual(a, b: TAmount): boolean;
begin
  Result := not (a = b);
end;

class operator TAmount.Subtract(a, b: TAmount): TAmount;
begin
  CheckSameCurrency(a,b);
  Result.Value := a.Value - b.Value;
  Result.CurCode := a.CurCode;
end;

initialization

end.
