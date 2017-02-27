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
//unit ap_DBPlatform;

interface

uses
  SysUtils,
  FMTBcd,
  DB,
  DBPlatform,
  System.Variants,
  atScript;

{$WARNINGS OFF}

type
  TatDBPlatformLibrary = class(TatScripterLibrary)
    procedure Init; override;
    class function LibraryName: string; override;
  end;

  TPlatformBytesClass = class of TPlatformBytes;
  TPlatformRecordBufferClass = class of TPlatformRecordBuffer;
  TPlatformValueBufferClass = class of TPlatformValueBuffer;



implementation



procedure TatDBPlatformLibrary.Init;
begin
  With Scripter.DefineClass(TPlatformBytes) do
  begin
  end;
  With Scripter.DefineClass(TPlatformRecordBuffer) do
  begin
  end;
  With Scripter.DefineClass(TPlatformValueBuffer) do
  begin
  end;
  With Scripter.DefineClass(ClassType) do
  begin
  end;
end;

class function TatDBPlatformLibrary.LibraryName: string;
begin
  result := 'DBPlatform';
end;

initialization
  RegisterScripterLibrary(TatDBPlatformLibrary, True);

{$WARNINGS ON}

end.

