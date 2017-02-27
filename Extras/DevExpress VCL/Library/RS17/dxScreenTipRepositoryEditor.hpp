// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxScreenTipRepositoryEditor.pas' rev: 24.00 (Win32)

#ifndef DxscreentiprepositoryeditorHPP
#define DxscreentiprepositoryeditorHPP

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
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxComponentCollectionEditor.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxScreenTip.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <System.StrUtils.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Vcl.StdActns.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxscreentiprepositoryeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmScreenTipRepositoryEditor;
class PASCALIMPLEMENTATION TfrmScreenTipRepositoryEditor : public Cxcomponentcollectioneditor::TfrmComponentCollectionEditor
{
	typedef Cxcomponentcollectioneditor::TfrmComponentCollectionEditor inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlButtons;
	Vcl::Stdctrls::TButton* btnClose;
	Vcl::Extctrls::TPanel* pnlPreviewAndOptions;
	Vcl::Extctrls::TPanel* pnlPreview;
	Vcl::Stdctrls::TGroupBox* gbPreview;
	Vcl::Extctrls::TPaintBox* PaintBox1;
	Vcl::Extctrls::TPanel* pnlOptions;
	Vcl::Comctrls::TPageControl* pcOptions;
	Vcl::Comctrls::TTabSheet* tsScreenTipOptions;
	Vcl::Stdctrls::TGroupBox* gbScreenTipInfo;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TEdit* edtHeader;
	Vcl::Stdctrls::TMemo* edtDescription;
	Vcl::Stdctrls::TEdit* edtFooter;
	Vcl::Stdctrls::TCheckBox* chbUseHintAsHeader;
	Vcl::Stdctrls::TCheckBox* chbUseStandardFooter;
	Vcl::Comctrls::TUpDown* UpDown1;
	Vcl::Stdctrls::TEdit* edtWidth;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPaintBox* pbDescription;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPaintBox* pbFooter;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Extctrls::TPaintBox* pbHeader;
	Vcl::Comctrls::TTabSheet* tsRepositoryOptions;
	Vcl::Stdctrls::TGroupBox* gbScreenTipsInfo;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Buttons::TSpeedButton* btnHeaderFont;
	Vcl::Buttons::TSpeedButton* btnDescriptionFont;
	Vcl::Buttons::TSpeedButton* btnFooterFont;
	Vcl::Stdctrls::TLabel* lblHeaderFontInfo;
	Vcl::Stdctrls::TLabel* lblDescriptionFontInfo;
	Vcl::Stdctrls::TLabel* lblFooterFontInfo;
	Vcl::Stdctrls::TCheckBox* chbShowDescription;
	Vcl::Stdctrls::TEdit* edtStandardFooter;
	Vcl::Extctrls::TPanel* Panel4;
	Vcl::Extctrls::TPaintBox* pbStandardFooter;
	Vcl::Stdctrls::TCheckBox* chbHeaderFont;
	Vcl::Stdctrls::TCheckBox* chbDescriptionFont;
	Vcl::Stdctrls::TCheckBox* chbFooterFont;
	Vcl::Extctrls::TSplitter* Splitter1;
	Vcl::Actnlist::TAction* actLeftDescriptionAlign;
	Vcl::Extdlgs::TOpenPictureDialog* OpenPictureDialog1;
	Vcl::Menus::TPopupMenu* PopupMenu3;
	Vcl::Menus::TMenuItem* Open1;
	Vcl::Menus::TMenuItem* Clear1;
	Vcl::Menus::TMenuItem* Align1;
	Vcl::Menus::TMenuItem* Left1;
	Vcl::Menus::TMenuItem* Right1;
	Vcl::Dialogs::TFontDialog* FontDialog1;
	Vcl::Menus::TMenuItem* FixedWidth1;
	Vcl::Buttons::TSpeedButton* btnHeaderRichTextEdit;
	Vcl::Buttons::TSpeedButton* btnDescriptionRichTextEdit;
	Vcl::Buttons::TSpeedButton* btnFooterRichTextEdit;
	Vcl::Buttons::TSpeedButton* btnStdFooterRichTextEdit;
	Vcl::Stdctrls::TCheckBox* chbPlainText;
	Vcl::Stdctrls::TCheckBox* chbHeaderPlain;
	Vcl::Stdctrls::TCheckBox* chbDescriptionPlain;
	Vcl::Stdctrls::TCheckBox* chbFooterPlain;
	Vcl::Stdctrls::TButton* btnShowOptions;
	void __fastcall PaintBox1Paint(System::TObject* Sender);
	void __fastcall edtHeaderChange(System::TObject* Sender);
	void __fastcall edtStandardFooterChange(System::TObject* Sender);
	void __fastcall btnCloseClick(System::TObject* Sender);
	void __fastcall chbShowDescriptionClick(System::TObject* Sender);
	void __fastcall chbHeaderFontClick(System::TObject* Sender);
	void __fastcall btnFooterFontClick(System::TObject* Sender);
	void __fastcall btnDescriptionFontClick(System::TObject* Sender);
	void __fastcall btnHeaderFontClick(System::TObject* Sender);
	void __fastcall chbUseHintAsHeaderClick(System::TObject* Sender);
	void __fastcall chbUseStandardFooterClick(System::TObject* Sender);
	void __fastcall edtWidthChange(System::TObject* Sender);
	void __fastcall edtWidthExit(System::TObject* Sender);
	void __fastcall PopupMenu3Popup(System::TObject* Sender);
	void __fastcall pbHeaderClick(System::TObject* Sender);
	void __fastcall pbHeaderContextPopup(System::TObject* Sender, const System::Types::TPoint &MousePos, bool &Handled);
	void __fastcall pbHeaderPaint(System::TObject* Sender);
	void __fastcall pbStandardFooterClick(System::TObject* Sender);
	void __fastcall pbStandardFooterPaint(System::TObject* Sender);
	void __fastcall pnlPreviewResize(System::TObject* Sender);
	void __fastcall Open1Click(System::TObject* Sender);
	void __fastcall Clear1Click(System::TObject* Sender);
	void __fastcall Right1Click(System::TObject* Sender);
	void __fastcall FixedWidth1Click(System::TObject* Sender);
	void __fastcall btnDescriptionRichTextEditClick(System::TObject* Sender);
	void __fastcall chbPlainTextClick(System::TObject* Sender);
	void __fastcall btnShowOptionsClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	
private:
	Dxscreentip::TdxCustomScreenTipBand* FEditBand;
	int FLockUpdate;
	Vcl::Extctrls::TPaintBox* FPopupTrackPaintBox;
	bool FRefreshing;
	Dxcustomhint::TdxCustomHintViewInfo* FViewInfo;
	void __fastcall ApplyRichText(System::TObject* Sender);
	void __fastcall DrawBandImage(Vcl::Extctrls::TPaintBox* APaintBox);
	Dxscreentip::TdxCustomScreenTipBand* __fastcall GetBand(int AIndex);
	Dxscreentip::TdxScreenTipRepository* __fastcall GetRepository(void);
	Dxscreentip::TdxScreenTip* __fastcall GetScreenTip(void);
	void __fastcall OpenBandImage(Vcl::Extctrls::TPaintBox* APaintBox);
	void __fastcall RefreshHint(void);
	void __fastcall SetBandText(Vcl::Stdctrls::TCustomEdit* AEdit);
	void __fastcall UpdateFontInfo(Vcl::Stdctrls::TLabel* AFontInfoViewer);
	void __fastcall UpdateHeaderFont(void);
	void __fastcall UpdateDescriptionFont(void);
	void __fastcall UpdateFooterFont(void);
	void __fastcall UpdateScreenTipInfo(void);
	void __fastcall UpdateRepositoryInfo(void);
	
protected:
	void __fastcall DataChanged(void);
	virtual void __fastcall DoSelectionIfNoItemsSelected(void);
	virtual void __fastcall InitFormEditor(void);
	
public:
	HIDESBASE void __fastcall BeginUpdate(void);
	HIDESBASE void __fastcall CancelUpdate(void);
	HIDESBASE void __fastcall EndUpdate(void);
	virtual bool __fastcall EditAction(Designintf::TEditAction Action);
	virtual Designintf::TEditState __fastcall GetEditState(void);
	virtual void __fastcall DoItemsModified(void);
	DYNAMIC bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	__property Dxscreentip::TdxScreenTipRepository* Repository = {read=GetRepository};
	__property Dxscreentip::TdxScreenTip* ScreenTip = {read=GetScreenTip};
public:
	/* TfrmComponentCollectionEditor.Create */ inline __fastcall virtual TfrmScreenTipRepositoryEditor(System::Classes::TComponent* AOwner) : Cxcomponentcollectioneditor::TfrmComponentCollectionEditor(AOwner) { }
	
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TfrmScreenTipRepositoryEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmScreenTipRepositoryEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxcomponentcollectioneditor::TfrmComponentCollectionEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmScreenTipRepositoryEditor(HWND ParentWindow) : Cxcomponentcollectioneditor::TfrmComponentCollectionEditor(ParentWindow) { }
	
};


class DELPHICLASS TdxScreenTipCollectionProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxScreenTipCollectionProperty : public Cxcomponentcollectioneditor::TcxComponentCollectionProperty
{
	typedef Cxcomponentcollectioneditor::TcxComponentCollectionProperty inherited;
	
public:
	virtual Cxcomponentcollectioneditor::TcxComponentCollectionEditorClass __fastcall GetEditorClass(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxScreenTipCollectionProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxcomponentcollectioneditor::TcxComponentCollectionProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxScreenTipCollectionProperty(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxscreentiprepositoryeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSCREENTIPREPOSITORYEDITOR)
using namespace Dxscreentiprepositoryeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxscreentiprepositoryeditorHPP
