// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBPivotGrid.pas' rev: 24.00 (Win32)

#ifndef CxdbpivotgridHPP
#define CxdbpivotgridHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.FmtBcd.hpp>	// Pascal unit
#include <Data.SqlTimSt.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbpivotgrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBPivotGridFieldDataBinding;
class DELPHICLASS TcxDBPivotGridDataController;
class DELPHICLASS TcxDBPivotGridField;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBPivotGridFieldDataBinding : public Cxcustompivotgrid::TcxPivotGridFieldDataBinding
{
	typedef Cxcustompivotgrid::TcxPivotGridFieldDataBinding inherited;
	
private:
	TcxDBPivotGridDataController* __fastcall GetDataController(void);
	Data::Db::TField* __fastcall GetDBField(void);
	TcxDBPivotGridField* __fastcall GetField(void);
	System::UnicodeString __fastcall GetFieldCaption(void);
	System::UnicodeString __fastcall GetFieldName(void);
	void __fastcall SetFieldName(System::UnicodeString AValue);
	
protected:
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	virtual System::UnicodeString __fastcall GetFilterFieldName(void);
	virtual void __fastcall Init(void);
	__property TcxDBPivotGridDataController* DataController = {read=GetDataController};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Data::Db::TField* DBField = {read=GetDBField};
	__property TcxDBPivotGridField* Field = {read=GetField};
	__property System::UnicodeString FieldCaption = {read=GetFieldCaption};
	
__published:
	__property ValueType = {default=0};
	__property System::UnicodeString FieldName = {read=GetFieldName, write=SetFieldName};
public:
	/* TcxPivotGridFieldDataBinding.Create */ inline __fastcall virtual TcxDBPivotGridFieldDataBinding(Cxcustompivotgrid::TcxPivotGridField* AOwner) : Cxcustompivotgrid::TcxPivotGridFieldDataBinding(AOwner) { }
	/* TcxPivotGridFieldDataBinding.Destroy */ inline __fastcall virtual ~TcxDBPivotGridFieldDataBinding(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomDBPivotGrid;
class PASCALIMPLEMENTATION TcxDBPivotGridField : public Cxcustompivotgrid::TcxPivotGridField
{
	typedef Cxcustompivotgrid::TcxPivotGridField inherited;
	
private:
	TcxDBPivotGridFieldDataBinding* __fastcall GetDataBinding(void);
	TcxCustomDBPivotGrid* __fastcall GetPivotGrid(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBPivotGridFieldDataBinding* AValue);
	HIDESBASE void __fastcall SetPivotGrid(TcxCustomDBPivotGrid* AValue);
	
protected:
	virtual Cxcustompivotgrid::TcxPivotGridFieldDataBinding* __fastcall CreateDataBinding(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual System::UnicodeString __fastcall GetActualDisplayFormat(void);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual bool __fastcall IsCurrency(Cxdatastorage::TcxValueTypeClass AType);
	
public:
	__property TcxCustomDBPivotGrid* PivotGrid = {read=GetPivotGrid, write=SetPivotGrid};
	
__published:
	__property Area = {default=2};
	__property AreaIndex = {default=-1};
	__property Caption = {default=0};
	__property TcxDBPivotGridFieldDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property SortOrder = {default=0};
	__property Visible = {default=0};
public:
	/* TcxPivotGridField.Create */ inline __fastcall virtual TcxDBPivotGridField(System::Classes::TComponent* AOwner) : Cxcustompivotgrid::TcxPivotGridField(AOwner) { }
	/* TcxPivotGridField.Destroy */ inline __fastcall virtual ~TcxDBPivotGridField(void) { }
	
};


class PASCALIMPLEMENTATION TcxDBPivotGridDataController : public Cxdbdata::TcxDBDataController
{
	typedef Cxdbdata::TcxDBDataController inherited;
	
private:
	TcxCustomDBPivotGrid* __fastcall GetPivotGrid(void);
	
protected:
	virtual void __fastcall DoValueTypeClassChanged(int AItemIndex);
	virtual void __fastcall FilterChanged(void);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	__property TcxCustomDBPivotGrid* PivotGrid = {read=GetPivotGrid};
	
public:
	virtual System::UnicodeString __fastcall GetFilterItemFieldCaption(System::TObject* AItem);
	virtual System::TObject* __fastcall GetItem(int Index);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall UpdateItemIndexes(void);
public:
	/* TcxDBDataController.Create */ inline __fastcall virtual TcxDBPivotGridDataController(System::Classes::TComponent* AOwner) : Cxdbdata::TcxDBDataController(AOwner) { }
	/* TcxDBDataController.Destroy */ inline __fastcall virtual ~TcxDBPivotGridDataController(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomDBPivotGrid : public Cxcustompivotgrid::TcxCustomPivotGrid
{
	typedef Cxcustompivotgrid::TcxCustomPivotGrid inherited;
	
private:
	TcxDBPivotGridDataController* __fastcall GetDataController(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	void __fastcall SetDataSource(Data::Db::TDataSource* AValue);
	
protected:
	virtual bool __fastcall CanRetrieveFields(bool &AIsActive);
	virtual Cxcustomdata::TcxCustomDataController* __fastcall CreateDataController(void);
	virtual void __fastcall DoCreateAllFields(void);
	virtual Cxcustompivotgrid::TcxPivotGridFieldClass __fastcall GetFieldClass(void);
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property TcxDBPivotGridDataController* DataController = {read=GetDataController};
	
public:
	void __fastcall CreateAllFields(void);
public:
	/* TcxCustomPivotGrid.Create */ inline __fastcall virtual TcxCustomDBPivotGrid(System::Classes::TComponent* AOwner) : Cxcustompivotgrid::TcxCustomPivotGrid(AOwner) { }
	/* TcxCustomPivotGrid.Destroy */ inline __fastcall virtual ~TcxCustomDBPivotGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDBPivotGrid(HWND ParentWindow) : Cxcustompivotgrid::TcxCustomPivotGrid(ParentWindow) { }
	
};


class DELPHICLASS TcxDBPivotGrid;
class PASCALIMPLEMENTATION TcxDBPivotGrid : public TcxCustomDBPivotGrid
{
	typedef TcxCustomDBPivotGrid inherited;
	
public:
	__property DataController;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BorderWidth = {default=0};
	__property BorderStyle = {default=1};
	__property Constraints;
	__property DataSource;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property FieldHeaderImages;
	__property Font;
	__property GroupHeaderImages;
	__property Groups;
	__property LookAndFeel;
	__property OptionsBehavior;
	__property OptionsCustomize;
	__property OptionsData;
	__property OptionsDataField;
	__property OptionsPrefilter;
	__property OptionsSelection;
	__property OptionsView;
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property PopupMenus;
	__property ShowHint;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnCompare;
	__property OnCustomDrawFieldHeader;
	__property OnCustomDrawColumnHeader;
	__property OnCustomDrawRowHeader;
	__property OnCustomDrawCell;
	__property OnCustomDrawPart;
	__property OnCustomization;
	__property OnFieldPosChanged;
	__property OnFieldSizeChanged;
	__property OnFilterChanged;
	__property OnPrefilterDialogShow;
	__property OnLayoutChanged;
	__property OnSelectionChanged;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
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
public:
	/* TcxCustomPivotGrid.Create */ inline __fastcall virtual TcxDBPivotGrid(System::Classes::TComponent* AOwner) : TcxCustomDBPivotGrid(AOwner) { }
	/* TcxCustomPivotGrid.Destroy */ inline __fastcall virtual ~TcxDBPivotGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBPivotGrid(HWND ParentWindow) : TcxCustomDBPivotGrid(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbpivotgrid */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBPIVOTGRID)
using namespace Cxdbpivotgrid;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbpivotgridHPP
