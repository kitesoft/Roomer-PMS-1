// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLookupDBGrid.pas' rev: 24.00 (Win64)

#ifndef CxlookupdbgridHPP
#define CxlookupdbgridHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxEditRepositoryItems.hpp>	// Pascal unit
#include <cxLookupGrid.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlookupdbgrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxLookupGridDBDataController;
class DELPHICLASS TcxCustomLookupDBGrid;
class PASCALIMPLEMENTATION TcxLookupGridDBDataController : public Cxdbdata::TcxDBDataController
{
	typedef Cxdbdata::TcxDBDataController inherited;
	
private:
	TcxCustomLookupDBGrid* __fastcall GetGrid(void);
	
protected:
	virtual void __fastcall UpdateScrollBars(void);
	
public:
	__fastcall virtual TcxLookupGridDBDataController(System::Classes::TComponent* AOwner);
	virtual System::TObject* __fastcall GetItem(int Index);
	__property TcxCustomLookupDBGrid* Grid = {read=GetGrid};
	
__published:
	__property OnCompare;
public:
	/* TcxDBDataController.Destroy */ inline __fastcall virtual ~TcxLookupGridDBDataController(void) { }
	
};


class DELPHICLASS TcxLookupDBGridDefaultValuesProvider;
class PASCALIMPLEMENTATION TcxLookupDBGridDefaultValuesProvider : public Cxdbedit::TcxCustomDBEditDefaultValuesProvider
{
	typedef Cxdbedit::TcxCustomDBEditDefaultValuesProvider inherited;
	
__published:
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
public:
	/* TcxCustomDBEditDefaultValuesProvider.Create */ inline __fastcall virtual TcxLookupDBGridDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Cxdbedit::TcxCustomDBEditDefaultValuesProvider(AOwner) { }
	/* TcxCustomDBEditDefaultValuesProvider.Destroy */ inline __fastcall virtual ~TcxLookupDBGridDefaultValuesProvider(void) { }
	
};


class DELPHICLASS TcxLookupDBGridColumn;
class PASCALIMPLEMENTATION TcxLookupDBGridColumn : public Cxlookupgrid::TcxLookupGridColumn
{
	typedef Cxlookupgrid::TcxLookupGridColumn inherited;
	
private:
	HIDESBASE TcxLookupGridDBDataController* __fastcall GetDataController(void);
	Data::Db::TField* __fastcall GetField(void);
	System::UnicodeString __fastcall GetFieldName(void);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	
protected:
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	void __fastcall InitDefaultValuesProvider(void);
	__property TcxLookupGridDBDataController* DataController = {read=GetDataController};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual int __fastcall DefaultWidth(void);
	__property Data::Db::TField* Field = {read=GetField};
	
__published:
	__property System::UnicodeString FieldName = {read=GetFieldName, write=SetFieldName};
public:
	/* TcxLookupGridColumn.Create */ inline __fastcall virtual TcxLookupDBGridColumn(System::Classes::TCollection* Collection) : Cxlookupgrid::TcxLookupGridColumn(Collection) { }
	/* TcxLookupGridColumn.Destroy */ inline __fastcall virtual ~TcxLookupDBGridColumn(void) { }
	
};


class DELPHICLASS TcxLookupDBGridColumns;
class PASCALIMPLEMENTATION TcxLookupDBGridColumns : public Cxlookupgrid::TcxLookupGridColumns
{
	typedef Cxlookupgrid::TcxLookupGridColumns inherited;
	
public:
	TcxLookupDBGridColumn* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxLookupDBGridColumn* __fastcall GetColumn(int Index);
	HIDESBASE void __fastcall SetColumn(int Index, TcxLookupDBGridColumn* Value);
	
public:
	HIDESBASE TcxLookupDBGridColumn* __fastcall Add(void);
	TcxLookupDBGridColumn* __fastcall ColumnByFieldName(const System::UnicodeString AFieldName);
	__property TcxLookupDBGridColumn* Items[int Index] = {read=GetColumn, write=SetColumn/*, default*/};
public:
	/* TcxLookupGridColumns.Create */ inline __fastcall virtual TcxLookupDBGridColumns(Cxlookupgrid::TcxCustomLookupGrid* AGrid, Cxlookupgrid::TcxLookupGridColumnClass AColumnClass) : Cxlookupgrid::TcxLookupGridColumns(AGrid, AColumnClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxLookupDBGridColumns(void) { }
	
};


class DELPHICLASS TcxLookupDBGridOptions;
class PASCALIMPLEMENTATION TcxLookupDBGridOptions : public Cxlookupgrid::TcxLookupGridOptions
{
	typedef Cxlookupgrid::TcxLookupGridOptions inherited;
	
private:
	TcxCustomLookupDBGrid* __fastcall GetGrid(void);
	bool __fastcall GetSyncMode(void);
	void __fastcall SetSyncMode(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomLookupDBGrid* Grid = {read=GetGrid};
	
__published:
	__property bool SyncMode = {read=GetSyncMode, write=SetSyncMode, default=0};
public:
	/* TcxLookupGridOptions.Create */ inline __fastcall virtual TcxLookupDBGridOptions(Cxlookupgrid::TcxCustomLookupGrid* AGrid) : Cxlookupgrid::TcxLookupGridOptions(AGrid) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxLookupDBGridOptions(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomLookupDBGrid : public Cxlookupgrid::TcxCustomLookupGrid
{
	typedef Cxlookupgrid::TcxCustomLookupGrid inherited;
	
private:
	TcxLookupDBGridColumns* __fastcall GetColumns(void);
	HIDESBASE TcxLookupGridDBDataController* __fastcall GetDataController(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	System::UnicodeString __fastcall GetKeyFieldNames(void);
	TcxLookupDBGridOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetColumns(TcxLookupDBGridColumns* Value);
	HIDESBASE void __fastcall SetDataController(TcxLookupGridDBDataController* Value);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetKeyFieldNames(const System::UnicodeString Value);
	HIDESBASE void __fastcall SetOptions(TcxLookupDBGridOptions* Value);
	
protected:
	virtual void __fastcall CreateColumnsByFields(System::Classes::TStrings* AFieldNames);
	virtual void __fastcall DataChanged(void);
	virtual Cxlookupgrid::TcxLookupGridColumnClass __fastcall GetColumnClass(void);
	virtual Cxlookupgrid::TcxLookupGridColumnsClass __fastcall GetColumnsClass(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxlookupgrid::TcxLookupGridOptionsClass __fastcall GetOptionsClass(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall UpdateScrollBars(void);
	
public:
	void __fastcall CreateAllColumns(void);
	void __fastcall CreateColumnsByFieldNames(const System::UnicodeString AFieldNames);
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Color = {default=-16777211};
	__property TcxLookupDBGridColumns* Columns = {read=GetColumns, write=SetColumns};
	__property TcxLookupGridDBDataController* DataController = {read=GetDataController, write=SetDataController};
	__property Font;
	__property LookAndFeel;
	__property TcxLookupDBGridOptions* Options = {read=GetOptions, write=SetOptions};
	__property ParentFont = {default=1};
	__property Visible = {default=1};
	
__published:
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property System::UnicodeString KeyFieldNames = {read=GetKeyFieldNames, write=SetKeyFieldNames};
public:
	/* TcxCustomLookupGrid.Create */ inline __fastcall virtual TcxCustomLookupDBGrid(System::Classes::TComponent* AOwner) : Cxlookupgrid::TcxCustomLookupGrid(AOwner) { }
	/* TcxCustomLookupGrid.Destroy */ inline __fastcall virtual ~TcxCustomLookupDBGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomLookupDBGrid(HWND ParentWindow) : Cxlookupgrid::TcxCustomLookupGrid(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxCustomLookupDBGridClass;

//-- var, const, procedure ---------------------------------------------------
static const bool DefaultSyncMode = false;
}	/* namespace Cxlookupdbgrid */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLOOKUPDBGRID)
using namespace Cxlookupdbgrid;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlookupdbgridHPP
