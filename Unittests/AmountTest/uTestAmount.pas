unit uTestAmount;

interface
uses
  DUnitX.TestFramework;

type

  [TestFixture]
  TTestAmount = class(TObject) 
  public
    [Setup]
    procedure Setup;
    [TearDown]
    procedure TearDown;
    // Sample Methods
    // Simple single Test
    [Test]
    procedure Test1;
  end;

implementation

uses
  SysUtils,
  Windows
  ;
procedure TTestAmount.Setup;
begin
end;

procedure TTestAmount.TearDown;
begin
end;

procedure TTestAmount.Test1;
begin
end;

initialization
  //TDUnitX.RegisterTestFixture(TTestAmount);
end.
