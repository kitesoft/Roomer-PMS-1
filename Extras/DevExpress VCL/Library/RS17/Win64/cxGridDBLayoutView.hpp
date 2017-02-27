// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridDBLayoutView.pas' rev: 24.00 (Win64)

#ifndef CxgriddblayoutviewHPP
#define CxgriddblayoutviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridLayoutView.hpp>	// Pascal unit
#include <cxGridDBDataDefinitions.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriddblayoutview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridDBLayoutViewItem;
class PASCALIMPLEMENTATION TcxGridDBLayoutViewItem : public Cxgridlayoutview::TcxGridLayoutViewItem
{
	typedef Cxgridlayoutview::TcxGridLayoutViewItem inherited;
	
private:
	Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* Value);
	
__published:
	__property Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxGridLayoutViewItem.Destroy */ inline __fastcall virtual ~TcxGridDBLayoutViewItem(void) { }
	
public:
	/* TcxCustomGridTableItem.Create */ inline __fastcall virtual TcxGridDBLayoutViewItem(System::Classes::TComponent* AOwner) : Cxgridlayoutview::TcxGridLayoutViewItem(AOwner) { }
	
};


class DELPHICLASS TcxGridDBLayoutView;
class PASCALIMPLEMENTATION TcxGridDBLayoutView : public Cxgridlayoutview::TcxGridLayoutView
{
	typedef Cxgridlayoutview::TcxGridLayoutView inherited;
	
private:
	HIDESBASE Cxgriddbdatadefinitions::TcxGridDBDataController* __fastcall GetDataController(void);
	HIDESBASE TcxGridDBLayoutViewItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetDataController(Cxgriddbdatadefinitions::TcxGridDBDataController* Value);
	HIDESBASE void __fastcall SetItem(int Index, TcxGridDBLayoutViewItem* Value);
	
protected:
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	
public:
	HIDESBASE TcxGridDBLayoutViewItem* __fastcall CreateItem(void);
	TcxGridDBLayoutViewItem* __fastcall GetItemByFieldName(const System::UnicodeString AFieldName);
	__property TcxGridDBLayoutViewItem* Items[int Index] = {read=GetItem, write=SetItem};
	
__published:
	__property Cxgriddbdatadefinitions::TcxGridDBDataController* DataController = {read=GetDataController, write=SetDataController};
public:
	/* TcxGridLayoutView.Create */ inline __fastcall virtual TcxGridDBLayoutView(System::Classes::TComponent* AOwner) : Cxgridlayoutview::TcxGridLayoutView(AOwner) { }
	/* TcxGridLayoutView.CreateEx */ inline __fastcall virtual TcxGridDBLayoutView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridlayoutview::TcxGridLayoutView(AControl, AAssignOwner) { }
	/* TcxGridLayoutView.Destroy */ inline __fastcall virtual ~TcxGridDBLayoutView(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridDBLayoutView(Cxcontrols::TcxControl* AControl) : Cxgridlayoutview::TcxGridLayoutView(AControl) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriddblayoutview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDDBLAYOUTVIEW)
using namespace Cxgriddblayoutview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriddblayoutviewHPP
