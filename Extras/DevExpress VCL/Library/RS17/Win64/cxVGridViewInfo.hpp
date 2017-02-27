// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVGridViewInfo.pas' rev: 24.00 (Win64)

#ifndef CxvgridviewinfoHPP
#define CxvgridviewinfoHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <cxVGridUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvgridviewinfo
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCategoryRowHeaderInfo;
class PASCALIMPLEMENTATION TcxCategoryRowHeaderInfo : public Cxvgrid::TcxCustomRowHeaderInfo
{
	typedef Cxvgrid::TcxCustomRowHeaderInfo inherited;
	
private:
	Cxvgrid::TcxCategoryRow* __fastcall GetRow(void);
	
protected:
	virtual void __fastcall AddBottomHorzLine(const System::Types::TRect &R);
	virtual void __fastcall AddRightVertLine(const System::Types::TRect &R);
	virtual void __fastcall CalcRowCaptionsInfo(void);
	virtual void __fastcall CalcViewParams(bool AAllowFocus);
	virtual void __fastcall DoCalcExpandButton(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetCaptionViewParams(void);
	virtual System::Uitypes::TColor __fastcall GetButtonColor(void);
	virtual System::Types::TRect __fastcall GetFocusRect(void);
	virtual bool __fastcall IncreaseBoundsByLastVertLine(void);
	virtual int __fastcall LeftViewPoint(void);
	
public:
	__property Cxvgrid::TcxCategoryRow* Row = {read=GetRow};
public:
	/* TcxCustomRowHeaderInfo.Create */ inline __fastcall virtual TcxCategoryRowHeaderInfo(Cxvgrid::TcxCustomRow* ARow) : Cxvgrid::TcxCustomRowHeaderInfo(ARow) { }
	/* TcxCustomRowHeaderInfo.Destroy */ inline __fastcall virtual ~TcxCategoryRowHeaderInfo(void) { }
	
};


class DELPHICLASS TcxCategoryRowViewInfo;
class PASCALIMPLEMENTATION TcxCategoryRowViewInfo : public Cxvgrid::TcxCustomRowViewInfo
{
	typedef Cxvgrid::TcxCustomRowViewInfo inherited;
	
private:
	Cxvgrid::TcxCategoryRow* __fastcall GetRow(void);
	
protected:
	virtual void __fastcall CalcRowHeaderInfo(Cxvgrid::TcxCustomRow* ANextRow);
	
public:
	__property Cxvgrid::TcxCategoryRow* Row = {read=GetRow};
public:
	/* TcxCustomRowViewInfo.Create */ inline __fastcall virtual TcxCategoryRowViewInfo(Cxvgrid::TcxCustomRow* ARow) : Cxvgrid::TcxCustomRowViewInfo(ARow) { }
	/* TcxCustomRowViewInfo.Destroy */ inline __fastcall virtual ~TcxCategoryRowViewInfo(void) { }
	
};


class DELPHICLASS TcxEditorRowHeaderInfo;
class PASCALIMPLEMENTATION TcxEditorRowHeaderInfo : public Cxvgrid::TcxCustomRowHeaderInfo
{
	typedef Cxvgrid::TcxCustomRowHeaderInfo inherited;
	
private:
	Cxvgrid::TcxEditorRow* __fastcall GetRow(void);
	
public:
	__property Cxvgrid::TcxEditorRow* Row = {read=GetRow};
public:
	/* TcxCustomRowHeaderInfo.Create */ inline __fastcall virtual TcxEditorRowHeaderInfo(Cxvgrid::TcxCustomRow* ARow) : Cxvgrid::TcxCustomRowHeaderInfo(ARow) { }
	/* TcxCustomRowHeaderInfo.Destroy */ inline __fastcall virtual ~TcxEditorRowHeaderInfo(void) { }
	
};


class DELPHICLASS TcxEditorRowViewInfo;
class PASCALIMPLEMENTATION TcxEditorRowViewInfo : public Cxvgrid::TcxCustomRowViewInfo
{
	typedef Cxvgrid::TcxCustomRowViewInfo inherited;
	
private:
	Cxvgrid::TcxEditorRow* __fastcall GetRow(void);
	
protected:
	virtual void __fastcall CalcValuesInfo(void);
	virtual int __fastcall GetValuesHeight(int ABandWidth, Cxvgrid::TcxvgCustomViewInfo* AViewInfo);
	
public:
	__property Cxvgrid::TcxEditorRow* Row = {read=GetRow};
public:
	/* TcxCustomRowViewInfo.Create */ inline __fastcall virtual TcxEditorRowViewInfo(Cxvgrid::TcxCustomRow* ARow) : Cxvgrid::TcxCustomRowViewInfo(ARow) { }
	/* TcxCustomRowViewInfo.Destroy */ inline __fastcall virtual ~TcxEditorRowViewInfo(void) { }
	
};


class DELPHICLASS TcxMultiEditorRowHeaderInfo;
class PASCALIMPLEMENTATION TcxMultiEditorRowHeaderInfo : public Cxvgrid::TcxCustomRowHeaderInfo
{
	typedef Cxvgrid::TcxCustomRowHeaderInfo inherited;
	
private:
	Cxvgridutils::TcxRectList* FSeparatorRects;
	Cxvgrid::TSeparatorInfo FSeparatorInfo;
	Cxvgrid::TcxMultiEditorRow* __fastcall GetRow(void);
	
protected:
	virtual void __fastcall CalcRowCaptionsInfo(void);
	virtual void __fastcall CalcSeparatorRects(Cxvgridutils::TcxRectList* AHeaderCells);
	virtual void __fastcall CalcSeparatorWidth(int ASeparatorWidth);
	virtual void __fastcall CalcSeparatorStyle(void);
	virtual void __fastcall Clear(void);
	
public:
	__fastcall virtual TcxMultiEditorRowHeaderInfo(Cxvgrid::TcxCustomRow* ARow);
	__fastcall virtual ~TcxMultiEditorRowHeaderInfo(void);
	__property Cxvgrid::TcxMultiEditorRow* Row = {read=GetRow};
	__property Cxvgrid::TSeparatorInfo SeparatorInfo = {read=FSeparatorInfo};
	__property Cxvgridutils::TcxRectList* SeparatorRects = {read=FSeparatorRects};
};


class DELPHICLASS TcxMultiEditorRowViewInfo;
class PASCALIMPLEMENTATION TcxMultiEditorRowViewInfo : public Cxvgrid::TcxCustomRowViewInfo
{
	typedef Cxvgrid::TcxCustomRowViewInfo inherited;
	
private:
	Cxvgridutils::TcxRectList* FSeparatorRects;
	TcxMultiEditorRowHeaderInfo* __fastcall GetHeaderInfo(void);
	Cxvgrid::TcxMultiEditorRow* __fastcall GetRow(void);
	Cxvgridutils::TcxRectList* __fastcall GetSeparatorRects(void);
	
protected:
	void __fastcall AddSeparatorRects(bool AHeader, Cxvgridutils::TcxRectList* ASepRects, Cxvgrid::TSeparatorKind ASeparatorKind, Cxvgridutils::TcxRectList* AValueCells, const System::Types::TRect &ABounds);
	virtual void __fastcall CalcValuesInfo(void);
	virtual void __fastcall CheckEmptyValuesInfo(void);
	virtual int __fastcall GetValuesHeight(int ABandWidth, Cxvgrid::TcxvgCustomViewInfo* AViewInfo);
	
public:
	__fastcall virtual TcxMultiEditorRowViewInfo(Cxvgrid::TcxCustomRow* ARow);
	__fastcall virtual ~TcxMultiEditorRowViewInfo(void);
	__classmethod Cxvgridutils::TcxRectList* __fastcall GetCellRects(Cxvgrid::TcxMultiEditorRow* ARow, const System::Types::TRect &R, int ASepWidth);
	__property TcxMultiEditorRowHeaderInfo* HeaderInfo = {read=GetHeaderInfo};
	__property Cxvgrid::TcxMultiEditorRow* Row = {read=GetRow};
	__property Cxvgridutils::TcxRectList* SeparatorRects = {read=GetSeparatorRects};
};


class DELPHICLASS TcxInspectorViewInfo;
class PASCALIMPLEMENTATION TcxInspectorViewInfo : public Cxvgrid::TcxvgCustomViewInfo
{
	typedef Cxvgrid::TcxvgCustomViewInfo inherited;
	
protected:
	virtual void __fastcall AddEmptyRects(void);
	virtual void __fastcall CheckMaxRowHeaderWidth(int &Value, int AValueMinWidth);
	virtual int __fastcall GetViewValueWidth(void);
	virtual int __fastcall GetVisibleValueCount(void);
public:
	/* TcxvgCustomViewInfo.Create */ inline __fastcall virtual TcxInspectorViewInfo(Cxinplacecontainer::TcxEditingControl* AOwner) : Cxvgrid::TcxvgCustomViewInfo(AOwner) { }
	/* TcxvgCustomViewInfo.Destroy */ inline __fastcall virtual ~TcxInspectorViewInfo(void) { }
	
};


class DELPHICLASS TcxBandsViewInfo;
class PASCALIMPLEMENTATION TcxBandsViewInfo : public Cxvgrid::TcxvgCustomViewInfo
{
	typedef Cxvgrid::TcxvgCustomViewInfo inherited;
	
private:
	bool FLock;
	bool __fastcall GetAutoScaleBands(void);
	int __fastcall GetBandIndentWidth(int ABandCount);
	int __fastcall GetBandsInterval(void);
	void __fastcall UpdateBandsWidth(void);
	
protected:
	virtual void __fastcall AddEmptyRects(void);
	virtual void __fastcall CalcBandRects(void);
	virtual void __fastcall CalcBandWidth(void);
	virtual void __fastcall CalculateBandsInfo(void);
	virtual bool __fastcall CanAddRowToBand(const System::Types::TRect &ARowRect, const System::Types::TRect &ABandRect, int ABandRowIndex);
	virtual void __fastcall CheckMaxRowHeaderWidth(int &Value, int AValueMinWidth);
	virtual void __fastcall CreateBand(int ABandHeight, int ABandWidth);
	virtual System::Types::TRect __fastcall GetBandSizeableRect(const System::Types::TRect &ABandRect);
	int __fastcall GetMinViewBandWidth(void);
	virtual bool __fastcall GetRowAutoHeight(Cxvgrid::TcxCustomRow* ARow);
	virtual int __fastcall GetViewBandWidth(void);
	virtual int __fastcall GetViewValueWidth(void);
	virtual int __fastcall GetVisibleValueCount(void);
	virtual void __fastcall SetDividerPos(int APos);
	__property bool AutoScaleBands = {read=GetAutoScaleBands, nodefault};
	__property int BandsIndent = {read=GetBandsInterval, nodefault};
public:
	/* TcxvgCustomViewInfo.Create */ inline __fastcall virtual TcxBandsViewInfo(Cxinplacecontainer::TcxEditingControl* AOwner) : Cxvgrid::TcxvgCustomViewInfo(AOwner) { }
	/* TcxvgCustomViewInfo.Destroy */ inline __fastcall virtual ~TcxBandsViewInfo(void) { }
	
};


class DELPHICLASS TcxMultiRecordViewInfo;
class PASCALIMPLEMENTATION TcxMultiRecordViewInfo : public Cxvgrid::TcxvgCustomViewInfo
{
	typedef Cxvgrid::TcxvgCustomViewInfo inherited;
	
private:
	int FCommonWidth;
	int FRecordsInterval;
	int FVisibleValueCount;
	int __fastcall CalcVisibleValueCount(void);
	int __fastcall GetRecordCount(void);
	Cxvgrid::TcxVirtualVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual void __fastcall AddBandRowsLines(const System::Types::TRect &R);
	virtual void __fastcall AddEmptyRects(void);
	virtual void __fastcall AddRightValueSide(Cxvgrid::TcxCustomRowViewInfo* ARowViewInfo, const System::Types::TRect &R, bool ALast);
	virtual void __fastcall CalcBandWidth(void);
	virtual void __fastcall CalcLayoutGeneral(void);
	virtual void __fastcall Clear(void);
	virtual System::Types::TRect __fastcall GetBandSizeableRect(const System::Types::TRect &ABandRect);
	virtual int __fastcall GetVisibleValueCount(void);
	virtual void __fastcall Reset(void);
	virtual void __fastcall SetDividerPos(int APos);
	__property int RecordCount = {read=GetRecordCount, nodefault};
	
public:
	__fastcall virtual TcxMultiRecordViewInfo(Cxinplacecontainer::TcxEditingControl* AOwner);
	virtual int __fastcall GetDefaultGridModeBufferCount(void);
	virtual System::Types::TRect __fastcall GetValueRect(int AValueIndex, Cxvgrid::TcxCustomRowViewInfo* ARowViewInfo);
	virtual void __fastcall UpdateRecord(int ARecordIndex);
	__property int RecordsInterval = {read=FRecordsInterval, nodefault};
	__property Cxvgrid::TcxVirtualVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
public:
	/* TcxvgCustomViewInfo.Destroy */ inline __fastcall virtual ~TcxMultiRecordViewInfo(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxvgridviewinfo */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVGRIDVIEWINFO)
using namespace Cxvgridviewinfo;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvgridviewinfoHPP
