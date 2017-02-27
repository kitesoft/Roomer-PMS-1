{*************************************************************************}
{ TMS TAdvRichEditor                                                      }
{ for Delphi & C++Builder                                                 }
{                                                                         }
{ written by TMS Software                                                 }
{           copyright © 2015 - 2016                                       }
{           Email : info@tmssoftware.com                                  }
{           Web : http://www.tmssoftware.com                              }
{                                                                         }
{ The source code is given as is. The author is not responsible           }
{ for any possible damage done due to the use of this code.               }
{ The component can be freely used in any application. The complete       }
{ source code remains property of the author and may not be distributed,  }
{ published, given or sold in any form as such. No parts of the source    }
{ code can be included in any other component or application without      }
{ written authorization of the author.                                    }
{*************************************************************************}

unit AdvRichEditorMiniHTMLIO;

{$I TMSDEFS.INC}

interface

uses
  Windows, Classes, ImgList, AdvRichEditorBase, AdvRichEditor, AdvRichEditorIO
  {$IFDEF DELPHIXE2_LVL}
  , System.UITypes
  {$ENDIF}
  {$IFDEF TMSPACK}
  , GDIPPictureContainer
  {$ENDIF}
  ;

type
  TAdvRichEditorMiniHTMLIO = class(TAdvRichEditorIO)
  private
    FTempRichEdit: TAdvRichEditor;
    FInlineImages: boolean;
  public
    procedure Save(const FileName: string; ImgPath: string = ''); overload; virtual;
    procedure Save(AStream: TStream); overload; override;
    function AsString: string;
    procedure Load(HtmlValue: string; const Images: TCustomImageList; const Pictures: TGDIPPictureContainer = nil); overload;
    procedure Load(FileName: string); overload;
    procedure Load(AStream: TStream); overload;
    procedure Insert(HtmlValue: string);
  published
    property RichEditor;
    property InlineImages: boolean read FInlineImages write FInlineImages default false;
  end;


implementation

uses
  StrUtils, SysUtils, Graphics, Clipbrd;

type
  TAdvRichEditorEx = class(TAdvRichEditor);

{ TAdvRichEditorMiniHTMLIO }

procedure TAdvRichEditorMiniHTMLIO.Load(HtmlValue: string;
  const Images: TCustomImageList; const Pictures: TGDIPPictureContainer);
begin
  if (HtmlValue = '') then
    Exit;

  if not Assigned(RichEditor) then
    raise Exception.Create('No rich editor assigned');

  RichEditor.Clear;

  TAdvRichEditorEx(RichEditor).ParseHTML(HTMLValue, Images, Pictures);
end;

procedure TAdvRichEditorMiniHTMLIO.Save(const FileName: string;
  ImgPath: string);
var
  sl: TStringList;
begin
  if not Assigned(RichEditor) then
    raise Exception.Create('No rich editor assigned');

  sl := TStringList.Create;

  try
    if ImgPath = '' then
      ImgPath := ExtractFilePath(FileName);

    sl.Text := AsString;
    sl.SaveToFile(FileName);
  finally
    sl.Free;
  end;
end;

procedure TAdvRichEditorMiniHTMLIO.Load(FileName: string);
var
  sl: TStringList;
begin
  if not Assigned(RichEditor) then
    raise Exception.Create('No rich editor assigned');

  sl := TStringList.Create;
  try
    sl.LoadFromFile(FileName);
    Load(sl.Text,nil,nil);
  finally
    sl.Free;
  end;
end;

procedure TAdvRichEditorMiniHTMLIO.Load(AStream: TStream);
var
  ss: TStringStream;
begin
  ss := TStringStream.Create;

  try
    ss.LoadFromStream(AStream);
    Load(ss.DataString, nil, nil);
  finally
    ss.Free;
  end;
end;

procedure TAdvRichEditorMiniHTMLIO.Save(AStream: TStream);
var
  ss: TStringStream;
begin
  ss := TStringStream.Create;
  try
    ss.WriteString(AsString);
    ss.Position := 0;
    ss.SaveToStream(AStream);
  finally
    ss.Free;
  end;
end;

function CRLFStrip(s: string): string;
var
  i,ls: Integer;
  lc,nc,cc: char;

begin
  Result := '';
  ls := Length(s);

  s := ReplaceStr(s,#10,'');

  for i := 1 to ls do
  begin
    if i > 1 then
      lc := CharInStr(s,i - 1)
    else
      lc := #0;

    if i + 1 < ls then
      nc := CharInStr(s,i + 1)
    else
      nc := #0;

    cc := CharInStr(s,i);

    if not ( (cc = #13) or (cc = #9) or (cc = #0) ) then
      Result := Result + cc
    else
      if (cc = #13) then
      begin
        if (lc <> '>') or (nc <> '<') then
          Result := Result + ' ';
      end;
  end;
end;

function TAdvRichEditorMiniHTMLIO.AsString: string;
begin
  Result := '';

  if not Assigned(RichEditor) then
    Exit;

  if InlineImages then
    TAdvRichEditorBaseEx(RichEditor).HTMLImages := igInline;

  Result := CRLFStrip(RichEditor.ContentAsHTML);
end;

procedure TAdvRichEditorMiniHTMLIO.Insert(HtmlValue: string);
var
  FOrig: TAdvRichEditorBase;
begin
  FOrig := RichEditor;
  FTempRichEdit := TAdvRichEditor.Create(Self);

  RichEditor := FTempRichEdit;

  try
    Load(HTMLValue, nil, nil);
    FTempRichEdit.SelectAll;
    Clipboard.Open;

    try
      TAdvRichEditorEx(FTempRichEdit).CopyFormattedSelectionToClipboard;
      TAdvRichEditorEx(FOrig).PasteFormattedSelectionFromClipboard;
    finally
      Clipboard.Close;
    end;

  finally
    RichEditor := FOrig;
    FTempRichEdit.Free;
  end;

end;

end.
