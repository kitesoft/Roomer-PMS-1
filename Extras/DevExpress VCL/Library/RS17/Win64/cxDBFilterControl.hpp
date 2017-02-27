// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBFilterControl.pas' rev: 24.00 (Win64)

#ifndef CxdbfiltercontrolHPP
#define CxdbfiltercontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxFilterControl.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbfiltercontrol
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxFilterItem;
class DELPHICLASS TcxDBFilterControl;
class PASCALIMPLEMENTATION TcxFilterItem : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
private:
	System::_di_IInterface FOwnerInterface;
	TcxDBFilterControl* FFilterControl;
	System::UnicodeString FCaption;
	System::UnicodeString FFieldName;
	Cxedit::TcxCustomEditProperties* FProperties;
	Cxedit::TcxEditRepositoryItem* FRepositoryItem;
	Cxedit::TcxCustomEditPropertiesClass FPropertiesClass;
	void __fastcall DoPropertiesChanged(System::TObject* Sender);
	System::UnicodeString __fastcall GetPropertiesClassName(void);
	bool __fastcall IsCaptionStored(void);
	void __fastcall RecreateProperties(void);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	void __fastcall SetProperties(Cxedit::TcxCustomEditProperties* const Value);
	void __fastcall SetPropertiesClass(const Cxedit::TcxCustomEditPropertiesClass Value);
	void __fastcall SetPropertiesClassName(const System::UnicodeString Value);
	void __fastcall SetRepositoryItem(Cxedit::TcxEditRepositoryItem* const Value);
	
protected:
	void __fastcall ItemRemoved(Cxedit::TcxEditRepositoryItem* Sender);
	void __fastcall PropertiesChanged(Cxedit::TcxEditRepositoryItem* Sender);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual void __fastcall CreateProperties(void);
	virtual void __fastcall DestroyProperties(void);
	
public:
	__fastcall virtual TcxFilterItem(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxFilterItem(void);
	virtual void __fastcall AfterConstruction(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void);
	__property TcxDBFilterControl* FilterControl = {read=FFilterControl};
	__property Cxedit::TcxCustomEditPropertiesClass PropertiesClass = {read=FPropertiesClass, write=SetPropertiesClass};
	
__published:
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property System::UnicodeString FieldName = {read=FFieldName, write=SetFieldName};
	__property System::UnicodeString PropertiesClassName = {read=GetPropertiesClassName, write=SetPropertiesClassName};
	__property Cxedit::TcxCustomEditProperties* Properties = {read=FProperties, write=SetProperties};
	__property Cxedit::TcxEditRepositoryItem* RepositoryItem = {read=FRepositoryItem, write=SetRepositoryItem};
private:
	void *__IcxEditRepositoryItemListener;	/* Cxedit::IcxEditRepositoryItemListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator Cxedit::_di_IcxEditRepositoryItemListener()
	{
		Cxedit::_di_IcxEditRepositoryItemListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditRepositoryItemListener*(void) { return (Cxedit::IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
	#endif
	
};


class DELPHICLASS TcxFilterPropertiesList;
class PASCALIMPLEMENTATION TcxFilterPropertiesList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	virtual void __fastcall Clear(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(Cxedit::TcxCustomEditPropertiesClass AClass);
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxFilterPropertiesList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxFilterPropertiesList(void) : System::Classes::TList() { }
	
};


class DELPHICLASS TcxFilterItemCollection;
class PASCALIMPLEMENTATION TcxFilterItemCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TcxFilterItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxDBFilterControl* __fastcall GetControl(void);
	TcxFilterItem* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, TcxFilterItem* const Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__property TcxDBFilterControl* Control = {read=GetControl};
	__property TcxFilterItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxFilterItemCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxFilterItemCollection(void) { }
	
};


class DELPHICLASS TcxDBFilterOptions;
class PASCALIMPLEMENTATION TcxDBFilterOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxDBFilterControl* FFilterControl;
	bool FSupportedBetween;
	bool FSupportedIn;
	bool FSupportedLike;
	System::UnicodeString __fastcall GetDateTimeFormat(void);
	System::WideChar __fastcall GetPercentWildcard(void);
	bool __fastcall GetSoftNull(void);
	bool __fastcall GetTranslateBetween(void);
	bool __fastcall GetTranslateIn(void);
	bool __fastcall GetTranslateLike(void);
	System::WideChar __fastcall GetUnderscoreWildcard(void);
	void __fastcall SetDateTimeFormat(const System::UnicodeString Value);
	void __fastcall SetPercentWildcard(System::WideChar Value);
	void __fastcall SetSoftNull(bool Value);
	void __fastcall SetTranslateBetween(bool Value);
	void __fastcall SetTranslateIn(bool Value);
	void __fastcall SetTranslateLike(bool Value);
	void __fastcall SetUnderscoreWildcard(System::WideChar Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxDBFilterOptions(TcxDBFilterControl* AFilterControl);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ProcessFilterOperators(Cxfiltercontrolutils::TcxFilterControlOperators &SupportedOperations);
	
__published:
	__property System::UnicodeString DateTimeFormat = {read=GetDateTimeFormat, write=SetDateTimeFormat};
	__property System::WideChar PercentWildcard = {read=GetPercentWildcard, write=SetPercentWildcard, default=37};
	__property bool SoftNull = {read=GetSoftNull, write=SetSoftNull, default=0};
	__property bool SupportedBetween = {read=FSupportedBetween, write=FSupportedBetween, default=1};
	__property bool SupportedIn = {read=FSupportedIn, write=FSupportedIn, default=1};
	__property bool SupportedLike = {read=FSupportedLike, write=FSupportedLike, default=1};
	__property bool TranslateBetween = {read=GetTranslateBetween, write=SetTranslateBetween, default=0};
	__property bool TranslateIn = {read=GetTranslateIn, write=SetTranslateIn, default=0};
	__property bool TranslateLike = {read=GetTranslateLike, write=SetTranslateLike, default=0};
	__property System::WideChar UnderscoreWildcard = {read=GetUnderscoreWildcard, write=SetUnderscoreWildcard, default=95};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDBFilterOptions(void) { }
	
};


class PASCALIMPLEMENTATION TcxDBFilterControl : public Cxfiltercontrol::TcxCustomFilterControl
{
	typedef Cxfiltercontrol::TcxCustomFilterControl inherited;
	
private:
	bool FApplyingFilter;
	Data::Db::TDataSource* FDataSource;
	Data::Db::TDataSet* FDataSet;
	System::UnicodeString FFieldNamePostfix;
	System::UnicodeString FFieldNamePrefix;
	TcxFilterPropertiesList* FFieldsProperties;
	TcxDBFilterOptions* FFilterOptions;
	TcxFilterItemCollection* FItems;
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	TcxFilterItemCollection* __fastcall GetItems(void);
	Data::Db::TField* __fastcall GetField(int AIndex);
	TcxDBFilterOptions* __fastcall GetFilterOptions(void);
	void __fastcall DataSetStateChange(System::TObject* Sender);
	void __fastcall SetDataSet(Data::Db::TDataSet* const Value);
	void __fastcall SetFilterOptions(TcxDBFilterOptions* Value);
	void __fastcall SetItems(TcxFilterItemCollection* Value);
	
protected:
	System::UnicodeString __fastcall GetCaption(int Index);
	int __fastcall GetCount(void);
	Cxfilter::TcxFilterCriteria* __fastcall GetCriteria(void);
	System::TObject* __fastcall GetItemLink(int Index);
	int __fastcall GetItemLinkID(int Index);
	System::UnicodeString __fastcall GetItemLinkName(int Index);
	System::UnicodeString __fastcall GetFieldName(int Index);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(int Index);
	Cxdatastorage::TcxValueTypeClass __fastcall GetValueType(int Index);
	void __fastcall SetDialogLinkComponent(System::Classes::TComponent* ALink);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall CorrectOperatorClass(Cxfilter::TcxFilterOperatorClass &AOperatorClass);
	virtual void __fastcall DoApplyFilter(void);
	virtual void __fastcall ValidateConditions(Cxfiltercontrolutils::TcxFilterControlOperators &SupportedOperations);
	virtual Cxfiltercontrol::_di_IcxFilterControl __fastcall GetFilterLink(void);
	
public:
	__fastcall virtual TcxDBFilterControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxDBFilterControl(void);
	virtual void __fastcall BuildFromCriteria(void);
	virtual void __fastcall Clear(void);
	System::UnicodeString __fastcall GetFilterTextEx(const System::UnicodeString AFieldNamePrefix, const System::UnicodeString AFieldNamePostfix);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClassFromFieldType(Data::Db::TFieldType AFieldType);
	__property Criteria;
	__property Data::Db::TDataSource* DataSource = {read=FDataSource};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AssignedFonts = {default=0};
	__property Color = {default=-16777201};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	__property TcxFilterItemCollection* Items = {read=GetItems, write=SetItems};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property TcxDBFilterOptions* FilterOptions = {read=GetFilterOptions, write=SetFilterOptions};
	__property Font;
	__property FontBoolOperator;
	__property FontCondition;
	__property FontItem;
	__property FontValue;
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property HelpType = {default=1};
	__property Hint = {default=0};
	__property HotTrackOnUnfocused = {default=1};
	__property LookAndFeel;
	__property Nullstring = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property ShowLevelLines = {default=1};
	__property SortItems = {default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property WantTabs = {default=0};
	__property OnApplyFilter;
	__property OnClick;
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBFilterControl(HWND ParentWindow) : Cxfiltercontrol::TcxCustomFilterControl(ParentWindow) { }
	
private:
	void *__IcxFilterControlDialog;	/* Cxfiltercontrol::IcxFilterControlDialog */
	void *__IcxFilterControl;	/* Cxfiltercontrol::IcxFilterControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D2369F8D-3B22-41A8-881E-B01BEB624B7D}
	operator Cxfiltercontrol::_di_IcxFilterControlDialog()
	{
		Cxfiltercontrol::_di_IcxFilterControlDialog intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxfiltercontrol::IcxFilterControlDialog*(void) { return (Cxfiltercontrol::IcxFilterControlDialog*)&__IcxFilterControlDialog; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B9890E09-5400-428D-8F72-1FF8FD15937C}
	operator Cxfiltercontrol::_di_IcxFilterControl()
	{
		Cxfiltercontrol::_di_IcxFilterControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxfiltercontrol::IcxFilterControl*(void) { return (Cxfiltercontrol::IcxFilterControl*)&__IcxFilterControl; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ExecuteDBFilterControlDialog(Data::Db::TDataSet* ADataSet, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, System::Classes::TNotifyEvent AOnApplyProc = 0x0, System::Classes::TNotifyEvent AOnShowDialog = 0x0, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), const System::UnicodeString AInitialDir = System::UnicodeString());
}	/* namespace Cxdbfiltercontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBFILTERCONTROL)
using namespace Cxdbfiltercontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbfiltercontrolHPP
