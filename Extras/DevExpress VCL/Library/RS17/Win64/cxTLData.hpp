// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTLData.pas' rev: 24.00 (Win64)

#ifndef CxtldataHPP
#define CxtldataHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxTL.hpp>	// Pascal unit
#include <cxTLStrs.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtldata
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxTreeListCustomDataSource;
class PASCALIMPLEMENTATION TcxTreeListCustomDataSource : public Cxcustomdata::TcxCustomDataSource
{
	typedef Cxcustomdata::TcxCustomDataSource inherited;
	
protected:
	virtual int __fastcall GetChildCount(void * AParentHandle);
	virtual void * __fastcall GetChildRecordHandle(void * AParentHandle, int AChildIndex);
	virtual void * __fastcall GetRootRecordHandle(void);
	virtual void * __fastcall GetParentRecordHandle(void * ARecordHandle);
	virtual int __fastcall GetRecordCount(void);
	virtual void * __fastcall GetRecordHandle(int ARecordIndex);
	void __fastcall DeleteChildItems(void * AParentHandle);
	virtual void __fastcall NodeMoveTo(void * ARecordHandle, void * AttachRecordHandle, Cxtl::TcxTreeListNodeAttachMode AttachMode, bool IsCopy);
	
public:
	virtual void __fastcall DataChanged(void);
public:
	/* TcxCustomDataSource.Destroy */ inline __fastcall virtual ~TcxTreeListCustomDataSource(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxTreeListCustomDataSource(void) : Cxcustomdata::TcxCustomDataSource() { }
	
};


class DELPHICLASS TcxDataTreeListDataController;
class DELPHICLASS TcxTreeListStructureLoader;
class DELPHICLASS TcxCustomDataTreeList;
class DELPHICLASS TcxVirtualTreeListNode;
class PASCALIMPLEMENTATION TcxDataTreeListDataController : public Cxtl::TcxTreeListDataController
{
	typedef Cxtl::TcxTreeListDataController inherited;
	
private:
	TcxTreeListCustomDataSource* FDataSource;
	bool FIsDataLoaded;
	TcxTreeListStructureLoader* FLoader;
	bool FLoadingInProcess;
	int FLoadingRefCount;
	HIDESBASE TcxCustomDataTreeList* __fastcall GetTreeList(void);
	HIDESBASE void __fastcall SetCustomDataSource(TcxTreeListCustomDataSource* AValue);
	
protected:
	virtual void __fastcall AfterLoad(void);
	virtual void __fastcall CheckData(void);
	virtual TcxTreeListStructureLoader* __fastcall CreateLoader(void) = 0 ;
	virtual void __fastcall DoInitInsertingNode(Cxtl::TcxTreeListNode* ANode);
	HIDESBASE virtual TcxTreeListCustomDataSource* __fastcall GetCustomDataSource(void);
	virtual bool __fastcall IsLoading(void);
	virtual void __fastcall Load(Cxtl::TcxTreeListNode* ANode);
	void __fastcall NodesMoveTo(TcxVirtualTreeListNode* AttachNode, Cxtl::TcxTreeListNodeAttachMode AttachMode, System::Classes::TList* ANodes, bool IsCopy);
	__property bool IsDataLoaded = {read=FIsDataLoaded, write=FIsDataLoaded, nodefault};
	__property TcxTreeListStructureLoader* Loader = {read=FLoader};
	__property bool LoadingInProcess = {read=FLoadingInProcess, write=FLoadingInProcess, nodefault};
	__property int LoadingRefCount = {read=FLoadingRefCount, nodefault};
	
public:
	__fastcall virtual TcxDataTreeListDataController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxDataTreeListDataController(void);
	virtual System::Variant __fastcall GetNodeDisplayText(Cxtl::TcxTreeListNode* ANode, int AIndex);
	__property TcxTreeListCustomDataSource* CustomDataSource = {read=GetCustomDataSource, write=SetCustomDataSource};
	__property TcxCustomDataTreeList* TreeList = {read=GetTreeList};
};


class DELPHICLASS TcxVirtualTreeListDataController;
class DELPHICLASS TcxCustomVirtualTreeList;
class PASCALIMPLEMENTATION TcxVirtualTreeListDataController : public TcxDataTreeListDataController
{
	typedef TcxDataTreeListDataController inherited;
	
private:
	HIDESBASE TcxCustomVirtualTreeList* __fastcall GetTreeList(void);
	
protected:
	void __fastcall CheckLoaded(Cxtl::TcxTreeListNode* ANode);
	virtual TcxTreeListStructureLoader* __fastcall CreateLoader(void);
	virtual void __fastcall DeleteNode(Cxtl::TcxTreeListNode* ANode);
	
public:
	virtual int __fastcall CompareNodesByColumns(Cxtl::TcxTreeListNode* ANode1, Cxtl::TcxTreeListNode* ANode2, System::Classes::TList* AColumns);
	virtual System::Variant __fastcall GetNodeDisplayText(Cxtl::TcxTreeListNode* ANode, int AIndex);
	virtual System::Variant __fastcall GetNodeValue(Cxtl::TcxTreeListNode* ANode, int AIndex);
	virtual void __fastcall SetNodeValue(Cxtl::TcxTreeListNode* ANode, int AIndex, const System::Variant &AValue);
	__property TcxCustomVirtualTreeList* TreeList = {read=GetTreeList};
public:
	/* TcxDataTreeListDataController.Create */ inline __fastcall virtual TcxVirtualTreeListDataController(System::Classes::TComponent* AOwner) : TcxDataTreeListDataController(AOwner) { }
	/* TcxDataTreeListDataController.Destroy */ inline __fastcall virtual ~TcxVirtualTreeListDataController(void) { }
	
};


class PASCALIMPLEMENTATION TcxVirtualTreeListNode : public Cxtl::TcxTreeListNode
{
	typedef Cxtl::TcxTreeListNode inherited;
	
private:
	void *FRecordHandle;
	
public:
	__property void * RecordHandle = {read=FRecordHandle};
public:
	/* TcxTreeListNode.Create */ inline __fastcall virtual TcxVirtualTreeListNode(Cxtl::TcxCustomTreeList* AOwner) : Cxtl::TcxTreeListNode(AOwner) { }
	/* TcxTreeListNode.Destroy */ inline __fastcall virtual ~TcxVirtualTreeListNode(void) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListStructureLoader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxDataTreeListDataController* FDataController;
	TcxCustomDataTreeList* FTreeList;
	Cxtl::TcxTreeListNode* __fastcall GetRoot(void);
	
protected:
	System::Classes::TList* Nodes;
	System::Classes::TList* Loaded;
	virtual void __fastcall AssignValues(Cxtl::TcxTreeListNode* ANode);
	System::Classes::TList* __fastcall CloneList(System::Classes::TList* ASource);
	virtual void __fastcall DoLoad(Cxtl::TcxTreeListNode* ALoadingNode) = 0 ;
	virtual int __fastcall GetImageIndex(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListImageIndexType AIndexType);
	void __fastcall InternalDelete(System::Classes::TList* ANodes);
	void __fastcall InternalMove(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListNode* ADestNode, Cxtl::TcxTreeListNodeAttachMode AMode);
	virtual bool __fastcall IsChildrenExist(Cxtl::TcxTreeListNode* ANode) = 0 ;
	virtual bool __fastcall IsLoadAllRecords(void);
	virtual void __fastcall RestorePos(void);
	virtual void __fastcall SavePos(void);
	
public:
	__fastcall virtual TcxTreeListStructureLoader(TcxDataTreeListDataController* AOwner);
	virtual void __fastcall Load(Cxtl::TcxTreeListNode* ANode);
	__property TcxDataTreeListDataController* DataController = {read=FDataController};
	__property Cxtl::TcxTreeListNode* Root = {read=GetRoot};
	__property TcxCustomDataTreeList* TreeList = {read=FTreeList};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListStructureLoader(void) { }
	
};


class DELPHICLASS TcxVirtualTreeListLoader;
class PASCALIMPLEMENTATION TcxVirtualTreeListLoader : public TcxTreeListStructureLoader
{
	typedef TcxTreeListStructureLoader inherited;
	
private:
	TcxDataTreeListDataController* __fastcall GetDataController(void);
	TcxTreeListCustomDataSource* __fastcall GetDataSource(void);
	TcxCustomVirtualTreeList* __fastcall GetTreeList(void);
	
protected:
	TcxVirtualTreeListNode* __fastcall AddChild(Cxtl::TcxTreeListNode* AParent, void * ARecordHandle);
	virtual void __fastcall AssignValues(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoLoad(Cxtl::TcxTreeListNode* ALoadingNode);
	bool __fastcall ExtractNode(void * ARecordHandle, TcxVirtualTreeListNode* &ANode);
	bool __fastcall FindParentNode(const void * AParentHandle, TcxVirtualTreeListNode* APrev, TcxVirtualTreeListNode* &ANode);
	virtual bool __fastcall IsChildrenExist(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall LoadAllRecords(void);
	virtual void __fastcall LoadLevel(Cxtl::TcxTreeListNode* AParent, void * AParentHandle);
	void __fastcall LoadValues(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall LoadVirtualLevel(Cxtl::TcxTreeListNode* ANode, bool ARecursive);
	void __fastcall RestoreNodeState(Cxtl::TcxTreeListNode* ANode, void * AData);
	void __fastcall SaveNodeState(Cxtl::TcxTreeListNode* ANode, void * AData);
	
public:
	__property TcxDataTreeListDataController* DataController = {read=GetDataController};
	__property TcxTreeListCustomDataSource* DataSource = {read=GetDataSource};
	__property TcxCustomVirtualTreeList* TreeList = {read=GetTreeList};
public:
	/* TcxTreeListStructureLoader.Create */ inline __fastcall virtual TcxVirtualTreeListLoader(TcxDataTreeListDataController* AOwner) : TcxTreeListStructureLoader(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVirtualTreeListLoader(void) { }
	
};


class DELPHICLASS TcxVirtualTreeListOptionsData;
class PASCALIMPLEMENTATION TcxVirtualTreeListOptionsData : public Cxtl::TcxTreeListOptionsData
{
	typedef Cxtl::TcxTreeListOptionsData inherited;
	
private:
	bool FCheckHasChildren;
	bool FSmartLoad;
	void __fastcall SetSmartLoad(bool AValue);
	
public:
	__fastcall virtual TcxVirtualTreeListOptionsData(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CheckHasChildren = {read=FCheckHasChildren, write=FCheckHasChildren, default=1};
	__property bool SmartLoad = {read=FSmartLoad, write=SetSmartLoad, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxVirtualTreeListOptionsData(void) { }
	
};


enum TcxDataTreeListChange : unsigned char { dtcStructure, dtcData, dtcLayout, dtcFocused };

typedef System::Set<TcxDataTreeListChange, TcxDataTreeListChange::dtcStructure, TcxDataTreeListChange::dtcFocused>  TcxDataTreeListChanges;

class PASCALIMPLEMENTATION TcxCustomDataTreeList : public Cxtl::TcxCustomTreeList
{
	typedef Cxtl::TcxCustomTreeList inherited;
	
private:
	TcxDataTreeListChanges FDataChanges;
	int FInternalCreationRefCount;
	int FLoadingLockCount;
	int FLockDataChanges;
	HIDESBASE TcxDataTreeListDataController* __fastcall GetDataController(void);
	TcxTreeListStructureLoader* __fastcall GetLoader(void);
	HIDESBASE TcxVirtualTreeListOptionsData* __fastcall GetOptionsData(void);
	HIDESBASE void __fastcall SetOptionsData(TcxVirtualTreeListOptionsData* Value);
	
protected:
	void __fastcall AddDataChanges(TcxDataTreeListChanges AChanges);
	virtual Cxtl::TcxTreeListNode* __fastcall AddNode(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListNode* ARelative, void * AData, Cxtl::TcxTreeListNodeAttachMode AttachMode);
	virtual void __fastcall CheckChanges(void);
	virtual void __fastcall CheckDataChanges(void);
	virtual Cxtl::TcxTreeListNode* __fastcall CreateNode(void);
	virtual void __fastcall DataModeChanged(void);
	virtual void __fastcall DeleteNodes(System::Classes::TList* AList);
	virtual void __fastcall DoClear(void);
	virtual void __fastcall DoExpand(Cxtl::TcxTreeListNode* ANode);
	virtual Cxinplacecontainer::TcxControlOptionsDataClass __fastcall GetOptionsDataClass(void);
	void __fastcall InternalCreationAddRef(void);
	void __fastcall InternalCreationRelease(void);
	virtual bool __fastcall IsDataSettingsValid(void);
	void __fastcall LockLoading(void);
	void __fastcall UnlockLoading(void);
	__property TcxDataTreeListDataController* DataController = {read=GetDataController};
	__property TcxDataTreeListChanges DataChanges = {read=FDataChanges, write=FDataChanges, nodefault};
	__property int InternalCreationRefCount = {read=FInternalCreationRefCount, nodefault};
	__property TcxTreeListStructureLoader* Loader = {read=GetLoader};
	__property int LoadingLockCount = {read=FLoadingLockCount, nodefault};
	__property int LockDataChanges = {read=FLockDataChanges, nodefault};
	__property TcxVirtualTreeListOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	
public:
	virtual void __fastcall FullRefresh(void);
public:
	/* TcxCustomTreeList.Create */ inline __fastcall virtual TcxCustomDataTreeList(System::Classes::TComponent* AOwner) : Cxtl::TcxCustomTreeList(AOwner) { }
	/* TcxCustomTreeList.Destroy */ inline __fastcall virtual ~TcxCustomDataTreeList(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDataTreeList(HWND ParentWindow) : Cxtl::TcxCustomTreeList(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TcxVirtualTreeListGetChildCountEvent)(Cxtl::TcxCustomTreeList* Sender, Cxtl::TcxTreeListNode* AParentNode, int &ACount);

typedef void __fastcall (__closure *TcxVirtualTreeListNodeValueEvent)(Cxtl::TcxCustomTreeList* Sender, Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn, System::Variant &AValue);

class PASCALIMPLEMENTATION TcxCustomVirtualTreeList : public TcxCustomDataTreeList
{
	typedef TcxCustomDataTreeList inherited;
	
private:
	Cxtl::TcxTreeListNode* FUpdatingNode;
	TcxVirtualTreeListGetChildCountEvent FOnGetChildCount;
	TcxVirtualTreeListNodeValueEvent FOnGetNodeValue;
	TcxVirtualTreeListNodeValueEvent FOnSetNodeValue;
	HIDESBASE TcxDataTreeListDataController* __fastcall GetDataController(void);
	TcxTreeListCustomDataSource* __fastcall GetDataSource(void);
	void __fastcall SetOnGetChildCount(TcxVirtualTreeListGetChildCountEvent AValue);
	void __fastcall SetOnGetNodeValue(TcxVirtualTreeListNodeValueEvent AValue);
	void __fastcall SetOnSetNodeValue(TcxVirtualTreeListNodeValueEvent AValue);
	void __fastcall SetDataSource(TcxTreeListCustomDataSource* Value);
	
protected:
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DoDeleteNode(Cxtl::TcxTreeListNode* ANode);
	virtual int __fastcall DoGetChildCount(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoLoadValues(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoMoveTo(Cxtl::TcxTreeListNode* AttachNode, Cxtl::TcxTreeListNodeAttachMode AttachMode, System::Classes::TList* ANodes, bool IsCopy);
	virtual void __fastcall DoSetValue(Cxtl::TcxTreeListNode* ANode, int AIndex, System::Variant &AValue);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual void __fastcall InitInsertingNode(Cxtl::TcxTreeListNode* ANode);
	virtual bool __fastcall InsertNode(Cxtl::TcxTreeListNode* ARelative, bool IsAppend);
	virtual bool __fastcall IsCompletelyVirtual(void);
	virtual void __fastcall Loaded(void);
	__property TcxDataTreeListDataController* DataController = {read=GetDataController};
	__property Cxtl::TcxTreeListNode* UpdatingNode = {read=FUpdatingNode, write=FUpdatingNode};
	__property TcxVirtualTreeListGetChildCountEvent OnGetChildCount = {read=FOnGetChildCount, write=SetOnGetChildCount};
	__property TcxVirtualTreeListNodeValueEvent OnGetNodeValue = {read=FOnGetNodeValue, write=SetOnGetNodeValue};
	__property TcxVirtualTreeListNodeValueEvent OnSetNodeValue = {read=FOnSetNodeValue, write=SetOnSetNodeValue};
	
public:
	__fastcall virtual ~TcxCustomVirtualTreeList(void);
	virtual void * __fastcall HandleFromNode(Cxtl::TcxTreeListNode* ANode);
	virtual Cxtl::TcxTreeListNode* __fastcall NodeFromHandle(void * ARecordHandle);
	__property TcxTreeListCustomDataSource* CustomDataSource = {read=GetDataSource, write=SetDataSource};
public:
	/* TcxCustomTreeList.Create */ inline __fastcall virtual TcxCustomVirtualTreeList(System::Classes::TComponent* AOwner) : TcxCustomDataTreeList(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomVirtualTreeList(HWND ParentWindow) : TcxCustomDataTreeList(ParentWindow) { }
	
};


class DELPHICLASS TcxVirtualTreeList;
class PASCALIMPLEMENTATION TcxVirtualTreeList : public TcxCustomVirtualTreeList
{
	typedef TcxCustomVirtualTreeList inherited;
	
public:
	__property ColumnCount;
	__property Columns;
	__property Customizing;
	__property DataController;
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
	__property OnGetChildCount;
	__property OnGetDragDropText;
	__property OnGetLevelImages;
	__property OnGetNodeHeight;
	__property OnGetNodeImageIndex;
	__property OnGetNodePreviewHeight;
	__property OnGetNodeValue;
	__property OnGetSiteInfo;
	__property OnGetStoredProperties;
	__property OnGetStoredPropertyValue;
	__property OnHotTrackNode;
	__property OnInitEdit;
	__property OnInitEditValue;
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
	__property OnSetNodeValue;
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
	/* TcxCustomVirtualTreeList.Destroy */ inline __fastcall virtual ~TcxVirtualTreeList(void) { }
	
public:
	/* TcxCustomTreeList.Create */ inline __fastcall virtual TcxVirtualTreeList(System::Classes::TComponent* AOwner) : TcxCustomVirtualTreeList(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxVirtualTreeList(HWND ParentWindow) : TcxCustomVirtualTreeList(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void *cxNullRecordHandle;
}	/* namespace Cxtldata */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTLDATA)
using namespace Cxtldata;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtldataHPP
