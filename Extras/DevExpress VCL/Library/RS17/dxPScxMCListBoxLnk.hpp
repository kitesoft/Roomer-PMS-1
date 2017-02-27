// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxMCListBoxLnk.pas' rev: 24.00 (Win32)

#ifndef DxpscxmclistboxlnkHPP
#define DxpscxmclistboxlnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxMCListBox.hpp>	// Pascal unit
#include <cxHeader.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxmclistboxlnk
{
//-- type declarations -------------------------------------------------------
enum TcxMCListBoxPaintOption : unsigned char { mclbpoBorder, mclbpoHorzLines, mclbpoVertLines, mclbpoColumnHeaders };

typedef System::Set<TcxMCListBoxPaintOption, TcxMCListBoxPaintOption::mclbpoBorder, TcxMCListBoxPaintOption::mclbpoColumnHeaders>  TcxMCListBoxPaintOptions;

class DELPHICLASS TcxMCListBoxReportLink;
typedef void __fastcall (__closure *TcxMCListBoxCustomDrawItemEvent)(TcxMCListBoxReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, int ACol, int ARow, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

class PASCALIMPLEMENTATION TcxMCListBoxReportLink : public Dxpsbasegridlnk::TAbstractdxGridReportLink
{
	typedef Dxpsbasegridlnk::TAbstractdxGridReportLink inherited;
	
private:
	TcxMCListBoxPaintOptions FOptions;
	TcxMCListBoxCustomDrawItemEvent FOnCustomDrawItem;
	Cxheader::TcxHeaderSection* __fastcall GetColumn(int Index);
	Cxmclistbox::TcxMCListBox* __fastcall GetcxMCListBox(void);
	System::Uitypes::TColor __fastcall GetHeaderColor(void);
	Vcl::Graphics::TFont* __fastcall GetHeaderFont(void);
	bool __fastcall GetHeaderTransparent(void);
	bool __fastcall GetIncludeHeaders(void);
	TcxMCListBoxPaintOptions __fastcall GetOptions(void);
	System::UnicodeString __fastcall GetText(int Column, int Row);
	void __fastcall SetOnCustomDrawItem(TcxMCListBoxCustomDrawItemEvent Value);
	void __fastcall SetHeaderColor(System::Uitypes::TColor Value);
	void __fastcall SetHeaderFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetHeaderTransparent(bool Value);
	void __fastcall SetIncludeHeaders(bool Value);
	void __fastcall SetOptions(TcxMCListBoxPaintOptions Value);
	bool __fastcall AreColumnHeadersShown(void);
	bool __fastcall HasHeaderSections(void);
	
protected:
	virtual bool __fastcall CanCalculateRowAutoHeight(int ARow);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABoundsRect, const System::Types::TRect &AClientRect, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawItem(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataItemClass(int ACol, int ARow = 0x0);
	virtual int __fastcall GetColCount(void);
	virtual int __fastcall GetFixedRowCount(void);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall GetCellImageIndex(int ACol, int ARow);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetCellImageList(int ACol, int ARow);
	virtual bool __fastcall GetCellMultiline(int ACol, int ARow);
	virtual System::UnicodeString __fastcall GetCellText(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetCellTextAlignX(int ACol, int ARow);
	virtual Dxpscore::TdxCellSortOrder __fastcall GetColSortOrder(int ACol);
	virtual int __fastcall GetSelectedColCount(void);
	virtual int __fastcall GetSelectedRowCount(void);
	virtual int __fastcall GetSourceColWidth(int ACol);
	virtual int __fastcall GetSourceRowHeight(int ARow);
	virtual bool __fastcall HasColumnHeaderImage(int ACol);
	virtual bool __fastcall HasSelection(void);
	virtual bool __fastcall HasSelectionInCol(int ACol);
	virtual bool __fastcall HasSelectionInRow(int ARow);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawFixedHorzLines(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual bool __fastcall IsDrawVertLines(void);
	virtual bool __fastcall IsSelectedCell(int ACol, int ARow);
	virtual bool __fastcall IsSelectedRow(int ARow);
	virtual void __fastcall SetDrawMode(Dxpsbasegridlnk::TdxGridDrawMode Value);
	__property Cxheader::TcxHeaderSection* Columns[int Index] = {read=GetColumn};
	__property System::UnicodeString Texts[int Column][int Row] = {read=GetText};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Cxmclistbox::TcxMCListBox* cxMCListBox = {read=GetcxMCListBox};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property DrawMode = {write=SetDrawMode, default=0};
	__property Effects3D = {default=0};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property System::Uitypes::TColor HeaderColor = {read=GetHeaderColor, write=SetHeaderColor, default=-16777201};
	__property Vcl::Graphics::TFont* HeaderFont = {read=GetHeaderFont, write=SetHeaderFont, stored=IsFixedFontStored};
	__property bool HeaderTransparent = {read=GetHeaderTransparent, write=SetHeaderTransparent, default=0};
	__property bool IncludeHeaders = {read=GetIncludeHeaders, write=SetIncludeHeaders, default=1};
	__property GridLineColor = {default=0};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property OnlySelected = {default=0};
	__property TcxMCListBoxPaintOptions Options = {read=GetOptions, write=SetOptions, default=15};
	__property RowAutoHeight = {default=0};
	__property Soft3D = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property UseCustomPageBreaks = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property TcxMCListBoxCustomDrawItemEvent OnCustomDrawItem = {read=FOnCustomDrawItem, write=SetOnCustomDrawItem};
	__property OnGetCustomPageBreaks;
	__property OnInitializeItem;
public:
	/* TAbstractdxGridReportLink.Create */ inline __fastcall virtual TcxMCListBoxReportLink(System::Classes::TComponent* AOwner) : Dxpsbasegridlnk::TAbstractdxGridReportLink(AOwner) { }
	/* TAbstractdxGridReportLink.Destroy */ inline __fastcall virtual ~TcxMCListBoxReportLink(void) { }
	
};


class DELPHICLASS TcxfmMCListBoxDesignWindow;
class PASCALIMPLEMENTATION TcxfmMCListBoxDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* pcMain;
	Cxpc::TcxTabSheet* tshOptions;
	Vcl::Extctrls::TImage* imgGrid;
	Cxpc::TcxTabSheet* tshColor;
	Cxpc::TcxTabSheet* tshFont;
	Cxpc::TcxTabSheet* tshBehaviors;
	Vcl::Extctrls::TImage* Image3;
	Vcl::Extctrls::TImage* Image8;
	Vcl::Extctrls::TPanel* pnlPreview;
	Vcl::Extctrls::TImage* Image5;
	Vcl::Extctrls::TImage* Image1;
	Cxcheckbox::TcxCheckBox* chbxShowVertLines;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxShowHorzLines;
	Cxcheckbox::TcxCheckBox* chbxShowColumnHeaders;
	Cxcheckbox::TcxCheckBox* chbxHeadersOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxcheckbox::TcxCheckBox* chbxTransparentHeaders;
	Cxcheckbox::TcxCheckBox* chbxIncludeFixed;
	Cxcheckbox::TcxCheckBox* chbxOnlySelected;
	Cxcheckbox::TcxCheckBox* chbxUse3DEffects;
	Cxcheckbox::TcxCheckBox* chbxUseSoft3D;
	Cxcheckbox::TcxCheckBox* chbxRowAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblOnEveryPage;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxlabel::TcxLabel* lblDrawMode;
	Cxlabel::TcxLabel* lblSelection;
	Cxlabel::TcxLabel* lblLookAndFeel;
	Cxlabel::TcxLabel* lblMiscellaneous;
	Cxlabel::TcxLabel* lblPreview;
	Cxbuttons::TcxButton* btnFont;
	Cxbuttons::TcxButton* btnHeadersFont;
	Cxbuttons::TcxButton* btnEvenFont;
	Cxtextedit::TcxTextEdit* edFont;
	Cxtextedit::TcxTextEdit* edFixedFont;
	Cxtextedit::TcxTextEdit* edEvenFont;
	Cxcolorcombobox::TcxColorComboBox* ccbxGridLineColor;
	Cximagecombobox::TcxImageComboBox* cbxDrawMode;
	Cxlabel::TcxLabel* stTransparentHeaders;
	Cxlabel::TcxLabel* stTransparent;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxlabel::TcxLabel* lblColor;
	Cxlabel::TcxLabel* lblEvenColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxEvenColor;
	Cxlabel::TcxLabel* lblHeadersColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxHeadersColor;
	Cxlabel::TcxLabel* lblSeparator;
	void __fastcall DrawModeClick(System::TObject* Sender);
	void __fastcall ShowClick(System::TObject* Sender);
	void __fastcall RowAutoHeightClick(System::TObject* Sender);
	void __fastcall TransparentClick(System::TObject* Sender);
	void __fastcall FontClick(System::TObject* Sender);
	void __fastcall HeadersOnEveryPageClick(System::TObject* Sender);
	void __fastcall OnlySelectedClick(System::TObject* Sender);
	void __fastcall IncludeFixedClick(System::TObject* Sender);
	void __fastcall Use3DEffectsClick(System::TObject* Sender);
	void __fastcall UseSoft3DClick(System::TObject* Sender);
	void __fastcall ColorChange(System::TObject* Sender);
	void __fastcall PreviewPaint(System::TObject* Sender);
	void __fastcall pcMainChange(System::TObject* Sender);
	void __fastcall chbxAutoWidthClick(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	void __fastcall stTransparentHeadersClick(System::TObject* Sender);
	
private:
	Dxextctrls::TdxPSPaintPanel* FPreviewBox;
	TcxMCListBoxReportLink* __fastcall GetReportLink(void);
	void __fastcall CreateControls(void);
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
	__fastcall virtual TcxfmMCListBoxDesignWindow(System::Classes::TComponent* AOwner);
	__property TcxMCListBoxReportLink* ReportLink = {read=GetReportLink};
public:
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TcxfmMCListBoxDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxfmMCListBoxDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxfmMCListBoxDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define dxDefaultMCListBoxOptions (System::Set<TcxMCListBoxPaintOption, TcxMCListBoxPaintOption::mclbpoBorder, TcxMCListBoxPaintOption::mclbpoColumnHeaders> () << TcxMCListBoxPaintOption::mclbpoBorder << TcxMCListBoxPaintOption::mclbpoHorzLines << TcxMCListBoxPaintOption::mclbpoVertLines << TcxMCListBoxPaintOption::mclbpoColumnHeaders )
}	/* namespace Dxpscxmclistboxlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXMCLISTBOXLNK)
using namespace Dxpscxmclistboxlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxmclistboxlnkHPP
