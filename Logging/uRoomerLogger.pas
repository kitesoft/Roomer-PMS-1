unit uRoomerLogger;

interface

uses uDateUtils,
     Classes,
     System.Generics.Collections
     ;

type

  TRoomerLogger = class
  private
    FFilename: String;
    LogWriter : TStreamWriter;
    procedure OpenStream;
    procedure CloseStream;
  public
    constructor Create(filename : String);
    destructor Destroy;

    procedure AddToLog(sText : String);

    property filename : String read FFilename;
  end;

function ActivateRoomerLogger(sUnit : String) : TRoomerLogger;
procedure DeactivateRoomerLogger(var Logger : TRoomerLogger);

implementation

uses
  uFileSystemUtils,
  IOUtils,
  SysUtils
  ;

var Loggers : TObjectList<TRoomerLogger>;

const DEFAULT_LOG_FILENAME_FORMAT = 'ROOMER_LOGS_%s.log';

function ActivateRoomerLogger(sUnit : String) : TRoomerLogger;
begin
  result := TRoomerLogger.Create(TPath.Combine(uFileSystemUtils.RoomerLogPath, format(DEFAULT_LOG_FILENAME_FORMAT, [sUnit])));
end;

procedure DeactivateRoomerLogger(var Logger : TRoomerLogger);
begin
  Loggers.Remove(Logger);
  Logger.Free;
  Logger := nil;
end;

{ TRoomerLogger }

procedure TRoomerLogger.AddToLog(sText: String);
begin
  OpenStream;
  try
    LogWriter.WriteLine(format('%s | %s', [uDateUtils.DateTimeToDBString(now), sText]));
  finally
    CloseStream;
  end;
end;

constructor TRoomerLogger.Create(filename: String);
begin
  FFilename := filename;
  OpenStream;
  try
    LogWriter.WriteLine;
  finally
    CloseStream;
  end;
  Loggers.Add(self);
end;

destructor TRoomerLogger.Destroy;
begin
end;

procedure TRoomerLogger.CloseStream;
begin
  LogWriter.Free;
end;

procedure TRoomerLogger.OpenStream;
begin
  LogWriter := TStreamWriter.Create(FileName, True);
  LogWriter.AutoFlush := True;         // Flush automatically after write
  LogWriter.NewLine := sLineBreak;     // Use system line breaks
end;

initialization
  Loggers := TObjectList<TRoomerLogger>.Create;

finalization
begin
  try Loggers.Free; except end;
end;

end.
