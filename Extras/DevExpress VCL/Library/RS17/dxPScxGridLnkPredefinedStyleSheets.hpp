// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxGridLnkPredefinedStyleSheets.pas' rev: 24.00 (Win32)

#ifndef DxpscxgridlnkpredefinedstylesheetsHPP
#define DxpscxgridlnkpredefinedstylesheetsHPP

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
#include <dxPScxGridLnk.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxgridlnkpredefinedstylesheets
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxdmPScxGridLnkPredefinedStyles;
class PASCALIMPLEMENTATION TdxdmPScxGridLnkPredefinedStyles : public System::Classes::TDataModule
{
	typedef System::Classes::TDataModule inherited;
	
__published:
	Cxstyles::TcxStyleRepository* StyleRepository;
	Cxstyles::TcxStyle* styleGreenFixed;
	Cxstyles::TcxStyle* styleGreenLightContent;
	Cxstyles::TcxStyle* styleProfessionalFixed;
	Cxstyles::TcxStyle* styleGreenLightPreview;
	Dxpscxgridlnk::TdxGridReportLinkStyleSheet* ssGreen;
	Dxpscxgridlnk::TdxGridReportLinkStyleSheet* ssProfessional;
	Cxstyles::TcxStyle* styleGreenFooter;
	Cxstyles::TcxStyle* styleNoneContent;
	Cxstyles::TcxStyle* styleNoneFixed;
	Cxstyles::TcxStyle* styleProfessionalGroup;
	Cxstyles::TcxStyle* styleProfessionalContentOdd;
	Cxstyles::TcxStyle* styleProfessionalContentEven;
	Cxstyles::TcxStyle* styleProfessionalSelection;
	Cxstyles::TcxStyle* styleProfessionalPreview;
	Cxstyles::TcxStyle* styleGreenSelected;
	Cxstyles::TcxStyle* styleGreenGroup;
	Cxstyles::TcxStyle* styleProfessionalRowCaption;
	Cxstyles::TcxStyle* styleProfessionalCaptionRow;
	Dxpscxgridlnk::TdxGridReportLinkStyleSheet* ssTransparent;
	Cxstyles::TcxStyle* styleTransparentContent;
	Cxstyles::TcxStyle* styleTransparentBandHeader;
	Cxstyles::TcxStyle* styleTransparentHeader;
	Cxstyles::TcxStyle* styleTransparentFooter;
	Cxstyles::TcxStyle* styleTransparentGroup;
	Cxstyles::TcxStyle* styleTransparentPreview;
	Cxstyles::TcxStyle* styleTransparentLevelCaption;
	Cxstyles::TcxStyle* styleTransparentFilterBar;
	Cxstyles::TcxStyle* styleTransparentCaptionRow;
	Cxstyles::TcxStyle* styleTransparentRowCaption;
	Cxstyles::TcxStyle* styleTransparentContentEven;
	Cxstyles::TcxStyle* styleTransparentContentOdd;
	Cxstyles::TcxStyle* styleTransparentSelection;
public:
	/* TDataModule.Create */ inline __fastcall virtual TdxdmPScxGridLnkPredefinedStyles(System::Classes::TComponent* AOwner) : System::Classes::TDataModule(AOwner) { }
	/* TDataModule.CreateNew */ inline __fastcall virtual TdxdmPScxGridLnkPredefinedStyles(System::Classes::TComponent* AOwner, int Dummy) : System::Classes::TDataModule(AOwner, Dummy) { }
	/* TDataModule.Destroy */ inline __fastcall virtual ~TdxdmPScxGridLnkPredefinedStyles(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxgridlnkpredefinedstylesheets */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXGRIDLNKPREDEFINEDSTYLESHEETS)
using namespace Dxpscxgridlnkpredefinedstylesheets;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxgridlnkpredefinedstylesheetsHPP
