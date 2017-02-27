// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerTreeListBrowser.pas' rev: 24.00 (Win64)

#ifndef CxschedulertreelistbrowserHPP
#define CxschedulertreelistbrowserHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxSchedulerTimeGridView.hpp>	// Pascal unit
#include <cxTL.hpp>	// Pascal unit
#include <cxTLData.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulertreelistbrowser
{
//-- type declarations -------------------------------------------------------
enum TcxShedulerTreeBrowserStyle : unsigned char { tbsTree, tbsList };

class DELPHICLASS TcxSchedulerTreeListBrowser;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowser : public Cxtldata::TcxVirtualTreeList
{
	typedef Cxtldata::TcxVirtualTreeList inherited;
	
private:
	Cxcustomdata::TcxCustomDataSource* FDataSource;
	Cxschedulerstorage::TcxSchedulerEvent* FDropGroup;
	bool FIsLoading;
	TcxShedulerTreeBrowserStyle FStyle;
	Cxschedulertimegridview::TcxSchedulerTimeGridView* FView;
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetFocusedEvent(void);
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	void __fastcall SetStyle(TcxShedulerTreeBrowserStyle AValue);
	MESSAGE void __fastcall WMDROPTOGROUP(Winapi::Messages::TMessage &AMessage);
	MESSAGE void __fastcall WMGROUPUNGROUP(Winapi::Messages::TMessage &AMessage);
	MESSAGE void __fastcall WMUNLOCK(Winapi::Messages::TMessage &AMessage);
	
protected:
	bool __fastcall ChangeExpanding(Cxtl::TcxTreeListNode* ANode, bool ARecursive, bool AExpanded);
	virtual void __fastcall CreateAllColumns(void);
	void __fastcall DragOverEventHandler(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DrawIndicator(Cxtl::TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxtl::TcxTreeListIndicatorCellViewInfo* AViewInfo, bool &ADone);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual Cxtl::TcxTreeListColumnClass __fastcall GetTreeListColumnClass(void);
	virtual Cxinplacecontainer::TcxCustomControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall InternalCollapseNode(Cxtl::TcxTreeListNode* ANode, bool ARecursive);
	virtual bool __fastcall InternalExpandNode(Cxtl::TcxTreeListNode* ANode, bool ARecursive);
	virtual bool __fastcall IsActionSupported(int AButtonIndex);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall RefreshData(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall SetContentLineHeight(int AHeight);
	void __fastcall SetHeaderHeight(int AHeight);
	void __fastcall SetMode(Cxschedulertimegridview::TcxSchedulerTreeBrowserDisplayMode AMode);
	void __fastcall SetTopRecordIndex(int AIndex);
	void __fastcall SetView(Cxschedulertimegridview::TcxSchedulerTimeGridView* AView);
	void __fastcall SynchronizeTopRow(void);
	
public:
	__fastcall virtual TcxSchedulerTreeListBrowser(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSchedulerTreeListBrowser(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall TranslationChanged(void);
	__property Cxschedulerstorage::TcxSchedulerEvent* FocusedEvent = {read=GetFocusedEvent};
	__property TcxShedulerTreeBrowserStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	__property Cxschedulertimegridview::TcxSchedulerTimeGridView* View = {read=FView};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSchedulerTreeListBrowser(HWND ParentWindow) : Cxtldata::TcxVirtualTreeList(ParentWindow) { }
	
private:
	void *__IcxSchedulerTreeBrowserControl;	/* Cxschedulertimegridview::IcxSchedulerTreeBrowserControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {192D59F3-FBB7-4097-B15C-B12C23921173}
	operator Cxschedulertimegridview::_di_IcxSchedulerTreeBrowserControl()
	{
		Cxschedulertimegridview::_di_IcxSchedulerTreeBrowserControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulertimegridview::IcxSchedulerTreeBrowserControl*(void) { return (Cxschedulertimegridview::IcxSchedulerTreeBrowserControl*)&__IcxSchedulerTreeBrowserControl; }
	#endif
	
};


class DELPHICLASS TcxTreeListBrowserColumn;
class PASCALIMPLEMENTATION TcxTreeListBrowserColumn : public Cxtl::TcxTreeListColumn
{
	typedef Cxtl::TcxTreeListColumn inherited;
	
protected:
	virtual bool __fastcall CanEdit(void);
	
public:
	__fastcall virtual ~TcxTreeListBrowserColumn(void);
public:
	/* TcxTreeListColumn.Create */ inline __fastcall virtual TcxTreeListBrowserColumn(System::Classes::TComponent* AOwner) : Cxtl::TcxTreeListColumn(AOwner) { }
	
};


class DELPHICLASS TcxSchedulerTreeBrowserDataSource;
class DELPHICLASS TcxSchedulerTreeListBrowserColumnDataProvider;
class PASCALIMPLEMENTATION TcxSchedulerTreeBrowserDataSource : public Cxtldata::TcxTreeListCustomDataSource
{
	typedef Cxtldata::TcxTreeListCustomDataSource inherited;
	
private:
	TcxSchedulerTreeListBrowser* FBrowser;
	System::Classes::TList* FEvents;
	Cxschedulertimegridview::TcxSchedulerTimeGridViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	TcxSchedulerTreeListBrowserColumnDataProvider* __fastcall GetColumnDataProvider(void * AItemHandle);
	virtual int __fastcall GetChildCount(void * AParentHandle);
	virtual void * __fastcall GetChildRecordHandle(void * AParentHandle, int AChildIndex);
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEventByGroupID(const System::Variant &AGroupID, int AIndex);
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEventByTaskLink(Cxschedulerstorage::TcxSchedulerEventItemLink* ALink);
	System::Variant __fastcall GetGroupID(void * AParentHandle);
	virtual void * __fastcall GetItemHandle(int AItemIndex);
	virtual void * __fastcall GetParentRecordHandle(void * ARecordHandle);
	virtual int __fastcall GetRecordCount(void);
	virtual void * __fastcall GetRecordHandle(int ARecordIndex);
	virtual void * __fastcall GetRootRecordHandle(void);
	virtual System::Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	void __fastcall PrepareEventsList(void);
	virtual void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const System::Variant &AValue);
	__property TcxSchedulerTreeListBrowser* Browser = {read=FBrowser};
	__property System::Classes::TList* Events = {read=FEvents};
	__property Cxschedulertimegridview::TcxSchedulerTimeGridViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerTreeBrowserDataSource(TcxSchedulerTreeListBrowser* ABrowser);
	__fastcall virtual ~TcxSchedulerTreeBrowserDataSource(void);
	virtual void __fastcall DataChanged(void);
};


class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserColumnDataProvider : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerTreeListBrowser* FBrowser;
	Cxtl::TcxTreeListColumn* FColumn;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void) = 0 ;
	virtual int __fastcall GetDefaultColumnWidth(void);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall InitializeProperties(void);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent, const System::Variant &AValue);
	void __fastcall TranslationChanged(void);
	
public:
	__fastcall TcxSchedulerTreeListBrowserColumnDataProvider(TcxSchedulerTreeListBrowser* ABrowser, bool AVisible);
	__property TcxSchedulerTreeListBrowser* Browser = {read=FBrowser};
	__property Cxtl::TcxTreeListColumn* Column = {read=FColumn};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserColumnDataProvider(void) { }
	
};


class DELPHICLASS TcxSchedulerTreeListBrowserColumnCaptionDataProvider;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserColumnCaptionDataProvider : public TcxSchedulerTreeListBrowserColumnDataProvider
{
	typedef TcxSchedulerTreeListBrowserColumnDataProvider inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual int __fastcall GetDefaultColumnWidth(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerTreeListBrowserColumnDataProvider.Create */ inline __fastcall TcxSchedulerTreeListBrowserColumnCaptionDataProvider(TcxSchedulerTreeListBrowser* ABrowser, bool AVisible) : TcxSchedulerTreeListBrowserColumnDataProvider(ABrowser, AVisible) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserColumnCaptionDataProvider(void) { }
	
};


class DELPHICLASS TcxSchedulerTreeListBrowserColumnLocationDataProvider;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserColumnLocationDataProvider : public TcxSchedulerTreeListBrowserColumnDataProvider
{
	typedef TcxSchedulerTreeListBrowserColumnDataProvider inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerTreeListBrowserColumnDataProvider.Create */ inline __fastcall TcxSchedulerTreeListBrowserColumnLocationDataProvider(TcxSchedulerTreeListBrowser* ABrowser, bool AVisible) : TcxSchedulerTreeListBrowserColumnDataProvider(ABrowser, AVisible) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserColumnLocationDataProvider(void) { }
	
};


class DELPHICLASS TcxSchedulerTreeListBrowserColumnDescriptionDataProvider;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserColumnDescriptionDataProvider : public TcxSchedulerTreeListBrowserColumnDataProvider
{
	typedef TcxSchedulerTreeListBrowserColumnDataProvider inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerTreeListBrowserColumnDataProvider.Create */ inline __fastcall TcxSchedulerTreeListBrowserColumnDescriptionDataProvider(TcxSchedulerTreeListBrowser* ABrowser, bool AVisible) : TcxSchedulerTreeListBrowserColumnDataProvider(ABrowser, AVisible) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserColumnDescriptionDataProvider(void) { }
	
};


class DELPHICLASS TcxSchedulerTreeListBrowserColumnStartDataProvider;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserColumnStartDataProvider : public TcxSchedulerTreeListBrowserColumnDataProvider
{
	typedef TcxSchedulerTreeListBrowserColumnDataProvider inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall InitializeProperties(void);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerTreeListBrowserColumnDataProvider.Create */ inline __fastcall TcxSchedulerTreeListBrowserColumnStartDataProvider(TcxSchedulerTreeListBrowser* ABrowser, bool AVisible) : TcxSchedulerTreeListBrowserColumnDataProvider(ABrowser, AVisible) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserColumnStartDataProvider(void) { }
	
};


class DELPHICLASS TcxSchedulerTreeListBrowserColumnFinishDataProvider;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserColumnFinishDataProvider : public TcxSchedulerTreeListBrowserColumnStartDataProvider
{
	typedef TcxSchedulerTreeListBrowserColumnStartDataProvider inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerTreeListBrowserColumnDataProvider.Create */ inline __fastcall TcxSchedulerTreeListBrowserColumnFinishDataProvider(TcxSchedulerTreeListBrowser* ABrowser, bool AVisible) : TcxSchedulerTreeListBrowserColumnStartDataProvider(ABrowser, AVisible) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserColumnFinishDataProvider(void) { }
	
};


class DELPHICLASS TcxSchedulerTreeListBrowserColumnReminderDataProvider;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserColumnReminderDataProvider : public TcxSchedulerTreeListBrowserColumnDataProvider
{
	typedef TcxSchedulerTreeListBrowserColumnDataProvider inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerTreeListBrowserColumnDataProvider.Create */ inline __fastcall TcxSchedulerTreeListBrowserColumnReminderDataProvider(TcxSchedulerTreeListBrowser* ABrowser, bool AVisible) : TcxSchedulerTreeListBrowserColumnDataProvider(ABrowser, AVisible) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserColumnReminderDataProvider(void) { }
	
};


class DELPHICLASS TcxSchedulerTreeListBrowserColumnProgressDataProvider;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserColumnProgressDataProvider : public TcxSchedulerTreeListBrowserColumnDataProvider
{
	typedef TcxSchedulerTreeListBrowserColumnDataProvider inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall InitializeProperties(void);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* const AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerTreeListBrowserColumnDataProvider.Create */ inline __fastcall TcxSchedulerTreeListBrowserColumnProgressDataProvider(TcxSchedulerTreeListBrowser* ABrowser, bool AVisible) : TcxSchedulerTreeListBrowserColumnDataProvider(ABrowser, AVisible) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserColumnProgressDataProvider(void) { }
	
};


class DELPHICLASS TcxSchedulerTreeListBrowserViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerTreeListBrowserViewInfo : public Cxtl::TcxTreeListViewInfo
{
	typedef Cxtl::TcxTreeListViewInfo inherited;
	
private:
	TcxSchedulerTreeListBrowser* __fastcall GetBrowser(void);
	Cxschedulertimegridview::TcxSchedulerTimeGridView* __fastcall GetView(void);
	Cxschedulertimegridview::TcxSchedulerTimeGridViewViewInfo* __fastcall GetView_ViewInfo(void);
	
protected:
	virtual void __fastcall CalculateDefaultHeights(void);
	__property TcxSchedulerTreeListBrowser* Browser = {read=GetBrowser};
	__property Cxschedulertimegridview::TcxSchedulerTimeGridView* View = {read=GetView};
	__property Cxschedulertimegridview::TcxSchedulerTimeGridViewViewInfo* View_ViewInfo = {read=GetView_ViewInfo};
public:
	/* TcxTreeListViewInfo.Create */ inline __fastcall virtual TcxSchedulerTreeListBrowserViewInfo(Cxinplacecontainer::TcxEditingControl* AOwner) : Cxtl::TcxTreeListViewInfo(AOwner) { }
	/* TcxTreeListViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerTreeListBrowserViewInfo(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Word WM_DROPTOGROUP = System::Word(0x81f4);
static const System::Word WM_GROUPUNGROUP = System::Word(0x81f5);
static const System::Word WM_UNLOCK = System::Word(0x81f6);
}	/* namespace Cxschedulertreelistbrowser */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERTREELISTBROWSER)
using namespace Cxschedulertreelistbrowser;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulertreelistbrowserHPP
