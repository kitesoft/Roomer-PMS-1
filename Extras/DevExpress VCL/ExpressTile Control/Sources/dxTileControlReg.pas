{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{                   ExpressTileControl                               }
{                                                                    }
{       Copyright (c) 2011-2014 Developer Express Inc.               }
{       ALL RIGHTS RESERVED                                          }
{                                                                    }
{   The entire contents of this file is protected by U.S. and        }
{   International Copyright Laws. Unauthorized reproduction,         }
{   reverse-engineering, and distribution of all or any portion of   }
{   the code contained in this file is strictly prohibited and may   }
{   result in severe civil and criminal penalties and will be        }
{   prosecuted to the maximum extent possible under the law.         }
{                                                                    }
{   RESTRICTIONS                                                     }
{                                                                    }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES            }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE     }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS    }
{   LICENSED TO DISTRIBUTE THE EXPRESSTILECONTROL AND ALL            }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY. }
{                                                                    }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED       }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE         }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE        }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT   }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                       }
{                                                                    }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON        }
{   ADDITIONAL RESTRICTIONS.                                         }
{                                                                    }
{********************************************************************}

unit dxTileControlReg;

{$I cxVer.inc}

interface

uses
  Forms, DesignIntf, DesignEditors, DesignMenus, Controls,
  cxClasses, dxCoreReg, dxCoreClasses, cxDesignWindows;

const
  dxTileControlProductName  = 'ExpressTileControl Suite';

procedure Register;

implementation

uses
  SysUtils, Windows, Classes, Menus, Graphics, TypInfo, Math,
  dxCustomTileControl, dxTileControl, cxLibraryReg;

const
  dxTileControlEditorVerbs: array [0..3] of string = ('Add Regular Item', 'Add Large Item',
    'Add Extra-Large Item', 'Add Group');

type
  TdxTileControlItemDetailProperty = class(TComponentProperty)
  private
    FProc: TGetStrProc;
    procedure GetStrProc(const AName: string);
  public
    procedure GetValues(Proc: TGetStrProc); override;
  end;

  { TdxCustomTileControlEditor }

  TdxCustomTileControlEditor = class(TdxComponentEditor)
  protected
    function GetProductName: string; override;
  end;

  { TdxTileControlComponentEditor }

  TdxTileControlComponentEditor = class(TdxCustomTileControlEditor)
  private
    procedure CreateTileControlItem(AIsLarge: Boolean = False; ARowCount: Integer = 1);
    function GetTileControl: TdxCustomTileControl;
  protected
    function InternalGetVerb(AIndex: Integer): string; override;
    function InternalGetVerbCount: Integer; override;
    procedure InternalExecuteVerb(AIndex: Integer); override;
  public
    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlDesignHelper }

  TdxTileControlDesignHelper = class(TdxTileControlCustomDesignHelper, IUnknown, IcxDesignSelectionChanged)
  private
    FDesignHelper: TcxDesignHelper;
  protected
    function GetControl: TdxCustomTileControl; override;
    // IUnknown
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    function QueryInterface(const IID: TGUID; out Obj): HResult; virtual; stdcall;
    // IDesignNotification
    procedure DesignSelectionChanged(AList: TList);
  public
    constructor Create(AControl: TdxCustomTileControl); override;
    destructor Destroy; override;
    procedure CreateItemClickHandler(AItem: TdxTileControlItem); override;
    function IsObjectSelected(AObject: TPersistent): Boolean; override;
    procedure Select(AObject: TPersistent; AShift: TShiftState); override;
    procedure SetSelection(AList: TList); override;
    procedure UnselectObject(AObject: TPersistent); override;
  end;

{ TdxTileControlComponentEditor }

function TdxCustomTileControlEditor.GetProductName: string;
begin
  Result := dxTileControlProductName;
end;

{ TdxTileControlItemDetailProperty }

procedure TdxTileControlItemDetailProperty.GetValues(Proc: TGetStrProc);
begin
  FProc := Proc;
  inherited GetValues(GetStrProc);
end;

procedure TdxTileControlItemDetailProperty.GetStrProc(const AName: string);
var
  ATileControl, ACandidate: TComponent;
begin
  ACandidate := Designer.GetComponent(AName);
  ATileControl := TdxTileControlItemDetailOptions(GetComponent(0)).TileControl;
  if (ACandidate is TWinControl) and (ATileControl <> ACandidate) and
    ((TWinControl(ACandidate).Parent is TScrollingWinControl) or (ACandidate is TScrollingWinControl)) then
    FProc(AName);
end;

{ TdxTileControlComponentEditor }

function TdxTileControlComponentEditor.GetTileControl: TdxCustomTileControl;
begin
  Result := Component as TdxCustomTileControl;
end;

function TdxTileControlComponentEditor.InternalGetVerb(AIndex: Integer): string;
begin
  Result := dxTileControlEditorVerbs[AIndex];
end;

function TdxTileControlComponentEditor.InternalGetVerbCount: Integer;
begin
  Result := Length(dxTileControlEditorVerbs);
end;

procedure TdxTileControlComponentEditor.CreateTileControlItem(AIsLarge: Boolean = False;
  ARowCount: Integer = 1);
var
  AItem: TdxTileControlItem;
begin
  AItem := TileControl.CreateItem(AIsLarge);
  AItem.RowCount := ARowCount;
  Designer.SelectComponent(AItem);
end;

procedure TdxTileControlComponentEditor.InternalExecuteVerb(AIndex: Integer);
var
  AGroup: TdxTileControlGroup;
begin
  case AIndex of
    0, 1:
      CreateTileControlItem(AIndex = 1);
    2:
      CreateTileControlItem(True, 2);
    3:
    begin
      AGroup := TileControl.CreateGroup;
      Designer.SelectComponent(AGroup);
    end;
  end;
end;

{ TdxTileControlDesignHelper }

constructor TdxTileControlDesignHelper.Create(AControl: TdxCustomTileControl);
begin
  inherited Create(AControl);
  FDesignHelper := TcxDesignHelper.Create(AControl);
  FDesignHelper.AddSelectionChangedListener(Self);
end;

destructor TdxTileControlDesignHelper.Destroy;
begin
  FDesignHelper.RemoveSelectionChangedListener(Self);
  FDesignHelper.Free;
  inherited Destroy;
end;

procedure TdxTileControlDesignHelper.CreateItemClickHandler(AItem: TdxTileControlItem);
const
  MethodParams: array[0..0] of TMethodParam = (
    (Flags: [pfAddress]; Name: 'Sender'; TypeName: 'TdxTileControlItem')
  );
begin
  if AItem <> nil then
    ShowEventMethod(FDesignHelper.Designer, AItem, 'OnClick', AItem.Name + 'Click', MethodParams);
end;

function TdxTileControlDesignHelper.IsObjectSelected(AObject: TPersistent): Boolean;
begin
  Result := FDesignHelper.IsObjectSelected(AObject);
end;

procedure TdxTileControlDesignHelper.Select(AObject: TPersistent;
  AShift: TShiftState);
begin
  if AShift * [ssCtrl, ssAlt] <> [] then Exit;
  if AObject = nil then
    FDesignHelper.SelectObject(Control)
  else
    if ssShift in AShift then
      FDesignHelper.ChangeSelection(AObject)
    else
      FDesignHelper.SelectObject(AObject);
end;

procedure TdxTileControlDesignHelper.SetSelection(AList: TList);
begin
  FDesignHelper.SetSelection(AList);
end;

procedure TdxTileControlDesignHelper.UnselectObject(AObject: TPersistent);
begin
  FDesignHelper.UnselectObject(AObject);
end;

function TdxTileControlDesignHelper.GetControl: TdxCustomTileControl;
begin
  Result := FDesignHelper.Component as TdxCustomTileControl; 
end;

function TdxTileControlDesignHelper._AddRef: Integer; stdcall;
begin
  Result := -1;
end;

function TdxTileControlDesignHelper._Release: Integer; stdcall;
begin
  Result := -1;
end;

function TdxTileControlDesignHelper.QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
begin
  if GetInterface(IID, Obj) then
    Result := 0
  else
    Result := cxE_NOINTERFACE;
end;

procedure TdxTileControlDesignHelper.DesignSelectionChanged(AList: TList);
begin
  if (Control <> nil) and not Control.IsDestroying or Control.IsLoading then
    Control.Invalidate;
end;

procedure Register;
begin
  RegisterComponents(dxCoreLibraryProductPage, [TdxTileControl]);
  RegisterNoIcon([TdxTileControlGroup, TdxTileControlItemFrame, TdxTileControlItem, TdxTileControlActionBarItem]);
  RegisterClasses([TdxTileControl, TdxTileControlGroup, TdxTileControlItemFrame, TdxTileControlItem, TdxTileControlActionBarItem]);
  RegisterComponentEditor(TdxTileControl, TdxTileControlComponentEditor);
  RegisterPropertyEditor(TypeInfo(TWinControl), TdxTileControlItemDetailOptions, 'DetailControl', TdxTileControlItemDetailProperty);
  // RegisterPropertyEditor(TypeInfo(Integer), TdxTileControlItem, 'GroupIndex', nil);
  RegisterPropertyEditor(TypeInfo(Integer), TdxTileControlItem, 'IndexInGroup', nil);
  RegisterPropertyEditor(TypeInfo(TColor), TdxTileControlStyle, 'BorderColor', nil);
end;

initialization
  dxDesignHelperClass := TdxTileControlDesignHelper;

finalization
  dxDesignHelperClass := nil;

end.
