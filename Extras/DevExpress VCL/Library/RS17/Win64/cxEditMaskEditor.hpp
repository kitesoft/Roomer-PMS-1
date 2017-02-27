// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditMaskEditor.pas' rev: 24.00 (Win64)

#ifndef CxeditmaskeditorHPP
#define CxeditmaskeditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxStandardMask.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditmaskeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxLoadMaskException;
class PASCALIMPLEMENTATION EcxLoadMaskException : public Cxedit::EcxEditError
{
	typedef Cxedit::EcxEditError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxLoadMaskException(const System::UnicodeString Msg) : Cxedit::EcxEditError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxLoadMaskException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Cxedit::EcxEditError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxLoadMaskException(NativeUInt Ident)/* overload */ : Cxedit::EcxEditError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxLoadMaskException(System::PResStringRec ResStringRec)/* overload */ : Cxedit::EcxEditError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxLoadMaskException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Cxedit::EcxEditError(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxLoadMaskException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Cxedit::EcxEditError(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxLoadMaskException(const System::UnicodeString Msg, int AHelpContext) : Cxedit::EcxEditError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxLoadMaskException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Cxedit::EcxEditError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxLoadMaskException(NativeUInt Ident, int AHelpContext)/* overload */ : Cxedit::EcxEditError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxLoadMaskException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Cxedit::EcxEditError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxLoadMaskException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Cxedit::EcxEditError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxLoadMaskException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Cxedit::EcxEditError(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxLoadMaskException(void) { }
	
};


struct DECLSPEC_DRECORD TcxSample
{
public:
	System::UnicodeString ShortDescription;
	System::UnicodeString Description;
	System::UnicodeString Mask;
};


typedef System::DynamicArray<TcxSample> TcxSamples;

typedef System::StaticArray<TcxSample, 20> Cxeditmaskeditor__2;

typedef System::StaticArray<TcxSample, 8> Cxeditmaskeditor__3;

class DELPHICLASS TcxEditMaskEditorDlg;
class PASCALIMPLEMENTATION TcxEditMaskEditorDlg : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxdropdownedit::TcxComboBox* cxMaskKindPickEdit1;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Extctrls::TPanel* StandardMaskPanel;
	Vcl::Extctrls::TPanel* RegExprMaskPanel;
	Cxtextedit::TcxTextEdit* cxEditMaskEdit;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TLabel* Label3;
	Cxmaskedit::TcxMaskEdit* cxMaskEdit1;
	Vcl::Extctrls::TBevel* Bevel1;
	Vcl::Stdctrls::TLabel* Label4;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Extctrls::TBevel* Bevel2;
	Cxtextedit::TcxTextEdit* cxTextEdit1;
	Cxmaskedit::TcxMaskEdit* cxMaskEdit2;
	Vcl::Extctrls::TBevel* Bevel3;
	Vcl::Stdctrls::TLabel* Label6;
	Vcl::Stdctrls::TLabel* Label7;
	Vcl::Stdctrls::TLabel* Label8;
	Vcl::Stdctrls::TLabel* Label9;
	Cxtextedit::TcxTextEdit* cxTextEdit2;
	Cxcheckbox::TcxCheckBox* cxCheckBox1;
	Vcl::Extctrls::TPanel* ButtonsPanel;
	Cxmemo::TcxMemo* Memo1;
	Cxlistbox::TcxListBox* ListBox1;
	Cxbuttons::TcxButton* CancelButton;
	Cxbuttons::TcxButton* OKButton;
	Cxbuttons::TcxButton* MasksButton;
	Vcl::Comctrls::TListView* ListView1;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall cxMaskKindPickEdit1PropertiesChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall cxEditMaskEditKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ListBox1Click(System::TObject* Sender);
	void __fastcall ListBox1Exit(System::TObject* Sender);
	void __fastcall OKButtonClick(System::TObject* Sender);
	void __fastcall CancelButtonClick(System::TObject* Sender);
	void __fastcall ListView1SelectItem(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, bool Selected);
	void __fastcall cxTextEdit1Exit(System::TObject* Sender);
	void __fastcall cxTextEdit1KeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall cxTextEdit2Exit(System::TObject* Sender);
	void __fastcall cxTextEdit2PropertiesChange(System::TObject* Sender);
	void __fastcall MasksButtonClick(System::TObject* Sender);
	void __fastcall cxMaskEdit1Enter(System::TObject* Sender);
	void __fastcall cxCheckBox1PropertiesChange(System::TObject* Sender);
	
private:
	Cxmaskedit::TcxCustomMaskEditProperties* FMaskEditProperties;
	int FLastItemIndex;
	void __fastcall ConvertMaskBlank(void);
	void __fastcall CorrectMaskBlank(void);
	void __fastcall FormatStandardMask(System::UnicodeString &AMask, System::WideChar ANewMaskBlank)/* overload */;
	void __fastcall FormatStandardMask(System::UnicodeString &AMask, bool ANewSaveLiteralChars)/* overload */;
	System::WideChar __fastcall GetCurrentMaskBlank(void);
	bool __fastcall GetSaveLiteralChars(const System::UnicodeString AEditMask);
	System::UnicodeString __fastcall GetSaveLiteralChartSymbol(const bool AValue);
	void __fastcall LoadMaskDem(System::UnicodeString AFileName);
	void __fastcall LoadMaskDxm(System::UnicodeString AFileName);
	void __fastcall OpenMask(void);
	void __fastcall ShowRegExprSamples(void);
	void __fastcall ShowStandardSamples(void);
	
public:
	__property Cxmaskedit::TcxCustomMaskEditProperties* MaskEditProperties = {read=FMaskEditProperties, write=FMaskEditProperties};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxEditMaskEditorDlg(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxEditMaskEditorDlg(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxEditMaskEditorDlg(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxEditMaskEditorDlg(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxSamples RegExprSamples;
extern PACKAGE TcxSamples StandardSamples;
static const System::Int8 DefaultRegExprSamplesCount = System::Int8(0x14);
extern PACKAGE Cxeditmaskeditor__2 DefaultRegExprSamples;
static const System::Int8 DefaultStandardSamplesCount = System::Int8(0x8);
extern PACKAGE Cxeditmaskeditor__3 DefaultStandardSamples;
extern PACKAGE TcxEditMaskEditorDlg* cxEditMaskEditorDlg;
}	/* namespace Cxeditmaskeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITMASKEDITOR)
using namespace Cxeditmaskeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditmaskeditorHPP
