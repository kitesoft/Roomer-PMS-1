// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSCtrls.pas' rev: 24.00 (Win64)

#ifndef CxssctrlsHPP
#define CxssctrlsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxSSColorBox.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPaintPanel;
typedef void __fastcall (__closure *TcxPaintEvent)(TcxPaintPanel* Sender);

class DELPHICLASS TcxLabelBevel;
class PASCALIMPLEMENTATION TcxLabelBevel : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	System::WideString FCaptionText;
	void __fastcall SetCaption(const System::WideString Value);
	void __fastcall SetComponentCaption(const Vcl::Controls::TCaption Value);
	
protected:
	virtual void __fastcall Paint(void);
	__property Caption = {write=SetComponentCaption, default=0};
	
__published:
	__property System::WideString CaptionText = {read=FCaptionText, write=SetCaption};
	__property Font;
public:
	/* TCustomControl.Create */ inline __fastcall virtual TcxLabelBevel(System::Classes::TComponent* AOwner) : Vcl::Controls::TCustomControl(AOwner) { }
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TcxLabelBevel(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxLabelBevel(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxPaintPanel : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	TcxPaintEvent FOnPaint;
	
protected:
	virtual void __fastcall Paint(void);
	
public:
	__property Canvas;
	
__published:
	__fastcall virtual TcxPaintPanel(System::Classes::TComponent* AOwner);
	void __fastcall InvalidateRect(const System::Types::TRect &ARect, bool EraseBackground);
	__property TcxPaintEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property Align = {default=0};
	__property Font;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TcxPaintPanel(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPaintPanel(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TcxSSStyleListBoxItem
{
public:
	System::UnicodeString Value;
	System::Uitypes::TColor Color;
	int ValueType;
};


typedef void __fastcall (__closure *TcxStyleChangeEvent)(System::TObject* Sender, int StyleValue);

class DELPHICLASS TcxSSStyleListBox;
class PASCALIMPLEMENTATION TcxSSStyleListBox : public Vcl::Stdctrls::TListBox
{
	typedef Vcl::Stdctrls::TListBox inherited;
	
private:
	typedef System::DynamicArray<TcxSSStyleListBoxItem> _TcxSSStyleListBox__1;
	
	
private:
	int FIndex;
	_TcxSSStyleListBox__1 FItems;
	TcxStyleChangeEvent FOnStyleChanged;
	void __fastcall SetItemIdx(int AIndex);
	
protected:
	virtual void __fastcall OnChange(System::TObject* Sender);
	void __fastcall OnDrawStyleItem(Vcl::Controls::TWinControl* Control, int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	
public:
	__fastcall virtual TcxSSStyleListBox(System::Classes::TComponent* AOwner);
	void __fastcall AssignItems(TcxSSStyleListBoxItem const *AItems, const int AItems_Size);
	__property TcxStyleChangeEvent OnStyleChanged = {read=FOnStyleChanged, write=FOnStyleChanged};
	__property ItemIndex = {write=SetItemIdx};
public:
	/* TCustomListBox.Destroy */ inline __fastcall virtual ~TcxSSStyleListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSSStyleListBox(HWND ParentWindow) : Vcl::Stdctrls::TListBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall SetCaptions(Vcl::Controls::TControl* const *AControls, const int AControls_Size, System::UnicodeString const *ACaptions, const int ACaptions_Size);
extern PACKAGE void __fastcall SetItems(Vcl::Stdctrls::TComboBox* AControl, System::UnicodeString const *AStringItems, const int AStringItems_Size);
}	/* namespace Cxssctrls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSCTRLS)
using namespace Cxssctrls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssctrlsHPP
