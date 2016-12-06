unit uUpgraderMainForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics, IOUtils,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, acPNG, Vcl.ExtCtrls, Vcl.StdCtrls, Data.DB, Data.Win.ADODB, cmpRoomerDataSet,
//  ALHttpClient, ALWininetHttpClient,
  sSkinProvider, sSkinManager, Vcl.ComCtrls, acProgressBar, sLabel, dxGDIPlusClasses
  , uRoomerHttpClient;

type
  TfrmUpgradeAgent = class(TForm)
    Image2: TImage;
    Label1: TsLabel;
    Label2: TsLabel;
    Label3: TsLabel;
    tmStart: TTimer;
    sProgressBar1: TsProgressBar;
    lblDownloaded: TsLabel;
    lblExename: TsLabel;
    procedure FormShow(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure tmStartTimer(Sender: TObject);
    procedure DownloadProgress(sender: TObject; Read, Total: Integer);
  private
    httpCLient: TRoomerHttpClient;
    procedure StartLabel(Label_: TsLabel);
    procedure EndLabel(Label_: TsLabel);
    procedure PerformUpdate;
    function DownloadFile(const Url, filename: String): Boolean;
    procedure RemoveLanguagesFiles;
    procedure RemoveAllRoomerCaches;
    function TryCopyFile(localFilename, exeName: PWideChar): Boolean;
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmUpgradeAgent: TfrmUpgradeAgent;

implementation

{$R *.dfm}

uses
  Types
  , ShellAPI
  , uStringUtils
  , uFileSystemUtils
  , uUpgraderCmdLineOptions
  , UITypes
  ;

const

  ROOMER_EXE_URI = 'Roomer.exe';

  _K  = 1024; //byte
  _B  = 1; //byte
  _KB = _K * _B; //kilobyte
  _MB = _K * _KB; //megabyte
  _GB = _K * _MB; //gigabyte

function FormatByteSize(const bytes: Longword): string;
begin

  if bytes > _GB then
    result := FormatFloat('#.## GB', bytes / _GB)
  else
    if bytes > _MB then
      result := FormatFloat('#.## MB', bytes / _MB)
    else
      if bytes > _KB then
        result := FormatFloat('#.## KB', bytes / _KB)
      else
        result := FormatFloat('#.## Bytes', bytes) ;
end;

procedure TfrmUpgradeAgent.FormCreate(Sender: TObject);
begin
  httpClient := TRoomerHttpClient.Create(Self);

  with httpClient do
  begin
    ConnectTimeout := 900;
    SendTimeout := 900;
    ReceiveTimeout := 900;
    OnDownloadProgress := DownloadProgress;
    InternetOptions := [wHttpIo_Ignore_cert_cn_invalid, wHttpIo_Ignore_cert_date_invalid, wHttpIo_Keep_connection, wHttpIo_Need_file, wHttpIo_No_cache_write, wHttpIo_Pragma_nocache, wHttpIo_Reload];
  end;
end;

procedure TfrmUpgradeAgent.FormShow(Sender: TObject);
begin
  tmStart.Enabled := true;
end;

procedure TfrmUpgradeAgent.StartLabel(Label_: TsLabel);
begin
  Label_.Font.Color := clWhite;
  Label_.Font.Style := [fsBold];
  Label_.Update;
end;

procedure TfrmUpgradeAgent.tmStartTimer(Sender: TObject);
begin
  tmStart.Enabled := false;
  PerformUpdate;
end;

procedure TfrmUpgradeAgent.DownloadProgress(sender: TObject; Read, Total: Integer);
var value : Extended;
begin
//  lblDownloaded.Caption := FormatFloat('0',Read) + ' bytes';
  if Total < 1 then
    Total := 57*_MB;
  if sProgressBar1.Max <> Total then
  begin
    sProgressBar1.Max := Total;
    sProgressBar1.Tag := 0;
  end;
  sProgressBar1.Position := Read;
  value := 100 * (Read / Total);
  if value > 100 then
     value := 100;
  lblDownloaded.Caption := FormatFloat('0.00',value) + '% of ~' + FormatByteSize(Total);
  lblDownloaded.Update;
  sProgressBar1.Update;
  sProgressBar1.Tag := sProgressBar1.Tag + 1;
  if sProgressBar1.Tag >= 20 then
  begin
    Application.ProcessMessages;
    sProgressBar1.Tag := 0;
  end;
end;

procedure TfrmUpgradeAgent.EndLabel(Label_: TsLabel);
begin
  Label_.Font.Color := clGray;
  Label_.Font.Style := [fsStrikeOut];
  Label_.Update;
end;

function TfrmUpgradeAgent.DownloadFile(const Url, filename : String) : Boolean;
var
  stream: TFileStream;
  aResponseContentHeader: TALHTTPResponseHeader;
begin
  aResponseContentHeader := TALHTTPResponseHeader.Create;
  stream := TFileStream.Create(filename, fmCreate);
  try
    try
      httpClient.Get(AnsiString(Url), stream, aResponseContentHeader);
      result := true;
    except
      result := false;
    end;
  finally
    stream.Free;
    aResponseContentHeader.Free;
  end;
end;


procedure TfrmUpgradeAgent.RemoveAllRoomerCaches;
var
  path: String;
  files : TStringDynArray;
  i: Integer;
begin
  try
    path := TPath.Combine(uFileSystemUtils.LocalAppDataPath, 'Roomer');
    files := TDirectory.GetFiles(Path + '\', '*.src', TSearchOption.soAllDirectories);
    for i := LOW(files) to HIGH(files) do
       DeleteFile(files[i]);
  except
    // Ignore - Not a vital problem
  end;
end;

procedure TfrmUpgradeAgent.RemoveLanguagesFiles;
var
  path: String;
begin
  try
    path := TPath.Combine(uFileSystemUtils.LocalAppDataPath, 'Roomer');
    path := TPath.Combine(path, 'Languages');
    forceDirectories(path);
    DeleteAllFiles(TPath.Combine(path, 'RoomerLanguage*.src'));
  except
    // Ignore - Not a vital problem
  end;
end;

function TfrmUpgradeAgent.TryCopyFile(localFilename, exeName : PWideChar) : Boolean;
begin
  result := False;
  while true do
  begin
    if CopyFile(localFilename, exeName, False) then
    begin
      result := True;
      Break;
    end;
    if MessageDlg('Unable to upgrade Roomer!' + #13#13 +
                  '[Retry] = Try to automatically close Roomer and retry the upgrade.' + #13 +
                  '[Cancel] = Cancel the upgrade for now.', mtConfirmation, [mbRetry, mbCancel], 0) = mrCancel then
    begin
      result := False;
      Break;
    end;
    KillTask(ExtractFilename(exeName));
    sleep(2000);
  end;
end;

procedure TfrmUpgradeAgent.PerformUpdate;
var exeName : String;
    localFilename : PWideChar;
    tempFile : String;
begin
  exeName := TUpgraderCmdlineOptions.ExeName;

  lblExename.Caption := exeName;
  StartLabel(Label1);
  try
    tempFile := TPath.GetTempFileName; // ExtractFilePath(exeName) + '\rTemp.exe';
    deleteFile(tempFile);
    if DownloadFile(TUpgraderCmdlineOptions.RoomerStoreURL + ROOMER_EXE_URI, tempFile) then
    begin
      if not TUpgraderCmdlineOptions.SkipClearLanguages then
        RemoveLanguagesFiles;
      if not TUpgraderCmdlineOptions.SkipClearCache then
        RemoveAllRoomerCaches;

      lblDownloaded.Hide;
      lblDownloaded.Update;

      EndLabel(Label1);

      StartLabel(Label2);
      sleep(2000);
      DeleteFile(exeName);
      localFilename := PWideChar(tempFile);
      if NOT TryCopyFile(localFilename, PChar(exeName)) then
      begin
        if FileExists(tempFile) then
          deleteFile(tempFile);
        Close;
        exit;
      end;
      DeleteFile(localFilename);
      EndLabel(Label2);

      StartLabel(Label3);
      ShellExecute(Handle, 'open', PChar(exeName), nil, nil, SW_SHOWNORMAL);
      EndLabel(Label3);
    end;
  except
    On E: Exception do begin
      {$IFDEF DEBUG}
        ShowMessage('Error: ' + e.Message);
      {$ENDIF}
    end;
  end;

  Close;
end;

end.
