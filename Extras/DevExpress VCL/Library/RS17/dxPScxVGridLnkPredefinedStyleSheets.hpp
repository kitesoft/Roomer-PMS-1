// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxVGridLnkPredefinedStyleSheets.pas' rev: 24.00 (Win32)

#ifndef DxpscxvgridlnkpredefinedstylesheetsHPP
#define DxpscxvgridlnkpredefinedstylesheetsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <dxPScxVGridLnk.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxvgridlnkpredefinedstylesheets
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxdmPScxVGridLnkPredefinedStyles;
class PASCALIMPLEMENTATION TcxdmPScxVGridLnkPredefinedStyles : public System::Classes::TDataModule
{
	typedef System::Classes::TDataModule inherited;
	
__published:
	Cxstyles::TcxStyleRepository* StyleRepository;
	Cxstyles::TcxStyle* styleGrayCategory;
	Cxstyles::TcxStyle* styleProfessionalCategory;
	Cxstyles::TcxStyle* styleGrayHeader;
	Cxstyles::TcxStyle* styleProfessionalHeader;
	Cxstyles::TcxStyle* styleNoneContent;
	Dxpscxvgridlnk::TcxVerticalGridReportLinkStyleSheet* ssProfessional;
	Dxpscxvgridlnk::TcxVerticalGridReportLinkStyleSheet* ssGray;
	Dxpscxvgridlnk::TcxVerticalGridReportLinkStyleSheet* ssTransparent;
	Cxstyles::TcxStyle* styleTransparentCategory;
	Cxstyles::TcxStyle* styleTransparentHeader;
	Cxstyles::TcxStyle* styleTransparentContent;
public:
	/* TDataModule.Create */ inline __fastcall virtual TcxdmPScxVGridLnkPredefinedStyles(System::Classes::TComponent* AOwner) : System::Classes::TDataModule(AOwner) { }
	/* TDataModule.CreateNew */ inline __fastcall virtual TcxdmPScxVGridLnkPredefinedStyles(System::Classes::TComponent* AOwner, int Dummy) : System::Classes::TDataModule(AOwner, Dummy) { }
	/* TDataModule.Destroy */ inline __fastcall virtual ~TcxdmPScxVGridLnkPredefinedStyles(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxvgridlnkpredefinedstylesheets */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXVGRIDLNKPREDEFINEDSTYLESHEETS)
using namespace Dxpscxvgridlnkpredefinedstylesheets;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxvgridlnkpredefinedstylesheetsHPP
