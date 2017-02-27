{***************************************************************************}
{ This source code was generated automatically by                           }
{ Pas file import tool for Scripter Studio (Pro)                            }
{                                                                           }
{ Scripter Studio and Pas file import tool for Scripter Studio              }
{ written by TMS Software                                                   }
{            copyright © 1997 - 2010                                        }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{***************************************************************************}
//unit ap_ExtCtrls;

interface

uses
  Messages,
  Windows,
  SysUtils,
  Classes,
  Contnrs,
  Types,
  Controls,
  Forms,
  Menus,
  Graphics,
  StdCtrls,
  GraphUtil,
  ImgList,
  ShellAPI,
  ExtCtrls,
  System.Variants,
  ap_Types,
  atScript;

{$WARNINGS OFF}

type
  TatExtCtrlsLibrary = class(TatScripterLibrary)
    procedure __TShapeCreate(AMachine: TatVirtualMachine);
    procedure __TShapeDestroy(AMachine: TatVirtualMachine);
    procedure __TShapeStyleChanged(AMachine: TatVirtualMachine);
    procedure __TPaintBoxCreate(AMachine: TatVirtualMachine);
    procedure __TImageCreate(AMachine: TatVirtualMachine);
    procedure __TImageDestroy(AMachine: TatVirtualMachine);
    procedure __GetTImageCanvas(AMachine: TatVirtualMachine);
    procedure __TBevelCreate(AMachine: TatVirtualMachine);
    procedure __TTimerCreate(AMachine: TatVirtualMachine);
    procedure __TTimerDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomPanelCreate(AMachine: TatVirtualMachine);
    procedure __TCustomPanelGetControlsAlignment(AMachine: TatVirtualMachine);
    procedure __TCustomFlowPanelCreate(AMachine: TatVirtualMachine);
    procedure __TCustomFlowPanelDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomFlowPanelGetControlIndex(AMachine: TatVirtualMachine);
    procedure __TCustomFlowPanelSetControlIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomFlowPanelAutoWrap(AMachine: TatVirtualMachine);
    procedure __SetTCustomFlowPanelAutoWrap(AMachine: TatVirtualMachine);
    procedure __GetTCustomFlowPanelFlowStyle(AMachine: TatVirtualMachine);
    procedure __SetTCustomFlowPanelFlowStyle(AMachine: TatVirtualMachine);
    procedure __TCellItemCreate(AMachine: TatVirtualMachine);
    procedure __TCellCollectionOwner(AMachine: TatVirtualMachine);
    procedure __GetTCellCollectionItems(AMachine: TatVirtualMachine);
    procedure __SetTCellCollectionItems(AMachine: TatVirtualMachine);
    procedure __TRowCollectionCreate(AMachine: TatVirtualMachine);
    procedure __TRowCollectionAdd(AMachine: TatVirtualMachine);
    procedure __TColumnCollectionCreate(AMachine: TatVirtualMachine);
    procedure __TColumnCollectionAdd(AMachine: TatVirtualMachine);
    procedure __TControlItemCreate(AMachine: TatVirtualMachine);
    procedure __TControlItemDestroy(AMachine: TatVirtualMachine);
    procedure __TControlItemSetLocation(AMachine: TatVirtualMachine);
    procedure __TControlCollectionCreate(AMachine: TatVirtualMachine);
    procedure __TControlCollectionAdd(AMachine: TatVirtualMachine);
    procedure __TControlCollectionAddControl(AMachine: TatVirtualMachine);
    procedure __TControlCollectionRemoveControl(AMachine: TatVirtualMachine);
    procedure __TControlCollectionIndexOf(AMachine: TatVirtualMachine);
    procedure __TControlCollectionOwner(AMachine: TatVirtualMachine);
    procedure __GetTControlCollectionControls(AMachine: TatVirtualMachine);
    procedure __SetTControlCollectionControls(AMachine: TatVirtualMachine);
    procedure __GetTControlCollectionControlItems(AMachine: TatVirtualMachine);
    procedure __GetTControlCollectionItems(AMachine: TatVirtualMachine);
    procedure __SetTControlCollectionItems(AMachine: TatVirtualMachine);
    procedure __TCustomGridPanelCreate(AMachine: TatVirtualMachine);
    procedure __TCustomGridPanelDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomGridPanelIsColumnEmpty(AMachine: TatVirtualMachine);
    procedure __TCustomGridPanelIsRowEmpty(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelColumnSpanIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelCellCount(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelCellSize(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelCellRect(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelColumnCollection(AMachine: TatVirtualMachine);
    procedure __SetTCustomGridPanelColumnCollection(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelControlCollection(AMachine: TatVirtualMachine);
    procedure __SetTCustomGridPanelControlCollection(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelExpandStyle(AMachine: TatVirtualMachine);
    procedure __SetTCustomGridPanelExpandStyle(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelRowCollection(AMachine: TatVirtualMachine);
    procedure __SetTCustomGridPanelRowCollection(AMachine: TatVirtualMachine);
    procedure __GetTCustomGridPanelRowSpanIndex(AMachine: TatVirtualMachine);
    procedure __TPageCreate(AMachine: TatVirtualMachine);
    procedure __TNotebookCreate(AMachine: TatVirtualMachine);
    procedure __TNotebookDestroy(AMachine: TatVirtualMachine);
    procedure __THeaderCreate(AMachine: TatVirtualMachine);
    procedure __THeaderDestroy(AMachine: TatVirtualMachine);
    procedure __GetTHeaderSectionWidth(AMachine: TatVirtualMachine);
    procedure __SetTHeaderSectionWidth(AMachine: TatVirtualMachine);
    procedure __TCustomRadioGroupCreate(AMachine: TatVirtualMachine);
    procedure __TCustomRadioGroupDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomRadioGroupFlipChildren(AMachine: TatVirtualMachine);
    procedure __GetTCustomRadioGroupButtons(AMachine: TatVirtualMachine);
    procedure __GetTCustomRadioGroupWordWrap(AMachine: TatVirtualMachine);
    procedure __SetTCustomRadioGroupWordWrap(AMachine: TatVirtualMachine);
    procedure __TSplitterCreate(AMachine: TatVirtualMachine);
    procedure __TSplitterDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomControlBarCreate(AMachine: TatVirtualMachine);
    procedure __TCustomControlBarDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomControlBarFlipChildren(AMachine: TatVirtualMachine);
    procedure __TCustomControlBarStickControls(AMachine: TatVirtualMachine);
    procedure __GetTCustomControlBarPicture(AMachine: TatVirtualMachine);
    procedure __SetTCustomControlBarPicture(AMachine: TatVirtualMachine);
    procedure __TBoundLabelCreate(AMachine: TatVirtualMachine);
    procedure __TCustomLabeledEditCreate(AMachine: TatVirtualMachine);
    procedure __TCustomLabeledEditSetBounds(AMachine: TatVirtualMachine);
    procedure __TCustomLabeledEditSetupInternalLabel(AMachine: TatVirtualMachine);
    procedure __GetTCustomLabeledEditEditLabel(AMachine: TatVirtualMachine);
    procedure __GetTCustomLabeledEditLabelPosition(AMachine: TatVirtualMachine);
    procedure __SetTCustomLabeledEditLabelPosition(AMachine: TatVirtualMachine);
    procedure __GetTCustomLabeledEditLabelSpacing(AMachine: TatVirtualMachine);
    procedure __SetTCustomLabeledEditLabelSpacing(AMachine: TatVirtualMachine);
    procedure __TEditButtonCreate(AMachine: TatVirtualMachine);
    procedure __TEditButtonDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomButtonedEditCreate(AMachine: TatVirtualMachine);
    procedure __TCustomButtonedEditDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomButtonedEditDefaultHandler(AMachine: TatVirtualMachine);
    procedure __GetTCustomButtonedEditImages(AMachine: TatVirtualMachine);
    procedure __SetTCustomButtonedEditImages(AMachine: TatVirtualMachine);
    procedure __GetTCustomButtonedEditLeftButton(AMachine: TatVirtualMachine);
    procedure __SetTCustomButtonedEditLeftButton(AMachine: TatVirtualMachine);
    procedure __GetTCustomButtonedEditRightButton(AMachine: TatVirtualMachine);
    procedure __SetTCustomButtonedEditRightButton(AMachine: TatVirtualMachine);
    procedure __TCustomColorBoxCreate(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorBoxStyle(AMachine: TatVirtualMachine);
    procedure __SetTCustomColorBoxStyle(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorBoxColors(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorBoxColorNames(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorBoxSelected(AMachine: TatVirtualMachine);
    procedure __SetTCustomColorBoxSelected(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorBoxDefaultColorColor(AMachine: TatVirtualMachine);
    procedure __SetTCustomColorBoxDefaultColorColor(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorBoxNoneColorColor(AMachine: TatVirtualMachine);
    procedure __SetTCustomColorBoxNoneColorColor(AMachine: TatVirtualMachine);
    procedure __TCustomColorListBoxCreate(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorListBoxStyle(AMachine: TatVirtualMachine);
    procedure __SetTCustomColorListBoxStyle(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorListBoxColors(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorListBoxColorNames(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorListBoxSelected(AMachine: TatVirtualMachine);
    procedure __SetTCustomColorListBoxSelected(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorListBoxDefaultColorColor(AMachine: TatVirtualMachine);
    procedure __SetTCustomColorListBoxDefaultColorColor(AMachine: TatVirtualMachine);
    procedure __GetTCustomColorListBoxNoneColorColor(AMachine: TatVirtualMachine);
    procedure __SetTCustomColorListBoxNoneColorColor(AMachine: TatVirtualMachine);
    procedure __TCustomTrayIconCreate(AMachine: TatVirtualMachine);
    procedure __TCustomTrayIconDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomTrayIconRefresh(AMachine: TatVirtualMachine);
    procedure __TCustomTrayIconSetDefaultIcon(AMachine: TatVirtualMachine);
    procedure __TCustomTrayIconShowBalloonHint(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconAnimate(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconAnimate(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconAnimateInterval(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconAnimateInterval(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconHint(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconHint(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconBalloonHint(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconBalloonHint(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconBalloonTitle(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconBalloonTitle(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconBalloonTimeout(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconBalloonTimeout(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconBalloonFlags(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconBalloonFlags(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconIcon(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconIcon(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconIcons(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconIcons(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconIconIndex(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconIconIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconPopupMenu(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconPopupMenu(AMachine: TatVirtualMachine);
    procedure __GetTCustomTrayIconVisible(AMachine: TatVirtualMachine);
    procedure __SetTCustomTrayIconVisible(AMachine: TatVirtualMachine);
    procedure __TCategoryPanelSurfaceCreate(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelCreate(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelCollapse(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelExpand(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelGetTabControlList(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelGetTabOrderList(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelSetBounds(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelCollapsed(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelCollapsed(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelCollapsedHotImageIndex(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelCollapsedHotImageIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelCollapsedImageIndex(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelCollapsedImageIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelCollapsedPressedImageIndex(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelCollapsedPressedImageIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelExpandedHotImageIndex(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelExpandedHotImageIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelExpandedImageIndex(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelExpandedImageIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelExpandedPressedImageIndex(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelExpandedPressedImageIndex(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelHeaderState(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelPanelGroup(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelPanelGroup(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelGroupCreate(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelGroupDestroy(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelGroupCollapseAll(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelGroupCreatePanel(AMachine: TatVirtualMachine);
    procedure __TCustomCategoryPanelGroupExpandAll(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupChevronAlignment(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupChevronAlignment(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupChevronColor(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupChevronColor(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupChevronHotColor(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupChevronHotColor(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupGradientBaseColor(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupGradientBaseColor(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupGradientColor(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupGradientColor(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupGradientDirection(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupGradientDirection(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupHeaderAlignment(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupHeaderAlignment(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupHeaderFont(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupHeaderFont(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupHeaderHeight(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupHeaderHeight(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupHeaderImage(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupHeaderImage(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupHeaderStyle(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupHeaderStyle(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupImages(AMachine: TatVirtualMachine);
    procedure __SetTCustomCategoryPanelGroupImages(AMachine: TatVirtualMachine);
    procedure __GetTCustomCategoryPanelGroupPanels(AMachine: TatVirtualMachine);
    procedure __TCustomLinkLabelCreate(AMachine: TatVirtualMachine);
    procedure __GetTCustomLinkLabelAlignment(AMachine: TatVirtualMachine);
    procedure __SetTCustomLinkLabelAlignment(AMachine: TatVirtualMachine);
    procedure __GetTCustomLinkLabelAutoSize(AMachine: TatVirtualMachine);
    procedure __SetTCustomLinkLabelAutoSize(AMachine: TatVirtualMachine);
    procedure __GetTCustomLinkLabelUseVisualStyle(AMachine: TatVirtualMachine);
    procedure __SetTCustomLinkLabelUseVisualStyle(AMachine: TatVirtualMachine);
    procedure __Frame3D(AMachine: TatVirtualMachine);
    procedure __NotebookHandlesNeeded(AMachine: TatVirtualMachine);
    procedure Init; override;
    class function LibraryName: string; override;
  end;

  TShapeClass = class of TShape;
  TPaintBoxClass = class of TPaintBox;
  TImageClass = class of TImage;
  TBevelClass = class of TBevel;
  TTimerClass = class of TTimer;
  TCustomPanelClass = class of TCustomPanel;
  TPanelClass = class of TPanel;
  TCustomFlowPanelClass = class of TCustomFlowPanel;
  TFlowPanelClass = class of TFlowPanel;
  EGridPanelExceptionClass = class of EGridPanelException;
  TCellItemClass = class of TCellItem;
  TRowItemClass = class of TRowItem;
  TColumnItemClass = class of TColumnItem;
  TCellCollectionClass = class of TCellCollection;
  TRowCollectionClass = class of TRowCollection;
  TColumnCollectionClass = class of TColumnCollection;
  TControlItemClass = class of TControlItem;
  TControlCollectionClass = class of TControlCollection;
  TCustomGridPanelClass = class of TCustomGridPanel;
  TGridPanelClass = class of TGridPanel;
  TPageClass = class of TPage;
  TNotebookClass = class of TNotebook;
  THeaderClass = class of THeader;
  TCustomRadioGroupClass = class of TCustomRadioGroup;
  TRadioGroupClass = class of TRadioGroup;
  TSplitterClass = class of TSplitter;
  TCustomControlBarClass = class of TCustomControlBar;
  TControlBarClass = class of TControlBar;
  TBoundLabelClass = class of TBoundLabel;
  TCustomLabeledEditClass = class of TCustomLabeledEdit;
  TLabeledEditClass = class of TLabeledEdit;
  TEditButtonClass = class of TEditButton;
  TCustomButtonedEditClass = class of TCustomButtonedEdit;
  TButtonedEditClass = class of TButtonedEdit;
  TCustomColorBoxClass = class of TCustomColorBox;
  TColorBoxClass = class of TColorBox;
  TCustomColorListBoxClass = class of TCustomColorListBox;
  TColorListBoxClass = class of TColorListBox;
  TCustomTrayIconClass = class of TCustomTrayIcon;
  TTrayIconClass = class of TTrayIcon;
  TCategoryPanelSurfaceClass = class of TCategoryPanelSurface;
  TCustomCategoryPanelClass = class of TCustomCategoryPanel;
  TCategoryPanelClass = class of TCategoryPanel;
  TCustomCategoryPanelGroupClass = class of TCustomCategoryPanelGroup;
  TCategoryPanelGroupClass = class of TCategoryPanelGroup;
  TCustomLinkLabelClass = class of TCustomLinkLabel;
  TLinkLabelClass = class of TLinkLabel;

  TatExtCtrlsDispatcher = class(TatEventDispatcher)
  private
    procedure __TSectionEvent( Sender: TObject;  ASection: Integer;  AWidth: Integer);
    procedure __TSplitterCanResizeEvent( Sender: TObject; var NewSize: Integer; var Accept: Boolean);
    procedure __TCanResizeEvent( Sender: TObject; var NewSize: Integer; var Accept: Boolean);
    procedure __TBandDragEvent( Sender: TObject;  Control: TControl; var Drag: Boolean);
    procedure __TBeginBandMoveEvent( Sender: TObject;  Control: TControl; var AllowMove: Boolean);
    procedure __TEndBandMoveEvent( Sender: TObject;  Control: TControl);
    procedure __TGetColorsEvent( Sender: TCustomColorBox;  Items: TStrings);
    procedure __TLBGetColorsEvent( Sender: TCustomColorListBox;  Items: TStrings);
    procedure __TSysLinkEvent( Sender: TObject; const Link: string;  LinkType: TSysLinkType);
  end;


implementation



procedure TatExtCtrlsLibrary.__TShapeCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TShapeClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TShapeDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TShape(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TShapeStyleChanged(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TShape(CurrentObject).StyleChanged(TObject(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatExtCtrlsLibrary.__TPaintBoxCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TPaintBoxClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TImageCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TImageClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TImageDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TImage(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__GetTImageCanvas(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TImage(CurrentObject).Canvas));
  end;
end;

procedure TatExtCtrlsLibrary.__TBevelCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TBevelClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TTimerCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TTimerClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TTimerDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TTimer(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomPanelCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomPanelClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomPanelGetControlsAlignment(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(TCustomPanel(CurrentObject).GetControlsAlignment);
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomFlowPanelCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomFlowPanelClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomFlowPanelDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomFlowPanel(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomFlowPanelGetControlIndex(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(TCustomFlowPanel(CurrentObject).GetControlIndex(TControl(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomFlowPanelSetControlIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomFlowPanel(CurrentObject).SetControlIndex(TControl(VarToObject(GetInputArg(0))),VarToInteger(GetInputArg(1)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomFlowPanelAutoWrap(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomFlowPanel(CurrentObject).AutoWrap);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomFlowPanelAutoWrap(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomFlowPanel(CurrentObject).AutoWrap:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomFlowPanelFlowStyle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomFlowPanel(CurrentObject).FlowStyle));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomFlowPanelFlowStyle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomFlowPanel(CurrentObject).FlowStyle:=TFlowStyle(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__TCellItemCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCellItemClass(CurrentClass.ClassRef).Create(TCollection(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCellCollectionOwner(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCellCollection(CurrentObject).Owner);
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCellCollectionItems(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCellCollection(CurrentObject).Items[VarToInteger(GetArrayIndex(0))]));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCellCollectionItems(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCellCollection(CurrentObject).Items[VarToInteger(GetArrayIndex(0))]:=TCellItem(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__TRowCollectionCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TRowCollectionClass(CurrentClass.ClassRef).Create(TPersistent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TRowCollectionAdd(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TRowCollection(CurrentObject).Add);
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TColumnCollectionCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TColumnCollectionClass(CurrentClass.ClassRef).Create(TPersistent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TColumnCollectionAdd(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TColumnCollection(CurrentObject).Add);
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TControlItemCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TControlItemClass(CurrentClass.ClassRef).Create(TCollection(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TControlItemDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TControlItem(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TControlItemSetLocation(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    Case InputArgCount of
      2: TControlItem(CurrentObject).SetLocation(VarToInteger(GetInputArg(0)),VarToInteger(GetInputArg(1)));
      3: TControlItem(CurrentObject).SetLocation(VarToInteger(GetInputArg(0)),VarToInteger(GetInputArg(1)),GetInputArg(2));
    end;
  end;
end;

procedure TatExtCtrlsLibrary.__TControlCollectionCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TControlCollectionClass(CurrentClass.ClassRef).Create(TPersistent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TControlCollectionAdd(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TControlCollection(CurrentObject).Add);
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TControlCollectionAddControl(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    Case InputArgCount of
      1: TControlCollection(CurrentObject).AddControl(TControl(VarToObject(GetInputArg(0))));
      2: TControlCollection(CurrentObject).AddControl(TControl(VarToObject(GetInputArg(0))),VarToInteger(GetInputArg(1)));
      3: TControlCollection(CurrentObject).AddControl(TControl(VarToObject(GetInputArg(0))),VarToInteger(GetInputArg(1)),VarToInteger(GetInputArg(2)));
    end;
  end;
end;

procedure TatExtCtrlsLibrary.__TControlCollectionRemoveControl(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TControlCollection(CurrentObject).RemoveControl(TControl(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatExtCtrlsLibrary.__TControlCollectionIndexOf(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := Integer(TControlCollection(CurrentObject).IndexOf(TControl(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TControlCollectionOwner(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TControlCollection(CurrentObject).Owner);
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTControlCollectionControls(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TControlCollection(CurrentObject).Controls[VarToInteger(GetArrayIndex(0)),VarToInteger(GetArrayIndex(1))]));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTControlCollectionControls(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TControlCollection(CurrentObject).Controls[VarToInteger(GetArrayIndex(0)),VarToInteger(GetArrayIndex(1))]:=TControl(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTControlCollectionControlItems(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TControlCollection(CurrentObject).ControlItems[VarToInteger(GetArrayIndex(0)),VarToInteger(GetArrayIndex(1))]));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTControlCollectionItems(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TControlCollection(CurrentObject).Items[VarToInteger(GetArrayIndex(0))]));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTControlCollectionItems(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TControlCollection(CurrentObject).Items[VarToInteger(GetArrayIndex(0))]:=TControlItem(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomGridPanelCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomGridPanelClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomGridPanelDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomGridPanel(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomGridPanelIsColumnEmpty(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomGridPanel(CurrentObject).IsColumnEmpty(VarToInteger(GetInputArg(0)));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomGridPanelIsRowEmpty(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := TCustomGridPanel(CurrentObject).IsRowEmpty(VarToInteger(GetInputArg(0)));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelColumnSpanIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomGridPanel(CurrentObject).ColumnSpanIndex[VarToInteger(GetArrayIndex(0)),VarToInteger(GetArrayIndex(1))]));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelCellCount(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomGridPanel(CurrentObject).CellCount));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelCellSize(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(integer(TPointWrapper.Create(TCustomGridPanel(CurrentObject).CellSize[VarToInteger(GetArrayIndex(0)),VarToInteger(GetArrayIndex(1))])));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelCellRect(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(integer(TRectWrapper.Create(TCustomGridPanel(CurrentObject).CellRect[VarToInteger(GetArrayIndex(0)),VarToInteger(GetArrayIndex(1))])));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelColumnCollection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomGridPanel(CurrentObject).ColumnCollection));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomGridPanelColumnCollection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomGridPanel(CurrentObject).ColumnCollection:=TColumnCollection(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelControlCollection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomGridPanel(CurrentObject).ControlCollection));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomGridPanelControlCollection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomGridPanel(CurrentObject).ControlCollection:=TControlCollection(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelExpandStyle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomGridPanel(CurrentObject).ExpandStyle));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomGridPanelExpandStyle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomGridPanel(CurrentObject).ExpandStyle:=TExpandStyle(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelRowCollection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomGridPanel(CurrentObject).RowCollection));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomGridPanelRowCollection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomGridPanel(CurrentObject).RowCollection:=TRowCollection(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomGridPanelRowSpanIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomGridPanel(CurrentObject).RowSpanIndex[VarToInteger(GetArrayIndex(0)),VarToInteger(GetArrayIndex(1))]));
  end;
end;

procedure TatExtCtrlsLibrary.__TPageCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TPageClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TNotebookCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TNotebookClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TNotebookDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TNotebook(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__THeaderCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(THeaderClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__THeaderDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    THeader(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__GetTHeaderSectionWidth(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(THeader(CurrentObject).SectionWidth[VarToInteger(GetArrayIndex(0))]));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTHeaderSectionWidth(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    THeader(CurrentObject).SectionWidth[VarToInteger(GetArrayIndex(0))]:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomRadioGroupCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomRadioGroupClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomRadioGroupDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomRadioGroup(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomRadioGroupFlipChildren(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomRadioGroup(CurrentObject).FlipChildren(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomRadioGroupButtons(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomRadioGroup(CurrentObject).Buttons[VarToInteger(GetArrayIndex(0))]));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomRadioGroupWordWrap(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomRadioGroup(CurrentObject).WordWrap);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomRadioGroupWordWrap(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomRadioGroup(CurrentObject).WordWrap:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsLibrary.__TSplitterCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TSplitterClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TSplitterDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TSplitter(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomControlBarCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomControlBarClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomControlBarDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomControlBar(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomControlBarFlipChildren(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomControlBar(CurrentObject).FlipChildren(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomControlBarStickControls(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomControlBar(CurrentObject).StickControls;
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomControlBarPicture(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomControlBar(CurrentObject).Picture));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomControlBarPicture(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomControlBar(CurrentObject).Picture:=TPicture(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__TBoundLabelCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TBoundLabelClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomLabeledEditCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomLabeledEditClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomLabeledEditSetBounds(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomLabeledEdit(CurrentObject).SetBounds(VarToInteger(GetInputArg(0)),VarToInteger(GetInputArg(1)),VarToInteger(GetInputArg(2)),VarToInteger(GetInputArg(3)));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomLabeledEditSetupInternalLabel(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomLabeledEdit(CurrentObject).SetupInternalLabel;
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomLabeledEditEditLabel(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomLabeledEdit(CurrentObject).EditLabel));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomLabeledEditLabelPosition(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomLabeledEdit(CurrentObject).LabelPosition));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomLabeledEditLabelPosition(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomLabeledEdit(CurrentObject).LabelPosition:=TLabelPosition(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomLabeledEditLabelSpacing(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomLabeledEdit(CurrentObject).LabelSpacing));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomLabeledEditLabelSpacing(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomLabeledEdit(CurrentObject).LabelSpacing:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__TEditButtonCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TEditButtonClass(CurrentClass.ClassRef).Create(TCustomButtonedEdit(VarToObject(GetInputArg(0))),GetInputArg(1)));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TEditButtonDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TEditButton(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomButtonedEditCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomButtonedEditClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomButtonedEditDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomButtonedEdit(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomButtonedEditDefaultHandler(AMachine: TatVirtualMachine);
  var
  Param0: Variant;
begin
  with AMachine do
  begin
Param0 := GetInputArg(0);
    TCustomButtonedEdit(CurrentObject).DefaultHandler(Param0);
    SetInputArg(0,Param0);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomButtonedEditImages(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomButtonedEdit(CurrentObject).Images));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomButtonedEditImages(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomButtonedEdit(CurrentObject).Images:=TCustomImageList(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomButtonedEditLeftButton(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomButtonedEdit(CurrentObject).LeftButton));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomButtonedEditLeftButton(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomButtonedEdit(CurrentObject).LeftButton:=TEditButton(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomButtonedEditRightButton(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomButtonedEdit(CurrentObject).RightButton));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomButtonedEditRightButton(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomButtonedEdit(CurrentObject).RightButton:=TEditButton(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomColorBoxCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomColorBoxClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorBoxStyle(AMachine: TatVirtualMachine);
var
PropValueSet: TColorBoxStyle;
begin
  with AMachine do
  begin
    PropValueSet := TCustomColorBox(CurrentObject).Style;
    ReturnOutputArg(IntFromSet(PropValueSet, SizeOf(PropValueSet)));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomColorBoxStyle(AMachine: TatVirtualMachine);
  var
  TempVar: TColorBoxStyle;
begin
  with AMachine do
  begin
    IntToSet(TempVar, VarToInteger(GetInputArg(0)), SizeOf(TempVar));
    TCustomColorBox(CurrentObject).Style:=TempVar;
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorBoxColors(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomColorBox(CurrentObject).Colors[VarToInteger(GetArrayIndex(0))]));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorBoxColorNames(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(string(TCustomColorBox(CurrentObject).ColorNames[VarToInteger(GetArrayIndex(0))]));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorBoxSelected(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomColorBox(CurrentObject).Selected));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomColorBoxSelected(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomColorBox(CurrentObject).Selected:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorBoxDefaultColorColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomColorBox(CurrentObject).DefaultColorColor));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomColorBoxDefaultColorColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomColorBox(CurrentObject).DefaultColorColor:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorBoxNoneColorColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomColorBox(CurrentObject).NoneColorColor));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomColorBoxNoneColorColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomColorBox(CurrentObject).NoneColorColor:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomColorListBoxCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomColorListBoxClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorListBoxStyle(AMachine: TatVirtualMachine);
var
PropValueSet: TColorBoxStyle;
begin
  with AMachine do
  begin
    PropValueSet := TCustomColorListBox(CurrentObject).Style;
    ReturnOutputArg(IntFromSet(PropValueSet, SizeOf(PropValueSet)));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomColorListBoxStyle(AMachine: TatVirtualMachine);
  var
  TempVar: TColorBoxStyle;
begin
  with AMachine do
  begin
    IntToSet(TempVar, VarToInteger(GetInputArg(0)), SizeOf(TempVar));
    TCustomColorListBox(CurrentObject).Style:=TempVar;
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorListBoxColors(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomColorListBox(CurrentObject).Colors[VarToInteger(GetArrayIndex(0))]));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorListBoxColorNames(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(string(TCustomColorListBox(CurrentObject).ColorNames[VarToInteger(GetArrayIndex(0))]));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorListBoxSelected(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomColorListBox(CurrentObject).Selected));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomColorListBoxSelected(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomColorListBox(CurrentObject).Selected:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorListBoxDefaultColorColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomColorListBox(CurrentObject).DefaultColorColor));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomColorListBoxDefaultColorColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomColorListBox(CurrentObject).DefaultColorColor:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomColorListBoxNoneColorColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomColorListBox(CurrentObject).NoneColorColor));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomColorListBoxNoneColorColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomColorListBox(CurrentObject).NoneColorColor:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomTrayIconCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomTrayIconClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomTrayIconDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomTrayIconRefresh(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).Refresh;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomTrayIconSetDefaultIcon(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).SetDefaultIcon;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomTrayIconShowBalloonHint(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).ShowBalloonHint;
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconAnimate(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomTrayIcon(CurrentObject).Animate);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconAnimate(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).Animate:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconAnimateInterval(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomTrayIcon(CurrentObject).AnimateInterval));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconAnimateInterval(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).AnimateInterval:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconHint(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(string(TCustomTrayIcon(CurrentObject).Hint));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconHint(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).Hint:=VarToStr(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconBalloonHint(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(string(TCustomTrayIcon(CurrentObject).BalloonHint));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconBalloonHint(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).BalloonHint:=VarToStr(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconBalloonTitle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(string(TCustomTrayIcon(CurrentObject).BalloonTitle));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconBalloonTitle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).BalloonTitle:=VarToStr(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconBalloonTimeout(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomTrayIcon(CurrentObject).BalloonTimeout));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconBalloonTimeout(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).BalloonTimeout:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconBalloonFlags(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomTrayIcon(CurrentObject).BalloonFlags));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconBalloonFlags(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).BalloonFlags:=TBalloonFlags(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconIcon(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomTrayIcon(CurrentObject).Icon));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconIcon(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).Icon:=TIcon(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconIcons(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomTrayIcon(CurrentObject).Icons));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconIcons(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).Icons:=TCustomImageList(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconIconIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomTrayIcon(CurrentObject).IconIndex));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconIconIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).IconIndex:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconPopupMenu(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomTrayIcon(CurrentObject).PopupMenu));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconPopupMenu(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).PopupMenu:=TPopupMenu(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomTrayIconVisible(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomTrayIcon(CurrentObject).Visible);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomTrayIconVisible(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomTrayIcon(CurrentObject).Visible:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsLibrary.__TCategoryPanelSurfaceCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCategoryPanelSurfaceClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomCategoryPanelClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelCollapse(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).Collapse;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelExpand(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).Expand;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelGetTabControlList(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).GetTabControlList(TList(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelGetTabOrderList(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).GetTabOrderList(TList(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelSetBounds(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).SetBounds(VarToInteger(GetInputArg(0)),VarToInteger(GetInputArg(1)),VarToInteger(GetInputArg(2)),VarToInteger(GetInputArg(3)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelCollapsed(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomCategoryPanel(CurrentObject).Collapsed);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelCollapsed(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).Collapsed:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelCollapsedHotImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanel(CurrentObject).CollapsedHotImageIndex));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelCollapsedHotImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).CollapsedHotImageIndex:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelCollapsedImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanel(CurrentObject).CollapsedImageIndex));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelCollapsedImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).CollapsedImageIndex:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelCollapsedPressedImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanel(CurrentObject).CollapsedPressedImageIndex));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelCollapsedPressedImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).CollapsedPressedImageIndex:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelExpandedHotImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanel(CurrentObject).ExpandedHotImageIndex));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelExpandedHotImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).ExpandedHotImageIndex:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelExpandedImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanel(CurrentObject).ExpandedImageIndex));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelExpandedImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).ExpandedImageIndex:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelExpandedPressedImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanel(CurrentObject).ExpandedPressedImageIndex));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelExpandedPressedImageIndex(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).ExpandedPressedImageIndex:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelHeaderState(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomCategoryPanel(CurrentObject).HeaderState);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelPanelGroup(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomCategoryPanel(CurrentObject).PanelGroup));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelPanelGroup(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanel(CurrentObject).PanelGroup:=TCustomCategoryPanelGroup(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelGroupCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomCategoryPanelGroupClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelGroupDestroy(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).Destroy;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelGroupCollapseAll(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).CollapseAll;
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelGroupCreatePanel(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomCategoryPanelGroup(CurrentObject).CreatePanel(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomCategoryPanelGroupExpandAll(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).ExpandAll;
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupChevronAlignment(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanelGroup(CurrentObject).ChevronAlignment));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupChevronAlignment(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).ChevronAlignment:=TAlignment(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupChevronColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanelGroup(CurrentObject).ChevronColor));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupChevronColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).ChevronColor:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupChevronHotColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanelGroup(CurrentObject).ChevronHotColor));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupChevronHotColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).ChevronHotColor:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupGradientBaseColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanelGroup(CurrentObject).GradientBaseColor));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupGradientBaseColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).GradientBaseColor:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupGradientColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanelGroup(CurrentObject).GradientColor));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupGradientColor(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).GradientColor:=TColor(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupGradientDirection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanelGroup(CurrentObject).GradientDirection));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupGradientDirection(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).GradientDirection:=TGradientDirection(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupHeaderAlignment(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanelGroup(CurrentObject).HeaderAlignment));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupHeaderAlignment(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).HeaderAlignment:=TAlignment(VarToInteger(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupHeaderFont(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomCategoryPanelGroup(CurrentObject).HeaderFont));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupHeaderFont(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).HeaderFont:=TFont(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupHeaderHeight(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(Integer(TCustomCategoryPanelGroup(CurrentObject).HeaderHeight));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupHeaderHeight(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).HeaderHeight:=VarToInteger(GetInputArg(0));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupHeaderImage(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomCategoryPanelGroup(CurrentObject).HeaderImage));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupHeaderImage(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).HeaderImage:=TPicture(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupHeaderStyle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomCategoryPanelGroup(CurrentObject).HeaderStyle);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupHeaderStyle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).HeaderStyle:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupImages(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomCategoryPanelGroup(CurrentObject).Images));
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomCategoryPanelGroupImages(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomCategoryPanelGroup(CurrentObject).Images:=TCustomImageList(VarToObject(GetInputArg(0)));
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomCategoryPanelGroupPanels(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(ObjectToVar(TCustomCategoryPanelGroup(CurrentObject).Panels));
  end;
end;

procedure TatExtCtrlsLibrary.__TCustomLinkLabelCreate(AMachine: TatVirtualMachine);
  var
  AResult: variant;
begin
  with AMachine do
  begin
AResult := ObjectToVar(TCustomLinkLabelClass(CurrentClass.ClassRef).Create(TComponent(VarToObject(GetInputArg(0)))));
    ReturnOutputArg(AResult);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomLinkLabelAlignment(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomLinkLabel(CurrentObject).Alignment);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomLinkLabelAlignment(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomLinkLabel(CurrentObject).Alignment:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomLinkLabelAutoSize(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomLinkLabel(CurrentObject).AutoSize);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomLinkLabelAutoSize(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomLinkLabel(CurrentObject).AutoSize:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsLibrary.__GetTCustomLinkLabelUseVisualStyle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ReturnOutputArg(TCustomLinkLabel(CurrentObject).UseVisualStyle);
  end;
end;

procedure TatExtCtrlsLibrary.__SetTCustomLinkLabelUseVisualStyle(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    TCustomLinkLabel(CurrentObject).UseVisualStyle:=GetInputArg(0);
  end;
end;

procedure TatExtCtrlsDispatcher.__TSectionEvent( Sender: TObject;  ASection: Integer;  AWidth: Integer);
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TSectionEvent(BeforeCall)(Sender,ASection,AWidth);
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,ASection,AWidth]);
    if AssignedMethod(AfterCall) then
      TSectionEvent(AfterCall)(Sender,ASection,AWidth);
  end;
end;

procedure TatExtCtrlsDispatcher.__TSplitterCanResizeEvent( Sender: TObject; var NewSize: Integer; var Accept: Boolean);
var
  NewSizeTemp: variant;
  AcceptTemp: variant;
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TSplitterCanResizeEvent(BeforeCall)(Sender,NewSize,Accept);
    NewSizeTemp := Integer(NewSize);
    AcceptTemp := Accept;
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,NewSizeTemp,AcceptTemp]);
    NewSize := VarToInteger(NewSizeTemp);
    Accept := AcceptTemp;
    if AssignedMethod(AfterCall) then
      TSplitterCanResizeEvent(AfterCall)(Sender,NewSize,Accept);
  end;
end;

procedure TatExtCtrlsDispatcher.__TCanResizeEvent( Sender: TObject; var NewSize: Integer; var Accept: Boolean);
var
  NewSizeTemp: variant;
  AcceptTemp: variant;
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TCanResizeEvent(BeforeCall)(Sender,NewSize,Accept);
    NewSizeTemp := Integer(NewSize);
    AcceptTemp := Accept;
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,NewSizeTemp,AcceptTemp]);
    NewSize := VarToInteger(NewSizeTemp);
    Accept := AcceptTemp;
    if AssignedMethod(AfterCall) then
      TCanResizeEvent(AfterCall)(Sender,NewSize,Accept);
  end;
end;

procedure TatExtCtrlsDispatcher.__TBandDragEvent( Sender: TObject;  Control: TControl; var Drag: Boolean);
var
  DragTemp: variant;
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TBandDragEvent(BeforeCall)(Sender,Control,Drag);
    DragTemp := Drag;
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,Control,DragTemp]);
    Drag := DragTemp;
    if AssignedMethod(AfterCall) then
      TBandDragEvent(AfterCall)(Sender,Control,Drag);
  end;
end;

procedure TatExtCtrlsDispatcher.__TBeginBandMoveEvent( Sender: TObject;  Control: TControl; var AllowMove: Boolean);
var
  AllowMoveTemp: variant;
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TBeginBandMoveEvent(BeforeCall)(Sender,Control,AllowMove);
    AllowMoveTemp := AllowMove;
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,Control,AllowMoveTemp]);
    AllowMove := AllowMoveTemp;
    if AssignedMethod(AfterCall) then
      TBeginBandMoveEvent(AfterCall)(Sender,Control,AllowMove);
  end;
end;

procedure TatExtCtrlsDispatcher.__TEndBandMoveEvent( Sender: TObject;  Control: TControl);
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TEndBandMoveEvent(BeforeCall)(Sender,Control);
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,Control]);
    if AssignedMethod(AfterCall) then
      TEndBandMoveEvent(AfterCall)(Sender,Control);
  end;
end;

procedure TatExtCtrlsDispatcher.__TGetColorsEvent( Sender: TCustomColorBox;  Items: TStrings);
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TGetColorsEvent(BeforeCall)(Sender,Items);
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,Items]);
    if AssignedMethod(AfterCall) then
      TGetColorsEvent(AfterCall)(Sender,Items);
  end;
end;

procedure TatExtCtrlsDispatcher.__TLBGetColorsEvent( Sender: TCustomColorListBox;  Items: TStrings);
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TLBGetColorsEvent(BeforeCall)(Sender,Items);
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,Items]);
    if AssignedMethod(AfterCall) then
      TLBGetColorsEvent(AfterCall)(Sender,Items);
  end;
end;

procedure TatExtCtrlsDispatcher.__TSysLinkEvent( Sender: TObject; const Link: string;  LinkType: TSysLinkType);
var
  LinkTypeTemp: variant;
begin
  if DoOnExecuteEvent then
  begin
    if AssignedMethod(BeforeCall) then
      TSysLinkEvent(BeforeCall)(Sender,Link,LinkType);
    LinkTypeTemp := Integer(LinkType);
    if Assigned(Scripter) and (RoutineName > '') then
      Scripter.ExecuteSubroutine(RoutineName, [Sender,Link,LinkTypeTemp]);
    if AssignedMethod(AfterCall) then
      TSysLinkEvent(AfterCall)(Sender,Link,LinkType);
  end;
end;

procedure TatExtCtrlsLibrary.__Frame3D(AMachine: TatVirtualMachine);
  var
  Param1Rec: TObject;
  Param1: TRect;
begin
  with AMachine do
  begin
Param1Rec := TObject(integer(GetInputArg(1)));
if not Assigned(Param1Rec) or not (Param1Rec is TRectWrapper) then 
  Param1Rec := TRectWrapper.Create(Param1);
Param1 := TRectWrapper(Param1Rec).ObjToRec;
    ExtCtrls.Frame3D(TCanvas(VarToObject(GetInputArg(0))),Param1,TColor(VarToInteger(GetInputArg(2))),TColor(VarToInteger(GetInputArg(3))),VarToInteger(GetInputArg(4)));
    SetInputArg(1,integer(TRectWrapper.Create(Param1)));
  end;
end;

procedure TatExtCtrlsLibrary.__NotebookHandlesNeeded(AMachine: TatVirtualMachine);
begin
  with AMachine do
  begin
    ExtCtrls.NotebookHandlesNeeded(TNotebook(VarToObject(GetInputArg(0))));
  end;
end;

procedure TatExtCtrlsLibrary.Init;
begin
  With Scripter.DefineClass(TShape) do
  begin
    DefineMethod('Create',1,tkClass,TShape,__TShapeCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TShapeDestroy,false,0,'');
    DefineMethod('StyleChanged',1,tkNone,nil,__TShapeStyleChanged,false,0,'Sender: TObject');
  end;
  With Scripter.DefineClass(TPaintBox) do
  begin
    DefineMethod('Create',1,tkClass,TPaintBox,__TPaintBoxCreate,true,0,'AOwner: TComponent');
    DefineProp('Canvas',tkVariant,nil,nil,nil,false,0);
  end;
  With Scripter.DefineClass(TImage) do
  begin
    DefineMethod('Create',1,tkClass,TImage,__TImageCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TImageDestroy,false,0,'');
    DefineProp('Canvas',tkClass,__GetTImageCanvas,nil,TCanvas,false,0);
  end;
  With Scripter.DefineClass(TBevel) do
  begin
    DefineMethod('Create',1,tkClass,TBevel,__TBevelCreate,true,0,'AOwner: TComponent');
  end;
  With Scripter.DefineClass(TTimer) do
  begin
    DefineMethod('Create',1,tkClass,TTimer,__TTimerCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TTimerDestroy,false,0,'');
  end;
  With Scripter.DefineClass(TCustomPanel) do
  begin
    DefineMethod('Create',1,tkClass,TCustomPanel,__TCustomPanelCreate,true,0,'AOwner: TComponent');
    DefineMethod('GetControlsAlignment',0,tkEnumeration,nil,__TCustomPanelGetControlsAlignment,false,0,'');
    DefineProp('ParentBackground',tkVariant,nil,nil,nil,false,0);
  end;
  With Scripter.DefineClass(TPanel) do
  begin
    DefineProp('DockManager',tkVariant,nil,nil,nil,false,0);
  end;
  With Scripter.DefineClass(TCustomFlowPanel) do
  begin
    DefineMethod('Create',1,tkClass,TCustomFlowPanel,__TCustomFlowPanelCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TCustomFlowPanelDestroy,false,0,'');
    DefineMethod('GetControlIndex',1,tkInteger,nil,__TCustomFlowPanelGetControlIndex,false,0,'AControl: TControl');
    DefineMethod('SetControlIndex',2,tkNone,nil,__TCustomFlowPanelSetControlIndex,false,0,'AControl: TControl; Index: Integer');
    DefineProp('AutoWrap',tkVariant,__GetTCustomFlowPanelAutoWrap,__SetTCustomFlowPanelAutoWrap,nil,false,0);
    DefineProp('FlowStyle',tkEnumeration,__GetTCustomFlowPanelFlowStyle,__SetTCustomFlowPanelFlowStyle,nil,false,0);
  end;
  With Scripter.DefineClass(TFlowPanel) do
  begin
  end;
  With Scripter.DefineClass(EGridPanelException) do
  begin
  end;
  With Scripter.DefineClass(TCellItem) do
  begin
    DefineMethod('Create',1,tkClass,TCellItem,__TCellItemCreate,true,0,'Collection: TCollection');
  end;
  With Scripter.DefineClass(TRowItem) do
  begin
  end;
  With Scripter.DefineClass(TColumnItem) do
  begin
  end;
  With Scripter.DefineClass(TCellCollection) do
  begin
    DefineMethod('Owner',0,tkClass,TCustomGridPanel,__TCellCollectionOwner,false,0,'');
    DefaultProperty := DefineProp('Items',tkClass,__GetTCellCollectionItems,__SetTCellCollectionItems,TCellItem,false,1);
  end;
  With Scripter.DefineClass(TRowCollection) do
  begin
    DefineMethod('Create',1,tkClass,TRowCollection,__TRowCollectionCreate,true,0,'AOwner: TPersistent');
    DefineMethod('Add',0,tkClass,TRowItem,__TRowCollectionAdd,false,0,'');
  end;
  With Scripter.DefineClass(TColumnCollection) do
  begin
    DefineMethod('Create',1,tkClass,TColumnCollection,__TColumnCollectionCreate,true,0,'AOwner: TPersistent');
    DefineMethod('Add',0,tkClass,TColumnItem,__TColumnCollectionAdd,false,0,'');
  end;
  With Scripter.DefineClass(TControlItem) do
  begin
    DefineMethod('Create',1,tkClass,TControlItem,__TControlItemCreate,true,0,'Collection: TCollection');
    DefineMethod('Destroy',0,tkNone,nil,__TControlItemDestroy,false,0,'');
    DefineMethod('SetLocation',3,tkNone,nil,__TControlItemSetLocation,false,1,'AColumn: Integer; ARow: Integer; APushed: Boolean = False');
  end;
  With Scripter.DefineClass(TControlCollection) do
  begin
    DefineMethod('Create',1,tkClass,TControlCollection,__TControlCollectionCreate,true,0,'AOwner: TPersistent');
    DefineMethod('Add',0,tkClass,TControlItem,__TControlCollectionAdd,false,0,'');
    DefineMethod('AddControl',3,tkNone,nil,__TControlCollectionAddControl,false,2,'AControl: TControl; AColumn: Integer = -1; ARow: Integer = -1');
    DefineMethod('RemoveControl',1,tkNone,nil,__TControlCollectionRemoveControl,false,0,'AControl: TControl');
    DefineMethod('IndexOf',1,tkInteger,nil,__TControlCollectionIndexOf,false,0,'AControl: TControl');
    DefineMethod('Owner',0,tkClass,TCustomGridPanel,__TControlCollectionOwner,false,0,'');
    DefineProp('Controls',tkClass,__GetTControlCollectionControls,__SetTControlCollectionControls,TControl,false,2);
    DefineProp('ControlItems',tkClass,__GetTControlCollectionControlItems,nil,TControlItem,false,2);
    DefaultProperty := DefineProp('Items',tkClass,__GetTControlCollectionItems,__SetTControlCollectionItems,TControlItem,false,1);
  end;
  With Scripter.DefineClass(TCustomGridPanel) do
  begin
    DefineMethod('Create',1,tkClass,TCustomGridPanel,__TCustomGridPanelCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TCustomGridPanelDestroy,false,0,'');
    DefineMethod('IsColumnEmpty',1,tkVariant,nil,__TCustomGridPanelIsColumnEmpty,false,0,'AColumn: Integer');
    DefineMethod('IsRowEmpty',1,tkVariant,nil,__TCustomGridPanelIsRowEmpty,false,0,'ARow: Integer');
    DefineProp('ColumnSpanIndex',tkInteger,__GetTCustomGridPanelColumnSpanIndex,nil,nil,false,2);
    DefineProp('CellCount',tkInteger,__GetTCustomGridPanelCellCount,nil,nil,false,0);
    DefineProp('CellSize',tkVariant,__GetTCustomGridPanelCellSize,nil,nil,false,2);
    DefineProp('CellRect',tkVariant,__GetTCustomGridPanelCellRect,nil,nil,false,2);
    DefineProp('ColumnCollection',tkClass,__GetTCustomGridPanelColumnCollection,__SetTCustomGridPanelColumnCollection,TColumnCollection,false,0);
    DefineProp('ControlCollection',tkClass,__GetTCustomGridPanelControlCollection,__SetTCustomGridPanelControlCollection,TControlCollection,false,0);
    DefineProp('ExpandStyle',tkEnumeration,__GetTCustomGridPanelExpandStyle,__SetTCustomGridPanelExpandStyle,nil,false,0);
    DefineProp('RowCollection',tkClass,__GetTCustomGridPanelRowCollection,__SetTCustomGridPanelRowCollection,TRowCollection,false,0);
    DefineProp('RowSpanIndex',tkInteger,__GetTCustomGridPanelRowSpanIndex,nil,nil,false,2);
  end;
  With Scripter.DefineClass(TGridPanel) do
  begin
    DefineProp('DockManager',tkVariant,nil,nil,nil,false,0);
  end;
  With Scripter.DefineClass(TPage) do
  begin
    DefineMethod('Create',1,tkClass,TPage,__TPageCreate,true,0,'AOwner: TComponent');
  end;
  With Scripter.DefineClass(TNotebook) do
  begin
    DefineMethod('Create',1,tkClass,TNotebook,__TNotebookCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TNotebookDestroy,false,0,'');
  end;
  With Scripter.DefineClass(THeader) do
  begin
    DefineMethod('Create',1,tkClass,THeader,__THeaderCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__THeaderDestroy,false,0,'');
    DefineProp('SectionWidth',tkInteger,__GetTHeaderSectionWidth,__SetTHeaderSectionWidth,nil,false,1);
  end;
  With Scripter.DefineClass(TCustomRadioGroup) do
  begin
    DefineMethod('Create',1,tkClass,TCustomRadioGroup,__TCustomRadioGroupCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TCustomRadioGroupDestroy,false,0,'');
    DefineMethod('FlipChildren',1,tkNone,nil,__TCustomRadioGroupFlipChildren,false,0,'AllLevels: Boolean');
    DefineProp('Buttons',tkClass,__GetTCustomRadioGroupButtons,nil,TRadioButton,false,1);
    DefineProp('WordWrap',tkVariant,__GetTCustomRadioGroupWordWrap,__SetTCustomRadioGroupWordWrap,nil,false,0);
  end;
  With Scripter.DefineClass(TRadioGroup) do
  begin
  end;
  With Scripter.DefineClass(TSplitter) do
  begin
    DefineMethod('Create',1,tkClass,TSplitter,__TSplitterCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TSplitterDestroy,false,0,'');
    DefineProp('Canvas',tkVariant,nil,nil,nil,false,0);
  end;
  With Scripter.DefineClass(TCustomControlBar) do
  begin
    DefineMethod('Create',1,tkClass,TCustomControlBar,__TCustomControlBarCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TCustomControlBarDestroy,false,0,'');
    DefineMethod('FlipChildren',1,tkNone,nil,__TCustomControlBarFlipChildren,false,0,'AllLevels: Boolean');
    DefineMethod('StickControls',0,tkNone,nil,__TCustomControlBarStickControls,false,0,'');
    DefineProp('Picture',tkClass,__GetTCustomControlBarPicture,__SetTCustomControlBarPicture,TPicture,false,0);
  end;
  With Scripter.DefineClass(TControlBar) do
  begin
    DefineProp('Canvas',tkVariant,nil,nil,nil,false,0);
  end;
  With Scripter.DefineClass(TBoundLabel) do
  begin
    DefineMethod('Create',1,tkClass,TBoundLabel,__TBoundLabelCreate,true,0,'AOwner: TComponent');
  end;
  With Scripter.DefineClass(TCustomLabeledEdit) do
  begin
    DefineMethod('Create',1,tkClass,TCustomLabeledEdit,__TCustomLabeledEditCreate,true,0,'AOwner: TComponent');
    DefineMethod('SetBounds',4,tkNone,nil,__TCustomLabeledEditSetBounds,false,0,'ALeft: Integer; ATop: Integer; AWidth: Integer; AHeight: Integer');
    DefineMethod('SetupInternalLabel',0,tkNone,nil,__TCustomLabeledEditSetupInternalLabel,false,0,'');
    DefineProp('EditLabel',tkClass,__GetTCustomLabeledEditEditLabel,nil,TBoundLabel,false,0);
    DefineProp('LabelPosition',tkEnumeration,__GetTCustomLabeledEditLabelPosition,__SetTCustomLabeledEditLabelPosition,nil,false,0);
    DefineProp('LabelSpacing',tkInteger,__GetTCustomLabeledEditLabelSpacing,__SetTCustomLabeledEditLabelSpacing,nil,false,0);
  end;
  With Scripter.DefineClass(TLabeledEdit) do
  begin
  end;
  With Scripter.DefineClass(TEditButton) do
  begin
    DefineMethod('Create',2,tkClass,TEditButton,__TEditButtonCreate,true,0,'EditControl: TCustomButtonedEdit; APosition: TButtonPosition');
    DefineMethod('Destroy',0,tkNone,nil,__TEditButtonDestroy,false,0,'');
  end;
  With Scripter.DefineClass(TCustomButtonedEdit) do
  begin
    DefineMethod('Create',1,tkClass,TCustomButtonedEdit,__TCustomButtonedEditCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TCustomButtonedEditDestroy,false,0,'');
    DefineMethod('DefaultHandler',1,tkNone,nil,__TCustomButtonedEditDefaultHandler,false,0,'Message').SetVarArgs([0]);
    DefineProp('Images',tkClass,__GetTCustomButtonedEditImages,__SetTCustomButtonedEditImages,TCustomImageList,false,0);
    DefineProp('LeftButton',tkClass,__GetTCustomButtonedEditLeftButton,__SetTCustomButtonedEditLeftButton,TEditButton,false,0);
    DefineProp('RightButton',tkClass,__GetTCustomButtonedEditRightButton,__SetTCustomButtonedEditRightButton,TEditButton,false,0);
  end;
  With Scripter.DefineClass(TButtonedEdit) do
  begin
  end;
  With Scripter.DefineClass(TCustomColorBox) do
  begin
    DefineMethod('Create',1,tkClass,TCustomColorBox,__TCustomColorBoxCreate,true,0,'AOwner: TComponent');
    DefineProp('Style',tkInteger,__GetTCustomColorBoxStyle,__SetTCustomColorBoxStyle,nil,false,0);
    DefineProp('Colors',tkEnumeration,__GetTCustomColorBoxColors,nil,nil,false,1);
    DefineProp('ColorNames',tkVariant,__GetTCustomColorBoxColorNames,nil,nil,false,1);
    DefineProp('Selected',tkEnumeration,__GetTCustomColorBoxSelected,__SetTCustomColorBoxSelected,nil,false,0);
    DefineProp('DefaultColorColor',tkEnumeration,__GetTCustomColorBoxDefaultColorColor,__SetTCustomColorBoxDefaultColorColor,nil,false,0);
    DefineProp('NoneColorColor',tkEnumeration,__GetTCustomColorBoxNoneColorColor,__SetTCustomColorBoxNoneColorColor,nil,false,0);
  end;
  With Scripter.DefineClass(TColorBox) do
  begin
  end;
  With Scripter.DefineClass(TCustomColorListBox) do
  begin
    DefineMethod('Create',1,tkClass,TCustomColorListBox,__TCustomColorListBoxCreate,true,0,'AOwner: TComponent');
    DefineProp('Style',tkInteger,__GetTCustomColorListBoxStyle,__SetTCustomColorListBoxStyle,nil,false,0);
    DefineProp('Colors',tkEnumeration,__GetTCustomColorListBoxColors,nil,nil,false,1);
    DefineProp('ColorNames',tkVariant,__GetTCustomColorListBoxColorNames,nil,nil,false,1);
    DefineProp('Selected',tkEnumeration,__GetTCustomColorListBoxSelected,__SetTCustomColorListBoxSelected,nil,false,0);
    DefineProp('DefaultColorColor',tkEnumeration,__GetTCustomColorListBoxDefaultColorColor,__SetTCustomColorListBoxDefaultColorColor,nil,false,0);
    DefineProp('NoneColorColor',tkEnumeration,__GetTCustomColorListBoxNoneColorColor,__SetTCustomColorListBoxNoneColorColor,nil,false,0);
  end;
  With Scripter.DefineClass(TColorListBox) do
  begin
  end;
  With Scripter.DefineClass(TCustomTrayIcon) do
  begin
    DefineMethod('Create',1,tkClass,TCustomTrayIcon,__TCustomTrayIconCreate,true,0,'Owner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TCustomTrayIconDestroy,false,0,'');
    DefineMethod('Refresh',0,tkNone,nil,__TCustomTrayIconRefresh,false,0,'');
    DefineMethod('SetDefaultIcon',0,tkNone,nil,__TCustomTrayIconSetDefaultIcon,false,0,'');
    DefineMethod('ShowBalloonHint',0,tkNone,nil,__TCustomTrayIconShowBalloonHint,false,0,'');
    DefineProp('Animate',tkVariant,__GetTCustomTrayIconAnimate,__SetTCustomTrayIconAnimate,nil,false,0);
    DefineProp('AnimateInterval',tkInteger,__GetTCustomTrayIconAnimateInterval,__SetTCustomTrayIconAnimateInterval,nil,false,0);
    DefineProp('Hint',tkVariant,__GetTCustomTrayIconHint,__SetTCustomTrayIconHint,nil,false,0);
    DefineProp('BalloonHint',tkVariant,__GetTCustomTrayIconBalloonHint,__SetTCustomTrayIconBalloonHint,nil,false,0);
    DefineProp('BalloonTitle',tkVariant,__GetTCustomTrayIconBalloonTitle,__SetTCustomTrayIconBalloonTitle,nil,false,0);
    DefineProp('BalloonTimeout',tkInteger,__GetTCustomTrayIconBalloonTimeout,__SetTCustomTrayIconBalloonTimeout,nil,false,0);
    DefineProp('BalloonFlags',tkEnumeration,__GetTCustomTrayIconBalloonFlags,__SetTCustomTrayIconBalloonFlags,nil,false,0);
    DefineProp('Icon',tkClass,__GetTCustomTrayIconIcon,__SetTCustomTrayIconIcon,TIcon,false,0);
    DefineProp('Icons',tkClass,__GetTCustomTrayIconIcons,__SetTCustomTrayIconIcons,TCustomImageList,false,0);
    DefineProp('IconIndex',tkInteger,__GetTCustomTrayIconIconIndex,__SetTCustomTrayIconIconIndex,nil,false,0);
    DefineProp('PopupMenu',tkClass,__GetTCustomTrayIconPopupMenu,__SetTCustomTrayIconPopupMenu,TPopupMenu,false,0);
    DefineProp('Visible',tkVariant,__GetTCustomTrayIconVisible,__SetTCustomTrayIconVisible,nil,false,0);
  end;
  With Scripter.DefineClass(TTrayIcon) do
  begin
  end;
  With Scripter.DefineClass(TCategoryPanelSurface) do
  begin
    DefineMethod('Create',1,tkClass,TCategoryPanelSurface,__TCategoryPanelSurfaceCreate,true,0,'AOwner: TComponent');
  end;
  With Scripter.DefineClass(TCustomCategoryPanel) do
  begin
    DefineMethod('Create',1,tkClass,TCustomCategoryPanel,__TCustomCategoryPanelCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TCustomCategoryPanelDestroy,false,0,'');
    DefineMethod('Collapse',0,tkNone,nil,__TCustomCategoryPanelCollapse,false,0,'');
    DefineMethod('Expand',0,tkNone,nil,__TCustomCategoryPanelExpand,false,0,'');
    DefineMethod('GetTabControlList',1,tkNone,nil,__TCustomCategoryPanelGetTabControlList,false,0,'List: TList');
    DefineMethod('GetTabOrderList',1,tkNone,nil,__TCustomCategoryPanelGetTabOrderList,false,0,'List: TList');
    DefineMethod('SetBounds',4,tkNone,nil,__TCustomCategoryPanelSetBounds,false,0,'ALeft: Integer; ATop: Integer; AWidth: Integer; AHeight: Integer');
    DefineProp('Collapsed',tkVariant,__GetTCustomCategoryPanelCollapsed,__SetTCustomCategoryPanelCollapsed,nil,false,0);
    DefineProp('CollapsedHotImageIndex',tkInteger,__GetTCustomCategoryPanelCollapsedHotImageIndex,__SetTCustomCategoryPanelCollapsedHotImageIndex,nil,false,0);
    DefineProp('CollapsedImageIndex',tkInteger,__GetTCustomCategoryPanelCollapsedImageIndex,__SetTCustomCategoryPanelCollapsedImageIndex,nil,false,0);
    DefineProp('CollapsedPressedImageIndex',tkInteger,__GetTCustomCategoryPanelCollapsedPressedImageIndex,__SetTCustomCategoryPanelCollapsedPressedImageIndex,nil,false,0);
    DefineProp('ExpandedHotImageIndex',tkInteger,__GetTCustomCategoryPanelExpandedHotImageIndex,__SetTCustomCategoryPanelExpandedHotImageIndex,nil,false,0);
    DefineProp('ExpandedImageIndex',tkInteger,__GetTCustomCategoryPanelExpandedImageIndex,__SetTCustomCategoryPanelExpandedImageIndex,nil,false,0);
    DefineProp('ExpandedPressedImageIndex',tkInteger,__GetTCustomCategoryPanelExpandedPressedImageIndex,__SetTCustomCategoryPanelExpandedPressedImageIndex,nil,false,0);
    DefineProp('HeaderState',tkVariant,__GetTCustomCategoryPanelHeaderState,nil,nil,false,0);
    DefineProp('PanelGroup',tkClass,__GetTCustomCategoryPanelPanelGroup,__SetTCustomCategoryPanelPanelGroup,TCustomCategoryPanelGroup,false,0);
  end;
  With Scripter.DefineClass(TCategoryPanel) do
  begin
  end;
  With Scripter.DefineClass(TCustomCategoryPanelGroup) do
  begin
    DefineMethod('Create',1,tkClass,TCustomCategoryPanelGroup,__TCustomCategoryPanelGroupCreate,true,0,'AOwner: TComponent');
    DefineMethod('Destroy',0,tkNone,nil,__TCustomCategoryPanelGroupDestroy,false,0,'');
    DefineMethod('CollapseAll',0,tkNone,nil,__TCustomCategoryPanelGroupCollapseAll,false,0,'');
    DefineMethod('CreatePanel',1,tkClass,TCustomCategoryPanel,__TCustomCategoryPanelGroupCreatePanel,false,0,'AOwner: TComponent');
    DefineMethod('ExpandAll',0,tkNone,nil,__TCustomCategoryPanelGroupExpandAll,false,0,'');
    DefineProp('ChevronAlignment',tkEnumeration,__GetTCustomCategoryPanelGroupChevronAlignment,__SetTCustomCategoryPanelGroupChevronAlignment,nil,false,0);
    DefineProp('ChevronColor',tkEnumeration,__GetTCustomCategoryPanelGroupChevronColor,__SetTCustomCategoryPanelGroupChevronColor,nil,false,0);
    DefineProp('ChevronHotColor',tkEnumeration,__GetTCustomCategoryPanelGroupChevronHotColor,__SetTCustomCategoryPanelGroupChevronHotColor,nil,false,0);
    DefineProp('Color',tkVariant,nil,nil,nil,false,0);
    DefineProp('GradientBaseColor',tkEnumeration,__GetTCustomCategoryPanelGroupGradientBaseColor,__SetTCustomCategoryPanelGroupGradientBaseColor,nil,false,0);
    DefineProp('GradientColor',tkEnumeration,__GetTCustomCategoryPanelGroupGradientColor,__SetTCustomCategoryPanelGroupGradientColor,nil,false,0);
    DefineProp('GradientDirection',tkEnumeration,__GetTCustomCategoryPanelGroupGradientDirection,__SetTCustomCategoryPanelGroupGradientDirection,nil,false,0);
    DefineProp('HeaderAlignment',tkEnumeration,__GetTCustomCategoryPanelGroupHeaderAlignment,__SetTCustomCategoryPanelGroupHeaderAlignment,nil,false,0);
    DefineProp('HeaderFont',tkClass,__GetTCustomCategoryPanelGroupHeaderFont,__SetTCustomCategoryPanelGroupHeaderFont,TFont,false,0);
    DefineProp('HeaderHeight',tkInteger,__GetTCustomCategoryPanelGroupHeaderHeight,__SetTCustomCategoryPanelGroupHeaderHeight,nil,false,0);
    DefineProp('HeaderImage',tkClass,__GetTCustomCategoryPanelGroupHeaderImage,__SetTCustomCategoryPanelGroupHeaderImage,TPicture,false,0);
    DefineProp('HeaderStyle',tkVariant,__GetTCustomCategoryPanelGroupHeaderStyle,__SetTCustomCategoryPanelGroupHeaderStyle,nil,false,0);
    DefineProp('Images',tkClass,__GetTCustomCategoryPanelGroupImages,__SetTCustomCategoryPanelGroupImages,TCustomImageList,false,0);
    DefineProp('Panels',tkClass,__GetTCustomCategoryPanelGroupPanels,nil,TList,false,0);
  end;
  With Scripter.DefineClass(TCategoryPanelGroup) do
  begin
  end;
  With Scripter.DefineClass(TCustomLinkLabel) do
  begin
    DefineMethod('Create',1,tkClass,TCustomLinkLabel,__TCustomLinkLabelCreate,true,0,'AOwner: TComponent');
    DefineProp('Alignment',tkVariant,__GetTCustomLinkLabelAlignment,__SetTCustomLinkLabelAlignment,nil,false,0);
    DefineProp('AutoSize',tkVariant,__GetTCustomLinkLabelAutoSize,__SetTCustomLinkLabelAutoSize,nil,false,0);
    DefineProp('UseVisualStyle',tkVariant,__GetTCustomLinkLabelUseVisualStyle,__SetTCustomLinkLabelUseVisualStyle,nil,false,0);
  end;
  With Scripter.DefineClass(TLinkLabel) do
  begin
  end;
  DefineEventAdapter(TypeInfo(TSectionEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TSectionEvent);
  DefineEventAdapter(TypeInfo(TSplitterCanResizeEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TSplitterCanResizeEvent);
  DefineEventAdapter(TypeInfo(TCanResizeEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TCanResizeEvent);
  DefineEventAdapter(TypeInfo(TBandDragEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TBandDragEvent);
  DefineEventAdapter(TypeInfo(TBeginBandMoveEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TBeginBandMoveEvent);
  DefineEventAdapter(TypeInfo(TEndBandMoveEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TEndBandMoveEvent);
  DefineEventAdapter(TypeInfo(TGetColorsEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TGetColorsEvent);
  DefineEventAdapter(TypeInfo(TLBGetColorsEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TLBGetColorsEvent);
  DefineEventAdapter(TypeInfo(TSysLinkEvent), TatExtCtrlsDispatcher, @TatExtCtrlsDispatcher.__TSysLinkEvent);
  With Scripter.DefineClass(ClassType) do
  begin
    DefineMethod('Frame3D',5,tkNone,nil,__Frame3D,false,0,'Canvas: TCanvas; Rect: TRect; TopColor: TColor; BottomColor: TColor; Width: Integer').SetVarArgs([1]);
    DefineMethod('NotebookHandlesNeeded',1,tkNone,nil,__NotebookHandlesNeeded,false,0,'Notebook: TNotebook');
    AddConstant('stRectangle',stRectangle);
    AddConstant('stSquare',stSquare);
    AddConstant('stRoundRect',stRoundRect);
    AddConstant('stRoundSquare',stRoundSquare);
    AddConstant('stEllipse',stEllipse);
    AddConstant('stCircle',stCircle);
    AddConstant('bsLowered',bsLowered);
    AddConstant('bsRaised',bsRaised);
    AddConstant('bsBox',bsBox);
    AddConstant('bsFrame',bsFrame);
    AddConstant('bsTopLine',bsTopLine);
    AddConstant('bsBottomLine',bsBottomLine);
    AddConstant('bsLeftLine',bsLeftLine);
    AddConstant('bsRightLine',bsRightLine);
    AddConstant('bsSpacer',bsSpacer);
    AddConstant('fsLeftRightTopBottom',fsLeftRightTopBottom);
    AddConstant('fsRightLeftTopBottom',fsRightLeftTopBottom);
    AddConstant('fsLeftRightBottomTop',fsLeftRightBottomTop);
    AddConstant('fsRightLeftBottomTop',fsRightLeftBottomTop);
    AddConstant('fsTopBottomLeftRight',fsTopBottomLeftRight);
    AddConstant('fsBottomTopLeftRight',fsBottomTopLeftRight);
    AddConstant('fsTopBottomRightLeft',fsTopBottomRightLeft);
    AddConstant('fsBottomTopRightLeft',fsBottomTopRightLeft);
    AddConstant('ssAbsolute',ssAbsolute);
    AddConstant('ssPercent',ssPercent);
    AddConstant('ssAuto',ssAuto);
    AddConstant('emAddRows',emAddRows);
    AddConstant('emAddColumns',emAddColumns);
    AddConstant('emFixedSize',emFixedSize);
    AddConstant('rsNone',rsNone);
    AddConstant('rsLine',rsLine);
    AddConstant('rsUpdate',rsUpdate);
    AddConstant('rsPattern',rsPattern);
    AddConstant('bpoGrabber',bpoGrabber);
    AddConstant('bpoFrame',bpoFrame);
    AddConstant('bpoGradient',bpoGradient);
    AddConstant('bpoRoundRect',bpoRoundRect);
    AddConstant('dsNormal',dsNormal);
    AddConstant('dsGradient',dsGradient);
    AddConstant('ceNone',ceNone);
    AddConstant('ceSmall',ceSmall);
    AddConstant('ceMedium',ceMedium);
    AddConstant('ceLarge',ceLarge);
    AddConstant('lpAbove',lpAbove);
    AddConstant('lpBelow',lpBelow);
    AddConstant('lpLeft',lpLeft);
    AddConstant('lpRight',lpRight);
    AddConstant('cbStandardColors',cbStandardColors);
    AddConstant('cbExtendedColors',cbExtendedColors);
    AddConstant('cbSystemColors',cbSystemColors);
    AddConstant('cbIncludeNone',cbIncludeNone);
    AddConstant('cbIncludeDefault',cbIncludeDefault);
    AddConstant('cbCustomColor',cbCustomColor);
    AddConstant('cbPrettyNames',cbPrettyNames);
    AddConstant('cbCustomColors',cbCustomColors);
    AddConstant('bfNone',bfNone);
    AddConstant('bfInfo',bfInfo);
    AddConstant('bfWarning',bfWarning);
    AddConstant('bfError',bfError);
    AddConstant('sltURL',sltURL);
    AddConstant('sltID',sltID);
    AddConstant('NoColorSelected',NoColorSelected);
    AddConstant('WM_SYSTEM_TRAY_MESSAGE',WM_SYSTEM_TRAY_MESSAGE);
    AddConstant('DefaultCategoryPanelHeight',DefaultCategoryPanelHeight);
  end;
end;

class function TatExtCtrlsLibrary.LibraryName: string;
begin
  result := 'ExtCtrls';
end;

initialization
  RegisterScripterLibrary(TatExtCtrlsLibrary, True);

{$WARNINGS ON}

end.

