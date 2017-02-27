program DBBreadcrumbEditDemo;

uses
  Forms,
  BaseForm in '..\BaseForm.pas',
  DemoUtils in '..\DemoUtils.pas',
  AboutDemoForm in '..\AboutDemoForm.pas',
  DBBreadcrumbEditDemoMain in 'DBBreadcrumbEditDemoMain.pas' {dxDBBreadcrumbEditDemoForm};

  {$R *.res}
  {$R WindowsXP.res}

begin
  Application.Initialize;
  Application.CreateForm(TdxDBBreadcrumbEditDemoForm, dxDBBreadcrumbEditDemoForm);
  Application.Run;
end.
