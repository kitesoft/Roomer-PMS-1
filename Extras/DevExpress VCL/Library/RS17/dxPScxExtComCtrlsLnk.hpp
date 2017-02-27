// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxExtComCtrlsLnk.pas' rev: 24.00 (Win32)

#ifndef DxpscxextcomctrlslnkHPP
#define DxpscxextcomctrlslnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxRichEdit.hpp>	// Pascal unit
#include <cxDBRichEdit.hpp>	// Pascal unit
#include <cxShellTreeView.hpp>	// Pascal unit
#include <cxShellListView.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSTVLnk.hpp>	// Pascal unit
#include <dxPSLVLnk.hpp>	// Pascal unit
#include <dxPSRELnk.hpp>	// Pascal unit
#include <dxPSContainerLnk.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxextcomctrlslnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomTreeViewReportLink;
class PASCALIMPLEMENTATION TcxCustomTreeViewReportLink : public Dxpstvlnk::TCustomdxTreeViewReportLink
{
	typedef Dxpstvlnk::TCustomdxTreeViewReportLink inherited;
	
private:
	Cxtreeview::TcxCustomTreeView* __fastcall GetcxCustomTreeView(void);
	
protected:
	virtual Vcl::Comctrls::TCustomTreeView* __fastcall GetCustomTreeView(void);
	__property Cxtreeview::TcxCustomTreeView* cxCustomTreeView = {read=GetcxCustomTreeView};
public:
	/* TCustomdxTreeViewReportLink.Create */ inline __fastcall virtual TcxCustomTreeViewReportLink(System::Classes::TComponent* AOwner) : Dxpstvlnk::TCustomdxTreeViewReportLink(AOwner) { }
	/* TCustomdxTreeViewReportLink.Destroy */ inline __fastcall virtual ~TcxCustomTreeViewReportLink(void) { }
	
};


class DELPHICLASS TcxTreeViewReportLink;
class PASCALIMPLEMENTATION TcxTreeViewReportLink : public TcxCustomTreeViewReportLink
{
	typedef TcxCustomTreeViewReportLink inherited;
	
private:
	Cxtreeview::TcxTreeView* __fastcall GetcxTreeView(void);
	
public:
	__property Cxtreeview::TcxTreeView* cxTreeView = {read=GetcxTreeView};
	
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
	/* TCustomdxTreeViewReportLink.Create */ inline __fastcall virtual TcxTreeViewReportLink(System::Classes::TComponent* AOwner) : TcxCustomTreeViewReportLink(AOwner) { }
	/* TCustomdxTreeViewReportLink.Destroy */ inline __fastcall virtual ~TcxTreeViewReportLink(void) { }
	
};


class DELPHICLASS TcxShellTreeViewReportLink;
class PASCALIMPLEMENTATION TcxShellTreeViewReportLink : public TcxCustomTreeViewReportLink
{
	typedef TcxCustomTreeViewReportLink inherited;
	
private:
	Cxshelltreeview::TcxShellTreeView* __fastcall GetcxShellTreeView(void);
	
protected:
	virtual Vcl::Comctrls::TCustomTreeView* __fastcall GetCustomTreeView(void);
	virtual void __fastcall CreateImages(void);
	virtual void __fastcall DeleteImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	virtual bool __fastcall HasStateImages(void);
	
public:
	__property Cxshelltreeview::TcxShellTreeView* cxShellTreeView = {read=GetcxShellTreeView};
	
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
	/* TCustomdxTreeViewReportLink.Create */ inline __fastcall virtual TcxShellTreeViewReportLink(System::Classes::TComponent* AOwner) : TcxCustomTreeViewReportLink(AOwner) { }
	/* TCustomdxTreeViewReportLink.Destroy */ inline __fastcall virtual ~TcxShellTreeViewReportLink(void) { }
	
};


class DELPHICLASS TcxCustomListViewReportLink;
class PASCALIMPLEMENTATION TcxCustomListViewReportLink : public Dxpslvlnk::TCustomdxListViewReportLink
{
	typedef Dxpslvlnk::TCustomdxListViewReportLink inherited;
	
private:
	Cxlistview::TcxCustomListView* __fastcall GetcxCustomListView(void);
	
protected:
	virtual Vcl::Comctrls::TCustomListView* __fastcall GetCustomListView(void);
	__property Cxlistview::TcxCustomListView* cxCustomListView = {read=GetcxCustomListView};
public:
	/* TCustomdxNativeListViewReportLink.Create */ inline __fastcall virtual TcxCustomListViewReportLink(System::Classes::TComponent* AOwner) : Dxpslvlnk::TCustomdxListViewReportLink(AOwner) { }
	/* TCustomdxNativeListViewReportLink.Destroy */ inline __fastcall virtual ~TcxCustomListViewReportLink(void) { }
	
};


class DELPHICLASS TcxListViewReportLink;
class PASCALIMPLEMENTATION TcxListViewReportLink : public TcxCustomListViewReportLink
{
	typedef TcxCustomListViewReportLink inherited;
	
private:
	Cxlistview::TcxListView* __fastcall GetcxListView(void);
	
public:
	__property Cxlistview::TcxListView* cxListView = {read=GetcxListView};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property DrawMode = {write=SetDrawMode, default=0};
	__property Effects3D = {default=0};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property HeaderColor = {default=-16777201};
	__property Font;
	__property HeaderFont;
	__property HeaderTransparent = {default=0};
	__property GridLineColor = {default=0};
	__property IncludeHeaders = {default=1};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property OnlySelected = {default=0};
	__property Options = {default=7};
	__property RowAutoHeight = {default=0};
	__property Soft3D = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property OnCustomDrawHeader;
	__property OnCustomDrawItem;
	__property OnInitializeHeader;
	__property OnInitializeItem;
public:
	/* TCustomdxNativeListViewReportLink.Create */ inline __fastcall virtual TcxListViewReportLink(System::Classes::TComponent* AOwner) : TcxCustomListViewReportLink(AOwner) { }
	/* TCustomdxNativeListViewReportLink.Destroy */ inline __fastcall virtual ~TcxListViewReportLink(void) { }
	
};


class DELPHICLASS TcxShellListViewReportLink;
class PASCALIMPLEMENTATION TcxShellListViewReportLink : public TcxCustomListViewReportLink
{
	typedef TcxCustomListViewReportLink inherited;
	
private:
	Cxshelllistview::TcxShellListView* __fastcall GetcxShellListView(void);
	
protected:
	virtual Vcl::Comctrls::TCustomListView* __fastcall GetCustomListView(void);
	virtual void __fastcall CreateImages(void);
	virtual void __fastcall DeleteImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetLargeImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetSmallImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	virtual bool __fastcall HasStateImages(void);
	
public:
	__property Cxshelllistview::TcxShellListView* cxShellListView = {read=GetcxShellListView};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property DrawMode = {write=SetDrawMode, default=0};
	__property Effects3D = {default=0};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property HeaderColor = {default=-16777201};
	__property HeaderFont;
	__property HeaderTransparent = {default=0};
	__property GridLineColor = {default=0};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property OnlySelected = {default=0};
	__property Options = {default=7};
	__property RowAutoHeight = {default=0};
	__property IncludeHeaders = {default=1};
	__property ShowColumnHeaders = {default=1};
	__property Soft3D = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property OnCustomDrawHeader;
	__property OnCustomDrawItem;
	__property OnInitializeHeader;
	__property OnInitializeItem;
public:
	/* TCustomdxNativeListViewReportLink.Create */ inline __fastcall virtual TcxShellListViewReportLink(System::Classes::TComponent* AOwner) : TcxCustomListViewReportLink(AOwner) { }
	/* TCustomdxNativeListViewReportLink.Destroy */ inline __fastcall virtual ~TcxShellListViewReportLink(void) { }
	
};


class DELPHICLASS TcxCustomRichEditReportLink;
class PASCALIMPLEMENTATION TcxCustomRichEditReportLink : public Dxpsrelnk::TAbstractdxRichEditReportLink
{
	typedef Dxpsrelnk::TAbstractdxRichEditReportLink inherited;
	
private:
	Cxrichedit::TcxCustomRichEdit* __fastcall GetRichEdit(void);
	
protected:
	virtual NativeUInt __fastcall GetRichEditHandle(void);
	__property Cxrichedit::TcxCustomRichEdit* RichEdit = {read=GetRichEdit};
	
public:
	__fastcall virtual TcxCustomRichEditReportLink(System::Classes::TComponent* AOwner);
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TcxCustomRichEditReportLink(void) { }
	
};


class DELPHICLASS TcxRichEditReportLink;
class PASCALIMPLEMENTATION TcxRichEditReportLink : public TcxCustomRichEditReportLink
{
	typedef TcxCustomRichEditReportLink inherited;
	
private:
	HIDESBASE Cxrichedit::TcxRichEdit* __fastcall GetRichEdit(void);
	
public:
	__property Cxrichedit::TcxRichEdit* RichEdit = {read=GetRichEdit};
public:
	/* TcxCustomRichEditReportLink.Create */ inline __fastcall virtual TcxRichEditReportLink(System::Classes::TComponent* AOwner) : TcxCustomRichEditReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TcxRichEditReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxextcomctrlslnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXEXTCOMCTRLSLNK)
using namespace Dxpscxextcomctrlslnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxextcomctrlslnkHPP
