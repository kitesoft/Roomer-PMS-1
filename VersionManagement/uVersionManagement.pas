unit uVersionManagement;

interface

uses Windows, Dialogs, SysUtils, vcl.ExtCtrls, idHttp, uFileDependencyManager;

type

  TVersionRec = record
    Version : String;
    TTL : Integer;
    EndDateTime : TDateTime;
  end;

  TOnAskUpgrade = procedure(Text : String; version : String; forced : Boolean; var upgrade : Boolean) of Object;

  TRoomerVersionManagement = class
  private
    httpCLient: TIdHttp;
    timer : TTimer;
    initialTmer : TTimer;
    FileDependencyManager: TFileDependencymanager;
    RoomerUpgradeDaemonPath : String;
    FOnAskUpgrade: TOnAskUpgrade;

    VersionRec : TVersionRec;
    lastCounter : Integer;

    procedure OnTimer(Sender: TObject);
    procedure Start(initialStart : Boolean = False);
    procedure Stop;

    procedure makeSureUpgradeDaemonIsActive;

    function doesUpgradeWindowExist : Boolean;
    function activateDaemon : Boolean;
    function openDaemon : Boolean;
    function newVersionAvailable : Boolean;
    function newVersionTTL : Boolean;
    function updateNow : Boolean;
    procedure BreakDownVersionString(sStr: String);
    procedure PerformUpdateIfAvailable;
    procedure CheckIfUpgradeExists;
  public
    constructor Create;
    destructor Destroy;

    procedure Prepare;
    property OnAskUpgrade : TOnAskUpgrade read FOnAskUpgrade write FOnAskUpgrade;
  end;

implementation

uses uD,
     IOUtils,
     uRoomerDefinitions,
     uFileSystemUtils,
     uRunWithElevatedOption,
     Forms,
     uUtils,
     Classes,
     uDateUtils,
     DateUtils,
     idURI,
     PrjConst
    ;

const SECOND = 1000;
      MINUTE = 60 * SECOND;
      TEN_MINUTES = 10 * MINUTE;

      COUNT_FOR_NOTIFICATION = 6;

      URI_UPGRADE_DAEMON = 'http://localhost:62999/';
      URI_UPGRADE_DAEMON_UPGRADE_AVAILABLE = URI_UPGRADE_DAEMON + 'UpgradeAvailable/%s';
      URI_UPGRADE_DAEMON_CHECK_UPGRADE = URI_UPGRADE_DAEMON + 'CheckForUpgrade/%s';
      URI_UPGRADE_DAEMON_UPDATE_NOW = URI_UPGRADE_DAEMON + 'UpdateNow/%s/%s/%s/%s';

{ TRoomerVersionManagement }

function TRoomerVersionManagement.activateDaemon: Boolean;
begin
  // --
  Start(true);
end;

constructor TRoomerVersionManagement.Create;
begin
  lastCounter := COUNT_FOR_NOTIFICATION;
  httpCLient := TIdHttp.Create(nil);
  timer := TTimer.Create(nil);
  timer.Enabled := False;
  timer.OnTimer := OnTimer;

  FileDependencyManager := TFileDependencymanager.Create;

  RoomerUpgradeDaemonPath := TPath.Combine(RoomerAppDataPath, cUpgradeDaemon);
end;

destructor TRoomerVersionManagement.Destroy;
begin
  timer.Free;
  httpClient.Free;
  FileDependencyManager.Free;
end;

function TRoomerVersionManagement.doesUpgradeWindowExist: Boolean;
begin
  Result := FindWindow('TfrmUpgradeDaemon', NIL) > 0;
end;

procedure TRoomerVersionManagement.makeSureUpgradeDaemonIsActive;
begin
  if NOT doesUpgradeWindowExist then
  begin
    openDaemon;
    sleep(1000);
  end;
  activateDaemon;
end;

procedure TRoomerVersionManagement.BreakDownVersionString(sStr : String);
var stlResult, stlValues : TStringList;
  i: Integer;
begin
  stlResult := Split(sStr, '|');
  try
  for i := 0 to stlResult.Count - 1 do
  begin
    stlValues := Split(stlResult[i], '=');
    try
      if stlValues[0] = 'VERSION' then
        VersionRec.Version := stlValues[1]
      else
      if stlValues[0] = 'TTL' then
        VersionRec.TTL := StrToInt(stlValues[1])
      else
      if stlValues[0] = 'END_TIME_STAMP' then
        VersionRec.EndDateTime := uDateUtils.XmlStringToDate(stlValues[1]);
    finally
      stlValues.Free;
    end;
  end;
  finally
    stlResult.Free;
  end;
end;

function TRoomerVersionManagement.newVersionAvailable: Boolean;
var answer : String;
begin
  answer := httpCLient.Get(format(URI_UPGRADE_DAEMON_UPGRADE_AVAILABLE, ['Roomer.exe']));
  result := answer.StartsWith('UPDATE_AVAILABLE');
  BreakDownVersionString(answer);
end;

function TRoomerVersionManagement.newVersionTTL: Boolean;
begin

end;

procedure TRoomerVersionManagement.OnTimer(Sender: TObject);
begin
  Stop;
  try
    if newVersionAvailable then
      updateNow
    else
      CheckIfUpgradeExists;
  finally
    Start;
  end;
end;

function TRoomerVersionManagement.openDaemon: Boolean;
var exePath : String;
begin
   exePath := FileDependencyManager.getRoomerUpgradeDaemonFilePath(RoomerUpgradeDaemonPath);
   if exePath = '' then
     MessageDlg('Could not find the Roomer Upgrade Daemon!', mtError, [mbOk], 0)
   else
     ExecuteFile(Application.MainForm.Handle, exePath, '', []); // [eoElevate]);
end;

procedure TRoomerVersionManagement.Start(initialStart : Boolean = False);
begin
  timer.Interval := TEN_MINUTES;
  timer.Enabled := True;
  if initialStart then
    PerformUpdateIfAvailable;
end;

procedure TRoomerVersionManagement.Stop;
begin
  timer.Enabled := False;
end;

procedure TRoomerVersionManagement.PerformUpdateIfAvailable;
begin
  Stop;
  try
    if newVersionAvailable then
      updateNow
    else
      CheckIfUpgradeExists;
  finally
    Start;
  end;
end;

procedure TRoomerVersionManagement.Prepare;
begin
  makeSureUpgradeDaemonIsActive;
end;

procedure TRoomerVersionManagement.CheckIfUpgradeExists;
var s : String;
begin
  s := httpCLient.Get(format(URI_UPGRADE_DAEMON_CHECK_UPGRADE, ['Roomer.exe']));
end;

procedure GetHoursAndMinutes(TTL : Integer; var h, m : Integer);
var totalMinutes : Integer;
begin
  h := TTL DIV 60;
  m := TTL MOD 60;
end;

function TRoomerVersionManagement.updateNow: Boolean;
var forced, upgrade : Boolean;
    exePath, uri, s, msg : String;
    h, m : Integer;
begin
  forced := VersionRec.EndDateTime <= Now;
  inc(lastCounter);
  if forced OR
     (lastCounter > COUNT_FOR_NOTIFICATION) then
  begin
    if Assigned(FOnAskUpgrade) then
    begin
      upgrade := True;
      if forced then
        msg := format(GetTranslatedText('shTx_VersionManagement_ForceNewVersion'), [VersionRec.Version])
      else begin
        GetHoursAndMinutes(VersionRec.TTL, h, m);
        msg := format(GetTranslatedText('shTx_VersionManagement_NewVersionAvailable'), [VersionRec.Version, h, m])
      end;
      FOnAskUpgrade(msg, VersionRec.Version, forced, upgrade);
      if forced OR upgrade then
      begin
        exePath := d.roomerMainDataSet.URLEncode(Application.ExeName);
        uri := format(URI_UPGRADE_DAEMON_UPDATE_NOW, ['Roomer.exe', exePath, 'true', 'true']);
        CopyToClipboard(uri);
        s := httpCLient.Get(uri);
        if s = 'UPDATING' then
          Application.MainForm.Close;
      end
      else
        CheckIfUpgradeExists;
    end;
  end;
end;

end.
