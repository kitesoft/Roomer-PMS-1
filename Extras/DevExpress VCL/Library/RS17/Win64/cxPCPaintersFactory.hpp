// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPCPaintersFactory.pas' rev: 24.00 (Win64)

#ifndef CxpcpaintersfactoryHPP
#define CxpcpaintersfactoryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxPCConsts.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpcpaintersfactory
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPCPaintersFactory;
class PASCALIMPLEMENTATION TcxPCPaintersFactory : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FPainterClassList;
	__classmethod void __fastcall OutError(const System::UnicodeString SourceMethodName, const System::UnicodeString Msg);
	int __fastcall GetPainterClassCount(void);
	int __fastcall GetPainterStyleID(int Index);
	Cxpc::TcxPCPainterClass __fastcall InternalGetPainterClass(int Index);
	
public:
	__fastcall TcxPCPaintersFactory(void);
	__fastcall virtual ~TcxPCPaintersFactory(void);
	Cxpc::TcxPCStyleID __fastcall GetDefaultStyleID(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	Cxpc::TcxPCPainterClass __fastcall GetPainterClass(const Cxpc::TcxPCStandardStyle StandardStyle)/* overload */;
	Cxpc::TcxPCPainterClass __fastcall GetPainterClass(const Cxpc::TcxPCStyleID StyleID)/* overload */;
	Cxpc::TcxPCPainterClass __fastcall GetPainterClass(const Vcl::Controls::TCaption StyleName)/* overload */;
	Cxpc::TcxPCStyleID __fastcall GetStyleID(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	void __fastcall RegisterPCPainterClass(Cxpc::TcxPCPainterClass PCPainterClass);
	void __fastcall UnregisterPCPainterClass(Cxpc::TcxPCPainterClass PCPainterClass);
	__property int PainterClassCount = {read=GetPainterClassCount, nodefault};
	__property Cxpc::TcxPCPainterClass PainterClasses[int Index] = {read=InternalGetPainterClass};
	__property int PainterStyleIDs[int Index] = {read=GetPainterStyleID};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxPCPaintersFactory* __fastcall PaintersFactory(void);
extern PACKAGE void __fastcall RegisterPCPainterClass(Cxpc::TcxPCPainterClass PCPainterClass);
extern PACKAGE void __fastcall UnregisterPCPainterClass(Cxpc::TcxPCPainterClass PCPainterClass);
}	/* namespace Cxpcpaintersfactory */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPCPAINTERSFACTORY)
using namespace Cxpcpaintersfactory;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpcpaintersfactoryHPP
