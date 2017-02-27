// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSHistory.pas' rev: 24.00 (Win64)

#ifndef CxsshistoryHPP
#define CxsshistoryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxSSData.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxsshistory
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxActionClass;

typedef System::TMetaClass* TcxSSHistoryClass;

class DELPHICLASS TcxCustomHistory;
class DELPHICLASS TcxCustomAction;
class DELPHICLASS TcxActionList;
class PASCALIMPLEMENTATION TcxCustomHistory : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomAction* FCurrentAction;
	int FFuncCount;
	bool FIsSafeException;
	int FMaxActionCount;
	System::TObject* FOwner;
	TcxActionList* FRedoList;
	TcxActionList* FUndoList;
	int FUpdateRef;
	System::Classes::TNotifyEvent FOnChange;
	bool __fastcall AddNewAction(TcxActionClass ActionClass, void *Action);
	bool __fastcall GetLocked(void);
	bool __fastcall GetIsComplexAction(void);
	void __fastcall SetMaxActionCount(const int Value);
	
protected:
	bool __fastcall AddAction(TcxActionClass ActionClass, void *Action);
	bool __fastcall AddComplexAction(TcxActionClass ActionClass, const System::UnicodeString ADescription, void *Action);
	virtual void __fastcall Change(void);
	virtual void __fastcall ChangeUpdateState(bool CanUpdate);
	virtual void __fastcall SafeException(void);
	virtual void __fastcall UpdateFormulas(void);
	__property System::TObject* HistoryOwner = {read=FOwner, write=FOwner};
	__property bool IsComplexAction = {read=GetIsComplexAction, nodefault};
	__property bool Locked = {read=GetLocked, nodefault};
	__property int MaxActions = {read=FMaxActionCount, write=SetMaxActionCount, nodefault};
	__property System::TObject* Owner = {read=FOwner};
	__property TcxActionList* RedoActions = {read=FRedoList};
	__property TcxActionList* UndoActions = {read=FUndoList};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	int __fastcall BeginUpdate(void);
	virtual void __fastcall Clear(void);
	int __fastcall EndUpdate(void);
	bool __fastcall StartComplexAction(const System::UnicodeString ADescription);
	void __fastcall StopComplexAction(void);
	virtual void __fastcall Redo(const int ACount = 0xffffffff);
	virtual void __fastcall Undo(const int ACount = 0xffffffff);
public:
	/* TObject.Create */ inline __fastcall TcxCustomHistory(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomHistory(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomAction : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomAction* operator[](int AIndex) { return Item[AIndex]; }
	
private:
	TcxCustomAction* FChild;
	TcxCustomHistory* FHistory;
	TcxCustomAction* FNext;
	TcxCustomHistory* FOwner;
	TcxCustomAction* FParent;
	TcxCustomAction* FPrev;
	int __fastcall GetCount(void);
	System::TObject* __fastcall GetHistoryOwner(void);
	TcxCustomAction* __fastcall GetItem(int AIndex);
	
protected:
	virtual void __fastcall Clear(void);
	virtual System::UnicodeString __fastcall GetActionDescription(void);
	void __fastcall DeleteFromChain(void);
	virtual void __fastcall DoUndo(void);
	virtual void __fastcall DoRedo(void);
	__classmethod int __fastcall GetCountActions(TcxCustomAction* Action);
	__classmethod TcxCustomAction* __fastcall GetFirstAction(TcxCustomAction* Action);
	__classmethod TcxCustomAction* __fastcall GetLastAction(TcxCustomAction* Action);
	__classmethod int __fastcall GetPosition(TcxCustomAction* Action);
	virtual void __fastcall InsertAfter(TcxCustomAction* Action);
	virtual void __fastcall InsertBefore(TcxCustomAction* Action);
	__property TcxCustomAction* Item[int AIndex] = {read=GetItem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomAction* Parent = {read=FParent};
	__property TcxCustomHistory* History = {read=FHistory};
	__property System::TObject* HistoryOwner = {read=GetHistoryOwner};
	
public:
	__fastcall virtual ~TcxCustomAction(void);
	__property System::UnicodeString Description = {read=GetActionDescription};
public:
	/* TObject.Create */ inline __fastcall TcxCustomAction(void) : System::TObject() { }
	
};


class DELPHICLASS TcxSpreadSheetHistory;
class PASCALIMPLEMENTATION TcxSpreadSheetHistory : public TcxCustomHistory
{
	typedef TcxCustomHistory inherited;
	
protected:
	virtual void __fastcall ChangeUpdateState(bool CanUpdate);
	virtual void __fastcall UpdateFormulas(void);
	
public:
	virtual void __fastcall Clear(void);
	__property MaxActions;
	__property RedoActions;
	__property UndoActions;
public:
	/* TObject.Create */ inline __fastcall TcxSpreadSheetHistory(void) : TcxCustomHistory() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSpreadSheetHistory(void) { }
	
};


class PASCALIMPLEMENTATION TcxActionList : public TcxCustomAction
{
	typedef TcxCustomAction inherited;
	
public:
	__property Item;
	__property Count;
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxActionList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxActionList(void) : TcxCustomAction() { }
	
};


struct DECLSPEC_DRECORD TcxStoreCellRec
{
public:
	System::UnicodeString Data;
	Cxsstypes::TcxSSDataType DataType;
	System::UnicodeString FontName;
	System::Word FontColor;
	System::Uitypes::TFontStyles FontStyle;
	System::Uitypes::TFontCharset FontCharset;
	System::Int8 FontSize;
	System::Byte FormatIndex;
	Cxsstypes::TcxHorzTextAlign HorzAlign;
	Cxsstypes::TcxVertTextAlign VertAlign;
	bool WordBreak;
	bool ShrinkToFit;
	Cxsstypes::TcxSSCellStates CellState;
	Cxsstypes::TcxSSFillStyle BrushStyle;
	System::Word BrushFgColor;
	System::Word BrushBkColor;
	Cxsstypes::TcxSSBordersStyle Borders;
};


typedef System::DynamicArray<TcxStoreCellRec> Cxsshistory__5;

typedef System::DynamicArray<System::DynamicArray<TcxStoreCellRec> > TcxCellsData;

class DELPHICLASS TcxSpreadSheetActions;
class PASCALIMPLEMENTATION TcxSpreadSheetActions : public TcxCustomAction
{
	typedef TcxCustomAction inherited;
	
private:
	TcxCellsData FData;
	System::Types::TRect FRect;
	System::TObject* FSheet;
	void __fastcall GetCellData(const int ACol, const int ARow, TcxStoreCellRec &AStoredData);
	Cxssdata::TcxSSDataStorage* __fastcall GetDataStorage(void);
	void __fastcall SetCellData(const int ACol, const int ARow, TcxStoreCellRec &AStoredData);
	
protected:
	virtual void __fastcall DoRedo(void);
	virtual void __fastcall DoUndo(void);
	virtual void __fastcall RestoreCellsData(void);
	void __fastcall SetData(System::TObject* ASheet, const System::Types::TRect &ACellRect, const bool SaveCells = true);
	virtual void __fastcall StoreCellsData(TcxCellsData &AData);
	__property System::Types::TRect CellsRect = {read=FRect};
	__property TcxCellsData Data = {read=FData};
	__property Cxssdata::TcxSSDataStorage* DataStorage = {read=GetDataStorage};
	__property System::TObject* Sheet = {read=FSheet};
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxSpreadSheetActions(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSpreadSheetActions(void) : TcxCustomAction() { }
	
};


class DELPHICLASS TcxComplexAction;
class PASCALIMPLEMENTATION TcxComplexAction : public TcxCustomAction
{
	typedef TcxCustomAction inherited;
	
private:
	System::UnicodeString FDescription;
	
protected:
	void __fastcall CheckEmpty(void);
	virtual System::UnicodeString __fastcall GetActionDescription(void);
	
public:
	__property Item;
	__property Count;
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxComplexAction(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxComplexAction(void) : TcxCustomAction() { }
	
};


class DELPHICLASS TcxSpreadSheetInsertDeleteActions;
class PASCALIMPLEMENTATION TcxSpreadSheetInsertDeleteActions : public TcxSpreadSheetActions
{
	typedef TcxSpreadSheetActions inherited;
	
private:
	Cxsstypes::TcxSSRectsArray FRects;
	Cxsstypes::TcxSSCellsModify FModifyType;
	
public:
	virtual void __fastcall BeforeAction(System::TObject* ASheet, const System::Types::TRect &ACellRect, Cxsstypes::TcxSSCellsModify AModifyType);
	__property Cxsstypes::TcxSSCellsModify ModifyType = {read=FModifyType, nodefault};
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxSpreadSheetInsertDeleteActions(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSpreadSheetInsertDeleteActions(void) : TcxSpreadSheetActions() { }
	
};


class DELPHICLASS TcxInsertCellsAction;
class PASCALIMPLEMENTATION TcxInsertCellsAction : public TcxSpreadSheetInsertDeleteActions
{
	typedef TcxSpreadSheetInsertDeleteActions inherited;
	
protected:
	virtual void __fastcall DoRedo(void);
	virtual void __fastcall DoUndo(void);
	virtual System::UnicodeString __fastcall GetActionDescription(void);
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxInsertCellsAction(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxInsertCellsAction(void) : TcxSpreadSheetInsertDeleteActions() { }
	
};


class DELPHICLASS TcxDeleteCellsAction;
class PASCALIMPLEMENTATION TcxDeleteCellsAction : public TcxSpreadSheetInsertDeleteActions
{
	typedef TcxSpreadSheetInsertDeleteActions inherited;
	
protected:
	virtual void __fastcall DoRedo(void);
	virtual void __fastcall DoUndo(void);
	virtual System::UnicodeString __fastcall GetActionDescription(void);
	
public:
	virtual void __fastcall BeforeAction(System::TObject* ASheet, const System::Types::TRect &ACellRect, Cxsstypes::TcxSSCellsModify AModifyType);
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxDeleteCellsAction(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxDeleteCellsAction(void) : TcxSpreadSheetInsertDeleteActions() { }
	
};


class DELPHICLASS TcxSpreadSheetChangeCellsAction;
class PASCALIMPLEMENTATION TcxSpreadSheetChangeCellsAction : public TcxSpreadSheetActions
{
	typedef TcxSpreadSheetActions inherited;
	
public:
	void __fastcall BeforeAction(System::TObject* ASheet, const System::Types::TRect &ACellRect);
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxSpreadSheetChangeCellsAction(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSpreadSheetChangeCellsAction(void) : TcxSpreadSheetActions() { }
	
};


class DELPHICLASS TcxChangeDataAction;
class PASCALIMPLEMENTATION TcxChangeDataAction : public TcxSpreadSheetChangeCellsAction
{
	typedef TcxSpreadSheetChangeCellsAction inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetActionDescription(void);
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxChangeDataAction(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxChangeDataAction(void) : TcxSpreadSheetChangeCellsAction() { }
	
};


class DELPHICLASS TcxChangeStyleAction;
class PASCALIMPLEMENTATION TcxChangeStyleAction : public TcxSpreadSheetChangeCellsAction
{
	typedef TcxSpreadSheetChangeCellsAction inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetActionDescription(void);
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxChangeStyleAction(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxChangeStyleAction(void) : TcxSpreadSheetChangeCellsAction() { }
	
};


class DELPHICLASS TcxMergeSplitActions;
class PASCALIMPLEMENTATION TcxMergeSplitActions : public TcxSpreadSheetActions
{
	typedef TcxSpreadSheetActions inherited;
	
private:
	Cxsstypes::TcxSSRectsArray FRects;
	
protected:
	virtual void __fastcall DoRedo(void);
	virtual void __fastcall DoUndo(void);
	
public:
	virtual void __fastcall BeforeAction(System::TObject* ASheet, const System::Types::TRect &ACellRect);
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxMergeSplitActions(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxMergeSplitActions(void) : TcxSpreadSheetActions() { }
	
};


class DELPHICLASS TcxMergeCellsAction;
class PASCALIMPLEMENTATION TcxMergeCellsAction : public TcxMergeSplitActions
{
	typedef TcxMergeSplitActions inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetActionDescription(void);
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxMergeCellsAction(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxMergeCellsAction(void) : TcxMergeSplitActions() { }
	
};


class DELPHICLASS TcxSplitCellsAction;
class PASCALIMPLEMENTATION TcxSplitCellsAction : public TcxMergeSplitActions
{
	typedef TcxMergeSplitActions inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetActionDescription(void);
public:
	/* TcxCustomAction.Destroy */ inline __fastcall virtual ~TcxSplitCellsAction(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSplitCellsAction(void) : TcxMergeSplitActions() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int MaximumActionsCount;
}	/* namespace Cxsshistory */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSHISTORY)
using namespace Cxsshistory;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxsshistoryHPP
