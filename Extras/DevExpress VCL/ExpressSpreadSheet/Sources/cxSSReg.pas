{*******************************************************************}
{                                                                   }
{       Developer Express Cross platform Visual Component Library   }
{       ExpressSpreadSheet registration components unit	            }
{                                                                   }
{       Copyright (c) 2001-2014 Developer Express Inc.              }
{       ALL RIGHTS RESERVED                                         }
{                                                                   }
{   The entire contents of this file is protected by U.S. and       }
{   International Copyright Laws. Unauthorized reproduction,        }
{   reverse-engineering, and distribution of all or any portion of  }
{   the code contained in this file is strictly prohibited and may  }
{   result in severe civil and criminal penalties and will be       }
{   prosecuted to the maximum extent possible under the law.        }
{                                                                   }
{   RESTRICTIONS                                                    }
{                                                                   }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES           }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE    }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS   }
{   LICENSED TO DISTRIBUTE THE EXPRESSSPREADSHEET AND ALL           }
{   ACCOMPANYING VCL AND CLX CONTROLS AS PART OF AN EXECUTABLE      }
{   PROGRAM ONLY.                                                   }
{                                                                   }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED      }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE        }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE       }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT  }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                      }
{                                                                   }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON       }
{   ADDITIONAL RESTRICTIONS.                                        }
{                                                                   }
{*******************************************************************}

unit cxSSReg;

{$I cxVer.inc}

interface

uses
  DesignIntf, DesignEditors,
  Classes, Dialogs,
  cxSSheet, cxSSStyles, cxSSTypes, cxSSDesigner,
  cxSSCtrls, cxSSColorBox, cxExcelConst, cxSSRes;

const
  cxSSProductName = 'ExpressSpreadSheet';

procedure Register;

implementation

uses
  dxCoreReg, cxLibraryReg;

type
 { TcxSpreadSheetEditor }
  TcxSpreadSheetEditor = class(TdxComponentEditor)
  protected
    function GetProductName: string; override;
  end;

  { TcxSSCellStyleProperty }
  TcxSSCellStyleProperty = class(TClassProperty)
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
  end;

  { TcxSSColorProperty }
  TcxSSColorProperty = class(TClassProperty)
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
  end;

  { TcxSSFontProperty }
  TcxSSFontProperty = class(TClassProperty)
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
  end;

{ TcxSpreadSheetEditor }

function TcxSpreadSheetEditor.GetProductName: string;
begin
  Result := cxSSProductName;
end;

{ TcxSSCellStyleProperty }
procedure TcxSSCellStyleProperty.Edit;
var
  AStyle: TcxSSCellStyle;
begin
  AStyle := TcxSSCellStyle(GetOrdValue);
  with TcxSSStyleDesigner.Create(nil) do
  try
    Execute(AStyle)
  finally
    Free;
  end;
  inherited;
end;

function TcxSSCellStyleProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paSubProperties, paDialog, paReadOnly];
end;

{ TcxSSColorProperty }
procedure TcxSSColorProperty.Edit;
var
  AColor: TcxSSColor;
begin
  AColor := TcxSSColor(GetOrdValue);
  if TcxSSColorPropertyEditor.Execute(AColor) then
    SetOrdValue(Integer(AColor));
  inherited;
end;

function TcxSSColorProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paDialog];
end;

procedure TcxSSFontProperty.Edit;
var
  AFont: TcxSSFont;
begin
  AFont := TcxSSFont(GetOrdValue);
  if AFont <> nil then
  begin
    with TFontDialog.Create(nil) do
    try
      if AFont.FontColor <= 55 then
        Font.Color := cxExcelStdColors[AFont.FontColor]
      else
        Font.Color := 0;
      Font.Name := AFont.Name;
      Font.Style := AFont.Style;
      Font.Charset := AFont.Charset;
      Font.Size := AFont.Size;
      if Execute then
        AFont.AssignInfo(Font.Name, Font.Size, Font.Style, Font.Charset,
          xlsSetColor(Font.Color, @cxExcelStdColors, 56));
    finally
      Free;
    end;
  end;
  inherited;
end;

function TcxSSFontProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paSubProperties, paDialog];
end;

procedure Register;
const
  VisualCategory: array[0..12] of string =
  ('BufferedPaint', 'ColHeaderHeight', 'DefaultColWidth', 'DefaultRowHeight',
   'DefaultStyle', 'HideSelection', 'PainterType', 'Precision', 'R1C1ReferenceStyle',
   'RowHeaderWidth', 'ShowFormulas', 'ShowGrid', 'ShowHeaders');
  SpreadSheetCategory: array[0..4] of string =
  ('GridColor', 'HeaderColor', 'HeaderFont', 'SelectionColor', 'BackgroundColor');

  AAction: string = sActionCategoryName;
  ASpreadSheet: string = scxSpreadSheet;
  AVisual: string = sVisualCategoryName;

begin
  RegisterComponents(dxCoreLibraryProductPage, [TcxSpreadSheetBook, TcxSpreadSheet]);

  RegisterClasses([TcxPaintPanel, TcxLabelBevel, TcxSSColorComboBox,
    TcxSSColorPanel, TcxSSStyleListBox]);
  RegisterNoIcon([TcxPaintPanel, TcxLabelBevel, TcxSSColorComboBox,
    TcxSSColorPanel, TcxSSStyleListBox]);
  RegisterPropertiesInCategory(AAction, TcxCustomSpreadSheetBook, ['AutoRecalc']);
  RegisterPropertiesInCategory(ASpreadSheet, TcxCustomSpreadSheetBook, SpreadSheetCategory);
  RegisterPropertiesInCategory(AVisual, TcxCustomSpreadSheetBook, VisualCategory);
  RegisterComponentEditor(TcxCustomSpreadSheetBook, TcxSpreadSheetEditor);
  RegisterPropertyEditor(TypeInfo(TcxSSCellStyle), TcxCustomSpreadSheetBook,
    'DefaultStyle', TcxSSCellStyleProperty);
  RegisterPropertyEditor(TypeInfo(TcxSSColor), nil, '', TcxSSColorProperty);
  RegisterPropertyEditor(TypeInfo(TcxSSFont), nil, '', TcxSSFontProperty);
end;

end.

