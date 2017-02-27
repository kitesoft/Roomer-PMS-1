
{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{       ExpressCoreLibrary                                           }
{                                                                    }
{       Copyright (c) 1998-2014 Developer Express Inc.               }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSCORELIBRARY AND ALL            }
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

unit dxCoreReg;

{$I cxVer.inc}

interface

uses
  Classes, SysUtils, Menus, TypInfo, Windows, VCLEditors, Graphics, Forms, Controls,
  DesignIntf, DesignEditors, DesignConst, DesignMenus, dxCore;

const
  dxCoreLibraryProductPage = 'DevExpress';
  dxCompanyName = 'Developer Express Inc.';
  dxCompanyURL = 'www.devexpress.com';

type
  TDesignMenuItem = DesignMenus.IMenuItem;

  { TdxComponentEditor }

  TdxComponentEditor = class(TComponentEditor)
  private
    function GetBaseVerbCount: Integer;

    procedure AssignClick(Sender: TObject);
    procedure CheckObjectsForAssign(const AObjectName: string);
    procedure UpdateAssignableList;
  protected
    FAssignableObjects: TStringList;

    function IsAssignable: Boolean; virtual;
    function IsObjectAssignable(AObject: TObject): Boolean; virtual;
    procedure DoAssign(AObject: TObject); virtual;
    function GetAssignItemCaption: string; virtual;
    function GetAssignTypeClass: TClass; virtual;

    function GetProductVersion: string; virtual;
    function GetProductName: string; virtual;
    function InternalGetVerb(AIndex: Integer): string; virtual;
    function InternalGetVerbCount: Integer; virtual;
    procedure InternalExecuteVerb(AIndex: Integer); virtual;
  public
    constructor Create(AComponent: TComponent; ADesigner: IDesigner); override;
    destructor Destroy; override;
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
    procedure ExecuteVerb(Index: Integer); override;

    procedure PrepareItem(Index: Integer; const AItem: TDesignMenuItem); override;
  end;

  TdxDefaultBooleanPropertyEditor = class(TEnumProperty,
    ICustomPropertyDrawing
  {$IFDEF DELPHI11}
    ,
    ICustomPropertyDrawing80,
    ICustomPropertyMessage
  {$ENDIF}
    )
  protected
    function GetCheckBoxBounds(const ARect: TRect): TRect;
    function GetDefaultValue: Boolean; virtual; abstract;
    function GetDisplayText(Value: TdxDefaultBoolean): string;
    procedure PaintCheckbox(ACanvas: TCanvas; const ARect: TRect; ASelected: Boolean);
  public
    procedure PropDrawName(ACanvas: TCanvas; const ARect: TRect; ASelected: Boolean);
    procedure PropDrawValue(ACanvas: TCanvas; const ARect: TRect; ASelected: Boolean);
  {$IFDEF DELPHI11}
    function PropDrawNameRect(const ARect: TRect): TRect;
    function PropDrawValueRect(const ARect: TRect): TRect;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer;
      InNameRect: Boolean; const ItemRect: TRect; var Handled: Boolean);
    procedure MouseMove(Shift: TShiftState; X, Y: Integer; InNameRect: Boolean;
      const ItemRect: TRect; var Handled: Boolean);
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer;
      InNameRect: Boolean; const ItemRect: TRect; var Handled: Boolean);
    procedure HintShow(var HintInfo: THintInfo; InNameRect: Boolean;
      const ItemRect: TRect; var Handled: Boolean);
  {$ENDIF}
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
  end;

procedure Register;

implementation

{$R dxSplash.res}

uses
  ToolsApi, Themes, StdCtrls;


{ TdxComponentEditor }

constructor TdxComponentEditor.Create(AComponent: TComponent; ADesigner: IDesigner);
begin
  inherited;
  FAssignableObjects := TStringList.Create;
  FAssignableObjects.Sorted := True;
end;

destructor TdxComponentEditor.Destroy;
begin
  FreeAndNil(FAssignableObjects);
  inherited;
end;

function TdxComponentEditor.GetVerb(Index: Integer): string;
begin
  if Index < InternalGetVerbCount then
    Result := InternalGetVerb(Index)
  else
  begin
    Index := Index - InternalGetVerbCount;
    if FAssignableObjects.Count = 0 then
      Inc(Index);
    case Index of
      0: Result := GetAssignItemCaption;
      1: Result := '-';
      2: Result := GetProductName + ' ' + GetProductVersion;
      3: Result := dxCompanyName;
      4: Result := dxCompanyURL;
    end;
  end;
end;

function TdxComponentEditor.GetVerbCount: Integer;
begin
  if IsAssignable then
    UpdateAssignableList;

  Result := GetBaseVerbCount + InternalGetVerbCount;
end;

procedure TdxComponentEditor.ExecuteVerb(Index: Integer);
begin
  if Index < InternalGetVerbCount then
    InternalExecuteVerb(Index);
end;

procedure TdxComponentEditor.PrepareItem(Index: Integer; const AItem: TDesignMenuItem);
var
  I: Integer;
begin
  inherited;
  if (FAssignableObjects.Count > 0) and (Index = InternalGetVerbCount) then
  begin
    for I := 0 to FAssignableObjects.Count - 1 do
      AItem.AddItem(FAssignableObjects[I], 0, False, True, AssignClick);
  end;
end;

function TdxComponentEditor.InternalGetVerb(AIndex: Integer): string;
begin
  Result := '';
end;

function TdxComponentEditor.IsAssignable: Boolean;
begin
  Result := False;
end;

function TdxComponentEditor.IsObjectAssignable(AObject: TObject): Boolean;
begin
  Result := AObject <> Component;
end;

procedure TdxComponentEditor.DoAssign(AObject: TObject);
begin
end;

function TdxComponentEditor.GetAssignItemCaption: string;
begin
  Result := 'Assign From';
end;

function TdxComponentEditor.GetAssignTypeClass: TClass;
begin
  Result := nil;
end;

function TdxComponentEditor.GetProductVersion: string;
begin
  Result := dxGetBuildNumberAsString;
end;

function TdxComponentEditor.GetProductName: string;
begin
  Result := '';
end;

function TdxComponentEditor.InternalGetVerbCount: Integer;
begin
  Result := 0;
end;

procedure TdxComponentEditor.InternalExecuteVerb(AIndex: Integer);
begin
// do nothing
end;

function TdxComponentEditor.GetBaseVerbCount: Integer;
begin
  Result := 4;
  if FAssignableObjects.Count > 0 then
    Inc(Result);
end;

procedure TdxComponentEditor.AssignClick(Sender: TObject);
begin
  DoAssign(FAssignableObjects.Objects[((Sender as TMenuItem).MenuIndex)]);
end;

procedure TdxComponentEditor.CheckObjectsForAssign(const AObjectName: string);
var
  AObject: TObject;
begin
  AObject := Designer.GetComponent(AObjectName);
  if IsObjectAssignable(AObject) then
    FAssignableObjects.AddObject(AObjectName, AObject);
end;

procedure TdxComponentEditor.UpdateAssignableList;
begin
  FAssignableObjects.Clear;
  Designer.GetComponentNames(GetTypeData(GetAssignTypeClass.ClassInfo), CheckObjectsForAssign);
end;

{$IFDEF DELPHI9}
procedure RegisterSplashItem;
var
  ASplashBitmap: HBITMAP;
begin
  ASplashBitmap := LoadBitmap(HInstance, 'DXSPLASH');
  try
    SplashScreenServices.AddPluginBitmap(Format('DevExpress VCL %s', [dxGetBuildNumberAsString]),
      ASplashBitmap);
  finally
    DeleteObject(ASplashBitmap);
  end;
end;
{$ENDIF}

procedure DrawCheckbox(ACanvas: TCanvas; const ARect: TRect; AState: TCheckBoxState;
  AEnabled: Boolean = True);
const
  ThemeStyles : array[TCheckBoxState] of array[Boolean] of TThemedButton = (
    (tbCheckBoxUncheckedDisabled, tbCheckBoxUnCheckedNormal),
    (tbCheckBoxCheckedDisabled, tbCheckBoxCheckedNormal),
    (tbCheckBoxMixedDisabled, tbCheckBoxMixedNormal)
  );
  UnThemedStyles : array[TCheckBoxState] of array[Boolean] of Cardinal = (
    (DFCS_BUTTONCHECK or DFCS_INACTIVE, DFCS_BUTTONCHECK),
    (DFCS_CHECKED or DFCS_INACTIVE, DFCS_CHECKED),
    (DFCS_BUTTON3STATE or DFCS_INACTIVE, DFCS_CHECKED or DFCS_INACTIVE{DFCS_BUTTON3STATE})
  );
begin
{$IFDEF DELPHI16}
  if StyleServices.Enabled then
    StyleServices.DrawElement(ACanvas.Handle,
      StyleServices.GetElementDetails(ThemeStyles[AState][AEnabled]), ARect)
{$ELSE}
  if ThemeServices.ThemesEnabled then
    ThemeServices.DrawElement(ACanvas.Handle,
      ThemeServices.GetElementDetails(ThemeStyles[AState][AEnabled]), ARect)
{$ENDIF}
  else
    DrawFrameControl(ACanvas.Handle, ARect,
      DFC_BUTTON, UnThemedStyles[AState][AEnabled]);
end;

function TdxDefaultBooleanPropertyEditor.GetCheckBoxBounds(const ARect: TRect): TRect;
begin
{$IFDEF DELPHI11}
  Result := Rect(ARect.Right + 2, ARect.Top,
    ARect.Right + ARect.Bottom - ARect.Top + 2, ARect.Bottom);
{$ELSE}
  Result := Rect(ARect.Left + 2, ARect.Top + 1,
    ARect.Left + ARect.Bottom - ARect.Top, ARect.Bottom - 1);
{$ENDIF}
end;

function TdxDefaultBooleanPropertyEditor.GetDisplayText(Value: TdxDefaultBoolean): string;
begin
  case Value of
    bFalse:
      Result := BoolToStr(False, True);
    bTrue:
      Result := BoolToStr(True, True);
  else 
    Result := 'Default (' + BoolToStr(GetDefaultValue, True) + ')';
  end;
end;

function TdxDefaultBooleanPropertyEditor.GetValue: string;
begin
  Result := GetDisplayText(TdxDefaultBoolean(GetOrdValue));
end;

procedure TdxDefaultBooleanPropertyEditor.GetValues(Proc: TGetStrProc);
begin
  Proc(GetDisplayText(bDefault));
  Proc(GetDisplayText(bTrue));
  Proc(GetDisplayText(bFalse));
end;

procedure TdxDefaultBooleanPropertyEditor.SetValue(const Value: string);
begin
  if SameText(Value, GetDisplayText(bTrue)) then
    SetOrdValue(Ord(bTrue))
  else
    if SameText(Value, GetDisplayText(bFalse)) then
      SetOrdValue(Ord(bFalse))
    else
      SetOrdValue(Ord(bDefault));
end;

procedure TdxDefaultBooleanPropertyEditor.PropDrawName(ACanvas: TCanvas; const ARect: TRect;
  ASelected: Boolean);
begin
  DefaultPropertyDrawName(Self, ACanvas, ARect);
end;

procedure TdxDefaultBooleanPropertyEditor.PropDrawValue(ACanvas: TCanvas; const ARect: TRect;
  ASelected: Boolean);
{$IFNDEF DELPHI11}
var
  R: TRect;
{$ENDIF}
begin
{$IFDEF DELPHI11}
  PaintCheckbox(ACanvas, ARect, ASelected);
{$ELSE}
  ACanvas.FillRect(ARect);
  R := GetCheckBoxBounds(ARect);
  PaintCheckbox(ACanvas, R, ASelected);
  R := Rect(R.Right + 2, ARect.Top, ARect.Right, ARect.Bottom);
  DefaultPropertyDrawValue(Self, ACanvas, R);
{$ENDIF}
end;

{$IFDEF DELPHI11}
function TdxDefaultBooleanPropertyEditor.PropDrawNameRect(const ARect: TRect): TRect;
begin
  Result := ARect;
end;

function TdxDefaultBooleanPropertyEditor.PropDrawValueRect(const ARect: TRect): TRect;
begin
  Result := Rect(ARect.Left, ARect.Top, (ARect.Bottom - ARect.Top) + ARect.Left, ARect.Bottom);
end;

procedure TdxDefaultBooleanPropertyEditor.HintShow(var HintInfo: THintInfo;
  InNameRect: Boolean; const ItemRect: TRect; var Handled: Boolean);
begin
  Handled := False;
end;

procedure TdxDefaultBooleanPropertyEditor.MouseDown(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer; InNameRect: Boolean; const ItemRect: TRect;
  var Handled: Boolean);
begin
  Handled := {$IFNDEF DELPHI12}PtInRect(GetCheckBoxBounds(ItemRect), Point(X, Y)){$ELSE}False{$ENDIF};
end;

procedure TdxDefaultBooleanPropertyEditor.MouseMove(Shift: TShiftState; X, Y: Integer;
  InNameRect: Boolean; const ItemRect: TRect; var Handled: Boolean);
begin
  Handled := False;
end;

procedure TdxDefaultBooleanPropertyEditor.MouseUp(Button: TMouseButton; Shift: TShiftState; X,
  Y: Integer; InNameRect: Boolean; const ItemRect: TRect; var Handled: Boolean);
const
  NextValue: array[TdxDefaultBoolean] of TdxDefaultBoolean = (bDefault, bFalse, bTrue);
begin
  Handled := False;
  if paReadOnly in GetAttributes then Exit;
  if PtInRect(GetCheckBoxBounds(ItemRect), Point(x,y)) then
  begin
    SetOrdValue(Ord(NextValue[TdxDefaultBoolean(GetOrdValue)]));
    Handled := True;
  end;
end;
{$ENDIF}

procedure TdxDefaultBooleanPropertyEditor.PaintCheckbox(ACanvas: TCanvas;
  const ARect: TRect; ASelected: Boolean);
begin
  if not AllEqual then
    DrawCheckbox(ACanvas, ARect, cbGrayed)
  else
  begin
    case TdxDefaultBoolean(GetOrdValue) of
      bFalse:
        DrawCheckbox(ACanvas, ARect, cbUnchecked);
      bTrue:
        DrawCheckbox(ACanvas, ARect, cbChecked);
    else 
      DrawCheckbox(ACanvas, ARect, cbGrayed);
    end;
  end;
{$IFDEF DELPHI11}
  if ASelected then
    ExcludeClipRect(ACanvas.Handle, ARect.Left, ARect.Top, ARect.Right + 2, ARect.Bottom); 
{$ENDIF}
end;

procedure Register;
begin
{$IFDEF DELPHI9}
  ForceDemandLoadState(dlDisable);
  RegisterSplashItem;
{$ENDIF}
end;

initialization

finalization
end.

