// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBTL.pas' rev: 24.00 (Win64)

#ifndef CxdbtlHPP
#define CxdbtlHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxEditDBRegisteredRepositoryItems.hpp>	// Pascal unit
#include <cxTL.hpp>	// Pascal unit
#include <cxTLData.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbtl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBTreeListNode;
class PASCALIMPLEMENTATION TcxDBTreeListNode : public Cxtl::TcxTreeListNode
{
	typedef Cxtl::TcxTreeListNode inherited;
	
private:
	System::Variant FKeyValue;
	System::Variant FParentKeyValue;
	
public:
	__property System::Variant KeyValue = {read=FKeyValue, write=FKeyValue};
	__property System::Variant ParentKeyValue = {read=FParentKeyValue, write=FParentKeyValue};
public:
	/* TcxTreeListNode.Create */ inline __fastcall virtual TcxDBTreeListNode(Cxtl::TcxCustomTreeList* AOwner) : Cxtl::TcxTreeListNode(AOwner) { }
	/* TcxTreeListNode.Destroy */ inline __fastcall virtual ~TcxDBTreeListNode(void) { }
	
};


class DELPHICLASS TcxTreeListDataLink;
class DELPHICLASS TcxDBTreeListDataController;
class DELPHICLASS TcxDBTreeListOptionsData;
class DELPHICLASS TcxCustomDBTreeList;
class PASCALIMPLEMENTATION TcxTreeListDataLink : public Cxdbdata::TcxDBCustomDataLink
{
	typedef Cxdbdata::TcxDBCustomDataLink inherited;
	
private:
	TcxDBTreeListDataController* FDataController;
	bool FIsLayoutChanged;
	bool FModified;
	bool __fastcall GetDataBusy(void);
	bool __fastcall GetDataLocate(void);
	TcxDBTreeListOptionsData* __fastcall GetOptionsData(void);
	TcxCustomDBTreeList* __fastcall GetTreeList(void);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataEvent(Data::Db::TDataEvent Event, NativeInt Info);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall FocusControl(Data::Db::TFieldRef Field);
	virtual bool __fastcall GetIsDataSetBusyState(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
	virtual void __fastcall UpdateData(void);
	
public:
	__fastcall virtual TcxTreeListDataLink(TcxDBTreeListDataController* ADataController);
	__property bool DataBusy = {read=GetDataBusy, nodefault};
	__property bool DataLocate = {read=GetDataLocate, nodefault};
	__property TcxDBTreeListDataController* DataController = {read=FDataController};
	__property bool Modified = {read=FModified, write=FModified, nodefault};
	__property TcxDBTreeListOptionsData* OptionsData = {read=GetOptionsData};
	__property TcxCustomDBTreeList* TreeList = {read=GetTreeList};
public:
	/* TcxDBCustomDataLink.Destroy */ inline __fastcall virtual ~TcxTreeListDataLink(void) { }
	
};


class PASCALIMPLEMENTATION TcxDBTreeListDataController : public Cxtldata::TcxDataTreeListDataController
{
	typedef Cxtldata::TcxDataTreeListDataController inherited;
	
private:
	TcxTreeListDataLink* FDataLink;
	Data::Db::TField* FImageIndexField;
	System::UnicodeString FImageIndexFieldName;
	Data::Db::TField* FKeyField;
	System::UnicodeString FKeyFieldName;
	Data::Db::TField* FParentKeyField;
	System::UnicodeString FParentKeyFieldName;
	System::UnicodeString FStateIndexFieldName;
	Data::Db::TField* FStateIndexField;
	bool FUpdateEditing;
	bool FUpdateInserting;
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	HIDESBASE TcxCustomDBTreeList* __fastcall GetTreeList(void);
	void __fastcall SetDataSource(Data::Db::TDataSource* AValue);
	void __fastcall SetImageIndexFieldName(const System::UnicodeString AValue);
	void __fastcall SetKeyFieldName(const System::UnicodeString AValue);
	void __fastcall SetParentKeyFieldName(const System::UnicodeString AValue);
	void __fastcall SetStateIndexFieldName(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall AfterLoad(void);
	bool __fastcall CanLocateByNode(TcxDBTreeListNode* AOldNode, TcxDBTreeListNode* ANode);
	virtual TcxTreeListDataLink* __fastcall CreateDataLink(void);
	virtual Cxtldata::TcxTreeListStructureLoader* __fastcall CreateLoader(void);
	virtual void __fastcall DataScrolled(int ADistance);
	virtual void __fastcall DeleteChildren(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DeleteNode(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DestroyInternalFields(void);
	void __fastcall DoCopyTo(TcxDBTreeListNode* AttachNode, Cxtl::TcxTreeListNodeAttachMode AttachMode, System::Classes::TList* ANodes);
	virtual void __fastcall DoInitInsertingNode(Cxtl::TcxTreeListNode* ANode);
	virtual Cxcustomdata::TcxDataControllerEditState __fastcall GetEditState(void);
	Data::Db::TField* __fastcall GetFieldByName(const System::UnicodeString AFieldName);
	bool __fastcall GetIsKeyFieldsEmpty(void);
	System::Variant __fastcall GetUniqueKeyValue(int Delta = 0x0);
	virtual bool __fastcall IsDataMode(void);
	virtual bool __fastcall IsSmartLoad(void);
	virtual void __fastcall PostRecord(void);
	virtual void __fastcall PostValues(void);
	void __fastcall SetFieldName(System::UnicodeString &AField, const System::UnicodeString AValue);
	void __fastcall SetNodeParentValue(TcxDBTreeListNode* ANode, const System::Variant &AValue);
	virtual void __fastcall SyncFocused(Cxtl::TcxTreeListNode* ANode);
	void __fastcall UpdateActive(void);
	virtual void __fastcall UpdateFocused(void);
	virtual void __fastcall UpdateInternalFields(void);
	__property TcxTreeListDataLink* DataLink = {read=FDataLink};
	__property Data::Db::TField* DBKeyField = {read=FKeyField};
	__property Data::Db::TField* DBParentField = {read=FParentKeyField};
	__property Data::Db::TField* DBStateIndexField = {read=FStateIndexField};
	__property Data::Db::TField* DBImageIndexField = {read=FImageIndexField};
	__property bool IsKeyFieldsEmpty = {read=GetIsKeyFieldsEmpty, nodefault};
	__property bool UpdateEditing = {read=FUpdateEditing, write=FUpdateEditing, nodefault};
	__property bool UpdateInserting = {read=FUpdateInserting, write=FUpdateInserting, nodefault};
	
public:
	__fastcall virtual TcxDBTreeListDataController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxDBTreeListDataController(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Append(void);
	virtual void __fastcall Cancel(void);
	virtual void __fastcall CheckBrowseMode(void);
	virtual void __fastcall CreateAllItems(void);
	virtual void __fastcall Edit(void);
	virtual void __fastcall FocusControl(int AItemIndex, bool &Done);
	virtual void __fastcall Insert(void);
	bool __fastcall LocateByKey(const System::Variant &AKeyValue);
	bool __fastcall LocateByKeyEx(const System::Variant &AKeyValue);
	virtual bool __fastcall SetEditValue(int AItemIndex, const System::Variant &AValue, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property TcxCustomDBTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property System::UnicodeString ImageIndexField = {read=FImageIndexFieldName, write=SetImageIndexFieldName};
	__property System::UnicodeString ParentField = {read=FParentKeyFieldName, write=SetParentKeyFieldName};
	__property System::UnicodeString KeyField = {read=FKeyFieldName, write=SetKeyFieldName};
	__property System::UnicodeString StateIndexField = {read=FStateIndexFieldName, write=SetStateIndexFieldName};
};


class DELPHICLASS TcxDBTreeListDefaultValuesProvider;
class PASCALIMPLEMENTATION TcxDBTreeListDefaultValuesProvider : public Cxdbedit::TcxCustomDBEditDefaultValuesProvider
{
	typedef Cxdbedit::TcxCustomDBEditDefaultValuesProvider inherited;
	
public:
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
public:
	/* TcxCustomDBEditDefaultValuesProvider.Create */ inline __fastcall virtual TcxDBTreeListDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Cxdbedit::TcxCustomDBEditDefaultValuesProvider(AOwner) { }
	/* TcxCustomDBEditDefaultValuesProvider.Destroy */ inline __fastcall virtual ~TcxDBTreeListDefaultValuesProvider(void) { }
	
};


class DELPHICLASS TcxDBItemDataBinding;
class PASCALIMPLEMENTATION TcxDBItemDataBinding : public Cxinplacecontainer::TcxCustomItemDataBinding
{
	typedef Cxinplacecontainer::TcxCustomItemDataBinding inherited;
	
private:
	Data::Db::TField* FField;
	System::UnicodeString FFieldName;
	HIDESBASE TcxDBTreeListDataController* __fastcall GetDataController(void);
	TcxDBTreeListDefaultValuesProvider* __fastcall GetDefaultValuesProviderProperty(void);
	System::UnicodeString __fastcall GetFieldName(void);
	TcxCustomDBTreeList* __fastcall GetTreeList(void);
	void __fastcall SetFieldName(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall CheckFreeNotification(System::Classes::TComponent* AComponent);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual System::UnicodeString __fastcall GetDefaultCaption(void);
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	virtual void __fastcall Init(void);
	void __fastcall InitializeField(void);
	bool __fastcall IsDisplayFormatDefinedForColumn(bool AIgnoreSimpleCurrency);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	__property TcxDBTreeListDefaultValuesProvider* DefaultValuesProvider = {read=GetDefaultValuesProviderProperty};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxDBTreeListDataController* DataController = {read=GetDataController};
	__property Data::Db::TField* Field = {read=FField};
	__property TcxCustomDBTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property System::UnicodeString FieldName = {read=GetFieldName, write=SetFieldName};
public:
	/* TcxCustomItemDataBinding.Create */ inline __fastcall virtual TcxDBItemDataBinding(System::Classes::TPersistent* AOwner) : Cxinplacecontainer::TcxCustomItemDataBinding(AOwner) { }
	/* TcxCustomItemDataBinding.Destroy */ inline __fastcall virtual ~TcxDBItemDataBinding(void) { }
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};


class DELPHICLASS TcxDBTreeListColumn;
class PASCALIMPLEMENTATION TcxDBTreeListColumn : public Cxtl::TcxTreeListColumn
{
	typedef Cxtl::TcxTreeListColumn inherited;
	
private:
	HIDESBASE TcxDBItemDataBinding* __fastcall GetDataBinding(void);
	Data::Db::TField* __fastcall GetField(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBItemDataBinding* Value);
	
protected:
	void __fastcall AssignValueFromField(Cxtl::TcxTreeListNode* ANode);
	virtual Cxinplacecontainer::TcxItemDataBindingClass __fastcall GetDataBindingClass(void);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual bool __fastcall GetIsCurrency(void);
	virtual bool __fastcall GetIsTextStored(void);
	__property Data::Db::TField* Field = {read=GetField};
	
__published:
	__property TcxDBItemDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxTreeListColumn.Create */ inline __fastcall virtual TcxDBTreeListColumn(System::Classes::TComponent* AOwner) : Cxtl::TcxTreeListColumn(AOwner) { }
	/* TcxTreeListColumn.Destroy */ inline __fastcall virtual ~TcxDBTreeListColumn(void) { }
	
};


class PASCALIMPLEMENTATION TcxDBTreeListOptionsData : public Cxtldata::TcxVirtualTreeListOptionsData
{
	typedef Cxtldata::TcxVirtualTreeListOptionsData inherited;
	
private:
	bool FAutoCalcKeyValue;
	bool FSmartRefresh;
	bool FSyncMode;
	TcxCustomDBTreeList* __fastcall GetTreeList(void);
	void __fastcall SetSmartRefresh(bool AValue);
	void __fastcall SetSyncMode(bool AValue);
	
public:
	__fastcall virtual TcxDBTreeListOptionsData(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomDBTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property bool AutoCalcKeyValue = {read=FAutoCalcKeyValue, write=FAutoCalcKeyValue, default=0};
	__property bool SmartRefresh = {read=FSmartRefresh, write=SetSmartRefresh, default=0};
	__property bool SyncMode = {read=FSyncMode, write=SetSyncMode, default=1};
	__property SmartLoad = {default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDBTreeListOptionsData(void) { }
	
};


class DELPHICLASS TcxDBTreeListLoader;
class PASCALIMPLEMENTATION TcxDBTreeListLoader : public Cxtldata::TcxTreeListStructureLoader
{
	typedef Cxtldata::TcxTreeListStructureLoader inherited;
	
private:
	System::TObject* FDataSetBookmark;
	TcxDBTreeListDataController* __fastcall GetDataController(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	TcxCustomDBTreeList* __fastcall GetTreeList(void);
	Data::Db::TField* __fastcall GetKeyField(void);
	System::UnicodeString __fastcall GetKeyFieldName(void);
	Data::Db::TField* __fastcall GetParentKeyField(void);
	System::UnicodeString __fastcall GetParentKeyFieldName(void);
	
protected:
	System::Variant CursorKey;
	TcxDBTreeListNode* CursorNode;
	System::Classes::TList* HasChildren;
	int LoadingIndex;
	virtual void __fastcall AssignValues(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoLoad(Cxtl::TcxTreeListNode* ALoadingNode);
	bool __fastcall FindLoadedNode(const System::Variant &AParentValue, int &AIndex);
	bool __fastcall FindNode(TcxDBTreeListNode* &ANode, const System::Variant &AValue);
	virtual int __fastcall GetImageIndex(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListImageIndexType AIndexType);
	int __fastcall GetImageIndexAsInteger(Data::Db::TField* AField);
	virtual bool __fastcall IsChildrenExist(Cxtl::TcxTreeListNode* ANode);
	virtual bool __fastcall IsExistKeyRoot(System::Variant &AParentValue);
	void __fastcall LoadLevel(TcxDBTreeListNode* ANode, const System::Variant &AParentValue, System::Classes::TList* ANewNodes);
	void __fastcall LoadLevelBack(System::Variant &AParentValue);
	TcxDBTreeListNode* __fastcall LoadValues(const System::Variant &AKeyValue, const System::Variant &AParentKeyValue);
	virtual void __fastcall RestorePos(void);
	virtual void __fastcall SavePos(void);
	
public:
	__fastcall virtual TcxDBTreeListLoader(Cxtldata::TcxDataTreeListDataController* AOwner);
	__fastcall virtual ~TcxDBTreeListLoader(void);
	virtual void __fastcall Load(Cxtl::TcxTreeListNode* ANode);
	__property TcxDBTreeListDataController* DataController = {read=GetDataController};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property Data::Db::TField* KeyField = {read=GetKeyField};
	__property System::UnicodeString KeyFieldName = {read=GetKeyFieldName};
	__property Data::Db::TField* ParentKeyField = {read=GetParentKeyField};
	__property System::UnicodeString ParentKeyFieldName = {read=GetParentKeyFieldName};
	__property TcxCustomDBTreeList* TreeList = {read=GetTreeList};
};


typedef void __fastcall (__closure *TcxDBTreeListGetUniqueKeyValueEvent)(TcxCustomDBTreeList* Sender, System::Variant &KeyValue);

typedef void __fastcall (__closure *TcxDBTreeListInitInsertingRecordEvent)(TcxCustomDBTreeList* Sender, TcxDBTreeListNode* AFocusedNode, bool &AHandled);

class PASCALIMPLEMENTATION TcxCustomDBTreeList : public Cxtldata::TcxCustomDataTreeList
{
	typedef Cxtldata::TcxCustomDataTreeList inherited;
	
private:
	bool FDataBusy;
	bool FDataLocate;
	bool FIsAppend;
	bool FIsRefresh;
	bool FIsRefreshValues;
	System::Variant FRootValue;
	bool FUpdateFocused;
	TcxDBTreeListNode* FUpdatingNode;
	TcxDBTreeListGetUniqueKeyValueEvent FOnGetUniqueKeyValue;
	TcxDBTreeListInitInsertingRecordEvent FOnInitInsertingRecord;
	HIDESBASE TcxDBTreeListDataController* __fastcall GetDataController(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	HIDESBASE TcxDBTreeListLoader* __fastcall GetLoader(void);
	HIDESBASE TcxDBTreeListOptionsData* __fastcall GetOptionsData(void);
	void __fastcall SetDataController(TcxDBTreeListDataController* AValue);
	HIDESBASE void __fastcall SetOptionsData(TcxDBTreeListOptionsData* AValue);
	void __fastcall SetRootValue(const System::Variant &AValue);
	
protected:
	virtual void __fastcall AssignData(Cxtl::TcxCustomTreeList* ASource);
	virtual void __fastcall CheckChanges(void);
	virtual void __fastcall CreateAllItems(void);
	virtual Cxtl::TcxTreeListNode* __fastcall CreateNode(void);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DataModeChanged(void);
	virtual void __fastcall DoClear(void);
	virtual void __fastcall DoDeleteNode(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DeleteNodes(System::Classes::TList* AList);
	virtual bool __fastcall DoInitInsertingNode(TcxDBTreeListNode* ANode);
	virtual void __fastcall DoMoveTo(Cxtl::TcxTreeListNode* AttachNode, Cxtl::TcxTreeListNodeAttachMode AttachMode, System::Classes::TList* ANodes, bool IsCopy);
	TcxDBTreeListNode* __fastcall FindLoadedNodeByKeyValue(const System::Variant &AValue);
	void __fastcall FindNodeById(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual Cxtl::TcxTreeListColumnClass __fastcall GetTreeListColumnClass(void);
	virtual bool __fastcall HasData(void);
	virtual void __fastcall InitializeFields(void);
	virtual bool __fastcall InsertNode(Cxtl::TcxTreeListNode* ARelative, bool IsAppend);
	virtual TcxDBTreeListNode* __fastcall InternalFindNode(const System::Variant &AKeyValue, Cxtl::TcxTreeListNode* AStartNode = (Cxtl::TcxTreeListNode*)(0x0), bool AExpandedOnly = false, bool AForward = true, bool ARefreshAll = true);
	void __fastcall InternalInsertNode(bool IsAppend);
	bool __fastcall IsAutoCalcKeyValue(void);
	virtual bool __fastcall IsDataSettingsValid(void);
	virtual bool __fastcall IsNodeInserting(Cxtl::TcxTreeListNode* ANode);
	virtual bool __fastcall IsTreeListLocked(void);
	void __fastcall RefreshTree(void);
	void __fastcall LoadListByID(const System::Variant &AKeyValue, System::Classes::TList* AList);
	void __fastcall LoadListByNode(TcxDBTreeListNode* ANode, System::Classes::TList* AList);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall RefreshFields(void);
	virtual bool __fastcall SupportCreateAllItems(void);
	virtual void __fastcall UpdateFocusedNode(Cxtl::TcxTreeListColumn* AColumn);
	__property bool DataBusy = {read=FDataBusy, write=FDataBusy, nodefault};
	__property TcxDBTreeListDataController* DataController = {read=GetDataController, write=SetDataController};
	__property bool DataLocate = {read=FDataLocate, write=FDataLocate, nodefault};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property bool IsRefresh = {read=FIsRefresh, write=FIsRefresh, nodefault};
	__property bool IsRefreshValues = {read=FIsRefreshValues, write=FIsRefreshValues, nodefault};
	__property TcxDBTreeListLoader* Loader = {read=GetLoader};
	__property TcxDBTreeListOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	__property System::Variant RootValue = {read=FRootValue, write=SetRootValue};
	__property bool UpdateFocused = {read=FUpdateFocused, write=FUpdateFocused, nodefault};
	__property TcxDBTreeListNode* UpdatingNode = {read=FUpdatingNode, write=FUpdatingNode};
	__property TcxDBTreeListGetUniqueKeyValueEvent OnGetUniqueKeyValue = {read=FOnGetUniqueKeyValue, write=FOnGetUniqueKeyValue};
	__property TcxDBTreeListInitInsertingRecordEvent OnInitInsertingRecord = {read=FOnInitInsertingRecord, write=FOnInitInsertingRecord};
	
public:
	__fastcall virtual TcxCustomDBTreeList(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomDBTreeList(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TcxDBTreeListNode* __fastcall FindNodeByKeyValue(const System::Variant &AKeyValue, Cxtl::TcxTreeListNode* AStartNode = (Cxtl::TcxTreeListNode*)(0x0), bool AExpandedOnly = false, bool AForward = true);
	TcxDBTreeListColumn* __fastcall GetColumnByFieldName(const System::UnicodeString AFieldName);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDBTreeList(HWND ParentWindow) : Cxtldata::TcxCustomDataTreeList(ParentWindow) { }
	
};


class DELPHICLASS TcxDBTreeList;
class PASCALIMPLEMENTATION TcxDBTreeList : public TcxCustomDBTreeList
{
	typedef TcxCustomDBTreeList inherited;
	
public:
	__property Customizing;
	__property ColumnCount;
	__property Columns;
	__property FocusedColumn;
	__property FocusedNode;
	__property HitTest;
	__property IsEditing;
	__property SelectionCount;
	__property Selections;
	__property Sorted;
	__property SortedColumnCount;
	__property SortedColumns;
	__property TopVisibleNode;
	__property VisibleColumnCount;
	__property VisibleColumns;
	__property VisibleCount;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Bands;
	__property BorderStyle = {default=1};
	__property Constraints;
	__property Cursor = {default=0};
	__property DataController;
	__property DefaultLayout = {default=0};
	__property DefaultRowHeight = {default=0};
	__property DragCursor = {default=0};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property HelpType = {default=1};
	__property Hint;
	__property Images;
	__property LookAndFeel;
	__property Navigator;
	__property OptionsBehavior;
	__property OptionsCustomizing;
	__property OptionsData;
	__property OptionsSelection;
	__property OptionsView;
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property PopupMenus;
	__property Preview;
	__property RootValue = {default=0};
	__property StateImages;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property NavigatorEvents;
	__property OnAfterSummary;
	__property OnBandHeaderClick;
	__property OnBandPosChanged;
	__property OnBandSizeChanged;
	__property OnBeginDragNode;
	__property OnCanFocusNode;
	__property OnCanResize;
	__property OnCanSelectNode;
	__property OnChange;
	__property OnClick;
	__property OnCollapsed;
	__property OnCollapsing;
	__property OnColumnHeaderClick;
	__property OnColumnPosChanged;
	__property OnColumnSizeChanged;
	__property OnCompare;
	__property OnConstrainedResize;
	__property OnContextPopup;
	__property OnCustomDrawBackgroundCell;
	__property OnCustomDrawBandCell;
	__property OnCustomDrawBandHeaderCell;
	__property OnCustomDrawDataCell;
	__property OnCustomDrawFooterCell;
	__property OnCustomDrawHeaderCell;
	__property OnCustomDrawIndentCell;
	__property OnCustomDrawIndicatorCell;
	__property OnCustomDrawPreviewCell;
	__property OnCustomizationFormVisibleChanged;
	__property OnDataChanged;
	__property OnDblClick;
	__property OnDeletion;
	__property OnDockDrop;
	__property OnDockOver;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEdited;
	__property OnEditing;
	__property OnEditValueChanged;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnExpanded;
	__property OnExpanding;
	__property OnFocusedColumnChanged;
	__property OnFocusedNodeChanged;
	__property OnGetCellHint;
	__property OnGetDragDropText;
	__property OnGetLevelImages;
	__property OnGetNodeHeight;
	__property OnGetNodeImageIndex;
	__property OnGetNodePreviewHeight;
	__property OnGetSiteInfo;
	__property OnGetStoredProperties;
	__property OnGetStoredPropertyValue;
	__property OnGetUniqueKeyValue;
	__property OnHotTrackNode;
	__property OnInitEdit;
	__property OnInitEditValue;
	__property OnInitInsertingRecord;
	__property OnInitStoredObject;
	__property OnIsGroupNode;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnLayoutChanged;
	__property OnLeftPosChanged;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnMoveTo;
	__property OnNodeChanged;
	__property OnNodeCheckChanged;
	__property OnResize;
	__property OnSelectionChanged;
	__property OnSetStoredPropertyValue;
	__property OnSorted;
	__property OnSorting;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnSummary;
	__property OnTopRecordIndexChanged;
	__property OnUnDock;
	__property PopupMenusEvents;
	__property StylesEvents;
public:
	/* TcxCustomDBTreeList.Create */ inline __fastcall virtual TcxDBTreeList(System::Classes::TComponent* AOwner) : TcxCustomDBTreeList(AOwner) { }
	/* TcxCustomDBTreeList.Destroy */ inline __fastcall virtual ~TcxDBTreeList(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBTreeList(HWND ParentWindow) : TcxCustomDBTreeList(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbtl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBTL)
using namespace Cxdbtl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbtlHPP
