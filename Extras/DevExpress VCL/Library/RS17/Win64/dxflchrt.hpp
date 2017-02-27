// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxflchrt.pas' rev: 24.00 (Win64)

#ifndef DxflchrtHPP
#define DxflchrtHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxLines.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxflchrt
{
//-- type declarations -------------------------------------------------------
enum TdxFcShapeType : unsigned char { fcsNone, fcsRectangle, fcsEllipse, fcsRoundRect, fcsDiamond, fcsNorthTriangle, fcsSouthTriangle, fcsEastTriangle, fcsWestTriangle, fcsHexagon, fcsUser };

enum TdxFclStyle : unsigned char { fclStraight, fclCurved, fclRectH, fclRectV };

enum TdxFcaType : unsigned char { fcaNone, fcaArrow, fcaEllipse, fcaRectangle };

enum TdxFcHorzPos : unsigned char { fchpLeft, fchpCenter, fchpRight };

enum TdxFcVertPos : unsigned char { fcvpUp, fcvpCenter, fcvpDown };

enum Dxflchrt__1 : unsigned char { htNowhere, htByObject, htOnObject, htOnConnection, htOnConLabel, htOnArrowSrc, htOnArrowDst, htOnSelPoint };

typedef System::Set<Dxflchrt__1, Dxflchrt__1::htNowhere, Dxflchrt__1::htOnSelPoint>  TdxFcHitTest;

enum TdxFcOption : unsigned char { fcoCanDelete, fcoCanDrag, fcoCanSelect, fcoMultiSelect, fcoHideSelection, fcoDelOnClick, fcoDynamicSizing, fcoDynamicMoving };

typedef System::Set<TdxFcOption, TdxFcOption::fcoCanDelete, TdxFcOption::fcoDynamicMoving>  TdxFcOptions;

typedef void __fastcall (__closure *TdxFcDragHandler)(int X, int Y, System::Uitypes::TDragState State);

class DELPHICLASS TdxCustomFlowChart;
class DELPHICLASS TdxFcItem;
typedef void __fastcall (__closure *TdxFcEvent)(TdxCustomFlowChart* Sender, TdxFcItem* Item);

typedef void __fastcall (__closure *TdxFcAllowEvent)(TdxCustomFlowChart* Sender, TdxFcItem* Item, bool &Allow);

class DELPHICLASS TdxFcObject;
typedef void __fastcall (__closure *TdxFcEditEvent)(TdxCustomFlowChart* Sender, TdxFcObject* AObject, System::UnicodeString &S);

typedef void __fastcall (__closure *TdxFcDrawEvent)(TdxCustomFlowChart* Sender, TdxFcObject* AObject, System::Types::TRect &R);

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxFcObjData
{
public:
	int Left;
	int Top;
	System::Word Width;
	System::Word Height;
	System::Word Edge;
	System::Word Border;
	TdxFcHorzPos HTPos;
	TdxFcVertPos VTPos;
	TdxFcHorzPos HIPos;
	TdxFcVertPos VIPos;
	System::Uitypes::TColor BkColor;
	System::Uitypes::TColor ShColor;
	int Tag;
	System::Word ObjCnt;
	short Image;
	TdxFcShapeType Shape;
	System::Byte ShWidth;
	bool ParFont;
	bool Transparent;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxFcArwData
{
public:
	TdxFcaType AType;
	System::Byte Width;
	System::Byte Height;
	System::Uitypes::TColor Color;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxFcConData
{
public:
	short ObjSrc;
	short ObjDst;
	System::Word PtCount;
	System::Uitypes::TColor Color;
	System::Byte PtSrc;
	System::Byte PtDst;
	TdxFclStyle Style;
	bool ParFont;
	TdxFcArwData ArwSrc;
	TdxFcArwData ArwDst;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxFcFntData
{
public:
	short Height;
	System::Uitypes::TColor Color;
	System::Uitypes::TFontPitch Pitch;
	System::Uitypes::TFontStyles Style;
	System::Uitypes::TFontCharset Charset;
};
#pragma pack(pop)


typedef System::StaticArray<System::Types::TPoint, 8> TdxFcSelectionPoints;

class DELPHICLASS TdxFlowChartPainter;
class PASCALIMPLEMENTATION TdxFlowChartPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	void __fastcall PrepareBrush(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor AColor);
	void __fastcall PreparePen(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor AColor, Vcl::Graphics::TPenStyle AStyle, int AWidth);
	
public:
	virtual void __fastcall DrawEdge(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, unsigned AEdgeStyle, unsigned ABorderStyle);
	virtual void __fastcall DrawEllipse(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, Vcl::Graphics::TPenStyle AFrameStyle, int AFrameWidth);
	virtual void __fastcall DrawPolygon(Cxgraphics::TcxCanvas* ACanvas, System::Types::TPoint const *P, const int P_Size, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, Vcl::Graphics::TPenStyle AFrameStyle, int AFrameWidth);
	virtual void __fastcall DrawPolyline(Cxgraphics::TcxCanvas* ACanvas, System::Types::TPoint const *P, const int P_Size, System::Uitypes::TColor AColor, Vcl::Graphics::TPenStyle AStyle, int AWidth);
	virtual void __fastcall DrawRectangle(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, Vcl::Graphics::TPenStyle AFrameStyle, int AFrameWidth);
	virtual void __fastcall DrawRegion(Cxgraphics::TcxCanvas* ACanvas, HRGN ARegionHandle, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, int AFrameWidth);
	virtual void __fastcall DrawRoundRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, Vcl::Graphics::TPenStyle AFrameStyle, int AFrameWidth, int ARadiusX, int ARadiusY);
public:
	/* TObject.Create */ inline __fastcall TdxFlowChartPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFlowChartPainter(void) { }
	
};


class DELPHICLASS TdxFlowChartGDIPlusPainter;
class PASCALIMPLEMENTATION TdxFlowChartGDIPlusPainter : public TdxFlowChartPainter
{
	typedef TdxFlowChartPainter inherited;
	
public:
	virtual void __fastcall DrawEllipse(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, Vcl::Graphics::TPenStyle AFrameStyle, int AFrameWidth);
	virtual void __fastcall DrawPolygon(Cxgraphics::TcxCanvas* ACanvas, System::Types::TPoint const *P, const int P_Size, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, Vcl::Graphics::TPenStyle AFrameStyle, int AFrameWidth);
	virtual void __fastcall DrawPolyline(Cxgraphics::TcxCanvas* ACanvas, System::Types::TPoint const *P, const int P_Size, System::Uitypes::TColor AColor, Vcl::Graphics::TPenStyle AStyle, int AWidth);
	virtual void __fastcall DrawRectangle(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, Vcl::Graphics::TPenStyle AFrameStyle, int AFrameWidth);
	virtual void __fastcall DrawRoundRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AFrameColor, Vcl::Graphics::TPenStyle AFrameStyle, int AFrameWidth, int ARadiusX, int ARadiusY);
public:
	/* TObject.Create */ inline __fastcall TdxFlowChartGDIPlusPainter(void) : TdxFlowChartPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFlowChartGDIPlusPainter(void) { }
	
};


class PASCALIMPLEMENTATION TdxFcItem : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FDestroying;
	Vcl::Graphics::TFont* FFont;
	TdxCustomFlowChart* FOwner;
	bool FParentFont;
	Vcl::Graphics::TFont* FRealFont;
	bool FSelected;
	System::UnicodeString FText;
	void __fastcall CalculateRealFont(void);
	void __fastcall OnFontChange(System::TObject* Sender);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetParentFont(bool Value);
	void __fastcall SetSelected(bool Value);
	
protected:
	virtual System::Types::TRect __fastcall GetDisplayRect(void) = 0 ;
	virtual System::Types::TRect __fastcall GetSelectionRect(void);
	virtual System::Classes::TList* __fastcall SelList(void) = 0 ;
	void __fastcall Changed(void);
	virtual void __fastcall FontChanged(void);
	virtual void __fastcall Invalidate(void) = 0 ;
	void __fastcall LoadFont(System::Classes::TStream* Stream, bool AIsUnicode);
	void __fastcall SaveFont(System::Classes::TStream* Stream);
	virtual void __fastcall SetText(System::UnicodeString Value) = 0 ;
	void __fastcall ScaleFont(void);
	__property System::Types::TRect DisplayRect = {read=GetDisplayRect};
	__property Vcl::Graphics::TFont* RealFont = {read=FRealFont};
	__property System::Types::TRect SelectionRect = {read=GetSelectionRect};
	
public:
	__fastcall TdxFcItem(TdxCustomFlowChart* AOwner);
	__fastcall virtual ~TdxFcItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool Destroying = {read=FDestroying, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property TdxCustomFlowChart* Owner = {read=FOwner};
	__property bool ParentFont = {read=FParentFont, write=SetParentFont, nodefault};
	__property bool Selected = {read=FSelected, write=SetSelected, nodefault};
	__property System::UnicodeString Text = {read=FText, write=SetText};
};


class DELPHICLASS TdxFcConnection;
class PASCALIMPLEMENTATION TdxFcObject : public TdxFcItem
{
	typedef TdxFcItem inherited;
	
private:
	System::Uitypes::TColor FBkColor;
	System::Word FBorder;
	System::Classes::TList* FConnections;
	System::UnicodeString FCustomData;
	void *FData;
	System::Word FEdge;
	System::Word FHeight;
	TdxFcHorzPos FHorzImagePos;
	TdxFcHorzPos FHorzTextPos;
	short FImageIndex;
	int FLeft;
	System::Classes::TList* FLinkedObjects;
	System::Classes::TList* FObjects;
	int FRealContentIndent;
	int FRealHeight;
	int FRealLeft;
	System::Word FRealSW;
	int FRealTop;
	int FRealWidth;
	System::Uitypes::TColor FShapeColor;
	Vcl::Graphics::TPenStyle FShapeStyle;
	TdxFcShapeType FShapeType;
	System::Byte FShapeWidth;
	int FTag;
	int FTop;
	bool FTransparent;
	TdxFcVertPos FVertImagePos;
	TdxFcVertPos FVertTextPos;
	bool FVisible;
	System::Word FWidth;
	System::Types::TRect __fastcall GetClientRect(void);
	TdxFcConnection* __fastcall GetConnection(int Index);
	int __fastcall GetConnectionCount(void);
	bool __fastcall GetIsUnion(void);
	TdxFcObject* __fastcall GetLinkedObject(int Index);
	int __fastcall GetLinkedObjectCount(void);
	int __fastcall GetObjectCount(void);
	TdxFcObject* __fastcall GetObjectValue(int Index);
	TdxFlowChartPainter* __fastcall GetPainter(void);
	int __fastcall GetPoint(System::Types::TPoint const *P, const int P_Size, int X, int Y, int Cnt);
	System::Word __fastcall GetZOrder(void);
	bool __fastcall HasEdge(void);
	bool __fastcall HasImage(void);
	int __fastcall Quadrant(int X, int Y);
	void __fastcall CalculateLinkedPoints(void);
	void __fastcall CalculateRealBounds(void);
	void __fastcall CalculateRealShapeWidth(void);
	void __fastcall ResolveObjRefs(void);
	void __fastcall SelPoints(System::Types::TPoint *Pts);
	void __fastcall SetBkColor(System::Uitypes::TColor Value);
	void __fastcall SetBorder(System::Word Value);
	void __fastcall SetEdge(System::Word Value);
	void __fastcall SetHeight(System::Word Value);
	void __fastcall SetHorzImagePos(TdxFcHorzPos Value);
	void __fastcall SetHorzTextPos(TdxFcHorzPos Value);
	void __fastcall SetImageIndex(short Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetShapeColor(System::Uitypes::TColor Value);
	void __fastcall SetShapeStyle(Vcl::Graphics::TPenStyle Value);
	void __fastcall SetShapeType(TdxFcShapeType Value);
	void __fastcall SetShapeWidth(System::Byte Value);
	void __fastcall SetTop(int Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetVertImagePos(TdxFcVertPos Value);
	void __fastcall SetVertTextPos(TdxFcVertPos Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetWidth(System::Word Value);
	void __fastcall SetZOrder(System::Word Value);
	void __fastcall UpdateConnections(void);
	void __fastcall ZoomChanged(void);
	
protected:
	System::StaticArray<System::Types::TPoint, 16> LinkedPoints;
	virtual bool __fastcall CalculatePolygon(/* out */ Cxgraphics::TPointArray &APolygon, int AIndent);
	virtual HRGN __fastcall CalculateRegion(const System::Types::TRect &ARect, int AShapeWidth);
	HRGN __fastcall CreateClientRegion(void);
	HRGN __fastcall CreateShapeRegion(void);
	virtual System::Types::TRect __fastcall GetDisplayRect(void);
	virtual System::Classes::TList* __fastcall SelList(void);
	virtual HRGN __fastcall UserRegion(System::Types::TRect &R);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall Load(System::Classes::TStream* Stream, bool AIsUnicode);
	virtual void __fastcall Save(System::Classes::TStream* Stream);
	virtual void __fastcall SetText(System::UnicodeString Value);
	virtual void __fastcall UserLinkedPoints(void);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintBackground(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property TdxFlowChartPainter* Painter = {read=GetPainter};
	__property int RealContentIndent = {read=FRealContentIndent, nodefault};
	__property System::Word RealSW = {read=FRealSW, nodefault};
	
public:
	__fastcall TdxFcObject(TdxCustomFlowChart* AOwner);
	__fastcall virtual ~TdxFcObject(void);
	int __fastcall GetLinkedPoint(int X, int Y);
	int __fastcall GetSelPoint(int X, int Y);
	bool __fastcall HasInUnion(TdxFcObject* AObject);
	virtual TdxFcHitTest __fastcall HitTest(const System::Types::TPoint P);
	bool __fastcall InRect(const System::Types::TRect &R);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddToUnion(TdxFcObject* AObject);
	void __fastcall RemoveFromUnion(TdxFcObject* AObject);
	void __fastcall BringToFront(void);
	void __fastcall ClearUnion(void);
	void __fastcall MakeVisible(void);
	void __fastcall PaintImage(const System::Types::TRect &R);
	void __fastcall PaintText(const System::Types::TRect &R);
	void __fastcall PutInFrontOf(TdxFcObject* Value);
	void __fastcall SelectUnion(void);
	void __fastcall SendToBack(void);
	void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight)/* overload */;
	void __fastcall SetBounds(const System::Types::TRect &R)/* overload */;
	__property System::Uitypes::TColor BkColor = {read=FBkColor, write=SetBkColor, nodefault};
	__property System::Word BorderStyle = {read=FBorder, write=SetBorder, nodefault};
	__property int ConnectionCount = {read=GetConnectionCount, nodefault};
	__property TdxFcConnection* Connections[int Index] = {read=GetConnection};
	__property System::UnicodeString CustomData = {read=FCustomData, write=FCustomData};
	__property void * Data = {read=FData, write=FData};
	__property System::Word EdgeStyle = {read=FEdge, write=SetEdge, nodefault};
	__property System::Word Height = {read=FHeight, write=SetHeight, nodefault};
	__property TdxFcHorzPos HorzImagePos = {read=FHorzImagePos, write=SetHorzImagePos, nodefault};
	__property TdxFcHorzPos HorzTextPos = {read=FHorzTextPos, write=SetHorzTextPos, nodefault};
	__property short ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property bool IsUnion = {read=GetIsUnion, nodefault};
	__property int Left = {read=FLeft, write=SetLeft, nodefault};
	__property int LinkedObjectCount = {read=GetLinkedObjectCount, nodefault};
	__property TdxFcObject* LinkedObjects[int Index] = {read=GetLinkedObject};
	__property int ObjectCount = {read=GetObjectCount, nodefault};
	__property TdxFcObject* Objects[int Index] = {read=GetObjectValue};
	__property int RealHeight = {read=FRealHeight, nodefault};
	__property int RealLeft = {read=FRealLeft, nodefault};
	__property int RealTop = {read=FRealTop, nodefault};
	__property int RealWidth = {read=FRealWidth, nodefault};
	__property System::Uitypes::TColor ShapeColor = {read=FShapeColor, write=SetShapeColor, nodefault};
	__property Vcl::Graphics::TPenStyle ShapeStyle = {read=FShapeStyle, write=SetShapeStyle, nodefault};
	__property TdxFcShapeType ShapeType = {read=FShapeType, write=SetShapeType, nodefault};
	__property System::Byte ShapeWidth = {read=FShapeWidth, write=SetShapeWidth, nodefault};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	__property int Top = {read=FTop, write=SetTop, nodefault};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, nodefault};
	__property TdxFcVertPos VertImagePos = {read=FVertImagePos, write=SetVertImagePos, nodefault};
	__property TdxFcVertPos VertTextPos = {read=FVertTextPos, write=SetVertTextPos, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
	__property System::Word Width = {read=FWidth, write=SetWidth, nodefault};
	__property System::Word ZOrder = {read=GetZOrder, write=SetZOrder, nodefault};
};


class DELPHICLASS TdxFcConnectionArrow;
class PASCALIMPLEMENTATION TdxFcConnectionArrow : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxFcaType FArrowType;
	System::Uitypes::TColor FColor;
	System::Byte FHeight;
	TdxFcConnection* FOwner;
	System::StaticArray<System::Types::TPoint, 4> FPoints;
	System::Word FRealHeight;
	System::Word FRealWidth;
	System::Byte FWidth;
	System::Types::TRect __fastcall DisplayRect(bool Ext);
	bool __fastcall GetActive(void);
	TdxFlowChartPainter* __fastcall GetPainter(void);
	void __fastcall SetArrowType(TdxFcaType Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetHeight(System::Byte Value);
	void __fastcall SetPoints(int Index);
	void __fastcall SetRealBounds(void);
	void __fastcall SetWidth(System::Byte Value);
	
protected:
	void __fastcall ClearPoints(void);
	void __fastcall OffsetPoints(int DX, int DY);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Reset(void);
	void __fastcall Load(const TdxFcArwData AData);
	void __fastcall Save(/* out */ TdxFcArwData &AData);
	__property bool Active = {read=GetActive, nodefault};
	__property TdxFlowChartPainter* Painter = {read=GetPainter};
	
public:
	__fastcall TdxFcConnectionArrow(TdxFcConnection* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxFcConnection* Owner = {read=FOwner};
	__property TdxFcaType ArrowType = {read=FArrowType, write=SetArrowType, nodefault};
	__property System::Byte Height = {read=FHeight, write=SetHeight, nodefault};
	__property System::Byte Width = {read=FWidth, write=SetWidth, nodefault};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxFcConnectionArrow(void) { }
	
};


class PASCALIMPLEMENTATION TdxFcConnection : public TdxFcItem
{
	typedef TdxFcItem inherited;
	
private:
	TdxFcConnectionArrow* FArrowDest;
	TdxFcConnectionArrow* FArrowSource;
	System::Uitypes::TColor FColor;
	System::Types::TRect FDisplayRect;
	System::Types::TPoint FMassCenter;
	TdxFcObject* FObjectDest;
	TdxFcObject* FObjectSource;
	Vcl::Graphics::TPenStyle FPenStyle;
	int FPenWidth;
	System::Byte FPointDest;
	Dxlines::TdxFcPoints* FPoints;
	System::Byte FPointSource;
	Dxlines::TdxFcPoints* FRealPoints;
	TdxFclStyle FStyle;
	System::Types::TRect FTextRect;
	bool FTransparent;
	bool FVisible;
	System::Types::TPoint __fastcall GetPoint(int Index);
	int __fastcall GetPointCount(void);
	int __fastcall GetRealCount(void);
	System::Types::TPoint __fastcall GetRealPoint(int Index);
	System::Types::TRect __fastcall GetRealTextRect(void);
	bool __fastcall HasPoint(const System::Types::TPoint P);
	bool __fastcall IndexValid(int &Index, int AMax);
	TdxFclStyle __fastcall RealStyle(void);
	System::Types::TPoint __fastcall ScreenPoint(int Index);
	void __fastcall CalculateDisplayRect(void);
	void __fastcall CalculateTextRect(void);
	void __fastcall DelObj(TdxFcObject* AObj, TdxFcObject* Partneur, int Index);
	void __fastcall InsObj(TdxFcObject* AObj, TdxFcObject* Partneur, int Index);
	void __fastcall InvalidateText(void);
	void __fastcall NewPoint(int X, int Y, TdxFcDragHandler Handler);
	void __fastcall OffsetRealPoints(int DX, int DY);
	void __fastcall SetArrowSource(TdxFcConnectionArrow* Value);
	void __fastcall SetArrowDest(TdxFcConnectionArrow* Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetObjectPoints(void);
	void __fastcall SetPenStyle(Vcl::Graphics::TPenStyle Value);
	void __fastcall SetPenWidth(int Value);
	void __fastcall SetPoint(int AIndex, System::Types::TPoint AValue);
	void __fastcall SetStyle(TdxFclStyle Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall ZoomChanged(void);
	
protected:
	virtual System::Types::TRect __fastcall GetDisplayRect(void);
	virtual System::Classes::TList* __fastcall SelList(void);
	void __fastcall ArrowChanged(TdxFcConnectionArrow* Value);
	void __fastcall ConnectionChanged(void);
	virtual void __fastcall FontChanged(void);
	void __fastcall InternalInsertPoint(int AIndex, System::Types::TPoint P);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall Load(System::Classes::TStream* Stream, bool AIsUnicode);
	virtual void __fastcall Save(System::Classes::TStream* Stream);
	virtual void __fastcall SetText(System::UnicodeString Value);
	void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawLine(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas, bool Upper);
	__property int RealCount = {read=GetRealCount, nodefault};
	__property System::Types::TPoint RealPoints[int Index] = {read=GetRealPoint};
	__property System::Types::TRect RealTextRect = {read=GetRealTextRect};
	
public:
	__fastcall TdxFcConnection(TdxCustomFlowChart* AOwner);
	__fastcall virtual ~TdxFcConnection(void);
	int __fastcall GetNearestPoint(int X, int Y);
	bool __fastcall InRect(const System::Types::TRect &R);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddPoint(const System::Types::TPoint P);
	void __fastcall InsertPoint(int Index, const System::Types::TPoint P);
	void __fastcall RemovePoint(int Index);
	void __fastcall SetObjectSource(TdxFcObject* AObject, System::Byte APoint);
	void __fastcall SetObjectDest(TdxFcObject* AObject, System::Byte APoint);
	__property TdxFcConnectionArrow* ArrowSource = {read=FArrowSource, write=SetArrowSource};
	__property TdxFcConnectionArrow* ArrowDest = {read=FArrowDest, write=SetArrowDest};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property TdxFcObject* ObjectSource = {read=FObjectSource};
	__property TdxFcObject* ObjectDest = {read=FObjectDest};
	__property Vcl::Graphics::TPenStyle PenStyle = {read=FPenStyle, write=SetPenStyle, nodefault};
	__property int PenWidth = {read=FPenWidth, write=SetPenWidth, nodefault};
	__property int PointCount = {read=GetPointCount, nodefault};
	__property System::Types::TPoint Points[int Index] = {read=GetPoint, write=SetPoint};
	__property System::Byte PointSource = {read=FPointSource, nodefault};
	__property System::Byte PointDest = {read=FPointDest, nodefault};
	__property TdxFclStyle Style = {read=FStyle, write=SetStyle, nodefault};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
};


class DELPHICLASS TdxFcSelection;
class PASCALIMPLEMENTATION TdxFcSelection : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FCounts;
	TdxCustomFlowChart* FOwner;
	Dxlines::TdxFcPoints* FPoints;
	
protected:
	void __fastcall AddPoint(const System::Types::TPoint P)/* overload */;
	void __fastcall AddPoint(int X, int Y)/* overload */;
	void __fastcall Clear(void);
	void __fastcall Paint(void);
	__property TdxCustomFlowChart* Owner = {read=FOwner};
	
public:
	__fastcall TdxFcSelection(TdxCustomFlowChart* AOwner);
	__fastcall virtual ~TdxFcSelection(void);
};


class DELPHICLASS TdxFlowChartDragHelper;
class PASCALIMPLEMENTATION TdxFlowChartDragHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TPoint FBase;
	TdxFcConnection* FDragConnection;
	bool FDragging;
	TdxFcDragHandler FDragHandler;
	TdxFcObject* FDragObject;
	bool FDynamicMoving;
	bool FDynamicSizing;
	int FIndex;
	System::Types::TPoint FMobile;
	TdxCustomFlowChart* FOwner;
	bool FPaintLocked;
	HRGN FRegion;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	TdxFcConnection* __fastcall GetConnectionAt(void);
	TdxFcObject* __fastcall GetObjectAt(void);
	
protected:
	void __fastcall CallDragHandler(int X, int Y, System::Uitypes::TDragState State);
	void __fastcall DoDragConnect(int X, int Y, System::Uitypes::TDragState State);
	void __fastcall DoDragMove(int X, int Y, System::Uitypes::TDragState State);
	void __fastcall DoDragPoint(int X, int Y, System::Uitypes::TDragState State);
	void __fastcall DoDragResize(int X, int Y, System::Uitypes::TDragState State);
	__property TdxFcConnection* ConnectionAt = {read=GetConnectionAt};
	__property bool DynamicMoving = {read=FDynamicMoving, nodefault};
	__property bool DynamicSizing = {read=FDynamicSizing, nodefault};
	__property TdxFcObject* ObjectAt = {read=GetObjectAt};
	
public:
	__fastcall TdxFlowChartDragHelper(TdxCustomFlowChart* AOwner);
	void __fastcall CheckDragStart(int X, int Y, const System::Classes::TShiftState AShift, const TdxFcHitTest AHitTest);
	void __fastcall DragStart(int X, int Y, TdxFcDragHandler AHandler);
	void __fastcall DragMove(int X, int Y);
	void __fastcall DragStop(int X, int Y);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property bool Dragging = {read=FDragging, nodefault};
	__property TdxCustomFlowChart* Owner = {read=FOwner};
	__property bool PaintLocked = {read=FPaintLocked, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxFlowChartDragHelper(void) { }
	
};


class PASCALIMPLEMENTATION TdxCustomFlowChart : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	bool FAntialiasing;
	Vcl::Imglist::TChangeLink* FChangeLink;
	int FChartHeight;
	int FChartLeft;
	int FChartTop;
	int FChartWidth;
	TdxFcConnection* FConnectionAt;
	System::Classes::TList* FConnections;
	TdxFlowChartDragHelper* FDragHelper;
	System::Types::TPoint FDragStartPoint;
	bool FHasContentChanges;
	TdxFcHitTest FHitTest;
	int FHitX;
	int FHitY;
	Vcl::Imglist::TCustomImageList* FImages;
	int FLeftEdge;
	bool FLoading;
	int FLockUpdates;
	TdxFcObject* FObjectAt;
	System::Classes::TList* FObjects;
	TdxFcOptions FOptions;
	TdxFlowChartPainter* FPainter;
	System::Word FRealZoom;
	bool FRepaint;
	System::Classes::TList* FSelConnections;
	TdxFcSelection* FSelection;
	System::Classes::TList* FSelObjects;
	int FTopEdge;
	System::Word FZoom;
	TdxFcEvent FOnChange;
	TdxFcEvent FOnCreateItem;
	TdxFcEvent FOnDeletion;
	TdxFcDrawEvent FOnDrawObject;
	TdxFcEditEvent FOnEdited;
	TdxFcAllowEvent FOnEditing;
	TdxFcEvent FOnSelected;
	TdxFcAllowEvent FOnSelection;
	bool __fastcall CanPaint(void);
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	Vcl::Forms::TBorderStyle __fastcall GetBorderStyle(void);
	HIDESBASE int __fastcall GetClientHeight(void);
	HIDESBASE int __fastcall GetClientWidth(void);
	TdxFcConnection* __fastcall GetConnection(int Index);
	int __fastcall GetConnectionCount(void);
	int __fastcall GetObjectCount(void);
	TdxFcObject* __fastcall GetObjectValue(int Index);
	TdxFcConnection* __fastcall GetSelConnect(void);
	TdxFcConnection* __fastcall GetSelectedConnection(int Index);
	int __fastcall GetSelectedConnectionCount(void);
	TdxFcObject* __fastcall GetSelectedObject(int Index);
	int __fastcall GetSelectedObjectCount(void);
	TdxFcObject* __fastcall GetSelObj(void);
	bool __fastcall HasSelection(void);
	int __fastcall TmpSel(void);
	void __fastcall AbortDrag(void);
	void __fastcall CalculateChartSizes(void);
	void __fastcall CalculateRealPos(void);
	bool __fastcall CanScaleByMouseWheel(System::Classes::TShiftState AShift, const System::Types::TPoint AMousePos);
	void __fastcall DoChangeLink(System::TObject* Sender);
	void __fastcall HitTest(int X, int Y);
	void __fastcall InvalidateSel(void);
	void __fastcall RestoreSel(int Value);
	void __fastcall ScalePoint(System::Types::TPoint &P);
	void __fastcall SetAntialiasing(bool AValue);
	HIDESBASE void __fastcall SetBorderStyle(Vcl::Forms::TBorderStyle Value);
	void __fastcall SetChartSizes(void);
	void __fastcall SetConnection(int Index, TdxFcConnection* Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetLeftEdge(int Value);
	void __fastcall SetObjectValue(int Index, TdxFcObject* Value);
	void __fastcall SetOptions(TdxFcOptions Value);
	void __fastcall SetSelConnect(TdxFcConnection* Value);
	void __fastcall SetSelObj(TdxFcObject* Value);
	void __fastcall SetTopEdge(int Value);
	void __fastcall SetZoom(System::Word AValue);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Msg);
	MESSAGE void __fastcall WMErase(Winapi::Messages::TWMEraseBkgnd &Msg);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Msg);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Msg);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Msg);
	
protected:
	virtual bool __fastcall CanSelect(TdxFcItem* Item);
	virtual TdxFlowChartPainter* __fastcall CreatePainter(void);
	virtual bool __fastcall IsDefaultGesture(int AGestureID);
	virtual TdxFcConnection* __fastcall InternalCreateConnection(void);
	virtual TdxFcObject* __fastcall InternalCreateObject(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	System::Types::TPoint __fastcall ScrollPoint(const System::Types::TPoint P, bool APositiveFactor = true);
	System::Types::TRect __fastcall ScrollRect(const System::Types::TRect &R, bool APositiveFactor = true);
	virtual void __fastcall Added(TdxFcItem* Item);
	DYNAMIC void __fastcall BoundsChanged(void);
	void __fastcall CalculateRealZoomFactor(void);
	HIDESBASE virtual void __fastcall Changed(TdxFcItem* Item);
	virtual void __fastcall ContentChanged(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DefaultDrawObject(TdxFcObject* AObject, System::Types::TRect &R);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Delete(TdxFcItem* Item);
	virtual void __fastcall DoDrawObject(TdxFcObject* AObject, System::Types::TRect &R);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall InternalMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	virtual bool __fastcall IsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MoveObjects(int DX, int DY);
	void __fastcall NeedRepaint(void);
	void __fastcall NeedRepaintObject(TdxFcItem* AItem);
	virtual void __fastcall Paint(void);
	void __fastcall PaintSelection(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall Select(TdxFcItem* Item);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	__property Vcl::Forms::TBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, default=1};
	__property int ChartHeight = {read=FChartHeight, nodefault};
	__property int ChartWidth = {read=FChartWidth, nodefault};
	__property int ClientHeight = {read=GetClientHeight, nodefault};
	__property int ClientWidth = {read=GetClientWidth, nodefault};
	__property TdxFlowChartDragHelper* DragHelper = {read=FDragHelper};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TdxFcOptions Options = {read=FOptions, write=SetOptions, nodefault};
	__property TdxFlowChartPainter* Painter = {read=FPainter};
	__property System::Word Zoom = {read=FZoom, write=SetZoom, default=100};
	__property TdxFcEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TdxFcEvent OnCreateItem = {read=FOnCreateItem, write=FOnCreateItem};
	__property TdxFcEvent OnDeletion = {read=FOnDeletion, write=FOnDeletion};
	__property TdxFcDrawEvent OnDrawObject = {read=FOnDrawObject, write=FOnDrawObject};
	__property TdxFcEditEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property TdxFcAllowEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property TdxFcEvent OnSelected = {read=FOnSelected, write=FOnSelected};
	__property TdxFcAllowEvent OnSelection = {read=FOnSelection, write=FOnSelection};
	
public:
	__fastcall virtual TdxCustomFlowChart(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomFlowChart(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	System::Types::TPoint __fastcall ChartPoint(int X, int Y)/* overload */;
	System::Types::TPoint __fastcall ChartPoint(const System::Types::TPoint P)/* overload */;
	TdxFcObject* __fastcall CreateObject(int L, int T, int W, int H, TdxFcShapeType AShape);
	TdxFcConnection* __fastcall CreateConnection(TdxFcObject* OSrc, TdxFcObject* ODst, System::Byte PSrc, System::Byte PDst);
	TdxFcConnection* __fastcall GetConnectionAt(int X, int Y);
	TdxFcObject* __fastcall GetObjectAt(int X, int Y);
	TdxFcHitTest __fastcall GetHitTestAt(int X, int Y);
	int __fastcall SelCount(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall Clear(void);
	void __fastcall ClearSelection(void);
	void __fastcall DeleteSelection(void);
	void __fastcall DeleteConnection(TdxFcConnection* AConnection);
	void __fastcall DeleteObject(TdxFcObject* AObject);
	virtual void __fastcall Invalidate(void);
	void __fastcall LoadFromFile(const System::UnicodeString FileName);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	void __fastcall SaveToFile(const System::UnicodeString FileName);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	void __fastcall SelectAll(void);
	void __fastcall SetLeftTop(int ALeft, int ATop);
	__property bool Antialiasing = {read=FAntialiasing, write=SetAntialiasing, default=0};
	__property Color = {default=536870912};
	__property int ConnectionCount = {read=GetConnectionCount, nodefault};
	__property TdxFcConnection* Connections[int Index] = {read=GetConnection, write=SetConnection};
	__property int LeftEdge = {read=FLeftEdge, write=SetLeftEdge, nodefault};
	__property int ObjectCount = {read=GetObjectCount, nodefault};
	__property TdxFcObject* Objects[int Index] = {read=GetObjectValue, write=SetObjectValue};
	__property System::Word RealZoom = {read=FRealZoom, nodefault};
	__property TdxFcConnection* SelectedConnection = {read=GetSelConnect, write=SetSelConnect};
	__property int SelectedConnectionCount = {read=GetSelectedConnectionCount, nodefault};
	__property TdxFcConnection* SelectedConnections[int Index] = {read=GetSelectedConnection};
	__property TdxFcObject* SelectedObject = {read=GetSelObj, write=SetSelObj};
	__property int SelectedObjectCount = {read=GetSelectedObjectCount, nodefault};
	__property TdxFcObject* SelectedObjects[int Index] = {read=GetSelectedObject};
	__property int TopEdge = {read=FTopEdge, write=SetTopEdge, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomFlowChart(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TdxFlowChart;
class PASCALIMPLEMENTATION TdxFlowChart : public TdxCustomFlowChart
{
	typedef TdxCustomFlowChart inherited;
	
__published:
	__property Align = {default=0};
	__property Antialiasing = {default=0};
	__property BorderStyle = {default=1};
	__property Color = {default=536870912};
	__property Ctl3D;
	__property Enabled = {default=1};
	__property Font;
	__property Images;
	__property LookAndFeel;
	__property OnChange;
	__property OnCreateItem;
	__property OnDeletion;
	__property OnDrawObject;
	__property OnEdited;
	__property OnEditing;
	__property OnSelected;
	__property OnSelection;
	__property Options;
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property Zoom = {default=100};
	__property OnClick;
	__property OnDblClick;
	__property OnEnter;
	__property OnExit;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnStartDrag;
	__property OnEndDrag;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
public:
	/* TdxCustomFlowChart.Create */ inline __fastcall virtual TdxFlowChart(System::Classes::TComponent* AOwner) : TdxCustomFlowChart(AOwner) { }
	/* TdxCustomFlowChart.Destroy */ inline __fastcall virtual ~TdxFlowChart(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxFlowChart(HWND ParentWindow) : TdxCustomFlowChart(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const int TO_HOME = int(0x8000000);
static const int TO_END = int(0x7ffffff);
}	/* namespace Dxflchrt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFLCHRT)
using namespace Dxflchrt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxflchrtHPP
