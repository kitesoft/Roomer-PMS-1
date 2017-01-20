program CurrencyTests;
{

  Delphi DUnit Test Project
  -------------------------
  This project contains the DUnit test framework and the GUI/Console test runners.
  Add "CONSOLE_TESTRUNNER" to the conditional defines entry in the project options
  to use the console test runner.  Otherwise the GUI test runner will be used by
  default.

}

{$IFDEF CONSOLE_TESTRUNNER}
{$APPTYPE CONSOLE}
{$ENDIF}

uses
  DUnitTestRunner,
  CurrencyDefinitionTest in 'CurrencyDefinitionTest.pas',
  CurrencyManagerTest in 'CurrencyManagerTest.pas',
  CurrencyConversionTest in 'CurrencyConversionTest.pas',
  AmountTest in 'AmountTest.pas',
  uAmount in '..\..\RoomerVCLs\Source\uAmount.pas',
  uCurrencyConstants in '..\..\RoomerVCLs\Source\uCurrencyConstants.pas',
  uCurrencyDefinition in '..\..\RoomerVCLs\Source\uCurrencyDefinition.pas',
  uCurrencyManager in '..\..\RoomerVCLs\Source\uCurrencyManager.pas',
  uFloatUtils in '..\..\RoomerVCLs\Source\uFloatUtils.pas';

{$R *.RES}

begin
  DUnitTestRunner.RunRegisteredTests;
end.

