// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellEditRepositoryItems.pas' rev: 24.00 (Win64)

#ifndef CxshelleditrepositoryitemsHPP
#define CxshelleditrepositoryitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxShellComboBox.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxshelleditrepositoryitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxEditRepositoryShellComboBoxItem;
class PASCALIMPLEMENTATION TcxEditRepositoryShellComboBoxItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxshellcombobox::TcxShellComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxshellcombobox::TcxShellComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxshellcombobox::TcxShellComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryShellComboBoxItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryShellComboBoxItem(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxshelleditrepositoryitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLEDITREPOSITORYITEMS)
using namespace Cxshelleditrepositoryitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshelleditrepositoryitemsHPP
