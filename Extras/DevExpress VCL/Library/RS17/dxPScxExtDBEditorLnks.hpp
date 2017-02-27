// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxExtDBEditorLnks.pas' rev: 24.00 (Win32)

#ifndef DxpscxextdbeditorlnksHPP
#define DxpscxextdbeditorlnksHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxDBCheckListBox.hpp>	// Pascal unit
#include <cxDBRichEdit.hpp>	// Pascal unit
#include <dxPScxCheckListBoxLnk.hpp>	// Pascal unit
#include <dxPScxExtComCtrlsLnk.hpp>	// Pascal unit
#include <dxPSGrLnks.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxPSRELnk.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxextdbeditorlnks
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBCheckListBoxReportLink;
class PASCALIMPLEMENTATION TcxDBCheckListBoxReportLink : public Dxpscxchecklistboxlnk::TcxCustomCheckListBoxReportLink
{
	typedef Dxpscxchecklistboxlnk::TcxCustomCheckListBoxReportLink inherited;
	
private:
	Cxdbchecklistbox::TcxDBCheckListBox* __fastcall GetcxDBCheckListBox(void);
	
public:
	__property Cxdbchecklistbox::TcxDBCheckListBox* cxDBCheckListBox = {read=GetcxDBCheckListBox};
	
__published:
	__property Color = {default=16777215};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property Multiline = {default=0};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property Options = {default=7};
	__property RowAutoHeight = {default=0};
	__property ScaleFonts = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property Width;
	__property OnCustomDrawItem;
	__property OnInitializeItem;
public:
	/* TdxCustomListBoxReportLink.Create */ inline __fastcall virtual TcxDBCheckListBoxReportLink(System::Classes::TComponent* AOwner) : Dxpscxchecklistboxlnk::TcxCustomCheckListBoxReportLink(AOwner) { }
	/* TdxCustomListBoxReportLink.Destroy */ inline __fastcall virtual ~TcxDBCheckListBoxReportLink(void) { }
	
};


class DELPHICLASS TcxDBRichEditReportLink;
class PASCALIMPLEMENTATION TcxDBRichEditReportLink : public Dxpscxextcomctrlslnk::TcxCustomRichEditReportLink
{
	typedef Dxpscxextcomctrlslnk::TcxCustomRichEditReportLink inherited;
	
private:
	HIDESBASE Cxdbrichedit::TcxDBRichEdit* __fastcall GetRichEdit(void);
	
public:
	__property Cxdbrichedit::TcxDBRichEdit* RichEdit = {read=GetRichEdit};
public:
	/* TcxCustomRichEditReportLink.Create */ inline __fastcall virtual TcxDBRichEditReportLink(System::Classes::TComponent* AOwner) : Dxpscxextcomctrlslnk::TcxCustomRichEditReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TcxDBRichEditReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxextdbeditorlnks */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXEXTDBEDITORLNKS)
using namespace Dxpscxextdbeditorlnks;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxextdbeditorlnksHPP
