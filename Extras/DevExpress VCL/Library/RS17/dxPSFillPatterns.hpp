// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSFillPatterns.pas' rev: 24.00 (Win32)

#ifndef DxpsfillpatternsHPP
#define DxpsfillpatternsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfillpatterns
{
//-- type declarations -------------------------------------------------------
typedef System::Word TdxPSPatternBitRow;

typedef System::StaticArray<System::Word, 8> TdxPSPatternBitRows;

typedef System::TMetaClass* TdxPSFillPatternClass;

class DELPHICLASS TdxPSFillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFillPattern : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::Types::TSize __fastcall Dimensions();
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual bool __fastcall RequiredBrushOrigin();
	__classmethod virtual bool __fastcall RequiredScaling();
	__classmethod virtual bool __fastcall Solid();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSFillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSFillPattern(void) : System::Classes::TPersistent() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSSolidFillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSSolidFillPattern : public TdxPSFillPattern
{
	typedef TdxPSFillPattern inherited;
	
public:
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual bool __fastcall RequiredBrushOrigin();
	__classmethod virtual bool __fastcall RequiredScaling();
	__classmethod virtual bool __fastcall Solid();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSSolidFillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSSolidFillPattern(void) : TdxPSFillPattern() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSGray50FillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSGray50FillPattern : public TdxPSFillPattern
{
	typedef TdxPSFillPattern inherited;
	
public:
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSGray50FillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSGray50FillPattern(void) : TdxPSFillPattern() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSFillPatternItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFillPatternItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TBitmap* FBitmap;
	Vcl::Graphics::TBrush* FBrush;
	TdxPSFillPatternClass FPattern;
	
protected:
	void __fastcall CreatePatternBitmap(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall Initialize(bool AIsPrinting);
	
public:
	__fastcall TdxPSFillPatternItem(TdxPSFillPatternClass APattern, bool AIsPrinting);
	__fastcall virtual ~TdxPSFillPatternItem(void);
	__property Vcl::Graphics::TBitmap* Bitmap = {read=FBitmap};
	__property Vcl::Graphics::TBrush* Brush = {read=FBrush};
	__property TdxPSFillPatternClass Pattern = {read=FPattern};
};

#pragma pack(pop)

class DELPHICLASS TdxPSFillPatternFactory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFillPatternFactory : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
private:
	System::Classes::TList* FItems;
	Dxbase::TdxClassList* FPatterns;
	System::Classes::TList* FPrintItems;
	int __fastcall GetCount(void);
	TdxPSFillPatternItem* __fastcall GetInternalItem(int Index, bool IsPrinting);
	TdxPSFillPatternItem* __fastcall GetItem(TdxPSFillPatternClass Pattern, bool IsPrinting);
	TdxPSFillPatternClass __fastcall GetPattern(int Index);
	void __fastcall SetInternalItem(int Index, bool IsPrinting, TdxPSFillPatternItem* Value);
	void __fastcall AddPattern(TdxPSFillPatternClass APattern);
	void __fastcall RemovePattern(TdxPSFillPatternClass APattern);
	bool __fastcall HasItem(TdxPSFillPatternClass APattern);
	bool __fastcall HasPrintItem(TdxPSFillPatternClass APattern);
	void __fastcall RemovePatternItem(TdxPSFillPatternClass APattern);
	void __fastcall RemovePatternPrintItem(TdxPSFillPatternClass APattern);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	HIDESBASE int __fastcall IndexOf(TdxPSFillPatternClass APattern);
	__property TdxPSFillPatternItem* InternalItems[int Index][bool IsPrinting] = {read=GetInternalItem, write=SetInternalItem};
	
public:
	__classmethod TdxPSFillPatternFactory* __fastcall Instance()/* overload */;
	HIDESBASE void __fastcall Register(TdxPSFillPatternClass APattern);
	HIDESBASE void __fastcall Unregister(TdxPSFillPatternClass APattern);
	void __fastcall ResetPrintItems(void);
	__property int Count = {read=GetCount, nodefault};
	__property TdxPSFillPatternItem* Items[TdxPSFillPatternClass Pattern][bool IsPrinting] = {read=GetItem/*, default*/};
	__property TdxPSFillPatternClass Patterns[int Index] = {read=GetPattern};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSFillPatternFactory(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSFillPatternFactory(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSFillPatternFactory(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxPSFillPatternFactory* __fastcall dxPSFillPatternFactory(void);
}	/* namespace Dxpsfillpatterns */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFILLPATTERNS)
using namespace Dxpsfillpatterns;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfillpatternsHPP
