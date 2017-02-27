// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxGridLnk.pas' rev: 24.00 (Win64)

#ifndef DxpscxgridlnkHPP
#define DxpscxgridlnkHPP

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
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxGridDBDataDefinitions.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxGridDBTableView.hpp>	// Pascal unit
#include <cxGridCardView.hpp>	// Pascal unit
#include <cxGridDBCardView.hpp>	// Pascal unit
#include <cxGridBandedTableView.hpp>	// Pascal unit
#include <cxGridDBBandedTableView.hpp>	// Pascal unit
#include <cxGridChartView.hpp>	// Pascal unit
#include <cxGridDBChartView.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxGridCustomLayoutView.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <cxGridServerModeTableView.hpp>	// Pascal unit
#include <cxGridServerModeBandedTableView.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxgridlnk
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxGridViewRowProducerClass;

typedef System::TMetaClass* TdxGridViewCaptionProducerClass;

typedef System::TMetaClass* TdxGridViewFilterBarProducerClass;

typedef System::TMetaClass* TdxGridViewDetailsSeparatorProducerClass;

typedef System::TMetaClass* TdxGridViewTerminatorProducerClass;

typedef System::TMetaClass* TdxGridTableViewHeadersProducerClass;

typedef System::TMetaClass* TdxGridTableViewFootersProducerClass;

typedef System::TMetaClass* TdxGridTableViewCustomDataRowProducerClass;

typedef System::TMetaClass* TdxGridTableViewRowSeparatorProducerClass;

typedef System::TMetaClass* TdxGridTableViewGroupFooterProducerClass;

typedef System::TMetaClass* TdxGridTableViewGroupRowSeparatorProducerClass;

typedef System::TMetaClass* TdxGridTableViewBandsProducerClass;

typedef System::TMetaClass* TdxGridCardViewCardsRowProducerClass;

typedef System::TMetaClass* TdxGridCustomLayoutViewRecordProducerClass;

typedef System::TMetaClass* TdxGridChartViewChartProducerClass;

typedef System::TMetaClass* TdxGridAttributeClass;

typedef System::DynamicArray<TdxGridAttributeClass> TdxGridAttributeClasses;

class DELPHICLASS TdxGridAttribute;
class PASCALIMPLEMENTATION TdxGridAttribute : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridAttribute(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridAttribute(void) { }
	
};


class DELPHICLASS TdxGridBandHeader;
class PASCALIMPLEMENTATION TdxGridBandHeader : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridBandHeader(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridBandHeader(void) { }
	
};


class DELPHICLASS TdxGridCardRowCaption;
class PASCALIMPLEMENTATION TdxGridCardRowCaption : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridCardRowCaption(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridCardRowCaption(void) { }
	
};


class DELPHICLASS TdxGridCardRowData;
class PASCALIMPLEMENTATION TdxGridCardRowData : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridCardRowData(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridCardRowData(void) { }
	
};


class DELPHICLASS TdxGridDetails;
class PASCALIMPLEMENTATION TdxGridDetails : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridDetails(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridDetails(void) { }
	
};


class DELPHICLASS TdxGridExpandButton;
class PASCALIMPLEMENTATION TdxGridExpandButton : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridExpandButton(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridExpandButton(void) { }
	
};


class DELPHICLASS TdxGridFilterBar;
class PASCALIMPLEMENTATION TdxGridFilterBar : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridFilterBar(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridFilterBar(void) { }
	
};


class DELPHICLASS TdxGridFooter;
class PASCALIMPLEMENTATION TdxGridFooter : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridFooter(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridFooter(void) { }
	
};


class DELPHICLASS TdxGridGroupFooter;
class PASCALIMPLEMENTATION TdxGridGroupFooter : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridGroupFooter(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridGroupFooter(void) { }
	
};


class DELPHICLASS TdxGridGroupRow;
class PASCALIMPLEMENTATION TdxGridGroupRow : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridGroupRow(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridGroupRow(void) { }
	
};


class DELPHICLASS TdxGridHeader;
class PASCALIMPLEMENTATION TdxGridHeader : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridHeader(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridHeader(void) { }
	
};


class DELPHICLASS TdxGridLevelCaption;
class PASCALIMPLEMENTATION TdxGridLevelCaption : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridLevelCaption(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridLevelCaption(void) { }
	
};


class DELPHICLASS TdxGridPreview;
class PASCALIMPLEMENTATION TdxGridPreview : public TdxGridAttribute
{
	typedef TdxGridAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxGridPreview(void) : TdxGridAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridPreview(void) { }
	
};


typedef int TdxGridAttributeID;

struct DECLSPEC_DRECORD TdxGridCellCustomDrawInfo
{
public:
	TdxGridAttributeID GridAttributeID;
	Cxgridcustomview::TcxCustomGridView* GridView;
	Cxgridcustomtableview::TcxCustomGridRecord* GridRecord;
	Cxgridtableview::TcxGridColumn* GridColumn;
	int GroupLevel;
	Cxgridbandedtableview::TcxGridBand* GridBand;
	Cxgridcardview::TcxGridCard* GridCard;
	Cxgridcardview::TcxGridCardViewRow* GridCardRow;
};


enum TdxAttributeColorKind : unsigned char { ackContentColor, ackTextColor };

enum TdxVerticalDetailsSeparatorKind : unsigned char { vdskLeading, vdskTrailing };

typedef System::TMetaClass* TdxCustomGridViewHelperClass;

class DELPHICLASS TdxCustomGridViewHelper;
class PASCALIMPLEMENTATION TdxCustomGridViewHelper : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
private:
	Cxgridcustomview::TcxCustomGridView* FView;
	
protected:
	__classmethod void __fastcall AddAttribute(TdxGridAttributeClasses &AnAtributes, TdxGridAttributeClass AnAttribute);
	__classmethod virtual Cxgridcustomtableview::TcxGridFilterPosition __fastcall FilterPosition(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual bool __fastcall IsFilterBarAtBottom(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual bool __fastcall IsFilterBarAtTop(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual bool __fastcall IsOffice11StyleGrouping(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall ViewClass();
	
public:
	__fastcall virtual TdxCustomGridViewHelper(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__classmethod virtual TdxGridAttributeID __fastcall ExtractCustomDrawID(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual void __fastcall ExtractCustomDrawInfo(Dxpscore::TdxReportVisualItem* AnItem, /* out */ TdxGridCellCustomDrawInfo &ACustomDrawInfo);
	__classmethod virtual Cxgridcustomview::TcxCustomGridView* __fastcall ExtractGridView(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual bool __fastcall HasData(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual bool __fastcall IsAttributeSupported(TdxGridAttributeClass AnAttribute);
	__classmethod virtual TdxGridAttributeClasses __fastcall SupportedAttributes();
	__property Cxgridcustomview::TcxCustomGridView* View = {read=FView, write=FView};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomGridViewHelper(void) { }
	
};


class DELPHICLASS TdxNullGridViewHelper;
class PASCALIMPLEMENTATION TdxNullGridViewHelper : public TdxCustomGridViewHelper
{
	typedef TdxCustomGridViewHelper inherited;
	
protected:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall ViewClass();
	
public:
	__classmethod virtual bool __fastcall IsAttributeSupported(TdxGridAttributeClass AnAttribute);
public:
	/* TdxCustomGridViewHelper.Create */ inline __fastcall virtual TdxNullGridViewHelper(Cxgridcustomview::TcxCustomGridView* AView) : TdxCustomGridViewHelper(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNullGridViewHelper(void) { }
	
};


class DELPHICLASS TdxCustomGridTableViewHelper;
class PASCALIMPLEMENTATION TdxCustomGridTableViewHelper : public TdxCustomGridViewHelper
{
	typedef TdxCustomGridViewHelper inherited;
	
protected:
	__classmethod virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall ExtractRecord(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual Cxgridcustomtableview::TcxGridFilterPosition __fastcall FilterPosition(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall ViewClass();
	
public:
	__classmethod virtual TdxGridAttributeID __fastcall ExtractCustomDrawID(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual bool __fastcall HasData(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual TdxGridAttributeClasses __fastcall SupportedAttributes();
public:
	/* TdxCustomGridViewHelper.Create */ inline __fastcall virtual TdxCustomGridTableViewHelper(Cxgridcustomview::TcxCustomGridView* AView) : TdxCustomGridViewHelper(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomGridTableViewHelper(void) { }
	
};


class DELPHICLASS TdxGridCardViewHelper;
class PASCALIMPLEMENTATION TdxGridCardViewHelper : public TdxCustomGridTableViewHelper
{
	typedef TdxCustomGridTableViewHelper inherited;
	
protected:
	__classmethod virtual Cxgridcardview::TcxGridCard* __fastcall ExtractCard(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual Cxgridcardview::TcxGridCardViewRow* __fastcall ExtractCardRow(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall ExtractRecord(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall ViewClass();
	
public:
	__classmethod virtual TdxGridAttributeID __fastcall ExtractCustomDrawID(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual void __fastcall ExtractCustomDrawInfo(Dxpscore::TdxReportVisualItem* AnItem, /* out */ TdxGridCellCustomDrawInfo &ACustomDrawInfo);
public:
	/* TdxCustomGridViewHelper.Create */ inline __fastcall virtual TdxGridCardViewHelper(Cxgridcustomview::TcxCustomGridView* AView) : TdxCustomGridTableViewHelper(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridCardViewHelper(void) { }
	
};


class DELPHICLASS TdxGridTableViewHelper;
class PASCALIMPLEMENTATION TdxGridTableViewHelper : public TdxCustomGridTableViewHelper
{
	typedef TdxCustomGridTableViewHelper inherited;
	
protected:
	__classmethod virtual Cxgridtableview::TcxGridColumn* __fastcall ExtractColumn(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual int __fastcall ExtractGroupLevel(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall ExtractRecord(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual bool __fastcall IsOffice11StyleGrouping(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall ViewClass();
	
public:
	__classmethod virtual TdxGridAttributeID __fastcall ExtractCustomDrawID(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual void __fastcall ExtractCustomDrawInfo(Dxpscore::TdxReportVisualItem* AnItem, /* out */ TdxGridCellCustomDrawInfo &ACustomDrawInfo);
	__classmethod virtual TdxGridAttributeClasses __fastcall SupportedAttributes();
public:
	/* TdxCustomGridViewHelper.Create */ inline __fastcall virtual TdxGridTableViewHelper(Cxgridcustomview::TcxCustomGridView* AView) : TdxCustomGridTableViewHelper(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridTableViewHelper(void) { }
	
};


class DELPHICLASS TdxGridBandedTableViewHelper;
class PASCALIMPLEMENTATION TdxGridBandedTableViewHelper : public TdxGridTableViewHelper
{
	typedef TdxGridTableViewHelper inherited;
	
protected:
	__classmethod virtual Cxgridbandedtableview::TcxGridBand* __fastcall ExtractBand(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall ViewClass();
	
public:
	__classmethod virtual TdxGridAttributeID __fastcall ExtractCustomDrawID(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual void __fastcall ExtractCustomDrawInfo(Dxpscore::TdxReportVisualItem* AnItem, /* out */ TdxGridCellCustomDrawInfo &ACustomDrawInfo);
	__classmethod virtual TdxGridAttributeClasses __fastcall SupportedAttributes();
public:
	/* TdxCustomGridViewHelper.Create */ inline __fastcall virtual TdxGridBandedTableViewHelper(Cxgridcustomview::TcxCustomGridView* AView) : TdxGridTableViewHelper(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridBandedTableViewHelper(void) { }
	
};


class DELPHICLASS TdxGridChartViewHelper;
class PASCALIMPLEMENTATION TdxGridChartViewHelper : public TdxCustomGridViewHelper
{
	typedef TdxCustomGridViewHelper inherited;
	
protected:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall ViewClass();
	
public:
	__classmethod virtual bool __fastcall HasData(Cxgridcustomview::TcxCustomGridView* AView);
public:
	/* TdxCustomGridViewHelper.Create */ inline __fastcall virtual TdxGridChartViewHelper(Cxgridcustomview::TcxCustomGridView* AView) : TdxCustomGridViewHelper(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridChartViewHelper(void) { }
	
};


typedef System::TMetaClass* TdxCustomGridRecordHelperClass;

class DELPHICLASS TdxCustomGridRecordHelper;
class DELPHICLASS TdxCustomGridTableViewAdapter;
class PASCALIMPLEMENTATION TdxCustomGridRecordHelper : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
private:
	TdxCustomGridTableViewAdapter* FAdapter;
	Cxgridcustomtableview::TcxCustomGridRecord* FGridRecord;
	
protected:
	virtual TdxCustomGridTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridTableViewCustomDataRowProducerClass __fastcall ProducerClass();
	__classmethod virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall RecordClass();
	virtual bool __fastcall GetCanCellMergingAsMaster(void);
	virtual bool __fastcall GetCanCellMergingAsSlave(void);
	virtual bool __fastcall GetHasDetails(void);
	virtual bool __fastcall GetHasExpandButton(void);
	virtual bool __fastcall GetHasSelectedChildren(void);
	virtual bool __fastcall GetIsCellMergingSeparator(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetParent(void);
	
public:
	__fastcall virtual TdxCustomGridRecordHelper(TdxCustomGridTableViewAdapter* AAdapter);
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__property bool CanCellMergingAsMaster = {read=GetCanCellMergingAsMaster, nodefault};
	__property bool CanCellMergingAsSlave = {read=GetCanCellMergingAsSlave, nodefault};
	__property Cxgridcustomtableview::TcxCustomGridRecord* GridRecord = {read=FGridRecord, write=FGridRecord};
	__property bool HasDetails = {read=GetHasDetails, nodefault};
	__property bool HasExpandButton = {read=GetHasExpandButton, nodefault};
	__property bool HasSelectedChildren = {read=GetHasSelectedChildren, nodefault};
	__property bool IsCellMergingSeparator = {read=GetIsCellMergingSeparator, nodefault};
	__property Cxgridcustomtableview::TcxCustomGridRecord* Parent = {read=GetParent};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomGridRecordHelper(void) { }
	
};


class DELPHICLASS TdxCustomGridRowHelper;
class DELPHICLASS TdxGridTableViewAdapter;
class PASCALIMPLEMENTATION TdxCustomGridRowHelper : public TdxCustomGridRecordHelper
{
	typedef TdxCustomGridRecordHelper inherited;
	
protected:
	HIDESBASE TdxGridTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall RecordClass();
public:
	/* TdxCustomGridRecordHelper.Create */ inline __fastcall virtual TdxCustomGridRowHelper(TdxCustomGridTableViewAdapter* AAdapter) : TdxCustomGridRecordHelper(AAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomGridRowHelper(void) { }
	
};


class DELPHICLASS TdxGridDataRowHelper;
class PASCALIMPLEMENTATION TdxGridDataRowHelper : public TdxCustomGridRowHelper
{
	typedef TdxCustomGridRowHelper inherited;
	
private:
	Cxgridtableview::TcxGridDataRow* __fastcall GetRow(void);
	
protected:
	__classmethod virtual TdxGridTableViewCustomDataRowProducerClass __fastcall ProducerClass();
	__classmethod virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall RecordClass();
	
public:
	__property Cxgridtableview::TcxGridDataRow* Row = {read=GetRow};
public:
	/* TdxCustomGridRecordHelper.Create */ inline __fastcall virtual TdxGridDataRowHelper(TdxCustomGridTableViewAdapter* AAdapter) : TdxCustomGridRowHelper(AAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridDataRowHelper(void) { }
	
};


class DELPHICLASS TdxGridGroupRowHelper;
class PASCALIMPLEMENTATION TdxGridGroupRowHelper : public TdxCustomGridRowHelper
{
	typedef TdxCustomGridRowHelper inherited;
	
private:
	Cxgridtableview::TcxGridGroupRow* __fastcall GetGroupRow(void);
	
protected:
	__classmethod virtual TdxGridTableViewCustomDataRowProducerClass __fastcall ProducerClass();
	__classmethod virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall RecordClass();
	virtual bool __fastcall GetCanCellMergingAsMaster(void);
	virtual bool __fastcall GetCanCellMergingAsSlave(void);
	virtual bool __fastcall GetHasExpandButton(void);
	virtual bool __fastcall GetHasSelectedChildren(void);
	
public:
	__property Cxgridtableview::TcxGridGroupRow* GroupRow = {read=GetGroupRow};
public:
	/* TdxCustomGridRecordHelper.Create */ inline __fastcall virtual TdxGridGroupRowHelper(TdxCustomGridTableViewAdapter* AAdapter) : TdxCustomGridRowHelper(AAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridGroupRowHelper(void) { }
	
};


class DELPHICLASS TdxGridMasterDataRowHelper;
class PASCALIMPLEMENTATION TdxGridMasterDataRowHelper : public TdxCustomGridRowHelper
{
	typedef TdxCustomGridRowHelper inherited;
	
private:
	Cxgridcustomview::TcxCustomGridView* __fastcall GetDetailView(void);
	Cxgridtableview::TcxGridMasterDataRow* __fastcall GetMasterRow(void);
	
protected:
	__classmethod virtual TdxGridTableViewCustomDataRowProducerClass __fastcall ProducerClass();
	__classmethod virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall RecordClass();
	virtual bool __fastcall GetCanCellMergingAsMaster(void);
	virtual bool __fastcall GetHasDetails(void);
	virtual bool __fastcall GetHasExpandButton(void);
	virtual bool __fastcall GetHasSelectedChildren(void);
	virtual bool __fastcall GetIsCellMergingSeparator(void);
	
public:
	__property Cxgridcustomview::TcxCustomGridView* DetailView = {read=GetDetailView};
	__property Cxgridtableview::TcxGridMasterDataRow* MasterRow = {read=GetMasterRow};
public:
	/* TdxCustomGridRecordHelper.Create */ inline __fastcall virtual TdxGridMasterDataRowHelper(TdxCustomGridTableViewAdapter* AAdapter) : TdxCustomGridRowHelper(AAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridMasterDataRowHelper(void) { }
	
};


class DELPHICLASS TdxRecordHelpersCache;
class PASCALIMPLEMENTATION TdxRecordHelpersCache : public Dxbase::TdxCustomCache
{
	typedef Dxbase::TdxCustomCache inherited;
	
public:
	TdxCustomGridRecordHelper* operator[](Cxgridcustomtableview::TcxCustomGridRecord* ARecord) { return Helpers[ARecord]; }
	
private:
	TdxCustomGridTableViewAdapter* FAdapter;
	TdxCustomGridRecordHelper* __fastcall GetHelper(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	HIDESBASE TdxCustomGridRecordHelper* __fastcall GetItem(int Index);
	
protected:
	int __fastcall IndexOf(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__property TdxCustomGridRecordHelper* Items[int Index] = {read=GetItem};
	
public:
	__fastcall TdxRecordHelpersCache(TdxCustomGridTableViewAdapter* AAdapter);
	__property TdxCustomGridTableViewAdapter* Adapter = {read=FAdapter};
	__property TdxCustomGridRecordHelper* Helpers[Cxgridcustomtableview::TcxCustomGridRecord* ARecord] = {read=GetHelper/*, default*/};
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TdxRecordHelpersCache(void) { }
	
};


class DELPHICLASS TdxProducerCache;
class DELPHICLASS TdxCustomGridViewBuilder;
class DELPHICLASS TdxGridViewRowProducer;
class PASCALIMPLEMENTATION TdxProducerCache : public Dxbase::TdxCustomCache
{
	typedef Dxbase::TdxCustomCache inherited;
	
public:
	TdxGridViewRowProducer* operator[](TdxGridViewRowProducerClass ProducerClass) { return Producers[ProducerClass]; }
	
private:
	TdxCustomGridViewBuilder* FBuilder;
	HIDESBASE TdxGridViewRowProducer* __fastcall GetItem(int Index);
	TdxGridViewRowProducer* __fastcall GetProducer(TdxGridViewRowProducerClass ProducerClass);
	
protected:
	int __fastcall IndexOf(TdxGridViewRowProducerClass AProducerClass);
	__property TdxGridViewRowProducer* Items[int Index] = {read=GetItem};
	
public:
	__fastcall TdxProducerCache(TdxCustomGridViewBuilder* ABuilder);
	__property TdxCustomGridViewBuilder* Builder = {read=FBuilder};
	__property TdxGridViewRowProducer* Producers[TdxGridViewRowProducerClass ProducerClass] = {read=GetProducer/*, default*/};
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TdxProducerCache(void) { }
	
};


typedef System::TMetaClass* TdxGridViewAdapterClass;

class DELPHICLASS TdxCustomGridViewAdapter;
class DELPHICLASS TdxGridReportLinkOptionsExpanding;
class PASCALIMPLEMENTATION TdxCustomGridViewAdapter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgridcustomview::TcxCustomGridView* FGridView;
	TdxCustomGridViewAdapter* FMasterAdapter;
	bool FPrevAllRecordsAreLoaded;
	int __fastcall GetAbsoluteLevel(void);
	bool __fastcall GetCanUseLookAndFeelColors(void);
	System::UnicodeString __fastcall GetCaptionText(void);
	System::Uitypes::TColor __fastcall GetDetailsSeparatorColor(void);
	int __fastcall GetDetailsSeparatorThickness(void);
	System::Uitypes::TColor __fastcall GetExpandButtonColor(void);
	int __fastcall GetExpandButtonSize(void);
	Cxcustomdata::TcxDataFilterCriteria* __fastcall GetFilter(void);
	bool __fastcall GetFilterActive(void);
	bool __fastcall GetFilterEmpty(void);
	System::UnicodeString __fastcall GetFilterText(void);
	Cxgrid::TcxCustomGrid* __fastcall GetGrid(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetGridLevel(void);
	int __fastcall GetGridWidth(void);
	bool __fastcall GetHasDetailsSeparator(void);
	Cxlookandfeels::TcxLookAndFeelKind __fastcall GetLookAndFeelKind(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	bool __fastcall GetIsDetail(void);
	bool __fastcall GetIsMaster(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetMasterGridLevel(void);
	Cxcustomdata::TcxDataSummary* __fastcall GetSummary(void);
	System::Uitypes::TColor __fastcall GetThemedCaptionColor(void);
	System::Uitypes::TColor __fastcall GetThemedCaptionTextColor(void);
	System::Uitypes::TColor __fastcall GetThemedFilterBarColor(void);
	System::Uitypes::TColor __fastcall GetThemedFilterBarTextColor(void);
	int __fastcall GetViewWidth(void);
	
protected:
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual Cxgridcustomview::TcxCustomGridBackgroundBitmaps* __fastcall BackgroundBitmaps(void)/* overload */;
	Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(int Index);
	bool __fastcall HasBackgroundBitmap(int Index);
	virtual bool __fastcall IsBackgroundBitmapSupported(int Index);
	virtual Cxgridcustomview::TcxCustomGridController* __fastcall Controller(void)/* overload */;
	virtual Cxcustomdata::TcxCustomDataController* __fastcall DataController(void)/* overload */;
	TdxCustomGridViewAdapter* __fastcall CreateCloneAdapter(Cxgridcustomview::TcxCustomGridView* AClone);
	virtual void __fastcall ExpandAllRowsInClones(bool AMasterRows, bool AGroupRows);
	void __fastcall ExpandAllRowsInGridView(Cxgridcustomview::TcxCustomGridView* AGridView, bool AMasterRows, bool AGroupRows);
	void __fastcall ExpandAllRowsInLevel(Cxgridlevel::TcxGridLevel* ALevel, bool AMasterRows, bool AGroupRows, bool ARecursive);
	virtual void __fastcall ExpandAllRowsInItself(bool AMasterRows, bool AGroupRows);
	virtual bool __fastcall GetAreAllMasterRowsCollapsed(void);
	virtual bool __fastcall GetAutoWidth(void);
	virtual bool __fastcall GetCanUseOnEveryPageMode(void);
	virtual Cxgridcustomtableview::TcxGridFilterPosition __fastcall GetFilterPosition(void);
	virtual bool __fastcall GetHasSelectedRecords(void);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetIndentWidth(void);
	virtual bool __fastcall GetIsOffice11StyleGrouping(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetMasterGridRecord(void);
	virtual int __fastcall GetRecordCount(void);
	virtual int __fastcall GetViewWidthExtra(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetCaptionViewParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetFilterBarViewParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetRootCaptionParams(void);
	virtual Cxdbdata::TcxDBDataModeController* __fastcall DBDataModeController(void);
	virtual bool __fastcall IsBoundView(void);
	virtual void __fastcall LoadAllRecords(void);
	virtual void __fastcall UnloadAllRecords(void);
	__property Cxcustomdata::TcxDataFilterCriteria* Filter = {read=GetFilter};
	__property Cxgrid::TcxCustomGrid* Grid = {read=GetGrid};
	__property Cxlookandfeels::TcxLookAndFeelKind LookAndFeelKind = {read=GetLookAndFeelKind, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property Cxcustomdata::TcxDataSummary* Summary = {read=GetSummary};
	
public:
	__fastcall virtual TdxCustomGridViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	virtual Cxgridcustomview::TcxCustomGridStyles* __fastcall Styles(void)/* overload */;
	virtual void __fastcall ExpandAllRows(TdxGridReportLinkOptionsExpanding* AnOptionsExpanding, bool ARecursive);
	__property int AbsoluteLevel = {read=GetAbsoluteLevel, nodefault};
	__property bool AreAllMasterRowsCollapsed = {read=GetAreAllMasterRowsCollapsed, nodefault};
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property bool CanUseOnEveryPageMode = {read=GetCanUseOnEveryPageMode, nodefault};
	__property bool CanUseLookAndFeelColors = {read=GetCanUseLookAndFeelColors, nodefault};
	__property System::UnicodeString CaptionText = {read=GetCaptionText};
	__property System::Uitypes::TColor DetailsSeparatorColor = {read=GetDetailsSeparatorColor, nodefault};
	__property int DetailsSeparatorThickness = {read=GetDetailsSeparatorThickness, nodefault};
	__property System::Uitypes::TColor ExpandButtonColor = {read=GetExpandButtonColor, nodefault};
	__property int ExpandButtonSize = {read=GetExpandButtonSize, nodefault};
	__property Cxgridlevel::TcxGridLevel* GridLevel = {read=GetGridLevel};
	__property int GridWidth = {read=GetGridWidth, nodefault};
	__property bool FilterActive = {read=GetFilterActive, nodefault};
	__property bool FilterEmpty = {read=GetFilterEmpty, nodefault};
	__property Cxgridcustomtableview::TcxGridFilterPosition FilterPosition = {read=GetFilterPosition, nodefault};
	__property System::UnicodeString FilterText = {read=GetFilterText};
	__property bool HasDetailsSeparator = {read=GetHasDetailsSeparator, nodefault};
	__property bool HasSelectedRecords = {read=GetHasSelectedRecords, nodefault};
	__property int IndentCount = {read=GetIndentCount, nodefault};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property bool IsDetail = {read=GetIsDetail, nodefault};
	__property bool IsMaster = {read=GetIsMaster, nodefault};
	__property bool IsOffice11StyleGrouping = {read=GetIsOffice11StyleGrouping, nodefault};
	__property TdxCustomGridViewAdapter* MasterAdapter = {read=FMasterAdapter};
	__property Cxgridlevel::TcxGridLevel* MasterGridLevel = {read=GetMasterGridLevel};
	__property Cxgridcustomtableview::TcxCustomGridRecord* MasterGridRecord = {read=GetMasterGridRecord};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property System::Uitypes::TColor ThemedCaptionColor = {read=GetThemedCaptionColor, nodefault};
	__property System::Uitypes::TColor ThemedCaptionTextColor = {read=GetThemedCaptionTextColor, nodefault};
	__property System::Uitypes::TColor ThemedFilterBarColor = {read=GetThemedFilterBarColor, nodefault};
	__property System::Uitypes::TColor ThemedFilterBarTextColor = {read=GetThemedFilterBarTextColor, nodefault};
	__property int ViewWidth = {read=GetViewWidth, nodefault};
	__property int ViewWidthExtra = {read=GetViewWidthExtra, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomGridViewAdapter(void) { }
	
};


typedef System::TMetaClass* TdxGridViewFormatterClass;

class DELPHICLASS TdxCustomGridViewFormatter;
class DELPHICLASS TdxGridReportLink;
class PASCALIMPLEMENTATION TdxCustomGridViewFormatter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomGridViewBuilder* FBuilder;
	int FCaptionLineHeight;
	System::Classes::TList* FExpandButtons;
	int FFilterBarLineHeight;
	Vcl::Graphics::TFont* FFont;
	System::Classes::TList* FLookAndFeelItems;
	System::Uitypes::TColor FTransparentColor;
	int __fastcall GetAbsoluteLevel(void);
	bool __fastcall GetAutoWidth(void);
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetCanvas(void);
	Dxpscore::TdxCellEdgeMode __fastcall GetEdgeMode(void);
	Cxgridcustomtableview::TcxGridFilterPosition __fastcall GetFilterBarPosition(void);
	int __fastcall GetGridWidth(void);
	Dxpscore::TdxReportCellExpandButton* __fastcall GetExpandButton(int Index);
	int __fastcall GetExpandButtonCount(void);
	int __fastcall GetIndentWidth(void);
	Dxpscore::TdxReportVisualItem* __fastcall GetLookAndFeelItem(int Index);
	int __fastcall GetLookAndFeelItemCount(void);
	bool __fastcall GetPaginateByTopLevelGroups(void);
	Dxpscore::TdxPSReportRenderer* __fastcall GetRenderer(void);
	TdxGridReportLink* __fastcall GetReportLink(void);
	bool __fastcall GetShowCaption(void);
	bool __fastcall GetShowFilterBar(void);
	bool __fastcall GetUseLookAndFeelColors(void);
	int __fastcall GetViewAvailableWidth(void);
	int __fastcall GetViewWidthExtra(void);
	void __fastcall FormatLookAndFeelItems(void);
	void __fastcall FormatExpandButtons(void);
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual void __fastcall AddDelimiters(void);
	virtual void __fastcall AddHorizontalDelimiters(void);
	virtual void __fastcall AddVerticalDelimiters(void);
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateLineHeights(void);
	virtual System::Uitypes::TColor __fastcall GetDetailsSeparatorColor(void);
	virtual int __fastcall GetDetailsSeparatorThickness(void);
	virtual bool __fastcall GetHasDetailsSeparator(void);
	virtual int __fastcall GetSiteHeight(void);
	virtual int __fastcall GetSiteWidth(void);
	virtual int __fastcall GetViewWidth(void);
	virtual int __fastcall GetViewWidthExtraAfter(void);
	virtual int __fastcall GetViewWidthExtraBefore(void);
	virtual Cxgridcustomview::TcxCustomGridBackgroundBitmaps* __fastcall BackgroundBitmaps(void)/* overload */;
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(int Index);
	int __fastcall GetBackgroundBitmapIndex(int Index);
	virtual bool __fastcall HasBackgroundBitmap(int Index);
	virtual int __fastcall MapStyleBackgroundBitmapIndex(int AGridBackgroundBitmapIndex);
	int __fastcall CalculateFontHeight(const Dxpscxcommon::TdxReportItemViewParams &AParams);
	void __fastcall CalculateHeight(const Dxpscxcommon::TdxReportItemViewParams &AParams, int &AHeight);
	int __fastcall GetStyleFontIndex(const Dxpscxcommon::TdxReportItemViewParams &AParams);
	bool __fastcall IsColorTransparent(System::Uitypes::TColor AColor);
	void __fastcall RegisterExpandButton(Dxpscore::TdxReportCellExpandButton* AExpandButton);
	void __fastcall RegisterLookAndFeelItem(Dxpscore::TdxReportVisualItem* AnItem, Dxpscore::TdxCellEdgeStyle AEdgeStyle);
	void __fastcall SetViewParams(Dxpscore::TdxReportVisualItem* AnItem, Cxgraphics::TcxGridLines AGridLines, const Cxgraphics::TcxViewParams &AParams)/* overload */;
	void __fastcall SetViewParams(Dxpscore::TdxReportVisualItem* AnItem, const Dxpscxcommon::TdxReportItemViewParams &AParams)/* overload */;
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* Canvas = {read=GetCanvas};
	__property Dxpscore::TdxCellEdgeMode EdgeMode = {read=GetEdgeMode, nodefault};
	__property int ExpandButtonCount = {read=GetExpandButtonCount, nodefault};
	__property Dxpscore::TdxReportCellExpandButton* ExpandButtons[int Index] = {read=GetExpandButton};
	__property int GridWidth = {read=GetGridWidth, nodefault};
	__property int LookAndFeelItemCount = {read=GetLookAndFeelItemCount, nodefault};
	__property Dxpscore::TdxReportVisualItem* LookAndFeelItems[int Index] = {read=GetLookAndFeelItem};
	__property bool PaginateByTopLevelGroups = {read=GetPaginateByTopLevelGroups, nodefault};
	__property Dxpscore::TdxPSReportRenderer* Renderer = {read=GetRenderer};
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	__property int SiteHeight = {read=GetSiteHeight, nodefault};
	__property int SiteWidth = {read=GetSiteWidth, nodefault};
	
public:
	__fastcall virtual TdxCustomGridViewFormatter(TdxCustomGridViewBuilder* ABuilder);
	__fastcall virtual ~TdxCustomGridViewFormatter(void);
	virtual TdxCustomGridViewAdapter* __fastcall Adapter(void)/* overload */;
	virtual TdxCustomGridViewBuilder* __fastcall Builder(void)/* overload */;
	virtual void __fastcall DoInitializeHost(Dxpscore::TdxReportCell* AHost);
	virtual Dxpscore::TdxReportCellClass __fastcall GetHostClass(void);
	virtual Dxpscore::TdxReportCellClass __fastcall GetRowHostClass(void);
	virtual void __fastcall DoInitializeCaption(Dxpscore::TdxReportCellText* ACaption);
	virtual void __fastcall DoInitializeCaptionRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoReportLinkInitializeCaption(Dxpscore::TdxReportCellText* ACaption);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetCaptionClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetCaptionViewParams(void);
	virtual void __fastcall DoInitializeFilterBar(Dxpscore::TdxReportCellText* AFilterBar);
	virtual void __fastcall DoInitializeFilterBarRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoReportLinkInitializeFilterBar(Dxpscore::TdxReportCellText* AFilterBar);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetFilterBarClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetFilterBarViewParams(void);
	virtual void __fastcall DoInitializeDetailsSeparatorRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoInitializeHorzDetailsSeparator(Dxpscore::TdxReportCellBox* ASeparator);
	virtual void __fastcall DoInitializeVertBottomDetailsSeparator(Dxpscore::TdxReportCellBox* ASeparator, TdxVerticalDetailsSeparatorKind ASeparatorKind);
	virtual void __fastcall DoInitializeVertDetailsSeparator(Dxpscore::TdxReportCellBox* ASeparator, TdxVerticalDetailsSeparatorKind ASeparatorKind);
	virtual void __fastcall DoInitializeVertTopDetailsSeparator(Dxpscore::TdxReportCellBox* ASeparator, TdxVerticalDetailsSeparatorKind ASeparatorKind);
	virtual Dxpscore::TdxReportCellBoxClass __fastcall GetDetailsSeparatorClass(void);
	void __fastcall DoInitializeExpandButton(Dxpscore::TdxReportCellExpandButton* AnExpandButton, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, bool AnIsMasterIndent);
	virtual void __fastcall DoInitializeMasterIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex, int AnIndentCount);
	virtual Dxpscore::TdxReportCellExpandButtonClass __fastcall GetMasterIndentClass(void);
	virtual void __fastcall DoInitializeViewTerminator(Dxpscore::TdxReportCellBox* ATerminator);
	__property int AbsoluteLevel = {read=GetAbsoluteLevel, nodefault};
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property int CaptionLineHeight = {read=FCaptionLineHeight, write=FCaptionLineHeight, nodefault};
	__property System::Uitypes::TColor DetailsSeparatorColor = {read=GetDetailsSeparatorColor, nodefault};
	__property int DetailsSeparatorThickness = {read=GetDetailsSeparatorThickness, nodefault};
	__property int FilterBarLineHeight = {read=FFilterBarLineHeight, write=FFilterBarLineHeight, nodefault};
	__property Cxgridcustomtableview::TcxGridFilterPosition FilterBarPosition = {read=GetFilterBarPosition, nodefault};
	__property bool HasDetailsSeparator = {read=GetHasDetailsSeparator, nodefault};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property bool ShowCaption = {read=GetShowCaption, nodefault};
	__property bool ShowFilterBar = {read=GetShowFilterBar, nodefault};
	__property System::Uitypes::TColor TransparentColor = {read=FTransparentColor, write=FTransparentColor, nodefault};
	__property bool UseLookAndFeelColors = {read=GetUseLookAndFeelColors, nodefault};
	__property int ViewAvailableWidth = {read=GetViewAvailableWidth, nodefault};
	__property int ViewWidth = {read=GetViewWidth, nodefault};
	__property int ViewWidthExtra = {read=GetViewWidthExtra, nodefault};
	__property int ViewWidthExtraAfter = {read=GetViewWidthExtraAfter, nodefault};
	__property int ViewWidthExtraBefore = {read=GetViewWidthExtraBefore, nodefault};
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};


typedef System::TMetaClass* TdxGridViewBuilderClass;

class DELPHICLASS TdxGridAttributeHostInfoServices;
class DELPHICLASS TdxGridViewCaptionProducer;
class DELPHICLASS TdxGridViewDetailsSeparatorProducer;
class DELPHICLASS TdxGridViewFilterBarProducer;
class DELPHICLASS TdxGridViewTerminatorProducer;
class PASCALIMPLEMENTATION TdxCustomGridViewBuilder : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
private:
	TdxCustomGridViewAdapter* FAdapter;
	TdxCustomGridViewBuilder* FDetailsBuilder;
	TdxCustomGridViewFormatter* FFormatter;
	Cxgridcustomview::TcxCustomGridView* FGridView;
	TdxCustomGridViewBuilder* FMasterBuilder;
	TdxProducerCache* FProducerCache;
	TdxGridReportLink* FReportLink;
	System::Classes::TList* FReportRows;
	TdxCustomGridViewBuilder* __fastcall GetAbsoluteBuilder(int AIndex);
	bool __fastcall GetAutoWidth(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetGridLevel(void);
	Cxgrid::TcxCustomGrid* __fastcall GetGrid(void);
	Dxpscore::TdxReportCell* __fastcall GetHost(void);
	TdxGridAttributeHostInfoServices* __fastcall GetHostInfoServices(void);
	Dxpscore::TdxReportCell* __fastcall GetReportRow(int Index);
	int __fastcall GetReportRowCount(void);
	TdxCustomGridViewBuilder* __fastcall GetRootBuilder(void);
	
protected:
	void __fastcall AddReportRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual void __fastcall DoBuild(void);
	virtual void __fastcall DoBuildViewBody(void);
	virtual void __fastcall DoBuildViewFooter(void);
	virtual void __fastcall DoBuildViewHeader(void);
	virtual int __fastcall GetViewAvailableWidth(void);
	virtual void __fastcall CreateCaption(void);
	virtual TdxGridViewCaptionProducer* __fastcall GetCaptionProducer(void);
	virtual TdxGridViewCaptionProducerClass __fastcall GetCaptionProducerClass(void);
	virtual void __fastcall CreateBottomDetailsSeparator(void);
	virtual void __fastcall CreateTopDetailsSeparator(void);
	virtual TdxGridViewDetailsSeparatorProducer* __fastcall GetDetailsBottomSeparatorProducer(void);
	virtual TdxGridViewDetailsSeparatorProducerClass __fastcall GetDetailsBottomSeparatorProducerClass(void);
	virtual TdxGridViewDetailsSeparatorProducer* __fastcall GetDetailsTopSeparatorProducer(void);
	virtual TdxGridViewDetailsSeparatorProducerClass __fastcall GetDetailsTopSeparatorProducerClass(void);
	virtual void __fastcall CreateFilterBar(void);
	virtual TdxGridViewFilterBarProducer* __fastcall GetFilterBarProducer(void);
	virtual TdxGridViewFilterBarProducerClass __fastcall GetFilterBarProducerClass(void);
	virtual void __fastcall CreateViewTerminator(void);
	virtual TdxGridViewTerminatorProducer* __fastcall GetViewTerminatorProducer(void);
	virtual TdxGridViewTerminatorProducerClass __fastcall GetViewTerminatorProducerClass(void);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	__property Cxgridlevel::TcxGridLevel* GridLevel = {read=GetGridLevel};
	__property TdxGridAttributeHostInfoServices* HostInfoServices = {read=GetHostInfoServices};
	__property TdxProducerCache* ProducerCache = {read=FProducerCache};
	__property TdxGridReportLink* ReportLink = {read=FReportLink};
	
public:
	__fastcall virtual TdxCustomGridViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TdxCustomGridViewBuilder(void);
	virtual TdxCustomGridViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
	__classmethod virtual TdxCustomGridViewAdapter* __fastcall CreateAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual TdxCustomGridViewFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TdxGridViewFormatterClass __fastcall FormatterClass();
	void __fastcall Build(void);
	bool __fastcall IsAborted(void);
	void __fastcall Progress(const double APercentDone);
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__property TdxCustomGridViewBuilder* AbsoluteBuilders[int Index] = {read=GetAbsoluteBuilder};
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property TdxCustomGridViewBuilder* DetailsBuilder = {read=FDetailsBuilder};
	__property Cxgrid::TcxCustomGrid* Grid = {read=GetGrid};
	__property Dxpscore::TdxReportCell* Host = {read=GetHost};
	__property TdxCustomGridViewBuilder* MasterBuilder = {read=FMasterBuilder};
	__property int ReportRowCount = {read=GetReportRowCount, nodefault};
	__property Dxpscore::TdxReportCell* ReportRows[int Index] = {read=GetReportRow};
	__property TdxCustomGridViewBuilder* RootBuilder = {read=GetRootBuilder};
	__property int ViewAvailableWidth = {read=GetViewAvailableWidth, nodefault};
};


typedef void __fastcall (__closure *TdxGridTableAdapterForEachRecordProc)(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AData, bool &AContinue);

class PASCALIMPLEMENTATION TdxCustomGridTableViewAdapter : public TdxCustomGridViewAdapter
{
	typedef TdxCustomGridViewAdapter inherited;
	
private:
	int FDetailsLineCount;
	TdxRecordHelpersCache* FRecordHelpersCache;
	bool __fastcall GetCellEndEllipsis(void);
	int __fastcall GetDetailsLineCount(void);
	Cxgridcustomtableview::TcxCustomGridTableFiltering* __fastcall GetFiltering(void);
	bool __fastcall GetIsGridMode(void);
	Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetRecord(int Index);
	TdxCustomGridRecordHelper* __fastcall GetRecordHelper(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetSelectedRecord(int Index);
	int __fastcall GetSelectedRecordCount(void);
	
protected:
	virtual int __fastcall CalculateDetailsLineCount(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, bool AIsDataCell = false);
	virtual Cxgraphics::TcxViewParams __fastcall GetPreviewViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem);
	virtual Cxgraphics::TcxViewParams __fastcall GetSelectionViewParams(void);
	bool __fastcall HasSelectionStyle(void);
	HIDESBASE Cxgridcustomtableview::TcxCustomGridTableController* __fastcall Controller(void)/* overload */;
	void __fastcall DoExpandMasterRow(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AData, bool &AContinue);
	virtual void __fastcall ExpandAllGroupRows(void);
	virtual void __fastcall ExpandAllMasterRows(bool AnExpandGroups);
	virtual void __fastcall ExpandAllRowsInItself(bool AMasterRows, bool AGroupRows);
	virtual bool __fastcall GetAreAllMasterRowsCollapsed(void);
	virtual bool __fastcall GetCanUseOnEveryPageMode(void);
	virtual bool __fastcall GetCellAutoHeight(void);
	virtual bool __fastcall GetCellMultiline(void);
	virtual Cxgridcustomtableview::TcxGridFilterPosition __fastcall GetFilterPosition(void);
	virtual System::Uitypes::TColor __fastcall GetGridLineColor(void);
	virtual bool __fastcall GetHasSelectedRecords(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetMasterGridRecord(void);
	virtual int __fastcall GetRecordCount(void);
	void __fastcall IsMasterRowCollapsed(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AData, bool &AContinue);
	__classmethod virtual Cxedit::TcxCustomEditProperties* __fastcall GetProperties(Cxgridcustomtableview::TcxCustomGridTableItem* AnItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(Cxgridcustomtableview::TcxCustomGridTableItem* AnItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__classmethod virtual Cxedit::TcxEditRepositoryItem* __fastcall GetRepositoryItem(Cxgridcustomtableview::TcxCustomGridTableItem* AnItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__property TdxRecordHelpersCache* RecordHelpersCache = {read=FRecordHelpersCache};
	
public:
	__fastcall virtual TdxCustomGridTableViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TdxCustomGridTableViewAdapter(void);
	bool __fastcall ForEachRecord(TdxGridTableAdapterForEachRecordProc AProc, int AData, bool AProcessSelection);
	HIDESBASE Cxgridcustomtableview::TcxCustomGridTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	HIDESBASE Cxgridcustomtableview::TcxCustomGridTableViewStyles* __fastcall Styles(void)/* overload */;
	__property bool CellAutoHeight = {read=GetCellAutoHeight, nodefault};
	__property bool CellEndEllipsis = {read=GetCellEndEllipsis, nodefault};
	__property bool CellMultiline = {read=GetCellMultiline, nodefault};
	__property int DetailsLineCount = {read=GetDetailsLineCount, write=FDetailsLineCount, nodefault};
	__property Cxgridcustomtableview::TcxCustomGridTableFiltering* Filtering = {read=GetFiltering};
	__property System::Uitypes::TColor GridLineColor = {read=GetGridLineColor, nodefault};
	__property bool IsGridMode = {read=GetIsGridMode, nodefault};
	__property TdxCustomGridRecordHelper* RecordHelpers[Cxgridcustomtableview::TcxCustomGridRecord* Row] = {read=GetRecordHelper};
	__property Cxgridcustomtableview::TcxCustomGridRecord* Records[int Index] = {read=GetRecord};
	__property int SelectedRecordCount = {read=GetSelectedRecordCount, nodefault};
	__property Cxgridcustomtableview::TcxCustomGridRecord* SelectedRecords[int Index] = {read=GetSelectedRecord};
};


class DELPHICLASS TdxCustomGridTableViewFormatter;
class DELPHICLASS TdxCustomGridTableViewBuilder;
class PASCALIMPLEMENTATION TdxCustomGridTableViewFormatter : public TdxCustomGridViewFormatter
{
	typedef TdxCustomGridViewFormatter inherited;
	
private:
	System::Classes::TList* FRecordIndexes;
	System::Classes::TList* FSelectedRecordList;
	System::Uitypes::TColor __fastcall GetGridLineColor(void);
	Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetRecord(int Index);
	int __fastcall GetRecordCount(void);
	int __fastcall GetRecordIndex(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetSelectedRecord(int Index);
	int __fastcall GetSelectedRecordCount(void);
	
protected:
	virtual bool __fastcall IdxPSCellParams_GetAutoHeight(void);
	virtual Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall IdxPSCellParams_GetCanvas(void);
	virtual bool __fastcall IdxPSCellParams_GetDisplayGraphicsAsText(void);
	virtual bool __fastcall IdxPSCellParams_GetEndEllipsis(void);
	virtual bool __fastcall IdxPSCellParams_GetFlatCheckMarks(void);
	virtual System::UnicodeString __fastcall IdxPSCellParams_GetGraphicsText(void);
	virtual bool __fastcall IdxPSCellParams_GetMultiline(void);
	virtual bool __fastcall IdxPSCellParams_GetTransparentGraphics(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMarginLeft(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMarginRight(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMaxHeight(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMaxLineCount(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall IdxPSCellParams2_GetRichEditGraphicClass(void);
	virtual bool __fastcall IdxPSCellParams2_GetRichEditTransparent(void);
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual void __fastcall BuildSelectedRecordList(void);
	bool __fastcall CanProcessSelectionStyle(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual bool __fastcall IsSelectedRecord(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual int __fastcall GetContentBackgroundBitmapStyleIndex(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem);
	virtual int __fastcall MapStyleBackgroundBitmapIndex(int AGridBackgroundBitmapIndex);
	__property System::Classes::TList* SelectedRecordList = {read=FSelectedRecordList};
	
public:
	__fastcall virtual TdxCustomGridTableViewFormatter(TdxCustomGridViewBuilder* ABuilder);
	__fastcall virtual ~TdxCustomGridTableViewFormatter(void);
	HIDESBASE TdxCustomGridTableViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxCustomGridTableViewBuilder* __fastcall Builder(void)/* overload */;
	int __fastcall IndexOfRecord(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	void __fastcall CheckDisplayValuePost(Cxedit::TcxCustomEditProperties* AProperties, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Dxpscore::TAbstractdxReportCellData* AnItem);
	virtual void __fastcall DoInitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, bool AnIsPreview = false);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetItemClass(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, bool AnIsPreview = false);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetItemProperties(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual System::Variant __fastcall GetItemValue(Cxedit::TcxCustomEditProperties* AProperties, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetItemViewParams(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, bool AnIsPreview = false, bool AIsDataCell = false);
	Dxpscxcommon::TdxReportItemViewParams __fastcall GetSelectionViewParams(void);
	__property System::Uitypes::TColor GridLineColor = {read=GetGridLineColor, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property int RecordIndexes[Cxgridcustomtableview::TcxCustomGridRecord* ARecord] = {read=GetRecordIndex};
	__property Cxgridcustomtableview::TcxCustomGridRecord* Records[int Index] = {read=GetRecord};
	__property int SelectedRecordCount = {read=GetSelectedRecordCount, nodefault};
	__property Cxgridcustomtableview::TcxCustomGridRecord* SelectedRecords[int Index] = {read=GetSelectedRecord};
private:
	void *__IdxPSCellParams2;	/* Dxpscxcommon::IdxPSCellParams2 */
	void *__IdxPSCellParams;	/* Dxpscxcommon::IdxPSCellParams */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {09EAB051-1AC2-46FB-A7F4-D6BFA883D015}
	operator Dxpscxcommon::_di_IdxPSCellParams2()
	{
		Dxpscxcommon::_di_IdxPSCellParams2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscxcommon::IdxPSCellParams2*(void) { return (Dxpscxcommon::IdxPSCellParams2*)&__IdxPSCellParams2; }
	#endif
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


class PASCALIMPLEMENTATION TdxCustomGridTableViewBuilder : public TdxCustomGridViewBuilder
{
	typedef TdxCustomGridViewBuilder inherited;
	
protected:
	virtual void __fastcall DoBuildViewFooter(void);
	virtual void __fastcall DoBuildViewHeader(void);
	void __fastcall DoGetCellHeight(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, int &AHeight);
	HIDESBASE Cxgridcustomtableview::TcxCustomGridTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	
public:
	HIDESBASE TdxCustomGridTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
	HIDESBASE TdxCustomGridTableViewFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TdxGridViewFormatterClass __fastcall FormatterClass();
public:
	/* TdxCustomGridViewBuilder.Create */ inline __fastcall virtual TdxCustomGridTableViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxCustomGridViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxCustomGridViewBuilder.Destroy */ inline __fastcall virtual ~TdxCustomGridTableViewBuilder(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridTableViewAdapter : public TdxCustomGridTableViewAdapter
{
	typedef TdxCustomGridTableViewAdapter inherited;
	
private:
	Cxgridtableview::TcxGridColumn* __fastcall GetColumn(int Index);
	int __fastcall GetColumnCount(void);
	System::UnicodeString __fastcall GetFooterItemText(int Index);
	bool __fastcall GetFooterMultiline(void);
	bool __fastcall GetFooterMultiSummaries(void);
	Cxgraphics::TcxGridLines __fastcall GetGridLines(void);
	bool __fastcall GetGroupFooterMultiSummaries(void);
	Cxgridtableview::TcxGridColumn* __fastcall GetGroupedColumn(int Index);
	int __fastcall GetGroupedColumnCount(void);
	Cxgridtableview::TcxGridGroupFootersMode __fastcall GetGroupFootersMode(void);
	bool __fastcall GetGroupFootersMultiline(void);
	System::Uitypes::TColor __fastcall GetGroupRowSeparatorColor(void);
	int __fastcall GetGroupRowSeparatorThickness(void);
	bool __fastcall GetHasFooterItem(int Index);
	bool __fastcall GetHasPreview(void);
	bool __fastcall GetHasRowSeparators(void);
	bool __fastcall GetHeaderEndEllipsis(void);
	int __fastcall GetInternalColumnMinWidth(Cxgridtableview::TcxGridColumn* Column);
	int __fastcall GetInternalColumnWidth(Cxgridtableview::TcxGridColumn* Column);
	Cxgridtableview::TcxGridColumn* __fastcall GetPreviewColumn(void);
	int __fastcall GetPreviewLeftIndent(void);
	Cxgridtableview::TcxGridPreviewPlace __fastcall GetPreviewPlace(void);
	int __fastcall GetPreviewRightIndent(void);
	Cxgridtableview::TcxCustomGridRow* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	System::Uitypes::TColor __fastcall GetRowSeparatorColor(void);
	int __fastcall GetRowSeparatorThickness(void);
	bool __fastcall GetShowExpandButtonsForEmptyDetails(void);
	bool __fastcall GetShowHorzGridLines(void);
	bool __fastcall GetShowVertGridLines(void);
	System::Uitypes::TColor __fastcall GetThemedFooterItemColor(void);
	System::Uitypes::TColor __fastcall GetThemedFooterItemTextColor(void);
	System::Uitypes::TColor __fastcall GetThemedHeaderItemColor(void);
	System::Uitypes::TColor __fastcall GetThemedHeaderItemTextColor(void);
	
protected:
	HIDESBASE Cxgridtableview::TcxGridTableController* __fastcall Controller(void)/* overload */;
	HIDESBASE Cxgridcustomtableview::TcxGridDataController* __fastcall DataController(void)/* overload */;
	virtual bool __fastcall GetAutoWidth(void);
	virtual bool __fastcall GetCellAutoHeight(void);
	virtual bool __fastcall GetCellMultiline(void);
	virtual System::Uitypes::TColor __fastcall GetGridLineColor(void);
	virtual bool __fastcall GetHeaderAutoHeight(void);
	virtual bool __fastcall GetHeaderMultiline(Cxgridtableview::TcxGridColumn* Column);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetIndentWidth(void);
	virtual int __fastcall GetIndicatorWidth(void);
	virtual bool __fastcall GetIsOffice11StyleGrouping(void);
	virtual int __fastcall GetViewWidthExtra(void);
	virtual int __fastcall GetDataRowHeight(void);
	virtual bool __fastcall GetDataRowHeightAssigned(void);
	virtual int __fastcall GetFooterHeight(void);
	virtual bool __fastcall GetFooterHeightAssigned(void);
	virtual int __fastcall GetGroupFooterHeight(void);
	virtual bool __fastcall GetGroupFooterHeightAssigned(void);
	virtual int __fastcall GetGroupRowHeight(void);
	virtual bool __fastcall GetGroupRowHeightAssigned(void);
	virtual int __fastcall GetHeaderHeight(void);
	virtual bool __fastcall GetHeaderHeightAssigned(void);
	virtual int __fastcall GetRowLineCount(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetFilterBarViewParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetFooterViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel, Cxgridtableview::TcxGridColumn* AColumn, Cxcustomdata::TcxDataSummaryItem* AItem);
	virtual Cxgraphics::TcxViewParams __fastcall GetGroupRowViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel);
	virtual Cxgraphics::TcxViewParams __fastcall GetHeaderViewParams(Cxgridtableview::TcxGridColumn* AColumn);
	virtual Cxgraphics::TcxViewParams __fastcall GetPreviewViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AnItem);
	__property int InternalColumnMinWidths[Cxgridtableview::TcxGridColumn* Column] = {read=GetInternalColumnMinWidth};
	__property int InternalColumnWidths[Cxgridtableview::TcxGridColumn* Column] = {read=GetInternalColumnWidth};
	
public:
	__fastcall virtual TdxGridTableViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView);
	HIDESBASE Cxgridtableview::TcxGridTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	HIDESBASE Cxgridtableview::TcxGridTableViewStyles* __fastcall Styles(void)/* overload */;
	bool __fastcall HasDetails(Cxgridtableview::TcxCustomGridRow* AGridRow);
	bool __fastcall IsSummaryHasSameLink(Cxcustomdata::TcxDataSummaryItem* AItem1, Cxcustomdata::TcxDataSummaryItem* AItem2);
	int __fastcall CheckSummaryItemIndex(Cxcustomdata::TcxDataSummaryItems* AItems, int AIndex, bool AIsGroup);
	int __fastcall GetFooterItemCount(Cxcustomdata::TcxDataSummaryItems* AItems, bool ACanMultiLine, bool AIsGroup);
	int __fastcall GetFooterItemInfo(Cxcustomdata::TcxDataSummaryItems* AItems, int AIndex, int &ARowIndex);
	int __fastcall GetFooterLineCount(Cxcustomdata::TcxDataSummaryItems* AItems, bool ACanMultiLine);
	int __fastcall GetGroupFooterCount(Cxgridtableview::TcxCustomGridRow* AGridRow);
	System::UnicodeString __fastcall GetGroupFooterItemText(int ARowIndex, int ALevel, int AIndex);
	bool __fastcall HasGroupFooter(Cxgridtableview::TcxCustomGridRow* AGridRow, int ALevel);
	bool __fastcall HasGroupFooterItem(int ALevel, int AIndex);
	bool __fastcall HasGroupFooters(Cxgridtableview::TcxCustomGridRow* AGridRow);
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property Cxgridtableview::TcxGridColumn* Columns[int Index] = {read=GetColumn};
	__property int DataRowHeight = {read=GetDataRowHeight, nodefault};
	__property bool DataRowHeightAssigned = {read=GetDataRowHeightAssigned, nodefault};
	__property int FooterHeight = {read=GetFooterHeight, nodefault};
	__property bool FooterHeightAssigned = {read=GetFooterHeightAssigned, nodefault};
	__property System::UnicodeString FooterItemTexts[int Index] = {read=GetFooterItemText};
	__property bool FooterMultiSummaries = {read=GetFooterMultiSummaries, nodefault};
	__property bool FooterMultiline = {read=GetFooterMultiline, nodefault};
	__property Cxgraphics::TcxGridLines GridLines = {read=GetGridLines, nodefault};
	__property int GroupedColumnCount = {read=GetGroupedColumnCount, nodefault};
	__property Cxgridtableview::TcxGridColumn* GroupedColumns[int Index] = {read=GetGroupedColumn};
	__property int GroupFooterHeight = {read=GetGroupFooterHeight, nodefault};
	__property bool GroupFooterHeightAssigned = {read=GetGroupFooterHeightAssigned, nodefault};
	__property bool GroupFooterMultiSummaries = {read=GetGroupFooterMultiSummaries, nodefault};
	__property Cxgridtableview::TcxGridGroupFootersMode GroupFootersMode = {read=GetGroupFootersMode, nodefault};
	__property bool GroupFootersMultiline = {read=GetGroupFootersMultiline, nodefault};
	__property int GroupRowHeight = {read=GetGroupRowHeight, nodefault};
	__property bool GroupRowHeightAssigned = {read=GetGroupRowHeightAssigned, nodefault};
	__property System::Uitypes::TColor GroupRowSeparatorColor = {read=GetGroupRowSeparatorColor, nodefault};
	__property int GroupRowSeparatorThickness = {read=GetGroupRowSeparatorThickness, nodefault};
	__property bool HasFooterItem[int Index] = {read=GetHasFooterItem};
	__property bool HasPreview = {read=GetHasPreview, nodefault};
	__property bool HasRowSeparators = {read=GetHasRowSeparators, nodefault};
	__property bool HeaderAutoHeight = {read=GetHeaderAutoHeight, nodefault};
	__property bool HeaderEndEllipsis = {read=GetHeaderEndEllipsis, nodefault};
	__property int HeaderHeight = {read=GetHeaderHeight, nodefault};
	__property bool HeaderHeightAssigned = {read=GetHeaderHeightAssigned, nodefault};
	__property bool HeaderMultilines[Cxgridtableview::TcxGridColumn* Column] = {read=GetHeaderMultiline};
	__property int IndicatorWidth = {read=GetIndicatorWidth, nodefault};
	__property Cxgridtableview::TcxGridColumn* PreviewColumn = {read=GetPreviewColumn};
	__property int PreviewLeftIndent = {read=GetPreviewLeftIndent, nodefault};
	__property Cxgridtableview::TcxGridPreviewPlace PreviewPlace = {read=GetPreviewPlace, nodefault};
	__property int PreviewRightIndent = {read=GetPreviewRightIndent, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowLineCount = {read=GetRowLineCount, nodefault};
	__property Cxgridtableview::TcxCustomGridRow* Rows[int Index] = {read=GetRow};
	__property System::Uitypes::TColor RowSeparatorColor = {read=GetRowSeparatorColor, nodefault};
	__property int RowSeparatorThickness = {read=GetRowSeparatorThickness, nodefault};
	__property bool ShowExpandButtonsForEmptyDetails = {read=GetShowExpandButtonsForEmptyDetails, nodefault};
	__property bool ShowHorzGridLines = {read=GetShowHorzGridLines, nodefault};
	__property bool ShowVertGridLines = {read=GetShowVertGridLines, nodefault};
	__property System::Uitypes::TColor ThemedFooterItemColor = {read=GetThemedFooterItemColor, nodefault};
	__property System::Uitypes::TColor ThemedFooterItemTextColor = {read=GetThemedFooterItemTextColor, nodefault};
	__property System::Uitypes::TColor ThemedHeaderItemColor = {read=GetThemedHeaderItemColor, nodefault};
	__property System::Uitypes::TColor ThemedHeaderItemTextColor = {read=GetThemedHeaderItemTextColor, nodefault};
public:
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridTableViewAdapter(void) { }
	
};


typedef System::TMetaClass* TdxCustomGridTableViewItemPlaceControllerClass;

class DELPHICLASS TdxCustomGridTableViewItemPlaceController;
class DELPHICLASS TdxGridTableViewFormatter;
class DELPHICLASS TdxGridTableViewColumnPlace;
class PASCALIMPLEMENTATION TdxCustomGridTableViewItemPlaceController : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxGridTableViewColumnPlace* operator[](Cxgridtableview::TcxGridColumn* Column) { return ItemsByColumn[Column]; }
	
private:
	TdxGridTableViewFormatter* FFormatter;
	int FHeaderLineCount;
	int FWidth;
	int __fastcall GetHeaderLineCount(void);
	int __fastcall GetWidth(void);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual int __fastcall CalculateWidth(void);
	virtual int __fastcall CalculateHeaderLineCount(void);
	virtual TdxGridTableViewColumnPlace* __fastcall GetItemByColumn(Cxgridtableview::TcxGridColumn* Column);
	virtual void __fastcall WidthChanged(void);
	
public:
	__fastcall virtual TdxCustomGridTableViewItemPlaceController(TdxGridTableViewFormatter* AFormatter);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Refresh(void);
	__property TdxGridTableViewFormatter* Formatter = {read=FFormatter};
	__property int HeaderLineCount = {read=GetHeaderLineCount, nodefault};
	__property TdxGridTableViewColumnPlace* ItemsByColumn[Cxgridtableview::TcxGridColumn* Column] = {read=GetItemByColumn/*, default*/};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomGridTableViewItemPlaceController(void) { }
	
};


typedef System::TMetaClass* TdxGridTableViewColumnPlaceClass;

class DELPHICLASS TdxGridTableViewColumnPlaceController;
class PASCALIMPLEMENTATION TdxGridTableViewColumnPlace : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgridtableview::TcxGridColumn* FColumn;
	TdxGridTableViewColumnPlaceController* FController;
	int FLeftBound;
	int FWidth;
	TdxGridTableViewAdapter* __fastcall GetAdapter(void);
	System::Types::TRect __fastcall GetCellBounds(int RowIndex);
	int __fastcall GetCellHeight(int RowIndex);
	System::Types::TRect __fastcall GetFooterCellBounds(void);
	int __fastcall GetFooterLineHeight(void);
	TdxGridTableViewFormatter* __fastcall GetFormatter(void);
	System::Types::TRect __fastcall GetGroupFooterCellBounds(int IndentCount);
	int __fastcall GetGroupFooterLineHeight(void);
	System::Types::TRect __fastcall GetHeaderCellBounds(void);
	int __fastcall GetHeaderLineHeight(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsFixed(void);
	int __fastcall GetLeftBound(void);
	int __fastcall GetMinWidth(void);
	int __fastcall GetOriginalWidth(void);
	int __fastcall GetWidth(void);
	
protected:
	virtual int __fastcall CalculateLeftBound(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetRowIndex(void);
	virtual void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AnItem);
	__property TdxGridTableViewAdapter* Adapter = {read=GetAdapter};
	__property TdxGridTableViewFormatter* Formatter = {read=GetFormatter};
	__property bool IsFixed = {read=GetIsFixed, nodefault};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property int OriginalWidth = {read=GetOriginalWidth, nodefault};
	__property int RowIndex = {read=GetRowIndex, nodefault};
	
public:
	__fastcall virtual TdxGridTableViewColumnPlace(TdxGridTableViewColumnPlaceController* AController, Cxgridtableview::TcxGridColumn* AColumn);
	virtual void __fastcall Calculate(int ALeftBound);
	__property System::Types::TRect CellBounds[int RowIndex] = {read=GetCellBounds};
	__property int CellHeights[int RowIndex] = {read=GetCellHeight};
	__property Cxgridtableview::TcxGridColumn* Column = {read=FColumn};
	__property TdxGridTableViewColumnPlaceController* Controller = {read=FController};
	__property System::Types::TRect FooterCellBounds = {read=GetFooterCellBounds};
	__property int FooterLineHeight = {read=GetFooterLineHeight, nodefault};
	__property System::Types::TRect GroupFooterCellBounds[int IndentCount] = {read=GetGroupFooterCellBounds};
	__property int GroupFooterLineHeight = {read=GetGroupFooterLineHeight, nodefault};
	__property System::Types::TRect HeaderCellBounds = {read=GetHeaderCellBounds};
	__property int HeaderLineHeight = {read=GetHeaderLineHeight, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property int LeftBound = {read=GetLeftBound, write=FLeftBound, nodefault};
	__property int Width = {read=GetWidth, write=FWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridTableViewColumnPlace(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridTableViewColumnPlaceController : public TdxCustomGridTableViewItemPlaceController
{
	typedef TdxCustomGridTableViewItemPlaceController inherited;
	
public:
	TdxGridTableViewColumnPlace* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FColumnIndexes;
	System::Classes::TList* FItems;
	TdxGridTableViewAdapter* __fastcall GetAdapter(void);
	int __fastcall GetColumnIndex(Cxgridtableview::TcxGridColumn* Column);
	TdxGridTableViewColumnPlace* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	void __fastcall FreeAndNilItems(void);
	
protected:
	virtual int __fastcall CalculateWidth(void);
	virtual TdxGridTableViewColumnPlace* __fastcall GetItemByColumn(Cxgridtableview::TcxGridColumn* Column);
	virtual void __fastcall AddItems(void);
	void __fastcall ClearItems(void);
	virtual TdxGridTableViewColumnPlace* __fastcall CreateItem(Cxgridtableview::TcxGridColumn* AColumn);
	virtual TdxGridTableViewColumnPlaceClass __fastcall GetItemClass(Cxgridtableview::TcxGridColumn* AColumn);
	virtual int __fastcall CalculateItemLeftBound(TdxGridTableViewColumnPlace* AnItem);
	virtual void __fastcall CalculateItemsWidth(void);
	virtual bool __fastcall GetItemsAutoWidth(void);
	virtual int __fastcall GetItemsAvailableWidth(void);
	__property TdxGridTableViewAdapter* Adapter = {read=GetAdapter};
	__property bool ItemsAutoWidth = {read=GetItemsAutoWidth, nodefault};
	__property int ItemsAvailableWidth = {read=GetItemsAvailableWidth, nodefault};
	
public:
	__fastcall virtual TdxGridTableViewColumnPlaceController(TdxGridTableViewFormatter* AFormatter);
	__fastcall virtual ~TdxGridTableViewColumnPlaceController(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Refresh(void);
	int __fastcall IndexOf(TdxGridTableViewColumnPlace* AnItem)/* overload */;
	int __fastcall IndexOf(Cxgridtableview::TcxGridColumn* AColumn)/* overload */;
	__property int ColumnIndexes[Cxgridtableview::TcxGridColumn* Column] = {read=GetColumnIndex};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxGridTableViewColumnPlace* Items[int Index] = {read=GetItem/*, default*/};
};


class DELPHICLASS TdxGridTableViewReportDataAdapter;
class PASCALIMPLEMENTATION TdxGridTableViewReportDataAdapter : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Dxpscore::TdxReportCell* operator[](int Index) { return ReportRows[Index]; }
	
private:
	TdxCustomGridViewBuilder* FBuilder;
	Dxpscore::TdxReportVisualItem* __fastcall GetReportItem(Cxgridtableview::TcxCustomGridRow* Row, Cxgridtableview::TcxGridColumn* Column);
	Dxpscore::TdxReportCell* __fastcall GetReportRow(int Index);
	Dxpscore::TdxReportCell* __fastcall GetReportRowByGridRow(Cxgridtableview::TcxCustomGridRow* Row);
	int __fastcall GetReportRowCount(void);
	
public:
	__fastcall virtual TdxGridTableViewReportDataAdapter(TdxCustomGridViewBuilder* ABuilder);
	__property TdxCustomGridViewBuilder* Builder = {read=FBuilder};
	__property Dxpscore::TdxReportVisualItem* ReportItems[Cxgridtableview::TcxCustomGridRow* Row][Cxgridtableview::TcxGridColumn* Column] = {read=GetReportItem};
	__property int ReportRowCount = {read=GetReportRowCount, nodefault};
	__property Dxpscore::TdxReportCell* ReportRows[int Index] = {read=GetReportRow/*, default*/};
	__property Dxpscore::TdxReportCell* ReportRowsByGridRow[Cxgridtableview::TcxCustomGridRow* Row] = {read=GetReportRowByGridRow};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridTableViewReportDataAdapter(void) { }
	
};


class DELPHICLASS TdxGridTableViewBuilder;
class PASCALIMPLEMENTATION TdxGridTableViewFormatter : public TdxCustomGridTableViewFormatter
{
	typedef TdxCustomGridTableViewFormatter inherited;
	
private:
	System::Classes::TList* FColumns;
	int FDetailsLineHeight;
	int FFooterLineHeight;
	int FGroupFooterLineHeight;
	int FGroupRowLineHeight;
	int FHeaderLineHeight;
	TdxCustomGridTableViewItemPlaceController* FItemPlaceController;
	int FPreviewLineHeight;
	TdxGridTableViewReportDataAdapter* FReportDataAdapter;
	System::Classes::TList* FRowHeights;
	Cxgridtableview::TcxGridColumn* __fastcall GetColumn(int Index);
	int __fastcall GetColumnCount(void);
	System::Uitypes::TColor __fastcall GetGroupRowSeparatorColor(void);
	int __fastcall GetGroupRowSeparatorThickness(void);
	bool __fastcall GetHasPreview(void);
	int __fastcall GetHeaderLineCount(void);
	bool __fastcall GetPreviewAutoHeight(void);
	Cxgridtableview::TcxGridColumn* __fastcall GetPreviewColumn(void);
	int __fastcall GetPreviewMaxLineCount(void);
	Cxgridtableview::TcxCustomGridRow* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	int __fastcall GetRowHeight(int Index);
	int __fastcall GetRowHeightByRow(Cxgridtableview::TcxCustomGridRow* Row);
	System::Uitypes::TColor __fastcall GetRowSeparatorColor(void);
	int __fastcall GetRowSeparatorThickness(void);
	bool __fastcall GetShowGroupFooters(void);
	bool __fastcall GetShowFooters(void);
	bool __fastcall GetShowHeaders(void);
	bool __fastcall GetShowPreview(void);
	void __fastcall SetRowHeight(int Index, int Value);
	void __fastcall SetRowHeightByRow(Cxgridtableview::TcxCustomGridRow* Row, int Value);
	
protected:
	virtual int __fastcall IdxPSCellParams2_GetPreviewMarginLeft(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMarginRight(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMaxHeight(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMaxLineCount(void);
	virtual void __fastcall AddHorizontalDelimiters(void);
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateDataRowHeights(void);
	virtual void __fastcall CalculateLineHeights(void);
	virtual bool __fastcall GetAlignSummaryWithColumns(void);
	virtual TdxCustomGridTableViewItemPlaceControllerClass __fastcall GetItemPlaceControllerClass(void);
	virtual int __fastcall MapStyleBackgroundBitmapIndex(int AGridBackgroundBitmapIndex);
	virtual bool __fastcall CanCellMerging(void);
	virtual bool __fastcall CanColumnCellMerging(Cxgridtableview::TcxGridColumn* AColumn);
	virtual void __fastcall PerformCellMerging(void);
	virtual void __fastcall PerformColumnCellMerging(Cxgridtableview::TcxGridColumn* AColumn);
	virtual void __fastcall BuildColumnList(void);
	virtual void __fastcall BuildItemLists(void);
	virtual bool __fastcall IsColumnActuallyVisible(Cxgridtableview::TcxGridColumn* AColumn);
	virtual int __fastcall GetViewWidth(void);
	__property TdxCustomGridTableViewItemPlaceController* ItemPlaceController = {read=FItemPlaceController};
	__property TdxGridTableViewReportDataAdapter* ReportDataAdapter = {read=FReportDataAdapter};
	
public:
	__fastcall virtual TdxGridTableViewFormatter(TdxCustomGridViewBuilder* ABuilder);
	__fastcall virtual ~TdxGridTableViewFormatter(void);
	HIDESBASE TdxGridTableViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridTableViewBuilder* __fastcall Builder(void)/* overload */;
	virtual void __fastcall DoInitializeFooterItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex, Cxcustomdata::TcxDataSummaryItem* AItem);
	virtual void __fastcall DoInitializeFooterRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoReportLinkInitializeFooterItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual System::Types::TRect __fastcall GetFooterItemBounds(int AnIndex);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetFooterItemClass(int AnIndex);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetFooterItemViewParams(Cxgridtableview::TcxGridColumn* AColumn, Cxcustomdata::TcxDataSummaryItem* AItem);
	virtual void __fastcall DoInitializeGroupFooterHost(Dxpscore::TdxReportVisualItem* AnItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel);
	virtual void __fastcall DoInitializeGroupFooterItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel, const System::Variant &AValue, Cxcustomdata::TcxDataSummaryItem* AItem);
	virtual void __fastcall DoInitializeGroupFooterRow(Dxpscore::TdxReportCell* ARow, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel);
	virtual void __fastcall DoReportLinkInitializeGroupFooterItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxgridtableview::TcxGridColumn* AColumn, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetGroupFooterItemClass(int AnIndex);
	virtual System::Types::TRect __fastcall GetGroupFooterItemBounds(int AnIndex, int AGroupLevel);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetGroupFooterItemViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel, Cxgridtableview::TcxGridColumn* AColumn, Cxcustomdata::TcxDataSummaryItem* AItem);
	virtual void __fastcall DoInitializeGroupRowItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxgridtableview::TcxGridGroupRow* ARow, int AIndex, const System::UnicodeString AText);
	virtual void __fastcall DoInitializeGroupRow(Dxpscore::TdxReportCell* ARow, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetGroupRowClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetGroupRowViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int ALevel);
	virtual void __fastcall DoInitializeGroupRowSeparator(Dxpscore::TAbstractdxReportCellData* ASeparator);
	virtual void __fastcall DoInitializeGroupSeparatorRow(Dxpscore::TdxReportCell* ARow);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetGroupRowSeparatorClass(void);
	virtual void __fastcall DoInitializeHeaderItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual void __fastcall DoInitializeHeaderRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoReportLinkInitializeHeaderItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual System::Types::TRect __fastcall GetHeaderItemBounds(int AnIndex);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetHeaderItemClass(int AnIndex);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetHeaderItemViewParams(Cxgridtableview::TcxGridColumn* AColumn);
	virtual Dxpscore::TdxReportCellExpandButton* __fastcall CreateIndent(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall DoInitializeDataRowIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex, int AnIndentCount, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoInitializeGroupFooterIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex, int AnIndentCount, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoInitializeGroupRowIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex, int AnIndentCount, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoInitializeMasterDataRowIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex, int AnIndentCount, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoInitializeRowSeparatorIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex, int AnIndentCount, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Dxpscore::TdxReportCellExpandButtonClass __fastcall GetIndentClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetIndentViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AnIndex, int AnIndentCount, bool ANonRecordIndent);
	virtual bool __fastcall HasExpandButton(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoInitializeDataRow(Dxpscore::TdxReportCell* ARow, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoReportLinkInitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxgridtableview::TcxGridColumn* AColumn, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual System::Types::TRect __fastcall GetItemBounds(Cxgridtableview::TcxCustomGridRow* AGridRow, int AGridRowIndex, int AColumnIndex);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetItemViewParams(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, bool AnIsPreview = false, bool AIsDataCell = false);
	virtual void __fastcall DoInitializeMasterIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex, int AnIndentCount);
	virtual void __fastcall DoInitializePreview(Dxpscore::TAbstractdxReportCellData* APreview, Cxgridtableview::TcxGridColumn* AColumn, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetPreviewClass(Cxgridtableview::TcxGridColumn* AColumn, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetPreviewViewParams(Cxgridtableview::TcxGridColumn* AColumn, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoInitializeSeparatorRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoInitializeRowSeparator(Dxpscore::TAbstractdxReportCellData* ASeparator);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetRowSeparatorClass(void);
	Dxpscore::TdxReportVisualItem* __fastcall GetReportItem(Cxgridtableview::TcxCustomGridRow* ARow, Cxgridtableview::TcxGridColumn* AColumn);
	__property bool AlignSummaryWithColumns = {read=GetAlignSummaryWithColumns, nodefault};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property Cxgridtableview::TcxGridColumn* Columns[int Index] = {read=GetColumn};
	__property int DetailsLineHeight = {read=FDetailsLineHeight, write=FDetailsLineHeight, nodefault};
	__property int FooterLineHeight = {read=FFooterLineHeight, write=FFooterLineHeight, nodefault};
	__property int GroupFooterLineHeight = {read=FGroupFooterLineHeight, write=FGroupFooterLineHeight, nodefault};
	__property int GroupRowLineHeight = {read=FGroupRowLineHeight, write=FGroupRowLineHeight, nodefault};
	__property System::Uitypes::TColor GroupRowSeparatorColor = {read=GetGroupRowSeparatorColor, nodefault};
	__property int GroupRowSeparatorThickness = {read=GetGroupRowSeparatorThickness, nodefault};
	__property bool HasPreview = {read=GetHasPreview, nodefault};
	__property int HeaderLineCount = {read=GetHeaderLineCount, nodefault};
	__property int HeaderLineHeight = {read=FHeaderLineHeight, write=FHeaderLineHeight, nodefault};
	__property bool PreviewAutoHeight = {read=GetPreviewAutoHeight, nodefault};
	__property Cxgridtableview::TcxGridColumn* PreviewColumn = {read=GetPreviewColumn};
	__property int PreviewLineHeight = {read=FPreviewLineHeight, write=FPreviewLineHeight, nodefault};
	__property int PreviewMaxLineCount = {read=GetPreviewMaxLineCount, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowHeights[int Index] = {read=GetRowHeight, write=SetRowHeight};
	__property int RowHeightsByRow[Cxgridtableview::TcxCustomGridRow* Row] = {read=GetRowHeightByRow, write=SetRowHeightByRow};
	__property Cxgridtableview::TcxCustomGridRow* Rows[int Index] = {read=GetRow};
	__property System::Uitypes::TColor RowSeparatorColor = {read=GetRowSeparatorColor, nodefault};
	__property int RowSeparatorThickness = {read=GetRowSeparatorThickness, nodefault};
	__property bool ShowGroupFooters = {read=GetShowGroupFooters, nodefault};
	__property bool ShowFooters = {read=GetShowFooters, nodefault};
	__property bool ShowHeaders = {read=GetShowHeaders, nodefault};
	__property bool ShowPreview = {read=GetShowPreview, nodefault};
};


class DELPHICLASS TdxGridTableViewFootersProducer;
class DELPHICLASS TdxGridTableViewGroupFooterProducer;
class DELPHICLASS TdxGridTableViewHeadersProducer;
class DELPHICLASS TdxGridTableViewCustomDataRowProducer;
class DELPHICLASS TdxGridTableViewRowSeparatorProducer;
class DELPHICLASS TdxGridTableViewGroupRowSeparatorProducer;
class PASCALIMPLEMENTATION TdxGridTableViewBuilder : public TdxCustomGridTableViewBuilder
{
	typedef TdxCustomGridTableViewBuilder inherited;
	
private:
	Dxpscore::TdxReportCell* __fastcall GetLastReportRow(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetProcessedView(void);
	void __fastcall SetProcessedView(Cxgridcustomview::TcxCustomGridView* Value);
	
protected:
	void __fastcall AddDelimitersHardVert(Dxpscore::TdxReportCell* AReportRow);
	virtual void __fastcall DoBuildViewBody(void);
	virtual void __fastcall DoBuildViewFooter(void);
	virtual void __fastcall CreateDetails(Cxgridtableview::TcxGridMasterDataRow* AMasterRow);
	virtual void __fastcall CreateDetailView(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual bool __fastcall GetAreDetailsBuilt(void);
	virtual void __fastcall CreateFooter(void);
	virtual TdxGridTableViewFootersProducer* __fastcall GetFootersProducer(void);
	virtual TdxGridTableViewFootersProducerClass __fastcall GetFootersProducerClass(void);
	virtual void __fastcall CreateGroupFooters(Cxgridtableview::TcxCustomGridRow* AGridRow);
	virtual TdxGridTableViewGroupFooterProducer* __fastcall GetGroupFooterProducer(void);
	virtual TdxGridTableViewGroupFooterProducerClass __fastcall GetGroupFooterProducerClass(void);
	virtual void __fastcall CreateHeader(void);
	virtual TdxGridTableViewHeadersProducer* __fastcall GetHeadersProducer(void);
	virtual TdxGridTableViewHeadersProducerClass __fastcall GetHeadersProducerClass(void);
	virtual void __fastcall CreateRow(Cxgridtableview::TcxCustomGridRow* AGridRow, int ARowIndex);
	virtual void __fastcall CreateRows(void);
	virtual TdxGridTableViewCustomDataRowProducer* __fastcall GetRowProducer(Cxgridtableview::TcxCustomGridRow* AGridRow);
	virtual TdxGridTableViewCustomDataRowProducerClass __fastcall GetRowProducerClass(Cxgridtableview::TcxCustomGridRow* AGridRow);
	virtual void __fastcall CreateRowSeparator(Cxgridtableview::TcxCustomGridRow* AGridRow, bool AnIsLast = false);
	virtual TdxGridTableViewRowSeparatorProducer* __fastcall GetRowSeparatorProducer(void);
	virtual TdxGridTableViewRowSeparatorProducerClass __fastcall GetRowSeparatorProducerClass(void);
	virtual bool __fastcall GetShowRowSeparators(void);
	virtual void __fastcall CreateGroupRowSeparator(Cxgridtableview::TcxGridGroupRow* AGridRow);
	virtual TdxGridTableViewGroupRowSeparatorProducer* __fastcall GetGroupRowSeparatorProducer(void);
	virtual TdxGridTableViewGroupRowSeparatorProducerClass __fastcall GetGroupRowSeparatorProducerClass(void);
	virtual bool __fastcall GetShowGroupRowSeparators(void);
	HIDESBASE Cxgridtableview::TcxGridTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	__property Dxpscore::TdxReportCell* LastReportRow = {read=GetLastReportRow};
	__property Cxgridcustomview::TcxCustomGridView* ProcessedView = {read=GetProcessedView, write=SetProcessedView};
	
public:
	HIDESBASE TdxGridTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
	HIDESBASE TdxGridTableViewFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TdxGridViewFormatterClass __fastcall FormatterClass();
	__property bool AreDetailsBuilt = {read=GetAreDetailsBuilt, nodefault};
	__property bool ShowGroupRowSeparators = {read=GetShowGroupRowSeparators, nodefault};
	__property bool ShowRowSeparators = {read=GetShowRowSeparators, nodefault};
public:
	/* TdxCustomGridViewBuilder.Create */ inline __fastcall virtual TdxGridTableViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxCustomGridTableViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxCustomGridViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridTableViewBuilder(void) { }
	
};


class DELPHICLASS TdxGridDBTableViewAdapter;
class PASCALIMPLEMENTATION TdxGridDBTableViewAdapter : public TdxGridTableViewAdapter
{
	typedef TdxGridTableViewAdapter inherited;
	
protected:
	HIDESBASE Cxgriddbdatadefinitions::TcxGridDBDataController* __fastcall DataController(void)/* overload */;
	virtual Cxdbdata::TcxDBDataModeController* __fastcall DBDataModeController(void);
	
public:
	HIDESBASE Cxgriddbtableview::TcxGridDBTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
public:
	/* TdxGridTableViewAdapter.Create */ inline __fastcall virtual TdxGridDBTableViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridTableViewAdapter(AMasterAdapter, AGridView) { }
	
public:
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridDBTableViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridDBTableViewBuilder;
class PASCALIMPLEMENTATION TdxGridDBTableViewBuilder : public TdxGridTableViewBuilder
{
	typedef TdxGridTableViewBuilder inherited;
	
protected:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	
public:
	HIDESBASE TdxGridDBTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
public:
	/* TdxCustomGridViewBuilder.Create */ inline __fastcall virtual TdxGridDBTableViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridTableViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxCustomGridViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridDBTableViewBuilder(void) { }
	
};


class DELPHICLASS TcxGridServerModeTableViewAdapter;
class PASCALIMPLEMENTATION TcxGridServerModeTableViewAdapter : public TdxGridTableViewAdapter
{
	typedef TdxGridTableViewAdapter inherited;
	
protected:
	HIDESBASE Dxservermodedata::TdxServerModeDataController* __fastcall DataController(void)/* overload */;
	
public:
	HIDESBASE Cxgridservermodetableview::TcxGridServerModeTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
public:
	/* TdxGridTableViewAdapter.Create */ inline __fastcall virtual TcxGridServerModeTableViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridTableViewAdapter(AMasterAdapter, AGridView) { }
	
public:
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TcxGridServerModeTableViewAdapter(void) { }
	
};


class DELPHICLASS TcxGridServerModeTableViewBuilder;
class PASCALIMPLEMENTATION TcxGridServerModeTableViewBuilder : public TdxGridTableViewBuilder
{
	typedef TdxGridTableViewBuilder inherited;
	
protected:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	
public:
	HIDESBASE TcxGridServerModeTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
public:
	/* TdxCustomGridViewBuilder.Create */ inline __fastcall virtual TcxGridServerModeTableViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridTableViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxCustomGridViewBuilder.Destroy */ inline __fastcall virtual ~TcxGridServerModeTableViewBuilder(void) { }
	
};


class DELPHICLASS TdxGridBandedTableViewAdapter;
class PASCALIMPLEMENTATION TdxGridBandedTableViewAdapter : public TdxGridTableViewAdapter
{
	typedef TdxGridTableViewAdapter inherited;
	
private:
	int FFooterLineCount;
	Cxgridbandedtableview::TcxGridBand* __fastcall GetBand(int Index);
	int __fastcall GetBandCount(void);
	bool __fastcall GetBandEndEllipsis(void);
	int __fastcall GetBandHeaderLineCount(void);
	bool __fastcall GetBandHeaderMultiline(void);
	Cxgridbandedtableview::TcxGridBand* __fastcall GetBottomBand(int Index);
	int __fastcall GetBottomBandCount(void);
	HIDESBASE Cxgridbandedtableview::TcxGridBandedColumn* __fastcall GetColumn(int Index);
	HIDESBASE int __fastcall GetFooterLineCount(void);
	Cxgridbandedtableview::TcxGridBand* __fastcall GetRootBand(int Index);
	int __fastcall GetRootBandCount(void);
	System::Uitypes::TColor __fastcall GetThemedBandHeaderItemColor(void);
	System::Uitypes::TColor __fastcall GetThemedBandHeaderItemTextColor(void);
	
protected:
	virtual int __fastcall CalculateDetailsLineCount(void);
	virtual int __fastcall CalculateFooterLineCount(void);
	virtual int __fastcall GetBandHeaderHeight(void);
	virtual bool __fastcall GetBandHeaderHeightAssigned(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetBandHeaderViewParams(Cxgridbandedtableview::TcxGridBand* ABand);
	virtual bool __fastcall GetDataRowHeightAssigned(void);
	virtual bool __fastcall GetFooterHeightAssigned(void);
	virtual bool __fastcall GetHeaderHeightAssigned(void);
	virtual bool __fastcall GetHeaderMultiline(Cxgridtableview::TcxGridColumn* Column);
	virtual int __fastcall GetRowLineCount(void);
	
public:
	__fastcall virtual TdxGridBandedTableViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView);
	HIDESBASE Cxgridbandedtableview::TcxGridBandedTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	HIDESBASE Cxgridbandedtableview::TcxGridBandedTableViewStyles* __fastcall Styles(void)/* overload */;
	__property int BandCount = {read=GetBandCount, nodefault};
	__property bool BandEndEllipsis = {read=GetBandEndEllipsis, nodefault};
	__property int BandHeaderHeight = {read=GetBandHeaderHeight, nodefault};
	__property bool BandHeaderHeightAssigned = {read=GetBandHeaderHeightAssigned, nodefault};
	__property int BandHeaderLineCount = {read=GetBandHeaderLineCount, nodefault};
	__property bool BandHeaderMultiline = {read=GetBandHeaderMultiline, nodefault};
	__property Cxgridbandedtableview::TcxGridBand* Bands[int Index] = {read=GetBand};
	__property int BottomBandCount = {read=GetBottomBandCount, nodefault};
	__property Cxgridbandedtableview::TcxGridBand* BottomBands[int Index] = {read=GetBottomBand};
	__property Cxgridbandedtableview::TcxGridBandedColumn* Columns[int Index] = {read=GetColumn};
	__property int FooterLineCount = {read=GetFooterLineCount, write=FFooterLineCount, nodefault};
	__property int RootBandCount = {read=GetRootBandCount, nodefault};
	__property Cxgridbandedtableview::TcxGridBand* RootBands[int Index] = {read=GetRootBand};
	__property System::Uitypes::TColor ThemedBandHeaderItemColor = {read=GetThemedBandHeaderItemColor, nodefault};
	__property System::Uitypes::TColor ThemedBandHeaderItemTextColor = {read=GetThemedBandHeaderItemTextColor, nodefault};
public:
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridBandedTableViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridBandedTableViewColumnPlace;
class DELPHICLASS TdxCustomGridBandedTableViewItemPlace;
class DELPHICLASS TdxGridBandedTableViewFormatter;
class PASCALIMPLEMENTATION TdxGridBandedTableViewColumnPlace : public TdxGridTableViewColumnPlace
{
	typedef TdxGridTableViewColumnPlace inherited;
	
private:
	Cxgridbandedtableview::TcxGridBandedColumn* __fastcall GetColumn(void);
	TdxCustomGridBandedTableViewItemPlace* __fastcall GetController(void);
	HIDESBASE TdxGridBandedTableViewFormatter* __fastcall GetFormatter(void);
	
protected:
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetRowIndex(void);
	
public:
	__property Cxgridbandedtableview::TcxGridBandedColumn* Column = {read=GetColumn};
	__property TdxCustomGridBandedTableViewItemPlace* Controller = {read=GetController};
	__property TdxGridBandedTableViewFormatter* Formatter = {read=GetFormatter};
public:
	/* TdxGridTableViewColumnPlace.Create */ inline __fastcall virtual TdxGridBandedTableViewColumnPlace(TdxGridTableViewColumnPlaceController* AController, Cxgridtableview::TcxGridColumn* AColumn) : TdxGridTableViewColumnPlace(AController, AColumn) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridBandedTableViewColumnPlace(void) { }
	
};


typedef System::TMetaClass* TdxCustomGridBandedTableViewItemPlaceClass;

class DELPHICLASS TdxGridBandedTableViewItemPlaceController;
class DELPHICLASS TdxGridBandedTableViewItemPlace;
class PASCALIMPLEMENTATION TdxCustomGridBandedTableViewItemPlace : public TdxGridTableViewColumnPlaceController
{
	typedef TdxGridTableViewColumnPlaceController inherited;
	
private:
	Cxgridbandedtableview::TcxGridBand* FBand;
	TdxGridBandedTableViewItemPlaceController* FController;
	int FHeight;
	int FLeftBound;
	int FMinWidth;
	TdxGridBandedTableViewItemPlace* FParent;
	int FTopBound;
	HIDESBASE TdxGridBandedTableViewAdapter* __fastcall GetAdapter(void);
	System::Types::TRect __fastcall GetBounds(void);
	TdxGridBandedTableViewFormatter* __fastcall GetFormatter(void);
	int __fastcall GetHeight(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsFixed(void);
	int __fastcall GetLeftBound(void);
	int __fastcall GetLevelIndex(void);
	int __fastcall GetMinWidth(void);
	int __fastcall GetTopBound(void);
	Dxpscxcommon::TdxReportItemViewParams __fastcall GetViewParams(void);
	
protected:
	virtual int __fastcall CalculateHeaderLineCount(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TdxGridTableViewColumnPlaceClass __fastcall GetItemClass(Cxgridtableview::TcxGridColumn* AColumn);
	void __fastcall AssignWidth(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateLeftBound(void);
	virtual int __fastcall CalculateLevelHeight(void);
	virtual int __fastcall CalculateLineHeight(void);
	virtual int __fastcall CalculateMinWidth(void);
	virtual int __fastcall CalculateTopBound(void);
	virtual void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AnItem);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall InternalCalculateMinWidth(void);
	virtual int __fastcall InternalCalculateWidth(void);
	__property TdxGridBandedTableViewAdapter* Adapter = {read=GetAdapter};
	__property Cxgridbandedtableview::TcxGridBand* Band = {read=FBand};
	__property bool IsFixed = {read=GetIsFixed, nodefault};
	__property int LevelIndex = {read=GetLevelIndex, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property Dxpscxcommon::TdxReportItemViewParams ViewParams = {read=GetViewParams};
	
public:
	__fastcall virtual TdxCustomGridBandedTableViewItemPlace(TdxGridBandedTableViewItemPlaceController* AController, TdxGridBandedTableViewItemPlace* AParent, Cxgridbandedtableview::TcxGridBand* ABand);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property TdxGridBandedTableViewItemPlaceController* Controller = {read=FController};
	__property TdxGridBandedTableViewFormatter* Formatter = {read=GetFormatter};
	__property int Height = {read=GetHeight, write=FHeight, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property int LeftBound = {read=GetLeftBound, write=FLeftBound, nodefault};
	__property TdxGridBandedTableViewItemPlace* Parent = {read=FParent};
	__property int TopBound = {read=GetTopBound, write=FTopBound, nodefault};
public:
	/* TdxGridTableViewColumnPlaceController.Destroy */ inline __fastcall virtual ~TdxCustomGridBandedTableViewItemPlace(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridBandedTableViewItemPlace : public TdxCustomGridBandedTableViewItemPlace
{
	typedef TdxCustomGridBandedTableViewItemPlace inherited;
	
private:
	System::Classes::TList* FChildItems;
	TdxCustomGridBandedTableViewItemPlace* __fastcall GetChildItem(int Index);
	int __fastcall GetChildItemCount(void);
	
protected:
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall InternalCalculateMinWidth(void);
	virtual int __fastcall InternalCalculateWidth(void);
	virtual void __fastcall WidthChanged(void);
	void __fastcall CalculateChildItemWidths(void);
	void __fastcall RefreshChildItems(void);
	
public:
	__fastcall virtual TdxGridBandedTableViewItemPlace(TdxGridBandedTableViewItemPlaceController* AnOwner, TdxGridBandedTableViewItemPlace* AParent, Cxgridbandedtableview::TcxGridBand* ABand);
	__fastcall virtual ~TdxGridBandedTableViewItemPlace(void);
	HIDESBASE int __fastcall IndexOf(TdxCustomGridBandedTableViewItemPlace* AnItem);
	virtual void __fastcall Refresh(void);
	__property int ChildItemCount = {read=GetChildItemCount, nodefault};
	__property TdxCustomGridBandedTableViewItemPlace* ChildItems[int Index] = {read=GetChildItem};
};


class DELPHICLASS TdxGridBandedTableViewBottomItemPlace;
class PASCALIMPLEMENTATION TdxGridBandedTableViewBottomItemPlace : public TdxCustomGridBandedTableViewItemPlace
{
	typedef TdxCustomGridBandedTableViewItemPlace inherited;
	
protected:
	virtual void __fastcall AddItems(void);
	virtual int __fastcall CalculateItemLeftBound(TdxGridTableViewColumnPlace* AnItem);
	virtual void __fastcall CalculateItemsWidth(void);
	virtual bool __fastcall GetItemsAutoWidth(void);
	virtual int __fastcall GetItemsAvailableWidth(void);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall InternalCalculateMinWidth(void);
	virtual int __fastcall InternalCalculateWidth(void);
	virtual void __fastcall WidthChanged(void);
public:
	/* TdxCustomGridBandedTableViewItemPlace.Create */ inline __fastcall virtual TdxGridBandedTableViewBottomItemPlace(TdxGridBandedTableViewItemPlaceController* AController, TdxGridBandedTableViewItemPlace* AParent, Cxgridbandedtableview::TcxGridBand* ABand) : TdxCustomGridBandedTableViewItemPlace(AController, AParent, ABand) { }
	
public:
	/* TdxGridTableViewColumnPlaceController.Destroy */ inline __fastcall virtual ~TdxGridBandedTableViewBottomItemPlace(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridBandedTableViewItemPlaceController : public TdxCustomGridTableViewItemPlaceController
{
	typedef TdxCustomGridTableViewItemPlaceController inherited;
	
public:
	TdxCustomGridBandedTableViewItemPlace* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FBottomItems;
	int FHeight;
	System::Classes::TList* FItems;
	int FLevelCount;
	System::Classes::TList* FLevelHeights;
	System::Classes::TList* FRootItems;
	TdxGridBandedTableViewAdapter* __fastcall GetAdapter(void);
	bool __fastcall GetAutoWidth(void);
	int __fastcall GetAvailableWidth(void);
	TdxCustomGridBandedTableViewItemPlace* __fastcall GetBottomItem(int Index);
	int __fastcall GetBottomItemCount(void);
	TdxGridBandedTableViewFormatter* __fastcall GetFormatter(void);
	int __fastcall GetHeight(void);
	TdxCustomGridBandedTableViewItemPlace* __fastcall GetItem(int Index);
	TdxCustomGridBandedTableViewItemPlace* __fastcall GetItemByBand(Cxgridbandedtableview::TcxGridBand* Band);
	int __fastcall GetItemCount(void);
	int __fastcall GetLevelCount(void);
	int __fastcall GetLevelHeight(int Index);
	TdxCustomGridBandedTableViewItemPlace* __fastcall GetRootItem(int Index);
	int __fastcall GetRootItemCount(void);
	void __fastcall SetLevelHeight(int Index, int Value);
	void __fastcall FreeAndNilItems(void);
	
protected:
	virtual int __fastcall CalculateHeaderLineCount(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TdxGridTableViewColumnPlace* __fastcall GetItemByColumn(Cxgridtableview::TcxGridColumn* Column);
	virtual void __fastcall AddItems(void);
	void __fastcall ClearItems(void);
	virtual TdxCustomGridBandedTableViewItemPlace* __fastcall CreateItem(Cxgridbandedtableview::TcxGridBand* ABand);
	virtual TdxCustomGridBandedTableViewItemPlaceClass __fastcall GetItemClass(Cxgridbandedtableview::TcxGridBand* ABand);
	void __fastcall RefreshBottomItems(void);
	void __fastcall RefreshItems(void);
	void __fastcall RefreshRootItems(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateItemHeight(TdxCustomGridBandedTableViewItemPlace* AnItem);
	virtual int __fastcall CalculateItemLeftBound(TdxCustomGridBandedTableViewItemPlace* AnItem);
	virtual int __fastcall CalculateItemTopBound(TdxCustomGridBandedTableViewItemPlace* AnItem);
	virtual int __fastcall CalculateLevelCount(void);
	void __fastcall CalculateItemWidths(void);
	void __fastcall CalculateLevelHeights(void);
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property TdxGridBandedTableViewAdapter* Adapter = {read=GetAdapter};
	__property int AvailableWidth = {read=GetAvailableWidth, nodefault};
	
public:
	__fastcall virtual TdxGridBandedTableViewItemPlaceController(TdxGridTableViewFormatter* AFormatter);
	__fastcall virtual ~TdxGridBandedTableViewItemPlaceController(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Refresh(void);
	int __fastcall IndexOf(TdxCustomGridBandedTableViewItemPlace* AnItem)/* overload */;
	int __fastcall IndexOf(Cxgridbandedtableview::TcxGridBand* ABand)/* overload */;
	int __fastcall RootIndexOf(TdxCustomGridBandedTableViewItemPlace* AnItem)/* overload */;
	int __fastcall RootIndexOf(Cxgridbandedtableview::TcxGridBand* ABand)/* overload */;
	__property int BottomItemCount = {read=GetBottomItemCount, nodefault};
	__property TdxCustomGridBandedTableViewItemPlace* BottomItems[int Index] = {read=GetBottomItem};
	__property TdxGridBandedTableViewFormatter* Formatter = {read=GetFormatter};
	__property int Height = {read=GetHeight, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxCustomGridBandedTableViewItemPlace* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxCustomGridBandedTableViewItemPlace* ItemsByBand[Cxgridbandedtableview::TcxGridBand* Band] = {read=GetItemByBand};
	__property int LevelCount = {read=GetLevelCount, nodefault};
	__property int LevelHeights[int Index] = {read=GetLevelHeight, write=SetLevelHeight};
	__property int RootItemCount = {read=GetRootItemCount, nodefault};
	__property TdxCustomGridBandedTableViewItemPlace* RootItems[int Index] = {read=GetRootItem};
};


class DELPHICLASS TdxGridBandedTableViewBuilder;
class PASCALIMPLEMENTATION TdxGridBandedTableViewFormatter : public TdxGridTableViewFormatter
{
	typedef TdxGridTableViewFormatter inherited;
	
private:
	System::Classes::TList* FBands;
	bool FHeadersSingleLine;
	Cxgridbandedtableview::TcxGridBand* __fastcall GetBand(int Index);
	int __fastcall GetBandCount(void);
	HIDESBASE Cxgridbandedtableview::TcxGridBandedColumn* __fastcall GetColumn(int Index);
	TdxGridBandedTableViewItemPlaceController* __fastcall GetItemPlaceController(void);
	bool __fastcall GetShowBandHeaders(void);
	
protected:
	virtual void __fastcall AddHorizontalDelimiters(void);
	virtual bool __fastcall CanColumnCellMerging(Cxgridtableview::TcxGridColumn* AColumn);
	virtual bool __fastcall IsColumnActuallyVisible(Cxgridtableview::TcxGridColumn* AColumn);
	virtual bool __fastcall GetAlignSummaryWithColumns(void);
	virtual TdxCustomGridTableViewItemPlaceControllerClass __fastcall GetItemPlaceControllerClass(void);
	virtual void __fastcall BuildBandList(void);
	virtual void __fastcall BuildItemLists(void);
	virtual bool __fastcall IsBandActuallyVisible(Cxgridbandedtableview::TcxGridBand* ABand);
	virtual int __fastcall MapStyleBackgroundBitmapIndex(int AGridBackgroundBitmapIndex);
	__property bool HeadersSingleLine = {read=FHeadersSingleLine, nodefault};
	__property TdxGridBandedTableViewItemPlaceController* ItemPlaceController = {read=GetItemPlaceController};
	
public:
	__fastcall virtual TdxGridBandedTableViewFormatter(TdxCustomGridViewBuilder* ABuilder);
	__fastcall virtual ~TdxGridBandedTableViewFormatter(void);
	HIDESBASE TdxGridBandedTableViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridBandedTableViewBuilder* __fastcall Builder(void)/* overload */;
	virtual void __fastcall DoInitializeBandItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual void __fastcall DoInitializeBandRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoReportLinkInitializeBandItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual System::Types::TRect __fastcall GetBandItemBounds(int AnIndex);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetBandItemClass(int AnIndex);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetBandItemViewParams(Cxgridbandedtableview::TcxGridBand* ABand);
	__property int BandCount = {read=GetBandCount, nodefault};
	__property Cxgridbandedtableview::TcxGridBand* Bands[int Index] = {read=GetBand};
	__property Cxgridbandedtableview::TcxGridBandedColumn* Columns[int Index] = {read=GetColumn};
	__property bool ShowBandHeaders = {read=GetShowBandHeaders, nodefault};
};


class DELPHICLASS TdxGridTableViewBandsProducer;
class PASCALIMPLEMENTATION TdxGridBandedTableViewBuilder : public TdxGridTableViewBuilder
{
	typedef TdxGridTableViewBuilder inherited;
	
protected:
	virtual void __fastcall DoBuildViewBody(void);
	virtual void __fastcall CreateBands(void);
	virtual TdxGridTableViewBandsProducer* __fastcall GetBandsProducer(void);
	virtual TdxGridTableViewBandsProducerClass __fastcall GetBandsProducerClass(void);
	HIDESBASE Cxgridbandedtableview::TcxGridBandedTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	
public:
	HIDESBASE TdxGridBandedTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
	HIDESBASE TdxGridBandedTableViewFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TdxGridViewFormatterClass __fastcall FormatterClass();
public:
	/* TdxCustomGridViewBuilder.Create */ inline __fastcall virtual TdxGridBandedTableViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridTableViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxCustomGridViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridBandedTableViewBuilder(void) { }
	
};


class DELPHICLASS TdxGridDBBandedTableViewAdapter;
class PASCALIMPLEMENTATION TdxGridDBBandedTableViewAdapter : public TdxGridBandedTableViewAdapter
{
	typedef TdxGridBandedTableViewAdapter inherited;
	
protected:
	HIDESBASE Cxgriddbdatadefinitions::TcxGridDBDataController* __fastcall DataController(void)/* overload */;
	virtual Cxdbdata::TcxDBDataModeController* __fastcall DBDataModeController(void);
	
public:
	HIDESBASE Cxgriddbbandedtableview::TcxGridDBBandedTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
public:
	/* TdxGridBandedTableViewAdapter.Create */ inline __fastcall virtual TdxGridDBBandedTableViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridBandedTableViewAdapter(AMasterAdapter, AGridView) { }
	
public:
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridDBBandedTableViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridDBBandedTableViewBuilder;
class PASCALIMPLEMENTATION TdxGridDBBandedTableViewBuilder : public TdxGridBandedTableViewBuilder
{
	typedef TdxGridBandedTableViewBuilder inherited;
	
protected:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	
public:
	HIDESBASE TdxGridDBBandedTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
public:
	/* TdxCustomGridViewBuilder.Create */ inline __fastcall virtual TdxGridDBBandedTableViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridBandedTableViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxCustomGridViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridDBBandedTableViewBuilder(void) { }
	
};


class DELPHICLASS TdxGridServerModeBandedTableViewAdapter;
class PASCALIMPLEMENTATION TdxGridServerModeBandedTableViewAdapter : public TdxGridBandedTableViewAdapter
{
	typedef TdxGridBandedTableViewAdapter inherited;
	
protected:
	HIDESBASE Dxservermodedata::TdxServerModeDataController* __fastcall DataController(void)/* overload */;
	
public:
	HIDESBASE Cxgridservermodebandedtableview::TcxGridServerModeBandedTableView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
public:
	/* TdxGridBandedTableViewAdapter.Create */ inline __fastcall virtual TdxGridServerModeBandedTableViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridBandedTableViewAdapter(AMasterAdapter, AGridView) { }
	
public:
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridServerModeBandedTableViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridServerModeBandedTableViewBuilder;
class PASCALIMPLEMENTATION TdxGridServerModeBandedTableViewBuilder : public TdxGridBandedTableViewBuilder
{
	typedef TdxGridBandedTableViewBuilder inherited;
	
protected:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	
public:
	HIDESBASE TdxGridServerModeBandedTableViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
public:
	/* TdxCustomGridViewBuilder.Create */ inline __fastcall virtual TdxGridServerModeBandedTableViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridBandedTableViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxCustomGridViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridServerModeBandedTableViewBuilder(void) { }
	
};


typedef System::TMetaClass* TdxReportCardRowClass;

typedef System::TMetaClass* TdxReportCardLayerClass;

class DELPHICLASS TdxReportCardLayer;
class DELPHICLASS TdxReportCardHorz;
class DELPHICLASS TdxReportCardRow;
class DELPHICLASS TdxGridCardViewBuilder;
class PASCALIMPLEMENTATION TdxReportCardLayer : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
public:
	TdxReportCardRow* operator[](int Index) { return Rows[Index]; }
	
private:
	Dxpscore::TdxReportCellBox* FCategorySeparator;
	Dxpscore::TdxReportCellBox* FLayerSeparator;
	bool FNeedCategorySeparator;
	bool FNeedLayerSeparator;
	System::Classes::TList* FRows;
	Cxgridcardview::TcxGridCardViewRow* __fastcall GetBeginsLayerRow(void);
	TdxReportCardHorz* __fastcall GetCard(void);
	HIDESBASE int __fastcall GetHeight(void);
	int __fastcall GetInternalHeight(void);
	int __fastcall GetInternalWidth(void);
	TdxReportCardRow* __fastcall GetRow(int AIndex);
	int __fastcall GetRowCount(void);
	HIDESBASE int __fastcall GetWidth(void);
	HIDESBASE void __fastcall SetHeight(int AValue);
	void __fastcall SetInternalHeight(int AValue);
	void __fastcall SetInternalWidth(int AValue);
	HIDESBASE void __fastcall SetWidth(int AValue);
	
protected:
	virtual void __fastcall AdjustRowsHeight(void);
	virtual void __fastcall AdjustRowHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, bool AAutoHeight, TdxGridCardViewBuilder* ABuilder);
	virtual bool __fastcall CanHaveIndent(TdxReportCardRow* ARow);
	virtual void __fastcall CheckNeedCategorySeparator(TdxReportCardLayer* ANextLayer);
	void __fastcall CreateItems(TdxGridCardViewBuilder* ABuilder);
	void __fastcall CreateCategorySeparator(void);
	virtual void __fastcall CreateLayerSeparator(void);
	void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AnItem, bool &AAllFixed);
	virtual void __fastcall PlaceSeparatorAndExcludeHeightFromHeight(int &AValue);
	virtual void __fastcall RecalculateHeight(void);
	virtual void __fastcall ResizeRowsHorz(void);
	int __fastcall SetPosition(int ALeft, int AWidth);
	virtual void __fastcall SetRowCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, bool ACaptionAutoWidths, int AValue);
	virtual void __fastcall SetRowHeight(int ARowIndex, int AValue);
	virtual void __fastcall SizeChanged(void);
	__property int InternalHeight = {read=GetInternalHeight, write=SetInternalHeight, nodefault};
	__property int InternalWidth = {read=GetInternalWidth, write=SetInternalWidth, nodefault};
	__property bool NeedCategorySeparator = {read=FNeedCategorySeparator, write=FNeedCategorySeparator, nodefault};
	__property bool NeedLayerSeparator = {read=FNeedLayerSeparator, write=FNeedLayerSeparator, nodefault};
	
public:
	__fastcall virtual TdxReportCardLayer(Dxpscore::TdxReportCell* AParent, Cxgridcardview::TcxGridCardViewRow* ABeginsLayerRow);
	__fastcall virtual ~TdxReportCardLayer(void);
	virtual void __fastcall AdjustCellSides(void);
	TdxReportCardRow* __fastcall AddRow(Cxgridcardview::TcxGridCardViewRow* AGridCardRow);
	virtual int __fastcall MeasureCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	int __fastcall MeasureDataWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureLayerHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, bool ACalculateLineHeight, TdxGridCardViewBuilder* ABuilder);
	virtual int __fastcall MeasureWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property Cxgridcardview::TcxGridCardViewRow* BeginsLayerRow = {read=GetBeginsLayerRow};
	__property TdxReportCardHorz* Card = {read=GetCard};
	__property Dxpscore::TdxReportCellBox* CategorySeparator = {read=FCategorySeparator};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property Dxpscore::TdxReportCellBox* LayerSeparator = {read=FLayerSeparator};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TdxReportCardRow* Rows[int Index] = {read=GetRow/*, default*/};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportCardLayer(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCell(AParent) { }
	
};


class DELPHICLASS TdxReportCardVerticalLayer;
class PASCALIMPLEMENTATION TdxReportCardVerticalLayer : public TdxReportCardLayer
{
	typedef TdxReportCardLayer inherited;
	
protected:
	virtual void __fastcall AdjustRowsHeight(void);
	virtual bool __fastcall CanHaveIndent(TdxReportCardRow* ARow);
	virtual void __fastcall CreateLayerSeparator(void);
	virtual void __fastcall CheckNeedCategorySeparator(TdxReportCardLayer* ANextLayer);
	virtual void __fastcall PlaceSeparatorAndExcludeHeightFromHeight(int &AValue);
	virtual void __fastcall RecalculateHeight(void);
	virtual void __fastcall SetRowCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, bool ACaptionAutoWidths, int AValue);
	virtual void __fastcall SizeChanged(void);
	
public:
	virtual void __fastcall AdjustCellSides(void);
	virtual int __fastcall MeasureCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
public:
	/* TdxReportCardLayer.CreateEx */ inline __fastcall virtual TdxReportCardVerticalLayer(Dxpscore::TdxReportCell* AParent, Cxgridcardview::TcxGridCardViewRow* ABeginsLayerRow) : TdxReportCardLayer(AParent, ABeginsLayerRow) { }
	/* TdxReportCardLayer.Destroy */ inline __fastcall virtual ~TdxReportCardVerticalLayer(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportCardVerticalLayer(Dxpscore::TdxReportCell* AParent) : TdxReportCardLayer(AParent) { }
	
};


class DELPHICLASS TdxReportCard;
class PASCALIMPLEMENTATION TdxReportCardRow : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
private:
	bool FNeedSeparator;
	Dxpscore::TdxReportCellText* FRowCaption;
	Dxpscore::TAbstractdxReportCellData* FRowData;
	Dxpscore::TdxReportCellExpandButton* FRowIndent;
	Dxpscore::TdxReportCellBox* FRowSeparator;
	TdxReportCard* __fastcall GetCard(void);
	Cxgridcardview::TcxGridCardViewRow* __fastcall GetGridCardRow(void);
	bool __fastcall GetHasCaption(void);
	bool __fastcall GetHasData(void);
	bool __fastcall GetHasIndent(void);
	bool __fastcall GetHasRowSeparator(void);
	HIDESBASE int __fastcall GetHeight(void);
	TdxReportCardLayer* __fastcall GetLayer(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void);
	HIDESBASE int __fastcall GetWidth(void);
	HIDESBASE void __fastcall SetHeight(int AValue);
	void __fastcall SetRowCaptionWidth(int Value);
	HIDESBASE void __fastcall SetWidth(int Value);
	
protected:
	virtual void __fastcall AdjustCellSides(bool AIsFirstItem, bool AIsLastItem, bool AIsLeftItem, bool AIsRightItem);
	virtual void __fastcall CreateItems(TdxGridCardViewBuilder* ABuilder);
	int __fastcall MeasureCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	int __fastcall MeasureDataWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property Cxedit::TcxCustomEditProperties* Properties = {read=GetProperties};
	__property bool NeedSeparator = {read=FNeedSeparator, write=FNeedSeparator, nodefault};
	
public:
	__fastcall virtual TdxReportCardRow(Dxpscore::TdxReportCell* AParent, Cxgridcardview::TcxGridCardViewRow* AGridCardRow);
	HIDESBASE int __fastcall MeasureHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, bool ACalculateLineHeight, TdxGridCardViewBuilder* ABuilder)/* overload */;
	virtual int __fastcall MeasureWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property TdxReportCard* Card = {read=GetCard};
	__property Cxgridcardview::TcxGridCardViewRow* GridCardRow = {read=GetGridCardRow};
	__property bool HasCaption = {read=GetHasCaption, nodefault};
	__property bool HasData = {read=GetHasData, nodefault};
	__property bool HasIndent = {read=GetHasIndent, nodefault};
	__property bool HasRowSeparator = {read=GetHasRowSeparator, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property TdxReportCardLayer* Layer = {read=GetLayer};
	__property Dxpscore::TdxReportCellText* RowCaption = {read=FRowCaption};
	__property int RowCaptionWidth = {write=SetRowCaptionWidth, nodefault};
	__property Dxpscore::TAbstractdxReportCellData* RowData = {read=FRowData};
	__property Dxpscore::TdxReportCellExpandButton* RowIndent = {read=FRowIndent};
	__property Dxpscore::TdxReportCellBox* RowSeparator = {read=FRowSeparator};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportCardRow(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportCardRow(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCell(AParent) { }
	
};


class DELPHICLASS TdxCardBorderPainter;
class PASCALIMPLEMENTATION TdxCardBorderPainter : public Dxpscore::TdxPSCellBorderPainter
{
	typedef Dxpscore::TdxPSCellBorderPainter inherited;
	
protected:
	HIDESBASE virtual void __fastcall DrawShadow(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	
public:
	TdxReportCard* __fastcall Card(void)/* overload */;
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
public:
	/* TdxPSCellBorderPainter.Create */ inline __fastcall virtual TdxCardBorderPainter(Dxpscore::TdxPSReportRenderer* ARenderer) : Dxpscore::TdxPSCellBorderPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCardBorderPainter(void) { }
	
};


typedef System::Int8 TdxGridCardShadowDepth;

enum TdxGridCardShadowPosition : unsigned char { cspTopLeft, cspTopRight, cspBottomRight, cspBottomLeft };

class DELPHICLASS TdxReportCustomLayoutRecord;
class PASCALIMPLEMENTATION TdxReportCustomLayoutRecord : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
protected:
	virtual void __fastcall AdjustRecordWidth(void);
	
public:
	__fastcall virtual TdxReportCustomLayoutRecord(Dxpscore::TdxReportCell* AParent, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord);
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportCustomLayoutRecord(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportCustomLayoutRecord(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCell(AParent) { }
	
};


typedef System::TMetaClass* TdxReportCustomLayoutRecordClass;

class PASCALIMPLEMENTATION TdxReportCard : public TdxReportCustomLayoutRecord
{
	typedef TdxReportCustomLayoutRecord inherited;
	
private:
	int FCaptionWidth;
	int FLayerCaptionWidth;
	System::Uitypes::TColor FShadowColor;
	int FShadowDepth;
	TdxGridCardShadowPosition FShadowPosition;
	int __fastcall GetContentHeight(void);
	int __fastcall GetContentWidth(void);
	bool __fastcall GetHasShadow(void);
	HIDESBASE int __fastcall GetHeight(void);
	int __fastcall GetLayerCount(void);
	TdxReportCardLayer* __fastcall GetLayer(int Index);
	int __fastcall GetLayerHeight(int Index);
	int __fastcall GetLayersOriginLeft(void);
	int __fastcall GetLayersOriginTop(void);
	HIDESBASE TdxGridReportLink* __fastcall GetReportLink(void);
	System::Types::TRect __fastcall GetShadowRectHorz(void);
	System::Types::TRect __fastcall GetShadowRectVert(void);
	Cxgridcardview::TcxGridCard* __fastcall GetGridCard(void);
	HIDESBASE int __fastcall GetWidth(void);
	void __fastcall SetContentHeight(int AValue);
	void __fastcall SetContentWidth(int AValue);
	HIDESBASE void __fastcall SetHeight(int Value);
	void __fastcall SetShadowDepth2(int AValue);
	HIDESBASE void __fastcall SetWidth(int Value);
	
protected:
	virtual void __fastcall AddVerticalDelimiters(void);
	virtual void __fastcall AdjustRecordWidth(void);
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual Dxpscore::TdxPSCellBorderPainterClass __fastcall GetBorderPainterClass(void);
	virtual void __fastcall ReadProperties(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteProperties(Dxpscore::TdxPSDataWriter* AWriter);
	virtual void __fastcall AdjustHeight(void) = 0 ;
	virtual void __fastcall AdjustWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas) = 0 ;
	virtual int __fastcall MeasureCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas) = 0 ;
	virtual void __fastcall SetCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, int ALayer, int AValue, int AMaxValue, bool ACaptionAutoWidths);
	virtual void __fastcall AdjustLayers(void);
	virtual void __fastcall AdjustLayersCellSides(void) = 0 ;
	virtual void __fastcall AdjustLayersPos(void) = 0 ;
	virtual void __fastcall CreateLayers(TdxGridCardViewBuilder* ABuilder);
	virtual TdxReportCardLayerClass __fastcall GetLayerClass(void);
	virtual int __fastcall GetLayerIndexByRow(Cxgridcardview::TcxGridCardViewRow* ARow);
	virtual int __fastcall GetLayerWidth(int Index);
	virtual bool __fastcall HasLayerSeparator(int ALayerIndex);
	void __fastcall RecalculateLayersHeight(void);
	virtual void __fastcall SetLayerHeight(int Index, int Value);
	virtual void __fastcall SetLayerWidth(int Index, int Value);
	virtual void __fastcall AdjustRowHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, bool AAutoHeight, TdxGridCardViewBuilder* ABuilder) = 0 ;
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall GetRowHeight(int AIndex);
	virtual void __fastcall SetRowHeight(int AIndex, int AValue);
	virtual void __fastcall SizeChanged(void);
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	
public:
	__fastcall virtual TdxReportCard(Dxpscore::TdxReportCell* AParent);
	virtual System::Types::TRect __fastcall GetBorderOuterBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property int CaptionWidth = {read=FCaptionWidth, write=FCaptionWidth, nodefault};
	__property int ContentHeight = {read=GetContentHeight, write=SetContentHeight, nodefault};
	__property int ContentWidth = {read=GetContentWidth, write=SetContentWidth, nodefault};
	__property Cxgridcardview::TcxGridCard* GridCard = {read=GetGridCard};
	__property bool HasShadow = {read=GetHasShadow, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int LayerCaptionWidth = {read=FLayerCaptionWidth, write=FLayerCaptionWidth, nodefault};
	__property int LayerCount = {read=GetLayerCount, nodefault};
	__property int LayerHeights[int Index] = {read=GetLayerHeight, write=SetLayerHeight};
	__property TdxReportCardLayer* Layers[int Index] = {read=GetLayer};
	__property int LayersOriginLeft = {read=GetLayersOriginLeft, nodefault};
	__property int LayersOriginTop = {read=GetLayersOriginTop, nodefault};
	__property int LayerWidths[int Index] = {read=GetLayerWidth, write=SetLayerWidth};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowHeight[int AIndex] = {read=GetRowHeight, write=SetRowHeight};
	__property System::Uitypes::TColor ShadowColor = {read=FShadowColor, write=FShadowColor, default=0};
	__property int ShadowDepth = {read=FShadowDepth, write=SetShadowDepth2, default=4};
	__property TdxGridCardShadowPosition ShadowPosition = {read=FShadowPosition, write=FShadowPosition, default=2};
	__property System::Types::TRect ShadowRectHorz = {read=GetShadowRectHorz};
	__property System::Types::TRect ShadowRectVert = {read=GetShadowRectVert};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
public:
	/* TdxReportCustomLayoutRecord.CreateEx */ inline __fastcall virtual TdxReportCard(Dxpscore::TdxReportCell* AParent, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord) : TdxReportCustomLayoutRecord(AParent, AGridRecord) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportCard(void) { }
	
};


class PASCALIMPLEMENTATION TdxReportCardHorz : public TdxReportCard
{
	typedef TdxReportCard inherited;
	
protected:
	virtual void __fastcall AdjustHeight(void);
	virtual void __fastcall AdjustLayersCellSides(void);
	virtual void __fastcall AdjustLayersPos(void);
	virtual void __fastcall AdjustRowHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, bool AAutoHeight, TdxGridCardViewBuilder* ABuilder);
	virtual void __fastcall AdjustWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureDataWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall SizeChanged(void);
public:
	/* TdxReportCard.Create */ inline __fastcall virtual TdxReportCardHorz(Dxpscore::TdxReportCell* AParent) : TdxReportCard(AParent) { }
	
public:
	/* TdxReportCustomLayoutRecord.CreateEx */ inline __fastcall virtual TdxReportCardHorz(Dxpscore::TdxReportCell* AParent, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord) : TdxReportCard(AParent, AGridRecord) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportCardHorz(void) { }
	
};


class DELPHICLASS TdxReportCardVert;
class PASCALIMPLEMENTATION TdxReportCardVert : public TdxReportCard
{
	typedef TdxReportCard inherited;
	
protected:
	virtual void __fastcall AdjustHeight(void);
	virtual void __fastcall AdjustLayers(void);
	virtual void __fastcall AdjustLayersCellSides(void);
	virtual void __fastcall AdjustLayersPos(void);
	virtual void __fastcall AdjustRowHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, bool AAutoHeight, TdxGridCardViewBuilder* ABuilder);
	virtual void __fastcall AdjustWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual TdxReportCardLayerClass __fastcall GetLayerClass(void);
	TdxReportCardLayer* __fastcall GetLayerByAbsoluteRowIndex(int &AIndex);
	virtual int __fastcall GetLayerIndexByRow(Cxgridcardview::TcxGridCardViewRow* ARow);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall GetRowHeight(int AIndex);
	virtual bool __fastcall HasLayerSeparator(int ALayerIndex);
	virtual int __fastcall MeasureCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall SetCaptionWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, int ALayer, int AValue, int AMaxValue, bool ACaptionAutoWidth);
	virtual void __fastcall SetLayerWidth(int Index, int Value);
	virtual void __fastcall SetLayerHeight(int AIndex, int AValue);
	void __fastcall SetLayersSameHeight(void);
	virtual void __fastcall SetRowHeight(int AIndex, int AValue);
	virtual void __fastcall SizeChanged(void);
public:
	/* TdxReportCard.Create */ inline __fastcall virtual TdxReportCardVert(Dxpscore::TdxReportCell* AParent) : TdxReportCard(AParent) { }
	
public:
	/* TdxReportCustomLayoutRecord.CreateEx */ inline __fastcall virtual TdxReportCardVert(Dxpscore::TdxReportCell* AParent, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord) : TdxReportCard(AParent, AGridRecord) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportCardVert(void) { }
	
};


typedef System::TMetaClass* TdxReportCardClass;

class DELPHICLASS TdxGridCustomLayoutViewAdapter;
class PASCALIMPLEMENTATION TdxGridCustomLayoutViewAdapter : public TdxCustomGridTableViewAdapter
{
	typedef TdxCustomGridTableViewAdapter inherited;
	
public:
	virtual void __fastcall ExpandAllRows(TdxGridReportLinkOptionsExpanding* AnOptionsExpanding, bool ARecursive);
public:
	/* TdxCustomGridTableViewAdapter.Create */ inline __fastcall virtual TdxGridCustomLayoutViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxCustomGridTableViewAdapter(AMasterAdapter, AGridView) { }
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridCustomLayoutViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridCardViewAdapter;
class PASCALIMPLEMENTATION TdxGridCardViewAdapter : public TdxGridCustomLayoutViewAdapter
{
	typedef TdxGridCustomLayoutViewAdapter inherited;
	
private:
	System::UnicodeString __fastcall GetCaptionSeparator(void);
	Cxgridcardview::TcxGridCard* __fastcall GetCard(int Index);
	bool __fastcall GetCardAutoWidth(void);
	int __fastcall GetCardCaptionWidth(void);
	int __fastcall GetCardCount(void);
	Cxgridcardview::TcxGridCardViewRow* __fastcall GetCardRow(int Index);
	int __fastcall GetCardRowCount(void);
	int __fastcall GetCardSeparatorColor(void);
	int __fastcall GetCardSeparatorThickness(void);
	int __fastcall GetCardWidth(void);
	bool __fastcall GetHasCardsSeparator(void);
	bool __fastcall GetHasIndent(int Index);
	bool __fastcall GetRowAutoHeight(void);
	bool __fastcall GetRowCaptionAutoHeight(void);
	bool __fastcall GetRowCaptionEndEllipsis(void);
	bool __fastcall GetShowRowCaption(int Index);
	bool __fastcall GetShowRowData(int Index);
	
protected:
	virtual bool __fastcall GetAreAllMasterRowsCollapsed(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, bool AIsDataCell = false);
	virtual Cxgraphics::TcxViewParams __fastcall GetCaptionRowViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcardview::TcxGridCardViewRow* ACardRow);
	virtual Cxgraphics::TcxViewParams __fastcall GetCardViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Cxgraphics::TcxViewParams __fastcall GetRowCaptionViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcardview::TcxGridCardViewRow* ACardRow);
	
public:
	HIDESBASE Cxgridcardview::TcxGridCardView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	HIDESBASE Cxgridcardview::TcxGridCardViewStyles* __fastcall Styles(void)/* overload */;
	void __fastcall GetVisibleCardRows(Cxgridcardview::TcxGridCard* ACard, System::Classes::TList* AList);
	bool __fastcall IsFirstRow(Cxgridcardview::TcxGridCardViewRow* ACardRow);
	bool __fastcall IsLastRow(Cxgridcardview::TcxGridCardViewRow* ACardRow);
	__property System::UnicodeString CaptionSeparator = {read=GetCaptionSeparator};
	__property bool CardAutoWidth = {read=GetCardAutoWidth, nodefault};
	__property int CardCaptionWidth = {read=GetCardCaptionWidth, nodefault};
	__property int CardCount = {read=GetCardCount, nodefault};
	__property int CardRowCount = {read=GetCardRowCount, nodefault};
	__property Cxgridcardview::TcxGridCardViewRow* CardRows[int Index] = {read=GetCardRow};
	__property Cxgridcardview::TcxGridCard* Cards[int Index] = {read=GetCard};
	__property int CardSeparatorColor = {read=GetCardSeparatorColor, nodefault};
	__property int CardSeparatorThickness = {read=GetCardSeparatorThickness, nodefault};
	__property int CardWidth = {read=GetCardWidth, nodefault};
	__property bool HasCardsSeparator = {read=GetHasCardsSeparator, nodefault};
	__property bool HasIndent[int Index] = {read=GetHasIndent};
	__property bool RowCaptionAutoHeight = {read=GetRowCaptionAutoHeight, nodefault};
	__property bool RowCaptionEndEllipsis = {read=GetRowCaptionEndEllipsis, nodefault};
	__property bool RowAutoHeight = {read=GetRowAutoHeight, nodefault};
	__property bool ShowRowCaption[int Index] = {read=GetShowRowCaption};
	__property bool ShowRowData[int Index] = {read=GetShowRowData};
public:
	/* TdxCustomGridTableViewAdapter.Create */ inline __fastcall virtual TdxGridCardViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridCustomLayoutViewAdapter(AMasterAdapter, AGridView) { }
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridCardViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridCustomLayoutViewFormatter;
class DELPHICLASS TdxGridCustomLayoutViewBuilder;
class PASCALIMPLEMENTATION TdxGridCustomLayoutViewFormatter : public TdxCustomGridTableViewFormatter
{
	typedef TdxCustomGridTableViewFormatter inherited;
	
private:
	HIDESBASE Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* __fastcall GetRecord(int Index);
	
protected:
	virtual void __fastcall AddHorizontalDelimiters(void);
	virtual int __fastcall GetViewWidth(void);
	virtual bool __fastcall GetCardAutoWidth(void);
	virtual int __fastcall GetFirstRecordOffset(void);
	virtual int __fastcall GetInterRecordsSpaceHorz(void);
	virtual int __fastcall GetInterRecordsSpaceVert(void);
	virtual int __fastcall GetRecordsAreaWidth(void);
	
public:
	HIDESBASE TdxGridCustomLayoutViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridCustomLayoutViewBuilder* __fastcall Builder(void)/* overload */;
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetItemViewParams(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, bool AnIsPreview = false, bool AIsDataCell = false);
	virtual TdxReportCustomLayoutRecordClass __fastcall GetRecordClass(Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord);
	virtual void __fastcall DoInitializeRecord(TdxReportCustomLayoutRecord* ARecord, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord);
	virtual void __fastcall DoInitializeRecordRow(Dxpscore::TdxReportCell* ARecord);
	__property bool CardAutoWidth = {read=GetCardAutoWidth, nodefault};
	__property Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* Records[int Index] = {read=GetRecord};
public:
	/* TdxCustomGridTableViewFormatter.Create */ inline __fastcall virtual TdxGridCustomLayoutViewFormatter(TdxCustomGridViewBuilder* ABuilder) : TdxCustomGridTableViewFormatter(ABuilder) { }
	/* TdxCustomGridTableViewFormatter.Destroy */ inline __fastcall virtual ~TdxGridCustomLayoutViewFormatter(void) { }
	
};


class DELPHICLASS TdxGridCardViewFormatter;
class PASCALIMPLEMENTATION TdxGridCardViewFormatter : public TdxGridCustomLayoutViewFormatter
{
	typedef TdxGridCustomLayoutViewFormatter inherited;
	
private:
	HIDESBASE bool __fastcall GetAutoWidth(void);
	bool __fastcall GetCaptionAutoWidth(void);
	Cxgridcardview::TcxGridCard* __fastcall GetCard(int Index);
	int __fastcall GetCardCount(void);
	bool __fastcall GetKeepSameHeight(void);
	bool __fastcall GetKeepSameWidth(void);
	bool __fastcall GetRowAutoHeight(void);
	
protected:
	virtual bool __fastcall GetCardAutoWidth(void);
	virtual int __fastcall GetFirstRecordOffset(void);
	virtual int __fastcall GetInterRecordsSpaceHorz(void);
	virtual int __fastcall GetInterRecordsSpaceVert(void);
	virtual int __fastcall GetContentBackgroundBitmapStyleIndex(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem);
	bool __fastcall IsHorizontalLayout(Cxgridcardview::TcxGridCard* AGridCard);
	virtual int __fastcall MapStyleBackgroundBitmapIndex(int AGridBackgroundBitmapIndex);
	virtual bool __fastcall NeedDelimitByRows(void);
	
public:
	HIDESBASE TdxGridCardViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridCardViewBuilder* __fastcall Builder(void)/* overload */;
	virtual void __fastcall DoInitializeRecord(TdxReportCustomLayoutRecord* ARecord, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord);
	virtual TdxReportCustomLayoutRecordClass __fastcall GetRecordClass(Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetCardViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoInitializeCardRowIndent(Dxpscore::TdxReportCellExpandButton* AnItem, Cxgridcardview::TcxGridCardViewRow* ACardRow, Cxgridcardview::TcxGridCard* AGridCard);
	virtual void __fastcall DoInitializeCardRowCaption(Dxpscore::TdxReportCellText* AnItem, Cxgridcardview::TcxGridCardViewRow* ACardRow, Cxgridcardview::TcxGridCard* AGridCard);
	virtual void __fastcall DoReportLinkInitializeCardRowCaption(Dxpscore::TdxReportCellText* AnItem, Cxgridcardview::TcxGridCardViewRow* ACardRow, Cxgridcardview::TcxGridCard* AGridCard);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetCardRowCaptionClass(Cxgridcardview::TcxGridCardViewRow* ACardRow);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetCardRowCaptionViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcardview::TcxGridCardViewRow* ACardRow);
	virtual void __fastcall DoReportLinkInitializeCardRowData(Dxpscore::TAbstractdxReportCellData* AnItem, Cxgridcardview::TcxGridCardViewRow* ACardRow, Cxgridcardview::TcxGridCard* AGridCard);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetItemViewParams(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, bool AnIsPreview = false, bool AIsDataCell = false);
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property bool CaptionAutoWidth = {read=GetCaptionAutoWidth, nodefault};
	__property int CardCount = {read=GetCardCount, nodefault};
	__property Cxgridcardview::TcxGridCard* Cards[int Index] = {read=GetCard};
	__property bool KeepSameHeight = {read=GetKeepSameHeight, nodefault};
	__property bool KeepSameWidth = {read=GetKeepSameWidth, nodefault};
	__property bool RowAutoHeight = {read=GetRowAutoHeight, nodefault};
public:
	/* TdxCustomGridTableViewFormatter.Create */ inline __fastcall virtual TdxGridCardViewFormatter(TdxCustomGridViewBuilder* ABuilder) : TdxGridCustomLayoutViewFormatter(ABuilder) { }
	/* TdxCustomGridTableViewFormatter.Destroy */ inline __fastcall virtual ~TdxGridCardViewFormatter(void) { }
	
};


class DELPHICLASS TdxGridCustomLayoutViewRecordProducer;
class PASCALIMPLEMENTATION TdxGridCustomLayoutViewBuilder : public TdxCustomGridTableViewBuilder
{
	typedef TdxCustomGridTableViewBuilder inherited;
	
private:
	int FMaxRecordWidth;
	System::Classes::TList* FRecords;
	TdxReportCustomLayoutRecord* __fastcall GetRecord(int Index);
	int __fastcall GetRecordCount(void);
	
protected:
	virtual void __fastcall DoBuildViewBody(void);
	virtual void __fastcall CreateRecords(void);
	virtual void __fastcall PlaceRecords(void);
	virtual void __fastcall DoResizeRecords(void);
	void __fastcall ResizeRecords(void);
	void __fastcall SetSameRecordsWidth(int AWidth);
	virtual void __fastcall CalculateMaxRecordWidth(void);
	TdxGridCustomLayoutViewRecordProducer* __fastcall GetRecordProducer(void);
	virtual TdxGridCustomLayoutViewRecordProducerClass __fastcall GetRecordProducerClass(void);
	virtual Dxpscore::TdxReportCell* __fastcall CreateRecord(Dxpscore::TdxReportCell* AParent, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* ARecord);
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property TdxReportCustomLayoutRecord* Records[int Index] = {read=GetRecord};
	
public:
	__fastcall virtual TdxGridCustomLayoutViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TdxGridCustomLayoutViewBuilder(void);
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
	HIDESBASE TdxGridCustomLayoutViewFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TdxGridViewFormatterClass __fastcall FormatterClass();
	__property int MaxRecordWidth = {read=FMaxRecordWidth, nodefault};
};


class DELPHICLASS TdxGridCardViewCardsRowProducer;
class PASCALIMPLEMENTATION TdxGridCardViewBuilder : public TdxGridCustomLayoutViewBuilder
{
	typedef TdxGridCustomLayoutViewBuilder inherited;
	
private:
	TdxReportCard* __fastcall GetCard(int Index);
	int __fastcall GetCardCount(void);
	void __fastcall AdjustCardRowsCellSides(void);
	
protected:
	virtual void __fastcall DoBuildViewBody(void);
	HIDESBASE TdxGridCardViewCardsRowProducer* __fastcall GetRecordProducer(void)/* overload */;
	virtual TdxGridCustomLayoutViewRecordProducerClass __fastcall GetRecordProducerClass(void);
	virtual void __fastcall DoResizeRecords(void);
	HIDESBASE Cxgridcardview::TcxGridCardView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	__property int CardCount = {read=GetCardCount, nodefault};
	__property TdxReportCard* Cards[int Index] = {read=GetCard};
	
public:
	HIDESBASE TdxGridCardViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
	HIDESBASE TdxGridCardViewFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TdxGridViewFormatterClass __fastcall FormatterClass();
public:
	/* TdxGridCustomLayoutViewBuilder.Create */ inline __fastcall virtual TdxGridCardViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridCustomLayoutViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxGridCustomLayoutViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridCardViewBuilder(void) { }
	
};


class DELPHICLASS TdxGridDBCardViewAdapter;
class PASCALIMPLEMENTATION TdxGridDBCardViewAdapter : public TdxGridCardViewAdapter
{
	typedef TdxGridCardViewAdapter inherited;
	
protected:
	HIDESBASE Cxgriddbdatadefinitions::TcxGridDBDataController* __fastcall DataController(void)/* overload */;
	virtual Cxdbdata::TcxDBDataModeController* __fastcall DBDataModeController(void);
	
public:
	HIDESBASE Cxgriddbcardview::TcxGridDBCardView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
public:
	/* TdxCustomGridTableViewAdapter.Create */ inline __fastcall virtual TdxGridDBCardViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridCardViewAdapter(AMasterAdapter, AGridView) { }
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridDBCardViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridDBCardViewBuilder;
class PASCALIMPLEMENTATION TdxGridDBCardViewBuilder : public TdxGridCardViewBuilder
{
	typedef TdxGridCardViewBuilder inherited;
	
public:
	HIDESBASE TdxGridDBCardViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
public:
	/* TdxGridCustomLayoutViewBuilder.Create */ inline __fastcall virtual TdxGridDBCardViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridCardViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxGridCustomLayoutViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridDBCardViewBuilder(void) { }
	
};


class DELPHICLASS TdxGridChartViewAdapter;
class PASCALIMPLEMENTATION TdxGridChartViewAdapter : public TdxCustomGridViewAdapter
{
	typedef TdxCustomGridViewAdapter inherited;
	
protected:
	Vcl::Graphics::TGraphic* __fastcall CreateGraphic(Vcl::Graphics::TGraphicClass AGraphicClass, int AWidth);
	virtual bool __fastcall GetCanUseOnEveryPageMode(void);
	
public:
	HIDESBASE Cxgridchartview::TcxGridChartView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
public:
	/* TdxCustomGridViewAdapter.Create */ inline __fastcall virtual TdxGridChartViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxCustomGridViewAdapter(AMasterAdapter, AGridView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridChartViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridChartViewFormatter;
class DELPHICLASS TdxGridChartViewBuilder;
class PASCALIMPLEMENTATION TdxGridChartViewFormatter : public TdxCustomGridViewFormatter
{
	typedef TdxCustomGridViewFormatter inherited;
	
private:
	Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(void);
	bool __fastcall GetGraphicTransparent(void);
	
protected:
	virtual Vcl::Graphics::TGraphic* __fastcall CreateChartImage(void);
	virtual void __fastcall DoInitializeChartItem(Dxpscore::TdxReportCellGraphic* AnItem);
	virtual void __fastcall DoReportLinkInitializeChartItem(Dxpscore::TdxReportCellGraphic* AnItem);
	Dxpscore::TdxReportCellGraphicClass __fastcall GetChartItemClass(void);
	virtual int __fastcall GetViewWidth(void);
	
public:
	HIDESBASE TdxGridChartViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridChartViewBuilder* __fastcall Builder(void)/* overload */;
	__property Vcl::Graphics::TGraphicClass GraphicClass = {read=GetGraphicClass};
	__property bool GraphicTransparent = {read=GetGraphicTransparent, nodefault};
public:
	/* TdxCustomGridViewFormatter.Create */ inline __fastcall virtual TdxGridChartViewFormatter(TdxCustomGridViewBuilder* ABuilder) : TdxCustomGridViewFormatter(ABuilder) { }
	/* TdxCustomGridViewFormatter.Destroy */ inline __fastcall virtual ~TdxGridChartViewFormatter(void) { }
	
};


class DELPHICLASS TdxGridChartViewChartProducer;
class PASCALIMPLEMENTATION TdxGridChartViewBuilder : public TdxCustomGridViewBuilder
{
	typedef TdxCustomGridViewBuilder inherited;
	
protected:
	virtual TdxGridChartViewChartProducer* __fastcall GetChartProducer(void);
	virtual TdxGridChartViewChartProducerClass __fastcall GetChartProducerClass(void);
	virtual void __fastcall CreateChart(void);
	virtual void __fastcall DoBuildViewBody(void);
	HIDESBASE Cxgridchartview::TcxGridChartView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	
public:
	HIDESBASE TdxGridChartViewAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TdxGridViewAdapterClass __fastcall AdapterClass();
	HIDESBASE TdxGridChartViewFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TdxGridViewFormatterClass __fastcall FormatterClass();
public:
	/* TdxCustomGridViewBuilder.Create */ inline __fastcall virtual TdxGridChartViewBuilder(TdxGridReportLink* AReportLink, TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxCustomGridViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxCustomGridViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridChartViewBuilder(void) { }
	
};


class DELPHICLASS TdxGridAttributeHostInfo;
class PASCALIMPLEMENTATION TdxGridViewRowProducer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomGridViewBuilder* FBuilder;
	Dxpscore::TdxReportCell* FHost;
	System::Classes::TList* FMasterIndents;
	Dxpscore::TdxReportCell* FRow;
	int FRowHeight;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetCanvas(void);
	Dxpscore::TdxReportCellClass __fastcall GetHostClass(void);
	int __fastcall GetIndentWidth(void);
	TdxCustomGridViewBuilder* __fastcall GetMasterBuilder(int Index);
	Dxpscore::TdxReportCellBox* __fastcall GetMasterIndent(int Index);
	int __fastcall GetMasterIndentCount(void);
	Dxpscore::TdxReportCellClass __fastcall GetRowHostClass(void);
	int __fastcall GetRowOriginX(void);
	int __fastcall GetRowWidth(void);
	
protected:
	virtual void __fastcall AddLeadingMasterIndentsAndSeparators(void);
	void __fastcall AddMasterIndents(TdxCustomGridViewFormatter* AMasterFormatter, TdxCustomGridViewAdapter* AMasterAdapter, int ALevel, int &ALeftPos);
	void __fastcall AddMasterSeparator(TdxCustomGridViewFormatter* AMasterFormatter, TdxCustomGridViewAdapter* AMasterAdapter, int &ALeftPos, TdxVerticalDetailsSeparatorKind ASeparatorKind);
	virtual void __fastcall AddTrailingMasterSeparators(void);
	virtual int __fastcall CalculateItemHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall CalculateRowAutoHeight(void);
	virtual void __fastcall CalculateRowHeight(void);
	virtual Dxpscore::TdxReportCellBox* __fastcall CreateDetailsSeparator(Dxpscore::TdxReportCell* AParent);
	virtual Dxpscore::TdxReportCellExpandButton* __fastcall CreateMasterIndent(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateRow(void);
	virtual void __fastcall CreateRowHost(TdxGridAttributeHostInfo* const AHostInfo);
	virtual bool __fastcall DoesItemParticipateInRowAutoHeightCalculation(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportCellBoxClass __fastcall GetDetailsSeparatorClass(void);
	virtual Dxpscore::TdxReportCellExpandButtonClass __fastcall GetMasterIndentClass(void);
	virtual void __fastcall FixupMasterIndentsHeight(void);
	virtual void __fastcall FixupRowDataItemHeight(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall FixupRowDataHeight(void);
	virtual void __fastcall FixupRowHeight(void);
	virtual void __fastcall FixupRowOwnHeight(void);
	virtual void __fastcall InitializeDetailsSeparator(TdxCustomGridViewFormatter* AFormatter, Dxpscore::TdxReportCellBox* ASeparator, TdxVerticalDetailsSeparatorKind ASeparatorKind);
	virtual void __fastcall InitializeMasterIndent(TdxCustomGridViewFormatter* AFormatter, Dxpscore::TdxReportCellExpandButton* AIndent, int AIndex, int ALevel);
	virtual void __fastcall InitializeHost(void);
	virtual void __fastcall InitializeRow(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Dxpscore::TdxReportCell* __fastcall GetItemsSite(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual int __fastcall GetWidth(void);
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* Canvas = {read=GetCanvas};
	__property Dxpscore::TdxReportCellClass HostClass = {read=GetHostClass};
	
public:
	__fastcall virtual TdxGridViewRowProducer(TdxCustomGridViewBuilder* ABuilder);
	__fastcall virtual ~TdxGridViewRowProducer(void);
	virtual TdxCustomGridViewAdapter* __fastcall Adapter(void)/* overload */;
	virtual TdxCustomGridViewBuilder* __fastcall Builder(void)/* overload */;
	virtual TdxCustomGridViewFormatter* __fastcall Formatter(void)/* overload */;
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo);
	__property bool AutoHeight = {read=GetAutoHeight, nodefault};
	__property Dxpscore::TdxReportCell* Host = {read=FHost};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property Dxpscore::TdxReportCell* ItemsSite = {read=GetItemsSite};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int LineHeight = {read=GetLineHeight, nodefault};
	__property TdxCustomGridViewBuilder* MasterBuilders[int Index] = {read=GetMasterBuilder};
	__property int MasterIndentCount = {read=GetMasterIndentCount, nodefault};
	__property Dxpscore::TdxReportCellBox* MasterIndents[int Index] = {read=GetMasterIndent};
	__property Dxpscore::TdxReportCell* Row = {read=FRow};
	__property int RowHeight = {read=FRowHeight, write=FRowHeight, nodefault};
	__property int RowOriginX = {read=GetRowOriginX, nodefault};
	__property int RowWidth = {read=GetRowWidth, nodefault};
	__property int Width = {read=GetWidth, nodefault};
};


class DELPHICLASS TdxGridViewCustomRowProducer;
class PASCALIMPLEMENTATION TdxGridViewCustomRowProducer : public TdxGridViewRowProducer
{
	typedef TdxGridViewRowProducer inherited;
	
private:
	Dxpscore::TAbstractdxReportCellData* FItem;
	
protected:
	virtual void __fastcall AddItem(void);
	virtual Dxpscore::TAbstractdxReportCellData* __fastcall CreateItem(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall FixupRowDataHeight(void);
	virtual void __fastcall InitializeItem(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetItemClass(void);
	__property Dxpscore::TAbstractdxReportCellData* Item = {read=FItem};
	
public:
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo);
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridViewCustomRowProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewRowProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridViewCustomRowProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridViewCaptionProducer : public TdxGridViewCustomRowProducer
{
	typedef TdxGridViewCustomRowProducer inherited;
	
private:
	Dxpscore::TdxReportCellText* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall InitializeItem(void);
	virtual void __fastcall InitializeRow(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetItemClass(void);
	virtual int __fastcall GetLineHeight(void);
	
public:
	__property Dxpscore::TdxReportCellText* Item = {read=GetItem};
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridViewCaptionProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewCustomRowProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridViewCaptionProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridViewFilterBarProducer : public TdxGridViewCustomRowProducer
{
	typedef TdxGridViewCustomRowProducer inherited;
	
private:
	Dxpscore::TdxReportCellText* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall InitializeItem(void);
	virtual void __fastcall InitializeRow(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetItemClass(void);
	virtual int __fastcall GetLineHeight(void);
	
public:
	__property Dxpscore::TdxReportCellText* Item = {read=GetItem};
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridViewFilterBarProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewCustomRowProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridViewFilterBarProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridViewDetailsSeparatorProducer : public TdxGridViewCustomRowProducer
{
	typedef TdxGridViewCustomRowProducer inherited;
	
private:
	Dxpscore::TdxReportCellBox* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall InitializeItem(void);
	virtual void __fastcall InitializeRow(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetItemClass(void);
	virtual int __fastcall GetLineHeight(void);
	
public:
	__property Dxpscore::TdxReportCellBox* Item = {read=GetItem};
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridViewDetailsSeparatorProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewCustomRowProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridViewDetailsSeparatorProducer(void) { }
	
};


class DELPHICLASS TdxGridViewDetailsTopSeparatorProducer;
class PASCALIMPLEMENTATION TdxGridViewDetailsTopSeparatorProducer : public TdxGridViewDetailsSeparatorProducer
{
	typedef TdxGridViewDetailsSeparatorProducer inherited;
	
protected:
	virtual void __fastcall InitializeDetailsSeparator(TdxCustomGridViewFormatter* AFormatter, Dxpscore::TdxReportCellBox* ASeparator, TdxVerticalDetailsSeparatorKind ASeparatorKind);
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridViewDetailsTopSeparatorProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewDetailsSeparatorProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridViewDetailsTopSeparatorProducer(void) { }
	
};


class DELPHICLASS TdxGridViewDetailsBottomSeparatorProducer;
class PASCALIMPLEMENTATION TdxGridViewDetailsBottomSeparatorProducer : public TdxGridViewDetailsSeparatorProducer
{
	typedef TdxGridViewDetailsSeparatorProducer inherited;
	
protected:
	virtual void __fastcall InitializeDetailsSeparator(TdxCustomGridViewFormatter* AFormatter, Dxpscore::TdxReportCellBox* ASeparator, TdxVerticalDetailsSeparatorKind ASeparatorKind);
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridViewDetailsBottomSeparatorProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewDetailsSeparatorProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridViewDetailsBottomSeparatorProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridViewTerminatorProducer : public TdxGridViewDetailsSeparatorProducer
{
	typedef TdxGridViewDetailsSeparatorProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(void);
	virtual int __fastcall GetLineHeight(void);
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridViewTerminatorProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewDetailsSeparatorProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridViewTerminatorProducer(void) { }
	
};


class DELPHICLASS TdxGridTableViewRowProducer;
class PASCALIMPLEMENTATION TdxGridTableViewRowProducer : public TdxGridViewRowProducer
{
	typedef TdxGridViewRowProducer inherited;
	
public:
	HIDESBASE TdxGridTableViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridTableViewBuilder* __fastcall Builder(void)/* overload */;
	HIDESBASE TdxGridTableViewFormatter* __fastcall Formatter(void)/* overload */;
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridTableViewRowProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewRowProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewRowProducer(void) { }
	
};


class DELPHICLASS TdxGridTableViewRowSubItemsProducer;
class PASCALIMPLEMENTATION TdxGridTableViewRowSubItemsProducer : public TdxGridTableViewRowProducer
{
	typedef TdxGridTableViewRowProducer inherited;
	
public:
	Dxpscore::TdxReportVisualItem* operator[](int Index) { return SubItems[Index]; }
	
private:
	System::Classes::TList* FIndents;
	System::Classes::TList* FSubItems;
	Cxgridtableview::TcxGridColumn* __fastcall GetColumn(int Index);
	Dxpscore::TdxReportCellExpandButton* __fastcall GetIndent(int Index);
	Dxpscore::TdxReportVisualItem* __fastcall GetSubItem(int Index);
	
protected:
	virtual void __fastcall AddIndents(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall AddSubItems(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateRow(void);
	Dxpscore::TAbstractdxReportCellData* __fastcall CreateSubItem(int AnIndex, Dxpscore::TdxReportCell* AParent);
	bool __fastcall IsItemIndent(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall FixupIndentsHeight(void);
	virtual void __fastcall FixupRowDataHeight(void);
	virtual void __fastcall FixupRowHeight(void);
	virtual void __fastcall InitializeIndentList(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual void __fastcall InitializeSubItemList(void);
	virtual bool __fastcall GetHasSubItem(int Index);
	virtual int __fastcall GetIndentCount(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index) = 0 ;
	virtual int __fastcall GetSubItemCount(void);
	
public:
	__fastcall virtual TdxGridTableViewRowSubItemsProducer(TdxCustomGridViewBuilder* ABuilder);
	__fastcall virtual ~TdxGridTableViewRowSubItemsProducer(void);
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo);
	__property Cxgridtableview::TcxGridColumn* Columns[int Index] = {read=GetColumn};
	__property bool HasSubItem[int Index] = {read=GetHasSubItem};
	__property int IndentCount = {read=GetIndentCount, nodefault};
	__property Dxpscore::TdxReportCellExpandButton* Indents[int Index] = {read=GetIndent};
	__property System::Types::TRect SubItemBounds[int Index] = {read=GetSubItemBound};
	__property Dxpscore::TdxReportCellDataClass SubItemClasses[int Index] = {read=GetSubItemClass};
	__property int SubItemCount = {read=GetSubItemCount, nodefault};
	__property Dxpscore::TdxReportVisualItem* SubItems[int Index] = {read=GetSubItem/*, default*/};
};


class PASCALIMPLEMENTATION TdxGridTableViewHeadersProducer : public TdxGridTableViewRowSubItemsProducer
{
	typedef TdxGridTableViewRowSubItemsProducer inherited;
	
protected:
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewHeadersProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewRowSubItemsProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewHeadersProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridTableViewFootersProducer : public TdxGridTableViewRowSubItemsProducer
{
	typedef TdxGridTableViewRowSubItemsProducer inherited;
	
private:
	virtual Cxcustomdata::TcxDataSummaryItems* __fastcall GetSummaryItems(void);
	
protected:
	virtual void __fastcall CalculateRowAutoHeight(void);
	virtual void __fastcall CalculateRowHeight(void);
	virtual void __fastcall FixupRowDataItemHeight(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual bool __fastcall GetAutoHeight(void);
	virtual bool __fastcall GetHasSubItem(int Index);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
	virtual int __fastcall GetSubItemCount(void);
	__property Cxcustomdata::TcxDataSummaryItems* SummaryItems = {read=GetSummaryItems};
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewFootersProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewRowSubItemsProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewFootersProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridTableViewCustomDataRowProducer : public TdxGridTableViewRowSubItemsProducer
{
	typedef TdxGridTableViewRowSubItemsProducer inherited;
	
private:
	Cxgridtableview::TcxCustomGridRow* FGridRow;
	int FGridRowIndex;
	int __fastcall GetIndentArea(void);
	System::Types::TRect __fastcall GetIndentBounds(int Index);
	
protected:
	virtual void __fastcall AddIndents(Dxpscore::TdxReportCell* AParent);
	virtual Dxpscore::TdxReportCellExpandButton* __fastcall CreateIndent(int AnIndex, Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AIndent, int AIndex);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	
public:
	virtual Cxgridtableview::TcxCustomGridRow* __fastcall GridRow(void)/* overload */;
	HIDESBASE virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo, Cxgridtableview::TcxCustomGridRow* AGridRow, int AGridRowIndex);
	__property int GridRowIndex = {read=FGridRowIndex, nodefault};
	__property int IndentArea = {read=GetIndentArea, nodefault};
	__property System::Types::TRect IndentBounds[int Index] = {read=GetIndentBounds};
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewCustomDataRowProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewRowSubItemsProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewCustomDataRowProducer(void) { }
	
};


class DELPHICLASS TdxCustomGridTableViewRowSeparatorProducer;
class PASCALIMPLEMENTATION TdxCustomGridTableViewRowSeparatorProducer : public TdxGridTableViewCustomDataRowProducer
{
	typedef TdxGridTableViewCustomDataRowProducer inherited;
	
protected:
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AIndent, int AIndex);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetSubItemCount(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	
public:
	HIDESBASE virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo, Cxgridtableview::TcxCustomGridRow* AGridRow);
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxCustomGridTableViewRowSeparatorProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewCustomDataRowProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxCustomGridTableViewRowSeparatorProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridTableViewRowSeparatorProducer : public TdxCustomGridTableViewRowSeparatorProducer
{
	typedef TdxCustomGridTableViewRowSeparatorProducer inherited;
	
private:
	bool FIsLast;
	
protected:
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
	
public:
	HIDESBASE virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo, Cxgridtableview::TcxCustomGridRow* AGridRow, bool AnIsLast);
	__property bool IsLast = {read=FIsLast, nodefault};
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewRowSeparatorProducer(TdxCustomGridViewBuilder* ABuilder) : TdxCustomGridTableViewRowSeparatorProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewRowSeparatorProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridTableViewGroupRowSeparatorProducer : public TdxCustomGridTableViewRowSeparatorProducer
{
	typedef TdxCustomGridTableViewRowSeparatorProducer inherited;
	
protected:
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual int __fastcall GetLineHeight(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewGroupRowSeparatorProducer(TdxCustomGridViewBuilder* ABuilder) : TdxCustomGridTableViewRowSeparatorProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewGroupRowSeparatorProducer(void) { }
	
};


class DELPHICLASS TdxGridTableViewDataRowProducer;
class PASCALIMPLEMENTATION TdxGridTableViewDataRowProducer : public TdxGridTableViewCustomDataRowProducer
{
	typedef TdxGridTableViewCustomDataRowProducer inherited;
	
private:
	Dxpscore::TdxReportVisualItem* FPreviewItem;
	Cxgridtableview::TcxGridColumn* __fastcall GetPreviewColumn(void);
	Cxgridtableview::TcxGridPreviewPlace __fastcall GetPreviewPlace(void);
	
protected:
	virtual void __fastcall AddPreview(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall AddSubItems(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CalculateRowAutoHeight(void);
	virtual bool __fastcall DoesItemParticipateInRowAutoHeightCalculation(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItem* __fastcall CreatePreview(Dxpscore::TdxReportCell* AParent);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetPreviewClass(void);
	virtual void __fastcall FixupRowDataHeight(void);
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AIndent, int AIndex);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual bool __fastcall GetAutoHeight(void);
	virtual bool __fastcall GetCellAutoHeight(void);
	virtual bool __fastcall GetHasPreview(void);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual int __fastcall GetPreviewHeight(void);
	virtual int __fastcall GetPreviewLineCount(void);
	virtual int __fastcall GetPreviewLineHeight(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
	
public:
	HIDESBASE Cxgridtableview::TcxGridDataRow* __fastcall GridRow(void)/* overload */;
	__property bool CellAutoHeight = {read=GetCellAutoHeight, nodefault};
	__property bool HasPreview = {read=GetHasPreview, nodefault};
	__property Cxgridtableview::TcxGridColumn* PreviewColumn = {read=GetPreviewColumn};
	__property int PreviewHeight = {read=GetPreviewHeight, nodefault};
	__property Dxpscore::TdxReportVisualItem* PreviewItem = {read=FPreviewItem};
	__property int PreviewLineCount = {read=GetPreviewLineCount, nodefault};
	__property int PreviewLineHeight = {read=GetPreviewLineHeight, nodefault};
	__property Cxgridtableview::TcxGridPreviewPlace PreviewPlace = {read=GetPreviewPlace, nodefault};
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewDataRowProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewCustomDataRowProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewDataRowProducer(void) { }
	
};


class DELPHICLASS TcxGridSummaryItemInfo;
class PASCALIMPLEMENTATION TcxGridSummaryItemInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TRect Bounds;
	Cxgridtableview::TcxGridColumn* Column;
	System::UnicodeString DisplayText;
	int SummaryIndex;
	Cxgraphics::TcxViewParams ViewParams;
public:
	/* TObject.Create */ inline __fastcall TcxGridSummaryItemInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridSummaryItemInfo(void) { }
	
};


class DELPHICLASS TdxGridTableViewGroupRowProducer;
class PASCALIMPLEMENTATION TdxGridTableViewGroupRowProducer : public TdxGridTableViewCustomDataRowProducer
{
	typedef TdxGridTableViewCustomDataRowProducer inherited;
	
private:
	TcxGridSummaryItemInfo* __fastcall GetSummaryItemInfo(int Index);
	
protected:
	Cxclasses::TcxObjectList* SummaryItemInfoList;
	Cxgraphics::TcxViewParams RowViewParams;
	bool __fastcall AddSummaryGroupInfo(Cxcustomdata::TcxDataSummaryItem* AItem, const System::UnicodeString ADisplayText);
	virtual void __fastcall AddSubItems(Dxpscore::TdxReportCell* AParent);
	void __fastcall DeleteInfo(int AIndex);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AIndent, int AIndex);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual void __fastcall InitializeSubItemList(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
	virtual int __fastcall GetSubItemCount(void);
	void __fastcall PrepareSummaryItemsInfo(void);
	void __fastcall PrepareSummaryItemsBounds(void);
	
public:
	HIDESBASE Cxgridtableview::TcxGridGroupRow* __fastcall GridRow(void)/* overload */;
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo, Cxgridtableview::TcxCustomGridRow* AGridRow, int AGridRowIndex);
	__property TcxGridSummaryItemInfo* SummaryItemInfos[int Index] = {read=GetSummaryItemInfo};
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewGroupRowProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewCustomDataRowProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewGroupRowProducer(void) { }
	
};


class DELPHICLASS TdxGridTableViewMasterRowProducer;
class PASCALIMPLEMENTATION TdxGridTableViewMasterRowProducer : public TdxGridTableViewDataRowProducer
{
	typedef TdxGridTableViewDataRowProducer inherited;
	
protected:
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AIndent, int AIndex);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual int __fastcall GetIndentCount(void);
	
public:
	HIDESBASE Cxgridtableview::TcxGridMasterDataRow* __fastcall GridRow(void)/* overload */;
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewMasterRowProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewDataRowProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewMasterRowProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridTableViewGroupFooterProducer : public TdxGridTableViewCustomDataRowProducer
{
	typedef TdxGridTableViewCustomDataRowProducer inherited;
	
private:
	int FGroupLevel;
	int FIndex;
	int FInternalLineCount;
	Dxpscore::TdxReportCell* FItemsSite;
	int __fastcall GetGroupLevel(void);
	System::Types::TRect __fastcall GetHostBounds(void);
	
protected:
	Cxcustomdata::TcxDataSummaryItems* SummaryItems;
	System::Variant *SummaryValues;
	virtual void __fastcall AddSubItems(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CalculateRowAutoHeight(void);
	virtual void __fastcall FixupRowDataItemHeight(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AIndent, int AIndex);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual bool __fastcall GetAutoHeight(void);
	int __fastcall GetCorrectRowIndex(Cxgridtableview::TcxCustomGridRow* AGridRow, int AGroupLevel);
	virtual bool __fastcall GetHasSubItem(int Index);
	virtual int __fastcall GetIndentCount(void);
	virtual Dxpscore::TdxReportCell* __fastcall GetItemsSite(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
	virtual int __fastcall GetSubItemCount(void);
	
public:
	HIDESBASE virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo, Cxgridtableview::TcxCustomGridRow* AGridRow, int AGroupLevel, int AnIndex);
	__property int GroupLevel = {read=GetGroupLevel, nodefault};
	__property System::Types::TRect HostBounds = {read=GetHostBounds};
	__property int Index = {read=FIndex, nodefault};
	__property int InternalLineCount = {read=FInternalLineCount, nodefault};
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewGroupFooterProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewCustomDataRowProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewGroupFooterProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridTableViewBandsProducer : public TdxGridTableViewRowSubItemsProducer
{
	typedef TdxGridTableViewRowSubItemsProducer inherited;
	
protected:
	virtual void __fastcall CalculateRowHeight(void);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AIndex);
	virtual bool __fastcall GetAutoHeight(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
	virtual int __fastcall GetSubItemCount(void);
	
public:
	HIDESBASE TdxGridBandedTableViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridBandedTableViewBuilder* __fastcall Builder(void)/* overload */;
	HIDESBASE TdxGridBandedTableViewFormatter* __fastcall Formatter(void)/* overload */;
public:
	/* TdxGridTableViewRowSubItemsProducer.Create */ inline __fastcall virtual TdxGridTableViewBandsProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridTableViewRowSubItemsProducer(ABuilder) { }
	/* TdxGridTableViewRowSubItemsProducer.Destroy */ inline __fastcall virtual ~TdxGridTableViewBandsProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridCustomLayoutViewRecordProducer : public TdxGridViewRowProducer
{
	typedef TdxGridViewRowProducer inherited;
	
protected:
	virtual void __fastcall CalculateRowHeight(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual void __fastcall InitializeRow(void);
	
public:
	HIDESBASE TdxGridCustomLayoutViewBuilder* __fastcall Builder(void)/* overload */;
	HIDESBASE TdxGridCustomLayoutViewFormatter* __fastcall Formatter(void)/* overload */;
	virtual TdxReportCustomLayoutRecord* __fastcall CreateRecord(Dxpscore::TdxReportCell* AParent, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord);
	HIDESBASE virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo, int ARowHeight);
	virtual void __fastcall InjectRecord(TdxReportCustomLayoutRecord* ARecord, int AIndex);
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridCustomLayoutViewRecordProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewRowProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridCustomLayoutViewRecordProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridCardViewCardsRowProducer : public TdxGridCustomLayoutViewRecordProducer
{
	typedef TdxGridCustomLayoutViewRecordProducer inherited;
	
public:
	HIDESBASE TdxGridCardViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridCardViewBuilder* __fastcall Builder(void)/* overload */;
	HIDESBASE TdxGridCardViewFormatter* __fastcall Formatter(void)/* overload */;
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridCardViewCardsRowProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridCustomLayoutViewRecordProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridCardViewCardsRowProducer(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridChartViewChartProducer : public TdxGridViewCustomRowProducer
{
	typedef TdxGridViewCustomRowProducer inherited;
	
private:
	Vcl::Graphics::TGraphic* FChartImage;
	Vcl::Graphics::TGraphic* __fastcall GetChartImage(void);
	Dxpscore::TdxReportCellGraphic* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall CalculateRowHeight(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetItemClass(void);
	virtual void __fastcall InitializeItem(void);
	__property Vcl::Graphics::TGraphic* ChartImage = {read=GetChartImage};
	__property Dxpscore::TdxReportCellGraphic* Item = {read=GetItem};
	
public:
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TdxGridAttributeHostInfo* AHostInfo);
	HIDESBASE TdxGridChartViewFormatter* __fastcall Formatter(void)/* overload */;
public:
	/* TdxGridViewRowProducer.Create */ inline __fastcall virtual TdxGridChartViewChartProducer(TdxCustomGridViewBuilder* ABuilder) : TdxGridViewCustomRowProducer(ABuilder) { }
	/* TdxGridViewRowProducer.Destroy */ inline __fastcall virtual ~TdxGridChartViewChartProducer(void) { }
	
};


typedef System::TMetaClass* TdxGridReportLinkOptionsClass;

class DELPHICLASS TdxGridReportLinkOptions;
class PASCALIMPLEMENTATION TdxGridReportLinkOptions : public Dxpscxcommon::TdxCustomReportLinkOptions
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptions inherited;
	
private:
	TdxGridReportLink* __fastcall GetReportLink(void);
	
public:
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptions(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptions(void) { }
	
};


typedef System::TMetaClass* TdxGridReportLinkCardsShadowClass;

class DELPHICLASS TdxGridReportLinkCardsShadow;
class DELPHICLASS TdxGridReportLinkOptionsCards;
class PASCALIMPLEMENTATION TdxGridReportLinkCardsShadow : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Uitypes::TColor FColor;
	TdxGridCardShadowDepth FDepth;
	TdxGridReportLinkOptionsCards* FOptionsCards;
	TdxGridCardShadowPosition FPosition;
	System::Uitypes::TColor __fastcall GetActualColor(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetDepth(TdxGridCardShadowDepth Value);
	void __fastcall SetPosition(TdxGridCardShadowPosition Value);
	
protected:
	DYNAMIC void __fastcall Changed(void);
	
public:
	__fastcall virtual TdxGridReportLinkCardsShadow(TdxGridReportLinkOptionsCards* AnOptionsCards);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property System::Uitypes::TColor ActualColor = {read=GetActualColor, nodefault};
	__property TdxGridReportLinkOptionsCards* OptionsCards = {read=FOptionsCards};
	__property bool Visible = {read=GetVisible, nodefault};
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property TdxGridCardShadowDepth Depth = {read=FDepth, write=SetDepth, default=4};
	__property TdxGridCardShadowPosition Position = {read=FPosition, write=SetPosition, default=2};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxGridReportLinkCardsShadow(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsCustomLayoutView;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsCustomLayoutView : public TdxGridReportLinkOptions
{
	typedef TdxGridReportLinkOptions inherited;
	
private:
	bool FAutoWidth;
	int FInterRecordsSpaceHorz;
	int FInterRecordsSpaceVert;
	void __fastcall SetAutoWidth(bool Value);
	void __fastcall SetInterRecordsSpaceHorz(int Value);
	void __fastcall SetInterRecordsSpaceVert(int Value);
	
protected:
	__property bool AutoWidth = {read=FAutoWidth, write=SetAutoWidth, default=0};
	__property int InterRecordsSpaceHorz = {read=FInterRecordsSpaceHorz, write=SetInterRecordsSpaceHorz, default=4};
	__property int InterRecordsSpaceVert = {read=FInterRecordsSpaceVert, write=SetInterRecordsSpaceVert, default=4};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsCustomLayoutView(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : TdxGridReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsCustomLayoutView(void) { }
	
};


typedef System::TMetaClass* TdxGridReportLinkOptionsCardsClass;

class PASCALIMPLEMENTATION TdxGridReportLinkOptionsCards : public TdxGridReportLinkOptionsCustomLayoutView
{
	typedef TdxGridReportLinkOptionsCustomLayoutView inherited;
	
private:
	bool FBorders;
	bool FKeepSameHeight;
	bool FKeepSameWidth;
	bool FRowBordersHorz;
	bool FRowBordersVert;
	TdxGridReportLinkCardsShadow* FShadow;
	int __fastcall GetInterCardsSpaceHorz(void);
	int __fastcall GetInterCardsSpaceVert(void);
	TdxGridReportLinkCardsShadow* __fastcall GetShadow(void);
	void __fastcall SetBorders(bool Value);
	void __fastcall SetInterCardsSpaceHorz(int Value);
	void __fastcall SetInterCardsSpaceVert(int Value);
	void __fastcall SetKeepSameHeight(bool Value);
	void __fastcall SetKeepSameWidth(bool Value);
	void __fastcall SetRowBordersHorz(bool Value);
	void __fastcall SetRowBordersVert(bool Value);
	void __fastcall SetShadow(TdxGridReportLinkCardsShadow* Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	virtual TdxGridReportLinkCardsShadowClass __fastcall GetShadowClass(void);
	
public:
	__fastcall virtual ~TdxGridReportLinkOptionsCards(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property AutoWidth = {default=0};
	__property bool Borders = {read=FBorders, write=SetBorders, default=1};
	__property int InterCardsSpaceHorz = {read=GetInterCardsSpaceHorz, write=SetInterCardsSpaceHorz, default=4};
	__property int InterCardsSpaceVert = {read=GetInterCardsSpaceVert, write=SetInterCardsSpaceVert, default=4};
	__property bool KeepSameHeight = {read=FKeepSameHeight, write=SetKeepSameHeight, default=1};
	__property bool KeepSameWidth = {read=FKeepSameWidth, write=SetKeepSameWidth, default=1};
	__property bool RowBordersHorz = {read=FRowBordersHorz, write=SetRowBordersHorz, default=0};
	__property bool RowBordersVert = {read=FRowBordersVert, write=SetRowBordersVert, default=0};
	__property TdxGridReportLinkCardsShadow* Shadow = {read=GetShadow, write=SetShadow};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsCards(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : TdxGridReportLinkOptionsCustomLayoutView(AReportLink) { }
	
};


typedef System::TMetaClass* TdxGridReportLinkOptionsChartsClass;

class DELPHICLASS TdxGridReportLinkOptionsCharts;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsCharts : public TdxGridReportLinkOptions
{
	typedef TdxGridReportLinkOptions inherited;
	
private:
	Vcl::Graphics::TGraphicClass FGraphicClass;
	bool FIsGraphicClassAssigned;
	bool FTransparent;
	Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(void);
	System::UnicodeString __fastcall GetGraphicClassName(void);
	bool __fastcall IsGraphicClassNameStored(void);
	void __fastcall SetGraphicClass(Vcl::Graphics::TGraphicClass Value);
	void __fastcall SetGraphicClassName(const System::UnicodeString Value);
	void __fastcall SetTransparent(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall DefaultGraphicClass(void);
	virtual bool __fastcall SupportsGraphicClass(Vcl::Graphics::TGraphicClass AGraphicClass);
	__property Vcl::Graphics::TGraphicClass GraphicClass = {read=GetGraphicClass, write=SetGraphicClass};
	
__published:
	__property System::UnicodeString GraphicClassName = {read=GetGraphicClassName, write=SetGraphicClassName, stored=IsGraphicClassNameStored};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsCharts(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : TdxGridReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsCharts(void) { }
	
};


typedef System::TMetaClass* TdxGridReportLinkOptionsDetailsClass;

class DELPHICLASS TdxGridReportLinkOptionsDetails;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsDetails : public TdxGridReportLinkOptions
{
	typedef TdxGridReportLinkOptions inherited;
	
private:
	bool FOnlyFocusedView;
	bool FStartFromFocusedView;
	void __fastcall SetOnlyFocusedView(bool Value);
	void __fastcall SetStartFromFocusedView(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool OnlyFocusedView = {read=FOnlyFocusedView, write=SetOnlyFocusedView, default=0};
	__property bool StartFromFocusedView = {read=FStartFromFocusedView, write=SetStartFromFocusedView, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsDetails(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : TdxGridReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsDetails(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridReportLinkOptionsExpanding : public Dxpscxcommon::TdxCustomReportLinkOptionsExpanding
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsExpanding inherited;
	
private:
	bool FExpandCards;
	bool FExpandGroupRows;
	bool FExpandMasterRows;
	bool __fastcall GetHasAny(void);
	TdxGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetExpandCards(bool Value);
	void __fastcall SetExpandGroupRows(bool Value);
	void __fastcall SetExpandMasterRows(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property bool HasAny = {read=GetHasAny, nodefault};
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool ExpandCards = {read=FExpandCards, write=SetExpandCards, default=0};
	__property bool ExpandGroupRows = {read=FExpandGroupRows, write=SetExpandGroupRows, default=0};
	__property bool ExpandMasterRows = {read=FExpandMasterRows, write=SetExpandMasterRows, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsExpanding(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsExpanding(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsExpanding(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsFormatting;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsFormatting : public Dxpscxcommon::TdxCustomReportLinkOptionsFormatting
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsFormatting inherited;
	
private:
	bool FConsumeSelectionStyle;
	TdxGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetConsumeSelectionStyle(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool ConsumeSelectionStyle = {read=FConsumeSelectionStyle, write=SetConsumeSelectionStyle, default=0};
	__property UseLookAndFeelColors = {default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsFormatting(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsFormatting(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsFormatting(void) { }
	
};


typedef System::TMetaClass* TdxGridReportLinkOptionsLevelsClass;

class DELPHICLASS TdxGridReportLinkOptionsLevels;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsLevels : public TdxGridReportLinkOptions
{
	typedef TdxGridReportLinkOptions inherited;
	
private:
	bool FRiseActiveLevelOntoTop;
	bool FSkipEmptyViews;
	bool FUnwrap;
	bool FUnwrapTopLevel;
	void __fastcall SetRiseActiveLevelOntoTop(bool Value);
	void __fastcall SetSkipEmptyViews(bool Value);
	void __fastcall SetUnwrap(bool Value);
	void __fastcall SetUnwrapTopLevel(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool RiseActiveLevelOntoTop = {read=FRiseActiveLevelOntoTop, write=SetRiseActiveLevelOntoTop, default=1};
	__property bool SkipEmptyViews = {read=FSkipEmptyViews, write=SetSkipEmptyViews, default=1};
	__property bool Unwrap = {read=FUnwrap, write=SetUnwrap, default=0};
	__property bool UnwrapTopLevel = {read=FUnwrapTopLevel, write=SetUnwrapTopLevel, default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsLevels(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : TdxGridReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsLevels(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsOnEveryPage;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsOnEveryPage : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsOnEveryPage
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsOnEveryPage inherited;
	
private:
	bool FCaption;
	bool FFilterBar;
	HIDESBASE TdxGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetCaption(bool Value);
	void __fastcall SetFilterBar(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	virtual bool __fastcall HasInstalledAttribute(TdxGridAttributeClass AnAttribute);
	virtual void __fastcall SetAll(void);
	virtual void __fastcall UnsetAll(void);
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property BandHeaders = {default=1};
	__property bool Caption = {read=FCaption, write=SetCaption, default=1};
	__property bool FilterBar = {read=FFilterBar, write=SetFilterBar, default=1};
	__property Footers = {default=1};
	__property Headers = {default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsOnEveryPage(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsOnEveryPage(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsOnEveryPage(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsPagination;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsPagination : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPagination
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPagination inherited;
	
private:
	bool FOneGroupPerPage;
	bool FTopLevelGroup;
	TdxGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetOneGroupPerPage(bool Value);
	void __fastcall SetTopLevelGroup(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property Band = {default=0};
	__property Column = {default=1};
	__property Custom = {default=0};
	__property bool OneGroupPerPage = {read=FOneGroupPerPage, write=SetOneGroupPerPage, default=0};
	__property Row = {default=1};
	__property bool TopLevelGroup = {read=FTopLevelGroup, write=SetTopLevelGroup, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsPagination(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPagination(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsPagination(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsPreview;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsPreview : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPreview
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPreview inherited;
	
private:
	HIDESBASE TdxGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsPreview(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPreview(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsPreview(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsRefinements;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsRefinements : public Dxpscxcommon::TdxCustomReportLinkOptionsRefinements
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsRefinements inherited;
	
private:
	TdxGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsRefinements(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsRefinements(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsRefinements(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsSelection;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsSelection : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsSelection
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsSelection inherited;
	
private:
	HIDESBASE TdxGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsSelection(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsSelection(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsSelection(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsSize;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsSize : public Dxpscxcommon::TdxCustomReportLinkOptionsSize
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsSize inherited;
	
private:
	TdxGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property AutoWidth = {default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsSize(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsSize(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsSize(void) { }
	
};


class DELPHICLASS TdxGridReportLinkOptionsView;
class PASCALIMPLEMENTATION TdxGridReportLinkOptionsView : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsView
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsView inherited;
	
private:
	bool FCaption;
	bool FFilterBar;
	bool FGroupFooters;
	TdxGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetCaption(bool Value);
	void __fastcall SetFilterBar(bool Value);
	void __fastcall SetGroupFooters(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	virtual bool __fastcall HasInstalledAttribute(TdxGridAttributeClass AnAttribute);
	void __fastcall SetAll(void);
	void __fastcall UnsetAll(void);
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property BandHeaders = {default=1};
	__property bool Caption = {read=FCaption, write=SetCaption, default=1};
	__property ExpandButtons = {default=1};
	__property bool FilterBar = {read=FFilterBar, write=SetFilterBar, default=1};
	__property Footers = {default=1};
	__property bool GroupFooters = {read=FGroupFooters, write=SetGroupFooters, default=1};
	__property Headers = {default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxGridReportLinkOptionsView(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsView(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxGridReportLinkOptionsView(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridAttributeHostInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxpscore::TdxReportCell* FParent;
	
public:
	System::Types::TPoint Origin;
	void __fastcall Initialize(Dxpscore::TdxReportCell* AParent);
	__property Dxpscore::TdxReportCell* Parent = {read=FParent};
public:
	/* TObject.Create */ inline __fastcall TdxGridAttributeHostInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGridAttributeHostInfo(void) { }
	
};


typedef System::TMetaClass* TdxGridAttributeHostInfoServicesClass;

class PASCALIMPLEMENTATION TdxGridAttributeHostInfoServices : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxGridAttributeHostInfo* FPageDetailsHostInfo;
	TdxGridAttributeHostInfo* FPageFootersHostInfo;
	TdxGridAttributeHostInfo* FPageHeadersHostInfo;
	TdxGridReportLink* FReportLink;
	Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveView(void);
	TdxCustomGridViewHelperClass __fastcall GetActiveViewHelper(void);
	bool __fastcall GetArePageFootersAssigned(void);
	bool __fastcall GetArePageHeadersAssigned(void);
	bool __fastcall GetCanUseBandHeadersOnEveyPage(void);
	bool __fastcall GetCanUseCaptionOnEveryPage(void);
	bool __fastcall GetCanUseFilterBarOnEveryPage(void);
	bool __fastcall GetCanUseFootersOnEveryPage(void);
	bool __fastcall GetCanUseHeadersOnEveryPage(void);
	bool __fastcall GetIsInconsistentBandHeadersState(void);
	bool __fastcall GetIsInconsistentFilterBarState(void);
	bool __fastcall GetIsInconsistentFootersState(void);
	bool __fastcall GetIsInconsistentHeadersState(void);
	TdxGridAttributeHostInfo* __fastcall GetLevelSeparatorBottomHostInfo(void);
	TdxGridAttributeHostInfo* __fastcall GetLevelSeparatorTopHostInfo(void);
	TdxGridReportLinkOptionsOnEveryPage* __fastcall GetOptionsOnEveryPage(void);
	TdxGridReportLinkOptionsView* __fastcall GetOptionsView(void);
	Dxpscore::TdxReportCell* __fastcall GetPageDetails(void);
	Dxpscore::TdxReportCell* __fastcall GetPageFooters(void);
	Dxpscore::TdxReportCell* __fastcall GetPageHeaders(void);
	
protected:
	void __fastcall CreateHostInfos(void);
	void __fastcall DestroyHostInfos(void);
	virtual TdxGridAttributeHostInfo* __fastcall GetBandHeadersHostInfo(void);
	virtual TdxGridAttributeHostInfo* __fastcall GetCaptionHostInfo(void);
	virtual TdxGridAttributeHostInfo* __fastcall GetFilterBarHostInfo(void);
	virtual TdxGridAttributeHostInfo* __fastcall GetFootersHostInfo(void);
	virtual TdxGridAttributeHostInfo* __fastcall GetHeadersHostInfo(void);
	virtual System::UnicodeString __fastcall GetInconsistentStateText(void);
	virtual bool __fastcall GetIsInconsistentState(void);
	bool __fastcall HasCells(void);
	bool __fastcall IsAttributeSupported(TdxGridAttributeClass AnAttribute);
	__property Cxgridcustomview::TcxCustomGridView* ActiveView = {read=GetActiveView};
	__property TdxCustomGridViewHelperClass ActiveViewHelper = {read=GetActiveViewHelper};
	__property TdxGridReportLinkOptionsOnEveryPage* OptionsOnEveryPage = {read=GetOptionsOnEveryPage};
	__property TdxGridReportLinkOptionsView* OptionsView = {read=GetOptionsView};
	__property Dxpscore::TdxReportCell* PageDetails = {read=GetPageDetails};
	__property Dxpscore::TdxReportCell* PageFooters = {read=GetPageFooters};
	__property Dxpscore::TdxReportCell* PageHeaders = {read=GetPageHeaders};
	
public:
	__fastcall virtual TdxGridAttributeHostInfoServices(TdxGridReportLink* AReportLink);
	__fastcall virtual ~TdxGridAttributeHostInfoServices(void);
	void __fastcall Initialize(void);
	__property bool ArePageFootersAssigned = {read=GetArePageFootersAssigned, nodefault};
	__property bool ArePageHeadersAssigned = {read=GetArePageHeadersAssigned, nodefault};
	__property TdxGridAttributeHostInfo* BandHeadersHostInfo = {read=GetBandHeadersHostInfo};
	__property bool CanUseBandHeadersOnEveyPage = {read=GetCanUseBandHeadersOnEveyPage, nodefault};
	__property bool CanUseCaptionOnEveryPage = {read=GetCanUseCaptionOnEveryPage, nodefault};
	__property bool CanUseFilterBarOnEveryPage = {read=GetCanUseFilterBarOnEveryPage, nodefault};
	__property bool CanUseFootersOnEveryPage = {read=GetCanUseFootersOnEveryPage, nodefault};
	__property bool CanUseHeadersOnEveryPage = {read=GetCanUseHeadersOnEveryPage, nodefault};
	__property TdxGridAttributeHostInfo* CaptionHostInfo = {read=GetCaptionHostInfo};
	__property TdxGridAttributeHostInfo* FilterBarHostInfo = {read=GetFilterBarHostInfo};
	__property TdxGridAttributeHostInfo* FootersHostInfo = {read=GetFootersHostInfo};
	__property TdxGridAttributeHostInfo* HeadersHostInfo = {read=GetHeadersHostInfo};
	__property System::UnicodeString InconsistentStateText = {read=GetInconsistentStateText};
	__property bool IsInconsistentBandHeadersState = {read=GetIsInconsistentBandHeadersState, nodefault};
	__property bool IsInconsistentFilterBarState = {read=GetIsInconsistentFilterBarState, nodefault};
	__property bool IsInconsistentFootersState = {read=GetIsInconsistentFootersState, nodefault};
	__property bool IsInconsistentHeadersState = {read=GetIsInconsistentHeadersState, nodefault};
	__property bool IsInconsistentState = {read=GetIsInconsistentState, nodefault};
	__property TdxGridAttributeHostInfo* LevelSeparatorBottomHostInfo = {read=GetLevelSeparatorBottomHostInfo};
	__property TdxGridAttributeHostInfo* LevelSeparatorTopHostInfo = {read=GetLevelSeparatorTopHostInfo};
	__property TdxGridAttributeHostInfo* PageDetailsHostInfo = {read=FPageDetailsHostInfo};
	__property TdxGridAttributeHostInfo* PageFootersHostInfo = {read=FPageFootersHostInfo};
	__property TdxGridAttributeHostInfo* PageHeadersHostInfo = {read=FPageHeadersHostInfo};
	__property TdxGridReportLink* ReportLink = {read=FReportLink};
};


typedef System::TMetaClass* TdxGridReportLinkStylesClass;

class DELPHICLASS TdxGridReportLinkStyles;
class PASCALIMPLEMENTATION TdxGridReportLinkStyles : public Dxpscxcommon::TdxCustomReportLinkStyles
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyles inherited;
	
private:
	HIDESBASE TdxGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__classmethod virtual System::UnicodeString __fastcall GetStyleCaption(int AnIndex);
	virtual int __fastcall GetStyleIndexByCaption(const System::UnicodeString Caption);
	bool __fastcall IsCardViewStyle(Cxstyles::TcxStyle* AStyle);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetBandHeaderParams(Cxgridbandedtableview::TcxGridBand* ABand, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetCaptionParams(Cxgridlevel::TcxGridLevel* ATabLevel, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetCardCaptionRowParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetCardRowCaptionParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetFilterBarParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetFooterParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel, Cxgridtableview::TcxGridColumn* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetGroupParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int AGroupLevel, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetHeaderParams(Cxgridtableview::TcxGridColumn* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetPreviewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetSelectionParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property Cxstyles::TcxStyle* BandHeader = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Caption = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* CardCaptionRow = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* CardRowCaption = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* ContentEven = {read=GetValue, write=SetValue, index=5};
	__property Cxstyles::TcxStyle* ContentOdd = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* FilterBar = {read=GetValue, write=SetValue, index=7};
	__property Cxstyles::TcxStyle* Footer = {read=GetValue, write=SetValue, index=8};
	__property Cxstyles::TcxStyle* Group = {read=GetValue, write=SetValue, index=9};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* Preview = {read=GetValue, write=SetValue, index=11};
	__property Cxstyles::TcxStyle* Selection = {read=GetValue, write=SetValue, index=12};
	__property StyleSheet;
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TdxGridReportLinkStyles(System::Classes::TPersistent* AOwner) : Dxpscxcommon::TdxCustomReportLinkStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TdxGridReportLinkStyles(void) { }
	
};


class DELPHICLASS TdxGridReportLinkStyleSheet;
class PASCALIMPLEMENTATION TdxGridReportLinkStyleSheet : public Dxpscxcommon::TdxCustomReportLinkStyleSheet
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyleSheet inherited;
	
private:
	TdxGridReportLinkStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TdxGridReportLinkStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TdxGridReportLinkStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TdxGridReportLinkStyleSheet(System::Classes::TComponent* AOwner) : Dxpscxcommon::TdxCustomReportLinkStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TdxGridReportLinkStyleSheet(void) { }
	
};


struct DECLSPEC_DRECORD TdxGridReportLinkProcessParams
{
public:
	bool HasMasterDetails;
	bool HasMasterDetailsInTopView;
	bool HasOnlyCards;
	bool HasOnlyCharts;
	bool HasUnwrapableData;
	bool CanUseOnEveryPageMode;
};


typedef System::DynamicArray<Cxgridcustomtableview::TcxCustomGridRecord*> TdxGridRecordArray;

typedef void __fastcall (__closure *TdxGridViewProc)(Cxgridcustomview::TcxCustomGridView* AGridView);

typedef void __fastcall (__closure *TdxGridGetCustomPageBreaksEvent)(TdxGridReportLink* Sender);

typedef void __fastcall (__closure *TdxGridReportLinkGetCellHeightEvent)(TdxGridReportLink* Sender, Cxgridcustomtableview::TcxCustomGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, int &AHeight);

typedef void __fastcall (__closure *TdxGridReportLinkCustomDrawBandCellEvent)(TdxGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxgridbandedtableview::TcxGridBandedTableView* AView, Cxgridbandedtableview::TcxGridBand* ABand, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxGridReportLinkCustomDrawCellEvent)(TdxGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxgridcustomtableview::TcxCustomGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridtableview::TcxGridColumn* AColumn, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxGridReportLinkCustomDrawCardRowCaptionCellEvent)(TdxGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxgridcardview::TcxGridCardView* AView, Cxgridcardview::TcxGridCard* ACard, Cxgridcardview::TcxGridCardViewRow* ARow, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxGridReportLinkCustomDrawCardRowDataCellEvent)(TdxGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxgridcardview::TcxGridCardView* AView, Cxgridcardview::TcxGridCard* ACard, Cxgridcardview::TcxGridCardViewRow* ARow, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxGridReportLinkCustomDrawFilterBarEvent)(TdxGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxgridcustomtableview::TcxCustomGridTableView* AView, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxGridReportLinkCustomDrawFooterCellEvent)(TdxGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxgridtableview::TcxGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridtableview::TcxGridColumn* AColumn, int ALevel, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxGridReportLinkCustomDrawHeaderCellEvent)(TdxGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxgridtableview::TcxGridTableView* AView, Cxgridtableview::TcxGridColumn* AColumn, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxGridReportLinkCustomDrawLevelCaptionEvent)(TdxGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxgridcustomview::TcxCustomGridView* AView, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeBandCellEvent)(TdxGridReportLink* Sender, Cxgridbandedtableview::TcxGridBandedTableView* AView, Cxgridbandedtableview::TcxGridBand* ABand, Dxpscore::TdxReportCellString* AnItem);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeCellEvent)(TdxGridReportLink* Sender, Cxgridcustomtableview::TcxCustomGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridtableview::TcxGridColumn* AColumn, Dxpscore::TAbstractdxReportCellData* AnItem);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeCardRowCaptionCellEvent)(TdxGridReportLink* Sender, Cxgridcardview::TcxGridCardView* AView, Cxgridcardview::TcxGridCard* ACard, Cxgridcardview::TcxGridCardViewRow* ARow, Dxpscore::TdxReportCellString* AnItem);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeCardRowDataCellEvent)(TdxGridReportLink* Sender, Cxgridcardview::TcxGridCardView* AView, Cxgridcardview::TcxGridCard* ACard, Cxgridcardview::TcxGridCardViewRow* ARow, Dxpscore::TAbstractdxReportCellData* AnItem);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeChartCellEvent)(TdxGridReportLink* Sender, Cxgridchartview::TcxGridChartView* AView, Dxpscore::TdxReportCellGraphic* AnItem);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeFilterBarEvent)(TdxGridReportLink* Sender, Cxgridcustomtableview::TcxCustomGridTableView* AView, Dxpscore::TdxReportCellString* AnItem);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeFooterCellEvent)(TdxGridReportLink* Sender, Cxgridtableview::TcxGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridtableview::TcxGridColumn* AColumn, int ALevel, Dxpscore::TdxReportCellString* AnItem);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeHeaderCellEvent)(TdxGridReportLink* Sender, Cxgridtableview::TcxGridTableView* AView, Cxgridtableview::TcxGridColumn* AColumn, Dxpscore::TdxReportCellString* AnItem);

typedef void __fastcall (__closure *TdxGridReportLinkInitializeLevelCaptionEvent)(TdxGridReportLink* Sender, Cxgridcustomview::TcxCustomGridView* AView, Dxpscore::TdxReportCellString* AnItem);

class DELPHICLASS TdxfmGridReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxGridReportLink : public Dxpscxcommon::TdxCustomTableControlReportLink
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLink inherited;
	
private:
	System::Classes::TList* FDelimitersHardHorz;
	System::Classes::TList* FDelimitersHardVert;
	TdxGridAttributeHostInfoServices* FHostInfoServices;
	TdxGridReportLinkOptionsCards* FOptionsCards;
	TdxGridReportLinkOptionsCharts* FOptionsCharts;
	TdxGridReportLinkOptionsDetails* FOptionsDetails;
	TdxGridReportLinkOptionsLevels* FOptionsLevels;
	Cxgridcustomview::TcxCustomGridView* FProcessedView;
	TdxGridReportLinkProcessParams FProcessParams;
	System::Classes::TList* FReportRows;
	TdxGridReportLinkCustomDrawBandCellEvent FOnCustomDrawBandCell;
	TdxGridReportLinkCustomDrawCardRowCaptionCellEvent FOnCustomDrawCardRowCaptionCell;
	TdxGridReportLinkCustomDrawCardRowDataCellEvent FOnCustomDrawCardRowDataCell;
	TdxGridReportLinkCustomDrawCellEvent FOnCustomDrawCell;
	TdxGridReportLinkCustomDrawFilterBarEvent FOnCustomDrawFilterBar;
	TdxGridReportLinkCustomDrawFooterCellEvent FOnCustomDrawFooterCell;
	TdxGridReportLinkCustomDrawHeaderCellEvent FOnCustomDrawHeaderCell;
	TdxGridReportLinkCustomDrawLevelCaptionEvent FOnCustomDrawLevelCaption;
	TdxGridReportLinkGetCellHeightEvent FOnGetCellHeight;
	TdxGridGetCustomPageBreaksEvent FOnGetCustomPageBreaks;
	TdxGridReportLinkInitializeBandCellEvent FOnInitializeBandCell;
	TdxGridReportLinkInitializeCardRowCaptionCellEvent FOnInitializeCardRowCaptionCell;
	TdxGridReportLinkInitializeCardRowDataCellEvent FOnInitializeCardRowDataCell;
	TdxGridReportLinkInitializeCellEvent FOnInitializeCell;
	TdxGridReportLinkInitializeChartCellEvent FOnInitializeChartCell;
	TdxGridReportLinkInitializeFilterBarEvent FOnInitializeFilterBar;
	TdxGridReportLinkInitializeFooterCellEvent FOnInitializeFooterCell;
	TdxGridReportLinkInitializeHeaderCellEvent FOnInitializeHeaderCell;
	TdxGridReportLinkInitializeLevelCaptionEvent FOnInitializeLevelCaption;
	HIDESBASE TdxGridReportLinkStyles* __fastcall GetActiveStyles(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveView(void);
	TdxCustomGridViewHelperClass __fastcall GetActiveViewHelper(void);
	Cxgridtableview::TcxGridMasterDataRow* __fastcall GetActiveViewMasterRow(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetActiveViewParentLevel(void);
	HIDESBASE TdxfmGridReportLinkDesignWindow* __fastcall GetDesignWindow(void);
	Cxgrid::TcxGrid* __fastcall GetGrid(void);
	TdxGridReportLinkOptionsExpanding* __fastcall GetOptionsExpanding(void);
	TdxGridReportLinkOptionsFormatting* __fastcall GetOptionsFormatting(void);
	TdxGridReportLinkOptionsOnEveryPage* __fastcall GetOptionsOnEveryPage(void);
	HIDESBASE TdxGridReportLinkOptionsPagination* __fastcall GetOptionsPagination(void);
	TdxGridReportLinkOptionsPreview* __fastcall GetOptionsPreview(void);
	TdxGridReportLinkOptionsRefinements* __fastcall GetOptionsRefinements(void);
	TdxGridReportLinkOptionsSelection* __fastcall GetOptionsSelection(void);
	TdxGridReportLinkOptionsSize* __fastcall GetOptionsSize(void);
	HIDESBASE TdxGridReportLinkOptionsView* __fastcall GetOptionsView(void);
	Dxpscore::TAbstractdxReportCellData* __fastcall GetReportDataCellByGridColumn(Cxgridtableview::TcxGridColumn* AColumn);
	Dxpscore::TdxReportCell* __fastcall GetReportRow(int Index);
	Dxpscore::TdxReportCell* __fastcall GetReportRowByGridRecord(Cxgridcustomtableview::TcxCustomGridRecord* GridRecord);
	int __fastcall GetReportRowCount(void);
	TdxGridReportLinkStyles* __fastcall GetStyles(void);
	void __fastcall SetOnCustomDrawBandCell(TdxGridReportLinkCustomDrawBandCellEvent Value);
	void __fastcall SetOnCustomDrawCell(TdxGridReportLinkCustomDrawCellEvent Value);
	void __fastcall SetOnCustomDrawCardRowCaptionCell(TdxGridReportLinkCustomDrawCardRowCaptionCellEvent Value);
	void __fastcall SetOnCustomDrawCardRowDataCell(TdxGridReportLinkCustomDrawCardRowDataCellEvent Value);
	void __fastcall SetOnCustomDrawFilterBar(TdxGridReportLinkCustomDrawFilterBarEvent Value);
	void __fastcall SetOnCustomDrawFooterCell(TdxGridReportLinkCustomDrawFooterCellEvent Value);
	void __fastcall SetOnCustomDrawHeaderCell(TdxGridReportLinkCustomDrawHeaderCellEvent Value);
	void __fastcall SetOnCustomDrawLevelCaption(TdxGridReportLinkCustomDrawLevelCaptionEvent Value);
	void __fastcall SetOptionsCards(TdxGridReportLinkOptionsCards* Value);
	void __fastcall SetOptionsCharts(TdxGridReportLinkOptionsCharts* Value);
	void __fastcall SetOptionsDetails(TdxGridReportLinkOptionsDetails* Value);
	HIDESBASE void __fastcall SetOptionsExpanding(TdxGridReportLinkOptionsExpanding* Value);
	HIDESBASE void __fastcall SetOptionsFormatting(TdxGridReportLinkOptionsFormatting* Value);
	void __fastcall SetOptionsLevels(TdxGridReportLinkOptionsLevels* Value);
	HIDESBASE void __fastcall SetOptionsOnEveryPage(TdxGridReportLinkOptionsOnEveryPage* Value);
	HIDESBASE void __fastcall SetOptionsPagination(TdxGridReportLinkOptionsPagination* Value);
	HIDESBASE void __fastcall SetOptionsPreview(TdxGridReportLinkOptionsPreview* Value);
	HIDESBASE void __fastcall SetOptionsRefinements(TdxGridReportLinkOptionsRefinements* Value);
	HIDESBASE void __fastcall SetOptionsSelection(TdxGridReportLinkOptionsSelection* Value);
	HIDESBASE void __fastcall SetOptionsSize(TdxGridReportLinkOptionsSize* Value);
	HIDESBASE void __fastcall SetOptionsView(TdxGridReportLinkOptionsView* Value);
	HIDESBASE void __fastcall SetStyles(TdxGridReportLinkStyles* Value);
	
protected:
	virtual void __fastcall BeforeDesignReport(void);
	virtual int __fastcall CalculateActualScaleFactor(void);
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall ConvertCoords(void);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);
	virtual bool __fastcall GetBreakPagesByHardDelimiters(void);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual bool __fastcall GetUseHardHorzDelimiters(void);
	virtual bool __fastcall GetUseHardVertDelimiters(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsDrawFootersOnEveryPage(void);
	virtual bool __fastcall IsDrawHeadersOnEveryPage(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	virtual void __fastcall MakeHardDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	virtual bool __fastcall GetAreNativeStylesAvailable(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStylesClass __fastcall GetStylesClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheetClass __fastcall GetStyleSheetClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheet* __fastcall GetStyleSheetPrototype(void);
	virtual void __fastcall PrepareConstruct(void);
	DYNAMIC void __fastcall DoCustomDrawBandCell(Vcl::Graphics::TCanvas* ACanvas, Cxgridbandedtableview::TcxGridBandedTableView* AView, Cxgridbandedtableview::TcxGridBand* ABand, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawCardRowCaptionCell(Vcl::Graphics::TCanvas* ACanvas, Cxgridcardview::TcxGridCardView* AView, Cxgridcardview::TcxGridCard* ACard, Cxgridcardview::TcxGridCardViewRow* ARow, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawCardRowDataCell(Vcl::Graphics::TCanvas* ACanvas, Cxgridcardview::TcxGridCardView* AView, Cxgridcardview::TcxGridCard* ACard, Cxgridcardview::TcxGridCardViewRow* ARow, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawCell(Vcl::Graphics::TCanvas* ACanvas, Cxgridcustomtableview::TcxCustomGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridtableview::TcxGridColumn* AColumn, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawFilterBar(Vcl::Graphics::TCanvas* ACanvas, Cxgridcustomtableview::TcxCustomGridTableView* AView, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawFooterCell(Vcl::Graphics::TCanvas* ACanvas, Cxgridtableview::TcxGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridtableview::TcxGridColumn* AColumn, int ALevel, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawHeaderCell(Vcl::Graphics::TCanvas* ACanvas, Cxgridtableview::TcxGridTableView* AView, Cxgridtableview::TcxGridColumn* AColumn, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawLevelCaption(Vcl::Graphics::TCanvas* ACanvas, Cxgridcustomview::TcxCustomGridView* AView, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoGetCellHeight(Cxgridcustomtableview::TcxCustomGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, int &AHeight);
	DYNAMIC void __fastcall DoGetCustomPageBreaks(void);
	DYNAMIC void __fastcall DoInitializeBandCell(Cxgridbandedtableview::TcxGridBandedTableView* AView, Cxgridbandedtableview::TcxGridBand* ABand, Dxpscore::TdxReportCellString* AnItem);
	DYNAMIC void __fastcall DoInitializeCardRowCaptionCell(Cxgridcardview::TcxGridCardView* AView, Cxgridcardview::TcxGridCard* ACard, Cxgridcardview::TcxGridCardViewRow* ARow, Dxpscore::TdxReportCellString* AnItem);
	DYNAMIC void __fastcall DoInitializeCardRowDataCell(Cxgridcardview::TcxGridCardView* AView, Cxgridcardview::TcxGridCard* ACard, Cxgridcardview::TcxGridCardViewRow* ARow, Dxpscore::TAbstractdxReportCellData* AnItem);
	DYNAMIC void __fastcall DoInitializeCell(Cxgridcustomtableview::TcxCustomGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridtableview::TcxGridColumn* AColumn, Dxpscore::TAbstractdxReportCellData* AnItem);
	DYNAMIC void __fastcall DoInitializeChartCell(Cxgridchartview::TcxGridChartView* AView, Dxpscore::TdxReportCellGraphic* AnItem);
	DYNAMIC void __fastcall DoInitializeFilterBar(Cxgridcustomtableview::TcxCustomGridTableView* AView, Dxpscore::TdxReportCellString* AnItem);
	DYNAMIC void __fastcall DoInitializeFooterCell(Cxgridtableview::TcxGridTableView* AView, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridtableview::TcxGridColumn* AColumn, int ALevel, Dxpscore::TdxReportCellString* AnItem);
	DYNAMIC void __fastcall DoInitializeHeaderCell(Cxgridtableview::TcxGridTableView* AView, Cxgridtableview::TcxGridColumn* AColumn, Dxpscore::TdxReportCellString* AnItem);
	DYNAMIC void __fastcall DoInitializeLevelCaption(Cxgridcustomview::TcxCustomGridView* AView, Dxpscore::TdxReportCellString* AnItem);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual TdxGridReportLinkOptionsCardsClass __fastcall GetOptionsCardsClass(void);
	virtual TdxGridReportLinkOptionsChartsClass __fastcall GetOptionsChartsClass(void);
	virtual TdxGridReportLinkOptionsDetailsClass __fastcall GetOptionsDetailsClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsExpandingClass __fastcall GetOptionsExpandingClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsFormattingClass __fastcall GetOptionsFormattingClass(void);
	virtual TdxGridReportLinkOptionsLevelsClass __fastcall GetOptionsLevelsClass(void);
	virtual Dxpscxcommon::TdxCustomTableControlReportLinkOptionsOnEveryPageClass __fastcall GetOptionsOnEveryPageClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsPaginationClass __fastcall GetOptionsPaginationClass(void);
	virtual Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPreviewClass __fastcall GetOptionsPreviewClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsRefinementsClass __fastcall GetOptionsRefinementsClass(void);
	virtual Dxpscxcommon::TdxCustomTableControlReportLinkOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsSizeClass __fastcall GetOptionsSizeClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsViewClass __fastcall GetOptionsViewClass(void);
	void __fastcall AddReportRow(Dxpscore::TdxReportCell* AReportRow);
	void __fastcall AddHorizontalHardDelimiter(int ADelimiter);
	void __fastcall AddVerticalHardDelimiter(int ADelimiter)/* overload */;
	void __fastcall AddVerticalHardDelimiter(Dxpscore::TdxReportCell* ADelimiter)/* overload */;
	void __fastcall BuildTopLevelView(Cxgridcustomview::TcxCustomGridView* AGridView);
	void __fastcall BuildTopLevelViews(void);
	void __fastcall BuildView(TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView);
	TdxCustomGridViewAdapter* __fastcall CreateViewAdapter(TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView);
	TdxCustomGridViewBuilder* __fastcall CreateViewBuilder(TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView);
	void __fastcall DoExpandRows(void);
	void __fastcall DoExpandViewRows(Cxgridcustomview::TcxCustomGridView* AGridView);
	void __fastcall ForEachView(Cxgridtableview::TcxGridMasterDataRow* AMasterRow, TdxGridViewProc AProc);
	virtual TdxGridAttributeID __fastcall GetItemCustomDrawInfo(Dxpscore::TdxReportVisualItem* AnItem, /* out */ TdxGridCellCustomDrawInfo &ADrawInfo);
	virtual bool __fastcall IsCardViewStyle(Cxstyles::TcxStyle* AStyle);
	virtual bool __fastcall IsCustomDrawn(TdxGridAttributeID AnAttributeID);
	bool __fastcall IsOffice11StyleGrouping(void);
	void __fastcall CalculateProcessParams(void);
	bool __fastcall CanAttributeBeUsedOnEveryPage(TdxGridAttributeClass AnAttribute);
	bool __fastcall IsAttributeUsedOnEveryPage(TdxGridAttributeClass AnAttribute);
	__property TdxGridReportLinkStyles* ActiveStyles = {read=GetActiveStyles};
	__property Cxgridcustomview::TcxCustomGridView* ActiveView = {read=GetActiveView};
	__property TdxCustomGridViewHelperClass ActiveViewHelper = {read=GetActiveViewHelper};
	__property Cxgridtableview::TcxGridMasterDataRow* ActiveViewMasterRow = {read=GetActiveViewMasterRow};
	__property Cxgridlevel::TcxGridLevel* ActiveViewParentLevel = {read=GetActiveViewParentLevel};
	__property System::Classes::TList* DelimitersHardHorz = {read=FDelimitersHardHorz};
	__property System::Classes::TList* DelimitersHardVert = {read=FDelimitersHardVert};
	__property TdxGridAttributeHostInfoServices* HostInfoServices = {read=FHostInfoServices};
	__property TdxGridReportLinkProcessParams ProcessParams = {read=FProcessParams};
	
public:
	__fastcall virtual TdxGridReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxGridReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddPageBreak(Cxgridcustomtableview::TcxCustomGridRecord* AGridRecord)/* overload */;
	void __fastcall AddPageBreak(Cxgridcustomtableview::TcxCustomGridRecord* const *AGridRecords, const int AGridRecords_Size)/* overload */;
	void __fastcall AddPageBreak(const TdxGridRecordArray AGridRecords)/* overload */;
	void __fastcall AddPageBreak(System::Classes::TList* AGridRecords)/* overload */;
	void __fastcall AddHorizontalPageBreak(Cxgridtableview::TcxGridColumn* AGridColumn)/* overload */;
	void __fastcall AddHorizontalPageBreak(System::Classes::TList* AGridColumns)/* overload */;
	void __fastcall AddHorizontalPageBreak(Cxgridtableview::TcxGridColumn* const *AGridColumns, const int AGridColumns_Size)/* overload */;
	__property Cxgrid::TcxGrid* Grid = {read=GetGrid};
	__property TdxfmGridReportLinkDesignWindow* DesignWindow = {read=GetDesignWindow};
	__property Dxpscore::TdxReportCell* ReportRows[int Index] = {read=GetReportRow};
	__property Dxpscore::TdxReportCell* ReportRowsByGridRecord[Cxgridcustomtableview::TcxCustomGridRecord* GridRow] = {read=GetReportRowByGridRecord};
	__property int ReportRowCount = {read=GetReportRowCount, nodefault};
	
__published:
	__property Color = {default=16777215};
	__property Font;
	__property TdxGridReportLinkOptionsCards* OptionsCards = {read=FOptionsCards, write=SetOptionsCards};
	__property TdxGridReportLinkOptionsCharts* OptionsCharts = {read=FOptionsCharts, write=SetOptionsCharts};
	__property TdxGridReportLinkOptionsDetails* OptionsDetails = {read=FOptionsDetails, write=SetOptionsDetails};
	__property TdxGridReportLinkOptionsExpanding* OptionsExpanding = {read=GetOptionsExpanding, write=SetOptionsExpanding};
	__property TdxGridReportLinkOptionsFormatting* OptionsFormatting = {read=GetOptionsFormatting, write=SetOptionsFormatting};
	__property TdxGridReportLinkOptionsLevels* OptionsLevels = {read=FOptionsLevels, write=SetOptionsLevels};
	__property TdxGridReportLinkOptionsOnEveryPage* OptionsOnEveryPage = {read=GetOptionsOnEveryPage, write=SetOptionsOnEveryPage};
	__property TdxGridReportLinkOptionsPagination* OptionsPagination = {read=GetOptionsPagination, write=SetOptionsPagination};
	__property TdxGridReportLinkOptionsPreview* OptionsPreview = {read=GetOptionsPreview, write=SetOptionsPreview};
	__property TdxGridReportLinkOptionsRefinements* OptionsRefinements = {read=GetOptionsRefinements, write=SetOptionsRefinements};
	__property TdxGridReportLinkOptionsSelection* OptionsSelection = {read=GetOptionsSelection, write=SetOptionsSelection};
	__property TdxGridReportLinkOptionsSize* OptionsSize = {read=GetOptionsSize, write=SetOptionsSize};
	__property TdxGridReportLinkOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property ScaleFonts = {default=1};
	__property StyleRepository;
	__property TdxGridReportLinkStyles* Styles = {read=GetStyles, write=SetStyles};
	__property SupportedCustomDraw = {default=0};
	__property TdxGridReportLinkCustomDrawBandCellEvent OnCustomDrawBandCell = {read=FOnCustomDrawBandCell, write=SetOnCustomDrawBandCell};
	__property TdxGridReportLinkCustomDrawCellEvent OnCustomDrawCell = {read=FOnCustomDrawCell, write=SetOnCustomDrawCell};
	__property TdxGridReportLinkCustomDrawCardRowCaptionCellEvent OnCustomDrawCardRowCaptionCell = {read=FOnCustomDrawCardRowCaptionCell, write=SetOnCustomDrawCardRowCaptionCell};
	__property TdxGridReportLinkCustomDrawCardRowDataCellEvent OnCustomDrawCardRowDataCell = {read=FOnCustomDrawCardRowDataCell, write=SetOnCustomDrawCardRowDataCell};
	__property TdxGridReportLinkCustomDrawFilterBarEvent OnCustomDrawFilterBar = {read=FOnCustomDrawFilterBar, write=SetOnCustomDrawFilterBar};
	__property TdxGridReportLinkCustomDrawFooterCellEvent OnCustomDrawFooterCell = {read=FOnCustomDrawFooterCell, write=SetOnCustomDrawFooterCell};
	__property TdxGridReportLinkCustomDrawHeaderCellEvent OnCustomDrawHeaderCell = {read=FOnCustomDrawHeaderCell, write=SetOnCustomDrawHeaderCell};
	__property TdxGridReportLinkCustomDrawLevelCaptionEvent OnCustomDrawLevelCaption = {read=FOnCustomDrawLevelCaption, write=SetOnCustomDrawLevelCaption};
	__property TdxGridReportLinkGetCellHeightEvent OnGetCellHeight = {read=FOnGetCellHeight, write=FOnGetCellHeight};
	__property TdxGridGetCustomPageBreaksEvent OnGetCustomPageBreaks = {read=FOnGetCustomPageBreaks, write=FOnGetCustomPageBreaks};
	__property TdxGridReportLinkInitializeBandCellEvent OnInitializeBandCell = {read=FOnInitializeBandCell, write=FOnInitializeBandCell};
	__property TdxGridReportLinkInitializeCardRowCaptionCellEvent OnInitializeCardRowCaptionCell = {read=FOnInitializeCardRowCaptionCell, write=FOnInitializeCardRowCaptionCell};
	__property TdxGridReportLinkInitializeCardRowDataCellEvent OnInitializeCardRowDataCell = {read=FOnInitializeCardRowDataCell, write=FOnInitializeCardRowDataCell};
	__property TdxGridReportLinkInitializeCellEvent OnInitializeCell = {read=FOnInitializeCell, write=FOnInitializeCell};
	__property TdxGridReportLinkInitializeChartCellEvent OnInitializeChartCell = {read=FOnInitializeChartCell, write=FOnInitializeChartCell};
	__property TdxGridReportLinkInitializeFilterBarEvent OnInitializeFilterBar = {read=FOnInitializeFilterBar, write=FOnInitializeFilterBar};
	__property TdxGridReportLinkInitializeFooterCellEvent OnInitializeFooterCell = {read=FOnInitializeFooterCell, write=FOnInitializeFooterCell};
	__property TdxGridReportLinkInitializeHeaderCellEvent OnInitializeHeaderCell = {read=FOnInitializeHeaderCell, write=FOnInitializeHeaderCell};
	__property TdxGridReportLinkInitializeLevelCaptionEvent OnInitializeLevelCaption = {read=FOnInitializeLevelCaption, write=FOnInitializeLevelCaption};
};


class DELPHICLASS TcxGridCardView2OptionsView;
class PASCALIMPLEMENTATION TcxGridCardView2OptionsView : public Cxgridcardview::TcxGridCardViewOptionsView
{
	typedef Cxgridcardview::TcxGridCardViewOptionsView inherited;
	
private:
	bool FCardBorders;
	System::Uitypes::TColor FGridLineColor;
	Cxgraphics::TcxGridLines FGridLines;
	int FShadowDepth;
	bool __fastcall GetShadowVisible(void);
	void __fastcall SetCardBorders(bool Value);
	void __fastcall SetGridLineColor(System::Uitypes::TColor Value);
	void __fastcall SetGridLines(Cxgraphics::TcxGridLines Value);
	void __fastcall SetShadowDepth(int Value);
	
public:
	__fastcall virtual TcxGridCardView2OptionsView(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool ShadowVisible = {read=GetShadowVisible, nodefault};
	
__published:
	__property bool CardBorders = {read=FCardBorders, write=SetCardBorders, default=0};
	__property System::Uitypes::TColor GridLineColor = {read=FGridLineColor, write=SetGridLineColor, default=536870912};
	__property Cxgraphics::TcxGridLines GridLines = {read=FGridLines, write=SetGridLines, default=1};
	__property int ShadowDepth = {read=FShadowDepth, write=SetShadowDepth, nodefault};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridCardView2OptionsView(void) { }
	
};


class DELPHICLASS TcxGridCardView2Styles;
class PASCALIMPLEMENTATION TcxGridCardView2Styles : public Cxgridcardview::TcxGridCardViewStyles
{
	typedef Cxgridcardview::TcxGridCardViewStyles inherited;
	
private:
	Cxgridcustomtableview::TcxGridGetRecordStyleEvent FOnGetCardShadowStyle;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetCardShadowParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	
__published:
	__property Cxstyles::TcxStyle* CardShadow = {read=GetValue, write=SetValue, index=16};
	__property Cxgridcustomtableview::TcxGridGetRecordStyleEvent OnGetCardShadowStyle = {read=FOnGetCardShadowStyle, write=FOnGetCardShadowStyle};
public:
	/* TcxGridCardViewStyles.Create */ inline __fastcall virtual TcxGridCardView2Styles(System::Classes::TPersistent* AOwner) : Cxgridcardview::TcxGridCardViewStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridCardView2Styles(void) { }
	
};


class DELPHICLASS TcxGridCardView2;
class PASCALIMPLEMENTATION TcxGridCardView2 : public Cxgridcardview::TcxGridCardView
{
	typedef Cxgridcardview::TcxGridCardView inherited;
	
protected:
	virtual Cxgridcustomview::TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewStylesClass __fastcall GetStylesClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewDataClass __fastcall GetViewDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void);
public:
	/* TcxCustomGridTableView.Destroy */ inline __fastcall virtual ~TcxGridCardView2(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridCardView2(Cxcontrols::TcxControl* AControl) : Cxgridcardview::TcxGridCardView(AControl) { }
	
public:
	/* TcxControlChildComponent.Create */ inline __fastcall virtual TcxGridCardView2(System::Classes::TComponent* AOwner) : Cxgridcardview::TcxGridCardView(AOwner) { }
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridCardView2(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridcardview::TcxGridCardView(AControl, AAssignOwner) { }
	
};


class PASCALIMPLEMENTATION TdxfmGridReportLinkDesignWindow : public Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow
{
	typedef Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshView;
	Cxpc::TcxTabSheet* tshBehaviors;
	Cxpc::TcxTabSheet* tshPreview;
	Cxpc::TcxTabSheet* tshCards;
	Vcl::Extctrls::TImage* imgShow;
	Vcl::Extctrls::TImage* imgOnEveryPage;
	Vcl::Extctrls::TBevel* bvlWarningHost;
	Vcl::Extctrls::TImage* imgSelection;
	Vcl::Extctrls::TImage* imgExpanding;
	Vcl::Extctrls::TImage* imgPreview;
	Vcl::Extctrls::TImage* imgDetails;
	Cxpc::TcxTabSheet* tshFormatting;
	Vcl::Extctrls::TImage* imgLookAndFeel;
	Vcl::Extctrls::TImage* imgRefinements;
	Vcl::Extctrls::TImage* imgCardSpacing;
	Vcl::Extctrls::TImage* imgCardSizes;
	Vcl::Extctrls::TImage* imgCardFraming;
	Vcl::Extctrls::TImage* imgCardShadow;
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxgrid::TcxGrid* PreviewGrid;
	Cxgridbandedtableview::TcxGridBandedTableView* PreviewBandedView;
	Cxgridbandedtableview::TcxGridBandedColumn* colVendorName;
	Cxgridbandedtableview::TcxGridBandedColumn* colVendorLogo;
	Cxgridbandedtableview::TcxGridBandedColumn* colVendorCountry;
	Cxgridbandedtableview::TcxGridBandedColumn* colCarModel;
	Cxgridbandedtableview::TcxGridBandedColumn* colIsSUVModel;
	Cxgridlevel::TcxGridLevel* PreviewGridLevel;
	Vcl::Extctrls::TImage* imgLevels;
	Cxpc::TcxTabSheet* tshStyles;
	Vcl::Menus::TPopupMenu* pmStyles;
	Vcl::Menus::TMenuItem* miStyleFont;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmap;
	Vcl::Menus::TMenuItem* miStyleColor;
	Vcl::Menus::TMenuItem* milLine;
	Vcl::Menus::TMenuItem* miStylesSaveAs;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmapClear;
	Vcl::Menus::TMenuItem* miStyleRestoreDefaults;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miLine3;
	Vcl::Extctrls::TBevel* bvlStylesHost;
	Vcl::Menus::TMenuItem* miStylesSelectAll;
	Vcl::Menus::TMenuItem* miLine4;
	Vcl::Extctrls::TImage* imgGridSize;
	Vcl::Extctrls::TImage* imgPagination;
	Cxstyles::TcxStyleRepository* cxStyleRepository1;
	Cxstyles::TcxStyle* styleCardShadow;
	Cxstyles::TcxStyle* styleCardBorder;
	Cxpc::TcxTabSheet* tshCharts;
	Vcl::Extctrls::TImage* imgCharts;
	Cxcheckbox::TcxCheckBox* chbxShowBands;
	Cxcheckbox::TcxCheckBox* chbxShowHeaders;
	Cxcheckbox::TcxCheckBox* chbxShowFooters;
	Cxcheckbox::TcxCheckBox* chbxShowGroupFooters;
	Cxcheckbox::TcxCheckBox* chbxShowExpandButtons;
	Cxcheckbox::TcxCheckBox* chbxBandsOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxHeadersOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxFootersOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxFilterBarOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxCaptionsOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxShowCaptions;
	Cxcheckbox::TcxCheckBox* chbxShowFilterBar;
	Cxcheckbox::TcxCheckBox* chbxProcessSelection;
	Cxcheckbox::TcxCheckBox* chbxProcessExactSelection;
	Cxcheckbox::TcxCheckBox* chbxExpandGroupRows;
	Cxcheckbox::TcxCheckBox* chbxExpandMasterRows;
	Cxcheckbox::TcxCheckBox* chbxStartFromActiveView;
	Cxcheckbox::TcxCheckBox* chbxOnlyActiveView;
	Cxcheckbox::TcxCheckBox* chbxLevelsUnwrap;
	Cxcheckbox::TcxCheckBox* chbxLevelsUnwrapTopLevel;
	Cxcheckbox::TcxCheckBox* chbxLevelsRiseActiveLevelOntoTop;
	Cxcheckbox::TcxCheckBox* chbxGridAutoWidth;
	Cxcheckbox::TcxCheckBox* chbxExpandCards;
	Cxcheckbox::TcxCheckBox* chbxLevelsSkipEmptyViews;
	Cxcheckbox::TcxCheckBox* chbxFlatCheckMarks;
	Cxcheckbox::TcxCheckBox* chbxDisplayGraphicsAsText;
	Cxcheckbox::TcxCheckBox* chbxTransparentGraphics;
	Cxcheckbox::TcxCheckBox* chbxSuppressBackgroundBitmaps;
	Cxcheckbox::TcxCheckBox* chbxConsumeSelectionStyle;
	Cxcheckbox::TcxCheckBox* chbxPaginateOneGroupPerPage;
	Cxcheckbox::TcxCheckBox* chbxPaginateByTopLevelGroups;
	Cxcheckbox::TcxCheckBox* chbxUseNativeStyles;
	Cxcheckbox::TcxCheckBox* chbxPreviewVisible;
	Cxcheckbox::TcxCheckBox* chbxPreviewAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxCardsKeepSameHeight;
	Cxcheckbox::TcxCheckBox* chbxCardsKeepSameWidth;
	Cxcheckbox::TcxCheckBox* chbxCardsAutoWidth;
	Cxcheckbox::TcxCheckBox* chbxCardsVertLines;
	Cxcheckbox::TcxCheckBox* chbxCardsHorzLines;
	Cxcheckbox::TcxCheckBox* chbxCardsBorder;
	Cxcheckbox::TcxCheckBox* chbxChartsTransparent;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblOnEveryPage;
	Cxlabel::TcxLabel* lblSelection;
	Cxlabel::TcxLabel* lblExpanding;
	Cxlabel::TcxLabel* lblDetails;
	Cxlabel::TcxLabel* lblLevels;
	Cxlabel::TcxLabel* lblGridSize;
	Cxlabel::TcxLabel* lblLookAndFeel;
	Cxlabel::TcxLabel* lblRefinements;
	Cxlabel::TcxLabel* lblPagination;
	Cxlabel::TcxLabel* lblStyleSheets;
	Cxlabel::TcxLabel* lblUseNativeStyles;
	Cxlabel::TcxLabel* lblPreviewOptions;
	Cxlabel::TcxLabel* lblPreviewMaxLineCount;
	Cxlabel::TcxLabel* lblCardSpaceVert;
	Cxlabel::TcxLabel* lblCardSpaceHorz;
	Cxlabel::TcxLabel* lblCardSpacing;
	Cxlabel::TcxLabel* lblCardSizes;
	Cxlabel::TcxLabel* lblCardFraming;
	Cxlabel::TcxLabel* lblCardShadowDepth;
	Cxlabel::TcxLabel* lblCardShadow;
	Cxlabel::TcxLabel* lblCardShadowColor;
	Cxlabel::TcxLabel* lblChartsOptions;
	Cxlabel::TcxLabel* lblPreviewWindow;
	Cxlabel::TcxLabel* bvlRefinementsSeparator;
	Cxdropdownedit::TcxComboBox* cbxLookAndFeel;
	Cxspinedit::TcxSpinEdit* sePreviewMaxLineCount;
	Cxspinedit::TcxSpinEdit* seCardsSpaceVert;
	Cxspinedit::TcxSpinEdit* seCardsSpaceHorz;
	Cxspinedit::TcxSpinEdit* seCardsShadowDepth;
	Cxcolorcombobox::TcxColorComboBox* ccbxCardsShadowColor;
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
	Cxdropdownedit::TcxComboBox* cbxStyleSheets;
	Cxgraphics::TcxImageList* ilStylesPopup;
	void __fastcall OptionsViewClick(System::TObject* Sender);
	void __fastcall OptionsOnEveryPageClick(System::TObject* Sender);
	void __fastcall OptionsSelectionClick(System::TObject* Sender);
	void __fastcall OptionsExpandingClick(System::TObject* Sender);
	void __fastcall OptionsRefinementClick(System::TObject* Sender);
	void __fastcall LookAndFeelClick(System::TObject* Sender);
	void __fastcall PreviewVisibleClick(System::TObject* Sender);
	void __fastcall PreviewAutoHeightClick(System::TObject* Sender);
	void __fastcall OptionsCardsClick(System::TObject* Sender);
	void __fastcall IsSUVModelCustomDrawCell(Cxgridcustomtableview::TcxCustomGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomtableview::TcxGridTableDataCellViewInfo* AViewInfo, bool &ADone);
	void __fastcall VendorLogoCustomDrawCell(Cxgridcustomtableview::TcxCustomGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomtableview::TcxGridTableDataCellViewInfo* AViewInfo, bool &ADone);
	void __fastcall PreviewBandedViewCustomDrawColumnHeader(Cxgridtableview::TcxGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxgridtableview::TcxGridColumnHeaderViewInfo* AViewInfo, bool &ADone);
	void __fastcall PreviewBandedViewCustomDrawBandHeader(Cxgridbandedtableview::TcxGridBandedTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxgridbandedtableview::TcxGridBandHeaderViewInfo* AViewInfo, bool &ADone);
	void __fastcall PreviewBandedViewCustomDrawFooterCell(Cxgridtableview::TcxGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxgridtableview::TcxGridColumnHeaderViewInfo* AViewInfo, bool &ADone);
	void __fastcall OptionsDetailsClick(System::TObject* Sender);
	void __fastcall OptionsSizeClick(System::TObject* Sender);
	void __fastcall OptionsLevelsClick(System::TObject* Sender);
	void __fastcall OptionsFormatingClick(System::TObject* Sender);
	void __fastcall StyleColorClick(System::TObject* Sender);
	void __fastcall StyleFontClick(System::TObject* Sender);
	void __fastcall StyleBackgroundBitmapClick(System::TObject* Sender);
	void __fastcall lbxStylesClick(System::TObject* Sender);
	void __fastcall pmStylesPopup(System::TObject* Sender);
	void __fastcall cbxStyleSheetsClick(System::TObject* Sender);
	void __fastcall StyleSheetNewClick(System::TObject* Sender);
	void __fastcall StyleSheetCopyClick(System::TObject* Sender);
	void __fastcall StyleSheetDeleteClick(System::TObject* Sender);
	void __fastcall StylesSaveAsClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall StyleSheetRenameClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall StyleBackgroundBitmapClearClick(System::TObject* Sender);
	void __fastcall StyleRestoreDefaultsClick(System::TObject* Sender);
	void __fastcall miStylesSelectAllClick(System::TObject* Sender);
	void __fastcall OptionsPaginationClick(System::TObject* Sender);
	void __fastcall lblUseNativeStylesClick(System::TObject* Sender);
	void __fastcall chbxChartsTransparentClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall CardShadowDepthChanged(System::TObject* Sender);
	void __fastcall CardShadowColorChanged(System::TObject* Sender);
	void __fastcall CardSpaceHorzChanged(System::TObject* Sender);
	void __fastcall CardSpaceVertChanged(System::TObject* Sender);
	void __fastcall PreviewMaxLineCountChanged(System::TObject* Sender);
	
private:
	Dxpscxcommon::TdxStylesListBox* lbxStyles;
	TcxGridCardView2* PreviewCardView;
	Cxgridchartview::TcxGridChartView* PreviewCharView;
	Cxgridcardview::TcxGridCardViewRow* rowCarModel;
	Cxgridcardview::TcxGridCardViewRow* rowIsSuvModel;
	Cxgridcardview::TcxGridCardViewRow* rowVendorCountry;
	Cxgridcardview::TcxGridCardViewRow* rowVendorLogo;
	Cxgridcardview::TcxGridCardViewRow* rowVendorName;
	Dxextctrls::TdxPSWarningPane* wpIncorrectOnEveryPageState;
	Cxstyles::TcxStyle* __fastcall GetActiveStyle(void);
	bool __fastcall GetHasSelectedStyles(void);
	bool __fastcall GetHasSelectedStylesWithAssignedBitmap(void);
	HIDESBASE TdxGridReportLink* __fastcall GetReportLink(void);
	bool __fastcall CanSelectAllStyles(void);
	void __fastcall ChangeActiveView(Cxgridcustomview::TcxCustomGridView* AView);
	void __fastcall CreateCardView(void);
	void __fastcall CreateChartView(void);
	void __fastcall CreateControls(void);
	void __fastcall CustomDrawBorders(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo);
	void __fastcall CustomDrawFooter(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo);
	void __fastcall CustomDrawHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo);
	void __fastcall CustomDrawTextRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo, Vcl::Graphics::TBitmap* ABackgroundBitmap);
	void __fastcall InitializePreviewGrid(void);
	void __fastcall InitializePreviewGridStyles(void);
	void __fastcall LoadDataIntoPreviewGridChartView(Cxgridchartview::TcxGridChartView* AView);
	void __fastcall LoadDataIntoPreviewGridView(Cxgridcustomtableview::TcxCustomGridTableView* AView);
	void __fastcall RecreateStylesListBox(void);
	void __fastcall RestoreSelectedStyles(System::Classes::TList* AList);
	void __fastcall SaveSelectedStyles(System::Classes::TList* AList);
	void __fastcall SetActivePage(void);
	void __fastcall UpdatePreviewGridStyles(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	void __fastcall UpdateWarningPane(void);
	void __fastcall SetOptionsCardsByIndex(int Index, bool Value);
	void __fastcall SetOptionsChartsByIndex(int Index, bool Value);
	void __fastcall SetOptionsDetailsByIndex(int Index, bool Value);
	void __fastcall SetOptionsExpandingByIndex(int Index, bool Value);
	void __fastcall SetOptionsFormattingByIndex(int Index, bool Value);
	void __fastcall SetOptionsLevelsByIndex(int Index, bool Value);
	void __fastcall SetOptionsOnEveryPageByIndex(int Index, bool Value);
	void __fastcall SetOptionsPaginationByIndex(int Index, bool Value);
	void __fastcall SetOptionsRefinementsByIndex(int Index, bool Value);
	void __fastcall SetOptionsSelectionByIndex(int Index, bool Value);
	void __fastcall SetOptionsSizeByIndex(int Index, bool Value);
	void __fastcall SetOptionsViewByIndex(int Index, bool Value);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	virtual int __fastcall GetDesignerTabIndex(void);
	virtual void __fastcall SetDesignerTabIndex(int Value);
	DYNAMIC void __fastcall DoActiveStyleSheetChanged(void);
	DYNAMIC void __fastcall DoFormActivated(bool AnActive);
	DYNAMIC void __fastcall DoRefreshStylesList(void);
	DYNAMIC void __fastcall DoStyleChanged(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	DYNAMIC void __fastcall DoStylesChanged(System::Classes::TStrings* AStrings, bool ARecreate);
	virtual void __fastcall GetSelectedStyleNames(System::Classes::TStrings* AStrings);
	virtual void __fastcall GetStyleNames(/* out */ System::Classes::TStrings* &AStrings);
	virtual void __fastcall GetStyleSheetNames(/* out */ System::Classes::TStrings* &AStrings);
	__property Cxstyles::TcxStyle* ActiveStyle = {read=GetActiveStyle};
	__property bool HasSelectedStyles = {read=GetHasSelectedStyles, nodefault};
	__property bool HasSelectedStylesWithAssignedBitmap = {read=GetHasSelectedStylesWithAssignedBitmap, nodefault};
	
public:
	__fastcall virtual TdxfmGridReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmGridReportLinkDesignWindow(void);
	__property TdxGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmGridReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmGridReportLinkDesignWindow(HWND ParentWindow) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 vspsGridFirst = System::Int8(0x0);
static const System::Int8 vspsGridBandHeader = System::Int8(0x0);
static const System::Int8 vspsGridCaption = System::Int8(0x1);
static const System::Int8 vspsGridCardCaptionRow = System::Int8(0x2);
static const System::Int8 vspsGridCardRowCaption = System::Int8(0x3);
static const System::Int8 vspsGridContent = System::Int8(0x4);
static const System::Int8 vspsGridContentEven = System::Int8(0x5);
static const System::Int8 vspsGridContentOdd = System::Int8(0x6);
static const System::Int8 vspsGridFilterBar = System::Int8(0x7);
static const System::Int8 vspsGridFooter = System::Int8(0x8);
static const System::Int8 vspsGridGroup = System::Int8(0x9);
static const System::Int8 vspsGridHeader = System::Int8(0xa);
static const System::Int8 vspsGridPreview = System::Int8(0xb);
static const System::Int8 vspsGridSelection = System::Int8(0xc);
static const System::Int8 vspsGridLast = System::Int8(0xc);
static const System::Int8 vsCardShadow = System::Int8(0x10);
static const System::Int8 vsCardViewLast = System::Int8(0x10);
static const System::Int8 bbTabs = System::Int8(-1);
static const System::Int8 dxDefaultInterRecordsSpaceHorz = System::Int8(0x4);
static const System::Int8 dxDefaultInterRecordsSpaceVert = System::Int8(0x4);
static const System::Int8 dxDefaultCardsShadowDepth = System::Int8(0x4);
static const int dxDefaultCardsShadowColor = int(0);
static const System::Int8 dxGridAttributeIDBase = System::Int8(0x0);
static const System::Int8 dxGridUndefinedID = System::Int8(0x0);
static const System::Int8 dxGridBandID = System::Int8(0x1);
static const System::Int8 dxGridCardRowCaptionID = System::Int8(0x2);
static const System::Int8 dxGridCardRowDataID = System::Int8(0x3);
static const System::Int8 dxGridFilterBarID = System::Int8(0x4);
static const System::Int8 dxGridFooterID = System::Int8(0x5);
static const System::Int8 dxGridGroupFooterID = System::Int8(0x6);
static const System::Int8 dxGridHeaderID = System::Int8(0x7);
static const System::Int8 dxGridLevelCaptionID = System::Int8(0x8);
static const System::Int8 dxGridRecordID = System::Int8(0x9);
}	/* namespace Dxpscxgridlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXGRIDLNK)
using namespace Dxpscxgridlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxgridlnkHPP
