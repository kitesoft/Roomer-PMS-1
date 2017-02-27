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
//unit ap_IBRestoreEditor;

interface

uses
  Windows,
  Messages,
  SysUtils,
  Variants,
  Classes,
  Graphics,
  Controls,
  Forms,
  Dialogs,
  Grids,
  StdCtrls,
  ExtCtrls,
  IBRestoreEditor,
  ap_Types,
  atScript;

{$WARNINGS OFF}

type
  TatIBRestoreEditorLibrary = class(TatScripterLibrary)
    procedure __TfrmIBRestoreEditorsgDatabaseFilesDrawCell(AMachine: TatVirtualMachine);
    procedure __TfrmIBRestoreEditorsgDatabaseFilesKeyDown(AMachine: TatVirtualMachine);
    procedure __TfrmIBRestoreEditorsgDatabaseFilesSelectCell(AMachine: TatVirtualMachine);
    procedure __TfrmIBRestoreEditorFormCreate(AMachine: TatVirtualMachine);
    procedure __TfrmIBRestoreEditorCreate(AMachine: TatVirtualMachine);
    procedure __TfrmIBRestoreEditorGetStrings(AMachine: TatVirtualMachine);
    procedure Init; override;
    class function LibraryName: string; override;
  end;

  TfrmIBRestoreEditorClass = class of TfrmIBRestoreEditor;



implementation



procedure TatIBRestoreEditorLibrary.__TfrmIBRestoreEditorsgDatabaseFilesDrawCell(AMachine: TatVirtualMachine);
  var
  Param4: TGridDrawState;
begin
  with AMachine do
  begin
IntToSet(Param4, VarToInteger(GetInputArg(4)), SizeOf(Param4));
    TfrmIBRestoreEditor(CurrentObject).sgDatabaseFilesDrawCell(TObject(VarToObject(GetInputArg(0))),VarToInteger(GetInputArg(1)),VarToInteger(GetInputArg(2)),TRectWrapper(integer(GetInputArg(3))).ObjToRec,Param4);
  end;
end;

procedure TatIBRestoreEditorLibrary.__TfrmIBRestoreEditorsgDatabaseFilesKeyDown(AMachine: TatVirtualMachine);
  var
  Param1: Word;
  Param2: TShiftState;
begin
  with AMachine do
  begin
Param1 := VarToInteger(GetInputArg(1));
IntToSet(Param2, VarToInteger(GetInputArg(2)), SizeOf(Param2));
    TfrmIBRestoreEditor(CurrentObject).sgDatabaseFilesKeyDown(TObject(VarToObject(GetInputArg(0))),Param1,Param2);
    SetInputArg(1,Integer(Param1));
  end;
end;

procedure TatIBRestoreEditorLibrary.__TfrmIBRestoreEditorsgDatabaseFilesSelectCell(AMachine: TatVirtualMachine);
  var
  Param3: Boolean;
begin
  with AMachine do
  begin
Param3 := GetInputArg(3);
    TfrmIBRestoreEditor(CurrentObject).sgDatabaseFilesSelectCell(TObject(VarToObject(GetInputArg(0))),VarToInteger(GetInputArg(1)),VarToInteger(GetInputArg(2)),Param3);
    SetInputArg(3,Param3);
  end;
end;

procedure TatIBRestoreEditorLibrary.__TfrmIBRestoreEditorFormCreate(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TfrmIBRestoreEditor(CurrentObject).FormCreate(TObject(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatIBRestoreEditorLibrary.__TfrmIBRestoreEditorCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TfrmIBRestoreEditorClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0))),TStrings(VarToObject(GetInputArg(1)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatIBRestoreEditorLibrary.__TfrmIBRestoreEditorGetStrings(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TfrmIBRestoreEditor(CurrentObject).GetStrings(TStrings(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatIBRestoreEditorLibrary.Init;
begin
  With Scripter.DefineClass(TfrmIBRestoreEditor) do
  begin
    DefineMethod('sgDatabaseFilesDrawCell',5,tkNone,nil,__TfrmIBRestoreEditorsgDatabaseFilesDrawCell,false,0,'Sender: TObject; ACol: Integer; ARow: Integer; Rect: TRect; State: TGridDrawState');
    DefineMethod('sgDatabaseFilesKeyDown',3,tkNone,nil,__TfrmIBRestoreEditorsgDatabaseFilesKeyDown,false,0,'Sender: TObject; Key: Word; Shift: TShiftState').SetVarArgs([1]);
    DefineMethod('sgDatabaseFilesSelectCell',4,tkNone,nil,__TfrmIBRestoreEditorsgDatabaseFilesSelectCell,false,0,'Sender: TObject; ACol: Integer; ARow: Integer; CanSelect: Boolean').SetVarArgs([3]);
    DefineMethod('FormCreate',1,tkNone,nil,__TfrmIBRestoreEditorFormCreate,false,0,'Sender: TObject');
    DefineMethod('Create',2,tkClass,TfrmIBRestoreEditor,__TfrmIBRestoreEditorCreate,true,0,'AOwner: TComponent; Values: TStrings');
    DefineMethod('GetStrings',1,tkNone,nil,__TfrmIBRestoreEditorGetStrings,false,0,'s: TStrings');
  end;
  With Scripter.DefineClass(ClassType) do
  begin
  end;
end;

class function TatIBRestoreEditorLibrary.LibraryName: string;
begin
  result := 'IBRestoreEditor';
end;

initialization
  RegisterScripterLibrary(TatIBRestoreEditorLibrary, True);

{$WARNINGS ON}

end.

