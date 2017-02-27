// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSEdgePatterns.pas' rev: 24.00 (Win32)

#ifndef DxpsedgepatternsHPP
#define DxpsedgepatternsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsedgepatterns
{
//-- type declarations -------------------------------------------------------
enum TdxPSCellEdgePatternOrientation : unsigned char { cepoHorizontal, cepoVertical };

class DELPHICLASS TdxPSEdgePattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSEdgePattern : public Dxpscore::TdxPSCustomCellBorder
{
	typedef Dxpscore::TdxPSCustomCellBorder inherited;
	
public:
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual bool __fastcall RequiredBrushOrigin();
	__classmethod virtual bool __fastcall RequiredScaling();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual bool __fastcall Solid();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSEdgePattern(void) : Dxpscore::TdxPSCustomCellBorder() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxPSEdgePatternClass;

class DELPHICLASS TdxPSSolidEdgePattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSSolidEdgePattern : public TdxPSEdgePattern
{
	typedef TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual bool __fastcall RequiredBrushOrigin();
	__classmethod virtual bool __fastcall RequiredScaling();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual bool __fastcall Solid();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSSolidEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSSolidEdgePattern(void) : TdxPSEdgePattern() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSEdgePatternItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSEdgePatternItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::StaticArray<Vcl::Graphics::TBitmap*, 2> FBitmaps;
	System::StaticArray<Vcl::Graphics::TBrush*, 2> FBrushes;
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(TdxPSCellEdgePatternOrientation Orientation);
	Vcl::Graphics::TBrush* __fastcall GetBrush(TdxPSCellEdgePatternOrientation Orientation);
	
protected:
	virtual void __fastcall Initialize(TdxPSEdgePatternClass APattern, bool AIsPrinting);
	
public:
	__fastcall TdxPSEdgePatternItem(TdxPSEdgePatternClass APattern, bool AIsPrinting);
	__fastcall virtual ~TdxPSEdgePatternItem(void);
	__property Vcl::Graphics::TBitmap* Bitmaps[TdxPSCellEdgePatternOrientation Orientation] = {read=GetBitmap};
	__property Vcl::Graphics::TBrush* Brushes[TdxPSCellEdgePatternOrientation Orientation] = {read=GetBrush};
};

#pragma pack(pop)

class DELPHICLASS TdxPSEdgePatternFactory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSEdgePatternFactory : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
private:
	System::Classes::TList* FItems;
	Dxbase::TdxClassList* FPatterns;
	System::Classes::TList* FPrintItems;
	int __fastcall GetCount(void);
	TdxPSEdgePatternItem* __fastcall GetInternalItem(int Index, bool IsPrinting);
	TdxPSEdgePatternItem* __fastcall GetItem(TdxPSEdgePatternClass Pattern, bool IsPrinting);
	TdxPSEdgePatternClass __fastcall GetPattern(int Index);
	void __fastcall SetInternalItem(int Index, bool IsPrinting, TdxPSEdgePatternItem* Value);
	void __fastcall AddPattern(TdxPSEdgePatternClass APattern);
	void __fastcall RemovePattern(TdxPSEdgePatternClass APattern);
	bool __fastcall HasItem(TdxPSEdgePatternClass APattern);
	bool __fastcall HasPrintItem(TdxPSEdgePatternClass APattern);
	void __fastcall RemovePatternItem(TdxPSEdgePatternClass APattern);
	void __fastcall RemovePatternPrintItem(TdxPSEdgePatternClass APattern);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	HIDESBASE int __fastcall IndexOf(TdxPSEdgePatternClass APattern);
	__property TdxPSEdgePatternItem* InternalItems[int Index][bool IsPrinting] = {read=GetInternalItem, write=SetInternalItem};
	
public:
	__classmethod TdxPSEdgePatternFactory* __fastcall Instance()/* overload */;
	HIDESBASE void __fastcall Register(TdxPSEdgePatternClass APattern);
	HIDESBASE void __fastcall Unregister(TdxPSEdgePatternClass APattern);
	void __fastcall ResetPrintItems(void);
	__property int Count = {read=GetCount, nodefault};
	__property TdxPSEdgePatternItem* Items[TdxPSEdgePatternClass Pattern][bool IsPrinting] = {read=GetItem/*, default*/};
	__property TdxPSEdgePatternClass Patterns[int Index] = {read=GetPattern};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSEdgePatternFactory(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSEdgePatternFactory(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSEdgePatternFactory(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxPSEdgePatternFactory* __fastcall dxPSEdgePatternFactory(void);
}	/* namespace Dxpsedgepatterns */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSEDGEPATTERNS)
using namespace Dxpsedgepatterns;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsedgepatternsHPP
