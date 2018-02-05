unit uSnapshotService;

interface

uses
  UITypes
  , SysUtils
  , Classes
  , uD
  , Generics.Collections;


type

  TSnapshotSettings = record
    id : Integer;
    active : boolean;
    systemUrl : String;
    username : String;
    password : String;
    apiKey : String;
  end;

function CreateConnectionSettingsXml(settings : TSnapshotSettings) : String;

function ParseConnectionSettingsXml(const settings : String) : TSnapshotSettings;

implementation

uses uStringUtils,
     uUtils,
     MSXML2_TLB,
     XmlUtils,
     msxmldom,
     XMLDoc,
     Xml.Xmldom,
     Xml.XMLIntf
;

const xmlTemplate = '<SnapshotSettings>' +
                    '<id>%d</id>' +
                    '<active>%s</active>' +
                    '<systemUrl>%s</systemUrl>' +
                    '<snapshotAuthentication>' +
                    '  <username>%s</username>' +
                    '  <password>%s</password>' +
                    '  <apiKey>%s</apiKey>' +
                    '</snapshotAuthentication>' +
                    '</SnapshotSettings>';

function CreateConnectionSettingsXml(settings : TSnapshotSettings) : String;
begin
  result := format(xmlTemplate,
              [
                settings.id,
                IIF(settings.active, 'true', 'false'),
                XmlEncode_ex(settings.systemUrl, ''),
                XmlEncode_ex(settings.username, ''),
                XmlEncode_ex(settings.password, ''),
                XmlEncode_ex(settings.apiKey, '')
              ]);
end;

function ParseConnectionSettingsXml(const settings : String) : TSnapshotSettings;
var
  XML: IXMLDOMDocument2;
  listNode, rootNode, authNode: IXMLDOmNode;
  i, l : Integer;
begin
  xml := CreateXmlDocument;
  xml.loadXML(settings);
  listNode := xml.documentElement;
  if listNode <> nil then
  begin
    if listNode.nodeName = 'SnapshotSettings' then
    begin
      with result do
      begin
        for i := 0 to listNode.childNodes.length - 1 do
        begin
          rootNode := listNode.childNodes.item[i];
          with rootNode do
          begin
            if rootNode.nodeName = 'id' then
               id := StrToInt(rootNode.text)
            else
            if rootNode.nodeName = 'active' then
               active := rootNode.text = 'true'
            else
            if rootNode.nodeName = 'systemUrl' then
               systemUrl := rootNode.text
            else
            if rootNode.nodeName = 'snapshotAuthentication' then
            begin
              for l := 0 to rootNode.childNodes.length - 1 do
              begin
                authNode := rootNode.childNodes.item[l];
                if authNode.nodeName = 'username' then
                   username := authNode.text
                else
                if authNode.nodeName = 'password' then
                   password := authNode.text
                else
                if authNode.nodeName = 'apiKey' then
                   apiKey := authNode.text;
              end;
            end;
          end;
        end;
      end;
    end;
  end;
end;

end.
