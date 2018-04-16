unit uUtils;

interface

uses
{$IFDEF MSWINDOWS}
    Winapi.Windows
{$ELSE}
    Macapi.AppKit
{$ENDIF}
    , ComCtrls
//    , sRichEdit
//    , vcl.Controls
    , System.Classes
    , Dialogs
//    , Vcl.Graphics
    , GraphUtil
    , Variants
    , Registry
    , Jpeg
    , pngimage
    , GIFImg
    , IOUtils
    , Data.DB
    , ImgList
    , kbmMemTable
//    , Vcl.Forms
    , TypInfo
    , Generics.Defaults
    ;

type
  TIntValue = class
    fvalue : integer;
  public
    constructor Create(value : integer);
  end;

  TCaseInsensitiveEqualityComparer = class(TEqualityComparer<string>)
  public
    function Equals(const Left, Right: string): Boolean; override;
    function GetHashCode(const Value: string): Integer; override;
  end;

  TMouseBtnType = (_mbLeft, _mbMiddle, _mbRight);

const
  MOUSE_BTN_VKEYS: Array [TMouseBtnType] of Integer = (VK_LBUTTON, VK_MBUTTON, VK_RBUTTON);


function CreateAGUID : String;
function simpleTextTosimpleHtml(_text : String) : String;
function ComputerName:String;
function GetMIMEtype(FileName:String):String;
function ReplaceString(original, toReplace, replaceWith : String) : String;
//function FloatToXml(Value : Double; decimals : Integer) : String;
function IndexOfArray(Items: array of String; const Value: String; defaultResult : Integer = -1): Integer;
function Split(Text : String; Delimiter : String) : TStringList;
function SplitStringToTStrings(const aSeparator, aString: String; aMax: Integer = 0): TStringList;
procedure parseFirstAndLastNameFromFullname(Fullname : String; var firstName : String; var lastName : String);

function iif(condition : Boolean; TrueResult : String; FalseResult : String) : String; overload;
function iif(condition : Boolean; TrueResult : Integer; FalseResult : Integer) : Integer; overload;
function iif(condition : Boolean; TrueResult : Double; FalseResult : Double) : Double; overload;
function iif(condition : Boolean; TrueResult : Boolean; FalseResult : Boolean) : Boolean; overload;

// DateTime value back in one line
function IIF(Condition : Boolean; Alfa, Beta : TdateTime) : TdateTime; overload;

procedure DuplicateCurrentRow(Dataset:Tdataset);

procedure DeleteFileWithWildcard(Path: string; files : String);
procedure GetFileList(FileList: TStrings; Path: string; files : String = '*.*');

function DoubleQuoteIfNeeded(s : String) : String;
//function CorrectDecimalSeparator(s : String) : String;
//function RoomerStrToFloat(s : String) : Double;
function ZerosInFront(s : String; toLength : Integer) : String;
function SecondsSinceMidnight : integer;
function MinutesSinceMidnight : integer;
function Month(ADate : TDateTime) : Integer;
function Year(ADate : TDateTime) : Integer;
function DayOfMonth(ADate : TDateTime) : Integer;
function Str2Bool(s : String) : Boolean;
function Bool2Str(b : Boolean) : String;
procedure DebugMessage(const Str: string);
procedure CopyToClipboard(const Str: string; iDelayMs: integer = 500);
function ClipboardText : String;
function ClipboardHasFormat(format : Word) : Boolean;

//{$IFNDEF ROOMER_UTIL}{$IFNDEF RBE_BUILD}function AuthenticateAgainstWindows(login, password, domain: string;
//  var token: THandle; var msg: string): Boolean;{$ENDIF}{$ENDIF}

function ParameterByName(name: String): String;

procedure SaveToTextFile(filename, data : String);
procedure SaveToUtf8TextFile(filename, data : String);
procedure AddToTextFile(filename, data : String);
function ReadFromTextFile(filename : String) : String;
function SetFileDateTime(Const FileName : String; Const FileDate : TDateTime): Boolean;
function GetFileTimeStampUTC(filename : String) : TDateTime;

procedure DeleteRegistryLocation(location : String);
function ReadStringValueFromAnyRegistry(location, key, defaultValue : String) : String;
procedure WriteStringValueToAnyRegistry(location, key, value : String);

function ReadStringValueFromAppRegistry(user, key, defaultValue : String) : String;
procedure WriteStringValueToAppRegistry(user, key, value : String);

function IsCapsLockOn : Boolean;
function IsControlKeyPressed: Boolean;
function IsAltKeyPressed: Boolean;
function IsShiftKeyPressed: Boolean;

function StringToHex(S: String): string;
function HexToString(H: String): String;
procedure Hex2Bin(HexStr : String; BinStream : TMemoryStream);
function Bin2Hex(BinStream : TMemoryStream) : String;
function IsMouseBtnSwapped: Boolean;
function IsMouseBtnDown(const AMouseBtn: TMouseBtnType): Boolean;
function IsAnyMouseBtnDown: Boolean;
function RoundTo(value, smallest_unit : extended) : extended;
function Capitalize(const s: string): string;

function ConvertToReadableText(s: string): string;
function ConvertToEncion(s: string): string;
function ConvertFromEncion(s: string): string;

procedure CloseWindowToRight(handle : THandle);
procedure OpenWindowFromRight(handle : THandle);
procedure LoadKbmMemtableFromDataSetQuiet(kbmTable : TkbmCustomMemTable; Source:TDataSet; CopyOptions:TkbmMemTableCopyTableOptions);

function GetEnumAsString(enum : PTypeInfo; value : Integer) : String;

function JoinStrings(list : TStrings; Delimiter : Char; QuoteChar : Char = '''') : String;
function JoinStringsNoQuote(list : TStrings; Delimiter : Char) : String;
procedure SplitString(text : String; list : TStrings; Delimiter : Char; QuoteChar : Char = '''');
function linuxLFCRToWindows(source : String) : String;

function ComponentRunning(aComponent: TComponent): boolean;
function RunningInMainThread: boolean;

function GetOwnerOfType(aComp: TComponent; aClassType: TClass): TComponent;
function FindChildComponentOfType(aComp: TComponent; aClassType: TClass): TComponent;


function StringIndexInSet(Selector : string; CaseList: array of string): Integer;

implementation

uses System.SysUtils, clipbrd, uFloatUtils;

function linuxLFCRToWindows(source : String) : String;
begin
  result := ReplaceString(ReplaceString(source, '\n', #10), '\r', #13);
end;

function StringIndexInSet(Selector : string; CaseList: array of string): Integer;
var cnt: integer;
begin
  Result:=-1;
  for cnt := 0 to Length(CaseList)-1 do
  begin
    if CompareText(Selector, CaseList[cnt]) = 0 then
    begin
      Result:=cnt;
      Break;
    end;
  end;
end;

function JoinStrings(list : TStrings; Delimiter : Char; QuoteChar : Char = '''') : String;
begin
  list.Delimiter := Delimiter;
  list.QuoteChar := QuoteChar;
  result := list.CommaText;
end;

function JoinStringsNoQuote(list : TStrings; Delimiter : Char) : String;
var
  i: Integer;
begin
  result := '';
  for i := 0 to list.Count - 1 do
    result := result + IIF(result = '', '', Delimiter) + list[i];
end;

procedure SplitString(text : String; list : TStrings; Delimiter : Char; QuoteChar : Char = '''');
begin
  Assert(Assigned(list));
  list.Clear;
  list.Delimiter := Delimiter;
  list.QuoteChar := QuoteChar;
  list.StrictDelimiter := True; // needed otherwise whitespace is used to delimit
  list.DelimitedText := text;
end;

function iif(condition : Boolean; TrueResult : String; FalseResult : String) : String;
begin
  if condition then
    result := TrueResult
  else
    result := FalseResult;
end;

function iif(condition : Boolean; TrueResult : Integer; FalseResult : Integer) : Integer;
begin
  if condition then
    result := TrueResult
  else
    result := FalseResult;
end;

function iif(condition : Boolean; TrueResult : Double; FalseResult : Double) : Double;
begin
  if condition then
    result := TrueResult
  else
    result := FalseResult;
end;

function iif(condition : Boolean; TrueResult : Boolean; FalseResult : Boolean) : Boolean;
begin
  if condition then
    result := TrueResult
  else
    result := FalseResult;
end;

// DateTime value back in one line
function IIF(Condition : Boolean; Alfa, Beta : TdateTime) : TdateTime; overload;
begin
  if Condition then
    Result := Alfa
  else
    Result := Beta;
end;

function GetEnumAsString(enum : PTypeInfo; value : Integer) : String;
begin
  result  := GetEnumName(enum,value) ;
end;

procedure LoadKbmMemtableFromDataSetQuiet(kbmTable : TkbmCustomMemTable; Source:TDataSet; CopyOptions:TkbmMemTableCopyTableOptions);
begin
  kbmTable.LoadFromDataSet(Source, CopyOptions);
end;

procedure CloseWindowToRight(handle : THandle);
begin
  AnimateWindow(Handle, 400, AW_HOR_POSITIVE OR AW_SLIDE OR AW_HIDE);
end;

procedure OpenWindowFromRight(handle : THandle);
begin
  AnimateWindow(Handle, 400, AW_HOR_NEGATIVE OR AW_SLIDE OR AW_ACTIVATE);
end;

function RoundTo(value, smallest_unit : extended) : extended;
begin
  result := Round(value / smallest_unit) * smallest_unit;
end;

function CreateAGUID : String;
var Uid: TGuid;
    Res: HResult;
begin
  Res := CreateGuid(Uid);
  result := '';
  if Res = S_OK then
   result := GuidToString(Uid);
end;

function simpleTextTosimpleHtml(_text : String) : String;
begin
  result := ConvertToEncion(
              StringReplace(
                StringReplace(
                  StringReplace(
                    StringReplace(
                      StringReplace(
                          StringReplace(
                            _text,
                        #10, '', [rfReplaceAll, rfIgnoreCase]),
                      '&', '&amp;', [rfReplaceAll, rfIgnoreCase]),
                    ' ', '&nbsp;', [rfReplaceAll, rfIgnoreCase]),
                  '<', '&lt;', [rfReplaceAll, rfIgnoreCase]),
                '>', '&gt;', [rfReplaceAll, rfIgnoreCase]),
              #13, '<br>', [rfReplaceAll, rfIgnoreCase])
            );
end;

function ReplaceString(original, toReplace, replaceWith : String) : String;
begin
  result := StringReplace(original, toReplace, replaceWith, [rfReplaceAll, rfIgnoreCase]);
end;

function IndexOfArray(Items: array of String; const Value: String; defaultResult : Integer = -1): Integer;
var
  i: Integer;
begin
  Result := defaultResult;
  for i := Low(Items) to High(Items) do
  begin
    if AnsiSameText(Value, Items[i]) then
    begin
      Result := i;
      Break;
    end;
  end;
end;

procedure parseFirstAndLastNameFromFullname(Fullname : String; var firstName : String; var lastName : String);
var s : String;
    strings : TStrings;
    i : Integer;
begin
  s := ReplaceString(fullname, '  ', ' ');
  strings := SplitStringToTStrings(' ', s);
  try
    firstName := Fullname;
    lastName := '';
    if strings.Count > 1 then
    begin
      lastName := strings[strings.count - 1];
      firstName := '';
      for i := 0 to strings.count - 2 do
        firstName := firstName + ' ' + strings[i];
    end;
  finally
    strings.Free;
  end;
end;

function Split(Text : String; Delimiter : String) : TStringList;
begin
  result := TStringList.Create;
  result.Text := StringReplace(Text, Delimiter, #13#10, [rfReplaceAll]);
end;

function SplitStringToTStrings(const aSeparator, aString: String; aMax: Integer = 0): TStringList;
var
  strt: Integer;
  s, sTemp : String;
begin
  s := aString;
  result := TStringList.Create;
  if s<>'' then
  begin
    if pos(aSeparator, s) = 0 then
      result.Add(s)
    else
    begin
      s := s + aSeparator;
      strt := pos(aSeparator, s);
      while strt > 0 do
      begin
        sTemp := copy(s, 1, strt - 1);
        result.Add(sTemp);
        s := copy(s, strt + length(aSeparator), length(s));
        strt := pos(aSeparator, s);
      end;
    end;
  end;
end;

function ComputerName:String;
var
  ComputerName: Array [0 .. 256] of char;
  Size: DWORD;
begin
  Size := 256;
  GetComputerName(ComputerName, Size);
  Result := ComputerName;
end;

function GetMIMEtype(FileName:String):String;
var
  reg:TRegistry;
  ans:String;
  ext:string;
begin
  if LowerCase(ExtractFileExt(FileName)) = '.pdf' then
  begin
    result := 'application/pdf';
    exit;
  end;

  ans := '';
  reg := TRegistry.Create;
  try
    ext := ExtractFileExt(FileName);
    if ext <> '' then
    begin
      reg.RootKey := HKEY_LOCAL_MACHINE;
      if reg.OpenKeyReadOnly('\SOFTWARE\Classes\' + ext + '\') then
        ans := reg.ReadString('Content Type');
    end;
  finally
    reg.Free;
  end;

  if ans = '' then
    ans := 'application/octet-stream';
  result := ans;
end;

function Capitalize(const s: string): string;
var
  flag: Boolean;
  I:    Byte;
begin
  if s <> '' then
    begin
      flag  := true;
      result     := '';
      for I := 1 to Length(s) do
        begin
          if flag then
            result := result + UpperCase(s [ I ] )
          else
            result  := result + LowerCase(s [ I ] );
          flag := ((s [ I ] = ' ') or (s [ I ] = '-'))
        end;
    end
  else
    result    := '';
  result := result;
end;

procedure DuplicateCurrentRow(Dataset:Tdataset);
var
  aField : Variant;
  i      : Integer;
begin
  // Create a variant Array
  aField := VarArrayCreate([0, DataSet.Fieldcount-1], VarVariant);
  // read values into the array
  for i := 0 to (DataSet.Fieldcount-1) do
  begin
     aField[i] := DataSet.fields[i].Value ;
  end;
  DataSet.Insert ;
  // Put array values into new the record
  for i := 0 to (DataSet.Fieldcount-1) do
  begin
     if (DataSet.fields[i].CanModify) then
      DataSet.fields[i].Value := aField[i];
  end;
end;

procedure GetFileList(FileList: TStrings; Path: string; files : String = '*.*');
var
  SR: TSearchRec;
begin
  if FindFirst(TPath.Combine(Path, files), faAnyFile, SR) = 0 then
  begin
    repeat
      if (SR.Attr <> faDirectory) then
      begin
        FileList.Add(SR.Name);
      end;
    until FindNext(SR) <> 0;
    FindClose(SR);
  end;
end;

procedure DeleteFileWithWildcard(Path: string; files : String);
var
  SR: TSearchRec;
  FileList : TStrings;
  i: Integer;
begin
  FileList := TStringList.Create;
  try
  if FindFirst(TPath.Combine(Path, files), faAnyFile, SR) = 0 then
  begin
    repeat
      if (SR.Attr <> faDirectory) then
      begin
        FileList.Add(SR.Name);
      end;
    until FindNext(SR) <> 0;
    FindClose(SR);

    for i := 0 to FileList.Count - 1 do
      DeleteFile(TPath.Combine(Path, FileList[i]));
  end;
  finally
    FileList.Free;
  end;
end;

function DoubleQuoteIfNeeded(s : String) : String;
begin
  if POS(' ', s) > 0 then
    result := '"' + s + '"'
  else
    result := s;
end;

//function CorrectDecimalSeparator(s : String) : String;
//begin
//  result := StringReplace(StringReplace(s, '.', FormatSettings.DecimalSeparator, []), ',', FormatSettings.DecimalSeparator, []);
//end;
//
//function RoomerStrToFloat(s : String) : Double;
//begin
//  result := StrToFloat(CorrectDecimalSeparator(s));
//end;

function ZerosInFront(s : String; toLength : Integer) : String;
begin
  result := StringOfChar('0', toLength - length(s)) + s;
end;

function SecondsSinceMidnight : integer;
var
  wHour, wMin, wSec, wMSec : Word;
begin
  DecodeTime(Now, wHour, wMin, wSec, wMSec);
  result := wHour * 3600 + wMin * 60 + wSec;
end;

function MinutesSinceMidnight : integer;
var
  wHour, wMin, wSec, wMSec : Word;
begin
  DecodeTime(Now, wHour, wMin, wSec, wMSec);
  result := wHour * 60 + wMin;
end;

function Month(ADate : TDateTime) : Integer;
var y, m, d : Word;
begin
  decodeDate(ADate, y, m, d);
  result := m;
end;

function Year(ADate : TDateTime) : Integer;
var y, m, d : Word;
begin
  decodeDate(ADate, y, m, d);
  result := y;
end;

function DayOfMonth(ADate : TDateTime) : Integer;
var y, m, d : Word;
begin
  decodeDate(ADate, y, m, d);
  result := d;
end;

function ParameterByName(name: String): String;
var
  i, iNameLength: Integer;
  param: String;
begin
  Result := '';
  for i := 1 to ParamCount do
  begin
    // example=value
    // 1234567890123
    // ==> Name length = 7 + 1 = 8
    // Value location = Name length + 1 = 9
    iNameLength := length(name) + 1;
    param := ParamStr(i);
    if Lowercase(copy(param, 1, iNameLength)) = Lowercase(name) + '=' then
    begin
      Result := copy(param, iNameLength + 1, length(param));
    end;
  end;
end;

function Bool2Str(b : Boolean) : String;
begin
  if b then
    result := '1'
  else
    result := '0';
end;

function Str2Bool(s : String) : Boolean;
begin
  result := (s = '1') OR (s = '-1') OR (lowercase(s) = 'true');
end;

function ReadStringValueFromAnyRegistry(location, key, defaultValue : String) : String;
var
  RegistryEntry: TRegistry;
  RegistryKey : String;
begin
  RegistryKey := location;
  RegistryEntry := TRegistry.Create(KEY_READ or KEY_WOW64_64KEY);
  try
    RegistryEntry.RootKey := HKEY_CURRENT_USER;
    if (not RegistryEntry.KeyExists(RegistryKey)) then
    begin
      RegistryEntry.Access := KEY_WRITE or KEY_WOW64_64KEY;
      if RegistryEntry.OpenKey(RegistryKey, true) then
        RegistryEntry.WriteString(key, defaultValue);
      result := defaultValue;
    end
    else
    begin
      RegistryEntry.Access := KEY_READ or KEY_WOW64_64KEY;
      if RegistryEntry.OpenKey(RegistryKey, false) then
      begin
        result := RegistryEntry.ReadString(key);
      end;
    end;
    RegistryEntry.CloseKey();
  finally
    RegistryEntry.Free;
  end;
end;

procedure DeleteRegistryLocation(location : String);
var
  RegistryEntry: TRegistry;
  RegistryKey : String;
begin
  RegistryKey := location;
  RegistryEntry := TRegistry.Create(KEY_ALL_ACCESS or KEY_WOW64_64KEY);
  try
    RegistryEntry.RootKey := HKEY_CURRENT_USER;
    if RegistryEntry.OpenKey(RegistryKey, true) then
    begin
        RegistryEntry.CloseKey();
    end;
    RegistryEntry.DeleteKey(RegistryKey);
  finally
    RegistryEntry.Free;
  end;
end;

procedure WriteStringValueToAnyRegistry(location, key, value : String);
var
  RegistryEntry: TRegistry;
  RegistryKey : String;
begin
  RegistryKey := location;
  RegistryEntry := TRegistry.Create(KEY_WRITE or KEY_WOW64_64KEY);
  try
    RegistryEntry.RootKey := HKEY_CURRENT_USER;
    if RegistryEntry.OpenKey(RegistryKey, true) then
    begin
        RegistryEntry.WriteString(key, value);
        RegistryEntry.CloseKey();
    end;
  finally
    RegistryEntry.Free;
  end;
end;



function ReadStringValueFromAppRegistry(user, key, defaultValue : String) : String;
Const
  C_KEY='Software\Roomer\SavedValues\user_%s';
var
  RegistryEntry: TRegistry;
  RegistryKey : String;
begin
  RegistryKey := format(C_KEY, [user]);
  RegistryEntry := TRegistry.Create(KEY_READ or KEY_WOW64_64KEY);
  try
    RegistryEntry.RootKey := HKEY_CURRENT_USER;
     RegistryEntry.Access := KEY_WRITE OR KEY_READ OR KEY_WOW64_64KEY;

    // Create Key if not existing.
    if (not RegistryEntry.KeyExists(RegistryKey)) then
    begin
      if RegistryEntry.OpenKey(RegistryKey, true) then
        RegistryEntry.CloseKey;
    end;

    if RegistryEntry.OpenKey(RegistryKey, false) then
    begin
      result := RegistryEntry.ReadString(key);
      if result = '' then
        result := defaultValue;
      RegistryEntry.CloseKey();
    end;

  finally
    RegistryEntry.Free;
  end;
end;

procedure WriteStringValueToAppRegistry(user, key, value : String);
Const
  C_KEY='Software\Roomer\SavedValues\user_%s';
var
  RegistryEntry: TRegistry;
  RegistryKey : String;
begin
  RegistryKey := format(C_KEY, [user]);
  RegistryEntry := TRegistry.Create(KEY_WRITE or KEY_WOW64_64KEY);
  try
    RegistryEntry.RootKey := HKEY_CURRENT_USER;
    if RegistryEntry.OpenKey(RegistryKey, true) then
    begin
        RegistryEntry.WriteString(key, value);
        RegistryEntry.CloseKey();
    end;
  finally
    RegistryEntry.Free;
  end;
end;

function IsCapsLockOn : Boolean;
var
    KeyState: TKeyboardState;
begin
  GetKeyboardState(KeyState) ;
  result := (KeyState[VK_CAPITAL] <> 0);
end;

function IsControlKeyPressed: Boolean;
begin
{$IFDEF MSWINDOWS}
  Result := GetKeyState(VK_CONTROL) < 0;
{$ELSE}
  Result := NSControlKeyMask and TNSEvent.OCClass.modifierFlags =
    NSControlKeyMask;
{$ENDIF}
end;

function IsAltKeyPressed: Boolean;
begin
{$IFDEF MSWINDOWS}
  Result := (GetKeyState(VK_LMENU) < 0) OR (GetKeyState(VK_RMENU) < 0);
{$ENDIF}
end;

function IsShiftKeyPressed: Boolean;
begin
{$IFDEF MSWINDOWS}
  Result := GetKeyState(VK_SHIFT) < 0;
{$ELSE}
  Result := NSShiftKeyMask and TNSEvent.OCClass.modifierFlags = NSShiftKeyMask;
{$ENDIF}
end;


//{$IFNDEF ROOMER_UTIL}
//{$IFNDEF RBE_BUILD}
//function AuthenticateAgainstWindows(login, password, domain: string;
//  var token: THandle; var msg: string): Boolean;
//var
//  error: Integer;
//begin
//  Result := false;
//  msg := '';
//  if (login = '') then
//  begin
//   // msg := 'Please enter a login.';
//	  msg := GetTranslatedText('shTx_Utils_EnterLogin');
//    exit;
//  end;
//  if (password = '') then
//  begin
//   // msg := 'Password can''t be empty.You must enter a password.';
//	  msg := GetTranslatedText('shTx_Utils_MustEnterPassword');
//    exit;
//  end;
//  Result := LogonUser(PChar(login), PChar(domain), PChar(password),
//    LOGON32_LOGON_INTERACTIVE, // first check interactive
//    LOGON32_PROVIDER_DEFAULT, token);
//  if not Result then
//  begin
//    Result := LogonUser(PChar(login), PChar(domain), PChar(password),
//      LOGON32_LOGON_NETWORK, // then check against network
//      LOGON32_PROVIDER_DEFAULT, token);
//  end;
//  if not Result then
//  begin
//    error := GetLastError;
//    msg := SysErrorMessage(error);
//  end;
//end;
//{$ENDIF}
//{$ENDIF}

function GetCurrentUserName: string;
const cnMaxUserNameLen = 254;
var sUserName: string;
    dwUserNameLen: DWORD;
begin
  dwUserNameLen := cnMaxUserNameLen - 1;
  SetLength(sUserName, cnMaxUserNameLen);
  GetUserName(PChar(sUserName), dwUserNameLen);
  SetLength(sUserName, dwUserNameLen);
  Result := sUserName;
end;

//function SystemThousandsSeparator : string;
//var Thousands : PChar;
//begin
//  Thousands := StrAlloc(10);
//  GetLocaleInfo(LOCALE_SYSTEM_DEFAULT, LOCALE_STHOUSAND, Thousands, 10);
//  result := String(Thousands)[1];
//end;

procedure DebugMessage(const Str: string);
begin
{$IFDEF DEBUG}
  ShowMessage(Str);
{$ENDIF}
end;


procedure CopyToClipboard(const Str: string; iDelayMs: integer = 500);
begin
{$IFDEF DEBUG}
  Clipboard.AsText:= Str;
{$ENDIF}
end;

function ClipboardText : String;
begin
  result := Clipboard.AsText;
end;

function ClipboardHasFormat(format : Word) : Boolean;
begin
  result := clipboard.HasFormat(format);
end;


function StringToHex(S: String): string;
var I: Integer;
begin
  Result:= '';
  for I := 1 to length (S) do
    Result:= Result+IntToHex(ord(S[i]),2);
end;

function HexToString(H: String): String;
var I: Integer;
begin
  Result:= '';
  for I := 1 to length (H) div 2 do
    Result:= Result+Char(StrToInt('$'+Copy(H,(I-1)*2+1,2)));
end;

procedure Hex2Bin(HexStr : String; BinStream : TMemoryStream);
begin
  BinStream.Size := Length(HexStr) div 2;
  if BinStream.Size > 0 then
  begin
    HexToBin(PChar(HexStr), BinStream.Memory, BinStream.Size);
    BinStream.Position := 0;
  end;
end;

function Bin2Hex(BinStream : TMemoryStream) : String;
begin
  SetLength(Result, BinStream.Size * 2);
  if BinStream.Size > 0 then
  begin
    BinToHex(BinStream.Memory, PChar(result), BinStream.Size);
  end;
end;

(* This function returns true if the mouse buttons are swapped *)
function IsMouseBtnSwapped: Boolean;
begin
  Result := GetSystemMetrics(SM_SWAPBUTTON) <> 0;
end;

(* This function returns true when the specified mouse button is pressed *)
function IsMouseBtnDown(const AMouseBtn: TMouseBtnType): Boolean;
var MouseBtnCorrected: TMouseBtnType;
begin
  MouseBtnCorrected := AMouseBtn;
  if IsMouseBtnSwapped then
  begin
    if MouseBtnCorrected = _mbLeft then
      MouseBtnCorrected := _mbRight
    else
    if MouseBtnCorrected = _mbRight then
      MouseBtnCorrected := _mbLeft;
  end;

  Result := GetAsyncKeyState(MOUSE_BTN_VKEYS[MouseBtnCorrected])
            AND $8000 <> 0;
end;


(* This function returns true when any of the mouse button is pressed *)
function IsAnyMouseBtnDown: Boolean;
begin
  Result := (GetAsyncKeyState(VK_LBUTTON)
             OR GetAsyncKeyState(VK_MBUTTON)
             OR GetAsyncKeyState(VK_RBUTTON)
             )
            AND $8000 <> 0;
end;

procedure SaveToTextFile(filename, data : String);
var stl : TStringList;
begin
  stl := TStringList.Create;
  try
    stl.Text := data;
    stl.SaveToFile(filename);
  finally
    stl.Free;
  end;
end;

procedure SaveToUtf8TextFile(filename, data : String);
const      // surrogate bytes
   Clef = #$5B + #$D834 + #$DD1E + #$5D;
var
  F: Text;
  B: Byte;
begin
  Assign(F, filename);
  Rewrite(f);
  for B in TEncoding.UTF8.GetPreamble do write(f, AnsiChar(B));
  writeln(f, UTF8String(data));
  Close(f);
end;

procedure AddToTextFile(filename, data : String);
var
  myFile : TextFile;
begin
  // If the file exists then append to the file, otherwise create a new file for writing
  AssignFile(myFile, filename);
  if FileExists(filename) then
    Append(myFile)
  else
    ReWrite(myFile);
  try
    Writeln(myFile, data);
  finally
    // Close the file for the last time
    CloseFile(myFile);
  end;
end;

function ReadFromTextFile(filename : String) : String;
var stl : TStringList;
begin
  result := '';
  if FileExists(filename) then
  begin
    stl := TStringList.Create;
    try
      stl.LoadFromFile(filename);
      result := stl.Text;
    finally
      stl.Free;
    end;
  end;
end;

function SetFileDateTime(Const FileName : String; Const FileDate : TDateTime): Boolean;
var
  FileHandle : THandle;
  FileSetDateResult : Integer;
begin
  Result := False;
  FileHandle := FileOpen(FileName, fmOpenWrite OR fmShareDenyNone) ;
  try
    try
      if FileHandle > 0 Then
      begin
       FileSetDateResult :=
         FileSetDate(
           FileHandle,
           DateTimeToFileDate(FileDate)) ;
         result := (FileSetDateResult = 0) ;
      end;
    except
      Result := False;
    end;
  finally
    FileClose (FileHandle) ;
  end;
end;

function GetFileTimeStampUTC(filename : String) : TDateTime;
var
  fad: TWin32FileAttributeData;
  SystemTime: TSystemTime;
begin
  result := 0;
  if FileExists(filename) then
  begin
    if not GetFileAttributesEx(PChar(FileName), GetFileExInfoStandard, @fad) then
      RaiseLastOSError;
    if not FileTimeToSystemTime(fad.ftLastWriteTime, SystemTime) then
      RaiseLastOSError;
    Result := SystemTimeToDateTime(SystemTime);
  end;
end;

type
  TEncions = packed record
    A: String;
    B: String;
  end;

function ConvertToReadableText(s: string): string;
var
  i: Integer;
begin
  Result := s;
  for i := 127 to 255 do
    Result := StringReplace(Result, chr(i), '&#' + inttostr(i) + ';', [rfReplaceAll, rfIgnoreCase]);
end;

const
Encions: array [0..97] of TEncions =
  (
//(A: '"'; B: '&quot;'),
//(A: '''; B: '&apos;'),
//(A: '&'; B: '&amp;'),
//(A: '<'; B: '&lt;'),
//(A: '>'; B: '&gt;'),
(A: '  '; B: '&nbsp;&nbsp;'),
(A: '€'; B: '&euro;'),
(A: '`'; B: '&#96;'),
(A: '¡'; B: '&iexcl;'),
(A: '¢'; B: '&cent;'),
(A: '£'; B: '&pound;'),
(A: '¤'; B: '&curren;'),
(A: '¥'; B: '&yen;'),
(A: '¦'; B: '&brvbar;'),
(A: '§'; B: '&sect;'),
(A: '¨'; B: '&uml;'),
(A: '©'; B: '&copy;'),
(A: 'ª'; B: '&ordf;'),
(A: '«'; B: '&laquo;'),
(A: '¬'; B: '&not;'),
(A: '­'; B: '&shy;'),
(A: '®'; B: '&reg;'),
(A: '¯'; B: '&macr;'),
(A: '°'; B: '&deg;'),
(A: '±'; B: '&plusmn;'),
(A: '²'; B: '&sup2;'),
(A: '³'; B: '&sup3;'),
(A: '´'; B: '&acute;'),
(A: 'µ'; B: '&micro;'),
(A: '¶'; B: '&para;'),
(A: '·'; B: '&middot;'),
(A: '¸'; B: '&cedil;'),
(A: '¹'; B: '&sup1;'),
(A: 'º'; B: '&ordm;'),
(A: '»'; B: '&raquo;'),
(A: '¼'; B: '&frac14;'),
(A: '½'; B: '&frac12;'),
(A: '¾'; B: '&frac34;'),
(A: '¿'; B: '&iquest;'),
(A: '×'; B: '&times;'),
(A: '÷'; B: '&divide;'),
(A: 'À'; B: '&Agrave;'),
(A: 'Á'; B: '&Aacute;'),
(A: 'Â'; B: '&Acirc;'),
(A: 'Ã'; B: '&Atilde;'),
(A: 'Ä'; B: '&Auml;'),
(A: 'Å'; B: '&Aring;'),
(A: 'Æ'; B: '&AElig;'),
(A: 'Ç'; B: '&Ccedil;'),
(A: 'È'; B: '&Egrave;'),
(A: 'É'; B: '&Eacute;'),
(A: 'Ê'; B: '&Ecirc;'),
(A: 'Ë'; B: '&Euml;'),
(A: 'Ì'; B: '&Igrave;'),
(A: 'Í'; B: '&Iacute;'),
(A: 'Î'; B: '&Icirc;'),
(A: 'Ï'; B: '&Iuml;'),
(A: 'Ð'; B: '&ETH;'),
(A: 'Ñ'; B: '&Ntilde;'),
(A: 'Ò'; B: '&Ograve;'),
(A: 'Ó'; B: '&Oacute;'),
(A: 'Ô'; B: '&Ocirc;'),
(A: 'Õ'; B: '&Otilde;'),
(A: 'Ö'; B: '&Ouml;'),
(A: 'Ø'; B: '&Oslash;'),
(A: 'Ù'; B: '&Ugrave;'),
(A: 'Ú'; B: '&Uacute;'),
(A: 'Û'; B: '&Ucirc;'),
(A: 'Ü'; B: '&Uuml;'),
(A: 'Ý'; B: '&Yacute;'),
(A: 'Þ'; B: '&THORN;'),
(A: 'ß'; B: '&szlig;'),
(A: 'à'; B: '&agrave;'),
(A: 'á'; B: '&aacute;'),
(A: 'â'; B: '&acirc;'),
(A: 'ã'; B: '&atilde;'),
(A: 'ä'; B: '&auml;'),
(A: 'å'; B: '&aring;'),
(A: 'æ'; B: '&aelig;'),
(A: 'ç'; B: '&ccedil;'),
(A: 'è'; B: '&egrave;'),
(A: 'é'; B: '&eacute;'),
(A: 'ê'; B: '&ecirc;'),
(A: 'ë'; B: '&euml;'),
(A: 'ì'; B: '&igrave;'),
(A: 'í'; B: '&iacute;'),
(A: 'î'; B: '&icirc;'),
(A: 'ï'; B: '&iuml;'),
(A: 'ð'; B: '&eth;'),
(A: 'ñ'; B: '&ntilde;'),
(A: 'ò'; B: '&ograve;'),
(A: 'ó'; B: '&oacute;'),
(A: 'ô'; B: '&ocirc;'),
(A: 'õ'; B: '&otilde;'),
(A: 'ö'; B: '&ouml;'),
(A: 'ø'; B: '&oslash;'),
(A: 'ù'; B: '&ugrave;'),
(A: 'ú'; B: '&uacute;'),
(A: 'û'; B: '&ucirc;'),
(A: 'ü'; B: '&uuml;'),
(A: 'ý'; B: '&yacute;'),
(A: 'þ'; B: '&thorn;'),
(A: 'ÿ'; B: '&yuml;'));

function ConvertToEncion(s: string): string;
var
  i: Integer;
begin
  Result := s;
  for i := Low(Encions) to High(Encions) do
    Result := StringReplace(Result, Encions[i].A, Encions[i].B, [rfReplaceAll]);
end;

function ConvertFromEncion(s: string): string;
var
  i: Integer;
begin
  Result := s;
  for i := Low(Encions) to High(Encions) do
    Result := StringReplace(Result, Encions[i].B, Encions[i].A, [rfReplaceAll, rfIgnoreCase]);
end;

function ComponentRunning(aComponent: TComponent): boolean;
begin
  Result := (aComponent.ComponentState * [csLoading, csDestroying, csDesigning]) = [];
end;

function RunningInMainThread: boolean;
begin
  Result := (GetCurrentThreadId() = MainThreadID);
end;

function GetOwnerOfType(aComp: TComponent; aClassType: TClass): TComponent;
begin
  Result := aComp.Owner;
  while Assigned(Result) and (not result.ClassType.InheritsFrom(aClassType)) do
    Result := Result.Owner;
end;


function FindChildComponentOfType(aComp: TComponent; aClassType: TClass): TComponent;
var
  lComp: TComponent;
begin
  Result := nil;
  for lComp in aComp do
    if lComp.ClassType = aClassType then
    begin
      Result := lComp;
      Break;
    end;
end;



constructor TIntValue.Create(value: integer);
begin
  fvalue := value;
end;

function TCaseInsensitiveEqualityComparer.Equals(const Left, Right: string): Boolean;
begin
  Result := SameText(Left, Right);
end;

function TCaseInsensitiveEqualityComparer.GetHashCode(const Value: string): Integer;
var s: string;
begin
  s := UpperCase(Value);
  Result := BobJenkinsHash(s[1], Length(s) * SizeOf(s[1]), 0);
end;

/////////////////////////////////////////////////////////
//procedure SetSystemDecimalSeparator;
//begin
//  SystemDecimalSeparator := TFormatsettings.Create.DecimalSeparator;
//end;
//
//initialization
//  SetSystemDecimalSeparator;

end.
