// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxViewEditor.pas' rev: 24.00 (Win32)

#ifndef CxvieweditorHPP
#define CxvieweditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <cxLibraryReg.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvieweditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxViewEditor;
class PASCALIMPLEMENTATION TcxViewEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* PViewEditor;
	void __fastcall FormKeyPress(System::TObject* Sender, System::WideChar &Key);
	
private:
	Cxgridcustomview::TcxCustomGridView* FView;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	System::Classes::TComponent* __fastcall GetOwnerForm(void);
	
protected:
	void __fastcall BeginUpdate(void);
	bool __fastcall CanAddComponent(void);
	bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent);
	void __fastcall EndUpdate(void);
	void __fastcall GetSelectionList(System::Classes::TList* AList);
	void __fastcall SelectComponent(System::Classes::TPersistent* AComponent);
	virtual System::UnicodeString __fastcall UniqueName(System::Classes::TComponent* AComponent, const System::UnicodeString ATruncateClassName = L"TcxGrid");
	virtual void __fastcall UpdateDesigner(void);
	virtual void __fastcall UpdateEditor(void);
	virtual void __fastcall UpdateSelection(void);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	
public:
	Cxdesignwindows::TcxDesignFormEditor* FormEditor;
	__classmethod virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetViewByObject(System::Classes::TPersistent* APersistent);
	void __fastcall SetView(Cxgridcustomview::TcxCustomGridView* Value, bool ARefreshNeeded);
	__property System::Classes::TComponent* OwnerForm = {read=GetOwnerForm};
	__property Cxgridcustomview::TcxCustomGridView* View = {read=FView};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxViewEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxViewEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxViewEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxViewEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxViewEditorClass;

class DELPHICLASS TcxCustomGridViewStorage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewStorage : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	Cxgridcustomview::TcxCustomGridView* FView;
	
protected:
	System::UnicodeString __fastcall GetObjectName(void);
	bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property Cxgridcustomview::TcxCustomGridView* View = {read=FView};
	
public:
	__fastcall virtual TcxCustomGridViewStorage(Cxgridcustomview::TcxCustomGridView* AView);
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridViewStorage(void) { }
	
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

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridViewStorageClass;

class DELPHICLASS TcxGridViewMenuItem;
typedef void __fastcall (__closure *TcxGridViewMenuItemActionEvent)(TcxGridViewMenuItem* Sender);

class DELPHICLASS TcxGridViewMenuItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewMenuItems : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridViewMenuItem* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxGridViewMenuItem* __fastcall GetItem(int Index);
	
protected:
	void __fastcall ClearItems(void);
	
public:
	__fastcall TcxGridViewMenuItems(void);
	__fastcall virtual ~TcxGridViewMenuItems(void);
	TcxGridViewMenuItem* __fastcall AddItem(const System::UnicodeString ACaption, TcxGridViewMenuItemActionEvent AOnClick = 0x0, bool AEnabled = true, bool AChecked = false, System::TObject* AData = (System::TObject*)(0x0));
	TcxGridViewMenuItem* __fastcall AddSeparator(void);
	void __fastcall Delete(int AIndex);
	virtual void __fastcall Prepare(Vcl::Menus::TMenuItem* AMenuItem)/* overload */;
	virtual void __fastcall Prepare(const Designmenus::_di_IMenuItem AMenuItem)/* overload */;
	void __fastcall RemoveExcessSeparators(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridViewMenuItem* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGridViewMenuItem : public TcxGridViewMenuItems
{
	typedef TcxGridViewMenuItems inherited;
	
private:
	Designmenus::_di_IMenuItem FDesignItem;
	void __fastcall MenuItemClick(System::TObject* Sender);
	
protected:
	TcxGridViewMenuItemActionEvent OnAction;
	
public:
	System::UnicodeString Caption;
	bool Checked;
	System::TObject* Data;
	bool Enabled;
	__fastcall TcxGridViewMenuItem(const System::UnicodeString ACaption, bool AEnabled, bool AChecked, System::TObject* AData, TcxGridViewMenuItemActionEvent AOnAction);
	__fastcall virtual ~TcxGridViewMenuItem(void);
	void __fastcall DoAction(void);
	bool __fastcall IsSeparator(void);
	virtual void __fastcall Prepare(Vcl::Menus::TMenuItem* AMenuItem)/* overload */;
	virtual void __fastcall Prepare(const Designmenus::_di_IMenuItem AMenuItem)/* overload */;
};


typedef System::TMetaClass* TcxCustomGridViewMenuProviderClass;

class DELPHICLASS TcxCustomGridViewMenuProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewMenuProvider : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Designintf::_di_IDesigner FDesigner;
	Cxdesignwindows::TcxDesignHelper* FDesignHelper;
	Cxgridcustomview::TcxCustomGridView* FGridView;
	TcxGridViewMenuItems* FItems;
	System::Classes::TStringList* FDBDataSourceNames;
	System::Classes::TStringList* FServerModeDataSourceNames;
	void __fastcall GetDBDataSourceName(const System::UnicodeString S);
	Data::Db::TDataSource* __fastcall GetDBViewDataSource(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetDBGridView(void);
	void __fastcall SetDBViewDataSource(Data::Db::TDataSource* Value);
	void __fastcall GetServerModeDataSourceName(const System::UnicodeString S);
	Dxservermodedata::TdxServerModeCustomDataSource* __fastcall GetServerModeViewDataSource(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetServerModeGridView(void);
	void __fastcall SetServerModeViewDataSource(Dxservermodedata::TdxServerModeCustomDataSource* Value);
	
protected:
	void __fastcall DesignerModified(void);
	void __fastcall ObjectCreated(System::Classes::TPersistent* AObject);
	void __fastcall SelectObject(System::Classes::TPersistent* AObject);
	virtual void __fastcall InitAdditionalItems(void);
	virtual void __fastcall InitCopySettingsFromViewItem(void);
	virtual void __fastcall InitDataBindingItems(void);
	virtual void __fastcall InitDBDataBindingItems(void);
	virtual void __fastcall InitServerModeDataBindingItems(void);
	virtual void __fastcall InitItems(void);
	virtual void __fastcall InitLayoutItems(void);
	virtual void __fastcall InitStructureItems(void);
	void __fastcall CopySettings(TcxGridViewMenuItem* Sender);
	void __fastcall DeleteView(TcxGridViewMenuItem* Sender);
	void __fastcall EditLayoutAndData(TcxGridViewMenuItem* Sender);
	void __fastcall SetAsDefault(TcxGridViewMenuItem* Sender);
	System::Classes::TStringList* __fastcall GetDBDataSourceNames(void);
	void __fastcall LinkToDBDataSource(TcxGridViewMenuItem* Sender);
	System::Classes::TStringList* __fastcall GetServerModeDataSourceNames(void);
	void __fastcall LinkToServerModeDataSource(TcxGridViewMenuItem* Sender);
	__property Data::Db::TDataSource* DBViewDataSource = {read=GetDBViewDataSource, write=SetDBViewDataSource};
	__property Cxgridcustomview::TcxCustomGridView* DBGridView = {read=GetDBGridView};
	__property Dxservermodedata::TdxServerModeCustomDataSource* ServerModeViewDataSource = {read=GetServerModeViewDataSource, write=SetServerModeViewDataSource};
	__property Cxgridcustomview::TcxCustomGridView* ServerModeGridView = {read=GetServerModeGridView};
	__property Designintf::_di_IDesigner Designer = {read=FDesigner};
	__property Cxdesignwindows::TcxDesignHelper* DesignHelper = {read=FDesignHelper};
	
public:
	__fastcall virtual TcxCustomGridViewMenuProvider(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridViewMenuProvider(void);
	__property Cxgridcustomview::TcxCustomGridView* GridView = {read=FGridView};
	__property TcxGridViewMenuItems* Items = {read=FItems};
};

#pragma pack(pop)

class DELPHICLASS TcxGridViewList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Designintf::_di_IDesigner FDesigner;
	System::Classes::TStringList* FViewNames;
	Cxgridcustomview::TcxCustomGridView* __fastcall GetView(int Index);
	void __fastcall AddViewName(const System::UnicodeString S);
	
protected:
	virtual void __fastcall GetViewNames(void);
	
public:
	__fastcall TcxGridViewList(Designintf::_di_IDesigner ADesigner);
	__fastcall virtual ~TcxGridViewList(void);
	int __fastcall GetViewIndex(Cxgridcustomview::TcxCustomGridView* AView);
	__property Designintf::_di_IDesigner Designer = {read=FDesigner};
	__property System::Classes::TStringList* ViewNames = {read=FViewNames};
	__property Cxgridcustomview::TcxCustomGridView* Views[int Index] = {read=GetView};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::WideChar cxGridViewMenuSeparatorCaption = (System::WideChar)(0x2d);
extern PACKAGE TcxViewEditorClass __fastcall GetViewEditorClass(Cxgridcustomview::TcxCustomGridViewClass AViewClass);
extern PACKAGE void __fastcall RegisterViewEditorClass(Cxgridcustomview::TcxCustomGridViewClass AViewClass, TcxViewEditorClass AViewEditorClass);
extern PACKAGE void __fastcall UnregisterViewEditorClass(Cxgridcustomview::TcxCustomGridViewClass AViewClass, TcxViewEditorClass AViewEditorClass);
extern PACKAGE Cxgridcustomview::TcxCustomGridView* __fastcall GetLinkedView(System::Classes::TPersistent* APersistent);
extern PACKAGE bool __fastcall IsViewLinkedToComponent(Cxgridcustomview::TcxCustomGridView* AView, System::Classes::TComponent* AComponent);
extern PACKAGE System::UnicodeString __fastcall GetViewTemplateRegKey(void);
extern PACKAGE void __fastcall RegisterDefaultViewStorage(TcxCustomGridViewStorageClass AStorageClass);
extern PACKAGE void __fastcall UnregisterDefaultViewStorage(TcxCustomGridViewStorageClass AStorageClass);
extern PACKAGE TcxCustomGridViewStorage* __fastcall GetDefaultViewStorageByViewClass(Cxgridcustomview::TcxCustomGridView* AGridView);
extern PACKAGE void __fastcall RestoreViewFromTemplate(const System::UnicodeString ARegPath, Cxgridcustomview::TcxCustomGridView* AView);
extern PACKAGE void __fastcall SaveViewToTemplate(const System::UnicodeString ARegPath, Cxgridcustomview::TcxCustomGridView* AView);
extern PACKAGE TcxCustomGridViewMenuProvider* __fastcall CreateViewMenuProvider(Cxgridcustomview::TcxCustomGridView* AView);
extern PACKAGE TcxCustomGridViewMenuProviderClass __fastcall GetViewMenuProviderClass(Cxgridcustomview::TcxCustomGridView* AView);
extern PACKAGE void __fastcall RegisterViewMenuProviderClass(Cxgridcustomview::TcxCustomGridViewClass AViewClass, TcxCustomGridViewMenuProviderClass AViewMenuProviderClass);
extern PACKAGE void __fastcall UnregisterViewMenuProviderClass(Cxgridcustomview::TcxCustomGridViewClass AViewClass, TcxCustomGridViewMenuProviderClass AViewMenuProviderClass);
}	/* namespace Cxvieweditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVIEWEDITOR)
using namespace Cxvieweditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvieweditorHPP
