unit uUpgradeDeamonMainForm;

interface

uses
  Vcl.Forms,
  ALHttpClient,
  ALWininetHttpClient,
  AlHttpCommon,
  uRoomerHttpClient,
  Vcl.ExtCtrls,
  Data.DB,
  Data.Win.ADODB,
  Vcl.Controls,
  Vcl.ComCtrls,
  acProgressBar,
  Vcl.StdCtrls,
  sLabel,
  dxGDIPlusClasses,
  System.Classes,
  IdContext,
  IdBaseComponent,
  IdComponent,
  IdCustomTCPServer,
  IdCustomHTTPServer,
  IdHTTPServer,
  URIParser, Vcl.Menus;

type
  TfrmUpgradeDaemon = class(TForm)
    Image2: TImage;
    lblDownload: TsLabel;
    lblInstalling: TsLabel;
    lblReopening: TsLabel;
    tmStart: TTimer;
    sProgressBar1: TsProgressBar;
    lblDownloaded: TsLabel;
    lblExename: TsLabel;
    lblURL: TsLabel;
    httpServer: TIdHTTPServer;
    timeUpgradeCheck: TTimer;
    timPerformRequest: TTimer;
    PopupMenu1: TPopupMenu;
    S1: TMenuItem;
    N1: TMenuItem;
    E1: TMenuItem;
    TrayIcon1: TTrayIcon;
    procedure FormCreate(Sender: TObject);
    procedure tmStartTimer(Sender: TObject);
    procedure httpServerCommandGet(AContext: TIdContext; ARequestInfo: TIdHTTPRequestInfo; AResponseInfo: TIdHTTPResponseInfo);
    procedure timPerformRequestTimer(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure E1Click(Sender: TObject);
    procedure S1Click(Sender: TObject);
  private
    httpCLient: TRoomerHttpClient;
    activeSince : TDateTime;
    URIProcessor : TURIProcessor;
    procedure StartLabel(Label_: TsLabel);
    procedure EndLabel(Label_: TsLabel);
    function DownloadFile(const Url, filename: String): Boolean;
    procedure RemoveLanguagesFiles;
    procedure RemoveAllRoomerCaches;
    function TryCopyFile(localFilename, exeName: PWideChar): Boolean;
    procedure DownloadProgress(Sender: TObject; Read, Total: Integer);
    procedure PerformDownloadOfUpdate;
    procedure NullifyScreen;
    procedure UpdateNow;
  public
    { Public declarations }
  end;

var
  frmUpgradeDaemon: TfrmUpgradeDaemon;

implementation

{$R *.dfm}

uses
  Winapi.Windows,
  System.SysUtils,
  Vcl.Graphics,
  IOUtils,
  Vcl.Dialogs,
  Types,
  ShellAPI,
  uStringUtils,
  uFileSystemUtils,
  UITypes,
  uDateUtils
  ;

const

  ROOMER_EXE_URI = 'Roomer.exe';
  ROOMER_XML_URI = 'Roomer.xml';

  _K = 1024; // byte
  _B = 1; // byte
  _KB = _K * _B; // kilobyte
  _MB = _K * _KB; // megabyte
  _GB = _K * _MB; // gigabyte

function FormatByteSize(const bytes: Longword): string;
begin

  if bytes > _GB then
    result := FormatFloat('#.## GB', bytes / _GB)
  else if bytes > _MB then
    result := FormatFloat('#.## MB', bytes / _MB)
  else if bytes > _KB then
    result := FormatFloat('#.## KB', bytes / _KB)
  else
    result := FormatFloat('#.## Bytes', bytes);
end;

procedure TfrmUpgradeDaemon.FormCreate(Sender: TObject);
begin
  URIProcessor := TURIProcessor.Create;
  httpCLient := TRoomerHttpClient.Create(Self);

  with httpCLient do
  begin
    ConnectTimeout := 900;
    SendTimeout := 900;
    ReceiveTimeout := 900;
    OnDownloadProgress := DownloadProgress;
    InternetOptions := [wHttpIo_Ignore_cert_cn_invalid, wHttpIo_Ignore_cert_date_invalid, wHttpIo_Keep_connection,
      wHttpIo_Need_file, wHttpIo_No_cache_write, wHttpIo_Pragma_nocache, wHttpIo_Reload];
  end;

  activeSince := Now;
end;

procedure TfrmUpgradeDaemon.FormDestroy(Sender: TObject);
begin
  URIProcessor.Free;
end;

procedure TfrmUpgradeDaemon.httpServerCommandGet(AContext: TIdContext; ARequestInfo: TIdHTTPRequestInfo; AResponseInfo: TIdHTTPResponseInfo);
begin
  if URIProcessor.Process(ARequestInfo.URI) then
  begin
    timPerformRequest.Enabled := False;
    AResponseInfo.ContentText := URIProcessor.ProcessResult;
    timPerformRequest.Interval := 200;
    timPerformRequest.Tag := ORD(URIProcessor.ActionType);
    timPerformRequest.Enabled := True;
  end;
end;

procedure TfrmUpgradeDaemon.S1Click(Sender: TObject);
begin
  if Visible then
    Hide
  else
    Show;
end;

procedure TfrmUpgradeDaemon.StartLabel(Label_: TsLabel);
begin
  Label_.Font.Color := clWhite;
  Label_.Font.Style := [fsBold];
  Label_.Update;
end;

procedure TfrmUpgradeDaemon.timPerformRequestTimer(Sender: TObject);
var URIActionType : TURIActionType;
begin
  timPerformRequest.Enabled := False;
  URIActionType := TURIActionType(timPerformRequest.Tag);
  case URIActionType of
    atCheckForUpgrade : begin
                          //
                           PerformDownloadOfUpdate;
                        end;
    atUpdateNow : begin
                          //
                           Sleep(5000);
                           UpdateNow;
                  end;
  end;
end;

procedure TfrmUpgradeDaemon.tmStartTimer(Sender: TObject);
begin
  tmStart.Enabled := false;
end;

procedure TfrmUpgradeDaemon.DownloadProgress(Sender: TObject; Read, Total: Integer);
var
  value: Extended;
begin
  // lblDownloaded.Caption := FormatFloat('0',Read) + ' bytes';
  if Total < 1 then
    Total := 57 * _MB;
  if sProgressBar1.Max <> Total then
  begin
    sProgressBar1.Max := Total;
    sProgressBar1.Tag := 0;
  end;
  sProgressBar1.Position := Read;
  value := 100 * (Read / Total);
  if value > 100 then
    value := 100;
  lblDownloaded.Caption := FormatFloat('0.00', value) + '% of ~' + FormatByteSize(Total);
  lblDownloaded.Update;
  sProgressBar1.Update;
  sProgressBar1.Tag := sProgressBar1.Tag + 1;
  if sProgressBar1.Tag >= 20 then
  begin
    Application.ProcessMessages;
    sProgressBar1.Tag := 0;
  end;
end;

procedure TfrmUpgradeDaemon.E1Click(Sender: TObject);
begin
  Close;
end;

procedure TfrmUpgradeDaemon.EndLabel(Label_: TsLabel);
begin
  Label_.Font.Color := clGray;
  Label_.Font.Style := [fsStrikeOut];
  Label_.Update;
end;

function TfrmUpgradeDaemon.DownloadFile(const Url, filename: String): Boolean;
var
  stream: TFileStream;
  aResponseContentHeader: TALHTTPResponseHeader;
begin
  lblURL.Caption := Url;
  aResponseContentHeader := TALHTTPResponseHeader.Create;
  stream := TFileStream.Create(filename, fmCreate);
  try
    try
      httpCLient.Get(AnsiString(Url), stream, aResponseContentHeader);
      result := true;
    except
      result := false;
    end;
  finally
    stream.Free;
    aResponseContentHeader.Free;
  end;
end;

procedure TfrmUpgradeDaemon.RemoveAllRoomerCaches;
var
  files: TStringDynArray;
  i: Integer;
begin
  try
    files := TDirectory.GetFiles(RoomerAppDataPath + '\', '*.src', TSearchOption.soAllDirectories);
    for i := LOW(files) to HIGH(files) do
      DeleteFile(files[i]);
  except
    // Ignore - Not a vital problem
  end;
end;

procedure TfrmUpgradeDaemon.RemoveLanguagesFiles;
var
  path: String;
begin
  try
    path := TPath.Combine(RoomerAppDataPath, 'Languages');
    forceDirectories(path);
    DeleteAllFiles(TPath.Combine(path, 'RoomerLanguage*.src'));
  except
    // Ignore - Not a vital problem
  end;
end;

function TfrmUpgradeDaemon.TryCopyFile(localFilename, exeName: PWideChar): Boolean;
begin
  result := false;
  while true do
  begin
    try
      if CopyFile(localFilename, exeName, false) then
      begin
        result := true;
        Break;
      end
      else
        RaiseLastOSError;

    except on E: Exception do
      if MessageDlg('Unable to upgrade Roomer executable' + #13 +
        'at ' + exeName + #13#13 +
        'Error: ' + E.Message + #13#13 +
        '[Retry] = Try to automatically close Roomer and retry the upgrade.' + #13 +
        '[Cancel] = Cancel the upgrade for now.', mtConfirmation, [mbRetry, mbCancel], 0) = mrCancel then
      begin
        result := false;
        Break;
      end;
    end;
    KillTask(ExtractFilename(exeName));
    sleep(2000);
  end;
end;

//procedure TfrmUpgradeAgent.PerformUpdate;
//var
//  exeName: String;
//  localFilename: PWideChar;
//  tempFile: String;
//begin
//  exeName := TUpgraderCmdlineOptions.exeName;
//
//  lblExename.Caption := exeName;
//  StartLabel(Label1);
//  try
//    tempFile := TPath.GetTempFileName;
//    DeleteFile(tempFile);
//    if DownloadFile(TUpgraderCmdlineOptions.RoomerStoreURL + ROOMER_EXE_URI, tempFile) then
//    begin
//      if not TUpgraderCmdlineOptions.SkipClearLanguages then
//        RemoveLanguagesFiles;
//      if not TUpgraderCmdlineOptions.SkipClearCache then
//        RemoveAllRoomerCaches;
//
//      lblDownloaded.Hide;
//      lblDownloaded.Update;
//
//      EndLabel(Label1);
//
//      StartLabel(Label2);
//      sleep(2000);
//      DeleteFile(exeName);
//      localFilename := PWideChar(tempFile);
//      if NOT TryCopyFile(localFilename, PChar(exeName)) then
//      begin
//        if FileExists(tempFile) then
//          DeleteFile(tempFile);
//        Close;
//        exit;
//      end;
//      DeleteFile(localFilename);
//      EndLabel(Label2);
//
//      StartLabel(Label3);
//      ShellExecute(Handle, 'open', PChar(exeName), nil, nil, SW_SHOWNORMAL);
//      EndLabel(Label3);
//    end;
//  except
//    On E: Exception do
//    begin
//{$IFDEF DEBUG}
//      ShowMessage('Error: ' + E.Message);
//{$ENDIF}
//    end;
//  end;
//
//  Close;
//end;

procedure TfrmUpgradeDaemon.UpdateNow;
var
  exeName: String;
  UpgradeFilename: PWideChar;
  tempFile: String;
begin
  if (NOT URIProcessor.FUpgradeFileManager.UpgradeFinished) AND
     (URIProcessor.FUpgradeFileManager.UpgradeMD5 <> '') then
  begin
    try
        if URIProcessor.ClearLanguage then
          RemoveLanguagesFiles;
        if URIProcessor.ClearCache then
          RemoveAllRoomerCaches;

        exeName := URIProcessor.FileExePath;
        DeleteFile(exeName);
        UpgradeFilename := PWideChar(URIProcessor.UpgradeExePathName);
        if NOT TryCopyFile(UpgradeFilename, PChar(exeName)) then
          exit;
        TouchFile(exeName, URIProcessor.UpgradeFileManager.UpgradeTimeStamp);
        URIProcessor.UpgradeFileManager.Upgraded(URIProcessor.FileExeName,
              URIProcessor.UpgradeFileManager.UpgradeTimeStamp,
              URIProcessor.UpgradeFileManager.UpgradeTTL_Minutes,
              URIProcessor.UpgradeFileManager.UpgradeMD5,
              URIProcessor.UpgradeFileManager.UpgradeVersion);
        ShellExecute(Handle, 'open', PChar(exeName), nil, nil, SW_SHOWNORMAL);
    except
      On E: Exception do
      begin
{$IFDEF DEBUG}
        ShowMessage('Error: ' + E.Message);
{$ENDIF}
      end;
    end;
  end;
end;


procedure TfrmUpgradeDaemon.NullifyScreen;
begin
  sProgressBar1.Position := 0;
  StartLabel(lblDownload);
  lblDownloaded.Show;
  lblDownloaded.Caption := '';
end;

procedure TfrmUpgradeDaemon.PerformDownloadOfUpdate;
var
  exeName: String;
  localFilename: PWideChar;
  tempFileXML: String;
  tempFileEXE: String;

  aVersion,
  serverMD5: string;
  ttl : Integer;
  timeStamp : TDateTime;
  MD5OfDownloadedFile : String;
begin
  exeName := URIProcessor.FileExeName;

  lblExename.Caption := exeName;
  StartLabel(lblDownload);
  try
   // 1. Get the XML file with the version info of thge Roomer executables...
    tempFileXML := TPath.GetTempFileName;
    DeleteFile(tempFileXML);
    try
      if DownloadFile(URIProcessor.RoomerStore + ROOMER_XML_URI, tempFileXML) then
      begin
        URIProcessor.RoomerUpgradeFileDependencymanager.FileVersionOnServer(tempFileXML,
              URIProcessor.FileExeName,
              aVersion,
              serverMD5,
              ttl,
              timeStamp);

       // 2. Check if the currently downloaded version is the same as on server...
        if (aVersion <> URIProcessor.FUpgradeFileManager.UpgradeVersion) OR
           (serverMD5 <> URIProcessor.FUpgradeFileManager.UpgradeMD5) OR
           (uDateUtils.dateTimeToXmlString(timeStamp) <> uDateUtils.dateTimeToXmlString(URIProcessor.FUpgradeFileManager.UpgradeTimeStamp)) OR
           (ttl <> URIProcessor.FUpgradeFileManager.UpgradeTTL_Minutes) then
        begin
         // 3. A new version is available on server.
         //    Download the release...
          tempFileEXE := TPath.GetTempFileName;
          DeleteFile(tempFileEXE);
          try
            if DownloadFile(URIProcessor.RoomerStore + URIProcessor.FileExeName, tempFileEXE) then
            begin
              lblDownloaded.Hide;
              lblDownloaded.Update;

              EndLabel(lblDownload);

              StartLabel(lblInstalling);


             // 4. And make it available in the local upgrades store
              MD5OfDownloadedFile := FileMD5(tempFileEXE);
              if MD5OfDownloadedFile = serverMD5 then
              begin
                URIProcessor.FUpgradeFileManager.NewUpgrade(tempFileEXE, URIProcessor.FileExeName, timeStamp, ttl, serverMD5, aVersion);

                EndLabel(lblInstalling);

                StartLabel(lblReopening);
                EndLabel(lblReopening);
              end;
            end;
          finally
            if FileExists(tempFileEXE) then
              DeleteFile(tempFileEXE);
          end;
        end;
      end;
    finally
      if FileExists(tempFileXML) then
        DeleteFile(tempFileXML);
    end;
  except
    On E: Exception do
    begin
{$IFDEF DEBUG}
      ShowMessage('Error: ' + E.Message);
{$ENDIF}
    end;
  end;

  NullifyScreen;
end;

end.
