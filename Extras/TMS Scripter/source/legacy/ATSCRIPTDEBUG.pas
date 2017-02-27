unit atScriptDebug;

{$I ASCRIPT.INC}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  atScriptDebugForm, atScript, atPascal, atBasic;


type
  ///  <summary>
  ///    Used to display a script debugger modal dialog.
  ///  </summary>
  ///  <remarks>
  ///    TatScripterDebugger encapsulates a dialog for script debugging. You can use this component to quickly
  ///    associate a scripter to it and call Execute method to open a debug window and perform debug operations in the script.
  ///    In the Pro version of Scripter Studio, this component is deprecated, since all debug operations can be performed
  ///    in the Scripter Studio IDE
  ///  </remarks>
  {$IFDEF DELPHIXE2_LVL}
  [ComponentPlatformsAttribute(pidWin32 or pidWin64)]
  {$ENDIF}
  TatScriptDebugger = class(TComponent)
  private
    FScripter: TatCustomScripter;
    FUpdateSourceCode: boolean;
    FRoutineName: string;
    FMemoReadOnly: boolean;
  protected
    procedure Notification(AComponent: TComponent; AOperation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    
    ///  <summary>
    ///    Opens the debug dialog window for debugging purposes.
    ///  </summary>
    ///  <remarks>
    ///    Execute method opens the dialog window for debugging. The source code is retrieved from the scripter component
    ///    indicated in Scripter property. The dialog is displayed in modal form. 
    ///  </remarks>
    procedure Execute;
  published
    ///  <summary>
    ///    Points to the scripter component containing the source code to be debugged.
    ///  </summary>
    property Scripter: TatCustomScripter read FScripter write FScripter;
    
    ///  <summary>
    ///    Indicates the name of the routine to be debugged in debugger. If RoutineName is empty (default), the main block
    ///    of the script will be debugged
    ///  </summary>
    property RoutineName: string read FRoutineName write FRoutineName;
    
    ///  <summary>
    ///    If UpdateSourceCode is true, changes to the source code made by the end-user will be applied to the script source code.
    ///    If this property is false (default), then any changes to source code made in debug window will be discarded.
    ///  </summary>
    property UpdateSourceCode: boolean read FUpdateSourceCode write FUpdateSourceCode;
    
    ///  <summary>
    ///    Indicates if the memo editor in debug window will be read-only or not.
    ///  </summary>
    property MemoReadOnly: boolean read FMemoReadOnly write FMemoReadOnly;
  end;

implementation

{ TScriptDebugger }

constructor TatScriptDebugger.Create(AOwner: TComponent);
begin
  inherited;
  FUpdateSourceCode := true;
  FRoutineName := '';
  FMemoReadOnly := false;
end;

procedure TatScriptDebugger.Execute;
var
  ADebugForm: TDebugForm;
begin
  if not Assigned(Scripter) then
    raise Exception.Create('No scripter engine assigned');

  ADebugForm := TDebugForm.Create(Application);
  ADebugForm.Position := poScreenCenter;
  ADebugForm.RoutineToRun := FRoutineName;
  ADebugForm.AdvMemo1.ReadOnly := FMemoReadOnly;
  ADebugForm.Scripter := Scripter;
  if not Scripter.Running then
  begin
    ADebugForm.ShowModal;
    if FUpdateSourceCode then
      Scripter.SourceCode.Assign(ADebugForm.AdvMemo1.Lines);
  end else
  begin
    ADebugForm.Show;
    Scripter.Paused := true;
  end;
end;

procedure TatScriptDebugger.Notification(AComponent: TComponent;
  AOperation: TOperation);
begin
  inherited;
  if (AOperation = opRemove) and (AComponent = Scripter) then
    Scripter := nil;
end;

end.
