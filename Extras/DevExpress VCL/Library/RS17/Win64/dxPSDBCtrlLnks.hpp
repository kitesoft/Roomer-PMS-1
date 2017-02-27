// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSDBCtrlLnks.pas' rev: 24.00 (Win64)

#ifndef DxpsdbctrllnksHPP
#define DxpsdbctrllnksHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.DBCtrls.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit
#include <dxPSLbxLnk.hpp>	// Pascal unit
#include <dxPSTextLnk.hpp>	// Pascal unit
#include <dxPSRELnk.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSGrLnks.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdbctrllnks
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDBImageReportLink;
class PASCALIMPLEMENTATION TdxDBImageReportLink : public Dxpsgraphiclnk::TCustomdxPictureReportLink
{
	typedef Dxpsgraphiclnk::TCustomdxPictureReportLink inherited;
	
private:
	Vcl::Dbctrls::TDBImage* __fastcall GetDBImage(void);
	
protected:
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual int __fastcall GetGraphicHeight(void);
	virtual int __fastcall GetGraphicWidth(void);
	virtual Vcl::Graphics::TPicture* __fastcall GetPicture(void);
	
public:
	virtual bool __fastcall DataProviderPresent(void);
	__property Vcl::Dbctrls::TDBImage* DBImage = {read=GetDBImage};
	
__published:
	__property BorderColor = {default=0};
	__property DrawBorder = {default=0};
	__property Transparent = {default=1};
	__property TransparentColor = {default=-16777211};
public:
	/* TCustomdxGraphicReportLink.Create */ inline __fastcall virtual TdxDBImageReportLink(System::Classes::TComponent* AOwner) : Dxpsgraphiclnk::TCustomdxPictureReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxDBImageReportLink(void) { }
	
};


class DELPHICLASS TdxDBListBoxReportLink;
class PASCALIMPLEMENTATION TdxDBListBoxReportLink : public Dxpslbxlnk::TCustomdxListBoxReportLinkControl
{
	typedef Dxpslbxlnk::TCustomdxListBoxReportLinkControl inherited;
	
private:
	Vcl::Dbctrls::TDBListBox* __fastcall GetDBListBox(void);
	
public:
	__property Vcl::Dbctrls::TDBListBox* DBListBox = {read=GetDBListBox};
	
__published:
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
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property Width;
	__property OnCustomDrawItem;
	__property OnInitializeItem;
public:
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TdxDBListBoxReportLink(System::Classes::TComponent* AOwner) : Dxpslbxlnk::TCustomdxListBoxReportLinkControl(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TdxDBListBoxReportLink(void) { }
	
};


class DELPHICLASS TdxDBRichEditReportLink;
class PASCALIMPLEMENTATION TdxDBRichEditReportLink : public Dxpsrelnk::TCustomdxRichEditReportLink
{
	typedef Dxpsrelnk::TCustomdxRichEditReportLink inherited;
	
private:
	Vcl::Dbctrls::TDBRichEdit* __fastcall GetDBRichEdit(void);
	
public:
	__property Vcl::Dbctrls::TDBRichEdit* DBRichEdit = {read=GetDBRichEdit};
public:
	/* TAbstractdxRichEditReportLink.Create */ inline __fastcall virtual TdxDBRichEditReportLink(System::Classes::TComponent* AOwner) : Dxpsrelnk::TCustomdxRichEditReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxDBRichEditReportLink(void) { }
	
};


class DELPHICLASS TdxDBMemoReportLink;
class PASCALIMPLEMENTATION TdxDBMemoReportLink : public Dxpstextlnk::TdxCustomMemoReportLink
{
	typedef Dxpstextlnk::TdxCustomMemoReportLink inherited;
	
private:
	Vcl::Dbctrls::TDBMemo* __fastcall GetMemo(void);
	
public:
	__property Vcl::Dbctrls::TDBMemo* Memo = {read=GetMemo};
public:
	/* TdxCustomTextReportLink.Create */ inline __fastcall virtual TdxDBMemoReportLink(System::Classes::TComponent* AOwner) : Dxpstextlnk::TdxCustomMemoReportLink(AOwner) { }
	/* TdxCustomTextReportLink.Destroy */ inline __fastcall virtual ~TdxDBMemoReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsdbctrllnks */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDBCTRLLNKS)
using namespace Dxpsdbctrllnks;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdbctrllnksHPP
