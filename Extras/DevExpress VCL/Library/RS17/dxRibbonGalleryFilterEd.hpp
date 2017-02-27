// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonGalleryFilterEd.pas' rev: 24.00 (Win32)

#ifndef DxribbongalleryfilteredHPP
#define DxribbongalleryfilteredHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.CheckLst.hpp>	// Pascal unit
#include <dxRibbonGallery.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbongalleryfiltered
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmGalleryFilterGroups;
class PASCALIMPLEMENTATION TfmGalleryFilterGroups : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Checklst::TCheckListBox* clbGroups;
	Vcl::Stdctrls::TGroupBox* GroupBox1;
	Vcl::Stdctrls::TButton* btnOk;
	Vcl::Stdctrls::TButton* btnCancel;
	
public:
	void __fastcall Init(Dxribbongallery::TdxRibbonGalleryFilterCategory* AFilterCategory);
	void __fastcall Apply(Dxribbongallery::TdxRibbonGalleryFilterCategory* AFilterCategory);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmGalleryFilterGroups(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmGalleryFilterGroups(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmGalleryFilterGroups(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmGalleryFilterGroups(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxribbongalleryfiltered */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONGALLERYFILTERED)
using namespace Dxribbongalleryfiltered;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbongalleryfilteredHPP
