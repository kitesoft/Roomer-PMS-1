// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSRELnk.pas' rev: 24.00 (Win32)

#ifndef DxpsrelnkHPP
#define DxpsrelnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.RichEdit.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPSContainerLnk.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsrelnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSCustomRichEditProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomRichEditProducer : public Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer
{
	typedef Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer inherited;
	
protected:
	virtual Vcl::Graphics::TGraphic* __fastcall CreateImage(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Comctrls::TCustomRichEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomRichEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomRichEditProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSREPageRenderInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSREPageRenderInfo : public Dxpscore::TdxPSPageRenderInfo
{
	typedef Dxpscore::TdxPSPageRenderInfo inherited;
	
private:
	int __fastcall GetUnitsPerInch(void);
	
public:
	int FirstChar;
	int LastChar;
	System::Types::TRect DetailsTwipsRect;
	virtual void __fastcall AdjustTwipsRect(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateBounds(void);
	__property int UnitsPerInch = {read=GetUnitsPerInch, nodefault};
public:
	/* TdxPSPageRenderInfo.Create */ inline __fastcall virtual TdxPSREPageRenderInfo(Dxpscore::TdxPSReportRenderInfo* ARenderInfo, int APageIndex) : Dxpscore::TdxPSPageRenderInfo(ARenderInfo, APageIndex) { }
	/* TdxPSPageRenderInfo.Destroy */ inline __fastcall virtual ~TdxPSREPageRenderInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSREReportLinkRenderInfo;
class DELPHICLASS TAbstractdxRichEditReportLink;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSREReportLinkRenderInfo : public Dxpscore::TdxPSReportRenderInfo
{
	typedef Dxpscore::TdxPSReportRenderInfo inherited;
	
private:
	System::Types::TRect FDetailsTwipsRect;
	FORMATRANGE FFormatRange;
	System::Types::TPoint FPageSize;
	System::Types::TRect FPageTwipsRect;
	HIDESBASE TdxPSREPageRenderInfo* __fastcall GetPageRenderInfo(int Index);
	NativeUInt __fastcall GetREHandle(void);
	TAbstractdxRichEditReportLink* __fastcall GetReportLink(void);
	void __fastcall DoFormatRichEdit(void);
	void __fastcall FormatRichEdit(void);
	void __fastcall PrepareFormatRange(void);
	void __fastcall SetupFormatRangeForNonSelection(void);
	void __fastcall UnprepareFormatRange(void);
	
protected:
	int FirstChar;
	int LastChar;
	virtual void __fastcall CalculatePageRenderInfos(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall Refresh(void);
	virtual Dxpscore::TdxPSPageRenderInfoClass __fastcall GetPageRenderInfoClass(void);
	virtual int __fastcall GetPageColCount(void);
	virtual int __fastcall GetPageRowCount(void);
	virtual System::Types::TPoint __fastcall GetPageSize(void);
	virtual int __fastcall GetUnitsPerInch(void);
	virtual Dxpscore::TdxWindowScalePair __fastcall GetWindowScalePair(void);
	virtual int __fastcall LoMetricValueToInternalUnits(int Value);
	__property TdxPSREPageRenderInfo* PageRenderInfos[int Index] = {read=GetPageRenderInfo};
	__property NativeUInt REHandle = {read=GetREHandle, nodefault};
	__property TAbstractdxRichEditReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxPSReportRenderInfo.Create */ inline __fastcall virtual TdxPSREReportLinkRenderInfo(Dxpscore::TBasedxReportLink* AReportLink) : Dxpscore::TdxPSReportRenderInfo(AReportLink) { }
	/* TdxPSReportRenderInfo.Destroy */ inline __fastcall virtual ~TdxPSREReportLinkRenderInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSREReportRenderer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSREReportRenderer : public Dxpscore::TdxPSReportRenderer
{
	typedef Dxpscore::TdxPSReportRenderer inherited;
	
private:
	NativeUInt __fastcall GetREHandle(void);
	HIDESBASE TdxPSREPageRenderInfo* __fastcall GetPageRenderInfo(void);
	HIDESBASE TdxPSREReportLinkRenderInfo* __fastcall GetRenderInfo(void);
	TAbstractdxRichEditReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual void __fastcall PrepareFont(Vcl::Graphics::TFont* AFont, bool AAdjustOnScale);
	void __fastcall PrepareRects(void);
	virtual void __fastcall PrepareRenderPage(void);
	virtual void __fastcall RenderPageContent(void);
	void __fastcall UnprepareRects(void);
	virtual void __fastcall UnprepareRenderPage(void);
	__property NativeUInt REHandle = {read=GetREHandle, nodefault};
	__property TdxPSREPageRenderInfo* PageRenderInfo = {read=GetPageRenderInfo};
	__property TdxPSREReportLinkRenderInfo* RenderInfo = {read=GetRenderInfo};
	__property TAbstractdxRichEditReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxPSReportRenderer.Create */ inline __fastcall virtual TdxPSREReportRenderer(Dxpscore::TBasedxReportLink* AReportLink) : Dxpscore::TdxPSReportRenderer(AReportLink) { }
	/* TdxPSReportRenderer.Destroy */ inline __fastcall virtual ~TdxPSREReportRenderer(void) { }
	
};

#pragma pack(pop)

typedef System::Int8 TdxRichEditVersion;

class PASCALIMPLEMENTATION TAbstractdxRichEditReportLink : public Dxpscore::TBasedxReportLink
{
	typedef Dxpscore::TBasedxReportLink inherited;
	
private:
	bool FOnlySelected;
	TdxRichEditVersion FRichEditVersion;
	bool __fastcall GetHasText(void);
	void __fastcall SetOnlySelected(bool Value);
	void __fastcall SetRichEditVersion(TdxRichEditVersion Value);
	void __fastcall GetCharRange(int &ASelStart, int &ASelLength);
	
protected:
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall DoCustomDrawPageHeaderOrFooter(Dxprnpg::TCustomdxPageObject* AHFObject, Vcl::Graphics::TCanvas* ACanvas, int APageIndex, const System::Types::TRect &R, bool &ADefaultDrawText, bool &ADefaultDrawBackground);
	virtual void __fastcall DoCustomDrawPageTitle(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont, bool &ADone);
	virtual int __fastcall GetRealScaleFactor(void);
	virtual Dxpscore::TdxPSReportRendererClass __fastcall GetRendererClass(void);
	virtual Dxpscore::TdxPSReportRenderInfoClass __fastcall GetRenderInfoClass(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	NativeUInt __fastcall GetNativeHandle(void);
	void __fastcall SetNativeHandle(NativeUInt Value);
	virtual NativeUInt __fastcall GetRichEditHandle(void) = 0 ;
	bool __fastcall TryLoadRichEditDLL(int AVersion);
	__property bool HasText = {read=GetHasText, nodefault};
	
public:
	__fastcall virtual TAbstractdxRichEditReportLink(System::Classes::TComponent* AOwner);
	__classmethod virtual bool __fastcall Aggregable();
	__classmethod virtual bool __fastcall CanBeUsedAsStub();
	__classmethod virtual bool __fastcall Serializable();
	virtual bool __fastcall SupportsScaling(void);
	__property NativeUInt REHandle = {read=GetRichEditHandle, nodefault};
	
__published:
	__property bool OnlySelected = {read=FOnlySelected, write=SetOnlySelected, default=0};
	__property TdxRichEditVersion RichEditVersion = {read=FRichEditVersion, write=SetRichEditVersion, default=2};
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TAbstractdxRichEditReportLink(void) { }
	
private:
	void *__IdxPSNativeWin32ControlHandleSupport;	/* Dxpscore::IdxPSNativeWin32ControlHandleSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4B649281-A283-4CAC-98D4-08E779A7F9C8}
	operator Dxpscore::_di_IdxPSNativeWin32ControlHandleSupport()
	{
		Dxpscore::_di_IdxPSNativeWin32ControlHandleSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscore::IdxPSNativeWin32ControlHandleSupport*(void) { return (Dxpscore::IdxPSNativeWin32ControlHandleSupport*)&__IdxPSNativeWin32ControlHandleSupport; }
	#endif
	
};


class DELPHICLASS TCustomdxRichEditReportLink;
class PASCALIMPLEMENTATION TCustomdxRichEditReportLink : public TAbstractdxRichEditReportLink
{
	typedef TAbstractdxRichEditReportLink inherited;
	
protected:
	virtual Vcl::Comctrls::TCustomRichEdit* __fastcall GetCustomRichEdit(void);
	virtual NativeUInt __fastcall GetRichEditHandle(void);
	__property Vcl::Comctrls::TCustomRichEdit* CustomRichEdit = {read=GetCustomRichEdit};
public:
	/* TAbstractdxRichEditReportLink.Create */ inline __fastcall virtual TCustomdxRichEditReportLink(System::Classes::TComponent* AOwner) : TAbstractdxRichEditReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TCustomdxRichEditReportLink(void) { }
	
};


class DELPHICLASS TdxRichEditReportLink;
class PASCALIMPLEMENTATION TdxRichEditReportLink : public TCustomdxRichEditReportLink
{
	typedef TCustomdxRichEditReportLink inherited;
	
private:
	Vcl::Comctrls::TRichEdit* __fastcall GetRichEdit(void);
	
public:
	__property Vcl::Comctrls::TRichEdit* RichEdit = {read=GetRichEdit};
public:
	/* TAbstractdxRichEditReportLink.Create */ inline __fastcall virtual TdxRichEditReportLink(System::Classes::TComponent* AOwner) : TCustomdxRichEditReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxRichEditReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxDefaultRichEditVersion = System::Int8(0x2);
extern PACKAGE Vcl::Graphics::TGraphic* __fastcall GetRichEditAsGraphic(NativeUInt AWnd, System::Uitypes::TColor ABkColor, const System::Types::TRect &AMargins, Vcl::Graphics::TGraphicClass AGraphicClass = 0x0, int AWidth = 0xffffffff, int AHeight = 0xffffffff, int AMaxHeight = 0xffffffff, HDC ARefDC = (HDC)(0x0), int ARichEditVersion = 0x1)/* overload */;
}	/* namespace Dxpsrelnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSRELNK)
using namespace Dxpsrelnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsrelnkHPP
