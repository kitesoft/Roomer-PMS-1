program RoomerDataConvert;

uses
  Vcl.Forms,
  uDataUnit in 'uDataUnit.pas',
  uRoomerDataConvertMain in 'uRoomerDataConvertMain.pas' {frmRoomerDataConvertMain},
  uDataBuilder in 'uDataBuilder.pas',
  uSplitUtils in 'uSplitUtils.pas',
  uCSVData in 'uCSVData.pas',
  XmlUtils in '..\..\RoomerUtils\XmlUtils.pas',
  uUtils in '..\..\RoomerUtils\uUtils.pas',
  uSQLUtils in '..\..\RoomerUtils\uSQLUtils.pas',
  uFileSystemUtils in '..\..\uFileSystemUtils.pas',
  uRunWithElevatedOption in '..\..\uRunWithElevatedOption.pas',
  uRoomerDefinitions in '..\..\uRoomerDefinitions.pas',
  uFloatUtils in '..\..\RoomerVCLs\Source\uFloatUtils.pas',
  uRegistryServices in '..\..\uRegistryServices.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TfrmRoomerDataConvertMain, frmRoomerDataConvertMain);
  Application.Run;
end.
