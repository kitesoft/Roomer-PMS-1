unit uVersionXml;

interface

uses Winapi.Windows, System.Classes, System.Types, System.AnsiStrings, System.SysUtils, System.IOUtils;

procedure GenerateXml(const location : String; const ttl : Integer);
function GetVersion(sFileName:string): string;
function FileMD5(const fileName : string) : string;
function dateTimeToXmlString(date : TDateTime) : String;

implementation

uses IdHashMessageDigest
    , idHash;


const xml = '<?xml version="1.0" encoding="UTF-8" standalone="no"?>' + #13#10 +
            '<files>' + #13#10 +
            '%s' +
            '</files>';
const xmlFile = '  <file version="%s" filename="%s" md5="%s" ttl="%d" timeStamp="%s" />' + #13#10;

procedure GenerateXml(const location : String; const ttl : Integer);
var list : TStringDynArray;
    i: Integer;
    fileList : TStrings;
begin
  fileList := TStringList.Create;
  try
    list := TDirectory.GetFiles(location);

    for i := LOW(list) to HIGH(list) do
    begin
      if Lowercase(ExtractFileExt(list[i])) = '.exe' then
        if (Copy(Lowercase(ExtractFilename(list[i])), 1, 6) = 'roomer') then
             if GetVersion(list[i]) <> '' then
               fileList.Add(format(xmlFile,
                    [
                     GetVersion(list[i]),
                     ExtractFilename(list[i]),
                     FileMD5(list[i]),
                     ttl,
                     dateTimeToXmlString(FileDateToDateTime(FileAge(list[i])))
                    ]));

    end;
    writeln(format(xml, [fileList.Text]));
  finally
    fileList.Free;
  end;

end;

// *********************** HELPERS ************************

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

function dateTimeToXmlString(date : TDateTime) : String;
begin
  result := FormatDateTime('yyyy-mm-dd', date) + 'T' +
            FormatDateTime('hh:nn:ss', date);
end;


end.
