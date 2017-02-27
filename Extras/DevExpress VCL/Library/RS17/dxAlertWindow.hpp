// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxAlertWindow.pas' rev: 24.00 (Win32)

#ifndef DxalertwindowHPP
#define DxalertwindowHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxalertwindow
{
//-- type declarations -------------------------------------------------------
enum TdxAlertWindowAnimation : unsigned char { awaNone, awaSlide, awaFade, awaMove };

enum TdxAlertWindowCaptionButton : unsigned char { awcbDropdown, awcbPin, awcbClose };

typedef System::Set<TdxAlertWindowCaptionButton, TdxAlertWindowCaptionButton::awcbDropdown, TdxAlertWindowCaptionButton::awcbClose>  TdxAlertWindowCaptionButtons;

enum TdxAlertWindowVisibilityTransition : unsigned char { awvtNone, awvtShowing, awvtHiding };

enum TdxAlertWindowMovingDirection : unsigned char { awmdAuto, awmdLeft, awmdRight, awmdUp, awmdDown };

enum TdxAlertWindowNavigationPanelVisibility : unsigned char { awnpvAuto, awnpvAlways, awnpvNever };

enum TdxAlertWindowPosition : unsigned char { awpAuto, awpTopLeft, awpTopRight, awpBottomLeft, awpBottomRight };

class DELPHICLASS TdxAlertWindowMessage;
class DELPHICLASS TdxAlertWindowMessageList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowMessage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FCaption;
	System::Uitypes::TImageIndex FImageIndex;
	TdxAlertWindowMessageList* FOwner;
	System::UnicodeString FText;
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex AValue);
	void __fastcall SetText(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall Changed(void);
	__property TdxAlertWindowMessageList* Owner = {read=FOwner};
	
public:
	__fastcall virtual TdxAlertWindowMessage(TdxAlertWindowMessageList* AOwner);
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property System::UnicodeString Text = {read=FText, write=SetText};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowMessage(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxAlertWindowMessageList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxAlertWindowMessage* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TNotifyEvent FOnChange;
	HIDESBASE TdxAlertWindowMessage* __fastcall GetItem(int AIndex);
	
protected:
	virtual void __fastcall Changed(void);
	bool __fastcall IsValid(int AIndex);
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	HIDESBASE TdxAlertWindowMessage* __fastcall Add(void)/* overload */;
	HIDESBASE TdxAlertWindowMessage* __fastcall Add(const System::UnicodeString ACaption, const System::UnicodeString AText, System::Uitypes::TImageIndex AImageIndex)/* overload */;
	__property TdxAlertWindowMessage* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxAlertWindowMessageList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAlertWindowMessageList(void) { }
	
};


class DELPHICLASS TdxAlertWindowCustomOptions;
class PASCALIMPLEMENTATION TdxAlertWindowCustomOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Classes::TNotifyEvent FOnChange;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	__property Dxcoreclasses::TcxFreeNotificator* FreeNotificator = {read=FFreeNotificator};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TdxAlertWindowCustomOptions(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxAlertWindowCustomOptions(void);
};


class DELPHICLASS TdxAlertWindowOptionsAnimate;
class PASCALIMPLEMENTATION TdxAlertWindowOptionsAnimate : public TdxAlertWindowCustomOptions
{
	typedef TdxAlertWindowCustomOptions inherited;
	
private:
	System::Byte FAlphaBlendValue;
	TdxAlertWindowAnimation FHidingAnimation;
	TdxAlertWindowMovingDirection FHidingAnimationDirection;
	unsigned FHidingAnimationTime;
	bool FHotTrack;
	System::Byte FHotTrackAlphaBlendValue;
	unsigned FHotTrackFadeInTime;
	unsigned FHotTrackFadeOutTime;
	TdxAlertWindowAnimation FShowingAnimation;
	TdxAlertWindowMovingDirection FShowingAnimationDirection;
	unsigned FShowingAnimationTime;
	void __fastcall SetAlphaBlendValue(System::Byte AValue);
	void __fastcall SetHidingAnimation(TdxAlertWindowAnimation AValue);
	void __fastcall SetHidingAnimationDirection(TdxAlertWindowMovingDirection AValue);
	void __fastcall SetHidingAnimationTime(unsigned AValue);
	void __fastcall SetHotTrack(bool AValue);
	void __fastcall SetHotTrackAlphaBlendValue(System::Byte AValue);
	void __fastcall SetHotTrackFadeInTime(unsigned AValue);
	void __fastcall SetHotTrackFadeOutTime(unsigned AValue);
	void __fastcall SetShowingAnimation(TdxAlertWindowAnimation AValue);
	void __fastcall SetShowingAnimationDirection(TdxAlertWindowMovingDirection AValue);
	void __fastcall SetShowingAnimationTime(unsigned AValue);
	
public:
	__fastcall virtual TdxAlertWindowOptionsAnimate(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Byte AlphaBlendValue = {read=FAlphaBlendValue, write=SetAlphaBlendValue, default=190};
	__property TdxAlertWindowAnimation HidingAnimation = {read=FHidingAnimation, write=SetHidingAnimation, default=2};
	__property TdxAlertWindowMovingDirection HidingAnimationDirection = {read=FHidingAnimationDirection, write=SetHidingAnimationDirection, default=0};
	__property unsigned HidingAnimationTime = {read=FHidingAnimationTime, write=SetHidingAnimationTime, default=1000};
	__property bool HotTrack = {read=FHotTrack, write=SetHotTrack, default=1};
	__property System::Byte HotTrackAlphaBlendValue = {read=FHotTrackAlphaBlendValue, write=SetHotTrackAlphaBlendValue, default=250};
	__property unsigned HotTrackFadeInTime = {read=FHotTrackFadeInTime, write=SetHotTrackFadeInTime, default=100};
	__property unsigned HotTrackFadeOutTime = {read=FHotTrackFadeOutTime, write=SetHotTrackFadeOutTime, default=1000};
	__property TdxAlertWindowAnimation ShowingAnimation = {read=FShowingAnimation, write=SetShowingAnimation, default=2};
	__property TdxAlertWindowMovingDirection ShowingAnimationDirection = {read=FShowingAnimationDirection, write=SetShowingAnimationDirection, default=0};
	__property unsigned ShowingAnimationTime = {read=FShowingAnimationTime, write=SetShowingAnimationTime, default=100};
public:
	/* TdxAlertWindowCustomOptions.Destroy */ inline __fastcall virtual ~TdxAlertWindowOptionsAnimate(void) { }
	
};


class DELPHICLASS TdxAlertWindowOptionsBehavior;
class PASCALIMPLEMENTATION TdxAlertWindowOptionsBehavior : public TdxAlertWindowCustomOptions
{
	typedef TdxAlertWindowCustomOptions inherited;
	
private:
	bool FCloseOnRightClick;
	unsigned FDisplayTime;
	bool FScreenSnap;
	int FScreenSnapBuffer;
	void __fastcall SetCloseOnRightClick(bool AValue);
	void __fastcall SetDisplayTime(unsigned AValue);
	void __fastcall SetScreenSnap(bool AValue);
	void __fastcall SetScreenSnapBuffer(int AValue);
	
public:
	__fastcall virtual TdxAlertWindowOptionsBehavior(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CloseOnRightClick = {read=FCloseOnRightClick, write=SetCloseOnRightClick, default=1};
	__property unsigned DisplayTime = {read=FDisplayTime, write=SetDisplayTime, default=7000};
	__property bool ScreenSnap = {read=FScreenSnap, write=SetScreenSnap, default=1};
	__property int ScreenSnapBuffer = {read=FScreenSnapBuffer, write=SetScreenSnapBuffer, default=20};
public:
	/* TdxAlertWindowCustomOptions.Destroy */ inline __fastcall virtual ~TdxAlertWindowOptionsBehavior(void) { }
	
};


class DELPHICLASS TdxAlertWindowOptionsText;
class PASCALIMPLEMENTATION TdxAlertWindowOptionsText : public TdxAlertWindowCustomOptions
{
	typedef TdxAlertWindowCustomOptions inherited;
	
private:
	System::Classes::TAlignment FAlignHorz;
	Cxclasses::TcxAlignmentVert FAlignVert;
	Vcl::Graphics::TFont* FFont;
	void __fastcall SetAlignHorz(System::Classes::TAlignment AValue);
	void __fastcall SetAlignVert(Cxclasses::TcxAlignmentVert AValue);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	
protected:
	virtual void __fastcall DoFontChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TdxAlertWindowOptionsText(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxAlertWindowOptionsText(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Classes::TAlignment AlignHorz = {read=FAlignHorz, write=SetAlignHorz, default=0};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=FAlignVert, write=SetAlignVert, default=0};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont};
};


class DELPHICLASS TdxAlertWindowOptionsMessage;
class PASCALIMPLEMENTATION TdxAlertWindowOptionsMessage : public TdxAlertWindowCustomOptions
{
	typedef TdxAlertWindowCustomOptions inherited;
	
private:
	TdxAlertWindowOptionsText* FCaption;
	Vcl::Imglist::TChangeLink* FChangeLink;
	Vcl::Imglist::TCustomImageList* FImages;
	TdxAlertWindowOptionsText* FText;
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetCaption(TdxAlertWindowOptionsText* AValue);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetText(TdxAlertWindowOptionsText* AValue);
	
protected:
	virtual void __fastcall DoOptionTextChange(System::TObject* Sender);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	
public:
	__fastcall virtual TdxAlertWindowOptionsMessage(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxAlertWindowOptionsMessage(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxAlertWindowOptionsText* Caption = {read=FCaption, write=SetCaption};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TdxAlertWindowOptionsText* Text = {read=FText, write=SetText};
};


class DELPHICLASS TdxAlertWindowOptionsNavigationPanel;
class PASCALIMPLEMENTATION TdxAlertWindowOptionsNavigationPanel : public TdxAlertWindowCustomOptions
{
	typedef TdxAlertWindowCustomOptions inherited;
	
private:
	System::UnicodeString FDisplayMask;
	Vcl::Graphics::TFont* FFont;
	TdxAlertWindowNavigationPanelVisibility FVisibility;
	int FWidth;
	bool __fastcall IsDisplayMaskStored(void);
	void __fastcall SetDisplayMask(const System::UnicodeString AValue);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetVisibility(TdxAlertWindowNavigationPanelVisibility AValue);
	void __fastcall SetWidth(int AValue);
	
protected:
	virtual void __fastcall DoFontChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TdxAlertWindowOptionsNavigationPanel(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxAlertWindowOptionsNavigationPanel(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::UnicodeString DisplayMask = {read=FDisplayMask, write=SetDisplayMask, stored=IsDisplayMaskStored};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property TdxAlertWindowNavigationPanelVisibility Visibility = {read=FVisibility, write=SetVisibility, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
};


class DELPHICLASS TdxAlertWindowOptionsCaptionButtons;
class PASCALIMPLEMENTATION TdxAlertWindowOptionsCaptionButtons : public TdxAlertWindowCustomOptions
{
	typedef TdxAlertWindowCustomOptions inherited;
	
private:
	TdxAlertWindowCaptionButtons FCaptionButtons;
	System::Classes::TComponent* FPopupMenu;
	void __fastcall SetCaptionButtons(TdxAlertWindowCaptionButtons AValue);
	void __fastcall SetPopupMenu(System::Classes::TComponent* AValue);
	
protected:
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	
public:
	__fastcall virtual TdxAlertWindowOptionsCaptionButtons(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxAlertWindowCaptionButtons CaptionButtons = {read=FCaptionButtons, write=SetCaptionButtons, default=7};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
public:
	/* TdxAlertWindowCustomOptions.Destroy */ inline __fastcall virtual ~TdxAlertWindowOptionsCaptionButtons(void) { }
	
};


class DELPHICLASS TdxAlertWindowOptionsSize;
class PASCALIMPLEMENTATION TdxAlertWindowOptionsSize : public TdxAlertWindowCustomOptions
{
	typedef TdxAlertWindowCustomOptions inherited;
	
private:
	bool FAutoHeight;
	bool FAutoWidth;
	int FHeight;
	int FMaxHeight;
	int FMaxWidth;
	int FMinHeight;
	int FMinWidth;
	int FWidth;
	void __fastcall SetAutoHeight(bool AValue);
	void __fastcall SetAutoWidth(bool AValue);
	void __fastcall SetHeight(int AValue);
	void __fastcall SetMaxHeight(int AValue);
	void __fastcall SetMaxWidth(int AValue);
	void __fastcall SetMinHeight(int AValue);
	void __fastcall SetMinWidth(int AValue);
	void __fastcall SetWidth(int AValue);
	
public:
	__fastcall virtual TdxAlertWindowOptionsSize(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AutoHeight = {read=FAutoHeight, write=SetAutoHeight, default=0};
	__property bool AutoWidth = {read=FAutoWidth, write=SetAutoWidth, default=0};
	__property int MaxHeight = {read=FMaxHeight, write=SetMaxHeight, default=0};
	__property int MaxWidth = {read=FMaxWidth, write=SetMaxWidth, default=0};
	__property int MinHeight = {read=FMinHeight, write=SetMinHeight, default=100};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=200};
	__property int Height = {read=FHeight, write=SetHeight, default=100};
	__property int Width = {read=FWidth, write=SetWidth, default=200};
public:
	/* TdxAlertWindowCustomOptions.Destroy */ inline __fastcall virtual ~TdxAlertWindowOptionsSize(void) { }
	
};


class DELPHICLASS TdxAlertWindowButton;
class DELPHICLASS TdxAlertWindowButtons;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowButton : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool FEnabled;
	System::UnicodeString FHint;
	System::Uitypes::TImageIndex FImageIndex;
	bool FVisible;
	TdxAlertWindowButtons* __fastcall GetCollection(void);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetHint(const System::UnicodeString AValue);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	__property TdxAlertWindowButtons* Collection = {read=GetCollection};
	
public:
	__fastcall virtual TdxAlertWindowButton(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property System::UnicodeString Hint = {read=FHint, write=SetHint};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxAlertWindowButton(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxAlertWindowButtonClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowButtons : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TdxAlertWindowButton* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxAlertWindowButton* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxAlertWindowButton* AValue);
	
protected:
	__classmethod virtual TdxAlertWindowButtonClass __fastcall GetButtonClass();
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TdxAlertWindowButtons(System::Classes::TPersistent* AOwner);
	HIDESBASE TdxAlertWindowButton* __fastcall Add(void);
	__property TdxAlertWindowButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxAlertWindowButtons(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowOptionsButtons;
class PASCALIMPLEMENTATION TdxAlertWindowOptionsButtons : public TdxAlertWindowCustomOptions
{
	typedef TdxAlertWindowCustomOptions inherited;
	
private:
	TdxAlertWindowButtons* FButtons;
	Vcl::Imglist::TChangeLink* FChangeLink;
	int FHeight;
	Vcl::Imglist::TCustomImageList* FImages;
	int FWidth;
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetButtons(TdxAlertWindowButtons* AValue);
	void __fastcall SetHeight(int AValue);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetWidth(int AValue);
	
protected:
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	
public:
	__fastcall virtual TdxAlertWindowOptionsButtons(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxAlertWindowOptionsButtons(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxAlertWindowButtons* Buttons = {read=FButtons, write=SetButtons};
	__property int Height = {read=FHeight, write=SetHeight, default=24};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property int Width = {read=FWidth, write=SetWidth, default=24};
};


__interface IdxAlertWindow;
typedef System::DelphiInterface<IdxAlertWindow> _di_IdxAlertWindow;
class DELPHICLASS TdxAlertWindowViewInfo;
class DELPHICLASS TdxAlertWindowCustomButtonViewInfo;
class DELPHICLASS TdxAlertWindowCaptionTextViewInfo;
class DELPHICLASS TdxAlertWindowImageViewInfo;
class DELPHICLASS TdxAlertWindowMessageTextViewInfo;
class DELPHICLASS TdxAlertWindowNavigationPanelTextViewInfo;
class DELPHICLASS TdxAlertWindowController;
__interface  INTERFACE_UUID("{3979BEBB-2A61-4410-A0E2-C83DB48F360A}") IdxAlertWindow  : public System::IInterface 
{
	
public:
	virtual void __fastcall ButtonClick(int AButtonIndex) = 0 ;
	virtual void __fastcall Close(void) = 0 ;
	virtual bool __fastcall DoCaptionButtonClick(TdxAlertWindowCaptionButton AButton) = 0 ;
	virtual bool __fastcall DoCustomDrawBackground(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowViewInfo* AViewInfo) = 0 ;
	virtual bool __fastcall DoCustomDrawButton(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCustomButtonViewInfo* AViewInfo) = 0 ;
	virtual bool __fastcall DoCustomDrawMessageCaptionText(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCaptionTextViewInfo* AViewInfo) = 0 ;
	virtual bool __fastcall DoCustomDrawMessageImage(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowImageViewInfo* AViewInfo) = 0 ;
	virtual bool __fastcall DoCustomDrawMessageText(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowMessageTextViewInfo* AViewInfo) = 0 ;
	virtual bool __fastcall DoCustomDrawNavigationPanelText(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowNavigationPanelTextViewInfo* AViewInfo) = 0 ;
	virtual void __fastcall DoMeasureMessageText(int &AWidth, int &AHeight) = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetContainer(void) = 0 ;
	virtual TdxAlertWindowController* __fastcall GetController(void) = 0 ;
	virtual int __fastcall GetCurrentMessageIndex(void) = 0 ;
	virtual bool __fastcall GetIsPopupMenuShown(void) = 0 ;
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void) = 0 ;
	virtual TdxAlertWindowMessageList* __fastcall GetMessages(void) = 0 ;
	virtual TdxAlertWindowOptionsBehavior* __fastcall GetOptionsBehavior(void) = 0 ;
	virtual TdxAlertWindowOptionsButtons* __fastcall GetOptionsButtons(void) = 0 ;
	virtual TdxAlertWindowOptionsCaptionButtons* __fastcall GetOptionsCaptionButtons(void) = 0 ;
	virtual TdxAlertWindowOptionsMessage* __fastcall GetOptionsMessage(void) = 0 ;
	virtual TdxAlertWindowOptionsNavigationPanel* __fastcall GetOptionsNavigationPanel(void) = 0 ;
	virtual bool __fastcall GetPinned(void) = 0 ;
	virtual TdxAlertWindowViewInfo* __fastcall GetViewInfo(void) = 0 ;
	virtual void __fastcall InvalidateRect(const System::Types::TRect &ARect) = 0 ;
	virtual void __fastcall SetCurrentMessageIndex(int AValue) = 0 ;
	virtual void __fastcall SetIsPopupMenuShown(bool AValue) = 0 ;
	virtual void __fastcall SetPinned(bool AValue) = 0 ;
	__property int CurrentMessageIndex = {read=GetCurrentMessageIndex, write=SetCurrentMessageIndex};
	__property bool IsPopupMenuShown = {read=GetIsPopupMenuShown, write=SetIsPopupMenuShown};
	__property bool Pinned = {read=GetPinned, write=SetPinned};
};

class DELPHICLASS TdxAlertWindowCustomViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCustomViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	_di_IdxAlertWindow FOwner;
	TdxAlertWindowController* __fastcall GetController(void);
	TdxAlertWindowMessage* __fastcall GetCurrentMessage(void);
	int __fastcall GetMessageCount(void);
	int __fastcall GetMessageIndex(void);
	TdxAlertWindowMessageList* __fastcall GetMessages(void);
	TdxAlertWindowOptionsButtons* __fastcall GetOptionsButtons(void);
	TdxAlertWindowOptionsMessage* __fastcall GetOptionsMessage(void);
	TdxAlertWindowOptionsNavigationPanel* __fastcall GetOptionsNavigationPanel(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	virtual System::UnicodeString __fastcall GetHint(void);
	
public:
	__fastcall virtual TdxAlertWindowCustomViewInfo(_di_IdxAlertWindow AOwner);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual TdxAlertWindowCustomViewInfo* __fastcall GetHitTest(const System::Types::TPoint &APoint);
	void __fastcall Invalidate(void);
	virtual void __fastcall RecreateViewInfo(void);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TdxAlertWindowController* Controller = {read=GetController};
	__property TdxAlertWindowMessage* CurrentMessage = {read=GetCurrentMessage};
	__property System::UnicodeString Hint = {read=GetHint};
	__property int MessageCount = {read=GetMessageCount, nodefault};
	__property int MessageIndex = {read=GetMessageIndex, nodefault};
	__property TdxAlertWindowMessageList* Messages = {read=GetMessages};
	__property TdxAlertWindowOptionsButtons* OptionsButtons = {read=GetOptionsButtons};
	__property TdxAlertWindowOptionsMessage* OptionsMessage = {read=GetOptionsMessage};
	__property TdxAlertWindowOptionsNavigationPanel* OptionsNavigationPanel = {read=GetOptionsNavigationPanel};
	__property _di_IdxAlertWindow Owner = {read=FOwner};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCustomViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowCustomTextViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCustomTextViewInfo : public TdxAlertWindowCustomViewInfo
{
	typedef TdxAlertWindowCustomViewInfo inherited;
	
private:
	bool FIsTextClipped;
	
protected:
	unsigned __fastcall FormatText(System::Classes::TAlignment AAlignHorz, Cxclasses::TcxAlignmentVert AAlignVert);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void);
	virtual unsigned __fastcall GetDrawTextFlags(void) = 0 ;
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void) = 0 ;
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual bool __fastcall GetIsTextClipped(void);
	virtual System::UnicodeString __fastcall GetText(void) = 0 ;
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	__property unsigned DrawTextFlags = {read=GetDrawTextFlags, nodefault};
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property bool IsTextClipped = {read=FIsTextClipped, write=FIsTextClipped, nodefault};
	__property System::UnicodeString Text = {read=GetText};
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowCustomTextViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCustomTextViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxAlertWindowCustomButtonViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCustomButtonViewInfo : public TdxAlertWindowCustomViewInfo
{
	typedef TdxAlertWindowCustomViewInfo inherited;
	
protected:
	virtual void __fastcall Click(void) = 0 ;
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	virtual bool __fastcall GetEnabled(void);
	virtual System::Types::TSize __fastcall GetGlyphSize(void);
	virtual Cxlookandfeelpainters::TdxAlertWindowButtonKind __fastcall GetKind(void) = 0 ;
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	
public:
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
	__property System::Types::TRect ContentOffsets = {read=GetContentOffsets};
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property System::Types::TSize GlyphSize = {read=GetGlyphSize};
	__property Cxlookandfeelpainters::TdxAlertWindowButtonKind Kind = {read=GetKind, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=GetState, nodefault};
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowCustomButtonViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCustomButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowPreviousButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowPreviousButtonViewInfo : public TdxAlertWindowCustomButtonViewInfo
{
	typedef TdxAlertWindowCustomButtonViewInfo inherited;
	
protected:
	virtual void __fastcall Click(void);
	virtual bool __fastcall GetEnabled(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual Cxlookandfeelpainters::TdxAlertWindowButtonKind __fastcall GetKind(void);
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowPreviousButtonViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomButtonViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowPreviousButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowNextButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowNextButtonViewInfo : public TdxAlertWindowCustomButtonViewInfo
{
	typedef TdxAlertWindowCustomButtonViewInfo inherited;
	
protected:
	virtual void __fastcall Click(void);
	virtual bool __fastcall GetEnabled(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual Cxlookandfeelpainters::TdxAlertWindowButtonKind __fastcall GetKind(void);
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowNextButtonViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomButtonViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowNextButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowCloseButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCloseButtonViewInfo : public TdxAlertWindowCustomButtonViewInfo
{
	typedef TdxAlertWindowCustomButtonViewInfo inherited;
	
protected:
	virtual void __fastcall Click(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual Cxlookandfeelpainters::TdxAlertWindowButtonKind __fastcall GetKind(void);
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowCloseButtonViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomButtonViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCloseButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowPinButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowPinButtonViewInfo : public TdxAlertWindowCustomButtonViewInfo
{
	typedef TdxAlertWindowCustomButtonViewInfo inherited;
	
protected:
	virtual void __fastcall Click(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual Cxlookandfeelpainters::TdxAlertWindowButtonKind __fastcall GetKind(void);
	bool __fastcall GetPinned(void);
	
public:
	__property bool Pinned = {read=GetPinned, nodefault};
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowPinButtonViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomButtonViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowPinButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowDropdownButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowDropdownButtonViewInfo : public TdxAlertWindowCustomButtonViewInfo
{
	typedef TdxAlertWindowCustomButtonViewInfo inherited;
	
protected:
	virtual void __fastcall Click(void);
	virtual bool __fastcall GetEnabled(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual Cxlookandfeelpainters::TdxAlertWindowButtonKind __fastcall GetKind(void);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowDropdownButtonViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomButtonViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowDropdownButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowButtonViewInfo : public TdxAlertWindowCustomButtonViewInfo
{
	typedef TdxAlertWindowCustomButtonViewInfo inherited;
	
private:
	TdxAlertWindowButton* FButtonItem;
	bool __fastcall GetIsImageAssigned(void);
	
protected:
	virtual void __fastcall Click(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetEnabled(void);
	virtual System::Types::TSize __fastcall GetGlyphSize(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual Cxlookandfeelpainters::TdxAlertWindowButtonKind __fastcall GetKind(void);
	
public:
	__fastcall virtual TdxAlertWindowButtonViewInfo(_di_IdxAlertWindow AOwner, TdxAlertWindowButton* AButtonItem);
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
	__property TdxAlertWindowButton* ButtonItem = {read=FButtonItem};
	__property bool IsImageAssigned = {read=GetIsImageAssigned, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowButtonsViewInfoList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowButtonsViewInfoList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxAlertWindowCustomButtonViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxAlertWindowCustomButtonViewInfo* __fastcall GetItem(int AIndex);
	
public:
	HIDESBASE int __fastcall Add(TdxAlertWindowCustomButtonViewInfo* AButton)/* overload */;
	HIDESBASE int __fastcall Add(_di_IdxAlertWindow AOwner, TdxAlertWindowButton* AButtonItem)/* overload */;
	HIDESBASE int __fastcall Add(_di_IdxAlertWindow AOwner, TdxAlertWindowCustomButtonViewInfoClass AButtonViewInfoClass)/* overload */;
	__property TdxAlertWindowCustomButtonViewInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxAlertWindowButtonsViewInfoList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAlertWindowButtonsViewInfoList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowCustomButtonsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCustomButtonsViewInfo : public TdxAlertWindowCustomViewInfo
{
	typedef TdxAlertWindowCustomViewInfo inherited;
	
private:
	TdxAlertWindowButtonsViewInfoList* FButtons;
	int __fastcall GetButtonsCount(void);
	System::Types::TSize __fastcall GetButtonSize(int ANumButton);
	
protected:
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxAlertWindowCustomButtonsViewInfo(_di_IdxAlertWindow AOwner);
	__fastcall virtual ~TdxAlertWindowCustomButtonsViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
	virtual TdxAlertWindowCustomViewInfo* __fastcall GetHitTest(const System::Types::TPoint &APoint);
	virtual void __fastcall RecreateViewInfo(void);
	__property TdxAlertWindowButtonsViewInfoList* Buttons = {read=FButtons};
	__property int ButtonsCount = {read=GetButtonsCount, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowButtonsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowButtonsViewInfo : public TdxAlertWindowCustomButtonsViewInfo
{
	typedef TdxAlertWindowCustomButtonsViewInfo inherited;
	
public:
	virtual void __fastcall RecreateViewInfo(void);
public:
	/* TdxAlertWindowCustomButtonsViewInfo.Create */ inline __fastcall virtual TdxAlertWindowButtonsViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomButtonsViewInfo(AOwner) { }
	/* TdxAlertWindowCustomButtonsViewInfo.Destroy */ inline __fastcall virtual ~TdxAlertWindowButtonsViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowCaptionButtonsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCaptionButtonsViewInfo : public TdxAlertWindowCustomButtonsViewInfo
{
	typedef TdxAlertWindowCustomButtonsViewInfo inherited;
	
public:
	virtual void __fastcall RecreateViewInfo(void);
public:
	/* TdxAlertWindowCustomButtonsViewInfo.Create */ inline __fastcall virtual TdxAlertWindowCaptionButtonsViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomButtonsViewInfo(AOwner) { }
	/* TdxAlertWindowCustomButtonsViewInfo.Destroy */ inline __fastcall virtual ~TdxAlertWindowCaptionButtonsViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowImageViewInfo : public TdxAlertWindowCustomViewInfo
{
	typedef TdxAlertWindowCustomViewInfo inherited;
	
private:
	System::Uitypes::TImageIndex __fastcall GetImageIndex(void);
	bool __fastcall GetIsImageAssigned(void);
	
protected:
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
	__property System::Uitypes::TImageIndex ImageIndex = {read=GetImageIndex, nodefault};
	__property bool IsImageAssigned = {read=GetIsImageAssigned, nodefault};
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowImageViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowImageViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCaptionTextViewInfo : public TdxAlertWindowCustomTextViewInfo
{
	typedef TdxAlertWindowCustomTextViewInfo inherited;
	
protected:
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual unsigned __fastcall GetDrawTextFlags(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual bool __fastcall GetIsTextClipped(void);
	virtual System::UnicodeString __fastcall GetText(void);
	
public:
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowCaptionTextViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomTextViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCaptionTextViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowMessageTextViewInfo : public TdxAlertWindowCustomTextViewInfo
{
	typedef TdxAlertWindowCustomTextViewInfo inherited;
	
protected:
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual unsigned __fastcall GetDrawTextFlags(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual bool __fastcall GetIsTextClipped(void);
	virtual System::UnicodeString __fastcall GetText(void);
	
public:
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowMessageTextViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomTextViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowMessageTextViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowNavigationPanelTextViewInfo : public TdxAlertWindowCustomTextViewInfo
{
	typedef TdxAlertWindowCustomTextViewInfo inherited;
	
protected:
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void);
	virtual unsigned __fastcall GetDrawTextFlags(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual bool __fastcall GetIsTextClipped(void);
	virtual System::UnicodeString __fastcall GetText(void);
	
public:
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
	virtual int __fastcall CalculateAutoHeight(int AWidth);
public:
	/* TdxAlertWindowCustomViewInfo.Create */ inline __fastcall virtual TdxAlertWindowNavigationPanelTextViewInfo(_di_IdxAlertWindow AOwner) : TdxAlertWindowCustomTextViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowNavigationPanelTextViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowNavigationPanelViewInfo;
class DELPHICLASS TdxAlertWindowNavigationPanelContentCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowNavigationPanelViewInfo : public TdxAlertWindowCustomViewInfo
{
	typedef TdxAlertWindowCustomViewInfo inherited;
	
private:
	TdxAlertWindowNavigationPanelTextViewInfo* FInfoPanelText;
	TdxAlertWindowNextButtonViewInfo* FNextButton;
	TdxAlertWindowPreviousButtonViewInfo* FPreviousButton;
	TdxAlertWindowNavigationPanelContentCalculator* FContentCalculator;
	
protected:
	__property TdxAlertWindowNavigationPanelContentCalculator* ContentCalculator = {read=FContentCalculator};
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TdxAlertWindowNavigationPanelViewInfo(_di_IdxAlertWindow AOwner);
	__fastcall virtual ~TdxAlertWindowNavigationPanelViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
	virtual TdxAlertWindowCustomViewInfo* __fastcall GetHitTest(const System::Types::TPoint &APoint);
	__property TdxAlertWindowNavigationPanelTextViewInfo* InfoPanelText = {read=FInfoPanelText};
	__property TdxAlertWindowNextButtonViewInfo* NextButton = {read=FNextButton};
	__property TdxAlertWindowPreviousButtonViewInfo* PreviousButton = {read=FPreviousButton};
	__property bool Visible = {read=GetVisible, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowContentCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowViewInfo : public TdxAlertWindowCustomViewInfo
{
	typedef TdxAlertWindowCustomViewInfo inherited;
	
public:
	TdxAlertWindowCustomViewInfo* operator[](int Index) { return ViewInfoItem[Index]; }
	
private:
	TdxAlertWindowButtonsViewInfo* FButtonsViewInfo;
	TdxAlertWindowCaptionButtonsViewInfo* FCaptionButtonsViewInfo;
	TdxAlertWindowCaptionTextViewInfo* FCaptionTextViewInfo;
	TdxAlertWindowContentCalculator* FContentCalculator;
	TdxAlertWindowImageViewInfo* FImageViewInfo;
	TdxAlertWindowMessageTextViewInfo* FMessageTextViewInfo;
	TdxAlertWindowNavigationPanelViewInfo* FNavigationPanelViewInfo;
	System::Classes::TList* FViewInfoList;
	int __fastcall GetItemCount(void);
	
protected:
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual TdxAlertWindowCustomViewInfo* __fastcall GetViewInfoItem(int Index);
	__property TdxAlertWindowContentCalculator* ContentCalculator = {read=FContentCalculator};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxAlertWindowCustomViewInfo* ViewInfoItem[int Index] = {read=GetViewInfoItem/*, default*/};
	
public:
	__fastcall virtual TdxAlertWindowViewInfo(_di_IdxAlertWindow AOwner);
	__fastcall virtual ~TdxAlertWindowViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual int __fastcall CalculateAutoHeight(int AWidth);
	virtual int __fastcall CalculateAutoWidth(int AHeight = 0xffffffff);
	virtual void __fastcall CalculateCustomSize(TdxAlertWindowOptionsSize* AOptionsSize, int &AWidth, int &AHeight);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual TdxAlertWindowCustomViewInfo* __fastcall GetHitTest(const System::Types::TPoint &APoint);
	virtual void __fastcall RecreateViewInfo(void);
	__property TdxAlertWindowButtonsViewInfo* ButtonsViewInfo = {read=FButtonsViewInfo};
	__property TdxAlertWindowCaptionButtonsViewInfo* CaptionButtonsViewInfo = {read=FCaptionButtonsViewInfo};
	__property TdxAlertWindowCaptionTextViewInfo* CaptionTextViewInfo = {read=FCaptionTextViewInfo};
	__property TdxAlertWindowImageViewInfo* ImageViewInfo = {read=FImageViewInfo};
	__property TdxAlertWindowMessageTextViewInfo* MessageTextViewInfo = {read=FMessageTextViewInfo};
	__property TdxAlertWindowNavigationPanelViewInfo* NavigationPanelViewInfo = {read=FNavigationPanelViewInfo};
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowCustomElementPlace;
class DELPHICLASS TdxAlertWindowCustomContentCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCustomElementPlace : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCalculatedHeight;
	int FCalculatedWidth;
	TdxAlertWindowCustomContentCalculator* FContentCalculator;
	TdxAlertWindowCustomViewInfo* FViewInfo;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void) = 0 ;
	virtual int __fastcall GetCalculatedHeight(void);
	virtual int __fastcall GetCalculatedWidth(void);
	virtual bool __fastcall GetCustomCalculate(void);
	virtual int __fastcall GetHeightForCalculating(void);
	virtual int __fastcall GetWidthForCalculating(void);
	
public:
	__fastcall TdxAlertWindowCustomElementPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property int CalculatedHeight = {read=GetCalculatedHeight, write=FCalculatedHeight, nodefault};
	__property int CalculatedWidth = {read=GetCalculatedWidth, write=FCalculatedWidth, nodefault};
	__property TdxAlertWindowCustomContentCalculator* ContentCalculator = {read=FContentCalculator};
	__property bool CustomCalculate = {read=GetCustomCalculate, nodefault};
	__property TdxAlertWindowCustomViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCustomElementPlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowImagePlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowImagePlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowImagePlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowImagePlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowButtonsPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowButtonsPlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowButtonsPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowButtonsPlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowCaptionButtonsPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCaptionButtonsPlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowCaptionButtonsPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCaptionButtonsPlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowNavigationPanelPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowNavigationPanelPlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual TdxAlertWindowContentCalculator* __fastcall GetContentCalculator(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowNavigationPanelPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowNavigationPanelPlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowCaptionTextPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCaptionTextPlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual TdxAlertWindowContentCalculator* __fastcall GetContentCalculator(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowCaptionTextPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCaptionTextPlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowMessageTextPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowMessageTextPlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual TdxAlertWindowContentCalculator* __fastcall GetContentCalculator(void);
	virtual int __fastcall GetHeightForCalculating(void);
	virtual int __fastcall GetWidthForCalculating(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowMessageTextPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowMessageTextPlace(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowCustomContentCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxAlertWindowCustomViewInfo* FViewInfo;
	bool FCustomCalculate;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void) = 0 ;
	virtual int __fastcall GetContentHeight(void) = 0 ;
	virtual int __fastcall GetContentWidth(void) = 0 ;
	
public:
	__fastcall virtual TdxAlertWindowCustomContentCalculator(TdxAlertWindowCustomViewInfo* AViewInfo);
	__property System::Types::TRect Bounds = {read=GetBounds, write=FBounds};
	__property int ContentHeight = {read=GetContentHeight, nodefault};
	__property int ContentWidth = {read=GetContentWidth, nodefault};
	__property bool CustomCalculate = {read=FCustomCalculate, write=FCustomCalculate, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowCustomContentCalculator(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowContentCalculator : public TdxAlertWindowCustomContentCalculator
{
	typedef TdxAlertWindowCustomContentCalculator inherited;
	
private:
	TdxAlertWindowButtonsPlace* FButtonsPlace;
	TdxAlertWindowCaptionButtonsPlace* FCaptionButtonsPlace;
	TdxAlertWindowCaptionTextPlace* FCaptionTextPlace;
	TdxAlertWindowImagePlace* FImagePlace;
	TdxAlertWindowMessageTextPlace* FMessageTextPlace;
	TdxAlertWindowNavigationPanelPlace* FNavigationPanelPlace;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual int __fastcall GetContentHeight(void);
	virtual int __fastcall GetContentWidth(void);
	TdxAlertWindowViewInfo* __fastcall GetViewInfo(void);
	
public:
	__fastcall virtual TdxAlertWindowContentCalculator(TdxAlertWindowCustomViewInfo* AViewInfo);
	__fastcall virtual ~TdxAlertWindowContentCalculator(void);
	__property TdxAlertWindowButtonsPlace* ButtonsPlace = {read=FButtonsPlace};
	__property TdxAlertWindowCaptionButtonsPlace* CaptionButtonsPlace = {read=FCaptionButtonsPlace};
	__property TdxAlertWindowCaptionTextPlace* CaptionTextPlace = {read=FCaptionTextPlace};
	__property TdxAlertWindowImagePlace* ImagePlace = {read=FImagePlace};
	__property TdxAlertWindowMessageTextPlace* MessageTextPlace = {read=FMessageTextPlace};
	__property TdxAlertWindowNavigationPanelPlace* NavigationPanelPlace = {read=FNavigationPanelPlace};
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowPreviousButtonPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowPreviousButtonPlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowPreviousButtonPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowPreviousButtonPlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowNextButtonPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowNextButtonPlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowNextButtonPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowNextButtonPlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowInfoPanelTextPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowInfoPanelTextPlace : public TdxAlertWindowCustomElementPlace
{
	typedef TdxAlertWindowCustomElementPlace inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual TdxAlertWindowNavigationPanelContentCalculator* __fastcall GetContentCalculator(void);
	virtual int __fastcall GetWidthForCalculating(void);
public:
	/* TdxAlertWindowCustomElementPlace.Create */ inline __fastcall TdxAlertWindowInfoPanelTextPlace(TdxAlertWindowCustomContentCalculator* AContentCalculator, TdxAlertWindowCustomViewInfo* AViewInfo) : TdxAlertWindowCustomElementPlace(AContentCalculator, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowInfoPanelTextPlace(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowNavigationPanelContentCalculator : public TdxAlertWindowCustomContentCalculator
{
	typedef TdxAlertWindowCustomContentCalculator inherited;
	
private:
	TdxAlertWindowInfoPanelTextPlace* FInfoPanelTextPlace;
	TdxAlertWindowNextButtonPlace* FNextButtonPlace;
	TdxAlertWindowPreviousButtonPlace* FPreviousButtonPlace;
	
protected:
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual int __fastcall GetContentHeight(void);
	virtual int __fastcall GetContentWidth(void);
	virtual TdxAlertWindowNavigationPanelViewInfo* __fastcall GetViewInfo(void);
	
public:
	__fastcall virtual TdxAlertWindowNavigationPanelContentCalculator(TdxAlertWindowCustomViewInfo* AViewInfo);
	__fastcall virtual ~TdxAlertWindowNavigationPanelContentCalculator(void);
	__property TdxAlertWindowInfoPanelTextPlace* InfoPanelTextPlace = {read=FInfoPanelTextPlace};
	__property TdxAlertWindowNextButtonPlace* NextButtonPlace = {read=FNextButtonPlace};
	__property TdxAlertWindowPreviousButtonPlace* PreviousButtonPlace = {read=FPreviousButtonPlace};
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowCustomAnimationController;
class PASCALIMPLEMENTATION TdxAlertWindowCustomAnimationController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxTimer* FTimer;
	System::Classes::TNotifyEvent FOnAnimation;
	System::Classes::TNotifyEvent FOnAnimationComplete;
	void __fastcall InternalStopAnimation(void);
	bool __fastcall GetActive(void);
	void __fastcall StartAnimationTimer(void);
	void __fastcall StopAnimationTimer(void);
	void __fastcall TimerHandler(System::TObject* Sender);
	
protected:
	int FFramesCount;
	virtual void __fastcall DoAnimation(void);
	virtual void __fastcall DoAnimationComplete(void);
	virtual unsigned __fastcall GetAnimationTimerInterval(void);
	virtual void __fastcall JumpToFinalState(void) = 0 ;
	virtual void __fastcall ProcessStep(void) = 0 ;
	
public:
	__fastcall virtual ~TdxAlertWindowCustomAnimationController(void);
	virtual void __fastcall StopAnimation(void);
	__property bool Active = {read=GetActive, nodefault};
	__property System::Classes::TNotifyEvent OnAnimation = {read=FOnAnimation, write=FOnAnimation};
	__property System::Classes::TNotifyEvent OnAnimationComplete = {read=FOnAnimationComplete, write=FOnAnimationComplete};
public:
	/* TObject.Create */ inline __fastcall TdxAlertWindowCustomAnimationController(void) : System::TObject() { }
	
};


class DELPHICLASS TdxAlertWindowMovingAnimationController;
class PASCALIMPLEMENTATION TdxAlertWindowMovingAnimationController : public TdxAlertWindowCustomAnimationController
{
	typedef TdxAlertWindowCustomAnimationController inherited;
	
private:
	System::Types::TRect FBaseRect;
	System::Types::TPoint FFinishPoint;
	System::Types::TPoint FStartPoint;
	float FStepMovingX;
	float FStepMovingY;
	float FWorkingPointX;
	float FWorkingPointY;
	void __fastcall SetBaseRect(const System::Types::TRect &AValue);
	void __fastcall SetWorkingPoint(float X, float Y);
	
protected:
	virtual System::Types::TPoint __fastcall GetCurrentPoint(void);
	virtual System::Types::TRect __fastcall GetCurrentWindowRect(void);
	virtual void __fastcall JumpToFinalState(void);
	virtual void __fastcall ProcessStep(void);
	void __fastcall StartAnimation(const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AFinishPoint, unsigned ATime)/* overload */;
	__property System::Types::TRect BaseRect = {read=FBaseRect, write=SetBaseRect};
	
public:
	void __fastcall StartAnimation(const System::Types::TRect &AStartRect, const System::Types::TPoint &AFinishPoint, unsigned ATime)/* overload */;
	__property System::Types::TRect CurrentWindowRect = {read=GetCurrentWindowRect};
	__property System::Types::TPoint FinishPoint = {read=FFinishPoint};
	__property System::Types::TPoint StartPoint = {read=FStartPoint};
public:
	/* TdxAlertWindowCustomAnimationController.Destroy */ inline __fastcall virtual ~TdxAlertWindowMovingAnimationController(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxAlertWindowMovingAnimationController(void) : TdxAlertWindowCustomAnimationController() { }
	
};


class DELPHICLASS TdxAlertWindowSlidingAnimationController;
class PASCALIMPLEMENTATION TdxAlertWindowSlidingAnimationController : public TdxAlertWindowMovingAnimationController
{
	typedef TdxAlertWindowMovingAnimationController inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetCurrentContentRect(void);
	virtual System::Types::TRect __fastcall GetCurrentWindowRect(void);
	virtual void __fastcall JumpToFinalState(void);
	
public:
	HIDESBASE void __fastcall StartAnimation(const System::Types::TRect &ARect, bool AShowing, TdxAlertWindowMovingDirection ADirection, unsigned ATime)/* overload */;
	__property System::Types::TRect CurrentContentRect = {read=GetCurrentContentRect};
public:
	/* TdxAlertWindowCustomAnimationController.Destroy */ inline __fastcall virtual ~TdxAlertWindowSlidingAnimationController(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxAlertWindowSlidingAnimationController(void) : TdxAlertWindowMovingAnimationController() { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  StartAnimation(const System::Types::TPoint &AStartPoint, const System::Types::TPoint &AFinishPoint, unsigned ATime){ TdxAlertWindowMovingAnimationController::StartAnimation(AStartPoint, AFinishPoint, ATime); }
	
public:
	inline void __fastcall  StartAnimation(const System::Types::TRect &AStartRect, const System::Types::TPoint &AFinishPoint, unsigned ATime){ TdxAlertWindowMovingAnimationController::StartAnimation(AStartRect, AFinishPoint, ATime); }
	
};


class DELPHICLASS TdxAlertWindowFadingAnimationController;
class PASCALIMPLEMENTATION TdxAlertWindowFadingAnimationController : public TdxAlertWindowCustomAnimationController
{
	typedef TdxAlertWindowCustomAnimationController inherited;
	
private:
	float FAlphaStep;
	System::Byte FFinishAlphaValue;
	float FWorkingAlphaValue;
	System::Byte __fastcall GetCurrentAlphaValue(void);
	
protected:
	virtual void __fastcall JumpToFinalState(void);
	virtual void __fastcall ProcessStep(void);
	
public:
	void __fastcall StartAnimation(System::Byte AStartAlphaValue, System::Byte AFinishAlphaValue, unsigned ATime);
	__property System::Byte CurrentAlphaValue = {read=GetCurrentAlphaValue, nodefault};
public:
	/* TdxAlertWindowCustomAnimationController.Destroy */ inline __fastcall virtual ~TdxAlertWindowFadingAnimationController(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxAlertWindowFadingAnimationController(void) : TdxAlertWindowCustomAnimationController() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	_di_IdxAlertWindow FAlertWindow;
	TdxAlertWindowCustomButtonViewInfo* FHotButton;
	TdxAlertWindowCustomButtonViewInfo* FPressedButton;
	TdxAlertWindowCustomButtonViewInfo* __fastcall ButtonHitTest(const System::Types::TPoint &APoint);
	TdxAlertWindowViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetHotButton(TdxAlertWindowCustomButtonViewInfo* AValue);
	void __fastcall SetPressedButton(TdxAlertWindowCustomButtonViewInfo* AValue);
	
protected:
	virtual void __fastcall ButtonsClick(int AButtonindex);
	virtual void __fastcall Close(void);
	virtual void __fastcall MouseDown(const System::Types::TPoint &P);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(const System::Types::TPoint &P);
	virtual void __fastcall MouseUp(const System::Types::TPoint &P, System::Uitypes::TMouseButton Button);
	virtual void __fastcall NextMessage(void);
	virtual void __fastcall PreviousMessage(void);
	virtual void __fastcall ShowPopupMenu(void);
	virtual void __fastcall TogglePin(void);
	__property _di_IdxAlertWindow AlertWindow = {read=FAlertWindow};
	__property TdxAlertWindowCustomButtonViewInfo* HotButton = {read=FHotButton, write=SetHotButton};
	__property TdxAlertWindowCustomButtonViewInfo* PressedButton = {read=FPressedButton, write=SetPressedButton};
	__property TdxAlertWindowViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxAlertWindowController(_di_IdxAlertWindow AAlertWindow);
	__fastcall virtual ~TdxAlertWindowController(void);
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowAnimationHelper;
class DELPHICLASS TdxAlertWindow;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowAnimationHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxAlertWindow* FAlertWindow;
	TdxAlertWindowFadingAnimationController* FFadingAnimationController;
	TdxAlertWindowMovingAnimationController* FMovingAnimationController;
	TdxAlertWindowOptionsAnimate* FOptionsAnimate;
	TdxAlertWindowSlidingAnimationController* FSlidingAnimationController;
	TdxAlertWindowAnimation FVisibilityAnimation;
	System::Types::TRect __fastcall CalculateFinishRectMoving(void);
	System::Types::TRect __fastcall CalculateStartRectMoving(void);
	int __fastcall GetAlphaBlendValue(void);
	System::Types::TRect __fastcall GetBoundsRect(void);
	System::Types::TRect __fastcall GetContentRect(void);
	void __fastcall SetAlphaBlendValue(int AValue);
	void __fastcall SetBoundsRect(const System::Types::TRect &AValue);
	void __fastcall SetOptionsAnimate(TdxAlertWindowOptionsAnimate* AValue);
	void __fastcall Show(void);
	void __fastcall AnimationOptionsChanged(System::TObject* Sender);
	void __fastcall AnimationComplete(TdxAlertWindowAnimation AAnimation);
	void __fastcall FadingAnimationHandler(System::TObject* Sender);
	void __fastcall FadingCompleteAnimationHandler(System::TObject* Sender);
	void __fastcall MovingAnimationHandler(System::TObject* Sender);
	void __fastcall MovingCompleteAnimationHandler(System::TObject* Sender);
	void __fastcall SlidingAnimationHandler(System::TObject* Sender);
	void __fastcall SlidingCompleteAnimationHandler(System::TObject* Sender);
	
protected:
	virtual TdxAlertWindowMovingDirection __fastcall GetRealMovingDirection(TdxAlertWindowVisibilityTransition AVisibilityTransition);
	__property TdxAlertWindow* AlertWindow = {read=FAlertWindow};
	__property int AlphaBlendValue = {read=GetAlphaBlendValue, write=SetAlphaBlendValue, nodefault};
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property TdxAlertWindowFadingAnimationController* FadingAnimationController = {read=FFadingAnimationController};
	__property TdxAlertWindowMovingAnimationController* MovingAnimationController = {read=FMovingAnimationController};
	__property TdxAlertWindowSlidingAnimationController* SlidingAnimationController = {read=FSlidingAnimationController};
	
public:
	__fastcall virtual TdxAlertWindowAnimationHelper(TdxAlertWindow* AOwner);
	__fastcall virtual ~TdxAlertWindowAnimationHelper(void);
	void __fastcall HideAnimation(void);
	void __fastcall ShowAnimation(void);
	void __fastcall StopAnimation(void);
	void __fastcall UpdateAlphaBlendValue(void);
	__property System::Types::TRect ContentRect = {read=GetContentRect};
	__property TdxAlertWindowOptionsAnimate* OptionsAnimate = {read=FOptionsAnimate, write=SetOptionsAnimate};
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowHitTest : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxAlertWindow* FAlertWindow;
	System::Types::TPoint FHitPoint;
	TdxAlertWindowCustomViewInfo* FViewInfo;
	void __fastcall SetHitPoint(const System::Types::TPoint &APoint);
	bool __fastcall GetHitAtBackground(void);
	bool __fastcall GetHitAtButton(void);
	bool __fastcall GetHitAtCaptionButtonClose(void);
	bool __fastcall GetHitAtCaptionButtonDropdown(void);
	bool __fastcall GetHitAtCaptionButtonPin(void);
	bool __fastcall GetHitAtMessageCaptionText(void);
	bool __fastcall GetHitAtMessageImage(void);
	bool __fastcall GetHitAtMessageText(void);
	bool __fastcall GetHitAtNavigationPanelNextButton(void);
	bool __fastcall GetHitAtNavigationPanelPreviousButton(void);
	bool __fastcall GetHitAtNavigationPanelText(void);
	bool __fastcall GetHitAtWindowArea(void);
	TdxAlertWindowViewInfo* __fastcall GetHitBackground(void);
	TdxAlertWindowButtonViewInfo* __fastcall GetHitButton(void);
	TdxAlertWindowCloseButtonViewInfo* __fastcall GetHitCaptionButtonClose(void);
	TdxAlertWindowDropdownButtonViewInfo* __fastcall GetHitCaptionButtonDropdown(void);
	TdxAlertWindowPinButtonViewInfo* __fastcall GetHitCaptionButtonPin(void);
	TdxAlertWindowCaptionTextViewInfo* __fastcall GetHitMessageCaptionText(void);
	TdxAlertWindowImageViewInfo* __fastcall GetHitMessageImage(void);
	TdxAlertWindowMessageTextViewInfo* __fastcall GetHitMessageText(void);
	TdxAlertWindowNextButtonViewInfo* __fastcall GetHitNavigationPanelNextButton(void);
	TdxAlertWindowPreviousButtonViewInfo* __fastcall GetHitNavigationPanelPreviousButton(void);
	TdxAlertWindowNavigationPanelTextViewInfo* __fastcall GetHitNavigationPanelText(void);
	
public:
	__fastcall virtual TdxAlertWindowHitTest(TdxAlertWindow* AOwner);
	void __fastcall ReCalculate(void)/* overload */;
	void __fastcall ReCalculate(const System::Types::TPoint &APoint)/* overload */;
	__property bool HitAtBackground = {read=GetHitAtBackground, nodefault};
	__property bool HitAtButton = {read=GetHitAtButton, nodefault};
	__property bool HitAtCaptionButtonClose = {read=GetHitAtCaptionButtonClose, nodefault};
	__property bool HitAtCaptionButtonDropdown = {read=GetHitAtCaptionButtonDropdown, nodefault};
	__property bool HitAtCaptionButtonPin = {read=GetHitAtCaptionButtonPin, nodefault};
	__property bool HitAtMessageCaptionText = {read=GetHitAtMessageCaptionText, nodefault};
	__property bool HitAtMessageImage = {read=GetHitAtMessageImage, nodefault};
	__property bool HitAtMessageText = {read=GetHitAtMessageText, nodefault};
	__property bool HitAtNavigationPanelNextButton = {read=GetHitAtNavigationPanelNextButton, nodefault};
	__property bool HitAtNavigationPanelPreviousButton = {read=GetHitAtNavigationPanelPreviousButton, nodefault};
	__property bool HitAtNavigationPanelText = {read=GetHitAtNavigationPanelText, nodefault};
	__property bool HitAtWindowArea = {read=GetHitAtWindowArea, nodefault};
	__property TdxAlertWindowViewInfo* HitBackground = {read=GetHitBackground};
	__property TdxAlertWindowButtonViewInfo* HitButton = {read=GetHitButton};
	__property TdxAlertWindowCloseButtonViewInfo* HitCaptionButtonClose = {read=GetHitCaptionButtonClose};
	__property TdxAlertWindowDropdownButtonViewInfo* HitCaptionButtonDropdown = {read=GetHitCaptionButtonDropdown};
	__property TdxAlertWindowPinButtonViewInfo* HitCaptionButtonPin = {read=GetHitCaptionButtonPin};
	__property TdxAlertWindowCaptionTextViewInfo* HitMessageCaptionText = {read=GetHitMessageCaptionText};
	__property TdxAlertWindowImageViewInfo* HitMessageImage = {read=GetHitMessageImage};
	__property TdxAlertWindowMessageTextViewInfo* HitMessageText = {read=GetHitMessageText};
	__property TdxAlertWindowNextButtonViewInfo* HitNavigationPanelNextButton = {read=GetHitNavigationPanelNextButton};
	__property TdxAlertWindowPreviousButtonViewInfo* HitNavigationPanelPreviousButton = {read=GetHitNavigationPanelPreviousButton};
	__property TdxAlertWindowNavigationPanelTextViewInfo* HitNavigationPanelText = {read=GetHitNavigationPanelText};
	__property System::Types::TPoint HitPoint = {read=FHitPoint, write=SetHitPoint};
	__property TdxAlertWindowCustomViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowHitTest(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxAlertWindowCustomDrawBackgroundEvent)(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowCustomDrawButtonEvent)(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCustomButtonViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowCustomDrawMessageCaptionTextEvent)(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCaptionTextViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowCustomDrawMessageImageEvent)(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowImageViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowCustomDrawMessageTextEvent)(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowMessageTextViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowCustomDrawNavigationPanelTextEvent)(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowNavigationPanelTextViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowButtonClickEvent)(TdxAlertWindow* AAlertWindow, int AButtonIndex);

typedef void __fastcall (__closure *TdxAlertWindowCaptionButtonClickEvent)(TdxAlertWindow* AAlertWindow, TdxAlertWindowCaptionButton AButton, bool &AHandled);

typedef void __fastcall (__closure *TdxAlertWindowDragBeginEvent)(TdxAlertWindow* AAlertWindow, bool &AAllow);

typedef void __fastcall (__closure *TdxAlertWindowMeasureEvent)(TdxAlertWindow* AAlertWindow, int &AWidth, int &AHeight);

typedef void __fastcall (__closure *TdxAlertWindowMouseEvent)(TdxAlertWindow* AAlertWindow, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);

typedef void __fastcall (__closure *TdxAlertWindowMouseMoveEvent)(TdxAlertWindow* AAlertWindow, System::Classes::TShiftState AShift, int X, int Y);

typedef void __fastcall (__closure *TdxAlertWindowNotifyEvent)(TdxAlertWindow* AAlertWindow);

class PASCALIMPLEMENTATION TdxAlertWindow : public Vcl::Forms::TCustomForm
{
	typedef Vcl::Forms::TCustomForm inherited;
	
private:
	TdxAlertWindowAnimationHelper* FAnimationHelper;
	bool FMouseHoldForDragging;
	TdxAlertWindowController* FController;
	int FCurrentMessageIndex;
	Cxclasses::TcxTimer* FDisplayTimer;
	bool FDragging;
	System::Types::TPoint FDraggingPoint;
	TdxAlertWindowHitTest* FHitTest;
	bool FIsPopupMenuShown;
	int FLockCount;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TdxAlertWindowMessageList* FMessageList;
	bool FMouseInControl;
	TdxAlertWindowOptionsBehavior* FOptionsBehavior;
	TdxAlertWindowOptionsButtons* FOptionsButtons;
	TdxAlertWindowOptionsCaptionButtons* FOptionsCaptionButtons;
	TdxAlertWindowOptionsMessage* FOptionsMessage;
	TdxAlertWindowOptionsNavigationPanel* FOptionsNavigationPanel;
	TdxAlertWindowOptionsSize* FOptionsSize;
	bool FPinned;
	TdxAlertWindowViewInfo* FViewInfo;
	TdxAlertWindowVisibilityTransition FVisibilityTransition;
	TdxAlertWindowCustomDrawBackgroundEvent FOnCustomDrawBackground;
	TdxAlertWindowCustomDrawButtonEvent FOnCustomDrawButton;
	TdxAlertWindowCustomDrawMessageCaptionTextEvent FOnCustomDrawMessageCaptionText;
	TdxAlertWindowCustomDrawMessageImageEvent FOnCustomDrawMessageImage;
	TdxAlertWindowCustomDrawMessageTextEvent FOnCustomDrawMessageText;
	TdxAlertWindowCustomDrawNavigationPanelTextEvent FOnCustomDrawNavigationPanelText;
	TdxAlertWindowDragBeginEvent FOnDragBegin;
	TdxAlertWindowNotifyEvent FOnDragEnd;
	TdxAlertWindowNotifyEvent FOnDragMove;
	TdxAlertWindowMouseEvent FOnMouseDown;
	TdxAlertWindowNotifyEvent FOnMouseEnter;
	TdxAlertWindowNotifyEvent FOnMouseLeave;
	TdxAlertWindowMouseMoveEvent FOnMouseMove;
	TdxAlertWindowMouseEvent FOnMouseUp;
	TdxAlertWindowButtonClickEvent FOnButtonClick;
	TdxAlertWindowCaptionButtonClickEvent FOnCaptionButtonClick;
	TdxAlertWindowNotifyEvent FOnClick;
	TdxAlertWindowNotifyEvent FOnHide;
	TdxAlertWindowMeasureEvent FOnMeasureMessageText;
	TdxAlertWindowNotifyEvent FOnShow;
	void __fastcall DisplayTimerHandler(System::TObject* Sender);
	bool __fastcall GetVisible(void);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetMessageList(TdxAlertWindowMessageList* AValue);
	void __fastcall SetMouseInControl(bool AValue);
	void __fastcall SetOptionsAnimate(TdxAlertWindowOptionsAnimate* AValue);
	void __fastcall SetOptionsBehavior(TdxAlertWindowOptionsBehavior* AValue);
	void __fastcall SetOptionsButtons(TdxAlertWindowOptionsButtons* AValue);
	void __fastcall SetOptionsCaptionButtons(TdxAlertWindowOptionsCaptionButtons* AValue);
	void __fastcall SetOptionsMessage(TdxAlertWindowOptionsMessage* AValue);
	void __fastcall SetOptionsNavigationPanel(TdxAlertWindowOptionsNavigationPanel* AValue);
	void __fastcall SetOptionsSize(TdxAlertWindowOptionsSize* AValue);
	void __fastcall StartDisplayTimer(void);
	void __fastcall StopDisplayTimer(void);
	void __fastcall StopVisibilityTransition(void);
	void __fastcall UpdateDisplayTimerState(void);
	
protected:
	virtual void __fastcall BehaviorOptionsChanged(System::TObject* Sender);
	virtual void __fastcall ButtonsOptionsChanged(System::TObject* Sender);
	virtual void __fastcall LookAndFeelOptionsChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall MessagesChanged(System::TObject* Sender);
	virtual void __fastcall OptionsChanged(System::TObject* Sender);
	virtual void __fastcall SizeOptionsChanged(System::TObject* Sender);
	virtual void __fastcall CalculateAutoSize(int AWidth, int AHeight);
	virtual void __fastcall CalculateViewInfo(void);
	HIDESBASE virtual void __fastcall Changed(void);
	DYNAMIC void __fastcall Click(void);
	virtual TdxAlertWindowHitTest* __fastcall CreateHitTest(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual TdxAlertWindowViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall DoButtonClick(int AButtonIndex);
	virtual void __fastcall DoClick(void);
	virtual bool __fastcall DoDragBegin(void);
	virtual void __fastcall DoDragEnd(void);
	virtual void __fastcall DoDragMove(void);
	DYNAMIC void __fastcall DoHide(void);
	HIDESBASE virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall DoMouseEnter(void);
	virtual void __fastcall DoMouseLeave(void);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState AShift, int X, int Y);
	HIDESBASE virtual void __fastcall DoMouseUp(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	DYNAMIC void __fastcall DoShow(void);
	TdxAlertWindowOptionsAnimate* __fastcall GetOptionsAnimate(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall SetWindowRegion(int ACornerRadius);
	void __fastcall VisibilityTransitionComplete(void);
	void __fastcall MouseLeave(void);
	bool __fastcall PtInCaller(const System::Types::TPoint &P);
	void __fastcall ButtonClick(int AButtonIndex);
	virtual bool __fastcall DoCaptionButtonClick(TdxAlertWindowCaptionButton AButton);
	virtual bool __fastcall DoCustomDrawBackground(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawButton(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCustomButtonViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawMessageCaptionText(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCaptionTextViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawMessageImage(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowImageViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawMessageText(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowMessageTextViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawNavigationPanelText(Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowNavigationPanelTextViewInfo* AViewInfo);
	virtual void __fastcall DoMeasureMessageText(int &AWidth, int &AHeight);
	Vcl::Controls::TWinControl* __fastcall GetContainer(void);
	TdxAlertWindowController* __fastcall GetController(void);
	int __fastcall GetCurrentMessageIndex(void);
	bool __fastcall GetIsPopupMenuShown(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	TdxAlertWindowMessageList* __fastcall GetMessages(void);
	TdxAlertWindowOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TdxAlertWindowOptionsButtons* __fastcall GetOptionsButtons(void);
	TdxAlertWindowOptionsCaptionButtons* __fastcall GetOptionsCaptionButtons(void);
	TdxAlertWindowOptionsMessage* __fastcall GetOptionsMessage(void);
	TdxAlertWindowOptionsNavigationPanel* __fastcall GetOptionsNavigationPanel(void);
	TdxAlertWindowOptionsSize* __fastcall GetOptionsSize(void);
	bool __fastcall GetPinned(void);
	TdxAlertWindowViewInfo* __fastcall GetViewInfo(void);
	void __fastcall InvalidateRect(const System::Types::TRect &ARect);
	void __fastcall SetCurrentMessageIndex(int AValue);
	void __fastcall SetIsPopupMenuShown(bool AValue);
	void __fastcall SetPinned(bool AValue);
	bool __fastcall IsSkinnable(void);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	__property TdxAlertWindowAnimationHelper* AnimationHelper = {read=FAnimationHelper};
	__property TdxAlertWindowController* Controller = {read=GetController};
	__property int LockCount = {read=FLockCount, nodefault};
	__property bool MouseInControl = {read=FMouseInControl, write=SetMouseInControl, nodefault};
	__property bool IsPopupMenuShown = {read=GetIsPopupMenuShown, write=SetIsPopupMenuShown, nodefault};
	__property TdxAlertWindowViewInfo* ViewInfo = {read=GetViewInfo};
	__property TdxAlertWindowCustomDrawBackgroundEvent OnCustomDrawBackground = {read=FOnCustomDrawBackground, write=FOnCustomDrawBackground};
	__property TdxAlertWindowCustomDrawButtonEvent OnCustomDrawButton = {read=FOnCustomDrawButton, write=FOnCustomDrawButton};
	__property TdxAlertWindowCustomDrawMessageCaptionTextEvent OnCustomDrawMessageCaptionText = {read=FOnCustomDrawMessageCaptionText, write=FOnCustomDrawMessageCaptionText};
	__property TdxAlertWindowCustomDrawMessageImageEvent OnCustomDrawMessageImage = {read=FOnCustomDrawMessageImage, write=FOnCustomDrawMessageImage};
	__property TdxAlertWindowCustomDrawMessageTextEvent OnCustomDrawMessageText = {read=FOnCustomDrawMessageText, write=FOnCustomDrawMessageText};
	__property TdxAlertWindowCustomDrawNavigationPanelTextEvent OnCustomDrawNavigationPanelText = {read=FOnCustomDrawNavigationPanelText, write=FOnCustomDrawNavigationPanelText};
	__property TdxAlertWindowDragBeginEvent OnDragBegin = {read=FOnDragBegin, write=FOnDragBegin};
	__property TdxAlertWindowNotifyEvent OnDragEnd = {read=FOnDragEnd, write=FOnDragEnd};
	__property TdxAlertWindowNotifyEvent OnDragMove = {read=FOnDragMove, write=FOnDragMove};
	__property TdxAlertWindowMouseEvent OnMouseDown = {read=FOnMouseDown, write=FOnMouseDown};
	__property TdxAlertWindowNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property TdxAlertWindowNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	__property TdxAlertWindowMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=FOnMouseMove};
	__property TdxAlertWindowMouseEvent OnMouseUp = {read=FOnMouseUp, write=FOnMouseUp};
	__property TdxAlertWindowButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property TdxAlertWindowCaptionButtonClickEvent OnCaptionButtonClick = {read=FOnCaptionButtonClick, write=FOnCaptionButtonClick};
	__property TdxAlertWindowNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TdxAlertWindowNotifyEvent OnHide = {read=FOnHide, write=FOnHide};
	__property TdxAlertWindowMeasureEvent OnMeasureMessageText = {read=FOnMeasureMessageText, write=FOnMeasureMessageText};
	__property TdxAlertWindowNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	
public:
	__fastcall virtual TdxAlertWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxAlertWindow(void);
	void __fastcall BeginUpdate(void);
	void __fastcall DeleteCurrentMessage(void);
	void __fastcall EndUpdate(void);
	HIDESBASE void __fastcall Hide(void);
	void __fastcall RestartDisplayTimer(void);
	HIDESBASE void __fastcall Show(void);
	HIDESBASE void __fastcall Close(void);
	__property int CurrentMessageIndex = {read=GetCurrentMessageIndex, write=SetCurrentMessageIndex, nodefault};
	__property TdxAlertWindowHitTest* HitTest = {read=FHitTest};
	__property Left;
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel, write=SetLookAndFeel};
	__property TdxAlertWindowMessageList* MessageList = {read=GetMessages, write=SetMessageList};
	__property TdxAlertWindowOptionsAnimate* OptionsAnimate = {read=GetOptionsAnimate, write=SetOptionsAnimate};
	__property TdxAlertWindowOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TdxAlertWindowOptionsButtons* OptionsButtons = {read=GetOptionsButtons, write=SetOptionsButtons};
	__property TdxAlertWindowOptionsCaptionButtons* OptionsCaptionButtons = {read=GetOptionsCaptionButtons, write=SetOptionsCaptionButtons};
	__property TdxAlertWindowOptionsMessage* OptionsMessage = {read=GetOptionsMessage, write=SetOptionsMessage};
	__property TdxAlertWindowOptionsNavigationPanel* OptionsNavigationPanel = {read=GetOptionsNavigationPanel, write=SetOptionsNavigationPanel};
	__property TdxAlertWindowOptionsSize* OptionsSize = {read=GetOptionsSize, write=SetOptionsSize};
	__property bool Pinned = {read=GetPinned, write=SetPinned, default=0};
	__property ShowHint;
	__property Top;
	__property TdxAlertWindowVisibilityTransition VisibilityTransition = {read=FVisibilityTransition, nodefault};
	__property bool Visible = {read=GetVisible, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxAlertWindow(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TCustomForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxAlertWindow(HWND ParentWindow) : Vcl::Forms::TCustomForm(ParentWindow) { }
	
private:
	void *__IdxSkinSupport2;	/* Cxlookandfeels::IdxSkinSupport2 */
	void *__IdxAlertWindow;	/* IdxAlertWindow */
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {01C435BA-7DA1-44A4-BE8B-BCE9CE0562AB}
	operator Cxlookandfeels::_di_IdxSkinSupport2()
	{
		Cxlookandfeels::_di_IdxSkinSupport2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport2*(void) { return (Cxlookandfeels::IdxSkinSupport2*)&__IdxSkinSupport2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3979BEBB-2A61-4410-A0E2-C83DB48F360A}
	operator _di_IdxAlertWindow()
	{
		_di_IdxAlertWindow intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxAlertWindow*(void) { return (IdxAlertWindow*)&__IdxAlertWindow; }
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
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	
};


class DELPHICLASS TdxAlertWindowPositionInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowPositionInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxAlertWindow* FAlertWindow;
	System::Types::TRect FInitialBounds;
	TdxAlertWindowPosition FPosition;
	
public:
	__fastcall TdxAlertWindowPositionInfo(TdxAlertWindow* AAlertWindow, TdxAlertWindowPosition APosition);
	bool __fastcall CompareAlertWindow(TdxAlertWindow* AAlertWindow);
	bool __fastcall IsPositionChanged(void);
	__property System::Types::TRect InitialBounds = {read=FInitialBounds};
	__property TdxAlertWindowPosition Position = {read=FPosition, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAlertWindowPositionInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowPositionInfoList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowPositionInfoList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxAlertWindowPositionInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxAlertWindowPositionInfo* __fastcall GetItem(int AIndex);
	
public:
	HIDESBASE TdxAlertWindowPositionInfo* __fastcall Add(TdxAlertWindow* AAlertWindow, TdxAlertWindowPosition APosition)/* overload */;
	__property TdxAlertWindowPositionInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxAlertWindowPositionInfoList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAlertWindowPositionInfoList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowInitialLayout;
class DELPHICLASS TdxAlertWindowManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowInitialLayout : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxAlertWindowManager* FManager;
	TdxAlertWindowPositionInfoList* FPositionInfoList;
	TdxAlertWindowPositionInfo* __fastcall GetLastInitialGrid(TdxAlertWindowPosition APosition);
	TdxAlertWindow* __fastcall GetNextWindowForShowing(void);
	TdxAlertWindowPosition __fastcall GetPosition(void);
	bool __fastcall HasWindow(TdxAlertWindow* AAlertWindow);
	int __fastcall RemoveItemWithWindow(TdxAlertWindow* AAlertWindow);
	
protected:
	virtual void __fastcall CalculateNextPosition(TdxAlertWindow* AAlertWindow);
	
public:
	__fastcall virtual TdxAlertWindowInitialLayout(TdxAlertWindowManager* AManager);
	__fastcall virtual ~TdxAlertWindowInitialLayout(void);
	void __fastcall AddItem(void);
	void __fastcall DeleteItem(TdxAlertWindow* AAlertWindow);
	__property TdxAlertWindowPosition Position = {read=GetPosition, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TdxAlertWindowClass;

class DELPHICLASS TdxAlertWindowList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxAlertWindow* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxAlertWindow* __fastcall GetItem(int AIndex);
	
public:
	HIDESBASE TdxAlertWindow* __fastcall Add(TdxAlertWindowClass AClass);
	__property TdxAlertWindow* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxAlertWindowList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAlertWindowList(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxAlertWindowManagerCustomDrawBackgroundEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowManagerCustomDrawButtonEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCustomButtonViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowManagerCustomDrawMessageCaptionTextEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCaptionTextViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowManagerCustomDrawMessageImageEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowImageViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowManagerCustomDrawMessageTextEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowMessageTextViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowManagerCustomDrawNavigationPanelTextEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowNavigationPanelTextViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TdxAlertWindowManagerButtonClickEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, int AButtonIndex);

typedef void __fastcall (__closure *TdxAlertWindowManagerCaptionButtonClickEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, TdxAlertWindowCaptionButton AButton, bool &AHandled);

typedef void __fastcall (__closure *TdxAlertWindowManagerDragBeginEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, bool &AAllow);

typedef void __fastcall (__closure *TdxAlertWindowManagerMeasureEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, int &AWidth, int &AHeight);

typedef void __fastcall (__closure *TdxAlertWindowManagerMouseEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);

typedef void __fastcall (__closure *TdxAlertWindowManagerMouseMoveEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow, System::Classes::TShiftState AShift, int X, int Y);

typedef void __fastcall (__closure *TdxAlertWindowManagerNotifyEvent)(System::TObject* Sender, TdxAlertWindow* AAlertWindow);

class PASCALIMPLEMENTATION TdxAlertWindowManager : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
public:
	TdxAlertWindow* operator[](int Index) { return Items[Index]; }
	
private:
	TdxAlertWindowList* FAlertWindows;
	TdxAlertWindow* FHotWindow;
	TdxAlertWindowInitialLayout* FInitialLayout;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TdxAlertWindowOptionsAnimate* FOptionsAnimate;
	TdxAlertWindowOptionsBehavior* FOptionsBehavior;
	TdxAlertWindowOptionsButtons* FOptionsButtons;
	TdxAlertWindowOptionsCaptionButtons* FOptionsCaptionButtons;
	TdxAlertWindowOptionsMessage* FOptionsMessage;
	TdxAlertWindowOptionsNavigationPanel* FOptionsNavigationPanel;
	TdxAlertWindowOptionsSize* FOptionsSize;
	TdxAlertWindowPosition FWindowPosition;
	int FWindowMaxCount;
	TdxAlertWindowManagerCustomDrawBackgroundEvent FOnCustomDrawBackground;
	TdxAlertWindowManagerCustomDrawMessageImageEvent FOnCustomDrawMessageImage;
	TdxAlertWindowManagerCustomDrawMessageTextEvent FOnCustomDrawMessageText;
	TdxAlertWindowManagerCustomDrawMessageCaptionTextEvent FOnCustomDrawMessageCaptionText;
	TdxAlertWindowManagerCustomDrawButtonEvent FOnCustomDrawButton;
	TdxAlertWindowManagerCustomDrawNavigationPanelTextEvent FOnCustomDrawNavigationPanelText;
	TdxAlertWindowManagerDragBeginEvent FOnDragBegin;
	TdxAlertWindowManagerNotifyEvent FOnDragEnd;
	TdxAlertWindowManagerNotifyEvent FOnDragMove;
	TdxAlertWindowManagerMouseEvent FOnMouseDown;
	TdxAlertWindowManagerNotifyEvent FOnMouseEnter;
	TdxAlertWindowManagerNotifyEvent FOnMouseLeave;
	TdxAlertWindowManagerMouseMoveEvent FOnMouseMove;
	TdxAlertWindowManagerMouseEvent FOnMouseUp;
	TdxAlertWindowManagerNotifyEvent FOnBeforeShow;
	TdxAlertWindowManagerButtonClickEvent FOnButtonClick;
	TdxAlertWindowManagerCaptionButtonClickEvent FOnCaptionButtonClick;
	TdxAlertWindowManagerNotifyEvent FOnClick;
	TdxAlertWindowManagerNotifyEvent FOnClose;
	TdxAlertWindowManagerNotifyEvent FOnHide;
	TdxAlertWindowManagerNotifyEvent FOnInitialize;
	TdxAlertWindowManagerMeasureEvent FOnMeasureMessageText;
	TdxAlertWindowManagerNotifyEvent FOnShow;
	void __fastcall AlertWindowCustomDrawBackgroundHandler(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowViewInfo* AViewInfo, bool &ADone);
	void __fastcall AlertWindowCustomDrawButtonHandler(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCustomButtonViewInfo* AViewInfo, bool &ADone);
	void __fastcall AlertWindowCustomDrawMessageCaptionTextHandler(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCaptionTextViewInfo* AViewInfo, bool &ADone);
	void __fastcall AlertWindowCustomDrawMessageImageHandler(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowImageViewInfo* AViewInfo, bool &ADone);
	void __fastcall AlertWindowCustomDrawMessageTextHandler(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowMessageTextViewInfo* AViewInfo, bool &ADone);
	void __fastcall AlertWindowCustomDrawNavigationPanelTextHandler(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowNavigationPanelTextViewInfo* AViewInfo, bool &ADone);
	void __fastcall AlertWindowDragBeginHandler(TdxAlertWindow* AAlertWindow, bool &AAllow);
	void __fastcall AlertWindowDragEndHandler(TdxAlertWindow* AAlertWindow);
	void __fastcall AlertWindowDragMoveHandler(TdxAlertWindow* AAlertWindow);
	void __fastcall AlertWindowButtonClickHandler(TdxAlertWindow* AAlertWindow, int AButtonIndex);
	void __fastcall AlertWindowCaptionButtonClickHandler(TdxAlertWindow* AAlertWindow, TdxAlertWindowCaptionButton AButton, bool &AHandled);
	void __fastcall AlertWindowClickHandler(TdxAlertWindow* AAlertWindow);
	void __fastcall AlertWindowEnterHandler(TdxAlertWindow* AAlertWindow);
	void __fastcall AlertWindowHideHandler(TdxAlertWindow* AAlertWindow);
	void __fastcall AlertWindowLeaveHandler(TdxAlertWindow* AAlertWindow);
	void __fastcall AlertWindowMeasureMessageTextHandler(TdxAlertWindow* AAlertWindow, int &AWidth, int &AHeight);
	void __fastcall AlertWindowMouseDownHandler(TdxAlertWindow* AAlertWindow, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	void __fastcall AlertWindowMouseMoveHandler(TdxAlertWindow* AAlertWindow, System::Classes::TShiftState AShift, int X, int Y);
	void __fastcall AlertWindowMouseUpHandler(TdxAlertWindow* AAlertWindow, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	void __fastcall AlertWindowShowHandler(TdxAlertWindow* AAlertWindow);
	int __fastcall GetCount(void);
	TdxAlertWindow* __fastcall GetItem(int AIndex);
	TdxAlertWindowOptionsAnimate* __fastcall GetOptionsAnimate(void);
	TdxAlertWindowOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TdxAlertWindowOptionsButtons* __fastcall GetOptionsButtons(void);
	TdxAlertWindowOptionsCaptionButtons* __fastcall GetOptionsCaptionButtons(void);
	TdxAlertWindowOptionsMessage* __fastcall GetOptionsMessage(void);
	TdxAlertWindowOptionsNavigationPanel* __fastcall GetOptionsNavigationPanel(void);
	TdxAlertWindowOptionsSize* __fastcall GetOptionsSize(void);
	TdxAlertWindow* __fastcall InternalAdd(void);
	bool __fastcall InternalRemove(System::Classes::TComponent* AComponent);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetOptionsAnimate(TdxAlertWindowOptionsAnimate* AValue);
	void __fastcall SetOptionsBehavior(TdxAlertWindowOptionsBehavior* AValue);
	void __fastcall SetOptionsButtons(TdxAlertWindowOptionsButtons* AValue);
	void __fastcall SetOptionsCaptionButtons(TdxAlertWindowOptionsCaptionButtons* AValue);
	void __fastcall SetOptionsMessage(TdxAlertWindowOptionsMessage* AValue);
	void __fastcall SetOptionsNavigationPanel(TdxAlertWindowOptionsNavigationPanel* AValue);
	void __fastcall SetOptionsSize(TdxAlertWindowOptionsSize* AValue);
	void __fastcall SetWindowPosition(TdxAlertWindowPosition AValue);
	void __fastcall SetWindowMaxCount(int AValue);
	
protected:
	virtual TdxAlertWindowInitialLayout* __fastcall CreateInitialLayoutCalculator(void);
	virtual void __fastcall DoBeforeShow(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoButtonClick(TdxAlertWindow* AAlertWindow, int AButtonIndex);
	virtual bool __fastcall DoCaptionButtonClick(TdxAlertWindow* AAlertWindow, TdxAlertWindowCaptionButton AButton);
	virtual void __fastcall DoClick(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoClose(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoInitialize(TdxAlertWindow* AAlertWindow);
	virtual bool __fastcall DoCustomDrawBackground(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawMessageImage(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowImageViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawMessageText(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowMessageTextViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawMessageCaptionText(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCaptionTextViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawButton(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowCustomButtonViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawNavigationPanelText(TdxAlertWindow* AAlertWindow, Cxgraphics::TcxCanvas* ACanvas, TdxAlertWindowNavigationPanelTextViewInfo* AViewInfo);
	virtual bool __fastcall DoDragBegin(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoDragEnd(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoDragMove(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoMouseDown(TdxAlertWindow* AAlertWindow, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall DoMouseEnter(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoMouseLeave(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoMouseMove(TdxAlertWindow* AAlertWindow, System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall DoMouseUp(TdxAlertWindow* AAlertWindow, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall DoHide(TdxAlertWindow* AAlertWindow);
	virtual void __fastcall DoMeasureMessageText(TdxAlertWindow* AAlertWindow, int &AWidth, int &AHeight);
	virtual void __fastcall DoShow(TdxAlertWindow* AAlertWindow);
	virtual TdxAlertWindowClass __fastcall GetAlertWindowClass(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	
public:
	__fastcall virtual TdxAlertWindowManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxAlertWindowManager(void);
	void __fastcall Close(TdxAlertWindow* AAlertWindow);
	int __fastcall IndexOf(TdxAlertWindow* AAlertWindow);
	TdxAlertWindow* __fastcall Show(const System::UnicodeString ACaption, const System::UnicodeString AText, System::Uitypes::TImageIndex AImageIndex = (System::Uitypes::TImageIndex)(0xffffffff));
	__property int Count = {read=GetCount, nodefault};
	__property TdxAlertWindow* HotWindow = {read=FHotWindow};
	__property TdxAlertWindow* Items[int Index] = {read=GetItem/*, default*/};
	
__published:
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property TdxAlertWindowOptionsAnimate* OptionsAnimate = {read=GetOptionsAnimate, write=SetOptionsAnimate};
	__property TdxAlertWindowOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TdxAlertWindowOptionsButtons* OptionsButtons = {read=GetOptionsButtons, write=SetOptionsButtons};
	__property TdxAlertWindowOptionsCaptionButtons* OptionsCaptionButtons = {read=GetOptionsCaptionButtons, write=SetOptionsCaptionButtons};
	__property TdxAlertWindowOptionsMessage* OptionsMessage = {read=GetOptionsMessage, write=SetOptionsMessage};
	__property TdxAlertWindowOptionsNavigationPanel* OptionsNavigationPanel = {read=GetOptionsNavigationPanel, write=SetOptionsNavigationPanel};
	__property TdxAlertWindowOptionsSize* OptionsSize = {read=GetOptionsSize, write=SetOptionsSize};
	__property TdxAlertWindowPosition WindowPosition = {read=FWindowPosition, write=SetWindowPosition, default=0};
	__property int WindowMaxCount = {read=FWindowMaxCount, write=SetWindowMaxCount, default=0};
	__property TdxAlertWindowManagerCustomDrawBackgroundEvent OnCustomDrawBackground = {read=FOnCustomDrawBackground, write=FOnCustomDrawBackground};
	__property TdxAlertWindowManagerCustomDrawMessageImageEvent OnCustomDrawMessageImage = {read=FOnCustomDrawMessageImage, write=FOnCustomDrawMessageImage};
	__property TdxAlertWindowManagerCustomDrawMessageTextEvent OnCustomDrawMessageText = {read=FOnCustomDrawMessageText, write=FOnCustomDrawMessageText};
	__property TdxAlertWindowManagerCustomDrawMessageCaptionTextEvent OnCustomDrawMessageCaptionText = {read=FOnCustomDrawMessageCaptionText, write=FOnCustomDrawMessageCaptionText};
	__property TdxAlertWindowManagerCustomDrawButtonEvent OnCustomDrawButton = {read=FOnCustomDrawButton, write=FOnCustomDrawButton};
	__property TdxAlertWindowManagerCustomDrawNavigationPanelTextEvent OnCustomDrawNavigationPanelText = {read=FOnCustomDrawNavigationPanelText, write=FOnCustomDrawNavigationPanelText};
	__property TdxAlertWindowManagerDragBeginEvent OnDragBegin = {read=FOnDragBegin, write=FOnDragBegin};
	__property TdxAlertWindowManagerNotifyEvent OnDragEnd = {read=FOnDragEnd, write=FOnDragEnd};
	__property TdxAlertWindowManagerNotifyEvent OnDragMove = {read=FOnDragMove, write=FOnDragMove};
	__property TdxAlertWindowManagerNotifyEvent OnBeforeShow = {read=FOnBeforeShow, write=FOnBeforeShow};
	__property TdxAlertWindowManagerButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property TdxAlertWindowManagerCaptionButtonClickEvent OnCaptionButtonClick = {read=FOnCaptionButtonClick, write=FOnCaptionButtonClick};
	__property TdxAlertWindowManagerNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TdxAlertWindowManagerNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property TdxAlertWindowManagerNotifyEvent OnHide = {read=FOnHide, write=FOnHide};
	__property TdxAlertWindowManagerNotifyEvent OnInitialize = {read=FOnInitialize, write=FOnInitialize};
	__property TdxAlertWindowManagerMeasureEvent OnMeasureMessageText = {read=FOnMeasureMessageText, write=FOnMeasureMessageText};
	__property TdxAlertWindowManagerMouseEvent OnMouseDown = {read=FOnMouseDown, write=FOnMouseDown};
	__property TdxAlertWindowManagerNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property TdxAlertWindowManagerNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	__property TdxAlertWindowManagerMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=FOnMouseMove};
	__property TdxAlertWindowManagerMouseEvent OnMouseUp = {read=FOnMouseUp, write=FOnMouseUp};
	__property TdxAlertWindowManagerNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
private:
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
	#endif
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
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxAlertWindowIndentBetweenRegions = System::Int8(0x5);
static const System::Byte dxAlertWindowDefaultAlphaBlendValue = System::Byte(0xbe);
static const TdxAlertWindowAnimation dxAlertWindowDefaultHidingAnimation = (TdxAlertWindowAnimation)(2);
static const TdxAlertWindowMovingDirection dxAlertWindowDefaultHidingAnimationDirection = (TdxAlertWindowMovingDirection)(0);
static const System::Word dxAlertWindowDefaultHidingAnimationTime = System::Word(0x3e8);
static const bool dxAlertWindowDefaultHotTrack = true;
static const System::Byte dxAlertWindowDefaultHotTrackAlphaBlendValue = System::Byte(0xfa);
static const System::Int8 dxAlertWindowDefaultHotTrackFadeInTime = System::Int8(0x64);
static const System::Word dxAlertWindowDefaultHotTrackFadeOutTime = System::Word(0x3e8);
static const TdxAlertWindowAnimation dxAlertWindowDefaultShowingAnimation = (TdxAlertWindowAnimation)(2);
static const TdxAlertWindowMovingDirection dxAlertWindowDefaultShowingAnimationDirection = (TdxAlertWindowMovingDirection)(0);
static const System::Int8 dxAlertWindowDefaultShowingAnimationTime = System::Int8(0x64);
static const bool dxAlertWindowDefaultCloseOnRightClick = true;
static const System::Word dxAlertWindowDefaultDisplayTime = System::Word(0x1b58);
static const bool dxAlertWindowDefaultScreenSnap = true;
static const System::Int8 dxAlertWindowDefaultScreenSnapBuffer = System::Int8(0x14);
#define dxAlertWindowDefaultCaptionButtons (System::Set<TdxAlertWindowCaptionButton, TdxAlertWindowCaptionButton::awcbDropdown, TdxAlertWindowCaptionButton::awcbClose> () << TdxAlertWindowCaptionButton::awcbDropdown << TdxAlertWindowCaptionButton::awcbPin << TdxAlertWindowCaptionButton::awcbClose )
static const System::Int8 dxAlertWindowDefaultButtonHeight = System::Int8(0x18);
static const System::Int8 dxAlertWindowDefaultButtonWidth = System::Int8(0x18);
static const TdxAlertWindowNavigationPanelVisibility dxAlertWindowDefaultNavigationPanelVisibility = (TdxAlertWindowNavigationPanelVisibility)(0);
static const System::Int8 dxAlertWindowDefaultNavigationPanelWidth = System::Int8(0x0);
static const bool dxAlertWindowDefaultAutoHeight = false;
static const bool dxAlertWindowDefaultAutoWidth = false;
static const System::Int8 dxAlertWindowDefaultMaxHeight = System::Int8(0x0);
static const System::Int8 dxAlertWindowDefaultMinHeight = System::Int8(0x64);
static const System::Int8 dxAlertWindowDefaultMaxWidth = System::Int8(0x0);
static const System::Byte dxAlertWindowDefaultMinWidth = System::Byte(0xc8);
static const System::Classes::TAlignment dxAlertWindowDefaultTextAlignHorz = (System::Classes::TAlignment)(0);
static const Cxclasses::TcxAlignmentVert dxAlertWindowDefaultTextAlignVert = (Cxclasses::TcxAlignmentVert)(0);
static const System::Int8 dxAlertWindowDefaultCaptionFontSize = System::Int8(0xa);
#define dxAlertWindowDefaultCaptionFontStyle (System::Set<System::Uitypes::TFontStyle, System::Uitypes::TFontStyle::fsBold, System::Uitypes::TFontStyle::fsStrikeOut> () << System::Uitypes::TFontStyle::fsBold )
#define sdxAlertWindowMessageCountMacro L"[MessageCount]"
#define sdxAlertWindowMessageIndexMacro L"[MessageIndex]"
}	/* namespace Dxalertwindow */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXALERTWINDOW)
using namespace Dxalertwindow;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxalertwindowHPP
