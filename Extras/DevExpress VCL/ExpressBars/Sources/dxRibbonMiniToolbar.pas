{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       ExpressBars components                                      }
{                                                                   }
{       Copyright (c) 1998-2014 Developer Express Inc.              }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSBARS AND ALL ACCOMPANYING VCL }
{   CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.                 }
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
unit dxRibbonMiniToolbar;

{$I cxVer.inc}

interface

uses
  Windows, Forms, Messages, Classes, SysUtils, Graphics,
  Controls, ExtCtrls, ImgList, IniFiles, Contnrs,
  dxCore, cxClasses, cxGraphics, cxControls, cxContainer, cxLookAndFeels,
  dxBar, dxBarSkinConsts, dxRibbon, cxGeometry, Math, Types;

type
  TdxRibbonMiniToolbarPainter = class;
  TdxRibbonMiniToolbarControl = class;

  { TdxRibbonCustomMiniToolbar }

  TdxRibbonCustomMiniToolbar = class(TdxRibbonCustomPopupComponent)
  private
    FBar: TdxBar;
    FPainter: TdxRibbonMiniToolbarPainter;
    FOnCloseUp: TNotifyEvent;

    function GetMiniToolbarControl: TdxRibbonMiniToolbarControl;

    procedure MiniToolbarDestroy(Sender: TObject);
    procedure MiniToolbarCloseUp(Sender: TObject);
  protected
    function CreateBarControl: TCustomdxBarControl; override;
    function GetControlClass: TCustomdxBarControlClass; override;
    function GetItemLinksClass: TdxBarItemLinksClass; override;

    property OnCloseUp: TNotifyEvent read FOnCloseUp write FOnCloseUp;
  public
    procedure Popup(AContextMenu: TdxBarCustomPopupMenu = nil); overload;
    procedure Popup(P: TPoint; AContextMenu: TdxBarCustomPopupMenu = nil); overload;
  end;

  { TdxRibbonMiniToolbar }

  TdxRibbonMiniToolbar = class(TdxRibbonCustomMiniToolbar)
  published
    property Images;
    property ItemLinks;
    property Ribbon;
  end;

  { TdxRibbonMiniToolbarControl }

  TdxRibbonMiniToolbarControl = class(TdxBarPopupControl)
  private
    FWasMouseOver: Boolean;
    FContextMenu: TdxBarCustomPopupMenu;

    function GetAlphaBlendValue: Integer;
    function GetContextPopup: TdxBarSubMenuControl;
    procedure DropContextMenu;
    procedure OnContextMenuClose(Sender: TObject; AReason: TdxBarCloseUpReason);
  protected
    // TCustomdxBarControl
    function AllowFade: Boolean; override;
    function AllowSeparators: Boolean; override;    
    function CanProcessMouseMessage: Boolean; override;
    function CanShowPopupMenuOnMouseClick(AMousePressed: Boolean): Boolean; override;
    procedure DoHideAll(AReason: TdxBarCloseUpReason); override;
    procedure DrawContentBackground; override;
    procedure FillBackground(ADC: HDC; const ARect: TRect; ABrush: HBRUSH; AColor: TColor;
      AIsClientArea: Boolean); override;
    function GetItemControlDefaultViewLevel(
      AItemControl: TdxBarItemControl): TdxBarItemViewLevel; override;
    function GetPaintType: TdxBarPaintType; override;
    function IsChildWindow(AWnd: HWND): Boolean; override;
    function NeedHideOnKeyPress: Boolean; override;
    procedure SetLayeredAttributes; override;

    // TdxBarControl
    procedure DoNCPaint(DC: HDC); override;

    // TdxBarPopupControl
    function GetPopupPosition(const ASize: TSize; const AOwnerRect: TRect; APopupDirection: TXDirection): TPoint; override;
    function GetPopupSize: TSize; override;

    function AlwaisTrackMouse: Boolean; override;
    procedure TrackMouse; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CloseUp; override;
  end;

  { TdxRibbonMiniToolbarPainter }

  TdxRibbonMiniToolbarPainter = class(TdxRibbonBarPainter)
  protected
    procedure DrawToolbarContentPart(ABarControl: TdxBarControl; ACanvas: TcxCanvas); override;
    procedure DrawToolbarNonContentPart(ABarControl: TdxBarControl; DC: HDC); override;
  public
    function GetToolbarContentOffsets(ABar: TdxBar;
      ADockingStyle: TdxBarDockingStyle; AHasSizeGrip: Boolean): TRect; override;
  end;

implementation

type
  TdxBarManagerAccess = class(TdxBarManager);
  TCustomdxBarControlAccess = class(TCustomdxBarControl);
  TdxCustomRibbonAccess = class(TdxCustomRibbon);
  TdxBarPainterAccess = class(TdxBarPainter);
  TdxBarCustomPopupMenuAccess = class(TdxBarCustomPopupMenu);
  TdxBarItemControlAccess = class(TdxBarItemControl);

{ TdxRibbonCustomMiniToolbar }

procedure TdxRibbonCustomMiniToolbar.Popup(AContextMenu: TdxBarCustomPopupMenu);
begin
  Popup(GetMouseCursorPos, AContextMenu);
end;

procedure TdxRibbonCustomMiniToolbar.Popup(P: TPoint; AContextMenu: TdxBarCustomPopupMenu);

  function CanShowBar: Boolean;
  begin
    Result := TdxBarManagerAccess(BarManager).IsOwnerVisible and IsFormActive(BarManager.ParentForm) and (Ribbon <> nil);
  end;

  procedure CorrectPosForContext(AContextMenu, AMiniToolbarControl: TCustomdxBarControl);

    function GetPositionAbove(const ABounds: TRect; AHeight: Integer): Integer;
    begin
      Result := ABounds.Top - AHeight - cxGetValueCurrentDPI(15);
    end;

    function GetPositionBelow(const ABounds: TRect): Integer;
    begin
      Result := ABounds.Bottom + cxGetValueCurrentDPI(15);
    end;

  var
    AWorkArea, AContextBounds: TRect;
    ANewPoint: TPoint;
    AMiniToolbarHeight: Integer;
  begin
    AMiniToolbarControl := GetMiniToolbarControl;
    AContextBounds := AContextMenu.BoundsRect;
    AMiniToolbarHeight := AMiniToolbarControl.Height;
    AWorkArea := GetWorkArea(P);

    ANewPoint.X := AContextBounds.Left;

    if P.Y > AContextBounds.Bottom then
    begin
      ANewPoint.Y := GetPositionBelow(AContextBounds);
      if ANewPoint.Y + AMiniToolbarControl.Height > AWorkArea.Bottom then
        ANewPoint.Y := GetPositionAbove(AContextBounds, AMiniToolbarHeight);
    end
    else
    begin
      ANewPoint.Y := GetPositionAbove(AContextBounds, AMiniToolbarHeight);
      if ANewPoint.Y < AWorkArea.Top then
        ANewPoint.Y := GetPositionBelow(AContextBounds);
    end;

    AMiniToolbarControl.Left := ANewPoint.X;
    AMiniToolbarControl.Top := ANewPoint.Y;
  end;

var
  AMiniToolbarControl: TdxRibbonMiniToolbarControl;
begin
  if CanShowBar then
  begin
    ItemLinks.CreateBarControl;
    AMiniToolbarControl := GetMiniToolbarControl;

  //  TCustomdxBarControlAccess(ItemLinks.BarControl.ParentBar).FMarkState := msPressed;
    BarDesignController.ShowQuickControl(AMiniToolbarControl, FPainter, cxRect(P, P));

    if AContextMenu <> nil then
    begin
      AMiniToolbarControl.FContextMenu := AContextMenu;
      TdxBarCustomPopupMenuAccess(AContextMenu).OnCloseUpEx := AMiniToolbarControl.OnContextMenuClose;

      TdxBarCustomPopupMenuAccess(AContextMenu).FUseOwnMessageLoop := False;
      TdxBarCustomPopupMenuAccess(AContextMenu).FMinWidth := ItemLinks.BarControl.Width;
//      TdxBarCustomPopupMenuAccess(FContextMenu).FOwnerControl := AMiniToolbarControl;
      AContextMenu.Popup(P.X, P.Y);
//      TdxBarCustomPopupMenuAccess(FContextMenu).FOwnerControl := nil;
      TdxBarCustomPopupMenuAccess(AContextMenu).FMinWidth := 0;
      TdxBarCustomPopupMenuAccess(AContextMenu).FUseOwnMessageLoop := True;

      CorrectPosForContext(AContextMenu.ItemLinks.BarControl as TdxBarSubMenuControl, AMiniToolbarControl);
    end;
    AMiniToolbarControl.TrackMouse;
  end;
end;

function TdxRibbonCustomMiniToolbar.CreateBarControl: TCustomdxBarControl;
begin
  if csDesigning in ComponentState then
    Result := inherited CreateBarControl
  else
  begin
    FBar := BarDesignController.AddInternalBar(BarManager);
    FBar.Visible := False;
    FBar.ItemLinks.CreateBarControl;

    Result := inherited CreateBarControl;
    (Result as TdxRibbonMiniToolbarControl).InitializeForPopup(FBar.Control, FBar);
    (Result as TdxRibbonMiniToolbarControl).OnCloseUp := MiniToolbarCloseUp;
    Result.OnDestroy := MiniToolbarDestroy;

    FPainter := TdxRibbonMiniToolbarPainter.Create(TdxNativeUInt(Ribbon));
  end;
end;

function TdxRibbonCustomMiniToolbar.GetControlClass: TCustomdxBarControlClass;
begin
  if csDesigning in ComponentState then
    Result := inherited GetControlClass
  else
    Result := TdxRibbonMiniToolbarControl;
end;

function TdxRibbonCustomMiniToolbar.GetItemLinksClass: TdxBarItemLinksClass;
begin
  if csDesigning in ComponentState then
    Result := inherited GetItemLinksClass
  else
    Result := TdxBarControlItemLinks;
end;

function TdxRibbonCustomMiniToolbar.GetMiniToolbarControl: TdxRibbonMiniToolbarControl;
begin
  Result := ItemLinks.Barcontrol as TdxRibbonMiniToolbarControl;
end;

procedure TdxRibbonCustomMiniToolbar.MiniToolbarDestroy(Sender: TObject);
begin
  FreeAndNil(FPainter);
  FreeAndNil(FBar);
end;

procedure TdxRibbonCustomMiniToolbar.MiniToolbarCloseUp(Sender: TObject);
begin
  dxCallNotify(OnCloseUp, Self);
end;

{ TdxRibbonMiniToolbarControl }

constructor TdxRibbonMiniToolbarControl.Create(AOwner: TComponent);
begin
  inherited;
  ControlStyle := ControlStyle + [csCaptureMouse];
end;

destructor TdxRibbonMiniToolbarControl.Destroy;
begin
  DropContextMenu;
  inherited Destroy;
end;

procedure TdxRibbonMiniToolbarControl.CloseUp;
begin
  dxCallNotify(OnCloseUp, Self);
//  inherited;
  Free;
end;

function TdxRibbonMiniToolbarControl.AlwaisTrackMouse: Boolean;
begin
  Result := True;
end;

procedure TdxRibbonMiniToolbarControl.TrackMouse;
var
  AAlpha: Integer;
begin
  AAlpha := GetAlphaBlendValue;
  if AAlpha = -1 then
    CloseUp
  else
    cxSetLayeredWindowAttributes(Handle, AAlpha);
end;

function TdxRibbonMiniToolbarControl.GetAlphaBlendValue: Integer;
var
  AMousePos: TPoint;
  AMouseDistance: TPoint;
  AMinMouseDistance: Integer;
  ABoundsRect: TRect;
  ALimitVisibility: Integer;
begin
  if (SelectedControl <> nil) or (FContextMenu <> nil) then
    Result := 255
  else
  begin
    AMousePos := GetMouseCursorPos;
    ABoundsRect := BoundsRect;
    AMouseDistance.X := Max(ABoundsRect.Left - AMousePos.X, AMousePos.X - ABoundsRect.Right);
    AMouseDistance.Y := Max(ABoundsRect.Top - AMousePos.Y, AMousePos.Y - ABoundsRect.Bottom);
    AMinMouseDistance := Max(AMouseDistance.X, AMouseDistance.Y);

    if AMinMouseDistance <= 0 then
    begin
      FWasMouseOver := True;
      Result := 255;
    end
    else
    begin
      if AMinMouseDistance > 176 then
        Result := -1
      else
      begin
        if FWasMouseOver then
          ALimitVisibility := cxGetValueCurrentDPI(84)
        else
          ALimitVisibility := cxGetValueCurrentDPI(13);
        if AMinMouseDistance > ALimitVisibility then
          Result := 0
        else
          Result := MulDiv(255, ALimitVisibility - AMinMouseDistance, ALimitVisibility);
      end;
    end;
  end;
end;

function TdxRibbonMiniToolbarControl.GetContextPopup: TdxBarSubMenuControl;
begin
  if FContextMenu <> nil then
    Result := FContextMenu.ItemLinks.BarControl as TdxBarSubMenuControl
  else
    Result := nil;
end;

procedure TdxRibbonMiniToolbarControl.DropContextMenu;
begin
  if FContextMenu <> nil then
  begin
    TdxBarCustomPopupMenuAccess(FContextMenu).OnCloseUpEx := nil;
    FContextMenu := nil;
  end;
end;

procedure TdxRibbonMiniToolbarControl.OnContextMenuClose(Sender: TObject; AReason: TdxBarCloseUpReason);
begin
  if AReason in [bcrEnter, bcrEscape] then
    CloseUp
  else
    DropContextMenu;
end;

function TdxRibbonMiniToolbarControl.GetPopupPosition(const ASize: TSize; const AOwnerRect: TRect; APopupDirection: TXDirection): TPoint;
begin
  Result := Point(AOwnerRect.Right, AOwnerRect.Bottom - ASize.cy - cxGetValueCurrentDPI(11));
end;

function TdxRibbonMiniToolbarControl.GetPopupSize: TSize;
begin
  if cxIsTouchModeEnabled then
    Result := GetSizeForHeight(dsNone, cxGetValueCurrentDPI(75), True)
  else
    Result := GetSizeForHeight(dsNone, cxGetValueCurrentDPI(50), True);

  with Painter.GetToolbarContentOffsets(Bar, DockingStyle, False) do
  begin
    Inc(Result.cx, Left + Right);
    Inc(Result.cy, Top + Bottom);
  end;
end;

function TdxRibbonMiniToolbarControl.GetPaintType: TdxBarPaintType;
begin
  //Result := ptMenu; exit;
  Result := inherited GetPaintType;
end;

function TdxRibbonMiniToolbarControl.IsChildWindow(AWnd: HWND): Boolean;
begin
  Result := inherited IsChildWindow(AWnd) or
    (GetContextPopup <> nil) and TCustomdxBarControlAccess(GetContextPopup).IsChildWindow(AWnd);
end;

procedure TdxRibbonMiniToolbarControl.DoHideAll(AReason: TdxBarCloseUpReason);
begin
  if AReason <> bcrEnter then
    CloseUp
  else
    if SelectedControl <> nil then
//      SetMouseSelectedItem(nil);
      TdxBarItemControlAccess(SelectedControl).ControlInactivate(True);
end;

procedure TdxRibbonMiniToolbarControl.DrawContentBackground;
begin
  inherited; Exit;

//Painter.DrawToolbarContentPart(Self, Canvas);
  Canvas.FillRect(ClientRect, clred);
end;

procedure TdxRibbonMiniToolbarControl.FillBackground(ADC: HDC; const ARect: TRect;
  ABrush: HBRUSH; AColor: TColor; AIsClientArea: Boolean);
begin
  Exit;
  {
  cxPaintCanvas.BeginPaint(ADC);
  try
    cxPaintCanvas.SetClipRegion(TcxRegion.Create(ARect), roIntersect);
    Painter.DrawToolbarContentPart(Self, cxPaintCanvas);
  finally
    cxPaintCanvas.EndPaint;
  end;
  }
end;

function TdxRibbonMiniToolbarControl.NeedHideOnKeyPress: Boolean;
begin
  Result := (FContextMenu = nil) and ((SelectedControl = nil) or not SelectedControl.HasWindow);
end;

procedure TdxRibbonMiniToolbarControl.SetLayeredAttributes;
begin
  cxSetLayeredWindowAttributes(Handle, 0);
end;

procedure TdxRibbonMiniToolbarControl.DoNCPaint(DC: HDC);
begin
  TdxBarPainterAccess(Painter).DrawToolbarNonContentPart(Self, DC);
end;

function TdxRibbonMiniToolbarControl.AllowFade: Boolean;
begin
  Result := False;
end;

function TdxRibbonMiniToolbarControl.AllowSeparators: Boolean;
begin
  Result := False;
end;

function TdxRibbonMiniToolbarControl.CanProcessMouseMessage: Boolean;
begin
  Result := True;
end;

function TdxRibbonMiniToolbarControl.CanShowPopupMenuOnMouseClick(AMousePressed: Boolean): Boolean;
begin
  Result := False;
end;

function TdxRibbonMiniToolbarControl.GetItemControlDefaultViewLevel(AItemControl: TdxBarItemControl): TdxBarItemViewLevel;
begin
  Result := AItemControl.ViewInfo.MinPossibleViewLevel;
end;

{ TdxRibbonMiniToolbarPainter }

procedure TdxRibbonMiniToolbarPainter.DrawToolbarContentPart(ABarControl: TdxBarControl; ACanvas: TcxCanvas);
begin
//  Skin.DrawBackground(ACanvas.Handle, ABarControl.ClientRect, DXBAR_MENUCONTENT);
  Skin.DrawBackground(ACanvas.Handle, ABarControl.ClientRect, DXBAR_MINITOOLBAR_BACKGROUND);
//  Skin.DrawBackground(ACanvas.Handle, ABarControl.ClientRect, DXBAR_DROPDOWNBORDER);
end;

procedure TdxRibbonMiniToolbarPainter.DrawToolbarNonContentPart(ABarControl: TdxBarControl; DC: HDC);
begin
  with ABarControl.ClientBounds do
    ExcludeClipRect(DC, Left, Top, Right, Bottom);
  Skin.DrawBackground(DC, TCustomdxBarControlAccess(ABarControl).NCRect, DXBAR_DROPDOWNBORDER);
end;

function TdxRibbonMiniToolbarPainter.GetToolbarContentOffsets(ABar: TdxBar;
  ADockingStyle: TdxBarDockingStyle; AHasSizeGrip: Boolean): TRect;
var
  AOffset: Integer;
begin
  AOffset := SubMenuControlBorderSize;
  Result := Rect(AOffset, AOffset, AOffset, AOffset);
end;

end.
