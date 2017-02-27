program CardLayoutDemo;

uses
  Forms,
  CardLayoutDemoMain in 'CardLayoutDemoMain.pas' {frmMain},
  AboutDemoForm in '..\AboutDemoForm.pas' {formAboutDemo},
  SkinDemoUtils in '..\SkinDemoUtils.pas',
  BaseForm in '..\BaseForm.pas' {fmBaseForm};

  {$R *.res}
  {$R WindowsXP.res}

begin
  Application.Initialize;
  Application.Title := 'ExpressQuantumGrid CardLayout Demo';
  Application.CreateForm(TfrmMain, frmMain);
  Application.Run;
end.
