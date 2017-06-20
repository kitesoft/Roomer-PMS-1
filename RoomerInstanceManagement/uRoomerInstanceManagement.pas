unit uRoomerInstanceManagement;

interface

uses Windows,
     Messages,
     SysUtils;

function InstanceAlreadyRunning : Boolean;

const SWindowClassName : String = 'OVERIDE_THIS_BEFORE_USING_INSTACE_ALREADY_RUNNING';

implementation

function IgnoreInstanceChecking : Boolean;
var i : Integer;
begin
  result := false;
  for i := 0 to ParamCount - 1 do
    if (LowerCase(ParamStr(i)) = 'ignore_instance_check') OR
       (LowerCase(ParamStr(i)) = 'iic') then
    begin
      result := true;
      Break;
    end;
end;

function InstanceAlreadyRunning : Boolean;
var
  i: Integer;
  Arg: string;
  Window: HWND;
  CopyDataStruct: TCopyDataStruct;
begin
  result := False;
  if IgnoreInstanceChecking then exit;

  Window := FindWindow(PCHAR(SWindowClassName), nil);
  if Window <> 0 then
  begin
    result := True;
    FillChar(CopyDataStruct, Sizeof(CopyDataStruct), 0);
    Arg := 'Starting second instance!';
    CopyDataStruct.cbData := (Length(Arg)+1)*SizeOf(Char);
    CopyDataStruct.lpData := PChar(Arg);
    SendMessage(Window, WM_COPYDATA, 0, NativeInt(@CopyDataStruct));
    SetForegroundWindow(Window);
  end;
end;

end.
