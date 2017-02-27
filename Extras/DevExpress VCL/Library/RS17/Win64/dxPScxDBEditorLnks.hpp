// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxDBEditorLnks.pas' rev: 24.00 (Win64)

#ifndef DxpscxdbeditorlnksHPP
#define DxpscxdbeditorlnksHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <dxPScxEditorLnks.hpp>	// Pascal unit
#include <dxPSLbxLnk.hpp>	// Pascal unit
#include <dxPSGrLnks.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSTextLnk.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxdbeditorlnks
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBListBoxReportLink;
class PASCALIMPLEMENTATION TcxDBListBoxReportLink : public Dxpscxeditorlnks::TcxListBoxReportLink
{
	typedef Dxpscxeditorlnks::TcxListBoxReportLink inherited;
	
private:
	Cxdbedit::TcxDBListBox* __fastcall GetcxDBListBox(void);
	
public:
	__property Cxdbedit::TcxDBListBox* cxDBListBox = {read=GetcxDBListBox};
public:
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TcxDBListBoxReportLink(System::Classes::TComponent* AOwner) : Dxpscxeditorlnks::TcxListBoxReportLink(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TcxDBListBoxReportLink(void) { }
	
};


class DELPHICLASS TcxDBImageReportLink;
class PASCALIMPLEMENTATION TcxDBImageReportLink : public Dxpscxeditorlnks::TcxCustomImageReportLink
{
	typedef Dxpscxeditorlnks::TcxCustomImageReportLink inherited;
	
private:
	Cxdbedit::TcxDBImage* __fastcall GetcxDBImage(void);
	
public:
	__property Cxdbedit::TcxDBImage* cxDBImage = {read=GetcxDBImage};
	
__published:
	__property BorderColor = {default=0};
	__property Center = {default=0};
	__property DrawBorder = {default=0};
	__property Stretch = {default=0};
	__property Transparent = {default=1};
	__property TransparentColor = {default=-16777211};
public:
	/* TcxCustomImageReportLink.Create */ inline __fastcall virtual TcxDBImageReportLink(System::Classes::TComponent* AOwner) : Dxpscxeditorlnks::TcxCustomImageReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TcxDBImageReportLink(void) { }
	
};


class DELPHICLASS TcxDBMemoReportLink;
class PASCALIMPLEMENTATION TcxDBMemoReportLink : public Dxpscxeditorlnks::TcxCustomMemoReportLink
{
	typedef Dxpscxeditorlnks::TcxCustomMemoReportLink inherited;
	
private:
	Cxdbedit::TcxDBMemo* __fastcall GetcxDBMemo(void);
	
public:
	__property Cxdbedit::TcxDBMemo* cxDBMemo = {read=GetcxDBMemo};
public:
	/* TdxCustomTextReportLink.Create */ inline __fastcall virtual TcxDBMemoReportLink(System::Classes::TComponent* AOwner) : Dxpscxeditorlnks::TcxCustomMemoReportLink(AOwner) { }
	/* TdxCustomTextReportLink.Destroy */ inline __fastcall virtual ~TcxDBMemoReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxdbeditorlnks */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXDBEDITORLNKS)
using namespace Dxpscxdbeditorlnks;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxdbeditorlnksHPP
