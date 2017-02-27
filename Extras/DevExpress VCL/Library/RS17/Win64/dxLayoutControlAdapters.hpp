// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutControlAdapters.pas' rev: 24.00 (Win64)

#ifndef DxlayoutcontroladaptersHPP
#define DxlayoutcontroladaptersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutcontroladapters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxLayoutComboAdapter;
class PASCALIMPLEMENTATION TdxLayoutComboAdapter : public Dxlayoutcontainer::TdxCustomLayoutControlAdapter
{
	typedef Dxlayoutcontainer::TdxCustomLayoutControlAdapter inherited;
	
protected:
	virtual bool __fastcall AllowCheckSize(void);
public:
	/* TdxCustomLayoutControlAdapter.Create */ inline __fastcall virtual TdxLayoutComboAdapter(Dxlayoutcontainer::TdxLayoutItem* AItem) : Dxlayoutcontainer::TdxCustomLayoutControlAdapter(AItem) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutComboAdapter(void) { }
	
};


class DELPHICLASS TdxLayoutPanelAdapter;
class PASCALIMPLEMENTATION TdxLayoutPanelAdapter : public Dxlayoutcontainer::TdxCustomLayoutControlAdapter
{
	typedef Dxlayoutcontainer::TdxCustomLayoutControlAdapter inherited;
	
protected:
	virtual bool __fastcall NeedBorder(void);
	virtual bool __fastcall UseItemColor(void);
public:
	/* TdxCustomLayoutControlAdapter.Create */ inline __fastcall virtual TdxLayoutPanelAdapter(Dxlayoutcontainer::TdxLayoutItem* AItem) : Dxlayoutcontainer::TdxCustomLayoutControlAdapter(AItem) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutPanelAdapter(void) { }
	
};


class DELPHICLASS TdxButtonControlAdapter;
class PASCALIMPLEMENTATION TdxButtonControlAdapter : public Dxlayoutcontainer::TdxCustomLayoutControlAdapter
{
	typedef Dxlayoutcontainer::TdxCustomLayoutControlAdapter inherited;
	
private:
	bool FChanged;
	int FStyles;
	NativeUInt __fastcall GetHandle(void);
	
protected:
	virtual void __fastcall BeginCustomization(void);
	virtual void __fastcall EndCustomization(void);
	__property NativeUInt Handle = {read=GetHandle};
public:
	/* TdxCustomLayoutControlAdapter.Create */ inline __fastcall virtual TdxButtonControlAdapter(Dxlayoutcontainer::TdxLayoutItem* AItem) : Dxlayoutcontainer::TdxCustomLayoutControlAdapter(AItem) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxButtonControlAdapter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxlayoutcontroladapters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTCONTROLADAPTERS)
using namespace Dxlayoutcontroladapters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutcontroladaptersHPP
