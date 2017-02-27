// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridStyleSheetsPreview.pas' rev: 24.00 (Win64)

#ifndef CxpivotgridstylesheetspreviewHPP
#define CxpivotgridstylesheetspreviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxStyleSheetEditor.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxPivotGrid.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridstylesheetspreview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPivotGridStyleSheetEditorPreview;
class PASCALIMPLEMENTATION TcxPivotGridStyleSheetEditorPreview : public Cxstylesheeteditor::TcxStyleSheetEditorPreview
{
	typedef Cxstylesheeteditor::TcxStyleSheetEditorPreview inherited;
	
private:
	Cxpivotgrid::TcxPivotGrid* FPivotGrid;
	
protected:
	virtual void __fastcall CreatePreviewData(void);
	__property Cxpivotgrid::TcxPivotGrid* PivotGrid = {read=FPivotGrid};
	
public:
	__fastcall virtual TcxPivotGridStyleSheetEditorPreview(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxPivotGridStyleSheetEditorPreview(void);
	__classmethod virtual Cxstyles::TcxCustomStyleSheetClass __fastcall GetStyleSheetClass();
	virtual void __fastcall SetStyleSheet(Cxstyles::TcxCustomStyleSheet* AStyleSheet);
	virtual Vcl::Controls::TWinControl* __fastcall Control(void);
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpivotgridstylesheetspreview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDSTYLESHEETSPREVIEW)
using namespace Cxpivotgridstylesheetspreview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridstylesheetspreviewHPP
