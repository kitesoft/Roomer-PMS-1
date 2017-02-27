// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxEditorLnks.pas' rev: 24.00 (Win32)

#ifndef DxpscxeditorlnksHPP
#define DxpscxeditorlnksHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSLbxLnk.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit
#include <dxPSTextLnk.hpp>	// Pascal unit
#include <dxPSGrLnks.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxeditorlnks
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxListBoxReportLink;
class PASCALIMPLEMENTATION TcxListBoxReportLink : public Dxpslbxlnk::TCustomdxListBoxReportLinkControl
{
	typedef Dxpslbxlnk::TCustomdxListBoxReportLinkControl inherited;
	
private:
	Cxlistbox::TcxListBox* __fastcall GetcxListBox(void);
	
protected:
	virtual Vcl::Stdctrls::TCustomListBox* __fastcall GetCustomListBox(void);
	
public:
	__property Cxlistbox::TcxListBox* cxListBox = {read=GetcxListBox};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property OddColor = {default=16777215};
	__property OddFont;
	__property Options = {default=3};
	__property Multiline = {default=0};
	__property PaintItemsGraphics = {default=0};
	__property RowAutoHeight = {default=0};
	__property ScaleFonts = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property TransparentGraphics = {default=0};
	__property UseCustomPageBreaks = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property Width;
	__property OnCustomDrawItem;
	__property OnGetCustomPageBreaks;
	__property OnInitializeItem;
public:
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TcxListBoxReportLink(System::Classes::TComponent* AOwner) : Dxpslbxlnk::TCustomdxListBoxReportLinkControl(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TcxListBoxReportLink(void) { }
	
};


class DELPHICLASS TcxCustomImageReportLink;
class PASCALIMPLEMENTATION TcxCustomImageReportLink : public Dxpsgraphiclnk::TCustomdxPictureReportLink
{
	typedef Dxpsgraphiclnk::TCustomdxPictureReportLink inherited;
	
private:
	Cximage::TcxCustomImage* __fastcall GetcxCustomImage(void);
	
protected:
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual int __fastcall GetGraphicHeight(void);
	virtual int __fastcall GetGraphicWidth(void);
	virtual Vcl::Graphics::TPicture* __fastcall GetPicture(void);
	__property Cximage::TcxCustomImage* cxCustomImage = {read=GetcxCustomImage};
	
public:
	__fastcall virtual TcxCustomImageReportLink(System::Classes::TComponent* AOwner);
	virtual bool __fastcall DataProviderPresent(void);
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TcxCustomImageReportLink(void) { }
	
};


class DELPHICLASS TcxImageReportLink;
class PASCALIMPLEMENTATION TcxImageReportLink : public TcxCustomImageReportLink
{
	typedef TcxCustomImageReportLink inherited;
	
private:
	Cximage::TcxImage* __fastcall GetcxImage(void);
	
public:
	__property Cximage::TcxImage* cxImage = {read=GetcxImage};
	
__published:
	__property BorderColor = {default=0};
	__property Center = {default=1};
	__property DrawBorder = {default=0};
	__property Proportional = {default=1};
	__property Stretch = {default=0};
	__property Transparent = {default=1};
	__property TransparentColor = {default=-16777211};
public:
	/* TcxCustomImageReportLink.Create */ inline __fastcall virtual TcxImageReportLink(System::Classes::TComponent* AOwner) : TcxCustomImageReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TcxImageReportLink(void) { }
	
};


class DELPHICLASS TcxCustomMemoReportLink;
class PASCALIMPLEMENTATION TcxCustomMemoReportLink : public Dxpstextlnk::TdxCustomMemoReportLink
{
	typedef Dxpstextlnk::TdxCustomMemoReportLink inherited;
	
private:
	Cxmemo::TcxCustomMemo* __fastcall GetcxCustomMemo(void);
	
protected:
	virtual Vcl::Stdctrls::TCustomMemo* __fastcall GetCustomMemo(void);
	__property Cxmemo::TcxCustomMemo* cxCustomMemo = {read=GetcxCustomMemo};
public:
	/* TdxCustomTextReportLink.Create */ inline __fastcall virtual TcxCustomMemoReportLink(System::Classes::TComponent* AOwner) : Dxpstextlnk::TdxCustomMemoReportLink(AOwner) { }
	/* TdxCustomTextReportLink.Destroy */ inline __fastcall virtual ~TcxCustomMemoReportLink(void) { }
	
};


class DELPHICLASS TcxMemoReportLink;
class PASCALIMPLEMENTATION TcxMemoReportLink : public TcxCustomMemoReportLink
{
	typedef TcxCustomMemoReportLink inherited;
	
private:
	Cxmemo::TcxMemo* __fastcall GetcxMemo(void);
	
public:
	__property Cxmemo::TcxMemo* cxMemo = {read=GetcxMemo};
public:
	/* TdxCustomTextReportLink.Create */ inline __fastcall virtual TcxMemoReportLink(System::Classes::TComponent* AOwner) : TcxCustomMemoReportLink(AOwner) { }
	/* TdxCustomTextReportLink.Destroy */ inline __fastcall virtual ~TcxMemoReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Vcl::Controls::TWinControl* __fastcall cxContainer_GetInnerControl(Cxcontainer::TcxContainer* AControl);
extern PACKAGE Cxcontrols::TcxControlScrollBar* __fastcall cxControl_GetHScrollBar(Cxcontrols::TcxControl* AControl);
extern PACKAGE Cxcontrols::TcxControlScrollBar* __fastcall cxControl_GetVScrollBar(Cxcontrols::TcxControl* AControl);
extern PACKAGE Cxcontrols::TcxSizeGrip* __fastcall cxControl_GetSizeGrip(Cxcontrols::TcxControl* AControl);
extern PACKAGE Cxedit::TcxCustomEditProperties* __fastcall cxEdit_GetProperties(Cxedit::TcxCustomEdit* AControl);
extern PACKAGE Vcl::Graphics::TPicture* __fastcall cxImage_GetPicture(Cximage::TcxCustomImage* AControl);
}	/* namespace Dxpscxeditorlnks */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXEDITORLNKS)
using namespace Dxpscxeditorlnks;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxeditorlnksHPP
