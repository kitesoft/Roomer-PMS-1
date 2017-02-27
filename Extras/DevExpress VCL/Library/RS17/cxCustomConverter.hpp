// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCustomConverter.pas' rev: 24.00 (Win32)

#ifndef CxcustomconverterHPP
#define CxcustomconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcustomconverter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxUnknownProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxUnknownProperty : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxUnknownProperty(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxUnknownProperty(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxUnknownProperty(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxUnknownProperty(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxUnknownProperty(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxUnknownProperty(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxUnknownProperty(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxUnknownProperty(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxUnknownProperty(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxUnknownProperty(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxUnknownProperty(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxUnknownProperty(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxUnknownProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS EcxConverterError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxConverterError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxConverterError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxConverterError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxConverterError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxConverterError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxConverterError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxConverterError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxConverterError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxConverterError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxConverterError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxConverterError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxConverterError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxConverterError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxConverterError(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomConverterClass;

class DELPHICLASS TcxCustomConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomConverter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::TObject* FDestination;
	bool FPropertyExceptionEnabled;
	System::TObject* FSource;
	System::TObject* __fastcall GetObject(System::TObject* AObject);
	System::Typinfo::PPropInfo __fastcall GetPropInfo_(System::TObject* AObject, const System::UnicodeString AName);
	bool __fastcall TestProperty(System::TObject* AObject, const System::UnicodeString AName, System::Typinfo::TTypeKind ATypeKind);
	
protected:
	virtual bool __fastcall CanConvert(void);
	void __fastcall DisablePropertyException(void);
	virtual void __fastcall DoImport(void);
	void __fastcall EnablePropertyException(void);
	bool __fastcall GetBooleanProperty(System::TObject* AObject, const System::UnicodeString AName, const bool ADefaultValue = false);
	System::WideChar __fastcall GetCharProperty(System::TObject* AObject, const System::UnicodeString AName, const System::WideChar ADefaultValue = (System::WideChar)(0x0));
	System::TObject* __fastcall GetClassProperty(System::TObject* AObject, const System::UnicodeString AName, System::TObject* const ADefaultValue = (System::TObject*)(0x0));
	System::UnicodeString __fastcall GetEnumProperty(System::TObject* AObject, const System::UnicodeString AName, const System::UnicodeString ADefaultValue = System::UnicodeString());
	System::Extended __fastcall GetFloatProperty(System::TObject* AObject, const System::UnicodeString AName, const System::Extended ADefaultValue = 0.000000E+00);
	int __fastcall GetIntegerProperty(System::TObject* AObject, const System::UnicodeString AName, const int ADefaultValue = 0x0);
	System::_di_IInterface __fastcall GetInterfaceProperty(System::TObject* AObject, const System::UnicodeString AName, const System::_di_IInterface ADefaultValue);
	System::TMethod __fastcall GetMethodProperty(System::TObject* AObject, const System::UnicodeString AName, const System::TMethod &ADefaultValue);
	void __fastcall GetSetProperty(System::TObject* AObject, const System::UnicodeString AName, System::Classes::TStrings* AValues);
	System::UnicodeString __fastcall GetStringProperty(System::TObject* AObject, const System::UnicodeString AName, const System::UnicodeString ADefaultValue = System::UnicodeString());
	System::Variant __fastcall GetVariantProperty(System::TObject* AObject, const System::UnicodeString AName, const System::Variant &ADefaultValue);
	System::WideChar __fastcall GetWideCharProperty(System::TObject* AObject, const System::UnicodeString AName, const System::WideChar ADefaultValue = (System::WideChar)(0x0));
	System::WideString __fastcall GetWideStringProperty(System::TObject* AObject, const System::UnicodeString AName, const System::WideString ADefaultValue = System::WideString());
	virtual void __fastcall PostImport(void);
	virtual void __fastcall PreImport(void);
	
public:
	__fastcall virtual TcxCustomConverter(System::TObject* ADestination);
	__classmethod virtual System::UnicodeString __fastcall GetSourceClassName();
	void __fastcall ImportFrom(System::TObject* ASource);
	__property System::TObject* Destination = {read=FDestination};
	__property System::TObject* Source = {read=FSource, write=FSource};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomConverter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxcustomconverter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCUSTOMCONVERTER)
using namespace Cxcustomconverter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcustomconverterHPP
