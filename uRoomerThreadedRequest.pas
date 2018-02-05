unit uRoomerThreadedRequest;

interface

{$INCLUDE roomer.inc}

uses
  Classes,
  DB,
  cmpRoomerDataSet,
  ADODB
  ;

type

  TOperationType = (OT_EXECUTE, OT_PUT, OT_POST);

  TFieldInfoRecord = Record
    // as far as sometimes parametertypes can not be detected by
    DataType: TFieldType; // Ado on his own, provide all needed informations
    Name: String;
    Size: Integer;
    Value: Variant;
  End;

  TFieldInfoArray = Array of TFieldInfoRecord;

type
  TBaseDBThread = class abstract(TThread)
  private
    FRecordSet: _RecordSet;
    FRoomerDataSet: TRoomerDataSet;
  protected
    Procedure Execute; override;
    procedure InternalExecute; virtual; abstract;
    procedure ExecuteSQL(const aCommand: string);
    procedure ExecutePUT(const aCommand, aData : string);
    procedure ExecutePOST(const aCommand, aData: string);
  public
    Property RecordSet: _RecordSet read FRecordSet;
    property Dataset: TRoomerDataset read FRoomerDataSet;
  end;

  TDBThread = Class(TBaseDBThread)
  private
    FSQL: String;
    FData: String;
    FOperationType: TOperationType;
    FFDArray: TFieldInfoArray;
  protected
    Procedure Execute; override;
    procedure InternalExecute; override;
  public
    constructor Create(Const aSQL: String; aFDArray: TFieldInfoArray); overload;
    constructor Create(Const sql, data: String; OperationType: TOperationType); overload;
  end;

  // Execute a sql statement or REST call in a separate thread, on termination of that thread the
  // result is assigned to RoomerDataset and the supplied TNotifyEvent is called.
  // This class should not be used if the sql results is not needed or POST or PUT calls are needed
  TGetSQLDataThreaded = class(TObject)
  private
    FRoomerDataSet: TRoomerDataSet;
    FEventHandler: TNotifyEvent;
    procedure ThreadTerminateAfterGet(Sender: TObject);
    procedure Cancel;
  protected
    dbThread : TDBThread;
  public
    constructor Create;
    destructor Destroy; override;

    // Execute SQL statement, on completion the result is in Dataset
    procedure Execute(const sql: String; aOnCompletionHandler: TNotifyEvent);
    property RoomerDataSet: TRoomerDataSet read FRoomerDataSet;
  end;

  // Execute a POST or PUT REST call in a separate thread, on termination of that thread the
  // OnCompletion event is executed. If no CompletionEvent is provided then the thread is terminated and the result is discarded
  TPutOrPostDataThreaded = class(TObject)
  private
    FEventHandler: TNotifyEvent;
    procedure Cancel;
    procedure ThreadTerminateAfterPost(Sender: TObject);
  protected
    dbThread : TDBThread;
  public
    constructor Create;
    destructor Destroy; override;

    // Execute REST Call
    procedure Put(const url, data: String; aOnCompletionHandler: TNotifyEvent);
    procedure Post(const url, data: String; aOnCompletionHandler: TNotifyEvent);
  end;

implementation

uses
  Windows,
  ActiveX,
  uD,
  SysUtils,
  TypInfo,
  Dialogs,
  UITypes;


procedure TGetSQLDataThreaded.Cancel;
begin
//  try
//    if assigned(dbThread) then
//      With dbThread do
//      begin
//        FreeOnTerminate := true;
//        OnTerminate := nil;
//        Terminate;
//      end;
//    dbThread := nil;
//  except end;
end;

procedure TGetSQLDataThreaded.Execute(const sql: String; aOnCompletionHandler: TNotifyEvent);
begin
  FEventHandler := aOnCompletionHandler;
  dbThread := TDBThread.Create(sql, nil);
  With dbThread do
  begin
    FOperationType := OT_EXECUTE;
    FreeOnTerminate := true;
    OnTerminate := ThreadTerminateAfterGet;
    Start;
  end;
end;

procedure TGetSQLDataThreaded.ThreadTerminateAfterGet(Sender: TObject);
begin
  // Executed in MainThread!
  try
    if assigned(FROomerDataset) then
      FRoomerDataSet.RecordSet := TDBThread(Sender).RecordSet;
    if assigned(FEventHandler) then
      FEventHandler(self);
  except
  end;
end;

constructor TGetSQLDataThreaded.Create;
begin
  inherited;
{$IFDEF rmMONITOR_LEAKAGE}
  ReportMemoryLeaksOnShutDown := IsDebuggerPresent();
{$ENDIF}
  FRoomerDataSet := CreateNewDataSet;
  FRoomerDataSet.RoomerDataSet := nil;
end;

destructor TGetSQLDataThreaded.Destroy;
begin
  Cancel;
  FRoomerDataSet.Free;
  inherited;
end;

{ TDBThread }

constructor TDBThread.Create(const aSQL: String; aFDArray: TFieldInfoArray);
begin
  inherited Create(True);
  FSQL := aSQL;
  FFDArray := aFDArray;
end;

constructor TDBThread.Create(const sql, data: String; OperationType: TOperationType);
begin
  inherited Create(True);
  FSQL := sql;
  FOperationType := OperationType;
  FData := data;
end;

procedure TDBThread.Execute;
begin
  OutputDebugString(PChar(format('starting DBthread [%], Operation: [%s], sql: [%s], data: [%s]',
                              [Classname, GetEnumName(TypeInfo(TOperationType), ord(FOperationType)), FSQL, FDATA])));
  inherited;
end;

procedure TBaseDBThread.Execute;
begin
  inherited;
  CoInitialize(nil);
  try
    try
      NameThreadForDebugging(Classname);
      FRoomerDataSet := CreateNewDataSet;
      try
        FRoomerDataSet.RoomerDataSet := nil;

        InternalExecute;

      finally
        FRoomerDataSet.Free;
      end;
    except
      on E: Exception do
      begin
        {ifdef DEBUG}
        MessageDlg(Format('Exception occured when executing thread [%s]'+ #10 + ' Messsge [%s]', [classname, e.Message]), mtError, [mbOK], 0);
        {endif}
        raise;
      end;
    end;
  finally
    CoUnInitialize;
  end;
end;


procedure TDBThread.InternalExecute;
begin
  inherited;
  case FOperationType of
    OT_EXECUTE:  ExecuteSQL(FSQL);
    OT_PUT:      ExecutePut(FSQL, FData);
    OT_POST:     ExecutePost(FSQL, FData);
  end;
end;

procedure TBaseDBThread.ExecutePOST(const aCommand, aData: string);
begin
  FRoomerDataSet.PostData(aCommand, aData);
end;

procedure TBaseDBThread.ExecutePUT(const aCommand, aData: string);
begin
  FRoomerDataSet.PutData(aCommand, aData);
end;

procedure TBaseDBThread.ExecuteSQL(const aCommand: string);
begin
  FreeAndNil(FRecordSet);
  FRoomerDataSet.CommandType := cmdText;
  FRoomerDataSet.CommandText := aCommand;
  FRoomerDataSet.Open(false, false, true);
  FRecordSet := FRoomerDataSet.RecordSet; // keep recordset
end;

{ TPostThreadedData }

procedure TPutOrPostDataThreaded.Cancel;
begin

end;

constructor TPutOrPostDataThreaded.Create;
begin
  inherited;
{$IFDEF rmMONITOR_LEAKAGE}
  ReportMemoryLeaksOnShutDown := IsDebuggerPresent();
{$ENDIF}
end;

destructor TPutOrPostDataThreaded.Destroy;
begin
  Cancel;
  inherited;
end;

procedure TPutOrPostDataThreaded.Post(const url, data: String; aOnCompletionHandler: TNotifyEvent);
begin
  FEventHandler := aOnCompletionHandler;
  dbThread := TDBThread.Create(url, data, OT_POST);
  With dbThread do
  begin
    FreeOnTerminate := not Assigned(FEventHandler);
    if assigned(FEventHandler) then
      OnTerminate := ThreadTerminateAfterPost
    else
      OnTerminate := nil;
    Start;
  end;
end;

procedure TPutOrPostDataThreaded.Put(const url, data: String; aOnCompletionHandler: TNotifyEvent);
begin
  FEventHandler := aOnCompletionHandler;
  dbThread := TDBThread.Create(url, data, OT_PUT);
  With dbThread do
  begin
    FreeOnTerminate := not Assigned(FEventHandler);
    if assigned(FEventHandler) then
      OnTerminate := ThreadTerminateAfterPost
    else
      OnTerminate := nil;
    Start;
  end;

end;

procedure TPutOrPostDataThreaded.ThreadTerminateAfterPost(Sender: TObject);
begin
  if assigned(FEventHandler) then
    FEventHandler(Self);
end;

end.
