// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPrnDev.pas' rev: 24.00 (Win64)

#ifndef DxprndevHPP
#define DxprndevHPP

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
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <winspool.h>

namespace Dxprndev
{
//-- type declarations -------------------------------------------------------
typedef _PRINTER_INFO_8A TPrinterInfo8A;

typedef _PRINTER_INFO_8W TPrinterInfo8W;

typedef _PRINTER_INFO_8A TPrinterInfo8;

typedef _PRINTER_INFO_8A *PPrinterInfo8A;

typedef _PRINTER_INFO_8W *PPrinterInfo8W;

typedef PPrinterInfo8A PPrinterInfo8;

typedef _PRINTER_INFO_9A _PRINTER_INFO_9;

typedef _PRINTER_INFO_9A TPrinterInfo9A;

typedef _PRINTER_INFO_9W TPrinterInfo9W;

typedef _PRINTER_INFO_9A TPrinterInfo9;

typedef _PRINTER_INFO_9A *PPrinterInfo9A;

typedef _PRINTER_INFO_9W *PPrinterInfo9W;

typedef PPrinterInfo9W PPrinterInfo9;

enum TdxPrinterState : unsigned char { psNoHandle, psHandleIC, psHandleDC };

enum TdxDuplexMode : unsigned char { dmSimplex, dmHorizontal, dmVertical };

enum TdxPrinterOrientation : unsigned char { poPortrait, poLandscape };

enum TdxPrinterCapability : unsigned char { pcCopies, pcOrientation, pcCollation };

typedef System::Set<TdxPrinterCapability, TdxPrinterCapability::pcCopies, TdxPrinterCapability::pcCollation>  TdxPrinterCapabilities;

class DELPHICLASS EdxPrintDevice;
class PASCALIMPLEMENTATION EdxPrintDevice : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxPrintDevice(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxPrintDevice(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxPrintDevice(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxPrintDevice(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPrintDevice(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPrintDevice(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxPrintDevice(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxPrintDevice(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPrintDevice(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPrintDevice(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPrintDevice(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPrintDevice(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxPrintDevice(void) { }
	
};


class DELPHICLASS TdxPrintDeviceInfo;
class PASCALIMPLEMENTATION TdxPrintDeviceInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::WideChar *FDevice;
	System::WideChar *FDriver;
	System::WideChar *FPort;
	bool FIsDefault;
	bool FIsNetwork;
	
public:
	__fastcall TdxPrintDeviceInfo(System::WideChar * ADriver, System::WideChar * ADevice, System::WideChar * APort, bool AnIsDefault, bool AnIsNetwork);
	__fastcall virtual ~TdxPrintDeviceInfo(void);
	bool __fastcall IsEqual(System::WideChar * ADriver, System::WideChar * ADevice, System::WideChar * APort);
	__property System::WideChar * Device = {read=FDevice};
	__property System::WideChar * Driver = {read=FDriver};
	__property System::WideChar * Port = {read=FPort};
	__property bool IsDefault = {read=FIsDefault, write=FIsDefault, nodefault};
	__property bool IsNetwork = {read=FIsNetwork, nodefault};
};


class DELPHICLASS TdxPrintDevice;
class PASCALIMPLEMENTATION TdxPrintDevice : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FAborted;
	bool FAutoRefresh;
	System::Classes::TStrings* FBins;
	Vcl::Graphics::TCanvas* FCanvas;
	TdxPrinterCapabilities FCapabilities;
	System::WideChar *FCurrentDevice;
	System::WideChar *FCurrentDriver;
	System::WideChar *FCurrentPort;
	HDC FDC;
	NativeUInt FDeviceHandle;
	_devicemodeW *FDeviceMode;
	bool FDeviceModeChanged;
	NativeUInt FHDeviceMode;
	System::UnicodeString FFileName;
	System::Classes::TStrings* FFonts;
	bool FIsDeviceModePersistent;
	int FMaxCopies;
	int FMaxExtents;
	int FMinExtents;
	int FPageNumber;
	System::Classes::TStrings* FPapers;
	System::Classes::TStrings* FPrinters;
	int FPrinterIndex;
	bool FPrinting;
	TdxPrinterState FState;
	System::UnicodeString FTitle;
	HWND FWindowHandle;
	System::Classes::TNotifyEvent FOnNewPage;
	System::Classes::TNotifyEvent FOnPrinterChange;
	System::Classes::TNotifyEvent FOnRefresh;
	int __fastcall GetBinIndex(void);
	System::Classes::TStrings* __fastcall GetBins(void);
	Vcl::Graphics::TCanvas* __fastcall GetCanvas(void);
	bool __fastcall GetCollate(void);
	bool __fastcall GetColorMode(void);
	System::WideChar * __fastcall GetCurrentDevice(void);
	System::WideChar * __fastcall GetCurrentDriver(void);
	System::WideChar * __fastcall GetCurrentPort(void);
	int __fastcall GetDefaultDMPaper(void);
	Winapi::Windows::PDeviceModeW __fastcall GetDeviceMode(void);
	TdxDuplexMode __fastcall GetDuplex(void);
	System::Classes::TStrings* __fastcall GetFonts(void);
	HDC __fastcall GetHandle(void);
	NativeUInt __fastcall GetHDeviceMode(void);
	bool __fastcall GetIsDefault(void);
	bool __fastcall GetIsInitialized(void);
	bool __fastcall GetIsNetwork(void);
	int __fastcall GetMaxExtents(int Index);
	int __fastcall GetMinExtents(int Index);
	int __fastcall GetNumCopies(void);
	TdxPrinterOrientation __fastcall GetOrientation(void);
	int __fastcall GetPageHeight(void);
	int __fastcall GetPageHeightLoMetric(void);
	int __fastcall GetPageWidth(void);
	int __fastcall GetPageWidthLoMetric(void);
	int __fastcall GetPaperCount(void);
	int __fastcall GetPaperIndex(void);
	System::Classes::TStrings* __fastcall GetPapers(void);
	int __fastcall GetPhysOffset(int Index);
	int __fastcall GetPrinterCount(void);
	int __fastcall GetPrinterIndex(void);
	TdxPrintDeviceInfo* __fastcall GetPrinterInfo(int Index);
	System::Classes::TStrings* __fastcall GetPrinters(void);
	void __fastcall SetBinIndex(int Value);
	void __fastcall SetCollate(bool Value);
	void __fastcall SetColorMode(bool Value);
	void __fastcall SetDuplex(TdxDuplexMode Value);
	void __fastcall SetIsDefault(bool Value);
	void __fastcall SetNumCopies(int Value);
	void __fastcall SetOrientation(TdxPrinterOrientation Value);
	void __fastcall SetPaperIndex(int Value);
	void __fastcall SetPrinterCapabilities(int Value);
	void __fastcall SetPrinterIndex(int Value);
	void __fastcall CheckPrinting(bool Value);
	void __fastcall ClosePrintDevice(void);
	void __fastcall DeselectHandles(void);
	void __fastcall FixMinMaxExtents(void);
	void __fastcall FreeAndNilBins(void);
	void __fastcall FreeAndNilCanvas(void);
	void __fastcall FreeAndNilFonts(void);
	void __fastcall FreeAndNilPapers(void);
	void __fastcall FreeAndNilPrinters(void);
	void __fastcall InternalSelectPaperBySize(int &AWidth, int &AHeight);
	void __fastcall OpenPrintDevice(int AIndex);
	void __fastcall SetState(TdxPrinterState Value);
	void __fastcall SetToDefaultPrintDevice(void);
	void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall DoNewPage(void);
	DYNAMIC void __fastcall DoPrinterChanged(void);
	DYNAMIC void __fastcall DoRefresh(void);
	
public:
	__fastcall TdxPrintDevice(void);
	__fastcall virtual ~TdxPrintDevice(void);
	void __fastcall Abort(void);
	int __fastcall BeginDoc(void);
	void __fastcall EndDoc(void);
	void __fastcall NewPage(void);
	int __fastcall FindPrintDevice(System::WideChar * ADevice, System::WideChar * APort);
	bool __fastcall IsDeviceModeChanged(void);
	void __fastcall Refresh(void);
	void __fastcall ResetDC(bool IsForced);
	void __fastcall ResetPrintDevice(void);
	int __fastcall FindBin(int ABin)/* overload */;
	int __fastcall FindBin(const System::UnicodeString AName)/* overload */;
	bool __fastcall IsAutoSelectBin(int AIndex);
	bool __fastcall IsUserPaperSource(int AIndex);
	bool __fastcall SelectBin(int Value)/* overload */;
	bool __fastcall SelectBin(const System::UnicodeString AName)/* overload */;
	int __fastcall FindPaper(int ADMPaper)/* overload */;
	int __fastcall FindPaper(const System::UnicodeString AName)/* overload */;
	int __fastcall FindPaper(const System::Types::TPoint ASize)/* overload */;
	int __fastcall FindPaper(int AWidth, int AHeight)/* overload */;
	bool __fastcall IsEnvelopePaper(int AIndex);
	bool __fastcall IsUserPaperSize(int AIndex);
	bool __fastcall SelectPaper(int ADMPaper)/* overload */;
	bool __fastcall SelectPaper(const System::UnicodeString AName)/* overload */;
	bool __fastcall SelectPaper(int &AWidth, int &AHeight)/* overload */;
	bool __fastcall IsSupportColoration(void);
	bool __fastcall IsSupportDuplex(void);
	__property bool Aborted = {read=FAborted, nodefault};
	__property bool AutoRefresh = {read=FAutoRefresh, write=FAutoRefresh, nodefault};
	__property int BinIndex = {read=GetBinIndex, write=SetBinIndex, nodefault};
	__property System::Classes::TStrings* Bins = {read=GetBins};
	__property Vcl::Graphics::TCanvas* Canvas = {read=GetCanvas};
	__property TdxPrinterCapabilities Capabilities = {read=FCapabilities, nodefault};
	__property bool Collate = {read=GetCollate, write=SetCollate, nodefault};
	__property bool ColorMode = {read=GetColorMode, write=SetColorMode, nodefault};
	__property int Copies = {read=GetNumCopies, write=SetNumCopies, nodefault};
	__property System::WideChar * CurrentDevice = {read=GetCurrentDevice};
	__property System::WideChar * CurrentDriver = {read=GetCurrentDriver};
	__property System::WideChar * CurrentPort = {read=GetCurrentPort};
	__property int DefaultDMPaper = {read=GetDefaultDMPaper, nodefault};
	__property Winapi::Windows::PDeviceModeW DeviceMode = {read=GetDeviceMode};
	__property TdxDuplexMode Duplex = {read=GetDuplex, write=SetDuplex, nodefault};
	__property System::UnicodeString FileName = {read=FFileName, write=FFileName};
	__property System::Classes::TStrings* Fonts = {read=GetFonts};
	__property HDC Handle = {read=GetHandle};
	__property NativeUInt HDeviceMode = {read=GetHDeviceMode};
	__property bool IsDefault = {read=GetIsDefault, write=SetIsDefault, nodefault};
	__property bool IsDeviceModePersistent = {read=FIsDeviceModePersistent, write=FIsDeviceModePersistent, nodefault};
	__property bool IsInitialized = {read=GetIsInitialized, nodefault};
	__property bool IsNetwork = {read=GetIsNetwork, nodefault};
	__property int MaxCopies = {read=FMaxCopies, nodefault};
	__property int MaxExtentX = {read=GetMaxExtents, index=0, nodefault};
	__property int MaxExtentY = {read=GetMaxExtents, index=1, nodefault};
	__property int MinExtentX = {read=GetMinExtents, index=0, nodefault};
	__property int MinExtentY = {read=GetMinExtents, index=1, nodefault};
	__property TdxPrinterOrientation Orientation = {read=GetOrientation, write=SetOrientation, nodefault};
	__property int PageHeight = {read=GetPageHeight, nodefault};
	__property int PageHeightLoMetric = {read=GetPageHeightLoMetric, nodefault};
	__property int PageWidth = {read=GetPageWidth, nodefault};
	__property int PageWidthLoMetric = {read=GetPageWidthLoMetric, nodefault};
	__property int PageNumber = {read=FPageNumber, nodefault};
	__property int PaperIndex = {read=GetPaperIndex, write=SetPaperIndex, nodefault};
	__property int PaperCount = {read=GetPaperCount, nodefault};
	__property System::Classes::TStrings* Papers = {read=GetPapers};
	__property int PhysOffsetX = {read=GetPhysOffset, index=0, nodefault};
	__property int PhysOffsetY = {read=GetPhysOffset, index=1, nodefault};
	__property int PrinterCount = {read=GetPrinterCount, nodefault};
	__property int PrinterIndex = {read=GetPrinterIndex, write=SetPrinterIndex, nodefault};
	__property TdxPrintDeviceInfo* PrinterInfos[int Index] = {read=GetPrinterInfo};
	__property System::Classes::TStrings* Printers = {read=GetPrinters};
	__property bool Printing = {read=FPrinting, nodefault};
	__property System::UnicodeString Title = {read=FTitle, write=FTitle};
	__property System::Classes::TNotifyEvent OnNewPage = {read=FOnNewPage, write=FOnNewPage};
	__property System::Classes::TNotifyEvent OnPrinterChange = {read=FOnPrinterChange, write=FOnPrinterChange};
	__property System::Classes::TNotifyEvent OnRefresh = {read=FOnRefresh, write=FOnRefresh};
};


class DELPHICLASS TdxPaperInfo;
class PASCALIMPLEMENTATION TdxPaperInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FDMPaper;
	System::UnicodeString FName;
	TdxPrintDevice* FPrintDevice;
	System::Types::TPoint FSize;
	int __fastcall GetSize(int Index);
	void __fastcall SetSize(int Index, int Value);
	
public:
	__fastcall TdxPaperInfo(TdxPrintDevice* APrintDevice);
	void __fastcall Assign(TdxPaperInfo* Source);
	bool __fastcall IsEqual(TdxPaperInfo* Source);
	__property int DMPaper = {read=FDMPaper, nodefault};
	__property int Height = {read=GetSize, write=SetSize, index=1, nodefault};
	__property System::UnicodeString Name = {read=FName};
	__property System::Types::TPoint Size = {read=FSize};
	__property int Width = {read=GetSize, write=SetSize, index=0, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPaperInfo(void) { }
	
};


typedef NativeUInt __stdcall (*TConnectToPrinterDlg)(HWND hWnd, unsigned Flags);

typedef BOOL __stdcall (*TGetDefaultPrinter)(System::WideChar * pszBuffer, unsigned &cchBuffer);

typedef BOOL __stdcall (*TGetDefaultPrinterA)(char * pszBuffer, unsigned &cchBuffer);

typedef BOOL __stdcall (*TGetDefaultPrinterW)(System::WideChar * pszBuffer, unsigned &cchBuffer);

typedef BOOL __stdcall (*TSetDefaultPrinter)(System::WideChar * pszPrinter);

typedef BOOL __stdcall (*TSetDefaultPrinterA)(char * pszPrinter);

typedef BOOL __stdcall (*TSetDefaultPrinterW)(System::WideChar * pszPrinter);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool dxPSUseCachedDMPaper;
static const System::Byte cMinPaperExtent = System::Byte(0xfe);
static const System::Word cMaxPaperExtent = System::Word(0x1dc4);
extern PACKAGE bool __fastcall dxIsPrintDeviceAllocated(void);
extern PACKAGE bool __fastcall dxIsPrintDeviceInitialized(void);
extern PACKAGE TdxPrintDevice* __fastcall dxPrintDevice(void);
extern PACKAGE bool __fastcall dxConnectToNetPrinter(HWND AParentWnd);
extern PACKAGE bool __fastcall dxDocumentProperties(HWND AParentWnd);
extern PACKAGE bool __fastcall dxInitPrintDevice(bool ARaiseException);
extern PACKAGE void __fastcall dxReleasePrintDevice(void);
extern PACKAGE TdxPrintDevice* __fastcall dxSetPrintDevice(TdxPrintDevice* APrintDevice);
extern PACKAGE bool __fastcall dxIsAutoSelectBin(const System::UnicodeString AName);
extern PACKAGE bool __fastcall dxIsEnvelopePaper(const System::UnicodeString AName);
extern PACKAGE int __fastcall dxGetDefaultDMPaper(void);
extern PACKAGE System::UnicodeString __fastcall dxGetDefaultPrinter(void);
extern PACKAGE bool __fastcall dxIsDefaultPrinter(System::WideChar * ADevice);
extern PACKAGE void __fastcall dxSetDefaultPrinter(System::WideChar * ADevice);
extern PACKAGE void __fastcall dxDrawPrinter(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, const System::UnicodeString AText, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, bool ADrawBackground = true);
extern PACKAGE void __fastcall dxGetPrinterList(System::Classes::TStrings* AStrings);
}	/* namespace Dxprndev */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPRNDEV)
using namespace Dxprndev;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxprndevHPP
