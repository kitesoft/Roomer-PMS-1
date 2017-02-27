// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxHintEditor.pas' rev: 24.00 (Win32)

#ifndef CxhinteditorHPP
#define CxhinteditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxFontNameComboBox.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxHint.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxSpinButton.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxSplitter.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxTrackBar.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxhinteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxHintStyleEditor;
class PASCALIMPLEMENTATION TcxHintStyleEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxbuttons::TcxButton* cxBtnOk;
	Cxbuttons::TcxButton* cxBtnCancel;
	Cxcheckbox::TcxCheckBox* cxCbStandard;
	Cxgroupbox::TcxGroupBox* cxGbHintFont;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TLabel* Label3;
	Cxfontnamecombobox::TcxFontNameComboBox* cxFnHint;
	Cxchecklistbox::TcxCheckListBox* cxClbHintFontStyles;
	Cxlistbox::TcxListBox* cxLbHfSize;
	Cxcolorcombobox::TcxColorComboBox* cxCcbHintFontColour;
	Cxgroupbox::TcxGroupBox* cxgbHintCapFont;
	Vcl::Stdctrls::TLabel* Label4;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Stdctrls::TLabel* Label6;
	Cxfontnamecombobox::TcxFontNameComboBox* cxFnHinCap;
	Cxchecklistbox::TcxCheckListBox* cxClbHintCapFontStyles;
	Cxlistbox::TcxListBox* cxLbHcfSize;
	Cxcolorcombobox::TcxColorComboBox* cxCcbHintCapColor;
	Cxgroupbox::TcxGroupBox* cxGbHintShape;
	Vcl::Stdctrls::TLabel* Label7;
	Vcl::Stdctrls::TLabel* Label8;
	Cxdropdownedit::TcxComboBox* cxCbHintCalloutPos;
	Cxcheckbox::TcxCheckBox* cxcbHintRounded;
	Cxspinedit::TcxSpinEdit* cxSeHintRadius;
	Cxgroupbox::TcxGroupBox* cxGbHintIcons;
	Vcl::Stdctrls::TLabel* Label11;
	Cxdropdownedit::TcxComboBox* cxCbHintIconType;
	Cxradiogroup::TcxRadioButton* cxRbHIDef;
	Cxradiogroup::TcxRadioButton* cxRbHILarge;
	Cxradiogroup::TcxRadioButton* cxRbHISmall;
	Cxgroupbox::TcxGroupBox* cxGbHintPause;
	Vcl::Stdctrls::TLabel* Label18;
	Vcl::Stdctrls::TLabel* Label19;
	Vcl::Stdctrls::TLabel* Label20;
	Cxspinedit::TcxSpinEdit* cxSeHintHidePause;
	Cxspinedit::TcxSpinEdit* cxSeHintPause;
	Cxspinedit::TcxSpinEdit* cxSeShortHintPause;
	Vcl::Stdctrls::TLabel* lblHintColour;
	Cxcolorcombobox::TcxColorComboBox* cxCcbHintColour;
	Cxgroupbox::TcxGroupBox* cxGbHintAnimation;
	Vcl::Stdctrls::TLabel* Label9;
	Vcl::Stdctrls::TLabel* Label10;
	Cxdropdownedit::TcxComboBox* cxCbHintAniStyle;
	Cxspinedit::TcxSpinEdit* cxSeHintDelay;
	Cxgroupbox::TcxGroupBox* cxGbPreview;
	Cxhint::TcxHintStyleController* cxHsc;
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxedit::TcxEditStyleController* cxEditStyleController1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall cxFnHintClick(System::TObject* Sender);
	void __fastcall cxCbHintCalloutPosClick(System::TObject* Sender);
	void __fastcall cxSeHintRadiusPropertiesChange(System::TObject* Sender);
	void __fastcall cxcbHintRoundedPropertiesChange(System::TObject* Sender);
	void __fastcall cxCbHintAniStylePropertiesChange(System::TObject* Sender);
	void __fastcall cxSeHintDelayPropertiesChange(System::TObject* Sender);
	void __fastcall cxCbHintIconTypeClick(System::TObject* Sender);
	void __fastcall cxRbHIDefClick(System::TObject* Sender);
	void __fastcall cxSeHintHidePausePropertiesChange(System::TObject* Sender);
	void __fastcall cxSeHintPausePropertiesChange(System::TObject* Sender);
	void __fastcall cxSeShortHintPausePropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall cxClbHintFontStylesClickCheck(System::TObject* Sender, int AIndex, Cxlookandfeelpainters::TcxCheckBoxState APrevState, Cxlookandfeelpainters::TcxCheckBoxState ANewState);
	void __fastcall cxCcbHintFontColourClick(System::TObject* Sender);
	void __fastcall cxCcbHintCapColorClick(System::TObject* Sender);
	void __fastcall cxFnHintPropertiesChange(System::TObject* Sender);
	void __fastcall cxLbHfSizeClick(System::TObject* Sender);
	void __fastcall cxLbHcfSizeClick(System::TObject* Sender);
	void __fastcall cxFnHinCapPropertiesChange(System::TObject* Sender);
	void __fastcall cxCbStandardClick(System::TObject* Sender);
	void __fastcall cxFnHinCapClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall cxCcbHintColourPropertiesEditValueChanged(System::TObject* Sender);
	
private:
	System::Classes::TStringList* fViewerFontSizes;
	int fHintHorz;
	int fHintVert;
	bool fFormLoaded;
	void __fastcall SetHsc(Cxhint::TcxHintStyleController* const Value);
	void __fastcall RefreshHint(void);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMMove(Winapi::Messages::TWMMove &Message);
	Cxhint::TcxHintStyle* __fastcall GetHintStyle(void);
	
public:
	void __fastcall SetHintController(Cxhint::TcxHintStyleController* aDest);
	void __fastcall LoadHintCtrls(void);
	__property Cxhint::TcxHintStyleController* HintController = {read=cxHsc, write=SetHsc};
	__property Cxhint::TcxHintStyle* HintStyle = {read=GetHintStyle};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxHintStyleEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxHintStyleEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxHintStyleEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxHintStyleEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxHintStyleEditor* cxHintStyleEditor;
extern PACKAGE void __fastcall ShowHintStyleEditor(Cxhint::TcxHintStyleController* AHintStyleController);
}	/* namespace Cxhinteditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXHINTEDITOR)
using namespace Cxhinteditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxhinteditorHPP
