unit URIParser;

interface

uses System.Classes, SysUtils,
     uUpgradeFileManager,
     uRoomerUpgradeFileDependencymanager
     ;

type
  TURIActionType = (
                      atUnknown,
                      atActivate,
                      atActive,
                      atCheckForUpgrade,
                      atUpgradeAvailable,
                      atUpgradeTTL,
                      atUpdateNow

                   );

  TStartUpgradeCheckEvent = procedure(const aStrParam:string) of object;

  TURIProcessor = class
    FURI : String;
    FProcessResult : String;
    FActionType : TURIActionType;
    FUpgradeFileManager : TUpgradeFileManager;

    function ActionTypeByName : TURIActionType;
    function ActionStringByEnum : TURIActionType;
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
  public
    constructor Create;
    destructor Destroy;
    function Process(URI : String) : Boolean;
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

function TURIProcessor.ActionStringByEnum: TURIActionType;
begin

end;

const URI_COMMAND_START_INDEX = 0;

// Activate (AV)
      URI_AV_ROOMER_STORE_INDEX = URI_COMMAND_START_INDEX + 1;

// CheckForUpgrade (CFU)
      URI_CFU_EXE_NAME_INDEX = URI_COMMAND_START_INDEX + 1;

// UpgradeAvailable (UA)
      URI_UA_EXE_NAME_INDEX = URI_COMMAND_START_INDEX + 1;

// UpgradeTTL (UTTL)
      URI_UTTL_EXE_NAME_INDEX = URI_COMMAND_START_INDEX + 1;

// UpdateNow (UN)
      URI_UN_EXE_NAME_INDEX = URI_COMMAND_START_INDEX + 1;
      URI_UN_PATH_INDEX = URI_UN_EXE_NAME_INDEX + 1;
      URI_UN_CLEAR_LANGUAGE_INDEX = URI_UN_PATH_INDEX + 1;
      URI_UN_CLEAR_CACHE_INDEX = URI_UN_CLEAR_LANGUAGE_INDEX + 1;


function TURIProcessor.ActionTypeByName: TURIActionType;
var ActionString : String;
    stl : TStringList;
begin
  ActionString := FURI;
  if copy(ActionString, 1, 1) = '/' then
    ActionString := Trim(Copy(FURI, 2, maxInt));
  stl := uUtils.Split(ActionString, '/');
  if stl.Count = 0 then
    result := atUnknown
  else begin
          // localhost:62999/Activate
    if stl[URI_COMMAND_START_INDEX] = 'Activate' then
    begin
      result := atActivate;
      FRoomerStore := TIdURI.URLDecode(stl[URI_AV_ROOMER_STORE_INDEX]);
    end
          // localhost:62999/Active
    else if stl[URI_COMMAND_START_INDEX] = 'Active' then
      result := atActive

          // localhost:62999/CheckForUpgrade/Roomer.exe/true/true
    else if stl[URI_COMMAND_START_INDEX] = 'CheckForUpgrade' then
    begin
      result := atCheckForUpgrade;
      FFileExeName := stl[URI_CFU_EXE_NAME_INDEX];
      UpgradeFileManager.SetFileName(FFileExeName);
    end
          // localhost:62999/UpdateNow/Roomer.exe/C:\Roomer\Roomer.exe
    else if stl[URI_COMMAND_START_INDEX] = 'UpdateNow' then
    begin
      result := atUpdateNow;
      FFileExeName := stl[URI_UN_EXE_NAME_INDEX];
      UpgradeFileManager.SetFileName(FFileExeName);
      FFileExePath := TIdURI.URLDecode(stl[URI_UN_PATH_INDEX]);
      FClearLanguage := LowerCase(stl[URI_UN_CLEAR_LANGUAGE_INDEX]) = 'true';
      FClearCache := LowerCase(stl[URI_UN_CLEAR_CACHE_INDEX]) = 'true';
    end
          // localhost:62999/UpgradeAvailable/Roomer.exe
    else if stl[URI_COMMAND_START_INDEX] = 'UpgradeAvailable' then
    begin
      result := atUpgradeAvailable;
      FFileExeName := stl[URI_UA_EXE_NAME_INDEX];
      UpgradeFileManager.SetFileName(FFileExeName);
    end
          // localhost:62999/UpgradeTTL/Roomer.exe
    else if stl[URI_COMMAND_START_INDEX] = 'UpgradeTTL' then
    begin
      result := atUpgradeTTL;
      FFileExeName := stl[URI_UTTL_EXE_NAME_INDEX];
      UpgradeFileManager.SetFileName(FFileExeName);
    end
    else
      result := atUnknown
  end;
end;

const RESULT_UPDATE_AVAILABLE = 'UPDATE_AVAILABLE|VERSION=%s|TTL=%d|END_TIME_STAMP=%s';
      RESULT_UPDATE_NOT_AVAILABLE = 'NO_UPDATE_AVAILABLE';

      RESULT_CHECK_FOR_UPGRADE = 'CHECK_FOR_UPGRADE_STARTED';

      RESULT_UNKNOWN = 'UNKNOWN';
      RESULT_ACTIVE = 'ACTIVE';
      RESULT_NO_UPGRADE = 'NO_UPGRADE';

      RESULT_UPGRADE_AVAILABLE = 'RESULT_UPGRADE_AVAILABLE';

      RESULT_UPGRADE_TTL = 'TTL=%d';

      RESULT_UPDATE_NOW = 'UPDATING';

function TURIProcessor.CheckForUpgrade : String;
begin
  result := RESULT_CHECK_FOR_UPGRADE;
end;

function TURIProcessor.UpgradeAvailable : String;
begin
  result := IIF(UpgradeFileManager.UpgradeFinished,
                RESULT_UPDATE_NOT_AVAILABLE,
                format(RESULT_UPDATE_AVAILABLE,
                    [
                      UpgradeFileManager.UpgradeVersion,
                      UpgradeFileManager.UpgradeTTL_Minutes,
                      uDateUtils.dateTimeToXmlString(IncMinute(UpgradeFileManager.UpgradeTimeStamp, UpgradeFileManager.UpgradeTTL_Minutes))
                    ]));
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
  FUpgradeFileManager := TUpgradeFileManager.Create(RoomerNewUpgradePath);
  FRoomerUpgradeFileDependencymanager := TRoomerUpgradeFileDependencymanager.Create;
end;

destructor TURIProcessor.Destroy;
begin
  FUpgradeFileManager.Free;
end;

function TURIProcessor.GetUpgradeExePathName: String;
begin
  result := TPath.Combine(RoomerNewUpgradePath, ExtractFilename(FileExeName));
end;

function TURIProcessor.Process(URI : String): Boolean;
begin
  FURI := URI;
  FActionType := ActionTypeByName;

  result := true;
  case FActionType of
    atUnknown : ProcessResult := RESULT_UNKNOWN;
    atActivate : ProcessResult := RESULT_ACTIVE;
    atActive : ProcessResult := RESULT_ACTIVE;
    atCheckForUpgrade : ProcessResult := CheckForUpgrade;
    atUpgradeAvailable : ProcessResult := UpgradeAvailable;
    atUpgradeTTL : ProcessResult := UpgradeTTL;
    atUpdateNow :  ProcessResult := UpdateNow;
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

end.

