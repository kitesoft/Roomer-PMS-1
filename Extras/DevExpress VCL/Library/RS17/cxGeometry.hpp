// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGeometry.pas' rev: 24.00 (Win32)

#ifndef CxgeometryHPP
#define CxgeometryHPP

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
#include <System.Math.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgeometry
{
//-- type declarations -------------------------------------------------------
enum TcxPtInRectType : unsigned char { ptrtNone, ptrtArea, ptrtLeft, ptrtTop, ptrtRight, ptrtBottom };

struct DECLSPEC_DRECORD TdxSector
{
public:
	float StartAngle;
	float SweepAngle;
};


struct DECLSPEC_DRECORD TdxPointF
{
public:
	float X;
	float Y;
};


struct DECLSPEC_DRECORD TdxSizeF
{
public:
	float cx;
	float cy;
};


class DELPHICLASS TcxGeometryObject;
class PASCALIMPLEMENTATION TcxGeometryObject : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Classes::TNotifyEvent FOnChange;
	
protected:
	virtual void __fastcall DoChange(void);
	
public:
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxGeometryObject(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxOwnedPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGeometryObject(void) { }
	
};


class DELPHICLASS TcxRect;
class PASCALIMPLEMENTATION TcxRect : public TcxGeometryObject
{
	typedef TcxGeometryObject inherited;
	
private:
	System::Types::TRect FRect;
	int __fastcall GetHeight(void);
	System::Types::TPoint __fastcall GetVertex(int AIndex);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(int AValue);
	void __fastcall SetRect(const System::Types::TRect &AValue);
	void __fastcall SetVertex(int AIndex, const System::Types::TPoint &AValue);
	void __fastcall SetWidth(int AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall ValidateRect(System::Types::TRect &R);
	
public:
	int __fastcall GetValue(int AIndex);
	void __fastcall SetValue(int AIndex, int AValue);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	bool __fastcall IsEmpty(void);
	bool __fastcall IsEqual(const System::Types::TRect &ARect)/* overload */;
	bool __fastcall IsEqual(TcxRect* ARect)/* overload */;
	__property System::Types::TPoint BottomLeft = {read=GetVertex, write=SetVertex, index=2};
	__property System::Types::TPoint BottomRight = {read=GetVertex, write=SetVertex, index=3};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property System::Types::TRect Rect = {read=FRect, write=SetRect};
	__property System::Types::TPoint TopLeft = {read=GetVertex, write=SetVertex, index=0};
	__property System::Types::TPoint TopRight = {read=GetVertex, write=SetVertex, index=1};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	
__published:
	__property int Left = {read=GetValue, write=SetValue, index=0, default=0};
	__property int Top = {read=GetValue, write=SetValue, index=1, default=0};
	__property int Right = {read=GetValue, write=SetValue, index=2, default=0};
	__property int Bottom = {read=GetValue, write=SetValue, index=3, default=0};
	__property OnChange;
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxRect(System::Classes::TPersistent* AOwner) : TcxGeometryObject(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxRect(void) { }
	
};


class DELPHICLASS TcxSize;
class PASCALIMPLEMENTATION TcxSize : public TcxGeometryObject
{
	typedef TcxGeometryObject inherited;
	
private:
	System::Types::TSize __fastcall GetSize(void);
	void __fastcall SetValue(int Index, int Value);
	
protected:
	System::Types::TSize FSize;
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual int __fastcall GetValue(int Index);
	virtual bool __fastcall IsSizeStored(int Index);
	virtual void __fastcall SetSize(const System::Types::TSize &Value);
	
public:
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	bool __fastcall IsEmpty(void);
	bool __fastcall IsEqual(const System::Types::TSize &ASize)/* overload */;
	bool __fastcall IsEqual(TcxSize* ASize)/* overload */;
	__property System::Types::TSize Size = {read=GetSize, write=SetSize};
	
__published:
	__property int Height = {read=GetValue, write=SetValue, stored=IsSizeStored, index=0, nodefault};
	__property int Width = {read=GetValue, write=SetValue, stored=IsSizeStored, index=1, nodefault};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxSize(System::Classes::TPersistent* AOwner) : TcxGeometryObject(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSize(void) { }
	
};


class DELPHICLASS TcxMargin;
class PASCALIMPLEMENTATION TcxMargin : public TcxGeometryObject
{
	typedef TcxGeometryObject inherited;
	
private:
	int FDefaultValue;
	System::Types::TRect FMargin;
	int __fastcall GetValue(int AIndex);
	bool __fastcall IsMarginStored(int AIndex);
	void __fastcall SetMargin(const System::Types::TRect &Value);
	void __fastcall SetValue(int AIndex, int AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall TcxMargin(System::Classes::TPersistent* AOwner, int ADefaultValue);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	bool __fastcall IsEqual(TcxMargin* AMargin);
	__property System::Types::TRect Margin = {read=FMargin, write=SetMargin};
	
__published:
	__property int All = {read=GetValue, write=SetValue, stored=IsMarginStored, index=0, nodefault};
	__property int Left = {read=GetValue, write=SetValue, stored=IsMarginStored, index=1, nodefault};
	__property int Top = {read=GetValue, write=SetValue, stored=IsMarginStored, index=2, nodefault};
	__property int Right = {read=GetValue, write=SetValue, stored=IsMarginStored, index=3, nodefault};
	__property int Bottom = {read=GetValue, write=SetValue, stored=IsMarginStored, index=4, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxMargin(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Types::TRect cxInvalidRect;
extern PACKAGE System::Types::TRect cxSimpleRect;
extern PACKAGE System::Types::TPoint cxInvalidPoint;
extern PACKAGE System::Types::TPoint cxSimplePoint;
extern PACKAGE System::Types::TPoint cxInvisiblePoint;
extern PACKAGE System::Types::TRect cxNullRect;
extern PACKAGE System::Types::TSize cxNullSize;
extern PACKAGE System::Types::TPoint cxNullPoint;
extern PACKAGE int __fastcall cxHalfCoordinate(int ASize);
extern PACKAGE int __fastcall cxRectHeight(const System::Types::TRect &R);
extern PACKAGE bool __fastcall cxRectIntersect(const System::Types::TRect &R1, const System::Types::TRect &R2)/* overload */;
extern PACKAGE bool __fastcall cxRectIntersect(/* out */ System::Types::TRect &R, const System::Types::TRect &R1, const System::Types::TRect &R2)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectInflate(const System::Types::TRect &R, int DX, int DY)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectInflate(const System::Types::TRect &R, int DX1, int DY1, int DX2, int DY2)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectInflate(const System::Types::TRect &R, const System::Types::TRect &AMargins)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectInvert(const System::Types::TRect &R);
extern PACKAGE bool __fastcall cxRectIsEmpty(const System::Types::TRect &R);
extern PACKAGE bool __fastcall cxRectIsEqual(const System::Types::TRect &R, const System::Types::TRect &R1);
extern PACKAGE bool __fastcall cxRectIsInvalid(const System::Types::TRect &R);
extern PACKAGE bool __fastcall cxRectIsNull(const System::Types::TRect &R);
extern PACKAGE int __fastcall cxRectGetItem(const System::Types::TRect &ARect, int AIndex);
extern PACKAGE int __fastcall cxRectGetSize(const System::Types::TRect &ARect, int AIndex);
extern PACKAGE System::Types::TPoint __fastcall cxRectLeftBottom(const System::Types::TRect &R);
extern PACKAGE void __fastcall cxRectMinMaxHeight(const System::Types::TRect &R, int &AMax, int &AMin);
extern PACKAGE void __fastcall cxRectMinMaxInit(int &AMin, int &AMax);
extern PACKAGE void __fastcall cxRectMinMaxWidth(const System::Types::TRect &R, int &AMax, int &AMin);
extern PACKAGE System::Types::TRect __fastcall cxRectOffset(const System::Types::TRect &R, const System::Types::TPoint &P, bool APositiveFactor = true)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectOffset(const System::Types::TRect &R, int DX, int DY, bool APositiveFactor = true)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectOffset(const System::Types::TRect &R, System::Types::TPoint const *Ps, const int Ps_Size, bool APositiveFactor = true)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectOffsetHorz(const System::Types::TRect &R, int DX);
extern PACKAGE System::Types::TRect __fastcall cxRectOffsetVert(const System::Types::TRect &R, int DY);
extern PACKAGE void __fastcall cxRectOverlapped(const System::Types::TRect &ASrc, const System::Types::TRect &ADst, /* out */ System::Types::TRect &ASrcH, /* out */ System::Types::TRect &ASrcV, /* out */ System::Types::TRect &ADstH, /* out */ System::Types::TRect &ADstV);
extern PACKAGE bool __fastcall cxRectPtIn(const System::Types::TRect &R, const System::Types::TPoint &P)/* overload */;
extern PACKAGE bool __fastcall cxRectPtIn(const System::Types::TRect &R, const int X, const int Y)/* overload */;
extern PACKAGE TcxPtInRectType __fastcall cxRectPtInEx(const System::Types::TRect &R, const int X, const int Y, int DL, int DT, int DR, int DB)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectRotate(const System::Types::TRect &R);
extern PACKAGE TcxPtInRectType __fastcall cxRectPtInEx(const System::Types::TRect &R, int X, int Y, int ADelta)/* overload */;
extern PACKAGE TcxPtInRectType __fastcall cxRectPtInEx(const System::Types::TRect &R, int X, int Y, int ADeltaX, int ADeltaY)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRect(const System::Types::TSize &ASize)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRect(const int ALeft, const int ATop, const int ARight, const int ABottom)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRect(const System::Types::TPoint &ATopLeft, const System::Types::TPoint &ABottomRight)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectAdjust(const System::Types::TRect &R);
extern PACKAGE System::Types::TRect __fastcall cxRectBounds(int ALeft, int ATop, int AWidth, int AHeight)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectBounds(const System::Types::TPoint &P, int AWidth, int AHeight)/* overload */;
extern PACKAGE System::Types::TPoint __fastcall cxRectRightTop(const System::Types::TRect &R);
extern PACKAGE System::Types::TRect __fastcall cxRectScale(const System::Types::TRect &R, int ANumerator, int ADenominator)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectScale(const System::Types::TRect &R, int ANumeratorX, int ADenominatorX, int ANumeratorY, int ADenominatorY)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectScaleHeight(const System::Types::TRect &R, int Y1, int Y2, int H1, int H2);
extern PACKAGE System::Types::TRect __fastcall cxRectScaleWidth(const System::Types::TRect &R, int X1, int X2, int W1, int W2);
extern PACKAGE System::Types::TRect __fastcall cxRectSetBottom(const System::Types::TRect &R, int Y)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetBottom(const System::Types::TRect &R, int Y, int H)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetHeight(const System::Types::TRect &R, int H);
extern PACKAGE System::Types::TRect __fastcall cxRectSetLeft(const System::Types::TRect &R, int X)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetLeft(const System::Types::TRect &R, int X, int W)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetOrigin(const System::Types::TRect &R, const System::Types::TPoint &APos);
extern PACKAGE System::Types::TRect __fastcall cxRectSetNullOrigin(const System::Types::TRect &R);
extern PACKAGE System::Types::TRect __fastcall cxRectSetTop(const System::Types::TRect &R, int Y)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetTop(const System::Types::TRect &R, int Y, int H)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetRight(const System::Types::TRect &R, int X)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetRight(const System::Types::TRect &R, int X, int W)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetSize(const System::Types::TRect &R, int W, int H)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetSize(const System::Types::TRect &R, const System::Types::TSize &ASize)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetWidth(const System::Types::TRect &R, int W)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetWidth(const System::Types::TRect &R, int X, int W)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectSetXPos(const System::Types::TRect &R, int X1, int X2);
extern PACKAGE System::Types::TRect __fastcall cxRectSetYPos(const System::Types::TRect &R, int Y1, int Y2);
extern PACKAGE System::Types::TSize __fastcall cxRectSize(const System::Types::TRect &R);
extern PACKAGE void __fastcall cxRectSplitHorz(const System::Types::TRect &ABounds, System::Types::TRect &ARect1, System::Types::TRect &ARect2);
extern PACKAGE int __fastcall cxRectSquare(const System::Types::TRect &R);
extern PACKAGE void __fastcall cxRectSplitVert(const System::Types::TRect &ABounds, System::Types::TRect &ARect1, System::Types::TRect &ARect2);
extern PACKAGE System::Types::TRect __fastcall cxRectTransform(const System::Types::TRect &ARect, int ALeftOffset, int ATopOffset, int ARightOffset, int ABottomOffset)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectTransform(const System::Types::TRect &ARect, const System::Types::TRect &AOffsets)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectUnion(const System::Types::TRect &R1, const System::Types::TRect &R2);
extern PACKAGE int __fastcall cxRectWidth(const System::Types::TRect &R);
extern PACKAGE System::Types::TRect __fastcall cxRectProportionalStretch(const System::Types::TRect &R, const System::Types::TSize &ASize)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectProportionalStretch(const System::Types::TRect &R, int W, int H)/* overload */;
extern PACKAGE int __fastcall cxMarginsHeight(const System::Types::TRect &R);
extern PACKAGE int __fastcall cxMarginsWidth(const System::Types::TRect &R);
extern PACKAGE bool __fastcall cxRectCompare(const System::Types::TRect &R1, const System::Types::TRect &R2);
extern PACKAGE System::Types::TPoint __fastcall cxRectCenter(const System::Types::TRect &R)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectCenter(const System::Types::TRect &ABounds, const System::Types::TSize &ASize)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectCenter(const System::Types::TRect &ABounds, int AWidth, int AHeight)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxRectCenterHorizontally(const System::Types::TRect &R, int AWidth);
extern PACKAGE System::Types::TRect __fastcall cxRectCenterVertically(const System::Types::TRect &R, int AHeight);
extern PACKAGE bool __fastcall cxRectContain(const System::Types::TRect &ABounds, const System::Types::TRect &AInner);
extern PACKAGE System::Types::TRect __fastcall cxRectContent(const System::Types::TRect &R, const System::Types::TRect &AMargins);
extern PACKAGE System::Types::TPoint __fastcall cxPointInvert(const System::Types::TPoint &P)/* overload */;
extern PACKAGE bool __fastcall cxPointIsEqual(const System::Types::TPoint &P1, const System::Types::TPoint &P2);
extern PACKAGE bool __fastcall cxPointIsInvalid(const System::Types::TPoint &P);
extern PACKAGE bool __fastcall cxPointIsNull(const System::Types::TPoint &P)/* overload */;
extern PACKAGE int __fastcall cxPointGetItem(const System::Types::TPoint &P, int AIndex);
extern PACKAGE System::Types::TPoint __fastcall cxPointOffset(const System::Types::TPoint &P, System::Types::TPoint const *Ps, const int Ps_Size, bool APositiveFactor = true)/* overload */;
extern PACKAGE System::Types::TPoint __fastcall cxPointOffset(const System::Types::TPoint &P, int X, int Y, bool APositiveFactor = true)/* overload */;
extern PACKAGE System::Types::TPoint __fastcall cxPointOffset(const System::Types::TPoint &P, const System::Types::TPoint &DP, bool APositiveFactor = true)/* overload */;
extern PACKAGE System::Types::TPoint __fastcall cxPointReplaceItem(const System::Types::TPoint &P, const int AIndex, const int AValue);
extern PACKAGE System::Types::TPoint __fastcall cxPoint(int X, int Y)/* overload */;
extern PACKAGE System::Types::TPoint __fastcall cxPoint(const System::Types::TSize &ASize)/* overload */;
extern PACKAGE System::Types::TPoint __fastcall cxPointSum(System::Types::TPoint const *Ps, const int Ps_Size);
extern PACKAGE System::Types::TRect __fastcall cxPointsBox(System::Types::TPoint const *Ps, const int Ps_Size);
extern PACKAGE void __fastcall cxPointsOffset(System::Types::TPoint *Ps, const int Ps_Size, int DX, int DY)/* overload */;
extern PACKAGE void __fastcall cxPointsOffset(System::Types::TPoint *Ps, const int Ps_Size, const System::Types::TPoint &AOffset)/* overload */;
extern PACKAGE System::Types::TSize __fastcall cxSize(int DX, int DY)/* overload */;
extern PACKAGE System::Types::TSize __fastcall cxSize(const System::Types::TPoint &P)/* overload */;
extern PACKAGE System::Types::TSize __fastcall cxSize(const System::Types::TRect &R)/* overload */;
extern PACKAGE bool __fastcall cxSizeIsEmpty(const System::Types::TSize &S1);
extern PACKAGE bool __fastcall cxSizeIsEqual(const System::Types::TSize &S1, const System::Types::TSize &S2);
extern PACKAGE System::Types::TSize __fastcall cxSizeMax(const System::Types::TSize &S1, const System::Types::TSize &S2);
extern PACKAGE TdxPointF __fastcall dxPointF(float X, float Y)/* overload */;
extern PACKAGE TdxPointF __fastcall dxPointF(const System::Types::TPoint &P)/* overload */;
extern PACKAGE TdxSizeF __fastcall dxSizeF(float DX, float DY);
extern PACKAGE float __fastcall dxPointDistance(const TdxPointF &P1, const TdxPointF &P2);
extern PACKAGE TdxPointF __fastcall dxPointOffset(const TdxPointF &P, const TdxPointF &AOffset)/* overload */;
extern PACKAGE void __fastcall dxPointsOffset(TdxPointF *Ps, const int Ps_Size, const TdxPointF &AOffset)/* overload */;
extern PACKAGE bool __fastcall dxRingPtIn(const System::Types::TRect &ARingRect, const System::Types::TPoint &P);
extern PACKAGE float __fastcall dxRingAngle(const TdxPointF &ABase, const TdxPointF &APoint);
extern PACKAGE TdxPointF __fastcall dxRingPoint(const TdxPointF &ABase, float ARadius, float AAngle);
extern PACKAGE TdxPointF __fastcall dxRingRelativePoint(const TdxPointF &ABase, const TdxPointF &APoint);
extern PACKAGE TdxPointF __fastcall dxRingRotatePoint(const TdxPointF &ABase, const TdxPointF &APoint, float AAngle);
extern PACKAGE void __fastcall dxRingRotatePoints(const TdxPointF &ABase, TdxPointF *APoints, const int APoints_Size, float AAngle);
}	/* namespace Cxgeometry */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGEOMETRY)
using namespace Cxgeometry;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgeometryHPP
