unit uRoomerUpgradeFileDependencyManager;

interface

uses
  Generics.Collections
  , Classes
  , IdHTTP
  , IdSSLOpenSSL
  , SysUtils
  ;

type
  EFileDependencyManagerException = class(Exception);

  TRoomerUpgradeFileDependencymanager = class(TObject)
    type
      TResourceInfo = class
        Filename: String;
        Timestamp: TDateTime;
        URI: String;
        Size: Integer;
      public
        constructor Create(const _Filename: String; _Timestamp: TDateTime; _Size: Integer; const _URI: String);
      end;
  private

    FURI: String;

    function getExeFilePath(const Filename, toFile: String): String;
    function getFileInfoViaHead(const Filename: String; http: TIdHTTP): TResourceInfo;
    procedure SetURI(const Value: String);
  public

    function getAnyFileFromRoomerStore(const FromFile, toFile: String): String;
    function getRoomerUpgradeAgentFilePath(const toFile: String): String;
    function getRoomerVersionXmlFilePath(const toFile: String): String;
    function FileVersionOnServer(xmlPath : String; fileToCheck : String; var aVersion, MD5: string; var ttl: Integer; var timeStamp : TDateTime): boolean;

    property URI : String read FURI write SetURI;

  end;

function RoomerUpgradeFileDependencyManager: TRoomerUpgradeFileDependencymanager;

implementation

uses
  IOUtils
  , MSXML2_TLB
  , uDateUtils
  , uAPIDataHandler
  , uFileSystemUtils
  , XmlUtils
  ;

var
  gRoomerUpgradeFileDependencyMgr: TRoomerUpgradeFileDependencymanager;

function RoomerUpgradeFileDependencyManager: TRoomerUpgradeFileDependencymanager;
begin
  if not assigned(gRoomerUpgradeFileDependencyMgr) then
    gRoomerUpgradeFileDependencyMgr := TRoomerUpgradeFileDependencymanager.Create;

  Result := gRoomerUpgradeFileDependencyMgr;
end;


function TRoomerUpgradeFileDependencymanager.getFileInfoViaHead(const Filename: String; http: TIdHTTP): TResourceInfo;
var
  URI: String;
begin
  URI := FURI + Filename;
  http.Head(URI);
  Result := TResourceInfo.Create(Filename, http.Response.LastModified, http.Response.ContentLength, URI);
end;

function TRoomerUpgradeFileDependencymanager.getExeFilePath(const Filename, toFile: String): String;
var
  sFullFilename: String;
  DateOfFile: TDateTime;
  RemoteFile: TResourceInfo;
  http: TIdHTTP;
  IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL;
  URI: String;
  FS : TFileStream;
begin
  http := TIdHTTP.Create(nil);
  try
    IdSSLIOHandlerSocketOpenSSL1 := TIdSSLIOHandlerSocketOpenSSL.Create(nil);
    try
      http.IOHandler := IdSSLIOHandlerSocketOpenSSL1;
      http.Request.Accept := 'text/html,application/xhtml+xml,application/xml;application/octed-stream;q=0.9,*/*;q=0.8';
      http.Request.Referer := 'Mozilla/3.0 (compatible; Roomer PMS)';
      http.HTTPOptions := [hoForceEncodeParams];

      sFullFilename := ExtractFileName(Filename);
      DateOfFile := 0;
      if FileExists(toFile) then
        FileAge(toFile, DateOfFile);

      RemoteFile := getFileInfoViaHead(sFullFilename, http);
      try
        if RemoteFile = nil then
          Result := ''
        else
        begin
          if DateTimeToComparableString(DateOfFile) <> DateTimeToComparableString(RemoteFile.Timestamp) then
          begin
            FS := TFileStream.Create(toFile, fmOpenReadWrite OR fmCreate);
            http.Get(RemoteFile.URI, FS); // xxx d.roomerMainDataSet.SystemDownloadFileFromURI(RemoteFile.URI, toFile);
            TouchFile(toFile, RemoteFile.Timestamp);
          end;
          Result := toFile;
        end;
      finally
        RemoteFile.Free;
      end;
    finally
      IdSSLIOHandlerSocketOpenSSL1.Free;
    end;
  finally
    http.Free;
  end;
end;

// *********************************************************************

function TRoomerUpgradeFileDependencymanager.getRoomerUpgradeAgentFilePath(const toFile: String): String;
begin
  Result := getExeFilePath('RoomerUpgradeAgent.exe', toFile);
end;

function TRoomerUpgradeFileDependencymanager.getRoomerVersionXmlFilePath(const toFile: String): String;
begin
  Result := getExeFilePath('Roomer.xml', toFile);
end;

procedure TRoomerUpgradeFileDependencymanager.SetURI(const Value: String);
begin
  FURI := Value;
  if NOT FURI.EndsWith('/') then
    FURI := Copy(FURI, 1, Length(FURI) - 1);
end;

function TRoomerUpgradeFileDependencymanager.getAnyFileFromRoomerStore(const FromFile, toFile: String): String;
begin
  Result := getExeFilePath(FromFile, toFile);
end;

function TRoomerUpgradeFileDependencymanager.FileVersionOnServer(xmlPath : String; fileToCheck : String; var aVersion, MD5: string; var ttl : Integer; var timeStamp : TDateTime): boolean;
var
  XML: IXMLDOMDocument2;
  node: IXMLDOmNode;
begin
  Result := false;
  aVersion := '<version not found>';

  xml := CreateXmlDocument; // CoDOMDocument40.Create;
  xml.Load(xmlPath);

  node := xml.documentElement.firstChild;
  while node <> nil do
  begin
    if GetAttributeValue(node, 'filename', '') = fileToCheck then
    begin
      Result := true;
      aVersion := GetAttributeValue(node, 'version', aVersion);
      MD5 := GetAttributeValue(node, 'md5', '');
      ttl := StrToIntDef(GetAttributeValue(node, 'ttl', '1440'), 1440);
      timeStamp := uDateUtils.XmlStringToDate(GetAttributeValue(node, 'timeStamp', '2099-12-12T00:00:00'));
      Break;
    end;
    node := node.nextSibling;
  end;
end;


// *********************************************************************


{ TFileDependencymanager.TResourceInfo }

constructor TRoomerUpgradeFileDependencymanager.TResourceInfo.Create(const _Filename: String; _Timestamp: TDateTime; _Size: Integer; const _URI: String);
begin
  Filename := _Filename;
  Timestamp := _Timestamp;
  Size := _Size;
  URI := _URI;
end;

initialization

finalization
  gRoomerUpgradeFileDependencyMgr.Free;

end.
