// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBLookupComboBox.pas' rev: 24.00 (Win64)

#ifndef CxdblookupcomboboxHPP
#define CxdblookupcomboboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.DBCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLookupEdit.hpp>	// Pascal unit
#include <cxDBLookupEdit.hpp>	// Pascal unit
#include <cxLookupGrid.hpp>	// Pascal unit
#include <cxLookupDBGrid.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdblookupcombobox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxLookupComboBoxProperties;
class PASCALIMPLEMENTATION TcxLookupComboBoxProperties : public Cxdblookupedit::TcxCustomDBLookupEditProperties
{
	typedef Cxdblookupedit::TcxCustomDBLookupEditProperties inherited;
	
private:
	Cxlookupdbgrid::TcxCustomLookupDBGrid* FGrid;
	Cxlookupdbgrid::TcxCustomLookupDBGrid* __fastcall GetGrid(void);
	bool __fastcall GetGridMode(void);
	Cxlookupdbgrid::TcxLookupDBGridColumns* __fastcall GetListColumns(void);
	Cxlookupdbgrid::TcxLookupDBGridOptions* __fastcall GetListOptions(void);
	Data::Db::TDataSource* __fastcall GetListSource(void);
	System::Classes::TNotifyEvent __fastcall GetOnSortingChanged(void);
	void __fastcall SetGridMode(bool Value);
	void __fastcall SetListColumns(Cxlookupdbgrid::TcxLookupDBGridColumns* Value);
	void __fastcall SetListOptions(Cxlookupdbgrid::TcxLookupDBGridOptions* Value);
	void __fastcall SetListSource(Data::Db::TDataSource* Value);
	void __fastcall SetOnSortingChanged(System::Classes::TNotifyEvent Value);
	
protected:
	virtual Cxlookupdbgrid::TcxCustomLookupDBGridClass __fastcall GetLookupGridClass(void);
	virtual void __fastcall ListOptionsChanged(System::TObject* Sender);
	virtual int __fastcall GetLookupGridColumnCount(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetLookupGridControl(void);
	virtual Cxcustomdata::TcxCustomDataController* __fastcall GetLookupGridDataController(void);
	virtual int __fastcall GetLookupGridVisualAreaPreferredWidth(void);
	virtual int __fastcall GetLookupGridNearestPopupHeight(int AHeight);
	virtual int __fastcall GetLookupGridPopupHeight(int ADropDownRowCount);
	virtual bool __fastcall IsLookupGridMouseOverList(const System::Types::TPoint P);
	virtual void __fastcall LookupGridInitEvents(System::Classes::TNotifyEvent AOnClick, System::Classes::TNotifyEvent AOnFocusedRowChanged, Cxlookupedit::TcxLookupGridCloseUpEvent AOnCloseUp);
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
	__fastcall virtual TcxLookupComboBoxProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxLookupComboBoxProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__property Cxlookupdbgrid::TcxCustomLookupDBGrid* Grid = {read=GetGrid};
	
__published:
	__property Alignment;
	__property AutoSelect = {default=1};
	__property AssignedValues;
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
	__property bool GridMode = {read=GetGridMode, write=SetGridMode, default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=1};
	__property ImmediatePost = {default=0};
	__property IncrementalFiltering = {default=1};
	__property KeyFieldNames = {default=0};
	__property Cxlookupdbgrid::TcxLookupDBGridColumns* ListColumns = {read=GetListColumns, write=SetListColumns};
	__property ListFieldNames = {default=0};
	__property ListFieldIndex = {default=0};
	__property Cxlookupdbgrid::TcxLookupDBGridOptions* ListOptions = {read=GetListOptions, write=SetListOptions};
	__property Data::Db::TDataSource* ListSource = {read=GetListSource, write=SetListSource};
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
	__property System::Classes::TNotifyEvent OnSortingChanged = {read=GetOnSortingChanged, write=SetOnSortingChanged};
	__property OnValidate;
};


class DELPHICLASS TcxCustomLookupComboBox;
class PASCALIMPLEMENTATION TcxCustomLookupComboBox : public Cxdblookupedit::TcxCustomDBLookupEdit
{
	typedef Cxdblookupedit::TcxCustomDBLookupEdit inherited;
	
private:
	HIDESBASE TcxLookupComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE TcxLookupComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxLookupComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxLookupComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property EditValue = {default=0};
	__property TcxLookupComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Text = {default=0};
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxCustomLookupComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomLookupComboBox(System::Classes::TComponent* AOwner)/* overload */ : Cxdblookupedit::TcxCustomDBLookupEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomLookupComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdblookupedit::TcxCustomDBLookupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomLookupComboBox(HWND ParentWindow) : Cxdblookupedit::TcxCustomDBLookupEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxLookupComboBox;
class PASCALIMPLEMENTATION TcxLookupComboBox : public TcxCustomLookupComboBox
{
	typedef TcxCustomLookupComboBox inherited;
	
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
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxLookupComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxLookupComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomLookupComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxLookupComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomLookupComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxLookupComboBox(HWND ParentWindow) : TcxCustomLookupComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxDBLookupComboBox;
class PASCALIMPLEMENTATION TcxDBLookupComboBox : public TcxCustomLookupComboBox
{
	typedef TcxCustomLookupComboBox inherited;
	
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
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxDBLookupComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBLookupComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomLookupComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBLookupComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomLookupComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBLookupComboBox(HWND ParentWindow) : TcxCustomLookupComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterLookupComboBoxHelper;
class PASCALIMPLEMENTATION TcxFilterLookupComboBoxHelper : public Cxdropdownedit::TcxFilterComboBoxHelper
{
	typedef Cxdropdownedit::TcxFilterComboBoxHelper inherited;
	
protected:
	__classmethod virtual bool __fastcall IsIDefaultValuesProviderNeeded(Cxedit::TcxCustomEditProperties* AEditProperties);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual void __fastcall GetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &V, Vcl::Controls::TCaption &S);
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
	__classmethod virtual bool __fastcall IsValueValid(Cxdatastorage::TcxValueTypeClass AValueTypeClass, System::Variant &Value);
public:
	/* TObject.Create */ inline __fastcall TcxFilterLookupComboBoxHelper(void) : Cxdropdownedit::TcxFilterComboBoxHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterLookupComboBoxHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdblookupcombobox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBLOOKUPCOMBOBOX)
using namespace Cxdblookupcombobox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdblookupcomboboxHPP
