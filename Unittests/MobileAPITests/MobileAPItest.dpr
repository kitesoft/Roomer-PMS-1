program MobileAPItest;
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
  HotelStatisticsTest in 'HotelStatisticsTest.pas',
  uHotelStatistics in '..\..\HotelStatstics\uHotelStatistics.pas',
  uRoomerSchema in '..\..\OpenAPI\schema\uRoomerSchema.pas',
  XmlUtils in '..\..\RoomerUtils\XmlUtils.pas',
  ReservationTaxesTest in 'ReservationTaxesTest.pas',
  RoomerExceptionHandling in '..\..\RoomerExceptionHandling.pas',
  uUtils in '..\..\RoomerUtils\uUtils.pas',
  uRoomRentTaxReceipt in '..\..\MobileAPI\uRoomRentTaxReceipt.pas';

{$R *.RES}

begin
  DUnitTestRunner.RunRegisteredTests;
end.

