{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       ExpressDocking                                              }
{                                                                   }
{       Copyright (c) 2002-2014 Developer Express Inc.              }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSDOCKING AND ALL ACCOMPANYING  }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.             }
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

unit dxDockReg;

{$I cxVer.inc}

interface

uses
  Windows, Classes, Forms, SysUtils, Graphics, Controls, ImgList,
  DesignIntf, ComponentDesigner, DesignEditors, VCLEditors,
  dxCoreReg, cxLibraryReg, cxPropEditors, cxControls, dxCore;

const
  dxDockProductName = 'ExpressDocking Library';
  dxDockProductPage = 'ExpressDocking';  

type
  TdxDockingComponentEditor = class(TdxComponentEditor)
  protected
    function GetProductName: string; override;
  end;

  TdxDockingImageIndexProperty = class(TImageIndexProperty)
  public
    function GetImages: TCustomImageList; override;
  end;

procedure Register;

implementation

uses
  dxDockControl, dxDockPanel, TypInfo, cxDesignWindows, dxMessages;

type
  TdxCustomDockControlAccess = class(TdxCustomDockControl);

{$IFDEF DELPHI10}
{$IFNDEF DELPHI14}

  { Guidelines }

  { TdxControlGuidelines }

  TdxControlGuidelines = class(TControlGuidelines)
  protected
    function CalcHorzPos(APos: Integer): Integer; override;
    function CalcVertPos(APos: Integer): Integer; override;
  end;

  { TdxWinControlGuidelines }

  TdxWinControlGuidelines = class(TWinControlGuidelines)
  protected
    function CalcHorzPos(APos: Integer): Integer; override;
    function CalcVertPos(APos: Integer): Integer; override;
  end;

  { TdxDockPanelGuidelines }

  TdxDockControlGuidelines = class(TWinControlGuidelines)
  protected
    function GetCount: Integer; override;
  public
    procedure Initialize(AComponent: TComponent; AContainer: TComponent); override;
  end;
{$ENDIF}
{$ENDIF}

  { TdxDockDesignWindow }

  TdxDockDesignWindow = class(TcxGlobalDesignWindow)
  public
    procedure SelectionsChanged(const ASelection: TDesignerSelectionList); override;
  end;

  { TdxDockingSelectionEditor }

  TdxDockingSelectionEditor = class(TSelectionEditor)
  public
    procedure RequiresUnits(Proc: TGetStrProc); override;
  end;

var
  FdxDockDesignWindow: TdxDockDesignWindow;

{ TdxDockingSelectionEditor }

procedure TdxDockingSelectionEditor.RequiresUnits(Proc: TGetStrProc);
begin
  inherited RequiresUnits(Proc);
  Proc('cxPC');
end;

{ TdxDockingComponentEditor }

function TdxDockingComponentEditor.GetProductName: string;
begin
  Result := dxDockProductName;
end;

{ TdxDockingImageIndexProperty  }

function TdxDockingImageIndexProperty.GetImages: TCustomImageList;
begin
  Result := TdxCustomDockSite(GetComponent(0)).Images;
end;

{ TdxDockDesignWindow }

procedure TdxDockDesignWindow.SelectionsChanged(const ASelection: TDesignerSelectionList);
var
  I: Integer;
begin
  for I := 0 to ASelection.Count - 1 do
  begin
    if (ASelection[I] is TdxCustomDockControl) and (TdxCustomDockControl(ASelection[I]).ParentDockControl = nil) then
      (ASelection[I] as TdxCustomDockControl).Repaint;
  end;
end;

{$IFDEF DELPHI10}
{$IFNDEF DELPHI14}
{ Guidelines }

function TdxControlGuidelines.CalcHorzPos(APos: Integer): Integer;
var
  LParent: TWinControl;
begin
  if Component <> Container then
    LParent := TControl(Component).Parent
  else
    LParent := TWinControl(Component);
  Result := TControl(Component).Left + APos;
  while (LParent <> Container) and (LParent <> nil) do
  begin
    Inc(Result, LParent.Left);
    LParent := LParent.Parent;
  end;
end;

function TdxControlGuidelines.CalcVertPos(APos: Integer): Integer;
var
  LParent: TWinControl;
begin
  if Component <> Container then
    LParent := TControl(Component).Parent
  else
    LParent := TWinControl(Component);
  Result := TControl(Component).Top + APos;
  while (LParent <> Container) and (LParent <> nil) do
  begin
    Inc(Result, LParent.Top);
    LParent := LParent.Parent;
  end;
end;

function TdxWinControlGuidelines.CalcHorzPos(APos: Integer): Integer;
var
  LParent: TWinControl;
begin
  if Component <> Container then
    LParent := TControl(Component).Parent
  else
    LParent := TWinControl(Component);
  Result := TControl(Component).Left + APos;
  while (LParent <> Container) and (LParent <> nil) do
  begin
    Inc(Result, LParent.Left);
    LParent := LParent.Parent;
  end;
end;

function TdxWinControlGuidelines.CalcVertPos(APos: Integer): Integer;
var
  LParent: TWinControl;
begin
  if Component <> Container then
    LParent := TControl(Component).Parent
  else
    LParent := TWinControl(Component);
  Result := TControl(Component).Top + APos;
  while (LParent <> Container) and (LParent <> nil) do
  begin
    Inc(Result, LParent.Top);
    LParent := LParent.Parent;
  end;
end;

{ TdxDockControlGuidelines }

// the same in dxDockControl
procedure dxIllegalSetParentField(AHackedControl: TWinControl; ANewParent: TObject);
var
  PParent: PdxNativeUInt;
begin
  PParent := @AHackedControl.Parent;
  PParent^ := TdxNativeUInt(ANewParent);
end;

procedure TdxDockControlGuidelines.Initialize(AComponent: TComponent; AContainer: TComponent);
var
  AFloatForm: TdxFloatForm;
begin
  inherited;
  AFloatForm := (Component as TdxCustomDockControl).FloatForm;
  if AFloatForm <> nil then
  begin
    dxIllegalSetParentField(AFloatForm, Container);
    PostMessage(AFloatForm.Handle, DXM_DOCK_PURGEPARENT, 0, 0);
  end;
end;

function TdxDockControlGuidelines.GetCount: Integer;
begin
  if (Component as TdxCustomDockControl).FloatForm <> nil then
    Result := 0
  else
    Result := inherited GetCount;
end;
{$ENDIF}
{$ENDIF}

procedure Register;
begin
  RegisterComponents(dxDockProductPage, [TdxDockingManager, TdxDockPanel, TdxDockSite]);
  RegisterPropertyEditor(TypeInfo(Integer), TdxCustomDockControl, 'ImageIndex',
    TdxDockingImageIndexProperty);
  RegisterComponentEditor(TdxCustomDockControl, TdxDockingComponentEditor);
  RegisterSelectionEditor(TdxCustomDockControl, TdxDockingSelectionEditor);
  RegisterComponentEditor(TdxDockingManager, TdxDockingComponentEditor);
{$IFDEF DELPHI10}
{$IFNDEF DELPHI14}
//  RegisterComponentGuidelines(TButton, TdxWinControlGuidelines);
  RegisterComponentGuidelines(TdxDockPanel, TdxDockControlGuidelines);
  RegisterComponentGuidelines(TdxFloatDockSite, TdxDockControlGuidelines);
  RegisterComponentGuidelines(TdxTabContainerDockSite, TdxDockControlGuidelines);
{$ENDIF}
{$ENDIF}
end;

procedure RegisterDockControl(ASender: TObject);
begin
  if dxDockingController.DockControlCount = 1 then
    FdxDockDesignWindow := TdxDockDesignWindow.Create(nil);

  TdxCustomDockControlAccess(ASender).FDesignHelper := TcxDesignHelper.Create(TComponent(ASender));
end;

procedure UnregisterDockControl(ASender: TObject);
begin
  if (FdxDockDesignWindow <> nil) and ((dxDockingController = nil) or (dxDockingController.DockControlCount = 1)) then
    cxReleaseForm(FdxDockDesignWindow);

  TdxCustomDockControlAccess(ASender).FDesignHelper := nil;
end;

initialization
  FOnRegisterDockControl := RegisterDockControl;
  FOnUnregisterDockControl := UnregisterDockControl;

end.
