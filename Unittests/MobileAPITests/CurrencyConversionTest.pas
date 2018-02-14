unit CurrencyConversionTest;

interface

uses
  TestFramework
  , uCurrencyConstants
  ;

type

  TCurrencyConversionTest = class(TTestCase)
  public
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestSetupTearDown;
    procedure TestConvertTo;
    procedure TestConvertToUnknown;
    procedure TestConvertToNative;
    procedure TestConvertWithFixedRateInAmount;
  end;

implementation

uses
  SysUtils
  , uAmount
  , uCurrencyManager
  , Math
  , uFloatUtils
  ;

{ TCurrencymanagertest }

procedure TCurrencyConversionTest.SetUp;
begin
  InitGlobalCurrencyManager(TCurrencyManager, 'EUR');
  CurrencyManager.DefaultCurrency := 'EUR';
  CurrencyManager.CreateDefinition('GBP').Rate := 1.15;
  CurrencyManager.CreateDefinition('ISK').Rate := 0.007;
end;

procedure TCurrencyConversionTest.TearDown;
begin
  CurrencyManager.ClearCache;
end;

procedure TCurrencyConversionTest.TestConvertToUnknown;
var
  v1, v2: TAmount;
begin
  v1 := TAmount.Create(153400, 'ISK');
  ExpectedException := ECurrencyConversionException;
  v2 := v1.ToCurrency('ANT');
end;

procedure TCurrencyConversionTest.TestConvertWithFixedRateInAmount;
var
  v1, v2: TAmount;
begin
  v1 := TAmount.Create(15.35, 'GBP');
  CheckTrue(SameValue(1.15, v1.CurrencyRate));
  v1.CurrencyRate := 2.30; // override global rate of GBP
  CheckTrue(SameValue(2.30, v1.CurrencyRate));

  v2 := v1.ToCurrency('EUR');
  CheckTrue(SameValue(15.35 * 2.30, v2.Value, 0.0001), Format('Expected %f, found %f', [ 15.35*2.30, v2.value]));
  v1.CurrencyRate := 0;
  v2 := v1.ToCurrency('EUR');
  CheckTrue(SameValue(15.35 * 1.15, v2.Value, 0.0001), Format('Expected %f, found %f', [ 15.35*1.15, v2.value]));
end;

procedure TCurrencyConversionTest.TestConvertTo;
var
  v1, v2: TAmount;
begin
  v1 := TAmount.Create(15.35, 'EUR');
  v2 := v1.ToCurrency('GBP');
  CheckTrue(SameValue(15.35 / 1.15, v2.Value, 0.0001), Format('Expected %f, found %f', [ 15.35/1.15, v2.value]));
  CheckEqualsString(string(v2.CurrencyCode), 'GBP');

  CheckTrue(SameValue(v1.Value, v2.ToCurrency('EUR'), 0.0001), 'Rondtrip conversion failed');
end;

procedure TCurrencyConversionTest.TestConvertToNative;
var
  v1, v2: TAmount;
begin
  v1 := TAmount.Create(15.35, 'GBP');
  v2 := v1.ToNative;
  CheckTrue(SameValue(15.35 * 1.15, v2.Value, 0.0001), Format('Expected %f, found %f', [ 15.35*1.15, v2.value]));
  CheckEqualsString(string(v2.CurrencyCode), 'EUR');

end;

procedure TCurrencyConversionTest.TestSetupTearDown;
begin
  CheckTrue(True);
end;

initialization
  RegisterTest(TCurrencyConversionTest.Suite);
end.
