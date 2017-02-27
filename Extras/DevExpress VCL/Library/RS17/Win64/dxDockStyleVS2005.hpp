// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDockStyleVS2005.pas' rev: 24.00 (Win64)

#ifndef Dxdockstylevs2005HPP
#define Dxdockstylevs2005HPP

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
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxDockControl.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdockstylevs2005
{
//-- type declarations -------------------------------------------------------
enum TdxDockingTargetSelectorZoneKind : unsigned char { tszLeft, tszRight, tszTop, tszBottom, tszClient, tszDockSiteLeft, tszDockSiteRight, tszDockSiteTop, tszDockSiteBottom };

class DELPHICLASS TdxDockingTargetSelectorZoneViewInfo;
class DELPHICLASS TdxDockingCustomTargetSelector;
class PASCALIMPLEMENTATION TdxDockingTargetSelectorZoneViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxDockingTargetSelectorZoneKind FKind;
	TdxDockingCustomTargetSelector* FOwner;
	Dxdockcontrol::TdxZone* FZone;
	bool __fastcall GetActive(void);
	bool __fastcall GetEnabled(void);
	
public:
	__fastcall virtual TdxDockingTargetSelectorZoneViewInfo(TdxDockingCustomTargetSelector* AOwner, TdxDockingTargetSelectorZoneKind AKind, Dxdockcontrol::TdxZone* AZone);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property bool Active = {read=GetActive, nodefault};
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property TdxDockingTargetSelectorZoneKind Kind = {read=FKind, nodefault};
	__property TdxDockingCustomTargetSelector* Owner = {read=FOwner};
	__property Dxdockcontrol::TdxZone* Zone = {read=FZone};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockingTargetSelectorZoneViewInfo(void) { }
	
};


class DELPHICLASS TdxDockingTargetSelectorCustomPainter;
class PASCALIMPLEMENTATION TdxDockingTargetSelectorCustomPainter : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual HRGN __fastcall CalculateClientTargetSelectorRegion(void) = 0 ;
	virtual void __fastcall DrawClientTargetSelectorBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R) = 0 ;
	virtual System::Types::TRect __fastcall GetClientTargetSelectorContentOffsets(void) = 0 ;
	virtual void __fastcall DrawZone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AActive, bool AEnabled, TdxDockingTargetSelectorZoneKind AKind) = 0 ;
	virtual System::Types::TSize __fastcall GetZoneSize(TdxDockingTargetSelectorZoneKind AKind) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TdxDockingTargetSelectorCustomPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockingTargetSelectorCustomPainter(void) { }
	
};


class DELPHICLASS TdxDockingTargetSelectorPainter;
class PASCALIMPLEMENTATION TdxDockingTargetSelectorPainter : public TdxDockingTargetSelectorCustomPainter
{
	typedef TdxDockingTargetSelectorCustomPainter inherited;
	
private:
	Cxgraphics::TcxBitmap* FClientTargetSelectorBackground;
	System::StaticArray<Cxgraphics::TcxBitmap*, 9> FZonesBitmaps;
	
protected:
	void __fastcall DoDrawZone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxDockingTargetSelectorZoneKind AKind, int AState);
	Cxgraphics::TcxBitmap* __fastcall LoadBitmap(const System::UnicodeString AResourceName);
	
public:
	__fastcall virtual TdxDockingTargetSelectorPainter(void);
	__fastcall virtual ~TdxDockingTargetSelectorPainter(void);
	virtual HRGN __fastcall CalculateClientTargetSelectorRegion(void);
	virtual void __fastcall DrawClientTargetSelectorBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall GetClientTargetSelectorContentOffsets(void);
	virtual void __fastcall DrawZone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AActive, bool AEnabled, TdxDockingTargetSelectorZoneKind AKind);
	virtual System::Types::TSize __fastcall GetZoneSize(TdxDockingTargetSelectorZoneKind AKind);
};


class PASCALIMPLEMENTATION TdxDockingCustomTargetSelector : public Cxcontrols::TcxCustomDragImage
{
	typedef Cxcontrols::TcxCustomDragImage inherited;
	
private:
	TdxDockingTargetSelectorZoneViewInfo* FActiveTargetZone;
	TdxDockingTargetSelectorCustomPainter* FPainter;
	Dxdockcontrol::TdxCustomDockControl* FDockControl;
	Cxclasses::TcxObjectList* FTargetZones;
	Dxdockcontrol::TdxZone* __fastcall GetTargetZone(void);
	System::Types::TSize __fastcall GetTargetZoneSize(TdxDockingTargetSelectorZoneKind AKind);
	TdxDockingTargetSelectorZoneViewInfo* __fastcall GetTargetZoneViewInfo(int Index);
	int __fastcall GetTargetZoneViewInfoCount(void);
	void __fastcall SetActiveTargetZone(TdxDockingTargetSelectorZoneViewInfo* AValue);
	void __fastcall SetDockControl(Dxdockcontrol::TdxCustomDockControl* AValue);
	
protected:
	TdxDockingTargetSelectorZoneViewInfo* __fastcall AddZoneViewInfo(TdxDockingTargetSelectorZoneKind AKind);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateTargetZones(void) = 0 ;
	DYNAMIC void __fastcall Paint(void);
	__property Cxclasses::TcxObjectList* TargetZones = {read=FTargetZones};
	
public:
	__fastcall virtual TdxDockingCustomTargetSelector(TdxDockingTargetSelectorCustomPainter* APainter);
	__fastcall virtual ~TdxDockingCustomTargetSelector(void);
	virtual void __fastcall CalculateHitTest(const System::Types::TPoint AScreenPoint);
	TdxDockingTargetSelectorZoneViewInfo* __fastcall GetTargetZoneAtPoint(const System::Types::TPoint APoint);
	__property TdxDockingTargetSelectorZoneViewInfo* ActiveTargetZone = {read=FActiveTargetZone, write=SetActiveTargetZone};
	__property Dxdockcontrol::TdxCustomDockControl* DockControl = {read=FDockControl, write=SetDockControl};
	__property TdxDockingTargetSelectorCustomPainter* Painter = {read=FPainter};
	__property Dxdockcontrol::TdxZone* TargetZone = {read=GetTargetZone};
	__property System::Types::TSize TargetZoneSize[TdxDockingTargetSelectorZoneKind AKind] = {read=GetTargetZoneSize};
	__property TdxDockingTargetSelectorZoneViewInfo* TargetZoneViewInfo[int Index] = {read=GetTargetZoneViewInfo};
	__property int TargetZoneViewInfoCount = {read=GetTargetZoneViewInfoCount, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxDockingCustomTargetSelector(System::Classes::TComponent* AOwner, int Dummy) : Cxcontrols::TcxCustomDragImage(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockingCustomTargetSelector(HWND ParentWindow) : Cxcontrols::TcxCustomDragImage(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxDockingCustomTargetSelectorClass;

class DELPHICLASS TdxDockingControllerVS2005Helper;
class PASCALIMPLEMENTATION TdxDockingControllerVS2005Helper : public Dxdockcontrol::TdxDockingControllerHelper
{
	typedef Dxdockcontrol::TdxDockingControllerHelper inherited;
	
private:
	TdxDockingTargetSelectorCustomPainter* FPainter;
	System::StaticArray<TdxDockingCustomTargetSelector*, 5> FTargetSelectors;
	TdxDockingCustomTargetSelector* __fastcall GetTargetSelector(Dxdockcontrol::TdxDockingType AType);
	
protected:
	virtual bool __fastcall CheckTargetDockControl(const System::Types::TPoint APoint, Dxdockcontrol::TdxCustomDockControl* AControl, Dxdockcontrol::TdxCustomDockControl* ATargetDockControl);
	virtual TdxDockingCustomTargetSelector* __fastcall CreateTargetSelector(Dxdockcontrol::TdxDockingType AType);
	virtual TdxDockingTargetSelectorCustomPainter* __fastcall CreateTargetSelectorPainter(void);
	virtual Dxdockcontrol::TdxCustomDockControl* __fastcall GetDockingTargetControl(Dxdockcontrol::TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	virtual Dxdockcontrol::TdxCustomDockSite* __fastcall GetDockSite(Vcl::Controls::TWinControl* AControl);
	virtual Dxdockcontrol::TdxZone* __fastcall GetTargetZone(const System::Types::TPoint APoint);
	void __fastcall SetDockingParams(Dxdockcontrol::TdxCustomDockControl* AControl, Dxdockcontrol::TdxZone* AZone, const System::Types::TPoint APoint);
	virtual void __fastcall UpdateTargetSelectors(Dxdockcontrol::TdxCustomDockControl* ATargetDockControl, Dxdockcontrol::TdxCustomDockControl* ATargetDockSite);
	
public:
	virtual void __fastcall DockingFinish(Dxdockcontrol::TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	virtual void __fastcall DockingMove(Dxdockcontrol::TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	virtual void __fastcall DockingStart(Dxdockcontrol::TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	__property TdxDockingTargetSelectorCustomPainter* Painter = {read=FPainter};
	__property TdxDockingCustomTargetSelector* TargetSelector[Dxdockcontrol::TdxDockingType AType] = {read=GetTargetSelector};
public:
	/* TObject.Create */ inline __fastcall TdxDockingControllerVS2005Helper(void) : Dxdockcontrol::TdxDockingControllerHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockingControllerVS2005Helper(void) { }
	
};


class DELPHICLASS TdxDockingClientTargetSelector;
class PASCALIMPLEMENTATION TdxDockingClientTargetSelector : public TdxDockingCustomTargetSelector
{
	typedef TdxDockingCustomTargetSelector inherited;
	
private:
	System::Types::TRect __fastcall CalculateClientRect(void);
	int __fastcall CalculateHorizontalRowMaxSize(void);
	int __fastcall CalculateVerticalRowMaxSize(void);
	
protected:
	virtual void __fastcall CalculateClientZone(void);
	virtual void __fastcall CalculateHorizontalZones(void);
	virtual void __fastcall CalculateTargetZones(void);
	virtual void __fastcall CalculateVerticalZones(void);
	DYNAMIC void __fastcall Paint(void);
public:
	/* TdxDockingCustomTargetSelector.Create */ inline __fastcall virtual TdxDockingClientTargetSelector(TdxDockingTargetSelectorCustomPainter* APainter) : TdxDockingCustomTargetSelector(APainter) { }
	/* TdxDockingCustomTargetSelector.Destroy */ inline __fastcall virtual ~TdxDockingClientTargetSelector(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxDockingClientTargetSelector(System::Classes::TComponent* AOwner, int Dummy) : TdxDockingCustomTargetSelector(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockingClientTargetSelector(HWND ParentWindow) : TdxDockingCustomTargetSelector(ParentWindow) { }
	
};


class DELPHICLASS TdxDockingParentTargetSelector;
class PASCALIMPLEMENTATION TdxDockingParentTargetSelector : public TdxDockingCustomTargetSelector
{
	typedef TdxDockingCustomTargetSelector inherited;
	
protected:
	virtual void __fastcall CalculateTargetZones(void);
	virtual TdxDockingTargetSelectorZoneKind __fastcall GetZoneKind(void) = 0 ;
	virtual void __fastcall PlaceTargetSelector(const System::Types::TRect &ATargetWindowRect) = 0 ;
	
public:
	__property TdxDockingTargetSelectorZoneKind ZoneKind = {read=GetZoneKind, nodefault};
public:
	/* TdxDockingCustomTargetSelector.Create */ inline __fastcall virtual TdxDockingParentTargetSelector(TdxDockingTargetSelectorCustomPainter* APainter) : TdxDockingCustomTargetSelector(APainter) { }
	/* TdxDockingCustomTargetSelector.Destroy */ inline __fastcall virtual ~TdxDockingParentTargetSelector(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxDockingParentTargetSelector(System::Classes::TComponent* AOwner, int Dummy) : TdxDockingCustomTargetSelector(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockingParentTargetSelector(HWND ParentWindow) : TdxDockingCustomTargetSelector(ParentWindow) { }
	
};


class DELPHICLASS TdxDockingLeftTargetSelector;
class PASCALIMPLEMENTATION TdxDockingLeftTargetSelector : public TdxDockingParentTargetSelector
{
	typedef TdxDockingParentTargetSelector inherited;
	
protected:
	virtual TdxDockingTargetSelectorZoneKind __fastcall GetZoneKind(void);
	virtual void __fastcall PlaceTargetSelector(const System::Types::TRect &ATargetWindowRect);
public:
	/* TdxDockingCustomTargetSelector.Create */ inline __fastcall virtual TdxDockingLeftTargetSelector(TdxDockingTargetSelectorCustomPainter* APainter) : TdxDockingParentTargetSelector(APainter) { }
	/* TdxDockingCustomTargetSelector.Destroy */ inline __fastcall virtual ~TdxDockingLeftTargetSelector(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxDockingLeftTargetSelector(System::Classes::TComponent* AOwner, int Dummy) : TdxDockingParentTargetSelector(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockingLeftTargetSelector(HWND ParentWindow) : TdxDockingParentTargetSelector(ParentWindow) { }
	
};


class DELPHICLASS TdxDockingRightTargetSelector;
class PASCALIMPLEMENTATION TdxDockingRightTargetSelector : public TdxDockingParentTargetSelector
{
	typedef TdxDockingParentTargetSelector inherited;
	
protected:
	virtual TdxDockingTargetSelectorZoneKind __fastcall GetZoneKind(void);
	virtual void __fastcall PlaceTargetSelector(const System::Types::TRect &ATargetWindowRect);
public:
	/* TdxDockingCustomTargetSelector.Create */ inline __fastcall virtual TdxDockingRightTargetSelector(TdxDockingTargetSelectorCustomPainter* APainter) : TdxDockingParentTargetSelector(APainter) { }
	/* TdxDockingCustomTargetSelector.Destroy */ inline __fastcall virtual ~TdxDockingRightTargetSelector(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxDockingRightTargetSelector(System::Classes::TComponent* AOwner, int Dummy) : TdxDockingParentTargetSelector(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockingRightTargetSelector(HWND ParentWindow) : TdxDockingParentTargetSelector(ParentWindow) { }
	
};


class DELPHICLASS TdxDockingTopTargetSelector;
class PASCALIMPLEMENTATION TdxDockingTopTargetSelector : public TdxDockingParentTargetSelector
{
	typedef TdxDockingParentTargetSelector inherited;
	
protected:
	virtual TdxDockingTargetSelectorZoneKind __fastcall GetZoneKind(void);
	virtual void __fastcall PlaceTargetSelector(const System::Types::TRect &ATargetWindowRect);
public:
	/* TdxDockingCustomTargetSelector.Create */ inline __fastcall virtual TdxDockingTopTargetSelector(TdxDockingTargetSelectorCustomPainter* APainter) : TdxDockingParentTargetSelector(APainter) { }
	/* TdxDockingCustomTargetSelector.Destroy */ inline __fastcall virtual ~TdxDockingTopTargetSelector(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxDockingTopTargetSelector(System::Classes::TComponent* AOwner, int Dummy) : TdxDockingParentTargetSelector(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockingTopTargetSelector(HWND ParentWindow) : TdxDockingParentTargetSelector(ParentWindow) { }
	
};


class DELPHICLASS TdxDockingBottomTargetSelector;
class PASCALIMPLEMENTATION TdxDockingBottomTargetSelector : public TdxDockingParentTargetSelector
{
	typedef TdxDockingParentTargetSelector inherited;
	
protected:
	virtual TdxDockingTargetSelectorZoneKind __fastcall GetZoneKind(void);
	virtual void __fastcall PlaceTargetSelector(const System::Types::TRect &ATargetWindowRect);
public:
	/* TdxDockingCustomTargetSelector.Create */ inline __fastcall virtual TdxDockingBottomTargetSelector(TdxDockingTargetSelectorCustomPainter* APainter) : TdxDockingParentTargetSelector(APainter) { }
	/* TdxDockingCustomTargetSelector.Destroy */ inline __fastcall virtual ~TdxDockingBottomTargetSelector(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxDockingBottomTargetSelector(System::Classes::TComponent* AOwner, int Dummy) : TdxDockingParentTargetSelector(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockingBottomTargetSelector(HWND ParentWindow) : TdxDockingParentTargetSelector(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdockstylevs2005 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCKSTYLEVS2005)
using namespace Dxdockstylevs2005;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxdockstylevs2005HPP
