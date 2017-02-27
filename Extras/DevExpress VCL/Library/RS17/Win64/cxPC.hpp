// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPC.pas' rev: 24.00 (Win64)

#ifndef CxpcHPP
#define CxpcHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpc
{
//-- type declarations -------------------------------------------------------
enum TcxPCOption : unsigned char { pcoAlwaysShowGoDialogButton, pcoCloseButton, pcoFixedTabWidthWhenRotated, pcoGoDialog, pcoGradient, pcoGradientClientArea, pcoNoArrows, pcoRedrawOnResize, pcoSort, pcoTopToBottomText, pcoUsePageColorForTab };

typedef System::Set<TcxPCOption, TcxPCOption::pcoAlwaysShowGoDialogButton, TcxPCOption::pcoUsePageColorForTab>  TcxPCOptions;

enum TcxPCButtonMode : unsigned char { cbmNone, cbmActiveTab, cbmEveryTab, cbmActiveAndHoverTabs };

enum TcxPCButtonPosition : unsigned char { pcbpTabs, pcbpHeader, pcbpTabsAndHeader };

enum TcxPCNewButtonMode : unsigned char { nbmNone, nbmTab };

enum TcxTabSlantKind : unsigned char { skCutCorner, skSlant };

enum TcxTabSlantPosition : unsigned char { spLeft, spRight };

typedef System::Set<TcxTabSlantPosition, TcxTabSlantPosition::spLeft, TcxTabSlantPosition::spRight>  TcxTabSlantPositions;

typedef int TcxPCStyleID;

enum TcxPCStandardStyle : unsigned char { tsTabs, tsButtons, tsFlatButtons };

enum TcxTabPosition : unsigned char { tpTop, tpBottom, tpLeft, tpRight };

typedef System::TMetaClass* TcxTabViewInfoClass;

typedef System::TMetaClass* TcxTabSheetClass;

typedef System::TMetaClass* TcxPCPainterClass;

struct DECLSPEC_DRECORD TcxPCOutTabImageAndTextData
{
public:
	System::Types::TRect TabImageRect;
	System::Types::TRect TabTextRect;
	int TabVisibleIndex;
};


class DELPHICLASS TcxCustomTabControlProperties;
class DELPHICLASS TcxTab;
typedef void __fastcall (__closure *TcxPCPropertiesDrawTabEvent)(TcxCustomTabControlProperties* AProperties, TcxTab* ATab, bool &DefaultDraw);

typedef void __fastcall (__closure *TcxPCPropertiesDrawTabExEvent)(TcxCustomTabControlProperties* AProperties, TcxTab* ATab, Vcl::Graphics::TFont* Font);

typedef void __fastcall (__closure *TcxGetTabImageEvent)(System::TObject* Sender, int TabIndex, int &ImageIndex);

typedef void __fastcall (__closure *TcxGetTabHintEvent)(System::TObject* Sender, int ATabIndex, System::UnicodeString &AHint, bool &ACanShow);

class DELPHICLASS TcxTabSheet;
typedef void __fastcall (__closure *TcxPageChangingEvent)(System::TObject* Sender, TcxTabSheet* NewPage, bool &AllowChange);

typedef void __fastcall (__closure *TcxPCCanCloseEventEx)(System::TObject* Sender, int ATabIndex, bool &ACanClose);

typedef void __fastcall (__closure *TcxPCCloseEvent)(System::TObject* Sender, int ATabIndex);

typedef void __fastcall (__closure *TcxPCTabClickEvent)(System::TObject* Sender, int ATabVisibleIndex, System::Classes::TShiftState AShift);

typedef void __fastcall (__closure *TcxTabChangedEvent)(System::TObject* Sender, int TabID);

typedef void __fastcall (__closure *TcxTabChangingEvent)(System::TObject* Sender, bool &AllowChange);

typedef void __fastcall (__closure *TcxTabAfterPaintEvent)(Cxgraphics::TcxCanvas* ACanvas, TcxTab* ATab, TcxPCOutTabImageAndTextData &AImageAndTextData);

enum TcxPCNavigatorButton : unsigned char { nbTopLeft, nbBottomRight, nbGoDialog, nbClose };

typedef System::Set<TcxPCNavigatorButton, TcxPCNavigatorButton::nbTopLeft, TcxPCNavigatorButton::nbClose>  TcxPCNavigatorButtons;

typedef TcxPCNavigatorButtons TcxPCNavigatorButtonIndex;

enum TcxPCNavigatorButtonState : unsigned char { nbsNormal, nbsPressed, nbsHotTrack, nbsDisabled };

enum TcxPCNavigatorPosition : unsigned char { npLeftTop, npLeftBottom, npRightTop, npRightBottom };

struct DECLSPEC_DRECORD TcxPCTabsPosition
{
public:
	System::Types::TRect ExtendedTabsRect;
	int ExtendedTopOrLeftTabsRectBottomOrRightBorderOffset;
	int ExtendedBottomOrRightTabsRectTopOrLeftBorderOffset;
	int MinDistanceBetweenTopOrLeftAndBottomOrRightExtendedTabsRects;
	int NormalRowWidth;
	System::Types::TRect NormalTabsRect;
};


struct DECLSPEC_DRECORD TcxPCWOffset
{
public:
	int Left;
	int Right;
};


struct DECLSPEC_DRECORD TcxPCDistance
{
public:
	int dw;
	int dh;
};


struct DECLSPEC_DRECORD TcxPCIndexInterval
{
public:
	int Left;
	int Right;
};


typedef System::DynamicArray<TcxPCIndexInterval> TcxPCLineIndexBoundsArray;

typedef int TcxPCTabIndex;

enum TcxPCTabPropertyChanged : unsigned char { tpcNotSpecified, tpcColor, tpcEnabled, tpcFocused, tpcHighlighted, tpcHotTrack, tpcIsMainTab, tpcLayout, tpcPressed, tpcSelected, tpcTracking, tpcVisible };

enum TcxPCTabNotification : unsigned char { tnDeleting };

struct DECLSPEC_DRECORD TcxPCImageListRotatedImagesElement
{
public:
	System::Uitypes::TColor BackgroundColor;
	Cxgraphics::TcxBitmap* Bitmap;
	bool IsBackgroundColorSpecified;
};


typedef System::DynamicArray<TcxPCImageListRotatedImagesElement> TcxPCImageListRotatedImagesElementArray;

__interface IcxTabControl;
typedef System::DelphiInterface<IcxTabControl> _di_IcxTabControl;
class DELPHICLASS TcxCustomTabControlController;
class DELPHICLASS TcxPCCustomPainter;
class DELPHICLASS TcxCustomTabControlViewInfo;
__interface  INTERFACE_UUID("{8C8C2262-5419-46E1-BCE0-5A5311C330A0}") IcxTabControl  : public Cxcontrols::IcxControlComponentState 
{
	
public:
	virtual TcxCustomTabControlController* __fastcall GetController(void) = 0 ;
	virtual TcxPCCustomPainter* __fastcall GetPainter(void) = 0 ;
	virtual TcxCustomTabControlProperties* __fastcall GetProperties(void) = 0 ;
	virtual TcxCustomTabControlViewInfo* __fastcall GetViewInfo(void) = 0 ;
	virtual bool __fastcall CanDrawParentBackground(void) = 0 ;
	virtual System::Types::TRect __fastcall GetBoundsRect(void) = 0 ;
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void) = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetControl(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetColor(void) = 0 ;
	virtual Cxcontrols::TcxDragAndDropObject* __fastcall GetDragAndDropObject(void) = 0 ;
	virtual Cxcontrols::TcxDragAndDropState __fastcall GetDragAndDropState(void) = 0 ;
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void) = 0 ;
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void) = 0 ;
	virtual void __fastcall InvalidateRect(const System::Types::TRect &R, bool AEraseBackground) = 0 ;
	virtual void __fastcall SetModified(void) = 0 ;
	virtual bool __fastcall IsEnabled(void) = 0 ;
	virtual bool __fastcall IsFocused(void) = 0 ;
	virtual bool __fastcall IsParentBackground(void) = 0 ;
	virtual void __fastcall RequestLayout(void) = 0 ;
	__property TcxCustomTabControlController* Controller = {read=GetController};
	__property TcxPCCustomPainter* Painter = {read=GetPainter};
	__property TcxCustomTabControlProperties* Properties = {read=GetProperties};
	__property TcxCustomTabControlViewInfo* ViewInfo = {read=GetViewInfo};
};

class DELPHICLASS TcxPCCustomElementViewInfo;
class DELPHICLASS TcxCustomTabControlHitTest;
class PASCALIMPLEMENTATION TcxPCCustomElementViewInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::Types::TRect FBounds;
	
protected:
	virtual System::Types::TRect __fastcall GetAbsoluteBounds(void);
	virtual TcxCustomTabControlViewInfo* __fastcall GetControlViewInfo(void) = 0 ;
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual bool __fastcall GetHitTest(TcxCustomTabControlHitTest* AHitTest);
	virtual int __fastcall GetHitTestIndex(void) = 0 ;
	virtual bool __fastcall PtInElement(const System::Types::TPoint APoint);
	virtual void __fastcall SetHitTest(TcxCustomTabControlHitTest* AHitTest);
	
public:
	virtual bool __fastcall HasHintPoint(const System::Types::TPoint P);
	virtual bool __fastcall IsHintAtMousePos(void);
	virtual bool __fastcall UseHintHidePause(void);
	__property System::Types::TRect AbsoluteBounds = {read=GetAbsoluteBounds};
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property TcxCustomTabControlViewInfo* ControlViewInfo = {read=GetControlViewInfo};
	__property System::UnicodeString Hint = {read=GetHint};
public:
	/* TObject.Create */ inline __fastcall TcxPCCustomElementViewInfo(void) : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCCustomElementViewInfo(void) { }
	
private:
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {228FF1F5-6D0C-40F0-9F7B-8C71CE12CEC8}
	operator Dxcustomhint::_di_IcxHintableObject()
	{
		Dxcustomhint::_di_IcxHintableObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomhint::IcxHintableObject*(void) { return (Dxcustomhint::IcxHintableObject*)&__IcxHintableObject; }
	#endif
	
};


class DELPHICLASS TcxPCCustomButtonViewInfo;
class PASCALIMPLEMENTATION TcxPCCustomButtonViewInfo : public TcxPCCustomElementViewInfo
{
	typedef TcxPCCustomElementViewInfo inherited;
	
private:
	TcxPCNavigatorButtonState FState;
	
protected:
	virtual bool __fastcall CanClick(void);
	void __fastcall Click(void);
	virtual void __fastcall DoClick(void);
	virtual void __fastcall Invalidate(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual System::Uitypes::TImageIndex __fastcall GetImageIndex(void);
	virtual bool __fastcall PtInElement(const System::Types::TPoint APoint);
	virtual TcxPCNavigatorButtonState __fastcall GetState(void);
	virtual void __fastcall SetState(TcxPCNavigatorButtonState AValue);
	
public:
	__fastcall virtual ~TcxPCCustomButtonViewInfo(void);
	virtual int __fastcall GetWidth(void) = 0 ;
	virtual bool __fastcall HasImage(void);
	__property System::Uitypes::TImageIndex ImageIndex = {read=GetImageIndex, nodefault};
	__property TcxPCNavigatorButtonState State = {read=GetState, write=SetState, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxPCCustomButtonViewInfo(void) : TcxPCCustomElementViewInfo() { }
	
};


class DELPHICLASS TcxPCCustomTabButtonViewInfo;
class DELPHICLASS TcxTabViewInfo;
class PASCALIMPLEMENTATION TcxPCCustomTabButtonViewInfo : public TcxPCCustomButtonViewInfo
{
	typedef TcxPCCustomButtonViewInfo inherited;
	
private:
	TcxTabViewInfo* FTabViewInfo;
	
protected:
	virtual System::Types::TRect __fastcall GetAbsoluteBounds(void);
	virtual TcxCustomTabControlViewInfo* __fastcall GetControlViewInfo(void);
	virtual TcxPCNavigatorButtonState __fastcall GetState(void);
	
public:
	__fastcall TcxPCCustomTabButtonViewInfo(TcxTabViewInfo* ATabViewInfo);
	__property TcxTabViewInfo* TabViewInfo = {read=FTabViewInfo};
public:
	/* TcxPCCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxPCCustomTabButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxPCTabButtonViewInfo;
class DELPHICLASS TcxPCButton;
class PASCALIMPLEMENTATION TcxPCTabButtonViewInfo : public TcxPCCustomTabButtonViewInfo
{
	typedef TcxPCCustomTabButtonViewInfo inherited;
	
private:
	TcxPCButton* FButton;
	
protected:
	virtual void __fastcall DoClick(void);
	virtual int __fastcall GetHitTestIndex(void);
	virtual System::Uitypes::TImageIndex __fastcall GetImageIndex(void);
	virtual TcxPCNavigatorButtonState __fastcall GetState(void);
	
public:
	__fastcall TcxPCTabButtonViewInfo(TcxTabViewInfo* ATabViewInfo, TcxPCButton* AButton);
	virtual int __fastcall GetWidth(void);
	__property TcxPCButton* Button = {read=FButton};
public:
	/* TcxPCCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxPCTabButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxPCTabCloseButtonViewInfo;
class PASCALIMPLEMENTATION TcxPCTabCloseButtonViewInfo : public TcxPCCustomTabButtonViewInfo
{
	typedef TcxPCCustomTabButtonViewInfo inherited;
	
protected:
	virtual void __fastcall DoClick(void);
	virtual int __fastcall GetHitTestIndex(void);
	
public:
	virtual int __fastcall GetWidth(void);
public:
	/* TcxPCCustomTabButtonViewInfo.Create */ inline __fastcall TcxPCTabCloseButtonViewInfo(TcxTabViewInfo* ATabViewInfo) : TcxPCCustomTabButtonViewInfo(ATabViewInfo) { }
	
public:
	/* TcxPCCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxPCTabCloseButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxPCCustomHeaderButtonViewInfo;
class PASCALIMPLEMENTATION TcxPCCustomHeaderButtonViewInfo : public TcxPCCustomButtonViewInfo
{
	typedef TcxPCCustomButtonViewInfo inherited;
	
private:
	TcxCustomTabControlViewInfo* FTabControlViewInfo;
	
protected:
	virtual bool __fastcall AllowHotTrack(void);
	virtual int __fastcall GetHitTestIndex(void);
	virtual TcxCustomTabControlViewInfo* __fastcall GetControlViewInfo(void);
	
public:
	__fastcall TcxPCCustomHeaderButtonViewInfo(TcxCustomTabControlViewInfo* ATabControlViewInfo);
	virtual bool __fastcall IsNavigatorButton(void)/* overload */;
	virtual bool __fastcall IsNavigatorButton(TcxPCNavigatorButtons AButtonTypes)/* overload */;
public:
	/* TcxPCCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxPCCustomHeaderButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxPCHeaderButtonViewInfo;
class PASCALIMPLEMENTATION TcxPCHeaderButtonViewInfo : public TcxPCCustomHeaderButtonViewInfo
{
	typedef TcxPCCustomHeaderButtonViewInfo inherited;
	
private:
	TcxPCButton* FButton;
	
protected:
	virtual void __fastcall DoClick(void);
	virtual System::Uitypes::TImageIndex __fastcall GetImageIndex(void);
	virtual TcxPCNavigatorButtonState __fastcall GetState(void);
	
public:
	__fastcall TcxPCHeaderButtonViewInfo(TcxCustomTabControlViewInfo* ATabControlViewInfo, TcxPCButton* AButton);
	virtual int __fastcall GetWidth(void);
	__property TcxPCButton* Button = {read=FButton};
public:
	/* TcxPCCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxPCHeaderButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxPCNavigatorButtonViewInfo;
class PASCALIMPLEMENTATION TcxPCNavigatorButtonViewInfo : public TcxPCCustomHeaderButtonViewInfo
{
	typedef TcxPCCustomHeaderButtonViewInfo inherited;
	
private:
	TcxPCNavigatorButton FButtonType;
	
protected:
	virtual bool __fastcall AllowHotTrack(void);
	virtual void __fastcall DoClick(void);
	virtual int __fastcall GetHitTestIndex(void);
	
public:
	__fastcall TcxPCNavigatorButtonViewInfo(TcxCustomTabControlViewInfo* ATabControlViewInfo, TcxPCNavigatorButton AButtonType);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall IsNavigatorButton(TcxPCNavigatorButtons AButtonTypes)/* overload */;
	__property TcxPCNavigatorButton ButtonType = {read=FButtonType, nodefault};
public:
	/* TcxPCCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxPCNavigatorButtonViewInfo(void) { }
	
/* Hoisted overloads: */
	
public:
	inline bool __fastcall  IsNavigatorButton(void){ return TcxPCCustomHeaderButtonViewInfo::IsNavigatorButton(); }
	
};


class DELPHICLASS TcxPCButtonViewInfos;
class PASCALIMPLEMENTATION TcxPCButtonViewInfos : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxPCCustomTabButtonViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	Cxclasses::TcxObjectList* FItems;
	TcxTabViewInfo* FTabViewInfo;
	int __fastcall GetCount(void);
	TcxPCCustomTabButtonViewInfo* __fastcall GetItems(int Index);
	
protected:
	TcxPCTabCloseButtonViewInfo* __fastcall GetCloseButtonInfo(void);
	
public:
	__fastcall TcxPCButtonViewInfos(TcxTabViewInfo* ATabViewInfo);
	__fastcall virtual ~TcxPCButtonViewInfos(void);
	void __fastcall Add(TcxPCCustomTabButtonViewInfo* AButtonViewInfo);
	bool __fastcall GetHitTest(TcxCustomTabControlHitTest* AHitTest);
	__property int Count = {read=GetCount, nodefault};
	__property TcxPCCustomTabButtonViewInfo* Items[int Index] = {read=GetItems/*, default*/};
};


class DELPHICLASS TcxTabsViewInfo;
class PASCALIMPLEMENTATION TcxTabViewInfo : public TcxPCCustomElementViewInfo
{
	typedef TcxPCCustomElementViewInfo inherited;
	
private:
	TcxPCButtonViewInfos* FButtonInfos;
	TcxTab* FTab;
	TcxTabsViewInfo* FTabsViewInfo;
	System::Types::TPoint FNormalPosition;
	int FNormalWidth;
	int FRow;
	int FVisibleRow;
	System::Types::TRect FContentRect;
	System::Types::TRect FImageRect;
	bool FIsTextTooLong;
	System::Types::TRect FTextRect;
	void __fastcall TabDestroyHandler(System::TObject* Sender, const void *AEventArgs);
	bool __fastcall CheckHasButton(TcxPCButtonMode AShowMode);
	int __fastcall GetButtonsCount(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	System::UnicodeString __fastcall GetCaption(void);
	TcxPCTabCloseButtonViewInfo* __fastcall GetCloseButtonInfo(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	TcxPCWOffset __fastcall GetContentOffset(void);
	System::Types::TRect __fastcall GetFullRect(void);
	bool __fastcall GetEnabled(void);
	int __fastcall GetImageAreaWidth(void);
	int __fastcall GetIndex(void);
	int __fastcall GetImageIndex(void);
	int __fastcall GetNormalLongitudinalSize(void);
	System::Types::TRect __fastcall GetNormalRect(void);
	TcxPCCustomPainter* __fastcall GetPainter(void);
	TcxTabPosition __fastcall GetPaintingPosition(void);
	int __fastcall GetPaintingPositionIndex(void);
	TcxCustomTabControlProperties* __fastcall GetProperties(void);
	System::Types::TRect __fastcall GetAbsolutePartRect(const System::Types::TRect &APartRect);
	System::Types::TRect __fastcall GetTabRect(void);
	System::Types::TRect __fastcall GetTabImageAndTextRect(void);
	int __fastcall GetVisibleIndex(void);
	System::Types::TRect __fastcall GetVisibleRect(void);
	bool __fastcall IsImagesAssigned(void);
	
protected:
	void __fastcall PrepareCanvasFont(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall RecreateButtonViewInfos(void);
	void __fastcall CalculateAngleDependentPartBounds(System::Types::TRect &ACalcRect, const int APartHeight, System::Types::TRect &ADrawOffset);
	void __fastcall CalculateButtonHorizontalPositions(void);
	void __fastcall CalculateButtonVerticalPositions(void);
	void __fastcall CalculateContentRect(void);
	void __fastcall CalculateImageAndTextHorizontalPositions(void);
	void __fastcall CalculateImageHorizontalPosition(void);
	void __fastcall CalculateImageVerticalPosition(void);
	void __fastcall CalculateIsTextTooLong(void);
	void __fastcall CalculateHorizontalPositions(void);
	void __fastcall CalculateTextVerticalPosition(void);
	int __fastcall GetContentHorizontalOffset(int ATabWidth, int AContentWidth);
	virtual TcxCustomTabControlViewInfo* __fastcall GetControlViewInfo(void);
	System::Types::TRect __fastcall GetScrollingArea(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual int __fastcall GetHitTestIndex(void);
	virtual bool __fastcall PtInElement(const System::Types::TPoint APoint);
	virtual void __fastcall SetHitTest(TcxCustomTabControlHitTest* AHitTest);
	virtual bool __fastcall CanClick(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanMultiSelect(void);
	virtual bool __fastcall CanSelect(void);
	void __fastcall Click(System::Classes::TShiftState AShift);
	virtual void __fastcall DoHandleDialogChar(int Key);
	virtual void __fastcall DoSelect(bool AAddToSelected);
	virtual void __fastcall DoSetFocus(void);
	virtual void __fastcall DoClick(System::Classes::TShiftState AShift);
	bool __fastcall HandleDialogChar(int Key);
	void __fastcall Select(bool AAddToSelected);
	void __fastcall SetFocus(void);
	bool __fastcall IsCompactMode(void);
	bool __fastcall IsNewButton(void);
	virtual bool __fastcall IsPressable(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property int NormalLongitudinalSize = {read=GetNormalLongitudinalSize, nodefault};
	__property System::Types::TPoint NormalPosition = {read=FNormalPosition, write=FNormalPosition};
	__property int NormalWidth = {read=FNormalWidth, write=FNormalWidth, nodefault};
	
public:
	__fastcall virtual TcxTabViewInfo(TcxTab* ATab, TcxTabsViewInfo* ATabsViewInfo);
	__fastcall virtual ~TcxTabViewInfo(void);
	bool __fastcall ActuallyEnabled(void);
	bool __fastcall ActuallyVisible(void);
	virtual bool __fastcall HasButton(TcxPCButton* AButton);
	bool __fastcall HasButtons(void);
	bool __fastcall HasCaption(void);
	virtual bool __fastcall HasCloseButton(void);
	bool __fastcall HasImage(void);
	bool __fastcall IsActive(void);
	bool __fastcall IsFocused(void);
	bool __fastcall IsHighlighted(void);
	bool __fastcall IsHotTrack(void);
	bool __fastcall IsMainTab(void);
	bool __fastcall IsPressed(void);
	bool __fastcall IsSelected(void);
	bool __fastcall IsTracking(void);
	virtual bool __fastcall IsVisibleForGoDialog(void);
	bool __fastcall IsButtonsPlacedFirst(void);
	virtual int __fastcall GetDefinedWidth(void);
	Cxgraphics::TcxRotationAngle __fastcall GetRelativeTextRotationAngle(void);
	void __fastcall CalculateNormalWidth(void);
	void __fastcall CalculateParts(void);
	virtual void __fastcall CorrectTabNormalWidth(int &AValue);
	__property TcxPCButtonViewInfos* ButtonInfos = {read=FButtonInfos};
	__property int ButtonsCount = {read=GetButtonsCount, nodefault};
	__property System::UnicodeString Caption = {read=GetCaption};
	__property TcxPCTabCloseButtonViewInfo* CloseButtonInfo = {read=GetCloseButtonInfo};
	__property System::Uitypes::TColor Color = {read=GetColor, nodefault};
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property System::Types::TRect FullRect = {read=GetFullRect};
	__property int ImageIndex = {read=GetImageIndex, nodefault};
	__property System::Types::TRect ImageRect = {read=FImageRect};
	__property int Index = {read=GetIndex, nodefault};
	__property System::Types::TRect NormalRect = {read=GetNormalRect};
	__property TcxPCCustomPainter* Painter = {read=GetPainter};
	__property TcxTabPosition PaintingPosition = {read=GetPaintingPosition, nodefault};
	__property int PaintingPositionIndex = {read=GetPaintingPositionIndex, nodefault};
	__property TcxCustomTabControlProperties* Properties = {read=GetProperties};
	__property TcxTab* Tab = {read=FTab};
	__property TcxTabsViewInfo* TabsViewInfo = {read=FTabsViewInfo};
	__property System::Types::TRect TextRect = {read=FTextRect};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
	__property System::Types::TRect VisibleRect = {read=GetVisibleRect};
	__property int VisibleRow = {read=FVisibleRow, nodefault};
};


class DELPHICLASS TcxPCNewButtonViewInfo;
class DELPHICLASS TcxPCNewButton;
class PASCALIMPLEMENTATION TcxPCNewButtonViewInfo : public TcxTabViewInfo
{
	typedef TcxTabViewInfo inherited;
	
private:
	TcxPCNewButton* __fastcall GetButton(void);
	
protected:
	virtual bool __fastcall CanClick(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanMultiSelect(void);
	virtual bool __fastcall CanSelect(void);
	virtual void __fastcall DoClick(System::Classes::TShiftState AShift);
	__property TcxPCNewButton* Button = {read=GetButton};
	
public:
	virtual void __fastcall CorrectTabNormalWidth(int &AValue);
	virtual int __fastcall GetDefinedWidth(void);
	virtual bool __fastcall HasButton(TcxPCButton* AButton);
	virtual bool __fastcall HasCloseButton(void);
	virtual bool __fastcall IsVisibleForGoDialog(void);
public:
	/* TcxTabViewInfo.Create */ inline __fastcall virtual TcxPCNewButtonViewInfo(TcxTab* ATab, TcxTabsViewInfo* ATabsViewInfo) : TcxTabViewInfo(ATab, ATabsViewInfo) { }
	/* TcxTabViewInfo.Destroy */ inline __fastcall virtual ~TcxPCNewButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxTabs;
class PASCALIMPLEMENTATION TcxTabsViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxTabViewInfo* operator[](int Index) { return ViewInfos[Index]; }
	
private:
	TcxCustomTabControlViewInfo* FControlViewInfo;
	TcxTabs* FTabs;
	System::Contnrs::TObjectList* FViewInfos;
	bool FNeedCheckTabIndex;
	bool FNeedRecreateViewInfos;
	int FTabNormalHeight;
	void __fastcall TabsChangedHandler(System::TObject* Sender, const void *AEventArgs);
	void __fastcall TabsDestroyHandler(System::TObject* Sender, const void *AEventArgs);
	int __fastcall GetViewInfoCount(void);
	TcxTabViewInfo* __fastcall GetViewInfo(int Index);
	
protected:
	void __fastcall AddViewInfo(TcxTabViewInfo* AViewInfo);
	int __fastcall GetMaxMainTabIndex(void);
	int __fastcall IndexOf(TcxTabViewInfo* AViewInfo);
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(void);
	void __fastcall RecreateButtonViewInfos(void);
	void __fastcall RecreateViewInfos(void);
	void __fastcall CheckTabIndex(void);
	bool __fastcall CalculateHitTest(TcxCustomTabControlHitTest* AHitTest);
	void __fastcall RepaintTab(int ATabVisibleIndex, TcxPCTabPropertyChanged ATabPropertyChanged);
	bool __fastcall HandleDialogChar(int Key);
	__property int TabNormalHeight = {read=FTabNormalHeight, nodefault};
	
public:
	__fastcall virtual TcxTabsViewInfo(TcxTabs* ATabs, TcxCustomTabControlViewInfo* AControlViewInfo);
	__fastcall virtual ~TcxTabsViewInfo(void);
	void __fastcall CalculateNormalSizes(void);
	void __fastcall CalculateTabParts(void);
	virtual int __fastcall GetTabDefaultHeight(void);
	__property TcxCustomTabControlViewInfo* ControlViewInfo = {read=FControlViewInfo};
	__property TcxTabs* Tabs = {read=FTabs};
	__property int ViewInfoCount = {read=GetViewInfoCount, nodefault};
	__property TcxTabViewInfo* ViewInfos[int Index] = {read=GetViewInfo/*, default*/};
};


typedef System::TMetaClass* TcxTabsViewInfoClass;

class DELPHICLASS TcxTabSlants;
class PASCALIMPLEMENTATION TcxCustomTabControlViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FExtendedBottomOrRightTabsRect;
	System::Types::TRect FExtendedTopOrLeftTabsRect;
	int FFirstTabVisibleIndex;
	int FFocusedTabVisibleIndex;
	_di_IcxTabControl FIControl;
	int FLastTabVisibleIndex;
	TcxPCCustomTabButtonViewInfo* FHotTrackTabButton;
	TcxPCCustomHeaderButtonViewInfo* FHotTrackNavigatorButton;
	int FHotTrackTabVisibleIndex;
	bool FIsLastTabFullyVisible;
	int FMainTabVisibleIndex;
	int FMaxTabCaptionWidth;
	System::TObject* FOwner;
	TcxPCCustomHeaderButtonViewInfo* FPressedNavigatorButton;
	TcxPCCustomTabButtonViewInfo* FPressedTabButton;
	int FPressedTabVisibleIndex;
	int FRowCount;
	int FRowHeight;
	int FTabButtonHeight;
	TcxPCTabsPosition FTabsPosition;
	TcxTabsViewInfo* FTabsViewInfo;
	int FTopOrLeftPartRowCount;
	int FTrackingTabVisibleIndex;
	bool FUpdating;
	TcxTabAfterPaintEvent FOnAfterPaintTab;
	int FHeaderButtonHeight;
	TcxPCNavigatorButtons FNavigatorButtons;
	System::Contnrs::TObjectList* FNavigatorButtonInfos;
	bool __fastcall CanPressButton(TcxPCNavigatorButton AButton);
	System::Types::TRect __fastcall GetBoundsRect(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	System::Types::TRect __fastcall GetClientRect(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	System::Types::TRect __fastcall GetControlBounds(void);
	TcxCustomTabControlController* __fastcall GetController(void);
	int __fastcall GetFocusedTabVisibleIndex(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	int __fastcall GetHeight(void);
	bool __fastcall GetHideTabs(void);
	int __fastcall GetImageBorder(void);
	int __fastcall GetLineWidth(const TcxPCLineIndexBoundsArray ALineIndexBoundsA, int ALineNumber, int ATabsDistance);
	int __fastcall GetMainTabIndex(void);
	bool __fastcall GetMultiLine(void);
	int __fastcall GetNavigatorButtonCount(void);
	TcxPCCustomHeaderButtonViewInfo* __fastcall GetNavigatorButtonInfos(int Index);
	TcxPCNavigatorButtons __fastcall GetNavigatorButtons(void);
	TcxPCNavigatorPosition __fastcall GetNavigatorPosition(void);
	TcxPCOptions __fastcall GetOptions(void);
	System::Types::TRect __fastcall GetPageClientRect(void);
	System::Types::TRect __fastcall GetPageClientRectOffset(void);
	System::Types::TRect __fastcall GetPageFrameRect(void);
	System::Types::TRect __fastcall GetPageFrameRectOffset(void);
	TcxPCCustomPainter* __fastcall GetPainter(void);
	TcxCustomTabControlProperties* __fastcall GetProperties(void);
	bool __fastcall GetRaggedRight(void);
	bool __fastcall GetShowFrame(void);
	short __fastcall GetTabHeight(void);
	TcxTabPosition __fastcall GetTabPosition(void);
	System::Types::TRect __fastcall GetTabsAreaRect(void);
	TcxTabSlants* __fastcall GetTabSlants(void);
	bool __fastcall GetTabsScroll(void);
	short __fastcall GetTabWidth(void);
	int __fastcall GetWidth(void);
	bool __fastcall IsInverseNavigatorButtonsOrder(void);
	void __fastcall RearrangeRows(void);
	void __fastcall ResetHotTrack(void);
	void __fastcall SetFocusedTabVisibleIndex(int Value);
	void __fastcall SetHotTrackTabButton(TcxPCCustomTabButtonViewInfo* const Value);
	void __fastcall SetHotTrackNavigatorButton(TcxPCCustomHeaderButtonViewInfo* const Value);
	void __fastcall SetHotTrackTabVisibleIndex(int Value);
	void __fastcall SetMainTabVisibleIndex(int Value);
	void __fastcall CreateHeaderButtons(void);
	void __fastcall SetPressedNavigatorButton(TcxPCCustomHeaderButtonViewInfo* const Value);
	void __fastcall SetPressedTabButton(TcxPCCustomTabButtonViewInfo* const Value);
	void __fastcall SetPressedTabVisibleIndex(int Value);
	void __fastcall SetTrackingTabVisibleIndex(int Value);
	void __fastcall SynchronizeHotTrackStates(System::Classes::TShiftState Shift);
	void __fastcall UpdateButtonsState(void);
	void __fastcall UpdateNavigatorButtons(bool AOnlyObligatoryButtons);
	void __fastcall UpdateTabPosition(bool AShowButtons);
	
protected:
	TcxTabViewInfo* __fastcall GetTabViewInfo(TcxTab* ATab);
	int __fastcall GetTabVisibleIndex(TcxTab* ATab);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual TcxPCPainterClass __fastcall GetPainterClass(void);
	void __fastcall CalculateHitTest(TcxCustomTabControlHitTest* AHitTest);
	void __fastcall CalculateLongitudinalTabPositions(void);
	void __fastcall CalculateRowHeight(void);
	void __fastcall CalculateRowPositions(void);
	void __fastcall CalculateTabsPositions(void);
	virtual void __fastcall DoCalculate(void);
	virtual int __fastcall GetTabIndex(void);
	virtual void __fastcall SetTabIndex(int Value);
	virtual void __fastcall AfterPaintTab(Cxgraphics::TcxCanvas* ACanvas, TcxTab* ATab, TcxPCOutTabImageAndTextData &AImageAndTextData);
	bool __fastcall ArrowButtonClick(TcxPCNavigatorButton ANavigatorButton);
	void __fastcall ButtonDestroying(TcxPCCustomElementViewInfo* AElementInfo);
	void __fastcall ElementDestroying(TcxPCCustomElementViewInfo* AElementInfo);
	void __fastcall CorrectFirstTabVisibleIndex(int ATabVisibleIndex);
	virtual System::Uitypes::TColor __fastcall GetActivePageColor(void);
	TcxPCNavigatorButtonViewInfo* __fastcall GetNavigatorButtonInfoByType(TcxPCNavigatorButton AType);
	int __fastcall GetNextFocusedTabVisibleIndex(int ACurrentTabVisibleIndex, int ADelta, bool ACycle, bool AOnlyAllowSelectedTabs);
	virtual System::Uitypes::TColor __fastcall GetTabColor(int ATabVisibleIndex);
	System::Types::TRect __fastcall GetTabExtendedTabsRect(TcxTabViewInfo* ATabViewInfo)/* overload */;
	System::Types::TRect __fastcall GetTabExtendedTabsRect(int ATabVisibleIndex)/* overload */;
	int __fastcall GetTabImageAreaWidth(void);
	int __fastcall GetTabImageAreaHeight(void);
	void __fastcall InitializeLineBoundsA(TcxPCLineIndexBoundsArray &ALineIndexBoundsA, int AFirstIndex, int ALastIndex);
	virtual bool __fastcall HasActivePage(void);
	virtual bool __fastcall HasBorders(void);
	void __fastcall MakeTabVisible(int ATabVisibleIndex);
	void __fastcall PlaceVisibleTabsOnRows(int ATabsWidth, int ATabsDistance);
	void __fastcall RepaintTab(int ATabVisibleIndex, TcxPCTabPropertyChanged ATabPropertyChanged);
	void __fastcall SetMainTab(void);
	void __fastcall TabDestroying(TcxTabViewInfo* ATabViewInfo);
	void __fastcall TabDown(int ATabVisibleIndex, System::Classes::TShiftState AShift);
	void __fastcall TabUp(int ATabVisibleIndex, System::Classes::TShiftState AShift);
	virtual bool __fastcall UseActivePageColor(void);
	void __fastcall DestroyTabs(void);
	int __fastcall ActuallyRotatedTabsMaxWidth(void);
	bool __fastcall AllowHotTrack(void);
	bool __fastcall AllowMultiSelect(void);
	bool __fastcall AllowDisabledTabAccess(void);
	bool __fastcall CanMouseWheel(const System::Types::TPoint AMousePos);
	bool __fastcall HasNavigatorButton(TcxPCNavigatorButton AType);
	bool __fastcall PtInTab(int ATabVisibleIndex, int X, int Y);
	bool __fastcall IsHeaderButtonImagesAssigned(void);
	bool __fastcall IsTabFullVisible(int ATabVisibleIndex);
	bool __fastcall IsSpecialAlignment(void);
	bool __fastcall IsTooSmallControlSize(void);
	bool __fastcall IsTabActuallyVisible(TcxTabViewInfo* ATabViewInfo);
	bool __fastcall IsTabAccessible(int AIndex);
	bool __fastcall IsTabButtonImagesAssigned(void);
	bool __fastcall IsTabImagesAssigned(void);
	bool __fastcall IsTabVisibleIndexValid(int AIndex);
	bool __fastcall PtInScrollingArea(const System::Types::TPoint P, int &ADirection);
	__property TcxCustomTabControlController* Controller = {read=GetController};
	__property TcxPCCustomHeaderButtonViewInfo* HotTrackNavigatorButton = {read=FHotTrackNavigatorButton, write=SetHotTrackNavigatorButton};
	__property TcxPCCustomTabButtonViewInfo* HotTrackTabButton = {read=FHotTrackTabButton, write=SetHotTrackTabButton};
	__property int HotTrackTabVisibleIndex = {read=FHotTrackTabVisibleIndex, write=SetHotTrackTabVisibleIndex, nodefault};
	__property int LastTabVisibleIndex = {read=FLastTabVisibleIndex, write=FLastTabVisibleIndex, nodefault};
	__property int MainTabIndex = {read=GetMainTabIndex, nodefault};
	__property System::TObject* Owner = {read=FOwner};
	__property System::Types::TRect PageFrameRect = {read=GetPageFrameRect};
	__property System::Types::TRect PageFrameRectOffset = {read=GetPageFrameRectOffset};
	__property TcxPCCustomPainter* Painter = {read=GetPainter};
	__property TcxPCCustomHeaderButtonViewInfo* PressedNavigatorButton = {read=FPressedNavigatorButton, write=SetPressedNavigatorButton};
	__property TcxPCCustomTabButtonViewInfo* PressedTabButton = {read=FPressedTabButton, write=SetPressedTabButton};
	__property int PressedTabVisibleIndex = {read=FPressedTabVisibleIndex, write=SetPressedTabVisibleIndex, nodefault};
	__property int RowHeight = {read=FRowHeight, nodefault};
	__property int TrackingTabVisibleIndex = {read=FTrackingTabVisibleIndex, write=SetTrackingTabVisibleIndex, nodefault};
	__property TcxTabAfterPaintEvent OnAfterPaintTab = {read=FOnAfterPaintTab, write=FOnAfterPaintTab};
	
public:
	__fastcall virtual TcxCustomTabControlViewInfo(System::TObject* AOwner);
	__fastcall virtual ~TcxCustomTabControlViewInfo(void);
	void __fastcall Calculate(void);
	bool __fastcall ActuallyRotate(void);
	bool __fastcall CanDrawParentBackground(void);
	int __fastcall GetHeaderButtonsDistance(TcxPCCustomHeaderButtonViewInfo* AButtonInfo1, TcxPCCustomHeaderButtonViewInfo* AButtonInfo2);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	int __fastcall GetOptimalSize(void);
	virtual System::Classes::TComponent* __fastcall GetPopupOwner(void);
	System::Types::TSize __fastcall GetTabImageSize(void);
	Cxgraphics::TcxRotationAngle __fastcall GetTextRotationAngle(void);
	bool __fastcall HasTabCloseButtons(void);
	bool __fastcall HasTabButtons(void);
	int __fastcall IndexOfTabAt(int X, int Y);
	void __fastcall InitializeLineBoundsArray(TcxPCLineIndexBoundsArray &ALineIndexBoundsA);
	void __fastcall InitializeVisibleTabRange(int &AFirstIndex, int &ALastIndex);
	void __fastcall InvalidateRect(const System::Types::TRect &R, bool EraseBackground);
	bool __fastcall IsBottomToTopAlignment(void);
	bool __fastcall IsEnabled(void);
	bool __fastcall IsFocused(void);
	bool __fastcall IsNativePainting(void);
	bool __fastcall IsRightToLeftAlignment(void);
	bool __fastcall IsTabsContainer(void);
	bool __fastcall IsTabsOnBothSides(void);
	bool __fastcall IsTabsVisible(void);
	bool __fastcall IsVerticalText(void);
	bool __fastcall ParentBackground(void);
	virtual void __fastcall PrepareTabCanvasFont(TcxTabViewInfo* ATabViewInfo, Cxgraphics::TcxCanvas* ACanvas);
	int __fastcall VisibleIndexOfTabAt(int X, int Y);
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect};
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property _di_IcxTabControl IControl = {read=FIControl};
	__property System::Types::TRect ControlBounds = {read=GetControlBounds};
	__property System::Uitypes::TColor Color = {read=GetColor, nodefault};
	__property int FirstTabVisibleIndex = {read=FFirstTabVisibleIndex, write=FFirstTabVisibleIndex, nodefault};
	__property int FocusedTabVisibleIndex = {read=GetFocusedTabVisibleIndex, write=SetFocusedTabVisibleIndex, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property bool HideTabs = {read=GetHideTabs, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property int ImageBorder = {read=GetImageBorder, nodefault};
	__property int MainTabVisibleIndex = {read=FMainTabVisibleIndex, write=SetMainTabVisibleIndex, nodefault};
	__property bool MultiLine = {read=GetMultiLine, nodefault};
	__property int NavigatorButtonCount = {read=GetNavigatorButtonCount, nodefault};
	__property int HeaderButtonHeight = {read=FHeaderButtonHeight, nodefault};
	__property TcxPCNavigatorButtonViewInfo* NavigatorButtonInfoByType[TcxPCNavigatorButton AType] = {read=GetNavigatorButtonInfoByType};
	__property TcxPCCustomHeaderButtonViewInfo* NavigatorButtonInfos[int Index] = {read=GetNavigatorButtonInfos};
	__property TcxPCNavigatorButtons NavigatorButtons = {read=GetNavigatorButtons, nodefault};
	__property TcxPCNavigatorPosition NavigatorPosition = {read=GetNavigatorPosition, nodefault};
	__property TcxPCOptions Options = {read=GetOptions, nodefault};
	__property System::Types::TRect PageClientRect = {read=GetPageClientRect};
	__property System::Types::TRect PageClientRectOffset = {read=GetPageClientRectOffset};
	__property TcxCustomTabControlProperties* Properties = {read=GetProperties};
	__property bool RaggedRight = {read=GetRaggedRight, nodefault};
	__property int RowCount = {read=FRowCount, nodefault};
	__property bool ShowFrame = {read=GetShowFrame, nodefault};
	__property int TabButtonHeight = {read=FTabButtonHeight, nodefault};
	__property System::Uitypes::TColor TabColors[int ATabVisibleIndex] = {read=GetTabColor};
	__property short TabHeight = {read=GetTabHeight, nodefault};
	__property int TabIndex = {read=GetTabIndex, write=SetTabIndex, nodefault};
	__property TcxTabPosition TabPosition = {read=GetTabPosition, nodefault};
	__property System::Types::TRect TabsAreaRect = {read=GetTabsAreaRect};
	__property TcxTabSlants* TabSlants = {read=GetTabSlants};
	__property bool TabsScroll = {read=GetTabsScroll, nodefault};
	__property TcxTabsViewInfo* TabsViewInfo = {read=FTabsViewInfo};
	__property short TabWidth = {read=GetTabWidth, nodefault};
	__property int TopOrLeftPartRowCount = {read=FTopOrLeftPartRowCount, nodefault};
	__property int Width = {read=GetWidth, nodefault};
};


typedef System::TMetaClass* TcxCustomTabControlViewInfoClass;

class PASCALIMPLEMENTATION TcxTab : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FAllowCloseButton;
	System::UnicodeString FCaption;
	System::Uitypes::TColor FColor;
	Cxclasses::TcxEventHandlerCollection* FDestroyHandlers;
	bool FEnabled;
	System::Uitypes::TImageIndex FImageIndex;
	System::TObject* FObject;
	bool FSelected;
	bool FHighlighted;
	TcxTabs* FTabs;
	bool FVisible;
	System::Types::TRect __fastcall GetFullRect(void);
	bool __fastcall GetHotTrack(void);
	System::Uitypes::TImageIndex __fastcall GetImageIndex(void);
	bool __fastcall GetIsMainTab(void);
	bool __fastcall GetPressed(void);
	TcxCustomTabControlProperties* __fastcall GetProperties(void);
	bool __fastcall GetRealVisible(void);
	bool __fastcall GetTracking(void);
	TcxCustomTabControlViewInfo* __fastcall GetControlViewInfo(void);
	TcxTabViewInfo* __fastcall GetViewInfo(void);
	int __fastcall GetVisibleIndex(void);
	System::Types::TRect __fastcall GetVisibleRect(void);
	int __fastcall GetVisibleRow(void);
	void __fastcall InternalSetCaption(const System::UnicodeString Value);
	void __fastcall SetAllowCloseButton(const bool Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetEnabled(const bool Value);
	void __fastcall SetHighlighted(const bool Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetSelected(const bool Value);
	void __fastcall SetVisible(const bool Value);
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	void __fastcall Changed(TcxPCTabPropertyChanged ATabPropertyChanged);
	virtual void __fastcall DoDestroy(void);
	virtual TcxTabViewInfoClass __fastcall GetViewInfoClass(void);
	virtual int __fastcall GetIndex(void);
	virtual bool __fastcall IsNewButton(void);
	__property Cxclasses::TcxEventHandlerCollection* DestroyHandlers = {read=FDestroyHandlers};
	__property TcxCustomTabControlProperties* Properties = {read=GetProperties};
	__property TcxTabs* Tabs = {read=FTabs};
	
public:
	__fastcall virtual TcxTab(TcxTabs* ATabs);
	__fastcall virtual ~TcxTab(void);
	__property bool AllowCloseButton = {read=FAllowCloseButton, write=SetAllowCloseButton, nodefault};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property System::TObject* Data = {read=FObject};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, nodefault};
	__property System::Types::TRect FullRect = {read=GetFullRect};
	__property bool Highlighted = {read=FHighlighted, write=SetHighlighted, nodefault};
	__property bool HotTrack = {read=GetHotTrack, nodefault};
	__property System::Uitypes::TImageIndex ImageIndex = {read=GetImageIndex, write=SetImageIndex, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property bool IsMainTab = {read=GetIsMainTab, nodefault};
	__property bool Pressed = {read=GetPressed, nodefault};
	__property bool RealVisible = {read=GetRealVisible, nodefault};
	__property bool Selected = {read=FSelected, write=SetSelected, nodefault};
	__property bool Tracking = {read=GetTracking, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
	__property System::Types::TRect VisibleRect = {read=GetVisibleRect};
	__property int VisibleRow = {read=GetVisibleRow, nodefault};
};


class PASCALIMPLEMENTATION TcxPCNewButton : public TcxTab
{
	typedef TcxTab inherited;
	
private:
	int FWidth;
	void __fastcall SetWidth(int Value);
	
protected:
	virtual TcxTabViewInfoClass __fastcall GetViewInfoClass(void);
	virtual int __fastcall GetIndex(void);
	virtual void __fastcall DoDestroy(void);
	virtual bool __fastcall IsNewButton(void);
	
public:
	__fastcall virtual TcxPCNewButton(TcxTabs* ATabs);
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
public:
	/* TcxTab.Destroy */ inline __fastcall virtual ~TcxPCNewButton(void) { }
	
};


typedef System::TMetaClass* TcxPCNewButtonClass;

class PASCALIMPLEMENTATION TcxTabs : public System::Classes::TStrings
{
	typedef System::Classes::TStrings inherited;
	
public:
	TcxTab* operator[](int TabIndex) { return Tabs[TabIndex]; }
	
private:
	Cxclasses::TcxEventHandlerCollection* FChangedHandlers;
	Cxclasses::TcxEventHandlerCollection* FDestroyHandlers;
	bool FIsTabsCleaning;
	TcxPCNewButton* FNewButton;
	TcxCustomTabControlProperties* FProperties;
	System::Contnrs::TObjectList* FTabItems;
	TcxTab* __fastcall GetTab(int TabIndex);
	TcxTab* __fastcall GetVisibleTab(int ATabVisibleIndex);
	void __fastcall SetTab(int Index, TcxTab* const Value);
	int __fastcall GetVisibleTabsCount(void);
	TcxCustomTabControlViewInfo* __fastcall GetControlViewInfo(void);
	TcxTabsViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual System::UnicodeString __fastcall Get(int Index);
	virtual int __fastcall GetCount(void);
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual void __fastcall Put(int Index, const System::UnicodeString S);
	virtual void __fastcall PutObject(int Index, System::TObject* AObject);
	virtual void __fastcall SetUpdateState(bool Updating);
	void __fastcall Changed(TcxTab* ATab = (TcxTab*)(0x0), TcxPCTabPropertyChanged ATabPropertyChanged = (TcxPCTabPropertyChanged)(0x7));
	virtual TcxTabsViewInfoClass __fastcall GetViewInfoClass(void);
	virtual TcxPCNewButtonClass __fastcall GetNewButtonClass(void);
	virtual void __fastcall CreateNewButton(void);
	virtual void __fastcall DestroyNewButton(void);
	void __fastcall RemoveTab(TcxTab* ATab);
	__property Cxclasses::TcxEventHandlerCollection* ChangedHandlers = {read=FChangedHandlers};
	__property Cxclasses::TcxEventHandlerCollection* DestroyHandlers = {read=FDestroyHandlers};
	__property TcxPCNewButton* NewButton = {read=FNewButton};
	__property TcxCustomTabControlProperties* Properties = {read=FProperties};
	__property System::Contnrs::TObjectList* TabItems = {read=FTabItems};
	
public:
	__fastcall TcxTabs(TcxCustomTabControlProperties* AProperties);
	__fastcall virtual ~TcxTabs(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Insert(int Index, const System::UnicodeString S);
	virtual void __fastcall Move(int CurIndex, int NewIndex);
	__property TcxTab* Tabs[int TabIndex] = {read=GetTab, write=SetTab/*, default*/};
	__property int VisibleTabsCount = {read=GetVisibleTabsCount, nodefault};
	__property TcxTab* VisibleTabs[int TabVisibleIndex] = {read=GetVisibleTab};
};


class DELPHICLASS TcxPCImageList;
class PASCALIMPLEMENTATION TcxPCCustomPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomTabControlViewInfo* FViewInfo;
	bool FIsDragImagePainted;
	System::Uitypes::TColor __fastcall GetDisabledTextFaceColor(void);
	System::Uitypes::TColor __fastcall GetDisabledTextShadowColor(void);
	TcxPCImageList* __fastcall GetHeaderButtonImagePainter(void);
	System::Uitypes::TColor __fastcall GetHighlightedTabBodyColor(void);
	TcxPCImageList* __fastcall GetImagePainter(void);
	TcxPCImageList* __fastcall GetTabButtonImagePainter(void);
	TcxTabViewInfo* __fastcall GetTabViewInfo(int Index);
	
protected:
	__classmethod virtual bool __fastcall AllowRotate();
	virtual int __fastcall CalculateTabNormalWidth(TcxTabViewInfo* ATabViewInfo) = 0 ;
	virtual bool __fastcall CanDrawParentBackground(void);
	virtual void __fastcall CorrectTabContentVerticalOffset(int ATabVisibleIndex, System::Types::TRect &ADrawOffset);
	virtual void __fastcall CorrectTabNormalWidth(int &AValue);
	virtual System::Types::TRect __fastcall GetButtonDrawOffsets(void);
	Dxcore::TRects __fastcall GetDropArrowRects(int ADragTabVisibleIndex, int AHitTabVisibleIndex, int ADestinationTabVisibleIndex);
	virtual System::Types::TRect __fastcall GetTabCorrection(int ATabVisibleIndex);
	void __fastcall DirectionalPolyline(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Types::TPoint *APoints, const int APoints_Size, TcxTabPosition ATabPosition, System::Uitypes::TColor AColor);
	bool __fastcall DoCustomDraw(int TabVisibleIndex);
	virtual void __fastcall DoDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoDrawTabButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxPCNavigatorButtonState AState) = 0 ;
	virtual void __fastcall DoDrawTabCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxPCNavigatorButtonState AState) = 0 ;
	void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawHeaderButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, TcxPCHeaderButtonViewInfo* AHeaderButtonInfo);
	virtual void __fastcall DrawFocusRect(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall DrawNativeTabBackground(HDC DC, TcxTabSheet* ATab);
	void __fastcall DrawTabButtons(Cxgraphics::TcxCanvas* ACanvas, int TabVisibleIndex);
	virtual void __fastcall DrawTabImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, int AImageIndex, bool AEnabled, System::Uitypes::TColor AColor, int ATabVisibleIndex);
	virtual void __fastcall DrawTabImageAndText(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall DrawTabText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::UnicodeString AText, bool AEnabled, System::Uitypes::TColor AColor, int ATabVisibleIndex);
	void __fastcall ExcludeTabContentClipRegion(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall FillFreeSpaceArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall FillPageClientRect(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall FillTabPaneContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetButtonHeight(void) = 0 ;
	virtual int __fastcall GetButtonsDistance(TcxPCNavigatorButton AButton1, TcxPCNavigatorButton AButton2);
	virtual int __fastcall GetButtonsRegionFromTabsOffset(void);
	virtual int __fastcall GetButtonsRegionHOffset(void);
	virtual int __fastcall GetButtonsRegionWOffset(void);
	virtual int __fastcall GetButtonWidth(TcxPCNavigatorButton Button) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetClientColor(void);
	virtual int __fastcall GetCloseButtonAreaHeight(int ATabVisibleIndex);
	virtual int __fastcall GetCloseButtonAreaWidth(int ATabVisibleIndex);
	virtual System::Types::TSize __fastcall GetCloseButtonSize(void);
	virtual System::Types::TRect __fastcall GetCloseButtonOffset(int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetFillClientRect(void);
	virtual System::Uitypes::TColor __fastcall GetFreeSpaceColor(void);
	virtual System::Types::TRect __fastcall GetHeaderButtonGlyphOffset(void);
	Cxgraphics::TcxBorders __fastcall GetPageBorders(void);
	System::Types::TRect __fastcall GetPageClientRect(void);
	virtual System::Types::TRect __fastcall GetPageClientRectOffset(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultClientColor(void);
	virtual System::Types::TRect __fastcall GetPageFrameRect(void);
	virtual System::Types::TRect __fastcall GetPageFrameRectOffset(void);
	virtual System::Types::TRect __fastcall GetDrawImageOffset(int TabVisibleIndex) = 0 ;
	virtual TcxPCWOffset __fastcall GetDrawImageWithoutTextWOffset(int TabVisibleIndex) = 0 ;
	virtual System::Types::TRect __fastcall GetDrawTextHOffset(int TabVisibleIndex) = 0 ;
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	virtual System::Types::TRect __fastcall GetBorderWidths(void);
	System::Types::TRect __fastcall GetExtendedRect(const System::Types::TRect &ARect, const System::Types::TRect &AExtension, TcxTabPosition ATabPosition);
	virtual int __fastcall GetFrameWidth(void);
	virtual System::Types::TRect __fastcall GetTabButtonGlyphOffset(void);
	virtual int __fastcall GetTabButtonsAreaWidth(int ATabVisibleIndex);
	virtual int __fastcall GetTabButtonDistance(void);
	virtual void __fastcall AfterPaintTab(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual bool __fastcall AlwaysColoredTabs(void);
	virtual System::Types::TPoint __fastcall GetGoDialogPosition(System::Types::TSize GoDialogSize) = 0 ;
	System::Uitypes::TColor __fastcall GetHighlightedTextColor(int ATabVisibleIndex, System::Uitypes::TColor ATextColor);
	System::Uitypes::TColor __fastcall GetHotTrackColor(void);
	virtual int __fastcall GetImageTextDistance(int ATabVisibleIndex) = 0 ;
	int __fastcall GetMaxTabCaptionHeight(void);
	virtual int __fastcall GetMinTabNormalWidth(int ATabVisibleIndex) = 0 ;
	virtual TcxPCDistance __fastcall GetMinTabSelectionDistance(void) = 0 ;
	virtual System::Types::TRect __fastcall GetNativeContentOffset(void);
	System::Types::TSize __fastcall GetTabBaseImageSize(void);
	virtual System::Uitypes::TColor __fastcall GetTabBodyColor(int TabVisibleIndex) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetTabColor(int ATabVisibleIndex);
	virtual Cxgraphics::TcxRegion* __fastcall GetTabClipRgn(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual Cxgraphics::TcxRegionOperation __fastcall GetTabClipRgnOperation(int ATabVisibleIndex);
	virtual TcxPCWOffset __fastcall GetTabContentWOffset(int ATabVisibleIndex) = 0 ;
	int __fastcall GetTabImageAreaHeight(void);
	int __fastcall GetTabImageAreaWidth(void);
	virtual void __fastcall GetTabNativePartAndState(int ATabVisibleIndex, /* out */ int &PartId, /* out */ int &StateId);
	int __fastcall GetTabNativeState(int ATabVisibleIndex);
	System::Types::TSize __fastcall GetTabRotatedImageSize(void);
	virtual System::Types::TRect __fastcall GetTabsContainerOffsets(void);
	virtual TcxPCDistance __fastcall GetTabsNormalDistance(void);
	virtual TcxPCTabsPosition __fastcall GetTabsPosition(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetTextColor(int ATabVisibleIndex);
	virtual TcxPCWOffset __fastcall GetTooNarrowTabContentWOffset(int ATabVisibleIndex) = 0 ;
	bool __fastcall HasActivePage(void);
	virtual void __fastcall Init(void);
	virtual void __fastcall InternalDrawText(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString ACaption, System::Types::TRect &ARect, int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall InternalGetPageFrameRectOffset(void);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall InternalPaintDragImage(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex) = 0 ;
	void __fastcall InternalPolyLine(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor AColor, Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall InternalResetClipRegion(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall InternalSetClipRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ClipR, bool IntersectWithCurrentClipRegion = true);
	void __fastcall InvalidateTabExtendedTabsRect(int TabVisibleIndex);
	virtual void __fastcall InvalidateTabRect(int ATabVisibleIndex);
	bool __fastcall IsAssignedImages(void);
	virtual bool __fastcall IsEnableHotTrack(void);
	bool __fastcall IsEnouphSpaceForClientPage(void);
	virtual bool __fastcall IsNativePainting(void);
	virtual bool __fastcall PtInTab(int TabVisibleIndex, int X, int Y);
	virtual bool __fastcall IsPaintHeadersAreaFirst(void);
	bool __fastcall IsTabHasImage(int ATabVisibleIndex);
	virtual bool __fastcall IsTabBorderThick(int ATabVisibleIndex) = 0 ;
	virtual bool __fastcall IsTabTransparent(int ATabVisibleIndex);
	virtual bool __fastcall IsTabsRectVisible(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall NeedDisabledTextShadow(void);
	virtual bool __fastcall NeedDoubleBuffer(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual bool __fastcall NeedShowFrame(void);
	virtual void __fastcall PaintButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxPCNavigatorButtonState AState, TcxPCNavigatorButton AType) = 0 ;
	virtual void __fastcall PaintButtonsRegion(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	void __fastcall PaintDragImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int ATabVisibleIndex);
	virtual void __fastcall DoPaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintHeadersArea(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall PaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintTab(Cxgraphics::TcxCanvas* ACanvas, int TabVisibleIndex);
	virtual void __fastcall PaintTabsRegion(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	virtual void __fastcall PrepareDrawTabContentBitmapBackground(Cxgraphics::TcxBitmap* ABitmap, const System::Types::TPoint ABitmapPos, int ATabVisibleIndex);
	virtual void __fastcall DrawTabContentBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor ABackgroundColor, int ATabVisibleIndex);
	virtual void __fastcall RepaintButtonsRegion(void);
	virtual void __fastcall RepaintTab(int TabVisibleIndex, TcxPCTabPropertyChanged TabPropertyChanged);
	void __fastcall RotatePoint(const System::Types::TRect &R, System::Types::TPoint &P, TcxTabPosition ATabPosition);
	void __fastcall RotatePolyline(const System::Types::TRect &R, System::Types::TPoint *APoints, const int APoints_Size, TcxTabPosition ATabPosition);
	bool __fastcall UseActivePageColor(void);
	virtual bool __fastcall UseLookAndFeelTabButton(void);
	bool __fastcall IsDragImagePainted(void);
	void __fastcall StartDragImagePainted(void);
	void __fastcall StopDragImagePainted(void);
	__property System::Uitypes::TColor DisabledTextFaceColor = {read=GetDisabledTextFaceColor, nodefault};
	__property System::Uitypes::TColor DisabledTextShadowColor = {read=GetDisabledTextShadowColor, nodefault};
	__property System::Uitypes::TColor HighlightedTabBodyColor = {read=GetHighlightedTabBodyColor, nodefault};
	
public:
	__fastcall virtual TcxPCCustomPainter(TcxCustomTabControlViewInfo* AViewInfo);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintPageClientArea(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall CalculateTabNormalHeight(void) = 0 ;
	__classmethod virtual TcxPCStandardStyle __fastcall GetStandardStyle();
	__classmethod virtual TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	__classmethod virtual bool __fastcall IsDefault(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	__classmethod virtual bool __fastcall IsMainTabBoundWithClient();
	__classmethod virtual bool __fastcall IsMultiSelectionAccepted();
	__classmethod virtual bool __fastcall IsStandardStyle();
	__classmethod virtual bool __fastcall IsTabPressable();
	__property TcxPCImageList* HeaderButtonImagePainter = {read=GetHeaderButtonImagePainter};
	__property TcxPCImageList* ImagePainter = {read=GetImagePainter};
	__property TcxCustomTabControlViewInfo* ViewInfo = {read=FViewInfo};
	__property TcxPCImageList* TabButtonImagePainter = {read=GetTabButtonImagePainter};
	__property TcxTabViewInfo* TabViewInfo[int Index] = {read=GetTabViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCCustomPainter(void) { }
	
};


class PASCALIMPLEMENTATION TcxPCImageList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Imglist::TChangeLink* FBaseHotImageChangeLink;
	Vcl::Imglist::TCustomImageList* FBaseHotImages;
	Vcl::Imglist::TChangeLink* FBaseImageChangeLink;
	Vcl::Imglist::TCustomImageList* FBaseImages;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	Cxgraphics::TcxRotationAngle FImageRotationAngle;
	TcxCustomTabControlProperties* FProperties;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall BaseImageListChange(System::TObject* Sender);
	void __fastcall Change(void);
	void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	__classmethod void __fastcall OutError(Vcl::Controls::TCaption SourceMethodName, Vcl::Controls::TCaption Msg);
	void __fastcall SetBaseHotImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetBaseImages(Vcl::Imglist::TCustomImageList* const Value);
	System::Types::TSize __fastcall GetBaseImageSize(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(bool AHot);
	System::Types::TSize __fastcall GetRotatedImageSize(void);
	
public:
	__fastcall TcxPCImageList(TcxCustomTabControlProperties* AProperties);
	__fastcall virtual ~TcxPCImageList(void);
	bool __fastcall IsImagesAssigned(void);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas, int X, int Y, int AIndex, System::Uitypes::TColor ABackgroundColor, bool AIsNativePainting, bool AEnabled, bool AHot);
	__property Vcl::Imglist::TCustomImageList* BaseHotImages = {read=FBaseHotImages, write=SetBaseHotImages};
	__property Vcl::Imglist::TCustomImageList* BaseImages = {read=FBaseImages, write=SetBaseImages};
	__property System::Types::TSize BaseImageSize = {read=GetBaseImageSize};
	__property Cxgraphics::TcxRotationAngle ImageRotationAngle = {read=FImageRotationAngle, write=FImageRotationAngle, default=0};
	__property System::Types::TSize RotatedImageSize = {read=GetRotatedImageSize};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class PASCALIMPLEMENTATION TcxTabSlants : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxTabSlantKind FKind;
	System::Classes::TPersistent* FOwner;
	TcxTabSlantPositions FPositions;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall Changed(void);
	void __fastcall SetKind(TcxTabSlantKind Value);
	void __fastcall SetPositions(TcxTabSlantPositions Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TcxTabSlants(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property TcxTabSlantKind Kind = {read=FKind, write=SetKind, default=1};
	__property TcxTabSlantPositions Positions = {read=FPositions, write=SetPositions, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTabSlants(void) { }
	
};


typedef void __fastcall (__closure *TcxPCGoDialogClickEvent)(int ATabVisibleIndex);

class DELPHICLASS TcxPCCustomGoDialog;
class PASCALIMPLEMENTATION TcxPCCustomGoDialog : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	_di_IcxTabControl FTabControl;
	TcxPCGoDialogClickEvent FOnClick;
	TcxCustomTabControlViewInfo* __fastcall GetViewInfo(void);
	
public:
	__fastcall virtual TcxPCCustomGoDialog(_di_IcxTabControl ATabControl);
	virtual bool __fastcall Popup(int X, int Y) = 0 ;
	__property _di_IcxTabControl TabControl = {read=FTabControl};
	__property TcxCustomTabControlViewInfo* ViewInfo = {read=GetViewInfo};
	__property TcxPCGoDialogClickEvent OnClick = {read=FOnClick, write=FOnClick};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCCustomGoDialog(void) { }
	
};


class DELPHICLASS TcxTabControlDragAndDropObject;
class PASCALIMPLEMENTATION TcxTabControlDragAndDropObject : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	int FHitTabVisibleIndex;
	Cxcontrols::TcxDragImage* FDragImage;
	Cxcontrols::TcxDragAndDropArrow* FDestinationArrowFirst;
	Cxcontrols::TcxDragAndDropArrow* FDestinationArrowSecond;
	int FDestinationTabVisibleIndex;
	_di_IcxTabControl FIControl;
	int FScrollingDirection;
	Cxclasses::TcxTimer* FScrollingTimer;
	System::Types::TPoint FDragPointOffset;
	int FTabVisibleIndex;
	TcxCustomTabControlProperties* __fastcall GetProperties(void);
	TcxCustomTabControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall ScrollingTimerHandler(System::TObject* Sender);
	void __fastcall SetDestinationTabVisibleIndex(int Value);
	
protected:
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	void __fastcall CheckScrolling(const System::Types::TPoint P);
	void __fastcall CreateDestinationImage(void);
	void __fastcall CreateDragImage(void);
	void __fastcall CreateScrollingTimer(void);
	void __fastcall DestroyDestinationImage(void);
	void __fastcall DestroyDragImage(void);
	void __fastcall DestroyScrollingTimer(void);
	virtual void __fastcall DoPaintDragImage(void);
	virtual void __fastcall Drop(bool Accepted);
	virtual System::Types::TPoint __fastcall GetClientCursorPos(void);
	void __fastcall PaintDragImage(void);
	void __fastcall ShowDragImage(void);
	__property int DestinationTabVisibleIndex = {read=FDestinationTabVisibleIndex, write=SetDestinationTabVisibleIndex, nodefault};
	__property TcxCustomTabControlProperties* Properties = {read=GetProperties};
	__property TcxCustomTabControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxTabControlDragAndDropObject(_di_IcxTabControl AIControl);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual void __fastcall Init(int ATabVisibleIndex, const System::Types::TPoint P);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTabControlDragAndDropObject(void) { }
	
};


typedef System::TMetaClass* TcxTabControlDragAndDropObjectClass;

class PASCALIMPLEMENTATION TcxCustomTabControlHitTest : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomTabControlController* FController;
	System::TObject* FHitObject;
	__int64 FFlags;
	System::Types::TPoint FHitPoint;
	TcxTabViewInfo* FHitTab;
	System::Classes::TShiftState FShift;
	bool __fastcall GetBitState(int AIndex);
	bool __fastcall GetHitAtHeaderButton(void);
	bool __fastcall GetHitAtTabButton(void);
	void __fastcall SetBitState(int AIndex, bool AValue);
	
protected:
	void __fastcall Clear(void);
	void __fastcall Recalculate(void);
	void __fastcall Update(System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	
public:
	__fastcall TcxCustomTabControlHitTest(TcxCustomTabControlController* AOwner);
	__property bool HitAtHeaderButton = {read=GetHitAtHeaderButton, nodefault};
	__property bool HitAtNavigatorButton = {read=GetBitState, index=1, nodefault};
	__property bool HitAtTab = {read=GetBitState, index=2, nodefault};
	__property bool HitAtTabCloseButton = {read=GetBitState, index=3, nodefault};
	__property bool HitAtTabButton = {read=GetHitAtTabButton, nodefault};
	__property System::TObject* HitObject = {read=FHitObject};
	__property System::Types::TPoint HitPoint = {read=FHitPoint};
	__property TcxTabViewInfo* HitTab = {read=FHitTab};
	__property System::Classes::TShiftState Shift = {read=FShift, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomTabControlHitTest(void) { }
	
};


class DELPHICLASS TcxCustomTabControlHintHelper;
class PASCALIMPLEMENTATION TcxCustomTabControlHintHelper : public Dxcustomhint::TcxCustomHintHelper
{
	typedef Dxcustomhint::TcxCustomHintHelper inherited;
	
private:
	TcxCustomTabControlController* FController;
	
protected:
	virtual void __fastcall CorrectHintWindowRect(System::Types::TRect &ARect);
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerWinControl(void);
	__property TcxCustomTabControlController* Controller = {read=FController};
	
public:
	__fastcall TcxCustomTabControlHintHelper(TcxCustomTabControlController* AController);
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TcxCustomTabControlHintHelper(void) { }
	
};


typedef System::TMetaClass* TcxCustomTabControlHintHelperClass;

class PASCALIMPLEMENTATION TcxCustomTabControlController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxCustomTabControlHintHelper* FHintHelper;
	TcxPCCustomElementViewInfo* FHintObject;
	TcxCustomTabControlHitTest* FHitTest;
	_di_IcxTabControl FIControl;
	System::TObject* FOwner;
	Cxclasses::TcxTimer* FTimer;
	int FMouseDownTabVisibleIndex;
	TcxPCCustomGoDialog* FGoDialog;
	bool FIsGoDialogShowing;
	bool FGoDialogJustClosed;
	void __fastcall ArrowButtonMouseDown(TcxPCNavigatorButton ANavigatorButton);
	void __fastcall ArrowButtonClick(TcxPCNavigatorButton ANavigatorButton);
	void __fastcall CloseButtonClick(void);
	void __fastcall CreateScrollingTimer(void);
	TcxCustomTabControlProperties* __fastcall GetProperties(void);
	TcxCustomTabControlViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall IsScrollTimerStarted(void);
	bool __fastcall IsTabPressable(void);
	void __fastcall StartScrollTimer(void);
	void __fastcall StopScrollTimer(void);
	void __fastcall TimerEventHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall CheckHint(void);
	virtual bool __fastcall DoMouseWheelDown(System::Classes::TShiftState Shift, System::Types::TPoint MousePos);
	virtual bool __fastcall DoMouseWheelUp(System::Classes::TShiftState Shift, System::Types::TPoint MousePos);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall FocusChanged(void);
	virtual bool __fastcall HandleDialogChar(int Key);
	virtual bool __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoTabClick(int ATabVisibleIndex, System::Classes::TShiftState AShift);
	virtual void __fastcall TabClick(int ATabVisibleIndex, System::Classes::TShiftState AShift, bool AMouseEvent);
	virtual void __fastcall TabDown(int ATabVisibleIndex, System::Classes::TShiftState AShift);
	virtual void __fastcall TabUp(int ATabVisibleIndex, System::Classes::TShiftState AShift);
	virtual void __fastcall TabButtonDown(TcxPCCustomTabButtonViewInfo* ATabButtonInfo);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual TcxTabControlDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	void __fastcall CreateGoDialog(void);
	virtual void __fastcall DoShowGoDialog(void);
	virtual System::Types::TPoint __fastcall GetClientToScreen(const System::Types::TPoint APoint);
	virtual System::Types::TPoint __fastcall GetMouseCursorPos(void);
	virtual System::Types::TPoint __fastcall GetScreenToClient(const System::Types::TPoint APoint);
	virtual void __fastcall GoDialogClickEventHandler(int ATabVisibleIndex);
	void __fastcall HideGoDialog(int ATabVisibleIndex);
	void __fastcall ShowGoDialog(void);
	virtual NativeUInt __fastcall GetControlHandle(void);
	virtual TcxCustomTabControlHintHelperClass __fastcall GetHintHelperClass(void);
	__property _di_IcxTabControl IControl = {read=FIControl};
	__property int MouseDownTabVisibleIndex = {read=FMouseDownTabVisibleIndex, write=FMouseDownTabVisibleIndex, nodefault};
	__property System::TObject* Owner = {read=FOwner};
	__property TcxCustomTabControlProperties* Properties = {read=GetProperties};
	__property TcxCustomTabControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomTabControlController(System::TObject* AOwner);
	__fastcall virtual ~TcxCustomTabControlController(void);
	void __fastcall ScrollTabs(int ADelta);
	__property TcxCustomTabControlHitTest* HitTest = {read=FHitTest};
};


typedef System::TMetaClass* TcxCustomTabControlControllerClass;

enum TcxCustomTabControlPropertiesChangedType : unsigned char { pctHard, pctMedium, pctLight };

typedef void __fastcall (__closure *TcxCustomTabControlPropertiesChangedEvent)(System::TObject* Sender, TcxCustomTabControlPropertiesChangedType AType);

typedef void __fastcall (__closure *TcxPCPrepareTabCanvasFontEvent)(TcxTab* ATab, Cxgraphics::TcxCanvas* ACanvas);

typedef void __fastcall (__closure *TcxPCNewTabButtonClickEvent)(System::TObject* Sender, bool &AHandled);

typedef void __fastcall (__closure *TcxPCNewTabCreateEvent)(System::TObject* Sender, int AIndex);

typedef void __fastcall (__closure *TcxPCPaintDragImageEvent)(System::TObject* Sender, Vcl::Graphics::TBitmap* ABitmap, bool &ADone);

typedef void __fastcall (__closure *TcxPCNewEvent)(System::TObject* Sender, int AIndex);

typedef void __fastcall (__closure *TcxPCButtonCanShowEvent)(TcxPCButton* AButton, int ATabIndex, bool &ACanShow);

class PASCALIMPLEMENTATION TcxPCButton : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool FEnabled;
	System::Uitypes::TImageIndex FHeaderImageIndex;
	System::UnicodeString FHint;
	TcxPCButtonPosition FPosition;
	System::Uitypes::TImageIndex FTabImageIndex;
	bool FVisible;
	TcxPCButtonCanShowEvent FOnCanShow;
	System::Classes::TNotifyEvent FOnClick;
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetHeaderImageIndex(System::Uitypes::TImageIndex AValue);
	void __fastcall SetHint(const System::UnicodeString AValue);
	void __fastcall SetPosition(TcxPCButtonPosition AValue);
	void __fastcall SetTabImageIndex(System::Uitypes::TImageIndex AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	bool __fastcall DoCanShow(int ATabIndex);
	void __fastcall DoClick(void);
	
public:
	__fastcall virtual TcxPCButton(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property System::Uitypes::TImageIndex HeaderImageIndex = {read=FHeaderImageIndex, write=SetHeaderImageIndex, default=-1};
	__property System::UnicodeString Hint = {read=FHint, write=SetHint};
	__property TcxPCButtonPosition Position = {read=FPosition, write=SetPosition, default=1};
	__property System::Uitypes::TImageIndex TabImageIndex = {read=FTabImageIndex, write=SetTabImageIndex, default=-1};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property TcxPCButtonCanShowEvent OnCanShow = {read=FOnCanShow, write=FOnCanShow};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxPCButton(void) { }
	
};


class DELPHICLASS TcxPCButtons;
class PASCALIMPLEMENTATION TcxPCButtons : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TcxPCButton* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxPCButton* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxPCButton* Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	HIDESBASE TcxPCButton* __fastcall Add(void);
	__property TcxPCButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxPCButtons(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxPCButtons(void) { }
	
};


class DELPHICLASS TcxPCCustomButtons;
class PASCALIMPLEMENTATION TcxPCCustomButtons : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TcxPCButtons* FButtons;
	TcxPCImageList* FHeaderImages;
	TcxPCButtonMode FMode;
	TcxCustomTabControlProperties* FProperties;
	TcxPCImageList* FTabImages;
	int __fastcall GetCount(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetHeaderImages(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetTabImages(void);
	void __fastcall SetButtons(TcxPCButtons* AValue);
	void __fastcall SetHeaderImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetMode(TcxPCButtonMode AValue);
	void __fastcall SetTabImages(Vcl::Imglist::TCustomImageList* AValue);
	
protected:
	void __fastcall Changed(void);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TcxPCCustomButtons(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxPCCustomButtons(void);
	__property int Count = {read=GetCount, nodefault};
	
__published:
	__property TcxPCButtons* Buttons = {read=FButtons, write=SetButtons};
	__property Vcl::Imglist::TCustomImageList* HeaderImages = {read=GetHeaderImages, write=SetHeaderImages};
	__property TcxPCButtonMode Mode = {read=FMode, write=SetMode, default=0};
	__property Vcl::Imglist::TCustomImageList* TabImages = {read=GetTabImages, write=SetTabImages};
};


class PASCALIMPLEMENTATION TcxCustomTabControlProperties : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FActivateFocusedTab;
	bool FAllowDisabledTabAccess;
	bool FAllowTabDragDrop;
	TcxPCButtonMode FCloseButtonMode;
	bool FCloseTabWithMiddleClick;
	TcxPCCustomButtons* FCustomButtons;
	Vcl::Graphics::TBitmap* FDragImage;
	bool FHideTabs;
	bool FHotTrack;
	bool FIsTabsContainer;
	TcxPCImageList* FImages;
	int FImageBorder;
	bool FMultiLine;
	bool FMultiSelect;
	TcxPCNavigatorPosition FNavigatorPosition;
	TcxPCOptions FOptions;
	bool FOwnerDraw;
	bool FRaggedRight;
	bool FRotate;
	int FRotatedTabsMaxWidth;
	bool FScrollOpposite;
	bool FShowFrame;
	bool FShowButtonHints;
	bool FShowTabHints;
	TcxPCStyleID FStyle;
	System::Classes::TAlignment FTabCaptionAlignment;
	bool FTabChanging;
	int FTabIndex;
	TcxTabPosition FTabPosition;
	TcxTabs* FTabs;
	bool FTabsScroll;
	System::Types::TSmallPoint FTabSize;
	TcxTabSlants* FTabSlants;
	int FUpdateLockCount;
	System::Classes::TNotifyEvent FOnChange;
	TcxCustomTabControlPropertiesChangedEvent FOnChanged;
	TcxTabChangingEvent FOnChanging;
	System::Classes::TNotifyEvent FOnStyleChanged;
	TcxPCCanCloseEventEx FOnCanClose;
	TcxPCCloseEvent FOnClose;
	TcxPCPropertiesDrawTabEvent FOnDrawTab;
	TcxPCPropertiesDrawTabExEvent FOnDrawTabEx;
	TcxGetTabImageEvent FOnGetImageIndex;
	TcxGetTabHintEvent FOnGetTabHint;
	TcxPCNewTabButtonClickEvent FOnNewTabButtonClick;
	TcxPCNewTabCreateEvent FOnNewTabCreate;
	TcxPCPaintDragImageEvent FOnPaintDragImage;
	TcxPCPrepareTabCanvasFontEvent FOnPrepareTabCanvasFont;
	TcxPCTabClickEvent FOnTabClick;
	void __fastcall TabSlantsChangedHandler(System::TObject* Sender);
	Vcl::Imglist::TCustomImageList* __fastcall GetHeaderButtonImages(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetHotImages(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	TcxPCNewButton* __fastcall GetNewButton(void);
	TcxPCNewButtonMode __fastcall GetNewButtonMode(void);
	TcxPCOptions __fastcall GetOptions(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetTabButtonImages(void);
	void __fastcall SetActivateFocusedTab(bool Value);
	void __fastcall SetAllowDisabledTabAccess(const bool Value);
	void __fastcall SetCloseButtonMode(const TcxPCButtonMode Value);
	void __fastcall SetCustomButtons(TcxPCCustomButtons* AValue);
	void __fastcall SetDragImage(Vcl::Graphics::TBitmap* const Value);
	void __fastcall SetHideTabs(bool Value);
	void __fastcall SetHotImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetImageBorder(int Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetIsTabsContainer(bool Value);
	void __fastcall SetRotatedTabsMaxWidth(int Value);
	void __fastcall SetMultiLine(bool Value);
	void __fastcall SetNavigatorPosition(const TcxPCNavigatorPosition Value);
	void __fastcall SetNewButtonMode(TcxPCNewButtonMode Value);
	void __fastcall SetOptions(TcxPCOptions Value);
	void __fastcall SetOwnerDraw(bool Value);
	void __fastcall SetRaggedRight(bool Value);
	void __fastcall SetRotate(bool Value);
	void __fastcall SetScrollOpposite(bool Value);
	void __fastcall SetShowFrame(bool Value);
	void __fastcall SetStyle(const TcxPCStyleID Value);
	void __fastcall SetTabCaptionAlignment(System::Classes::TAlignment Value);
	void __fastcall SetTabHeight(short Value);
	void __fastcall SetTabIndex(int Value);
	void __fastcall SetTabPosition(TcxTabPosition Value);
	void __fastcall SetTabs(TcxTabs* const Value);
	void __fastcall SetTabsScroll(bool Value);
	void __fastcall SetTabSlants(TcxTabSlants* Value);
	void __fastcall SetTabWidth(const short Value);
	
protected:
	bool __fastcall CanChange(int NewTabIndex);
	virtual bool __fastcall CanCloseButtonShow(TcxTab* ATab);
	void __fastcall Changed(TcxCustomTabControlPropertiesChangedType AType = (TcxCustomTabControlPropertiesChangedType)(0x0));
	virtual bool __fastcall DoCanChange(int NewTabIndex);
	DYNAMIC void __fastcall DoChange(void);
	virtual void __fastcall DoChanged(TcxCustomTabControlPropertiesChangedType AType = (TcxCustomTabControlPropertiesChangedType)(0x0));
	virtual bool __fastcall DoPaintDragImage(Cxcontrols::TcxDragImage* AImage);
	virtual void __fastcall DoPrepareTabCanvasFont(TcxTab* ATab, Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DoStyleChanged(void);
	virtual void __fastcall DoSetTabIndex(int Value);
	virtual int __fastcall GetTabIndex(void);
	virtual void __fastcall CloseActiveTab(void);
	virtual void __fastcall CloseTab(int AIndex);
	virtual int __fastcall CreateNewTab(void);
	virtual bool __fastcall DoCanClose(int AIndex);
	virtual void __fastcall DoClose(int ATabIndex);
	virtual void __fastcall DoCloseTab(int AIndex);
	virtual void __fastcall DoCloseButtonClick(int ATabIndex);
	virtual void __fastcall DoGetTabHint(TcxTab* ATab, System::UnicodeString &AHint, bool &ACanShow);
	virtual bool __fastcall DoNewTabButtonClick(void);
	virtual void __fastcall DoNewTabCreate(int AIndex);
	virtual void __fastcall DoTabClick(int ATabVisibleIndex, System::Classes::TShiftState AShift);
	void __fastcall NewButtonClick(void);
	virtual void __fastcall MoveTab(int ACurrentIndex, int ANewIndex);
	void __fastcall SetModified(void);
	DYNAMIC bool __fastcall DoCustomDraw(int TabVisibleIndex);
	virtual void __fastcall DoDrawTabEx(int ATabVisibleIndex, Vcl::Graphics::TFont* AFont);
	bool __fastcall IsUpdateLocked(void);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	virtual _di_IcxTabControl __fastcall GetTabControl(void);
	TcxCustomTabControlViewInfo* __fastcall GetViewInfo(void);
	virtual void __fastcall ImageListChange(System::TObject* Sender);
	virtual System::UnicodeString __fastcall InternalGetTabHint(TcxTab* ATab, bool &ACanShow);
	virtual System::UnicodeString __fastcall GetButtonHint(TcxPCCustomButtonViewInfo* AButtonViewInfo);
	virtual int __fastcall GetImageIndex(TcxTab* ATab);
	TcxPCNavigatorButtons __fastcall GetNavigatorButtons(bool AOnlyObligatoryButtons);
	virtual System::UnicodeString __fastcall GetTabHint(TcxTab* ATab);
	virtual bool __fastcall TabIndexTabMustBeVisible(void);
	__property bool ActivateFocusedTab = {read=FActivateFocusedTab, write=SetActivateFocusedTab, default=1};
	__property TcxPCNewButtonMode NewButtonMode = {read=GetNewButtonMode, write=SetNewButtonMode, default=0};
	__property bool AllowDisabledTabAccess = {read=FAllowDisabledTabAccess, write=SetAllowDisabledTabAccess, default=0};
	__property bool AllowTabDragDrop = {read=FAllowTabDragDrop, write=FAllowTabDragDrop, default=0};
	__property TcxPCButtonMode CloseButtonMode = {read=FCloseButtonMode, write=SetCloseButtonMode, default=0};
	__property bool CloseTabWithMiddleClick = {read=FCloseTabWithMiddleClick, write=FCloseTabWithMiddleClick, default=0};
	__property TcxPCCustomButtons* CustomButtons = {read=FCustomButtons, write=SetCustomButtons};
	__property Vcl::Graphics::TBitmap* DragImage = {read=FDragImage, write=SetDragImage};
	__property Vcl::Imglist::TCustomImageList* HeaderButtonImages = {read=GetHeaderButtonImages};
	__property bool HideTabs = {read=FHideTabs, write=SetHideTabs, default=0};
	__property Vcl::Imglist::TCustomImageList* HotImages = {read=GetHotImages, write=SetHotImages};
	__property bool HotTrack = {read=FHotTrack, write=SetHotTrack, default=0};
	__property int ImageBorder = {read=FImageBorder, write=SetImageBorder, default=0};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property bool IsTabsContainer = {read=FIsTabsContainer, write=SetIsTabsContainer, default=0};
	__property bool MultiLine = {read=FMultiLine, write=SetMultiLine, default=0};
	__property bool MultiSelect = {read=FMultiSelect, write=FMultiSelect, default=0};
	__property TcxPCNavigatorPosition NavigatorPosition = {read=FNavigatorPosition, write=SetNavigatorPosition, default=2};
	__property TcxPCOptions Options = {read=GetOptions, write=SetOptions, default=177};
	__property bool OwnerDraw = {read=FOwnerDraw, write=SetOwnerDraw, default=0};
	__property bool RaggedRight = {read=FRaggedRight, write=SetRaggedRight, default=0};
	__property bool Rotate = {read=FRotate, write=SetRotate, default=0};
	__property int RotatedTabsMaxWidth = {read=FRotatedTabsMaxWidth, write=SetRotatedTabsMaxWidth, default=0};
	__property bool ScrollOpposite = {read=FScrollOpposite, write=SetScrollOpposite, default=0};
	__property bool ShowButtonHints = {read=FShowButtonHints, write=FShowButtonHints, default=0};
	__property bool ShowFrame = {read=FShowFrame, write=SetShowFrame, default=0};
	__property bool ShowTabHints = {read=FShowTabHints, write=FShowTabHints, default=0};
	__property TcxPCStyleID Style = {read=FStyle, write=SetStyle, default=0};
	__property Vcl::Imglist::TCustomImageList* TabButtonImages = {read=GetTabButtonImages};
	__property System::Classes::TAlignment TabCaptionAlignment = {read=FTabCaptionAlignment, write=SetTabCaptionAlignment, default=2};
	__property short TabHeight = {read=FTabSize.y, write=SetTabHeight, default=0};
	__property int TabIndex = {read=GetTabIndex, write=SetTabIndex, default=-1};
	__property TcxTabPosition TabPosition = {read=FTabPosition, write=SetTabPosition, default=0};
	__property TcxTabs* Tabs = {read=FTabs, write=SetTabs};
	__property bool TabsScroll = {read=FTabsScroll, write=SetTabsScroll, default=1};
	__property TcxTabSlants* TabSlants = {read=FTabSlants, write=SetTabSlants};
	__property short TabWidth = {read=FTabSize.x, write=SetTabWidth, default=0};
	__property TcxPCCanCloseEventEx OnCanClose = {read=FOnCanClose, write=FOnCanClose};
	__property TcxPCCloseEvent OnClose = {read=FOnClose, write=FOnClose};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TcxCustomTabControlPropertiesChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	__property TcxTabChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TcxPCPropertiesDrawTabEvent OnDrawTab = {read=FOnDrawTab, write=FOnDrawTab};
	__property TcxPCPropertiesDrawTabExEvent OnDrawTabEx = {read=FOnDrawTabEx, write=FOnDrawTabEx};
	__property TcxGetTabImageEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	__property TcxGetTabHintEvent OnGetTabHint = {read=FOnGetTabHint, write=FOnGetTabHint};
	__property TcxPCNewTabButtonClickEvent OnNewTabButtonClick = {read=FOnNewTabButtonClick, write=FOnNewTabButtonClick};
	__property TcxPCNewTabCreateEvent OnNewTabCreate = {read=FOnNewTabCreate, write=FOnNewTabCreate};
	__property System::Classes::TNotifyEvent OnStyleChanged = {read=FOnStyleChanged, write=FOnStyleChanged};
	__property TcxPCPaintDragImageEvent OnPaintDragImage = {read=FOnPaintDragImage, write=FOnPaintDragImage};
	__property TcxPCPrepareTabCanvasFontEvent OnPrepareTabCanvasFont = {read=FOnPrepareTabCanvasFont, write=FOnPrepareTabCanvasFont};
	__property TcxPCTabClickEvent OnTabClick = {read=FOnTabClick, write=FOnTabClick};
	
public:
	__fastcall virtual TcxCustomTabControlProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomTabControlProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	__property TcxPCNewButton* NewButton = {read=GetNewButton};
};


typedef System::TMetaClass* TcxCustomTabControlPropertiesClass;

class DELPHICLASS TcxTabControlProperties;
class PASCALIMPLEMENTATION TcxTabControlProperties : public TcxCustomTabControlProperties
{
	typedef TcxCustomTabControlProperties inherited;
	
__published:
	__property ActivateFocusedTab = {default=1};
	__property AllowTabDragDrop = {default=0};
	__property CloseButtonMode = {default=0};
	__property CloseTabWithMiddleClick = {default=0};
	__property CustomButtons;
	__property DragImage;
	__property HideTabs = {default=0};
	__property HotImages;
	__property HotTrack = {default=0};
	__property ImageBorder = {default=0};
	__property Images;
	__property MultiLine = {default=0};
	__property MultiSelect = {default=0};
	__property NavigatorPosition = {default=2};
	__property NewButtonMode = {default=0};
	__property Options = {default=177};
	__property OwnerDraw = {default=0};
	__property RaggedRight = {default=0};
	__property Rotate = {default=0};
	__property RotatedTabsMaxWidth = {default=0};
	__property ScrollOpposite = {default=0};
	__property ShowButtonHints = {default=0};
	__property ShowFrame = {default=0};
	__property ShowTabHints = {default=0};
	__property Style = {default=0};
	__property TabCaptionAlignment = {default=2};
	__property TabHeight = {default=0};
	__property TabIndex = {default=-1};
	__property TabPosition = {default=0};
	__property Tabs;
	__property TabsScroll = {default=1};
	__property TabSlants;
	__property TabWidth = {default=0};
public:
	/* TcxCustomTabControlProperties.Create */ inline __fastcall virtual TcxTabControlProperties(System::Classes::TPersistent* AOwner) : TcxCustomTabControlProperties(AOwner) { }
	/* TcxCustomTabControlProperties.Destroy */ inline __fastcall virtual ~TcxTabControlProperties(void) { }
	
};


class DELPHICLASS TcxCustomTabControl;
typedef void __fastcall (__closure *TcxDrawTabEvent)(TcxCustomTabControl* AControl, TcxTab* ATab, bool &DefaultDraw);

typedef void __fastcall (__closure *TcxDrawTabExEvent)(TcxCustomTabControl* AControl, TcxTab* ATab, Vcl::Graphics::TFont* Font);

typedef void __fastcall (__closure *TcxPCCanCloseEvent)(System::TObject* Sender, bool &ACanClose);

class PASCALIMPLEMENTATION TcxCustomTabControl : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	int FChangeEventLockCount;
	TcxCustomTabControlController* FController;
	bool FFocusable;
	TcxPCCustomPainter* FPainter;
	TcxCustomTabControlProperties* FProperties;
	TcxCustomTabControlViewInfo* FViewInfo;
	System::Types::TRect FClientRect;
	bool FIsClientRectLoaded;
	Vcl::Controls::TScalingFlags FScalingFlags;
	TcxPCCanCloseEvent FOnCanClose;
	TcxPCCanCloseEventEx FOnCanCloseEx;
	System::Classes::TNotifyEvent FOnChange;
	TcxTabChangingEvent FOnChanging;
	TcxDrawTabEvent FOnDrawTab;
	TcxDrawTabExEvent FOnDrawTabEx;
	TcxGetTabImageEvent FOnGetImageIndex;
	TcxGetTabHintEvent FOnGetTabHint;
	TcxPCNewTabButtonClickEvent FOnNewTabButtonClick;
	TcxPCNewTabCreateEvent FOnNewTabCreate;
	TcxPCPaintDragImageEvent FOnPaintDragImage;
	int __fastcall GetFirstVisibleTab(void);
	bool __fastcall GetHideTabs(void);
	bool __fastcall GetHotTrack(void);
	int __fastcall GetImageBorder(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	bool __fastcall GetIsTabsContainer(void);
	bool __fastcall GetMultiLine(void);
	bool __fastcall GetMultiSelect(void);
	TcxPCNavigatorPosition __fastcall GetNavigatorPosition(void);
	TcxPCOptions __fastcall GetOptions(void);
	bool __fastcall GetOwnerDraw(void);
	bool __fastcall GetRaggedRight(void);
	bool __fastcall GetRotate(void);
	int __fastcall GetMaxRotatedTabWidth(void);
	bool __fastcall GetScrollOpposite(void);
	bool __fastcall GetShowFrame(void);
	System::Classes::TAlignment __fastcall GetTabCaptionAlignment(void);
	short __fastcall GetTabHeight(void);
	int __fastcall GetTabIndex(void);
	TcxTabPosition __fastcall GetTabPosition(void);
	TcxTabSlants* __fastcall GetTabSlants(void);
	short __fastcall GetTabWidth(void);
	TcxPCNewEvent __fastcall GetOnNew(void);
	void __fastcall SetFirstVisibleTab(int Value);
	void __fastcall SetHideTabs(const bool Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetIsTabsContainer(bool Value);
	void __fastcall SetImageBorder(const int Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetMultiLine(const bool Value);
	void __fastcall SetMultiSelect(const bool Value);
	void __fastcall SetNavigatorPosition(const TcxPCNavigatorPosition Value);
	void __fastcall SetOptions(TcxPCOptions Value);
	void __fastcall SetOwnerDraw(const bool Value);
	void __fastcall SetRaggedRight(const bool Value);
	void __fastcall SetRotate(const bool Value);
	void __fastcall SetMaxRotatedTabWidth(int Value);
	void __fastcall SetScrollOpposite(const bool Value);
	void __fastcall SetShowFrame(const bool Value);
	void __fastcall SetTabCaptionAlignment(System::Classes::TAlignment Value);
	void __fastcall SetTabHeight(const short Value);
	void __fastcall SetTabIndex(int Value);
	void __fastcall SetTabPosition(const TcxTabPosition Value);
	void __fastcall SetTabSlants(TcxTabSlants* Value);
	void __fastcall SetTabWidth(const short Value);
	void __fastcall SetOnNew(const TcxPCNewEvent Value);
	void __fastcall PropertiesChangedHandler(System::TObject* Sender, TcxCustomTabControlPropertiesChangedType AType);
	void __fastcall PropertiesPaintDragImage(System::TObject* Sender, Vcl::Graphics::TBitmap* ABitmap, bool &ADone);
	System::Types::TRect __fastcall GetPageClientRect(void);
	System::Types::TRect __fastcall GetPageClientRectOffset(void);
	int __fastcall GetMainTabIndex(void);
	TcxPCStyleID __fastcall GetStyle(void);
	TcxTabs* __fastcall GetTabs(void);
	System::Types::TRect __fastcall InternalGetClientRect(void);
	bool __fastcall PassDesignMouseEvent(int X, int Y);
	void __fastcall ReadClientRectBottom(System::Classes::TReader* Reader);
	void __fastcall ReadClientRectLeft(System::Classes::TReader* Reader);
	void __fastcall ReadClientRectRight(System::Classes::TReader* Reader);
	void __fastcall ReadClientRectTop(System::Classes::TReader* Reader);
	void __fastcall SetProperties(TcxCustomTabControlProperties* const Value);
	void __fastcall SetStyle(const TcxPCStyleID Value);
	void __fastcall SetTabs(TcxTabs* const Value);
	void __fastcall WriteClientRectBottom(System::Classes::TWriter* Writer);
	void __fastcall WriteClientRectLeft(System::Classes::TWriter* Writer);
	void __fastcall WriteClientRectRight(System::Classes::TWriter* Writer);
	void __fastcall WriteClientRectTop(System::Classes::TWriter* Writer);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMPrintClient(Winapi::Messages::TWMPrint &Message);
	
protected:
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual bool __fastcall CanFocusOnClick(int X, int Y)/* overload */;
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	virtual Cxcontrols::TcxDragAndDropObject* __fastcall CreateDragAndDropObject(void);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall FocusChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	DYNAMIC bool __fastcall DoMouseWheelDown(System::Classes::TShiftState Shift, System::Types::TPoint MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(System::Classes::TShiftState Shift, System::Types::TPoint MousePos);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall TabClick(System::TObject* Sender, int ATabVisibleIndex, System::Classes::TShiftState AShift);
	void __fastcall PropertiesCanCloseHandler(System::TObject* Sender, int AIndex, bool &ACanClose);
	void __fastcall PropertiesChangeHandler(System::TObject* Sender);
	void __fastcall PropertiesChangingHandler(System::TObject* Sender, bool &AllowChange);
	void __fastcall PropertiesDrawTabExHandler(TcxCustomTabControlProperties* AControl, TcxTab* ATab, Vcl::Graphics::TFont* Font);
	void __fastcall PropertiesDrawTabHandler(TcxCustomTabControlProperties* AControl, TcxTab* ATab, bool &DefaultDraw);
	void __fastcall PropertiesGetImageIndexHandler(System::TObject* Sender, int TabIndex, int &ImageIndex);
	void __fastcall PropertiesGetTabHintHandler(System::TObject* Sender, int ATabIndex, System::UnicodeString &AHint, bool &ACanShow);
	void __fastcall PropertiesNewTabButtonClickHandler(System::TObject* Sender, bool &AHandled);
	void __fastcall PropertiesNewTabCreateHandler(System::TObject* Sender, int AIndex);
	virtual void __fastcall AfterLoaded(void);
	virtual void __fastcall AfterPaintTab(Cxgraphics::TcxCanvas* ACanvas, TcxTab* ATab, TcxPCOutTabImageAndTextData &AImageAndTextData);
	virtual void __fastcall Change(void);
	virtual void __fastcall EraseBackground(HDC DC)/* overload */;
	virtual bool __fastcall HandleDialogChar(int Key);
	virtual bool __fastcall HasBackground(void);
	virtual void __fastcall DrawTab(int TabIndex, const System::Types::TRect &Rect, bool Active);
	virtual TcxCustomTabControlControllerClass __fastcall GetControllerClass(void);
	TcxPCPainterClass __fastcall GetPainterClass(void);
	virtual TcxCustomTabControlPropertiesClass __fastcall GetPropertiesClass(void);
	virtual TcxCustomTabControlViewInfoClass __fastcall GetViewInfoClass(void);
	__classmethod void __fastcall OutError(Vcl::Controls::TCaption SourceMethodName, Vcl::Controls::TCaption Msg);
	virtual void __fastcall PrepareTabCanvasFont(TcxTab* ATab, Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall RecreatePainter(void);
	DYNAMIC void __fastcall RequestLayout(void);
	void __fastcall SetModified(void);
	void __fastcall StyleChanged(System::TObject* Sender);
	void __fastcall UpdateTabImages(void);
	bool __fastcall InternalKeyDown(System::Word Key, System::Classes::TShiftState Shift);
	bool __fastcall IsChangeEventLocked(void);
	void __fastcall LockChangeEvent(bool ALock);
	virtual bool __fastcall AllowAutoDragAndDropAtDesignTime(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC bool __fastcall AllowDragAndDropWithoutFocus(void);
	DYNAMIC void __fastcall EndDragAndDrop(bool Accepted);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	bool __fastcall CanDrawParentBackground(void);
	HIDESBASE System::Types::TRect __fastcall GetBoundsRect(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	TcxCustomTabControlController* __fastcall GetController(void);
	HIDESBASE Cxcontrols::TcxDragAndDropObject* __fastcall GetDragAndDropObject(void);
	Cxcontrols::TcxDragAndDropState __fastcall GetDragAndDropState(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	TcxPCCustomPainter* __fastcall GetPainter(void);
	TcxCustomTabControlProperties* __fastcall GetProperties(void);
	TcxCustomTabControlViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall IsEnabled(void);
	HIDESBASE bool __fastcall IsDesigning(void);
	HIDESBASE bool __fastcall IsDestroying(void);
	HIDESBASE bool __fastcall IsFocused(void);
	HIDESBASE bool __fastcall IsLoading(void);
	bool __fastcall IsParentBackground(void);
	bool __fastcall PtInCaller(const System::Types::TPoint P);
	void __fastcall MouseTrackingCallerMouseLeave(void);
	__property int FirstVisibleTab = {read=GetFirstVisibleTab, write=SetFirstVisibleTab, nodefault};
	__property bool HideTabs = {read=GetHideTabs, write=SetHideTabs, stored=false, nodefault};
	__property bool HotTrack = {read=GetHotTrack, write=SetHotTrack, stored=false, nodefault};
	__property bool IsTabsContainer = {read=GetIsTabsContainer, write=SetIsTabsContainer, stored=false, nodefault};
	__property int ImageBorder = {read=GetImageBorder, write=SetImageBorder, stored=false, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages, stored=false};
	__property bool MultiLine = {read=GetMultiLine, write=SetMultiLine, stored=false, nodefault};
	__property bool MultiSelect = {read=GetMultiSelect, write=SetMultiSelect, stored=false, nodefault};
	__property TcxPCNavigatorPosition NavigatorPosition = {read=GetNavigatorPosition, write=SetNavigatorPosition, stored=false, nodefault};
	__property TcxPCOptions Options = {read=GetOptions, write=SetOptions, stored=false, nodefault};
	__property bool OwnerDraw = {read=GetOwnerDraw, write=SetOwnerDraw, stored=false, nodefault};
	__property bool RaggedRight = {read=GetRaggedRight, write=SetRaggedRight, stored=false, nodefault};
	__property bool Rotate = {read=GetRotate, write=SetRotate, stored=false, nodefault};
	__property int MaxRotatedTabWidth = {read=GetMaxRotatedTabWidth, write=SetMaxRotatedTabWidth, stored=false, nodefault};
	__property bool ScrollOpposite = {read=GetScrollOpposite, write=SetScrollOpposite, stored=false, nodefault};
	__property bool ShowFrame = {read=GetShowFrame, write=SetShowFrame, stored=false, nodefault};
	__property System::Classes::TAlignment TabCaptionAlignment = {read=GetTabCaptionAlignment, write=SetTabCaptionAlignment, stored=false, nodefault};
	__property short TabHeight = {read=GetTabHeight, write=SetTabHeight, stored=false, nodefault};
	__property int TabIndex = {read=GetTabIndex, write=SetTabIndex, stored=false, nodefault};
	__property TcxTabPosition TabPosition = {read=GetTabPosition, write=SetTabPosition, stored=false, nodefault};
	__property TcxTabSlants* TabSlants = {read=GetTabSlants, write=SetTabSlants};
	__property short TabWidth = {read=GetTabWidth, write=SetTabWidth, stored=false, nodefault};
	__property TcxPCCanCloseEvent OnCanClose = {read=FOnCanClose, write=FOnCanClose};
	__property TcxPCCanCloseEventEx OnCanCloseEx = {read=FOnCanCloseEx, write=FOnCanCloseEx};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TcxTabChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TcxDrawTabEvent OnDrawTab = {read=FOnDrawTab, write=FOnDrawTab};
	__property TcxDrawTabExEvent OnDrawTabEx = {read=FOnDrawTabEx, write=FOnDrawTabEx};
	__property TcxGetTabImageEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	__property TcxGetTabHintEvent OnGetTabHint = {read=FOnGetTabHint, write=FOnGetTabHint};
	__property TcxPCPaintDragImageEvent OnPaintDragImage = {read=FOnPaintDragImage, write=FOnPaintDragImage};
	__property TcxPCNewTabButtonClickEvent OnNewTabButtonClick = {read=FOnNewTabButtonClick, write=FOnNewTabButtonClick};
	__property TcxPCNewTabCreateEvent OnNewTabCreate = {read=FOnNewTabCreate, write=FOnNewTabCreate};
	__property TcxPCNewEvent OnNew = {read=GetOnNew, write=SetOnNew, stored=false};
	__property System::Types::TRect PageClientRect = {read=GetPageClientRect};
	__property System::Types::TRect PageClientRectOffset = {read=GetPageClientRectOffset};
	__property bool Focusable = {read=FFocusable, write=FFocusable, default=1};
	__property int MainTabIndex = {read=GetMainTabIndex, nodefault};
	__property TcxPCStyleID Style = {read=GetStyle, write=SetStyle, stored=false, nodefault};
	__property TcxTabs* Tabs = {read=GetTabs, write=SetTabs, stored=false};
	
public:
	__fastcall virtual TcxCustomTabControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomTabControl(void);
	DYNAMIC bool __fastcall CanFocus(void);
	void __fastcall CloseTab(int AIndex);
	int __fastcall GetOptimalSize(void);
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	int __fastcall IndexOfTabAt(int X, int Y);
	int __fastcall VisibleIndexOfTabAt(int X, int Y);
	void __fastcall ScrollTabs(int ADelta);
	void __fastcall SetStandardStyle(TcxPCStandardStyle StandardStyle);
	void __fastcall SetStyleByStyleName(Vcl::Controls::TCaption StyleName);
	__property TcxCustomTabControlController* Controller = {read=FController};
	__property LookAndFeel;
	__property TcxPCCustomPainter* Painter = {read=FPainter};
	__property ParentBackground = {default=1};
	__property TcxCustomTabControlProperties* Properties = {read=FProperties, write=SetProperties};
	__property TabStop = {default=1};
	__property TcxCustomTabControlViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomTabControl(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(void){ return Cxcontrols::TcxControl::CanFocusOnClick(); }
	inline void __fastcall  EraseBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect){ Cxcontrols::TcxControl::EraseBackground(ACanvas, ARect); }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	void *__IcxTabControl;	/* IcxTabControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E29BF582-E8C0-4868-A799-DB4C41AC3BC8}
	operator Cxcontrols::_di_IcxControlComponentState()
	{
		Cxcontrols::_di_IcxControlComponentState intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxControlComponentState*(void) { return (Cxcontrols::IcxControlComponentState*)&__IcxTabControl; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8C8C2262-5419-46E1-BCE0-5A5311C330A0}
	operator _di_IcxTabControl()
	{
		_di_IcxTabControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxTabControl*(void) { return (IcxTabControl*)&__IcxTabControl; }
	#endif
	
};


class DELPHICLASS TcxPageControlProperties;
class DELPHICLASS TcxPageControl;
class PASCALIMPLEMENTATION TcxPageControlProperties : public TcxCustomTabControlProperties
{
	typedef TcxCustomTabControlProperties inherited;
	
private:
	TcxTabSheet* FActivePage;
	bool FActivePageSetting;
	int FLockCount;
	System::Classes::TList* FLockedEvents;
	bool FPageInserting;
	System::Classes::TList* FPages;
	TcxTabSheetClass FTabSheetClass;
	TcxPageChangingEvent FOnPageChanging;
	void __fastcall ChangeActivePage(TcxTabSheet* APage);
	void __fastcall UpdateTabOrders(void);
	TcxPageControl* __fastcall GetControl(void);
	int __fastcall GetPageCount(void);
	void __fastcall SetActivePage(TcxTabSheet* APage);
	void __fastcall AddDeferredEvent(System::Classes::TNotifyEvent AEvent, System::TObject* ASender);
	void __fastcall LockNotifyEvents(bool ALock);
	
protected:
	virtual bool __fastcall CanCloseButtonShow(TcxTab* ATab);
	virtual int __fastcall CreateNewTab(void);
	virtual bool __fastcall DoCanChange(int NewTabIndex);
	DYNAMIC void __fastcall DoChange(void);
	virtual void __fastcall ImageListChange(System::TObject* Sender);
	virtual void __fastcall DoCloseTab(int AIndex);
	virtual System::UnicodeString __fastcall InternalGetTabHint(TcxTab* ATab, bool &ACanShow);
	virtual bool __fastcall TabIndexTabMustBeVisible(void);
	virtual void __fastcall MoveTab(int ACurrentIntex, int ANewIndex);
	DYNAMIC bool __fastcall CanChangeActivePage(TcxTabSheet* ANewPage);
	virtual TcxTabSheet* __fastcall GetActivePage(void);
	virtual TcxTabSheet* __fastcall GetPage(int ATabIndex);
	DYNAMIC void __fastcall DoPageChange(void);
	DYNAMIC void __fastcall DoPageChanging(TcxTabSheet* NewPage, bool &AllowChange);
	void __fastcall InsertPage(TcxTabSheet* APage);
	void __fastcall RemovePage(TcxTabSheet* APage);
	virtual void __fastcall UpdateActivePage(void);
	void __fastcall UpdateTab(TcxTabSheet* APage);
	void __fastcall UpdateTabs(void);
	__property TcxPageControl* Control = {read=GetControl};
	__property TcxPageChangingEvent OnPageChanging = {read=FOnPageChanging, write=FOnPageChanging};
	
public:
	__fastcall virtual TcxPageControlProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxPageControlProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TcxTabSheet* __fastcall FindNextPage(TcxTabSheet* ACurrentPage, bool AGoForward, bool ACheckTabAccessibility, bool ACircular);
	__property int PageCount = {read=GetPageCount, nodefault};
	__property TcxTabSheet* Pages[int Index] = {read=GetPage};
	__property TabIndex = {default=-1};
	__property TcxTabSheetClass TabSheetClass = {read=FTabSheetClass, write=FTabSheetClass};
	
__published:
	__property TcxTabSheet* ActivePage = {read=GetActivePage, write=SetActivePage};
	__property ActivateFocusedTab = {default=1};
	__property AllowDisabledTabAccess = {default=0};
	__property AllowTabDragDrop = {default=0};
	__property CloseButtonMode = {default=0};
	__property CloseTabWithMiddleClick = {default=0};
	__property CustomButtons;
	__property DragImage;
	__property HideTabs = {default=0};
	__property HotImages;
	__property HotTrack = {default=0};
	__property ImageBorder = {default=0};
	__property Images;
	__property MultiLine = {default=0};
	__property NavigatorPosition = {default=2};
	__property NewButtonMode = {default=0};
	__property Options = {default=177};
	__property OwnerDraw = {default=0};
	__property RaggedRight = {default=0};
	__property Rotate = {default=0};
	__property RotatedTabsMaxWidth = {default=0};
	__property ScrollOpposite = {default=0};
	__property ShowButtonHints = {default=0};
	__property ShowFrame = {default=0};
	__property ShowTabHints = {default=0};
	__property Style = {default=0};
	__property TabCaptionAlignment = {default=2};
	__property TabHeight = {default=0};
	__property TabPosition = {default=0};
	__property TabsScroll = {default=1};
	__property TabSlants;
	__property TabWidth = {default=0};
};


class DELPHICLASS TcxPageControlViewInfo;
class PASCALIMPLEMENTATION TcxPageControlViewInfo : public TcxCustomTabControlViewInfo
{
	typedef TcxCustomTabControlViewInfo inherited;
	
private:
	TcxTabSheet* __fastcall GetActivePage(void);
	HIDESBASE TcxPageControlProperties* __fastcall GetProperties(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetActivePageColor(void);
	virtual System::Uitypes::TColor __fastcall GetTabColor(int ATabVisibleIndex);
	virtual bool __fastcall HasActivePage(void);
	virtual bool __fastcall UseActivePageColor(void);
	
public:
	__property TcxTabSheet* ActivePage = {read=GetActivePage};
	__property TcxPageControlProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomTabControlViewInfo.Create */ inline __fastcall virtual TcxPageControlViewInfo(System::TObject* AOwner) : TcxCustomTabControlViewInfo(AOwner) { }
	/* TcxCustomTabControlViewInfo.Destroy */ inline __fastcall virtual ~TcxPageControlViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxPageControl : public TcxCustomTabControl
{
	typedef TcxCustomTabControl inherited;
	
private:
	TcxTabSheet* FNewDockSheet;
	TcxTabSheet* FUndockingPage;
	TcxPageChangingEvent FOnPageChanging;
	void __fastcall PropertiesPageChangingHandler(System::TObject* Sender, TcxTabSheet* NewPage, bool &AllowChange);
	TcxTabSheet* __fastcall GetActivePage(void);
	void __fastcall SetActivePage(TcxTabSheet* APage);
	int __fastcall GetActivePageIndex(void);
	Vcl::Controls::TControl* __fastcall GetDockClientFromPoint(System::Types::TPoint P);
	TcxTabSheet* __fastcall GetPage(int Index);
	int __fastcall GetPageCount(void);
	HIDESBASE TcxPageControlProperties* __fastcall GetProperties(void);
	int __fastcall GetTabCount(void);
	void __fastcall SetActivePageIndex(int Value);
	HIDESBASE void __fastcall SetProperties(TcxPageControlProperties* Value);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMMouse &Message);
	MESSAGE void __fastcall CMDockNotification(Vcl::Controls::TCMDockNotification &Message);
	MESSAGE void __fastcall CMControlChange(Vcl::Controls::TCMControlChange &Message);
	HIDESBASE MESSAGE void __fastcall CMUnDockClient(Vcl::Controls::TCMUnDockClient &Message);
	
protected:
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	DYNAMIC void __fastcall RequestLayout(void);
	virtual void __fastcall AfterLoaded(void);
	virtual TcxCustomTabControlPropertiesClass __fastcall GetPropertiesClass(void);
	virtual TcxCustomTabControlViewInfoClass __fastcall GetViewInfoClass(void);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall ShowControl(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall DoAddDockClient(Vcl::Controls::TControl* Client, const System::Types::TRect &ARect);
	DYNAMIC void __fastcall DockOver(Vcl::Controls::TDragDockObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	DYNAMIC void __fastcall DoRemoveDockClient(Vcl::Controls::TControl* Client);
	DYNAMIC bool __fastcall DoUnDock(Vcl::Controls::TWinControl* NewTarget, Vcl::Controls::TControl* Client);
	virtual int __fastcall DockClient(Vcl::Controls::TDragDockObject* DockSource, System::Types::TPoint MousePos);
	DYNAMIC void __fastcall GetSiteInfo(Vcl::Controls::TControl* Client, System::Types::TRect &InfluenceRect, System::Types::TPoint MousePos, bool &CanDock);
	TcxTabSheet* __fastcall GetPageFromDockClient(Vcl::Controls::TControl* Client);
	virtual bool __fastcall UndockClient(Vcl::Controls::TControl* NewTarget, Vcl::Controls::TControl* Client);
	virtual void __fastcall ControlChange(bool Inserting, Vcl::Controls::TControl* Child);
	
public:
	__fastcall virtual TcxPageControl(System::Classes::TComponent* AOwner);
	TcxTabSheet* __fastcall FindNextPage(TcxTabSheet* ACurrentPage, bool AGoForward, bool ACheckTabAccessibility);
	TcxTabSheet* __fastcall FindNextPageEx(TcxTabSheet* ACurrentPage, bool AGoForward, bool ACheckTabAccessibility, bool ACircular);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	DYNAMIC void __fastcall DockDrop(Vcl::Controls::TDragDockObject* Source, int X, int Y);
	void __fastcall SelectNextPage(bool GoForward, bool CheckTabVisible = true);
	__property int ActivePageIndex = {read=GetActivePageIndex, write=SetActivePageIndex, nodefault};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property TcxTabSheet* Pages[int Index] = {read=GetPage};
	__property int TabCount = {read=GetTabCount, nodefault};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Color = {default=-16777211};
	__property Constraints;
	__property DockSite = {default=0};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Focusable = {default=1};
	__property Font;
	__property ParentBackground = {default=1};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property TcxPageControlProperties* Properties = {read=GetProperties, write=SetProperties};
	__property TcxTabSheet* ActivePage = {read=GetActivePage, write=SetActivePage, stored=false};
	__property HideTabs;
	__property HotTrack;
	__property ImageBorder;
	__property Images;
	__property LookAndFeel;
	__property MultiLine;
	__property NavigatorPosition;
	__property Options;
	__property OwnerDraw;
	__property RaggedRight;
	__property Rotate;
	__property MaxRotatedTabWidth;
	__property ScrollOpposite;
	__property ShowFrame;
	__property Style;
	__property TabHeight;
	__property TabPosition;
	__property TabSlants;
	__property TabWidth;
	__property OnCanClose;
	__property OnCanCloseEx;
	__property OnChange;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDockDrop;
	__property OnDockOver;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawTab;
	__property OnDrawTabEx;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetImageIndex;
	__property OnGetTabHint;
	__property OnGetSiteInfo;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnNew;
	__property OnNewTabButtonClick;
	__property OnNewTabCreate;
	__property TcxPageChangingEvent OnPageChanging = {read=FOnPageChanging, write=FOnPageChanging};
	__property OnPaintDragImage;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnUnDock;
public:
	/* TcxCustomTabControl.Destroy */ inline __fastcall virtual ~TcxPageControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPageControl(HWND ParentWindow) : TcxCustomTabControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxTabSheet : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	bool FAllowCloseButton;
	bool FHighlighted;
	System::Uitypes::TImageIndex FImageIndex;
	TcxPageControl* FPageControl;
	TcxTab* FTab;
	System::UnicodeString FTabHint;
	bool FTabVisible;
	System::Classes::TNotifyEvent FOnHide;
	System::Classes::TNotifyEvent FOnShow;
	int __fastcall GetPageIndex(void);
	TcxPCCustomPainter* __fastcall GetPainter(void);
	int __fastcall GetTabIndex(void);
	void __fastcall InternalColorChanged(void);
	void __fastcall SetAllowCloseButton(const bool Value);
	void __fastcall SetHighlighted(const bool Value);
	void __fastcall SetImageIndex(const System::Uitypes::TImageIndex Value);
	void __fastcall SetPageControl(TcxPageControl* const Value);
	void __fastcall SetPageIndex(const int Value);
	void __fastcall SetTabVisible(const bool Value);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMInvalidate(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoHide(void);
	DYNAMIC void __fastcall DoShow(void);
	DYNAMIC void __fastcall EnabledChanged(void);
	void __fastcall PagePropertyChanged(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall SetParentPageControl(TcxPageControl* AParentPageControl);
	DYNAMIC void __fastcall ShowingChanged(void);
	DYNAMIC void __fastcall TextChanged(void);
	__property TcxPCCustomPainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual TcxTabSheet(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxTabSheet(void);
	__property TcxPageControl* PageControl = {read=FPageControl, write=SetPageControl};
	__property int TabIndex = {read=GetTabIndex, nodefault};
	
__published:
	__property bool AllowCloseButton = {read=FAllowCloseButton, write=SetAllowCloseButton, default=1};
	__property BorderWidth = {default=0};
	__property Caption = {default=0};
	__property Color = {default=-16777211};
	__property Constraints;
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Height = {stored=false};
	__property bool Highlighted = {read=FHighlighted, write=SetHighlighted, default=0};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property Left = {stored=false};
	__property int PageIndex = {read=GetPageIndex, write=SetPageIndex, stored=false, nodefault};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property System::UnicodeString TabHint = {read=FTabHint, write=FTabHint};
	__property bool TabVisible = {read=FTabVisible, write=SetTabVisible, default=1};
	__property Top = {stored=false};
	__property Visible = {stored=false, default=1};
	__property Width = {stored=false};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property System::Classes::TNotifyEvent OnHide = {read=FOnHide, write=FOnHide};
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property System::Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTabSheet(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TcxTabControl;
class PASCALIMPLEMENTATION TcxTabControl : public TcxCustomTabControl
{
	typedef TcxCustomTabControl inherited;
	
private:
	HIDESBASE TcxTabControlProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxTabControlProperties* Value);
	
protected:
	virtual TcxCustomTabControlPropertiesClass __fastcall GetPropertiesClass(void);
	
public:
	__property PageClientRect;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Color = {default=-16777211};
	__property Constraints;
	__property DockSite = {default=0};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Focusable = {default=1};
	__property Font;
	__property ParentBackground = {default=1};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property TcxTabControlProperties* Properties = {read=GetProperties, write=SetProperties};
	__property HideTabs;
	__property HotTrack;
	__property ImageBorder;
	__property Images;
	__property LookAndFeel;
	__property MultiLine;
	__property MultiSelect;
	__property NavigatorPosition;
	__property Options;
	__property OwnerDraw;
	__property RaggedRight;
	__property Rotate;
	__property MaxRotatedTabWidth;
	__property ScrollOpposite;
	__property ShowFrame;
	__property Style;
	__property TabHeight;
	__property TabIndex;
	__property TabPosition;
	__property Tabs;
	__property TabSlants;
	__property TabWidth;
	__property OnCanClose;
	__property OnCanCloseEx;
	__property OnChange;
	__property OnChanging;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDockDrop;
	__property OnDockOver;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawTab;
	__property OnDrawTabEx;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetImageIndex;
	__property OnGetSiteInfo;
	__property OnGetTabHint;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnNew;
	__property OnNewTabButtonClick;
	__property OnNewTabCreate;
	__property OnPaintDragImage;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnUnDock;
public:
	/* TcxCustomTabControl.Create */ inline __fastcall virtual TcxTabControl(System::Classes::TComponent* AOwner) : TcxCustomTabControl(AOwner) { }
	/* TcxCustomTabControl.Destroy */ inline __fastcall virtual ~TcxTabControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTabControl(HWND ParentWindow) : TcxCustomTabControl(ParentWindow) { }
	
};


typedef System::StaticArray<System::UnicodeString, 11> Cxpc__63;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 TabsContainerOffset = System::Int8(0x2);
static const System::Int8 TabsContainerBaseWidth = System::Int8(0x3);
static const System::Int8 cxPCNoStyle = System::Int8(-1);
static const System::Int8 cxPCDefaultStyle = System::Int8(0x0);
#define cxPCDefaultStyleName L"Default"
static const System::Int8 cxPCNewButtonIndex = System::Int8(-2);
#define cxPCDefaultOptions (System::Set<TcxPCOption, TcxPCOption::pcoAlwaysShowGoDialogButton, TcxPCOption::pcoUsePageColorForTab> () << TcxPCOption::pcoAlwaysShowGoDialogButton << TcxPCOption::pcoGradient << TcxPCOption::pcoGradientClientArea << TcxPCOption::pcoRedrawOnResize )
#define cxTabSlantDefaultPositions (System::Set<TcxTabSlantPosition, TcxTabSlantPosition::spLeft, TcxTabSlantPosition::spRight> () << TcxTabSlantPosition::spLeft )
static const System::Int8 pchtNavigatorButton = System::Int8(0x1);
static const System::Int8 pchtTab = System::Int8(0x2);
static const System::Int8 pchtTabCloseButton = System::Int8(0x3);
static const System::Int8 pchtTabButton = System::Int8(0x4);
static const System::Int8 pchtHeaderButton = System::Int8(0x5);
extern PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxButtonState, 4> NavigatorBtnStateToLookAndFeelBtnState;
extern PACKAGE Cxpc__63 dxPCOptionsNames;
extern PACKAGE int TabScrollingDelay;
extern PACKAGE int TabScrollingStartDelay;
extern PACKAGE int __fastcall DistanceGetter(const TcxPCDistance Distance, const bool LongitudinalDistance);
extern PACKAGE Cxgraphics::TcxRotationAngle __fastcall InternalGetTextRotationAngle(TcxCustomTabControlViewInfo* AViewInfo);
extern PACKAGE bool __fastcall InternalIsVerticalText(TcxCustomTabControlViewInfo* AViewInfo);
extern PACKAGE bool __fastcall IsBottomToTopAlignment(TcxCustomTabControl* TabControl);
extern PACKAGE bool __fastcall IsOneOfButtons(TcxPCNavigatorButton AButton1, TcxPCNavigatorButton AButton2, TcxPCNavigatorButton AButton);
extern PACKAGE bool __fastcall IsRightToLeftAlignment(TcxCustomTabControl* TabControl);
extern PACKAGE bool __fastcall IsVerticalText(TcxCustomTabControl* TabControl);
extern PACKAGE int __fastcall PointGetter(const System::Types::TPoint APoint, bool AIsY);
extern PACKAGE void __fastcall PointSetter(System::Types::TPoint &APoint, bool AIsY, int AValue);
extern PACKAGE void __fastcall RectSetter(System::Types::TRect &ARect, bool AIsLeftTop, bool AIsY, int AValue);
extern PACKAGE System::Types::TRect __fastcall RotateRect(const System::Types::TRect &ARect, TcxTabPosition ATabPosition);
extern PACKAGE System::Types::TRect __fastcall RotateRectBack(const System::Types::TRect &ARect, TcxTabPosition ATabPosition);
extern PACKAGE System::Types::TSize __fastcall TextSize(TcxTabViewInfo* ATabViewInfo, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0));
extern PACKAGE void __fastcall ValidateRect(System::Types::TRect &R);
extern PACKAGE System::UnicodeString __fastcall GetPCStyleName(TcxPCStyleID AStyleID);
}	/* namespace Cxpc */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPC)
using namespace Cxpc;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpcHPP
