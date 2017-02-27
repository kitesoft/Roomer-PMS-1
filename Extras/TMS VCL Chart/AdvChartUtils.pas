{********************************************************************}
{                                                                    }
{ written by TMS Software                                            }
{            copyright © 2016                                        }
{            Email : info@tmssoftware.com                            }
{            Web : http://www.tmssoftware.com                        }
{                                                                    }
{ The source code is given as is. The author is not responsible      }
{ for any possible damage done due to the use of this code.          }
{ The complete source code remains property of the author and may    }
{ not be distributed, published, given or sold in any form as such.  }
{ No parts of the source code can be included in any other component }
{ or application without written authorization of the author.        }
{********************************************************************}

unit AdvChartUtils;

{$I TMSDEFS.inc}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

interface

uses
  {$IFDEF MSWINDOWS}
  Windows,
  {$ENDIF}
  Classes, SysUtils, Types, AdvChartTypes, Controls,
  Graphics, Forms
  {$IFDEF FMXLIB}
  ,FMX.Types, VCL.Dialogs
  {$IFDEF MACOS}
  ,MacApi.ObjectiveC, MacApi.ObjcRuntime
  {$IFDEF IOS}
  ,iOSApi.Foundation
  {$ELSE}
  ,MacApi.Foundation
  {$ENDIF}
  {$ENDIF}
  {$ENDIF}
  {$IFNDEF LCLLIB}
  ,Rtti
  {$HINTS OFF}
  {$IF COMPILERVERSION > 22}
  ,UITypes
  {$IFEND}
  {$HINTS ON}
  {$ENDIF}
  {$IFDEF VCLLIB}
  ,JPEG, PngImage, GifImg
  {$ENDIF}
  {$IFDEF CMNLIB}
  ,Dialogs
  {$ENDIF}
  ;

const
  PthDel = {$IFDEF MSWINDOWS} '\'; {$ELSE} '/'; {$ENDIF}

type
  TAdvChartUtilsCharSet = array of char;

  TAdvChartUtils = class
  public
    class procedure OpenURL(AURL: string);
    class procedure OpenFile(AFile: string);
    class procedure GetFonts(FontList: TStringList);
    class procedure SetFontSize(AFont: TFont; ASize: Single);
    class function IsHTMLUnicode(AValue: UnicodeString): Boolean;
    class function IsHTML(AValue: String): Boolean;
    class function GetDocumentsPath: String;
    class function GetAppPath: String;
    class function GetMousePos: TPointF;
    class function IsHighDPIScale: Boolean;
    class function GetDPIScale: Single;
    class function AddBackslash(const AValue: string): string;
    class function GetResourceStream(AResourceName: string): TResourceStream;
    class function Clone(AComponent: TComponent): TComponent;
    class function HTMLStrip(AHTML: string): string;
    class function VarPos(ASubValue, AValue: string; var AResult: Integer): Integer;
    class function VarPosNoCase(ASubValue, AValue: string; var AResult: Integer): Integer;
    class function CharInStr(s: string; Index: Integer): Char;
    class function HexStrToBytes(const AValue: string): TBytes;
    {$IFDEF CMNLIB}
    class function ConvertBitmapToJPEGStream(ABitmap: TAdvChartBitmap; AQuality: Single = 1.0; ABackgroundColor: TColor = clWhite): TMemoryStream;
    class function FindGraphicClass(const Buffer; const {%H-}BufferSize: Int64; out GraphicClass: TGraphicClass): Boolean;
    {$ENDIF}
    {$IFDEF FMXLIB}
    class function ConvertBitmapToJPEGStream(ABitmap: TAdvChartBitmap; AQuality: Single = 1.0; ABackgroundColor: TAlphaColor = TAlphaColorRec.White): TMemoryStream;
    {$ENDIF}
    class procedure Split(const ADelimiter: Char; AInput: string; const AStrings: TStrings);
    class function MatchStrEx(AValue1, AValue2: string; ACaseSensitive: Boolean): Boolean;
    class function MatchStr(AValue1, AValue2:string; ACaseSensitive: Boolean): Boolean;
    class function StripLogicSpaces(AValue: string): string;
    class function FirstChar(ACharset: TAdvChartUtilsCharSet; AValue: string; var spos: Integer): char;
    class function CharInSet(ch: Char; ACharSet: TAdvChartUtilsCharSet): boolean; overload;
    class function AddCharSet(ACharSet1, ACharSet2: TAdvChartUtilsCharSet): TAdvChartUtilsCharSet;
    class function SubCharSet(ACharSet1, ACharSet2: TAdvChartUtilsCharSet): TAdvChartUtilsCharSet;
    class function AlphaCharSet: TAdvChartUtilsCharSet;
    class function NumericCharSet: TAdvChartUtilsCharSet;
    class function CreateCharSet(AValue: string): TAdvChartUtilsCharSet;
    class function IsDate(AValue: string; var ADate: TDateTime): boolean;
    class function IPos(su,s:string):Integer;
    class function UnFixMarkup(su:string; SpecialChars: boolean = true): string;
    class function FixMarkup(su:string;SpecialChars: boolean = true): string;
    class function TagReplaceString(const Srch,Repl:string;var Dest:string):Boolean;
    class function Matches(s0a, s1a: PChar): Boolean;
    class function StripThousandSep(ps: string): String;
    class function ClosingParenthesis(s1: string): Integer;
    class function GetMarkupIndex(const Markup: string): integer;
    class function GetSpecialChar(const Value: integer): UnicodeString;
    class function IndexOfTextInArray(const AText: string; const AValues: array of string): Integer;
    {$IFDEF MACOS}
    class function NSStrEx(AString: String): NSString;
    {$ENDIF}
    {$IFDEF FMXLIB}
    class function GetParentForm(AControl: TFMXObject): TCustomForm;
    {$ENDIF}
    {$IFDEF CMNLIB}
    class function GetParentForm(AControl: TControl): TCustomForm;
    {$ENDIF}
    class function MessageDlg(const AMessage: string; const ADialogType: TMsgDlgType; const AButtons: TMsgDlgButtons; const AHelpContext: LongInt): Integer;
    class function SelectFile(var AFileName: string; const ADefaultFolder: string = ''; const AFilter: string = ''): Boolean;
    class function SaveFile(var AFileName: string; const AFilter: string = ''): Boolean;
  end;

  TAdvComponentHelper = class helper for TComponent
    function GetVersionNumber(AMaj, AMin, ARel, ABld: ShortInt): string;
  end;

  {$IFDEF CMNLIB}
  TAdvControlHelper = class helper for TControl
    function MakeScreenshot: TAdvChartBitmap;
  end;
  {$ENDIF}

  TAdvClipBoardFormat = (cfText, cfRTF, cfHTML, cfBitmap, cfBitmapWin, cfStream, cfRichTextStream);

  TAdvClipBoard = class
  protected
    {$IFDEF FMXLIB}
    {$IFDEF MSWINDOWS}
    class function GetFormat(AFormat: TAdvClipBoardFormat): Cardinal; virtual;
    class function isTextFormat(AFormat: Cardinal): Boolean; virtual;
    class function isStreamFormat(AFormat: Cardinal): Boolean; virtual;
    {$ELSE}
    class function GetFormat(AFormat: TAdvClipBoardFormat): string; virtual;
    class function isTextFormat(AFormat: String): Boolean; virtual;
    class function isStreamFormat(AFormat: String): Boolean; virtual;
    {$ENDIF}
    {$ENDIF}
  public
    {$IFDEF FMXLIB}
    {$IFDEF MSWINDOWS}
    class procedure SetValue(AValue: TValue; AFormat: Cardinal); virtual;
    class function GetValue(AFormat: Cardinal): TValue; virtual;
    class function GetCustomValue(AFormat: Cardinal; AData: Pointer): TValue; virtual;
    class procedure SetCustomValue(AFormat: Cardinal; AValue: TValue; var AData: Pointer); virtual;
    class function AllocateCustomValue(AFormat: Cardinal; AValue: TValue): THandle; virtual;
    {$ELSE}
    class procedure SetValue(AValue: TValue; AFormat: String); virtual;
    class function GetValue(AFormat: String): TValue; virtual;
    {$IFDEF MACOS}
    class function GetCustomValue(AFormat: String; AData: NSData): TValue; virtual;
    class function SetCustomValue(AFormat: String; AValue: TValue): NSData; virtual;
    {$ELSE}
    class function GetCustomValue(AFormat: String; AData: Pointer): TValue; virtual;
    class function SetCustomValue(AFormat: String; AValue: TValue): Pointer; virtual;
    {$ENDIF}
    {$ENDIF}
    {$IFDEF MSWINDOWS}
    class procedure SetBitmapWin(ABitmap: TAdvChartBitmap); virtual;
    class function GetBitmapWin: TAdvChartBitmap; virtual;
    {$ENDIF}
    {$IFDEF MSWINDOWS}
    class function HasFormat(AFormat: Cardinal): Boolean; overload; virtual;
    {$ELSE}
    class function HasFormat(AFormat: String): Boolean; overload; virtual;
    {$ENDIF}
    {$ENDIF}

    {$IFDEF CMNLIB}
    class function GetFormat(AFormat: TAdvClipBoardFormat): string; virtual;
    {$ENDIF}
    class function HasFormat(AFormat: TAdvClipBoardFormat): Boolean; overload; virtual;
    class function HasContent: Boolean; virtual;
    class procedure Clear; virtual;
    class procedure SetText(AText: String); virtual;
    class function GetText: String; virtual;
    class procedure SetStream(AStream: TMemoryStream); virtual;
    class function GetStream: TMemoryStream; virtual;
    class procedure SetBitmap(ABitmap: TAdvChartBitmap); virtual;
    class function GetBitmap: TAdvChartBitmap; virtual;
    class procedure SetRichTextStream(AStream: TMemoryStream); virtual;
    class function GetRichTextStream: TMemoryStream; virtual;
    class procedure SetRTF(ARTF: String); virtual;
    class function GetRTF: String; virtual;
    class procedure SetHTML(AHTML: String); virtual;
    class function GetHTML: String; virtual;
  end;

{$EXTERNALSYM Hiword}
function Hiword(L: DWORD): Word;
{$EXTERNALSYM LoWord}
function LoWord(L: DWORD): Word;
{$EXTERNALSYM MakeWord}
function MakeWord(b1,b2: Integer): Integer;
{$EXTERNALSYM MakeLong}
function MakeLong(i1,i2: Integer): Integer;

var
  CF_FNCSTREAM: Word;
  CF_FNCRICHTEXTSTREAM: Word;
  CF_FNCRTF: Word;
  CF_FNCBITMAP: Word;
  {$IFDEF FMXLIB}
  CF_FNCBITMAPWIN: Word;
  {$ENDIF}
  CF_FNCHTML: Word;

implementation

uses
  {$IFDEF MSWINDOWS}
  {$IFNDEF LCLLIB}
  ShellApi, AnsiStrings
  {$ENDIF}
  {$IFDEF VCLLIB}
  ,ShlObj, ComObj
  {$ENDIF}
  {$ENDIF}
  {$IFDEF MACOS}
  {$IFDEF IOS}
  iOSApi.UIKit, iOSApi.CocoaTypes, FMX.Platform.iOS
  {$ELSE}
  MacApi.AppKit
  {$ENDIF}
  ,MacApi.Helpers
  {$ENDIF}
  {$IFDEF ANDROID}
  AndroidApi.JNI.App, AndroidApi.JNI.GraphicsContentViewText, AndroidApi.JNIBridge, Generics.Collections,
  AndroidApi.JNI.Net, AndroidApi.Helpers, FMX.Helpers.Android, AndroidApi.JNI.JavaTypes
  {$ENDIF}
  {$IFDEF FMXLIB}
  ,FMX.Platform, IOUtils, FMX.Surfaces
  {$HINTS OFF}
  {$IF COMPILERVERSION > 28}
  ,FMX.Utils
  {$IFEND}
  {$IF COMPILERVERSION > 30}
  {$IFNDEF FMXMOBILE}
  ,FMX.DialogService.Sync
  {$ENDIF}
  {$IFEND}
  {$HINTS ON}
  {$ENDIF}
  {$IFDEF LCLLIB}
  LCLIntF, LCLType
  {$ENDIF}
  {$IFDEF CMNLIB}
  ,ClipBrd
  {$ENDIF}
  {$IFNDEF LCLLIB}
  ,StrUtils
  {$ENDIF}
  ;

const
  NumSpecialChar = 63;

var
  HTMLEncodedChar : array[1..NumSpecialChar] of unicodestring = ('&','<','>','"',' ',
                                                     'é','è','ë','ê',
                                                     'ó','ò','ö','ô',
                                                     'í','ì','ï','î',
                                                     'ú','ù','ü','û',
                                                     'á','à','ä','â',
                                                     'É','È','Ë','Ê',
                                                     'Ó','Ò','Ö','Ô',
                                                     'Í','Ì','Ï','Î',
                                                     'Ú','Ù','Ü','Û',
                                                     'Á','À','Ä','Â',
                                                     'ç','Ç','ø','Ø',
                                                     'å','Å','©','®',
                                                     '€','«','»','ã',
                                                     'Ã','õ','Õ','™',
                                                     '§','¶');

  HTMLSpecialChar : array[1..NumSpecialChar] of string = ('amp;','lt;','gt;','quot;','&nbsp;',
                                             '&eacute;','&egrave;','&euml;','&ecirc;',
                                             '&oacute;','&ograve;','&ouml;','&ocirc;',
                                             '&iacute;','&igrave;','&iuml;','&icirc;',
                                             '&uacute;','&ugrave;','&uuml;','&ucirc;',
                                             '&aacute;','&agrave;','&auml;','&acirc;',
                                             '&Eacute;','&Egrave;','&Euml;','&Ecirc;',
                                             '&Oacute;','&Ograve;','&Ouml;','&Ocirc;',
                                             '&Iacute;','&Igrave;','&Iuml;','&Icirc;',
                                             '&Uacute;','&Ugrave;','&Uuml;','&Ucirc;',
                                             '&Aacute;','&Agrave;','&Auml;','&Acirc;',
                                             '&ccedil;','&Ccedil;','&oslash;','&Oslash;',
                                             '&aring;','&Aring;','&copy;','&reg;',
                                             '&euro;','&laquo;','&raquo;','&atilde;',
                                             '&Atilde;','&otilde;','&Otilde',
                                             '&trade;','&sect;','&para;');

function Hiword(L: DWORD): Word;
begin
  Result := L shr 16;
end;

function LoWord(L: DWORD): Word;
begin
  Result := L AND $FFFF;
end;

function MakeWord(b1,b2: Integer): Integer;
begin
  Result := b1 or b2 shl 8;
end;

function MakeLong(i1,i2: Integer): Integer;
begin
  Result := i1 or i2 shl 16;
end;

{$IFDEF ANDROID}
type
  TAdvChartUtilsFileMode = (ufmOpen, ufmSave);

  TAdvChartUtilsDialogDismissListener = class(TJavaLocal, JDialogInterface_OnDismissListener)
  public
    procedure onDismiss(dialog: JDialogInterface); cdecl;
  end;

  TAdvChartUtilsDialogSelectDirectoryListener = class(TJavaLocal, JDialogInterface_OnClickListener)
  public
    procedure onClick(dialog: JDialogInterface; which: Integer); cdecl;
  end;

  TAdvChartUtilsDialogSelectFileListener = class(TJavaLocal, JDialogInterface_OnClickListener)
  public
    procedure onClick(dialog: JDialogInterface; which: Integer); cdecl;
  end;

var
  FFilePicked: Boolean;
  FFileMode: TAdvChartUtilsFileMode;
  FSelectedFile: String;
  FCancelled: Boolean;
  FManuallyCancelled: Boolean;
  FDialogBuilder: JAlertDialog_Builder;
  FDialog: JDialog;
  FCurrentPath: JFile;
  FFileList: TJavaObjectArray<JCharSequence>;
  FDirectoryListener: TAdvChartUtilsDialogSelectDirectoryListener;
  FSelectFileListener: TAdvChartUtilsDialogSelectFileListener;
  FFilter: string;
  FDismissListener: TAdvChartUtilsDialogDismissListener;

function SharedActivityEx: JActivity;
begin
  {$HINTS OFF}
  {$IF COMPILERVERSION > 29}
  Result := TAndroidHelper.Activity;
  {$ELSE}
  Result := SharedActivity;
  {$IFEND}
  {$HINTS ON}
end;

procedure LoadFileList(APath: JFile; AFilter: string);
var
  l, lf: TList<string>;
  a, c: TArray<string>;
  I, K: Integer;
  s: string;
  SR: TSearchRec;
  fn: string;
  chk: Boolean;
begin
  FCurrentPath := APath;
  l := TList<string>.Create;
  if APath.exists then
  begin
    lf := TList<string>.Create;

    a := AFilter.Split(['|']);

    for I := 0 to Length(a) - 1 do
    begin
      if Odd(I) then
      begin
        c := a[I].Split([';']);
        for K := 0 to Length(c) - 1 do
        begin
          s := c[K].Replace('*', '');
          if not lf.Contains(s) then
            lf.Add(s);
        end;
      end;
    end;

    if APath.getParentFile <> nil then
      l.Add('..');

    fn := TAdvChartUtils.AddBackslash(JStringToString(APath.getPath)) + '*';
    k := FindFirst(fn, faAnyFile, SR);
    while K = 0 do
    begin
      chk := (sr.Name <> '.') and (sr.Name <> '..');
      chk := chk and (lf.Contains(ExtractFileExt(sr.Name)) or (lf.Count = 0) or ((lf.Count = 1) and (lf[0] = '.')) or (sr.Attr and 16 = 16));

      if chk then
      begin
        l.Add(ExtractFilePath(fn) + SR.Name);
      end;

      K := FindNext(SR);
    end;
    FindClose(SR);

    lf.Free;
  end;

  FFileList := TJavaObjectArray<JCharSequence>.Create(l.Count);
  for I := 0 to l.Count - 1 do
    FFileList.Items[I] := StrToJCharSequence(l[I]);

  l.Free;
end;

procedure ShowDialog(AFile: JFile);
begin
  FDialogBuilder := TJAlertDialog_Builder.JavaClass.init(SharedActivityEx);
  FDialogBuilder.setTitle(StrToJCharSequence(JStringToString(AFile.getPath)));
  if FFileMode = ufmSave then
    FDialogBuilder.setPositiveButton(StrToJCharSequence('Save'), FDirectoryListener);
  FDialogBuilder.setItems(FFileList, FSelectFileListener);
  FDialog := FDialogBuilder.create;
  FDialog.setOnDismissListener(FDismissListener);
  FDialog.show;
end;
{$ENDIF}

{$IFDEF MACOS}
class function TAdvChartUtils.NSStrEx(AString: String): NSString;
begin
  Result := StrToNSStr(AString);
end;
{$ENDIF}

{ TAdvChartUtils }

class function TAdvChartUtils.IPos(su,s:string):Integer;
begin
  Result := Pos(UpperCase(su),UpperCase(s));
end;

class function TAdvChartUtils.TagReplaceString(const Srch,Repl:string;var Dest:string):Boolean;
var
  i: Integer;
begin
  i := IPos(srch,dest);
  if i > 0 then
  begin
    Result := True;
    Delete(Dest,i,Length(Srch));
    Dest := Copy(Dest,1,i-1) + Repl + Copy(Dest,i,Length(Dest));
  end
  else
    Result := False;
end;

class function TAdvChartUtils.SaveFile(var AFileName: string; const AFilter: string = ''): Boolean;
{$IFNDEF FMXMOBILE}
var
  s: TSaveDialog;
  ext: string;
{$ENDIF}
{$IFDEF FMXMOBILE}
{$IFDEF ANDROID}
var
  fn: string;
  f: string;
{$ENDIF}
{$ENDIF}
begin
  Result := False;
  {$IFDEF FMXMOBILE}
  {$IFDEF ANDROID}
  fn := ExtractFileName(AFileName);

  FFileMode := ufmSave;
  FFilePicked := False;
  FCancelled := False;

  FDirectoryListener := TAdvChartUtilsDialogSelectDirectoryListener.Create;
  FSelectFileListener := TAdvChartUtilsDialogSelectFileListener.Create;
  FDismissListener := TAdvChartUtilsDialogDismissListener.Create;

  FFilter := AFilter;
  if ExtractFilePath(AFileName) = '' then
    f := AddBackslash(TAdvChartUtils.GetDocumentsPath)
  else
    f := AddBackslash(ExtractFilePath(AFileName));

  FSelectedFile := f + fn;

  FCurrentPath := TJFile.JavaClass.init(StringToJString(f));
  LoadFileList(FCurrentPath, FFilter);
  CallInUIThreadAndWaitFinishing(
  procedure
  begin
    ShowDialog(FCurrentPath);
  end
  );

  while not FFilePicked and not FCancelled do
    Sleep(1);

  if FFilePicked and not FCancelled then
  begin
    AFileName := FSelectedFile;
    if ExtractFileExt(FSelectedFile) = '' then
      AFileName := AddBackslash(AFileName) + fn;

    Result := True;
  end;
  {$ENDIF}
  {$ENDIF}
  {$IFNDEF FMXMOBILE}
  s := TSaveDialog.Create(Application);
  try
    ext := ExtractFileExt(AFileName);
    s.Filter := AFilter;
    if ExtractFilePath(AFileName) = '' then
      s.InitialDir := AddBackslash(TAdvChartUtils.GetDocumentsPath)
    else
      s.InitialDir := AddBackslash(ExtractFilePath(AFileName));
    s.Options := s.Options + [TOpenOption.ofOverwritePrompt];
    s.FileName := ExtractFileName(AFileName);
    if s.Execute then
    begin
      AFileName := s.FileName;
      if ExtractFileExt(s.FileName) = '' then
        AFileName := AFileName + ext;
      Result := True;
    end;
  finally
    s.Free;
  end;
  {$ENDIF}
end;

class function TAdvChartUtils.SelectFile(var AFileName: string; const ADefaultFolder: string = ''; const AFilter: string = ''): Boolean;
{$IFNDEF FMXMOBILE}
var
  o: TOpenDialog;
{$ENDIF}
{$IFDEF FMXMOBILE}
{$IFDEF ANDROID}
var
  f: string;
{$ENDIF}
{$ENDIF}
begin
  Result := False;
  {$IFDEF FMXMOBILE}
  {$IFDEF ANDROID}
  FFileMode := ufmOpen;
  FFilePicked := False;
  FCancelled := False;

  FSelectFileListener := TAdvChartUtilsDialogSelectFileListener.Create;
  FDismissListener := TAdvChartUtilsDialogDismissListener.Create;

  FFilter := AFilter;
  if ADefaultFolder = '' then
    f := AddBackslash(TAdvChartUtils.GetDocumentsPath)
  else
    f := AddBackslash(ADefaultFolder);

  FCurrentPath := TJFile.JavaClass.init(StringToJString(f));
  LoadFileList(FCurrentPath, FFilter);
  CallInUIThreadAndWaitFinishing(
  procedure
  begin
    ShowDialog(FCurrentPath);
  end
  );

  while not FFilePicked and not FCancelled do
    Sleep(1);

  if FFilePicked and not FCancelled then
  begin
    AFileName := FSelectedFile;
    Result := True;
  end;
  {$ENDIF}
  {$ENDIF}
  {$IFNDEF FMXMOBILE}
  o := TOpenDialog.Create(Application);
  try
    o.Options := [TOpenOption.ofFileMustExist];
    if ADefaultFolder = '' then
      o.InitialDir := AddBackslash(TAdvChartUtils.GetDocumentsPath)
    else
      o.InitialDir := AddBackslash(ADefaultFolder);
    o.Filter := AFilter;
    if o.Execute then
    begin
      AFileName := o.FileName;
      Result := False;
    end;
  finally
    o.Free;
  end;
  {$ENDIF}
end;

class function TAdvChartUtils.MessageDlg(const AMessage: string; const ADialogType: TMsgDlgType; const AButtons: TMsgDlgButtons; const AHelpContext: LongInt): Integer;
begin
  {$IFDEF FMXMOBILE}
  Result := mrOk;
  {$ELSE}
  {$IFDEF LCLLIB}
  Result := MessageDlg(AMessage, ADialogType, AButtons, AHelpContext);
  {$ELSE}
  {$HINTS OFF}
  {$IF COMPILERVERSION > 30}
  {$IFDEF FMXLIB}
  Result := TDialogServiceSync.MessageDialog(AMessage, ADialogType, AButtons, TMsgDlgBtn.mbYes, AHelpContext);
  {$ELSE}
  Result := MessageDlg(AMessage, ADialogType, AButtons, AHelpContext);
  {$ENDIF}
  {$ELSE}
  Result := MessageDlg(AMessage, ADialogType, AButtons, AHelpContext);
  {$IFEND}
  {$HINTS ON}
  {$ENDIF}
  {$ENDIF}
end;

class function TAdvChartUtils.NumericCharSet: TAdvChartUtilsCharSet;
var
  ch: char;
  i: integer;
begin
  SetLength(Result,10);
  i := 0;

  for ch := '0' to '9' do
  begin
    Result[i] := ch;
    inc(i);
  end;
end;

class function TAdvChartUtils.CreateCharSet(AValue: string): TAdvChartUtilsCharSet;
var
  i: integer;
begin
  SetLength(Result, Length(AValue));

  for i := 1 to Length(AValue) do
  begin
    Result[i - 1] := CharInStr(AValue, i);
  end;
end;

class function TAdvChartUtils.IndexOfTextInArray(const AText: string; const AValues: array of string): Integer;
{$IFNDEF LCLLIB}
begin
  Result := IndexText(AText, AValues);
{$ENDIF}
{$IFDEF LCLLIB}
var
  I: Integer;
begin
  Result := -1;
  for I := Low(AValues) to High(AValues) do
    if SameText(AText, AValues[I]) then
    begin
      Result := I;
      Break;
    end;
  {$ENDIF}
end;

class function TAdvChartUtils.GetMarkupIndex(const Markup: string): integer;
begin
  Result := IndexOfTextInArray(Markup, HTMLSpecialChar);
end;

class function TAdvChartUtils.GetSpecialChar(const Value: integer): UnicodeString;
begin
  Result := HTMLEncodedChar[Value];
end;

class function TAdvChartUtils.UnFixMarkup(su:string;SpecialChars: boolean = true):string;
var
  i: integer;
begin
  while Pos('&lt;',su) > 0 do
  begin
    TagReplacestring('&lt;','<',su);
  end;

  while Pos('&gt;',su) > 0 do
  begin
    TagReplacestring('&gt;','>',su);
  end;

  while Pos('&amp;',su) > 0 do
  begin
    TagReplacestring('&amp;','&',su);
  end;

  while Pos('&quot;',su) > 0 do
  begin
    TagReplacestring('&quot;','"',su);
  end;

  if SpecialChars then
  begin
    for i := 4 to NumSpecialChar do
    begin
      while Pos(string(HTMLSpecialChar[i]),su) > 0 do
      begin
        TagReplacestring(string(HTMLSpecialChar[i]),string(HTMLEncodedChar[i]),su);
      end;
    end;
  end;

  Result := su;
end;

class function TAdvChartUtils.FixMarkup(su:string;SpecialChars: boolean = true): string;
var
  i: integer;
begin
  while Pos('&',su) > 0 do
  begin
    TagReplacestring('&','*amp;',su);
  end;

  while Pos('*amp;',su) > 0 do
  begin
    TagReplacestring('*amp;','&amp;',su);
  end;

  while Pos('"',su) > 0 do
  begin
    TagReplacestring('"','&quot;',su);
  end;

  while Pos('<',su) > 0 do
  begin
    TagReplacestring('<','&lt;',su);
  end;

  while Pos('>',su) > 0 do
  begin
    TagReplacestring('>','&gt;',su);
  end;

  if SpecialChars then
  begin
    for i := 4 to NumSpecialChar do
    begin
      while Pos(string(HTMLEncodedChar[i]),su) > 0 do
      begin
        TagReplacestring(string(HTMLEncodedChar[i]),string(HTMLSpecialChar[i]),su);
      end;
    end;
  end;

  Result := su;
end;

{$IFDEF FMXLIB}
class function TAdvChartUtils.GetParentForm(AControl: TFMXObject): TCustomForm;
var
  c: TFMXObject;
{$ENDIF}
{$IFDEF CMNLIB}
class function TAdvChartUtils.GetParentForm(AControl: TControl): TCustomForm;
{$ENDIF}
begin
{$IFDEF FMXLIB}
  Result := nil;
  c := AControl;
  if not Assigned(c) then
    Exit;

  if c.Parent is TCustomForm then
    Result := c.Parent as TCustomForm
  else
    Result := GetParentForm(c.Parent);
{$ENDIF}
{$IFDEF CMNLIB}
  Result := Forms.GetParentForm(AControl);
{$ENDIF}
end;

{$IFDEF VCLLIB}
function CalculateDPIScale(Scaled: boolean; AHDC: HDC): single; overload;
var
  FDPI: integer;
begin
  Result:= 1.0;
  if Scaled then
  begin
    if AHDC = 0 then
      AHDC:= GetDC(0);
    try
      FDPI := GetDeviceCaps(AHDC, LOGPIXELSX);
      if FDPI <> 96 then
        Result:= FDPI / 96;
    finally
      if AHDC = 0 then
        ReleaseDC(0, AHDC);
    end;
  end;
end;

function CalculateDPIScale(AForm: TCustomForm; AHDC: HDC): single; overload;
begin
  Result := 1.0;
  if Assigned(AForm) and (AForm is TForm) then
    Result := CalculateDPIScale((AForm as TForm).Scaled, AHDC);
end;
{$ENDIF}

class function TAdvChartUtils.CharInStr(s: string; Index: Integer): Char;
begin
  Result := #0;
  if (Index > 0) and (Index <= Length(s)) then
  begin
    {$IFDEF FMXMOBILE}
    dec(Index);
    {$ENDIF}
    Result := s[Index]
  end;
end;

class function TAdvChartUtils.Clone(AComponent: TComponent): TComponent;
var
  S: TStream;
  SaveName: string;
  Reader: TReader;
begin
  S := TMemoryStream.Create;
  try
    { store }
    SaveName := AComponent.Name;
    AComponent.Name := '';
    S.WriteComponent(AComponent);
    AComponent.Name := SaveName;
    S.Position := 0;
    { load }
    try
      Reader := TReader.Create(S, 4096);
      try
        Result := Reader.ReadRootComponent(nil);
      finally
        Reader.Free;
      end;
    finally
    end;
  finally
    S.Free;
  end;
end;

class function TAdvChartUtils.GetAppPath: String;
begin
  Result := ExtractFilePath(ParamStr(0));
end;

class function TAdvChartUtils.GetDocumentsPath: string;
{$IFDEF VCLLIB}
var
  szBuffer: array [0..MAX_PATH] of Char;
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  Result := TPath.GetDocumentsPath;
  {$ENDIF}
  {$IFDEF LCLLIB}
  Result := GetUserDir + PathDelim + 'Documents';
  {$ENDIF}
  {$IFDEF VCLLIB}
  OleCheck(SHGetFolderPath(0, $0005, 0, 0, szBuffer));
  Result := szBuffer;
  {$ENDIF}
end;

class function TAdvChartUtils.GetMousePos: TPointF;
{$IFDEF FMXLIB}
var
  m: IFMXMouseService;
{$ENDIF}
begin
  Result := PointF(-1, -1);
  {$IFDEF FMXLIB}
  if TPlatformServices.Current.SupportsPlatformService(IFMXMouseService, IInterface(m)) then
    Result := m.GetMousePos;
  {$ENDIF}
  {$IFDEF CMNLIB}
  Result := PointF(Mouse.CursorPos.X, Mouse.CursorPos.Y);
  {$ENDIF}
end;

class function TAdvChartUtils.AddBackslash(const AValue: string): string;
begin
  {$IFDEF FMXMOBILE}
  if (Length(AValue) >= 1) and (AValue[Length(AValue) - 1] <> PthDel) then
  {$ELSE}
  if (Length(AValue) >= 1) and (AValue[Length(AValue)] <> PthDel) then
  {$ENDIF}
    Result := AValue + PthDel
  else
    Result := AValue;
end;

class function TAdvChartUtils.GetDPIScale: Single;
{$IFDEF FMXLIB}
var
  ScreenSvc: IFMXScreenService;
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  Result := 1.0;
  if TPlatformServices.Current.SupportsPlatformService(IFMXScreenService, IInterface(ScreenSvc)) then
    Result := ScreenSvc.GetScreenScale;
  {$ENDIF}
  {$IFDEF VCLLIB}
  Result := 1.0;
  if Assigned(Application.MainForm) and Assigned(Application.MainForm.Canvas) then
    Result := CalculateDPIScale(Application.MainForm, Application.MainForm.Canvas.Handle);
  {$ENDIF}
  {$IFDEF LCLLIB}
  {$IFDEF MSWINDOWS}
  Result := Screen.PixelsPerInch / 96;
  {$ENDIF}
  {$IFDEF DARWIN}
  Result := Screen.PixelsPerInch / 72;
  {$ENDIF}
  {$IFDEF LINUX}
  Result := Screen.PixelsPerInch / 96;
  {$ENDIF}
  {$ENDIF}
end;

class function TAdvChartUtils.IsHighDPIScale: Boolean;
begin
  Result := GetDPIScale > 1;
end;

class function TAdvChartUtils.IsHTMLUnicode(AValue: UnicodeString): Boolean;
begin
  {$IFDEF LCLLIB}
  Result := IsHTML(UTF8Encode(AValue));
  {$ENDIF}
  {$IFNDEF LCLLIB}
  Result := IsHTML(AValue);
  {$ENDIF}
end;

class function TAdvChartUtils.IsHTML(AValue: string): Boolean;
begin
  Result := (Pos('</', AValue) > 0) or (Pos('/>', AValue)  > 0) or (Pos('<BR>', UpperCase(AValue)) > 0);
end;

class procedure TAdvChartUtils.OpenFile(AFile: string);
{$IFDEF ANDROID}
var
  i: JIntent;
  t: string;
  ext: string;
{$ENDIF}
{$IFDEF IOS}
var
  docController: UIDocumentInteractionController;
  url: NSURL;
  r: NSRect;
  vw: UIView;
  frm: TCommonCustomForm;
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  {$IFDEF MACOS}
  {$IFDEF IOS}
  frm := Application.MainForm;
  if Assigned(frm) then
  begin
    url := TNSURL.Wrap(TNSURL.OCClass.fileURLWithPath(NSStrEx(AFile)));
    docController := TUIDocumentInteractionController.Wrap(TUIDocumentInteractionController.OCClass.interactionControllerWithURL(url));
    docController.retain;
    vw := WindowHandleToPlatform(frm.Handle).View;
    docController.presentOpenInMenuFromRect(r, vw, TRUE);
  end;
  {$ELSE}
  TNSWorkspace.Wrap(TNSWorkspace.OCClass.sharedWorkspace).openFile(NSStrEx(AFile));
  {$ENDIF}
  {$ENDIF}

  {$IFDEF ANDROID}
  i := TJIntent.Create;
  i.setAction(TJIntent.JavaClass.ACTION_VIEW);
  if not AFile.ToLower.StartsWith('file://') then
    AFile := 'file://' + AFile;

  ext := ExtractFileExt(AFile).ToLower;
  if ext = '.pdf' then
    t := 'application/pdf'
  else if ext = '.html' then
    t := 'text/html'
  else if (ext = '.jpeg') or (ext = '.jpg') then
    t := 'image/jpeg'
  else if (ext = '.gif') then
    t := 'image/gif'
  else if (ext = '.png') then
    t := 'image/png'
  else if (ext = '.bmp') then
    t := 'image/bmp'
  else
    t := 'text/plain';

  i.setDataAndType(StrToJURI(AFile), StringToJString(t));
  SharedActivityEx.startActivity(i);
  {$ENDIF}
  {$ENDIF}

  {$IFNDEF LCLLIB}
  {$IFDEF MSWINDOWS}
  ShellExecute(0,PChar('open'),PChar(AFile),PChar(''),PChar(''), SW_NORMAL);
  {$ENDIF}
  {$ENDIF}

  {$IFDEF LCLLIB}
  OpenDocument(AFile);
  {$ENDIF}
end;

class procedure TAdvChartUtils.OpenURL(AURL: string);
{$IFDEF ANDROID}
var
  i: JIntent;
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  {$IFDEF MACOS}
  {$IFDEF IOS}
  TUIApplication.Wrap(TUIApplication.OCClass.sharedApplication).openURL(TNSURL.Wrap(TNSURL.OCClass.URLWithString(NSStrEx(AUrl))));
  {$ELSE}
  TNSWorkspace.Wrap(TNSWorkspace.OCClass.sharedWorkspace).openURL(TNSURL.Wrap(TNSURL.OCClass.URLWithString(NSStrEx(AUrl))));
  {$ENDIF}
  {$ENDIF}

  {$IFDEF ANDROID}
  i := TJIntent.Create;
  i.setAction(TJIntent.JavaClass.ACTION_VIEW);
  i.setData(StrToJURI(AURL));
  SharedActivityEx.startActivity(i);
  {$ENDIF}
  {$ENDIF}

  {$IFDEF LCLLIB}
  LCLIntF.OpenURL(AURL);
  {$ENDIF}

  {$IFNDEF LCLLIB}
  {$IFDEF MSWINDOWS}
  ShellExecute(0,PChar('open'),PChar(AURL),PChar(''),PChar(''), SW_NORMAL);
  {$ENDIF}
  {$ENDIF}
end;

{$IFNDEF LCLLIB}
{$IFDEF MSWINDOWS}
function EnumFontsProc(var LogFont: TLogFont; var TextMetric: TTextMetric;
  FontType: Integer; Data: Pointer): Integer; stdcall;
var
  S: TStrings;
  Temp: string;
begin
  S := TStrings(Data);
  Temp := LogFont.lfFaceName;
  if (S.Count = 0) or (AnsiCompareText(S[S.Count-1], Temp) <> 0) then
    S.Add(Temp);
  Result := 1;
end;

class procedure TAdvChartUtils.GetFonts(FontList: TStringList);
var
  DC: HDC;
  LFont: TLogFont;
begin
  FontList.BeginUpdate;
  FontList.Clear;
  DC := GetDC(0);
  FillChar(LFont, sizeof(LFont), 0);
  LFont.lfCharset := DEFAULT_CHARSET;
  EnumFontFamiliesEx(DC, LFont, @EnumFontsProc, LPARAM(FontList), 0);
  ReleaseDC(0, DC);
  FontList.Sort;
  FontList.EndUpdate;
end;
{$ENDIF}

{$IFDEF MACOS}
class procedure TAdvChartUtils.GetFonts(FontList: TStringList);
{$IFDEF IOS}
var
  arr: NSArray;
  I: Integer;
  lItem: NSString;
begin
  FontList.BeginUpdate;
  FontList.Clear;
  arr := TUIFont.OCClass.familyNames;
  arr := arr.sortedArrayUsingSelector(sel_getUid('localizedCaseInsensitiveCompare:'));

  for I := 0 to arr.count - 1 do
  begin
    lItem := TNSString.Wrap(arr.objectAtIndex(i));
    FontList.Add(String(lItem.UTF8String));
  end;
  FontList.Sort;
  FontList.EndUpdate;
end;
{$ELSE}
var
  fManager: NsFontManager;
  list: NSArray;
  lItem: NSString;
  i: Integer;
begin
  FontList.BeginUpdate;
  FontList.Clear;
  fManager := TNsFontManager.Wrap(TNsFontManager.OCClass.sharedFontManager);
  list := fManager.availableFontFamilies;
  if (List <> nil) and (List.count > 0) then
  begin
    for i := 0 to List.Count-1 do
    begin
      lItem := TNSString.Wrap(List.objectAtIndex(i));
      FontList.Add(String(lItem.UTF8String));
    end;
  end;
  FontList.Sort;
  FontList.EndUpdate;
end;
{$ENDIF}
{$ENDIF}

{$IFDEF ANDROID}
class procedure TAdvChartUtils.GetFonts(FontList: TStringList);
begin
  FontList.BeginUpdate;
  FontList.Clear;
  FontList.Add('Roboto');
  FontList.Add('Droid Sans');
  FontList.Add('Droid Serif');
  FontList.Add('Droid Sans Mono');
  FontList.Sort;
  FontList.EndUpdate;
end;
{$ENDIF}
{$ELSE}
class procedure TAdvChartUtils.GetFonts(FontList: TStringList);
begin
  FontList.Assign(Screen.Fonts);
end;
{$ENDIF}

class procedure TAdvChartUtils.SetFontSize(AFont: TFont; ASize: Single);
begin
  {$IFDEF FMXLIB}
  AFont.Size := ASize;
  {$ENDIF}
  {$IFDEF CMNLIB}
  AFont.Size := Round(ASize / 96 * 72);
  {$ENDIF}
end;

{$IFDEF CMNLIB}
class function TAdvChartUtils.FindGraphicClass(const Buffer; const BufferSize: Int64;
  out GraphicClass: TGraphicClass): Boolean;
var
  {$IFDEF VCLLIB}
  LongWords: array[Byte] of LongWord absolute Buffer;
  {$ENDIF}
  Words: array[Byte] of Word absolute Buffer;
begin
  GraphicClass := nil;

  if BufferSize = 0 then
  begin
    Result := False;
    Exit;
  end;

  {$IFDEF VCLLIB}
  case Words[0] of
    $4D42: GraphicClass := TBitmap;
    $D8FF: GraphicClass := TJPEGImage;
    $4949: if Words[1] = $002A then GraphicClass := TWicImage; //i.e., TIFF
    $4D4D: if Words[1] = $2A00 then GraphicClass := TWicImage; //i.e., TIFF
  else
    if Int64(Buffer) = $A1A0A0D474E5089 then
      GraphicClass := TPNGImage
    else if LongWords[0] = $9AC6CDD7 then
      GraphicClass := TMetafile
    else if (LongWords[0] = 1) and (LongWords[10] = $464D4520) then
      GraphicClass := TMetafile
    {$HINTS OFF}
    {$IF COMPILERVERSION > 24}
    else if AnsiStrings.StrLComp(PAnsiChar(@Buffer), 'GIF', 3) = 0 then
    {$ELSE}
    else if StrLComp(PAnsiChar(@Buffer), 'GIF', 3) = 0 then
    {$IFEND}
    GraphicClass := TGIFImage
    {$HINTS ON}
    else if Words[1] = 1 then
      GraphicClass := TIcon;
  end;
  {$ENDIF}
  {$IFDEF LCLLIB}
  case Words[0] of
    $4D42: GraphicClass := GetGraphicClassForFileExtension('bmp');
    $D8FF: GraphicClass := GetGraphicClassForFileExtension('jpeg');
    $4949: if Words[1] = $002A then GraphicClass := GetGraphicClassForFileExtension('tiff');
    $4D4D: if Words[1] = $2A00 then GraphicClass := GetGraphicClassForFileExtension('tiff');
  else
    if Int64(Buffer) = $A1A0A0D474E5089 then
      GraphicClass := GetGraphicClassForFileExtension('png')
    else if StrLComp(PAnsiChar(@Buffer), 'GIF', 3) = 0 then
      GraphicClass := GetGraphicClassForFileExtension('gif')
    else if Words[1] = 1 then
      GraphicClass := GetGraphicClassForFileExtension('ico');
  end;
  {$ENDIF}
  Result := (GraphicClass <> nil);
end;
{$ENDIF}

class function TAdvChartUtils.HexStrToBytes(const AValue: string): TBytes;
var
  il, idx: Integer;
  b: TBytes;
begin
  Result := nil;
  SetLength(b, Length(AValue) div 2);
  il := 1;
  idx := 0;
  while il <= Length(AValue) do
  begin
    b[idx] := StrToInt('$' + AValue[il{$IFDEF FMXMOBILE}-1{$ENDIF}] + AValue[il{$IFNDEF FMXMOBILE} + 1{$ENDIF}]);
    il := il + 2;
    idx := idx + 1;
  end;
  Result := b;
end;

class function TAdvChartUtils.AddCharSet(ACharSet1,
  ACharSet2: TAdvChartUtilsCharSet): TAdvChartUtilsCharSet;
var
  l,j: integer;
begin
  l := Length(ACharSet1)+Length(ACharSet2);
  SetLength(Result,l);
  l := 0;

  for j := 0 to High(ACharSet1) do
  begin
    Result[l] := ACharSet1[j];
    inc(l);
  end;

  for j := 0 to High(ACharSet2) do
  begin
    Result[l] := ACharSet2[j];
    inc(l);
  end;
end;

class function TAdvChartUtils.AlphaCharSet: TAdvChartUtilsCharSet;
var
  i: integer;
  ch: char;
begin
  SetLength(Result,52);
  i := 0;

  for ch := 'a' to 'z' do
  begin
    Result[i] := ch;
    inc(i);
  end;

  for ch := 'A' to 'Z' do
  begin
    Result[i] := ch;
    inc(i);
  end;

end;

class function TAdvChartUtils.CharInSet(ch: Char; ACharset: TAdvChartUtilsCharSet): boolean;
var
  j: integer;
begin
  Result := false;
  for j := 0 to High(ACharSet) do
  begin
    if ch = ACharSet[j] then
    begin
      result := true;
      break;
    end;
  end;
end;

class function TAdvChartUtils.FirstChar(ACharset: TAdvChartUtilsCharSet; AValue: string; var spos: Integer): char;
var
  i:Integer;
  q: Integer;

begin
  {$IFDEF FMXMOBILE}
  i := 0;
  {$ELSE}
  i := 1;
  {$ENDIF}
  q := 0;
  spos := -1;
  Result := #0;

  while i <= Length(AValue) do
  begin
    if AValue[i] = '"' then
      inc(q);

    if (CharInSet(AValue[i], ACharSet)) and not Odd(q) then
    begin
      spos := i;
      Result := AValue[i];
      Break;
    end;
    Inc(i);
  end;
end;

class function TAdvChartUtils.StripLogicSpaces(AValue: string): string;
var
  i, k: integer;
  q: integer;
begin
  q := 0;
  {$IFDEF FMXMOBILE}
  i := 0;
  k := length(AValue) - 1;
  {$ELSE}
  i := 1;
  k := length(AValue);
  {$ENDIF}
  Result := '';

  while (i <= k) do
  begin
    if AValue[i] = '"' then
      inc(q);

    if (AValue[i] = ' ') then
    begin
      if Odd(q) then
        Result := Result + AValue[i];
    end
    else
      Result := Result + AValue[i];

    inc(i);
  end;
end;

class function TAdvChartUtils.ClosingParenthesis(s1: string): integer;
var
  i,j,k,r: integer;
begin
  r := 0;
  j := 0;
  k := 0;
  {$IFDEF FMXMOBILE}
  i := 0;
  {$ELSE}
  i := 1;
  {$ENDIF}

  while (i <= length(s1)) do
  begin
    if (s1[i] = ')') then
      inc(k);

    if (s1[i] = '(') then
      inc(j);

    if (s1[i] = ')') and (j = k) then
    begin
      r := i;
      break;
    end;

    inc(i);
  end;

  Result := r;
end;

{$IFDEF FMXLIB}
class function TAdvChartUtils.ConvertBitmapToJPEGStream(ABitmap: TAdvChartBitmap; AQuality: Single = 1.0; ABackgroundColor: TAlphaColor = TAlphaColorRec.White): TMemoryStream;
{$ENDIF}
{$IFDEF CMNLIB}
class function TAdvChartUtils.ConvertBitmapToJPEGStream(ABitmap: TAdvChartBitmap; AQuality: Single = 1.0; ABackgroundColor: TColor = clWhite): TMemoryStream;
{$ENDIF}
var
  ms: TMemoryStream;
  bmp: TBitmap;
{$IFDEF FMXLIB}
  s: TBitmapSurface;
  sp: TBitmapCodecSaveParams;
{$ENDIF}
{$IFDEF CMNLIB}
  gcc: TGraphicClass;
  bms: TMemoryStream;
  p: TGraphic;
  img: TJPEGImage;
{$ENDIF}
begin
  Result := nil;
  {$IFDEF FMXLIB}
  s := TBitmapSurface.Create;
  bmp := TBitmap.Create;
  try
    bmp.Width := ABitmap.Width;
    bmp.Height := ABitmap.Height;
    if ABackgroundColor <> TAlphaColorRec.Null then
      bmp.Clear(ABackgroundColor)
    else
      bmp.Clear(TAlphaColorRec.White);
    bmp.Canvas.BeginScene;
    bmp.Canvas.DrawBitmap(ABitmap, RectF(0, 0, bmp.Width, bmp.Height), RectF(0, 0, bmp.Width, bmp.Height), 1);
    bmp.Canvas.EndScene;
    s.Assign(bmp);
    sp.Quality := Round(AQuality * 100);
    ms := TMemoryStream.Create;
    if TBitmapCodecManager.SaveToStream(ms, s, '.jpeg', @sp) then
      Result := ms;
  finally
    bmp.Free;
    s.Free;
  end;
  {$ENDIF}
  {$IFDEF CMNLIB}
  bms := TMemoryStream.Create;
  ABitmap.SaveToStream(bms);
  try
    if FindGraphicClass(bms.Memory^, bms.Size, gcc) then
    begin
      if gcc = TJPEGImage then
      begin
        ms := TMemoryStream.Create;
        ms.LoadFromStream(bms);
        Result := ms;
      end
      else
      begin
        p := gcc.Create;
        img := TJPEGImage.Create;
        img.CompressionQuality := Round(AQuality * 100);
        bmp := TBitmap.Create;
        try
          bms.Position := 0;
          p.LoadFromStream(bms);
          bmp.Width := p.Width;
          bmp.Height := p.Height;
          if ABackgroundColor <> clNone then
            bmp.Canvas.Brush.Color := ABackgroundColor
          else
            bmp.Canvas.Brush.Color := clWhite;
          bmp.Canvas.FillRect(Rect(0, 0, bmp.Width, bmp.Height));
          bmp.Canvas.Draw(0, 0, p);
          img.Assign(bmp);
          ms := TMemoryStream.Create;
          img.SaveToStream(ms);
          Result := ms;
        finally
          bmp.Free;
          img.Free;
          p.Free;
        end;
      end;
    end;
  finally
    bms.Free;
  end;
  {$ENDIF}
end;

class function TAdvChartUtils.StripThousandSep(ps: string): string;
begin
  while (Pos(FormatSettings.ThousandSeparator, ps) > 0) do
    Delete(ps, Pos(FormatSettings.ThousandSeparator, ps), 1);
  Result := ps;
end;

class function TAdvChartUtils.SubCharSet(ACharSet1,
  ACharSet2: TAdvChartUtilsCharSet): TAdvChartUtilsCharSet;
var
  i,j,l: integer;
  found: boolean;
begin
  l := 0;
  SetLength(Result,l);

  for i := 0 to Length(ACharSet1) - 1 do
  begin
    found := false;
    for j := 0 to Length(ACharSet2) - 1 do
      begin
        if ACharSet1[i] = ACharSet2[j] then
        begin
          found := true;
          break;
        end;
      end;

    if not found then
    begin
      inc(l);
      SetLength(Result,l);
      Result[l - 1] := ACharSet1[i];
    end;
  end;
end;

class function TAdvChartUtils.IsDate(AValue: string; var ADate: TDateTime):boolean;
var
  su, ts: string;
  da,mo,ye,ho,mi,se: word;
  err: Integer;
  dp,mp,yp,vp: Integer;
begin
  Result := False;

  ts := '';

  su := UpperCase(FormatSettings.ShortDateFormat);
  dp := pos('D',su);
  mp := pos('M',su);
  yp := pos('Y',su);

  da := 0;
  mo := 0;
  ye := 0;
  ho := 0;
  mi := 0;
  se := 0;

  vp := -1;
  if TAdvChartUtils.VarPos(FormatSettings.DateSeparator,AValue,vp)>0 then
  begin
    su := Copy(AValue,1,vp - 1);

    if (dp<mp) and
       (dp<yp) then
       val(su,da,err)
    else
    if (mp<dp) and
       (mp<yp) then
       val(su,mo,err)
    else
    if (yp<mp) and
       (yp<dp) then
       val(su,ye,err);

    if err<>0 then Exit;
    Delete(AValue,1,vp);

    if TAdvChartUtils.VarPos(FormatSettings.DateSeparator,AValue,vp)>0 then
    begin
      su := Copy(AValue,1,vp - 1);

      if ((dp>mp) and (dp<yp)) or
         ((dp>yp) and (dp<mp)) then
         val(su,da,err)
      else
      if ((mp>dp) and (mp<yp)) or
         ((mp>yp) and (mp<dp)) then
         val(su,mo,err)
      else
      if ((yp>mp) and (yp<dp)) or
         ((yp>dp) and (yp<mp)) then
         val(su,ye,err);

      if err<>0 then Exit;
      Delete(AValue,1,vp);

      AValue := Trim(AValue);

      if TAdvChartUtils.VarPos(' ',AValue, vp) > 0 then  // there is space to separate date & time
      begin
        ts := copy(AValue, vp, length(AValue));
        AValue := copy(AValue, 1, vp - 1);
      end;

      if (dp>mp) and
         (dp>yp) then
         val(AValue,da,err)
      else
      if (mp>dp) and
         (mp>yp) then
         val(AValue,mo,err)
      else
      if (yp>mp) and
         (yp>dp) then
         val(AValue,ye,err);

      if err<>0 then Exit;
      if (da>31) then Exit;
      if (mo>12) then Exit;

      if (ts <> '') then  // there is a time part
      begin
        if TAdvChartUtils.VarPos(FormatSettings.TimeSeparator,ts,vp)>0 then
        begin
          su := Copy(ts,1,vp - 1); // hour part
          val(su,ho,err);

          if (err <> 0) then Exit;
          if (ho > 23) then Exit;

          Delete(ts,1,vp);

          if TAdvChartUtils.VarPos(FormatSettings.TimeSeparator,ts,vp)>0 then // there is a second part
          begin
            su := Copy(ts,1,vp - 1); // minute part
            val(su,mi,err);

            if err <> 0 then Exit;
            Delete(ts,1,vp);

            val(ts,se,err);  // second part
            if (err <> 0) then Exit;
            if (se > 60) then Exit;
          end
          else
          begin
            val(su,mi,err); // minute part
            if (err <> 0) then Exit;
          end;

          if (mi > 59) then Exit;

          Result := true;
        end;
      end
      else
        Result := True;

      try
        ADate := EncodeDate(ye,mo,da) + EncodeTime(ho,mi,se,0);
      except
        Result := False;
      end;
    end;
  end;
end;

class function TAdvChartUtils.Matches(s0a,s1a: PChar): Boolean;
const
  larger = '>';
  smaller = '<';
  logand  = '&';
  logor   = '^';
  asterix = '*';
  qmark = '?';
  negation = '!';
  null = #0;

var
  matching:boolean;
  done:boolean;
  len:longint;
  lastchar:char;
  s0,s1,s2,s3:pchar;
  oksmaller,oklarger,negflag:boolean;
  compstr:array[0..255] of char;
  flag1,flag2,flag3:boolean;
  equal:boolean;
  n1,n2:double;
  code1,code2:Integer;
  dt1,dt2:TDateTime;
  q: integer;
begin
  oksmaller := True;
  oklarger := True;
  flag1 := False;
  flag2 := False;
  flag3 := False;
  negflag := False;
  equal := False;

  { [<>] string [&|] [<>] string }

  // do larger than or larger than or equal
  s2 := StrPos(s0a,larger);
  if s2 <> nil then
  begin
    inc(s2);
    if (s2^ = '=') then
    begin
      Equal := True;
      inc(s2);
    end;

    while (s2^ = ' ') do
      inc(s2);

    s3 := s2;
    len := 0;

    lastchar := #0;

    q := 0;

    while (s2^ <> ' ') and (s2^ <> NULL) and (odd(q) or ((s2^ <> '&') and (s2^ <> '|')))  do
    begin
      if (s2^= '"') then
        inc(q);

      if (len = 0) and (s2^ = '"') then
        inc(s3)
      else
        inc(len);

      lastchar := s2^;
      inc(s2);

      if (s2^= ' ') and odd(q) then // skip space if between quotes
      begin
        lastchar := s2^;
        inc(s2);
      end;
    end;

    if (len > 0) and (lastchar = '"') then
      dec(len);

    StrLCopy(compstr,s3,len);

    Val(StripThousandSep(s1a),n1,code1);
    Val(StripThousandSep(compstr),n2,code2);

    dt2 := 0;
    if IsDate(compstr,dt2) then
      code2 := 1;

    dt1 := 0;
    if IsDate(s1a,dt1) then
      code1 := 1;

    if (code1 = 0) and (code2 = 0) then {both are numeric types}
    begin
      if equal then
        oklarger := n1 >= n2
      else
        oklarger := n1 > n2;
    end
    else
    begin
      if IsDate(StrPas(compstr),dt2) and IsDate(StrPas(s1a),dt1) then
      begin
        if equal then
         oklarger := dt1 >= dt2
        else
         oklarger := dt1 > dt2;
      end
      else
      begin
        if equal then
         oklarger := (strlcomp(compstr,s1a,255)<=0)
        else
         oklarger := (strlcomp(compstr,s1a,255)<0);
      end;
    end;
    flag1 := True;
  end;

  equal := False;

  // do smaller than or smaller than or equal
  s2 := strpos(s0a,smaller);
  if (s2 <> nil) then
  begin
    inc(s2);
    if (s2^ = '=') then
      begin
       equal := True;
       inc(s2);
      end;

    lastchar := #0;

    while (s2^=' ') do inc(s2);
    s3 := s2;
    len := 0;
    q := 0;

    while (s2^ <> ' ') and (s2^ <> NULL) and (odd(q) or ((s2^ <> '&') and (s2^ <> '|'))) do
    begin
      if s2^ = '"' then
        inc(q);

      if (len = 0) and (s2^ = '"') then
        inc(s3)
      else
        inc(len);

      lastchar := s2^;
      inc(s2);
    end;

    if (len > 0) and (lastchar = '"') then
      dec(len);

    strlcopy(compstr,s3,len);

    Val(StripThousandSep(s1a),n1,code1);
    Val(StripThousandSep(compstr),n2,code2);
    if IsDate(compstr,dt2) then code2 := 1;
    if IsDate(s1a,dt1) then code1 := 1;

    if (code1 = 0) and (code2 = 0) then // both are numeric types
     begin
      if equal then
       oksmaller := n1 <= n2
      else
       oksmaller := n1 < n2;
     end
    else
     begin
      // check for dates here ?
      if IsDate(strpas(compstr),dt2) and IsDate(strpas(s1a),dt1) then
       begin
        if equal then
         oksmaller := dt1 <= dt2
        else
         oksmaller := dt1 < dt2;
       end
      else
       begin
        if equal then
          oksmaller := (strlcomp(compstr,s1a,255)>=0)
        else
          oksmaller := (strlcomp(compstr,s1a,255)>0);
       end;
     end;

    flag2 := True;
  end;

  s2 := strpos(s0a,negation);

  if (s2 <> nil) then
  begin
    inc(s2);
    while (s2^=' ') do
      inc(s2);
    s3 := s2;
    len := 0;

    lastchar := #0;
    q := 0;

    while (s2^ <> ' ') and (s2^ <> NULL) and (odd(q) or ((s2^ <> '&') and (s2^ <> '|'))) do
    begin
      if (s2^ = '"') then
        inc(q);

      if (len = 0) and (s2^ = '"') then
        inc(s3)
      else
        inc(len);

      lastchar := s2^;
      inc(s2);
    end;

    if (len > 0) and (lastchar = '"') then
      dec(len);

    strlcopy(compstr,s3,len);
    flag3 := True;
  end;

  if (flag3) then
  begin
    if strpos(s0a,larger) = nil then
      flag1 := flag3;
    if strpos(s0a,smaller) = nil then
      flag2 := flag3;
  end;

  if (strpos(s0a,logor) <> nil) then
    if flag1 or flag2 then
    begin
      matches := oksmaller or oklarger;
      Exit;
    end;

  if (strpos(s0a,logand)<>nil) then
    if flag1 and flag2 then
    begin
      matches := oksmaller and oklarger;
      Exit;
    end;

  if ((strpos(s0a,larger) <> nil) and (oklarger)) or
     ((strpos(s0a,smaller) <> nil) and (oksmaller)) then
  begin
    matches := True;
    Exit;
  end;

  s0 := s0a;
  s1 := s1a;

  matching := True;

  done := (s0^ = NULL) and (s1^ = NULL);

  while not done and matching do
  begin
    case s0^ of
    qmark:
      begin
        matching := s1^ <> NULL;
        if matching then
        begin
          inc(s0);
          inc(s1);
        end;
      end;
    negation:
      begin
        negflag:=True;
        inc(s0);
      end;
    '"':
      begin
        inc(s0);
      end;
    (*
    '\':
      begin
        inc(s0);
        matching := s0^ = s1^;

        if matching then
        begin
          inc(s0);
          inc(s1);
        end;
      end;
    *)
    asterix:
      begin
        repeat
          inc(s0)
        until (s0^ <> asterix);
        len := strlen(s1);
        inc(s1,len);
        matching := matches(s0,s1);
        while (len >= 0) and not matching do
        begin
         dec(s1);
         dec(len);
         matching := Matches(s0,s1);
       end;
       if matching then
       begin
         s0 := strend(s0);
         s1 := strend(s1);
       end;
     end;
   else
     begin
       matching := s0^ = s1^;

       if matching then
       begin
         inc(s0);
         inc(s1);
       end;
     end;
   end;

   Done := (s0^ = NULL) and (s1^ = NULL);
  end;

  if negflag then
    Matches := not matching
  else
    Matches := matching;
end;

class function TAdvChartUtils.MatchStr(AValue1, AValue2:string; ACaseSensitive:Boolean):Boolean;
begin
  if ACaseSensitive then
    MatchStr := Matches(PChar(AValue1),PChar(AValue2))
  else
    MatchStr := Matches(PChar(AnsiUpperCase(AValue1)),PChar(AnsiUpperCase(AValue2)));
end;

class function TAdvChartUtils.MatchStrEx(AValue1, AValue2: string; ACaseSensitive: Boolean): Boolean;
var
  ch,lastop: Char;
  sep,cp: Integer;
  res,newres: Boolean;
  CharArray: TAdvChartUtilsCharSet;
begin
  AValue1 := Trim(AValue1);
  AValue1 := StripLogicSpaces(AValue1);

  sep := -1;
  if TAdvChartUtils.VarPos('=', AValue1, sep) = 1 then
    Delete(AValue1, sep, 1);

  LastOp := #0;
  Res := True;

  SetLength(CharArray,5);
  CharArray[0] := '(';
  CharArray[1] := ';';
  CharArray[2] := '^';
  CharArray[3] := '&';
  CharArray[4] := '|';

  repeat
    ch := FirstChar(CharArray, AValue1, sep);
    if ch <> #0 then
    begin
      {$IFDEF FMXMOBILE}
      if (length(AValue1) > 0) and (AValue1[0] = '(') and (pos('(',AValue1) > 0) then
      {$ELSE}
      if (length(AValue1) > 0) and (AValue1[1] = '(') and (pos('(',AValue1) > 0) then
      {$ENDIF}
      begin
        cp := ClosingParenthesis(AValue1);
        NewRes := MatchStrEx(copy(AValue1,2,cp - 2),AValue2,ACaseSensitive);
        delete(AValue1,1,cp);
      end
      else
      begin
        NewRes := MatchStr(Copy(AValue1,1,sep - 1),AValue2,ACaseSensitive);
        Delete(AValue1,1,sep);
      end;

      if LastOp = #0 then
        Res := NewRes
      else
        case LastOp of
        ';','^','|':Res := Res or NewRes;
        '&':Res := Res and NewRes;
        end;

      LastOp := ch;
     end;

  until (ch = #0);

  NewRes := MatchStr(AValue1, AValue2, ACaseSensitive);

  if LastOp = #0 then
    Res := NewRes
  else
    case LastOp of
    ';','^','|':Res := Res or NewRes;
    '&':Res := Res and NewRes;
    end;

  Result := Res;
end;

class procedure TAdvChartUtils.Split(const ADelimiter: Char; AInput: string; const AStrings: TStrings);
begin
  AStrings.Clear;
  AStrings.Delimiter := ADelimiter;
  AStrings.StrictDelimiter := True;
  AStrings.DelimitedText := AInput;
end;

class function TAdvChartUtils.VarPos(ASubValue, AValue: string; var AResult: Integer): Integer;
begin
  AResult := Pos(ASubValue, AValue);
  Result := AResult;
end;

class function TAdvChartUtils.VarPosNoCase(ASubValue, AValue: string;
  var AResult: Integer): Integer;
begin
  AResult := Pos(Uppercase(ASubValue), Uppercase(AValue));
  Result := AResult;
end;

class function TAdvChartUtils.HTMLStrip(AHTML: string): string;
var
  TagPos: integer;
begin
  Result := '';
  // replace line breaks by linefeeds
  while (pos('<BR>',uppercase(AHTML))>0) do
    AHTML := StringReplace(AHTML,'<BR>',chr(13)+chr(10),[rfIgnoreCase]);

  while (pos('<HR>',uppercase(AHTML))>0) do
    AHTML := StringReplace(AHTML,'<HR>',chr(13)+chr(10),[rfIgnoreCase]);

  TagPos := 0;
  {remove all other tags}
  while (VarPos('<',AHTML,TagPos) > 0) do
  begin
    Result := Result + Copy(AHTML,1,TagPos-1);
    if (VarPos('>',AHTML,TagPos)>0) then
      Delete(AHTML,1,TagPos)
    else
      Break;
  end;
  Result := Result + AHTML;
end;

class function TAdvChartUtils.GetResourceStream(AResourceName: string): TResourceStream;
var
  hst: NativeUInt;
  function FindRCData(ModuleHandle: HMODULE; Name: string): boolean;
  begin
    Result := FindResource(ModuleHandle, PChar(Name), PChar(RT_RCDATA)) <> 0;
  end;
begin
  Result := nil;
  hst := HInstance;
  if FindRCData(hst, AResourceName) then
    Result := TResourceStream.Create(hst, AResourceName, RT_RCDATA);
end;

{ TAdvComponentHelper }

function TAdvComponentHelper.GetVersionNumber(AMaj, AMin, ARel,
  ABld: ShortInt): string;
var
  vn: Integer;
begin
  vn := MakeLong(MakeWord(ABld, ARel),MakeWord(AMin, AMaj));
  Result := IntToStr(Hi(Hiword(vn)))+'.'+IntToStr(Lo(Hiword(vn)))+'.'+IntToStr(Hi(Loword(vn)))+'.'+IntToStr(Lo(Loword(vn)));
end;

{$IFDEF CMNLIB}

{ TAdvControlHelper }

function TAdvControlHelper.MakeScreenshot: TAdvChartBitmap;
var
  bmp: Graphics.TBitmap;
begin
  bmp := Graphics.TBitmap.Create;
  bmp.SetSize(Width, Height);
  Result := TAdvChartBitmap.Create;
  try
    if (Self is TWinControl) and (Self as TWinControl).HandleAllocated then
      TWinControl(Self).PaintTo(bmp.Canvas.Handle, 0, 0);

    Result.Assign(bmp);
  finally
    bmp.Free;
  end;
end;

{$ENDIF}

{ TAdvClipBoard }

{$IFDEF FMXLIB}

class procedure TAdvClipBoard.Clear;
{$IFDEF MACOS}
var
{$IFDEF IOS}
  pb: UIPasteboard;
{$ELSE}
  pb: NSPasteboard;
{$ENDIF}
{$ENDIF}
{$IFDEF ANDROID}
var
  clip: IFMXClipboardService;
{$ENDIF}
begin
  {$IFDEF MSWINDOWS}
  OpenClipboard(0);
  try
    EmptyClipboard;
  finally
    CloseClipBoard;
  end;
  {$ENDIF}
  {$IFDEF MACOS}
  {$IFDEF IOS}
  pb := TUIPasteboard.Wrap(TUIPasteboard.OCClass.generalPasteboard);
  pb.setData(nil, CocoaNSStringConst(libUIKit, 'UIPasteboardNameGeneral'));
  {$ELSE}
  pb := TNSPasteboard.Wrap(TNSPasteboard.OCClass.generalPasteboard);
  pb.clearContents;
  {$ENDIF}
  {$ENDIF}
  {$IFDEF ANDROID}
  if TPlatformServices.Current.SupportsPlatformService(IFMXClipboardService, IInterface(clip)) then
    clip.SetClipboard('');
  {$ENDIF}
end;

class function TAdvClipBoard.GetHTML: String;
var
  val: TValue;
begin
  Result := '';
  val := GetValue(GetFormat(TAdvClipBoardFormat.cfHTML));
  if not val.IsEmpty and val.IsType<String> then
    Result := val.AsType<String>;
end;

{$IFDEF MSWINDOWS}
class function TAdvClipBoard.IsTextFormat(AFormat: Cardinal): Boolean;
{$ELSE}
class function TAdvClipBoard.IsTextFormat(AFormat: String): Boolean;
{$ENDIF}
begin
  Result := (AFormat = GetFormat(TAdvClipBoardFormat.cfText))
         or (AFormat = GetFormat(TAdvClipBoardFormat.cfRTF))
         or (AFormat = GetFormat(TAdvClipBoardFormat.cfHTML));
end;

{$IFDEF MSWINDOWS}
class function TAdvClipBoard.IsStreamFormat(AFormat: Cardinal): Boolean;
{$ELSE}
class function TAdvClipBoard.IsStreamFormat(AFormat: String): Boolean;
{$ENDIF}
begin
  Result := (AFormat = GetFormat(TAdvClipBoardFormat.cfStream)) or (AFormat = GetFormat(TAdvClipBoardFormat.cfBitmap))
         or (AFormat = GetFormat(TAdvClipBoardFormat.cfRichTextStream));
end;

{$IFDEF MSWINDOWS}
class function TAdvClipBoard.GetFormat(AFormat: TAdvClipBoardFormat): Cardinal;
begin
  Result := 0;
  case AFormat of
    TAdvClipBoardFormat.cfText: Result := CF_TEXT;
    TAdvClipBoardFormat.cfRTF: Result := CF_FNCRTF;
    TAdvClipBoardFormat.cfHTML: Result := CF_FNCHTML;
    TAdvClipBoardFormat.cfStream: Result := CF_FNCSTREAM;
    TAdvClipBoardFormat.cfBitmap: Result := CF_FNCBITMAP;
    TAdvClipBoardFormat.cfBitmapWin: Result := CF_FNCBITMAPWIN;
    TAdvClipBoardFormat.cfRichTextStream: Result := CF_FNCRICHTEXTSTREAM;
  end;
end;
{$ELSE}
class function TAdvClipBoard.GetFormat(AFormat: TAdvClipBoardFormat): string;
begin
  Result := '';
  case AFormat of
    TAdvClipBoardFormat.cfText: Result := 'public.utf8-plain-text';
    TAdvClipBoardFormat.cfRTF: Result := 'public.rtf';
    TAdvClipBoardFormat.cfHTML: Result := 'public.html';
    TAdvClipBoardFormat.cfStream: Result := 'TAdvClipBoard.StreamFormat';
    {$IFDEF IOS}
    TAdvClipBoardFormat.cfBitmap: Result := 'public.png';
    {$ELSE}
    TAdvClipBoardFormat.cfBitmap: Result := 'public.image';
    {$ENDIF}
    TAdvClipBoardFormat.cfRichTextStream: Result := 'RichEditorText';
  end;
end;
{$ENDIF}

class function TAdvClipBoard.GetRTF: String;
var
  val: TValue;
begin
  Result := '';
  val := GetValue(GetFormat(TAdvClipBoardFormat.cfRTF));
  if not val.IsEmpty and val.IsType<String> then
    Result := val.AsType<String>;
end;

class function TAdvClipBoard.GetBitmap: TAdvChartBitmap;
var
  val: TValue;
  ms: TMemoryStream;
begin
  Result := nil;
  val := GetValue(GetFormat(TAdvClipBoardFormat.cfBitmap));
  if not val.IsEmpty and val.IsType<TMemoryStream> then
  begin
    Result := TAdvChartBitmap.Create;
    Result.LoadFromStream(val.AsType<TMemoryStream>);
    ms := val.AsType<TMemoryStream>;
    ms.Free;
  end;
end;

class function TAdvClipBoard.GetStream: TMemoryStream;
var
  val: TValue;
begin
  Result := nil;
  val := GetValue(GetFormat(TAdvClipBoardFormat.cfStream));
  if not val.IsEmpty and val.IsType<TMemoryStream> then
    Result := val.AsType<TMemoryStream>;
end;

class function TAdvClipBoard.GetRichTextStream: TMemoryStream;
var
  val: TValue;
begin
  Result := nil;
  val := GetValue(GetFormat(TAdvClipBoardFormat.cfRichTextStream));
  if not val.IsEmpty and val.IsType<TMemoryStream> then
    Result := val.AsType<TMemoryStream>;
end;

class function TAdvClipBoard.GetText: String;
var
  val: TValue;
begin
  Result := '';
  val := GetValue(GetFormat(TAdvClipBoardFormat.cfText));
  if not val.IsEmpty and val.IsType<String> then
    Result := val.AsType<String>;
end;

{$IFDEF MSWINDOWS}
class function TAdvClipBoard.AllocateCustomValue(AFormat: Cardinal; AValue: TValue): THandle;
begin
  Result := 0;
end;

class procedure TAdvClipBoard.SetCustomValue(AFormat: Cardinal; AValue: TValue; var AData: Pointer);
{$ELSE}
{$IFDEF MACOS}
class function TAdvClipBoard.SetCustomValue(AFormat: String; AValue: TValue): NSData;
{$ELSE}
class function TAdvClipBoard.SetCustomValue(AFormat: String; AValue: TValue): Pointer;
{$ENDIF}
{$ENDIF}
begin
  {$IFNDEF MSWINDOWS}
  Result := nil;
  {$ENDIF}
end;

{$IFDEF MSWINDOWS}
class function TAdvClipBoard.GetCustomValue(AFormat: Cardinal; AData: Pointer): TValue;
{$ELSE}
{$IFDEF MACOS}
class function TAdvClipBoard.GetCustomValue(AFormat: String; AData: NSData): TValue;
{$ELSE}
class function TAdvClipBoard.GetCustomValue(AFormat: String; AData: Pointer): TValue;
{$ENDIF}
{$ENDIF}
begin
  Result := nil;
end;

{$IFDEF MSWINDOWS}
class function TAdvClipBoard.GetValue(AFormat: Cardinal): TValue;
{$ELSE}
class function TAdvClipBoard.GetValue(AFormat: String): TValue;
{$ENDIF}
{$IFDEF MACOS}
var
  dt: NSData;
  str: NSString;
  I: Integer;
  arr: NSArray;
{$IFDEF IOS}
  dtObj: NSObject;
  dtp: Pointer;
  pb: UIPasteboard;
  dic: NSDictionary;
  K: Integer;
  kp: Pointer;
  key: String;
{$ELSE}
  pb: NSPasteboard;
  pbit: NSPasteboardItem;
{$ENDIF}
{$ENDIF}
{$IFDEF MSWINDOWS}
var
  hMem: THandle;
  pMem: Pointer;
  txt: string;
{$ENDIF}
{$IFDEF ANDROID}
var
  clip: IFMXClipboardService;
{$ENDIF}
begin
  Result := nil;
{$IFDEF MACOS}
  {$IFDEF IOS}
  pb := TUIPasteboard.Wrap(TUIPasteboard.OCClass.generalPasteboard);
  arr := pb.items;
  for I := 0 to arr.count - 1 do
  begin
    dic := TNSDictionary.Wrap(arr.objectAtIndex(I));
    for K := 0 to dic.allKeys.count - 1 do
    begin
      kp := dic.allKeys.objectAtIndex(K);
      key := UTF8ToString(TNSString.Wrap(kp).UTF8String);
      if key = AFormat then
      begin
        dtp := dic.objectForKey(kp);
        dtobj := TNSObject.Wrap(dtp);
        if isStreamFormat(AFormat) then
        begin
          dt := TNSData.Wrap(dtp);
          if Assigned(dt) then
          begin
            Result := TMemoryStream.Create;
            Result.AsType<TMemoryStream>.Write(dt.bytes^, dt.length);
            Result.AsType<TMemoryStream>.Position := 0;
            Exit;
          end;
        end
        else if isTextFormat(AFormat) then
        begin
          str := TNSString.Wrap(dtp);
          Result := UTF8ToString(str.UTF8String);
          Exit;
        end
        else
          Result := GetCustomValue(AFormat, TNSData.Wrap(dtp));
      end;
    end;
  end;
  {$ELSE}
  pb := TNSPasteboard.Wrap(TNSPasteboard.OCClass.generalPasteboard);
  arr := pb.pasteboardItems;
  for I := 0 to arr.count - 1 do
  begin
    pbit := TNSPasteboardItem.Wrap(arr.objectAtIndex(I));
    if isTextFormat(AFormat) then
    begin
      str := pbit.stringForType(TAdvChartUtils.NSStrEx(AFormat));
      if Assigned(str) then
      begin
        Result := UTF8ToString(str.UTF8String);
        Exit;
      end;
    end
    else if isStreamFormat(AFormat) then
    begin
      if AFormat = 'public.image' then
      begin
        dt := pbit.dataForType(TAdvChartUtils.NSStrEx('public.png'));
        if not Assigned(dt) then
        begin
          dt := pbit.dataForType(TAdvChartUtils.NSStrEx('public.tiff'));
          if not Assigned(dt) then
            dt := pbit.dataForType(TAdvChartUtils.NSStrEx('public.jpeg'));
        end;
      end
      else
        dt := pbit.dataForType(TAdvChartUtils.NSStrEx(AFormat));

      if Assigned(dt) then
      begin
        Result := TMemoryStream.Create;
        Result.AsType<TMemoryStream>.Write(dt.bytes^, dt.length);
        Result.AsType<TMemoryStream>.Position := 0;
        Exit;
      end;
    end
    else
      Result := GetCustomValue(AFormat, pbit.dataForType(TAdvChartUtils.NSStrEx(AFormat)));
  end;
  {$ENDIF}
{$ENDIF}

{$IFDEF MSWINDOWS}
  if AFormat = CF_TEXT then
  begin
    if HasFormat(CF_UNICODETEXT) then
      AFormat := CF_UNICODETEXT;
  end;

  OpenClipboard(0);
  try
    hMem := GetClipboardData(AFormat);
  finally
    CloseClipboard;
  end;

  if hMem <> 0 then
  begin
    pMem := GlobalLock(hMem);
    if pMem <> nil then
    begin
      try
        if isStreamFormat(AFormat) then
        begin
          Result := TMemoryStream.Create;
          Result.AsType<TMemoryStream>.Write(pMem^, GlobalSize(hMem));
          Result.AsType<TMemoryStream>.Position := 0;
        end
        else if isTextFormat(AFormat) or (AFormat = CF_UNICODETEXT) then
        begin
          if AFormat = CF_UNICODETEXT then
            txt := PChar(pMem)
          else
            txt := UTF8ToString(pMem);

          Result := txt;
        end
        else
          Result := GetCustomValue(AFormat, pMem);
      finally
        GlobalUnlock(hMem);
      end;
    end;
  end;
{$ENDIF}

{$IFDEF ANDROID}
  if TPlatformServices.Current.SupportsPlatformService(IFMXClipboardService, IInterface(clip)) then
    Result := clip.GetClipboard;
{$ENDIF}
end;

class function TAdvClipBoard.HasFormat(AFormat: TAdvClipBoardFormat): Boolean;
begin
  Result := HasFormat(GetFormat(AFormat));
end;

{$IFDEF MSWINDOWS}
class function TAdvClipBoard.HasFormat(AFormat: Cardinal): Boolean;
begin
  Result := False;
  try
    OpenClipboard(0);
    Result := Boolean(IsClipboardFormatAvailable(AFormat));
    CloseClipboard;
  except
  end;
end;
{$ELSE}
class function TAdvClipBoard.HasFormat(AFormat: String): Boolean;
var
  {$IFDEF MACOS}
  {$IFDEF IOS}
  I, K: Integer;
  kp: Pointer;
  key: String;
  pb: UIPasteBoard;
  arr: NSArray;
  dic: NSDictionary;
  {$ELSE}
  I: Integer;
  pb: NSPasteBoard;
  pbi: NSPasteboardItem;
  str: NSString;
  {$ENDIF}
  {$ELSE}
  clip: IFMXClipboardService;
  {$ENDIF}
begin
  Result := False;
  {$IFDEF MACOS}
  {$IFDEF IOS}
  pb := TUIPasteboard.Wrap(TUIPasteboard.OCClass.generalPasteboard);
  arr := pb.items;
  for I := 0 to arr.count - 1 do
  begin
    dic := TNSDictionary.Wrap(arr.objectAtIndex(I));
    for K := 0 to dic.allKeys.count - 1 do
    begin
      kp := dic.allKeys.objectAtIndex(K);
      key := UTF8ToString(TNSString.Wrap(kp).UTF8String);
      if key = AFormat then
      begin
        Result := True;
        Exit;
      end;
    end;
  end;
  {$ELSE}
  pb := TNSPasteboard.Wrap(TNSPasteboard.OCClass.generalPasteboard);
  for I := 0 to pb.pasteboardItems.count - 1 do
  begin
    pbi := TNSPasteboardItem.Wrap(pb.pasteboardItems.objectAtIndex(I));
    str := pbi.availableTypeFromArray(TNSArray.Wrap(TNSArray.OCClass.arrayWithObject((TAdvChartUtils.NSStrEx(AFormat) as ILocalObject).GetObjectID)));
    if Assigned(str) then
    begin
      Result := True;
      Exit;
    end;
  end;
  {$ENDIF}
  {$ELSE}
  if TPlatformServices.Current.SupportsPlatformService(IFMXClipboardService, IInterface(clip)) then
    Result := not clip.GetClipboard.IsEmpty;
  {$ENDIF}
end;
{$ENDIF}

class procedure TAdvClipBoard.SetHTML(AHTML: String);
begin
  SetValue(AHTML, GetFormat(TAdvClipBoardFormat.cfHTML));
end;

class procedure TAdvClipBoard.SetRTF(ARTF: String);
begin
  SetValue(ARTF, GetFormat(TAdvClipBoardFormat.cfRTF));
end;

class procedure TAdvClipBoard.SetStream(AStream: TMemoryStream);
begin
  SetValue(AStream, GetFormat(TAdvClipBoardFormat.cfStream));
end;

{$IFDEF MSWINDOWS}
class function TAdvClipBoard.GetBitmapWin: TAdvChartBitmap;
var
  Header: TBitmapFileHeader;
  DataHandle: HGLOBAL;
  BitmapInfoPtr: PBitmapV5Header;
  Stream: TMemoryStream;
begin
  Result := nil;
  OpenClipboard(0);
  DataHandle := GetClipboardData(CF_DIB);
  BitmapInfoPtr := nil;
  if DataHandle <> 0 then
    BitmapInfoPtr := GlobalLock(DataHandle);

  if Assigned(BitmapInfoPtr) then
  begin
    Stream := TMemoryStream.Create;
    try
      FillChar(Header, SizeOf(Header), 0);
      Header.bfType := $4D42;
      Header.bfSize := SizeOf(Header) + GlobalSize(DataHandle);
      Header.bfOffBits := SizeOf(Header) + BitmapInfoPtr.bV5Size;
      Stream.WriteBuffer(Header, SizeOf(Header));
      Stream.WriteBuffer(BitmapInfoPtr^, Header.bfSize - SizeOf(Header));
      Stream.Position := 0;
      Result := TAdvChartBitmap.Create;
      Result.LoadFromStream(Stream);
    finally
      GlobalUnlock(DataHandle);
      Stream.Free;
      CloseClipboard;
    end;
  end;
end;

class procedure TAdvClipBoard.SetBitmapWin(ABitmap: TAdvChartBitmap);
var
  Data: THandle;
  DataPtr: Pointer;
  BitmapHeader: TBitmapInfoHeader;
  BitmapData: TBitmapData;
  I, J: Integer;
  DIBDataPtr: Pointer;
begin
  OpenClipboard(0);
  try
    FillChar(BitmapHeader, SizeOf(BitmapHeader), 0);
    BitmapHeader.biSize := SizeOf(TBitmapInfoHeader);
    BitmapHeader.biPlanes := 1;
    BitmapHeader.biBitCount := 32;
    BitmapHeader.biCompression := BI_RGB;

    BitmapHeader.biWidth := ABitmap.Width;
    BitmapHeader.biHeight := ABitmap.Height;
    BitmapHeader.biSizeImage := ABitmap.BytesPerPixel * ABitmap.Width * ABitmap.Height;

    if BitmapHeader.biWidth <= 0 then
      BitmapHeader.biWidth := 1;
    if BitmapHeader.biHeight <= 0 then
      BitmapHeader.biHeight := 1;

    Data := GlobalAlloc(GMEM_MOVEABLE + GMEM_DDESHARE, BitmapHeader.biWidth * Abs(BitmapHeader.biHeight) * 4 + SizeOf(BitmapHeader));
    try
      DataPtr := GlobalLock(Data);
      try
        Move(BitmapHeader, DataPtr^, SizeOf(BitmapHeader));
        DIBDataPtr := @(PByteArray(DataPtr)[SizeOf(BitmapHeader)]);

        if ABitmap.Map(TMapAccess.Read, BitmapData) then
        try
          if BitmapData.PixelFormat = TPixelFormat.BGRA then
            for I := 0 to ABitmap.Height - 1 do
              Move(PAlphaColorArray(BitmapData.Data)[I * (BitmapData.Pitch div 4)],
                PAlphaColorArray(DIBDataPtr)[(ABitmap.Height - 1 - I) * ABitmap.Width], ABitmap.Width * 4)
          else
            for I := 0 to ABitmap.Height - 1 do
              for J := 0 to ABitmap.Width - 1 do
                PAlphaColorArray(DIBDataPtr)[(ABitmap.Height - 1 - I) * ABitmap.Width + J] :=
                  BitmapData.GetPixel(J, I);
        finally
          ABitmap.Unmap(BitmapData);
        end;
      finally
        GlobalUnlock(Data);
      end;
      SetClipboardData(CF_DIB, Data);
    except
      GlobalFree(Data);
      raise;
    end;
  finally
    CloseClipboard;
  end;
end;

{$ENDIF}

class procedure TAdvClipBoard.SetBitmap(ABitmap: TAdvChartBitmap);
var
  ms: TMemoryStream;
begin
  ms := TMemoryStream.Create;
  try
    ABitmap.SaveToStream(ms);
    SetValue(ms, GetFormat(TAdvClipBoardFormat.cfBitmap));
  finally
    ms.Free;
  end;
end;

class procedure TAdvClipBoard.SetRichTextStream(AStream: TMemoryStream);
begin
  SetValue(AStream, GetFormat(TAdvClipBoardFormat.cfRichTextStream));
end;

class procedure TAdvClipBoard.SetText(AText: String);
begin
  SetValue(AText, GetFormat(TAdvClipBoardFormat.cfText));
end;

{$IFDEF MSWINDOWS}
class procedure TAdvClipBoard.SetValue(AValue: TValue; AFormat: Cardinal);
{$ELSE}
class procedure TAdvClipBoard.SetValue(AValue: TValue; AFormat: String);
{$ENDIF}
{$IFDEF MACOS}
var
{$IFDEF IOS}
  pb: UIPasteboard;
  dic: NSDictionary;
  pValue: Pointer;
{$ELSE}
  pb: NSPasteboard;
  pbit: NSPasteboardItem;
{$ENDIF}
{$ENDIF}
{$IFDEF MSWINDOWS}
var
  hMem: THandle;
  pMem: Pointer;
  txt: string;
  l: integer;
{$ENDIF}
{$IFDEF ANDROID}
var
  clip: IFMXClipboardService;
{$ENDIF}
begin
  if AValue.IsObject then
  begin
    if AValue.IsType<TMemoryStream> then
      AValue.AsType<TMemoryStream>.Position := 0;
  end;

  {$IFDEF MACOS}
  {$IFDEF IOS}
  pb := TUIPasteboard.Wrap(TUIPasteboard.OCClass.generalPasteboard);
  if AValue.IsType<TMemoryStream> then
    pValue := TNSData.OCClass.dataWithBytes(AValue.AsType<TMemoryStream>.Memory, AValue.AsType<TMemoryStream>.Size)
  else if AValue.IsType<String> then
    pValue := (TAdvChartUtils.NSStrEx(AValue.AsType<String>) as ILocalObject).GetObjectID
  else
    pValue := (SetCustomValue(AFormat, AValue) as ILocalObject).GetObjectID;

  if Assigned(pValue) then
  begin
    dic := TNSDictionary.Wrap(TNSDictionary.OCClass.dictionaryWithObject(pValue, (TAdvChartUtils.NSStrEx(AFormat) as ILocalObject).GetObjectID));
    pb.addItems(TNSArray.Wrap(TNSArray.OCClass.arrayWithObject((dic as ILocalObject).GetObjectID)));
  end;
  {$ELSE}
  pb := TNSPasteboard.Wrap(TNSPasteboard.OCClass.generalPasteboard);
  pbit := TNSPasteboardItem.Wrap(TNSPasteboardItem.Wrap(TNSPasteboardItem.OCClass.alloc).init);
  if AValue.IsType<TMemoryStream> then
    pbit.setData(TNSData.Wrap(TNSData.OCClass.dataWithBytes(AValue.AsType<TMemoryStream>.Memory, AValue.AsType<TMemoryStream>.Size)), TAdvChartUtils.NSStrEx(AFormat))
  else if AValue.IsType<String> then
    pbit.setData(TAdvChartUtils.NSStrEx(AValue.AsType<String>).dataUsingEncoding(NSUTF8StringEncoding), TAdvChartUtils.NSStrEx(AFormat))
  else
    pbit.setData(SetCustomValue(AFormat, AValue), TAdvChartUtils.NSStrEx(AFormat));

  pb.writeObjects(TNSArray.Wrap(TNSArray.OCClass.arrayWithObject((pbit as ILocalObject).GetObjectID)));
  {$ENDIF}
{$ENDIF}

{$IFDEF MSWINDOWS}
  if AValue.IsObject and AValue.IsType<TMemoryStream> then
    hMem := GlobalAlloc(GHND or GMEM_DDESHARE, AValue.AsType<TMemoryStream>.Size)
  else if AValue.IsType<String> then
  begin
    txt := AValue.AsString;
    if AFormat = CF_FNCRTF then
    begin
      l := Length(txt) + 1;
      hMem := GlobalAlloc(GHND or GMEM_DDESHARE, l)
    end
    else
    begin
      l := ByteLength(txt) + SizeOf(Char);
      hMem := GlobalAlloc(GHND or GMEM_DDESHARE, l)
    end;
  end
  else
    hMem := AllocateCustomValue(AFormat, AValue);

  if hMem <> 0 then
  begin
    pMem := GlobalLock(hMem);
    if pMem <> nil then
    begin
      try
        if AValue.IsObject and AValue.IsType<TMemoryStream> then
        begin
          AValue.AsType<TMemoryStream>.Read(pMem^, AValue.AsType<TMemoryStream>.Size);
          AValue.AsType<TMemoryStream>.Position := 0;
        end
        else if AValue.IsType<string> then
        begin
          if AFormat = CF_FNCRTF then
          begin
            {$HINTS OFF}
            {$IF COMPILERVERSION > 24}
            AnsiStrings.StrCopy(pMem, PAnsiChar(AnsiString(txt)));
            {$ELSE}
            StrCopy(PAnsiChar(pMem), PAnsiChar(AnsiString(txt)));
            {$IFEND}
            {$HINTS ON}
          end
          else
          begin
            if AFormat = CF_TEXT then
              AFormat := CF_UNICODETEXT;

            Move(PChar(txt)^, pMem^, ByteLength(txt) + SizeOf(Char));
          end;
        end
        else
          SetCustomValue(AFormat, AValue, pMem);
      finally
        GlobalUnlock(hMem);
      end;
      OpenClipboard(0);
      try
        SetClipboardData(AFormat, hmem);
      finally
        CloseClipboard;
      end;
    end
    else
    begin
      GlobalFree(hMem);
    end;
  end;
{$ENDIF}

{$IFDEF ANDROID}
  if TPlatformServices.Current.SupportsPlatformService(IFMXClipboardService, IInterface(clip)) then
    clip.SetClipboard(AValue);
{$ENDIF}
end;
{$ENDIF}

{$IFDEF CMNLIB}
class function TAdvClipBoard.HasFormat(AFormat: TAdvClipBoardFormat): Boolean;
begin
  Result := False;
  case AFormat of
    TAdvClipBoardFormat.cfText: Result := Clipboard.HasFormat(CF_TEXT);
    TAdvClipBoardFormat.cfRTF: Result := Clipboard.HasFormat(CF_FNCRTF);
    TAdvClipBoardFormat.cfHTML: Result := Clipboard.HasFormat(CF_FNCHTML);
    TAdvClipBoardFormat.cfStream: Result := Clipboard.HasFormat(CF_FNCSTREAM);
    TAdvClipBoardFormat.cfBitmap: Result := Clipboard.HasFormat(CF_FNCBITMAP);
    TAdvClipBoardFormat.cfRichTextStream: Result := Clipboard.HasFormat(CF_FNCRICHTEXTSTREAM);
  end;
end;

class function TAdvClipBoard.GetFormat(AFormat: TAdvClipBoardFormat): string;
begin
  Result := '';
  {$IFDEF MSWINDOWS}
  case AFormat of
    TAdvClipBoardFormat.cfText: Result := 'text/plain';
    TAdvClipBoardFormat.cfRTF: Result := 'Rich Text Format';
    TAdvClipBoardFormat.cfHTML: Result := 'HTML Format';
    TAdvClipBoardFormat.cfStream: Result := 'TAdvClipBoard.StreamFormat';
    TAdvClipBoardFormat.cfBitmap: Result := 'Delphi Picture';
    TAdvClipBoardFormat.cfRichTextStream: Result := 'RichEditorText';
  end;
  {$ENDIF}
  {$IFDEF LINUX}
  case AFormat of
    TAdvClipBoardFormat.cfText: Result := 'text/plain';
    TAdvClipBoardFormat.cfRTF: Result := 'text/richtext';
    TAdvClipBoardFormat.cfHTML: Result := 'text/html';
    TAdvClipBoardFormat.cfStream: Result := 'TAdvClipBoard.StreamFormat';
    TAdvClipBoardFormat.cfBitmap: Result := 'Delphi Picture';
    TAdvClipBoardFormat.cfRichTextStream: Result := 'RichEditorText';
  end;
  {$ENDIF}
  {$IFDEF DARWIN}
  case AFormat of
    TAdvClipBoardFormat.cfText: Result := 'text/plain';
    TAdvClipBoardFormat.cfRTF: Result := 'text/rtf';
    TAdvClipBoardFormat.cfHTML: Result := 'text/html';
    TAdvClipBoardFormat.cfStream: Result := 'TAdvClipBoard.StreamFormat';
    TAdvClipBoardFormat.cfBitmap: Result := 'Delphi Picture';
    TAdvClipBoardFormat.cfRichTextStream: Result := 'RichEditorText';
  end;
  {$ENDIF}
end;

class procedure TAdvClipBoard.Clear;
begin
  Clipboard.Clear;
end;

class procedure TAdvClipBoard.SetText(AText: String);
begin
  {$IFDEF VCLLIB}
  Clipboard.AsText := AText;
  {$ENDIF}
  {$IFDEF LCLLIB}
  Clipboard.SetTextBuf(PChar(AText));
  {$ENDIF}
end;

class function TAdvClipBoard.GetText: String;
begin
  Result := Clipboard.AsText;
end;

class procedure TAdvClipBoard.SetStream(AStream: TMemoryStream);
{$IFDEF VCLLIB}
var
  Data: THandle;
  DataPtr: Pointer;
begin
  Clipboard.Open;
  try
    Data := GlobalAlloc(GMEM_MOVEABLE + GMEM_DDESHARE, AStream.Size);
    try
      DataPtr := GlobalLock(Data);
      try
        Move(AStream.Memory^, DataPtr^, AStream.Size);
        SetClipboardData(CF_FNCSTREAM, Data);
      finally
        GlobalUnlock(Data);
      end;
    except
      GlobalFree(Data);
      raise;
    end;
  finally
    Clipboard.Close;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
begin
  Clipboard.Open;
  try
    Clipboard.AddFormat(CF_FNCSTREAM, AStream);
  finally
    Clipboard.Close;
  end;
{$ENDIF}
end;

class function TAdvClipBoard.GetStream: TMemoryStream;
{$IFDEF VCLLIB}
var
  DataPtr: Pointer;
  Data: THandle;
begin
  Result := nil;
  Clipboard.Open;
  try
    Data := GetClipboardData(CF_FNCSTREAM);
    if Data <> 0 then
    begin
      DataPtr := GlobalLock(Data);
      if Assigned(DataPtr) then
      begin
        Result := TMemoryStream.Create;
        Result.WriteBuffer(DataPtr^, GlobalSize(Data));
        Result.Position := 0;
      end;
    end;
  finally
    Clipboard.Close;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
var
  fmt: TClipboardFormat;
begin
  Result := nil;
  fmt := Clipboard.FindFormatID(GetFormat(cfStream));
  if fmt <> 0 then
  begin
    Result := TMemoryStream.Create;
    Clipboard.GetFormat(fmt, Result);
    Result.Position := 0;
  end;
{$ENDIF}
end;

class procedure TAdvClipBoard.SetBitmap(ABitmap: TAdvChartBitmap);
{$IFDEF VCLLIB}
var
  pic: TGraphic;
  ms, ds: TMemoryStream;
  gcc: TGraphicClass;
begin
  pic := nil;

  if IsBitmapEmpty(ABitmap) then
    Exit;

  ds := TMemoryStream.Create;
  try
    ABitmap.SaveToStream(ds);
    ds.Position := 0;
    if TAdvChartUtils.FindGraphicClass(ds.Memory^, ds.Size, gcc) then
      pic := gcc.Create;
  finally
    ds.Free;
  end;

  if Assigned(pic) then
  begin
    try
      ms := TMemoryStream.Create;
      try
        ABitmap.SaveToStream(ms);
        ms.Position := 0;
        pic.LoadFromStream(ms);
      finally
        ms.Free;
      end;

      Clipboard.Open;
      try
        Clipboard.Assign(pic);
      finally
        Clipboard.Close;
      end;

    finally
      pic.Free;
    end;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
begin
  if IsBitmapEmpty(ABitmap) then
    Exit;

  ClipBoard.Open;
  try
    ClipBoard.Assign(ABitmap.Graphic);
  finally
    ClipBoard.Close;
  end;
{$ENDIF}
end;

class function TAdvClipBoard.GetBitmap: TAdvChartBitmap;
begin
  Result := TAdvChartBitmap.Create;
  Result.Assign(Clipboard);
end;

class procedure TAdvClipBoard.SetRichTextStream(AStream: TMemoryStream);
{$IFDEF VCLLIB}
var
  Data: THandle;
  DataPtr: Pointer;
begin
  Clipboard.Open;
  try
    Data := GlobalAlloc(GMEM_MOVEABLE + GMEM_DDESHARE, AStream.Size);
    try
      DataPtr := GlobalLock(Data);
      try
        Move(AStream.Memory^, DataPtr^, AStream.Size);
        SetClipboardData(CF_FNCRICHTEXTSTREAM, Data);
      finally
        GlobalUnlock(Data);
      end;
    except
      GlobalFree(Data);
      raise;
    end;
  finally
    Clipboard.Close;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
begin
  Clipboard.Open;
  try
    Clipboard.AddFormat(CF_FNCRICHTEXTSTREAM, AStream);
  finally
    Clipboard.Close;
  end;
{$ENDIF}
end;

class function TAdvClipBoard.GetRichTextStream: TMemoryStream;
{$IFDEF VCLLIB}
var
  DataPtr: Pointer;
  Data: THandle;
begin
  Result := nil;
  Clipboard.Open;
  try
    Data := GetClipboardData(CF_FNCRICHTEXTSTREAM);
    if Data <> 0 then
    begin
      DataPtr := GlobalLock(Data);
      if Assigned(DataPtr) then
      begin
        Result := TMemoryStream.Create;
        Result.WriteBuffer(DataPtr^, GlobalSize(Data));
        Result.Position := 0;
      end;
    end;
  finally
    Clipboard.Close;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
var
  fmt: TClipboardFormat;
begin
  Result := nil;
  fmt := Clipboard.FindFormatID(GetFormat(cfRichTextStream));
  if fmt <> 0 then
  begin
    Result := TMemoryStream.Create;
    Clipboard.GetFormat(fmt, Result);
    Result.Position := 0;
  end;
{$ENDIF}
end;

class procedure TAdvClipBoard.SetRTF(ARTF: String);
{$IFDEF VCLLIB}
var
  rtfstr: ansistring;
  MemHandleRTF: THandle;
begin
  Clipboard.Open;
  try
    rtfstr := ansistring(ARTF);

    MemHandleRTF := GlobalAlloc(GHND or GMEM_SHARE, Length(rtfstr) + 1);

    if (MemHandleRTF <> 0) then
    begin
      {$HINTS OFF}
      {$IF COMPILERVERSION > 24}
      AnsiStrings.StrCopy(GlobalLock(MemHandleRTF), PAnsiChar(rtfstr));
      {$ELSE}
      StrCopy(PAnsiChar(GlobalLock(MemHandleRTF)), PAnsiChar(rtfstr));
      {$IFEND}
      {$HINTS ON}
      GlobalUnlock(MemHandleRTF);
      SetClipboardData(CF_FNCRTF, MemHandleRTF);
    end;
  finally
    Clipboard.Close;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
begin
  Clipboard.Open;
  try
    Clipboard.AddFormat(CF_FNCRTF, ARTF[1], Length(ARTF));
  finally
    Clipboard.Close;
  end;
{$ENDIF}
end;

class function TAdvClipBoard.GetRTF: String;
{$IFDEF VCLLIB}
var
  hClip: THandle;
  bufptr: Pointer;
  mstream: TStringStream;
begin
  Result := '';
  Clipboard.Open;
  try
    HClip := Clipboard.GetAsHandle(CF_FNCRTF);
    bufptr := GlobalLock(HClip);
    if bufptr <> nil then
    begin
      try
        mstream := TStringStream.Create('');
        try
          mstream.WriteBuffer(bufptr^, GlobalSize(HClip));
          Result := mstream.DataString;
        finally
          mstream.Free;
        end;
      finally
        GlobalUnlock(HClip);
      end;
    end;
  finally
    Clipboard.Close;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
var
  fmt: TClipboardFormat;
  ms: TMemoryStream;
  sz: int64;
begin
  Result := '';
  fmt := Clipboard.FindFormatID(GetFormat(cfRTF));
  if fmt <> 0 then
  begin
    ms := TMemoryStream.Create;
    try
      if Clipboard.GetFormat(fmt, ms) then
      begin
        sz := ms.Size;
        if (sz > 0) and (PChar(ms.Memory)[sz - 1]=#0) then
          Dec(sz);

        ms.Position := 0;
        SetLength(Result, sz);
        if sz > 0 then
          ms.Read(Result[1], sz);
      end;
    finally
      ms.Free;
    end;
  end;
{$ENDIF}
end;

class procedure TAdvClipBoard.SetHTML(AHTML: String);
{$IFDEF VCLLIB}
var
  htmlstr: ansistring;
  MemHandleHTML: THandle;
begin
  htmlstr := AnsiString(AHTML);
  htmlstr := AnsiString('Version:0.9'#13#10
    +'StartHTML:71'#13#10
    +'EndHTML:'+inttostr(length(htmlstr) + 71)+#13#10
    +'StartFragment:140'#13#10
    +'EndFragment:'+inttostr(length(htmlstr)+ 142)+#13#10
    +'<!DOCTYPE>' +#13#10
    +'<HTML>'#13#10
    +'<HEAD>'#13#10
    +'<TITLE>The HTML Clipboard</TITLE>'#13#10
    +'<BASE HREF="http://sample/specs">'#13#10
    +'</HEAD>'#13#10
    +'<BODY>'#13#10
    +'<!--StartFragment -->'#13#10)
    + htmlstr + AnsiString(#13#10
    +'<!--StartFragment -->'#13#10
    +'</BODY>'#13#10
    +'</HTML>'#13#10);

  Clipboard.Open;
  try
    MemHandleHTML := GlobalAlloc(GHND or GMEM_SHARE, Length(htmlstr) + 1);

    if (MemHandleHTML <> 0) then
    begin
      {$HINTS OFF}
      {$IF COMPILERVERSION > 24}
      AnsiStrings.StrCopy(GlobalLock(MemHandleHTML), PAnsiChar(htmlstr));
      {$ELSE}
      StrCopy(PAnsiChar(GlobalLock(MemHandleHTML)), PAnsiChar(htmlstr));
      {$IFEND}
      {$HINTS ON}
      GlobalUnlock(MemHandleHTML);
      SetClipboardData(CF_FNCHTML, MemHandleHTML);
    end;
  finally
    Clipboard.Close;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
{$IFDEF MSWINDOWS}
const
  nhdr = 'Version:0.9' + #13#10 +
                 'StartHTML:%.10d' + #13#10+
                 'EndHTML:%.10d' + #13#10+
                 'StartFragment:%.10d' + #13#10+
                 'EndFragment:%.10d' + #13#10;
  hdr = '<html><head></head><body><!--StartFragment-->';
  ftr1 = '<!--EndFragment-->';
  ftr2 = '</body></html>';
{$ENDIF}
var
  HTMLSource : String;
  {$IFDEF MSWINDOWS}
  iStartHTML: Integer;
  iStartFragment: Integer;
  iEndFragment: Integer;
  iEndHTML: Integer;
  {$ENDIF}
begin
  {$IFDEF MSWINDOWS}
  iStartHTML := 105;
  iStartFragment := iStartHTML + Length(nhdr);
  iEndFragment := iStartFragment + Length(AHTML) + Length(ftr1);
  iEndHTML := iEndFragment + Length(ftr2);
  HTMLSource := Format(nhdr, [iStartHTML, iEndHTML, iStartFragment,
    iEndFragment]) + hdr + AHTML + ftr1 + ftr2;
  {$ELSE}
  HTMLSource := AHTML;
  {$ENDIF}

  Clipboard.Open;
  try
    Clipboard.AddFormat(CF_FNCHTML, HTMLSource[1], Length(HTMLSource));
  finally
    Clipboard.Close;
  end;
{$ENDIF}
end;

class function TAdvClipBoard.GetHTML: String;
{$IFDEF VCLLIB}
var
  hclip: THandle;
  bufptr: Pointer;
  mstream: TStringStream;
begin
  Result := '';
  Clipboard.Open;
  try
    HClip := Clipboard.GetAsHandle(CF_FNCHTML);
    bufptr := GlobalLock(HClip);
    if bufptr <> nil then
    begin
      try
        mstream := TStringStream.Create('');
        try
          mstream.WriteBuffer(bufptr^, GlobalSize(HClip));
          Result := UTF8ToString(RawByteString(mstream.DataString));
        finally
          mstream.Free;
        end;
      finally
        GlobalUnlock(HClip);
      end;
    end;
  finally
    Clipboard.Close;
  end;
{$ENDIF}
{$IFDEF LCLLIB}
var
  fmt: TClipboardFormat;
  ms: TMemoryStream;
  sz: int64;
begin
  Result := '';
  fmt := Clipboard.FindFormatID(GetFormat(cfHTML));
  if fmt <> 0 then
  begin
    ms := TMemoryStream.Create;
    try
      if Clipboard.GetFormat(fmt, ms) then
      begin
        sz := ms.Size;
        if (sz > 0) and (PChar(ms.Memory)[sz-1]=#0) then
          Dec(sz);

        ms.Position := 0;
        SetLength(Result, sz);
        if sz > 0 then
          ms.Read(Result[1], sz);
      end;
    finally
      ms.Free;
    end;
  end;
{$ENDIF}
end;

{$ENDIF}

class function TAdvClipBoard.HasContent: Boolean;
begin
  Result := HasFormat(TAdvClipBoardFormat.cfText)
  or HasFormat(TAdvClipBoardFormat.cfRTF)
  or HasFormat(TAdvClipBoardFormat.cfBitmap)
  or HasFormat(TAdvClipBoardFormat.cfBitmapWin)
  or HasFormat(TAdvClipBoardFormat.cfRichTextStream)
  or HasFormat(TAdvClipBoardFormat.cfStream);
end;

{$IFDEF ANDROID}
procedure TAdvChartUtilsDialogSelectFileListener.onClick(dialog: JDialogInterface; which: Integer);
var
  f: JFile;
  s: JCharSequence;
begin
  s := FFileList.Items[which];
  if JCharSequenceToStr(s) = '..' then
    f := FCurrentPath.getParentFile
  else
    f := TJFile.JavaClass.init(s.toString);

  if f.isDirectory then
  begin
    if FFileMode = ufmSave then
      FSelectedFile := JStringToString(f.toString);

    LoadFileList(f, FFilter);
    FManuallyCancelled := True;
    FDialog.cancel;
    FDialog.dismiss;
    CallInUIThreadAndWaitFinishing(
    procedure
    begin
      ShowDialog(f);
    end
    );
  end
  else
  begin
    FSelectedFile := JStringToString(f.toString);
    FFilePicked := True;
  end;
end;

procedure TAdvChartUtilsDialogDismissListener.onDismiss(dialog: JDialogInterface);
begin
  FCancelled := not FManuallyCancelled;
  FManuallyCancelled := False;
end;

procedure TAdvChartUtilsDialogSelectDirectoryListener.onClick(dialog: JDialogInterface; which: Integer);
begin
  FFilePicked := True;
end;
{$ENDIF}

initialization
begin
  {$IFNDEF LCLLIB}
  {$IFDEF MSWINDOWS}
  CF_FNCRICHTEXTSTREAM := RegisterClipboardFormat('RichEditorText');
  CF_FNCSTREAM := RegisterClipboardFormat('TAdvClipBoard.StreamFormat');
  {$IFDEF FMXLIB}
  CF_FNCBITMAP := RegisterClipboardFormat('PNG');
  CF_FNCBITMAPWIN := CF_BITMAP;
  {$ENDIF}
  {$IFDEF VCLLIB}
  CF_FNCBITMAP := CF_BITMAP;
  {$ENDIF}
  CF_FNCRTF := RegisterClipboardFormat('Rich Text Format');
  CF_FNCHTML := RegisterClipboardFormat('HTML Format');
  {$ENDIF}
  {$ENDIF}

  {$IFDEF LCLLIB}
  CF_FNCRICHTEXTSTREAM := RegisterClipboardFormat('RichEditorText');
  CF_FNCSTREAM := RegisterClipboardFormat('TAdvClipBoard.StreamFormat');
  CF_FNCBITMAP := CF_PICTURE;
  CF_FNCRTF := RegisterClipboardFormat(TAdvClipBoard.GetFormat(TAdvClipBoardFormat.cfRTF));
  CF_FNCHTML := RegisterClipboardFormat(TAdvClipBoard.GetFormat(TAdvClipBoardFormat.cfHTML));
  {$ENDIF}
end;


end.


