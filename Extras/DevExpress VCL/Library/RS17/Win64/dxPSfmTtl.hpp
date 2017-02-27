// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmTtl.pas' rev: 24.00 (Win64)

#ifndef DxpsfmttlHPP
#define DxpsfmttlHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
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
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmttl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmReportTitleProperties;
class PASCALIMPLEMENTATION TdxfmReportTitleProperties : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxlabel::TcxLabel* Bevel2;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnFont;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnRestoreDefaults;
	Cxlabel::TcxLabel* bvlFont;
	Cxcolorcombobox::TcxColorComboBox* cbxColor;
	Cxdropdownedit::TcxComboBox* cbxMode;
	Cxdropdownedit::TcxComboBox* cbxTextAlignX;
	Cxdropdownedit::TcxComboBox* cbxTextAlignY;
	Cxcheckbox::TcxCheckBox* chbxAdjustOnScale;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxtextedit::TcxTextEdit* edFont;
	Vcl::Controls::TImageList* ilAlignments;
	Vcl::Extctrls::TImage* imgFont;
	Cxlabel::TcxLabel* lblAlignment;
	Cxlabel::TcxLabel* lblColor;
	Cxlabel::TcxLabel* lblMode;
	Cxlabel::TcxLabel* lblTextAlignX;
	Cxlabel::TcxLabel* lblTextAlignY;
	Cxlabel::TcxLabel* lblTransparent;
	Cxmemo::TcxMemo* memText;
	Cxpc::TcxPageControl* pctlMain;
	Cxpc::TcxTabSheet* tshProperties;
	Cxpc::TcxTabSheet* tshText;
	void __fastcall btnFontClick(System::TObject* Sender);
	void __fastcall btnRestoreDefaultsClick(System::TObject* Sender);
	void __fastcall cbxTextAlignYPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall lblTransparentClick(System::TObject* Sender);
	void __fastcall memTextKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall TitleChanged(System::TObject* Sender);
	void __fastcall btnHelpClick(System::TObject* Sender);
	
private:
	int FActivePage;
	bool FModified;
	Dxpscore::TdxReportTitle* FReportTitle;
	void __fastcall SetReportTitle(Dxpscore::TdxReportTitle* Value);
	void __fastcall InitializeControls(void);
	void __fastcall LoadStrings(void);
	void __fastcall SaveUserInput(void);
	void __fastcall SetModified(bool Value);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	__property bool Modified = {read=FModified, write=SetModified, nodefault};
	
protected:
	virtual void __fastcall BeforeConstruction(void);
	
public:
	__fastcall virtual TdxfmReportTitleProperties(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmReportTitleProperties(void);
	bool __fastcall Execute(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property Dxpscore::TdxReportTitle* ReportTitle = {read=FReportTitle, write=SetReportTitle};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmReportTitleProperties(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmReportTitleProperties(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowReportTitlePropertiesDlg(Dxpscore::TdxReportTitle* AReportTitle);
}	/* namespace Dxpsfmttl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMTTL)
using namespace Dxpsfmttl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmttlHPP
