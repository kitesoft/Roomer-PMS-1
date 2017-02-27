{***************************************************************************}
{ TMS Scripter Components for Delphi & C++Builder                           }
{                                                                           }
{ written by TMS Software                                                   }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{                                                                           }
{ For information about version history, check the section "What's New"     }
{ at TMS Scripter manual.                                                   }
{                                                                           }
{ The source code is given as is. The author is not responsible             }
{ for any possible damage done due to the use of this code.                 }
{ The component can be freely used in any application. The complete         }
{ source code remains property of the author and may not be distributed,    }
{ published, given or sold in any form as such. No parts of the source      }
{ code can be included in any other component or application without        }
{ written authorization of the author.                                      }
{***************************************************************************}

unit atBasic;

{$I ASCRIPT.INC}

interface

uses
  Classes,
  atScript,
  Languages.Basic;

type
  TatBasicScript = Languages.Basic.TatBasicScript;
    ///  <summary>
    ///    Scripter component that supports scripts with Basic syntax
    ///  </summary>
    ///  <remarks>
    ///    TatBasicScripter is a TatCustomScripter descendant that implements Basic syntax. With this component
    ///    you can create and execute scripts in Basic language.
    ///    This component is deprecated since new TatScripter component allows multiple languages in the same
    ///    component without the need to use different components for each script language.
    ///  </remarks>
  {$IFDEF DELPHIXE2_LVL}
  [ComponentPlatformsAttribute(pidWin32 or pidWin64)]
  {$ENDIF}
  TatBasicScripter = class(TatCustomScripter)
  protected
    procedure DefineInternalClasses; override;
  public
    constructor Create( AOwner:TComponent ); override;
    destructor Destroy; override;
  published
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

implementation

{TatBasicScripter}

procedure TatBasicScripter.DefineInternalClasses;
begin
  ScriptClass := TatBasicScript;
end;

constructor TatBasicScripter.Create( AOwner:TComponent );
begin
   { script classes customization }
   inherited Create(AOwner);
   LibOptions.CompiledFileExt := '.bcu';
   LibOptions.SourceFileExt := '.bsc';
   if Assigned(OnGlobalScripterCreate) then
     OnGlobalScripterCreate(Self);
end;

destructor TatBasicScripter.Destroy;
begin
   inherited;
end;

end.

