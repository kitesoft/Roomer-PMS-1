// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutcxEditAdapters.pas' rev: 24.00 (Win64)

#ifndef DxlayoutcxeditadaptersHPP
#define DxlayoutcxeditadaptersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutcxeditadapters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxLayoutcxEditAdapter;
class PASCALIMPLEMENTATION TdxLayoutcxEditAdapter : public Dxlayoutcontainer::TdxCustomLayoutControlAdapter
{
	typedef Dxlayoutcontainer::TdxCustomLayoutControlAdapter inherited;
	
private:
	HIDESBASE Cxedit::TcxCustomEdit* __fastcall GetControl(void);
	Cxedit::TcxCustomEditStyle* __fastcall GetControlStyle(void);
	
protected:
	virtual void __fastcall Init(void);
	virtual void __fastcall InternalSetInitialSettings(void);
	bool __fastcall IsDefaultSkinAssigned(void);
	__property Cxedit::TcxCustomEdit* Control = {read=GetControl};
	__property Cxedit::TcxCustomEditStyle* ControlStyle = {read=GetControlStyle};
	
public:
	__fastcall virtual TdxLayoutcxEditAdapter(Dxlayoutcontainer::TdxLayoutItem* AItem);
	__fastcall virtual ~TdxLayoutcxEditAdapter(void);
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxlayoutcxeditadapters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTCXEDITADAPTERS)
using namespace Dxlayoutcxeditadapters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutcxeditadaptersHPP
