// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridCardView.pas' rev: 24.00 (Win32)

#ifndef CxgridcardviewHPP
#define CxgridcardviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGridCustomLayoutView.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridcardview
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridCardRowLayoutClass;

typedef System::TMetaClass* TcxGridCardViewInfoClass;

enum TcxGridCardExpandButtonAlignment : unsigned char { cebaLeft, cebaRight };

enum TcxGridCardViewLayoutDirection : unsigned char { ldHorizontal, ldVertical };

class DELPHICLASS TcxGridCardRowFilterButtonHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowFilterButtonHitTest : public Cxgridcustomtableview::TcxGridRecordCellHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordCellHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__classmethod virtual bool __fastcall CanClick();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCardRowFilterButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCardRowFilterButtonHitTest(void) : Cxgridcustomtableview::TcxGridRecordCellHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowIndentHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowIndentHitTest : public Cxgridcustomtableview::TcxGridRecordCellHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordCellHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCardRowIndentHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCardRowIndentHitTest(void) : Cxgridcustomtableview::TcxGridRecordCellHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowExpandButtonHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowExpandButtonHitTest : public Cxgridcustomtableview::TcxGridRecordCellHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordCellHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCardRowExpandButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCardRowExpandButtonHitTest(void) : Cxgridcustomtableview::TcxGridRecordCellHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowCellHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowCellHitTest : public Cxgridcustomtableview::TcxGridRecordCellHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordCellHitTest inherited;
	
public:
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCardRowCellHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCardRowCellHitTest(void) : Cxgridcustomtableview::TcxGridRecordCellHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowCaptionHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowCaptionHitTest : public TcxGridCardRowCellHitTest
{
	typedef TcxGridCardRowCellHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	int RowContainerKind;
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCardRowCaptionHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCardRowCaptionHitTest(void) : TcxGridCardRowCellHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardScrollButtonDownHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardScrollButtonDownHitTest : public Cxgridcustomtableview::TcxGridRecordHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__classmethod virtual bool __fastcall CanClick();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCardScrollButtonDownHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCardScrollButtonDownHitTest(void) : Cxgridcustomtableview::TcxGridRecordHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardScrollButtonUpHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardScrollButtonUpHitTest : public Cxgridcustomtableview::TcxGridRecordHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__classmethod virtual bool __fastcall CanClick();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCardScrollButtonUpHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCardScrollButtonUpHitTest(void) : Cxgridcustomtableview::TcxGridRecordHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewSeparatorHitTest;
class DELPHICLASS TcxGridCardViewSeparatorsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewSeparatorHitTest : public Cxgridcustomview::TcxCustomGridHitTest
{
	typedef Cxgridcustomview::TcxCustomGridHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	int Index;
	TcxGridCardViewSeparatorsViewInfo* Separators;
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCardViewSeparatorHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCardViewSeparatorHitTest(void) : Cxgridcustomview::TcxCustomGridHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCard;
class DELPHICLASS TcxGridCardView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCard : public Cxgridcustomlayoutview::TcxGridCustomLayoutRecord
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutRecord inherited;
	
private:
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheItemClass __fastcall GetViewInfoCacheItemClass(void);
	
public:
	void __fastcall GetVisibleRows(System::Classes::TList* ARows);
	__property TcxGridCardView* GridView = {read=GetGridView};
public:
	/* TcxGridCustomLayoutRecord.Create */ inline __fastcall virtual TcxGridCard(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutRecord(AViewData, AIndex, ARecordInfo) { }
	
public:
	/* TcxCustomGridRecord.Destroy */ inline __fastcall virtual ~TcxGridCard(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewViewData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewViewData : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewData
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewData inherited;
	
private:
	TcxGridCard* __fastcall GetCard(int Index);
	int __fastcall GetCardCount(void);
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo);
	
public:
	__property int CardCount = {read=GetCardCount, nodefault};
	__property TcxGridCard* Cards[int Index] = {read=GetCard};
public:
	/* TcxCustomGridTableViewData.Create */ inline __fastcall virtual TcxGridCardViewViewData(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewData(AGridView) { }
	/* TcxCustomGridTableViewData.Destroy */ inline __fastcall virtual ~TcxGridCardViewViewData(void) { }
	
};

#pragma pack(pop)

enum TcxGridCardRowInsertionPos : unsigned char { ripPrevLayer, ripNewLayer, ripSameLayer };

class DELPHICLASS TcxGridCardRowContainerZone;
class DELPHICLASS TcxGridCardViewRow;
class DELPHICLASS TcxGridCardViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowContainerZone : public Cxgridcustomtableview::TcxGridItemContainerZone
{
	typedef Cxgridcustomtableview::TcxGridItemContainerZone inherited;
	
private:
	TcxGridCardViewRow* __fastcall GetItem(void);
	TcxGridCardViewInfo* __fastcall GetRecordViewInfo(void);
	
public:
	Cxgridcustomtableview::TcxCustomGridRecord* GridRecord;
	TcxGridCardRowInsertionPos InsertionPos;
	__fastcall TcxGridCardRowContainerZone(Cxgridcustomtableview::TcxCustomGridRecord* AGridRecord, int AItemIndex, TcxGridCardRowInsertionPos AInsertionPos);
	virtual bool __fastcall IsEqual(Cxgridcustomtableview::TcxGridItemContainerZone* Value);
	__property TcxGridCardViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
	__property TcxGridCardViewRow* Item = {read=GetItem};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardRowContainerZone(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardRowMovingObjectClass;

class DELPHICLASS TcxGridCardRowMovingObject;
class DELPHICLASS TcxGridCardViewRowLayoutObject;
class DELPHICLASS TcxGridCardViewViewInfo;
class DELPHICLASS TcxGridCardViewVisibleRowLayoutObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowMovingObject : public Cxgridcustomtableview::TcxCustomGridTableItemMovingObject
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemMovingObject inherited;
	
private:
	TcxGridCardViewRow* FExpandingRow;
	Cxclasses::TcxTimer* FRowExpandingTimer;
	Cxgridcustomtableview::TcxCustomGridRecord* FSourceGridRecord;
	TcxGridCardRowContainerZone* __fastcall GetDestZone(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	TcxGridCardViewRowLayoutObject* __fastcall GetRowLayout(void);
	TcxGridCardViewRow* __fastcall GetSourceItem(void);
	HIDESBASE TcxGridCardViewViewInfo* __fastcall GetViewInfo(void);
	TcxGridCardViewVisibleRowLayoutObject* __fastcall GetVisibleRowLayout(void);
	HIDESBASE void __fastcall SetDestZone(TcxGridCardRowContainerZone* Value);
	void __fastcall SetSourceItem(TcxGridCardViewRow* Value);
	void __fastcall RowExpandingHandler(System::TObject* Sender);
	
protected:
	virtual bool __fastcall AreArrowsVertical(void);
	virtual void __fastcall CalculateDestParams(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, /* out */ int &AContainerKind, /* out */ Cxgridcustomtableview::TcxGridItemContainerZone* &AZone);
	virtual bool __fastcall CanRemove(void);
	virtual void __fastcall ChangeSourceItemPosition(void);
	virtual System::Types::TRect __fastcall GetArrowAreaBounds(Cxcontrols::TcxArrowPlace APlace);
	virtual System::Types::TRect __fastcall GetArrowsClientRect(void);
	virtual Cxgridcustomview::TcxCustomGridCellViewInfo* __fastcall GetSourceItemViewInfo(void);
	virtual bool __fastcall IsValidDestination(void);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	void __fastcall StartRowExpanding(TcxGridCardViewRow* ARow);
	void __fastcall StopRowExpanding(void);
	__property TcxGridCardViewRow* ExpandingRow = {read=FExpandingRow};
	__property TcxGridCardRowContainerZone* DestZone = {read=GetDestZone, write=SetDestZone};
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property TcxGridCardViewRowLayoutObject* RowLayout = {read=GetRowLayout};
	__property Cxgridcustomtableview::TcxCustomGridRecord* SourceGridRecord = {read=FSourceGridRecord, write=FSourceGridRecord};
	__property TcxGridCardViewRow* SourceItem = {read=GetSourceItem, write=SetSourceItem};
	__property TcxGridCardViewViewInfo* ViewInfo = {read=GetViewInfo};
	__property TcxGridCardViewVisibleRowLayoutObject* VisibleRowLayout = {read=GetVisibleRowLayout};
	
public:
	virtual void __fastcall Init(const System::Types::TPoint &P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
public:
	/* TcxCustomGridTableItemMovingObject.Create */ inline __fastcall virtual TcxGridCardRowMovingObject(Cxcontrols::TcxControl* AControl) : Cxgridcustomtableview::TcxCustomGridTableItemMovingObject(AControl) { }
	/* TcxCustomGridTableItemMovingObject.Destroy */ inline __fastcall virtual ~TcxGridCardRowMovingObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardSizingObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardSizingObject : public Cxgridcustomview::TcxCustomGridDragAndDropObject
{
	typedef Cxgridcustomview::TcxCustomGridDragAndDropObject inherited;
	
private:
	int FCardColumnIndex;
	int FCardOriginalWidth;
	int FDestPointX;
	System::Classes::TList* FSeparators;
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	System::Types::TRect __fastcall GetSeparator(int Index);
	int __fastcall GetSeparatorCount(void);
	HIDESBASE TcxGridCardViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetDestPointX(int Value);
	
protected:
	virtual void __fastcall DirtyChanged(void);
	virtual int __fastcall GetCurrentWidth(void);
	virtual int __fastcall GetDeltaWidth(void);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual bool __fastcall GetImmediateStart(void);
	virtual int __fastcall GetOriginalWidth(void);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	void __fastcall AddSeparator(const System::Types::TRect &R);
	void __fastcall CalculateSeparators(void);
	void __fastcall ClearSeparators(void);
	void __fastcall DrawSeparators(void);
	__property int SeparatorCount = {read=GetSeparatorCount, nodefault};
	__property System::Types::TRect Separators[int Index] = {read=GetSeparator};
	__property int CardColumnIndex = {read=FCardColumnIndex, nodefault};
	__property int CardOriginalWidth = {read=FCardOriginalWidth, write=FCardOriginalWidth, nodefault};
	__property int CurrentWidth = {read=GetCurrentWidth, nodefault};
	__property int DeltaWidth = {read=GetDeltaWidth, nodefault};
	__property int DestPointX = {read=FDestPointX, write=SetDestPointX, nodefault};
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property int OriginalWidth = {read=GetOriginalWidth, nodefault};
	__property TcxGridCardViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxGridCardSizingObject(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TcxGridCardSizingObject(void);
	virtual void __fastcall Init(const System::Types::TPoint &P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowsListBox;
class PASCALIMPLEMENTATION TcxGridCardRowsListBox : public Cxgridcustomtableview::TcxCustomGridTableItemsListBox
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemsListBox inherited;
	
private:
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	
protected:
	virtual int __fastcall CalculateItemHeight(void);
	virtual void __fastcall DoRefreshItems(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetDragAndDropParams(void);
	__property TcxGridCardView* GridView = {read=GetGridView};
	
public:
	virtual void __fastcall PaintItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int AIndex, bool AFocused);
public:
	/* TcxCustomGridItemsListBox.Create */ inline __fastcall virtual TcxGridCardRowsListBox(System::Classes::TComponent* AOwner) : Cxgridcustomtableview::TcxCustomGridTableItemsListBox(AOwner) { }
	
public:
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TcxGridCardRowsListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridCardRowsListBox(HWND ParentWindow) : Cxgridcustomtableview::TcxCustomGridTableItemsListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxGridCardViewCustomizationForm;
class PASCALIMPLEMENTATION TcxGridCardViewCustomizationForm : public Cxgridcustomtableview::TcxCustomGridTableCustomizationForm
{
	typedef Cxgridcustomtableview::TcxCustomGridTableCustomizationForm inherited;
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridTableItemsListBoxClass __fastcall GetItemsListBoxClass(void);
	virtual System::UnicodeString __fastcall GetItemsPageCaption(void);
public:
	/* TcxCustomGridCustomizationForm.Create */ inline __fastcall virtual TcxGridCardViewCustomizationForm(Cxgridcustomview::TcxCustomGridController* AController) : Cxgridcustomtableview::TcxCustomGridTableCustomizationForm(AController) { }
	/* TcxCustomGridCustomizationForm.Destroy */ inline __fastcall virtual ~TcxGridCardViewCustomizationForm(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridCardViewCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomtableview::TcxCustomGridTableCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridCardViewCustomizationForm(HWND ParentWindow) : Cxgridcustomtableview::TcxCustomGridTableCustomizationForm(ParentWindow) { }
	
};


class DELPHICLASS TcxGridCardViewController;
class PASCALIMPLEMENTATION TcxGridCardViewController : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewController
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewController inherited;
	
private:
	TcxGridCardViewCustomizationForm* __fastcall GetCustomizationForm(void);
	TcxGridCard* __fastcall GetFocusedCard(void);
	TcxGridCardViewInfo* __fastcall GetFocusedCardViewInfo(void);
	TcxGridCardViewRow* __fastcall GetFocusedRow(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	TcxGridCardViewInfo* __fastcall GetScrollCardViewInfo(void);
	int __fastcall GetTopCardIndex(void);
	HIDESBASE TcxGridCardViewViewData* __fastcall GetViewData(void);
	HIDESBASE TcxGridCardViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetFocusedCard(TcxGridCard* Value);
	void __fastcall SetFocusedRow(TcxGridCardViewRow* Value);
	void __fastcall SetScrollCardViewInfo(TcxGridCardViewInfo* Value);
	void __fastcall SetTopCardIndex(int Value);
	
protected:
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutViewControllerHelperClass __fastcall GetHelperClass(void);
	virtual bool __fastcall CanFocusNextItem(int AFocusedItemIndex, int ANextItemIndex, bool AGoForward, bool AGoOnCycle, bool AGoToNextRecordOnCycle);
	TcxGridCardViewRow* __fastcall FindNextRow(TcxGridCard* ACard, System::Classes::TList* ARows, TcxGridCardViewRow* ARow, bool AGoForward, bool AGoOnCycle, /* out */ bool &ACycleChanged);
	virtual bool __fastcall GetDesignHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall IsKeyForMultiSelect(System::Word AKey, System::Classes::TShiftState AShift, bool AFocusedRecordChanged);
	virtual void __fastcall RowExpandedChanged(TcxGridCardViewRow* ARow);
	virtual void __fastcall RowExpandedChanging(TcxGridCardViewRow* ARow, bool AValue);
	virtual void __fastcall ScrollData(Cxclasses::TcxDirection ADirection);
	virtual bool __fastcall CanScrollData(Cxclasses::TcxDirection ADirection);
	virtual int __fastcall GetScrollDataTimeInterval(Cxclasses::TcxDirection ADirection);
	virtual Cxgridcustomview::TcxCustomGridCustomizationFormClass __fastcall GetCustomizationFormClass(void);
	virtual TcxGridCardRowMovingObjectClass __fastcall GetRowDragAndDropObjectClass(void);
	__property TcxGridCardViewInfo* FocusedCardViewInfo = {read=GetFocusedCardViewInfo};
	__property TcxGridCardViewInfo* ScrollCardViewInfo = {read=GetScrollCardViewInfo, write=SetScrollCardViewInfo};
	__property TcxGridCardViewViewData* ViewData = {read=GetViewData};
	__property TcxGridCardViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall CheckScrolling(const System::Types::TPoint &P);
	virtual void __fastcall MakeItemVisible(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual bool __fastcall CanScrollFocusedCard(bool ADown);
	virtual bool __fastcall ScrollFocusedCard(bool ADown);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall FocusNextItemHorizontally(bool AGoForward, bool AGoOnCycle);
	virtual bool __fastcall FocusNextItemVertically(bool AGoForward, bool AGoOnCycle);
	__property TcxGridCardViewCustomizationForm* CustomizationForm = {read=GetCustomizationForm};
	__property TcxGridCard* FocusedCard = {read=GetFocusedCard, write=SetFocusedCard};
	__property TcxGridCardViewRow* FocusedItem = {read=GetFocusedRow, write=SetFocusedRow};
	__property TcxGridCardViewRow* FocusedRow = {read=GetFocusedRow, write=SetFocusedRow};
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property int TopCardIndex = {read=GetTopCardIndex, write=SetTopCardIndex, nodefault};
public:
	/* TcxGridCustomLayoutViewController.Create */ inline __fastcall virtual TcxGridCardViewController(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewController(AGridView) { }
	/* TcxGridCustomLayoutViewController.Destroy */ inline __fastcall virtual ~TcxGridCardViewController(void) { }
	
};


enum TcxGridCardViewRowLayout : unsigned char { rlHorizontal, rlVertical };

enum TcxGridCardViewRowLayerPosition : unsigned char { rlpBeforeRow, rlpAfterRow, rlpBeforeLayer, rlpAfterLayer };

struct DECLSPEC_DRECORD TcxGridCardRowPosition
{
public:
	int LayerIndex;
	int IndexInLayer;
};


struct DECLSPEC_DRECORD TcxGridCardRowCoordinates
{
public:
	int ColIndex;
	int RowIndex;
};


typedef System::DynamicArray<TcxGridCardRowCoordinates> TcxGridCardRowCoordinatesArray;

class DELPHICLASS TcxCustomGridCardRowLayoutObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridCardRowLayoutObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FLayerRowCounts;
	int __fastcall GetLayerCount(void);
	TcxGridCardViewRow* __fastcall GetLayerFirstRow(int ALayerIndex);
	int __fastcall GetLayerFirstRowIndex(int ALayerIndex);
	TcxGridCardViewRow* __fastcall GetLayerRow(int ALayerIndex, int AIndex);
	int __fastcall GetLayerRowCount(int ALayerIndex);
	void __fastcall SetLayerRowCount(int ALayerIndex, int Value);
	
protected:
	virtual TcxGridCardViewRowLayout __fastcall GetLayout(void) = 0 ;
	virtual TcxGridCardViewRow* __fastcall GetRow(int AIndex) = 0 ;
	virtual int __fastcall GetRowCount(void) = 0 ;
	virtual int __fastcall GetRowIndex(TcxGridCardViewRow* ARow) = 0 ;
	TcxGridCardRowCoordinates __fastcall GetCoordinates(const TcxGridCardRowPosition &APosition)/* overload */;
	TcxGridCardRowPosition __fastcall GetPosition(const TcxGridCardRowCoordinates &ACoordinates)/* overload */;
	int __fastcall GetLayerIndex(int ARowIndex)/* overload */;
	TcxGridCardViewRowLayerPosition __fastcall GetLayerPosition(Cxclasses::TcxPosition APosition);
	int __fastcall GetLength(TcxGridCardViewRow* ARow);
	int __fastcall GetOffsetInLayer(int ALayerIndex, int AIndexInLayer)/* overload */;
	TcxGridCardRowPosition __fastcall GetPosition(int ARowIndex)/* overload */;
	__property System::Classes::TList* LayerRowCounts = {read=FLayerRowCounts};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxGridCardViewRow* Rows[int AIndex] = {read=GetRow};
	
public:
	__fastcall TcxCustomGridCardRowLayoutObject(void);
	__fastcall virtual ~TcxCustomGridCardRowLayoutObject(void);
	TcxGridCardRowCoordinates __fastcall GetCoordinates(TcxGridCardViewRow* ARow)/* overload */;
	int __fastcall GetIndexInLayer(TcxGridCardViewRow* ARow);
	int __fastcall GetLayerIndex(TcxGridCardViewRow* ARow)/* overload */;
	int __fastcall GetOffsetInLayer(TcxGridCardViewRow* ARow)/* overload */;
	TcxGridCardRowPosition __fastcall GetPosition(TcxGridCardViewRow* ARow)/* overload */;
	TcxGridCardViewRow* __fastcall GetRowAtOffset(int ALayerIndex, int AOffset);
	bool __fastcall IsFirstInLayer(TcxGridCardViewRow* ARow);
	bool __fastcall IsLastInLayer(TcxGridCardViewRow* ARow);
	bool __fastcall IsWholeLine(TcxGridCardViewRow* ARow);
	__property int LayerCount = {read=GetLayerCount, nodefault};
	__property TcxGridCardViewRow* LayerFirstRow[int ALayerIndex] = {read=GetLayerFirstRow};
	__property int LayerFirstRowIndex[int ALayerIndex] = {read=GetLayerFirstRowIndex};
	__property int LayerRowCount[int ALayerIndex] = {read=GetLayerRowCount, write=SetLayerRowCount};
	__property TcxGridCardViewRow* LayerRows[int ALayerIndex][int AIndex] = {read=GetLayerRow};
	__property TcxGridCardViewRowLayout Layout = {read=GetLayout, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowLayoutObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowLayoutObject : public TcxCustomGridCardRowLayoutObject
{
	typedef TcxCustomGridCardRowLayoutObject inherited;
	
private:
	TcxGridCardViewRowLayout FLayout;
	System::Classes::TList* FRows;
	
protected:
	virtual TcxGridCardViewRowLayout __fastcall GetLayout(void);
	virtual TcxGridCardViewRow* __fastcall GetRow(int AIndex);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall GetRowIndex(TcxGridCardViewRow* ARow);
	__property System::Classes::TList* RowsList = {read=FRows};
	
public:
	__fastcall TcxGridCardRowLayoutObject(void);
	__fastcall virtual ~TcxGridCardRowLayoutObject(void);
	void __fastcall Fill(System::Classes::TList* ARows);
	__property TcxGridCardViewRowLayout Layout = {read=GetLayout, write=FLayout, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardVisibleRowLayoutObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardVisibleRowLayoutObject : public TcxGridCardRowLayoutObject
{
	typedef TcxGridCardRowLayoutObject inherited;
	
private:
	TcxGridCard* FCard;
	
public:
	__fastcall TcxGridCardVisibleRowLayoutObject(TcxGridCard* ACard);
	void __fastcall GetInsertionParams(TcxGridCardViewRow* ARow, Cxclasses::TcxPosition APosition, /* out */ int &AInsertionIndex, /* out */ TcxGridCardRowInsertionPos &AInsertionPos);
	void __fastcall GetLayerRows(TcxGridCardViewRow* ARowInLayer, System::Classes::TList* ARows);
	void __fastcall GetRowsAtOffset(TcxGridCardViewRow* ARowAtOffset, System::Classes::TList* ARows);
	__property TcxGridCard* Card = {read=FCard};
public:
	/* TcxGridCardRowLayoutObject.Destroy */ inline __fastcall virtual ~TcxGridCardVisibleRowLayoutObject(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGridCardViewRowLayoutObject : public TcxCustomGridCardRowLayoutObject
{
	typedef TcxCustomGridCardRowLayoutObject inherited;
	
private:
	TcxGridCardView* FGridView;
	System::Classes::TNotifyEvent FOnLayerIndexChanged;
	bool __fastcall GetBeginsLayer(TcxGridCardViewRow* ARow);
	void __fastcall SetBeginsLayer(TcxGridCardViewRow* ARow, bool Value);
	
protected:
	virtual TcxGridCardViewRowLayout __fastcall GetLayout(void);
	virtual TcxGridCardViewRow* __fastcall GetRow(int AIndex);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall GetRowIndex(TcxGridCardViewRow* ARow);
	void __fastcall AddLayer(void);
	void __fastcall InsertLayer(int AIndex);
	void __fastcall RemoveLayer(int AIndex);
	void __fastcall AddRowToLayer(int ALayerIndex);
	void __fastcall RemoveRowFromLayer(int ALayerIndex);
	void __fastcall AddRow(TcxGridCardViewRow* ARow);
	void __fastcall RemoveRow(int ARowIndex);
	void __fastcall MoveRow(TcxGridCardViewRow* ARow, int AOldIndex);
	void __fastcall MoveRows(System::Classes::TList* ARows, int AIndex)/* overload */;
	void __fastcall MoveRows(System::Classes::TList* ARows, int AIndex, TcxGridCardRowLayoutObject* ARowLayout)/* overload */;
	void __fastcall LayerIndexChanged(void);
	__property System::Classes::TNotifyEvent OnLayerIndexChanged = {read=FOnLayerIndexChanged, write=FOnLayerIndexChanged};
	
public:
	__fastcall TcxGridCardViewRowLayoutObject(TcxGridCardView* AGridView);
	void __fastcall BreakLayer(int ALayerIndex, int AIndexInLayer);
	bool __fastcall IsSimpleLayout(void);
	void __fastcall MergeLayer(int ALayerIndex);
	void __fastcall SetCoordinates(TcxGridCardViewRow* ARow, const TcxGridCardRowCoordinates &ACoordinates);
	void __fastcall SetIndexInLayer(TcxGridCardViewRow* ARow, int AValue, bool AMoveSubItems = false);
	void __fastcall SetLayerIndex(TcxGridCardViewRow* ARow, int AValue, bool ANewLayer = false, bool AMoveSubItems = false);
	void __fastcall SetPosition(TcxGridCardViewRow* ARow, const TcxGridCardRowPosition &APosition);
	__property bool BeginsLayer[TcxGridCardViewRow* ARow] = {read=GetBeginsLayer, write=SetBeginsLayer};
	__property TcxGridCardView* GridView = {read=FGridView};
public:
	/* TcxCustomGridCardRowLayoutObject.Destroy */ inline __fastcall virtual ~TcxGridCardViewRowLayoutObject(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewVisibleRowLayoutObject : public TcxGridCardRowLayoutObject
{
	typedef TcxGridCardRowLayoutObject inherited;
	
private:
	TcxGridCardView* FGridView;
	
protected:
	virtual TcxGridCardViewRowLayout __fastcall GetLayout(void);
	
public:
	__fastcall TcxGridCardViewVisibleRowLayoutObject(TcxGridCardView* AGridView);
	TcxGridCardViewRow* __fastcall GetLastVisibleSubItem(TcxGridCardViewRow* ARow);
	HIDESBASE int __fastcall GetLayerCount(TcxGridCardViewRow* ARow);
	bool __fastcall IsWholeLayer(TcxGridCardViewRow* ARow);
	__property TcxGridCardView* GridView = {read=FGridView};
public:
	/* TcxGridCardRowLayoutObject.Destroy */ inline __fastcall virtual ~TcxGridCardViewVisibleRowLayoutObject(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardViewRowLayoutControllerClass;

class DELPHICLASS TcxGridCardViewRowLayoutController;
class DELPHICLASS TcxGridCardRowLayout;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewRowLayoutController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxGridCardView* FGridView;
	TcxGridCardViewRowLayoutObject* FLayoutObject;
	TcxGridCardViewVisibleRowLayoutObject* FVisibleLayoutObject;
	bool __fastcall GetBeginsLayer(TcxGridCardViewRow* ARow);
	TcxGridCardViewRowLayout __fastcall GetLayout(void);
	void __fastcall SetBeginsLayer(TcxGridCardViewRow* ARow, bool Value);
	void __fastcall LayerIndexChanged(System::TObject* Sender);
	
protected:
	void __fastcall RefreshVisibleLayoutObject(void);
	void __fastcall RowIndexChanged(TcxGridCardViewRow* ARow, int AOldIndex);
	void __fastcall VisibleRowsListChanged(void);
	TcxGridCardRowLayout* __fastcall CreateCardRowLayout(TcxGridCardViewInfo* ACardViewInfo);
	virtual TcxGridCardRowLayoutClass __fastcall GetCardRowLayoutClass(void);
	
public:
	__fastcall virtual TcxGridCardViewRowLayoutController(TcxGridCardView* AGridView);
	__fastcall virtual ~TcxGridCardViewRowLayoutController(void);
	bool __fastcall IsHorizontalLayout(void);
	bool __fastcall IsSimpleLayout(void);
	bool __fastcall IsWholeLine(TcxGridCardViewRow* ARow);
	TcxGridCardRowCoordinates __fastcall GetCoordinates(TcxGridCardViewRow* ARow);
	void __fastcall SetCoordinates(TcxGridCardViewRow* ARow, int AColIndex, int ARowIndex)/* overload */;
	void __fastcall SetCoordinates(TcxGridCardViewRow* ARow, const TcxGridCardRowCoordinates &ACoordinates)/* overload */;
	TcxGridCardRowCoordinates __fastcall GetVisibleCoordinates(TcxGridCardViewRow* ARow);
	TcxGridCardRowPosition __fastcall GetPosition(TcxGridCardViewRow* ARow);
	void __fastcall SetPosition(TcxGridCardViewRow* ARow, int ALayerIndex, int AIndexInLayer);
	TcxGridCardRowPosition __fastcall GetVisiblePosition(TcxGridCardViewRow* ARow);
	TcxGridCardViewRow* __fastcall FindNextRow(TcxGridCard* ACard, TcxGridCardViewRow* ARow, bool ASameLayer, bool AGoForward, bool AGoOnCycle, /* out */ bool &ACycleChanged);
	TcxGridCardViewRow* __fastcall FindNextRowHorizontally(TcxGridCard* ACard, TcxGridCardViewRow* ARow, bool AGoForward, bool AGoOnCycle, /* out */ bool &ACycleChanged);
	TcxGridCardViewRow* __fastcall FindNextRowVertically(TcxGridCard* ACard, TcxGridCardViewRow* ARow, bool AGoForward, bool AGoOnCycle, /* out */ bool &ACycleChanged);
	__property bool BeginsLayer[TcxGridCardViewRow* ARow] = {read=GetBeginsLayer, write=SetBeginsLayer};
	__property TcxGridCardView* GridView = {read=FGridView};
	__property TcxGridCardViewRowLayout Layout = {read=GetLayout, nodefault};
	__property TcxGridCardViewRowLayoutObject* LayoutObject = {read=FLayoutObject};
	__property TcxGridCardViewVisibleRowLayoutObject* VisibleLayoutObject = {read=FVisibleLayoutObject};
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowFilterButtonPainter;
class DELPHICLASS TcxGridCardRowFilterButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowFilterButtonPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridCardRowFilterButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridCardRowFilterButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridCardRowFilterButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardRowFilterButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowCaptionPainter;
class DELPHICLASS TcxGridCardRowCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowCaptionPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridCardRowCaptionViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	__property TcxGridCardRowCaptionViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridCardRowCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardRowCaptionPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardRowPainterClass;

class DELPHICLASS TcxGridCardRowPainter;
class DELPHICLASS TcxGridCardRowViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridCardRowViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawExpandButton(void);
	virtual void __fastcall DrawFocusRect(void);
	virtual void __fastcall DrawIndent(void);
	virtual void __fastcall Paint(void);
	__property TcxGridCardRowViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridCardRowPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardRowPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardScrollButtonPainter;
class DELPHICLASS TcxCustomGridCardScrollButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardScrollButtonPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxCustomGridCardScrollButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxCustomGridCardScrollButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridCardScrollButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardScrollButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardExpandButtonPainter;
class DELPHICLASS TcxGridCardExpandButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardExpandButtonPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridCardExpandButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridCardExpandButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridCardExpandButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardExpandButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardPainter : public Cxgridcustomtableview::TcxCustomGridRecordPainter
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordPainter inherited;
	
private:
	Cxgraphics::TcxRegion* FClipRegion;
	HIDESBASE TcxGridCardViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeforePaint(void);
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual void __fastcall DrawCardBorder(void);
	virtual void __fastcall DrawExpandButton(void);
	virtual bool __fastcall DrawExpandButtonBeforePaint(void);
	virtual void __fastcall DrawLayerSeparators(void);
	virtual void __fastcall DrawRows(void);
	virtual void __fastcall DrawScrollButtons(void);
	virtual void __fastcall Paint(void);
	__property TcxGridCardViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridCardPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomtableview::TcxCustomGridRecordPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewPainter : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewPainter
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewPainter inherited;
	
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxGridCardViewPainter(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewPainter(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridCardViewPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewColumn;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewColumn : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewBand
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewBand inherited;
	
public:
	TcxGridCardViewInfo* operator[](int Index) { return Rows[Index]; }
	
private:
	TcxGridCardViewInfo* __fastcall GetLastRow(void);
	TcxGridCardViewInfo* __fastcall GetRow(int Index);
	void __fastcall SetRow(int Index, TcxGridCardViewInfo* Value);
	
public:
	TcxGridCardViewInfo* __fastcall GetNearestRow(int APos);
	__property TcxGridCardViewInfo* LastRow = {read=GetLastRow};
	__property TcxGridCardViewInfo* Rows[int Index] = {read=GetRow, write=SetRow/*, default*/};
public:
	/* TcxGridCustomLayoutViewBand.Create */ inline __fastcall TcxGridCardViewColumn(int AIndex) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewBand(AIndex) { }
	/* TcxGridCustomLayoutViewBand.Destroy */ inline __fastcall virtual ~TcxGridCardViewColumn(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewColumns;
class DELPHICLASS TcxGridCardsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewColumns : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewBands
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewBands inherited;
	
public:
	TcxGridCardViewColumn* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridCardsViewInfo* __fastcall GetCardsViewInfo(void);
	HIDESBASE TcxGridCardViewColumn* __fastcall GetItem(int Index);
	TcxGridCardViewColumn* __fastcall GetLast(void);
	
protected:
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutViewBandClass __fastcall GetBandClass(void);
	__property TcxGridCardsViewInfo* CardsViewInfo = {read=GetCardsViewInfo};
	
public:
	__property TcxGridCardViewColumn* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxGridCardViewColumn* Last = {read=GetLast};
public:
	/* TcxGridCustomLayoutViewBands.Create */ inline __fastcall TcxGridCardViewColumns(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewBands(ARecordsViewInfo) { }
	/* TcxGridCustomLayoutViewBands.Destroy */ inline __fastcall virtual ~TcxGridCardViewColumns(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowCellViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowCellViewInfo : public Cxgridcustomtableview::TcxGridTableDataCellViewInfo
{
	typedef Cxgridcustomtableview::TcxGridTableDataCellViewInfo inherited;
	
private:
	TcxGridCardRowViewInfo* FRowViewInfo;
	TcxGridCardViewInfo* __fastcall GetCardViewInfo(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	HIDESBASE TcxGridCard* __fastcall GetGridRecord(void);
	TcxGridCardViewRow* __fastcall GetRow(void);
	
protected:
	virtual System::Types::TRect __fastcall GetAreaBounds(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual bool __fastcall GetMultiLinePainting(void);
	virtual bool __fastcall GetTransparent(void);
	virtual bool __fastcall HasFocusRect(void);
	
public:
	__fastcall virtual TcxGridCardRowCellViewInfo(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxGridCardViewInfo* CardViewInfo = {read=GetCardViewInfo};
	__property TcxGridCard* GridRecord = {read=GetGridRecord};
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property TcxGridCardViewRow* Row = {read=GetRow};
	__property TcxGridCardRowViewInfo* RowViewInfo = {read=FRowViewInfo};
public:
	/* TcxGridTableDataCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardRowCellViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardRowFilterButtonViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowFilterButtonViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewItemFilterButtonViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewItemFilterButtonViewInfo inherited;
	
private:
	TcxGridCardRowCaptionViewInfo* FRowCaptionViewInfo;
	TcxGridCardViewRow* __fastcall GetRow(void);
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridTableItem* __fastcall GetItem(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual System::Types::TRect __fastcall GetDropDownWindowOwnerBounds(void);
	
public:
	__fastcall virtual TcxGridCardRowFilterButtonViewInfo(TcxGridCardRowCaptionViewInfo* ARowCaptionViewInfo);
	__property TcxGridCardViewRow* Row = {read=GetRow};
	__property TcxGridCardRowCaptionViewInfo* RowCaptionViewInfo = {read=FRowCaptionViewInfo};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardRowFilterButtonViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardRowCaptionViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowCaptionViewInfo : public TcxGridCardRowCellViewInfo
{
	typedef TcxGridCardRowCellViewInfo inherited;
	
private:
	bool FCalculatingRealWidth;
	TcxGridCardRowFilterButtonViewInfo* FFilterButtonViewInfo;
	int __fastcall GetRealWidth(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	__classmethod virtual int __fastcall CalculateSimpleHeight(TcxGridCardViewRow* ARow, Cxgraphics::TcxCanvas* ACanvas, Vcl::Graphics::TFont* AFont);
	virtual int __fastcall CalculateRealWidth(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanFilter(void);
	virtual bool __fastcall CanShowAutoHint(void);
	virtual bool __fastcall CanShowCustomHint(void);
	virtual bool __fastcall CanShowEdit(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual System::Types::TRect __fastcall GetFilterButtonBounds(void);
	virtual TcxGridCardRowFilterButtonViewInfoClass __fastcall GetFilterButtonViewInfoClass(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetShowEndEllipsis(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall UseStandardNeedShowHint(void);
	__property bool CalculatingRealWidth = {read=FCalculatingRealWidth, nodefault};
	__property System::Types::TRect FilterButtonBounds = {read=GetFilterButtonBounds};
	
public:
	__fastcall virtual TcxGridCardRowCaptionViewInfo(TcxGridCardRowViewInfo* ARowViewInfo);
	__fastcall virtual ~TcxGridCardRowCaptionViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property TcxGridCardRowFilterButtonViewInfo* FilterButtonViewInfo = {read=FFilterButtonViewInfo};
	__property int RealWidth = {read=GetRealWidth, nodefault};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardRowDataViewInfoClass;

class DELPHICLASS TcxGridCardRowDataViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowDataViewInfo : public TcxGridCardRowCellViewInfo
{
	typedef TcxGridCardRowCellViewInfo inherited;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	__classmethod virtual int __fastcall CalculateSimpleHeight(TcxGridCardViewRow* ARow, Cxgraphics::TcxCanvas* ACanvas, Vcl::Graphics::TFont* AFont);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
public:
	/* TcxGridCardRowCellViewInfo.Create */ inline __fastcall virtual TcxGridCardRowDataViewInfo(TcxGridCardRowViewInfo* ARowViewInfo) : TcxGridCardRowCellViewInfo(ARowViewInfo) { }
	
public:
	/* TcxGridTableDataCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardRowDataViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardRowViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridCardRowCaptionViewInfo* FCaptionViewInfo;
	TcxGridCardViewInfo* FCardViewInfo;
	TcxGridCardRowDataViewInfo* FDataViewInfo;
	int FHeight;
	int FIndex;
	bool FPartVisible;
	int __fastcall GetExpandButtonAreaSizeValue(void);
	int __fastcall GetExpandButtonSizeValue(void);
	bool __fastcall GetExpanded(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	TcxGridCard* __fastcall GetGridRecord(void);
	TcxGridCardViewViewInfo* __fastcall GetGridViewInfo(void);
	TcxGridCardViewRow* __fastcall GetRow(void);
	void __fastcall SetExpanded(bool Value);
	bool __fastcall CalculatePartVisible(void);
	bool __fastcall CalculateVisible(void);
	void __fastcall CreateViewInfos(void);
	void __fastcall DestroyViewInfos(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual int __fastcall CalculateHeaderWidth(void);
	virtual int __fastcall CalculateHeight(void);
	__classmethod virtual int __fastcall CalculateSimpleHeight(TcxGridCardViewRow* ARow, Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall CalculateWidth(void);
	__classmethod virtual void __fastcall CheckHeight(TcxGridCardViewInfoClass ACardViewInfoClass, TcxGridCardViewRow* ARow, TcxGridCardRowViewInfo* ARowViewInfo, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter, int &AHeight);
	__classmethod virtual TcxGridCardRowCaptionViewInfoClass __fastcall GetCaptionViewInfoClass();
	virtual int __fastcall GetCaptionWidth(void);
	__classmethod virtual TcxGridCardRowDataViewInfoClass __fastcall GetDataViewInfoClass();
	virtual int __fastcall GetDataWidth(void);
	virtual System::Types::TRect __fastcall GetDesignSelectionBounds(void);
	virtual System::Types::TRect __fastcall GetExpandButtonAreaBounds(void);
	__classmethod virtual int __fastcall GetExpandButtonAreaSize(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	virtual System::Types::TRect __fastcall GetExpandButtonBounds(void);
	__classmethod virtual int __fastcall GetExpandButtonSize(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	virtual int __fastcall GetHeaderWidth(void);
	virtual int __fastcall GetHeight(void);
	virtual bool __fastcall GetHidden(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual int __fastcall GetIndent(void);
	virtual System::Types::TRect __fastcall GetIndentBounds(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetIndentViewParams(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual bool __fastcall GetIsVisibleForPainting(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	__classmethod virtual Cxgraphics::TcxViewParams __fastcall GetSimpleViewParams(TcxGridCardViewRow* ARow, bool AIsCaption);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall GetCaptionViewParams(Cxgraphics::TcxViewParams &AParams, bool AIgnoreSelection) = 0 ;
	virtual void __fastcall GetDataViewParams(Cxgraphics::TcxViewParams &AParams) = 0 ;
	__property int CaptionWidth = {read=GetCaptionWidth, nodefault};
	__property int DataWidth = {read=GetDataWidth, nodefault};
	__property int ExpandButtonAreaSize = {read=GetExpandButtonAreaSizeValue, nodefault};
	__property int ExpandButtonSize = {read=GetExpandButtonSizeValue, nodefault};
	__property int Indent = {read=GetIndent, nodefault};
	
public:
	__fastcall virtual TcxGridCardRowViewInfo(TcxGridCardViewInfo* ACardViewInfo, int AIndex);
	__fastcall virtual ~TcxGridCardRowViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds)/* overload */;
	bool __fastcall CalculateVisibleCounts(int &AVisibleRowCount, int &APartVisibleRowCount);
	void __fastcall CalculateVisibles(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual bool __fastcall HasExpandButton(void);
	virtual bool __fastcall HasIndent(void);
	virtual bool __fastcall HasLimitedHeaderSpace(void);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxGridCardRowCaptionViewInfo* CaptionViewInfo = {read=FCaptionViewInfo};
	__property TcxGridCardViewInfo* CardViewInfo = {read=FCardViewInfo};
	__property TcxGridCardRowDataViewInfo* DataViewInfo = {read=FDataViewInfo};
	__property System::Types::TRect ExpandButtonAreaBounds = {read=GetExpandButtonAreaBounds};
	__property System::Types::TRect ExpandButtonBounds = {read=GetExpandButtonBounds};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property TcxGridCard* GridRecord = {read=GetGridRecord};
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property TcxGridCardViewViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property int HeaderWidth = {read=GetHeaderWidth, nodefault};
	__property int Height = {read=GetHeight, write=FHeight, nodefault};
	__property bool Hidden = {read=GetHidden, nodefault};
	__property System::Types::TRect IndentBounds = {read=GetIndentBounds};
	__property int Index = {read=FIndex, nodefault};
	__property bool PartVisible = {read=FPartVisible, nodefault};
	__property TcxGridCardViewRow* Row = {read=GetRow};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ALeftBound, ATopBound, AWidth, AHeight); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardDataRowDataViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardDataRowDataViewInfo : public TcxGridCardRowDataViewInfo
{
	typedef TcxGridCardRowDataViewInfo inherited;
	
protected:
	virtual bool __fastcall CalculateSelected(void);
public:
	/* TcxGridCardRowCellViewInfo.Create */ inline __fastcall virtual TcxGridCardDataRowDataViewInfo(TcxGridCardRowViewInfo* ARowViewInfo) : TcxGridCardRowDataViewInfo(ARowViewInfo) { }
	
public:
	/* TcxGridTableDataCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardDataRowDataViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardDataRowViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardDataRowViewInfo : public TcxGridCardRowViewInfo
{
	typedef TcxGridCardRowViewInfo inherited;
	
protected:
	virtual void __fastcall GetCaptionViewParams(Cxgraphics::TcxViewParams &AParams, bool AIgnoreSelection);
	__classmethod virtual TcxGridCardRowDataViewInfoClass __fastcall GetDataViewInfoClass();
	virtual void __fastcall GetDataViewParams(Cxgraphics::TcxViewParams &AParams);
	__classmethod virtual Cxgraphics::TcxViewParams __fastcall GetSimpleViewParams(TcxGridCardViewRow* ARow, bool AIsCaption);
public:
	/* TcxGridCardRowViewInfo.Create */ inline __fastcall virtual TcxGridCardDataRowViewInfo(TcxGridCardViewInfo* ACardViewInfo, int AIndex) : TcxGridCardRowViewInfo(ACardViewInfo, AIndex) { }
	/* TcxGridCardRowViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardDataRowViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardCaptionRowCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardCaptionRowCaptionViewInfo : public TcxGridCardRowCaptionViewInfo
{
	typedef TcxGridCardRowCaptionViewInfo inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
public:
	/* TcxGridCardRowCaptionViewInfo.Create */ inline __fastcall virtual TcxGridCardCaptionRowCaptionViewInfo(TcxGridCardRowViewInfo* ARowViewInfo) : TcxGridCardRowCaptionViewInfo(ARowViewInfo) { }
	/* TcxGridCardRowCaptionViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardCaptionRowCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardCaptionRowDataViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardCaptionRowDataViewInfo : public TcxGridCardRowDataViewInfo
{
	typedef TcxGridCardRowDataViewInfo inherited;
	
protected:
	virtual void __fastcall GetEditViewDataContentOffsets(System::Types::TRect &R);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
public:
	/* TcxGridCardRowCellViewInfo.Create */ inline __fastcall virtual TcxGridCardCaptionRowDataViewInfo(TcxGridCardRowViewInfo* ARowViewInfo) : TcxGridCardRowDataViewInfo(ARowViewInfo) { }
	
public:
	/* TcxGridTableDataCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardCaptionRowDataViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardCaptionRowViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardCaptionRowViewInfo : public TcxGridCardRowViewInfo
{
	typedef TcxGridCardRowViewInfo inherited;
	
protected:
	__classmethod virtual TcxGridCardRowCaptionViewInfoClass __fastcall GetCaptionViewInfoClass();
	virtual void __fastcall GetCaptionViewParams(Cxgraphics::TcxViewParams &AParams, bool AIgnoreSelection);
	__classmethod virtual TcxGridCardRowDataViewInfoClass __fastcall GetDataViewInfoClass();
	virtual void __fastcall GetDataViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
public:
	/* TcxGridCardRowViewInfo.Create */ inline __fastcall virtual TcxGridCardCaptionRowViewInfo(TcxGridCardViewInfo* ACardViewInfo, int AIndex) : TcxGridCardRowViewInfo(ACardViewInfo, AIndex) { }
	/* TcxGridCardRowViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardCaptionRowViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardCategoryRowViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardCategoryRowViewInfo : public TcxGridCardCaptionRowViewInfo
{
	typedef TcxGridCardCaptionRowViewInfo inherited;
	
protected:
	__classmethod virtual void __fastcall CheckHeight(TcxGridCardViewInfoClass ACardViewInfoClass, TcxGridCardViewRow* ARow, TcxGridCardRowViewInfo* ARowViewInfo, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter, int &AHeight);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual void __fastcall GetDataViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual System::Uitypes::TColor __fastcall GetSeparatorColor(void);
	bool __fastcall HasSeparator(void)/* overload */;
	__classmethod bool __fastcall HasSeparator(TcxGridCardViewInfoClass ACardViewInfoClass, TcxGridCardViewRow* ARow)/* overload */;
	__property System::Uitypes::TColor SeparatorColor = {read=GetSeparatorColor, nodefault};
	
public:
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
public:
	/* TcxGridCardRowViewInfo.Create */ inline __fastcall virtual TcxGridCardCategoryRowViewInfo(TcxGridCardViewInfo* ACardViewInfo, int AIndex) : TcxGridCardCaptionRowViewInfo(ACardViewInfo, AIndex) { }
	/* TcxGridCardRowViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardCategoryRowViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridCardScrollButtonViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridCardViewInfo* FCardViewInfo;
	Cxclasses::TcxTimer* FScrollTimer;
	void __fastcall ScrollTimerHandler(System::TObject* Sender);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual bool __fastcall GetIsDownButton(void) = 0 ;
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall Scroll(void) = 0 ;
	virtual void __fastcall StateChanged(Cxgridcommon::TcxGridCellState APrevState);
	void __fastcall StartAutoScrolling(void);
	void __fastcall StopAutoScrolling(void);
	__property Cxclasses::TcxTimer* ScrollTimer = {read=FScrollTimer};
	
public:
	__fastcall virtual TcxCustomGridCardScrollButtonViewInfo(TcxGridCardViewInfo* ACardViewInfo);
	__property bool IsDownButton = {read=GetIsDownButton, nodefault};
	__property TcxGridCardViewInfo* CardViewInfo = {read=FCardViewInfo};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxCustomGridCardScrollButtonViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardScrollButtonDownViewInfoClass;

class DELPHICLASS TcxGridCardScrollButtonDownViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardScrollButtonDownViewInfo : public TcxCustomGridCardScrollButtonViewInfo
{
	typedef TcxCustomGridCardScrollButtonViewInfo inherited;
	
protected:
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsDownButton(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall Scroll(void);
public:
	/* TcxCustomGridCardScrollButtonViewInfo.Create */ inline __fastcall virtual TcxGridCardScrollButtonDownViewInfo(TcxGridCardViewInfo* ACardViewInfo) : TcxCustomGridCardScrollButtonViewInfo(ACardViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardScrollButtonDownViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardScrollButtonUpViewInfoClass;

class DELPHICLASS TcxGridCardScrollButtonUpViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardScrollButtonUpViewInfo : public TcxCustomGridCardScrollButtonViewInfo
{
	typedef TcxCustomGridCardScrollButtonViewInfo inherited;
	
protected:
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsDownButton(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall Scroll(void);
public:
	/* TcxCustomGridCardScrollButtonViewInfo.Create */ inline __fastcall virtual TcxGridCardScrollButtonUpViewInfo(TcxGridCardViewInfo* ACardViewInfo) : TcxCustomGridCardScrollButtonViewInfo(ACardViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardScrollButtonUpViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardExpandButtonViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardExpandButtonViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridCardViewInfo* FCardViewInfo;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual void __fastcall Click(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	
public:
	__fastcall virtual TcxGridCardExpandButtonViewInfo(TcxGridCardViewInfo* ACardViewInfo);
	virtual bool __fastcall HasPoint(const System::Types::TPoint &P);
	__property TcxGridCardViewInfo* CardViewInfo = {read=FCardViewInfo};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardExpandButtonViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardRowLayerClass;

class DELPHICLASS TcxGridCardRowLayer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowLayer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FIndex;
	int FLength;
	TcxGridCardRowLayout* FOwner;
	int FThickness;
	System::Types::TRect __fastcall GetBounds(void);
	int __fastcall GetLength(void);
	TcxGridCardRowViewInfo* __fastcall GetRow(int AIndex);
	int __fastcall GetRowCount(void);
	int __fastcall GetThickness(void);
	
protected:
	virtual void __fastcall BeforeCalculation(void);
	virtual int __fastcall CalculateLength(void) = 0 ;
	virtual int __fastcall CalculateThickness(void) = 0 ;
	virtual void __fastcall SetThickness(int Value);
	
public:
	__fastcall virtual TcxGridCardRowLayer(TcxGridCardRowLayout* AOwner, int AIndex);
	virtual void __fastcall Calculate(int AOwnerWidth);
	virtual void __fastcall CalculateRows(const System::Types::TRect &ABounds, int ATopRowIndex, int &AVisibleRowCount, int &APartVisibleRowCount) = 0 ;
	virtual bool __fastcall HasPoint(const System::Types::TPoint &P) = 0 ;
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property int Index = {read=FIndex, nodefault};
	__property int Length = {read=GetLength, nodefault};
	__property TcxGridCardRowLayout* Owner = {read=FOwner};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxGridCardRowViewInfo* Rows[int Index] = {read=GetRow};
	__property int Thickness = {read=GetThickness, write=SetThickness, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardRowLayer(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowLayout : public TcxGridCardVisibleRowLayoutObject
{
	typedef TcxGridCardVisibleRowLayoutObject inherited;
	
private:
	typedef System::DynamicArray<TcxGridCardRowLayer*> _TcxGridCardRowLayout__1;
	
	
private:
	TcxGridCardViewInfo* FCardViewInfo;
	_TcxGridCardRowLayout__1 FLayers;
	int FSeparatorWidth;
	bool FSimple;
	TcxGridCardRowLayer* __fastcall GetLayer(int Index);
	TcxGridCardRowViewInfo* __fastcall GetLayerRowViewInfo(int ALayerIndex, int AIndex);
	int __fastcall GetSeparatorCount(void);
	void __fastcall CreateLayers(void);
	void __fastcall DestroyLayers(void);
	
protected:
	virtual void __fastcall BeforeCalculation(void);
	virtual void __fastcall CalculateLayerBounds(TcxGridCardRowLayer* ALayer, int AMaxRowHeight, System::Types::TRect &ABounds) = 0 ;
	virtual void __fastcall CalculateLayers(int AWidth);
	virtual int __fastcall CalculateRowsHeaderWidth(System::Classes::TList* ARows, int AWidth);
	virtual TcxGridCardRowLayerClass __fastcall GetLayerClass(void);
	virtual int __fastcall GetLayersHeight(void) = 0 ;
	virtual int __fastcall GetLayersLength(void);
	virtual int __fastcall GetLayersThickness(void);
	virtual int __fastcall GetNonContentThickness(void);
	bool __fastcall HasSeparator(TcxGridCardRowLayer* ALayer);
	virtual bool __fastcall IsLayerVisible(TcxGridCardRowLayer* ALayer, int ATopRowIndex)/* overload */;
	virtual bool __fastcall IsLayerVisible(const System::Types::TRect &ABounds, const System::Types::TRect &ALayerBounds)/* overload */;
	__property int LayersLength = {read=GetLayersLength, nodefault};
	__property int LayersThickness = {read=GetLayersThickness, nodefault};
	__property int NonContentThickness = {read=GetNonContentThickness, nodefault};
	
public:
	__fastcall virtual TcxGridCardRowLayout(TcxGridCardViewInfo* ACardViewInfo, bool ASimple);
	__fastcall virtual ~TcxGridCardRowLayout(void);
	virtual void __fastcall Calculate(int AWidth);
	virtual void __fastcall CalculateRows(const System::Types::TRect &ABounds, int ATopRowIndex, int AMaxRowHeight, int &AVisibleRowCount, int &APartVisibleRowCount);
	virtual int __fastcall GetHeaderWidth(TcxGridCardRowViewInfo* ARowViewInfo) = 0 ;
	HIDESBASE int __fastcall GetIndexInLayer(TcxGridCardRowViewInfo* ARowViewInfo)/* overload */;
	HIDESBASE int __fastcall GetLayerIndex(TcxGridCardRowViewInfo* ARowViewInfo)/* overload */;
	HIDESBASE int __fastcall GetLayerIndex(const System::Types::TPoint &P)/* overload */;
	virtual System::Types::TRect __fastcall GetSeparatorBounds(int AIndex) = 0 ;
	virtual bool __fastcall IsLeft(TcxGridCardRowViewInfo* ARowViewInfo) = 0 ;
	virtual bool __fastcall IsTop(TcxGridCardRowViewInfo* ARowViewInfo) = 0 ;
	virtual bool __fastcall IsZoneVertical(TcxGridCardRowContainerZone* AZone) = 0 ;
	__property TcxGridCardViewInfo* CardViewInfo = {read=FCardViewInfo};
	__property TcxGridCardRowViewInfo* LayerRowViewInfos[int ALayerIndex][int AIndex] = {read=GetLayerRowViewInfo};
	__property int LayersHeight = {read=GetLayersHeight, nodefault};
	__property TcxGridCardRowLayer* Layers[int Index] = {read=GetLayer};
	__property int SeparatorCount = {read=GetSeparatorCount, nodefault};
	__property int SeparatorWidth = {read=FSeparatorWidth, write=FSeparatorWidth, nodefault};
	__property bool Simple = {read=FSimple, nodefault};
/* Hoisted overloads: */
	
protected:
	inline int __fastcall  GetLayerIndex(int ARowIndex){ return TcxCustomGridCardRowLayoutObject::GetLayerIndex(ARowIndex); }
	
public:
	inline int __fastcall  GetLayerIndex(TcxGridCardViewRow* ARow){ return TcxCustomGridCardRowLayoutObject::GetLayerIndex(ARow); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowHorizontalLayer;
class DELPHICLASS TcxGridCardRowHorizontalLayout;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowHorizontalLayer : public TcxGridCardRowLayer
{
	typedef TcxGridCardRowLayer inherited;
	
private:
	TcxGridCardRowHorizontalLayout* __fastcall GetOwner(void);
	
protected:
	virtual int __fastcall CalculateLength(void);
	virtual void __fastcall CalculateRowWidths(int AAvailableWidth);
	virtual int __fastcall CalculateThickness(void);
	
public:
	virtual void __fastcall Calculate(int AOwnerWidth);
	virtual void __fastcall CalculateRows(const System::Types::TRect &ABounds, int ATopRowIndex, int &AVisibleRowCount, int &APartVisibleRowCount);
	virtual bool __fastcall HasPoint(const System::Types::TPoint &P);
	__property TcxGridCardRowHorizontalLayout* Owner = {read=GetOwner};
public:
	/* TcxGridCardRowLayer.Create */ inline __fastcall virtual TcxGridCardRowHorizontalLayer(TcxGridCardRowLayout* AOwner, int AIndex) : TcxGridCardRowLayer(AOwner, AIndex) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardRowHorizontalLayer(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowHorizontalLayout : public TcxGridCardRowLayout
{
	typedef TcxGridCardRowLayout inherited;
	
private:
	int FFirstColumnRowsHeaderWidth;
	
protected:
	virtual int __fastcall CalculateFirstColumnRowsHeaderWidth(int AWidth);
	virtual void __fastcall CalculateLayerBounds(TcxGridCardRowLayer* ALayer, int AMaxRowHeight, System::Types::TRect &ABounds);
	virtual TcxGridCardRowLayerClass __fastcall GetLayerClass(void);
	virtual int __fastcall GetLayersHeight(void);
	virtual bool __fastcall IsLayerVisible(TcxGridCardRowLayer* ALayer, int ATopRowIndex)/* overload */;
	virtual bool __fastcall IsLayerVisible(const System::Types::TRect &ABounds, const System::Types::TRect &ALayerBounds)/* overload */;
	
public:
	__fastcall virtual TcxGridCardRowHorizontalLayout(TcxGridCardViewInfo* ACardViewInfo, bool ASimple);
	virtual void __fastcall Calculate(int AWidth);
	virtual int __fastcall GetHeaderWidth(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(int AIndex);
	virtual bool __fastcall IsLeft(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual bool __fastcall IsTop(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual bool __fastcall IsZoneVertical(TcxGridCardRowContainerZone* AZone);
	__property int FirstColumnRowsHeaderWidth = {read=FFirstColumnRowsHeaderWidth, nodefault};
public:
	/* TcxGridCardRowLayout.Destroy */ inline __fastcall virtual ~TcxGridCardRowHorizontalLayout(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowVerticalLayer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowVerticalLayer : public TcxGridCardRowLayer
{
	typedef TcxGridCardRowLayer inherited;
	
private:
	int FRowsHeaderWidth;
	
protected:
	virtual int __fastcall CalculateLength(void);
	virtual int __fastcall CalculateRowsHeaderWidth(void);
	virtual int __fastcall CalculateThickness(void);
	virtual void __fastcall SetThickness(int Value);
	
public:
	__fastcall virtual TcxGridCardRowVerticalLayer(TcxGridCardRowLayout* AOwner, int AIndex);
	virtual void __fastcall Calculate(int AOwnerWidth);
	virtual void __fastcall CalculateRows(const System::Types::TRect &ABounds, int ATopRowIndex, int &AVisibleRowCount, int &APartVisibleRowCount);
	virtual bool __fastcall HasPoint(const System::Types::TPoint &P);
	__property int RowsHeaderWidth = {read=FRowsHeaderWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardRowVerticalLayer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardRowVerticalLayout;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardRowVerticalLayout : public TcxGridCardRowLayout
{
	typedef TcxGridCardRowLayout inherited;
	
protected:
	virtual void __fastcall CalculateLayerBounds(TcxGridCardRowLayer* ALayer, int AMaxRowHeight, System::Types::TRect &ABounds);
	virtual void __fastcall CalculateLayers(int AWidth);
	virtual void __fastcall CalculateLayerWidths(int AAvailableWidth);
	virtual TcxGridCardRowLayerClass __fastcall GetLayerClass(void);
	virtual int __fastcall GetLayersHeight(void);
	
public:
	virtual int __fastcall GetHeaderWidth(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(int AIndex);
	virtual bool __fastcall IsLeft(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual bool __fastcall IsTop(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual bool __fastcall IsZoneVertical(TcxGridCardRowContainerZone* AZone);
public:
	/* TcxGridCardRowLayout.Create */ inline __fastcall virtual TcxGridCardRowVerticalLayout(TcxGridCardViewInfo* ACardViewInfo, bool ASimple) : TcxGridCardRowLayout(ACardViewInfo, ASimple) { }
	/* TcxGridCardRowLayout.Destroy */ inline __fastcall virtual ~TcxGridCardRowVerticalLayout(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewInfoCacheItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutRecordViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutRecordViewInfo inherited;
	
private:
	TcxGridCardExpandButtonViewInfo* FExpandButtonViewInfo;
	TcxGridCardRowLayout* FLayout;
	bool FLayoutCalculated;
	int FPartVisibleRowCount;
	System::Classes::TList* FRowViewInfos;
	TcxGridCardScrollButtonDownViewInfo* FScrollButtonDown;
	TcxGridCardScrollButtonUpViewInfo* FScrollButtonUp;
	int FVisibleRowCount;
	HIDESBASE TcxGridCardViewInfoCacheItem* __fastcall GetCacheItem(void);
	int __fastcall GetCardBorderWidth(void);
	int __fastcall GetExpandButtonSizeValue(void);
	TcxGridCardRowViewInfo* __fastcall GetFirstCaptionRowViewInfo(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	TcxGridCard* __fastcall GetGridRecord(void);
	HIDESBASE TcxGridCardsViewInfo* __fastcall GetRecordsViewInfo(void);
	TcxGridCardRowViewInfo* __fastcall GetRowViewInfo(int Index);
	int __fastcall GetRowViewInfoCount(void);
	int __fastcall GetTopRowIndex(void);
	TcxGridCardRowViewInfo* __fastcall GetVisibleRowViewInfo(int Index);
	int __fastcall GetVisibleRowViewInfoCount(void);
	void __fastcall SetTopRowIndex(int Value);
	void __fastcall CreateRowViewInfos(void);
	void __fastcall DestroyRowViewInfos(void);
	void __fastcall CreateScrollButtons(void);
	void __fastcall DestroyScrollButtons(void);
	
protected:
	virtual void __fastcall CalculateExpandButtonBounds(System::Types::TRect &ABounds);
	virtual int __fastcall CalculateHeight(void);
	virtual void __fastcall CalculateLayout(void);
	void __fastcall DoCalculateLayout(void);
	virtual void __fastcall CalculateRows(void);
	virtual void __fastcall CalculateRowVisibles(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanGenerateExpandButtonHitTest(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual System::Types::TRect __fastcall GetBackgroundBitmapBounds(void);
	virtual System::Types::TRect __fastcall GetContentBounds(void);
	virtual int __fastcall GetContentHeight(void);
	virtual int __fastcall GetContentWidth(void);
	virtual TcxGridCardExpandButtonAlignment __fastcall GetExpandButtonAlignment(void);
	virtual System::Types::TRect __fastcall GetExpandButtonAreaBounds(void);
	virtual int __fastcall GetExpandButtonAreaWidth(void);
	virtual int __fastcall GetHeight(void);
	virtual System::Types::TRect __fastcall GetLayerSeparatorAreaBounds(void);
	virtual System::Uitypes::TColor __fastcall GetLayerSeparatorColor(void);
	virtual int __fastcall GetLayerSeparatorWidth(void);
	virtual int __fastcall GetMaxRowViewInfoHeight(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetRestSpaceBounds(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBounds(void);
	virtual System::Types::TRect __fastcall GetScrollButtonDownBounds(void);
	virtual TcxGridCardScrollButtonDownViewInfoClass __fastcall GetScrollButtonDownViewInfoClass(void);
	virtual TcxGridCardScrollButtonUpViewInfoClass __fastcall GetScrollButtonUpViewInfoClass(void);
	virtual int __fastcall GetScrollButtonHeight(void);
	virtual System::Types::TRect __fastcall GetScrollButtonUpBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall HasCategorySeparator(TcxGridCardCategoryRowViewInfo* ARowViewInfo)/* overload */;
	__classmethod virtual bool __fastcall HasCategorySeparator(TcxGridCardViewRow* ARow)/* overload */;
	virtual bool __fastcall HasIndent(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual bool __fastcall HasLayerSeparators(void);
	virtual bool __fastcall IsRowPartiallyVisible(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual bool __fastcall IsRowVisible(TcxGridCardRowViewInfo* ARowViewInfo);
	virtual bool __fastcall SupportsScrolling(void);
	virtual Cxgridcustomtableview::TcxGridItemContainerZone* __fastcall GetZone(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual System::Types::TRect __fastcall GetZoneBounds(TcxGridCardRowContainerZone* AZone);
	virtual bool __fastcall IsZoneVertical(TcxGridCardRowContainerZone* AZone);
	virtual TcxGridCardExpandButtonViewInfoClass __fastcall GetExpandButtonViewInfoClass(void);
	__classmethod virtual TcxGridCardRowViewInfoClass __fastcall GetRowViewInfoClass(TcxGridCardViewRow* ARow);
	__property TcxGridCardViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property int ExpandButtonAreaWidth = {read=GetExpandButtonAreaWidth, nodefault};
	__property int ExpandButtonSize = {read=GetExpandButtonSizeValue, nodefault};
	__property TcxGridCardRowViewInfo* FirstCaptionRowViewInfo = {read=GetFirstCaptionRowViewInfo};
	__property int LayerSeparatorWidth = {read=GetLayerSeparatorWidth, nodefault};
	__property int MaxRowViewInfoHeight = {read=GetMaxRowViewInfoHeight, nodefault};
	__property System::Types::TRect ScrollButtonDownBounds = {read=GetScrollButtonDownBounds};
	__property int ScrollButtonHeight = {read=GetScrollButtonHeight, nodefault};
	__property System::Types::TRect ScrollButtonUpBounds = {read=GetScrollButtonUpBounds};
	
public:
	__fastcall virtual TcxGridCardViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__fastcall virtual ~TcxGridCardViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual System::Types::TRect __fastcall GetBoundsForItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual void __fastcall GetCardBorderViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual Cxgridcustomtableview::TcxGridTableDataCellViewInfo* __fastcall GetCellViewInfoByItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual void __fastcall MainCalculate(int ALeftBound, int ATopBound);
	virtual void __fastcall MakeRowVisible(TcxGridCardViewRow* ARow);
	virtual bool __fastcall NeedsScrollingDown(void);
	virtual bool __fastcall NeedsScrollingUp(void);
	int __fastcall VisibleRowViewInfoIndexOf(TcxGridCardViewRow* ARow)/* overload */;
	int __fastcall VisibleRowViewInfoIndexOf(TcxGridCardRowViewInfo* ARowViewInfo)/* overload */;
	__property int CardBorderWidth = {read=GetCardBorderWidth, nodefault};
	__property TcxGridCardExpandButtonAlignment ExpandButtonAlignment = {read=GetExpandButtonAlignment, nodefault};
	__property TcxGridCardExpandButtonViewInfo* ExpandButtonViewInfo = {read=FExpandButtonViewInfo};
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property TcxGridCard* GridRecord = {read=GetGridRecord};
	__property System::Types::TRect LayerSeparatorAreaBounds = {read=GetLayerSeparatorAreaBounds};
	__property System::Uitypes::TColor LayerSeparatorColor = {read=GetLayerSeparatorColor, nodefault};
	__property TcxGridCardRowLayout* Layout = {read=FLayout};
	__property int PartVisibleRowCount = {read=FPartVisibleRowCount, nodefault};
	__property TcxGridCardsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	__property System::Types::TRect RestSpaceBounds = {read=GetRestSpaceBounds};
	__property int RowViewInfoCount = {read=GetRowViewInfoCount, nodefault};
	__property TcxGridCardRowViewInfo* RowViewInfos[int Index] = {read=GetRowViewInfo};
	__property System::Types::TRect ScrollableAreaBounds = {read=GetScrollableAreaBounds};
	__property TcxGridCardScrollButtonDownViewInfo* ScrollButtonDown = {read=FScrollButtonDown};
	__property TcxGridCardScrollButtonUpViewInfo* ScrollButtonUp = {read=FScrollButtonUp};
	__property int TopRowIndex = {read=GetTopRowIndex, write=SetTopRowIndex, nodefault};
	__property int VisibleRowCount = {read=FVisibleRowCount, nodefault};
	__property int VisibleRowViewInfoCount = {read=GetVisibleRowViewInfoCount, nodefault};
	__property TcxGridCardRowViewInfo* VisibleRowViewInfos[int Index] = {read=GetVisibleRowViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardsViewInfoHorizontalCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardsViewInfoHorizontalCalculator : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoHorizontalCalculator
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoHorizontalCalculator inherited;
	
protected:
	virtual int __fastcall GetRecordSpaceVert(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridCardsViewInfoHorizontalCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoHorizontalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardsViewInfoHorizontalCalculator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardsViewInfoVerticalCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardsViewInfoVerticalCalculator : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoVerticalCalculator
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoVerticalCalculator inherited;
	
protected:
	virtual int __fastcall GetRecordSpaceHorz(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridCardsViewInfoVerticalCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoVerticalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardsViewInfoVerticalCalculator(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardsViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo inherited;
	
private:
	typedef System::DynamicArray<int> _TcxGridCardsViewInfo__1;
	
	
public:
	TcxGridCardViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	int __fastcall GetCardBorderWidth(void);
	int __fastcall GetCardContentWidth(void);
	TcxGridCardViewColumns* __fastcall GetColumns(void);
	int __fastcall GetColumnWidth(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	HIDESBASE TcxGridCardViewViewInfo* __fastcall GetGridViewInfo(void);
	HIDESBASE TcxGridCardViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetRowHeight(void);
	HIDESBASE TcxGridCardViewViewData* __fastcall GetViewData(void);
	
protected:
	virtual int __fastcall CalculateRecordHeight(void);
	virtual int __fastcall CalculateCardRowHeight(TcxGridCardViewRow* ARow);
	virtual int __fastcall CalculateRecordWidth(void);
	virtual bool __fastcall GetAutoCellHeight(void);
	virtual bool __fastcall GetAutoDataRecordHeight(void);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutRecordViewInfoClass __fastcall GetItemViewInfoClass(void);
	virtual int __fastcall GetSeparatorWidth(void);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfoBasedCalculatorClass __fastcall GetCalculatorClass(void);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutViewBandsClass __fastcall GetBandsClass(void);
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property TcxGridCardViewViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridCardViewViewData* ViewData = {read=GetViewData};
	
public:
	_TcxGridCardsViewInfo__1 CardRowHeights;
	HIDESBASE virtual TcxGridCardViewInfo* __fastcall GetRealItem(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Cxgridcustomtableview::TcxGridItemContainerZone* __fastcall GetZone(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall UseCardHeight(void);
	virtual bool __fastcall UseCardRowHeights(void);
	__property bool AutoCellHeight = {read=GetAutoCellHeight, nodefault};
	__property int CardBorderWidth = {read=GetCardBorderWidth, nodefault};
	__property int CardContentWidth = {read=GetCardContentWidth, nodefault};
	__property TcxGridCardViewColumns* Columns = {read=GetColumns};
	__property int ColumnWidth = {read=GetColumnWidth, nodefault};
	__property TcxGridCardViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int RowHeight = {read=GetRowHeight, nodefault};
public:
	/* TcxGridCustomLayoutRecordsViewInfo.Create */ inline __fastcall virtual TcxGridCardsViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutRecordsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardsViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewSeparatorsViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewSeparatorsViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewSeparatorsViewInfo inherited;
	
private:
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	TcxGridCardViewViewInfo* __fastcall GetGridViewInfo(void);
	TcxGridCardsViewInfo* __fastcall GetCardsViewInfo(void);
	
protected:
	virtual System::Types::TRect __fastcall GetHitTestItem(int Index) = 0 ;
	virtual int __fastcall GetHitTestItemCount(void) = 0 ;
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property TcxGridCardViewViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property int HitTestItemCount = {read=GetHitTestItemCount, nodefault};
	__property System::Types::TRect HitTestItems[int Index] = {read=GetHitTestItem};
	__property TcxGridCardsViewInfo* CardsViewInfo = {read=GetCardsViewInfo};
	
public:
	virtual TcxGridCardViewSeparatorHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property System::Uitypes::TColor Color = {read=GetColor, nodefault};
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridCardViewSeparatorsViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardViewSeparatorsViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewSeparatorsHorizontalViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewSeparatorsHorizontalViewInfo : public TcxGridCardViewSeparatorsViewInfo
{
	typedef TcxGridCardViewSeparatorsViewInfo inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetHitTestItem(int Index);
	virtual int __fastcall GetHitTestItemCount(void);
	
public:
	virtual void __fastcall DoCalculate(void);
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridCardViewSeparatorsHorizontalViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : TcxGridCardViewSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardViewSeparatorsHorizontalViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewSeparatorsVerticalViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewSeparatorsVerticalViewInfo : public TcxGridCardViewSeparatorsViewInfo
{
	typedef TcxGridCardViewSeparatorsViewInfo inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetHitTestItem(int Index);
	virtual int __fastcall GetHitTestItemCount(void);
	
public:
	virtual void __fastcall DoCalculate(void);
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridCardViewSeparatorsVerticalViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : TcxGridCardViewSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardViewSeparatorsVerticalViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo inherited;
	
private:
	HIDESBASE TcxGridCardViewController* __fastcall GetController(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	HIDESBASE TcxGridCardsViewInfo* __fastcall GetRecordsViewInfo(void);
	TcxGridCardViewSeparatorsViewInfo* __fastcall GetSeparatorsViewInfo(void);
	HIDESBASE TcxGridCardViewViewData* __fastcall GetViewData(void);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall DoGetHitTest(const System::Types::TPoint &P);
	virtual int __fastcall GetDefaultGridModeBufferCount(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsForEdit(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordsViewInfoClass __fastcall GetRecordsViewInfoClass(void);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutViewSeparatorsViewInfoClass __fastcall GetSeparatorsViewInfoClass(void);
	__property TcxGridCardViewController* Controller = {read=GetController};
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property TcxGridCardViewViewData* ViewData = {read=GetViewData};
	
public:
	__property TcxGridCardsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	__property TcxGridCardViewSeparatorsViewInfo* SeparatorsViewInfo = {read=GetSeparatorsViewInfo};
public:
	/* TcxCustomGridTableViewInfo.Create */ inline __fastcall virtual TcxGridCardViewViewInfo(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo(AGridView) { }
	/* TcxCustomGridTableViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCardViewViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewInfoCacheItem : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoCacheItem
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoCacheItem inherited;
	
private:
	int FTopRowIndex;
	bool FIsTopRowIndexAssigned;
	void __fastcall SetTopRowIndex(int Value);
	
public:
	virtual void __fastcall UnassignValues(bool AKeepMaster);
	__property int TopRowIndex = {read=FTopRowIndex, write=SetTopRowIndex, nodefault};
	__property bool IsTopRowIndexAssigned = {read=FIsTopRowIndexAssigned, write=FIsTopRowIndexAssigned, nodefault};
public:
	/* TcxCustomGridViewInfoCacheItem.Create */ inline __fastcall virtual TcxGridCardViewInfoCacheItem(Cxgridcustomview::TcxCustomGridViewInfoCache* AOwner, int AIndex) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoCacheItem(AOwner, AIndex) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCardViewInfoCacheItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewRowOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewRowOptions : public Cxgridcustomtableview::TcxCustomGridTableItemOptions
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemOptions inherited;
	
private:
	bool FExpanding;
	bool FShowData;
	void __fastcall SetExpanding(bool Value);
	void __fastcall SetShowData(bool Value);
	
protected:
	virtual void __fastcall BeforeShowCaptionChange(void);
	
public:
	__fastcall virtual TcxGridCardViewRowOptions(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Expanding = {read=FExpanding, write=SetExpanding, default=1};
	__property Moving = {default=1};
	__property ShowCaption = {default=1};
	__property bool ShowData = {read=FShowData, write=SetShowData, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridCardViewRowOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCardViewRowPositionClass;

class DELPHICLASS TcxGridCardViewRowPosition;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewRowPosition : public Cxgridcustomtableview::TcxCustomGridTableItemCustomOptions
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemCustomOptions inherited;
	
private:
	bool FBeginsLayer;
	int FLineCount;
	int FWidth;
	bool __fastcall GetBeginsLayer(void);
	int __fastcall GetColIndex(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	int __fastcall GetIndexInLayer(void);
	TcxGridCardViewRow* __fastcall GetItem(void);
	int __fastcall GetLayerIndex(void);
	int __fastcall GetLayerVisibleIndex(void);
	int __fastcall GetRowIndex(void);
	int __fastcall GetVisibleColIndex(void);
	int __fastcall GetVisibleIndexInLayer(void);
	int __fastcall GetVisibleRowIndex(void);
	void __fastcall SetBeginsLayer(bool Value);
	void __fastcall SetColIndex(int Value);
	void __fastcall SetIndexInLayer(int Value);
	void __fastcall SetLayerIndex(int Value);
	void __fastcall SetLineCount(int Value);
	void __fastcall SetRowIndex(int Value);
	void __fastcall SetWidth(int Value);
	
protected:
	void __fastcall AssignParams(void);
	void __fastcall SaveParams(void);
	
public:
	__fastcall virtual TcxGridCardViewRowPosition(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsWholeLine(void);
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property TcxGridCardViewRow* Item = {read=GetItem};
	__property int ColIndex = {read=GetColIndex, write=SetColIndex, nodefault};
	__property int RowIndex = {read=GetRowIndex, write=SetRowIndex, nodefault};
	__property int VisibleColIndex = {read=GetVisibleColIndex, nodefault};
	__property int VisibleRowIndex = {read=GetVisibleRowIndex, nodefault};
	__property int LayerVisibleIndex = {read=GetLayerVisibleIndex, nodefault};
	__property int VisibleIndexInLayer = {read=GetVisibleIndexInLayer, nodefault};
	
__published:
	__property bool BeginsLayer = {read=GetBeginsLayer, write=SetBeginsLayer, nodefault};
	__property int IndexInLayer = {read=GetIndexInLayer, write=SetIndexInLayer, stored=false, nodefault};
	__property int LayerIndex = {read=GetLayerIndex, write=SetLayerIndex, stored=false, nodefault};
	__property int LineCount = {read=FLineCount, write=SetLineCount, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridCardViewRowPosition(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewRowStyles;
class PASCALIMPLEMENTATION TcxGridCardViewRowStyles : public Cxgridcustomtableview::TcxCustomGridTableItemStyles
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemStyles inherited;
	
private:
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetCaptionRowStyle;
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetCaptionStyle;
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetCategoryRowStyle;
	HIDESBASE TcxGridCardView* __fastcall GetGridViewValue(void);
	HIDESBASE TcxGridCardViewRow* __fastcall GetItem(void);
	void __fastcall SetOnGetCaptionRowStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	void __fastcall SetOnGetCaptionStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	void __fastcall SetOnGetCategoryRowStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxGridCardViewRowStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetCaptionParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetCaptionRowParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetCategoryRowParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridCardView* GridView = {read=GetGridViewValue};
	__property TcxGridCardViewRow* Item = {read=GetItem};
	
__published:
	__property Cxstyles::TcxStyle* Caption = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* CaptionRow = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* CategoryRow = {read=GetValue, write=SetValue, index=2};
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetCaptionRowStyle = {read=FOnGetCaptionRowStyle, write=SetOnGetCaptionRowStyle};
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetCaptionStyle = {read=FOnGetCaptionStyle, write=SetOnGetCaptionStyle};
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetCategoryRowStyle = {read=FOnGetCategoryRowStyle, write=SetOnGetCategoryRowStyle};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridCardViewRowStyles(void) { }
	
};


enum TcxGridCardViewRowKind : unsigned char { rkData, rkCaption, rkCategory };

class PASCALIMPLEMENTATION TcxGridCardViewRow : public Cxgridcustomtableview::TcxCustomGridTableItem
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItem inherited;
	
private:
	System::Classes::TList* FCategoryItems;
	TcxGridCardViewRow* FCategoryRow;
	bool FExpanded;
	TcxGridCardViewRowKind FKind;
	bool FLockPositionSync;
	TcxGridCardViewRowPosition* FPosition;
	System::Classes::TAlignment __fastcall GetCaptionAlignmentHorz(void);
	Cxclasses::TcxAlignmentVert __fastcall GetCaptionAlignmentVert(void);
	TcxGridCardViewRow* __fastcall GetCategoryItem(int AIndex);
	int __fastcall GetCategoryItemCount(void);
	bool __fastcall GetExpanded(void);
	TcxGridCardView* __fastcall GetGridView(void);
	TcxGridCardViewRowOptions* __fastcall GetOptions(void);
	TcxGridCardViewRowStyles* __fastcall GetStyles(void);
	void __fastcall SetCaptionAlignmentHorz(System::Classes::TAlignment Value);
	void __fastcall SetCaptionAlignmentVert(Cxclasses::TcxAlignmentVert Value);
	void __fastcall SetCategoryRow(TcxGridCardViewRow* Value);
	void __fastcall SetCategoryRowValue(TcxGridCardViewRow* Value);
	void __fastcall SetExpanded(bool Value);
	void __fastcall SetKind(TcxGridCardViewRowKind Value);
	HIDESBASE void __fastcall SetOptions(TcxGridCardViewRowOptions* Value);
	void __fastcall SetPosition(TcxGridCardViewRowPosition* Value);
	HIDESBASE void __fastcall SetStyles(TcxGridCardViewRowStyles* Value);
	bool __fastcall IsCaptionAlignmentHorzStored(void);
	bool __fastcall IsCaptionAlignmentVertStored(void);
	
protected:
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemOptionsClass __fastcall GetOptionsClass(void);
	virtual TcxGridCardViewRowPositionClass __fastcall GetPositionClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemStylesClass __fastcall GetStylesClass(void);
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall CanExpand(void);
	virtual bool __fastcall CanFilter(bool AVisually);
	virtual bool __fastcall CanFocus(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall ChangeGroupIndex(int Value);
	virtual System::UnicodeString __fastcall DefaultAlternateCaption(void);
	virtual int __fastcall DefaultWidth(void);
	virtual bool __fastcall GetActuallyVisible(void);
	virtual bool __fastcall GetExpandable(void);
	virtual void __fastcall GetItems(System::Classes::TList* ARows, bool AIncludeSubItems);
	virtual System::UnicodeString __fastcall GetVisibleCaption(void);
	virtual bool __fastcall HasExpandableItems(void);
	__property System::Classes::TList* CategoryItemsList = {read=FCategoryItems};
	__property TcxGridCardView* GridView = {read=GetGridView};
	__property bool LockPositionSync = {read=FLockPositionSync, write=FLockPositionSync, nodefault};
	
public:
	__fastcall virtual TcxGridCardViewRow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridCardViewRow(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall HasCardExpandButton(void);
	virtual bool __fastcall HasExpandButton(void);
	virtual bool __fastcall IsVisibleInCard(TcxGridCard* ACard);
	void __fastcall MoveTo(int AIndex, bool AMoveSubItems);
	__property int CategoryItemCount = {read=GetCategoryItemCount, nodefault};
	__property TcxGridCardViewRow* CategoryItems[int AIndex] = {read=GetCategoryItem};
	__property TcxGridCardViewRow* CategoryRow = {read=FCategoryRow, write=SetCategoryRow};
	__property bool Expandable = {read=GetExpandable, nodefault};
	__property Hidden;
	
__published:
	__property System::Classes::TAlignment CaptionAlignmentHorz = {read=GetCaptionAlignmentHorz, write=SetCaptionAlignmentHorz, stored=IsCaptionAlignmentHorzStored, nodefault};
	__property Cxclasses::TcxAlignmentVert CaptionAlignmentVert = {read=GetCaptionAlignmentVert, write=SetCaptionAlignmentVert, stored=IsCaptionAlignmentVertStored, nodefault};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, default=0};
	__property TcxGridCardViewRowKind Kind = {read=FKind, write=SetKind, default=0};
	__property TcxGridCardViewRowOptions* Options = {read=GetOptions, write=SetOptions};
	__property TcxGridCardViewRowPosition* Position = {read=FPosition, write=SetPosition};
	__property SortIndex = {default=-1};
	__property SortOrder;
	__property TcxGridCardViewRowStyles* Styles = {read=GetStyles, write=SetStyles};
	__property VisibleForCustomization;
};


class DELPHICLASS TcxGridCardViewBackgroundBitmaps;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewBackgroundBitmaps : public Cxgridcustomtableview::TcxCustomGridTableBackgroundBitmaps
{
	typedef Cxgridcustomtableview::TcxCustomGridTableBackgroundBitmaps inherited;
	
protected:
	virtual int __fastcall GetBitmapStyleIndex(int Index);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBitmap(int Index);
	
__published:
	__property Vcl::Graphics::TBitmap* CaptionRow = {read=GetValue, write=SetValue, index=3};
	__property Vcl::Graphics::TBitmap* CardBorder = {read=GetValue, write=SetValue, index=4};
	__property Vcl::Graphics::TBitmap* RowCaption = {read=GetValue, write=SetValue, index=5};
public:
	/* TcxCustomGridBackgroundBitmaps.Create */ inline __fastcall virtual TcxGridCardViewBackgroundBitmaps(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableBackgroundBitmaps(AGridView) { }
	/* TcxCustomGridBackgroundBitmaps.Destroy */ inline __fastcall virtual ~TcxGridCardViewBackgroundBitmaps(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewDateTimeHandling;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewDateTimeHandling : public Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling
{
	typedef Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling inherited;
	
public:
	/* TcxCustomGridTableDateTimeHandling.Create */ inline __fastcall virtual TcxGridCardViewDateTimeHandling(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridCardViewDateTimeHandling(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewFiltering;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewFiltering : public Cxgridcustomtableview::TcxCustomGridTableFiltering
{
	typedef Cxgridcustomtableview::TcxCustomGridTableFiltering inherited;
	
private:
	bool __fastcall GetRowAddValueItems(void);
	bool __fastcall GetRowFilteredItemsList(void);
	bool __fastcall GetRowMRUItemsList(void);
	int __fastcall GetRowMRUItemsListCount(void);
	Cxgridcustomtableview::TcxGridItemFilterPopupOptions* __fastcall GetRowPopup(void);
	void __fastcall SetRowAddValueItems(bool Value);
	void __fastcall SetRowFilteredItemsList(bool Value);
	void __fastcall SetRowMRUItemsList(bool Value);
	void __fastcall SetRowMRUItemsListCount(int Value);
	void __fastcall SetRowPopup(Cxgridcustomtableview::TcxGridItemFilterPopupOptions* Value);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	__property DropDownWidth;
	__property int RowPopupDropDownWidth = {read=GetItemPopupDropDownWidth, write=SetItemPopupDropDownWidth, nodefault};
	__property MaxDropDownCount;
	__property int RowPopupMaxDropDownItemCount = {read=GetItemPopupMaxDropDownItemCount, write=SetItemPopupMaxDropDownItemCount, nodefault};
	
__published:
	__property bool RowAddValueItems = {read=GetRowAddValueItems, write=SetRowAddValueItems, default=1};
	__property bool RowFilteredItemsList = {read=GetRowFilteredItemsList, write=SetRowFilteredItemsList, default=0};
	__property bool RowMRUItemsList = {read=GetRowMRUItemsList, write=SetRowMRUItemsList, default=1};
	__property int RowMRUItemsListCount = {read=GetRowMRUItemsListCount, write=SetRowMRUItemsListCount, default=5};
	__property Cxgridcustomtableview::TcxGridItemFilterPopupOptions* RowPopup = {read=GetRowPopup, write=SetRowPopup};
public:
	/* TcxCustomGridTableFiltering.Create */ inline __fastcall virtual TcxGridCardViewFiltering(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableFiltering(AGridView) { }
	/* TcxCustomGridTableFiltering.Destroy */ inline __fastcall virtual ~TcxGridCardViewFiltering(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewOptionsBehavior : public Cxgridcustomtableview::TcxCustomGridTableOptionsBehavior
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsBehavior inherited;
	
private:
	bool FExpandRowOnDblClick;
	bool FRowCaptionHints;
	void __fastcall SetExpandRowOnDblClick(bool Value);
	void __fastcall SetRowCaptionHints(bool Value);
	
public:
	__fastcall virtual TcxGridCardViewOptionsBehavior(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool ExpandRowOnDblClick = {read=FExpandRowOnDblClick, write=SetExpandRowOnDblClick, default=1};
	__property PullFocusing = {default=0};
	__property bool RowCaptionHints = {read=FRowCaptionHints, write=SetRowCaptionHints, default=1};
public:
	/* TcxCustomGridOptionsBehavior.Destroy */ inline __fastcall virtual ~TcxGridCardViewOptionsBehavior(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewOptionsCustomize;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewOptionsCustomize : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsCustomize
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsCustomize inherited;
	
private:
	bool FCardSizing;
	bool FLayeredRows;
	bool FRowExpanding;
	bool __fastcall GetCardExpanding(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	bool __fastcall GetRowFiltering(void);
	bool __fastcall GetRowHiding(void);
	bool __fastcall GetRowMoving(void);
	void __fastcall SetCardExpanding(bool Value);
	void __fastcall SetCardSizing(bool Value);
	void __fastcall SetLayeredRows(bool Value);
	void __fastcall SetRowExpanding(bool Value);
	void __fastcall SetRowFiltering(bool Value);
	void __fastcall SetRowHiding(bool Value);
	void __fastcall SetRowMoving(bool Value);
	
public:
	__fastcall virtual TcxGridCardViewOptionsCustomize(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridCardView* GridView = {read=GetGridView};
	
__published:
	__property bool CardExpanding = {read=GetCardExpanding, write=SetCardExpanding, default=0};
	__property bool CardSizing = {read=FCardSizing, write=SetCardSizing, default=1};
	__property bool LayeredRows = {read=FLayeredRows, write=SetLayeredRows, default=0};
	__property bool RowExpanding = {read=FRowExpanding, write=SetRowExpanding, default=1};
	__property bool RowFiltering = {read=GetRowFiltering, write=SetRowFiltering, default=1};
	__property bool RowHiding = {read=GetRowHiding, write=SetRowHiding, default=0};
	__property bool RowMoving = {read=GetRowMoving, write=SetRowMoving, default=0};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridCardViewOptionsCustomize(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewOptionsData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewOptionsData : public Cxgridcustomtableview::TcxCustomGridTableOptionsData
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsData inherited;
	
public:
	/* TcxCustomGridTableOptionsData.Create */ inline __fastcall virtual TcxGridCardViewOptionsData(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableOptionsData(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridCardViewOptionsData(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewOptionsSelection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewOptionsSelection : public Cxgridcustomtableview::TcxCustomGridTableOptionsSelection
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsSelection inherited;
	
private:
	bool FCardBorderSelection;
	void __fastcall SetCardBorderSelection(bool Value);
	
public:
	__fastcall virtual TcxGridCardViewOptionsSelection(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CardBorderSelection = {read=FCardBorderSelection, write=SetCardBorderSelection, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridCardViewOptionsSelection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewOptionsView : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsView
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsView inherited;
	
private:
	int FCaptionWidth;
	bool FCardAutoWidth;
	int FCardBorderWidth;
	TcxGridCardExpandButtonAlignment FCardExpandButtonAlignment;
	int FCardWidth;
	int FCategoryIndent;
	bool FCategoryRowCaptionInRowAlternateCaption;
	int FCategorySeparatorWidth;
	bool FEmptyRows;
	int FLayerSeparatorWidth;
	int __fastcall GetCardIndent(void);
	HIDESBASE TcxGridCardView* __fastcall GetGridView(void);
	bool __fastcall GetRowCaptionAutoHeight(void);
	bool __fastcall GetRowCaptionEndEllipsis(void);
	Cxgridcustomtableview::TcxGridShowItemFilterButtons __fastcall GetShowRowFilterButtons(void);
	void __fastcall SetCaptionWidth(int Value);
	void __fastcall SetCardAutoWidth(bool Value);
	void __fastcall SetCardBorderWidth(int Value);
	void __fastcall SetCardExpandButtonAlignment(TcxGridCardExpandButtonAlignment Value);
	void __fastcall SetCardIndent(int Value);
	void __fastcall SetCardWidth(int Value);
	void __fastcall SetCategoryIndent(int Value);
	void __fastcall SetCategoryRowCaptionInRowAlternateCaption(bool Value);
	void __fastcall SetCategorySeparatorWidth(int Value);
	void __fastcall SetEmptyRows(bool Value);
	void __fastcall SetLayerSeparatorWidth(int Value);
	void __fastcall SetRowCaptionAutoHeight(bool Value);
	void __fastcall SetRowCaptionEndEllipsis(bool Value);
	void __fastcall SetShowRowFilterButtons(Cxgridcustomtableview::TcxGridShowItemFilterButtons Value);
	
public:
	__fastcall virtual TcxGridCardViewOptionsView(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridCardView* GridView = {read=GetGridView};
	
__published:
	__property CaptionSeparator = {default=58};
	__property int CaptionWidth = {read=FCaptionWidth, write=SetCaptionWidth, default=0};
	__property bool CardAutoWidth = {read=FCardAutoWidth, write=SetCardAutoWidth, default=0};
	__property int CardBorderWidth = {read=FCardBorderWidth, write=SetCardBorderWidth, default=3};
	__property TcxGridCardExpandButtonAlignment CardExpandButtonAlignment = {read=FCardExpandButtonAlignment, write=SetCardExpandButtonAlignment, default=1};
	__property int CardIndent = {read=GetCardIndent, write=SetCardIndent, nodefault};
	__property int CardWidth = {read=FCardWidth, write=SetCardWidth, default=200};
	__property int CategoryIndent = {read=FCategoryIndent, write=SetCategoryIndent, default=17};
	__property bool CategoryRowCaptionInRowAlternateCaption = {read=FCategoryRowCaptionInRowAlternateCaption, write=SetCategoryRowCaptionInRowAlternateCaption, default=0};
	__property int CategorySeparatorWidth = {read=FCategorySeparatorWidth, write=SetCategorySeparatorWidth, default=2};
	__property CellAutoHeight = {default=0};
	__property CellTextMaxLineCount = {default=0};
	__property bool EmptyRows = {read=FEmptyRows, write=SetEmptyRows, default=1};
	__property int LayerSeparatorWidth = {read=FLayerSeparatorWidth, write=SetLayerSeparatorWidth, default=0};
	__property bool RowCaptionAutoHeight = {read=GetRowCaptionAutoHeight, write=SetRowCaptionAutoHeight, default=0};
	__property bool RowCaptionEndEllipsis = {read=GetRowCaptionEndEllipsis, write=SetRowCaptionEndEllipsis, default=0};
	__property SeparatorColor = {default=536870912};
	__property SeparatorWidth = {default=2};
	__property Cxgridcustomtableview::TcxGridShowItemFilterButtons ShowRowFilterButtons = {read=GetShowRowFilterButtons, write=SetShowRowFilterButtons, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridCardViewOptionsView(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCardViewStyles;
class PASCALIMPLEMENTATION TcxGridCardViewStyles : public Cxgridcustomtableview::TcxCustomGridTableViewStyles
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewStyles inherited;
	
private:
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetCaptionRowStyle;
	Cxgridcustomtableview::TcxGridGetRecordStyleEvent FOnGetCardBorderStyle;
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetCategoryRowStyle;
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetRowCaptionStyle;
	HIDESBASE TcxGridCardView* __fastcall GetGridViewValue(void);
	void __fastcall SetOnGetCaptionRowStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	void __fastcall SetOnGetCardBorderStyle(Cxgridcustomtableview::TcxGridGetRecordStyleEvent Value);
	void __fastcall SetOnGetCategoryRowStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	void __fastcall SetOnGetRowCaptionStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	
protected:
	virtual int __fastcall GetBackgroundBitmapIndex(int Index);
	virtual Vcl::Graphics::TBitmap* __fastcall GetDefaultBitmap(int Index);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxGridCardViewStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetCaptionRowParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetCardBorderParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetCardBorderVisualParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetCategoryRowParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetDataCellContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetRowCaptionParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridCardView* GridView = {read=GetGridViewValue};
	
__published:
	__property Cxstyles::TcxStyle* CaptionRow = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* CardBorder = {read=GetValue, write=SetValue, index=11};
	__property Cxstyles::TcxStyle* CategoryRow = {read=GetValue, write=SetValue, index=12};
	__property Cxstyles::TcxStyle* CategorySeparator = {read=GetValue, write=SetValue, index=13};
	__property Cxstyles::TcxStyle* LayerSeparator = {read=GetValue, write=SetValue, index=14};
	__property Cxstyles::TcxStyle* RowCaption = {read=GetValue, write=SetValue, index=15};
	__property StyleSheet;
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetCaptionRowStyle = {read=FOnGetCaptionRowStyle, write=SetOnGetCaptionRowStyle};
	__property Cxgridcustomtableview::TcxGridGetRecordStyleEvent OnGetCardBorderStyle = {read=FOnGetCardBorderStyle, write=SetOnGetCardBorderStyle};
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetCategoryRowStyle = {read=FOnGetCategoryRowStyle, write=SetOnGetCategoryRowStyle};
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetRowCaptionStyle = {read=FOnGetRowCaptionStyle, write=SetOnGetRowCaptionStyle};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridCardViewStyles(void) { }
	
};


class DELPHICLASS TcxGridCardViewStyleSheet;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewStyleSheet : public Cxstyles::TcxCustomStyleSheet
{
	typedef Cxstyles::TcxCustomStyleSheet inherited;
	
private:
	TcxGridCardViewStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxGridCardViewStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxGridCardViewStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxGridCardViewStyleSheet(System::Classes::TComponent* AOwner) : Cxstyles::TcxCustomStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxGridCardViewStyleSheet(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridCardRowEvent)(TcxGridCardView* Sender, TcxGridCardViewRow* ARow);

typedef void __fastcall (__closure *TcxGridCardRowChangingEvent)(TcxGridCardView* Sender, TcxGridCardViewRow* ARow, bool &AAllow);

class PASCALIMPLEMENTATION TcxGridCardView : public Cxgridcustomlayoutview::TcxGridCustomLayoutView
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutView inherited;
	
private:
	TcxGridCardViewLayoutDirection FLayoutDirection;
	TcxGridCardRowChangingEvent FOnRowCollapsing;
	TcxGridCardRowEvent FOnRowCollapsed;
	TcxGridCardRowChangingEvent FOnRowExpanding;
	TcxGridCardRowEvent FOnRowExpanded;
	TcxGridCardRowEvent FOnRowPosChanged;
	TcxGridCardViewRowLayout FRowLayout;
	TcxGridCardViewRowLayoutController* FRowLayoutController;
	HIDESBASE TcxGridCardViewBackgroundBitmaps* __fastcall GetBackgroundBitmaps(void);
	Cxgrid::TcxCustomGrid* __fastcall GetControl(void);
	HIDESBASE TcxGridCardViewController* __fastcall GetController(void);
	Cxgridcustomtableview::TcxGridDataController* __fastcall GetDataController(void);
	TcxGridCardViewDateTimeHandling* __fastcall GetDateTimeHandling(void);
	TcxGridCardViewFiltering* __fastcall GetFiltering(void);
	TcxGridCardViewRow* __fastcall GetFirstCaptionRow(void);
	TcxGridCardViewRow* __fastcall GetFirstCategoryRow(void);
	HIDESBASE TcxGridCardViewOptionsBehavior* __fastcall GetOptionsBehavior(void);
	HIDESBASE TcxGridCardViewOptionsCustomize* __fastcall GetOptionsCustomize(void);
	HIDESBASE TcxGridCardViewOptionsData* __fastcall GetOptionsData(void);
	HIDESBASE TcxGridCardViewOptionsSelection* __fastcall GetOptionsSelection(void);
	HIDESBASE TcxGridCardViewOptionsView* __fastcall GetOptionsView(void);
	HIDESBASE TcxGridCardViewPainter* __fastcall GetPainter(void);
	TcxGridCardViewRow* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	HIDESBASE TcxGridCardViewStyles* __fastcall GetStyles(void);
	HIDESBASE TcxGridCardViewViewData* __fastcall GetViewData(void);
	HIDESBASE TcxGridCardViewViewInfo* __fastcall GetViewInfo(void);
	TcxGridCardViewRow* __fastcall GetVisibleRow(int Index);
	int __fastcall GetVisibleRowCount(void);
	HIDESBASE void __fastcall SetBackgroundBitmaps(TcxGridCardViewBackgroundBitmaps* Value);
	void __fastcall SetDataController(Cxgridcustomtableview::TcxGridDataController* Value);
	HIDESBASE void __fastcall SetDateTimeHandling(TcxGridCardViewDateTimeHandling* Value);
	HIDESBASE void __fastcall SetFiltering(TcxGridCardViewFiltering* Value);
	void __fastcall SetLayoutDirection(TcxGridCardViewLayoutDirection Value);
	void __fastcall SetOnRowCollapsed(TcxGridCardRowEvent Value);
	void __fastcall SetOnRowCollapsing(TcxGridCardRowChangingEvent Value);
	void __fastcall SetOnRowExpanded(TcxGridCardRowEvent Value);
	void __fastcall SetOnRowExpanding(TcxGridCardRowChangingEvent Value);
	void __fastcall SetOnRowPosChanged(TcxGridCardRowEvent Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxGridCardViewOptionsBehavior* Value);
	HIDESBASE void __fastcall SetOptionsCustomize(TcxGridCardViewOptionsCustomize* Value);
	HIDESBASE void __fastcall SetOptionsData(TcxGridCardViewOptionsData* Value);
	HIDESBASE void __fastcall SetOptionsSelection(TcxGridCardViewOptionsSelection* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxGridCardViewOptionsView* Value);
	void __fastcall SetRow(int Index, TcxGridCardViewRow* Value);
	void __fastcall SetRowLayout(TcxGridCardViewRowLayout Value);
	HIDESBASE void __fastcall SetStyles(TcxGridCardViewStyles* Value);
	void __fastcall RefreshCategoryRowLinks(void);
	
protected:
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall AssignLayout(Cxgridcustomview::TcxCustomGridView* ALayoutView);
	virtual System::UnicodeString __fastcall GetLayoutCustomizationFormButtonCaption(void);
	virtual void __fastcall CreateHandlers(void);
	virtual void __fastcall DestroyHandlers(void);
	virtual Cxgridcustomview::TcxCustomGridControllerClass __fastcall GetControllerClass(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridcustomview::TcxCustomGridPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridCardViewRowLayoutControllerClass __fastcall GetRowLayoutControllerClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewDataClass __fastcall GetViewDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void);
	void __fastcall SaveRowParams(void);
	void __fastcall AssignRowParams(void);
	TcxGridCardRowCoordinatesArray __fastcall GetRowCoordinates(void);
	void __fastcall SetRowCoordinates(const TcxGridCardRowCoordinatesArray ACoordinates);
	DYNAMIC void __fastcall Updating(void);
	DYNAMIC void __fastcall Updated(void);
	virtual void __fastcall BeforeRestoring(void);
	virtual void __fastcall AfterRestoring(void);
	virtual void __fastcall ChangeItemIndex(Cxgridcustomtableview::TcxCustomGridTableItem* AItem, int Value);
	virtual void __fastcall DoAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual bool __fastcall GetResizeOnBoundsChange(void);
	virtual void __fastcall ItemIndexChanged(Cxgridcustomtableview::TcxCustomGridTableItem* AItem, int AOldIndex);
	virtual void __fastcall ItemVisibilityChanged(Cxgridcustomtableview::TcxCustomGridTableItem* AItem, bool Value);
	virtual void __fastcall RefreshVisibleItemsList(void);
	virtual void __fastcall RowExpandedChanged(TcxGridCardViewRow* ARow);
	virtual bool __fastcall RowExpandedChanging(TcxGridCardViewRow* ARow, bool AValue);
	virtual bool __fastcall CalculateDataCellSelected(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, bool AUseViewInfo, Cxgridcustomtableview::TcxGridTableCellViewInfo* ACellViewInfo);
	virtual bool __fastcall DrawCardBorderSelected(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Cxgridcustomview::TcxCustomGridBackgroundBitmapsClass __fastcall GetBackgroundBitmapsClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableDateTimeHandlingClass __fastcall GetDateTimeHandlingClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableFilteringClass __fastcall GetFilteringClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableOptionsCustomizeClass __fastcall GetOptionsCustomizeClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewStylesClass __fastcall GetStylesClass(void);
	virtual bool __fastcall SupportsCardSizing(void);
	virtual bool __fastcall SupportsLayeredRows(void);
	virtual void __fastcall DoRowCollapsed(TcxGridCardViewRow* ARow);
	virtual bool __fastcall DoRowCollapsing(TcxGridCardViewRow* ARow);
	virtual void __fastcall DoRowExpanded(TcxGridCardViewRow* ARow);
	virtual bool __fastcall DoRowExpanding(TcxGridCardViewRow* ARow);
	virtual void __fastcall DoRowPositionChanged(TcxGridCardViewRow* ARow);
	__property TcxGridCardViewRow* FirstCaptionRow = {read=GetFirstCaptionRow};
	__property TcxGridCardViewRow* FirstCategoryRow = {read=GetFirstCategoryRow};
	
public:
	TcxGridCardViewRow* __fastcall CreateRow(void);
	__property Cxgrid::TcxCustomGrid* Control = {read=GetControl};
	__property TcxGridCardViewController* Controller = {read=GetController};
	__property TcxGridCardViewPainter* Painter = {read=GetPainter};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxGridCardViewRow* Rows[int Index] = {read=GetRow, write=SetRow};
	__property TcxGridCardViewRowLayoutController* RowLayoutController = {read=FRowLayoutController};
	__property TcxGridCardViewViewData* ViewData = {read=GetViewData};
	__property TcxGridCardViewViewInfo* ViewInfo = {read=GetViewInfo};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	__property TcxGridCardViewRow* VisibleRows[int Index] = {read=GetVisibleRow};
	
__published:
	__property TcxGridCardViewBackgroundBitmaps* BackgroundBitmaps = {read=GetBackgroundBitmaps, write=SetBackgroundBitmaps};
	__property Cxgridcustomtableview::TcxGridDataController* DataController = {read=GetDataController, write=SetDataController};
	__property TcxGridCardViewDateTimeHandling* DateTimeHandling = {read=GetDateTimeHandling, write=SetDateTimeHandling};
	__property TcxGridCardViewFiltering* Filtering = {read=GetFiltering, write=SetFiltering};
	__property TcxGridCardViewLayoutDirection LayoutDirection = {read=FLayoutDirection, write=SetLayoutDirection, default=0};
	__property TcxGridCardViewOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxGridCardViewOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize, write=SetOptionsCustomize};
	__property TcxGridCardViewOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	__property TcxGridCardViewOptionsSelection* OptionsSelection = {read=GetOptionsSelection, write=SetOptionsSelection};
	__property TcxGridCardViewOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxGridCardViewRowLayout RowLayout = {read=FRowLayout, write=SetRowLayout, default=0};
	__property TcxGridCardViewStyles* Styles = {read=GetStyles, write=SetStyles};
	__property OnCustomization;
	__property TcxGridCardRowEvent OnRowCollapsed = {read=FOnRowCollapsed, write=SetOnRowCollapsed};
	__property TcxGridCardRowChangingEvent OnRowCollapsing = {read=FOnRowCollapsing, write=SetOnRowCollapsing};
	__property TcxGridCardRowEvent OnRowExpanded = {read=FOnRowExpanded, write=SetOnRowExpanded};
	__property TcxGridCardRowChangingEvent OnRowExpanding = {read=FOnRowExpanding, write=SetOnRowExpanding};
	__property TcxGridCardRowEvent OnRowPosChanged = {read=FOnRowPosChanged, write=SetOnRowPosChanged};
public:
	/* TcxCustomGridTableView.Destroy */ inline __fastcall virtual ~TcxGridCardView(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridCardView(Cxcontrols::TcxControl* AControl) : Cxgridcustomlayoutview::TcxGridCustomLayoutView(AControl) { }
	
public:
	/* TcxControlChildComponent.Create */ inline __fastcall virtual TcxGridCardView(System::Classes::TComponent* AOwner) : Cxgridcustomlayoutview::TcxGridCustomLayoutView(AOwner) { }
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridCardView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridcustomlayoutview::TcxGridCustomLayoutView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString cxGridCardViewAlternateCaptionSeparator;
static const System::Int8 cxGridDefaultCardBorderWidth = System::Int8(0x3);
static const System::Int8 cxGridCardDefaultCategoryIndent = System::Int8(0x11);
static const System::Int8 cxGridCardDefaultCategorySeparatorWidth = System::Int8(0x2);
static const System::Int8 cxGridCardDefaultLayerSeparatorWidth = System::Int8(0x0);
static const System::Byte cxGridCardDefaultWidth = System::Byte(0xc8);
static const System::Int8 cxGridCardBorderMinWidth = System::Int8(0x1);
static const System::Int8 cxGridCardMinWidth = System::Int8(0x28);
static const System::Byte htCardViewBase = System::Byte(0x96);
static const System::Byte htCardRowIndent = System::Byte(0x97);
static const System::Byte htCardRowExpandButton = System::Byte(0x98);
static const System::Byte htRowCaption = System::Byte(0x99);
static const System::Byte htRowFilterButton = System::Byte(0x9a);
static const System::Byte htCardScrollButtonUp = System::Byte(0x9b);
static const System::Byte htCardScrollButtonDown = System::Byte(0x9c);
static const System::Byte htSeparator = System::Byte(0x9d);
static const System::Int8 ckRows = System::Int8(0x2);
static const System::Int8 bbCardViewFirst = System::Int8(0x3);
static const System::Int8 bbCaptionRow = System::Int8(0x3);
static const System::Int8 bbCardBorder = System::Int8(0x4);
static const System::Int8 bbRowCaption = System::Int8(0x5);
static const System::Int8 bbCardViewLast = System::Int8(0x5);
static const System::Int8 isRowFirst = System::Int8(0x1);
static const System::Int8 isCaptionRow = System::Int8(0x1);
static const System::Int8 isCategoryRow = System::Int8(0x2);
static const System::Int8 isRowCaption = System::Int8(0x3);
static const System::Int8 isRowLast = System::Int8(0x3);
static const System::Int8 vsCardViewFirst = System::Int8(0xa);
static const System::Int8 vsCaptionRow = System::Int8(0xa);
static const System::Int8 vsCardBorder = System::Int8(0xb);
static const System::Int8 vsCategoryRow = System::Int8(0xc);
static const System::Int8 vsCategorySeparator = System::Int8(0xd);
static const System::Int8 vsLayerSeparator = System::Int8(0xe);
static const System::Int8 vsRowCaption = System::Int8(0xf);
static const System::Int8 vsCardViewLast = System::Int8(0xf);
}	/* namespace Cxgridcardview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDCARDVIEW)
using namespace Cxgridcardview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridcardviewHPP
