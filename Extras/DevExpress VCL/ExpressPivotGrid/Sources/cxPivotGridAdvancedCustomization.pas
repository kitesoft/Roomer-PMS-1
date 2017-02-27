{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{                   ExpressPivotGrid                                 }
{                                                                    }
{       Copyright (c) 2005-2014 Developer Express Inc.               }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSPIVOTGRID AND ALL ACCOMPANYING }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.              }
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

unit cxPivotGridAdvancedCustomization;

{$I cxVer.inc}

interface

uses
  Windows, Messages, Graphics, Classes, Controls, ExtCtrls, ActnList, Menus, StdCtrls,
  ImgList, cxCustomPivotGrid, cxPivotGridCustomization, cxGraphics, cxControls, cxLookAndFeels,
  cxLookAndFeelPainters, cxContainer, cxEdit, cxGroupBox, cxButtons, cxCheckBox, cxLabel,
  cxSplitter, dxGDIPlusClasses;

type
  TcxPivotGridAdvancedCustomizationForm = class;

  { TcxPivotGridCustomizationFormLayoutChooser }

  TcxPivotGridCustomizationFormLayoutChooser = class
  private
    FFieldChooser: TcxPivotGridAdvancedCustomizationForm;
    FPopupMenu: TComponent;
  protected
    procedure CreateItem(Action: TAction); virtual; abstract;
    procedure CreateItems;
    function GetPopupMenuClass: TComponentClass; virtual; abstract;
    procedure InitializePopupMenu; virtual;
  public
    constructor Create(AFieldChooser: TcxPivotGridAdvancedCustomizationForm); virtual;
    destructor Destroy; override;

    procedure Popup(X, Y: Integer);

    property FieldChooser: TcxPivotGridAdvancedCustomizationForm read FFieldChooser;
    property PopupMenu: TComponent read FPopupMenu;
  end;
  TcxPivotGridCustomizationFormLayoutChooserClass = class of TcxPivotGridCustomizationFormLayoutChooser;

  { TcxPivotGridCustomizationFormStandardLayoutChooser }

  TcxPivotGridCustomizationFormStandardLayoutChooser = class(TcxPivotGridCustomizationFormLayoutChooser)
  private
    procedure DrawItem(Sender: TObject; ACanvas: TCanvas; ARect: TRect; State: TOwnerDrawState);
    function GetPopupMenu: TPopupMenu;
  protected
    procedure CreateItem(Action: TAction); override;
    function GetPopupMenuClass: TComponentClass; override;
    procedure InitializePopupMenu; override;
  public
    property PopupMenu: TPopupMenu read GetPopupMenu;
  end;

  { TcxPivotGridAdvancedCustomizationForm }

  TcxPivotGridCustomizationFormLayout = (cflBottomPanelOnly1by4, cflBottomPanelOnly2by2,
    cflStackedDefault, cflStackedSideBySide, cflTopPanelOnly);
  TcxPivotGridCustomizationFormLayouts = set of TcxPivotGridCustomizationFormLayout;

  TcxPivotGridAdvancedCustomizationForm = class(TcxPivotGridCustomCustomizationForm)
    gbTop: TcxGroupBox;
    gbMainBottom: TcxGroupBox;
    gbMainVisibleFields: TcxGroupBox;
    btnLayoutMode: TcxButton;
    btnUpdate: TcxButton;
    cbDeferLayoutUpdate: TcxCheckBox;
    lbMain: TLabel;
    lbTopMain: TLabel;
    gbFilterArea: TcxGroupBox;
    imgFilterArea: TImage;
    lbFilterArea: TLabel;
    gbRowArea: TcxGroupBox;
    imgRowArea: TImage;
    lbRowArea: TLabel;
    gbColumnArea: TcxGroupBox;
    imgColumnArea: TImage;
    lbColumnArea: TLabel;
    gbDataArea: TcxGroupBox;
    imgDataAdea: TImage;
    lbDataArea: TLabel;
    gbMainCenter: TcxGroupBox;
    gbMain: TcxGroupBox;
    gbFields: TcxGroupBox;
    splBottom: TcxSplitter;
    ilLayoutChooser: TcxImageList;
    alLayoutChooser: TActionList;
    acBottomPanelOnly1by4: TAction;
    acBottomPanelOnly2by2: TAction;
    acStackedDefault: TAction;
    acStackedSideBySide: TAction;
    acTopPanelOnly: TAction;
    splRight: TcxSplitter;
    lbEmpty: TLabel;
    procedure gbMainResize(Sender: TObject);
    procedure LayoutChooserExecute(Sender: TObject);
    procedure btnLayoutModeClick(Sender: TObject);
    procedure cbDeferLayoutUpdateClick(Sender: TObject);
    procedure btnUpdateClick(Sender: TObject);
    procedure gbFieldsResize(Sender: TObject);
  private
    FMainCaption: string;
    FAvailableFieldList: TcxFieldListListBox;
    FColumnAreaFieldList: TcxFieldListListBox;
    FDataAreaFieldList: TcxFieldListListBox;
    FFilterAreaFieldList: TcxFieldListListBox;
    FAllowedLayouts: TcxPivotGridCustomizationFormLayouts;
    FLayout: TcxPivotGridCustomizationFormLayout;
    FRowAreaFieldList: TcxFieldListListBox;
    FLayoutChooser: TcxPivotGridCustomizationFormLayoutChooser;

    FMainFieldsHeight: Integer;
    FMainFieldsWidth: Integer;

    procedure AlignChildren(AGroup: TcxGroupBox; AColumnCount, ARowCount: Integer);
    procedure CalculateTabOrders;
    function CreateFieldListBox(AParent: TWinControl; AFieldsType: TcxPivotGridCustomizationFormFieldListType): TcxFieldListListBox;
    procedure ListBoxDblClick(Sender: TObject);
    procedure SetAllowedLayouts(const AValue: TcxPivotGridCustomizationFormLayouts);
    procedure SetLayout(AValue: TcxPivotGridCustomizationFormLayout);
  protected
    function CanChangeFieldSortOrder: Boolean; override;
    function CanChangeFieldFilter: Boolean; override;
    procedure DoCreateControls; override;
    procedure DoUpdateSelection; override;
    function GetFieldListByType(AListType: TcxPivotGridCustomizationFormFieldListType): TObject; override;
    function GetImmediateUpdate: Boolean; override;
    function HasDeferredLayoutChanges: Boolean;
    procedure Init; override;
    procedure Localize; override;
    procedure LookAndFeelChanged; override;
    procedure SynchronizeFields; virtual;

    procedure BottomPanelOnly1by4FormCalculator;
    procedure BottomPanelOnly2by2FormCalculator;
    procedure SetIsLayoutChanged(AValue: Boolean); override;
    procedure StackedDefaultFormCalculator;
    procedure StackedSideBySideFormCalculator;
    procedure TopPanelOnlyFormCalculator;
    procedure UpdateButtonState; override;

    procedure InternalDisableAlign(AControl: TWinControl);
    procedure InternalEnableAlign(AControl: TWinControl);

    property LayoutChooser: TcxPivotGridCustomizationFormLayoutChooser read FLayoutChooser;
    procedure PopulateFieldLists; virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    procedure CalculateFormLayout; override;
    procedure RefreshList; override;

    property AllowedLayouts: TcxPivotGridCustomizationFormLayouts read FAllowedLayouts
      write SetAllowedLayouts;
    property AvailableFieldList: TcxFieldListListBox read FAvailableFieldList;
    property Layout: TcxPivotGridCustomizationFormLayout read FLayout
      write SetLayout;
    property ColumnAreaFieldList: TcxFieldListListBox read FColumnAreaFieldList;
    property DataAreaFieldList: TcxFieldListListBox read FDataAreaFieldList;
    property FilterAreaFieldList: TcxFieldListListBox read FFilterAreaFieldList;
    property RowAreaFieldList: TcxFieldListListBox read FRowAreaFieldList;
  end;

var
  cxPivotGridCustomizationFormLayoutChooserClass: TcxPivotGridCustomizationFormLayoutChooserClass;
  
implementation

{$R *.DFM}

uses
  Types, Contnrs, cxGeometry, Math, SysUtils, Forms, cxListBox, cxClasses, cxPivotGridStrs;

const
  cxControlsIndent = 6;
  cxSplitterSize = 8;
  cxDefaultFormAllowedLayouts = [cflBottomPanelOnly1by4, cflBottomPanelOnly2by2,
    cflStackedDefault, cflStackedSideBySide, cflTopPanelOnly];
  
{ TcxPivotGridCustomizationFormLayoutChooser }

constructor TcxPivotGridCustomizationFormLayoutChooser.Create(
  AFieldChooser: TcxPivotGridAdvancedCustomizationForm);
begin
  inherited Create;
  FFieldChooser := AFieldChooser;
  FPopupMenu := GetPopupMenuClass.Create(nil);
  InitializePopupMenu;
end;

destructor TcxPivotGridCustomizationFormLayoutChooser.Destroy;
begin
  FreeAndNil(FPopupMenu);
  inherited;
end;

procedure TcxPivotGridCustomizationFormLayoutChooser.Popup(X, Y: Integer);
begin
  ShowPopupMenu(nil, PopupMenu, X, Y);
end;

procedure TcxPivotGridCustomizationFormLayoutChooser.CreateItems;
begin
  CreateItem(FieldChooser.acStackedDefault);
  CreateItem(FieldChooser.acStackedSideBySide);
  CreateItem(FieldChooser.acTopPanelOnly);
  CreateItem(FieldChooser.acBottomPanelOnly1by4);
  CreateItem(FieldChooser.acBottomPanelOnly2by2);
end;

procedure TcxPivotGridCustomizationFormLayoutChooser.InitializePopupMenu;
begin
  CreateItems;
end;

{ TcxPivotGridCustomizationFormStandardLayoutChooser }

procedure TcxPivotGridCustomizationFormStandardLayoutChooser.CreateItem(Action: TAction);
var
  AItem: TMenuItem;
begin
  AItem := TMenuItem.Create(PopupMenu);
  AItem.Action := Action;
  AItem.OnAdvancedDrawItem := DrawItem;
  PopupMenu.Items.Add(AItem);
end;

function TcxPivotGridCustomizationFormStandardLayoutChooser.GetPopupMenuClass: TComponentClass;
begin
  Result := TPopupMenu;
end;

procedure TcxPivotGridCustomizationFormStandardLayoutChooser.InitializePopupMenu;
begin
  inherited;
  PopupMenu.Images := FieldChooser.ilLayoutChooser;
end;

procedure TcxPivotGridCustomizationFormStandardLayoutChooser.DrawItem(
  Sender: TObject; ACanvas: TCanvas; ARect: TRect; State: TOwnerDrawState);
begin
  cxAdvancedDrawPopupMenuItem(TMenuItem(Sender), ACanvas, ARect, State, PopupMenu.Images);
end;

function TcxPivotGridCustomizationFormStandardLayoutChooser.GetPopupMenu: TPopupMenu;
begin
  Result := TPopupMenu(inherited PopupMenu);
end;

{ TcxPivotGridAdvancedCustomizationForm }

constructor TcxPivotGridAdvancedCustomizationForm.Create(AOwner: TComponent);
begin
  inherited;
  DoubleBuffered := True; 
  FLayoutChooser := cxPivotGridCustomizationFormLayoutChooserClass.Create(Self);
  FLayout := cflStackedDefault;
  FAllowedLayouts := cxDefaultFormAllowedLayouts;
  lbEmpty.Width := cxControlsIndent;
end;

destructor TcxPivotGridAdvancedCustomizationForm.Destroy;
begin
  FreeAndNil(FLayoutChooser);
  inherited;
end;

procedure TcxPivotGridAdvancedCustomizationForm.CalculateFormLayout;
begin
  if Visible then
    InternalDisableAlign(Self);
  try
    case Layout of
      cflBottomPanelOnly1by4: BottomPanelOnly1by4FormCalculator;
      cflBottomPanelOnly2by2: BottomPanelOnly2by2FormCalculator;
      cflStackedDefault: StackedDefaultFormCalculator;
      cflStackedSideBySide: StackedSideBySideFormCalculator;
      cflTopPanelOnly: TopPanelOnlyFormCalculator;
    end;
    CalculateTabOrders;
    lbEmpty.Visible := Layout = cflStackedSideBySide;
    FMainFieldsHeight := -1;
    FMainFieldsWidth := -1;
    gbMain.BoundsRect := cxRectInflate(ClientRect, -cxControlsIndent, -cxControlsIndent);
  finally
    if Visible then
      InternalEnableAlign(Self);
  end;
end;

procedure TcxPivotGridAdvancedCustomizationForm.RefreshList;
begin
  inherited;
  PopulateFieldLists;
  UpdateSelection;
  IsLayoutChanged := False;
end;

function TcxPivotGridAdvancedCustomizationForm.CanChangeFieldSortOrder: Boolean;
begin
  Result := not HasDeferredLayoutChanges;
end;

function TcxPivotGridAdvancedCustomizationForm.CanChangeFieldFilter: Boolean;
begin
  Result := not HasDeferredLayoutChanges;
end;

procedure TcxPivotGridAdvancedCustomizationForm.DoCreateControls;
begin
  inherited;
  FAvailableFieldList := CreateFieldListBox(gbFields, fltAvailable);
  FAvailableFieldList.TabOrder := 0;
  FColumnAreaFieldList := CreateFieldListBox(gbColumnArea, fltColumn);
  FDataAreaFieldList := CreateFieldListBox(gbDataArea, fltData);
  FFilterAreaFieldList := CreateFieldListBox(gbFilterArea, fltFilter);
  FRowAreaFieldList := CreateFieldListBox(gbRowArea, fltRow);
end;

procedure TcxPivotGridAdvancedCustomizationForm.DoUpdateSelection;
var
  I: TcxPivotGridCustomizationFormFieldListType;
begin
  for I := Low(TcxPivotGridCustomizationFormFieldListType) to High(TcxPivotGridCustomizationFormFieldListType) do
    if GetFieldListByType(I) <> nil then
      (GetFieldListByType(I) as TcxFieldListListBox).UpdateSelection;
end;

function TcxPivotGridAdvancedCustomizationForm.GetFieldListByType(
  AListType: TcxPivotGridCustomizationFormFieldListType): TObject;
begin
  Result := AvailableFieldList;
  case AListType of
     fltColumn:
       Result := ColumnAreaFieldList;
     fltRow:
       Result := RowAreaFieldList;
     fltFilter:
       Result := FilterAreaFieldList;
     fltData:
       Result := DataAreaFieldList;
   end;
end;

function TcxPivotGridAdvancedCustomizationForm.GetImmediateUpdate: Boolean;
begin
  Result := not cbDeferLayoutUpdate.Checked;
end;

function TcxPivotGridAdvancedCustomizationForm.HasDeferredLayoutChanges: Boolean;
begin
  Result := cbDeferLayoutUpdate.Checked and IsLayoutChanged;
end;

procedure TcxPivotGridAdvancedCustomizationForm.Init;
begin
  inherited Init;
  gbTop.Constraints.MinHeight := btnLayoutMode.Height + cxControlsIndent;
  gbTop.Constraints.MaxHeight := gbTop.Constraints.MinHeight;
  gbMainBottom.Constraints.MinHeight := gbTop.Constraints.MinHeight;
  gbMainBottom.Constraints.MaxHeight := gbMainBottom.Constraints.MinHeight;
  gbMainBottom.Height := gbMainBottom.Constraints.MinHeight;
  cbDeferLayoutUpdate.Top := cxControlsIndent;
  btnUpdate.Top := cxControlsIndent;
  splBottom.Height := cxSplitterSize;
  splRight.Width := cxSplitterSize;
end;

procedure TcxPivotGridAdvancedCustomizationForm.Localize;
begin
  inherited;
  btnUpdate.Caption := cxGetResourceString(@scxUpdate);
  btnUpdate.Hint := StripHotKey(btnUpdate.Caption);

  cbDeferLayoutUpdate.Caption := cxGetResourceString(@scxDeferLayoutUpdate);
  cbDeferLayoutUpdate.Hint := StripHotKey(cbDeferLayoutUpdate.Caption);

  FMainCaption := cxGetResourceString(@scxAdvancedCustomizationFormMainCaption);
  lbTopMain.Caption := cxGetResourceString(@scxAdvancedCustomizationFormFieldsCaption);
  lbFilterArea.Caption := cxGetResourceString(@scxAdvancedCustomizationFormFilterAreaCaption);
  lbColumnArea.Caption := cxGetResourceString(@scxAdvancedCustomizationFormColumnAreaCaption);
  lbRowArea.Caption := cxGetResourceString(@scxAdvancedCustomizationFormRowAreaCaption);
  lbDataArea.Caption := cxGetResourceString(@scxAdvancedCustomizationFormDataAreaCaption);

  acBottomPanelOnly1by4.Caption := cxGetResourceString(@scxAdvancedCustomizationFormBottomPanelOnly1by4);
  acBottomPanelOnly2by2.Caption := cxGetResourceString(@scxAdvancedCustomizationFormBottomPanelOnly2by2);
  acStackedDefault.Caption := cxGetResourceString(@scxAdvancedCustomizationFormStackedDefault);
  acStackedSideBySide.Caption := cxGetResourceString(@scxAdvancedCustomizationFormStackedSideBySide);
  acTopPanelOnly.Caption := cxGetResourceString(@scxAdvancedCustomizationFormTopPanelOnly);
end;

procedure TcxPivotGridAdvancedCustomizationForm.LookAndFeelChanged;
begin
  inherited;
  Color := Painter.DefaultGroupColor;
end;

procedure TcxPivotGridAdvancedCustomizationForm.SynchronizeFields;
var
  I: TcxPivotGridCustomizationFormFieldListType;
begin
  PivotGrid.BeginUpdate;
  try
    for I := Low(TcxPivotGridCustomizationFormFieldListType) to High(TcxPivotGridCustomizationFormFieldListType) do
      if GetFieldListByType(I) <> nil then
        (GetFieldListByType(I) as TcxFieldListListBox).SynchronizeFields;
  finally
    PivotGrid.EndUpdate;
  end;
end;

procedure TcxPivotGridAdvancedCustomizationForm.BottomPanelOnly1by4FormCalculator;
begin
  gbTop.Constraints.MinHeight := btnLayoutMode.Height;
  gbTop.Height := gbTop.Constraints.MinHeight;

  gbMainVisibleFields.Constraints.MinHeight := gbFilterArea.Constraints.MinHeight +
    gbColumnArea.Constraints.MinHeight + gbRowArea.Constraints.MinHeight + gbDataArea.Constraints.MinHeight +
    gbMainBottom.Constraints.MinHeight;
  gbMainVisibleFields.Constraints.MinWidth := gbMainBottom.Constraints.MinWidth;
  Constraints.MinHeight := gbMainVisibleFields.Constraints.MinHeight + gbTop.Constraints.MinHeight +
    2 * cxControlsIndent + Height - ClientHeight;
  Constraints.MinWidth := gbTop.Constraints.MinWidth + 2 * cxControlsIndent +
    Width - ClientWidth;

  lbTopMain.Visible := False;
  gbMainResize(gbMainVisibleFields);
  gbMainVisibleFields.Visible := True;
  gbMainVisibleFields.Align := alClient;

  AvailableFieldList.Visible := False;
  splRight.Visible := False;
  splBottom.Visible := False;

  lbMain.Caption := lbTopMain.Caption;
end;

procedure TcxPivotGridAdvancedCustomizationForm.BottomPanelOnly2by2FormCalculator;
begin
  gbTop.Constraints.MinHeight := btnLayoutMode.Height;
  gbTop.Height := gbTop.Constraints.MinHeight;

  gbMainVisibleFields.Constraints.MinHeight := gbFilterArea.Constraints.MinHeight +
    gbColumnArea.Constraints.MinHeight + gbMainBottom.Constraints.MinHeight;
  gbMainVisibleFields.Constraints.MinWidth := gbMainBottom.Constraints.MinWidth;
  Constraints.MinHeight := gbMainVisibleFields.Constraints.MinHeight + gbTop.Constraints.MinHeight +
    2 * cxControlsIndent + Height - ClientHeight;
  Constraints.MinWidth := gbTop.Constraints.MinWidth + 2 * cxControlsIndent +
    Width - ClientWidth;

  lbTopMain.Visible := False;
  gbMainResize(gbMainVisibleFields);
  gbMainVisibleFields.Visible := True;
  gbMainVisibleFields.Align := alClient;

  AvailableFieldList.Visible := False;
  splRight.Visible := False;
  splBottom.Visible := False;

  lbMain.Caption := lbTopMain.Caption;
end;

procedure TcxPivotGridAdvancedCustomizationForm.SetIsLayoutChanged(AValue: Boolean);
begin
  inherited SetIsLayoutChanged(AValue);
  UpdateButtonState;
end;

procedure TcxPivotGridAdvancedCustomizationForm.StackedDefaultFormCalculator;
begin
  gbTop.Constraints.MinHeight := btnLayoutMode.Height + cxControlsIndent;
  gbTop.Height := gbTop.Constraints.MinHeight;

  gbMainVisibleFields.Constraints.MinHeight := gbFilterArea.Constraints.MinHeight +
    gbColumnArea.Constraints.MinHeight + gbMainBottom.Constraints.MinHeight + lbTopMain.Height;
  gbMainVisibleFields.Constraints.MinWidth := gbMainBottom.Constraints.MinWidth;
  Constraints.MinHeight := gbMainVisibleFields.Constraints.MinHeight + cxSplitterSize +
    AvailableFieldList.Constraints.MinHeight + gbTop.Constraints.MinHeight +
    2 * cxControlsIndent + Height - ClientHeight;
  Constraints.MinWidth := gbMainVisibleFields.Constraints.MinWidth + 2 * cxControlsIndent +
    Width - ClientWidth;

  lbTopMain.Visible := True;
  gbMainVisibleFields.Visible := True;
  gbMainVisibleFields.Align := alBottom;
  gbMainVisibleFields.Height := MulDiv(gbMainVisibleFields.Parent.ClientHeight, 3, 4);

  AvailableFieldList.Align := alClient;
  AvailableFieldList.Visible := True;

  splRight.Visible := False;
  splBottom.Visible := True;
  splBottom.Top := 0;

  lbMain.Caption := FMainCaption;
end;

procedure TcxPivotGridAdvancedCustomizationForm.StackedSideBySideFormCalculator;
begin
  gbTop.Constraints.MinHeight := btnLayoutMode.Height + cxControlsIndent;
  gbTop.Height := gbTop.Constraints.MinHeight;

  gbMainVisibleFields.Constraints.MinHeight := gbFilterArea.Constraints.MinHeight +
    gbColumnArea.Constraints.MinHeight + gbRowArea.Constraints.MinHeight + gbDataArea.Constraints.MinHeight +
    gbMainBottom.Constraints.MinHeight + lbTopMain.Height;
  gbMainVisibleFields.Constraints.MinWidth := gbMainBottom.Constraints.MinWidth + cxControlsIndent;

  Constraints.MinHeight := gbMainVisibleFields.Constraints.MinHeight + gbTop.Constraints.MinHeight +
    2 * cxControlsIndent + Height - ClientHeight;
  Constraints.MinWidth := gbMainVisibleFields.Constraints.MinWidth + 2 * cxControlsIndent +
    AvailableFieldList.Constraints.MinWidth + cxSplitterSize + Width - ClientWidth;

  lbTopMain.Visible := True;
  gbMainVisibleFields.Visible := True;
  gbMainVisibleFields.Align := alRight;
  gbMainVisibleFields.Width := gbMainVisibleFields.Parent.ClientWidth div 2;

  AvailableFieldList.Align := alClient;
  AvailableFieldList.Visible := True;

  splBottom.Visible := False;
  splRight.Visible := True;
  splRight.Left := 0;

  lbMain.Caption := FMainCaption;
end;

procedure TcxPivotGridAdvancedCustomizationForm.TopPanelOnlyFormCalculator;
begin
  gbTop.Constraints.MinHeight := btnLayoutMode.Height + cxControlsIndent;
  gbTop.Height := gbTop.Constraints.MinHeight;

  gbMainVisibleFields.Visible := False;
  splBottom.Visible := False;
  splRight.Visible := False;
  AvailableFieldList.Visible := True;
  AvailableFieldList.Align := alClient;

  Constraints.MinHeight := AvailableFieldList.Constraints.MinHeight + gbTop.Constraints.MinHeight +
    2 * cxControlsIndent + Height - ClientHeight;
  Constraints.MinWidth := gbTop.Constraints.MinWidth + 2 * cxControlsIndent +
    Width - ClientWidth;

   lbMain.Caption := FMainCaption;
end;

procedure TcxPivotGridAdvancedCustomizationForm.UpdateButtonState;
begin
  inherited;
  btnUpdate.Enabled := HasDeferredLayoutChanges;
  btnLayoutMode.Visible := AllowedLayouts <> [];
  acBottomPanelOnly1by4.Visible := cflBottomPanelOnly1by4 in AllowedLayouts;
  acBottomPanelOnly2by2.Visible := cflBottomPanelOnly2by2 in AllowedLayouts;
  acStackedDefault.Visible := cflStackedDefault in AllowedLayouts;
  acStackedSideBySide.Visible := cflStackedSideBySide in AllowedLayouts;
  acTopPanelOnly.Visible := cflTopPanelOnly in AllowedLayouts;
end;

procedure TcxPivotGridAdvancedCustomizationForm.InternalDisableAlign(
  AControl: TWinControl);
var
  I: Integer;
begin
  AControl.DisableAlign;
  for I := 0 to AControl.ControlCount - 1 do
    if AControl.Controls[I] is TWinControl then
      InternalDisableAlign(TWinControl(AControl.Controls[I]));
end;

procedure TcxPivotGridAdvancedCustomizationForm.InternalEnableAlign(
  AControl: TWinControl);
var
  I: Integer;
begin
  AControl.EnableAlign;
  for I := 0 to AControl.ControlCount - 1 do
    if AControl.Controls[I] is TWinControl then
      InternalEnableAlign(TWinControl(AControl.Controls[I]));
end;

procedure TcxPivotGridAdvancedCustomizationForm.PopulateFieldLists;
begin
  cxPopulateListBox(Self, AvailableFieldList, fltAvailable);
  cxPopulateListBox(Self, ColumnAreaFieldList, fltColumn);
  cxPopulateListBox(Self, FilterAreaFieldList, fltFilter);
  cxPopulateListBox(Self, DataAreaFieldList, fltData);
  cxPopulateListBox(Self, RowAreaFieldList, fltRow);
end;

procedure TcxPivotGridAdvancedCustomizationForm.AlignChildren(AGroup: TcxGroupBox;
  AColumnCount, ARowCount: Integer);
var
  I: Integer;
  R: TRect;
  X, Y: Integer;
  AList: TList;
begin
  R := AGroup.ClientRect;
  R.Right := (cxRectWidth(R) - cxControlsIndent * (AColumnCount - 1)) div AColumnCount;
  R.Bottom := (cxRectHeight(R) - IfThen(lbTopMain.Visible, lbTopMain.Height, 0) -
    gbMainBottom.Height) div ARowCount;
  X := cxRectWidth(R) + cxControlsIndent;
  Y := cxRectHeight(R);
  if lbTopMain.Visible then
    R := cxRectOffset(R, 0, lbTopMain.Height);
  AList := TList.Create;
  try
    AList.Add(gbFilterArea);
    AList.Add(gbRowArea);
    AList.Add(gbColumnArea);
    AList.Add(gbDataArea);
    for I := 0 to AList.Count - 1 do
      TWinControl(AList[I]).BoundsRect := cxRectOffset(R, X * (I div ARowCount), Y * (I mod ARowCount));
  finally
    AList.Free;
  end;
end;

procedure TcxPivotGridAdvancedCustomizationForm.CalculateTabOrders;
begin
  gbFilterArea.TabOrder := 0;
  if Layout in [cflBottomPanelOnly1by4, cflStackedSideBySide] then
  begin
    gbRowArea.TabOrder := 1;
    gbColumnArea.TabOrder := 2;
  end
  else
  begin
    gbColumnArea.TabOrder := 1;
    gbRowArea.TabOrder := 2;
  end;
  gbDataArea.TabOrder := 3;
end;

function TcxPivotGridAdvancedCustomizationForm.CreateFieldListBox(AParent: TWinControl;
  AFieldsType: TcxPivotGridCustomizationFormFieldListType): TcxFieldListListBox;
var
  R: TRect;
begin
  Result := TcxFieldListListBox.CreateEx(Self, AFieldsType);
  Result.Parent := AParent;
  if Result.Parent <> gbFields then
  begin
    R := AParent.ClientRect;
    R.Top := AParent.Controls[0].BoundsRect.Bottom + cxControlsIndent;
    Result.BoundsRect := R;
  end
  else
    Result.Visible := False;
  Result.Anchors := AnchorAlign[alClient];
  Result.LookAndFeel.MasterLookAndFeel := PivotGrid.LookAndFeel;
  Result.ItemHeight := Painter.HeaderHeight(cxTextHeight(Font));
  Result.OnDblClick := ListBoxDblClick;
  Result.Constraints.MinHeight := 30;
  Result.Constraints.MinWidth := 30;
end;

procedure TcxPivotGridAdvancedCustomizationForm.ListBoxDblClick(Sender: TObject);
var
  AListBox: TcxFieldListListBox;
begin
  if CanChangeFieldFilter then
  begin
    AListBox := TcxFieldListListBox(Sender);
    UpdateHitTest;
    if (AListBox.SelectedField <> nil) and not PivotGrid.HitTest.HitAtFilter then
      ChangeFieldSorting(AListBox.SelectedField);
  end;
end;

procedure TcxPivotGridAdvancedCustomizationForm.SetAllowedLayouts(const AValue: TcxPivotGridCustomizationFormLayouts);
begin
  if FAllowedLayouts <> AValue then
  begin
    FAllowedLayouts := AValue;
    UpdateButtonState;
  end;
end;

procedure TcxPivotGridAdvancedCustomizationForm.SetLayout(AValue: TcxPivotGridCustomizationFormLayout);
begin
  if FLayout <> AValue then
  begin
    FLayout := AValue;
    CalculateFormLayout;
  end;
end;

procedure TcxPivotGridAdvancedCustomizationForm.gbMainResize(Sender: TObject);
const
  ARowCountMap: array[TcxPivotGridCustomizationFormLayout] of Integer = (4, 2, 2, 4, 1);
  AColumnCountMap: array[TcxPivotGridCustomizationFormLayout] of Integer = (1, 2, 2, 1, 1);
var
  AGroup: TcxGroupBox;
begin
  AGroup := TcxGroupBox(Sender);
  AlignChildren(AGroup, AColumnCountMap[Layout], ARowCountMap[Layout]);
end;

procedure TcxPivotGridAdvancedCustomizationForm.LayoutChooserExecute(
  Sender: TObject);
var
  ATag: Integer;
begin
  ATag := TComponent(Sender).Tag;
  Layout := TcxPivotGridCustomizationFormLayout(ATag);
end;

procedure TcxPivotGridAdvancedCustomizationForm.btnLayoutModeClick(
  Sender: TObject);

  procedure CheckStates;
  var
    I: Integer;
  begin
    for I := 0 to alLayoutChooser.ActionCount - 1 do
      with TAction(alLayoutChooser.Actions[I]) do
        Checked := Tag = Ord(Layout);    
  end;
  
var
  P: TPoint;
begin
  CheckStates;
  P.X := 0;
  P.Y := btnLayoutMode.Height;
  P := btnLayoutMode.ClientToScreen(P);
  LayoutChooser.Popup(P.X, P.Y);
end;

procedure TcxPivotGridAdvancedCustomizationForm.cbDeferLayoutUpdateClick(
  Sender: TObject);
begin
  if IsLayoutChanged then
    RefreshList;
  UpdateButtonState;
end;

procedure TcxPivotGridAdvancedCustomizationForm.btnUpdateClick(
  Sender: TObject);
begin
  if not IsLayoutChanged then Exit;
  SynchronizeFields;
  IsLayoutChanged := False;
end;

procedure TcxPivotGridAdvancedCustomizationForm.gbFieldsResize(
  Sender: TObject);

  procedure ResizeVertically;
  var
    AAlign: TAlign;
  begin
    if (AvailableFieldList.Height > AvailableFieldList.Constraints.MinHeight) or
        ((FMainFieldsHeight > 0) and (gbMainVisibleFields.Height >= FMainFieldsHeight)) then
      AAlign := alClient
    else
      AAlign := alTop;
    if AAlign <> AvailableFieldList.Align then
    begin
      AvailableFieldList.Align := AAlign;
      if AvailableFieldList.Align = alTop then
      begin
        FMainFieldsHeight := gbMainVisibleFields.Height;
        gbMainVisibleFields.Align := alClient;
        splBottom.Align := alTop;
        splBottom.Control := AvailableFieldList;
      end
      else
      begin
        FMainFieldsHeight := -1;
        gbMainVisibleFields.Align := alBottom;
        splBottom.Align := alBottom;
        splBottom.Control := gbMainVisibleFields;
      end;
    end;
  end;

  procedure ResizeHorizontally;
  var
    AAlign: TAlign;
  begin
    if (AvailableFieldList.Width > AvailableFieldList.Constraints.MinWidth) or
        ((FMainFieldsWidth > 0) and (gbMainVisibleFields.Width >= FMainFieldsWidth)) then
      AAlign := alClient
    else
      AAlign := alLeft;
    if AAlign <> AvailableFieldList.Align then
    begin
      AvailableFieldList.Align := AAlign;
      if AvailableFieldList.Align = alLeft then
      begin
        FMainFieldsWidth := gbMainVisibleFields.Width;
        gbMainVisibleFields.Align := alClient;
      splRight.Align := alLeft;
      splRight.Control := AvailableFieldList;
      end
      else
      begin
        FMainFieldsWidth := -1;
        gbMainVisibleFields.Align := alRight;
        splRight.Align := alRight;
        splRight.Control := gbMainVisibleFields;
      end;
    end;
  end;

begin
  if not gbFields.HandleAllocated then
    Exit;
  if (AvailableFieldList <> nil) and AvailableFieldList.Visible then
  begin
    InternalDisableAlign(gbFields);
    try
      if Layout = cflStackedDefault then
        ResizeVertically
      else
        ResizeHorizontally;
    finally
      InternalEnableAlign(gbFields);
    end;
  end
  else
    gbMainVisibleFields.Align := alClient;
end;

initialization
  cxPivotGridCustomizationFormLayoutChooserClass := TcxPivotGridCustomizationFormStandardLayoutChooser;

end.
