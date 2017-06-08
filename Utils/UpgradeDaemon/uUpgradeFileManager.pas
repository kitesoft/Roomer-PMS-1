unit uUpgradeFileManager;

interface

uses Forms, Inifiles, SysUtils, IOUtils;

type

  TUpgradeFileManager = class
    FIniFile : TInifile;
    FUpgradeFilename : String;
    FBaseLocation : String;

    function ReadInteger(Ident : String; default : Integer) : Integer;
    function ReadDateTime(Ident : String; default : TDateTime) : TDateTime;
    function ReadString(Ident : String; default : String) : String;
    function ReadBoolean(Ident: String; default: Boolean): Boolean;

    procedure WriteInteger(Ident : String; value : Integer);
    procedure WriteDateTime(Ident : String; value : TDateTime);
    procedure WriteBoolean(Ident : String; value: Boolean);
    procedure WriteString(Ident : String; value : String);
  private
    SectionName : String;
  public
    constructor Create(BaseLocation : String);
    destructor Destroy; override;

    procedure SetFileName(filename : String);
    function UpgradeAvailable : Boolean;
    function UpgradeTTL_Minutes : Integer;
    function UpgradeMD5: String;
    function UpgradeTimeStamp: TDateTime;
    function UpgradeVersion: String;
    function UpgradeFilename : String;
    function UpgradeFinished : boolean;
    procedure NewUpgrade(Filename, fileExeName : String; FileTimeStamp : TDateTime; TTL_Minutes : Integer; MD5, Version : String);
    procedure Upgraded(fileExeName : String; FileTimeStamp : TDateTime; TTL_Minutes : Integer; MD5, Version : String);

    procedure ClearLocalUpgradeInformation;
  end;

implementation

{ TUpgradeFileManager }

uses uUtils, uDateUtils, uFileSystemUtils;

const
  SECTION_UPGRADE = 'APP_';

  IDENT_FILENAME = 'FILENAME';
  IDENT_TIME_STAMP = 'TIME_STAMP';
  IDENT_TTL_MINUTES = 'TTL_MINUTES';
  IDENT_MD5 = 'MD5';
  IDENT_VERSION = 'VERSION';
  IDENT_UPGRADED = 'UPGRADED';

procedure TUpgradeFileManager.ClearLocalUpgradeInformation;
var IniFileName : String;
begin
  IniFileName := TPath.Combine(RoomerNewUpgradePath, 'ROOMER_UPDATES.DAT');
  if FileExists(IniFileName) then
    DeleteFile(IniFileName);
end;

constructor TUpgradeFileManager.Create(BaseLocation: String);
begin
  FIniFile := TInifile.Create(TPath.Combine(RoomerNewUpgradePath, 'ROOMER_UPDATES.DAT'));
end;

destructor TUpgradeFileManager.Destroy;
begin
  FIniFile.Free;
  inherited;
end;

procedure TUpgradeFileManager.NewUpgrade(Filename, fileExeName : String; FileTimeStamp: TDateTime; TTL_Minutes: Integer; MD5, Version : String);
var newFilename : String;
begin
  newFilename := TPath.Combine(RoomerNewUpgradePath, ExtractFilename(fileExeName));
  DeleteFile(newFilename);
  TFile.Move(Filename, newFilename);

  WriteString(IDENT_FILENAME, ExtractFilename(fileExeName));
  WriteDateTime(IDENT_TIME_STAMP, FileTimeStamp);
  WriteInteger(IDENT_TTL_MINUTES, TTL_Minutes);
  WriteString(IDENT_MD5, MD5);
  WriteString(IDENT_VERSION, Version);
  WriteBoolean(IDENT_UPGRADED, false);
end;

procedure TUpgradeFileManager.Upgraded(fileExeName : String; FileTimeStamp: TDateTime; TTL_Minutes: Integer; MD5, Version : String);
var newFilename : String;
begin
  newFilename := TPath.Combine(RoomerNewUpgradePath, ExtractFilename(fileExeName));

  WriteString(IDENT_FILENAME, ExtractFilename(fileExeName));
  WriteDateTime(IDENT_TIME_STAMP, FileTimeStamp);
  WriteInteger(IDENT_TTL_MINUTES, TTL_Minutes);
  WriteString(IDENT_MD5, MD5);
  WriteString(IDENT_VERSION, Version);
  WriteBoolean(IDENT_UPGRADED, true);
end;

function TUpgradeFileManager.ReadDateTime(Ident: String; default: TDateTime): TDateTime;
begin
  result := SqlStringToDateTime(FIniFile.ReadString(SectionName, Ident, DateTimeToDBString(default)));
end;

function TUpgradeFileManager.ReadInteger(Ident: String; default: Integer): Integer;
begin
  result := FIniFile.ReadInteger(SectionName, Ident, default);
end;

function TUpgradeFileManager.ReadString(Ident, default: String): String;
begin
  result := FIniFile.ReadString(SectionName, Ident, default);
end;

function TUpgradeFileManager.ReadBoolean(Ident : String; default: Boolean) : Boolean;
begin
  result := FIniFile.ReadBool(SectionName, Ident, default);
end;

procedure TUpgradeFileManager.SetFileName(filename: String);
begin
  FUpgradeFilename := Filename;
  SectionName := SECTION_UPGRADE + '_' + ExtractFilename(filename);
end;

function TUpgradeFileManager.UpgradeAvailable: Boolean;
begin
  result := UpgradeFilename <> '';
end;

function TUpgradeFileManager.UpgradeFilename: String;
begin
  result := ReadString(IDENT_FILENAME, '');
end;

function TUpgradeFileManager.UpgradeFinished: boolean;
begin
  result := ReadBoolean(IDENT_UPGRADED, false);
end;

function TUpgradeFileManager.UpgradeTTL_Minutes: Integer;
begin
  result := ReadInteger(IDENT_TTL_MINUTES, 0);
end;

function TUpgradeFileManager.UpgradeVersion: String;
begin
  result := ReadString(IDENT_VERSION, '');
end;

function TUpgradeFileManager.UpgradeMD5: String;
begin
  result := ReadString(IDENT_MD5, '');
end;

function TUpgradeFileManager.UpgradeTimeStamp: TDateTime;
begin
  result := ReadDateTime(IDENT_TIME_STAMP, 73030);
end;

procedure TUpgradeFileManager.WriteDateTime(Ident: String; value: TDateTime);
begin
  FIniFile.WriteString(SectionName, Ident, DateTimeToDBString(value));
end;

procedure TUpgradeFileManager.WriteInteger(Ident: String; value: Integer);
begin
  FIniFile.WriteInteger(SectionName, Ident, value);
end;

procedure TUpgradeFileManager.WriteString(Ident, value: String);
begin
  FIniFile.WriteString(SectionName, Ident, value);
end;

procedure TUpgradeFileManager.WriteBoolean(Ident : String; value: Boolean);
begin
  FIniFile.WriteBool(SectionName, Ident, value);
end;

end.
