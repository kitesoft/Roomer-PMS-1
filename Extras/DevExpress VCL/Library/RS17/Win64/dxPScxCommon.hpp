// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxCommon.pas' rev: 24.00 (Win64)

#ifndef DxpscxcommonHPP
#define DxpscxcommonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxBlobEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxHyperLinkEdit.hpp>	// Pascal unit
#include <cxCurrencyEdit.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSRes.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxcommon
{
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TdxReportItemViewParams
{
public:
	Dxpscore::TdxCellSides CellSides;
	int FontSize;
	System::Uitypes::TFontStyles FontStyle;
	bool Transparent;
	Cxgraphics::TcxViewParams NativeParams;
};


__interface IdxPSCellParams;
typedef System::DelphiInterface<IdxPSCellParams> _di_IdxPSCellParams;
__interface  INTERFACE_UUID("{F0A495A1-1F0F-4245-A437-16E21ACF9FED}") IdxPSCellParams  : public System::IInterface 
{
	
public:
	virtual bool __fastcall GetAutoHeight(void) = 0 ;
	virtual Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetCanvas(void) = 0 ;
	virtual bool __fastcall GetDisplayGraphicsAsText(void) = 0 ;
	virtual bool __fastcall GetEndEllipsis(void) = 0 ;
	virtual bool __fastcall GetFlatCheckMarks(void) = 0 ;
	virtual System::UnicodeString __fastcall GetGraphicsText(void) = 0 ;
	virtual bool __fastcall GetMultiline(void) = 0 ;
	virtual bool __fastcall GetTransparentGraphics(void) = 0 ;
	__property bool AutoHeight = {read=GetAutoHeight};
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* Canvas = {read=GetCanvas};
	__property bool DisplayGraphicsAsText = {read=GetDisplayGraphicsAsText};
	__property bool EndEllipsis = {read=GetEndEllipsis};
	__property bool FlatCheckMarks = {read=GetFlatCheckMarks};
	__property System::UnicodeString GraphicsText = {read=GetGraphicsText};
	__property bool Multiline = {read=GetMultiline};
	__property bool TransparentGraphics = {read=GetTransparentGraphics};
};

__interface IdxPSCellParams2;
typedef System::DelphiInterface<IdxPSCellParams2> _di_IdxPSCellParams2;
__interface  INTERFACE_UUID("{09EAB051-1AC2-46FB-A7F4-D6BFA883D015}") IdxPSCellParams2  : public System::IInterface 
{
	
public:
	virtual int __fastcall GetPreviewMarginLeft(void) = 0 ;
	virtual int __fastcall GetPreviewMarginRight(void) = 0 ;
	virtual int __fastcall GetPreviewMaxHeight(void) = 0 ;
	virtual int __fastcall GetPreviewMaxLineCount(void) = 0 ;
	virtual Vcl::Graphics::TGraphicClass __fastcall GetRichEditGraphicClass(void) = 0 ;
	virtual bool __fastcall GetRichEditTransparent(void) = 0 ;
	__property int PreviewMarginLeft = {read=GetPreviewMarginLeft};
	__property int PreviewMarginRight = {read=GetPreviewMarginRight};
	__property int PreviewMaxHeight = {read=GetPreviewMaxHeight};
	__property int PreviewMaxLineCount = {read=GetPreviewMaxLineCount};
	__property Vcl::Graphics::TGraphicClass RichEditGraphicClass = {read=GetRichEditGraphicClass};
	__property bool RichEditTransparent = {read=GetRichEditTransparent};
};

typedef System::TMetaClass* TdxPSDataMapClass;

class DELPHICLASS TdxPSDataMaps;
class PASCALIMPLEMENTATION TdxPSDataMaps : public Dxbase::TdxCustomClassMaps
{
	typedef Dxbase::TdxCustomClassMaps inherited;
	
public:
	TdxPSDataMapClass operator[](Cxedit::TcxCustomEditProperties* Properties) { return MapClasses[Properties]; }
	
private:
	TdxPSDataMapClass __fastcall GetMapClass(Cxedit::TcxCustomEditProperties* Properties);
	
public:
	__classmethod TdxPSDataMaps* __fastcall Instance()/* overload */;
	bool __fastcall DoesItemParticipateInAutoHeightCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	bool __fastcall DoesItemParticipateInAutoWidthCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	void __fastcall GetImageLists(Cxedit::TcxCustomEditProperties* AProperties, Dxpscore::TdxPSGetImageListProc AProc);
	void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__property TdxPSDataMapClass MapClasses[Cxedit::TcxCustomEditProperties* Properties] = {read=GetMapClass/*, default*/};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSDataMaps(int Dummy) : Dxbase::TdxCustomClassMaps(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSDataMaps(void) : Dxbase::TdxCustomClassMaps() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSDataMaps(void) { }
	
};


class DELPHICLASS TdxPSCustomDataMap;
class PASCALIMPLEMENTATION TdxPSCustomDataMap : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
protected:
	__classmethod virtual bool __fastcall DoesItemParticipateInAutoHeightCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual bool __fastcall DoesItemParticipateInAutoWidthCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall GetImageLists(Cxedit::TcxCustomEditProperties* AProperties, Dxpscore::TdxPSGetImageListProc AProc);
	__classmethod virtual System::UnicodeString __fastcall GetText(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual bool __fastcall HasText(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
	
public:
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
public:
	/* TObject.Create */ inline __fastcall TdxPSCustomDataMap(void) : Dxbase::TdxCustomClassMapItem() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomDataMap(void) { }
	
};


class DELPHICLASS TdxPSTextDataMap;
class PASCALIMPLEMENTATION TdxPSTextDataMap : public TdxPSCustomDataMap
{
	typedef TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSTextDataMap(void) : TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTextDataMap(void) { }
	
};


class DELPHICLASS TdxPSMemoDataMap;
class PASCALIMPLEMENTATION TdxPSMemoDataMap : public TdxPSTextDataMap
{
	typedef TdxPSTextDataMap inherited;
	
protected:
	__classmethod virtual bool __fastcall DoesItemParticipateInAutoWidthCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSMemoDataMap(void) : TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSMemoDataMap(void) { }
	
};


class DELPHICLASS TdxPSHyperLinkDataMap;
class PASCALIMPLEMENTATION TdxPSHyperLinkDataMap : public TdxPSTextDataMap
{
	typedef TdxPSTextDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSHyperLinkDataMap(void) : TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSHyperLinkDataMap(void) { }
	
};


class DELPHICLASS TdxPSCheckDataMap;
class PASCALIMPLEMENTATION TdxPSCheckDataMap : public TdxPSCustomDataMap
{
	typedef TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSCheckDataMap(void) : TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCheckDataMap(void) { }
	
};


class DELPHICLASS TdxPSCustomButtonGroupDataMap;
class PASCALIMPLEMENTATION TdxPSCustomButtonGroupDataMap : public TdxPSCustomDataMap
{
	typedef TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual Dxpscore::TdxCustomReportButtonGroupClass __fastcall ButtonGroupClass(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeGroupButton(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, Dxpscore::TdxCustomReportCellCheck* AButton, int AnIndex);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSCustomButtonGroupDataMap(void) : TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomButtonGroupDataMap(void) { }
	
};


class DELPHICLASS TdxPSRadioButtonGroupDataMap;
class PASCALIMPLEMENTATION TdxPSRadioButtonGroupDataMap : public TdxPSCustomButtonGroupDataMap
{
	typedef TdxPSCustomButtonGroupDataMap inherited;
	
protected:
	__classmethod virtual Dxpscore::TdxCustomReportButtonGroupClass __fastcall ButtonGroupClass(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSRadioButtonGroupDataMap(void) : TdxPSCustomButtonGroupDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSRadioButtonGroupDataMap(void) { }
	
};


class DELPHICLASS TdxPSGraphicDataMap;
class PASCALIMPLEMENTATION TdxPSGraphicDataMap : public TdxPSCustomDataMap
{
	typedef TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual bool __fastcall DoesItemParticipateInAutoHeightCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall DefaultGraphicClass();
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(Cxedit::TcxCustomEditProperties* AProperties, Vcl::Graphics::TGraphicClass AGraphicClass, const System::Variant &AValue);
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(Cxedit::TcxCustomEditProperties* AProperties, int ARecordIndex, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual bool __fastcall HasGraphic(const System::Variant &AValue);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSGraphicDataMap(void) : TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSGraphicDataMap(void) { }
	
};


class DELPHICLASS TdxPSGraphicAsTextDataMap;
class PASCALIMPLEMENTATION TdxPSGraphicAsTextDataMap : public TdxPSCustomDataMap
{
	typedef TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSGraphicAsTextDataMap(void) : TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSGraphicAsTextDataMap(void) { }
	
};


class DELPHICLASS TdxPSImageDataMap;
class PASCALIMPLEMENTATION TdxPSImageDataMap : public TdxPSTextDataMap
{
	typedef TdxPSTextDataMap inherited;
	
protected:
	__classmethod virtual bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cximagecombobox::TcxImageComboBoxItem* __fastcall GetComboBoxItem(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual int __fastcall GetImageIndex(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual void __fastcall GetImageLists(Cxedit::TcxCustomEditProperties* AProperties, Dxpscore::TdxPSGetImageListProc AProc);
	__classmethod virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual System::UnicodeString __fastcall GetText(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual bool __fastcall HasImages(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual bool __fastcall IsMultilinedText(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSImageDataMap(void) : TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSImageDataMap(void) { }
	
};


class DELPHICLASS TdxPSDelegateDataMap;
class PASCALIMPLEMENTATION TdxPSDelegateDataMap : public TdxPSCustomDataMap
{
	typedef TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual TdxPSDataMapClass __fastcall DataMapClass(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual bool __fastcall DoesItemParticipateInAutoHeightCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual bool __fastcall DoesItemParticipateInAutoWidthCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall GetImageLists(Cxedit::TcxCustomEditProperties* AProperties, Dxpscore::TdxPSGetImageListProc AProc);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
public:
	/* TObject.Create */ inline __fastcall TdxPSDelegateDataMap(void) : TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSDelegateDataMap(void) { }
	
};


class DELPHICLASS TdxPSBlobDataMap;
class PASCALIMPLEMENTATION TdxPSBlobDataMap : public TdxPSDelegateDataMap
{
	typedef TdxPSDelegateDataMap inherited;
	
protected:
	__classmethod virtual TdxPSDataMapClass __fastcall DataMapClass(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSBlobDataMap(void) : TdxPSDelegateDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSBlobDataMap(void) { }
	
};


class DELPHICLASS TdxPSBlobDefaultDataMap;
class PASCALIMPLEMENTATION TdxPSBlobDefaultDataMap : public TdxPSTextDataMap
{
	typedef TdxPSTextDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
public:
	/* TObject.Create */ inline __fastcall TdxPSBlobDefaultDataMap(void) : TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSBlobDefaultDataMap(void) { }
	
};


class DELPHICLASS TdxPSBlobTextDataMap;
class PASCALIMPLEMENTATION TdxPSBlobTextDataMap : public TdxPSTextDataMap
{
	typedef TdxPSTextDataMap inherited;
	
protected:
	__classmethod virtual bool __fastcall DoesItemParticipateInAutoWidthCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
public:
	/* TObject.Create */ inline __fastcall TdxPSBlobTextDataMap(void) : TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSBlobTextDataMap(void) { }
	
};


class DELPHICLASS TdxPSBlobPictureDataMap;
class PASCALIMPLEMENTATION TdxPSBlobPictureDataMap : public TdxPSCustomDataMap
{
	typedef TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall GetImageLists(Cxedit::TcxCustomEditProperties* AProperties, Dxpscore::TdxPSGetImageListProc AProc);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0x0, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const _di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
public:
	/* TObject.Create */ inline __fastcall TdxPSBlobPictureDataMap(void) : TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSBlobPictureDataMap(void) { }
	
};


class DELPHICLASS TdxReportCellPreviewText;
class PASCALIMPLEMENTATION TdxReportCellPreviewText : public Dxpscore::TdxReportCellString
{
	typedef Dxpscore::TdxReportCellString inherited;
	
private:
	int FMaxLineCount;
	int FRightIndent;
	int __fastcall GetLeftIndent(void);
	void __fastcall SetLeftIndent(int Value);
	void __fastcall SetMaxLineCount(int Value);
	void __fastcall SetRightIndent(int Value);
	
protected:
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawText(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property int LeftIndent = {read=GetLeftIndent, write=SetLeftIndent, nodefault};
	__property int MaxLineCount = {read=FMaxLineCount, write=SetMaxLineCount, nodefault};
	__property PreventLeftTextExceed;
	__property PreventTopTextExceed;
	__property int RightIndent = {read=FRightIndent, write=SetRightIndent, nodefault};
	__property TextAlignX = {default=0};
	__property TextAlignY = {default=1};
public:
	/* TdxReportCellText.Create */ inline __fastcall virtual TdxReportCellPreviewText(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCellString(AParent) { }
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportCellPreviewText(void) { }
	
};


__interface IdxReportLinkOptionsDesignerSupport;
typedef System::DelphiInterface<IdxReportLinkOptionsDesignerSupport> _di_IdxReportLinkOptionsDesignerSupport;
__interface  INTERFACE_UUID("{98EBA10A-01A5-4011-ABA0-C52CE12F5553}") IdxReportLinkOptionsDesignerSupport  : public System::IInterface 
{
	
public:
	virtual void __fastcall DesignerFinalize(void) = 0 ;
	virtual void __fastcall DesignerInitialize(void) = 0 ;
	virtual int __fastcall DesignerTabIndex(void) = 0 ;
};

typedef System::TMetaClass* TdxCustomReportLinkStylesClass;

class DELPHICLASS TdxCustomReportLinkStyles;
class DELPHICLASS TdxCustomcxControlReportLink;
class PASCALIMPLEMENTATION TdxCustomReportLinkStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	TdxCustomcxControlReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual void __fastcall DesignerFinalize(void);
	virtual void __fastcall DesignerInitialize(void);
	virtual int __fastcall DesignerTabIndex(void);
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall GetDefaultViewParamsByCaption(const System::UnicodeString ACaption, void * AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__classmethod virtual System::UnicodeString __fastcall GetStyleCaption(int AnIndex);
	virtual Cxstyles::TcxStyle* __fastcall GetStyleByCaption(const System::UnicodeString Caption);
	virtual int __fastcall GetStyleIndexByCaption(const System::UnicodeString Caption) = 0 ;
	virtual void __fastcall SetStyleByCaption(const System::UnicodeString Caption, Cxstyles::TcxStyle* Value);
	__property int StyleIndexesByCaption[const System::UnicodeString Caption] = {read=GetStyleIndexByCaption};
	
public:
	__property TdxCustomcxControlReportLink* ReportLink = {read=GetReportLink};
	__property Cxstyles::TcxStyle* StylesByCaption[const System::UnicodeString Caption] = {read=GetStyleByCaption, write=SetStyleByCaption};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TdxCustomReportLinkStyles(System::Classes::TPersistent* AOwner) : Cxstyles::TcxStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TdxCustomReportLinkStyles(void) { }
	
private:
	void *__IdxReportLinkOptionsDesignerSupport;	/* IdxReportLinkOptionsDesignerSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {98EBA10A-01A5-4011-ABA0-C52CE12F5553}
	operator _di_IdxReportLinkOptionsDesignerSupport()
	{
		_di_IdxReportLinkOptionsDesignerSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxReportLinkOptionsDesignerSupport*(void) { return (IdxReportLinkOptionsDesignerSupport*)&__IdxReportLinkOptionsDesignerSupport; }
	#endif
	
};


typedef System::TMetaClass* TdxCustomReportLinkStyleSheetClass;

class DELPHICLASS TdxCustomReportLinkStyleSheet;
class PASCALIMPLEMENTATION TdxCustomReportLinkStyleSheet : public Cxstyles::TcxCustomStyleSheet
{
	typedef Cxstyles::TcxCustomStyleSheet inherited;
	
public:
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TdxCustomReportLinkStyleSheet(System::Classes::TComponent* AOwner) : Cxstyles::TcxCustomStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TdxCustomReportLinkStyleSheet(void) { }
	
};


typedef System::TMetaClass* TdxCustomReportLinkOptionsClass;

class DELPHICLASS TdxCustomReportLinkOptions;
class PASCALIMPLEMENTATION TdxCustomReportLinkOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxCustomcxControlReportLink* FReportLink;
	
protected:
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	virtual void __fastcall DesignerFinalize(void);
	virtual void __fastcall DesignerInitialize(void);
	virtual int __fastcall DesignerTabIndex(void);
	virtual void __fastcall Changed(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	virtual void __fastcall CreateObjects(void);
	virtual void __fastcall DestroyObjects(void);
	void __fastcall DesignerModified(void);
	
public:
	__fastcall virtual TdxCustomReportLinkOptions(TdxCustomcxControlReportLink* AReportLink);
	__fastcall virtual ~TdxCustomReportLinkOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TdxCustomcxControlReportLink* ReportLink = {read=FReportLink};
private:
	void *__IdxReportLinkOptionsDesignerSupport;	/* IdxReportLinkOptionsDesignerSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {98EBA10A-01A5-4011-ABA0-C52CE12F5553}
	operator _di_IdxReportLinkOptionsDesignerSupport()
	{
		_di_IdxReportLinkOptionsDesignerSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxReportLinkOptionsDesignerSupport*(void) { return (IdxReportLinkOptionsDesignerSupport*)&__IdxReportLinkOptionsDesignerSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IdxReportLinkOptionsDesignerSupport; }
	#endif
	
};


typedef System::TMetaClass* TdxCustomReportLinkOptionsExpandingClass;

class DELPHICLASS TdxCustomReportLinkOptionsExpanding;
class PASCALIMPLEMENTATION TdxCustomReportLinkOptionsExpanding : public TdxCustomReportLinkOptions
{
	typedef TdxCustomReportLinkOptions inherited;
	
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomReportLinkOptionsExpanding(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomReportLinkOptionsExpanding(void) { }
	
};


typedef System::TMetaClass* TdxCustomReportLinkOptionsFormattingClass;

class DELPHICLASS TdxCustomReportLinkOptionsFormatting;
class PASCALIMPLEMENTATION TdxCustomReportLinkOptionsFormatting : public TdxCustomReportLinkOptions
{
	typedef TdxCustomReportLinkOptions inherited;
	
private:
	System::Uitypes::TColor FGridLineColor;
	Cxlookandfeels::TcxLookAndFeelKind FLookAndFeelKind;
	bool FSuppressBackgroundBitmaps;
	bool FUseLookAndFeelColors;
	bool FUseNativeStyles;
	void __fastcall SetGridLineColor(System::Uitypes::TColor Value);
	void __fastcall SetLookAndFeelKind(Cxlookandfeels::TcxLookAndFeelKind Value);
	void __fastcall SetSuppressBackgroundBitmaps(bool Value);
	void __fastcall SetUseLookAndFeelColors(bool Value);
	void __fastcall SetUseNativeStyles(bool Value);
	
protected:
	__property bool UseLookAndFeelColors = {read=FUseLookAndFeelColors, write=SetUseLookAndFeelColors, default=0};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property System::Uitypes::TColor GridLineColor = {read=FGridLineColor, write=SetGridLineColor, default=536870912};
	__property Cxlookandfeels::TcxLookAndFeelKind LookAndFeelKind = {read=FLookAndFeelKind, write=SetLookAndFeelKind, default=2};
	__property bool SuppressBackgroundBitmaps = {read=FSuppressBackgroundBitmaps, write=SetSuppressBackgroundBitmaps, default=0};
	__property bool UseNativeStyles = {read=FUseNativeStyles, write=SetUseNativeStyles, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomReportLinkOptionsFormatting(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomReportLinkOptionsFormatting(void) { }
	
};


typedef System::TMetaClass* TdxCustomReportLinkOptionsPaginationClass;

class DELPHICLASS TdxCustomReportLinkOptionsPagination;
class PASCALIMPLEMENTATION TdxCustomReportLinkOptionsPagination : public TdxCustomReportLinkOptions
{
	typedef TdxCustomReportLinkOptions inherited;
	
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomReportLinkOptionsPagination(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomReportLinkOptionsPagination(void) { }
	
};


typedef System::TMetaClass* TdxCustomReportLinkOptionsRefinementsClass;

class DELPHICLASS TdxCustomReportLinkOptionsRefinements;
class PASCALIMPLEMENTATION TdxCustomReportLinkOptionsRefinements : public TdxCustomReportLinkOptions
{
	typedef TdxCustomReportLinkOptions inherited;
	
private:
	bool FDisplayGraphicsAsText;
	bool FFlatCheckMarks;
	System::UnicodeString FGraphicsText;
	bool FIsGraphicsTextAssigned;
	bool FTransparentGraphics;
	bool FTransparentRichEdits;
	System::UnicodeString __fastcall GetGraphicsText(void);
	bool __fastcall IsGraphicsTextStored(void);
	void __fastcall SetDisplayGraphicsAsText(bool Value);
	void __fastcall SetFlatCheckMarks(bool Value);
	void __fastcall SetGraphicsText(const System::UnicodeString Value);
	void __fastcall SetTransparentGraphics(bool Value);
	void __fastcall SetTransparentRichEdits(bool Value);
	void __fastcall ReadIsGraphicsTextAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteIsGraphicsTextAssigned(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultGraphicsText(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool DisplayGraphicsAsText = {read=FDisplayGraphicsAsText, write=SetDisplayGraphicsAsText, default=0};
	__property bool FlatCheckMarks = {read=FFlatCheckMarks, write=SetFlatCheckMarks, default=1};
	__property System::UnicodeString GraphicsText = {read=GetGraphicsText, write=SetGraphicsText, stored=IsGraphicsTextStored};
	__property bool TransparentGraphics = {read=FTransparentGraphics, write=SetTransparentGraphics, default=0};
	__property bool TransparentRichEdits = {read=FTransparentRichEdits, write=SetTransparentRichEdits, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomReportLinkOptionsRefinements(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomReportLinkOptionsRefinements(void) { }
	
};


typedef System::TMetaClass* TdxCustomReportLinkOptionsSizeClass;

class DELPHICLASS TdxCustomReportLinkOptionsSize;
class PASCALIMPLEMENTATION TdxCustomReportLinkOptionsSize : public TdxCustomReportLinkOptions
{
	typedef TdxCustomReportLinkOptions inherited;
	
private:
	bool FAutoWidth;
	void __fastcall SetAutoWidth(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property bool AutoWidth = {read=FAutoWidth, write=SetAutoWidth, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomReportLinkOptionsSize(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomReportLinkOptionsSize(void) { }
	
};


typedef System::TMetaClass* TdxCustomReportLinkOptionsViewClass;

class DELPHICLASS TdxCustomReportLinkOptionsView;
class PASCALIMPLEMENTATION TdxCustomReportLinkOptionsView : public TdxCustomReportLinkOptions
{
	typedef TdxCustomReportLinkOptions inherited;
	
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomReportLinkOptionsView(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomReportLinkOptionsView(void) { }
	
};


typedef bool __fastcall (__closure *TdxStyleSheetHasCaptionProc)(const System::UnicodeString ACaption);

class DELPHICLASS TdxfmCustomcxControlReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxCustomcxControlReportLink : public Dxpscore::TBasedxReportLink
{
	typedef Dxpscore::TBasedxReportLink inherited;
	
private:
	System::Classes::TList* FDelimitersHorz;
	System::Classes::TList* FDelimitersVert;
	int FDesignerTabIndex;
	System::Classes::TList* FImageLists;
	System::Classes::TList* FOptions;
	TdxCustomReportLinkOptionsExpanding* FOptionsExpanding;
	TdxCustomReportLinkOptionsFormatting* FOptionsFormatting;
	TdxCustomReportLinkOptionsPagination* FOptionsPagination;
	TdxCustomReportLinkOptionsRefinements* FOptionsRefinements;
	TdxCustomReportLinkOptionsSize* FOptionsSize;
	TdxCustomReportLinkOptionsView* FOptionsView;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* FScreenCanvas;
	Cxstyles::TcxStyleRepository* FStyleRepository;
	TdxCustomReportLinkStyles* FStyles;
	bool FSupportedCustomDraw;
	TdxCustomReportLinkStyles* __fastcall GetActiveStyles(void);
	TdxfmCustomcxControlReportLinkDesignWindow* __fastcall GetDesignWindow(void);
	bool __fastcall GetEffects3D(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImageList(int Index);
	int __fastcall GetImageListCount(void);
	TdxCustomReportLinkOptions* __fastcall GetOptions(int Index);
	int __fastcall GetOptionsCount(void);
	bool __fastcall GetSoft3D(void);
	void __fastcall SetOptionsExpanding(TdxCustomReportLinkOptionsExpanding* Value);
	void __fastcall SetOptionsFormatting(TdxCustomReportLinkOptionsFormatting* Value);
	void __fastcall SetOptionsPagination(TdxCustomReportLinkOptionsPagination* Value);
	void __fastcall SetOptionsRefinements(TdxCustomReportLinkOptionsRefinements* Value);
	void __fastcall SetOptionsSize(TdxCustomReportLinkOptionsSize* Value);
	void __fastcall SetOptionsView(TdxCustomReportLinkOptionsView* Value);
	void __fastcall SetStyleRepository(Cxstyles::TcxStyleRepository* Value);
	void __fastcall SetStyles(TdxCustomReportLinkStyles* Value);
	void __fastcall SetSupportedCustomDraw(bool Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall BeforeDesignReport(void);
	virtual void __fastcall ConvertCoords(void);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	virtual void __fastcall MakeDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	void __fastcall AddHorizontalDelimiter(Dxpscore::TdxReportCell* ADelimiter)/* overload */;
	void __fastcall AddHorizontalDelimiter(int ADelimiter)/* overload */;
	void __fastcall AddVerticalDelimiter(Dxpscore::TdxReportCell* ADelimiter)/* overload */;
	void __fastcall AddVerticalDelimiter(int ADelimiter)/* overload */;
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual TdxCustomReportLinkOptionsExpandingClass __fastcall GetOptionsExpandingClass(void);
	virtual TdxCustomReportLinkOptionsFormattingClass __fastcall GetOptionsFormattingClass(void);
	virtual TdxCustomReportLinkOptionsPaginationClass __fastcall GetOptionsPaginationClass(void);
	virtual TdxCustomReportLinkOptionsRefinementsClass __fastcall GetOptionsRefinementsClass(void);
	virtual TdxCustomReportLinkOptionsSizeClass __fastcall GetOptionsSizeClass(void);
	virtual TdxCustomReportLinkOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual void __fastcall OptionsChanged(TdxCustomReportLinkOptions* AnOptions);
	void __fastcall AddOptions(TdxCustomReportLinkOptions* AnOptions);
	void __fastcall NotifyOptions(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	void __fastcall RemoveOptions(TdxCustomReportLinkOptions* AnOptions);
	void __fastcall AppendImageList(Vcl::Imglist::TCustomImageList* AnImageList);
	bool __fastcall CanCreateComponent(void);
	void __fastcall ConvertDelimiters(System::Classes::TList* ADelimiters);
	Cxstyles::TcxStyle* __fastcall CreateStyle(const System::UnicodeString ACaption);
	Cxstyles::TcxStyleRepository* __fastcall CreateStyleRepository(void);
	TdxCustomReportLinkStyleSheet* __fastcall CreateStyleSheet(Cxstyles::TcxCustomStyleSheet* APrototype, const System::UnicodeString ACaption, bool AUseStyles);
	Cxstyles::TcxStyleRepository* __fastcall FindStyleRepositoryInStyles(Cxstyles::TcxStyles* AStyles);
	System::Classes::TComponent* __fastcall GetChildComponentOwner(void);
	int __fastcall GetStyleConsumerCount(Cxstyles::TcxStyle* AStyle);
	virtual Cxstyles::TcxStyleRepository* __fastcall GetStyleRepository(void);
	bool __fastcall GetStyleSheetCaption(TdxStyleSheetHasCaptionProc ACheckProc, System::UnicodeString &ACaption);
	bool __fastcall InitiateStyle(const System::UnicodeString ACaption, Cxstyles::TcxStyle* &AStyle, bool AForceCreation);
	void __fastcall StyleRestoreDefaults(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	virtual void __fastcall StyleChanged(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	virtual bool __fastcall GetAreNativeStylesAvailable(void);
	virtual TdxCustomReportLinkStylesClass __fastcall GetStylesClass(void);
	virtual TdxCustomReportLinkStyleSheetClass __fastcall GetStyleSheetClass(void);
	virtual TdxCustomReportLinkStyleSheet* __fastcall GetStyleSheetPrototype(void);
	virtual void __fastcall PrepareConstruct(void);
	virtual void __fastcall UnprepareConstruct(void);
	__property TdxCustomReportLinkStyles* ActiveStyles = {read=GetActiveStyles};
	__property bool AreNativeStylesAvailable = {read=GetAreNativeStylesAvailable, nodefault};
	__property System::Classes::TList* DelimitersHorz = {read=FDelimitersHorz};
	__property System::Classes::TList* DelimitersVert = {read=FDelimitersVert};
	__property int DesignerTabIndex = {read=FDesignerTabIndex, write=FDesignerTabIndex, nodefault};
	__property bool Effects3D = {read=GetEffects3D, nodefault};
	__property int ImageListCount = {read=GetImageListCount, nodefault};
	__property Vcl::Imglist::TCustomImageList* ImageLists[int Index] = {read=GetImageList};
	__property TdxCustomReportLinkOptions* Options[int Index] = {read=GetOptions};
	__property int OptionsCount = {read=GetOptionsCount, nodefault};
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ScreenCanvas = {read=FScreenCanvas};
	__property bool Soft3D = {read=GetSoft3D, nodefault};
	__property Cxstyles::TcxStyleRepository* StyleRepository = {read=FStyleRepository, write=SetStyleRepository};
	__property TdxCustomReportLinkStyles* Styles = {read=FStyles, write=SetStyles};
	
public:
	__fastcall virtual TdxCustomcxControlReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomcxControlReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxfmCustomcxControlReportLinkDesignWindow* DesignWindow = {read=GetDesignWindow};
	__property TdxCustomReportLinkOptionsExpanding* OptionsExpanding = {read=FOptionsExpanding, write=SetOptionsExpanding};
	__property TdxCustomReportLinkOptionsFormatting* OptionsFormatting = {read=FOptionsFormatting, write=SetOptionsFormatting};
	__property TdxCustomReportLinkOptionsPagination* OptionsPagination = {read=FOptionsPagination, write=SetOptionsPagination};
	__property TdxCustomReportLinkOptionsRefinements* OptionsRefinements = {read=FOptionsRefinements, write=SetOptionsRefinements};
	__property TdxCustomReportLinkOptionsSize* OptionsSize = {read=FOptionsSize, write=SetOptionsSize};
	__property TdxCustomReportLinkOptionsView* OptionsView = {read=FOptionsView, write=SetOptionsView};
	__property bool SupportedCustomDraw = {read=FSupportedCustomDraw, write=SetSupportedCustomDraw, default=0};
};


typedef System::TMetaClass* TdxCustomTableControlReportLinkOptionsClass;

class DELPHICLASS TdxCustomTableControlReportLinkOptions;
class DELPHICLASS TdxCustomTableControlReportLink;
class PASCALIMPLEMENTATION TdxCustomTableControlReportLinkOptions : public TdxCustomReportLinkOptions
{
	typedef TdxCustomReportLinkOptions inherited;
	
private:
	TdxCustomTableControlReportLink* __fastcall GetReportLink(void);
	
public:
	__property TdxCustomTableControlReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomTableControlReportLinkOptions(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomTableControlReportLinkOptions(void) { }
	
};


typedef System::TMetaClass* TdxCustomTableControlReportLinkOptionsOnEveryPageClass;

class DELPHICLASS TdxCustomTableControlReportLinkOptionsOnEveryPage;
class PASCALIMPLEMENTATION TdxCustomTableControlReportLinkOptionsOnEveryPage : public TdxCustomTableControlReportLinkOptions
{
	typedef TdxCustomTableControlReportLinkOptions inherited;
	
private:
	bool FBandHeaders;
	bool FFooters;
	bool FHeaders;
	void __fastcall SetBandHeaders(bool Value);
	void __fastcall SetFooters(bool Value);
	void __fastcall SetHeaders(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool BandHeaders = {read=FBandHeaders, write=SetBandHeaders, default=1};
	__property bool Footers = {read=FFooters, write=SetFooters, default=1};
	__property bool Headers = {read=FHeaders, write=SetHeaders, default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomTableControlReportLinkOptionsOnEveryPage(TdxCustomcxControlReportLink* AReportLink) : TdxCustomTableControlReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomTableControlReportLinkOptionsOnEveryPage(void) { }
	
};


typedef System::TMetaClass* TdxCustomTableControlReportLinkOptionsPaginationClass;

class DELPHICLASS TdxCustomTableControlReportLinkOptionsPagination;
class PASCALIMPLEMENTATION TdxCustomTableControlReportLinkOptionsPagination : public TdxCustomReportLinkOptionsPagination
{
	typedef TdxCustomReportLinkOptionsPagination inherited;
	
private:
	bool FBand;
	bool FCustom;
	bool __fastcall GetColumn(void);
	bool __fastcall GetRow(void);
	void __fastcall SetBand(bool Value);
	void __fastcall SetColumn(bool Value);
	void __fastcall SetCustom(bool Value);
	void __fastcall SetRow(bool Value);
	
protected:
	__property bool Band = {read=FBand, write=SetBand, default=0};
	__property bool Row = {read=GetRow, write=SetRow, default=1};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property bool Column = {read=GetColumn, write=SetColumn, default=1};
	__property bool Custom = {read=FCustom, write=SetCustom, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomTableControlReportLinkOptionsPagination(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptionsPagination(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomTableControlReportLinkOptionsPagination(void) { }
	
};


typedef System::TMetaClass* TdxCustomTableControlReportLinkOptionsPreviewClass;

class DELPHICLASS TdxCustomTableControlReportLinkOptionsPreview;
class PASCALIMPLEMENTATION TdxCustomTableControlReportLinkOptionsPreview : public TdxCustomTableControlReportLinkOptions
{
	typedef TdxCustomTableControlReportLinkOptions inherited;
	
private:
	bool FAutoHeight;
	int FMaxLineCount;
	bool FVisible;
	void __fastcall SetAutoHeight(bool Value);
	void __fastcall SetMaxLineCount(int Value);
	void __fastcall SetVisible(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool AutoHeight = {read=FAutoHeight, write=SetAutoHeight, default=1};
	__property int MaxLineCount = {read=FMaxLineCount, write=SetMaxLineCount, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomTableControlReportLinkOptionsPreview(TdxCustomcxControlReportLink* AReportLink) : TdxCustomTableControlReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomTableControlReportLinkOptionsPreview(void) { }
	
};


typedef System::TMetaClass* TdxCustomTableControlReportLinkOptionsSelectionClass;

class DELPHICLASS TdxCustomTableControlReportLinkOptionsSelection;
class PASCALIMPLEMENTATION TdxCustomTableControlReportLinkOptionsSelection : public TdxCustomTableControlReportLinkOptions
{
	typedef TdxCustomTableControlReportLinkOptions inherited;
	
private:
	bool FProcessExactSelection;
	bool FProcessSelection;
	void __fastcall SetProcessExactSelection(bool Value);
	void __fastcall SetProcessSelection(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool ProcessExactSelection = {read=FProcessExactSelection, write=SetProcessExactSelection, default=0};
	__property bool ProcessSelection = {read=FProcessSelection, write=SetProcessSelection, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomTableControlReportLinkOptionsSelection(TdxCustomcxControlReportLink* AReportLink) : TdxCustomTableControlReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomTableControlReportLinkOptionsSelection(void) { }
	
};


typedef System::TMetaClass* TdxCustomTableControlReportLinkOptionsViewClass;

class DELPHICLASS TdxCustomTableControlReportLinkOptionsView;
class PASCALIMPLEMENTATION TdxCustomTableControlReportLinkOptionsView : public TdxCustomReportLinkOptionsView
{
	typedef TdxCustomReportLinkOptionsView inherited;
	
private:
	bool FBandHeaders;
	bool FExpandButtons;
	bool FFooters;
	bool FHeaders;
	void __fastcall SetBandHeaders(bool Value);
	void __fastcall SetExpandButtons(bool Value);
	void __fastcall SetFooters(bool Value);
	void __fastcall SetHeaders(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property bool BandHeaders = {read=FBandHeaders, write=SetBandHeaders, default=1};
	__property bool ExpandButtons = {read=FExpandButtons, write=SetExpandButtons, default=1};
	
__published:
	__property bool Footers = {read=FFooters, write=SetFooters, default=1};
	__property bool Headers = {read=FHeaders, write=SetHeaders, default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TdxCustomTableControlReportLinkOptionsView(TdxCustomcxControlReportLink* AReportLink) : TdxCustomReportLinkOptionsView(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TdxCustomTableControlReportLinkOptionsView(void) { }
	
};


class PASCALIMPLEMENTATION TdxCustomTableControlReportLink : public TdxCustomcxControlReportLink
{
	typedef TdxCustomcxControlReportLink inherited;
	
private:
	TdxCustomTableControlReportLinkOptionsOnEveryPage* FOptionsOnEveryPage;
	TdxCustomTableControlReportLinkOptionsPreview* FOptionsPreview;
	TdxCustomTableControlReportLinkOptionsSelection* FOptionsSelection;
	TdxCustomTableControlReportLinkOptionsPagination* __fastcall GetOptionsPagination(void);
	TdxCustomTableControlReportLinkOptionsView* __fastcall GetOptionsView(void);
	void __fastcall SetOptionsOnEveryPage(TdxCustomTableControlReportLinkOptionsOnEveryPage* Value);
	HIDESBASE void __fastcall SetOptionsPagination(TdxCustomTableControlReportLinkOptionsPagination* Value);
	void __fastcall SetOptionsPreview(TdxCustomTableControlReportLinkOptionsPreview* Value);
	void __fastcall SetOptionsSelection(TdxCustomTableControlReportLinkOptionsSelection* Value);
	HIDESBASE void __fastcall SetOptionsView(TdxCustomTableControlReportLinkOptionsView* Value);
	
protected:
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual TdxCustomTableControlReportLinkOptionsOnEveryPageClass __fastcall GetOptionsOnEveryPageClass(void);
	virtual TdxCustomReportLinkOptionsPaginationClass __fastcall GetOptionsPaginationClass(void);
	virtual TdxCustomTableControlReportLinkOptionsPreviewClass __fastcall GetOptionsPreviewClass(void);
	virtual TdxCustomTableControlReportLinkOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual TdxCustomReportLinkOptionsViewClass __fastcall GetOptionsViewClass(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxCustomTableControlReportLinkOptionsOnEveryPage* OptionsOnEveryPage = {read=FOptionsOnEveryPage, write=SetOptionsOnEveryPage};
	__property TdxCustomTableControlReportLinkOptionsPagination* OptionsPagination = {read=GetOptionsPagination, write=SetOptionsPagination};
	__property TdxCustomTableControlReportLinkOptionsPreview* OptionsPreview = {read=FOptionsPreview, write=SetOptionsPreview};
	__property TdxCustomTableControlReportLinkOptionsSelection* OptionsSelection = {read=FOptionsSelection, write=SetOptionsSelection};
	__property TdxCustomTableControlReportLinkOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
public:
	/* TdxCustomcxControlReportLink.Create */ inline __fastcall virtual TdxCustomTableControlReportLink(System::Classes::TComponent* AOwner) : TdxCustomcxControlReportLink(AOwner) { }
	/* TdxCustomcxControlReportLink.Destroy */ inline __fastcall virtual ~TdxCustomTableControlReportLink(void) { }
	
};


class PASCALIMPLEMENTATION TdxfmCustomcxControlReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
private:
	Cxstyles::TcxCustomStyleSheet* __fastcall GetActiveStyleSheet(void);
	bool __fastcall GetAreNativeStylesAvailable(void);
	TdxCustomcxControlReportLink* __fastcall GetReportLink(void);
	Cxstyles::TcxStyleRepository* __fastcall GetStyleRepository(void);
	void __fastcall SetActiveStyleSheet(Cxstyles::TcxCustomStyleSheet* Value);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &message);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual bool __fastcall CanCopyStyleSheet(void);
	virtual bool __fastcall CanCreateStyleSheet(void);
	virtual bool __fastcall CanDeleteStyleSheet(void);
	virtual bool __fastcall CanRenameStyleSheet(void);
	virtual bool __fastcall CanSaveStyles(void);
	bool __fastcall PerformStyleSheetCopy(void);
	bool __fastcall PerformStyleSheetDelete(void);
	void __fastcall PerformStyleSheetDrawItem(Vcl::Graphics::TCanvas* ACanvas, int AnIndex, System::Types::TRect &R, Winapi::Windows::TOwnerDrawState AState, bool AEnabled);
	bool __fastcall PerformStyleSheetKeyDown(System::TObject* Sender, System::Word &AKey, System::Classes::TShiftState AShift);
	bool __fastcall PerformStyleSheetNew(void);
	bool __fastcall PerformStyleSheetRename(void);
	bool __fastcall PerformStylesChangeBitmap(void);
	bool __fastcall PerformStylesChangeColor(void);
	bool __fastcall PerformStylesChangeFont(void);
	bool __fastcall PerformStylesClearBitmap(void);
	bool __fastcall PerformStylesRestoreDefaults(void);
	bool __fastcall PerformStylesSaveAsStyleSheet(void);
	void __fastcall RefreshStyleSheetList(void);
	void __fastcall RefreshStylesList(void);
	DYNAMIC void __fastcall DoActiveStyleSheetChanged(void);
	DYNAMIC void __fastcall DoFormActivated(bool AnActive);
	DYNAMIC void __fastcall DoRefreshStylesList(void);
	DYNAMIC void __fastcall DoStyleChanged(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	DYNAMIC void __fastcall DoStylesChanged(System::Classes::TStrings* AStrings, bool ARecreate);
	virtual int __fastcall GetDesignerTabIndex(void);
	virtual void __fastcall SetDesignerTabIndex(int Value);
	virtual void __fastcall GetSelectedStyleNames(System::Classes::TStrings* AStrings);
	virtual void __fastcall GetStyleNames(/* out */ System::Classes::TStrings* &AStrings);
	virtual void __fastcall GetStyleSheetNames(/* out */ System::Classes::TStrings* &AStrings);
	int __fastcall GetStyleConsumerCount(Cxstyles::TcxStyle* AStyle);
	bool __fastcall GetStyleSheetCaption(System::UnicodeString &ACaption);
	bool __fastcall HasStyleSheetWithCaption(const System::UnicodeString ACaption);
	void __fastcall InitiateStyle(const System::UnicodeString ACaption, Cxstyles::TcxStyle* &AStyle, bool AForceCreation);
	__property Cxstyles::TcxCustomStyleSheet* ActiveStyleSheet = {read=GetActiveStyleSheet, write=SetActiveStyleSheet};
	__property bool AreNativeStylesAvailable = {read=GetAreNativeStylesAvailable, nodefault};
	__property int DesignerTabIndex = {read=GetDesignerTabIndex, write=SetDesignerTabIndex, nodefault};
	__property TdxCustomcxControlReportLink* ReportLink = {read=GetReportLink};
	__property Cxstyles::TcxStyleRepository* StyleRepository = {read=GetStyleRepository};
public:
	/* TStandarddxReportLinkDesignWindow.Create */ inline __fastcall virtual TdxfmCustomcxControlReportLinkDesignWindow(System::Classes::TComponent* AOwner) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner) { }
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TdxfmCustomcxControlReportLinkDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmCustomcxControlReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmCustomcxControlReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TdxStyleBarViewInfo
{
public:
	System::Uitypes::TColor BarColor;
	Vcl::Graphics::TFont* BarFont;
	System::Uitypes::TColor BarStyleColorBoxFrameColor;
	System::UnicodeString StyleCaption;
	Vcl::Graphics::TBitmap* StyleBitmap;
	System::Types::TPoint StyleBitmapOrg;
	System::Uitypes::TColor StyleColor;
	Vcl::Graphics::TFont* StyleFont;
	System::Uitypes::TColor StyleTextColor;
	System::Types::TRect StyleCaptionBoxBounds;
	System::Types::TRect StyleColorBoxBounds;
	System::Types::TRect StyleColorBoxContentBounds;
	System::Types::TRect StyleFontInfoBoxBounds;
	int MaxWidth;
	System::Types::TRect RestSpaceBounds;
};


class DELPHICLASS TdxStylesListBoxToolTipsWindow;
class DELPHICLASS TdxStylesListBox;
class PASCALIMPLEMENTATION TdxStylesListBoxToolTipsWindow : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	int FStyleIndex;
	TdxStylesListBox* __fastcall GetListBox(void);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Paint(void);
	virtual void __fastcall CalculateStyleBarViewInfo(const System::Types::TRect &R, TdxStyleBarViewInfo &AViewInfo);
	virtual void __fastcall DrawBorder(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawStyle(System::Types::TRect &R);
	
public:
	void __fastcall Activate(const System::Types::TRect &R, int AnIndex);
	void __fastcall Deactivate(void);
	__property TdxStylesListBox* ListBox = {read=GetListBox};
	__property int StyleIndex = {read=FStyleIndex, nodefault};
public:
	/* TCustomControl.Create */ inline __fastcall virtual TdxStylesListBoxToolTipsWindow(System::Classes::TComponent* AOwner) : Vcl::Controls::TCustomControl(AOwner) { }
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TdxStylesListBoxToolTipsWindow(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxStylesListBoxToolTipsWindow(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TdxStylesListBox : public Cxlistbox::TcxListBox
{
	typedef Cxlistbox::TcxListBox inherited;
	
private:
	int FHotTrackStyleIndex;
	TdxCustomReportLinkStyles* FReportLinkStyles;
	bool FToolTips;
	Vcl::Extctrls::TTimer* FToolTipsLongHideTimer;
	Vcl::Extctrls::TTimer* FToolTipsShortHideTimer;
	TdxStylesListBoxToolTipsWindow* FToolTipsWindow;
	System::Types::TRect __fastcall GetHotTrackStyleBounds(void);
	System::UnicodeString __fastcall GetHotTrackStyleName(void);
	Cxstyles::TcxStyle* __fastcall GetSelectedStyle(void);
	HIDESBASE Cxstyles::TcxStyle* __fastcall GetStyle(int Index);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetStyleLookAndFeelPainter(void);
	System::Types::TRect __fastcall GetToolTipsBounds(void);
	void __fastcall SetReportLinkStyles(TdxCustomReportLinkStyles* Value);
	void __fastcall SetToolTips(bool Value);
	void __fastcall ToolTipsLongHideTimerHandler(System::TObject* Sender);
	void __fastcall ToolTipsShortHideTimerHandler(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Winapi::Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseWheel(Winapi::Messages::TWMMouseWheel &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Winapi::Messages::TWMScroll &Message);
	
protected:
	Vcl::Extctrls::TTimer* __fastcall CreateTimer(int AInterval, System::Classes::TNotifyEvent ATimerEvent);
	HIDESBASE virtual void __fastcall DoMeasureItem(Cxlistbox::TcxListBox* AControl, int AIndex, int &Height);
	virtual bool __fastcall DrawItem(Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall CalculateStyleBarViewInfoSizes(int AnIndex, const System::Types::TRect &R, TdxStyleBarViewInfo &AViewInfo);
	virtual void __fastcall CalculateStyleBarViewInfoViewParams(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle, const System::Types::TRect &R, bool ASelected, TdxStyleBarViewInfo &AViewInfo);
	void __fastcall CalculateStyleBarViewInfo(const System::UnicodeString ACaption, int AnIndex, Cxstyles::TcxStyle* AStyle, const System::Types::TRect &R, bool ASelected, TdxStyleBarViewInfo &AViewInfo);
	virtual System::Uitypes::TColor __fastcall GetStyleBarItemColor(bool ASelected);
	virtual System::Uitypes::TColor __fastcall GetStyleBarItemTextColor(bool ASelected, System::Uitypes::TColor AColor, System::Uitypes::TColor ABkColor);
	bool __fastcall AreToolTipsNeeded(void);
	int __fastcall FindHotTrackStyle(const System::Types::TPoint Pt);
	bool __fastcall IsHotTrackStyleViolateControlBounds(void);
	bool __fastcall IsMouseOver(void);
	void __fastcall ShowToolTips(void);
	void __fastcall UpdateToolTips(const System::Types::TPoint Pt);
	__property System::Types::TRect HotTrackStyleBounds = {read=GetHotTrackStyleBounds};
	__property int HotTrackStyleIndex = {read=FHotTrackStyleIndex, write=FHotTrackStyleIndex, nodefault};
	__property System::UnicodeString HotTrackStyleName = {read=GetHotTrackStyleName};
	__property System::Types::TRect ToolTipsBounds = {read=GetToolTipsBounds};
	__property TdxStylesListBoxToolTipsWindow* ToolTipsWindow = {read=FToolTipsWindow};
	
public:
	__fastcall virtual TdxStylesListBox(System::Classes::TComponent* AOwner);
	int __fastcall IndexOfStyle(Cxstyles::TcxStyle* AStyle);
	void __fastcall HideToolTips(void);
	__property TdxCustomReportLinkStyles* ReportLinkStyles = {read=FReportLinkStyles, write=SetReportLinkStyles};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* StyleLookAndFeelPainter = {read=GetStyleLookAndFeelPainter};
	__property Cxstyles::TcxStyle* Styles[int Index] = {read=GetStyle};
	__property Cxstyles::TcxStyle* SelectedStyle = {read=GetSelectedStyle};
	
__published:
	__property bool ToolTips = {read=FToolTips, write=SetToolTips, default=1};
public:
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TdxStylesListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxStylesListBox(HWND ParentWindow) : Cxlistbox::TcxListBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxPSPreviewCarLogoCount = System::Int8(0x5);
static const System::Int8 dxPSPreviewCarLogoWidth = System::Int8(0x3c);
static const System::Int8 dxPSPreviewCarLogoHeight = System::Int8(0x1e);
extern PACKAGE System::StaticArray<Dxpscore::TdxCellSides, 4> CellSidesMap;
extern PACKAGE System::StaticArray<Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle, 2> EdgeStyleMap;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignX, 3> EditTextAlignXMap;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignY, 3> EditTextAlignYMap;
extern PACKAGE System::StaticArray<System::StaticArray<Dxpscore::TdxImageLayout, 3>, 3> HeaderImageLayoutMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxImageLayout, 2> ImageLayoutMap;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignX, 3> TextAlignXMap;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignY, 3> TextAlignYMap;
extern PACKAGE System::UnicodeString __fastcall cxButtonGroupItem_GetCaption(Cxgroupbox::TcxButtonGroupItem* AnItem);
extern PACKAGE Cxblobedit::TcxBlobEditKind __fastcall cxBlobEditProperties_GetEditKind(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Cxblobedit::TcxBlobPaintStyle __fastcall cxBlobEditProperties_GetPaintStyle(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE int __fastcall cxButtonGroupProperties_GetColumnCount(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Cxgroupbox::TcxButtonGroupItems* __fastcall cxButtonGroupProperties_GetItems(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::Classes::TAlignment __fastcall cxCheckBoxProperties_GetAlignment(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCheckBoxProperties_GetGlyph(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE int __fastcall cxCheckBoxProperties_GetGlyphCount(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall cxCheckBoxProperties_GetIsMultilined(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Cxcheckbox::TcxCheckBoxNullValueShowingStyle __fastcall cxCheckBoxProperties_GetNullStyle(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::UnicodeString __fastcall cxCurrencyProperties_GetNullString(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Cxedit::TcxEditAlignment* __fastcall cxEditProperties_GetAlignment(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::Uitypes::TColor __fastcall cxHyperLinkEditProperties_GetLinkColor(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::Classes::TAlignment __fastcall cxMemoProperties_GetAlignment(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall cxMemoProperties_GetWordWrap(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::UnicodeString __fastcall cxImageComboBoxProperties_GetDefaultDescription(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE int __fastcall cxImageComboBoxProperties_GetDefaultImageIndex(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Cximagecombobox::TcxImageComboBoxItem* __fastcall cxImageComboBoxProperties_FindItemByValue(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
extern PACKAGE Cximagecombobox::TcxImageAlign __fastcall cxImageComboBoxProperties_GetImageAlignment(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Vcl::Imglist::TCustomImageList* __fastcall cxImageComboBoxProperties_GetImages(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall cxImageComboBoxProperties_GetIsMultilined(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Cximagecombobox::TcxImageComboBoxItems* __fastcall cxImageComboBoxProperties_GetItems(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall cxImageComboBoxProperties_GetShowDescription(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::UnicodeString __fastcall cxImageProperties_GetCaption(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall cxImageProperties_GetCenter(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall cxImageProperties_GetProportional(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall cxImageProperties_GetStretch(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Vcl::Graphics::TGraphicClass __fastcall cxImageProperties_GetGraphicClass(Cxedit::TcxCustomEditProperties* AProperties, int ARecordIndex, System::TObject* AOwner = (System::TObject*)(0x0));
extern PACKAGE System::UnicodeString __fastcall cxRadioGroupProperties_GetDisplayText(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
extern PACKAGE Cxgraphics::TcxGridLines __fastcall dxPSMakecxGridLines(bool AHorizontal, bool AVertical);
extern PACKAGE void __fastcall dxPSDrawStyleBar(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, const TdxStyleBarViewInfo &AViewInfo);
extern PACKAGE int __fastcall dxPSMeasureTextWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont);
extern PACKAGE Vcl::Graphics::TPicture* __fastcall dxPSPreviewCarLogos(int Index);
extern PACKAGE System::AnsiString __fastcall dxPSPreviewCarLogosAsString(int Index);
extern PACKAGE void __fastcall dxPSResetStyles(Cxstyles::TcxStyles* AStyles);
extern PACKAGE Vcl::Extdlgs::TOpenPictureDialog* __fastcall dxPSPictureDialog(void);
extern PACKAGE TdxPSDataMaps* __fastcall dxPSDataMaps(void);
}	/* namespace Dxpscxcommon */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXCOMMON)
using namespace Dxpscxcommon;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxcommonHPP
