unit Vcl.ScripterMachine;

{$I AScript.Inc}

interface
uses
  SysUtils, Classes, Windows,
  {$IFDEF DELPHIXE2_LVL}
  VCL.Forms, VCL.Dialogs,
  {$ELSE}
  Forms, Dialogs,
  {$ENDIF}
  atScript;

type
  TScripterMachine = class(TatVirtualMachine)
  private
    FOldOnException: TExceptionEvent;
    FHooking: integer;
    FExceptionRaised: Exception;
    procedure AppException(Sender: TObject; E: Exception);
  protected
    procedure PerformShowMessage(const Msg: string); override;
    function PerformInputQuery(const ACaption, APrompt: string; var Value: string): Boolean; override;
    function PerformMessageBox(AText: string; AType: integer = -1; ACaption: string = ''): integer; override;
    procedure DoDebugHook; override;
  public
    constructor Create(ACollection: TCollection); override;
    destructor Destroy; override;
  end;

implementation

{ TScripterMachine }

procedure TScripterMachine.AppException(Sender: TObject; E: Exception);
begin
  FExceptionRaised := ExceptClass(E.ClassType).CreateHelp(E.Message, E.HelpContext);
end;

constructor TScripterMachine.Create(ACollection: TCollection);
begin
  inherited;
  FOldOnException := nil;
  FHooking := 0;
  FExceptionRaised := nil;
end;

destructor TScripterMachine.Destroy;
begin
  inherited;
end;

procedure TScripterMachine.DoDebugHook;
begin
  { Allow an user callback to implement things while script is being debugged }
  Inc(FHooking);
  if FHooking = 1 then
  begin
    FOldOnException := Application.OnException;
    Application.OnException := AppException;
  end;
  try
    ScripterSingleDebugHook;
    repeat
       if not ScripterDoDebugHook then
       begin
         if GetCurrentThreadID = MainThreadID then
           Application.HandleMessage;
       end;
    until not Paused or (NextInstruction=nil) or (NextInstruction = StopInstruction) or
      (FExceptionRaised <> nil);
    if FExceptionRaised <> nil then
    try
      raise FExceptionRaised;
    finally
      FExceptionRaised := nil;
    end;
  finally
    Dec(FHooking);
    if FHooking = 0 then
    begin
      Application.OnException := FOldOnException;
    end;
  end;
end;

function TScripterMachine.PerformInputQuery(const ACaption, APrompt: string;
  var Value: string): Boolean;
begin
  Result := InputQuery(ACaption, APrompt, Value);
end;

function TScripterMachine.PerformMessageBox(AText: string; AType: integer = -1;
  ACaption: string = ''): integer;
begin
  {$IFDEF MSWINDOWS}
  if ACaption = '' then
    ACaption := Application.Title;
  if AType=  -1 then
    AType := 0; //vbOKOnly
  Result := Windows.MessageBox(Application.Handle, PChar(AText), PChar(ACaption), AType);
  {$ELSE}
  Result := 0;
  showMessage(AText);
  {$ENDIF}
end;

procedure TScripterMachine.PerformShowMessage(const Msg: string);
begin
  ShowMessage(Msg);
end;

end.
