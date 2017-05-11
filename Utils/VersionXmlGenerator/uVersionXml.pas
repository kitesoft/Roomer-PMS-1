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
function GetVersion(sFileName:string): string;
function FileMD5(const fileName : string) : string;

// Other Helpers
function dateTimeToXmlString(date : TDateTime) : String;

implementation

uses IdHashMessageDigest
    , idHash
    , uDateUtils;


const initialXmlContent =
            '<?xml version="1.0" encoding="UTF-8" standalone="no"?>' + #13#10 +
            '<files>' + #13#10 +
            '</files>';

procedure GenerateXml(const location : String; const ttl : Integer; const xmlFile : String; const onlyMd5 : Boolean);
var list : TStringDynArray;
    i: Integer;
    xml : IXMLDocument;
begin
  xml := GetXmlFile(xmlFile);

  list := TDirectory.GetFiles(location);

  for i := LOW(list) to HIGH(list) do
  begin
    if Lowercase(ExtractFileExt(list[i])) = '.exe' then
      if (Copy(Lowercase(ExtractFilename(list[i])), 1, 6) = 'roomer') then
           if GetVersion(list[i]) <> '' then
             SetFileInformation(xml,
                     ExtractFilename(list[i]),
                     GetVersion(list[i]),
                     FileMD5(list[i]),
                     ttl,
                     FileDateToDateTime(FileAge(list[i])),
                     onlyMd5);

  end;
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
var
  stl : TStrings;
begin
  Result := nil;
  result := NewXMLDocument; // CoDOMDocument40.Create;
  if NOT FileExists(xmlPath) then
  begin
    stl := TStringList.Create;
    try
      stl.Add(initialXmlContent);
      stl.SaveToFile(xmlPath);
    finally
      stl.Free;
    end;
  end;
  result.LoadFromFile(xmlPath);
end;

// *********************** FILE RESOURCE HELPERS ************************

function GetVersion(sFileName:string): string;
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
  GetFileVersionInfo(PChar(sFileName), 0, VerInfoSize, VerInfo);
  VerQueryValue(VerInfo, '\', Pointer(VerValue), VerValueSize);
  with VerValue^ do
  begin
    Result := IntToStr(dwFileVersionMS shr 16);
    Result := Result + '.' + IntToStr(dwFileVersionMS and $FFFF);
    Result := Result + '.' + IntToStr(dwFileVersionLS shr 16);
    Result := Result + '.' + IntToStr(dwFileVersionLS and $FFFF);
  end;
  FreeMem(VerInfo, VerInfoSize);
  Except end;
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
