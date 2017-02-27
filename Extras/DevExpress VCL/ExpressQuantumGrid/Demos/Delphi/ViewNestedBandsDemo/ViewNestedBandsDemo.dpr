program ViewNestedBandsDemo;

uses
  Forms,
  ViewNestedBandsDemoMain in 'ViewNestedBandsDemoMain.pas' {ViewNestedBandsDemoMainForm},
  ViewNestedBandsDemoData in 'ViewNestedBandsDemoData.pas' {ViewNestedBandsDemoDataDM: TDataModule},
  AboutDemoForm in '..\AboutDemoForm.pas' {formAboutDemo},
  BaseForm in '..\BaseForm.pas' {fmBaseForm},
  SkinDemoUtils in '..\SkinDemoUtils.pas',
  DemoUtils in '..\DemoUtils.pas';

  {$R *.res}
  {$R WindowsXP.res}

begin
  Application.Initialize;
  Application.Title := 'ExpressQuantumGrid ViewNestedBandsDemo';
  Application.CreateForm(TViewNestedBandsDemoDataDM, ViewNestedBandsDemoDataDM);
  Application.CreateForm(TViewNestedBandsDemoMainForm, ViewNestedBandsDemoMainForm);
  Application.Run;
end.
