program GridMenuViewsDemo;

uses
  Forms,
  GridMenuViewsDemoMain in 'GridMenuViewsDemoMain.pas' {GridMenuViewsDemoMainForm},
  GridMenuViewsDemoData in 'GridMenuViewsDemoData.pas' {GridMenuViewsDemoDataDM: TDataModule},
  BaseForm in '..\BaseForm.pas' {fmBaseForm},
  SkinDemoUtils in '..\SkinDemoUtils.pas',
  AboutDemoForm in '..\AboutDemoForm.pas' {formAboutDemo};

  {$R *.res}
  {$R WindowsXP.res}

begin
  Application.Initialize;
  Application.Title := 'ExpressQuantumGrid GridMenuViewsDemo';
  Application.CreateForm(TGridMenuViewsDemoDataDM, GridMenuViewsDemoDataDM);
  Application.CreateForm(TGridMenuViewsDemoMainForm, GridMenuViewsDemoMainForm);
  Application.Run;
end.
