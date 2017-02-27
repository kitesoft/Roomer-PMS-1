// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPrnPg.pas' rev: 24.00 (Win32)

#ifndef DxprnpgHPP
#define DxprnpgHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Winapi.CommDlg.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSUtl.hpp>	// Pascal unit
#include <dxWrap.hpp>	// Pascal unit
#include <dxPrnDev.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxprnpg
{
//-- type declarations -------------------------------------------------------
enum TdxHFPageType : unsigned char { ptHeader, ptFooter };

enum TdxMeasurementUnits : unsigned char { muDefault, muInches, muMillimeters };

enum TdxPageTitlePart : unsigned char { tpLeft, tpCenter, tpRight };

typedef System::Set<TdxPageTitlePart, TdxPageTitlePart::tpLeft, TdxPageTitlePart::tpRight>  TdxPageTitleParts;

enum TdxScaleMode : unsigned char { smAdjust, smFit };

enum TdxMarginType : unsigned char { mtLeft, mtTop, mtRight, mtBottom, mtHeader, mtFooter };

typedef System::Set<TdxMarginType, TdxMarginType::mtLeft, TdxMarginType::mtFooter>  TdxMarginTypes;

enum TdxPrinterPageUpdateCode : unsigned char { ucMarginLeft, ucMarginTop, ucMarginRight, ucMarginBottom, ucMarginHeader, ucMarginFooter, ucScale };

typedef System::Set<TdxPrinterPageUpdateCode, TdxPrinterPageUpdateCode::ucMarginLeft, TdxPrinterPageUpdateCode::ucScale>  TdxPrinterPageUpdateCodes;

typedef System::TMetaClass* TdxPrinterPageObjectClass;

class DELPHICLASS TdxPrinterPageObject;
class DELPHICLASS TdxPrinterPage;
class PASCALIMPLEMENTATION TdxPrinterPageObject : public Dxbase::TdxBaseObject
{
	typedef Dxbase::TdxBaseObject inherited;
	
private:
	Dxbkgnd::TdxBackground* FBackground;
	TdxPrinterPage* FPage;
	void __fastcall SetBackground(Dxbkgnd::TdxBackground* Value);
	
protected:
	virtual void __fastcall DoAssign(Dxbase::TdxBaseObject* Source);
	DYNAMIC void __fastcall LockUpdate(Dxbase::TdxLockState ALockState);
	DYNAMIC void __fastcall Changed(void);
	virtual Dxbkgnd::TdxBackground* __fastcall CreateBackground(void);
	virtual Dxbkgnd::TdxBackgroundClass __fastcall GetBackgroundClass(void);
	virtual void __fastcall InitializeBackground(Dxbkgnd::TdxBackground* ABackground);
	__property Dxbkgnd::TdxBackground* Background = {read=FBackground, write=SetBackground};
	__property TdxPrinterPage* Page = {read=FPage};
	
public:
	__fastcall virtual TdxPrinterPageObject(void);
	__fastcall virtual ~TdxPrinterPageObject(void);
};


typedef System::TMetaClass* TCustomdxPageObjectClass;

class DELPHICLASS TCustomdxPageObject;
class PASCALIMPLEMENTATION TCustomdxPageObject : public TdxPrinterPageObject
{
	typedef TdxPrinterPageObject inherited;
	
public:
	System::Classes::TStrings* operator[](TdxPageTitlePart Index) { return Titles[Index]; }
	
private:
	Vcl::Graphics::TFont* FDefaultFont;
	Vcl::Graphics::TFont* FFont;
	System::StaticArray<Cxdrawtextutils::TcxTextAlignY, 3> FTextAlignY;
	System::StaticArray<System::Classes::TStrings*, 3> FTitles;
	Cxdrawtextutils::TcxTextAlignY __fastcall GetPartialTextAlignY(int Index);
	System::Classes::TStrings* __fastcall GetPartialTitle(int Index);
	Cxdrawtextutils::TcxTextAlignY __fastcall GetTextAlignY(TdxPageTitlePart Index);
	System::Classes::TStrings* __fastcall GetTitle(TdxPageTitlePart Index);
	bool __fastcall IsFontStored(void);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetPartialTextAlignY(int Index, Cxdrawtextutils::TcxTextAlignY Value);
	void __fastcall SetPartialTitle(int Index, System::Classes::TStrings* Value);
	void __fastcall SetTextAlignY(TdxPageTitlePart Index, Cxdrawtextutils::TcxTextAlignY Value);
	void __fastcall SetTitle(TdxPageTitlePart Index, System::Classes::TStrings* Value);
	void __fastcall FontChanged(System::TObject* Sender);
	void __fastcall TitleChanged(System::TObject* Sender);
	void __fastcall FreeAndNilTitles(void);
	
protected:
	virtual void __fastcall DoAssign(Dxbase::TdxBaseObject* Source);
	virtual void __fastcall InitializeDefaultFont(Vcl::Graphics::TFont* AFont);
	virtual bool __fastcall IsTitleStored(int Index);
	
public:
	__fastcall virtual TCustomdxPageObject(void);
	__fastcall virtual ~TCustomdxPageObject(void);
	virtual Vcl::Graphics::TFont* __fastcall DefaultFont(void);
	__property Cxdrawtextutils::TcxTextAlignY CenterTextAlignY = {read=GetPartialTextAlignY, write=SetPartialTextAlignY, index=1, default=1};
	__property System::Classes::TStrings* CenterTitle = {read=GetPartialTitle, write=SetPartialTitle, stored=IsTitleStored, index=1};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property Cxdrawtextutils::TcxTextAlignY LeftTextAlignY = {read=GetPartialTextAlignY, write=SetPartialTextAlignY, index=0, default=1};
	__property System::Classes::TStrings* LeftTitle = {read=GetPartialTitle, write=SetPartialTitle, stored=IsTitleStored, index=0};
	__property Page;
	__property Cxdrawtextutils::TcxTextAlignY RightTextAlignY = {read=GetPartialTextAlignY, write=SetPartialTextAlignY, index=2, default=1};
	__property System::Classes::TStrings* RightTitle = {read=GetPartialTitle, write=SetPartialTitle, stored=IsTitleStored, index=2};
	__property Cxdrawtextutils::TcxTextAlignY TextAlignY[TdxPageTitlePart Index] = {read=GetTextAlignY, write=SetTextAlignY};
	__property System::Classes::TStrings* Titles[TdxPageTitlePart Index] = {read=GetTitle, write=SetTitle/*, default*/};
	
__published:
	__property Background;
};


typedef System::TMetaClass* TdxPageFooterClass;

class DELPHICLASS TdxPageFooter;
class PASCALIMPLEMENTATION TdxPageFooter : public TCustomdxPageObject
{
	typedef TCustomdxPageObject inherited;
	
protected:
	virtual bool __fastcall IsTitleStored(int Index);
	
__published:
	__property CenterTextAlignY = {index=1, default=1};
	__property CenterTitle;
	__property Font;
	__property LeftTextAlignY = {index=0, default=1};
	__property LeftTitle;
	__property RightTextAlignY = {index=2, default=1};
	__property RightTitle;
public:
	/* TCustomdxPageObject.Create */ inline __fastcall virtual TdxPageFooter(void) : TCustomdxPageObject() { }
	/* TCustomdxPageObject.Destroy */ inline __fastcall virtual ~TdxPageFooter(void) { }
	
};


typedef System::TMetaClass* TdxPageHeaderClass;

class DELPHICLASS TdxPageHeader;
class PASCALIMPLEMENTATION TdxPageHeader : public TCustomdxPageObject
{
	typedef TCustomdxPageObject inherited;
	
protected:
	virtual bool __fastcall IsTitleStored(int Index);
	
__published:
	__property CenterTextAlignY = {index=1, default=1};
	__property CenterTitle;
	__property Font;
	__property LeftTextAlignY = {index=0, default=1};
	__property LeftTitle;
	__property RightTextAlignY = {index=2, default=1};
	__property RightTitle;
public:
	/* TCustomdxPageObject.Create */ inline __fastcall virtual TdxPageHeader(void) : TCustomdxPageObject() { }
	/* TCustomdxPageObject.Destroy */ inline __fastcall virtual ~TdxPageHeader(void) { }
	
};


typedef System::TMetaClass* TdxPrinterPageClass;

class PASCALIMPLEMENTATION TdxPrinterPage : public TdxPrinterPageObject
{
	typedef TdxPrinterPageObject inherited;
	
private:
	bool FAssigning;
	bool FAutoSwapMargins;
	bool FCenterOnPageH;
	bool FCenterOnPageV;
	int FDMPaper;
	bool FGrayShading;
	Dxwrap::TdxRectWrapper* FHFG;
	Cxgraphics::TcxImageCollection* FImageCollection;
	TdxMeasurementUnits FLastMU;
	Dxwrap::TdxRectWrapper* FMargins;
	TdxMeasurementUnits FMeasurementUnits;
	Dxwrap::TdxRectWrapper* FMinMargins;
	System::Classes::TNotifyEvent FOnChange;
	System::Classes::TNotifyEvent FOnMarginChange;
	Dxprndev::TdxPrinterOrientation FOrientation;
	TdxPageFooter* FPageFooter;
	TdxPageHeader* FPageHeader;
	Dxpsglbl::TdxPageOrder FPageOrder;
	Dxwrap::TdxPointWrapper* FPageSize;
	bool FPageSizeLocked;
	int FPaperSource;
	bool FReverseTitlesOnEvenPages;
	int FScaleFactor;
	TdxScaleMode FScaleMode;
	bool __fastcall GetCanSwapMargins(void);
	int __fastcall GetHFG(int index);
	TdxMeasurementUnits __fastcall GetRealMeasurementUnits(void);
	System::Types::TPoint __fastcall GetRealPageSize(void);
	int __fastcall GetRestPageSizeX(void);
	int __fastcall GetRestPageSizeY(void);
	bool __fastcall IsMinMarginsStored(void);
	bool __fastcall IsPageSizeStored(void);
	void __fastcall SetDMPaper(int Value);
	void __fastcall SetHFG(int index, int Value);
	void __fastcall SetImageCollection(Cxgraphics::TcxImageCollection* AValue);
	void __fastcall SetMargins(Dxwrap::TdxRectWrapper* Value);
	void __fastcall SetMeasurementUnits(TdxMeasurementUnits Value);
	void __fastcall SetMinMargins(Dxwrap::TdxRectWrapper* Value);
	void __fastcall SetOrientation(Dxprndev::TdxPrinterOrientation Value);
	void __fastcall SetPageFooter(TdxPageFooter* Value);
	void __fastcall SetPageHeader(TdxPageHeader* Value);
	void __fastcall SetPageSize(Dxwrap::TdxPointWrapper* Value);
	void __fastcall SetPaperSource(int Value);
	void __fastcall SetRealPageSize(const System::Types::TPoint &Value);
	void __fastcall SetScaleFactor(int Value);
	void __fastcall HFGChanged(System::TObject* Sender, Dxwrap::TdxRectSides ASides);
	void __fastcall HFGChanging(System::TObject* Sender, Dxwrap::TdxRectSides ASides, int *Values, const int Values_Size);
	void __fastcall LockUpdated(Dxbase::TdxBaseObject* Sender, Dxbase::TdxLockState ALockState);
	void __fastcall MarginsChanged(System::TObject* Sender, Dxwrap::TdxRectSides ASides);
	void __fastcall MarginsChanging(System::TObject* Sender, Dxwrap::TdxRectSides ASides, int *Values, const int Values_Size);
	void __fastcall MinMarginsChanged(System::TObject* Sender, Dxwrap::TdxRectSides ASides);
	void __fastcall MinMarginsChanging(System::TObject* Sender, Dxwrap::TdxRectSides ASides, int *Values, const int Values_Size);
	void __fastcall PageSizeChanged(System::TObject* Sender, Dxwrap::TdxPointCoords ACoords);
	void __fastcall PageSizeChanging(System::TObject* Sender, Dxwrap::TdxPointCoords ACoords, int *Values, const int Values_Size);
	void __fastcall ReadInt(System::Classes::TReader* Reader);
	void __fastcall ReadLastMU(System::Classes::TReader* Reader);
	void __fastcall ReadMU(System::Classes::TReader* Reader);
	void __fastcall WriteInt(System::Classes::TWriter* Writer);
	void __fastcall WriteLastMU(System::Classes::TWriter* Writer);
	void __fastcall WriteMU(System::Classes::TWriter* Writer);
	void __fastcall DoSwapMargins(void);
	void __fastcall FindDMPaperByPageSize(void);
	void __fastcall FixMargins(void);
	void __fastcall FixMinMargins(void);
	bool __fastcall IsLoading(void);
	void __fastcall SetPaperSizeByDMPaper(void);
	
protected:
	__fastcall TdxPrinterPage(int Dummy);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall Changed(void);
	virtual void __fastcall DoAssign(Dxbase::TdxBaseObject* Source);
	virtual bool __fastcall GetSupportsScaling(void);
	bool __fastcall IsDefaultDMPaperSelected(void);
	virtual bool __fastcall IsPageFooterTitleStored(int Index);
	virtual bool __fastcall IsPageHeaderTitleStored(int Index);
	DYNAMIC void __fastcall MarginChanged(void);
	virtual void __fastcall PageParamsChanged(TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual TdxPageFooter* __fastcall CreatePageFooter(void);
	virtual TdxPageFooterClass __fastcall GetPageFooterClass(void);
	virtual void __fastcall InitializePageFooter(TdxPageFooter* APageFooter);
	virtual TdxPageHeader* __fastcall CreatePageHeader(void);
	virtual TdxPageHeaderClass __fastcall GetPageHeaderClass(void);
	virtual void __fastcall InitializePageHeader(TdxPageHeader* APageHeader);
	void __fastcall DoUpdateMeasurementUnits(void);
	void __fastcall ReadPrinterInfos(void);
	void __fastcall SynchronizeMeasurementUnits(void);
	void __fastcall ImageCollectionChanged(void);
	void __fastcall ImageCollectionDestroyed(void);
	__property bool CanSwapMargins = {read=GetCanSwapMargins, nodefault};
	__property int RestPageSizeX = {read=GetRestPageSizeX, nodefault};
	__property int RestPageSizeY = {read=GetRestPageSizeY, nodefault};
	__property bool SupportsScaling = {read=GetSupportsScaling, nodefault};
	
public:
	__fastcall virtual TdxPrinterPage(void);
	__fastcall virtual ~TdxPrinterPage(void);
	DYNAMIC System::UnicodeString __fastcall GetNamePath(void);
	void __fastcall ApplyToPrintDevice(void);
	void __fastcall InitFromPrintDevice(void);
	void __fastcall FixMarginsOutside(void);
	TdxMeasurementUnits __fastcall GetInnerMeasurementUnits(void);
	void __fastcall GetRealMinMargins(int &AMinLeft, int &AMinRight, int &AMinTop, int &AMinBottom);
	virtual bool __fastcall IsEqual(Dxbase::TdxBaseObject* ABaseObject);
	HIDESBASE void __fastcall RestoreDefaults(void);
	void __fastcall MapRect2LoMetric(System::Types::TRect &R);
	int __fastcall FooterLoMetric(void);
	System::Types::TRect __fastcall FooterRect(void);
	System::Types::TRect __fastcall FooterRectLoMetric(void);
	int __fastcall HeaderLoMetric(void);
	System::Types::TRect __fastcall HeaderRect(void);
	System::Types::TRect __fastcall HeaderRectLoMetric(void);
	System::Types::TRect __fastcall MarginsLoMetric(void);
	System::Types::TRect __fastcall MinMarginsLoMetric(void);
	int __fastcall MinPrintableArea(void);
	int __fastcall MinPrintableAreaLoMetric(void);
	System::Types::TPoint __fastcall PageSizeLoMetric(void);
	System::Types::TPoint __fastcall PageSizePixels(void);
	System::Types::TRect __fastcall PaintRectLoMetric(void);
	System::Types::TRect __fastcall PaintRectPixels(void);
	System::Types::TPoint __fastcall RealPageSizeLoMetric(void);
	System::Types::TPoint __fastcall RealPageSizePixels(void);
	bool __fastcall ValidateMargins(void);
	__property TdxMeasurementUnits RealMeasurementUnits = {read=GetRealMeasurementUnits, nodefault};
	__property System::Types::TPoint RealPageSize = {read=GetRealPageSize, write=SetRealPageSize};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property System::Classes::TNotifyEvent OnMarginChange = {read=FOnMarginChange, write=FOnMarginChange};
	
__published:
	__property bool AutoSwapMargins = {read=FAutoSwapMargins, write=FAutoSwapMargins, default=1};
	__property Background;
	__property bool CenterOnPageH = {read=FCenterOnPageH, write=FCenterOnPageH, default=0};
	__property bool CenterOnPageV = {read=FCenterOnPageV, write=FCenterOnPageV, default=0};
	__property int DMPaper = {read=FDMPaper, write=SetDMPaper, nodefault};
	__property int Footer = {read=GetHFG, write=SetHFG, index=3, default=0};
	__property bool GrayShading = {read=FGrayShading, write=FGrayShading, default=0};
	__property int Header = {read=GetHFG, write=SetHFG, index=1, default=0};
	__property Cxgraphics::TcxImageCollection* ImageCollection = {read=FImageCollection, write=SetImageCollection};
	__property Dxwrap::TdxRectWrapper* Margins = {read=FMargins, write=SetMargins};
	__property TdxMeasurementUnits MeasurementUnits = {read=FMeasurementUnits, write=SetMeasurementUnits, stored=false, default=0};
	__property Dxwrap::TdxRectWrapper* MinMargins = {read=FMinMargins, write=SetMinMargins, stored=IsMinMarginsStored};
	__property Dxprndev::TdxPrinterOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	__property TdxPageFooter* PageFooter = {read=FPageFooter, write=SetPageFooter};
	__property TdxPageHeader* PageHeader = {read=FPageHeader, write=SetPageHeader};
	__property Dxpsglbl::TdxPageOrder PageOrder = {read=FPageOrder, write=FPageOrder, default=0};
	__property Dxwrap::TdxPointWrapper* PageSize = {read=FPageSize, write=SetPageSize, stored=IsPageSizeStored};
	__property int PaperSource = {read=FPaperSource, write=SetPaperSource, default=7};
	__property bool ReverseTitlesOnEvenPages = {read=FReverseTitlesOnEvenPages, write=FReverseTitlesOnEvenPages, default=0};
	__property int ScaleFactor = {read=FScaleFactor, write=SetScaleFactor, default=100};
	__property TdxScaleMode ScaleMode = {read=FScaleMode, write=FScaleMode, default=0};
private:
	void *__IcxImageCollectionListener;	/* Cxgraphics::IcxImageCollectionListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FDFF372B-F49E-40C9-9E03-E0D6B110774A}
	operator Cxgraphics::_di_IcxImageCollectionListener()
	{
		Cxgraphics::_di_IcxImageCollectionListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgraphics::IcxImageCollectionListener*(void) { return (Cxgraphics::IcxImageCollectionListener*)&__IcxImageCollectionListener; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxMarginTypes mtAll;
#define ucAll (System::Set<TdxPrinterPageUpdateCode, TdxPrinterPageUpdateCode::ucMarginLeft, TdxPrinterPageUpdateCode::ucScale> () << TdxPrinterPageUpdateCode::ucMarginLeft << TdxPrinterPageUpdateCode::ucMarginTop << TdxPrinterPageUpdateCode::ucMarginRight << TdxPrinterPageUpdateCode::ucMarginBottom << TdxPrinterPageUpdateCode::ucMarginHeader << TdxPrinterPageUpdateCode::ucMarginFooter << TdxPrinterPageUpdateCode::ucScale )
#define ucMargins (System::Set<TdxPrinterPageUpdateCode, TdxPrinterPageUpdateCode::ucMarginLeft, TdxPrinterPageUpdateCode::ucScale> () << TdxPrinterPageUpdateCode::ucMarginLeft << TdxPrinterPageUpdateCode::ucMarginTop << TdxPrinterPageUpdateCode::ucMarginRight << TdxPrinterPageUpdateCode::ucMarginBottom << TdxPrinterPageUpdateCode::ucMarginHeader << TdxPrinterPageUpdateCode::ucMarginFooter )
#define uaMarginsVert (System::Set<TdxPrinterPageUpdateCode, TdxPrinterPageUpdateCode::ucMarginLeft, TdxPrinterPageUpdateCode::ucScale> () << TdxPrinterPageUpdateCode::ucMarginLeft << TdxPrinterPageUpdateCode::ucMarginRight )
#define uaMarginsHorz (System::Set<TdxPrinterPageUpdateCode, TdxPrinterPageUpdateCode::ucMarginLeft, TdxPrinterPageUpdateCode::ucScale> () << TdxPrinterPageUpdateCode::ucMarginTop << TdxPrinterPageUpdateCode::ucMarginBottom )
static const System::Int8 dxDefaultDMPaper = System::Int8(0x1);
static const System::Int8 dxDefaultPaperSource = System::Int8(0x7);
extern PACKAGE System::StaticArray<TdxPageTitlePart, 3> dxPSPageTitlePartMap;
static const int dxPSDefaltHFFontColor = int(0);
#define dxPSDefaltHFFontName L"Tahoma"
static const System::Int8 dxPSDefaltHFFontSize = System::Int8(0x8);
#define dxPSDefaltHFFontStyle EMPTYSET
#define dxDefaultHFFont L"Tahoma"
extern PACKAGE TdxPrinterPage* __fastcall DefaultPrinterPage(void);
extern PACKAGE void __fastcall RereadDefaultPrinterPage(void);
extern PACKAGE TdxMeasurementUnits __fastcall GetDefaultMeasurementUnits(void);
}	/* namespace Dxprnpg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPRNPG)
using namespace Dxprnpg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxprnpgHPP
