// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLines.pas' rev: 24.00 (Win32)

#ifndef DxlinesHPP
#define DxlinesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlines
{
//-- type declarations -------------------------------------------------------
enum TLineType : unsigned char { liStraight, liQSpline, liRectH, liRectV };

typedef System::StaticArray<System::Types::TPoint, 16777216> TdxFCPointArray;

typedef TdxFCPointArray *PdxFCPointArray;

class DELPHICLASS TdxFcLinesHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFcLinesHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	__classmethod Cxgraphics::TcxBorders __fastcall CheckPointOutside(const System::Types::TPoint &P, const System::Types::TRect &R);
	__classmethod int __fastcall PartLengthQSpline(PdxFCPointArray P, int I, int ACount, System::Types::PPoint ACenter);
	__classmethod int __fastcall PartLengthRect(PdxFCPointArray P, int I, int ACount, System::Types::PPoint ACenter, bool AHorizontal);
	__classmethod int __fastcall PartLengthStraight(PdxFCPointArray P, int I, int ACount, System::Types::PPoint ACenter);
	__classmethod void __fastcall QSplineCalcPart(System::Types::TPoint &P0, System::Types::TPoint &P1, System::Types::TPoint &P2, bool AIsLast, Cxgraphics::TPointArray &ASplinePoints, int &ASplinePointsCount);
	
public:
	__classmethod bool __fastcall IsLineInRect(const System::Types::TPoint &P1, const System::Types::TPoint &P2, const System::Types::TRect &R);
	__classmethod bool __fastcall IsPointOnLine(TLineType ALineType, PdxFCPointArray APoints, int ACount, int ASigma, const System::Types::TPoint &P);
	__classmethod bool __fastcall IsRectOnLine(TLineType ALineType, PdxFCPointArray APoints, int ACount, const System::Types::TRect &R);
	__classmethod System::Types::TPoint __fastcall LineCenter(TLineType ALineType, PdxFCPointArray APoints, int ACount);
	__classmethod int __fastcall PartDistance(const System::Types::TPoint &PS, const System::Types::TPoint &PE, const System::Types::TPoint &Src);
	__classmethod int __fastcall PartLength(TLineType ALineType, PdxFCPointArray APoints, int I, int ACount, System::Types::PPoint ACenter);
	__classmethod void __fastcall QSpline(PdxFCPointArray APoints, int ACount, /* out */ Cxgraphics::TPointArray &ASplinePoints);
public:
	/* TObject.Create */ inline __fastcall TdxFcLinesHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFcLinesHelper(void) { }
	
};

#pragma pack(pop)

typedef System::StaticArray<System::Types::TPoint, 1> TdxFcPointList;

typedef TdxFcPointList *PdxFcPointList;

class DELPHICLASS TdxFcPoints;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFcPoints : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TPoint operator[](int Index) { return Points[Index]; }
	
private:
	int FCapacity;
	int FCount;
	TdxFcPointList *FList;
	System::Types::TPoint __fastcall GetPoint(int Index);
	void __fastcall SetPoint(int Index, const System::Types::TPoint &P);
	
protected:
	void __fastcall Grow(void);
	__property int Capacity = {read=FCapacity, nodefault};
	
public:
	__fastcall virtual ~TdxFcPoints(void);
	void __fastcall Add(const System::Types::TPoint &P);
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	void __fastcall Insert(int AIndex, const System::Types::TPoint &P);
	void __fastcall CalculatePolyline(TLineType ALineType, /* out */ Cxgraphics::TPointArray &P);
	System::Types::TPoint __fastcall GetLineCenter(TLineType ALineType);
	int __fastcall GetNearestPointIndex(const System::Types::TPoint &P);
	bool __fastcall IsPointOnLine(TLineType ALineType, const System::Types::TPoint &P);
	bool __fastcall IsRectOnLine(TLineType ALineType, const System::Types::TRect &R);
	bool __fastcall IsValidIndex(int Index);
	void __fastcall OffsetPoints(int DX, int DY);
	__property int Count = {read=FCount, nodefault};
	__property PdxFcPointList List = {read=FList};
	__property System::Types::TPoint Points[int Index] = {read=GetPoint, write=SetPoint/*, default*/};
public:
	/* TObject.Create */ inline __fastcall TdxFcPoints(void) : System::TObject() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ExtendRect(System::Types::TRect &R, const System::Types::TPoint &P);
extern PACKAGE int __fastcall Distance(const System::Types::TPoint &A, const System::Types::TPoint &B);
extern PACKAGE int __fastcall QDistance(int X, int Y, const System::Types::TPoint &P);
extern PACKAGE System::Types::TPoint __fastcall LineCenter(TLineType AType, void *APoints, int ACount);
extern PACKAGE int __fastcall PointIndex(void);
extern PACKAGE bool __fastcall PtOnLine(TLineType LType, void *Points, int Count, int Delta, int X, int Y);
extern PACKAGE bool __fastcall RectOnLine(TLineType LType, void *Points, int Count, const System::Types::TRect &R);
}	/* namespace Dxlines */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLINES)
using namespace Dxlines;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlinesHPP
