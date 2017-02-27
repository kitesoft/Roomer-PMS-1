// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSheet.pas' rev: 24.00 (Win64)

#ifndef CxssheetHPP
#define CxssheetHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxExcelAccess.hpp>	// Pascal unit
#include <cxSSHeaders.hpp>	// Pascal unit
#include <cxSSData.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSStyles.hpp>	// Pascal unit
#include <cxSSFormulas.hpp>	// Pascal unit
#include <cxSSViewInfo.hpp>	// Pascal unit
#include <cxSSPainters.hpp>	// Pascal unit
#include <cxSSEditors.hpp>	// Pascal unit
#include <cxSSUtils.hpp>	// Pascal unit
#include <cxSSPainterWrapper.hpp>	// Pascal unit
#include <cxSSIntf.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit
#include <cxSSHistory.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssheet
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ESpreadSheetError;
class PASCALIMPLEMENTATION ESpreadSheetError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ESpreadSheetError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ESpreadSheetError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ESpreadSheetError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ESpreadSheetError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ESpreadSheetError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall ESpreadSheetError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ESpreadSheetError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ESpreadSheetError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ESpreadSheetError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ESpreadSheetError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ESpreadSheetError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ESpreadSheetError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ESpreadSheetError(void) { }
	
};


typedef System::TMetaClass* TcxSSListenerClass;

typedef System::TMetaClass* TcxSSBookSheetClass;

typedef System::TMetaClass* TcxSSFormatDialogClass;

enum TcxScrollBars : unsigned char { sbsNone, sbsHorizontal, sbsVertical, sbsBoth };

class DELPHICLASS TcxSSListener;
class DELPHICLASS TcxCustomSpreadSheetBook;
class DELPHICLASS TcxSSBookSheet;
class PASCALIMPLEMENTATION TcxSSListener : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FLockCount;
	TcxCustomSpreadSheetBook* FOwner;
	
protected:
	int __fastcall BeginUpdate(void);
	int __fastcall EndUpdate(void);
	bool __fastcall IsLocked(void);
	virtual void __fastcall OnActiveCellChanging(TcxSSBookSheet* Sender, const System::Types::TPoint ActiveCell, bool &CanSelect);
	virtual void __fastcall OnActiveSheetChanging(TcxCustomSpreadSheetBook* Sender, const int ActiveSheet, bool &CanSelect);
	virtual void __fastcall OnChangeCellData(TcxSSBookSheet* Sender, const int ACol, const int ARow);
	virtual void __fastcall OnChangeDefaultStyle(const Cxsstypes::TcxSSCellStyleRec &AOldValue, const Cxsstypes::TcxSSCellStyleRec &ANewValue);
	virtual void __fastcall OnChangeLockColRow(TcxSSBookSheet* Sender, Cxsstypes::TcxSSHeaderType AKind, int AIndex, bool AOldValue, bool ANewValue);
	virtual void __fastcall OnChangeSelection(TcxSSBookSheet* Sender, const System::Types::TRect &AOldValue, const System::Types::TRect &ANewValue);
	virtual void __fastcall OnChangeSheetCaption(TcxSSBookSheet* Sender, System::UnicodeString &ACaption);
	virtual void __fastcall OnChangeSizeColRow(TcxSSBookSheet* Sender, Cxsstypes::TcxSSHeaderType AKind, int AIndex, System::Word &ANewSize);
	virtual void __fastcall OnChangeVisibleColRow(TcxSSBookSheet* Sender, Cxsstypes::TcxSSHeaderType AKind, int AIndex, bool AOldValue, bool ANewValue);
	virtual void __fastcall OnClearCells(TcxSSBookSheet* Sender, const System::Types::TRect &ACellRec, bool &AUseDefaultStyle, bool &CanClear);
	virtual void __fastcall OnEditing(TcxSSBookSheet* Sender, const int ACol, const int ARow, bool &CanEdit);
	virtual void __fastcall OnDeleteCells(TcxSSBookSheet* Sender, System::Types::TRect &ACellRect, Cxsstypes::TcxSSModifyType AModifyType);
	virtual void __fastcall OnHistoryChanged(System::TObject* Sender);
	virtual void __fastcall OnInsertCells(TcxSSBookSheet* Sender, System::Types::TRect &ACellRect, Cxsstypes::TcxSSModifyType AModifyType);
	virtual void __fastcall OnMergeCells(TcxSSBookSheet* Sender, System::Types::TRect &ACellRect, bool AIsMerge, bool &CanMerge);
	virtual void __fastcall OnProgress(System::TObject* Sender, System::Byte APercent);
	virtual void __fastcall OnResizeDataLength(TcxSSBookSheet* Sender, Cxsstypes::TcxSSHeaderType AType);
	virtual void __fastcall OnSheetPopupMenu(TcxSSBookSheet* Sender, const System::Types::TPoint AHitPoint);
	virtual void __fastcall OnTopLeftChanging(TcxSSBookSheet* Sender, System::Types::TPoint &ATopLeft);
	virtual void __fastcall OnCaptionPopupMenu(TcxSSBookSheet* Sender, const System::Types::TPoint AHitPoint);
	virtual void __fastcall UpdateAfterChanged(TcxSSBookSheet* Sender, System::Types::TRect &ACellRect);
	__property int LockRef = {read=FLockCount, nodefault};
	
public:
	__fastcall virtual TcxSSListener(TcxCustomSpreadSheetBook* AOwner);
	__property TcxCustomSpreadSheetBook* Owner = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSSListener(void) { }
	
};


class DELPHICLASS TcxWorkBookSubControl;
class PASCALIMPLEMENTATION TcxWorkBookSubControl : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	System::Types::TRect FBounds;
	TcxCustomSpreadSheetBook* FOwner;
	bool FVisible;
	System::Types::TRect __fastcall GetBoundsRect(void);
	Cxsspainterwrapper::TcxCanvasWrapper* __fastcall GetCanvas(void);
	System::Types::TRect __fastcall GetClientRect(void);
	Vcl::Graphics::TCanvas* __fastcall GetControlCanvas(void);
	System::Uitypes::TCursor __fastcall GetCursor(void);
	int __fastcall GetHeight(void);
	int __fastcall GetLeft(void);
	int __fastcall GetTop(void);
	int __fastcall GetWidth(void);
	void __fastcall SetBoundsRect(System::Types::TRect &ARect);
	void __fastcall SetCursor(const System::Uitypes::TCursor Value);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetWidth(const int Value);
	
protected:
	System::Types::TPoint __fastcall ClientToScreen(const int X, const int Y);
	virtual void __fastcall DblClick(void);
	virtual void __fastcall FocusChanged(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Resize(void);
	void __fastcall SetBounds(const int ALeft, const int ATop, const int AWidth, const int AHeight);
	virtual void __fastcall VisibleChanging(void);
	__property Cxsspainterwrapper::TcxCanvasWrapper* Canvas = {read=GetCanvas};
	__property Vcl::Graphics::TCanvas* ControlCanvas = {read=GetControlCanvas};
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property TcxCustomSpreadSheetBook* Owner = {read=FOwner};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property System::Uitypes::TCursor Cursor = {read=GetCursor, write=SetCursor, nodefault};
	
public:
	__fastcall virtual TcxWorkBookSubControl(TcxCustomSpreadSheetBook* AOwner);
	virtual void __fastcall Invalidate(void);
	void __fastcall InvalidateRect(System::Types::TRect &ARect);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWorkBookSubControl(void) { }
	
};


typedef System::TMetaClass* TcxSSBookPageCaptionsClass;

class DELPHICLASS TcxSSBookPageCaptions;
class PASCALIMPLEMENTATION TcxSSBookPageCaptions : public TcxWorkBookSubControl
{
	typedef TcxWorkBookSubControl inherited;
	
private:
	Cxsseditors::TcxSSInplaceTextEdit* FCaptionEditor;
	Cxsspainters::TcxPageCaptionPainter* FCaptionPainter;
	bool FIsEditorActivate;
	System::Types::TPoint FMouseDownPos;
	bool FSkipActivePageChanging;
	Cxssviewinfo::TcxSSBookCaptionViewInfo FViewInfo;
	int __fastcall GetFirstVisibleCaption(void);
	void __fastcall SetFirstVisibleCaption(const int Value);
	
protected:
	void __fastcall ActivateEditor(void);
	virtual void __fastcall DblClick(void);
	virtual void __fastcall DoEditCaption(void);
	System::Types::TRect __fastcall GetCaptionTextExtent(int APage);
	Cxssviewinfo::TcxSSCaptionHitTest __fastcall HitTest(int X, int Y, int &AIndex);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall OnEditCaptionText(System::TObject* Sender);
	virtual void __fastcall OnEndEditCaption(System::TObject* Sender);
	virtual void __fastcall Paint(void);
	virtual void __fastcall ReCalcViewInfo(void);
	virtual void __fastcall Resize(void);
	virtual void __fastcall UpdateCaptionInfo(System::Byte APage, Cxssviewinfo::TcxSSCaptionStates AState);
	virtual void __fastcall VisibleChanging(void);
	__property Cxssviewinfo::TcxSSBookCaptionViewInfo ViewInfo = {read=FViewInfo};
	__property Cxsspainters::TcxPageCaptionPainter* PageCaptionPainter = {read=FCaptionPainter, write=FCaptionPainter};
	
public:
	__property int FirstVisibleCaption = {read=GetFirstVisibleCaption, write=SetFirstVisibleCaption, nodefault};
	__fastcall virtual TcxSSBookPageCaptions(TcxCustomSpreadSheetBook* AOwner);
	__fastcall virtual ~TcxSSBookPageCaptions(void);
	void __fastcall MakeTabVisible(int AIndex);
};


class DELPHICLASS TcxSSCellObject;
class PASCALIMPLEMENTATION TcxSSCellObject : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	int FCol;
	Cxsshistory::TcxComplexAction* FComplexAction;
	Cxssstyles::TcxSSCellStyle* FCreatedStyle;
	Cxssdata::TcxSSDataStorage* FOwner;
	Cxsshistory::TcxCustomAction* FAction;
	int FRow;
	Cxssintf::_di_IcxSpreadSheetCellStyle __fastcall GetCellStyle(void);
	System::UnicodeString __fastcall GetCellTextValue(void);
	System::Variant __fastcall GetCellValue(void);
	Cxsstypes::TcxSSDataType __fastcall GetDataType(void);
	System::TDateTime __fastcall GetDateTime(void);
	System::UnicodeString __fastcall GetDisplayText(void);
	Cxsstypes::TcxDisplayTextAlignment __fastcall GetDisplayTextAlignment(void);
	bool __fastcall GetIsLoading(void);
	System::Types::TRect __fastcall GetMergedRect(void);
	TcxSSBookSheet* __fastcall GetOwnerSheet(void);
	Cxssstyles::TcxSSCellStyle* __fastcall GetStyle(void);
	bool __fastcall GetStyleExist(void);
	System::UnicodeString __fastcall GetText(void);
	void __fastcall SetDateTime(const System::TDateTime Value);
	void __fastcall SetStyle(Cxssstyles::TcxSSCellStyle* const Value);
	void __fastcall SetText(const System::UnicodeString Value);
	void __fastcall SetTextEx(const System::UnicodeString Value, bool IsFormula = false, bool Analyze = true);
	
protected:
	void __fastcall CheckCellWordBreak(void);
	__property Cxsshistory::TcxCustomAction* Action = {read=FAction};
	__property Cxsshistory::TcxComplexAction* ComplexAction = {read=FComplexAction};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property Cxssdata::TcxSSDataStorage* Owner = {read=FOwner};
	__property TcxSSBookSheet* OwnerSheet = {read=GetOwnerSheet};
	__property System::Types::TRect MergedRect = {read=GetMergedRect};
	
public:
	__fastcall virtual TcxSSCellObject(Cxssdata::TcxSSDataStorage* AOwner, int ACol, int ARow);
	__fastcall virtual ~TcxSSCellObject(void);
	virtual void __fastcall Assign(TcxSSCellObject* Source);
	void __fastcall SetCellText(const System::UnicodeString AText, const bool NeedParse = false);
	__property int Col = {read=FCol, nodefault};
	__property System::TDateTime DateTime = {read=GetDateTime, write=SetDateTime};
	__property Cxsstypes::TcxSSDataType DataType = {read=GetDataType, nodefault};
	__property System::UnicodeString DisplayText = {read=GetDisplayText};
	__property Cxsstypes::TcxDisplayTextAlignment DisplayTextAlignment = {read=GetDisplayTextAlignment, nodefault};
	__property System::UnicodeString Text = {read=GetText, write=SetText};
	__property int Row = {read=FRow, nodefault};
	__property System::Variant CellValue = {read=GetCellValue};
	__property Cxssstyles::TcxSSCellStyle* Style = {read=GetStyle, write=SetStyle};
	__property bool StyleExist = {read=GetStyleExist, nodefault};
private:
	void *__IcxSpreadSheetCell;	/* Cxssintf::IcxSpreadSheetCell */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4D22A8C2-F327-4080-B3B6-D8526CE00F0E}
	operator Cxssintf::_di_IcxSpreadSheetCell()
	{
		Cxssintf::_di_IcxSpreadSheetCell intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxssintf::IcxSpreadSheetCell*(void) { return (Cxssintf::IcxSpreadSheetCell*)&__IcxSpreadSheetCell; }
	#endif
	
};


enum TcxSSSheetState : unsigned char { ssResize, ssColHeader, ssRowHeader, ssEditorActivate, ssSelection };

typedef System::Set<TcxSSSheetState, TcxSSSheetState::ssResize, TcxSSSheetState::ssSelection>  TcxSSSheetStates;

class PASCALIMPLEMENTATION TcxSSBookSheet : public TcxWorkBookSubControl
{
	typedef TcxWorkBookSubControl inherited;
	
private:
	System::Word FChangedSizeValue;
	System::Types::TPoint FCurrentPos;
	Cxssdata::TcxSSDataStorage* FDataStorage;
	System::Types::TPoint FDownCellPos;
	System::Types::TPoint FEditingPos;
	bool FIsEditMode;
	System::Types::TPoint FMouseDownPos;
	bool FProtected;
	bool FReadOnly;
	Cxsstypes::TcxSSHeaderType FResizeHeaderType;
	Cxssviewinfo::TcxSSheetViewInfo* FSheetViewInfo;
	TcxSSSheetStates FSheetState;
	bool FShowGrid;
	bool FShowHeaders;
	bool FShowFormulas;
	int FSizeIndex;
	System::Types::TPoint FStartSelection;
	System::Types::TPoint __fastcall GetActiveCell(void);
	Cxssintf::_di_IcxSpreadSheetCell __fastcall GetCell(const int ACol, const int ARow);
	Cxsseditors::TcxSSInplaceTextEdit* __fastcall GetCellEditor(void);
	Cxssheaders::TcxSSHeader* __fastcall GetColHeader(void);
	int __fastcall GetColumnCount(void);
	System::Types::TRect __fastcall GetCorners(void);
	int __fastcall GetContentColCount(void);
	int __fastcall GetContentRowCount(void);
	int __fastcall GetCurrentCol(void);
	int __fastcall GetCurrentRow(void);
	Cxsshistory::TcxSpreadSheetHistory* __fastcall GetHistory(void);
	bool __fastcall GetIsLoaded(void);
	TcxSSListener* __fastcall GetListener(void);
	int __fastcall GetPageIndex(void);
	System::UnicodeString __fastcall GetSheetCaption(void);
	int __fastcall GetRowCount(void);
	Cxssheaders::TcxSSHeader* __fastcall GetRowHeader(void);
	System::Types::TRect __fastcall GetSelectionRect(void);
	System::Types::TPoint __fastcall GetTopLeft(void);
	void __fastcall SetActiveCell(const System::Types::TPoint Value);
	void __fastcall SetColRowSize(const Cxsstypes::TcxSSHeaderType AKind, const int AColumn, const int ASize, const int AOriginalSize, bool ALocked, bool AVisible = true);
	void __fastcall SetCorners(const System::Types::TRect &Value);
	void __fastcall SetDefaultSize(const Cxsstypes::TcxSSHeaderType AKind, int ASize);
	void __fastcall SetMergedCells(const System::Types::TRect &ARect, bool IsMerge);
	void __fastcall SetPageDimension(const int AHorzCount, const int AVertCount);
	void __fastcall SetProtection(bool Value);
	void __fastcall SetSheetCaption(System::UnicodeString Value);
	void __fastcall SetShowGrid(const bool Value);
	void __fastcall SetShowHeaders(const bool Value);
	void __fastcall SetShowFormulas(const bool Value);
	void __fastcall SetSelectionRect(System::Types::TRect &Value);
	void __fastcall SetTopLeft(const System::Types::TPoint Value);
	void __fastcall SetViewInformation(const System::Types::TRect &ASelectionRect, bool AViewFormulas, bool AViewGrid, bool AViewHeaders, bool AScrollBars);
	
protected:
	virtual void __fastcall CellsChanged(const System::Types::TRect &ARect);
	virtual void __fastcall DblClick(void);
	virtual bool __fastcall DoEditorActivate(void);
	virtual bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	virtual void __fastcall FocusChanged(void);
	virtual void __fastcall InitScrollBars(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall OnEndEditCell(System::TObject* Sender);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos, bool IsViewInfoUpdate = true);
	bool __fastcall ViewInfoValid(void);
	__property System::Types::TPoint CurrentPos = {read=FCurrentPos};
	__property Cxsseditors::TcxSSInplaceTextEdit* CellEditor = {read=GetCellEditor};
	__property Cxssdata::TcxSSDataStorage* DataStorage = {read=FDataStorage};
	__property bool IsEditMode = {read=FIsEditMode, write=FIsEditMode, nodefault};
	__property bool IsLoaded = {read=GetIsLoaded, nodefault};
	__property Cxsshistory::TcxSpreadSheetHistory* History = {read=GetHistory};
	__property TcxSSListener* Listener = {read=GetListener};
	__property System::Types::TPoint TopLeft = {read=GetTopLeft, write=SetTopLeft};
	__property Cxssviewinfo::TcxSSheetViewInfo* ViewInfo = {read=FSheetViewInfo};
	
public:
	__fastcall virtual TcxSSBookSheet(TcxCustomSpreadSheetBook* AOwner);
	__fastcall virtual ~TcxSSBookSheet(void);
	virtual void __fastcall ApplyAutoHeight(int ARow);
	virtual void __fastcall Assign(TcxSSBookSheet* Source);
	virtual void __fastcall ClearAll(void);
	void __fastcall ClearCells(const System::Types::TRect &ARect, bool SetDefaultStyle = false);
	void __fastcall Copy(const System::Types::TRect &ARect, bool IsCut);
	void __fastcall DeleteCells(const System::Types::TRect &ACells, Cxsstypes::TcxSSCellsModify ACellsModify);
	void __fastcall FormatCells(const System::Types::TRect &ACells);
	virtual TcxSSCellObject* __fastcall GetCellObject(int ACol, int ARow);
	void __fastcall InsertCells(const System::Types::TRect &ACells, Cxsstypes::TcxSSCellsModify ACellsModify);
	virtual void __fastcall Invalidate(void);
	void __fastcall Paste(const System::Types::TPoint APlace);
	void __fastcall SelectCell(const int ACol, const int ARow, bool OpenEditor = false);
	void __fastcall SetMergedState(const System::Types::TRect &ARect, bool IsMerge);
	void __fastcall SetVisibleState(const System::Types::TRect &ARect, bool ACols, bool ARows, bool AShow);
	void __fastcall Sort(const System::Types::TRect &ARect, Cxsstypes::TcxSortType const *ASortTypes, const int ASortTypes_Size);
	__property System::Types::TPoint ActiveCell = {read=GetActiveCell, write=SetActiveCell};
	__property System::UnicodeString Caption = {read=GetSheetCaption, write=SetSheetCaption};
	__property int Col = {read=GetCurrentCol, nodefault};
	__property Cxssheaders::TcxSSHeader* Cols = {read=GetColHeader};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property System::Types::TRect Corners = {read=GetCorners, write=SetCorners};
	__property int ContentColCount = {read=GetContentColCount, nodefault};
	__property int ContentRowCount = {read=GetContentRowCount, nodefault};
	__property int PageIndex = {read=GetPageIndex, nodefault};
	__property bool Protected = {read=FProtected, write=FProtected, nodefault};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, nodefault};
	__property int Row = {read=GetCurrentRow, nodefault};
	__property Cxssheaders::TcxSSHeader* Rows = {read=GetRowHeader};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property System::Types::TRect SelectionRect = {read=GetSelectionRect, write=SetSelectionRect};
	__property bool ShowGrid = {read=FShowGrid, write=SetShowGrid, nodefault};
	__property bool ShowHeaders = {read=FShowHeaders, write=SetShowHeaders, nodefault};
	__property bool ShowFormulas = {read=FShowFormulas, write=SetShowFormulas, nodefault};
private:
	void *__IcxBookSheet;	/* Cxssintf::IcxBookSheet */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6EA75673-9538-4626-97C8-08A5A818FCB4}
	operator Cxssintf::_di_IcxBookSheet()
	{
		Cxssintf::_di_IcxBookSheet intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxssintf::IcxBookSheet*(void) { return (Cxssintf::IcxBookSheet*)&__IcxBookSheet; }
	#endif
	
};


typedef void __fastcall (__closure *TcxSSActiveCellChangingEvent)(TcxSSBookSheet* Sender, const System::Types::TPoint ActiveCell, bool &CanSelect);

typedef void __fastcall (__closure *TcxSSActiveSheetChangingEvent)(TcxCustomSpreadSheetBook* Sender, const int ActiveSheet, bool &CanSelect);

typedef void __fastcall (__closure *TcxSSCellChangeEvent)(TcxSSBookSheet* Sender, const int ACol, const int ARow);

typedef void __fastcall (__closure *TcxSSClearCellsEvent)(TcxSSBookSheet* Sender, const System::Types::TRect &ACellRect, bool &UseDefaultStyle, bool &CanClear);

typedef void __fastcall (__closure *TcxSSCustomPaintEvent)(System::TObject* Sender, Cxsspainters::TcxSheetPainterClass &PainterClass);

typedef void __fastcall (__closure *TcxSSDeleteSheetEvent)(const int ASheet, bool &CanDelete);

typedef void __fastcall (__closure *TcxSSExchangeSheetsEvent)(const int ASheet1, const int ASheet2, bool &CanExchange);

typedef void __fastcall (__closure *TcxSSSetSelectionEvent)(System::TObject* Sender, TcxSSBookSheet* ASheet);

typedef void __fastcall (__closure *TcxSSSetPositionEvent)(System::TObject* Sender, TcxSSBookSheet* ASheet);

typedef void __fastcall (__closure *TcxSSChangeVisible)(System::TObject* Sender, TcxSSBookSheet* ASheet, int AChangedIndex, bool APrevValue, bool ANewValue);

typedef void __fastcall (__closure *TcxSSPopupMenuEvent)(System::TObject* Sender, int X, int Y);

typedef void __fastcall (__closure *TcxSSResizeEvent)(TcxSSBookSheet* Sender, int AIndex, System::Word &ANewSize);

typedef void __fastcall (__closure *TcxSSFormatCellsEvent)(System::TObject* Sender, System::Types::TRect &ACells, bool &CanFormat, /* out */ TcxSSFormatDialogClass &FormatDialogClass);

typedef void __fastcall (__closure *TcxSSTopLeftChangingEvent)(TcxSSBookSheet* Sender, System::Types::TPoint &ATopLeft);

typedef void __fastcall (__closure *TcxSSMergeCellsEvent)(TcxSSBookSheet* Sender, System::Types::TRect &ACellRect, bool AIsMerge, bool &CanMerge);

typedef void __fastcall (__closure *TcxSSChangeCaptionEvent)(TcxSSBookSheet* Sender, System::UnicodeString &ACaption);

typedef void __fastcall (__closure *TcxSSEditingEvent)(TcxSSBookSheet* Sender, const int ACol, const int ARow, bool &CanEdit);

class PASCALIMPLEMENTATION TcxCustomSpreadSheetBook : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	typedef System::DynamicArray<bool> _TcxCustomSpreadSheetBook__1;
	
	
public:
	TcxSSBookSheet* operator[](int APage) { return Pages[APage]; }
	
private:
	Vcl::Extctrls::TTimer* FTimer;
	int FActivePage;
	bool FBufferedPaint;
	Cxsspainterwrapper::TcxCanvasWrapper* FCanvas;
	TcxSSBookPageCaptions* FCaptionBar;
	TcxWorkBookSubControl* FCaptureControl;
	Cxsseditors::TcxSSInplaceTextEdit* FCellEditor;
	int FColHeaderHeight;
	bool FContextPopupHandled;
	System::Word FDefaultColWidth;
	System::Word FDefaultRowHeight;
	Cxssformulas::TcxSSFormulasCache* FFormulasCache;
	System::Byte FFloatPrecision;
	System::Uitypes::TColor FGridColor;
	System::Uitypes::TColor FHeaderColor;
	Vcl::Graphics::TFont* FHeaderFont;
	Cxsshistory::TcxSpreadSheetHistory* FHistory;
	bool FHideSelection;
	bool FIsLoaded;
	TcxSSListener* FListener;
	bool FProtected;
	System::Types::TPoint FMouseDownPos;
	System::Types::TPoint FMousePos;
	bool FModified;
	Cxsspainters::TcxSheetPainter* FPainter;
	Vcl::Graphics::TBitmap* FPaintBitmap;
	Cxsstypes::TcxSSPainterType FPainterType;
	System::Classes::TList* FPages;
	_TcxCustomSpreadSheetBook__1 FPageVisible;
	Cxexcelconst::TcxExcelPalette FPalette;
	bool FReadOnly;
	int FRowHeaderWidth;
	bool FRowsAutoHeight;
	TcxScrollBars FScrollBars;
	System::Uitypes::TColor FSelectionColor;
	System::Classes::TShiftState FShift;
	bool FShowCaptionBar;
	bool FShowFormulas;
	bool FShowGrid;
	Cxssstyles::TcxSSStyleCache* FStyleCache;
	System::Uitypes::TColor FWindowColor;
	TcxSSActiveCellChangingEvent FOnActiveCellChanging;
	TcxSSActiveSheetChangingEvent FOnActiveSheetChanging;
	System::Classes::TNotifyEvent FOnAfterCalculation;
	TcxSSPopupMenuEvent FOnCaptionPopupMenu;
	TcxSSCellChangeEvent FOnCellChange;
	TcxSSClearCellsEvent FOnClearCells;
	TcxSSChangeVisible FOnChangeColVisible;
	TcxSSChangeCaptionEvent FOnChangeCaption;
	TcxSSChangeVisible FOnChangeRowVisible;
	TcxSSCustomPaintEvent FOnCustomPaint;
	TcxSSEditingEvent FOnEditing;
	System::Classes::TNotifyEvent FOnEndEdit;
	TcxSSFormatCellsEvent FOnFormatCells;
	System::Classes::TNotifyEvent FOnHistoryChanged;
	TcxSSMergeCellsEvent FOnMergeCells;
	Cxexcelaccess::TcxProgressEvent FOnProgress;
	TcxSSResizeEvent FOnResizeCol;
	TcxSSResizeEvent FOnResizeRow;
	TcxSSSetSelectionEvent FOnSetSelection;
	TcxSSPopupMenuEvent FOnSheetPopupMenu;
	TcxSSTopLeftChangingEvent FOnTopLeftChanging;
	bool FExcelProtectionStyle;
	Cxssintf::_di_IcxBookSheet __fastcall AddSheet(const System::UnicodeString AName, bool AVisible);
	System::Types::TPoint __fastcall GetActiveCell(void);
	TcxSSBookSheet* __fastcall GetActiveSheet(void);
	bool __fastcall GetAutoReCalc(void);
	Cxssintf::_di_IcxSpreadSheetCell __fastcall GetCell(System::Word APage, int ACol, int ARow);
	Cxsstypes::TcxSSNamesDef __fastcall GetDefinedNames(void);
	Cxssstyles::TcxSSDefaultStyle* __fastcall GetDefaultStyle(void);
	TcxSSBookSheet* __fastcall GetPage(int APage);
	System::Word __fastcall GetPageCount(void);
	System::Types::TRect __fastcall GetPageSelection(System::Word APage);
	bool __fastcall GetPageVisible(System::Word APage);
	bool __fastcall GetRCRefStyle(void);
	System::Types::TRect __fastcall GetSelection(void);
	Cxssintf::_di_IcxBookSheet __fastcall GetSheet(System::Word APage);
	bool __fastcall GetShowHeaders(void);
	void __fastcall SetActiveCell(const System::Types::TPoint AValue);
	void __fastcall SetActivePage(int AValue);
	void __fastcall SetAutoRecalc(const bool AValue);
	void __fastcall SetBufferedPaint(const bool AValue);
	void __fastcall SetColHeaderHeight(const int AValue);
	void __fastcall SetCustomPainter(const TcxSSCustomPaintEvent AValue);
	void __fastcall SetDefaultColWidth(const System::Word AValue);
	void __fastcall SetDefaultStyle(const Cxsstypes::PcxSSCellStyleRec AStyle);
	void __fastcall SetDefaultStyleProperty(Cxssstyles::TcxSSDefaultStyle* AValue);
	void __fastcall SetDefaultRowHeight(const System::Word AValue);
	void __fastcall SetDefaultColor(const System::Uitypes::TColor AValue);
	void __fastcall SetFloatPrecision(const System::Byte AValue);
	void __fastcall SetGridColor(const System::Uitypes::TColor AValue);
	void __fastcall SetHeaderFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetHeaderColor(const System::Uitypes::TColor AValue);
	void __fastcall SetPainterType(const Cxsstypes::TcxSSPainterType AValue);
	void __fastcall SetPageCount(const System::Word AValue);
	void __fastcall SetPageSelection(System::Word APage, const System::Types::TRect &AValue);
	void __fastcall SetPageVisible(System::Word APage, const bool AValue);
	void __fastcall SetPalette(const Cxexcelconst::PcxExcelPalette APalette);
	void __fastcall SetProtection(bool Value);
	void __fastcall SetRCRefStyle(const bool AValue);
	void __fastcall SetReadOnly(const bool AValue);
	void __fastcall SetRowHeaderWidth(const int AValue);
	void __fastcall SetSelectionColor(const System::Uitypes::TColor AValue);
	HIDESBASE void __fastcall SetScrollBars(const TcxScrollBars AValue);
	void __fastcall SetShowCaptionBar(const bool AValue);
	void __fastcall SetShowFormulas(const bool AValue);
	void __fastcall SetShowHeaders(const bool AValue);
	void __fastcall SetShowGrid(const bool AValue);
	void __fastcall SetSelection(const System::Types::TRect &AValue);
	MESSAGE void __fastcall CM_CHANGELOCALE(Winapi::Messages::TMessage &Message);
	
protected:
	bool IsDataLoading;
	virtual void __fastcall AddPage(TcxSSBookSheet* ASheet);
	virtual void __fastcall AddSheetPage(const System::UnicodeString APageName = System::UnicodeString());
	virtual void __fastcall AdjustControls(void);
	DYNAMIC void __fastcall DblClick(void);
	void __fastcall DoRecalc(void);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	DYNAMIC void __fastcall DoContextPopup(System::Types::TPoint MousePos, bool &Handled);
	virtual void __fastcall DoGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind, int ANewScrollPos);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual TcxSSBookPageCaptionsClass __fastcall GetBookPageCaptionsClass(void);
	virtual Cxsspainters::TcxPageCaptionPainterClass __fastcall GetCaptionPainterClass(void);
	virtual Cxssdata::TcxSSDataStorageClass __fastcall GetDataStorageClass(void);
	virtual Cxssformulas::TcxFormulasCacheClass __fastcall GetFormulasCacheClass(void);
	virtual Cxssheaders::TcxSSHeaderClass __fastcall GetHeaderClass(void);
	virtual Cxsshistory::TcxSSHistoryClass __fastcall GetHistoryClass(void);
	virtual System::Types::TRect __fastcall GetHScrollBarBounds(void);
	virtual Cxsseditors::TcxSSInplaceEditClass __fastcall GetInplaceEditClass(void);
	virtual TcxSSListenerClass __fastcall GetListenerClass(void);
	virtual Cxsspainters::TcxSheetPainterClass __fastcall GetPainterClass(void);
	Cxexcelconst::PcxExcelPalette __fastcall GetPalettePtr(void);
	virtual Cxssstyles::TcxSSStyleCacheClass __fastcall GetStyleCacheClass(void);
	virtual TcxSSBookSheetClass __fastcall GetSheetClass(void);
	virtual System::Types::TRect __fastcall GetVScrollBarBounds(void);
	virtual Cxssviewinfo::TcxSSheetViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall InternalUpdate(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall OnChangeHeaderStyle(System::TObject* Sender);
	virtual void __fastcall OnMouseTimerHandle(System::TObject* Sender);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual bool __fastcall SpreadSheetClipboardDataToData(TcxSSBookSheet* ASheet, const int AColPos, const int ARowPos, /* out */ System::Types::TRect &AChangedRect);
	virtual System::AnsiString __fastcall SpreadSheetDataToClipboardData(TcxSSBookSheet* ASheet, const System::Types::TRect &ACells);
	void __fastcall SetModified(void);
	DYNAMIC void __fastcall VisibleChanging(void);
	bool __fastcall ViewInfoValid(void);
	__property System::Types::TPoint ActiveCell = {read=GetActiveCell, write=SetActiveCell};
	__property int ActivePage = {read=FActivePage, write=SetActivePage, nodefault};
	__property TcxSSBookSheet* ActiveSheet = {read=GetActiveSheet};
	__property bool AutoRecalc = {read=GetAutoReCalc, write=SetAutoRecalc, default=1};
	__property TcxWorkBookSubControl* CaptureControl = {read=FCaptureControl};
	__property int ColHeaderHeight = {read=FColHeaderHeight, write=SetColHeaderHeight, default=20};
	__property TcxSSBookPageCaptions* CaptionBar = {read=FCaptionBar};
	__property Cxsspainterwrapper::TcxCanvasWrapper* Canvas = {read=FCanvas};
	__property System::Word DefaultColWidth = {read=FDefaultColWidth, write=SetDefaultColWidth, default=85};
	__property System::Word DefaultRowHeight = {read=FDefaultRowHeight, write=SetDefaultRowHeight, default=20};
	__property Cxssstyles::TcxSSDefaultStyle* DefaultStyle = {read=GetDefaultStyle, write=SetDefaultStyleProperty};
	__property Cxsstypes::TcxSSNamesDef DefinedNames = {read=GetDefinedNames};
	__property Cxssformulas::TcxSSFormulasCache* FormulasCache = {read=FFormulasCache};
	__property System::Uitypes::TColor GridColor = {read=FGridColor, write=SetGridColor, default=-16777201};
	__property System::Uitypes::TColor HeaderColor = {read=FHeaderColor, write=SetHeaderColor, default=-16777201};
	__property Vcl::Graphics::TFont* HeaderFont = {read=FHeaderFont, write=SetHeaderFont};
	__property Cxsshistory::TcxSpreadSheetHistory* History = {read=FHistory};
	__property bool IsLoaded = {read=FIsLoaded, nodefault};
	__property TcxSSListener* Listener = {read=FListener};
	__property System::Word PageCount = {read=GetPageCount, write=SetPageCount, default=1};
	__property System::Types::TRect PageSelection[System::Word APage] = {read=GetPageSelection, write=SetPageSelection};
	__property TcxSSBookSheet* Pages[int APage] = {read=GetPage/*, default*/};
	__property bool PageVisible[System::Word APage] = {read=GetPageVisible, write=SetPageVisible};
	__property Vcl::Graphics::TBitmap* PaintBitmap = {read=FPaintBitmap};
	__property Cxsspainters::TcxSheetPainter* Painter = {read=FPainter};
	__property Cxsstypes::TcxSSPainterType PainterType = {read=FPainterType, write=SetPainterType, default=0};
	__property Cxexcelconst::PcxExcelPalette Palette = {read=GetPalettePtr};
	__property System::Byte Precision = {read=FFloatPrecision, write=SetFloatPrecision, default=2};
	__property int RowHeaderWidth = {read=FRowHeaderWidth, write=SetRowHeaderWidth, default=85};
	__property System::Uitypes::TColor SelectionColor = {read=FSelectionColor, write=SetSelectionColor, default=-16777203};
	__property Cxssstyles::TcxSSStyleCache* StyleCache = {read=FStyleCache};
	__property bool ShowCaptionBar = {read=FShowCaptionBar, write=SetShowCaptionBar, default=1};
	__property bool ShowFormulas = {read=FShowFormulas, write=SetShowFormulas, default=0};
	__property bool ShowGrid = {read=FShowGrid, write=SetShowGrid, default=1};
	__property bool ShowHeaders = {read=GetShowHeaders, write=SetShowHeaders, default=1};
	__property System::Types::TRect SelectionRect = {read=GetSelection, write=SetSelection};
	__property TcxSSActiveCellChangingEvent OnActiveCellChanging = {read=FOnActiveCellChanging, write=FOnActiveCellChanging};
	__property TcxSSActiveSheetChangingEvent OnActiveSheetChanging = {read=FOnActiveSheetChanging, write=FOnActiveSheetChanging};
	__property System::Classes::TNotifyEvent OnAfterCalculation = {read=FOnAfterCalculation, write=FOnAfterCalculation};
	__property TcxSSChangeVisible OnChangeColVisible = {read=FOnChangeColVisible, write=FOnChangeColVisible};
	__property TcxSSChangeCaptionEvent OnChangeSheetCaption = {read=FOnChangeCaption, write=FOnChangeCaption};
	__property TcxSSChangeVisible OnChangeRowVisible = {read=FOnChangeRowVisible, write=FOnChangeRowVisible};
	__property TcxSSCellChangeEvent OnCellChange = {read=FOnCellChange, write=FOnCellChange};
	__property TcxSSClearCellsEvent OnClearCells = {read=FOnClearCells, write=FOnClearCells};
	__property TcxSSCustomPaintEvent OnCustomPaint = {read=FOnCustomPaint, write=SetCustomPainter};
	__property TcxSSEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property System::Classes::TNotifyEvent OnEndEdit = {read=FOnEndEdit, write=FOnEndEdit};
	__property TcxSSFormatCellsEvent OnFormatCells = {read=FOnFormatCells, write=FOnFormatCells};
	__property System::Classes::TNotifyEvent OnHistoryChanged = {read=FOnHistoryChanged, write=FOnHistoryChanged};
	__property TcxSSMergeCellsEvent OnMergeCells = {read=FOnMergeCells, write=FOnMergeCells};
	__property Cxexcelaccess::TcxProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property TcxSSResizeEvent OnResizeCol = {read=FOnResizeCol, write=FOnResizeCol};
	__property TcxSSResizeEvent OnResizeRow = {read=FOnResizeRow, write=FOnResizeRow};
	__property TcxSSSetSelectionEvent OnSetSelection = {read=FOnSetSelection, write=FOnSetSelection};
	__property TcxSSPopupMenuEvent OnSheetPopupMenu = {read=FOnSheetPopupMenu, write=FOnSheetPopupMenu};
	__property TcxSSPopupMenuEvent OnCaptionPopupMenu = {read=FOnCaptionPopupMenu, write=FOnCaptionPopupMenu};
	__property TcxSSTopLeftChangingEvent OnTopLeftChanging = {read=FOnTopLeftChanging, write=FOnTopLeftChanging};
	
public:
	__fastcall virtual TcxCustomSpreadSheetBook(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomSpreadSheetBook(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	int __fastcall BeginUpdate(void);
	System::UnicodeString __fastcall CellsNameByRef(int ASheet, const System::Types::TRect &CellsRef, bool IsText = true);
	void __fastcall ClearAll(void);
	void __fastcall DeactivateEditor(void);
	virtual bool __fastcall DeleteName(const System::UnicodeString AName);
	virtual int __fastcall DefineName(const System::UnicodeString AName, System::Word APage, const System::Types::TRect &ARect);
	virtual int __fastcall DefineNameEx(const System::UnicodeString AName, System::Word APage, const System::Types::TRect &ARect, bool Validate = true);
	int __fastcall EndUpdate(void);
	int __fastcall HasRectName(int ASheet, const System::Types::TRect &ARect);
	virtual bool __fastcall HitTest(const System::Types::TPoint APoint, /* out */ Cxsstypes::TcxSSHitTestInfo &HitTestInfo);
	virtual void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	virtual void __fastcall Recalc(void);
	virtual void __fastcall SaveToFile(const System::UnicodeString AFileName);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	virtual void __fastcall UpdateControl(void);
	__property bool DocumentModified = {read=FModified, nodefault};
	
__published:
	__property bool BufferedPaint = {read=FBufferedPaint, write=SetBufferedPaint, default=0};
	__property bool ExcelProtectionStyle = {read=FExcelProtectionStyle, write=FExcelProtectionStyle, default=1};
	__property bool HideSelection = {read=FHideSelection, write=FHideSelection, default=0};
	__property bool R1C1ReferenceStyle = {read=GetRCRefStyle, write=SetRCRefStyle, default=0};
	__property bool RowsAutoHeight = {read=FRowsAutoHeight, write=FRowsAutoHeight, default=1};
	__property TcxScrollBars ScrollBars = {read=FScrollBars, write=SetScrollBars, default=3};
	__property System::Uitypes::TColor BackgroundColor = {read=FWindowColor, write=SetDefaultColor, default=-16777211};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property bool Protected = {read=FProtected, write=FProtected, default=0};
	__property Visible = {default=1};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomSpreadSheetBook(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IcxSpreadSheetBook;	/* Cxssintf::IcxSpreadSheetBook */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {BD273CEA-BD42-43E1-9E05-2CE37DE710F6}
	operator Cxssintf::_di_IcxSpreadSheetBook()
	{
		Cxssintf::_di_IcxSpreadSheetBook intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxssintf::IcxSpreadSheetBook*(void) { return (Cxssintf::IcxSpreadSheetBook*)&__IcxSpreadSheetBook; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxSpreadSheetBook; }
	#endif
	
};


class DELPHICLASS TcxSSFormatDialog;
class PASCALIMPLEMENTATION TcxSSFormatDialog : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
public:
	__fastcall virtual TcxSSFormatDialog(System::Classes::TComponent* AOwner);
	virtual bool __fastcall Execute(const System::Types::TRect &ACells, TcxSSBookSheet* ASheet);
	
__published:
	__property Position = {default=0};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSSFormatDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxSSFormatDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSSFormatDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class DELPHICLASS TcxSpreadSheetBook;
class PASCALIMPLEMENTATION TcxSpreadSheetBook : public TcxCustomSpreadSheetBook
{
	typedef TcxCustomSpreadSheetBook inherited;
	
private:
	TcxSSDeleteSheetEvent FOnDeleteSheet;
	TcxSSExchangeSheetsEvent FOnExchangeSheets;
	
public:
	__fastcall virtual TcxSpreadSheetBook(System::Classes::TComponent* AOwner);
	virtual void __fastcall AddSheetPage(const System::UnicodeString APageName = System::UnicodeString());
	void __fastcall EditActiveSheetCaption(void);
	virtual void __fastcall ExchangeSheets(const int ASheet1, const int ASheet2);
	virtual void __fastcall DeleteSheet(const int ASheet);
	__property ActiveCell;
	__property ActivePage;
	__property ActiveSheet;
	__property DefinedNames;
	__property History;
	__property Palette;
	__property Pages;
	__property PageVisible;
	__property SelectionRect;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoRecalc = {default=1};
	__property ColHeaderHeight = {default=20};
	__property DefaultStyle;
	__property DefaultColWidth = {default=85};
	__property DefaultRowHeight = {default=20};
	__property GridColor = {default=-16777201};
	__property HeaderFont;
	__property HeaderColor = {default=-16777201};
	__property PainterType = {default=0};
	__property Precision = {default=2};
	__property PageCount = {default=1};
	__property PopupMenu;
	__property RowHeaderWidth = {default=85};
	__property SelectionColor = {default=-16777203};
	__property ShowCaptionBar = {default=1};
	__property ShowFormulas = {default=0};
	__property ShowGrid = {default=1};
	__property ShowHeaders = {default=1};
	__property TcxSSDeleteSheetEvent OnDeleteSheet = {read=FOnDeleteSheet, write=FOnDeleteSheet};
	__property TcxSSExchangeSheetsEvent OnExchangeSheets = {read=FOnExchangeSheets, write=FOnExchangeSheets};
	__property OnActiveCellChanging;
	__property OnActiveSheetChanging;
	__property OnAfterCalculation;
	__property OnCellChange;
	__property OnChangeColVisible;
	__property OnChangeSheetCaption;
	__property OnChangeRowVisible;
	__property OnClearCells;
	__property OnCustomPaint;
	__property OnEditing;
	__property OnEndEdit;
	__property OnFormatCells;
	__property OnHistoryChanged;
	__property OnMergeCells;
	__property OnProgress;
	__property OnResizeCol;
	__property OnResizeRow;
	__property OnSetSelection;
	__property OnSheetPopupMenu;
	__property OnCaptionPopupMenu;
	__property OnTopLeftChanging;
	__property OnEnter;
	__property OnExit;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
public:
	/* TcxCustomSpreadSheetBook.Destroy */ inline __fastcall virtual ~TcxSpreadSheetBook(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSpreadSheetBook(HWND ParentWindow) : TcxCustomSpreadSheetBook(ParentWindow) { }
	
};


class DELPHICLASS TcxSpreadSheet;
class PASCALIMPLEMENTATION TcxSpreadSheet : public TcxCustomSpreadSheetBook
{
	typedef TcxCustomSpreadSheetBook inherited;
	
private:
	HIDESBASE TcxSSBookSheet* __fastcall GetSheet(void);
	
public:
	__fastcall virtual TcxSpreadSheet(System::Classes::TComponent* AOwner);
	__property TcxSSBookSheet* Sheet = {read=GetSheet};
	__property ActiveCell;
	__property History;
	__property DefinedNames;
	__property Palette;
	__property SelectionRect;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoRecalc = {default=1};
	__property ColHeaderHeight = {default=20};
	__property DefaultStyle;
	__property DefaultColWidth = {default=85};
	__property DefaultRowHeight = {default=20};
	__property GridColor = {default=-16777201};
	__property HeaderFont;
	__property HeaderColor = {default=-16777201};
	__property PainterType = {default=0};
	__property Precision = {default=2};
	__property RowHeaderWidth = {default=85};
	__property SelectionColor = {default=-16777203};
	__property ShowFormulas = {default=0};
	__property ShowGrid = {default=1};
	__property ShowHeaders = {default=1};
	__property OnActiveCellChanging;
	__property OnAfterCalculation;
	__property OnCellChange;
	__property OnChangeColVisible;
	__property OnChangeRowVisible;
	__property OnClearCells;
	__property OnCustomPaint;
	__property OnEditing;
	__property OnEndEdit;
	__property OnFormatCells;
	__property OnHistoryChanged;
	__property OnMergeCells;
	__property OnProgress;
	__property OnResizeCol;
	__property OnResizeRow;
	__property OnSetSelection;
	__property OnSheetPopupMenu;
	__property OnTopLeftChanging;
	__property OnEnter;
	__property OnExit;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
public:
	/* TcxCustomSpreadSheetBook.Destroy */ inline __fastcall virtual ~TcxSpreadSheet(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSpreadSheet(HWND ParentWindow) : TcxCustomSpreadSheetBook(ParentWindow) { }
	
};


class DELPHICLASS TcxSSClipboard;
class PASCALIMPLEMENTATION TcxSSClipboard : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::AnsiString __fastcall GetESSData(void);
	System::WideString __fastcall GetUnicodeData(void);
	void __fastcall SetUnicodeData(const System::WideString Value);
	void __fastcall SetESSData(const System::AnsiString Value);
	
protected:
	int __fastcall BufferSize(System::Word AFormat);
	void __fastcall GetBuffer(System::Word AFormat, void *ABuffer);
	void __fastcall SetBuffer(System::Word AFormat, const void *ABuffer, int ASize, bool ClearClipboard);
	
public:
	__property System::WideString DataAsUnicode = {read=GetUnicodeData, write=SetUnicodeData};
	__property System::AnsiString DataAsEssFormat = {read=GetESSData, write=SetESSData};
public:
	/* TObject.Create */ inline __fastcall TcxSSClipboard(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSSClipboard(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall CellReadOnly(System::TObject* ABook, System::TObject* ASheet, int ACol, int ARow);
extern PACKAGE bool __fastcall CanModify(System::TObject* ABook, System::TObject* ASheet, int ACol, int ARow)/* overload */;
extern PACKAGE bool __fastcall CanModify(System::TObject* ABook, System::TObject* ASheet, const System::Types::TRect &ARect)/* overload */;
}	/* namespace Cxssheet */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSHEET)
using namespace Cxssheet;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssheetHPP
