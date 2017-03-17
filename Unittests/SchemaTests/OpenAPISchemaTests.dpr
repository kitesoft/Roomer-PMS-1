program OpenAPISchemaTests;
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
  TestRoomerBookingCommunicationModel_RequestsResponses in 'TestRoomerBookingCommunicationModel_RequestsResponses.pas',
  RoomerBookingCommunicationModel_RequestsResponses in '..\..\OpenAPI\schema\RoomerBookingCommunicationModel_RequestsResponses.pas',
  RoomerConfigurationItemsCommunicationModel_RequestsResponses in '..\..\OpenAPI\schema\RoomerConfigurationItemsCommunicationModel_RequestsResponses.pas',
  RoomerFinancialDataModel_ModelObjects in '..\..\OpenAPI\schema\RoomerFinancialDataModel_ModelObjects.pas',
  uRoomerCanonicalDataModel_BaseTypes in '..\..\OpenAPI\schema\uRoomerCanonicalDataModel_BaseTypes.pas',
  uRoomerCanonicalDataModel_SimpleTypes in '..\..\OpenAPI\schema\uRoomerCanonicalDataModel_SimpleTypes.pas',
  uRoomerHotelServicesCommunicationModel_RequestsResponses in '..\..\OpenAPI\schema\uRoomerHotelServicesCommunicationModel_RequestsResponses.pas',
  uRoomerHotelServicesCommunicationModel_RunningTabs in '..\..\OpenAPI\schema\uRoomerHotelServicesCommunicationModel_RunningTabs.pas',
  uRoomerSchema in '..\..\OpenAPI\schema\uRoomerSchema.pas',
  XmlUtils in '..\..\RoomerUtils\XmlUtils.pas',
  DUnitTestRunner,
  uExceptionUtils in '..\..\RoomerUtils\uExceptionUtils.pas';

{R *.RES}

begin
  DUnitTestRunner.RunRegisteredTests;
end.

