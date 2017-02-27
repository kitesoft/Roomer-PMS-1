// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxNavigator.pas' rev: 24.00 (Win64)

#ifndef CxnavigatorHPP
#define CxnavigatorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxnavigator
{
//-- type declarations -------------------------------------------------------
enum TcxNavigatorChangeType : unsigned char { nctProperties, nctSize, nctLayout };

__interface IcxNavigatorOwner;
typedef System::DelphiInterface<IcxNavigatorOwner> _di_IcxNavigatorOwner;
class DELPHICLASS TcxCustomNavigatorButtons;
__interface  INTERFACE_UUID("{504B7F43-8847-46C5-B84A-C24F8E5E61A6}") IcxNavigatorOwner  : public System::IInterface 
{
	
public:
	virtual void __fastcall NavigatorChanged(TcxNavigatorChangeType AChangeType) = 0 ;
	virtual System::Types::TRect __fastcall GetNavigatorBounds(void) = 0 ;
	virtual TcxCustomNavigatorButtons* __fastcall GetNavigatorButtons(void) = 0 ;
	virtual Vcl::Graphics::TCanvas* __fastcall GetNavigatorCanvas(void) = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetNavigatorControl(void) = 0 ;
	virtual bool __fastcall GetNavigatorFocused(void) = 0 ;
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetNavigatorLookAndFeel(void) = 0 ;
	virtual System::Classes::TComponent* __fastcall GetNavigatorOwner(void) = 0 ;
	virtual bool __fastcall GetNavigatorShowHint(void) = 0 ;
	virtual bool __fastcall GetNavigatorTabStop(void) = 0 ;
	virtual void __fastcall NavigatorStateChanged(void) = 0 ;
	virtual void __fastcall RefreshNavigator(void) = 0 ;
};

__interface IcxNavigatorOwner2;
typedef System::DelphiInterface<IcxNavigatorOwner2> _di_IcxNavigatorOwner2;
class DELPHICLASS TcxCustomNavigatorInfoPanel;
__interface  INTERFACE_UUID("{5AC3BE65-B332-40D4-9635-869F52634B17}") IcxNavigatorOwner2  : public IcxNavigatorOwner 
{
	
public:
	virtual TcxCustomNavigatorInfoPanel* __fastcall GetNavigatorInfoPanel(void) = 0 ;
};

class DELPHICLASS TcxNavigatorControlNotifier;
class PASCALIMPLEMENTATION TcxNavigatorControlNotifier : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FList;
	
public:
	__fastcall TcxNavigatorControlNotifier(void);
	__fastcall virtual ~TcxNavigatorControlNotifier(void);
	void __fastcall AddNavigator(_di_IcxNavigatorOwner ANavigator);
	void __fastcall RemoveNavigator(_di_IcxNavigatorOwner ANavigator);
	void __fastcall RefreshNavigatorButtons(void);
};


__interface IcxNavigator;
typedef System::DelphiInterface<IcxNavigator> _di_IcxNavigator;
__interface  INTERFACE_UUID("{A15F80CA-DE56-47CB-B0EB-035D0BF90E9D}") IcxNavigator  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanAppend(void) = 0 ;
	virtual bool __fastcall CanDelete(void) = 0 ;
	virtual bool __fastcall CanEdit(void) = 0 ;
	virtual bool __fastcall CanInsert(void) = 0 ;
	virtual bool __fastcall IsActive(void) = 0 ;
	virtual bool __fastcall IsBof(void) = 0 ;
	virtual bool __fastcall IsBookmarkAvailable(void) = 0 ;
	virtual bool __fastcall IsEditing(void) = 0 ;
	virtual bool __fastcall IsEof(void) = 0 ;
	virtual void __fastcall ClearBookmark(void) = 0 ;
	virtual void __fastcall DoAction(int AButtonIndex) = 0 ;
	virtual TcxNavigatorControlNotifier* __fastcall GetNotifier(void) = 0 ;
	virtual bool __fastcall IsActionSupported(int AButtonIndex) = 0 ;
};

__interface IcxNavigatorRecordPosition;
typedef System::DelphiInterface<IcxNavigatorRecordPosition> _di_IcxNavigatorRecordPosition;
__interface  INTERFACE_UUID("{715C9E38-5BA0-4ED8-B35C-BB40EA739362}") IcxNavigatorRecordPosition  : public System::IInterface 
{
	
public:
	virtual int __fastcall GetRecordCount(void) = 0 ;
	virtual int __fastcall GetRecordIndex(void) = 0 ;
};

class DELPHICLASS TcxNavigatorButton;
class PASCALIMPLEMENTATION TcxNavigatorButton : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomNavigatorButtons* FButtons;
	int FDefaultIndex;
	bool FDefaultVisible;
	bool FEnabled;
	System::UnicodeString FHint;
	System::Uitypes::TImageIndex FImageIndex;
	bool FIsVisibleAssigned;
	bool FVisible;
	System::Classes::TNotifyEvent FOnClick;
	int __fastcall GetInternalImageIndex(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetInternalImages(void);
	void __fastcall InternalSetVisible(bool Value, bool AIsInternalSetting = true);
	bool __fastcall IsVisibleStored(void);
	void __fastcall SetEnabled(const bool Value);
	void __fastcall SetHint(const System::UnicodeString Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetOnClick(const System::Classes::TNotifyEvent Value);
	void __fastcall SetVisible(const bool Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	bool __fastcall GetInternalEnabled(void);
	System::UnicodeString __fastcall GetInternalHint(void);
	bool __fastcall HasImage(void);
	bool __fastcall IsCustomButton(void);
	bool __fastcall IsUserImageListUsed(void);
	DYNAMIC void __fastcall DoClick(void);
	void __fastcall RestoreDefaultVisible(bool ACanBeVisible);
	_di_IcxNavigatorOwner __fastcall GetNavigator(void);
	__property int DefaultIndex = {read=FDefaultIndex, write=FDefaultIndex, nodefault};
	__property int InternalImageIndex = {read=GetInternalImageIndex, nodefault};
	__property Vcl::Imglist::TCustomImageList* InternalImages = {read=GetInternalImages};
	
public:
	__fastcall TcxNavigatorButton(TcxCustomNavigatorButtons* AButtons, bool ADefaultVisible);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Click(void);
	System::Types::TSize __fastcall GetImageSize(void);
	__property TcxCustomNavigatorButtons* Buttons = {read=FButtons};
	__property _di_IcxNavigatorOwner Navigator = {read=GetNavigator};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=SetOnClick};
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property System::UnicodeString Hint = {read=FHint, write=SetHint};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxNavigatorButton(void) { }
	
};


class DELPHICLASS TcxNavigatorChildComponent;
class PASCALIMPLEMENTATION TcxNavigatorChildComponent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	_di_IcxNavigatorOwner FNavigator;
	
protected:
	void __fastcall Changed(TcxNavigatorChangeType AChangeType, bool ANeedRefresh = false);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	bool __fastcall IsNavigatorEnabled(void);
	
public:
	__fastcall virtual TcxNavigatorChildComponent(_di_IcxNavigatorOwner ANavigator);
	__property _di_IcxNavigatorOwner Navigator = {read=FNavigator};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxNavigatorChildComponent(void) { }
	
};


class DELPHICLASS TcxNavigatorCustomButton;
class PASCALIMPLEMENTATION TcxNavigatorCustomButton : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TcxNavigatorButton* FButton;
	bool __fastcall GetEnabled(void);
	System::UnicodeString __fastcall GetHint(void);
	System::Uitypes::TImageIndex __fastcall GetImageIndex(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetButton(TcxNavigatorButton* const Value);
	void __fastcall SetEnabled(const bool Value);
	void __fastcall SetHint(const System::UnicodeString Value);
	void __fastcall SetImageIndex(const System::Uitypes::TImageIndex Value);
	void __fastcall SetVisible(const bool Value);
	
protected:
	__property TcxNavigatorButton* Button = {read=FButton, write=SetButton};
	
public:
	__fastcall virtual TcxNavigatorCustomButton(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxNavigatorCustomButton(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, default=1};
	__property System::UnicodeString Hint = {read=GetHint, write=SetHint};
	__property System::Uitypes::TImageIndex ImageIndex = {read=GetImageIndex, write=SetImageIndex, default=-1};
	__property bool Visible = {read=GetVisible, write=SetVisible, default=1};
};


class DELPHICLASS TcxNavigatorCustomButtons;
class PASCALIMPLEMENTATION TcxNavigatorCustomButtons : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TcxNavigatorCustomButton* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxNavigatorCustomButton* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxNavigatorCustomButton* Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	HIDESBASE TcxNavigatorCustomButton* __fastcall Add(void);
	__property TcxNavigatorCustomButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxNavigatorCustomButtons(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxNavigatorCustomButtons(void) { }
	
};


typedef void __fastcall (__closure *TcxNavigatorButtonClickEvent)(System::TObject* Sender, int AButtonIndex, bool &ADone);

class PASCALIMPLEMENTATION TcxCustomNavigatorButtons : public TcxNavigatorChildComponent
{
	typedef TcxNavigatorChildComponent inherited;
	
public:
	TcxNavigatorButton* operator[](int Index) { return Buttons[Index]; }
	
private:
	System::Classes::TList* FButtons;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	bool FConfirmDelete;
	TcxNavigatorCustomButtons* FCustomButtons;
	TcxNavigatorButtonClickEvent FOnButtonClick;
	TcxNavigatorButton* __fastcall GetButton(int Index);
	int __fastcall GetButtonCount(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetDefaultImages(void);
	void __fastcall SetButton(int Index, TcxNavigatorButton* const Value);
	void __fastcall SetConfirmDelete(const bool Value);
	void __fastcall SetCustomButtons(TcxNavigatorCustomButtons* const Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetOnButtonClick(const TcxNavigatorButtonClickEvent Value);
	void __fastcall ImageListChange(System::TObject* Sender);
	
protected:
	virtual void __fastcall CreateButtons(void);
	virtual void __fastcall DestroyButtons(void);
	void __fastcall CustomButtonsChanged(void);
	virtual void __fastcall DoButtonClick(int ADefaultIndex);
	virtual bool __fastcall GetButtonEnabled(int ADefaultIndex);
	virtual System::UnicodeString __fastcall GetButtonHint(int ADefaultIndex);
	virtual int __fastcall GetButtonImageOffset(void);
	virtual bool __fastcall IsButtonVisibleByDefault(int AIndex);
	__property bool ConfirmDelete = {read=FConfirmDelete, write=SetConfirmDelete, default=1};
	__property TcxNavigatorButton* First = {read=GetButton, write=SetButton, index=0};
	__property TcxNavigatorButton* PriorPage = {read=GetButton, write=SetButton, index=1};
	__property TcxNavigatorButton* Prior = {read=GetButton, write=SetButton, index=2};
	__property TcxNavigatorButton* Next = {read=GetButton, write=SetButton, index=3};
	__property TcxNavigatorButton* NextPage = {read=GetButton, write=SetButton, index=4};
	__property TcxNavigatorButton* Last = {read=GetButton, write=SetButton, index=5};
	__property TcxNavigatorButton* Insert = {read=GetButton, write=SetButton, index=6};
	__property TcxNavigatorButton* Append = {read=GetButton, write=SetButton, index=7};
	__property TcxNavigatorButton* Delete = {read=GetButton, write=SetButton, index=8};
	__property TcxNavigatorButton* Edit = {read=GetButton, write=SetButton, index=9};
	__property TcxNavigatorButton* Post = {read=GetButton, write=SetButton, index=10};
	__property TcxNavigatorButton* Cancel = {read=GetButton, write=SetButton, index=11};
	__property TcxNavigatorCustomButtons* CustomButtons = {read=FCustomButtons, write=SetCustomButtons};
	__property TcxNavigatorButton* Refresh = {read=GetButton, write=SetButton, index=12};
	__property TcxNavigatorButton* SaveBookmark = {read=GetButton, write=SetButton, index=13};
	__property TcxNavigatorButton* GotoBookmark = {read=GetButton, write=SetButton, index=14};
	__property TcxNavigatorButton* Filter = {read=GetButton, write=SetButton, index=15};
	
public:
	__fastcall virtual TcxCustomNavigatorButtons(_di_IcxNavigatorOwner ANavigator);
	__fastcall virtual ~TcxCustomNavigatorButtons(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ClickButton(int Index);
	virtual void __fastcall ReleaseBookmark(void);
	__property int ButtonCount = {read=GetButtonCount, nodefault};
	__property TcxNavigatorButton* Buttons[int Index] = {read=GetButton/*, default*/};
	__property Vcl::Imglist::TCustomImageList* DefaultImages = {read=GetDefaultImages};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	
__published:
	__property TcxNavigatorButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=SetOnButtonClick};
};


typedef _di_IcxNavigatorRecordPosition __fastcall (__closure *TcxInfoPanelGetIRecordPosition)(void);

typedef void __fastcall (__closure *TcxNavigatorInfoPanelClickEvent)(TcxCustomNavigatorInfoPanel* Sender, System::Uitypes::TMouseButton Button);

class PASCALIMPLEMENTATION TcxCustomNavigatorInfoPanel : public TcxNavigatorChildComponent
{
	typedef TcxNavigatorChildComponent inherited;
	
private:
	System::UnicodeString FDisplayMask;
	System::UnicodeString FFormatString;
	bool FIsNeedRecordCount;
	bool FIsNeedRecordIndex;
	bool FVisible;
	TcxNavigatorInfoPanelClickEvent FOnClick;
	TcxInfoPanelGetIRecordPosition FOnGetIRecordPosition;
	int FWidth;
	_di_IcxNavigatorRecordPosition __fastcall GetIRecordPosition(void);
	bool __fastcall IsDisplayMaskStored(void);
	void __fastcall SetDisplayMask(const System::UnicodeString Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetWidth(const int Value);
	
protected:
	void __fastcall BuildFormatString(void);
	virtual void __fastcall DoClick(System::Uitypes::TMouseButton Button);
	virtual Cxgraphics::TcxViewParams __fastcall GetViewParams(void) = 0 ;
	__property System::UnicodeString DisplayMask = {read=FDisplayMask, write=SetDisplayMask, stored=IsDisplayMaskStored};
	__property bool IsNeedRecordIndex = {read=FIsNeedRecordIndex, nodefault};
	__property bool IsNeedRecordCount = {read=FIsNeedRecordCount, nodefault};
	__property _di_IcxNavigatorRecordPosition IRecordPosition = {read=GetIRecordPosition};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
	
public:
	__fastcall virtual TcxCustomNavigatorInfoPanel(_di_IcxNavigatorOwner ANavigator);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetFormattedText(void);
	__property TcxInfoPanelGetIRecordPosition OnGetIRecordPosition = {read=FOnGetIRecordPosition, write=FOnGetIRecordPosition};
	
__published:
	__property TcxNavigatorInfoPanelClickEvent OnClick = {read=FOnClick, write=FOnClick};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomNavigatorInfoPanel(void) { }
	
};


class DELPHICLASS TcxNavigatorButtonViewInfo;
class DELPHICLASS TcxNavigatorViewInfo;
class PASCALIMPLEMENTATION TcxNavigatorButtonViewInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxNavigatorViewInfo* FOwner;
	bool __fastcall GetNeedDrawFocusRect(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	System::Types::TSize FSize;
	Cxlookandfeelpainters::TcxButtonState FState;
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall CalculateState(void);
	virtual void __fastcall CorrectButtonBounds(System::Types::TRect &R);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	bool __fastcall CanFade(void);
	void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	bool __fastcall HasHintPoint(const System::Types::TPoint P);
	bool __fastcall IsHintAtMousePos(void);
	bool __fastcall UseHintHidePause(void);
	__property bool NeedDrawFocusRect = {read=GetNeedDrawFocusRect, nodefault};
	
public:
	TcxNavigatorButton* Button;
	System::Types::TRect Bounds;
	bool Enabled;
	System::UnicodeString Hint;
	__fastcall virtual TcxNavigatorButtonViewInfo(TcxNavigatorViewInfo* AOwner);
	__fastcall virtual ~TcxNavigatorButtonViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Invalidate(void);
	void __fastcall UpdateState(void);
	__property TcxNavigatorViewInfo* Owner = {read=FOwner};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property System::Types::TSize Size = {read=FSize};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, nodefault};
private:
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator Dxfading::_di_IdxFadingObject()
	{
		Dxfading::_di_IdxFadingObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObject*(void) { return (Dxfading::IdxFadingObject*)&__IdxFadingObject; }
	#endif
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


class DELPHICLASS TcxNavigatorButtonsViewInfo;
class PASCALIMPLEMENTATION TcxNavigatorButtonsViewInfo : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	TcxNavigatorButtonViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	System::Types::TSize FSize;
	HIDESBASE TcxNavigatorButtonViewInfo* __fastcall GetItem(int Index);
	
public:
	void __fastcall CalculateSize(void);
	__property TcxNavigatorButtonViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property System::Types::TSize Size = {read=FSize};
public:
	/* TdxFastObjectList.Create */ inline __fastcall TcxNavigatorButtonsViewInfo(bool AOwnsObjects, int ACapacity) : Dxcoreclasses::TdxFastObjectList(AOwnsObjects, ACapacity) { }
	
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TcxNavigatorButtonsViewInfo(void) { }
	
};


class DELPHICLASS TcxCustomNavigatorInfoPanelViewInfo;
class PASCALIMPLEMENTATION TcxCustomNavigatorInfoPanelViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FText;
	System::Types::TRect FBounds;
	TcxNavigatorViewInfo* FNavigatorViewInfo;
	_di_IcxNavigatorOwner2 __fastcall GetNavigatorOwner(void);
	
protected:
	__property _di_IcxNavigatorOwner2 NavigatorOwner = {read=GetNavigatorOwner};
	__property TcxNavigatorViewInfo* NavigatorViewInfo = {read=FNavigatorViewInfo};
	
public:
	__fastcall TcxCustomNavigatorInfoPanelViewInfo(TcxNavigatorViewInfo* ANavigatorViewInfo);
	void __fastcall Calculate(const System::Types::TRect &ABounds, const System::UnicodeString AText);
	void __fastcall Paint(void);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::UnicodeString Text = {read=FText};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomNavigatorInfoPanelViewInfo(void) { }
	
};


class DELPHICLASS TcxNavigatorHintHelper;
class PASCALIMPLEMENTATION TcxNavigatorHintHelper : public Dxcustomhint::TcxControlHintHelper
{
	typedef Dxcustomhint::TcxControlHintHelper inherited;
	
private:
	TcxNavigatorViewInfo* FNavigatorViewInfo;
	
protected:
	virtual void __fastcall CorrectHintWindowRect(System::Types::TRect &ARect);
	virtual Cxcontrols::TcxControl* __fastcall GetOwnerControl(void);
	
public:
	__fastcall TcxNavigatorHintHelper(TcxNavigatorViewInfo* ANavigatorViewInfo);
	virtual void __fastcall MouseDown(void);
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TcxNavigatorHintHelper(void) { }
	
};


class PASCALIMPLEMENTATION TcxNavigatorViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxTimer* FButtonPressTimer;
	TcxNavigatorButtonsViewInfo* FButtons;
	Cxgraphics::TcxCanvas* FCanvas;
	TcxNavigatorButton* FFocusedButton;
	TcxNavigatorHintHelper* FHintHelper;
	TcxNavigatorButtonViewInfo* FHotTrackButtonViewInfo;
	bool FInfoPanelPressed;
	TcxCustomNavigatorInfoPanelViewInfo* FInfoPanelViewInfo;
	bool FIsDirty;
	bool FIsInplace;
	bool FIsSelected;
	_di_IcxNavigatorOwner FNavigatorOwner;
	_di_IcxNavigatorOwner2 FNavigatorOwner2;
	TcxNavigatorButtonViewInfo* FPressedButtonViewInfo;
	int __fastcall GetButtonCount(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	TcxNavigatorButtonViewInfo* __fastcall GetFocusedButton(void);
	TcxCustomNavigatorInfoPanel* __fastcall GetInfoPanel(void);
	void __fastcall SetFocusedButton(TcxNavigatorButtonViewInfo* Value);
	bool __fastcall StopButtonPressTimerIfLeftMouseReleased(void);
	void __fastcall DoButtonPressTimer(System::TObject* Sender);
	void __fastcall UpdateSelected(void);
	
protected:
	void __fastcall CancelHint(void);
	void __fastcall CheckHint(void);
	void __fastcall CalculateBounds(const System::UnicodeString AInfoPanelText, int AInfoPanelWidth, int AHeight, int AButtonIndent);
	void __fastcall CalculateButtons(void);
	System::Types::TSize __fastcall CalculateMinSize(void);
	void __fastcall CalculateSize(int &AWidth, int &AHeight, const System::UnicodeString AInfoPanelText, /* out */ int &AButtonIndent, /* out */ int &AInfoPanelWidth);
	virtual bool __fastcall CanButtonOverlapBorder(void);
	void __fastcall CheckCalculate(void);
	void __fastcall ClearButtons(void);
	Vcl::Graphics::TFont* __fastcall GetInfoPanelFont(void);
	System::UnicodeString __fastcall GetInfoPanelText(void);
	System::Types::TSize __fastcall GetInfoPanelSize(System::UnicodeString AText);
	System::Types::TSize __fastcall GetMinButtonSize(int AButtonIndex);
	bool __fastcall HasInfoPanel(void);
	void __fastcall InvalidateButton(TcxNavigatorButtonViewInfo* AButton);
	void __fastcall PaintButton(int AButtonIndex);
	void __fastcall PaintButtons(void);
	void __fastcall ValidateButtonsViewInfos(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property TcxNavigatorButtonViewInfo* FocusedButton = {read=GetFocusedButton, write=SetFocusedButton};
	__property TcxNavigatorButtonViewInfo* HotTrackButtonViewInfo = {read=FHotTrackButtonViewInfo, write=FHotTrackButtonViewInfo};
	__property TcxCustomNavigatorInfoPanel* InfoPanel = {read=GetInfoPanel};
	__property TcxCustomNavigatorInfoPanelViewInfo* InfoPanelViewInfo = {read=FInfoPanelViewInfo};
	__property bool IsInplace = {read=FIsInplace, nodefault};
	__property _di_IcxNavigatorOwner NavigatorOwner = {read=FNavigatorOwner};
	__property _di_IcxNavigatorOwner2 NavigatorOwner2 = {read=FNavigatorOwner2};
	__property TcxNavigatorButtonViewInfo* PressedButtonViewInfo = {read=FPressedButtonViewInfo, write=FPressedButtonViewInfo};
	
public:
	__fastcall virtual TcxNavigatorViewInfo(_di_IcxNavigatorOwner ANavigator, bool AIsInplace);
	__fastcall virtual ~TcxNavigatorViewInfo(void);
	virtual void __fastcall Calculate(void);
	void __fastcall CheckSize(int &AWidth, int &AHeight);
	void __fastcall Clear(void);
	void __fastcall DoEnter(void);
	void __fastcall DoExit(void);
	TcxNavigatorButton* __fastcall GetButtonAt(const System::Types::TPoint pt);
	TcxNavigatorButtonViewInfo* __fastcall GetButtonViewInfoAt(const System::Types::TPoint pt);
	TcxNavigatorButtonViewInfo* __fastcall GetButtonViewInfoByButton(TcxNavigatorButton* AButton);
	void __fastcall MakeDirty(void);
	void __fastcall MouseDown(int X, int Y);
	void __fastcall MouseLeave(void);
	void __fastcall MouseMove(int X, int Y);
	void __fastcall MouseUp(System::Uitypes::TMouseButton Button, int X, int Y);
	void __fastcall Paint(void);
	void __fastcall PaintBorder(const System::Types::TRect &ABounds);
	void __fastcall PressArrowKey(bool ALeftKey);
	void __fastcall Update(void);
	void __fastcall UpdateButtonsEnabled(void);
	void __fastcall UpdateInfoPanel(void);
	__property int ButtonCount = {read=GetButtonCount, nodefault};
	__property TcxNavigatorButtonsViewInfo* Buttons = {read=FButtons};
};


typedef System::TMetaClass* TcxNavigatorViewInfoClass;

enum TcxNavigatorBorderStyle : unsigned char { nbsDefault, nbsNone, nbsAlways };

class DELPHICLASS TcxNavigatorControlViewInfo;
class PASCALIMPLEMENTATION TcxNavigatorControlViewInfo : public TcxNavigatorViewInfo
{
	typedef TcxNavigatorViewInfo inherited;
	
protected:
	virtual bool __fastcall CanButtonOverlapBorder(void);
public:
	/* TcxNavigatorViewInfo.Create */ inline __fastcall virtual TcxNavigatorControlViewInfo(_di_IcxNavigatorOwner ANavigator, bool AIsInplace) : TcxNavigatorViewInfo(ANavigator, AIsInplace) { }
	/* TcxNavigatorViewInfo.Destroy */ inline __fastcall virtual ~TcxNavigatorControlViewInfo(void) { }
	
};


class DELPHICLASS TcxControlAccess;
class PASCALIMPLEMENTATION TcxControlAccess : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
public:
	/* TcxControl.Create */ inline __fastcall virtual TcxControlAccess(System::Classes::TComponent* AOwner) : Cxcontrols::TcxControl(AOwner) { }
	/* TcxControl.Destroy */ inline __fastcall virtual ~TcxControlAccess(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxControlAccess(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TcxInplaceNavigatorViewInfo;
class PASCALIMPLEMENTATION TcxInplaceNavigatorViewInfo : public TcxNavigatorViewInfo
{
	typedef TcxNavigatorViewInfo inherited;
	
private:
	System::Types::TSize FNavigatorSize;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	int __fastcall GetHeight(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	virtual int __fastcall GetNavigatorOffset(void);
	System::Types::TRect __fastcall GetNavigatorSiteBounds(void);
	int __fastcall GetWidth(void);
	bool __fastcall IsNavigatorSizeChanged(void);
	virtual void __fastcall UpdateNavigatorSiteBounds(const System::Types::TRect &ABounds);
	
public:
	virtual void __fastcall Calculate(void);
	virtual System::Types::TRect __fastcall GetNavigatorBounds(void);
	__property Cxcontrols::TcxControl* Control = {read=GetControl};
public:
	/* TcxNavigatorViewInfo.Create */ inline __fastcall virtual TcxInplaceNavigatorViewInfo(_di_IcxNavigatorOwner ANavigator, bool AIsInplace) : TcxNavigatorViewInfo(ANavigator, AIsInplace) { }
	/* TcxNavigatorViewInfo.Destroy */ inline __fastcall virtual ~TcxInplaceNavigatorViewInfo(void) { }
	
};


class DELPHICLASS TcxCustomNavigator;
class PASCALIMPLEMENTATION TcxCustomNavigator : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TcxNavigatorBorderStyle FBorderStyle;
	TcxCustomNavigatorButtons* FButtons;
	TcxCustomNavigatorInfoPanel* FInfoPanel;
	System::Classes::TNotifyEvent FSubClassEvents;
	TcxNavigatorViewInfo* FViewInfo;
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	HIDESBASE void __fastcall SetBorderStyle(const TcxNavigatorBorderStyle Value);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	
protected:
	void __fastcall NavigatorMouseLeave(void);
	void __fastcall NavigatorChanged(TcxNavigatorChangeType AChangeType);
	System::Types::TRect __fastcall GetNavigatorBounds(void);
	TcxCustomNavigatorButtons* __fastcall GetNavigatorButtons(void);
	Vcl::Graphics::TCanvas* __fastcall GetNavigatorCanvas(void);
	Vcl::Controls::TWinControl* __fastcall GetNavigatorControl(void);
	bool __fastcall GetNavigatorFocused(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetNavigatorLookAndFeel(void);
	System::Classes::TComponent* __fastcall GetNavigatorOwner(void);
	bool __fastcall GetNavigatorShowHint(void);
	bool __fastcall GetNavigatorTabStop(void);
	TcxCustomNavigatorInfoPanel* __fastcall GetNavigatorInfoPanel(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual TcxCustomNavigatorButtons* __fastcall CreateButtons(void);
	virtual TcxCustomNavigatorInfoPanel* __fastcall CreateInfoPanel(void) = 0 ;
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall EnabledChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual int __fastcall GetBorderSize(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall CheckSize(int &AWidth, int &AHeight);
	virtual TcxNavigatorViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall InitButtons(void);
	void __fastcall NavigatorStateChanged(void);
	void __fastcall RefreshNavigator(void);
	__property TcxCustomNavigatorButtons* CustomButtons = {read=FButtons};
	__property TcxCustomNavigatorInfoPanel* CustomInfoPanel = {read=FInfoPanel};
	__property TcxNavigatorViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxCustomNavigator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomNavigator(void);
	void __fastcall ClickButton(int Index);
	void __fastcall RestoreButtons(void);
	__property TcxNavigatorBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	__property LookAndFeel;
	
__published:
	__property TabStop = {default=0};
	__property System::Classes::TNotifyEvent ButtonsEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent InfoPanelEvents = {read=FSubClassEvents, write=FSubClassEvents};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomNavigator(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	void *__IcxNavigatorOwner2;	/* IcxNavigatorOwner2 */
	
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
	// {5AC3BE65-B332-40D4-9635-869F52634B17}
	operator _di_IcxNavigatorOwner2()
	{
		_di_IcxNavigatorOwner2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxNavigatorOwner2*(void) { return (IcxNavigatorOwner2*)&__IcxNavigatorOwner2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {504B7F43-8847-46C5-B84A-C24F8E5E61A6}
	operator _di_IcxNavigatorOwner()
	{
		_di_IcxNavigatorOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxNavigatorOwner*(void) { return (IcxNavigatorOwner*)&__IcxNavigatorOwner2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IdxSkinSupport; }
	#endif
	
};


typedef _di_IcxNavigator __fastcall (__closure *TcxNavigatorControlButtonsGetControl)(void);

class DELPHICLASS TcxNavigatorControlButtons;
class PASCALIMPLEMENTATION TcxNavigatorControlButtons : public TcxCustomNavigatorButtons
{
	typedef TcxCustomNavigatorButtons inherited;
	
private:
	TcxNavigatorControlButtonsGetControl FOnGetControl;
	_di_IcxNavigator __fastcall GetControl(void);
	
protected:
	virtual void __fastcall DoButtonClick(int ADefaultIndex);
	virtual bool __fastcall GetButtonEnabled(int ADefaultIndex);
	__property _di_IcxNavigator Control = {read=GetControl};
	
public:
	virtual void __fastcall ReleaseBookmark(void);
	__property TcxNavigatorControlButtonsGetControl OnGetControl = {read=FOnGetControl, write=FOnGetControl};
	
__published:
	__property ConfirmDelete = {default=1};
	__property CustomButtons;
	__property Images;
	__property First;
	__property PriorPage;
	__property Prior;
	__property Next;
	__property NextPage;
	__property Last;
	__property Insert;
	__property Append;
	__property Delete;
	__property Edit;
	__property Post;
	__property Cancel;
	__property Refresh;
	__property SaveBookmark;
	__property GotoBookmark;
	__property Filter;
public:
	/* TcxCustomNavigatorButtons.Create */ inline __fastcall virtual TcxNavigatorControlButtons(_di_IcxNavigatorOwner ANavigator) : TcxCustomNavigatorButtons(ANavigator) { }
	/* TcxCustomNavigatorButtons.Destroy */ inline __fastcall virtual ~TcxNavigatorControlButtons(void) { }
	
};


typedef System::TMetaClass* TcxNavigatorControlButtonsClass;

class DELPHICLASS TcxNavigatorControlInfoPanel;
class PASCALIMPLEMENTATION TcxNavigatorControlInfoPanel : public TcxCustomNavigatorInfoPanel
{
	typedef TcxCustomNavigatorInfoPanel inherited;
	
private:
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	TcxCustomNavigator* __fastcall GetControl(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	bool __fastcall GetParentFont(void);
	bool __fastcall IsFontStored(void);
	void __fastcall SetParentFont(const bool Value);
	
protected:
	virtual Cxgraphics::TcxViewParams __fastcall GetViewParams(void);
	virtual void __fastcall ResetFont(void);
	__property TcxCustomNavigator* Control = {read=GetControl};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property DisplayMask = {default=0};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont, stored=IsFontStored};
	__property bool ParentFont = {read=GetParentFont, write=SetParentFont, default=1};
	__property Visible = {default=0};
	__property Width = {default=0};
public:
	/* TcxCustomNavigatorInfoPanel.Create */ inline __fastcall virtual TcxNavigatorControlInfoPanel(_di_IcxNavigatorOwner ANavigator) : TcxCustomNavigatorInfoPanel(ANavigator) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxNavigatorControlInfoPanel(void) { }
	
};


typedef System::TMetaClass* TcxNavigatorControlInfoPanelClass;

class DELPHICLASS TcxCustomNavigatorControl;
class PASCALIMPLEMENTATION TcxCustomNavigatorControl : public TcxCustomNavigator
{
	typedef TcxCustomNavigator inherited;
	
private:
	System::Classes::TComponent* FControl;
	TcxNavigatorControlButtons* __fastcall GetButtons(void);
	_di_IcxNavigator __fastcall GetIcxNavigator(void);
	_di_IcxNavigatorRecordPosition __fastcall GetIRecordPosition(void);
	TcxNavigatorControlInfoPanel* __fastcall GetInfoPanel(void);
	void __fastcall SetButtons(TcxNavigatorControlButtons* Value);
	void __fastcall SetControl(System::Classes::TComponent* Value);
	void __fastcall SetInfoPanel(TcxNavigatorControlInfoPanel* Value);
	
protected:
	virtual TcxCustomNavigatorButtons* __fastcall CreateButtons(void);
	virtual TcxCustomNavigatorInfoPanel* __fastcall CreateInfoPanel(void);
	virtual TcxNavigatorControlButtonsClass __fastcall GetButtonsClass(void);
	virtual TcxNavigatorControlInfoPanelClass __fastcall GetInfoPanelClass(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall InitButtons(void);
	__property TcxNavigatorControlButtons* Buttons = {read=GetButtons, write=SetButtons};
	__property System::Classes::TComponent* Control = {read=FControl, write=SetControl};
	__property TcxNavigatorControlInfoPanel* InfoPanel = {read=GetInfoPanel, write=SetInfoPanel};
	
public:
	__fastcall virtual ~TcxCustomNavigatorControl(void);
public:
	/* TcxCustomNavigator.Create */ inline __fastcall virtual TcxCustomNavigatorControl(System::Classes::TComponent* AOwner) : TcxCustomNavigator(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomNavigatorControl(HWND ParentWindow) : TcxCustomNavigator(ParentWindow) { }
	
};


class DELPHICLASS TcxNavigator;
class PASCALIMPLEMENTATION TcxNavigator : public TcxCustomNavigatorControl
{
	typedef TcxCustomNavigatorControl inherited;
	
__published:
	__property BorderStyle = {default=0};
	__property Control;
	__property Buttons;
	__property InfoPanel;
	__property LookAndFeel;
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Ctl3D;
	__property ParentCtl3D = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomNavigatorControl.Destroy */ inline __fastcall virtual ~TcxNavigator(void) { }
	
public:
	/* TcxCustomNavigator.Create */ inline __fastcall virtual TcxNavigator(System::Classes::TComponent* AOwner) : TcxCustomNavigatorControl(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxNavigator(HWND ParentWindow) : TcxCustomNavigatorControl(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 NavigatorButtonCount = System::Int8(0x10);
static const System::Int8 NBDI_FIRST = System::Int8(0x0);
static const System::Int8 NBDI_PRIORPAGE = System::Int8(0x1);
static const System::Int8 NBDI_PRIOR = System::Int8(0x2);
static const System::Int8 NBDI_NEXT = System::Int8(0x3);
static const System::Int8 NBDI_NEXTPAGE = System::Int8(0x4);
static const System::Int8 NBDI_LAST = System::Int8(0x5);
static const System::Int8 NBDI_INSERT = System::Int8(0x6);
static const System::Int8 NBDI_APPEND = System::Int8(0x7);
static const System::Int8 NBDI_DELETE = System::Int8(0x8);
static const System::Int8 NBDI_EDIT = System::Int8(0x9);
static const System::Int8 NBDI_POST = System::Int8(0xa);
static const System::Int8 NBDI_CANCEL = System::Int8(0xb);
static const System::Int8 NBDI_REFRESH = System::Int8(0xc);
static const System::Int8 NBDI_SAVEBOOKMARK = System::Int8(0xd);
static const System::Int8 NBDI_GOTOBOOKMARK = System::Int8(0xe);
static const System::Int8 NBDI_FILTER = System::Int8(0xf);
extern PACKAGE Cxgraphics::TcxImageList* __fastcall NavigatorImages(void);
extern PACKAGE System::UnicodeString __fastcall cxGetNavigatorFormatString(const System::UnicodeString ADisplayMask, /* out */ bool &AIsNeedRecordIndex, /* out */ bool &AIsNeedRecordCount);
}	/* namespace Cxnavigator */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXNAVIGATOR)
using namespace Cxnavigator;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxnavigatorHPP
