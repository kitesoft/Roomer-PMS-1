// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSLbxLnk.pas' rev: 24.00 (Win32)

#ifndef DxpslbxlnkHPP
#define DxpslbxlnkHPP

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
#include <Vcl.CheckLst.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <dxPSGrLnks.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpslbxlnk
{
//-- type declarations -------------------------------------------------------
enum TdxListBoxPaintOption : unsigned char { lbxpoBorder, lbxpoHorzLines };

typedef System::Set<TdxListBoxPaintOption, TdxListBoxPaintOption::lbxpoBorder, TdxListBoxPaintOption::lbxpoHorzLines>  TdxListBoxPaintOptions;

class DELPHICLASS TCustomdxListBoxReportLinkControl;
class PASCALIMPLEMENTATION TCustomdxListBoxReportLinkControl : public Dxpsgrlnks::TdxCustomListBoxReportLink
{
	typedef Dxpsgrlnks::TdxCustomListBoxReportLink inherited;
	
private:
	TdxListBoxPaintOptions FOptions;
	bool FPaintItemsGraphics;
	bool FTransparentGraphics;
	TdxListBoxPaintOptions __fastcall GetOptions(void);
	void __fastcall SetOptions(TdxListBoxPaintOptions Value);
	void __fastcall SetPaintItemsGraphics(bool Value);
	void __fastcall SetTransparentGraphics(bool Value);
	
protected:
	virtual void __fastcall AssignData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataItemClass(int ACol, int ARow = 0x0);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual void __fastcall SetDrawMode(Dxpsbasegridlnk::TdxGridDrawMode Value);
	virtual bool __fastcall GetCellHasImage(int ACol, int ARow);
	virtual Vcl::Graphics::TGraphic* __fastcall GetCellImage(int ACol, int ARow);
	virtual bool __fastcall GetCellImageTransparent(int ACol, int ARow);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxListBoxPaintOptions Options = {read=GetOptions, write=SetOptions, default=3};
	__property bool PaintItemsGraphics = {read=FPaintItemsGraphics, write=SetPaintItemsGraphics, default=0};
	__property bool TransparentGraphics = {read=FTransparentGraphics, write=SetTransparentGraphics, default=0};
public:
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TCustomdxListBoxReportLinkControl(System::Classes::TComponent* AOwner) : Dxpsgrlnks::TdxCustomListBoxReportLink(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TCustomdxListBoxReportLinkControl(void) { }
	
};


class DELPHICLASS TdxListBoxReportLink;
class PASCALIMPLEMENTATION TdxListBoxReportLink : public TCustomdxListBoxReportLinkControl
{
	typedef TCustomdxListBoxReportLinkControl inherited;
	
private:
	Vcl::Stdctrls::TListBox* __fastcall GetListBox(void);
	
public:
	__property Vcl::Stdctrls::TListBox* ListBox = {read=GetListBox};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property OddColor = {default=16777215};
	__property OddFont;
	__property Options = {default=3};
	__property Multiline = {default=0};
	__property PaintItemsGraphics = {default=0};
	__property RowAutoHeight = {default=0};
	__property ScaleFonts = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property TransparentGraphics = {default=0};
	__property UseCustomPageBreaks = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property Width;
	__property OnCustomDrawItem;
	__property OnGetCustomPageBreaks;
	__property OnInitializeItem;
public:
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TdxListBoxReportLink(System::Classes::TComponent* AOwner) : TCustomdxListBoxReportLinkControl(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TdxListBoxReportLink(void) { }
	
};


class DELPHICLASS TdxLBxReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxLBxReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Cxpc::TcxTabSheet* tshColor;
	Cxpc::TcxTabSheet* tshFont;
	Cxpc::TcxTabSheet* tshBehaviors;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblPreview;
	Vcl::Extctrls::TImage* imgGrid;
	Cxcheckbox::TcxCheckBox* chbxTransparentGraphics;
	Cxcheckbox::TcxCheckBox* chbxShowHorzLines;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxPaintItemGraphics;
	Cxlabel::TcxLabel* Bevel4;
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
	Cximagecombobox::TcxImageComboBox* cbxDrawMode;
	Cxtextedit::TcxTextEdit* edFont;
	Cxtextedit::TcxTextEdit* edEvenFont;
	Cxbuttons::TcxButton* btnFont;
	Cxbuttons::TcxButton* btnEvenFont;
	Cxlabel::TcxLabel* lblSelection;
	Cxlabel::TcxLabel* lblMiscellaneous;
	Vcl::Extctrls::TImage* imgMiscellaneous;
	Vcl::Extctrls::TImage* Image3;
	Cxcheckbox::TcxCheckBox* chbxRowAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxOnlySelected;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxgraphics::TcxImageList* ilPreview;
	void __fastcall chbxOnlySelectedClick(System::TObject* Sender);
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall btnFontClick(System::TObject* Sender);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	void __fastcall chbxPaintItemGraphicsClick(System::TObject* Sender);
	void __fastcall chbxTransparentClick(System::TObject* Sender);
	void __fastcall lblComboClick(System::TObject* Sender);
	void __fastcall chbxShowBordersClick(System::TObject* Sender);
	void __fastcall cbxDrawModeClick(System::TObject* Sender);
	void __fastcall chbxRowAutoHeightClick(System::TObject* Sender);
	void __fastcall chbxTransparentGraphicsClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall chbxAutoWidthClick(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	
private:
	int FItemCount;
	int FPaintWidth;
	int FPaintHeight;
	Vcl::Extctrls::TCustomPanel* FPreviewBox;
	Vcl::Graphics::TFont* FPreviewFont;
	int FRectHeight;
	int FRectWidth;
	void __fastcall CreateControls(void);
	TCustomdxListBoxReportLinkControl* __fastcall GetReportLink(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &message);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	
public:
	__fastcall virtual TdxLBxReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxLBxReportLinkDesignWindow(void);
	__property TCustomdxListBoxReportLinkControl* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxLBxReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxLBxReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


typedef System::StaticArray<System::UnicodeString, 6> Dxpslbxlnk__4;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxListBoxPaintOptions dxDefaultListBoxPaintOptions;
extern PACKAGE Dxpslbxlnk__4 dxListBoxStrings;
}	/* namespace Dxpslbxlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSLBXLNK)
using namespace Dxpslbxlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpslbxlnkHPP
