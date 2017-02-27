// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxStyleSheetsLoad.pas' rev: 24.00 (Win32)

#ifndef CxstylesheetsloadHPP
#define CxstylesheetsloadHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxStyleSheetEditor.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxstylesheetsload
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxPredefinedStyleSheetsClass;

class DELPHICLASS TcxPredefinedStyleSheets;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPredefinedStyleSheets : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FList;
	
protected:
	void __fastcall AddStyleSheet(Cxstyles::TcxCustomStyleSheet* AStyleSheet);
	virtual void __fastcall AddStyleSheets(void) = 0 ;
	
public:
	__fastcall virtual TcxPredefinedStyleSheets(void);
	__fastcall virtual ~TcxPredefinedStyleSheets(void);
	void __fastcall GetStyleSheetsByClass(Cxstyles::TcxCustomStyleSheetClass AStyleSheetClass, System::Classes::TList* const AList);
};

#pragma pack(pop)

class DELPHICLASS TcxPredefinedStyleSheetsList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPredefinedStyleSheetsList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FList;
	Vcl::Stdctrls::TComboBox* FStyleSheetClassComboBox;
	Vcl::Stdctrls::TListBox* FStyleSheetsListBox;
	Vcl::Stdctrls::TButton* FLoadButton;
	Cxstylesheeteditor::TcxStyleSheetEditorPreview* FPreview;
	void __fastcall StyleSheetClassComboBoxClick(System::TObject* Sender);
	void __fastcall StyleSheetsListBoxClick(System::TObject* Sender);
	
protected:
	void __fastcall FreeAndNilItems(void);
	void __fastcall UpdateButton(void);
	
public:
	__fastcall TcxPredefinedStyleSheetsList(Vcl::Stdctrls::TComboBox* AStyleSheetClassComboBox, Vcl::Stdctrls::TListBox* AStyleSheetsListBox, Vcl::Stdctrls::TButton* ALoadButton);
	__fastcall virtual ~TcxPredefinedStyleSheetsList(void);
	Cxstyles::TcxCustomStyleSheet* __fastcall CurrentStyleSheet(void);
	Cxstyles::TcxCustomStyleSheetClass __fastcall CurrentStyleSheetClass(void);
	void __fastcall FillListBox(void);
};

#pragma pack(pop)

class DELPHICLASS TfrmcxStyleSheetsLoad;
class PASCALIMPLEMENTATION TfrmcxStyleSheetsLoad : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlBottom;
	Vcl::Extctrls::TBevel* Bevel;
	Vcl::Extctrls::TPanel* pnlStyles;
	Vcl::Extctrls::TPanel* pnlStyleSheetClasses;
	Vcl::Stdctrls::TLabel* lbStyleSheetClass;
	Vcl::Stdctrls::TComboBox* cbStyleSheetClasses;
	Vcl::Stdctrls::TListBox* lbStyleSheets;
	Vcl::Extctrls::TPanel* pnlPreview;
	Vcl::Extctrls::TPanel* pnlClient;
	Vcl::Stdctrls::TButton* btnLoad;
	Vcl::Stdctrls::TButton* btnClose;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Stdctrls::TLabel* lbPreview;
	Vcl::Extctrls::TPanel* pnlPreviewClient;
	void __fastcall FormCreate(System::TObject* Sender);
	
public:
	__fastcall virtual TfrmcxStyleSheetsLoad(System::Classes::TComponent* AOwner);
	Cxstyles::TcxCustomStyleSheetClass __fastcall CurrentStyleSheetClass(void);
	void __fastcall SetShowPreview(bool Value);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmcxStyleSheetsLoad(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmcxStyleSheetsLoad(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmcxStyleSheetsLoad(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegisterPredefinedStyleSheets(TcxPredefinedStyleSheetsClass APredefinedStyleSheetsClass);
extern PACKAGE void __fastcall UnregisterPredefinedStyleSheets(TcxPredefinedStyleSheetsClass APredefinedStyleSheetsClass);
extern PACKAGE void __fastcall GetPredefinedStyleSheetClasses(System::Classes::TList* AList);
extern PACKAGE void __fastcall ShowLoadStyleSheetsFromIniFile(const System::UnicodeString AIniFileName, Cxstyles::TcxStyleRepository* AStyleRepository, System::Classes::TComponent* AOwner, System::Classes::TList* const AStyleSheetList, Cxstyles::TcxStyleGetName AStyleGetName);
extern PACKAGE void __fastcall ShowLoadStyleSheetsFromPreDefineStyles(Cxstyles::TcxStyleRepository* AStyleRepository, System::Classes::TComponent* AOwner, System::Classes::TList* const AStyleSheetList, Cxstyles::TcxStyleGetName AStyleGetName);
}	/* namespace Cxstylesheetsload */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSTYLESHEETSLOAD)
using namespace Cxstylesheetsload;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxstylesheetsloadHPP
