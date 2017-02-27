// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDataStorage.pas' rev: 24.00 (Win64)

#ifndef CxdatastorageHPP
#define CxdatastorageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.FmtBcd.hpp>	// Pascal unit
#include <Data.SqlTimSt.hpp>	// Pascal unit
#include <System.AnsiStrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdatastorage
{
//-- type declarations -------------------------------------------------------
typedef __int64 LargeInt;

typedef __int64 *PLargeInt;

typedef System::PUnicodeString PStringValue;

typedef System::PWideString PWideStringValue;

class DELPHICLASS TcxValueType;
class PASCALIMPLEMENTATION TcxValueType : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual void __fastcall FreeTextBuffer(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDefaultDisplayText(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDisplayText(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall ReadDisplayText(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall SetDisplayText(char * ABuffer, const System::UnicodeString DisplayText);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall WriteDisplayText(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Caption();
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsValueValid(System::Variant &Value);
	__classmethod virtual bool __fastcall IsString();
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxValueType(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxValueType(void) { }
	
};


typedef System::TMetaClass* TcxValueTypeClass;

class DELPHICLASS TcxStringValueType;
class PASCALIMPLEMENTATION TcxStringValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsString();
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxStringValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStringValueType(void) { }
	
};


class DELPHICLASS TcxWideStringValueType;
class PASCALIMPLEMENTATION TcxWideStringValueType : public TcxStringValueType
{
	typedef TcxStringValueType inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsString();
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxWideStringValueType(void) : TcxStringValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWideStringValueType(void) { }
	
};


class DELPHICLASS TcxSmallintValueType;
class PASCALIMPLEMENTATION TcxSmallintValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxSmallintValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSmallintValueType(void) { }
	
};


class DELPHICLASS TcxIntegerValueType;
class PASCALIMPLEMENTATION TcxIntegerValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxIntegerValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxIntegerValueType(void) { }
	
};


class DELPHICLASS TcxWordValueType;
class PASCALIMPLEMENTATION TcxWordValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxWordValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWordValueType(void) { }
	
};


class DELPHICLASS TcxBooleanValueType;
class PASCALIMPLEMENTATION TcxBooleanValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDefaultDisplayText(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxBooleanValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBooleanValueType(void) { }
	
};


class DELPHICLASS TcxSingleValueType;
class PASCALIMPLEMENTATION TcxSingleValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxSingleValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSingleValueType(void) { }
	
};


class DELPHICLASS TcxFloatValueType;
class PASCALIMPLEMENTATION TcxFloatValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxFloatValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFloatValueType(void) { }
	
};


class DELPHICLASS TcxCurrencyValueType;
class PASCALIMPLEMENTATION TcxCurrencyValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxCurrencyValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCurrencyValueType(void) { }
	
};


class DELPHICLASS TcxDateTimeValueType;
class PASCALIMPLEMENTATION TcxDateTimeValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
private:
	__classmethod System::TDateTime __fastcall GetDateTime(char * ABuffer);
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDefaultDisplayText(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxDateTimeValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDateTimeValueType(void) { }
	
};


class DELPHICLASS TcxLargeIntValueType;
class PASCALIMPLEMENTATION TcxLargeIntValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxLargeIntValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxLargeIntValueType(void) { }
	
};


class DELPHICLASS TcxFMTBcdValueType;
class PASCALIMPLEMENTATION TcxFMTBcdValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual System::UnicodeString __fastcall GetDefaultDisplayText(char * ABuffer);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxFMTBcdValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFMTBcdValueType(void) { }
	
};


class DELPHICLASS TcxSQLTimeStampValueType;
class PASCALIMPLEMENTATION TcxSQLTimeStampValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual int __fastcall GetVarType();
public:
	/* TObject.Create */ inline __fastcall TcxSQLTimeStampValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSQLTimeStampValueType(void) { }
	
};


class DELPHICLASS TcxVariantValueType;
class PASCALIMPLEMENTATION TcxVariantValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxVariantValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVariantValueType(void) { }
	
};


class DELPHICLASS TcxBLOBValueType;
class PASCALIMPLEMENTATION TcxBLOBValueType : public TcxValueType
{
	typedef TcxValueType inherited;
	
protected:
	__classmethod virtual int __fastcall Compare(void * P1, void * P2);
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod System::AnsiString __fastcall GetAnsiString(char * ABuffer);
	__classmethod virtual int __fastcall GetDataSize();
	__classmethod virtual System::Variant __fastcall GetDataValue(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__classmethod virtual int __fastcall CompareValues(void * P1, void * P2);
	__classmethod virtual System::Variant __fastcall GetValue(char * ABuffer);
	__classmethod virtual int __fastcall GetVarType();
	__classmethod virtual bool __fastcall IsString();
	__classmethod virtual void __fastcall PrepareValueBuffer(char * &ABuffer);
public:
	/* TObject.Create */ inline __fastcall TcxBLOBValueType(void) : TcxValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBLOBValueType(void) { }
	
};


class DELPHICLASS TcxObjectValueType;
class PASCALIMPLEMENTATION TcxObjectValueType : public TcxLargeIntValueType
{
	typedef TcxLargeIntValueType inherited;
	
protected:
	__classmethod virtual void __fastcall FreeBuffer(char * ABuffer);
	__classmethod virtual void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	__classmethod virtual void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	__classmethod virtual void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
public:
	/* TObject.Create */ inline __fastcall TcxObjectValueType(void) : TcxLargeIntValueType() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxObjectValueType(void) { }
	
};


class DELPHICLASS TcxValueDef;
class DELPHICLASS TcxValueDefs;
class PASCALIMPLEMENTATION TcxValueDef : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FBufferSize;
	int FDataOffset;
	int FDataSize;
	int FDisplayTextOffset;
	bool FStored;
	System::TObject* FLinkObject;
	int FOffset;
	bool FStreamStored;
	bool FTextStored;
	TcxValueDefs* FValueDefs;
	TcxValueTypeClass FValueTypeClass;
	bool __fastcall GetIsNeedConversion(void);
	bool __fastcall GetTextStored(void);
	void __fastcall SetStored(bool Value);
	void __fastcall SetTextStored(bool Value);
	void __fastcall SetValueTypeClass(TcxValueTypeClass Value);
	
protected:
	void __fastcall Changed(bool AResyncNeeded);
	int __fastcall Compare(char * P1, char * P2);
	void __fastcall FreeBuffer(char * ABuffer);
	void __fastcall FreeTextBuffer(char * ABuffer);
	char * __fastcall GetDataFromBuffer(char * ABuffer);
	System::Variant __fastcall GetDataValue(char * ABuffer);
	System::UnicodeString __fastcall GetDisplayText(char * ABuffer);
	char * __fastcall GetDisplayTextFromBuffer(char * ABuffer);
	virtual System::TObject* __fastcall GetLinkObject(void);
	virtual bool __fastcall GetStored(void);
	void __fastcall Init(int &AOffset);
	bool __fastcall IsNullValue(char * ABuffer);
	bool __fastcall IsNullValueEx(char * ABuffer);
	void __fastcall ReadDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	void __fastcall ReadDisplayText(char * ABuffer, Dxcore::TdxStream* AStream);
	void __fastcall SetDataValue(char * ABuffer, const System::Variant &Value);
	void __fastcall SetDisplayText(char * ABuffer, const System::UnicodeString DisplayText);
	virtual void __fastcall SetLinkObject(System::TObject* Value);
	void __fastcall SetNull(char * ABuffer, bool AIsNull);
	void __fastcall WriteDataValue(char * ABuffer, Dxcore::TdxStream* AStream);
	void __fastcall WriteDisplayText(char * ABuffer, Dxcore::TdxStream* AStream);
	
public:
	__fastcall virtual TcxValueDef(TcxValueDefs* AValueDefs, TcxValueTypeClass AValueTypeClass);
	__fastcall virtual ~TcxValueDef(void);
	virtual void __fastcall Assign(TcxValueDef* ASource);
	int __fastcall CompareValues(bool AIsNull1, bool AIsNull2, char * P1, char * P2);
	__property int BufferSize = {read=FBufferSize, nodefault};
	__property int DataSize = {read=FDataSize, nodefault};
	__property bool IsNeedConversion = {read=GetIsNeedConversion, nodefault};
	__property System::TObject* LinkObject = {read=GetLinkObject, write=SetLinkObject};
	__property int Offset = {read=FOffset, nodefault};
	__property bool Stored = {read=GetStored, write=SetStored, default=1};
	__property bool StreamStored = {read=FStreamStored, write=FStreamStored, default=1};
	__property bool TextStored = {read=GetTextStored, write=SetTextStored, default=0};
	__property TcxValueDefs* ValueDefs = {read=FValueDefs};
	__property TcxValueTypeClass ValueTypeClass = {read=FValueTypeClass, write=SetValueTypeClass};
};


typedef System::TMetaClass* TcxValueDefClass;

class DELPHICLASS TcxDataStorage;
class PASCALIMPLEMENTATION TcxValueDefs : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxValueDef* operator[](int Index) { return Items[Index]; }
	
private:
	TcxDataStorage* FDataStorage;
	System::Classes::TList* FItems;
	int FRecordOffset;
	int FRecordSize;
	int __fastcall GetStoredCount(void);
	int __fastcall GetCount(void);
	TcxValueDef* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall Changed(TcxValueDef* AValueDef, bool AResyncNeeded);
	virtual TcxValueDefClass __fastcall GetValueDefClass(void);
	virtual void __fastcall Prepare(int AStartOffset);
	void __fastcall Remove(TcxValueDef* AItem);
	__property TcxDataStorage* DataStorage = {read=FDataStorage};
	
public:
	__fastcall virtual TcxValueDefs(TcxDataStorage* ADataStorage);
	__fastcall virtual ~TcxValueDefs(void);
	TcxValueDef* __fastcall Add(TcxValueTypeClass AValueTypeClass, bool AStored, bool ATextStored, System::TObject* ALinkObject);
	void __fastcall Clear(void);
	__property int StoredCount = {read=GetStoredCount, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TcxValueDef* Items[int Index] = {read=GetItem/*, default*/};
	__property int RecordSize = {read=FRecordSize, nodefault};
};


class DELPHICLASS TcxInternalValueDef;
class PASCALIMPLEMENTATION TcxInternalValueDef : public TcxValueDef
{
	typedef TcxValueDef inherited;
	
protected:
	virtual System::TObject* __fastcall GetLinkObject(void);
	virtual bool __fastcall GetStored(void);
	
public:
	TcxValueDef* __fastcall GetValueDef(void);
public:
	/* TcxValueDef.Create */ inline __fastcall virtual TcxInternalValueDef(TcxValueDefs* AValueDefs, TcxValueTypeClass AValueTypeClass) : TcxValueDef(AValueDefs, AValueTypeClass) { }
	/* TcxValueDef.Destroy */ inline __fastcall virtual ~TcxInternalValueDef(void) { }
	
};


class DELPHICLASS TcxInternalValueDefs;
class PASCALIMPLEMENTATION TcxInternalValueDefs : public TcxValueDefs
{
	typedef TcxValueDefs inherited;
	
protected:
	virtual TcxValueDefClass __fastcall GetValueDefClass(void);
	
public:
	TcxValueDef* __fastcall FindByLinkObject(System::TObject* ALinkObject);
	void __fastcall RemoveByLinkObject(System::TObject* ALinkObject);
public:
	/* TcxValueDefs.Create */ inline __fastcall virtual TcxInternalValueDefs(TcxDataStorage* ADataStorage) : TcxValueDefs(ADataStorage) { }
	/* TcxValueDefs.Destroy */ inline __fastcall virtual ~TcxInternalValueDefs(void) { }
	
};


class DELPHICLASS TcxValueDefReader;
class PASCALIMPLEMENTATION TcxValueDefReader : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__fastcall virtual TcxValueDefReader(void);
	virtual System::UnicodeString __fastcall GetDisplayText(TcxValueDef* AValueDef);
	virtual System::Variant __fastcall GetValue(TcxValueDef* AValueDef);
	virtual bool __fastcall IsInternal(TcxValueDef* AValueDef);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxValueDefReader(void) { }
	
};


typedef System::TMetaClass* TcxValueDefReaderClass;

typedef void __fastcall (__closure *TcxValueDefSetProc)(TcxValueDef* AValueDef, int AFromRecordIndex, int AToRecordIndex, TcxValueDefReader* AValueDefReader);

class PASCALIMPLEMENTATION TcxDataStorage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FDestroying;
	System::Classes::TList* FInternalRecordBuffers;
	TcxInternalValueDefs* FInternalValueDefs;
	bool FStoredValuesOnly;
	System::Classes::TList* FRecordBuffers;
	int FRecordIDCounter;
	bool FUseRecordID;
	TcxValueDefs* FValueDefs;
	System::Classes::TList* FValueDefsList;
	System::Classes::TNotifyEvent FOnClearInternalRecords;
	char * __fastcall GetRecordBuffer(int Index);
	int __fastcall GetRecordCount(void);
	void __fastcall SetStoredValuesOnly(bool Value);
	void __fastcall SetRecordBuffer(int Index, char * Value);
	void __fastcall SetRecordCount(int Value);
	void __fastcall SetUseRecordID(bool Value);
	
protected:
	char * __fastcall AllocRecordBuffer(int Index);
	int __fastcall CalcRecordOffset(void);
	void __fastcall ChangeRecordFlag(char * ABuffer, System::Byte AFlag, bool ATurnOn);
	void __fastcall CheckRecordID(int ARecordIndex);
	void __fastcall CheckRecordIDCounter(void);
	void __fastcall CheckRecordIDCounterAfterLoad(int ALoadedID);
	bool __fastcall CheckValueDef(int ARecordIndex, TcxValueDef* &AValueDef);
	void __fastcall DeleteInternalRecord(int ARecordIndex);
	void __fastcall FreeAndNilRecordBuffer(int AIndex);
	virtual void __fastcall InitStructure(TcxValueDefs* AValueDefs);
	void __fastcall InsertValueDef(int AIndex, TcxValueDef* AValueDef);
	bool __fastcall IsRecordFlag(char * ABuffer, System::Byte AFlag);
	void __fastcall RemoveValueDef(TcxValueDef* AValueDef);
	virtual void __fastcall ValueDefsChanged(TcxValueDef* AValueDef, bool AResyncNeeded);
	virtual TcxValueDefs* __fastcall ValueDefsByRecordIndex(int Index);
	__property TcxInternalValueDefs* InternalValueDefs = {read=FInternalValueDefs};
	
public:
	__fastcall virtual TcxDataStorage(void);
	__fastcall virtual ~TcxDataStorage(void);
	int __fastcall AddInternalRecord(void);
	int __fastcall AppendRecord(void);
	virtual void __fastcall BeforeDestruction(void);
	void __fastcall BeginLoad(void);
	void __fastcall CheckStructure(void);
	void __fastcall Clear(bool AWithoutInternal);
	void __fastcall ClearInternalRecords(void);
	void __fastcall ClearRecords(bool AClearList);
	int __fastcall CompareRecords(int ARecordIndex1, int ARecordIndex2, TcxValueDef* AValueDef);
	void __fastcall DeleteRecord(int ARecordIndex);
	void __fastcall EndLoad(void);
	System::UnicodeString __fastcall GetDisplayText(int ARecordIndex, TcxValueDef* AValueDef);
	bool __fastcall GetCompareInfo(int ARecordIndex, TcxValueDef* AValueDef, char * &P);
	int __fastcall GetRecordID(int ARecordIndex);
	System::Variant __fastcall GetValue(int ARecordIndex, TcxValueDef* AValueDef);
	void __fastcall InsertRecord(int ARecordIndex);
	void __fastcall ReadData(int ARecordIndex, System::Classes::TStream* AStream);
	void __fastcall ReadRecord(int ARecordIndex, TcxValueDefReader* AValueDefReader);
	void __fastcall ReadRecordFrom(int AFromRecordIndex, int AToRecordIndex, TcxValueDefReader* AValueDefReader, TcxValueDefSetProc ASetProc);
	void __fastcall SetDisplayText(int ARecordIndex, TcxValueDef* AValueDef, const System::UnicodeString Value);
	void __fastcall SetRecordID(int ARecordIndex, int AID);
	void __fastcall SetValue(int ARecordIndex, TcxValueDef* AValueDef, const System::Variant &Value);
	void __fastcall WriteData(int ARecordIndex, System::Classes::TStream* AStream);
	void __fastcall BeginStreaming(System::Classes::TListSortCompare ACompare);
	void __fastcall EndStreaming(void);
	__property bool StoredValuesOnly = {read=FStoredValuesOnly, write=SetStoredValuesOnly, nodefault};
	__property bool UseRecordID = {read=FUseRecordID, write=SetUseRecordID, nodefault};
	__property char * RecordBuffers[int Index] = {read=GetRecordBuffer, write=SetRecordBuffer};
	__property int RecordCount = {read=GetRecordCount, write=SetRecordCount, nodefault};
	__property TcxValueDefs* ValueDefs = {read=FValueDefs};
	__property System::Classes::TNotifyEvent OnClearInternalRecords = {read=FOnClearInternalRecords, write=FOnClearInternalRecords};
};


class DELPHICLASS TcxDataStorageHelper;
class PASCALIMPLEMENTATION TcxDataStorageHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void * __fastcall AllocateRecord(TcxDataStorage* ADataStorage);
	__classmethod int __fastcall AppendRecord(TcxDataStorage* ADataStorage, void * ARecord);
	__classmethod int __fastcall Compare(TcxValueDef* AValueDef, void * ARecord1, void * ARecord2);
	__classmethod void __fastcall FreeBuffer(TcxValueDef* AValueDef, void * ARecord);
	__classmethod System::UnicodeString __fastcall GetDisplayText(TcxValueDef* AValueDef, void * ARecord);
	__classmethod int __fastcall GetRecordSize(TcxDataStorage* ADataStorage);
	__classmethod int __fastcall GetStoredCount(TcxDataStorage* ADataStorage);
	__classmethod System::Variant __fastcall GetValue(TcxValueDef* AValueDef, void * ARecord);
	__classmethod void * __fastcall RemoveRecord(TcxDataStorage* ADataStorage, int ARecordIndex);
	__classmethod void __fastcall SetDisplayText(void * ARecord, TcxValueDef* AValueDef, const System::UnicodeString AValue);
	__classmethod void __fastcall SetRecordsCapacity(TcxDataStorage* ADataStorage, int ACapacity);
	__classmethod void __fastcall SetTextStored(TcxValueDef* AValueDef, bool ATextStored);
	__classmethod void __fastcall SetValue(void * ARecord, TcxValueDef* AValueDef, const System::Variant &AValue);
	__classmethod void __fastcall FreeRecord(TcxDataStorage* ADataStorage, void * &ARecord);
public:
	/* TObject.Create */ inline __fastcall TcxDataStorageHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataStorageHelper(void) { }
	
};


struct DECLSPEC_DRECORD TcxLookupListItem
{
public:
	System::Variant KeyValue;
	System::UnicodeString DisplayText;
};


typedef TcxLookupListItem *PcxLookupListItem;

class DELPHICLASS TcxLookupList;
class PASCALIMPLEMENTATION TcxLookupList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	PcxLookupListItem operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	PcxLookupListItem __fastcall GetItem(int Index);
	
public:
	__fastcall TcxLookupList(void);
	__fastcall virtual ~TcxLookupList(void);
	void __fastcall Clear(void);
	bool __fastcall Find(const System::Variant &AKeyValue, int &AIndex);
	void __fastcall Insert(int AIndex, const System::Variant &AKeyValue, const System::UnicodeString ADisplayText);
	__property int Count = {read=GetCount, nodefault};
	__property PcxLookupListItem Items[int Index] = {read=GetItem/*, default*/};
};


class DELPHICLASS TcxValueTypeClassList;
class PASCALIMPLEMENTATION TcxValueTypeClassList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxValueTypeClass operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxValueTypeClass __fastcall GetItem(int Index);
	
public:
	__fastcall TcxValueTypeClassList(void);
	__fastcall virtual ~TcxValueTypeClassList(void);
	TcxValueTypeClass __fastcall ItemByCaption(const System::UnicodeString ACaption);
	void __fastcall RegisterItem(TcxValueTypeClass AValueTypeClass);
	void __fastcall UnregisterItem(TcxValueTypeClass AValueTypeClass);
	__property int Count = {read=GetCount, nodefault};
	__property TcxValueTypeClass Items[int Index] = {read=GetItem/*, default*/};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxValueTypeClassList* __fastcall cxValueTypeClassList(void);
extern PACKAGE bool __fastcall IsDateTimeValueTypeClass(TcxValueTypeClass AValueTypeClass);
}	/* namespace Cxdatastorage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDATASTORAGE)
using namespace Cxdatastorage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdatastorageHPP
