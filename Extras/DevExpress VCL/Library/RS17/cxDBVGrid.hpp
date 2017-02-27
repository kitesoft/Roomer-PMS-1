// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBVGrid.pas' rev: 24.00 (Win32)

#ifndef CxdbvgridHPP
#define CxdbvgridHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEditRepositoryItems.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbvgrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBVerticalGridDefaultValuesProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBVerticalGridDefaultValuesProvider : public Cxdbedit::TcxCustomDBEditDefaultValuesProvider
{
	typedef Cxdbedit::TcxCustomDBEditDefaultValuesProvider inherited;
	
public:
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
public:
	/* TcxCustomDBEditDefaultValuesProvider.Create */ inline __fastcall virtual TcxDBVerticalGridDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Cxdbedit::TcxCustomDBEditDefaultValuesProvider(AOwner) { }
	/* TcxCustomDBEditDefaultValuesProvider.Destroy */ inline __fastcall virtual ~TcxDBVerticalGridDefaultValuesProvider(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBVerticalGridDataController;
class DELPHICLASS TcxDBVerticalGrid;
class PASCALIMPLEMENTATION TcxDBVerticalGridDataController : public Cxdbdata::TcxDBDataController
{
	typedef Cxdbdata::TcxDBDataController inherited;
	
private:
	int FPrevBufferCount;
	int FPrevScrollBarPos;
	TcxDBVerticalGrid* __fastcall GetVerticalGrid(void);
	bool __fastcall GetGridMode(void);
	int __fastcall GetGridModeBufferCount(void);
	Cxvgrid::TcxvgScroller* __fastcall GetScroller(void);
	void __fastcall SetGridMode(bool Value);
	void __fastcall SetGridModeBufferCount(int Value);
	
protected:
	void __fastcall CheckGridModeBufferCount(void);
	bool __fastcall DoScroll(bool AForward);
	HIDESBASE int __fastcall GetDataSetRecordCount(void);
	int __fastcall GetScrollBarPos(void);
	int __fastcall GetScrollBarRecordCount(void);
	bool __fastcall SetScrollBarPos(int APos);
	virtual int __fastcall GetDefaultGridModeBufferCount(void);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual bool __fastcall SupportsScrollBarParams(void);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual void __fastcall UpdateScrollBars(void);
	__property Cxvgrid::TcxvgScroller* Scroller = {read=GetScroller};
	__property TcxDBVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	void __fastcall CreateAllItems(void);
	virtual void __fastcall FocusControl(int AItemIndex, bool &Done);
	virtual System::TObject* __fastcall GetItem(int Index);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall UpdateItemIndexes(void);
	
__published:
	__property DataSource;
	__property bool GridMode = {read=GetGridMode, write=SetGridMode, default=0};
	__property int GridModeBufferCount = {read=GetGridModeBufferCount, write=SetGridModeBufferCount, default=0};
public:
	/* TcxDBDataController.Create */ inline __fastcall virtual TcxDBVerticalGridDataController(System::Classes::TComponent* AOwner) : Cxdbdata::TcxDBDataController(AOwner) { }
	/* TcxDBDataController.Destroy */ inline __fastcall virtual ~TcxDBVerticalGridDataController(void) { }
	
private:
	void *__IcxVerticalGridDBDataContoller;	/* Cxvgrid::IcxVerticalGridDBDataContoller */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {947072DE-3531-4010-8C44-D243FD289FDF}
	operator Cxvgrid::_di_IcxVerticalGridDBDataContoller()
	{
		Cxvgrid::_di_IcxVerticalGridDBDataContoller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxvgrid::IcxVerticalGridDBDataContoller*(void) { return (Cxvgrid::IcxVerticalGridDBDataContoller*)&__IcxVerticalGridDBDataContoller; }
	#endif
	
};


class DELPHICLASS TcxDBVerticalGridItemDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBVerticalGridItemDataBinding : public Cxinplacecontainer::TcxCustomItemDataBinding
{
	typedef Cxinplacecontainer::TcxCustomItemDataBinding inherited;
	
private:
	HIDESBASE TcxDBVerticalGridDataController* __fastcall GetDataController(void);
	Data::Db::TField* __fastcall GetField(void);
	System::UnicodeString __fastcall GetFieldName(void);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	
protected:
	virtual Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	virtual void __fastcall Init(void);
	virtual void __fastcall ValueTypeClassChanged(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	__property TcxDBVerticalGridDataController* DataController = {read=GetDataController};
	__property Data::Db::TField* Field = {read=GetField};
	
__published:
	__property System::UnicodeString FieldName = {read=GetFieldName, write=SetFieldName};
public:
	/* TcxCustomItemDataBinding.Create */ inline __fastcall virtual TcxDBVerticalGridItemDataBinding(System::Classes::TPersistent* AOwner) : Cxinplacecontainer::TcxCustomItemDataBinding(AOwner) { }
	/* TcxCustomItemDataBinding.Destroy */ inline __fastcall virtual ~TcxDBVerticalGridItemDataBinding(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBCellEdit;
class PASCALIMPLEMENTATION TcxDBCellEdit : public Cxvgrid::TcxCellEdit
{
	typedef Cxvgrid::TcxCellEdit inherited;
	
protected:
	virtual Cxinplacecontainer::TcxItemDataBindingClass __fastcall GetDataBindingClass(void);
public:
	/* TcxCellEdit.Create */ inline __fastcall virtual TcxDBCellEdit(System::Classes::TComponent* AOwner) : Cxvgrid::TcxCellEdit(AOwner) { }
	/* TcxCellEdit.Destroy */ inline __fastcall virtual ~TcxDBCellEdit(void) { }
	
};


class DELPHICLASS TcxDBEditorRowItemProperties;
class PASCALIMPLEMENTATION TcxDBEditorRowItemProperties : public Cxvgrid::TcxCollectionItemEditorRowProperties
{
	typedef Cxvgrid::TcxCollectionItemEditorRowProperties inherited;
	
private:
	HIDESBASE TcxDBVerticalGridItemDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBVerticalGridItemDataBinding* Value);
	
protected:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual Cxvgrid::TcxCellEditClass __fastcall GetInplaceEditContainerClass(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxDBVerticalGridItemDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property Options;
	__property OnGetDisplayText;
	__property OnGetEditProperties;
	__property OnGetEditingProperties;
	__property OnValidateDrawValue;
public:
	/* TcxCollectionItemEditorRowProperties.CreateEx */ inline __fastcall virtual TcxDBEditorRowItemProperties(Cxvgrid::TcxCustomRow* ARow) : Cxvgrid::TcxCollectionItemEditorRowProperties(ARow) { }
	
public:
	/* TcxCustomEditorRowProperties.Destroy */ inline __fastcall virtual ~TcxDBEditorRowItemProperties(void) { }
	
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxDBEditorRowItemProperties(System::Classes::TCollection* Collection) : Cxvgrid::TcxCollectionItemEditorRowProperties(Collection) { }
	
};


class DELPHICLASS TcxDBEditorPropertiesCollection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBEditorPropertiesCollection : public Cxvgrid::TcxEditorPropertiesCollection
{
	typedef Cxvgrid::TcxEditorPropertiesCollection inherited;
	
public:
	TcxDBEditorRowItemProperties* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxDBEditorRowItemProperties* __fastcall GetItem(int Index);
	
protected:
	virtual System::Classes::TCollectionItemClass __fastcall GetCollectionItemClass(void);
	
public:
	HIDESBASE TcxDBEditorRowItemProperties* __fastcall Add(void);
	__property TcxDBEditorRowItemProperties* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxEditorPropertiesCollection.Create */ inline __fastcall virtual TcxDBEditorPropertiesCollection(Cxvgrid::TcxCustomMultiEditorRow* ARow) : Cxvgrid::TcxEditorPropertiesCollection(ARow) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDBEditorPropertiesCollection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBEditorRowProperties;
class PASCALIMPLEMENTATION TcxDBEditorRowProperties : public Cxvgrid::TcxCustomEditorRowProperties
{
	typedef Cxvgrid::TcxCustomEditorRowProperties inherited;
	
private:
	HIDESBASE TcxDBVerticalGridItemDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBVerticalGridItemDataBinding* Value);
	
protected:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual Cxvgrid::TcxCellEditClass __fastcall GetInplaceEditContainerClass(void);
	
public:
	__property Value = {default=0};
	
__published:
	__property TcxDBVerticalGridItemDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property Options;
	__property OnGetDisplayText;
	__property OnGetEditProperties;
	__property OnGetEditingProperties;
	__property OnValidateDrawValue;
public:
	/* TcxCustomEditorRowProperties.CreateEx */ inline __fastcall virtual TcxDBEditorRowProperties(Cxvgrid::TcxCustomRow* ARow) : Cxvgrid::TcxCustomEditorRowProperties(ARow) { }
	/* TcxCustomEditorRowProperties.Destroy */ inline __fastcall virtual ~TcxDBEditorRowProperties(void) { }
	
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxDBEditorRowProperties(System::Classes::TCollection* Collection) : Cxvgrid::TcxCustomEditorRowProperties(Collection) { }
	
};


class DELPHICLASS TcxDBEditorRow;
class PASCALIMPLEMENTATION TcxDBEditorRow : public Cxvgrid::TcxCustomEditorRow
{
	typedef Cxvgrid::TcxCustomEditorRow inherited;
	
private:
	HIDESBASE TcxDBEditorRowProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxDBEditorRowProperties* Value);
	
protected:
	virtual Cxvgrid::TcxRowPropertiesClass __fastcall GetPropertiesClass(void);
	
__published:
	__property Expanded = {default=1};
	__property Height = {default=-1};
	__property Options;
	__property TcxDBEditorRowProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Styles;
	__property Visible = {default=1};
public:
	/* TcxCustomRow.Create */ inline __fastcall virtual TcxDBEditorRow(System::Classes::TComponent* AOwner) : Cxvgrid::TcxCustomEditorRow(AOwner) { }
	/* TcxCustomRow.Destroy */ inline __fastcall virtual ~TcxDBEditorRow(void) { }
	
};


class DELPHICLASS TcxDBMultiEditorRowProperties;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBMultiEditorRowProperties : public Cxvgrid::TcxMultiEditorRowProperties
{
	typedef Cxvgrid::TcxMultiEditorRowProperties inherited;
	
private:
	TcxDBEditorPropertiesCollection* __fastcall GetEditors(void);
	void __fastcall SetEditors(TcxDBEditorPropertiesCollection* Value);
	
protected:
	virtual Cxvgrid::TcxEditorPropertiesCollectionClass __fastcall GetCollectionClass(void);
	
__published:
	__property TcxDBEditorPropertiesCollection* Editors = {read=GetEditors, write=SetEditors};
public:
	/* TcxMultiEditorRowProperties.CreateEx */ inline __fastcall virtual TcxDBMultiEditorRowProperties(Cxvgrid::TcxCustomRow* ARow) : Cxvgrid::TcxMultiEditorRowProperties(ARow) { }
	/* TcxMultiEditorRowProperties.Destroy */ inline __fastcall virtual ~TcxDBMultiEditorRowProperties(void) { }
	
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxDBMultiEditorRowProperties(System::Classes::TCollection* Collection) : Cxvgrid::TcxMultiEditorRowProperties(Collection) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBMultiEditorRow;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBMultiEditorRow : public Cxvgrid::TcxCustomMultiEditorRow
{
	typedef Cxvgrid::TcxCustomMultiEditorRow inherited;
	
private:
	HIDESBASE TcxDBMultiEditorRowProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxDBMultiEditorRowProperties* Value);
	
protected:
	virtual Cxvgrid::TcxRowPropertiesClass __fastcall GetPropertiesClass(void);
	
__published:
	__property Expanded = {default=1};
	__property Height = {default=-1};
	__property Options;
	__property TcxDBMultiEditorRowProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Styles;
	__property Visible = {default=1};
public:
	/* TcxCustomRow.Create */ inline __fastcall virtual TcxDBMultiEditorRow(System::Classes::TComponent* AOwner) : Cxvgrid::TcxCustomMultiEditorRow(AOwner) { }
	/* TcxCustomRow.Destroy */ inline __fastcall virtual ~TcxDBMultiEditorRow(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxDBVerticalGrid : public Cxvgrid::TcxVirtualVerticalGrid
{
	typedef Cxvgrid::TcxVirtualVerticalGrid inherited;
	
private:
	TcxDBVerticalGridDataController* __fastcall GetDataController(void);
	void __fastcall SetDataController(TcxDBVerticalGridDataController* Value);
	
protected:
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxinplacecontainer::TcxItemDataBindingClass __fastcall GetEditCellDataBindingClass(void);
	virtual Cxvgrid::TcxCustomRowClass __fastcall GetEditorRowClass(void);
	virtual Cxvgrid::TcxCustomRowClass __fastcall GetMultiEditorRowClass(void);
	virtual void __fastcall InitDataController(void);
	
public:
	__fastcall virtual ~TcxDBVerticalGrid(void);
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property TcxDBVerticalGridDataController* DataController = {read=GetDataController, write=SetDataController};
	__property DragCursor = {default=0};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Images;
	__property LayoutStyle = {default=1};
	__property LookAndFeel;
	__property OptionsView;
	__property OptionsBehavior;
	__property OptionsData;
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnCustomizationFormVisibleChanged;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawBackground;
	__property OnDrawRowHeader;
	__property OnDrawValue;
	__property OnEdited;
	__property OnEditing;
	__property OnEditValueChanged;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnFilterControlDialogShow;
	__property OnFilterRecord;
	__property OnFocusedRecordChanged;
	__property OnInitEdit;
	__property OnItemChanged;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnLayoutChanged;
	__property OnLeftVisibleBandIndexChanged;
	__property OnLeftVisibleRecordIndexChanged;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnTopRowIndexChanged;
public:
	/* TcxVirtualVerticalGrid.Create */ inline __fastcall virtual TcxDBVerticalGrid(System::Classes::TComponent* AOwner) : Cxvgrid::TcxVirtualVerticalGrid(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBVerticalGrid(HWND ParentWindow) : Cxvgrid::TcxVirtualVerticalGrid(ParentWindow) { }
	
private:
	void *__IcxVGridDesignerRows;	/* Cxvgrid::IcxVGridDesignerRows */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D77CC392-984F-4C1E-A41C-A341FEAC93EB}
	operator Cxvgrid::_di_IcxVGridDesignerRows()
	{
		Cxvgrid::_di_IcxVGridDesignerRows intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxvgrid::IcxVGridDesignerRows*(void) { return (Cxvgrid::IcxVGridDesignerRows*)&__IcxVGridDesignerRows; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbvgrid */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBVGRID)
using namespace Cxdbvgrid;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbvgridHPP
