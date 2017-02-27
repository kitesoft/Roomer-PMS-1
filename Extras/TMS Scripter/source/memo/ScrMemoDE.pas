{********************************************************************}
{ ScrMemo property editore                                           }
{ for Delphi & C++Builder                                            }
{                                                                    }
{ written by : TMS Software                                          }
{               copyright © 2002 - 2013                              }
{               Email : info@tmssoftware.com                         }
{               Web : http://www.tmssoftware.com                     }
{********************************************************************}
unit ScrMemoDE;

interface

{$I TMSDEFS.INC}

uses
  Classes, ScrMemo, Dialogs, ScrMemoEd, Forms, Controls, ScrMemoAC,
  DesignIntf, DesignEditors;
                                                        
type
  TScrMemoProperty = class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TScrMemoEditor = class(TDefaultEditor)
  protected
    procedure EditProperty(const PropertyEditor: IProperty; var Continue: Boolean); override;
  public
    function GetVerb(index: Integer):string; override;
    function GetVerbCount: Integer; override;
    procedure ExecuteVerb(Index: Integer); override;
  end;

  TMemoScrACorrectProperty = class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TScrCodeListEditor = class(TDefaultEditor)
  protected
    procedure EditProperty(const PropertyEditor: IProperty; var Continue: Boolean); override;
  public
  end;


implementation

uses
  SysUtils;

{ TIWScriptEventProperty }

procedure TScrMemoProperty.Edit;
var
  SE: TFrmMemoEdit;
begin
  SE := TFrmMemoEdit.Create(Application);

  try
    SE.AdvMemo1.Lines.Assign(TStrings(GetOrdValue));

    if GetComponent(0) is TScrMemo then
    begin
      SE.AdvMemo1.SyntaxStyles := (GetComponent(0) as TScrMemo).SyntaxStyles;
    end;

    if SE.ShowModal = mrOk then
    begin
      SetOrdValue(longint(SE.AdvMemo1.Lines));
      (GetComponent(0) as TScrMemo).TopLine := 0;
    end;

  finally
    SE.Free;
  end;
end;

function TScrMemoProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

{ TScrMemoEditor }
procedure TScrMemoEditor.EditProperty(const PropertyEditor: IProperty; var Continue: Boolean);
var
  PropName: string;
begin
  PropName := PropertyEditor.GetName;
  if (CompareText(PropName, 'LINES') = 0) then
  begin
    PropertyEditor.Edit;
    Continue := False;
  end;
end;

function TScrMemoEditor.GetVerb(Index: Integer):string;
begin
  if Index = 0 then
    Result := 'About';
end;

function TScrMemoEditor.GetVerbCount: Integer;
begin
  Result := 1;
end;

procedure TScrMemoEditor.ExecuteVerb(Index: Integer);
var
  compiler:string;

begin
  {$I COMPILERTEXT.INC}

  if Index = 0 then
    MessageDlg(Component.ClassName+' version '+(Component as TScrCustomMemo).GetVersionString+' for '+compiler+#13#10'© 2001-2015 by TMS software',
               mtinformation,[mbok],0);
end;

{ TMemoScrACorrectProperty }

procedure TMemoScrACorrectProperty.Edit;
var
  Dlg: TACMemo;
  i: Integer;
  Memo: TScrMemo;
begin
  Dlg := TACMemo.Create(Application);

  Memo := TScrMemo(GetComponent(0));

  dlg.ckDoAutoCorrect.Checked := Memo.AutoCorrect.Active;
  if Memo.AutoCorrect.OldValue.Count > 0 then
    Dlg.StringGrid1.RowCount := 1 + Memo.AutoCorrect.OldValue.Count;

  for i := 1 to Memo.AutoCorrect.OldValue.Count do
  begin
    Dlg.StringGrid1.Cells[0,i] := Memo.AutoCorrect.OldValue.Strings[i - 1];
    Dlg.StringGrid1.Cells[1,i] := Memo.AutoCorrect.NewValue.Strings[i - 1];
  end;

  if Dlg.ShowModal = mrOk then
  begin
    Memo.AutoCorrect.Active := dlg.ckDoAutoCorrect.Checked;
    Memo.AutoCorrect.OldValue.Clear;
    Memo.AutoCorrect.NewValue.Clear;

    for i := 1 to Dlg.StringGrid1.RowCount - 1 do
    begin
      Memo.AutoCorrect.OldValue.Add(Dlg.StringGrid1.Cells[0,i]);
      Memo.AutoCorrect.NewValue.Add(Dlg.StringGrid1.Cells[1,i]);
    end;

    Designer.Modified;
  end;

  Dlg.Free;

end;

function TMemoScrACorrectProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;


{ TScrCodeListEditor }
procedure TScrCodeListEditor.EditProperty(const PropertyEditor: IProperty; var Continue: Boolean);
var
  PropName: string;
begin
  PropName := PropertyEditor.GetName;
  if (CompareText(PropName, 'CODEBLOCKS') = 0) then
  begin
    PropertyEditor.Edit;
    Continue := False;
  end;
end;



end.




