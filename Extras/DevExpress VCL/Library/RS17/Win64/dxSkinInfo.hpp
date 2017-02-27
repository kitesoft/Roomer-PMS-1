// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinInfo.pas' rev: 24.00 (Win64)

#ifndef DxskininfoHPP
#define DxskininfoHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinsStrs.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskininfo
{
//-- type declarations -------------------------------------------------------
enum TdxSkinFormIcon : unsigned char { sfiMenu, sfiHelp, sfiMinimize, sfiMaximize, sfiRestore, sfiClose };

typedef System::Set<TdxSkinFormIcon, TdxSkinFormIcon::sfiMenu, TdxSkinFormIcon::sfiClose>  TdxSkinFormIcons;

class DELPHICLASS TdxSkinScrollInfo;
class PASCALIMPLEMENTATION TdxSkinScrollInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxskinscore::TdxSkinElement* FElement;
	int FImageIndex;
	
public:
	__fastcall TdxSkinScrollInfo(Dxskinscore::TdxSkinElement* AElement, int AImageIndex, Cxlookandfeelpainters::TcxScrollBarPart APart);
	bool __fastcall Draw(HDC DC, const System::Types::TRect &R, int AImageIndex, Dxskinscore::TdxSkinElementState AState)/* overload */;
	bool __fastcall Draw(HDC DC, const System::Types::TRect &R, Dxskinscore::TdxSkinElementState AState)/* overload */;
	__property Dxskinscore::TdxSkinElement* Element = {read=FElement};
	__property int ImageIndex = {read=FImageIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinScrollInfo(void) { }
	
};


class DELPHICLASS TdxSkinElementHelper;
class PASCALIMPLEMENTATION TdxSkinElementHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod System::Types::TSize __fastcall CalculateCaptionButtonSize(int ACaptionHeight, Dxskinscore::TdxSkinElement* AElement);
	__classmethod bool __fastcall IsAlternateImageSetUsed(Dxskinscore::TdxSkinElement* AElement, int AImageIndex, Dxskinscore::TdxSkinElementState AState);
public:
	/* TObject.Create */ inline __fastcall TdxSkinElementHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinElementHelper(void) { }
	
};


class DELPHICLASS TdxSkinInfo;
class PASCALIMPLEMENTATION TdxSkinInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Dxskinscore::TdxSkin* FSkin;
	void __fastcall MarkObjectUsed(Dxskinscore::TdxSkinCustomObject* AObject);
	void __fastcall SetSkin(Dxskinscore::TdxSkin* ASkin);
	
protected:
	Dxskinscore::TdxSkinControlGroup* GroupBars;
	Dxskinscore::TdxSkinControlGroup* GroupCommon;
	Dxskinscore::TdxSkinControlGroup* GroupDocking;
	Dxskinscore::TdxSkinControlGroup* GroupEditors;
	Dxskinscore::TdxSkinControlGroup* GroupForm;
	Dxskinscore::TdxSkinControlGroup* GroupGrid;
	Dxskinscore::TdxSkinControlGroup* GroupNavBar;
	Dxskinscore::TdxSkinControlGroup* GroupNavPane;
	Dxskinscore::TdxSkinControlGroup* GroupPrintingSystem;
	Dxskinscore::TdxSkinControlGroup* GroupRibbon;
	Dxskinscore::TdxSkinControlGroup* GroupScheduler;
	Dxskinscore::TdxSkinControlGroup* GroupTabs;
	Dxskinscore::TdxSkinControlGroup* GroupTileControl;
	Dxskinscore::TdxSkinControlGroup* GroupVGrid;
	Dxskinscore::TdxSkinElement* CardViewSeparator;
	Dxskinscore::TdxSkinElement* CheckboxElement;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> ClockElements;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> EditButtonElements;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 8> EditButtonGlyphs;
	bool EditButtonMergeBorders;
	Dxskinscore::TdxSkinElement* GridGroupByBox;
	Dxskinscore::TdxSkinElement* GridGroupRow;
	Dxskinscore::TdxSkinElement* GridLine;
	Dxskinscore::TdxSkinElement* GridFixedLine;
	Dxskinscore::TdxSkinColor* GridGroupRowStyleOffice11ContentColor;
	Dxskinscore::TdxSkinColor* GridGroupRowStyleOffice11SeparatorColor;
	Dxskinscore::TdxSkinColor* GridGroupRowStyleOffice11TextColor;
	Dxskinscore::TdxSkinElement* IndicatorImages;
	Dxskinscore::TdxSkinElement* NavigatorButton;
	Dxskinscore::TdxSkinElement* NavigatorGlyphs;
	Dxskinscore::TdxSkinElement* NavigatorGlyphsVert;
	Dxskinscore::TdxSkinElement* RadioGroupButton;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> Splitter;
	System::StaticArray<System::StaticArray<Dxskinscore::TdxSkinElement*, 3>, 2> TrackBarThumb;
	Dxskinscore::TdxSkinColor* TrackBarTickColor;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> TrackBarTrack;
	Dxskinscore::TdxSkinElement* VGridCategory;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> VGridLine;
	Dxskinscore::TdxSkinElement* VGridRowHeader;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 28> CalcEditButtonTextColors;
	Dxskinscore::TdxSkinColor* ContentEvenColor;
	Dxskinscore::TdxSkinColor* ContentOddColor;
	Dxskinscore::TdxSkinColor* ContentTextColor;
	Dxskinscore::TdxSkinColor* HeaderBackgroundColor;
	Dxskinscore::TdxSkinColor* HeaderBackgroundTextColor;
	Dxskinscore::TdxSkinColor* SelectionColor;
	Dxskinscore::TdxSkinColor* SelectionTextColor;
	Dxskinscore::TdxSkinColor* TreeListGridLineColor;
	Dxskinscore::TdxSkinColor* TreeListTreeLineColor;
	Dxskinscore::TdxSkinElement* ExpandButton;
	Dxskinscore::TdxSkinElement* FooterCell;
	Dxskinscore::TdxSkinElement* FooterPanel;
	Dxskinscore::TdxSkinElement* Header;
	Dxskinscore::TdxSkinElement* HeaderSpecial;
	Dxskinscore::TdxSkinElement* SortGlyphs;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> FilterButtons;
	Dxskinscore::TdxSkinElement* FilterPanel;
	Dxskinscore::TdxSkinElement* SmartFilterButton;
	Dxskinscore::TdxSkinElement* __fastcall CreateBlankElement(Dxskinscore::TdxSkinControlGroup* AGroup, const System::UnicodeString AName);
	Dxskinscore::TdxSkinControlGroup* __fastcall CreateBlankGroup(const System::UnicodeString AName);
	Dxskinscore::TdxSkinBooleanProperty* __fastcall GetBoolPropertyByName(Dxskinscore::TdxSkinPersistent* AElement, const System::UnicodeString AName);
	Dxskinscore::TdxSkinColor* __fastcall GetColorByName(Dxskinscore::TdxSkinPersistent* AElement, const System::UnicodeString AName)/* overload */;
	Dxskinscore::TdxSkinColor* __fastcall GetColorByName(const System::UnicodeString AName)/* overload */;
	System::Uitypes::TColor __fastcall GetColorValueByName(Dxskinscore::TdxSkinPersistent* AElement, const System::UnicodeString AName);
	Dxskinscore::TdxSkinElement* __fastcall GetElementByName(Dxskinscore::TdxSkinControlGroup* AGroup, const System::UnicodeString AName, bool ACreateIfAbsent = true);
	System::Uitypes::TColor __fastcall GetElementColorProperty(Dxskinscore::TdxSkinPersistent* AElement, const System::UnicodeString APropName);
	Dxskinscore::TdxSkinControlGroup* __fastcall GetGroupByName(const System::UnicodeString AName);
	Dxskinscore::TdxSkinIntegerProperty* __fastcall GetIntPropertyByName(Dxskinscore::TdxSkinPersistent* AElement, const System::UnicodeString AName);
	Dxskinscore::TdxSkinProperty* __fastcall GetPropertyByName(Dxskinscore::TdxSkinPersistent* AElement, const System::UnicodeString AName);
	void __fastcall FinalizeScrollBarElements(void);
	void __fastcall InitializeAlertWindowElements(void);
	void __fastcall InitializeBarElements(void);
	void __fastcall InitializeBreadcrumbEditElements(void);
	void __fastcall InitializeButtonElements(void);
	void __fastcall InitializeCalcEditColors(void);
	void __fastcall InitializeCalendarElements(void);
	void __fastcall InitializeCheckboxElements(void);
	void __fastcall InitializeClockElements(void);
	void __fastcall InitializeColors(void);
	void __fastcall InitializeDockControlElements(void);
	void __fastcall InitializeEditButtonElements(void);
	void __fastcall InitializeFilterElements(void);
	void __fastcall InitializeFooterElements(void);
	void __fastcall InitializeFormElements(void);
	void __fastcall InitializeGalleryElements(void);
	void __fastcall InitializeGridElements(void);
	void __fastcall InitializeGroupBoxElements(void);
	void __fastcall InitializeGroups(void);
	void __fastcall InitializeHeaderElements(void);
	void __fastcall InitializeIndicatorImages(void);
	void __fastcall InitializeLayoutViewElements(void);
	void __fastcall InitializeNavBarElements(void);
	void __fastcall InitializeNavigatorElements(void);
	void __fastcall InitializePageControlElements(void);
	void __fastcall InitializePrintingSystemElements(void);
	void __fastcall InitializeProgressBarElements(void);
	void __fastcall InitializeRadioGroupElements(void);
	void __fastcall InitializeRibbonColors(void);
	void __fastcall InitializeRibbonElements(void);
	void __fastcall InitializeRibbonProperties(void);
	void __fastcall InitializeSchedulerElements(void);
	void __fastcall InitializeScrollBarElements(void);
	void __fastcall InitializeSizeGripElements(void);
	void __fastcall InitializeSplitterElements(void);
	void __fastcall InitializeTileControlElements(void);
	void __fastcall InitializeToolTipElements(void);
	void __fastcall InitializeTrackBarElements(void);
	virtual void __fastcall FinalizeSkinInfo(void);
	virtual void __fastcall InitializeSkinInfo(void);
	Dxskinscore::TdxSkin* __fastcall GetSkin(void);
	virtual void __fastcall SkinChanged(Dxskinscore::TdxSkin* Sender);
	
public:
	Dxskinscore::TdxSkinElement* BackButton;
	Dxskinscore::TdxSkinColor* ButtonDisabled;
	Dxskinscore::TdxSkinElement* ButtonElements;
	Dxskinscore::TdxSkinColor* ContainerBorderColor;
	Dxskinscore::TdxSkinColor* ContainerHighlightBorderColor;
	Dxskinscore::TdxSkinColor* ContentColor;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 4> EditorBackgroundColors;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 4> EditorTextColors;
	Dxskinscore::TdxSkinColor* HyperLinkTextColor;
	Dxskinscore::TdxSkinColor* InactiveColor;
	Dxskinscore::TdxSkinColor* InactiveTextColor;
	System::StaticArray<System::StaticArray<Dxskinscore::TdxSkinElement*, 2>, 2> ProgressBarElements;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 2> ProgressBarTextColors;
	System::StaticArray<System::StaticArray<TdxSkinScrollInfo*, 6>, 2> ScrollBar_Elements;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> LabelLine;
	Dxskinscore::TdxSkinColor* BevelShapeColor1;
	Dxskinscore::TdxSkinColor* BevelShapeColor2;
	Dxskinscore::TdxSkinElement* AlertWindow;
	Dxskinscore::TdxSkinElement* AlertWindowButton;
	Dxskinscore::TdxSkinElement* AlertWindowButtonGlyphs;
	Dxskinscore::TdxSkinElement* AlertWindowCaption;
	int AlertWindowCornerRadius;
	Dxskinscore::TdxSkinElement* AlertWindowNavigationPanel;
	Dxskinscore::TdxSkinElement* AlertWindowNavigationPanelButton;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 4> BreadcrumbEditBackgroundColors;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 4> BreadcrumbEditBordersColors;
	Dxskinscore::TdxSkinElement* BreadcrumbEditButton;
	bool BreadcrumbEditButtonMergeBorders;
	Dxskinscore::TdxSkinElement* BreadcrumbEditButtonsAreaSeparator;
	Dxskinscore::TdxSkinElement* BreadcrumbEditDropDownButton;
	Dxskinscore::TdxSkinElement* BreadcrumbEditNodeButton;
	Dxskinscore::TdxSkinElement* BreadcrumbEditNodeSplitButtonLeft;
	Dxskinscore::TdxSkinElement* BreadcrumbEditNodeSplitButtonRight;
	Dxskinscore::TdxSkinElement* BreadcrumbEditProgressChunk;
	Dxskinscore::TdxSkinElement* BreadcrumbEditProgressChunkOverlay;
	Dxskinscore::TdxSkinRectProperty* BreadcrumbEditProgressChunkPadding;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 5> GroupBoxCaptionElements;
	System::StaticArray<Dxskinscore::TdxSkinIntegerProperty*, 5> GroupBoxCaptionTailSizes;
	System::StaticArray<Dxskinscore::TdxSkinIntegerProperty*, 5> GroupBoxCaptionTextPadding;
	Dxskinscore::TdxSkinElement* GroupBoxClient;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 5> GroupBoxElements;
	Dxskinscore::TdxSkinElement* GroupExpandButton;
	Dxskinscore::TdxSkinElement* DockControlBorder;
	Dxskinscore::TdxSkinElement* DockControlCaption;
	System::Uitypes::TColor DockControlCaptionNonFocusedTextColor;
	Dxskinscore::TdxSkinElement* DockControlHideBar;
	Dxskinscore::TdxSkinElement* DockControlHideBarLeft;
	Dxskinscore::TdxSkinElement* DockControlHideBarRight;
	Dxskinscore::TdxSkinElement* DockControlHideBarBottom;
	Dxskinscore::TdxSkinElement* DockControlHideBarButtons;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 2> DockControlHideBarTextColor;
	System::StaticArray<int, 3> DockControlIndents;
	Dxskinscore::TdxSkinElement* DockControlTabHeader;
	Dxskinscore::TdxSkinElement* DockControlTabButtonHorz;
	Dxskinscore::TdxSkinElement* DockControlTabButtonVert;
	Dxskinscore::TdxSkinElement* DockControlTabHeaderBackground;
	Dxskinscore::TdxSkinElement* DockControlTabHeaderCloseButton;
	Dxskinscore::TdxSkinElement* DockControlTabHeaderLine;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 2> DockControlTabTextColor;
	Dxskinscore::TdxSkinElement* DockControlWindowButton;
	Dxskinscore::TdxSkinElement* DockControlWindowButtonGlyphs;
	Dxskinscore::TdxSkinColor* LayoutControlColor;
	System::StaticArray<Dxskinscore::TdxSkinRectProperty*, 6> LayoutViewElementPadding;
	System::StaticArray<Dxskinscore::TdxSkinRectProperty*, 6> LayoutViewElementSpacing;
	Dxskinscore::TdxSkinElement* LayoutViewItem;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 5> LayoutViewRecordCaptionElements;
	System::StaticArray<Dxskinscore::TdxSkinIntegerProperty*, 5> LayoutViewRecordCaptionTailSizes;
	System::StaticArray<Dxskinscore::TdxSkinIntegerProperty*, 5> LayoutViewRecordCaptionTextPadding;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 5> LayoutViewRecordElements;
	Dxskinscore::TdxSkinElement* LayoutViewRecordExpandButton;
	Dxskinscore::TdxSkinElement* PageControlButton;
	Dxskinscore::TdxSkinElement* PageControlButtonHorz;
	Dxskinscore::TdxSkinElement* PageControlButtonVert;
	Dxskinscore::TdxSkinElement* PageControlCloseButton;
	Dxskinscore::TdxSkinElement* PageControlHeader;
	Dxskinscore::TdxSkinElement* PageControlHeaderButton;
	System::StaticArray<int, 8> PageControlIndents;
	Dxskinscore::TdxSkinElement* PageControlPane;
	Dxskinscore::TdxSkinColor* TabTextColor;
	Dxskinscore::TdxSkinColor* TabTextColorActive;
	Dxskinscore::TdxSkinColor* TabTextColorDisabled;
	Dxskinscore::TdxSkinColor* TabTextColorHot;
	Dxskinscore::TdxSkinElement* NavBarBackgroundColor;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> NavBarGroupButtons;
	Dxskinscore::TdxSkinElement* NavBarGroupClient;
	Dxskinscore::TdxSkinElement* NavBarGroupHeader;
	Dxskinscore::TdxSkinElement* NavBarItem;
	Dxskinscore::TdxSkinIntegerProperty* NavPaneCaptionFontSize;
	Dxskinscore::TdxSkinIntegerProperty* NavPaneCaptionHeight;
	Dxskinscore::TdxSkinElement* NavPaneCollapseButton;
	Dxskinscore::TdxSkinElement* NavPaneCollapsedGroupClient;
	Dxskinscore::TdxSkinElement* NavPaneExpandButton;
	Dxskinscore::TdxSkinElement* NavPaneFormBorder;
	Dxskinscore::TdxSkinElement* NavPaneFormSizeGrip;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> NavPaneGroupButton;
	Dxskinscore::TdxSkinElement* NavPaneGroupCaption;
	Dxskinscore::TdxSkinElement* NavPaneGroupClient;
	Dxskinscore::TdxSkinElement* NavPaneItem;
	Dxskinscore::TdxSkinBooleanProperty* NavPaneOffsetGroupBorders;
	Dxskinscore::TdxSkinElement* NavPaneOverflowPanel;
	Dxskinscore::TdxSkinElement* NavPaneOverflowPanelExpandedItem;
	Dxskinscore::TdxSkinElement* NavPaneOverflowPanelItem;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> NavPaneScrollButtons;
	Dxskinscore::TdxSkinElement* NavPaneSelectedItem;
	Dxskinscore::TdxSkinElement* NavPaneSplitter;
	System::StaticArray<System::Types::TRect, 2> FormBorderWidths;
	int FormCaptionDelta;
	Dxskinscore::TdxSkinElement* FormContent;
	System::StaticArray<System::StaticArray<Dxskinscore::TdxSkinElement*, 4>, 2> FormFrames;
	System::StaticArray<System::StaticArray<Dxskinscore::TdxSkinElement*, 6>, 2> FormIcons;
	Dxskinscore::TdxSkinColor* FormInactiveColor;
	Dxskinscore::TdxSkinElement* FormStatusBar;
	Dxskinscore::TdxSkinColor* FormTextShadowColor;
	Dxskinscore::TdxSkinElement* SizeGrip;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> SchedulerAllDayArea;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> SchedulerAppointment;
	Dxskinscore::TdxSkinColor* SchedulerAppointmentBorder;
	Dxskinscore::TdxSkinIntegerProperty* SchedulerAppointmentBorderSize;
	Dxskinscore::TdxSkinElement* SchedulerAppointmentMask;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> SchedulerAppointmentShadow;
	Dxskinscore::TdxSkinElement* SchedulerCurrentTimeIndicator;
	Dxskinscore::TdxSkinElement* SchedulerGroup;
	Dxskinscore::TdxSkinElement* SchedulerMilestone;
	Dxskinscore::TdxSkinElement* SchedulerMoreButton;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> SchedulerNavigationButtons;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> SchedulerNavigationButtonsArrow;
	Dxskinscore::TdxSkinColor* SchedulerNavigatorColor;
	System::StaticArray<Dxskinscore::TdxSkinColor*, 12> SchedulerResourceColors;
	Dxskinscore::TdxSkinElement* SchedulerTimeGridCurrentTimeIndicator;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> SchedulerTimeGridHeader;
	Dxskinscore::TdxSkinElement* SchedulerTimeLine;
	Dxskinscore::TdxSkinElement* SchedulerTimeRuler;
	Dxskinscore::TdxSkinElement* Bar;
	Dxskinscore::TdxSkinElement* BarCustomize;
	Dxskinscore::TdxSkinElement* BarCustomizeVertical;
	Dxskinscore::TdxSkinColor* BarDisabledTextColor;
	Dxskinscore::TdxSkinElement* BarDrag;
	Dxskinscore::TdxSkinElement* BarDragVertical;
	Dxskinscore::TdxSkinElement* BarMDIButtonClose;
	Dxskinscore::TdxSkinElement* BarMDIButtonMinimize;
	Dxskinscore::TdxSkinElement* BarMDIButtonRestore;
	Dxskinscore::TdxSkinElement* BarSeparator;
	Dxskinscore::TdxSkinElement* BarVertical;
	Dxskinscore::TdxSkinElement* BarVerticalSeparator;
	Dxskinscore::TdxSkinElement* Dock;
	Dxskinscore::TdxSkinElement* FloatingBar;
	Dxskinscore::TdxSkinElement* ItemSeparator;
	Dxskinscore::TdxSkinElement* LinkBorderPainter;
	Dxskinscore::TdxSkinElement* LinkSelected;
	Dxskinscore::TdxSkinElement* MainMenu;
	Dxskinscore::TdxSkinElement* MainMenuCustomize;
	Dxskinscore::TdxSkinElement* MainMenuDrag;
	Dxskinscore::TdxSkinElement* MainMenuLinkSelected;
	Dxskinscore::TdxSkinElement* MainMenuVertical;
	Dxskinscore::TdxSkinElement* PopupMenu;
	Dxskinscore::TdxSkinElement* PopupMenuCheck;
	Dxskinscore::TdxSkinElement* PopupMenuExpandButton;
	Dxskinscore::TdxSkinElement* PopupMenuLinkSelected;
	Dxskinscore::TdxSkinElement* PopupMenuSeparator;
	Dxskinscore::TdxSkinElement* PopupMenuSideStrip;
	Dxskinscore::TdxSkinElement* PopupMenuSideStripNonRecent;
	Dxskinscore::TdxSkinElement* PopupMenuSplitButton;
	Dxskinscore::TdxSkinElement* PopupMenuSplitButton2;
	Dxskinscore::TdxSkinColor* ScreenTipItem;
	Dxskinscore::TdxSkinElement* ScreenTipSeparator;
	Dxskinscore::TdxSkinColor* ScreenTipTitleItem;
	Dxskinscore::TdxSkinElement* ScreenTipWindow;
	Dxskinscore::TdxSkinColor* RadialMenuBackgroundColor;
	Dxskinscore::TdxSkinColor* RadialMenuBaseColor;
	Dxskinscore::TdxSkinElement* RibbonApplicationBackground;
	Dxskinscore::TdxSkinElement* RibbonApplicationButton;
	Dxskinscore::TdxSkinElement* RibbonApplicationButton2010;
	Dxskinscore::TdxSkinElement* RibbonApplicationFooterBackground;
	Dxskinscore::TdxSkinElement* RibbonApplicationHeaderBackground;
	Dxskinscore::TdxSkinElement* RibbonBackstageView;
	Dxskinscore::TdxSkinElement* RibbonBackstageViewBackButton;
	Dxskinscore::TdxSkinElement* RibbonBackstageViewImage;
	Dxskinscore::TdxSkinElement* RibbonBackstageViewMenu;
	Dxskinscore::TdxSkinElement* RibbonBackstageViewMenuButton;
	Dxskinscore::TdxSkinElement* RibbonBackstageViewMenuHeader;
	Dxskinscore::TdxSkinElement* RibbonBackstageViewMenuSeparator;
	Dxskinscore::TdxSkinElement* RibbonBackstageViewTab;
	Dxskinscore::TdxSkinElement* RibbonBackstageViewTabArrow;
	Dxskinscore::TdxSkinElement* RibbonButtonArrow;
	Dxskinscore::TdxSkinElement* RibbonButtonGroup;
	Dxskinscore::TdxSkinElement* RibbonButtonGroupButton;
	Dxskinscore::TdxSkinElement* RibbonButtonGroupSeparator;
	Dxskinscore::TdxSkinElement* RibbonButtonGroupSplitButtonLeft;
	Dxskinscore::TdxSkinElement* RibbonButtonGroupSplitButtonRight;
	System::StaticArray<System::Uitypes::TColor, 2> RibbonButtonText;
	Dxskinscore::TdxSkinIntegerProperty* RibbonCaptionFontDelta;
	System::StaticArray<System::Uitypes::TColor, 2> RibbonCaptionText;
	Dxskinscore::TdxSkinElement* RibbonCollapsedToolBarBackground;
	Dxskinscore::TdxSkinElement* RibbonCollapsedToolBarGlyphBackground;
	Dxskinscore::TdxSkinElement* RibbonContextualTabHeader;
	System::StaticArray<System::Uitypes::TColor, 2> RibbonContextualTabHeaderText;
	System::Uitypes::TColor RibbonContextualTabHeaderTextHot;
	Dxskinscore::TdxSkinElement* RibbonContextualTabLabel;
	Dxskinscore::TdxSkinElement* RibbonContextualTabLabelOnGlass;
	Dxskinscore::TdxSkinColor* RibbonContextualTabLabelOnGlassShadowColor;
	Dxskinscore::TdxSkinColor* RibbonContextualTabLabelShadowColor;
	Dxskinscore::TdxSkinElement* RibbonContextualTabPanel;
	Dxskinscore::TdxSkinElement* RibbonContextualTabSeparator;
	System::StaticArray<System::Uitypes::TColor, 2> RibbonDocumentNameTextColor;
	Dxskinscore::TdxSkinColor* RibbonEditorBackground;
	Dxskinscore::TdxSkinElement* RibbonExtraPaneButton;
	Dxskinscore::TdxSkinColor* RibbonExtraPaneColor;
	Dxskinscore::TdxSkinColor* RibbonExtraPaneHeaderSeparator;
	Dxskinscore::TdxSkinElement* RibbonExtraPanePinButtonGlyph;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> RibbonFormBottom;
	Dxskinscore::TdxSkinElement* RibbonFormButtonAutoHideMode;
	Dxskinscore::TdxSkinElement* RibbonFormButtonAutoHideModeShowUI;
	Dxskinscore::TdxSkinElement* RibbonFormCaption;
	Dxskinscore::TdxSkinElement* RibbonFormCaptionRibbonHidden;
	Dxskinscore::TdxSkinElement* RibbonFormContent;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> RibbonFormLeft;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> RibbonFormRight;
	Dxskinscore::TdxSkinElement* RibbonGalleryBackground;
	Dxskinscore::TdxSkinElement* RibbonGalleryButtonDown;
	Dxskinscore::TdxSkinElement* RibbonGalleryButtonDropDown;
	Dxskinscore::TdxSkinElement* RibbonGalleryButtonUp;
	Dxskinscore::TdxSkinElement* RibbonGalleryGroupCaption;
	Dxskinscore::TdxSkinElement* RibbonGalleryPane;
	Dxskinscore::TdxSkinElement* RibbonGallerySizeGrips;
	Dxskinscore::TdxSkinElement* RibbonGallerySizingPanel;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> RibbonGroupScroll;
	Dxskinscore::TdxSkinElement* RibbonHeaderBackground;
	Dxskinscore::TdxSkinElement* RibbonHeaderBackgroundOnGlass;
	Dxskinscore::TdxSkinElement* RibbonKeyTip;
	Dxskinscore::TdxSkinElement* RibbonLargeButton;
	Dxskinscore::TdxSkinElement* RibbonLargeSplitButtonBottom;
	Dxskinscore::TdxSkinElement* RibbonLargeSplitButtonTop;
	Dxskinscore::TdxSkinElement* RibbonMinimizeButtonGlyph;
	System::StaticArray<Dxskinscore::TdxSkinBooleanProperty*, 2> RibbonQATCustomizeButtonOutsizeQAT;
	System::StaticArray<Dxskinscore::TdxSkinIntegerProperty*, 2> RibbonQATIndentBeforeCustomizeButton;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 2> RibbonQuickToolbar;
	Dxskinscore::TdxSkinElement* RibbonQuickToolbarBelow;
	Dxskinscore::TdxSkinElement* RibbonQuickToolbarButtonGlyph;
	Dxskinscore::TdxSkinElement* RibbonQuickToolbarDropDown;
	Dxskinscore::TdxSkinElement* RibbonQuickToolbarGlyph;
	Dxskinscore::TdxSkinElement* RibbonSmallButton;
	Dxskinscore::TdxSkinIntegerProperty* RibbonSpaceBetweenTabGroups;
	Dxskinscore::TdxSkinElement* RibbonSplitButtonLeft;
	Dxskinscore::TdxSkinElement* RibbonSplitButtonRight;
	Dxskinscore::TdxSkinElement* RibbonStatusBarBackground;
	Dxskinscore::TdxSkinElement* RibbonStatusBarButton;
	Dxskinscore::TdxSkinElement* RibbonStatusBarSeparator;
	System::Uitypes::TColor RibbonStatusBarTextSelected;
	Dxskinscore::TdxSkinElement* RibbonTab;
	Dxskinscore::TdxSkinBooleanProperty* RibbonTabAeroSupport;
	Dxskinscore::TdxSkinElement* RibbonTabGroup;
	Dxskinscore::TdxSkinElement* RibbonTabGroupHeader;
	Dxskinscore::TdxSkinElement* RibbonTabGroupItemsSeparator;
	Dxskinscore::TdxSkinIntegerProperty* RibbonTabHeaderDownGrowIndent;
	Dxskinscore::TdxSkinElement* RibbonTabPanel;
	Dxskinscore::TdxSkinIntegerProperty* RibbonTabPanelBottomIndent;
	Dxskinscore::TdxSkinElement* RibbonTabPanelGroupButton;
	Dxskinscore::TdxSkinElement* RibbonTabSeparatorLine;
	System::StaticArray<System::Uitypes::TColor, 2> RibbonTabText;
	System::Uitypes::TColor RibbonTabTextHot;
	Dxskinscore::TdxSkinBooleanProperty* RibbonUseRoundedWindowCorners;
	Dxskinscore::TdxSkinColor* CalendarDayTextColor;
	Dxskinscore::TdxSkinColor* CalendarHolidayTextColor;
	Dxskinscore::TdxSkinColor* CalendarInactiveDayTextColor;
	Dxskinscore::TdxSkinColor* CalendarSelectedDayColor;
	Dxskinscore::TdxSkinColor* CalendarSelectedDayTextColor;
	Dxskinscore::TdxSkinColor* CalendarSeparatorColor;
	Dxskinscore::TdxSkinColor* CalendarTodayFrameColor;
	Dxskinscore::TdxSkinColor* CalendarTodayTextColor;
	Dxskinscore::TdxSkinElement* PrintingPageBorder;
	Dxskinscore::TdxSkinElement* PrintingPreviewBackground;
	Dxskinscore::TdxSkinElement* GalleryBackground;
	Dxskinscore::TdxSkinElement* GalleryGroup;
	Dxskinscore::TdxSkinElement* GalleryItem;
	Dxskinscore::TdxSkinElement* GalleryItemGlyphFrame;
	Dxskinscore::TdxSkinElement* ZoomInButton;
	Dxskinscore::TdxSkinElement* ZoomOutButton;
	System::StaticArray<Dxskinscore::TdxSkinElement*, 4> SliderArrow;
	Dxskinscore::TdxSkinElement* TileControlActionBar;
	Dxskinscore::TdxSkinElement* TileControlBackground;
	Dxskinscore::TdxSkinElement* TileControlItem;
	Dxskinscore::TdxSkinElement* TileControlItemCheck;
	Dxskinscore::TdxSkinElement* TileControlGroupCaption;
	int TileControlGroupCaptionFontDelta;
	System::Uitypes::TColor TileControlSelectionFocusedColor;
	System::Uitypes::TColor TileControlSelectionHotColor;
	Dxskinscore::TdxSkinElement* TileControlTabHeader;
	int TileControlTabHeaderFontDelta;
	Dxskinscore::TdxSkinElement* TileControlTitle;
	int TileControlTitleFontDelta;
	Dxskinscore::TdxSkinElement* TileControlVirtualGroup;
	__fastcall virtual TdxSkinInfo(Dxskinscore::TdxSkin* ASkin)/* overload */;
	__fastcall virtual ~TdxSkinInfo(void);
	int __fastcall GetIntegerPropertyValue(Dxskinscore::TdxSkinPersistent* AObject, const System::UnicodeString APropertyName, int ADefaultValue = 0x0);
	__property Dxskinscore::TdxSkin* Skin = {read=FSkin, write=SetSkin};
private:
	void *__IdxSkinInfo;	/* Dxskinscore::IdxSkinInfo */
	void *__IdxSkinChangeListener;	/* Dxskinscore::IdxSkinChangeListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {97D85495-E631-413C-8DBC-BE7B784A9EA0}
	operator Dxskinscore::_di_IdxSkinInfo()
	{
		Dxskinscore::_di_IdxSkinInfo intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxskinscore::IdxSkinInfo*(void) { return (Dxskinscore::IdxSkinInfo*)&__IdxSkinInfo; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {28681774-0475-43AE-8704-1C904D294742}
	operator Dxskinscore::_di_IdxSkinChangeListener()
	{
		Dxskinscore::_di_IdxSkinChangeListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxskinscore::IdxSkinChangeListener*(void) { return (Dxskinscore::IdxSkinChangeListener*)&__IdxSkinChangeListener; }
	#endif
	
};


typedef System::TMetaClass* TdxSkinInfoClass;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxSkinsSchedulerResourceColorsCount = System::Int8(0xc);
}	/* namespace Dxskininfo */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKININFO)
using namespace Dxskininfo;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskininfoHPP
