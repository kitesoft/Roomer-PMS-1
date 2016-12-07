program RoomerUpgradeAgent;

uses
  Vcl.Forms,
  uUpgraderMainForm in 'uUpgraderMainForm.pas' {frmUpgradeAgent},
  uRunWithElevatedOption in '..\..\uRunWithElevatedOption.pas',
  uUpgraderCmdlineOptions in 'uUpgraderCmdlineOptions.pas',
  uRoomerHttpClient in '..\..\RoomerVCLs\Source\uRoomerHttpClient.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;

  if TUpgraderCmdlineOptions.ParseCommandLine then
  begin
    Application.CreateForm(TfrmUpgradeAgent, frmUpgradeAgent);
    Application.Run;
  end;
end.
