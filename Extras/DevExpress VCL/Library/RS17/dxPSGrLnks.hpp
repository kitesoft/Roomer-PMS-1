// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSGrLnks.pas' rev: 24.00 (Win32)

#ifndef DxpsgrlnksHPP
#define DxpsgrlnksHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Grids.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsgrlnks
{
//-- type declarations -------------------------------------------------------
enum TdxGridPaintOption : unsigned char { gpoBorder, gpoHorzLines, gpoVertLines, gpoFixedHorzLines, gpoFixedVertLines };

typedef System::Set<TdxGridPaintOption, TdxGridPaintOption::gpoBorder, TdxGridPaintOption::gpoFixedVertLines>  TdxGridPaintOptions;

class DELPHICLASS TCustomdxGridReportLink;
class PASCALIMPLEMENTATION TCustomdxGridReportLink : public Dxpsbasegridlnk::TAbstractdxGridReportLink
{
	typedef Dxpsbasegridlnk::TAbstractdxGridReportLink inherited;
	
private:
	TdxGridPaintOptions FOptions;
	Vcl::Grids::TCustomGrid* __fastcall GetCustomGrid(void);
	TdxGridPaintOptions __fastcall GetOptions(void);
	void __fastcall SetOptions(TdxGridPaintOptions Value);
	
protected:
	int FSourceFontIndex;
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual int __fastcall GetColCount(void);
	virtual int __fastcall GetFixedColCount(void);
	virtual int __fastcall GetFixedRowCount(void);
	virtual int __fastcall GetRowCount(void);
	virtual System::Types::TRect __fastcall GetSelectionRect(void);
	virtual System::Uitypes::TColor __fastcall GetSourceCellColor(int ACol, int ARow);
	virtual Dxpscore::TdxCellEdgeMode __fastcall GetSourceCellEdgeMode(int ACol, int ARow);
	virtual Vcl::Graphics::TFont* __fastcall GetSourceCellFont(int ACol, int ARow);
	virtual int __fastcall GetSourceCellFontIndex(int ACol, int ARow);
	virtual bool __fastcall GetSourceCellTransparent(int ACol, int ARow);
	virtual int __fastcall GetSourceColWidth(int ACol);
	virtual int __fastcall GetSourceRowHeight(int ARow);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawFixedHorzLines(void);
	virtual bool __fastcall IsDrawFixedVertLines(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual bool __fastcall IsDrawVertLines(void);
	virtual void __fastcall PrepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	__property Vcl::Grids::TCustomGrid* CustomGrid = {read=GetCustomGrid};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property AutoWidth = {default=0};
	__property DrawMode = {default=0};
	__property Effects3D = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property FixedColor = {default=-16777201};
	__property FixedFont;
	__property FixedTransparent = {default=0};
	__property GridLineColor = {default=0};
	__property HeadersOnEveryPage = {default=0};
	__property IncludeFixed = {default=1};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property OnlySelected = {default=0};
	__property TdxGridPaintOptions Options = {read=GetOptions, write=SetOptions, default=31};
	__property Soft3D = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
public:
	/* TAbstractdxGridReportLink.Create */ inline __fastcall virtual TCustomdxGridReportLink(System::Classes::TComponent* AOwner) : Dxpsbasegridlnk::TAbstractdxGridReportLink(AOwner) { }
	/* TAbstractdxGridReportLink.Destroy */ inline __fastcall virtual ~TCustomdxGridReportLink(void) { }
	
};


typedef void __fastcall (__closure *TdxCustomDrawItemEvent)(Dxpscore::TBasedxReportLink* Sender, int Index, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, System::UnicodeString &AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, bool &ADone);

class DELPHICLASS TdxCustomListBoxReportLink;
class PASCALIMPLEMENTATION TdxCustomListBoxReportLink : public Dxpsbasegridlnk::TAbstractdxGridReportLink
{
	typedef Dxpsbasegridlnk::TAbstractdxGridReportLink inherited;
	
private:
	bool FCustomDrawFontChanged;
	bool FIsWidthAssigned;
	Vcl::Graphics::TFont* FSaveFont;
	Cxdrawtextutils::TcxTextAlignX FTextAlignX;
	Cxdrawtextutils::TcxTextAlignY FTextAlignY;
	int FWidth;
	TdxCustomDrawItemEvent FOnCustomDrawItem;
	int __fastcall GetWidth(void);
	bool __fastcall IsWidthStored(void);
	void __fastcall SetTextAlignX(Cxdrawtextutils::TcxTextAlignX Value);
	void __fastcall SetTextAlignY(Cxdrawtextutils::TcxTextAlignY Value);
	void __fastcall SetWidth(int Value);
	void __fastcall CustomDrawFontChanged(System::TObject* Sender);
	
protected:
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABoundsRect, const System::Types::TRect &AClientRect, bool &ADone);
	virtual void __fastcall DoCustomDrawItem(int Index, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABoundsRect, const System::Types::TRect &AClientRect, System::UnicodeString &AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, bool &ADone);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* AItem);
	virtual int __fastcall GetColCount(void);
	virtual int __fastcall GetRowCount(void);
	virtual Dxpscore::TdxCellSides __fastcall GetCellSides(int ACol, int ARow);
	virtual System::UnicodeString __fastcall GetCellText(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetCellTextAlignX(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetCellTextAlignY(int ACol, int ARow);
	virtual int __fastcall GetSourceColWidth(int ACol);
	virtual int __fastcall GetSourceRowHeight(int ARow);
	virtual int __fastcall GetSelectedColCount(void);
	virtual int __fastcall GetSelectedRowCount(void);
	virtual bool __fastcall HasSelection(void);
	virtual bool __fastcall HasSelectionInRow(int ARow);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual bool __fastcall IsSelectedCell(int ACol, int ARow);
	virtual bool __fastcall IsSelectedRow(int ARow);
	virtual Vcl::Stdctrls::TCustomListBox* __fastcall GetCustomListBox(void);
	__property Vcl::Stdctrls::TCustomListBox* CustomListBox = {read=GetCustomListBox};
	
public:
	__fastcall virtual TdxCustomListBoxReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomListBoxReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual int __fastcall DefaultWidth(void);
	__property AutoWidth = {default=0};
	__property DrawMode = {default=0};
	__property EndEllipsis = {default=0};
	__property GridLineColor = {default=0};
	__property OnlySelected = {default=0};
	__property SupportedCustomDraw = {default=0};
	__property Cxdrawtextutils::TcxTextAlignX TextAlignX = {read=FTextAlignX, write=SetTextAlignX, default=0};
	__property Cxdrawtextutils::TcxTextAlignY TextAlignY = {read=FTextAlignY, write=SetTextAlignY, default=1};
	__property int Width = {read=GetWidth, write=SetWidth, stored=IsWidthStored, nodefault};
	__property TdxCustomDrawItemEvent OnCustomDrawItem = {read=FOnCustomDrawItem, write=FOnCustomDrawItem};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxGridPaintOptions dxDefaultGridPaintOptions;
static const System::Word dxDefaultListBoxWidth = System::Word(0x190);
}	/* namespace Dxpsgrlnks */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSGRLNKS)
using namespace Dxpsgrlnks;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsgrlnksHPP
