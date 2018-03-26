unit RoomerExceptionHandling;

interface

uses
  SysUtils
  ;

type
  ERoomerException = class(Exception)
  public
    /// <summary>
    ///   If set to false, the exception will only be logged (if logging is active) and the user will not be
    ///  notified.
    /// </summary>
    function ShowToUSer: boolean; virtual;
  end;

  ERoomerUserException = class(ERoomerException)
  public
    function ShowToUSer: boolean; override;
  end;

  TRoomerExceptionHandler = class(TObject)
  private
    FExceptionsLoggingActive: boolean;
    FExceptionLogPath: string;
    FLogFileName: string;
    FLogStackTrace: boolean;
    procedure SetExceptionLogPath(const Value: string);
    function GetFullLogFilePath: string;
    procedure LogStackTrace(ExceptObj: TObject; ExceptAddr: Pointer; IsOS: boolean);
    function AppendToLogfile(const line : string; addDate : boolean = false) : boolean;

  public
    constructor Create(const aLogFileName: string = '');

    /// <summary>
    ///   Eventhandler for Application.OnException
    /// </summary>
    procedure ExceptionHandler(Sender: TObject; E: Exception);

    property ExceptionsLoggingActive: boolean read FExceptionsLoggingActive write FExceptionsLoggingActive;
    property ExceptionLogPath: string read FExceptionLogPath write SetExceptionLogPath;
    property ExceptionLogFilename: string read FLogFileName write FLogFileName;
    property FullLogfilePath: string read GetFullLogFilePath;
    property LogStackTraceOnException: boolean read FLogStackTrace write FLogStackTrace;
  end;


implementation

uses
    Classes
    , uRoomerExceptions
    , JclDebug, JclHookExcept, TypInfo
//    , uSplashRoomer
    , VCL.Forms
    , IOUtils
    , uUtils
    , Windows
    ;

procedure TRoomerExceptionHandler.LogStackTrace(ExceptObj: TObject; ExceptAddr: Pointer; IsOS: boolean);
var
  TmpS: string;
  ModInfo: TJclLocationInfo;
  StackTrace: TStringlist;
begin
  if ExceptionsLoggingActive then
  begin
    AppendToLogFile('--------------------------------------------------------------------------------------------', true);
    TmpS := ExceptObj.ClassName +  ' occurred';
    if ExceptObj is Exception then
      TmpS := TmpS + ': ' + Exception(ExceptObj).message;
    if IsOS then
      TmpS := TmpS + ' (OS Exception)';
    AppendToLogfile(TmpS, true);
    ModInfo := GetLocationInfo(ExceptAddr);
    AppendToLogfile(Format('  Exception occured at $%p (Module "%s", Procedure "%s", Unit "%s", Line %d)',
      [ModInfo.Address, ModInfo.UnitName, ModInfo.ProcedureName, ModInfo.SourceName, ModInfo.LineNumber]), true);

    StackTrace := TStringlist.Create;
    try
      JclLastExceptStackListToStrings(StackTrace, True, False, True, True);
      for TmpS in StackTrace do
        AppendToLogfile(TmpS, true);
    finally
      StackTrace.Free;
    end;
    AppendToLogFile('--------------------------------------------------------------------------------------------', true);

  end;

end;


constructor TRoomerExceptionHandler.Create(const aLogFileName: string = '');
begin
  if not aLogFileName.IsEmpty then
  begin
    ExceptionLogPath := TPath.GetDirectoryName(aLogFileName);
    ExceptionLogFilename := TPath.GetFileName(aLogFileName);
  end
  else
  begin
    if ParameterByName('LogPath') <> '' then
      ExceptionLogPath := ParameterByName('LogPath')
    else
      ExceptionLogPath :=  TPath.GetDirectoryName(Application.ExeName);
    ExceptionLogFilename := TPath.GetFileNameWithoutExtension(Application.ExeName) + '.log';
  end;
{$IFDEF DUMP_STACKTRACE}
  FLogStackTrace := True;
{$ENDIF}
end;

function TRoomerExceptionHandler.AppendToLogfile(const line : string; addDate : boolean = false) : boolean;
var
  aText : String;
begin
  result := true;
  try
    aText := line;
    if addDate then
      aText := format('%s %s | %s', [FormatDateTime('yyyy-mm-dd', now),
                                     FormatDateTime('hh:nn:ss', now),
                                     aText]);

    TFile.AppendAllText(FullLogfilePath, '                    | ' + aText + #13#10);
    OutputDebugString(PChar(aText));
  except
    result := false;
  end;
end;


procedure TRoomerExceptionHandler.ExceptionHandler(Sender: TObject; E: Exception);
begin
  if FLogStackTrace then
    LogStackTrace(E, ExceptAddr, E is EOSError);

//  try
//    TSplashFormManager.TryHideForm;
//  except
//  end;
//
  if (E is EDivByZero) or (E is ERangeError) or (E is ERoomerOfflineAssertionException) or
    (E is EInvalidPointer) or
    (E is EInvalidOp) or (E is EAbstractError) or (E is EIntOverflow) or (E is EAccessViolation) or (E is EControlC) or
    (E is EPrivilege) or (E is EInvalidCast)
    or (E is EVariantError) or (E is EAssertionFailed) or (E is EIntfCastError) or
    (pos('out of bounds', ANSIlowercase(E.message)) > 0)  or
    (E is ERoomerException and not ERoomerException(E).SHowToUser) then
  begin
    if ExceptionsLoggingActive then
      ExceptionsLoggingActive := AppendToLogfile(E.message, true);
  end
  else
  begin
    Application.ShowException(E);
  end;
end;

function TRoomerExceptionHandler.GetFullLogFilePath: string;
begin
  Result := TPath.Combine(FExceptionLogPath, FLogFileName);
end;

procedure TRoomerExceptionHandler.SetExceptionLogPath(const Value: string);
begin
  FExceptionLogPath := Value;
  forceDirectories(ExceptionLogPath);
end;

{ ERoomerException }

function ERoomerException.ShowToUSer: boolean;
begin
  Result := false;
end;

{ ERoomerUserException }

function ERoomerUserException.ShowToUSer: boolean;
begin
  Result := true;
end;

initialization
  JclStackTrackingOptions := JclStackTrackingOptions + [stRawMode, stExceptFrame];
  JclStartExceptionTracking;


end.
