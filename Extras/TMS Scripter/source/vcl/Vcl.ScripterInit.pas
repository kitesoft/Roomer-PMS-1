unit Vcl.ScripterInit;

interface
uses
  atScript;

implementation
uses
  Vcl.ScripterMachine,
  Vcl.ScriptForm;

var
  VCLScriptFormFactory: TVCLScriptFormFactory;

initialization
  atScript.DefaultMachineClass := Vcl.ScripterMachine.TScripterMachine;
  atScript.DefaultScriptFormClass := Vcl.ScriptForm.TScriptForm;
  VCLScriptFormFactory := TVCLScriptFormFactory.Create;
  atScript.ScriptFormFactory := VCLScriptFormFactory;

finalization
  VCLScriptFormFactory.Free;

end.
