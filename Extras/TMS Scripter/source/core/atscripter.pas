unit atScripter;

{$I ASCRIPT.INC}

interface
uses
  Classes, atScript;

type
  {Indicates the language/syntax of the script.}
  TScriptLanguage = (
    slPascal,  //Pascal language
    slBasic    //Basic language
  );

  ///  <summary>
  ///    Main scripter component used to execute scripts, supporting several languages.
  ///  </summary>
  ///  <remarks>
  ///    TatScripter component is a TatCustomScripter descendant that effectively implement the script languages.
  ///    Alternatively to the deprecated TatPascalScripter and TatBasicScripter components, which only deal with one
  ///    language type, TatScripter component can create and execute scripts in all languages supported by Scripter Studio
  ///    package. You can use AddScript method to add a new script and define its language.
  ///    Most of properties, methods, collections you will use in TatScripter are implemented in its abstract ancestor,
  ///    TatCustomScripter.
  ///  </remarks>
  TatBaseScripter = class(TatCustomScripter)
  private
    FDefaultLanguage: TScriptLanguage;
    function LanguageToClass(ALanguage: TScriptLanguage): TScriptClass;
  protected
    procedure DefineInternalClasses; override;
    function DefaultScriptClass: TScriptClass; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    ///  <summary>
    ///    Adds a new script object in Scripts collection with the specified language.
    ///  </summary>
    ///  <param name="ALanguage">
    ///  Specifies the language of the script to be created.
    /// </param>
    ///  <remarks>
    ///    Use AddScript method to create a new script in Scripts collection. You can use this method as an alternative to
    ///    Scripts.Add, which uses DefaultLanguage property to know which language the created script will support.
    ///    Depending on the language, AddScript creates a TatScript descendant (for example, TatPascalScript for pascal language.
    ///  </remarks>
    function AddScript(ALanguage: TScriptLanguage): TatScript;
  published
    ///  <summary>
    ///    Specifies the default language for next scripts added to the collection.
    ///  </summary>
    ///  <remarks>
    ///    Use DefaultLanguage to specify the language of the next scripts created in the scripter component using Scripts.Add
    ///    method. Note that changing DefaultLanguage does not change the language of existing script objects, it will only
    ///    be used for the next scripts that will be created.
    ///    Alternatively you can use AddScript method to add a script specifying the language of the script as a parameter.
    ///  </remarks>
    property DefaultLanguage: TScriptLanguage read FDefaultLanguage write FDefaultLanguage;

    property SourceCode;
    property Compiled;
    property SaveCompiledCode;
    property EventSupport;
    property EventSetMode;
    property EventUnsetMode;
    property OnDebugHook;
    property OnExecHook;
    property OnCompileError;
    property OnRuntimeError;
    property OnExecuteEvent;
    property OnSettingEvent;
    property OnSetEvent;
    property OnUnsettingEvent;
    property ShortBooleanEval;
    property LibOptions;
    property CallExecHookEvent;
    property OnUnknownElement;
    property OnBreakpointStop;
  end;

  {$IFDEF DELPHIXE2_LVL}
  [ComponentPlatformsAttribute(pidWin32 or pidWin64)]
  {$ENDIF}
  TatScripter = class(TatBaseScripter)
  end;

implementation
uses
  Languages.Pascal, Languages.Basic;

{ TatBaseScripter }

function TatBaseScripter.AddScript(ALanguage: TScriptLanguage): TatScript;
begin
  result := LanguageToClass(ALanguage).Create(Scripts);
end;

constructor TatBaseScripter.Create(AOwner: TComponent);
begin
  FDefaultLanguage := slPascal;
  ShortBooleanEval := true;
  OptionExplicit := true;
  inherited Create(AOwner);
   if Assigned(OnGlobalScripterCreate) then
     OnGlobalScripterCreate(Self);
end;

function TatBaseScripter.DefaultScriptClass: TScriptClass;
begin
  result := LanguageToClass(FDefaultLanguage);
end;

procedure TatBaseScripter.DefineInternalClasses;
begin
  inherited;
  ScriptClass := TatScript; //Do not create a specific script language
end;

destructor TatBaseScripter.Destroy;
begin
  inherited;

end;

function TatBaseScripter.LanguageToClass(ALanguage: TScriptLanguage): TScriptClass;
begin
  Case ALanguage of
    slBasic: result := TatBasicScript;
  else
    //slPascal
    result := TatPascalScript;
  end;
end;

end.
