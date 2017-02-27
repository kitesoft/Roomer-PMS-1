// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDBBreadcrumbEdit.pas' rev: 24.00 (Win64)

#ifndef DxdbbreadcrumbeditHPP
#define DxdbbreadcrumbeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxBreadcrumbEdit.hpp>	// Pascal unit
#include <dxCustomTree.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdbbreadcrumbedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EdxDBBreadcrumbEditValidationError;
class PASCALIMPLEMENTATION EdxDBBreadcrumbEditValidationError : public Dxbreadcrumbedit::EdxBreadcrumbEditValidationError
{
	typedef Dxbreadcrumbedit::EdxBreadcrumbEditValidationError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxDBBreadcrumbEditValidationError(const System::UnicodeString Msg) : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxDBBreadcrumbEditValidationError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxDBBreadcrumbEditValidationError(NativeUInt Ident)/* overload */ : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxDBBreadcrumbEditValidationError(System::PResStringRec ResStringRec)/* overload */ : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxDBBreadcrumbEditValidationError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxDBBreadcrumbEditValidationError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxDBBreadcrumbEditValidationError(const System::UnicodeString Msg, int AHelpContext) : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxDBBreadcrumbEditValidationError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxDBBreadcrumbEditValidationError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxDBBreadcrumbEditValidationError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxDBBreadcrumbEditValidationError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxDBBreadcrumbEditValidationError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxbreadcrumbedit::EdxBreadcrumbEditValidationError(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxDBBreadcrumbEditValidationError(void) { }
	
};


__interface IdxDBBreadCrumbEdit;
typedef System::DelphiInterface<IdxDBBreadCrumbEdit> _di_IdxDBBreadCrumbEdit;
class DELPHICLASS TdxDBBreadcrumbEditDataBinding;
__interface  INTERFACE_UUID("{B5813847-E4A4-4789-8673-488107711B74}") IdxDBBreadCrumbEdit  : public Dxbreadcrumbedit::IdxBreadcrumbEdit 
{
	
public:
	virtual TdxDBBreadcrumbEditDataBinding* __fastcall GetDataBinding(void) = 0 ;
	virtual System::Variant __fastcall GetRootValue(void) = 0 ;
	virtual void __fastcall RecordChanged(Data::Db::TField* AField) = 0 ;
	virtual void __fastcall StructureChanged(void) = 0 ;
	virtual void __fastcall SynchronizeSelection(void) = 0 ;
};

class DELPHICLASS TdxDBBreadcrumbEditDataLink;
class PASCALIMPLEMENTATION TdxDBBreadcrumbEditDataLink : public Cxdbdata::TcxDBCustomDataLink
{
	typedef Cxdbdata::TcxDBCustomDataLink inherited;
	
private:
	bool FDataBusy;
	bool FDataLocate;
	TdxDBBreadcrumbEditDataBinding* FOwner;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual bool __fastcall GetIsDataSetBusyState(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
	virtual void __fastcall SelectionChanged(void);
	virtual void __fastcall StructureChanged(void);
	virtual void __fastcall UpdateData(void);
	
public:
	__fastcall virtual TdxDBBreadcrumbEditDataLink(TdxDBBreadcrumbEditDataBinding* AOwner);
	__property bool DataBusy = {read=FDataBusy, write=FDataBusy, nodefault};
	__property bool DataLocate = {read=FDataLocate, write=FDataLocate, nodefault};
	__property TdxDBBreadcrumbEditDataBinding* Owner = {read=FOwner};
public:
	/* TcxDBCustomDataLink.Destroy */ inline __fastcall virtual ~TdxDBBreadcrumbEditDataLink(void) { }
	
};


class PASCALIMPLEMENTATION TdxDBBreadcrumbEditDataBinding : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	_di_IdxDBBreadCrumbEdit FControl;
	TdxDBBreadcrumbEditDataLink* FDataLink;
	Data::Db::TField* FImageIndexField;
	System::UnicodeString FImageIndexFieldName;
	Data::Db::TField* FKeyField;
	System::UnicodeString FKeyFieldName;
	Data::Db::TField* FNameField;
	System::UnicodeString FNameFieldName;
	Data::Db::TField* FParentKeyField;
	System::UnicodeString FParentKeyFieldName;
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	bool __fastcall GetIsRequeredFieldsAssigned(void);
	void __fastcall DoSetFieldValue(const System::UnicodeString AValue, System::UnicodeString &AFieldValue);
	void __fastcall SetDataSource(Data::Db::TDataSource* AValue);
	void __fastcall SetImageIndexFieldName(const System::UnicodeString AValue);
	void __fastcall SetKeyFieldName(const System::UnicodeString AValue);
	void __fastcall SetNameFieldName(const System::UnicodeString AValue);
	void __fastcall SetParentKeyFieldName(const System::UnicodeString AValue);
	
protected:
	virtual TdxDBBreadcrumbEditDataLink* __fastcall CreateDataLink(void);
	Data::Db::TField* __fastcall GetFieldByName(const System::UnicodeString AFieldName);
	virtual void __fastcall BindFields(void);
	virtual void __fastcall RecordChanged(Data::Db::TField* AField);
	virtual void __fastcall SelectionChanged(void);
	virtual void __fastcall StructureChanged(void);
	__property _di_IdxDBBreadCrumbEdit Control = {read=FControl};
	__property TdxDBBreadcrumbEditDataLink* DataLink = {read=FDataLink};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property Data::Db::TField* FieldImageIndex = {read=FImageIndexField};
	__property Data::Db::TField* FieldKey = {read=FKeyField};
	__property Data::Db::TField* FieldName = {read=FNameField};
	__property Data::Db::TField* FieldParentKey = {read=FParentKeyField};
	__property bool IsRequeredFieldsAssigned = {read=GetIsRequeredFieldsAssigned, nodefault};
	
public:
	__fastcall virtual TdxDBBreadcrumbEditDataBinding(System::Classes::TPersistent* AOwner, _di_IdxDBBreadCrumbEdit AControl);
	__fastcall virtual ~TdxDBBreadcrumbEditDataBinding(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property System::UnicodeString ImageIndexField = {read=FImageIndexFieldName, write=SetImageIndexFieldName};
	__property System::UnicodeString KeyField = {read=FKeyFieldName, write=SetKeyFieldName};
	__property System::UnicodeString NameField = {read=FNameFieldName, write=SetNameFieldName};
	__property System::UnicodeString ParentKeyField = {read=FParentKeyFieldName, write=SetParentKeyFieldName};
};


class DELPHICLASS TdxDBBreadcrumbEditProperties;
class PASCALIMPLEMENTATION TdxDBBreadcrumbEditProperties : public Dxbreadcrumbedit::TdxCustomBreadcrumbEditProperties
{
	typedef Dxbreadcrumbedit::TdxCustomBreadcrumbEditProperties inherited;
	
__published:
	__property Borders = {default=15};
	__property ButtonImages;
	__property Buttons;
	__property DropDownRows = {default=18};
	__property Images;
	__property PathEditor;
	__property ProgressBar;
public:
	/* TdxCustomBreadcrumbEditProperties.Create */ inline __fastcall virtual TdxDBBreadcrumbEditProperties(System::Classes::TPersistent* AOwner) : Dxbreadcrumbedit::TdxCustomBreadcrumbEditProperties(AOwner) { }
	/* TdxCustomBreadcrumbEditProperties.Destroy */ inline __fastcall virtual ~TdxDBBreadcrumbEditProperties(void) { }
	
};


class DELPHICLASS TdxDBBreadcrumbEditNode;
class PASCALIMPLEMENTATION TdxDBBreadcrumbEditNode : public Dxbreadcrumbedit::TdxBreadcrumbEditNode
{
	typedef Dxbreadcrumbedit::TdxBreadcrumbEditNode inherited;
	
public:
	TdxDBBreadcrumbEditNode* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	System::Variant FKeyValue;
	System::Variant FParentKeyValue;
	HIDESBASE TdxDBBreadcrumbEditNode* __fastcall GetItem(int AIndex);
	HIDESBASE TdxDBBreadcrumbEditNode* __fastcall GetParent(void);
	
public:
	HIDESBASE TdxDBBreadcrumbEditNode* __fastcall AddChild(void)/* overload */;
	virtual void __fastcall Clear(void);
	__property TdxDBBreadcrumbEditNode* Items[int AIndex] = {read=GetItem/*, default*/};
	__property System::Variant KeyValue = {read=FKeyValue, write=FKeyValue};
	__property TdxDBBreadcrumbEditNode* Parent = {read=GetParent};
	__property System::Variant ParentKeyValue = {read=FParentKeyValue, write=FParentKeyValue};
public:
	/* TdxTreeCustomNode.Create */ inline __fastcall virtual TdxDBBreadcrumbEditNode(Dxcustomtree::_di_IdxTreeOwner AOwner) : Dxbreadcrumbedit::TdxBreadcrumbEditNode(AOwner) { }
	/* TdxTreeCustomNode.Destroy */ inline __fastcall virtual ~TdxDBBreadcrumbEditNode(void) { }
	
/* Hoisted overloads: */
	
public:
	inline Dxbreadcrumbedit::TdxBreadcrumbEditNode* __fastcall  AddChild(const System::UnicodeString AName, System::Uitypes::TImageIndex AImageIndex = (System::Uitypes::TImageIndex)(0xffffffff), void * AData = (void *)(0x0)){ return Dxbreadcrumbedit::TdxBreadcrumbEditNode::AddChild(AName, AImageIndex, AData); }
	
};


class DELPHICLASS TdxDBBreadcrumbEditDataLoader;
class PASCALIMPLEMENTATION TdxDBBreadcrumbEditDataLoader : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	_di_IdxDBBreadCrumbEdit FControl;
	TdxDBBreadcrumbEditDataBinding* __fastcall GetDataBinding(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	TdxDBBreadcrumbEditNode* __fastcall GetRootNode(void);
	
protected:
	virtual void __fastcall BuildStructure(System::Classes::TList* AList);
	bool __fastcall FindLoadedNode(System::Classes::TList* AList, const System::Variant &AParentKeyValue, /* out */ TdxDBBreadcrumbEditNode* &ANode);
	int __fastcall GetImageIndexAsInteger(Data::Db::TField* AField);
	System::UnicodeString __fastcall GetNameAsString(Data::Db::TField* AField);
	virtual void __fastcall LoadAllRecords(System::Classes::TList* AList);
	
public:
	__fastcall virtual TdxDBBreadcrumbEditDataLoader(_di_IdxDBBreadCrumbEdit AControl);
	virtual void __fastcall LoadNodeData(TdxDBBreadcrumbEditNode* ANode);
	virtual void __fastcall RebuildStructure(void);
	__property _di_IdxDBBreadCrumbEdit Control = {read=FControl};
	__property TdxDBBreadcrumbEditDataBinding* DataBinding = {read=GetDataBinding};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property TdxDBBreadcrumbEditNode* RootNode = {read=GetRootNode};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDBBreadcrumbEditDataLoader(void) { }
	
};


enum TdxDBBreadcrumbEditControllerState : unsigned char { dxdbbecsSynchronizingSelection, dxdbbecsUpdatingRecord, dxdbbecsLocating };

typedef System::Set<TdxDBBreadcrumbEditControllerState, TdxDBBreadcrumbEditControllerState::dxdbbecsSynchronizingSelection, TdxDBBreadcrumbEditControllerState::dxdbbecsLocating>  TdxDBBreadcrumbEditControllerStates;

class DELPHICLASS TdxDBBreadcrumbEditController;
class PASCALIMPLEMENTATION TdxDBBreadcrumbEditController : public Dxbreadcrumbedit::TdxBreadcrumbEditController
{
	typedef Dxbreadcrumbedit::TdxBreadcrumbEditController inherited;
	
private:
	HIDESBASE _di_IdxDBBreadCrumbEdit __fastcall GetControl(void);
	TdxDBBreadcrumbEditDataBinding* __fastcall GetDataBinding(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	HIDESBASE TdxDBBreadcrumbEditNode* __fastcall GetRoot(void);
	
protected:
	TdxDBBreadcrumbEditControllerStates FState;
	virtual bool __fastcall CanSelectNode(Dxbreadcrumbedit::TdxBreadcrumbEditNode* ANode);
	virtual void __fastcall SelectionChanged(void);
	__property TdxDBBreadcrumbEditNode* Root = {read=GetRoot};
	
public:
	TdxDBBreadcrumbEditNode* __fastcall FindNodeByKeyValue(const System::Variant &AKeyValue)/* overload */;
	virtual bool __fastcall FindNodeByKeyValue(const System::Variant &AKeyValue, /* out */ TdxDBBreadcrumbEditNode* &ANode)/* overload */;
	virtual bool __fastcall ProcessParentKeyValueChanges(const System::Variant &ANewParentKeyValue);
	virtual void __fastcall Locate(TdxDBBreadcrumbEditNode* ANode);
	virtual void __fastcall SynchronizeSelection(void);
	__property _di_IdxDBBreadCrumbEdit Control = {read=GetControl};
	__property TdxDBBreadcrumbEditDataBinding* DataBinding = {read=GetDataBinding};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property TdxDBBreadcrumbEditControllerStates State = {read=FState, nodefault};
public:
	/* TdxBreadcrumbEditController.Create */ inline __fastcall virtual TdxDBBreadcrumbEditController(Dxbreadcrumbedit::TdxBreadcrumbEditViewInfo* AViewInfo) : Dxbreadcrumbedit::TdxBreadcrumbEditController(AViewInfo) { }
	/* TdxBreadcrumbEditController.Destroy */ inline __fastcall virtual ~TdxDBBreadcrumbEditController(void) { }
	
};


class DELPHICLASS TdxCustomDBBreadCrumbEdit;
class PASCALIMPLEMENTATION TdxCustomDBBreadCrumbEdit : public Dxbreadcrumbedit::TdxCustomBreadcrumbEdit
{
	typedef Dxbreadcrumbedit::TdxCustomBreadcrumbEdit inherited;
	
private:
	TdxDBBreadcrumbEditDataBinding* FDataBinding;
	TdxDBBreadcrumbEditDataLoader* FDataLoader;
	System::Variant FRootValue;
	TdxDBBreadcrumbEditController* __fastcall GetDBController(void);
	TdxDBBreadcrumbEditProperties* __fastcall GetDBProperties(void);
	TdxDBBreadcrumbEditNode* __fastcall GetDBRoot(void);
	HIDESBASE TdxDBBreadcrumbEditNode* __fastcall GetSelected(void);
	void __fastcall SetDataBinding(TdxDBBreadcrumbEditDataBinding* AValue);
	void __fastcall SetDBProperties(TdxDBBreadcrumbEditProperties* AValue);
	void __fastcall SetRootValue(const System::Variant &AValue);
	HIDESBASE void __fastcall SetSelected(TdxDBBreadcrumbEditNode* AValue);
	
protected:
	virtual Dxbreadcrumbedit::TdxBreadcrumbEditController* __fastcall CreateController(void);
	virtual TdxDBBreadcrumbEditDataBinding* __fastcall CreateDataBinding(void);
	virtual TdxDBBreadcrumbEditDataLoader* __fastcall CreateDataLoader(void);
	virtual Dxbreadcrumbedit::TdxCustomBreadcrumbEditProperties* __fastcall CreateProperties(void);
	virtual Dxbreadcrumbedit::TdxBreadcrumbEditNode* __fastcall CreateRoot(void);
	TdxDBBreadcrumbEditDataBinding* __fastcall GetDataBinding(void);
	System::Variant __fastcall GetRootValue(void);
	void __fastcall RecordChanged(Data::Db::TField* AField);
	void __fastcall StructureChanged(void);
	void __fastcall SynchronizeSelection(void);
	__property TdxDBBreadcrumbEditController* Controller = {read=GetDBController};
	__property TdxDBBreadcrumbEditDataLoader* DataLoader = {read=FDataLoader};
	
public:
	__fastcall virtual TdxCustomDBBreadCrumbEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomDBBreadCrumbEdit(void);
	__property TdxDBBreadcrumbEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property TdxDBBreadcrumbEditProperties* Properties = {read=GetDBProperties, write=SetDBProperties};
	__property TdxDBBreadcrumbEditNode* Root = {read=GetDBRoot};
	__property System::Variant RootValue = {read=GetRootValue, write=SetRootValue};
	__property TdxDBBreadcrumbEditNode* Selected = {read=GetSelected, write=SetSelected};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomDBBreadCrumbEdit(HWND ParentWindow) : Dxbreadcrumbedit::TdxCustomBreadcrumbEdit(ParentWindow) { }
	
private:
	void *__IdxDBBreadCrumbEdit;	/* IdxDBBreadCrumbEdit */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B5813847-E4A4-4789-8673-488107711B74}
	operator _di_IdxDBBreadCrumbEdit()
	{
		_di_IdxDBBreadCrumbEdit intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxDBBreadCrumbEdit*(void) { return (IdxDBBreadCrumbEdit*)&__IdxDBBreadCrumbEdit; }
	#endif
	
};


class DELPHICLASS TdxDBBreadcrumbEdit;
class PASCALIMPLEMENTATION TdxDBBreadcrumbEdit : public TdxCustomDBBreadCrumbEdit
{
	typedef TdxCustomDBBreadCrumbEdit inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property Color = {default=536870912};
	__property DataBinding;
	__property Enabled = {default=1};
	__property Font;
	__property LookAndFeel;
	__property ParentShowHint = {default=1};
	__property Properties;
	__property RootValue = {default=0};
	__property ShowHint;
	__property Transparent = {default=0};
	__property OnButtonClick;
	__property OnPathEntered;
	__property OnPathSelected;
	__property OnPathValidate;
	__property OnPopulateAutoCompleteSuggestions;
public:
	/* TdxCustomDBBreadCrumbEdit.Create */ inline __fastcall virtual TdxDBBreadcrumbEdit(System::Classes::TComponent* AOwner) : TdxCustomDBBreadCrumbEdit(AOwner) { }
	/* TdxCustomDBBreadCrumbEdit.Destroy */ inline __fastcall virtual ~TdxDBBreadcrumbEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDBBreadcrumbEdit(HWND ParentWindow) : TdxCustomDBBreadCrumbEdit(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdbbreadcrumbedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDBBREADCRUMBEDIT)
using namespace Dxdbbreadcrumbedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdbbreadcrumbeditHPP
