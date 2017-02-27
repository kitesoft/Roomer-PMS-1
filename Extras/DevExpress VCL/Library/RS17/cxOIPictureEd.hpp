// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxOIPictureEd.pas' rev: 24.00 (Win32)

#ifndef CxoipictureedHPP
#define CxoipictureedHPP

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
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxoipictureed
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxfmPictureEditor;
class PASCALIMPLEMENTATION TcxfmPictureEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnLoad;
	Cxbuttons::TcxButton* btnSave;
	Cxbuttons::TcxButton* btnCopy;
	Cxbuttons::TcxButton* btnPaste;
	Cxbuttons::TcxButton* btnClear;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnOk;
	Cximage::TcxImage* Image;
	Vcl::Extctrls::TBevel* Bevel1;
	Vcl::Extctrls::TPanel* Panel1;
	void __fastcall btnLoadClick(System::TObject* Sender);
	void __fastcall btnSaveClick(System::TObject* Sender);
	void __fastcall btnClearClick(System::TObject* Sender);
	void __fastcall btnCopyClick(System::TObject* Sender);
	void __fastcall btnPasteClick(System::TObject* Sender);
	void __fastcall FormPaint(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	
private:
	System::Types::TRect FSizeGripBounds;
	bool FChained;
	HWND FNextWindow;
	System::UnicodeString FGraphicFilter;
	System::UnicodeString __fastcall GetSaveGraphicFilter(void);
	void __fastcall ForwardMessage(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMChangeCBChain(Winapi::Messages::TWMChangeCBChain &Message);
	MESSAGE void __fastcall WMDrawClipboard(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWindowHandle(void);
	bool __fastcall HasPicture(void);
	void __fastcall UpdateButtons(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxfmPictureEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxfmPictureEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxfmPictureEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxfmPictureEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


struct TcxPictureEditorDlgData;
typedef TcxPictureEditorDlgData *PcxPictureEditorDlgData;

struct DECLSPEC_DRECORD TcxPictureEditorDlgData
{
public:
	System::UnicodeString Caption;
	System::Word ClipboardFormat;
	System::UnicodeString GraphicFilter;
	Cxlookandfeels::TcxLookAndFeel* LookAndFeel;
	Vcl::Graphics::TPicture* Picture;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall cxShowPictureEditor(const PcxPictureEditorDlgData AData);
}	/* namespace Cxoipictureed */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXOIPICTUREED)
using namespace Cxoipictureed;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxoipictureedHPP
