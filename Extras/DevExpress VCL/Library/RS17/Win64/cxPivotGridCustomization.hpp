// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridCustomization.pas' rev: 24.00 (Win64)

#ifndef CxpivotgridcustomizationHPP
#define CxpivotgridcustomizationHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxPivotGridStrs.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridcustomization
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxFieldListListBox;
class PASCALIMPLEMENTATION TcxFieldListListBox : public Cxlistbox::TdxCustomListBox
{
	typedef Cxlistbox::TdxCustomListBox inherited;
	
private:
	Cxcustompivotgrid::TcxPivotGridCustomizationFormFieldListType FFieldsType;
	void __fastcall CheckItemIndex(const System::Types::TPoint P);
	void __fastcall FilterInitPopupHandler(System::TObject* Sender);
	Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm* __fastcall GetFieldChooser(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	Cxcustompivotgrid::TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	
protected:
	bool __fastcall CanChangeFieldFilter(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall DrawItem(const System::Types::TRect &R, Cxlistbox::TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	int __fastcall GetAreaIndexOffset(Cxcustompivotgrid::TcxPivotGridField* AField, bool ACheckGroup);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	Cxcustompivotgrid::TcxPivotGridField* __fastcall GetSelectedField(void);
	virtual void __fastcall Initialize(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	void __fastcall SynchronizeField(Cxcustompivotgrid::TcxPivotGridField* AField, int AAreaIndex);
	void __fastcall UpdateBackgroundColor(void);
	
public:
	__fastcall virtual TcxFieldListListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual TcxFieldListListBox(System::Classes::TComponent* AOwner, Cxcustompivotgrid::TcxPivotGridCustomizationFormFieldListType AFieldsType);
	virtual bool __fastcall CalculateHitTest(Cxcustompivotgrid::TcxPivotGridHitTest* AHitTest);
	Cxcustompivotgrid::TcxPivotGridField* __fastcall FieldByIndex(int AIndex);
	void __fastcall SynchronizeFields(void);
	void __fastcall UpdateItemHeight(void);
	void __fastcall UpdateSelection(void);
	__property Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm* FieldChooser = {read=GetFieldChooser};
	__property Cxcustompivotgrid::TcxPivotGridCustomizationFormFieldListType FieldsType = {read=FFieldsType, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property Cxcustompivotgrid::TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property Cxcustompivotgrid::TcxPivotGridField* SelectedField = {read=GetSelectedField};
public:
	/* TdxCustomListBox.Destroy */ inline __fastcall virtual ~TcxFieldListListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxFieldListListBox(HWND ParentWindow) : Cxlistbox::TdxCustomListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxPivotGridListListBoxDragAndDropObject;
class PASCALIMPLEMENTATION TcxPivotGridListListBoxDragAndDropObject : public Cxcustompivotgrid::TcxPivotGridDragAndDropObject
{
	typedef Cxcustompivotgrid::TcxPivotGridDragAndDropObject inherited;
	
private:
	Cxcustompivotgrid::TcxPivotGridField* __fastcall GetField(void);
	int __fastcall GetFieldHeaderHeight(void);
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual bool __fastcall CheckArea(const System::Types::TPoint P, Cxcustompivotgrid::TcxPivotGridDragDropAreaInfo* &AInfo);
	virtual void __fastcall CreateDragImage(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual Cxcustompivotgrid::TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	virtual bool __fastcall IsSameDropPlace(void);
	__property Cxcustompivotgrid::TcxPivotGridField* Field = {read=GetField};
	__property int FieldHeaderHeight = {read=GetFieldHeaderHeight, nodefault};
public:
	/* TcxPivotGridDragAndDropObject.Destroy */ inline __fastcall virtual ~TcxPivotGridListListBoxDragAndDropObject(void) { }
	
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxPivotGridListListBoxDragAndDropObject(Cxcontrols::TcxControl* AControl) : Cxcustompivotgrid::TcxPivotGridDragAndDropObject(AControl) { }
	
};


class DELPHICLASS TcxPivotGridCustomizationForm;
class PASCALIMPLEMENTATION TcxPivotGridCustomizationForm : public Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm
{
	typedef Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm inherited;
	
protected:
	Cxbuttons::TcxButton* AddButton;
	Cxdropdownedit::TcxComboBox* AreaList;
	TcxFieldListListBox* FieldList;
	Vcl::Stdctrls::TLabel* FieldListCaption;
	void __fastcall AddToClickHandler(System::TObject* Sender);
	void __fastcall AreaListClickHandler(System::TObject* Sender);
	virtual void __fastcall DoCreateControls(void);
	virtual void __fastcall DoUpdateSelection(void);
	virtual System::Uitypes::TColor __fastcall GetCustomizationFormListBackgroundColor(void);
	virtual System::TObject* __fastcall GetFieldListByType(Cxcustompivotgrid::TcxPivotGridCustomizationFormFieldListType AListType);
	virtual void __fastcall Init(void);
	void __fastcall OnItemDblClick(System::TObject* Sender);
	DYNAMIC void __fastcall Resize(void);
	void __fastcall FieldListClickHandler(System::TObject* Sender);
	Cxdropdownedit::TcxComboBox* __fastcall CreateAreaList(System::Types::TRect &ABounds);
	Cxbuttons::TcxButton* __fastcall CreateButton(System::Types::TRect &ABounds);
	Vcl::Stdctrls::TLabel* __fastcall CreateCaption(System::Types::TRect &ABounds);
	TcxFieldListListBox* __fastcall CreateFieldList(System::Types::TRect &ABounds);
	void __fastcall SyncArea(void);
	void __fastcall SyncVisibility(void);
	
public:
	__fastcall virtual TcxPivotGridCustomizationForm(System::Classes::TComponent* AOwner);
	virtual void __fastcall RefreshList(void);
public:
	/* TcxPivotGridCustomCustomizationForm.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomizationForm(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxPivotGridCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGridCustomizationForm(HWND ParentWindow) : Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm(ParentWindow) { }
	
};


class DELPHICLASS TcxPivotGridOLAPTreeDragAndDropObject;
class DELPHICLASS TcxPivotGridOLAPStructureInnerTreeView;
class DELPHICLASS TcxPivotGridOLAPCustomizationForm;
class PASCALIMPLEMENTATION TcxPivotGridOLAPTreeDragAndDropObject : public Cxcustompivotgrid::TcxPivotGridDragAndDropObject
{
	typedef Cxcustompivotgrid::TcxPivotGridDragAndDropObject inherited;
	
private:
	TcxPivotGridOLAPStructureInnerTreeView* FTreeView;
	Cxcustompivotgrid::TcxPivotGridField* __fastcall GetField(void);
	TcxPivotGridOLAPCustomizationForm* __fastcall GetFieldChooser(void);
	int __fastcall GetFieldHeaderHeight(void);
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual bool __fastcall CheckArea(const System::Types::TPoint P, Cxcustompivotgrid::TcxPivotGridDragDropAreaInfo* &AInfo);
	virtual void __fastcall CreateDragImage(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual System::Types::TPoint __fastcall GetClientCursorPos(void);
	virtual bool __fastcall GetImmediateStart(void);
	__property Cxcustompivotgrid::TcxPivotGridField* Field = {read=GetField};
	__property TcxPivotGridOLAPCustomizationForm* FieldChooser = {read=GetFieldChooser};
	__property int FieldHeaderHeight = {read=GetFieldHeaderHeight, nodefault};
	__property TcxPivotGridOLAPStructureInnerTreeView* TreeView = {read=FTreeView};
public:
	/* TcxPivotGridDragAndDropObject.Destroy */ inline __fastcall virtual ~TcxPivotGridOLAPTreeDragAndDropObject(void) { }
	
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxPivotGridOLAPTreeDragAndDropObject(Cxcontrols::TcxControl* AControl) : Cxcustompivotgrid::TcxPivotGridDragAndDropObject(AControl) { }
	
};


class PASCALIMPLEMENTATION TcxPivotGridOLAPStructureInnerTreeView : public Cxtreeview::TcxCustomInnerTreeView
{
	typedef Cxtreeview::TcxCustomInnerTreeView inherited;
	
private:
	Cxcontrols::TcxDragAndDropObject* FDragAndDropObject;
	System::Uitypes::TCursor FDragAndDropPrevCursor;
	Cxcontrols::TcxDragAndDropState FDragAndDropState;
	bool FFinishingDragAndDrop;
	System::TObject* FMouseCaptureObject;
	System::Types::TPoint FMouseDownPos;
	bool __fastcall GetIsDestroying(void);
	Cxcontrols::TcxDragAndDropObject* __fastcall GetDragAndDropObject(void);
	Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm* __fastcall GetFieldChooser(void);
	TcxPivotGridOLAPCustomizationForm* __fastcall GetForm(void);
	Cxcustompivotgrid::TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	void __fastcall SetDragAndDropState(Cxcontrols::TcxDragAndDropState AValue);
	void __fastcall SetMouseCaptureObject(System::TObject* AValue);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	
protected:
	DYNAMIC bool __fastcall CanEdit(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall BeginDragAndDrop(void);
	void __fastcall DoCancelMode(void);
	void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	void __fastcall EndDragAndDrop(bool Accepted);
	void __fastcall FinishDragAndDrop(bool Accepted);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	__property Cxcontrols::TcxDragAndDropObject* DragAndDropObject = {read=GetDragAndDropObject};
	__property Cxcontrols::TcxDragAndDropState DragAndDropState = {read=FDragAndDropState, write=SetDragAndDropState, nodefault};
	__property TcxPivotGridOLAPCustomizationForm* Form = {read=GetForm};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property System::TObject* MouseCaptureObject = {read=FMouseCaptureObject, write=SetMouseCaptureObject};
	__property Cxcustompivotgrid::TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	
public:
	virtual bool __fastcall CalculateHitTest(Cxcustompivotgrid::TcxPivotGridHitTest* AHitTest);
	__property Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm* FieldChooser = {read=GetFieldChooser};
public:
	/* TcxCustomInnerTreeView.Create */ inline __fastcall virtual TcxPivotGridOLAPStructureInnerTreeView(System::Classes::TComponent* AOwner) : Cxtreeview::TcxCustomInnerTreeView(AOwner) { }
	/* TcxCustomInnerTreeView.Destroy */ inline __fastcall virtual ~TcxPivotGridOLAPStructureInnerTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGridOLAPStructureInnerTreeView(HWND ParentWindow) : Cxtreeview::TcxCustomInnerTreeView(ParentWindow) { }
	
};


class DELPHICLASS TcxPivotGridOLAPTreeView;
class PASCALIMPLEMENTATION TcxPivotGridOLAPTreeView : public Cxtreeview::TcxTreeView
{
	typedef Cxtreeview::TcxTreeView inherited;
	
protected:
	__classmethod virtual Cxtreeview::TcxCustomInnerTreeViewClass __fastcall GetTreeViewClass();
public:
	/* TcxCustomTreeView.Create */ inline __fastcall virtual TcxPivotGridOLAPTreeView(System::Classes::TComponent* AOwner) : Cxtreeview::TcxTreeView(AOwner) { }
	
public:
	/* TcxTreeViewContainer.Destroy */ inline __fastcall virtual ~TcxPivotGridOLAPTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGridOLAPTreeView(HWND ParentWindow) : Cxtreeview::TcxTreeView(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxPivotGridOLAPCustomizationForm : public Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm
{
	typedef Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm inherited;
	
private:
	Cxcustompivotgrid::TcxPivotGridOLAPStructureNode* __fastcall GetStructure(void);
	
protected:
	Cxcustompivotgrid::TcxPivotGridOLAPStructureNode* CurrentStructure;
	Vcl::Stdctrls::TLabel* FieldListCaption;
	TcxPivotGridOLAPTreeView* FieldList;
	System::Classes::TList* ExpandingInfo;
	bool StructureIsPopulated;
	virtual void __fastcall DoCreateControls(void);
	virtual void __fastcall DoUpdateSelection(void);
	void __fastcall DrawStructureItem(Vcl::Comctrls::TCustomTreeView* Sender, Vcl::Comctrls::TTreeNode* Node, Vcl::Comctrls::TCustomDrawState State, bool &DefaultDraw);
	virtual System::Uitypes::TColor __fastcall GetCustomizationFormListBackgroundColor(void);
	System::UnicodeString __fastcall GetStructureDisplayText(Cxcustompivotgrid::TcxPivotGridOLAPStructureNode* AStructure);
	virtual void __fastcall Init(void);
	virtual void __fastcall Localize(void);
	void __fastcall OnGetTreeViewNodeImageIndex(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall OnItemDblClick(System::TObject* Sender);
	virtual void __fastcall PopulateStructure(void);
	void __fastcall SaveExpanding(void);
	
public:
	__fastcall virtual TcxPivotGridOLAPCustomizationForm(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxPivotGridOLAPCustomizationForm(void);
	virtual void __fastcall RefreshList(void);
	__property Cxcustompivotgrid::TcxPivotGridOLAPStructureNode* Structure = {read=GetStructure};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxPivotGridOLAPCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGridOLAPCustomizationForm(HWND ParentWindow) : Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxcustompivotgrid::TcxPivotGridCustomizationFormClass cxPivotGridCustimzationFormClass;
extern PACKAGE void __fastcall cxPopulateListBox(Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm* AFieldChooser, TcxFieldListListBox* AListBox, Cxcustompivotgrid::TcxPivotGridCustomizationFormFieldListType AType);
}	/* namespace Cxpivotgridcustomization */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDCUSTOMIZATION)
using namespace Cxpivotgridcustomization;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridcustomizationHPP
