unit uUpgradeFileManager;

interface

uses Forms, Inifiles, SysUtils, IOUtils;

type

  TUpgradeFileManager = class
    FUpgradeFilename : String;
    FBaseLocation : String;

    function ReadInteger(const Ident : String; default : Integer) : Integer;
    function ReadDateTime(const Ident : String; default : TDateTime) : TDateTime;
    function ReadString(const Ident : String; const default : String) : String;
    function ReadBoolean(const Ident: String; default: Boolean): Boolean;

    procedure WriteInteger(const Ident : String; value : Integer);
    procedure WriteDateTime(const Ident : String; value : TDateTime);
    procedure WriteBoolean(const Ident : String; value: Boolean);
    procedure WriteString(const Ident : String; const value : String);
  private
    SectionName : String;
    INIFilename : String;
  public
    constructor Create();
    destructor Destroy; override;

    function OpenINI : TIniFile;

    procedure SetFileName(const filename : String);
    function UpgradeAvailable : Boolean;
    function UpgradeTTL_Minutes : Integer;
    function UpgradeMD5: String;
    function UpgradeTimeStamp: TDateTime;
    function UpgradeVersion: String;
    function UpgradeFilename : String;
    function UpgradeFinished : boolean;
    procedure NewUpgrade(const Filename, fileExeName : String; FileTimeStamp : TDateTime; TTL_Minutes : Integer; const MD5, Version : String);
    procedure Upgraded(const fileExeName : String; FileTimeStamp : TDateTime; TTL_Minutes : Integer; const MD5, Version : String);

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
begin
  if FileExists(INIFileName) then
    DeleteFile(INIFileName);
end;

constructor TUpgradeFileManager.Create();
begin
 //
  INIFilename := TPath.Combine(RoomerNewUpgradePath, 'ROOMER_UPDATES.DAT');
end;

destructor TUpgradeFileManager.Destroy;
begin
  inherited;
end;

procedure TUpgradeFileManager.NewUpgrade(const Filename, fileExeName : String; FileTimeStamp: TDateTime; TTL_Minutes: Integer; const MD5, Version : String);
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

function TUpgradeFileManager.OpenINI : TIniFile;
begin
  result := TInifile.Create(INIFilename);
end;

procedure TUpgradeFileManager.Upgraded(const fileExeName : String; FileTimeStamp: TDateTime; TTL_Minutes: Integer; const MD5, Version : String);
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

function TUpgradeFileManager.ReadDateTime(const Ident: String; default: TDateTime): TDateTime;
var FIniFile : TInifile;
begin
  FIniFile := OpenINI;
  try
    result := SqlStringToDateTime(FIniFile.ReadString(SectionName, Ident, DateTimeToDBString(default)));
  finally
    FIniFile.Free;
  end;
end;

function TUpgradeFileManager.ReadInteger(const Ident: String; default: Integer): Integer;
var FIniFile : TInifile;
begin
  FIniFile := OpenINI;
  try
    result := FIniFile.ReadInteger(SectionName, Ident, default);
  finally
    FIniFile.Free;
  end;
end;

function TUpgradeFileManager.ReadString(const Ident, default: String): String;
var FIniFile : TInifile;
begin
  FIniFile := OpenINI;
  try
    result := FIniFile.ReadString(SectionName, Ident, default);
  finally
    FIniFile.Free;
  end;
end;

function TUpgradeFileManager.ReadBoolean(const Ident : String; default: Boolean) : Boolean;
var FIniFile : TInifile;
begin
  FIniFile := OpenINI;
  try
    result := FIniFile.ReadBool(SectionName, Ident, default);
  finally
    FIniFile.Free;
  end;
end;

procedure TUpgradeFileManager.SetFileName(const filename: String);
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

procedure TUpgradeFileManager.WriteDateTime(const Ident: String; value: TDateTime);
var FIniFile : TInifile;
begin
  FIniFile := OpenINI;
  try
    FIniFile.WriteString(SectionName, Ident, DateTimeToDBString(value));
  finally
    FIniFile.Free;
  end;
end;

procedure TUpgradeFileManager.WriteInteger(const Ident: String; value: Integer);
var FIniFile : TInifile;
begin
  FIniFile := OpenINI;
  try
    FIniFile.WriteInteger(SectionName, Ident, value);
  finally
    FIniFile.Free;
  end;
end;

procedure TUpgradeFileManager.WriteString(const Ident, value: String);
var FIniFile : TInifile;
begin
  FIniFile := OpenINI;
  try
    FIniFile.WriteString(SectionName, Ident, value);
  finally
    FIniFile.Free;
  end;
end;

procedure TUpgradeFileManager.WriteBoolean(const Ident : String; value: Boolean);
var FIniFile : TInifile;
begin
  FIniFile := OpenINI;
  try
    FIniFile.WriteBool(SectionName, Ident, value);
  finally
    FIniFile.Free;
  end;
end;

end.
