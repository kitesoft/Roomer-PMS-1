// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxTLLnkPredefinedStyleSheets.pas' rev: 24.00 (Win32)

#ifndef DxpscxtllnkpredefinedstylesheetsHPP
#define DxpscxtllnkpredefinedstylesheetsHPP

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
#include <dxPScxTLLnk.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxtllnkpredefinedstylesheets
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxdmPScxTreeListLnkPredefinedStyles;
class PASCALIMPLEMENTATION TdxdmPScxTreeListLnkPredefinedStyles : public System::Classes::TDataModule
{
	typedef System::Classes::TDataModule inherited;
	
__published:
	Cxstyles::TcxStyleRepository* StyleRepository;
	Cxstyles::TcxStyle* styleProfessionalFixed;
	Cxstyles::TcxStyle* styleProfessionalGroup;
	Cxstyles::TcxStyle* styleProfessionalRowCaption;
	Cxstyles::TcxStyle* styleProfessionalCaptionRow;
	Cxstyles::TcxStyle* styleProfessionalContentOdd;
	Cxstyles::TcxStyle* styleProfessionalContentEven;
	Cxstyles::TcxStyle* styleProfessionalPreview;
	Cxstyles::TcxStyle* styleProfessionalSelection;
	Cxstyles::TcxStyle* styleGreenFixed;
	Cxstyles::TcxStyle* styleGreenFooter;
	Cxstyles::TcxStyle* styleGreenLightContent;
	Cxstyles::TcxStyle* styleGreenLightPreview;
	Cxstyles::TcxStyle* styleGreenSelected;
	Cxstyles::TcxStyle* styleGreenGroup;
	Cxstyles::TcxStyle* styleNoneContent;
	Cxstyles::TcxStyle* styleNoneFixed;
	Dxpscxtllnk::TcxTreeListReportLinkStyleSheet* ssProfessional;
	Dxpscxtllnk::TcxTreeListReportLinkStyleSheet* ssGreen;
	Dxpscxtllnk::TcxTreeListReportLinkStyleSheet* ssTransparent;
	Cxstyles::TcxStyle* styleTransparentBandHeader;
	Cxstyles::TcxStyle* styleTransparentContent;
	Cxstyles::TcxStyle* styleTransparentContentEven;
	Cxstyles::TcxStyle* styleTransparentContentOdd;
	Cxstyles::TcxStyle* styleTransparentFooter;
	Cxstyles::TcxStyle* styleTransparentFooterRow;
	Cxstyles::TcxStyle* styleTransparentHeader;
	Cxstyles::TcxStyle* styleTransparentPreview;
	Cxstyles::TcxStyle* styleTransparentSelection;
public:
	/* TDataModule.Create */ inline __fastcall virtual TdxdmPScxTreeListLnkPredefinedStyles(System::Classes::TComponent* AOwner) : System::Classes::TDataModule(AOwner) { }
	/* TDataModule.CreateNew */ inline __fastcall virtual TdxdmPScxTreeListLnkPredefinedStyles(System::Classes::TComponent* AOwner, int Dummy) : System::Classes::TDataModule(AOwner, Dummy) { }
	/* TDataModule.Destroy */ inline __fastcall virtual ~TdxdmPScxTreeListLnkPredefinedStyles(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxtllnkpredefinedstylesheets */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXTLLNKPREDEFINEDSTYLESHEETS)
using namespace Dxpscxtllnkpredefinedstylesheets;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxtllnkpredefinedstylesheetsHPP
