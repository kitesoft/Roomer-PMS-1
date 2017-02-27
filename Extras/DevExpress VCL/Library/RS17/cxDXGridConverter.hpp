// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDXGridConverter.pas' rev: 24.00 (Win32)

#ifndef CxdxgridconverterHPP
#define CxdxgridconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxConverterFactory.hpp>	// Pascal unit
#include <cxGridConverter.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridDBTableView.hpp>	// Pascal unit
#include <cxGridDBBandedTableView.hpp>	// Pascal unit
#include <cxGridBandedTableView.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxBlobEdit.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <cxCalc.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxCurrencyEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxHyperLinkEdit.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxDBLookupComboBox.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxMRUEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxConverterUtils.hpp>	// Pascal unit
#include <cxCustomConverter.hpp>	// Pascal unit
#include <cxPropertiesConverters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdxgridconverter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDXGridConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDXGridConverter : public Cxgridconverter::TcxCustomGridConverter
{
	typedef Cxgridconverter::TcxCustomGridConverter inherited;
	
protected:
	virtual void __fastcall DoRealImport(void);
	virtual void __fastcall DoImportStyles(void);
	virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetGridViewClass(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetSourceClassName();
public:
	/* TcxCustomGridConverter.Create */ inline __fastcall virtual TcxDXGridConverter(System::TObject* ADestination) : Cxgridconverter::TcxCustomGridConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDXGridConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDXGridLayoutConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDXGridLayoutConverter : public TcxDXGridConverter
{
	typedef TcxDXGridConverter inherited;
	
private:
	System::Classes::TComponent* FdxDBGrid;
	System::Classes::TComponent* FComponent;
	
protected:
	virtual void __fastcall DoRealImport(void);
	virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetGridViewClass(void);
	virtual void __fastcall PostImport(void);
	virtual void __fastcall PreImport(void);
	virtual bool __fastcall TestIntermediary(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetIntermediaryClassName();
	__classmethod virtual System::UnicodeString __fastcall GetSourceClassName();
public:
	/* TcxCustomGridConverter.Create */ inline __fastcall virtual TcxDXGridLayoutConverter(System::TObject* ADestination) : TcxDXGridConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDXGridLayoutConverter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdxgridconverter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDXGRIDCONVERTER)
using namespace Cxdxgridconverter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdxgridconverterHPP
