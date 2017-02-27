// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBGridConverter.pas' rev: 24.00 (Win32)

#ifndef CxdbgridconverterHPP
#define CxdbgridconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxConverterFactory.hpp>	// Pascal unit
#include <cxGridConverter.hpp>	// Pascal unit
#include <cxConverterUtils.hpp>	// Pascal unit
#include <cxGridDBTableView.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxDBLookupComboBox.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxCustomConverter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbgridconverter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBGridConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBGridConverter : public Cxgridconverter::TcxCustomGridConverter
{
	typedef Cxgridconverter::TcxCustomGridConverter inherited;
	
private:
	int FColor;
	int FFixedColor;
	Vcl::Graphics::TFont* FFont;
	Vcl::Graphics::TFont* FTitleFont;
	Cxgriddbtableview::TcxGridDBColumn* __fastcall FindcxColumn(const System::UnicodeString AFieldName);
	HIDESBASE Cxgriddbtableview::TcxGridDBTableView* __fastcall GetcxGridView(void);
	System::UnicodeString __fastcall GetFieldName(System::Classes::TCollectionItem* AColumn);
	void __fastcall ImportColumns(void);
	void __fastcall ImportColumnsStyles(void);
	void __fastcall ImportGrid(void);
	void __fastcall ImportGridStyles(void);
	
protected:
	virtual void __fastcall DoRealImport(void);
	virtual void __fastcall DoImportStyles(void);
	virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetGridViewClass(void);
	__property Cxgriddbtableview::TcxGridDBTableView* cxGridView = {read=GetcxGridView};
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetSourceClassName();
public:
	/* TcxCustomGridConverter.Create */ inline __fastcall virtual TcxDBGridConverter(System::TObject* ADestination) : Cxgridconverter::TcxCustomGridConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDBGridConverter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbgridconverter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBGRIDCONVERTER)
using namespace Cxdbgridconverter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbgridconverterHPP
