// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxfmDfnStl.pas' rev: 24.00 (Win64)

#ifndef DxfmdfnstlHPP
#define DxfmdfnstlHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfmdfnstl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmDefinePrintStyles;
class PASCALIMPLEMENTATION TdxfmDefinePrintStyles : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
private:
	typedef System::StaticArray<System::UnicodeString, 2> _TdxfmDefinePrintStyles__1;
	
	typedef System::StaticArray<System::UnicodeString, 2> _TdxfmDefinePrintStyles__2;
	
	
__published:
	Cxbuttons::TcxButton* btnClose;
	Cxbuttons::TcxButton* btnCopy;
	Cxbuttons::TcxButton* btnEdit;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnReset;
	Cxgraphics::TcxImageList* ilPrintStyles;
	Vcl::Stdctrls::TLabel* lblPrintStyles;
	Cxlistbox::TcxListBox* lbxPrintStyles;
	Vcl::Menus::TMenuItem* miClear;
	Vcl::Menus::TMenuItem* miCopy;
	Vcl::Menus::TMenuItem* miEdit;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Menus::TMenuItem* miReset;
	Vcl::Menus::TPopupMenu* pmPrintStyles;
	void __fastcall ClearClick(System::TObject* Sender);
	void __fastcall CopyClick(System::TObject* Sender);
	void __fastcall EditClick(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall lbxPrintStylesClick(System::TObject* Sender);
	void __fastcall pmPrintStylesPopup(System::TObject* Sender);
	void __fastcall ResetClick(System::TObject* Sender);
	void __fastcall lbxPrintStylesDrawItem(Cxlistbox::TcxListBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	
private:
	unsigned FPrevClassStyle;
	System::Classes::TWndMethod FPrevWindowProc;
	Dxpsesys::TdxEventSubscriber* FSubscriber;
	_TdxfmDefinePrintStyles__1 FBtnDelCaptions;
	_TdxfmDefinePrintStyles__2 FBtnCopyCaptions;
	bool FPreviewBtnClicked;
	bool FPrintBtnClicked;
	Dxpgsdlg::TdxPrintStyleManager* FStyleManager;
	void __fastcall SetStyleManager(Dxpgsdlg::TdxPrintStyleManager* Value);
	void __fastcall AddPrintStyle(int AClonedIndex);
	void __fastcall FillRestSpace(HDC DC);
	void __fastcall Initialize(void);
	void __fastcall LoadStrings(void);
	void __fastcall RefreshStyleList(void);
	void __fastcall StyleListChanged(System::TObject* Sender);
	void __fastcall UpdateControlsState(void);
	void __fastcall ListBoxWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall RestoreWndProc(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall SubstWindowProc(Vcl::Stdctrls::TListBox* AListBox);
	
protected:
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall BeforeConstruction(void);
	
public:
	__fastcall virtual TdxfmDefinePrintStyles(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmDefinePrintStyles(void);
	bool __fastcall Execute(void);
	__property bool PreviewBtnClicked = {read=FPreviewBtnClicked, nodefault};
	__property bool PrintBtnClicked = {read=FPrintBtnClicked, nodefault};
	__property Dxpgsdlg::TdxPrintStyleManager* StyleManager = {read=FStyleManager, write=SetStyleManager};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmDefinePrintStyles(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmDefinePrintStyles(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxDefinePrintStylesDlg(Dxpgsdlg::TdxPrintStyleManager* AStyleManager, const System::UnicodeString ATitle, bool &APreviewBtnClicked, bool &APrintBtnClicked);
}	/* namespace Dxfmdfnstl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFMDFNSTL)
using namespace Dxfmdfnstl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfmdfnstlHPP
