unit uVersionXml;

interface

uses Winapi.Windows, System.Classes, System.Types, System.AnsiStrings, System.SysUtils, System.IOUtils,
    XmlUtils, ActiveX, XMLIntf, XMLDoc;

procedure GenerateXml(const location : String; const ttl : Integer; const xmlFile : String; const onlyMd5 : Boolean);

// XML Helpers
procedure SetFileNodeInfo(Node : IXMLNode; const new : Boolean; const Filename : String; const aVersion, MD5 : String; const ttl : Integer; timeStamp : TDateTime; const onlyMd5 : Boolean);
procedure SetFileInformation(XmlDoc : IXMLDocument; const Filename : String; const aVersion, MD5 : String; const ttl : Integer; const timeStamp : TDateTime; const onlyMd5 : Boolean);
function GetXmlFile(xmlPath : String): IXMLDocument;

// File resource Helpers
function GetVersion(const sFileName:string): string;
function FileMD5(const fileName : string) : string;

// Other Helpers
function dateTimeToXmlString(date : TDateTime) : String;

implementation

uses IdHashMessageDigest
    , idHash
    , uDateUtils;


procedure GenerateXml(const location : String; const ttl : Integer; const xmlFile : String; const onlyMd5 : Boolean);
var list : TStringDynArray;
    i: Integer;
    xml : IXMLDocument;
    lVersionString: string;
    lFileDate: TDateTime;
    lFileName: string;
begin
  xml := GetXmlFile(xmlFile);

  list := TDirectory.GetFiles(location);

  for i := LOW(list) to HIGH(list) do
  begin
    lFileName := ExtractFileName(list[i]);
    if ExtractFileExt(lFileName.ToLower).Equals('.exe') then
      if lFileName.ToLower.StartsWith('roomer') then
      begin
        lVersionString := GetVersion(list[i]);
        if not lVersionString.IsEmpty and FileAge(list[i], lFileDate) then
             SetFileInformation(xml,
                     lFileName,
                     lVersionString,
                     FileMD5(list[i]),
                     ttl,
                     lFileDate,
                     onlyMd5);

      end;
  end;
  xml.XML.Text := XMLDoc.FormatXMLData(xml.XML.Text);
  xml.Active := True;
  xml.SaveToFile(xmlFile);
end;

// *********************** XML HELPERS ************************

procedure SetFileNodeInfo(Node : IXMLNode; const new : Boolean; const Filename : String; const aVersion, MD5 : String; const ttl : Integer; timeStamp : TDateTime; const onlyMd5 : Boolean);
begin
  node.Attributes['filename'] := filename;
  node.Attributes['md5'] := MD5;
  if (NOT onlyMd5) OR new then
  begin
    node.Attributes['version'] := aVersion;
    node.Attributes['ttl'] := inttoStr(ttl);
    node.Attributes['timeStamp'] := dateTimeToXmlString(timeStamp);
  end;
end;

procedure SetFileInformation(XmlDoc : IXMLDocument; const Filename : String; const aVersion, MD5 : String; const ttl : Integer; const timeStamp : TDateTime; const onlyMd5 : Boolean);
var
  node: IXMLNode;
  newElement : IXMLNode;
  found : Boolean;
  nodeList : IXmlNodeList;
begin
  found := false;
  nodeList := XmlDoc.documentElement.ChildNodes;
  node := nodeList.First;
  while node <> nil do
  begin
    if node.Attributes['filename'] = Filename then
    begin
      SetFileNodeInfo(Node, false, Filename, aVersion, MD5, ttl, timeStamp, onlyMd5);
      found := true;
      Break;
    end;
    node := node.nextSibling;
  end;
  if NOT found then
  begin
    node := XmlDoc.documentElement;
    newElement := node.AddChild('file');
    SetFileNodeInfo(newElement, true, Filename, aVersion, MD5, ttl, timeStamp, onlyMd5);
  end;
end;

function GetXmlFile(xmlPath : String): IXMLDocument;
begin
  result := NewXMLDocument; // CoDOMDocument40.Create;
  if NOT FileExists(xmlPath) then
  begin
    result.AddChild('files');
    result.StandAlone := 'no';
    result.encoding := 'UTF-8';
  end
  else
    result.LoadFromFile(xmlPath);
end;

// *********************** FILE RESOURCE HELPERS ************************

function GetVersion(const sFileName:string): string;
var
  VerInfoSize: DWORD;
  VerInfo: Pointer;
  VerValueSize: DWORD;
  VerValue: PVSFixedFileInfo;
  Dummy: DWORD;
begin
  result := '';
  try
    VerInfoSize := GetFileVersionInfoSize(PChar(sFileName), Dummy);
    GetMem(VerInfo, VerInfoSize);
    try
      GetFileVersionInfo(PChar(sFileName), 0, VerInfoSize, VerInfo);
      VerQueryValue(VerInfo, '\', Pointer(VerValue), VerValueSize);
      with VerValue^ do
      begin
        Result := IntToStr(dwFileVersionMS shr 16);
        Result := Result + '.' + IntToStr(dwFileVersionMS and $FFFF);
        Result := Result + '.' + IntToStr(dwFileVersionLS shr 16);
        Result := Result + '.' + IntToStr(dwFileVersionLS and $FFFF);
      end;
    finally
      FreeMem(VerInfo, VerInfoSize);
    end;
  except
    Result := '';
  end;
end;

function FileMD5(const fileName : string) : string;
var
  IdMD5: TIdHashMessageDigest5;
  FS: TFileStream;
begin
 IdMD5 := TIdHashMessageDigest5.Create;
 FS := TFileStream.Create(fileName, fmOpenRead or fmShareDenyWrite);
 try
   Result := LowerCase(IdMD5.HashStreamAsHex(FS))
 finally
   FS.Free;
   IdMD5.Free;
 end;
end;

// *********************** OTHER HELPERS ************************

function dateTimeToXmlString(date : TDateTime) : String;
begin
  result := FormatDateTime('yyyy-mm-dd', date) + 'T' +
            FormatDateTime('hh:nn:ss', date);
end;


end.
