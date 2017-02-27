// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSChLbxLnk.pas' rev: 24.00 (Win32)

#ifndef DxpschlbxlnkHPP
#define DxpschlbxlnkHPP

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
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.CheckLst.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGrLnks.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpschlbxlnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSCheckGridCellDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCheckGridCellDataMap : public Dxpsbasegridlnk::TdxPSTextGridCellDataMap
{
	typedef Dxpsbasegridlnk::TdxPSTextGridCellDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeCellData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem, Dxpsbasegridlnk::TAbstractdxGridReportLink* AReportLink);
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall DataClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSCheckGridCellDataMap(void) : Dxpsbasegridlnk::TdxPSTextGridCellDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCheckGridCellDataMap(void) { }
	
};

#pragma pack(pop)

enum TdxCheckListBoxPaintOption : unsigned char { chlbxpoBorder, chlbxpoHorzLines, chlbxpoFlatCheckMarks };

typedef System::Set<TdxCheckListBoxPaintOption, TdxCheckListBoxPaintOption::chlbxpoBorder, TdxCheckListBoxPaintOption::chlbxpoFlatCheckMarks>  TdxCheckListBoxPaintOptions;

class DELPHICLASS TdxCheckListBoxReportLink;
class PASCALIMPLEMENTATION TdxCheckListBoxReportLink : public Dxpsgrlnks::TdxCustomListBoxReportLink
{
	typedef Dxpsgrlnks::TdxCustomListBoxReportLink inherited;
	
private:
	TdxCheckListBoxPaintOptions FOptions;
	TdxCheckListBoxPaintOptions __fastcall GetOptions(void);
	Vcl::Checklst::TCheckListBox* __fastcall GetCheckListBox(void);
	void __fastcall SetOptions(TdxCheckListBoxPaintOptions Value);
	bool __fastcall IsFlatCheckMarks(void);
	
protected:
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataItemClass(int ACol, int ARow = 0x0);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual void __fastcall SetDrawMode(Dxpsbasegridlnk::TdxGridDrawMode Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Vcl::Checklst::TCheckListBox* CheckListBox = {read=GetCheckListBox};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property OddColor = {default=16777215};
	__property OddFont;
	__property TdxCheckListBoxPaintOptions Options = {read=GetOptions, write=SetOptions, default=7};
	__property Multiline = {default=0};
	__property RowAutoHeight = {default=0};
	__property ScaleFonts = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property UseCustomPageBreaks = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property Width;
	__property OnCustomDrawItem;
	__property OnGetCustomPageBreaks;
	__property OnInitializeItem;
public:
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TdxCheckListBoxReportLink(System::Classes::TComponent* AOwner) : Dxpsgrlnks::TdxCustomListBoxReportLink(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TdxCheckListBoxReportLink(void) { }
	
};


class DELPHICLASS TdxChlbxReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxChlbxReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Cxpc::TcxTabSheet* tshColor;
	Vcl::Extctrls::TImage* Image5;
	Vcl::Extctrls::TImage* imgGrid;
	Cxlabel::TcxLabel* stTransparent;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxlabel::TcxLabel* lblColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxEvenColor;
	Cxlabel::TcxLabel* lblEvenColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxGridLineColor;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxlabel::TcxLabel* cxLabel1;
	Cximagecombobox::TcxImageComboBox* cbxDrawMode;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblMiscellaneous;
	Cxlabel::TcxLabel* lblDrawMode;
	Cxlabel::TcxLabel* lblPreview;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxShowHorzLines;
	Cxcheckbox::TcxCheckBox* chbxFlatCheckMarks;
	Cxcheckbox::TcxCheckBox* chbxRowAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxpc::TcxTabSheet* tshFont;
	Vcl::Extctrls::TPanel* pnlFont;
	Cxbuttons::TcxButton* btnFont;
	Cxbuttons::TcxButton* btnEvenFont;
	Cxtextedit::TcxTextEdit* edFont;
	Cxtextedit::TcxTextEdit* edEvenFont;
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall btnFontClick(System::TObject* Sender);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	void __fastcall chbxTransparentClick(System::TObject* Sender);
	void __fastcall cbxDrawModeClick(System::TObject* Sender);
	void __fastcall chbxShowBordersClick(System::TObject* Sender);
	void __fastcall chbxRowAutoHeightClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall chbxAutoWidthClick(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	
private:
	int FItemCount;
	int FPaintWidth;
	int FPaintHeight;
	Vcl::Extctrls::TCustomPanel* FPreviewBox;
	Vcl::Graphics::TFont* FPreviewFont;
	int FRectWidth;
	int FRectHeight;
	void __fastcall CreateControls(void);
	TdxCheckListBoxReportLink* __fastcall GetReportLink(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	
public:
	__fastcall virtual TdxChlbxReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxChlbxReportLinkDesignWindow(void);
	__property TdxCheckListBoxReportLink* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxChlbxReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxChlbxReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


typedef System::StaticArray<System::UnicodeString, 6> Dxpschlbxlnk__4;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxCheckListBoxPaintOptions dxDefaultCheckListBoxPaintOptions;
static const System::Int8 DesignerStringCount = System::Int8(0x6);
extern PACKAGE Dxpschlbxlnk__4 dxCheckListBoxStrings;
}	/* namespace Dxpschlbxlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCHLBXLNK)
using namespace Dxpschlbxlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpschlbxlnkHPP
