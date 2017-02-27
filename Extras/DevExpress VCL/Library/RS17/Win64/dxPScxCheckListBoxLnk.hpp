// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxCheckListBoxLnk.pas' rev: 24.00 (Win64)

#ifndef DxpscxchecklistboxlnkHPP
#define DxpscxchecklistboxlnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <dxPSGrLnks.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxchecklistboxlnk
{
//-- type declarations -------------------------------------------------------
enum TcxCheckListBoxReportLinkOption : unsigned char { chlbxoBorder, chlbxoHorzLines, chlbxoFlatCheckMarks };

typedef System::Set<TcxCheckListBoxReportLinkOption, TcxCheckListBoxReportLinkOption::chlbxoBorder, TcxCheckListBoxReportLinkOption::chlbxoFlatCheckMarks>  TcxCheckListBoxReportLinkOptions;

class DELPHICLASS TcxCustomCheckListBoxReportLink;
class PASCALIMPLEMENTATION TcxCustomCheckListBoxReportLink : public Dxpsgrlnks::TdxCustomListBoxReportLink
{
	typedef Dxpsgrlnks::TdxCustomListBoxReportLink inherited;
	
private:
	TcxCheckListBoxReportLinkOptions FOptions;
	Cxchecklistbox::TcxCustomCheckListBox* __fastcall GetcxCustomCheckListBox(void);
	void __fastcall SetOptions(TcxCheckListBoxReportLinkOptions Value);
	bool __fastcall IsFlatCheckMarks(void);
	
protected:
	virtual void __fastcall AssignData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual int __fastcall GetCellFontIndex(int ACol, int ARow);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataItemClass(int ACol, int ARow = 0x0);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual void __fastcall SetDrawMode(Dxpsbasegridlnk::TdxGridDrawMode Value);
	virtual Vcl::Stdctrls::TCustomListBox* __fastcall GetCustomListBox(void);
	__property Cxchecklistbox::TcxCustomCheckListBox* cxCustomCheckListBox = {read=GetcxCustomCheckListBox};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCheckListBoxReportLinkOptions Options = {read=FOptions, write=SetOptions, default=7};
public:
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TcxCustomCheckListBoxReportLink(System::Classes::TComponent* AOwner) : Dxpsgrlnks::TdxCustomListBoxReportLink(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TcxCustomCheckListBoxReportLink(void) { }
	
};


class DELPHICLASS TcxCheckListBoxReportLink;
class PASCALIMPLEMENTATION TcxCheckListBoxReportLink : public TcxCustomCheckListBoxReportLink
{
	typedef TcxCustomCheckListBoxReportLink inherited;
	
private:
	Cxchecklistbox::TcxCheckListBox* __fastcall GetCheckListBox(void);
	
public:
	__property Cxchecklistbox::TcxCheckListBox* CheckListBox = {read=GetCheckListBox};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property Multiline = {default=0};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property Options = {default=7};
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
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TcxCheckListBoxReportLink(System::Classes::TComponent* AOwner) : TcxCustomCheckListBoxReportLink(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TcxCheckListBoxReportLink(void) { }
	
};


class DELPHICLASS TcxfmCheckListBoxDesignWindow;
class PASCALIMPLEMENTATION TcxfmCheckListBoxDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Cxpc::TcxTabSheet* tshColor;
	Cxpc::TcxTabSheet* tshFont;
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxlabel::TcxLabel* stTransparent;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxlabel::TcxLabel* lblEvenColor;
	Cxlabel::TcxLabel* lblDrawMode;
	Cxlabel::TcxLabel* lblColor;
	Cxlabel::TcxLabel* cxLabel1;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxcolorcombobox::TcxColorComboBox* ccbxGridLineColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxEvenColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxcheckbox::TcxCheckBox* chbxFlatCheckMarks;
	Cxcheckbox::TcxCheckBox* chbxRowAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxShowHorzLines;
	Vcl::Extctrls::TImage* Image5;
	Vcl::Extctrls::TImage* imgGrid;
	Cxlabel::TcxLabel* lblMiscellaneous;
	Cxlabel::TcxLabel* lblPreview;
	Cxlabel::TcxLabel* lblShow;
	Cxtextedit::TcxTextEdit* edFont;
	Cxtextedit::TcxTextEdit* edEvenFont;
	Cxbuttons::TcxButton* btnFont;
	Cxbuttons::TcxButton* btnEvenFont;
	Cximagecombobox::TcxImageComboBox* cbxDrawMode;
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	void __fastcall cbxDrawModeClick(System::TObject* Sender);
	void __fastcall chbxOptionsClick(System::TObject* Sender);
	void __fastcall chbxRowAutoHeightClick(System::TObject* Sender);
	void __fastcall chbxTransparentClick(System::TObject* Sender);
	void __fastcall btnFontClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall chbxAutoWidthClick(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	
private:
	int FItemCount;
	int FPaintWidth;
	int FPaintHeight;
	Vcl::Extctrls::TCustomPanel* FPreviewBox;
	int FRectWidth;
	int FRectHeight;
	void __fastcall CreateControls(void);
	TcxCustomCheckListBoxReportLink* __fastcall GetReportLink(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	
public:
	__fastcall virtual TcxfmCheckListBoxDesignWindow(System::Classes::TComponent* AOwner);
	__property TcxCustomCheckListBoxReportLink* ReportLink = {read=GetReportLink};
public:
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TcxfmCheckListBoxDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxfmCheckListBoxDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxfmCheckListBoxDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


typedef System::StaticArray<System::UnicodeString, 5> Dxpscxchecklistboxlnk__4;

//-- var, const, procedure ---------------------------------------------------
#define cxDefaultCheckListBoxOptions (System::Set<TcxCheckListBoxReportLinkOption, TcxCheckListBoxReportLinkOption::chlbxoBorder, TcxCheckListBoxReportLinkOption::chlbxoFlatCheckMarks> () << TcxCheckListBoxReportLinkOption::chlbxoBorder << TcxCheckListBoxReportLinkOption::chlbxoHorzLines << TcxCheckListBoxReportLinkOption::chlbxoFlatCheckMarks )
extern PACKAGE Dxpscxchecklistboxlnk__4 cxCheckListBoxStrings;
}	/* namespace Dxpscxchecklistboxlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXCHECKLISTBOXLNK)
using namespace Dxpscxchecklistboxlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxchecklistboxlnkHPP
