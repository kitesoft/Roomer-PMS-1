// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBar.pas' rev: 24.00 (Win64)

#ifndef DxnavbarHPP
#define DxnavbarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <cxLibraryConsts.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarConsts.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbar
{
//-- type declarations -------------------------------------------------------
enum TdxNavBarDragDropFlag : unsigned char { fAllowDragLink, fAllowDropLink, fAllowDragGroup, fAllowDropGroup };

typedef System::Set<TdxNavBarDragDropFlag, TdxNavBarDragDropFlag::fAllowDragLink, TdxNavBarDragDropFlag::fAllowDropGroup>  TdxNavBarDragDropFlags;

enum TdxNavBarObjectState : unsigned char { sActive, sDisabled, sExpanded, sHotTracked, sPressed, sSelected, sSpecial, sFocused };

typedef System::Set<TdxNavBarObjectState, TdxNavBarObjectState::sActive, TdxNavBarObjectState::sFocused>  TdxNavBarObjectStates;

enum TdxNavBarChildKind : unsigned char { nbckGroup, nbckItem, nbckStyle, nbckGroupControl };

enum TdxNavBarViewCategory : unsigned char { nbvcExplorerBar, nbvcSideBar };

typedef System::Set<TdxNavBarViewCategory, TdxNavBarViewCategory::nbvcExplorerBar, TdxNavBarViewCategory::nbvcSideBar>  TdxNavBarViewCategories;

typedef System::TMetaClass* TdxNavBarControllerClass;

class DELPHICLASS TdxNavBarPersistent;
class DELPHICLASS TdxCustomNavBar;
class PASCALIMPLEMENTATION TdxNavBarPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxCustomNavBar* FNavBar;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TdxNavBarPersistent(TdxCustomNavBar* ANavBar);
	__property TdxCustomNavBar* NavBar = {read=FNavBar};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarPersistent(void) { }
	
};


class DELPHICLASS TdxNavBarCustomViewInfo;
class DELPHICLASS TdxNavBarPainter;
class PASCALIMPLEMENTATION TdxNavBarCustomViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TdxCustomNavBar* FNavBar;
	TdxNavBarPainter* FPainter;
	double FRatio;
	__property double Ratio = {read=FRatio};
	int __fastcall GetRevisedValue(int AValue);
	
public:
	__fastcall TdxNavBarCustomViewInfo(void);
	__property TdxCustomNavBar* NavBar = {read=FNavBar};
	__property TdxNavBarPainter* Painter = {read=FPainter};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarCustomItemViewInfo;
class DELPHICLASS TdxNavBarViewInfo;
class PASCALIMPLEMENTATION TdxNavBarCustomItemViewInfo : public TdxNavBarCustomViewInfo
{
	typedef TdxNavBarCustomViewInfo inherited;
	
protected:
	Vcl::Graphics::TFont* FCaptionFont;
	System::Types::TRect FCaptionRect;
	bool FCaptionVisible;
	System::Types::TRect FDesignRect;
	System::Types::TRect FImageRect;
	bool FImageVisible;
	System::Types::TRect FFocusRect;
	System::Types::TRect FRect;
	TdxNavBarViewInfo* FViewInfo;
	void __fastcall CalcDesignRect(const System::Types::TRect &AItemRect, int AMarkSize);
	virtual Dxnavbarcollns::TdxNavBarCustomItem* __fastcall GetNavBarItem(void) = 0 ;
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImageList(void);
	virtual TdxNavBarObjectStates __fastcall GetState(void);
	bool __fastcall IsEnabled(void);
	bool __fastcall IsFocused(void);
	bool __fastcall IsSelected(void);
	virtual bool __fastcall UseDisabledImages(void);
	virtual bool __fastcall UseHotImages(void);
	virtual bool __fastcall UseLargeImages(void);
	
public:
	__fastcall TdxNavBarCustomItemViewInfo(TdxNavBarViewInfo* AViewInfo);
	__fastcall virtual ~TdxNavBarCustomItemViewInfo(void);
	virtual void __fastcall CorrectBounds(int dX, int dY);
	virtual int __fastcall ImageIndex(void);
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property System::Types::TRect DesignRect = {read=FDesignRect};
	__property System::Types::TRect ImageRect = {read=FImageRect};
	__property System::Types::TRect FocusRect = {read=FFocusRect};
	__property System::Types::TRect Rect = {read=FRect};
	__property Vcl::Imglist::TCustomImageList* ImageList = {read=GetImageList};
	__property TdxNavBarObjectStates State = {read=GetState, nodefault};
	__property TdxNavBarViewInfo* ViewInfo = {read=FViewInfo};
};


class DELPHICLASS TdxNavBarLinkViewInfo;
class DELPHICLASS TdxNavBarGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarLinkViewInfo : public TdxNavBarCustomItemViewInfo
{
	typedef TdxNavBarCustomItemViewInfo inherited;
	
private:
	TdxNavBarGroupViewInfo* FGroupViewInfo;
	Dxnavbarcollns::TdxNavBarItemLink* FLink;
	Dxnavbarcollns::TdxNavBarItem* FItem;
	
protected:
	virtual Dxnavbarcollns::TdxNavBarCustomItem* __fastcall GetNavBarItem(void);
	virtual TdxNavBarObjectStates __fastcall GetState(void);
	
public:
	__fastcall TdxNavBarLinkViewInfo(TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble);
	virtual void __fastcall CalculateBounds(int X, int Y);
	virtual int __fastcall GetCaptionHeight(void);
	virtual int __fastcall GetDrawEdgeFlag(void);
	virtual int __fastcall GetImageHeight(void);
	virtual int __fastcall GetImageWidth(void);
	bool __fastcall IsCaptionVisible(void);
	bool __fastcall IsImageVisible(void);
	bool __fastcall IsWholeVisible(void);
	virtual bool __fastcall UseLargeImages(void);
	virtual Dxnavbarstyles::TdxNavBarStyleItem* __fastcall StyleItem(void);
	virtual Dxnavbarstyles::TdxNavBarBaseStyle* __fastcall Style(void);
	virtual Vcl::Graphics::TFont* __fastcall Font(void);
	virtual System::Uitypes::TColor __fastcall FontColor(void);
	virtual System::Uitypes::TColor __fastcall SeparatorColor(void);
	virtual System::Types::TRect __fastcall SelectionRect(void);
	virtual System::Types::TRect __fastcall SeparatorRect(void);
	__property Dxnavbarcollns::TdxNavBarItemLink* Link = {read=FLink};
	__property Dxnavbarcollns::TdxNavBarItem* Item = {read=FItem};
	__property TdxNavBarGroupViewInfo* GroupViewInfo = {read=FGroupViewInfo};
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarLinkViewInfo(void) { }
	
};


typedef System::TMetaClass* TdxNavBarLinkViewInfoClass;

class PASCALIMPLEMENTATION TdxNavBarGroupViewInfo : public TdxNavBarCustomItemViewInfo
{
	typedef TdxNavBarCustomItemViewInfo inherited;
	
private:
	System::Classes::TList* FItems;
	Dxnavbarcollns::TdxNavBarGroup* FGroup;
	bool FItemsVisible;
	Dxnavbarcollns::TdxNavBarGroupControl* __fastcall GetControl(void);
	System::Uitypes::TColor __fastcall GetControlBackColor(void);
	System::Uitypes::TColor __fastcall GetControlBackColor2(void);
	int __fastcall GetItemCount(void);
	TdxNavBarLinkViewInfo* __fastcall GetItem(int Index);
	bool __fastcall IsDefaultControlStyle(void);
	
protected:
	System::Types::TRect FCaptionSignRect;
	System::Types::TRect FCaptionTextRect;
	System::Types::TRect FItemsRect;
	void __fastcall AddLink(TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble);
	void __fastcall ClearItems(void);
	virtual void __fastcall DoCreateItemsInfo(void);
	System::Types::TRect __fastcall GetBorderOffsets(void);
	virtual System::Types::TRect __fastcall GetControlRect(void);
	virtual int __fastcall GetImageIndent(void);
	virtual void __fastcall AdjustControlBounds(void);
	virtual Dxnavbarcollns::TdxNavBarCustomItem* __fastcall GetNavBarItem(void);
	virtual TdxNavBarObjectStates __fastcall GetState(void);
	bool __fastcall HasEnoughSpaceForScrollButtons(void);
	
public:
	__fastcall TdxNavBarGroupViewInfo(TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible);
	__fastcall virtual ~TdxNavBarGroupViewInfo(void);
	virtual void __fastcall CreateInfo(void);
	void __fastcall CreateItemsInfo(void);
	virtual void __fastcall CalculateBounds(int &X, int &Y);
	virtual void __fastcall CorrectBounds(int dX, int dY);
	virtual void __fastcall CorrectActiveGroupBounds(int dX, int dY);
	TdxNavBarLinkViewInfo* __fastcall GetLinkViewInfoByLink(Dxnavbarcollns::TdxNavBarItemLink* ALink);
	int __fastcall IndexOfLinkViewInfo(TdxNavBarLinkViewInfo* AViewInfo);
	virtual int __fastcall GetCaptionHeight(void);
	virtual int __fastcall GetDrawEdgeFlag(void);
	virtual int __fastcall GetImageHeight(void);
	virtual int __fastcall GetImageWidth(void);
	bool __fastcall IsCaptionVisible(void);
	bool __fastcall IsCaptionImageVisible(void);
	bool __fastcall IsCaptionSignVisible(void);
	bool __fastcall IsCaptionUseSmallImages(void);
	bool __fastcall IsItemsVisible(void);
	bool __fastcall IsLinksUseSmallImages(void);
	bool __fastcall IsViewAsIconView(void);
	virtual System::Uitypes::TColor __fastcall BorderColor(void);
	virtual Vcl::Graphics::TPicture* __fastcall BgImage(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor2(void);
	virtual System::Byte __fastcall BgAlphaBlend(void);
	virtual System::Byte __fastcall BgAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall BgGradientMode(void);
	virtual Dxnavbarstyles::TdxNavBarStyleItem* __fastcall CaptionStyleItem(void);
	virtual Dxnavbarstyles::TdxNavBarBaseStyle* __fastcall CaptionStyle(void);
	virtual Vcl::Graphics::TPicture* __fastcall CaptionImage(void);
	virtual System::Uitypes::TColor __fastcall CaptionBorderColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor2(void);
	virtual System::Byte __fastcall CaptionAlphaBlend(void);
	virtual System::Byte __fastcall CaptionAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall CaptionGradientMode(void);
	virtual Vcl::Graphics::TFont* __fastcall CaptionFont(void);
	virtual System::Uitypes::TColor __fastcall CaptionFontColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionSignColor(void);
	virtual Dxnavbarstyles::TdxBarStyleHAlignment __fastcall CaptionHAlignment(void);
	virtual Dxnavbarstyles::TdxBarStyleVAlignment __fastcall CaptionVAlignment(void);
	virtual Vcl::Graphics::TPicture* __fastcall ControlImage(void);
	virtual System::Uitypes::TColor __fastcall ControlBackColor(void);
	virtual System::Uitypes::TColor __fastcall ControlBackColor2(void);
	virtual System::Byte __fastcall ControlAlphaBlend(void);
	virtual System::Byte __fastcall ControlAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall ControlGradientMode(void);
	virtual bool __fastcall UseLargeImages(void);
	__property System::Types::TRect CaptionImageRect = {read=FImageRect};
	__property System::Types::TRect CaptionSignRect = {read=FCaptionSignRect};
	__property System::Types::TRect CaptionTextRect = {read=FCaptionTextRect};
	__property System::Types::TRect ControlRect = {read=GetControlRect};
	__property System::Types::TRect ItemsRect = {read=FItemsRect};
	__property Dxnavbarcollns::TdxNavBarGroupControl* Control = {read=GetControl};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxNavBarLinkViewInfo* Items[int Index] = {read=GetItem};
	__property Dxnavbarcollns::TdxNavBarGroup* Group = {read=FGroup};
};


typedef System::TMetaClass* TdxNavBarGroupViewInfoClass;

typedef void __fastcall (__closure *TdxNavBarCalcHintEvent)(System::TObject* AItem, System::Types::TRect &ARect);

class PASCALIMPLEMENTATION TdxNavBarViewInfo : public TdxNavBarCustomViewInfo
{
	typedef TdxNavBarCustomViewInfo inherited;
	
private:
	System::Contnrs::TObjectList* FGroups;
	Vcl::Graphics::TFont* FHeaderFont;
	System::Types::TRect FTopScrollButtonRect;
	System::Types::TRect FBottomScrollButtonRect;
	System::Types::TRect FHintRect;
	System::UnicodeString FHintText;
	int __fastcall GetGroupCount(void);
	TdxNavBarGroupViewInfo* __fastcall GetGroup(int Index);
	TdxNavBarObjectStates __fastcall GetBottomScrollButtonState(void);
	TdxNavBarObjectStates __fastcall GetTopScrollButtonState(void);
	
protected:
	virtual void __fastcall CreateColors(void);
	virtual void __fastcall RefreshColors(void);
	virtual void __fastcall ReleaseColors(void);
	int __fastcall ClientHeight(void);
	int __fastcall ClientWidth(void);
	int __fastcall GetSpaceBetweenGroups(void);
	int __fastcall GetLargeImageHeight(void);
	int __fastcall GetLargeImageWidth(void);
	int __fastcall GetSmallImageHeight(void);
	int __fastcall GetSmallImageWidth(void);
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	__classmethod virtual int __fastcall GetGroupCaptionTextIndent();
	__classmethod virtual int __fastcall GetGroupCaptionImageIndent();
	virtual System::Types::TRect __fastcall GetGroupCaptionImageOffsets(void);
	virtual int __fastcall GetGroupSeparatorWidth(void);
	virtual System::Types::TSize __fastcall GetGroupCaptionSignSize(void);
	virtual System::Types::TPoint __fastcall GetGroupEdges(void);
	__classmethod virtual int __fastcall GetGroupCaptionSeparatorWidth();
	__classmethod virtual int __fastcall GetLinksLargeSeparatorWidth();
	__classmethod virtual int __fastcall GetLinksSmallSeparatorWidth();
	__classmethod virtual int __fastcall GetLinksIconViewSeparatorWidth();
	virtual System::Types::TRect __fastcall GetLinksImageEdges(void);
	__classmethod virtual int __fastcall GetDragArrowHeight();
	__classmethod virtual int __fastcall GetDragArrowWidth();
	virtual int __fastcall GetHeaderHeightAddon(void);
	virtual int __fastcall GetNavBarCollapsedWidth(void);
	virtual int __fastcall GetNavBarMinExpandedWidth(void);
	__classmethod virtual int __fastcall GetScrollButtonVerticalEdge();
	__classmethod virtual int __fastcall GetScrollButtonHorizontalEdge();
	__classmethod virtual int __fastcall GetScrollButtonVerticalSize();
	__classmethod virtual int __fastcall GetScrollButtonHorizontalSize();
	virtual bool __fastcall CanCollapse(void);
	virtual bool __fastcall CanHasActiveGroup(void);
	virtual bool __fastcall CanHasSpecialGroup(void);
	virtual bool __fastcall CanHasScrollButtonInGroupCaption(void);
	virtual bool __fastcall CanHasImageInGroupCaption(void);
	virtual bool __fastcall CanHasSignInGroupCaption(void);
	virtual bool __fastcall CanHasGroupViewAsIconView(void);
	virtual bool __fastcall CanHasGroupWithNoCaption(void);
	virtual bool __fastcall CanHasVisibleItemsInGroup(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual bool __fastcall CanGroupCaptionBoundsByImage(void);
	virtual bool __fastcall CanGroupsUseLargeImages(void);
	virtual bool __fastcall CanLinksUseLargeImages(void);
	virtual bool __fastcall CanSelectLinkByRect(void);
	void __fastcall AddGroup(TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible);
	void __fastcall RemoveGroup(TdxNavBarGroupViewInfo* AGroupViewInfo);
	void __fastcall ClearGroups(void);
	virtual void __fastcall AdjustControlsBounds(void);
	virtual void __fastcall CorrectBounds(void);
	virtual Dxnavbarbase::TdxNavBarChangeType __fastcall GetBoundsUpdateType(void);
	virtual System::Types::TRect __fastcall GetTopScrollButtonRect(void);
	virtual System::Types::TRect __fastcall GetBottomScrollButtonRect(void);
	virtual void __fastcall DoCreateGroupsInfo(void);
	virtual void __fastcall DoCalculateBounds(int X, int Y);
	virtual bool __fastcall IsGroupActive(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual void __fastcall DoGroupActiveToggle(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual void __fastcall DoGroupActivate(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual void __fastcall DoGroupDeactivate(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual void __fastcall MakeLinkVisible(Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ATop = true);
	virtual void __fastcall MakeGroupVisible(Dxnavbarcollns::TdxNavBarGroup* AGroup, bool AExpandGroup = true, bool ATop = true);
	
public:
	__fastcall virtual TdxNavBarViewInfo(TdxNavBarPainter* APainter);
	__fastcall virtual ~TdxNavBarViewInfo(void);
	virtual void __fastcall CreateInfo(void);
	void __fastcall CreateGroupsInfo(void);
	void __fastcall CalculateBounds(void);
	virtual void __fastcall CalculateScrollButtonsBounds(void);
	virtual void __fastcall ClearRects(void);
	virtual Vcl::Graphics::TPicture* __fastcall BgImage(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor2(void);
	virtual System::Byte __fastcall BgAlphaBlend(void);
	virtual System::Byte __fastcall BgAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall BgGradientMode(void);
	virtual System::Uitypes::TColor __fastcall BorderColor(void);
	virtual Dxnavbarstyles::TdxNavBarStyleItem* __fastcall BottomScrollButtonStyleItem(void);
	virtual Dxnavbarstyles::TdxNavBarBaseStyle* __fastcall BottomScrollButtonStyle(void);
	virtual Vcl::Graphics::TPicture* __fastcall BottomScrollButtonImage(void);
	virtual System::Uitypes::TColor __fastcall BottomScrollButtonBackColor(void);
	virtual System::Uitypes::TColor __fastcall BottomScrollButtonBackColor2(void);
	virtual System::Byte __fastcall BottomScrollButtonAlphaBlend(void);
	virtual System::Byte __fastcall BottomScrollButtonAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall BottomScrollButtonGradientMode(void);
	virtual Dxnavbarstyles::TdxNavBarStyleItem* __fastcall TopScrollButtonStyleItem(void);
	virtual Dxnavbarstyles::TdxNavBarBaseStyle* __fastcall TopScrollButtonStyle(void);
	virtual Vcl::Graphics::TPicture* __fastcall TopScrollButtonImage(void);
	virtual System::Uitypes::TColor __fastcall TopScrollButtonBackColor(void);
	virtual System::Uitypes::TColor __fastcall TopScrollButtonBackColor2(void);
	virtual System::Byte __fastcall TopScrollButtonAlphaBlend(void);
	virtual System::Byte __fastcall TopScrollButtonAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall TopScrollButtonGradientMode(void);
	virtual Vcl::Graphics::TPicture* __fastcall HintImage(void);
	virtual System::Uitypes::TColor __fastcall HintBackColor(void);
	virtual System::Uitypes::TColor __fastcall HintBackColor2(void);
	virtual System::Byte __fastcall HintAlphaBlend(void);
	virtual System::Byte __fastcall HintAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall HintGradientMode(void);
	virtual Vcl::Graphics::TFont* __fastcall HintFont(void);
	virtual System::Uitypes::TColor __fastcall DragDropItemTargetBackColor(void);
	virtual System::Uitypes::TColor __fastcall DragDropGroupTargetBackColor(void);
	virtual System::Uitypes::TColor __fastcall DragDropGroupTargetBackColor2(void);
	virtual System::Byte __fastcall DragDropGroupTargetAlphaBlend(void);
	virtual System::Byte __fastcall DragDropGroupTargetAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall DragDropGroupTargetGradient(void);
	virtual Vcl::Graphics::TPicture* __fastcall HeaderImage(void);
	virtual System::Uitypes::TColor __fastcall HeaderBackColor(void);
	virtual System::Uitypes::TColor __fastcall HeaderBackColor2(void);
	virtual System::Byte __fastcall HeaderAlphaBlend(void);
	virtual System::Byte __fastcall HeaderAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall HeaderGradientMode(void);
	virtual Vcl::Graphics::TFont* __fastcall HeaderFont(void);
	virtual System::Uitypes::TColor __fastcall HeaderFontColor(void);
	virtual Dxnavbarstyles::TdxBarStyleHAlignment __fastcall HeaderHAlignment(void);
	virtual Dxnavbarstyles::TdxBarStyleVAlignment __fastcall HeaderVAlignment(void);
	int __fastcall HeaderDrawEdgeFlag(void);
	virtual Vcl::Graphics::TPicture* __fastcall OverflowPanelImage(void);
	virtual System::Uitypes::TColor __fastcall OverflowPanelBackColor(void);
	virtual System::Uitypes::TColor __fastcall OverflowPanelBackColor2(void);
	virtual System::Byte __fastcall OverflowPanelAlphaBlend(void);
	virtual System::Byte __fastcall OverflowPanelAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall OverflowPanelGradientMode(void);
	virtual Vcl::Graphics::TFont* __fastcall OverflowPanelFont(void);
	virtual System::Uitypes::TColor __fastcall OverflowPanelFontColor(void);
	virtual System::Uitypes::TColor __fastcall SplitterBackColor(void);
	virtual System::Uitypes::TColor __fastcall SplitterBackColor2(void);
	virtual System::Byte __fastcall SplitterAlphaBlend(void);
	virtual System::Byte __fastcall SplitterAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall SplitterGradientMode(void);
	virtual void __fastcall AssignDefaultBackgroundStyle(void);
	virtual void __fastcall AssignDefaultButtonStyle(void);
	virtual void __fastcall AssignDefaultButtonPressedStyle(void);
	virtual void __fastcall AssignDefaultButtonHotTrackedStyle(void);
	virtual void __fastcall AssignDefaultGroupControlStyle(void);
	virtual void __fastcall AssignDefaultGroupBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderActiveStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderActiveHotTrackedStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderActivePressedStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderHotTrackedStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderPressedStyle(void);
	virtual void __fastcall AssignDefaultHintStyle(void);
	virtual void __fastcall AssignDefaultItemStyle(void);
	virtual void __fastcall AssignDefaultItemDisabledStyle(void);
	virtual void __fastcall AssignDefaultItemHotTrackedStyle(void);
	virtual void __fastcall AssignDefaultItemPressedStyle(void);
	virtual void __fastcall AssignDefaultDropTargetGroupStyle(void);
	virtual void __fastcall AssignDefaultDropTargetLinkStyle(void);
	virtual void __fastcall AssignDefaultNavigationPaneHeaderStyle(void);
	TdxNavBarGroupViewInfo* __fastcall ActiveGroupViewInfo(void);
	TdxNavBarGroupViewInfo* __fastcall GetGroupViewInfoByGroup(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	TdxNavBarLinkViewInfo* __fastcall GetLinkViewInfoByLink(Dxnavbarcollns::TdxNavBarItemLink* ALink);
	int __fastcall IndexOfGroupViewInfo(TdxNavBarGroupViewInfo* AViewInfo);
	TdxNavBarGroupViewInfo* __fastcall GetGroupViewInfoAtPos(const System::Types::TPoint pt);
	virtual TdxNavBarGroupViewInfo* __fastcall GetGroupViewInfoAtCaptionPos(const System::Types::TPoint pt);
	virtual TdxNavBarGroupViewInfo* __fastcall GetGroupViewInfoAtItemsPos(const System::Types::TPoint pt);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroupAtCaptionPos(const System::Types::TPoint pt);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroupAtItemsPos(const System::Types::TPoint pt);
	virtual TdxNavBarLinkViewInfo* __fastcall GetLinkViewInfoAtPos(const System::Types::TPoint pt);
	virtual TdxNavBarLinkViewInfo* __fastcall GetLinkViewInfoAtSelectedPos(const System::Types::TPoint pt);
	virtual Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetLinkAtPos(const System::Types::TPoint pt);
	Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetLinkAtSelectedPos(const System::Types::TPoint pt);
	virtual int __fastcall GetViewInfoAtDragPosition(const System::Types::TPoint pt, TdxNavBarGroupViewInfo* &ItemGroup, TdxNavBarLinkViewInfo* &Item1, TdxNavBarLinkViewInfo* &Item2);
	virtual int __fastcall GetViewInfoAtDragPositionWhenIconView(const System::Types::TPoint pt, TdxNavBarGroupViewInfo* &ItemGroup, TdxNavBarLinkViewInfo* &Item1, TdxNavBarLinkViewInfo* &Item2);
	int __fastcall GetLinksAtDragPosition(const System::Types::TPoint pt, Dxnavbarcollns::TdxNavBarGroup* &ItemGroup, Dxnavbarcollns::TdxNavBarItemLink* &Item1, Dxnavbarcollns::TdxNavBarItemLink* &Item2);
	bool __fastcall IsPtGroupDesignRect(const System::Types::TPoint pt);
	bool __fastcall IsPtItemDesignRect(const System::Types::TPoint pt);
	bool __fastcall IsTopScrollButtonVisible(void);
	bool __fastcall IsBottomScrollButtonVisible(void);
	bool __fastcall IsPtTopScrollButton(const System::Types::TPoint pt);
	bool __fastcall IsPtBottomScrollButton(const System::Types::TPoint pt);
	__property System::Types::TRect TopScrollButtonRect = {read=FTopScrollButtonRect};
	__property System::Types::TRect BottomScrollButtonRect = {read=FBottomScrollButtonRect};
	__property TdxNavBarObjectStates TopScrollButtonState = {read=GetTopScrollButtonState, nodefault};
	__property TdxNavBarObjectStates BottomScrollButtonState = {read=GetBottomScrollButtonState, nodefault};
	__property System::Types::TRect HintRect = {read=FHintRect, write=FHintRect};
	__property System::UnicodeString HintText = {read=FHintText, write=FHintText};
	virtual Dxnavbarcollns::TdxNavBarGroup* __fastcall FindGroupWithAccel(System::Word AKey);
	virtual Dxnavbarcollns::TdxNavBarItemLink* __fastcall FindLinkWithAccel(System::Word AKey);
	__property int GroupCount = {read=GetGroupCount, nodefault};
	__property TdxNavBarGroupViewInfo* Groups[int Index] = {read=GetGroup};
};


typedef System::TMetaClass* TdxNavBarViewInfoClass;

class DELPHICLASS TdxNavBarItemCalculator;
class PASCALIMPLEMENTATION TdxNavBarItemCalculator : public Dxnavbarcollns::TdxNavBarCustomGroupItemCalculator
{
	typedef Dxnavbarcollns::TdxNavBarCustomGroupItemCalculator inherited;
	
public:
	__classmethod virtual void __fastcall CalculateBounds(int X, int Y, void *ALinkViewInfo);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarItemCalculator(void) : Dxnavbarcollns::TdxNavBarCustomGroupItemCalculator() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarItemCalculator(void) { }
	
};


class DELPHICLASS TdxNavBarSeparatorCalculator;
class PASCALIMPLEMENTATION TdxNavBarSeparatorCalculator : public Dxnavbarcollns::TdxNavBarCustomGroupItemCalculator
{
	typedef Dxnavbarcollns::TdxNavBarCustomGroupItemCalculator inherited;
	
public:
	__classmethod virtual void __fastcall CalculateBounds(int X, int Y, void *ALinkViewInfo);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarSeparatorCalculator(void) : Dxnavbarcollns::TdxNavBarCustomGroupItemCalculator() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarSeparatorCalculator(void) { }
	
};


class DELPHICLASS TdxNavBarController;
class DELPHICLASS TdxNavBarScrollBar;
class DELPHICLASS TdxNavBarHintWindow;
class PASCALIMPLEMENTATION TdxNavBarPainter : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	bool FNeedRecreateViewInfo;
	bool FNeedRecalculateViewInfo;
	TdxNavBarViewInfo* FViewInfo;
	TdxNavBarController* FController;
	Vcl::Graphics::TCanvas* __fastcall GetCanvas(void);
	Cxgraphics::TcxCanvas* __fastcall GetcxCanvas(void);
	
protected:
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetMasterLookAndFeel(void);
	void __fastcall CheckDrawParamChanges(void);
	void __fastcall CheckViewInfo(void);
	__classmethod virtual bool __fastcall Reregistered();
	virtual TdxNavBarViewInfo* __fastcall CreateViewInfo(void);
	virtual TdxNavBarGroupViewInfo* __fastcall CreateGroupViewInfo(TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible);
	virtual TdxNavBarLinkViewInfo* __fastcall CreateLinkViewInfo(TdxNavBarGroupViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble);
	__classmethod virtual TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	void __fastcall RecreateViewInfo(void);
	void __fastcall RecalculateViewInfo(void);
	void __fastcall RedrawCanvas(void);
	TdxNavBarController* __fastcall CreateController(void);
	virtual TdxNavBarControllerClass __fastcall GetControllerClass(void);
	virtual Cxcontrols::TcxControlScrollBarHelper* __fastcall CreatecxScrollBarHelper(TdxNavBarScrollBar* AOwner);
	virtual Cxcontrols::TcxControlScrollBarHelperClass __fastcall GetcxScrollBarHelperClass(void);
	virtual bool __fastcall NeedScrollBar(void);
	virtual void __fastcall UpdateScrollBarLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	bool __fastcall IsViewInfoValid(void);
	virtual void __fastcall DoDrawHint(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	void __fastcall DrawSolidFocusRect(System::Types::TRect &ARect, System::Uitypes::TColor AColor);
	
public:
	__fastcall virtual TdxNavBarPainter(TdxCustomNavBar* ANavBar);
	__fastcall virtual ~TdxNavBarPainter(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HDC __fastcall DC(void);
	virtual void __fastcall DrawNavBarControl(void);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawGroup(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupBackground(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupBorder(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaption(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionButton(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionText(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionImage(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionSign(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupControl(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupDesignRect(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupItems(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupFocusRect(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawItem(TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawItemCaption(TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawItemDesignRect(TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawItemFocusRect(TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawItemImage(TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawItemSelection(TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawItemsRect(TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawSeparator(TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawScrollButtons(void);
	virtual void __fastcall DrawBottomScrollButton(void);
	virtual void __fastcall DrawTopScrollButton(void);
	virtual void __fastcall DrawDropTargetGroupSelection(void);
	virtual void __fastcall DrawDropTargetLinkSelection(void);
	virtual void __fastcall DrawHintWindow(TdxNavBarHintWindow* AHintWindow);
	virtual void __fastcall DrawGroupHintWindow(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawLinkHintWindow(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	void __fastcall InvalidateViewInfo(Dxnavbarbase::TdxNavBarChangeType AType);
	void __fastcall InvalidateScrollButtons(void);
	void __fastcall Paint(void);
	__classmethod virtual TdxNavBarViewCategories __fastcall GetCategories();
	__property Vcl::Graphics::TCanvas* Canvas = {read=GetCanvas};
	__property Cxgraphics::TcxCanvas* cxCanvas = {read=GetcxCanvas};
	__property TdxNavBarController* Controller = {read=FController};
	__property TdxNavBarViewInfo* ViewInfo = {read=FViewInfo};
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};


typedef System::TMetaClass* TdxNavBarPainterClass;

class DELPHICLASS TdxNavBarCursors;
class PASCALIMPLEMENTATION TdxNavBarCursors : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	System::Uitypes::TCursor FDragCopyCursor;
	System::Uitypes::TCursor FHotTrackedGroupCursor;
	System::Uitypes::TCursor FHotTrackedLinkCursor;
	System::Uitypes::TCursor __fastcall GetCursor(void);
	System::Uitypes::TCursor __fastcall GetDragCursor(void);
	void __fastcall SetCursor(System::Uitypes::TCursor Value);
	void __fastcall SetDragCursor(System::Uitypes::TCursor Value);
	
public:
	__fastcall virtual TdxNavBarCursors(TdxCustomNavBar* ANavBar);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Uitypes::TCursor Cursor = {read=GetCursor, write=SetCursor, default=0};
	__property System::Uitypes::TCursor DragCursor = {read=GetDragCursor, write=SetDragCursor, default=-1120};
	__property System::Uitypes::TCursor DragCopyCursor = {read=FDragCopyCursor, write=FDragCopyCursor, default=-1119};
	__property System::Uitypes::TCursor HotTrackedGroupCursor = {read=FHotTrackedGroupCursor, write=FHotTrackedGroupCursor, default=0};
	__property System::Uitypes::TCursor HotTrackedLinkCursor = {read=FHotTrackedLinkCursor, write=FHotTrackedLinkCursor, default=-1118};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarCursors(void) { }
	
};


typedef void __fastcall (__closure *TdxNavBarCustomDrawEvent)(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, TdxNavBarViewInfo* AViewInfo, bool &AHandled);

typedef void __fastcall (__closure *TdxNavBarCustomDrawGroupEvent)(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, TdxNavBarGroupViewInfo* AViewInfo, bool &AHandled);

typedef void __fastcall (__closure *TdxNavBarCustomDrawGroupHintEvent)(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxnavbarcollns::TdxNavBarGroup* AGroup, System::UnicodeString AHint, System::Types::TRect &R, bool &AHandled);

typedef void __fastcall (__closure *TdxNavBarCustomDrawLinkEvent)(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, TdxNavBarLinkViewInfo* AViewInfo, bool &AHandled);

typedef void __fastcall (__closure *TdxNavBarCustomDrawLinkHintEvent)(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxnavbarcollns::TdxNavBarItemLink* ALink, System::UnicodeString AHint, System::Types::TRect &R, bool &AHandled);

class DELPHICLASS TdxNavBarCustomDrawEvents;
class PASCALIMPLEMENTATION TdxNavBarCustomDrawEvents : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	TdxNavBarCustomDrawEvent FBackground;
	TdxNavBarCustomDrawEvent FBottomScrollButton;
	TdxNavBarCustomDrawEvent FTopScrollButton;
	TdxNavBarCustomDrawGroupEvent FGroupCaption;
	TdxNavBarCustomDrawGroupEvent FGroupClientBackground;
	TdxNavBarCustomDrawGroupEvent FGroupClientForeground;
	TdxNavBarCustomDrawGroupHintEvent FGroupHint;
	TdxNavBarCustomDrawLinkEvent FLink;
	TdxNavBarCustomDrawLinkHintEvent FLinkHint;
	TdxNavBarCustomDrawEvent FNavigationPaneHeader;
	TdxNavBarCustomDrawEvent FNavigationPaneSplitter;
	TdxNavBarCustomDrawEvent FNavigationPaneOverflowPanel;
	TdxNavBarCustomDrawGroupHintEvent FNavigationPaneOverflowPanelHint;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxNavBarCustomDrawEvent Background = {read=FBackground, write=FBackground};
	__property TdxNavBarCustomDrawGroupEvent GroupCaption = {read=FGroupCaption, write=FGroupCaption};
	__property TdxNavBarCustomDrawGroupEvent GroupClientBackground = {read=FGroupClientBackground, write=FGroupClientBackground};
	__property TdxNavBarCustomDrawGroupEvent GroupClientForeground = {read=FGroupClientForeground, write=FGroupClientForeground};
	__property TdxNavBarCustomDrawGroupHintEvent GroupHint = {read=FGroupHint, write=FGroupHint};
	__property TdxNavBarCustomDrawLinkEvent Link = {read=FLink, write=FLink};
	__property TdxNavBarCustomDrawLinkHintEvent LinkHint = {read=FLinkHint, write=FLinkHint};
	__property TdxNavBarCustomDrawEvent BottomScrollButton = {read=FBottomScrollButton, write=FBottomScrollButton};
	__property TdxNavBarCustomDrawEvent TopScrollButton = {read=FTopScrollButton, write=FTopScrollButton};
	__property TdxNavBarCustomDrawEvent NavigationPaneHeader = {read=FNavigationPaneHeader, write=FNavigationPaneHeader};
	__property TdxNavBarCustomDrawEvent NavigationPaneSplitter = {read=FNavigationPaneSplitter, write=FNavigationPaneSplitter};
	__property TdxNavBarCustomDrawEvent NavigationPaneOverflowPanel = {read=FNavigationPaneOverflowPanel, write=FNavigationPaneOverflowPanel};
	__property TdxNavBarCustomDrawGroupHintEvent NavigationPaneOverflowPanelHint = {read=FNavigationPaneOverflowPanelHint, write=FNavigationPaneOverflowPanelHint};
public:
	/* TdxNavBarPersistent.Create */ inline __fastcall virtual TdxNavBarCustomDrawEvents(TdxCustomNavBar* ANavBar) : TdxNavBarPersistent(ANavBar) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarCustomDrawEvents(void) { }
	
};


class DELPHICLASS TdxNavBarCustomCustomizationForm;
class PASCALIMPLEMENTATION TdxNavBarCustomCustomizationForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TdxCustomNavBar* FNavBar;
	int FLockCount;
	void __fastcall SetNavBar(TdxCustomNavBar* Value);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoClose(System::Uitypes::TCloseAction &Action);
	void __fastcall CreateControls(void);
	virtual void __fastcall DoCreateControls(void);
	virtual void __fastcall Init(void);
	virtual void __fastcall Localize(void);
	virtual void __fastcall DoRefreshItems(void);
	void __fastcall RefreshItems(void);
	void __fastcall CreateLink(Dxnavbarcollns::TdxNavBarItem* AItem, Dxnavbarcollns::TdxNavBarGroup* AGroup, int AIndex);
	void __fastcall MoveLink(Dxnavbarcollns::TdxNavBarItemLink* ALink, Dxnavbarcollns::TdxNavBarGroup* AGroup, int AIndex);
	void __fastcall RemoveLink(Dxnavbarcollns::TdxNavBarItemLink* ALink);
	virtual bool __fastcall CanProcessDropItem(System::TObject* Target, int X, int Y);
	virtual void __fastcall DoProcessDropItem(System::TObject* Target, int X, int Y);
	void __fastcall ProcessDropItem(System::TObject* Target, int X, int Y);
	
public:
	__fastcall virtual ~TdxNavBarCustomCustomizationForm(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	__property TdxCustomNavBar* NavBar = {read=FNavBar, write=SetNavBar};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxNavBarCustomCustomizationForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxNavBarCustomCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxNavBarCustomCustomizationForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxNavBarCustomCustomizationFormClass;

class DELPHICLASS TdxNavBarCustomization;
class PASCALIMPLEMENTATION TdxNavBarCustomization : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	TdxNavBarCustomCustomizationForm* FForm;
	System::Types::TRect FFormBounds;
	bool __fastcall GetVisible(void);
	void __fastcall SetVisible(bool Value);
	
protected:
	virtual System::Types::TRect __fastcall CalculateFormBounds(void);
	virtual void __fastcall CreateForm(void);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual TdxNavBarCustomCustomizationFormClass __fastcall GetFormClass(void);
	void __fastcall RefreshItems(void);
	
public:
	__fastcall virtual ~TdxNavBarCustomization(void);
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
	__property TdxNavBarCustomCustomizationForm* Form = {read=FForm};
	__property System::Types::TRect FormBounds = {read=FFormBounds, write=FFormBounds};
public:
	/* TdxNavBarPersistent.Create */ inline __fastcall virtual TdxNavBarCustomization(TdxCustomNavBar* ANavBar) : TdxNavBarPersistent(ANavBar) { }
	
};


typedef System::TMetaClass* TdxNavBarCustomizationClass;

class DELPHICLASS TdxNavBarCommonBehaviorOptions;
class PASCALIMPLEMENTATION TdxNavBarCommonBehaviorOptions : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	bool FAllowSelectLinks;
	TdxNavBarDragDropFlags FDragDropFlags;
	bool FEachGroupHasSelectedLink;
	bool FShowGroupsHint;
	bool FShowLinksHint;
	void __fastcall SetAllowSelectLinks(bool Value);
	void __fastcall SetEachGroupHasSelectedLink(bool Value);
	
public:
	__fastcall virtual TdxNavBarCommonBehaviorOptions(TdxCustomNavBar* ANavBar);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AllowSelectLinks = {read=FAllowSelectLinks, write=SetAllowSelectLinks, default=0};
	__property TdxNavBarDragDropFlags DragDropFlags = {read=FDragDropFlags, write=FDragDropFlags, default=15};
	__property bool EachGroupHasSelectedLink = {read=FEachGroupHasSelectedLink, write=SetEachGroupHasSelectedLink, default=0};
	__property bool ShowGroupsHint = {read=FShowGroupsHint, write=FShowGroupsHint, default=0};
	__property bool ShowLinksHint = {read=FShowLinksHint, write=FShowLinksHint, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarCommonBehaviorOptions(void) { }
	
};


class DELPHICLASS TdxNavBarNavigationPaneBehaviorOptions;
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneBehaviorOptions : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	bool FAdjustWidthByPopup;
	bool FAllowCustomizing;
	bool FCollapsible;
	bool FCollapsed;
	bool FShowOverflowPanelHints;
	void __fastcall SetCollapsible(bool Value);
	void __fastcall SetCollapsed(bool Value);
	
public:
	__fastcall virtual TdxNavBarNavigationPaneBehaviorOptions(TdxCustomNavBar* ANavBar);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AdjustWidthByPopup = {read=FAdjustWidthByPopup, write=FAdjustWidthByPopup, default=0};
	__property bool AllowCustomizing = {read=FAllowCustomizing, write=FAllowCustomizing, default=1};
	__property bool Collapsible = {read=FCollapsible, write=SetCollapsible, default=0};
	__property bool Collapsed = {read=FCollapsed, write=SetCollapsed, default=0};
	__property bool ShowOverflowPanelHints = {read=FShowOverflowPanelHints, write=FShowOverflowPanelHints, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneBehaviorOptions(void) { }
	
};


class DELPHICLASS TdxNavBarSideBarBehaviorOptions;
class PASCALIMPLEMENTATION TdxNavBarSideBarBehaviorOptions : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	bool __fastcall GetAllowSelectLinks(void);
	bool __fastcall GetEachGroupHasSelectedLink(void);
	void __fastcall SetAllowSelectLinks(bool Value);
	void __fastcall SetEachGroupHasSelectedLink(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AllowSelectLinks = {read=GetAllowSelectLinks, write=SetAllowSelectLinks, stored=false, nodefault};
	__property bool EachGroupHasSelectedLink = {read=GetEachGroupHasSelectedLink, write=SetEachGroupHasSelectedLink, stored=false, nodefault};
public:
	/* TdxNavBarPersistent.Create */ inline __fastcall virtual TdxNavBarSideBarBehaviorOptions(TdxCustomNavBar* ANavBar) : TdxNavBarPersistent(ANavBar) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarSideBarBehaviorOptions(void) { }
	
};


class DELPHICLASS TdxNavBarBehaviorOptions;
class PASCALIMPLEMENTATION TdxNavBarBehaviorOptions : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	TdxNavBarCommonBehaviorOptions* FCommon;
	TdxNavBarNavigationPaneBehaviorOptions* FNavigationPane;
	TdxNavBarSideBarBehaviorOptions* FSideBar;
	void __fastcall SetCommon(TdxNavBarCommonBehaviorOptions* AValue);
	void __fastcall SetNavigationPane(TdxNavBarNavigationPaneBehaviorOptions* AValue);
	void __fastcall SetSideBar(TdxNavBarSideBarBehaviorOptions* AValue);
	
public:
	__fastcall virtual TdxNavBarBehaviorOptions(TdxCustomNavBar* ANavBar);
	__fastcall virtual ~TdxNavBarBehaviorOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxNavBarCommonBehaviorOptions* Common = {read=FCommon, write=SetCommon};
	__property TdxNavBarNavigationPaneBehaviorOptions* NavigationPane = {read=FNavigationPane, write=SetNavigationPane};
	__property TdxNavBarSideBarBehaviorOptions* SideBar = {read=FSideBar, write=SetSideBar, stored=false};
};


class DELPHICLASS TdxNavBarCommonViewOptions;
class PASCALIMPLEMENTATION TdxNavBarCommonViewOptions : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	bool FShowGroupCaptions;
	void __fastcall SetShowGroupCaptions(bool AValue);
	
public:
	__fastcall virtual TdxNavBarCommonViewOptions(TdxCustomNavBar* ANavBar);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool ShowGroupCaptions = {read=FShowGroupCaptions, write=SetShowGroupCaptions, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarCommonViewOptions(void) { }
	
};


class DELPHICLASS TdxNavBarExplorerBarViewOptions;
class PASCALIMPLEMENTATION TdxNavBarExplorerBarViewOptions : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	bool FShowSpecialGroup;
	int FSpaceBetweenGroups;
	void __fastcall SetShowSpecialGroup(bool Value);
	void __fastcall SetSpaceBetweenGroups(int Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool ShowSpecialGroup = {read=FShowSpecialGroup, write=SetShowSpecialGroup, default=0};
	__property int SpaceBetweenGroups = {read=FSpaceBetweenGroups, write=SetSpaceBetweenGroups, default=0};
public:
	/* TdxNavBarPersistent.Create */ inline __fastcall virtual TdxNavBarExplorerBarViewOptions(TdxCustomNavBar* ANavBar) : TdxNavBarPersistent(ANavBar) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarExplorerBarViewOptions(void) { }
	
};


class DELPHICLASS TdxNavBarNavigationPaneViewOptions;
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneViewOptions : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	int FMaxVisibleGroups;
	bool FOverflowPanelUseSmallImages;
	bool FShowActiveGroupCaptionWhenCollapsed;
	bool FShowHeader;
	bool FShowOverflowPanel;
	void __fastcall SetMaxVisibleGroups(int Value);
	void __fastcall SetOverflowPanelUseSmallImages(bool Value);
	void __fastcall SetShowActiveGroupCaptionWhenCollapsed(bool Value);
	void __fastcall SetShowHeader(bool Value);
	void __fastcall SetShowOverflowPanel(bool Value);
	
public:
	__fastcall virtual TdxNavBarNavigationPaneViewOptions(TdxCustomNavBar* ANavBar);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int MaxVisibleGroups = {read=FMaxVisibleGroups, write=SetMaxVisibleGroups, default=-1};
	__property bool OverflowPanelUseSmallImages = {read=FOverflowPanelUseSmallImages, write=SetOverflowPanelUseSmallImages, default=1};
	__property bool ShowActiveGroupCaptionWhenCollapsed = {read=FShowActiveGroupCaptionWhenCollapsed, write=SetShowActiveGroupCaptionWhenCollapsed, default=0};
	__property bool ShowHeader = {read=FShowHeader, write=SetShowHeader, default=1};
	__property bool ShowOverflowPanel = {read=FShowOverflowPanel, write=SetShowOverflowPanel, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneViewOptions(void) { }
	
};


class DELPHICLASS TdxNavBarViewOptions;
class PASCALIMPLEMENTATION TdxNavBarViewOptions : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	TdxNavBarCommonViewOptions* FCommon;
	TdxNavBarExplorerBarViewOptions* FExplorerBar;
	TdxNavBarNavigationPaneViewOptions* FNavigationPane;
	void __fastcall SetCommon(TdxNavBarCommonViewOptions* AValue);
	void __fastcall SetExplorerBar(TdxNavBarExplorerBarViewOptions* AValue);
	void __fastcall SetNavigationPane(TdxNavBarNavigationPaneViewOptions* AValue);
	
public:
	__fastcall virtual TdxNavBarViewOptions(TdxCustomNavBar* ANavBar);
	__fastcall virtual ~TdxNavBarViewOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxNavBarCommonViewOptions* Common = {read=FCommon, write=SetCommon};
	__property TdxNavBarExplorerBarViewOptions* ExplorerBar = {read=FExplorerBar, write=SetExplorerBar};
	__property TdxNavBarNavigationPaneViewOptions* NavigationPane = {read=FNavigationPane, write=SetNavigationPane};
};


class DELPHICLASS TdxNavBarImageOptions;
class PASCALIMPLEMENTATION TdxNavBarImageOptions : public Dxnavbarbase::TdxNavBarNexusPersistent
{
	typedef Dxnavbarbase::TdxNavBarNexusPersistent inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FDisabledSmallImages;
	Vcl::Imglist::TCustomImageList* FDisabledLargeImages;
	Vcl::Imglist::TCustomImageList* FHotSmallImages;
	Vcl::Imglist::TCustomImageList* FHotLargeImages;
	Vcl::Imglist::TCustomImageList* FLargeImages;
	Vcl::Imglist::TCustomImageList* FSmallImages;
	Vcl::Imglist::TChangeLink* FDisabledLargeChangeLink;
	Vcl::Imglist::TChangeLink* FDisabledSmallChangeLink;
	Vcl::Imglist::TChangeLink* FHotLargeChangeLink;
	Vcl::Imglist::TChangeLink* FHotSmallChangeLink;
	Vcl::Imglist::TChangeLink* FLargeChangeLink;
	Vcl::Imglist::TChangeLink* FSmallChangeLink;
	void __fastcall SetImageList(Vcl::Imglist::TCustomImageList* &ANewValue, Vcl::Imglist::TCustomImageList* &AOldValue, Vcl::Imglist::TChangeLink* const AChangeLink);
	void __fastcall SetDisabledLargeImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetDisabledSmallImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetHotLargeImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetHotSmallImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetLargeImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetSmallImages(Vcl::Imglist::TCustomImageList* Value);
	
protected:
	virtual void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	
public:
	__fastcall virtual TdxNavBarImageOptions(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxNavBarImageOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Imglist::TCustomImageList* DisabledLargeImages = {read=FDisabledLargeImages, write=SetDisabledLargeImages};
	__property Vcl::Imglist::TCustomImageList* DisabledSmallImages = {read=FDisabledSmallImages, write=SetDisabledSmallImages};
	__property Vcl::Imglist::TCustomImageList* HotLargeImages = {read=FHotLargeImages, write=SetHotLargeImages};
	__property Vcl::Imglist::TCustomImageList* HotSmallImages = {read=FHotSmallImages, write=SetHotSmallImages};
	__property Vcl::Imglist::TCustomImageList* LargeImages = {read=FLargeImages, write=SetLargeImages};
	__property Vcl::Imglist::TCustomImageList* SmallImages = {read=FSmallImages, write=SetSmallImages};
};


struct DECLSPEC_DRECORD TdxNavBarPart
{
public:
	int MajorPartIndex;
	int MinorPartIndex;
};


class PASCALIMPLEMENTATION TdxNavBarController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxNavBarPart FHotPart;
	TdxNavBarPart FPressedPart;
	TdxNavBarPainter* __fastcall GetPainter(void);
	Cxcontrols::TcxControlScrollBarHelper* __fastcall GetScrollBarHelper(void);
	TdxNavBarViewInfo* __fastcall GetViewInfo(void);
	void __fastcall CalcGroupHintRect(System::TObject* AItem, System::Types::TRect &ARect);
	void __fastcall CalcLinkHintRect(System::TObject* AItem, System::Types::TRect &ARect);
	void __fastcall SetHotPart(TdxNavBarPart APart);
	void __fastcall SetPressedPart(TdxNavBarPart APart);
	void __fastcall UpdateHotTrack(System::Classes::TShiftState AShift = System::Classes::TShiftState() )/* overload */;
	void __fastcall UpdateHotTrack(System::Classes::TShiftState AShift, const System::Types::TPoint APoint)/* overload */;
	
protected:
	TdxCustomNavBar* FNavBar;
	virtual bool __fastcall CanFocusOnClick(const System::Types::TPoint APoint);
	virtual HICON __fastcall GetCursor(void);
	System::Types::TRect __fastcall GetItemHintRect(System::TObject* ANavBarItem, TdxNavBarCalcHintEvent ACalcHintProc);
	virtual TdxNavBarPart __fastcall GetPartAtPos(const System::Types::TPoint APoint);
	virtual void __fastcall DoClick(const TdxNavBarPart APart);
	virtual void __fastcall DoCheckBounds(int &ALeft, int &ATop, int &AWidth, int &AHeight);
	virtual void __fastcall DoLinkClick(TdxCustomNavBar* ANavBar, Dxnavbarcollns::TdxNavBarItemLink* ALink);
	virtual void __fastcall DoLinkHotTrack(TdxCustomNavBar* ANavBar, Dxnavbarcollns::TdxNavBarItemLink* ALink);
	virtual void __fastcall DoLinkPress(TdxCustomNavBar* ANavBar, Dxnavbarcollns::TdxNavBarItemLink* ALink);
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	virtual void __fastcall DoMouseUp(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	virtual void __fastcall DoMouseLeave(void);
	virtual bool __fastcall DoMouseWheel(System::Classes::TShiftState AShift, int AWheelDelta, const System::Types::TPoint APoint);
	bool __fastcall DoScrollDown(void);
	bool __fastcall DoScrollUp(void);
	virtual void __fastcall DoSetHotPart(const TdxNavBarPart APart);
	virtual void __fastcall DoSetPressedPart(const TdxNavBarPart APart);
	virtual void __fastcall DoShowHint(Vcl::Controls::THintInfo &AHintInfo);
	virtual void __fastcall DoShowGroupHint(Vcl::Controls::THintInfo &AHintInfo, TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DoShowLinkHint(Vcl::Controls::THintInfo &AHintInfo, TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual System::Types::TRect __fastcall GetGroupHintRect(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual System::UnicodeString __fastcall GetGroupHintText(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual System::Types::TRect __fastcall GetLinkHintRect(Dxnavbarcollns::TdxNavBarItemLink* ALink);
	virtual System::UnicodeString __fastcall GetLinkHintText(Dxnavbarcollns::TdxNavBarItemLink* ALink);
	__property TdxCustomNavBar* NavBar = {read=FNavBar};
	__property Cxcontrols::TcxControlScrollBarHelper* ScrollBarHelper = {read=GetScrollBarHelper};
	
public:
	__fastcall virtual TdxNavBarController(TdxCustomNavBar* ANavBar);
	__fastcall virtual ~TdxNavBarController(void);
	void __fastcall CheckBounds(int &ALeft, int &ATop, int &AWidth, int &AHeight);
	void __fastcall InvalidateAll(Dxnavbarbase::TdxNavBarChangeType AType);
	void __fastcall MouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	void __fastcall MouseUp(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	void __fastcall MouseMove(System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	void __fastcall MouseLeave(void);
	bool __fastcall MouseWheel(System::Classes::TShiftState AShift, int AWheelDelta, const System::Types::TPoint APoint);
	void __fastcall ShowHint(Vcl::Controls::THintInfo &AHintInfo, /* out */ bool &ACanShow);
	__property TdxNavBarPart HotPart = {read=FHotPart, write=SetHotPart};
	__property TdxNavBarPart PressedPart = {read=FPressedPart, write=SetPressedPart};
	__property TdxNavBarPainter* Painter = {read=GetPainter};
	__property TdxNavBarViewInfo* ViewInfo = {read=GetViewInfo};
};


typedef void __fastcall (__closure *TdxNavBarGroupEvent)(System::TObject* Sender, Dxnavbarcollns::TdxNavBarGroup* AGroup);

typedef void __fastcall (__closure *TdxNavBarGroupChangingEvent)(System::TObject* Sender, Dxnavbarcollns::TdxNavBarGroup* ANewGroup, bool &AAllowChange);

typedef void __fastcall (__closure *TdxNavBarLinkEvent)(System::TObject* Sender, Dxnavbarcollns::TdxNavBarItemLink* ALink);

typedef void __fastcall (__closure *TdxNavBarCalcGroupHintRectEvent)(System::TObject* Sender, Dxnavbarcollns::TdxNavBarGroup* AGroup, TdxNavBarViewInfo* AViewInfo, System::Types::TRect &R);

typedef void __fastcall (__closure *TdxNavBarCalcLinkHintRectEvent)(System::TObject* Sender, Dxnavbarcollns::TdxNavBarItemLink* ALink, TdxNavBarViewInfo* AViewInfo, System::Types::TRect &R);

typedef void __fastcall (__closure *TdxNavBarCalcGroupClientHeightEvent)(System::TObject* Sender, TdxNavBarGroupViewInfo* AViewInfo, int &AHeight);

typedef void __fastcall (__closure *TdxNavBarGetGroupHintEvent)(System::TObject* Sender, Dxnavbarcollns::TdxNavBarGroup* AGroup, System::UnicodeString &AHint);

typedef void __fastcall (__closure *TdxNavBarGetLinkHintEvent)(System::TObject* Sender, Dxnavbarcollns::TdxNavBarItemLink* ALink, System::UnicodeString &AHint);

enum TdxNavBarInternalState : unsigned char { nbisKeyDowned, nbisDragging, nbisAlreadyCollapsed, nbisAfterLoading };

typedef System::Set<TdxNavBarInternalState, TdxNavBarInternalState::nbisKeyDowned, TdxNavBarInternalState::nbisAfterLoading>  TdxNavBarInternalStates;

class DELPHICLASS TdxNavBarLookAndFeelSchemes;
class PASCALIMPLEMENTATION TdxNavBarLookAndFeelSchemes : public TdxNavBarPersistent
{
	typedef TdxNavBarPersistent inherited;
	
private:
	System::StaticArray<int, 6> FViews;
	int __fastcall GetRealView(int Index);
	int __fastcall GetView(Cxlookandfeelpainters::TcxLookAndFeelStyle Index);
	void __fastcall SetRealView(int Index, const int Value);
	void __fastcall SetView(Cxlookandfeelpainters::TcxLookAndFeelStyle Index, const int Value);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TdxNavBarLookAndFeelSchemes(TdxCustomNavBar* ANavBar);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int Views[Cxlookandfeelpainters::TcxLookAndFeelStyle Index] = {read=GetView, write=SetView};
	
__published:
	__property int Flat = {read=GetRealView, write=SetRealView, index=0, default=1};
	__property int Standard = {read=GetRealView, write=SetRealView, index=1, default=0};
	__property int UltraFlat = {read=GetRealView, write=SetRealView, index=2, default=1};
	__property int Native = {read=GetRealView, write=SetRealView, index=3, default=17};
	__property int Office11 = {read=GetRealView, write=SetRealView, index=4, default=13};
	__property int Skin = {read=GetRealView, write=SetRealView, index=5, default=15};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarLookAndFeelSchemes(void) { }
	
};


class PASCALIMPLEMENTATION TdxCustomNavBar : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Dxnavbarcollns::TdxNavBarGroup* FActiveGroup;
	int FActiveGroupIndex;
	Vcl::Forms::TFormBorderStyle FBorderStyle;
	TdxNavBarCursors* FCursors;
	TdxNavBarCustomization* FCustomization;
	Vcl::Controls::TDragControlObject* FDragObject;
	Dxnavbarcollns::TdxNavBarGroups* FGroups;
	TdxNavBarInternalStates FInternalState;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FIAccessibilityHelper;
	int FIsBoundsCheckingLockCount;
	bool FIsCollapseStateChecking;
	bool FIsLookAndFeelDependent;
	Dxnavbarcollns::TdxNavBarItems* FItems;
	TdxNavBarLookAndFeelSchemes* FLookAndFeelSchemes;
	TdxNavBarPainter* FPainter;
	int FViewReal;
	TdxNavBarScrollBar* FScrollBar;
	Dxthememanager::TdxThemeChangedNotificator* FThemeNotificator;
	int FUpdateLock;
	int FView;
	TdxNavBarBehaviorOptions* FOptionsBehavior;
	TdxNavBarImageOptions* FOptionsImage;
	Dxnavbarstyles::TdxNavBarStyleOptions* FOptionsStyle;
	TdxNavBarViewOptions* FOptionsView;
	TdxNavBarCustomDrawEvents* FOnCustomDraw;
	System::Classes::TNotifyEvent FOnActiveGroupChanged;
	TdxNavBarGroupChangingEvent FOnActiveGroupChanging;
	TdxNavBarCalcGroupHintRectEvent FOnCalcGroupHintRect;
	TdxNavBarCalcGroupClientHeightEvent FOnCalcGroupClientHeight;
	TdxNavBarCalcLinkHintRectEvent FOnCalcLinkHintRect;
	TdxNavBarCalcGroupHintRectEvent FOnCalcNavigationPaneOverflowPanelHintRect;
	System::Classes::TNotifyEvent FOnCollapseStateChanged;
	TdxNavBarGetGroupHintEvent FOnGetGroupHint;
	TdxNavBarGetLinkHintEvent FOnGetLinkHint;
	TdxNavBarGroupEvent FOnGroupClick;
	TdxNavBarGroupEvent FOnGroupHotTrack;
	TdxNavBarGroupEvent FOnGroupPress;
	TdxNavBarLinkEvent FOnLinkClick;
	TdxNavBarLinkEvent FOnLinkHotTrack;
	TdxNavBarLinkEvent FOnLinkPress;
	System::Classes::TNotifyEvent FOnNavigationPaneCollapsed;
	System::Classes::TNotifyEvent FOnNavigationPaneExpanded;
	Cxclasses::TcxTimer* FActivateGroupTimer;
	Cxclasses::TcxTimer* FScrollTimer;
	Dxnavbarcollns::TdxNavBarGroup* FActiveGroupCandidate;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FFocusedAccessibleObject;
	System::Types::TPoint FSourcePoint;
	System::Classes::TShiftState FSourceShift;
	Dxnavbarcollns::TdxNavBarGroup* FSourceGroup;
	Dxnavbarcollns::TdxNavBarItemLink* FSourceLink;
	System::Types::TPoint FTargetPoint;
	Dxnavbarcollns::TdxNavBarGroup* FHotTrackedGroup;
	Dxnavbarcollns::TdxNavBarItemLink* FHotTrackedLink;
	int FOriginalWidth;
	Dxnavbarcollns::TdxNavBarGroup* FPressedGroup;
	Dxnavbarcollns::TdxNavBarItemLink* FPressedLink;
	bool FScrollButtonDownIsDown;
	bool FScrollButtonUpIsDown;
	TdxNavBarController* __fastcall GetController(void);
	TdxNavBarPainter* __fastcall GetPainter(void);
	TdxNavBarViewInfo* __fastcall GetViewInfo(void);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetActiveGroup(void);
	int __fastcall GetActiveGroupIndex(void);
	int __fastcall GetNavigationPaneOverflowPanelItemCount(void);
	bool __fastcall GetEnableDragging(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	int __fastcall GetScrollPosition(void);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetSourceGroup(void);
	Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetSourceLink(void);
	Dxnavbarcollns::TdxNavBarItem* __fastcall GetSourceItem(void);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetTargetGroup(void);
	Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetTargetLink1(void);
	Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetTargetLink2(void);
	int __fastcall GetTargetLinkIndex(void);
	int __fastcall GetVisibleGroupCount(void);
	void __fastcall SetActiveGroup(Dxnavbarcollns::TdxNavBarGroup* Value);
	void __fastcall SetActiveGroupIndex(int Value);
	HIDESBASE void __fastcall SetBorderStyle(const Vcl::Forms::TBorderStyle Value);
	void __fastcall SetFocusedAccessibleObject(Dxnavbarbase::_di_IdxNavBarAccessibilityHelper Value);
	System::Uitypes::TCursor __fastcall GetDragCopyCursor(void);
	System::Uitypes::TCursor __fastcall GetHotTrackedGroupCursor(void);
	System::Uitypes::TCursor __fastcall GetHotTrackedLinkCursor(void);
	void __fastcall SetCursors(TdxNavBarCursors* Value);
	void __fastcall SetDragCopyCursor(System::Uitypes::TCursor Value);
	void __fastcall SetHotTrackedGroupCursor(System::Uitypes::TCursor Value);
	void __fastcall SetHotTrackedLinkCursor(System::Uitypes::TCursor Value);
	void __fastcall CheckViewReal(void);
	bool __fastcall IsViewRealStored(void);
	bool __fastcall IsViewStored(void);
	TdxNavBarPainter* __fastcall GetViewStyle(void);
	void __fastcall SetLookAndFeelSchemes(TdxNavBarLookAndFeelSchemes* const Value);
	void __fastcall SetViewReal(int Value);
	void __fastcall SetView(int Value);
	void __fastcall SetViewStyle(TdxNavBarPainter* Value);
	void __fastcall UpdateViewReal(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetLargeImages(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetSmallImages(void);
	void __fastcall SetOptionsImage(TdxNavBarImageOptions* Value);
	void __fastcall SetLargeImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetSmallImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetOptionsView(TdxNavBarViewOptions* Value);
	void __fastcall SetOptionsBehavior(TdxNavBarBehaviorOptions* Value);
	TdxNavBarDragDropFlags __fastcall GetDragDropFlags(void);
	bool __fastcall GetShowGroupCaptions(void);
	bool __fastcall GetShowGroupsHint(void);
	bool __fastcall GetShowLinksHint(void);
	void __fastcall SetDragDropFlags(TdxNavBarDragDropFlags Value);
	void __fastcall SetShowGroupsHint(const bool Value);
	void __fastcall SetShowLinksHint(const bool Value);
	void __fastcall SetShowGroupCaptions(bool Value);
	bool __fastcall GetShowSpecialGroup(void);
	int __fastcall GetSpaceBetweenGroups(void);
	void __fastcall SetShowSpecialGroup(const bool Value);
	void __fastcall SetSpaceBetweenGroups(int Value);
	bool __fastcall GetAllowSelectLinks(void);
	bool __fastcall GetEachGroupHasSelectedLink(void);
	void __fastcall SetAllowSelectLinks(const bool Value);
	void __fastcall SetEachGroupHasSelectedLink(const bool Value);
	int __fastcall GetNavigationPaneMaxVisibleGroups(void);
	bool __fastcall GetNavigationPaneOverflowPanelUseSmallImages(void);
	bool __fastcall GetShowNavigationPaneOverflowPanelHints(void);
	void __fastcall SetNavigationPaneMaxVisibleGroups(int Value);
	void __fastcall SetNavigationPaneOverflowPanelUseSmallImages(const bool Value);
	void __fastcall SetShowNavigationPaneOverflowPanelHints(const bool Value);
	TdxNavBarCustomDrawEvent __fastcall GetOnCustomDrawBackground(void);
	TdxNavBarCustomDrawEvent __fastcall GetOnCustomDrawBottomScrollButton(void);
	TdxNavBarCustomDrawGroupEvent __fastcall GetOnCustomDrawGroupCaption(void);
	TdxNavBarCustomDrawGroupEvent __fastcall GetOnCustomDrawGroupClientBackground(void);
	TdxNavBarCustomDrawGroupEvent __fastcall GetOnCustomDrawGroupClientForeground(void);
	TdxNavBarCustomDrawGroupHintEvent __fastcall GetOnCustomDrawGroupHint(void);
	TdxNavBarCustomDrawLinkEvent __fastcall GetOnCustomDrawLink(void);
	TdxNavBarCustomDrawLinkHintEvent __fastcall GetOnCustomDrawLinkHint(void);
	TdxNavBarCustomDrawEvent __fastcall GetOnCustomDrawNavigationPaneHeader(void);
	TdxNavBarCustomDrawEvent __fastcall GetOnCustomDrawNavigationPaneOverflowPanel(void);
	TdxNavBarCustomDrawGroupHintEvent __fastcall GetOnCustomDrawNavigationPaneOverflowPanelHint(void);
	TdxNavBarCustomDrawEvent __fastcall GetOnCustomDrawNavigationPaneSplitter(void);
	TdxNavBarCustomDrawEvent __fastcall GetOnCustomDrawTopScrollButton(void);
	void __fastcall SetOnCustomDraw(TdxNavBarCustomDrawEvents* Value);
	void __fastcall SetOnCustomDrawBackground(const TdxNavBarCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawBottomScrollButton(const TdxNavBarCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawGroupCaption(const TdxNavBarCustomDrawGroupEvent Value);
	void __fastcall SetOnCustomDrawGroupClientBackground(const TdxNavBarCustomDrawGroupEvent Value);
	void __fastcall SetOnCustomDrawGroupClientForeground(const TdxNavBarCustomDrawGroupEvent Value);
	void __fastcall SetOnCustomDrawGroupHint(const TdxNavBarCustomDrawGroupHintEvent Value);
	void __fastcall SetOnCustomDrawLink(const TdxNavBarCustomDrawLinkEvent Value);
	void __fastcall SetOnCustomDrawLinkHint(const TdxNavBarCustomDrawLinkHintEvent Value);
	void __fastcall SetOnCustomDrawNavigationPaneHeader(const TdxNavBarCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawNavigationPaneOverflowPanel(const TdxNavBarCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawNavigationPaneOverflowPanelHint(const TdxNavBarCustomDrawGroupHintEvent Value);
	void __fastcall SetOnCustomDrawNavigationPaneSplitter(const TdxNavBarCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawTopScrollButton(const TdxNavBarCustomDrawEvent Value);
	Dxnavbarstyles::TdxNavBarDefaultStyles* __fastcall GetDefaultStyles(void);
	Dxnavbarstyles::TdxNavBarStyleItem* __fastcall GetNavBarCustomStyle(int Index);
	Dxnavbarstyles::TdxNavBarStyleRepository* __fastcall GetStyles(void);
	void __fastcall SetDefaultStyles(Dxnavbarstyles::TdxNavBarDefaultStyles* Value);
	void __fastcall SetNavBarCustomStyle(int Index, Dxnavbarstyles::TdxNavBarStyleItem* const Value);
	void __fastcall SetOptionsStyle(Dxnavbarstyles::TdxNavBarStyleOptions* Value);
	void __fastcall DragDone(void);
	bool __fastcall IsAllowDragLink(void);
	bool __fastcall IsAllowDropLink(void);
	bool __fastcall IsAllowDragGroup(void);
	bool __fastcall IsAllowDropGroup(void);
	void __fastcall OnGroupsChanged(System::TObject* Sender, Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall OnItemsChanged(System::TObject* Sender, Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall OnStylesChanged(System::TObject* Sender);
	void __fastcall OnImagesChanged(System::TObject* Sender);
	void __fastcall OnLinksChanged(System::TObject* Sender, Dxnavbarcollns::TdxNavBarItemLink* ALink);
	void __fastcall OnThemeChanged(void);
	void __fastcall DoActivateGroupTimer(System::TObject* Sender);
	void __fastcall DoScrollTimer(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Msg);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Winapi::Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	
protected:
	Cxclasses::_di_IcxDesignHelper FDesignHelper;
	virtual void __fastcall AccessibleObjectOwnerObjectDestroyedNotification(System::TObject* Sender);
	DYNAMIC void __fastcall BoundsChanged(void);
	void __fastcall CheckBounds(int &ALeft, int &ATop, int &AWidth, int &AHeight);
	void __fastcall CheckCollapseState(void);
	void __fastcall CheckFocusedAccessibleObject(void);
	void __fastcall CollapseStateChanged(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual System::Types::TRect __fastcall GetClientOffsets(void);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	int __fastcall GetViewReal(void);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual bool __fastcall HasNonClientArea(void);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl)/* overload */;
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall PaintNonClientArea(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall ReadOriginalWidth(System::Classes::TReader* Reader);
	virtual void __fastcall RequestAlign(void);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	void __fastcall WriteOriginalWidth(System::Classes::TWriter* Writer);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	virtual bool __fastcall CanFocusOnClick(int X, int Y)/* overload */;
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	virtual void __fastcall DoActiveGroupChanged(void);
	virtual void __fastcall DoActiveGroupChanging(Dxnavbarcollns::TdxNavBarGroup* ANewGroup, bool &AAllowChange);
	void __fastcall DoCollapseStateChanged(void);
	virtual void __fastcall DoGroupDragDrop(Dxnavbarcollns::TdxNavBarGroup* Group);
	virtual void __fastcall DoGroupDragOver(Dxnavbarcollns::TdxNavBarGroup* Group, bool &Accept);
	virtual void __fastcall DoGroupHotTrack(Dxnavbarcollns::TdxNavBarGroup* Group);
	virtual void __fastcall DoGroupMouseDown(Dxnavbarcollns::TdxNavBarGroup* Group);
	virtual void __fastcall DoGroupMouseUp(Dxnavbarcollns::TdxNavBarGroup* Group);
	virtual void __fastcall DoLinkDragDrop(Dxnavbarcollns::TdxNavBarItemLink* Link);
	virtual void __fastcall DoLinkDragOver(Dxnavbarcollns::TdxNavBarItemLink* Link, bool &Accept);
	virtual void __fastcall DoLinkHotTrack(Dxnavbarcollns::TdxNavBarItemLink* Link);
	virtual void __fastcall DoLinkMouseDown(Dxnavbarcollns::TdxNavBarItemLink* Link);
	virtual void __fastcall DoLinkMouseUp(Dxnavbarcollns::TdxNavBarItemLink* Link);
	void __fastcall DoNavigationPaneCollapsed(void);
	void __fastcall DoNavigationPaneExpanded(void);
	virtual void __fastcall DoItemDragDrop(Dxnavbarcollns::TdxNavBarItem* Item);
	virtual void __fastcall DoItemDragOver(Dxnavbarcollns::TdxNavBarItem* Item, bool &Accept);
	virtual void __fastcall DoBottomScrollButtonDown(void);
	virtual void __fastcall DoBottomScrollButtonUp(void);
	virtual void __fastcall DoTopScrollButtonDown(void);
	virtual void __fastcall DoTopScrollButtonUp(void);
	virtual void __fastcall DoUpdateScrollBarStyle(void);
	void __fastcall DoScroll(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	virtual void __fastcall Paint(void);
	void __fastcall InvalidateScrollButtons(void);
	virtual void __fastcall LoadFromRegIni(System::Inifiles::TCustomIniFile* AStorage, bool LoadStyles);
	virtual void __fastcall SaveToRegIni(System::Inifiles::TCustomIniFile* AStorage, bool SaveStyles);
	virtual TdxNavBarPainter* __fastcall CreatePainter(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual TdxNavBarCustomizationClass __fastcall GetCustomizationClass(void);
	virtual Dxnavbarcollns::TdxNavBarGroupClass __fastcall GetGroupClass(void);
	virtual Dxnavbarcollns::TdxNavBarItemClass __fastcall GetItemClass(void);
	bool __fastcall IsCollapsed(void);
	virtual TdxCustomNavBar* __fastcall GetMasterNavBar(void);
	virtual bool __fastcall IsInternal(void);
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FocusedAccessibleObject = {read=FFocusedAccessibleObject, write=SetFocusedAccessibleObject};
	__property int UpdateLock = {read=FUpdateLock, nodefault};
	__property int OriginalWidth = {read=FOriginalWidth, write=FOriginalWidth, nodefault};
	__property System::Classes::TNotifyEvent OnCollapseStateChanged = {read=FOnCollapseStateChanged, write=FOnCollapseStateChanged};
	
public:
	__fastcall virtual TdxCustomNavBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomNavBar(void);
	DYNAMIC bool __fastcall CanFocus(void);
	void __fastcall DeSelectLinks(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual void __fastcall InitiateAction(void);
	virtual void __fastcall Invalidate(void);
	void __fastcall InvalidateAll(Dxnavbarbase::TdxNavBarChangeType AType)/* overload */;
	void __fastcall InvalidateAll(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction)/* overload */;
	void __fastcall AssignDefaultStyles(void);
	void __fastcall LoadFromIniFile(System::UnicodeString AFileName, bool LoadStyles = true);
	void __fastcall LoadFromRegistry(System::UnicodeString ARegistryPath, bool LoadStyles = true);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream, bool LoadStyles = true);
	void __fastcall SaveToIniFile(System::UnicodeString AFileName, bool SaveStyles = true);
	void __fastcall SaveToRegistry(System::UnicodeString ARegistryPath, bool SaveStyles = true);
	void __fastcall SaveToStream(System::Classes::TStream* AStream, bool SaveStyles = true);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroupAtCaptionPos(const System::Types::TPoint pt);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroupAtItemsPos(const System::Types::TPoint pt);
	virtual Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetLinkAtPos(const System::Types::TPoint pt);
	Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetLinkAtSelectedPos(const System::Types::TPoint pt);
	bool __fastcall IsPtGroupDesignRect(const System::Types::TPoint pt);
	bool __fastcall IsPtItemDesignRect(const System::Types::TPoint pt);
	bool __fastcall IsPtTopScrollButton(const System::Types::TPoint pt);
	bool __fastcall IsPtBottomScrollButton(const System::Types::TPoint pt);
	bool __fastcall IsTopScrollButtonVisible(void);
	bool __fastcall IsBottomScrollButtonVisible(void);
	void __fastcall MakeLinkVisible(Dxnavbarcollns::TdxNavBarItemLink* ALink);
	void __fastcall MakeGroupVisible(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	bool __fastcall CanDecNavigationPaneOverflowPanelItemCount(void);
	bool __fastcall CanIncNavigationPaneOverflowPanelItemCount(void);
	void __fastcall DoDecNavigationPaneOverflowPanelItemCount(void);
	void __fastcall DoIncNavigationPaneOverflowPanelItemCount(void);
	bool __fastcall DesignerIsSelected(System::Classes::TPersistent* AObject);
	void __fastcall DesignerModified(void);
	void __fastcall DesignerSelect(System::Classes::TPersistent* AObject);
	void __fastcall DesignSelectionChanged(System::Classes::TList* ASelection);
	virtual void __fastcall TranslationChanged(void);
	__property TdxNavBarController* Controller = {read=GetController};
	__property TdxNavBarCustomization* Customization = {read=FCustomization};
	__property TdxNavBarPainter* Painter = {read=GetPainter};
	__property TdxNavBarViewInfo* ViewInfo = {read=GetViewInfo};
	__property bool EnableDragging = {read=GetEnableDragging, nodefault};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property TdxNavBarScrollBar* ScrollBar = {read=FScrollBar};
	__property System::Types::TPoint SourcePoint = {read=FSourcePoint};
	__property Dxnavbarcollns::TdxNavBarGroup* SourceGroup = {read=GetSourceGroup};
	__property Dxnavbarcollns::TdxNavBarItemLink* SourceLink = {read=GetSourceLink};
	__property Dxnavbarcollns::TdxNavBarItem* SourceItem = {read=GetSourceItem};
	__property System::Types::TPoint TargetPoint = {read=FTargetPoint};
	__property Dxnavbarcollns::TdxNavBarGroup* TargetGroup = {read=GetTargetGroup};
	__property Dxnavbarcollns::TdxNavBarItemLink* TargetLink1 = {read=GetTargetLink1};
	__property Dxnavbarcollns::TdxNavBarItemLink* TargetLink2 = {read=GetTargetLink2};
	__property int TargetLinkIndex = {read=GetTargetLinkIndex, nodefault};
	__property Dxnavbarcollns::TdxNavBarGroup* HotTrackedGroup = {read=FHotTrackedGroup};
	__property Dxnavbarcollns::TdxNavBarItemLink* HotTrackedLink = {read=FHotTrackedLink};
	__property Dxnavbarcollns::TdxNavBarGroup* PressedGroup = {read=FPressedGroup};
	__property Dxnavbarcollns::TdxNavBarItemLink* PressedLink = {read=FPressedLink};
	__property int NavigationPaneOverflowPanelItemCount = {read=GetNavigationPaneOverflowPanelItemCount, nodefault};
	__property bool ScrollButtonDownIsDown = {read=FScrollButtonDownIsDown, nodefault};
	__property bool ScrollButtonUpIsDown = {read=FScrollButtonUpIsDown, nodefault};
	__property int ScrollPosition = {read=GetScrollPosition, nodefault};
	__property int ActiveGroupIndex = {read=GetActiveGroupIndex, write=SetActiveGroupIndex, nodefault};
	__property Dxnavbarcollns::TdxNavBarGroup* ActiveGroup = {read=GetActiveGroup, write=SetActiveGroup};
	__property Dxnavbarcollns::TdxNavBarGroups* Groups = {read=FGroups};
	__property Dxnavbarcollns::TdxNavBarItems* Items = {read=FItems};
	__property int VisibleGroupCount = {read=GetVisibleGroupCount, nodefault};
	__property TdxNavBarCursors* Cursors = {read=FCursors, write=SetCursors};
	__property System::Uitypes::TCursor DragCopyCursor = {read=GetDragCopyCursor, write=SetDragCopyCursor, nodefault};
	__property System::Uitypes::TCursor HotTrackedGroupCursor = {read=GetHotTrackedGroupCursor, write=SetHotTrackedGroupCursor, nodefault};
	__property System::Uitypes::TCursor HotTrackedLinkCursor = {read=GetHotTrackedLinkCursor, write=SetHotTrackedLinkCursor, nodefault};
	__property TdxNavBarLookAndFeelSchemes* LookAndFeelSchemes = {read=FLookAndFeelSchemes, write=SetLookAndFeelSchemes};
	__property int View = {read=FView, write=SetView, stored=IsViewStored, nodefault};
	__property int ViewReal = {read=FViewReal, write=SetViewReal, stored=IsViewRealStored, nodefault};
	__property TdxNavBarPainter* ViewStyle = {read=GetViewStyle, write=SetViewStyle};
	__property TdxNavBarImageOptions* OptionsImage = {read=FOptionsImage, write=SetOptionsImage};
	__property Vcl::Imglist::TCustomImageList* LargeImages = {read=GetLargeImages, write=SetLargeImages};
	__property Vcl::Imglist::TCustomImageList* SmallImages = {read=GetSmallImages, write=SetSmallImages};
	__property Dxnavbarstyles::TdxNavBarStyleOptions* OptionsStyle = {read=FOptionsStyle, write=SetOptionsStyle};
	__property Dxnavbarstyles::TdxNavBarDefaultStyles* DefaultStyles = {read=GetDefaultStyles, write=SetDefaultStyles};
	__property Dxnavbarstyles::TdxNavBarStyleRepository* Styles = {read=GetStyles};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleBackground = {read=GetNavBarCustomStyle, write=SetNavBarCustomStyle, index=0};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleHint = {read=GetNavBarCustomStyle, write=SetNavBarCustomStyle, index=1};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleDropTargetGroup = {read=GetNavBarCustomStyle, write=SetNavBarCustomStyle, index=2};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleDropTargetLink = {read=GetNavBarCustomStyle, write=SetNavBarCustomStyle, index=3};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleButton = {read=GetNavBarCustomStyle, write=SetNavBarCustomStyle, index=4};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleButtonHotTracked = {read=GetNavBarCustomStyle, write=SetNavBarCustomStyle, index=5};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleButtonPressed = {read=GetNavBarCustomStyle, write=SetNavBarCustomStyle, index=6};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleNavigationPaneHeader = {read=GetNavBarCustomStyle, write=SetNavBarCustomStyle, index=7};
	__property TdxNavBarViewOptions* OptionsView = {read=FOptionsView, write=SetOptionsView};
	__property TdxNavBarBehaviorOptions* OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior};
	__property TdxNavBarDragDropFlags DragDropFlags = {read=GetDragDropFlags, write=SetDragDropFlags, nodefault};
	__property bool ShowGroupsHint = {read=GetShowGroupsHint, write=SetShowGroupsHint, nodefault};
	__property bool ShowLinksHint = {read=GetShowLinksHint, write=SetShowLinksHint, nodefault};
	__property bool ShowGroupCaptions = {read=GetShowGroupCaptions, write=SetShowGroupCaptions, nodefault};
	__property bool ShowSpecialGroup = {read=GetShowSpecialGroup, write=SetShowSpecialGroup, nodefault};
	__property int SpaceBetweenGroups = {read=GetSpaceBetweenGroups, write=SetSpaceBetweenGroups, nodefault};
	__property bool AllowSelectLinks = {read=GetAllowSelectLinks, write=SetAllowSelectLinks, nodefault};
	__property bool EachGroupHasSelectedLink = {read=GetEachGroupHasSelectedLink, write=SetEachGroupHasSelectedLink, nodefault};
	__property int NavigationPaneMaxVisibleGroups = {read=GetNavigationPaneMaxVisibleGroups, write=SetNavigationPaneMaxVisibleGroups, nodefault};
	__property bool NavigationPaneOverflowPanelUseSmallImages = {read=GetNavigationPaneOverflowPanelUseSmallImages, write=SetNavigationPaneOverflowPanelUseSmallImages, nodefault};
	__property bool ShowNavigationPaneOverflowPanelHints = {read=GetShowNavigationPaneOverflowPanelHints, write=SetShowNavigationPaneOverflowPanelHints, nodefault};
	__property System::Classes::TNotifyEvent OnActiveGroupChanged = {read=FOnActiveGroupChanged, write=FOnActiveGroupChanged};
	__property TdxNavBarGroupChangingEvent OnActiveGroupChanging = {read=FOnActiveGroupChanging, write=FOnActiveGroupChanging};
	__property TdxNavBarCalcGroupClientHeightEvent OnCalcGroupClientHeight = {read=FOnCalcGroupClientHeight, write=FOnCalcGroupClientHeight};
	__property TdxNavBarCalcGroupHintRectEvent OnCalcGroupHintRect = {read=FOnCalcGroupHintRect, write=FOnCalcGroupHintRect};
	__property TdxNavBarCalcLinkHintRectEvent OnCalcLinkHintRect = {read=FOnCalcLinkHintRect, write=FOnCalcLinkHintRect};
	__property TdxNavBarCalcGroupHintRectEvent OnCalcNavigationPaneOverflowPanelHintRect = {read=FOnCalcNavigationPaneOverflowPanelHintRect, write=FOnCalcNavigationPaneOverflowPanelHintRect};
	__property TdxNavBarCustomDrawEvents* OnCustomDraw = {read=FOnCustomDraw, write=SetOnCustomDraw};
	__property TdxNavBarCustomDrawEvent OnCustomDrawBackground = {read=GetOnCustomDrawBackground, write=SetOnCustomDrawBackground};
	__property TdxNavBarCustomDrawGroupEvent OnCustomDrawGroupCaption = {read=GetOnCustomDrawGroupCaption, write=SetOnCustomDrawGroupCaption};
	__property TdxNavBarCustomDrawGroupEvent OnCustomDrawGroupClientBackground = {read=GetOnCustomDrawGroupClientBackground, write=SetOnCustomDrawGroupClientBackground};
	__property TdxNavBarCustomDrawGroupEvent OnCustomDrawGroupClientForeground = {read=GetOnCustomDrawGroupClientForeground, write=SetOnCustomDrawGroupClientForeground};
	__property TdxNavBarCustomDrawGroupHintEvent OnCustomDrawGroupHint = {read=GetOnCustomDrawGroupHint, write=SetOnCustomDrawGroupHint};
	__property TdxNavBarCustomDrawLinkEvent OnCustomDrawLink = {read=GetOnCustomDrawLink, write=SetOnCustomDrawLink};
	__property TdxNavBarCustomDrawLinkHintEvent OnCustomDrawLinkHint = {read=GetOnCustomDrawLinkHint, write=SetOnCustomDrawLinkHint};
	__property TdxNavBarCustomDrawEvent OnCustomDrawBottomScrollButton = {read=GetOnCustomDrawBottomScrollButton, write=SetOnCustomDrawBottomScrollButton};
	__property TdxNavBarCustomDrawEvent OnCustomDrawTopScrollButton = {read=GetOnCustomDrawTopScrollButton, write=SetOnCustomDrawTopScrollButton};
	__property TdxNavBarCustomDrawEvent OnCustomDrawNavigationPaneHeader = {read=GetOnCustomDrawNavigationPaneHeader, write=SetOnCustomDrawNavigationPaneHeader};
	__property TdxNavBarCustomDrawEvent OnCustomDrawNavigationPaneSplitter = {read=GetOnCustomDrawNavigationPaneSplitter, write=SetOnCustomDrawNavigationPaneSplitter};
	__property TdxNavBarCustomDrawEvent OnCustomDrawNavigationPaneOverflowPanel = {read=GetOnCustomDrawNavigationPaneOverflowPanel, write=SetOnCustomDrawNavigationPaneOverflowPanel};
	__property TdxNavBarCustomDrawGroupHintEvent OnCustomDrawNavigationPaneOverflowPanelHint = {read=GetOnCustomDrawNavigationPaneOverflowPanelHint, write=SetOnCustomDrawNavigationPaneOverflowPanelHint};
	__property System::Classes::TNotifyEvent OnNavigationPaneCollapsed = {read=FOnNavigationPaneCollapsed, write=FOnNavigationPaneCollapsed};
	__property System::Classes::TNotifyEvent OnNavigationPaneExpanded = {read=FOnNavigationPaneExpanded, write=FOnNavigationPaneExpanded};
	__property TdxNavBarGetGroupHintEvent OnGetGroupHint = {read=FOnGetGroupHint, write=FOnGetGroupHint};
	__property TdxNavBarGetLinkHintEvent OnGetLinkHint = {read=FOnGetLinkHint, write=FOnGetLinkHint};
	__property TdxNavBarGroupEvent OnGroupClick = {read=FOnGroupClick, write=FOnGroupClick};
	__property TdxNavBarGroupEvent OnGroupHotTrack = {read=FOnGroupHotTrack, write=FOnGroupHotTrack};
	__property TdxNavBarGroupEvent OnGroupPress = {read=FOnGroupPress, write=FOnGroupPress};
	__property TdxNavBarLinkEvent OnLinkClick = {read=FOnLinkClick, write=FOnLinkClick};
	__property TdxNavBarLinkEvent OnLinkHotTrack = {read=FOnLinkHotTrack, write=FOnLinkHotTrack};
	__property TdxNavBarLinkEvent OnLinkPress = {read=FOnLinkPress, write=FOnLinkPress};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Vcl::Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property Enabled = {default=1};
	__property Font;
	__property PopupMenu;
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomNavBar(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(void){ return Cxcontrols::TcxControl::CanFocusOnClick(); }
	
private:
	void *__IcxDesignSelectionChanged;	/* Cxclasses::IcxDesignSelectionChanged */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {66B3AA59-1EBD-4135-AB18-E980F9C970F3}
	operator Cxclasses::_di_IcxDesignSelectionChanged()
	{
		Cxclasses::_di_IcxDesignSelectionChanged intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxclasses::IcxDesignSelectionChanged*(void) { return (Cxclasses::IcxDesignSelectionChanged*)&__IcxDesignSelectionChanged; }
	#endif
	
};


class DELPHICLASS TdxNavBarDragObject;
class PASCALIMPLEMENTATION TdxNavBarDragObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomNavBar* FNavBar;
	Dxnavbarcollns::TdxNavBarGroup* FSourceGroup;
	Dxnavbarcollns::TdxNavBarItemLink* FSourceLink;
	Dxnavbarcollns::TdxNavBarItem* FSourceItem;
	Dxnavbarcollns::TdxNavBarGroup* FTargetGroup;
	Dxnavbarcollns::TdxNavBarItemLink* FTargetLink1;
	Dxnavbarcollns::TdxNavBarItemLink* FTargetLink2;
	int FTargetLinkIndex;
	Dxnavbarcollns::TdxNavBarItem* __fastcall GetSourceItem(void);
	
protected:
	virtual void __fastcall UpdateTargets(void);
	
public:
	__fastcall TdxNavBarDragObject(TdxCustomNavBar* ANavBar, Vcl::Controls::TDragObject* &DragObject, Dxnavbarcollns::TdxNavBarGroup* ASourceGroup, Dxnavbarcollns::TdxNavBarItemLink* ASourceLink, Dxnavbarcollns::TdxNavBarItem* ASourceItem);
	__property TdxCustomNavBar* NavBar = {read=FNavBar};
	__property Dxnavbarcollns::TdxNavBarGroup* SourceGroup = {read=FSourceGroup};
	__property Dxnavbarcollns::TdxNavBarItemLink* SourceLink = {read=FSourceLink};
	__property Dxnavbarcollns::TdxNavBarItem* SourceItem = {read=GetSourceItem};
	__property Dxnavbarcollns::TdxNavBarGroup* TargetGroup = {read=FTargetGroup};
	__property Dxnavbarcollns::TdxNavBarItemLink* TargetLink1 = {read=FTargetLink1};
	__property Dxnavbarcollns::TdxNavBarItemLink* TargetLink2 = {read=FTargetLink2};
	__property int TargetLinkIndex = {read=FTargetLinkIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarDragObject(void) { }
	
};


class PASCALIMPLEMENTATION TdxNavBarScrollBar : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Vcl::Forms::TScrollBarKind FKind;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	Vcl::Controls::TWinControl* FParent;
	Cxcontrols::TcxControlScrollBarHelper* FScrollBar;
	tagSCROLLINFO FScrollInfo;
	int FLargeChange;
	int FSmallChange;
	Vcl::Stdctrls::TScrollEvent FOnScroll;
	void __fastcall CorrectPos(int &APos, int AMin, int AMax, int APageSize);
	System::Types::TRect __fastcall GetBounds(void);
	int __fastcall GetHeight(void);
	int __fastcall GetMax(void);
	int __fastcall GetMin(void);
	TdxNavBarPainter* __fastcall GetNavBarPainter(void);
	int __fastcall GetPageSize(void);
	int __fastcall GetPosition(void);
	bool __fastcall GetVisible(void);
	int __fastcall GetWidth(void);
	void __fastcall SetBounds(const System::Types::TRect &AValue);
	void __fastcall SetMax(const int Value);
	void __fastcall SetMin(const int Value);
	void __fastcall SetPageSize(const int Value);
	void __fastcall SetPosition(const int Value);
	void __fastcall SetVisible(const bool Value);
	void __fastcall DestroyInternalScrollBar(void);
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall VisibleChanged(void);
	
protected:
	void __fastcall CheckScrollBarClass(void);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall RecreatecxScrollBar(void);
	void __fastcall ResetScrollInfo(void);
	void __fastcall Scroll(System::TObject* Sender, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall UpdateStyle(void);
	Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel};
	__property TdxNavBarPainter* NavBarPainter = {read=GetNavBarPainter};
	__property Cxcontrols::TcxControlScrollBarHelper* ScrollBar = {read=FScrollBar};
	
public:
	__fastcall TdxNavBarScrollBar(Vcl::Controls::TWinControl* AParent, Vcl::Forms::TScrollBarKind AKind);
	__fastcall virtual ~TdxNavBarScrollBar(void);
	void __fastcall SetScrollParams(int AMin, int AMax, int APosition, int APageSize, bool ARedraw = true);
	__property System::Types::TRect Bounds = {read=GetBounds, write=SetBounds};
	__property int Height = {read=GetHeight, nodefault};
	__property int Max = {read=GetMax, write=SetMax, nodefault};
	__property int Min = {read=GetMin, write=SetMin, nodefault};
	__property int PageSize = {read=GetPageSize, write=SetPageSize, nodefault};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	__property int LargeChange = {read=FLargeChange, write=FLargeChange, nodefault};
	__property int SmallChange = {read=FSmallChange, write=FSmallChange, nodefault};
	__property Vcl::Stdctrls::TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
private:
	void *__IcxScrollBarOwner;	/* Cxscrollbar::IcxScrollBarOwner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {56771164-C253-40FF-B6D4-2A29D0C90236}
	operator Cxscrollbar::_di_IcxScrollBarOwner()
	{
		Cxscrollbar::_di_IcxScrollBarOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxscrollbar::IcxScrollBarOwner*(void) { return (Cxscrollbar::IcxScrollBarOwner*)&__IcxScrollBarOwner; }
	#endif
	
};


class PASCALIMPLEMENTATION TdxNavBarHintWindow : public Dxcustomhint::TcxBaseHintWindow
{
	typedef Dxcustomhint::TcxBaseHintWindow inherited;
	
protected:
	TdxCustomNavBar* FNavBar;
	virtual void __fastcall Paint(void);
	
public:
	virtual System::Types::TRect __fastcall CalcHintRect(int MaxWidth, const System::UnicodeString AHint, void * AData);
public:
	/* TcxBaseHintWindow.Create */ inline __fastcall virtual TdxNavBarHintWindow(System::Classes::TComponent* AOwner) : Dxcustomhint::TcxBaseHintWindow(AOwner) { }
	/* TcxBaseHintWindow.Destroy */ inline __fastcall virtual ~TdxNavBarHintWindow(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxNavBarHintWindow(HWND ParentWindow) : Dxcustomhint::TcxBaseHintWindow(ParentWindow) { }
	
};


class DELPHICLASS TdxNavBar;
class PASCALIMPLEMENTATION TdxNavBar : public TdxCustomNavBar
{
	typedef TdxCustomNavBar inherited;
	
private:
	System::Classes::TNotifyEvent FCustomDrawEvents;
	
__published:
	__property ActiveGroupIndex;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Cursors;
	__property Cursor = {stored=false, default=0};
	__property DragCopyCursor = {stored=false};
	__property DragCursor = {stored=false, default=-12};
	__property HotTrackedGroupCursor = {stored=false};
	__property HotTrackedLinkCursor = {stored=false};
	__property LookAndFeel;
	__property LookAndFeelSchemes;
	__property View;
	__property ViewReal;
	__property ViewStyle;
	__property OptionsBehavior;
	__property OptionsImage;
	__property OptionsStyle;
	__property OptionsView;
	__property DragDropFlags = {stored=false};
	__property ShowGroupsHint = {stored=false};
	__property ShowLinksHint = {stored=false};
	__property ShowGroupCaptions = {stored=false};
	__property ShowSpecialGroup = {stored=false};
	__property SpaceBetweenGroups = {stored=false};
	__property AllowSelectLinks = {stored=false};
	__property EachGroupHasSelectedLink = {stored=false};
	__property NavigationPaneMaxVisibleGroups = {stored=false};
	__property NavigationPaneOverflowPanelUseSmallImages = {stored=false};
	__property ShowNavigationPaneOverflowPanelHints = {stored=false};
	__property LargeImages = {stored=false};
	__property SmallImages = {stored=false};
	__property DefaultStyles = {stored=false};
	__property StyleBackground = {stored=false, index=0};
	__property StyleHint = {stored=false, index=1};
	__property StyleDropTargetGroup = {stored=false, index=2};
	__property StyleDropTargetLink = {stored=false, index=3};
	__property StyleButton = {stored=false, index=4};
	__property StyleButtonHotTracked = {stored=false, index=5};
	__property StyleButtonPressed = {stored=false, index=6};
	__property StyleNavigationPaneHeader = {stored=false, index=7};
	__property OnActiveGroupChanged;
	__property OnActiveGroupChanging;
	__property OnCalcGroupClientHeight;
	__property OnCalcGroupHintRect;
	__property OnCalcNavigationPaneOverflowPanelHintRect;
	__property OnCalcLinkHintRect;
	__property OnCustomDraw;
	__property System::Classes::TNotifyEvent CustomDrawEvents = {read=FCustomDrawEvents, write=FCustomDrawEvents};
	__property OnCustomDrawBackground = {stored=false};
	__property OnCustomDrawGroupCaption = {stored=false};
	__property OnCustomDrawGroupClientBackground = {stored=false};
	__property OnCustomDrawGroupClientForeground = {stored=false};
	__property OnCustomDrawGroupHint = {stored=false};
	__property OnCustomDrawLink = {stored=false};
	__property OnCustomDrawLinkHint = {stored=false};
	__property OnCustomDrawBottomScrollButton = {stored=false};
	__property OnCustomDrawTopScrollButton = {stored=false};
	__property OnCustomDrawNavigationPaneHeader = {stored=false};
	__property OnCustomDrawNavigationPaneSplitter = {stored=false};
	__property OnCustomDrawNavigationPaneOverflowPanel = {stored=false};
	__property OnCustomDrawNavigationPaneOverflowPanelHint = {stored=false};
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDrag;
	__property OnGetGroupHint;
	__property OnGetLinkHint;
	__property OnGroupClick;
	__property OnGroupHotTrack;
	__property OnGroupPress;
	__property OnLinkClick;
	__property OnLinkHotTrack;
	__property OnLinkPress;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnNavigationPaneCollapsed;
	__property OnNavigationPaneExpanded;
	__property OnStartDrag;
public:
	/* TdxCustomNavBar.Create */ inline __fastcall virtual TdxNavBar(System::Classes::TComponent* AOwner) : TdxCustomNavBar(AOwner) { }
	/* TdxCustomNavBar.Destroy */ inline __fastcall virtual ~TdxNavBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxNavBar(HWND ParentWindow) : TdxCustomNavBar(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 nbNone = System::Int8(-1);
#define dxNavBarDefaultDragDropFlags (System::Set<TdxNavBarDragDropFlag, TdxNavBarDragDropFlag::fAllowDragLink, TdxNavBarDragDropFlag::fAllowDropGroup> () << TdxNavBarDragDropFlag::fAllowDragLink << TdxNavBarDragDropFlag::fAllowDropLink << TdxNavBarDragDropFlag::fAllowDragGroup << TdxNavBarDragDropFlag::fAllowDropGroup )
static const System::Int8 dxNavBarHintWindowSizeCorrection = System::Int8(0x6);
extern PACKAGE System::Types::TPoint dxNavBarHintWindowTextOffset;
#define dxNavBarAllCategories (System::Set<TdxNavBarViewCategory, TdxNavBarViewCategory::nbvcExplorerBar, TdxNavBarViewCategory::nbvcSideBar> () << TdxNavBarViewCategory::nbvcExplorerBar << TdxNavBarViewCategory::nbvcSideBar )
extern PACKAGE TdxNavBarDragObject* dxNavBarDragObject;
extern PACKAGE bool DrawIconsAsEnabled;
extern PACKAGE Cxclasses::TcxNotifyProcedure FOnRegisterNavBar;
extern PACKAGE Cxclasses::TcxNotifyProcedure FOnUnRegisterNavBar;
extern PACKAGE TdxNavBarPart __fastcall dxNavBarPart(int AMajorPartIndex, int AMinorPartIndex = 0xffffffff);
extern PACKAGE bool __fastcall IsdxNavBarPartsEqual(const TdxNavBarPart APart1, const TdxNavBarPart APart2);
extern PACKAGE void __fastcall dxNavBarRegisterCustomizationFormClass(TdxNavBarCustomCustomizationFormClass AClass);
extern PACKAGE void __fastcall dxNavBarUnregisterCustomizationFormClass(TdxNavBarCustomCustomizationFormClass AClass);
}	/* namespace Dxnavbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBAR)
using namespace Dxnavbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarHPP
