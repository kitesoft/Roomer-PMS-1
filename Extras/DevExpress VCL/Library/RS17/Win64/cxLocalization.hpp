// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLocalization.pas' rev: 24.00 (Win64)

#ifndef CxlocalizationHPP
#define CxlocalizationHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <Winapi.TlHelp32.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlocalization
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxLocalizerStorageClass;

class DELPHICLASS TcxLanguage;
class PASCALIMPLEMENTATION TcxLanguage : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Classes::TStrings* FDictionary;
	unsigned FLocaleID;
	System::UnicodeString __fastcall GetName(void);
	void __fastcall SetDictionary(System::Classes::TStrings* AValue);
	
public:
	__fastcall virtual TcxLanguage(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxLanguage(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall FindTranslation(const System::UnicodeString AResStringName, /* out */ System::UnicodeString &AValue);
	void __fastcall ResetValue(const System::UnicodeString AResStringName);
	void __fastcall SetTranslation(const System::UnicodeString AResStringName, const System::UnicodeString AValue);
	__property System::UnicodeString Name = {read=GetName};
	__property System::Classes::TStrings* Dictionary = {read=FDictionary, write=SetDictionary};
	__property unsigned LocaleID = {read=FLocaleID, write=FLocaleID, nodefault};
};


class DELPHICLASS TcxLanguages;
class PASCALIMPLEMENTATION TcxLanguages : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxLanguage* operator[](int Index) { return Items[Index]; }
	
private:
	int FActiveLanguage;
	System::Classes::TStrings* FCustomResStrings;
	System::Classes::TNotifyEvent FOnLanguagesChanged;
	System::Classes::TPersistent* FOwner;
	void __fastcall SetActiveLanguage(int AValue);
	void __fastcall TranslateResString(const System::UnicodeString AResStringName, void * AResString);
	
protected:
	HIDESBASE TcxLanguage* __fastcall GetItem(int Index);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	bool __fastcall GetLocalizedString(const System::UnicodeString AResStringName, /* out */ System::UnicodeString &AValue);
	HIDESBASE void __fastcall SetItem(int Index, TcxLanguage* Value);
	void __fastcall Translate(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property int ActiveLanguage = {read=FActiveLanguage, write=SetActiveLanguage, nodefault};
	__property System::Classes::TNotifyEvent OnLanguagesChanged = {read=FOnLanguagesChanged, write=FOnLanguagesChanged};
	
public:
	__fastcall TcxLanguages(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxLanguages(void);
	HIDESBASE TcxLanguage* __fastcall Add(void);
	int __fastcall GetLanguageByName(System::UnicodeString AName);
	void __fastcall SetCustomResStringOriginalValue(const System::UnicodeString AResStringName, const System::UnicodeString AValue);
	__property System::Classes::TStrings* CustomResStrings = {read=FCustomResStrings};
	__property TcxLanguage* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


typedef void __fastcall (__closure *TcxLocalizerTranslateEvent)(const System::UnicodeString AResStringName, System::UnicodeString &AResStringValue, /* out */ bool &AHandled);

enum TcxLocalizerStorageType : unsigned char { lstResource, lstIni };

class DELPHICLASS TcxLocalizer;
class DELPHICLASS TcxLocalizerStorage;
class PASCALIMPLEMENTATION TcxLocalizer : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FActive;
	System::Sysutils::TFileName FFileName;
	TcxLanguages* FLanguages;
	bool FLoadedActive;
	System::UnicodeString FLoadedLanguage;
	TcxLocalizerStorage* FStorage;
	TcxLocalizerStorageType FStorageType;
	TcxLocalizerTranslateEvent FOnTranslate;
	NativeUInt __fastcall FindModuleWithLocalizerResources(void);
	System::UnicodeString __fastcall GetLanguage(void);
	int __fastcall GetLanguageIndex(void);
	unsigned __fastcall GetLocale(void);
	void __fastcall InternalLoadFromStream(System::Classes::TStream* AStream);
	bool __fastcall IsLanguageIndexValid(void);
	bool __fastcall IsLocaleStored(void);
	void __fastcall RecreateStorage(void);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetFileName(System::Sysutils::TFileName AValue);
	void __fastcall SetLanguage(System::UnicodeString AValue);
	void __fastcall SetLanguageIndex(int AValue);
	void __fastcall SetLocale(unsigned AValue);
	void __fastcall SetStorageType(TcxLocalizerStorageType AValue);
	
protected:
	void __fastcall Clear(void);
	bool __fastcall DoCustomTranslate(const System::UnicodeString AResStringName, /* out */ System::UnicodeString &ALocalizedValue);
	TcxLocalizerStorageClass __fastcall GetStorageClassType(void);
	void __fastcall LanguagesChanged(System::TObject* ASender);
	virtual void __fastcall Loaded(void);
	void __fastcall UpdateDependentComponents(void);
	
public:
	__fastcall virtual TcxLocalizer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxLocalizer(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall LoadFromFile(const System::Sysutils::TFileName AFileName = System::Sysutils::TFileName());
	void __fastcall LoadFromResource(unsigned AHandle);
	void __fastcall SaveToFile(const System::Sysutils::TFileName AFileName, bool AIsAnsiSaveFormat);
	void __fastcall SaveToStream(System::Classes::TStream* AStream, bool AIsAnsiSaveFormat);
	void __fastcall Translate(void);
	__property int LanguageIndex = {read=GetLanguageIndex, write=SetLanguageIndex, nodefault};
	__property System::UnicodeString Language = {read=GetLanguage, write=SetLanguage};
	__property TcxLanguages* Languages = {read=FLanguages};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property System::Sysutils::TFileName FileName = {read=FFileName, write=SetFileName};
	__property unsigned Locale = {read=GetLocale, write=SetLocale, stored=IsLocaleStored, nodefault};
	__property TcxLocalizerStorageType StorageType = {read=FStorageType, write=SetStorageType, default=1};
	__property TcxLocalizerTranslateEvent OnTranslate = {read=FOnTranslate, write=FOnTranslate};
};


class PASCALIMPLEMENTATION TcxLocalizerStorage : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Sysutils::TEncoding* __fastcall GetEndcodingFromLocaleID(int ALocaleID);
	
public:
	void __fastcall LoadFromStream(System::Classes::TStream* AStream, TcxLanguages* ALanguages);
	void __fastcall SaveToStream(System::Classes::TStream* AStream, TcxLanguages* ALanguages, bool AIsAnsiSaveFormat);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxLocalizerStorage(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxLocalizerStorage(void) : System::Classes::TPersistent() { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define ANoActiveLanguage L"English (Original translation)"
}	/* namespace Cxlocalization */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLOCALIZATION)
using namespace Cxlocalization;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlocalizationHPP
