unit uRoomerLogger;

interface

uses uDateUtils,
     Classes,
     System.Generics.Collections
     ;

type

  //TODO Adapt RoomerExceptionHandler to make use of this roomerlogger

  /// <summary>
  ///   Class to log messages to a file.
  ///  On creation the logger is registered with a global logger list, who owns the object
  /// </summary>
  TRoomerLogger = class
  private
    FFilename: String;
    LogWriter : TStreamWriter;
    procedure OpenStream;
    procedure CloseStream;
  public
    constructor Create(const filename : String);
    procedure AddToLog(const sText : String);
    property Filename : String read FFilename;
  end;

/// <summary>
///   Create and register a logger, logging to a file with the supplied postfix
/// </summary>
function ActivateRoomerLogger(const sUnit : String) : TRoomerLogger;
/// <summary>
///   Remove (and subsequently free) logger from global list. Logger variable will be set to nil
/// </summary>
procedure DeactivateRoomerLogger(var Logger : TRoomerLogger);

implementation

uses
  uFileSystemUtils,
  IOUtils,
  SysUtils
  ;

var Loggers : TObjectList<TRoomerLogger>;

const DEFAULT_LOG_FILENAME_FORMAT = 'ROOMER_LOGS_%s.log';

function ActivateRoomerLogger(const sUnit : String) : TRoomerLogger;
begin
  // Constructor includes registering the logger wih the Logger ObjectList
  result := TRoomerLogger.Create(TPath.Combine(uFileSystemUtils.RoomerLogPath, format(DEFAULT_LOG_FILENAME_FORMAT, [sUnit])));
end;

procedure DeactivateRoomerLogger(var Logger : TRoomerLogger);
begin
  Loggers.Remove(Logger);
  // Logger objectlist own objects, so it will free the object when removed from list
  Logger := nil;
end;

{ TRoomerLogger }

procedure TRoomerLogger.AddToLog(const sText: String);
begin
  OpenStream;
  try
    LogWriter.WriteLine(format('%s | %s', [uDateUtils.DateTimeToDBString(now), sText]));
  finally
    CloseStream;
  end;
end;

constructor TRoomerLogger.Create(const filename: String);
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
