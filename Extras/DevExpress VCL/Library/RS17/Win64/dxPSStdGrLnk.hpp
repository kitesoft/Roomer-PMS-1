// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSStdGrLnk.pas' rev: 24.00 (Win64)

#ifndef DxpsstdgrlnkHPP
#define DxpsstdgrlnkHPP

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
#include <Vcl.Grids.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.CheckLst.hpp>	// Pascal unit
#include <dxPSRes.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGrLnks.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsstdgrlnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStddxGridReportLink;
class PASCALIMPLEMENTATION TStddxGridReportLink : public Dxpsgrlnks::TCustomdxGridReportLink
{
	typedef Dxpsgrlnks::TCustomdxGridReportLink inherited;
	
private:
	Vcl::Graphics::TFont* FSaveFont;
	bool FCustomDrawFontChanged;
	void __fastcall CustomDrawFontChanged(System::TObject* Sender);
	
protected:
	__classmethod virtual bool __fastcall IsDrawGridLink();
	__classmethod virtual bool __fastcall IsStringGridLink();
	
public:
	__fastcall virtual TStddxGridReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TStddxGridReportLink(void);
};


typedef void __fastcall (__closure *TdxCustomDrawTextCellEvent)(Dxpscore::TBasedxReportLink* Sender, int ACol, int ARow, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, System::UnicodeString &AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, bool &ADone);

class DELPHICLASS TdxStringGridReportLink;
class PASCALIMPLEMENTATION TdxStringGridReportLink : public TStddxGridReportLink
{
	typedef TStddxGridReportLink inherited;
	
private:
	Cxdrawtextutils::TcxTextAlignX FTextAlignX;
	Cxdrawtextutils::TcxTextAlignY FTextAlignY;
	TdxCustomDrawTextCellEvent FOnCustomDrawCell;
	Vcl::Grids::TStringGrid* __fastcall GetStringGrid(void);
	void __fastcall SetTextAlignX(Cxdrawtextutils::TcxTextAlignX Value);
	void __fastcall SetTextAlignY(Cxdrawtextutils::TcxTextAlignY Value);
	
protected:
	virtual void __fastcall InternalRestoreDefaults(void);
	__classmethod virtual bool __fastcall IsStringGridLink();
	virtual System::UnicodeString __fastcall GetCellText(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetCellTextAlignX(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetCellTextAlignY(int ACol, int ARow);
	virtual void __fastcall SetDrawMode(Dxpsbasegridlnk::TdxGridDrawMode Value);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);
	virtual void __fastcall DoCustomDrawCell(int ACol, int ARow, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, System::UnicodeString &AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, bool &ADone);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Vcl::Grids::TStringGrid* StringGrid = {read=GetStringGrid};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property DrawMode = {default=0};
	__property Effects3D = {default=0};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property FixedColor = {default=-16777201};
	__property FixedFont;
	__property FixedTransparent = {default=0};
	__property Font;
	__property GridLineColor = {default=0};
	__property HeadersOnEveryPage = {default=0};
	__property IncludeFixed = {default=1};
	__property Multiline = {default=0};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property OnlySelected = {default=0};
	__property Options = {default=31};
	__property RowAutoHeight = {default=0};
	__property ScaleFonts = {default=1};
	__property Soft3D = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Cxdrawtextutils::TcxTextAlignX TextAlignX = {read=FTextAlignX, write=SetTextAlignX, default=0};
	__property Cxdrawtextutils::TcxTextAlignY TextAlignY = {read=FTextAlignY, write=SetTextAlignY, default=1};
	__property Transparent = {default=1};
	__property UseCustomPageBreaks = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property TdxCustomDrawTextCellEvent OnCustomDrawCell = {read=FOnCustomDrawCell, write=FOnCustomDrawCell};
	__property OnGetCustomPageBreaks;
	__property OnInitializeItem;
public:
	/* TStddxGridReportLink.Create */ inline __fastcall virtual TdxStringGridReportLink(System::Classes::TComponent* AOwner) : TStddxGridReportLink(AOwner) { }
	/* TStddxGridReportLink.Destroy */ inline __fastcall virtual ~TdxStringGridReportLink(void) { }
	
};


typedef void __fastcall (__closure *TdxCustomDrawCellEvent)(Dxpscore::TBasedxReportLink* Sender, int ACol, int ARow, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect);

typedef void __fastcall (__closure *TdxCustomDrawCellExEvent)(Dxpscore::TBasedxReportLink* Sender, int ACol, int ARow, Vcl::Graphics::TCanvas* ACanvas, Vcl::Graphics::TFont* AFont, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);

class DELPHICLASS TdxDrawGridReportLink;
class PASCALIMPLEMENTATION TdxDrawGridReportLink : public TStddxGridReportLink
{
	typedef TStddxGridReportLink inherited;
	
private:
	bool FDefaultDrawing;
	TdxCustomDrawCellEvent FOnCustomDrawCell;
	TdxCustomDrawCellExEvent FOnCustomDrawCellEx;
	Vcl::Grids::TDrawGrid* __fastcall GetDrawGrid(void);
	void __fastcall SetDefaultDrawing(bool Value);
	
protected:
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual System::UnicodeString __fastcall GetCellText(int ACol, int ARow);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataItemClass(int ACol, int ARow = 0x0);
	virtual void __fastcall SetDrawMode(Dxpsbasegridlnk::TdxGridDrawMode Value);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);
	virtual void __fastcall DoCustomDrawCell(int ACol, int ARow, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect);
	virtual void __fastcall DoCustomDrawCellEx(int ACol, int ARow, Vcl::Graphics::TCanvas* ACanvas, Vcl::Graphics::TFont* AFont, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect);
	__classmethod virtual bool __fastcall IsDrawGridLink();
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Serializable();
	__property Vcl::Grids::TDrawGrid* DrawGrid = {read=GetDrawGrid};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property bool DefaultDrawing = {read=FDefaultDrawing, write=SetDefaultDrawing, default=1};
	__property DrawMode = {default=0};
	__property Effects3D = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property FixedColor = {default=-16777201};
	__property FixedFont;
	__property FixedTransparent = {default=0};
	__property Font;
	__property GridLineColor = {default=0};
	__property HeadersOnEveryPage = {default=0};
	__property IncludeFixed = {default=1};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property OnlySelected = {default=0};
	__property Options = {default=31};
	__property ScaleFonts = {default=1};
	__property Soft3D = {default=1};
	__property SupportedCustomDraw = {default=1};
	__property Transparent = {default=1};
	__property UseCustomPageBreaks = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property TdxCustomDrawCellEvent OnCustomDrawCell = {read=FOnCustomDrawCell, write=FOnCustomDrawCell};
	__property TdxCustomDrawCellExEvent OnCustomDrawCellEx = {read=FOnCustomDrawCellEx, write=FOnCustomDrawCellEx};
	__property OnGetCustomPageBreaks;
	__property OnInitializeItem;
public:
	/* TStddxGridReportLink.Create */ inline __fastcall virtual TdxDrawGridReportLink(System::Classes::TComponent* AOwner) : TStddxGridReportLink(AOwner) { }
	/* TStddxGridReportLink.Destroy */ inline __fastcall virtual ~TdxDrawGridReportLink(void) { }
	
};


class DELPHICLASS TdxGridReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxGridReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Cxpc::TcxTabSheet* tshColor;
	Cxpc::TcxTabSheet* tshFont;
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxpc::TcxTabSheet* tshBehaviors;
	Vcl::Extctrls::TImage* Image3;
	Vcl::Extctrls::TImage* Image8;
	Vcl::Extctrls::TImage* imgGrid;
	Vcl::Extctrls::TImage* Image1;
	Vcl::Extctrls::TImage* imgMiscellaneous;
	Cxlabel::TcxLabel* lblPreview;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblOnEveryPage;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxlabel::TcxLabel* lblDrawMode;
	Cxlabel::TcxLabel* lblSelection;
	Cxlabel::TcxLabel* lblLookAndFeel;
	Cxlabel::TcxLabel* lblMiscellaneous;
	Cxcheckbox::TcxCheckBox* chbxShowVertLines;
	Cxcheckbox::TcxCheckBox* chbxShowFixedHorzLines;
	Cxcheckbox::TcxCheckBox* chbxShowFixedVertLines;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxShowHorzLines;
	Cxcheckbox::TcxCheckBox* chbxFixedRowsOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxFixedTransparent;
	Cxcheckbox::TcxCheckBox* chbxIncludeFixed;
	Cxcheckbox::TcxCheckBox* chbxOnlySelected;
	Cxcheckbox::TcxCheckBox* chbxUse3DEffects;
	Cxcheckbox::TcxCheckBox* chbxUseSoft3D;
	Cxcheckbox::TcxCheckBox* chbxRowAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxbuttons::TcxButton* btnFont;
	Cxbuttons::TcxButton* btnFixedFont;
	Cxbuttons::TcxButton* btnEvenFont;
	Cxtextedit::TcxTextEdit* edFont;
	Cxtextedit::TcxTextEdit* edFixedFont;
	Cxtextedit::TcxTextEdit* edEvenFont;
	Cxcolorcombobox::TcxColorComboBox* ccbxGridLineColor;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxlabel::TcxLabel* stFixedTransparent;
	Cxlabel::TcxLabel* stTransparent;
	Cxlabel::TcxLabel* lblColor;
	Cxlabel::TcxLabel* lblEvenColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxEvenColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxlabel::TcxLabel* lblFixedColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxFixedColor;
	Cxlabel::TcxLabel* lblGridLineSeparator;
	Cximagecombobox::TcxImageComboBox* cbxDrawMode;
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall btnFontClick(System::TObject* Sender);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	void __fastcall chbxOnlySelectedClick(System::TObject* Sender);
	void __fastcall chbxIncludeFixedClick(System::TObject* Sender);
	void __fastcall chbxTransparentClick(System::TObject* Sender);
	void __fastcall lblColorClick(System::TObject* Sender);
	void __fastcall chbxRowAutoHeightClick(System::TObject* Sender);
	void __fastcall chbxFixedRowsOnEveryPageClick(System::TObject* Sender);
	void __fastcall chbxShowBordersClick(System::TObject* Sender);
	void __fastcall cbxDrawModeClick(System::TObject* Sender);
	void __fastcall chbxUse3DEffectsClick(System::TObject* Sender);
	void __fastcall chbxUseSoft3DClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall chbxAutoWidthClick(System::TObject* Sender);
	void __fastcall stFixedTransparentClick(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	
private:
	Vcl::Controls::TCustomControl* FPreviewBox;
	TStddxGridReportLink* __fastcall GetReportLink(void);
	void __fastcall CreateControls(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &message);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	
public:
	__fastcall virtual TdxGridReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__property TStddxGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TdxGridReportLinkDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxGridReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxGridReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsstdgrlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSSTDGRLNK)
using namespace Dxpsstdgrlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsstdgrlnkHPP
