// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxStorage.pas' rev: 24.00 (Win32)

#ifndef CxstorageHPP
#define CxstorageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLibraryStrs.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxstorage
{
//-- type declarations -------------------------------------------------------
__interface IcxStoredObject;
typedef System::DelphiInterface<IcxStoredObject> _di_IcxStoredObject;
__interface  INTERFACE_UUID("{79A05009-CAC3-47E8-B454-F6F3D91F495D}") IcxStoredObject  : public System::IInterface 
{
	
public:
	virtual System::UnicodeString __fastcall GetObjectName(void) = 0 ;
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties) = 0 ;
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue) = 0 ;
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue) = 0 ;
};

__interface IcxStoredParent;
typedef System::DelphiInterface<IcxStoredParent> _di_IcxStoredParent;
__interface  INTERFACE_UUID("{6AF48CD0-3A0B-4BEC-AC88-5D323432A686}") IcxStoredParent  : public System::IInterface 
{
	
public:
	virtual System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName) = 0 ;
	virtual void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject) = 0 ;
	virtual void __fastcall GetChildren(System::Classes::TStringList* AChildren) = 0 ;
};

class DELPHICLASS EcxStorage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxStorage : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxStorage(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxStorage(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxStorage(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxStorage(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxStorage(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxStorage(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxStorage(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxStorage(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxStorage(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxStorage(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxStorage(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxStorage(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxStorage(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS EcxHexStringConvertError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxHexStringConvertError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxHexStringConvertError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxHexStringConvertError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxHexStringConvertError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxHexStringConvertError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxHexStringConvertError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxHexStringConvertError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxHexStringConvertError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxHexStringConvertError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxHexStringConvertError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxHexStringConvertError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxHexStringConvertError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxHexStringConvertError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxHexStringConvertError(void) { }
	
};

#pragma pack(pop)

enum TcxStorageMode : unsigned char { smChildrenCreating, smChildrenDeleting, smSavePublishedClassProperties };

typedef System::Set<TcxStorageMode, TcxStorageMode::smChildrenCreating, TcxStorageMode::smSavePublishedClassProperties>  TcxStorageModes;

typedef System::TMetaClass* TcxCustomReaderClass;

typedef System::TMetaClass* TcxCustomWriterClass;

typedef TcxStorageModes __fastcall (__closure *TcxGetStorageModesEvent)(void);

typedef bool __fastcall (__closure *TcxTestClassPropertyEvent)(const System::UnicodeString AName, System::TObject* AObject);

typedef System::Classes::TComponent* __fastcall (__closure *TcxGetComponentByNameEvent)(const System::UnicodeString AName);

typedef bool __fastcall (__closure *TcxGetUseInterfaceOnlyEvent)(void);

typedef void __fastcall (__closure *TcxGetStoredPropertiesEvent)(System::TObject* Sender, System::Classes::TStrings* AProperties);

typedef void __fastcall (__closure *TcxGetStoredPropertyValueEvent)(System::TObject* Sender, const System::UnicodeString AName, System::Variant &AValue);

typedef void __fastcall (__closure *TcxInitStoredObjectEvent)(System::TObject* Sender, System::TObject* AObject);

typedef void __fastcall (__closure *TcxSetStoredPropertyValueEvent)(System::TObject* Sender, const System::UnicodeString AName, const System::Variant &AValue);

enum TcxStorageType : unsigned char { stIniFile, stRegistry, stStream };

class DELPHICLASS TcxStorage;
class DELPHICLASS TcxCustomWriter;
class DELPHICLASS TcxCustomReader;
class PASCALIMPLEMENTATION TcxStorage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FNamePrefix;
	TcxStorageModes FModes;
	System::UnicodeString FObjectNamePrefix;
	bool FReCreate;
	System::UnicodeString FStorageName;
	System::Classes::TStream* FStream;
	System::TObject* FStoredObject;
	bool FSaveComponentPropertiesByName;
	bool FUseInterfaceOnly;
	TcxGetStorageModesEvent FOnGetStorageModes;
	TcxGetComponentByNameEvent FOnGetComponentByName;
	TcxTestClassPropertyEvent FOnTestClassProperty;
	TcxGetUseInterfaceOnlyEvent FOnGetUseInterfaceOnly;
	System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	void __fastcall CreateChildrenNames(System::Classes::TStringList* AChildren);
	void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	void __fastcall GetAllPublishedClassProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetAllPublishedProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetChildren(System::Classes::TStringList* AChildren);
	System::TObject* __fastcall GetClassProperty(const System::UnicodeString AName);
	System::Classes::TComponent* __fastcall GetComponentByName(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetObjectName(System::TObject* AObject);
	void __fastcall GetProperties(System::Classes::TStrings* AProperties);
	System::Variant __fastcall GetPropertyValue(const System::UnicodeString AName);
	TcxStorageModes __fastcall GetStorageModes(void);
	bool __fastcall GetUseInterfaceOnly(void);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	bool __fastcall TestClassProperty(const System::UnicodeString AName, System::TObject* AObject);
	
protected:
	void __fastcall ClearObjectData(TcxCustomWriter* AWriter);
	System::UnicodeString __fastcall GetFullObjectName(const System::UnicodeString ADefaultObjectName = System::UnicodeString());
	void __fastcall InternalCheckChildrenOrder(System::Classes::TStringList* AChildrenNames, System::Classes::TStringList* AChildrenClassNames);
	virtual void __fastcall InternalRestoreFrom(TcxCustomReader* AReader, const System::UnicodeString ADefaultObjectName = System::UnicodeString());
	virtual void __fastcall InternalStoreTo(TcxCustomWriter* AWriter, const System::UnicodeString ADefaultObjectName = System::UnicodeString());
	void __fastcall SetStoredObject(System::TObject* AObject);
	
public:
	__fastcall TcxStorage(const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream)/* overload */;
	__fastcall TcxStorage(const System::UnicodeString AStorageName)/* overload */;
	__fastcall TcxStorage(System::Classes::TStream* AStream)/* overload */;
	virtual void __fastcall RestoreFrom(System::TObject* AObject, TcxCustomReaderClass AReaderClass);
	virtual void __fastcall RestoreWithExistingReader(System::TObject* AObject, TcxCustomReader* AReader);
	void __fastcall RestoreFromIni(System::TObject* AObject);
	void __fastcall RestoreFromRegistry(System::TObject* AObject);
	void __fastcall RestoreFromStream(System::TObject* AObject);
	virtual void __fastcall StoreTo(System::TObject* AObject, TcxCustomWriterClass AWriterClass);
	virtual void __fastcall StoreWithExistingWriter(System::TObject* AObject, TcxCustomWriter* AWriter);
	void __fastcall StoreToIni(System::TObject* AObject);
	void __fastcall StoreToRegistry(System::TObject* AObject);
	void __fastcall StoreToStream(System::TObject* AObject);
	__property System::UnicodeString NamePrefix = {read=FNamePrefix, write=FNamePrefix};
	__property TcxStorageModes Modes = {read=FModes, write=FModes, nodefault};
	__property bool ReCreate = {read=FReCreate, write=FReCreate, nodefault};
	__property bool SaveComponentPropertiesByName = {read=FSaveComponentPropertiesByName, write=FSaveComponentPropertiesByName, nodefault};
	__property System::TObject* StoredObject = {read=FStoredObject};
	__property System::UnicodeString StorageName = {read=FStorageName, write=FStorageName};
	__property bool UseInterfaceOnly = {read=FUseInterfaceOnly, write=FUseInterfaceOnly, nodefault};
	__property TcxGetComponentByNameEvent OnGetComponentByName = {read=FOnGetComponentByName, write=FOnGetComponentByName};
	__property TcxGetStorageModesEvent OnGetStorageModes = {read=FOnGetStorageModes, write=FOnGetStorageModes};
	__property TcxGetUseInterfaceOnlyEvent OnGetUseInterfaceOnly = {read=FOnGetUseInterfaceOnly, write=FOnGetUseInterfaceOnly};
	__property TcxTestClassPropertyEvent OnTestClassProperty = {read=FOnTestClassProperty, write=FOnTestClassProperty};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStorage(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FStorageVersion;
	System::UnicodeString FStorageName;
	System::Classes::TStream* FStorageStream;
	
protected:
	virtual bool __fastcall CanRead(void);
	virtual void __fastcall DoSetStream(System::Classes::TStream* AStream);
	virtual void __fastcall BeginRead(void);
	virtual void __fastcall EndRead(void);
	
public:
	__fastcall virtual TcxCustomReader(const System::UnicodeString AStorageName)/* overload */;
	__fastcall virtual TcxCustomReader(const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream)/* overload */;
	virtual void __fastcall ReadProperties(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AProperties);
	virtual System::Variant __fastcall ReadProperty(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, const System::UnicodeString AName);
	virtual void __fastcall ReadChildren(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AChildrenNames, System::Classes::TStrings* AChildrenClassNames);
	void __fastcall SetStream(System::Classes::TStream* AStream);
	__property System::UnicodeString StorageName = {read=FStorageName};
	__property System::Classes::TStream* StorageStream = {read=FStorageStream};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomReader(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomWriter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool FReCreate;
	System::UnicodeString FStorageName;
	System::Classes::TStream* FStorageStream;
	virtual bool __fastcall CanWrite(void);
	virtual void __fastcall ClearObjectData(const System::UnicodeString AObjectFullName, const System::UnicodeString AClassName);
	virtual void __fastcall DoSetStream(System::Classes::TStream* AStream);
	virtual void __fastcall BeginWrite(void);
	virtual void __fastcall EndWrite(void);
	
public:
	__fastcall virtual TcxCustomWriter(const System::UnicodeString AStorageName, bool AReCreate)/* overload */;
	__fastcall virtual TcxCustomWriter(const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream, bool AReCreate)/* overload */;
	virtual void __fastcall BeginWriteObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall EndWriteObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	void __fastcall SetStream(System::Classes::TStream* AStream);
	virtual void __fastcall WriteProperty(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, const System::UnicodeString AName, const System::Variant &AValue);
	__property bool ReCreate = {read=FReCreate, write=FReCreate, nodefault};
	__property System::UnicodeString StorageName = {read=FStorageName};
	__property System::Classes::TStream* StorageStream = {read=FStorageStream};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomWriter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegistryReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegistryReader : public TcxCustomReader
{
	typedef TcxCustomReader inherited;
	
private:
	System::Win::Registry::TRegistry* FRegistry;
	
protected:
	__property System::Win::Registry::TRegistry* Registry = {read=FRegistry};
	
public:
	__fastcall virtual TcxRegistryReader(const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream)/* overload */;
	__fastcall virtual ~TcxRegistryReader(void);
	virtual void __fastcall ReadProperties(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AProperties);
	virtual System::Variant __fastcall ReadProperty(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, const System::UnicodeString AName);
	virtual void __fastcall ReadChildren(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AChildrenNames, System::Classes::TStrings* AChildrenClassNames);
public:
	/* TcxCustomReader.Create */ inline __fastcall virtual TcxRegistryReader(const System::UnicodeString AStorageName)/* overload */ : TcxCustomReader(AStorageName) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegistryWriter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegistryWriter : public TcxCustomWriter
{
	typedef TcxCustomWriter inherited;
	
private:
	System::Win::Registry::TRegistry* FRegistry;
	bool FRootKeyCreated;
	bool FRootKeyOpened;
	void __fastcall CreateRootKey(void);
	System::UnicodeString __fastcall GetKeyName(const System::UnicodeString AObjectName);
	
protected:
	virtual void __fastcall ClearObjectData(const System::UnicodeString AObjectFullName, const System::UnicodeString AClassName);
	__property System::Win::Registry::TRegistry* Registry = {read=FRegistry};
	
public:
	__fastcall virtual TcxRegistryWriter(const System::UnicodeString AStorageName, System::Classes::TStream* AStream, bool AReCreate)/* overload */;
	__fastcall virtual ~TcxRegistryWriter(void);
	virtual void __fastcall BeginWriteObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall EndWriteObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall WriteProperty(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, const System::UnicodeString AName, const System::Variant &AValue);
public:
	/* TcxCustomWriter.Create */ inline __fastcall virtual TcxRegistryWriter(const System::UnicodeString AStorageName, bool AReCreate)/* overload */ : TcxCustomWriter(AStorageName, AReCreate) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxIniFileReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxIniFileReader : public TcxCustomReader
{
	typedef TcxCustomReader inherited;
	
private:
	System::Inifiles::TMemIniFile* FIniFile;
	System::Classes::TStringList* FPathList;
	System::Classes::TStringList* FObjectNameList;
	System::Classes::TStringList* FClassNameList;
	System::UnicodeString __fastcall DecodeString(System::UnicodeString S);
	void __fastcall CreateLists(void);
	void __fastcall GetSectionDetail(const System::UnicodeString ASection, System::UnicodeString &APath, System::UnicodeString &AObjectName, System::UnicodeString &AClassName);
	
protected:
	virtual void __fastcall BeginRead(void);
	virtual bool __fastcall CanRead(void);
	__property System::Inifiles::TMemIniFile* IniFile = {read=FIniFile};
	
public:
	__fastcall virtual TcxIniFileReader(const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream)/* overload */;
	__fastcall virtual ~TcxIniFileReader(void);
	virtual void __fastcall ReadProperties(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AProperties);
	virtual System::Variant __fastcall ReadProperty(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, const System::UnicodeString AName);
	virtual void __fastcall ReadChildren(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AChildrenNames, System::Classes::TStrings* AChildrenClassNames);
public:
	/* TcxCustomReader.Create */ inline __fastcall virtual TcxIniFileReader(const System::UnicodeString AStorageName)/* overload */ : TcxCustomReader(AStorageName) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxIniFileWriter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxIniFileWriter : public TcxCustomWriter
{
	typedef TcxCustomWriter inherited;
	
private:
	System::Inifiles::TMemIniFile* FIniFile;
	System::UnicodeString __fastcall EncodeString(const System::UnicodeString S);
	
protected:
	virtual void __fastcall BeginWrite(void);
	virtual void __fastcall ClearObjectData(const System::UnicodeString AObjectFullName, const System::UnicodeString AClassName);
	virtual void __fastcall EndWrite(void);
	__property System::Inifiles::TMemIniFile* IniFile = {read=FIniFile};
	
public:
	__fastcall virtual TcxIniFileWriter(const System::UnicodeString AStorageName, System::Classes::TStream* AStream, bool AReCreate)/* overload */;
	__fastcall virtual ~TcxIniFileWriter(void);
	virtual void __fastcall BeginWriteObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall WriteProperty(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, const System::UnicodeString AName, const System::Variant &AValue);
public:
	/* TcxCustomWriter.Create */ inline __fastcall virtual TcxIniFileWriter(const System::UnicodeString AStorageName, bool AReCreate)/* overload */ : TcxCustomWriter(AStorageName, AReCreate) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStreamReader;
class DELPHICLASS TcxStreamObjectData;
class DELPHICLASS TcxStreamPropertyData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStreamReader : public TcxCustomReader
{
	typedef TcxCustomReader inherited;
	
private:
	TcxStreamObjectData* FCurrentObject;
	System::UnicodeString FCurrentObjectFullName;
	TcxStreamObjectData* FRootObject;
	System::Classes::TReader* FReader;
	TcxStreamObjectData* __fastcall GetObject(const System::UnicodeString AObjectFullName);
	TcxStreamPropertyData* __fastcall GetProperty(TcxStreamObjectData* AObject, const System::UnicodeString AName);
	TcxStreamObjectData* __fastcall InternalGetObject(const System::UnicodeString AObjectName, System::Classes::TStrings* AParents);
	
protected:
	virtual bool __fastcall CanRead(void);
	virtual void __fastcall DoSetStream(System::Classes::TStream* AStream);
	virtual void __fastcall BeginRead(void);
	
public:
	__fastcall virtual ~TcxStreamReader(void);
	void __fastcall Read(void);
	virtual void __fastcall ReadProperties(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AProperties);
	virtual System::Variant __fastcall ReadProperty(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, const System::UnicodeString AName);
	virtual void __fastcall ReadChildren(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AChildrenNames, System::Classes::TStrings* AChildrenClassNames);
public:
	/* TcxCustomReader.Create */ inline __fastcall virtual TcxStreamReader(const System::UnicodeString AStorageName)/* overload */ : TcxCustomReader(AStorageName) { }
	/* TcxCustomReader.Create */ inline __fastcall virtual TcxStreamReader(const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream)/* overload */ : TcxCustomReader(AStorageName, AStorageStream) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStreamWriter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStreamWriter : public TcxCustomWriter
{
	typedef TcxCustomWriter inherited;
	
private:
	TcxStreamObjectData* FCurrentObject;
	TcxStreamObjectData* FRootObject;
	System::Classes::TWriter* FWriter;
	void __fastcall CreateObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, System::Classes::TStrings* AParents);
	
protected:
	virtual bool __fastcall CanWrite(void);
	virtual void __fastcall DoSetStream(System::Classes::TStream* AStream);
	virtual void __fastcall EndWrite(void);
	
public:
	__fastcall virtual ~TcxStreamWriter(void);
	virtual void __fastcall BeginWriteObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	void __fastcall Write(void);
	virtual void __fastcall WriteProperty(const System::UnicodeString AObjectName, const System::UnicodeString AClassName, const System::UnicodeString AName, const System::Variant &AValue);
public:
	/* TcxCustomWriter.Create */ inline __fastcall virtual TcxStreamWriter(const System::UnicodeString AStorageName, bool AReCreate)/* overload */ : TcxCustomWriter(AStorageName, AReCreate) { }
	/* TcxCustomWriter.Create */ inline __fastcall virtual TcxStreamWriter(const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream, bool AReCreate)/* overload */ : TcxCustomWriter(AStorageName, AStorageStream, AReCreate) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxStreamPropertyData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FName;
	System::Variant FValue;
	void __fastcall ReadValue(System::Classes::TReader* AReader);
	void __fastcall WriteValue(System::Classes::TWriter* AWriter);
	
public:
	__fastcall TcxStreamPropertyData(const System::UnicodeString AName, const System::Variant &AValue);
	void __fastcall Read(System::Classes::TReader* AReader);
	void __fastcall Write(System::Classes::TWriter* AWriter);
	__property System::UnicodeString Name = {read=FName};
	__property System::Variant Value = {read=FValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStreamPropertyData(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStreamObjectData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FClassName;
	System::Classes::TList* FChildren;
	System::UnicodeString FName;
	System::Classes::TList* FProperties;
	void __fastcall Clear(void);
	int __fastcall GetChildCount(void);
	TcxStreamObjectData* __fastcall GetChildren(int AIndex);
	TcxStreamPropertyData* __fastcall GetProperties(int AIndex);
	int __fastcall GetPropertyCount(void);
	
public:
	__fastcall TcxStreamObjectData(const System::UnicodeString AName, const System::UnicodeString AClassName);
	__fastcall virtual ~TcxStreamObjectData(void);
	void __fastcall AddChild(TcxStreamObjectData* AChild);
	void __fastcall AddProperty(TcxStreamPropertyData* AProperty);
	void __fastcall Read(System::Classes::TReader* AReader);
	void __fastcall Write(System::Classes::TWriter* AWriter);
	__property int ChildCount = {read=GetChildCount, nodefault};
	__property TcxStreamObjectData* Children[int AIndex] = {read=GetChildren};
	__property System::UnicodeString Name = {read=FName};
	__property System::UnicodeString ClassName_ = {read=FClassName};
	__property TcxStreamPropertyData* Properties[int AIndex] = {read=GetProperties};
	__property int PropertyCount = {read=GetPropertyCount, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int cxBufferSize;
static const System::Int8 cxStreamBoolean = System::Int8(0x1);
static const System::Int8 cxStreamChar = System::Int8(0x2);
static const System::Int8 cxStreamCurrency = System::Int8(0x3);
static const System::Int8 cxStreamDate = System::Int8(0x4);
static const System::Int8 cxStreamFloat = System::Int8(0x5);
static const System::Int8 cxStreamInteger = System::Int8(0x6);
static const System::Int8 cxStreamSingle = System::Int8(0x7);
static const System::Int8 cxStreamString = System::Int8(0x8);
static const System::Int8 cxStreamWideString = System::Int8(0x9);
extern PACKAGE System::UnicodeString __fastcall cxQuotedStr(const System::UnicodeString S, System::WideChar AQuote = (System::WideChar)(0x22));
extern PACKAGE System::UnicodeString __fastcall cxDequotedStr(const System::UnicodeString S);
extern PACKAGE bool __fastcall cxIsQuotedStr(const System::UnicodeString S, System::WideChar AQuote = (System::WideChar)(0x22));
extern PACKAGE System::AnsiString __fastcall StreamToString(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall StringToStream(System::AnsiString AValue, System::Classes::TStream* AStream);
extern PACKAGE System::AnsiString __fastcall StringToHexString(const System::AnsiString ABuffer);
extern PACKAGE System::AnsiString __fastcall HexStringToString(const System::AnsiString AHexString);
extern PACKAGE bool __fastcall StringToBoolean(const System::UnicodeString AString);
extern PACKAGE System::UnicodeString __fastcall EnumerationToString(const int AValue, System::UnicodeString const *AEnumNames, const int AEnumNames_Size);
extern PACKAGE int __fastcall StringToEnumeration(const System::UnicodeString AValue, System::UnicodeString const *AEnumNames, const int AEnumNames_Size);
extern PACKAGE System::UnicodeString __fastcall SetToString(const void *ASet, int ASize, System::UnicodeString const *AEnumNames, const int AEnumNames_Size);
extern PACKAGE void __fastcall StringToSet(System::UnicodeString AString, void *ASet, int ASize, System::UnicodeString const *AEnumNames, const int AEnumNames_Size);
}	/* namespace Cxstorage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSTORAGE)
using namespace Cxstorage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxstorageHPP
