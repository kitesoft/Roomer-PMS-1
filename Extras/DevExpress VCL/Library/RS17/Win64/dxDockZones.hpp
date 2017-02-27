// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDockZones.pas' rev: 24.00 (Win64)

#ifndef DxdockzonesHPP
#define DxdockzonesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxDockControl.hpp>	// Pascal unit
#include <dxDockPanel.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdockzones
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxLeftZone;
class PASCALIMPLEMENTATION TdxLeftZone : public Dxdockcontrol::TdxZone
{
	typedef Dxdockcontrol::TdxZone inherited;
	
protected:
	virtual Dxdockcontrol::TdxZoneDirection __fastcall GetDirection(void);
	virtual Dxdockcontrol::TdxDockingType __fastcall GetDockType(void);
	virtual System::Types::TRect __fastcall GetRectangle(void);
	virtual bool __fastcall CanConstrainedResize(int NewWidth, int NewHeight);
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	virtual System::Types::TRect __fastcall GetDockingSelection(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual System::Types::TRect __fastcall GetResizingSelection(System::Types::TPoint pt);
	virtual void __fastcall DoResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxLeftZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : Dxdockcontrol::TdxZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLeftZone(void) { }
	
};


class DELPHICLASS TdxRightZone;
class PASCALIMPLEMENTATION TdxRightZone : public Dxdockcontrol::TdxZone
{
	typedef Dxdockcontrol::TdxZone inherited;
	
protected:
	virtual Dxdockcontrol::TdxZoneDirection __fastcall GetDirection(void);
	virtual Dxdockcontrol::TdxDockingType __fastcall GetDockType(void);
	virtual System::Types::TRect __fastcall GetRectangle(void);
	virtual bool __fastcall CanConstrainedResize(int NewWidth, int NewHeight);
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	virtual System::Types::TRect __fastcall GetDockingSelection(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual System::Types::TRect __fastcall GetResizingSelection(System::Types::TPoint pt);
	virtual void __fastcall DoResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxRightZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : Dxdockcontrol::TdxZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRightZone(void) { }
	
};


class DELPHICLASS TdxTopZone;
class PASCALIMPLEMENTATION TdxTopZone : public Dxdockcontrol::TdxZone
{
	typedef Dxdockcontrol::TdxZone inherited;
	
protected:
	virtual Dxdockcontrol::TdxZoneDirection __fastcall GetDirection(void);
	virtual Dxdockcontrol::TdxDockingType __fastcall GetDockType(void);
	virtual System::Types::TRect __fastcall GetRectangle(void);
	virtual bool __fastcall CanConstrainedResize(int NewWidth, int NewHeight);
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	virtual System::Types::TRect __fastcall GetDockingSelection(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual System::Types::TRect __fastcall GetResizingSelection(System::Types::TPoint pt);
	virtual void __fastcall DoResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxTopZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : Dxdockcontrol::TdxZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTopZone(void) { }
	
};


class DELPHICLASS TdxBottomZone;
class PASCALIMPLEMENTATION TdxBottomZone : public Dxdockcontrol::TdxZone
{
	typedef Dxdockcontrol::TdxZone inherited;
	
protected:
	virtual Dxdockcontrol::TdxZoneDirection __fastcall GetDirection(void);
	virtual Dxdockcontrol::TdxDockingType __fastcall GetDockType(void);
	virtual System::Types::TRect __fastcall GetRectangle(void);
	virtual bool __fastcall CanConstrainedResize(int NewWidth, int NewHeight);
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	virtual System::Types::TRect __fastcall GetDockingSelection(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual System::Types::TRect __fastcall GetResizingSelection(System::Types::TPoint pt);
	virtual void __fastcall DoResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxBottomZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : Dxdockcontrol::TdxZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBottomZone(void) { }
	
};


class DELPHICLASS TdxClientZone;
class PASCALIMPLEMENTATION TdxClientZone : public Dxdockcontrol::TdxZone
{
	typedef Dxdockcontrol::TdxZone inherited;
	
protected:
	virtual Dxdockcontrol::TdxZoneDirection __fastcall GetDirection(void);
	virtual Dxdockcontrol::TdxDockingType __fastcall GetDockType(void);
	virtual System::Types::TRect __fastcall GetRectangle(void);
	
public:
	__fastcall TdxClientZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxClientZone(void) { }
	
};


class DELPHICLASS TdxInvisibleClientZone;
class PASCALIMPLEMENTATION TdxInvisibleClientZone : public TdxClientZone
{
	typedef TdxClientZone inherited;
	
protected:
	Dxdockcontrol::TdxCustomDockControl* __fastcall FindTargetDockControlInControl(Dxdockcontrol::TdxCustomDockControl* AControl);
	Dxdockcontrol::TdxCustomDockControl* __fastcall FindTargetDockControl(void);
	
public:
	virtual bool __fastcall CanDock(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual void __fastcall DoDock(Dxdockcontrol::TdxCustomDockControl* AControl);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxClientZone.Create */ inline __fastcall TdxInvisibleClientZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth) : TdxClientZone(AOwner, AWidth) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxInvisibleClientZone(void) { }
	
};


class DELPHICLASS TdxFloatZone;
class PASCALIMPLEMENTATION TdxFloatZone : public TdxClientZone
{
	typedef TdxClientZone inherited;
	
private:
	Dxdockcontrol::TdxFloatDockSite* __fastcall GetFloatSite(void);
	
protected:
	Dxdockcontrol::TdxZone* __fastcall FindTargetDockZone(void);
	
public:
	__fastcall TdxFloatZone(Dxdockcontrol::TdxFloatDockSite* AControl);
	virtual bool __fastcall CanDock(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual void __fastcall DoDock(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual void __fastcall PrepareSelectionRegion(Cxgraphics::TcxRegion* ARegion, Dxdockcontrol::TdxCustomDockControl* AControl, const System::Types::TRect &ARect);
	virtual bool __fastcall IsZonePoint(const System::Types::TPoint pt);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
	__property Dxdockcontrol::TdxFloatDockSite* FloatSite = {read=GetFloatSite};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFloatZone(void) { }
	
};


class DELPHICLASS TdxAutoHideLeftZone;
class PASCALIMPLEMENTATION TdxAutoHideLeftZone : public TdxLeftZone
{
	typedef TdxLeftZone inherited;
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxAutoHideLeftZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxLeftZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoHideLeftZone(void) { }
	
};


class DELPHICLASS TdxAutoHideRightZone;
class PASCALIMPLEMENTATION TdxAutoHideRightZone : public TdxRightZone
{
	typedef TdxRightZone inherited;
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxAutoHideRightZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxRightZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoHideRightZone(void) { }
	
};


class DELPHICLASS TdxAutoHideTopZone;
class PASCALIMPLEMENTATION TdxAutoHideTopZone : public TdxTopZone
{
	typedef TdxTopZone inherited;
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxAutoHideTopZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxTopZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoHideTopZone(void) { }
	
};


class DELPHICLASS TdxAutoHideBottomZone;
class PASCALIMPLEMENTATION TdxAutoHideBottomZone : public TdxBottomZone
{
	typedef TdxBottomZone inherited;
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxAutoHideBottomZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxBottomZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoHideBottomZone(void) { }
	
};


class DELPHICLASS TdxAutoSizeLeftZone;
class PASCALIMPLEMENTATION TdxAutoSizeLeftZone : public TdxLeftZone
{
	typedef TdxLeftZone inherited;
	
public:
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxAutoSizeLeftZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxLeftZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoSizeLeftZone(void) { }
	
};


class DELPHICLASS TdxAutoSizeRightZone;
class PASCALIMPLEMENTATION TdxAutoSizeRightZone : public TdxRightZone
{
	typedef TdxRightZone inherited;
	
public:
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxAutoSizeRightZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxRightZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoSizeRightZone(void) { }
	
};


class DELPHICLASS TdxAutoSizeTopZone;
class PASCALIMPLEMENTATION TdxAutoSizeTopZone : public TdxTopZone
{
	typedef TdxTopZone inherited;
	
public:
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxAutoSizeTopZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxTopZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoSizeTopZone(void) { }
	
};


class DELPHICLASS TdxAutoSizeBottomZone;
class PASCALIMPLEMENTATION TdxAutoSizeBottomZone : public TdxBottomZone
{
	typedef TdxBottomZone inherited;
	
public:
	__classmethod virtual bool __fastcall ValidateResizeZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TdxZone.Create */ inline __fastcall TdxAutoSizeBottomZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxBottomZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoSizeBottomZone(void) { }
	
};


class DELPHICLASS TdxAutoSizeClientZone;
class PASCALIMPLEMENTATION TdxAutoSizeClientZone : public TdxClientZone
{
	typedef TdxClientZone inherited;
	
public:
	virtual System::Types::TRect __fastcall GetDockingSelection(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual bool __fastcall IsZonePoint(const System::Types::TPoint pt);
public:
	/* TdxClientZone.Create */ inline __fastcall TdxAutoSizeClientZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth) : TdxClientZone(AOwner, AWidth) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoSizeClientZone(void) { }
	
};


class DELPHICLASS TdxInvisibleAutoSizeClientZone;
class PASCALIMPLEMENTATION TdxInvisibleAutoSizeClientZone : public TdxInvisibleClientZone
{
	typedef TdxInvisibleClientZone inherited;
	
public:
	virtual System::Types::TRect __fastcall GetDockingSelection(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual bool __fastcall IsZonePoint(const System::Types::TPoint pt);
public:
	/* TdxClientZone.Create */ inline __fastcall TdxInvisibleAutoSizeClientZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth) : TdxInvisibleClientZone(AOwner, AWidth) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxInvisibleAutoSizeClientZone(void) { }
	
};


class DELPHICLASS TdxCustomTabContainerZone;
class PASCALIMPLEMENTATION TdxCustomTabContainerZone : public TdxClientZone
{
	typedef TdxClientZone inherited;
	
protected:
	virtual void __fastcall CorrectTabRects(System::Types::TRect &ATabsRect, System::Types::TRect &ATabRect);
	virtual Cxpc::TcxTabPosition __fastcall GetTabPosition(void) = 0 ;
	virtual System::Types::TRect __fastcall GetTabRect(Dxdockcontrol::TdxCustomDockControl* AControl) = 0 ;
	virtual System::Types::TRect __fastcall GetTabsRect(void) = 0 ;
	
public:
	virtual void __fastcall PrepareSelectionRegion(Cxgraphics::TcxRegion* ARegion, Dxdockcontrol::TdxCustomDockControl* AControl, const System::Types::TRect &ARect);
public:
	/* TdxClientZone.Create */ inline __fastcall TdxCustomTabContainerZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth) : TdxClientZone(AOwner, AWidth) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomTabContainerZone(void) { }
	
};


class DELPHICLASS TdxTabContainerZone;
class PASCALIMPLEMENTATION TdxTabContainerZone : public TdxCustomTabContainerZone
{
	typedef TdxCustomTabContainerZone inherited;
	
private:
	Dxdockcontrol::TdxTabContainerDockSite* __fastcall GetTabContainer(void);
	
protected:
	virtual void __fastcall CorrectTabRects(System::Types::TRect &ATabsRect, System::Types::TRect &ATabRect);
	virtual int __fastcall GetDockIndex(void);
	virtual Cxpc::TcxTabPosition __fastcall GetTabPosition(void);
	virtual System::Types::TRect __fastcall GetTabRect(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual System::Types::TRect __fastcall GetTabsRect(void);
	
public:
	__fastcall TdxTabContainerZone(Dxdockcontrol::TdxTabContainerDockSite* AControl);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
	__property Dxdockcontrol::TdxTabContainerDockSite* TabContainer = {read=GetTabContainer};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTabContainerZone(void) { }
	
};


class DELPHICLASS TdxTabContainerCaptionZone;
class PASCALIMPLEMENTATION TdxTabContainerCaptionZone : public TdxTabContainerZone
{
	typedef TdxTabContainerZone inherited;
	
public:
	virtual bool __fastcall IsZonePoint(const System::Types::TPoint pt);
public:
	/* TdxTabContainerZone.Create */ inline __fastcall TdxTabContainerCaptionZone(Dxdockcontrol::TdxTabContainerDockSite* AControl) : TdxTabContainerZone(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTabContainerCaptionZone(void) { }
	
};


class DELPHICLASS TdxTabContainerTabZone;
class PASCALIMPLEMENTATION TdxTabContainerTabZone : public TdxTabContainerZone
{
	typedef TdxTabContainerZone inherited;
	
private:
	int FDockIndex;
	
protected:
	virtual int __fastcall GetDockIndex(void);
	
public:
	__fastcall TdxTabContainerTabZone(Dxdockcontrol::TdxTabContainerDockSite* AControl, int ADockIndex);
	virtual bool __fastcall IsZonePoint(const System::Types::TPoint pt);
	__classmethod virtual bool __fastcall ValidateDockZone(Dxdockcontrol::TdxCustomDockControl* AOwner, Dxdockcontrol::TdxCustomDockControl* AControl);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTabContainerTabZone(void) { }
	
};


class DELPHICLASS TdxTabContainerNewTabZone;
class PASCALIMPLEMENTATION TdxTabContainerNewTabZone : public TdxTabContainerTabZone
{
	typedef TdxTabContainerTabZone inherited;
	
public:
	__fastcall TdxTabContainerNewTabZone(Dxdockcontrol::TdxTabContainerDockSite* AControl);
	virtual bool __fastcall IsZonePoint(const System::Types::TPoint pt);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTabContainerNewTabZone(void) { }
	
};


class DELPHICLASS TdxHorizContainerZone;
class PASCALIMPLEMENTATION TdxHorizContainerZone : public TdxRightZone
{
	typedef TdxRightZone inherited;
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	virtual void __fastcall DoResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
public:
	/* TdxZone.Create */ inline __fastcall TdxHorizContainerZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxRightZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHorizContainerZone(void) { }
	
};


class DELPHICLASS TdxVertContainerZone;
class PASCALIMPLEMENTATION TdxVertContainerZone : public TdxBottomZone
{
	typedef TdxBottomZone inherited;
	
public:
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	virtual void __fastcall DoResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
public:
	/* TdxZone.Create */ inline __fastcall TdxVertContainerZone(Dxdockcontrol::TdxCustomDockControl* AOwner, int AWidth, Dxdockcontrol::TdxZoneKind AKind) : TdxBottomZone(AOwner, AWidth, AKind) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxVertContainerZone(void) { }
	
};


class DELPHICLASS TdxDockPanelClientZone;
class PASCALIMPLEMENTATION TdxDockPanelClientZone : public TdxCustomTabContainerZone
{
	typedef TdxCustomTabContainerZone inherited;
	
private:
	Dxdockpanel::TdxDockPanel* __fastcall GetDockPanel(void);
	
protected:
	virtual Cxpc::TcxTabPosition __fastcall GetTabPosition(void);
	virtual System::Types::TRect __fastcall GetTabRect(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual System::Types::TRect __fastcall GetTabsRect(void);
	
public:
	__fastcall TdxDockPanelClientZone(Dxdockpanel::TdxDockPanel* AControl);
	__property Dxdockpanel::TdxDockPanel* DockPanel = {read=GetDockPanel};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockPanelClientZone(void) { }
	
};


class DELPHICLASS TdxDockPanelCaptionClientZone;
class PASCALIMPLEMENTATION TdxDockPanelCaptionClientZone : public TdxDockPanelClientZone
{
	typedef TdxDockPanelClientZone inherited;
	
public:
	virtual bool __fastcall IsZonePoint(const System::Types::TPoint pt);
public:
	/* TdxDockPanelClientZone.Create */ inline __fastcall TdxDockPanelCaptionClientZone(Dxdockpanel::TdxDockPanel* AControl) : TdxDockPanelClientZone(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockPanelCaptionClientZone(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdockzones */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCKZONES)
using namespace Dxdockzones;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdockzonesHPP
