unit FMX.ScripterMachine;

interface
uses
  SysUtils, Classes,
  {$IFDEF MACOS}
    {$IFDEF IOS}
    {$ELSE}
    Macapi.Foundation,
    Macapi.AppKit,
    {$ENDIF}
  {$ENDIF}
  FMX.Forms, FMX.Dialogs,
  atScript;

type
  TScripterMachine = class(TatVirtualMachine)
  private
    FOldOnException: TExceptionEvent;
    FHooking: integer;
    FExceptionRaised: Exception;
    {$IFDEF MACOS}
    {$IFNDEF IOS}
    FNSApp: NSApplication;
    {$ENDIF}
    {$ENDIF}
    procedure AppException(Sender: TObject; E: Exception);
    procedure ProcessApplicationMessage;
    {$IFDEF MSWINDOWS}
    function ProcessWindowsMessage: boolean;
    {$ENDIF}
    {$IFDEF MACOS}
    {$IFNDEF IOS}
    function ProcessMacOSMessage(ATimeoutSec: Longword = 0): boolean;
    {$ENDIF}
    {$ENDIF}
  protected
    procedure PerformShowMessage(const Msg: string); override;
    function PerformInputQuery(const ACaption, APrompt: string; var Value: string): Boolean; override;
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
  {$IFDEF MACOS}
  {$IFNDEF IOS}
  FNSApp := TNSApplication.Wrap(TNSApplication.OCClass.sharedApplication);
  {$ENDIF}
  {$ENDIF}
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
         if TThread.CurrentThread.ThreadId = MainThreadID then
           ProcessApplicationMessage;
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

procedure TScripterMachine.PerformShowMessage(const Msg: string);
begin
  ShowMessage(Msg);
end;

procedure TScripterMachine.ProcessApplicationMessage;
begin
  {$IFDEF MSWINDOWS}
  ProcessWindowsMessage;
  {$ENDIF}
  {$IFDEF MACOS}
    {$IFDEF IOS}
    Application.HandleMessage;
    {$ELSE}
    ProcessMacOSMessage;
    {$ENDIF}
  {$ENDIF}
  {$IFDEF ANDROID}
  Application.HandleMessage;
  {$ENDIF}
end;

{$IFDEF MSWINDOWS}
function TScripterMachine.ProcessWindowsMessage: boolean;
begin
  result := Application.HandleMessage;
end;
{$ENDIF}

{$IFDEF MACOS}
{$IFNDEF IOS}
function TScripterMachine.ProcessMacOSMessage(ATimeoutSec: Longword = 0): boolean;
var
  TimeoutDate: NSDate;
  NSEvt: NSEvent;
  Done: boolean;
begin
  if ATimeoutSec = 0 then
    TimeoutDate := TNSDate.Wrap(TNSDate.OCClass.dateWithTimeIntervalSinceNow(0.1))
  else
    TimeoutDate := TNSDate.Wrap(TNSDate.OCClass.dateWithTimeIntervalSinceNow(ATimeOutSec));
  NSEvt := FNSApp.nextEventMatchingMask(NSAnyEventMask, TimeoutDate, NSDefaultRunLoopMode, True);
  Result := NSEvt <> nil;
  if Result then
    FNSApp.sendEvent(NSEvt)
  else
  begin
    // Idle
    Done := false;
    Application.DoIdle(Done);
  end;
end;
{$ENDIF}
{$ENDIF}

end.

