unit CurrencyDefinitionTest;

interface
uses
  TestFramework,
  uCurrencyDefinition;

type
  TTestCurrencyDefinition = class(TTestCase)
  private
    FCurrDef: TCurrencyDefinition;
  public
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestSetupTearDown;
    procedure TestFormattedValue;
  end;

implementation

uses
  SysUtils
  ;

{ TTestCurrencyhandler }

procedure TTestCurrencyDefinition.Setup;
var
  lFormatSettings: TFormatSettings;
begin
  FCurrDef := TCurrencyDefinition.Create('EUR');
  FCurrDef.Description := 'Euro';
  lFormatSettings := FCurrDef.CurrencyFormatSettings;
  lFormatSettings.DecimalSeparator := 'q';
  lFormatSettings.ThousandSeparator := 'z';
  FCurrDef.CurrencyFormatSettings := lFormatSettings;
  FCUrrDef.Symbol := 'x';
end;

procedure TTestCurrencyDefinition.TearDown;
begin
  FCurrDef.Free;
end;

procedure TTestCurrencyDefinition.TestFormattedValue;
begin
  CheckEqualsString('123q46', FCurrDef.FormattedValue(123.4567));
  CheckEqualsString('x 123q44', FCurrDef.FormattedValue(123.4447, True));
  CheckEqualsString('x 98z123q44', FCurrDef.FormattedValue(98123.4447, True));
end;

procedure TTestCurrencyDefinition.TestSetupTearDown;
begin
  CheckTrue(true);
end;

initialization
  RegisterTest(TTestCurrencyDefinition.Suite);
end.
