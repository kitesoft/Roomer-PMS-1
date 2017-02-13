unit RoomerExceptionHandling;

interface

uses
  SysUtils
  ;

type
  TRoomerExceptionHandler = class(TObject)
  private
    FExceptionsLoggingActive: boolean;
    FExceptionLogPath: string;
    FLogFileName: string;
    procedure SetExceptionLogPath(const Value: string);
    function GetFullLogFilePath: string;

  public

    constructor Create(const aLogFileName: string = '');
    destructor Destroy; override;
    function AppendToLogfile(const line : string; addDate : boolean = false) : boolean;

    {$IFDEF USE_JCL}
    procedure LogException(ExceptObj: TObject; ExceptAddr: Pointer; IsOS: boolean);
    {$ENDIF}
    procedure ExceptionHandler(Sender: TObject; E: Exception);

    property ExceptionsLoggingActive: boolean read FExceptionsLoggingActive write FExceptionsLoggingActive;
    property ExceptionLogPath: string read FExceptionLogPath write SetExceptionLogPath;
    property ExceptionLogFilename: string read FLogFileName write FLogFileName;
    property FullLogfilePath: string read GetFullLogFilePath;
  end;


implementation

uses
    Classes
    , uRoomerExceptions
{$IFDEF USE_JCL}
    , JclDebug, JclHookExcept, TypInfo
{$ENDIF}
    , uSplashRoomer
    , VCL.Forms
    , IOUtils
    , uUtils
    ;

{$IFDEF USE_JCL}

procedure TRoomerExceptionHandler.LogException(ExceptObj: TObject; ExceptAddr: Pointer; IsOS: boolean);
var
  TmpS: string;
  ModInfo: TJclLocationInfo;
  i: integer;
  ExceptionHandled: boolean;
  HandlerLocation: Pointer;
  ExceptFrame: TJclExceptFrame;

begin
  if ExceptionsLoggingActive then
  begin
    TmpS := 'Exception ' + ExceptObj.ClassName;
    if ExceptObj is Exception then
      TmpS := TmpS + ': ' + Exception(ExceptObj).message;
    if IsOS then
      TmpS := TmpS + ' (OS Exception)';
    _textAppend(ExceptionLogPath, TmpS, true);
    ModInfo := GetLocationInfo(ExceptAddr);
    _textAppend(ExceptionLogPath, Format('  Exception occured at $%p (Module "%s", Procedure "%s", Unit "%s", Line %d)',
      [ModInfo.Address, ModInfo.UnitName, ModInfo.ProcedureName, ModInfo.SourceName, ModInfo.LineNumber]), true);
    if stExceptFrame in JclStackTrackingOptions then
    begin
      _textAppend(ExceptionLogPath, '  Except frame-dump:', true);
      i := 0;
      ExceptionHandled := false;
      while ( { chkShowAllFrames.Checked or } not ExceptionHandled) and (i < JclLastExceptFrameList.Count) do
      begin
        ExceptFrame := JclLastExceptFrameList.Items[i];
        ExceptionHandled := ExceptFrame.HandlerInfo(ExceptObj, HandlerLocation);
        if (ExceptFrame.FrameKind = efkFinally) or (ExceptFrame.FrameKind = efkUnknown) or not ExceptionHandled then
          HandlerLocation := ExceptFrame.CodeLocation;
        ModInfo := GetLocationInfo(HandlerLocation);
        TmpS := Format('    Frame at $%p (type: %s', [ExceptFrame.FrameLocation, GetEnumName(TypeInfo(TExceptFrameKind),
          Ord(ExceptFrame.FrameKind))]);
        if ExceptionHandled then
          TmpS := TmpS + ', handles exception)'
        else
          TmpS := TmpS + ')';
        _textAppend(ExceptionLogPath, TmpS, true);
        if ExceptionHandled then
          _textAppend(ExceptionLogPath, Format('      Handler at $%p', [HandlerLocation]), true)
        else
          _textAppend(ExceptionLogPath, Format('      Code at $%p', [HandlerLocation]), true);
        _textAppend(ExceptionLogPath, Format('      Module "%s", Procedure "%s", Unit "%s", Line %d',
          [ModInfo.UnitName, ModInfo.ProcedureName,
          ModInfo.SourceName, ModInfo.LineNumber]), true);
        inc(i);
      end;
    end;
    _textAppend(ExceptionLogPath, '', true);
  end;
end;
{$ENDIF}


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

{$IFDEF USE_JCL}
  JclAddExceptNotifier(LogException);
{$ENDIF}

end;

destructor TRoomerExceptionHandler.Destroy;
begin
{$IFDEF USE_JCL}
  try
    JclRemoveExceptNotifier(LogException);
  except
  end;
{$ENDIF}

  inherited;
end;

function TRoomerExceptionHandler.AppendToLogfile(const line : string; addDate : boolean = false) : boolean;
var aTextFile : TextFile;
    lFile: TFileStream;
    aText : String;
begin
  result := true;
  try
    aText := line;
    if addDate then
      aText := format('%s %s | %s', [FormatDateTime('yyyy-mm-dd', now),
                                     FormatDateTime('hh:nn:ss', now),
                                     aText]);

    TFile.AppendAllText(FullLogfilePath, aText + #10#13);
  except
    result := false;
  end;
end;


procedure TRoomerExceptionHandler.ExceptionHandler(Sender: TObject; E: Exception);
begin
  try
    TSplashFormManager.TryHideForm;
  except
  end;
  // --
  if (E is EDivByZero) or (E is ERangeError) or (E is ERoomerOfflineAssertionException) or
    (E is EInvalidPointer) or
  // ( E is EOverflow          ) or
  // ( E is EUnderflow         ) or
    (E is EInvalidOp) or (E is EAbstractError) or (E is EIntOverflow) or (E is EAccessViolation) or (E is EControlC) or
    (E is EPrivilege) or (E is EInvalidCast)
    or (E is EVariantError) or (E is EAssertionFailed) or (E is EIntfCastError) or
    (pos('out of bounds', ANSIlowercase(E.message)) > 0) then
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

initialization
{$IFDEF USE_JCL}
  JclStackTrackingOptions := JclStackTrackingOptions + [stExceptFrame];
  JclStartExceptionTracking;
{$ENDIF}


end.
