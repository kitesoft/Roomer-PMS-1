// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxPivotGridLnk.pas' rev: 24.00 (Win32)

#ifndef DxpscxpivotgridlnkHPP
#define DxpscxpivotgridlnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxPSUtl.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxDBPivotGrid.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxPivotGrid.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxpivotgridlnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPivotGridReportLinkOptionsExpanding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridReportLinkOptionsExpanding : public Dxpscxcommon::TdxCustomReportLinkOptionsExpanding
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsExpanding inherited;
	
private:
	bool FAutoExpandColumns;
	bool FAutoExpandRows;
	void __fastcall SetAutoExpandColumns(bool AValue);
	void __fastcall SetAutoExpandRows(bool AValue);
	
protected:
	virtual void __fastcall AssignToPivot(Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid);
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool AutoExpandColumns = {read=FAutoExpandColumns, write=SetAutoExpandColumns, default=0};
	__property bool AutoExpandRows = {read=FAutoExpandRows, write=SetAutoExpandRows, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxPivotGridReportLinkOptionsExpanding(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsExpanding(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxPivotGridReportLinkOptionsExpanding(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridReportLinkOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridReportLinkOptionsView : public Dxpscxcommon::TdxCustomReportLinkOptionsView
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsView inherited;
	
private:
	bool FBorders;
	bool FColumnFields;
	bool FDataFields;
	bool FExpandButtons;
	bool FFilterFields;
	Cxcustompivotgrid::TcxPivotGridLines FGridLines;
	Cxcustompivotgrid::TcxPivotGridPrefilterVisible FPrefilter;
	bool FRowFields;
	void __fastcall SetBorders(bool AValue);
	void __fastcall SetColumnFields(bool AValue);
	void __fastcall SetDataFields(bool AValue);
	void __fastcall SetExpandButtons(bool AValue);
	void __fastcall SetFilterFields(bool AValue);
	void __fastcall SetGridLines(Cxcustompivotgrid::TcxPivotGridLines AValue);
	void __fastcall SetPrefilter(Cxcustompivotgrid::TcxPivotGridPrefilterVisible AValue);
	void __fastcall SetRowFields(bool AValue);
	
protected:
	virtual void __fastcall AssignToPivot(Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid);
	void __fastcall SetBoolValue(bool &AField, bool ANewValue);
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool Borders = {read=FBorders, write=SetBorders, default=1};
	__property bool ColumnFields = {read=FColumnFields, write=SetColumnFields, default=1};
	__property bool DataFields = {read=FDataFields, write=SetDataFields, default=1};
	__property bool ExpandButtons = {read=FExpandButtons, write=SetExpandButtons, default=1};
	__property bool FilterFields = {read=FFilterFields, write=SetFilterFields, default=0};
	__property Cxcustompivotgrid::TcxPivotGridLines GridLines = {read=FGridLines, write=SetGridLines, default=3};
	__property Cxcustompivotgrid::TcxPivotGridPrefilterVisible Prefilter = {read=FPrefilter, write=SetPrefilter, default=2};
	__property bool RowFields = {read=FRowFields, write=SetRowFields, default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxPivotGridReportLinkOptionsView(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsView(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxPivotGridReportLinkOptionsView(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridReportLinkOptionsFormatting;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridReportLinkOptionsFormatting : public Dxpscxcommon::TdxCustomReportLinkOptionsFormatting
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsFormatting inherited;
	
private:
	bool FSuppressContentColoration;
	void __fastcall SetSuppressContentColoration(bool AValue);
	
protected:
	virtual void __fastcall AssignToPivot(Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid);
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool SuppressContentColoration = {read=FSuppressContentColoration, write=SetSuppressContentColoration, default=0};
	__property UseLookAndFeelColors = {default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxPivotGridReportLinkOptionsFormatting(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsFormatting(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxPivotGridReportLinkOptionsFormatting(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridReportLinkOptionsOnEveryPage;
class DELPHICLASS TcxPivotGridReportLink;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridReportLinkOptionsOnEveryPage : public Dxpscxcommon::TdxCustomReportLinkOptions
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptions inherited;
	
private:
	bool FColumnHeaders;
	bool FFilterBar;
	bool FRowHeaders;
	TcxPivotGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetColumnHeaders(bool AValue);
	void __fastcall SetFilterBar(bool AValue);
	void __fastcall SetRowHeaders(bool AValue);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxPivotGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool ColumnHeaders = {read=FColumnHeaders, write=SetColumnHeaders, default=0};
	__property bool FilterBar = {read=FFilterBar, write=SetFilterBar, default=1};
	__property bool RowHeaders = {read=FRowHeaders, write=SetRowHeaders, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxPivotGridReportLinkOptionsOnEveryPage(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxPivotGridReportLinkOptionsOnEveryPage(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxPivotGridReportLinkOptionsOnEveryPageClass;

class DELPHICLASS TcxPivotGridReportLinkStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridReportLinkStyles : public Dxpscxcommon::TdxCustomReportLinkStyles
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyles inherited;
	
private:
	HIDESBASE TcxPivotGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual void __fastcall AssignToPivot(Cxcustompivotgrid::TcxCustomPivotGrid* AFromGrid, Cxcustompivotgrid::TcxCustomPivotGrid* ADestGrid, bool AUsePivotStyles);
	virtual int __fastcall DesignerTabIndex(void);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__classmethod virtual System::UnicodeString __fastcall GetStyleCaption(int AnIndex);
	virtual int __fastcall GetStyleIndexByCaption(const System::UnicodeString Caption);
	bool __fastcall UsePivotStyles(void);
	
public:
	__fastcall virtual TcxPivotGridReportLinkStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetColumnHeaderParams(Cxcustompivotgrid::TcxPivotGridViewDataItem* AColumn);
	Cxgraphics::TcxViewParams __fastcall GetContentParams(Cxcustompivotgrid::TcxPivotGridDataCellViewInfo* ACell);
	Cxgraphics::TcxViewParams __fastcall GetFieldHeaderParams(Cxcustompivotgrid::TcxPivotGridField* AField);
	Cxgraphics::TcxViewParams __fastcall GetHeaderBackgroundParams(Cxcustompivotgrid::TcxPivotGridFieldArea AArea);
	Cxgraphics::TcxViewParams __fastcall GetPrefilterParams(void);
	Cxgraphics::TcxViewParams __fastcall GetRowHeaderParams(Cxcustompivotgrid::TcxPivotGridViewDataItem* ARow);
	__property TcxPivotGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property Cxstyles::TcxStyle* ColumnHeader = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* FieldHeader = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* HeaderBackground = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* Prefilter = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* RowHeader = {read=GetValue, write=SetValue, index=5};
	__property StyleSheet;
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxPivotGridReportLinkStyles(void) { }
	
private:
	void *__IcxPivotGridBaseStyles;	/* Cxcustompivotgrid::IcxPivotGridBaseStyles */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {60482E74-4425-4CF0-86A3-818C486E895F}
	operator Cxcustompivotgrid::_di_IcxPivotGridBaseStyles()
	{
		Cxcustompivotgrid::_di_IcxPivotGridBaseStyles intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcustompivotgrid::IcxPivotGridBaseStyles*(void) { return (Cxcustompivotgrid::IcxPivotGridBaseStyles*)&__IcxPivotGridBaseStyles; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxPivotGridReportLinkStylesClass;

class DELPHICLASS TcxPivotGridReportLinkStyleSheet;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridReportLinkStyleSheet : public Dxpscxcommon::TdxCustomReportLinkStyleSheet
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyleSheet inherited;
	
private:
	TcxPivotGridReportLinkStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxPivotGridReportLinkStyles* AValue);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxPivotGridReportLinkStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxPivotGridReportLinkStyleSheet(System::Classes::TComponent* AOwner) : Dxpscxcommon::TdxCustomReportLinkStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxPivotGridReportLinkStyleSheet(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxPivotGridReportLinkCustomDrawDataCellEventEvent)(TcxPivotGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridReportLinkCustomDrawFieldHeaderCellEvent)(TcxPivotGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCell* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridReportLinkCustomDrawGroupHeaderCellEvent)(TcxPivotGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCell* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridReportLinkCustomDrawHeaderBackgroundEvent)(TcxPivotGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCell* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridReportLinkCustomDrawPrefilterEvent)(TcxPivotGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCellText* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridReportLinkInitializeDataCellEvent)(TcxPivotGridReportLink* Sender, Cxcustompivotgrid::TcxPivotGridDataCellViewInfo* ACell, Dxpscore::TAbstractdxReportCellData* AnItem);

typedef void __fastcall (__closure *TcxPivotGridReportLinkInitializeFieldHeaderCellEvent)(TcxPivotGridReportLink* Sender, Cxcustompivotgrid::TcxPivotGridFieldHeaderCellViewInfo* ACell, Dxpscore::TdxReportCell* AnItem);

typedef void __fastcall (__closure *TcxPivotGridReportLinkInitializeGroupHeaderCellEvent)(TcxPivotGridReportLink* Sender, Cxcustompivotgrid::TcxPivotGridHeaderCellViewInfo* ACell, Dxpscore::TdxReportCell* AnItem);

typedef void __fastcall (__closure *TcxPivotGridReportLinkInitializeHeaderBackgroundEvent)(TcxPivotGridReportLink* Sender, Cxcustompivotgrid::TcxPivotGridHeaderBackgroundCellViewInfo* ACell, Dxpscore::TdxReportCell* AnItem);

typedef void __fastcall (__closure *TcxPivotGridReportLinkInitializePrefilterEvent)(TcxPivotGridReportLink* Sender, Cxcustompivotgrid::TcxPivotGridPrefilterViewInfo* ACell, Dxpscore::TdxReportCellText* AnItem);

class DELPHICLASS TcxfmPivotGridReportLinkDesignWindow;
class PASCALIMPLEMENTATION TcxPivotGridReportLink : public Dxpscxcommon::TdxCustomcxControlReportLink
{
	typedef Dxpscxcommon::TdxCustomcxControlReportLink inherited;
	
private:
	Dxpscore::TdxReportCell* FHostCell;
	Dxpscore::TdxReportCell* FHostHeaderCell;
	Dxpscore::TdxReportCell* FHostHeaderCornerCell;
	Dxpscore::TdxReportCell* FHostFilterBarCell;
	Dxpscore::TdxReportCell* FHostRowHeaderCell;
	System::Classes::TList* FLookAndFeelItems;
	Cxcustompivotgrid::TcxPivotGridViewInfo* FViewInfo;
	TcxPivotGridReportLinkOptionsOnEveryPage* FOptionsOnEveryPage;
	TcxPivotGridReportLinkCustomDrawDataCellEventEvent FOnCustomDrawDataCell;
	TcxPivotGridReportLinkCustomDrawFieldHeaderCellEvent FOnCustomDrawFieldHeaderCell;
	TcxPivotGridReportLinkCustomDrawGroupHeaderCellEvent FOnCustomDrawGroupHeaderCell;
	TcxPivotGridReportLinkCustomDrawHeaderBackgroundEvent FOnCustomDrawHeaderBackground;
	TcxPivotGridReportLinkCustomDrawPrefilterEvent FOnCustomDrawPrefilter;
	TcxPivotGridReportLinkInitializeDataCellEvent FOnInitializeDataCell;
	TcxPivotGridReportLinkInitializeFieldHeaderCellEvent FOnInitializeFieldHeaderCell;
	TcxPivotGridReportLinkInitializeGroupHeaderCellEvent FOnInitializeGroupHeaderCell;
	TcxPivotGridReportLinkInitializeHeaderBackgroundEvent FOnInitializeHeaderBackground;
	TcxPivotGridReportLinkInitializePrefilterEvent FOnInitializePrefilter;
	HIDESBASE TcxPivotGridReportLinkStyles* __fastcall GetActiveStyles(void);
	System::Types::TPoint __fastcall GetCellsOffset(void);
	HIDESBASE TcxfmPivotGridReportLinkDesignWindow* __fastcall GetDesignWindow(void);
	System::Uitypes::TColor __fastcall GetGridLineColor(void);
	Dxpscore::TdxReportCell* __fastcall GetHostByArea(Cxcustompivotgrid::TcxPivotGridFieldArea Area);
	TcxPivotGridReportLinkOptionsExpanding* __fastcall GetOptionsExpanding(void);
	TcxPivotGridReportLinkOptionsFormatting* __fastcall GetOptionsFormatting(void);
	TcxPivotGridReportLinkOptionsOnEveryPage* __fastcall GetOptionsOnEveryPage(void);
	TcxPivotGridReportLinkOptionsView* __fastcall GetOptionsView(void);
	TcxPivotGridReportLinkStyles* __fastcall GetStyles(void);
	Cxcustompivotgrid::TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	HIDESBASE void __fastcall SetOptionsExpanding(TcxPivotGridReportLinkOptionsExpanding* AValue);
	HIDESBASE void __fastcall SetOptionsFormatting(TcxPivotGridReportLinkOptionsFormatting* AValue);
	void __fastcall SetOptionsOnEveryPage(TcxPivotGridReportLinkOptionsOnEveryPage* AValue);
	HIDESBASE void __fastcall SetOptionsView(TcxPivotGridReportLinkOptionsView* AValue);
	HIDESBASE void __fastcall SetStyles(TcxPivotGridReportLinkStyles* AValue);
	
protected:
	virtual void __fastcall BuildReport(void);
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall ConvertCoords(void);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABoundsRect, const System::Types::TRect &AClientRect, bool &ADone);
	virtual void __fastcall DoCustomDrawDataCell(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TAbstractdxReportCellData* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawFieldHeaderCell(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCell* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawGroupHeaderCell(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCell* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawHeaderBackground(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCell* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawPrefilter(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TdxReportCellString* AItem, bool &ADone);
	virtual void __fastcall DoInitializeDataCell(Dxpscore::TAbstractdxReportCellData* AItem, Cxcustompivotgrid::TcxPivotGridDataCellViewInfo* ACell);
	virtual void __fastcall DoInitializeFieldHeaderCell(Dxpscore::TdxReportCell* AItem, Cxcustompivotgrid::TcxPivotGridFieldHeaderCellViewInfo* ACell);
	virtual void __fastcall DoInitializeGroupHeaderCell(Dxpscore::TdxReportCell* AItem, Cxcustompivotgrid::TcxPivotGridHeaderCellViewInfo* ACell);
	virtual void __fastcall DoInitializeHeaderBackground(Dxpscore::TdxReportCell* AItem, Cxcustompivotgrid::TcxPivotGridHeaderBackgroundCellViewInfo* ACell);
	virtual void __fastcall DoInitializePrefilter(Dxpscore::TdxReportCellString* AItem, Cxcustompivotgrid::TcxPivotGridPrefilterViewInfo* ACell);
	virtual bool __fastcall IdxPSCellParams_GetAutoHeight(void);
	virtual Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall IdxPSCellParams_GetCanvas(void);
	virtual bool __fastcall IdxPSCellParams_GetDisplayGraphicsAsText(void);
	virtual bool __fastcall IdxPSCellParams_GetEndEllipsis(void);
	virtual bool __fastcall IdxPSCellParams_GetFlatCheckMarks(void);
	virtual System::UnicodeString __fastcall IdxPSCellParams_GetGraphicsText(void);
	virtual bool __fastcall IdxPSCellParams_GetMultiline(void);
	virtual bool __fastcall IdxPSCellParams_GetTransparentGraphics(void);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsDrawFootersOnEveryPage(void);
	virtual bool __fastcall IsDrawHeaderCornersOnEveryPage(void);
	virtual bool __fastcall IsDrawHeadersOnEveryPage(void);
	virtual bool __fastcall IsDrawRowHeadersOnEveryPage(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	void __fastcall FormatLookAndFeelItems(void);
	Dxpscore::TdxCellEdgeMode __fastcall GetEdgeMode(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsExpandingClass __fastcall GetOptionsExpandingClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsFormattingClass __fastcall GetOptionsFormattingClass(void);
	virtual TcxPivotGridReportLinkOptionsOnEveryPageClass __fastcall GetOptionsOnEveryPageClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual bool __fastcall GetAreNativeStylesAvailable(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStylesClass __fastcall GetStylesClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheetClass __fastcall GetStyleSheetClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheet* __fastcall GetStyleSheetPrototype(void);
	virtual void __fastcall PrepareConstruct(void);
	virtual void __fastcall UnprepareConstruct(void);
	void __fastcall AddDataCell(Cxcustompivotgrid::TcxPivotGridDataCellViewInfo* ACell);
	void __fastcall AddFieldHeaderCell(Cxcustompivotgrid::TcxPivotGridFieldHeaderCellViewInfo* ACell);
	void __fastcall AddHeaderBackground(Cxcustompivotgrid::TcxPivotGridHeaderBackgroundCellViewInfo* ACell);
	void __fastcall AddHeaderCell(Cxcustompivotgrid::TcxPivotGridFieldArea Area, Cxcustompivotgrid::TcxPivotGridHeaderCellViewInfo* ACell);
	void __fastcall AddPrefilter(Cxcustompivotgrid::TcxPivotGridPrefilterViewInfo* ACell);
	Dxpscore::TdxReportCell* __fastcall CreateHeaderCell(Dxpscore::TdxReportCell* AHost, Cxcustompivotgrid::TcxPivotGridHeaderCellViewInfo* ACell, int AttributeID);
	virtual void __fastcall InitializeOptionsBeforeBuildReport(Cxcustompivotgrid::TcxPivotGridExportController* AController);
	virtual void __fastcall ProcessCreateReportItems(Cxcustompivotgrid::TcxPivotGridViewInfo* AViewInfo);
	void __fastcall RegisterLookAndFeelItem(Dxpscore::TdxReportVisualItem* AItem, Dxpscore::TdxCellEdgeStyle AEdgeStyle);
	void __fastcall SetCellViewParams(Dxpscore::TdxReportVisualItem* ACell, const Cxgraphics::TcxViewParams &AParams);
	void __fastcall SetCellViewParamsEx(Dxpscore::TdxReportVisualItem* ACell, const Dxpscxcommon::TdxReportItemViewParams &AParams);
	__property TcxPivotGridReportLinkStyles* ActiveStyles = {read=GetActiveStyles};
	__property System::Types::TPoint CellsOffset = {read=GetCellsOffset};
	__property System::Uitypes::TColor GridLineColor = {read=GetGridLineColor, nodefault};
	__property Dxpscore::TdxReportCell* HostByArea[Cxcustompivotgrid::TcxPivotGridFieldArea Area] = {read=GetHostByArea};
	__property Dxpscore::TdxReportCell* HostCell = {read=FHostCell};
	__property Dxpscore::TdxReportCell* HostFilterBarCell = {read=FHostFilterBarCell};
	__property Dxpscore::TdxReportCell* HostHeaderCell = {read=FHostHeaderCell};
	__property Dxpscore::TdxReportCell* HostHeaderCornerCell = {read=FHostHeaderCornerCell};
	__property Dxpscore::TdxReportCell* HostRowHeaderCell = {read=FHostRowHeaderCell};
	__property Cxcustompivotgrid::TcxPivotGridViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxPivotGridReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxPivotGridReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxfmPivotGridReportLinkDesignWindow* DesignWindow = {read=GetDesignWindow};
	__property System::Classes::TList* LookAndFeelItems = {read=FLookAndFeelItems};
	__property Cxcustompivotgrid::TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	
__published:
	__property Color = {default=16777215};
	__property Font;
	__property TcxPivotGridReportLinkOptionsExpanding* OptionsExpanding = {read=GetOptionsExpanding, write=SetOptionsExpanding};
	__property TcxPivotGridReportLinkOptionsFormatting* OptionsFormatting = {read=GetOptionsFormatting, write=SetOptionsFormatting};
	__property TcxPivotGridReportLinkOptionsOnEveryPage* OptionsOnEveryPage = {read=GetOptionsOnEveryPage, write=SetOptionsOnEveryPage};
	__property TcxPivotGridReportLinkOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property ScaleFonts = {default=1};
	__property StyleRepository;
	__property TcxPivotGridReportLinkStyles* Styles = {read=GetStyles, write=SetStyles};
	__property SupportedCustomDraw = {default=0};
	__property TcxPivotGridReportLinkCustomDrawDataCellEventEvent OnCustomDrawDataCell = {read=FOnCustomDrawDataCell, write=FOnCustomDrawDataCell};
	__property TcxPivotGridReportLinkCustomDrawFieldHeaderCellEvent OnCustomDrawFieldHeaderCell = {read=FOnCustomDrawFieldHeaderCell, write=FOnCustomDrawFieldHeaderCell};
	__property TcxPivotGridReportLinkCustomDrawGroupHeaderCellEvent OnCustomDrawGroupHeaderCell = {read=FOnCustomDrawGroupHeaderCell, write=FOnCustomDrawGroupHeaderCell};
	__property TcxPivotGridReportLinkCustomDrawHeaderBackgroundEvent OnCustomDrawHeaderBackground = {read=FOnCustomDrawHeaderBackground, write=FOnCustomDrawHeaderBackground};
	__property TcxPivotGridReportLinkCustomDrawPrefilterEvent OnCustomDrawPrefilter = {read=FOnCustomDrawPrefilter, write=FOnCustomDrawPrefilter};
	__property TcxPivotGridReportLinkInitializeDataCellEvent OnInitializeDataCell = {read=FOnInitializeDataCell, write=FOnInitializeDataCell};
	__property TcxPivotGridReportLinkInitializeFieldHeaderCellEvent OnInitializeFieldHeaderCell = {read=FOnInitializeFieldHeaderCell, write=FOnInitializeFieldHeaderCell};
	__property TcxPivotGridReportLinkInitializeGroupHeaderCellEvent OnInitializeGroupHeaderCell = {read=FOnInitializeGroupHeaderCell, write=FOnInitializeGroupHeaderCell};
	__property TcxPivotGridReportLinkInitializeHeaderBackgroundEvent OnInitializeHeaderBackground = {read=FOnInitializeHeaderBackground, write=FOnInitializeHeaderBackground};
	__property TcxPivotGridReportLinkInitializePrefilterEvent OnInitializePrefilter = {read=FOnInitializePrefilter, write=FOnInitializePrefilter};
private:
	void *__IdxPSCellParams;	/* Dxpscxcommon::IdxPSCellParams */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F0A495A1-1F0F-4245-A437-16E21ACF9FED}
	operator Dxpscxcommon::_di_IdxPSCellParams()
	{
		Dxpscxcommon::_di_IdxPSCellParams intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscxcommon::IdxPSCellParams*(void) { return (Dxpscxcommon::IdxPSCellParams*)&__IdxPSCellParams; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxfmPivotGridReportLinkDesignWindow : public Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow
{
	typedef Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshView;
	Cxpc::TcxTabSheet* tshBehaviors;
	Cxpc::TcxTabSheet* tshFormatting;
	Vcl::Extctrls::TImage* imgLookAndFeel;
	Vcl::Extctrls::TImage* imgRefinements;
	Cxpc::TcxTabSheet* tshStyles;
	Vcl::Extctrls::TBevel* bvlStylesHost;
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxstyles::TcxStyleRepository* cxStyleRepository1;
	Cxstyles::TcxStyle* styleCategory;
	Cxstyles::TcxStyle* styleHeader;
	Cxstyles::TcxStyle* styleContent;
	Vcl::Menus::TPopupMenu* pmStyles;
	Vcl::Menus::TMenuItem* miStyleFont;
	Vcl::Menus::TMenuItem* miStyleColor;
	Vcl::Menus::TMenuItem* miLine3;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmap;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmapClear;
	Vcl::Menus::TMenuItem* milLine;
	Vcl::Menus::TMenuItem* miStylesSelectAll;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miStyleRestoreDefaults;
	Vcl::Menus::TMenuItem* miLine4;
	Vcl::Menus::TMenuItem* miStylesSaveAs;
	Vcl::Extctrls::TImage* imgExpanding;
	Vcl::Extctrls::TImage* Image1;
	Cxpivotgrid::TcxPivotGrid* PreviewPivotGrid;
	Cxcustompivotgrid::TcxPivotGridField* pgfPurchaseQuarter;
	Cxcustompivotgrid::TcxPivotGridField* pgfPurchaseMonth;
	Cxcustompivotgrid::TcxPivotGridField* pgfPaymentType;
	Cxcustompivotgrid::TcxPivotGridField* pgfQuantity;
	Cxcustompivotgrid::TcxPivotGridField* pgfCarName;
	Cxcustompivotgrid::TcxPivotGridField* pgfUnitPrice;
	Cxcustompivotgrid::TcxPivotGridField* pgfCompanyName;
	Cxcustompivotgrid::TcxPivotGridField* pgfPaymentAmount;
	Cxcheckbox::TcxCheckBox* chbxColumnFields;
	Cxcheckbox::TcxCheckBox* chbxShowExpandButtons;
	Cxcheckbox::TcxCheckBox* chbxHorizontalLines;
	Cxcheckbox::TcxCheckBox* chbxVerticalLines;
	Cxcheckbox::TcxCheckBox* chbxBorders;
	Cxcheckbox::TcxCheckBox* chbxDataFields;
	Cxcheckbox::TcxCheckBox* chbxFilterFields;
	Cxcheckbox::TcxCheckBox* chbxRowFields;
	Cxcheckbox::TcxCheckBox* chbxPrefilter;
	Cxcheckbox::TcxCheckBox* chbxExpandRows;
	Cxcheckbox::TcxCheckBox* chbxExpandColumns;
	Cxcheckbox::TcxCheckBox* chbxSuppressBackgroundBitmaps;
	Cxcheckbox::TcxCheckBox* chbxSuppressContentColoration;
	Cxcheckbox::TcxCheckBox* chbxUseNativeStyles;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblExpanding;
	Cxlabel::TcxLabel* lblLookAndFeel;
	Cxlabel::TcxLabel* lblRefinements;
	Cxlabel::TcxLabel* lblStyleSheets;
	Cxlabel::TcxLabel* lblUseNativeStyles;
	Cxbuttons::TcxButton* btnStyleColor;
	Cxbuttons::TcxButton* btnStyleFont;
	Cxbuttons::TcxButton* btnStyleBackgroundBitmap;
	Cxbuttons::TcxButton* btnStyleSheetNew;
	Cxbuttons::TcxButton* btnStyleSheetCopy;
	Cxbuttons::TcxButton* btnStyleSheetDelete;
	Cxbuttons::TcxButton* btnStylesSaveAs;
	Cxbuttons::TcxButton* btnStyleSheetRename;
	Cxbuttons::TcxButton* btnStyleBackgroundBitmapClear;
	Cxbuttons::TcxButton* btnStyleRestoreDefaults;
	Cxlabel::TcxLabel* lblPreviewWindow;
	Cxdropdownedit::TcxComboBox* cbxLookAndFeel;
	Cxdropdownedit::TcxComboBox* cbxStyleSheets;
	Cxcheckbox::TcxCheckBox* chbxFlatCheckMarks;
	Cxcheckbox::TcxCheckBox* chbxDisplayGraphicsAsText;
	Cxcheckbox::TcxCheckBox* chbxTransparentGraphics;
	Cxlabel::TcxLabel* bvlRefinementsSeparator;
	Cxlabel::TcxLabel* cxLabel1;
	Cxgraphics::TcxImageList* ilStylesPopup;
	Cxlabel::TcxLabel* lblOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxColumnHeadersOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxRowHeadersOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxFilterBarOnEveryPage;
	Vcl::Extctrls::TImage* imgOnEveryPage;
	void __fastcall OptionsFormattingChanged(System::TObject* Sender);
	void __fastcall btnStyleFontClick(System::TObject* Sender);
	void __fastcall btnStyleColorClick(System::TObject* Sender);
	void __fastcall btnStyleBackgroundBitmapClick(System::TObject* Sender);
	void __fastcall btnStyleClearClick(System::TObject* Sender);
	void __fastcall lblUseNativeStylesClick(System::TObject* Sender);
	void __fastcall pmStylesPopup(System::TObject* Sender);
	void __fastcall miStylesSelectAllClick(System::TObject* Sender);
	void __fastcall btnStyleRestoreDefaultsClick(System::TObject* Sender);
	void __fastcall btnStylesSaveAsClick(System::TObject* Sender);
	void __fastcall btnStyleSheetNewClick(System::TObject* Sender);
	void __fastcall btnStyleSheetCopyClick(System::TObject* Sender);
	void __fastcall btnStyleSheetDeleteClick(System::TObject* Sender);
	void __fastcall btnStyleSheetRenameClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall cbxLookAndFeelChange(System::TObject* Sender);
	void __fastcall chbxExpandOptionsClick(System::TObject* Sender);
	void __fastcall chbxOptionsViewClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall chbxOptionsOnEveryPageClick(System::TObject* Sender);
	
private:
	Cxstyles::TcxStyle* __fastcall GetActiveStyle(void);
	bool __fastcall GetHasSelectedStyles(void);
	bool __fastcall GetHasSelectedStylesWithAssignedBitmap(void);
	HIDESBASE TcxPivotGridReportLink* __fastcall GetReportLink(void);
	void __fastcall lbxStylesClick(System::TObject* Sender);
	
protected:
	Dxpscxcommon::TdxStylesListBox* lbxStyles;
	virtual void __fastcall CreateControls(void);
	bool __fastcall CanSelectAllStyles(void);
	virtual void __fastcall DoInitialize(void);
	DYNAMIC void __fastcall DoActiveStyleSheetChanged(void);
	DYNAMIC void __fastcall DoFormActivated(bool AnActive);
	DYNAMIC void __fastcall DoRefreshStylesList(void);
	DYNAMIC void __fastcall DoStyleChanged(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	DYNAMIC void __fastcall DoStylesChanged(System::Classes::TStrings* AStrings, bool ARecreate);
	virtual void __fastcall GetSelectedStyleNames(System::Classes::TStrings* AStrings);
	virtual void __fastcall GetStyleNames(/* out */ System::Classes::TStrings* &AStrings);
	virtual void __fastcall GetStyleSheetNames(/* out */ System::Classes::TStrings* &AStrings);
	void __fastcall LoadCaption(Vcl::Controls::TControl* AControl, void * StrPtr)/* overload */;
	void __fastcall LoadCaption(Vcl::Menus::TMenuItem* AItem, void * StrPtr)/* overload */;
	virtual void __fastcall LoadGroupsIcons(void);
	void __fastcall LoadPreviewData(void);
	virtual void __fastcall LoadStrings(void);
	void __fastcall LoadStringsCombo(Cxdropdownedit::TcxComboBox* ACombo, void * *ACaptions, const int ACaptions_Size);
	void __fastcall RecreateStylesListBox(void);
	void __fastcall RestoreSelectedStyles(System::Classes::TList* AList);
	void __fastcall SaveSelectedStyles(System::Classes::TList* AList);
	virtual void __fastcall UpdateControlsState(void);
	void __fastcall UpdateEnabled(Vcl::Controls::TControl* AControl, bool AEnabled)/* overload */;
	void __fastcall UpdateEnabled(Vcl::Menus::TMenuItem* AItem, bool AEnabled)/* overload */;
	void __fastcall UpdateEnabledControls(Vcl::Controls::TControl* *AControls, const int AControls_Size, bool AEnabled);
	virtual void __fastcall UpdatePreview(void);
	__property Cxstyles::TcxStyle* ActiveStyle = {read=GetActiveStyle};
	__property bool HasSelectedStyles = {read=GetHasSelectedStyles, nodefault};
	__property bool HasSelectedStylesWithAssignedBitmap = {read=GetHasSelectedStylesWithAssignedBitmap, nodefault};
	
public:
	__fastcall virtual TcxfmPivotGridReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxfmPivotGridReportLinkDesignWindow(void);
	__property TcxPivotGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxfmPivotGridReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxfmPivotGridReportLinkDesignWindow(HWND ParentWindow) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 vspsPGridFirst = System::Int8(0x0);
static const System::Int8 vspsPGridColumnHeader = System::Int8(0x0);
static const System::Int8 vspsPGridContent = System::Int8(0x1);
static const System::Int8 vspsPGridFieldHeader = System::Int8(0x2);
static const System::Int8 vspsPGridHeaderBackground = System::Int8(0x3);
static const System::Int8 vspsPGridPrefilter = System::Int8(0x4);
static const System::Int8 vspsPGridRowHeader = System::Int8(0x5);
static const System::Int8 vspsPGridLast = System::Int8(0x5);
static const System::Int8 cxPivotGridAttributeIDBase = System::Int8(0x0);
static const System::Int8 cxPivotGridDataCellID = System::Int8(0x1);
static const System::Int8 cxPivotGridFieldHeaderCellID = System::Int8(0x2);
static const System::Int8 cxPivotGridGroupHeaderCellID = System::Int8(0x3);
static const System::Int8 cxPivotGridPrefilterID = System::Int8(0x4);
static const System::Int8 cxPivotGridHeaderBackgroundID = System::Int8(0x5);
}	/* namespace Dxpscxpivotgridlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXPIVOTGRIDLNK)
using namespace Dxpscxpivotgridlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxpivotgridlnkHPP
