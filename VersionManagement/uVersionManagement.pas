unit uVersionManagement;

interface

uses Windows,
     Dialogs,
     SysUtils,
     vcl.ExtCtrls,
     uFileDependencyManager,
     uRoomerLogger,

     uRoomerHttpClient;

type

  TVersionRec = record
    Version : String;
    TTL : Integer;
    EndDateTime : TDateTime;
  end;

  TOnAskUpgrade = procedure(Text : String; version : String; forced : Boolean; var upgrade : Boolean) of Object;

  TRoomerVersionManagement = class
  private
    httpCLient: TRoomerHttpClient;
    timer : TTimer;
    initialTmer : TTimer;
    FileDependencyManager: TFileDependencymanager;
    RoomerUpgradeDaemonPath : String;
    FOnAskUpgrade: TOnAskUpgrade;

    VersionRec : TVersionRec;
    lastCounter : Integer;

    RoomerLogger : TRoomerLogger;

    PortToUse : Integer;

    procedure OnTimer(Sender: TObject);
    procedure Start(initialStart : Boolean = False);
    procedure Stop;

    procedure makeSureUpgradeDaemonIsActive;

    function doesUpgradeWindowExist : Boolean;
    function activateDaemon : Boolean;
    function openDaemon : Boolean;
    function newVersionAvailable(force : Boolean = false) : Boolean;
    function updateNow(force : boolean = false) : Boolean;
    procedure BreakDownVersionString(sStr: String);
    procedure PerformUpdateIfAvailable(initialStart : Boolean = False);
    procedure CheckIfUpgradeExists;
    function GetFromURI(uri: String; useGetUriPort : Boolean = True): String;
    procedure CloseDaemon;
    function FindServicePort : integer;
    function GetURIPort(SourceURI : String) : String;
    procedure startEngine;
  public
    VersionManagerActive : Boolean;

    constructor Create;
    destructor Destroy; override;

    procedure Prepare;
    procedure ForceUpdate;
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
     PrjConst,
     uRoomerVersionInfo,
     uSocketHelpers
    ;

const SECOND = 1000;
      MINUTE = 60 * SECOND;
      FIVE_MINUTES = 5 * MINUTE;
      TEN_MINUTES = 10 * MINUTE;

      HTTP_LOCAL_IP = '127.0.0.1';
      HTTP_DEFAULT_PORT = 62999;
      HTTP_DEFAULT_PORT_MIN = 62989;

      MAX_COUNT_FOR_NOTIFICATION = 6;
      HTTP_CONNECT_TIME_OUT = 10 * SECOND;
      HTTP_TRANSFER_TIME_OUT = FIVE_MINUTES;

      URI_UPGRADE_DAEMON = 'http://localhost:{port}/';
      URI_UPGRADE_DAEMON_WHO_ARE_YOU = URI_UPGRADE_DAEMON + 'WhoAreYou';
      URI_UPGRADE_DAEMON_CLOSE = URI_UPGRADE_DAEMON + 'Close';
      URI_UPGRADE_DAEMON_ACTIVE = URI_UPGRADE_DAEMON + 'Active';
      URI_UPGRADE_DAEMON_ACTIVATE = URI_UPGRADE_DAEMON + 'Activate/%s';
      URI_UPGRADE_DAEMON_UPGRADE_AVAILABLE = URI_UPGRADE_DAEMON + 'UpgradeAvailable/%s/%s';
      URI_UPGRADE_DAEMON_CHECK_UPGRADE = URI_UPGRADE_DAEMON + 'CheckForUpgrade/%s';
      URI_UPGRADE_DAEMON_UPDATE_NOW = URI_UPGRADE_DAEMON + 'UpdateNow/%s/%s/%s/%s';

{ TRoomerVersionManagement }


function TRoomerVersionManagement.activateDaemon: Boolean;
begin
  // --
  GetFromURI(format(URI_UPGRADE_DAEMON_ACTIVATE, [d.roomerMainDataSet.ForcedURLEncode(d.roomerMainDataSet.RoomerStoreUri)]));
  Start(true);
end;

constructor TRoomerVersionManagement.Create;
begin
  PortToUse := 0;
  VersionManagerActive := NOT FileExists(ChangeFileExt(Application.ExeName, '-SharedResource.True'));
  RoomerLogger := ActivateRoomerLogger(ClassName);
  lastCounter := MAX_COUNT_FOR_NOTIFICATION;
  httpCLient := TRoomerHttpClient.Create(nil);
//  httpCLient.InternetOptions := [
//                                 wHttpIo_No_cache_write,
//                                 wHttpIo_No_cookies,
//                                 wHttpIo_No_ui,
//                                 wHttpIo_Pragma_nocache
//                                ];
//  httpClient.ConnectTimeout := HTTP_CONNECT_TIME_OUT;
//  httpClient.ReceiveTimeout := HTTP_TRANSFER_TIME_OUT;
//  httpClient.SendTimeout := HTTP_TRANSFER_TIME_OUT;
  FileDependencyManager := TFileDependencymanager.Create;

  RoomerUpgradeDaemonPath := TPath.Combine(RoomerAppDataPath, cUpgradeDaemon);

  timer := TTimer.Create(nil);
  timer.Enabled := False;
  timer.OnTimer := OnTimer;

end;

destructor TRoomerVersionManagement.Destroy;
begin
  timer.Free;
  httpClient.Free;
  FileDependencyManager.Free;
  DeactivateRoomerLogger(RoomerLogger);
  inherited;
end;

procedure TRoomerVersionManagement.CloseDaemon;
var i : Integer;
begin
  GetFromURI(URI_UPGRADE_DAEMON_CLOSE);
  Application.ProcessMessages;
  for i := 1 to 20 do
  begin
    Sleep(100);
    Application.ProcessMessages;
  end;
  Application.ProcessMessages;
  PortToUse := 0;
end;

function TRoomerVersionManagement.FindServicePort: integer;
var uri,
    res : String;
    UnusedPorts : TAvailablePortArray;

    function PortInUse(port : word) : Boolean;
    var i: Integer;
    begin
      result := True;
      for i := LOW(UnusedPorts) to HIGH(UnusedPorts) do
        if UnusedPorts[i] = port then
        begin
          result := False;
          Break;
        end;
    end;
begin
  if PortToUse = 0 then
  begin
    UnusedPorts := findAvailableTCPPort( HTTP_LOCAL_IP, HTTP_DEFAULT_PORT_MIN, HTTP_DEFAULT_PORT, 11 );
    result := HTTP_DEFAULT_PORT;
    repeat
      if PortInUse(result) then
      begin
        uri := replaceString(URI_UPGRADE_DAEMON_WHO_ARE_YOU, '{port}', inttostr(result));
        res := getFromURI(uri, False);
        if res = 'ROOMER_DAEMON' then
          Break;
      end;
      dec(result);
    until result <= HTTP_DEFAULT_PORT_MIN;
    if result <= HTTP_DEFAULT_PORT_MIN then
      result := 0;
  end else
    result := PortToUse;
end;

procedure TRoomerVersionManagement.ForceUpdate;
begin
  Stop;
  try
    if newVersionAvailable(true) then
      updateNow(true)
//    else
//      CheckIfUpgradeExists;
  finally
    Start;
  end;
end;

function TRoomerVersionManagement.GetFromURI(uri : String; useGetUriPort : Boolean = True) : String;
begin
  try
    if useGetUriPort then
      uri := GetURIPort(uri);
    RoomerLogger.AddToLog(format('Calling to %s', [uri]));
    Result := string(httpCLient.Get(AnsiString(uri)));
    RoomerLogger.AddToLog(format('Call to %s returned %s', [uri, result]));
  except
    ON E: Exception do
    begin
      result := '';
      RoomerLogger.AddToLog(format('Call to %s failed with %s', [uri, e.Message]));
    end;
  end;
end;

function TRoomerVersionManagement.GetURIPort(SourceURI: String): String;
begin
  result := replaceString(SourceURI, '{port}', inttostr(PortToUse));
end;

function TRoomerVersionManagement.doesUpgradeWindowExist: Boolean;
var s : String;
begin
  s := '';
  PortToUse := FindServicePort;
  if PortToUse > 0 then
    s := GetFromURI(URI_UPGRADE_DAEMON_ACTIVE);
  result := (s = 'ACTIVE') OR (s = 'BUSY');
end;


procedure TRoomerVersionManagement.makeSureUpgradeDaemonIsActive;
var UpgradeActive : Boolean;
begin
{$IFNDEF DEBUG}
  if VersionManagerActive then
    begin
    UpgradeActive := doesUpgradeWindowExist;
    if UpgradeActive AND FileDependencyManager.doesNewUpgradeDemonExist(RoomerUpgradeDaemonPath) then
      CloseDaemon;
    if NOT doesUpgradeWindowExist then
    begin
      openDaemon;
      PortToUse := FindServicePort;
    end;
  end;
{$ENDIF}
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
      while stlValues.Count < 2 do stlValues.Add('');

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

function TRoomerVersionManagement.newVersionAvailable(force : Boolean = false): Boolean;
var answer, exePath : String;
    List : TStrings;
    uri : String;
begin
  exePath := d.roomerMainDataSet.URLEncode(Application.ExeName);
  uri := format(URI_UPGRADE_DAEMON_UPGRADE_AVAILABLE, ['Roomer.exe', exePath]);
  answer := GetFromURI(uri);
  BreakDownVersionString(answer);
  RoomerLogger.AddToLog('Upgrade Daemon returned: ' + answer);
  result := UpperCase(Trim(answer)).StartsWith('UPDATE_AVAILABLE');
  if result then
  begin
    RoomerLogger.AddToLog('     Update available: ' + VersionRec.Version);
    RoomerLogger.AddToLog('     Time-to-live: ' + IntToStr(VersionRec.TTL));
    RoomerLogger.AddToLog('     Ending at: ' + DateTimeToStr(VersionRec.EndDateTime));
    result := result AND (force OR (VersionRec.Version <> TRoomerVersionInfo.FileVersion));
    if result then
      RoomerLogger.AddToLog('Returning: accept-update')
    else
      RoomerLogger.AddToLog('Returning: update-not-needed');
  end;
end;

procedure TRoomerVersionManagement.OnTimer(Sender: TObject);
begin
  Stop;
  try
    if newVersionAvailable then
      updateNow
//    else
//      CheckIfUpgradeExists;
  finally
    Start;
  end;
end;

function TRoomerVersionManagement.openDaemon: Boolean;
var exePath : String;
begin
   RoomerLogger.AddToLog('Opening Daemon...');
   exePath := FileDependencyManager.getRoomerUpgradeDaemonFilePath(RoomerUpgradeDaemonPath);
   if exePath = '' then
   begin
     MessageDlg('Could not find the Roomer Upgrade Daemon!', mtError, [mbOk], 0);
     RoomerLogger.AddToLog('Daemon Could not be found!');
   end else
   begin
     PortToUse := 0;
     ExecuteFile(Application.MainForm.Handle, exePath, '', []); // [eoElevate]);
     RoomerLogger.AddToLog('Daemon opened.');
     sleep(2000);
   end;
end;

procedure TRoomerVersionManagement.Start(initialStart : Boolean = False);
begin
  timer.Interval := TEN_MINUTES;
  timer.Enabled := True;
  if initialStart then
    PerformUpdateIfAvailable(InitialStart);
end;

procedure TRoomerVersionManagement.Stop;
begin
  timer.Enabled := False;
end;

procedure TRoomerVersionManagement.PerformUpdateIfAvailable(initialStart : Boolean = False);
begin
  Stop;
  try
    if newVersionAvailable then
      updateNow
    else
    if initialStart then
      CheckIfUpgradeExists;
  finally
    Start;
  end;
end;

procedure TRoomerVersionManagement.Prepare;
begin
  makeSureUpgradeDaemonIsActive;
  StartEngine;
end;

procedure TRoomerVersionManagement.startEngine;
begin
{$IFNDEF DEBUG}
  if VersionManagerActive then
    activateDaemon;
{$ENDIF}
end;

procedure TRoomerVersionManagement.CheckIfUpgradeExists;
var s : String;
begin
  s := GetFromURI(format(URI_UPGRADE_DAEMON_CHECK_UPGRADE, ['Roomer.exe']));
end;

procedure GetHoursAndMinutes(TTL : Integer; var h, m : Integer);
var totalMinutes : Integer;
begin
  h := TTL DIV 60;
  m := TTL MOD 60;
end;

function TRoomerVersionManagement.updateNow(force : boolean = false): Boolean;
var forced, upgrade : Boolean;
    s, msg : String;
    h, m : Integer;

    procedure Update;
    var exePath, uri : String;
    begin
      RoomerLogger.AddToLog('Updating Roomer...');
      exePath := d.roomerMainDataSet.URLEncode(Application.ExeName);
      uri := format(URI_UPGRADE_DAEMON_UPDATE_NOW, ['Roomer.exe', exePath, 'true', 'true']);
      CopyToClipboard(uri);
      s := GetFromURI(uri);
      if s = 'UPDATING' then
      begin
        Application.MainForm.Close;
        RoomerLogger.AddToLog('Closing Roomer for update...');
      end else
        RoomerLogger.AddToLog('Update not continuing!');
    end;
begin
  RoomerLogger.AddToLog('Starting update check...');
  if force then
    update
  else
  begin
    forced := VersionRec.EndDateTime <= Now;
    inc(lastCounter);
    if forced OR
       (lastCounter > MAX_COUNT_FOR_NOTIFICATION) then
    begin
      if Assigned(FOnAskUpgrade) then
      begin
        upgrade := True;
        if forced then
          msg := format(GetTranslatedText('shTx_VersionManagement_ForceNewVersion'), [VersionRec.Version,
                 GetTranslatedText('shTx_AboutRoomer_NewVersionAvailableUpdateNow')])
        else begin
//          GetHoursAndMinutes(VersionRec.TTL, h, m);
          GetHoursAndMinutes(MinutesBetween(VersionRec.EndDateTime,Now), h, m);
          msg := format(GetTranslatedText('shTx_VersionManagement_NewVersionAvailable'), [VersionRec.Version,
                 h,
                 m,
                 GetTranslatedText('shTx_AboutRoomer_NewVersionAvailableUpdateNow'),
                 GetTranslatedText('shTx_AboutRoomer_NewVersionAvailableUpdateLater')])
        end;
        RoomerLogger.AddToLog('Asking user: ' + msg);
        FOnAskUpgrade(msg, VersionRec.Version, forced, upgrade);
        if forced OR upgrade then
          update
//        else
//          CheckIfUpgradeExists;
      end;
      lastCounter := 0;
    end;
  end;
  RoomerLogger.AddToLog('Finished update check.');
end;

end.
