// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVGridUtils.pas' rev: 24.00 (Win64)

#ifndef CxvgridutilsHPP
#define CxvgridutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvgridutils
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDataList;
class PASCALIMPLEMENTATION TcxDataList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FAllocated;
	void *FData;
	int FDelta;
	int FRecordSize;
	
protected:
	int FCount;
	void __fastcall CheckCapacity(void);
	void * __fastcall Get(int Index);
	__property void * Data = {read=FData};
	__property int RecordSize = {read=FRecordSize, nodefault};
	
public:
	__fastcall TcxDataList(int ARecordSize);
	__fastcall virtual ~TcxDataList(void);
	void __fastcall Clear(void);
	__property int Count = {read=FCount, nodefault};
	__property int Delta = {read=FDelta, write=FDelta, nodefault};
};


class DELPHICLASS TcxRectList;
class PASCALIMPLEMENTATION TcxRectList : public TcxDataList
{
	typedef TcxDataList inherited;
	
public:
	System::Types::TRect operator[](int Index) { return Rects[Index]; }
	
private:
	System::Types::TRect __fastcall GetRect(int Index);
	void __fastcall SetRect(int Index, const System::Types::TRect &Value);
	
public:
	__fastcall TcxRectList(void);
	void __fastcall Assign(TcxRectList* Source);
	int __fastcall Add(const System::Types::TRect &R);
	__property System::Types::TRect Rects[int Index] = {read=GetRect, write=SetRect/*, default*/};
public:
	/* TcxDataList.Destroy */ inline __fastcall virtual ~TcxRectList(void) { }
	
};


struct TScaleParams;
typedef TScaleParams *PScaleParams;

struct DECLSPEC_DRECORD TScaleParams
{
public:
	int Width;
	int MinWidth;
	int FixedWidth;
};


class DELPHICLASS TRectScaler;
class PASCALIMPLEMENTATION TRectScaler : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	TcxRectList* FScaledRects;
	TScaleParams __fastcall GetSummaryParam(void);
	
public:
	__fastcall TRectScaler(void);
	__fastcall virtual ~TRectScaler(void);
	HIDESBASE void __fastcall Add(int AWidth)/* overload */;
	HIDESBASE void __fastcall Add(int AWidth, int AMinWidth)/* overload */;
	HIDESBASE void __fastcall Add(int AWidth, int AMinWidth, int AFixedWidth)/* overload */;
	virtual void __fastcall Clear(void);
	void __fastcall CalcRect(const System::Types::TRect &Rect);
	void __fastcall ScaleRect(const System::Types::TRect &Rect);
	__property TcxRectList* ScaledRects = {read=FScaledRects};
	__property TScaleParams SummaryParam = {read=GetSummaryParam};
};


struct TLineInfo;
typedef TLineInfo *PLineInfo;

struct DECLSPEC_DRECORD TLineInfo
{
public:
	System::Types::TRect Rect;
	bool IsBrush;
	#pragma pack(push,1)
	union
	{
		struct 
		{
			unsigned:32;
			unsigned:24;
			Vcl::Graphics::TBrush* Brush;
		};
		struct 
		{
			unsigned:32;
			unsigned:24;
			System::Uitypes::TColor Color;
		};
		
	};
	#pragma pack(pop)
};


class DELPHICLASS TLineInfoList;
class PASCALIMPLEMENTATION TLineInfoList : public TcxDataList
{
	typedef TcxDataList inherited;
	
public:
	PLineInfo operator[](int Index) { return Items[Index]; }
	
private:
	bool FLocked;
	PLineInfo __fastcall GetItem(int Index);
	
public:
	__fastcall TLineInfoList(void);
	int __fastcall Add(const System::Types::TRect &ARect, Vcl::Graphics::TBrush* ABrush)/* overload */;
	int __fastcall Add(const System::Types::TRect &ARect, System::Uitypes::TColor AColor)/* overload */;
	int __fastcall Add(int X, int Y, int AWidth, int AHeight, Vcl::Graphics::TBrush* ABrush)/* overload */;
	int __fastcall Add(int X, int Y, int AWidth, int AHeight, System::Uitypes::TColor AColor)/* overload */;
	__property PLineInfo Items[int Index] = {read=GetItem/*, default*/};
	__property bool Locked = {read=FLocked, write=FLocked, nodefault};
public:
	/* TcxDataList.Destroy */ inline __fastcall virtual ~TLineInfoList(void) { }
	
};


struct TIndentInfo;
typedef TIndentInfo *PIndentInfo;

struct DECLSPEC_DRECORD TIndentInfo
{
public:
	System::Types::TRect Bounds;
	Cxgraphics::TcxViewParams ViewParams;
};


class DELPHICLASS TIndentInfoList;
class PASCALIMPLEMENTATION TIndentInfoList : public TcxDataList
{
	typedef TcxDataList inherited;
	
public:
	PIndentInfo operator[](int Index) { return Items[Index]; }
	
private:
	PIndentInfo __fastcall GetItem(int Index);
	
public:
	__fastcall TIndentInfoList(void);
	int __fastcall Add(const System::Types::TRect &ABounds, const Cxgraphics::TcxViewParams &AViewParams);
	__property PIndentInfo Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxDataList.Destroy */ inline __fastcall virtual ~TIndentInfoList(void) { }
	
};


struct TIndentRectInfo;
typedef TIndentRectInfo *PIndentRectInfo;

struct DECLSPEC_DRECORD TIndentRectInfo
{
public:
	bool IsCategory;
	System::Types::TSize Size;
	Cxgraphics::TcxViewParams ViewParams;
	bool Underline;
};


class DELPHICLASS TIndentRectInfoList;
class PASCALIMPLEMENTATION TIndentRectInfoList : public TcxDataList
{
	typedef TcxDataList inherited;
	
public:
	PIndentRectInfo operator[](int Index) { return Items[Index]; }
	
private:
	PIndentRectInfo __fastcall GetItem(int Index);
	
public:
	__fastcall TIndentRectInfoList(void);
	int __fastcall Add(const System::Types::TSize ASize, bool AIsCategory, bool AUnderline, const Cxgraphics::TcxViewParams &AViewParams);
	__property PIndentRectInfo Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxDataList.Destroy */ inline __fastcall virtual ~TIndentRectInfoList(void) { }
	
};


class DELPHICLASS TViewRects;
class PASCALIMPLEMENTATION TViewRects : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxRectList* BandRects;
	TcxRectList* EmptyRects;
	__fastcall TViewRects(void);
	__fastcall virtual ~TViewRects(void);
	void __fastcall Clear(void);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall Max(int A, int B);
extern PACKAGE int __fastcall Min(int A, int B);
extern PACKAGE Vcl::Graphics::TBrush* __fastcall cxCreateHalftoneBrush(System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2);
}	/* namespace Cxvgridutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVGRIDUTILS)
using namespace Cxvgridutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvgridutilsHPP
