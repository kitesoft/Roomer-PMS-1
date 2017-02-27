unit FMX.ScriptForm;

{$I AScript.Inc}

interface
uses
  Classes,
  FMX.Forms,
  atScript;

type
  ///  <remarks>
  ///  TScriptForm is the base class for script forms, a special kind of form declared in script. Script forms are defined
  ///  using the $FORM directive. When this happens, the scripter understands the script as a "form declaration", and all
  ///  methods and properties declared in script are treated as if they were methods and properties of the form class.
  ///  You can instantiate such forms from another script. All forms instantiated that way are inherited from TScriptForm class.
  ///  </remarks>
  TScriptForm = class(TForm, IScriptBasedForm)
  private
    FRunScript: TatScript;
    FDesignScript: TatScript;
    FSaveProps: TStrings;
    FSaveEvents: TStrings;
    FOnReadState: TNotifyEvent;
    procedure SetSaveProps(const Value: TStrings);
    procedure SetSaveEvents(const Value: TStrings);
  private
    {IScriptBasedForm methods}
    function GetRunScript: TatScript;
    function GetSaveEvents: TStrings;
    function GetSaveProps: TStrings;
    function GetForm: TComponent;
    procedure SetRunScript(const Value: TatScript);
    procedure SetOnReadState(Handler: TNotifyEvent);
  protected
    procedure ReadState(Reader: TReader); override;

    ///  <summary>
    ///  CreateFromScript constructor is called from scripter engine when a script form is instantiated by a script code.
    ///  You will not need to call CreateFromScript method nor to instantiate a TScriptForm class directly.
    ///  </summary>
    constructor CreateFromScript(AOwner: TComponent; AMachine: TatVirtualMachine); virtual;

    ///  <remarks>
    ///  RunScript retrieves the underlying script object which has the source code for the form. The script routines
    ///  will behave as form methods. Each form instance has its own RunScript. When a form is instantiated, a new RunScript
    ///  is created and its content is copied from the base script where the form was declared.
    ///  </remarks>
    property RunScript: TatScript read GetRunScript write SetRunScript;
  public
    constructor Create(AOwner: TComponent); override;
    {$IFDEF DELPHIXE5_LVL}
    constructor CreateNew(AOwner: TComponent; Dummy: NativeInt = 0); override;
    {$ELSE}
    constructor CreateNew(AOwner: TComponent; Dummy: integer = 0); override;
    {$ENDIF}

    destructor Destroy; override;

    ///  <summary>
    ///  DesignScript property is not being used in current version.
    ///  </summary>
    property DesignScript: TatScript read FDesignScript write FDesignScript;
  published
    ///  <remarks>
    ///  SaveProps property holds the list of property values to be saved when the form is serialized. The format is
    ///  PropertyName=PropertyValue
    ///  You should not use this property, it's only used by scripter IDE.
    ///  </remarks>
    property SaveProps: TStrings read GetSaveProps write SetSaveProps;

    ///  <remarks>
    ///  SaveEvents property holds the list of event values to be saved when the form is serialized. The format is
    ///  EventName=EventHandler
    ///  You should not use this property, it's only used by scripter IDE.
    ///  </remarks>
    property SaveEvents: TStrings read GetSaveEvents write SetSaveEvents;

    property Visible stored false;
    property Left stored false;
    property Top stored false;
    property WindowState stored false;
    property BorderStyle stored false;
    property ActiveControl stored false;
  end;

  TFMXScriptFormFactory = class(TScriptFormFactory)
  public
    function CreateScriptForm(AOwner: TComponent; AMachine: TatVirtualMachine): TBaseScriptForm; override;
  end;

  TFMXScriptFormClass = class of TScriptForm;

implementation
uses
  SysUtils;

{ TScriptForm }

destructor TScriptForm.Destroy;
begin
  if FRunScript <> nil then
  begin
    FRunScript.Free;
    FRunScript := nil;
  end;
  FSaveProps.Free;
  FSaveEvents.Free;
  inherited;
end;

function TScriptForm.GetForm: TComponent;
begin
  Result := Self;
end;

function TScriptForm.GetRunScript: TatScript;
begin
  Result := FRunScript;
end;

function TScriptForm.GetSaveEvents: TStrings;
begin
  Result := FSaveEvents;
end;

function TScriptForm.GetSaveProps: TStrings;
begin
  Result := FSaveProps;
end;

type
  THackMachine = class(TatVirtualMachine)
  end;

constructor TScriptForm.CreateFromScript(AOwner: TComponent; AMachine: TatVirtualMachine);
var
  AForm: TBaseScriptForm;
  Loader: TScriptFormLoader;
  TheRunScript: TatScript;
  FormIntf: IScriptBasedForm;
begin
  CreateNew(AOwner);

  AForm := Self;
  if not Supports(AForm, IScriptBasedForm, FormIntf) then
    AMachine.Script.RuntimeError('IScriptBasedForm not found in ScriptFormClass');
  TheRunScript := THackMachine(AMachine).CreateFormRunScript(AForm);
  FormIntf.SetRunScript(TheRunScript);
  Loader := TScriptFormLoader.Create(FormIntf);
  try
    Loader.LoadFormResource(TheRunScript.ScriptInfo.FormResource, TheRunScript.Scripter.LoadFormEvents);
//    Loader.RestoreSavedEvents;
//    Loader.RestoreSavedProps;
  finally
    Loader.Free;
  end;
end;

constructor TScriptForm.Create(AOwner: TComponent);
begin
  CreateNew(AOwner);
end;

{$IFDEF DELPHIXE5_LVL}
constructor TScriptForm.CreateNew(AOwner: TComponent; Dummy: NativeInt);
{$ELSE}
constructor TScriptForm.CreateNew(AOwner: TComponent; Dummy: integer);
{$ENDIF}
begin
  FSaveProps := TStringList.Create;
  FSaveEvents := TStringList.Create;
  Visible := false;
  FSaveProps.Values['Visible'] := 'False';

  // KeyPreview := true;
  inherited;
end;

procedure TScriptForm.SetSaveProps(const Value: TStrings);
begin
  FSaveProps.Assign(Value);
end;

procedure TScriptForm.SetOnReadState(Handler: TNotifyEvent);
begin
  FOnReadState := Handler;
end;

procedure TScriptForm.SetRunScript(const Value: TatScript);
begin
  FRunScript := Value;
end;

procedure TScriptForm.SetSaveEvents(const Value: TStrings);
begin
  FSaveEvents.Assign(Value);
end;

procedure TScriptForm.ReadState(Reader: TReader);
begin
  inherited;
  if Assigned(FOnReadstate) then
    FOnReadState(Self);
end;

{ TFMXScriptFormFactory }

function TFMXScriptFormFactory.CreateScriptForm(AOwner: TComponent;
  AMachine: TatVirtualMachine): TBaseScriptForm;
begin
  Assert(AMachine.Scripter.ScriptFormClass.InheritsFrom(TScriptForm));
  Result := TFMXScriptFormClass(AMachine.Scripter.ScriptFormClass).CreateFromScript(AOwner, AMachine);
end;

end.
