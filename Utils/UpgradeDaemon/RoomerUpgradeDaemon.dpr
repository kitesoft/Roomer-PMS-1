program RoomerUpgradeDaemon;

uses
  Vcl.Forms,
  uUpgradeDeamonMainForm in 'uUpgradeDeamonMainForm.pas' {frmUpgradeDaemon},
  uRunWithElevatedOption in '..\..\uRunWithElevatedOption.pas',
  uRoomerHttpClient in '..\..\RoomerVCLs\Source\uRoomerHttpClient.pas',
  URIParser in 'URIParser.pas' {/  uUpgradeFileManager in 'uUpgradeFileManager.pas',},
  uRoomerUpgradeFileDependencyManager in 'uRoomerUpgradeFileDependencyManager.pas',
  uUpgradeFileManager in 'uUpgradeFileManager.pas',
  uFileSystemUtils in '..\..\uFileSystemUtils.pas' {/  uRoomerDefinitions in '..\..\uRoomerDefinitions.pas';},
  uRoomerDefinitions in '..\..\uRoomerDefinitions.pas',
  uUtils in '..\..\RoomerUtils\uUtils.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := false;

  Application.ShowMainForm := false;
  Application.CreateForm(TfrmUpgradeDaemon, frmUpgradeDaemon);
  Application.Run;
end.
