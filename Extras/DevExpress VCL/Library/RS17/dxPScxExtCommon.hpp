// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxExtCommon.pas' rev: 24.00 (Win32)

#ifndef DxpscxextcommonHPP
#define DxpscxextcommonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxCheckGroup.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxextcommon
{
//-- type declarations -------------------------------------------------------
enum TdxReportCellColorBoxAlignment : unsigned char { ccbaLeft, ccbaRight };

class DELPHICLASS TdxReportCellColorBox;
class PASCALIMPLEMENTATION TdxReportCellColorBox : public Dxpscore::TdxReportCellImageContainer
{
	typedef Dxpscore::TdxReportCellImageContainer inherited;
	
private:
	System::Uitypes::TColor FColorBoxFrameColor;
	int FColorBoxWidth;
	System::Uitypes::TColor FColorValue;
	TdxReportCellColorBoxAlignment __fastcall GetColorBoxAlignment(void);
	bool __fastcall GetShowDescription(void);
	void __fastcall SetColorBoxAlignment(TdxReportCellColorBoxAlignment Value);
	void __fastcall SetShowDescription(bool Value);
	
protected:
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual System::Types::TRect __fastcall GetImageAreaBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetImageBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall GetImageSizes(int &AImageWidth, int &AImageHeight);
	virtual System::Types::TRect __fastcall GetTextBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual bool __fastcall HasImage(void);
	virtual bool __fastcall IsImageBackgroundDrawn(void);
	virtual bool __fastcall IsImageDrawn(void);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	virtual void __fastcall DrawColorBox(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetColorBoxFrameBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetColorBoxIntreriorBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	
public:
	__fastcall virtual TdxReportCellColorBox(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual int __fastcall ActualColorBoxWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawImage(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property TdxReportCellColorBoxAlignment ColorBoxAlignment = {read=GetColorBoxAlignment, write=SetColorBoxAlignment, nodefault};
	__property System::Uitypes::TColor ColorBoxFrameColor = {read=FColorBoxFrameColor, write=FColorBoxFrameColor, nodefault};
	__property int ColorBoxWidth = {read=FColorBoxWidth, write=FColorBoxWidth, nodefault};
	__property System::Uitypes::TColor ColorValue = {read=FColorValue, write=FColorValue, nodefault};
	__property bool ShowDescription = {read=GetShowDescription, write=SetShowDescription, nodefault};
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportCellColorBox(void) { }
	
};


class DELPHICLASS TdxReportCellProgressBar;
class PASCALIMPLEMENTATION TdxReportCellProgressBar : public Dxpscore::TdxReportCellText
{
	typedef Dxpscore::TdxReportCellText inherited;
	
private:
	double FMaxValue;
	double FMinValue;
	System::Uitypes::TColor FProgressColor;
	System::UnicodeString FText;
	double FValue;
	Dxcore::TdxOrientation __fastcall GetOrientation(void);
	double __fastcall GetProgress(void);
	bool __fastcall GetShowPercentSymbol(void);
	bool __fastcall GetShowText(void);
	void __fastcall SetOrientation(Dxcore::TdxOrientation Value);
	void __fastcall SetMaxValue(double Value);
	void __fastcall SetMinValue(double Value);
	void __fastcall SetShowPercentSymbol(bool Value);
	void __fastcall SetShowText(bool Value);
	void __fastcall SetValue(double Value);
	
protected:
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall SetText(const System::UnicodeString Value);
	virtual System::Types::TRect __fastcall GetProgressBarProgressBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetProgressBarProgressRestBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual bool __fastcall IsProgressBarDrawn(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	__property double Progress = {read=GetProgress};
	
public:
	__fastcall virtual TdxReportCellProgressBar(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	virtual void __fastcall DrawProgressBar(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawText(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property double MaxValue = {read=FMaxValue, write=SetMaxValue};
	__property double MinValue = {read=FMinValue, write=SetMinValue};
	__property Dxcore::TdxOrientation Orientation = {read=GetOrientation, write=SetOrientation, nodefault};
	__property System::Uitypes::TColor ProgressColor = {read=FProgressColor, write=FProgressColor, nodefault};
	__property bool ShowPercentSymbol = {read=GetShowPercentSymbol, write=SetShowPercentSymbol, nodefault};
	__property bool ShowText = {read=GetShowText, write=SetShowText, nodefault};
	__property double Value = {read=FValue, write=SetValue};
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportCellProgressBar(void) { }
	
};


class DELPHICLASS TdxReportCellRichEditGraphic;
class PASCALIMPLEMENTATION TdxReportCellRichEditGraphic : public Dxpscore::TdxReportCellGraphic
{
	typedef Dxpscore::TdxReportCellGraphic inherited;
	
protected:
	virtual bool __fastcall IsBackgroundBitmapDrawn(void);
public:
	/* TdxReportCellGraphic.Create */ inline __fastcall virtual TdxReportCellRichEditGraphic(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCellGraphic(AParent) { }
	
public:
	/* TCustomdxReportCellImageContainer.Destroy */ inline __fastcall virtual ~TdxReportCellRichEditGraphic(void) { }
	
};


class DELPHICLASS TdxPSColorComboBoxDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSColorComboBoxDataMap : public Dxpscxcommon::TdxPSTextDataMap
{
	typedef Dxpscxcommon::TdxPSTextDataMap inherited;
	
protected:
	__classmethod virtual bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual System::UnicodeString __fastcall GetText(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Dxpscxcommon::TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0xffffffff, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSColorComboBoxDataMap(void) : Dxpscxcommon::TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSColorComboBoxDataMap(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSFontNameComboBoxDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFontNameComboBoxDataMap : public Dxpscxcommon::TdxPSTextDataMap
{
	typedef Dxpscxcommon::TdxPSTextDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall GetImageLists(Cxedit::TcxCustomEditProperties* AProperties, Dxpscore::TdxPSGetImageListProc AProc);
	__classmethod virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Dxpscxcommon::TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0xffffffff, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSFontNameComboBoxDataMap(void) : Dxpscxcommon::TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSFontNameComboBoxDataMap(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSShellComboBoxDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSShellComboBoxDataMap : public Dxpscxcommon::TdxPSTextDataMap
{
	typedef Dxpscxcommon::TdxPSTextDataMap inherited;
	
protected:
	__classmethod int __fastcall GetImageIndex(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual void __fastcall GetImageLists(Cxedit::TcxCustomEditProperties* AProperties, Dxpscore::TdxPSGetImageListProc AProc);
	__classmethod Vcl::Imglist::TCustomImageList* __fastcall GetImages(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod bool __fastcall HasImages(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Dxpscxcommon::TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0xffffffff, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
	__classmethod virtual int __fastcall MeasureWidth(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Vcl::Graphics::TFont* AFont, int ARecordIndex = 0x0);
public:
	/* TObject.Create */ inline __fastcall TdxPSShellComboBoxDataMap(void) : Dxpscxcommon::TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSShellComboBoxDataMap(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSLabelDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSLabelDataMap : public Dxpscxcommon::TdxPSTextDataMap
{
	typedef Dxpscxcommon::TdxPSTextDataMap inherited;
	
protected:
	__classmethod virtual bool __fastcall DoesItemParticipateInAutoWidthCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Dxpscxcommon::TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0xffffffff, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSLabelDataMap(void) : Dxpscxcommon::TdxPSTextDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLabelDataMap(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSProgressBarDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSProgressBarDataMap : public Dxpscxcommon::TdxPSCustomDataMap
{
	typedef Dxpscxcommon::TdxPSCustomDataMap inherited;
	
protected:
	__classmethod int __fastcall GetValue(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual bool __fastcall HasText(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Dxpscxcommon::TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0xffffffff, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSProgressBarDataMap(void) : Dxpscxcommon::TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSProgressBarDataMap(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTrackBarDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTrackBarDataMap : public Dxpscxcommon::TdxPSCustomDataMap
{
	typedef Dxpscxcommon::TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Dxpscxcommon::TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0xffffffff, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSTrackBarDataMap(void) : Dxpscxcommon::TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTrackBarDataMap(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCheckButtonGroupDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCheckButtonGroupDataMap : public Dxpscxcommon::TdxPSCustomButtonGroupDataMap
{
	typedef Dxpscxcommon::TdxPSCustomButtonGroupDataMap inherited;
	
protected:
	__classmethod virtual Dxpscore::TdxCustomReportButtonGroupClass __fastcall ButtonGroupClass(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeGroupButton(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, Dxpscore::TdxCustomReportCellCheck* AButton, int AnIndex);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Dxpscxcommon::TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0xffffffff, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSCheckButtonGroupDataMap(void) : Dxpscxcommon::TdxPSCustomButtonGroupDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCheckButtonGroupDataMap(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSRichEditDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSRichEditDataMap : public Dxpscxcommon::TdxPSDelegateDataMap
{
	typedef Dxpscxcommon::TdxPSDelegateDataMap inherited;
	
protected:
	__classmethod virtual Dxpscxcommon::TdxPSDataMapClass __fastcall DataMapClass(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall PropertiesClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSRichEditDataMap(void) : Dxpscxcommon::TdxPSDelegateDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSRichEditDataMap(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSRichTextDataMap;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSRichTextDataMap : public Dxpscxcommon::TdxPSCustomDataMap
{
	typedef Dxpscxcommon::TdxPSCustomDataMap inherited;
	
protected:
	__classmethod virtual bool __fastcall DoesItemParticipateInBestFitCalculation(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, const Dxpscxcommon::_di_IdxPSCellParams ACellParams, Dxpscxcommon::TdxReportItemViewParams &AViewParams, bool AnIsPreview = false, int ARecordIndex = 0xffffffff, System::TObject* AOwner = (System::TObject*)(0x0));
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall ItemClass(Cxedit::TcxCustomEditProperties* AProperties, bool AnIsPreview = false);
public:
	/* TObject.Create */ inline __fastcall TdxPSRichTextDataMap(void) : Dxpscxcommon::TdxPSCustomDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSRichTextDataMap(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxDefaultColorBoxWidth = System::Int8(0x1e);
extern PACKAGE System::Uitypes::TColor dxDefaultColorBoxColorValue;
extern PACKAGE System::StaticArray<TdxReportCellColorBoxAlignment, 2> ColorBoxAlignmentMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxCellCheckPos, 2> LeftRightMap;
extern PACKAGE System::Uitypes::TColor __fastcall ColorComboBoxProperties_GetColor(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
extern PACKAGE TdxReportCellColorBoxAlignment __fastcall ColorComboBoxProperties_GetColorBoxAlignment(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::Uitypes::TColor __fastcall ColorComboBoxProperties_GetColorBoxFrameColor(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE int __fastcall ColorComboBoxProperties_GetColorBoxWidth(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall ColorComboBoxProperties_GetShowDescriptions(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::UnicodeString __fastcall ColorComboBoxProperties_GetText(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
extern PACKAGE bool __fastcall FontNameComboBox_GetShowTypeIcon(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE int __fastcall FontNameComboBox_GetTypeIconImageIndex(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue);
extern PACKAGE double __fastcall ProgressBarProperties_GetMaxValue(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE double __fastcall ProgressBarProperties_GetMinValue(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Dxcore::TdxOrientation __fastcall ProgressBarProperties_GetOrientation(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::Uitypes::TColor __fastcall ProgressBarProperties_GetProgressBarColor(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall ProgressBarProperties_GetShowPercentSymbol(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall ProgressBarProperties_GetShowText(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE System::UnicodeString __fastcall ProgressBarProperties_GetText(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall CheckGroupProperties_GetGlyph(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE int __fastcall CheckGroupProperties_GetGlyphCount(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Dxpscore::TdxCellCheckPos __fastcall CheckGroupProperties_GetCheckPos(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE bool __fastcall CheckGroupProperties_GetCheckStates(Cxedit::TcxCustomEditProperties* AProperties, const System::Variant &AValue, /* out */ Cxcheckbox::TcxCheckStates &ACheckStates);
extern PACKAGE bool __fastcall CheckGroupProperties_GetIsItemEnabled(Cxedit::TcxCustomEditProperties* AProperties, int AnIndex);
extern PACKAGE bool __fastcall RichEditProperties_GetIsMemoMode(Cxedit::TcxCustomEditProperties* AProperties);
extern PACKAGE Vcl::Imglist::TCustomImageList* __fastcall FontImages(void);
}	/* namespace Dxpscxextcommon */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXEXTCOMMON)
using namespace Dxpscxextcommon;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxextcommonHPP
