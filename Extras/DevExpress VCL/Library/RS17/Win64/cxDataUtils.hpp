// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDataUtils.pas' rev: 24.00 (Win64)

#ifndef CxdatautilsHPP
#define CxdatautilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdatautils
{
//-- type declarations -------------------------------------------------------
enum TcxDataEditValueSource : unsigned char { evsValue, evsText, evsKey };

typedef void __fastcall (__closure *TcxDataBindingNotifyEvent)(void);

class DELPHICLASS TcxCustomDataBinding;
class PASCALIMPLEMENTATION TcxCustomDataBinding : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TComponent* FDataComponent;
	System::Classes::TComponent* FOwner;
	bool FReadOnly;
	System::Classes::TComponent* FVisualControl;
	TcxDataBindingNotifyEvent FOnDataChange;
	TcxDataBindingNotifyEvent FOnDataSetChange;
	TcxDataBindingNotifyEvent FOnUpdateData;
	void __fastcall SetVisualControl(System::Classes::TComponent* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall DataChange(void);
	virtual void __fastcall DataSetChange(void);
	virtual bool __fastcall GetModified(void);
	virtual bool __fastcall GetReadOnly(void);
	virtual void __fastcall SetReadOnly(bool Value);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall VisualControlChanged(void);
	__property System::Classes::TComponent* DataComponent = {read=FDataComponent};
	
public:
	__fastcall virtual TcxCustomDataBinding(System::Classes::TComponent* AOwner, System::Classes::TComponent* ADataComponent);
	virtual bool __fastcall CanModify(void);
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual System::Variant __fastcall GetStoredValue(TcxDataEditValueSource AValueSource, bool AFocused);
	virtual bool __fastcall IsControlReadOnly(void);
	virtual bool __fastcall IsDataSourceLive(void);
	virtual bool __fastcall IsDataStorage(void);
	virtual void __fastcall Reset(void);
	virtual bool __fastcall SetEditMode(void);
	virtual void __fastcall SetStoredValue(TcxDataEditValueSource AValueSource, const System::Variant &Value);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall UpdateDataSource(void);
	__property bool Modified = {read=GetModified, nodefault};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property System::Classes::TComponent* VisualControl = {read=FVisualControl, write=SetVisualControl};
	__property TcxDataBindingNotifyEvent OnDataChange = {read=FOnDataChange, write=FOnDataChange};
	__property TcxDataBindingNotifyEvent OnDataSetChange = {read=FOnDataSetChange, write=FOnDataSetChange};
	__property TcxDataBindingNotifyEvent OnUpdateData = {read=FOnUpdateData, write=FOnUpdateData};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomDataBinding(void) { }
	
};


typedef System::TMetaClass* TcxCustomDataBindingClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall DataCompareText(const System::UnicodeString S1, const System::UnicodeString S2, bool APartialCompare);
}	/* namespace Cxdatautils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDATAUTILS)
using namespace Cxdatautils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdatautilsHPP
