// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxControls.pas' rev: 24.00 (Win64)

#ifndef CxcontrolsHPP
#define CxcontrolsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Themes.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcontrols
{
//-- type declarations -------------------------------------------------------
enum TcxSystemMenuType : unsigned char { smSystem, smChild, smDialog };

typedef HWND TcxHandle;

enum TcxDragDetect : unsigned char { ddNone, ddDrag, ddCancel };

enum TcxNumberType : unsigned char { ntInteger, ntFloat, ntExponent };

typedef System::Uitypes::TScrollStyle TcxScrollStyle;

enum TcxRecordScrollMode : unsigned char { rsmDefault, rsmByRecord, rsmByPixel };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TLBGetItemRect
{
public:
	unsigned Msg;
	int ItemIndex;
	System::Types::TRect *Rect;
	int Result;
};
#pragma pack(pop)


typedef System::TMetaClass* TDragControlObjectClass;

__interface IdxPopupControl;
typedef System::DelphiInterface<IdxPopupControl> _di_IdxPopupControl;
__interface  INTERFACE_UUID("{631D4C30-8543-4A08-A50E-9ABA2FA7EF33}") IdxPopupControl  : public System::IInterface 
{
	
public:
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerControl(void) = 0 ;
};

__interface IdxSpellChecker;
typedef System::DelphiInterface<IdxSpellChecker> _di_IdxSpellChecker;
__interface  INTERFACE_UUID("{4515FCEE-2D09-4709-A170-E29C556355BF}") IdxSpellChecker  : public System::IInterface 
{
	
public:
	virtual void __fastcall CheckFinish(void) = 0 ;
	virtual void __fastcall CheckStart(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall DrawMisspellings(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual bool __fastcall IsSpellCheckerDialogControl(NativeUInt AWnd) = 0 ;
	virtual void __fastcall KeyPress(System::WideChar AKey) = 0 ;
	virtual void __fastcall LayoutChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual bool __fastcall QueryPopup(System::Classes::TComponent* APopup, const System::Types::TPoint P) = 0 ;
	virtual void __fastcall SelectionChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall TextChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall Undo(void) = 0 ;
};

__interface IdxSpellChecker2;
typedef System::DelphiInterface<IdxSpellChecker2> _di_IdxSpellChecker2;
__interface  INTERFACE_UUID("{0480D25C-94DA-449D-BBE6-B771C76D0BB1}") IdxSpellChecker2  : public System::IInterface 
{
	
public:
	virtual void __fastcall KeyDown(System::Word AKey, System::Classes::TShiftState Shift) = 0 ;
	virtual void __fastcall KeyUp(System::Word AKey, System::Classes::TShiftState Shift) = 0 ;
};

__interface IdxSpellCheckerControl;
typedef System::DelphiInterface<IdxSpellCheckerControl> _di_IdxSpellCheckerControl;
__interface  INTERFACE_UUID("{2DEA4CCA-3C6D-4283-9441-AABBD61F74F3}") IdxSpellCheckerControl  : public System::IInterface 
{
	
public:
	virtual bool __fastcall SupportsSpelling(void) = 0 ;
	virtual void __fastcall SetSelText(const System::UnicodeString AText, bool APost = false) = 0 ;
	virtual void __fastcall SetIsBarControl(bool AValue) = 0 ;
	virtual void __fastcall SetValue(const System::Variant &AValue) = 0 ;
};

__interface IdxSystemInfoListener;
typedef System::DelphiInterface<IdxSystemInfoListener> _di_IdxSystemInfoListener;
__interface  INTERFACE_UUID("{F137963E-6165-47F9-A4C7-96BB4EB91AE0}") IdxSystemInfoListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall Changed(unsigned AParameter) = 0 ;
};

struct DECLSPEC_DRECORD TdxSpellCheckerAutoCorrectWordRange
{
public:
	System::WideString Replacement;
	int SelStart;
	int SelLength;
	int NewSelStart;
};


typedef TdxSpellCheckerAutoCorrectWordRange *PdxSpellCheckerAutoCorrectWordRange;

__interface IcxMouseCaptureObject;
typedef System::DelphiInterface<IcxMouseCaptureObject> _di_IcxMouseCaptureObject;
__interface  INTERFACE_UUID("{ACB73657-6066-4564-9A3D-D4D0273AA82F}") IcxMouseCaptureObject  : public System::IInterface 
{
	
public:
	virtual void __fastcall DoCancelMode(void) = 0 ;
};

__interface IcxMouseTrackingCaller;
typedef System::DelphiInterface<IcxMouseTrackingCaller> _di_IcxMouseTrackingCaller;
__interface  INTERFACE_UUID("{84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}") IcxMouseTrackingCaller  : public System::IInterface 
{
	
public:
	virtual void __fastcall MouseLeave(void) = 0 ;
};

__interface IcxMouseTrackingCaller2;
typedef System::DelphiInterface<IcxMouseTrackingCaller2> _di_IcxMouseTrackingCaller2;
__interface  INTERFACE_UUID("{3A5D973B-F016-4F22-80B6-1D35668D7743}") IcxMouseTrackingCaller2  : public IcxMouseTrackingCaller 
{
	
public:
	virtual bool __fastcall PtInCaller(const System::Types::TPoint P) = 0 ;
};

__interface IcxCompoundControl;
typedef System::DelphiInterface<IcxCompoundControl> _di_IcxCompoundControl;
__interface  INTERFACE_UUID("{A4A77F28-1D03-425B-9A83-0B853B5D8DEF}") IcxCompoundControl  : public System::IInterface 
{
	
public:
	virtual Vcl::Controls::TWinControl* __fastcall GetActiveControl(void) = 0 ;
	__property Vcl::Controls::TWinControl* ActiveControl = {read=GetActiveControl};
};

__interface IcxControlComponentState;
typedef System::DelphiInterface<IcxControlComponentState> _di_IcxControlComponentState;
__interface  INTERFACE_UUID("{E29BF582-E8C0-4868-A799-DB4C41AC3BC8}") IcxControlComponentState  : public System::IInterface 
{
	
public:
	virtual bool __fastcall IsDesigning(void) = 0 ;
	virtual bool __fastcall IsDestroying(void) = 0 ;
	virtual bool __fastcall IsLoading(void) = 0 ;
};

__interface IcxPopupMenu;
typedef System::DelphiInterface<IcxPopupMenu> _di_IcxPopupMenu;
__interface  INTERFACE_UUID("{61EEDA7D-88CC-45BF-8A00-5C25174D6501}") IcxPopupMenu  : public System::IInterface 
{
	
public:
	virtual bool __fastcall IsShortCutKey(Winapi::Messages::TWMKey &Message) = 0 ;
	virtual void __fastcall Popup(int X, int Y) = 0 ;
};

__interface IcxPopupMenu2;
typedef System::DelphiInterface<IcxPopupMenu2> _di_IcxPopupMenu2;
__interface  INTERFACE_UUID("{E6DC09CE-3252-457B-B6D2-09D8335C2DED}") IcxPopupMenu2  : public IcxPopupMenu 
{
	
public:
	HIDESBASE virtual void __fastcall Popup(int X, int Y, const System::Types::TRect &AOwnerBounds, Vcl::Menus::TPopupAlignment APopupAlignment) = 0 ;
};

__interface IcxTransparentControl;
typedef System::DelphiInterface<IcxTransparentControl> _di_IcxTransparentControl;
__interface  INTERFACE_UUID("{F4980C69-029E-4B14-B3AD-953DA5C18BE7}") IcxTransparentControl  : public System::IInterface 
{
	
public:
	virtual bool __fastcall IsTransparentRegionsPresent(void) = 0 ;
};

class DELPHICLASS TcxControlChildComponent;
class DELPHICLASS TcxControl;
class PASCALIMPLEMENTATION TcxControlChildComponent : public Cxclasses::TcxComponent
{
	typedef Cxclasses::TcxComponent inherited;
	
private:
	TcxControl* FControl;
	bool __fastcall GetIsLoading(void);
	
protected:
	HIDESBASE virtual bool __fastcall GetIsDestroying(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall SetControl(TcxControl* Value);
	
public:
	__fastcall virtual TcxControlChildComponent(System::Classes::TComponent* AOwner);
	__fastcall virtual TcxControlChildComponent(TcxControl* AControl, bool AAssignOwner);
	__fastcall virtual ~TcxControlChildComponent(void);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	__property TcxControl* Control = {read=FControl, write=SetControl};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
};


class DELPHICLASS TcxScrollBarData;
class PASCALIMPLEMENTATION TcxScrollBarData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FAllowHide;
	bool FAllowShow;
	bool FEnabled;
	bool FIsValid;
	Vcl::Forms::TScrollBarInc FLargeChange;
	int FMin;
	int FMax;
	int FPosition;
	int FPageSize;
	Vcl::Forms::TScrollBarInc FSmallChange;
	bool FVisible;
	
protected:
	void __fastcall Validate(void);
	
public:
	__property bool AllowHide = {read=FAllowHide, write=FAllowHide, nodefault};
	__property bool AllowShow = {read=FAllowShow, write=FAllowShow, nodefault};
	__property bool Enabled = {read=FEnabled, write=FEnabled, nodefault};
	__property bool IsValid = {read=FIsValid, nodefault};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=FLargeChange, write=FLargeChange, nodefault};
	__property int Min = {read=FMin, write=FMin, nodefault};
	__property int Max = {read=FMax, write=FMax, nodefault};
	__property int Position = {read=FPosition, write=FPosition, nodefault};
	__property int PageSize = {read=FPageSize, write=FPageSize, nodefault};
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=FSmallChange, write=FSmallChange, nodefault};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxScrollBarData(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxScrollBarData(void) { }
	
};


__interface IcxControlScrollBar;
typedef System::DelphiInterface<IcxControlScrollBar> _di_IcxControlScrollBar;
class DELPHICLASS TcxControlScrollBar;
__interface  INTERFACE_UUID("{D70735C6-82E8-4D17-AE14-9317D2A11D0C}") IcxControlScrollBar  : public System::IInterface 
{
	
public:
	virtual void __fastcall ApplyData(void) = 0 ;
	virtual TcxControlScrollBar* __fastcall GetControl(void) = 0 ;
	virtual System::Types::TRect __fastcall GetBoundsRect(void) = 0 ;
	virtual TcxScrollBarData* __fastcall GetData(void) = 0 ;
	virtual bool __fastcall GetEnabled(void) = 0 ;
	virtual int __fastcall GetHeight(void) = 0 ;
	virtual Vcl::Forms::TScrollBarKind __fastcall GetKind(void) = 0 ;
	virtual Vcl::Forms::TScrollBarInc __fastcall GetLargeChange(void) = 0 ;
	virtual int __fastcall GetLeft(void) = 0 ;
	virtual int __fastcall GetMax(void) = 0 ;
	virtual int __fastcall GetMin(void) = 0 ;
	virtual int __fastcall GetPageSize(void) = 0 ;
	virtual int __fastcall GetPosition(void) = 0 ;
	virtual Vcl::Forms::TScrollBarInc __fastcall GetSmallChange(void) = 0 ;
	virtual int __fastcall GetTop(void) = 0 ;
	virtual bool __fastcall GetUnlimitedTracking(void) = 0 ;
	virtual bool __fastcall GetVisible(void) = 0 ;
	virtual int __fastcall GetWidth(void) = 0 ;
	virtual void __fastcall SetBoundsRect(const System::Types::TRect &AValue) = 0 ;
	virtual void __fastcall SetEnabled(bool AValue) = 0 ;
	virtual void __fastcall SetHeight(int AValue) = 0 ;
	virtual void __fastcall SetKind(Vcl::Forms::TScrollBarKind AValue) = 0 ;
	virtual void __fastcall SetLargeChange(Vcl::Forms::TScrollBarInc AValue) = 0 ;
	virtual void __fastcall SetLeft(int AValue) = 0 ;
	virtual void __fastcall SetMax(int AValue) = 0 ;
	virtual void __fastcall SetMin(int AValue) = 0 ;
	virtual void __fastcall SetPageSize(int AValue) = 0 ;
	virtual void __fastcall SetPosition(int AValue) = 0 ;
	virtual void __fastcall SetScrollParams(int AMin, int AMax, int APosition, int APageSize, bool ARedraw = true) = 0 ;
	virtual void __fastcall SetSmallChange(Vcl::Forms::TScrollBarInc AValue) = 0 ;
	virtual void __fastcall SetTop(int AValue) = 0 ;
	virtual void __fastcall SetUnlimitedTracking(bool AValue) = 0 ;
	virtual void __fastcall SetVisible(bool AValue) = 0 ;
	virtual void __fastcall SetWidth(int AValue) = 0 ;
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property TcxControlScrollBar* Control = {read=GetControl};
	__property TcxScrollBarData* Data = {read=GetData};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled};
	__property int Height = {read=GetHeight, write=SetHeight};
	__property Vcl::Forms::TScrollBarKind Kind = {read=GetKind, write=SetKind};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=GetLargeChange, write=SetLargeChange};
	__property int Left = {read=GetLeft, write=SetLeft};
	__property int Max = {read=GetMax, write=SetMax};
	__property int Min = {read=GetMin, write=SetMin};
	__property int PageSize = {read=GetPageSize, write=SetPageSize};
	__property int Position = {read=GetPosition, write=SetPosition};
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=GetSmallChange, write=SetSmallChange};
	__property int Top = {read=GetTop, write=SetTop};
	__property bool UnlimitedTracking = {read=GetUnlimitedTracking, write=SetUnlimitedTracking};
	__property bool Visible = {read=GetVisible, write=SetVisible};
	__property int Width = {read=GetWidth, write=SetWidth};
};

class PASCALIMPLEMENTATION TcxControlScrollBar : public Cxscrollbar::TcxScrollBar
{
	typedef Cxscrollbar::TcxScrollBar inherited;
	
private:
	TcxScrollBarData* FData;
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	
protected:
	virtual void __fastcall DoPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall FocusParent(void);
	DYNAMIC void __fastcall SetZOrder(bool TopMost);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TcxControlScrollBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxControlScrollBar(void);
	void __fastcall ApplyData(void);
	HIDESBASE System::Types::TRect __fastcall GetBoundsRect(void);
	HIDESBASE TcxControlScrollBar* __fastcall GetControl(void);
	TcxScrollBarData* __fastcall GetData(void);
	int __fastcall GetHeight(void);
	int __fastcall GetLeft(void);
	int __fastcall GetTop(void);
	bool __fastcall GetVisible(void);
	int __fastcall GetWidth(void);
	HIDESBASE void __fastcall SetBoundsRect(const System::Types::TRect &AValue);
	HIDESBASE void __fastcall SetHeight(int AValue);
	HIDESBASE void __fastcall SetLeft(int AValue);
	HIDESBASE void __fastcall SetTop(int AValue);
	HIDESBASE void __fastcall SetVisible(bool AValue);
	HIDESBASE void __fastcall SetWidth(int AValue);
	__property TcxControlScrollBar* Control = {read=GetControl};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxControlScrollBar(HWND ParentWindow) : Cxscrollbar::TcxScrollBar(ParentWindow) { }
	
private:
	void *__IcxControlScrollBar;	/* IcxControlScrollBar */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D70735C6-82E8-4D17-AE14-9317D2A11D0C}
	operator _di_IcxControlScrollBar()
	{
		_di_IcxControlScrollBar intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxControlScrollBar*(void) { return (IcxControlScrollBar*)&__IcxControlScrollBar; }
	#endif
	
};


typedef System::TMetaClass* TcxControlScrollBarClass;

class DELPHICLASS TcxControlScrollBarHelper;
class PASCALIMPLEMENTATION TcxControlScrollBarHelper : public Cxscrollbar::TcxScrollBarHelper
{
	typedef Cxscrollbar::TcxScrollBarHelper inherited;
	
private:
	TcxScrollBarData* FData;
	
public:
	__fastcall virtual TcxControlScrollBarHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner);
	__fastcall virtual ~TcxControlScrollBarHelper(void);
	virtual void __fastcall Repaint(void);
	void __fastcall ApplyData(void);
	TcxControlScrollBar* __fastcall GetControl(void);
	TcxScrollBarData* __fastcall GetData(void);
	int __fastcall GetHeight(void);
	int __fastcall GetLeft(void);
	int __fastcall GetTop(void);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(int Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetTop(int Value);
	void __fastcall SetWidth(int Value);
	__property TcxControlScrollBar* Control = {read=GetControl};
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
private:
	void *__IcxControlScrollBar;	/* IcxControlScrollBar */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D70735C6-82E8-4D17-AE14-9317D2A11D0C}
	operator _di_IcxControlScrollBar()
	{
		_di_IcxControlScrollBar intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxControlScrollBar*(void) { return (IcxControlScrollBar*)&__IcxControlScrollBar; }
	#endif
	
};


typedef System::TMetaClass* TcxControlScrollBarHelperClass;

class DELPHICLASS TcxSizeGrip;
class PASCALIMPLEMENTATION TcxSizeGrip : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &AMessage);
	
protected:
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas);
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall SetZOrder(bool TopMost);
	
public:
	__fastcall virtual TcxSizeGrip(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSizeGrip(void);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSizeGrip(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxSizeGripClass;

class DELPHICLASS TcxSizeGripHelper;
class PASCALIMPLEMENTATION TcxSizeGripHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBoundsRect;
	bool FIsNonClient;
	Cxscrollbar::_di_IcxScrollBarOwner FOwner;
	bool FVisible;
	void __fastcall RefreshNCPart(const System::Types::TRect &ARect);
	
protected:
	__property Cxscrollbar::_di_IcxScrollBarOwner Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxSizeGripHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Repaint(void);
	__property System::Types::TRect BoundsRect = {read=FBoundsRect, write=FBoundsRect};
	__property bool IsNonClient = {read=FIsNonClient, write=FIsNonClient, nodefault};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSizeGripHelper(void) { }
	
};


typedef System::TMetaClass* TcxSizeGripHelperClass;

class DELPHICLASS TcxControlScrollBarsManager;
class PASCALIMPLEMENTATION TcxControlScrollBarsManager : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool FIsCapture;
	TcxControlScrollBarHelper* FHotScrollBar;
	TcxControl* FOwner;
	System::Classes::TList* FScrollBars;
	TcxControlScrollBarHelper* __fastcall GetScrollBars(int AIndex);
	void __fastcall SetHotScrollBar(TcxControlScrollBarHelper* AValue);
	void __fastcall SetIsCapture(bool AValue);
	
protected:
	virtual bool __fastcall ProcessMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall ProcessMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall ProcessMouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MouseLeave(void);
	bool __fastcall PtInCaller(const System::Types::TPoint P);
	__property TcxControlScrollBarHelper* HotScrollBar = {read=FHotScrollBar, write=SetHotScrollBar};
	__property bool IsCapture = {read=FIsCapture, write=SetIsCapture, nodefault};
	__property TcxControlScrollBarHelper* ScrollBars[int Index] = {read=GetScrollBars};
	
public:
	__fastcall virtual TcxControlScrollBarsManager(TcxControl* AOwner);
	__fastcall virtual ~TcxControlScrollBarsManager(void);
	virtual bool __fastcall HandleMessage(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsScrollBarsArea(const System::Types::TPoint APoint);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall RegisterScrollBar(TcxControlScrollBarHelper* AScrollBar);
	void __fastcall UnRegisterScrollBar(TcxControlScrollBarHelper* AScrollBar);
private:
	void *__IcxMouseTrackingCaller2;	/* IcxMouseTrackingCaller2 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator _di_IcxMouseTrackingCaller2()
	{
		_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxMouseTrackingCaller2*(void) { return (IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator _di_IcxMouseTrackingCaller()
	{
		_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxMouseTrackingCaller*(void) { return (IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	
};


class DELPHICLASS TcxControlCustomScrollBars;
class PASCALIMPLEMENTATION TcxControlCustomScrollBars : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool FCalculating;
	TcxControl* FOwner;
	System::TObject* FHScrollBar;
	System::TObject* FSizeGrip;
	System::TObject* FVScrollBar;
	
protected:
	virtual void __fastcall ApplyData(void);
	virtual void __fastcall BringInternalControlsToFront(void);
	virtual bool __fastcall CheckSize(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall CheckSizeGripVisible(bool AValue) = 0 ;
	virtual System::TObject* __fastcall CreateScrollBar(Vcl::Forms::TScrollBarKind AKind) = 0 ;
	virtual void __fastcall CreateScrollBars(void);
	virtual System::TObject* __fastcall CreateSizeGrip(void) = 0 ;
	virtual void __fastcall DestroyScrollBars(void);
	virtual void __fastcall DoScroll(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	virtual _di_IcxControlScrollBar __fastcall GetScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall InitScrollBars(void);
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall IsScrollBarVisible(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsSizeGripArea(const System::Types::TPoint APoint);
	virtual void __fastcall SetInternalControlsBounds(void);
	virtual void __fastcall UpdateInternalControlsState(void);
	__property bool Calculating = {read=FCalculating, write=FCalculating, nodefault};
	__property TcxControl* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxControlCustomScrollBars(TcxControl* AOwner);
	__fastcall virtual ~TcxControlCustomScrollBars(void);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall DrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas);
};


typedef System::TMetaClass* TcxControlCustomScrollBarsClass;

class DELPHICLASS TcxControlScrollBars;
class PASCALIMPLEMENTATION TcxControlScrollBars : public TcxControlCustomScrollBars
{
	typedef TcxControlCustomScrollBars inherited;
	
private:
	TcxControlScrollBarHelper* __fastcall GetHScrollBar(void);
	TcxSizeGripHelper* __fastcall GetSizeGrip(void);
	TcxControlScrollBarHelper* __fastcall GetVScrollBar(void);
	
protected:
	virtual Vcl::Controls::TWinControl* __fastcall GetControl(void);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	virtual bool __fastcall CheckSize(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall CheckSizeGripVisible(bool AValue);
	virtual System::TObject* __fastcall CreateScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual System::TObject* __fastcall CreateSizeGrip(void);
	virtual void __fastcall DestroyScrollBars(void);
	virtual TcxControlScrollBarHelperClass __fastcall GetScrollBarClass(Vcl::Forms::TScrollBarKind AKind);
	virtual TcxSizeGripHelperClass __fastcall GetSizeGripClass(void);
	virtual bool __fastcall IsSizeGripArea(const System::Types::TPoint APoint);
	virtual void __fastcall SetInternalControlsBounds(void);
	__property TcxControlScrollBarHelper* HScrollBar = {read=GetHScrollBar};
	__property TcxControlScrollBarHelper* VScrollBar = {read=GetVScrollBar};
	__property TcxSizeGripHelper* SizeGrip = {read=GetSizeGrip};
	
public:
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall DrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TcxControlCustomScrollBars.Create */ inline __fastcall virtual TcxControlScrollBars(TcxControl* AOwner) : TcxControlCustomScrollBars(AOwner) { }
	/* TcxControlCustomScrollBars.Destroy */ inline __fastcall virtual ~TcxControlScrollBars(void) { }
	
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


class DELPHICLASS TcxControlWindowedScrollBars;
class PASCALIMPLEMENTATION TcxControlWindowedScrollBars : public TcxControlCustomScrollBars
{
	typedef TcxControlCustomScrollBars inherited;
	
private:
	TcxControlScrollBar* __fastcall GetHScrollBar(void);
	TcxSizeGrip* __fastcall GetSizeGrip(void);
	TcxControlScrollBar* __fastcall GetVScrollBar(void);
	
protected:
	virtual void __fastcall BringInternalControlsToFront(void);
	virtual bool __fastcall CheckSize(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall CheckSizeGripVisible(bool AValue);
	virtual System::TObject* __fastcall CreateScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual System::TObject* __fastcall CreateSizeGrip(void);
	virtual void __fastcall DestroyScrollBars(void);
	virtual void __fastcall InitScrollBars(void);
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual void __fastcall SetInternalControlsBounds(void);
	virtual void __fastcall UpdateInternalControlsState(void);
	__property TcxControlScrollBar* HScrollBar = {read=GetHScrollBar};
	__property TcxControlScrollBar* VScrollBar = {read=GetVScrollBar};
	__property TcxSizeGrip* SizeGrip = {read=GetSizeGrip};
	
public:
	virtual void __fastcall Invalidate(void);
public:
	/* TcxControlCustomScrollBars.Create */ inline __fastcall virtual TcxControlWindowedScrollBars(TcxControl* AOwner) : TcxControlCustomScrollBars(AOwner) { }
	/* TcxControlCustomScrollBars.Destroy */ inline __fastcall virtual ~TcxControlWindowedScrollBars(void) { }
	
};


typedef System::TMetaClass* TcxDragAndDropObjectClass;

class DELPHICLASS TcxDragAndDropObject;
class PASCALIMPLEMENTATION TcxDragAndDropObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxControl* FControl;
	bool FDirty;
	void __fastcall SetDirty(bool Value);
	
protected:
	void __fastcall ChangeMousePos(const System::Types::TPoint P);
	virtual void __fastcall DirtyChanged(void);
	virtual System::Types::TPoint __fastcall GetClientCursorPos(void);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual bool __fastcall GetImmediateStart(void);
	virtual void __fastcall AfterDragAndDrop(bool Accepted);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas, write=FCanvas};
	__property TcxControl* Control = {read=FControl};
	__property bool Dirty = {read=FDirty, write=SetDirty, nodefault};
	
public:
	System::Types::TPoint CurMousePos;
	System::Types::TPoint PrevMousePos;
	__fastcall virtual TcxDragAndDropObject(TcxControl* AControl);
	void __fastcall DoBeginDragAndDrop(void);
	void __fastcall DoDragAndDrop(const System::Types::TPoint P, bool &Accepted);
	void __fastcall DoEndDragAndDrop(bool Accepted);
	__property bool ImmediateStart = {read=GetImmediateStart, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDragAndDropObject(void) { }
	
};


class DELPHICLASS TcxDragControlObject;
class PASCALIMPLEMENTATION TcxDragControlObject : public Vcl::Controls::TDragControlObject
{
	typedef Vcl::Controls::TDragControlObject inherited;
	
protected:
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
public:
	/* TBaseDragControlObject.Create */ inline __fastcall virtual TcxDragControlObject(Vcl::Controls::TControl* AControl) : Vcl::Controls::TDragControlObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDragControlObject(void) { }
	
};


typedef System::TMetaClass* TcxDragImageListClass;

class DELPHICLASS TcxDragImageList;
class PASCALIMPLEMENTATION TcxDragImageList : public Vcl::Controls::TDragImageList
{
	typedef Vcl::Controls::TDragImageList inherited;
	
public:
	/* TCustomImageList.Create */ inline __fastcall virtual TcxDragImageList(System::Classes::TComponent* AOwner) : Vcl::Controls::TDragImageList(AOwner) { }
	/* TCustomImageList.CreateSize */ inline __fastcall TcxDragImageList(int AWidth, int AHeight) : Vcl::Controls::TDragImageList(AWidth, AHeight) { }
	/* TCustomImageList.Destroy */ inline __fastcall virtual ~TcxDragImageList(void) { }
	
};


enum TcxControlBorderStyle : unsigned char { cxcbsNone, cxcbsDefault };

enum TcxDragAndDropState : unsigned char { ddsNone, ddsStarting, ddsInProcess };

enum TcxKey : unsigned char { kAll, kArrows, kChars, kTab };

typedef System::Set<TcxKey, TcxKey::kAll, TcxKey::kTab>  TcxKeys;

enum TcxMouseWheelScrollingKind : unsigned char { mwskNone, mwskHorizontal, mwskVertical };

class DELPHICLASS TcxControlListernerLink;
class PASCALIMPLEMENTATION TcxControlListernerLink : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxControl* Ref;
public:
	/* TObject.Create */ inline __fastcall TcxControlListernerLink(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxControlListernerLink(void) { }
	
};


class PASCALIMPLEMENTATION TcxControl : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	Cxgraphics::TcxCanvas* FActiveCanvas;
	TcxControlBorderStyle FBorderStyle;
	Cxgraphics::TcxCanvas* FCanvas;
	bool FCreatingWindow;
	TcxDragAndDropObject* FDragAndDropObject;
	TcxDragAndDropObjectClass FDragAndDropObjectClass;
	System::Uitypes::TCursor FDragAndDropPrevCursor;
	TcxDragAndDropState FDragAndDropState;
	TcxDragImageList* FDragImages;
	bool FFinishingDragAndDrop;
	bool FFocusOnClick;
	System::Classes::_di_IInterfaceList FFontListenerList;
	Dxtouch::TdxGestureHelper* FGestureHelper;
	System::Types::TPoint FGestureAccumulatedDelta;
	bool FInitialHScrollBarVisible;
	bool FInitialVScrollBarVisible;
	bool FIsInitialScrollBarsParams;
	TcxKeys FKeys;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	bool FMouseButtonPressed;
	System::TObject* FMouseCaptureObject;
	System::Types::TPoint FMouseDownPos;
	int FMouseEnterCounter;
	bool FMouseRightButtonReleased;
	int FMouseWheelAccumulator;
	System::Classes::TComponent* FPopupMenu;
	TcxControlCustomScrollBars* FMainScrollBars;
	System::Uitypes::TScrollStyle FScrollBars;
	TcxControlScrollBarsManager* FScrollBarsManager;
	int FScrollBarsLockCount;
	bool FScrollBarsUpdateNeeded;
	bool FUpdatingScrollBars;
	bool FIsScrollingContent;
	System::Classes::TNotifyEvent FOnFocusChanged;
	System::Classes::TNotifyEvent FOnMouseEnter;
	System::Classes::TNotifyEvent FOnMouseLeave;
	Cxgraphics::TcxCanvas* __fastcall GetActiveCanvas(void);
	TcxDragAndDropObject* __fastcall GetDragAndDropObject(void);
	_di_IcxControlScrollBar __fastcall GetHScrollBar(void);
	bool __fastcall GetHScrollBarVisible(void);
	bool __fastcall GetIsDestroying(void);
	bool __fastcall GetIsLoading(void);
	TcxSizeGrip* __fastcall GetSizeGrip(void);
	_di_IcxControlScrollBar __fastcall GetVScrollBar(void);
	bool __fastcall GetVScrollBarVisible(void);
	void __fastcall SetBorderStyle(TcxControlBorderStyle Value);
	void __fastcall SetDragAndDropState(TcxDragAndDropState Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetKeys(TcxKeys Value);
	void __fastcall SetMouseCaptureObject(System::TObject* Value);
	HIDESBASE void __fastcall SetPopupMenu(System::Classes::TComponent* Value);
	void __fastcall SetScrollBars(System::Uitypes::TScrollStyle Value);
	void __fastcall DoNCPaint(HDC AWindowDC);
	void __fastcall DoScrollBarBasedGestureScroll(Vcl::Forms::TScrollBarKind AKind, int &AAccumulatedDelta, int ADeltaX, int ADeltaY);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	MESSAGE void __fastcall WMPrint(Winapi::Messages::TWMPrint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCursorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMInvalidate(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMNCSizeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CNSysKeyDown(Winapi::Messages::TWMKey &Message);
	void __fastcall CreateScrollBars(void);
	void __fastcall DestroyScrollBars(void);
	
protected:
	System::Types::TRect FBounds;
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall DestroyWindowHandle(void);
	DYNAMIC void __fastcall DoContextPopup(System::Types::TPoint MousePos, bool &Handled);
	virtual void __fastcall BeginGestureScroll(System::Types::TPoint APos);
	virtual bool __fastcall CanScrollContentByGestureWithoutScrollBars(void);
	virtual void __fastcall CheckOverpan(Vcl::Forms::TScrollBarKind AScrollKind, int ANewDataPos, int AMinDataPos, int AMaxDataPos, int ADeltaX, int ADeltaY);
	virtual void __fastcall DoGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind, int ANewScrollPos);
	virtual void __fastcall EndGestureScroll(void);
	virtual void __fastcall DoGesture(const Vcl::Controls::TGestureEventInfo &EventInfo, bool &Handled);
	virtual void __fastcall DoGetGestureOptions(Vcl::Controls::TInteractiveGestures &Gestures, Vcl::Controls::TInteractiveGestureOptions &Options);
	virtual Vcl::Controls::TInteractiveGestures __fastcall GetDefaultInteractiveGestures(void);
	virtual Vcl::Controls::TInteractiveGestureOptions __fastcall GetDefaultInteractiveGestureOptions(void);
	DYNAMIC bool __fastcall IsTouchPropertyStored(Vcl::Controls::TTouchProperty AProperty);
	virtual void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	virtual bool __fastcall IsDefaultGesture(int AGestureID);
	virtual bool __fastcall IsGestureHelperMessage(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsGestureScrolling(void);
	virtual bool __fastcall IsScrollBarBasedGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual int __fastcall GetDefaultPanOptions(void);
	virtual void __fastcall ScrollContentByGesture(Vcl::Forms::TScrollBarKind AScrollKind, int ADelta);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* AMenu, int X, int Y);
	DYNAMIC Vcl::Menus::TPopupMenu* __fastcall GetPopupMenu(void);
	virtual bool __fastcall InternalMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	HIDESBASE virtual bool __fastcall IsMenuKey(Winapi::Messages::TWMKey &Message);
	virtual void __fastcall Modified(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetParentBackground(bool Value);
	virtual void __fastcall EraseBackground(HDC DC)/* overload */;
	virtual void __fastcall EraseBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
	virtual void __fastcall Paint(void);
	void __fastcall StandardPaintHandler(Winapi::Messages::TWMPaint &Message);
	virtual void __fastcall PaintNonClientArea(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintWindow(HDC DC);
	DYNAMIC void __fastcall AddChildComponent(TcxControlChildComponent* AComponent);
	DYNAMIC void __fastcall RemoveChildComponent(TcxControlChildComponent* AComponent);
	virtual void __fastcall AfterMouseDown(System::Uitypes::TMouseButton AButton, int X, int Y);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall BringInternalControlsToFront(void);
	virtual void __fastcall CancelMouseOperations(void);
	DYNAMIC void __fastcall DoCancelMode(void);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawScrollBars(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetBorderSize(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual System::Types::TRect __fastcall GetClientOffsets(void);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC TDragControlObjectClass __fastcall GetDragObjectClass(void);
	virtual bool __fastcall GetIsDesigning(void);
	virtual bool __fastcall GetIsFocused(void);
	virtual TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass(void);
	System::Types::TPoint __fastcall GetMouseCursorClientPos(void);
	virtual TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual bool __fastcall GetPaintBlackOpaqueOnGlass(void);
	virtual TcxControlScrollBarClass __fastcall GetScrollBarClass(Vcl::Forms::TScrollBarKind AKind);
	virtual TcxSizeGripClass __fastcall GetSizeGripClass(void);
	virtual void __fastcall InitControl(void);
	__classmethod void __fastcall InvalidateControl(Vcl::Controls::TWinControl* AControl, bool ANeedInvalidateSelf, bool ANeedInvalidateChildren);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall FocusEnter(void);
	DYNAMIC void __fastcall FocusLeave(void);
	virtual void __fastcall SetPaintRegion(void);
	virtual bool __fastcall AllowCompositionPainting(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual bool __fastcall CanFocusOnClick(int X, int Y)/* overload */;
	virtual bool __fastcall FocusWhenChildIsClicked(Vcl::Controls::TControl* AChild);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall HasNonClientArea(void);
	virtual bool __fastcall IsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	virtual bool __fastcall IsTransparentBackground(void);
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	DYNAMIC bool __fastcall MayFocus(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual bool __fastcall UpdateMousePositionIfControlMoved(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC void __fastcall ColorChanged(void);
	virtual void __fastcall ParentBackgroundChanged(void);
	DYNAMIC void __fastcall CursorChanged(void);
	DYNAMIC void __fastcall FocusChanged(void);
	HIDESBASEDYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall TextChanged(void);
	DYNAMIC void __fastcall VisibleChanged(void);
	virtual bool __fastcall AllowGesture(int AGestureId);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual int __fastcall GetPanOptions(void);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint APoint);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual Dxtouch::_di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint APoint);
	virtual NativeUInt __fastcall GetGestureClientHandle(void);
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeelValue(void);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetScrollBarLookAndFeel(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	void __fastcall LookAndFeelChangeHandler(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	virtual bool __fastcall CanScrollLineWithoutScrollBars(Cxclasses::TcxDirection ADirection);
	virtual bool __fastcall CanUpdateScrollBars(void);
	void __fastcall CheckNeedsScrollBars(void);
	void __fastcall DoScrolling(void);
	virtual void __fastcall DoUpdateScrollBars(void);
	virtual System::Types::TRect __fastcall GetHScrollBarBounds(void);
	virtual System::Types::TRect __fastcall GetSizeGripBounds(void);
	_di_IcxControlScrollBar __fastcall GetScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual System::Uitypes::TScrollStyle __fastcall GetSystemSizeScrollBars(void);
	virtual System::Types::TRect __fastcall GetVScrollBarBounds(void);
	void __fastcall InitScrollBars(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual bool __fastcall IsScrollBarsArea(const System::Types::TPoint APoint);
	bool __fastcall IsScrollBarsCapture(void);
	virtual bool __fastcall IsSizeGripArea(const System::Types::TPoint APoint);
	virtual bool __fastcall IsSizeGripVisible(void);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual bool __fastcall NeedsToBringInternalControlsToFront(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SetInternalControlsBounds(void);
	virtual void __fastcall UpdateInternalControlsState(void);
	virtual void __fastcall UpdateScrollBars(void);
	__property _di_IcxControlScrollBar HScrollBar = {read=GetHScrollBar};
	__property bool HScrollBarVisible = {read=GetHScrollBarVisible, nodefault};
	__property TcxControlCustomScrollBars* MainScrollBars = {read=FMainScrollBars};
	__property TcxControlScrollBarsManager* ScrollBarsManager = {read=FScrollBarsManager};
	__property System::Uitypes::TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=3};
	__property TcxSizeGrip* SizeGrip = {read=GetSizeGrip};
	__property bool UpdatingScrollBars = {read=FUpdatingScrollBars, nodefault};
	__property _di_IcxControlScrollBar VScrollBar = {read=GetVScrollBar};
	__property bool VScrollBarVisible = {read=GetVScrollBarVisible, nodefault};
	virtual bool __fastcall AllowAutoDragAndDropAtDesignTime(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC bool __fastcall AllowDragAndDropWithoutFocus(void);
	virtual bool __fastcall CanCancelDragStartOnCaptureObjectClear(void);
	virtual TcxDragAndDropObject* __fastcall CreateDragAndDropObject(void);
	DYNAMIC void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	DYNAMIC void __fastcall EndDragAndDrop(bool Accepted);
	virtual TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	DYNAMIC bool __fastcall CanDrag(int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DrawDragImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual TcxDragImageListClass __fastcall GetDragImagesClass(void);
	virtual System::Types::TPoint __fastcall GetDragImagesSize(void);
	virtual bool __fastcall GetIsCopyDragDrop(void);
	virtual bool __fastcall HasDragImages(void);
	void __fastcall HideDragImage(void);
	virtual void __fastcall InitDragImages(TcxDragImageList* ADragImages);
	void __fastcall ShowDragImage(void);
	__property TcxDragImageList* DragImages = {read=FDragImages};
	__property Dxtouch::TdxGestureHelper* GestureHelper = {read=FGestureHelper};
	__property bool IsCopyDragDrop = {read=GetIsCopyDragDrop, nodefault};
	__property int BorderSize = {read=GetBorderSize, nodefault};
	__property TcxControlBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, nodefault};
	__property bool CreatingWindow = {read=FCreatingWindow, nodefault};
	__property bool FocusOnClick = {read=FFocusOnClick, write=FFocusOnClick, default=1};
	__property System::Classes::_di_IInterfaceList FontListenerList = {read=FFontListenerList};
	__property TcxKeys Keys = {read=FKeys, write=SetKeys, nodefault};
	__property bool MouseRightButtonReleased = {read=FMouseRightButtonReleased, write=FMouseRightButtonReleased, nodefault};
	__property TcxMouseWheelScrollingKind MouseWheelScrollingKind = {read=GetMouseWheelScrollingKind, nodefault};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property bool IsScrollingContent = {read=FIsScrollingContent, nodefault};
	__property ParentBackground = {default=1};
	__property System::Classes::TNotifyEvent OnFocusChanged = {read=FOnFocusChanged, write=FOnFocusChanged};
	__property System::Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property System::Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	
public:
	__fastcall virtual TcxControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxControl(void);
	virtual Vcl::Controls::TDragImageList* __fastcall GetDragImages(void);
	virtual bool __fastcall CanFocusEx(void);
	virtual bool __fastcall AcceptMousePosForClick(int X, int Y);
	void __fastcall InvalidateRect(const System::Types::TRect &R, bool EraseBackground);
	void __fastcall InvalidateRgn(Cxgraphics::TcxRegion* ARegion, bool EraseBackground);
	void __fastcall InvalidateWithChildren(void);
	virtual bool __fastcall IsMouseInPressedArea(int X, int Y);
	void __fastcall PostMouseMove(System::Types::TPoint AMousePos)/* overload */;
	void __fastcall PostMouseMove(void)/* overload */;
	virtual void __fastcall ScrollContent(Cxclasses::TcxDirection ADirection);
	void __fastcall ScrollWindow(int DX, int DY, const System::Types::TRect &AScrollRect);
	void __fastcall SetScrollBarInfo(Vcl::Forms::TScrollBarKind AScrollBarKind, int AMin, int AMax, int AStep, int APage, int APos, bool AAllowShow, bool AAllowHide);
	DYNAMIC bool __fastcall StartDrag(Vcl::Controls::TDragObject* DragObject);
	void __fastcall UpdateWithChildren(void);
	DYNAMIC void __fastcall BeginDragAndDrop(void);
	void __fastcall FinishDragAndDrop(bool Accepted);
	__property TcxDragAndDropObject* DragAndDropObject = {read=GetDragAndDropObject};
	__property TcxDragAndDropObjectClass DragAndDropObjectClass = {read=GetDragAndDropObjectClass, write=FDragAndDropObjectClass};
	__property TcxDragAndDropState DragAndDropState = {read=FDragAndDropState, write=SetDragAndDropState, nodefault};
	void __fastcall AddFontListener(Cxgraphics::_di_IcxFontListener AListener);
	void __fastcall RemoveFontListener(Cxgraphics::_di_IcxFontListener AListener);
	void __fastcall LockScrollBars(void);
	void __fastcall UnlockScrollBars(void);
	virtual void __fastcall TranslationChanged(void);
	virtual void __fastcall SystemInfoChanged(unsigned AParameter);
	__property Cxgraphics::TcxCanvas* ActiveCanvas = {read=GetActiveCanvas};
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsFocused = {read=GetIsFocused, nodefault};
	__property System::TObject* MouseCaptureObject = {read=FMouseCaptureObject, write=SetMouseCaptureObject};
	__property System::Types::TPoint MouseDownPos = {read=FMouseDownPos, write=FMouseDownPos};
	__property TabStop = {default=1};
	
__published:
	__property Touch;
	__property OnGesture;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxControl(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
private:
	void *__IcxScrollBarOwner;	/* Cxscrollbar::IcxScrollBarOwner */
	void *__IdxGestureOwner;	/* Dxtouch::IdxGestureOwner */
	void *__IdxGestureClient;	/* Dxtouch::IdxGestureClient */
	void *__IdxSystemInfoListener;	/* IdxSystemInfoListener */
	void *__IdxLocalizerListener;	/* Dxcore::IdxLocalizerListener */
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4DF001DA-BE2C-4817-B75C-55171270D158}
	operator Dxtouch::_di_IdxGestureOwner()
	{
		Dxtouch::_di_IdxGestureOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureOwner*(void) { return (Dxtouch::IdxGestureOwner*)&__IdxGestureOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {652B8A09-DAC8-4332-9206-C8905AEE7791}
	operator Dxtouch::_di_IdxGestureClient()
	{
		Dxtouch::_di_IdxGestureClient intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureClient*(void) { return (Dxtouch::IdxGestureClient*)&__IdxGestureClient; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F137963E-6165-47F9-A4C7-96BB4EB91AE0}
	operator _di_IdxSystemInfoListener()
	{
		_di_IdxSystemInfoListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxSystemInfoListener*(void) { return (IdxSystemInfoListener*)&__IdxSystemInfoListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2E926681-1A56-4599-E8E0-B02D62740E56}
	operator Dxcore::_di_IdxLocalizerListener()
	{
		Dxcore::_di_IdxLocalizerListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcore::IdxLocalizerListener*(void) { return (Dxcore::IdxLocalizerListener*)&__IdxLocalizerListener; }
	#endif
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
	
};


typedef System::TMetaClass* TcxControlClass;

enum TdxChangeType : unsigned char { ctLight, ctMedium, ctHard };

enum TdxAutoSizeMode : unsigned char { asNone, asAutoWidth, asAutoHeight, asAutoSize };

__interface IdxScrollingControl;
typedef System::DelphiInterface<IdxScrollingControl> _di_IdxScrollingControl;
__interface  INTERFACE_UUID("{7F141990-5975-4E6B-BFAF-03D378860F20}") IdxScrollingControl  : public System::IInterface 
{
	
public:
	virtual int __fastcall GetLeftPos(void) = 0 ;
	virtual void __fastcall SetLeftPos(int Value) = 0 ;
	virtual int __fastcall GetTopPos(void) = 0 ;
	virtual void __fastcall SetTopPos(int Value) = 0 ;
	virtual System::Types::TSize __fastcall GetContentSize(void) = 0 ;
	virtual TcxControl* __fastcall GetInstance(void) = 0 ;
};

class DELPHICLASS TcxScrollingControl;
class PASCALIMPLEMENTATION TcxScrollingControl : public TcxControl
{
	typedef TcxControl inherited;
	
private:
	int __fastcall GetTopPos(void);
	int __fastcall GetLeftPos(void);
	TcxControl* __fastcall GetInstance(void);
	
protected:
	TdxAutoSizeMode FAutoSizeMode;
	bool FAutoSizeModeSetting;
	int FLeftPos;
	int FTopPos;
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall Calculate(TdxChangeType AType);
	virtual void __fastcall LayoutChanged(TdxChangeType AType = (TdxChangeType)(0x2));
	virtual void __fastcall ScrollPosChanged(void);
	virtual bool __fastcall IsScrollDataValid(void);
	void __fastcall CheckPositions(void);
	void __fastcall CheckLeftPos(int &AValue);
	void __fastcall CheckTopPos(int &AValue);
	virtual System::Types::TSize __fastcall GetContentSize(void);
	virtual System::Types::TSize __fastcall GetClientSize(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	void __fastcall MakeVisible(const System::Types::TRect &ARect, bool AFully);
	virtual void __fastcall SetAutoSize(bool Value);
	virtual void __fastcall SetAutoSizeMode(TdxAutoSizeMode AValue);
	virtual void __fastcall SetLeftPos(int AValue);
	virtual void __fastcall SetTopPos(int AValue);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	__property TdxAutoSizeMode AutoSizeMode = {read=FAutoSizeMode, write=SetAutoSizeMode, nodefault};
	__property int LeftPos = {read=GetLeftPos, write=SetLeftPos, nodefault};
	__property int TopPos = {read=GetTopPos, write=SetTopPos, nodefault};
public:
	/* TcxControl.Create */ inline __fastcall virtual TcxScrollingControl(System::Classes::TComponent* AOwner) : TcxControl(AOwner) { }
	/* TcxControl.Destroy */ inline __fastcall virtual ~TcxScrollingControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxScrollingControl(HWND ParentWindow) : TcxControl(ParentWindow) { }
	
private:
	void *__IdxScrollingControl;	/* IdxScrollingControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7F141990-5975-4E6B-BFAF-03D378860F20}
	operator _di_IdxScrollingControl()
	{
		_di_IdxScrollingControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxScrollingControl*(void) { return (IdxScrollingControl*)&__IdxScrollingControl; }
	#endif
	
};


class DELPHICLASS TdxScrollHelper;
class PASCALIMPLEMENTATION TdxScrollHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	__classmethod void __fastcall CheckLeftPos(_di_IdxScrollingControl AControl, int &AValue);
	__classmethod void __fastcall CheckTopPos(_di_IdxScrollingControl AControl, int &AValue);
	__classmethod void __fastcall ScrollContent(_di_IdxScrollingControl AControl);
	
public:
	__classmethod void __fastcall CheckPositions(_di_IdxScrollingControl AControl);
	__classmethod void __fastcall SetPos(_di_IdxScrollingControl AControl, int X, int Y);
	__classmethod void __fastcall SetLeftPos(_di_IdxScrollingControl AControl, int AValue);
	__classmethod void __fastcall SetTopPos(_di_IdxScrollingControl AControl, int AValue);
	__classmethod bool __fastcall IsScrollDataValid(_di_IdxScrollingControl AControl);
	__classmethod void __fastcall GestureScroll(_di_IdxScrollingControl AControl, int ADeltaX, int ADeltaY);
	__classmethod System::Types::TSize __fastcall GetClientSize(_di_IdxScrollingControl AControl);
	__classmethod void __fastcall InitScrollBarsParameters(_di_IdxScrollingControl AControl);
	__classmethod void __fastcall Scroll(_di_IdxScrollingControl AControl, Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
public:
	/* TObject.Create */ inline __fastcall TdxScrollHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxScrollHelper(void) { }
	
};


class DELPHICLASS TcxCustomizeListBox;
class PASCALIMPLEMENTATION TcxCustomizeListBox : public Vcl::Stdctrls::TListBox
{
	typedef Vcl::Stdctrls::TListBox inherited;
	
private:
	int FDragAndDropItemIndex;
	System::Types::TPoint FMouseDownPos;
	System::TObject* __fastcall GetDragAndDropItemObject(void);
	System::TObject* __fastcall GetItemObject(void);
	void __fastcall SetItemObject(System::TObject* Value);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Winapi::Messages::TWMMouse &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall BeginDragAndDrop(void);
	__property int DragAndDropItemIndex = {read=FDragAndDropItemIndex, nodefault};
	__property System::TObject* DragAndDropItemObject = {read=GetDragAndDropItemObject};
	
public:
	__fastcall virtual TcxCustomizeListBox(System::Classes::TComponent* AOwner);
	__property System::TObject* ItemObject = {read=GetItemObject, write=SetItemObject};
public:
	/* TCustomListBox.Destroy */ inline __fastcall virtual ~TcxCustomizeListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomizeListBox(HWND ParentWindow) : Vcl::Stdctrls::TListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxDesignSelector;
class PASCALIMPLEMENTATION TcxDesignSelector : public TcxControl
{
	typedef TcxControl inherited;
	
private:
	HRGN __fastcall CreateRegion(void);
	System::Types::TRect __fastcall GetDesignRect(void);
	
protected:
	virtual bool __fastcall GetSelected(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TcxDesignSelector(System::Classes::TComponent* AOwner);
	__property System::Types::TRect DesignRect = {read=GetDesignRect};
	__property bool Selected = {read=GetSelected, nodefault};
public:
	/* TcxControl.Destroy */ inline __fastcall virtual ~TcxDesignSelector(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDesignSelector(HWND ParentWindow) : TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TcxMessageWindow;
class PASCALIMPLEMENTATION TcxMessageWindow : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	HWND FHandle;
	void __fastcall MainWndProc(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TcxMessageWindow(void);
	__fastcall virtual ~TcxMessageWindow(void);
	__property HWND Handle = {read=FHandle};
};


class DELPHICLASS TcxSystemController;
class PASCALIMPLEMENTATION TcxSystemController : public TcxMessageWindow
{
	typedef TcxMessageWindow inherited;
	
private:
	System::Classes::TNotifyEvent FPrevWakeMainThread;
	void __fastcall WakeMainThread(System::TObject* Sender);
	void __fastcall HookSynchronizeWakeup(void);
	void __fastcall UnhookSynchronizeWakeup(void);
	
protected:
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TcxSystemController(void);
	__fastcall virtual ~TcxSystemController(void);
};


class DELPHICLASS TdxSystemInfo;
class PASCALIMPLEMENTATION TdxSystemInfo : public TcxMessageWindow
{
	typedef TcxMessageWindow inherited;
	
private:
	bool FIsDropShadow;
	System::Classes::TInterfaceList* FListeners;
	tagNONCLIENTMETRICSW FNonClientMetrics;
	bool __fastcall GetIsRemoteSession(void);
	void __fastcall UpdateCache(unsigned AParameter);
	
protected:
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall NotifyListeners(unsigned AParameter);
	
public:
	__fastcall virtual TdxSystemInfo(void);
	__fastcall virtual ~TdxSystemInfo(void);
	void __fastcall AddListener(_di_IdxSystemInfoListener AListener);
	bool __fastcall GetParameter(unsigned AParameter, void *AValue);
	void __fastcall RemoveListener(_di_IdxSystemInfoListener AListener);
	__property bool IsDropShadow = {read=FIsDropShadow, nodefault};
	__property bool IsRemoteSession = {read=GetIsRemoteSession, nodefault};
	__property tagNONCLIENTMETRICSW NonClientMetrics = {read=FNonClientMetrics};
};


class DELPHICLASS TdxMessagesController;
class PASCALIMPLEMENTATION TdxMessagesController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FLockedMessages;
	
protected:
	void *FOldWndProc;
	
public:
	__fastcall TdxMessagesController(void);
	__fastcall virtual ~TdxMessagesController(void);
	bool __fastcall IsMessageInQueue(NativeUInt AWnd, unsigned AMessage);
	bool __fastcall KillMessages(NativeUInt AWnd, unsigned AMsgFilterMin, unsigned AMsgFilterMax = (unsigned)(0x0), bool AKillAllMessages = true);
	bool __fastcall IsMessageLocked(unsigned AMessage);
	void __fastcall LockMessages(unsigned *AMessages, const int AMessages_Size);
	void __fastcall UnlockMessages(unsigned *AMessages, const int AMessages_Size);
	void __fastcall BlockMessage(NativeUInt AHandle);
	void __fastcall BlockLockedMessage(NativeUInt AHandle, unsigned &AMessage);
};


enum TcxPopupAlignHorz : unsigned char { pahLeft, pahCenter, pahRight };

enum TcxPopupAlignVert : unsigned char { pavTop, pavCenter, pavBottom };

enum TcxPopupDirection : unsigned char { pdHorizontal, pdVertical };

class DELPHICLASS TcxPopupWindow;
class PASCALIMPLEMENTATION TcxPopupWindow : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	bool FAdjustable;
	TcxPopupAlignHorz FAlignHorz;
	TcxPopupAlignVert FAlignVert;
	int FBorderSpace;
	Cxlookandfeelpainters::TcxPopupBorderStyle FBorderStyle;
	Cxgraphics::TcxCanvas* FCanvas;
	TcxPopupDirection FDirection;
	System::Uitypes::TColor FFrameColor;
	System::Types::TRect FOwnerBounds;
	Vcl::Controls::TControl* FOwnerParent;
	HWND FPrevActiveWindow;
	int __fastcall GetNCHeight(void);
	int __fastcall GetNCWidth(void);
	void __fastcall SetBorderSpace(int Value);
	HIDESBASE void __fastcall SetBorderStyle(Cxlookandfeelpainters::TcxPopupBorderStyle Value);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &Message);
	MESSAGE void __fastcall WMActivateApp(Winapi::Messages::TWMActivateApp &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Deactivate(void);
	DYNAMIC void __fastcall Paint(void);
	DYNAMIC void __fastcall VisibleChanged(void);
	virtual System::Types::TPoint __fastcall CalculatePosition(void);
	virtual void __fastcall CalculateSize(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder ABorder);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual int __fastcall GetFrameWidth(Cxgraphics::TcxBorder ABorder);
	virtual System::Types::TRect __fastcall GetOwnerScreenBounds(void);
	virtual void __fastcall InitPopup(void);
	void __fastcall RestoreControlsBounds(void);
	virtual void __fastcall DrawFrame(void);
	bool __fastcall IsSkinnable(void);
	__property int BorderWidths[Cxgraphics::TcxBorder ABorder] = {read=GetBorderWidth};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property int FrameWidths[Cxgraphics::TcxBorder ABorder] = {read=GetFrameWidth};
	__property int NCHeight = {read=GetNCHeight, nodefault};
	__property int NCWidth = {read=GetNCWidth, nodefault};
	
public:
	__fastcall virtual TcxPopupWindow(void);
	__fastcall virtual ~TcxPopupWindow(void);
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall Popup(void);
	__property bool Adjustable = {read=FAdjustable, write=FAdjustable, nodefault};
	__property TcxPopupAlignHorz AlignHorz = {read=FAlignHorz, write=FAlignHorz, nodefault};
	__property TcxPopupAlignVert AlignVert = {read=FAlignVert, write=FAlignVert, nodefault};
	__property int BorderSpace = {read=FBorderSpace, write=SetBorderSpace, nodefault};
	__property Cxlookandfeelpainters::TcxPopupBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, nodefault};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property TcxPopupDirection Direction = {read=FDirection, write=FDirection, nodefault};
	__property System::Uitypes::TColor FrameColor = {read=FFrameColor, write=FFrameColor, nodefault};
	__property System::Types::TRect OwnerBounds = {read=FOwnerBounds, write=FOwnerBounds};
	__property Vcl::Controls::TControl* OwnerParent = {read=FOwnerParent, write=FOwnerParent};
	__property System::Types::TRect OwnerScreenBounds = {read=GetOwnerScreenBounds};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPopupWindow(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
private:
	void *__IdxSkinSupport2;	/* Cxlookandfeels::IdxSkinSupport2 */
	
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
	
};


class DELPHICLASS TcxCustomDragImage;
class PASCALIMPLEMENTATION TcxCustomDragImage : public TcxPopupWindow
{
	typedef TcxPopupWindow inherited;
	
private:
	System::Types::TPoint FPositionOffset;
	bool __fastcall GetAlphaBlended(void);
	bool __fastcall GetVisible(void);
	HIDESBASE void __fastcall SetVisible(bool Value);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	HIDESBASE virtual bool __fastcall IsSkinnable(void);
	
public:
	__fastcall virtual TcxCustomDragImage(void);
	__fastcall virtual ~TcxCustomDragImage(void);
	void __fastcall Init(const System::Types::TRect &ASourceBounds, const System::Types::TPoint ASourcePoint);
	void __fastcall MoveTo(const System::Types::TPoint APosition);
	HIDESBASE void __fastcall Show(int ACmdShow = 0x8);
	HIDESBASE void __fastcall Hide(void);
	__property bool AlphaBlended = {read=GetAlphaBlended, nodefault};
	__property System::Types::TPoint PositionOffset = {read=FPositionOffset, write=FPositionOffset};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomDragImage(System::Classes::TComponent* AOwner, int Dummy) : TcxPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDragImage(HWND ParentWindow) : TcxPopupWindow(ParentWindow) { }
	
private:
	void *__IdxSkinSupport2;	/* Cxlookandfeels::IdxSkinSupport2 */
	
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
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport2; }
	#endif
	
};


class DELPHICLASS TcxDragImage;
class PASCALIMPLEMENTATION TcxDragImage : public TcxCustomDragImage
{
	typedef TcxCustomDragImage inherited;
	
private:
	Cxgraphics::TcxBitmap* FImage;
	Cxgraphics::TcxCanvas* __fastcall GetImageCanvas(void);
	Cxgraphics::TcxCanvas* __fastcall GetWindowCanvas(void);
	
protected:
	DYNAMIC void __fastcall Paint(void);
	__property Cxgraphics::TcxBitmap* Image = {read=FImage};
	__property Cxgraphics::TcxCanvas* WindowCanvas = {read=GetWindowCanvas};
	
public:
	__fastcall virtual TcxDragImage(void);
	__fastcall virtual ~TcxDragImage(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetImageCanvas};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxDragImage(System::Classes::TComponent* AOwner, int Dummy) : TcxCustomDragImage(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDragImage(HWND ParentWindow) : TcxCustomDragImage(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxDragImageClass;

class DELPHICLASS TcxSizeFrame;
class PASCALIMPLEMENTATION TcxSizeFrame : public TcxCustomDragImage
{
	typedef TcxCustomDragImage inherited;
	
private:
	bool FFillSelection;
	int FFrameWidth;
	Cxgraphics::TcxRegion* FRegion;
	void __fastcall InitializeFrameRegion(void);
	void __fastcall SetWindowRegion(void);
	
protected:
	DYNAMIC void __fastcall Paint(void);
	__property int FrameWidth = {read=FFrameWidth, nodefault};
	
public:
	__fastcall virtual TcxSizeFrame(int AFrameWidth);
	__fastcall virtual ~TcxSizeFrame(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall DrawSizeFrame(const System::Types::TRect &ARect)/* overload */;
	void __fastcall DrawSizeFrame(const System::Types::TRect &ARect, Cxgraphics::TcxRegion* const ARegion)/* overload */;
	__property bool FillSelection = {read=FFillSelection, write=FFillSelection, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSizeFrame(System::Classes::TComponent* AOwner, int Dummy) : TcxCustomDragImage(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSizeFrame(HWND ParentWindow) : TcxCustomDragImage(ParentWindow) { }
	
};


enum TcxArrowPlace : unsigned char { apLeft, apTop, apRight, apBottom };

typedef System::TMetaClass* TcxDragAndDropArrowClass;

class DELPHICLASS TcxDragAndDropArrow;
class PASCALIMPLEMENTATION TcxDragAndDropArrow : public TcxDragImage
{
	typedef TcxDragImage inherited;
	
private:
	bool FTransparent;
	bool __fastcall GetTransparent(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetImageBackColor(void);
	__property System::Uitypes::TColor ImageBackColor = {read=GetImageBackColor, nodefault};
	
public:
	__fastcall virtual TcxDragAndDropArrow(bool ATransparent);
	HIDESBASE void __fastcall Init(Vcl::Controls::TControl* AOwner, const System::Types::TRect &AAreaBounds, const System::Types::TRect &AClientRect, TcxArrowPlace APlace)/* overload */;
	HIDESBASE void __fastcall Init(const System::Types::TPoint AOwnerOrigin, const System::Types::TRect &AAreaBounds, const System::Types::TRect &AClientRect, TcxArrowPlace APlace)/* overload */;
	__property bool Transparent = {read=GetTransparent, nodefault};
public:
	/* TcxDragImage.Destroy */ inline __fastcall virtual ~TcxDragAndDropArrow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxDragAndDropArrow(System::Classes::TComponent* AOwner, int Dummy) : TcxDragImage(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDragAndDropArrow(HWND ParentWindow) : TcxDragImage(ParentWindow) { }
	
};


enum TcxDesignState : unsigned char { dsDesignerModifying };

typedef System::Set<TcxDesignState, TcxDesignState::dsDesignerModifying, TcxDesignState::dsDesignerModifying>  TcxDesignStates;

class DELPHICLASS TcxDesignController;
class PASCALIMPLEMENTATION TcxDesignController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FLockDesignerModifiedCount;
	
protected:
	TcxDesignStates FState;
	
public:
	void __fastcall DesignerModified(Vcl::Forms::TCustomForm* AForm)/* overload */;
	bool __fastcall IsDesignerModifiedLocked(void);
	void __fastcall LockDesignerModified(void);
	void __fastcall UnLockDesignerModified(void);
public:
	/* TObject.Create */ inline __fastcall TcxDesignController(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDesignController(void) { }
	
};


class DELPHICLASS TcxWindowProcLinkedObject;
class PASCALIMPLEMENTATION TcxWindowProcLinkedObject : public Dxcoreclasses::TcxDoublyLinkedObject
{
	typedef Dxcoreclasses::TcxDoublyLinkedObject inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	NativeUInt FHandle;
	System::Classes::TWndMethod FWindowProc;
	
protected:
	__property System::Classes::TWndMethod WindowProc = {read=FWindowProc, write=FWindowProc};
	
public:
	__fastcall TcxWindowProcLinkedObject(Vcl::Controls::TControl* AControl)/* overload */;
	__fastcall TcxWindowProcLinkedObject(NativeUInt AHandle)/* overload */;
	void __fastcall DefaultProc(Winapi::Messages::TMessage &Message);
	__property Vcl::Controls::TControl* Control = {read=FControl};
	__property NativeUInt Handle = {read=FHandle};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWindowProcLinkedObject(void) { }
	
};


class DELPHICLASS TcxSubclassingHelper;
class PASCALIMPLEMENTATION TcxSubclassingHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::Classes::TWndMethod FDefaultWindowProc;
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject(void) = 0 ;
	virtual void __fastcall RestoreDefaultProc(void) = 0 ;
	virtual void __fastcall StoreAndReplaceDefaultProc(System::Classes::TWndMethod AWndProc) = 0 ;
	__property System::Classes::TWndMethod DefaultWindowProc = {read=FDefaultWindowProc};
public:
	/* TObject.Create */ inline __fastcall TcxSubclassingHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSubclassingHelper(void) { }
	
};


class DELPHICLASS TcxVCLSubclassingHelper;
class PASCALIMPLEMENTATION TcxVCLSubclassingHelper : public TcxSubclassingHelper
{
	typedef TcxSubclassingHelper inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	
protected:
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject(void);
	virtual void __fastcall RestoreDefaultProc(void);
	virtual void __fastcall StoreAndReplaceDefaultProc(System::Classes::TWndMethod AWndProc);
	
public:
	__fastcall TcxVCLSubclassingHelper(Vcl::Controls::TControl* AControl);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVCLSubclassingHelper(void) { }
	
};


class DELPHICLASS TcxWin32SubclassingHelper;
class PASCALIMPLEMENTATION TcxWin32SubclassingHelper : public TcxSubclassingHelper
{
	typedef TcxSubclassingHelper inherited;
	
private:
	void *FAPIDefaultWndProc;
	void *FAPIWndProc;
	NativeUInt FHandle;
	
protected:
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject(void);
	void __fastcall DefaultWndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall RestoreDefaultProc(void);
	virtual void __fastcall StoreAndReplaceDefaultProc(System::Classes::TWndMethod AWndProc);
	
public:
	__fastcall TcxWin32SubclassingHelper(NativeUInt AHandle);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWin32SubclassingHelper(void) { }
	
};


class DELPHICLASS TcxWindowProcLinkedObjectList;
class PASCALIMPLEMENTATION TcxWindowProcLinkedObjectList : public Dxcoreclasses::TcxDoublyLinkedObjectList
{
	typedef Dxcoreclasses::TcxDoublyLinkedObjectList inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	NativeUInt FHandle;
	TcxSubclassingHelper* FHelper;
	
protected:
	TcxWindowProcLinkedObject* __fastcall AddProc(System::Classes::TWndMethod AWndProc);
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject(void);
	virtual void __fastcall Initialize(void);
	bool __fastcall IsEmpty(void);
	void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property Vcl::Controls::TControl* Control = {read=FControl};
	__property NativeUInt Handle = {read=FHandle};
	
public:
	__fastcall TcxWindowProcLinkedObjectList(Vcl::Controls::TControl* AControl)/* overload */;
	__fastcall TcxWindowProcLinkedObjectList(NativeUInt AHandle)/* overload */;
	__fastcall virtual ~TcxWindowProcLinkedObjectList(void);
};


class DELPHICLASS TcxWindowProcController;
class PASCALIMPLEMENTATION TcxWindowProcController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FWindowProcObjects;
	TcxWindowProcLinkedObjectList* __fastcall GetControlWindowProcObjects(Vcl::Controls::TControl* AControl)/* overload */;
	TcxWindowProcLinkedObjectList* __fastcall GetControlWindowProcObjects(NativeUInt AHandle)/* overload */;
	
public:
	__fastcall TcxWindowProcController(void);
	__fastcall virtual ~TcxWindowProcController(void);
	TcxWindowProcLinkedObject* __fastcall Add(Vcl::Controls::TControl* AControl, System::Classes::TWndMethod AWndProc)/* overload */;
	TcxWindowProcLinkedObject* __fastcall Add(NativeUInt AHandle, System::Classes::TWndMethod AWndProc)/* overload */;
	void __fastcall Remove(TcxWindowProcLinkedObject* &AWndProcObject);
};


__interface IcxLockedStatePaint;
typedef System::DelphiInterface<IcxLockedStatePaint> _di_IcxLockedStatePaint;
__interface  INTERFACE_UUID("{EB45AB76-3681-4838-BDA8-7D0081B4C184}") IcxLockedStatePaint  : public System::IInterface 
{
	
public:
	virtual Cxgraphics::TcxBitmap32* __fastcall GetImage(void) = 0 ;
	virtual TcxControl* __fastcall GetTopmostControl(void) = 0 ;
};

__interface IcxLockedStateFontChanged;
typedef System::DelphiInterface<IcxLockedStateFontChanged> _di_IcxLockedStateFontChanged;
__interface  INTERFACE_UUID("{825BFA90-77C6-4725-BE95-B0A1EA8F934D}") IcxLockedStateFontChanged  : public System::IInterface 
{
	
public:
	virtual void __fastcall FontChanged(Vcl::Graphics::TFont* AFont) = 0 ;
};

enum TcxLockedStateImageShowingMode : unsigned char { lsimNever, lsimPending, lsimImmediate };

enum TcxLockedStateImageEffect : unsigned char { lsieNone, lsieLight, lsieDark };

enum TcxLockedStateImageAssignedValue : unsigned char { lsiavFont, lsiavColor };

typedef System::Set<TcxLockedStateImageAssignedValue, TcxLockedStateImageAssignedValue::lsiavFont, TcxLockedStateImageAssignedValue::lsiavColor>  TcxLockedStateImageAssignedValues;

class DELPHICLASS TcxLockedStateImageOptions;
class PASCALIMPLEMENTATION TcxLockedStateImageOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxLockedStateImageAssignedValues FAssignedValues;
	bool FEnabled;
	System::Classes::TComponent* FOwner;
	bool FShowText;
	TcxLockedStateImageEffect FEffect;
	System::UnicodeString FText;
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FFont;
	void __fastcall FontChanged(System::TObject* Sender);
	bool __fastcall IsFontStored(void);
	void __fastcall SetColor(const System::Uitypes::TColor Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* const Value);
	void __fastcall SetAssignedValues(const TcxLockedStateImageAssignedValues Value);
	
protected:
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void) = 0 ;
	virtual bool __fastcall IsTextStored(void);
	__property System::Classes::TComponent* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxLockedStateImageOptions(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxLockedStateImageOptions(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall UpdateFont(Vcl::Graphics::TFont* AFont);
	
__published:
	__property TcxLockedStateImageAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870911};
	__property TcxLockedStateImageEffect Effect = {read=FEffect, write=FEffect, default=0};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property bool ShowText = {read=FShowText, write=FShowText, default=0};
	__property System::UnicodeString Text = {read=FText, write=FText, stored=IsTextStored};
};


class DELPHICLASS TcxLockedStatePaintHelper;
class PASCALIMPLEMENTATION TcxLockedStatePaintHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxBitmap32* FBitmap;
	int FCount;
	bool FCreatingImage;
	bool FIsImageReady;
	System::Classes::TComponent* FOwner;
	System::Uitypes::TColor __fastcall GetColor(void);
	TcxLockedStateImageEffect __fastcall GetEffect(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	System::UnicodeString __fastcall GetText(void);
	
protected:
	void __fastcall CreateImage(void);
	void __fastcall DrawText(void);
	virtual void __fastcall PrepareImage(void);
	void __fastcall ValidateImage(void);
	virtual bool __fastcall CanCreateLockedImage(void);
	virtual bool __fastcall CanControlPaint(void);
	virtual bool __fastcall DoPrepareImage(void);
	virtual TcxLockedStateImageOptions* __fastcall GetOptions(void) = 0 ;
	virtual TcxControl* __fastcall GetControl(void) = 0 ;
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	__property Cxgraphics::TcxBitmap32* Bitmap = {read=FBitmap};
	__property System::Uitypes::TColor Color = {read=GetColor, nodefault};
	__property TcxControl* Control = {read=GetControl};
	__property bool CreatingImage = {read=FCreatingImage, nodefault};
	__property TcxLockedStateImageEffect Effect = {read=GetEffect, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property bool IsImageReady = {read=FIsImageReady, nodefault};
	__property TcxLockedStateImageOptions* Options = {read=GetOptions};
	__property System::Classes::TComponent* Owner = {read=FOwner};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property System::UnicodeString Text = {read=GetText};
	
public:
	__fastcall virtual TcxLockedStatePaintHelper(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxLockedStatePaintHelper(void);
	void __fastcall BeginLockedPaint(TcxLockedStateImageShowingMode AMode);
	void __fastcall EndLockedPaint(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetActiveCanvas(void);
	Cxgraphics::TcxBitmap32* __fastcall GetImage(void);
	bool __fastcall IsActive(void);
};


enum TdxSetOperation : unsigned char { soSet, soAdd, soSubtract };

enum TdxWindowStyleIndex : unsigned char { wsiStyle, wsiExStyle };

typedef Vcl::Forms::TCustomForm* __fastcall (*TcxGetParentFormForDockingFunc)(Vcl::Controls::TControl* AControl);

typedef HWND __fastcall (*TcxGetParentWndForDockingFunc)(HWND AWnd);

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxDesignSelectorIndentFromBorder = System::Int8(0x8);
static const System::Int8 cxDesignSelectorSize = System::Int8(0xf);
static const System::Word cxInvisibleCoordinate = System::Word(0x7530);
extern PACKAGE System::Byte cxDragAndDropWindowTransparency;
extern PACKAGE TcxGetParentFormForDockingFunc cxGetParentFormForDocking;
extern PACKAGE TcxGetParentWndForDockingFunc cxGetParentWndForDocking;
extern PACKAGE _di_IdxSpellChecker dxISpellChecker;
extern PACKAGE _di_IdxSpellChecker2 dxISpellChecker2;
extern PACKAGE void __fastcall cxSetLayeredWindowAttributes(HWND AHandle, int AAlphaBlendValue);
extern PACKAGE TcxWindowProcController* __fastcall cxWindowProcController(void);
extern PACKAGE bool __fastcall dxIsWindowStyleSet(NativeUInt AHandle, unsigned AStyle);
extern PACKAGE void * __fastcall dxSetWindowProc(NativeUInt AHandle, void * ANewWindowProc);
extern PACKAGE NativeInt __fastcall dxSetWindowStyle(NativeUInt AHandle, NativeInt ANewStyle, TdxSetOperation AOperation = (TdxSetOperation)(0x0), TdxWindowStyleIndex AStyleIndex = (TdxWindowStyleIndex)(0x0));
extern PACKAGE TdxSystemInfo* __fastcall dxSystemInfo(void);
extern PACKAGE void __fastcall dxDrawTextOnGlass(HDC DC, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor, unsigned AFlags, int AGlowingSize, bool ATransparent);
extern PACKAGE void __fastcall dxDrawWindowOnGlass(NativeUInt AWnd, NativeUInt ADC, const System::Types::TRect &ABounds, bool APaintBlackOpaque = false)/* overload */;
extern PACKAGE void __fastcall dxDrawWindowOnGlass(NativeUInt AWnd, bool APaintBlackOpaque = false)/* overload */;
extern PACKAGE void __fastcall dxPaintWindowOnGlass(NativeUInt AWnd, bool APaintBlackOpaque = false);
extern PACKAGE void __fastcall dxBufferedPaintControl(Vcl::Controls::TWinControl* AControl);
extern PACKAGE bool __fastcall dxIsPaintOnGlass(Vcl::Controls::TWinControl* AControl);
extern PACKAGE void __fastcall dxForceProcessBufferedPaintMessages(Vcl::Controls::TWinControl* AControl);
extern PACKAGE bool __fastcall CanAllocateHandle(Vcl::Controls::TWinControl* AControl);
extern PACKAGE bool __fastcall cxIsDrawToMemory(const Winapi::Messages::TWMEraseBkgnd &AMessage);
extern PACKAGE TcxMessageWindow* __fastcall cxMessageWindow(void);
extern PACKAGE TdxMessagesController* __fastcall dxMessagesController(void);
extern PACKAGE bool __fastcall cxIsVCLThemesAvailable(void);
extern PACKAGE bool __fastcall cxIsVCLThemesEnabled(void);
extern PACKAGE Vcl::Themes::TCustomStyleServices* __fastcall cxStyleServices(void);
extern PACKAGE TcxDragDetect __fastcall cxDragDetect(HWND Wnd, const System::Types::TPoint AStartPoint);
extern PACKAGE System::WideChar __fastcall GetCharFromKeyCode(System::Word ACode);
extern PACKAGE NativeUInt __fastcall GetMouseKeys(void);
extern PACKAGE int __fastcall GetDblClickInterval(void);
extern PACKAGE System::Types::TRect __fastcall GetDesktopWorkArea(const System::Types::TPoint P);
extern PACKAGE System::Types::TRect __fastcall GetMonitorWorkArea(const int AMonitor);
extern PACKAGE System::Types::TPoint __fastcall GetMouseCursorPos(void);
extern PACKAGE Cxclasses::TcxPosition __fastcall GetPointPosition(const System::Types::TRect &ARect, const System::Types::TPoint P, bool AHorzSeparation, bool AVertSeparation);
extern PACKAGE bool __fastcall cxShiftStateMoveOnly(const System::Classes::TShiftState AShift);
extern PACKAGE bool __fastcall cxShiftStateLeftOnly(System::Classes::TShiftState AShift, bool ACanIncludeDoubleClick = false);
extern PACKAGE bool __fastcall IsChildClassWindow(HWND AWnd);
extern PACKAGE bool __fastcall IsChildEx(HWND AParentWnd, HWND AWnd);
extern PACKAGE bool __fastcall IsMDIChild(Vcl::Forms::TCustomForm* AForm);
extern PACKAGE bool __fastcall IsMDIForm(Vcl::Forms::TCustomForm* AForm);
extern PACKAGE bool __fastcall IsCtrlPressed(void);
extern PACKAGE bool __fastcall IsEditStartChar(System::WideChar C);
extern PACKAGE bool __fastcall IsIncSearchStartChar(System::WideChar C);
extern PACKAGE bool __fastcall IsOwner(HWND AOwnerWnd, HWND AWnd);
extern PACKAGE bool __fastcall IsOwnerEx(HWND AOwnerWnd, HWND AWnd);
extern PACKAGE bool __fastcall IsWindowEnabledEx(HWND AWindowHandle);
extern PACKAGE bool __fastcall IsControlVisible(Vcl::Controls::TWinControl* AControl);
extern PACKAGE Vcl::Controls::TWinControl* __fastcall cxFindVCLControl(HWND AWnd);
extern PACKAGE System::Classes::TComponent* __fastcall cxFindComponent(System::Classes::TComponent* AParentComponent, System::TClass AClass);
extern PACKAGE System::Types::TPoint __fastcall cxClientToParent(Vcl::Controls::TControl* AControl, const System::Types::TPoint P, Vcl::Controls::TWinControl* AParent);
extern PACKAGE System::Types::TPoint __fastcall cxParentToClient(Vcl::Controls::TControl* AControl, const System::Types::TPoint P, Vcl::Controls::TWinControl* AParent);
extern PACKAGE Vcl::Controls::TWinControl* __fastcall dxFindParentControl(NativeUInt AHandle);
extern PACKAGE Vcl::Forms::TCustomForm* __fastcall dxGetParentForm(NativeUInt AHandle);
extern PACKAGE void __fastcall dxPerformMessageByQueue(Vcl::Controls::TControl* AControl, unsigned AMessage);
extern PACKAGE bool __fastcall IsPointInDragDetectArea(const System::Types::TPoint AMouseDownPos, int X, int Y);
extern PACKAGE bool __fastcall IsNumericChar(System::WideChar C, TcxNumberType AType);
extern PACKAGE bool __fastcall IsSysKey(System::Word AKey);
extern PACKAGE bool __fastcall IsTextChar(System::WideChar C);
extern PACKAGE void __fastcall MakeVisibleOnDesktop(System::Types::TRect &ABounds, const System::Types::TPoint ADesktopPoint)/* overload */;
extern PACKAGE void __fastcall MakeVisibleOnDesktop(Vcl::Controls::TControl* AControl)/* overload */;
extern PACKAGE System::Types::TPoint __fastcall dxMapWindowPoint(HWND AHandleFrom, HWND AHandleTo, const System::Types::TPoint P, bool AClient = true);
extern PACKAGE System::Types::TRect __fastcall dxMapWindowRect(HWND AHandleFrom, HWND AHandleTo, const System::Types::TRect &R, bool AClient = true);
extern PACKAGE void __fastcall cxRecreateControlWnd(Vcl::Controls::TWinControl* AControl, bool APostponed = false);
extern PACKAGE System::Types::TPoint __fastcall cxClientToScreen(NativeUInt AHandle, const System::Types::TPoint APoint);
extern PACKAGE System::Types::TRect __fastcall cxGetClientRect(NativeUInt AHandle)/* overload */;
extern PACKAGE System::Types::TPoint __fastcall cxGetClientOffset(NativeUInt AHandle);
extern PACKAGE System::Types::TRect __fastcall cxGetClientRect(Vcl::Controls::TWinControl* AControl)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxGetWindowRect(NativeUInt AHandle)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxGetWindowText(NativeUInt AHandle);
extern PACKAGE System::Types::TRect __fastcall cxGetWindowRect(Vcl::Controls::TWinControl* AControl)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxGetWindowBounds(Vcl::Controls::TWinControl* AControl)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxGetWindowBounds(NativeUInt AHandle)/* overload */;
extern PACKAGE HWND __fastcall cxWindowFromPoint(System::Types::TPoint P);
extern PACKAGE void __fastcall dxSetZOrder(NativeUInt AHandle, NativeUInt AWndAfter = (NativeUInt)(0xffffffffffffffffULL), bool AActivate = false, unsigned AFlags = (unsigned)(0x0));
extern PACKAGE NativeUInt __fastcall cxLoadSysMenu(TcxSystemMenuType AMenuType);
extern PACKAGE void __fastcall cxModifySystemMenu(NativeUInt ASysMenu, NativeUInt AWindowHandle, bool AIsDialog, System::Uitypes::TBorderIcons ABorderIcons, System::Uitypes::TWindowState AWindowState, bool ALockRepaint = true);
extern PACKAGE void __fastcall cxMoveMenuItems(NativeUInt ASource, NativeUInt ADest);
extern PACKAGE System::AnsiString __fastcall RemoveAccelChars(const System::AnsiString S, bool AAppendTerminatingUnderscore = true)/* overload */;
extern PACKAGE System::WideString __fastcall RemoveAccelChars(const System::WideString S, bool AAppendTerminatingUnderscore = true)/* overload */;
extern PACKAGE void __fastcall SetDesignerModified(System::Classes::TComponent* AComponent);
extern PACKAGE System::UnicodeString __fastcall cxGetFullComponentName(System::Classes::TComponent* AComponent);
extern PACKAGE void __fastcall cxReleaseForm(void *AForm);
extern PACKAGE System::Word __fastcall ShiftStateToKeys(System::Classes::TShiftState AShift);
extern PACKAGE System::Word __fastcall TranslateKey(System::Word Key);
extern PACKAGE void __fastcall BeginMouseTracking(Vcl::Controls::TWinControl* AControl, const System::Types::TRect &ABounds, _di_IcxMouseTrackingCaller ACaller);
extern PACKAGE void __fastcall EndMouseTracking(_di_IcxMouseTrackingCaller ACaller);
extern PACKAGE bool __fastcall IsMouseTracking(_di_IcxMouseTrackingCaller ACaller);
extern PACKAGE void __fastcall HideHourglassCursor(void);
extern PACKAGE void __fastcall ShowHourglassCursor(void);
extern PACKAGE int __fastcall GetPopupMenuHeight(Vcl::Menus::TPopupMenu* APopupMenu);
extern PACKAGE bool __fastcall IsPopupMenu(System::Classes::TComponent* APopupMenu);
extern PACKAGE bool __fastcall IsPopupMenuShortCut(System::Classes::TComponent* APopupMenu, Winapi::Messages::TWMKey &Message);
extern PACKAGE bool __fastcall ShowPopupMenu(System::Classes::TComponent* ACaller, System::Classes::TComponent* APopupMenu, const System::Types::TPoint P)/* overload */;
extern PACKAGE bool __fastcall ShowPopupMenu(System::Classes::TComponent* ACaller, System::Classes::TComponent* APopupMenu, int X, int Y)/* overload */;
extern PACKAGE bool __fastcall ShowPopupMenu(System::Classes::TComponent* ACaller, System::Classes::TComponent* APopupMenu, const System::Types::TRect &AOwnerBounds, Vcl::Menus::TPopupAlignment APopupAlignment)/* overload */;
extern PACKAGE bool __fastcall ShowPopupMenuFromCursorPos(System::Classes::TComponent* ACaller, System::Classes::TComponent* AComponent);
extern PACKAGE System::TObject* __fastcall cxExtractDragObjectSource(System::TObject* ADragObject);
extern PACKAGE Vcl::Controls::TDragObject* __fastcall GetDragObject(void);
extern PACKAGE System::Types::TRect __fastcall GetDragAndDropArrowBounds(const System::Types::TRect &AAreaBounds, const System::Types::TRect &AClientRect, TcxArrowPlace APlace);
extern PACKAGE void __fastcall GetDragAndDropArrowPoints(const System::Types::TRect &ABounds, TcxArrowPlace APlace, /* out */ Cxgraphics::TPointArray &P, bool AForRegion);
extern PACKAGE void __fastcall DrawDragAndDropArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxArrowPlace APlace);
extern PACKAGE void __fastcall DialogApplyFont(Vcl::Forms::TCustomForm* ADialog, Vcl::Graphics::TFont* AFont);
extern PACKAGE TcxDesignController* __fastcall DesignController(void);
}	/* namespace Cxcontrols */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCONTROLS)
using namespace Cxcontrols;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcontrolsHPP
