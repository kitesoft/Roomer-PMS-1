// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFilterControlUtils.pas' rev: 24.00 (Win64)

#ifndef CxfiltercontrolutilsHPP
#define CxfiltercontrolutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxfiltercontrolutils
{
//-- type declarations -------------------------------------------------------
enum TcxFilterControlOperator : unsigned char { fcoNone, fcoEqual, fcoNotEqual, fcoLess, fcoLessEqual, fcoGreater, fcoGreaterEqual, fcoLike, fcoNotLike, fcoBlanks, fcoNonBlanks, fcoBetween, fcoNotBetween, fcoInList, fcoNotInList, fcoYesterday, fcoToday, fcoTomorrow, fcoLast7Days, fcoLastWeek, fcoLast14Days, fcoLastTwoWeeks, fcoLast30Days, fcoLastMonth, fcoLastYear, fcoInPast, fcoThisWeek, fcoThisMonth, fcoThisYear, fcoNext7Days, fcoNextWeek, fcoNext14Days, fcoNextTwoWeeks, fcoNext30Days, fcoNextMonth, fcoNextYear, fcoInFuture };

typedef System::Set<TcxFilterControlOperator, TcxFilterControlOperator::fcoNone, TcxFilterControlOperator::fcoInFuture>  TcxFilterControlOperators;

class DELPHICLASS EcxFilterControlError;
class PASCALIMPLEMENTATION EcxFilterControlError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxFilterControlError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxFilterControlError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxFilterControlError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxFilterControlError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxFilterControlError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxFilterControlError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxFilterControlError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxFilterControlError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxFilterControlError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxFilterControlError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxFilterControlError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxFilterControlError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxFilterControlError(void) { }
	
};


class DELPHICLASS TcxCustomFilterEditHelper;
class PASCALIMPLEMENTATION TcxCustomFilterEditHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall ClearPropertiesEvents(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual void __fastcall InitializeEdit(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties);
	__classmethod virtual bool __fastcall IsIDefaultValuesProviderNeeded(Cxedit::TcxCustomEditProperties* AEditProperties);
	
public:
	__classmethod virtual bool __fastcall EditPropertiesHasButtons();
	__classmethod Cxedit::TcxCustomEdit* __fastcall GetFilterEdit(Cxedit::TcxCustomEditProperties* AEditProperties, Cxedit::TcxInplaceEditList* AInplaceEditList = (Cxedit::TcxInplaceEditList*)(0x0));
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual void __fastcall GetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &V, Vcl::Controls::TCaption &S);
	__classmethod virtual TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
	__classmethod virtual bool __fastcall IsValueValid(Cxdatastorage::TcxValueTypeClass AValueTypeClass, System::Variant &AValue);
	__classmethod virtual void __fastcall SetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &AValue);
	__classmethod virtual bool __fastcall UseDisplayValue();
public:
	/* TObject.Create */ inline __fastcall TcxCustomFilterEditHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomFilterEditHelper(void) { }
	
};


typedef System::TMetaClass* TcxCustomFilterEditHelperClass;

class DELPHICLASS TcxFilterEditsController;
class PASCALIMPLEMENTATION TcxFilterEditsController : public Cxclasses::TcxRegisteredClassList
{
	typedef Cxclasses::TcxRegisteredClassList inherited;
	
private:
	System::TClass __fastcall GetItemClass(System::TClass AItemClass);
	
public:
	TcxCustomFilterEditHelperClass __fastcall FindHelper(System::TClass APropertiesClass);
	virtual void __fastcall Register(System::TClass AItemClass, System::TClass ARegisteredClass);
	virtual void __fastcall Unregister(System::TClass AItemClass, System::TClass ARegisteredClass);
public:
	/* TcxRegisteredClassList.Create */ inline __fastcall TcxFilterEditsController(void) : Cxclasses::TcxRegisteredClassList() { }
	/* TcxRegisteredClassList.Destroy */ inline __fastcall virtual ~TcxFilterEditsController(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxfilter::TcxFilterOperatorKind __fastcall GetFilterOperatorKind(TcxFilterControlOperator AOperator);
extern PACKAGE TcxFilterControlOperator __fastcall GetFilterControlOperator(Cxfilter::TcxFilterOperatorKind AOperatorKind, bool AIsNull);
extern PACKAGE void __fastcall CorrectDlgParams(Vcl::Controls::TCreateParams &Params);
extern PACKAGE void __fastcall FilterControlError(const System::UnicodeString Msg);
extern PACKAGE void __fastcall FilterControlValidateValue(Cxedit::TcxCustomEdit* AEdit, System::Variant &AValue, TcxFilterControlOperator AOperator, Cxdatastorage::TcxValueTypeClass AValueTypeClass, TcxCustomFilterEditHelperClass AFilterEditHelper);
extern PACKAGE TcxFilterEditsController* __fastcall FilterEditsController(void);
extern PACKAGE System::UnicodeString __fastcall GetFilterControlOperatorText(TcxFilterControlOperator AOperator);
}	/* namespace Cxfiltercontrolutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFILTERCONTROLUTILS)
using namespace Cxfiltercontrolutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxfiltercontrolutilsHPP
