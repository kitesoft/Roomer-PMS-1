// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridDBCardView.pas' rev: 24.00 (Win32)

#ifndef CxgriddbcardviewHPP
#define CxgriddbcardviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridCardView.hpp>	// Pascal unit
#include <cxGridDBDataDefinitions.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGridCustomLayoutView.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriddbcardview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridDBCardViewRow;
class PASCALIMPLEMENTATION TcxGridDBCardViewRow : public Cxgridcardview::TcxGridCardViewRow
{
	typedef Cxgridcardview::TcxGridCardViewRow inherited;
	
private:
	Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* Value);
	
__published:
	__property Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxGridCardViewRow.Create */ inline __fastcall virtual TcxGridDBCardViewRow(System::Classes::TComponent* AOwner) : Cxgridcardview::TcxGridCardViewRow(AOwner) { }
	/* TcxGridCardViewRow.Destroy */ inline __fastcall virtual ~TcxGridDBCardViewRow(void) { }
	
};


class DELPHICLASS TcxGridDBCardView;
class PASCALIMPLEMENTATION TcxGridDBCardView : public Cxgridcardview::TcxGridCardView
{
	typedef Cxgridcardview::TcxGridCardView inherited;
	
private:
	HIDESBASE Cxgriddbdatadefinitions::TcxGridDBDataController* __fastcall GetDataController(void);
	HIDESBASE TcxGridDBCardViewRow* __fastcall GetRow(int Index);
	HIDESBASE void __fastcall SetDataController(Cxgriddbdatadefinitions::TcxGridDBDataController* Value);
	HIDESBASE void __fastcall SetRow(int Index, TcxGridDBCardViewRow* Value);
	
protected:
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	
public:
	HIDESBASE TcxGridDBCardViewRow* __fastcall CreateRow(void);
	TcxGridDBCardViewRow* __fastcall GetRowByFieldName(const System::UnicodeString AFieldName);
	__property TcxGridDBCardViewRow* Rows[int Index] = {read=GetRow, write=SetRow};
	
__published:
	__property Cxgriddbdatadefinitions::TcxGridDBDataController* DataController = {read=GetDataController, write=SetDataController};
public:
	/* TcxCustomGridTableView.Destroy */ inline __fastcall virtual ~TcxGridDBCardView(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridDBCardView(Cxcontrols::TcxControl* AControl) : Cxgridcardview::TcxGridCardView(AControl) { }
	
public:
	/* TcxControlChildComponent.Create */ inline __fastcall virtual TcxGridDBCardView(System::Classes::TComponent* AOwner) : Cxgridcardview::TcxGridCardView(AOwner) { }
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridDBCardView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridcardview::TcxGridCardView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriddbcardview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDDBCARDVIEW)
using namespace Cxgriddbcardview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriddbcardviewHPP
