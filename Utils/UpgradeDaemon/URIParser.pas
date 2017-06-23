unit URIParser;

interface

uses System.Classes, SysUtils,
     uUpgradeFileManager,
     uRoomerUpgradeFileDependencymanager
     ;

type
  TURIActionType = (
                      atUnknown,
                      atClose,
                      atActive,
                      atActivate,
                      atCheckForUpgrade,
                      atUpgradeAvailable,
                      atUpgradeTTL,
                      atUpdateNow,
                      atWhoAreYou

                   );

  TStartUpgradeCheckEvent = procedure(const aStrParam:string) of object;

  TURIProcessor = class
    FURI : String;
    FProcessResult : String;
    FActionType : TURIActionType;
    FUpgradeFileManager : TUpgradeFileManager;

  private
    FFileExeName: String;
    FClearLanguage: Boolean;
    FClearCache: Boolean;
    FRoomerUpgradeFileDependencymanager: TRoomerUpgradeFileDependencymanager;
    FRoomerStore: String;
    FFileExePath: String;
    procedure SetProcessResult(const Value: String);
    procedure SetActionType(const Value: TURIActionType);
    function CheckForUpgrade: String;
    function UpgradeAvailable: String;
    function UpgradeTTL: String;
    function GetUpgradeExePathName: String;
    function UpdateNow: String;
    function GetActivateResult: String;
    function getStringAtIndex(stl: TStringList; index: Integer): String;
    function ActionTypeByName : TURIActionType;
  public
    constructor Create;
    destructor Destroy; override;
    function Process(const URI : String) : Boolean;
    procedure ClearLocalUpgradeInformation;

    property ProcessResult : String read FProcessResult write SetProcessResult;
    property ActionType : TURIActionType read FActionType write SetActionType;

    property UpgradeFileManager : TUpgradeFileManager read FUpgradeFileManager;
    property RoomerUpgradeFileDependencymanager : TRoomerUpgradeFileDependencymanager read FRoomerUpgradeFileDependencymanager;
    property FileExeName : String read FFileExeName;
    property FileExePath : String read FFileExePath;
    property RoomerStore : String read FRoomerStore;
    property ClearLanguage: Boolean read FClearLanguage;
    property ClearCache: Boolean read FClearCache;
    property UpgradeExePathName : String read GetUpgradeExePathName;
  end;

implementation


{ TURIProcessor }

uses uUtils,
     ioUtils,
     uFileSystemUtils,
     DateUtils,
     uDateUtils,
     idURI;

const URI_COMMAND_START_INDEX = 0;

// WhoAreYou (WAY)
      URI_WAY_ROOMER_STORE_INDEX = URI_COMMAND_START_INDEX + 1;

// Activate (AV)
      URI_AV_ROOMER_STORE_INDEX = URI_COMMAND_START_INDEX + 1;

// CheckForUpgrade (CFU)
      URI_CFU_EXE_NAME_INDEX = URI_COMMAND_START_INDEX + 1;

// UpgradeAvailable (UA)
      URI_UA_EXE_NAME_INDEX = URI_COMMAND_START_INDEX + 1;
      URI_UA_PATH_INDEX = URI_UA_EXE_NAME_INDEX + 1;

// UpgradeTTL (UTTL)
      URI_UTTL_EXE_NAME_INDEX = URI_COMMAND_START_INDEX + 1;

// UpdateNow (UN)
      URI_UN_EXE_NAME_INDEX = URI_COMMAND_START_INDEX + 1;
      URI_UN_PATH_INDEX = URI_UN_EXE_NAME_INDEX + 1;
      URI_UN_CLEAR_LANGUAGE_INDEX = URI_UN_PATH_INDEX + 1;
      URI_UN_CLEAR_CACHE_INDEX = URI_UN_CLEAR_LANGUAGE_INDEX + 1;

function TURIProcessor.getStringAtIndex(stl : TStringList; index : Integer) : String;
begin
  result := '';
  if index < stl.Count then
    result := stl[index];
end;

function TURIProcessor.ActionTypeByName: TURIActionType;
var ActionString : String;
    stl : TStringList;
begin
  ActionString := FURI;
  if copy(ActionString, 1, 1) = '/' then
    ActionString := Trim(Copy(FURI, 2, maxInt));

  stl := uUtils.Split(ActionString, '/');
  try
    if stl.Count = 0 then
      result := atUnknown
    else
    begin
            // localhost:62999/WhoAreYou
      if stl[URI_COMMAND_START_INDEX] = 'WhoAreYou' then
        result := atWhoAreYou

            // localhost:62999/Activate
      else if stl[URI_COMMAND_START_INDEX] = 'Activate' then
      begin
        result := atActivate;
        FRoomerStore := TIdURI.URLDecode(getStringAtIndex(stl, URI_AV_ROOMER_STORE_INDEX));
      end
            // localhost:62999/Active
      else if stl[URI_COMMAND_START_INDEX] = 'Active' then
        result := atActive

            // localhost:62999/Close
      else if stl[URI_COMMAND_START_INDEX] = 'Close' then
        result := atClose

            // localhost:62999/CheckForUpgrade/Roomer.exe/true/true
      else if stl[URI_COMMAND_START_INDEX] = 'CheckForUpgrade' then
      begin
        result := atCheckForUpgrade;
        FFileExeName := getStringAtIndex(stl, URI_CFU_EXE_NAME_INDEX);
        UpgradeFileManager.SetFileName(FFileExeName);
      end
            // localhost:62999/UpdateNow/Roomer.exe/C:\Roomer\Roomer.exe
      else if stl[URI_COMMAND_START_INDEX] = 'UpdateNow' then
      begin
        result := atUpdateNow;
        FFileExeName := getStringAtIndex(stl, URI_UN_EXE_NAME_INDEX);
        UpgradeFileManager.SetFileName(FFileExeName);
        FFileExePath := TIdURI.URLDecode(getStringAtIndex(stl, URI_UN_PATH_INDEX));
        FClearLanguage := LowerCase(getStringAtIndex(stl, URI_UN_CLEAR_LANGUAGE_INDEX)) = 'true';
        FClearCache := LowerCase(getStringAtIndex(stl, URI_UN_CLEAR_CACHE_INDEX)) = 'true';
      end
            // localhost:62999/UpgradeAvailable/Roomer.exe
      else if stl[URI_COMMAND_START_INDEX] = 'UpgradeAvailable' then
      begin
        result := atUpgradeAvailable;
        FFileExeName := getStringAtIndex(stl, URI_UA_EXE_NAME_INDEX);
        UpgradeFileManager.SetFileName(FFileExeName);
        FFileExePath := TIdURI.URLDecode(getStringAtIndex(stl, URI_UA_PATH_INDEX));
      end
            // localhost:62999/UpgradeTTL/Roomer.exe
      else if stl[URI_COMMAND_START_INDEX] = 'UpgradeTTL' then
      begin
        result := atUpgradeTTL;
        FFileExeName := getStringAtIndex(stl, URI_UTTL_EXE_NAME_INDEX);
        UpgradeFileManager.SetFileName(FFileExeName);
      end
      else
        result := atUnknown
    end;
  finally
    stl.Free;
  end;
end;

const RESULT_UPDATE_AVAILABLE = 'UPDATE_AVAILABLE|VERSION=%s|TTL=%d|END_TIME_STAMP=%s';
      RESULT_UPDATE_NOT_AVAILABLE = 'NO_UPDATE_AVAILABLE';

      RESULT_CHECK_FOR_UPGRADE = 'CHECK_FOR_UPGRADE_STARTED';

      RESULT_UNKNOWN = 'UNKNOWN';
      RESULT_ACTIVE = 'ACTIVE';
      RESULT_WHO_ARE_YOU = 'ROOMER_DAEMON';
      RESULT_CLOSE = 'CLOSING';
      RESULT_ACTIVATE = 'ACTIVATED %s';
      RESULT_NO_UPGRADE = 'NO_UPGRADE';

      RESULT_UPGRADE_AVAILABLE = 'RESULT_UPGRADE_AVAILABLE';

      RESULT_UPGRADE_TTL = 'TTL=%d';

      RESULT_UPDATE_NOW = 'UPDATING';

function TURIProcessor.CheckForUpgrade : String;
begin
  result := RESULT_CHECK_FOR_UPGRADE;
end;

procedure TURIProcessor.ClearLocalUpgradeInformation;
begin

end;

function TURIProcessor.UpgradeAvailable : String;
begin
  if (FileExePath <> '') AND FileExists(FileExePath) then
  begin
    if UpgradeFileManager.UpgradeFinished OR
      (TRIM(UpgradeFileManager.UpgradeVersion)='') OR
      (FileMD5(FileExePath) = UpgradeFileManager.UpgradeMD5) then
      result := RESULT_UPDATE_NOT_AVAILABLE
    else
      result := format(RESULT_UPDATE_AVAILABLE,
                        [
                          UpgradeFileManager.UpgradeVersion,
                          UpgradeFileManager.UpgradeTTL_Minutes,
                          uDateUtils.dateTimeToXmlString(IncMinute(UpgradeFileManager.UpgradeTimeStamp, UpgradeFileManager.UpgradeTTL_Minutes))
                        ]);
  end;
end;

function TURIProcessor.UpgradeTTL : String;
begin
  result := format(RESULT_UPGRADE_TTL, [UpgradeFileManager.UpgradeTTL_Minutes]);
end;

function TURIProcessor.UpdateNow : String;
begin
  result := RESULT_UPDATE_NOW;
end;

constructor TURIProcessor.Create;
begin
  FRoomerStore := 'http://roomerstore.com/';
  FUpgradeFileManager := TUpgradeFileManager.Create();
  FRoomerUpgradeFileDependencymanager := TRoomerUpgradeFileDependencymanager.Create;
end;

destructor TURIProcessor.Destroy;
begin
  FUpgradeFileManager.Free;
  FRoomerUpgradeFileDependencymanager.Free;
  inherited;
end;

function TURIProcessor.GetUpgradeExePathName: String;
begin
  result := TPath.Combine(RoomerNewUpgradePath, ExtractFilename(FileExeName));
end;

function TURIProcessor.Process(const URI : String): Boolean;
begin
  FURI := URI;
  FActionType := ActionTypeByName;

  result := true;
  case FActionType of
    atUnknown : ProcessResult := RESULT_UNKNOWN;
    atActivate : ProcessResult := GetActivateResult;
    atActive : ProcessResult := RESULT_ACTIVE;
    atClose : ProcessResult := RESULT_CLOSE;
    atCheckForUpgrade : ProcessResult := CheckForUpgrade;
    atUpgradeAvailable : ProcessResult := UpgradeAvailable;
    atUpgradeTTL : ProcessResult := UpgradeTTL;
    atUpdateNow :  ProcessResult := UpdateNow;
    atWhoAreYou :  ProcessResult := RESULT_WHO_ARE_YOU;
    else result := false;
  end;
end;

procedure TURIProcessor.SetActionType(const Value: TURIActionType);
begin
  FActionType := Value;
end;

procedure TURIProcessor.SetProcessResult(const Value: String);
begin
  FProcessResult := Value;
end;

function TURIProcessor.GetActivateResult : String;
begin
  result := format(RESULT_ACTIVATE, [FRoomerStore]);
end;

end.

