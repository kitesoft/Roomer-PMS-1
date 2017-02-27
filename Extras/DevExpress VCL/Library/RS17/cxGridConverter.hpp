// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridConverter.pas' rev: 24.00 (Win32)

#ifndef CxgridconverterHPP
#define CxgridconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxConverterFactory.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridDBBandedTableView.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGridStrs.hpp>	// Pascal unit
#include <cxGridStructureNavigator.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxCustomConverter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridconverter
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxCustomGridConverterClass;

class DELPHICLASS TcxCustomGridConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridConverter : public Cxconverterfactory::TcxCustomConverterWithStyles
{
	typedef Cxconverterfactory::TcxCustomConverterWithStyles inherited;
	
private:
	bool FDeleteAllSublevels;
	Cxgridlevel::TcxGridLevel* FDestinationLevel;
	System::Classes::TComponent* FIntermediary;
	void __fastcall ClearAllSublevels(Cxgridlevel::TcxGridLevel* ALevel);
	void __fastcall ClearGrid(void);
	void __fastcall ClearSublevels(Cxgridlevel::TcxGridLevel* ALevel);
	void __fastcall ClearViewItems(Cxgridcustomview::TcxCustomGridView* AView);
	Cxgrid::TcxCustomGrid* __fastcall GetDestination(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetDestinationLevel(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetcxGridView(void);
	System::Classes::TComponent* __fastcall GetSource(void);
	void __fastcall SetIntermediary(System::Classes::TComponent* AIntermediary);
	void __fastcall SetSource(System::Classes::TComponent* ASource);
	
protected:
	virtual bool __fastcall CanConvert(void);
	void __fastcall DeleteComponent(System::Classes::TComponent* AComponent);
	virtual void __fastcall DoImport(void);
	virtual void __fastcall DoRealImport(void);
	virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetGridViewClass(void);
	virtual bool __fastcall TestIntermediary(void);
	System::UnicodeString __fastcall UniqueColumnName(System::Classes::TComponent* AColumn, const System::UnicodeString AFieldName = System::UnicodeString());
	__property Cxgridcustomview::TcxCustomGridView* cxGridView = {read=GetcxGridView};
	
public:
	__fastcall virtual TcxCustomGridConverter(System::TObject* ADestination);
	__classmethod virtual System::UnicodeString __fastcall GetIntermediaryClassName();
	__property bool DeleteAllSublevels = {read=FDeleteAllSublevels, write=FDeleteAllSublevels, nodefault};
	__property Cxgrid::TcxCustomGrid* Destination = {read=GetDestination};
	__property Cxgridlevel::TcxGridLevel* DestinationLevel = {read=FDestinationLevel, write=FDestinationLevel};
	__property System::Classes::TComponent* Intermediary = {read=FIntermediary, write=SetIntermediary};
	__property System::Classes::TComponent* Source = {read=GetSource, write=SetSource};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridConverter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define cxGridGroupConverterName L"Grid Converters"
}	/* namespace Cxgridconverter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDCONVERTER)
using namespace Cxgridconverter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridconverterHPP
