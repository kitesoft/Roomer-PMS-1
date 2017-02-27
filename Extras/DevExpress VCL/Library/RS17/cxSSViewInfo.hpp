// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSViewInfo.pas' rev: 24.00 (Win32)

#ifndef CxssviewinfoHPP
#define CxssviewinfoHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSStyles.hpp>	// Pascal unit
#include <cxSSData.hpp>	// Pascal unit
#include <cxSSHeaders.hpp>	// Pascal unit
#include <cxSSFormulas.hpp>	// Pascal unit
#include <cxSSUtils.hpp>	// Pascal unit
#include <cxSSPainterWrapper.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssviewinfo
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxSSheetViewInfoClass;

typedef System::Set<Cxsstypes::TcxSSNavigatorBtn, Cxsstypes::TcxSSNavigatorBtn::nbStart, Cxsstypes::TcxSSNavigatorBtn::nbEnd>  TcxSSNavigatorBtnStates;

enum TcxSSCaptionHitTest : unsigned char { htNone, htCaption, htButton };

enum Cxssviewinfo__1 : unsigned char { csCurrent, csHidden };

typedef System::Set<Cxssviewinfo__1, Cxssviewinfo__1::csCurrent, Cxssviewinfo__1::csHidden>  TcxSSCaptionStates;

struct DECLSPEC_DRECORD TcxSSCaptionInfoBrick
{
public:
	TcxSSCaptionStates State;
	System::UnicodeString DisplayText;
	System::Types::TRect BoundsRect;
};


struct DECLSPEC_DRECORD TcxSSBookCaptionViewInfo
{
private:
	typedef System::DynamicArray<TcxSSCaptionInfoBrick> _TcxSSBookCaptionViewInfo__1;
	
	
public:
	System::Types::TRect Bounds;
	System::Uitypes::TColor FillColor;
	Vcl::Graphics::TFont* Font;
	System::Byte PageCount;
	bool IsButtonDown;
	System::Int8 BtnDown;
	TcxSSNavigatorBtnStates Enabled;
	int FirstVisibleCaption;
	System::StaticArray<System::Types::TRect, 4> BtnBricks;
	_TcxSSBookCaptionViewInfo__1 Bricks;
};


typedef System::StaticArray<System::Types::TRect, 3> TcxEdgeVertex;

typedef TcxEdgeVertex *PcxEdgeVertex;

struct TcxSSInfoBrick;
typedef TcxSSInfoBrick *PcxSSInfoBrick;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSSInfoBrick
{
public:
	int Col;
	int Row;
	System::Types::TRect DisplayRect;
	System::Types::TRect TextRect;
	Cxsstypes::TcxSSFillStyle BrushStyle;
	System::Word BrushBkColor;
	System::Word BrushFGColor;
	Cxsstypes::TcxSSBordersStyle Edges;
	TcxEdgeVertex TopEdgeVertex;
	TcxEdgeVertex LeftEdgeVertex;
	Cxsstypes::TcxTextParameters TextSettings;
	bool IsSelected;
	
public:
	bool IsMerge;
	union
	{
		struct 
		{
			
		};
		struct 
		{
			int UnionIndex;
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSSUnionInfoBrick
{
public:
	System::Types::TRect UnionRange;
	Cxsstypes::TcxSSFillStyle BrushStyle;
	System::Word BrushBkColor;
	System::Word BrushFGColor;
	System::Types::TRect TextRect;
	System::Types::TRect DisplayRect;
	bool IsSelected;
	Cxsstypes::TcxTextParameters TextSettings;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSSViewInfoData
{
private:
	typedef System::DynamicArray<TcxSSUnionInfoBrick> _TcxSSViewInfoData__1;
	
	typedef System::DynamicArray<TcxSSInfoBrick> _TcxSSViewInfoData__2;
	
	typedef System::DynamicArray<System::DynamicArray<TcxSSInfoBrick> > _TcxSSViewInfoData__3;
	
	
public:
	System::Types::TRect DisplayRect;
	System::Types::TRect Bounds;
	System::Types::TRect Selection;
	System::Types::TRect SelectedBricks;
	int HeaderColor;
	int HeaderFontColor;
	bool IsSelectionVisible;
	bool DrawHeaders;
	System::Word Reserved;
	_TcxSSViewInfoData__1 UnionBricks;
	_TcxSSViewInfoData__3 Bricks;
};
#pragma pack(pop)


enum TcxSSHitTestState : unsigned char { htCell, htRowHeader, htColHeader, htResize, htUpperLeft };

typedef System::Set<TcxSSHitTestState, TcxSSHitTestState::htCell, TcxSSHitTestState::htUpperLeft>  TcxSSHitTestStates;

class DELPHICLASS TcxSSheetViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSSheetViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FDrawGrid;
	TcxSSViewInfoData FInfoData;
	bool FInfoChanged;
	System::TObject* FOwner;
	bool FShowFormulas;
	int __fastcall GetBottomRow(void);
	System::Types::TPoint __fastcall GetBottomRight(void);
	Cxsspainterwrapper::TcxCanvasWrapper* __fastcall GetCanvas(void);
	System::Types::TRect __fastcall GetClientRect(void);
	int __fastcall GetColHeaderHeight(void);
	Cxssdata::TcxSSDataStorage* __fastcall GetDataStorage(void);
	System::Byte __fastcall GetFloatDigits(void);
	Cxssformulas::TcxSSFormulasCache* __fastcall GetFormulasCache(void);
	Cxssheaders::TcxSSHeader* __fastcall GetHeader(Cxsstypes::TcxSSHeaderType AType);
	int __fastcall GetLeftCol(void);
	int __fastcall GetRowHeaderWidth(void);
	int __fastcall GetRightCol(void);
	System::Types::TPoint __fastcall GetTopLeft(void);
	int __fastcall GetTopRow(void);
	void __fastcall SetBottomRight(const System::Types::TPoint &Value);
	void __fastcall SetBottomRow(const int Value);
	void __fastcall SetInfoChanged(const bool Value);
	void __fastcall SetLeftCol(const int Value);
	void __fastcall SetRightCol(const int Value);
	void __fastcall SetTopLeft(const System::Types::TPoint &Value);
	void __fastcall SetTopRow(const int Value);
	
protected:
	virtual int __fastcall AddUnionBrick(int ACol, int ARow);
	virtual void __fastcall CalculateViewInfo(void);
	void __fastcall CheckSelectionVisibility(void);
	System::UnicodeString __fastcall ConvertCellRecToDisplayText(const Cxsstypes::TcxSSCellRec &ACellRec, System::Word &AColor);
	virtual void __fastcall InvalidateRect(const System::Types::TRect &ARect);
	bool __fastcall GetCellIndexes(int ACol, int ARow, int &AColPos, int &ARowPos);
	System::Types::TRect __fastcall GetCellsRectIndexes(const System::Types::TRect &ASelRect);
	Cxsstypes::TcxHorzTextAlign __fastcall GetCellTextAlignment(const Cxsstypes::TcxSSCellRec &ACell);
	virtual void __fastcall InvalidateBrick(int AColPos, int ARowPos);
	virtual void __fastcall InvalidateCells(void);
	virtual void __fastcall SetBrickInfo(int AColPos, int ARowPos);
	__property Cxsspainterwrapper::TcxCanvasWrapper* Canvas = {read=GetCanvas};
	__property System::Types::TRect ClipRect = {read=GetClientRect};
	__property Cxssdata::TcxSSDataStorage* DataStorage = {read=GetDataStorage};
	__property Cxssheaders::TcxSSHeader* Headers[Cxsstypes::TcxSSHeaderType AType] = {read=GetHeader};
	__property Cxssformulas::TcxSSFormulasCache* FormulasCache = {read=GetFormulasCache};
	__property System::Byte FloatDigits = {read=GetFloatDigits, nodefault};
	
public:
	__fastcall virtual TcxSSheetViewInfo(System::TObject* AOwner);
	void __fastcall ClearBrickText(int ACol, int ARow);
	TcxSSHitTestStates __fastcall HitTest(int X, int Y, int &ACol, int &ARow);
	void __fastcall UpdateCellInfo(const int ACol, const int ARow);
	void __fastcall UpdateCellsInfo(const System::Types::TRect &ACellRect);
	void __fastcall UpdateOnChangeSelection(void);
	void __fastcall UpdateOnCancelMode(void);
	void __fastcall UpdateOnResize(void);
	void __fastcall UpdateOnResizeColumn(const int ACol);
	void __fastcall UpdateOnResizeRow(const int ARow);
	void __fastcall UpdateViewInfo(void);
	__property System::Types::TPoint BottomRight = {read=GetBottomRight, write=SetBottomRight};
	__property int BottomRow = {read=GetBottomRow, write=SetBottomRow, nodefault};
	__property int ColHeaderHeight = {read=GetColHeaderHeight, nodefault};
	__property TcxSSViewInfoData InfoData = {read=FInfoData};
	__property bool InfoChanged = {read=FInfoChanged, write=SetInfoChanged, nodefault};
	__property int LeftCol = {read=GetLeftCol, write=SetLeftCol, nodefault};
	__property System::TObject* Owner = {read=FOwner};
	__property int RightCol = {read=GetRightCol, write=SetRightCol, nodefault};
	__property int RowHeaderWidth = {read=GetRowHeaderWidth, nodefault};
	__property System::Types::TPoint TopLeft = {read=GetTopLeft, write=SetTopLeft};
	__property int TopRow = {read=GetTopRow, write=SetTopRow, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSSheetViewInfo(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxssviewinfo */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSVIEWINFO)
using namespace Cxssviewinfo;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssviewinfoHPP
