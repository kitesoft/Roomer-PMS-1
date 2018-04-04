unit AmountTest;


interface

uses
  TestFramework
  , uAmount
  ;

type

  TAmountImplicitTests = class(TTestCase)
  public
    procedure SetUp; override;
  published
    procedure TestSetupTearDown;
    procedure TestAmountFromCurrency;
    procedure TestAmountFromDouble;
    procedure TestAmountFromExtended;
    procedure TestAmountFromInteger;
    procedure TestImplicitCasting;
    procedure TestExplicitCasting;
  end;

  TAmountArtithmeticTests = class(TTestCase)
  public
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestSetupTearDown;
    procedure TestAdd;
    procedure TestSubtract;
    procedure TestMultiply;
    procedure TestDivide;
  end;

  TAmountCompareTests = class(TTestCase)
  public
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestSetupTearDown;
    procedure TestEqual;
    procedure TestGreaterAndLesser;
  end;

implementation

uses
  SysUtils
  , uCurrencyManager
  , uCurrencyConstants
  , Math
  , uFloatUtils
  ;


{ TAmountImplicitTests }

procedure TAmountImplicitTests.SetUp;
begin
  inherited;
  CurrencyManager.DefaultCurrency := 'EUR';
end;

procedure TAmountImplicitTests.TestAmountFromCurrency;
var
  c: currency;
  a: TAmount;
begin
  c := 13.456;
  a := c;
  CheckTrue(SameValue(a.value, c, 0.0001), 'wrong value');
  CheckTrue(CurrencyManager.DefaultCurrency = a.CurrencyCode, 'Different currencycode');
end;

procedure TAmountImplicitTests.TestAmountFromDouble;
var
  c: double;
  a: TAmount;
begin
  c := 13.456;
  a := c;
  CheckTrue(SameValue(a.value, c, 0.0001), 'wrong value');
  CheckTrue(CurrencyManager.DefaultCurrency = a.CurrencyCode, 'Different currencycode');
end;

procedure TAmountImplicitTests.TestAmountFromExtended;
var
  c: extended;
  a: TAmount;
begin
  c := 13.456;
  a := c;
  CheckTrue(SameValue(a.value, c, 0.0001), 'wrong value');
  CheckTrue(CurrencyManager.DefaultCurrency = a.CurrencyCode, 'Different currencycode');
end;

procedure TAmountImplicitTests.TestAmountFromInteger;
var
  c: integer;
  a: TAmount;
begin
  c := 123456;
  a := c;
  CheckTrue(SameValue(a.value, c, 0.0001), 'wrong value');
  CheckTrue(CurrencyManager.DefaultCurrency = a.CurrencyCode, 'Different currencycode');
end;

procedure TAmountImplicitTests.TestExplicitCasting;
var
  a:TAmount;
  i: integer;
  d: double;
  e: extended;
begin

  a := TAmount.Create(4056.7639, 'EUR');
  d := Double(a);
  CheckTrue(SameValue(d, 4056.7639, 0.0001), 'Explicit cast to double failed');
  e := Extended(a);
  CheckTrue(SameValue(e, 4056.7639, 0.0001), 'Explicit cast to extended failed');
  i := Integer(a);
  CheckEquals(i, 4057, 'Explicit cast to integer failed');
end;

procedure TAmountImplicitTests.TestImplicitCasting;
var
  a:TAmount;
  i: integer;
  d: double;
  e: extended;
  c: currency;
begin

  a := TAmount.Create(4056.7639, 'EUR');
  d := a;
  CheckTrue(SameValue(d, 4056.7639, 0.0001), 'Implicit cast to double failed');
  e := a;
  CheckTrue(SameValue(e, 4056.7639, 0.0001), 'Implicit cast to extended failed');
  c := a;
  CheckTrue(SameValue(c, 4056.7639, 0.0001), 'Implicit cast to extended failed');

  ExpectedException := EAmountInvalidCastException;
  i := a;
end;

procedure TAmountImplicitTests.TestSetupTearDown;
begin
  CheckTrue(True);
end;

