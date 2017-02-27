// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxScrollBox.pas' rev: 24.00 (Win64)

#ifndef CxscrollboxHPP
#define CxscrollboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxscrollbox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxScrollBoxScrollBarOptions;
class DELPHICLASS TcxCustomScrollBox;
class PASCALIMPLEMENTATION TcxScrollBoxScrollBarOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Vcl::Forms::TScrollBarInc FIncrement;
	System::Word FMargin;
	Vcl::Forms::TScrollBarKind FKind;
	int FPosition;
	int FRange;
	TcxCustomScrollBox* FScrollBox;
	bool FTracking;
	bool FVisible;
	bool __fastcall GetAutoScroll(void);
	int __fastcall GetPageSize(void);
	bool __fastcall IsRangeStored(void);
	void __fastcall CheckPosition(int &APosition);
	void __fastcall SetIncrement(Vcl::Forms::TScrollBarInc Value);
	void __fastcall SetMargin(System::Word Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetRange(int Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall UpdateRange(int ARange);
	
protected:
	void __fastcall AdjustAutoRange(Vcl::Controls::TControl* AControl, int &ARange, int &AAlignMargin);
	void __fastcall CalculateAutoRange(void);
	void __fastcall Changed(void);
	int __fastcall GetMaxPosition(void);
	void __fastcall Scroll(System::Uitypes::TScrollCode ACode, int &APosition);
	virtual bool __fastcall IsVisible(void);
	__property bool AutoScroll = {read=GetAutoScroll, nodefault};
	__property int PageSize = {read=GetPageSize, nodefault};
	__property TcxCustomScrollBox* ScrollBox = {read=FScrollBox};
	
public:
	__fastcall virtual TcxScrollBoxScrollBarOptions(TcxCustomScrollBox* AScrollBox, Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Vcl::Forms::TScrollBarKind Kind = {read=FKind, nodefault};
	
__published:
	__property Vcl::Forms::TScrollBarInc Increment = {read=FIncrement, write=SetIncrement, default=8};
	__property System::Word Margin = {read=FMargin, write=SetMargin, default=0};
	__property int Position = {read=FPosition, write=SetPosition, default=0};
	__property int Range = {read=FRange, write=SetRange, stored=IsRangeStored, nodefault};
	__property bool Tracking = {read=FTracking, write=FTracking, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxScrollBoxScrollBarOptions(void) { }
	
};


typedef System::TMetaClass* TcxScrollBoxScrollBarOptionsClass;

class DELPHICLASS TcxCustomScrollBoxViewInfo;
class PASCALIMPLEMENTATION TcxCustomScrollBoxViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FClientRect;
	TcxCustomScrollBox* FScrollBox;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
public:
	__fastcall virtual TcxCustomScrollBoxViewInfo(TcxCustomScrollBox* AScrollBox);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateClientRect(const System::Types::TRect &ABounds);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TRect ClientRect = {read=FClientRect};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxCustomScrollBox* ScrollBox = {read=FScrollBox};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomScrollBoxViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxCustomScrollBoxViewInfoClass;

class DELPHICLASS TcxControlNCScrollBars;
class PASCALIMPLEMENTATION TcxControlNCScrollBars : public Cxcontrols::TcxControlScrollBars
{
	typedef Cxcontrols::TcxControlScrollBars inherited;
	
protected:
	virtual System::TObject* __fastcall CreateScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual System::TObject* __fastcall CreateSizeGrip(void);
public:
	/* TcxControlCustomScrollBars.Create */ inline __fastcall virtual TcxControlNCScrollBars(Cxcontrols::TcxControl* AOwner) : Cxcontrols::TcxControlScrollBars(AOwner) { }
	/* TcxControlCustomScrollBars.Destroy */ inline __fastcall virtual ~TcxControlNCScrollBars(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomScrollBox : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	bool FAutoScroll;
	TcxCustomScrollBoxViewInfo* FViewInfo;
	TcxScrollBoxScrollBarOptions* FHorzScrollBar;
	TcxScrollBoxScrollBarOptions* FVertScrollBar;
	bool FIsScrollBarsUpdating;
	bool FTransparent;
	void __fastcall CalculateAutoRange(void);
	void __fastcall SetAutoScroll(bool Value);
	void __fastcall SetHorzScrollBar(TcxScrollBoxScrollBarOptions* Value);
	void __fastcall SetTransparent(const bool Value);
	void __fastcall SetVertScrollBar(TcxScrollBoxScrollBarOptions* Value);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFocusChanged(Vcl::Controls::TCMFocusChanged &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual TcxScrollBoxScrollBarOptions* __fastcall CreateScrollBarOptions(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall DoUpdateScrollBars(void);
	virtual void __fastcall EraseBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual System::Types::TRect __fastcall GetClientOffsets(void);
	virtual Cxcontrols::TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass(void);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual bool __fastcall HasNonClientArea(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall IsTransparentBackground(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall PaintNonClientArea(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall AdvancedScrollBy(int ADeltaX, int ADeltaY);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall DoWndProc(Winapi::Messages::TMessage &Message);
	virtual TcxCustomScrollBoxViewInfoClass __fastcall GetViewInfoClass(void);
	void __fastcall RefreshNonClientArea(void);
	__property BorderStyle = {default=1};
	__property TabStop = {default=0};
	__property TcxCustomScrollBoxViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxCustomScrollBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomScrollBox(void);
	void __fastcall MakeVisible(Vcl::Controls::TWinControl* AControl);
	__property bool AutoScroll = {read=FAutoScroll, write=SetAutoScroll, default=1};
	__property TcxScrollBoxScrollBarOptions* HorzScrollBar = {read=FHorzScrollBar, write=SetHorzScrollBar};
	__property LookAndFeel;
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property TcxScrollBoxScrollBarOptions* VertScrollBar = {read=FVertScrollBar, write=SetVertScrollBar};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomScrollBox(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	inline void __fastcall  EraseBackground(HDC DC){ Cxcontrols::TcxControl::EraseBackground(DC); }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
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
	
};


class DELPHICLASS TcxScrollBox;
class PASCALIMPLEMENTATION TcxScrollBox : public TcxCustomScrollBox
{
	typedef TcxCustomScrollBox inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoScroll = {default=1};
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property Cursor = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property HelpType = {default=1};
	__property HorzScrollBar;
	__property LookAndFeel;
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Transparent = {default=0};
	__property VertScrollBar;
	__property Visible = {default=1};
	__property OnCanResize;
	__property OnClick;
	__property OnConstrainedResize;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnEnter;
	__property OnExit;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnResize;
public:
	/* TcxCustomScrollBox.Create */ inline __fastcall virtual TcxScrollBox(System::Classes::TComponent* AOwner) : TcxCustomScrollBox(AOwner) { }
	/* TcxCustomScrollBox.Destroy */ inline __fastcall virtual ~TcxScrollBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxScrollBox(HWND ParentWindow) : TcxCustomScrollBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxscrollbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCROLLBOX)
using namespace Cxscrollbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxscrollboxHPP
