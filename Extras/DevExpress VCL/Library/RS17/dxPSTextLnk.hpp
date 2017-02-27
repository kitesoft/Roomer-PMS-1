// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSTextLnk.pas' rev: 24.00 (Win32)

#ifndef DxpstextlnkHPP
#define DxpstextlnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpstextlnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxMemoLineItem;
class PASCALIMPLEMENTATION TdxMemoLineItem : public Dxpscore::TdxReportCellString
{
	typedef Dxpscore::TdxReportCellString inherited;
	
public:
	virtual unsigned __fastcall GetDTFormat(void);
public:
	/* TdxReportCellText.Create */ inline __fastcall virtual TdxMemoLineItem(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCellString(AParent) { }
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxMemoLineItem(void) { }
	
};


class DELPHICLASS TdxCustomTextReportLink;
typedef void __fastcall (__closure *TdxTextReportLinkCustomDrawRowEvent)(TdxCustomTextReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxTextReportLinkInitializeRowEvent)(TdxCustomTextReportLink* Sender, Dxpscore::TdxReportCellString* AnItem);

class DELPHICLASS TdxfmTextReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxCustomTextReportLink : public Dxpscore::TBasedxReportLink
{
	typedef Dxpscore::TBasedxReportLink inherited;
	
private:
	Cxdrawtextutils::TcxTextAlignX FAlignment;
	System::Classes::TList* FDelimiters;
	int FFontIndex;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* FScreenCanvas;
	bool FSupportedCustomDraw;
	int FTextRowHeight;
	double FTextRowSpacing;
	TdxTextReportLinkCustomDrawRowEvent FOnCustomDrawRow;
	TdxTextReportLinkInitializeRowEvent FOnInitializeRow;
	int __fastcall GetDelimiter(int Index);
	int __fastcall GetDelimiterCount(void);
	TdxfmTextReportLinkDesignWindow* __fastcall GetDesignWindow(void);
	System::Types::TRect __fastcall GetTextBounds(void);
	bool __fastcall IsTextRowSpacingStored(void);
	void __fastcall SetAlignment(Cxdrawtextutils::TcxTextAlignX Value);
	void __fastcall SetOnCustomDrawRow(TdxTextReportLinkCustomDrawRowEvent Value);
	void __fastcall SetSupportedCustomDraw(bool Value);
	void __fastcall SetTextRowSpacing(double Value);
	
protected:
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall ConvertCoords(void);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABoundsRect, const System::Types::TRect &AClientRect, bool &ADone);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	virtual void __fastcall MakeDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	void __fastcall AddDelimiter(int Value)/* overload */;
	void __fastcall AddDelimiter(Dxpscore::TdxReportVisualItem* AItem)/* overload */;
	void __fastcall AdjustHostBounds(Dxpscore::TdxReportCell* AHost);
	virtual void __fastcall CalculateTextRowHeight(void);
	virtual Dxpscore::TdxReportCell* __fastcall CreateHost(Dxpscore::TdxReportCells* AReportCells);
	virtual Dxpscore::TdxReportCellString* __fastcall CreateItem(Dxpscore::TdxReportCell* AParent, const Cxdrawtextutils::TcxTextRow &ATextRow);
	void __fastcall CreateItems(Dxpscore::TdxReportCell* AHost);
	virtual int __fastcall GetTextRowBoundsWidth(void);
	virtual void __fastcall InitializeHost(Dxpscore::TdxReportCell* AHost);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportCellString* AItem, const System::UnicodeString AText);
	virtual void __fastcall DoConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall PrepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall UnprepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual unsigned __fastcall GetTextFormat(void);
	virtual Dxpscore::TdxReportCellStringClass __fastcall GetTextItemClass(void);
	DYNAMIC void __fastcall DoCustomDrawRow(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoInitializeRow(Dxpscore::TdxReportCellString* AnItem);
	__property int DelimiterCount = {read=GetDelimiterCount, nodefault};
	__property System::Classes::TList* DelimiterList = {read=FDelimiters};
	__property int Delimiters[int Index] = {read=GetDelimiter};
	__property int FontIndex = {read=FFontIndex, nodefault};
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ScreenCanvas = {read=FScreenCanvas};
	__property System::Types::TRect TextBounds = {read=GetTextBounds};
	__property unsigned TextFormat = {read=GetTextFormat, nodefault};
	__property int TextRowBoundsWidth = {read=GetTextRowBoundsWidth, nodefault};
	__property int TextRowHeight = {read=FTextRowHeight, write=FTextRowHeight, nodefault};
	
public:
	__fastcall virtual TdxCustomTextReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomTextReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
	virtual bool __fastcall DataProviderPresent(void);
	__property Cxdrawtextutils::TcxTextAlignX Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property Color = {default=16777215};
	__property TdxfmTextReportLinkDesignWindow* DesignWindow = {read=GetDesignWindow};
	__property Font;
	__property ScaleFonts = {default=1};
	__property bool SupportedCustomDraw = {read=FSupportedCustomDraw, write=SetSupportedCustomDraw, default=0};
	__property System::UnicodeString Text = {read=GetText};
	__property double TextRowSpacing = {read=FTextRowSpacing, write=SetTextRowSpacing, stored=IsTextRowSpacingStored};
	__property Transparent = {default=1};
	__property UseHorzDelimiters = {default=1};
	__property TdxTextReportLinkCustomDrawRowEvent OnCustomDrawRow = {read=FOnCustomDrawRow, write=SetOnCustomDrawRow};
	__property TdxTextReportLinkInitializeRowEvent OnInitializeRow = {read=FOnInitializeRow, write=FOnInitializeRow};
};


class DELPHICLASS TdxCustomStringsReportLink;
class PASCALIMPLEMENTATION TdxCustomStringsReportLink : public TdxCustomTextReportLink
{
	typedef TdxCustomTextReportLink inherited;
	
protected:
	virtual System::Classes::TStrings* __fastcall GetStrings(void) = 0 ;
	virtual System::UnicodeString __fastcall GetText(void);
	virtual unsigned __fastcall GetTextFormat(void);
	
public:
	__property System::Classes::TStrings* Strings = {read=GetStrings};
public:
	/* TdxCustomTextReportLink.Create */ inline __fastcall virtual TdxCustomStringsReportLink(System::Classes::TComponent* AOwner) : TdxCustomTextReportLink(AOwner) { }
	/* TdxCustomTextReportLink.Destroy */ inline __fastcall virtual ~TdxCustomStringsReportLink(void) { }
	
};


class DELPHICLASS TdxTextReportLink;
class PASCALIMPLEMENTATION TdxTextReportLink : public TdxCustomStringsReportLink
{
	typedef TdxCustomStringsReportLink inherited;
	
private:
	System::Classes::TStrings* FStrings;
	void __fastcall StringsChanged(System::TObject* Sender);
	
protected:
	virtual System::Classes::TStrings* __fastcall GetStrings(void);
	virtual void __fastcall SetStrings(System::Classes::TStrings* Value);
	void __fastcall SetText(const System::UnicodeString Value);
	
public:
	__fastcall virtual TdxTextReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxTextReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Text = {write=SetText, default=0};
	
__published:
	__property Alignment = {default=0};
	__property Color = {default=16777215};
	__property Font;
	__property ScaleFonts = {default=1};
	__property Strings = {write=SetStrings};
	__property TextRowSpacing = {default=0};
	__property SupportedCustomDraw = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property Transparent = {default=1};
	__property OnCustomDrawRow;
	__property OnInitializeRow;
};


class DELPHICLASS TdxCustomMemoReportLink;
class PASCALIMPLEMENTATION TdxCustomMemoReportLink : public TdxCustomStringsReportLink
{
	typedef TdxCustomStringsReportLink inherited;
	
protected:
	virtual int __fastcall GetTextRowBoundsWidth(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual Vcl::Stdctrls::TCustomMemo* __fastcall GetCustomMemo(void);
	virtual System::Classes::TStrings* __fastcall GetStrings(void);
	__property Vcl::Stdctrls::TCustomMemo* CustomMemo = {read=GetCustomMemo};
	
__published:
	__property Alignment = {default=0};
	__property Color = {default=16777215};
	__property Font;
	__property ScaleFonts = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property TextRowSpacing = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property Transparent = {default=1};
	__property OnCustomDrawRow;
	__property OnInitializeRow;
public:
	/* TdxCustomTextReportLink.Create */ inline __fastcall virtual TdxCustomMemoReportLink(System::Classes::TComponent* AOwner) : TdxCustomStringsReportLink(AOwner) { }
	/* TdxCustomTextReportLink.Destroy */ inline __fastcall virtual ~TdxCustomMemoReportLink(void) { }
	
};


class DELPHICLASS TdxMemoReportLink;
class PASCALIMPLEMENTATION TdxMemoReportLink : public TdxCustomMemoReportLink
{
	typedef TdxCustomMemoReportLink inherited;
	
private:
	Vcl::Stdctrls::TMemo* __fastcall GetMemo(void);
	
public:
	__property Vcl::Stdctrls::TMemo* Memo = {read=GetMemo};
public:
	/* TdxCustomTextReportLink.Create */ inline __fastcall virtual TdxMemoReportLink(System::Classes::TComponent* AOwner) : TdxCustomMemoReportLink(AOwner) { }
	/* TdxCustomTextReportLink.Destroy */ inline __fastcall virtual ~TdxMemoReportLink(void) { }
	
};


class PASCALIMPLEMENTATION TdxfmTextReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Vcl::Extctrls::TPanel* pnlPreview;
	Vcl::Extctrls::TPaintBox* pbxPreview;
	Vcl::Controls::TImageList* ilAlignments;
	Cxlabel::TcxLabel* lblLineSpacing;
	Cxlabel::TcxLabel* lblAlignment;
	Cxlabel::TcxLabel* lblPreview;
	Cxspinedit::TcxSpinEdit* seLineSpacing;
	Cxdropdownedit::TcxComboBox* cbxAlignment;
	Cxlabel::TcxLabel* Bevel1;
	Cxbuttons::TcxButton* btnFont;
	Cxtextedit::TcxTextEdit* edFont;
	void __fastcall btnFontClick(System::TObject* Sender);
	void __fastcall cbxAlignmentClick(System::TObject* Sender);
	void __fastcall cbxAlignmentPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall LineSpacingChanged(System::TObject* Sender);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	
private:
	TdxCustomTextReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall UpdatePreview(void);
	
public:
	__fastcall virtual TdxfmTextReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__property TdxCustomTextReportLink* ReportLink = {read=GetReportLink};
public:
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TdxfmTextReportLinkDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmTextReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmTextReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpstextlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSTEXTLNK)
using namespace Dxpstextlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpstextlnkHPP
