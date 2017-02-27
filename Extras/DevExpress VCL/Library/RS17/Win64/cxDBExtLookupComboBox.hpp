// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBExtLookupComboBox.pas' rev: 24.00 (Win64)

#ifndef CxdbextlookupcomboboxHPP
#define CxdbextlookupcomboboxHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxDBLookupEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridStrs.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookupEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbextlookupcombobox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxExtLookupGrid;
class PASCALIMPLEMENTATION TcxExtLookupGrid : public Cxgrid::TcxGrid
{
	typedef Cxgrid::TcxGrid inherited;
	
private:
	bool FEditable;
	System::Types::TPoint FMousePos;
	bool FPopupMouseMoveLocked;
	Vcl::Controls::TKeyEvent FPrevOnKeyDown;
	Vcl::Controls::TMouseEvent FPrevOnMouseDown;
	Vcl::Controls::TMouseMoveEvent FPrevOnMouseMove;
	Vcl::Controls::TMouseEvent FPrevOnMouseUp;
	bool FRowPressed;
	Cxlookupedit::TcxLookupGridCloseUpEvent FOnCloseUp;
	HIDESBASE Cxgridcustomtableview::TcxCustomGridTableView* __fastcall GetView(void);
	void __fastcall ViewKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ViewMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ViewMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ViewMouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	
protected:
	DYNAMIC void __fastcall DoCancelMode(void);
	virtual void __fastcall DoCloseUp(bool AAccept);
	bool __fastcall IsDataRow(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	__property bool Editable = {read=FEditable, write=FEditable, nodefault};
	__property bool PopupMouseMoveLocked = {read=FPopupMouseMoveLocked, write=FPopupMouseMoveLocked, nodefault};
	__property Cxlookupedit::TcxLookupGridCloseUpEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	
public:
	__property Cxgridcustomtableview::TcxCustomGridTableView* View = {read=GetView};
public:
	/* TcxCustomGrid.Create */ inline __fastcall virtual TcxExtLookupGrid(System::Classes::TComponent* AOwner) : Cxgrid::TcxGrid(AOwner) { }
	/* TcxCustomGrid.Destroy */ inline __fastcall virtual ~TcxExtLookupGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxExtLookupGrid(HWND ParentWindow) : Cxgrid::TcxGrid(ParentWindow) { }
	
};


class DELPHICLASS TcxCustomExtLookupComboBoxProperties;
class PASCALIMPLEMENTATION TcxCustomExtLookupComboBoxProperties : public Cxdblookupedit::TcxCustomDBLookupEditProperties
{
	typedef Cxdblookupedit::TcxCustomDBLookupEditProperties inherited;
	
public:
	/* TcxCustomDBLookupEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomExtLookupComboBoxProperties(void) { }
	
public:
	/* TcxCustomLookupEditProperties.Create */ inline __fastcall virtual TcxCustomExtLookupComboBoxProperties(System::Classes::TPersistent* AOwner) : Cxdblookupedit::TcxCustomDBLookupEditProperties(AOwner) { }
	
};


class DELPHICLASS TcxExtLookupComboBoxProperties;
class PASCALIMPLEMENTATION TcxExtLookupComboBoxProperties : public TcxCustomExtLookupComboBoxProperties
{
	typedef TcxCustomExtLookupComboBoxProperties inherited;
	
private:
	bool FAutoSearchOnPopup;
	bool FDestroying;
	bool FFocusPopup;
	TcxExtLookupGrid* FGrid;
	bool FInCheckListFieldItem;
	Cxgridcustomtableview::TcxCustomGridTableItem* FListFieldItem;
	bool FPrevColumnFiltering;
	bool FPrevColumnsQuickCustomization;
	bool FPrevPullFocusing;
	bool FPrevImmediateEditor;
	bool FPrevIncSearch;
	bool FPrevMultiSelect;
	Cxgridcustomtableview::TcxCustomGridTableView* FView;
	TcxExtLookupGrid* __fastcall GetGrid(void);
	bool __fastcall GetGridMode(void);
	HIDESBASE int __fastcall GetListFieldIndex(void);
	Cxgridcustomtableview::TcxCustomGridTableItem* __fastcall GetListFieldItem(void);
	void __fastcall SetGridMode(bool Value);
	void __fastcall SetListFieldItem(Cxgridcustomtableview::TcxCustomGridTableItem* Value);
	void __fastcall SetView(Cxgridcustomtableview::TcxCustomGridTableView* Value);
	
protected:
	void __fastcall CheckListFieldItem(void);
	virtual void __fastcall DeinitializeDataController(void);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	virtual bool __fastcall GetIncrementalFiltering(void);
	virtual int __fastcall GetListIndex(void);
	virtual void __fastcall InitializeDataController(void);
	void __fastcall LinkView(Cxgridcustomtableview::TcxCustomGridTableView* AView);
	virtual bool __fastcall PopupWindowCapturesFocus(void);
	void __fastcall UnlinkView(Cxgridcustomtableview::TcxCustomGridTableView* AView);
	virtual Vcl::Controls::TWinControl* __fastcall GetLookupGridActiveControl(void);
	virtual bool __fastcall GetLookupGridCanResize(void);
	virtual int __fastcall GetLookupGridColumnCount(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetLookupGridControl(void);
	virtual Cxcustomdata::TcxCustomDataController* __fastcall GetLookupGridDataController(void);
	virtual int __fastcall GetLookupGridVisualAreaPreferredWidth(void);
	virtual int __fastcall GetLookupGridNearestPopupHeight(int AHeight);
	virtual int __fastcall GetLookupGridPopupHeight(int ADropDownRowCount);
	virtual bool __fastcall IsLookupGridMouseOverList(const System::Types::TPoint P);
	virtual void __fastcall LookupGridDeinitialize(void);
	virtual void __fastcall LookupGridDroppedDown(const System::UnicodeString AFindStr);
	virtual void __fastcall LookupGridInitEvents(System::Classes::TNotifyEvent AOnClick, System::Classes::TNotifyEvent AOnFocusedRowChanged, Cxlookupedit::TcxLookupGridCloseUpEvent AOnCloseUp);
	virtual void __fastcall LookupGridInitialize(void);
	virtual void __fastcall LookupGridInitLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, System::Uitypes::TColor AColor, Vcl::Graphics::TFont* AFont);
	virtual void __fastcall LookupGridLockMouseMove(void);
	virtual void __fastcall LookupGridMakeFocusedRowVisible(void);
	virtual void __fastcall LookupGridUnlockMouseMove(void);
	virtual void __fastcall DBLookupGridBeginUpdate(void);
	virtual void __fastcall DBLookupGridCheckColumnByFieldName(const System::UnicodeString AFieldName);
	virtual void __fastcall DBLookupGridCreateColumnsByFieldNames(const System::UnicodeString AFieldNames);
	virtual void __fastcall DBLookupGridEndUpdate(void);
	virtual Data::Db::TField* __fastcall GetDBLookupGridColumnField(int AIndex);
	virtual System::UnicodeString __fastcall GetDBLookupGridColumnFieldName(int AIndex);
	virtual int __fastcall GetDBLookupGridColumnIndexByFieldName(const System::UnicodeString AFieldName);
	virtual Cxdbdata::TcxDBDataController* __fastcall GetDBLookupGridDataController(void);
	
public:
	__fastcall virtual TcxExtLookupComboBoxProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxExtLookupComboBoxProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__classmethod bool __fastcall IsViewSupported(Cxgridcustomtableview::TcxCustomGridTableView* Value);
	__property TcxExtLookupGrid* Grid = {read=GetGrid};
	__property int ListFieldIndex = {read=GetListFieldIndex, nodefault};
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property bool AutoSearchOnPopup = {read=FAutoSearchOnPopup, write=FAutoSearchOnPopup, default=1};
	__property AutoSelect = {default=1};
	__property ButtonGlyph;
	__property CaseSensitiveSearch = {default=0};
	__property CharCase = {default=0};
	__property ClearKey = {default=0};
	__property DropDownAutoSize = {default=0};
	__property DropDownHeight = {default=0};
	__property DropDownListStyle = {default=0};
	__property DropDownRows = {default=8};
	__property DropDownSizeable = {default=0};
	__property DropDownWidth = {default=0};
	__property bool FocusPopup = {read=FFocusPopup, write=FFocusPopup, default=0};
	__property bool GridMode = {read=GetGridMode, write=SetGridMode, default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDown;
	__property ImmediatePost = {default=0};
	__property IncrementalFiltering = {default=1};
	__property Cxgridcustomtableview::TcxCustomGridTableView* View = {read=FView, write=SetView};
	__property KeyFieldNames = {default=0};
	__property Cxgridcustomtableview::TcxCustomGridTableItem* ListFieldItem = {read=GetListFieldItem, write=SetListFieldItem};
	__property MaxLength;
	__property OEMConvert = {default=0};
	__property PopupAlignment = {default=0};
	__property PostPopupValueOnTab = {default=0};
	__property ReadOnly;
	__property Revertable = {default=0};
	__property UseLeftAlignmentOnEditing;
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnCloseUp;
	__property OnEditValueChanged;
	__property OnInitPopup;
	__property OnNewLookupDisplayText;
	__property OnPopup;
	__property OnValidate;
};


class DELPHICLASS TcxCustomExtLookupComboBox;
class PASCALIMPLEMENTATION TcxCustomExtLookupComboBox : public Cxdblookupedit::TcxCustomDBLookupEdit
{
	typedef Cxdblookupedit::TcxCustomDBLookupEdit inherited;
	
private:
	HIDESBASE TcxExtLookupComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxExtLookupComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxExtLookupComboBoxProperties* Value);
	
protected:
	virtual bool __fastcall CanDropDown(void);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxExtLookupComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property EditValue = {default=0};
	__property TcxExtLookupComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Text = {default=0};
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxCustomExtLookupComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomExtLookupComboBox(System::Classes::TComponent* AOwner)/* overload */ : Cxdblookupedit::TcxCustomDBLookupEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomExtLookupComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdblookupedit::TcxCustomDBLookupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomExtLookupComboBox(HWND ParentWindow) : Cxdblookupedit::TcxCustomDBLookupEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxExtLookupComboBox;
class PASCALIMPLEMENTATION TcxExtLookupComboBox : public TcxCustomExtLookupComboBox
{
	typedef TcxCustomExtLookupComboBox inherited;
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Properties;
	__property EditValue = {default=0};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnEditing;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxExtLookupComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxExtLookupComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomExtLookupComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxExtLookupComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomExtLookupComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxExtLookupComboBox(HWND ParentWindow) : TcxCustomExtLookupComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxDBExtLookupComboBox;
class PASCALIMPLEMENTATION TcxDBExtLookupComboBox : public TcxCustomExtLookupComboBox
{
	typedef TcxCustomExtLookupComboBox inherited;
	
private:
	Cxdbedit::TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(Cxdbedit::TcxDBTextEditDataBinding* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property Cxdbedit::TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Properties;
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnEditing;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxDBExtLookupComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBExtLookupComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomExtLookupComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBExtLookupComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomExtLookupComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBExtLookupComboBox(HWND ParentWindow) : TcxCustomExtLookupComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxEditRepositoryExtLookupComboBoxItem;
class PASCALIMPLEMENTATION TcxEditRepositoryExtLookupComboBoxItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	TcxExtLookupComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxExtLookupComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property TcxExtLookupComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryExtLookupComboBoxItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryExtLookupComboBoxItem(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbextlookupcombobox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBEXTLOOKUPCOMBOBOX)
using namespace Cxdbextlookupcombobox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbextlookupcomboboxHPP
