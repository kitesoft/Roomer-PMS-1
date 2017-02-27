// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridFilterHelpers.pas' rev: 24.00 (Win64)

#ifndef CxgridfilterhelpersHPP
#define CxgridfilterhelpersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridfilterhelpers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxFilterExtLookupComboBoxHelper;
class PASCALIMPLEMENTATION TcxFilterExtLookupComboBoxHelper : public Cxdropdownedit::TcxFilterComboBoxHelper
{
	typedef Cxdropdownedit::TcxFilterComboBoxHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual void __fastcall GetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &V, Vcl::Controls::TCaption &S);
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
	__classmethod virtual bool __fastcall IsValueValid(Cxdatastorage::TcxValueTypeClass AValueTypeClass, System::Variant &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxFilterExtLookupComboBoxHelper(void) : Cxdropdownedit::TcxFilterComboBoxHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterExtLookupComboBoxHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridfilterhelpers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDFILTERHELPERS)
using namespace Cxgridfilterhelpers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridfilterhelpersHPP
