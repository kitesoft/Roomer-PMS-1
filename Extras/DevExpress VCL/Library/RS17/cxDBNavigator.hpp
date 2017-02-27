// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBNavigator.pas' rev: 24.00 (Win32)

#ifndef CxdbnavigatorHPP
#define CxdbnavigatorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxDBFilterControl.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbnavigator
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBNavigatorDataLink;
class DELPHICLASS TcxCustomDBNavigator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBNavigatorDataLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	TcxCustomDBNavigator* FNavigator;
	
protected:
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall ActiveChanged(void);
	
public:
	__fastcall TcxDBNavigatorDataLink(TcxCustomDBNavigator* ANavigator);
	__fastcall virtual ~TcxDBNavigatorDataLink(void);
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxDBNavigatorButtonsFilterEvent)(System::TObject* Sender, Cxdbfiltercontrol::TcxDBFilterControl* AFilterControl);

typedef Data::Db::TDataLink* __fastcall (__closure *TcxDBNavigatorButtonsGetDataLink)(void);

class DELPHICLASS TcxDBNavigatorButtons;
class PASCALIMPLEMENTATION TcxDBNavigatorButtons : public Cxnavigator::TcxCustomNavigatorButtons
{
	typedef Cxnavigator::TcxCustomNavigatorButtons inherited;
	
private:
	System::DynamicArray<System::Byte> FBookmark;
	// System::TArray__1<System::Byte>  FBookmark;
	System::Classes::TMemoryStream* FFilterCriteria;
	bool FFilterSetting;
	int FPageSize;
	TcxDBNavigatorButtonsFilterEvent FOnApplyFilter;
	TcxDBNavigatorButtonsGetDataLink FOnGetDataLink;
	TcxDBNavigatorButtonsFilterEvent FOnShowFilterDialog;
	void __fastcall DoApplyFilter(System::TObject* Sender);
	void __fastcall DoShowFilterDialog(System::TObject* Sender);
	Data::Db::TDataLink* __fastcall GetDataLink(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	int __fastcall GetInternalPageSize(void);
	void __fastcall SetBookmark(System::DynamicArray<System::Byte> Value);
	void __fastcall SetPageSize(int Value);
	void __fastcall ShowFilter(void);
	
protected:
	virtual void __fastcall DoButtonClick(int ADefaultIndex);
	virtual bool __fastcall GetButtonEnabled(int ADefaultIndex);
	void __fastcall CheckBookmark(void);
	void __fastcall ClearFilterCriteria(void);
	__property System::DynamicArray<System::Byte> Bookmark = {read=FBookmark, write=SetBookmark};
	// __property System::TArray__1<System::Byte>  Bookmark = ...;
	__property Data::Db::TDataLink* DataLink = {read=GetDataLink};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property int InternalPageSize = {read=GetInternalPageSize, nodefault};
	__property TcxDBNavigatorButtonsGetDataLink OnGetDataLink = {read=FOnGetDataLink, write=FOnGetDataLink};
	
public:
	__fastcall virtual TcxDBNavigatorButtons(Cxnavigator::_di_IcxNavigatorOwner ANavigator);
	__fastcall virtual ~TcxDBNavigatorButtons(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ReleaseBookmark(void);
	
__published:
	__property ConfirmDelete = {default=1};
	__property CustomButtons;
	__property Images;
	__property int PageSize = {read=FPageSize, write=SetPageSize, default=0};
	__property TcxDBNavigatorButtonsFilterEvent OnShowFilterDialog = {read=FOnShowFilterDialog, write=FOnShowFilterDialog};
	__property TcxDBNavigatorButtonsFilterEvent OnApplyFilter = {read=FOnApplyFilter, write=FOnApplyFilter};
	__property First;
	__property PriorPage;
	__property Prior;
	__property Next;
	__property NextPage;
	__property Last;
	__property Insert;
	__property Append;
	__property Delete;
	__property Edit;
	__property Post;
	__property Cancel;
	__property Refresh;
	__property SaveBookmark;
	__property GotoBookmark;
	__property Filter;
};


typedef void __fastcall (__closure *TcxDBNavigatorFilterEvent)(TcxCustomDBNavigator* ANavigator, Cxdbfiltercontrol::TcxDBFilterControl* AFilterControl);

class PASCALIMPLEMENTATION TcxCustomDBNavigator : public Cxnavigator::TcxCustomNavigator
{
	typedef Cxnavigator::TcxCustomNavigator inherited;
	
private:
	TcxDBNavigatorDataLink* FDataLink;
	TcxDBNavigatorFilterEvent FOnApplyFilter;
	TcxDBNavigatorFilterEvent FOnShowFilterDialog;
	void __fastcall DoApplyFilter(System::TObject* Sender, Cxdbfiltercontrol::TcxDBFilterControl* AFilterControl);
	void __fastcall DoShowFilterDialog(System::TObject* Sender, Cxdbfiltercontrol::TcxDBFilterControl* AFilterControl);
	TcxDBNavigatorButtons* __fastcall GetButtons(void);
	Data::Db::TDataLink* __fastcall GetDataLink(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	Cxnavigator::_di_IcxNavigatorRecordPosition __fastcall GetIRecordPosition(void);
	Cxnavigator::TcxNavigatorControlInfoPanel* __fastcall GetInfoPanel(void);
	void __fastcall SetButtons(TcxDBNavigatorButtons* Value);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetOnApplyFilter(TcxDBNavigatorFilterEvent Value);
	void __fastcall SetOnShowFilterDialog(TcxDBNavigatorFilterEvent Value);
	void __fastcall SetInfoPanel(Cxnavigator::TcxNavigatorControlInfoPanel* Value);
	
protected:
	int __fastcall GetRecordCount(void);
	int __fastcall GetRecordIndex(void);
	virtual Cxnavigator::TcxCustomNavigatorButtons* __fastcall CreateButtons(void);
	virtual Cxnavigator::TcxCustomNavigatorInfoPanel* __fastcall CreateInfoPanel(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall DataSetActiveChanged(void);
	virtual void __fastcall DataSetDataChanged(void);
	__property TcxDBNavigatorButtons* Buttons = {read=GetButtons, write=SetButtons};
	__property TcxDBNavigatorDataLink* DataLink = {read=FDataLink};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property Cxnavigator::TcxNavigatorControlInfoPanel* InfoPanel = {read=GetInfoPanel, write=SetInfoPanel};
	__property TcxDBNavigatorFilterEvent OnApplyFilter = {read=FOnApplyFilter, write=SetOnApplyFilter};
	__property TcxDBNavigatorFilterEvent OnShowFilterDialog = {read=FOnShowFilterDialog, write=SetOnShowFilterDialog};
	
public:
	__fastcall virtual TcxCustomDBNavigator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomDBNavigator(void);
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDBNavigator(HWND ParentWindow) : Cxnavigator::TcxCustomNavigator(ParentWindow) { }
	
private:
	void *__IcxNavigatorRecordPosition;	/* Cxnavigator::IcxNavigatorRecordPosition */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {715C9E38-5BA0-4ED8-B35C-BB40EA739362}
	operator Cxnavigator::_di_IcxNavigatorRecordPosition()
	{
		Cxnavigator::_di_IcxNavigatorRecordPosition intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigatorRecordPosition*(void) { return (Cxnavigator::IcxNavigatorRecordPosition*)&__IcxNavigatorRecordPosition; }
	#endif
	
};


class DELPHICLASS TcxDBNavigator;
class PASCALIMPLEMENTATION TcxDBNavigator : public TcxCustomDBNavigator
{
	typedef TcxCustomDBNavigator inherited;
	
__published:
	__property BorderStyle = {default=0};
	__property Buttons;
	__property DataSource;
	__property InfoPanel;
	__property LookAndFeel;
	__property OnApplyFilter;
	__property OnShowFilterDialog;
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Ctl3D;
	__property ParentCtl3D = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomDBNavigator.Create */ inline __fastcall virtual TcxDBNavigator(System::Classes::TComponent* AOwner) : TcxCustomDBNavigator(AOwner) { }
	/* TcxCustomDBNavigator.Destroy */ inline __fastcall virtual ~TcxDBNavigator(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBNavigator(HWND ParentWindow) : TcxCustomDBNavigator(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbnavigator */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBNAVIGATOR)
using namespace Cxdbnavigator;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbnavigatorHPP
