// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSdxDBTVLnk.pas' rev: 24.00 (Win64)

#ifndef DxpsdxdbtvlnkHPP
#define DxpsdxdbtvlnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxtree.hpp>	// Pascal unit
#include <dxdbtree.hpp>	// Pascal unit
#include <dxPSTVLnk.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdxdbtvlnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxTreeViewExReportLink;
class PASCALIMPLEMENTATION TdxTreeViewExReportLink : public Dxpstvlnk::TCustomdxTreeViewReportLink
{
	typedef Dxpstvlnk::TCustomdxTreeViewReportLink inherited;
	
private:
	Dxtree::TdxTreeView* __fastcall GetdxTreeView(void);
	
protected:
	virtual void __fastcall InternalRestoreFromOriginal(void);
	
public:
	__property Dxtree::TdxTreeView* dxTreeView = {read=GetdxTreeView};
	
__published:
	__property AutoNodesExpand = {default=0};
	__property AutoWidth = {default=1};
	__property Color = {default=16777215};
	__property ExpandLevel = {default=-1};
	__property ExplicitTreeViewExpand = {default=0};
	__property Font;
	__property GridLineColor = {default=0};
	__property Options = {default=60};
	__property ScaleFonts = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property TreeLineColor = {default=8421504};
	__property UseVertDelimiters = {default=1};
	__property Width;
	__property OnCustomDrawNode;
	__property OnInitializeNode;
public:
	/* TCustomdxTreeViewReportLink.Create */ inline __fastcall virtual TdxTreeViewExReportLink(System::Classes::TComponent* AOwner) : Dxpstvlnk::TCustomdxTreeViewReportLink(AOwner) { }
	/* TCustomdxTreeViewReportLink.Destroy */ inline __fastcall virtual ~TdxTreeViewExReportLink(void) { }
	
};


class DELPHICLASS TdxDBTreeViewReportLink;
class PASCALIMPLEMENTATION TdxDBTreeViewReportLink : public TdxTreeViewExReportLink
{
	typedef TdxTreeViewExReportLink inherited;
	
private:
	System::DynamicArray<System::Byte> FBookmark;
	// System::TArray__1<System::Byte>  FBookmark;
	Dxdbtree::TdxDBTreeView* __fastcall GetDBTreeView(void);
	
protected:
	virtual void __fastcall PrepareContruct(void);
	virtual void __fastcall UnprepareContruct(void);
	
public:
	__property Dxdbtree::TdxDBTreeView* DBTreeView = {read=GetDBTreeView};
public:
	/* TCustomdxTreeViewReportLink.Create */ inline __fastcall virtual TdxDBTreeViewReportLink(System::Classes::TComponent* AOwner) : TdxTreeViewExReportLink(AOwner) { }
	/* TCustomdxTreeViewReportLink.Destroy */ inline __fastcall virtual ~TdxDBTreeViewReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsdxdbtvlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDXDBTVLNK)
using namespace Dxpsdxdbtvlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdxdbtvlnkHPP
