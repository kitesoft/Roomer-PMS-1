unit CurrencyDefinitionTest;

interface
uses
  TestFramework,
  uCurrencyDefinition;

type
  TTestCurrencyDefinition = class(TTestCase)
  public
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestSetupTearDown;
  end;

implementation


{ TTestCurrencyhandler }

procedure TTestCurrencyDefinition.Setup;
begin

end;

procedure TTestCurrencyDefinition.TearDown;
begin

end;

procedure TTestCurrencyDefinition.TestSetupTearDown;
begin
  CheckTrue(true);
end;

initialization
  RegisterTest(TTestCurrencyDefinition.Suite);
end.
