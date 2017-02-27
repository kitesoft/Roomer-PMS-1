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

unit RegScrpt;

{$I ASCRIPT.INC}

interface

uses
   Classes, atScript, atPascal,  atBasic, atScripter, ScriptCtrls
   {$IFNDEF BCB}
   , atWebScripter, atWebScriptPP
   {$ENDIF}
   , SysUtils
   , Forms, Dialogs, Controls
   , EditScript, FormScript, ScrMemo, atScriptDebug, atMemoInterface
   ;

procedure Register;

implementation
uses
  {$IFDEF DELPHI6_LVL}
  DesignEditors, Variants, DesignIntf
  {$ELSE}
  DsgnIntf
  {$ENDIF}
  ;

{ TatPascalScripterEditor }

type
  TatScripterEditor = class(TComponentEditor)
    procedure ExecuteVerb(Index: Integer); override;
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
  end;

  TatScriptProperty =class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TScrMemoLinesProperty =class(TClassProperty)
  public
    function GetAttributes:TPropertyAttributes; override;
    procedure Edit; override;
  end;

  TScrMemoEditor = class(TDefaultEditor)
                      protected
                        {$IFNDEF DELPHI6_LVL}
                        procedure EditProperty(PropertyEditor: TPropertyEditor;
                                               var Continue, FreeEditor: Boolean); override;
                        {$ELSE}
                        procedure EditProperty(const PropertyEditor: IProperty; var Continue: Boolean); override;
                        {$ENDIF}
                      public
                      end;

procedure Register;
const
  ScripterPalette = 'TMS Scripter';
begin
  RegisterComponents(ScripterPalette,[TatScripter, TatPascalScripter, TatBasicScripter]);
  
  {$IFNDEF BCB}
  RegisterComponents(ScripterPalette,[TatWebScripter, TatPageProducer]);
  {$ENDIF}

  RegisterComponents(ScripterPalette, [TatPascalFormScripter]);
  RegisterComponents(ScripterPalette, [TatBasicFormScripter]);
  RegisterComponents(ScripterPalette,[TSourceExplorer]);
  RegisterComponents(ScripterPalette,[TatScriptDebugger]);
  RegisterComponents(ScripterPalette,[TatMemoInterface]);
  RegisterComponentEditor(TatCustomScripter, TatScripterEditor);
  RegisterPropertyEditor(TypeInfo(TStrings), TatCustomScripter, 'SourceCode', TatScriptProperty);
  RegisterPropertyEditor(TypeInfo(TStrings),TScrMemo,'Lines',TScrMemoLinesProperty);
  RegisterComponentEditor(TScrMemo, TScrMemoEditor);
end;



procedure TatScripterEditor.ExecuteVerb(Index: Integer);
var
  MyScripter: TatCustomScripter;
  MyScriptDebugger: TatScriptDebugger;
begin
  MyScripter := Component as TatCustomScripter;
  if Index = 0 then
  begin
    MyScripter.Compile;
    MyScripter.Execute;
  end;

  if Index = 1 then
  begin
    MyScriptDebugger := TatScriptDebugger.Create(Application);
    MyScriptDebugger.Scripter := Component as TatCustomScripter;
    MyScriptDebugger.Execute;
    MyScriptDebugger.Free;
    Designer.Modified;
  end;

end;

function TatScripterEditor.GetVerb(Index: Integer): string;
begin
  case Index of
    0: Result := 'Execute script';
    1: Result := 'Debug script';
    else Result := '';
  end;

end;

function TatScripterEditor.GetVerbCount: Integer;
begin
  Result := 2;
end;

{ TatScriptProperty }

procedure TatScriptProperty.Edit;
var
  ScriptEditForm: TScriptEditForm;
begin
  ScriptEditForm := TScriptEditForm.Create(Application);
  try
    if GetComponent(0) is TatPascalScripter then
      ScriptEditForm.AdvMemo1.SyntaxStyles := ScriptEditForm.AdvPascalMemoStyler1;

    if GetComponent(0) is TatBasicScripter then
      ScriptEditForm.AdvMemo1.SyntaxStyles := ScriptEditForm.AdvBasicMemoStyler1;

    with GetComponent(0) as TatCustomScripter do
    begin
      ScriptEditForm.AdvMemo1.Lines.Assign(SourceCode);
    end;

    if ScriptEditForm.ShowModal = mrOk then
    begin
      with GetComponent(0) as TatCustomScripter do
        SourceCode.Assign(ScriptEditForm.AdvMemo1.Lines);

      Designer.Modified;
    end;
  finally
    ScriptEditForm.Free;
  end;
end;

function TatScriptProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

{ TScrMemoProperty }

procedure TScrMemoLinesProperty.Edit;
var
  ScriptEditForm: TScriptEditForm;
begin
  ScriptEditForm := TScriptEditForm.Create(Application);
  try
    with GetComponent(0) as TScrMemo do
    begin
      ScriptEditForm.AdvMemo1.SyntaxStyles := SyntaxStyles;
      ScriptEditForm.AdvMemo1.Lines.Assign(Lines);
      ScriptEditForm.AdvMemo1.RefreshMemo;

      if ScriptEditForm.ShowModal = mrOk then
      begin
        Lines.Assign(ScriptEditForm.AdvMemo1.Lines);
        RefreshMemo;
      end;

    end;
    Designer.Modified;
  finally
    ScriptEditForm.Free;
  end;

end;

{$IFDEF DELPHI6_LVL}
procedure TScrMemoEditor.EditProperty(const PropertyEditor: IProperty; var Continue: Boolean);
{$ELSE}
procedure TScrMemoEditor.EditProperty(PropertyEditor: TPropertyEditor;
  var Continue, FreeEditor: Boolean);
{$ENDIF}
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

function TScrMemoLinesProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

end.