{ TAmountArtithmeticTests }

procedure TAmountArtithmeticTests.SetUp;
begin
  inherited;
  CurrencyManager.CreateDefinition('GBP').Rate := 1.15;
end;

procedure TAmountArtithmeticTests.TearDown;
begin
  inherited;
  CurrencyManager.ClearDefinitions;
end;

procedure TAmountArtithmeticTests.TestAdd;
var
  c: currency;
  d: double;
  e: extended;
  i: integer;
  a: TAmount;
  b: TAmount;
  r: TAmount;
begin

  c := 23.9986;
  d := 1576.098;
  e := 78943.877632;
  i := 653542;

  a := 61;       // default curr
  b := a + c;
  CheckTrue(Samevalue(b.Value, 61 + 23.9986), 'Addition with currency not working');
  b := a + d;
  CheckTrue(Samevalue(b.Value, 61 + 1576.098), 'Addition with double not working');
  b := a + e;
  CheckTrue(Samevalue(b.Value, 61 + 78943.8776), 'Addition with extended not working');
  b := a + i;
  CheckTrue(Samevalue(b.Value, 61 + 653542), 'Addition with integer not working');

  b := TAmount.Create(39, 'EUR');
  CheckEquals(TAmount(a+b).Value, 100);

  b := TAmount.Create(39, 'GBP');
  r := a + b;
  CheckEqualsString(r.CurrencyCode, CurrencyManager.DefaultCurrency);
  CheckTrue(SameValue(r, TAmount(61 + 39 * 1.15)), 'Adding a + b not working');

  r := b + a;
  CheckEqualsString(r.CurrencyCode, b.CurrencyCode);
  CheckTrue(SameValue(r, TAmount.Create(61/1.15 + 39, r.CurrencyCode)), 'Adding b + a not working');

end;

procedure TAmountArtithmeticTests.TestDivide;
var
  c: currency;
  d: double;
  e: extended;
  i: integer;
  a: TAmount;
  a2: TAmount;
  b: TAmount;
begin

  c := 23.9986;
  d := 1576.098;
  e := 1178943.877632;
  i := 6542;

  a := 899661;
  b := a / c;
  CheckTrue(SameValue(b.Value, 899661/ 23.9986, 0.001), 'Dividing currency not working');
  b := a / d;
  CheckTrue(SameValue(b.Value, 899661 / 1576.098, 0.001), 'Dividing double not working');
  b := a / e;
  CheckTrue(SameValue(b.Value, 899661 / 1178943.877632, 0.001), 'Dividing extended not working');
  b := a / i;
  CheckTrue(SameValue(b.Value, 899661 / 6542, 0.001), 'Dividing integer not working');

  a2 := TAmount.Create(91.2623, a.CurrencyCode);
  b := a / a2;
  CheckTrue(SameValue(b.Value, RoundDecimals(899661 / 91.2623, 4), 0.0001), 'Dividing by same currency not working');
  a2 := TAmount.Create(91.2623, 'GBP');
  b := a /a2;
  CheckTrue(SameValue(b.Value, 899661 / RoundDecimals(91.2623 * 1.15, 4), 0.0001), 'Dividing by different currency not working');
end;

procedure TAmountArtithmeticTests.TestMultiply;
var
  c: currency;
  d: double;
  e: extended;
  i: integer;
  a: TAmount;
  a2: TAmount;
  b: TAmount;
begin

  c := 23.9986;
  d := 1576.098;
  e := 78943.877632;
  i := 653542;
  a2 := TAmount.Create(911.0665, 'EUR');

  a := TAmount.Create(61, 'GBP');
  b := a * c;
  CheckTrue(SameValue(b.Value, 61 * 23.9986, 0.0001), 'Multiplying currency not working');
  b := a * d;
  CheckTrue(SameValue(b.Value, 61 * 1576.098, 0.0001), 'Multiplying double not working');
  b := a * e;
  CheckTrue(SameValue(b.Value, 61 * 78943.877632, 0.0001), 'Multiplying extended not working');
  b := a * i;
  CheckTrue(b.Value = 61 * 653542, 'Multiplying integer not working');

  a2 := TAmount.Create(911.0665, 'EUR');
  b := a * a2;
  CheckTrue(SameValue(b.Value, 61 * RoundDecimals(911.0665 / 1.15, 4), 0.0001), 'Multiplying amounts with diff currencies not working');
  a2 := TAmount.Create(911.0665, a.CurrencyCode);
  b := a * a2;
  CheckTrue(SameValue(b.Value, 61 * 911.0665, 0.0001), 'Multiplying amounts with same currencies not working');

