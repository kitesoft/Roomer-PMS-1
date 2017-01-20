unit CurrencyManagerTest;

interface

uses
  TestFramework
  , uCurrencymanager
  ;

type

  TCurrencymanagertest = class(TTestCase)
  private
    FMgr: TCurrencyManager;
  public
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestSetupTearDown;
    procedure TestStartEmpty;
    procedure TestAddDefaultRate;
    procedure TestAddAndCHangeRate;
    procedure TestChangeDefaultToNew;
    procedure TestChangeDefaultToExisting;
    procedure TestCreateAndRetrieveByID;
  end;

implementation

uses
  SysUtils
  , Math
  ;

{ TCurrencymanagertest }

procedure TCurrencymanagertest.SetUp;
begin
  FMgr := TCurrencymanager.Create;
end;

procedure TCurrencymanagertest.TearDown;
begin
  FMgr.Free;
end;

procedure TCurrencymanagertest.TestAddAndChangeRate;
begin
  FMgr.CreateDefinition('GBP');
  CheckEquals(FMgr.CurrencyDefinition['GBP'].Rate, 1.0);
  FMgr.CurrencyDefinition['GBP'].Rate := 1.15;
  CheckTrue(SameValue(1.15, FMgr.CurrencyDefinition['GBP'].Rate));
end;

procedure TCurrencymanagertest.TestAddDefaultRate;
begin
  Fmgr.CreateDefinition('FFF');
  CheckTrue(SameValue(1.0, FMgr.CurrencyDefinition['FFF'].Rate));
  CheckTrue(FMgr.DefinitionExists('FFF'));
end;

procedure TCurrencymanagertest.TestChangeDefaultToExisting;
begin
  FMgr.CreateDefinition('GBP').Rate := 1.15;
  FMgr.CreateDefinition('ISK').Rate := 0.0007;

  FMgr.DefaultCurrency := 'GBP';
  CHeckTrue(SameValue(1.0 / 1.15, FMgr.CurrencyDefinition['EUR'].Rate));
  CHeckTrue(SameValue(1.0, FMgr.CurrencyDefinition['GBP'].Rate));
  CHeckTrue(SameValue(0.0007 / 1.15, FMgr.CurrencyDefinition['ISK'].Rate));
end;

procedure TCurrencymanagertest.TestChangeDefaultToNew;
begin
  FMgr.CreateDefinition('GBP').Rate := 1.15;
  FMgr.CreateDefinition('ISK').Rate := 0.0007;

  FMgr.DefaultCurrency := 'ANT';
  CHeckTrue(SameValue(1.0, FMgr.CurrencyDefinition['EUR'].Rate));
  CHeckTrue(SameValue(1.15, FMgr.CurrencyDefinition['GBP'].Rate));
  CHeckTrue(SameValue(0.0007, FMgr.CurrencyDefinition['ISK'].Rate));
  CHeckTrue(SameValue(1.0, FMgr.CurrencyDefinition['ANT'].Rate));
end;

procedure TCurrencymanagertest.TestCreateAndRetrieveByID;
begin
  FMgr.CreateDefinition('GBP', 17).Rate := 1.15;
  FMgr.CreateDefinition('ISK', 21).Rate := 0.0007;

  CheckTrue(FMgr.CurrencyDefinitionByID[21].CurrencyCode = 'ISK');
end;

procedure TCurrencymanagertest.TestSetupTearDown;
begin
  CHeckTrue(True);
end;

procedure TCurrencymanagertest.TestStartEmpty;
begin
  CheckTrue(FMgr.DefinitionExists('EUR'));
end;

initialization
  RegisterTest(TCurrencymanagertest.Suite);
end.
