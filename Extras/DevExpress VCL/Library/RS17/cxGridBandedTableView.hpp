// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridBandedTableView.pas' rev: 24.00 (Win32)

#ifndef CxgridbandedtableviewHPP
#define CxgridbandedtableviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxGridRows.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridbandedtableview
{
//-- type declarations -------------------------------------------------------
enum TcxGridBandFixedKind : unsigned char { fkNone, fkLeft, fkRight };

class DELPHICLASS TcxGridColumnHeaderVertSizingEdgeHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridColumnHeaderVertSizingEdgeHitTest : public Cxgridtableview::TcxCustomGridColumnHitTest
{
	typedef Cxgridtableview::TcxCustomGridColumnHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderVertSizingEdgeHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridColumnHeaderVertSizingEdgeHitTest(void) : Cxgridtableview::TcxCustomGridColumnHitTest() { }
	
};

#pragma pack(pop)

enum TcxGridBandContainerKind : unsigned char { bcHeader, bcCustomizationForm };

class DELPHICLASS TcxGridBandHitTest;
class DELPHICLASS TcxGridBand;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
private:
	TcxGridBand* FBand;
	TcxGridBandContainerKind FBandContainerKind;
	int FVisibleRowIndex;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__property TcxGridBand* Band = {read=FBand, write=FBand};
	__property TcxGridBandContainerKind BandContainerKind = {read=FBandContainerKind, write=FBandContainerKind, nodefault};
	__property int VisibleRowIndex = {read=FVisibleRowIndex, write=FVisibleRowIndex, nodefault};
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridBandHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridBandHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandHeaderHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandHeaderHitTest : public TcxGridBandHitTest
{
	typedef TcxGridBandHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridBandHeaderHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridBandHeaderHitTest(void) : TcxGridBandHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandHeaderSizingEdgeHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandHeaderSizingEdgeHitTest : public TcxGridBandHitTest
{
	typedef TcxGridBandHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridBandHeaderSizingEdgeHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridBandHeaderSizingEdgeHitTest(void) : TcxGridBandHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridIndicatorBandHeaderHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridIndicatorBandHeaderHitTest : public Cxgridtableview::TcxGridIndicatorHitTest
{
	typedef Cxgridtableview::TcxGridIndicatorHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridIndicatorBandHeaderHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridIndicatorBandHeaderHitTest(void) : Cxgridtableview::TcxGridIndicatorHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedColumnContainerZone;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedColumnContainerZone : public Cxgridcustomtableview::TcxGridItemContainerZone
{
	typedef Cxgridcustomtableview::TcxGridItemContainerZone inherited;
	
public:
	TcxGridBand* Band;
	int ColIndex;
	int RowIndex;
	__fastcall TcxGridBandedColumnContainerZone(int AColumnIndex, TcxGridBand* ABand, int AColIndex, int ARowIndex);
	virtual bool __fastcall IsEqual(Cxgridcustomtableview::TcxGridItemContainerZone* Value);
	bool __fastcall IsInsertion(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandedColumnContainerZone(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedColumnHeaderMovingObject;
class DELPHICLASS TcxGridBandedColumn;
class DELPHICLASS TcxGridBandedColumnPosition;
class DELPHICLASS TcxGridBandedTableViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedColumnHeaderMovingObject : public Cxgridtableview::TcxGridColumnHeaderMovingObject
{
	typedef Cxgridtableview::TcxGridColumnHeaderMovingObject inherited;
	
private:
	TcxGridBandedColumnContainerZone* __fastcall GetDestZone(void);
	HIDESBASE TcxGridBandedColumn* __fastcall GetSourceItem(void);
	TcxGridBandedColumnPosition* __fastcall GetSourcePosition(void);
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE void __fastcall SetSourceItem(TcxGridBandedColumn* Value);
	
protected:
	virtual bool __fastcall AreArrowsVertical(void);
	virtual void __fastcall CheckDestItemContainerKind(int &AValue);
	virtual void __fastcall DoColumnMoving(void);
	virtual System::Types::TRect __fastcall GetArrowAreaBoundsForHeader(Cxcontrols::TcxArrowPlace APlace);
	virtual System::Types::TRect __fastcall GetArrowsClientRect(void);
	virtual bool __fastcall IsValidDestinationForVisibleSource(void);
	__property TcxGridBandedColumnContainerZone* DestZone = {read=GetDestZone};
	__property TcxGridBandedColumn* SourceItem = {read=GetSourceItem, write=SetSourceItem};
	__property TcxGridBandedColumnPosition* SourcePosition = {read=GetSourcePosition};
	__property TcxGridBandedTableViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridTableItemMovingObject.Create */ inline __fastcall virtual TcxGridBandedColumnHeaderMovingObject(Cxcontrols::TcxControl* AControl) : Cxgridtableview::TcxGridColumnHeaderMovingObject(AControl) { }
	/* TcxCustomGridTableItemMovingObject.Destroy */ inline __fastcall virtual ~TcxGridBandedColumnHeaderMovingObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandHeaderMovingObject;
class DELPHICLASS TcxGridBandedTableController;
class DELPHICLASS TcxGridBandedTableCustomizationForm;
class DELPHICLASS TcxGridBandedTableView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandHeaderMovingObject : public Cxgridcustomtableview::TcxCustomGridTableMovingObject
{
	typedef Cxgridcustomtableview::TcxCustomGridTableMovingObject inherited;
	
private:
	TcxGridBand* FDestBand;
	TcxGridBandContainerKind FDestBandContainerKind;
	Cxclasses::TcxPosition FDestInsertPosition;
	bool FIsEmptyViewInsert;
	TcxGridBandContainerKind FSourceBandContainerKind;
	HIDESBASE TcxGridBandedTableController* __fastcall GetController(void);
	HIDESBASE TcxGridBandedTableCustomizationForm* __fastcall GetCustomizationForm(void);
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	TcxGridBand* __fastcall GetSourceBand(void);
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetDestBand(TcxGridBand* Value);
	void __fastcall SetDestBandContainerKind(TcxGridBandContainerKind Value);
	void __fastcall SetDestInsertPosition(Cxclasses::TcxPosition Value);
	void __fastcall SetIsEmptyViewInsert(bool Value);
	void __fastcall SetSourceBand(TcxGridBand* Value);
	
protected:
	virtual bool __fastcall AreArrowsVertical(void);
	bool __fastcall CalculateIsEmptyViewInsert(bool ACheckMousePos);
	virtual bool __fastcall CanRemove(void);
	virtual void __fastcall CheckDestParams(void);
	virtual System::Types::TRect __fastcall GetArrowAreaBounds(Cxcontrols::TcxArrowPlace APlace);
	virtual System::Types::TRect __fastcall GetArrowsClientRect(void);
	virtual Cxgridcustomview::TcxCustomGridItemsListBox* __fastcall GetCustomizationFormListBox(void);
	virtual Cxgridcustomview::TcxCustomGridCellViewInfo* __fastcall GetSourceItemViewInfo(void);
	virtual bool __fastcall IsSourceCustomizationForm(void);
	virtual bool __fastcall IsValidDestination(void);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	__property TcxGridBandedTableController* Controller = {read=GetController};
	__property TcxGridBandedTableCustomizationForm* CustomizationForm = {read=GetCustomizationForm};
	__property TcxGridBand* DestBand = {read=FDestBand, write=SetDestBand};
	__property TcxGridBandContainerKind DestBandContainerKind = {read=FDestBandContainerKind, write=SetDestBandContainerKind, nodefault};
	__property Cxclasses::TcxPosition DestInsertPosition = {read=FDestInsertPosition, write=SetDestInsertPosition, nodefault};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property bool IsEmptyViewInsert = {read=FIsEmptyViewInsert, write=SetIsEmptyViewInsert, nodefault};
	__property TcxGridBand* SourceBand = {read=GetSourceBand, write=SetSourceBand};
	__property TcxGridBandContainerKind SourceBandContainerKind = {read=FSourceBandContainerKind, write=FSourceBandContainerKind, nodefault};
	__property TcxGridBandedTableViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Init(const System::Types::TPoint &P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxGridBandHeaderMovingObject(Cxcontrols::TcxControl* AControl) : Cxgridcustomtableview::TcxCustomGridTableMovingObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandHeaderMovingObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridColumnVertSizingObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridColumnVertSizingObject : public Cxgridtableview::TcxCustomGridColumnSizingObject
{
	typedef Cxgridtableview::TcxCustomGridColumnSizingObject inherited;
	
private:
	TcxGridBandedColumn* __fastcall GetColumn(void);
	HIDESBASE TcxGridBandedTableController* __fastcall GetController(void);
	int __fastcall GetLineHeight(void);
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual int __fastcall GetCurrentSize(void);
	virtual bool __fastcall GetIsHorizontalSizing(void);
	__property TcxGridBandedColumn* Column = {read=GetColumn};
	__property TcxGridBandedTableController* Controller = {read=GetController};
	__property int LineHeight = {read=GetLineHeight, nodefault};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxGridColumnVertSizingObject(Cxcontrols::TcxControl* AControl) : Cxgridtableview::TcxCustomGridColumnSizingObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnVertSizingObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandSizingObject;
class DELPHICLASS TcxGridBandViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandSizingObject : public Cxgridtableview::TcxCustomGridSizingObject
{
	typedef Cxgridtableview::TcxCustomGridSizingObject inherited;
	
private:
	TcxGridBand* FBand;
	TcxGridBandViewInfo* __fastcall GetBandViewInfo(void);
	HIDESBASE TcxGridBandedTableController* __fastcall GetController(void);
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual int __fastcall GetCurrentSize(void);
	virtual System::Types::TRect __fastcall GetSizingItemBounds(void);
	virtual int __fastcall GetSizingMarkWidth(void);
	__property TcxGridBand* Band = {read=FBand, write=FBand};
	__property TcxGridBandViewInfo* BandViewInfo = {read=GetBandViewInfo};
	__property TcxGridBandedTableController* Controller = {read=GetController};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	
public:
	virtual void __fastcall Init(const System::Types::TPoint &P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxGridBandSizingObject(Cxcontrols::TcxControl* AControl) : Cxgridtableview::TcxCustomGridSizingObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandSizingObject(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridBandedTableBandsListBoxClass;

class DELPHICLASS TcxGridBandedTableBandsListBox;
class PASCALIMPLEMENTATION TcxGridBandedTableBandsListBox : public Cxgridtableview::TcxGridTableItemsListBox
{
	typedef Cxgridtableview::TcxGridTableItemsListBox inherited;
	
private:
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall DoRefreshItems(void);
	virtual bool __fastcall DrawItemDrawBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetDragAndDropParams(void);
	virtual bool __fastcall GetItemEndEllipsis(void);
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
public:
	/* TcxGridTableItemsListBox.Create */ inline __fastcall virtual TcxGridBandedTableBandsListBox(System::Classes::TComponent* AOwner) : Cxgridtableview::TcxGridTableItemsListBox(AOwner) { }
	
public:
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TcxGridBandedTableBandsListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridBandedTableBandsListBox(HWND ParentWindow) : Cxgridtableview::TcxGridTableItemsListBox(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxGridBandedTableCustomizationForm : public Cxgridtableview::TcxGridTableCustomizationForm
{
	typedef Cxgridtableview::TcxGridTableCustomizationForm inherited;
	
private:
	TcxGridBandedTableBandsListBox* FBandsListBox;
	Cxpc::TcxTabSheet* FBandsPage;
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall InitPageControl(void);
	virtual TcxGridBandedTableBandsListBoxClass __fastcall GetBandsListBoxClass(void);
	__property TcxGridBandedTableBandsListBox* BandsListBox = {read=FBandsListBox};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	
public:
	virtual void __fastcall RefreshData(void);
	__property Cxpc::TcxTabSheet* BandsPage = {read=FBandsPage};
public:
	/* TcxCustomGridCustomizationForm.Create */ inline __fastcall virtual TcxGridBandedTableCustomizationForm(Cxgridcustomview::TcxCustomGridController* AController) : Cxgridtableview::TcxGridTableCustomizationForm(AController) { }
	/* TcxCustomGridCustomizationForm.Destroy */ inline __fastcall virtual ~TcxGridBandedTableCustomizationForm(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridBandedTableCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Cxgridtableview::TcxGridTableCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridBandedTableCustomizationForm(HWND ParentWindow) : Cxgridtableview::TcxGridTableCustomizationForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridBandsCustomizationPopupClass;

class DELPHICLASS TcxGridBandsCustomizationPopup;
class PASCALIMPLEMENTATION TcxGridBandsCustomizationPopup : public Cxgridcustomtableview::TcxCustomGridCustomizationPopup
{
	typedef Cxgridcustomtableview::TcxCustomGridCustomizationPopup inherited;
	
private:
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall AddCheckListBoxItems(void);
	virtual int __fastcall GetDropDownCount(void);
	virtual bool __fastcall SupportsItemMoving(void);
	virtual void __fastcall ItemClicked(System::TObject* AItem, bool AChecked);
	virtual int __fastcall GetItemIndex(System::TObject* AItem);
	virtual void __fastcall SetItemIndex(System::TObject* AItem, int AIndex);
	
public:
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridCustomizationPopup.Create */ inline __fastcall virtual TcxGridBandsCustomizationPopup(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridCustomizationPopup(AGridView) { }
	
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxGridBandsCustomizationPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridBandsCustomizationPopup(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomtableview::TcxCustomGridCustomizationPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridBandsCustomizationPopup(HWND ParentWindow) : Cxgridcustomtableview::TcxCustomGridCustomizationPopup(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxGridBandedTableController : public Cxgridtableview::TcxGridTableController
{
	typedef Cxgridtableview::TcxGridTableController inherited;
	
private:
	TcxGridBandsCustomizationPopup* FBandsCustomizationPopup;
	TcxGridBand* FForcingWidthBand;
	TcxGridBand* FMovingBand;
	TcxGridBand* FPressedBand;
	TcxGridBand* FSizingBand;
	TcxGridBandedColumn* FVertSizingColumn;
	TcxGridBandsCustomizationPopup* __fastcall GetBandsCustomizationPopup(void);
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	bool __fastcall GetIsBandMoving(void);
	bool __fastcall GetIsBandSizing(void);
	bool __fastcall GetIsColumnVertSizing(void);
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetPressedBand(TcxGridBand* Value);
	
protected:
	virtual TcxGridBandsCustomizationPopupClass __fastcall GetBandsCustomizationPopupClass(void);
	virtual Cxgridtableview::TcxGridColumnHeaderMovingObjectClass __fastcall GetColumnHeaderDragAndDropObjectClass(void);
	virtual void __fastcall GetColumnNeighbors(TcxGridBandedColumn* AColumn, bool AGoForward, System::Classes::TList* AList);
	virtual Cxgridcustomview::TcxCustomGridCustomizationFormClass __fastcall GetCustomizationFormClass(void);
	virtual bool __fastcall GetDesignHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual System::Classes::TPersistent* __fastcall GetPatternObject(System::Classes::TPersistent* AObject);
	virtual bool __fastcall IsBandFixedDuringSizing(TcxGridBand* ABand);
	virtual bool __fastcall IsColumnFixedDuringHorzSizing(Cxgridtableview::TcxGridColumn* AColumn);
	virtual void __fastcall LeftPosChanged(void);
	virtual void __fastcall CreateGridViewItem(System::TObject* Sender);
	virtual void __fastcall CreateChildBandForSelection(System::TObject* Sender);
	virtual void __fastcall CreateParentBandForSelection(System::TObject* Sender);
	virtual void __fastcall DeleteGridViewItem(System::Classes::TPersistent* AItem);
	virtual void __fastcall PopulateColumnHeaderDesignPopupMenu(Vcl::Menus::TPopupMenu* AMenu);
	virtual bool __fastcall GetCellMultiSelect(void);
	__property TcxGridBand* ForcingWidthBand = {read=FForcingWidthBand, write=FForcingWidthBand};
	__property TcxGridBandedTableViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual ~TcxGridBandedTableController(void);
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	bool __fastcall HasBandsCustomizationPopup(void);
	virtual int __fastcall FindNextColumnVertically(int AFocusedItemIndex, bool AGoForward, bool AGoOnCycle);
	virtual int __fastcall FindNextItem(int AFocusedItemIndex, bool AGoForward, bool AGoOnCycle, bool AFollowVisualOrder, /* out */ bool &ACycleChanged, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	bool __fastcall FocusNextColumnVertically(int AFocusedColumnIndex, bool AGoForward, bool AGoOnCycle);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__property TcxGridBandsCustomizationPopup* BandsCustomizationPopup = {read=GetBandsCustomizationPopup};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property bool IsBandMoving = {read=GetIsBandMoving, nodefault};
	__property bool IsBandSizing = {read=GetIsBandSizing, nodefault};
	__property bool IsColumnVertSizing = {read=GetIsColumnVertSizing, nodefault};
	__property TcxGridBand* MovingBand = {read=FMovingBand};
	__property TcxGridBand* PressedBand = {read=FPressedBand, write=SetPressedBand};
	__property TcxGridBand* SizingBand = {read=FSizingBand};
	__property TcxGridBandedColumn* VertSizingColumn = {read=FVertSizingColumn};
public:
	/* TcxGridTableController.Create */ inline __fastcall virtual TcxGridBandedTableController(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridtableview::TcxGridTableController(AGridView) { }
	
};


class DELPHICLASS TcxGridBandHeaderPainter;
class DELPHICLASS TcxGridBandHeaderViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandHeaderPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridBandHeaderViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBorders(void);
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawPressed(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	virtual void __fastcall Paint(void);
	__property TcxGridBandHeaderViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridBandHeaderPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandHeaderPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridBandViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoExcludeFromClipRect(void);
	virtual void __fastcall DrawChildBands(void);
	virtual void __fastcall DrawColumnHeaders(void);
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawHeader(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxGridBandViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridBandPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedHeaderPainter;
class DELPHICLASS TcxGridBandedHeaderViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedHeaderPainter : public Cxgridtableview::TcxGridHeaderPainter
{
	typedef Cxgridtableview::TcxGridHeaderPainter inherited;
	
private:
	HIDESBASE TcxGridBandedHeaderViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBands(void);
	virtual void __fastcall DrawItems(void);
	__property TcxGridBandedHeaderViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridBandedHeaderPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridtableview::TcxGridHeaderPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandedHeaderPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedFooterPainter;
class DELPHICLASS TcxGridBandsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedFooterPainter : public Cxgridtableview::TcxGridFooterPainter
{
	typedef Cxgridtableview::TcxGridFooterPainter inherited;
	
private:
	TcxGridBandsViewInfo* __fastcall GetBandsViewInfo(void);
	
protected:
	virtual void __fastcall DrawItems(void);
	__property TcxGridBandsViewInfo* BandsViewInfo = {read=GetBandsViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridBandedFooterPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridtableview::TcxGridFooterPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandedFooterPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridIndicatorBandHeaderItemPainter;
class DELPHICLASS TcxGridIndicatorBandHeaderItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridIndicatorBandHeaderItemPainter : public Cxgridtableview::TcxGridIndicatorHeaderItemPainter
{
	typedef Cxgridtableview::TcxGridIndicatorHeaderItemPainter inherited;
	
private:
	HIDESBASE TcxGridIndicatorBandHeaderItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall DrawBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	__property TcxGridIndicatorBandHeaderItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridIndicatorBandHeaderItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridtableview::TcxGridIndicatorHeaderItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridIndicatorBandHeaderItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedDataRowCellsAreaItemPainter;
class DELPHICLASS TcxGridBandedDataRowCellsAreaItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedDataRowCellsAreaItemPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridBandedDataRowCellsAreaItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawFixedBandsSeparator(void);
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawLines(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	virtual void __fastcall Paint(void);
	__property TcxGridBandedDataRowCellsAreaItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridBandedDataRowCellsAreaItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandedDataRowCellsAreaItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedRowsPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedRowsPainter : public Cxgridtableview::TcxGridRowsPainter
{
	typedef Cxgridtableview::TcxGridRowsPainter inherited;
	
public:
	__classmethod virtual void __fastcall DrawDataRowCells(Cxgridtableview::TcxCustomGridRowViewInfo* ARowViewInfo);
public:
	/* TcxCustomGridRecordsPainter.Create */ inline __fastcall virtual TcxGridBandedRowsPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* AViewInfo) : Cxgridtableview::TcxGridRowsPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandedRowsPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedTablePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTablePainter : public Cxgridtableview::TcxGridTablePainter
{
	typedef Cxgridtableview::TcxGridTablePainter inherited;
	
private:
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall CanOffset(int AItemsOffset, int DX, int DY);
	
public:
	__property TcxGridBandedTableViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxGridBandedTablePainter(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridtableview::TcxGridTablePainter(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridBandedTablePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedColumnHeaderVertSizingEdgeViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedColumnHeaderVertSizingEdgeViewInfo : public Cxgridtableview::TcxGridColumnHeaderAreaViewInfo
{
	typedef Cxgridtableview::TcxGridColumnHeaderAreaViewInfo inherited;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall OccupiesSpace(void);
	virtual bool __fastcall ResidesInContent(void);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds, System::Types::TRect &ATextAreaBounds);
public:
	/* TcxGridColumnHeaderAreaViewInfo.Create */ inline __fastcall virtual TcxGridBandedColumnHeaderVertSizingEdgeViewInfo(Cxgridtableview::TcxGridColumnHeaderViewInfo* AColumnHeaderViewInfo) : Cxgridtableview::TcxGridColumnHeaderAreaViewInfo(AColumnHeaderViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridBandedColumnHeaderVertSizingEdgeViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedColumnHeaderViewInfo;
class DELPHICLASS TcxGridBandRowViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedColumnHeaderViewInfo : public Cxgridtableview::TcxGridColumnHeaderViewInfo
{
	typedef Cxgridtableview::TcxGridColumnHeaderViewInfo inherited;
	
private:
	TcxGridBandViewInfo* __fastcall GetBandViewInfo(void);
	TcxGridBandedColumn* __fastcall GetColumn(void);
	TcxGridBandedHeaderViewInfo* __fastcall GetContainer(void);
	TcxGridBandRowViewInfo* __fastcall GetRowViewInfo(void);
	
protected:
	virtual bool __fastcall CanVertSize(void);
	virtual void __fastcall GetAreaViewInfoClasses(Cxgridcommon::TcxGridClassEnumeratorProc AProc);
	virtual int __fastcall GetMaxWidth(void);
	__property TcxGridBandViewInfo* BandViewInfo = {read=GetBandViewInfo};
	__property TcxGridBandedHeaderViewInfo* Container = {read=GetContainer};
	__property TcxGridBandRowViewInfo* RowViewInfo = {read=GetRowViewInfo};
	
public:
	__property TcxGridBandedColumn* Column = {read=GetColumn};
public:
	/* TcxGridColumnHeaderViewInfo.Create */ inline __fastcall virtual TcxGridBandedColumnHeaderViewInfo(Cxgridtableview::TcxGridColumnContainerViewInfo* AContainer, Cxgridtableview::TcxGridColumn* AColumn) : Cxgridtableview::TcxGridColumnHeaderViewInfo(AContainer, AColumn) { }
	/* TcxGridColumnHeaderViewInfo.Destroy */ inline __fastcall virtual ~TcxGridBandedColumnHeaderViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridBandHeaderViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandHeaderViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridBandViewInfo* FBandViewInfo;
	TcxGridBand* __fastcall GetBand(void);
	int __fastcall GetVerticalBorderOverlapSize(void);
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	TcxGridBandedTableViewInfo* __fastcall GetGridViewInfo(void);
	int __fastcall GetRowCount(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanShowHint(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual System::Types::TRect __fastcall GetAreaBounds(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	__classmethod virtual int __fastcall GetCellHeight(int ATextHeight, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	virtual int __fastcall GetHeight(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual bool __fastcall GetIsPressed(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetShowEndEllipsis(void);
	virtual System::Types::TRect __fastcall GetSizingEdgeBounds(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasCustomDraw(void);
	virtual bool __fastcall HasDesignPopupMenu(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall PopulateDesignPopupMenu(Vcl::Menus::TPopupMenu* AMenu);
	__property System::Types::TRect SizingEdgeBounds = {read=GetSizingEdgeBounds};
	
public:
	__fastcall virtual TcxGridBandHeaderViewInfo(TcxGridBandViewInfo* ABandViewInfo);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxGridBand* Band = {read=GetBand};
	__property TcxGridBandViewInfo* BandViewInfo = {read=FBandViewInfo};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property TcxGridBandedTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property bool IsPressed = {read=GetIsPressed, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridBandHeaderViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridBandRowViewInfoClass;

class DELPHICLASS TcxGridBandRowsViewInfo;
class DELPHICLASS TcxGridBandRow;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandRowViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridBandedColumnHeaderViewInfo* operator[](int Index) { return ColumnViewInfos[Index]; }
	
private:
	System::Classes::TList* FColumnViewInfos;
	int FHeight;
	int FIndex;
	TcxGridBandRowsViewInfo* FRowsViewInfo;
	TcxGridBandRow* __fastcall GetBandRow(void);
	TcxGridBandViewInfo* __fastcall GetBandViewInfo(void);
	TcxGridBandedColumnHeaderViewInfo* __fastcall GetColumnViewInfo(int Index);
	int __fastcall GetColumnViewInfoCount(void);
	TcxGridBandedTableView* __fastcall GetGridView(void);
	int __fastcall GetHeight(void);
	int __fastcall GetLineHeight(void);
	int __fastcall GetMinWidth(void);
	int __fastcall GetWidth(void);
	
protected:
	virtual void __fastcall AddColumnViewInfos(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateColumnWidths(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateLineHeight(void);
	virtual int __fastcall CalculateWidth(void);
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property int LineHeight = {read=GetLineHeight, nodefault};
	
public:
	System::Types::TRect Bounds;
	__fastcall virtual TcxGridBandRowViewInfo(TcxGridBandRowsViewInfo* ARowsViewInfo, int AIndex);
	__fastcall virtual ~TcxGridBandRowViewInfo(void);
	void __fastcall AssignColumnWidths(void);
	virtual void __fastcall Offset(int DX, int DY);
	__property TcxGridBandRow* BandRow = {read=GetBandRow};
	__property TcxGridBandViewInfo* BandViewInfo = {read=GetBandViewInfo};
	__property int ColumnViewInfoCount = {read=GetColumnViewInfoCount, nodefault};
	__property TcxGridBandedColumnHeaderViewInfo* ColumnViewInfos[int Index] = {read=GetColumnViewInfo/*, default*/};
	__property int Index = {read=FIndex, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property TcxGridBandRowsViewInfo* RowsViewInfo = {read=FRowsViewInfo};
	__property int Height = {read=GetHeight, nodefault};
	__property int Width = {read=GetWidth, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridBandRowsViewInfoClass;

class DELPHICLASS TcxGridBandRows;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandRowsViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridBandRowViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridBandViewInfo* FBandViewInfo;
	System::Classes::TList* FItems;
	int FWidth;
	TcxGridBandRows* __fastcall GetBandRows(void);
	int __fastcall GetCount(void);
	TcxGridBandRowViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetMinWidth(void);
	int __fastcall GetWidth(void);
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	
protected:
	void __fastcall AssignColumnWidths(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateColumnWidths(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TcxGridBandRowViewInfoClass __fastcall GetBandRowViewInfoClass(void);
	
public:
	System::Types::TRect Bounds;
	__fastcall virtual TcxGridBandRowsViewInfo(TcxGridBandViewInfo* ABandViewInfo);
	__fastcall virtual ~TcxGridBandRowsViewInfo(void);
	int __fastcall IndexAtPos(const System::Types::TPoint &P);
	virtual void __fastcall Offset(int DX, int DY);
	__property TcxGridBandRows* BandRows = {read=GetBandRows};
	__property TcxGridBandViewInfo* BandViewInfo = {read=FBandViewInfo};
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridBandRowViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property int Width = {read=GetWidth, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridBandViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandViewInfo : public Cxgridcustomview::TcxCustomGridCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridCellViewInfo inherited;
	
public:
	TcxGridBandedColumnHeaderViewInfo* operator[](int Index) { return ColumnViewInfos[Index]; }
	
private:
	TcxGridBandsViewInfo* FBandsViewInfo;
	int FBottomIndex;
	System::Classes::TList* FColumnViewInfos;
	System::Types::TRect FExcludeBounds;
	TcxGridBandHeaderViewInfo* FHeaderViewInfo;
	int FIndex;
	TcxGridBandRowsViewInfo* FRowsViewInfo;
	int FWidth;
	TcxGridBand* __fastcall GetBand(void);
	int __fastcall GetBorderOverlapSize(void);
	System::Types::TRect __fastcall GetBoundsForBandInsert(void);
	int __fastcall GetChildBandsHorizontalBorderOverlapSize(void);
	TcxGridBandViewInfo* __fastcall GetChildBandViewInfo(int Index);
	int __fastcall GetChildBandViewInfoCount(void);
	TcxGridBandedColumnHeaderViewInfo* __fastcall GetColumnViewInfo(int Index);
	int __fastcall GetColumnViewInfoCount(void);
	TcxGridBandedHeaderViewInfo* __fastcall GetContainerViewInfo(void);
	TcxGridBandFixedKind __fastcall GetFixedKind(void);
	TcxGridBandedTableView* __fastcall GetGridView(void);
	TcxGridBandedTableViewInfo* __fastcall GetGridViewInfo(void);
	bool __fastcall GetIsBottom(void);
	bool __fastcall GetIsFixed(void);
	bool __fastcall GetIsRight(void);
	bool __fastcall GetIsRoot(void);
	TcxGridBandViewInfo* __fastcall GetParentBandViewInfo(void);
	int __fastcall GetRowCount(void);
	int __fastcall GetSameLevelAutoWidth(void);
	TcxGridBandViewInfo* __fastcall GetSameLevelItem(int Index);
	int __fastcall GetSameLevelItemCount(void);
	
protected:
	virtual void __fastcall AddColumnViewInfos(void);
	void __fastcall AssignChildBandWidths(void);
	void __fastcall AssignColumnWidths(void);
	virtual void __fastcall CalculateChildBandWidths(void);
	virtual void __fastcall CalculateChildBands(const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall CalculateChildBandsBounds(void);
	virtual System::Types::TRect __fastcall CalculateColumnsBounds(void);
	virtual void __fastcall CalculateColumnWidths(void);
	virtual System::Types::TRect __fastcall CalculateHeaderBounds(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanSize(void);
	virtual void __fastcall CheckWidth(int &Value);
	virtual bool __fastcall CustomDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetAreAllColumnsFixed(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual int __fastcall GetContentWidth(void);
	__classmethod virtual TcxGridBandHeaderViewInfoClass __fastcall GetHeaderViewInfoClass();
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual int __fastcall GetMaxContentWidth(void);
	virtual int __fastcall GetMaxWidth(void);
	virtual int __fastcall GetMinContentWidth(void);
	virtual int __fastcall GetMinWidth(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridBandRowsViewInfoClass __fastcall GetRowsViewInfoClass(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall SetWidth(int Value);
	__property int BorderOverlapSize = {read=GetBorderOverlapSize, nodefault};
	__property System::Types::TRect BoundsForBandInsert = {read=GetBoundsForBandInsert};
	__property System::Types::TRect ExcludeBounds = {read=FExcludeBounds};
	
public:
	__fastcall virtual TcxGridBandViewInfo(TcxGridBandsViewInfo* ABandsViewInfo, int AIndex);
	__fastcall virtual ~TcxGridBandViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AAutoWidthItem);
	bool __fastcall InsertPositionAtPos(const System::Types::TPoint &P, /* out */ TcxGridBand* &ABand, /* out */ Cxclasses::TcxPosition &AInsertPosition);
	__property bool AreAllColumnsFixed = {read=GetAreAllColumnsFixed, nodefault};
	__property TcxGridBand* Band = {read=GetBand};
	__property TcxGridBandsViewInfo* BandsViewInfo = {read=FBandsViewInfo};
	__property int BottomIndex = {read=FBottomIndex, nodefault};
	__property int ChildBandViewInfoCount = {read=GetChildBandViewInfoCount, nodefault};
	__property TcxGridBandViewInfo* ChildBandViewInfos[int Index] = {read=GetChildBandViewInfo};
	__property int ColumnViewInfoCount = {read=GetColumnViewInfoCount, nodefault};
	__property TcxGridBandedColumnHeaderViewInfo* ColumnViewInfos[int Index] = {read=GetColumnViewInfo/*, default*/};
	__property TcxGridBandedHeaderViewInfo* ContainerViewInfo = {read=GetContainerViewInfo};
	__property TcxGridBandFixedKind FixedKind = {read=GetFixedKind, nodefault};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property TcxGridBandedTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridBandHeaderViewInfo* HeaderViewInfo = {read=FHeaderViewInfo};
	__property int Index = {read=FIndex, nodefault};
	__property bool IsBottom = {read=GetIsBottom, nodefault};
	__property bool IsFixed = {read=GetIsFixed, nodefault};
	__property bool IsRight = {read=GetIsRight, nodefault};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property int MaxContentWidth = {read=GetMaxContentWidth, nodefault};
	__property int MaxWidth = {read=GetMaxWidth, nodefault};
	__property int MinContentWidth = {read=GetMinContentWidth, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property TcxGridBandViewInfo* ParentBandViewInfo = {read=GetParentBandViewInfo};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxGridBandRowsViewInfo* RowsViewInfo = {read=FRowsViewInfo};
	__property int SameLevelItemCount = {read=GetSameLevelItemCount, nodefault};
	__property TcxGridBandViewInfo* SameLevelItems[int Index] = {read=GetSameLevelItem};
	__property int SameLevelAutoWidth = {read=GetSameLevelAutoWidth, nodefault};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ALeftBound, ATopBound, AWidth, AHeight); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridBandsViewInfoClass;

class DELPHICLASS TcxGridBands;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandsViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridBandViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridBandedHeaderViewInfo* FContainerViewInfo;
	System::Classes::TList* FBandHeaderRowHeights;
	int FBandHeadersAreaHeight;
	System::Classes::TList* FItems;
	int FLineCount;
	int FRowCount;
	int __fastcall GetBandHeaderRowCount(void);
	int __fastcall GetBandHeaderRowHeight(int Index);
	int __fastcall GetBandHeadersAreaHeight(void);
	int __fastcall GetBandHeadersVerticalBorderOverlapSize(void);
	TcxGridBands* __fastcall GetBands(void);
	int __fastcall GetBorderOverlapSize(void);
	TcxGridBandViewInfo* __fastcall GetBottomItem(int Index);
	int __fastcall GetBottomItemCount(void);
	int __fastcall GetColumnHeadersAreaHeight(void);
	int __fastcall GetCount(void);
	TcxGridBandedTableView* __fastcall GetGridView(void);
	TcxGridBandedTableViewInfo* __fastcall GetGridViewInfo(void);
	TcxGridBandViewInfo* __fastcall GetInternalItem(int Index);
	TcxGridBandViewInfo* __fastcall GetItem(int Index);
	TcxGridBandViewInfo* __fastcall GetLastFixedItem(TcxGridBandFixedKind AFixedKind, int ALevelIndex);
	int __fastcall GetLineCount(void);
	TcxGridBandViewInfo* __fastcall GetRootItem(int Index);
	int __fastcall GetRootItemCount(void);
	int __fastcall GetRootItemsHorizontalBorderOverlapSize(void);
	int __fastcall GetRowCount(void);
	void __fastcall SetBandHeaderRowHeight(int Index, int Value);
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	
protected:
	virtual bool __fastcall AddIndicatorItems(Cxgridtableview::TcxGridIndicatorViewInfo* AIndicatorViewInfo, int ATopBound);
	virtual void __fastcall Calculate(void);
	virtual int __fastcall CalculateBandHeaderHeight(TcxGridBandHeaderViewInfo* ABandHeaderViewInfo);
	virtual void __fastcall CalculateBandHeaderRowHeights(void);
	virtual int __fastcall CalculateBandHeadersAreaHeight(void);
	virtual void __fastcall CalculateColumnWidths(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall DrawBandHeaderBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBandBackgroundBitmap(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBandHeaderBackgroundBitmap(void);
	virtual TcxGridBandViewInfoClass __fastcall GetItemClass(void);
	System::Types::TRect __fastcall GetRootItemsAreaBounds(void);
	virtual bool __fastcall IsBandHeaderHeightAssigned(void);
	virtual bool __fastcall ShowBandHeaders(void);
	virtual bool __fastcall ShowColumnHeaders(void);
	__property int BandHeadersAreaHeight = {read=GetBandHeadersAreaHeight, nodefault};
	__property int BorderOverlapSize = {read=GetBorderOverlapSize, nodefault};
	__property int ColumnHeadersAreaHeight = {read=GetColumnHeadersAreaHeight, nodefault};
	__property TcxGridBandedTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridBandViewInfo* InternalItems[int Index] = {read=GetInternalItem};
	
public:
	__fastcall virtual TcxGridBandsViewInfo(TcxGridBandedHeaderViewInfo* AContainerViewInfo);
	__fastcall virtual ~TcxGridBandsViewInfo(void);
	void __fastcall AssignRootItemWidths(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual System::Types::TRect __fastcall GetItemAreaBounds(TcxGridBand* ABand);
	void __fastcall InsertPositionAtPos(const System::Types::TPoint &P, /* out */ TcxGridBand* &ABand, /* out */ Cxclasses::TcxPosition &AInsertPosition);
	virtual void __fastcall Offset(int DX, int DY);
	__property Vcl::Graphics::TBitmap* BandBackgroundBitmap = {read=GetBandBackgroundBitmap};
	__property Vcl::Graphics::TBitmap* BandHeaderBackgroundBitmap = {read=GetBandHeaderBackgroundBitmap};
	__property int BandHeaderRowCount = {read=GetBandHeaderRowCount, nodefault};
	__property int BandHeaderRowHeights[int Index] = {read=GetBandHeaderRowHeight, write=SetBandHeaderRowHeight};
	__property TcxGridBands* Bands = {read=GetBands};
	__property int BottomItemCount = {read=GetBottomItemCount, nodefault};
	__property TcxGridBandViewInfo* BottomItems[int Index] = {read=GetBottomItem};
	__property TcxGridBandedHeaderViewInfo* ContainerViewInfo = {read=FContainerViewInfo};
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property TcxGridBandViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxGridBandViewInfo* LastFixedItems[TcxGridBandFixedKind AFixedKind][int ALevelIndex] = {read=GetLastFixedItem};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int RootItemCount = {read=GetRootItemCount, nodefault};
	__property TcxGridBandViewInfo* RootItems[int Index] = {read=GetRootItem};
	__property int RowCount = {read=GetRowCount, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedHeaderViewInfoSpecific;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedHeaderViewInfoSpecific : public Cxgridtableview::TcxGridHeaderViewInfoSpecific
{
	typedef Cxgridtableview::TcxGridHeaderViewInfoSpecific inherited;
	
private:
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetGridViewInfo(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	
public:
	__property TcxGridBandedTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
public:
	/* TcxGridHeaderViewInfoSpecific.Create */ inline __fastcall virtual TcxGridBandedHeaderViewInfoSpecific(Cxgridtableview::TcxGridHeaderViewInfo* AContainerViewInfo) : Cxgridtableview::TcxGridHeaderViewInfoSpecific(AContainerViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBandedHeaderViewInfoSpecific(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedHeaderViewInfo : public Cxgridtableview::TcxGridHeaderViewInfo
{
	typedef Cxgridtableview::TcxGridHeaderViewInfo inherited;
	
public:
	TcxGridBandedColumnHeaderViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridBandsViewInfo* FBandsViewInfo;
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetGridViewInfo(void);
	HIDESBASE TcxGridBandedColumnHeaderViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetLineCount(void);
	int __fastcall GetRowCount(void);
	TcxGridBandedHeaderViewInfoSpecific* __fastcall GetSpecific(void);
	
protected:
	virtual void __fastcall AddIndicatorItems(Cxgridtableview::TcxGridIndicatorViewInfo* AIndicatorViewInfo, int ATopBound);
	virtual void __fastcall CalculateColumnAutoWidths(void);
	virtual void __fastcall CalculateColumnWidths(void);
	virtual int __fastcall CalculateHeight(void);
	virtual void __fastcall CalculateItems(void);
	virtual TcxGridBandsViewInfoClass __fastcall GetBandsViewInfoClass(void);
	virtual Cxlookandfeelpainters::TcxNeighbors __fastcall GetColumnNeighbors(Cxgridtableview::TcxGridColumn* AColumn);
	virtual int __fastcall GetColumnAdditionalWidth(Cxgridtableview::TcxGridColumn* AColumn);
	virtual int __fastcall GetColumnWidth(Cxgridtableview::TcxGridColumn* AColumn);
	virtual bool __fastcall GetIsScrollable(void);
	virtual System::Types::TRect __fastcall GetItemAreaBounds(Cxgridtableview::TcxGridColumnHeaderViewInfo* AItem);
	virtual Cxgridtableview::TcxGridColumnHeaderViewInfoClass __fastcall GetItemClass(void);
	virtual bool __fastcall GetItemMultiLinePainting(Cxgridtableview::TcxGridColumnHeaderViewInfo* AItem);
	virtual System::Types::TRect __fastcall GetItemsAreaBounds(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetItemsHitTest(const System::Types::TPoint &P);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall IsHeightAssigned(void);
	virtual void __fastcall Offset(int DX, int DY);
	
public:
	__fastcall virtual TcxGridBandedHeaderViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxGridBandedHeaderViewInfo(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual Cxgridcustomtableview::TcxGridItemContainerZone* __fastcall GetZone(const System::Types::TPoint &P);
	__property TcxGridBandsViewInfo* BandsViewInfo = {read=FBandsViewInfo};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property TcxGridBandedTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridBandedColumnHeaderViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxGridBandedHeaderViewInfoSpecific* Specific = {read=GetSpecific};
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedFooterViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedFooterViewInfo : public Cxgridtableview::TcxGridFooterViewInfo
{
	typedef Cxgridtableview::TcxGridFooterViewInfo inherited;
	
protected:
	virtual bool __fastcall GetItemMultiLinePainting(Cxgridtableview::TcxGridColumnHeaderViewInfo* AItem);
	virtual bool __fastcall IsColumnOnFirstLayer(int AColumnIndex);
	virtual bool __fastcall IsMultilayerLayout(void);
	virtual void __fastcall PrepareSummaryItems(System::Classes::TList* ASummaryItems);
public:
	/* TcxGridHeaderViewInfo.Create */ inline __fastcall virtual TcxGridBandedFooterViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo) : Cxgridtableview::TcxGridFooterViewInfo(AGridViewInfo) { }
	/* TcxGridHeaderViewInfo.Destroy */ inline __fastcall virtual ~TcxGridBandedFooterViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridIndicatorBandHeaderItemViewInfo : public Cxgridtableview::TcxGridIndicatorHeaderItemViewInfo
{
	typedef Cxgridtableview::TcxGridIndicatorHeaderItemViewInfo inherited;
	
private:
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall SupportsQuickCustomization(void);
	virtual bool __fastcall DropDownWindowExists(void);
	virtual Cxgridcustomview::TcxCustomGridPopup* __fastcall GetDropDownWindow(void);
	
public:
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridIndicatorItemViewInfo.Create */ inline __fastcall virtual TcxGridIndicatorBandHeaderItemViewInfo(Cxgridtableview::TcxGridIndicatorViewInfo* AContainer) : Cxgridtableview::TcxGridIndicatorHeaderItemViewInfo(AContainer) { }
	/* TcxCustomGridIndicatorItemViewInfo.Destroy */ inline __fastcall virtual ~TcxGridIndicatorBandHeaderItemViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedIndicatorViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedIndicatorViewInfo : public Cxgridtableview::TcxGridIndicatorViewInfo
{
	typedef Cxgridtableview::TcxGridIndicatorViewInfo inherited;
	
protected:
	virtual bool __fastcall GetAlwaysVisible(void);
public:
	/* TcxGridIndicatorViewInfo.Create */ inline __fastcall virtual TcxGridBandedIndicatorViewInfo(Cxgridtableview::TcxGridTableViewInfo* AGridViewInfo) : Cxgridtableview::TcxGridIndicatorViewInfo(AGridViewInfo) { }
	/* TcxGridIndicatorViewInfo.Destroy */ inline __fastcall virtual ~TcxGridBandedIndicatorViewInfo(void) { }
	
};

#pragma pack(pop)

enum TcxGridFixedBandsSeparatorLocation : unsigned char { slNone, slLeft, slRight };

typedef System::TMetaClass* TcxGridBandedDataRowCellsAreaItemViewInfoClass;

class DELPHICLASS TcxGridBandedDataRowCellsAreaViewInfo;
class DELPHICLASS TcxGridBandedRowsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedDataRowCellsAreaItemViewInfo : public Cxgridrows::TcxGridCellViewInfo
{
	typedef Cxgridrows::TcxGridCellViewInfo inherited;
	
private:
	TcxGridBandViewInfo* FBandViewInfo;
	TcxGridBandedDataRowCellsAreaViewInfo* FCellsAreaViewInfo;
	System::Classes::TList* FLineBounds;
	TcxGridFixedBandsSeparatorLocation __fastcall GetFixedBandsSeparatorLocation(void);
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetGridViewInfo(void);
	System::Types::TRect __fastcall GetLineBounds(int Index);
	int __fastcall GetLineCount(void);
	TcxGridBandedRowsViewInfo* __fastcall GetRecordsViewInfo(void);
	HIDESBASE Cxgridrows::TcxGridDataRowViewInfo* __fastcall GetRecordViewInfo(void);
	void __fastcall ClearLines(void);
	void __fastcall CreateLineBounds(void);
	void __fastcall DestroyLineBounds(void);
	
protected:
	void __fastcall AddLine(const System::Types::TRect &ABounds);
	virtual void __fastcall AddLines(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual System::Types::TRect __fastcall GetFixedBandsSeparatorBounds(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall Offset(int DX, int DY);
	__property TcxGridBandViewInfo* BandViewInfo = {read=FBandViewInfo};
	__property TcxGridBandedDataRowCellsAreaViewInfo* CellsAreaViewInfo = {read=FCellsAreaViewInfo};
	__property TcxGridBandedTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property Cxgridrows::TcxGridDataRowViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
	__property TcxGridBandedRowsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	
public:
	__fastcall virtual TcxGridBandedDataRowCellsAreaItemViewInfo(TcxGridBandedDataRowCellsAreaViewInfo* ACellsAreaViewInfo, TcxGridBandViewInfo* ABandViewInfo);
	__fastcall virtual ~TcxGridBandedDataRowCellsAreaItemViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall CanDrawSelected(void);
	__property System::Types::TRect FixedBandsSeparatorBounds = {read=GetFixedBandsSeparatorBounds};
	__property TcxGridFixedBandsSeparatorLocation FixedBandsSeparatorLocation = {read=GetFixedBandsSeparatorLocation, nodefault};
	__property System::Types::TRect LineBounds[int Index] = {read=GetLineBounds};
	__property int LineCount = {read=GetLineCount, nodefault};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedDataRowCellsAreaViewInfo : public Cxgridrows::TcxGridDataRowCellsAreaViewInfo
{
	typedef Cxgridrows::TcxGridDataRowCellsAreaViewInfo inherited;
	
public:
	TcxGridBandedDataRowCellsAreaItemViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	TcxGridBandsViewInfo* __fastcall GetBandsViewInfo(void);
	int __fastcall GetCount(void);
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetGridViewInfo(void);
	TcxGridBandedDataRowCellsAreaItemViewInfo* __fastcall GetItem(int Index);
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	
protected:
	virtual bool __fastcall CalculateVisible(void);
	virtual TcxGridBandedDataRowCellsAreaItemViewInfoClass __fastcall GetItemClass(void);
	virtual void __fastcall Offset(int DX, int DY);
	__property TcxGridBandsViewInfo* BandsViewInfo = {read=GetBandsViewInfo};
	__property TcxGridBandedTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	
public:
	__fastcall virtual TcxGridBandedDataRowCellsAreaViewInfo(Cxgridcustomtableview::TcxCustomGridRecordViewInfo* ARecordViewInfo);
	__fastcall virtual ~TcxGridBandedDataRowCellsAreaViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall DrawMergedCells(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridBandedDataRowCellsAreaItemViewInfo* Items[int Index] = {read=GetItem/*, default*/};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedRowsViewInfo : public Cxgridtableview::TcxGridRowsViewInfo
{
	typedef Cxgridtableview::TcxGridRowsViewInfo inherited;
	
private:
	bool FRowCellsAreaVisible;
	HIDESBASE TcxGridBandedHeaderViewInfo* __fastcall GetHeaderViewInfo(void);
	
protected:
	virtual int __fastcall CalculateDataRowHeight(void);
	virtual bool __fastcall CalculateRowCellsAreaVisible(void);
	virtual System::Types::TRect __fastcall GetAreaBoundsForCell(Cxgridcustomtableview::TcxGridTableDataCellViewInfo* ACellViewInfo);
	virtual Cxgridcustomtableview::TcxCustomGridRecordsPainterClass __fastcall GetPainterClass(void);
	virtual int __fastcall GetRowWidth(void);
	virtual bool __fastcall GetShowBandSeparators(void);
	virtual bool __fastcall GetShowCellLeftLines(void);
	virtual bool __fastcall GetShowCellTopLines(void);
	__property TcxGridBandedHeaderViewInfo* HeaderViewInfo = {read=GetHeaderViewInfo};
	__property bool ShowBandSeparators = {read=GetShowBandSeparators, nodefault};
	__property bool ShowCellLeftLines = {read=GetShowCellLeftLines, nodefault};
	__property bool ShowCellTopLines = {read=GetShowCellTopLines, nodefault};
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual System::TClass __fastcall GetDataRowCellsAreaViewInfoClass(void);
	virtual bool __fastcall IsCellMultiLine(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	__property bool RowCellsAreaVisible = {read=FRowCellsAreaVisible, nodefault};
public:
	/* TcxGridRowsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridBandedRowsViewInfo(void) { }
	
public:
	/* TcxCustomGridRecordsViewInfo.Create */ inline __fastcall virtual TcxGridBandedRowsViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo) : Cxgridtableview::TcxGridRowsViewInfo(AGridViewInfo) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTableViewInfo : public Cxgridtableview::TcxGridTableViewInfo
{
	typedef Cxgridtableview::TcxGridTableViewInfo inherited;
	
private:
	HIDESBASE TcxGridBandedTableController* __fastcall GetController(void);
	System::Uitypes::TColor __fastcall GetFixedBandSeparatorColor(void);
	int __fastcall GetFixedBandSeparatorWidth(void);
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	TcxGridBandedHeaderViewInfo* __fastcall GetHeaderViewInfo(void);
	
protected:
	virtual int __fastcall GetColumnFooterWidth(Cxgridtableview::TcxGridFooterViewInfo* AFooterViewInfo, Cxgridtableview::TcxGridColumn* AColumn);
	virtual int __fastcall GetFirstItemAdditionalWidth(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsForEdit(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsHorz(void);
	virtual bool __fastcall SupportsAutoHeight(void);
	virtual bool __fastcall SupportsGroupSummariesAlignedWithColumns(void);
	virtual bool __fastcall SupportsMultipleFooterSummaries(void);
	virtual Cxgridtableview::TcxGridFooterPainterClass __fastcall GetFooterPainterClass(void);
	virtual Cxgridtableview::TcxGridFooterViewInfoClass __fastcall GetFooterViewInfoClass(void);
	virtual Cxgridtableview::TcxGridHeaderViewInfoClass __fastcall GetHeaderViewInfoClass(void);
	virtual Cxgridtableview::TcxGridHeaderViewInfoSpecificClass __fastcall GetHeaderViewInfoSpecificClass(void);
	virtual Cxgridtableview::TcxGridIndicatorViewInfoClass __fastcall GetIndicatorViewInfoClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordsViewInfoClass __fastcall GetRecordsViewInfoClass(void);
	__property TcxGridBandedTableController* Controller = {read=GetController};
	
public:
	virtual bool __fastcall CanOffset(int ARecordCountDelta, int DX, int DY);
	virtual int __fastcall GetCellHeight(int AIndex, int ACellHeight);
	virtual int __fastcall GetCellTopOffset(int AIndex, int ACellHeight);
	__property System::Uitypes::TColor FixedBandSeparatorColor = {read=GetFixedBandSeparatorColor, nodefault};
	__property int FixedBandSeparatorWidth = {read=GetFixedBandSeparatorWidth, nodefault};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property TcxGridBandedHeaderViewInfo* HeaderViewInfo = {read=GetHeaderViewInfo};
public:
	/* TcxCustomGridTableViewInfo.Create */ inline __fastcall virtual TcxGridBandedTableViewInfo(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridtableview::TcxGridTableViewInfo(AGridView) { }
	/* TcxCustomGridTableViewInfo.Destroy */ inline __fastcall virtual ~TcxGridBandedTableViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedColumnOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedColumnOptions : public Cxgridtableview::TcxGridColumnOptions
{
	typedef Cxgridtableview::TcxGridColumnOptions inherited;
	
private:
	bool FVertSizing;
	void __fastcall SetVertSizing(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__fastcall virtual TcxGridBandedColumnOptions(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	
__published:
	__property bool VertSizing = {read=FVertSizing, write=SetVertSizing, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridBandedColumnOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedColumnStyles;
class PASCALIMPLEMENTATION TcxGridBandedColumnStyles : public Cxgridtableview::TcxGridColumnStyles
{
	typedef Cxgridtableview::TcxGridColumnStyles inherited;
	
private:
	HIDESBASE TcxGridBandedColumn* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	__property TcxGridBandedColumn* Item = {read=GetItem};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxGridBandedColumnStyles(System::Classes::TPersistent* AOwner) : Cxgridtableview::TcxGridColumnStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridBandedColumnStyles(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedColumnPosition : public Cxgridcustomtableview::TcxCustomGridTableItemCustomOptions
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemCustomOptions inherited;
	
private:
	TcxGridBand* FBand;
	int FBandIndex;
	int FColIndex;
	int FLineCount;
	TcxGridBandRow* FRow;
	int FRowIndex;
	int FVisibleColIndex;
	int __fastcall GetBandIndex(void);
	int __fastcall GetColIndex(void);
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	TcxGridBandedColumn* __fastcall GetItem(void);
	int __fastcall GetRowIndex(void);
	int __fastcall GetVisibleBandIndex(void);
	int __fastcall GetVisibleRowIndex(void);
	void __fastcall SetBand(TcxGridBand* Value);
	void __fastcall SetBandIndex(int Value);
	void __fastcall SetColIndex(int Value);
	void __fastcall SetLineCount(int Value);
	void __fastcall SetRowIndex(int Value);
	
protected:
	void __fastcall CheckLineCount(int &Value);
	void __fastcall SaveParams(bool ABandIndexOnly = false);
	
public:
	__fastcall virtual TcxGridBandedColumnPosition(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridBand* Band = {read=FBand};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property TcxGridBandedColumn* Item = {read=GetItem};
	__property TcxGridBandRow* Row = {read=FRow};
	__property int VisibleBandIndex = {read=GetVisibleBandIndex, nodefault};
	__property int VisibleColIndex = {read=FVisibleColIndex, nodefault};
	__property int VisibleRowIndex = {read=GetVisibleRowIndex, nodefault};
	
__published:
	__property int BandIndex = {read=GetBandIndex, write=SetBandIndex, nodefault};
	__property int ColIndex = {read=GetColIndex, write=SetColIndex, nodefault};
	__property int LineCount = {read=FLineCount, write=SetLineCount, default=1};
	__property int RowIndex = {read=GetRowIndex, write=SetRowIndex, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridBandedColumnPosition(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGridBandedColumn : public Cxgridtableview::TcxGridColumn
{
	typedef Cxgridtableview::TcxGridColumn inherited;
	
private:
	TcxGridBandedColumnPosition* FPosition;
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	HIDESBASE TcxGridBandedColumnOptions* __fastcall GetOptions(void);
	HIDESBASE TcxGridBandedColumnStyles* __fastcall GetStyles(void);
	HIDESBASE void __fastcall SetOptions(TcxGridBandedColumnOptions* Value);
	void __fastcall SetPosition(TcxGridBandedColumnPosition* Value);
	HIDESBASE void __fastcall SetStyles(TcxGridBandedColumnStyles* Value);
	
protected:
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemOptionsClass __fastcall GetOptionsClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemStylesClass __fastcall GetStylesClass(void);
	virtual void __fastcall AssignColumnWidths(void);
	virtual bool __fastcall CanCellMerging(void);
	virtual bool __fastcall CanScroll(void);
	virtual bool __fastcall CanVertSize(void);
	virtual System::UnicodeString __fastcall DefaultAlternateCaption(void);
	virtual bool __fastcall GetActuallyVisible(void);
	virtual bool __fastcall GetEditPartVisible(void);
	virtual bool __fastcall GetIsBottom(void);
	virtual bool __fastcall GetIsLeft(void);
	virtual bool __fastcall GetIsMostBottom(void);
	virtual bool __fastcall GetIsMostLeft(void);
	virtual bool __fastcall GetIsMostRight(void);
	virtual bool __fastcall GetIsRight(void);
	virtual bool __fastcall GetIsTop(void);
	virtual bool __fastcall GetVisibleInQuickCustomizationPopup(void);
	virtual void __fastcall VisibleChanged(void);
	
public:
	__fastcall virtual ~TcxGridBandedColumn(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	
__published:
	__property TcxGridBandedColumnOptions* Options = {read=GetOptions, write=SetOptions};
	__property TcxGridBandedColumnPosition* Position = {read=FPosition, write=SetPosition};
	__property TcxGridBandedColumnStyles* Styles = {read=GetStyles, write=SetStyles};
public:
	/* TcxGridColumn.Create */ inline __fastcall virtual TcxGridBandedColumn(System::Classes::TComponent* AOwner) : Cxgridtableview::TcxGridColumn(AOwner) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandRow : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridBandedColumn* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridBandRows* FBandRows;
	System::Classes::TList* FItems;
	System::Classes::TList* FVisibleItems;
	int __fastcall GetCount(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsFirst(void);
	bool __fastcall GetIsLast(void);
	TcxGridBandedColumn* __fastcall GetItem(int Index);
	int __fastcall GetLineCount(void);
	int __fastcall GetLineOffset(void);
	bool __fastcall GetVisible(void);
	int __fastcall GetVisibleCount(void);
	int __fastcall GetVisibleIndex(void);
	TcxGridBandedColumn* __fastcall GetVisibleItem(int Index);
	int __fastcall GetWidth(void);
	
protected:
	void __fastcall CheckIndexForInsert(int &AIndex, bool AExistingItem);
	void __fastcall RefreshVisibleItemsList(void);
	__property System::Classes::TList* VisibleItemsList = {read=FVisibleItems};
	__property int Width = {read=GetWidth, nodefault};
	
public:
	__fastcall TcxGridBandRow(TcxGridBandRows* ABandRows);
	__fastcall virtual ~TcxGridBandRow(void);
	void __fastcall ApplyBestFit(bool ACheckSizingAbility = false, bool AFireEvents = false);
	void __fastcall Delete(int AIndex);
	int __fastcall IndexOf(TcxGridBandedColumn* AColumn);
	void __fastcall Insert(int AIndex, TcxGridBandedColumn* AColumn);
	void __fastcall Move(int ACurIndex, int ANewIndex);
	__property TcxGridBandRows* BandRows = {read=FBandRows};
	__property int Count = {read=GetCount, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property bool IsFirst = {read=GetIsFirst, nodefault};
	__property bool IsLast = {read=GetIsLast, nodefault};
	__property TcxGridBandedColumn* Items[int Index] = {read=GetItem/*, default*/};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int LineOffset = {read=GetLineOffset, nodefault};
	__property bool Visible = {read=GetVisible, nodefault};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
	__property TcxGridBandedColumn* VisibleItems[int Index] = {read=GetVisibleItem};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandRows : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridBandRow* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridBand* FBand;
	System::Classes::TList* FItems;
	System::Classes::TList* FVisibleItems;
	int __fastcall GetCount(void);
	TcxGridBandRow* __fastcall GetFirstVisible(void);
	TcxGridBandedTableView* __fastcall GetGridView(void);
	TcxGridBandRow* __fastcall GetItem(int Index);
	TcxGridBandRow* __fastcall GetLastVisible(void);
	int __fastcall GetLineCount(void);
	int __fastcall GetVisibleCount(void);
	TcxGridBandRow* __fastcall GetVisibleItem(int Index);
	int __fastcall GetWidth(void);
	void __fastcall SetCount(int Value);
	void __fastcall RemoveItem(TcxGridBandRow* ARow);
	
protected:
	void __fastcall RefreshVisibleItemsList(void);
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property int Width = {read=GetWidth, nodefault};
	
public:
	__fastcall virtual TcxGridBandRows(TcxGridBand* ABand);
	__fastcall virtual ~TcxGridBandRows(void);
	void __fastcall ApplyBestFit(bool ACheckSizingAbility = false, bool AFireEvents = false);
	int __fastcall GetLineIndex(int ARowIndex);
	int __fastcall GetRowIndex(int ALineIndex);
	TcxGridBandRow* __fastcall Insert(int AIndex);
	void __fastcall MoveColumn(TcxGridBandedColumn* AColumn, int ARowIndex, int AColIndex);
	__property TcxGridBand* Band = {read=FBand};
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property TcxGridBandRow* FirstVisible = {read=GetFirstVisible};
	__property TcxGridBandRow* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxGridBandRow* LastVisible = {read=GetLastVisible};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	__property TcxGridBandRow* VisibleItems[int Index] = {read=GetVisibleItem};
};

#pragma pack(pop)

enum TcxGridBandChange : unsigned char { bcProperty, bcLayout, bcSize };

class DELPHICLASS TcxGridBandCustomOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandCustomOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxGridBand* FBand;
	
protected:
	virtual void __fastcall Changed(TcxGridBandChange AChange);
	
public:
	__fastcall virtual TcxGridBandCustomOptions(TcxGridBand* ABand);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridBand* Band = {read=FBand};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridBandCustomOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridBandOptionsClass;

class DELPHICLASS TcxGridBandOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandOptions : public TcxGridBandCustomOptions
{
	typedef TcxGridBandCustomOptions inherited;
	
private:
	bool FHoldOwnColumnsOnly;
	bool FMoving;
	bool FSizing;
	void __fastcall SetHoldOwnColumnsOnly(bool Value);
	void __fastcall SetMoving(bool Value);
	void __fastcall SetSizing(bool Value);
	
public:
	__fastcall virtual TcxGridBandOptions(TcxGridBand* ABand);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool HoldOwnColumnsOnly = {read=FHoldOwnColumnsOnly, write=SetHoldOwnColumnsOnly, default=0};
	__property bool Moving = {read=FMoving, write=SetMoving, default=1};
	__property bool Sizing = {read=FSizing, write=SetSizing, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridBandOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandPosition;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandPosition : public TcxGridBandCustomOptions
{
	typedef TcxGridBandCustomOptions inherited;
	
private:
	int FBandIndex;
	int FColIndex;
	int __fastcall GetBandIndex(void);
	int __fastcall GetColIndex(void);
	TcxGridBandedTableView* __fastcall GetGridView(void);
	TcxGridBand* __fastcall GetParentBand(void);
	int __fastcall GetVisibleColIndex(void);
	void __fastcall SetBandIndex(int Value);
	void __fastcall SetColIndex(int Value);
	bool __fastcall IsColIndexStored(void);
	
protected:
	bool __fastcall CheckBandIndex(int &Value);
	void __fastcall SaveParams(void);
	
public:
	__fastcall virtual TcxGridBandPosition(TcxGridBand* ABand);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property TcxGridBand* ParentBand = {read=GetParentBand};
	__property int VisibleColIndex = {read=GetVisibleColIndex, nodefault};
	
__published:
	__property int BandIndex = {read=GetBandIndex, write=SetBandIndex, default=-1};
	__property int ColIndex = {read=GetColIndex, write=SetColIndex, stored=IsColIndexStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridBandPosition(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridBandGetHeaderStyle)(TcxGridBandedTableView* Sender, TcxGridBand* ABand, Cxstyles::TcxStyle* &AStyle);

typedef System::TMetaClass* TcxGridBandStylesClass;

class DELPHICLASS TcxGridBandStyles;
class PASCALIMPLEMENTATION TcxGridBandStyles : public Cxgridcustomview::TcxCustomGridStyles
{
	typedef Cxgridcustomview::TcxCustomGridStyles inherited;
	
private:
	TcxGridBandGetHeaderStyle FOnGetHeaderStyle;
	TcxGridBand* __fastcall GetBand(void);
	TcxGridBandedTableView* __fastcall GetGridViewValue(void);
	void __fastcall SetOnGetHeaderStyle(TcxGridBandGetHeaderStyle Value);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetGridView(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetHeaderParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridBand* Band = {read=GetBand};
	__property TcxGridBandedTableView* GridView = {read=GetGridViewValue};
	
__published:
	__property Cxstyles::TcxStyle* Background = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=2};
	__property TcxGridBandGetHeaderStyle OnGetHeaderStyle = {read=FOnGetHeaderStyle, write=SetOnGetHeaderStyle};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxGridBandStyles(System::Classes::TPersistent* AOwner) : Cxgridcustomview::TcxCustomGridStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridBandStyles(void) { }
	
};


typedef void __fastcall (__closure *TcxGridBandGetStoredPropertiesEvent)(TcxGridBand* Sender, System::Classes::TStrings* AProperties);

typedef void __fastcall (__closure *TcxGridBandGetStoredPropertyValueEvent)(TcxGridBand* Sender, const System::UnicodeString AName, System::Variant &AValue);

typedef void __fastcall (__closure *TcxGridBandSetStoredPropertyValueEvent)(TcxGridBand* Sender, const System::UnicodeString AName, const System::Variant &AValue);

typedef System::TMetaClass* TcxGridBandClass;

class PASCALIMPLEMENTATION TcxGridBand : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
private:
	System::UnicodeString FAlternateCaption;
	System::UnicodeString FCaption;
	System::Classes::TList* FChildBands;
	System::Classes::TList* FColumns;
	TcxGridBandFixedKind FFixedKind;
	System::Classes::TAlignment FHeaderAlignmentHorz;
	Cxclasses::TcxAlignmentVert FHeaderAlignmentVert;
	int FID;
	bool FIgnoreLoadingStatus;
	bool FIsDestroying;
	int FLoadedIndex;
	TcxGridBandOptions* FOptions;
	TcxGridBand* FParentBand;
	TcxGridBandPosition* FPosition;
	TcxGridBandRows* FRows;
	bool FSavedVisible;
	TcxGridBandStyles* FStyles;
	int FTag;
	bool FVisible;
	System::Classes::TList* FVisibleChildBands;
	bool FVisibleForCustomization;
	int FWidth;
	System::Classes::TNotifyEvent FSubClassEvents;
	System::Classes::TNotifyEvent FOnHeaderClick;
	TcxGridBandGetStoredPropertiesEvent FOnGetStoredProperties;
	TcxGridBandGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	TcxGridBandSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	int __fastcall GetBandLevelIndex(void);
	TcxGridBands* __fastcall GetBands(void);
	TcxGridBand* __fastcall GetChildBand(int Index);
	int __fastcall GetChildBandCount(void);
	System::TObject* __fastcall GetChildItem(int Index);
	int __fastcall GetChildItemCount(void);
	bool __fastcall GetChildItemVisible(int Index);
	int __fastcall GetColumnCount(void);
	TcxGridBandedColumn* __fastcall GetColumn(int Index);
	TcxGridBand* __fastcall GetFirstChildBottomBand(void);
	TcxGridBand* __fastcall GetFirstVisibleChildBottomBand(void);
	TcxGridBandedTableView* __fastcall GetGridView(void);
	bool __fastcall GetHidden(void);
	bool __fastcall GetIsBottom(void);
	bool __fastcall GetIsEmpty(void);
	bool __fastcall GetIsFirst(void);
	bool __fastcall GetIsFirstNonEmpty(void);
	bool __fastcall GetIsLast(void);
	bool __fastcall GetIsLastAsChild(void);
	bool __fastcall GetIsLastNonEmpty(void);
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIsMostRight(void);
	bool __fastcall GetIsRoot(void);
	bool __fastcall GetIsUpdating(void);
	bool __fastcall GetIsVisibleBottom(void);
	int __fastcall GetMinWidth(void);
	TcxGridBand* __fastcall GetParentBandWithAssignedWidth(void);
	int __fastcall GetRootIndex(void);
	TcxGridBand* __fastcall GetRootParentBand(void);
	int __fastcall GetVisibleBandLevelCount(void);
	int __fastcall GetVisibleBottomIndex(void);
	TcxGridBand* __fastcall GetVisibleChildBand(int Index);
	int __fastcall GetVisibleChildBandCount(void);
	int __fastcall GetVisibleIndex(void);
	int __fastcall GetVisibleRootIndex(void);
	bool __fastcall IsTagStored(void);
	void __fastcall SetAlternateCaption(const System::UnicodeString Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetFixedKind(TcxGridBandFixedKind Value);
	void __fastcall SetHeaderAlignmentHorz(System::Classes::TAlignment Value);
	void __fastcall SetHeaderAlignmentVert(Cxclasses::TcxAlignmentVert Value);
	void __fastcall SetHidden(bool Value);
	void __fastcall SetOnHeaderClick(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnGetStoredProperties(TcxGridBandGetStoredPropertiesEvent Value);
	void __fastcall SetOnGetStoredPropertyValue(TcxGridBandGetStoredPropertyValueEvent Value);
	void __fastcall SetOnSetStoredPropertyValue(TcxGridBandSetStoredPropertyValueEvent Value);
	void __fastcall SetOptions(TcxGridBandOptions* Value);
	void __fastcall SetPosition(TcxGridBandPosition* Value);
	void __fastcall SetRootIndex(int Value);
	void __fastcall SetStyles(TcxGridBandStyles* Value);
	void __fastcall SetTag(int Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetVisibleForCustomization(bool Value);
	void __fastcall SetWidth(int Value);
	void __fastcall ReadHidden(System::Classes::TReader* Reader);
	void __fastcall AddBand(TcxGridBand* ABand);
	void __fastcall RemoveBand(TcxGridBand* ABand);
	void __fastcall RefreshVisibleChildBandsList(void);
	void __fastcall AddColumn(TcxGridBandedColumn* AColumn);
	void __fastcall RemoveColumn(TcxGridBandedColumn* AColumn);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	void __fastcall ApplyLoadedIndex(void);
	void __fastcall AssignChildBandWidths(void);
	void __fastcall AssignColumnWidths(void);
	virtual bool __fastcall CanHide(void);
	virtual bool __fastcall CanMove(void);
	virtual bool __fastcall CanSize(void);
	HIDESBASE virtual void __fastcall Changed(TcxGridBandChange AChange);
	virtual System::UnicodeString __fastcall DefaultAlternateCaption(void);
	virtual void __fastcall ForceWidth(int Value);
	virtual bool __fastcall GetActuallyVisible(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual bool __fastcall GetFixed(void);
	TcxGridBand* __fastcall GetParentInParent(TcxGridBand* ABand);
	virtual bool __fastcall HasFixedWidth(void);
	bool __fastcall HasParentWithAssignedWidth(void);
	int __fastcall ColIndexOf(TcxGridBand* ABand)/* overload */;
	void __fastcall MoveBandsToRoot(void);
	void __fastcall ResetLoadedIndex(void);
	virtual void __fastcall SetIndex(int Value);
	int __fastcall VisibleColIndexOf(TcxGridBand* ABand)/* overload */;
	virtual void __fastcall VisibleForCustomizationChanged(void);
	void __fastcall CheckChildrenVisibles(void);
	void __fastcall CheckVisible(void);
	void __fastcall SaveChildrenVisibles(void);
	void __fastcall SaveColumnsVisibles(void);
	void __fastcall SaveVisible(void);
	__property int ChildItemCount = {read=GetChildItemCount, nodefault};
	__property System::TObject* ChildItems[int Index] = {read=GetChildItem};
	__property bool ChildItemVisibles[int Index] = {read=GetChildItemVisible};
	__property bool SavedVisible = {read=FSavedVisible, nodefault};
	virtual TcxGridBandOptionsClass __fastcall GetOptionsClass(void);
	virtual TcxGridBandStylesClass __fastcall GetStylesClass(void);
	virtual void __fastcall DoHeaderClick(void);
	__property bool Fixed = {read=GetFixed, nodefault};
	__property bool IgnoreLoadingStatus = {read=FIgnoreLoadingStatus, write=FIgnoreLoadingStatus, nodefault};
	__property bool IsDestroying = {read=FIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsUpdating = {read=GetIsUpdating, nodefault};
	__property TcxGridBand* ParentBandWithAssignedWidth = {read=GetParentBandWithAssignedWidth};
	
public:
	__fastcall virtual TcxGridBand(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxGridBand(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ApplyBestFit(bool ACheckSizingAbility = false, bool AFireEvents = false);
	System::UnicodeString __fastcall GetAlternateCaption(void);
	bool __fastcall HasAsParent(TcxGridBand* ABand);
	void __fastcall MoveBand(TcxGridBand* ABand, int AColIndex);
	void __fastcall MoveColumn(TcxGridBandedColumn* AColumn, int ARowIndex, int AColIndex);
	void __fastcall MoveColumns(TcxGridBand* ABand);
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property int BandLevelIndex = {read=GetBandLevelIndex, nodefault};
	__property TcxGridBands* Bands = {read=GetBands};
	__property int ChildBandCount = {read=GetChildBandCount, nodefault};
	__property TcxGridBand* ChildBands[int Index] = {read=GetChildBand};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property TcxGridBandedColumn* Columns[int Index] = {read=GetColumn};
	__property TcxGridBand* FirstChildBottomBand = {read=GetFirstChildBottomBand};
	__property TcxGridBand* FirstVisibleChildBottomBand = {read=GetFirstVisibleChildBottomBand};
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	__property bool Hidden = {read=GetHidden, write=SetHidden, nodefault};
	__property int ID = {read=FID, nodefault};
	__property bool IsBottom = {read=GetIsBottom, nodefault};
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property bool IsFirst = {read=GetIsFirst, nodefault};
	__property bool IsFirstNonEmpty = {read=GetIsFirstNonEmpty, nodefault};
	__property bool IsLast = {read=GetIsLast, nodefault};
	__property bool IsLastAsChild = {read=GetIsLastAsChild, nodefault};
	__property bool IsLastNonEmpty = {read=GetIsLastNonEmpty, nodefault};
	__property bool IsMostRight = {read=GetIsMostRight, nodefault};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property bool IsVisibleBottom = {read=GetIsVisibleBottom, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property TcxGridBand* ParentBand = {read=FParentBand};
	__property int RootIndex = {read=GetRootIndex, write=SetRootIndex, nodefault};
	__property TcxGridBand* RootParentBand = {read=GetRootParentBand};
	__property TcxGridBandRows* Rows = {read=FRows};
	__property int VisibleBandLevelCount = {read=GetVisibleBandLevelCount, nodefault};
	__property int VisibleBottomIndex = {read=GetVisibleBottomIndex, nodefault};
	__property int VisibleChildBandCount = {read=GetVisibleChildBandCount, nodefault};
	__property TcxGridBand* VisibleChildBands[int Index] = {read=GetVisibleChildBand};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
	__property int VisibleRootIndex = {read=GetVisibleRootIndex, nodefault};
	
__published:
	__property System::Classes::TAlignment Alignment = {read=FHeaderAlignmentHorz, write=SetHeaderAlignmentHorz, stored=false, nodefault};
	__property System::UnicodeString AlternateCaption = {read=FAlternateCaption, write=SetAlternateCaption};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property TcxGridBandFixedKind FixedKind = {read=FFixedKind, write=SetFixedKind, default=0};
	__property System::Classes::TAlignment HeaderAlignmentHorz = {read=FHeaderAlignmentHorz, write=SetHeaderAlignmentHorz, default=2};
	__property Cxclasses::TcxAlignmentVert HeaderAlignmentVert = {read=FHeaderAlignmentVert, write=SetHeaderAlignmentVert, default=2};
	__property TcxGridBandOptions* Options = {read=FOptions, write=SetOptions};
	__property TcxGridBandPosition* Position = {read=FPosition, write=SetPosition};
	__property TcxGridBandStyles* Styles = {read=FStyles, write=SetStyles};
	__property int Tag = {read=FTag, write=SetTag, stored=IsTagStored, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property bool VisibleForCustomization = {read=FVisibleForCustomization, write=SetVisibleForCustomization, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
	__property System::Classes::TNotifyEvent StylesEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent OnHeaderClick = {read=FOnHeaderClick, write=SetOnHeaderClick};
	__property TcxGridBandGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=SetOnGetStoredProperties};
	__property TcxGridBandGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=SetOnGetStoredPropertyValue};
	__property TcxGridBandSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=SetOnSetStoredPropertyValue};
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	
};


enum TcxGridBandsLayout : unsigned char { blNonFixed, blLeftFixed, blRightFixed, blLeftRightFixed };

typedef System::TMetaClass* TcxGridBandsClass;

class PASCALIMPLEMENTATION TcxGridBands : public Cxclasses::TcxOwnedInterfacedCollection
{
	typedef Cxclasses::TcxOwnedInterfacedCollection inherited;
	
public:
	TcxGridBand* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FBottomItems;
	TcxGridBandedTableView* FGridView;
	int FNextID;
	System::Classes::TList* FRootItems;
	System::Classes::TList* FVisibleBottomItems;
	System::Classes::TList* FVisibleItems;
	int FVisibleLeftFixedCount;
	int FVisibleRightFixedCount;
	System::Classes::TList* FVisibleRootItems;
	int FVisibleRootLeftFixedCount;
	int FVisibleRootRightFixedCount;
	TcxGridBand* __fastcall GetBottomItem(int Index);
	int __fastcall GetBottomItemCount(void);
	TcxGridBand* __fastcall GetFirstVisibleNonEmpty(void);
	HIDESBASE TcxGridBand* __fastcall GetItem(int Index);
	TcxGridBand* __fastcall GetLastVisibleNonEmpty(void);
	TcxGridBandsLayout __fastcall GetLayout(void);
	int __fastcall GetLineCount(void);
	TcxGridBand* __fastcall GetRootItem(int Index);
	int __fastcall GetRootItemCount(void);
	TcxGridBand* __fastcall GetVisibleBottomItem(int Index);
	int __fastcall GetVisibleBottomItemCount(void);
	int __fastcall GetVisibleCount(void);
	TcxGridBand* __fastcall GetVisibleItem(int Index);
	TcxGridBand* __fastcall GetVisibleRootItem(int Index);
	int __fastcall GetVisibleRootItemCount(void);
	int __fastcall GetVisibleRowCount(void);
	HIDESBASE void __fastcall SetItem(int Index, TcxGridBand* Value);
	void __fastcall AddItem(TcxGridBand* AItem);
	HIDESBASE void __fastcall RemoveItem(TcxGridBand* AItem);
	void __fastcall RefreshBottomItemsList(void);
	void __fastcall RefreshRootItemsList(void);
	void __fastcall RefreshVisibleBottomItemsList(void);
	void __fastcall RefreshVisibleItemsList(void);
	void __fastcall RefreshVisibleRootItemsList(void);
	
protected:
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall GetChildren(System::Classes::TStringList* AChildren);
	virtual void __fastcall BandVisibilityChanged(TcxGridBand* ABand, bool Value);
	virtual TcxGridBandClass __fastcall GetBandClass(void);
	int __fastcall GetNextID(void);
	void __fastcall ReleaseID(int AID);
	__property int NextID = {read=FNextID, nodefault};
	
public:
	__fastcall virtual TcxGridBands(TcxGridBandedTableView* AGridView);
	__fastcall virtual ~TcxGridBands(void);
	HIDESBASE TcxGridBand* __fastcall Add(void);
	bool __fastcall AreNested(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HIDESBASE void __fastcall Clear(void);
	HIDESBASE TcxGridBand* __fastcall FindItemID(int AID);
	int __fastcall GetFirstVisibleIndex(TcxGridBandFixedKind AFixedKind);
	int __fastcall GetFirstVisibleRootIndex(TcxGridBandFixedKind AFixedKind);
	int __fastcall GetLastVisibleIndex(TcxGridBandFixedKind AFixedKind);
	int __fastcall GetLastVisibleRootIndex(TcxGridBandFixedKind AFixedKind);
	bool __fastcall HaveFixedItems(void);
	__property int BottomItemCount = {read=GetBottomItemCount, nodefault};
	__property TcxGridBand* BottomItems[int Index] = {read=GetBottomItem};
	__property TcxGridBand* FirstVisibleNonEmpty = {read=GetFirstVisibleNonEmpty};
	__property TcxGridBandedTableView* GridView = {read=FGridView};
	__property TcxGridBand* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxGridBandsLayout Layout = {read=GetLayout, nodefault};
	__property TcxGridBand* LastVisibleNonEmpty = {read=GetLastVisibleNonEmpty};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int RootItemCount = {read=GetRootItemCount, nodefault};
	__property TcxGridBand* RootItems[int Index] = {read=GetRootItem};
	__property int VisibleBottomItemCount = {read=GetVisibleBottomItemCount, nodefault};
	__property TcxGridBand* VisibleBottomItems[int Index] = {read=GetVisibleBottomItem};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	__property TcxGridBand* VisibleItems[int Index] = {read=GetVisibleItem};
	__property int VisibleLeftFixedCount = {read=FVisibleLeftFixedCount, nodefault};
	__property int VisibleRightFixedCount = {read=FVisibleRightFixedCount, nodefault};
	__property int VisibleRootItemCount = {read=GetVisibleRootItemCount, nodefault};
	__property TcxGridBand* VisibleRootItems[int Index] = {read=GetVisibleRootItem};
	__property int VisibleRootLeftFixedCount = {read=FVisibleRootLeftFixedCount, nodefault};
	__property int VisibleRootRightFixedCount = {read=FVisibleRootRightFixedCount, nodefault};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
private:
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6AF48CD0-3A0B-4BEC-AC88-5D323432A686}
	operator Cxstorage::_di_IcxStoredParent()
	{
		Cxstorage::_di_IcxStoredParent intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredParent*(void) { return (Cxstorage::IcxStoredParent*)&__IcxStoredParent; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	
};


class DELPHICLASS TcxGridBandedTableBackgroundBitmaps;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTableBackgroundBitmaps : public Cxgridtableview::TcxGridTableBackgroundBitmaps
{
	typedef Cxgridtableview::TcxGridTableBackgroundBitmaps inherited;
	
protected:
	virtual int __fastcall GetBitmapStyleIndex(int Index);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Graphics::TBitmap* BandBackground = {read=GetValue, write=SetValue, index=9};
	__property Vcl::Graphics::TBitmap* BandHeader = {read=GetValue, write=SetValue, index=10};
public:
	/* TcxCustomGridBackgroundBitmaps.Create */ inline __fastcall virtual TcxGridBandedTableBackgroundBitmaps(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridtableview::TcxGridTableBackgroundBitmaps(AGridView) { }
	/* TcxCustomGridBackgroundBitmaps.Destroy */ inline __fastcall virtual ~TcxGridBandedTableBackgroundBitmaps(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedTableOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTableOptionsBehavior : public Cxgridtableview::TcxGridTableOptionsBehavior
{
	typedef Cxgridtableview::TcxGridTableOptionsBehavior inherited;
	
private:
	bool FBandHeaderHints;
	void __fastcall SetBandHeaderHints(bool Value);
	
public:
	__fastcall virtual TcxGridBandedTableOptionsBehavior(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool BandHeaderHints = {read=FBandHeaderHints, write=SetBandHeaderHints, default=1};
public:
	/* TcxCustomGridOptionsBehavior.Destroy */ inline __fastcall virtual ~TcxGridBandedTableOptionsBehavior(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedTableOptionsCustomize;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTableOptionsCustomize : public Cxgridtableview::TcxGridTableOptionsCustomize
{
	typedef Cxgridtableview::TcxGridTableOptionsCustomize inherited;
	
private:
	bool FBandHiding;
	bool FBandMoving;
	bool FBandSizing;
	bool FBandsQuickCustomization;
	int FBandsQuickCustomizationMaxDropDownCount;
	Cxgridcustomtableview::TcxGridQuickCustomizationReordering FBandsQuickCustomizationReordering;
	bool FColumnVertSizing;
	bool FNestedBands;
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	void __fastcall SetBandHiding(bool Value);
	void __fastcall SetBandMoving(bool Value);
	void __fastcall SetBandSizing(bool Value);
	void __fastcall SetBandsQuickCustomization(bool Value);
	void __fastcall SetBandsQuickCustomizationMaxDropDownCount(int Value);
	void __fastcall SetBandsQuickCustomizationReordering(Cxgridcustomtableview::TcxGridQuickCustomizationReordering Value);
	void __fastcall SetColumnVertSizing(bool Value);
	void __fastcall SetNestedBands(bool Value);
	
public:
	__fastcall virtual TcxGridBandedTableOptionsCustomize(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall SupportsBandsQuickCustomizationReordering(void);
	virtual bool __fastcall SupportsItemsQuickCustomizationReordering(void);
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	
__published:
	__property bool BandHiding = {read=FBandHiding, write=SetBandHiding, default=0};
	__property bool BandMoving = {read=FBandMoving, write=SetBandMoving, default=1};
	__property bool BandSizing = {read=FBandSizing, write=SetBandSizing, default=1};
	__property bool BandsQuickCustomization = {read=FBandsQuickCustomization, write=SetBandsQuickCustomization, default=0};
	__property int BandsQuickCustomizationMaxDropDownCount = {read=FBandsQuickCustomizationMaxDropDownCount, write=SetBandsQuickCustomizationMaxDropDownCount, default=0};
	__property Cxgridcustomtableview::TcxGridQuickCustomizationReordering BandsQuickCustomizationReordering = {read=FBandsQuickCustomizationReordering, write=SetBandsQuickCustomizationReordering, default=0};
	__property bool ColumnVertSizing = {read=FColumnVertSizing, write=SetColumnVertSizing, default=1};
	__property bool NestedBands = {read=FNestedBands, write=SetNestedBands, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridBandedTableOptionsCustomize(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedTableOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTableOptionsView : public Cxgridtableview::TcxGridTableOptionsView
{
	typedef Cxgridtableview::TcxGridTableOptionsView inherited;
	
private:
	bool FBandCaptionsInColumnAlternateCaption;
	bool FBandHeaderEndEllipsis;
	int FBandHeaderHeight;
	int FBandHeaderLineCount;
	bool FBandHeaders;
	System::Uitypes::TColor FFixedBandSeparatorColor;
	int FFixedBandSeparatorWidth;
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridView(void);
	void __fastcall SetBandCaptionsInColumnAlternateCaption(bool Value);
	void __fastcall SetBandHeaderEndEllipsis(bool Value);
	void __fastcall SetBandHeaderHeight(int Value);
	void __fastcall SetBandHeaderLineCount(int Value);
	void __fastcall SetBandHeaders(bool Value);
	void __fastcall SetFixedBandSeparatorColor(System::Uitypes::TColor Value);
	void __fastcall SetFixedBandSeparatorWidth(int Value);
	
public:
	__fastcall virtual TcxGridBandedTableOptionsView(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::Uitypes::TColor __fastcall GetFixedBandSeparatorColor(void);
	__property TcxGridBandedTableView* GridView = {read=GetGridView};
	
__published:
	__property bool BandCaptionsInColumnAlternateCaption = {read=FBandCaptionsInColumnAlternateCaption, write=SetBandCaptionsInColumnAlternateCaption, default=0};
	__property bool BandHeaderEndEllipsis = {read=FBandHeaderEndEllipsis, write=SetBandHeaderEndEllipsis, default=0};
	__property int BandHeaderHeight = {read=FBandHeaderHeight, write=SetBandHeaderHeight, default=0};
	__property int BandHeaderLineCount = {read=FBandHeaderLineCount, write=SetBandHeaderLineCount, default=1};
	__property bool BandHeaders = {read=FBandHeaders, write=SetBandHeaders, default=1};
	__property System::Uitypes::TColor FixedBandSeparatorColor = {read=FFixedBandSeparatorColor, write=SetFixedBandSeparatorColor, default=536870912};
	__property int FixedBandSeparatorWidth = {read=FFixedBandSeparatorWidth, write=SetFixedBandSeparatorWidth, default=2};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridBandedTableOptionsView(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedTableViewStyles;
class PASCALIMPLEMENTATION TcxGridBandedTableViewStyles : public Cxgridtableview::TcxGridTableViewStyles
{
	typedef Cxgridtableview::TcxGridTableViewStyles inherited;
	
private:
	TcxGridBandGetHeaderStyle FOnGetBandHeaderStyle;
	HIDESBASE TcxGridBandedTableView* __fastcall GetGridViewValue(void);
	void __fastcall SetOnGetBandHeaderStyle(TcxGridBandGetHeaderStyle Value);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetBandHeaderParams(TcxGridBand* ABand, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridBandedTableView* GridView = {read=GetGridViewValue};
	
__published:
	__property Cxstyles::TcxStyle* BandBackground = {read=GetValue, write=SetValue, index=21};
	__property Cxstyles::TcxStyle* BandHeader = {read=GetValue, write=SetValue, index=22};
	__property StyleSheet;
	__property TcxGridBandGetHeaderStyle OnGetBandHeaderStyle = {read=FOnGetBandHeaderStyle, write=SetOnGetBandHeaderStyle};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxGridBandedTableViewStyles(System::Classes::TPersistent* AOwner) : Cxgridtableview::TcxGridTableViewStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridBandedTableViewStyles(void) { }
	
};


class DELPHICLASS TcxGridBandedTableViewStyleSheet;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTableViewStyleSheet : public Cxstyles::TcxCustomStyleSheet
{
	typedef Cxstyles::TcxCustomStyleSheet inherited;
	
private:
	TcxGridBandedTableViewStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxGridBandedTableViewStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxGridBandedTableViewStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxGridBandedTableViewStyleSheet(System::Classes::TComponent* AOwner) : Cxstyles::TcxCustomStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxGridBandedTableViewStyleSheet(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridBandCustomDrawHeaderEvent)(TcxGridBandedTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridBandHeaderViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridBandEvent)(TcxGridBandedTableView* Sender, TcxGridBand* ABand);

class PASCALIMPLEMENTATION TcxGridBandedTableView : public Cxgridtableview::TcxGridTableView
{
	typedef Cxgridtableview::TcxGridTableView inherited;
	
private:
	TcxGridBands* FBands;
	bool FIsAssigningBands;
	TcxGridBandEvent FOnBandPosChanged;
	TcxGridBandEvent FOnBandSizeChanged;
	TcxGridBandCustomDrawHeaderEvent FOnCustomDrawBandHeader;
	HIDESBASE TcxGridBandedTableBackgroundBitmaps* __fastcall GetBackgroundBitmaps(void);
	HIDESBASE TcxGridBandedColumn* __fastcall GetColumn(int Index);
	HIDESBASE TcxGridBandedTableController* __fastcall GetController(void);
	HIDESBASE TcxGridBandedColumn* __fastcall GetGroupedColumn(int Index);
	HIDESBASE TcxGridBandedTableOptionsBehavior* __fastcall GetOptionsBehavior(void);
	HIDESBASE TcxGridBandedTableOptionsCustomize* __fastcall GetOptionsCustomize(void);
	HIDESBASE TcxGridBandedTableOptionsView* __fastcall GetOptionsView(void);
	HIDESBASE TcxGridBandedTableViewStyles* __fastcall GetStyles(void);
	HIDESBASE TcxGridBandedTableViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE TcxGridBandedColumn* __fastcall GetVisibleColumn(int Index);
	HIDESBASE void __fastcall SetBackgroundBitmaps(TcxGridBandedTableBackgroundBitmaps* Value);
	void __fastcall SetBands(TcxGridBands* Value);
	HIDESBASE void __fastcall SetColumn(int Index, TcxGridBandedColumn* Value);
	void __fastcall SetOnBandPosChanged(TcxGridBandEvent Value);
	void __fastcall SetOnBandSizeChanged(TcxGridBandEvent Value);
	void __fastcall SetOnCustomDrawBandHeader(TcxGridBandCustomDrawHeaderEvent Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxGridBandedTableOptionsBehavior* Value);
	HIDESBASE void __fastcall SetOptionsCustomize(TcxGridBandedTableOptionsCustomize* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxGridBandedTableOptionsView* Value);
	HIDESBASE void __fastcall SetStyles(TcxGridBandedTableViewStyles* Value);
	
protected:
	virtual void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual void __fastcall AssignLayout(Cxgridcustomview::TcxCustomGridView* ALayoutView);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	DYNAMIC void __fastcall Updated(void);
	DYNAMIC void __fastcall Updating(void);
	void __fastcall BeginAssignBands(void);
	virtual void __fastcall DoAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual void __fastcall DoItemsAssigned(void);
	void __fastcall EndAssignBands(void);
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	virtual bool __fastcall GetIsControlFocused(void);
	bool __fastcall HasCustomDrawBandHeader(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual void __fastcall AddItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	void __fastcall AssignBandsParams(void);
	void __fastcall AssignColumnsParams(bool AAssignBandIndexes, bool AAssignOtherIndexes);
	virtual void __fastcall BeforeRestoring(void);
	virtual void __fastcall GetVisibleItemsList(System::Classes::TList* AItems);
	virtual void __fastcall LoadingComplete(void);
	virtual void __fastcall RefreshVisibleItemsList(void);
	virtual void __fastcall RestoringComplete(void);
	void __fastcall SaveBandsParams(void);
	void __fastcall SaveColumnsParams(bool ABandIndexOnly = false);
	virtual Cxgridcustomview::TcxCustomGridBackgroundBitmapsClass __fastcall GetBackgroundBitmapsClass(void);
	virtual TcxGridBandsClass __fastcall GetBandsClass(void);
	virtual Cxgridcustomview::TcxCustomGridControllerClass __fastcall GetControllerClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableOptionsCustomizeClass __fastcall GetOptionsCustomizeClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxgridcustomview::TcxCustomGridPainterClass __fastcall GetPainterClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewStylesClass __fastcall GetStylesClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall DoBandPosChanged(TcxGridBand* ABand);
	virtual void __fastcall DoBandSizeChanged(TcxGridBand* ABand);
	virtual void __fastcall DoCustomDrawBandHeader(Cxgraphics::TcxCanvas* ACanvas, TcxGridBandHeaderViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall Initialize(void);
	__property bool IsAssigningBands = {read=FIsAssigningBands, nodefault};
	
public:
	virtual void __fastcall ApplyBestFit(Cxgridcustomtableview::TcxCustomGridTableItem* AItem = (Cxgridcustomtableview::TcxCustomGridTableItem*)(0x0), bool ACheckSizingAbility = false, bool AFireEvents = false);
	HIDESBASE TcxGridBandedColumn* __fastcall CreateColumn(void);
	__property TcxGridBandedColumn* Columns[int Index] = {read=GetColumn, write=SetColumn};
	__property TcxGridBandedTableController* Controller = {read=GetController};
	__property TcxGridBandedColumn* GroupedColumns[int Index] = {read=GetGroupedColumn};
	__property TcxGridBandedTableViewInfo* ViewInfo = {read=GetViewInfo};
	__property TcxGridBandedColumn* VisibleColumns[int Index] = {read=GetVisibleColumn};
	
__published:
	__property TcxGridBandedTableBackgroundBitmaps* BackgroundBitmaps = {read=GetBackgroundBitmaps, write=SetBackgroundBitmaps};
	__property TcxGridBands* Bands = {read=FBands, write=SetBands};
	__property TcxGridBandedTableOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxGridBandedTableOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize, write=SetOptionsCustomize};
	__property TcxGridBandedTableOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxGridBandedTableViewStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxGridBandEvent OnBandPosChanged = {read=FOnBandPosChanged, write=SetOnBandPosChanged};
	__property TcxGridBandEvent OnBandSizeChanged = {read=FOnBandSizeChanged, write=SetOnBandSizeChanged};
	__property TcxGridBandCustomDrawHeaderEvent OnCustomDrawBandHeader = {read=FOnCustomDrawBandHeader, write=SetOnCustomDrawBandHeader};
public:
	/* TcxGridTableView.Create */ inline __fastcall virtual TcxGridBandedTableView(System::Classes::TComponent* AOwner) : Cxgridtableview::TcxGridTableView(AOwner) { }
	
public:
	/* TcxCustomGridTableView.Destroy */ inline __fastcall virtual ~TcxGridBandedTableView(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridBandedTableView(Cxcontrols::TcxControl* AControl) : Cxgridtableview::TcxGridTableView(AControl) { }
	
public:
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridBandedTableView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridtableview::TcxGridTableView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString cxGridBandedTableViewAlternateCaptionSeparator;
static const System::Int8 cxGridDefaultFixedBandSeparatorWidth = System::Int8(0x2);
static const System::Int8 cxGridDefaultEmptyBandWidth = System::Int8(0x32);
static const System::Byte htBandedGridBase = System::Byte(0xfa);
static const System::Byte htColumnHeaderVertSizingEdge = System::Byte(0xfb);
static const System::Byte htBand = System::Byte(0xfc);
static const System::Byte htBandHeader = System::Byte(0xfd);
static const System::Byte htBandHeaderSizingEdge = System::Byte(0xfe);
static const System::Byte htIndicatorBandHeader = System::Byte(0xff);
static const System::Int8 bbBandedTableFirst = System::Int8(0x9);
static const System::Int8 bbBandBackground = System::Int8(0x9);
static const System::Int8 bbBandHeader = System::Int8(0xa);
static const System::Int8 bbBandedTableLast = System::Int8(0xa);
static const System::Int8 bsFirst = System::Int8(0x0);
static const System::Int8 bsBackground = System::Int8(0x0);
static const System::Int8 bsContent = System::Int8(0x1);
static const System::Int8 bsHeader = System::Int8(0x2);
static const System::Int8 bsLast = System::Int8(0x2);
static const System::Int8 vsBandedTableFirst = System::Int8(0x15);
static const System::Int8 vsBandBackground = System::Int8(0x15);
static const System::Int8 vsBandHeader = System::Int8(0x16);
static const System::Int8 vsBandedTableLast = System::Int8(0x16);
}	/* namespace Cxgridbandedtableview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDBANDEDTABLEVIEW)
using namespace Cxgridbandedtableview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridbandedtableviewHPP
