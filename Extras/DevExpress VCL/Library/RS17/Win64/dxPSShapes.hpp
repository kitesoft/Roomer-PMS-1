// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSShapes.pas' rev: 24.00 (Win64)

#ifndef DxpsshapesHPP
#define DxpsshapesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsshapes
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxReportCellShapeClass;

class DELPHICLASS TdxPSShapeFactory;
class PASCALIMPLEMENTATION TdxPSShapeFactory : public Dxbase::TdxCustomClassFactory
{
	typedef Dxbase::TdxCustomClassFactory inherited;
	
public:
	TdxReportCellShapeClass operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxReportCellShapeClass __fastcall GetItem(int Index);
	
public:
	__classmethod TdxPSShapeFactory* __fastcall Instance()/* overload */;
	void __fastcall GetList(System::Classes::TStrings* const AStrings);
	__property TdxReportCellShapeClass Items[int Index] = {read=GetItem/*, default*/};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSShapeFactory(int Dummy) : Dxbase::TdxCustomClassFactory(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSShapeFactory(void) : Dxbase::TdxCustomClassFactory() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSShapeFactory(void) { }
	
};


class DELPHICLASS TCustomdxReportCellShape;
class PASCALIMPLEMENTATION TCustomdxReportCellShape : public Dxpscore::TAbstractdxReportCellData
{
	typedef Dxpscore::TAbstractdxReportCellData inherited;
	
private:
	System::Uitypes::TColor FContentBkColor;
	Dxpsfillpatterns::TdxPSFillPatternClass FContentPattern;
	System::Uitypes::TColor FShapeBorderColor;
	int FShapeBorderThickness;
	System::Uitypes::TColor FShapeColor;
	bool __fastcall GetShapeTransparent(void);
	void __fastcall SetShapeBorderThickness(int Value);
	void __fastcall SetShapeTransparent(bool Value);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetContentBkColor(void);
	virtual Dxpsfillpatterns::TdxPSFillPatternClass __fastcall GetContentPattern(void);
	virtual void __fastcall SetContentBkColor(System::Uitypes::TColor Value);
	virtual void __fastcall SetContentPattern(Dxpsfillpatterns::TdxPSFillPatternClass Value);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	virtual System::Types::TPoint __fastcall GetShapeCenter(void);
	virtual int __fastcall GetShapeHeight(void);
	virtual System::Types::TRect __fastcall GetShapeRect(void);
	virtual int __fastcall GetShapeWidth(void);
	
public:
	__fastcall virtual TCustomdxReportCellShape(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual void __fastcall RegisterShape();
	__classmethod virtual void __fastcall UnregisterShape();
	__property System::Uitypes::TColor ShapeBorderColor = {read=FShapeBorderColor, write=FShapeBorderColor, nodefault};
	__property int ShapeBorderThickness = {read=FShapeBorderThickness, write=SetShapeBorderThickness, nodefault};
	__property System::Types::TPoint ShapeCenter = {read=GetShapeCenter};
	__property System::Uitypes::TColor ShapeColor = {read=FShapeColor, write=FShapeColor, nodefault};
	__property int ShapeHeight = {read=GetShapeHeight, nodefault};
	__property System::Types::TRect ShapeRect = {read=GetShapeRect};
	__property bool ShapeTransparent = {read=GetShapeTransparent, write=SetShapeTransparent, nodefault};
	__property int ShapeWidth = {read=GetShapeWidth, nodefault};
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TCustomdxReportCellShape(void) { }
	
};


class DELPHICLASS TCustomdxReportCellEllipseShape;
class PASCALIMPLEMENTATION TCustomdxReportCellEllipseShape : public TCustomdxReportCellShape
{
	typedef TCustomdxReportCellShape inherited;
	
private:
	int __fastcall GetRadiusHorz(void);
	int __fastcall GetRadiusVert(void);
	
protected:
	__property int RadiusHorz = {read=GetRadiusHorz, nodefault};
	__property int RadiusVert = {read=GetRadiusVert, nodefault};
	
public:
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
public:
	/* TCustomdxReportCellShape.Create */ inline __fastcall virtual TCustomdxReportCellEllipseShape(Dxpscore::TdxReportCell* AParent) : TCustomdxReportCellShape(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TCustomdxReportCellEllipseShape(void) { }
	
};


class DELPHICLASS TdxReportCellEllipse;
class PASCALIMPLEMENTATION TdxReportCellEllipse : public TCustomdxReportCellEllipseShape
{
	typedef TCustomdxReportCellEllipseShape inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall Name();
	__property RadiusHorz;
	__property RadiusVert;
public:
	/* TCustomdxReportCellShape.Create */ inline __fastcall virtual TdxReportCellEllipse(Dxpscore::TdxReportCell* AParent) : TCustomdxReportCellEllipseShape(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellEllipse(void) { }
	
};


class DELPHICLASS TdxReportCellCircle;
class PASCALIMPLEMENTATION TdxReportCellCircle : public TCustomdxReportCellEllipseShape
{
	typedef TCustomdxReportCellEllipseShape inherited;
	
private:
	int __fastcall GetRadius(void);
	
protected:
	virtual int __fastcall GetShapeHeight(void);
	virtual int __fastcall GetShapeWidth(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Name();
	__property int Radius = {read=GetRadius, nodefault};
public:
	/* TCustomdxReportCellShape.Create */ inline __fastcall virtual TdxReportCellCircle(Dxpscore::TdxReportCell* AParent) : TCustomdxReportCellEllipseShape(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellCircle(void) { }
	
};


class DELPHICLASS TCustomdxReportCellRectangle;
class PASCALIMPLEMENTATION TCustomdxReportCellRectangle : public TCustomdxReportCellShape
{
	typedef TCustomdxReportCellShape inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetShapeRect(void);
	
public:
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
public:
	/* TCustomdxReportCellShape.Create */ inline __fastcall virtual TCustomdxReportCellRectangle(Dxpscore::TdxReportCell* AParent) : TCustomdxReportCellShape(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TCustomdxReportCellRectangle(void) { }
	
};


class DELPHICLASS TdxReportCellRectangle;
class PASCALIMPLEMENTATION TdxReportCellRectangle : public TCustomdxReportCellRectangle
{
	typedef TCustomdxReportCellRectangle inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TCustomdxReportCellShape.Create */ inline __fastcall virtual TdxReportCellRectangle(Dxpscore::TdxReportCell* AParent) : TCustomdxReportCellRectangle(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellRectangle(void) { }
	
};


class DELPHICLASS TdxReportCellSquare;
class PASCALIMPLEMENTATION TdxReportCellSquare : public TCustomdxReportCellRectangle
{
	typedef TCustomdxReportCellRectangle inherited;
	
protected:
	virtual int __fastcall GetShapeHeight(void);
	virtual int __fastcall GetShapeWidth(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TCustomdxReportCellShape.Create */ inline __fastcall virtual TdxReportCellSquare(Dxpscore::TdxReportCell* AParent) : TCustomdxReportCellRectangle(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellSquare(void) { }
	
};


class DELPHICLASS TdxReportCellRoundRect;
class PASCALIMPLEMENTATION TdxReportCellRoundRect : public TCustomdxReportCellRectangle
{
	typedef TCustomdxReportCellRectangle inherited;
	
private:
	int FEllipseHeight;
	int FEllipseWidth;
	void __fastcall SetEllipseHeight(int Value);
	void __fastcall SetEllipseWidth(int Value);
	
protected:
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	
public:
	__fastcall virtual TdxReportCellRoundRect(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__property int EllipseHeight = {read=FEllipseHeight, write=SetEllipseHeight, nodefault};
	__property int EllipseWidth = {read=FEllipseWidth, write=SetEllipseWidth, nodefault};
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellRoundRect(void) { }
	
};


class DELPHICLASS TdxReportCellRoundSquare;
class PASCALIMPLEMENTATION TdxReportCellRoundSquare : public TdxReportCellRoundRect
{
	typedef TdxReportCellRoundRect inherited;
	
protected:
	virtual int __fastcall GetShapeHeight(void);
	virtual int __fastcall GetShapeWidth(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TdxReportCellRoundRect.Create */ inline __fastcall virtual TdxReportCellRoundSquare(Dxpscore::TdxReportCell* AParent) : TdxReportCellRoundRect(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TdxReportCellRoundSquare(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsshapes */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSSHAPES)
using namespace Dxpsshapes;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsshapesHPP
