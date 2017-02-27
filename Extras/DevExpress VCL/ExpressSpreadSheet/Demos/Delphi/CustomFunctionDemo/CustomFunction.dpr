program CustomFunction;

uses
  Forms,
  CustomFunctionFrm in 'CustomFunctionFrm.pas' {CustomFunctionForm},
  AreaCustomFunc in 'AreaCustomFunc.pas';

  {$R *.res}
  {$R WindowsXP.res}

begin
  Application.Initialize;
  Application.CreateForm(TCustomFunctionForm, CustomFunctionForm);
  Application.Run;
end.
