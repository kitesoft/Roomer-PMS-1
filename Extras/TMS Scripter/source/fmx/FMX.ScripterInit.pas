unit FMX.ScripterInit;

interface
uses
  atScript;

implementation
uses
  FMX.ScripterMachine,
  FMX.ScriptForm;

var
  FMXScriptFormFactory: TFMXScriptFormFactory;

initialization
  atScript.DefaultMachineClass := FMX.ScripterMachine.TScripterMachine;
  atScript.DefaultScriptFormClass := FMX.ScriptForm.TScriptForm;
  FMXScriptFormFactory := TFMXScriptFormFactory.Create;
  atScript.ScriptFormFactory := FMXScriptFormFactory;

finalization
  FMXScriptFormFactory.Free;

end.

