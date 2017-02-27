// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBEditRepository.pas' rev: 24.00 (Win32)

#ifndef CxdbeditrepositoryHPP
#define CxdbeditrepositoryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBLookupComboBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbeditrepository
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxEditRepositoryLookupComboBoxItem;
class PASCALIMPLEMENTATION TcxEditRepositoryLookupComboBoxItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxdblookupcombobox::TcxLookupComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxdblookupcombobox::TcxLookupComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxdblookupcombobox::TcxLookupComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryLookupComboBoxItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryLookupComboBoxItem(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbeditrepository */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBEDITREPOSITORY)
using namespace Cxdbeditrepository;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbeditrepositoryHPP
