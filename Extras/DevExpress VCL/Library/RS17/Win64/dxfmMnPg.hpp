// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxfmMnPg.pas' rev: 24.00 (Win64)

#ifndef DxfmmnpgHPP
#define DxfmmnpgHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfmmnpg
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxChooseMultiplePages(Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, System::Types::TPoint AOrigin, int AYShift, int AMaxColCount, int AMaxRowCount, int &AColCount, int &ARowCount);
}	/* namespace Dxfmmnpg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFMMNPG)
using namespace Dxfmmnpg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfmmnpgHPP
