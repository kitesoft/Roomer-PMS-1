// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSData.pas' rev: 24.00 (Win64)

#ifndef CxssdataHPP
#define CxssdataHPP

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
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxSSHeaders.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit
#include <cxSSStyles.hpp>	// Pascal unit
#include <cxSSUtils.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssdata
{
//-- type declarations -------------------------------------------------------
enum TcxSSSelectionState : unsigned char { ssCurrentSelect, ssMultiSelect, ssMergeSelect };

typedef System::TMetaClass* TcxSSDataStorageClass;

class DELPHICLASS TcxSSDataStorage;
class DELPHICLASS TcxSSMergedCellsStorage;
class PASCALIMPLEMENTATION TcxSSDataStorage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FCaption;
	System::Types::TSize FCapacity;
	int FColCapacityInc;
	Cxsstypes::TcxSSColumns *FCols;
	int FColsCount;
	Cxsstypes::TcxSSCellRec FDefaultCellRec;
	System::Types::TSize FDimension;
	bool FDimensionAssigned;
	System::StaticArray<Cxssheaders::TcxSSHeader*, 2> FHeaders;
	bool FIsSetSelecton;
	bool FIsDeleted;
	int FMaxRow;
	TcxSSMergedCellsStorage* FMergedCells;
	System::TObject* FOwnerSheet;
	int FRowCapacityInc;
	System::Types::TRect FSelection;
	TcxSSSelectionState FSelectionState;
	Cxssstyles::TcxSSCellStyle* __fastcall GetCellStyle(int ACol, int ARow);
	Cxsstypes::TcxSSDataType __fastcall GetCellDataType(int ACol, int ARow);
	System::TDateTime __fastcall GetCellDateTime(int ACol, int ARow);
	Cxsstypes::PcxSSFuncRec __fastcall GetCellFormulaPtr(int ACol, int ARow);
	Cxsstypes::PcxSSCellStyleRec __fastcall GetCellStylePtr(int ACol, int ARow);
	System::UnicodeString __fastcall GetCellText(int ACol, int ARow);
	int __fastcall GetCurrentCol(void);
	int __fastcall GetCurrentRow(void);
	System::Word __fastcall GetCurrentPage(void);
	Cxssheaders::TcxSSHeader* __fastcall GetHeaders(Cxsstypes::TcxSSHeaderType AType);
	System::TObject* __fastcall GetListener(void);
	System::TObject* __fastcall GetParentBook(void);
	int __fastcall GetRowCount(int ACol);
	System::Types::TRect __fastcall GetSelection(void);
	Cxsstypes::TcxSSRectsArray __fastcall GetMergedCellsRange(void);
	void __fastcall SetModified(void);
	void __fastcall SetCellDateTime(int ACol, int ARow, const System::TDateTime Value);
	void __fastcall SetCellFormulaPtr(int ACol, int ARow, const Cxsstypes::PcxSSFuncRec Value);
	void __fastcall SetCellStylePtr(int ACol, int ARow, const Cxsstypes::PcxSSCellStyleRec Value);
	void __fastcall SetCellText(int ACol, int ARow, const System::UnicodeString Value);
	void __fastcall SetDimension(const System::Types::TSize ASize);
	void __fastcall SetSheetCaption(const System::UnicodeString Value);
	void __fastcall SetSelectionRect(const System::Types::TRect &ARect);
	
protected:
	void __fastcall AddCellToHistory(const int ACol, const int ARow);
	short __fastcall CellCompare(const Cxsstypes::TcxSSCellRec &ACell1, const Cxsstypes::TcxSSCellRec &ACell2);
	bool __fastcall CellIsEmpty(int ACol, int ARow);
	Cxsstypes::PcxSSCellRec __fastcall CloneCell(Cxsstypes::PcxSSCellRec ACell);
	bool __fastcall CompareCells(const Cxsstypes::TcxSSCellRec &ACell1, const Cxsstypes::TcxSSCellRec &ACell2);
	virtual Cxsstypes::TcxSSCellRec __fastcall GetCellRec(int ACol, int ARow);
	bool __fastcall GetMultiSelection(void);
	bool __fastcall IsLoading(void);
	bool __fastcall IsValidCell(int ACol, int ARow);
	virtual void __fastcall SetCellRec(int ACol, int ARow, const Cxsstypes::TcxSSCellRec &Value);
	void __fastcall SetCellTextEx(int ACol, int ARow, const System::UnicodeString Value, bool IsFormula = false, bool Analyze = true);
	virtual void __fastcall SetCurrentCol(const int Value);
	virtual void __fastcall SetCurrentRow(const int Value);
	__property Cxsstypes::PcxSSColumns AccessTable = {read=FCols, write=FCols};
	__property int AccessColsCount = {read=FColsCount, write=FColsCount, nodefault};
	__property int AccessMaxRow = {read=FMaxRow, write=FMaxRow, nodefault};
	__property System::Types::TSize Capacity = {read=FCapacity};
	__property Cxsstypes::PcxSSColumns Columns = {read=FCols};
	__property Cxsstypes::TcxSSCellRec DefaultCellRec = {read=FDefaultCellRec};
	__property System::TObject* Listener = {read=GetListener};
	__property TcxSSMergedCellsStorage* MergedCells = {read=FMergedCells};
	__property Cxsstypes::TcxSSRectsArray MergedCellsRange = {read=GetMergedCellsRange};
	
public:
	__fastcall virtual TcxSSDataStorage(System::TObject* AOwner);
	__fastcall virtual ~TcxSSDataStorage(void);
	virtual void __fastcall Assign(TcxSSDataStorage* Source);
	virtual System::Types::TRect __fastcall CellRect(int ALeft, int ATop, int ACol, int ARow, bool IsExtendedRect = false);
	bool __fastcall CheckInMergeRange(const System::Types::TPoint APoint, System::Types::TRect &AMergeRange);
	bool __fastcall CheckIntersection(const System::Types::TRect &ARect, bool IsHorz);
	virtual System::Types::TRect __fastcall CheckSelectionRect(const System::Types::TRect &ARect);
	virtual void __fastcall Clear(void);
	virtual void __fastcall ClearCells(System::Types::TRect &ARect, bool SetDefaultStyle = false);
	virtual void __fastcall CopyCells(const int ADestCol, const int ASourceCol, int AFromRow, int AToRow, int ACount, bool IsClearSource = true);
	virtual System::TObject* __fastcall CreateAccessCellObject(int ACol, int ARow);
	virtual void __fastcall DeleteCells(System::Types::TRect &ACells, Cxsstypes::TcxSSCellsModify ACellsModify);
	bool __fastcall HasCell(int ACol, int ARow);
	virtual void __fastcall InsertCells(System::Types::TRect &ACells, Cxsstypes::TcxSSCellsModify ACellsModify);
	bool __fastcall IsMerge(int ACol, int ARow);
	virtual int __fastcall GetContentColCount(void);
	virtual int __fastcall GetContentRowCount(void);
	virtual void __fastcall MergeUnMerge(const System::Types::TRect &ARect, bool AIsMerge);
	virtual void __fastcall SetCapacity(const System::Types::TSize ASize);
	virtual void __fastcall Sort(const System::Types::TRect &ARect, Cxsstypes::TcxSortType const *ASortTypes, const int ASortTypes_Size);
	__property System::UnicodeString Caption = {read=FCaption, write=SetSheetCaption};
	__property Cxsstypes::TcxSSCellRec Cells[int ACol][int ARow] = {read=GetCellRec, write=SetCellRec/*, default*/};
	__property System::UnicodeString CellText[int ACol][int ARow] = {read=GetCellText, write=SetCellText};
	__property Cxssstyles::TcxSSCellStyle* CellStyle[int ACol][int ARow] = {read=GetCellStyle};
	__property Cxsstypes::PcxSSCellStyleRec CellStylePtr[int ACol][int ARow] = {read=GetCellStylePtr, write=SetCellStylePtr};
	__property Cxsstypes::TcxSSDataType CellDataType[int ACol][int ARow] = {read=GetCellDataType};
	__property System::TDateTime CellDateTime[int ACol][int ARow] = {read=GetCellDateTime, write=SetCellDateTime};
	__property Cxsstypes::PcxSSFuncRec CellFormulaPtr[int ACol][int ARow] = {read=GetCellFormulaPtr, write=SetCellFormulaPtr};
	__property int Col = {read=GetCurrentCol, write=SetCurrentCol, nodefault};
	__property System::Word CurrentPage = {read=GetCurrentPage, nodefault};
	__property System::Types::TSize Dimension = {read=FDimension, write=SetDimension};
	__property bool DimensionAssigned = {read=FDimensionAssigned, nodefault};
	__property int Row = {read=GetCurrentRow, write=SetCurrentRow, nodefault};
	__property Cxssheaders::TcxSSHeader* Headers[Cxsstypes::TcxSSHeaderType AType] = {read=GetHeaders};
	__property bool IsMultiSelection = {read=GetMultiSelection, nodefault};
	__property int MaxColumn = {read=FColsCount, nodefault};
	__property int MaxRow = {read=FMaxRow, nodefault};
	__property System::TObject* Owner = {read=FOwnerSheet};
	__property System::TObject* ParentBook = {read=GetParentBook};
	__property int RowCount[int ACol] = {read=GetRowCount};
	__property System::UnicodeString SheetCaption = {read=FCaption, write=SetSheetCaption};
	__property System::Types::TRect Selection = {read=GetSelection, write=SetSelectionRect};
	__property TcxSSSelectionState SelectionState = {read=FSelectionState, nodefault};
};


class PASCALIMPLEMENTATION TcxSSMergedCellsStorage : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TRect operator[](int AIndex) { return MergedAsRect[AIndex]; }
	
private:
	int FCount;
	void *FData;
	TcxSSDataStorage* FOwner;
	bool __fastcall CheckRect(const System::Types::TRect &ARect, /* out */ int &AIndex);
	System::Types::TRect __fastcall GetItemBounds(int AIndex);
	System::Types::TRect __fastcall GetItemRect(int AIndex);
	Cxsstypes::TcxSSRectsArray __fastcall GetItemsRects(void);
	
protected:
	void __fastcall AddMergeItem(const System::Types::TRect &ARect);
	void __fastcall CheckAfterClear(System::Types::TRect &ARect);
	bool __fastcall CheckInMergeRange(const System::Types::TPoint APoint, System::Types::TRect &ARect);
	System::Types::TRect __fastcall CheckSelection(const System::Types::TRect &ARect);
	void __fastcall Clear(void);
	void __fastcall DeleteMergeCell(const int ACol, const int ARow);
	void __fastcall DeleteMergeItem(const int AIndex);
	Cxsstypes::TcxSSRectsArray __fastcall GetRects(void);
	bool __fastcall GetRectItem(const int AIndex, System::Types::TRect &AItem);
	void __fastcall InflateItem(const int AIndex, const int DW, const int DH);
	void __fastcall InflatePoint(System::Types::TPoint &APoint, const int DX, const int DY);
	bool __fastcall RectIsBelow(const System::Types::TRect &ATopRect, const System::Types::TRect &ABottomRect);
	bool __fastcall RectIsRight(const System::Types::TRect &ALeftRect, const System::Types::TRect &ARightRect);
	void __fastcall SetMergeStyle(const System::Types::TRect &ARect, bool AIsMerge);
	Cxsstypes::TcxSSRectsArray __fastcall SetRects(const Cxsstypes::TcxSSRectsArray ARects);
	void __fastcall ShiftItem(const int AItem, const int DX, const int DY);
	void __fastcall UpdateOnInsertCells(System::Types::TRect &ARect, Cxsstypes::TcxSSCellsModify AShift);
	void __fastcall UpdateOnDeleteCells(System::Types::TRect &ARect, Cxsstypes::TcxSSCellsModify AShift);
	System::Types::TRect __fastcall ValidateRect(const System::Types::TRect &ARect);
	__property TcxSSDataStorage* Owner = {read=FOwner};
	
public:
	virtual void __fastcall Assign(TcxSSMergedCellsStorage* Source);
	void __fastcall AddMerges(const Cxsstypes::TcxSSRectsArray ARects);
	bool __fastcall IntersectMerge(const System::Types::TRect &ARect);
	Cxsstypes::TcxSSRectsArray __fastcall IntersectMergedCells(const System::Types::TRect &ARect);
	__property System::Types::TRect MergedAsRect[int AIndex] = {read=GetItemRect/*, default*/};
	__property System::Types::TRect MergedAsBounds[int AIndex] = {read=GetItemBounds};
	__property Cxsstypes::TcxSSRectsArray Rects = {read=GetItemsRects};
	__property int Count = {read=FCount, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxSSMergedCellsStorage(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSSMergedCellsStorage(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxssdata */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSDATA)
using namespace Cxssdata;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssdataHPP
