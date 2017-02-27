// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDockConsts.pas' rev: 24.00 (Win64)

#ifndef DxdockconstsHPP
#define DxdockconstsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdockconsts
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxDefaultImageHeight = System::Int8(0x10);
static const System::Int8 dxDefaultImageWidth = System::Int8(0x10);
static const System::Int8 dxDockZonesWidth = System::Int8(0x14);
static const System::Int8 dxResizeZonesWidth = System::Int8(0x3);
static const System::Int8 dxSelectionFrameWidth = System::Int8(0x4);
static const System::Word dxAutoHideInterval = System::Word(0x1f4);
static const System::Int8 dxAutoHideMovingInterval = System::Int8(0x1);
static const System::Int8 dxAutoHideMovingSize = System::Int8(0x14);
static const System::Word dxAutoShowInterval = System::Word(0x12c);
static const System::Word dxTabsScrollInterval = System::Word(0x12c);
extern PACKAGE System::ResourceString _sdxInvalidLayoutSiteDeleting;
#define Dxdockconsts_sdxInvalidLayoutSiteDeleting System::LoadResourceString(&Dxdockconsts::_sdxInvalidLayoutSiteDeleting)
extern PACKAGE System::ResourceString _sdxInvalidFloatSiteDeleting;
#define Dxdockconsts_sdxInvalidFloatSiteDeleting System::LoadResourceString(&Dxdockconsts::_sdxInvalidFloatSiteDeleting)
extern PACKAGE System::ResourceString _sdxInvalidFloatingDeleting;
#define Dxdockconsts_sdxInvalidFloatingDeleting System::LoadResourceString(&Dxdockconsts::_sdxInvalidFloatingDeleting)
extern PACKAGE System::ResourceString _sdxInvalidParentAssigning;
#define Dxdockconsts_sdxInvalidParentAssigning System::LoadResourceString(&Dxdockconsts::_sdxInvalidParentAssigning)
extern PACKAGE System::ResourceString _sdxInvalidOwner;
#define Dxdockconsts_sdxInvalidOwner System::LoadResourceString(&Dxdockconsts::_sdxInvalidOwner)
extern PACKAGE System::ResourceString _sdxInvalidParent;
#define Dxdockconsts_sdxInvalidParent System::LoadResourceString(&Dxdockconsts::_sdxInvalidParent)
extern PACKAGE System::ResourceString _sdxInvalidDockSiteParent;
#define Dxdockconsts_sdxInvalidDockSiteParent System::LoadResourceString(&Dxdockconsts::_sdxInvalidDockSiteParent)
extern PACKAGE System::ResourceString _sdxInvalidFloatSiteParent;
#define Dxdockconsts_sdxInvalidFloatSiteParent System::LoadResourceString(&Dxdockconsts::_sdxInvalidFloatSiteParent)
extern PACKAGE System::ResourceString _sdxInvalidPanelChild;
#define Dxdockconsts_sdxInvalidPanelChild System::LoadResourceString(&Dxdockconsts::_sdxInvalidPanelChild)
extern PACKAGE System::ResourceString _sdxInvalidSiteChild;
#define Dxdockconsts_sdxInvalidSiteChild System::LoadResourceString(&Dxdockconsts::_sdxInvalidSiteChild)
extern PACKAGE System::ResourceString _sdxInvaldZoneOwner;
#define Dxdockconsts_sdxInvaldZoneOwner System::LoadResourceString(&Dxdockconsts::_sdxInvaldZoneOwner)
extern PACKAGE System::ResourceString _sdxInternalErrorAutoHide;
#define Dxdockconsts_sdxInternalErrorAutoHide System::LoadResourceString(&Dxdockconsts::_sdxInternalErrorAutoHide)
extern PACKAGE System::ResourceString _sdxInternalErrorPainter;
#define Dxdockconsts_sdxInternalErrorPainter System::LoadResourceString(&Dxdockconsts::_sdxInternalErrorPainter)
extern PACKAGE System::ResourceString _sdxInternalErrorLayout;
#define Dxdockconsts_sdxInternalErrorLayout System::LoadResourceString(&Dxdockconsts::_sdxInternalErrorLayout)
extern PACKAGE System::ResourceString _sdxInternalErrorCreateLayout;
#define Dxdockconsts_sdxInternalErrorCreateLayout System::LoadResourceString(&Dxdockconsts::_sdxInternalErrorCreateLayout)
extern PACKAGE System::ResourceString _sdxInternalErrorDestroyLayout;
#define Dxdockconsts_sdxInternalErrorDestroyLayout System::LoadResourceString(&Dxdockconsts::_sdxInternalErrorDestroyLayout)
extern PACKAGE System::ResourceString _sdxManagerError;
#define Dxdockconsts_sdxManagerError System::LoadResourceString(&Dxdockconsts::_sdxManagerError)
extern PACKAGE System::ResourceString _sdxAncestorError;
#define Dxdockconsts_sdxAncestorError System::LoadResourceString(&Dxdockconsts::_sdxAncestorError)
#define sdxManagerOwnerError L"Redundant TdxDockingManager component declaration found.\r"\
	L"\nYou can safely remove the TdxDockingManager component fr"\
	L"om \"%s\" (%s) because only TCustomForm descendants can be"\
	L" effective owners of TdxDockingManager components."
}	/* namespace Dxdockconsts */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCKCONSTS)
using namespace Dxdockconsts;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdockconstsHPP
