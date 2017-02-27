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
//unit ap_SHFolder;

interface

uses
  Windows,
  SHFolder,
  Variants,
  atScript;

{$WARNINGS OFF}

type
  TatSHFolderLibrary = class(TatScripterLibrary)
    procedure __SHGetFolderPath(AMachine: TatVirtualMachine);
    procedure __SHGetFolderPathA(AMachine: TatVirtualMachine);
    procedure __SHGetFolderPathW(AMachine: TatVirtualMachine);
    procedure Init; override;
    class function LibraryName: string; override;
  end;




implementation



procedure TatSHFolderLibrary.__SHGetFolderPath(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(SHFolder.SHGetFolderPath(VarToInteger(GetInputArg(0)),VarToInteger(GetInputArg(1)),VarToInteger(GetInputArg(2)),VarToInteger(GetInputArg(3)),PChar(VarToStr(GetInputArg(4)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatSHFolderLibrary.__SHGetFolderPathA(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(SHFolder.SHGetFolderPathA(VarToInteger(GetInputArg(0)),VarToInteger(GetInputArg(1)),VarToInteger(GetInputArg(2)),VarToInteger(GetInputArg(3)),PChar(VarToStr(GetInputArg(4)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatSHFolderLibrary.__SHGetFolderPathW(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(SHFolder.SHGetFolderPathW(VarToInteger(GetInputArg(0)),VarToInteger(GetInputArg(1)),VarToInteger(GetInputArg(2)),VarToInteger(GetInputArg(3)),PChar(VarToStr(GetInputArg(4)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatSHFolderLibrary.Init;
begin
  With Scripter.DefineClass(ClassType) do
  begin
    DefineMethod('SHGetFolderPath',5,tkInteger,nil,__SHGetFolderPath,false,0,'hwnd: HWND; csidl: Integer; hToken: THandle; dwFlags: DWord; pszPath: PAnsiChar');
    DefineMethod('SHGetFolderPathA',5,tkInteger,nil,__SHGetFolderPathA,false,0,'hwnd: HWND; csidl: Integer; hToken: THandle; dwFlags: DWord; pszPath: PAnsiChar');
    DefineMethod('SHGetFolderPathW',5,tkInteger,nil,__SHGetFolderPathW,false,0,'hwnd: HWND; csidl: Integer; hToken: THandle; dwFlags: DWord; pszPath: PAnsiChar');
    AddConstant('CSIDL_PERSONAL',CSIDL_PERSONAL);
    AddConstant('CSIDL_APPDATA',CSIDL_APPDATA);
    AddConstant('CSIDL_LOCAL_APPDATA',CSIDL_LOCAL_APPDATA);
    AddConstant('CSIDL_INTERNET_CACHE',CSIDL_INTERNET_CACHE);
    AddConstant('CSIDL_COOKIES',CSIDL_COOKIES);
    AddConstant('CSIDL_HISTORY',CSIDL_HISTORY);
    AddConstant('CSIDL_COMMON_APPDATA',CSIDL_COMMON_APPDATA);
    AddConstant('CSIDL_WINDOWS',CSIDL_WINDOWS);
    AddConstant('CSIDL_SYSTEM',CSIDL_SYSTEM);
    AddConstant('CSIDL_PROGRAM_FILES',CSIDL_PROGRAM_FILES);
    AddConstant('CSIDL_MYPICTURES',CSIDL_MYPICTURES);
    AddConstant('CSIDL_PROGRAM_FILES_COMMON',CSIDL_PROGRAM_FILES_COMMON);
    AddConstant('CSIDL_COMMON_DOCUMENTS',CSIDL_COMMON_DOCUMENTS);
    AddConstant('CSIDL_FLAG_CREATE',CSIDL_FLAG_CREATE);
    AddConstant('CSIDL_COMMON_ADMINTOOLS',CSIDL_COMMON_ADMINTOOLS);
    AddConstant('CSIDL_ADMINTOOLS',CSIDL_ADMINTOOLS);
  end;
end;

class function TatSHFolderLibrary.LibraryName: string;
begin
  result := 'SHFolder';
end;

initialization
  RegisterScripterLibrary(TatSHFolderLibrary, True);

{$WARNINGS ON}

end.