end;

procedure TAmountArtithmeticTests.TestSetupTearDown;
begin
  CheckTrue(True);
end;

procedure TAmountArtithmeticTests.TestSubtract;
var
  c: currency;
  d: double;
  e: extended;
  i: integer;
  a: TAmount;
  b: TAmount;
  r: TAmount;
begin

  c := 23.9986;
  d := 1576.098;
  e := 78943.877632;
  i := 653542;

  a := 61;
  b := a - c;
  CheckTrue(SameValue(b.Value, 61 - 23.9986), 'Subtracting currency not working');
  b := a - d;
  CheckTrue(SameValue(b.Value, 61 - 1576.098), 'Subtracting double not working');
  b := a - e;
  CheckTrue(SameValue(b.Value, 61 - 78943.8776), 'Subtracting extended not working');
  b := a - i;
  CheckTrue(b.Value = 61 - 653542, 'Subtracting integer not working');

  b := TAmount.Create(39, 'EUR');
  CheckEquals(TAmount(a-b).Value, 61-39, 'Subtracting same currencies not working');

  b := TAmount.Create(39, 'GBP');

  r := a - b;
  CheckEqualsString(r.CurrencyCode, CurrencyManager.DefaultCurrency);
  CheckTrue(SameValue(r.Value, 61 - 39 * 1.15, 0.0001), 'Subtracting a- b not working');

  r := b - a;
  CheckEqualsString(r.CurrencyCode, b.CurrencyCode);
  CheckTrue(SameValue(r.Value, 39 - 61/1.15, 0.0001), 'Subtracting b - a not working');
end;

{ TAmountCompareTests }

procedure TAmountCompareTests.SetUp;
begin
  inherited;
  CurrencyManager.CreateDefinition('USD').Rate := 0.89;
end;

procedure TAmountCompareTests.TearDown;
begin
  inherited;
  CurrencyManager.ClearDefinitions;
end;

procedure TAmountCompareTests.TestEqual;
var
  a, b, c: TAmount;
  d: double;
begin
  // SAme default currency
  a := 61;
  b := 61;
  c := 61.0001;
  d := 61.000101;
  CheckTrue(a = b);
  CheckFalse(a <> b);
  CheckFalse(a = c);
  CheckTrue(c = d);
  CheckFalse(a = d);

  // Same other currency
  a := TAmount.Create(61, 'USD');
  b := TAmount.Create(61, 'USD');
  c := TAmount.Create(61.0001, 'USD');
  CheckTrue(a = b);
  CheckFalse(a <> b);
  CheckTrue(c <> d);
  CheckFalse(a = d);

  // Different currency
  a := TAmount.Create(61, 'USD');
  b := TAmount.Create(61, 'EUR');
  CheckFalse(a = b);
  CheckTrue(a <> b);

end;

procedure TAmountCompareTests.TestGreaterAndLesser;
var
  a, b: TAmount;
begin

  a := 98.99;
  b := 98.9901;

  CheckTrue(a < b);
  CheckTrue(b > a);
  CheckTrue(a <= b);
  CheckTrue(b >= a);

  b := TAmount.Create(98.99, 'USD');
  CheckFalse(a < b);

end;

procedure TAmountCompareTests.TestSetupTearDown;
begin
  CheckTrue(True);
end;

initialization
  RegisterTest(TAmountImplicitTests.Suite);
  RegisterTest(TAmountArtithmeticTests.Suite);
  RegisterTest(TAmountCompareTests.Suite);
end.
