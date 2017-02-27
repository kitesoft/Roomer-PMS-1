// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSEditors.pas' rev: 24.00 (Win64)

#ifndef CxsseditorsHPP
#define CxsseditorsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxsseditors
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxSSInplaceEditClass;

class DELPHICLASS TcxSSInplaceTextEdit;
class PASCALIMPLEMENTATION TcxSSInplaceTextEdit : public Vcl::Stdctrls::TCustomMemo
{
	typedef Vcl::Stdctrls::TCustomMemo inherited;
	
private:
	bool FAutoWidth;
	bool FError;
	bool FIsInit;
	bool FIsCellEditor;
	bool FIsUpdate;
	int FMinimalWidth;
	int FMinimalHeight;
	System::Classes::TNotifyEvent FOnEndEdit;
	System::UnicodeString FValidText;
	bool FWantTab;
	System::UnicodeString __fastcall GetDisplayText(void);
	void __fastcall SetDisplayText(System::UnicodeString AText);
	void __fastcall SetMinimalHeight(const int Value);
	void __fastcall SetMinimalWidth(const int Value);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	
protected:
	DYNAMIC void __fastcall Change(void);
	int __fastcall CaretPosToSelStart(const System::Types::TPoint APos);
	virtual void __fastcall DoAutoSize(void);
	virtual void __fastcall DoEndEdit(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall DoLineBreak(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	System::Types::TSize __fastcall TextExtents(Vcl::Graphics::TFont* AFont, System::Classes::TStrings* const Text);
	
public:
	__fastcall TcxSSInplaceTextEdit(System::Classes::TComponent* AOwner, bool IsCellEditor)/* overload */;
	System::Types::TPoint __fastcall GetEditPos(const int XPos, const int YPos);
	void __fastcall InitEditor(const System::UnicodeString AValidText, const System::UnicodeString AText);
	virtual void __fastcall SetCursorPosition(const System::Types::TPoint APos);
	__property bool AutoWidth = {read=FAutoWidth, write=FAutoWidth, nodefault};
	__property System::UnicodeString DisplayText = {read=GetDisplayText, write=SetDisplayText};
	__property bool Error = {read=FError, write=FError, nodefault};
	__property int MinimalWidth = {read=FMinimalWidth, write=SetMinimalWidth, nodefault};
	__property int MinimalHeight = {read=FMinimalHeight, write=SetMinimalHeight, nodefault};
	__property bool WantTab = {read=FWantTab, write=FWantTab, nodefault};
	__property Color = {default=-16777211};
	__property Font;
	__property System::Classes::TNotifyEvent OnEndEdit = {read=FOnEndEdit, write=FOnEndEdit};
	__property OnChange;
public:
	/* TCustomMemo.Destroy */ inline __fastcall virtual ~TcxSSInplaceTextEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSSInplaceTextEdit(HWND ParentWindow) : Vcl::Stdctrls::TCustomMemo(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxsseditors */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSEDITORS)
using namespace Cxsseditors;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxsseditorsHPP
