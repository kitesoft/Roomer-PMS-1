// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxConverterFactory.pas' rev: 24.00 (Win32)

#ifndef CxconverterfactoryHPP
#define CxconverterfactoryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLibraryStrs.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxCustomConverter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxconverterfactory
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxCustomConverterWithStylesClass;

class DELPHICLASS TcxCustomConverterWithStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomConverterWithStyles : public Cxcustomconverter::TcxCustomConverter
{
	typedef Cxcustomconverter::TcxCustomConverter inherited;
	
private:
	bool FConvertWithStyles;
	Designintf::_di_IDesigner FDesigner;
	System::UnicodeString FNameOfNewStyleRepository;
	Cxstyles::TcxStyleRepository* FStyleRepository;
	Cxstyles::TcxStyleRepository* __fastcall GetStyleRepository(void);
	
protected:
	Cxstyles::TcxCustomStyle* __fastcall CreateStyleItem(void);
	virtual void __fastcall DoImport(void);
	virtual void __fastcall DoImportStyles(void);
	
public:
	__property bool ConvertWithStyles = {read=FConvertWithStyles, write=FConvertWithStyles, nodefault};
	__property Designintf::_di_IDesigner Designer_ = {read=FDesigner, write=FDesigner};
	__property System::UnicodeString NameOfNewStyleRepository = {read=FNameOfNewStyleRepository, write=FNameOfNewStyleRepository};
	__property Cxstyles::TcxStyleRepository* StyleRepository = {read=GetStyleRepository, write=FStyleRepository};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxCustomConverterWithStyles(System::TObject* ADestination) : Cxcustomconverter::TcxCustomConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomConverterWithStyles(void) { }
	
};

#pragma pack(pop)

struct TcxConverterFactoryItem;
typedef TcxConverterFactoryItem *PcxConverterFactoryItem;

struct DECLSPEC_DRECORD TcxConverterFactoryItem
{
public:
	TcxCustomConverterWithStylesClass Class_;
	System::UnicodeString Name;
};


class DELPHICLASS TcxConverterFactory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxConverterFactory : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxConverterFactoryItem operator[](int AIndex) { return Items[AIndex]; }
	
private:
	System::Classes::TList* FItems;
	
protected:
	__fastcall TcxConverterFactory(int AParam);
	
private:
	int __fastcall GetCount(void);
	TcxConverterFactoryItem __fastcall GetItems(int AIndex);
	int __fastcall IndexOf(TcxCustomConverterWithStylesClass AClass);
	
public:
	__fastcall TcxConverterFactory(void);
	__fastcall virtual ~TcxConverterFactory(void);
	TcxCustomConverterWithStylesClass __fastcall FindConverter(System::TObject* ASource);
	__classmethod TcxConverterFactory* __fastcall Instance(System::UnicodeString AConverterGroupName);
	void __fastcall RegisterConverter(const System::UnicodeString AName, const TcxCustomConverterWithStylesClass AClass);
	void __fastcall UnregisterConverter(const TcxCustomConverterWithStylesClass AClass);
	__property int Count = {read=GetCount, nodefault};
	__property TcxConverterFactoryItem Items[int AIndex] = {read=GetItems/*, default*/};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxConverterFactory* __fastcall ConverterFactory(System::UnicodeString AConverterGroupName);
}	/* namespace Cxconverterfactory */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCONVERTERFACTORY)
using namespace Cxconverterfactory;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxconverterfactoryHPP
