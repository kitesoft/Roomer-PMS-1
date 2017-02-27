program SummaryMultiDemo;

uses
  Forms,
  SummaryMultiDemoMain in 'SummaryMultiDemoMain.pas' {SummaryMultiDemoMainForm},
  SummaryMultiDemoData in 'SummaryMultiDemoData.pas' {SummaryMultiDemoDataDM: TDataModule},
  AboutDemoForm in '..\AboutDemoForm.pas' {formAboutDemo},
  BaseForm in '..\BaseForm.pas' {fmBaseForm},
  SkinDemoUtils in '..\SkinDemoUtils.pas',
  DemoUtils in '..\DemoUtils.pas';

  {$R *.res}
  {$R WindowsXP.res}

begin
  Application.Initialize;
  Application.Title := 'ExpressQuantumGrid SummaryMultiDemo';
  Application.CreateForm(TSummaryMultiDemoDataDM, SummaryMultiDemoDataDM);
  Application.CreateForm(TSummaryMultiDemoMainForm, SummaryMultiDemoMainForm);
  Application.Run;
end.
