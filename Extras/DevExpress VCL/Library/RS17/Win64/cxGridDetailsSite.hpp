// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridDetailsSite.pas' rev: 24.00 (Win64)

#ifndef CxgriddetailssiteHPP
#define CxgriddetailssiteHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriddetailssite
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridDetailsSiteTabHitTestClass;

class DELPHICLASS TcxGridDetailsSiteTabHitTest;
class PASCALIMPLEMENTATION TcxGridDetailsSiteTabHitTest : public Cxgridcustomview::TcxCustomGridHitTest
{
	typedef Cxgridcustomview::TcxCustomGridHitTest inherited;
	
private:
	Cxgridlevel::TcxGridLevel* FLevel;
	System::TObject* FOwner;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__property Cxgridlevel::TcxGridLevel* Level = {read=FLevel, write=FLevel};
	__property System::TObject* Owner = {read=FOwner, write=FOwner};
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridDetailsSiteTabHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridDetailsSiteTabHitTest(void) : Cxgridcustomview::TcxCustomGridHitTest() { }
	
};


class DELPHICLASS TcxGridDetailsSiteTabsPainter;
class DELPHICLASS TcxCustomGridDetailsSiteTabsViewInfo;
class PASCALIMPLEMENTATION TcxGridDetailsSiteTabsPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxCustomGridDetailsSiteTabsViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxCustomGridDetailsSiteTabsViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridDetailsSiteTabsPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDetailsSiteTabsPainter(void) { }
	
};


typedef System::TMetaClass* TcxGridDetailsSitePainterClass;

class DELPHICLASS TcxGridDetailsSitePainter;
class DELPHICLASS TcxCustomGridDetailsSiteViewInfo;
class PASCALIMPLEMENTATION TcxGridDetailsSitePainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxCustomGridDetailsSiteViewInfo* FViewInfo;
	
protected:
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawFrame(void);
	virtual void __fastcall DrawTabs(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property TcxCustomGridDetailsSiteViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxGridDetailsSitePainter(Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridDetailsSiteViewInfo* AViewInfo);
	virtual void __fastcall Paint(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDetailsSitePainter(void) { }
	
};


class DELPHICLASS TcxGridLevelTabsProperties;
class PASCALIMPLEMENTATION TcxGridLevelTabsProperties : public Cxpc::TcxCustomTabControlProperties
{
	typedef Cxpc::TcxCustomTabControlProperties inherited;
	
private:
	bool FFocusActiveViewOnChange;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	bool FUnderlineHotKeys;
	Cxgridlevel::TcxGridLevel* __fastcall GetActiveLevel(void);
	int __fastcall GetLevelCount(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetLevel(int Index);
	TcxCustomGridDetailsSiteViewInfo* __fastcall GetSiteViewInfo(void);
	void __fastcall SetActiveLevel(Cxgridlevel::TcxGridLevel* Value);
	void __fastcall SetUnderlineHotKeys(bool Value);
	
protected:
	void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	System::UnicodeString __fastcall GetLevelDisplayText(Cxgridlevel::TcxGridLevel* ALevel);
	__property bool FocusActiveViewOnChange = {read=FFocusActiveViewOnChange, write=FFocusActiveViewOnChange, nodefault};
	
public:
	__fastcall virtual TcxGridLevelTabsProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxGridLevelTabsProperties(void);
	void __fastcall AddLevel(Cxgridlevel::TcxGridLevel* ALevel);
	__property Cxgridlevel::TcxGridLevel* ActiveLevel = {read=GetActiveLevel, write=SetActiveLevel};
	__property int LevelCount = {read=GetLevelCount, nodefault};
	__property Cxgridlevel::TcxGridLevel* Levels[int Index] = {read=GetLevel};
	__property TcxCustomGridDetailsSiteViewInfo* SiteViewInfo = {read=GetSiteViewInfo};
	__property bool UnderlineHotKeys = {read=FUnderlineHotKeys, write=SetUnderlineHotKeys, nodefault};
};


class DELPHICLASS TcxGridLevelTabsController;
class PASCALIMPLEMENTATION TcxGridLevelTabsController : public Cxpc::TcxCustomTabControlController
{
	typedef Cxpc::TcxCustomTabControlController inherited;
	
private:
	HIDESBASE TcxGridLevelTabsProperties* __fastcall GetProperties(void);
	
protected:
	virtual bool __fastcall HandleDialogChar(int Key);
	virtual System::Types::TPoint __fastcall GetClientToScreen(const System::Types::TPoint APoint);
	virtual System::Types::TPoint __fastcall GetScreenToClient(const System::Types::TPoint APoint);
	__property TcxGridLevelTabsProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomTabControlController.Create */ inline __fastcall virtual TcxGridLevelTabsController(System::TObject* AOwner) : Cxpc::TcxCustomTabControlController(AOwner) { }
	/* TcxCustomTabControlController.Destroy */ inline __fastcall virtual ~TcxGridLevelTabsController(void) { }
	
};


class DELPHICLASS TcxGridLevelTabsViewInfo;
class PASCALIMPLEMENTATION TcxGridLevelTabsViewInfo : public Cxpc::TcxCustomTabControlViewInfo
{
	typedef Cxpc::TcxCustomTabControlViewInfo inherited;
	
private:
	HIDESBASE TcxGridLevelTabsController* __fastcall GetController(void);
	HIDESBASE TcxGridLevelTabsProperties* __fastcall GetProperties(void);
	TcxCustomGridDetailsSiteViewInfo* __fastcall GetSiteViewInfo(void);
	
protected:
	virtual void __fastcall AfterPaintTab(Cxgraphics::TcxCanvas* ACanvas, Cxpc::TcxTab* ATab, Cxpc::TcxPCOutTabImageAndTextData &AImageAndTextData);
	virtual bool __fastcall HasBorders(void);
	__property TcxGridLevelTabsController* Controller = {read=GetController};
	
public:
	virtual void __fastcall PrepareTabCanvasFont(Cxpc::TcxTabViewInfo* ATabViewInfo, Cxgraphics::TcxCanvas* ACanvas);
	__property TcxGridLevelTabsProperties* Properties = {read=GetProperties};
	__property TcxCustomGridDetailsSiteViewInfo* SiteViewInfo = {read=GetSiteViewInfo};
public:
	/* TcxCustomTabControlViewInfo.Create */ inline __fastcall virtual TcxGridLevelTabsViewInfo(System::TObject* AOwner) : Cxpc::TcxCustomTabControlViewInfo(AOwner) { }
	/* TcxCustomTabControlViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLevelTabsViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxCustomGridDetailsSiteTabsViewInfoClass;

class PASCALIMPLEMENTATION TcxCustomGridDetailsSiteTabsViewInfo : public Cxgridcustomview::TcxCustomGridCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridCellViewInfo inherited;
	
private:
	TcxCustomGridDetailsSiteViewInfo* FSiteViewInfo;
	TcxGridLevelTabsController* FTabsController;
	Cxpc::TcxPCCustomPainter* FTabsPainter;
	TcxGridLevelTabsProperties* FTabsProperties;
	TcxGridLevelTabsViewInfo* FTabsViewInfo;
	bool FNeedActiveLevelChanged;
	Cxgridlevel::TcxGridLevel* __fastcall GetActiveLevel(void);
	int __fastcall GetFirstTabVisibleIndex(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetLevel(void);
	void __fastcall SetFirstTabVisibleIndex(int Value);
	void __fastcall TabsPropertiesChangeHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall DoInvalidate(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual int __fastcall GetHeight(void);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual void __fastcall MouseLeave(void);
	virtual bool __fastcall PtInCaller(const System::Types::TPoint P);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	void __fastcall CheckActiveLevel(void);
	virtual void __fastcall AdjustBounds(void);
	virtual bool __fastcall AreTabsRotated(void);
	virtual System::Uitypes::TColor __fastcall GetBkColor(void);
	System::Types::TPoint __fastcall GetTabsPointFromHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	bool __fastcall GetIsVertical(void);
	Cxpc::TcxTabPosition __fastcall GetTabPosition(void);
	virtual void __fastcall InitTabs(void);
	virtual void __fastcall InitTabsData(void);
	virtual void __fastcall InitTabsHotKeyParams(void);
	virtual void __fastcall InitTabsLayout(void);
	virtual void __fastcall InitTabsStyle(void);
	virtual void __fastcall InitTabsViewParams(void);
	void __fastcall SynchronizeActiveLevel(void);
	bool __fastcall IsDesigning(void);
	HIDESBASE bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	Cxpc::TcxCustomTabControlController* __fastcall GetController(void);
	Cxpc::TcxPCCustomPainter* __fastcall GetPainter(void);
	Cxpc::TcxCustomTabControlProperties* __fastcall GetProperties(void);
	Cxpc::TcxCustomTabControlViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall CanDrawParentBackground(void);
	virtual System::Types::TRect __fastcall GetBoundsRect(void);
	Cxgraphics::TcxCanvas* __fastcall GetTabCanvas(void);
	Vcl::Controls::TWinControl* __fastcall GetTabControl(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	Cxcontrols::TcxDragAndDropObject* __fastcall GetDragAndDropObject(void);
	Cxcontrols::TcxDragAndDropState __fastcall GetDragAndDropState(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	void __fastcall InvalidateRect(const System::Types::TRect &R, bool AEraseBackground);
	void __fastcall SetModified(void);
	bool __fastcall IsEnabled(void);
	bool __fastcall IsFocused(void);
	bool __fastcall IsParentBackground(void);
	void __fastcall RequestLayout(void);
	__property int FirstTabVisibleIndex = {read=GetFirstTabVisibleIndex, write=SetFirstTabVisibleIndex, nodefault};
	__property bool IsVertical = {read=GetIsVertical, nodefault};
	__property Cxgridlevel::TcxGridLevel* Level = {read=GetLevel};
	__property TcxGridLevelTabsController* TabsController = {read=FTabsController};
	__property Cxpc::TcxPCCustomPainter* TabsPainter = {read=FTabsPainter};
	__property TcxGridLevelTabsProperties* TabsProperties = {read=FTabsProperties};
	__property TcxGridLevelTabsViewInfo* TabsViewInfo = {read=FTabsViewInfo};
	
public:
	__fastcall virtual TcxCustomGridDetailsSiteTabsViewInfo(TcxCustomGridDetailsSiteViewInfo* ASiteViewInfo);
	__fastcall virtual ~TcxCustomGridDetailsSiteTabsViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds)/* overload */;
	HIDESBASE virtual void __fastcall GetClientBounds(System::Types::TRect &AClientBounds);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall MouseMove(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	virtual bool __fastcall MouseUp(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property Cxgridlevel::TcxGridLevel* ActiveLevel = {read=GetActiveLevel};
	__property System::Uitypes::TColor BkColor = {read=GetBkColor, nodefault};
	__property TcxCustomGridDetailsSiteViewInfo* SiteViewInfo = {read=FSiteViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ALeftBound, ATopBound, AWidth, AHeight); }
	
private:
	void *__IcxControlComponentState;	/* Cxcontrols::IcxControlComponentState */
	void *__IcxTabControl;	/* Cxpc::IcxTabControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E29BF582-E8C0-4868-A799-DB4C41AC3BC8}
	operator Cxcontrols::_di_IcxControlComponentState()
	{
		Cxcontrols::_di_IcxControlComponentState intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxControlComponentState*(void) { return (Cxcontrols::IcxControlComponentState*)&__IcxControlComponentState; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8C8C2262-5419-46E1-BCE0-5A5311C330A0}
	operator Cxpc::_di_IcxTabControl()
	{
		Cxpc::_di_IcxTabControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxpc::IcxTabControl*(void) { return (Cxpc::IcxTabControl*)&__IcxTabControl; }
	#endif
	
};


class DELPHICLASS TcxGridDetailsSiteLeftTabsViewInfo;
class PASCALIMPLEMENTATION TcxGridDetailsSiteLeftTabsViewInfo : public TcxCustomGridDetailsSiteTabsViewInfo
{
	typedef TcxCustomGridDetailsSiteTabsViewInfo inherited;
	
protected:
	virtual void __fastcall AdjustBounds(void);
public:
	/* TcxCustomGridDetailsSiteTabsViewInfo.Create */ inline __fastcall virtual TcxGridDetailsSiteLeftTabsViewInfo(TcxCustomGridDetailsSiteViewInfo* ASiteViewInfo) : TcxCustomGridDetailsSiteTabsViewInfo(ASiteViewInfo) { }
	/* TcxCustomGridDetailsSiteTabsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridDetailsSiteLeftTabsViewInfo(void) { }
	
};


class DELPHICLASS TcxGridDetailsSiteTopTabsViewInfo;
class PASCALIMPLEMENTATION TcxGridDetailsSiteTopTabsViewInfo : public TcxCustomGridDetailsSiteTabsViewInfo
{
	typedef TcxCustomGridDetailsSiteTabsViewInfo inherited;
	
protected:
	virtual void __fastcall AdjustBounds(void);
public:
	/* TcxCustomGridDetailsSiteTabsViewInfo.Create */ inline __fastcall virtual TcxGridDetailsSiteTopTabsViewInfo(TcxCustomGridDetailsSiteViewInfo* ASiteViewInfo) : TcxCustomGridDetailsSiteTabsViewInfo(ASiteViewInfo) { }
	/* TcxCustomGridDetailsSiteTabsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridDetailsSiteTopTabsViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxCustomGridDetailsSiteViewInfoCachedInfoClass;

class DELPHICLASS TcxCustomGridDetailsSiteViewInfoCachedInfo;
class PASCALIMPLEMENTATION TcxCustomGridDetailsSiteViewInfoCachedInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int FirstTabVisibleIndex;
	System::Types::TRect Bounds;
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridDetailsSiteViewInfoCachedInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridDetailsSiteViewInfoCachedInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomGridDetailsSiteViewInfo : public Cxclasses::TcxComponent
{
	typedef Cxclasses::TcxComponent inherited;
	
private:
	Cxgridcustomview::TcxCustomGridView* FActiveGridView;
	bool FFullyVisible;
	Cxgridlevel::TcxGridLevel* FLevel;
	int FNormalHeight;
	TcxCustomGridDetailsSiteTabsViewInfo* FTabsViewInfo;
	int __fastcall GetClientHeight(void);
	int __fastcall GetClientWidth(void);
	Cxcontrols::TcxControl* __fastcall GetControl(void);
	System::Types::TRect __fastcall GetFrameBounds(void);
	int __fastcall GetInternalHeight(void);
	int __fastcall GetInternalWidth(void);
	bool __fastcall GetIsActiveGridViewDestroying(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	int __fastcall GetMaxDetailHeight(void);
	System::Types::TPoint __fastcall GetMaxDetailSize(void);
	int __fastcall GetMaxDetailWidth(void);
	int __fastcall GetNonClientHeight(void);
	int __fastcall GetNonClientWidth(void);
	Cxgridlevel::TcxGridDetailTabsPosition __fastcall GetTabsPosition(void);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual System::Uitypes::TColor __fastcall GetBkColor(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void) = 0 ;
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual Cxcontrols::TcxControl* __fastcall GetContainer(void) = 0 ;
	virtual Cxgridcustomview::TcxCustomGridDesignController* __fastcall GetDesignController(void) = 0 ;
	virtual int __fastcall GetEmptyClientHeight(void);
	virtual int __fastcall GetEmptyClientWidth(void);
	virtual System::Uitypes::TColor __fastcall GetFrameColor(void);
	virtual int __fastcall GetFrameWidth(void);
	virtual bool __fastcall GetFullyVisible(void);
	virtual int __fastcall GetHeight(void);
	virtual System::TObject* __fastcall GetMasterRecord(void) = 0 ;
	virtual int __fastcall GetMaxHeight(void) = 0 ;
	virtual int __fastcall GetMaxNormalHeight(void);
	virtual int __fastcall GetMaxWidth(void) = 0 ;
	virtual int __fastcall GetMinWidth(void);
	virtual int __fastcall GetNormalHeight(void);
	virtual int __fastcall GetWidth(void);
	virtual TcxGridDetailsSitePainterClass __fastcall GetPainterClass(void);
	virtual TcxCustomGridDetailsSiteTabsViewInfoClass __fastcall GetTabsViewInfoClass(void);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveGridView(void) = 0 ;
	virtual bool __fastcall GetActiveGridViewExists(void);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveGridViewValue(void);
	virtual Cxgridlevel::TcxGridLevel* __fastcall GetActiveLevel(void) = 0 ;
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall GetLevelTabDefaultParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetLevelTabParams(Cxgridlevel::TcxGridLevel* ALevel, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall InitTabHitTest(TcxGridDetailsSiteTabHitTest* AHitTest) = 0 ;
	virtual void __fastcall GetCachedInfo(TcxCustomGridDetailsSiteViewInfoCachedInfo* &AInfo);
	virtual TcxCustomGridDetailsSiteViewInfoCachedInfoClass __fastcall GetCachedInfoClass(void);
	virtual void __fastcall SetCachedInfo(TcxCustomGridDetailsSiteViewInfoCachedInfo* &AInfo);
	void __fastcall CreateTabsViewInfo(void);
	__property Cxgridcustomview::TcxCustomGridView* ActiveGridView = {read=GetActiveGridViewValue};
	__property bool ActiveGridViewExists = {read=GetActiveGridViewExists, nodefault};
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property int ClientHeight = {read=GetClientHeight, nodefault};
	__property int ClientWidth = {read=GetClientWidth, nodefault};
	__property Cxcontrols::TcxControl* Container = {read=GetContainer};
	__property Cxcontrols::TcxControl* Control = {read=GetControl};
	__property Cxgridcustomview::TcxCustomGridDesignController* DesignController = {read=GetDesignController};
	__property int EmptyClientHeight = {read=GetEmptyClientHeight, nodefault};
	__property int EmptyClientWidth = {read=GetEmptyClientWidth, nodefault};
	__property int InternalHeight = {read=GetInternalHeight, nodefault};
	__property int InternalWidth = {read=GetInternalWidth, nodefault};
	__property bool IsActiveGridViewDestroying = {read=GetIsActiveGridViewDestroying, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property int MaxDetailHeight = {read=GetMaxDetailHeight, nodefault};
	__property System::Types::TPoint MaxDetailSize = {read=GetMaxDetailSize};
	__property int MaxDetailWidth = {read=GetMaxDetailWidth, nodefault};
	__property int MaxHeight = {read=GetMaxHeight, nodefault};
	__property int MaxNormalHeight = {read=GetMaxNormalHeight, nodefault};
	__property int MaxWidth = {read=GetMaxWidth, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property int NonClientHeight = {read=GetNonClientHeight, nodefault};
	__property int NonClientWidth = {read=GetNonClientWidth, nodefault};
	__property Cxgridlevel::TcxGridDetailTabsPosition TabsPosition = {read=GetTabsPosition, nodefault};
	
public:
	System::Types::TRect Bounds;
	__fastcall virtual TcxCustomGridDetailsSiteViewInfo(Cxgridlevel::TcxGridLevel* ALevel);
	__fastcall virtual ~TcxCustomGridDetailsSiteViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound);
	virtual void __fastcall ChangeActiveTab(Cxgridlevel::TcxGridLevel* ALevel, bool AFocusView = false) = 0 ;
	virtual bool __fastcall DetailHasData(Cxgridlevel::TcxGridLevel* ALevel) = 0 ;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	virtual bool __fastcall IsTabVisible(Cxgridlevel::TcxGridLevel* ALevel);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall SupportsTabAccelerators(void);
	virtual void __fastcall VisibilityChanged(bool AVisible);
	__property Cxgridlevel::TcxGridLevel* ActiveLevel = {read=GetActiveLevel};
	__property System::Uitypes::TColor BkColor = {read=GetBkColor, nodefault};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property System::Types::TRect FrameBounds = {read=GetFrameBounds};
	__property System::Uitypes::TColor FrameColor = {read=GetFrameColor, nodefault};
	__property int FrameWidth = {read=GetFrameWidth, nodefault};
	__property bool FullyVisible = {read=GetFullyVisible, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property Cxgridlevel::TcxGridLevel* Level = {read=FLevel};
	__property System::TObject* MasterRecord = {read=GetMasterRecord};
	__property int NormalHeight = {read=GetNormalHeight, nodefault};
	__property TcxCustomGridDetailsSiteTabsViewInfo* TabsViewInfo = {read=FTabsViewInfo};
	__property bool Visible = {read=GetVisible, nodefault};
	__property int Width = {read=GetWidth, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 htTab = System::Int8(0x32);
extern PACKAGE int cxGridTabsRootSize;
}	/* namespace Cxgriddetailssite */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDDETAILSSITE)
using namespace Cxgriddetailssite;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriddetailssiteHPP
