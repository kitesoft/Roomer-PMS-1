{***************************************************************************}
{ TMS Scripter Components for Delphi & C++Builder                           }
{                                                                           }
{ written by TMS Software                                                   }
{            copyright © 1997 - 2012                                        }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{                                                                           }
{ For information about version history, check the section "What's New"     }
{ at TMS Scripter manual.                                                   }
{                                                                           }
{ The source code is given as is. The author is not responsible             }
{ for any possible damage done due to the use of this code.                 }
{ The component can be freely used in any application. The complete         }
{ source code remains property of the author and may not be distributed,    }
{ published, given or sold in any form as such. No parts of the source      }
{ code can be included in any other component or application without        }
{ written authorization of the author.                                      }
{***************************************************************************}

unit uVBScriptLibrary;

{$I ASCRIPT.INC}

interface
uses
  SysUtils, Classes, TypInfo, atScript
  {$IFDEF MSWINDOWS}
  , Windows
  {$ENDIF}
  {$IFDEF DELPHI6_LVL}
  , Variants
  {$ENDIF}
  ;

type
  TatVBScriptLibrary = class(TatScripterLibrary)
  private
    procedure __Asc(AMachine: TatVirtualMachine);
    procedure __Atn(AMachine: TatVirtualMachine);
    procedure __CBool(AMachine: TatVirtualMachine);
    procedure __CByte(AMachine: TatVirtualMachine);
    procedure __CCur(AMachine: TatVirtualMachine);
    procedure __CDate(AMachine: TatVirtualMachine);
    procedure __CDbl(AMachine: TatVirtualMachine);
    procedure __CInt(AMachine: TatVirtualMachine);
    procedure __CreateObject(AMachine: TatVirtualMachine);
    procedure __CSng(AMachine: TatVirtualMachine);
    procedure __CStr(AMachine: TatVirtualMachine);
    procedure __DateValue(AMachine: TatVirtualMachine);
    procedure __Day(AMachine: TatVirtualMachine);
    procedure __Hex(AMachine: TatVirtualMachine);
    procedure __Hour(AMachine: TatVirtualMachine);
    procedure __InStr(AMachine: TatVirtualMachine);
    procedure __Fix(AMachine: TatVirtualMachine);
    procedure __Int(AMachine: TatVirtualMachine);
    procedure __IsArray(AMachine: TatVirtualMachine);
    procedure __IsDate(AMachine: TatVirtualMachine);
    procedure __IsEmpty(AMachine: TatVirtualMachine);
    procedure __IsNull(AMachine: TatVirtualMachine);
    procedure __IsNumeric(AMachine: TatVirtualMachine);
    procedure __LBound(AMachine: TatVirtualMachine);
    procedure __LCase(AMachine: TatVirtualMachine);
    procedure __UBound(AMachine: TatVirtualMachine);
    procedure __UCase(AMachine: TatVirtualMachine);
    procedure __Left(AMachine: TatVirtualMachine);
    procedure __Len(AMachine: TatVirtualMachine);
    procedure __Log(AMachine: TatVirtualMachine);
    procedure __LTrim(AMachine: TatVirtualMachine);
    procedure __RTrim(AMachine: TatVirtualMachine);
    procedure __Mid(AMachine: TatVirtualMachine);
    procedure __Minute(AMachine: TatVirtualMachine);
    procedure __Month(AMachine: TatVirtualMachine);
    procedure __MonthName(AMachine: TatVirtualMachine);
    procedure __Replace(AMachine: TatVirtualMachine);
    procedure __Right(AMachine: TatVirtualMachine);
    procedure __Rnd(AMachine: TatVirtualMachine);
    procedure __Second(AMachine: TatVirtualMachine);
    procedure __Sgn(AMachine: TatVirtualMachine);
    procedure __Space(AMachine: TatVirtualMachine);
    procedure __StrComp(AMachine: TatVirtualMachine);
    procedure __String(AMachine: TatVirtualMachine);
    procedure __Timer(AMachine: TatVirtualMachine);
    procedure __TimeSerial(AMachine: TatVirtualMachine);
    procedure __TimeValue(AMachine: TatVirtualMachine);
    procedure __Weekday(AMachine: TatVirtualMachine);
    procedure __WeekdayName(AMachine: TatVirtualMachine);
    procedure __Year(AMachine: TatVirtualMachine);
    procedure __DateSerial(AMachine: TatVirtualMachine);
    procedure __FormatNumber(AMachine: TatVirtualMachine);
    procedure __FormatCurrency(AMachine: TatVirtualMachine);
    procedure __FormatDateTime(AMachine: TatVirtualMachine);
    procedure __MsgBox(AMachine: TatVirtualMachine);
    procedure __InputBox(AMachine: TatVirtualMachine);
    procedure __DatePart(AMachine: TatVirtualMachine);
    {$IFNDEF NEWSTACK}
    procedure __Redim(AMachine: TatVirtualMachine);
    procedure __RedimPreserve(AMachine: TatVirtualMachine);
    procedure __Split(AMachine: TatVirtualMachine);
    procedure __Join(AMachine: TatVirtualMachine);
    {$ENDIF}
    procedure __StrReverse(AMachine: TatVirtualMachine);
    procedure __Randomize(AMachine: TatVirtualMachine);
  protected
    procedure Init; override;
  public
    class function LibraryName: string; override;
  end;

implementation
uses
  Math
  {$IFDEF MSWINDOWS}
  ,ComObj
  {$ENDIF}
  ;

{TatVBScriptLibrary}

const
  {FormatDateTime constants}
  vbGeneralDate = 0;
  vbLongDate = 1;
  vbShortDate = 2;
  vbLongTime = 3;
  vbShortTime = 4;

  {MsgBox constants}
  {MsgBox buttons}
  vbOKOnly = 0;
  vbOKCancel = 1;
  vbAbortRetryIgnore = 2;
  vbYesNoCancel = 3;
  vbYesNo = 4;
  vbRetryCancel = 5;
  vbCritical = 16;
  vbQuestion = 32;
  vbExclamation = 48;
  vbInformation = 64;
  vbDefaultButton1 = 0;
  vbDefaultButton2 = 256;
  vbDefaultButton3 = 512;
  vbDefaultButton4 = 768;
  vbApplicationModal = 0;
  vbSystemModal = 4096;

  {MsgBox return values}
  vbOK = 1;
  vbCancel = 2;
  vbAbort = 3;
  vbRetry = 4;
  vbIgnore = 5;
  vbYes = 6;
  vbNo = 7;

  {Split compare values}
  vbBinaryCompare = 0;
  vbTextCompare = 1;

class function TatVBScriptLibrary.LibraryName: string;
begin
  result := 'VBScript';
end;

procedure TatVBScriptLibrary.Init;
begin
  with Scripter.DefineClass(ClassType) do
  begin
     { methods }
     DefineMethod('Asc', 1, tkInteger, nil, __Asc, false, 0, 'C: Char');
     DefineMethod('Atn', 1, tkFloat, nil, __Atn, false, 0, 'X: Extended');
     DefineMethod('CBool', 1, tkEnumeration, nil, __CBool, false, 0, 'V: Variant');
     DefineMethod('CByte', 1, tkInteger, nil, __CByte, false, 0, 'V: Variant');
     DefineMethod('CCur', 1, tkFloat, nil, __CCur, false, 0, 'V: Variant');
     DefineMethod('CDate', 1, tkFloat, nil, __CDate, false, 0, 'V: Variant');
     DefineMethod('CDbl', 1, tkFloat, nil, __CDbl, false, 0, 'V: Variant');
     DefineMethod('CInt', 1, tkInteger, nil, __CInt, false, 0, 'V: Variant');
     DefineMethod('CLng', 1, tkInteger, nil, __CInt, false, 0, 'V: Variant'); //<-- Uses same as CInt
     DefineMethod('CreateObject', 1, tkVariant, nil, __CreateObject, false, 0, 'ClassName: string');
     DefineMethod('CSng', 1, tkFloat, nil, __CSng, false, 0, 'V: Variant');
     DefineMethod('CStr', 1, tkString, nil, __CStr, false, 0, 'V: Variant');
     DefineMethod('DatePart', 2, tkInteger, nil, __DatePart, false, 0, 'DatePart: string; DateTime: TDateTime');
     DefineMethod('DateSerial', 3, tkFloat, nil, __DateSerial, false, 0, 'Year: Word; Month: Word; Day: Word');
     DefineMethod('DateValue', 1, tkFloat, nil, __DateValue, false, 0, 'DateTime: TDateTime');
     DefineMethod('Day', 1, tkInteger, nil, __Day, false, 0, 'DateTime: TDateTime');
     DefineMethod('Hex', 1, tkString, nil, __Hex, false, 0, 'X: Integer');
     DefineMethod('Hour', 1, tkInteger, nil, __Hour, false, 0, 'DateTime: TDateTime');
     DefineMethod('InStr', 2, tkInteger, nil, __InStr, false, 0, 'Str: String; SubStr: String');
     DefineMethod('Int', 1, tkInteger, nil, __Int, false, 0, 'X: Real');
     DefineMethod('Fix', 1, tkInteger, nil, __Fix, false, 0, 'X: Real');
     DefineMethod('FormatCurrency', 2, tkString, nil, __FormatCurrency, false, 0, 'Value: Real; Digits: integer');
     DefineMethod('FormatDateTime', 2, tkString, nil, __FormatDateTime, false, 0, 'Value: TDateTime; Format: integer');
     DefineMethod('FormatNumber', 2, tkString, nil, __FormatNumber, false, 0, 'Value: Real; Digits: integer');
     DefineMethod('InputBox', 3, tkInteger, nil, __InputBox, false, 0, 'APrompt: string; ACaption: string; Value: string');
     DefineMethod('IsArray', 1, tkEnumeration, nil, __IsArray, false, 0, 'V: Variant');
     DefineMethod('IsDate', 1, tkEnumeration, nil, __IsDate, false, 0, 'V: Variant');
     DefineMethod('IsEmpty', 1, tkEnumeration, nil, __IsEmpty, false, 0, 'V: Variant');
     DefineMethod('IsNull', 1, tkEnumeration, nil, __IsNull, false, 0, 'V: Variant');
     DefineMethod('IsNumeric', 1, tkEnumeration, nil, __IsNumeric, false, 0, 'V: Variant');
     DefineMethod('LBound', 2, tkInteger, nil, __LBound, false, 1, 'V: VariantArray; Dim: integer = 1');
     DefineMethod('LCase', 1, tkString, nil, __LCase, false, 0, 'S: string');
     DefineMethod('Left', 2, tkString, nil, __Left, false, 0, 'S: string; Count: integer');
     DefineMethod('Len', 1, tkInteger, nil, __Len, false, 0, 'S: string');
     DefineMethod('Log', 1, tkFloat, nil, __Log, false, 0, 'X: Extended');
     DefineMethod('LTrim', 1, tkString,  nil, __LTrim, false, 0, 'S: string');
     DefineMethod('RTrim', 1, tkString,  nil, __RTrim, false, 0, 'S: string');
     DefineMethod('UBound', 2, tkInteger, nil, __UBound, false, 1, 'V: VariantArray; Dim: integer = 1');
     DefineMethod('UCase', 1, tkString, nil, __UCase, false, 0, 'S: string');
     DefineMethod('Mid', 3, tkString,  nil, __Mid, false, 0, 'S: string; Index: integer; Count: integer');
     DefineMethod('Minute', 1, tkInteger, nil, __Minute, false, 0, 'DateTime: TDateTime');
     DefineMethod('Month', 1, tkInteger, nil, __Month, false, 0, 'DateTime: TDateTime');
     DefineMethod('MonthName', 2, tkString, nil, __MonthName, false, 0, 'Month: integer; ShortName: boolean');
     DefineMethod('MsgBox', 3, tkInteger, nil, __MsgBox, false, 2, 'Text: string; Caption: string = ""; Type: integer = vbOkOnly');
     DefineMethod('Replace', 3, tkString, nil, __Replace, false, 0, 'S: string; OldPattern: string; NewPattern: string');
     DefineMethod('Right', 2, tkString, nil, __Right, false, 0, 'S: string; Count: integer');
     DefineMethod('Rnd', 0, tkFloat, nil, __Rnd, false, 0, '');
     DefineMethod('Second', 1, tkInteger, nil, __Second, false, 0, 'DateTime: TDateTime');
     DefineMethod('Sgn', 1, tkInteger, nil, __Sgn, false, 0, 'X: Real');
     DefineMethod('Space', 1, tkString, nil, __Space, false, 0, 'Count: integer');
     DefineMethod('StrComp', 2, tkInteger, nil, __StrComp, false, 0, 'S1: string; S2: string');
     DefineMethod('String', 2, tkString, nil, __String, false, 0, 'Count: integer; C: Char');
     DefineMethod('Timer', 0, tkInteger, nil, __Timer, false, 0, '');
     DefineMethod('TimeSerial', 3, tkFloat, nil, __TimeSerial, false, 0, 'Hour: Word; Min: Word; Sec: Word');
     DefineMethod('TimeValue', 1, tkFloat, nil, __TimeValue, false, 0, 'DateTime: TDateTime');
     DefineMethod('Weekday', 1, tkInteger, nil, __Weekday, false, 0, 'DateTime: TDateTime');
     DefineMethod('WeekdayName', 2, tkString, nil, __WeekdayName, false, 0, 'DateTime: TDateTime; ShortName: boolean');
     DefineMethod('Year', 1, tkInteger, nil, __Year, false, 0, 'DateTime: TDateTime');
     {$IFNDEF NEWSTACK}
     DefineMethod('Redim', 10, tkVariant, nil, __Redim, false, 9, '');
     DefineMethod('RedimPreserve', 2, tkVariant, nil, __RedimPreserve, false, 0, '').SetVarArgs([0]);
     DefineMethod('Split', 3, tkVariant, nil, __Split, false, 2, 'S: string; Delimiter: Char = " "; Count: integer=-1');
     DefineMethod('Join', 2, tkString, nil, __Join, false, 1, 'V: VariantArray; Delimiter: Char = " "');
     {$ENDIF}
     DefineMethod('StrReverse', 1, tkString, nil, __StrReverse, false, 0, 'S: string');
     DefineMethod('Randomize', 0, tkNone, nil, __Randomize, false, 0, '');

     {Constants}
     {FormatDateTime constants}
     AddConstant('vbGeneralDate', vbGeneralDate);
     AddConstant('vbLongDate', vbLongDate);
     AddConstant('vbShortDate', vbShortDate);
     AddConstant('vbLongTime', vbLongTime);
     AddConstant('vbShortTime', vbShortTime);

     {MsgBox Constants}
     {MsgBox buttons}
     AddConstant('vbOKOnly', vbOKOnly);
     AddConstant('vbOKCancel', vbOKCancel);
     AddConstant('vbAbortRetryIgnore', vbAbortRetryIgnore);
     AddConstant('vbYesNoCancel', vbYesNoCancel);
     AddConstant('vbYesNo', vbYesNo);
     AddConstant('vbRetryCancel', vbRetryCancel);
     AddConstant('vbCritical', vbCritical);
     AddConstant('vbQuestion', vbQuestion);
     AddConstant('vbExclamation',vbExclamation);
     AddConstant('vbInformation', vbInformation);
     AddConstant('vbDefaultButton1', vbDefaultButton1);
     AddConstant('vbDefaultButton2', vbDefaultButton2);
     AddConstant('vbDefaultButton3', vbDefaultButton3);
     AddConstant('vbDefaultButton4', vbDefaultButton4);
     AddConstant('vbApplicationModal', vbApplicationModal);
     AddConstant('vbSystemModal', vbSystemModal);

     {MsgBox return values}
     AddConstant('vbOK', vbOK);
     AddConstant('vbCancel', vbCancel);
     AddConstant('vbAbort', vbAbort);
     AddConstant('vbRetry', vbRetry);
     AddConstant('vbIgnore', vbIgnore);
     AddConstant('vbYes', vbYes);
     AddConstant('vbNo', vbNo);

     {Split compare values}
     AddConstant('vbBinaryCompare', vbBinaryCompare);
     AddConstant('vbTextCompare', vbTextCompare);
  end;
end;

procedure TatVBScriptLibrary.__Asc(AMachine: TatVirtualMachine);
var
  S: string;
begin
  with AMachine do
  begin
    S := GetInputArgAsString(0);
    if Length(S) > 0 then
      ReturnOutputArg(Ord(S[1]))
    else
      RaiseRuntimeError('Empty string when calling Asc function');
  end;
end;

procedure TatVBScriptLibrary.__Atn(AMachine: TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(ArcTan(GetInputArgAsFloat(0)));
end;

procedure TatVBScriptLibrary.__CBool(AMachine: TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(GetInputArgAsBoolean(0));
end;

procedure TatVBScriptLibrary.__CByte(AMachine: TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(Byte(GetInputArgAsInteger(0)));
end;

procedure TatVBScriptLibrary.__CCur(AMachine: TatVirtualMachine);
var
  R: Currency;
begin
  with AMachine do
  begin
    R := GetInputArgAsFloat(0);
    ReturnOutputArg(R);
  end;
end;

procedure TatVBScriptLibrary.__CDate(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(GetInputArgAsDateTime(0));
end;

procedure TatVBScriptLibrary.__CDbl(AMachine:TatVirtualMachine);
var
  D: double;
begin
  with AMachine do
  begin
    D := GetInputArgAsFloat(0);
    ReturnOutputArg(D);
  end;
end;

procedure TatVBScriptLibrary.__CInt(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(GetInputArgAsInteger(0));
end;

procedure TatVBScriptLibrary.__CreateObject(AMachine:TatVirtualMachine);
begin
  {$IFDEF MSWINDOWS}
  with AMachine do
    ReturnOutputArg(CreateOleObject(GetInputArgAsString(0)));
  {$ENDIF}
end;

procedure TatVBScriptLibrary.__CSng(AMachine:TatVirtualMachine);
var
  D: single;
begin
  with AMachine do
  begin
    D := GetInputArgAsFloat(0);
    ReturnOutputArg(D);
  end;
end;

procedure TatVBScriptLibrary.__CStr(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(GetInputArgAsString(0));
end;

procedure TatVBScriptLibrary.__DatePart(AMachine:TatVirtualMachine);
var
  DD: TDateTime;
  I: string;
  D, M, Y, H, Min, S, MS: word;
  Res: integer;
begin
  with AMachine do
  begin
    DD := GetInputArgAsDateTime(1);
    I := LowerCase(GetInputArgAsString(0));
    DecodeDate(DD, Y, M, D);
    DecodeTime(DD, H, Min, S, MS);
    if I = 'yyyy' then
      Res := Y
    else
    if I = 'm' then
      Res := M
    else
    if I = 'd' then
      Res := D
    else
    if I = 'h' then
      Res := H
    else
    if I = 'n' then
      Res := Min
    else
    if I = 's' then
      Res := S
    else
    if I = 'w' then
      Res := DayOfWeek(DD)
    else
    if I = 'q' then
      Res := ((M - 1) div 3) + 1
    else
      Res := 0;
    ReturnOutputArg(Res);
  end;
end;

procedure TatVBScriptLibrary.__DateSerial(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(EncodeDate(GetInputArgAsInteger(0),
      GetInputArgAsInteger(1), GetInputArgAsInteger(2)));
end;

procedure TatVBScriptLibrary.__DateValue(AMachine:TatVirtualMachine);
var
  D, M, Y: word;
begin
  with AMachine do
  begin
    DecodeDate(GetInputArgAsDateTime(0), Y, M, D);
    ReturnOutputArg(EncodeDate(Y, M, D));
  end;
end;

procedure TatVBScriptLibrary.__Day(AMachine:TatVirtualMachine);
var
  D, M, Y: word;
begin
  with AMachine do
  begin
    DecodeDate(GetInputArgAsDateTime(0), Y, M, D);
    ReturnOutputArg(D);
  end;
end;

procedure TatVBScriptLibrary.__Hex(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(IntToHex(GetInputArgAsInteger(0), 0));
end;

procedure TatVBScriptLibrary.__Hour(AMachine:TatVirtualMachine);
var
  H, M, S, MS: word;
begin
  with AMachine do
  begin
    DecodeTime(GetInputArgAsDateTime(0), H, M, S, MS);
    ReturnOutputArg(H);
  end;
end;

procedure TatVBScriptLibrary.__InStr(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(pos(GetInputArgAsString(1), GetInputArgAsString(0)));
end;

procedure TatVBScriptLibrary.__Int(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(Floor(GetInputArgAsFloat(0)));
end;

procedure TatVBScriptLibrary.__Fix(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(Int(GetInputArgAsFloat(0)));
end;

procedure TatVBScriptLibrary.__FormatCurrency(AMachine:TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(CurrToStrF(GetInputArgAsFloat(0), ffCurrency, GetInputArgAsInteger(1)));
  end;
end;

procedure TatVBScriptLibrary.__FormatDateTime(AMachine:TatVirtualMachine);
var
  AFormat: string;
begin
  with AMachine do
  begin
    Case GetInputArgAsInteger(1) of
      vbLongDate: AFormat := 'dddddd';
      vbShortDate: AFormat := 'ddddd';
      vbLongTime: AFormat := 'tt';
      vbShortTime: AFormat := 't';
    else
      {vbGeneralDate}
      AFormat := 'c';
    end;
    ReturnOutputArg(FormatDateTime(AFormat, GetInputArgAsDateTime(0)));
  end;
end;

procedure TatVBScriptLibrary.__FormatNumber(AMachine:TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(FloatToStrF(GetInputArgAsFloat(0), ffFixed, 15, GetInputArgAsInteger(1)));
  end;
end;

type
  THackMachine = class(TatVirtualMachine)
  end;

procedure TatVBScriptLibrary.__InputBox(AMachine:TatVirtualMachine);
var
  V: string;
begin
  with THackMachine(AMachine) do
  begin
    V := GetInputArgAsString(2);
    if PerformInputQuery(GetInputArgAsString(1), GetInputArgAsString(0), V) then
      ReturnOutputArg(V)
    else
      ReturnOutputArg('');
  end;
end;

procedure TatVBScriptLibrary.__IsArray(AMachine:TatVirtualMachine);
begin
  {$IFDEF NEWSTACK}
  AMachine.ReturnOutputArg(AMachine.GetInputArg(0).IsArray);
  {$ELSE}
  AMachine.ReturnOutputArg(VarIsArray(AMachine.GetInputArg(0)));
  {$ENDIF}
end;

procedure TatVBScriptLibrary.__IsDate(AMachine:TatVirtualMachine);
var
  Dummy: TDateTime;
  IsDateResult: boolean;
begin
  with AMachine do
  begin
    if ScriptValueIsDateTime(GetInputArg(0)) then
      IsDateResult := true
    else
      IsDateResult := TryStrToDate(GetInputArgAsString(0), Dummy);
    ReturnOutputArg(IsDateResult);
  end;
end;

procedure TatVBScriptLibrary.__IsEmpty(AMachine:TatVirtualMachine);
begin
  {$IFDEF NEWSTACK}
  AMachine.ReturnOutputArg(AMachine.GetInputArg(0).IsEmpty);
  {$ELSE}
  AMachine.ReturnOutputArg(VarIsEmpty(AMachine.GetInputArg(0)));
  {$ENDIF}
end;

procedure TatVBScriptLibrary.__IsNull(AMachine:TatVirtualMachine);
begin
  {$IFDEF NEWSTACK}
  AMachine.ReturnOutputArg(AMachine.GetInputArg(0).IsEmpty);
  {$ELSE}
  AMachine.ReturnOutputArg(VarIsNull(AMachine.GetInputArg(0)));
  {$ENDIF}
end;

{$HINTS OFF}
procedure TatVBScriptLibrary.__IsNumeric(AMachine:TatVirtualMachine);
var
  e: integer;
  V: double;
begin
  with AMachine do
  begin
    Val(GetInputArgAsString(0), V, e);
    ReturnOutputArg(e = 0);
  end;
end;
{$HINTS ON}

procedure TatVBScriptLibrary.__LBound(AMachine:TatVirtualMachine);
begin
  {$IFDEF NEWSTACK}
  with AMachine do
    ReturnOutPutArg(ScriptArrayLow(GetInputArg(0)));
  {$ELSE}
  with AMachine do
    if InputArgCount = 1 then
      ReturnOutPutArg(VarArrayLowBound(GetInputArg(0), 1))
    else
      ReturnOutPutArg(VarArrayLowBound(GetInputArg(0), GetInputArgAsInteger(1)))
  {$ENDIF}
end;

procedure TatVBScriptLibrary.__LCase(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutPutArg(LowerCase(GetInputArgAsString(0)));
end;

procedure TatVBScriptLibrary.__Left(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutPutArg(Copy(GetInputArgAsString(0), 1, GetInputArgAsInteger(1)));
end;

procedure TatVBScriptLibrary.__Len(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutPutArg(Length(GetInputArgAsString(0)));
end;

procedure TatVBScriptLibrary.__Log(AMachine: TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(Ln(GetInputArgAsFloat(0)));
end;

procedure TatVBScriptLibrary.__LTrim(AMachine:TatVirtualMachine);
begin
   with AMachine do
      ReturnOutputArg( TrimLeft( GetInputArgAsString( 0 ) ) );
end;

procedure TatVBScriptLibrary.__RTrim(AMachine:TatVirtualMachine);
begin
   with AMachine do
      ReturnOutputArg( TrimRight( GetInputArgAsString( 0 ) ) );
end;

procedure TatVBScriptLibrary.__UBound(AMachine:TatVirtualMachine);
begin
  {$IFDEF NEWSTACK}
  with AMachine do
    ReturnOutPutArg(ScriptArrayHigh(GetInputArg(0)));
  {$ELSE}
  with AMachine do
    if InputArgCount = 1 then
      ReturnOutPutArg(VarArrayHighBound(GetInputArg(0), 1))
    else
      ReturnOutPutArg(VarArrayHighBound(GetInputArg(0), GetInputArgAsInteger(1)));
  {$ENDIF}
end;

procedure TatVBScriptLibrary.__UCase(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutPutArg(UpperCase(GetInputArgAsString(0)));
end;

procedure TatVBScriptLibrary.__Mid(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutPutArg(Copy(GetInputArgAsString(0), GetInputArgAsInteger(1), GetInputArgAsInteger(2)));
end;

procedure TatVBScriptLibrary.__Minute(AMachine:TatVirtualMachine);
var
  H, M, S, MS: word;
begin
  with AMachine do
  begin
    DecodeTime(GetInputArgAsDateTime(0), H, M, S, MS);
    ReturnOutputArg(M);
  end;
end;

procedure TatVBScriptLibrary.__Month(AMachine:TatVirtualMachine);
var
  D, M, Y: word;
begin
  with AMachine do
  begin
    DecodeDate(GetInputArgAsDateTime(0), Y, M, D);
    ReturnOutputArg(M);
  end;
end;

procedure TatVBScriptLibrary.__MonthName(AMachine:TatVirtualMachine);
var
  D: TDateTime;
begin
  with AMachine do
  begin
    D := EncodeDate(1900, GetInputArgAsInteger(0), 1);
    if GetInputArgAsBoolean(1) then
      ReturnOutputArg(FormatDateTime('mmm', D))
    else
      ReturnOutputArg(FormatDateTime('mmmm', D));
  end;
end;

procedure TatVBScriptLibrary.__MsgBox(AMachine:TatVirtualMachine);
begin
  with THackMachine(AMachine) do
  begin
    case InputArgCount of
      {$IFDEF MSWINDOWS}
      1:  ReturnOutputArg(PerformMessageBox(GetInputArgAsString(0)));
      2:  ReturnOutputArg(PerformMessageBox(GetInputArgAsString(0), GetInputArgAsInteger(1)));
      3:  ReturnOutputArg(PerformMessageBox(GetInputArgAsString(0), GetInputArgAsInteger(1), GetInputArgAsString(2)));
      {$ELSE}
      1..3: PerformShowMessage(GetInputArgAsString(0));
      {$ENDIF}
    end;
  end;
end;

procedure TatVBScriptLibrary.__Replace(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(StringReplace(GetInputArgAsString(0),
      GetInputArgAsString(1),GetInputArgAsString(2), [rfReplaceAll]));
end;

procedure TatVBScriptLibrary.__Right(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutPutArg(Copy(GetInputArgAsString(0),
      Length(GetInputArgAsString(0)) - GetInputArgAsInteger(1) + 1, MaxInt));
end;

procedure TatVBScriptLibrary.__Rnd(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutPutArg(Random);
end;

procedure TatVBScriptLibrary.__Second(AMachine:TatVirtualMachine);
var
  H, M, S, MS: word;
begin
  with AMachine do
  begin
    DecodeTime(GetInputArgAsDateTime(0), H, M, S, MS);
    ReturnOutputArg(S);
  end;
end;

procedure TatVBScriptLibrary.__Sgn(AMachine:TatVirtualMachine);
var
  D: double;
begin
  with AMachine do
  begin
    D := GetInputArgAsFloat(0);
    if D > 0 then
      ReturnOutputArg(1)
    else
    if D < 0 then
      ReturnOutputArg(-1)
    else
      ReturnOutputArg(0);
  end;
end;

procedure TatVBScriptLibrary.__Space(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutPutArg(StringOfChar(' ', GetInputArgAsInteger(0)));
end;

procedure TatVBScriptLibrary.__StrComp(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(CompareStr(GetInputArgAsString(0), GetInputArgAsString(1)));
end;

procedure TatVBScriptLibrary.__String(AMachine:TatVirtualMachine);
var
  Ch: char;
  S: string;
begin
  with AMachine do
  begin
    S := GetInputArgAsString(1);
    if Length(S) > 0 then
      Ch := S[1]
    else
      Ch := ' ';
    ReturnOutPutArg(StringOfChar(Ch, GetInputArgAsInteger(0)));
  end;
end;

procedure TatVBScriptLibrary.__Timer(AMachine:TatVirtualMachine);
var
  H, M, S, MS: word;
begin
  with AMachine do
  begin
    DecodeTime(Now, H, M, S, MS);
    ReturnOutputArg(H * 3600 + M * 60 + S + (MS / 1000));
  end;
end;

procedure TatVBScriptLibrary.__TimeSerial(AMachine:TatVirtualMachine);
begin
  with AMachine do
    ReturnOutputArg(EncodeTime(GetInputArgAsInteger(0),
      GetInputArgAsInteger(1), GetInputArgAsInteger(2), 0));
end;

procedure TatVBScriptLibrary.__TimeValue(AMachine:TatVirtualMachine);
var
  H, M, S, MS: word;
begin
  with AMachine do
  begin
    DecodeTime(GetInputArgAsDateTime(0), H, M, S, MS);
    ReturnOutputArg(EncodeTime(H, M, S, MS));
  end;
end;

procedure TatVBScriptLibrary.__Weekday(AMachine:TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(DayOfWeek(GetInputArgAsDateTime(0)));
  end;
end;

procedure TatVBScriptLibrary.__WeekdayName(AMachine:TatVirtualMachine);
var
  D: TDateTime;
begin
  with AMachine do
  begin
    //The date 1/1/1899 is a sunday, so...
    D := EncodeDate(1899, 1, GetInputArgAsInteger(0));
    if GetInputArgAsBoolean(1) then
      ReturnOutputArg(FormatDateTime('ddd', D))
    else
      ReturnOutputArg(FormatDateTime('dddd', D));
  end;
end;

procedure TatVBScriptLibrary.__Year(AMachine:TatVirtualMachine);
var
  D, M, Y: word;
begin
  with AMachine do
  begin
    DecodeDate(GetInputArgAsDateTime(0), Y, M, D);
    ReturnOutputArg(Y);
  end;
end;

{$IFNDEF NEWSTACK}
procedure TatVBScriptLibrary.__Redim(AMachine: TatVirtualMachine);
var
  ParamCount: integer;
  Dimensions: array of integer;
begin
  with AMachine do
  begin
    SetLength(Dimensions, (InputArgCount) * 2);

    for ParamCount := 0 to InputArgCount - 1 do
    begin
      Dimensions[(ParamCount * 2)    ] :=  0;
      Dimensions[(ParamCount * 2) + 1] := GetInputArgAsInteger(ParamCount);
    end;

    ReturnOutputArg(VarArrayCreate(Dimensions, varVariant));
  end;
end;
{$ENDIF}

{$IFNDEF NEWSTACK}
procedure TatVBScriptLibrary.__RedimPreserve(AMachine: TatVirtualMachine);
var
  VariantArray: Variant;
begin
  with AMachine do
  begin
    VariantArray := GetInputArg(0);
    VarArrayRedim(VariantArray, GetInputArgAsInteger(1));
    SetInputArg(0, VariantArray);
  end;
end;
{$ENDIF}

{$IFNDEF NEWSTACK}
procedure TatVBScriptLibrary.__Split(AMachine: TatVirtualMachine);

  function CharPos(ADelimiter: Char; AExpression: string): integer;
  var
    I: integer;
  begin
    for I := 1 to Length(AExpression) do
      if AExpression[I] = ADelimiter then
      begin
        Result := I;
        Exit;
      end;

    Result := -1;
  end;

var
  I: Integer;
  Token: string;
  DelimiterCount: integer;
  TokensCount: integer;
  Expression: string;
  Delimiter: char;
  Count: integer;
  OutPut: Variant;
begin
  with AMachine do
  begin
    Expression := GetInputArgAsString(0);

    if Expression = '' then
    begin
      Output := VarArrayCreate([0, 0], varVariant);
      Output[0] := Expression;
    end
    else begin
      if InputArgCount < 2 then
        Delimiter := ' '
      else
        Delimiter := GetInputArgAsChar(1);

      if InputArgCount < 3 then
        Count := -1
      else
        Count := GetInputArgAsInteger(2);

      DelimiterCount := 0;
      for I := 1 to Length(Expression) do
        if Expression[I] = Delimiter then
          Inc(DelimiterCount);

      if DelimiterCount = 0 then
      begin
        Output := VarArrayCreate([0, 0], varVariant);
        Output[0] := Expression;
      end
      else
      begin
        if Count = -1 then
          Count := DelimiterCount + 1;

        Output := VarArrayCreate([0, Count - 1], varVariant);

        TokensCount := 0;
        I := CharPos(Delimiter, Expression);

        while (I > 0) and (TokensCount < Count) do
        begin
          Token := Copy(Expression, 1, I - 1);
          Output[TokensCount] := Token;
          Inc(TokensCount);
          Delete(Expression, 1, I);
          I := CharPos(Delimiter, Expression);
        end;

        if (Expression <> '') and (TokensCount < Count) then
          Output[TokensCount] := Expression;
      end;
    end;

    ReturnOutputArg(OutPut);
  end;
end;
{$ENDIF}

{$IFNDEF NEWSTACK}
procedure TatVBScriptLibrary.__Join(AMachine: TatVirtualMachine);
var
  I: Integer;
  HighBound: integer;
  ResultString: string;
  Delimiter: Char;
  VarArray: array of Variant;
begin
  with AMachine do
  begin
    VarArray := GetInputArg(0);

    if InputArgCount < 2 then
      Delimiter := ' '
    else
      Delimiter := GetInputArgAsChar(1);

    HighBound := VarArrayHighBound(VarArray, 1);
    ResultString := '';    

    for I := VarArrayLowBound(VarArray, 1) to HighBound do begin
      ResultString := ResultString + String(VarArray[I]);

      if I <> HighBound then
        ResultString := ResultString + Delimiter;
    end;

    ReturnOutputArg(ResultString);
  end;
end;
{$ENDIF}

procedure TatVBScriptLibrary.__StrReverse(AMachine: TatVirtualMachine);
var
  I: Integer;
  Len: integer;
  InputString: string;
  ResultString: string;
begin
  with AMachine do
  begin
    InputString := GetInputArgAsString(0);

    Len := Length(InputString);

    SetLength(ResultString, Len);

    for I := 1 to Len do
      ResultString[Len - I + 1] := InputString[I];

    ReturnOutputArg(ResultString);
  end;
end;

procedure TatVBScriptLibrary.__Randomize(AMachine: TatVirtualMachine);
begin
  Randomize;
end;

initialization
  RegisterScripterLibrary(TatVBScriptLibrary, True);

end.
