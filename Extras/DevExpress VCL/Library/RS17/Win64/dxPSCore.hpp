// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSCore.pas' rev: 24.00 (Win64)

#ifndef DxpscoreHPP
#define DxpscoreHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxPSEngn.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit
#include <dxPrnDlg.hpp>	// Pascal unit
#include <dxWrap.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <dxPSPDFExportCore.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscore
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EdxPrintEngine;
class PASCALIMPLEMENTATION EdxPrintEngine : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxPrintEngine(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxPrintEngine(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxPrintEngine(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxPrintEngine(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPrintEngine(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPrintEngine(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxPrintEngine(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxPrintEngine(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPrintEngine(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPrintEngine(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPrintEngine(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPrintEngine(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxPrintEngine(void) { }
	
};


class DELPHICLASS EdxReportLink;
class PASCALIMPLEMENTATION EdxReportLink : public EdxPrintEngine
{
	typedef EdxPrintEngine inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxReportLink(const System::UnicodeString Msg) : EdxPrintEngine(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxReportLink(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EdxPrintEngine(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxReportLink(NativeUInt Ident)/* overload */ : EdxPrintEngine(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxReportLink(System::PResStringRec ResStringRec)/* overload */ : EdxPrintEngine(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxReportLink(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxPrintEngine(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxReportLink(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxPrintEngine(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxReportLink(const System::UnicodeString Msg, int AHelpContext) : EdxPrintEngine(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxReportLink(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EdxPrintEngine(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxReportLink(NativeUInt Ident, int AHelpContext)/* overload */ : EdxPrintEngine(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxReportLink(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EdxPrintEngine(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxReportLink(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxPrintEngine(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxReportLink(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxPrintEngine(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxReportLink(void) { }
	
};


class DELPHICLASS EdxPSExplorer;
class PASCALIMPLEMENTATION EdxPSExplorer : public EdxPrintEngine
{
	typedef EdxPrintEngine inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxPSExplorer(const System::UnicodeString Msg) : EdxPrintEngine(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxPSExplorer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EdxPrintEngine(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxPSExplorer(NativeUInt Ident)/* overload */ : EdxPrintEngine(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxPSExplorer(System::PResStringRec ResStringRec)/* overload */ : EdxPrintEngine(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPSExplorer(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxPrintEngine(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPSExplorer(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxPrintEngine(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxPSExplorer(const System::UnicodeString Msg, int AHelpContext) : EdxPrintEngine(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxPSExplorer(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EdxPrintEngine(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPSExplorer(NativeUInt Ident, int AHelpContext)/* overload */ : EdxPrintEngine(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPSExplorer(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EdxPrintEngine(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPSExplorer(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxPrintEngine(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPSExplorer(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxPrintEngine(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxPSExplorer(void) { }
	
};


class DELPHICLASS EdxComponentPrinter;
class PASCALIMPLEMENTATION EdxComponentPrinter : public EdxPrintEngine
{
	typedef EdxPrintEngine inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxComponentPrinter(const System::UnicodeString Msg) : EdxPrintEngine(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxComponentPrinter(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EdxPrintEngine(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxComponentPrinter(NativeUInt Ident)/* overload */ : EdxPrintEngine(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxComponentPrinter(System::PResStringRec ResStringRec)/* overload */ : EdxPrintEngine(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxComponentPrinter(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxPrintEngine(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxComponentPrinter(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxPrintEngine(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxComponentPrinter(const System::UnicodeString Msg, int AHelpContext) : EdxPrintEngine(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxComponentPrinter(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EdxPrintEngine(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxComponentPrinter(NativeUInt Ident, int AHelpContext)/* overload */ : EdxPrintEngine(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxComponentPrinter(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EdxPrintEngine(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxComponentPrinter(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxPrintEngine(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxComponentPrinter(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxPrintEngine(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxComponentPrinter(void) { }
	
};


class DELPHICLASS EdxInvalidStorageVersion;
class PASCALIMPLEMENTATION EdxInvalidStorageVersion : public EdxComponentPrinter
{
	typedef EdxComponentPrinter inherited;
	
private:
	unsigned FVersion;
	
public:
	__fastcall EdxInvalidStorageVersion(unsigned AVersion, bool ADummy);
	__property unsigned Version = {read=FVersion, write=FVersion, nodefault};
public:
	/* Exception.CreateFmt */ inline __fastcall EdxInvalidStorageVersion(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EdxComponentPrinter(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxInvalidStorageVersion(NativeUInt Ident)/* overload */ : EdxComponentPrinter(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxInvalidStorageVersion(System::PResStringRec ResStringRec)/* overload */ : EdxComponentPrinter(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxInvalidStorageVersion(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxComponentPrinter(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxInvalidStorageVersion(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxComponentPrinter(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxInvalidStorageVersion(const System::UnicodeString Msg, int AHelpContext) : EdxComponentPrinter(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxInvalidStorageVersion(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EdxComponentPrinter(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxInvalidStorageVersion(NativeUInt Ident, int AHelpContext)/* overload */ : EdxComponentPrinter(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxInvalidStorageVersion(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EdxComponentPrinter(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxInvalidStorageVersion(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxComponentPrinter(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxInvalidStorageVersion(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxComponentPrinter(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxInvalidStorageVersion(void) { }
	
};


enum TdxPreviewEnableOption : unsigned char { peoCanChangeMargins, peoHelp, peoPageBackground, peoPageSetup, peoPreferences, peoPrint, peoReportDesign };

typedef System::Set<TdxPreviewEnableOption, TdxPreviewEnableOption::peoCanChangeMargins, TdxPreviewEnableOption::peoReportDesign>  TdxPreviewEnableOptions;

enum TdxPreviewVisibleOption : unsigned char { pvoHelp, pvoPageBackground, pvoPageSetup, pvoPreferences, pvoPrint, pvoReportDesign, pvoPrintStyles, pvoReportFileOperations, pvoPageMargins };

typedef System::Set<TdxPreviewVisibleOption, TdxPreviewVisibleOption::pvoHelp, TdxPreviewVisibleOption::pvoPageMargins>  TdxPreviewVisibleOptions;

enum TdxPSPreviewState : unsigned char { prsNone, prsEditHeaders, prsEditFooters };

enum TdxPSThumbnailsSize : unsigned char { tsSmall, tsLarge };

__interface IdxPSExplorerContextCommandBuilder;
typedef System::DelphiInterface<IdxPSExplorerContextCommandBuilder> _di_IdxPSExplorerContextCommandBuilder;
class DELPHICLASS TCustomdxPSExplorerContextCommand;
__interface  INTERFACE_UUID("{EE36E842-FD6A-4A89-A343-A32828AEFE3D}") IdxPSExplorerContextCommandBuilder  : public System::IInterface 
{
	
public:
	virtual void __fastcall AddExplorerContextCommand(TCustomdxPSExplorerContextCommand* ACommand) = 0 ;
	virtual void __fastcall UpdateExplorerContextCommands(void) = 0 ;
};

__interface IdxPSExplorerContextCommands;
typedef System::DelphiInterface<IdxPSExplorerContextCommands> _di_IdxPSExplorerContextCommands;
__interface  INTERFACE_UUID("{DC3A582D-7E33-410F-A235-680A846824D3}") IdxPSExplorerContextCommands  : public System::IInterface 
{
	
public:
	virtual void __fastcall BuildCommandSet(_di_IdxPSExplorerContextCommandBuilder ABuilder) = 0 ;
};

__interface IdxPSExplorerContextCommands2;
typedef System::DelphiInterface<IdxPSExplorerContextCommands2> _di_IdxPSExplorerContextCommands2;
__interface  INTERFACE_UUID("{E4D68CF3-AD07-4220-B892-92C8F9B3F966}") IdxPSExplorerContextCommands2  : public System::IInterface 
{
	
public:
	virtual void __fastcall FinalizeCommand(TCustomdxPSExplorerContextCommand* ACommand) = 0 ;
	virtual void __fastcall InitializeCommand(TCustomdxPSExplorerContextCommand* ACommand) = 0 ;
};

__interface IdxReportLinkController;
typedef System::DelphiInterface<IdxReportLinkController> _di_IdxReportLinkController;
__interface  INTERFACE_UUID("{120F53E4-1B09-46EF-B42D-04AB8BBCC374}") IdxReportLinkController  : public System::IInterface 
{
	
public:
	virtual System::Types::TRect __fastcall GetControlSiteBounds(Vcl::Controls::TControl* AControl) = 0 ;
};

typedef System::TMetaClass* TdxReportLinkClass;

typedef System::TMetaClass* TdxReportLinkDesignWindowClass;

typedef System::TMetaClass* TdxReportVisualItemClass;

typedef System::TMetaClass* TdxReportCellDataClass;

typedef System::TMetaClass* TdxReportCellClass;

typedef System::TMetaClass* TdxReportCellsClass;

typedef System::TMetaClass* TdxPSCellBorderClass;

typedef System::TMetaClass* TdxPSCellBorderPainterClass;

typedef System::TMetaClass* TdxPSReportGroupLookAndFeelClass;

typedef System::TMetaClass* TdxPSReportGroupLookAndFeelPainterClass;

typedef System::TMetaClass* TdxPSDataReaderClass;

class DELPHICLASS TdxPSDataReader;
class PASCALIMPLEMENTATION TdxPSDataReader : public System::Classes::TReader
{
	typedef System::Classes::TReader inherited;
	
private:
	Dxpsglbl::TdxPSVersion FPSVersion;
	
protected:
	__classmethod virtual bool __fastcall SupportsStorageVersion(int AVersion);
	
public:
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	TdxPSCellBorderClass __fastcall ReadCellBorderClass(void);
	System::TClass __fastcall ReadClass(void);
	Dxpsfillpatterns::TdxPSFillPatternClass __fastcall ReadFillPatternClass(void);
	Vcl::Graphics::TFont* __fastcall ReadFont(Vcl::Graphics::TFont* AFont);
	Vcl::Graphics::TGraphicClass __fastcall ReadGraphicClass(void);
	TdxReportLinkClass __fastcall ReadLinkClass(void);
	TdxPSReportGroupLookAndFeelClass __fastcall ReadLookAndFeelClass(void);
	System::Types::TPoint __fastcall ReadPoint(void);
	Dxpsglbl::TdxPSVersion __fastcall ReadPSVersion(void);
	System::Types::TRect __fastcall ReadRect(void);
	void __fastcall ReadImage(Vcl::Graphics::TGraphic* AImage);
	void __fastcall ReadImageList(Vcl::Imglist::TCustomImageList* AnImageList);
	HIDESBASE void __fastcall SkipBytes(__int64 Count);
	__property Dxpsglbl::TdxPSVersion PSVersion = {read=FPSVersion};
public:
	/* TReader.Destroy */ inline __fastcall virtual ~TdxPSDataReader(void) { }
	
public:
	/* TFiler.Create */ inline __fastcall TdxPSDataReader(System::Classes::TStream* Stream, int BufSize) : System::Classes::TReader(Stream, BufSize) { }
	
};


typedef System::TMetaClass* TdxPSDataWriterClass;

class DELPHICLASS TdxPSDataWriter;
class PASCALIMPLEMENTATION TdxPSDataWriter : public System::Classes::TWriter
{
	typedef System::Classes::TWriter inherited;
	
protected:
	Dxpsglbl::TdxPSVersion FPSVersion;
	__classmethod virtual bool __fastcall SupportsStorageVersion(int AVersion);
	
public:
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	void __fastcall WriteClassName(System::TClass AClass)/* overload */;
	void __fastcall WriteClassName(System::TObject* AnObject)/* overload */;
	void __fastcall WriteFont(Vcl::Graphics::TFont* AFont);
	void __fastcall WriteImage(Vcl::Graphics::TGraphic* AnImage);
	void __fastcall WriteImageList(Vcl::Imglist::TCustomImageList* AnImageList);
	void __fastcall WritePoint(const System::Types::TPoint Pt);
	void __fastcall WritePSVersion(const Dxpsglbl::TdxPSVersion &AVersion);
	void __fastcall WriteRect(const System::Types::TRect &R);
	__property Dxpsglbl::TdxPSVersion PSVersion = {read=FPSVersion};
public:
	/* TWriter.Destroy */ inline __fastcall virtual ~TdxPSDataWriter(void) { }
	
public:
	/* TFiler.Create */ inline __fastcall TdxPSDataWriter(System::Classes::TStream* Stream, int BufSize) : System::Classes::TWriter(Stream, BufSize) { }
	
};


struct DECLSPEC_DRECORD TdxWindowScalePair
{
public:
	int Numerator;
	int Denominator;
};


class DELPHICLASS TdxContinuedIndexPair;
class PASCALIMPLEMENTATION TdxContinuedIndexPair : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int StartIndex;
	int EndIndex;
public:
	/* TObject.Create */ inline __fastcall TdxContinuedIndexPair(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxContinuedIndexPair(void) { }
	
};


class DELPHICLASS TdxPageOverlayIndexes;
class PASCALIMPLEMENTATION TdxPageOverlayIndexes : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	int operator[](int Index) { return Items[Index]; }
	
private:
	int __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, int Value);
	
public:
	HIDESBASE int __fastcall Add(int AValue);
	__property int Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxPageOverlayIndexes(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPageOverlayIndexes(void) : System::Classes::TList() { }
	
};


typedef System::TMetaClass* TdxPSPageRenderInfoClass;

class DELPHICLASS TdxPSPageRenderInfo;
class DELPHICLASS TdxPSReportRenderInfo;
class DELPHICLASS TdxReportCells;
class DELPHICLASS TBasedxReportLink;
class PASCALIMPLEMENTATION TdxPSPageRenderInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FIndexPairs;
	bool FIsCompositionPagePart;
	bool FIsEmptyPage;
	bool FIsEmptyPageCalculated;
	System::Classes::TList* FOverlays;
	int FPageIndex;
	TdxPSReportRenderInfo* FRenderInfo;
	int __fastcall GetColIndex(void);
	System::Types::TRect __fastcall GetFooterBounds(void);
	System::Types::TRect __fastcall GetFootnotesBounds(void);
	int __fastcall GetFootnotesHeight(void);
	System::Types::TRect __fastcall GetHeaderBounds(void);
	System::Types::TRect __fastcall GetHeaderCornerBounds(void);
	TdxContinuedIndexPair* __fastcall GetIndexPair(int Index);
	int __fastcall GetIndexPairCount(void);
	bool __fastcall GetIsBottomPage(void);
	bool __fastcall GetIsEmptyPage(void);
	bool __fastcall GetIsTopPage(void);
	TdxPageOverlayIndexes* __fastcall GetOverlay(int Index);
	int __fastcall GetOverlayCount(void);
	Dxprnpg::TdxPrinterPage* __fastcall GetPrinterPage(void);
	TdxReportCells* __fastcall GetReportCells(void);
	TBasedxReportLink* __fastcall GetReportLink(void);
	System::Types::TRect __fastcall GetRowHeaderBounds(void);
	int __fastcall GetRowIndex(void);
	System::Types::TRect __fastcall GetTitleBounds(void);
	int __fastcall GetTitleHeight(void);
	void __fastcall SetIndexPair(int Index, TdxContinuedIndexPair* Value);
	void __fastcall FreeAndNilIndexPairs(void);
	void __fastcall FreeAndNilOverlays(void);
	
protected:
	System::Types::TPoint PageOffset;
	bool __fastcall AreRectsIntersected(const System::Types::TRect &R1, const System::Types::TRect &R2);
	virtual int __fastcall CalculateIndexPairCount(void);
	virtual bool __fastcall CalculateIsEmptyPage(void);
	virtual void __fastcall CalculateBounds(void);
	virtual void __fastcall CalculateIndexPairs(void);
	void __fastcall CalculateOffsets(void);
	void __fastcall CalculateOverlayIndexes(void);
	__property bool IsEmptyPageCalculated = {read=FIsEmptyPageCalculated, write=FIsEmptyPageCalculated, nodefault};
	
public:
	System::Types::TRect ContentBounds;
	System::Types::TPoint DataOffset;
	System::Types::TRect DetailBounds;
	System::Types::TPoint FootnotesOffset;
	System::Types::TPoint TitleOffset;
	__fastcall virtual TdxPSPageRenderInfo(TdxPSReportRenderInfo* ARenderInfo, int APageIndex);
	__fastcall virtual ~TdxPSPageRenderInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateCompositionPartInfo(void);
	virtual void __fastcall CalculateFootnotesOffset(void);
	virtual void __fastcall CalculateTitleOffset(void);
	virtual bool __fastcall HasDetails(void);
	virtual bool __fastcall HasFooter(void);
	virtual bool __fastcall HasFootnotes(void);
	virtual bool __fastcall HasHeader(void);
	virtual bool __fastcall HasHeaderCorner(void);
	virtual bool __fastcall HasRowHeader(void);
	virtual bool __fastcall HasTitle(void);
	__property int ColIndex = {read=GetColIndex, nodefault};
	__property System::Types::TRect FooterBounds = {read=GetFooterBounds};
	__property System::Types::TRect FootnotesBounds = {read=GetFootnotesBounds};
	__property int FootnotesHeight = {read=GetFootnotesHeight, nodefault};
	__property System::Types::TRect HeaderBounds = {read=GetHeaderBounds};
	__property System::Types::TRect HeaderCornerBounds = {read=GetHeaderCornerBounds};
	__property int IndexPairCount = {read=GetIndexPairCount, nodefault};
	__property TdxContinuedIndexPair* IndexPairs[int Index] = {read=GetIndexPair, write=SetIndexPair};
	__property bool IsBottomPage = {read=GetIsBottomPage, nodefault};
	__property bool IsCompositionPagePart = {read=FIsCompositionPagePart, nodefault};
	__property bool IsEmptyPage = {read=GetIsEmptyPage, nodefault};
	__property bool IsTopPage = {read=GetIsTopPage, nodefault};
	__property int OverlayCount = {read=GetOverlayCount, nodefault};
	__property TdxPageOverlayIndexes* Overlays[int Index] = {read=GetOverlay};
	__property int PageIndex = {read=FPageIndex, nodefault};
	__property Dxprnpg::TdxPrinterPage* PrinterPage = {read=GetPrinterPage};
	__property TdxPSReportRenderInfo* RenderInfo = {read=FRenderInfo};
	__property TdxReportCells* ReportCells = {read=GetReportCells};
	__property TBasedxReportLink* ReportLink = {read=GetReportLink};
	__property System::Types::TRect RowHeaderBounds = {read=GetRowHeaderBounds};
	__property int RowIndex = {read=GetRowIndex, nodefault};
	__property System::Types::TRect TitleBounds = {read=GetTitleBounds};
	__property int TitleHeight = {read=GetTitleHeight, nodefault};
};


typedef System::TMetaClass* TdxPSReportRenderInfoClass;

enum TdxPSCalculatePagesStage : unsigned char { cpsFirstPass, cpsSecondPass };

class DELPHICLASS TdxPSCompositionReportRenderRowInfo;
class PASCALIMPLEMENTATION TdxPSReportRenderInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TFont* FBaseContentFont;
	int FCompositionPagePartCount;
	System::Classes::TList* FDelimitersX;
	System::Classes::TList* FDelimitersY;
	System::Uitypes::TColor FGridLinesColor;
	System::Classes::TList* FHardDelimitersX;
	System::Classes::TList* FHardDelimitersY;
	int FLockCounter;
	System::Classes::TList* FPageDelimitersX;
	System::Classes::TList* FPageDelimitersY;
	System::Classes::TList* FPageRenderInfos;
	TBasedxReportLink* FReportLink;
	bool __fastcall GetBreakPagesByHardDelimiters(void);
	int __fastcall GetDelimiterX(int Index);
	int __fastcall GetDelimiterXCount(void);
	int __fastcall GetDelimiterY(int Index);
	int __fastcall GetDelimiterYCount(void);
	int __fastcall GetFooterHeight(void);
	bool __fastcall GetFootnotesAdjustOnReportScale(void);
	Vcl::Graphics::TFont* __fastcall GetFootnotesFont(void);
	int __fastcall GetFootnotesHeight(void);
	System::UnicodeString __fastcall GetFootnotesText(void);
	int __fastcall GetHeaderHeight(void);
	bool __fastcall GetLocked(void);
	int __fastcall GetPageDelimiterX(int Index);
	int __fastcall GetPageDelimiterXCount(void);
	int __fastcall GetPageDelimiterY(int Index);
	int __fastcall GetPageDelimiterYCount(void);
	TdxPSPageRenderInfo* __fastcall GetPageRenderInfo(int Index);
	int __fastcall GetPageRenderInfoCount(void);
	Dxprnpg::TdxPrinterPage* __fastcall GetPrinterPage(void);
	TdxReportCells* __fastcall GetReportCells(void);
	int __fastcall GetReportHeight(void);
	int __fastcall GetReportWidth(void);
	int __fastcall GetRowHeaderWidth(void);
	int __fastcall GetScaleFactor(void);
	bool __fastcall GetTitleAdjustOnReportScale(void);
	Vcl::Graphics::TFont* __fastcall GetTitleFont(void);
	System::UnicodeString __fastcall GetTitleText(void);
	bool __fastcall GetUseHardHorzDelimiters(void);
	bool __fastcall GetUseHardVertDelimiters(void);
	bool __fastcall GetUseHorzDelimiters(void);
	bool __fastcall GetUseVertDelimiters(void);
	int __fastcall GetTitleHeight(void);
	void __fastcall SetBaseContentFont(Vcl::Graphics::TFont* Value);
	bool __fastcall IsNonEmptyPage(const System::Types::TRect &ABounds);
	
protected:
	virtual int __fastcall CalculateCompositionPagePartCount(void);
	virtual int __fastcall CalculatePageContentHeight(int APageIndex);
	virtual int __fastcall CalculatePageContentWidth(int APageIndex);
	virtual System::Types::TRect __fastcall CalculatePageDetailBounds(int APageCol, int APageRow);
	virtual void __fastcall CalculateFootnotesBounds(void);
	virtual void __fastcall CalculateHeaderAndFooterBounds(void);
	virtual void __fastcall CalculatePages(TdxPSCalculatePagesStage AStage);
	virtual void __fastcall CalculatePageHeaderAndFooterBounds(void);
	virtual void __fastcall CalculatePageRenderInfos(void);
	virtual void __fastcall CalculateTitleBounds(void);
	virtual void __fastcall DoCalculate(void);
	bool __fastcall GetCompositionInfo(int APageIndex, /* out */ TdxPSCompositionReportRenderRowInfo* &ARowInfo);
	virtual int __fastcall GetCompositionPagePartCount(void);
	virtual int __fastcall GetNonEmptyPageCount(void);
	virtual int __fastcall GetPageColCount(void);
	virtual int __fastcall GetPageRowCount(void);
	virtual System::Types::TPoint __fastcall GetPageSize(void);
	virtual System::Types::TPoint __fastcall GetPaintSize(void);
	virtual int __fastcall GetPointsPerInch(void);
	virtual int __fastcall GetUnitsPerInch(void);
	virtual TdxWindowScalePair __fastcall GetWindowScalePair(void);
	virtual void __fastcall SetUnitsPerInch(int Value);
	void __fastcall ClearPageRenderInfos(void);
	virtual TdxPSPageRenderInfo* __fastcall CreatePageRenderInfo(int APageIndex);
	void __fastcall FreeAndNilPageRenderInfos(void);
	virtual TdxPSPageRenderInfoClass __fastcall GetPageRenderInfoClass(void);
	virtual void __fastcall Refresh(void);
	bool __fastcall HasPageFootnotes(int APageIndex);
	bool __fastcall HasPageTitle(int APageIndex);
	bool __fastcall IsHardHorizontalDelimiter(int AValue);
	bool __fastcall IsHardVerticalDelimiter(int AValue);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	void __fastcall ReadDelimiters(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	void __fastcall WriteDelimiters(TdxPSDataWriter* AWriter);
	void __fastcall AddPageDelimiterX(int AValue);
	void __fastcall AddPageDelimiterY(int AValue);
	void __fastcall PageDelimiterXClear(void);
	void __fastcall PageDelimiterYClear(void);
	void __fastcall AddStandardDelimiters(void);
	void __fastcall EliminateDuplicatesAndSortDelimiters(System::Classes::TList* AList);
	void __fastcall GetDelimiters(void);
	void __fastcall MakeDelimiters(void);
	void __fastcall MakeHardDelimiters(void);
	void __fastcall TrancateDelimiters(System::Classes::TList* AList, int AValue);
	System::Types::TRect __fastcall LoMetricRectToInternalUnits(const System::Types::TRect &R);
	virtual int __fastcall LoMetricValueToInternalUnits(int Value);
	__property System::Classes::TList* DelimiterXList = {read=FDelimitersX};
	__property System::Classes::TList* DelimiterYList = {read=FDelimitersY};
	__property System::Classes::TList* HardDelimiterXList = {read=FHardDelimitersX};
	__property System::Classes::TList* HardDelimiterYList = {read=FHardDelimitersY};
	
public:
	bool CanUseHFOnEveryPageMode;
	System::Types::TRect FooterBounds;
	System::Types::TRect FootnotesBounds;
	System::Types::TRect HeaderBounds;
	System::Types::TRect HeaderCornerBounds;
	System::Types::TRect PageFooterBounds;
	System::Types::TRect PageHeaderBounds;
	System::Types::TRect RowHeaderBounds;
	System::Types::TRect TitleBounds;
	int VirtualPageCount;
	__fastcall virtual TdxPSReportRenderInfo(TBasedxReportLink* AReportLink);
	__fastcall virtual ~TdxPSReportRenderInfo(void);
	void __fastcall Calculate(void);
	virtual int __fastcall CalculateActualScaleFactor(void);
	virtual int __fastcall CalculateFootnotesHeight(bool AAdjustOnReportScale)/* overload */;
	int __fastcall CalculateFootnotesHeight(void)/* overload */;
	virtual int __fastcall CalculateTitleHeight(bool AAdjustOnReportScale)/* overload */;
	int __fastcall CalculateTitleHeight(void)/* overload */;
	virtual int __fastcall CalculateReportNotesTextHeight(const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, bool AAdjustOnReportScale);
	virtual bool __fastcall CanRenderPage(int APageIndex);
	virtual bool __fastcall IsDrawPageFootnotesOnPage(int APageIndex);
	virtual bool __fastcall IsDrawPageTitleOnPage(int APageIndex);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	__property Vcl::Graphics::TFont* BaseContentFont = {read=FBaseContentFont, write=SetBaseContentFont};
	__property bool BreakPagesByHardDelimiters = {read=GetBreakPagesByHardDelimiters, nodefault};
	__property int CompositionPagePartCount = {read=GetCompositionPagePartCount, nodefault};
	__property int DelimitersX[int Index] = {read=GetDelimiterX};
	__property int DelimitersY[int Index] = {read=GetDelimiterY};
	__property int DelimiterXCount = {read=GetDelimiterXCount, nodefault};
	__property int DelimiterYCount = {read=GetDelimiterYCount, nodefault};
	__property int FooterHeight = {read=GetFooterHeight, nodefault};
	__property bool FootnotesAdjustOnReportScale = {read=GetFootnotesAdjustOnReportScale, nodefault};
	__property Vcl::Graphics::TFont* FootnotesFont = {read=GetFootnotesFont};
	__property int FootnotesHeight = {read=GetFootnotesHeight, nodefault};
	__property System::UnicodeString FootnotesText = {read=GetFootnotesText};
	__property System::Uitypes::TColor GridLinesColor = {read=FGridLinesColor, write=FGridLinesColor, nodefault};
	__property int HeaderHeight = {read=GetHeaderHeight, nodefault};
	__property bool Locked = {read=GetLocked, nodefault};
	__property int NonEmptyPageCount = {read=GetNonEmptyPageCount, nodefault};
	__property int PageColCount = {read=GetPageColCount, nodefault};
	__property int PageDelimitersX[int Index] = {read=GetPageDelimiterX};
	__property int PageDelimiterXCount = {read=GetPageDelimiterXCount, nodefault};
	__property int PageDelimitersY[int Index] = {read=GetPageDelimiterY};
	__property int PageDelimiterYCount = {read=GetPageDelimiterYCount, nodefault};
	__property int PageRenderInfoCount = {read=GetPageRenderInfoCount, nodefault};
	__property TdxPSPageRenderInfo* PageRenderInfos[int Index] = {read=GetPageRenderInfo};
	__property int PageRowCount = {read=GetPageRowCount, nodefault};
	__property System::Types::TPoint PageSize = {read=GetPageSize};
	__property System::Types::TPoint PaintSize = {read=GetPaintSize};
	__property Dxprnpg::TdxPrinterPage* PrinterPage = {read=GetPrinterPage};
	__property TdxReportCells* ReportCells = {read=GetReportCells};
	__property int ReportHeight = {read=GetReportHeight, nodefault};
	__property TBasedxReportLink* ReportLink = {read=FReportLink};
	__property int ReportWidth = {read=GetReportWidth, nodefault};
	__property int RowHeaderWidth = {read=GetRowHeaderWidth, nodefault};
	__property int ScaleFactor = {read=GetScaleFactor, nodefault};
	__property bool TitleAdjustOnReportScale = {read=GetTitleAdjustOnReportScale, nodefault};
	__property Vcl::Graphics::TFont* TitleFont = {read=GetTitleFont};
	__property int TitleHeight = {read=GetTitleHeight, nodefault};
	__property System::UnicodeString TitleText = {read=GetTitleText};
	__property int PointsPerInch = {read=GetPointsPerInch, nodefault};
	__property int UnitsPerInch = {read=GetUnitsPerInch, write=SetUnitsPerInch, nodefault};
	__property bool UseHardHorzDelimiters = {read=GetUseHardHorzDelimiters, nodefault};
	__property bool UseHardVertDelimiters = {read=GetUseHardVertDelimiters, nodefault};
	__property bool UseHorzDelimiters = {read=GetUseHorzDelimiters, nodefault};
	__property bool UseVertDelimiters = {read=GetUseVertDelimiters, nodefault};
	__property TdxWindowScalePair WindowScalePair = {read=GetWindowScalePair};
};


enum TdxCellCheckPos : unsigned char { ccpLeft, ccpCenter, ccpRight };

enum TdxCellEdgeKind : unsigned char { cekInner, cekOuter };

enum TdxCellEdgeMode : unsigned char { cemPattern, cem3DEffects };

enum TdxCellEdgeStyle : unsigned char { cesRaised, cesSunken };

enum TdxCellSide : unsigned char { csLeft, csTop, csRight, csBottom };

typedef System::Set<TdxCellSide, TdxCellSide::csLeft, TdxCellSide::csBottom>  TdxCellSides;

enum TdxCellSortOrder : unsigned char { csoNone, csoUp, csoDown };

typedef TdxCellSortOrder TdxCellUpDown;

typedef Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle TdxCheckButtonEdgeStyle;

enum TdxGraphicDrawMode : unsigned char { gdmNone, gdmCenter, gdmStretch, gdmStretchProportional, gdmCenterAndStretchProportional, gdmProportional, gdmCenterProportional };

enum TdxImageLayout : unsigned char { ilImageTopLeft, ilImageTopCenter, ilImageTopRight, ilImageCenterLeft, ilImageCenterCenter, ilImageCenterRight, ilImageBottomLeft, ilImageBottomCenter, ilImageBottomRight };

enum TdxCellImageBuffering : unsigned char { cibDefault, cibNone, cibAlways };

typedef TdxCellImageBuffering TdxCellImageActualBuffering;

enum TdxPSCellBorderSalientType : unsigned char { bstOuter, bstInner };

enum TdxPSTreeLineMode : unsigned char { tlmNone, tlmVertical, tlmCross, tlmTopRightCorner, tlmBottomRightCorner };

enum TdxPSTreeLinePart : unsigned char { tlpTop, tlpRight, tlpBottom };

typedef System::Set<TdxPSTreeLinePart, TdxPSTreeLinePart::tlpTop, TdxPSTreeLinePart::tlpBottom>  TdxPSTreeLineParts;

enum TdxPSTreeLineStyle : unsigned char { tlsSolid, tlsDot };

class DELPHICLASS TdxPSCellBorderPainter;
class DELPHICLASS TdxReportVisualItem;
class DELPHICLASS TdxPSReportRenderer;
class PASCALIMPLEMENTATION TdxPSCellBorderPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxReportVisualItem* FItem;
	TdxPSReportRenderer* FRenderer;
	int __fastcall GetLineThickness(void);
	
protected:
	__classmethod virtual System::Types::TRect __fastcall GetBorderBounds(const System::Types::TRect &R, TdxCellSide ASide, int ALineThickness);
	__classmethod System::Types::TRect __fastcall GetBottomShadowBounds(const System::Types::TRect &R, int AShadowDepth);
	__classmethod System::Types::TRect __fastcall GetBottomShadowRestSpaceBounds(const System::Types::TRect &R, int AShadowDepth);
	__classmethod System::Types::TRect __fastcall GetRightShadowBounds(const System::Types::TRect &R, int AShadowDepth);
	__classmethod System::Types::TRect __fastcall GetRightShadowRestSpaceBounds(const System::Types::TRect &R, int AShadowDepth);
	__classmethod void __fastcall InflateRect(System::Types::TRect &R, TdxCellSides ASides, int ALineThickness);
	
public:
	__fastcall virtual TdxPSCellBorderPainter(TdxPSReportRenderer* ARenderer);
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod void __fastcall DrawFrame(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, TdxCellSides ASides, System::Uitypes::TColor ATopLeftColor, System::Uitypes::TColor ARightBottomColor, int ALineThickness, int AThickness = 0x1);
	__classmethod void __fastcall DrawShadow(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, int AShadowDepth, System::Uitypes::TColor AShadowColor, System::Uitypes::TColor ARestSpaceColor);
	virtual TdxPSCellBorderClass __fastcall BorderClass(void)/* overload */;
	virtual TdxReportVisualItem* __fastcall Item(void)/* overload */;
	virtual TdxPSReportRenderer* __fastcall Renderer(void)/* overload */;
	__property int LineThickness = {read=GetLineThickness, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCellBorderPainter(void) { }
	
};


class DELPHICLASS TdxPSCustomCellBorder;
class PASCALIMPLEMENTATION TdxPSCustomCellBorder : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	__classmethod virtual bool __fastcall Edge3DSoft();
	__classmethod virtual TdxCellEdgeStyle __fastcall Edge3DStyle();
	__classmethod virtual TdxCellEdgeMode __fastcall EdgeMode();
	__classmethod virtual int __fastcall GetBorderEdgeSalient(TdxCellSide ASide, TdxPSCellBorderSalientType ASalient);
	__classmethod virtual TdxPSCellBorderPainterClass __fastcall GetPainterClass();
	
public:
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	__classmethod virtual bool __fastcall Solid();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCustomCellBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCustomCellBorder(void) : System::Classes::TPersistent() { }
	
};


class DELPHICLASS TdxPSCellNullBorder;
class PASCALIMPLEMENTATION TdxPSCellNullBorder : public TdxPSCustomCellBorder
{
	typedef TdxPSCustomCellBorder inherited;
	
public:
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellNullBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellNullBorder(void) : TdxPSCustomCellBorder() { }
	
};


class DELPHICLASS TdxPSCellFlatBorder;
class PASCALIMPLEMENTATION TdxPSCellFlatBorder : public TdxPSCustomCellBorder
{
	typedef TdxPSCustomCellBorder inherited;
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellFlatBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellFlatBorder(void) : TdxPSCustomCellBorder() { }
	
};


class DELPHICLASS TdxPSCellBoldFlatBorder;
class PASCALIMPLEMENTATION TdxPSCellBoldFlatBorder : public TdxPSCellFlatBorder
{
	typedef TdxPSCellFlatBorder inherited;
	
public:
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellBoldFlatBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellBoldFlatBorder(void) : TdxPSCellFlatBorder() { }
	
};


class DELPHICLASS TdxPSCellUltraFlatBorder;
class PASCALIMPLEMENTATION TdxPSCellUltraFlatBorder : public TdxPSCellFlatBorder
{
	typedef TdxPSCellFlatBorder inherited;
	
public:
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellUltraFlatBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellUltraFlatBorder(void) : TdxPSCellFlatBorder() { }
	
};


typedef System::TMetaClass* TdxPSCell3DBorderClass;

class DELPHICLASS TdxPSCell3DBorderPainter;
class PASCALIMPLEMENTATION TdxPSCell3DBorderPainter : public TdxPSCellBorderPainter
{
	typedef TdxPSCellBorderPainter inherited;
	
public:
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall Draw3DFrame(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, TdxCellSides ASides, System::Uitypes::TColor AOuterTLColor, System::Uitypes::TColor AOuterBRColor, System::Uitypes::TColor AInnerTLColor, System::Uitypes::TColor AInnerBRColor, int ALineThickness)/* overload */;
	__classmethod virtual void __fastcall Draw3DFrame(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, TdxCellSides ASides, TdxPSCell3DBorderClass ACellBorders, int ALineThickness)/* overload */;
	HIDESBASE TdxPSCell3DBorderClass __fastcall BorderClass(void)/* overload */;
public:
	/* TdxPSCellBorderPainter.Create */ inline __fastcall virtual TdxPSCell3DBorderPainter(TdxPSReportRenderer* ARenderer) : TdxPSCellBorderPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCell3DBorderPainter(void) { }
	
};


class DELPHICLASS TdxPSCustomCell3DBorder;
class PASCALIMPLEMENTATION TdxPSCustomCell3DBorder : public TdxPSCustomCellBorder
{
	typedef TdxPSCustomCellBorder inherited;
	
protected:
	__classmethod virtual TdxCellEdgeMode __fastcall EdgeMode();
	__classmethod virtual int __fastcall GetBorderEdgeSalient(TdxCellSide ASide, TdxPSCellBorderSalientType ASalient);
	__classmethod virtual TdxPSCellBorderPainterClass __fastcall GetPainterClass();
	
public:
	__classmethod virtual bool __fastcall Solid();
	__classmethod virtual int __fastcall Thickness();
	__classmethod virtual HBRUSH __fastcall BottomRightInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightInnerColor();
	__classmethod virtual HBRUSH __fastcall BottomRightOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightOuterColor();
	__classmethod virtual HBRUSH __fastcall TopLeftInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftInnerColor();
	__classmethod virtual HBRUSH __fastcall TopLeftOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftOuterColor();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCustomCell3DBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCustomCell3DBorder(void) : TdxPSCustomCellBorder() { }
	
};


class DELPHICLASS TdxPSCellRaisedBorder;
class PASCALIMPLEMENTATION TdxPSCellRaisedBorder : public TdxPSCustomCell3DBorder
{
	typedef TdxPSCustomCell3DBorder inherited;
	
protected:
	__classmethod virtual bool __fastcall Edge3DSoft();
	__classmethod virtual TdxCellEdgeStyle __fastcall Edge3DStyle();
	
public:
	__classmethod virtual HBRUSH __fastcall BottomRightInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightInnerColor();
	__classmethod virtual HBRUSH __fastcall BottomRightOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightOuterColor();
	__classmethod virtual HBRUSH __fastcall TopLeftInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftInnerColor();
	__classmethod virtual HBRUSH __fastcall TopLeftOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftOuterColor();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellRaisedBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellRaisedBorder(void) : TdxPSCustomCell3DBorder() { }
	
};


class DELPHICLASS TdxPSCellRaisedSoftBorder;
class PASCALIMPLEMENTATION TdxPSCellRaisedSoftBorder : public TdxPSCellRaisedBorder
{
	typedef TdxPSCellRaisedBorder inherited;
	
protected:
	__classmethod virtual bool __fastcall Edge3DSoft();
	
public:
	__classmethod virtual HBRUSH __fastcall BottomRightInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightInnerColor();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellRaisedSoftBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellRaisedSoftBorder(void) : TdxPSCellRaisedBorder() { }
	
};


class DELPHICLASS TdxPSCellSunkenBorder;
class PASCALIMPLEMENTATION TdxPSCellSunkenBorder : public TdxPSCustomCell3DBorder
{
	typedef TdxPSCustomCell3DBorder inherited;
	
protected:
	__classmethod virtual bool __fastcall Edge3DSoft();
	__classmethod virtual TdxCellEdgeStyle __fastcall Edge3DStyle();
	
public:
	__classmethod virtual HBRUSH __fastcall BottomRightInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightInnerColor();
	__classmethod virtual HBRUSH __fastcall BottomRightOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightOuterColor();
	__classmethod virtual HBRUSH __fastcall TopLeftInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftInnerColor();
	__classmethod virtual HBRUSH __fastcall TopLeftOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftOuterColor();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellSunkenBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellSunkenBorder(void) : TdxPSCustomCell3DBorder() { }
	
};


class DELPHICLASS TdxPSCellSunkenSoftBorder;
class PASCALIMPLEMENTATION TdxPSCellSunkenSoftBorder : public TdxPSCellSunkenBorder
{
	typedef TdxPSCellSunkenBorder inherited;
	
protected:
	__classmethod virtual bool __fastcall Edge3DSoft();
	
public:
	__classmethod virtual HBRUSH __fastcall BottomRightInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightInnerColor();
	__classmethod virtual HBRUSH __fastcall TopLeftInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftInnerColor();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellSunkenSoftBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellSunkenSoftBorder(void) : TdxPSCellSunkenBorder() { }
	
};


class DELPHICLASS TdxPSCellTwistedBorderPainter;
class PASCALIMPLEMENTATION TdxPSCellTwistedBorderPainter : public TdxPSCell3DBorderPainter
{
	typedef TdxPSCell3DBorderPainter inherited;
	
public:
	__classmethod virtual void __fastcall Draw3DFrame(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, TdxCellSides ASides, TdxPSCell3DBorderClass ACellBorders, int ALineThickness)/* overload */;
	__classmethod virtual void __fastcall Draw3DFrame(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, TdxCellSides ASides, System::Uitypes::TColor AOuterTLColor, System::Uitypes::TColor AOuterBRColor, System::Uitypes::TColor AInnerTLColor, System::Uitypes::TColor AInnerBRColor, int ALineThickness)/* overload */;
public:
	/* TdxPSCellBorderPainter.Create */ inline __fastcall virtual TdxPSCellTwistedBorderPainter(TdxPSReportRenderer* ARenderer) : TdxPSCell3DBorderPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCellTwistedBorderPainter(void) { }
	
};


class DELPHICLASS TdxPSCellTwistedBorder;
class PASCALIMPLEMENTATION TdxPSCellTwistedBorder : public TdxPSCustomCell3DBorder
{
	typedef TdxPSCustomCell3DBorder inherited;
	
protected:
	__classmethod virtual TdxPSCellBorderPainterClass __fastcall GetPainterClass();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellTwistedBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellTwistedBorder(void) : TdxPSCustomCell3DBorder() { }
	
};


class DELPHICLASS TdxPSCellEtchedBorder;
class PASCALIMPLEMENTATION TdxPSCellEtchedBorder : public TdxPSCellTwistedBorder
{
	typedef TdxPSCellTwistedBorder inherited;
	
public:
	__classmethod virtual HBRUSH __fastcall BottomRightInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightInnerColor();
	__classmethod virtual HBRUSH __fastcall BottomRightOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightOuterColor();
	__classmethod virtual HBRUSH __fastcall TopLeftInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftInnerColor();
	__classmethod virtual HBRUSH __fastcall TopLeftOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftOuterColor();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellEtchedBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellEtchedBorder(void) : TdxPSCellTwistedBorder() { }
	
};


class DELPHICLASS TdxPSCellBumpedBorder;
class PASCALIMPLEMENTATION TdxPSCellBumpedBorder : public TdxPSCellTwistedBorder
{
	typedef TdxPSCellTwistedBorder inherited;
	
public:
	__classmethod virtual HBRUSH __fastcall BottomRightInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightInnerColor();
	__classmethod virtual HBRUSH __fastcall BottomRightOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall BottomRightOuterColor();
	__classmethod virtual HBRUSH __fastcall TopLeftInnerBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftInnerColor();
	__classmethod virtual HBRUSH __fastcall TopLeftOuterBrush();
	__classmethod virtual System::Uitypes::TColor __fastcall TopLeftOuterColor();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCellBumpedBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCellBumpedBorder(void) : TdxPSCellTwistedBorder() { }
	
};


class DELPHICLASS TdxPSColorBorderPainter;
class PASCALIMPLEMENTATION TdxPSColorBorderPainter : public TdxPSCellBorderPainter
{
	typedef TdxPSCellBorderPainter inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetSideColor(TdxCellSide ASide);
	
public:
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	__property System::Uitypes::TColor SideColor[TdxCellSide ASide] = {read=GetSideColor};
public:
	/* TdxPSCellBorderPainter.Create */ inline __fastcall virtual TdxPSColorBorderPainter(TdxPSReportRenderer* ARenderer) : TdxPSCellBorderPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSColorBorderPainter(void) { }
	
};


class DELPHICLASS TdxPSColorBorder;
class PASCALIMPLEMENTATION TdxPSColorBorder : public TdxPSCellUltraFlatBorder
{
	typedef TdxPSCellUltraFlatBorder inherited;
	
protected:
	__classmethod virtual TdxPSCellBorderPainterClass __fastcall GetPainterClass();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSColorBorder(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSColorBorder(void) : TdxPSCellUltraFlatBorder() { }
	
};


class DELPHICLASS TdxPSBackgroundBitmapPool;
class PASCALIMPLEMENTATION TdxPSBackgroundBitmapPool : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Vcl::Graphics::TBitmap* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	Vcl::Graphics::TBitmap* __fastcall GetItem(int Index);
	
protected:
	void __fastcall ReadData(TdxPSDataReader* AReader);
	void __fastcall WriteData(TdxPSDataWriter* AWriter);
	
public:
	__fastcall TdxPSBackgroundBitmapPool(void);
	__fastcall virtual ~TdxPSBackgroundBitmapPool(void);
	void __fastcall Assign(TdxPSBackgroundBitmapPool* Source);
	int __fastcall Add(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall Clear(void);
	void __fastcall Delete(int AnIndex);
	bool __fastcall Find(Vcl::Graphics::TBitmap* ABitmap, /* out */ int &AnIndex);
	__property int Count = {read=GetCount, nodefault};
	__property Vcl::Graphics::TBitmap* Items[int Index] = {read=GetItem/*, default*/};
};


class DELPHICLASS TdxPSBrushPoolItem;
class PASCALIMPLEMENTATION TdxPSBrushPoolItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TBrush* FBrush;
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TBrush* __fastcall GetBrush(void);
	
public:
	__fastcall TdxPSBrushPoolItem(System::Uitypes::TColor AColor);
	__fastcall virtual ~TdxPSBrushPoolItem(void);
	__property Vcl::Graphics::TBrush* Brush = {read=GetBrush};
	__property System::Uitypes::TColor Color = {read=FColor, nodefault};
};


class DELPHICLASS TdxPSReportBrushPool;
class PASCALIMPLEMENTATION TdxPSReportBrushPool : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Vcl::Graphics::TBrush* operator[](System::Uitypes::TColor AColor) { return Brushes[AColor]; }
	
private:
	System::Classes::TList* FItems;
	Vcl::Graphics::TBrush* __fastcall GetBrush(System::Uitypes::TColor AColor);
	int __fastcall GetCount(void);
	TdxPSBrushPoolItem* __fastcall GetItem(int Index);
	
protected:
	int __fastcall Add(System::Uitypes::TColor AColor);
	
public:
	__fastcall TdxPSReportBrushPool(void);
	__fastcall virtual ~TdxPSReportBrushPool(void);
	void __fastcall Clear(void);
	int __fastcall IndexOf(System::Uitypes::TColor AColor);
	__property Vcl::Graphics::TBrush* Brushes[System::Uitypes::TColor AColor] = {read=GetBrush/*, default*/};
	__property int Count = {read=GetCount, nodefault};
	__property TdxPSBrushPoolItem* Items[int Index] = {read=GetItem};
};


typedef System::TMetaClass* TdxPSReportRendererClass;

class DELPHICLASS TdxPSFontPoolItem;
class PASCALIMPLEMENTATION TdxPSFontPoolItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TFont* FFont;
	int FOriginalSize;
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	
public:
	__fastcall TdxPSFontPoolItem(Vcl::Graphics::TFont* AFont);
	__fastcall virtual ~TdxPSFontPoolItem(void);
	void __fastcall PrepareFont(int AUnitsPerInch);
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property int OriginalSize = {read=FOriginalSize, write=FOriginalSize, nodefault};
};


class DELPHICLASS TdxPSReportFontPool;
class PASCALIMPLEMENTATION TdxPSReportFontPool : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Vcl::Graphics::TFont* operator[](int Index) { return Fonts[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	Vcl::Graphics::TFont* __fastcall GetFont(int Index);
	TdxPSFontPoolItem* __fastcall GetItem(int Index);
	
protected:
	bool FLocked;
	int __fastcall CreateFont(Vcl::Graphics::TFont* AFont);
	void __fastcall FontChanged(System::TObject* Sender);
	void __fastcall PrepareFonts(int UPI);
	void __fastcall ReadData(TdxPSDataReader* AReader);
	void __fastcall WriteData(TdxPSDataWriter* AWriter);
	
public:
	__fastcall TdxPSReportFontPool(void);
	__fastcall virtual ~TdxPSReportFontPool(void);
	int __fastcall Add(Vcl::Graphics::TFont* AFont);
	void __fastcall Clear(void);
	int __fastcall IndexOf(Vcl::Graphics::TFont* AFont);
	__property int Count = {read=GetCount, nodefault};
	__property Vcl::Graphics::TFont* Fonts[int Index] = {read=GetFont/*, default*/};
	__property TdxPSFontPoolItem* Items[int Index] = {read=GetItem};
};


class DELPHICLASS TdxPSCachedGraphicInfo;
class PASCALIMPLEMENTATION TdxPSCachedGraphicInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxBitmap* FCacheBitmap;
	TdxPSReportRenderer* FRenderer;
	Vcl::Graphics::TGraphic* FSourceGraphic;
	
protected:
	int UnitsPerInch;
	int UnitsPerPixel;
	System::Types::TRect ViewPortRect;
	int ZoomFactor;
	bool __fastcall CheckRendererModeInfo(void);
	void __fastcall PrepareByGraphic(Vcl::Graphics::TGraphic* AGraphic, System::Uitypes::TColor ABackgroundColor, bool AIsTransparent);
	void __fastcall PrepareByImageList(Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, System::Uitypes::TColor ABackgroundColor, bool AIsTransparent);
	void __fastcall SaveModeInfo(void);
	__property Cxgraphics::TcxBitmap* CacheBitmap = {read=FCacheBitmap};
	__property TdxPSReportRenderer* Renderer = {read=FRenderer};
	
public:
	__fastcall virtual TdxPSCachedGraphicInfo(TdxPSReportRenderer* ARenderer);
	__fastcall virtual ~TdxPSCachedGraphicInfo(void);
	void __fastcall Clear(void);
	void __fastcall PrepareImage(Vcl::Graphics::TGraphic* AGraphic, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, System::Uitypes::TColor ABackgroundColor, bool AIsTransparent);
};


enum TdxPSRenderStage : unsigned char { rsFirstPass, rsSecondPass };

typedef System::Set<TdxPSRenderStage, TdxPSRenderStage::rsFirstPass, TdxPSRenderStage::rsSecondPass>  TdxPSRenderStages;

class DELPHICLASS TdxPSReportGroupLookAndFeelPainter;
class DELPHICLASS TAbstractdxReportCellData;
class DELPHICLASS TdxReportCell;
class PASCALIMPLEMENTATION TdxPSReportRenderer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	System::Classes::TList* FBorderPainters;
	TdxPSReportBrushPool* FBrushPool;
	TdxPSCachedGraphicInfo* FCachedGraphicInfo;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* FCanvas;
	Cxgraphics::TcxBitmap* FCheckBitmap;
	System::Classes::TList* FGroupLookAndFeelPainters;
	System::Classes::TStrings* FHFStrings;
	bool FIsRendering;
	int FLineThickness;
	Vcl::Graphics::TFont* FMarlettFont10;
	Vcl::Graphics::TFont* FMarlettFont8;
	int FPixelsPerInch;
	int FRenderingPageIndex;
	TdxPSRenderStages FRenderStage;
	TBasedxReportLink* FReportLink;
	Vcl::Graphics::TFont* FSymbolFont;
	int FUnitsPerPixel;
	System::Types::TRect FViewPortRect;
	int FZoomFactor;
	TdxPSCellBorderPainter* __fastcall GetBorderPainterItem(int Index);
	int __fastcall GetBorderPainterCount(void);
	TdxPSReportGroupLookAndFeelPainter* __fastcall GetGroupLookAndFeelPainter(int Index);
	int __fastcall GetGroupLookAndFeelPainterCount(void);
	int __fastcall GetHalfLineThickness(void);
	bool __fastcall GetIsCompositionPagePart(void);
	bool __fastcall GetIsPrinting(void);
	TdxPSPageRenderInfo* __fastcall GetPageRenderInfo(void);
	TdxPSReportRenderInfo* __fastcall GetRenderInfo(void);
	TdxReportCells* __fastcall GetReportCells(void);
	
protected:
	bool __fastcall CustomDrawReportItem(TAbstractdxReportCellData* AItem);
	void __fastcall Get3DBorderBrushes(TdxReportVisualItem* AnItem, HBRUSH &AOuterTLBrush, HBRUSH &AOuterBRBrush, HBRUSH &AInnerTLBrush, HBRUSH &AInnerBRBrush);
	void __fastcall Get3DBorderColors(TdxReportVisualItem* AnItem, System::Uitypes::TColor &AOuterTLColor, System::Uitypes::TColor &AOuterBRColor, System::Uitypes::TColor &AInnerTLColor, System::Uitypes::TColor &AInnerBRColor);
	virtual int __fastcall GetUnitsPerInch(void);
	virtual int __fastcall GetUnitsPerInchEx(bool AAdjustOnReportScale);
	TdxPSCellBorderPainter* __fastcall CreateBorderPainter(TdxPSCellBorderPainterClass AClass);
	TdxPSCellBorderPainter* __fastcall FindBorderPainter(TdxPSCellBorderPainterClass AClass);
	void __fastcall FreeAndNilBorderPainters(void);
	TdxPSReportGroupLookAndFeelPainter* __fastcall CreateReportGroupLookAndFeelPainter(TdxPSReportGroupLookAndFeelPainterClass AClass);
	TdxPSReportGroupLookAndFeelPainter* __fastcall FindReportGroupLookAndFeelPainter(TdxPSReportGroupLookAndFeelPainterClass AClass);
	void __fastcall FreeAndNilReportGroupLookAndFeelPainters(void);
	virtual void __fastcall PrepareFont(Vcl::Graphics::TFont* AFont, bool AAdjustOnScale);
	void __fastcall PrepareFonts(void);
	virtual void __fastcall PrepareGDIObjects(void);
	virtual void __fastcall PrepareLogicalCoordinates(void);
	virtual void __fastcall PrepareLogicalUnits(void);
	int __fastcall PreparedPageIndex(int APageIndex);
	virtual void __fastcall PrepareRenderPage(void);
	void __fastcall RenderCell(TdxReportCell* ACell, const System::Types::TRect &OriginRect);
	void __fastcall RenderDelimiters(void);
	virtual void __fastcall RenderEntirePage(int ARealPageIndex);
	virtual void __fastcall RenderPageContent(void);
	void __fastcall RenderPageContentPart(TdxReportCell* ACell, int StartIndex, int EndIndex, const System::Types::TRect &OriginRect);
	virtual void __fastcall RenderPageOverlay(int AOverlayIndex, TdxPageOverlayIndexes* AOverlay, const System::Types::TRect &OriginRect);
	virtual void __fastcall RenderPageBackground(int ARealPageIndex);
	virtual void __fastcall RenderPageFooter(int ARealPageIndex);
	virtual void __fastcall RenderPageHeader(int ARealPageIndex);
	virtual void __fastcall RenderPageHeaderOrFooter(Dxprnpg::TCustomdxPageObject* AHeaderOfFooter, int APageIndex, System::Types::TRect &ARect);
	virtual void __fastcall RenderPageHeaderOrFooterContent(Dxprnpg::TCustomdxPageObject* HF, int APageIndex, System::Types::TRect &ARect, Dxprnpg::TdxPageTitleParts ATitleParts, bool ADrawBackground);
	void __fastcall RenderPageHeaderOrFooterContentPart(Dxprnpg::TdxPageTitlePart ATitlePart, System::Classes::TStrings* AStrings, Cxdrawtextutils::TcxTextAlignY ATextAlignY, int ALineHeight, int ADestWidth, int ADestHeight, const System::Types::TRect &ARect);
	virtual void __fastcall RenderPageReportArea(int ARealPageIndex);
	virtual void __fastcall RestoreMapMode(void);
	virtual void __fastcall SaveMapMode(void);
	virtual void __fastcall UnprepareGDIObjects(void);
	virtual void __fastcall UnprepareLogicalUnits(void);
	virtual void __fastcall UnprepareRenderPage(void);
	__property int BorderPainterCount = {read=GetBorderPainterCount, nodefault};
	__property TdxPSCellBorderPainter* BorderPainters[int Index] = {read=GetBorderPainterItem};
	__property TdxPSReportBrushPool* BrushPool = {read=FBrushPool};
	__property TdxPSCachedGraphicInfo* CachedGraphicInfo = {read=FCachedGraphicInfo};
	__property int GroupLookAndFeelPainterCount = {read=GetGroupLookAndFeelPainterCount, nodefault};
	__property TdxPSReportGroupLookAndFeelPainter* GroupLookAndFeelPainters[int Index] = {read=GetGroupLookAndFeelPainter};
	
public:
	__fastcall virtual TdxPSReportRenderer(TBasedxReportLink* AReportLink);
	__fastcall virtual ~TdxPSReportRenderer(void);
	int __fastcall CalcTextHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::UnicodeString AText, bool AWordBreak, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), int ABaseWidth = 0xffffffff);
	int __fastcall CalcTextLineCount(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), int ABaseWidth = 0xffffffff);
	int __fastcall CalcTextPatternHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0));
	int __fastcall CalcTextRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::UnicodeString AText, System::Types::TRect &ARect, bool AWordBreak, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0))/* overload */;
	int __fastcall CalcTextRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::UnicodeString AText, System::Types::TRect &ARect, unsigned AFormat, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0))/* overload */;
	int __fastcall CalcTextWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0));
	virtual void __fastcall DrawCheckBox(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, bool AChecked, bool AEnabled, bool AIsRadio, Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle AEdgeStyle, System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0xff000008));
	virtual void __fastcall DrawEdge(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, TdxCellEdgeMode AEdgeMode, TdxCellEdgeStyle AEdge3DEdge, TdxCellSides ASides, bool ASoft, System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0xffffffff));
	virtual void __fastcall DrawEllipse(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, System::Uitypes::TColor ABorderColor, int ABorderThickness = 0x1);
	virtual void __fastcall DrawExpandButton(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, bool AExpanded, bool ADrawBorder, bool AEdge3D, bool AEdge3DSoft, bool AShadow, bool AFillInterior, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor AInteriorColor);
	void __fastcall DrawGlyph(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, System::Byte AGlyph);
	virtual void __fastcall DrawGraphic(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, const System::Types::TRect &AClipRect, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, Vcl::Graphics::TGraphic* AGraphic, bool AGraphicTransparent, bool ATransparent, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawGraphicEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, const System::Types::TRect &AClipRect, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, Vcl::Graphics::TGraphic* AGraphic, bool AGraphicTransparent, bool ATransparent, System::Uitypes::TColor AColor, System::Uitypes::TColor ABkColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, TdxCellImageBuffering AActualImageBuffering = (TdxCellImageBuffering)(0x2));
	virtual void __fastcall DrawRectangle(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor, Dxpsfillpatterns::TdxPSFillPatternClass AContentPattern, System::Uitypes::TColor ABorderColor, int ABorderThickness = 0x1);
	virtual void __fastcall DrawRoundRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor, Dxpsfillpatterns::TdxPSFillPatternClass AContentPattern, System::Uitypes::TColor ABorderColor, int ABorderThickness = 0x1);
	virtual void __fastcall DrawSortMark(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, TdxCellSortOrder ASortOrder, bool AMono);
	void __fastcall DrawText(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, int AMaxLineCount, int ALeftIndent, int ARightIndent, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ABkColor, Cxdrawtextutils::TcxTextAlignX ATextAlignX, Cxdrawtextutils::TcxTextAlignY ATextAlignY, bool AFillBackground, bool AMultiline, bool AEndEllipsis, bool APreventLeftTextExceed = true, bool APreventTopTextExceed = true, bool AHidePrefix = true);
	void __fastcall DrawTextEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, int AMaxLineCount, int ALeftIndent, int ARightIndent, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, unsigned AFormat)/* overload */;
	void __fastcall DrawTextEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, int AMaxLineCount, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, unsigned AFormat, const System::Types::TRect &AIndents)/* overload */;
	unsigned __fastcall MakeTextFormat(Cxdrawtextutils::TcxTextAlignX ATextAlignX, Cxdrawtextutils::TcxTextAlignY ATextAlignY, bool AMultiline, bool AEndEllipsis, bool APreventLeftTextExceed, bool APreventTopTextExceed, bool AHidePrefix);
	virtual void __fastcall FillEllipse(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall FillEllipseEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern);
	virtual void __fastcall FillRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall FillRectByBrush(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, Vcl::Graphics::TBrush* ABrush);
	virtual void __fastcall FillRectEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern);
	virtual void __fastcall FillRoundRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor AColor);
	virtual void __fastcall FillRoundRectEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern);
	virtual void __fastcall FillRgn(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, HRGN Rgn, System::Uitypes::TColor AColor);
	virtual void __fastcall FillRgnEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, HRGN Rgn, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern);
	void __fastcall FrameEllipse(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, System::Uitypes::TColor AColor, int AThickness = 0x1);
	virtual void __fastcall FrameRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, System::Uitypes::TColor AColor, TdxCellSides ASides = (TdxCellSides() << TdxCellSide::csLeft << TdxCellSide::csTop << TdxCellSide::csRight << TdxCellSide::csBottom ), int AThickness = 0x1);
	virtual void __fastcall FrameRoundRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor AColor, int AThickness = 0x1);
	virtual void __fastcall Polyline(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor AColor, int AThickness = 0x1);
	virtual void __fastcall Polygone(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor ABkColor, System::Uitypes::TColor AFrameColor, int AThickness = 0x1);
	TdxPSCellBorderPainter* __fastcall GetBorderPainter(TdxPSCellBorderPainterClass AClass);
	HBRUSH __fastcall GetBrushByColor(System::Uitypes::TColor AColor);
	Vcl::Graphics::TBrush* __fastcall GetPatternBrush(Dxpsfillpatterns::TdxPSFillPatternClass APattern, System::Uitypes::TColor AColor);
	TdxPSReportGroupLookAndFeelPainter* __fastcall GetReportGroupLookAndFeelPainter(TdxPSReportGroupLookAndFeelPainterClass AClass);
	virtual void __fastcall RenderPage(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &APageBounds, int APageIndex, int AContinuousPageIndex, int AZoomFactor);
	virtual void __fastcall RenderPageEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &APageBounds, int APageIndex, int AContinuousPageIndex, int AZoomFactor);
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, nodefault};
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* Canvas = {read=FCanvas};
	__property int HalfLineThickness = {read=GetHalfLineThickness, nodefault};
	__property bool IsCompositionPagePart = {read=GetIsCompositionPagePart, nodefault};
	__property bool IsPrinting = {read=GetIsPrinting, nodefault};
	__property bool IsRendering = {read=FIsRendering, nodefault};
	__property int LineThickness = {read=FLineThickness, write=FLineThickness, nodefault};
	__property Vcl::Graphics::TFont* MarlettFont10 = {read=FMarlettFont10};
	__property Vcl::Graphics::TFont* MarlettFont8 = {read=FMarlettFont8};
	__property TdxPSPageRenderInfo* PageRenderInfo = {read=GetPageRenderInfo};
	__property int PixelsPerInch = {read=FPixelsPerInch, write=FPixelsPerInch, nodefault};
	__property TdxPSReportRenderInfo* RenderInfo = {read=GetRenderInfo};
	__property int RenderingPageIndex = {read=FRenderingPageIndex, nodefault};
	__property TdxPSRenderStages RenderStage = {read=FRenderStage, nodefault};
	__property TdxReportCells* ReportCells = {read=GetReportCells};
	__property TBasedxReportLink* ReportLink = {read=FReportLink};
	__property Vcl::Graphics::TFont* SymbolFont = {read=FSymbolFont};
	__property int UnitsPerInch = {read=GetUnitsPerInch, nodefault};
	__property int UnitsPerPixel = {read=FUnitsPerPixel, write=FUnitsPerPixel, nodefault};
	__property System::Types::TRect ViewPortRect = {read=FViewPortRect};
	__property int ZoomFactor = {read=FZoomFactor, nodefault};
};


class DELPHICLASS TdxPSCustomReportExportProvider;
class PASCALIMPLEMENTATION TdxPSCustomReportExportProvider : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TBasedxReportLink* FReportLink;
	TdxPSReportRenderer* __fastcall GetRenderer(void);
	TdxPSReportRenderInfo* __fastcall GetRenderInfo(void);
	
public:
	__fastcall virtual TdxPSCustomReportExportProvider(TBasedxReportLink* AReportLink);
	virtual void __fastcall Build(void) = 0 ;
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream) = 0 ;
	__property TdxPSReportRenderer* Renderer = {read=GetRenderer};
	__property TdxPSReportRenderInfo* RenderInfo = {read=GetRenderInfo};
	__property TBasedxReportLink* ReportLink = {read=FReportLink};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomReportExportProvider(void) { }
	
};


class DELPHICLASS TdxPSPDFReportExportOptions;
class DELPHICLASS TdxPSPrintPageRangeInfo;
class PASCALIMPLEMENTATION TdxPSPDFReportExportOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FAuthor;
	bool FCompressStreams;
	System::UnicodeString FCreator;
	System::UnicodeString FDefaultFileName;
	bool FDefaultFileNameAssigned;
	bool FEmbedFonts;
	bool FIsCreatorAssigned;
	bool FIsTitleAssigned;
	int FJPEGQuality;
	System::UnicodeString FKeywords;
	bool FOpenDocumentAfterExport;
	TdxPSPrintPageRangeInfo* FPageRangeInfo;
	Dxpspdfexportcore::TdxPSPDFSecurityOptions* FSecurityOptions;
	System::UnicodeString FSubject;
	System::UnicodeString FTitle;
	bool FUseCIDFonts;
	bool FUseJPEGCompression;
	System::UnicodeString __fastcall GenerateDefaultFileName(void);
	System::UnicodeString __fastcall GetCreator(void);
	System::UnicodeString __fastcall GetDefaultCreator(void);
	System::UnicodeString __fastcall GetDefaultFileName(void);
	bool __fastcall GetDefaultFileNameIsStored(void);
	System::UnicodeString __fastcall GetDefaultTitle(void);
	bool __fastcall GetIsCreatorStored(void);
	bool __fastcall GetIsTitleStored(void);
	System::UnicodeString __fastcall GetTitle(void);
	void __fastcall SetCreator(const System::UnicodeString AValue);
	void __fastcall SetDefaultFileName(const System::UnicodeString AValue);
	void __fastcall SetSecurityOptions(Dxpspdfexportcore::TdxPSPDFSecurityOptions* AValue);
	void __fastcall SetTitle(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall LoadDefaultSettings(void);
	void __fastcall SaveDefaultSettings(void);
	void __fastcall ReadIsCreatorAssigned(System::Classes::TReader* Reader);
	void __fastcall ReadIsTitleAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteIsCreatorAssigned(System::Classes::TWriter* Writer);
	void __fastcall WriteIsTitleAssigned(System::Classes::TWriter* Writer);
	
public:
	__fastcall virtual TdxPSPDFReportExportOptions(void);
	__fastcall virtual ~TdxPSPDFReportExportOptions(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName)/* overload */;
	void __fastcall LoadFromIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall LoadFromRegistry(const System::UnicodeString APath);
	void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName)/* overload */;
	void __fastcall SaveToIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall SaveToRegistry(const System::UnicodeString APath);
	__property TdxPSPrintPageRangeInfo* PageRangeInfo = {read=FPageRangeInfo};
	
__published:
	__property System::UnicodeString Author = {read=FAuthor, write=FAuthor};
	__property System::UnicodeString Creator = {read=GetCreator, write=SetCreator, stored=GetIsCreatorStored};
	__property System::UnicodeString Keywords = {read=FKeywords, write=FKeywords};
	__property System::UnicodeString Subject = {read=FSubject, write=FSubject};
	__property System::UnicodeString Title = {read=GetTitle, write=SetTitle, stored=GetIsTitleStored};
	__property bool CompressStreams = {read=FCompressStreams, write=FCompressStreams, default=0};
	__property System::UnicodeString DefaultFileName = {read=GetDefaultFileName, write=SetDefaultFileName, stored=GetDefaultFileNameIsStored};
	__property bool DefaultFileNameAssigned = {read=FDefaultFileNameAssigned, write=FDefaultFileNameAssigned, default=0};
	__property bool EmbedFonts = {read=FEmbedFonts, write=FEmbedFonts, default=1};
	__property int JPEGQuality = {read=FJPEGQuality, write=FJPEGQuality, default=90};
	__property bool OpenDocumentAfterExport = {read=FOpenDocumentAfterExport, write=FOpenDocumentAfterExport, default=0};
	__property Dxpspdfexportcore::TdxPSPDFSecurityOptions* SecurityOptions = {read=FSecurityOptions, write=SetSecurityOptions};
	__property bool UseCIDFonts = {read=FUseCIDFonts, write=FUseCIDFonts, default=1};
	__property bool UseJPEGCompression = {read=FUseJPEGCompression, write=FUseJPEGCompression, default=1};
};


typedef System::TMetaClass* TdxReportItemClass;

class DELPHICLASS TdxReportItem;
class PASCALIMPLEMENTATION TdxReportItem : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Cxclasses::TcxObjectLink* FCreatorLink;
	__int64 FData;
	TdxReportCell* FParent;
	void __fastcall FreeCreatorLink(void);
	TBasedxReportLink* __fastcall GetCreator(void);
	int __fastcall GetIndex(void);
	virtual TdxReportCells* __fastcall GetReportCells(void);
	TBasedxReportLink* __fastcall GetReportLink(void);
	void __fastcall SetCreator(TBasedxReportLink* AValue);
	void __fastcall SetIndex(int Value);
	void __fastcall SetParent(TdxReportCell* Value);
	
protected:
	TdxReportCell* __fastcall AsCell(void);
	TdxReportCell* __fastcall GetTopLevelParent(void);
	__classmethod virtual bool __fastcall IsCell();
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__classmethod virtual bool __fastcall Serializable();
	
public:
	__fastcall virtual TdxReportItem(TdxReportCell* AParent);
	__fastcall virtual ~TdxReportItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod TdxReportItemClass __fastcall ReportItemClass();
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	TdxReportItem* __fastcall Clone(TdxReportCell* AParent);
	TdxReportItem* __fastcall getNextSibling(void);
	TdxReportItem* __fastcall getPrevSibling(void);
	bool __fastcall HasParent(void);
	bool __fastcall IsFirstItem(void);
	bool __fastcall IsLastItem(void);
	__property TBasedxReportLink* Creator = {read=GetCreator};
	__property __int64 Data = {read=FData, write=FData};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property TdxReportCell* Parent = {read=FParent, write=SetParent};
	__property TdxReportCells* ReportCells = {read=GetReportCells};
	__property TBasedxReportLink* ReportLink = {read=GetReportLink};
	__property TdxReportCell* TopLevelParent = {read=GetTopLevelParent};
};


class PASCALIMPLEMENTATION TdxReportVisualItem : public TdxReportItem
{
	typedef TdxReportItem inherited;
	
private:
	int FBackgroundBitmapIndex;
	TdxPSCellBorderClass FBorderClass;
	System::Uitypes::TColor FBorderColor;
	System::Types::TRect FBoundsRect;
	System::StaticArray<System::Uitypes::TColor, 4> FCellSideColors;
	System::Uitypes::TColor FColor;
	int FFontIndex;
	unsigned FFormat;
	System::Types::TPoint __fastcall GetAbsoluteOrigin(void);
	System::Types::TRect __fastcall GetAbsoluteRect(void);
	Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	int __fastcall GetBackgroundBitmapHeight(void);
	TdxPSBackgroundBitmapPool* __fastcall GetBackgroundBitmapPool(void);
	System::Types::TPoint __fastcall GetBackgroundBitmapTileOrigin(void);
	int __fastcall GetBackgroundBitmapTileStartIndexX(void);
	int __fastcall GetBackgroundBitmapTileStartIndexY(void);
	int __fastcall GetBackgroundBitmapTileStopIndexX(void);
	int __fastcall GetBackgroundBitmapTileStopIndexY(void);
	int __fastcall GetBackgroundBitmapWidth(void);
	HBRUSH __fastcall GetBorderBrush(void);
	System::Uitypes::TColor __fastcall GetBorderColor(void);
	TdxCellSides __fastcall GetCellSides(void);
	System::Uitypes::TColor __fastcall GetCellSideColors(TdxCellSide ASide);
	HBRUSH __fastcall GetContentBrush(void);
	bool __fastcall GetEdge3DSoft(void);
	TdxCellEdgeStyle __fastcall GetEdge3DStyle(void);
	TdxCellEdgeMode __fastcall GetEdgeMode(void);
	bool __fastcall GetExcludeFromClipRgn(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	int __fastcall GetHeight(void);
	bool __fastcall GetIsPrinting(void);
	int __fastcall GetLeft(void);
	int __fastcall GetLineThickness(void);
	System::Types::TPoint __fastcall GetOrigin(void);
	HBRUSH __fastcall GetParentBrush(void);
	System::Uitypes::TColor __fastcall GetParentColor(void);
	TdxPSReportRenderer* __fastcall GetRenderer(void);
	HBRUSH __fastcall GetShadowBrush(void);
	bool __fastcall GetShowShadow(void);
	int __fastcall GetTop(void);
	bool __fastcall GetTransparent(void);
	int __fastcall GetWidth(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetBackgroundBitmapIndex(int Value);
	void __fastcall SetBorderClass(TdxPSCellBorderClass Value);
	void __fastcall SetBoundsRect(const System::Types::TRect &Value);
	void __fastcall SetCellSides(TdxCellSides Value);
	void __fastcall SetCellSideColors(TdxCellSide ASide, System::Uitypes::TColor AValue);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetEdge3DSoft(bool Value);
	void __fastcall SetEdge3DStyle(TdxCellEdgeStyle Value);
	void __fastcall SetEdgeMode(TdxCellEdgeMode Value);
	void __fastcall SetExcludeFromClipRgn(bool Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetFormat(unsigned Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetOrigin(const System::Types::TPoint Value);
	void __fastcall SetShowShadow(bool Value);
	void __fastcall SetTop(int Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetWidth(int Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	virtual void __fastcall BoundsChanged(void);
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	void __fastcall DoExcludeFromClipRgn(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, int &AResult);
	virtual System::Types::TRect __fastcall GetBackgroundBitmapTileBounds(int Col, int Row);
	virtual System::Types::TRect __fastcall GetBackgroundBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual TdxPSCellBorderClass __fastcall GetBorderClass(void);
	virtual System::Types::TRect __fastcall GetBorderEdgeBounds(TdxCellSide ASide, const System::Types::TRect &AOuterRect);
	virtual TdxPSCellBorderClass __fastcall GetBorderEdgeClass(TdxCellSide ASide);
	virtual int __fastcall GetBorderEdgeSalient(TdxCellSide ASide, TdxPSCellBorderSalientType ASalient);
	virtual int __fastcall GetBorderEdgeThickness(TdxCellSide ASide);
	virtual System::Types::TRect __fastcall GetBorderBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	System::Types::TRect __fastcall GetBorderOuterBoundsRelativeTo(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	System::Types::TRect __fastcall GetInnerBoundsRelativeTo(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	System::Types::TRect __fastcall GetOuterBoundsRelativeTo(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	TdxPSCellBorderPainter* __fastcall GetBorderPainter(void);
	virtual TdxPSCellBorderPainterClass __fastcall GetBorderPainterClass(void);
	virtual void __fastcall InitBorderPainter(TdxPSCellBorderPainter* ABorderPainter);
	virtual bool __fastcall HasBorderColoration(void);
	bool __fastcall GetFormatBit(unsigned ABit);
	void __fastcall SetFormatBit(unsigned ABit, bool Value);
	virtual System::Uitypes::TColor __fastcall GetContentBkColor(void);
	virtual Dxpsfillpatterns::TdxPSFillPatternClass __fastcall GetContentPattern(void);
	virtual System::Uitypes::TColor __fastcall GetShadowColor(void);
	virtual int __fastcall GetShadowDepth(void);
	virtual void __fastcall SetContentBkColor(System::Uitypes::TColor Value);
	virtual void __fastcall SetContentPattern(Dxpsfillpatterns::TdxPSFillPatternClass Value);
	virtual void __fastcall SetFontIndex(int Value);
	virtual void __fastcall SetShadowColor(System::Uitypes::TColor Value);
	virtual void __fastcall SetShadowDepth(int Value);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall IsBackgroundBitmapDrawn(void);
	virtual bool __fastcall IsBackgroundDrawn(void);
	virtual bool __fastcall IsBordersDrawn(void);
	virtual bool __fastcall IsShadowDrawn(void);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property int BackgroundBitmapHeight = {read=GetBackgroundBitmapHeight, nodefault};
	__property System::Types::TRect BackgroundBitmapTileBounds[int Col][int Row] = {read=GetBackgroundBitmapTileBounds};
	__property System::Types::TPoint BackgroundBitmapTileOrigin = {read=GetBackgroundBitmapTileOrigin};
	__property int BackgroundBitmapTileStartIndexX = {read=GetBackgroundBitmapTileStartIndexX, nodefault};
	__property int BackgroundBitmapTileStartIndexY = {read=GetBackgroundBitmapTileStartIndexY, nodefault};
	__property int BackgroundBitmapTileStopIndexX = {read=GetBackgroundBitmapTileStopIndexX, nodefault};
	__property int BackgroundBitmapTileStopIndexY = {read=GetBackgroundBitmapTileStopIndexY, nodefault};
	__property int BackgroundBitmapWidth = {read=GetBackgroundBitmapWidth, nodefault};
	__property unsigned Format = {read=FFormat, write=SetFormat, nodefault};
	__property bool IsPrinting = {read=GetIsPrinting, nodefault};
	__property int LineThickness = {read=GetLineThickness, nodefault};
	__property TdxPSReportRenderer* Renderer = {read=GetRenderer};
	
public:
	__fastcall virtual TdxReportVisualItem(TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AdjustContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawBackground(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas)/* overload */;
	virtual void __fastcall DrawBackground(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R)/* overload */;
	virtual void __fastcall DrawBackgroundBitmap(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawBackgroundBitmapTile(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &Rect);
	void __fastcall DrawBackgroundRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetBorderOuterBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetInnerBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetOuterBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual int __fastcall CalculateLineCount(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureBordersHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureBordersWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureFontHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall Offset(int AOffsetX, int AOffsetY);
	__classmethod TdxPSCellBorderClass __fastcall MapBorderClass(TdxCellEdgeMode AEdgeMode, TdxCellEdgeStyle AEdgeStyle, bool ASoft);
	__property System::Types::TPoint AbsoluteOrigin = {read=GetAbsoluteOrigin};
	__property System::Types::TRect AbsoluteRect = {read=GetAbsoluteRect};
	__property Vcl::Graphics::TBitmap* BackgroundBitmap = {read=GetBackgroundBitmap};
	__property int BackgroundBitmapIndex = {read=FBackgroundBitmapIndex, write=SetBackgroundBitmapIndex, nodefault};
	__property TdxPSBackgroundBitmapPool* BackgroundBitmapPool = {read=GetBackgroundBitmapPool};
	__property HBRUSH BorderBrush = {read=GetBorderBrush};
	__property TdxPSCellBorderClass BorderClass = {read=GetBorderClass, write=SetBorderClass};
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, write=FBorderColor, nodefault};
	__property TdxPSCellBorderClass BorderEdgeClasses[TdxCellSide Side] = {read=GetBorderEdgeClass};
	__property int BorderEdgeSalients[TdxCellSide Side][TdxPSCellBorderSalientType Salient] = {read=GetBorderEdgeSalient};
	__property int BorderEdgeThicknesses[TdxCellSide Side] = {read=GetBorderEdgeThickness};
	__property TdxPSCellBorderPainter* BorderPainter = {read=GetBorderPainter};
	__property TdxPSCellBorderPainterClass BorderPainterClass = {read=GetBorderPainterClass};
	__property System::Types::TRect BoundsRect = {read=FBoundsRect, write=SetBoundsRect};
	__property TdxCellSides CellSides = {read=GetCellSides, write=SetCellSides, nodefault};
	__property System::Uitypes::TColor CellSideColors[TdxCellSide ASide] = {read=GetCellSideColors, write=SetCellSideColors};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property System::Uitypes::TColor ContentBkColor = {read=GetContentBkColor, write=SetContentBkColor, nodefault};
	__property HBRUSH ContentBrush = {read=GetContentBrush};
	__property Dxpsfillpatterns::TdxPSFillPatternClass ContentPattern = {read=GetContentPattern, write=SetContentPattern};
	__property bool Edge3DSoft = {read=GetEdge3DSoft, write=SetEdge3DSoft, nodefault};
	__property TdxCellEdgeStyle Edge3DStyle = {read=GetEdge3DStyle, write=SetEdge3DStyle, nodefault};
	__property TdxCellEdgeMode EdgeMode = {read=GetEdgeMode, write=SetEdgeMode, nodefault};
	__property bool ExcludeFromClipRgn = {read=GetExcludeFromClipRgn, write=SetExcludeFromClipRgn, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont};
	__property int FontIndex = {read=FFontIndex, write=SetFontIndex, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property System::Types::TPoint Origin = {read=GetOrigin, write=SetOrigin};
	__property HBRUSH ParentBrush = {read=GetParentBrush};
	__property System::Uitypes::TColor ParentColor = {read=GetParentColor, nodefault};
	__property HBRUSH ShadowBrush = {read=GetShadowBrush};
	__property System::Uitypes::TColor ShadowColor = {read=GetShadowColor, write=SetShadowColor, nodefault};
	__property int ShadowDepth = {read=GetShadowDepth, write=SetShadowDepth, nodefault};
	__property bool ShowShadow = {read=GetShowShadow, write=SetShowShadow, nodefault};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportVisualItem(void) { }
	
};


class PASCALIMPLEMENTATION TdxReportCell : public TdxReportVisualItem
{
	typedef TdxReportVisualItem inherited;
	
public:
	TdxReportCell* operator[](int Index) { return Cells[Index]; }
	
private:
	Cxclasses::TcxObjectList* FCellList;
	Cxclasses::TcxObjectList* FDataList;
	TdxReportCells* FReportCells;
	int __fastcall GetAbsoluteIndex(void);
	int __fastcall GetCellCount(void);
	TdxReportCell* __fastcall GetCell(int Index);
	bool __fastcall GetClipChildren(void);
	int __fastcall GetDataItemCount(void);
	TAbstractdxReportCellData* __fastcall GetDataItem(int Index);
	bool __fastcall GetIsTopLevel(void);
	int __fastcall GetLevel(void);
	virtual TdxReportCells* __fastcall GetReportCells(void);
	void __fastcall CellListNeeded(void);
	void __fastcall CellListRelease(void);
	void __fastcall DataListNeeded(void);
	void __fastcall DataListRelease(void);
	void __fastcall InsertCell(TdxReportCell* AItem);
	void __fastcall InsertDataItem(TdxReportItem* AnItem);
	void __fastcall InsertItem(TdxReportItem* AnItem);
	void __fastcall MoveCell(int ACurIndex, int ANewIndex);
	void __fastcall MoveDataItem(int ACurIndex, int ANewIndex);
	void __fastcall MoveItem(TdxReportItem* AnItem, int ACurIndex, int ANewIndex);
	void __fastcall RemoveCell(TdxReportCell* AnItem);
	void __fastcall RemoveDataItem(TdxReportItem* AnItem);
	void __fastcall RemoveItem(TdxReportItem* AnItem);
	void __fastcall SetClipChildren(bool Value);
	
protected:
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual System::Types::TRect __fastcall GetBackgroundBitmapTileBounds(int Col, int Row);
	virtual System::Types::TRect __fastcall GetBackgroundBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetBorderBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__classmethod virtual bool __fastcall IsCell();
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	virtual void __fastcall ReadCells(TdxPSDataReader* AReader);
	virtual void __fastcall ReadDataItems(TdxPSDataReader* AReader);
	virtual void __fastcall ReadProperties(TdxPSDataReader* AReader);
	virtual void __fastcall WriteCells(TdxPSDataWriter* AWriter);
	virtual void __fastcall WriteDataItems(TdxPSDataWriter* AWriter);
	virtual void __fastcall WriteProperties(TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual ~TdxReportCell(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &DrawRect, const System::Types::TRect &OriginRect, TdxPSRenderStages AStage);
	virtual void __fastcall DrawItself(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage);
	virtual void __fastcall DrawNestedCells(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &DrawRect, const System::Types::TRect &OriginRect, TdxPSRenderStages AStage);
	virtual void __fastcall DrawNestedDataItems(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &OriginRect, TdxPSRenderStages AStage);
	virtual int __fastcall ExcludeNestedItems(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &OriginRect);
	virtual System::Types::TRect __fastcall GetBorderOuterBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetInnerBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetOuterBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall Offset(int AOffsetX, int AOffsetY);
	TdxReportCell* __fastcall AddCell(void);
	TAbstractdxReportCellData* __fastcall AddDataItem(TdxReportCellDataClass AClass);
	void __fastcall AllocateSpaceForCells(int ACapacity);
	void __fastcall AllocateSpaceForDatas(int ACapacity);
	void __fastcall ClearAll(void);
	void __fastcall ClearCells(void);
	void __fastcall ClearDataItems(void);
	void __fastcall DeleteCell(int Index);
	void __fastcall DeleteDataItem(int Index);
	TdxReportCell* __fastcall FirstCell(void);
	bool __fastcall FindDataItemByData(const __int64 AData, TAbstractdxReportCellData* &ADataItem);
	bool __fastcall HasChildren(void);
	int __fastcall IndexOf(TdxReportItem* AnItem);
	TdxReportCell* __fastcall LastCell(void);
	__property int AbsoluteIndex = {read=GetAbsoluteIndex, nodefault};
	__property int CellCount = {read=GetCellCount, nodefault};
	__property TdxReportCell* Cells[int Index] = {read=GetCell/*, default*/};
	__property bool ClipChildren = {read=GetClipChildren, write=SetClipChildren, nodefault};
	__property int DataItemCount = {read=GetDataItemCount, nodefault};
	__property TAbstractdxReportCellData* DataItems[int Index] = {read=GetDataItem};
	__property bool IsTopLevel = {read=GetIsTopLevel, nodefault};
	__property int Level = {read=GetLevel, nodefault};
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportCell(TdxReportCell* AParent) : TdxReportVisualItem(AParent) { }
	
};


class DELPHICLASS TdxReportGroup;
class DELPHICLASS TdxPSReportGroupLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportGroupLookAndFeelPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxReportGroup* FGroup;
	TdxPSReportGroupLookAndFeel* FLookAndFeel;
	TdxPSReportRenderer* FRenderer;
	
protected:
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawCaption(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawCaptionText(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawCheckBox(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall Initialize(TdxPSReportGroupLookAndFeel* ALookAndFeel, TdxReportGroup* AGroup);
	virtual TdxReportGroup* __fastcall Group(void)/* overload */;
	virtual TdxPSReportGroupLookAndFeel* __fastcall LookAndFeel(void)/* overload */;
	
public:
	__fastcall virtual TdxPSReportGroupLookAndFeelPainter(TdxPSReportRenderer* ARenderer);
	virtual void __fastcall Paint(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property TdxPSReportRenderer* Renderer = {read=FRenderer};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSReportGroupLookAndFeelPainter(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSReportGroupLookAndFeel : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FCaptionHeight;
	int FCaptionFontIndex;
	int FCaptionIndent;
	System::Uitypes::TColor FColor;
	void *FData;
	int FFontIndex;
	TdxReportCells* FReportCells;
	Vcl::Graphics::TFont* __fastcall GetCaptionFont(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	TdxPSReportRenderer* __fastcall GetRenderer(void);
	void __fastcall SetCaptionFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetCaptionFontIndex(int Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetFontIndex(int Value);
	
protected:
	virtual void __fastcall AdjustBorderOuterBounds(System::Types::TRect &R, TdxReportGroup* AGroup);
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	virtual int __fastcall GetBorderEdgeThickness(TdxReportGroup* AGroup, TdxCellSide ASide);
	virtual TdxCellSides __fastcall GetBorderSides(TdxReportGroup* AGroup);
	virtual int __fastcall GetBorderThickness(void);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	virtual void __fastcall SetBorderThickness(int Value);
	virtual int __fastcall GetCaptionAreaHeight(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionBounds(TdxReportGroup* AGroup);
	virtual System::Uitypes::TColor __fastcall GetCaptionColor(void);
	virtual int __fastcall GetCaptionHeight(TdxReportGroup* AGroup);
	virtual int __fastcall GetCaptionIndent(void);
	virtual System::Types::TRect __fastcall GetCaptionLeftRestSpaceBounds(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionRightRestSpaceBounds(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionTextBounds(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCheckBounds(TdxReportGroup* AGroup);
	int __fastcall GetCheckWidth(void);
	TdxPSReportGroupLookAndFeelPainter* __fastcall GetPainter(void);
	__classmethod virtual TdxPSReportGroupLookAndFeelPainterClass __fastcall GetPainterClass();
	__property int BorderThickness = {read=GetBorderThickness, write=SetBorderThickness, nodefault};
	__property System::Uitypes::TColor CaptionColor = {read=GetCaptionColor, nodefault};
	__property int CaptionIndent = {read=GetCaptionIndent, nodefault};
	__property TdxPSReportRenderer* Renderer = {read=GetRenderer};
	__property TdxReportCells* ReportCells = {read=FReportCells};
	
public:
	__fastcall virtual TdxPSReportGroupLookAndFeel(TdxReportCells* AReportCells);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual TdxPSCellBorderClass __fastcall BorderClass();
	__classmethod virtual TdxCellSides __fastcall DefaultBorderSides();
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	void __fastcall Paint(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxReportGroup* AGroup);
	virtual void __fastcall Prepare(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property Vcl::Graphics::TFont* CaptionFont = {read=GetCaptionFont, write=SetCaptionFont};
	__property int CaptionFontIndex = {read=FCaptionFontIndex, write=SetCaptionFontIndex, nodefault};
	__property System::Uitypes::TColor Color = {read=GetColor, write=FColor, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont};
	__property int FontIndex = {read=FFontIndex, write=SetFontIndex, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportGroupLookAndFeel(void) { }
	
};


class DELPHICLASS TdxPSReportGroupNullLookAndFeelPainter;
class PASCALIMPLEMENTATION TdxPSReportGroupNullLookAndFeelPainter : public TdxPSReportGroupLookAndFeelPainter
{
	typedef TdxPSReportGroupLookAndFeelPainter inherited;
	
public:
	virtual void __fastcall Paint(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
public:
	/* TdxPSReportGroupLookAndFeelPainter.Create */ inline __fastcall virtual TdxPSReportGroupNullLookAndFeelPainter(TdxPSReportRenderer* ARenderer) : TdxPSReportGroupLookAndFeelPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSReportGroupNullLookAndFeelPainter(void) { }
	
};


class DELPHICLASS TdxPSReportGroupNullLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportGroupNullLookAndFeel : public TdxPSReportGroupLookAndFeel
{
	typedef TdxPSReportGroupLookAndFeel inherited;
	
protected:
	virtual int __fastcall GetBorderThickness(void);
	virtual int __fastcall GetCaptionHeight(TdxReportGroup* AGroup);
	__classmethod virtual TdxPSReportGroupLookAndFeelPainterClass __fastcall GetPainterClass();
	
public:
	__classmethod virtual TdxPSCellBorderClass __fastcall BorderClass();
	__classmethod virtual TdxCellSides __fastcall DefaultBorderSides();
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TdxPSReportGroupLookAndFeel.Create */ inline __fastcall virtual TdxPSReportGroupNullLookAndFeel(TdxReportCells* AReportCells) : TdxPSReportGroupLookAndFeel(AReportCells) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportGroupNullLookAndFeel(void) { }
	
};


class DELPHICLASS TdxPSReportGroupStandardLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportGroupStandardLookAndFeel : public TdxPSReportGroupLookAndFeel
{
	typedef TdxPSReportGroupLookAndFeel inherited;
	
protected:
	__classmethod virtual TdxPSReportGroupLookAndFeelPainterClass __fastcall GetPainterClass();
	
public:
	__classmethod virtual TdxPSCellBorderClass __fastcall BorderClass();
	__classmethod virtual System::UnicodeString __fastcall Name();
	__property CaptionFont;
	__property CaptionFontIndex;
public:
	/* TdxPSReportGroupLookAndFeel.Create */ inline __fastcall virtual TdxPSReportGroupStandardLookAndFeel(TdxReportCells* AReportCells) : TdxPSReportGroupLookAndFeel(AReportCells) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportGroupStandardLookAndFeel(void) { }
	
};


class DELPHICLASS TdxPSReportGroupStandardLookAndFeelPainter;
class PASCALIMPLEMENTATION TdxPSReportGroupStandardLookAndFeelPainter : public TdxPSReportGroupLookAndFeelPainter
{
	typedef TdxPSReportGroupLookAndFeelPainter inherited;
	
protected:
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawCaptionRestSpace(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	HIDESBASE TdxPSReportGroupStandardLookAndFeel* __fastcall LookAndFeel(void)/* overload */;
	
public:
	virtual void __fastcall Paint(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
public:
	/* TdxPSReportGroupLookAndFeelPainter.Create */ inline __fastcall virtual TdxPSReportGroupStandardLookAndFeelPainter(TdxPSReportRenderer* ARenderer) : TdxPSReportGroupLookAndFeelPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSReportGroupStandardLookAndFeelPainter(void) { }
	
};


class DELPHICLASS TdxPSReportGroupPanelStyleLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportGroupPanelStyleLookAndFeel : public TdxPSReportGroupStandardLookAndFeel
{
	typedef TdxPSReportGroupStandardLookAndFeel inherited;
	
protected:
	virtual void __fastcall AdjustBorderOuterBounds(System::Types::TRect &R, TdxReportGroup* AGroup);
	__classmethod virtual TdxPSReportGroupLookAndFeelPainterClass __fastcall GetPainterClass();
	virtual int __fastcall GetBorderEdgeThickness(TdxReportGroup* AGroup, TdxCellSide ASide);
public:
	/* TdxPSReportGroupLookAndFeel.Create */ inline __fastcall virtual TdxPSReportGroupPanelStyleLookAndFeel(TdxReportCells* AReportCells) : TdxPSReportGroupStandardLookAndFeel(AReportCells) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportGroupPanelStyleLookAndFeel(void) { }
	
};


class DELPHICLASS TdxPSReportGroupPanelStyleLookAndFeelPainter;
class PASCALIMPLEMENTATION TdxPSReportGroupPanelStyleLookAndFeelPainter : public TdxPSReportGroupStandardLookAndFeelPainter
{
	typedef TdxPSReportGroupStandardLookAndFeelPainter inherited;
	
public:
	virtual void __fastcall Paint(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
public:
	/* TdxPSReportGroupLookAndFeelPainter.Create */ inline __fastcall virtual TdxPSReportGroupPanelStyleLookAndFeelPainter(TdxPSReportRenderer* ARenderer) : TdxPSReportGroupStandardLookAndFeelPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSReportGroupPanelStyleLookAndFeelPainter(void) { }
	
};


class DELPHICLASS TdxPSReportGroupOfficeLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportGroupOfficeLookAndFeel : public TdxPSReportGroupStandardLookAndFeel
{
	typedef TdxPSReportGroupStandardLookAndFeel inherited;
	
protected:
	virtual int __fastcall GetCaptionIndent(void);
	
public:
	__classmethod virtual TdxCellSides __fastcall DefaultBorderSides();
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TdxPSReportGroupLookAndFeel.Create */ inline __fastcall virtual TdxPSReportGroupOfficeLookAndFeel(TdxReportCells* AReportCells) : TdxPSReportGroupStandardLookAndFeel(AReportCells) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportGroupOfficeLookAndFeel(void) { }
	
};


class DELPHICLASS TdxPSReportGroupWebLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportGroupWebLookAndFeel : public TdxPSReportGroupLookAndFeel
{
	typedef TdxPSReportGroupLookAndFeel inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	int FBorderThickness;
	System::Uitypes::TColor FCaptionColor;
	System::Uitypes::TColor FCaptionSeparatorColor;
	int FCaptionSeparatorThickness;
	void __fastcall SetCaptionSeparatorThickness(int Value);
	
protected:
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	virtual int __fastcall GetBorderEdgeThickness(TdxReportGroup* AGroup, TdxCellSide ASide);
	virtual int __fastcall GetBorderThickness(void);
	virtual void __fastcall SetBorderThickness(int Value);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(void);
	virtual System::Uitypes::TColor __fastcall GetCaptionColor(void);
	virtual System::Uitypes::TColor __fastcall GetCaptionSeparatorColor(void);
	virtual int __fastcall GetCaptionAreaHeight(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionBounds(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionLeftRestSpaceBounds(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionRightRestSpaceBounds(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionSeparatorBounds(TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionTextBounds(TdxReportGroup* AGroup);
	__classmethod virtual TdxPSReportGroupLookAndFeelPainterClass __fastcall GetPainterClass();
	
public:
	__fastcall virtual TdxPSReportGroupWebLookAndFeel(TdxReportCells* AReportCells);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual TdxPSCellBorderClass __fastcall BorderClass();
	__classmethod virtual System::UnicodeString __fastcall Name();
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, write=FBorderColor, nodefault};
	__property BorderThickness;
	__property CaptionColor = {write=FCaptionColor};
	__property CaptionFont;
	__property System::Uitypes::TColor CaptionSeparatorColor = {read=GetCaptionSeparatorColor, write=FCaptionSeparatorColor, nodefault};
	__property int CaptionSeparatorThickness = {read=FCaptionSeparatorThickness, write=SetCaptionSeparatorThickness, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportGroupWebLookAndFeel(void) { }
	
};


class DELPHICLASS TdxPSReportGroupWebLookAndFeelPainter;
class PASCALIMPLEMENTATION TdxPSReportGroupWebLookAndFeelPainter : public TdxPSReportGroupLookAndFeelPainter
{
	typedef TdxPSReportGroupLookAndFeelPainter inherited;
	
protected:
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawCaptionSeparator(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	HIDESBASE TdxPSReportGroupWebLookAndFeel* __fastcall LookAndFeel(void)/* overload */;
	
public:
	virtual void __fastcall Paint(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
public:
	/* TdxPSReportGroupLookAndFeelPainter.Create */ inline __fastcall virtual TdxPSReportGroupWebLookAndFeelPainter(TdxPSReportRenderer* ARenderer) : TdxPSReportGroupLookAndFeelPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSReportGroupWebLookAndFeelPainter(void) { }
	
};


class PASCALIMPLEMENTATION TdxReportGroup : public TdxReportCell
{
	typedef TdxReportCell inherited;
	
private:
	System::UnicodeString FCaptionText;
	int FCaptionTextWidth;
	bool FCheckBoxChecked;
	bool FCheckBoxVisible;
	TdxPSReportGroupLookAndFeel* FLookAndFeel;
	Cxdrawtextutils::TcxTextAlignX __fastcall GetCaptionAlignment(void);
	int __fastcall GetCaptionTextWidth(void);
	bool __fastcall GetCaptionTransparent(void);
	TdxPSReportGroupLookAndFeel* __fastcall GetLookAndFeel(void);
	int __fastcall GetLookAndFeelIndex(void);
	bool __fastcall GetShowCaption(void);
	bool __fastcall GetUseOwnBorderClass(void);
	void __fastcall SetCaptionAlignment(Cxdrawtextutils::TcxTextAlignX Value);
	void __fastcall SetCaptionTransparent(bool Value);
	void __fastcall SetLookAndFeel(TdxPSReportGroupLookAndFeel* Value);
	void __fastcall SetShowCaption(bool Value);
	void __fastcall SetUseOwnBorderClass(bool Value);
	
protected:
	virtual void __fastcall AdjustBorderOuterBounds(System::Types::TRect &R);
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual void __fastcall InternalDrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual TdxPSCellBorderClass __fastcall GetBorderClass(void);
	virtual int __fastcall GetBorderEdgeSalient(TdxCellSide ASide, TdxPSCellBorderSalientType ASalient);
	virtual int __fastcall GetBorderEdgeThickness(TdxCellSide ASide);
	int __fastcall InternalGetBorderEdgeThickness(TdxCellSide ASide);
	virtual bool __fastcall IsBordersDrawn(void);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property int CaptionTextWidth = {read=GetCaptionTextWidth, nodefault};
	__property int LookAndFeelIndex = {read=GetLookAndFeelIndex, nodefault};
	
public:
	__fastcall virtual TdxReportGroup(TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	void __fastcall CalculateCaptionTextWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetBorderOuterBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property Cxdrawtextutils::TcxTextAlignX CaptionAlignment = {read=GetCaptionAlignment, write=SetCaptionAlignment, nodefault};
	__property System::UnicodeString CaptionText = {read=FCaptionText, write=FCaptionText};
	__property bool CaptionTransparent = {read=GetCaptionTransparent, write=SetCaptionTransparent, nodefault};
	__property bool CheckBoxVisible = {read=FCheckBoxVisible, write=FCheckBoxVisible, nodefault};
	__property bool CheckBoxChecked = {read=FCheckBoxChecked, write=FCheckBoxChecked, nodefault};
	__property TdxPSReportGroupLookAndFeel* LookAndFeel = {read=GetLookAndFeel, write=SetLookAndFeel};
	__property bool ShowCaption = {read=GetShowCaption, write=SetShowCaption, nodefault};
	__property bool UseOwnBorderClass = {read=GetUseOwnBorderClass, write=SetUseOwnBorderClass, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportGroup(void) { }
	
};


class PASCALIMPLEMENTATION TdxReportCells : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	int FBorderWidth;
	TdxReportCell* FCells;
	System::Uitypes::TColor FExpandButtonBorderColor;
	TdxReportCell* FFooterCells;
	System::Uitypes::TColor FGroupBorderColor;
	System::Uitypes::TColor FGroupCaptionColor;
	System::Uitypes::TColor FGroupCaptionSeparatorColor;
	System::Uitypes::TColor FGroupColor;
	TdxReportCell* FHeaderCells;
	TdxReportCell* FHeaderCornerCells;
	System::Classes::TList* FImageLists;
	TdxPSReportGroupLookAndFeel* FLookAndFeel;
	System::Classes::TList* FLookAndFeels;
	System::Classes::TList* FOverlays;
	bool FOwnImageLists;
	TBasedxReportLink* FReportLink;
	TdxReportCell* FRowHeaderCells;
	System::Uitypes::TColor FShadowColor;
	int FShadowDepth;
	System::Uitypes::TColor FTreeLineColor;
	TdxPSTreeLineStyle FTreeLineStyle;
	TdxReportCell* __fastcall CreateFixedGroupCell(void);
	bool __fastcall GetAreFooterCellsAllocated(void);
	bool __fastcall GetAreHeaderCellsAllocated(void);
	bool __fastcall GetAreHeaderCornerCellsAllocated(void);
	bool __fastcall GetAreRowHeaderCellsAllocated(void);
	System::Types::TRect __fastcall GetBoundsRect(void);
	int __fastcall GetCount(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	System::Types::TRect __fastcall GetFooterBoundsRect(void);
	int __fastcall GetFooterCellCount(void);
	TdxReportCell* __fastcall GetFooterCells(void);
	System::Types::TRect __fastcall GetHeaderBoundsRect(void);
	int __fastcall GetHeaderCellCount(void);
	TdxReportCell* __fastcall GetHeaderCells(void);
	System::Types::TRect __fastcall GetHeaderCornerBoundsRect(void);
	TdxReportCell* __fastcall GetHeaderCornerCells(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImageList(int Index);
	int __fastcall GetImageListCount(void);
	TdxPSReportGroupLookAndFeel* __fastcall GetLookAndFeel(int Index);
	int __fastcall GetLookAndFeelCount(void);
	TdxReportCell* __fastcall GetOverlay(int Index);
	int __fastcall GetOverlayCount(void);
	TdxPSReportRenderer* __fastcall GetRenderer(void);
	System::Types::TRect __fastcall GetRowHeaderBoundsRect(void);
	int __fastcall GetRowHeaderCellCount(void);
	TdxReportCell* __fastcall GetRowHeaderCells(void);
	void __fastcall SetBorderColor(System::Uitypes::TColor Value);
	void __fastcall SetShadowColor(System::Uitypes::TColor Value);
	void __fastcall SetShadowDepth(int Value);
	void __fastcall SetTreeLineColor(System::Uitypes::TColor Value);
	
protected:
	virtual void __fastcall AfterReadData(TdxPSDataReader* AReader);
	virtual void __fastcall AfterWriteData(TdxPSDataWriter* AWriter);
	virtual void __fastcall BeforeReadData(TdxPSDataReader* AReader);
	virtual void __fastcall BeforeWriteData(TdxPSDataWriter* AWriter);
	void __fastcall ReadCells(TdxPSDataReader* AReader);
	void __fastcall ReadHeaderCells(TdxPSDataReader* AReader);
	void __fastcall ReadFooterCells(TdxPSDataReader* AReader);
	void __fastcall ReadImageLists(TdxPSDataReader* AReader);
	void __fastcall ReadLookAndFeels(TdxPSDataReader* AReader);
	void __fastcall ReadOverlayCells(TdxPSDataReader* AReader);
	void __fastcall ReadProperties(TdxPSDataReader* AReader);
	void __fastcall WriteCells(TdxPSDataWriter* AWriter);
	void __fastcall WriteFooterCells(TdxPSDataWriter* AWriter);
	void __fastcall WriteHeaderCells(TdxPSDataWriter* AWriter);
	void __fastcall WriteImageLists(TdxPSDataWriter* AWriter);
	void __fastcall WriteLookAndFeels(TdxPSDataWriter* AWriter);
	void __fastcall WriteOverlayCells(TdxPSDataWriter* AWriter);
	void __fastcall WriteProperties(TdxPSDataWriter* AWriter);
	int __fastcall CalculateOverlaysHeight(void);
	int __fastcall CalculateOverlaysWidth(void);
	int __fastcall CalculateTotalHeight(void);
	int __fastcall CalculateTotalWidth(void);
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual TdxReportCell* __fastcall GetCellTopLevelParent(TdxReportItem* AnItem);
	void __fastcall FreeAndNilReportGroupLookAndFeels(void);
	void __fastcall PrepareReportGroupsLookAndFeels(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	void __fastcall AddImageList(Vcl::Imglist::TCustomImageList* AImageList);
	void __fastcall ClearImageLists(void);
	void __fastcall FreeAndNilImageLists(void);
	void __fastcall GetImageLists(void);
	__property int ImageListCount = {read=GetImageListCount, nodefault};
	__property bool OwnImageLists = {read=FOwnImageLists, write=FOwnImageLists, nodefault};
	__property TdxPSReportRenderer* Renderer = {read=GetRenderer};
	
public:
	__fastcall virtual TdxReportCells(TBasedxReportLink* AReportLink);
	__fastcall virtual ~TdxReportCells(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ClearItems(void);
	void __fastcall ClearLookAndFeels(void);
	TdxPSReportGroupLookAndFeel* __fastcall CreateGroupLookAndFeel(TdxPSReportGroupLookAndFeelClass AClass, bool ACheckExisting = true);
	TdxPSReportGroupLookAndFeel* __fastcall FindGroupLookAndFeelByClass(TdxPSReportGroupLookAndFeelClass AClass);
	TdxPSReportGroupLookAndFeel* __fastcall FindGroupLookAndFeelByData(void * AData);
	int __fastcall IndexOfImageList(Vcl::Imglist::TCustomImageList* AnImageList);
	int __fastcall IndexOfReportGroupLookAndFeel(TdxPSReportGroupLookAndFeel* ALookAndFeel);
	void __fastcall DoProgress(const double APercentDone);
	TdxReportCell* __fastcall AddOverlay(void);
	void __fastcall AppendOverlays(TdxReportCells* Source, int AnOffsetX = 0x0, int AnOffsetY = 0x0);
	void __fastcall AssignOverlays(TdxReportCells* Source, int AnOffsetX = 0x0, int AnOffsetY = 0x0);
	void __fastcall ClearOverlays(void);
	void __fastcall DeleteOverlay(TdxReportCell* AnOverlay);
	void __fastcall FreeAndNilOverlays(void);
	bool __fastcall HasOverlays(void);
	int __fastcall IndexOfOverlay(TdxReportCell* AnOverlay);
	virtual void __fastcall AssignLookAndFeels(TdxReportCells* Source);
	Vcl::Graphics::TFont* __fastcall GetFontByIndex(int AnIndex);
	int __fastcall GetIndexByFont(Vcl::Graphics::TFont* AFont);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property bool AreFooterCellsAllocated = {read=GetAreFooterCellsAllocated, nodefault};
	__property bool AreHeaderCellsAllocated = {read=GetAreHeaderCellsAllocated, nodefault};
	__property bool AreHeaderCornerCellsAllocated = {read=GetAreHeaderCornerCellsAllocated, nodefault};
	__property bool AreRowHeaderCellsAllocated = {read=GetAreRowHeaderCellsAllocated, nodefault};
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=SetBorderColor, nodefault};
	__property int BorderWidth = {read=FBorderWidth, write=FBorderWidth, nodefault};
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect};
	__property TdxReportCell* Cells = {read=FCells};
	__property int Count = {read=GetCount, nodefault};
	__property System::Uitypes::TColor ExpandButtonBorderColor = {read=FExpandButtonBorderColor, write=FExpandButtonBorderColor, default=0};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property System::Types::TRect FooterBoundsRect = {read=GetFooterBoundsRect};
	__property int FooterCellCount = {read=GetFooterCellCount, nodefault};
	__property TdxReportCell* FooterCells = {read=GetFooterCells};
	__property System::Uitypes::TColor GroupBorderColor = {read=FGroupBorderColor, write=FGroupBorderColor, nodefault};
	__property System::Uitypes::TColor GroupCaptionColor = {read=FGroupCaptionColor, write=FGroupCaptionColor, nodefault};
	__property System::Uitypes::TColor GroupCaptionSeparatorColor = {read=FGroupCaptionSeparatorColor, write=FGroupCaptionSeparatorColor, nodefault};
	__property System::Uitypes::TColor GroupColor = {read=FGroupColor, write=FGroupColor, nodefault};
	__property System::Types::TRect HeaderBoundsRect = {read=GetHeaderBoundsRect};
	__property int HeaderCellCount = {read=GetHeaderCellCount, nodefault};
	__property TdxReportCell* HeaderCells = {read=GetHeaderCells};
	__property System::Types::TRect HeaderCornerBoundsRect = {read=GetHeaderCornerBoundsRect};
	__property TdxReportCell* HeaderCornerCells = {read=GetHeaderCornerCells};
	__property Vcl::Imglist::TCustomImageList* ImageLists[int Index] = {read=GetImageList};
	__property TdxPSReportGroupLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=FLookAndFeel};
	__property int LookAndFeelCount = {read=GetLookAndFeelCount, nodefault};
	__property TdxPSReportGroupLookAndFeel* LookAndFeels[int Index] = {read=GetLookAndFeel};
	__property int OverlayCount = {read=GetOverlayCount, nodefault};
	__property TdxReportCell* Overlays[int Index] = {read=GetOverlay};
	__property TBasedxReportLink* ReportLink = {read=FReportLink};
	__property System::Types::TRect RowHeaderBoundsRect = {read=GetRowHeaderBoundsRect};
	__property int RowHeaderCellCount = {read=GetRowHeaderCellCount, nodefault};
	__property TdxReportCell* RowHeaderCells = {read=GetRowHeaderCells};
	__property System::Uitypes::TColor ShadowColor = {read=FShadowColor, write=SetShadowColor, nodefault};
	__property int ShadowDepth = {read=FShadowDepth, write=SetShadowDepth, nodefault};
	__property System::Uitypes::TColor TreeLineColor = {read=FTreeLineColor, write=SetTreeLineColor, nodefault};
	__property TdxPSTreeLineStyle TreeLineStyle = {read=FTreeLineStyle, write=FTreeLineStyle, default=1};
};


class PASCALIMPLEMENTATION TAbstractdxReportCellData : public TdxReportVisualItem
{
	typedef TdxReportVisualItem inherited;
	
private:
	bool FPreventAutoIndents;
	bool __fastcall GetBreakByChars(void);
	bool __fastcall GetEndEllipsis(void);
	bool __fastcall GetHidePrefix(void);
	bool __fastcall GetMultiline(void);
	bool __fastcall GetPreventLeftTextExceed(void);
	bool __fastcall GetPreventTopTextExceed(void);
	TdxCellSortOrder __fastcall GetSortOrder(void);
	Cxdrawtextutils::TcxTextAlignX __fastcall GetTextAlignX(void);
	Cxdrawtextutils::TcxTextAlignY __fastcall GetTextAlignY(void);
	void __fastcall SetBreakByChars(bool Value);
	void __fastcall SetEndEllipsis(bool Value);
	void __fastcall SetHidePrefix(bool Value);
	void __fastcall SetMultiline(bool Value);
	void __fastcall SetPreventLeftTextExceed(bool Value);
	void __fastcall SetPreventTopTextExceed(bool Value);
	void __fastcall SetSortOrder(TdxCellSortOrder Value);
	void __fastcall SetTextAlignX(Cxdrawtextutils::TcxTextAlignX Value);
	void __fastcall SetTextAlignY(Cxdrawtextutils::TcxTextAlignY Value);
	bool __fastcall HasPreventAutoIndentsProperty(const Dxpsglbl::TdxPSVersion &AVersion);
	
protected:
	virtual bool __fastcall CustomDraw(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetAbsoluteEffectiveBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage);
	virtual unsigned __fastcall GetDefaultDTFormat(void);
	virtual System::Types::TRect __fastcall GetEffectiveBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage);
	virtual unsigned __fastcall GetDTFormat(void);
	virtual bool __fastcall IsCustomDrawn(void);
	virtual bool __fastcall IsDrawingNeeded(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage, const System::Types::TRect &ARect);
	virtual bool __fastcall IsDrawn(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage, const System::Types::TRect &ARect);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property bool BreakByChars = {read=GetBreakByChars, write=SetBreakByChars, default=1};
	__property bool EndEllipsis = {read=GetEndEllipsis, write=SetEndEllipsis, default=0};
	__property bool HidePrefix = {read=GetHidePrefix, write=SetHidePrefix, default=0};
	__property bool Multiline = {read=GetMultiline, write=SetMultiline, default=0};
	__property bool PreventAutoIndents = {read=FPreventAutoIndents, write=FPreventAutoIndents, default=0};
	__property bool PreventLeftTextExceed = {read=GetPreventLeftTextExceed, write=SetPreventLeftTextExceed, nodefault};
	__property bool PreventTopTextExceed = {read=GetPreventTopTextExceed, write=SetPreventTopTextExceed, nodefault};
	__property TdxCellSortOrder SortOrder = {read=GetSortOrder, write=SetSortOrder, default=0};
	__property Cxdrawtextutils::TcxTextAlignX TextAlignX = {read=GetTextAlignX, write=SetTextAlignX, default=0};
	__property Cxdrawtextutils::TcxTextAlignY TextAlignY = {read=GetTextAlignY, write=SetTextAlignY, default=1};
	
public:
	__fastcall virtual TAbstractdxReportCellData(TdxReportCell* AParent);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage);
	virtual int __fastcall GetCustomDrawID(void);
	virtual int __fastcall MeasureContentHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property unsigned DefaultDTFormat = {read=GetDefaultDTFormat, nodefault};
	__property unsigned DTFormat = {read=GetDTFormat, nodefault};
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TAbstractdxReportCellData(void) { }
	
};


class DELPHICLASS TdxReportCellBox;
class PASCALIMPLEMENTATION TdxReportCellBox : public TAbstractdxReportCellData
{
	typedef TAbstractdxReportCellData inherited;
	
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TdxReportCellBox(TdxReportCell* AParent) : TAbstractdxReportCellData(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellBox(void) { }
	
};


typedef System::TMetaClass* TdxReportCellBoxClass;

class DELPHICLASS TdxReportCellText;
class PASCALIMPLEMENTATION TdxReportCellText : public TAbstractdxReportCellData
{
	typedef TAbstractdxReportCellData inherited;
	
private:
	bool FAdjustFont;
	Cxgeometry::TcxRect* FIndents;
	int FSortMarkRegionSize;
	int __fastcall GetSortMarkRegionSize(void);
	void __fastcall SetIndents(Cxgeometry::TcxRect* AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetText(void) = 0 ;
	virtual void __fastcall SetText(const System::UnicodeString Value) = 0 ;
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual System::Types::TRect __fastcall GetSortMarkBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetTextBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual bool __fastcall IsSortMarkDrawn(void);
	virtual bool __fastcall IsTextDrawn(void);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property bool AdjustFont = {read=FAdjustFont, write=FAdjustFont, nodefault};
	__property int SortMarkRegionSize = {read=GetSortMarkRegionSize, nodefault};
	
public:
	__fastcall virtual TdxReportCellText(TdxReportCell* AParent);
	__fastcall virtual ~TdxReportCellText(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage);
	virtual void __fastcall DrawSortMark(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawText(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall CalculateLineCount(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureFontHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property EndEllipsis = {default=0};
	__property HidePrefix = {default=0};
	__property Cxgeometry::TcxRect* Indents = {read=FIndents, write=SetIndents};
	__property Multiline = {default=0};
	__property SortOrder = {default=0};
	__property System::UnicodeString Text = {read=GetText, write=SetText};
};


typedef System::TMetaClass* TdxReportCellTextClass;

class DELPHICLASS TdxReportCellString;
class PASCALIMPLEMENTATION TdxReportCellString : public TdxReportCellText
{
	typedef TdxReportCellText inherited;
	
private:
	System::UnicodeString FText;
	
protected:
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall SetText(const System::UnicodeString Value);
	
public:
	__property AdjustFont;
	__property PreventAutoIndents = {default=0};
	__property PreventLeftTextExceed;
	__property PreventTopTextExceed;
	__property TextAlignX = {default=0};
	__property TextAlignY = {default=1};
public:
	/* TdxReportCellText.Create */ inline __fastcall virtual TdxReportCellString(TdxReportCell* AParent) : TdxReportCellText(AParent) { }
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportCellString(void) { }
	
};


typedef System::TMetaClass* TdxReportCellStringClass;

class DELPHICLASS TdxReportCellImageContainer;
class PASCALIMPLEMENTATION TdxReportCellImageContainer : public TdxReportCellString
{
	typedef TdxReportCellString inherited;
	
private:
	bool __fastcall GetImageTransparent(void);
	void __fastcall SetImageTransparent(bool Value);
	
protected:
	virtual System::Types::TRect __fastcall GetImageAreaBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetImageBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall GetImageSizes(int &AImageWidth, int &AImageHeight);
	virtual bool __fastcall HasImage(void);
	virtual bool __fastcall IsImageBackgroundDrawn(void);
	virtual bool __fastcall IsImageDrawn(void);
	virtual bool __fastcall IsTextBackgroundDrawn(void);
	__property bool ImageTransparent = {read=GetImageTransparent, write=SetImageTransparent, default=1};
	
public:
	__fastcall virtual TdxReportCellImageContainer(TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage);
	virtual void __fastcall DrawImage(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawImageBackground(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawTextBackground(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportCellImageContainer(void) { }
	
};


typedef System::TMetaClass* TdxCustomReportCellCheckClass;

class DELPHICLASS TdxCustomReportCellCheck;
class PASCALIMPLEMENTATION TdxCustomReportCellCheck : public TdxReportCellImageContainer
{
	typedef TdxReportCellImageContainer inherited;
	
private:
	bool __fastcall GetBoldBorder(void);
	Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle __fastcall GetButtonEdgeStyle(void);
	bool __fastcall GetChecked(void);
	TdxCellCheckPos __fastcall GetCheckPos(void);
	bool __fastcall GetEnabled(void);
	bool __fastcall GetFlatBorder(void);
	Vcl::Stdctrls::TCheckBoxState __fastcall GetState(void);
	void __fastcall SetBoldBorder(bool Value);
	void __fastcall SetButtonEdgeStyle(Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle Value);
	void __fastcall SetCheckPos(TdxCellCheckPos Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetFlatBorder(bool Value);
	
protected:
	virtual System::Types::TRect __fastcall GetCheckBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetImageAreaBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetImageBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall GetImageSizes(int &AImageWidth, int &AImageHeight);
	virtual System::Types::TRect __fastcall GetTextBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual bool __fastcall HasImage(void);
	virtual bool __fastcall IsImageBackgroundDrawn(void);
	__classmethod virtual bool __fastcall IsRadio();
	virtual void __fastcall SetChecked(bool Value);
	__property bool BoldBorder = {read=GetBoldBorder, write=SetBoldBorder, nodefault};
	__property bool FlatBorder = {read=GetFlatBorder, write=SetFlatBorder, nodefault};
	__property Vcl::Stdctrls::TCheckBoxState State = {read=GetState, nodefault};
	
public:
	__fastcall virtual TdxCustomReportCellCheck(TdxReportCell* AParent);
	virtual void __fastcall DrawCheck(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawImage(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle ButtonEdgeStyle = {read=GetButtonEdgeStyle, write=SetButtonEdgeStyle, default=4};
	__property bool Checked = {read=GetChecked, write=SetChecked, default=0};
	__property TdxCellCheckPos CheckPos = {read=GetCheckPos, write=SetCheckPos, default=1};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, default=1};
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxCustomReportCellCheck(void) { }
	
};


class DELPHICLASS TdxReportCellCheck;
class PASCALIMPLEMENTATION TdxReportCellCheck : public TdxCustomReportCellCheck
{
	typedef TdxCustomReportCellCheck inherited;
	
public:
	__property BoldBorder;
	__property FlatBorder;
	__property State;
public:
	/* TdxCustomReportCellCheck.Create */ inline __fastcall virtual TdxReportCellCheck(TdxReportCell* AParent) : TdxCustomReportCellCheck(AParent) { }
	
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportCellCheck(void) { }
	
};


class DELPHICLASS TdxCustomReportCellRadio;
class PASCALIMPLEMENTATION TdxCustomReportCellRadio : public TdxReportCellCheck
{
	typedef TdxReportCellCheck inherited;
	
protected:
	__classmethod virtual bool __fastcall IsRadio();
public:
	/* TdxCustomReportCellCheck.Create */ inline __fastcall virtual TdxCustomReportCellRadio(TdxReportCell* AParent) : TdxReportCellCheck(AParent) { }
	
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxCustomReportCellRadio(void) { }
	
};


class DELPHICLASS TdxReportCellRadio;
class PASCALIMPLEMENTATION TdxReportCellRadio : public TdxCustomReportCellRadio
{
	typedef TdxCustomReportCellRadio inherited;
	
public:
	/* TdxCustomReportCellCheck.Create */ inline __fastcall virtual TdxReportCellRadio(TdxReportCell* AParent) : TdxCustomReportCellRadio(AParent) { }
	
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportCellRadio(void) { }
	
};


class DELPHICLASS TdxCustomReportCellCheckImage;
class PASCALIMPLEMENTATION TdxCustomReportCellCheckImage : public TdxReportCellCheck
{
	typedef TdxReportCellCheck inherited;
	
private:
	System::Types::TRect __fastcall GetGlyphPartialBounds(void);
	
protected:
	virtual void __fastcall GetImageSizes(int &AImageWidth, int &AImageHeight);
	virtual Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	virtual int __fastcall GetGlyphCount(void);
	virtual int __fastcall GetGlyphIndex(void);
	virtual void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	virtual void __fastcall SetGlyphCount(int Value);
	virtual bool __fastcall HasGlyph(void);
	virtual void __fastcall ReleaseGlyph(void);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int GlyphCount = {read=GetGlyphCount, write=SetGlyphCount, nodefault};
	__property int GlyphIndex = {read=GetGlyphIndex, nodefault};
	__property System::Types::TRect GlyphPartialBounds = {read=GetGlyphPartialBounds};
	
public:
	__fastcall virtual TdxCustomReportCellCheckImage(TdxReportCell* AParent);
	__fastcall virtual ~TdxCustomReportCellCheckImage(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawCheck(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawCheckGlyph(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
};


class DELPHICLASS TdxReportCellCheckImage;
class PASCALIMPLEMENTATION TdxReportCellCheckImage : public TdxCustomReportCellCheckImage
{
	typedef TdxCustomReportCellCheckImage inherited;
	
private:
	Vcl::Graphics::TBitmap* FGlyph;
	
protected:
	virtual int __fastcall GetGlyphCount(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	virtual void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	virtual void __fastcall SetGlyphCount(int Value);
	virtual bool __fastcall HasGlyph(void);
	virtual void __fastcall ReleaseGlyph(void);
	
public:
	__property Glyph;
	__property GlyphCount;
	__property GlyphIndex;
	__property GlyphPartialBounds;
public:
	/* TdxCustomReportCellCheckImage.Create */ inline __fastcall virtual TdxReportCellCheckImage(TdxReportCell* AParent) : TdxCustomReportCellCheckImage(AParent) { }
	/* TdxCustomReportCellCheckImage.Destroy */ inline __fastcall virtual ~TdxReportCellCheckImage(void) { }
	
};


typedef System::TMetaClass* TdxCustomReportButtonGroupClass;

class DELPHICLASS TdxCustomReportButtonGroup;
class PASCALIMPLEMENTATION TdxCustomReportButtonGroup : public TdxReportGroup
{
	typedef TdxReportGroup inherited;
	
private:
	int FColumnCount;
	int FInterColumnsMinSpace;
	int FInterRowsMinSpace;
	System::Types::TRect FIndents;
	System::Types::TSize FItemSize;
	Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle __fastcall GetButtonEdgeStyle(void);
	TdxCellCheckPos __fastcall GetCheckPos(void);
	TdxCustomReportCellCheck* __fastcall GetItem(int Index);
	int __fastcall GetItemColumn(int Index);
	int __fastcall GetItemCount(void);
	int __fastcall GetItemRow(int Index);
	int __fastcall GetRowCount(void);
	void __fastcall SetButtonEdgeStyle(Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle Value);
	void __fastcall SetCheckPos(TdxCellCheckPos Value);
	void __fastcall SetColumnCount(int Value);
	void __fastcall SetInterColumnsMinSpace(int Value);
	void __fastcall SetInterRowsMinSpace(int Value);
	void __fastcall SetIndents(System::Types::TRect &Value);
	
protected:
	bool FLocked;
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual void __fastcall SetFontIndex(int Value);
	virtual void __fastcall ReadDataItems(TdxPSDataReader* AReader);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__classmethod virtual TdxCustomReportCellCheckClass __fastcall GetItemClass();
	virtual void __fastcall InitializeItem(TdxCustomReportCellCheck* AnItem);
	__property System::Types::TSize ItemSize = {read=FItemSize};
	__property bool Locked = {read=FLocked, write=FLocked, nodefault};
	
public:
	__fastcall virtual TdxCustomReportButtonGroup(TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AdjustContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	TdxCustomReportCellCheck* __fastcall Add(const System::UnicodeString AText = System::UnicodeString());
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	int __fastcall FindItem(const System::UnicodeString ACaption);
	__property Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle ButtonEdgeStyle = {read=GetButtonEdgeStyle, write=SetButtonEdgeStyle, default=4};
	__property TdxCellCheckPos CheckPos = {read=GetCheckPos, write=SetCheckPos, default=1};
	__property int ColumnCount = {read=FColumnCount, write=SetColumnCount, nodefault};
	__property System::Types::TRect Indents = {read=FIndents, write=SetIndents};
	__property int InterColumnsMinSpace = {read=FInterColumnsMinSpace, write=SetInterColumnsMinSpace, nodefault};
	__property int InterRowsMinSpace = {read=FInterRowsMinSpace, write=SetInterRowsMinSpace, nodefault};
	__property int ItemColumns[int Index] = {read=GetItemColumn};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property int ItemRows[int Index] = {read=GetItemRow};
	__property TdxCustomReportCellCheck* Items[int Index] = {read=GetItem};
	__property int RowCount = {read=GetRowCount, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxCustomReportButtonGroup(void) { }
	
};


class DELPHICLASS TdxReportRadioGroup;
class PASCALIMPLEMENTATION TdxReportRadioGroup : public TdxCustomReportButtonGroup
{
	typedef TdxCustomReportButtonGroup inherited;
	
private:
	HIDESBASE TdxCustomReportCellRadio* __fastcall GetItem(int Index);
	int __fastcall GetItemIndex(void);
	void __fastcall SetItemIndex(int Value);
	
protected:
	__classmethod virtual TdxCustomReportCellCheckClass __fastcall GetItemClass();
	
public:
	HIDESBASE TdxCustomReportCellRadio* __fastcall Add(const System::UnicodeString AText = System::UnicodeString());
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property TdxCustomReportCellRadio* Items[int Index] = {read=GetItem};
public:
	/* TdxCustomReportButtonGroup.Create */ inline __fastcall virtual TdxReportRadioGroup(TdxReportCell* AParent) : TdxCustomReportButtonGroup(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportRadioGroup(void) { }
	
};


class DELPHICLASS TdxReportCheckGroup;
class PASCALIMPLEMENTATION TdxReportCheckGroup : public TdxCustomReportButtonGroup
{
	typedef TdxCustomReportButtonGroup inherited;
	
private:
	Vcl::Graphics::TBitmap* FGlyph;
	int FGlyphCount;
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	HIDESBASE TdxCustomReportCellCheckImage* __fastcall GetItem(int Index);
	bool __fastcall GetItemChecked(int Index);
	bool __fastcall GetItemEnabled(int Index);
	Vcl::Stdctrls::TCheckBoxState __fastcall GetItemState(int Index);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetGlyphCount(int Value);
	void __fastcall SetItemChecked(int Index, bool Value);
	void __fastcall SetItemEnabled(int Index, bool Value);
	
protected:
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__classmethod virtual TdxCustomReportCellCheckClass __fastcall GetItemClass();
	virtual void __fastcall InitializeItem(TdxCustomReportCellCheck* AnItem);
	
public:
	__fastcall virtual TdxReportCheckGroup(TdxReportCell* AParent);
	__fastcall virtual ~TdxReportCheckGroup(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HIDESBASE TdxCustomReportCellCheckImage* __fastcall Add(const System::UnicodeString AText = System::UnicodeString());
	bool __fastcall HasGlyph(void);
	void __fastcall ReleaseGlyph(void);
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int GlyphCount = {read=FGlyphCount, write=SetGlyphCount, nodefault};
	__property TdxCustomReportCellCheckImage* Items[int Index] = {read=GetItem};
	__property bool ItemsChecked[int Index] = {read=GetItemChecked, write=SetItemChecked};
	__property bool ItemsEnabled[int Index] = {read=GetItemEnabled, write=SetItemEnabled};
	__property Vcl::Stdctrls::TCheckBoxState ItemsState[int Index] = {read=GetItemState};
};


class DELPHICLASS TCustomdxReportCellImageContainer;
class PASCALIMPLEMENTATION TCustomdxReportCellImageContainer : public TdxReportCellImageContainer
{
	typedef TdxReportCellImageContainer inherited;
	
private:
	Vcl::Graphics::TGraphic* FImage;
	int FImageIndex;
	Vcl::Imglist::TCustomImageList* FImageList;
	bool FImagePrepared;
	int FOverlayImageIndex;
	bool __fastcall GetImageListUsed(void);
	void __fastcall SetImage(Vcl::Graphics::TGraphic* Value);
	
protected:
	virtual bool __fastcall CanPrepareImage(void);
	virtual TdxCellImageBuffering __fastcall GetActualImageBuffering(void);
	virtual TdxCellImageBuffering __fastcall GetImageBuffering(void);
	virtual void __fastcall GetImageSizes(int &AImageWidth, int &AImageHeight);
	virtual bool __fastcall HasImage(void);
	Cxgraphics::TcxBitmap* __fastcall PrepareImage(void);
	void __fastcall PrepareImageBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall SetImageBuffering(TdxCellImageBuffering Value);
	int __fastcall GetImageListIndex(void);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property TdxCellImageBuffering ActualImageBuffering = {read=GetActualImageBuffering, nodefault};
	__property TdxCellImageBuffering ImageBuffering = {read=GetImageBuffering, write=SetImageBuffering, nodefault};
	__property bool ImageListUsed = {read=GetImageListUsed, nodefault};
	__property bool ImagePrepared = {read=FImagePrepared, write=FImagePrepared, nodefault};
	
public:
	__fastcall virtual TCustomdxReportCellImageContainer(TdxReportCell* AParent);
	__fastcall virtual ~TCustomdxReportCellImageContainer(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Vcl::Graphics::TGraphic* __fastcall CreateImage(Vcl::Graphics::TGraphicClass AGraphicClass);
	virtual void __fastcall DrawImage(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property Vcl::Graphics::TGraphic* Image = {read=FImage, write=SetImage};
	__property int ImageIndex = {read=FImageIndex, write=FImageIndex, nodefault};
	__property Vcl::Imglist::TCustomImageList* ImageList = {read=FImageList, write=FImageList};
	__property ImageTransparent = {default=1};
	__property int OverlayImageIndex = {read=FOverlayImageIndex, write=FOverlayImageIndex, nodefault};
};


typedef System::TMetaClass* TdxReportCellImageClass;

class DELPHICLASS TdxReportCellImage;
class PASCALIMPLEMENTATION TdxReportCellImage : public TCustomdxReportCellImageContainer
{
	typedef TCustomdxReportCellImageContainer inherited;
	
private:
	TdxImageLayout __fastcall GetImageLayout(void);
	System::Types::TSize __fastcall GetImageSize(void);
	bool __fastcall GetIsTextDrawnForCenteredImage(void);
	bool __fastcall GetIsTextShiftedForHorizontallyCenteredImage(void);
	bool __fastcall GetMakeSpaceForEmptyImage(void);
	void __fastcall SetImageLayout(TdxImageLayout Value);
	void __fastcall SetIsTextDrawnForCenteredImage(bool Value);
	void __fastcall SetIsTextShiftedForHorizontallyCenteredImage(bool Value);
	void __fastcall SetMakeSpaceForEmptyImage(bool Value);
	
protected:
	virtual System::Types::TRect __fastcall GetImageAreaBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetImageBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetTextBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual bool __fastcall IsImageBackgroundDrawn(void);
	virtual bool __fastcall IsTextDrawn(void);
	virtual bool __fastcall IsTextBackgroundDrawn(void);
	
public:
	__fastcall virtual TdxReportCellImage(TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual int __fastcall MeasureContentHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property TdxImageLayout ImageLayout = {read=GetImageLayout, write=SetImageLayout, default=3};
	__property ImageTransparent = {default=1};
	__property bool IsTextDrawnForCenteredImage = {read=GetIsTextDrawnForCenteredImage, write=SetIsTextDrawnForCenteredImage, default=0};
	__property bool IsTextShiftedForHorizontallyCenteredImage = {read=GetIsTextShiftedForHorizontallyCenteredImage, write=SetIsTextShiftedForHorizontallyCenteredImage, default=1};
	__property bool MakeSpaceForEmptyImage = {read=GetMakeSpaceForEmptyImage, write=SetMakeSpaceForEmptyImage, default=1};
public:
	/* TCustomdxReportCellImageContainer.Destroy */ inline __fastcall virtual ~TdxReportCellImage(void) { }
	
};


typedef System::TMetaClass* TdxReportCellGraphicClass;

class DELPHICLASS TdxReportCellGraphic;
class PASCALIMPLEMENTATION TdxReportCellGraphic : public TCustomdxReportCellImageContainer
{
	typedef TCustomdxReportCellImageContainer inherited;
	
private:
	bool FCenter;
	bool FProportional;
	bool FStretch;
	void __fastcall CalculateDrawMode(void);
	Vcl::Graphics::TGraphic* __fastcall GetImage(void);
	TdxGraphicDrawMode __fastcall GetDrawMode(void);
	bool __fastcall GetRealStretch(void);
	HIDESBASE void __fastcall SetImage(Vcl::Graphics::TGraphic* Value);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetDrawMode(TdxGraphicDrawMode Value);
	void __fastcall SetProportional(bool Value);
	void __fastcall SetStretch(bool Value);
	
protected:
	virtual System::Types::TRect __fastcall GetImageBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual TdxCellImageBuffering __fastcall GetImageBuffering(void);
	virtual System::Types::TRect __fastcall GetTextBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall SetImageBuffering(TdxCellImageBuffering Value);
	
public:
	__fastcall virtual TdxReportCellGraphic(TdxReportCell* AParent);
	virtual int __fastcall MeasureFontHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureContentWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property bool Center = {read=FCenter, write=SetCenter, nodefault};
	__property TdxGraphicDrawMode DrawMode = {read=GetDrawMode, write=SetDrawMode, default=0};
	__property Vcl::Graphics::TGraphic* Image = {read=GetImage, write=SetImage};
	__property ImageBuffering;
	__property ImageTransparent = {default=1};
	__property bool Proportional = {read=FProportional, write=SetProportional, nodefault};
	__property bool RealStretch = {read=GetRealStretch, nodefault};
	__property bool Stretch = {read=FStretch, write=SetStretch, nodefault};
public:
	/* TCustomdxReportCellImageContainer.Destroy */ inline __fastcall virtual ~TdxReportCellGraphic(void) { }
	
};


enum TdxReportCellExpandButtonAlignHorz : unsigned char { bahLeft, bahCenter, bahRight };

enum TdxReportCellExpandButtonAlignVert : unsigned char { bavTop, bavCenter, bavBottom };

typedef System::TMetaClass* TdxReportCellExpandButtonClass;

class DELPHICLASS TdxReportCellExpandButton;
class PASCALIMPLEMENTATION TdxReportCellExpandButton : public TAbstractdxReportCellData
{
	typedef TAbstractdxReportCellData inherited;
	
private:
	System::Uitypes::TColor FButtonInteriorColor;
	int FButtonSize;
	int __fastcall GetActualButtonSize(void);
	bool __fastcall GetButtonBorder3D(void);
	bool __fastcall GetButtonBorder3DSoft(void);
	bool __fastcall GetButtonBorderShadow(void);
	bool __fastcall GetButtonExpanded(void);
	bool __fastcall GetButtonTransparent(void);
	bool __fastcall GetKeepOddSize(void);
	bool __fastcall GetShowButton(void);
	bool __fastcall GetShowButtonBorder(void);
	TdxPSTreeLineMode __fastcall GetTreeLineMode(void);
	void __fastcall SetButtonBorder3D(bool Value);
	void __fastcall SetButtonBorder3DSoft(bool Value);
	void __fastcall SetButtonBorderShadow(bool Value);
	void __fastcall SetButtonExpanded(bool Value);
	void __fastcall SetButtonTransparent(bool Value);
	void __fastcall SetKeepOddSize(bool Value);
	void __fastcall SetShowButton(bool Value);
	void __fastcall SetShowButtonBorder(bool Value);
	void __fastcall SetTreeLineMode(TdxPSTreeLineMode Value);
	
protected:
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	bool __fastcall AreTreeLinesDrawn(void);
	virtual System::Types::TRect __fastcall CalculateButtonBounds(void);
	virtual TdxReportCellExpandButtonAlignHorz __fastcall GetButtonAlignHorz(void);
	virtual TdxReportCellExpandButtonAlignVert __fastcall GetButtonAlignVert(void);
	virtual System::Types::TRect __fastcall GetButtonIndents(void);
	virtual void __fastcall SetButtonAlignHorz(TdxReportCellExpandButtonAlignHorz Value);
	virtual void __fastcall SetButtonAlignVert(TdxReportCellExpandButtonAlignVert Value);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TdxReportCellExpandButton(TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, TdxPSRenderStages AStage);
	virtual void __fastcall DrawExpandButton(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall DrawTreeLines(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetButtonBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property int ActualButtonSize = {read=GetActualButtonSize, nodefault};
	__property TdxReportCellExpandButtonAlignHorz ButtonAlignHorz = {read=GetButtonAlignHorz, write=SetButtonAlignHorz, default=1};
	__property TdxReportCellExpandButtonAlignVert ButtonAlignVert = {read=GetButtonAlignVert, write=SetButtonAlignVert, default=1};
	__property bool ButtonBorder3D = {read=GetButtonBorder3D, write=SetButtonBorder3D, default=0};
	__property bool ButtonBorder3DSoft = {read=GetButtonBorder3DSoft, write=SetButtonBorder3DSoft, default=0};
	__property bool ButtonBorderShadow = {read=GetButtonBorderShadow, write=SetButtonBorderShadow, default=0};
	__property bool ButtonExpanded = {read=GetButtonExpanded, write=SetButtonExpanded, default=0};
	__property System::Types::TRect ButtonIndents = {read=GetButtonIndents};
	__property System::Uitypes::TColor ButtonInteriorColor = {read=FButtonInteriorColor, write=FButtonInteriorColor, default=536870911};
	__property int ButtonSize = {read=FButtonSize, write=FButtonSize, default=9};
	__property bool ButtonTransparent = {read=GetButtonTransparent, write=SetButtonTransparent, default=1};
	__property bool KeepOddSize = {read=GetKeepOddSize, write=SetKeepOddSize, default=1};
	__property bool ShowButton = {read=GetShowButton, write=SetShowButton, default=0};
	__property bool ShowButtonBorder = {read=GetShowButtonBorder, write=SetShowButtonBorder, default=1};
	__property TdxPSTreeLineMode TreeLineMode = {read=GetTreeLineMode, write=SetTreeLineMode, default=0};
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellExpandButton(void) { }
	
};


class DELPHICLASS TdxReportCellExpandButtonEx;
class PASCALIMPLEMENTATION TdxReportCellExpandButtonEx : public TdxReportCellExpandButton
{
	typedef TdxReportCellExpandButton inherited;
	
private:
	unsigned FFormatEx;
	
protected:
	virtual TdxReportCellExpandButtonAlignHorz __fastcall GetButtonAlignHorz(void);
	virtual TdxReportCellExpandButtonAlignVert __fastcall GetButtonAlignVert(void);
	virtual System::Types::TRect __fastcall GetButtonIndents(void);
	virtual void __fastcall SetButtonAlignHorz(TdxReportCellExpandButtonAlignHorz Value);
	virtual void __fastcall SetButtonAlignVert(TdxReportCellExpandButtonAlignVert Value);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property unsigned FormatEx = {read=FFormatEx, write=FFormatEx, nodefault};
public:
	/* TdxReportCellExpandButton.Create */ inline __fastcall virtual TdxReportCellExpandButtonEx(TdxReportCell* AParent) : TdxReportCellExpandButton(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellExpandButtonEx(void) { }
	
};


enum TdxPSExplorerRefreshStage : unsigned char { ersBefore, ersAfter };

struct DECLSPEC_DRECORD TCustomdxPSExplorerItemStateInfo
{
public:
	int Count;
	int UniqueIDSize;
};


__interface IdxPSExplorerTreeContainerHost;
typedef System::DelphiInterface<IdxPSExplorerTreeContainerHost> _di_IdxPSExplorerTreeContainerHost;
__interface  INTERFACE_UUID("{4E52E062-EDCF-4A58-8212-45EAE673F506}") IdxPSExplorerTreeContainerHost  : public System::IInterface 
{
	
public:
	virtual bool __fastcall GetFlat(void) = 0 ;
	virtual TBasedxReportLink* __fastcall GetReportLink(void) = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetTreeContainerParent(void) = 0 ;
	virtual void __fastcall UpdateState(void) = 0 ;
	__property bool Flat = {read=GetFlat};
	__property TBasedxReportLink* ReportLink = {read=GetReportLink};
	__property Vcl::Controls::TWinControl* TreeContainerParent = {read=GetTreeContainerParent};
};

class DELPHICLASS TdxPSExplorerChangeNotifier;
class DELPHICLASS TCustomdxPSExplorer;
class DELPHICLASS TdxPSExplorerFolder;
class DELPHICLASS TCustomdxPSExplorerItem;
class DELPHICLASS TdxPSExplorerItem;
class PASCALIMPLEMENTATION TdxPSExplorerChangeNotifier : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TCustomdxPSExplorer* FExplorer;
	void __fastcall SetExplorer(TCustomdxPSExplorer* Value);
	
protected:
	virtual void __fastcall ExplorerRefresh(TdxPSExplorerRefreshStage AStage) = 0 ;
	virtual void __fastcall FolderPopulated(TdxPSExplorerFolder* AFolder) = 0 ;
	virtual void __fastcall ItemAdded(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall ItemDataLoaded(TdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall ItemDataUnloaded(TdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall ItemDeleted(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall ItemParentChanged(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall ItemPropertiesChanged(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall ItemRenamed(TCustomdxPSExplorerItem* AnItem) = 0 ;
	
public:
	__fastcall TdxPSExplorerChangeNotifier(TCustomdxPSExplorer* AnExplorer);
	__fastcall virtual ~TdxPSExplorerChangeNotifier(void);
	__property TCustomdxPSExplorer* Explorer = {read=FExplorer, write=SetExplorer};
};


class DELPHICLASS TdxPSExplorerChangeNotifierAdapter;
class PASCALIMPLEMENTATION TdxPSExplorerChangeNotifierAdapter : public TdxPSExplorerChangeNotifier
{
	typedef TdxPSExplorerChangeNotifier inherited;
	
protected:
	virtual void __fastcall ExplorerRefresh(TdxPSExplorerRefreshStage AStage);
	virtual void __fastcall FolderPopulated(TdxPSExplorerFolder* AFolder);
	virtual void __fastcall ItemAdded(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemDataLoaded(TdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemDataUnloaded(TdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemDeleted(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemParentChanged(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemPropertiesChanged(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemRenamed(TCustomdxPSExplorerItem* AnItem);
public:
	/* TdxPSExplorerChangeNotifier.Create */ inline __fastcall TdxPSExplorerChangeNotifierAdapter(TCustomdxPSExplorer* AnExplorer) : TdxPSExplorerChangeNotifier(AnExplorer) { }
	/* TdxPSExplorerChangeNotifier.Destroy */ inline __fastcall virtual ~TdxPSExplorerChangeNotifierAdapter(void) { }
	
};


class DELPHICLASS TdxPSExplorerTreeChangeNotifier;
class DELPHICLASS TCustomdxPSExplorerTreeContainer;
class PASCALIMPLEMENTATION TdxPSExplorerTreeChangeNotifier : public TdxPSExplorerChangeNotifierAdapter
{
	typedef TdxPSExplorerChangeNotifierAdapter inherited;
	
private:
	TCustomdxPSExplorerTreeContainer* FTreeContainer;
	
protected:
	virtual void __fastcall ExplorerRefresh(TdxPSExplorerRefreshStage AStage);
	virtual void __fastcall FolderPopulated(TdxPSExplorerFolder* AFolder);
	virtual void __fastcall ItemAdded(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemDataLoaded(TdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemDataUnloaded(TdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemDeleted(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemParentChanged(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemPropertiesChanged(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemRenamed(TCustomdxPSExplorerItem* AnItem);
	
public:
	__fastcall TdxPSExplorerTreeChangeNotifier(TCustomdxPSExplorerTreeContainer* ATreeContainer, bool ARegister);
	__property TCustomdxPSExplorerTreeContainer* TreeContainer = {read=FTreeContainer};
public:
	/* TdxPSExplorerChangeNotifier.Destroy */ inline __fastcall virtual ~TdxPSExplorerTreeChangeNotifier(void) { }
	
};


typedef System::TMetaClass* TCustomdxPSExplorerTreeContainerClass;

class PASCALIMPLEMENTATION TCustomdxPSExplorerTreeContainer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Controls::TWinControl* FControl;
	TdxPSExplorerTreeChangeNotifier* FChangeNotifier;
	TCustomdxPSExplorer* FExplorer;
	_di_IdxPSExplorerTreeContainerHost FHost;
	
protected:
	virtual void __fastcall AddItem(TdxPSExplorerFolder* AParent, TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall DeleteItem(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall InvalidateItem(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall MoveItem(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall RenameItem(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual TdxPSExplorerFolder* __fastcall GetCreationParent(void) = 0 ;
	virtual TCustomdxPSExplorerItem* __fastcall GetFocusedItem(void) = 0 ;
	virtual bool __fastcall GetIsEditing(void) = 0 ;
	virtual bool __fastcall GetIsFolderSelected(void) = 0 ;
	virtual bool __fastcall GetIsItemSelected(void) = 0 ;
	virtual bool __fastcall GetIsRootSelected(void) = 0 ;
	virtual TdxPSExplorerFolder* __fastcall GetSelectedFolder(void) = 0 ;
	virtual TCustomdxPSExplorerItem* __fastcall GetSelectedItem(void) = 0 ;
	virtual System::UnicodeString __fastcall GetSelectedItemText(void) = 0 ;
	virtual void __fastcall SetFocusedItem(TCustomdxPSExplorerItem* Value) = 0 ;
	virtual void __fastcall SetSelectedItem(TCustomdxPSExplorerItem* Value) = 0 ;
	virtual void __fastcall SetSelectedItemText(const System::UnicodeString Value) = 0 ;
	virtual void __fastcall RestoreState(void);
	virtual void __fastcall SaveState(void);
	void __fastcall CreateTreeContainer(void);
	virtual void __fastcall InitializeTreeContainer(void);
	virtual void __fastcall ProcessKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall ProcessKeyPress(System::WideChar &Key);
	__property TdxPSExplorerTreeChangeNotifier* ChangeNotifier = {read=FChangeNotifier};
	__property _di_IdxPSExplorerTreeContainerHost Host = {read=FHost};
	
public:
	__fastcall virtual TCustomdxPSExplorerTreeContainer(TCustomdxPSExplorer* AnExplorer, _di_IdxPSExplorerTreeContainerHost AHost);
	__fastcall virtual ~TCustomdxPSExplorerTreeContainer(void);
	__classmethod virtual Vcl::Controls::TWinControlClass __fastcall ControlClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall EndUpdate(void);
	virtual bool __fastcall BeginEdit(bool AnImmediate = true) = 0 ;
	virtual void __fastcall EndEdit(bool ACancel) = 0 ;
	virtual void __fastcall CollapseItem(TCustomdxPSExplorerItem* AnItem, bool ARecursive = false) = 0 ;
	virtual void __fastcall ExpandItem(TCustomdxPSExplorerItem* AnItem, bool ARecursive = false) = 0 ;
	virtual void __fastcall ItemDataLoaded(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall ItemDataUnloaded(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual void __fastcall MakeItemVisible(TCustomdxPSExplorerItem* AnItem) = 0 ;
	virtual bool __fastcall CanCreateFolder(void);
	virtual bool __fastcall CanCreateItem(void);
	virtual bool __fastcall CanDeleteSelection(void);
	virtual bool __fastcall CanLoadSelectedItemData(void);
	virtual bool __fastcall CanRefresh(void);
	virtual bool __fastcall CanRenameSelectedItem(void);
	virtual bool __fastcall CanShowPropertySheetsForSelectedItem(void);
	virtual bool __fastcall CanUnloadItemData(void);
	virtual TdxPSExplorerItem* __fastcall CreateItem(void);
	virtual void __fastcall DeleteSelection(bool AShowMessage = true);
	bool __fastcall IsSelectedItemCurrentlyLoaded(void);
	virtual void __fastcall LoadSelectedItemData(void);
	virtual void __fastcall RenameSelectedItem(void);
	bool __fastcall ShowSelectedItemPropertySheets(void);
	virtual void __fastcall UnloadItemData(void);
	virtual TdxPSExplorerFolder* __fastcall GetDropTarget(int X, int Y) = 0 ;
	virtual TCustomdxPSExplorerItem* __fastcall GetItemAt(int X, int Y) = 0 ;
	virtual bool __fastcall CanFocus(void);
	virtual void __fastcall SetFocus(void);
	virtual void __fastcall RefreshSorting(System::TObject* ANode)/* overload */;
	virtual void __fastcall RefreshSorting(TdxPSExplorerFolder* AFolder)/* overload */;
	__property Vcl::Controls::TWinControl* Control = {read=FControl};
	__property TdxPSExplorerFolder* CreationParent = {read=GetCreationParent};
	__property TCustomdxPSExplorer* Explorer = {read=FExplorer};
	__property TCustomdxPSExplorerItem* FocusedItem = {read=GetFocusedItem, write=SetFocusedItem};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property bool IsFolderSelected = {read=GetIsFolderSelected, nodefault};
	__property bool IsItemSelected = {read=GetIsItemSelected, nodefault};
	__property bool IsRootSelected = {read=GetIsRootSelected, nodefault};
	__property TdxPSExplorerFolder* SelectedFolder = {read=GetSelectedFolder};
	__property TCustomdxPSExplorerItem* SelectedItem = {read=GetSelectedItem, write=SetSelectedItem};
	__property System::UnicodeString SelectedItemText = {read=GetSelectedItemText, write=SetSelectedItemText};
};


typedef System::TMetaClass* TdxPSExplorerTreeBuilderClass;

class DELPHICLASS TdxPSExplorerTreeBuilder;
class PASCALIMPLEMENTATION TdxPSExplorerTreeBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall BuildTree(TCustomdxPSExplorer* AnExplorer, TCustomdxPSExplorerTreeContainer* ATreeContainer);
	__classmethod virtual void __fastcall CreateFolderNode(TCustomdxPSExplorerTreeContainer* ATreeContainer, TdxPSExplorerFolder* AParent, TdxPSExplorerFolder* AFolder);
	__classmethod virtual void __fastcall CreateItemNode(TCustomdxPSExplorerTreeContainer* ATreeContainer, TdxPSExplorerFolder* AParent, TCustomdxPSExplorerItem* AnItem);
	__classmethod virtual void __fastcall PopulateTreeFolder(TCustomdxPSExplorerTreeContainer* ATreeContainer, TdxPSExplorerFolder* AFolder);
	
public:
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
public:
	/* TObject.Create */ inline __fastcall TdxPSExplorerTreeBuilder(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSExplorerTreeBuilder(void) { }
	
};


enum TdxPSStreamMode : unsigned char { smRead, smWrite, smReadWrite };

typedef System::TMetaClass* TCustomdxPSExplorerItemPropertySheetsClass;

class DELPHICLASS TCustomdxPSExplorerItemPropertySheets;
class PASCALIMPLEMENTATION TCustomdxPSExplorerItemPropertySheets : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
private:
	TCustomdxPSExplorerItem* FExplorerItem;
	__classmethod TCustomdxPSExplorerItemPropertySheetsClass __fastcall FormClass();
	
protected:
	virtual void __fastcall Done(void);
	virtual void __fastcall Initialize(void);
	
public:
	__fastcall virtual TCustomdxPSExplorerItemPropertySheets(TCustomdxPSExplorerItem* AnExplorerItem);
	__classmethod bool __fastcall Execute(TCustomdxPSExplorerItem* AnExplorerItem);
	virtual TCustomdxPSExplorerItem* __fastcall ExplorerItem(void)/* overload */;
public:
	/* TCustomForm.Create */ inline __fastcall virtual TCustomdxPSExplorerItemPropertySheets(System::Classes::TComponent* AOwner) : Dxpsform::TCustomdxPSForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCustomdxPSExplorerItemPropertySheets(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCustomdxPSExplorerItemPropertySheets(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomdxPSExplorerItemPropertySheets(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


class DELPHICLASS TCustomdxPSExplorerItemComparator;
class PASCALIMPLEMENTATION TCustomdxPSExplorerItemComparator : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod int __fastcall CompareItems(void * AnItem1, void * AnItem2);
public:
	/* TObject.Create */ inline __fastcall TCustomdxPSExplorerItemComparator(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomdxPSExplorerItemComparator(void) { }
	
};


class DELPHICLASS TCustomdxPSExplorerItemHelper;
class PASCALIMPLEMENTATION TCustomdxPSExplorerItemHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod virtual bool __fastcall GetHasChildren(TdxPSExplorerFolder* AFolder);
	__classmethod virtual int __fastcall GetImageIndex(TCustomdxPSExplorerItem* AnItem);
	__classmethod virtual int __fastcall GetSelectedIndex(TCustomdxPSExplorerItem* AnItem);
	__classmethod virtual void __fastcall SetHasChildren(TdxPSExplorerFolder* AFolder, bool Value);
public:
	/* TObject.Create */ inline __fastcall TCustomdxPSExplorerItemHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomdxPSExplorerItemHelper(void) { }
	
};


typedef System::TMetaClass* TCustomdxPSExplorerItemClass;

class PASCALIMPLEMENTATION TCustomdxPSExplorerItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TCustomdxPSExplorer* FExplorer;
	System::UnicodeString FName;
	TdxPSExplorerFolder* FParent;
	HWND FWindowHandle;
	void __fastcall SetParent(TdxPSExplorerFolder* Value);
	
protected:
	virtual int __fastcall CompareTo(TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall DoDelete(void);
	virtual bool __fastcall DoMove(TdxPSExplorerFolder* AParent);
	virtual bool __fastcall DoRename(System::UnicodeString &ANewName);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual int __fastcall GetImageIndex(void);
	virtual System::UnicodeString __fastcall GetInfoTip(void);
	virtual System::UnicodeString __fastcall GetNewName(TBasedxReportLink* AReportLink);
	virtual int __fastcall GetSelectedIndex(void);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalMove(TdxPSExplorerFolder* AParent);
	virtual void __fastcall InternalRename(const System::UnicodeString AName);
	virtual void __fastcall SetName(const System::UnicodeString Value);
	virtual TCustomdxPSExplorerItemStateInfo __fastcall GetItemStateInfo(void);
	virtual void __fastcall WriteState(System::Classes::TStream* AStream);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TCustomdxPSExplorerItem(TCustomdxPSExplorer* AnExplorer, TdxPSExplorerFolder* AParent);
	__fastcall virtual ~TCustomdxPSExplorerItem(void);
	virtual TCustomdxPSExplorer* __fastcall Explorer(void)/* overload */;
	virtual bool __fastcall CanAccept(TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanMove(void);
	virtual bool __fastcall CanMoveTo(TCustomdxPSExplorerItem* AParent)/* overload */;
	virtual bool __fastcall CanRename(void);
	virtual bool __fastcall CanRenameTo(const System::UnicodeString AName);
	virtual void __fastcall Delete(void);
	virtual int __fastcall GetUniqueID(/* out */ System::DynamicArray<System::Byte> &AnUniqueID);
	bool __fastcall HasAsParent(TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall IsNameChanged(const System::UnicodeString ANewName);
	__classmethod bool __fastcall HasPropertySheets();
	__classmethod virtual TCustomdxPSExplorerItemPropertySheetsClass __fastcall PropertySheetsClass();
	bool __fastcall ShowPropertySheets(void);
	virtual System::UnicodeString __fastcall CannotRenameMessageText(const System::UnicodeString AOldName, const System::UnicodeString ANewName);
	virtual System::UnicodeString __fastcall DeleteMessageText(void);
	virtual System::UnicodeString __fastcall OverwriteMessageText(TCustomdxPSExplorerItem* Dest);
	__property System::UnicodeString DisplayName = {read=GetDisplayName};
	__property System::UnicodeString InfoTip = {read=GetInfoTip};
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property TdxPSExplorerFolder* Parent = {read=FParent, write=SetParent};
};


class DELPHICLASS TdxPSExplorerFolderHelper;
class PASCALIMPLEMENTATION TdxPSExplorerFolderHelper : public TCustomdxPSExplorerItemHelper
{
	typedef TCustomdxPSExplorerItemHelper inherited;
	
public:
	__classmethod virtual bool __fastcall GetHasChildren(TdxPSExplorerFolder* AFolder);
	__classmethod virtual void __fastcall SetHasChildren(TdxPSExplorerFolder* AFolder, bool Value);
public:
	/* TObject.Create */ inline __fastcall TdxPSExplorerFolderHelper(void) : TCustomdxPSExplorerItemHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSExplorerFolderHelper(void) { }
	
};


typedef System::TMetaClass* TdxPSExplorerFolderClass;

class PASCALIMPLEMENTATION TdxPSExplorerFolder : public TCustomdxPSExplorerItem
{
	typedef TCustomdxPSExplorerItem inherited;
	
public:
	TdxPSExplorerFolder* operator[](int Index) { return Folders[Index]; }
	
private:
	System::Classes::TList* FFolders;
	bool FHasChildren;
	System::Classes::TList* FItems;
	TdxPSExplorerFolder* __fastcall GetFolder(int Index);
	int __fastcall GetFolderCount(void);
	bool __fastcall GetHasChildren(void);
	bool __fastcall GetIsRoot(void);
	TdxPSExplorerItem* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	System::Classes::TList* __fastcall GetItemList(TCustomdxPSExplorerItem* AnItem)/* overload */;
	System::Classes::TList* __fastcall GetItemList(TCustomdxPSExplorerItemClass AnItemClass)/* overload */;
	void __fastcall SetHasChildren(bool Value);
	
protected:
	virtual int __fastcall CompareTo(TCustomdxPSExplorerItem* AnItem);
	virtual int __fastcall GetImageIndex(void);
	virtual System::UnicodeString __fastcall GetNewName(TBasedxReportLink* AReportLink);
	virtual int __fastcall GetSelectedIndex(void);
	virtual TCustomdxPSExplorerItemStateInfo __fastcall GetItemStateInfo(void);
	virtual void __fastcall WriteState(System::Classes::TStream* AStream);
	virtual void __fastcall LoadData(void);
	void __fastcall Add(TCustomdxPSExplorerItem* AnItem);
	void __fastcall Remove(TCustomdxPSExplorerItem* AnItem);
	void __fastcall FreeAndNilFolders(void);
	void __fastcall FreeAndNilItems(void);
	__property bool HasChildren = {read=GetHasChildren, write=SetHasChildren, nodefault};
	
public:
	__fastcall virtual TdxPSExplorerFolder(TCustomdxPSExplorer* AnExplorer, TdxPSExplorerFolder* AParent);
	__fastcall virtual ~TdxPSExplorerFolder(void);
	virtual bool __fastcall CanAccept(TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall CanRenameTo(const System::UnicodeString AName);
	virtual TdxPSExplorerFolder* __fastcall CreateFolder(void);
	virtual TdxPSExplorerItem* __fastcall CreateItem(TBasedxReportLink* AReportLink);
	void __fastcall Populate(void);
	virtual void __fastcall Delete(void);
	virtual void __fastcall DeleteFolders(void);
	virtual void __fastcall DeleteItems(void);
	virtual bool __fastcall HasFolders(void);
	virtual bool __fastcall HasItems(void);
	virtual bool __fastcall HasLoadedItem(void);
	virtual TdxPSExplorerFolder* __fastcall FolderByName(const System::UnicodeString AName);
	virtual TdxPSExplorerItem* __fastcall ItemByName(const System::UnicodeString AName);
	virtual System::UnicodeString __fastcall CannotRenameMessageText(const System::UnicodeString AOldName, const System::UnicodeString ANewName);
	virtual System::UnicodeString __fastcall DeleteMessageText(void);
	virtual System::UnicodeString __fastcall OverwriteMessageText(TCustomdxPSExplorerItem* Dest);
	__property int FolderCount = {read=GetFolderCount, nodefault};
	__property TdxPSExplorerFolder* Folders[int Index] = {read=GetFolder/*, default*/};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxPSExplorerItem* Items[int Index] = {read=GetItem};
};


typedef System::TMetaClass* TdxPSExplorerItemClass;

class DELPHICLASS TdxPSReportDocument;
class PASCALIMPLEMENTATION TdxPSExplorerItem : public TCustomdxPSExplorerItem
{
	typedef TCustomdxPSExplorerItem inherited;
	
private:
	bool FHasInvalidData;
	TdxPSReportDocument* FReportDocument;
	bool __fastcall GetIsCurrentlyLoaded(void);
	void __fastcall SetHasInvalidData(bool Value);
	
protected:
	virtual int __fastcall CompareTo(TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall DoDelete(void);
	virtual System::UnicodeString __fastcall GetFormCaption(void);
	virtual int __fastcall GetImageIndex(void);
	virtual System::UnicodeString __fastcall GetInfoTip(void);
	virtual System::UnicodeString __fastcall GetNewName(TBasedxReportLink* AReportLink);
	virtual int __fastcall GetSelectedIndex(void);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall DocumentChanged(System::TObject* Sender);
	virtual void __fastcall SaveDocument(void);
	virtual void __fastcall SetReportData(TBasedxReportLink* AReportLink);
	__property System::UnicodeString FormCaption = {read=GetFormCaption};
	
public:
	__fastcall virtual TdxPSExplorerItem(TCustomdxPSExplorer* AnExplorer, TdxPSExplorerFolder* AParent);
	__fastcall virtual ~TdxPSExplorerItem(void);
	virtual bool __fastcall CanLoadData(void);
	virtual bool __fastcall CanRenameTo(const System::UnicodeString AName);
	virtual System::UnicodeString __fastcall CannotRenameMessageText(const System::UnicodeString AOldName, const System::UnicodeString ANewName);
	virtual System::UnicodeString __fastcall DataLoadErrorText(void);
	virtual System::UnicodeString __fastcall DeleteMessageText(void);
	virtual System::UnicodeString __fastcall OverwriteMessageText(TCustomdxPSExplorerItem* Dest);
	virtual System::Classes::TStream* __fastcall CreateDataStream(TdxPSStreamMode AMode);
	virtual void __fastcall RetrieveReportData(TBasedxReportLink* AReportLink);
	virtual bool __fastcall IsLoading(void);
	void __fastcall Load(TBasedxReportLink* AReportLink);
	void __fastcall Unload(void);
	__classmethod virtual TCustomdxPSExplorerItemPropertySheetsClass __fastcall PropertySheetsClass();
	__property bool HasInvalidData = {read=FHasInvalidData, write=SetHasInvalidData, nodefault};
	__property bool IsCurrentlyLoaded = {read=GetIsCurrentlyLoaded, nodefault};
	__property TdxPSReportDocument* ReportDocument = {read=FReportDocument};
};


typedef System::TMetaClass* TCustomdxPSExplorerContextCommandClass;

class PASCALIMPLEMENTATION TCustomdxPSExplorerContextCommand : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Cxgraphics::TcxBitmap* FBitmap;
	System::UnicodeString FCaption;
	void *FData;
	TCustomdxPSExplorer* FExplorer;
	System::UnicodeString FHint;
	System::Classes::TShortCut FShortCut;
	void __fastcall SetBitmap(Cxgraphics::TcxBitmap* Value);
	
public:
	__fastcall virtual TCustomdxPSExplorerContextCommand(TCustomdxPSExplorer* AnExplorer);
	__fastcall virtual ~TCustomdxPSExplorerContextCommand(void);
	virtual bool __fastcall Enabled(void);
	virtual TCustomdxPSExplorer* __fastcall Explorer(void)/* overload */;
	virtual void __fastcall Execute(void);
	__property Cxgraphics::TcxBitmap* Bitmap = {read=FBitmap, write=SetBitmap};
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property void * Data = {read=FData, write=FData};
	__property System::UnicodeString Hint = {read=FHint, write=FHint};
	__property System::Classes::TShortCut ShortCut = {read=FShortCut, write=FShortCut, nodefault};
};


class DELPHICLASS TdxPSExplorerContextCommandSeparator;
class PASCALIMPLEMENTATION TdxPSExplorerContextCommandSeparator : public TCustomdxPSExplorerContextCommand
{
	typedef TCustomdxPSExplorerContextCommand inherited;
	
public:
	__fastcall virtual TdxPSExplorerContextCommandSeparator(TCustomdxPSExplorer* AnExplorer);
	virtual bool __fastcall Enabled(void);
public:
	/* TCustomdxPSExplorerContextCommand.Destroy */ inline __fastcall virtual ~TdxPSExplorerContextCommandSeparator(void) { }
	
};


class DELPHICLASS TdxPSExplorerRefreshContextCommand;
class PASCALIMPLEMENTATION TdxPSExplorerRefreshContextCommand : public TCustomdxPSExplorerContextCommand
{
	typedef TCustomdxPSExplorerContextCommand inherited;
	
public:
	__fastcall virtual TdxPSExplorerRefreshContextCommand(TCustomdxPSExplorer* AnExplorer);
	virtual void __fastcall Execute(void);
public:
	/* TCustomdxPSExplorerContextCommand.Destroy */ inline __fastcall virtual ~TdxPSExplorerRefreshContextCommand(void) { }
	
};


enum TdxPSExplorerState : unsigned char { esItemCreating, esFolderCreating, esLoading, esRefreshing };

typedef System::Set<TdxPSExplorerState, TdxPSExplorerState::esItemCreating, TdxPSExplorerState::esRefreshing>  TdxPSExplorerStates;

typedef void __fastcall (__closure *TdxPSExplorerItemDataLoadErrorEvent)(TCustomdxPSExplorer* Sender, TdxPSExplorerItem* AnItem, bool &AShowErrorMessage, System::UnicodeString &AText);

typedef System::TMetaClass* TdxPSExplorerClass;

class PASCALIMPLEMENTATION TCustomdxPSExplorer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TdxPSExplorerFolder* FActiveFolder;
	System::Classes::TList* FCommands;
	System::Classes::TComponentClass FFilterLinkClass;
	System::UnicodeString FFilterLinkClassName;
	TdxPSExplorerItem* FLoadedItem;
	int FLoadingCounter;
	int FLockCounter;
	System::Classes::TList* FNotifiers;
	int FRefreshCounter;
	TdxPSExplorerFolder* FRoot;
	TdxPSExplorerStates FState;
	System::Classes::TStream* FStateStream;
	TdxPSExplorerItemDataLoadErrorEvent FOnItemDataLoadError;
	TCustomdxPSExplorerContextCommand* __fastcall GetCommand(int Index);
	int __fastcall GetCommandCount(void);
	TdxPSExplorerChangeNotifier* __fastcall GetNotifier(int Index);
	int __fastcall GetNotifierCount(void);
	TdxPSExplorerFolder* __fastcall GetRoot(void);
	void __fastcall SetFilterLink(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall BuildCommandSet(_di_IdxPSExplorerContextCommandBuilder ABuilder);
	virtual void __fastcall FinalizeCommand(TCustomdxPSExplorerContextCommand* ACommand);
	virtual void __fastcall InitializeCommand(TCustomdxPSExplorerContextCommand* ACommand);
	TCustomdxPSExplorerContextCommand* __fastcall AddCommand(TCustomdxPSExplorerContextCommandClass ACommandClass);
	TdxPSExplorerContextCommandSeparator* __fastcall AddCommandSeparator(void);
	void __fastcall ClearCommands(void);
	TCustomdxPSExplorerContextCommand* __fastcall CreateCommand(TCustomdxPSExplorerContextCommandClass ACommandClass);
	TdxPSExplorerContextCommandSeparator* __fastcall CreateCommandSeparator(void);
	TCustomdxPSExplorerContextCommand* __fastcall FindCommand(TCustomdxPSExplorerContextCommandClass ACommandClass);
	void __fastcall FreeAndNilCommands(void);
	__classmethod virtual bool __fastcall AcceptItemNameChar(TCustomdxPSExplorerItem* AnItem, System::WideChar Ch);
	virtual System::Classes::TStream* __fastcall CreateItemDataStream(TdxPSExplorerItem* AnItem, TdxPSStreamMode AMode) = 0 ;
	__classmethod virtual TdxPSExplorerFolderClass __fastcall GetFolderClass();
	__classmethod virtual TdxPSExplorerItemClass __fastcall GetItemClass();
	__classmethod virtual TdxPSExplorerFolderClass __fastcall GetRootFolderClass();
	virtual System::UnicodeString __fastcall GetRootDisplayName(void);
	void __fastcall LoadData(TdxPSExplorerFolder* AFolder);
	virtual bool __fastcall CanDelete(TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall CanMove(TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall CanMoveTo(TCustomdxPSExplorerItem* AnItem, TCustomdxPSExplorerItem* AParent);
	virtual bool __fastcall CanRename(TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall CanRenameTo(TCustomdxPSExplorerItem* AnItem, const System::UnicodeString AName);
	virtual void __fastcall Delete(TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall MoveTo(TCustomdxPSExplorerItem* AnItem, TdxPSExplorerFolder* AParent);
	virtual void __fastcall PopulateFolder(TdxPSExplorerFolder* AFolder);
	virtual void __fastcall RenameTo(TCustomdxPSExplorerItem* AnItem, System::UnicodeString AName);
	void __fastcall AfterRefresh(void);
	void __fastcall BeforeRefresh(void);
	virtual void __fastcall DoRefresh(void);
	void __fastcall RootNeeded(void);
	DYNAMIC void __fastcall DoItemDataLoadError(TdxPSExplorerItem* AnItem);
	virtual void __fastcall DoLoadData(TdxPSExplorerFolder* AFolder) = 0 ;
	void __fastcall InternalSetLoadedItem(TdxPSExplorerItem* Value);
	void __fastcall PopulateTreeFolder(TCustomdxPSExplorerTreeContainer* ATreeContainer, TdxPSExplorerFolder* AFolder);
	void __fastcall LoadState(void);
	void __fastcall SaveState(void);
	void __fastcall NotifyFolderPopulated(TdxPSExplorerFolder* AFolder);
	void __fastcall NotifyItemAdded(TCustomdxPSExplorerItem* AnItem);
	void __fastcall NotifyItemDataLoaded(TdxPSExplorerItem* AnItem);
	void __fastcall NotifyItemDataUnloaded(TdxPSExplorerItem* AnItem);
	void __fastcall NotifyItemDeleted(TCustomdxPSExplorerItem* AnItem);
	void __fastcall NotifyItemParentChanged(TCustomdxPSExplorerItem* AnItem);
	void __fastcall NotifyItemPropertiesChanged(TCustomdxPSExplorerItem* AnItem);
	void __fastcall NotifyItemRenamed(TCustomdxPSExplorerItem* AnItem);
	void __fastcall NotifyRefresh(TdxPSExplorerRefreshStage AStage);
	bool __fastcall AreNotificationsLocked(void);
	int __fastcall IndexOfNotifier(TdxPSExplorerChangeNotifier* ANotifier);
	void __fastcall LockNotifications(void);
	void __fastcall ReleaseAndNilNotifiers(void);
	void __fastcall UnlockNotifications(void);
	void __fastcall BeginLoading(void);
	void __fastcall EndLoading(void);
	bool __fastcall IsLoading(void);
	__property int CommandCount = {read=GetCommandCount, nodefault};
	__property TCustomdxPSExplorerContextCommand* Commands[int Index] = {read=GetCommand};
	__property int NotifierCount = {read=GetNotifierCount, nodefault};
	__property TdxPSExplorerChangeNotifier* Notifiers[int Index] = {read=GetNotifier};
	
public:
	__fastcall virtual TCustomdxPSExplorer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxPSExplorer(void);
	virtual TdxPSExplorerItem* __fastcall LoadedItem(void)/* overload */;
	virtual bool __fastcall CanCreateFolder(void);
	virtual bool __fastcall CanCreateItem(void);
	virtual TdxPSExplorerFolder* __fastcall CreateNewFolder(TdxPSExplorerFolder* AParent);
	virtual TdxPSExplorerItem* __fastcall CreateNewItem(TdxPSExplorerFolder* AParent, TBasedxReportLink* AReportLink);
	void __fastcall BuildTree(TCustomdxPSExplorerTreeContainer* ATreeContainer);
	TCustomdxPSExplorerTreeContainer* __fastcall CreateTree(const _di_IdxPSExplorerTreeContainerHost AHost);
	virtual TCustomdxPSExplorerItem* __fastcall FindCustomItemByUniqueID(const System::DynamicArray<System::Byte> AnUniqueID);
	void __fastcall LoadItemData(TdxPSExplorerItem* AnItem, TBasedxReportLink* AReportLink)/* overload */;
	void __fastcall UnloadItemData(TdxPSExplorerItem* AnItem)/* overload */;
	virtual void __fastcall Refresh(void);
	void __fastcall RegisterNotifier(TdxPSExplorerChangeNotifier* ANotifier);
	void __fastcall UnregisterNotifier(TdxPSExplorerChangeNotifier* ANotifier);
	__property TdxPSExplorerFolder* ActiveFolder = {read=FActiveFolder, write=FActiveFolder};
	__property System::Classes::TComponentClass FilterLinkClass = {read=FFilterLinkClass, write=FFilterLinkClass};
	__property System::UnicodeString FilterLinkClassName = {read=FFilterLinkClassName, write=FFilterLinkClassName};
	__property TdxPSExplorerFolder* Root = {read=GetRoot};
	__property TdxPSExplorerStates State = {read=FState, nodefault};
	
__published:
	__property System::UnicodeString FilterLink = {read=FFilterLinkClassName, write=SetFilterLink};
	__property TdxPSExplorerItemDataLoadErrorEvent OnItemDataLoadError = {read=FOnItemDataLoadError, write=FOnItemDataLoadError};
private:
	void *__IdxPSExplorerContextCommands2;	/* IdxPSExplorerContextCommands2 */
	void *__IdxPSExplorerContextCommands;	/* IdxPSExplorerContextCommands */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E4D68CF3-AD07-4220-B892-92C8F9B3F966}
	operator _di_IdxPSExplorerContextCommands2()
	{
		_di_IdxPSExplorerContextCommands2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxPSExplorerContextCommands2*(void) { return (IdxPSExplorerContextCommands2*)&__IdxPSExplorerContextCommands2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {DC3A582D-7E33-410F-A235-680A846824D3}
	operator _di_IdxPSExplorerContextCommands()
	{
		_di_IdxPSExplorerContextCommands intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxPSExplorerContextCommands*(void) { return (IdxPSExplorerContextCommands*)&__IdxPSExplorerContextCommands; }
	#endif
	
};


class DELPHICLASS TdxReportNote;
class PASCALIMPLEMENTATION TdxReportNote : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FAdjustOnReportScale;
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FDefaultFont;
	Vcl::Graphics::TFont* FFont;
	bool FHasChanged;
	TBasedxReportLink* FReportLink;
	System::UnicodeString FText;
	Cxdrawtextutils::TcxTextAlignX FTextAlignX;
	Cxdrawtextutils::TcxTextAlignY FTextAlignY;
	bool FTransparent;
	int FUpdateCount;
	bool __fastcall IsFontStored(void);
	void __fastcall SetAdjustOnReportScale(bool Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetText(const System::UnicodeString Value);
	void __fastcall SetTextAlignX(Cxdrawtextutils::TcxTextAlignX Value);
	void __fastcall SetTextAlignY(Cxdrawtextutils::TcxTextAlignY Value);
	
protected:
	void __fastcall CalculateRenderInfos(void);
	virtual void __fastcall Changed(void);
	virtual void __fastcall DoRestoreDefaults(void);
	void __fastcall FontChanged(System::TObject* Sender);
	virtual void __fastcall InitializeDefaultFont(Vcl::Graphics::TFont* AFont);
	virtual void __fastcall DoCustomDraw(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone) = 0 ;
	virtual bool __fastcall IsCustomDrawn(void) = 0 ;
	virtual void __fastcall Draw(TdxPSReportRenderer* ARenderer, const System::Types::TRect &R);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall ReadMode(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	virtual void __fastcall WriteMode(TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TdxReportNote(TBasedxReportLink* AReportLink);
	__fastcall virtual ~TdxReportNote(void);
	virtual Vcl::Graphics::TFont* __fastcall DefaultFont(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall RestoreDefaults(bool ARefresh = true);
	__property bool AdjustOnReportScale = {read=FAdjustOnReportScale, write=SetAdjustOnReportScale, default=0};
	__property System::Uitypes::TColor Color = {read=FColor, write=FColor, default=16777215};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property TBasedxReportLink* ReportLink = {read=FReportLink};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property Cxdrawtextutils::TcxTextAlignX TextAlignX = {read=FTextAlignX, write=SetTextAlignX, default=1};
	__property Cxdrawtextutils::TcxTextAlignY TextAlignY = {read=FTextAlignY, write=SetTextAlignY, default=1};
	__property bool Transparent = {read=FTransparent, write=FTransparent, default=1};
};


enum TdxReportTitleMode : unsigned char { tmNone, tmOnFirstPage, tmOnEveryTopPage };

class DELPHICLASS TdxReportTitle;
class PASCALIMPLEMENTATION TdxReportTitle : public TdxReportNote
{
	typedef TdxReportNote inherited;
	
private:
	TdxReportTitleMode FMode;
	void __fastcall SetMode(TdxReportTitleMode Value);
	
protected:
	virtual void __fastcall DoRestoreDefaults(void);
	virtual void __fastcall ReadMode(TdxPSDataReader* AReader);
	virtual void __fastcall WriteMode(TdxPSDataWriter* AWriter);
	virtual void __fastcall DoCustomDraw(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone);
	virtual bool __fastcall IsCustomDrawn(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property AdjustOnReportScale = {default=0};
	__property Color = {default=16777215};
	__property Font;
	__property TdxReportTitleMode Mode = {read=FMode, write=SetMode, default=2};
	__property Text = {default=0};
	__property TextAlignX = {default=1};
	__property TextAlignY = {default=1};
	__property Transparent = {default=1};
public:
	/* TdxReportNote.Create */ inline __fastcall virtual TdxReportTitle(TBasedxReportLink* AReportLink) : TdxReportNote(AReportLink) { }
	/* TdxReportNote.Destroy */ inline __fastcall virtual ~TdxReportTitle(void) { }
	
};


enum TdxReportFootnoteMode : unsigned char { fnmNone, fnmOnLastPage, fnmOnEveryBottomPage };

class DELPHICLASS TdxReportFootnotes;
class PASCALIMPLEMENTATION TdxReportFootnotes : public TdxReportNote
{
	typedef TdxReportNote inherited;
	
private:
	TdxReportFootnoteMode FMode;
	void __fastcall SetMode(TdxReportFootnoteMode Value);
	
protected:
	virtual void __fastcall DoRestoreDefaults(void);
	virtual void __fastcall ReadMode(TdxPSDataReader* AReader);
	virtual void __fastcall WriteMode(TdxPSDataWriter* AWriter);
	virtual void __fastcall DoCustomDraw(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone);
	virtual bool __fastcall IsCustomDrawn(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property AdjustOnReportScale = {default=0};
	__property Color = {default=16777215};
	__property Font;
	__property TdxReportFootnoteMode Mode = {read=FMode, write=SetMode, default=2};
	__property Text = {default=0};
	__property TextAlignX = {default=1};
	__property TextAlignY = {default=1};
	__property Transparent = {default=1};
public:
	/* TdxReportNote.Create */ inline __fastcall virtual TdxReportFootnotes(TBasedxReportLink* AReportLink) : TdxReportNote(AReportLink) { }
	/* TdxReportNote.Destroy */ inline __fastcall virtual ~TdxReportFootnotes(void) { }
	
};


typedef System::TMetaClass* TdxPSReportDocumentClass;

class PASCALIMPLEMENTATION TdxPSReportDocument : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FCaption;
	System::TDateTime FCreationDate;
	System::UnicodeString FCreator;
	System::UnicodeString FDescription;
	bool FIsCaptionAssigned;
	bool FIsCreatorAssigned;
	bool FIsDescriptionAssigned;
	Vcl::Graphics::TMetafile* FPreview;
	TBasedxReportLink* FReportLink;
	int FUpdateCount;
	System::Classes::TNotifyEvent FOnChanged;
	System::UnicodeString __fastcall GetCaption(void);
	System::UnicodeString __fastcall GetCreator(void);
	System::UnicodeString __fastcall GetDescription(void);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsCreatorStored(void);
	bool __fastcall IsDesciptionStored(void);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetCreationDate(const System::TDateTime Value);
	void __fastcall SetCreator(const System::UnicodeString Value);
	void __fastcall SetDescription(const System::UnicodeString Value);
	void __fastcall ReadIsCaptionAssigned(System::Classes::TReader* Reader);
	void __fastcall ReadIsCreatorAssigned(System::Classes::TReader* Reader);
	void __fastcall ReadIsDescriptionAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteIsCaptionAssigned(System::Classes::TWriter* Writer);
	void __fastcall WriteIsCreatorAssigned(System::Classes::TWriter* Writer);
	void __fastcall WriteIsDescriptionAssigned(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Changed(void);
	virtual void __fastcall DoAssign(TdxPSReportDocument* Source);
	virtual void __fastcall DoRestoreDefaults(void);
	virtual System::UnicodeString __fastcall GetInfoTip(void);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property int UpdateCount = {read=FUpdateCount, write=FUpdateCount, nodefault};
	
public:
	__fastcall virtual TdxPSReportDocument(TBasedxReportLink* AReportLink);
	__fastcall virtual ~TdxPSReportDocument(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	bool __fastcall IsUpdateLocked(void);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual System::UnicodeString __fastcall DefaultCreator(void);
	virtual System::UnicodeString __fastcall DefaultDescription(void);
	void __fastcall RestoreDefaults(void);
	virtual void __fastcall RetrievePreview(void);
	__property System::UnicodeString InfoTip = {read=GetInfoTip};
	__property Vcl::Graphics::TMetafile* Preview = {read=FPreview};
	__property TBasedxReportLink* ReportLink = {read=FReportLink};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property System::TDateTime CreationDate = {read=FCreationDate, write=SetCreationDate};
	__property System::UnicodeString Creator = {read=GetCreator, write=SetCreator, stored=IsCreatorStored};
	__property System::UnicodeString Description = {read=GetDescription, write=SetDescription, stored=IsDesciptionStored};
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPSDataStorageOffsetTableInfo
{
public:
	int Information;
	int Document;
	int Title;
	int Data;
	int Footnotes;
	int Reserved1;
	int Reserved2;
	int Reserved3;
};
#pragma pack(pop)


class DELPHICLASS TdxPSDataStorageOffsetTable;
class PASCALIMPLEMENTATION TdxPSDataStorageOffsetTable : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TdxPSDataStorageOffsetTableInfo FTableInfo;
	virtual void __fastcall DoAssign(TdxPSDataStorageOffsetTable* Source);
	
public:
	__fastcall virtual TdxPSDataStorageOffsetTable(TdxPSDataStorageOffsetTable* ATemplate);
	virtual void __fastcall Assign(TdxPSDataStorageOffsetTable* Source);
	virtual void __fastcall Clear(void);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__property int Information = {read=FTableInfo.Information, write=FTableInfo.Information, nodefault};
	__property int Document = {read=FTableInfo.Document, write=FTableInfo.Document, nodefault};
	__property int Title = {read=FTableInfo.Title, write=FTableInfo.Title, nodefault};
	__property int Data = {read=FTableInfo.Data, write=FTableInfo.Data, nodefault};
	__property int Footnotes = {read=FTableInfo.Footnotes, write=FTableInfo.Footnotes, nodefault};
	__property int Reserved1 = {read=FTableInfo.Reserved1, write=FTableInfo.Reserved1, nodefault};
	__property int Reserved2 = {read=FTableInfo.Reserved2, write=FTableInfo.Reserved2, nodefault};
	__property int Reserved3 = {read=FTableInfo.Reserved3, write=FTableInfo.Reserved3, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSDataStorageOffsetTable(void) { }
	
};


typedef System::TMetaClass* TdxPSDataStorageOffsetTableClass;

typedef TdxPSDataStorageOffsetTable PdxPSDataStorageOffsetTable;

class DELPHICLASS TdxPSDataStorageInfo;
class PASCALIMPLEMENTATION TdxPSDataStorageInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int StorageVersion;
	Dxpsglbl::TdxPSVersion PrintingSystemVersion;
	System::SmallString<255>  LinkClassName;
	System::SmallString<255>  ComponentClassName;
	TdxReportLinkClass LinkClass;
	System::Classes::TComponentClass ComponentClass;
	__fastcall virtual TdxPSDataStorageInfo(TBasedxReportLink* AReportLink);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSDataStorageInfo(void) { }
	
};


typedef System::TMetaClass* TdxPSDataStorageInfoClass;

typedef TdxPSDataStorageInfo PdxPSDataStorageInfo;

enum TdxAssignedFormatValue : unsigned char { fvDate, fvTime, fvPageNumber };

typedef System::Set<TdxAssignedFormatValue, TdxAssignedFormatValue::fvDate, TdxAssignedFormatValue::fvPageNumber>  TdxAssignedFormatValues;

enum TdxReportLinkState : unsigned char { rlsDataLoading, rlsDataSaving };

typedef System::Set<TdxReportLinkState, TdxReportLinkState::rlsDataLoading, TdxReportLinkState::rlsDataSaving>  TdxReportLinkStates;

enum TdxReportLinkDataSource : unsigned char { rldsComponent, rldsExternalStorage };

typedef void __fastcall (__closure *TdxCustomDrawReportLinkTitleEvent)(TBasedxReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, int ANom, int ADenom, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone);

typedef void __fastcall (__closure *TdxCustomDrawReportLinkHFEvent)(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, int APageIndex, System::Types::TRect &ARect, int ANom, int ADenom, bool &ADefaultDrawText, bool &ADefaultDrawBackground);

typedef void __fastcall (__closure *TdxFilterStyleEvent)(TBasedxReportLink* Sender, Dxpgsdlg::TBasedxPrintStyle* AStyle, bool &ASupported);

typedef void __fastcall (__closure *TdxMeasureReportLinkTitleEvent)(TBasedxReportLink* Sender, int &AHeight);

typedef void __fastcall (__closure *TdxPSGetNewReportStorageNameEvent)(TBasedxReportLink* Sender, System::UnicodeString &AName);

typedef void __fastcall (__closure *TdxPSGetImageListProc)(Vcl::Imglist::TCustomImageList* AnImageList);

__interface IdxPSNativeWin32ControlHandleSupport;
typedef System::DelphiInterface<IdxPSNativeWin32ControlHandleSupport> _di_IdxPSNativeWin32ControlHandleSupport;
__interface  INTERFACE_UUID("{4B649281-A283-4CAC-98D4-08E779A7F9C8}") IdxPSNativeWin32ControlHandleSupport  : public System::IInterface 
{
	
public:
	virtual NativeUInt __fastcall GetNativeHandle(void) = 0 ;
	virtual void __fastcall SetNativeHandle(NativeUInt Value) = 0 ;
	__property NativeUInt NativeHandle = {read=GetNativeHandle, write=SetNativeHandle};
};

class DELPHICLASS TCustomdxComponentPrinter;
class DELPHICLASS TAbstractdxReportLinkDesignWindow;
class DELPHICLASS TdxPSCustomPreviewWindow;
class DELPHICLASS TdxCompositionReportLink;
class PASCALIMPLEMENTATION TBasedxReportLink : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FActive;
	TdxAssignedFormatValues FAssignedFormatValues;
	bool FBuiltIn;
	System::Classes::TComponent* FComponent;
	TCustomdxComponentPrinter* FComponentPrinter;
	TBasedxReportLink* FController;
	int FCurrentPage;
	void *FData;
	TdxReportLinkDataSource FDataSource;
	System::Classes::TStream* FDataStream;
	int FDateFormat;
	Vcl::Graphics::TFont* FDefaultFont;
	System::UnicodeString FDesignerCaption;
	System::Classes::THelpContext FDesignerHelpContext;
	TAbstractdxReportLinkDesignWindow* FDesignWindow;
	Vcl::Graphics::TFont* FFont;
	bool FFootersOnEveryPage;
	bool FHeadersOnEveryPage;
	bool FInternalStreaming;
	bool FIsDesignerCaptionAssigned;
	bool FIsInvalidReport;
	Dxpsglbl::TdxPageNumberFormat FPageNumberFormat;
	TdxPSPDFReportExportOptions* FPDFExportOptions;
	Dxprnpg::TdxPrinterPage* FPrinterPage;
	bool FRebuildNeeded;
	TdxPSReportRenderer* FRenderer;
	TdxPSReportRenderInfo* FRenderInfo;
	TdxReportCells* FReportCells;
	TdxPSReportDocument* FReportDocument;
	TdxReportFootnotes* FReportFootnotes;
	TdxReportTitle* FReportTitle;
	TdxPSReportDocument* FSavedReportDocument;
	TdxReportFootnotes* FSavedReportFootnotes;
	TdxReportTitle* FSavedReportTitle;
	bool FScaleFonts;
	bool FShowDesigner;
	bool FShowPageFooter;
	bool FShowPageHeader;
	bool FShowPageRowHeader;
	int FStartPageIndex;
	TdxReportLinkStates FState;
	System::UnicodeString FStorageName;
	Dxpgsdlg::TdxPrintStyleManager* FStyleManager;
	Dxpsesys::TdxEventSubscriber* FSubscriber;
	int FTimeFormat;
	bool FTransparent;
	bool FUseHorzDelimiters;
	bool FUseVertDelimiters;
	TdxPSBackgroundBitmapPool* FBackgroundBitmapPool;
	TdxPSReportFontPool* FFontPool;
	bool FPainting;
	bool FPrepared;
	bool FStreamedActive;
	System::Classes::TNotifyEvent FOnChangeComponent;
	TdxCustomDrawReportLinkHFEvent FOnCustomDrawPageFooter;
	TdxCustomDrawReportLinkHFEvent FOnCustomDrawPageHeader;
	TdxCustomDrawReportLinkTitleEvent FOnCustomDrawReportLinkFootnotes;
	TdxCustomDrawReportLinkTitleEvent FOnCustomDrawReportLinkTitle;
	System::Classes::TNotifyEvent FOnDataSourceChanged;
	System::Classes::TNotifyEvent FOnDestroy;
	TdxFilterStyleEvent FOnFilterStyle;
	TdxPSGetNewReportStorageNameEvent FOnGetNewReportStorageName;
	TdxMeasureReportLinkTitleEvent FOnMeasureReportLinkFootnotes;
	TdxMeasureReportLinkTitleEvent FOnMeasureReportLinkTitle;
	bool __fastcall GetAbortBuilding(void);
	System::UnicodeString __fastcall GetCaption(void);
	Dxpgsdlg::TBasedxPrintStyle* __fastcall GetCurrentPrintStyle(void);
	int __fastcall GetDateFormat(void);
	System::TDateTime __fastcall GetDateTime(void);
	System::UnicodeString __fastcall GetDescription(void);
	System::UnicodeString __fastcall GetDesignerCaption(void);
	TdxPSReportFontPool* __fastcall GetFontPool(void);
	bool __fastcall GetHasDesignWindow(void);
	bool __fastcall GetHasPreviewWindow(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsAggregated(void);
	bool __fastcall GetIsBuilding(void);
	bool __fastcall GetIsCurrentLink(void);
	bool __fastcall GetIsReading(void);
	int __fastcall GetPageHeight(void);
	Dxpsglbl::TdxPageNumberFormat __fastcall GetPageNumberFormat(void);
	int __fastcall GetPageWidth(void);
	TdxPSCustomPreviewWindow* __fastcall GetPreviewWindow(void);
	Dxprnpg::TdxPrinterPage* __fastcall GetRealPrinterPage(void);
	TdxPSReportRenderer* __fastcall GetRenderer(void);
	TdxPSReportRenderInfo* __fastcall GetRenderInfo(void);
	TdxPSRenderStages __fastcall GetRenderStage(void);
	TdxReportTitleMode __fastcall GetReportTitleMode(void);
	System::UnicodeString __fastcall GetReportTitleText(void);
	bool __fastcall GetShowPageFooter(void);
	bool __fastcall GetShowPageHeader(void);
	bool __fastcall GetShowPageRowHeader(void);
	bool __fastcall GetShrinkToPageWidth(void);
	int __fastcall GetStartPageIndex(void);
	int __fastcall GetTimeFormat(void);
	int __fastcall GetVirtualPageCount(void);
	bool __fastcall IsDateFormatStored(void);
	bool __fastcall IsDesignerCaptionStored(void);
	bool __fastcall IsPageNumberFormatStored(void);
	bool __fastcall IsTimeFormatStored(void);
	void __fastcall SetAbortBuilding(bool Value);
	void __fastcall SetAssignedFormatValues(TdxAssignedFormatValues Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetComponentPrinter(TCustomdxComponentPrinter* Value);
	void __fastcall SetCurrentPage(int Value);
	void __fastcall SetDateFormat(int Value);
	void __fastcall SetDataSource(TdxReportLinkDataSource Value);
	void __fastcall SetDateTime(const System::TDateTime Value);
	void __fastcall SetDesignerCaption(const System::UnicodeString Value);
	void __fastcall SetDescription(const System::UnicodeString Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetIsCurrentLink(bool Value);
	void __fastcall SetPageNumberFormat(Dxpsglbl::TdxPageNumberFormat Value);
	void __fastcall SetPDFExportOptions(TdxPSPDFReportExportOptions* AValue);
	void __fastcall SetPrinterPage(Dxprnpg::TdxPrinterPage* Value);
	void __fastcall SetRealPrinterPage(Dxprnpg::TdxPrinterPage* Value);
	void __fastcall SetReportDocument(TdxPSReportDocument* Value);
	void __fastcall SetReportFootnotes(TdxReportFootnotes* Value);
	void __fastcall SetReportTitle(TdxReportTitle* Value);
	void __fastcall SetReportTitleMode(TdxReportTitleMode Value);
	void __fastcall SetReportTitleText(const System::UnicodeString Value);
	void __fastcall SetShowPageFooter(bool Value);
	void __fastcall SetShowPageHeader(bool Value);
	void __fastcall SetShowPageRowHeader(bool Value);
	void __fastcall SetShrinkToPageWidth(bool Value);
	void __fastcall SetStartPageIndex(int Value);
	void __fastcall SetStorageName(const System::UnicodeString Value);
	void __fastcall SetStyleManager(Dxpgsdlg::TdxPrintStyleManager* Value);
	void __fastcall SetTimeFormat(int Value);
	void __fastcall SetUseHorzDelimiters(bool Value);
	void __fastcall SetUseVertDelimiters(bool Value);
	TdxCompositionReportLink* __fastcall CurrentComposition(void);
	bool __fastcall ValidateMargins(void);
	void __fastcall DefineStylesClick(System::TObject* Sender);
	void __fastcall StyleClick(System::TObject* Sender);
	void __fastcall ReadBuiltIn(System::Classes::TReader* Reader);
	void __fastcall ReadComponentName(System::Classes::TReader* AReader);
	void __fastcall ReadIsDesignerCaptionAssigned(System::Classes::TReader* Reader);
	void __fastcall ReadStyleManagerName(System::Classes::TReader* AReader);
	void __fastcall WriteBuiltIn(System::Classes::TWriter* Writer);
	void __fastcall WriteComponentName(System::Classes::TWriter* AWriter);
	void __fastcall WriteIsDesignerCaptionAssigned(System::Classes::TWriter* Writer);
	void __fastcall WriteStyleManagerName(System::Classes::TWriter* AWriter);
	
protected:
	System::Uitypes::TColor FColor;
	int FFontIndex;
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* AParent);
	virtual TdxPSReportRenderInfo* __fastcall CreateRenderInfo(void);
	virtual TdxPSReportRenderInfoClass __fastcall GetRenderInfoClass(void);
	void __fastcall CalculateRenderInfos(void);
	void __fastcall ClearGDIPools(void);
	void __fastcall FreeRenderInfos(void);
	virtual TdxPSReportRenderer* __fastcall CreateRenderer(void);
	virtual TdxPSReportRendererClass __fastcall GetRendererClass(void);
	void __fastcall FreeRenderer(void);
	virtual void __fastcall InitializeDefaultFont(Vcl::Graphics::TFont* AFont);
	void __fastcall InternalGetDelimiters(System::Classes::TList* ADelimitersHorz, System::Classes::TList* ADelimitersVert);
	bool __fastcall IsEntirePageCustomDrawn(void);
	bool __fastcall IsFootnotesCustomDrawn(void);
	bool __fastcall IsHeaderOrFooterCustomDrawn(Dxprnpg::TCustomdxPageObject* AHFObject);
	bool __fastcall IsTitleCustomDrawn(void);
	bool __fastcall PageReady(int APageIndex);
	void __fastcall PrepareFonts(int UPI);
	void __fastcall PrepareLongOperation(void);
	void __fastcall UnprepareLongOperation(void);
	TdxPSReportDocument* __fastcall CreateReportDocument(void);
	virtual void __fastcall DocumentChanged(System::TObject* Sender);
	__classmethod virtual TdxPSReportDocumentClass __fastcall GetReportDocumentClass();
	virtual TdxReportCells* __fastcall CreateReportCells(void);
	virtual TdxReportCellsClass __fastcall GetReportCellsClass(void);
	__classmethod TdxPSDataReader* __fastcall CreateDataReader(System::Classes::TStream* AStream);
	__classmethod TdxPSDataWriter* __fastcall CreateDataWriter(System::Classes::TStream* AStream);
	__classmethod virtual TdxPSDataReaderClass __fastcall GetDataReaderClass();
	__classmethod virtual TdxPSDataWriterClass __fastcall GetDataWriterClass();
	void __fastcall InternalLoadDataFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall InternalReadData(TdxPSDataReader* AReader);
	virtual void __fastcall InternalWriteData(TdxPSDataWriter* AWriter);
	bool __fastcall IsRebuildNeededAndAllowed(bool ACheckPreviewMode);
	virtual TdxPSDataStorageInfo* __fastcall RetrieveStorageInfo(void);
	virtual void __fastcall ReadData(TdxPSDataReader* AReader);
	__classmethod virtual TdxPSDataStorageOffsetTable* __fastcall ReadOffsetTable(TdxPSDataReader* AReader);
	__classmethod virtual void __fastcall ReadReportDocument(TdxPSDataReader* AReader, TdxPSReportDocument* AReportDocument);
	__classmethod virtual TdxPSDataStorageInfo* __fastcall ReadStorageInfo(TdxPSDataReader* AReader);
	__classmethod void __fastcall SkipStorageInfo(TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(TdxPSDataWriter* AWriter);
	__classmethod virtual void __fastcall WriteOffsetTable(TdxPSDataWriter* AWriter, TdxPSDataStorageOffsetTable* AnOffsetTable);
	__classmethod virtual void __fastcall WriteReportDocument(TdxPSDataWriter* AWriter, TdxPSReportDocument* AReportDocument);
	__classmethod virtual void __fastcall WriteStorageInfo(TdxPSDataWriter* AWriter, TdxPSDataStorageInfo* AStorageInfo);
	virtual void __fastcall ReadFootnotes(TdxPSDataReader* AReader);
	virtual void __fastcall ReadTitle(TdxPSDataReader* AReader);
	virtual void __fastcall WriteFootnotes(TdxPSDataWriter* AWriter);
	virtual void __fastcall WriteTitle(TdxPSDataWriter* AWriter);
	void __fastcall ReadBackgroundBitmapPool(TdxPSDataReader* AReader);
	void __fastcall ReadFontPool(TdxPSDataReader* AReader);
	void __fastcall ReadRenderInfo(TdxPSDataReader* AReader);
	void __fastcall ReadReportData(TdxPSDataReader* AReader);
	void __fastcall WriteBackgroundBitmapPool(TdxPSDataWriter* AWriter);
	void __fastcall WriteFontPool(TdxPSDataWriter* AWriter);
	void __fastcall WriteRenderInfo(TdxPSDataWriter* AWriter);
	void __fastcall WriteReportData(TdxPSDataWriter* AWriter);
	virtual bool __fastcall GetAllowContinuousPageIndexes(void);
	virtual bool __fastcall GetAlwaysBufferedGraphics(void);
	virtual bool __fastcall GetContinuousPageIndexes(void);
	virtual int __fastcall GetRealScaleFactor(void);
	virtual int __fastcall GetReportHeight(void);
	virtual int __fastcall GetReportWidth(void);
	virtual bool __fastcall IsFontStored(void);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetColor(System::Uitypes::TColor Value);
	virtual void __fastcall SetComponent(System::Classes::TComponent* Value);
	virtual void __fastcall SetContinuousPageIndexes(bool Value);
	virtual void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	virtual void __fastcall SetFootersOnEveryPage(bool Value);
	virtual void __fastcall SetHeadersOnEveryPage(bool Value);
	virtual void __fastcall SetTransparent(bool Value);
	virtual void __fastcall FontChanged(System::TObject* Sender);
	virtual void __fastcall LinkModified(bool Value);
	virtual void __fastcall AfterDesignReport(bool ADone);
	virtual void __fastcall BeforeDesignReport(void);
	virtual void __fastcall AfterPrinting(void);
	virtual void __fastcall BeforePrinting(void);
	virtual int __fastcall CalculateActualScaleFactor(void);
	virtual System::UnicodeString __fastcall CannotActivateReportErrorString(void);
	virtual void __fastcall ConstructReport(TdxReportCells* AReportCells);
	virtual void __fastcall ConvertCoords(void);
	virtual void __fastcall CustomDraw(TAbstractdxReportCellData* AnItem, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);
	virtual TdxReportLinkDesignWindowClass __fastcall GetDesignerClass(void);
	virtual void __fastcall DoApplyInDesigner(void);
	DYNAMIC bool __fastcall DoBeforeExportToPDF(const System::UnicodeString AFileName, TdxPSPDFReportExportOptions* AOptions);
	virtual void __fastcall DoCreateReport(void);
	void __fastcall DoCreateReportData(void);
	DYNAMIC void __fastcall DoDataProviderDontPresent(void);
	virtual void __fastcall DoDestroyReport(void);
	virtual void __fastcall DoPageParamsChanged(void);
	void __fastcall CopyDataStreamFrom(System::Classes::TStream* AStream);
	virtual void __fastcall FinalizeDataStream(void);
	virtual bool __fastcall GetBreakPagesByHardDelimiters(void);
	virtual int __fastcall GetCriticalSize(TdxReportCells* AReportCells);
	virtual void __fastcall GetImageLists(TdxPSGetImageListProc AProc);
	virtual int __fastcall GetPageCount(void);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual bool __fastcall GetUseHardHorzDelimiters(void);
	virtual bool __fastcall GetUseHardVertDelimiters(void);
	virtual int __fastcall GetVisiblePageCount(void);
	virtual void __fastcall InternalActivate(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsDrawFootersOnEveryPage(void);
	virtual bool __fastcall IsDrawHeadersOnEveryPage(void);
	virtual bool __fastcall IsDrawHeaderCornersOnEveryPage(void);
	virtual bool __fastcall IsDrawRowHeadersOnEveryPage(void);
	virtual bool __fastcall IsScaleGridLines(void);
	virtual bool __fastcall IsSupportedCustomDraw(TAbstractdxReportCellData* Item);
	virtual void __fastcall MakeDelimiters(TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	virtual void __fastcall MakeHardDelimiters(TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	virtual void __fastcall PageParamsChanged(Dxprnpg::TdxPrinterPage* Sender, Dxpgsdlg::TBasedxPrintStyle* AStyle, Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual bool __fastcall PossibleCustomDraw(TAbstractdxReportCellData* AnItem);
	void __fastcall PrepareReportGroupsLookAndFeels(void);
	void __fastcall RetrievePageAsImage(int APageIndex, Vcl::Graphics::TGraphicClass AGraphicClass, Vcl::Graphics::TGraphic* AGraphic);
	void __fastcall RetrievePageAsImageCallBack(TCustomdxComponentPrinter* AComponentPrinter, TBasedxReportLink* AReportLink, int AIndex, int APageIndex, Vcl::Graphics::TGraphic* const AGraphic, void * AData, bool &AContinue);
	virtual void __fastcall ShowPageFooterChanged(void);
	virtual void __fastcall ShowPageHeaderChanged(void);
	virtual void __fastcall StdProcessDataSourceDontPresent(void);
	virtual void __fastcall TunePixelsNumerator(TdxReportCells* AReportCells);
	virtual void __fastcall PaintPage(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &APageBounds, int APageIndex, int AContinuousPageIndex, int AZoomFactor);
	virtual void __fastcall PaintPageEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &APageBounds, int APageIndex, int AContinuousPageIndex, int AZoomFactor);
	void __fastcall ComponentUnsupportedError(System::Classes::TComponent* AComponent);
	DYNAMIC void __fastcall DoChangeComponent(void);
	virtual void __fastcall DoCustomDrawEntirePage(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, int ARealPageIndex);
	virtual void __fastcall DoCustomDrawPageHeaderOrFooter(Dxprnpg::TCustomdxPageObject* AHFObject, Vcl::Graphics::TCanvas* ACanvas, int APageIndex, System::Types::TRect &R, bool &ADefaultDrawText, bool &ADefaultDrawBackground);
	virtual void __fastcall DoCustomDrawPageFootnotes(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone);
	virtual void __fastcall DoCustomDrawPageTitle(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone);
	virtual void __fastcall DoParentCustomDrawPageHeaderOrFooter(Dxprnpg::TCustomdxPageObject* AHFObject, Vcl::Graphics::TCanvas* ACanvas, int APageIndex, System::Types::TRect &R, bool &ADefaultDrawText, bool &ADefaultDrawBackground, int APixelsNumerator);
	virtual void __fastcall DoParentCustomDrawReportFootnotes(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone, int APixelsNumerator);
	virtual void __fastcall DoParentCustomDrawReportTitle(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone, int APixelsNumerator);
	virtual void __fastcall DoGetNewReportStorageName(System::UnicodeString &AName);
	DYNAMIC void __fastcall DoDataSourceChanged(void);
	DYNAMIC void __fastcall DoDestroy(void);
	virtual void __fastcall DoMeasureReportLinkFootnotes(int &AHeight);
	virtual void __fastcall DoMeasureReportLinkTitle(int &AHeight);
	DYNAMIC void __fastcall DoProgress(const double APercentDone);
	virtual bool __fastcall IsComposable(TdxCompositionReportLink* AComposition);
	virtual bool __fastcall IsSupportedStyle(Dxpgsdlg::TBasedxPrintStyle* APrintStyle);
	virtual bool __fastcall NeedTwoPassRendering(void);
	void __fastcall DesignerModified(void);
	void __fastcall DesignerUpdate(bool TheAll);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	__property bool AllowContinuousPageIndexes = {read=GetAllowContinuousPageIndexes, nodefault};
	__property bool AlwaysBufferedGraphics = {read=GetAlwaysBufferedGraphics, nodefault};
	__property TdxPSBackgroundBitmapPool* BackgroundBitmapPool = {read=FBackgroundBitmapPool};
	__property bool BreakPagesByHardDelimiters = {read=GetBreakPagesByHardDelimiters, nodefault};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=16777215};
	__property bool ContinuousPageIndexes = {read=GetContinuousPageIndexes, write=SetContinuousPageIndexes, default=0};
	__property System::Classes::TStream* DataStream = {read=FDataStream};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property TdxPSReportFontPool* FontPool = {read=GetFontPool};
	__property bool FootersOnEveryPage = {read=FFootersOnEveryPage, write=SetFootersOnEveryPage, default=0};
	__property bool HeadersOnEveryPage = {read=FHeadersOnEveryPage, write=SetHeadersOnEveryPage, default=0};
	__property bool InternalStreaming = {read=FInternalStreaming, write=FInternalStreaming, nodefault};
	__property bool IsBuilding = {read=GetIsBuilding, nodefault};
	__property bool IsInvalidReport = {read=FIsInvalidReport, nodefault};
	__property bool IsReading = {read=GetIsReading, nodefault};
	__property int PageHeight = {read=GetPageHeight, nodefault};
	__property int PageWidth = {read=GetPageWidth, nodefault};
	__property TdxPSReportRenderInfo* RenderInfo = {read=GetRenderInfo};
	__property bool ScaleFonts = {read=FScaleFonts, write=FScaleFonts, default=1};
	__property TdxReportLinkStates State = {read=FState, nodefault};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=1};
	__property bool UseHardHorzDelimiters = {read=GetUseHardHorzDelimiters, nodefault};
	__property bool UseHardVertDelimiters = {read=GetUseHardVertDelimiters, nodefault};
	__property bool UseHorzDelimiters = {read=FUseHorzDelimiters, write=SetUseHorzDelimiters, default=1};
	__property bool UseVertDelimiters = {read=FUseVertDelimiters, write=SetUseVertDelimiters, default=1};
	__property int VirtualPageCount = {read=GetVirtualPageCount, nodefault};
	
public:
	__fastcall virtual TBasedxReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TBasedxReportLink(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection)/* overload */;
	void __fastcall LoadFromIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall LoadFromRegistry(const System::UnicodeString APath);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection)/* overload */;
	void __fastcall SaveToIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall SaveToRegistry(const System::UnicodeString APath);
	__classmethod virtual bool __fastcall Aggregable();
	__classmethod virtual bool __fastcall CanBeUsedAsStub();
	__classmethod virtual bool __fastcall Serializable();
	virtual int __fastcall DefaultDateFormat(void);
	virtual System::UnicodeString __fastcall DefaultDesignerCaption(void);
	virtual Vcl::Graphics::TFont* __fastcall DefaultFont(void);
	virtual Dxpsglbl::TdxPageNumberFormat __fastcall DefaultPageNumberFormat(void);
	virtual int __fastcall DefaultTimeFormat(void);
	virtual void __fastcall RestoreDefaults(void);
	virtual void __fastcall RestoreFromOriginal(void);
	bool __fastcall CheckToDesign(void);
	virtual bool __fastcall DataProviderPresent(void);
	virtual bool __fastcall DesignerExists(System::Classes::TComponentClass AComponentClass);
	bool __fastcall DesignReport(void);
	virtual void __fastcall DestroyReport(void);
	virtual void __fastcall GetPageColRowCount(/* out */ int &APageColCount, /* out */ int &APageRowCount);
	virtual void __fastcall Initialize(void);
	virtual bool __fastcall IsEmptyPage(int APageIndex);
	virtual bool __fastcall IsEmptyReport(void);
	virtual void __fastcall RebuildReport(void);
	void __fastcall SetComponentUnconditionally(System::Classes::TComponent* Value);
	__classmethod void __fastcall GetSupportedComponentList(Dxbase::TdxClassList* AList);
	__classmethod virtual bool __fastcall IsSupportedCompClass(System::TClass AComponentClass);
	__classmethod TdxReportLinkClass __fastcall LinkClass();
	__classmethod bool __fastcall Supports(System::TObject* AnObject)/* overload */;
	__classmethod bool __fastcall Supports(System::TClass AClass)/* overload */;
	bool __fastcall Print(bool AShowDialog, Dxprndlg::PdxPrintDlgData APPrintDlgData);
	void __fastcall PrintEx(Dxprndlg::TdxPageNumbers APageNums, int ACopies, bool ACollate);
	void __fastcall PrintPages(const Dxpsglbl::TIntegers APageIndexes);
	void __fastcall PrintPagesEx(const Dxpsglbl::TIntegers APageIndexes, Dxprndlg::TdxPageNumbers APageNums, int ACopyCount, bool ACollate);
	void __fastcall ExportToPDF(void)/* overload */;
	void __fastcall ExportToPDF(const System::UnicodeString AFileName, bool ACanShowDialog = true, TdxPSPDFReportExportOptions* ASettings = (TdxPSPDFReportExportOptions*)(0x0))/* overload */;
	void __fastcall Preview(bool Modal = true);
	bool __fastcall PreviewExists(void);
	void __fastcall BuildPageSetupMenu(System::Classes::TComponent* ARootItem, void * AData, bool AIncludeDefineItem = true);
	void __fastcall DefinePrintStylesDlg(void);
	void __fastcall GetFilteredStyles(System::Classes::TStrings* AStrings);
	bool __fastcall PageSetup(void);
	bool __fastcall PageSetupEx(int AActivePageIndex, bool AShowPreviewBtn, bool AShowPrintBtn, /* out */ bool &APreviewBtnClicked, /* out */ bool &APrintBtnClicked)/* overload */;
	bool __fastcall ShowDateTimeFormatsDlg(void);
	bool __fastcall ShowFootnotesPropertiesDlg(void);
	bool __fastcall ShowPageNumberFormatsDlg(void);
	bool __fastcall ShowTitlePropertiesDlg(void);
	virtual bool __fastcall SupportsScaling(void);
	bool __fastcall CanChangeFootnotes(void);
	bool __fastcall CanChangeTitle(void);
	virtual bool __fastcall SupportsFootnotes(void);
	virtual bool __fastcall SupportsTitle(void);
	virtual bool __fastcall CanLoadData(void);
	virtual bool __fastcall CanSaveData(void);
	virtual bool __fastcall CanUnloadData(void);
	virtual System::UnicodeString __fastcall GetNewReportStorageName(void);
	virtual void __fastcall LoadDataFromFile(const System::UnicodeString AName);
	virtual void __fastcall LoadDataFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveDataToFile(const System::UnicodeString AName);
	virtual void __fastcall SaveDataToStream(System::Classes::TStream* AStream);
	__classmethod System::Classes::TComponentClass __fastcall ExtractComponentClass(System::Classes::TStream* AStream, bool ARaiseException = false);
	__classmethod System::UnicodeString __fastcall ExtractComponentClassName(System::Classes::TStream* AStream, bool ARaiseException = false);
	__classmethod TdxReportLinkClass __fastcall ExtractLinkClass(System::Classes::TStream* AStream, bool ARaiseException = false);
	__classmethod TdxPSDataStorageOffsetTable* __fastcall ExtractOffsetTable(System::Classes::TStream* AStream, bool ARaiseException = false);
	__classmethod TdxPSReportDocument* __fastcall ExtractReportDocument(System::Classes::TStream* AStream, bool ARaiseException = false);
	__classmethod TdxPSDataStorageInfo* __fastcall ExtractStorageInfo(System::Classes::TStream* AStream, bool ARaiseException = false);
	__classmethod int __fastcall ExtractStorageVersion(System::Classes::TStream* AStream, bool ARaiseException = false);
	__classmethod void __fastcall FinalizeStorageInfo(TdxPSDataStorageInfo* &AStorageInfo);
	__classmethod bool __fastcall PossibleDataStorage(System::Classes::TStream* AStream, bool ARaiseException = false)/* overload */;
	__classmethod bool __fastcall PossibleDataStorage(const System::UnicodeString AFileName, bool ARaiseException = false)/* overload */;
	int __fastcall AddBackgroundBitmapToPool(Vcl::Graphics::TBitmap* ABitmap);
	int __fastcall AddFontToPool(Vcl::Graphics::TFont* AFont);
	TdxPSReportGroupLookAndFeel* __fastcall CreateGroupLookAndFeel(TdxPSReportGroupLookAndFeelClass AClass, bool ACheckExisting = true);
	TdxPSReportGroupLookAndFeel* __fastcall FindGroupLookAndFeelByClass(TdxPSReportGroupLookAndFeelClass AClass);
	int __fastcall IndexOfReportGroupLookAndFeel(TdxPSReportGroupLookAndFeel* ALookAndFeel);
	void __fastcall DrawPageHeader(int APageIndex, System::Types::TRect &ARect, Dxprnpg::TdxPageTitleParts ATitleParts, bool ADrawBackground);
	void __fastcall DrawPageFooter(int APageIndex, System::Types::TRect &ARect, Dxprnpg::TdxPageTitleParts ATitleParts, bool ADrawBackground);
	virtual void __fastcall DrawCheckBox(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, bool Checked, bool Enabled, bool FlatBorder, bool BoldBorder = false)/* overload */;
	virtual void __fastcall DrawCheckBox(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, bool Checked, bool Enabled, bool IsRadio, Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle EdgeStyle, System::Uitypes::TColor BorderColor = (System::Uitypes::TColor)(0xff000008))/* overload */;
	virtual void __fastcall drawEdge(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, TdxCellEdgeMode EdgeMode, TdxCellEdgeStyle InnerEdge, TdxCellEdgeStyle OuterEdge, TdxCellSides Sides = (TdxCellSides() << TdxCellSide::csLeft << TdxCellSide::csTop << TdxCellSide::csRight << TdxCellSide::csBottom ), bool Soft = true);
	virtual void __fastcall DrawEllipse(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, System::Uitypes::TColor ForeColor, System::Uitypes::TColor BkColor, Dxpsfillpatterns::TdxPSFillPatternClass Pattern, System::Uitypes::TColor BorderColor, int BorderThickness = 0x1);
	virtual void __fastcall DrawExpandButton(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, bool Expanded, bool DrawBorder, bool Edge3D, bool Edge3DSoft, bool Shadow, bool FillInterior, System::Uitypes::TColor BorderColor, System::Uitypes::TColor InteriorColor);
	void __fastcall DrawGlyph(HDC DC, const System::Types::TRect &R, System::Byte AGlyph);
	virtual void __fastcall DrawGraphic(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, const System::Types::TRect &ClipRect, Vcl::Imglist::TCustomImageList* ImageList, int ImageIndex, Vcl::Graphics::TGraphic* Graphic, bool GraphicTransparent, bool Transparent, System::Uitypes::TColor BkColor);
	virtual void __fastcall DrawGraphicEx(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, const System::Types::TRect &ClipRect, Vcl::Imglist::TCustomImageList* ImageList, int ImageIndex, Vcl::Graphics::TGraphic* Graphic, bool GraphicTransparent, bool Transparent, System::Uitypes::TColor BkColor, System::Uitypes::TColor ForeColor, Dxpsfillpatterns::TdxPSFillPatternClass Pattern, TdxCellImageBuffering AActualImageBuffering = (TdxCellImageBuffering)(0x2));
	virtual void __fastcall DrawRectangle(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, System::Uitypes::TColor ForeColor, System::Uitypes::TColor BkColor, Dxpsfillpatterns::TdxPSFillPatternClass ContentPattern, System::Uitypes::TColor BorderColor, int BorderThickness = 0x1);
	virtual void __fastcall DrawRoundRect(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, int CornerWidth, int CornerHeight, System::Uitypes::TColor ForeColor, System::Uitypes::TColor BkColor, Dxpsfillpatterns::TdxPSFillPatternClass ContentPattern, System::Uitypes::TColor BorderColor, int BorderThickness = 0x1);
	virtual void __fastcall DrawSortMark(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, TdxCellSortOrder SortOrder, bool Mono);
	virtual void __fastcall drawText(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, int AIndent, const System::UnicodeString Text, Vcl::Graphics::TFont* Font, System::Uitypes::TColor BkColor, Cxdrawtextutils::TcxTextAlignX TextAlignX, Cxdrawtextutils::TcxTextAlignY TextAlignY, bool FillBackground, bool Multiline, bool EndEllipsis);
	virtual void __fastcall drawTextEx(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, int MaxLineCount, int LeftIndent, int RightIndent, const System::UnicodeString Text, Vcl::Graphics::TFont* Font, System::Uitypes::TColor BkColor, Cxdrawtextutils::TcxTextAlignX TextAlignX, Cxdrawtextutils::TcxTextAlignY TextAlignY, bool FillBackground, bool Multiline, bool EndEllipsis, bool PreventLeftTextExceed, bool PreventTopTextExceed);
	virtual void __fastcall FillEllipse(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &R, System::Uitypes::TColor Color);
	virtual void __fastcall FillEllipseEx(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &R, System::Uitypes::TColor ForeColor, System::Uitypes::TColor BkColor, Dxpsfillpatterns::TdxPSFillPatternClass Pattern);
	virtual void __fastcall FillRectEx(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &R, System::Uitypes::TColor ForeColor, System::Uitypes::TColor BkColor, Dxpsfillpatterns::TdxPSFillPatternClass Pattern);
	virtual void __fastcall FillRoundRect(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &R, int CornerWidth, int CornerHeight, System::Uitypes::TColor Color);
	virtual void __fastcall FillRoundRectEx(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &R, int CornerWidth, int CornerHeight, System::Uitypes::TColor ForeColor, System::Uitypes::TColor BkColor, Dxpsfillpatterns::TdxPSFillPatternClass Pattern);
	virtual void __fastcall FillRgnEx(Vcl::Graphics::TCanvas* Canvas, HRGN Rgn, System::Uitypes::TColor ForeColor, System::Uitypes::TColor BkColor, Dxpsfillpatterns::TdxPSFillPatternClass Pattern);
	void __fastcall FrameEllipse(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, System::Uitypes::TColor Color, int Thickness = 0x1);
	void __fastcall frameRect(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, System::Uitypes::TColor Color, TdxCellSides Sides = (TdxCellSides() << TdxCellSide::csLeft << TdxCellSide::csTop << TdxCellSide::csRight << TdxCellSide::csBottom ), int Thickness = 0x1);
	virtual void __fastcall FrameRoundRect(Vcl::Graphics::TCanvas* Canvas, System::Types::TRect &R, int CornerWidth, int CornerHeight, System::Uitypes::TColor Color, int Thickness = 0x1);
	__property bool AbortBuilding = {read=GetAbortBuilding, write=SetAbortBuilding, nodefault};
	__property bool BuiltIn = {read=FBuiltIn, write=FBuiltIn, nodefault};
	__property TCustomdxComponentPrinter* ComponentPrinter = {read=FComponentPrinter, write=SetComponentPrinter};
	__property TBasedxReportLink* Controller = {read=FController, write=FController};
	__property int CurrentPage = {read=FCurrentPage, write=SetCurrentPage, nodefault};
	__property Dxpgsdlg::TBasedxPrintStyle* CurrentPrintStyle = {read=GetCurrentPrintStyle};
	__property void * Data = {read=FData, write=FData};
	__property TdxReportLinkDataSource DataSource = {read=FDataSource, write=SetDataSource, nodefault};
	__property TAbstractdxReportLinkDesignWindow* DesignWindow = {read=FDesignWindow};
	__property bool HasDesignWindow = {read=GetHasDesignWindow, nodefault};
	__property bool HasPreviewWindow = {read=GetHasPreviewWindow, nodefault};
	__property bool IsAggregated = {read=GetIsAggregated, nodefault};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property TdxPSCustomPreviewWindow* PreviewWindow = {read=GetPreviewWindow};
	__property Dxprnpg::TdxPrinterPage* RealPrinterPage = {read=GetRealPrinterPage, write=SetRealPrinterPage};
	__property int RealScaleFactor = {read=GetRealScaleFactor, nodefault};
	__property bool RebuildNeeded = {read=FRebuildNeeded, nodefault};
	__property TdxPSReportRenderer* Renderer = {read=GetRenderer};
	__property TdxPSRenderStages RenderStage = {read=GetRenderStage, nodefault};
	__property TdxReportCells* ReportCells = {read=FReportCells};
	__property int ReportHeight = {read=GetReportHeight, nodefault};
	__property int ReportWidth = {read=GetReportWidth, nodefault};
	__property int VisiblePageCount = {read=GetVisiblePageCount, nodefault};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=false};
	__property System::Classes::TComponent* Component = {read=FComponent, write=SetComponent};
	__property System::UnicodeString Description = {read=GetDescription, write=SetDescription, stored=false};
	__property int DateFormat = {read=GetDateFormat, write=SetDateFormat, stored=IsDateFormatStored, default=0};
	__property System::TDateTime DateTime = {read=GetDateTime, write=SetDateTime, stored=false};
	__property System::UnicodeString DesignerCaption = {read=GetDesignerCaption, write=SetDesignerCaption, stored=IsDesignerCaptionStored};
	__property System::Classes::THelpContext DesignerHelpContext = {read=FDesignerHelpContext, write=FDesignerHelpContext, default=0};
	__property int Index = {read=GetIndex, write=SetIndex, stored=false, nodefault};
	__property bool IsCurrentLink = {read=GetIsCurrentLink, write=SetIsCurrentLink, stored=false, nodefault};
	__property Dxpsglbl::TdxPageNumberFormat PageNumberFormat = {read=GetPageNumberFormat, write=SetPageNumberFormat, stored=IsPageNumberFormatStored, nodefault};
	__property TdxPSPDFReportExportOptions* PDFExportOptions = {read=FPDFExportOptions, write=SetPDFExportOptions};
	__property Dxprnpg::TdxPrinterPage* PrinterPage = {read=FPrinterPage, write=SetPrinterPage};
	__property TdxPSReportDocument* ReportDocument = {read=FReportDocument, write=SetReportDocument};
	__property TdxReportFootnotes* ReportFootnotes = {read=FReportFootnotes, write=SetReportFootnotes};
	__property TdxReportTitle* ReportTitle = {read=FReportTitle, write=SetReportTitle};
	__property TdxReportTitleMode ReportTitleMode = {read=GetReportTitleMode, write=SetReportTitleMode, stored=false, default=2};
	__property System::UnicodeString ReportTitleText = {read=GetReportTitleText, write=SetReportTitleText, stored=false};
	__property bool ShowDesigner = {read=FShowDesigner, write=FShowDesigner, stored=false, nodefault};
	__property bool ShowPageFooter = {read=GetShowPageFooter, write=SetShowPageFooter, default=1};
	__property bool ShowPageHeader = {read=GetShowPageHeader, write=SetShowPageHeader, default=1};
	__property bool ShowPageRowHeader = {read=GetShowPageRowHeader, write=SetShowPageRowHeader, default=1};
	__property bool ShrinkToPageWidth = {read=GetShrinkToPageWidth, write=SetShrinkToPageWidth, default=0};
	__property int StartPageIndex = {read=GetStartPageIndex, write=SetStartPageIndex, default=1};
	__property System::UnicodeString StorageName = {read=FStorageName, write=SetStorageName};
	__property Dxpgsdlg::TdxPrintStyleManager* StyleManager = {read=FStyleManager, write=SetStyleManager};
	__property int TimeFormat = {read=GetTimeFormat, write=SetTimeFormat, stored=IsTimeFormatStored, default=0};
	__property TdxAssignedFormatValues AssignedFormatValues = {read=FAssignedFormatValues, write=SetAssignedFormatValues, default=0};
	__property System::Classes::TNotifyEvent OnChangeComponent = {read=FOnChangeComponent, write=FOnChangeComponent};
	__property TdxCustomDrawReportLinkHFEvent OnCustomDrawPageFooter = {read=FOnCustomDrawPageFooter, write=FOnCustomDrawPageFooter};
	__property TdxCustomDrawReportLinkHFEvent OnCustomDrawPageHeader = {read=FOnCustomDrawPageHeader, write=FOnCustomDrawPageHeader};
	__property TdxCustomDrawReportLinkTitleEvent OnCustomDrawReportLinkFootnotes = {read=FOnCustomDrawReportLinkFootnotes, write=FOnCustomDrawReportLinkFootnotes};
	__property TdxCustomDrawReportLinkTitleEvent OnCustomDrawReportLinkTitle = {read=FOnCustomDrawReportLinkTitle, write=FOnCustomDrawReportLinkTitle};
	__property System::Classes::TNotifyEvent OnDataSourceChanged = {read=FOnDataSourceChanged, write=FOnDataSourceChanged};
	__property System::Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property TdxFilterStyleEvent OnFilterStyle = {read=FOnFilterStyle, write=FOnFilterStyle};
	__property TdxPSGetNewReportStorageNameEvent OnGetNewReportStorageName = {read=FOnGetNewReportStorageName, write=FOnGetNewReportStorageName};
	__property TdxMeasureReportLinkTitleEvent OnMeasureReportLinkFootnotes = {read=FOnMeasureReportLinkFootnotes, write=FOnMeasureReportLinkFootnotes};
	__property TdxMeasureReportLinkTitleEvent OnMeasureReportLinkTitle = {read=FOnMeasureReportLinkTitle, write=FOnMeasureReportLinkTitle};
};


class DELPHICLASS TdxCompositionLinkItem;
class PASCALIMPLEMENTATION TdxCompositionLinkItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool FBuiltIn;
	TBasedxReportLink* FReportLink;
	System::UnicodeString FLoadingReportLinkName;
	void __fastcall SetReportLink(TBasedxReportLink* Value);
	void __fastcall ReadData(System::Classes::TReader* Reader);
	void __fastcall ReadLinkName(System::Classes::TReader* Reader);
	void __fastcall WriteData(System::Classes::TWriter* Writer);
	void __fastcall WriteLinkName(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall SetIndex(int Value);
	TdxCompositionReportLink* __fastcall Composition(void);
	
public:
	__fastcall virtual TdxCompositionLinkItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool BuiltIn = {read=FBuiltIn, write=FBuiltIn, nodefault};
	
__published:
	__property TBasedxReportLink* ReportLink = {read=FReportLink, write=SetReportLink};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxCompositionLinkItem(void) { }
	
};


class DELPHICLASS TdxCompositionLinkItemList;
class PASCALIMPLEMENTATION TdxCompositionLinkItemList : public System::Classes::TStringList
{
	typedef System::Classes::TStringList inherited;
	
private:
	TdxCompositionLinkItem* __fastcall GetObjectEx(int Index);
	TBasedxReportLink* __fastcall GetReportLink(int Index);
	
public:
	__property TdxCompositionLinkItem* Objects[int Index] = {read=GetObjectEx};
	__property TBasedxReportLink* ReportLinks[int Index] = {read=GetReportLink};
public:
	/* TStringList.Create */ inline __fastcall TdxCompositionLinkItemList(void)/* overload */ : System::Classes::TStringList() { }
	/* TStringList.Create */ inline __fastcall TdxCompositionLinkItemList(bool OwnsObjects)/* overload */ : System::Classes::TStringList(OwnsObjects) { }
	/* TStringList.Destroy */ inline __fastcall virtual ~TdxCompositionLinkItemList(void) { }
	
};


class DELPHICLASS TdxCompositionLinkItems;
class PASCALIMPLEMENTATION TdxCompositionLinkItems : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxCompositionLinkItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxCompositionReportLink* FComposition;
	bool FDontNeedRebuild;
	HIDESBASE TdxCompositionLinkItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxCompositionLinkItem* Value);
	
protected:
	void __fastcall CorrectLinksAfterLoadings(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TdxCompositionLinkItems(TdxCompositionReportLink* AComposition);
	HIDESBASE TdxCompositionLinkItem* __fastcall Add(void);
	TdxCompositionLinkItem* __fastcall AddLink(TBasedxReportLink* AReportLink);
	void __fastcall DeleteItemsByLink(TBasedxReportLink* AReportLink);
	void __fastcall DeleteNonBuiltIns(void);
	void __fastcall GetLinkEntries(TBasedxReportLink* AReportLink, System::Classes::TList* AList);
	int __fastcall IndexOfLink(TBasedxReportLink* AReportLink);
	bool __fastcall IsLinkComposable(TBasedxReportLink* AReportLink);
	bool __fastcall LinkExists(TBasedxReportLink* AReportLink);
	TdxCompositionLinkItem* __fastcall NextAssignedItem(TdxCompositionLinkItem* AnItem);
	bool __fastcall NonBuiltInsExists(void);
	TdxCompositionLinkItem* __fastcall PrevAssignedItem(TdxCompositionLinkItem* AnItem);
	__property TdxCompositionReportLink* Composition = {read=FComposition};
	__property TdxCompositionLinkItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxCompositionLinkItems(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSCompositionReportRenderRowInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FComposedLinks;
	TdxCompositionLinkItem* FItem;
	int FPageAbsoluteIndex;
	int FPageIndex;
	TBasedxReportLink* __fastcall GetComposedLink(int Index);
	int __fastcall GetComposedLinksCount(void);
	int __fastcall GetPageCount(void);
	TBasedxReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual void __fastcall CalculateContentInfo(TBasedxReportLink* AReportLink, /* out */ int &AOffset, /* out */ int &AHeight);
	
public:
	__fastcall virtual TdxPSCompositionReportRenderRowInfo(TdxCompositionLinkItem* AItem, int APageIndex, int APageAbsoluteIndex);
	__fastcall virtual ~TdxPSCompositionReportRenderRowInfo(void);
	int __fastcall CalculateContentAreaHeight(TBasedxReportLink* AReportLink);
	int __fastcall CalculateContentOffset(TBasedxReportLink* AReportLink);
	bool __fastcall CanCompose(TBasedxReportLink* AReportLink);
	bool __fastcall Compose(TBasedxReportLink* AReportLink);
	bool __fastcall ContainsPage(int APageIndex);
	int __fastcall GetPageIndexRelativeToReportLink(int APageIndex);
	bool __fastcall IsPartOfComposition(TBasedxReportLink* AReportLink);
	__property TBasedxReportLink* ComposedLinks[int Index] = {read=GetComposedLink};
	__property int ComposedLinksCount = {read=GetComposedLinksCount, nodefault};
	__property TdxCompositionLinkItem* Item = {read=FItem};
	__property int PageAbsoluteIndex = {read=FPageAbsoluteIndex, nodefault};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property int PageIndex = {read=FPageIndex, nodefault};
	__property TBasedxReportLink* ReportLink = {read=GetReportLink};
};


class DELPHICLASS TdxPSCompositionReportRenderInfo;
class PASCALIMPLEMENTATION TdxPSCompositionReportRenderInfo : public TdxPSReportRenderInfo
{
	typedef TdxPSReportRenderInfo inherited;
	
private:
	int FNonEmptyPageCount;
	int FPageColCount;
	int FPageRowCount;
	Cxclasses::TcxObjectList* FRowInfoList;
	TdxPSCompositionReportRenderRowInfo* __fastcall GetRowInfo(int Index);
	int __fastcall GetRowInfoCount(void);
	TdxCompositionReportLink* __fastcall GetReportLink(void);
	
protected:
	TdxPSCompositionReportRenderRowInfo* __fastcall AddRowInfo(TdxCompositionLinkItem* AItem, int AStartPageIndex, int AStartPageAbsoluteIndex);
	virtual int __fastcall CalculateNonEmptyPageCount(void);
	virtual int __fastcall CalculatePageColCount(void);
	virtual int __fastcall CalculatePageRowCount(void);
	bool __fastcall FindRowInfo(int APageIndex, /* out */ TdxPSCompositionReportRenderRowInfo* &ARowInfo);
	TdxCompositionLinkItemList* __fastcall GetItems(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall Refresh(void);
	HIDESBASE bool __fastcall GetCompositionInfo(TBasedxReportLink* AReportLink, int APageIndex, /* out */ TdxPSCompositionReportRenderRowInfo* &ARowInfo);
	virtual int __fastcall GetNonEmptyPageCount(void);
	virtual int __fastcall GetPageColCount(void);
	virtual int __fastcall GetPageRowCount(void);
	
public:
	__fastcall virtual TdxPSCompositionReportRenderInfo(TBasedxReportLink* AReportLink);
	__fastcall virtual ~TdxPSCompositionReportRenderInfo(void);
	__property TdxCompositionReportLink* ReportLink = {read=GetReportLink};
	__property TdxPSCompositionReportRenderRowInfo* RowInfo[int Index] = {read=GetRowInfo};
	__property int RowInfoCount = {read=GetRowInfoCount, nodefault};
};


class DELPHICLASS TdxPSCompositionReportRenderer;
class PASCALIMPLEMENTATION TdxPSCompositionReportRenderer : public TdxPSReportRenderer
{
	typedef TdxPSReportRenderer inherited;
	
private:
	HIDESBASE TdxPSCompositionReportRenderInfo* __fastcall GetRenderInfo(void);
	TdxCompositionReportLink* __fastcall GetReportLink(void);
	
public:
	virtual void __fastcall RenderPageEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &APageBounds, int APageIndex, int AContinuousPageIndex, int AZoomFactor);
	__property TdxPSCompositionReportRenderInfo* RenderInfo = {read=GetRenderInfo};
	__property TdxCompositionReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxPSReportRenderer.Create */ inline __fastcall virtual TdxPSCompositionReportRenderer(TBasedxReportLink* AReportLink) : TdxPSReportRenderer(AReportLink) { }
	/* TdxPSReportRenderer.Destroy */ inline __fastcall virtual ~TdxPSCompositionReportRenderer(void) { }
	
};


class DELPHICLASS TdxPSReportCompositionDocument;
class PASCALIMPLEMENTATION TdxPSReportCompositionDocument : public TdxPSReportDocument
{
	typedef TdxPSReportDocument inherited;
	
private:
	TdxCompositionReportLink* __fastcall GetReportLink(void);
	
public:
	virtual System::UnicodeString __fastcall DefaultDescription(void);
	__property TdxCompositionReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxPSReportDocument.Create */ inline __fastcall virtual TdxPSReportCompositionDocument(TBasedxReportLink* AReportLink) : TdxPSReportDocument(AReportLink) { }
	/* TdxPSReportDocument.Destroy */ inline __fastcall virtual ~TdxPSReportCompositionDocument(void) { }
	
};


typedef void __fastcall (__closure *TdxCompositionReportLinkEvent)(TdxCompositionReportLink* Sender, TdxCompositionLinkItem* AItem);

enum TdxCompositionState : unsigned char { csRebuildReportLink };

typedef System::Set<TdxCompositionState, TdxCompositionState::csRebuildReportLink, TdxCompositionState::csRebuildReportLink>  TdxCompositionStates;

enum TdxCompositionOption : unsigned char { coCanEdit, coShowDescription };

typedef System::Set<TdxCompositionOption, TdxCompositionOption::coCanEdit, TdxCompositionOption::coShowDescription>  TdxCompositionOptions;

class PASCALIMPLEMENTATION TdxCompositionReportLink : public TBasedxReportLink
{
	typedef TBasedxReportLink inherited;
	
private:
	TdxCompositionStates FCompositionState;
	bool FContinuousPageIndexes;
	TdxCompositionOptions FDesignerOptions;
	System::Classes::TList* FInvalidatedLinks;
	TdxCompositionLinkItems* FItems;
	bool FStartEachItemFromNewPage;
	TdxCompositionReportLinkEvent FOnAfterBuildReport;
	TdxCompositionReportLinkEvent FOnBeforeBuildReport;
	HIDESBASE TdxPSCompositionReportRenderer* __fastcall GetRenderer(void);
	HIDESBASE TdxPSCompositionReportRenderInfo* __fastcall GetRenderInfo(void);
	TdxPSReportCompositionDocument* __fastcall GetReportDocument(void);
	void __fastcall SetItems(TdxCompositionLinkItems* Value);
	HIDESBASE void __fastcall SetReportDocument(TdxPSReportCompositionDocument* Value);
	void __fastcall SetStartEachItemFromNewPage(bool AValue);
	void __fastcall ActivateLink(TBasedxReportLink* AReportLink);
	void __fastcall UpdateComposition(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	virtual void __fastcall ConstructReport(TdxReportCells* AReportCells);
	virtual void __fastcall DoCreateReport(void);
	virtual TdxPSReportRendererClass __fastcall GetRendererClass(void);
	virtual TdxPSReportRenderInfoClass __fastcall GetRenderInfoClass(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual void __fastcall ShowPageFooterChanged(void);
	virtual void __fastcall ShowPageHeaderChanged(void);
	virtual void __fastcall StdProcessDataSourceDontPresent(void);
	virtual bool __fastcall GetAllowContinuousPageIndexes(void);
	virtual bool __fastcall GetContinuousPageIndexes(void);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual int __fastcall GetReportHeight(void);
	virtual int __fastcall GetReportWidth(void);
	virtual void __fastcall SetContinuousPageIndexes(bool Value);
	DYNAMIC void __fastcall DoAfterBuildReport(TdxCompositionLinkItem* AItem);
	DYNAMIC void __fastcall DoBeforeBuildReport(TdxCompositionLinkItem* AItem);
	__classmethod virtual TdxPSReportDocumentClass __fastcall GetReportDocumentClass();
	__property TdxPSCompositionReportRenderer* Renderer = {read=GetRenderer};
	__property TdxPSCompositionReportRenderInfo* RenderInfo = {read=GetRenderInfo};
	
public:
	__fastcall virtual TdxCompositionReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCompositionReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultDesignerCaption(void);
	__classmethod virtual bool __fastcall CanBeUsedAsStub();
	__classmethod virtual bool __fastcall Serializable();
	virtual bool __fastcall DataProviderPresent(void);
	virtual bool __fastcall IsEmptyPage(int APageIndex);
	virtual bool __fastcall SupportsFootnotes(void);
	virtual bool __fastcall SupportsTitle(void);
	void __fastcall GetItems(System::Classes::TStrings* AStrings, bool AExcludeUnassigned);
	__property TdxCompositionStates CompositionState = {read=FCompositionState, nodefault};
	__property TdxPSReportCompositionDocument* ReportDocument = {read=GetReportDocument, write=SetReportDocument};
	
__published:
	__property ContinuousPageIndexes = {default=1};
	__property TdxCompositionOptions DesignerOptions = {read=FDesignerOptions, write=FDesignerOptions, default=3};
	__property TdxCompositionLinkItems* Items = {read=FItems, write=SetItems};
	__property bool StartEachItemFromNewPage = {read=FStartEachItemFromNewPage, write=SetStartEachItemFromNewPage, default=1};
	__property TdxCompositionReportLinkEvent OnAfterBuildReport = {read=FOnAfterBuildReport, write=FOnAfterBuildReport};
	__property TdxCompositionReportLinkEvent OnBeforeBuildReport = {read=FOnBeforeBuildReport, write=FOnBeforeBuildReport};
};


enum TdxReportLinkDesignWindowState : unsigned char { dwsInitialize };

typedef System::Set<TdxReportLinkDesignWindowState, TdxReportLinkDesignWindowState::dwsInitialize, TdxReportLinkDesignWindowState::dwsInitialize>  TdxReportLinkDesignWindowStates;

class PASCALIMPLEMENTATION TAbstractdxReportLinkDesignWindow : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
private:
	bool FApplyed;
	bool FModified;
	bool FPrevKeyPreview;
	TBasedxReportLink* FReportLink;
	HIDESBASE System::Classes::TComponent* __fastcall GetComponent(void);
	bool __fastcall GetIsDesigning(void);
	HIDESBASE bool __fastcall IsCaptionStored(void);
	void __fastcall SetModified(bool Value);
	HIDESBASE MESSAGE void __fastcall WMHelp(Winapi::Messages::TWMHelp &message);
	
protected:
	TdxReportLinkDesignWindowStates FState;
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall AfterRebuildReport(void);
	virtual void __fastcall BeforeRebuildReport(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall UpdateControlsState(void);
	__property bool Applyed = {read=FApplyed, write=FApplyed, nodefault};
	__property System::Classes::TComponent* Component = {read=GetComponent};
	
public:
	__fastcall virtual TAbstractdxReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	virtual bool __fastcall Execute(void);
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property bool Modified = {read=FModified, write=SetModified, nodefault};
	__property TBasedxReportLink* ReportLink = {read=FReportLink, write=FReportLink};
	__property TdxReportLinkDesignWindowStates State = {read=FState, nodefault};
	
__published:
	__property Caption = {stored=IsCaptionStored, default=0};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TAbstractdxReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TAbstractdxReportLinkDesignWindow(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TAbstractdxReportLinkDesignWindow(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


class DELPHICLASS TStandarddxReportLinkDesignWindow;
class PASCALIMPLEMENTATION TStandarddxReportLinkDesignWindow : public TAbstractdxReportLinkDesignWindow
{
	typedef TAbstractdxReportLinkDesignWindow inherited;
	
private:
	bool FAtLeastOneTimeApplied;
	int FUpdateControlsCount;
	void __fastcall SetAtLeastOneTimeApplied(bool Value);
	void __fastcall CreateStdButtons(void);
	void __fastcall PlaceStdButtons(void);
	void __fastcall RegroupStdButtons(void);
	
protected:
	System::Classes::TWndMethod FPrevPreviewHostWindowProc;
	DYNAMIC void __fastcall Resize(void);
	virtual bool __fastcall CanApply(void);
	virtual void __fastcall DoApply(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall ApplyClick(System::TObject* Sender);
	virtual void __fastcall FootnotesPropertiesClick(System::TObject* Sender);
	virtual void __fastcall RestoreDefaultsClick(System::TObject* Sender);
	virtual void __fastcall RestoreOriginalClick(System::TObject* Sender);
	virtual void __fastcall TitlePropertiesClick(System::TObject* Sender);
	virtual void __fastcall DoInitialize(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall PreviewHostWindowProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall UpdatePreview(void);
	__property bool AtLeastOneTimeApplied = {read=FAtLeastOneTimeApplied, write=SetAtLeastOneTimeApplied, nodefault};
	__property Vcl::Extctrls::TCustomPanel* PreviewHost = {read=GetPreviewHost};
	__property int UpdateControlsCount = {read=FUpdateControlsCount, nodefault};
	
public:
	__fastcall virtual TStandarddxReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TStandarddxReportLinkDesignWindow(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeginUpdateControls(void);
	virtual void __fastcall EndUpdateControls(void);
	bool __fastcall LockControlsUpdate(void);
	
__published:
	Cxbuttons::TcxButton* btnApply;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnFootnoteProperties;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnRestoreDefaults;
	Cxbuttons::TcxButton* btnRestoreOriginal;
	Cxbuttons::TcxButton* btnTitleProperties;
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TStandarddxReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : TAbstractdxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TStandarddxReportLinkDesignWindow(HWND ParentWindow) : TAbstractdxReportLinkDesignWindow(ParentWindow) { }
	
};


class DELPHICLASS TdxPSPrintStyle;
class PASCALIMPLEMENTATION TdxPSPrintStyle : public Dxpgsdlg::TBasedxPrintStyle
{
	typedef Dxpgsdlg::TBasedxPrintStyle inherited;
	
private:
	System::Classes::TNotifyEvent FOnAfterGenerating;
	System::Classes::TNotifyEvent FOnAfterPrinting;
	System::Classes::TNotifyEvent FOnBeforeGenerating;
	System::Classes::TNotifyEvent FOnBeforePrinting;
	void __fastcall AfterGenerating(void);
	void __fastcall BeforeGenerating(void);
	
protected:
	virtual void __fastcall AddStdHFFunctions(void);
	virtual void __fastcall DoAfterGenerating(void);
	DYNAMIC void __fastcall DoAfterPrinting(void);
	virtual void __fastcall DoBeforeGenerating(void);
	DYNAMIC void __fastcall DoBeforePrinting(void);
	virtual void __fastcall InitializeDefaultStyleGlyph(Vcl::Graphics::TBitmap* ABitmap);
	
public:
	__fastcall virtual TdxPSPrintStyle(System::Classes::TComponent* AOwner);
	virtual System::UnicodeString __fastcall DefaultPageFooterText(Dxprnpg::TdxPageTitlePart APart);
	virtual System::UnicodeString __fastcall DefaultStyleCaption(void);
	
__published:
	__property System::Classes::TNotifyEvent OnAfterGenerating = {read=FOnAfterGenerating, write=FOnAfterGenerating};
	__property System::Classes::TNotifyEvent OnAfterPrinting = {read=FOnAfterPrinting, write=FOnAfterPrinting};
	__property System::Classes::TNotifyEvent OnBeforeGenerating = {read=FOnBeforeGenerating, write=FOnBeforeGenerating};
	__property System::Classes::TNotifyEvent OnBeforePrinting = {read=FOnBeforePrinting, write=FOnBeforePrinting};
public:
	/* TBasedxPrintStyle.Destroy */ inline __fastcall virtual ~TdxPSPrintStyle(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSCustomPreviewWindow : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TCustomdxComponentPrinter* FComponentPrinter;
	bool FIsDestroying;
	Vcl::Forms::TForm* __fastcall GetOwnerForm(void);
	TBasedxReportLink* __fastcall GetReportLink(void);
	void __fastcall SetComponentPrinter(TCustomdxComponentPrinter* AValue);
	
protected:
	bool FIsFormPositionAssigned;
	virtual void __fastcall AddExplorerContextCommand(TCustomdxPSExplorerContextCommand* ACommand) = 0 ;
	virtual void __fastcall UpdateExplorerContextCommands(void) = 0 ;
	virtual int __fastcall GetActivePageIndex(void) = 0 ;
	virtual Dxbkgnd::TdxBackground* __fastcall GetBackground(void) = 0 ;
	virtual TCustomdxPSExplorerTreeContainer* __fastcall GetExplorerTree(void);
	virtual Dxprnpg::TdxPageTitlePart __fastcall GetHFEditPart(void);
	virtual int __fastcall GetPageCount(void) = 0 ;
	virtual TdxPreviewEnableOptions __fastcall GetPreviewEnableOptions(void) = 0 ;
	virtual TdxPreviewVisibleOptions __fastcall GetPreviewVisibleOptions(void) = 0 ;
	virtual bool __fastcall GetSaveZoomPosition(void) = 0 ;
	virtual bool __fastcall GetShowExplorer(void);
	virtual bool __fastcall GetShowThumbnails(void);
	virtual TdxPSPreviewState __fastcall GetState(void);
	virtual TdxPSThumbnailsSize __fastcall GetThumbnailsSize(void) = 0 ;
	virtual System::Types::TPoint __fastcall GetVisiblePageSize(void) = 0 ;
	virtual int __fastcall GetZoomFactor(void) = 0 ;
	virtual void __fastcall SetActivePageIndex(int Value) = 0 ;
	virtual void __fastcall SetBackground(Dxbkgnd::TdxBackground* const Value) = 0 ;
	virtual void __fastcall SetHFEditPart(const Dxprnpg::TdxPageTitlePart Value) = 0 ;
	virtual void __fastcall SetPageCount(int Value) = 0 ;
	virtual void __fastcall SetPreviewEnableOptions(const TdxPreviewEnableOptions Value) = 0 ;
	virtual void __fastcall SetPreviewVisibleOptions(const TdxPreviewVisibleOptions Value) = 0 ;
	virtual void __fastcall SetSaveZoomPosition(bool Value) = 0 ;
	virtual void __fastcall SetShowExplorer(bool Value);
	virtual void __fastcall SetShowThumbnails(bool Value);
	virtual void __fastcall SetState(const TdxPSPreviewState Value) = 0 ;
	virtual void __fastcall SetThumbnailsSize(const TdxPSThumbnailsSize Value) = 0 ;
	virtual void __fastcall SetZoomFactor(int Value) = 0 ;
	virtual void __fastcall AfterComponentPrinterChanged(void);
	virtual void __fastcall BeforeComponentPrinterChanged(void);
	virtual void __fastcall CreationComplete(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall PaintPage(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, int APageIndex);
	virtual void __fastcall PaintThumbnailPage(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, int APageIndex);
	void __fastcall UpdateCaption(void);
	__property bool IsDestroying = {read=FIsDestroying, nodefault};
	
public:
	__fastcall virtual TdxPSCustomPreviewWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPSCustomPreviewWindow(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall GoToFirstPage(void) = 0 ;
	virtual void __fastcall GoToLastPage(void) = 0 ;
	virtual void __fastcall GoToNextPage(void) = 0 ;
	virtual void __fastcall GoToPrevPage(void) = 0 ;
	virtual void __fastcall InitContent(void);
	virtual void __fastcall InvalidateContent(void);
	virtual void __fastcall InvalidatePage(int APageIndex);
	virtual void __fastcall InvalidateAllPages(void);
	virtual void __fastcall InvalidatePagesContent(void);
	virtual void __fastcall InvalidatePagesHeaderContent(void);
	virtual void __fastcall InvalidatePagesFooterContent(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName)/* overload */;
	void __fastcall LoadFromIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall LoadFromRegistry(const System::UnicodeString APath);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName)/* overload */;
	void __fastcall SaveToIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall SaveToRegistry(const System::UnicodeString APath);
	virtual void __fastcall FullRefresh(void) = 0 ;
	virtual void __fastcall RebuildReport(void);
	virtual void __fastcall ReleaseForm(void);
	HIDESBASE virtual void __fastcall Show(bool AModal);
	virtual void __fastcall UpdateControls(void);
	virtual bool __fastcall Locked(void);
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall CancelUpdate(void);
	virtual void __fastcall EndUpdate(void);
	__property int ActivePageIndex = {read=GetActivePageIndex, write=SetActivePageIndex, nodefault};
	__property Dxbkgnd::TdxBackground* Background = {read=GetBackground, write=SetBackground};
	__property TCustomdxComponentPrinter* ComponentPrinter = {read=FComponentPrinter, write=SetComponentPrinter};
	__property TdxPreviewEnableOptions EnableOptions = {read=GetPreviewEnableOptions, write=SetPreviewEnableOptions, nodefault};
	__property TCustomdxPSExplorerTreeContainer* ExplorerTree = {read=GetExplorerTree};
	__property Vcl::Forms::TForm* Form = {read=GetOwnerForm};
	__property Dxprnpg::TdxPageTitlePart HFEditPart = {read=GetHFEditPart, write=SetHFEditPart, nodefault};
	__property int PageCount = {read=GetPageCount, write=SetPageCount, nodefault};
	__property TBasedxReportLink* ReportLink = {read=GetReportLink};
	__property bool SaveZoomPosition = {read=GetSaveZoomPosition, write=SetSaveZoomPosition, nodefault};
	__property bool ShowExplorer = {read=GetShowExplorer, write=SetShowExplorer, nodefault};
	__property bool ShowThumbnails = {read=GetShowThumbnails, write=SetShowThumbnails, nodefault};
	__property TdxPSPreviewState State = {read=GetState, write=SetState, nodefault};
	__property TdxPSThumbnailsSize ThumbnailsSize = {read=GetThumbnailsSize, write=SetThumbnailsSize, nodefault};
	__property TdxPreviewVisibleOptions VisibleOptions = {read=GetPreviewVisibleOptions, write=SetPreviewVisibleOptions, nodefault};
	__property System::Types::TPoint VisiblePageSize = {read=GetVisiblePageSize};
	__property int ZoomFactor = {read=GetZoomFactor, write=SetZoomFactor, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSCustomPreviewWindow(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxPSExplorerContextCommandBuilder;	/* IdxPSExplorerContextCommandBuilder */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EE36E842-FD6A-4A89-A343-A32828AEFE3D}
	operator _di_IdxPSExplorerContextCommandBuilder()
	{
		_di_IdxPSExplorerContextCommandBuilder intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxPSExplorerContextCommandBuilder*(void) { return (IdxPSExplorerContextCommandBuilder*)&__IdxPSExplorerContextCommandBuilder; }
	#endif
	
};


typedef System::TMetaClass* TdxPreviewWindowClass;

class DELPHICLASS TdxComponentPrinterThumbnailsOptions;
class DELPHICLASS TdxPreviewOptions;
class PASCALIMPLEMENTATION TdxComponentPrinterThumbnailsOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Vcl::Graphics::TFont* FDefaultFont;
	Vcl::Graphics::TFont* FFont;
	TdxPreviewOptions* FPreviewOptions;
	bool FShowPageNumbers;
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetShowPageNumbers(bool Value);
	
protected:
	virtual void __fastcall InitializeDefaultFont(Vcl::Graphics::TFont* AFont);
	virtual bool __fastcall IsFontStored(void);
	
public:
	__fastcall virtual TdxComponentPrinterThumbnailsOptions(TdxPreviewOptions* APreviewOptions);
	__fastcall virtual ~TdxComponentPrinterThumbnailsOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Vcl::Graphics::TFont* __fastcall DefaultFont(void);
	virtual void __fastcall RestoreDefaults(void);
	__property TdxPreviewOptions* PreviewOptions = {read=FPreviewOptions};
	
__published:
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property bool ShowPageNumbers = {read=FShowPageNumbers, write=SetShowPageNumbers, default=1};
};


class PASCALIMPLEMENTATION TdxPreviewOptions : public Dxbase::TdxBaseObject
{
	typedef Dxbase::TdxBaseObject inherited;
	
private:
	System::UnicodeString FCaption;
	TCustomdxComponentPrinter* FComponentPrinter;
	Vcl::Graphics::TIcon* FDefaultIcon;
	TdxPreviewEnableOptions FEnableOptions;
	Vcl::Graphics::TIcon* FIcon;
	System::Classes::THelpContext FHelpContext;
	bool FIsBoundsAssigned;
	bool FIsCaptionAssigned;
	bool FIsIconAssigned;
	System::Types::TRect FRect;
	bool FSavePosition;
	bool FSaveZoomPosition;
	bool FShowExplorer;
	TdxComponentPrinterThumbnailsOptions* FThumbnailsOptions;
	TdxPreviewVisibleOptions FVisibleOptions;
	System::Uitypes::TWindowState FWindowState;
	System::UnicodeString __fastcall GetCaption(void);
	bool __fastcall GetHasPreviewWindow(void);
	System::UnicodeString __fastcall GetHelpFile(void);
	Vcl::Graphics::TIcon* __fastcall GetIcon(void);
	int __fastcall GetPosition(int index);
	TdxPSCustomPreviewWindow* __fastcall GetPreviewWindow(void);
	Vcl::Forms::TForm* __fastcall GetPreviewWindowForm(void);
	System::Types::TRect __fastcall GetRect(void);
	bool __fastcall IsBoundsStored(void);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsIconStored(void);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetEnableOptions(TdxPreviewEnableOptions Value);
	void __fastcall SetHelpContext(System::Classes::THelpContext Value);
	void __fastcall SetHelpFile(const System::UnicodeString Value);
	void __fastcall SetIcon(Vcl::Graphics::TIcon* Value);
	void __fastcall SetPosition(int Index, int Value);
	void __fastcall SetRect(System::Types::TRect &Value);
	void __fastcall SetShowExplorer(bool Value);
	void __fastcall SetThumbnailsOptions(TdxComponentPrinterThumbnailsOptions* Value);
	void __fastcall SetVisibleOptions(TdxPreviewVisibleOptions Value);
	void __fastcall SetWindowState(System::Uitypes::TWindowState Value);
	void __fastcall ReadBoundsRect(System::Classes::TStream* Stream);
	void __fastcall ReadIsCaptionAssigned(System::Classes::TReader* Reader);
	void __fastcall ReadIsIconAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteBoundsRect(System::Classes::TStream* Stream);
	void __fastcall WriteIsCaptionAssigned(System::Classes::TWriter* Writer);
	void __fastcall WriteIsIconAssigned(System::Classes::TWriter* Writer);
	__property bool HasPreviewWindow = {read=GetHasPreviewWindow, nodefault};
	__property TdxPSCustomPreviewWindow* PreviewWindow = {read=GetPreviewWindow};
	__property Vcl::Forms::TForm* PreviewWindowForm = {read=GetPreviewWindowForm};
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoAssign(Dxbase::TdxBaseObject* Source);
	virtual void __fastcall DoRestoreDefaults(void);
	bool __fastcall GetIsIconAssigned(void);
	virtual void __fastcall IconChanged(System::TObject* Sender);
	virtual void __fastcall InitializeDefaultIcon(Vcl::Graphics::TIcon* AnIcon);
	void __fastcall RefreshIsIconAssigned(void);
	
public:
	__fastcall virtual TdxPreviewOptions(void);
	__fastcall virtual ~TdxPreviewOptions(void);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual Vcl::Graphics::TIcon* __fastcall DefaultIcon(void);
	virtual System::Types::TRect __fastcall DefaultRect(void);
	void __fastcall RestoreOriginalIcon(void);
	void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TCustomdxComponentPrinter* ComponentPrinter = {read=FComponentPrinter};
	__property bool IsIconAssigned = {read=FIsIconAssigned, nodefault};
	__property System::Types::TRect Rect = {read=GetRect, write=SetRect};
	
__published:
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property TdxPreviewEnableOptions EnableOptions = {read=FEnableOptions, write=SetEnableOptions, default=125};
	__property int Height = {read=GetPosition, write=SetPosition, stored=false, index=0, nodefault};
	__property System::Classes::THelpContext HelpContext = {read=FHelpContext, write=SetHelpContext, default=0};
	__property System::UnicodeString HelpFile = {read=GetHelpFile, write=SetHelpFile, stored=false};
	__property Vcl::Graphics::TIcon* Icon = {read=GetIcon, write=SetIcon, stored=IsIconStored};
	__property int Left = {read=GetPosition, write=SetPosition, stored=false, index=1, nodefault};
	__property bool SavePosition = {read=FSavePosition, write=FSavePosition, stored=false, default=1};
	__property bool SaveZoomPosition = {read=FSaveZoomPosition, write=FSaveZoomPosition, default=1};
	__property bool ShowExplorer = {read=FShowExplorer, write=SetShowExplorer, default=0};
	__property TdxComponentPrinterThumbnailsOptions* ThumbnailsOptions = {read=FThumbnailsOptions, write=SetThumbnailsOptions};
	__property int Top = {read=GetPosition, write=SetPosition, stored=false, index=2, nodefault};
	__property TdxPreviewVisibleOptions VisibleOptions = {read=FVisibleOptions, write=SetVisibleOptions, default=510};
	__property int Width = {read=GetPosition, write=SetPosition, stored=false, index=3, nodefault};
	__property System::Uitypes::TWindowState WindowState = {read=FWindowState, write=SetWindowState, default=0};
};


typedef void __fastcall (__closure *TdxBeforeDesignReportEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, TAbstractdxReportLinkDesignWindow* ADesignWindow);

typedef void __fastcall (__closure *TdxCustomDrawPageEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, Vcl::Graphics::TCanvas* ACanvas, int APageIndex, System::Types::TRect &ARect, int ANom, int ADenom);

typedef void __fastcall (__closure *TdxCustomDrawReportTitleEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, int ANom, int ADenom, Cxdrawtextutils::TcxTextAlignX &TextAlignX, Cxdrawtextutils::TcxTextAlignY &TextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone);

typedef void __fastcall (__closure *TdxCustomDrawPageHFEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, Vcl::Graphics::TCanvas* ACanvas, int APageIndex, System::Types::TRect &ARect, int ANom, int ADenom, bool &ADefaultDrawText, bool &ADefaultDrawBackground);

typedef void __fastcall (__closure *TdxDesignReportEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, bool &ADone);

typedef void __fastcall (__closure *TdxGenerateReportProgressEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, double APercentDone);

typedef void __fastcall (__closure *TdxGetPrintTitleEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, System::UnicodeString &ATitle);

typedef void __fastcall (__closure *TdxPrintDlgDataEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, Dxprndlg::TdxPrintDlgData &APrintDlgData);

typedef void __fastcall (__closure *TdxMeasureReportTitleEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, int &AHeight);

typedef void __fastcall (__closure *TdxNewPageEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, int APageIndex);

typedef void __fastcall (__closure *TdxPageSetupEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, bool ADone);

typedef void __fastcall (__closure *TdxPreviewEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink);

typedef void __fastcall (__closure *TdxPrintDeviceProblemEvent)(System::TObject* Sender, bool &ADone);

typedef void __fastcall (__closure *TdxReportLinkBeforeExportToPDFEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, const System::UnicodeString AFileName, TdxPSPDFReportExportOptions* AOptions, bool &AAllow);

typedef void __fastcall (__closure *TdxReportLinkNotifyEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink);

typedef void __fastcall (__closure *TdxStartPrintEvent)(System::TObject* Sender, TBasedxReportLink* AReportLink, int APageCount);

enum TdxCPOption : unsigned char { cpoAutoRebuildBeforePreview, cpoAutoRebuildBeforePrint, cpoGenerateReportProgressEvent, cpoShowHourGlass, cpoDropStorageModeAfterPreview };

typedef System::Set<TdxCPOption, TdxCPOption::cpoAutoRebuildBeforePreview, TdxCPOption::cpoDropStorageModeAfterPreview>  TdxCPOptions;

enum TdxCPState : unsigned char { cpsBuilding, cpsDesigning, cpsPreviewing, cpsPrinting, cpsPrintDialog, cpsPageSetupDialog, cpsDefineStylesDialog, cpsCustomizing, cpsLoading, cpsSaving, cpsExplore };

typedef System::Set<TdxCPState, TdxCPState::cpsBuilding, TdxCPState::cpsExplore>  TdxCPStates;

enum TdxPSBuildStage : unsigned char { bsStart, bsProgress, bsEnd };

enum TdxPSPrintStage : unsigned char { psStart, psProgress, psEnd };

class DELPHICLASS TdxPSComponentPrinterExplorerChangeNotifier;
class PASCALIMPLEMENTATION TdxPSComponentPrinterExplorerChangeNotifier : public TdxPSExplorerChangeNotifierAdapter
{
	typedef TdxPSExplorerChangeNotifierAdapter inherited;
	
private:
	TCustomdxComponentPrinter* FComponentPrinter;
	
protected:
	virtual void __fastcall ItemDataUnloaded(TdxPSExplorerItem* AnItem);
	
public:
	__fastcall TdxPSComponentPrinterExplorerChangeNotifier(TCustomdxComponentPrinter* AComponentPrinter);
	__property TCustomdxComponentPrinter* ComponentPrinter = {read=FComponentPrinter};
public:
	/* TdxPSExplorerChangeNotifier.Destroy */ inline __fastcall virtual ~TdxPSComponentPrinterExplorerChangeNotifier(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSPrintPageRangeInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxpsglbl::TIntegers FPageIndexes;
	Dxprndlg::TdxPageRanges FPageRanges;
	int __fastcall GetPageIndex(int Index);
	int __fastcall GetPageIndexCount(void);
	System::UnicodeString __fastcall GetPageIndexesAsString(void);
	void __fastcall SetPageIndexesAsString(const System::UnicodeString AValue);
	
public:
	__fastcall virtual TdxPSPrintPageRangeInfo(void);
	__fastcall virtual ~TdxPSPrintPageRangeInfo(void);
	void __fastcall Assign(TdxPSPrintPageRangeInfo* AInfo);
	__property int PageIndex[int Index] = {read=GetPageIndex};
	__property int PageIndexCount = {read=GetPageIndexCount, nodefault};
	__property System::UnicodeString PageIndexesAsString = {read=GetPageIndexesAsString, write=SetPageIndexesAsString};
	__property Dxprndlg::TdxPageRanges PageRanges = {read=FPageRanges, write=FPageRanges, nodefault};
};


class DELPHICLASS TAbstractdxPreviewWindowDesigner;
class DELPHICLASS TAbstractdxReportLinkDesigner;
class PASCALIMPLEMENTATION TCustomdxComponentPrinter : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
public:
	TBasedxReportLink* operator[](int Index) { return ReportLink[Index]; }
	
private:
	bool FAbortBuilding;
	bool FAbortPrinting;
	bool FAutoUpdateDateTime;
	bool FBeepAfterLongOperations;
	TBasedxReportLink* FCurrentLink;
	int FDateFormat;
	TCustomdxPSExplorer* FExplorer;
	TdxPSComponentPrinterExplorerChangeNotifier* FExplorerChangeNotifier;
	TBasedxReportLink* FExplorerStubLink;
	bool FInternalStreaming;
	int FLongOperationTime;
	TdxCPOptions FOptions;
	Dxpsglbl::TdxPageNumberFormat FPageNumberFormat;
	TdxPreviewOptions* FPreviewOptions;
	TdxPSCustomPreviewWindow* FPreviewWindow;
	TAbstractdxPreviewWindowDesigner* FPreviewWindowDesigner;
	System::Classes::TStrings* FPrintFileList;
	System::UnicodeString FPrintTitle;
	TAbstractdxReportLinkDesigner* FReportLinkDesigner;
	System::Classes::TList* FReportLinks;
	TdxCPStates FState;
	int FTimeFormat;
	int FVersion;
	TdxReportLinkNotifyEvent FOnAddReportLink;
	TdxPreviewEvent FOnAfterPreview;
	TdxBeforeDesignReportEvent FOnBeforeDesignReport;
	TdxReportLinkBeforeExportToPDFEvent FOnBeforeExportToPDF;
	TdxPreviewEvent FOnBeforePreview;
	TdxReportLinkNotifyEvent FOnChangeComponent;
	System::Classes::TNotifyEvent FOnChangeCurrentLink;
	TdxCustomDrawPageEvent FOnCustomDrawPage;
	TdxCustomDrawPageHFEvent FOnCustomDrawPageFooter;
	TdxCustomDrawPageHFEvent FOnCustomDrawPageHeader;
	TdxCustomDrawReportTitleEvent FOnCustomDrawReportFootnotes;
	TdxCustomDrawReportTitleEvent FOnCustomDrawReportTitle;
	TdxReportLinkNotifyEvent FOnDeleteReportLink;
	TdxDesignReportEvent FOnDesignReport;
	TdxReportLinkNotifyEvent FOnEndGenerateReport;
	TdxReportLinkNotifyEvent FOnEndPrint;
	TdxPrintDlgDataEvent FOnFinalizePrintDlgData;
	TdxGenerateReportProgressEvent FOnGenerateReportProgress;
	TdxGetPrintTitleEvent FOnGetPrintTitle;
	TdxPrintDlgDataEvent FOnInitializePrintDlgData;
	TdxMeasureReportTitleEvent FOnMeasureReportFootnotes;
	TdxMeasureReportTitleEvent FOnMeasureReportTitle;
	TdxNewPageEvent FOnNewPage;
	TdxPageSetupEvent FOnPageSetup;
	TdxPrintDeviceProblemEvent FOnPrintDeviceBusy;
	TdxPrintDeviceProblemEvent FOnPrintDeviceError;
	TdxReportLinkNotifyEvent FOnStartGenerateReport;
	TdxStartPrintEvent FOnStartPrint;
	unsigned FEndTime;
	Dxpsesys::TdxEventSubscriber* FHFTextEntryChooseSubscriber;
	int FLongOperationCounter;
	System::Classes::TStream* FMemoryStream;
	bool FModalPreview;
	bool FPrintAll;
	int FSavePageIndex;
	bool FSavePrintToFile;
	unsigned FStartTime;
	HWND FWindowHandle;
	int __fastcall GetCurrentLinkIndex(void);
	TBasedxReportLink* __fastcall GetExplorerRealStubLink(void);
	bool __fastcall GetIsExplorerMode(void);
	int __fastcall GetLinkCount(void);
	System::UnicodeString __fastcall GetPreviewCaption(void);
	TBasedxReportLink* __fastcall GetReportLink(int index);
	void __fastcall SetAbortBuilding(bool Value);
	void __fastcall SetAbortPrinting(bool Value);
	void __fastcall SetAutoUpdateDateTime(bool Value);
	void __fastcall SetCurrentLink(TBasedxReportLink* Value);
	void __fastcall SetCurrentLinkIndex(int Value);
	void __fastcall SetDateFormat(int Value);
	void __fastcall SetExplorer(TCustomdxPSExplorer* Value);
	void __fastcall SetExplorerStubLink(TBasedxReportLink* Value);
	void __fastcall SetLongOperationTime(int Value);
	void __fastcall SetPageNumberFormat(Dxpsglbl::TdxPageNumberFormat Value);
	void __fastcall SetPreviewOptions(TdxPreviewOptions* Value);
	void __fastcall SetPrintFileList(System::Classes::TStrings* Value);
	void __fastcall SetReportLink(int index, TBasedxReportLink* Value);
	void __fastcall SetTimeFormat(int Value);
	bool __fastcall BeginPrintPages(const System::UnicodeString Source, /* out */ Dxpsglbl::TIntegers &APageIndexes);
	void __fastcall EndPrintPages(Dxpsglbl::TIntegers &APageIndexes);
	TdxPSCustomPreviewWindow* __fastcall CreatePreviewWindow(TBasedxReportLink* AReportLink);
	void __fastcall DestroyPreviewWindow(void);
	void __fastcall ReleasePreviewWindowForm(void);
	virtual void __fastcall FinalizeDefaultPrintDlgData(TBasedxReportLink* AReportLink, Dxprndlg::TdxPrintDlgData &APrintDlgData);
	virtual void __fastcall InitializeDefaultPrintDlgData(TBasedxReportLink* AReportLink, /* out */ Dxprndlg::TdxPrintDlgData &APrintDlgData);
	void __fastcall InitDevModeFromPrinterPageSettings(Dxprnpg::TdxPrinterPage* APrinterPage);
	bool __fastcall PrintDialog(TBasedxReportLink* AReportLink, Dxprndlg::TdxPrintDlgData &APrintDlgData);
	bool __fastcall PrintPagesAsStringEx(const System::UnicodeString APages, Dxprndlg::TdxPageNumbers APageNums, int ACopyCount, bool ACollate, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall PrnDlgPageSetup(System::TObject* Sender, bool &ADone, System::PBoolean APreviewBtnClicked, System::PBoolean APrintBtnClicked);
	void __fastcall RaiseBuildingEvent(TBasedxReportLink* AReportLink, const double APercentCompleted, TdxPSBuildStage AStage);
	void __fastcall RaisePrintingEvent(TBasedxReportLink* AReportLink, int APageIndex, int APageCount, TdxPSPrintStage AStage);
	void __fastcall ActivateLink(TBasedxReportLink* AReportLink);
	TBasedxReportLink* __fastcall CheckLink(TBasedxReportLink* Value);
	TBasedxReportLink* __fastcall CreateLink(TdxReportLinkClass ALinkClass, System::Classes::TComponent* AComponent, System::Classes::TComponent* AOwner);
	void __fastcall DeactivateLink(TBasedxReportLink* AReportLink);
	void __fastcall InsertLink(TBasedxReportLink* Value);
	void __fastcall MoveLink(int ACurIndex, int ANewIndex);
	void __fastcall RemoveLink(TBasedxReportLink* Value);
	void __fastcall ResyncCurrentLink(int AIndex);
	void __fastcall OnHFTextEntryChosen(System::TObject* Sender, const System::UnicodeString AEntry);
	void __fastcall SetupPreviewProperties(TdxPSCustomPreviewWindow* APreviewWindow);
	void __fastcall DesignerModified(void);
	void __fastcall DesignerUpdate(TBasedxReportLink* AnItem);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall DoAddReportLink(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoAfterPreview(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoBeforeDesignReport(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoBeforeDestroyReport(TBasedxReportLink* AReportLink);
	DYNAMIC bool __fastcall DoBeforeExportToPDF(TBasedxReportLink* AReportLink, const System::UnicodeString AFileName, TdxPSPDFReportExportOptions* AOptions);
	DYNAMIC void __fastcall DoBeforePreview(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoChangeComponent(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoChangeCurrentLink(void);
	virtual void __fastcall DoCustomDrawEntirePage(TBasedxReportLink* AReportLink, Vcl::Graphics::TCanvas* ACanvas, int APageIndex, System::Types::TRect &ARect, int ANom, int ADenom);
	virtual void __fastcall DoCustomDrawPageHeaderOrFooter(TBasedxReportLink* AReportLink, Dxprnpg::TCustomdxPageObject* AHFObject, Vcl::Graphics::TCanvas* ACanvas, int APageIndex, System::Types::TRect &R, bool &ADefaultDrawText, bool &ADefaultDrawBackground, int APixelsNumerator = 0x0);
	virtual void __fastcall DoCustomDrawReportFootnotes(TBasedxReportLink* AReportLink, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone, int APixelsNumerator = 0x0);
	virtual void __fastcall DoCustomDrawReportTitle(TBasedxReportLink* AReportLink, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone, int APixelsNumerator = 0x0);
	DYNAMIC void __fastcall DoDeleteReportLink(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoDesignReport(TBasedxReportLink* AReportLink, bool ADone);
	DYNAMIC void __fastcall DoEndPrint(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoFinalizePrintDlgData(TBasedxReportLink* AReportLink, Dxprndlg::TdxPrintDlgData &APrintDlgData);
	DYNAMIC void __fastcall DoInitializePrintDlgData(TBasedxReportLink* AReportLink, Dxprndlg::TdxPrintDlgData &APrintDlgData);
	virtual void __fastcall DoMeasureReportFootnotes(TBasedxReportLink* AReportLink, int &AHeight);
	virtual void __fastcall DoMeasureReportTitle(TBasedxReportLink* AReportLink, int &AHeight);
	DYNAMIC void __fastcall DoNewPage(TBasedxReportLink* AReportLink, int APageIndex);
	void __fastcall DoPageParamsChanged(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoPageSetup(TBasedxReportLink* AReportLink, bool ADone);
	virtual void __fastcall DoPreviewWindowDestroyed(TdxPSCustomPreviewWindow* APreviewWindow);
	DYNAMIC void __fastcall DoPrintDeviceBusy(void);
	DYNAMIC void __fastcall DoPrintDeviceError(void);
	DYNAMIC void __fastcall DoProgress(TBasedxReportLink* AReportLink, const double PercentDone);
	DYNAMIC void __fastcall DoStartPrint(TBasedxReportLink* AReportLink, int FullPageCount);
	DYNAMIC void __fastcall DoStartUpdateReport(TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoEndUpdateReport(TBasedxReportLink* AReportLink);
	DYNAMIC System::UnicodeString __fastcall GetPrintTitle(TBasedxReportLink* AReportLink);
	virtual void __fastcall StdProcessPrintDeviceBusy(void);
	virtual void __fastcall StdProcessPrintDeviceError(void);
	bool __fastcall IsCustomPrintDlgData(void);
	bool __fastcall IsForegroundPreviewWindow(void);
	bool __fastcall IsGenerateReportProgressEvent(void);
	bool __fastcall IsRebuildBeforeOutput(bool AForceRebuild);
	bool __fastcall IsRebuildBeforePreview(void);
	bool __fastcall IsRebuildBeforePrint(void);
	bool __fastcall IsShowHourGlass(void);
	void __fastcall PaintThumbnailPage(Vcl::Graphics::TCanvas* ACanvas, int APageIndex, const System::Types::TRect &APageBounds, const System::Types::TRect &AContentBounds, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall PaintThumbnailPageIndex(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, int APageIndex);
	void __fastcall FormatChanged(TBasedxReportLink* AReportLink);
	void __fastcall PreparePageSetup(void);
	void __fastcall PrepareBuildReport(TBasedxReportLink* AReportLink);
	void __fastcall PrepareLongOperation(void);
	void __fastcall PrepareReport(TBasedxReportLink* AReportLink);
	virtual void __fastcall PrintPage(TBasedxReportLink* AReportLink, int APageIndex);
	void __fastcall UnprepareBuildReport(TBasedxReportLink* AReportLink);
	void __fastcall UnprepareLongOperation(void);
	void __fastcall UnpreparePageSetup(void);
	void __fastcall UnprepareReport(TBasedxReportLink* AReportLink);
	void __fastcall AfterLoadFromStream(System::Classes::TStream* AStream);
	void __fastcall BeforeLoadFromStream(System::Classes::TStream* AStream);
	void __fastcall ErrorLoadFromStream(System::Classes::TStream* AStream);
	void __fastcall LoadItselfFromStream(System::Classes::TStream* AStream);
	void __fastcall LoadLinksFromStream(System::Classes::TStream* AStream);
	void __fastcall LoadVersionFromStream(System::Classes::TStream* AStream, int &AVersion);
	void __fastcall PrepareLoadFromStream(System::Classes::TStream* AStream);
	void __fastcall UnprepareLoadFromStream(System::Classes::TStream* AStream);
	void __fastcall PrepareSaveToStream(System::Classes::TStream* AStream);
	void __fastcall SaveItselfToStream(System::Classes::TStream* AStream);
	void __fastcall SaveLinksToStream(System::Classes::TStream* AStream);
	void __fastcall SaveVersionToStream(System::Classes::TStream* AStream);
	void __fastcall UnprepareSaveToStream(System::Classes::TStream* AStream);
	__property TdxPSComponentPrinterExplorerChangeNotifier* ExplorerChangeNotifier = {read=FExplorerChangeNotifier};
	__property System::UnicodeString PreviewCaption = {read=GetPreviewCaption};
	__property TdxPreviewEvent OnAfterPreview = {read=FOnAfterPreview, write=FOnAfterPreview};
	__property TdxBeforeDesignReportEvent OnBeforeDesignReport = {read=FOnBeforeDesignReport, write=FOnBeforeDesignReport};
	__property TdxReportLinkBeforeExportToPDFEvent OnBeforeExportToPDF = {read=FOnBeforeExportToPDF, write=FOnBeforeExportToPDF};
	__property TdxPreviewEvent OnBeforePreview = {read=FOnBeforePreview, write=FOnBeforePreview};
	__property TdxReportLinkNotifyEvent OnChangeComponent = {read=FOnChangeComponent, write=FOnChangeComponent};
	__property System::Classes::TNotifyEvent OnChangeCurrentLink = {read=FOnChangeCurrentLink, write=FOnChangeCurrentLink};
	__property TdxCustomDrawPageHFEvent OnCustomDrawPageFooter = {read=FOnCustomDrawPageFooter, write=FOnCustomDrawPageFooter};
	__property TdxCustomDrawPageHFEvent OnCustomDrawPageHeader = {read=FOnCustomDrawPageHeader, write=FOnCustomDrawPageHeader};
	__property TdxCustomDrawReportTitleEvent OnCustomDrawReportFootnotes = {read=FOnCustomDrawReportFootnotes, write=FOnCustomDrawReportFootnotes};
	__property TdxCustomDrawReportTitleEvent OnCustomDrawReportTitle = {read=FOnCustomDrawReportTitle, write=FOnCustomDrawReportTitle};
	__property TdxDesignReportEvent OnDesignReport = {read=FOnDesignReport, write=FOnDesignReport};
	__property TdxMeasureReportTitleEvent OnMeasureReportFootnotes = {read=FOnMeasureReportFootnotes, write=FOnMeasureReportFootnotes};
	__property TdxMeasureReportTitleEvent OnMeasureReportTitle = {read=FOnMeasureReportTitle, write=FOnMeasureReportTitle};
	
public:
	__fastcall virtual TCustomdxComponentPrinter(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxComponentPrinter(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	TdxCompositionReportLink* __fastcall AddComposition(void);
	TBasedxReportLink* __fastcall AddEmptyLink(TdxReportLinkClass ALinkClass);
	TBasedxReportLink* __fastcall AddEmptyLinkEx(TdxReportLinkClass ALinkClass, System::Classes::TComponent* AOwner);
	TBasedxReportLink* __fastcall AddLink(System::Classes::TComponent* AComponent);
	TBasedxReportLink* __fastcall AddLinkEx(System::Classes::TComponent* AComponent, System::Classes::TComponent* AOwner);
	void __fastcall AssignReportLinks(TCustomdxComponentPrinter* Source);
	TBasedxReportLink* __fastcall CreateLinkFromFile(const System::UnicodeString AFileName);
	TBasedxReportLink* __fastcall CreateLinkFromStream(System::Classes::TStream* AStream);
	void __fastcall DeleteAllLinks(void);
	void __fastcall DeleteLink(int AIndex);
	void __fastcall DestroyReport(TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	TBasedxReportLink* __fastcall FindLinkByComponent(System::Classes::TComponent* Value, bool ACanCreate = false);
	void __fastcall GetLinks(System::Classes::TList* AList);
	int __fastcall IndexOfLink(TBasedxReportLink* AReportLink)/* overload */;
	int __fastcall IndexOfLink(const System::UnicodeString AName)/* overload */;
	int __fastcall IndexOfLinkByName(const System::UnicodeString AName);
	TBasedxReportLink* __fastcall LinkByName(const System::UnicodeString AName);
	void __fastcall RebuildReport(TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	__classmethod System::UnicodeString __fastcall GetNewLinkName(TBasedxReportLink* AReportLink);
	__classmethod bool __fastcall IsSupportedCompClass(System::TClass AComponentClass)/* overload */;
	__classmethod bool __fastcall IsSupportedCompClass(System::TObject* AComponent)/* overload */;
	TdxCompositionReportLink* __fastcall CurrentCompositionByLink(TBasedxReportLink* AReportLink);
	void __fastcall GetCompositionsByLink(TBasedxReportLink* AReportLink, System::Classes::TList* ACompositions);
	void __fastcall GetItems(TdxCompositionReportLink* AComposition, System::Classes::TStrings* AStrings, bool AExcludeAssigned);
	bool __fastcall IsLinkInComposition(TBasedxReportLink* AReportLink, TdxCompositionReportLink* AComposition);
	bool __fastcall IsLinkInCurrentComposition(TBasedxReportLink* AReportLink);
	void __fastcall Explore(void);
	void __fastcall ExportToPDF(TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0))/* overload */;
	void __fastcall ExportToPDF(const System::UnicodeString AFileName, bool ACanShowDialog = true, TdxPSPDFReportExportOptions* ASettings = (TdxPSPDFReportExportOptions*)(0x0), TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0))/* overload */;
	bool __fastcall DesignerExists(TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	bool __fastcall DesignerExistsByComponent(System::Classes::TComponent* AComponent);
	bool __fastcall DesignReport(TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall DrawPageFooter(TBasedxReportLink* AReportLink, int APageIndex, System::Types::TRect &ARect, Dxprnpg::TdxPageTitleParts ATitleParts, bool ADrawBackground);
	void __fastcall DrawPageHeader(TBasedxReportLink* AReportLink, int APageIndex, System::Types::TRect &ARect, Dxprnpg::TdxPageTitleParts ATitleParts, bool ADrawBackground);
	void __fastcall GetPageColRowCount(/* out */ int &ACol, /* out */ int &ARow, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	int __fastcall GetPageCount(TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	bool __fastcall PageSetup(TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	bool __fastcall PageSetupEx(int AActivePageIndex, bool AShowPreviewBtn, bool AShowPrintBtn, /* out */ bool &APreviewBtnClicked, /* out */ bool &APrintBtnClicked, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0))/* overload */;
	void __fastcall PaintPage(Vcl::Graphics::TCanvas* ACanvas, int APageIndex, const System::Types::TRect &APageBounds, const System::Types::TRect &AContentBounds, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall Preview(bool AModal = true, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	bool __fastcall PreviewExists(void);
	bool __fastcall Print(bool AShowDialog, Dxprndlg::PdxPrintDlgData APPrintDlgData, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall PrintEx(Dxprndlg::TdxPageNumbers APageNums, int ACopies, bool ACollate, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall PrintPages(const Dxpsglbl::TIntegers APageIndexes, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall PrintPagesEx(const Dxpsglbl::TIntegers APageIndexes, Dxprndlg::TdxPageNumbers APageNums, int ACopyCount, bool ACollate, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall LoadFromFile(const System::UnicodeString AName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::UnicodeString AName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property bool AbortBuilding = {read=FAbortBuilding, write=SetAbortBuilding, nodefault};
	__property bool AbortPrinting = {read=FAbortPrinting, write=SetAbortPrinting, nodefault};
	__property bool AutoUpdateDateTime = {read=FAutoUpdateDateTime, write=SetAutoUpdateDateTime, default=1};
	__property bool BeepAfterLongOperations = {read=FBeepAfterLongOperations, write=FBeepAfterLongOperations, default=1};
	__property TBasedxReportLink* CurrentLink = {read=FCurrentLink, write=SetCurrentLink};
	__property int CurrentLinkIndex = {read=GetCurrentLinkIndex, write=SetCurrentLinkIndex, nodefault};
	__property int DateFormat = {read=FDateFormat, write=SetDateFormat, default=0};
	__property TCustomdxPSExplorer* Explorer = {read=FExplorer, write=SetExplorer};
	__property TBasedxReportLink* ExplorerRealStubLink = {read=GetExplorerRealStubLink};
	__property TBasedxReportLink* ExplorerStubLink = {read=FExplorerStubLink, write=SetExplorerStubLink};
	__property bool IsExplorerMode = {read=GetIsExplorerMode, nodefault};
	__property int LinkCount = {read=GetLinkCount, nodefault};
	__property int LongOperationTime = {read=FLongOperationTime, write=SetLongOperationTime, default=5000};
	__property TdxCPOptions Options = {read=FOptions, write=FOptions, default=31};
	__property Dxpsglbl::TdxPageNumberFormat PageNumberFormat = {read=FPageNumberFormat, write=SetPageNumberFormat, default=0};
	__property TdxPreviewOptions* PreviewOptions = {read=FPreviewOptions, write=SetPreviewOptions};
	__property TdxPSCustomPreviewWindow* PreviewWindow = {read=FPreviewWindow};
	__property System::Classes::TStrings* PrintFileList = {read=FPrintFileList, write=SetPrintFileList};
	__property System::UnicodeString PrintTitle = {read=FPrintTitle, write=FPrintTitle};
	__property TBasedxReportLink* ReportLink[int Index] = {read=GetReportLink, write=SetReportLink/*, default*/};
	__property TdxCPStates State = {read=FState, nodefault};
	__property int TimeFormat = {read=FTimeFormat, write=SetTimeFormat, default=0};
	__property int Version = {read=FVersion, write=FVersion, nodefault};
	__property TAbstractdxPreviewWindowDesigner* PreviewWindowDesigner = {read=FPreviewWindowDesigner};
	__property TAbstractdxReportLinkDesigner* ReportLinkDesigner = {read=FReportLinkDesigner};
	__property TdxReportLinkNotifyEvent OnAddReportLink = {read=FOnAddReportLink, write=FOnAddReportLink};
	__property TdxCustomDrawPageEvent OnCustomDrawPage = {read=FOnCustomDrawPage, write=FOnCustomDrawPage};
	__property TdxReportLinkNotifyEvent OnDeleteReportLink = {read=FOnDeleteReportLink, write=FOnDeleteReportLink};
	__property TdxReportLinkNotifyEvent OnEndGenerateReport = {read=FOnEndGenerateReport, write=FOnEndGenerateReport};
	__property TdxReportLinkNotifyEvent OnEndPrint = {read=FOnEndPrint, write=FOnEndPrint};
	__property TdxPrintDlgDataEvent OnFinalizePrintDlgData = {read=FOnFinalizePrintDlgData, write=FOnFinalizePrintDlgData};
	__property TdxGenerateReportProgressEvent OnGenerateReportProgress = {read=FOnGenerateReportProgress, write=FOnGenerateReportProgress};
	__property TdxGetPrintTitleEvent OnGetPrintTitle = {read=FOnGetPrintTitle, write=FOnGetPrintTitle};
	__property TdxPrintDlgDataEvent OnInitializePrintDlgData = {read=FOnInitializePrintDlgData, write=FOnInitializePrintDlgData};
	__property TdxNewPageEvent OnNewPage = {read=FOnNewPage, write=FOnNewPage};
	__property TdxPageSetupEvent OnPageSetup = {read=FOnPageSetup, write=FOnPageSetup};
	__property TdxPrintDeviceProblemEvent OnPrintDeviceBusy = {read=FOnPrintDeviceBusy, write=FOnPrintDeviceBusy};
	__property TdxPrintDeviceProblemEvent OnPrintDeviceError = {read=FOnPrintDeviceError, write=FOnPrintDeviceError};
	__property TdxReportLinkNotifyEvent OnStartGenerateReport = {read=FOnStartGenerateReport, write=FOnStartGenerateReport};
	__property TdxStartPrintEvent OnStartPrint = {read=FOnStartPrint, write=FOnStartPrint};
};


typedef void __fastcall (__closure *TdxEnumPagesAsImagesProc)(TCustomdxComponentPrinter* AComponentPrinter, TBasedxReportLink* AReportLink, int AIndex, int APageIndex, Vcl::Graphics::TGraphic* const AGraphic, void * AData, bool &AContinue);

typedef void __fastcall (__closure *TdxExportProgressEvent)(TCustomdxComponentPrinter* Sender, TBasedxReportLink* AReportLink, int APageCount, int AIndex, int APageIndex, void * AData);

typedef void __fastcall (__closure *TdxExportPrepareGraphicEvent)(TCustomdxComponentPrinter* Sender, TBasedxReportLink* AReportLink, Vcl::Graphics::TGraphic* const AGraphic, void * AData);

typedef void __fastcall (__closure *TdxExportGetPageFileNameEvent)(TCustomdxComponentPrinter* Sender, int AIndex, int APageIndex, System::UnicodeString &AFileName);

typedef void __fastcall (__closure *TdxOnFilterComponentEvent)(System::TObject* Sender, System::Classes::TComponent* &AComponent, System::UnicodeString &ACaption, System::UnicodeString &ADescription, bool &Accept);

typedef void __fastcall (__closure *TdxOnGetSupportedComponentsEvent)(System::TObject* Sender, System::Classes::TStrings* AComponents);

enum TdxCPCustomizeDlgOption : unsigned char { cdoShowDescription };

typedef System::Set<TdxCPCustomizeDlgOption, TdxCPCustomizeDlgOption::cdoShowDescription, TdxCPCustomizeDlgOption::cdoShowDescription>  TdxCPCustomizeDlgOptions;

class DELPHICLASS TdxComponentPrinter;
class PASCALIMPLEMENTATION TdxComponentPrinter : public TCustomdxComponentPrinter
{
	typedef TCustomdxComponentPrinter inherited;
	
private:
	TdxCPCustomizeDlgOptions FCustomizeDlgOptions;
	bool FOverWriteAll;
	bool FOverWriteExistingFiles;
	bool FOverWriteFile;
	TdxExportGetPageFileNameEvent FOnExportGetPageFileName;
	TdxExportPrepareGraphicEvent FOnExportPrepareGraphic;
	TdxExportProgressEvent FOnExportProgress;
	TdxOnFilterComponentEvent FOnFilterComponent;
	TdxOnGetSupportedComponentsEvent FOnGetSupportedComponents;
	void __fastcall WritePageAsImageToDisk(TCustomdxComponentPrinter* AComponentPrinter, TBasedxReportLink* AReportLink, int AIndex, int APageIndex, Vcl::Graphics::TGraphic* const AGraphic, void * AData, bool &AContinue);
	
protected:
	DYNAMIC bool __fastcall DoFilterComponent(System::Classes::TComponent* AComponent, System::UnicodeString &ACaption, System::UnicodeString &ADescription);
	DYNAMIC bool __fastcall GetSupportedComponents(System::Classes::TStrings* AComponents);
	DYNAMIC void __fastcall GetDefaultExportPageFileName(int AIndex, int APageIndex, System::UnicodeString &AFileName);
	DYNAMIC void __fastcall GetExportPageFileName(int AIndex, int APageIndex, System::UnicodeString &AFileName);
	void __fastcall InternalLoadDefaultSettigns(void);
	void __fastcall InternalSaveDefaultSettings(void);
	virtual void __fastcall Loaded(void);
	
public:
	__fastcall virtual TdxComponentPrinter(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxComponentPrinter(void);
	void __fastcall ShowCustomizeDlg(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection)/* overload */;
	void __fastcall LoadFromIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall LoadFromRegistry(const System::UnicodeString APath);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection)/* overload */;
	void __fastcall SaveToIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall SaveToRegistry(const System::UnicodeString APath);
	void __fastcall EnumPagesAsImages(int const *APageIndexes, const int APageIndexes_Size, Vcl::Graphics::TGraphicClass AGraphicClass, bool ADrawBackground, TdxEnumPagesAsImagesProc ACallBackProc, void * ACallBackData, void * AProgressData, void * APrepareData, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	void __fastcall SavePagesAsImagesToDisk(int const *APageIndexes, const int APageIndexes_Size, Vcl::Graphics::TGraphicClass AGraphicClass, bool ADrawBackground, const System::UnicodeString AFileMask, void * AProgressData, void * APrepareData, TBasedxReportLink* AReportLink = (TBasedxReportLink*)(0x0));
	
__published:
	__property AutoUpdateDateTime = {default=1};
	__property BeepAfterLongOperations = {default=1};
	__property CurrentLink;
	__property TdxCPCustomizeDlgOptions CustomizeDlgOptions = {read=FCustomizeDlgOptions, write=FCustomizeDlgOptions, default=1};
	__property DateFormat = {default=0};
	__property Explorer;
	__property ExplorerStubLink;
	__property LongOperationTime = {default=5000};
	__property Options = {default=31};
	__property bool OverWriteExistingFiles = {read=FOverWriteExistingFiles, write=FOverWriteExistingFiles, default=0};
	__property PageNumberFormat = {default=0};
	__property PreviewOptions;
	__property PrintTitle = {default=0};
	__property TimeFormat = {default=0};
	__property Version;
	__property OnAddReportLink;
	__property OnAfterPreview;
	__property OnBeforeDesignReport;
	__property OnBeforeExportToPDF;
	__property OnBeforePreview;
	__property OnChangeComponent;
	__property OnChangeCurrentLink;
	__property OnCustomDrawPage;
	__property OnCustomDrawPageFooter;
	__property OnCustomDrawPageHeader;
	__property OnCustomDrawReportTitle;
	__property OnDeleteReportLink;
	__property OnDesignReport;
	__property OnEndGenerateReport;
	__property OnEndPrint;
	__property TdxExportGetPageFileNameEvent OnExportGetPageFileName = {read=FOnExportGetPageFileName, write=FOnExportGetPageFileName};
	__property TdxExportPrepareGraphicEvent OnExportPrepareGraphic = {read=FOnExportPrepareGraphic, write=FOnExportPrepareGraphic};
	__property TdxExportProgressEvent OnExportProgress = {read=FOnExportProgress, write=FOnExportProgress};
	__property TdxOnFilterComponentEvent OnFilterComponent = {read=FOnFilterComponent, write=FOnFilterComponent};
	__property OnFinalizePrintDlgData;
	__property OnGetPrintTitle;
	__property OnGenerateReportProgress;
	__property TdxOnGetSupportedComponentsEvent OnGetSupportedComponents = {read=FOnGetSupportedComponents, write=FOnGetSupportedComponents};
	__property OnInitializePrintDlgData;
	__property OnMeasureReportTitle;
	__property OnNewPage;
	__property OnPageSetup;
	__property OnPrintDeviceBusy;
	__property OnPrintDeviceError;
	__property OnStartGenerateReport;
	__property OnStartPrint;
};


class PASCALIMPLEMENTATION TAbstractdxPreviewWindowDesigner : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TCustomdxComponentPrinter* FComponentPrinter;
	
protected:
	virtual void __fastcall Activate(void) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	
public:
	__fastcall TAbstractdxPreviewWindowDesigner(TCustomdxComponentPrinter* AComponentPrinter);
	__fastcall virtual ~TAbstractdxPreviewWindowDesigner(void);
	__property TCustomdxComponentPrinter* ComponentPrinter = {read=FComponentPrinter};
};


class PASCALIMPLEMENTATION TAbstractdxReportLinkDesigner : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TCustomdxComponentPrinter* FComponentPrinter;
	
protected:
	virtual void __fastcall Modified(void) = 0 ;
	virtual void __fastcall Update(TBasedxReportLink* Item) = 0 ;
	
public:
	__fastcall TAbstractdxReportLinkDesigner(TCustomdxComponentPrinter* AComponentPrinter);
	__fastcall virtual ~TAbstractdxReportLinkDesigner(void);
	virtual void __fastcall BeginUpdate(void) = 0 ;
	virtual void __fastcall CancelUpdate(void) = 0 ;
	virtual void __fastcall EndUpdate(void) = 0 ;
	__property TCustomdxComponentPrinter* ComponentPrinter = {read=FComponentPrinter};
};


class DELPHICLASS TdxPSPreviewDialogStyleInfo;
class PASCALIMPLEMENTATION TdxPSPreviewDialogStyleInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	__classmethod virtual TdxPSCustomPreviewWindow* __fastcall CreatePreviewWindow();
	__classmethod virtual System::UnicodeString __fastcall GetName();
	__classmethod virtual System::UnicodeString __fastcall GetUnitName();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSPreviewDialogStyleInfo(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSPreviewDialogStyleInfo(void) : System::Classes::TPersistent() { }
	
};


typedef System::TMetaClass* TdxPSPreviewDialogStyleInfoClass;

class DELPHICLASS TdxPSPreviewDialogManager;
class PASCALIMPLEMENTATION TdxPSPreviewDialogManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxpsglbl::TdxPSPreviewDialogStyle FCurrentPreviewDialogStyle;
	System::Classes::TList* FList;
	int __fastcall GetCount(void);
	Dxpsglbl::TdxPSPreviewDialogStyle __fastcall GetCurrentPreviewDialogStyle(void);
	TdxPSPreviewDialogStyleInfoClass __fastcall GetCurrentPreviewDialogStyleInfo(void);
	TdxPSPreviewDialogStyleInfoClass __fastcall GetDefaultPreviewDialogStyleInfo(void);
	TdxPSPreviewDialogStyleInfoClass __fastcall GetItem(int Index);
	System::UnicodeString __fastcall GetName(int Index);
	void __fastcall SetCurrentPreviewDialogStyle(const Dxpsglbl::TdxPSPreviewDialogStyle AValue);
	
public:
	__fastcall virtual TdxPSPreviewDialogManager(void);
	__fastcall virtual ~TdxPSPreviewDialogManager(void);
	TdxPSCustomPreviewWindow* __fastcall CreatePreviewWindow(void);
	bool __fastcall FindPreviewDialogStyleInfoByName(const System::UnicodeString AName, /* out */ TdxPSPreviewDialogStyleInfoClass &AInfoClass);
	void __fastcall PopulatePreviewDialogList(System::Classes::TStrings* AStrings);
	void __fastcall RegisterPreviewDialog(TdxPSPreviewDialogStyleInfoClass APreviewDialogStyleInfo);
	void __fastcall UnregisterPreviewDialog(TdxPSPreviewDialogStyleInfoClass APreviewDialogStyleInfo);
	__property int Count = {read=GetCount, nodefault};
	__property Dxpsglbl::TdxPSPreviewDialogStyle CurrentPreviewDialogStyle = {read=GetCurrentPreviewDialogStyle, write=SetCurrentPreviewDialogStyle};
	__property TdxPSPreviewDialogStyleInfoClass CurrentPreviewDialogStyleInfo = {read=GetCurrentPreviewDialogStyleInfo};
	__property TdxPSPreviewDialogStyleInfoClass DefaultPreviewDialogStyleInfo = {read=GetDefaultPreviewDialogStyleInfo};
	__property TdxPSPreviewDialogStyleInfoClass Items[int Index] = {read=GetItem};
	__property System::UnicodeString Names[int Index] = {read=GetName};
};


//-- var, const, procedure ---------------------------------------------------
#define dxDefaultPreviewEnableOptions (System::Set<TdxPreviewEnableOption, TdxPreviewEnableOption::peoCanChangeMargins, TdxPreviewEnableOption::peoReportDesign> () << TdxPreviewEnableOption::peoCanChangeMargins << TdxPreviewEnableOption::peoPageBackground << TdxPreviewEnableOption::peoPageSetup << TdxPreviewEnableOption::peoPreferences << TdxPreviewEnableOption::peoPrint << TdxPreviewEnableOption::peoReportDesign )
#define dxDefaultPreviewVisibleOptions (System::Set<TdxPreviewVisibleOption, TdxPreviewVisibleOption::pvoHelp, TdxPreviewVisibleOption::pvoPageMargins> () << TdxPreviewVisibleOption::pvoPageBackground << TdxPreviewVisibleOption::pvoPageSetup << TdxPreviewVisibleOption::pvoPreferences << TdxPreviewVisibleOption::pvoPrint << TdxPreviewVisibleOption::pvoReportDesign << TdxPreviewVisibleOption::pvoPrintStyles << TdxPreviewVisibleOption::pvoReportFileOperations << TdxPreviewVisibleOption::pvoPageMargins )
static const int PSTO_DEFAULT_FORMAT = int(0x11000);
static const TdxCellEdgeMode cemSingle = (TdxCellEdgeMode)(0);
static const TdxCellEdgeStyle cesNone = (TdxCellEdgeStyle)(0);
#define csAll (System::Set<TdxCellSide, TdxCellSide::csLeft, TdxCellSide::csBottom> () << TdxCellSide::csLeft << TdxCellSide::csTop << TdxCellSide::csRight << TdxCellSide::csBottom )
#define csTopLeft (System::Set<TdxCellSide, TdxCellSide::csLeft, TdxCellSide::csBottom> () << TdxCellSide::csLeft << TdxCellSide::csTop )
#define csBottomRight (System::Set<TdxCellSide, TdxCellSide::csLeft, TdxCellSide::csBottom> () << TdxCellSide::csRight << TdxCellSide::csBottom )
#define csLeftRight (System::Set<TdxCellSide, TdxCellSide::csLeft, TdxCellSide::csBottom> () << TdxCellSide::csLeft << TdxCellSide::csRight )
#define csTopBottom (System::Set<TdxCellSide, TdxCellSide::csLeft, TdxCellSide::csBottom> () << TdxCellSide::csTop << TdxCellSide::csBottom )
extern PACKAGE TdxPSTreeLineParts tlpAll;
extern PACKAGE System::StaticArray<System::Classes::TAlignment, 5> dxAlignment;
extern PACKAGE System::StaticArray<unsigned, 2> dxCalcFormat;
extern PACKAGE System::StaticArray<unsigned, 5> dxDrawTextTextAlignX;
extern PACKAGE System::StaticArray<unsigned, 4> dxDrawTextTextAlignY;
extern PACKAGE System::StaticArray<TdxImageLayout, 3> dxImageLayout;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignY, 2> dxMultilineTextAlignY;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignX, 3> dxTextAlignX;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignY, 3> dxTextAlignY;
extern PACKAGE System::StaticArray<System::StaticArray<TdxPSCellBorderClass, 2>, 2> dxCellBorderClassMap;
#define dxDefaultCPOptions (System::Set<TdxCPOption, TdxCPOption::cpoAutoRebuildBeforePreview, TdxCPOption::cpoDropStorageModeAfterPreview> () << TdxCPOption::cpoAutoRebuildBeforePreview << TdxCPOption::cpoAutoRebuildBeforePrint << TdxCPOption::cpoGenerateReportProgressEvent << TdxCPOption::cpoShowHourGlass << TdxCPOption::cpoDropStorageModeAfterPreview )
extern PACKAGE System::StaticArray<System::StaticArray<System::StaticArray<TdxGraphicDrawMode, 2>, 2>, 2> dxGraphicDrawModeMap;
extern PACKAGE System::StaticArray<int, 2> dxThumbnailsZoomFactors;
static const int dxDefaultBkColor = int(16777215);
static const bool dxDefaultBreakByChars = true;
#define dxDefaultCellSides (System::Set<TdxCellSide, TdxCellSide::csLeft, TdxCellSide::csBottom> () << TdxCellSide::csLeft << TdxCellSide::csTop << TdxCellSide::csRight << TdxCellSide::csBottom )
static const bool dxDefaultCheckFlatBorder = true;
static const TdxCellCheckPos dxDefaultCheckPos = (TdxCellCheckPos)(1);
static const int dxDefaultColor = int(16777215);
static const int dxDefaultContentColor = int(16777215);
static const System::Int8 dxDefaultCrossSignCrossSize = System::Int8(0x9);
static const TdxCellEdgeMode dxDefaultEdgeMode = (TdxCellEdgeMode)(0);
static const bool dxDefaultEdge3DSoft = true;
static const TdxCellEdgeStyle dxDefaultEdge3DStyle = (TdxCellEdgeStyle)(0);
static const bool dxDefaultEndEllipsis = false;
static const int dxDefaultExpandButtonBorderColor = int(0);
static const int dxDefaultFixedColor = int(-16777201);
static const bool dxDefaultFixedTransparent = false;
extern PACKAGE System::StaticArray<System::WideChar, 32> dxDefaultFont;
static const int dxDefaultGridLineColor = int(0);
static const int dxDefaultGroupBorderColor = int(-16777201);
static const int dxDefaultGroupCaptionColor = int(-16777201);
static const int dxDefaultGroupCaptionSeparatorColor = int(-16777201);
static const int dxDefaultGroupColor = int(-16777201);
static const bool dxDefaultHidePrefix = false;
static const bool dxDefaultMultiline = false;
static const int dxDefaultShadowColor = int(0);
static const System::Int8 dxDefaultShadowDepth = System::Int8(0x3);
static const TdxCellSortOrder dxDefaultSortOrder = (TdxCellSortOrder)(0);
static const bool dxDefaultPreventLeftTextExceed = true;
static const bool dxDefaultPreventTopTextExceed = true;
static const System::Int8 dxDefaultReportGroupCaptionIndent = System::Int8(0x5);
extern PACKAGE TdxPSReportGroupLookAndFeelClass dxDefaultReportGroupLookAndFeel;
static const Cxdrawtextutils::TcxTextAlignX dxDefaultTextAlignX = (Cxdrawtextutils::TcxTextAlignX)(0);
static const Cxdrawtextutils::TcxTextAlignY dxDefaultTextAlignY = (Cxdrawtextutils::TcxTextAlignY)(1);
static const bool dxDefaultTransparent = true;
static const int dxDefaultTreeLineColor = int(8421504);
static const System::Int8 dxPSDefaultFontCharSet = System::Int8(0x1);
static const int dxPSDefaultFontColor = int(0);
#define dxPSDefaultFontName L"Times New Roman"
static const System::Int8 dxPSDefaultFontSize = System::Int8(0x8);
#define dxPSDefaultFontStyle EMPTYSET
static const int dxPSDefaultPreviewThumbnailsFontColor = int(16711680);
#define dxPSDefaultPreviewThumbnailsFontName L"Tahoma"
static const System::Int8 dxPSDefaultPreviewThumbnailsFontSize = System::Int8(0x30);
#define dxPSDefaultPreviewThumbnailsFontStyle EMPTYSET
static const int dxPSDefaultReportTitleFontColor = int(0);
#define dxPSDefaultReportTitleFontName L"Times New Roman"
static const System::Int8 dxPSDefaultReportTitleFontSize = System::Int8(0xe);
#define dxPSDefaultReportTitleFontStyle (System::Set<System::Uitypes::TFontStyle, System::Uitypes::TFontStyle::fsBold, System::Uitypes::TFontStyle::fsStrikeOut> () << System::Uitypes::TFontStyle::fsBold )
static const System::Int8 dxRadioGroupInterColumnsMinSpace = System::Int8(0x1);
static const System::Int8 dxRadioGroupInterRowsMinSpace = System::Int8(0x1);
static const System::Int8 dxRadioGroupBoundsIndent = System::Int8(0x2);
#define dxPSReportFileLongExtension L"ExpressPrinting System-Report"
#define dxPSReportFileShortExtension L"rps"
static const System::Int8 dxSortMarkRgnSize = System::Int8(0x10);
static const System::Int8 dxSortMarkWidth = System::Int8(0x8);
static const System::Int8 dxSortMarkHeight = System::Int8(0x7);
static const System::WideChar sdxDocumentCaptionSeparator = (System::WideChar)(0x2d);
extern PACKAGE bool FDontPrintTransparentImages;
extern PACKAGE bool FEmulatePrintCopies;
extern PACKAGE bool FSmoothlyStretchImages;
extern PACKAGE bool FUnitFinalized;
extern PACKAGE int FUnitsPerInch;
extern PACKAGE int iiExplorerFolderCollapsed;
extern PACKAGE int iiExplorerFolderExpanded;
extern PACKAGE int iiExplorerItem;
extern PACKAGE int iiExplorerItemHasInvalidData;
extern PACKAGE System::StaticArray<int, 7> iiDriveTypes;
extern PACKAGE int dxTextSpace;
extern PACKAGE System::Classes::TList* dxComponentPrintersList;
extern PACKAGE int dxPSIndentBetweenComposedPages;
extern PACKAGE bool FUseIsotropicMode;
extern PACKAGE System::Types::TRect __fastcall dxPSCalculateImageBounds(const System::Types::TRect &R, int AWidth, int AHeight, TdxGraphicDrawMode ADrawMode);
extern PACKAGE Cxgraphics::TcxBorders __fastcall dxCellSidesToBorders(TdxCellSides ASides);
extern PACKAGE void __fastcall dxPSScaleFont(Vcl::Graphics::TFont* AFont, int AFontSize, int AUnitsPerInch);
extern PACKAGE TdxPSPreviewDialogManager* __fastcall dxPSPreviewDialogManager(void);
extern PACKAGE int __fastcall OnePixel(void);
extern PACKAGE int __fastcall PixelsNumerator(void);
extern PACKAGE int __fastcall PixelsDenominator(void);
extern PACKAGE void __fastcall FixupRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R);
extern PACKAGE void __fastcall Get3DBorderBrushes(TdxCellEdgeStyle AEdgeStyle, bool ASoft, HBRUSH &AOuterTLBrush, HBRUSH &AOuterBRBrush, HBRUSH &AInnerTLBrush, HBRUSH &AInnerBRBrush);
extern PACKAGE void __fastcall Get3DBorderColors(TdxCellEdgeStyle AEdgeStyle, bool ASoft, System::Uitypes::TColor &AOuterTLColor, System::Uitypes::TColor &AOuterBRColor, System::Uitypes::TColor &AInnerTLColor, System::Uitypes::TColor &AInnerBRColor);
extern PACKAGE Vcl::Imglist::TCustomImageList* __fastcall dxPSExplorerImages(void);
extern PACKAGE void __fastcall dxPSStartWait(void);
extern PACKAGE void __fastcall dxPSStopWait(void);
extern PACKAGE void __fastcall dxPSRegisterReportLink(TdxReportLinkClass ALinkClass, System::Classes::TComponentClass AComponentClass, TdxReportLinkDesignWindowClass ADesignerClass);
extern PACKAGE void __fastcall dxPSUnregisterReportLink(TdxReportLinkClass ALinkClass, System::Classes::TComponentClass AComponentClass, TdxReportLinkDesignWindowClass ADesignerClass);
extern PACKAGE void __fastcall dxPSUnregisterReportLinks(TdxReportLinkClass const *ALinkClasses, const int ALinkClasses_Size);
extern PACKAGE TdxReportLinkDesignWindowClass __fastcall dxPSDesignerClassByCompClass(System::TClass AComponentClass)/* overload */;
extern PACKAGE TdxReportLinkDesignWindowClass __fastcall dxPSDesignerClassByCompClass(System::TObject* AComponent)/* overload */;
extern PACKAGE TdxReportLinkClass __fastcall dxPSLinkClassByCompClass(System::TClass AComponentClass)/* overload */;
extern PACKAGE TdxReportLinkClass __fastcall dxPSLinkClassByCompClass(System::TObject* AComponent)/* overload */;
extern PACKAGE TdxReportLinkDesignWindowClass __fastcall dxPSDesignerClassByLinkClass(System::TClass ALinkClass)/* overload */;
extern PACKAGE TdxReportLinkDesignWindowClass __fastcall dxPSDesignerClassByLinkClass(System::TObject* ALink)/* overload */;
extern PACKAGE void __fastcall dxPSGetActiveReportLinksList(Dxbase::TdxClassList* AClassList);
extern PACKAGE void __fastcall dxPSGetReportLinksList(Dxbase::TdxClassList* AClassList);
extern PACKAGE void __fastcall dxPSGetLinkSupportedComponentsList(Dxbase::TdxClassList* AClassList, System::TClass ALinkClass)/* overload */;
extern PACKAGE void __fastcall dxPSGetLinkSupportedComponentsList(Dxbase::TdxClassList* AClassList, System::TObject* ALink)/* overload */;
extern PACKAGE void __fastcall dxPSGetSupportedComponentsList(Dxbase::TdxClassList* AClassList);
extern PACKAGE bool __fastcall dxPSIsSupportedCompClass(System::TClass AComponentClass)/* overload */;
extern PACKAGE bool __fastcall dxPSIsSupportedCompClass(System::TObject* AComponent)/* overload */;
extern PACKAGE bool __fastcall dxPrintComponent(System::Classes::TComponent* AComponent, bool APrintPreview = true, bool APrintDialog = false, const System::UnicodeString AReportTitle = System::UnicodeString(), const System::UnicodeString APrintTitle = System::UnicodeString());
extern PACKAGE void __fastcall dxPSEnumReportPages(TdxComponentPrinter* AComponentPrinter, TBasedxReportLink* AReportLink, int const *APageIndexes, const int APageIndexes_Size, Vcl::Graphics::TGraphicClass AGraphicClass, bool AnExportBackground, TdxEnumPagesAsImagesProc ACallBackProc, void * ACallBackData, TdxExportProgressEvent AProgressProc, void * AProgressData, TdxExportPrepareGraphicEvent APrepareGraphicProc, void * APrepareData);
}	/* namespace Dxpscore */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCORE)
using namespace Dxpscore;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscoreHPP
