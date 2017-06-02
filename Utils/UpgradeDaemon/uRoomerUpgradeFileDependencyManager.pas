unit uRoomerUpgradeFileDependencyManager;

interface

uses  Classes
    , SysUtils
    ;

type
  TRoomerUpgradeFileDependencymanager = class(TObject)
  private
  public
    function FileVersionOnServer(xmlPath : String; fileToCheck : String; var aVersion, MD5: string; var ttl: Integer; var timeStamp : TDateTime): boolean;
  end;

function RoomerUpgradeFileDependencyManager: TRoomerUpgradeFileDependencymanager;

implementation

uses
  IOUtils
  , MSXML2_TLB
  , uDateUtils
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

initialization

finalization
  gRoomerUpgradeFileDependencyMgr.Free;

end.
