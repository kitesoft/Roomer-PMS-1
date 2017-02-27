// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarApplicationMenu.pas' rev: 24.00 (Win32)

#ifndef DxbarapplicationmenuHPP
#define DxbarapplicationmenuHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarAccessibility.hpp>	// Pascal unit
#include <dxScreenTip.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarapplicationmenu
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TdxBarExtraPaneNotifyEvent)(System::TObject* Sender, int AIndex);

typedef void __fastcall (__closure *TdxBarExtraPaneGetDisplayTextEvent)(System::TObject* Sender, int AIndex, System::UnicodeString &ADisplayText);

class DELPHICLASS TdxBarExtraPaneItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarExtraPaneItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	int FData;
	System::UnicodeString FDisplayText;
	int FImageIndex;
	bool FPin;
	System::UnicodeString FText;
	void __fastcall SetDisplayText(const System::UnicodeString Value);
	void __fastcall SetText(const System::UnicodeString Value);
	
public:
	__fastcall virtual TdxBarExtraPaneItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int Data = {read=FData, write=FData, nodefault};
	
__published:
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=SetDisplayText};
	__property int ImageIndex = {read=FImageIndex, write=FImageIndex, default=-1};
	__property bool Pin = {read=FPin, write=FPin, default=0};
	__property System::UnicodeString Text = {read=FText, write=SetText};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxBarExtraPaneItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarExtraPaneItems;
class DELPHICLASS TdxBarCustomApplicationMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarExtraPaneItems : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxBarExtraPaneItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxBarCustomApplicationMenu* FApplicationMenu;
	HIDESBASE TdxBarExtraPaneItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxBarExtraPaneItem* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TdxBarExtraPaneItems(TdxBarCustomApplicationMenu* AApplicationMenu);
	HIDESBASE TdxBarExtraPaneItem* __fastcall Add(void);
	int __fastcall IndexOf(const System::UnicodeString AItemText);
	HIDESBASE TdxBarExtraPaneItem* __fastcall Insert(int AIndex);
	__property TdxBarExtraPaneItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxBarExtraPaneItems(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarApplicationMenuExtraPane;
class DELPHICLASS TdxBarExtraPaneListItem;
class PASCALIMPLEMENTATION TdxBarApplicationMenuExtraPane : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxBarCustomApplicationMenu* FApplicationMenu;
	TdxBarExtraPaneItems* FItems;
	TdxBarExtraPaneListItem* FListItem;
	int FSize;
	bool FVisible;
	double FWidthRatio;
	TdxBarExtraPaneGetDisplayTextEvent FOnGetItemDisplayText;
	TdxBarExtraPaneNotifyEvent FOnItemClick;
	bool __fastcall GetAllowPinItems(void);
	System::UnicodeString __fastcall GetHeader(void);
	bool __fastcall IsHeaderStored(void);
	bool __fastcall IsWidthRatioStored(void);
	void __fastcall SetAllowPinItems(bool AValue);
	void __fastcall SetHeader(const System::UnicodeString AHeader);
	void __fastcall SetItems(TdxBarExtraPaneItems* AValue);
	void __fastcall SetSize(int AValue);
	void __fastcall SetWidthRatio(double AValue);
	void __fastcall DoItemClick(System::TObject* Sender);
	void __fastcall DoGetItemDisplayText(System::TObject* Sender, int AIndex, System::UnicodeString &ADisplayText);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall PopulateListItem(void);
	__property TdxBarExtraPaneListItem* ListItem = {read=FListItem};
	
public:
	__fastcall TdxBarApplicationMenuExtraPane(TdxBarCustomApplicationMenu* AApplicationMenu);
	__fastcall virtual ~TdxBarApplicationMenuExtraPane(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AllowPinItems = {read=GetAllowPinItems, write=SetAllowPinItems, default=1};
	__property System::UnicodeString Header = {read=GetHeader, write=SetHeader, stored=IsHeaderStored};
	__property TdxBarExtraPaneItems* Items = {read=FItems, write=SetItems};
	__property int Size = {read=FSize, write=SetSize, default=0};
	__property bool Visible = {read=FVisible, write=FVisible, default=1};
	__property double WidthRatio = {read=FWidthRatio, write=SetWidthRatio, stored=IsWidthRatioStored};
	__property TdxBarExtraPaneNotifyEvent OnItemClick = {read=FOnItemClick, write=FOnItemClick};
	__property TdxBarExtraPaneGetDisplayTextEvent OnGetItemDisplayText = {read=FOnGetItemDisplayText, write=FOnGetItemDisplayText};
};


class DELPHICLASS TdxBarApplicationMenuButtonItem;
class PASCALIMPLEMENTATION TdxBarApplicationMenuButtonItem : public Dxbar::TdxBarButtonLikeItem
{
	typedef Dxbar::TdxBarButtonLikeItem inherited;
	
private:
	Dxbar::TdxBarButton* FExternalItem;
	void __fastcall SetExternalItem(Dxbar::TdxBarButton* AValue);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual bool __fastcall GetEnabled(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual int __fastcall GetImageIndex(void);
	virtual Dxscreentip::TdxScreenTip* __fastcall GetScreenTip(void);
	virtual Dxbar::TdxBarItemVisible __fastcall GetVisible(void);
	
public:
	__fastcall virtual TdxBarApplicationMenuButtonItem(System::Classes::TComponent* AOwner);
	DYNAMIC void __fastcall DirectClick(void);
	__property Dxbar::TdxBarButton* ExternalItem = {read=FExternalItem, write=SetExternalItem};
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxBarApplicationMenuButtonItem(void) { }
	
};


class DELPHICLASS TdxBarApplicationMenuButton;
class DELPHICLASS TdxBarApplicationMenuButtons;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarApplicationMenuButton : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TdxBarApplicationMenuButtonItem* FInternalItem;
	TdxBarApplicationMenuButtons* __fastcall GetCollection(void);
	Dxbar::TdxBarButton* __fastcall GetItem(void);
	int __fastcall GetWidth(void);
	void __fastcall SetItem(Dxbar::TdxBarButton* Value);
	void __fastcall SetWidth(int Value);
	
protected:
	__property TdxBarApplicationMenuButtonItem* InternalItem = {read=FInternalItem};
	
public:
	__fastcall virtual TdxBarApplicationMenuButton(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxBarApplicationMenuButton(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxBarApplicationMenuButtons* Collection = {read=GetCollection};
	
__published:
	__property Dxbar::TdxBarButton* Item = {read=GetItem, write=SetItem};
	__property int Width = {read=GetWidth, write=SetWidth, default=0};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarApplicationMenuButtons : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxBarApplicationMenuButton* operator[](int Index) { return Items[Index]; }
	
private:
	TdxBarCustomApplicationMenu* FApplicationMenu;
	HIDESBASE TdxBarApplicationMenuButton* __fastcall GetItem(int Index);
	void __fastcall PopulateItemLinks(Dxbar::TdxBarItemLinks* AItemLinks);
	HIDESBASE void __fastcall SetItem(int Index, TdxBarApplicationMenuButton* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TdxBarApplicationMenuButtons(TdxBarCustomApplicationMenu* AApplicationMenu);
	HIDESBASE TdxBarApplicationMenuButton* __fastcall Add(void);
	HIDESBASE TdxBarApplicationMenuButton* __fastcall Insert(int AIndex);
	__property TdxBarApplicationMenuButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxBarApplicationMenuButtons(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarApplicationMenuButtonItemLinks;
class PASCALIMPLEMENTATION TdxBarApplicationMenuButtonItemLinks : public Dxbar::TdxBarSubMenuControlItemLinks
{
	typedef Dxbar::TdxBarSubMenuControlItemLinks inherited;
	
protected:
	void __fastcall CalcItemsRects(const System::Types::TRect &ARect);
	virtual bool __fastcall IsScrollable(void);
public:
	/* TdxBarItemLinks.Create */ inline __fastcall TdxBarApplicationMenuButtonItemLinks(Dxbar::TdxBarManager* ABarManager, Dxbar::_di_IdxBarLinksOwner ALinksOwner) : Dxbar::TdxBarSubMenuControlItemLinks(ABarManager, ALinksOwner) { }
	/* TdxBarItemLinks.Destroy */ inline __fastcall virtual ~TdxBarApplicationMenuButtonItemLinks(void) { }
	
};


class PASCALIMPLEMENTATION TdxBarCustomApplicationMenu : public Dxbar::TdxBarCustomPopupMenu
{
	typedef Dxbar::TdxBarCustomPopupMenu inherited;
	
private:
	TdxBarApplicationMenuButtons* FButtons;
	TdxBarApplicationMenuExtraPane* FExtraPane;
	System::Classes::TNotifyEvent FExtraPaneEvents;
	double __fastcall GetExtraPaneWidthRatio(void);
	int __fastcall GetExtraPaneSize(void);
	TdxBarExtraPaneItems* __fastcall GetExtraPaneItems(void);
	System::UnicodeString __fastcall GetExtraPaneHeader(void);
	TdxBarExtraPaneNotifyEvent __fastcall GetOnExtraPaneItemClick(void);
	void __fastcall SetExtraPaneWidthRatio(double AValue);
	void __fastcall SetExtraPaneSize(int AValue);
	void __fastcall SetExtraPaneItems(TdxBarExtraPaneItems* AValue);
	void __fastcall SetExtraPaneHeader(System::UnicodeString AValue);
	void __fastcall SetOnExtraPaneItemClick(TdxBarExtraPaneNotifyEvent AValue);
	void __fastcall SetButtons(TdxBarApplicationMenuButtons* AValue);
	void __fastcall SetExtraPane(TdxBarApplicationMenuExtraPane* AValue);
	
protected:
	virtual Dxbar::TCustomdxBarControlClass __fastcall GetControlClass(void);
	virtual Dxbar::TdxBarItemLinksClass __fastcall GetItemLinksClass(void);
	
public:
	__fastcall virtual TdxBarCustomApplicationMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarCustomApplicationMenu(void);
	virtual bool __fastcall IsShortCut(System::Classes::TShortCut AShortCut);
	__property TdxBarApplicationMenuButtons* Buttons = {read=FButtons, write=SetButtons};
	__property TdxBarApplicationMenuExtraPane* ExtraPane = {read=FExtraPane, write=SetExtraPane};
	__property System::Classes::TNotifyEvent ExtraPaneEvents = {read=FExtraPaneEvents, write=FExtraPaneEvents};
	__property double ExtraPaneWidthRatio = {read=GetExtraPaneWidthRatio, write=SetExtraPaneWidthRatio};
	__property int ExtraPaneSize = {read=GetExtraPaneSize, write=SetExtraPaneSize, nodefault};
	__property TdxBarExtraPaneItems* ExtraPaneItems = {read=GetExtraPaneItems, write=SetExtraPaneItems};
	__property System::UnicodeString ExtraPaneHeader = {read=GetExtraPaneHeader, write=SetExtraPaneHeader};
	__property TdxBarExtraPaneNotifyEvent OnExtraPaneItemClick = {read=GetOnExtraPaneItemClick, write=SetOnExtraPaneItemClick};
};


class DELPHICLASS TdxBarApplicationMenuControlViewInfo;
class DELPHICLASS TdxBarApplicationMenuControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarApplicationMenuControlViewInfo : public Dxbar::TdxBarSubMenuControlViewInfo
{
	typedef Dxbar::TdxBarSubMenuControlViewInfo inherited;
	
private:
	HIDESBASE TdxBarApplicationMenuControl* __fastcall GetBarControl(void);
	
public:
	virtual void __fastcall Calculate(void);
	__property TdxBarApplicationMenuControl* BarControl = {read=GetBarControl};
public:
	/* TCustomdxBarControlViewInfo.Create */ inline __fastcall virtual TdxBarApplicationMenuControlViewInfo(Dxbar::TCustomdxBarControl* ABarControl) : Dxbar::TdxBarSubMenuControlViewInfo(ABarControl) { }
	/* TCustomdxBarControlViewInfo.Destroy */ inline __fastcall virtual ~TdxBarApplicationMenuControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarExtraPaneControl;
class PASCALIMPLEMENTATION TdxBarExtraPaneControl : public Dxbar::TdxBarControl
{
	typedef Dxbar::TdxBarControl inherited;
	
private:
	System::Types::TRect FHeaderRect;
	bool FIsControlsCreated;
	int __fastcall CalculateHeaderHeight(void);
	int __fastcall GetActuallyVisibleItemsCount(void);
	bool __fastcall GetAllowPinItems(void);
	TdxBarApplicationMenuControl* __fastcall GetBasicControl(void);
	System::Types::TRect __fastcall GetHeaderSeparatorRect(void);
	System::Types::TRect __fastcall GetHeaderTextRect(void);
	void __fastcall SetHeaderFontTo(Cxgraphics::TcxCanvas* ACanvas);
	
protected:
	virtual void __fastcall CalcControlsPositions(void);
	virtual void __fastcall CalcItemsRect(void);
	virtual bool __fastcall CanMoving(void);
	virtual bool __fastcall CanProcessMouseMessage(void);
	virtual bool __fastcall CanSetMouseSelectedItem(const System::Types::TPoint &P, Dxbar::TdxBarItemControl* AItemControl);
	virtual bool __fastcall CanShowHint(void);
	virtual bool __fastcall CanShowPopupMenuOnMouseClick(bool AMousePressed);
	virtual bool __fastcall CanUpdateControlByMouseOnLostFocus(void);
	virtual void __fastcall DoCreateControls(void);
	virtual void __fastcall DoDestroyControls(void);
	virtual void __fastcall DoDrawBeginGroup(const System::Types::TRect &ASeparatorRect, bool AHorz);
	virtual void __fastcall DoNCPaint(HDC DC);
	virtual void __fastcall DoHideAll(Dxbar::TdxBarCloseUpReason AReason);
	void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, HBRUSH ABrush, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContentBackground(void);
	void __fastcall DrawHeaderSeparator(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawHeaderText(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall FillBackground(HDC ADC, const System::Types::TRect &ARect, HBRUSH ABrush, System::Uitypes::TColor AColor, bool AIsClientArea);
	virtual Dxbar::TdxBarItemLink* __fastcall FindLinkWithAccel(System::Word AKey, System::Classes::TShiftState AShift, Dxbar::TdxBarItemLink* ACurrentLink, /* out */ bool &ADuplicate);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Dxbar::TdxBarBehaviorOptions __fastcall GetBehaviorOptions(void);
	virtual Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	virtual Dxbar::TCustomdxBarControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall IsMeaningParent(HWND AWnd);
	virtual void __fastcall LayoutChanged(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall SetAccelSelectedItem(Dxbar::TdxBarItemControl* AItemControl, bool ADuplicate);
	virtual void __fastcall SetMouseSelectedItem(Dxbar::TdxBarItemControl* Value);
	virtual void __fastcall InitCustomizationPopup(Dxbar::TdxBarItemLinks* AItemLinks);
	virtual void __fastcall ShowPopup(Dxbar::TdxBarItemControl* AItem);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	__property int ActuallyVisibleItemsCount = {read=GetActuallyVisibleItemsCount, nodefault};
	__property bool AllowPinItems = {read=GetAllowPinItems, nodefault};
	__property TdxBarApplicationMenuControl* BasicControl = {read=GetBasicControl};
	__property System::Types::TRect HeaderRect = {read=FHeaderRect};
	__property System::Types::TRect HeaderSeparatorRect = {read=GetHeaderSeparatorRect};
	__property System::Types::TRect HeaderTextRect = {read=GetHeaderTextRect};
	
public:
	virtual void __fastcall HideAllByEscape(void);
public:
	/* TdxBarControl.Create */ inline __fastcall virtual TdxBarExtraPaneControl(System::Classes::TComponent* AOwner) : Dxbar::TdxBarControl(AOwner) { }
	/* TdxBarControl.Destroy */ inline __fastcall virtual ~TdxBarExtraPaneControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarExtraPaneControl(HWND ParentWindow) : Dxbar::TdxBarControl(ParentWindow) { }
	
};


class DELPHICLASS TdxBarExtraPaneDockControl;
class PASCALIMPLEMENTATION TdxBarExtraPaneDockControl : public Dxbar::TdxBarDockControl
{
	typedef Dxbar::TdxBarDockControl inherited;
	
protected:
	virtual void __fastcall CalcRowToolbarPositions(int ARowIndex, int AClientSize);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Dxbar::TdxBarControlClass __fastcall GetDockedBarControlClass(void);
	virtual bool __fastcall GetSunkenBorder(void);
	
public:
	__fastcall virtual TdxBarExtraPaneDockControl(System::Classes::TComponent* AOwner);
public:
	/* TdxDockControl.CreateEx */ inline __fastcall TdxBarExtraPaneDockControl(System::Classes::TComponent* AOwner, Dxbar::TdxBarManager* ABarManager, Dxbar::TdxBarDockingStyle ADockStyle) : Dxbar::TdxBarDockControl(AOwner, ABarManager, ADockStyle) { }
	/* TdxDockControl.Destroy */ inline __fastcall virtual ~TdxBarExtraPaneDockControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarExtraPaneDockControl(HWND ParentWindow) : Dxbar::TdxBarDockControl(ParentWindow) { }
	
};


class DELPHICLASS TdxBarExtraPaneControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarExtraPaneControlViewInfo : public Dxbar::TdxBarControlViewInfo
{
	typedef Dxbar::TdxBarControlViewInfo inherited;
	
protected:
	virtual void __fastcall DoCalcSeparatorInfo(Dxbar::TdxBarItemLink* AItemLink, const System::Types::TRect &AItemRect);
public:
	/* TCustomdxBarControlViewInfo.Create */ inline __fastcall virtual TdxBarExtraPaneControlViewInfo(Dxbar::TCustomdxBarControl* ABarControl) : Dxbar::TdxBarControlViewInfo(ABarControl) { }
	/* TCustomdxBarControlViewInfo.Destroy */ inline __fastcall virtual ~TdxBarExtraPaneControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarExtraPaneButton;
class PASCALIMPLEMENTATION TdxBarExtraPaneButton : public Dxbar::TdxBarButton
{
	typedef Dxbar::TdxBarButton inherited;
	
private:
	TdxBarExtraPaneItem* FExtraPaneItem;
	bool __fastcall GetPin(void);
	void __fastcall SetExtraPaneItem(TdxBarExtraPaneItem* AValue);
	void __fastcall SetPin(bool AValue);
	
protected:
	virtual Dxbar::TdxBarItemControlClass __fastcall GetControlClass(bool AIsVertical);
	__property TdxBarExtraPaneItem* ExtraPaneItem = {read=FExtraPaneItem, write=SetExtraPaneItem};
	__property bool Pin = {read=GetPin, write=SetPin, nodefault};
public:
	/* TdxBarButton.Create */ inline __fastcall virtual TdxBarExtraPaneButton(System::Classes::TComponent* AOwner) : Dxbar::TdxBarButton(AOwner) { }
	
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxBarExtraPaneButton(void) { }
	
};


class DELPHICLASS TdxBarExtraPanePinnedButton;
class PASCALIMPLEMENTATION TdxBarExtraPanePinnedButton : public TdxBarExtraPaneButton
{
	typedef TdxBarExtraPaneButton inherited;
	
protected:
	virtual Dxbar::TdxBarItemControlClass __fastcall GetControlClass(bool AIsVertical);
public:
	/* TdxBarButton.Create */ inline __fastcall virtual TdxBarExtraPanePinnedButton(System::Classes::TComponent* AOwner) : TdxBarExtraPaneButton(AOwner) { }
	
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxBarExtraPanePinnedButton(void) { }
	
};


class DELPHICLASS TdxBarExtraPaneButtonControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarExtraPaneButtonControl : public Dxbar::TdxBarButtonControl
{
	typedef Dxbar::TdxBarButtonControl inherited;
	
private:
	HIDESBASE Dxbar::TdxBarExtraMenuButtonControlDrawParams* __fastcall GetDrawParams(void);
	HIDESBASE TdxBarExtraPaneButton* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall DoPaint(const System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	virtual Dxbar::TdxBarItemControlDrawParamsClass __fastcall GetDrawParamsClass(void);
	virtual void __fastcall GetTextColors(bool AEnabled, bool ASelected, bool AFlat, System::Uitypes::TColor &AColor1, System::Uitypes::TColor &AColor2);
	
public:
	__property Dxbar::TdxBarExtraMenuButtonControlDrawParams* DrawParams = {read=GetDrawParams};
	__property TdxBarExtraPaneButton* Item = {read=GetItem};
public:
	/* TdxBarButtonLikeControl.Destroy */ inline __fastcall virtual ~TdxBarExtraPaneButtonControl(void) { }
	
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxBarExtraPaneButtonControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarButtonControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarExtraPanePinnedButtonControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarExtraPanePinnedButtonControl : public TdxBarExtraPaneButtonControl
{
	typedef TdxBarExtraPaneButtonControl inherited;
	
private:
	bool __fastcall GetPin(void);
	void __fastcall SetPin(bool AValue);
	
protected:
	virtual void __fastcall CalcDrawParams(bool AFull = true);
	virtual void __fastcall CalcParts(void);
	virtual void __fastcall ControlUnclick(bool ByMouse);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual int __fastcall GetPartCount(void);
	
public:
	__property bool Pin = {read=GetPin, write=SetPin, nodefault};
public:
	/* TdxBarButtonLikeControl.Destroy */ inline __fastcall virtual ~TdxBarExtraPanePinnedButtonControl(void) { }
	
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxBarExtraPanePinnedButtonControl(Dxbar::TdxBarItemLink* AItemLink) : TdxBarExtraPaneButtonControl(AItemLink) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxBarExtraPaneListItem : public Dxbar::TdxBarListItem
{
	typedef Dxbar::TdxBarListItem inherited;
	
private:
	int FActuallyVisibleItemsCount;
	bool FAllowPinItems;
	Dxbar::TdxBarPaintStyle FPaintStyle;
	TdxBarExtraPaneGetDisplayTextEvent FOnGetDisplayText;
	Dxbar::TdxBarPaintStyle __fastcall CalculatePaintStyle(void);
	TdxBarExtraPaneItem* __fastcall GetExtraPaneItem(int AIndex);
	int __fastcall GetExtraPaneItemIndex(void);
	void __fastcall SetActuallyVisibleItemsCount(int AValue);
	
protected:
	virtual Dxbar::TdxBarButton* __fastcall CreateItem(int AIndex, int ACurIndex);
	virtual System::UnicodeString __fastcall GetDisplayHint(const System::UnicodeString AText);
	virtual System::UnicodeString __fastcall GetDisplayText(int AItemIndex)/* overload */;
	virtual Dxbar::TdxBarButtonClass __fastcall GetItemClass(void);
	virtual bool __fastcall InternalActuallyVisible(void);
	virtual void __fastcall PopulateListedItemLinks(Dxbar::TdxBarItemLinks* AItemLinks, System::TObject* ALinkData, int AIndex);
	__property int ActuallyVisibleItemsCount = {read=FActuallyVisibleItemsCount, write=SetActuallyVisibleItemsCount, nodefault};
	__property bool AllowPinItems = {read=FAllowPinItems, write=FAllowPinItems, nodefault};
	__property TdxBarExtraPaneItem* ExtraPaneItem[int AIndex] = {read=GetExtraPaneItem};
	__property int ExtraPaneItemIndex = {read=GetExtraPaneItemIndex, nodefault};
	__property TdxBarExtraPaneGetDisplayTextEvent OnGetDisplayText = {read=FOnGetDisplayText, write=FOnGetDisplayText};
	
public:
	__fastcall virtual TdxBarExtraPaneListItem(System::Classes::TComponent* AOwner);
public:
	/* TdxBarListItem.Destroy */ inline __fastcall virtual ~TdxBarExtraPaneListItem(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline System::UnicodeString __fastcall  GetDisplayText(const System::UnicodeString AText){ return Dxbar::TdxBarListItem::GetDisplayText(AText); }
	
};


class PASCALIMPLEMENTATION TdxBarApplicationMenuControl : public Dxbar::TdxBarSubMenuControl
{
	typedef Dxbar::TdxBarSubMenuControl inherited;
	
private:
	TdxBarApplicationMenuButtonItemLinks* FButtonLinks;
	System::Types::TRect FButtonsRect;
	Dxbar::TdxBarDockControl* FDockControl;
	Dxbar::TdxBar* FExtraPaneBar;
	System::Types::TRect FExtraPaneRect;
	int FExtraPaneSize;
	Dxbar::TdxBarItemLinks* FTotalItemLinks;
	void __fastcall DoGetExtraPaneListItemData(System::TObject* Sender);
	TdxBarCustomApplicationMenu* __fastcall GetApplicationMenu(void);
	TdxBarApplicationMenuExtraPane* __fastcall GetExtraPane(void);
	TdxBarExtraPaneControl* __fastcall GetExtraPaneControl(void);
	Dxbar::TdxBarItemLinks* __fastcall GetExtraPaneItemLinks(void);
	bool __fastcall GetHasExtraPane(void);
	Dxbar::TdxBarItemLinks* __fastcall GetTotalItemLinks(void);
	
protected:
	virtual bool __fastcall CalcChildBarBounds(/* out */ System::Types::TRect &ARect);
	virtual int __fastcall CalcExtraPaneWidth(const System::Types::TSize &AMenuBarSize);
	virtual bool __fastcall CanProcessMouseMessage(void);
	virtual void __fastcall CalcItemRects(Dxbar::TdxBarPaintType APaintStyle, int ATopIndex);
	virtual void __fastcall CalcItemsRect(void);
	virtual void __fastcall DoCalcSize(/* out */ System::Types::TSize &ASize);
	virtual Dxbar::TdxBarDockControlClass __fastcall GetExtraPaneDockControlClass(void);
	virtual Dxbar::TCustomdxBarControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall DoShow(void);
	virtual void __fastcall DrawContent(void);
	void __fastcall DrawContentArea(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoFillBackgroundEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, HBRUSH ABrush, System::Uitypes::TColor AColor, bool AIsClientArea);
	virtual Dxbar::TdxBarItemLink* __fastcall DoFindLinkWithAccel(System::Word AKey, System::Classes::TShiftState AShift, Dxbar::TdxBarItemLink* ACurrentLink);
	virtual Dxbar::TdxBarItemLink* __fastcall FindLinkWithAccel(System::Word AKey, System::Classes::TShiftState AShift, Dxbar::TdxBarItemLink* ACurrentLink, /* out */ bool &ADuplicate);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Dxbar::TdxBarBehaviorOptions __fastcall GetBehaviorOptions(void);
	virtual System::Types::TRect __fastcall GetClientOffset(bool AIncludeDetachCaption = true);
	virtual System::Types::TRect __fastcall GetItemsRectOffset(void);
	virtual bool __fastcall IsControlExists(Dxbar::TdxBarItemControl* ABarItemControl);
	virtual void __fastcall SetAccelSelectedItem(Dxbar::TdxBarItemControl* AItemControl, bool ADuplicate);
	virtual void __fastcall SetControlVisible(Dxbar::TdxBarItemControl* AControl);
	virtual void __fastcall SetItemLinks(Dxbar::TdxBarItemLinks* Value);
	virtual void __fastcall SetMouseSelectedItem(Dxbar::TdxBarItemControl* Value);
	bool __fastcall CanCreateExtraPaneControl(void);
	void __fastcall CreateExtraPaneControls(void);
	void __fastcall ShowExtraPaneControl(void);
	__property TdxBarCustomApplicationMenu* ApplicationMenu = {read=GetApplicationMenu};
	__property TdxBarApplicationMenuButtonItemLinks* ButtonLinks = {read=FButtonLinks};
	__property TdxBarApplicationMenuExtraPane* ExtraPane = {read=GetExtraPane};
	__property TdxBarExtraPaneControl* ExtraPaneControl = {read=GetExtraPaneControl};
	__property Dxbar::TdxBarDockControl* ExtraPaneControlDockControl = {read=FDockControl};
	__property Dxbar::TdxBarItemLinks* ExtraPaneItemLinks = {read=GetExtraPaneItemLinks};
	__property bool HasExtraPane = {read=GetHasExtraPane, nodefault};
	__property Dxbar::TdxBarItemLinks* TotalItemLinks = {read=GetTotalItemLinks};
	
public:
	__fastcall virtual TdxBarApplicationMenuControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarApplicationMenuControl(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarApplicationMenuControl(HWND ParentWindow) : Dxbar::TdxBarSubMenuControl(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxbarapplicationmenu */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARAPPLICATIONMENU)
using namespace Dxbarapplicationmenu;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarapplicationmenuHPP
