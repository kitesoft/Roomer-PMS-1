// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSHeaders.pas' rev: 24.00 (Win32)

#ifndef CxssheadersHPP
#define CxssheadersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssheaders
{
//-- type declarations -------------------------------------------------------
enum TcxSSHeaderElementState : unsigned char { hsHidden, hsLocked, hsDefault, hsScaled, hsLockProtect };

typedef System::Set<TcxSSHeaderElementState, TcxSSHeaderElementState::hsHidden, TcxSSHeaderElementState::hsLockProtect>  TcxSSHeaderElementStates;

typedef System::Word TcxSSSize;

struct TcxSSHeaderElement;
typedef TcxSSHeaderElement *PcxSSHeaderElement;

struct DECLSPEC_DRECORD TcxSSHeaderElement
{
public:
	int OriginalSize;
	TcxSSHeaderElementStates States;
	int Scale;
	System::Word Size;
};


typedef System::StaticArray<TcxSSHeaderElement, 134217727> TcxSSHeaderElements;

typedef TcxSSHeaderElements *PcxSSHeaderElements;

class DELPHICLASS TcxSSHeader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSSHeader : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Word operator[](int AIndex) { return Size[AIndex]; }
	
private:
	int FCount;
	TcxSSHeaderElement FDefaultElement;
	TcxSSHeaderElements *FElements;
	Cxsstypes::TcxSSHeaderType FKind;
	System::TObject* FListener;
	System::TObject* FOwner;
	System::Word __fastcall GetDefaultSize(void);
	int __fastcall GetHeaderSize(void);
	bool __fastcall GetIsDefault(int AIndex);
	TcxSSHeaderElement __fastcall GetItem(int AIndex);
	System::Word __fastcall GetItemSize(int AIndex);
	bool __fastcall GetLock(int AIndex);
	int __fastcall GetOriginalSize(int AIndex);
	System::TObject* __fastcall GetOwnerSheet(void);
	bool __fastcall GetReadOnly(int AIndex);
	bool __fastcall GetVisible(int AIndex);
	void __fastcall SetDefaultSize(const System::Word Value);
	void __fastcall SetItem(int AIndex, const TcxSSHeaderElement &Value);
	void __fastcall SetItemSize(int AIndex, System::Word Value);
	void __fastcall SetItemSizeEx(int AIndex, System::Word Value, bool ACheckDefault = false);
	void __fastcall SetLock(int AIndex, const bool Value);
	void __fastcall SetOriginalSize(int AIndex, const int Value);
	void __fastcall SetReadOnly(int AIndex, const bool Value);
	void __fastcall SetVisible(int AIndex, const bool Value);
	
protected:
	virtual void __fastcall Clear(void);
	bool __fastcall CompareElements(const TcxSSHeaderElement &AItem1, const TcxSSHeaderElement &AItem2);
	virtual void __fastcall DeleteAt(int AIndex);
	virtual int __fastcall FindItem(int AFromIndex, System::Word ALength, bool AForward = true);
	virtual int __fastcall GetCountItems(int AFromIndex, int ALength, bool AForward = true);
	virtual int __fastcall GetLength(int AFromIndex, int AToIndex);
	virtual int __fastcall GetNextItem(int AIndex, bool AForward);
	void __fastcall GetPageCount(int AIndex, int APageSize, int &APageCount, int &AMinItem, int &AMaxItem);
	virtual void __fastcall InsertAt(int AIndex, System::Word ASize, bool ADefault = false, bool AVisible = true, bool ALock = false);
	virtual void __fastcall SetScaledSize(int AIndex, int ANewScale)/* overload */;
	virtual void __fastcall SetScaledSize(int AIndex, int AScale, int ANewScale)/* overload */;
	__property int Count = {read=FCount, nodefault};
	__property int HeaderSize = {read=GetHeaderSize, nodefault};
	__property System::TObject* Listener = {read=FListener};
	__property System::TObject* Owner = {read=FOwner};
	__property PcxSSHeaderElements Data = {read=FElements};
	
public:
	__fastcall virtual TcxSSHeader(System::TObject* AOwner, Cxsstypes::TcxSSHeaderType AKind, int ADefSize);
	__fastcall virtual ~TcxSSHeader(void);
	virtual void __fastcall Assign(TcxSSHeader* Source);
	void __fastcall ResetDefault(int AIndex);
	__property System::Word DefaultSize = {read=GetDefaultSize, write=SetDefaultSize, nodefault};
	__property bool IsDefault[int AIndex] = {read=GetIsDefault};
	__property bool Lock[int AIndex] = {read=GetLock, write=SetLock};
	__property bool LockProtect[int AIndex] = {read=GetReadOnly, write=SetReadOnly};
	__property int OriginalSize[int AIndex] = {read=GetOriginalSize, write=SetOriginalSize};
	__property System::TObject* OwnerSheet = {read=GetOwnerSheet};
	__property System::Word Size[int AIndex] = {read=GetItemSize, write=SetItemSize/*, default*/};
	__property bool Visible[int AIndex] = {read=GetVisible, write=SetVisible};
	__property Cxsstypes::TcxSSHeaderType Kind = {read=FKind, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSSHeaderClass;

class DELPHICLASS EHeaderError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EHeaderError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EHeaderError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EHeaderError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EHeaderError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EHeaderError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EHeaderError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EHeaderError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EHeaderError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EHeaderError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EHeaderError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EHeaderError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EHeaderError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EHeaderError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EHeaderError(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxssheaders */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSHEADERS)
using namespace Cxssheaders;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssheadersHPP
