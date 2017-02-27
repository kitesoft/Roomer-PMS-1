// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxWrap.pas' rev: 24.00 (Win32)

#ifndef DxwrapHPP
#define DxwrapHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxwrap
{
//-- type declarations -------------------------------------------------------
enum TdxPointCoord : unsigned char { pcX, pcY };

typedef System::Set<TdxPointCoord, TdxPointCoord::pcX, TdxPointCoord::pcY>  TdxPointCoords;

typedef void __fastcall (__closure *TdxPointChangingEvent)(System::TObject* Sender, TdxPointCoords Coords, int *Values, const int Values_Size);

typedef void __fastcall (__closure *TdxPointChangeEvent)(System::TObject* Sender, TdxPointCoords Coords);

class DELPHICLASS TdxPointWrapper;
class PASCALIMPLEMENTATION TdxPointWrapper : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Types::TPoint FPoint;
	TdxPointChangeEvent FOnChanged;
	TdxPointChangingEvent FOnChanging;
	int __fastcall GetPartPoint(int Index);
	void __fastcall SetPartPoint(int Index, int Value);
	void __fastcall SetPoint(const System::Types::TPoint &Value);
	
protected:
	DYNAMIC void __fastcall DoChanged(TdxPointCoords ACoords);
	DYNAMIC void __fastcall DoChanging(TdxPointCoords ACoords, int *AValues, const int AValues_Size);
	
public:
	__fastcall TdxPointWrapper(int AX, int AY);
	__fastcall TdxPointWrapper(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::Classes::TPersistent* __fastcall Clone(void);
	void __fastcall Empty(void);
	bool __fastcall IsEqual(const System::Types::TPoint &APoint);
	__classmethod bool __fastcall ArePointsEqual(const System::Types::TPoint &Pt1, const System::Types::TPoint &Pt2);
	__property System::Types::TPoint Point = {read=FPoint, write=SetPoint};
	__property TdxPointChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TdxPointChangeEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property int X = {read=GetPartPoint, write=SetPartPoint, index=0, default=0};
	__property int Y = {read=GetPartPoint, write=SetPartPoint, index=1, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPointWrapper(void) { }
	
};


enum TdxRectSide : unsigned char { rsLeft, rsTop, rsRight, rsBottom };

typedef System::Set<TdxRectSide, TdxRectSide::rsLeft, TdxRectSide::rsBottom>  TdxRectSides;

typedef void __fastcall (__closure *TdxRectChangingEvent)(System::TObject* Sender, TdxRectSides Sides, int *Values, const int Values_Size);

typedef void __fastcall (__closure *TdxRectChangeEvent)(System::TObject* Sender, TdxRectSides Sides);

class DELPHICLASS TdxRectWrapper;
class PASCALIMPLEMENTATION TdxRectWrapper : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	int operator[](TdxRectSide ASide) { return Side[ASide]; }
	
private:
	System::Types::TRect FRect;
	TdxRectChangeEvent FOnChanged;
	TdxRectChangingEvent FOnChanging;
	int __fastcall GetHeight(void);
	int __fastcall GetPartRect(int Index);
	System::Types::TPoint __fastcall GetRectPoint(int Index);
	int __fastcall GetSide(TdxRectSide ASide);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(int Value);
	void __fastcall SetPartRect(int Index, int Value);
	void __fastcall SetRect(const System::Types::TRect &Value);
	void __fastcall SetRectPoint(int Index, const System::Types::TPoint &Value);
	void __fastcall SetSide(TdxRectSide ASide, int Value);
	void __fastcall SetWidth(int Value);
	
protected:
	DYNAMIC void __fastcall DoChanged(TdxRectSides ASides);
	DYNAMIC void __fastcall DoChanging(TdxRectSides ASides, int *AValues, const int AValues_Size);
	
public:
	__fastcall TdxRectWrapper(int ALeft, int ATop, int ARight, int ABottom);
	__fastcall TdxRectWrapper(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::Classes::TPersistent* __fastcall Clone(void);
	void __fastcall Empty(void);
	bool __fastcall IsEqual(const System::Types::TRect &ARect);
	bool __fastcall IsEmpty(bool AnExact = false);
	__property System::Types::TPoint BottomRight = {read=GetRectPoint, write=SetRectPoint, index=1};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property System::Types::TRect Rect = {read=FRect, write=SetRect};
	__property int Side[TdxRectSide ASide] = {read=GetSide, write=SetSide/*, default*/};
	__property System::Types::TPoint TopLeft = {read=GetRectPoint, write=SetRectPoint, index=0};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property TdxRectChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TdxRectChangeEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property int Bottom = {read=GetPartRect, write=SetPartRect, index=3, default=0};
	__property int Left = {read=GetPartRect, write=SetPartRect, index=0, default=0};
	__property int Right = {read=GetPartRect, write=SetPartRect, index=2, default=0};
	__property int Top = {read=GetPartRect, write=SetPartRect, index=1, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRectWrapper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxwrap */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXWRAP)
using namespace Dxwrap;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxwrapHPP
