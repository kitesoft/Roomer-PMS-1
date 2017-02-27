// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridChartView.pas' rev: 24.00 (Win32)

#ifndef CxgridchartviewHPP
#define CxgridchartviewHPP

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
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <dxOffice11.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
__interface IcxGridChartItem;

namespace Cxgridchartview
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridChartLineDiagramValueViewInfoClass;

typedef System::TMetaClass* TcxGridChartItemClass;

typedef int TcxGridChartDataGroupContainerKind;

enum TcxGridChartPartAlignment : unsigned char { cpaDefault, cpaStart, cpaCenter, cpaEnd };

enum TcxGridChartPartOrientation : unsigned char { cpoDefault, cpoHorizontal, cpoVertical };

enum TcxGridChartPartPosition : unsigned char { cppDefault, cppNone, cppLeft, cppTop, cppRight, cppBottom };

enum TcxGridChartColumnDiagramValueCaptionPosition : unsigned char { cdvcpNone, cdvcpInsideBase, cdvcpCenter, cdvcpInsideEnd, cdvcpOutsideEnd };

enum TcxGridChartLineDiagramValueCaptionPosition : unsigned char { ldvcpNone, ldvcpLeft, ldvcpAbove, ldvcpRight, ldvcpBelow, ldvcpCenter, ldvcpAboveRight, ldvcpBelowRight, ldvcpAboveLeft, ldvcpBelowLeft };

enum TcxGridChartLineStyle : unsigned char { clsNone, clsSolid, clsDash, clsDot, clsDashDot, clsDashDotDot };

enum TcxGridChartMarkerStyle : unsigned char { cmsNone, cmsSquare, cmsTriangle, cmsDiamond, cmsCircle };

enum TcxGridChartPieDiagramValueCaptionPosition : unsigned char { pdvcpNone, pdvcpCenter, pdvcpInsideEnd, pdvcpOutsideEnd, pdvcpOutsideEndWithLeaderLines };

enum TcxGridChartValuesStacking : unsigned char { vsNone, vsNormal, vs100Percent };

class DELPHICLASS TcxGridChartTitleHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartTitleHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartTitleHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartTitleHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLegendHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLegendHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartLegendHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartLegendHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLegendItemHitTest;
class DELPHICLASS TcxGridChartSeries;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLegendItemHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	int Index;
	TcxGridChartSeries* Series;
	int ValueIndex;
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartLegendItemHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartLegendItemHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartToolBoxHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartToolBoxHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartDataLevelInfoHitTest;
class DELPHICLASS TcxGridChartDataGroup;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDataLevelInfoHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
private:
	int FDataLevel;
	TcxGridChartDataGroup* FDataLevelObject;
	void __fastcall SetDataLevel(int Value);
	void __fastcall SetDataLevelObject(TcxGridChartDataGroup* Value);
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	int DataLevelObjectContainerKind;
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
	__property int DataLevel = {read=FDataLevel, write=SetDataLevel, nodefault};
	__property TcxGridChartDataGroup* DataLevelObject = {read=FDataLevelObject, write=SetDataLevelObject};
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartDataLevelInfoHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartDataLevelInfoHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartDataLevelActiveValueInfoHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDataLevelActiveValueInfoHitTest : public TcxGridChartDataLevelInfoHitTest
{
	typedef TcxGridChartDataLevelInfoHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	bool CanDropDown;
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartDataLevelActiveValueInfoHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartDataLevelActiveValueInfoHitTest(void) : TcxGridChartDataLevelInfoHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartCustomizeButtonHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartCustomizeButtonHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartCustomizeButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartCustomizeButtonHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartDiagramSelectorHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDiagramSelectorHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	bool CanDropDown;
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartDiagramSelectorHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartDiagramSelectorHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartValueHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartValueHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	bool CanDrillDown;
	TcxGridChartSeries* Series;
	int ValueIndex;
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartValueHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartValueHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridChartDiagramHitTest;
class DELPHICLASS TcxGridChartDiagram;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridChartDiagramHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	
public:
	TcxGridChartDiagram* Diagram;
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxCustomGridChartDiagramHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridChartDiagramHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramPlotHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramPlotHitTest : public TcxCustomGridChartDiagramHitTest
{
	typedef TcxCustomGridChartDiagramHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramPlotHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartHistogramPlotHitTest(void) : TcxCustomGridChartDiagramHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridChartHistogramAxisHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridChartHistogramAxisHitTest : public TcxCustomGridChartDiagramHitTest
{
	typedef TcxCustomGridChartDiagramHitTest inherited;
	
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxCustomGridChartHistogramAxisHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridChartHistogramAxisHitTest(void) : TcxCustomGridChartDiagramHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramCategoryAxisTitleHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramCategoryAxisTitleHitTest : public TcxCustomGridChartHistogramAxisHitTest
{
	typedef TcxCustomGridChartHistogramAxisHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramCategoryAxisTitleHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartHistogramCategoryAxisTitleHitTest(void) : TcxCustomGridChartHistogramAxisHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramValueAxisTitleHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramValueAxisTitleHitTest : public TcxCustomGridChartHistogramAxisHitTest
{
	typedef TcxCustomGridChartHistogramAxisHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramValueAxisTitleHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartHistogramValueAxisTitleHitTest(void) : TcxCustomGridChartHistogramAxisHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartValueLineHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartValueLineHitTest : public TcxGridChartValueHitTest
{
	typedef TcxGridChartValueHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartValueLineHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartValueLineHitTest(void) : TcxGridChartValueHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartValueAreaHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartValueAreaHitTest : public TcxGridChartValueHitTest
{
	typedef TcxGridChartValueHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartValueAreaHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartValueAreaHitTest(void) : TcxGridChartValueHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartPieSeriesSiteHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieSeriesSiteHitTest : public TcxCustomGridChartDiagramHitTest
{
	typedef TcxCustomGridChartDiagramHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	TcxGridChartSeries* Series;
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartPieSeriesSiteHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartPieSeriesSiteHitTest(void) : TcxCustomGridChartDiagramHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartPieSeriesSiteCaptionHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieSeriesSiteCaptionHitTest : public TcxGridChartPieSeriesSiteHitTest
{
	typedef TcxGridChartPieSeriesSiteHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridChartPieSeriesSiteCaptionHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridChartPieSeriesSiteCaptionHitTest(void) : TcxGridChartPieSeriesSiteHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridChartMovingObject;
class DELPHICLASS TcxGridChartController;
class DELPHICLASS TcxGridChartCustomizationForm;
class DELPHICLASS TcxGridChartView;
class DELPHICLASS TcxGridChartViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridChartMovingObject : public Cxgridcustomview::TcxCustomGridMovingObject
{
	typedef Cxgridcustomview::TcxCustomGridMovingObject inherited;
	
private:
	HIDESBASE TcxGridChartController* __fastcall GetController(void);
	HIDESBASE TcxGridChartCustomizationForm* __fastcall GetCustomizationForm(void);
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	HIDESBASE TcxGridChartViewInfo* __fastcall GetViewInfo(void);
	
protected:
	__property TcxGridChartController* Controller = {read=GetController};
	__property TcxGridChartCustomizationForm* CustomizationForm = {read=GetCustomizationForm};
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property TcxGridChartViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxCustomGridChartMovingObject(Cxcontrols::TcxControl* AControl) : Cxgridcustomview::TcxCustomGridMovingObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridChartMovingObject(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartDataGroupMovingObjectClass;

class DELPHICLASS TcxGridChartDataGroupMovingObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDataGroupMovingObject : public TcxCustomGridChartMovingObject
{
	typedef TcxCustomGridChartMovingObject inherited;
	
private:
	int FDestDataLevel;
	int FSourceItemContainerKind;
	TcxGridChartDataGroup* __fastcall GetSourceItem(void);
	void __fastcall SetDestDataLevel(int Value);
	void __fastcall SetSourceItem(TcxGridChartDataGroup* Value);
	
protected:
	virtual bool __fastcall CanRemove(void);
	virtual System::Types::TRect __fastcall GetArrowAreaBounds(Cxcontrols::TcxArrowPlace APlace);
	virtual Cxgridcustomview::TcxCustomGridItemsListBox* __fastcall GetCustomizationFormListBox(void);
	virtual Cxgridcustomview::TcxCustomGridCellViewInfo* __fastcall GetSourceItemViewInfo(void);
	virtual bool __fastcall IsSourceCustomizationForm(void);
	virtual bool __fastcall IsValidDestination(void);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	__property int DestDataLevel = {read=FDestDataLevel, write=SetDestDataLevel, nodefault};
	__property TcxGridChartDataGroup* SourceItem = {read=GetSourceItem, write=SetSourceItem};
	__property int SourceItemContainerKind = {read=FSourceItemContainerKind, write=FSourceItemContainerKind, nodefault};
	
public:
	__fastcall virtual TcxGridChartDataGroupMovingObject(Cxcontrols::TcxControl* AControl);
	virtual void __fastcall Init(const System::Types::TPoint &P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartDataGroupMovingObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartSeriesInnerCheckListBox;
class PASCALIMPLEMENTATION TcxGridChartSeriesInnerCheckListBox : public Cxchecklistbox::TcxCustomInnerCheckListBox
{
	typedef Cxchecklistbox::TcxCustomInnerCheckListBox inherited;
	
protected:
	virtual Cxchecklistbox::TcxCheckListBoxMetrics __fastcall GetMetrics(void);
	
public:
	virtual int __fastcall GetSeriesImageSize(void);
public:
	/* TcxCustomInnerCheckListBox.Create */ inline __fastcall virtual TcxGridChartSeriesInnerCheckListBox(System::Classes::TComponent* AOwner) : Cxchecklistbox::TcxCustomInnerCheckListBox(AOwner) { }
	/* TcxCustomInnerCheckListBox.Destroy */ inline __fastcall virtual ~TcxGridChartSeriesInnerCheckListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartSeriesInnerCheckListBox(HWND ParentWindow) : Cxchecklistbox::TcxCustomInnerCheckListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridChartSeriesCheckListBoxClass;

class DELPHICLASS TcxGridChartSeriesCheckListBox;
class PASCALIMPLEMENTATION TcxGridChartSeriesCheckListBox : public Cxchecklistbox::TcxCheckListBox
{
	typedef Cxchecklistbox::TcxCheckListBox inherited;
	
private:
	TcxGridChartSeries* FDraggingSeries;
	TcxGridChartView* FGridView;
	bool FLockRefreshItems;
	Vcl::Controls::TImageList* FSeriesImages;
	TcxGridChartSeries* __fastcall GetSeries(int AIndex);
	
protected:
	virtual void __fastcall CheckClicked(System::TObject* Sender, int AIndex, Cxlookandfeelpainters::TcxCheckBoxState APrevState, Cxlookandfeelpainters::TcxCheckBoxState ANewState);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DrawSeriesImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxGridChartSeries* ASeries);
	virtual Cxchecklistbox::TcxCustomInnerCheckListBoxClass __fastcall GetInnerCheckListBoxClass(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall RefreshImages(void);
	virtual void __fastcall RefreshSeriesImages(void);
	__property TcxGridChartSeries* DraggingSeries = {read=FDraggingSeries, write=FDraggingSeries};
	__property TcxGridChartView* GridView = {read=FGridView};
	__property bool LockRefreshItems = {read=FLockRefreshItems, write=FLockRefreshItems, nodefault};
	__property TcxGridChartSeries* Series[int AIndex] = {read=GetSeries};
	__property Vcl::Controls::TImageList* SeriesImages = {read=FSeriesImages};
	
public:
	__fastcall virtual TcxGridChartSeriesCheckListBox(System::Classes::TComponent* AOwner, TcxGridChartView* AGridView);
	__fastcall virtual ~TcxGridChartSeriesCheckListBox(void);
	virtual void __fastcall RefreshItems(void);
	DYNAMIC bool __fastcall StartDrag(Vcl::Controls::TDragObject* DragObject);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartSeriesCheckListBox(HWND ParentWindow) : Cxchecklistbox::TcxCheckListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridChartSortBySeriesComboBoxClass;

class DELPHICLASS TcxGridChartSortBySeriesComboBox;
class PASCALIMPLEMENTATION TcxGridChartSortBySeriesComboBox : public Cxdropdownedit::TcxComboBox
{
	typedef Cxdropdownedit::TcxComboBox inherited;
	
private:
	Cxedit::TcxEditButton* FDirectionButton;
	TcxGridChartView* FGridView;
	
protected:
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall DirectionButtonClick(void);
	virtual void __fastcall DoButtonClick(int AButtonVisibleIndex);
	virtual void __fastcall DrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall MeasureItem(Cxdropdownedit::TcxCustomComboBox* AControl, int AIndex, Cxgraphics::TcxCanvas* ACanvas, int &AHeight);
	virtual void __fastcall RefreshDirectionButton(void);
	__property Cxedit::TcxEditButton* DirectionButton = {read=FDirectionButton};
	__property TcxGridChartView* GridView = {read=FGridView};
	
public:
	__fastcall virtual TcxGridChartSortBySeriesComboBox(System::Classes::TComponent* AOwner, TcxGridChartView* AGridView);
	virtual void __fastcall RefreshItems(void);
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxGridChartSortBySeriesComboBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartSortBySeriesComboBox(HWND ParentWindow) : Cxdropdownedit::TcxComboBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridChartDataGroupsListBoxClass;

class DELPHICLASS TcxGridChartDataGroupsListBox;
class PASCALIMPLEMENTATION TcxGridChartDataGroupsListBox : public Cxgridcustomview::TcxCustomGridItemsListBox
{
	typedef Cxgridcustomview::TcxCustomGridItemsListBox inherited;
	
private:
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	
protected:
	virtual int __fastcall CalculateItemHeight(void);
	virtual void __fastcall DoRefreshItems(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetDragAndDropParams(void);
	__property TcxGridChartView* GridView = {read=GetGridView};
	
public:
	virtual void __fastcall PaintItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int AIndex, bool AFocused);
public:
	/* TcxCustomGridItemsListBox.Create */ inline __fastcall virtual TcxGridChartDataGroupsListBox(System::Classes::TComponent* AOwner) : Cxgridcustomview::TcxCustomGridItemsListBox(AOwner) { }
	
public:
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TcxGridChartDataGroupsListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartDataGroupsListBox(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridItemsListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridChartOptionsTreeViewClass;

class DELPHICLASS TcxGridChartOptionsTreeView;
class PASCALIMPLEMENTATION TcxGridChartOptionsTreeView : public Cxgridcommon::TcxGridOptionsTreeView
{
	typedef Cxgridcommon::TcxGridOptionsTreeView inherited;
	
private:
	TcxGridChartView* FGridView;
	
protected:
	int LegendID;
	int LegendAlignmentID;
	int LegendBorderID;
	int LegendKeyBorderID;
	int LegendOrientationID;
	int LegendPositionID;
	int TitleID;
	int TitleAlignmentID;
	int TitlePositionID;
	int ToolBoxID;
	int ToolBoxBorderID;
	int ToolBoxDiagramSelectorID;
	int ToolBoxPositionID;
	int OtherID;
	int OtherValueHintsID;
	virtual void __fastcall AddItems(void);
	virtual bool __fastcall IsItemChecked(int AParentID, int AID);
	virtual void __fastcall ItemClicked(int AParentID, int AID);
	__property TcxGridChartView* GridView = {read=FGridView};
	
public:
	__fastcall virtual TcxGridChartOptionsTreeView(System::Classes::TComponent* AOwner, TcxGridChartView* AGridView);
public:
	/* TcxTreeViewContainer.Destroy */ inline __fastcall virtual ~TcxGridChartOptionsTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartOptionsTreeView(HWND ParentWindow) : Cxgridcommon::TcxGridOptionsTreeView(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxGridChartCustomizationForm : public Cxgridcustomview::TcxCustomGridCustomizationForm
{
	typedef Cxgridcustomview::TcxCustomGridCustomizationForm inherited;
	
private:
	TcxGridChartDataGroupsListBox* FDataGroupsListBox;
	Cxpc::TcxTabSheet* FDataGroupsPage;
	Cxpc::TcxTabSheet* FOptionsPage;
	TcxGridChartOptionsTreeView* FOptionsTreeView;
	TcxGridChartSeriesCheckListBox* FSeriesCheckListBox;
	TcxGridChartSortBySeriesComboBox* FSortBySeriesComboBox;
	Cxlabel::TcxLabel* FSortBySeriesLabel;
	Cxpc::TcxTabSheet* FSeriesPage;
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	
protected:
	virtual bool __fastcall CanChangeSortedSeries(void);
	virtual void __fastcall CreateControls(void);
	virtual TcxGridChartDataGroupsListBoxClass __fastcall GetDataGroupsListBoxClass(void);
	virtual bool __fastcall GetDataGroupsPageVisible(void);
	virtual bool __fastcall GetOptionsPageVisible(void);
	virtual TcxGridChartOptionsTreeViewClass __fastcall GetOptionsTreeViewClass(void);
	virtual TcxGridChartSeriesCheckListBoxClass __fastcall GetSeriesCheckListBoxClass(void);
	virtual bool __fastcall GetSeriesPageVisible(void);
	virtual TcxGridChartSortBySeriesComboBoxClass __fastcall GetSortBySeriesComboBoxClass(void);
	virtual void __fastcall GridViewChanged(void);
	virtual void __fastcall InitPageControl(void);
	__property TcxGridChartView* GridView = {read=GetGridView};
	
public:
	virtual void __fastcall PrepareForDataGroupDragAndDrop(void);
	virtual void __fastcall RefreshData(void);
	__property TcxGridChartDataGroupsListBox* DataGroupsListBox = {read=FDataGroupsListBox};
	__property Cxpc::TcxTabSheet* DataGroupsPage = {read=FDataGroupsPage};
	__property Cxpc::TcxTabSheet* OptionsPage = {read=FOptionsPage};
	__property TcxGridChartOptionsTreeView* OptionsTreeView = {read=FOptionsTreeView};
	__property TcxGridChartSeriesCheckListBox* SeriesCheckListBox = {read=FSeriesCheckListBox};
	__property Cxpc::TcxTabSheet* SeriesPage = {read=FSeriesPage};
	__property TcxGridChartSortBySeriesComboBox* SortBySeriesComboBox = {read=FSortBySeriesComboBox};
	__property Cxlabel::TcxLabel* SortBySeriesLabel = {read=FSortBySeriesLabel};
public:
	/* TcxCustomGridCustomizationForm.Create */ inline __fastcall virtual TcxGridChartCustomizationForm(Cxgridcustomview::TcxCustomGridController* AController) : Cxgridcustomview::TcxCustomGridCustomizationForm(AController) { }
	/* TcxCustomGridCustomizationForm.Destroy */ inline __fastcall virtual ~TcxGridChartCustomizationForm(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridChartCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomview::TcxCustomGridCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartCustomizationForm(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridCustomizationForm(ParentWindow) { }
	
};


__interface IcxGridChartDataLevelActiveValuePopupOwner;
typedef System::DelphiInterface<IcxGridChartDataLevelActiveValuePopupOwner> _di_IcxGridChartDataLevelActiveValuePopupOwner;
__interface  INTERFACE_UUID("{94AE5C9F-9A81-401D-8B76-E3278CDD0CEB}") IcxGridChartDataLevelActiveValuePopupOwner  : public Cxgridcustomview::IcxCustomGridPopupOwner 
{
	
public:
	virtual TcxGridChartDataGroup* __fastcall GetDataGroup(void) = 0 ;
};

typedef System::TMetaClass* TcxGridChartDataLevelActiveValuePopupClass;

class DELPHICLASS TcxGridChartDataLevelActiveValuePopup;
class PASCALIMPLEMENTATION TcxGridChartDataLevelActiveValuePopup : public Cxgridcustomview::TcxCustomGridPopup
{
	typedef Cxgridcustomview::TcxCustomGridPopup inherited;
	
private:
	TcxGridChartDataGroup* FDataGroup;
	Cxgridcustomview::TcxGridPopupListBox* FListBox;
	TcxGridChartView* __fastcall GetGridView(void);
	void __fastcall ListBoxAction(Cxgridcustomview::TcxGridPopupListBox* Sender, int AItemIndex);
	
protected:
	Cxvariants::TVariantArray Values;
	virtual void __fastcall AddValueItems(System::Classes::TStrings* AStrings, /* out */ Cxvariants::TVariantArray &AValues);
	virtual void __fastcall AdjustListBoxSize(void);
	virtual void __fastcall InitPopup(void);
	virtual void __fastcall SetDataGroupActiveValue(int AItemIndex);
	__property Cxgridcustomview::TcxGridPopupListBox* ListBox = {read=FListBox};
	
public:
	__fastcall virtual TcxGridChartDataLevelActiveValuePopup(Cxgridcustomview::TcxCustomGridView* AGridView);
	__property TcxGridChartDataGroup* DataGroup = {read=FDataGroup};
	__property TcxGridChartView* GridView = {read=GetGridView};
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxGridChartDataLevelActiveValuePopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridChartDataLevelActiveValuePopup(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomview::TcxCustomGridPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartDataLevelActiveValuePopup(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridPopup(ParentWindow) { }
	
};


class DELPHICLASS TcxGridChartDiagramSelectorPopupListBox;
class PASCALIMPLEMENTATION TcxGridChartDiagramSelectorPopupListBox : public Cxgridcustomview::TcxGridPopupListBox
{
	typedef Cxgridcustomview::TcxGridPopupListBox inherited;
	
protected:
	virtual int __fastcall CalculateItemHeight(void);
	virtual void __fastcall DrawItemContent(Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
public:
	/* TcxGridPopupListBox.Create */ inline __fastcall virtual TcxGridChartDiagramSelectorPopupListBox(Cxgridcustomview::TcxCustomGridPopup* APopup) : Cxgridcustomview::TcxGridPopupListBox(APopup) { }
	/* TcxGridPopupListBox.Destroy */ inline __fastcall virtual ~TcxGridChartDiagramSelectorPopupListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartDiagramSelectorPopupListBox(HWND ParentWindow) : Cxgridcustomview::TcxGridPopupListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridChartDiagramSelectorPopupClass;

class DELPHICLASS TcxGridChartDiagramSelectorPopup;
class PASCALIMPLEMENTATION TcxGridChartDiagramSelectorPopup : public Cxgridcustomview::TcxCustomGridPopup
{
	typedef Cxgridcustomview::TcxCustomGridPopup inherited;
	
private:
	TcxGridChartDiagramSelectorPopupListBox* FListBox;
	TcxGridChartView* __fastcall GetGridView(void);
	void __fastcall ListBoxAction(Cxgridcustomview::TcxGridPopupListBox* Sender, int AItemIndex);
	
protected:
	virtual void __fastcall AddDiagramItems(System::Classes::TStrings* AStrings);
	virtual int __fastcall GetImageOffset(void);
	virtual void __fastcall InitPopup(void);
	virtual void __fastcall SelectDiagram(int AItemIndex);
	__property TcxGridChartDiagramSelectorPopupListBox* ListBox = {read=FListBox};
	
public:
	__fastcall virtual TcxGridChartDiagramSelectorPopup(Cxgridcustomview::TcxCustomGridView* AGridView);
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property int ImageOffset = {read=GetImageOffset, nodefault};
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxGridChartDiagramSelectorPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridChartDiagramSelectorPopup(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomview::TcxCustomGridPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridChartDiagramSelectorPopup(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridPopup(ParentWindow) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartController : public Cxgridcustomview::TcxCustomGridController
{
	typedef Cxgridcustomview::TcxCustomGridController inherited;
	
private:
	typedef System::DynamicArray<int> _TcxGridChartController__1;
	
	
private:
	TcxGridChartDataLevelActiveValuePopup* FDataLevelActiveValuePopup;
	TcxGridChartDiagramSelectorPopup* FDiagramSelectorPopup;
	int FFirstVisibleCategoryIndex;
	_TcxGridChartController__1 FFirstVisibleCategoryIndexes;
	TcxGridChartDataGroup* FMovingDataGroup;
	int FStoredFirstVisibleCategoryIndex;
	TcxGridChartCustomizationForm* __fastcall GetCustomizationForm(void);
	TcxGridChartDataLevelActiveValuePopup* __fastcall GetDataLevelActiveValuePopup(void);
	TcxGridChartDiagramSelectorPopup* __fastcall GetDiagramSelectorPopup(void);
	TcxGridChartView* __fastcall GetGridView(void);
	bool __fastcall GetIsDataGroupMoving(void);
	HIDESBASE TcxGridChartViewInfo* __fastcall GetViewInfo(void);
	int __fastcall GetVisibleCategoryCountValue(void);
	void __fastcall SetFirstVisibleCategoryIndex(int Value);
	
protected:
	virtual void __fastcall ActiveDataLevelChanged(int APrevActiveDataLevel, int AActiveDataLevel);
	virtual void __fastcall ActiveDiagramChanged(TcxGridChartDiagram* ADiagram);
	virtual void __fastcall CheckCoordinates(void);
	virtual void __fastcall DataLevelsChanged(void);
	virtual void __fastcall FirstVisibleCategoryIndexChanged(void);
	virtual TcxGridChartDataLevelActiveValuePopupClass __fastcall GetDataLevelActiveValuePopupClass(void);
	virtual bool __fastcall GetDesignHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual TcxGridChartDiagramSelectorPopupClass __fastcall GetDiagramSelectorPopupClass(void);
	virtual System::Classes::TPersistent* __fastcall GetPatternObject(System::Classes::TPersistent* AObject);
	virtual int __fastcall GetFirstVisibleCategoryIndex(void);
	virtual int __fastcall GetVisibleCategoryCount(bool ACheckCount);
	virtual bool __fastcall CanDataDrillDown(int AValueIndex);
	virtual bool __fastcall CanDataDrillUp(void);
	virtual bool __fastcall DoDataDrillDown(int AValueIndex);
	virtual bool __fastcall DoDataDrillUp(void);
	virtual bool __fastcall MayDataDrillDown(bool ACheckDesignTime = true);
	virtual void __fastcall DoScroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual bool __fastcall CanShowScrollBar(void);
	virtual Vcl::Forms::TScrollBarKind __fastcall GetScrollBarKind(void);
	virtual int __fastcall GetScrollBarPageSize(void);
	virtual int __fastcall GetScrollBarPos(void);
	virtual int __fastcall GetScrollBarSize(void);
	virtual int __fastcall ScrollPosToCategoryIndex(int AScrollPos);
	virtual bool __fastcall CanShowDataLevelActiveValuePopup(bool ACheckDesignTime = true);
	virtual void __fastcall CustomizationChanged(void);
	virtual Cxgridcustomview::TcxCustomGridCustomizationFormClass __fastcall GetCustomizationFormClass(void);
	virtual int __fastcall GetCustomizationFormDefaultWidth(void);
	virtual TcxGridChartDataGroupMovingObjectClass __fastcall GetDataLevelInfoDragAndDropObjectClass(void);
	__property TcxGridChartViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxGridChartController(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxGridChartController(void);
	bool __fastcall HasDataLevelActiveValuePopup(void);
	bool __fastcall HasDiagramSelectorPopup(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual System::UnicodeString __fastcall GetValueHintText(TcxGridChartSeries* ASeries, int AValueIndex);
	virtual bool __fastcall DataDrillDown(int AValueIndex);
	virtual bool __fastcall DataDrillUp(void);
	bool __fastcall IsDataDrillDownPossible(int AValueIndex);
	bool __fastcall ActiveDiagramSupportsPaging(void);
	__property int FirstVisibleCategoryIndex = {read=GetFirstVisibleCategoryIndex, write=SetFirstVisibleCategoryIndex, nodefault};
	__property int VisibleCategoryCount = {read=GetVisibleCategoryCountValue, nodefault};
	__property TcxGridChartCustomizationForm* CustomizationForm = {read=GetCustomizationForm};
	__property TcxGridChartDataLevelActiveValuePopup* DataLevelActiveValuePopup = {read=GetDataLevelActiveValuePopup};
	__property TcxGridChartDiagramSelectorPopup* DiagramSelectorPopup = {read=GetDiagramSelectorPopup};
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property bool IsDataGroupMoving = {read=GetIsDataGroupMoving, nodefault};
	__property TcxGridChartDataGroup* MovingDataGroup = {read=FMovingDataGroup};
};

#pragma pack(pop)

__interface IcxGridChartItem;
typedef System::DelphiInterface<IcxGridChartItem> _di_IcxGridChartItem;
class DELPHICLASS TcxGridChartItemDataBinding;
__interface  INTERFACE_UUID("{CDDAE712-6292-4814-A69E-7D871B299EB2}") IcxGridChartItem  : public System::IInterface 
{
	
public:
	virtual void __fastcall DataChanged(void) = 0 ;
	virtual TcxGridChartItemDataBinding* __fastcall GetDataBinding(void) = 0 ;
	virtual int __fastcall GetID(void) = 0 ;
	virtual void __fastcall ValueTypeClassChanged(void) = 0 ;
};

__interface IcxGridChartViewItemsProvider;
typedef System::DelphiInterface<IcxGridChartViewItemsProvider> _di_IcxGridChartViewItemsProvider;
class DELPHICLASS TcxGridChartItem;
__interface  INTERFACE_UUID("{852B466D-5068-4600-BBC6-0061BF69A0B0}") IcxGridChartViewItemsProvider  : public System::IInterface 
{
	
public:
	virtual TcxGridChartItem* __fastcall GetItem(TcxGridChartItemClass AItemClass, int AIndex) = 0 ;
	virtual void __fastcall GetItemCaptions(TcxGridChartItemClass AItemClass, System::Classes::TStringList* ACaptions) = 0 ;
	virtual void __fastcall InitItem(TcxGridChartItem* AItem, int AIndex) = 0 ;
};

class DELPHICLASS TcxGridChartDataController;
class PASCALIMPLEMENTATION TcxGridChartDataController : public Cxdata::TcxDataController
{
	typedef Cxdata::TcxDataController inherited;
	
private:
	TcxGridChartView* __fastcall GetGridViewValue(void);
	Cxcustomdata::TcxAfterSummaryEvent __fastcall GetOnAfterSummary(void);
	Cxcustomdata::TcxSummaryEvent __fastcall GetOnSummary(void);
	void __fastcall SetOnAfterSummary(Cxcustomdata::TcxAfterSummaryEvent Value);
	void __fastcall SetOnSummary(Cxcustomdata::TcxSummaryEvent Value);
	
protected:
	void __fastcall AssignData(Cxcustomdata::TcxCustomDataController* ADataController);
	void __fastcall CreateAllItems(bool AMissingItemsOnly);
	void __fastcall DeleteAllItems(void);
	void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetGridView(void);
	bool __fastcall HasAllItems(void);
	bool __fastcall IsDataChangeable(void);
	bool __fastcall IsDataLinked(void);
	bool __fastcall SupportsCreateAllItems(void);
	virtual void __fastcall DoValueTypeClassChanged(int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual Cxcustomdata::TcxSortingBySummaryEngineClass __fastcall GetSortingBySummaryEngineClass(void);
	virtual void __fastcall Unlocked(void);
	
public:
	virtual void __fastcall BeginFullUpdate(void);
	virtual void __fastcall EndFullUpdate(void);
	virtual System::TObject* __fastcall GetItem(int Index);
	__property TcxGridChartView* GridView = {read=GetGridViewValue};
	
__published:
	__property Options = {default=28};
	__property Cxcustomdata::TcxAfterSummaryEvent OnAfterSummary = {read=GetOnAfterSummary, write=SetOnAfterSummary};
	__property OnCompare;
	__property OnDataChanged;
	__property OnFilterRecord;
	__property OnRecordChanged;
	__property Cxcustomdata::TcxSummaryEvent OnSummary = {read=GetOnSummary, write=SetOnSummary};
public:
	/* TcxDataController.Create */ inline __fastcall virtual TcxGridChartDataController(System::Classes::TComponent* AOwner) : Cxdata::TcxDataController(AOwner) { }
	/* TcxDataController.Destroy */ inline __fastcall virtual ~TcxGridChartDataController(void) { }
	
private:
	void *__IcxCustomGridDataController;	/* Cxgridcustomview::IcxCustomGridDataController */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B9ABDC6B-1A4A-4F11-A629-09B6FB9FB4BA}
	operator Cxgridcustomview::_di_IcxCustomGridDataController()
	{
		Cxgridcustomview::_di_IcxCustomGridDataController intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridcustomview::IcxCustomGridDataController*(void) { return (Cxgridcustomview::IcxCustomGridDataController*)&__IcxCustomGridDataController; }
	#endif
	
};


typedef System::TMetaClass* TcxGridChartViewPainterHelperClass;

class DELPHICLASS TcxGridChartViewPainterHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartViewPainterHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Byte FAlphaChannel;
	Cxgraphics::TcxCanvas* FCanvas;
	System::Uitypes::TColor FPenColor;
	Vcl::Graphics::TPenStyle FPenStyle;
	int FPenWidth;
	Dxgdiplusclasses::TdxGPSmoothingMode FSmoothingMode;
	HPEN __fastcall CreatePen(void);
	System::Uitypes::TColor __fastcall RealPenColor(void);
	
public:
	__fastcall virtual TcxGridChartViewPainterHelper(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Pie(const System::Types::TRect &R, int AStartAngle, int ASweepAngle);
	virtual void __fastcall Polygon(System::Types::TPoint const *Points, const int Points_Size);
	virtual void __fastcall Polyline(System::Types::TPoint const *Points, const int Points_Size);
	__property System::Byte AlphaChannel = {read=FAlphaChannel, write=FAlphaChannel, nodefault};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property System::Uitypes::TColor PenColor = {read=FPenColor, write=FPenColor, nodefault};
	__property Vcl::Graphics::TPenStyle PenStyle = {read=FPenStyle, write=FPenStyle, nodefault};
	__property int PenWidth = {read=FPenWidth, write=FPenWidth, nodefault};
	__property Dxgdiplusclasses::TdxGPSmoothingMode SmoothingMode = {read=FSmoothingMode, write=FSmoothingMode, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartViewPainterHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartViewGDIPlusPainterHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartViewGDIPlusPainterHelper : public TcxGridChartViewPainterHelper
{
	typedef TcxGridChartViewPainterHelper inherited;
	
public:
	virtual void __fastcall Pie(const System::Types::TRect &R, int AStartAngle, int ASweepAngle);
	virtual void __fastcall Polygon(System::Types::TPoint const *Points, const int Points_Size);
	virtual void __fastcall Polyline(System::Types::TPoint const *Points, const int Points_Size);
public:
	/* TcxGridChartViewPainterHelper.Create */ inline __fastcall virtual TcxGridChartViewGDIPlusPainterHelper(Cxgraphics::TcxCanvas* ACanvas) : TcxGridChartViewPainterHelper(ACanvas) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartViewGDIPlusPainterHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartTitlePainter;
class DELPHICLASS TcxCustomGridChartTitleViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartTitlePainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxCustomGridChartTitleViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall PrepareCanvasForDrawText(void);
	virtual void __fastcall UnprepareCanvasForDrawText(void);
	
public:
	__property TcxCustomGridChartTitleViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartTitlePainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartTitlePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLegendItemPainter;
class DELPHICLASS TcxGridChartLegendItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLegendItemPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartLegendItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawLegendKey(void);
	__property TcxGridChartLegendItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartLegendItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartLegendItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLegendPainter;
class DELPHICLASS TcxGridChartLegendViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLegendPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartLegendViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxGridChartLegendViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartLegendPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartLegendPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartDiagramPainter;
class DELPHICLASS TcxGridChartDiagramViewInfo;
class DELPHICLASS TcxGridChartDiagramValueViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDiagramPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartDiagramViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawValueCaptions(void);
	virtual void __fastcall DrawValues(void);
	void __fastcall FillAndExcludeRect(const System::Types::TRect &R);
	virtual bool __fastcall NeedsPainting(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PrepareClipRegionForValueDrawing(TcxGridChartDiagramValueViewInfo* AValueViewInfo, Cxgraphics::TcxRegion* AOriginalClipRegion);
	__property TcxGridChartDiagramViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartDiagramPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartDiagramPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramTickMarkLabelsPainter;
class DELPHICLASS TcxGridChartHistogramTickMarkLabelsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramTickMarkLabelsPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartHistogramTickMarkLabelsViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawCaptions(void);
	virtual void __fastcall DrawContent(void);
	
public:
	__property TcxGridChartHistogramTickMarkLabelsViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartHistogramTickMarkLabelsPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramTickMarkLabelsPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramPainter;
class DELPHICLASS TcxGridChartHistogramViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramPainter : public TcxGridChartDiagramPainter
{
	typedef TcxGridChartDiagramPainter inherited;
	
private:
	HIDESBASE TcxGridChartHistogramViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawCategoryAxis(void);
	virtual void __fastcall DrawCategoryGridLines(void);
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawPlotBackground(void);
	virtual void __fastcall DrawValueAxis(void);
	virtual void __fastcall DrawValueGridLines(void);
	virtual void __fastcall DrawValuesBackground(void);
	virtual bool __fastcall GetTransparentValues(void) = 0 ;
	virtual System::Types::TRect __fastcall GetValuesClipRect(void);
	virtual void __fastcall SetValuesClipRegion(void);
	__property bool TransparentValues = {read=GetTransparentValues, nodefault};
	__property TcxGridChartHistogramViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartHistogramPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridChartDiagramPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartColumnDiagramValuePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartColumnDiagramValuePainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
protected:
	virtual bool __fastcall ExcludeFromClipRect(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartColumnDiagramValuePainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartColumnDiagramValuePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartColumnDiagramPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartColumnDiagramPainter : public TcxGridChartHistogramPainter
{
	typedef TcxGridChartHistogramPainter inherited;
	
protected:
	virtual bool __fastcall GetTransparentValues(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartColumnDiagramPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridChartHistogramPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartColumnDiagramPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartColumnValueCaptionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartColumnValueCaptionPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
protected:
	virtual void __fastcall DrawBackground(void)/* overload */;
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartColumnValueCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartColumnValueCaptionPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLineDiagramLegendItemPainter;
class DELPHICLASS TcxGridChartLineDiagramLegendItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLineDiagramLegendItemPainter : public TcxGridChartLegendItemPainter
{
	typedef TcxGridChartLegendItemPainter inherited;
	
private:
	HIDESBASE TcxGridChartLineDiagramLegendItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawLegendKey(void);
	virtual void __fastcall DrawLine(void);
	virtual void __fastcall DrawMarker(void);
	__property TcxGridChartLineDiagramLegendItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartLineDiagramLegendItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridChartLegendItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramLegendItemPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartLineDiagramValuePainterClass;

class DELPHICLASS TcxGridChartLineDiagramValuePainter;
class DELPHICLASS TcxGridChartLineDiagramValueViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLineDiagramValuePainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartLineDiagramValueViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall CanDrawDesignSelection(void);
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawLine(void);
	virtual void __fastcall DrawMarker(void);
	__property TcxGridChartLineDiagramValueViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__classmethod virtual void __fastcall DrawLineEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &AStart, const System::Types::TPoint &AFinish, TcxGridChartLineStyle AStyle, int AWidth, System::Uitypes::TColor AColor, bool Antialiasing);
	__classmethod virtual void __fastcall DrawLines(Cxgraphics::TcxCanvas* ACanvas, const Cxgraphics::TPointArray APoints, TcxGridChartLineStyle AStyle, int AWidth, System::Uitypes::TColor AColor, bool Antialiasing);
	__classmethod virtual void __fastcall DrawMarkerEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const Cxgraphics::TPointArray APoints, TcxGridChartMarkerStyle AStyle, const Cxgraphics::TcxViewParams &AParams, bool Antialiasing);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartLineDiagramValuePainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramValuePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLineDiagramPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLineDiagramPainter : public TcxGridChartHistogramPainter
{
	typedef TcxGridChartHistogramPainter inherited;
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawValuesDesignSelection(void);
	virtual bool __fastcall GetTransparentValues(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartLineDiagramPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridChartHistogramPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartAreaDiagramLegendItemPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartAreaDiagramLegendItemPainter : public TcxGridChartLineDiagramLegendItemPainter
{
	typedef TcxGridChartLineDiagramLegendItemPainter inherited;
	
protected:
	virtual void __fastcall DrawAreaBackground(void);
	virtual void __fastcall DrawAreaBorder(void);
	virtual void __fastcall DrawLegendKey(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartAreaDiagramLegendItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridChartLineDiagramLegendItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagramLegendItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartAreaDiagramValuePainter;
class DELPHICLASS TcxGridChartAreaDiagramValueViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartAreaDiagramValuePainter : public TcxGridChartLineDiagramValuePainter
{
	typedef TcxGridChartLineDiagramValuePainter inherited;
	
private:
	HIDESBASE TcxGridChartAreaDiagramValueViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoDrawArea(void);
	virtual void __fastcall DrawArea(void);
	__property TcxGridChartAreaDiagramValueViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartAreaDiagramValuePainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridChartLineDiagramValuePainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagramValuePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartAreaDiagramPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartAreaDiagramPainter : public TcxGridChartLineDiagramPainter
{
	typedef TcxGridChartLineDiagramPainter inherited;
	
protected:
	virtual void __fastcall DrawValuesBackground(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartAreaDiagramPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridChartLineDiagramPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagramPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartPieDiagramValuePainter;
class DELPHICLASS TcxGridChartPieDiagramValueViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieDiagramValuePainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartPieDiagramValueViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawLeaderLine(void);
	virtual void __fastcall DrawSlice(void);
	__property TcxGridChartPieDiagramValueViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall MainPaint(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartPieDiagramValuePainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartPieDiagramValuePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartPieSeriesSiteCaptionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieSeriesSiteCaptionPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
protected:
	virtual bool __fastcall ExcludeFromClipRect(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartPieSeriesSiteCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartPieSeriesSiteCaptionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartPieSeriesSitePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieSeriesSitePainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
protected:
	virtual bool __fastcall CanDrawDesignSelection(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartPieSeriesSitePainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartPieSeriesSitePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartPieDiagramPainter;
class DELPHICLASS TcxGridChartPieDiagramViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieDiagramPainter : public TcxGridChartDiagramPainter
{
	typedef TcxGridChartDiagramPainter inherited;
	
private:
	HIDESBASE TcxGridChartPieDiagramViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawSeriesDesignSelection(void);
	virtual void __fastcall DrawSeriesSites(void);
	virtual void __fastcall DrawValues(void);
	virtual void __fastcall ExcludeSeriesPieAreasFromClipRegion(void);
	virtual void __fastcall PrepareClipRegionForValueDrawing(TcxGridChartDiagramValueViewInfo* AValueViewInfo, Cxgraphics::TcxRegion* AOriginalClipRegion);
	__property TcxGridChartPieDiagramViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartPieDiagramPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridChartDiagramPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartPieDiagramPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartToolBoxItemSeparatorPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxItemSeparatorPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
protected:
	virtual void __fastcall DrawContent(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartToolBoxItemSeparatorPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxItemSeparatorPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartToolBoxDataLevelActiveValuePainter;
class DELPHICLASS TcxGridChartToolBoxDataLevelActiveValueViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxDataLevelActiveValuePainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartToolBoxDataLevelActiveValueViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall PrepareCanvasForDrawText(void);
	__property TcxGridChartToolBoxDataLevelActiveValueViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartToolBoxDataLevelActiveValuePainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxDataLevelActiveValuePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartToolBoxDataLevelInfoPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxDataLevelInfoPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
protected:
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual bool __fastcall ExcludeFromClipRect(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartToolBoxDataLevelInfoPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxDataLevelInfoPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartToolBoxCustomizeButtonPainter;
class DELPHICLASS TcxGridChartToolBoxCustomizeButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxCustomizeButtonPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartToolBoxCustomizeButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridChartToolBoxCustomizeButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartToolBoxCustomizeButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxCustomizeButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartToolBoxDiagramSelectorPainter;
class DELPHICLASS TcxGridChartToolBoxDiagramSelectorViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxDiagramSelectorPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartToolBoxDiagramSelectorViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawImage(void);
	virtual void __fastcall PrepareCanvasForDrawText(void);
	__property TcxGridChartToolBoxDiagramSelectorViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartToolBoxDiagramSelectorPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxDiagramSelectorPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartToolBoxPainter;
class DELPHICLASS TcxGridChartToolBoxViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridChartToolBoxViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawDataLevelInfoConnectors(void);
	virtual void __fastcall DrawItems(bool AOpaqueItems);
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxGridChartToolBoxViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridChartToolBoxPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPainter : public Cxgridcustomview::TcxCustomGridPainter
{
	typedef Cxgridcustomview::TcxCustomGridPainter inherited;
	
private:
	HIDESBASE TcxGridChartViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall PaintAfter(void);
	virtual void __fastcall PaintContent(void);
	
public:
	__property TcxGridChartViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxGridChartPainter(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridPainter(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridChartPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartViewData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartViewData : public Cxgridcustomview::TcxCustomGridViewData
{
	typedef Cxgridcustomview::TcxCustomGridViewData inherited;
	
private:
	int FDataGroupIndex;
	Cxvariants::TVariantArray FSumOfValues;
	System::Variant __fastcall GetCategory(int AIndex);
	int __fastcall GetCategoryCount(void);
	int __fastcall GetChildCount(void);
	int __fastcall GetChildDataGroupIndex(int Index);
	int __fastcall GetChildLevel(void);
	int __fastcall GetChildRecordIndex(int Index);
	int __fastcall GetDataGroupIndex(void);
	TcxGridChartView* __fastcall GetGridView(void);
	System::Variant __fastcall GetGroupValue(int ADataGroupIndex, int AIndex);
	bool __fastcall GetIsEmptyValue(int ASeriesIndex, int AIndex);
	System::Variant __fastcall GetSumOfValues(int ASeriesIndex);
	System::Variant __fastcall GetValue(int ASeriesIndex, int AIndex);
	System::Variant __fastcall GetVisibleCategory(int AIndex);
	int __fastcall GetVisibleCategoryCount(void);
	System::Variant __fastcall GetVisibleGroupValue(int AVisibleDataGroupIndex, int AIndex);
	int __fastcall GetVisibleGroupValueCount(int AVisibleDataGroupIndex);
	System::Variant __fastcall GetVisibleValue(int ASeriesIndex, int AIndex);
	void __fastcall SetCategory(int AIndex, const System::Variant &Value);
	void __fastcall SetCategoryCount(int Value);
	void __fastcall SetGroupValue(int ADataGroupIndex, int AIndex, const System::Variant &Value);
	void __fastcall SetValue(int ASeriesIndex, int AIndex, const System::Variant &Value);
	
protected:
	virtual int __fastcall CalculateDataGroupIndex(void);
	virtual System::Variant __fastcall CalculateSumOfValues(int ASeriesIndex);
	void __fastcall CheckValueAtLevel(int ALevel, System::Variant &AValue);
	int __fastcall GetDataGroupIndexByLevel(int ALevel);
	int __fastcall GetRecordIndexByValueIndex(int AValueIndex);
	virtual void __fastcall DataLevelsChanged(void);
	bool __fastcall IsDataGrouped(void);
	bool __fastcall IsSummaryLevel(void);
	void __fastcall CalculateSumsOfValues(void);
	virtual void __fastcall SeriesPosChanged(TcxGridChartSeries* ASeries);
	virtual void __fastcall Update(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	void __fastcall UpdateDataGroupIndex(void);
	void __fastcall UpdateSumsOfValues(void);
	__property int ChildCount = {read=GetChildCount, nodefault};
	__property int ChildDataGroupIndex[int Index] = {read=GetChildDataGroupIndex};
	__property int ChildLevel = {read=GetChildLevel, nodefault};
	__property int ChildRecordIndex[int Index] = {read=GetChildRecordIndex};
	__property int DataGroupIndex = {read=GetDataGroupIndex, nodefault};
	
public:
	__fastcall virtual TcxGridChartViewData(Cxgridcustomview::TcxCustomGridView* AGridView);
	void __fastcall GetVisibleGroupValues(TcxGridChartDataGroup* ADataGroup, System::Classes::TStrings* AStrings, /* out */ Cxvariants::TVariantArray &AValues);
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property System::Variant SumOfValues[int ASeriesIndex] = {read=GetSumOfValues};
	__property System::Variant Categories[int AIndex] = {read=GetCategory, write=SetCategory};
	__property int CategoryCount = {read=GetCategoryCount, write=SetCategoryCount, nodefault};
	__property System::Variant GroupValues[int ADataGroupIndex][int AIndex] = {read=GetGroupValue, write=SetGroupValue};
	__property System::Variant Values[int ASeriesIndex][int AIndex] = {read=GetValue, write=SetValue};
	__property bool IsEmptyValue[int ASeriesIndex][int AIndex] = {read=GetIsEmptyValue};
	__property System::Variant VisibleCategories[int AIndex] = {read=GetVisibleCategory};
	__property int VisibleCategoryCount = {read=GetVisibleCategoryCount, nodefault};
	__property System::Variant VisibleValues[int ASeriesIndex][int AIndex] = {read=GetVisibleValue};
	__property int VisibleGroupValueCount[int AVisibleDataGroupIndex] = {read=GetVisibleGroupValueCount};
	__property System::Variant VisibleGroupValues[int AVisibleDataGroupIndex][int AIndex] = {read=GetVisibleGroupValue};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridChartViewData(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridChartPartViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridChartPartViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	TcxGridChartViewInfo* __fastcall GetGridViewInfo(void);
	
protected:
	virtual TcxGridChartPartAlignment __fastcall GetAlignment(void) = 0 ;
	virtual int __fastcall GetHeight(void);
	virtual TcxGridChartPartOrientation __fastcall GetOrientation(void) = 0 ;
	virtual TcxGridChartPartPosition __fastcall GetPosition(void) = 0 ;
	virtual bool __fastcall GetVisible(void);
	virtual int __fastcall GetWidth(void);
	
public:
	__property TcxGridChartPartAlignment Alignment = {read=GetAlignment, nodefault};
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property TcxGridChartViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridChartPartOrientation Orientation = {read=GetOrientation, nodefault};
	__property TcxGridChartPartPosition Position = {read=GetPosition, nodefault};
public:
	/* TcxCustomGridViewCellViewInfo.Create */ inline __fastcall virtual TcxCustomGridChartPartViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo) : Cxgridcustomview::TcxCustomGridViewCellViewInfo(AGridViewInfo) { }
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxCustomGridChartPartViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridChartTitle;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridChartTitleViewInfo : public TcxCustomGridChartPartViewInfo
{
	typedef TcxCustomGridChartPartViewInfo inherited;
	
private:
	TcxCustomGridChartTitle* FTitle;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TcxGridChartPartAlignment __fastcall GetAlignment(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxgraphics::TcxRotationAngle __fastcall GetDrawTextRotationAngle(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual TcxGridChartPartOrientation __fastcall GetOrientation(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridChartPartPosition __fastcall GetPosition(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual bool __fastcall HasBackground(void);
	
public:
	__fastcall virtual TcxCustomGridChartTitleViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxCustomGridChartTitle* ATitle);
	__property TcxCustomGridChartTitle* Title = {read=FTitle};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxCustomGridChartTitleViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartLegendItemViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLegendItemViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridChartLegendViewInfo* FContainer;
	int FIndex;
	TcxGridChartDiagram* __fastcall GetDiagram(void);
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	int __fastcall GetLegendKeyHeight(void);
	int __fastcall GetLegendKeyWidth(void);
	TcxGridChartSeries* __fastcall GetSeries(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual int __fastcall CalculateLegendKeyHeight(void);
	virtual int __fastcall CalculateLegendKeySize(void);
	virtual int __fastcall CalculateLegendKeyWidth(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoCalculateParams(void);
	virtual System::Types::TRect __fastcall GetDesignSelectionBounds(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual Cxgraphics::TcxBorders __fastcall GetLegendKeyBorders(void);
	virtual System::Types::TRect __fastcall GetLegendKeyBounds(void);
	virtual int __fastcall GetLegendKeyOffset(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall HasCustomDraw(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	__property int LegendKeyHeight = {read=GetLegendKeyHeight, nodefault};
	__property int LegendKeyOffset = {read=GetLegendKeyOffset, nodefault};
	__property int LegendKeyWidth = {read=GetLegendKeyWidth, nodefault};
	
public:
	Cxgraphics::TcxViewParams LegendKeyParams;
	__fastcall virtual TcxGridChartLegendItemViewInfo(TcxGridChartLegendViewInfo* AContainer, int AIndex);
	virtual System::Types::TRect __fastcall GetAreaBoundsForPainting(void);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxGridChartLegendViewInfo* Container = {read=FContainer};
	__property TcxGridChartDiagram* Diagram = {read=GetDiagram};
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property int Index = {read=FIndex, nodefault};
	__property Cxgraphics::TcxBorders LegendKeyBorders = {read=GetLegendKeyBorders, nodefault};
	__property System::Types::TRect LegendKeyBounds = {read=GetLegendKeyBounds};
	__property TcxGridChartSeries* Series = {read=GetSeries};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartLegendItemViewInfo(void) { }
	
};

#pragma pack(pop)

enum TcxGridChartLegendKind : unsigned char { lkSeries, lkCategories };

typedef System::TMetaClass* TcxGridChartLegendViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLegendViewInfo : public TcxCustomGridChartPartViewInfo
{
	typedef TcxCustomGridChartPartViewInfo inherited;
	
private:
	TcxGridChartDiagram* FDiagram;
	int FItemLegendKeyWidth;
	int FItemLegendKeyHeight;
	int FItemOffset;
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxGridChartLegendItemViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetItemLegendKeyWidth(void);
	int __fastcall GetItemLegendKeyHeight(void);
	int __fastcall GetItemOffset(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual int __fastcall CalculateItemLegendKeyWidth(void);
	virtual int __fastcall CalculateItemLegendKeyHeight(void);
	virtual int __fastcall CalculateItemOffset(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxGridChartPartAlignment __fastcall GetAlignment(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual TcxGridChartPartOrientation __fastcall GetOrientation(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridChartPartPosition __fastcall GetPosition(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall HasCustomDraw(void);
	TcxGridChartLegendItemViewInfo* __fastcall AddItem(void);
	virtual void __fastcall CalculateItems(void);
	virtual System::UnicodeString __fastcall GetItemCaption(int AIndex);
	virtual TcxGridChartLegendItemViewInfoClass __fastcall GetItemClass(void);
	virtual int __fastcall GetItemCount(void);
	virtual int __fastcall GetItemObjectIndex(int AIndex) = 0 ;
	virtual int __fastcall GetItemSeriesIndex(int AIndex);
	virtual int __fastcall GetItemValueIndex(int AIndex);
	virtual TcxGridChartLegendKind __fastcall GetKind(void) = 0 ;
	__property int ItemLegendKeyWidth = {read=GetItemLegendKeyWidth, nodefault};
	__property int ItemLegendKeyHeight = {read=GetItemLegendKeyHeight, nodefault};
	__property int ItemOffset = {read=GetItemOffset, nodefault};
	
public:
	__fastcall virtual TcxGridChartLegendViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram);
	__fastcall virtual ~TcxGridChartLegendViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual void __fastcall GetItemLegendKeyParams(int AIndex, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridChartDiagram* Diagram = {read=FDiagram};
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridChartLegendItemViewInfo* Items[int Index] = {read=GetItem};
	__property TcxGridChartLegendKind Kind = {read=GetKind, nodefault};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartDiagramValueCaptionViewInfoClass;

class DELPHICLASS TcxGridChartDiagramValueCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDiagramValueCaptionViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridChartDiagramValueViewInfo* FValueViewInfo;
	
protected:
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual int __fastcall GetTextAttributes(bool AForPainting);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall HasCustomDraw(void);
	virtual bool __fastcall HasVisualCompensation(void);
	
public:
	__fastcall virtual TcxGridChartDiagramValueCaptionViewInfo(TcxGridChartDiagramValueViewInfo* AValueViewInfo);
	__property TcxGridChartDiagramValueViewInfo* ValueViewInfo = {read=FValueViewInfo};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartDiagramValueCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartDiagramValueViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDiagramValueViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridChartDiagramValueCaptionViewInfo* FCaptionViewInfo;
	TcxGridChartDiagramViewInfo* FDiagramViewInfo;
	int FSeriesIndex;
	int FVisibleValueIndex;
	HIDESBASE TcxGridChartController* __fastcall GetController(void);
	TcxGridChartDiagram* __fastcall GetDiagram(void);
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	TcxGridChartSeries* __fastcall GetSeries(void);
	int __fastcall GetValueIndex(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateCaptionBounds(void) = 0 ;
	virtual bool __fastcall CanShowHint(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxGridChartDiagramValueCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual System::UnicodeString __fastcall GetCaptionText(void);
	virtual void __fastcall GetCaptionViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual System::Types::TRect __fastcall GetCellBoundsForHint(void);
	virtual System::UnicodeString __fastcall GetHintText(void);
	virtual System::Types::TRect __fastcall GetHintTextRect(const System::Types::TPoint &AMousePos);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasCaption(void);
	virtual bool __fastcall HasCaptionVisualCompensation(void);
	virtual bool __fastcall HasCustomDraw(void);
	virtual bool __fastcall HasHintPoint(const System::Types::TPoint &P);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall IsHintAtMousePos(void);
	virtual bool __fastcall IsHintForText(void);
	virtual bool __fastcall IsHintMultiLine(void);
	virtual void __fastcall StateChanged(Cxgridcommon::TcxGridCellState APrevState);
	__property TcxGridChartController* Controller = {read=GetController};
	__property TcxGridChartDiagram* Diagram = {read=GetDiagram};
	
public:
	__fastcall virtual TcxGridChartDiagramValueViewInfo(TcxGridChartDiagramViewInfo* ADiagramViewInfo, int ASeriesIndex, int AVisibleValueIndex);
	__fastcall virtual ~TcxGridChartDiagramValueViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxGridChartDiagramValueCaptionViewInfo* CaptionViewInfo = {read=FCaptionViewInfo};
	__property TcxGridChartDiagramViewInfo* DiagramViewInfo = {read=FDiagramViewInfo};
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property TcxGridChartSeries* Series = {read=GetSeries};
	__property int SeriesIndex = {read=FSeriesIndex, nodefault};
	__property int ValueIndex = {read=GetValueIndex, nodefault};
	__property int VisibleValueIndex = {read=FVisibleValueIndex, nodefault};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartDiagramViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDiagramViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridChartDiagram* FDiagram;
	System::Classes::TList* FValueViewInfos;
	System::UnicodeString __fastcall GetCategory(int AIndex);
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	TcxGridChartSeries* __fastcall GetSeries(int AIndex);
	int __fastcall GetSeriesCount(void);
	int __fastcall GetValueCount(void);
	TcxGridChartDiagramValueViewInfo* __fastcall GetValueViewInfoValue(int Index);
	int __fastcall GetValueViewInfoCount(void);
	TcxGridChartViewData* __fastcall GetViewData(void);
	
protected:
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	TcxGridChartDiagramValueViewInfo* __fastcall CreateValueViewInfo(int ASeriesIndex, int AVisibleValueIndex);
	virtual System::Variant __fastcall GetValue(int ASeriesIndex, int AIndex);
	virtual System::UnicodeString __fastcall GetValueCaption(int ASeriesIndex, int AVisibleValueIndex);
	virtual int __fastcall GetValueIndex(int AVisibleValueIndex);
	__classmethod virtual TcxGridChartDiagramValueViewInfoClass __fastcall GetValueViewInfoClass();
	virtual int __fastcall GetValueViewInfoIndex(int ASeriesIndex, int AVisibleIndex) = 0 ;
	virtual System::UnicodeString __fastcall GetVisibleCategory(int AIndex);
	virtual System::Variant __fastcall GetVisibleValue(int ASeriesIndex, int AIndex);
	virtual int __fastcall GetVisibleValueCount(void);
	__property System::UnicodeString Categories[int AIndex] = {read=GetCategory};
	__property System::Variant Values[int ASeriesIndex][int AIndex] = {read=GetValue};
	__property TcxGridChartSeries* Series[int AIndex] = {read=GetSeries};
	
public:
	__fastcall virtual TcxGridChartDiagramViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram);
	__fastcall virtual ~TcxGridChartDiagramViewInfo(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	TcxGridChartDiagramValueViewInfo* __fastcall GetValueViewInfo(int ASeriesIndex, int AVisibleIndex);
	__property TcxGridChartDiagram* Diagram = {read=FDiagram};
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property int SeriesCount = {read=GetSeriesCount, nodefault};
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property int ValueViewInfoCount = {read=GetValueViewInfoCount, nodefault};
	__property TcxGridChartDiagramValueViewInfo* ValueViewInfos[int Index] = {read=GetValueViewInfoValue};
	__property TcxGridChartViewData* ViewData = {read=GetViewData};
	__property System::UnicodeString VisibleCategories[int AIndex] = {read=GetVisibleCategory};
	__property int VisibleValueCount = {read=GetVisibleValueCount, nodefault};
	__property System::Variant VisibleValues[int ASeriesIndex][int AIndex] = {read=GetVisibleValue};
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramLegendViewInfo;
class DELPHICLASS TcxGridChartHistogram;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramLegendViewInfo : public TcxGridChartLegendViewInfo
{
	typedef TcxGridChartLegendViewInfo inherited;
	
private:
	TcxGridChartHistogram* __fastcall GetDiagram(void);
	
protected:
	virtual int __fastcall GetItemObjectIndex(int AIndex);
	virtual bool __fastcall GetItemsInReverseOrder(void);
	virtual TcxGridChartLegendKind __fastcall GetKind(void);
	__property bool ItemsInReverseOrder = {read=GetItemsInReverseOrder, nodefault};
	
public:
	__property TcxGridChartHistogram* Diagram = {read=GetDiagram};
public:
	/* TcxGridChartLegendViewInfo.Create */ inline __fastcall virtual TcxGridChartHistogramLegendViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartLegendViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartLegendViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramLegendViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramValueViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramValueViewInfo : public TcxGridChartDiagramValueViewInfo
{
	typedef TcxGridChartDiagramValueViewInfo inherited;
	
private:
	Cxclasses::TcxDirection __fastcall GetCategoryDirection(void);
	TcxGridChartHistogramViewInfo* __fastcall GetDiagramViewInfo(void);
	Cxclasses::TcxDirection __fastcall GetValueDirection(void);
	
public:
	__property Cxclasses::TcxDirection CategoryDirection = {read=GetCategoryDirection, nodefault};
	__property TcxGridChartHistogramViewInfo* DiagramViewInfo = {read=GetDiagramViewInfo};
	__property Cxclasses::TcxDirection ValueDirection = {read=GetValueDirection, nodefault};
public:
	/* TcxGridChartDiagramValueViewInfo.Create */ inline __fastcall virtual TcxGridChartHistogramValueViewInfo(TcxGridChartDiagramViewInfo* ADiagramViewInfo, int ASeriesIndex, int AVisibleValueIndex) : TcxGridChartDiagramValueViewInfo(ADiagramViewInfo, ASeriesIndex, AVisibleValueIndex) { }
	/* TcxGridChartDiagramValueViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramValueViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartHistogramAxisTitleViewInfoClass;

class DELPHICLASS TcxGridChartHistogramAxisTitleViewInfo;
class DELPHICLASS TcxGridChartHistogramAxisTitle;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramAxisTitleViewInfo : public TcxCustomGridChartTitleViewInfo
{
	typedef TcxCustomGridChartTitleViewInfo inherited;
	
private:
	TcxGridChartHistogramTickMarkLabelsViewInfo* FContainer;
	TcxGridChartHistogramAxisTitle* __fastcall GetTitle(void);
	
protected:
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	
public:
	__fastcall virtual TcxGridChartHistogramAxisTitleViewInfo(TcxGridChartHistogramTickMarkLabelsViewInfo* AContainer, TcxCustomGridChartTitle* ATitle);
	__property TcxGridChartHistogramTickMarkLabelsViewInfo* Container = {read=FContainer};
	__property TcxGridChartHistogramAxisTitle* Title = {read=GetTitle};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramAxisTitleViewInfo(void) { }
	
};

#pragma pack(pop)

typedef TcxGridChartPartPosition TcxGridChartAxisPosition;

class DELPHICLASS TcxGridChartHistogramAxis;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramTickMarkLabelsViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	typedef System::DynamicArray<int> _TcxGridChartHistogramTickMarkLabelsViewInfo__1;
	
	
private:
	Cxgraphics::TRectArray FCaptionBounds;
	int FCaptionHeight;
	_TcxGridChartHistogramTickMarkLabelsViewInfo__1 FCaptionWidths;
	TcxGridChartHistogramViewInfo* FDiagramViewInfo;
	bool FIsTwoRowLayout;
	TcxGridChartHistogramAxisTitleViewInfo* FTitleViewInfo;
	System::Types::TRect __fastcall GetCaptionBounds(int Index);
	int __fastcall GetCaptionHeight(void);
	int __fastcall GetCaptionWidth(int Index);
	TcxGridChartHistogram* __fastcall GetDiagram(void);
	bool __fastcall GetIsVertical(void);
	void __fastcall SetCaptionBounds(int Index, const System::Types::TRect &Value);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridChartHistogramAxisTitleViewInfoClass __fastcall GetTitleViewInfoClass(void);
	virtual System::UnicodeString __fastcall GetCaption(int Index);
	virtual int __fastcall GetCount(void) = 0 ;
	virtual bool __fastcall GetIsReverseOrder(void) = 0 ;
	virtual System::Variant __fastcall GetValue(int Index) = 0 ;
	virtual System::Types::TRect __fastcall CalculateCaptionBounds(int AIndex);
	virtual void __fastcall CalculateCaptionsBounds(void);
	HIDESBASE virtual int __fastcall CalculateHeight(int AWidth, int ALeftReduction, int ARightReduction);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CalculateIsTwoRowLayout(int AWidth, int ALeftReduction, int ARightReduction);
	virtual void __fastcall CalculateTitleBounds(/* out */ System::Types::TRect &ATitleBounds, /* out */ System::Types::TRect &AContentBounds);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual TcxGridChartHistogramAxis* __fastcall GetAxis(void) = 0 ;
	virtual int __fastcall GetCaptionPosition(int AIndex) = 0 ;
	virtual bool __fastcall GetCaptionsVisible(void);
	virtual void __fastcall GetEdgeCaptionsReductions(int &ALeftReduction, int &ARightReduction);
	virtual bool __fastcall GetIsEdgeCaptions(void) = 0 ;
	virtual TcxGridChartAxisPosition __fastcall GetPosition(void) = 0 ;
	virtual int __fastcall GetTextAttributes(bool AForPainting);
	virtual void __fastcall GetTitleViewParams(Cxgraphics::TcxViewParams &AParams) = 0 ;
	virtual bool __fastcall GetVisible(void);
	__property TcxGridChartHistogramAxis* Axis = {read=GetAxis};
	__property int CaptionHeight = {read=GetCaptionHeight, nodefault};
	__property int CaptionWidths[int Index] = {read=GetCaptionWidth};
	__property TcxGridChartHistogram* Diagram = {read=GetDiagram};
	__property bool IsEdgeCaptions = {read=GetIsEdgeCaptions, nodefault};
	__property bool IsReverseOrder = {read=GetIsReverseOrder, nodefault};
	__property bool IsTwoRowLayout = {read=FIsTwoRowLayout, write=FIsTwoRowLayout, nodefault};
	__property bool IsVertical = {read=GetIsVertical, nodefault};
	
public:
	__fastcall virtual TcxGridChartHistogramTickMarkLabelsViewInfo(TcxGridChartHistogramViewInfo* ADiagramViewInfo);
	__fastcall virtual ~TcxGridChartHistogramTickMarkLabelsViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual void __fastcall FitCaptionsHorz(int AWidth, int &ALeftReduction, int &ARightReduction);
	virtual void __fastcall FitCaptionsVert(int &ATopReduction, int &ABottomReduction);
	virtual int __fastcall GetCaptionSpace(int AWidth, int ALeftReduction, int ARightReduction);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property System::Types::TRect CaptionBounds[int Index] = {read=GetCaptionBounds, write=SetCaptionBounds};
	__property System::UnicodeString Captions[int Index] = {read=GetCaption};
	__property bool CaptionsVisible = {read=GetCaptionsVisible, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridChartHistogramViewInfo* DiagramViewInfo = {read=FDiagramViewInfo};
	__property TcxGridChartAxisPosition Position = {read=GetPosition, nodefault};
	__property TcxGridChartHistogramAxisTitleViewInfo* TitleViewInfo = {read=FTitleViewInfo};
	__property System::Variant Values[int Index] = {read=GetValue};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramCategoryAxisTitleViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramCategoryAxisTitleViewInfo : public TcxGridChartHistogramAxisTitleViewInfo
{
	typedef TcxGridChartHistogramAxisTitleViewInfo inherited;
	
protected:
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
public:
	/* TcxGridChartHistogramAxisTitleViewInfo.Create */ inline __fastcall virtual TcxGridChartHistogramCategoryAxisTitleViewInfo(TcxGridChartHistogramTickMarkLabelsViewInfo* AContainer, TcxCustomGridChartTitle* ATitle) : TcxGridChartHistogramAxisTitleViewInfo(AContainer, ATitle) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramCategoryAxisTitleViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartHistogramCategoryTickMarkLabelsViewInfoClass;

class DELPHICLASS TcxGridChartHistogramCategoryTickMarkLabelsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramCategoryTickMarkLabelsViewInfo : public TcxGridChartHistogramTickMarkLabelsViewInfo
{
	typedef TcxGridChartHistogramTickMarkLabelsViewInfo inherited;
	
protected:
	virtual TcxGridChartHistogramAxisTitleViewInfoClass __fastcall GetTitleViewInfoClass(void);
	virtual int __fastcall GetCount(void);
	virtual bool __fastcall GetIsReverseOrder(void);
	virtual System::Variant __fastcall GetValue(int Index);
	virtual TcxGridChartHistogramAxis* __fastcall GetAxis(void);
	virtual int __fastcall GetCaptionPosition(int AIndex);
	virtual bool __fastcall GetIsEdgeCaptions(void);
	virtual TcxGridChartAxisPosition __fastcall GetPosition(void);
	virtual void __fastcall GetTitleViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
public:
	/* TcxGridChartHistogramTickMarkLabelsViewInfo.Create */ inline __fastcall virtual TcxGridChartHistogramCategoryTickMarkLabelsViewInfo(TcxGridChartHistogramViewInfo* ADiagramViewInfo) : TcxGridChartHistogramTickMarkLabelsViewInfo(ADiagramViewInfo) { }
	/* TcxGridChartHistogramTickMarkLabelsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramCategoryTickMarkLabelsViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartHistogramValueAxisTitleViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramValueAxisTitleViewInfo : public TcxGridChartHistogramAxisTitleViewInfo
{
	typedef TcxGridChartHistogramAxisTitleViewInfo inherited;
	
protected:
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
public:
	/* TcxGridChartHistogramAxisTitleViewInfo.Create */ inline __fastcall virtual TcxGridChartHistogramValueAxisTitleViewInfo(TcxGridChartHistogramTickMarkLabelsViewInfo* AContainer, TcxCustomGridChartTitle* ATitle) : TcxGridChartHistogramAxisTitleViewInfo(AContainer, ATitle) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramValueAxisTitleViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartHistogramValueTickMarkLabelsViewInfoClass;

class DELPHICLASS TcxGridChartHistogramValueTickMarkLabelsViewInfo;
class DELPHICLASS TcxGridChartHistogramAxisValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramValueTickMarkLabelsViewInfo : public TcxGridChartHistogramTickMarkLabelsViewInfo
{
	typedef TcxGridChartHistogramTickMarkLabelsViewInfo inherited;
	
private:
	TcxGridChartHistogramAxisValue* __fastcall GetAxisValue(void);
	
protected:
	virtual TcxGridChartHistogramAxisTitleViewInfoClass __fastcall GetTitleViewInfoClass(void);
	virtual System::UnicodeString __fastcall GetCaption(int Index);
	virtual int __fastcall GetCount(void);
	virtual bool __fastcall GetIsReverseOrder(void);
	virtual System::Variant __fastcall GetValue(int Index);
	virtual TcxGridChartHistogramAxis* __fastcall GetAxis(void);
	virtual int __fastcall GetCaptionPosition(int AIndex);
	virtual bool __fastcall GetIsEdgeCaptions(void);
	virtual TcxGridChartAxisPosition __fastcall GetPosition(void);
	virtual void __fastcall GetTitleViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	__property TcxGridChartHistogramAxisValue* Axis = {read=GetAxisValue};
public:
	/* TcxGridChartHistogramTickMarkLabelsViewInfo.Create */ inline __fastcall virtual TcxGridChartHistogramValueTickMarkLabelsViewInfo(TcxGridChartHistogramViewInfo* ADiagramViewInfo) : TcxGridChartHistogramTickMarkLabelsViewInfo(ADiagramViewInfo) { }
	/* TcxGridChartHistogramTickMarkLabelsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramValueTickMarkLabelsViewInfo(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxGridChartHistogramMark
{
public:
	System::Variant Value;
	int Position;
};


typedef System::DynamicArray<TcxGridChartHistogramMark> TcxGridChartHistogramMarks;

class PASCALIMPLEMENTATION TcxGridChartHistogramViewInfo : public TcxGridChartDiagramViewInfo
{
	typedef TcxGridChartDiagramViewInfo inherited;
	
private:
	typedef System::DynamicArray<Cxvariants::TVariantArray> _TcxGridChartHistogramViewInfo__1;
	
	
private:
	TcxGridChartHistogramCategoryTickMarkLabelsViewInfo* FCategoryTickMarkLabelsViewInfo;
	int FCategoryMarkHeight;
	TcxGridChartHistogramMarks FCategoryMarks;
	bool FHasValuesOutOfRange;
	bool FIsPlotBoundsCalculated;
	System::Extended FMinValue;
	System::Extended FMaxValue;
	System::Extended FMinVisualValue;
	System::Extended FMaxVisualValue;
	System::Types::TRect FPlotBounds;
	_TcxGridChartHistogramViewInfo__1 FSumOfValues;
	TcxGridChartHistogramValueTickMarkLabelsViewInfo* FValueTickMarkLabelsViewInfo;
	int FValueMarkHeight;
	TcxGridChartHistogramMarks FValueMarks;
	System::Extended FValueStep;
	System::Uitypes::TColor __fastcall GetCategoryAxisColor(void);
	System::Uitypes::TColor __fastcall GetCategoryGridLineColor(void);
	int __fastcall GetCategoryMarkCount(void);
	int __fastcall GetCategoryMarkPosition(int Index);
	int __fastcall GetCategoryMarkValue(int Index);
	TcxGridChartHistogram* __fastcall GetDiagram(void);
	bool __fastcall GetHasCategoryAxis(void);
	bool __fastcall GetHasCategoryGridLines(void);
	bool __fastcall GetHasValueAxis(void);
	bool __fastcall GetHasValueGridLines(void);
	bool __fastcall GetIsCategoriesInReverseOrder(void);
	bool __fastcall GetIsCategoryAxisHorz(void);
	bool __fastcall GetIsValueAxisVert(void);
	System::Types::TRect __fastcall GetPlotBounds(void);
	System::Variant __fastcall GetSumOfValues(int AGroupIndex, int AValueIndex);
	System::Uitypes::TColor __fastcall GetValueAxisColor(void);
	System::Uitypes::TColor __fastcall GetValueGridLineColor(void);
	int __fastcall GetValueMarkCount(void);
	int __fastcall GetValueMarkPosition(int Index);
	System::Extended __fastcall GetValueMarkValue(int Index);
	int __fastcall GetZeroValueOffset(void);
	void __fastcall SetCategoryMarkPosition(int Index, int Value);
	void __fastcall SetValueMarkPosition(int Index, int Value);
	
protected:
	virtual TcxGridChartHistogramCategoryTickMarkLabelsViewInfoClass __fastcall GetCategoryTickMarkLabelsViewInfoClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridChartHistogramValueTickMarkLabelsViewInfoClass __fastcall GetValueTickMarkLabelsViewInfoClass(void);
	virtual void __fastcall DoCalculateParams(void);
	virtual void __fastcall GetPlotBackgroundParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual Cxclasses::TcxDirection __fastcall GetCategoryDirection(void);
	virtual int __fastcall GetCategoryTickMarkLabelOffsetUnits(int AIndex) = 0 ;
	virtual int __fastcall GetCategoryTickMarkOffsetUnits(int AIndex, bool AValueAxisBetweenCategories) = 0 ;
	virtual int __fastcall GetUnitAdjustedOffset(int AIndex);
	virtual int __fastcall GetUnitCount(void) = 0 ;
	virtual int __fastcall GetUnitOffset(int AIndex);
	virtual bool __fastcall IsEdgeCategoryTickMarkLabels(void) = 0 ;
	virtual void __fastcall CalculateMinMaxValues(/* out */ System::Extended &AMinValue, /* out */ System::Extended &AMaxValue, /* out */ bool &AHasValuesOutOfRange);
	void __fastcall CalculateMinMaxStackedValues(bool APercentage, /* out */ System::Extended &AMinValue, /* out */ System::Extended &AMaxValue, /* out */ bool &AHasValuesOutOfRange);
	virtual void __fastcall CalculateMinMaxVisualValues(/* out */ System::Extended &AMinVisualValue, /* out */ System::Extended &AMaxVisualValue);
	virtual System::Variant __fastcall CalculateSumOfValues(int AGroupIndex, int AValueIndex);
	virtual System::Extended __fastcall CalculateValueStep(void);
	virtual System::Variant __fastcall GetStackedValue(int ASeriesIndex, int AIndex);
	virtual System::Variant __fastcall GetValue(int ASeriesIndex, int AIndex);
	virtual Cxclasses::TcxDirection __fastcall GetValueDirection(int ASeriesIndex, int AVisibleValueIndex);
	virtual int __fastcall GetValueOffset(const System::Variant &AValue);
	virtual int __fastcall GetVisibleGroupIndex(int ASeriesIndex);
	virtual System::Extended __fastcall GetZeroValue(void);
	void __fastcall InitializeMinMaxValues(/* out */ System::Extended &AMinValue, /* out */ System::Extended &AMaxValue);
	bool __fastcall IsDataInteger(void);
	virtual bool __fastcall IsSeriesBeginOfGroup(int ASeriesIndex);
	virtual bool __fastcall IsValuePositive(int ASeriesIndex, int AVisibleValueIndex);
	virtual bool __fastcall NeedsMinMaxValuesOffset(void);
	void __fastcall AddMark(TcxGridChartHistogramMarks &AMarks, const System::Variant &AValue);
	void __fastcall AddCategoryMark(int AValue);
	void __fastcall CalculateCategoryMarkPositions(void);
	virtual void __fastcall CalculateCategoryMarkValues(void);
	void __fastcall AddValueMark(const System::Extended AValue);
	void __fastcall CalculateValueMarkPositions(void);
	virtual void __fastcall CalculateValueMarkValues(void);
	virtual int __fastcall CalculateCategoryMarkHeight(void);
	virtual int __fastcall CalculateValueMarkHeight(void);
	virtual System::Types::TRect __fastcall CalculatePlotBounds(void);
	virtual void __fastcall CalculatePlotOffsets(int APlotAreaWidth, System::Types::TRect &AOffsets);
	virtual void __fastcall CalculateValues(void) = 0 ;
	virtual System::Types::TRect __fastcall GetCategoryAxisBounds(void);
	virtual TcxGridChartAxisPosition __fastcall GetCategoryAxisPosition(void);
	virtual System::Types::TRect __fastcall GetCategoryGridLineBounds(int AIndex);
	virtual System::Types::TRect __fastcall GetCategoryMarkBounds(int Index);
	virtual System::Types::TRect __fastcall GetCategoryTickMarkLabelsBounds(void);
	virtual System::Types::TRect __fastcall GetTickMarkLabelsBounds(TcxGridChartAxisPosition APosition);
	virtual System::Types::TRect __fastcall GetValueAxisBounds(void);
	virtual TcxGridChartAxisPosition __fastcall GetValueAxisPosition(void);
	virtual System::Types::TRect __fastcall GetValueGridLineBounds(int AIndex);
	virtual System::Types::TRect __fastcall GetValueMarkBounds(int Index);
	virtual System::Types::TRect __fastcall GetValueTickMarkLabelsBounds(void);
	virtual bool __fastcall CustomDrawPlot(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall DoCustomDrawPlot(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall HasCustomDrawPlot(void);
	__property int CategoryMarkHeight = {read=FCategoryMarkHeight, nodefault};
	__property int CategoryMarkValues[int Index] = {read=GetCategoryMarkValue};
	__property bool HasValuesOutOfRange = {read=FHasValuesOutOfRange, nodefault};
	__property bool IsCategoriesInReverseOrder = {read=GetIsCategoriesInReverseOrder, nodefault};
	__property bool IsCategoryAxisHorz = {read=GetIsCategoryAxisHorz, nodefault};
	__property bool IsValueAxisVert = {read=GetIsValueAxisVert, nodefault};
	__property System::Extended MinValue = {read=FMinValue};
	__property System::Extended MaxValue = {read=FMaxValue};
	__property System::Extended MinVisualValue = {read=FMinVisualValue};
	__property System::Extended MaxVisualValue = {read=FMaxVisualValue};
	__property System::Variant SumOfValues[int AGroupIndex][int AValueIndex] = {read=GetSumOfValues};
	__property int UnitCount = {read=GetUnitCount, nodefault};
	__property int ValueMarkHeight = {read=FValueMarkHeight, nodefault};
	__property System::Extended ValueMarkValues[int Index] = {read=GetValueMarkValue};
	__property System::Extended ValueStep = {read=FValueStep};
	__property System::Extended ZeroValue = {read=GetZeroValue};
	__property int ZeroValueOffset = {read=GetZeroValueOffset, nodefault};
	
public:
	Cxgraphics::TcxViewParams PlotParams;
	__fastcall virtual TcxGridChartHistogramViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram);
	__fastcall virtual ~TcxGridChartHistogramViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property System::Uitypes::TColor CategoryAxisColor = {read=GetCategoryAxisColor, nodefault};
	__property System::Types::TRect CategoryAxisBounds = {read=GetCategoryAxisBounds};
	__property TcxGridChartAxisPosition CategoryAxisPosition = {read=GetCategoryAxisPosition, nodefault};
	__property System::Types::TRect CategoryGridLineBounds[int AIndex] = {read=GetCategoryGridLineBounds};
	__property System::Uitypes::TColor CategoryGridLineColor = {read=GetCategoryGridLineColor, nodefault};
	__property System::Types::TRect CategoryMarkBounds[int Index] = {read=GetCategoryMarkBounds};
	__property TcxGridChartHistogramCategoryTickMarkLabelsViewInfo* CategoryTickMarkLabelsViewInfo = {read=FCategoryTickMarkLabelsViewInfo};
	__property int CategoryMarkCount = {read=GetCategoryMarkCount, nodefault};
	__property int CategoryMarkPositions[int Index] = {read=GetCategoryMarkPosition, write=SetCategoryMarkPosition};
	__property TcxGridChartHistogram* Diagram = {read=GetDiagram};
	__property bool HasCategoryAxis = {read=GetHasCategoryAxis, nodefault};
	__property bool HasCategoryGridLines = {read=GetHasCategoryGridLines, nodefault};
	__property bool HasValueAxis = {read=GetHasValueAxis, nodefault};
	__property bool HasValueGridLines = {read=GetHasValueGridLines, nodefault};
	__property System::Types::TRect PlotBounds = {read=GetPlotBounds};
	__property System::Types::TRect ValueAxisBounds = {read=GetValueAxisBounds};
	__property System::Uitypes::TColor ValueAxisColor = {read=GetValueAxisColor, nodefault};
	__property TcxGridChartAxisPosition ValueAxisPosition = {read=GetValueAxisPosition, nodefault};
	__property System::Types::TRect ValueGridLineBounds[int AIndex] = {read=GetValueGridLineBounds};
	__property System::Uitypes::TColor ValueGridLineColor = {read=GetValueGridLineColor, nodefault};
	__property System::Types::TRect ValueMarkBounds[int Index] = {read=GetValueMarkBounds};
	__property TcxGridChartHistogramValueTickMarkLabelsViewInfo* ValueTickMarkLabelsViewInfo = {read=FValueTickMarkLabelsViewInfo};
	__property int ValueMarkCount = {read=GetValueMarkCount, nodefault};
	__property int ValueMarkPositions[int Index] = {read=GetValueMarkPosition, write=SetValueMarkPosition};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ALeftBound, ATopBound, AWidth, AHeight); }
	
};


class DELPHICLASS TcxGridChartColumnDiagramLegendViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartColumnDiagramLegendViewInfo : public TcxGridChartHistogramLegendViewInfo
{
	typedef TcxGridChartHistogramLegendViewInfo inherited;
	
protected:
	virtual bool __fastcall GetItemsInReverseOrder(void);
public:
	/* TcxGridChartLegendViewInfo.Create */ inline __fastcall virtual TcxGridChartColumnDiagramLegendViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartHistogramLegendViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartLegendViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartColumnDiagramLegendViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartColumnDiagramValueViewInfo;
class DELPHICLASS TcxGridChartColumnDiagramViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartColumnDiagramValueViewInfo : public TcxGridChartHistogramValueViewInfo
{
	typedef TcxGridChartHistogramValueViewInfo inherited;
	
private:
	TcxGridChartColumnDiagramValueCaptionPosition __fastcall GetCaptionPosition(void);
	HIDESBASE TcxGridChartColumnDiagramViewInfo* __fastcall GetDiagramViewInfo(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateCaptionBounds(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall HasCaption(void);
	virtual bool __fastcall HasCaptionVisualCompensation(void);
	
public:
	__property TcxGridChartColumnDiagramValueCaptionPosition CaptionPosition = {read=GetCaptionPosition, nodefault};
	__property TcxGridChartColumnDiagramViewInfo* DiagramViewInfo = {read=GetDiagramViewInfo};
public:
	/* TcxGridChartDiagramValueViewInfo.Create */ inline __fastcall virtual TcxGridChartColumnDiagramValueViewInfo(TcxGridChartDiagramViewInfo* ADiagramViewInfo, int ASeriesIndex, int AVisibleValueIndex) : TcxGridChartHistogramValueViewInfo(ADiagramViewInfo, ASeriesIndex, AVisibleValueIndex) { }
	/* TcxGridChartDiagramValueViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartColumnDiagramValueViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartColumnDiagram;
class PASCALIMPLEMENTATION TcxGridChartColumnDiagramViewInfo : public TcxGridChartHistogramViewInfo
{
	typedef TcxGridChartHistogramViewInfo inherited;
	
private:
	HIDESBASE TcxGridChartColumnDiagram* __fastcall GetDiagram(void);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	__classmethod virtual TcxGridChartDiagramValueViewInfoClass __fastcall GetValueViewInfoClass();
	virtual int __fastcall GetValueViewInfoIndex(int ASeriesIndex, int AVisibleIndex);
	virtual int __fastcall GetCategoryTickMarkLabelOffsetUnits(int AIndex);
	virtual int __fastcall GetCategoryTickMarkOffsetUnits(int AIndex, bool AValueAxisBetweenCategories);
	virtual int __fastcall GetUnitCount(void);
	virtual int __fastcall GetValueGroupAreaSizeUnits(void);
	virtual int __fastcall GetValueOffsetUnits(int AVisibleValueIndex, int ASeriesIndex);
	virtual bool __fastcall IsEdgeCategoryTickMarkLabels(void);
	virtual void __fastcall CalculateValues(void);
	virtual System::Types::TRect __fastcall GetValueBounds(int AVisibleValueIndex, int ASeriesIndex);
	System::Types::TRect __fastcall MakeValueBounds(const int ACategoryStart, const int ACategoryFinish, const int AValueStart, const int AValueFinish);
	
public:
	__property TcxGridChartColumnDiagram* Diagram = {read=GetDiagram};
public:
	/* TcxGridChartHistogramViewInfo.Create */ inline __fastcall virtual TcxGridChartColumnDiagramViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartHistogramViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartHistogramViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartColumnDiagramViewInfo(void) { }
	
};


class DELPHICLASS TcxGridChartStackedColumnDiagramViewInfo;
class DELPHICLASS TcxGridChartStackedColumnDiagram;
class PASCALIMPLEMENTATION TcxGridChartStackedColumnDiagramViewInfo : public TcxGridChartColumnDiagramViewInfo
{
	typedef TcxGridChartColumnDiagramViewInfo inherited;
	
private:
	HIDESBASE TcxGridChartStackedColumnDiagram* __fastcall GetDiagram(void);
	int __fastcall GetSeriesGroupCount(void);
	
protected:
	virtual void __fastcall CalculateValues(void);
	virtual void __fastcall CalculateMinMaxValues(/* out */ System::Extended &AMinValue, /* out */ System::Extended &AMaxValue, /* out */ bool &AHasValuesOutOfRange);
	virtual System::Variant __fastcall GetValue(int ASeriesIndex, int AIndex);
	virtual int __fastcall GetValueGroupAreaSizeUnits(void);
	virtual bool __fastcall IsSeriesBeginOfGroup(int ASeriesIndex);
	int __fastcall StackedGroupIndentWidth(void);
	__property TcxGridChartStackedColumnDiagram* Diagram = {read=GetDiagram};
	__property int SeriesGroupCount = {read=GetSeriesGroupCount, nodefault};
public:
	/* TcxGridChartHistogramViewInfo.Create */ inline __fastcall virtual TcxGridChartStackedColumnDiagramViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartColumnDiagramViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartHistogramViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartStackedColumnDiagramViewInfo(void) { }
	
};


class DELPHICLASS TcxGridChartLineDiagram;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLineDiagramLegendItemViewInfo : public TcxGridChartLegendItemViewInfo
{
	typedef TcxGridChartLegendItemViewInfo inherited;
	
private:
	HIDESBASE TcxGridChartLineDiagram* __fastcall GetDiagram(void);
	TcxGridChartLineStyle __fastcall GetLineStyle(void);
	int __fastcall GetLineWidth(void);
	int __fastcall GetMarkerSize(void);
	TcxGridChartMarkerStyle __fastcall GetMarkerStyle(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateLegendKeyWidth(void);
	virtual void __fastcall CalculateMarkerPoints(void);
	virtual void __fastcall DoCalculateParams(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	TcxGridChartLineDiagramValueViewInfoClass __fastcall GetDiagramValueViewInfoClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Uitypes::TColor __fastcall GetLineColor(void);
	virtual System::Types::TPoint __fastcall GetLineStart(void);
	virtual System::Types::TPoint __fastcall GetLineFinish(void);
	virtual System::Types::TRect __fastcall GetMarkerBounds(void);
	__property int MarkerSize = {read=GetMarkerSize, nodefault};
	
public:
	Cxgraphics::TcxViewParams MarkerParams;
	Cxgraphics::TPointArray MarkerPoints;
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	__property TcxGridChartLineDiagram* Diagram = {read=GetDiagram};
	__property System::Uitypes::TColor LineColor = {read=GetLineColor, nodefault};
	__property System::Types::TPoint LineStart = {read=GetLineStart};
	__property System::Types::TPoint LineFinish = {read=GetLineFinish};
	__property TcxGridChartLineStyle LineStyle = {read=GetLineStyle, nodefault};
	__property int LineWidth = {read=GetLineWidth, nodefault};
	__property System::Types::TRect MarkerBounds = {read=GetMarkerBounds};
	__property TcxGridChartMarkerStyle MarkerStyle = {read=GetMarkerStyle, nodefault};
public:
	/* TcxGridChartLegendItemViewInfo.Create */ inline __fastcall virtual TcxGridChartLineDiagramLegendItemViewInfo(TcxGridChartLegendViewInfo* AContainer, int AIndex) : TcxGridChartLegendItemViewInfo(AContainer, AIndex) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramLegendItemViewInfo(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLineDiagramLegendViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLineDiagramLegendViewInfo : public TcxGridChartHistogramLegendViewInfo
{
	typedef TcxGridChartHistogramLegendViewInfo inherited;
	
protected:
	virtual TcxGridChartLegendItemViewInfoClass __fastcall GetItemClass(void);
	
public:
	virtual void __fastcall GetItemLegendKeyMarkerParams(int AIndex, /* out */ Cxgraphics::TcxViewParams &AParams);
public:
	/* TcxGridChartLegendViewInfo.Create */ inline __fastcall virtual TcxGridChartLineDiagramLegendViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartHistogramLegendViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartLegendViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramLegendViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLineDiagramViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLineDiagramValueViewInfo : public TcxGridChartHistogramValueViewInfo
{
	typedef TcxGridChartHistogramValueViewInfo inherited;
	
private:
	int FLineStartY;
	int FLineFinishY;
	TcxGridChartLineDiagramValueCaptionPosition __fastcall GetCaptionPosition(void);
	HIDESBASE TcxGridChartLineDiagram* __fastcall GetDiagram(void);
	HIDESBASE TcxGridChartLineDiagramViewInfo* __fastcall GetDiagramViewInfo(void);
	TcxGridChartLineStyle __fastcall GetLineStyle(void);
	int __fastcall GetLineWidth(void);
	TcxGridChartMarkerStyle __fastcall GetMarkerStyle(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateCaptionBounds(void);
	virtual void __fastcall CalculateMarkerParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall CalculateMarkerPoints(void);
	virtual void __fastcall DoCalculateParams(void);
	virtual System::Types::TRect __fastcall GetCellBoundsForHint(void);
	virtual System::Types::TRect __fastcall GetDesignSelectionBounds(void);
	virtual System::Types::TRect __fastcall GetHotSpotBounds(void);
	virtual System::Uitypes::TColor __fastcall GetLineColor(void);
	virtual int __fastcall GetLineHotZoneMinWidth(void);
	virtual System::Types::TPoint __fastcall GetLineStart(void);
	virtual System::Types::TPoint __fastcall GetLineFinish(void);
	virtual System::Types::TRect __fastcall GetMarkerBounds(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	__classmethod virtual TcxGridChartLineDiagramValuePainterClass __fastcall GetPainterClassEx();
	virtual System::Types::TPoint __fastcall GetPosition(void);
	void __fastcall MakeRealBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall HasCaption(void);
	__property TcxGridChartLineDiagram* Diagram = {read=GetDiagram};
	__property System::Types::TRect HotSpotBounds = {read=GetHotSpotBounds};
	__property int LineHotZoneMinWidth = {read=GetLineHotZoneMinWidth, nodefault};
	
public:
	Cxgraphics::TcxViewParams MarkerParams;
	Cxgraphics::TPointArray MarkerPoints;
	HIDESBASE virtual void __fastcall Calculate(const System::Types::TRect &ABounds, int ALineStartY, int ALineFinishY);
	__classmethod virtual void __fastcall CalculateMarkerPointsEx(const System::Types::TRect &ABounds, TcxGridChartMarkerStyle AStyle, Cxgraphics::TPointArray &APoints);
	virtual System::Types::TRect __fastcall GetAreaBoundsForPainting(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	HIDESBASE System::Types::TRect __fastcall GetRealBounds(void);
	virtual bool __fastcall HasPoint(const System::Types::TPoint &P);
	__property TcxGridChartLineDiagramValueCaptionPosition CaptionPosition = {read=GetCaptionPosition, nodefault};
	__property TcxGridChartLineDiagramViewInfo* DiagramViewInfo = {read=GetDiagramViewInfo};
	__property System::Uitypes::TColor LineColor = {read=GetLineColor, nodefault};
	__property System::Types::TPoint LineStart = {read=GetLineStart};
	__property System::Types::TPoint LineFinish = {read=GetLineFinish};
	__property int LineStartY = {read=FLineStartY, nodefault};
	__property int LineFinishY = {read=FLineFinishY, nodefault};
	__property TcxGridChartLineStyle LineStyle = {read=GetLineStyle, nodefault};
	__property int LineWidth = {read=GetLineWidth, nodefault};
	__property System::Types::TRect MarkerBounds = {read=GetMarkerBounds};
	__property TcxGridChartMarkerStyle MarkerStyle = {read=GetMarkerStyle, nodefault};
	__property System::Types::TPoint Position = {read=GetPosition};
public:
	/* TcxGridChartDiagramValueViewInfo.Create */ inline __fastcall virtual TcxGridChartLineDiagramValueViewInfo(TcxGridChartDiagramViewInfo* ADiagramViewInfo, int ASeriesIndex, int AVisibleValueIndex) : TcxGridChartHistogramValueViewInfo(ADiagramViewInfo, ASeriesIndex, AVisibleValueIndex) { }
	/* TcxGridChartDiagramValueViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramValueViewInfo(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGridChartLineDiagramViewInfo : public TcxGridChartHistogramViewInfo
{
	typedef TcxGridChartHistogramViewInfo inherited;
	
private:
	HIDESBASE TcxGridChartLineDiagram* __fastcall GetDiagram(void);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	__classmethod virtual TcxGridChartDiagramValueViewInfoClass __fastcall GetValueViewInfoClass();
	virtual int __fastcall GetValueViewInfoIndex(int ASeriesIndex, int AVisibleIndex);
	virtual int __fastcall GetCategoryTickMarkLabelOffsetUnits(int AIndex);
	virtual int __fastcall GetCategoryTickMarkOffsetUnits(int AIndex, bool AValueAxisBetweenCategories);
	virtual int __fastcall GetUnitCount(void);
	virtual int __fastcall GetValueOffsetUnits(int AVisibleValueIndex, int ASeriesIndex);
	virtual int __fastcall GetValueY(int AVisibleValueIndex, int ASeriesIndex);
	bool __fastcall HasGap(int AValueIndex);
	virtual bool __fastcall IsEdgeCategoryTickMarkLabels(void);
	bool __fastcall IsGapValue(int ASeriesIndex, int AValueIndex);
	virtual void __fastcall CalculatePlotOffsets(int APlotAreaWidth, System::Types::TRect &AOffsets);
	virtual void __fastcall CalculateValues(void);
	virtual System::Types::TRect __fastcall GetValueBounds(int AVisibleValueIndex, int ASeriesIndex);
	
public:
	__property TcxGridChartLineDiagram* Diagram = {read=GetDiagram};
public:
	/* TcxGridChartHistogramViewInfo.Create */ inline __fastcall virtual TcxGridChartLineDiagramViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartHistogramViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartHistogramViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramViewInfo(void) { }
	
};


class DELPHICLASS TcxGridChartAreaDiagramLegendItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartAreaDiagramLegendItemViewInfo : public TcxGridChartLineDiagramLegendItemViewInfo
{
	typedef TcxGridChartLineDiagramLegendItemViewInfo inherited;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateLegendKeyHeight(void);
	virtual int __fastcall CalculateLegendKeyWidth(void);
	virtual System::Uitypes::TColor __fastcall GetLineColor(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
public:
	/* TcxGridChartLegendItemViewInfo.Create */ inline __fastcall virtual TcxGridChartAreaDiagramLegendItemViewInfo(TcxGridChartLegendViewInfo* AContainer, int AIndex) : TcxGridChartLineDiagramLegendItemViewInfo(AContainer, AIndex) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagramLegendItemViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartAreaDiagramLegendViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartAreaDiagramLegendViewInfo : public TcxGridChartLineDiagramLegendViewInfo
{
	typedef TcxGridChartLineDiagramLegendViewInfo inherited;
	
protected:
	virtual TcxGridChartLegendItemViewInfoClass __fastcall GetItemClass(void);
	virtual bool __fastcall GetItemsInReverseOrder(void);
public:
	/* TcxGridChartLegendViewInfo.Create */ inline __fastcall virtual TcxGridChartAreaDiagramLegendViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartLineDiagramLegendViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartLegendViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagramLegendViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartAreaDiagram;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartAreaDiagramValueViewInfo : public TcxGridChartLineDiagramValueViewInfo
{
	typedef TcxGridChartLineDiagramValueViewInfo inherited;
	
private:
	HIDESBASE TcxGridChartAreaDiagram* __fastcall GetDiagram(void);
	
protected:
	virtual void __fastcall CalculateAreaPoints(void);
	virtual bool __fastcall CustomDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Uitypes::TColor __fastcall GetAreaColor(void);
	virtual System::Types::TRect __fastcall GetHotSpotBounds(void);
	virtual System::Uitypes::TColor __fastcall GetLineColor(void);
	virtual int __fastcall GetLineHotZoneMinWidth(void);
	__classmethod virtual TcxGridChartLineDiagramValuePainterClass __fastcall GetPainterClassEx();
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual int __fastcall GetZeroValueOffset(void);
	virtual bool __fastcall HasCustomDrawBackground(void);
	__property TcxGridChartAreaDiagram* Diagram = {read=GetDiagram};
	__property int ZeroValueOffset = {read=GetZeroValueOffset, nodefault};
	
public:
	Cxgraphics::TPointArray AreaPoints;
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds, int ALineStartY, int ALineFinishY);
	virtual Cxgraphics::TcxRegion* __fastcall CreateAreaRegion(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property System::Uitypes::TColor AreaColor = {read=GetAreaColor, nodefault};
public:
	/* TcxGridChartDiagramValueViewInfo.Create */ inline __fastcall virtual TcxGridChartAreaDiagramValueViewInfo(TcxGridChartDiagramViewInfo* ADiagramViewInfo, int ASeriesIndex, int AVisibleValueIndex) : TcxGridChartLineDiagramValueViewInfo(ADiagramViewInfo, ASeriesIndex, AVisibleValueIndex) { }
	/* TcxGridChartDiagramValueViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagramValueViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartAreaDiagramViewInfo;
class PASCALIMPLEMENTATION TcxGridChartAreaDiagramViewInfo : public TcxGridChartLineDiagramViewInfo
{
	typedef TcxGridChartLineDiagramViewInfo inherited;
	
protected:
	virtual bool __fastcall ExcludeEachSeriesArea(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	__classmethod virtual TcxGridChartDiagramValueViewInfoClass __fastcall GetValueViewInfoClass();
public:
	/* TcxGridChartHistogramViewInfo.Create */ inline __fastcall virtual TcxGridChartAreaDiagramViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartLineDiagramViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartHistogramViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagramViewInfo(void) { }
	
};


class DELPHICLASS TcxGridCharStackedAreaDiagramViewInfo;
class DELPHICLASS TcxGridChartStackedAreaDiagram;
class PASCALIMPLEMENTATION TcxGridCharStackedAreaDiagramViewInfo : public TcxGridChartAreaDiagramViewInfo
{
	typedef TcxGridChartAreaDiagramViewInfo inherited;
	
private:
	HIDESBASE TcxGridChartStackedAreaDiagram* __fastcall GetDiagram(void);
	
protected:
	virtual void __fastcall CalculateValues(void);
	virtual bool __fastcall ExcludeEachSeriesArea(void);
	int __fastcall GetSeriesCountAt(int AValueIndex);
	virtual System::Variant __fastcall GetValue(int ASeriesIndex, int AIndex);
	
public:
	__property TcxGridChartStackedAreaDiagram* Diagram = {read=GetDiagram};
public:
	/* TcxGridChartHistogramViewInfo.Create */ inline __fastcall virtual TcxGridCharStackedAreaDiagramViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartAreaDiagramViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartHistogramViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCharStackedAreaDiagramViewInfo(void) { }
	
};


class DELPHICLASS TcxGridChartPieDiagramLegendViewInfo;
class DELPHICLASS TcxGridChartPieDiagram;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieDiagramLegendViewInfo : public TcxGridChartLegendViewInfo
{
	typedef TcxGridChartLegendViewInfo inherited;
	
private:
	TcxGridChartPieDiagram* __fastcall GetDiagram(void);
	
protected:
	virtual int __fastcall GetItemObjectIndex(int AIndex);
	virtual TcxGridChartLegendKind __fastcall GetKind(void);
	
public:
	__property TcxGridChartPieDiagram* Diagram = {read=GetDiagram};
public:
	/* TcxGridChartLegendViewInfo.Create */ inline __fastcall virtual TcxGridChartPieDiagramLegendViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram) : TcxGridChartLegendViewInfo(AGridViewInfo, ADiagram) { }
	/* TcxGridChartLegendViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartPieDiagramLegendViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieDiagramValueViewInfo : public TcxGridChartDiagramValueViewInfo
{
	typedef TcxGridChartDiagramValueViewInfo inherited;
	
private:
	int FStartAngle;
	int FFinishAngle;
	TcxGridChartPieDiagramValueCaptionPosition __fastcall GetCaptionPosition(void);
	System::Types::TPoint __fastcall GetCenter(void);
	TcxGridChartPieDiagramViewInfo* __fastcall GetDiagramViewInfo(void);
	int __fastcall GetRadius(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateCaptionBounds(void);
	virtual System::Types::TPoint __fastcall CalculateCaptionCenter(int AAngle, int ACaptionWidth, int ACaptionHeight);
	virtual void __fastcall CalculateLeaderLinePoints(int AAngle);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall HasCaption(void);
	virtual void __fastcall MakeCaptionVisible(System::Types::TRect &ACaptionBounds, int AAngle);
	
public:
	Cxgraphics::TPointArray LeaderLinePoints;
	HIDESBASE virtual void __fastcall Calculate(const System::Types::TRect &R, int AStartAngle, int AFinishAngle);
	virtual bool __fastcall HasPoint(const System::Types::TPoint &P);
	__property TcxGridChartPieDiagramValueCaptionPosition CaptionPosition = {read=GetCaptionPosition, nodefault};
	__property System::Types::TPoint Center = {read=GetCenter};
	__property TcxGridChartPieDiagramViewInfo* DiagramViewInfo = {read=GetDiagramViewInfo};
	__property int Radius = {read=GetRadius, nodefault};
	__property int StartAngle = {read=FStartAngle, nodefault};
	__property int FinishAngle = {read=FFinishAngle, nodefault};
public:
	/* TcxGridChartDiagramValueViewInfo.Create */ inline __fastcall virtual TcxGridChartPieDiagramValueViewInfo(TcxGridChartDiagramViewInfo* ADiagramViewInfo, int ASeriesIndex, int AVisibleValueIndex) : TcxGridChartDiagramValueViewInfo(ADiagramViewInfo, ASeriesIndex, AVisibleValueIndex) { }
	/* TcxGridChartDiagramValueViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartPieDiagramValueViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartPieSeriesSiteCaptionViewInfoClass;

class DELPHICLASS TcxGridChartPieSeriesSiteCaptionViewInfo;
class DELPHICLASS TcxGridChartPieSeriesSiteViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieSeriesSiteCaptionViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridChartPieSeriesSiteViewInfo* FSiteViewInfo;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall HasCustomDraw(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	
public:
	__fastcall virtual TcxGridChartPieSeriesSiteCaptionViewInfo(TcxGridChartPieSeriesSiteViewInfo* ASiteViewInfo);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxGridChartPieSeriesSiteViewInfo* SiteViewInfo = {read=FSiteViewInfo};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartPieSeriesSiteCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartPieSeriesSiteViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieSeriesSiteViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	typedef System::DynamicArray<int> _TcxGridChartPieSeriesSiteViewInfo__1;
	
	
private:
	System::Types::TRect FCaptionBounds;
	TcxGridChartPieSeriesSiteCaptionViewInfo* FCaptionViewInfo;
	TcxGridChartPieDiagramViewInfo* FDiagramViewInfo;
	System::Types::TRect FPieAreaBounds;
	TcxGridChartSeries* FSeries;
	TcxGridChartPieDiagram* __fastcall GetDiagram(void);
	
protected:
	_TcxGridChartPieSeriesSiteViewInfo__1 Angles;
	virtual void __fastcall CalculateAngles(void);
	virtual void __fastcall CalculateCaptionAndPieAreaBounds(System::Types::TRect &ACaptionBounds, System::Types::TRect &APieAreaBounds);
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual TcxGridChartPieSeriesSiteCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual System::Types::TRect __fastcall GetDesignSelectionBounds(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	TcxGridChartPieDiagramValueViewInfo* __fastcall GetValueViewInfo(int AVisibleValueIndex);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall HasCustomDraw(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	__property System::Types::TRect CaptionBounds = {read=FCaptionBounds};
	__property TcxGridChartPieDiagram* Diagram = {read=GetDiagram};
	
public:
	__fastcall virtual TcxGridChartPieSeriesSiteViewInfo(TcxGridChartPieDiagramViewInfo* ADiagramViewInfo, TcxGridChartSeries* ASeries);
	__fastcall virtual ~TcxGridChartPieSeriesSiteViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual bool __fastcall IsPieEmpty(void);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas = (Cxgraphics::TcxCanvas*)(0x0));
	__property TcxGridChartPieSeriesSiteCaptionViewInfo* CaptionViewInfo = {read=FCaptionViewInfo};
	__property TcxGridChartPieDiagramViewInfo* DiagramViewInfo = {read=FDiagramViewInfo};
	__property System::Types::TRect PieAreaBounds = {read=FPieAreaBounds};
	__property TcxGridChartSeries* Series = {read=FSeries};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ALeftBound, ATopBound, AWidth, AHeight); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieDiagramViewInfo : public TcxGridChartDiagramViewInfo
{
	typedef TcxGridChartDiagramViewInfo inherited;
	
private:
	int FPieAreaValueCaptionCompensation;
	System::Classes::TList* FSeriesSiteViewInfos;
	TcxGridChartPieDiagramValueCaptionPosition __fastcall GetCaptionPosition(void);
	TcxGridChartPieDiagram* __fastcall GetDiagram(void);
	TcxGridChartPieSeriesSiteViewInfo* __fastcall GetSeriesSiteViewInfo(int Index);
	int __fastcall GetSeriesSiteViewInfoCount(void);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridChartPieSeriesSiteViewInfoClass __fastcall GetSeriesSiteViewInfoClass(void);
	__classmethod virtual TcxGridChartDiagramValueViewInfoClass __fastcall GetValueViewInfoClass();
	virtual int __fastcall GetValueViewInfoIndex(int ASeriesIndex, int AVisibleIndex);
	virtual int __fastcall CalculatePieAreaValueCaptionCompensation(void);
	virtual System::Types::TRect __fastcall CalculateSeriesSiteViewInfoBounds(int AIndex);
	int __fastcall CalculateValueCaptionMaxWidth(void);
	int __fastcall CalculateValueCaptionMaxHeight(void);
	__property TcxGridChartPieDiagramValueCaptionPosition CaptionPosition = {read=GetCaptionPosition, nodefault};
	__property int PieAreaValueCaptionCompensation = {read=FPieAreaValueCaptionCompensation, nodefault};
	
public:
	__fastcall virtual TcxGridChartPieDiagramViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxGridChartDiagram* ADiagram);
	__fastcall virtual ~TcxGridChartPieDiagramViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property TcxGridChartPieDiagram* Diagram = {read=GetDiagram};
	__property int SeriesSiteViewInfoCount = {read=GetSeriesSiteViewInfoCount, nodefault};
	__property TcxGridChartPieSeriesSiteViewInfo* SeriesSiteViewInfos[int Index] = {read=GetSeriesSiteViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ALeftBound, ATopBound, AWidth, AHeight); }
	
};

#pragma pack(pop)

typedef TcxGridChartPartPosition TcxGridChartToolBoxItemAlignment;

typedef System::TMetaClass* TcxGridChartToolBoxItemViewInfoClass;

class DELPHICLASS TcxGridChartToolBoxItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxItemViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridChartPartPosition FAlignment;
	TcxGridChartToolBoxViewInfo* FContainer;
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxGridChartToolBoxItemViewInfo(TcxGridChartToolBoxViewInfo* AContainer, TcxGridChartPartPosition AAlignment);
	__property TcxGridChartPartPosition Alignment = {read=FAlignment, write=FAlignment, nodefault};
	__property TcxGridChartToolBoxViewInfo* Container = {read=FContainer};
	__property TcxGridChartView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxItemViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartToolBoxItemSeparatorViewInfoClass;

class DELPHICLASS TcxGridChartToolBoxItemSeparatorViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxItemSeparatorViewInfo : public TcxGridChartToolBoxItemViewInfo
{
	typedef TcxGridChartToolBoxItemViewInfo inherited;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasBackground(void);
public:
	/* TcxGridChartToolBoxItemViewInfo.Create */ inline __fastcall virtual TcxGridChartToolBoxItemSeparatorViewInfo(TcxGridChartToolBoxViewInfo* AContainer, TcxGridChartPartPosition AAlignment) : TcxGridChartToolBoxItemViewInfo(AContainer, AAlignment) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxItemSeparatorViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartToolBoxDataLevelActiveValueViewInfoClass;

class DELPHICLASS TcxGridChartToolBoxDataLevelInfoViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxDataLevelActiveValueViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	bool FCanShowDropDownWindow;
	TcxGridChartToolBoxDataLevelInfoViewInfo* FContainer;
	HIDESBASE TcxGridChartView* __fastcall GetGridView(void);
	
protected:
	TcxGridChartDataGroup* __fastcall GetDataGroup(void);
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall DropDownWindowExists(void);
	virtual Cxgridcustomview::TcxCustomGridPopup* __fastcall GetDropDownWindow(void);
	virtual System::Types::TRect __fastcall GetDropDownWindowOwnerBounds(void);
	
public:
	__fastcall virtual TcxGridChartToolBoxDataLevelActiveValueViewInfo(TcxGridChartToolBoxDataLevelInfoViewInfo* AContainer);
	__property bool CanShowDropDownWindow = {read=FCanShowDropDownWindow, nodefault};
	__property TcxGridChartToolBoxDataLevelInfoViewInfo* Container = {read=FContainer};
	__property TcxGridChartView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxDataLevelActiveValueViewInfo(void) { }
	
private:
	void *__IcxGridChartDataLevelActiveValuePopupOwner;	/* IcxGridChartDataLevelActiveValuePopupOwner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {94AE5C9F-9A81-401D-8B76-E3278CDD0CEB}
	operator _di_IcxGridChartDataLevelActiveValuePopupOwner()
	{
		_di_IcxGridChartDataLevelActiveValuePopupOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxGridChartDataLevelActiveValuePopupOwner*(void) { return (IcxGridChartDataLevelActiveValuePopupOwner*)&__IcxGridChartDataLevelActiveValuePopupOwner; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartToolBoxDataLevelInfoViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxDataLevelInfoViewInfo : public TcxGridChartToolBoxItemViewInfo
{
	typedef TcxGridChartToolBoxItemViewInfo inherited;
	
private:
	TcxGridChartToolBoxDataLevelActiveValueViewInfo* FActiveValueViewInfo;
	int FDataLevel;
	bool __fastcall GetActive(void);
	TcxGridChartDataGroup* __fastcall GetDataLevelObject(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateActiveValueViewInfoBounds(void);
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TcxGridChartToolBoxDataLevelActiveValueViewInfoClass __fastcall GetActiveValueViewInfoClass(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual System::Classes::TPersistent* __fastcall GetDesignObject(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasActiveValue(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	
public:
	__fastcall virtual TcxGridChartToolBoxDataLevelInfoViewInfo(TcxGridChartToolBoxViewInfo* AContainer, TcxGridChartPartPosition AAlignment, int ADataLevel);
	__fastcall virtual ~TcxGridChartToolBoxDataLevelInfoViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas = (Cxgraphics::TcxCanvas*)(0x0));
	__property bool Active = {read=GetActive, nodefault};
	__property TcxGridChartToolBoxDataLevelActiveValueViewInfo* ActiveValueViewInfo = {read=FActiveValueViewInfo};
	__property int DataLevel = {read=FDataLevel, nodefault};
	__property TcxGridChartDataGroup* DataLevelObject = {read=GetDataLevelObject};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartToolBoxCustomizeButtonViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxCustomizeButtonViewInfo : public TcxGridChartToolBoxItemViewInfo
{
	typedef TcxGridChartToolBoxItemViewInfo inherited;
	
private:
	bool __fastcall GetChecked(void);
	void __fastcall SetChecked(bool Value);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual void __fastcall Click(void);
	virtual Cxgridcommon::TcxGridCellState __fastcall GetActualState(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual bool __fastcall HasBackground(void);
	__property bool Checked = {read=GetChecked, write=SetChecked, nodefault};
public:
	/* TcxGridChartToolBoxItemViewInfo.Create */ inline __fastcall virtual TcxGridChartToolBoxCustomizeButtonViewInfo(TcxGridChartToolBoxViewInfo* AContainer, TcxGridChartPartPosition AAlignment) : TcxGridChartToolBoxItemViewInfo(AContainer, AAlignment) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxCustomizeButtonViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartToolBoxDiagramSelectorViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxDiagramSelectorViewInfo : public TcxGridChartToolBoxItemViewInfo
{
	typedef TcxGridChartToolBoxItemViewInfo inherited;
	
private:
	bool FCanShowDropDownWindow;
	TcxGridChartDiagramSelectorPopup* __fastcall GetDropDownWindowValue(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual System::Types::TRect __fastcall GetImageBounds(void);
	virtual int __fastcall GetImageHeight(void);
	virtual int __fastcall GetImageIndex(void);
	virtual int __fastcall GetImageWidth(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasBackground(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall CalculateCanShowDropDownWindow(void);
	virtual bool __fastcall DropDownWindowExists(void);
	virtual Cxgridcustomview::TcxCustomGridPopup* __fastcall GetDropDownWindow(void);
	virtual System::Types::TRect __fastcall GetDropDownWindowOwnerBounds(void);
	__property TcxGridChartDiagramSelectorPopup* DropDownWindow = {read=GetDropDownWindowValue};
	__property int ImageWidth = {read=GetImageWidth, nodefault};
	__property int ImageHeight = {read=GetImageHeight, nodefault};
	
public:
	__fastcall virtual TcxGridChartToolBoxDiagramSelectorViewInfo(TcxGridChartToolBoxViewInfo* AContainer, TcxGridChartPartPosition AAlignment);
	__property bool CanShowDropDownWindow = {read=FCanShowDropDownWindow, nodefault};
	__property System::Types::TRect ImageBounds = {read=GetImageBounds};
	__property int ImageIndex = {read=GetImageIndex, nodefault};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartToolBoxDiagramSelectorViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartToolBoxViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBoxViewInfo : public TcxCustomGridChartPartViewInfo
{
	typedef TcxCustomGridChartPartViewInfo inherited;
	
private:
	TcxGridChartToolBoxCustomizeButtonViewInfo* FCustomizeButton;
	System::Classes::TList* FDataLevelInfos;
	TcxGridChartToolBoxDiagramSelectorViewInfo* FDiagramSelector;
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	int __fastcall GetDataLevelInfoConnectorCount(void);
	TcxGridChartToolBoxDataLevelInfoViewInfo* __fastcall GetDataLevelInfo(int AIndex);
	int __fastcall GetDataLevelInfoCount(void);
	TcxGridChartToolBoxItemViewInfo* __fastcall GetItem(int AIndex);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual void __fastcall CalculateItems(void);
	virtual TcxGridChartPartAlignment __fastcall GetAlignment(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual System::Types::TRect __fastcall GetDataGroupInsertionAreaBounds(void);
	virtual System::Types::TRect __fastcall GetDataLevelInfoConnector(int AIndex);
	virtual System::Uitypes::TColor __fastcall GetDataLevelInfoConnectorColor(void);
	TcxGridChartToolBoxItemViewInfo* __fastcall GetFirstSeparator(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual System::Types::TRect __fastcall GetItemsAreaBounds(void);
	virtual TcxGridChartPartOrientation __fastcall GetOrientation(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridChartPartPosition __fastcall GetPosition(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	TcxGridChartToolBoxItemViewInfo* __fastcall AddItem(TcxGridChartToolBoxItemViewInfo* AItem);
	void __fastcall AddSeparator(TcxGridChartPartPosition AAlignment);
	virtual void __fastcall CreateItems(void);
	virtual TcxGridChartToolBoxCustomizeButtonViewInfoClass __fastcall GetCustomizeButtonClass(void);
	virtual TcxGridChartToolBoxDataLevelInfoViewInfoClass __fastcall GetDataLevelInfoClass(void);
	virtual TcxGridChartToolBoxDiagramSelectorViewInfoClass __fastcall GetDiagramSelectorClass(void);
	virtual TcxGridChartToolBoxItemSeparatorViewInfoClass __fastcall GetItemSeparatorClass(void);
	virtual bool __fastcall IsCustomizeButtonVisible(void);
	virtual bool __fastcall IsDataLevelsInfoVisible(void);
	virtual bool __fastcall IsDiagramSelectorVisible(void);
	bool __fastcall IsSeparator(TcxGridChartToolBoxItemViewInfo* AItem);
	__property System::Types::TRect ItemsAreaBounds = {read=GetItemsAreaBounds};
	
public:
	__fastcall virtual TcxGridChartToolBoxViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxGridChartToolBoxViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual System::Types::TRect __fastcall GetDataGroupInsertionBounds(int AIndex);
	virtual int __fastcall GetDataGroupInsertionIndex(const System::Types::TPoint &P);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	void __fastcall InvalidateCustomizeButton(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridChartToolBoxCustomizeButtonViewInfo* CustomizeButton = {read=FCustomizeButton};
	__property System::Uitypes::TColor DataLevelInfoConnectorColor = {read=GetDataLevelInfoConnectorColor, nodefault};
	__property int DataLevelInfoConnectorCount = {read=GetDataLevelInfoConnectorCount, nodefault};
	__property System::Types::TRect DataLevelInfoConnectors[int AIndex] = {read=GetDataLevelInfoConnector};
	__property int DataLevelInfoCount = {read=GetDataLevelInfoCount, nodefault};
	__property TcxGridChartToolBoxDataLevelInfoViewInfo* DataLevelInfos[int AIndex] = {read=GetDataLevelInfo};
	__property TcxGridChartToolBoxDiagramSelectorViewInfo* DiagramSelector = {read=FDiagramSelector};
	__property TcxGridChartToolBoxItemViewInfo* Items[int AIndex] = {read=GetItem};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartTitleViewInfoClass;

class DELPHICLASS TcxGridChartTitleViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartTitleViewInfo : public TcxCustomGridChartTitleViewInfo
{
	typedef TcxCustomGridChartTitleViewInfo inherited;
	
protected:
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
public:
	/* TcxCustomGridChartTitleViewInfo.Create */ inline __fastcall virtual TcxGridChartTitleViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo, TcxCustomGridChartTitle* ATitle) : TcxCustomGridChartTitleViewInfo(AGridViewInfo, ATitle) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartTitleViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartViewInfo : public Cxgridcustomview::TcxCustomGridViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewInfo inherited;
	
private:
	TcxGridChartDiagramViewInfo* FDiagramViewInfo;
	bool FIsImage;
	TcxGridChartLegendViewInfo* FLegendViewInfo;
	TcxGridChartTitleViewInfo* FTitleViewInfo;
	TcxGridChartToolBoxViewInfo* FToolBoxViewInfo;
	TcxGridChartView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(bool AIsRecreating);
	virtual TcxGridChartTitleViewInfoClass __fastcall GetTitleViewInfoClass(void);
	virtual TcxGridChartToolBoxViewInfoClass __fastcall GetToolBoxViewInfoClass(void);
	virtual void __fastcall Calculate(void);
	virtual System::Types::TRect __fastcall CalculateClientBounds(void);
	virtual void __fastcall CalculateHeight(const System::Types::TPoint &AMaxSize, int &AHeight, bool &AFullyVisible);
	virtual void __fastcall CalculatePartBounds(TcxCustomGridChartPartViewInfo* APart, System::Types::TRect &ABounds, System::Types::TRect &APartBounds);
	virtual void __fastcall CalculatePartsBounds(/* out */ System::Types::TRect &ADiagramBounds, /* out */ System::Types::TRect &ALegendBounds, /* out */ System::Types::TRect &ATitleBounds, /* out */ System::Types::TRect &AToolBoxBounds);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall DoGetHitTest(const System::Types::TPoint &P);
	__property bool IsImage = {read=FIsImage, write=FIsImage, nodefault};
	
public:
	__property TcxGridChartDiagramViewInfo* DiagramViewInfo = {read=FDiagramViewInfo};
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property TcxGridChartLegendViewInfo* LegendViewInfo = {read=FLegendViewInfo};
	__property TcxGridChartTitleViewInfo* TitleViewInfo = {read=FTitleViewInfo};
	__property TcxGridChartToolBoxViewInfo* ToolBoxViewInfo = {read=FToolBoxViewInfo};
public:
	/* TcxCustomGridViewInfo.Create */ inline __fastcall virtual TcxGridChartViewInfo(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridViewInfo(AGridView) { }
	/* TcxCustomGridViewInfo.Destroy */ inline __fastcall virtual ~TcxGridChartViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridChartTitle : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	TcxGridChartPartAlignment FAlignment;
	TcxGridChartPartPosition FPosition;
	System::UnicodeString FText;
	void __fastcall SetAlignment(TcxGridChartPartAlignment Value);
	void __fastcall SetPosition(TcxGridChartPartPosition Value);
	void __fastcall SetText(System::UnicodeString Value);
	
protected:
	virtual void __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual TcxGridChartPartAlignment __fastcall GetDefaultAlignment(void);
	virtual TcxGridChartPartOrientation __fastcall GetDefaultOrientation(void);
	virtual TcxGridChartPartPosition __fastcall GetDefaultPosition(void) = 0 ;
	virtual System::UnicodeString __fastcall GetDefaultText(void);
	__property TcxGridChartPartPosition Position = {read=FPosition, write=SetPosition, default=0};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TcxGridChartPartAlignment __fastcall GetAlignment(void);
	TcxGridChartPartOrientation __fastcall GetOrientation(void);
	TcxGridChartPartPosition __fastcall GetPosition(void);
	System::UnicodeString __fastcall GetText(void);
	
__published:
	__property TcxGridChartPartAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property System::UnicodeString Text = {read=FText, write=SetText};
public:
	/* TcxCustomGridOptions.Create */ inline __fastcall virtual TcxCustomGridChartTitle(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridOptions(AGridView) { }
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridChartTitle(void) { }
	
};

#pragma pack(pop)

enum TcxGridChartLegendBorder : unsigned char { lbDefault, lbNone, lbSingle };

typedef System::TMetaClass* TcxGridChartLegendClass;

class DELPHICLASS TcxGridChartLegend;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLegend : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	TcxGridChartPartAlignment FAlignment;
	TcxGridChartLegendBorder FBorder;
	TcxGridChartLegendBorder FKeyBorder;
	TcxGridChartPartOrientation FOrientation;
	TcxGridChartLegend* FParent;
	TcxGridChartPartPosition FPosition;
	void __fastcall SetAlignment(TcxGridChartPartAlignment Value);
	void __fastcall SetBorder(TcxGridChartLegendBorder Value);
	void __fastcall SetKeyBorder(TcxGridChartLegendBorder Value);
	void __fastcall SetOrientation(TcxGridChartPartOrientation Value);
	void __fastcall SetPosition(TcxGridChartPartPosition Value);
	
protected:
	virtual void __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual TcxGridChartPartAlignment __fastcall GetDefaultAlignment(void);
	virtual TcxGridChartLegendBorder __fastcall GetDefaultBorder(void);
	virtual TcxGridChartLegendBorder __fastcall GetDefaultKeyBorder(void);
	virtual TcxGridChartPartOrientation __fastcall GetDefaultOrientation(TcxGridChartPartPosition APosition);
	virtual TcxGridChartPartPosition __fastcall GetDefaultPosition(void);
	__property TcxGridChartLegend* Parent = {read=FParent, write=FParent};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TcxGridChartPartAlignment __fastcall GetAlignment(void);
	TcxGridChartLegendBorder __fastcall GetBorder(void);
	TcxGridChartLegendBorder __fastcall GetKeyBorder(void);
	TcxGridChartPartOrientation __fastcall GetOrientation(TcxGridChartPartPosition APosition = (TcxGridChartPartPosition)(0x0));
	TcxGridChartPartPosition __fastcall GetPosition(void);
	
__published:
	__property TcxGridChartPartAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property TcxGridChartLegendBorder Border = {read=FBorder, write=SetBorder, default=0};
	__property TcxGridChartLegendBorder KeyBorder = {read=FKeyBorder, write=SetKeyBorder, default=0};
	__property TcxGridChartPartOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	__property TcxGridChartPartPosition Position = {read=FPosition, write=SetPosition, default=0};
public:
	/* TcxCustomGridOptions.Create */ inline __fastcall virtual TcxGridChartLegend(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridOptions(AGridView) { }
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridChartLegend(void) { }
	
};

#pragma pack(pop)

enum TcxGridDiagramChange : unsigned char { dcProperty, dcLayout, dcSize };

class DELPHICLASS TcxCustomGridChartDiagramOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridChartDiagramOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxGridChartDiagram* FDiagram;
	TcxGridChartView* __fastcall GetGridView(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual void __fastcall Changed(TcxGridDiagramChange AChange = (TcxGridDiagramChange)(0x1));
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
public:
	__fastcall virtual TcxCustomGridChartDiagramOptions(TcxGridChartDiagram* ADiagram);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridChartDiagram* Diagram = {read=FDiagram};
	__property TcxGridChartView* GridView = {read=GetGridView};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridChartDiagramOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartDiagramStylesClass;

class DELPHICLASS TcxGridChartDiagramStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartDiagramStyles : public Cxgridcustomview::TcxCustomGridStyles
{
	typedef Cxgridcustomview::TcxCustomGridStyles inherited;
	
private:
	TcxGridChartDiagram* __fastcall GetDiagram(void);
	TcxGridChartView* __fastcall GetGridViewValue(void);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetGridView(void);
	virtual bool __fastcall GetVaryColorsByCategory(void) = 0 ;
	
public:
	__fastcall virtual TcxGridChartDiagramStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall GetBackgroundParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetValueParams(int AVisibleSeriesIndex, int AValueIndex, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridChartDiagram* Diagram = {read=GetDiagram};
	__property TcxGridChartView* GridView = {read=GetGridViewValue};
	
__published:
	__property Cxstyles::TcxStyle* Legend = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* ValueCaptions = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* Values = {read=GetValue, write=SetValue, index=2};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridChartDiagramStyles(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridChartDiagramLegendCustomDrawEvent)(TcxGridChartDiagram* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartLegendViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridChartDiagramLegendItemCustomDrawEvent)(TcxGridChartDiagram* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartLegendItemViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridChartDiagramValueCustomDrawEvent)(TcxGridChartDiagram* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartDiagramValueViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridChartDiagramValueCaptionCustomDrawEvent)(TcxGridChartDiagram* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartDiagramValueCaptionViewInfo* AViewInfo, bool &ADone);

typedef System::TMetaClass* TcxGridChartDiagramClass;

class PASCALIMPLEMENTATION TcxGridChartDiagram : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FEnabled;
	TcxGridChartView* FGridView;
	TcxGridChartLegend* FLegend;
	TcxGridChartDiagramStyles* FStyles;
	TcxGridChartDiagramLegendCustomDrawEvent FOnCustomDrawLegend;
	TcxGridChartDiagramLegendItemCustomDrawEvent FOnCustomDrawLegendItem;
	TcxGridChartDiagramValueCustomDrawEvent FOnCustomDrawValue;
	TcxGridChartDiagramValueCaptionCustomDrawEvent FOnCustomDrawValueCaption;
	bool __fastcall GetActive(void);
	System::UnicodeString __fastcall GetID(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetLegend(TcxGridChartLegend* Value);
	void __fastcall SetStyles(TcxGridChartDiagramStyles* Value);
	void __fastcall SetOnCustomDrawLegend(TcxGridChartDiagramLegendCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawLegendItem(TcxGridChartDiagramLegendItemCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawValue(TcxGridChartDiagramValueCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawValueCaption(TcxGridChartDiagramValueCaptionCustomDrawEvent Value);
	
protected:
	System::Classes::TNotifyEvent FSubClassEvents;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall CreateSubObjects(TcxGridChartView* AGridView);
	virtual void __fastcall DestroySubObjects(void);
	void __fastcall SetGridView(TcxGridChartView* Value);
	virtual TcxGridChartDiagramStylesClass __fastcall GetStylesClass(void);
	virtual TcxGridChartLegendViewInfoClass __fastcall GetLegendViewInfoClass(void) = 0 ;
	virtual TcxGridChartDiagramViewInfoClass __fastcall GetViewInfoClass(void) = 0 ;
	virtual void __fastcall Changed(TcxGridDiagramChange AChange = (TcxGridDiagramChange)(0x1));
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	virtual bool __fastcall HorizontalPaging(void);
	virtual bool __fastcall PagingInOppositeDirection(void);
	virtual bool __fastcall SupportsPaging(void);
	virtual bool __fastcall SupportsValueHotTrack(void);
	virtual void __fastcall DoCustomDrawLegend(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartLegendViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawLegendItem(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartLegendItemViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawValue(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartDiagramValueViewInfo* AViewInfo, bool &ADone);
	virtual bool __fastcall HasCustomDrawLegend(void);
	virtual bool __fastcall HasCustomDrawLegendItem(void);
	virtual bool __fastcall HasCustomDrawValue(void);
	virtual bool __fastcall HasCustomDrawValueCaption(void);
	__property int ImageIndex = {read=GetImageIndex, nodefault};
	__property TcxGridChartDiagramStyles* Styles = {read=FStyles, write=SetStyles};
	
public:
	__fastcall virtual TcxGridChartDiagram(TcxGridChartView* AGridView);
	__fastcall virtual ~TcxGridChartDiagram(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC System::UnicodeString __fastcall GetNamePath(void);
	virtual System::UnicodeString __fastcall GetStackedValueCaption(TcxGridChartSeries* ASeries, int AValueIndex, bool APercentage);
	virtual System::UnicodeString __fastcall GetValueCaption(TcxGridChartSeries* ASeries, int AValueIndex);
	virtual bool __fastcall IsAvailable(void);
	__property System::UnicodeString DisplayText = {read=GetDisplayText};
	__property TcxGridChartView* GridView = {read=FGridView};
	__property System::UnicodeString ID = {read=GetID};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property TcxGridChartLegend* Legend = {read=FLegend, write=SetLegend};
	__property TcxGridChartDiagramLegendCustomDrawEvent OnCustomDrawLegend = {read=FOnCustomDrawLegend, write=SetOnCustomDrawLegend};
	__property TcxGridChartDiagramLegendItemCustomDrawEvent OnCustomDrawLegendItem = {read=FOnCustomDrawLegendItem, write=SetOnCustomDrawLegendItem};
	__property TcxGridChartDiagramValueCustomDrawEvent OnCustomDrawValue = {read=FOnCustomDrawValue, write=SetOnCustomDrawValue};
	__property TcxGridChartDiagramValueCaptionCustomDrawEvent OnCustomDrawValueCaption = {read=FOnCustomDrawValueCaption, write=SetOnCustomDrawValueCaption};
};


typedef System::TMetaClass* TcxGridChartHistogramAxisTitleClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramAxisTitle : public TcxCustomGridChartTitle
{
	typedef TcxCustomGridChartTitle inherited;
	
private:
	TcxGridChartHistogramAxis* FAxis;
	
protected:
	virtual TcxGridChartPartPosition __fastcall GetDefaultPosition(void);
	virtual System::UnicodeString __fastcall GetDefaultText(void);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetGridViewValue(void);
	
public:
	__fastcall virtual TcxGridChartHistogramAxisTitle(TcxGridChartHistogramAxis* AAxis);
	__property TcxGridChartHistogramAxis* Axis = {read=FAxis};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramAxisTitle(void) { }
	
};

#pragma pack(pop)

enum TcxGridChartHistogramTickMarkKind : unsigned char { tmkNone, tmkCross, tmkInside, tmkOutside };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramAxis : public TcxCustomGridChartDiagramOptions
{
	typedef TcxCustomGridChartDiagramOptions inherited;
	
private:
	bool FGridLines;
	TcxGridChartHistogramTickMarkKind FTickMarkKind;
	bool FTickMarkLabels;
	TcxGridChartHistogramAxisTitle* FTitle;
	bool FVisible;
	TcxGridChartHistogram* __fastcall GetDiagram(void);
	void __fastcall SetGridLines(bool Value);
	void __fastcall SetTickMarkKind(TcxGridChartHistogramTickMarkKind Value);
	void __fastcall SetTickMarkLabels(bool Value);
	void __fastcall SetTitle(TcxGridChartHistogramAxisTitle* Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	virtual TcxGridChartHistogramAxisTitleClass __fastcall GetTitleClass(void);
	virtual System::UnicodeString __fastcall GetTitleDefaultText(void);
	
public:
	__fastcall virtual TcxGridChartHistogramAxis(TcxGridChartDiagram* ADiagram);
	__fastcall virtual ~TcxGridChartHistogramAxis(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual TcxGridChartAxisPosition __fastcall GetPosition(void) = 0 ;
	__property TcxGridChartHistogram* Diagram = {read=GetDiagram};
	
__published:
	__property bool GridLines = {read=FGridLines, write=SetGridLines, default=1};
	__property TcxGridChartHistogramTickMarkKind TickMarkKind = {read=FTickMarkKind, write=SetTickMarkKind, default=3};
	__property bool TickMarkLabels = {read=FTickMarkLabels, write=SetTickMarkLabels, default=1};
	__property TcxGridChartHistogramAxisTitle* Title = {read=FTitle, write=SetTitle};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartHistogramAxisCategoryClass;

class DELPHICLASS TcxGridChartHistogramAxisCategory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramAxisCategory : public TcxGridChartHistogramAxis
{
	typedef TcxGridChartHistogramAxis inherited;
	
private:
	bool FCategoriesInReverseOrder;
	bool FValueAxisAtMaxCategory;
	bool FValueAxisBetweenCategories;
	void __fastcall SetCategoriesInReverseOrder(bool Value);
	void __fastcall SetValueAxisAtMaxCategory(bool Value);
	void __fastcall SetValueAxisBetweenCategories(bool Value);
	
protected:
	virtual bool __fastcall GetDefaultValueAxisBetweenCategories(void);
	virtual System::UnicodeString __fastcall GetTitleDefaultText(void);
	
public:
	__fastcall virtual TcxGridChartHistogramAxisCategory(TcxGridChartDiagram* ADiagram);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual TcxGridChartAxisPosition __fastcall GetPosition(void);
	
__published:
	__property bool CategoriesInReverseOrder = {read=FCategoriesInReverseOrder, write=SetCategoriesInReverseOrder, default=0};
	__property bool ValueAxisAtMaxCategory = {read=FValueAxisAtMaxCategory, write=SetValueAxisAtMaxCategory, default=0};
	__property bool ValueAxisBetweenCategories = {read=FValueAxisBetweenCategories, write=SetValueAxisBetweenCategories, default=1};
public:
	/* TcxGridChartHistogramAxis.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramAxisCategory(void) { }
	
};

#pragma pack(pop)

enum TcxGridChartHistogramMinMaxValues : unsigned char { mmvZeroBasedAuto, mmvAuto, mmvCustom };

typedef System::TMetaClass* TcxGridChartHistogramAxisValueClass;

class PASCALIMPLEMENTATION TcxGridChartHistogramAxisValue : public TcxGridChartHistogramAxis
{
	typedef TcxGridChartHistogramAxis inherited;
	
private:
	System::Extended FMaxValue;
	TcxGridChartHistogramMinMaxValues FMinMaxValues;
	System::Extended FMinValue;
	System::UnicodeString FTickMarkLabelFormat;
	void __fastcall SetMaxValue(const System::Extended Value);
	void __fastcall SetMinMaxValues(TcxGridChartHistogramMinMaxValues Value);
	void __fastcall SetMinValue(const System::Extended Value);
	void __fastcall SetTickMarkLabelFormat(const System::UnicodeString Value);
	
protected:
	virtual System::UnicodeString __fastcall GetTitleDefaultText(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual TcxGridChartAxisPosition __fastcall GetPosition(void);
	virtual System::UnicodeString __fastcall GetTickMarkLabel(const System::Variant &ATickMarkValue);
	virtual System::UnicodeString __fastcall GetTickMarkLabelFormat(bool AConsiderSeriesFormat);
	
__published:
	__property TcxGridChartHistogramMinMaxValues MinMaxValues = {read=FMinMaxValues, write=SetMinMaxValues, default=0};
	__property System::Extended MinValue = {read=FMinValue, write=SetMinValue};
	__property System::Extended MaxValue = {read=FMaxValue, write=SetMaxValue};
	__property System::UnicodeString TickMarkLabelFormat = {read=FTickMarkLabelFormat, write=SetTickMarkLabelFormat};
public:
	/* TcxGridChartHistogramAxis.Create */ inline __fastcall virtual TcxGridChartHistogramAxisValue(TcxGridChartDiagram* ADiagram) : TcxGridChartHistogramAxis(ADiagram) { }
	/* TcxGridChartHistogramAxis.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramAxisValue(void) { }
	
};


class DELPHICLASS TcxGridChartHistogramStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramStyles : public TcxGridChartDiagramStyles
{
	typedef TcxGridChartDiagramStyles inherited;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVaryColorsByCategory(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Cxstyles::TcxStyle* Axis = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* AxisTitle = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* CategoryAxis = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* CategoryAxisTitle = {read=GetValue, write=SetValue, index=7};
	__property Cxstyles::TcxStyle* CategoryGridLines = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* GridLines = {read=GetValue, write=SetValue, index=9};
	__property Cxstyles::TcxStyle* Plot = {read=GetValue, write=SetValue, index=12};
	__property Cxstyles::TcxStyle* ValueAxis = {read=GetValue, write=SetValue, index=5};
	__property Cxstyles::TcxStyle* ValueAxisTitle = {read=GetValue, write=SetValue, index=8};
	__property Cxstyles::TcxStyle* ValueGridLines = {read=GetValue, write=SetValue, index=11};
public:
	/* TcxGridChartDiagramStyles.Create */ inline __fastcall virtual TcxGridChartHistogramStyles(System::Classes::TPersistent* AOwner) : TcxGridChartDiagramStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramStyles(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartHistogramValuesClass;

class DELPHICLASS TcxGridChartHistogramValues;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartHistogramValues : public TcxCustomGridChartDiagramOptions
{
	typedef TcxCustomGridChartDiagramOptions inherited;
	
private:
	TcxGridChartValuesStacking FStacking;
	bool FVaryColorsByCategory;
	void __fastcall SetStacking(TcxGridChartValuesStacking Value);
	void __fastcall SetVaryColorsByCategory(bool Value);
	
protected:
	__property TcxGridChartValuesStacking Stacking = {read=FStacking, write=SetStacking, default=0};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall GetVaryColorsByCategory(void);
	
__published:
	__property bool VaryColorsByCategory = {read=FVaryColorsByCategory, write=SetVaryColorsByCategory, default=0};
public:
	/* TcxCustomGridChartDiagramOptions.Create */ inline __fastcall virtual TcxGridChartHistogramValues(TcxGridChartDiagram* ADiagram) : TcxCustomGridChartDiagramOptions(ADiagram) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridChartHistogramValues(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridChartHistogramPlotCustomDrawEvent)(TcxGridChartHistogram* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartHistogramViewInfo* AViewInfo, const System::Types::TRect &ABounds, bool &ADone);

enum TcxGridChartEmptyPointsDisplayMode : unsigned char { epdmZero, epdmGap };

class PASCALIMPLEMENTATION TcxGridChartHistogram : public TcxGridChartDiagram
{
	typedef TcxGridChartDiagram inherited;
	
private:
	TcxGridChartHistogramAxisCategory* FAxisCategory;
	TcxGridChartHistogramAxisValue* FAxisValue;
	TcxGridChartEmptyPointsDisplayMode FEmptyPointsDisplayMode;
	TcxGridChartHistogramValues* FValues;
	TcxGridChartHistogramPlotCustomDrawEvent FOnCustomDrawPlot;
	TcxGridChartHistogramStyles* __fastcall GetStyles(void);
	void __fastcall SetAxisCategory(TcxGridChartHistogramAxisCategory* Value);
	void __fastcall SetAxisValue(TcxGridChartHistogramAxisValue* Value);
	void __fastcall SetEmptyPointsDisplayMode(TcxGridChartEmptyPointsDisplayMode Value);
	HIDESBASE void __fastcall SetStyles(TcxGridChartHistogramStyles* Value);
	void __fastcall SetValues(TcxGridChartHistogramValues* Value);
	void __fastcall SetOnCustomDrawPlot(TcxGridChartHistogramPlotCustomDrawEvent Value);
	
protected:
	virtual void __fastcall CreateSubObjects(TcxGridChartView* AGridView);
	virtual void __fastcall DestroySubObjects(void);
	virtual TcxGridChartHistogramAxisCategoryClass __fastcall GetAxisCategoryClass(void);
	virtual TcxGridChartHistogramAxisValueClass __fastcall GetAxisValueClass(void);
	virtual TcxGridChartDiagramStylesClass __fastcall GetStylesClass(void);
	virtual TcxGridChartHistogramValuesClass __fastcall GetValuesClass(void);
	virtual TcxGridChartLegendViewInfoClass __fastcall GetLegendViewInfoClass(void);
	virtual bool __fastcall PagingInOppositeDirection(void);
	virtual bool __fastcall SupportsPaging(void);
	virtual void __fastcall DoCustomDrawPlot(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartHistogramViewInfo* AViewInfo, const System::Types::TRect &ABounds, bool &ADone);
	virtual bool __fastcall HasCustomDrawPlot(void);
	__property TcxGridChartEmptyPointsDisplayMode EmptyPointsDisplayMode = {read=FEmptyPointsDisplayMode, write=SetEmptyPointsDisplayMode, default=0};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual TcxGridChartAxisPosition __fastcall GetCategoryAxisPosition(void);
	virtual TcxGridChartAxisPosition __fastcall GetValueAxisPosition(void);
	__property TcxGridChartHistogramAxisCategory* AxisCategory = {read=FAxisCategory, write=SetAxisCategory};
	__property TcxGridChartHistogramAxisValue* AxisValue = {read=FAxisValue, write=SetAxisValue};
	__property TcxGridChartHistogramStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxGridChartHistogramValues* Values = {read=FValues, write=SetValues};
	__property System::Classes::TNotifyEvent ValuesEvents = {read=FSubClassEvents, write=FSubClassEvents};
	
__published:
	__property TcxGridChartHistogramPlotCustomDrawEvent OnCustomDrawPlot = {read=FOnCustomDrawPlot, write=SetOnCustomDrawPlot};
public:
	/* TcxGridChartDiagram.Create */ inline __fastcall virtual TcxGridChartHistogram(TcxGridChartView* AGridView) : TcxGridChartDiagram(AGridView) { }
	/* TcxGridChartDiagram.Destroy */ inline __fastcall virtual ~TcxGridChartHistogram(void) { }
	
};


class DELPHICLASS TcxGridChartColumnDiagramValues;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartColumnDiagramValues : public TcxGridChartHistogramValues
{
	typedef TcxGridChartHistogramValues inherited;
	
private:
	int FBorderWidth;
	TcxGridChartColumnDiagramValueCaptionPosition FCaptionPosition;
	void __fastcall SetBorderWidth(int Value);
	void __fastcall SetCaptionPosition(TcxGridChartColumnDiagramValueCaptionPosition Value);
	
public:
	__fastcall virtual TcxGridChartColumnDiagramValues(TcxGridChartDiagram* ADiagram);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=1};
	__property TcxGridChartColumnDiagramValueCaptionPosition CaptionPosition = {read=FCaptionPosition, write=SetCaptionPosition, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridChartColumnDiagramValues(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartColumnDiagramClass;

class PASCALIMPLEMENTATION TcxGridChartColumnDiagram : public TcxGridChartHistogram
{
	typedef TcxGridChartHistogram inherited;
	
private:
	TcxGridChartColumnDiagramValues* __fastcall GetValues(void);
	HIDESBASE void __fastcall SetValues(TcxGridChartColumnDiagramValues* Value);
	
protected:
	virtual TcxGridChartLegendViewInfoClass __fastcall GetLegendViewInfoClass(void);
	virtual TcxGridChartHistogramValuesClass __fastcall GetValuesClass(void);
	virtual TcxGridChartDiagramViewInfoClass __fastcall GetViewInfoClass(void);
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	
__published:
	__property AxisCategory;
	__property AxisValue;
	__property Styles;
	__property TcxGridChartColumnDiagramValues* Values = {read=GetValues, write=SetValues};
public:
	/* TcxGridChartDiagram.Create */ inline __fastcall virtual TcxGridChartColumnDiagram(TcxGridChartView* AGridView) : TcxGridChartHistogram(AGridView) { }
	/* TcxGridChartDiagram.Destroy */ inline __fastcall virtual ~TcxGridChartColumnDiagram(void) { }
	
};


typedef System::TMetaClass* TcxGridChartBarDiagramClass;

class DELPHICLASS TcxGridChartBarDiagram;
class PASCALIMPLEMENTATION TcxGridChartBarDiagram : public TcxGridChartColumnDiagram
{
	typedef TcxGridChartColumnDiagram inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	virtual bool __fastcall HorizontalPaging(void);
	virtual bool __fastcall PagingInOppositeDirection(void);
	
public:
	virtual TcxGridChartAxisPosition __fastcall GetCategoryAxisPosition(void);
	virtual TcxGridChartAxisPosition __fastcall GetValueAxisPosition(void);
public:
	/* TcxGridChartDiagram.Create */ inline __fastcall virtual TcxGridChartBarDiagram(TcxGridChartView* AGridView) : TcxGridChartColumnDiagram(AGridView) { }
	/* TcxGridChartDiagram.Destroy */ inline __fastcall virtual ~TcxGridChartBarDiagram(void) { }
	
};


class DELPHICLASS TcxGridChartLineDiagramAxisCategory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLineDiagramAxisCategory : public TcxGridChartHistogramAxisCategory
{
	typedef TcxGridChartHistogramAxisCategory inherited;
	
protected:
	virtual bool __fastcall GetDefaultValueAxisBetweenCategories(void);
	
__published:
	__property ValueAxisBetweenCategories = {default=0};
public:
	/* TcxGridChartHistogramAxisCategory.Create */ inline __fastcall virtual TcxGridChartLineDiagramAxisCategory(TcxGridChartDiagram* ADiagram) : TcxGridChartHistogramAxisCategory(ADiagram) { }
	
public:
	/* TcxGridChartHistogramAxis.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramAxisCategory(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartLineDiagramStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartLineDiagramStyles : public TcxGridChartHistogramStyles
{
	typedef TcxGridChartHistogramStyles inherited;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall ValueMarkerHasBorderByDefault(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetValueMarkerParams(int AVisibleSeriesIndex, int AValueIndex, /* out */ Cxgraphics::TcxViewParams &AParams);
	
__published:
	__property Cxstyles::TcxStyle* ValueMarkers = {read=GetValue, write=SetValue, index=13};
public:
	/* TcxGridChartDiagramStyles.Create */ inline __fastcall virtual TcxGridChartLineDiagramStyles(System::Classes::TPersistent* AOwner) : TcxGridChartHistogramStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramStyles(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridChartLineDiagramGetLineStyleEvent)(TcxGridChartLineDiagram* Sender, TcxGridChartSeries* ASeries, TcxGridChartLineStyle &AStyle);

typedef void __fastcall (__closure *TcxGridChartLineDiagramGetMarkerStyleEvent)(TcxGridChartLineDiagram* Sender, TcxGridChartSeries* ASeries, TcxGridChartMarkerStyle &AStyle);

class DELPHICLASS TcxGridChartLineDiagramValues;
class PASCALIMPLEMENTATION TcxGridChartLineDiagramValues : public TcxGridChartHistogramValues
{
	typedef TcxGridChartHistogramValues inherited;
	
private:
	TcxGridChartLineDiagramValueCaptionPosition FCaptionPosition;
	int FHotSpotSize;
	TcxGridChartLineStyle FLineStyle;
	int FLineWidth;
	int FMarkerSize;
	TcxGridChartMarkerStyle FMarkerStyle;
	TcxGridChartLineDiagramGetLineStyleEvent FOnGetLineStyle;
	TcxGridChartLineDiagramGetMarkerStyleEvent FOnGetMarkerStyle;
	TcxGridChartLineDiagram* __fastcall GetDiagram(void);
	void __fastcall SetCaptionPosition(TcxGridChartLineDiagramValueCaptionPosition Value);
	void __fastcall SetHotSpotSize(int Value);
	void __fastcall SetLineStyle(TcxGridChartLineStyle Value);
	void __fastcall SetLineWidth(int Value);
	void __fastcall SetMarkerSize(int Value);
	void __fastcall SetMarkerStyle(TcxGridChartMarkerStyle Value);
	void __fastcall SetOnGetLineStyle(TcxGridChartLineDiagramGetLineStyleEvent Value);
	void __fastcall SetOnGetMarkerStyle(TcxGridChartLineDiagramGetMarkerStyleEvent Value);
	
protected:
	virtual void __fastcall DoGetLineStyle(TcxGridChartSeries* ASeries, TcxGridChartLineStyle &AStyle);
	virtual void __fastcall DoGetMarkerStyle(TcxGridChartSeries* ASeries, TcxGridChartMarkerStyle &AStyle);
	
public:
	__fastcall virtual TcxGridChartLineDiagramValues(TcxGridChartDiagram* ADiagram);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual int __fastcall GetHotSpotSize(void);
	virtual TcxGridChartLineStyle __fastcall GetLineStyle(TcxGridChartSeries* ASeries);
	virtual TcxGridChartMarkerStyle __fastcall GetMarkerStyle(TcxGridChartSeries* ASeries);
	__property TcxGridChartLineDiagram* Diagram = {read=GetDiagram};
	
__published:
	__property TcxGridChartLineDiagramValueCaptionPosition CaptionPosition = {read=FCaptionPosition, write=SetCaptionPosition, default=0};
	__property int HotSpotSize = {read=FHotSpotSize, write=SetHotSpotSize, default=15};
	__property TcxGridChartLineStyle LineStyle = {read=FLineStyle, write=SetLineStyle, default=1};
	__property int LineWidth = {read=FLineWidth, write=SetLineWidth, default=1};
	__property int MarkerSize = {read=FMarkerSize, write=SetMarkerSize, default=7};
	__property TcxGridChartMarkerStyle MarkerStyle = {read=FMarkerStyle, write=SetMarkerStyle, default=0};
	__property Stacking = {default=0};
	__property TcxGridChartLineDiagramGetLineStyleEvent OnGetLineStyle = {read=FOnGetLineStyle, write=SetOnGetLineStyle};
	__property TcxGridChartLineDiagramGetMarkerStyleEvent OnGetMarkerStyle = {read=FOnGetMarkerStyle, write=SetOnGetMarkerStyle};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagramValues(void) { }
	
};


typedef System::TMetaClass* TcxGridChartLineDiagramClass;

class PASCALIMPLEMENTATION TcxGridChartLineDiagram : public TcxGridChartHistogram
{
	typedef TcxGridChartHistogram inherited;
	
private:
	TcxGridChartLineDiagramAxisCategory* __fastcall GetAxisCategory(void);
	HIDESBASE TcxGridChartLineDiagramStyles* __fastcall GetStyles(void);
	TcxGridChartLineDiagramValues* __fastcall GetValues(void);
	HIDESBASE void __fastcall SetAxisCategory(TcxGridChartLineDiagramAxisCategory* Value);
	HIDESBASE void __fastcall SetStyles(TcxGridChartLineDiagramStyles* Value);
	HIDESBASE void __fastcall SetValues(TcxGridChartLineDiagramValues* Value);
	
protected:
	virtual TcxGridChartHistogramAxisCategoryClass __fastcall GetAxisCategoryClass(void);
	virtual TcxGridChartLegendViewInfoClass __fastcall GetLegendViewInfoClass(void);
	virtual TcxGridChartDiagramStylesClass __fastcall GetStylesClass(void);
	virtual TcxGridChartHistogramValuesClass __fastcall GetValuesClass(void);
	virtual TcxGridChartDiagramViewInfoClass __fastcall GetViewInfoClass(void);
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	virtual bool __fastcall SupportsValueHotTrack(void);
	
__published:
	__property TcxGridChartLineDiagramAxisCategory* AxisCategory = {read=GetAxisCategory, write=SetAxisCategory};
	__property AxisValue;
	__property EmptyPointsDisplayMode = {default=0};
	__property TcxGridChartLineDiagramStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxGridChartLineDiagramValues* Values = {read=GetValues, write=SetValues};
	__property ValuesEvents;
public:
	/* TcxGridChartDiagram.Create */ inline __fastcall virtual TcxGridChartLineDiagram(TcxGridChartView* AGridView) : TcxGridChartHistogram(AGridView) { }
	/* TcxGridChartDiagram.Destroy */ inline __fastcall virtual ~TcxGridChartLineDiagram(void) { }
	
};


class DELPHICLASS TcxGridChartAreaDiagramStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartAreaDiagramStyles : public TcxGridChartLineDiagramStyles
{
	typedef TcxGridChartLineDiagramStyles inherited;
	
protected:
	virtual bool __fastcall ValueMarkerHasBorderByDefault(void);
public:
	/* TcxGridChartDiagramStyles.Create */ inline __fastcall virtual TcxGridChartAreaDiagramStyles(System::Classes::TPersistent* AOwner) : TcxGridChartLineDiagramStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagramStyles(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridChartAreaDiagramValueAreaCustomDrawEvent)(TcxGridChartAreaDiagram* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartAreaDiagramValueViewInfo* AViewInfo, bool &ADone);

typedef System::TMetaClass* TcxGridChartAreaDiagramClass;

class PASCALIMPLEMENTATION TcxGridChartAreaDiagram : public TcxGridChartLineDiagram
{
	typedef TcxGridChartLineDiagram inherited;
	
private:
	System::Byte FTransparency;
	TcxGridChartAreaDiagramValueAreaCustomDrawEvent FOnCustomDrawValueArea;
	HIDESBASE TcxGridChartAreaDiagramStyles* __fastcall GetStyles(void);
	HIDESBASE void __fastcall SetStyles(TcxGridChartAreaDiagramStyles* Value);
	void __fastcall SetTransparency(System::Byte Value);
	void __fastcall SetOnCustomDrawValueArea(TcxGridChartAreaDiagramValueAreaCustomDrawEvent Value);
	
protected:
	virtual bool __fastcall CheckGapPoints(void);
	virtual TcxGridChartLegendViewInfoClass __fastcall GetLegendViewInfoClass(void);
	virtual TcxGridChartDiagramStylesClass __fastcall GetStylesClass(void);
	virtual TcxGridChartDiagramViewInfoClass __fastcall GetViewInfoClass(void);
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	virtual void __fastcall DoCustomDrawValueArea(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartAreaDiagramValueViewInfo* AViewInfo, bool &ADone);
	virtual bool __fastcall HasCustomDrawValueArea(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Byte Transparency = {read=FTransparency, write=SetTransparency, default=0};
	__property TcxGridChartAreaDiagramStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxGridChartAreaDiagramValueAreaCustomDrawEvent OnCustomDrawValueArea = {read=FOnCustomDrawValueArea, write=SetOnCustomDrawValueArea};
public:
	/* TcxGridChartDiagram.Create */ inline __fastcall virtual TcxGridChartAreaDiagram(TcxGridChartView* AGridView) : TcxGridChartLineDiagram(AGridView) { }
	/* TcxGridChartDiagram.Destroy */ inline __fastcall virtual ~TcxGridChartAreaDiagram(void) { }
	
};


typedef System::TMetaClass* TcxGridChartStackedAreaDiagramClass;

typedef System::TMetaClass* TcxGridChartStackedColumnDiagramClass;

typedef System::TMetaClass* TcxGridChartStackedBarDiagramClass;

enum TcxGridChartStackedAreaDiagramStyle : unsigned char { sasDefault, sas100Percent };

enum TcxGridChartStackedDiagramStyle : unsigned char { sdsDefault, sds100Percent, sdsSideBySide, sdsSideBySide100Percent };

class PASCALIMPLEMENTATION TcxGridChartStackedAreaDiagram : public TcxGridChartAreaDiagram
{
	typedef TcxGridChartAreaDiagram inherited;
	
private:
	TcxGridChartStackedAreaDiagramStyle FStackedStyle;
	void __fastcall SetStackedStyle(TcxGridChartStackedAreaDiagramStyle Value);
	
public:
	virtual bool __fastcall CheckGapPoints(void);
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	virtual System::UnicodeString __fastcall GetValueCaption(TcxGridChartSeries* ASeries, int AValueIndex);
	virtual TcxGridChartDiagramViewInfoClass __fastcall GetViewInfoClass(void);
	
__published:
	__property TcxGridChartStackedAreaDiagramStyle StackedStyle = {read=FStackedStyle, write=SetStackedStyle, default=0};
public:
	/* TcxGridChartDiagram.Create */ inline __fastcall virtual TcxGridChartStackedAreaDiagram(TcxGridChartView* AGridView) : TcxGridChartAreaDiagram(AGridView) { }
	/* TcxGridChartDiagram.Destroy */ inline __fastcall virtual ~TcxGridChartStackedAreaDiagram(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridChartStackedColumnDiagram : public TcxGridChartColumnDiagram
{
	typedef TcxGridChartColumnDiagram inherited;
	
private:
	int FSideBySideIndentWidth;
	TcxGridChartStackedDiagramStyle FStackedStyle;
	void __fastcall SetSideBySideIndentWidth(int Value);
	void __fastcall SetStackedStyle(TcxGridChartStackedDiagramStyle Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	virtual TcxGridChartDiagramViewInfoClass __fastcall GetViewInfoClass(void);
	
public:
	__fastcall virtual TcxGridChartStackedColumnDiagram(TcxGridChartView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetValueCaption(TcxGridChartSeries* ASeries, int AValueIndex);
	
__published:
	__property TcxGridChartStackedDiagramStyle StackedStyle = {read=FStackedStyle, write=SetStackedStyle, default=0};
	__property int SideBySideIndentWidth = {read=FSideBySideIndentWidth, write=SetSideBySideIndentWidth, default=2};
public:
	/* TcxGridChartDiagram.Destroy */ inline __fastcall virtual ~TcxGridChartStackedColumnDiagram(void) { }
	
};


class DELPHICLASS TcxGridChartStackedBarDiagram;
class PASCALIMPLEMENTATION TcxGridChartStackedBarDiagram : public TcxGridChartStackedColumnDiagram
{
	typedef TcxGridChartStackedColumnDiagram inherited;
	
public:
	virtual TcxGridChartAxisPosition __fastcall GetCategoryAxisPosition(void);
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	virtual TcxGridChartAxisPosition __fastcall GetValueAxisPosition(void);
	virtual bool __fastcall HorizontalPaging(void);
	virtual bool __fastcall PagingInOppositeDirection(void);
public:
	/* TcxGridChartStackedColumnDiagram.Create */ inline __fastcall virtual TcxGridChartStackedBarDiagram(TcxGridChartView* AGridView) : TcxGridChartStackedColumnDiagram(AGridView) { }
	
public:
	/* TcxGridChartDiagram.Destroy */ inline __fastcall virtual ~TcxGridChartStackedBarDiagram(void) { }
	
};


class DELPHICLASS TcxGridChartPieDiagramStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieDiagramStyles : public TcxGridChartDiagramStyles
{
	typedef TcxGridChartDiagramStyles inherited;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVaryColorsByCategory(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Cxstyles::TcxStyle* SeriesSiteCaptions = {read=GetValue, write=SetValue, index=14};
	__property Cxstyles::TcxStyle* SeriesSites = {read=GetValue, write=SetValue, index=15};
public:
	/* TcxGridChartDiagramStyles.Create */ inline __fastcall virtual TcxGridChartPieDiagramStyles(System::Classes::TPersistent* AOwner) : TcxGridChartDiagramStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridChartPieDiagramStyles(void) { }
	
};

#pragma pack(pop)

enum TcxGridChartPieDiagramValueCaptionItem : unsigned char { pdvciCategory, pdvciValue, pdvciPercentage };

typedef System::Set<TcxGridChartPieDiagramValueCaptionItem, TcxGridChartPieDiagramValueCaptionItem::pdvciCategory, TcxGridChartPieDiagramValueCaptionItem::pdvciPercentage>  TcxGridChartPieDiagramValueCaptionItems;

typedef System::TMetaClass* TcxGridChartPieDiagramValuesClass;

class DELPHICLASS TcxGridChartPieDiagramValues;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartPieDiagramValues : public TcxCustomGridChartDiagramOptions
{
	typedef TcxCustomGridChartDiagramOptions inherited;
	
private:
	int FAngleOfFirstSlice;
	TcxGridChartPieDiagramValueCaptionItems FCaptionItems;
	System::UnicodeString FCaptionItemSeparator;
	TcxGridChartPieDiagramValueCaptionPosition FCaptionPosition;
	System::UnicodeString FPercentageCaptionFormat;
	void __fastcall SetAngleOfFirstSlice(int Value);
	void __fastcall SetCaptionItems(TcxGridChartPieDiagramValueCaptionItems Value);
	void __fastcall SetCaptionItemSeparator(const System::UnicodeString Value);
	void __fastcall SetCaptionPosition(TcxGridChartPieDiagramValueCaptionPosition Value);
	void __fastcall SetPercentageCaptionFormat(const System::UnicodeString Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDefaultCaptionItemSeparator(void);
	virtual System::UnicodeString __fastcall GetDefaultPercentageCaptionFormat(void);
	
public:
	__fastcall virtual TcxGridChartPieDiagramValues(TcxGridChartDiagram* ADiagram);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::UnicodeString __fastcall GetCaptionItemSeparator(void);
	virtual TcxGridChartPieDiagramValueCaptionPosition __fastcall GetCaptionPosition(void);
	System::UnicodeString __fastcall GetPercentageCaptionFormat(void);
	
__published:
	__property int AngleOfFirstSlice = {read=FAngleOfFirstSlice, write=SetAngleOfFirstSlice, default=0};
	__property TcxGridChartPieDiagramValueCaptionPosition CaptionPosition = {read=FCaptionPosition, write=SetCaptionPosition, default=0};
	__property TcxGridChartPieDiagramValueCaptionItems CaptionItems = {read=FCaptionItems, write=SetCaptionItems, default=2};
	__property System::UnicodeString CaptionItemSeparator = {read=FCaptionItemSeparator, write=SetCaptionItemSeparator};
	__property System::UnicodeString PercentageCaptionFormat = {read=FPercentageCaptionFormat, write=SetPercentageCaptionFormat};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridChartPieDiagramValues(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridChartPieDiagramSeriesSiteCaptionCustomDrawEvent)(TcxGridChartPieDiagram* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartPieSeriesSiteCaptionViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridChartPieDiagramSeriesSiteCustomDrawEvent)(TcxGridChartPieDiagram* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartPieSeriesSiteViewInfo* AViewInfo, bool &ADone);

typedef System::TMetaClass* TcxGridChartPieDiagramClass;

class PASCALIMPLEMENTATION TcxGridChartPieDiagram : public TcxGridChartDiagram
{
	typedef TcxGridChartDiagram inherited;
	
private:
	bool FSeriesCaptions;
	int FSeriesColumnCount;
	bool FSeriesSites;
	TcxGridChartPieDiagramValues* FValues;
	TcxGridChartPieDiagramSeriesSiteCustomDrawEvent FOnCustomDrawSeriesSite;
	TcxGridChartPieDiagramSeriesSiteCaptionCustomDrawEvent FOnCustomDrawSeriesSiteCaption;
	TcxGridChartPieDiagramStyles* __fastcall GetStyles(void);
	void __fastcall SetSeriesCaptions(bool Value);
	void __fastcall SetSeriesColumnCount(int Value);
	void __fastcall SetSeriesSites(bool Value);
	HIDESBASE void __fastcall SetStyles(TcxGridChartPieDiagramStyles* Value);
	void __fastcall SetValues(TcxGridChartPieDiagramValues* Value);
	void __fastcall SetOnCustomDrawSeriesSite(TcxGridChartPieDiagramSeriesSiteCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawSeriesSiteCaption(TcxGridChartPieDiagramSeriesSiteCaptionCustomDrawEvent Value);
	
protected:
	virtual void __fastcall CreateSubObjects(TcxGridChartView* AGridView);
	virtual void __fastcall DestroySubObjects(void);
	virtual TcxGridChartDiagramStylesClass __fastcall GetStylesClass(void);
	virtual TcxGridChartPieDiagramValuesClass __fastcall GetValuesClass(void);
	virtual TcxGridChartLegendViewInfoClass __fastcall GetLegendViewInfoClass(void);
	virtual TcxGridChartDiagramViewInfoClass __fastcall GetViewInfoClass(void);
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual int __fastcall GetImageIndex(void);
	virtual void __fastcall DoCustomDrawSeriesSite(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartPieSeriesSiteViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawSeriesSiteCaption(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartPieSeriesSiteCaptionViewInfo* AViewInfo, bool &ADone);
	virtual bool __fastcall HasCustomDrawSeriesSite(void);
	virtual bool __fastcall HasCustomDrawSeriesSiteCaption(void);
	
public:
	__fastcall virtual TcxGridChartPieDiagram(TcxGridChartView* AGridView);
	__fastcall virtual ~TcxGridChartPieDiagram(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual int __fastcall GetSeriesColumnCount(void);
	virtual System::UnicodeString __fastcall GetValueCaption(TcxGridChartSeries* ASeries, int AValueIndex);
	
__published:
	__property bool SeriesCaptions = {read=FSeriesCaptions, write=SetSeriesCaptions, default=1};
	__property int SeriesColumnCount = {read=FSeriesColumnCount, write=SetSeriesColumnCount, default=0};
	__property bool SeriesSites = {read=FSeriesSites, write=SetSeriesSites, default=0};
	__property TcxGridChartPieDiagramStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxGridChartPieDiagramValues* Values = {read=FValues, write=SetValues};
	__property TcxGridChartPieDiagramSeriesSiteCustomDrawEvent OnCustomDrawSeriesSite = {read=FOnCustomDrawSeriesSite, write=SetOnCustomDrawSeriesSite};
	__property TcxGridChartPieDiagramSeriesSiteCaptionCustomDrawEvent OnCustomDrawSeriesSiteCaption = {read=FOnCustomDrawSeriesSiteCaption, write=SetOnCustomDrawSeriesSiteCaption};
};


typedef System::TMetaClass* TcxGridChartItemDataBindingClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartItemDataBinding : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	System::TObject* FData;
	Cxcustomdata::TcxCustomDataField* FDataField;
	Cxedit::TcxEditRepositoryItem* FDefaultRepositoryItem;
	Cxedit::TcxCustomEditDefaultValuesProvider* FDefaultValuesProvider;
	Cxdatastorage::TcxValueTypeClass FDefaultValueTypeClass;
	TcxGridChartView* FGridView;
	int FID;
	bool FIsValue;
	Cxcustomdata::TcxDataSummaryItem* FSummaryItem;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	int __fastcall GetDataIndex(void);
	System::TObject* __fastcall GetDataItem(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetDefaultProperties(void);
	Cxedit::TcxCustomEditDefaultValuesProvider* __fastcall GetDefaultValuesProvider(void);
	int __fastcall GetGroupIndex(void);
	int __fastcall GetSortIndex(void);
	Dxcore::TdxSortOrder __fastcall GetSortOrder(void);
	int __fastcall GetSummaryIndex(void);
	Cxcustomdata::TcxSummaryKind __fastcall GetSummaryKind(void);
	System::UnicodeString __fastcall GetValueType(void);
	Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	void __fastcall SetData(System::TObject* Value);
	void __fastcall SetDataField(Cxcustomdata::TcxCustomDataField* Value);
	void __fastcall SetGroupIndex(int Value);
	void __fastcall SetSortIndex(int Value);
	void __fastcall SetSortOrder(Dxcore::TdxSortOrder Value);
	void __fastcall SetSummaryKind(Cxcustomdata::TcxSummaryKind Value);
	void __fastcall SetValueType(const System::UnicodeString Value);
	void __fastcall SetValueTypeClass(Cxdatastorage::TcxValueTypeClass Value);
	
protected:
	void __fastcall ItemRemoved(Cxedit::TcxEditRepositoryItem* Sender);
	void __fastcall PropertiesChanged(Cxedit::TcxEditRepositoryItem* Sender);
	virtual void __fastcall CreateSummaryItem(Cxcustomdata::TcxDataSummaryItem* &ASummaryItem);
	virtual System::UnicodeString __fastcall GetDefaultDisplayText(void);
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetDefaultValueTypeClass(void);
	virtual Cxcustomdata::TcxDataSummaryItem* __fastcall GetSummaryItem(void);
	virtual void __fastcall InitDefaultValuesProvider(Cxedit::TcxCustomEditDefaultValuesProvider* ADefaultValuesProvider);
	bool __fastcall IsValueTypeInteger(void);
	virtual bool __fastcall IsValueTypeStored(void);
	void __fastcall UpdateSummaryItemValue(void);
	virtual void __fastcall ValueTypeClassChanged(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall GetDefaultRepositoryItem(void);
	void __fastcall UpdateDefaultRepositoryItemValue(void);
	__property Cxcustomdata::TcxCustomDataField* DataField = {read=FDataField, write=SetDataField};
	__property Cxedit::TcxCustomEditProperties* DefaultProperties = {read=GetDefaultProperties};
	__property Cxedit::TcxEditRepositoryItem* DefaultRepositoryItem = {read=FDefaultRepositoryItem};
	__property Cxedit::TcxCustomEditDefaultValuesProvider* DefaultValuesProvider = {read=GetDefaultValuesProvider};
	__property System::TObject* DataItem = {read=GetDataItem};
	__property int GroupIndex = {read=GetGroupIndex, write=SetGroupIndex, nodefault};
	__property int ID = {read=FID, write=FID, nodefault};
	__property bool IsValue = {read=FIsValue, nodefault};
	__property int SortIndex = {read=GetSortIndex, write=SetSortIndex, nodefault};
	__property Dxcore::TdxSortOrder SortOrder = {read=GetSortOrder, write=SetSortOrder, nodefault};
	__property Cxcustomdata::TcxSummaryKind SummaryKind = {read=GetSummaryKind, write=SetSummaryKind, nodefault};
	
public:
	__fastcall virtual TcxGridChartItemDataBinding(TcxGridChartView* AGridView, bool AIsValue, Cxdatastorage::TcxValueTypeClass ADefaultValueTypeClass);
	__fastcall virtual ~TcxGridChartItemDataBinding(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetValueDisplayText(const System::Variant &AValue);
	virtual bool __fastcall IsValueTypeClassValid(Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	__property System::TObject* Data = {read=FData, write=SetData};
	__property int DataIndex = {read=GetDataIndex, nodefault};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxGridChartView* GridView = {read=FGridView};
	__property int SummaryIndex = {read=GetSummaryIndex, nodefault};
	__property Cxcustomdata::TcxDataSummaryItem* SummaryItem = {read=FSummaryItem};
	__property Cxdatastorage::TcxValueTypeClass ValueTypeClass = {read=GetValueTypeClass, write=SetValueTypeClass};
	
__published:
	__property System::UnicodeString ValueType = {read=GetValueType, write=SetValueType, stored=IsValueTypeStored};
private:
	void *__IcxEditRepositoryItemListener;	/* Cxedit::IcxEditRepositoryItemListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator Cxedit::_di_IcxEditRepositoryItemListener()
	{
		Cxedit::_di_IcxEditRepositoryItemListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditRepositoryItemListener*(void) { return (Cxedit::IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
	#endif
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridChartGetValueDisplayTextEvent)(System::TObject* Sender, const System::Variant &AValue, System::UnicodeString &ADisplayText);

typedef void __fastcall (__closure *TcxGridChartItemGetStoredPropertiesEvent)(TcxGridChartItem* Sender, System::Classes::TStrings* AProperties);

typedef void __fastcall (__closure *TcxGridChartItemGetStoredPropertyValueEvent)(TcxGridChartItem* Sender, const System::UnicodeString AName, System::Variant &AValue);

typedef void __fastcall (__closure *TcxGridChartItemSetStoredPropertyValueEvent)(TcxGridChartItem* Sender, const System::UnicodeString AName, const System::Variant &AValue);

class PASCALIMPLEMENTATION TcxGridChartItem : public Cxclasses::TcxComponent
{
	typedef Cxclasses::TcxComponent inherited;
	
public:
	System::Variant operator[](int AIndex) { return Values[AIndex]; }
	
private:
	TcxGridChartItemDataBinding* FDataBinding;
	System::UnicodeString FDisplayText;
	TcxGridChartView* FGridView;
	System::UnicodeString FLastDataBindingDefaultDisplayText;
	int FOrder;
	bool FVisible;
	bool FVisibleForCustomization;
	int FVisibleIndex;
	TcxGridChartItemGetStoredPropertiesEvent FOnGetStoredProperties;
	TcxGridChartItemGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	TcxGridChartGetValueDisplayTextEvent FOnGetValueDisplayText;
	TcxGridChartItemSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	int __fastcall GetID(void);
	int __fastcall GetIndex(void);
	Dxcore::TdxSortOrder __fastcall GetSortOrder(void);
	int __fastcall GetTag(void);
	System::UnicodeString __fastcall GetVisibleDisplayText(int AIndex);
	void __fastcall SetDataBinding(TcxGridChartItemDataBinding* Value);
	void __fastcall SetDisplayText(const System::UnicodeString Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetOnGetStoredProperties(TcxGridChartItemGetStoredPropertiesEvent Value);
	void __fastcall SetOnGetStoredPropertyValue(TcxGridChartItemGetStoredPropertyValueEvent Value);
	void __fastcall SetOnGetValueDisplayText(TcxGridChartGetValueDisplayTextEvent Value);
	void __fastcall SetOnSetStoredPropertyValue(TcxGridChartItemSetStoredPropertyValueEvent Value);
	void __fastcall SetSortOrder(Dxcore::TdxSortOrder Value);
	void __fastcall SetTag(int Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetVisibleForCustomization(bool Value);
	bool __fastcall IsTagStored(void);
	
protected:
	System::Classes::TNotifyEvent FSubObjectEvents;
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall SetRestoredIndex(int AValue) = 0 ;
	virtual void __fastcall DataChanged(void);
	TcxGridChartItemDataBinding* __fastcall GetDataBinding(void);
	void __fastcall ValueTypeClassChanged(void);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* AParent);
	virtual void __fastcall Changed(Cxgridcustomview::TcxGridViewChangeKind AChange = (Cxgridcustomview::TcxGridViewChangeKind)(0x1));
	virtual void __fastcall DisplayTextChanged(void);
	virtual void __fastcall DoGetValueDisplayText(const System::Variant &AValue, System::UnicodeString &ADisplayText);
	virtual System::UnicodeString __fastcall GetDefaultDisplayText(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetDefaultValueTypeClass(void) = 0 ;
	void __fastcall SetGridView(TcxGridChartView* Value);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	virtual System::Variant __fastcall GetValue(int AIndex) = 0 ;
	virtual int __fastcall GetValueCount(void) = 0 ;
	virtual System::Variant __fastcall GetVisibleValue(int AIndex) = 0 ;
	virtual int __fastcall GetVisibleValueCount(void) = 0 ;
	virtual void __fastcall SetValue(int AIndex, const System::Variant &Value) = 0 ;
	virtual void __fastcall SetValueCount(int Value) = 0 ;
	
public:
	__fastcall virtual TcxGridChartItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridChartItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	System::UnicodeString __fastcall GetDisplayText(void);
	System::UnicodeString __fastcall GetValueDisplayText(const System::Variant &AValue);
	__classmethod virtual bool __fastcall IsValue();
	__property TcxGridChartView* GridView = {read=FGridView};
	__property int ID = {read=GetID, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property int Order = {read=FOrder, nodefault};
	__property int ValueCount = {read=GetValueCount, write=SetValueCount, nodefault};
	__property System::Variant Values[int AIndex] = {read=GetValue, write=SetValue/*, default*/};
	__property System::UnicodeString VisibleDisplayTexts[int AIndex] = {read=GetVisibleDisplayText};
	__property int VisibleIndex = {read=FVisibleIndex, nodefault};
	__property int VisibleValueCount = {read=GetVisibleValueCount, nodefault};
	__property System::Variant VisibleValues[int AIndex] = {read=GetVisibleValue};
	
__published:
	__property TcxGridChartItemDataBinding* DataBinding = {read=FDataBinding, write=SetDataBinding};
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=SetDisplayText};
	__property Dxcore::TdxSortOrder SortOrder = {read=GetSortOrder, write=SetSortOrder, default=0};
	__property int Tag = {read=GetTag, write=SetTag, stored=IsTagStored, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property bool VisibleForCustomization = {read=FVisibleForCustomization, write=SetVisibleForCustomization, default=1};
	__property TcxGridChartItemGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=SetOnGetStoredProperties};
	__property TcxGridChartItemGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=SetOnGetStoredPropertyValue};
	__property TcxGridChartGetValueDisplayTextEvent OnGetValueDisplayText = {read=FOnGetValueDisplayText, write=SetOnGetValueDisplayText};
	__property TcxGridChartItemSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=SetOnSetStoredPropertyValue};
private:
	void *__IcxGridChartItem;	/* IcxGridChartItem */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {CDDAE712-6292-4814-A69E-7D871B299EB2}
	operator _di_IcxGridChartItem()
	{
		_di_IcxGridChartItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxGridChartItem*(void) { return (IcxGridChartItem*)&__IcxGridChartItem; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	
};


typedef System::TMetaClass* TcxGridChartCategoriesClass;

class DELPHICLASS TcxGridChartCategories;
class PASCALIMPLEMENTATION TcxGridChartCategories : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
public:
	System::Variant operator[](int Index) { return Values[Index]; }
	
private:
	TcxGridChartItemDataBinding* FDataBinding;
	System::UnicodeString FDisplayText;
	TcxGridChartGetValueDisplayTextEvent FOnGetValueDisplayText;
	TcxGridChartView* __fastcall GetGridView(void);
	int __fastcall GetID(void);
	Dxcore::TdxSortOrder __fastcall GetSortOrder(void);
	System::Variant __fastcall GetValue(int Index);
	int __fastcall GetValueCount(void);
	System::UnicodeString __fastcall GetVisibleDisplayText(int Index);
	System::Variant __fastcall GetVisibleValue(int Index);
	int __fastcall GetVisibleValueCount(void);
	void __fastcall SetDataBinding(TcxGridChartItemDataBinding* Value);
	void __fastcall SetDisplayText(const System::UnicodeString Value);
	void __fastcall SetOnGetValueDisplayText(TcxGridChartGetValueDisplayTextEvent Value);
	void __fastcall SetSortOrder(Dxcore::TdxSortOrder Value);
	void __fastcall SetValue(int Index, const System::Variant &Value);
	void __fastcall SetValueCount(int Value);
	
protected:
	virtual void __fastcall DataChanged(void);
	TcxGridChartItemDataBinding* __fastcall GetDataBinding(void);
	void __fastcall ValueTypeClassChanged(void);
	virtual void __fastcall DoGetValueDisplayText(const System::Variant &AValue, System::UnicodeString &ADisplayText);
	virtual System::UnicodeString __fastcall GetDefaultDisplayText(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetDefaultValueTypeClass(void);
	
public:
	__fastcall virtual TcxGridChartCategories(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxGridChartCategories(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::UnicodeString __fastcall GetDisplayText(void);
	DYNAMIC System::UnicodeString __fastcall GetNamePath(void);
	System::UnicodeString __fastcall GetValueDisplayText(const System::Variant &AValue);
	__property TcxGridChartView* GridView = {read=GetGridView};
	__property int ID = {read=GetID, nodefault};
	__property int ValueCount = {read=GetValueCount, write=SetValueCount, nodefault};
	__property System::Variant Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
	__property System::UnicodeString VisibleDisplayTexts[int Index] = {read=GetVisibleDisplayText};
	__property int VisibleValueCount = {read=GetVisibleValueCount, nodefault};
	__property System::Variant VisibleValues[int Index] = {read=GetVisibleValue};
	
__published:
	__property TcxGridChartItemDataBinding* DataBinding = {read=FDataBinding, write=SetDataBinding};
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=SetDisplayText};
	__property Dxcore::TdxSortOrder SortOrder = {read=GetSortOrder, write=SetSortOrder, default=0};
	__property TcxGridChartGetValueDisplayTextEvent OnGetValueDisplayText = {read=FOnGetValueDisplayText, write=SetOnGetValueDisplayText};
private:
	void *__IcxGridChartItem;	/* IcxGridChartItem */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {CDDAE712-6292-4814-A69E-7D871B299EB2}
	operator _di_IcxGridChartItem()
	{
		_di_IcxGridChartItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxGridChartItem*(void) { return (IcxGridChartItem*)&__IcxGridChartItem; }
	#endif
	
};


typedef System::TMetaClass* TcxGridChartDataGroupClass;

class PASCALIMPLEMENTATION TcxGridChartDataGroup : public TcxGridChartItem
{
	typedef TcxGridChartItem inherited;
	
private:
	System::Variant FActiveValue;
	bool __fastcall GetActive(void);
	System::UnicodeString __fastcall GetActiveValueDisplayText(void);
	int __fastcall GetDataLevel(void);
	int __fastcall GetGroupIndex(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetActiveValue(const System::Variant &Value);
	void __fastcall SetDataLevel(int Value);
	void __fastcall SetGroupIndex(int Value);
	
protected:
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall SetRestoredIndex(int AValue);
	void __fastcall CheckActiveValue(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetDefaultValueTypeClass(void);
	virtual System::Variant __fastcall GetValue(int AIndex);
	virtual int __fastcall GetValueCount(void);
	virtual System::Variant __fastcall GetVisibleValue(int AIndex);
	virtual int __fastcall GetVisibleValueCount(void);
	virtual void __fastcall SetValue(int AIndex, const System::Variant &Value);
	virtual void __fastcall SetValueCount(int Value);
	virtual bool __fastcall CanMove(void);
	__property int GroupIndex = {read=GetGroupIndex, write=SetGroupIndex, nodefault};
	
public:
	bool __fastcall HasActiveValue(void);
	__classmethod virtual bool __fastcall IsValue();
	__property bool Active = {read=GetActive, write=SetActive, nodefault};
	__property System::Variant ActiveValue = {read=FActiveValue, write=SetActiveValue};
	__property System::UnicodeString ActiveValueDisplayText = {read=GetActiveValueDisplayText};
	__property int DataLevel = {read=GetDataLevel, write=SetDataLevel, nodefault};
	
__published:
	__property SortOrder = {default=1};
public:
	/* TcxGridChartItem.Create */ inline __fastcall virtual TcxGridChartDataGroup(System::Classes::TComponent* AOwner) : TcxGridChartItem(AOwner) { }
	/* TcxGridChartItem.Destroy */ inline __fastcall virtual ~TcxGridChartDataGroup(void) { }
	
};


typedef void __fastcall (__closure *TcxGridChartSeriesGetValueStyleEvent)(TcxGridChartSeries* Sender, int AValueIndex, Cxstyles::TcxStyle* &AStyle);

typedef System::TMetaClass* TcxGridChartSeriesStylesClass;

class DELPHICLASS TcxGridChartSeriesStyles;
class PASCALIMPLEMENTATION TcxGridChartSeriesStyles : public Cxgridcustomview::TcxCustomGridStyles
{
	typedef Cxgridcustomview::TcxCustomGridStyles inherited;
	
private:
	TcxGridChartSeriesGetValueStyleEvent FOnGetValueStyle;
	TcxGridChartSeries* __fastcall GetSeries(void);
	void __fastcall SetOnGetValueStyle(TcxGridChartSeriesGetValueStyleEvent Value);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetGridView(void);
	
public:
	__fastcall virtual TcxGridChartSeriesStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetValueParams(int AValueIndex, bool AVaryColorsByCategory, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridChartSeries* Series = {read=GetSeries};
	
__published:
	__property Cxstyles::TcxStyle* Values = {read=GetValue, write=SetValue, index=0};
	__property TcxGridChartSeriesGetValueStyleEvent OnGetValueStyle = {read=FOnGetValueStyle, write=SetOnGetValueStyle};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridChartSeriesStyles(void) { }
	
};


typedef void __fastcall (__closure *TcxGridChartSeriesValueCustomDrawEvent)(TcxGridChartSeries* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartDiagramValueViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridChartValueClickEvent)(TcxGridChartView* Sender, TcxGridChartSeries* ASeries, int AValueIndex, bool &AHandled);

typedef System::TMetaClass* TcxGridChartSeriesClass;

class PASCALIMPLEMENTATION TcxGridChartSeries : public TcxGridChartItem
{
	typedef TcxGridChartItem inherited;
	
private:
	int FGroupIndex;
	TcxGridChartSeriesStyles* FStyles;
	System::UnicodeString FValueCaptionFormat;
	int FVisibleGroupIndex;
	TcxGridChartSeriesValueCustomDrawEvent FOnCustomDrawValue;
	TcxGridChartValueClickEvent FOnValueClick;
	Cxcustomdata::TcxSummaryKind __fastcall GetGroupSummaryKind(void);
	System::Variant __fastcall GetSumOfValues(void);
	void __fastcall SetGroupIndex(int Value);
	void __fastcall SetGroupSummaryKind(Cxcustomdata::TcxSummaryKind Value);
	void __fastcall SetStyles(TcxGridChartSeriesStyles* Value);
	void __fastcall SetValueCaptionFormat(const System::UnicodeString Value);
	void __fastcall SetOnCustomDrawValue(TcxGridChartSeriesValueCustomDrawEvent Value);
	void __fastcall SetOnValueClick(TcxGridChartValueClickEvent Value);
	
protected:
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall SetRestoredIndex(int AValue);
	virtual void __fastcall DoGetValueDisplayText(const System::Variant &AValue, System::UnicodeString &ADisplayText);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetDefaultValueTypeClass(void);
	virtual TcxGridChartSeriesStylesClass __fastcall GetStylesClass(void);
	virtual bool __fastcall IsGroupSummaryKindValid(Cxcustomdata::TcxSummaryKind AValue);
	virtual System::Variant __fastcall GetValue(int AIndex);
	virtual int __fastcall GetValueCount(void);
	virtual System::Variant __fastcall GetVisibleValue(int AIndex);
	virtual int __fastcall GetVisibleValueCount(void);
	virtual void __fastcall SetValue(int AIndex, const System::Variant &Value);
	virtual void __fastcall SetValueCount(int Value);
	virtual void __fastcall DoCustomDrawValue(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartDiagramValueViewInfo* AViewInfo, bool &ADone);
	virtual bool __fastcall DoValueClick(int AValueIndex);
	virtual bool __fastcall HasCustomDrawValue(void);
	
public:
	__fastcall virtual TcxGridChartSeries(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridChartSeries(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	int __fastcall AddValue(const System::Variant &AValue);
	__classmethod virtual bool __fastcall IsValue();
	__property System::Variant SumOfValues = {read=GetSumOfValues};
	__property int VisibleGroupIndex = {read=FVisibleGroupIndex, nodefault};
	
__published:
	__property int GroupIndex = {read=FGroupIndex, write=SetGroupIndex, default=0};
	__property Cxcustomdata::TcxSummaryKind GroupSummaryKind = {read=GetGroupSummaryKind, write=SetGroupSummaryKind, default=1};
	__property TcxGridChartSeriesStyles* Styles = {read=FStyles, write=SetStyles};
	__property System::UnicodeString ValueCaptionFormat = {read=FValueCaptionFormat, write=SetValueCaptionFormat};
	__property System::Classes::TNotifyEvent StylesEvents = {read=FSubObjectEvents, write=FSubObjectEvents};
	__property TcxGridChartSeriesValueCustomDrawEvent OnCustomDrawValue = {read=FOnCustomDrawValue, write=SetOnCustomDrawValue};
	__property TcxGridChartValueClickEvent OnValueClick = {read=FOnValueClick, write=SetOnValueClick};
};


typedef System::TMetaClass* TcxGridChartTitleClass;

class DELPHICLASS TcxGridChartTitle;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartTitle : public TcxCustomGridChartTitle
{
	typedef TcxCustomGridChartTitle inherited;
	
protected:
	virtual TcxGridChartPartPosition __fastcall GetDefaultPosition(void);
	
__published:
	__property Position = {default=0};
public:
	/* TcxCustomGridOptions.Create */ inline __fastcall virtual TcxGridChartTitle(Cxgridcustomview::TcxCustomGridView* AGridView) : TcxCustomGridChartTitle(AGridView) { }
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridChartTitle(void) { }
	
};

#pragma pack(pop)

enum TcxGridChartDataLevelsInfoVisible : unsigned char { dlivNever, dlivNonEmpty, dlivAlways };

enum TcxGridChartToolBoxBorder : unsigned char { tbNone, tbSingle };

enum TcxGridChartToolBoxPosition : unsigned char { tpTop, tpBottom };

enum TcxGridChartToolBoxVisible : unsigned char { tvNever, tvNonEmpty, tvAlways };

typedef System::TMetaClass* TcxGridChartToolBoxClass;

class DELPHICLASS TcxGridChartToolBox;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartToolBox : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	TcxGridChartToolBoxBorder FBorder;
	bool FCustomizeButton;
	int FDataLevelActiveValueDropDownCount;
	int FDataLevelActiveValueDropDownWidth;
	TcxGridChartDataLevelsInfoVisible FDataLevelsInfoVisible;
	bool FDiagramSelector;
	TcxGridChartToolBoxPosition FPosition;
	TcxGridChartToolBoxVisible FVisible;
	TcxGridChartView* __fastcall GetGridView(void);
	void __fastcall SetBorder(TcxGridChartToolBoxBorder Value);
	void __fastcall SetCustomizeButton(bool Value);
	void __fastcall SetDataLevelActiveValueDropDownCount(int Value);
	void __fastcall SetDataLevelActiveValueDropDownWidth(int Value);
	void __fastcall SetDataLevelsInfoVisible(TcxGridChartDataLevelsInfoVisible Value);
	void __fastcall SetDiagramSelector(bool Value);
	void __fastcall SetPosition(TcxGridChartToolBoxPosition Value);
	void __fastcall SetVisible(TcxGridChartToolBoxVisible Value);
	
protected:
	virtual void __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual bool __fastcall IsDataLevelsInfoNonEmpty(void);
	virtual bool __fastcall IsNonEmpty(void);
	
public:
	__fastcall virtual TcxGridChartToolBox(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall GetDataLevelsInfoVisible(void);
	bool __fastcall GetVisible(void);
	__property TcxGridChartView* GridView = {read=GetGridView};
	
__published:
	__property TcxGridChartToolBoxBorder Border = {read=FBorder, write=SetBorder, default=1};
	__property bool CustomizeButton = {read=FCustomizeButton, write=SetCustomizeButton, default=0};
	__property int DataLevelActiveValueDropDownCount = {read=FDataLevelActiveValueDropDownCount, write=SetDataLevelActiveValueDropDownCount, default=15};
	__property int DataLevelActiveValueDropDownWidth = {read=FDataLevelActiveValueDropDownWidth, write=SetDataLevelActiveValueDropDownWidth, default=0};
	__property TcxGridChartDataLevelsInfoVisible DataLevelsInfoVisible = {read=FDataLevelsInfoVisible, write=SetDataLevelsInfoVisible, default=1};
	__property bool DiagramSelector = {read=FDiagramSelector, write=SetDiagramSelector, default=0};
	__property TcxGridChartToolBoxPosition Position = {read=FPosition, write=SetPosition, default=0};
	__property TcxGridChartToolBoxVisible Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridChartToolBox(void) { }
	
};

#pragma pack(pop)

enum TcxGridChartValueHotTrack : unsigned char { vhDefault, vhNever, vhAlways };

class DELPHICLASS TcxGridChartOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartOptionsBehavior : public Cxgridcustomview::TcxCustomGridOptionsBehavior
{
	typedef Cxgridcustomview::TcxCustomGridOptionsBehavior inherited;
	
private:
	bool FValueHints;
	TcxGridChartValueHotTrack FValueHotTrack;
	TcxGridChartView* __fastcall GetGridView(void);
	void __fastcall SetValueHints(bool Value);
	void __fastcall SetValueHotTrack(TcxGridChartValueHotTrack Value);
	
protected:
	virtual void __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual bool __fastcall GetDefaultValueHotTrack(int AValueIndex);
	
public:
	__fastcall virtual TcxGridChartOptionsBehavior(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall GetValueHotTrack(int AValueIndex);
	__property TcxGridChartView* GridView = {read=GetGridView};
	
__published:
	__property HintHidePause = {default=0};
	__property SuppressHintOnMouseDown = {default=1};
	__property bool ValueHints = {read=FValueHints, write=SetValueHints, default=1};
	__property TcxGridChartValueHotTrack ValueHotTrack = {read=FValueHotTrack, write=SetValueHotTrack, default=0};
public:
	/* TcxCustomGridOptionsBehavior.Destroy */ inline __fastcall virtual ~TcxGridChartOptionsBehavior(void) { }
	
};

#pragma pack(pop)

enum TcxGridChartDataDrillUpMethod : unsigned char { ddumNone, ddumValueMouseRightButtonClick, ddumMouseRightButtonClick };

typedef System::TMetaClass* TcxGridChartOptionsCustomizeClass;

class DELPHICLASS TcxGridChartOptionsCustomize;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartOptionsCustomize : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	bool FDataDrillDown;
	TcxGridChartDataDrillUpMethod FDataDrillUpMethod;
	bool FDataGroupHiding;
	bool FDataGroupMoving;
	bool FOptionsCustomization;
	bool FSeriesCustomization;
	void __fastcall SetDataDrillDown(bool Value);
	void __fastcall SetDataDrillUpMethod(TcxGridChartDataDrillUpMethod Value);
	void __fastcall SetDataGroupHiding(bool Value);
	void __fastcall SetDataGroupMoving(bool Value);
	void __fastcall SetOptionsCustomization(bool Value);
	void __fastcall SetSeriesCustomization(bool Value);
	
public:
	__fastcall virtual TcxGridChartOptionsCustomize(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool DataDrillDown = {read=FDataDrillDown, write=SetDataDrillDown, default=1};
	__property TcxGridChartDataDrillUpMethod DataDrillUpMethod = {read=FDataDrillUpMethod, write=SetDataDrillUpMethod, default=2};
	__property bool DataGroupHiding = {read=FDataGroupHiding, write=SetDataGroupHiding, default=0};
	__property bool DataGroupMoving = {read=FDataGroupMoving, write=SetDataGroupMoving, default=1};
	__property bool OptionsCustomization = {read=FOptionsCustomization, write=SetOptionsCustomization, default=1};
	__property bool SeriesCustomization = {read=FSeriesCustomization, write=SetSeriesCustomization, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridChartOptionsCustomize(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridChartOptionsViewClass;

class DELPHICLASS TcxGridChartOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartOptionsView : public Cxgridcustomview::TcxCustomGridOptionsView
{
	typedef Cxgridcustomview::TcxCustomGridOptionsView inherited;
	
private:
	bool FAntialiasing;
	int FCategoriesPerPage;
	bool FTransparentCaptions;
	TcxGridChartView* __fastcall GetGridView(void);
	void __fastcall SetAntialiasing(bool Value);
	void __fastcall SetCategoriesPerPage(int Value);
	void __fastcall SetTransparentCaptions(bool Value);
	
public:
	__fastcall virtual TcxGridChartOptionsView(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridChartView* GridView = {read=GetGridView};
	
__published:
	__property bool Antialiasing = {read=FAntialiasing, write=SetAntialiasing, default=1};
	__property int CategoriesPerPage = {read=FCategoriesPerPage, write=SetCategoriesPerPage, default=0};
	__property bool TransparentCaptions = {read=FTransparentCaptions, write=SetTransparentCaptions, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridChartOptionsView(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartViewStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartViewStyles : public Cxgridcustomview::TcxCustomGridViewStyles
{
	typedef Cxgridcustomview::TcxCustomGridViewStyles inherited;
	
private:
	TcxGridChartView* __fastcall GetGridViewValue(void);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxGridChartViewStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetDataLevelInfoParams(int ADataLevel, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridChartView* GridView = {read=GetGridViewValue};
	
__published:
	__property Cxstyles::TcxStyle* ActiveDataLevelInfo = {read=GetValue, write=SetValue, index=7};
	__property Cxstyles::TcxStyle* DataLevelActiveValueInfo = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* DataLevelsInfo = {read=GetValue, write=SetValue, index=5};
	__property Cxstyles::TcxStyle* DiagramSelector = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* Legend = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* Title = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* ToolBox = {read=GetValue, write=SetValue, index=3};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridChartViewStyles(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridOpenChartItemList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridOpenChartItemList : public Cxclasses::TcxOpenList
{
	typedef Cxclasses::TcxOpenList inherited;
	
public:
	TcxGridChartItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxGridChartItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxGridChartItem* Value);
	
public:
	__property TcxGridChartItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxGridOpenChartItemList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridOpenChartItemList(void) : Cxclasses::TcxOpenList() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridChartDataGroupEvent)(TcxGridChartView* Sender, TcxGridChartDataGroup* ADataGroup);

typedef void __fastcall (__closure *TcxGridChartDiagramEvent)(TcxGridChartView* Sender, TcxGridChartDiagram* ADiagram);

typedef void __fastcall (__closure *TcxGridChartGetValueHintEvent)(TcxGridChartView* Sender, TcxGridChartSeries* ASeries, int AValueIndex, System::UnicodeString &AHint);

typedef void __fastcall (__closure *TcxGridChartLegendCustomDrawEvent)(TcxGridChartView* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartLegendViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridChartLegendItemCustomDrawEvent)(TcxGridChartView* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridChartLegendItemViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridChartSeriesEvent)(TcxGridChartView* Sender, TcxGridChartSeries* ASeries);

class PASCALIMPLEMENTATION TcxGridChartView : public Cxgridcustomview::TcxCustomGridView
{
	typedef Cxgridcustomview::TcxCustomGridView inherited;
	
private:
	int FActiveDataLevel;
	TcxGridChartDiagram* FActiveDiagram;
	System::Classes::TList* FAvailableDiagrams;
	TcxGridChartCategories* FCategories;
	bool FDataGroupActiveValuesUpdateNeeded;
	System::Classes::TList* FDataGroups;
	TcxGridChartAreaDiagram* FDiagramArea;
	TcxGridChartBarDiagram* FDiagramBar;
	TcxGridChartStackedAreaDiagram* FDiagramStackedArea;
	TcxGridChartStackedBarDiagram* FDiagramStackedBar;
	TcxGridChartStackedColumnDiagram* FDiagramStackedColumn;
	TcxGridChartColumnDiagram* FDiagramColumn;
	TcxGridChartLineDiagram* FDiagramLine;
	TcxGridChartPieDiagram* FDiagramPie;
	System::Classes::TList* FDiagrams;
	System::Classes::TList* FIDs;
	TcxGridChartLegend* FLegend;
	TcxGridChartOptionsCustomize* FOptionsCustomize;
	int FRestoredActiveDataLevel;
	TcxGridOpenChartItemList* FRestoringDataGroups;
	TcxGridOpenChartItemList* FRestoringSeries;
	System::Classes::TList* FSeries;
	TcxGridChartTitle* FTitle;
	TcxGridChartToolBox* FToolBox;
	System::Classes::TList* FVisibleDataGroups;
	System::Classes::TList* FVisibleSeries;
	System::Classes::TList* FVisibleSeriesGroups;
	System::Classes::TNotifyEvent FOnActiveDataLevelChanged;
	TcxGridChartDiagramEvent FOnActiveDiagramChanged;
	TcxGridChartLegendCustomDrawEvent FOnCustomDrawLegend;
	TcxGridChartLegendItemCustomDrawEvent FOnCustomDrawLegendItem;
	TcxGridChartDataGroupEvent FOnDataGroupPosChanged;
	System::Classes::TNotifyEvent FOnFirstVisibleCategoryIndexChanged;
	TcxGridChartGetValueHintEvent FOnGetValueHint;
	TcxGridChartSeriesEvent FOnSeriesPosChanged;
	TcxGridChartValueClickEvent FOnValueClick;
	System::Classes::TNotifyEvent FSubClassEvents;
	TcxGridChartDataGroup* __fastcall GetActiveDataGroup(void);
	TcxGridChartDiagram* __fastcall GetAvailableDiagram(int Index);
	int __fastcall GetAvailableDiagramCount(void);
	TcxGridChartController* __fastcall GetController(void);
	TcxGridChartDataController* __fastcall GetDataController(void);
	TcxGridChartDataGroup* __fastcall GetDataGroup(int Index);
	int __fastcall GetDataGroupCount(void);
	TcxGridChartDiagram* __fastcall GetDiagram(int Index);
	int __fastcall GetDiagramCount(void);
	_di_IcxGridChartItem __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	TcxGridChartOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TcxGridChartOptionsView* __fastcall GetOptionsView(void);
	TcxGridChartSeries* __fastcall GetSeries(int Index);
	int __fastcall GetSeriesCount(void);
	TcxGridChartSeries* __fastcall GetSortedSeries(void);
	TcxGridChartViewStyles* __fastcall GetStyles(void);
	TcxGridChartViewData* __fastcall GetViewData(void);
	TcxGridChartViewInfo* __fastcall GetViewInfo(void);
	TcxGridChartDataGroup* __fastcall GetVisibleDataGroup(int Index);
	int __fastcall GetVisibleDataGroupCount(void);
	TcxGridChartSeries* __fastcall GetVisibleSeries(int Index);
	int __fastcall GetVisibleSeriesCount(void);
	int __fastcall GetVisibleSeriesGroupCount(void);
	int __fastcall GetVisibleSeriesGroupIndex(int Index);
	void __fastcall SetActiveDataGroup(TcxGridChartDataGroup* Value);
	void __fastcall SetActiveDataLevel(int Value);
	void __fastcall SetActiveDiagram(TcxGridChartDiagram* Value);
	void __fastcall SetCategories(TcxGridChartCategories* Value);
	void __fastcall SetDataController(TcxGridChartDataController* Value);
	void __fastcall SetDataGroup(int Index, TcxGridChartDataGroup* Value);
	void __fastcall SetDiagramArea(TcxGridChartAreaDiagram* Value);
	void __fastcall SetDiagramBar(TcxGridChartBarDiagram* Value);
	void __fastcall SetDiagramColumn(TcxGridChartColumnDiagram* Value);
	void __fastcall SetDiagramLine(TcxGridChartLineDiagram* Value);
	void __fastcall SetDiagramPie(TcxGridChartPieDiagram* Value);
	void __fastcall SetDiagramStackedArea(TcxGridChartStackedAreaDiagram* Value);
	void __fastcall SetDiagramStackedBar(TcxGridChartStackedBarDiagram* Value);
	void __fastcall SetDiagramStackedColumn(TcxGridChartStackedColumnDiagram* Value);
	void __fastcall SetLegend(TcxGridChartLegend* Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxGridChartOptionsBehavior* Value);
	void __fastcall SetOptionsCustomize(TcxGridChartOptionsCustomize* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxGridChartOptionsView* Value);
	void __fastcall SetSeries(int Index, TcxGridChartSeries* Value);
	void __fastcall SetSortedSeries(TcxGridChartSeries* Value);
	HIDESBASE void __fastcall SetStyles(TcxGridChartViewStyles* Value);
	void __fastcall SetTitle(TcxGridChartTitle* Value);
	void __fastcall SetToolBox(TcxGridChartToolBox* Value);
	void __fastcall SetOnActiveDataLevelChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnActiveDiagramChanged(TcxGridChartDiagramEvent Value);
	void __fastcall SetOnCustomDrawLegend(TcxGridChartLegendCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawLegendItem(TcxGridChartLegendItemCustomDrawEvent Value);
	void __fastcall SetOnDataGroupPosChanged(TcxGridChartDataGroupEvent Value);
	void __fastcall SetOnFirstVisibleCategoryIndexChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnGetValueHint(TcxGridChartGetValueHintEvent Value);
	void __fastcall SetOnSeriesPosChanged(TcxGridChartSeriesEvent Value);
	void __fastcall SetOnValueClick(TcxGridChartValueClickEvent Value);
	
protected:
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall CreateStoredObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual void __fastcall AssignLayout(Cxgridcustomview::TcxCustomGridView* ALayoutView);
	virtual System::UnicodeString __fastcall GetLayoutCustomizationFormButtonCaption(void);
	virtual bool __fastcall HasLayoutCustomizationForm(void);
	virtual void __fastcall CreateHandlers(void);
	virtual void __fastcall DestroyHandlers(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual void __fastcall ActiveDataLevelChanged(int APrevActiveDataLevel);
	virtual void __fastcall ActiveDiagramChanged(TcxGridChartDiagram* ADiagram);
	virtual void __fastcall BeforeAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual void __fastcall AfterAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual void __fastcall DoAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual void __fastcall BeforeRestoring(void);
	virtual void __fastcall AfterRestoring(void);
	virtual void __fastcall DataControllerUnlocked(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	virtual void __fastcall RestoringComplete(void);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual Cxgridcustomview::TcxCustomGridControllerClass __fastcall GetControllerClass(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual TcxGridChartItemDataBindingClass __fastcall GetItemDataBindingClass(void);
	virtual Cxgridcustomview::TcxCustomGridPainterClass __fastcall GetPainterClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewDataClass __fastcall GetViewDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void);
	virtual TcxGridChartLegendClass __fastcall GetLegendClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual TcxGridChartOptionsCustomizeClass __fastcall GetOptionsCustomizeClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewStylesClass __fastcall GetStylesClass(void);
	virtual TcxGridChartTitleClass __fastcall GetTitleClass(void);
	virtual TcxGridChartToolBoxClass __fastcall GetToolBoxClass(void);
	virtual TcxGridChartAreaDiagramClass __fastcall GetAreaDiagramClass(void);
	virtual TcxGridChartBarDiagramClass __fastcall GetBarDiagramClass(void);
	virtual TcxGridChartCategoriesClass __fastcall GetCategoriesClass(void);
	virtual TcxGridChartColumnDiagramClass __fastcall GetColumnDiagramClass(void);
	virtual TcxGridChartLineDiagramClass __fastcall GetLineDiagramClass(void);
	virtual TcxGridChartPieDiagramClass __fastcall GetPieDiagramClass(void);
	virtual TcxGridChartStackedAreaDiagramClass __fastcall GetStackedAreaDiagramClass(void);
	virtual TcxGridChartStackedColumnDiagramClass __fastcall GetStackedColumnDiagramClass(void);
	virtual TcxGridChartStackedBarDiagramClass __fastcall GetStackedBarDiagramClass(void);
	virtual System::UnicodeString __fastcall GetCategoriesNamePath(void);
	void __fastcall AddDiagram(TcxGridChartDiagram* ADiagram);
	void __fastcall RemoveDiagram(TcxGridChartDiagram* ADiagram);
	void __fastcall ClearDiagrams(void);
	TcxGridChartDiagram* __fastcall CreateDiagram(TcxGridChartDiagramClass ADiagramClass);
	virtual void __fastcall CreateDiagrams(void);
	virtual void __fastcall DiagramRemoved(TcxGridChartDiagram* ADiagram);
	virtual System::UnicodeString __fastcall GetDiagramNamePath(TcxGridChartDiagram* ADiagram);
	TcxGridChartDiagram* __fastcall GetFirstAvailableDiagram(void);
	void __fastcall RefreshAvailableDiagramList(void);
	int __fastcall GetNextID(void);
	void __fastcall ReleaseID(int AID);
	virtual void __fastcall DataSortingChanged(System::TObject* AItem);
	virtual void __fastcall DataSortingChanging(System::TObject* AItem);
	void __fastcall UpdateDataController(System::TObject* AItem, TcxGridChartItemDataBinding* ADataBinding, bool AAdd);
	void __fastcall UpdateSummaryItemValues(void);
	virtual System::Classes::TList* __fastcall GetItemList(TcxGridChartItemClass AItemClass)/* overload */;
	System::Classes::TList* __fastcall GetItemList(TcxGridChartItem* AItem)/* overload */;
	virtual System::Classes::TList* __fastcall GetVisibleItemList(TcxGridChartItem* AItem);
	void __fastcall AddItem(TcxGridChartItem* AItem);
	void __fastcall RemoveItem(TcxGridChartItem* AItem);
	int __fastcall GetItemIndex(TcxGridChartItem* AItem);
	void __fastcall SetItemIndex(TcxGridChartItem* AItem, int AIndex);
	virtual void __fastcall DataGroupVisibilityChanged(TcxGridChartDataGroup* ADataGroup);
	virtual void __fastcall ItemDisplayTextChanged(TcxGridChartItem* AItem);
	virtual void __fastcall ItemIndexChanged(TcxGridChartItem* AItem);
	virtual void __fastcall ItemPosChanged(TcxGridChartItem* AItem);
	virtual void __fastcall ItemVisibilityChanged(TcxGridChartItem* AItem);
	virtual void __fastcall ItemVisibilityForCustomizationChanged(TcxGridChartItem* AItem);
	virtual void __fastcall SeriesVisibilityChanged(TcxGridChartSeries* ASeries);
	void __fastcall RefreshVisibleItemsList(System::Classes::TList* AItems, System::Classes::TList* AVisibleItems);
	void __fastcall UpdateItemsOrder(TcxGridChartItemClass AItemClass);
	void __fastcall UpdateSeriesVisibleGroups(void);
	void __fastcall ClearItems(TcxGridChartItemClass AItemClass);
	TcxGridChartItem* __fastcall CreateItem(TcxGridChartItemClass AItemClass);
	TcxGridChartItem* __fastcall FindItemByID(TcxGridChartItemClass AItemClass, int AID);
	TcxGridChartItem* __fastcall FindItemByName(TcxGridChartItemClass AItemClass, const System::UnicodeString AName);
	TcxGridChartItem* __fastcall FindItemByTag(TcxGridChartItemClass AItemClass, int ATag);
	int __fastcall GetAvailableDataLevel(int ALevel);
	virtual int __fastcall GetDataLevelCount(void);
	virtual TcxGridChartDataGroup* __fastcall GetDataLevelObject(int Index);
	virtual int __fastcall GetDataObjectLevel(TcxGridChartDataGroup* AObject);
	virtual void __fastcall SetDataObjectLevel(TcxGridChartDataGroup* AObject, int ALevel);
	virtual bool __fastcall GetIsDataGrouped(void);
	void __fastcall UpdateDataGroupActiveValues(void);
	void __fastcall UpdateDataLevels(void);
	void __fastcall UpdateDataSortingBySummary(void);
	virtual void __fastcall CalculateImageWidth(int &AWidth);
	virtual void __fastcall CalculateImageHeight(int &AHeight);
	virtual void __fastcall DoActiveDataLevelChanged(void);
	virtual void __fastcall DoActiveDiagramChanged(TcxGridChartDiagram* ADiagram);
	virtual void __fastcall DoCustomDrawLegend(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartLegendViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawLegendItem(Cxgraphics::TcxCanvas* ACanvas, TcxGridChartLegendItemViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoDataGroupPosChanged(TcxGridChartDataGroup* ADataGroup);
	virtual void __fastcall DoFirstVisibleCategoryIndexChanged(void);
	virtual void __fastcall DoGetValueHint(TcxGridChartSeries* ASeries, int AValueIndex, System::UnicodeString &AHint);
	virtual void __fastcall DoSeriesPosChanged(TcxGridChartSeries* ASeries);
	virtual bool __fastcall DoValueClick(TcxGridChartSeries* ASeries, int AValueIndex);
	virtual bool __fastcall HasCustomDrawLegend(void);
	virtual bool __fastcall HasCustomDrawLegendItem(void);
	__property bool DataGroupActiveValuesUpdateNeeded = {read=FDataGroupActiveValuesUpdateNeeded, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property _di_IcxGridChartItem Items[int Index] = {read=GetItem};
	__property TcxGridOpenChartItemList* RestoringDataGroups = {read=FRestoringDataGroups};
	__property TcxGridOpenChartItemList* RestoringSeries = {read=FRestoringSeries};
	
public:
	Vcl::Graphics::TGraphic* __fastcall CreateImage(Vcl::Graphics::TGraphicClass AGraphicClass, int AWidth = 0x0, int AHeight = 0x0);
	__property TcxGridChartController* Controller = {read=GetController};
	__property TcxGridChartViewData* ViewData = {read=GetViewData};
	__property TcxGridChartViewInfo* ViewInfo = {read=GetViewInfo};
	TcxGridChartDiagram* __fastcall FindDiagramByDisplayText(const System::UnicodeString ADisplayText);
	TcxGridChartDiagram* __fastcall FindDiagramByID(const System::UnicodeString AID);
	__property int AvailableDiagramCount = {read=GetAvailableDiagramCount, nodefault};
	__property TcxGridChartDiagram* AvailableDiagrams[int Index] = {read=GetAvailableDiagram};
	__property int DiagramCount = {read=GetDiagramCount, nodefault};
	__property TcxGridChartDiagram* Diagrams[int Index] = {read=GetDiagram};
	void __fastcall ClearSeries(void);
	TcxGridChartSeries* __fastcall CreateSeries(void);
	TcxGridChartSeries* __fastcall FindSeriesByID(int AID);
	TcxGridChartSeries* __fastcall FindSeriesByName(const System::UnicodeString AName);
	TcxGridChartSeries* __fastcall FindSeriesByTag(int ATag);
	virtual TcxGridChartSeriesClass __fastcall GetSeriesClass(void);
	__property TcxGridChartSeries* Series[int Index] = {read=GetSeries, write=SetSeries};
	__property int SeriesCount = {read=GetSeriesCount, nodefault};
	__property TcxGridChartSeries* SortedSeries = {read=GetSortedSeries, write=SetSortedSeries};
	__property TcxGridChartSeries* VisibleSeries[int Index] = {read=GetVisibleSeries};
	__property int VisibleSeriesCount = {read=GetVisibleSeriesCount, nodefault};
	__property int VisibleSeriesGroupCount = {read=GetVisibleSeriesGroupCount, nodefault};
	__property int VisibleSeriesGroupIndex[int Index] = {read=GetVisibleSeriesGroupIndex};
	void __fastcall ClearDataGroups(void);
	TcxGridChartDataGroup* __fastcall CreateDataGroup(void);
	TcxGridChartDataGroup* __fastcall FindDataGroupByID(int AID);
	TcxGridChartDataGroup* __fastcall FindDataGroupByName(const System::UnicodeString AName);
	TcxGridChartDataGroup* __fastcall FindDataGroupByTag(int ATag);
	virtual TcxGridChartDataGroupClass __fastcall GetDataGroupClass(void);
	bool __fastcall CanActivateDataLevel(int ALevel);
	__property TcxGridChartDataGroup* ActiveDataGroup = {read=GetActiveDataGroup, write=SetActiveDataGroup};
	__property int ActiveDataLevel = {read=FActiveDataLevel, write=SetActiveDataLevel, nodefault};
	__property int DataLevelCount = {read=GetDataLevelCount, nodefault};
	__property TcxGridChartDataGroup* DataLevelObjects[int Index] = {read=GetDataLevelObject};
	__property int DataGroupCount = {read=GetDataGroupCount, nodefault};
	__property TcxGridChartDataGroup* DataGroups[int Index] = {read=GetDataGroup, write=SetDataGroup};
	__property bool IsDataGrouped = {read=GetIsDataGrouped, nodefault};
	__property int VisibleDataGroupCount = {read=GetVisibleDataGroupCount, nodefault};
	__property TcxGridChartDataGroup* VisibleDataGroups[int Index] = {read=GetVisibleDataGroup};
	
__published:
	__property TcxGridChartDiagram* ActiveDiagram = {read=FActiveDiagram, write=SetActiveDiagram, stored=false};
	__property TcxGridChartCategories* Categories = {read=FCategories, write=SetCategories};
	__property TcxGridChartDataController* DataController = {read=GetDataController, write=SetDataController};
	__property TcxGridChartAreaDiagram* DiagramArea = {read=FDiagramArea, write=SetDiagramArea};
	__property TcxGridChartBarDiagram* DiagramBar = {read=FDiagramBar, write=SetDiagramBar};
	__property TcxGridChartColumnDiagram* DiagramColumn = {read=FDiagramColumn, write=SetDiagramColumn};
	__property TcxGridChartLineDiagram* DiagramLine = {read=FDiagramLine, write=SetDiagramLine};
	__property TcxGridChartPieDiagram* DiagramPie = {read=FDiagramPie, write=SetDiagramPie};
	__property TcxGridChartStackedAreaDiagram* DiagramStackedArea = {read=FDiagramStackedArea, write=SetDiagramStackedArea};
	__property TcxGridChartStackedBarDiagram* DiagramStackedBar = {read=FDiagramStackedBar, write=SetDiagramStackedBar};
	__property TcxGridChartStackedColumnDiagram* DiagramStackedColumn = {read=FDiagramStackedColumn, write=SetDiagramStackedColumn};
	__property TcxGridChartLegend* Legend = {read=FLegend, write=SetLegend};
	__property TcxGridChartOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxGridChartOptionsCustomize* OptionsCustomize = {read=FOptionsCustomize, write=SetOptionsCustomize};
	__property TcxGridChartOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxGridChartViewStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxGridChartTitle* Title = {read=FTitle, write=SetTitle};
	__property TcxGridChartToolBox* ToolBox = {read=FToolBox, write=SetToolBox};
	__property System::Classes::TNotifyEvent CategoriesEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent DiagramAreaEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent DiagramBarEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent DiagramColumnEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent DiagramLineEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent DiagramPieEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent DiagramStackedAreaEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent DiagramStackedBarEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent DiagramStackedColumnEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent OnActiveDataLevelChanged = {read=FOnActiveDataLevelChanged, write=SetOnActiveDataLevelChanged};
	__property TcxGridChartDiagramEvent OnActiveDiagramChanged = {read=FOnActiveDiagramChanged, write=SetOnActiveDiagramChanged};
	__property TcxGridChartLegendCustomDrawEvent OnCustomDrawLegend = {read=FOnCustomDrawLegend, write=SetOnCustomDrawLegend};
	__property TcxGridChartLegendItemCustomDrawEvent OnCustomDrawLegendItem = {read=FOnCustomDrawLegendItem, write=SetOnCustomDrawLegendItem};
	__property OnCustomization;
	__property TcxGridChartDataGroupEvent OnDataGroupPosChanged = {read=FOnDataGroupPosChanged, write=SetOnDataGroupPosChanged};
	__property System::Classes::TNotifyEvent OnFirstVisibleCategoryIndexChanged = {read=FOnFirstVisibleCategoryIndexChanged, write=SetOnFirstVisibleCategoryIndexChanged};
	__property TcxGridChartGetValueHintEvent OnGetValueHint = {read=FOnGetValueHint, write=SetOnGetValueHint};
	__property OnInitStoredObject;
	__property TcxGridChartSeriesEvent OnSeriesPosChanged = {read=FOnSeriesPosChanged, write=SetOnSeriesPosChanged};
	__property TcxGridChartValueClickEvent OnValueClick = {read=FOnValueClick, write=SetOnValueClick};
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridChartView(Cxcontrols::TcxControl* AControl) : Cxgridcustomview::TcxCustomGridView(AControl) { }
	/* TcxCustomGridView.Destroy */ inline __fastcall virtual ~TcxGridChartView(void) { }
	
public:
	/* TcxControlChildComponent.Create */ inline __fastcall virtual TcxGridChartView(System::Classes::TComponent* AOwner) : Cxgridcustomview::TcxCustomGridView(AOwner) { }
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridChartView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridcustomview::TcxCustomGridView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Byte cxGridChartCustomizationFormDefaultWidth = System::Byte(0xc8);
static const System::Int8 htChartBase = System::Int8(0x32);
static const System::Int8 htChartTitle = System::Int8(0x33);
static const System::Int8 htLegend = System::Int8(0x34);
static const System::Int8 htLegendItem = System::Int8(0x35);
static const System::Int8 htChartToolBox = System::Int8(0x36);
static const System::Int8 htDataLevelInfo = System::Int8(0x37);
static const System::Int8 htDataLevelActiveValueInfo = System::Int8(0x38);
static const System::Int8 htChartCustomizeButton = System::Int8(0x39);
static const System::Int8 htDiagramSelector = System::Int8(0x3a);
static const System::Int8 htChartValue = System::Int8(0x3b);
static const System::Int8 htPlot = System::Int8(0x3c);
static const System::Int8 htCategoryAxisTitle = System::Int8(0x3d);
static const System::Int8 htValueAxisTitle = System::Int8(0x3e);
static const System::Int8 htChartValueLine = System::Int8(0x3f);
static const System::Int8 htChartValueArea = System::Int8(0x40);
static const System::Int8 htSeriesSite = System::Int8(0x41);
static const System::Int8 htSeriesSiteCaption = System::Int8(0x42);
static const System::Int8 ckToolBox = System::Int8(0x2);
static const System::Int8 dsDiagramFirst = System::Int8(0x0);
static const System::Int8 dsLegend = System::Int8(0x0);
static const System::Int8 dsValueCaptions = System::Int8(0x1);
static const System::Int8 dsValues = System::Int8(0x2);
static const System::Int8 dsAxis = System::Int8(0x3);
static const System::Int8 dsCategoryAxis = System::Int8(0x4);
static const System::Int8 dsValueAxis = System::Int8(0x5);
static const System::Int8 dsAxisTitle = System::Int8(0x6);
static const System::Int8 dsCategoryAxisTitle = System::Int8(0x7);
static const System::Int8 dsValueAxisTitle = System::Int8(0x8);
static const System::Int8 dsGridLines = System::Int8(0x9);
static const System::Int8 dsCategoryGridLines = System::Int8(0xa);
static const System::Int8 dsValueGridLines = System::Int8(0xb);
static const System::Int8 dsPlot = System::Int8(0xc);
static const System::Int8 dsValueMarkers = System::Int8(0xd);
static const System::Int8 dsSeriesSiteCaptions = System::Int8(0xe);
static const System::Int8 dsSeriesSites = System::Int8(0xf);
static const System::Int8 dsDiagramLast = System::Int8(0xf);
static const System::Int8 ssSeriesFirst = System::Int8(0x0);
static const System::Int8 ssValues = System::Int8(0x0);
static const System::Int8 ssSeriesLast = System::Int8(0x0);
static const System::Int8 vsChartFirst = System::Int8(0x1);
static const System::Int8 vsTitle = System::Int8(0x1);
static const System::Int8 vsLegend = System::Int8(0x2);
static const System::Int8 vsToolBox = System::Int8(0x3);
static const System::Int8 vsDiagramSelector = System::Int8(0x4);
static const System::Int8 vsDataLevelsInfo = System::Int8(0x5);
static const System::Int8 vsDataLevelActiveValueInfo = System::Int8(0x6);
static const System::Int8 vsActiveDataLevelInfo = System::Int8(0x7);
static const System::Int8 vsChartLast = System::Int8(0x7);
static const System::Int8 cxGridChartColumnDiagramDefaultBorderWidth = System::Int8(0x1);
static const System::Int8 cxGridChartLineDiagramDefaultHotSpotSize = System::Int8(0xf);
static const System::Int8 cxGridChartLineDiagramDefaultLineWidth = System::Int8(0x1);
static const System::Int8 cxGridChartLineDiagramDefaultMarkerSize = System::Int8(0x7);
static const System::Int8 cxGridChartDefaultDataLevelActiveValueDropDownCount = System::Int8(0xf);
static const Cxcustomdata::TcxSummaryKind cxGridChartItemDefaultSummaryKind = (Cxcustomdata::TcxSummaryKind)(1);
static const System::Int8 cxGridChartSideBySideDefaultIndentWidth = System::Int8(0x2);
static const System::Int8 cxGridChartFullStackedValue = System::Int8(0x64);
extern PACKAGE Cxgraphics::TcxImageList* cxGridChartDiagramImages;
extern PACKAGE void __fastcall cxGridChartDiagramImages_Add(const System::UnicodeString AResourceName);
extern PACKAGE bool __fastcall IsValueTypeClassValid(Cxdatastorage::TcxValueTypeClass AValueTypeClass);
}	/* namespace Cxgridchartview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDCHARTVIEW)
using namespace Cxgridchartview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridchartviewHPP
