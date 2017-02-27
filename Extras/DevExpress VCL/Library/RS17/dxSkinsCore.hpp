// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsCore.pas' rev: 24.00 (Win32)

#ifndef DxskinscoreHPP
#define DxskinscoreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxSkinsStrs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <dxOffice11.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinscore
{
//-- type declarations -------------------------------------------------------
typedef double TdxSkinVersion;

typedef System::StaticArray<char, 6> TdxSkinSignature;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxSkinHeader
{
public:
	int Reserved;
	TdxSkinSignature Signature;
	double Version;
};
#pragma pack(pop)


typedef System::StaticArray<System::UnicodeString, 2> Dxskinscore__1;

typedef System::TMetaClass* TdxSkinControlGroupClass;

typedef System::TMetaClass* TdxSkinCustomObjectClass;

typedef System::TMetaClass* TdxSkinElementClass;

typedef System::TMetaClass* TdxSkinPersistentClass;

typedef System::TMetaClass* TdxSkinPropertyClass;

enum TdxSkinGradientMode : unsigned char { gmHorizontal, gmVertical, gmForwardDiagonal, gmBackwardDiagonal };

enum TdxSkinIconSize : unsigned char { sis16, sis48 };

enum TdxSkinImageSet : unsigned char { imsDefault, imsOriginal, imsAlternate };

enum TdxSkinObjectState : unsigned char { sosUnassigned, sosUnused };

typedef System::Set<TdxSkinObjectState, TdxSkinObjectState::sosUnassigned, TdxSkinObjectState::sosUnused>  TdxSkinObjectStates;

enum TdxSkinChange : unsigned char { scStruct, scContent, scDetails };

typedef System::Set<TdxSkinChange, TdxSkinChange::scStruct, TdxSkinChange::scDetails>  TdxSkinChanges;

typedef void __fastcall (__closure *TdxSkinChangeNotify)(System::TObject* Sender, TdxSkinChanges AChanges);

class DELPHICLASS EdxSkin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxSkin : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxSkin(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxSkin(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxSkin(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxSkin(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxSkin(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxSkin(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxSkin(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxSkin(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxSkin(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxSkin(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxSkin(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxSkin(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxSkin(void) { }
	
};

#pragma pack(pop)

__interface IdxSkinInfo;
typedef System::DelphiInterface<IdxSkinInfo> _di_IdxSkinInfo;
class DELPHICLASS TdxSkin;
__interface  INTERFACE_UUID("{97D85495-E631-413C-8DBC-BE7B784A9EA0}") IdxSkinInfo  : public System::IInterface 
{
	
public:
	virtual TdxSkin* __fastcall GetSkin(void) = 0 ;
};

__interface IdxSkinChangeListener;
typedef System::DelphiInterface<IdxSkinChangeListener> _di_IdxSkinChangeListener;
__interface  INTERFACE_UUID("{28681774-0475-43AE-8704-1C904D294742}") IdxSkinChangeListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall SkinChanged(TdxSkin* Sender) = 0 ;
};

__interface IdxSkinChangeListener2;
typedef System::DelphiInterface<IdxSkinChangeListener2> _di_IdxSkinChangeListener2;
__interface  INTERFACE_UUID("{0D7C0942-D2C4-4579-AD03-A3CB5BBFC5AF}") IdxSkinChangeListener2  : public System::IInterface 
{
	
public:
	virtual void __fastcall SkinChanged(TdxSkin* ASkin, TdxSkinChanges AChanges) = 0 ;
};

class DELPHICLASS TdxSkinCustomObject;
class PASCALIMPLEMENTATION TdxSkinCustomObject : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FName;
	System::Classes::TPersistent* FOwner;
	TdxSkinObjectStates FState;
	int FTag;
	TdxSkinChangeNotify FOnChange;
	void __fastcall SetName(const System::UnicodeString AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Changed(TdxSkinChanges AChanges);
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	virtual void __fastcall DoChanged(TdxSkinChanges AChanges);
	
public:
	__fastcall virtual TdxSkinCustomObject(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	__property TdxSkinObjectStates State = {read=FState, write=FState, nodefault};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	
__published:
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property TdxSkinChangeNotify OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinCustomObject(void) { }
	
};


class DELPHICLASS TdxSkinCustomObjectList;
class PASCALIMPLEMENTATION TdxSkinCustomObjectList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
private:
	TdxSkinChanges FChanges;
	System::Classes::TPersistent* FOwner;
	bool FSorted;
	int FUpdateCount;
	TdxSkinChangeNotify FOnChange;
	void __fastcall SubItemChanged(System::TObject* ASender, TdxSkinChanges AChanges);
	
protected:
	virtual void __fastcall Changed(TdxSkinChanges AChanges);
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion) = 0 ;
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream) = 0 ;
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	__property TdxSkinChangeNotify OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TdxSkinCustomObjectList(System::Classes::TPersistent* AOwner);
	__fastcall TdxSkinCustomObjectList(System::Classes::TPersistent* AOwner, TdxSkinChangeNotify AChangeHandler);
	TdxSkinCustomObject* __fastcall FindItemByName(const System::UnicodeString AName);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	HIDESBASE void __fastcall Exchange(int Index1, int Index2);
	HIDESBASE void __fastcall Sort(void);
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinCustomObjectList(void) { }
	
};


class DELPHICLASS TdxSkinProperties;
class DELPHICLASS TdxSkinProperty;
class PASCALIMPLEMENTATION TdxSkinProperties : public TdxSkinCustomObjectList
{
	typedef TdxSkinCustomObjectList inherited;
	
public:
	TdxSkinProperty* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSkinProperty* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream);
	
public:
	HIDESBASE TdxSkinProperty* __fastcall Add(const System::UnicodeString AName, TdxSkinPropertyClass AClass);
	HIDESBASE void __fastcall Assign(TdxSkinProperties* ASource);
	bool __fastcall Compare(TdxSkinProperties* AProperties);
	HIDESBASE TdxSkinProperty* __fastcall FindItemByName(const System::UnicodeString AName);
	__property TdxSkinProperty* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxSkinCustomObjectList.Create */ inline __fastcall virtual TdxSkinProperties(System::Classes::TPersistent* AOwner) : TdxSkinCustomObjectList(AOwner) { }
	/* TdxSkinCustomObjectList.CreateEx */ inline __fastcall TdxSkinProperties(System::Classes::TPersistent* AOwner, TdxSkinChangeNotify AChangeHandler) : TdxSkinCustomObjectList(AOwner, AChangeHandler) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinProperties(void) { }
	
};


class DELPHICLASS TdxSkinColors;
class DELPHICLASS TdxSkinColor;
class PASCALIMPLEMENTATION TdxSkinColors : public TdxSkinProperties
{
	typedef TdxSkinProperties inherited;
	
public:
	TdxSkinColor* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSkinColor* __fastcall GetItem(int Index);
	
public:
	HIDESBASE TdxSkinColor* __fastcall Add(const System::UnicodeString AName, System::Uitypes::TColor AValue);
	HIDESBASE TdxSkinColor* __fastcall FindItemByName(const System::UnicodeString AName);
	__property TdxSkinColor* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxSkinCustomObjectList.Create */ inline __fastcall virtual TdxSkinColors(System::Classes::TPersistent* AOwner) : TdxSkinProperties(AOwner) { }
	/* TdxSkinCustomObjectList.CreateEx */ inline __fastcall TdxSkinColors(System::Classes::TPersistent* AOwner, TdxSkinChangeNotify AChangeHandler) : TdxSkinProperties(AOwner, AChangeHandler) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinColors(void) { }
	
};


class DELPHICLASS TdxSkinControlGroups;
class DELPHICLASS TdxSkinControlGroup;
class PASCALIMPLEMENTATION TdxSkinControlGroups : public TdxSkinCustomObjectList
{
	typedef TdxSkinCustomObjectList inherited;
	
public:
	TdxSkinControlGroup* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSkinControlGroup* __fastcall GetItem(int Index);
	
public:
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream);
	HIDESBASE TdxSkinControlGroup* __fastcall Add(const System::UnicodeString AName);
	HIDESBASE void __fastcall Assign(TdxSkinControlGroups* ASource);
	HIDESBASE TdxSkinControlGroup* __fastcall FindItemByName(const System::UnicodeString AName);
	__property TdxSkinControlGroup* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxSkinCustomObjectList.Create */ inline __fastcall virtual TdxSkinControlGroups(System::Classes::TPersistent* AOwner) : TdxSkinCustomObjectList(AOwner) { }
	/* TdxSkinCustomObjectList.CreateEx */ inline __fastcall TdxSkinControlGroups(System::Classes::TPersistent* AOwner, TdxSkinChangeNotify AChangeHandler) : TdxSkinCustomObjectList(AOwner, AChangeHandler) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinControlGroups(void) { }
	
};


class DELPHICLASS TdxSkinElements;
class DELPHICLASS TdxSkinElement;
class PASCALIMPLEMENTATION TdxSkinElements : public TdxSkinCustomObjectList
{
	typedef TdxSkinCustomObjectList inherited;
	
public:
	TdxSkinElement* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSkinElement* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream);
	
public:
	HIDESBASE TdxSkinElement* __fastcall Add(const System::UnicodeString AName, TdxSkinElementClass AClass);
	HIDESBASE void __fastcall Assign(TdxSkinElements* ASource);
	HIDESBASE TdxSkinElement* __fastcall FindItemByName(const System::UnicodeString AName);
	__property TdxSkinElement* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxSkinCustomObjectList.Create */ inline __fastcall virtual TdxSkinElements(System::Classes::TPersistent* AOwner) : TdxSkinCustomObjectList(AOwner) { }
	/* TdxSkinCustomObjectList.CreateEx */ inline __fastcall TdxSkinElements(System::Classes::TPersistent* AOwner, TdxSkinChangeNotify AChangeHandler) : TdxSkinCustomObjectList(AOwner, AChangeHandler) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinElements(void) { }
	
};


class DELPHICLASS TdxSkinPersistent;
class DELPHICLASS TdxSkinBooleanProperty;
class DELPHICLASS TdxSkinIntegerProperty;
class PASCALIMPLEMENTATION TdxSkinPersistent : public TdxSkinCustomObject
{
	typedef TdxSkinCustomObject inherited;
	
private:
	TdxSkinChanges FChanges;
	bool FModified;
	int FUpdateCount;
	TdxSkinProperty* __fastcall GetProperty(int Index);
	int __fastcall GetPropertyCount(void);
	
protected:
	TdxSkinProperties* FProperties;
	virtual void __fastcall Changed(TdxSkinChanges AChanges);
	void __fastcall SubItemChanged(System::TObject* ASender, TdxSkinChanges AChanges);
	__property int UpdateCount = {read=FUpdateCount, write=FUpdateCount, nodefault};
	
public:
	__fastcall virtual TdxSkinPersistent(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	__fastcall virtual ~TdxSkinPersistent(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TdxSkinProperty* __fastcall AddProperty(const System::UnicodeString AName, TdxSkinPropertyClass APropertyClass);
	TdxSkinBooleanProperty* __fastcall AddPropertyBool(const System::UnicodeString AName, bool AValue);
	TdxSkinColor* __fastcall AddPropertyColor(const System::UnicodeString AName, System::Uitypes::TColor AValue);
	TdxSkinIntegerProperty* __fastcall AddPropertyInteger(const System::UnicodeString AName, int AValue);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall DeleteProperty(TdxSkinProperty* const AProperty)/* overload */;
	void __fastcall DeleteProperty(const System::UnicodeString APropertyName)/* overload */;
	void __fastcall ExchangeProperty(int AIndex1, int AIndex2);
	TdxSkinProperty* __fastcall GetPropertyByName(const System::UnicodeString AName)/* overload */;
	bool __fastcall GetPropertyByName(const System::UnicodeString AName, /* out */ TdxSkinProperty* &AProperty)/* overload */;
	virtual void __fastcall Sort(void);
	__property bool Modified = {read=FModified, write=FModified, nodefault};
	__property int PropertyCount = {read=GetPropertyCount, nodefault};
	__property TdxSkinProperty* Properties[int Index] = {read=GetProperty};
};


class DELPHICLASS TdxSkinDetails;
class PASCALIMPLEMENTATION TdxSkinDetails : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FDisplayName;
	System::UnicodeString FGroupName;
	System::StaticArray<Dxgdiplusclasses::TdxPNGImage*, 2> FIcons;
	System::UnicodeString FName;
	System::WideString FNotes;
	System::Classes::TNotifyEvent FOnChange;
	int FUpdateCount;
	Dxgdiplusclasses::TdxPNGImage* __fastcall GetIcon(TdxSkinIconSize ASize);
	void __fastcall DoIconsChanged(System::TObject* Sender);
	void __fastcall SetDisplayName(const System::UnicodeString AValue);
	void __fastcall SetGroupName(const System::UnicodeString AValue);
	void __fastcall SetName(const System::UnicodeString AValue);
	void __fastcall SetNotes(const System::WideString AValue);
	
protected:
	__int64 FDataOffset;
	virtual void __fastcall Changed(void);
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual TdxSkinDetails(void);
	__fastcall virtual ~TdxSkinDetails(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall Clear(void);
	bool __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall ResetIcon(TdxSkinIconSize ASize);
	__property System::UnicodeString DisplayName = {read=FDisplayName, write=SetDisplayName};
	__property System::UnicodeString GroupName = {read=FGroupName, write=SetGroupName};
	__property Dxgdiplusclasses::TdxPNGImage* Icons[TdxSkinIconSize ASize] = {read=GetIcon};
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property System::WideString Notes = {read=FNotes, write=SetNotes};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


typedef System::TMetaClass* TdxSkinClass;

class PASCALIMPLEMENTATION TdxSkin : public TdxSkinPersistent
{
	typedef TdxSkinPersistent inherited;
	
private:
	bool FDestroying;
	TdxSkinDetails* FDetails;
	TdxSkinControlGroups* FGroups;
	System::Classes::TInterfaceList* FListeners;
	TdxSkinChangeNotify FOnChange;
	TdxSkinColor* __fastcall GetColor(int Index);
	int __fastcall GetColorCount(void);
	System::UnicodeString __fastcall GetDisplayName(void);
	TdxSkinControlGroup* __fastcall GetGroup(int Index);
	int __fastcall GetGroupCount(void);
	bool __fastcall GetHasMissingElements(void);
	System::UnicodeString __fastcall GetName(void);
	HIDESBASE void __fastcall SetName(const System::UnicodeString Value);
	void __fastcall DetailsChanged(System::TObject* Sender);
	
protected:
	TdxSkinColors* FColors;
	virtual void __fastcall DoChanged(TdxSkinChanges AChanges);
	virtual void __fastcall LoadFromResource(NativeUInt hInst);
	void __fastcall NotifyListener(TdxSkinChanges AChanges, System::_di_IInterface ACustomListener);
	void __fastcall NotifyListeners(TdxSkinChanges AChanges);
	void __fastcall ReadDetailsFromOldSkinFormat(void);
	__property System::Classes::TInterfaceList* Listeners = {read=FListeners};
	
public:
	__fastcall virtual TdxSkin(const System::UnicodeString AName, bool ALoadOnCreate, NativeUInt hInst);
	__fastcall virtual ~TdxSkin(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TdxSkinColor* __fastcall AddColor(const System::UnicodeString AName, const System::Uitypes::TColor AColor);
	TdxSkinControlGroup* __fastcall AddGroup(const System::UnicodeString AName = System::UnicodeString());
	virtual void __fastcall Clear(void);
	void __fastcall ClearModified(void);
	virtual TdxSkin* __fastcall Clone(const System::UnicodeString AName);
	virtual void __fastcall DeleteGroup(TdxSkinControlGroup* const AGroup);
	virtual void __fastcall DeleteProperty(TdxSkinProperty* const AProperty)/* overload */;
	void __fastcall ExchangeColors(int AIndex1, int AIndex2);
	void __fastcall ExchangeGroups(int AIndex1, int AIndex2);
	TdxSkinColor* __fastcall GetColorByName(const System::UnicodeString AName);
	TdxSkinControlGroup* __fastcall GetGroupByName(const System::UnicodeString AName)/* overload */;
	bool __fastcall GetGroupByName(const System::UnicodeString AName, /* out */ TdxSkinControlGroup* &AGroup)/* overload */;
	void __fastcall LoadFromBinaryFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromBinaryStream(System::Classes::TStream* AStream);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall SaveToBinaryFile(const System::UnicodeString AFileName);
	void __fastcall SaveToBinaryStream(System::Classes::TStream* AStream);
	virtual void __fastcall Sort(void);
	void __fastcall AddListener(System::_di_IInterface AListener);
	void __fastcall RemoveListener(System::_di_IInterface AListener);
	__property int ColorCount = {read=GetColorCount, nodefault};
	__property TdxSkinColor* Colors[int Index] = {read=GetColor};
	__property TdxSkinDetails* Details = {read=FDetails};
	__property int GroupCount = {read=GetGroupCount, nodefault};
	__property TdxSkinControlGroup* Groups[int Index] = {read=GetGroup};
	__property bool HasMissingElements = {read=GetHasMissingElements, nodefault};
	
__published:
	__property System::UnicodeString DisplayName = {read=GetDisplayName};
	__property System::UnicodeString Name = {read=GetName, write=SetName};
	__property TdxSkinChangeNotify OnChange = {read=FOnChange, write=FOnChange};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  DeleteProperty(const System::UnicodeString APropertyName){ TdxSkinPersistent::DeleteProperty(APropertyName); }
	
};


class PASCALIMPLEMENTATION TdxSkinProperty : public TdxSkinCustomObject
{
	typedef TdxSkinCustomObject inherited;
	
public:
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__classmethod virtual System::UnicodeString __fastcall Description();
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
public:
	/* TdxSkinCustomObject.Create */ inline __fastcall virtual TdxSkinProperty(System::Classes::TPersistent* AOwner, const System::UnicodeString AName) : TdxSkinCustomObject(AOwner, AName) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinProperty(void) { }
	
};


class PASCALIMPLEMENTATION TdxSkinIntegerProperty : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
private:
	int FValue;
	void __fastcall SetValue(int AValue);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	
__published:
	__property int Value = {read=FValue, write=SetValue, default=0};
public:
	/* TdxSkinCustomObject.Create */ inline __fastcall virtual TdxSkinIntegerProperty(System::Classes::TPersistent* AOwner, const System::UnicodeString AName) : TdxSkinProperty(AOwner, AName) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinIntegerProperty(void) { }
	
};


class PASCALIMPLEMENTATION TdxSkinBooleanProperty : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
private:
	bool FValue;
	void __fastcall SetValue(bool AValue);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	
__published:
	__property bool Value = {read=FValue, write=SetValue, default=0};
public:
	/* TdxSkinCustomObject.Create */ inline __fastcall virtual TdxSkinBooleanProperty(System::Classes::TPersistent* AOwner, const System::UnicodeString AName) : TdxSkinProperty(AOwner, AName) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinBooleanProperty(void) { }
	
};


class PASCALIMPLEMENTATION TdxSkinColor : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
private:
	System::Uitypes::TColor FValue;
	void __fastcall SetValue(System::Uitypes::TColor AValue);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TdxSkinColor(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	
__published:
	__property System::Uitypes::TColor Value = {read=FValue, write=SetValue, default=536870912};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinColor(void) { }
	
};


class DELPHICLASS TdxSkinRectProperty;
class PASCALIMPLEMENTATION TdxSkinRectProperty : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
private:
	Cxgeometry::TcxRect* FValue;
	int __fastcall GetValueByIndex(int Index);
	void __fastcall SetValue(Cxgeometry::TcxRect* Value);
	void __fastcall SetValueByIndex(int Index, int Value);
	void __fastcall InternalHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TdxSkinRectProperty(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	__fastcall virtual ~TdxSkinRectProperty(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	__property Cxgeometry::TcxRect* Value = {read=FValue, write=SetValue};
	
__published:
	__property int Left = {read=GetValueByIndex, write=SetValueByIndex, index=0, default=0};
	__property int Top = {read=GetValueByIndex, write=SetValueByIndex, index=1, default=0};
	__property int Right = {read=GetValueByIndex, write=SetValueByIndex, index=2, default=0};
	__property int Bottom = {read=GetValueByIndex, write=SetValueByIndex, index=3, default=0};
};


class DELPHICLASS TdxSkinSizeProperty;
class PASCALIMPLEMENTATION TdxSkinSizeProperty : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
private:
	System::Types::TSize FValue;
	void __fastcall SetValue(const System::Types::TSize &AValue);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	int __fastcall GetValueByIndex(int Index);
	void __fastcall SetValueByIndex(int Index, int Value);
	__property System::Types::TSize Value = {read=FValue, write=SetValue};
	
__published:
	__property int cx = {read=GetValueByIndex, write=SetValueByIndex, index=0, default=0};
	__property int cy = {read=GetValueByIndex, write=SetValueByIndex, index=1, default=0};
public:
	/* TdxSkinCustomObject.Create */ inline __fastcall virtual TdxSkinSizeProperty(System::Classes::TPersistent* AOwner, const System::UnicodeString AName) : TdxSkinProperty(AOwner, AName) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinSizeProperty(void) { }
	
};


class DELPHICLASS TdxSkinBorder;
class DELPHICLASS TdxSkinCanvas;
class PASCALIMPLEMENTATION TdxSkinBorder : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
private:
	System::Uitypes::TColor FColor;
	Cxgraphics::TcxBorder FKind;
	int FThin;
	int __fastcall GetContentMargin(void);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetThin(int AValue);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TdxSkinBorder(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	virtual void __fastcall Draw(HDC DC, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawEx(TdxSkinCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall ResetToDefaults(void);
	__property int ContentMargin = {read=GetContentMargin, nodefault};
	__property Cxgraphics::TcxBorder Kind = {read=FKind, nodefault};
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870911};
	__property int Thin = {read=FThin, write=SetThin, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinBorder(void) { }
	
};


class DELPHICLASS TdxSkinBorders;
class PASCALIMPLEMENTATION TdxSkinBorders : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
public:
	TdxSkinBorder* operator[](Cxgraphics::TcxBorder AKind) { return Items[AKind]; }
	
private:
	System::StaticArray<TdxSkinBorder*, 4> FBorders;
	TdxSkinBorder* __fastcall GetBorder(Cxgraphics::TcxBorder ABorder);
	TdxSkinBorder* __fastcall GetBorderByIndex(int Index);
	System::Types::TRect __fastcall GetContentMargins(void);
	void __fastcall SetBorderByIndex(int Index, TdxSkinBorder* AValue);
	void __fastcall SubItemChanged(System::TObject* ASender, TdxSkinChanges AChanges);
	
protected:
	void __fastcall CreateBorders(void);
	void __fastcall DeleteBorders(void);
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual TdxSkinBorders(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	__fastcall virtual ~TdxSkinBorders(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	virtual void __fastcall Draw(TdxSkinCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall ResetToDefaults(void);
	__property System::Types::TRect ContentMargins = {read=GetContentMargins};
	__property TdxSkinBorder* Items[Cxgraphics::TcxBorder AKind] = {read=GetBorder/*, default*/};
	
__published:
	__property TdxSkinBorder* Left = {read=GetBorderByIndex, write=SetBorderByIndex, index=0};
	__property TdxSkinBorder* Top = {read=GetBorderByIndex, write=SetBorderByIndex, index=1};
	__property TdxSkinBorder* Right = {read=GetBorderByIndex, write=SetBorderByIndex, index=2};
	__property TdxSkinBorder* Bottom = {read=GetBorderByIndex, write=SetBorderByIndex, index=3};
};


class DELPHICLASS TdxSkinStringProperty;
class PASCALIMPLEMENTATION TdxSkinStringProperty : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
private:
	System::UnicodeString FValue;
	void __fastcall SetValue(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	
__published:
	__property System::UnicodeString Value = {read=FValue, write=SetValue};
public:
	/* TdxSkinCustomObject.Create */ inline __fastcall virtual TdxSkinStringProperty(System::Classes::TPersistent* AOwner, const System::UnicodeString AName) : TdxSkinProperty(AOwner, AName) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinStringProperty(void) { }
	
};


class DELPHICLASS TdxSkinWideStringProperty;
class PASCALIMPLEMENTATION TdxSkinWideStringProperty : public TdxSkinStringProperty
{
	typedef TdxSkinStringProperty inherited;
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* Stream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* Stream);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TdxSkinCustomObject.Create */ inline __fastcall virtual TdxSkinWideStringProperty(System::Classes::TPersistent* AOwner, const System::UnicodeString AName) : TdxSkinStringProperty(AOwner, AName) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSkinWideStringProperty(void) { }
	
};


class DELPHICLASS TdxSkinAlternateImageAttributes;
class PASCALIMPLEMENTATION TdxSkinAlternateImageAttributes : public TdxSkinProperty
{
	typedef TdxSkinProperty inherited;
	
private:
	System::Byte FAlpha;
	TdxSkinBorders* FBorders;
	TdxSkinBorders* FBordersInner;
	Cxgeometry::TcxRect* FContentOffsets;
	TdxSkinGradientMode FGradient;
	System::Uitypes::TColor FGradientBeginColor;
	System::Uitypes::TColor FGradientEndColor;
	bool __fastcall GetIsAlphaUsed(void);
	void __fastcall BordersChanged(System::TObject* ASender, TdxSkinChanges AChanges);
	void __fastcall ContentOffsetsChanged(System::TObject* ASender);
	void __fastcall SetAlpha(System::Byte AValue);
	void __fastcall SetBorders(TdxSkinBorders* AValue);
	void __fastcall SetBordersInner(TdxSkinBorders* AValue);
	void __fastcall SetContentOffsets(Cxgeometry::TcxRect* AValue);
	void __fastcall SetGradientBeginColor(System::Uitypes::TColor AValue);
	void __fastcall SetGradientEndColor(System::Uitypes::TColor AValue);
	void __fastcall SetGradientMode(TdxSkinGradientMode AValue);
	
protected:
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual TdxSkinAlternateImageAttributes(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	__fastcall virtual ~TdxSkinAlternateImageAttributes(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Draw(TdxSkinCanvas* ACanvas, const System::Types::TRect &R);
	virtual bool __fastcall Compare(TdxSkinProperty* AProperty);
	__property bool IsAlphaUsed = {read=GetIsAlphaUsed, nodefault};
	
__published:
	__property System::Byte Alpha = {read=FAlpha, write=SetAlpha, default=255};
	__property TdxSkinBorders* Borders = {read=FBorders, write=SetBorders};
	__property TdxSkinBorders* BordersInner = {read=FBordersInner, write=SetBordersInner};
	__property Cxgeometry::TcxRect* ContentOffsets = {read=FContentOffsets, write=SetContentOffsets};
	__property TdxSkinGradientMode Gradient = {read=FGradient, write=SetGradientMode, default=0};
	__property System::Uitypes::TColor GradientBeginColor = {read=FGradientBeginColor, write=SetGradientBeginColor, default=536870911};
	__property System::Uitypes::TColor GradientEndColor = {read=FGradientEndColor, write=SetGradientEndColor, default=536870911};
};


class PASCALIMPLEMENTATION TdxSkinControlGroup : public TdxSkinPersistent
{
	typedef TdxSkinPersistent inherited;
	
private:
	int __fastcall GetCount(void);
	TdxSkinElement* __fastcall GetElement(int AIndex);
	bool __fastcall GetHasMissingElements(void);
	TdxSkin* __fastcall GetSkin(void);
	void __fastcall SetElement(int AIndex, TdxSkinElement* AElement);
	
protected:
	TdxSkinElements* FElements;
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual TdxSkinControlGroup(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	__fastcall virtual ~TdxSkinControlGroup(void);
	TdxSkinElement* __fastcall AddElement(const System::UnicodeString AName);
	TdxSkinElement* __fastcall AddElementEx(const System::UnicodeString AName, TdxSkinElementClass AElementClass);
	TdxSkinElement* __fastcall GetElementByName(const System::UnicodeString AName)/* overload */;
	bool __fastcall GetElementByName(const System::UnicodeString AName, /* out */ TdxSkinElement* &AElement)/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	void __fastcall ClearModified(void);
	void __fastcall Delete(int AIndex);
	void __fastcall ExchangeElements(int AIndex1, int AIndex2);
	void __fastcall RemoveElement(TdxSkinElement* AElement);
	void __fastcall RemoveElementByName(const System::UnicodeString AElementName);
	virtual void __fastcall Sort(void);
	__property int Count = {read=GetCount, nodefault};
	__property TdxSkinElement* Elements[int Index] = {read=GetElement, write=SetElement};
	__property bool HasMissingElements = {read=GetHasMissingElements, nodefault};
	__property TdxSkin* Skin = {read=GetSkin};
};


enum TdxSkinElementState : unsigned char { esNormal, esHot, esPressed, esDisabled, esActive, esFocused, esDroppedDown, esChecked, esHotCheck, esActiveDisabled, esCheckPressed };

typedef System::Set<TdxSkinElementState, TdxSkinElementState::esNormal, TdxSkinElementState::esCheckPressed>  TdxSkinElementStates;

enum TdxSkinImagePart : unsigned char { sipTopLeft, sipTop, sipTopRight, sipLeft, sipCenter, sipRight, sipBottomLeft, sipBottom, sipBottomRight };

typedef System::StaticArray<System::Types::TRect, 9> TdxSkinElementPartBounds;

typedef System::StaticArray<bool, 9> TdxSkinElementPartVisibility;

enum TdxSkinImageLayout : unsigned char { ilHorizontal, ilVertical };

enum TdxSkinStretchMode : unsigned char { smStretch, smTile, smNoResize };

class DELPHICLASS TdxSkinImage;
class PASCALIMPLEMENTATION TdxSkinImage : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxSkinGradientMode FGradient;
	System::Uitypes::TColor FGradientBeginColor;
	System::Uitypes::TColor FGradientEndColor;
	int FImageCount;
	TdxSkinImageLayout FImageLayout;
	bool FIsDirty;
	Cxgeometry::TcxMargin* FMargins;
	TdxSkinElement* FOwner;
	TdxSkinElementPartBounds FPartsBounds;
	TdxSkinElementPartVisibility FPartsVisibility;
	System::Types::TSize FSize;
	System::UnicodeString FSourceName;
	System::StaticArray<System::Types::TRect, 11> FStateBounds;
	int FStateCount;
	TdxSkinElementStates FStates;
	TdxSkinStretchMode FStretch;
	Dxgdiplusclasses::TdxPNGImage* FTexture;
	System::Uitypes::TColor FTransparentColor;
	System::Classes::TNotifyEvent FOnChange;
	bool __fastcall GetEmpty(void);
	bool __fastcall GetIsGradientParamsAssigned(void);
	System::UnicodeString __fastcall GetName(void);
	System::Types::TRect __fastcall GetPartBounds(TdxSkinImagePart APart);
	bool __fastcall GetPartVisible(TdxSkinImagePart APart);
	System::Types::TSize __fastcall GetSize(void);
	System::UnicodeString __fastcall GetSourceName(void);
	System::Types::TRect __fastcall GetStateBounds(int AImageIndex, TdxSkinElementState AState);
	int __fastcall GetStateCount(void);
	void __fastcall SetGradientBeginColor(System::Uitypes::TColor AValue);
	void __fastcall SetGradientEndColor(System::Uitypes::TColor AValue);
	void __fastcall SetGradientMode(TdxSkinGradientMode AValue);
	void __fastcall SetImageCount(int AValue);
	void __fastcall SetImageLayout(TdxSkinImageLayout AValue);
	void __fastcall SetMargins(Cxgeometry::TcxMargin* AValue);
	void __fastcall SetName(const System::UnicodeString AValue);
	void __fastcall SetStates(TdxSkinElementStates AValue);
	void __fastcall SetStretch(TdxSkinStretchMode AValue);
	void __fastcall SetTransparentColor(System::Uitypes::TColor AValue);
	void __fastcall SubItemChanged(System::TObject* ASender);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Changed(void);
	void __fastcall CheckInfo(void);
	void __fastcall CheckState(TdxSkinElementState &AState, int &AImageIndex);
	virtual void __fastcall InitializeInfo(void);
	void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	void __fastcall DataWrite(System::Classes::TStream* AStream);
	__property bool IsDirty = {read=FIsDirty, write=FIsDirty, nodefault};
	__property bool IsGradientParamsAssigned = {read=GetIsGradientParamsAssigned, nodefault};
	__property System::Types::TRect PartBounds[TdxSkinImagePart APart] = {read=GetPartBounds};
	__property bool PartVisible[TdxSkinImagePart APart] = {read=GetPartVisible};
	__property System::Uitypes::TColor TransparentColor = {read=FTransparentColor, write=SetTransparentColor, nodefault};
	
public:
	__fastcall virtual TdxSkinImage(TdxSkinElement* AOwner);
	__fastcall virtual ~TdxSkinImage(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Clear(void);
	virtual bool __fastcall Compare(TdxSkinImage* AImage);
	virtual void __fastcall Draw(HDC DC, const System::Types::TRect &ARect, int AImageIndex = 0x0, TdxSkinElementState AState = (TdxSkinElementState)(0x0));
	virtual void __fastcall DrawEx(TdxSkinCanvas* ACanvas, const System::Types::TRect &ARect, int AImageIndex = 0x0, TdxSkinElementState AState = (TdxSkinElementState)(0x0));
	void __fastcall GetBitmap(int AImageIndex, TdxSkinElementState AState, Vcl::Graphics::TBitmap* ABitmap, System::Uitypes::TColor ABackgroundColor = (System::Uitypes::TColor)(0x1fffffff));
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromResource(NativeUInt AInstance, const System::UnicodeString AName, System::WideChar * AType);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall SetStateMapping(TdxSkinElementState *AStateOrder, const int AStateOrder_Size);
	__property bool Empty = {read=GetEmpty, nodefault};
	__property System::UnicodeString Name = {read=GetName, write=SetName};
	__property TdxSkinElement* Owner = {read=FOwner};
	__property System::Types::TSize Size = {read=GetSize};
	__property System::UnicodeString SourceName = {read=GetSourceName};
	__property System::Types::TRect StateBounds[int ImageIndex][TdxSkinElementState State] = {read=GetStateBounds};
	__property int StateCount = {read=GetStateCount, nodefault};
	__property Dxgdiplusclasses::TdxPNGImage* Texture = {read=FTexture};
	
__published:
	__property TdxSkinGradientMode Gradient = {read=FGradient, write=SetGradientMode, default=0};
	__property System::Uitypes::TColor GradientBeginColor = {read=FGradientBeginColor, write=SetGradientBeginColor, default=536870911};
	__property System::Uitypes::TColor GradientEndColor = {read=FGradientEndColor, write=SetGradientEndColor, default=536870911};
	__property int ImageCount = {read=FImageCount, write=SetImageCount, default=1};
	__property TdxSkinImageLayout ImageLayout = {read=FImageLayout, write=SetImageLayout, default=0};
	__property Cxgeometry::TcxMargin* Margins = {read=FMargins, write=SetMargins};
	__property TdxSkinElementStates States = {read=FStates, write=SetStates, default=1};
	__property TdxSkinStretchMode Stretch = {read=FStretch, write=SetStretch, default=0};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinCanvas : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxgdiplusclasses::TdxGPGraphics* FGraphics;
	bool FLowColorsMode;
	
public:
	void __fastcall BeginPaint(void * AGraphics)/* overload */;
	void __fastcall BeginPaint(HDC DC, const System::Types::TRect &R)/* overload */;
	void __fastcall EndPaint(void)/* overload */;
	void __fastcall DrawFrame(const System::Types::TRect &R, System::Uitypes::TColor AColor, int ALineWidth = 0x1, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ), System::Byte AAlpha = (System::Byte)(0xff));
	void __fastcall DrawImage(TdxSkinImage* AImage, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect);
	void __fastcall DrawTexture(Dxgdiplusclasses::TdxGPImage* ATexture, const System::Types::TRect &R, TdxSkinStretchMode AStretchMode);
	void __fastcall FillRectByColor(const System::Types::TRect &R, System::Uitypes::TColor AColor, System::Byte AAlpha = (System::Byte)(0xff));
	void __fastcall FillRectByGradient(const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, TdxSkinGradientMode AMode, System::Byte AAlpha = (System::Byte)(0xff));
	bool __fastcall IsRectVisible(HDC DC, const System::Types::TRect &R);
	__property Dxgdiplusclasses::TdxGPGraphics* Graphics = {read=FGraphics};
	__property bool LowColorsMode = {read=FLowColorsMode, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxSkinCanvas(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinCanvas(void) { }
	
};

#pragma pack(pop)

typedef System::StaticArray<TdxSkinAlternateImageAttributes*, 11> TdxSkinAlternateImageSet;

class DELPHICLASS TdxSkinElementCache;
class PASCALIMPLEMENTATION TdxSkinElement : public TdxSkinPersistent
{
	typedef TdxSkinPersistent inherited;
	
private:
	System::Byte FAlpha;
	bool FAlternateImageSetDirty;
	int FAlternateImageSetIndex;
	TdxSkinBorders* FBorders;
	TdxSkinElementCache* FCache;
	System::Uitypes::TColor FColor;
	Cxgeometry::TcxRect* FContentOffset;
	TdxSkinImage* FGlyph;
	TdxSkinImage* FImage;
	Cxgeometry::TcxSize* FMinSize;
	System::Uitypes::TColor FTextColor;
	TdxSkinControlGroup* __fastcall GetGroup(void);
	int __fastcall GetImageCount(void);
	bool __fastcall GetIsAlphaUsed(void);
	System::UnicodeString __fastcall GetPath(void);
	System::Types::TSize __fastcall GetSize(void);
	TdxSkinElementStates __fastcall GetStates(void);
	bool __fastcall GetUseCache(void);
	void __fastcall SetAlpha(System::Byte AValue);
	void __fastcall SetBorders(TdxSkinBorders* AValue);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetContentOffset(Cxgeometry::TcxRect* AValue);
	void __fastcall SetGlyph(TdxSkinImage* AValue);
	void __fastcall SetImage(TdxSkinImage* AValue);
	void __fastcall SetMinSize(Cxgeometry::TcxSize* AValue);
	void __fastcall SetTextColor(System::Uitypes::TColor AValue);
	void __fastcall SetUseCache(bool AValue);
	void __fastcall BordersChanged(System::TObject* ASender, TdxSkinChanges AChanges);
	HIDESBASE void __fastcall SubItemChanged(System::TObject* ASender);
	
protected:
	TdxSkinAlternateImageSet FAlternateImageSet;
	int FReadedImageCount;
	virtual System::UnicodeString __fastcall ExpandName(TdxSkinImage* ABitmap);
	bool __fastcall CanUseAlternateImageSet(int AImageIndex, TdxSkinElementState AState, bool ALowColorsMode, /* out */ TdxSkinAlternateImageAttributes* &AStateAttributes);
	void __fastcall CheckAlternateImageSet(int AIndex);
	virtual void __fastcall Changed(TdxSkinChanges AChanges);
	virtual void __fastcall DataRead(System::Classes::TStream* AStream, const double AVersion);
	virtual void __fastcall DataWrite(System::Classes::TStream* AStream);
	__property bool AlternateImageSetDirty = {read=FAlternateImageSetDirty, write=FAlternateImageSetDirty, nodefault};
	__property int AlternateImageSetIndex = {read=FAlternateImageSetIndex, nodefault};
	
public:
	__fastcall virtual TdxSkinElement(System::Classes::TPersistent* AOwner, const System::UnicodeString AName);
	__fastcall virtual ~TdxSkinElement(void);
	TdxSkinAlternateImageAttributes* __fastcall AddAlternateImageAttributes(TdxSkinElementState AState, int AImageIndex = 0x0);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Compare(TdxSkinElement* AElement);
	virtual System::Uitypes::TColor __fastcall GetTextColor(Cxlookandfeelpainters::TcxButtonState AState, const System::UnicodeString APropertyPrefix = System::UnicodeString());
	virtual void __fastcall Draw(HDC DC, const System::Types::TRect &ARect, int AImageIndex = 0x0, TdxSkinElementState AState = (TdxSkinElementState)(0x0));
	void __fastcall DrawEx(TdxSkinCanvas* ACanvas, const System::Types::TRect &ARect, int AImageIndex = 0x0, TdxSkinElementState AState = (TdxSkinElementState)(0x0));
	void __fastcall SetStateMapping(TdxSkinElementState *AStateOrder, const int AStateOrder_Size);
	__property TdxSkinControlGroup* Group = {read=GetGroup};
	__property int ImageCount = {read=GetImageCount, nodefault};
	__property bool IsAlphaUsed = {read=GetIsAlphaUsed, nodefault};
	__property System::UnicodeString Path = {read=GetPath};
	__property System::Types::TSize Size = {read=GetSize};
	__property TdxSkinElementStates States = {read=GetStates, nodefault};
	__property bool UseCache = {read=GetUseCache, write=SetUseCache, nodefault};
	
__published:
	__property System::Byte Alpha = {read=FAlpha, write=SetAlpha, default=255};
	__property TdxSkinBorders* Borders = {read=FBorders, write=SetBorders};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property Cxgeometry::TcxRect* ContentOffset = {read=FContentOffset, write=SetContentOffset};
	__property TdxSkinImage* Glyph = {read=FGlyph, write=SetGlyph};
	__property TdxSkinImage* Image = {read=FImage, write=SetImage};
	__property Cxgeometry::TcxSize* MinSize = {read=FMinSize, write=SetMinSize};
	__property System::Uitypes::TColor TextColor = {read=FTextColor, write=SetTextColor, default=536870912};
};


class DELPHICLASS TdxSkinEmptyElement;
class PASCALIMPLEMENTATION TdxSkinEmptyElement : public TdxSkinElement
{
	typedef TdxSkinElement inherited;
	
public:
	virtual void __fastcall Draw(HDC DC, const System::Types::TRect &ARect, int AImageIndex = 0x0, TdxSkinElementState AState = (TdxSkinElementState)(0x0));
public:
	/* TdxSkinElement.Create */ inline __fastcall virtual TdxSkinEmptyElement(System::Classes::TPersistent* AOwner, const System::UnicodeString AName) : TdxSkinElement(AOwner, AName) { }
	/* TdxSkinElement.Destroy */ inline __fastcall virtual ~TdxSkinEmptyElement(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinElementCache : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	void *FCache;
	Cxgraphics::TcxBitmap* FCacheOpaque;
	TdxSkinElement* FElement;
	int FImageIndex;
	TdxSkinImageSet FImageSet;
	System::Types::TRect FRect;
	TdxSkinElementState FState;
	void __fastcall FreeCache(void);
	void __fastcall InitCache(const System::Types::TRect &R);
	void __fastcall InitOpaqueCache(const System::Types::TRect &R);
	
protected:
	__property TdxSkinElement* Element = {read=FElement};
	__property int ImageIndex = {read=FImageIndex, nodefault};
	__property TdxSkinElementState State = {read=FState, nodefault};
	
public:
	__fastcall virtual ~TdxSkinElementCache(void);
	void __fastcall CheckCacheState(TdxSkinElement* AElement, const System::Types::TRect &R, TdxSkinElementState AState = (TdxSkinElementState)(0x0), int AImageIndex = 0x0);
	void __fastcall Draw(HDC DC, const System::Types::TRect &R);
	void __fastcall DrawEx(HDC DC, TdxSkinElement* AElement, const System::Types::TRect &R, TdxSkinElementState AState = (TdxSkinElementState)(0x0), int AImageIndex = 0x0);
	void __fastcall Flush(void);
public:
	/* TObject.Create */ inline __fastcall TdxSkinElementCache(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSkinElementCacheList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinElementCacheList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
private:
	int FCacheListLimit;
	void __fastcall CheckListLimits(void);
	bool __fastcall FindElementCache(TdxSkinElement* AElement, const System::Types::TRect &R, /* out */ TdxSkinElementCache* &AElementCache);
	TdxSkinElementCache* __fastcall GetElementCache(int AIndex);
	
public:
	__fastcall TdxSkinElementCacheList(void);
	void __fastcall DrawElement(HDC DC, TdxSkinElement* AElement, const System::Types::TRect &R, TdxSkinElementState AState = (TdxSkinElementState)(0x0), int AImageIndex = 0x0);
	void __fastcall Flush(void);
	__property int CacheListLimit = {read=FCacheListLimit, write=FCacheListLimit, nodefault};
	__property TdxSkinElementCache* ElementCache[int Index] = {read=GetElementCache};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinElementCacheList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSkinBinaryWriter;
class PASCALIMPLEMENTATION TdxSkinBinaryWriter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCount;
	__int64 FHeaderOffset;
	System::Classes::TStream* FStream;
	void __fastcall WriteHeader(void);
	
protected:
	__property System::Classes::TStream* Stream = {read=FStream};
	
public:
	__fastcall virtual TdxSkinBinaryWriter(System::Classes::TStream* AStream);
	__fastcall virtual ~TdxSkinBinaryWriter(void);
	void __fastcall AddSkin(TdxSkin* ASkin);
};


class DELPHICLASS TdxSkinBinaryReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinBinaryReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FSkins;
	System::Classes::TStream* FStream;
	int __fastcall GetCount(void);
	TdxSkinDetails* __fastcall GetSkinDetails(int Index);
	System::UnicodeString __fastcall GetSkinDisplayName(int Index);
	System::UnicodeString __fastcall GetSkinName(int Index);
	int __fastcall GetSkinOffset(int Index);
	
protected:
	int __fastcall IndexOf(const System::UnicodeString ASkinName);
	bool __fastcall ReadBinaryProject(System::Classes::TStream* AStream);
	bool __fastcall ReadBinarySkin(System::Classes::TStream* AStream);
	void __fastcall ReadSkinsInfo(void);
	__property System::Classes::TStream* Stream = {read=FStream};
	
public:
	__fastcall virtual TdxSkinBinaryReader(System::Classes::TStream* AStream);
	__fastcall virtual ~TdxSkinBinaryReader(void);
	bool __fastcall LoadSkin(TdxSkin* ASkin, int ASkinIndex)/* overload */;
	bool __fastcall LoadSkin(TdxSkin* ASkin, const System::UnicodeString ASkinName)/* overload */;
	__property int Count = {read=GetCount, nodefault};
	__property TdxSkinDetails* SkinDetails[int Index] = {read=GetSkinDetails};
	__property System::UnicodeString SkinDisplayName[int Index] = {read=GetSkinDisplayName};
	__property System::UnicodeString SkinName[int Index] = {read=GetSkinName};
	__property int SkinOffset[int Index] = {read=GetSkinOffset};
};

#pragma pack(pop)

typedef System::StaticArray<System::UnicodeString, 5> Dxskinscore__23;

typedef System::StaticArray<System::UnicodeString, 11> Dxskinscore__33;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxSkinSignature dxSkinSignature;
extern PACKAGE double dxSkinStreamVersion;
#define dxSkinImageExt L".png"
#define GlyphNameSuffix L"_Glyph.png"
#define ImageNameSuffix L"_Image.png"
extern PACKAGE Dxskinscore__1 BitmapNameSuffixes;
extern PACKAGE Dxskinscore__23 dxSkinElementTextColorPropertyNames;
extern PACKAGE Dxskinscore__33 dxSkinElementStateNames;
extern PACKAGE TdxSkinImageSet dxSkinsUseImageSet;
extern PACKAGE System::UnicodeString __fastcall dxSkinGetAlternateImageAttrsPropertyName(TdxSkinElementState AState, int AImageIndex = 0x0);
extern PACKAGE System::UnicodeString __fastcall dxSkinReadStringFromStream(System::Classes::TStream* AStream);
extern PACKAGE System::WideString __fastcall dxSkinReadWideStringFromStream(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall dxSkinWriteStringToStream(System::Classes::TStream* AStream, const System::UnicodeString AValue);
extern PACKAGE void __fastcall dxSkinWriteWideStringToStream(System::Classes::TStream* AStream, const System::WideString AValue);
extern PACKAGE System::Classes::TList* __fastcall dxSkinRegisteredPropertyTypes(void);
extern PACKAGE void __fastcall dxSkinInvalidOperation(const System::UnicodeString AMessage);
extern PACKAGE void __fastcall dxSkinCheck(bool ACondition, const System::UnicodeString AMessage);
extern PACKAGE void __fastcall dxSkinCheckVersion(const double AVersion);
extern PACKAGE bool __fastcall dxSkinCheckSignature(System::Classes::TStream* AStream, /* out */ double &AVersion);
extern PACKAGE TdxSkinElement* __fastcall dxSkinCheckSkinElement(TdxSkinElement* AElement);
extern PACKAGE void __fastcall dxSkinWriteSignature(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall dxSkinsCalculatePartsBounds(const System::Types::TRect &R, const System::Types::TRect &AMargins, void *AParts);
extern PACKAGE void __fastcall dxSkinsCheckMargins(System::Types::TRect &AMargins, const System::Types::TRect &R);
extern PACKAGE TdxSkinElementState __fastcall dxSkinElementCheckState(TdxSkinElement* AElement, TdxSkinElementState AState);
}	/* namespace Dxskinscore */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSCORE)
using namespace Dxskinscore;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinscoreHPP
