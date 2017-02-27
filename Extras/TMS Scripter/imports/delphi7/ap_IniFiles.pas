{***************************************************************************}
{ This source code was generated automatically by                           }
{ Pas file import tool for Scripter Studio (Pro)                            }
{                                                                           }
{ Scripter Studio and Pas file import tool for Scripter Studio              }
{ written by TMS Software                                                   }
{            copyright © 1997 - 2010                                        }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{***************************************************************************}
//unit ap_IniFiles;

interface

uses
  SysUtils,
  Classes,
  IniFiles,
  Variants,
  atScript;

{$WARNINGS OFF}

type
  TatIniFilesLibrary = class(TatScripterLibrary)
    procedure __TCustomIniFileCreate(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileSectionExists(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadString(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileWriteString(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadInteger(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileWriteInteger(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadBool(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileWriteBool(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadBinaryStream(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadDate(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadDateTime(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadFloat(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadTime(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileWriteBinaryStream(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileWriteDate(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileWriteDateTime(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileWriteFloat(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileWriteTime(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadSection(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadSections(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileReadSectionValues(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileEraseSection(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileDeleteKey(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileUpdateFile(AMachine: TatVirtualMachine);
    procedure __TCustomIniFileValueExists(AMachine: TatVirtualMachine);
    procedure __GetTCustomIniFileFileName(AMachine: TatVirtualMachine);
    procedure __TStringHashCreate(AMachine: TatVirtualMachine);
    procedure __TStringHashDestroy(AMachine: TatVirtualMachine);
    procedure __TStringHashAdd(AMachine: TatVirtualMachine);
    procedure __TStringHashClear(AMachine: TatVirtualMachine);
    procedure __TStringHashRemove(AMachine: TatVirtualMachine);
    procedure __TStringHashModify(AMachine: TatVirtualMachine);
    procedure __TStringHashValueOf(AMachine: TatVirtualMachine);
    procedure __THashedStringListDestroy(AMachine: TatVirtualMachine);
    procedure __THashedStringListIndexOf(AMachine: TatVirtualMachine);
    procedure __THashedStringListIndexOfName(AMachine: TatVirtualMachine);
    procedure __TMemIniFileCreate(AMachine: TatVirtualMachine);
    procedure __TMemIniFileDestroy(AMachine: TatVirtualMachine);
    procedure __TMemIniFileClear(AMachine: TatVirtualMachine);
    procedure __TMemIniFileDeleteKey(AMachine: TatVirtualMachine);
    procedure __TMemIniFileEraseSection(AMachine: TatVirtualMachine);
    procedure __TMemIniFileGetStrings(AMachine: TatVirtualMachine);
    procedure __TMemIniFileReadSection(AMachine: TatVirtualMachine);
    procedure __TMemIniFileReadSections(AMachine: TatVirtualMachine);
    procedure __TMemIniFileReadSectionValues(AMachine: TatVirtualMachine);
    procedure __TMemIniFileReadString(AMachine: TatVirtualMachine);
    procedure __TMemIniFileRename(AMachine: TatVirtualMachine);
    procedure __TMemIniFileSetStrings(AMachine: TatVirtualMachine);
    procedure __TMemIniFileUpdateFile(AMachine: TatVirtualMachine);
    procedure __TMemIniFileWriteString(AMachine: TatVirtualMachine);
    procedure __GetTMemIniFileCaseSensitive(AMachine: TatVirtualMachine);
    procedure __SetTMemIniFileCaseSensitive(AMachine: TatVirtualMachine);
    procedure __TIniFileDestroy(AMachine: TatVirtualMachine);
    procedure __TIniFileReadString(AMachine: TatVirtualMachine);
    procedure __TIniFileWriteString(AMachine: TatVirtualMachine);
    procedure __TIniFileReadSection(AMachine: TatVirtualMachine);
    procedure __TIniFileReadSections(AMachine: TatVirtualMachine);
    procedure __TIniFileReadSectionValues(AMachine: TatVirtualMachine);
    procedure __TIniFileEraseSection(AMachine: TatVirtualMachine);
    procedure __TIniFileDeleteKey(AMachine: TatVirtualMachine);
    procedure __TIniFileUpdateFile(AMachine: TatVirtualMachine);
    procedure Init; override;
    class function LibraryName: string; override;
  end;

  EIniFileExceptionClass = class of EIniFileException;
  TCustomIniFileClass = class of TCustomIniFile;
  TStringHashClass = class of TStringHash;
  THashedStringListClass = class of THashedStringList;
  TMemIniFileClass = class of TMemIniFile;
  TIniFileClass = class of TIniFile;


  THashItemWrapper = class(TatRecordWrapper)
  private
    FKey: string;
    FValue: Integer;
  public
    constructor Create(ARecord: THashItem);
    function ObjToRec: THashItem;
  published
    property Key: string read FKey write FKey;
    property Value: Integer read FValue write FValue;
  end;
  

implementation

constructor THashItemWrapper.Create(ARecord: THashItem);
begin
  inherited Create;
  FKey := ARecord.Key;
  FValue := ARecord.Value;
end;

function THashItemWrapper.ObjToRec: THashItem;
begin
  result.Key := FKey;
  result.Value := FValue;
end;



procedure TatIniFilesLibrary.__TCustomIniFileCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomIniFileClass(CurrentClass.ClassRef).Create(VarToStr(GetInputArg(0))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileSectionExists(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomIniFile(CurrentObject).SectionExists(VarToStr(GetInputArg(0)));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadString(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := string(TCustomIniFile(CurrentObject).ReadString(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),VarToStr(GetInputArg(2))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileWriteString(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).WriteString(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),VarToStr(GetInputArg(2)));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadInteger(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(TCustomIniFile(CurrentObject).ReadInteger(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),VarToInteger(GetInputArg(2))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileWriteInteger(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).WriteInteger(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),VarToInteger(GetInputArg(2)));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadBool(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomIniFile(CurrentObject).ReadBool(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileWriteBool(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).WriteBool(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadBinaryStream(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(TCustomIniFile(CurrentObject).ReadBinaryStream(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),TStream(VarToObject(GetInputArg(2)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadDate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomIniFile(CurrentObject).ReadDate(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadDateTime(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomIniFile(CurrentObject).ReadDateTime(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadFloat(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomIniFile(CurrentObject).ReadFloat(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadTime(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomIniFile(CurrentObject).ReadTime(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileWriteBinaryStream(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).WriteBinaryStream(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),TStream(VarToObject(GetInputArg(2))));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileWriteDate(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).WriteDate(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileWriteDateTime(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).WriteDateTime(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileWriteFloat(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).WriteFloat(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileWriteTime(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).WriteTime(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),GetInputArg(2));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadSection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).ReadSection(VarToStr(GetInputArg(0)),TStrings(VarToObject(GetInputArg(1))));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadSections(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).ReadSections(TStrings(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileReadSectionValues(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).ReadSectionValues(VarToStr(GetInputArg(0)),TStrings(VarToObject(GetInputArg(1))));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileEraseSection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).EraseSection(VarToStr(GetInputArg(0)));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileDeleteKey(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).DeleteKey(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)));
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileUpdateFile(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomIniFile(CurrentObject).UpdateFile;
  end;
end;

procedure TatIniFilesLibrary.__TCustomIniFileValueExists(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomIniFile(CurrentObject).ValueExists(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__GetTCustomIniFileFileName(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(string(TCustomIniFile(CurrentObject).FileName));
  end;
end;

procedure TatIniFilesLibrary.__TStringHashCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
case InputArgCount of
0: AResult := ObjectToVar(TStringHashClass(CurrentClass.ClassRef).Create);
1: AResult := ObjectToVar(TStringHashClass(CurrentClass.ClassRef).Create(VarToInteger(GetInputArg(0))));
end;
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TStringHashDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TStringHash(CurrentObject).Destroy;
  end;
end;

procedure TatIniFilesLibrary.__TStringHashAdd(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TStringHash(CurrentObject).Add(VarToStr(GetInputArg(0)),VarToInteger(GetInputArg(1)));
  end;
end;

procedure TatIniFilesLibrary.__TStringHashClear(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TStringHash(CurrentObject).Clear;
  end;
end;

procedure TatIniFilesLibrary.__TStringHashRemove(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TStringHash(CurrentObject).Remove(VarToStr(GetInputArg(0)));
  end;
end;

procedure TatIniFilesLibrary.__TStringHashModify(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TStringHash(CurrentObject).Modify(VarToStr(GetInputArg(0)),VarToInteger(GetInputArg(1)));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TStringHashValueOf(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(TStringHash(CurrentObject).ValueOf(VarToStr(GetInputArg(0))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__THashedStringListDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    THashedStringList(CurrentObject).Destroy;
  end;
end;

procedure TatIniFilesLibrary.__THashedStringListIndexOf(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(THashedStringList(CurrentObject).IndexOf(VarToStr(GetInputArg(0))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__THashedStringListIndexOfName(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(THashedStringList(CurrentObject).IndexOfName(VarToStr(GetInputArg(0))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TMemIniFileClass(CurrentClass.ClassRef).Create(VarToStr(GetInputArg(0))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).Destroy;
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileClear(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).Clear;
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileDeleteKey(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).DeleteKey(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)));
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileEraseSection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).EraseSection(VarToStr(GetInputArg(0)));
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileGetStrings(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).GetStrings(TStrings(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileReadSection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).ReadSection(VarToStr(GetInputArg(0)),TStrings(VarToObject(GetInputArg(1))));
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileReadSections(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).ReadSections(TStrings(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileReadSectionValues(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).ReadSectionValues(VarToStr(GetInputArg(0)),TStrings(VarToObject(GetInputArg(1))));
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileReadString(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := string(TMemIniFile(CurrentObject).ReadString(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),VarToStr(GetInputArg(2))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileRename(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).Rename(VarToStr(GetInputArg(0)),GetInputArg(1));
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileSetStrings(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).SetStrings(TStrings(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileUpdateFile(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).UpdateFile;
  end;
end;

procedure TatIniFilesLibrary.__TMemIniFileWriteString(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).WriteString(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),VarToStr(GetInputArg(2)));
  end;
end;

procedure TatIniFilesLibrary.__GetTMemIniFileCaseSensitive(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TMemIniFile(CurrentObject).CaseSensitive);
  end;
end;

procedure TatIniFilesLibrary.__SetTMemIniFileCaseSensitive(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TMemIniFile(CurrentObject).CaseSensitive:=GetInputArg(0);
  end;
end;

procedure TatIniFilesLibrary.__TIniFileDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TIniFile(CurrentObject).Destroy;
  end;
end;

procedure TatIniFilesLibrary.__TIniFileReadString(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := string(TIniFile(CurrentObject).ReadString(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),VarToStr(GetInputArg(2))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIniFilesLibrary.__TIniFileWriteString(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TIniFile(CurrentObject).WriteString(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)),VarToStr(GetInputArg(2)));
  end;
end;

procedure TatIniFilesLibrary.__TIniFileReadSection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TIniFile(CurrentObject).ReadSection(VarToStr(GetInputArg(0)),TStrings(VarToObject(GetInputArg(1))));
  end;
end;

procedure TatIniFilesLibrary.__TIniFileReadSections(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TIniFile(CurrentObject).ReadSections(TStrings(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatIniFilesLibrary.__TIniFileReadSectionValues(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TIniFile(CurrentObject).ReadSectionValues(VarToStr(GetInputArg(0)),TStrings(VarToObject(GetInputArg(1))));
  end;
end;

procedure TatIniFilesLibrary.__TIniFileEraseSection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TIniFile(CurrentObject).EraseSection(VarToStr(GetInputArg(0)));
  end;
end;

procedure TatIniFilesLibrary.__TIniFileDeleteKey(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TIniFile(CurrentObject).DeleteKey(VarToStr(GetInputArg(0)),VarToStr(GetInputArg(1)));
  end;
end;

procedure TatIniFilesLibrary.__TIniFileUpdateFile(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TIniFile(CurrentObject).UpdateFile;
  end;
end;

procedure TatIniFilesLibrary.Init;
begin
  With Scripter.DefineClass(EIniFileException) do
  begin
  end;
  With Scripter.DefineClass(TCustomIniFile) do
  begin
    DefineMethod('Create',1,tkClass,TCustomIniFile,__TCustomIniFileCreate,true,0,'FileName: string');
    DefineMethod('SectionExists',1,tkVariant,nil,__TCustomIniFileSectionExists,false,0,'Section: string');
    DefineMethod('ReadString',3,tkVariant,nil,__TCustomIniFileReadString,false,0,'Section: string; Ident: string; Default: string');
    DefineMethod('WriteString',3,tkNone,nil,__TCustomIniFileWriteString,false,0,'Section: String; Ident: String; Value: String');
    DefineMethod('ReadInteger',3,tkInteger,nil,__TCustomIniFileReadInteger,false,0,'Section: string; Ident: string; Default: Longint');
    DefineMethod('WriteInteger',3,tkNone,nil,__TCustomIniFileWriteInteger,false,0,'Section: string; Ident: string; Value: Longint');
    DefineMethod('ReadBool',3,tkVariant,nil,__TCustomIniFileReadBool,false,0,'Section: string; Ident: string; Default: Boolean');
    DefineMethod('WriteBool',3,tkNone,nil,__TCustomIniFileWriteBool,false,0,'Section: string; Ident: string; Value: Boolean');
    DefineMethod('ReadBinaryStream',3,tkInteger,nil,__TCustomIniFileReadBinaryStream,false,0,'Section: string; Name: string; Value: TStream');
    DefineMethod('ReadDate',3,tkVariant,nil,__TCustomIniFileReadDate,false,0,'Section: string; Name: string; Default: TDateTime');
    DefineMethod('ReadDateTime',3,tkVariant,nil,__TCustomIniFileReadDateTime,false,0,'Section: string; Name: string; Default: TDateTime');
    DefineMethod('ReadFloat',3,tkVariant,nil,__TCustomIniFileReadFloat,false,0,'Section: string; Name: string; Default: Double');
    DefineMethod('ReadTime',3,tkVariant,nil,__TCustomIniFileReadTime,false,0,'Section: string; Name: string; Default: TDateTime');
    DefineMethod('WriteBinaryStream',3,tkNone,nil,__TCustomIniFileWriteBinaryStream,false,0,'Section: string; Name: string; Value: TStream');
    DefineMethod('WriteDate',3,tkNone,nil,__TCustomIniFileWriteDate,false,0,'Section: string; Name: string; Value: TDateTime');
    DefineMethod('WriteDateTime',3,tkNone,nil,__TCustomIniFileWriteDateTime,false,0,'Section: string; Name: string; Value: TDateTime');
    DefineMethod('WriteFloat',3,tkNone,nil,__TCustomIniFileWriteFloat,false,0,'Section: string; Name: string; Value: Double');
    DefineMethod('WriteTime',3,tkNone,nil,__TCustomIniFileWriteTime,false,0,'Section: string; Name: string; Value: TDateTime');
    DefineMethod('ReadSection',2,tkNone,nil,__TCustomIniFileReadSection,false,0,'Section: string; Strings: TStrings');
    DefineMethod('ReadSections',1,tkNone,nil,__TCustomIniFileReadSections,false,0,'Strings: TStrings');
    DefineMethod('ReadSectionValues',2,tkNone,nil,__TCustomIniFileReadSectionValues,false,0,'Section: string; Strings: TStrings');
    DefineMethod('EraseSection',1,tkNone,nil,__TCustomIniFileEraseSection,false,0,'Section: string');
    DefineMethod('DeleteKey',2,tkNone,nil,__TCustomIniFileDeleteKey,false,0,'Section: String; Ident: String');
    DefineMethod('UpdateFile',0,tkNone,nil,__TCustomIniFileUpdateFile,false,0,'');
    DefineMethod('ValueExists',2,tkVariant,nil,__TCustomIniFileValueExists,false,0,'Section: string; Ident: string');
    DefineProp('FileName',tkVariant,__GetTCustomIniFileFileName,nil,nil,false,0);
  end;
  With Scripter.DefineClass(TStringHash) do
  begin
    DefineMethod('Create',1,tkClass,TStringHash,__TStringHashCreate,true,1,'Size: Cardinal = 256');
    DefineMethod('Destroy',0,tkNone,nil,__TStringHashDestroy,false,0,'');
    DefineMethod('Add',2,tkNone,nil,__TStringHashAdd,false,0,'Key: string; Value: Integer');
    DefineMethod('Clear',0,tkNone,nil,__TStringHashClear,false,0,'');
    DefineMethod('Remove',1,tkNone,nil,__TStringHashRemove,false,0,'Key: string');
    DefineMethod('Modify',2,tkVariant,nil,__TStringHashModify,false,0,'Key: string; Value: Integer');
    DefineMethod('ValueOf',1,tkInteger,nil,__TStringHashValueOf,false,0,'Key: string');
  end;
  With Scripter.DefineClass(THashedStringList) do
  begin
    DefineMethod('Destroy',0,tkNone,nil,__THashedStringListDestroy,false,0,'');
    DefineMethod('IndexOf',1,tkInteger,nil,__THashedStringListIndexOf,false,0,'S: string');
    DefineMethod('IndexOfName',1,tkInteger,nil,__THashedStringListIndexOfName,false,0,'Name: string');
  end;
  With Scripter.DefineClass(TMemIniFile) do
  begin
    DefineMethod('Create',1,tkClass,TMemIniFile,__TMemIniFileCreate,true,0,'FileName: string');
    DefineMethod('Destroy',0,tkNone,nil,__TMemIniFileDestroy,false,0,'');
    DefineMethod('Clear',0,tkNone,nil,__TMemIniFileClear,false,0,'');
    DefineMethod('DeleteKey',2,tkNone,nil,__TMemIniFileDeleteKey,false,0,'Section: String; Ident: String');
    DefineMethod('EraseSection',1,tkNone,nil,__TMemIniFileEraseSection,false,0,'Section: string');
    DefineMethod('GetStrings',1,tkNone,nil,__TMemIniFileGetStrings,false,0,'List: TStrings');
    DefineMethod('ReadSection',2,tkNone,nil,__TMemIniFileReadSection,false,0,'Section: string; Strings: TStrings');
    DefineMethod('ReadSections',1,tkNone,nil,__TMemIniFileReadSections,false,0,'Strings: TStrings');
    DefineMethod('ReadSectionValues',2,tkNone,nil,__TMemIniFileReadSectionValues,false,0,'Section: string; Strings: TStrings');
    DefineMethod('ReadString',3,tkVariant,nil,__TMemIniFileReadString,false,0,'Section: string; Ident: string; Default: string');
    DefineMethod('Rename',2,tkNone,nil,__TMemIniFileRename,false,0,'FileName: string; Reload: Boolean');
    DefineMethod('SetStrings',1,tkNone,nil,__TMemIniFileSetStrings,false,0,'List: TStrings');
    DefineMethod('UpdateFile',0,tkNone,nil,__TMemIniFileUpdateFile,false,0,'');
    DefineMethod('WriteString',3,tkNone,nil,__TMemIniFileWriteString,false,0,'Section: String; Ident: String; Value: String');
    DefineProp('CaseSensitive',tkVariant,__GetTMemIniFileCaseSensitive,__SetTMemIniFileCaseSensitive,nil,false,0);
  end;
  With Scripter.DefineClass(TIniFile) do
  begin
    DefineMethod('Destroy',0,tkNone,nil,__TIniFileDestroy,false,0,'');
    DefineMethod('ReadString',3,tkVariant,nil,__TIniFileReadString,false,0,'Section: string; Ident: string; Default: string');
    DefineMethod('WriteString',3,tkNone,nil,__TIniFileWriteString,false,0,'Section: String; Ident: String; Value: String');
    DefineMethod('ReadSection',2,tkNone,nil,__TIniFileReadSection,false,0,'Section: string; Strings: TStrings');
    DefineMethod('ReadSections',1,tkNone,nil,__TIniFileReadSections,false,0,'Strings: TStrings');
    DefineMethod('ReadSectionValues',2,tkNone,nil,__TIniFileReadSectionValues,false,0,'Section: string; Strings: TStrings');
    DefineMethod('EraseSection',1,tkNone,nil,__TIniFileEraseSection,false,0,'Section: string');
    DefineMethod('DeleteKey',2,tkNone,nil,__TIniFileDeleteKey,false,0,'Section: String; Ident: String');
    DefineMethod('UpdateFile',0,tkNone,nil,__TIniFileUpdateFile,false,0,'');
  end;
  With Scripter.DefineClass(ClassType) do
  begin
  end;
end;

class function TatIniFilesLibrary.LibraryName: string;
begin
  result := 'IniFiles';
end;

initialization
  RegisterScripterLibrary(TatIniFilesLibrary, True);

{$WARNINGS ON}

end.

