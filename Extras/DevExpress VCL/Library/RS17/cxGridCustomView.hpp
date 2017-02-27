// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridCustomView.pas' rev: 24.00 (Win32)

#ifndef CxgridcustomviewHPP
#define CxgridcustomviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Cxgridcustomview
{
__interface IcxCustomGridPopupOwner;
}

namespace Cxgridcustomview
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxCustomGridDragAndDropObjectClass;

typedef Cxcontrols::TcxLockedStateImageShowingMode TcxGridShowLockedStateImageMode;

__interface IcxGridViewLayoutEditorSupport;
typedef System::DelphiInterface<IcxGridViewLayoutEditorSupport> _di_IcxGridViewLayoutEditorSupport;
class DELPHICLASS TcxCustomGridView;
__interface  INTERFACE_UUID("{9C5EC9C0-A912-4822-BBD0-87AB45FDCC78}") IcxGridViewLayoutEditorSupport  : public System::IInterface 
{
	
public:
	virtual void __fastcall BeforeEditLayout(TcxCustomGridView* ALayoutView) = 0 ;
	virtual bool __fastcall CanEditViewLayoutAndData(void) = 0 ;
	virtual void __fastcall DoAssignLayout(TcxCustomGridView* ALayoutView) = 0 ;
	virtual System::UnicodeString __fastcall GetLayoutCustomizationFormButtonCaption(void) = 0 ;
	virtual bool __fastcall HasLayoutCustomizationForm(void) = 0 ;
	virtual bool __fastcall IsLayoutChangeable(void) = 0 ;
	virtual void __fastcall RunLayoutCustomizationForm(void) = 0 ;
};

class DELPHICLASS TcxCustomGridViewChange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewChange : public Cxgridcommon::TcxCustomGridChange
{
	typedef Cxgridcommon::TcxCustomGridChange inherited;
	
private:
	TcxCustomGridView* FGridView;
	
public:
	__fastcall virtual TcxCustomGridViewChange(TcxCustomGridView* AGridView);
	__property TcxCustomGridView* GridView = {read=FGridView, write=FGridView};
	virtual bool __fastcall IsEqual(Cxgridcommon::TcxCustomGridChange* AChange);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridViewChange(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridControlFocusChange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridControlFocusChange : public TcxCustomGridViewChange
{
	typedef TcxCustomGridViewChange inherited;
	
public:
	virtual void __fastcall Execute(void);
public:
	/* TcxCustomGridViewChange.Create */ inline __fastcall virtual TcxGridControlFocusChange(TcxCustomGridView* AGridView) : TcxCustomGridViewChange(AGridView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridControlFocusChange(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridHitTestClass;

class DELPHICLASS TcxCustomGridHitTest;
class DELPHICLASS TcxCustomGridCellViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridHitTest : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsClone;
	System::Types::TPoint FPos;
	TcxCustomGridCellViewInfo* FViewInfo;
	void __fastcall SetViewInfo(TcxCustomGridCellViewInfo* Value);
	
protected:
	virtual void __fastcall Assign(TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	void __fastcall Init(const System::Types::TPoint &APos);
	
public:
	__fastcall virtual ~TcxCustomGridHitTest(void);
	TcxCustomGridHitTest* __fastcall Clone(void);
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
	virtual TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
	__classmethod int __fastcall HitTestCode();
	__classmethod TcxCustomGridHitTest* __fastcall Instance(const System::Types::TPoint &APos);
	__property System::Types::TPoint Pos = {read=FPos};
	__property TcxCustomGridCellViewInfo* ViewInfo = {read=FViewInfo, write=SetViewInfo};
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridHitTest(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridNoneHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridNoneHitTest : public TcxCustomGridHitTest
{
	typedef TcxCustomGridHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridNoneHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridNoneHitTest(void) : TcxCustomGridHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridViewHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewHitTest : public TcxCustomGridHitTest
{
	typedef TcxCustomGridHitTest inherited;
	
private:
	TcxCustomGridView* FGridView;
	
protected:
	virtual void __fastcall Assign(TcxCustomGridHitTest* Source);
	
public:
	__property TcxCustomGridView* GridView = {read=FGridView, write=FGridView};
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxCustomGridViewHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridViewHitTest(void) : TcxCustomGridHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridViewNoneHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewNoneHitTest : public TcxCustomGridViewHitTest
{
	typedef TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridViewNoneHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridViewNoneHitTest(void) : TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridNavigatorHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridNavigatorHitTest : public TcxCustomGridViewHitTest
{
	typedef TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridNavigatorHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridNavigatorHitTest(void) : TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomizationFormHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomizationFormHitTest : public TcxCustomGridViewHitTest
{
	typedef TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridCustomizationFormHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridCustomizationFormHitTest(void) : TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridDesignSelectorHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDesignSelectorHitTest : public TcxCustomGridViewHitTest
{
	typedef TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridDesignSelectorHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridDesignSelectorHitTest(void) : TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridViewHandler;
class DELPHICLASS TcxCustomGridController;
class DELPHICLASS TcxCustomGridPainter;
class DELPHICLASS TcxGridSite;
class DELPHICLASS TcxCustomGridViewData;
class DELPHICLASS TcxCustomGridViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewHandler : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxCustomGridView* FGridView;
	Cxcontrols::TcxControl* __fastcall GetControl(void);
	TcxCustomGridController* __fastcall GetController(void);
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	TcxCustomGridPainter* __fastcall GetPainter(void);
	TcxGridSite* __fastcall GetSite(void);
	TcxCustomGridViewData* __fastcall GetViewData(void);
	TcxCustomGridViewInfo* __fastcall GetViewInfo(void);
	
protected:
	__property Cxcontrols::TcxControl* Control = {read=GetControl};
	__property TcxCustomGridController* Controller = {read=GetController};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxCustomGridViewData* ViewData = {read=GetViewData};
	
public:
	__fastcall virtual TcxGridViewHandler(TcxCustomGridView* AGridView);
	void __fastcall BeginUpdate(TcxGridShowLockedStateImageMode AShowLockedStateImage = (TcxGridShowLockedStateImageMode)(0x0));
	void __fastcall EndUpdate(void);
	__property TcxCustomGridView* GridView = {read=FGridView};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TcxCustomGridPainter* Painter = {read=GetPainter};
	__property TcxGridSite* Site = {read=GetSite};
	__property TcxCustomGridViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridViewHandler(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridDragAndDropObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridDragAndDropObject : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	TcxCustomGridController* __fastcall GetController(void);
	TcxCustomGridView* __fastcall GetGridView(void);
	TcxCustomGridViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AfterDragAndDrop(bool Accepted);
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeforePaint(void);
	__property TcxCustomGridController* Controller = {read=GetController};
	__property TcxCustomGridViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	System::Types::TPoint SourcePoint;
	virtual void __fastcall AfterScrolling(void);
	virtual void __fastcall BeforeScrolling(void);
	virtual void __fastcall AfterViewChange(void);
	virtual void __fastcall BeforeViewChange(void);
	virtual void __fastcall Init(const System::Types::TPoint &P, TcxCustomGridHitTest* AParams);
	__property TcxCustomGridView* GridView = {read=GetGridView};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxCustomGridDragAndDropObject(Cxcontrols::TcxControl* AControl) : Cxcontrols::TcxDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridDragAndDropObject(void) { }
	
};

#pragma pack(pop)

enum TcxGridArrowNumber : unsigned char { anFirst, anLast };

typedef Cxcontrols::TcxArrowPlace TcxGridArrowPlace;

class DELPHICLASS TcxCustomGridMovingObject;
class DELPHICLASS TcxCustomGridCustomizationForm;
class DELPHICLASS TcxCustomGridItemsListBox;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridMovingObject : public TcxCustomGridDragAndDropObject
{
	typedef TcxCustomGridDragAndDropObject inherited;
	
private:
	Cxcontrols::TcxDragImage* FDragImage;
	System::TObject* FSourceItem;
	Cxcontrols::TcxArrowPlace __fastcall GetArrowPlace(TcxGridArrowNumber AArrowNumber);
	TcxCustomGridCustomizationForm* __fastcall GetCustomizationForm(void);
	bool __fastcall HasArrows(void);
	
protected:
	System::StaticArray<Cxcontrols::TcxDragAndDropArrow*, 2> Arrows;
	virtual void __fastcall DirtyChanged(void);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	void __fastcall ChangeArrowsPosition(bool AVisible = true);
	void __fastcall ChangeDragImagePosition(bool AVisible = true);
	virtual bool __fastcall AreArrowsVertical(void);
	virtual bool __fastcall CanRemove(void) = 0 ;
	virtual System::Types::TRect __fastcall GetArrowAreaBounds(Cxcontrols::TcxArrowPlace APlace) = 0 ;
	virtual Cxcontrols::TcxDragAndDropArrowClass __fastcall GetArrowClass(void);
	virtual System::Types::TRect __fastcall GetArrowsClientRect(void);
	virtual TcxCustomGridItemsListBox* __fastcall GetCustomizationFormListBox(void) = 0 ;
	virtual Cxcontrols::TcxDragImageClass __fastcall GetDragImageClass(void);
	virtual System::Types::TRect __fastcall GetSourceItemBounds(void);
	virtual TcxCustomGridCellViewInfo* __fastcall GetSourceItemViewInfo(void);
	virtual void __fastcall InitDragImage(void);
	virtual void __fastcall InitDragImageUsingCustomizationForm(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::TObject* AItem);
	virtual bool __fastcall IsSourceCustomizationForm(void) = 0 ;
	virtual bool __fastcall IsValidDestination(void) = 0 ;
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	__property Cxcontrols::TcxArrowPlace ArrowPlaces[TcxGridArrowNumber AArrowNumber] = {read=GetArrowPlace};
	__property System::Types::TRect ArrowsClientRect = {read=GetArrowsClientRect};
	__property TcxCustomGridCustomizationForm* CustomizationForm = {read=GetCustomizationForm};
	__property TcxCustomGridItemsListBox* CustomizationFormListBox = {read=GetCustomizationFormListBox};
	__property Cxcontrols::TcxDragImage* DragImage = {read=FDragImage};
	__property System::TObject* SourceItem = {read=FSourceItem, write=FSourceItem};
	__property System::Types::TRect SourceItemBounds = {read=GetSourceItemBounds};
	__property TcxCustomGridCellViewInfo* SourceItemViewInfo = {read=GetSourceItemViewInfo};
	
public:
	virtual void __fastcall AfterScrolling(void);
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxCustomGridMovingObject(Cxcontrols::TcxControl* AControl) : TcxCustomGridDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridMovingObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridItemsInnerListBox;
class PASCALIMPLEMENTATION TcxCustomGridItemsInnerListBox : public Cxlistbox::TcxInnerListBox
{
	typedef Cxlistbox::TcxInnerListBox inherited;
	
private:
	int FDragAndDropItemIndex;
	System::Types::TPoint FMouseDownPos;
	HIDESBASE TcxCustomGridItemsListBox* __fastcall GetContainer(void);
	System::TObject* __fastcall GetDragAndDropItem(void);
	TcxCustomGridView* __fastcall GetGridView(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DrawBorder(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawItem(int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall CalculateBorderStyle(void);
	void __fastcall CalculateItemHeight(void);
	__property TcxCustomGridItemsListBox* Container = {read=GetContainer};
	__property System::TObject* DragAndDropItem = {read=GetDragAndDropItem};
	__property int DragAndDropItemIndex = {read=FDragAndDropItemIndex, nodefault};
	__property TcxCustomGridView* GridView = {read=GetGridView};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
public:
	__fastcall virtual TcxCustomGridItemsInnerListBox(System::Classes::TComponent* AOwner);
public:
	/* TcxCustomInnerListBox.Destroy */ inline __fastcall virtual ~TcxCustomGridItemsInnerListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridItemsInnerListBox(HWND ParentWindow) : Cxlistbox::TcxInnerListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxCustomGridItemsListBoxClass;

class PASCALIMPLEMENTATION TcxCustomGridItemsListBox : public Cxlistbox::TcxListBox
{
	typedef Cxlistbox::TcxListBox inherited;
	
private:
	System::TObject* __fastcall GetDragAndDropItem(void);
	TcxCustomGridView* __fastcall GetGridView(void);
	HIDESBASE TcxCustomGridItemsInnerListBox* __fastcall GetInnerListBox(void);
	
protected:
	virtual int __fastcall CalculateItemHeight(void) = 0 ;
	virtual void __fastcall DoRefreshItems(void) = 0 ;
	virtual Cxlistbox::TcxInnerListBoxClass __fastcall GetInnerListBoxClass(void);
	virtual TcxCustomGridHitTest* __fastcall GetDragAndDropParams(void) = 0 ;
	__property System::TObject* DragAndDropItem = {read=GetDragAndDropItem};
	__property TcxCustomGridView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxCustomGridItemsListBox(System::Classes::TComponent* AOwner);
	int __fastcall IndexOfItem(System::TObject* AItem);
	void __fastcall PaintDragAndDropItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::TObject* AItem);
	virtual void __fastcall PaintItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int AIndex, bool AFocused) = 0 ;
	void __fastcall RefreshItems(void);
	__property TcxCustomGridItemsInnerListBox* InnerListBox = {read=GetInnerListBox};
public:
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TcxCustomGridItemsListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridItemsListBox(HWND ParentWindow) : Cxlistbox::TcxListBox(ParentWindow) { }
	
};


__interface IcxGridCustomizationForm;
typedef System::DelphiInterface<IcxGridCustomizationForm> _di_IcxGridCustomizationForm;
__interface  INTERFACE_UUID("{D702C868-B1BC-41B6-BDD0-5CF5030E03C3}") IcxGridCustomizationForm  : public System::IInterface 
{
	
public:
	virtual void __fastcall GridViewChanged(void) = 0 ;
	virtual TcxCustomGridController* __fastcall GetController(void) = 0 ;
	virtual void __fastcall Initialize(TcxCustomGridController* AController) = 0 ;
	virtual void __fastcall RefreshData(void) = 0 ;
	__property TcxCustomGridController* Controller = {read=GetController};
};

typedef System::TMetaClass* TcxCustomGridCustomizationFormClass;

class PASCALIMPLEMENTATION TcxCustomGridCustomizationForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TcxCustomGridController* FController;
	Cxclasses::TcxTimer* FHookTimer;
	int FOffset;
	Cxpc::TcxPageControl* FPageControl;
	TcxCustomGridView* __fastcall GetGridView(void);
	TcxCustomGridViewInfo* __fastcall GetViewInfo(void);
	void __fastcall HookTimerHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall GridViewChanged(void);
	TcxCustomGridController* __fastcall GetController(void);
	void __fastcall Initialize(TcxCustomGridController* AController);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoClose(System::Uitypes::TCloseAction &Action);
	DYNAMIC void __fastcall DoShow(void);
	Cxpc::TcxTabSheet* __fastcall CreatePage(const System::UnicodeString ACaption, bool AVisible);
	virtual void __fastcall CalculateConsts(void);
	virtual void __fastcall CreateControls(void);
	virtual System::Types::TRect __fastcall GetContentBounds(void);
	virtual System::Types::TRect __fastcall GetPageControlBounds(void);
	virtual bool __fastcall HasDFM(void);
	virtual void __fastcall InitPageControl(void);
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
	__property TcxCustomGridView* GridView = {read=GetGridView};
	__property int Offset = {read=FOffset, write=FOffset, nodefault};
	__property Cxpc::TcxPageControl* PageControl = {read=FPageControl};
	__property TcxCustomGridViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomGridCustomizationForm(TcxCustomGridController* AController);
	__fastcall virtual ~TcxCustomGridCustomizationForm(void);
	__property TcxCustomGridController* Controller = {read=FController};
	void __fastcall ActivatePage(Cxpc::TcxTabSheet* APage);
	virtual void __fastcall RefreshData(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomGridCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridCustomizationForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
private:
	void *__IcxGridCustomizationForm;	/* IcxGridCustomizationForm */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D702C868-B1BC-41B6-BDD0-5CF5030E03C3}
	operator _di_IcxGridCustomizationForm()
	{
		_di_IcxGridCustomizationForm intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxGridCustomizationForm*(void) { return (IcxGridCustomizationForm*)&__IcxGridCustomizationForm; }
	#endif
	
};


__interface IcxCustomGridPopupOwner;
typedef System::DelphiInterface<IcxCustomGridPopupOwner> _di_IcxCustomGridPopupOwner;
__interface  INTERFACE_UUID("{ACF62D23-6871-4735-A4CE-3B0888DB8FC3}") IcxCustomGridPopupOwner  : public System::IInterface 
{
	
public:
	virtual bool __fastcall ClosePopupWhenNilOwner(void) = 0 ;
	virtual System::Types::TRect __fastcall GetOwnerBounds(void) = 0 ;
	virtual void __fastcall PopupClosed(void) = 0 ;
};

class DELPHICLASS TcxCustomGridPopup;
class PASCALIMPLEMENTATION TcxCustomGridPopup : public Cxcontainer::TcxCustomPopupWindow
{
	typedef Cxcontainer::TcxCustomPopupWindow inherited;
	
private:
	TcxCustomGridView* FGridView;
	_di_IcxCustomGridPopupOwner FOwner;
	void __fastcall SetOwner(_di_IcxCustomGridPopupOwner Value);
	
protected:
	virtual System::Types::TRect __fastcall CalculateOwnerBounds(void);
	virtual int __fastcall GetClientMinWidth(void);
	virtual void __fastcall InitPopup(void);
	DYNAMIC void __fastcall Paint(void);
	virtual void __fastcall UpdateInnerControlsHeight(int &AClientHeight);
	DYNAMIC void __fastcall VisibleChanged(void);
	
public:
	__fastcall virtual TcxCustomGridPopup(TcxCustomGridView* AGridView);
	virtual void __fastcall CorrectBoundsWithDesktopWorkArea(System::Types::TPoint &APosition);
	HIDESBASE virtual void __fastcall Popup(void);
	__property BorderWidths;
	__property TcxCustomGridView* GridView = {read=FGridView};
	__property int ClientMinWidth = {read=GetClientMinWidth, nodefault};
	__property _di_IcxCustomGridPopupOwner Owner = {read=FOwner, write=SetOwner};
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxCustomGridPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomGridPopup(System::Classes::TComponent* AOwner, int Dummy) : Cxcontainer::TcxCustomPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridPopup(HWND ParentWindow) : Cxcontainer::TcxCustomPopupWindow(ParentWindow) { }
	
};


typedef System::DynamicArray<int> TcxGridIndexes;

class DELPHICLASS TcxGridPopupListBox;
typedef void __fastcall (__closure *TcxGridPopupListBoxActionEvent)(TcxGridPopupListBox* Sender, int AItemIndex);

class PASCALIMPLEMENTATION TcxGridPopupListBox : public Cxlistbox::TcxListBox
{
	typedef Cxlistbox::TcxListBox inherited;
	
private:
	Dxcoreclasses::TdxFastList* FCheckedIndexes;
	int FItemTextOffsetLeft;
	int FItemTextOffsetRight;
	int FItemTextOffsetVert;
	int FMinWidth;
	TcxCustomGridPopup* FPopup;
	int FPressedItemIndex;
	bool FShowChecks;
	int FVisibleItemCount;
	int FVisibleWidth;
	TcxGridPopupListBoxActionEvent FOnAction;
	bool __fastcall GetChecked(int Index);
	TcxGridIndexes __fastcall GetCheckedIndexes(void);
	TcxCustomGridView* __fastcall GetGridView(void);
	void __fastcall SetChecked(int Index, bool Value);
	void __fastcall SetCheckedIndexes(const TcxGridIndexes Value);
	void __fastcall SetPressedItemIndex(int Value);
	void __fastcall SetShowChecks(bool Value);
	
protected:
	virtual bool __fastcall DrawItem(Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual int __fastcall CalculateClientHeight(System::Classes::TStrings* AItems);
	virtual int __fastcall CalculateClientWidth(System::Classes::TStrings* AItems);
	virtual int __fastcall CalculateItemHeight(void);
	virtual void __fastcall DoAction(int AItemIndex);
	virtual void __fastcall DrawItemCheck(Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ACheckAreaRect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall DrawItemContent(Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual int __fastcall GetVisibleItemCount(System::Classes::TStrings* AItems);
	virtual void __fastcall Init(void);
	void __fastcall InvalidateItem(int AIndex);
	virtual bool __fastcall CanHaveCheck(int AItemIndex);
	virtual void __fastcall ChangeChecked(int AItemIndex);
	int __fastcall GetCheckAreaHeight(void);
	int __fastcall GetCheckAreaWidth(void);
	virtual bool __fastcall HasCheck(int AItemIndex);
	bool __fastcall IsCheck(int AItemIndex);
	__property bool Checked[int Index] = {read=GetChecked, write=SetChecked};
	__property TcxGridIndexes CheckedIndexes = {read=GetCheckedIndexes, write=SetCheckedIndexes};
	__property int PressedItemIndex = {read=FPressedItemIndex, write=SetPressedItemIndex, nodefault};
	__property bool ShowChecks = {read=FShowChecks, write=SetShowChecks, nodefault};
	
public:
	__fastcall virtual TcxGridPopupListBox(TcxCustomGridPopup* APopup);
	__fastcall virtual ~TcxGridPopupListBox(void);
	virtual void __fastcall AdjustBounds(System::Classes::TStrings* AItems = (System::Classes::TStrings*)(0x0));
	__property TcxCustomGridView* GridView = {read=GetGridView};
	__property int ItemTextOffsetLeft = {read=FItemTextOffsetLeft, write=FItemTextOffsetLeft, nodefault};
	__property int ItemTextOffsetRight = {read=FItemTextOffsetRight, write=FItemTextOffsetRight, nodefault};
	__property int ItemTextOffsetVert = {read=FItemTextOffsetVert, write=FItemTextOffsetVert, nodefault};
	__property int MinWidth = {read=FMinWidth, write=FMinWidth, nodefault};
	__property TcxCustomGridPopup* Popup = {read=FPopup};
	__property int VisibleItemCount = {read=FVisibleItemCount, write=FVisibleItemCount, nodefault};
	__property int VisibleWidth = {read=FVisibleWidth, write=FVisibleWidth, nodefault};
	__property TcxGridPopupListBoxActionEvent OnAction = {read=FOnAction, write=FOnAction};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridPopupListBox(HWND ParentWindow) : Cxlistbox::TcxListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridPopupListBoxClass;

class DELPHICLASS TcxCustomGridDesignController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridDesignController : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void) = 0 ;
	virtual System::Classes::TPersistent* __fastcall GetDesignObject(System::Classes::TPersistent* AObject);
	
public:
	bool __fastcall CanAddComponent(void);
	bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent);
	void __fastcall GetSelection(System::Classes::TList* AList);
	bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject);
	void __fastcall NotifyEditors(void);
	void __fastcall SelectObject(System::Classes::TPersistent* AObject, bool AClearSelection);
	void __fastcall SelectObjects(System::Classes::TList* AObjects);
	void __fastcall UnselectObject(System::Classes::TPersistent* AObject);
	__property Cxcontrols::TcxControl* Control = {read=GetControl};
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridDesignController(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridDesignController(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridViewDesignControllerClass;

class DELPHICLASS TcxGridViewDesignController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewDesignController : public TcxCustomGridDesignController
{
	typedef TcxCustomGridDesignController inherited;
	
private:
	TcxCustomGridController* FController;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	virtual System::Classes::TPersistent* __fastcall GetDesignObject(System::Classes::TPersistent* AObject);
	
public:
	__fastcall virtual TcxGridViewDesignController(TcxCustomGridController* AController);
	__property TcxCustomGridController* Controller = {read=FController};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridViewDesignController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridHintHelper;
class DELPHICLASS TcxCustomGridOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridHintHelper : public Dxcustomhint::TcxControlHintHelper
{
	typedef Dxcustomhint::TcxControlHintHelper inherited;
	
private:
	TcxCustomGridController* FController;
	TcxCustomGridOptionsBehavior* __fastcall GetOptionsBehavior(void);
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetHintControl(void);
	virtual int __fastcall GetHintHidePause(void);
	virtual Vcl::Controls::THintWindowClass __fastcall GetHintWindowClass(void);
	virtual Cxcontrols::TcxControl* __fastcall GetOwnerControl(void);
	virtual bool __fastcall IsSuppressHintOnMouseDown(void);
	__property TcxCustomGridOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior};
	
public:
	__fastcall virtual TcxGridHintHelper(TcxCustomGridController* AController);
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TcxGridHintHelper(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridHintHelperClass;

class DELPHICLASS TcxCustomGridViewCellViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridController : public TcxGridViewHandler
{
	typedef TcxGridViewHandler inherited;
	
private:
	bool FCustomization;
	Vcl::Forms::TForm* FCustomizationForm;
	System::Types::TRect FCustomizationFormBounds;
	TcxGridViewDesignController* FDesignController;
	TcxCustomGridCellViewInfo* FDesignPopupMenuInvoker;
	TcxGridHintHelper* FHintHelper;
	bool FIsCheckingCoordinates;
	bool FIsDblClick;
	bool FIsFocusing;
	TcxGridViewDesignController* __fastcall GetDesignController(void);
	TcxCustomGridDragAndDropObject* __fastcall GetDragAndDropObject(void);
	Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	Cxcontrols::TcxDragImageList* __fastcall GetDragImages(void);
	TcxCustomGridViewCellViewInfo* __fastcall GetHintCellViewInfo(void);
	Vcl::Controls::THintWindow* __fastcall GetHintWindow(void);
	_di_IcxGridCustomizationForm __fastcall GetICustomizationForm(void);
	bool __fastcall GetIsDragging(void);
	TcxCustomGridCellViewInfo* __fastcall GetMouseCaptureViewInfo(void);
	void __fastcall SetCustomization(bool Value);
	void __fastcall SetDragAndDropObjectClass(Cxcontrols::TcxDragAndDropObjectClass Value);
	void __fastcall SetMouseCaptureViewInfo(TcxCustomGridCellViewInfo* Value);
	
protected:
	virtual void __fastcall AfterPaint(void);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall BeforePaint(void);
	virtual bool __fastcall CanCancelDragStartOnCaptureObjectClear(void);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual bool __fastcall CanHandleHitTest(TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall CheckCoordinates(void);
	virtual bool __fastcall CreateFieldControls(int X, int Y, System::TObject* ADataSource, System::Classes::TList* AFieldList);
	virtual void __fastcall DetailFocused(TcxCustomGridView* ADetail);
	virtual void __fastcall DoEnter(void);
	virtual void __fastcall DoExit(void);
	virtual void __fastcall DoSetFocus(bool ANotifyMaster);
	TcxCustomGridCellViewInfo* __fastcall GetActiveCellViewInfo(TcxCustomGridHitTest* AHitTest);
	virtual TcxGridViewDesignControllerClass __fastcall GetDesignControllerClass(void);
	virtual bool __fastcall GetDesignHitTest(TcxCustomGridHitTest* AHitTest);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual System::Classes::TPersistent* __fastcall GetPatternObject(System::Classes::TPersistent* AObject);
	virtual void __fastcall GridViewChanged(void);
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	bool __fastcall IsSuppressHintOnMouseDown(void);
	virtual bool __fastcall MayFocus(void);
	virtual void __fastcall MouseLeave(void);
	virtual bool __fastcall ProcessDesignPopupMenu(TcxCustomGridCellViewInfo* AViewInfo);
	virtual void __fastcall RemoveFocus(void);
	virtual void __fastcall SetFocus(bool ANotifyMaster);
	virtual void __fastcall VisibilityChanged(bool AVisible);
	virtual bool __fastcall CanCustomize(void);
	virtual void __fastcall CheckCustomizationFormBounds(System::Types::TRect &R);
	virtual Vcl::Forms::TForm* __fastcall CreateCustomizationForm(void);
	virtual void __fastcall CustomizationChanged(void);
	virtual void __fastcall DoCreateCustomizationForm(void);
	void __fastcall DoCustomization(void);
	virtual System::Types::TRect __fastcall GetCustomizationFormBounds(void);
	virtual TcxCustomGridCustomizationFormClass __fastcall GetCustomizationFormClass(void);
	virtual int __fastcall GetCustomizationFormDefaultWidth(void);
	virtual int __fastcall GetCustomizationFormDefaultHeight(void);
	void __fastcall HideCustomizationForm(void);
	virtual void __fastcall InitializeCustomizationForm(Vcl::Forms::TForm* AForm);
	void __fastcall ShowCustomizationForm(void);
	virtual TcxGridHintHelperClass __fastcall GetHintHelperClass(void);
	virtual void __fastcall AfterScrolling(void);
	virtual void __fastcall BeforeScrolling(void);
	virtual void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	virtual void __fastcall DoScroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall EndGestureScroll(void);
	virtual void __fastcall ScrollContentByGesture(Vcl::Forms::TScrollBarKind AScrollKind, int ADelta);
	__property TcxGridHintHelper* HintHelper = {read=FHintHelper};
	__property _di_IcxGridCustomizationForm ICustomizationForm = {read=GetICustomizationForm};
	__property TcxCustomGridCellViewInfo* DesignPopupMenuInvoker = {read=FDesignPopupMenuInvoker};
	__property TcxCustomGridDragAndDropObject* DragAndDropObject = {read=GetDragAndDropObject};
	__property bool IsCheckingCoordinates = {read=FIsCheckingCoordinates, nodefault};
	__property bool IsDragging = {read=GetIsDragging, nodefault};
	__property bool IsFocusing = {read=FIsFocusing, nodefault};
	
public:
	__fastcall virtual TcxCustomGridController(TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridController(void);
	virtual void __fastcall ControlFocusChanged(void);
	void __fastcall DesignerModified(void);
	virtual void __fastcall DoCancelMode(void);
	void __fastcall DoCheckCoordinates(void);
	void __fastcall DoControlFocusChanged(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual bool __fastcall HasFocusedControls(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall IsDataFullyVisible(bool AIsCallFromMaster = false);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall SetScrollBarInfo(Vcl::Forms::TScrollBarKind AScrollBarKind, int AMin, int AMax, int AStep, int APage, int APos, bool AAllowShow, bool AAllowHide);
	void __fastcall UpdateScrollBars(bool AIgnoreUpdateLock = false);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	virtual void __fastcall BeforeStartDrag(void);
	virtual bool __fastcall CanDrag(int X, int Y);
	virtual void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DrawDragImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual System::Types::TPoint __fastcall GetDragImagesSize(void);
	virtual bool __fastcall HasDragImages(void);
	virtual void __fastcall StartDrag(Vcl::Controls::TDragObject* &DragObject);
	__property Cxcontrols::TcxDragImageList* DragImages = {read=GetDragImages};
	void __fastcall CancelHint(void);
	void __fastcall HideHint(void);
	virtual Vcl::Controls::THintWindowClass __fastcall GetHintWindowClass(void);
	void __fastcall ShowHint(const System::Types::TRect &AHintAreaBounds, const System::Types::TRect &ATextRect, const System::UnicodeString AText, bool AIsHintMultiLine, Vcl::Graphics::TFont* AFont, TcxCustomGridViewCellViewInfo* AHintCellViewInfo);
	__property TcxCustomGridViewCellViewInfo* HintCellViewInfo = {read=GetHintCellViewInfo};
	__property Vcl::Controls::THintWindow* HintWindow = {read=GetHintWindow};
	virtual void __fastcall DoKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall IMEStartComposition(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall ProcessDetailDialogChar(TcxCustomGridView* ADetail, System::Word ACharCode);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall RefreshCustomizationForm(void);
	__property bool Customization = {read=FCustomization, write=SetCustomization, nodefault};
	__property Vcl::Forms::TForm* CustomizationForm = {read=FCustomizationForm};
	__property System::Types::TRect CustomizationFormBounds = {read=FCustomizationFormBounds, write=FCustomizationFormBounds};
	__property TcxGridViewDesignController* DesignController = {read=GetDesignController};
	__property Cxcontrols::TcxDragAndDropObjectClass DragAndDropObjectClass = {read=GetDragAndDropObjectClass, write=SetDragAndDropObjectClass};
	__property bool IsDblClick = {read=FIsDblClick, nodefault};
	__property TcxCustomGridCellViewInfo* MouseCaptureViewInfo = {read=GetMouseCaptureViewInfo, write=SetMouseCaptureViewInfo};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridControllerClass;

class DELPHICLASS TcxDataGroupNode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataGroupNode : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxDataGroupNode* operator[](int Index) { return Children[Index]; }
	
private:
	Dxcoreclasses::TdxFastObjectList* FChildren;
	Cxcustomdata::TcxDataGroupInfo* FDataGroupInfo;
	TcxDataGroupNode* FParent;
	TcxDataGroupNode* __fastcall GetChild(int Index);
	int __fastcall GetChildCount(void);
	
protected:
	void __fastcall SortChildren(Dxcoreclasses::TCompareItems ACompare);
	
public:
	__fastcall TcxDataGroupNode(TcxDataGroupNode* AParent, Cxcustomdata::TcxDataGroupInfo* ADataGroupInfo);
	__fastcall virtual ~TcxDataGroupNode(void);
	TcxDataGroupNode* __fastcall AddChild(Cxcustomdata::TcxDataGroupInfo* ADataGroupInfo);
	__property int ChildCount = {read=GetChildCount, nodefault};
	__property TcxDataGroupNode* Children[int Index] = {read=GetChild/*, default*/};
	__property Cxcustomdata::TcxDataGroupInfo* DataGroupInfo = {read=FDataGroupInfo};
	__property TcxDataGroupNode* Parent = {read=FParent};
};

#pragma pack(pop)

class DELPHICLASS TcxSortingBySummaryInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSortingBySummaryInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Dxcore::TdxSortOrder SortOrder;
	int SummaryItemIndex;
public:
	/* TObject.Create */ inline __fastcall TcxSortingBySummaryInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSortingBySummaryInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridSortingBySummaryEngine;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridSortingBySummaryEngine : public Cxcustomdata::TcxSortingBySummaryEngine
{
	typedef Cxcustomdata::TcxSortingBySummaryEngine inherited;
	
private:
	Dxcoreclasses::TdxFastObjectList* FInfos;
	TcxDataGroupNode* FRootNode;
	Cxcustomdata::TcxDataGroups* __fastcall GetDataGroups(void);
	TcxSortingBySummaryInfo* __fastcall GetInfo(int Index);
	int __fastcall GetInfoCount(void);
	
protected:
	void __fastcall AddInfo(TcxSortingBySummaryInfo* AInfo);
	void __fastcall BuildNodes(TcxDataGroupNode* AParentNode, int ALevel, int &ACurIndex);
	void __fastcall ClearInfos(void);
	int __fastcall CompareGroupsBySummary(void * AInfo1, void * AInfo2);
	void __fastcall RebuildDataGroupRecursive(TcxDataGroupNode* AParentNode, int &ABeginRecordListIndex);
	void __fastcall RebuildDataGroups(void);
	void __fastcall SortNodeRecursive(TcxDataGroupNode* ANode, int ALevel);
	void __fastcall SortNodes(void);
	__property Cxcustomdata::TcxDataGroups* DataGroups = {read=GetDataGroups};
	__property int InfoCount = {read=GetInfoCount, nodefault};
	__property TcxSortingBySummaryInfo* Infos[int Index] = {read=GetInfo};
	
public:
	__fastcall virtual TcxGridSortingBySummaryEngine(Cxcustomdata::TcxCustomDataControllerInfo* ADataControllerInfo);
	__fastcall virtual ~TcxGridSortingBySummaryEngine(void);
	virtual void __fastcall Sort(void);
};

#pragma pack(pop)

__interface IcxCustomGridDataController;
typedef System::DelphiInterface<IcxCustomGridDataController> _di_IcxCustomGridDataController;
__interface  INTERFACE_UUID("{B9ABDC6B-1A4A-4F11-A629-09B6FB9FB4BA}") IcxCustomGridDataController  : public System::IInterface 
{
	
public:
	virtual void __fastcall AssignData(Cxcustomdata::TcxCustomDataController* ADataController) = 0 ;
	virtual void __fastcall CreateAllItems(bool AMissingItemsOnly) = 0 ;
	virtual void __fastcall DeleteAllItems(void) = 0 ;
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList) = 0 ;
	virtual TcxCustomGridView* __fastcall GetGridView(void) = 0 ;
	virtual bool __fastcall HasAllItems(void) = 0 ;
	virtual bool __fastcall IsDataChangeable(void) = 0 ;
	virtual bool __fastcall IsDataLinked(void) = 0 ;
	virtual bool __fastcall SupportsCreateAllItems(void) = 0 ;
	__property TcxCustomGridView* GridView = {read=GetGridView};
};

typedef System::TMetaClass* TcxCustomGridCellPainterClass;

class DELPHICLASS TcxCustomGridCellPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridCellPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxCustomGridCellViewInfo* FViewInfo;
	bool __fastcall GetIsMainCanvasInUseValue(void);
	
protected:
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeforePaint(void);
	virtual bool __fastcall CanDrawDesignSelection(void);
	virtual void __fastcall DoExcludeFromClipRect(void);
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual void __fastcall DrawBackground(const System::Types::TRect &R)/* overload */;
	virtual bool __fastcall DrawBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxBorder ABorder);
	virtual void __fastcall DrawBorders(void);
	virtual void __fastcall DrawContent(void);
	__classmethod virtual void __fastcall DrawDesignSelection(Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridCellViewInfo* AViewInfo);
	virtual void __fastcall DrawText(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	__classmethod bool __fastcall GetIsMainCanvasInUse(Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridCellViewInfo* AViewInfo);
	virtual bool __fastcall NeedsPainting(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PrepareCanvasForDrawText(void);
	virtual void __fastcall UnprepareCanvasForDrawText(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property bool IsMainCanvasInUse = {read=GetIsMainCanvasInUseValue, nodefault};
	__property TcxCustomGridCellViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxCustomGridCellPainter(Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridCellViewInfo* AViewInfo);
	__classmethod virtual void __fastcall DoDrawDesignSelection(Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridCellViewInfo* AViewInfo);
	virtual void __fastcall MainPaint(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridCellPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridDesignSelectorPainter;
class DELPHICLASS TcxGridDesignSelectorViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDesignSelectorPainter : public TcxCustomGridCellPainter
{
	typedef TcxCustomGridCellPainter inherited;
	
private:
	TcxGridDesignSelectorViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoExcludeFromClipRect(void);
	virtual void __fastcall DrawSign(System::Uitypes::TColor AColor);
	virtual bool __fastcall ExcludeFromClipRect(void);
	virtual void __fastcall Paint(void);
	__property TcxGridDesignSelectorViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridDesignSelectorPainter(Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDesignSelectorPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridPainterClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridPainter : public TcxGridViewHandler
{
	typedef TcxGridViewHandler inherited;
	
private:
	Cxgraphics::TcxRegion* FBackgroundRegion;
	Cxgraphics::TcxRegion* FBeforePaintClipRegion;
	Cxgraphics::TcxCanvas* FCanvas;
	TcxCustomGridViewInfo* FViewInfo;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	HIDESBASE TcxCustomGridViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall PaintAfter(void);
	virtual void __fastcall PaintBefore(void);
	virtual void __fastcall PaintContent(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas, write=FCanvas};
	__property TcxCustomGridViewInfo* ViewInfo = {read=GetViewInfo, write=FViewInfo};
	
public:
	virtual void __fastcall DrawFocusRect(const System::Types::TRect &R, bool AHideFocusRect);
	void __fastcall ExcludeFromBackground(const System::Types::TRect &R);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas = (Cxgraphics::TcxCanvas*)(0x0), TcxCustomGridViewInfo* AViewInfo = (TcxCustomGridViewInfo*)(0x0));
	void __fastcall Invalidate(void)/* overload */;
	void __fastcall Invalidate(const System::Types::TRect &R)/* overload */;
	void __fastcall Invalidate(Cxgraphics::TcxRegion* ARegion)/* overload */;
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxCustomGridPainter(TcxCustomGridView* AGridView) : TcxGridViewHandler(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridViewDataClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewData : public TcxGridViewHandler
{
	typedef TcxGridViewHandler inherited;
	
public:
	virtual Cxcustomdata::TcxSortingBySummaryEngineClass __fastcall GetSortingBySummaryEngineClass(void);
	virtual bool __fastcall IsEmpty(void);
	virtual TcxCustomGridView* __fastcall MakeDetailVisible(System::Classes::TComponent* ADetailLevel);
	__property DataController;
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxCustomGridViewData(TcxCustomGridView* AGridView) : TcxGridViewHandler(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridViewData(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGridSite : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Cxclasses::TcxTimer* FBoundsChangedTimer;
	TcxCustomGridCellViewInfo* FDesignPopupMenuInvoker;
	bool FIgnoreUpdateLock;
	bool FIsWindowRegionAssigned;
	int FLeftOnMouseDown;
	int FTopOnMouseDown;
	System::Types::TSize FSize;
	TcxCustomGridViewInfo* FViewInfo;
	Cxcontrols::TcxControl* __fastcall GetContainer(void);
	TcxCustomGridController* __fastcall GetController(void);
	TcxCustomGridView* __fastcall GetGridView(void);
	bool __fastcall GetLocked(void);
	TcxCustomGridPainter* __fastcall GetPainter(void);
	void __fastcall SendKeyDownNotification(Winapi::Messages::TWMKey &Message);
	void __fastcall BoundsChangedTimerHandler(System::TObject* Sender);
	void __fastcall SaveOrigin(void);
	HIDESBASE MESSAGE void __fastcall WMGestureNotify(Dxtouch::TWMGestureNotify &Message);
	MESSAGE void __fastcall WMIMEStartComposition(Winapi::Messages::TMessage &Message);
	
protected:
	Cxgraphics::TcxBitmap32* __fastcall GetLockedStateImage(void);
	Cxcontrols::TcxControl* __fastcall GetLockedStateTopmostControl(void);
	bool __fastcall CreateFieldControls(int X, int Y, System::TObject* ADataSource, System::Classes::TList* AFieldList);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall CheckOverpan(Vcl::Forms::TScrollBarKind AScrollKind, int ANewDataPos, int AMinDataPos, int AMaxDataPos, int ADeltaX, int ADeltaY);
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd);
	virtual bool __fastcall AllowAutoDragAndDropAtDesignTime(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC bool __fastcall AllowDragAndDropWithoutFocus(void);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC bool __fastcall CanDrag(int X, int Y);
	virtual bool __fastcall CanFocusOnClick(int X, int Y)/* overload */;
	virtual void __fastcall DestroyHandle(void);
	DYNAMIC void __fastcall DoCancelMode(void);
	DYNAMIC void __fastcall DoContextPopup(const System::Types::TPoint &MousePos, bool &Handled);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	virtual bool __fastcall CanScrollContentByGestureWithoutScrollBars(void);
	virtual void __fastcall DoGetGestureOptions(Vcl::Controls::TInteractiveGestures &Gestures, Vcl::Controls::TInteractiveGestureOptions &Options);
	virtual void __fastcall DoGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind, int ANewScrollPos);
	virtual void __fastcall EndGestureScroll(void);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	virtual bool __fastcall IsGestureScrolling(void);
	virtual bool __fastcall IsGestureHelperMessage(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsMenuKey(Winapi::Messages::TWMKey &Message);
	virtual bool __fastcall IsScrollBarBasedGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind);
	void __fastcall ResetRegion(void);
	virtual void __fastcall ScrollContentByGesture(Vcl::Forms::TScrollBarKind AScrollKind, int ADelta);
	void __fastcall SetRegion(const System::Types::TRect &AVisibleRect);
	virtual void __fastcall DoPaint(void);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual bool __fastcall FocusWhenChildIsClicked(Vcl::Controls::TControl* AChild);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual bool __fastcall GetIsDesigning(void);
	virtual bool __fastcall GetIsFocused(void);
	virtual Cxcontrols::TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass(void);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual System::Uitypes::TScrollStyle __fastcall GetSystemSizeScrollBars(void);
	void __fastcall HideWindow(void);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint &APoint);
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC bool __fastcall MayFocus(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MoveWindow(const System::Types::TRect &ANewBounds);
	virtual void __fastcall Paint(void);
	virtual void __fastcall RequestAlign(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual bool __fastcall UpdateMousePositionIfControlMoved(void);
	virtual bool __fastcall WasMovedOnMouseDown(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DrawDragImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Types::TPoint __fastcall GetDragImagesSize(void);
	virtual bool __fastcall HasDragImages(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual System::Types::TRect __fastcall GetHScrollBarBounds(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall UpdateScrollBars(void);
	virtual bool __fastcall CanCancelDragStartOnCaptureObjectClear(void);
	DYNAMIC void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	DYNAMIC void __fastcall EndDragAndDrop(bool Accepted);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	void __fastcall CancelPostBoundsChanged(void);
	virtual void __fastcall CheckClipping(void);
	void __fastcall InitTabStop(Vcl::Controls::TWinControl* AParent);
	bool __fastcall IsLockedStatePaint(/* out */ Cxgraphics::TcxBitmap32* &ALockedStateImage);
	void __fastcall PostBoundsChanged(void);
	virtual void __fastcall UpdateSize(void);
	__property TcxCustomGridController* Controller = {read=GetController};
	__property bool IgnoreUpdateLock = {read=FIgnoreUpdateLock, write=FIgnoreUpdateLock, nodefault};
	__property TcxCustomGridPainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual TcxGridSite(TcxCustomGridViewInfo* AViewInfo);
	__fastcall virtual ~TcxGridSite(void);
	DYNAMIC void __fastcall BeginDragAndDrop(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall SetFocus(void);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	__property Cxcontrols::TcxControl* Container = {read=GetContainer};
	__property TcxCustomGridView* GridView = {read=GetGridView};
	__property HScrollBar;
	__property HScrollBarVisible;
	__property Keys;
	__property bool Locked = {read=GetLocked, nodefault};
	__property MouseCapture;
	__property TcxCustomGridViewInfo* ViewInfo = {read=FViewInfo};
	__property VScrollBar;
	__property VScrollBarVisible;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridSite(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(void){ return Cxcontrols::TcxControl::CanFocusOnClick(); }
	
private:
	void *__IcxEditorFieldLink;	/* Cxedit::IcxEditorFieldLink */
	void *__IcxLockedStatePaint;	/* Cxcontrols::IcxLockedStatePaint */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E21A0DDE-85DF-42CC-9063-D9E5DF45F02F}
	operator Cxedit::_di_IcxEditorFieldLink()
	{
		Cxedit::_di_IcxEditorFieldLink intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditorFieldLink*(void) { return (Cxedit::IcxEditorFieldLink*)&__IcxEditorFieldLink; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EB45AB76-3681-4838-BDA8-7D0081B4C184}
	operator Cxcontrols::_di_IcxLockedStatePaint()
	{
		Cxcontrols::_di_IcxLockedStatePaint intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxLockedStatePaint*(void) { return (Cxcontrols::IcxLockedStatePaint*)&__IcxLockedStatePaint; }
	#endif
	
};


typedef System::TMetaClass* TcxGridSiteClass;

typedef System::TMetaClass* TcxCustomGridCellViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridCellViewInfo : public Dxcoreclasses::TcxOwnedInterfacedPersistent
{
	typedef Dxcoreclasses::TcxOwnedInterfacedPersistent inherited;
	
private:
	bool FCalculated;
	bool FCalculatingParams;
	System::Classes::TAlignment FAlignmentHorz;
	Cxclasses::TcxAlignmentVert FAlignmentVert;
	Cxgraphics::TcxBorders FBorders;
	bool FIsDestroying;
	TcxCustomGridHitTest* FLinkedHitTest;
	bool FParamsCalculated;
	Cxgridcommon::TcxGridCellState FState;
	System::UnicodeString FText;
	bool FVisible;
	int __fastcall GetBorderSize(Cxgraphics::TcxBorder AIndex);
	Cxlookandfeelpainters::TcxButtonState __fastcall GetButtonState(void);
	System::Types::TRect __fastcall GetClientBounds(void);
	System::Types::TRect __fastcall GetContentBounds(void);
	System::Types::TRect __fastcall GetTextBoundsValue(void);
	int __fastcall GetTextHeight(void);
	int __fastcall GetTextHeightWithOffset(void);
	int __fastcall GetTextWidth(void);
	int __fastcall GetTextWidthWithOffset(void);
	void __fastcall SetLinkedHitTest(TcxCustomGridHitTest* Value);
	void __fastcall SetState(Cxgridcommon::TcxGridCellState Value);
	
protected:
	System::Types::TRect FClientBounds;
	System::Types::TRect FContentBounds;
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall MouseLeave(void);
	virtual bool __fastcall PtInCaller(const System::Types::TPoint &P);
	bool __fastcall ClosePopupWhenNilOwner(void);
	System::Types::TRect __fastcall GetOwnerBounds(void);
	void __fastcall PopupClosed(void);
	virtual void __fastcall AfterCalculateBounds(System::Types::TRect &ABounds);
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall BeforeCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall BeforeStateChange(void);
	virtual System::Types::TRect __fastcall CalculateClientBounds(void);
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	int __fastcall CalculateTextWidth(int AAngle = 0x0);
	int __fastcall CalculateTextHeight(bool AForPainting, int AAngle = 0x0);
	void __fastcall CalculateParams(void);
	void __fastcall CalculateParamsNeeded(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual void __fastcall Click(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall CustomDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Destroying(void);
	virtual void __fastcall DoCalculateParams(void);
	virtual void __fastcall DoInvalidate(void);
	virtual bool __fastcall DoCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall DoCustomDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxgridcommon::TcxGridCellState __fastcall GetActualState(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual System::Types::TRect __fastcall GetAreaBounds(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual System::Types::TRect __fastcall GetBorderBounds(Cxgraphics::TcxBorder AIndex);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	System::Types::TRect __fastcall GetBounds(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void) = 0 ;
	__classmethod virtual int __fastcall GetCellHeight(int ATextHeight, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	virtual int __fastcall GetContentHeight(void);
	virtual int __fastcall GetContentWidth(void);
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	virtual System::Types::TRect __fastcall GetDesignSelectionBounds(void);
	virtual int __fastcall GetDesignSelectionWidth(void);
	virtual Cxgraphics::TcxRotationAngle __fastcall GetDrawTextRotationAngle(void);
	virtual int __fastcall GetHeight(void);
	virtual TcxCustomGridHitTestClass __fastcall GetHitTestClass(void) = 0 ;
	virtual bool __fastcall GetHotTrack(void);
	virtual bool __fastcall GetIsCheck(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual bool __fastcall GetIsVisibleForPainting(void);
	virtual bool __fastcall GetMouseCapture(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual bool __fastcall GetMultiLinePainting(void);
	virtual TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetRealBounds(void);
	virtual bool __fastcall GetShowEndEllipsis(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual int __fastcall GetTextAttributes(bool AForPainting);
	System::Types::TRect __fastcall GetTextBounds(bool AHorizontal, bool AVertical);
	virtual int __fastcall GetTextCellHeight(TcxCustomGridViewInfo* AGridViewInfo, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	virtual System::UnicodeString __fastcall GetTextForPainting(void);
	virtual bool __fastcall GetTransparent(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall GetVisibleForHitTest(void);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall HasCustomDraw(void);
	virtual bool __fastcall HasCustomDrawBackground(void);
	virtual bool __fastcall HasDesignPopupMenu(void);
	virtual bool __fastcall HasHitTestPoint(const System::Types::TPoint &P);
	virtual bool __fastcall HasMouse(TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall InitHitTest(TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall InvalidateOnStateChange(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall PopulateDesignPopupMenu(Vcl::Menus::TPopupMenu* APopupMenu);
	virtual void __fastcall RestoreParams(const Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall SaveParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetMouseCapture(bool Value);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall StateChanged(Cxgridcommon::TcxGridCellState APrevState);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall CloseUp(void);
	virtual bool __fastcall CloseDropDownWindowOnDestruction(void);
	virtual bool __fastcall DropDownWindowExists(void);
	virtual TcxCustomGridPopup* __fastcall GetDropDownWindow(void);
	virtual System::Types::TRect __fastcall GetDropDownWindowOwnerBounds(void);
	virtual bool __fastcall IsDropDownWindowOwner(void);
	__property TcxCustomGridPopup* DropDownWindow = {read=GetDropDownWindow};
	__property int BorderWidth[Cxgraphics::TcxBorder AIndex] = {read=GetBorderWidth};
	__property bool CalculatingParams = {read=FCalculatingParams, nodefault};
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property Cxcontrols::TcxControl* Control = {read=GetControl};
	__property System::Types::TRect DesignSelectionBounds = {read=GetDesignSelectionBounds};
	__property int DesignSelectionWidth = {read=GetDesignSelectionWidth, nodefault};
	__property bool HotTrack = {read=GetHotTrack, nodefault};
	__property bool IsCheck = {read=GetIsCheck, nodefault};
	__property bool IsDesignSelected = {read=GetIsDesignSelected, nodefault};
	__property bool IsDestroying = {read=FIsDestroying, nodefault};
	__property bool IsVisibleForPainting = {read=GetIsVisibleForPainting, nodefault};
	__property TcxCustomGridHitTest* LinkedHitTest = {read=FLinkedHitTest, write=SetLinkedHitTest};
	__property bool ShowEndEllipsis = {read=GetShowEndEllipsis, nodefault};
	
public:
	System::Types::TRect Bounds;
	bool MultiLine;
	bool MultiLinePainting;
	Cxgraphics::TcxViewParams Params;
	__fastcall TcxCustomGridCellViewInfo(void);
	__fastcall virtual ~TcxCustomGridCellViewInfo(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall AfterRecalculation(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds)/* overload */;
	virtual System::Types::TRect __fastcall GetAreaBoundsForPainting(void);
	virtual int __fastcall GetBestFitWidth(void);
	virtual TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual bool __fastcall HasPoint(const System::Types::TPoint &P);
	virtual void __fastcall Invalidate(void);
	virtual bool __fastcall MouseDown(TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall MouseMove(TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	virtual bool __fastcall MouseUp(TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	void __fastcall DoOffset(int DX, int DY);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas = (Cxgraphics::TcxCanvas*)(0x0));
	void __fastcall Recalculate(void);
	void __fastcall ResetContentBounds(void);
	void __fastcall Update(void);
	__property Cxgridcommon::TcxGridCellState ActualState = {read=GetActualState, nodefault};
	__property System::Classes::TAlignment AlignmentHorz = {read=FAlignmentHorz, write=FAlignmentHorz, nodefault};
	__property Cxclasses::TcxAlignmentVert AlignmentVert = {read=FAlignmentVert, write=FAlignmentVert, nodefault};
	__property Vcl::Graphics::TBitmap* BackgroundBitmap = {read=GetBackgroundBitmap};
	__property System::Types::TRect BorderBounds[Cxgraphics::TcxBorder AIndex] = {read=GetBorderBounds};
	__property System::Uitypes::TColor BorderColor[Cxgraphics::TcxBorder AIndex] = {read=GetBorderColor};
	__property int BorderSize[Cxgraphics::TcxBorder AIndex] = {read=GetBorderSize};
	__property Cxgraphics::TcxBorders Borders = {read=FBorders, write=FBorders, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState ButtonState = {read=GetButtonState, nodefault};
	__property bool Calculated = {read=FCalculated, write=FCalculated, nodefault};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
	__property int ContentHeight = {read=GetContentHeight, nodefault};
	__property int ContentWidth = {read=GetContentWidth, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property bool MouseCapture = {read=GetMouseCapture, write=SetMouseCapture, nodefault};
	__property System::Types::TRect RealBounds = {read=GetRealBounds};
	__property Cxgridcommon::TcxGridCellState State = {read=FState, write=SetState, nodefault};
	__property System::UnicodeString Text = {read=FText, write=FText};
	__property System::Types::TRect TextBounds = {read=GetTextBoundsValue};
	__property System::UnicodeString TextForPainting = {read=GetTextForPainting};
	__property int TextHeightWithOffset = {read=GetTextHeightWithOffset, nodefault};
	__property int TextWidthWithOffset = {read=GetTextWidthWithOffset, nodefault};
	__property int TextHeight = {read=GetTextHeight, nodefault};
	__property int TextWidth = {read=GetTextWidth, nodefault};
	__property System::Types::TRect TextAreaBounds = {read=GetTextAreaBounds};
	__property bool Transparent = {read=GetTransparent, nodefault};
	__property bool Visible = {read=GetVisible, write=FVisible, nodefault};
	__property bool VisibleForHitTest = {read=GetVisibleForHitTest, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
private:
	void *__IcxCustomGridPopupOwner;	/* IcxCustomGridPopupOwner */
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	void *__IcxMouseCaptureObject;	/* Cxcontrols::IcxMouseCaptureObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {ACF62D23-6871-4735-A4CE-3B0888DB8FC3}
	operator _di_IcxCustomGridPopupOwner()
	{
		_di_IcxCustomGridPopupOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxCustomGridPopupOwner*(void) { return (IcxCustomGridPopupOwner*)&__IcxCustomGridPopupOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {ACB73657-6066-4564-9A3D-D4D0273AA82F}
	operator Cxcontrols::_di_IcxMouseCaptureObject()
	{
		Cxcontrols::_di_IcxMouseCaptureObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseCaptureObject*(void) { return (Cxcontrols::IcxMouseCaptureObject*)&__IcxMouseCaptureObject; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewCellViewInfo : public TcxCustomGridCellViewInfo
{
	typedef TcxCustomGridCellViewInfo inherited;
	
private:
	TcxCustomGridViewInfo* FGridViewInfo;
	TcxCustomGridController* __fastcall GetController(void);
	TcxCustomGridView* __fastcall GetGridView(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual void __fastcall AfterCalculateBounds(System::Types::TRect &ABounds);
	virtual void __fastcall DoInvalidate(void);
	virtual bool __fastcall EmulateMouseMoveAfterCalculate(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	virtual bool __fastcall HasMouse(TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall InitHitTest(TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall IsHintAtMousePos(void);
	virtual bool __fastcall UseHintHidePause(void);
	virtual bool __fastcall HasHintPoint(const System::Types::TPoint &P);
	virtual bool __fastcall CanShowHint(void);
	void __fastcall CheckHint(TcxCustomGridHitTest* AHitTest);
	virtual System::Types::TRect __fastcall GetAreaBoundsForHint(void);
	System::Types::TRect __fastcall GetBoundsForHint(void);
	virtual System::Types::TRect __fastcall GetCellBoundsForHint(void);
	virtual System::UnicodeString __fastcall GetHintText(void);
	virtual System::Types::TRect __fastcall GetHintTextRect(const System::Types::TPoint &AMousePos);
	virtual void __fastcall InitHint(const System::Types::TPoint &AMousePos, /* out */ Vcl::Controls::TCaption &AHintText, /* out */ bool &AIsHintMultiLine, /* out */ System::Types::TRect &ATextRect);
	virtual bool __fastcall IsHintForText(void);
	virtual bool __fastcall IsHintMultiLine(void);
	virtual bool __fastcall NeedShowHint(const System::Types::TPoint &AMousePos, /* out */ Vcl::Controls::TCaption &AHintText, /* out */ bool &AIsHintMultiLine, /* out */ System::Types::TRect &ATextRect);
	__property TcxCustomGridController* Controller = {read=GetController};
	
public:
	__fastcall virtual TcxCustomGridViewCellViewInfo(TcxCustomGridViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxCustomGridViewCellViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Invalidate(void);
	virtual bool __fastcall MouseMove(TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	__property TcxCustomGridView* GridView = {read=GetGridView};
	__property TcxCustomGridViewInfo* GridViewInfo = {read=FGridViewInfo};
	__property System::UnicodeString HintText = {read=GetHintText};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
private:
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {228FF1F5-6D0C-40F0-9F7B-8C71CE12CEC8}
	operator Dxcustomhint::_di_IcxHintableObject()
	{
		Dxcustomhint::_di_IcxHintableObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomhint::IcxHintableObject*(void) { return (Dxcustomhint::IcxHintableObject*)&__IcxHintableObject; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridDesignSelectorViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDesignSelectorViewInfo : public TcxCustomGridViewCellViewInfo
{
	typedef TcxCustomGridViewCellViewInfo inherited;
	
private:
	Cxgraphics::TcxRegion* FRegion;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	void __fastcall CreateRegion(void);
	void __fastcall DestroyRegion(void);
	__property Cxgraphics::TcxRegion* Region = {read=FRegion};
	
public:
	__fastcall virtual ~TcxGridDesignSelectorViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall HasPoint(const System::Types::TPoint &P);
	virtual bool __fastcall MouseDown(TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
public:
	/* TcxCustomGridViewCellViewInfo.Create */ inline __fastcall virtual TcxGridDesignSelectorViewInfo(TcxCustomGridViewInfo* AGridViewInfo) : TcxCustomGridViewCellViewInfo(AGridViewInfo) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewInfo : public TcxGridViewHandler
{
	typedef TcxGridViewHandler inherited;
	
private:
	Dxcoreclasses::TdxFastList* FActiveViewInfos;
	bool FAllowCheckCoordinates;
	bool FAllowHideSite;
	System::Types::TRect FBounds;
	System::Types::TRect FClientBounds;
	bool FClientBoundsAssigned;
	TcxGridDesignSelectorViewInfo* FDesignSelectorViewInfo;
	bool FIsCalculating;
	bool FIsInternalUse;
	_RTL_CRITICAL_SECTION FLock;
	System::Types::TPoint FMousePos;
	TcxGridSite* FSite;
	bool FSizeCalculating;
	bool FVisibilityChanging;
	bool __fastcall GetCalculated(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	System::Types::TRect __fastcall GetClientBounds(void);
	int __fastcall GetClientHeight(void);
	int __fastcall GetClientWidth(void);
	bool __fastcall GetIsInternalUseValue(void);
	void __fastcall SetClientBounds(const System::Types::TRect &Value);
	
protected:
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(bool AIsRecreating);
	virtual void __fastcall RecreateViewInfos(void);
	virtual TcxGridDesignSelectorViewInfoClass __fastcall GetDesignSelectorViewInfoClass(void);
	virtual bool __fastcall CanHideSite(void);
	void __fastcall CreateSite(void);
	void __fastcall DestroySite(void);
	virtual TcxGridSiteClass __fastcall GetSiteClass(void);
	Vcl::Controls::TWinControl* __fastcall GetSiteParent(void);
	void __fastcall AddActiveViewInfo(System::TObject* AViewInfo);
	bool __fastcall IsViewInfoActive(System::TObject* AViewInfo);
	void __fastcall RemoveActiveViewInfo(System::TObject* AViewInfo, bool ARemoveAll = false);
	void __fastcall AddScrollBarHeight(int &AHeight);
	virtual void __fastcall AdjustClientBounds(System::Types::TRect &ABounds);
	virtual int __fastcall GetBottomNonClientHeight(void);
	virtual int __fastcall GetRightNonClientWidth(void);
	virtual void __fastcall AfterCalculating(void);
	virtual void __fastcall BeforeCalculating(void);
	virtual void __fastcall Calculate(void);
	virtual System::Types::TRect __fastcall CalculateClientBounds(void);
	virtual void __fastcall CalculateHeight(const System::Types::TPoint &AMaxSize, int &AHeight, bool &AFullyVisible);
	virtual void __fastcall CalculateWidth(const System::Types::TPoint &AMaxSize, int &AWidth);
	virtual bool __fastcall CanCheckCoordinates(void);
	virtual bool __fastcall CanHandleDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual void __fastcall ControlFocusChanged(void);
	virtual TcxCustomGridHitTest* __fastcall DoGetHitTest(const System::Types::TPoint &P);
	virtual bool __fastcall GetAllowBoundsChangedNotification(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	virtual System::Types::TRect __fastcall GetContentBounds(void);
	virtual System::Types::TPoint __fastcall GetDesignSelectorPos(void);
	virtual void __fastcall GetHScrollBarBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall GetIsInternalUse(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall InitHitTest(TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	virtual bool __fastcall SiteCanBeClipped(void);
	void __fastcall UpdateMousePos(void);
	virtual void __fastcall VisibilityChanged(bool AVisible);
	__property bool AllowBoundsChangedNotification = {read=GetAllowBoundsChangedNotification, nodefault};
	__property bool AllowCheckCoordinates = {read=FAllowCheckCoordinates, write=FAllowCheckCoordinates, nodefault};
	__property bool ClientBoundsAssigned = {read=FClientBoundsAssigned, write=FClientBoundsAssigned, nodefault};
	__property bool SizeCalculating = {read=FSizeCalculating, nodefault};
	__property bool VisibilityChanging = {read=FVisibilityChanging, nodefault};
	__property bool Visible = {read=GetVisible, nodefault};
	
public:
	__fastcall virtual TcxCustomGridViewInfo(TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridViewInfo(void);
	virtual void __fastcall BeforeDestruction(void);
	void __fastcall DoVisibilityChanged(bool AVisible);
	int __fastcall GetFontHeight(Vcl::Graphics::TFont* AFont);
	void __fastcall GetFontMetrics(Vcl::Graphics::TFont* AFont, /* out */ tagTEXTMETRICW &AMetrics);
	void __fastcall GetHeight(const System::Types::TPoint &AMaxSize, int &AHeight, bool &AFullyVisible);
	virtual TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P)/* overload */;
	virtual TcxCustomGridHitTest* __fastcall GetHitTest(int X, int Y)/* overload */;
	void __fastcall GetWidth(const System::Types::TPoint &AMaxSize, int &AWidth);
	void __fastcall MainCalculate(const System::Types::TRect &ABounds);
	void __fastcall Recalculate(void);
	__property bool AllowHideSite = {read=FAllowHideSite, write=FAllowHideSite, nodefault};
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	__property Vcl::Graphics::TBitmap* BackgroundBitmap = {read=GetBackgroundBitmap};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property bool Calculated = {read=GetCalculated, nodefault};
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds, write=SetClientBounds};
	__property int ClientHeight = {read=GetClientHeight, nodefault};
	__property int ClientWidth = {read=GetClientWidth, nodefault};
	__property TcxGridDesignSelectorViewInfo* DesignSelectorViewInfo = {read=FDesignSelectorViewInfo};
	__property bool IsCalculating = {read=FIsCalculating, nodefault};
	__property bool IsInternalUse = {read=GetIsInternalUseValue, write=FIsInternalUse, nodefault};
	__property System::Types::TPoint MousePos = {read=FMousePos};
	__property TcxGridSite* Site = {read=FSite};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridViewInfoCacheItemClass;

class DELPHICLASS TcxCustomGridViewInfoCacheItem;
class DELPHICLASS TcxCustomGridViewInfoCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewInfoCacheItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FIndex;
	TcxCustomGridViewInfoCache* FOwner;
	
protected:
	__property int Index = {read=FIndex, nodefault};
	__property TcxCustomGridViewInfoCache* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxCustomGridViewInfoCacheItem(TcxCustomGridViewInfoCache* AOwner, int AIndex);
	virtual void __fastcall UnassignValues(bool AKeepMaster);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridViewInfoCacheItem(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridViewInfoCacheClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewInfoCache : public TcxGridViewHandler
{
	typedef TcxGridViewHandler inherited;
	
public:
	TcxCustomGridViewInfoCacheItem* operator[](int Index) { return Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastObjectList* FItems;
	bool FUnassigningValues;
	int __fastcall GetCount(void);
	TcxCustomGridViewInfoCacheItem* __fastcall GetInternalItem(int Index);
	TcxCustomGridViewInfoCacheItem* __fastcall GetItem(int Index);
	void __fastcall SetCount(int Value);
	void __fastcall DestroyItems(void);
	
protected:
	virtual TcxCustomGridViewInfoCacheItemClass __fastcall GetItemClass(int Index) = 0 ;
	__property TcxCustomGridViewInfoCacheItem* InternalItems[int Index] = {read=GetInternalItem};
	
public:
	__fastcall virtual TcxCustomGridViewInfoCache(TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridViewInfoCache(void);
	virtual void __fastcall UnassignValues(bool AKeepMaster = false);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property TcxCustomGridViewInfoCacheItem* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

enum TcxGridViewChangeKind : unsigned char { vcProperty, vcLayout, vcSize };

class DELPHICLASS TcxCustomGridOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridOptions : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxCustomGridView* FGridView;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual void __fastcall Changed(TcxGridViewChangeKind AChangeKind);
	virtual TcxCustomGridView* __fastcall GetGridViewValue(void);
	bool __fastcall IsLoading(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	virtual void __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
public:
	__fastcall virtual TcxCustomGridOptions(TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomGridView* GridView = {read=GetGridViewValue};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridBackgroundBitmapsClass;

class DELPHICLASS TcxCustomGridBackgroundBitmaps;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridBackgroundBitmaps : public TcxCustomGridOptions
{
	typedef TcxCustomGridOptions inherited;
	
public:
	Vcl::Graphics::TBitmap* operator[](int Index) { return Values[Index]; }
	
private:
	Dxcoreclasses::TdxFastObjectList* FItems;
	int __fastcall GetCount(void);
	void __fastcall BitmapChanged(System::TObject* Sender);
	
protected:
	virtual int __fastcall GetBitmapStyleIndex(int Index);
	virtual Vcl::Graphics::TBitmap* __fastcall GetDefaultBitmap(int Index);
	Vcl::Graphics::TBitmap* __fastcall GetValue(int Index);
	void __fastcall SetValue(int Index, Vcl::Graphics::TBitmap* Value);
	__property int Count = {read=GetCount, nodefault};
	
public:
	__fastcall virtual TcxCustomGridBackgroundBitmaps(TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridBackgroundBitmaps(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBitmap(int Index);
	__property Vcl::Graphics::TBitmap* Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
	
__published:
	__property Vcl::Graphics::TBitmap* Background = {read=GetValue, write=SetValue, index=0};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridShowLockedStateImageOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridShowLockedStateImageOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	__fastcall virtual TcxCustomGridShowLockedStateImageOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridShowLockedStateImageOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridShowLockedStateImageOptionsClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridOptionsBehavior : public TcxCustomGridOptions
{
	typedef TcxCustomGridOptions inherited;
	
private:
	int FHintHidePause;
	TcxCustomGridShowLockedStateImageOptions* FShowLockedStateImageOptions;
	bool FPostponedSynchronization;
	bool FShowHourglassCursor;
	bool FSuppressHintOnMouseDown;
	bool __fastcall GetPostponedSynchronization(void);
	void __fastcall SetShowLockedStateImageOptions(TcxCustomGridShowLockedStateImageOptions* Value);
	
protected:
	virtual TcxCustomGridShowLockedStateImageOptionsClass __fastcall GetShowLockedStateImageOptionsClass(void);
	__property int HintHidePause = {read=FHintHidePause, write=FHintHidePause, default=0};
	__property bool ShowHourglassCursor = {read=FShowHourglassCursor, write=FShowHourglassCursor, default=1};
	__property TcxCustomGridShowLockedStateImageOptions* ShowLockedStateImageOptions = {read=FShowLockedStateImageOptions, write=SetShowLockedStateImageOptions};
	__property bool SuppressHintOnMouseDown = {read=FSuppressHintOnMouseDown, write=FSuppressHintOnMouseDown, default=1};
	
public:
	__fastcall virtual TcxCustomGridOptionsBehavior(TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridOptionsBehavior(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool PostponedSynchronization = {read=GetPostponedSynchronization, write=FPostponedSynchronization, default=1};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridOptionsBehaviorClass;

class DELPHICLASS TcxCustomGridOptionsData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridOptionsData : public TcxCustomGridOptions
{
	typedef TcxCustomGridOptions inherited;
	
public:
	/* TcxCustomGridOptions.Create */ inline __fastcall virtual TcxCustomGridOptionsData(TcxCustomGridView* AGridView) : TcxCustomGridOptions(AGridView) { }
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridOptionsData(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridOptionsDataClass;

class DELPHICLASS TcxCustomGridOptionsSelection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridOptionsSelection : public TcxCustomGridOptions
{
	typedef TcxCustomGridOptions inherited;
	
public:
	/* TcxCustomGridOptions.Create */ inline __fastcall virtual TcxCustomGridOptionsSelection(TcxCustomGridView* AGridView) : TcxCustomGridOptions(AGridView) { }
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridOptionsSelection(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridOptionsSelectionClass;

class DELPHICLASS TcxCustomGridOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridOptionsView : public TcxCustomGridOptions
{
	typedef TcxCustomGridOptions inherited;
	
private:
	System::Uitypes::TScrollStyle __fastcall GetScrollBars(void);
	void __fastcall SetScrollBars(System::Uitypes::TScrollStyle Value);
	
protected:
	__property System::Uitypes::TScrollStyle ScrollBars = {read=GetScrollBars, write=SetScrollBars, default=3};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TcxCustomGridOptions.Create */ inline __fastcall virtual TcxCustomGridOptionsView(TcxCustomGridView* AGridView) : TcxCustomGridOptions(AGridView) { }
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridOptionsView(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridOptionsViewClass;

class DELPHICLASS TcxCustomGridStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	bool __fastcall GetIsSkinsAvailable(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	virtual TcxCustomGridView* __fastcall GetGridView(void) = 0 ;
	__property bool IsSkinsAvailable = {read=GetIsSkinsAvailable, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
public:
	__property TcxCustomGridView* GridView = {read=GetGridView};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxCustomGridStyles(System::Classes::TPersistent* AOwner) : Cxstyles::TcxStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxCustomGridStyles(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridViewStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewStyles : public TcxCustomGridStyles
{
	typedef TcxCustomGridStyles inherited;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual TcxCustomGridView* __fastcall GetGridView(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Cxstyles::TcxStyle* Background = {read=GetValue, write=SetValue, index=0};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxCustomGridViewStyles(System::Classes::TPersistent* AOwner) : TcxCustomGridStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxCustomGridViewStyles(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridViewStylesClass;

class DELPHICLASS TcxGridListenerLink;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridListenerLink : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomGridView* FGridView;
	
public:
	__fastcall TcxGridListenerLink(TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxGridListenerLink(void);
	void __fastcall Clear(void);
	__property TcxCustomGridView* GridView = {read=FGridView};
};

#pragma pack(pop)

class DELPHICLASS TcxGridViewNotificationList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewNotificationList : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	Cxcustomdata::TcxUpdateControlInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomGridView* FGridView;
	HIDESBASE Cxcustomdata::TcxUpdateControlInfo* __fastcall GetItem(int Index);
	
public:
	__fastcall TcxGridViewNotificationList(TcxCustomGridView* AGridView);
	HIDESBASE void __fastcall Add(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	__property Cxcustomdata::TcxUpdateControlInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TcxGridViewNotificationList(void) { }
	
};

#pragma pack(pop)

enum TcxGridStorageOption : unsigned char { gsoUseFilter, gsoUseSummary };

typedef System::Set<TcxGridStorageOption, TcxGridStorageOption::gsoUseFilter, TcxGridStorageOption::gsoUseSummary>  TcxGridStorageOptions;

enum TcxGridViewChangeNotificationKind : unsigned char { vcnName };

typedef void __fastcall (__closure *TcxGridInitStoredObjectEvent)(TcxCustomGridView* Sender, System::TObject* AObject);

typedef void __fastcall (__closure *TcxGridViewGetStoredPropertiesEvent)(TcxCustomGridView* Sender, System::Classes::TStrings* AProperties);

typedef void __fastcall (__closure *TcxGridViewGetStoredPropertyValueEvent)(TcxCustomGridView* Sender, const System::UnicodeString AName, System::Variant &AValue);

typedef void __fastcall (__closure *TcxGridViewSetStoredPropertyValueEvent)(TcxCustomGridView* Sender, const System::UnicodeString AName, const System::Variant &AValue);

typedef System::TMetaClass* TcxCustomGridViewClass;

class PASCALIMPLEMENTATION TcxCustomGridView : public Cxcontrols::TcxControlChildComponent
{
	typedef Cxcontrols::TcxControlChildComponent inherited;
	
private:
	bool FAssigningPattern;
	bool FAssigningSettings;
	TcxCustomGridBackgroundBitmaps* FBackgroundBitmaps;
	Dxcoreclasses::TdxFastList* FClones;
	TcxCustomGridController* FController;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	bool FIsChangeNotificationForControllerNeeded;
	bool FIsCustomizationFormRefreshNeeded;
	bool FIsRestoring;
	bool FIsSynchronizing;
	System::Classes::TComponent* FLevel;
	System::Classes::TList* FListenerLinks;
	TcxGridViewNotificationList* FNotifications;
	System::Classes::TList* FOptionsList;
	TcxCustomGridOptionsBehavior* FOptionsBehavior;
	TcxCustomGridOptionsData* FOptionsData;
	TcxCustomGridOptionsSelection* FOptionsSelection;
	TcxCustomGridOptionsView* FOptionsView;
	TcxCustomGridPainter* FPainter;
	TcxCustomGridView* FPatternGridView;
	System::Classes::TComponent* FRepository;
	Cxcontrols::TcxControl* FStorageControl;
	TcxGridStorageOptions FStorageOptions;
	int FStoredVersion;
	System::UnicodeString FStoringName;
	TcxCustomGridStyles* FStyles;
	bool FSynchronization;
	bool FSynchronizationAssignNeeded;
	bool FSynchronizationNeeded;
	int FUpdateLockCount;
	TcxCustomGridViewData* FViewData;
	TcxCustomGridViewInfo* FViewInfo;
	TcxCustomGridViewInfoCache* FViewInfoCache;
	System::Classes::TNotifyEvent FOnCustomization;
	TcxGridViewGetStoredPropertiesEvent FOnGetStoredProperties;
	TcxGridViewGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	TcxGridInitStoredObjectEvent FOnInitStoredObject;
	TcxGridViewSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	TcxCustomGridView* __fastcall GetClone(int Index);
	int __fastcall GetCloneCount(void);
	System::Uitypes::TDragMode __fastcall GetDragMode(void);
	bool __fastcall GetFocused(void);
	bool __fastcall GetIsControlFocusedValue(void);
	bool __fastcall GetIsDetail(void);
	bool __fastcall GetIsExportMode(void);
	bool __fastcall GetIsMaster(void);
	bool __fastcall GetIsPattern(void);
	bool __fastcall GetIsStoringNameMode(void);
	bool __fastcall GetIsUpdating(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	TcxCustomGridView* __fastcall GetMasterGridView(void);
	int __fastcall GetMasterGridRecordIndex(void);
	int __fastcall GetMasterRecordIndex(void);
	System::Classes::TNotifyEvent __fastcall GetOnDblClick(void);
	Vcl::Controls::TDragDropEvent __fastcall GetOnDragDrop(void);
	Vcl::Controls::TDragOverEvent __fastcall GetOnDragOver(void);
	Vcl::Controls::TEndDragEvent __fastcall GetOnEndDrag(void);
	Vcl::Controls::TKeyEvent __fastcall GetOnKeyDown(void);
	Vcl::Controls::TKeyPressEvent __fastcall GetOnKeyPress(void);
	Vcl::Controls::TKeyEvent __fastcall GetOnKeyUp(void);
	Vcl::Controls::TMouseEvent __fastcall GetOnMouseDown(void);
	System::Classes::TNotifyEvent __fastcall GetOnMouseEnter(void);
	System::Classes::TNotifyEvent __fastcall GetOnMouseLeave(void);
	Vcl::Controls::TMouseMoveEvent __fastcall GetOnMouseMove(void);
	Vcl::Controls::TMouseEvent __fastcall GetOnMouseUp(void);
	Vcl::Controls::TMouseWheelEvent __fastcall GetOnMouseWheel(void);
	Vcl::Controls::TMouseWheelUpDownEvent __fastcall GetOnMouseWheelDown(void);
	Vcl::Controls::TMouseWheelUpDownEvent __fastcall GetOnMouseWheelUp(void);
	Vcl::Controls::TStartDragEvent __fastcall GetOnStartDrag(void);
	TcxCustomGridView* __fastcall GetPatternGridView(void);
	System::Classes::TComponent* __fastcall GetPopupMenu(void);
	TcxGridSite* __fastcall GetSite(void);
	bool __fastcall GetSynchronization(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetBackgroundBitmaps(TcxCustomGridBackgroundBitmaps* Value);
	void __fastcall SetDragMode(System::Uitypes::TDragMode Value);
	void __fastcall SetFocused(bool Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetIsRestoring(bool Value);
	void __fastcall SetSynchronization(bool Value);
	void __fastcall SetOnCustomization(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnDblClick(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnDragDrop(Vcl::Controls::TDragDropEvent Value);
	void __fastcall SetOnDragOver(Vcl::Controls::TDragOverEvent Value);
	void __fastcall SetOnEndDrag(Vcl::Controls::TEndDragEvent Value);
	void __fastcall SetOnGetStoredProperties(TcxGridViewGetStoredPropertiesEvent Value);
	void __fastcall SetOnGetStoredPropertyValue(TcxGridViewGetStoredPropertyValueEvent Value);
	void __fastcall SetOnInitStoredObject(TcxGridInitStoredObjectEvent Value);
	void __fastcall SetOnKeyDown(Vcl::Controls::TKeyEvent Value);
	void __fastcall SetOnKeyPress(Vcl::Controls::TKeyPressEvent Value);
	void __fastcall SetOnKeyUp(Vcl::Controls::TKeyEvent Value);
	void __fastcall SetOnMouseDown(Vcl::Controls::TMouseEvent Value);
	void __fastcall SetOnMouseEnter(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnMouseLeave(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnMouseMove(Vcl::Controls::TMouseMoveEvent Value);
	void __fastcall SetOnMouseUp(Vcl::Controls::TMouseEvent Value);
	void __fastcall SetOnMouseWheel(Vcl::Controls::TMouseWheelEvent Value);
	void __fastcall SetOnMouseWheelDown(Vcl::Controls::TMouseWheelUpDownEvent Value);
	void __fastcall SetOnMouseWheelUp(Vcl::Controls::TMouseWheelUpDownEvent Value);
	void __fastcall SetOnSetStoredPropertyValue(TcxGridViewSetStoredPropertyValueEvent Value);
	void __fastcall SetOnStartDrag(Vcl::Controls::TStartDragEvent Value);
	void __fastcall SetOptionsBehavior(TcxCustomGridOptionsBehavior* Value);
	void __fastcall SetOptionsData(TcxCustomGridOptionsData* Value);
	void __fastcall SetOptionsSelection(TcxCustomGridOptionsSelection* Value);
	void __fastcall SetOptionsView(TcxCustomGridOptionsView* Value);
	void __fastcall SetPopupMenu(System::Classes::TComponent* Value);
	void __fastcall SetStyles(TcxCustomGridStyles* Value);
	void __fastcall ClearListenerLinks(void);
	void __fastcall ClearNotifications(void);
	
protected:
	Cxcustomdata::TcxCustomDataController* FDataController;
	System::Classes::TNotifyEvent FSubClassEvents;
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual System::TObject* __fastcall CreateStoredObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual void __fastcall InitChildComponent(System::TObject* AObject, const System::UnicodeString AObjectName);
	virtual void __fastcall AssignLayout(TcxCustomGridView* ALayoutView);
	virtual void __fastcall BeforeEditLayout(TcxCustomGridView* ALayoutView);
	virtual bool __fastcall CanEditViewLayoutAndData(void);
	void __fastcall DoAssignLayout(TcxCustomGridView* ALayoutView);
	virtual System::UnicodeString __fastcall GetLayoutCustomizationFormButtonCaption(void);
	virtual bool __fastcall HasLayoutCustomizationForm(void);
	virtual bool __fastcall IsLayoutChangeable(void);
	virtual void __fastcall RunLayoutCustomizationForm(void);
	virtual bool __fastcall ShowGridViewEditor(void);
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	virtual bool __fastcall GetIsDestroying(void);
	virtual System::Uitypes::TScrollStyle __fastcall GetSystemSizeScrollBars(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetControl(Cxcontrols::TcxControl* Value);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall Updated(void);
	DYNAMIC void __fastcall Updating(void);
	virtual void __fastcall CreateHandlers(void);
	virtual void __fastcall DestroyHandlers(void);
	virtual void __fastcall InitDataController(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	void __fastcall AddOptions(TcxCustomGridOptions* AOptions);
	void __fastcall RemoveOptions(TcxCustomGridOptions* AOptions);
	void __fastcall NotifyOptions(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	void __fastcall AddClone(TcxCustomGridView* AClone);
	void __fastcall RemoveClone(TcxCustomGridView* AClone);
	TcxGridListenerLink* __fastcall AddListenerLink(void);
	void __fastcall RemoveListenerLink(TcxGridListenerLink* ALink);
	void __fastcall GridBeginUpdate(TcxGridShowLockedStateImageMode AShowLockedStateImage = (TcxGridShowLockedStateImageMode)(0x0));
	void __fastcall GridCancelUpdate(void);
	void __fastcall GridEndUpdate(void);
	void __fastcall GridBeginLockedStatePaint(TcxGridShowLockedStateImageMode AMode);
	void __fastcall GridEndLockedStatePaint(void);
	void __fastcall Synchronize(bool ACheckUpdateLock = true)/* overload */;
	void __fastcall Synchronize(TcxCustomGridView* AView)/* overload */;
	__property bool SynchronizationAssignNeeded = {read=FSynchronizationAssignNeeded, nodefault};
	__property bool SynchronizationNeeded = {read=FSynchronizationNeeded, nodefault};
	void __fastcall AssignPattern(TcxCustomGridView* APattern);
	virtual void __fastcall BeforeAssign(TcxCustomGridView* ASource);
	virtual void __fastcall DoAssign(TcxCustomGridView* ASource);
	virtual void __fastcall DoAssignSettings(TcxCustomGridView* ASource);
	virtual void __fastcall AfterAssign(TcxCustomGridView* ASource);
	__property bool AssigningPattern = {read=FAssigningPattern, nodefault};
	__property bool AssigningSettings = {read=FAssigningSettings, nodefault};
	virtual void __fastcall BeforeRestoring(void);
	virtual void __fastcall AfterRestoring(void);
	virtual void __fastcall RestoreFrom(const System::UnicodeString AStorageName, System::Classes::TStream* AStream, Cxstorage::TcxCustomReaderClass AReaderClass, bool AChildrenCreating, bool AChildrenDeleting, TcxGridStorageOptions AOptions, const System::UnicodeString ARestoreViewName, const System::UnicodeString AOwnerName = System::UnicodeString());
	void __fastcall StoreTo(const System::UnicodeString AStorageName, System::Classes::TStream* AStream, Cxstorage::TcxCustomWriterClass AWriterClass, bool AReCreate, TcxGridStorageOptions AOptions, const System::UnicodeString ASaveViewName, const System::UnicodeString AOwnerName = System::UnicodeString());
	__property bool IsRestoring = {read=FIsRestoring, write=SetIsRestoring, nodefault};
	void __fastcall AddNotification(Cxcustomdata::TcxUpdateControlInfo* AUpdateInfo);
	virtual bool __fastcall CanBeUsedAsDetail(void);
	virtual bool __fastcall CanBeUsedAsMaster(void);
	void __fastcall UnsupportedMasterDetailError(void);
	void __fastcall ValidateMasterDetailRelationship(bool AIsMaster);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanGetHitTest(void);
	virtual bool __fastcall CanTabStop(void);
	virtual void __fastcall Deactivate(void);
	virtual void __fastcall DestroyingSiteHandle(void);
	virtual void __fastcall DetailDataChanged(TcxCustomGridView* ADetail);
	virtual void __fastcall DetailVisibleChanged(System::Classes::TComponent* ADetailLevel, int APrevVisibleDetailCount, int AVisibleDetailCount);
	virtual void __fastcall DoChanged(TcxGridViewChangeKind AChangeKind);
	virtual void __fastcall DoUnlockNotification(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual bool __fastcall GetChangeable(void);
	virtual bool __fastcall GetCustomVisible(bool ALevelVisible);
	virtual bool __fastcall GetIsControlFocused(void);
	virtual bool __fastcall GetIsControlLocked(void);
	virtual bool __fastcall GetResizeOnBoundsChange(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall Init(void);
	virtual bool __fastcall IsDetailVisible(TcxCustomGridView* AGridView);
	virtual bool __fastcall IsRecordPixelScrolling(void);
	virtual void __fastcall FocusChanged(bool AFocused);
	virtual void __fastcall LoadingComplete(void);
	virtual void __fastcall LookAndFeelChanged(void);
	void __fastcall NotifyControl(TcxGridViewChangeNotificationKind AChangeKind);
	void __fastcall NotifyControllerAboutChange(void);
	virtual void __fastcall RestoringComplete(void);
	virtual void __fastcall ScrollContentByGesture(Vcl::Forms::TScrollBarKind AScrollKind, int ADelta);
	virtual void __fastcall SetLevel(System::Classes::TComponent* Value);
	virtual void __fastcall SetTabStop(bool Value);
	void __fastcall UnlockNotifications(void);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual void __fastcall UpdateUnlocked(void);
	virtual TcxCustomGridControllerClass __fastcall GetControllerClass(void) = 0 ;
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void) = 0 ;
	virtual TcxCustomGridPainterClass __fastcall GetPainterClass(void) = 0 ;
	virtual TcxCustomGridViewDataClass __fastcall GetViewDataClass(void) = 0 ;
	virtual TcxCustomGridViewInfoCacheClass __fastcall GetViewInfoCacheClass(void);
	virtual TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void) = 0 ;
	virtual TcxCustomGridBackgroundBitmapsClass __fastcall GetBackgroundBitmapsClass(void);
	virtual TcxCustomGridOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual TcxCustomGridOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual TcxCustomGridOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual TcxCustomGridViewStylesClass __fastcall GetStylesClass(void);
	virtual void __fastcall Initialize(void);
	void __fastcall RefreshCustomizationForm(void);
	virtual void __fastcall DoCustomization(void);
	virtual void __fastcall DoInitStoredObject(System::TObject* AObject);
	__property TcxCustomGridBackgroundBitmaps* BackgroundBitmaps = {read=FBackgroundBitmaps, write=SetBackgroundBitmaps};
	__property bool Changeable = {read=GetChangeable, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property bool IsExportMode = {read=GetIsExportMode, nodefault};
	__property bool IsStoringNameMode = {read=GetIsStoringNameMode, nodefault};
	__property bool IsSynchronizing = {read=FIsSynchronizing, nodefault};
	__property bool IsUpdating = {read=GetIsUpdating, nodefault};
	__property TcxCustomGridOptionsBehavior* OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior};
	__property TcxCustomGridOptionsData* OptionsData = {read=FOptionsData, write=SetOptionsData};
	__property TcxCustomGridOptionsSelection* OptionsSelection = {read=FOptionsSelection, write=SetOptionsSelection};
	__property TcxCustomGridOptionsView* OptionsView = {read=FOptionsView, write=SetOptionsView};
	__property bool ResizeOnBoundsChange = {read=GetResizeOnBoundsChange, nodefault};
	__property int StoredVersion = {read=FStoredVersion, nodefault};
	__property TcxCustomGridStyles* Styles = {read=FStyles, write=SetStyles};
	__property System::Classes::TNotifyEvent OnCustomization = {read=FOnCustomization, write=SetOnCustomization};
	__property TcxGridInitStoredObjectEvent OnInitStoredObject = {read=FOnInitStoredObject, write=SetOnInitStoredObject};
	
public:
	__fastcall virtual TcxCustomGridView(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TcxCustomGridView(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AssignSettings(TcxCustomGridView* ASource);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	bool __fastcall HasAsClone(TcxCustomGridView* AGridView);
	bool __fastcall HasAsMaster(TcxCustomGridView* AGridView);
	void __fastcall Invalidate(bool AHardUpdate = false);
	virtual void __fastcall RestoreDefaults(void);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	void __fastcall CheckSynchronizationAssignNeeded(void);
	bool __fastcall IsSynchronization(void);
	void __fastcall BeginUpdate(TcxGridShowLockedStateImageMode AShowLockedStateImage = (TcxGridShowLockedStateImageMode)(0x0));
	void __fastcall CancelUpdate(void);
	virtual bool __fastcall Changed(System::TObject* AGridChange)/* overload */;
	void __fastcall EndUpdate(void);
	bool __fastcall IsUpdateLocked(void);
	void __fastcall HideHourglassCursor(void);
	void __fastcall ShowHourglassCursor(void);
	virtual TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P)/* overload */;
	virtual TcxCustomGridHitTest* __fastcall GetHitTest(int X, int Y)/* overload */;
	virtual void __fastcall BoundsChanged(bool AUpdateSelfOnly = false, bool AKeepMaster = false);
	virtual void __fastcall Changed(TcxGridViewChangeKind AChangeKind)/* overload */;
	void __fastcall LayoutChanged(bool AUpdateSelfOnly = true);
	virtual bool __fastcall SizeChanged(bool AUpdateSelfOnly = false, bool AKeepMaster = false);
	virtual void __fastcall ViewChanged(void)/* overload */;
	virtual void __fastcall ViewChanged(const System::Types::TRect &AUpdateRect)/* overload */;
	virtual void __fastcall ViewChanged(Cxgraphics::TcxRegion* ARegion)/* overload */;
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName, bool AChildrenCreating = true, bool AChildrenDeleting = false, TcxGridStorageOptions AOptions = (TcxGridStorageOptions() << TcxGridStorageOption::gsoUseFilter << TcxGridStorageOption::gsoUseSummary ), const System::UnicodeString ARestoreViewName = System::UnicodeString(), const System::UnicodeString AOwnerName = System::UnicodeString());
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName, bool AChildrenCreating = true, bool AChildrenDeleting = false, TcxGridStorageOptions AOptions = (TcxGridStorageOptions() << TcxGridStorageOption::gsoUseFilter << TcxGridStorageOption::gsoUseSummary ), const System::UnicodeString ARestoreViewName = System::UnicodeString(), const System::UnicodeString AOwnerName = System::UnicodeString());
	void __fastcall RestoreFromStream(System::Classes::TStream* AStream, bool AChildrenCreating = true, bool AChildrenDeleting = false, TcxGridStorageOptions AOptions = (TcxGridStorageOptions() << TcxGridStorageOption::gsoUseFilter << TcxGridStorageOption::gsoUseSummary ), const System::UnicodeString ARestoreViewName = System::UnicodeString(), const System::UnicodeString AOwnerName = System::UnicodeString());
	void __fastcall RestoreFromStorage(const System::UnicodeString AStorageName, Cxstorage::TcxCustomReaderClass AReaderClass, bool AChildrenCreating = true, bool AChildrenDeleting = false, TcxGridStorageOptions AOptions = (TcxGridStorageOptions() << TcxGridStorageOption::gsoUseFilter << TcxGridStorageOption::gsoUseSummary ), const System::UnicodeString ARestoreViewName = System::UnicodeString(), const System::UnicodeString AOwnerName = System::UnicodeString());
	void __fastcall StoreToIniFile(const System::UnicodeString AStorageName, bool AReCreate = true, TcxGridStorageOptions AOptions = TcxGridStorageOptions() , const System::UnicodeString ASaveViewName = System::UnicodeString(), const System::UnicodeString AOwnerName = System::UnicodeString());
	void __fastcall StoreToRegistry(const System::UnicodeString AStorageName, bool AReCreate = true, TcxGridStorageOptions AOptions = TcxGridStorageOptions() , const System::UnicodeString ASaveViewName = System::UnicodeString(), const System::UnicodeString AOwnerName = System::UnicodeString());
	void __fastcall StoreToStream(System::Classes::TStream* AStream, TcxGridStorageOptions AOptions = TcxGridStorageOptions() , const System::UnicodeString ASaveViewName = System::UnicodeString(), const System::UnicodeString AOwnerName = System::UnicodeString());
	void __fastcall StoreToStorage(const System::UnicodeString AStorageName, Cxstorage::TcxCustomWriterClass AWriterClass, bool AReCreate = true, TcxGridStorageOptions AOptions = TcxGridStorageOptions() , const System::UnicodeString ASaveViewName = System::UnicodeString(), const System::UnicodeString AOwnerName = System::UnicodeString());
	TcxCustomGridViewInfo* __fastcall CreateViewInfo(void);
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property TcxGridStorageOptions StorageOptions = {read=FStorageOptions, write=FStorageOptions, nodefault};
	__property System::UnicodeString StoringName = {read=FStoringName, write=FStoringName};
	__property bool TabStop = {write=SetTabStop, nodefault};
	__property int CloneCount = {read=GetCloneCount, nodefault};
	__property TcxCustomGridView* Clones[int Index] = {read=GetClone};
	__property bool IsControlFocused = {read=GetIsControlFocusedValue, nodefault};
	__property bool IsControlLocked = {read=GetIsControlLocked, nodefault};
	__property bool IsDetail = {read=GetIsDetail, nodefault};
	__property bool IsMaster = {read=GetIsMaster, nodefault};
	__property bool IsPattern = {read=GetIsPattern, nodefault};
	__property System::Classes::TComponent* Level = {read=FLevel};
	__property TcxCustomGridView* MasterGridView = {read=GetMasterGridView};
	__property int MasterGridRecordIndex = {read=GetMasterGridRecordIndex, nodefault};
	__property int MasterRecordIndex = {read=GetMasterRecordIndex, nodefault};
	__property TcxCustomGridView* PatternGridView = {read=GetPatternGridView};
	__property System::Classes::TComponent* Repository = {read=FRepository, write=FRepository};
	__property TcxCustomGridController* Controller = {read=FController};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=FDataController};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TcxCustomGridPainter* Painter = {read=FPainter};
	__property TcxGridSite* Site = {read=GetSite};
	__property Cxcontrols::TcxControl* StorageControl = {read=FStorageControl};
	__property TcxCustomGridViewData* ViewData = {read=FViewData};
	__property TcxCustomGridViewInfo* ViewInfo = {read=FViewInfo};
	__property TcxCustomGridViewInfoCache* ViewInfoCache = {read=FViewInfoCache};
	__property bool Visible = {read=GetVisible, nodefault};
	
__published:
	__property System::Classes::TNotifyEvent DataControllerEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Uitypes::TDragMode DragMode = {read=GetDragMode, write=SetDragMode, default=0};
	__property System::Classes::TComponent* PopupMenu = {read=GetPopupMenu, write=SetPopupMenu};
	__property System::Classes::TNotifyEvent StylesEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property bool Synchronization = {read=GetSynchronization, write=SetSynchronization, default=1};
	__property System::Classes::TNotifyEvent OnDblClick = {read=GetOnDblClick, write=SetOnDblClick};
	__property Vcl::Controls::TDragDropEvent OnDragDrop = {read=GetOnDragDrop, write=SetOnDragDrop};
	__property Vcl::Controls::TDragOverEvent OnDragOver = {read=GetOnDragOver, write=SetOnDragOver};
	__property Vcl::Controls::TEndDragEvent OnEndDrag = {read=GetOnEndDrag, write=SetOnEndDrag};
	__property Vcl::Controls::TKeyEvent OnKeyDown = {read=GetOnKeyDown, write=SetOnKeyDown};
	__property Vcl::Controls::TKeyPressEvent OnKeyPress = {read=GetOnKeyPress, write=SetOnKeyPress};
	__property Vcl::Controls::TKeyEvent OnKeyUp = {read=GetOnKeyUp, write=SetOnKeyUp};
	__property Vcl::Controls::TMouseEvent OnMouseDown = {read=GetOnMouseDown, write=SetOnMouseDown};
	__property System::Classes::TNotifyEvent OnMouseEnter = {read=GetOnMouseEnter, write=SetOnMouseEnter};
	__property System::Classes::TNotifyEvent OnMouseLeave = {read=GetOnMouseLeave, write=SetOnMouseLeave};
	__property Vcl::Controls::TMouseMoveEvent OnMouseMove = {read=GetOnMouseMove, write=SetOnMouseMove};
	__property Vcl::Controls::TMouseEvent OnMouseUp = {read=GetOnMouseUp, write=SetOnMouseUp};
	__property Vcl::Controls::TMouseWheelEvent OnMouseWheel = {read=GetOnMouseWheel, write=SetOnMouseWheel};
	__property Vcl::Controls::TMouseWheelUpDownEvent OnMouseWheelDown = {read=GetOnMouseWheelDown, write=SetOnMouseWheelDown};
	__property Vcl::Controls::TMouseWheelUpDownEvent OnMouseWheelUp = {read=GetOnMouseWheelUp, write=SetOnMouseWheelUp};
	__property Vcl::Controls::TStartDragEvent OnStartDrag = {read=GetOnStartDrag, write=SetOnStartDrag};
	__property TcxGridViewGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=SetOnGetStoredProperties};
	__property TcxGridViewGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=SetOnGetStoredPropertyValue};
	__property TcxGridViewSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=SetOnSetStoredPropertyValue};
public:
	/* TcxControlChildComponent.Create */ inline __fastcall virtual TcxCustomGridView(System::Classes::TComponent* AOwner) : Cxcontrols::TcxControlChildComponent(AOwner) { }
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxCustomGridView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxcontrols::TcxControlChildComponent(AControl, AAssignOwner) { }
	
private:
	void *__IcxGridViewLayoutEditorSupport;	/* IcxGridViewLayoutEditorSupport */
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9C5EC9C0-A912-4822-BBD0-87AB45FDCC78}
	operator _di_IcxGridViewLayoutEditorSupport()
	{
		_di_IcxGridViewLayoutEditorSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxGridViewLayoutEditorSupport*(void) { return (IcxGridViewLayoutEditorSupport*)&__IcxGridViewLayoutEditorSupport; }
	#endif
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


class DELPHICLASS TcxCustomGridViewAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void __fastcall AddClone(TcxCustomGridView* AInstance, TcxCustomGridView* AClone);
	__classmethod void __fastcall AssignPattern(TcxCustomGridView* AInstance, TcxCustomGridView* APattern);
	__classmethod bool __fastcall CanBeUsedAsDetail(TcxCustomGridView* AInstance);
	__classmethod bool __fastcall CanBeUsedAsMaster(TcxCustomGridView* AInstance);
	__classmethod bool __fastcall CanFocus(TcxCustomGridView* AInstance);
	__classmethod void __fastcall Deactivate(TcxCustomGridView* AInstance);
	__classmethod void __fastcall DetailVisibleChanged(TcxCustomGridView* AInstance, System::Classes::TComponent* ADetailLevel, int APrevVisibleDetailCount, int AVisibleDetailCount);
	__classmethod void __fastcall FocusChanged(TcxCustomGridView* AInstance, bool AFocused);
	__classmethod void __fastcall LookAndFeelChanged(TcxCustomGridView* AInstance);
	__classmethod void __fastcall SetLevel(TcxCustomGridView* AInstance, System::Classes::TComponent* Value);
	__classmethod bool __fastcall GetChangeable(TcxCustomGridView* AInstance);
	__classmethod TcxCustomGridStyles* __fastcall GetStyles(TcxCustomGridView* AInstance);
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridViewAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridViewAccess(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Byte cxGridCustomizationFormDefaultWidth = System::Byte(0xb4);
static const System::Word cxGridCustomizationFormDefaultHeight = System::Word(0x12c);
static const System::Int8 htError = System::Int8(-1);
static const System::Int8 htNone = System::Int8(0x0);
static const System::Int8 htNavigator = System::Int8(0x1);
static const System::Int8 htCustomizationForm = System::Int8(0x2);
static const System::Int8 htDesignSelector = System::Int8(0x3);
static const System::Int8 ckNone = System::Int8(0x0);
static const System::Int8 ckCustomizationForm = System::Int8(0x1);
static const System::Int8 bbCustomFirst = System::Int8(0x0);
static const System::Int8 bbBackground = System::Int8(0x0);
static const System::Int8 bbCustomLast = System::Int8(0x0);
static const System::Int8 vsCustomFirst = System::Int8(0x0);
static const System::Int8 vsBackground = System::Int8(0x0);
static const System::Int8 vsCustomLast = System::Int8(0x0);
static const System::Int8 StoringVersion = System::Int8(0x1);
extern PACKAGE Cxclasses::TcxRegisteredClasses* cxGridRegisteredViews;
extern PACKAGE System::UnicodeString __fastcall GetViewItemUniqueName(TcxCustomGridView* AView, System::Classes::TComponent* AItem, const System::UnicodeString AItemName);
extern PACKAGE Cxcustomdata::TcxCustomDataController* __fastcall GetGridViewDataController(TcxCustomGridView* AView);
extern PACKAGE TcxCustomGridView* __fastcall GetParentGridView(Vcl::Controls::TControl* AControl);
}	/* namespace Cxgridcustomview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDCUSTOMVIEW)
using namespace Cxgridcustomview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridcustomviewHPP
