// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridUIHelper.pas' rev: 24.00 (Win32)

#ifndef CxgriduihelperHPP
#define CxgriduihelperHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriduihelper
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomGridOperationHelperParameters;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridOperationHelperParameters : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgridcustomview::TcxCustomGridView* FView;
	bool FIsPerform;
	
public:
	__fastcall virtual TcxCustomGridOperationHelperParameters(Cxgridcustomview::TcxCustomGridView* AView, bool AIsPerform);
	__property Cxgridcustomview::TcxCustomGridView* View = {read=FView};
	__property bool IsPerform = {read=FIsPerform, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridOperationHelperParameters(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxShowingGridOperationHelperParameters;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxShowingGridOperationHelperParameters : public TcxCustomGridOperationHelperParameters
{
	typedef TcxCustomGridOperationHelperParameters inherited;
	
private:
	bool FShowing;
	
public:
	__property bool Showing = {read=FShowing, write=FShowing, nodefault};
public:
	/* TcxCustomGridOperationHelperParameters.Create */ inline __fastcall virtual TcxShowingGridOperationHelperParameters(Cxgridcustomview::TcxCustomGridView* AView, bool AIsPerform) : TcxCustomGridOperationHelperParameters(AView, AIsPerform) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxShowingGridOperationHelperParameters(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridOperationHelperProc)(TcxCustomGridOperationHelperParameters* const AParameter);

class DELPHICLASS TcxCustomGridViewOperationHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridViewOperationHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FList;
	
protected:
	void __fastcall RegisterOperation(int AOperationIndex, const TcxGridOperationHelperProc AProc);
	virtual void __fastcall RegisterOperations(void);
	bool __fastcall GetShowProperty(TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall SetShowProperty(TcxCustomGridOperationHelperParameters* const AParameter, bool AShow);
	void __fastcall DoFirst(TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoLast(TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoNext(TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoPrev(TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoInsert(TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoDelete(TcxCustomGridOperationHelperParameters* const AParameter);
	
public:
	__fastcall virtual TcxCustomGridViewOperationHelper(void);
	__fastcall virtual ~TcxCustomGridViewOperationHelper(void);
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
	virtual bool __fastcall IsOperationAccessible(int AOperationIndex);
	virtual bool __fastcall IsOperationEnabled(Cxgridcustomview::TcxCustomGridView* AView, int AOperationIndex);
	virtual void __fastcall PerformOperation(int AOperationIndex, TcxCustomGridOperationHelperParameters* const AParameter);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridViewOperationHelperClass;

class DELPHICLASS TcxCustomGridOperationHelper;
class PASCALIMPLEMENTATION TcxCustomGridOperationHelper : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Cxgrid::TcxCustomGridNotification* FFocusedViewChangedNotification;
	Cxgrid::TcxGrid* FGrid;
	System::Classes::TNotifyEvent FOnUpdateOperations;
	System::Classes::TNotifyEvent FOnFocusedRecordChanged;
	System::Classes::TNotifyEvent FOnCustomizationFormVisibleChanged;
	bool __fastcall GetIsOperationAccessible(int AOperationIndex);
	bool __fastcall GetIsOperationEnabled(int AOperationIndex);
	bool __fastcall GetIsOperationShowing(int AOperationIndex);
	void __fastcall SetGrid(Cxgrid::TcxGrid* const Value);
	void __fastcall DoFocusedViewChanged(void);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	DYNAMIC void __fastcall DoUpdateOperations(void);
	DYNAMIC void __fastcall DoFocusedRecordChanged(void);
	DYNAMIC void __fastcall DoCustomizationFormVisibleChanged(void);
	
public:
	__fastcall virtual TcxCustomGridOperationHelper(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomGridOperationHelper(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall FocusedView(void);
	Cxgridcustomview::TcxCustomGridViewClass __fastcall FocusedViewClass(void);
	void __fastcall PerformOperation(int AOperationIndex, TcxCustomGridOperationHelperParameters* const AParameters);
	void __fastcall PerformStandardOperation(int AOperationIndex);
	void __fastcall PerformShowingOperation(int AOperationIndex, bool AShow);
	__property bool IsOperationAccessible[int AOperationIndex] = {read=GetIsOperationAccessible};
	__property bool IsOperationEnabled[int AOperationIndex] = {read=GetIsOperationEnabled};
	__property bool IsOperationShowing[int AOperationIndex] = {read=GetIsOperationShowing};
	void __fastcall DoFirst(void);
	void __fastcall DoLast(void);
	void __fastcall DoNext(void);
	void __fastcall DoPrev(void);
	void __fastcall DoInsert(void);
	void __fastcall DoDelete(void);
	void __fastcall CopyToClipboard(void);
	void __fastcall DoShowColumnCustomizing(bool AShow);
	void __fastcall DoShowGroupingPanel(bool AShow);
	void __fastcall DoShowHeaders(bool AShow);
	void __fastcall DoShowBands(bool AShow);
	void __fastcall DoShowSummaryFooter(bool AShow);
	void __fastcall DoShowGrid(bool AShow);
	void __fastcall DoColumnAutoWidth(bool AShow);
	void __fastcall DoShowPreview(bool AShow);
	void __fastcall DoShowEditButtons(bool AShow);
	void __fastcall DoLayoutDirection(bool AShow);
	void __fastcall DoInvertSelect(bool AShow);
	void __fastcall DoShowIndicator(bool AShow);
	bool __fastcall IsColumnsCustomizingShowing(void);
	bool __fastcall IsGroupingPanelShowing(void);
	bool __fastcall IsHeadersShowing(void);
	bool __fastcall IsBandsShowing(void);
	bool __fastcall IsSummaryFooterShowing(void);
	bool __fastcall IsGridShowing(void);
	bool __fastcall IsColumnAutoWidth(void);
	bool __fastcall IsShowPreview(void);
	bool __fastcall IsShowEditButtons(void);
	bool __fastcall IsVertLayoutDirection(void);
	bool __fastcall IsInvertSelect(void);
	bool __fastcall IsShowIndicator(void);
	__property Cxgrid::TcxGrid* Grid = {read=FGrid, write=SetGrid};
	__property System::Classes::TNotifyEvent OnUpdateOperations = {read=FOnUpdateOperations, write=FOnUpdateOperations};
	__property System::Classes::TNotifyEvent onFocusedRecordChanged = {read=FOnFocusedRecordChanged, write=FOnFocusedRecordChanged};
	__property System::Classes::TNotifyEvent OnCustomizationFormVisibleChanged = {read=FOnCustomizationFormVisibleChanged, write=FOnCustomizationFormVisibleChanged};
};


class DELPHICLASS TcxGridOperationHelper;
class PASCALIMPLEMENTATION TcxGridOperationHelper : public TcxCustomGridOperationHelper
{
	typedef TcxCustomGridOperationHelper inherited;
	
__published:
	__property Grid;
	__property OnUpdateOperations;
public:
	/* TcxCustomGridOperationHelper.Create */ inline __fastcall virtual TcxGridOperationHelper(System::Classes::TComponent* AOwner) : TcxCustomGridOperationHelper(AOwner) { }
	/* TcxCustomGridOperationHelper.Destroy */ inline __fastcall virtual ~TcxGridOperationHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 GROP_FIRST = System::Int8(0x0);
static const System::Int8 GROP_LAST = System::Int8(0x1);
static const System::Int8 GROP_PREV = System::Int8(0x2);
static const System::Int8 GROP_NEXT = System::Int8(0x3);
static const System::Int8 GROP_INSERT = System::Int8(0x4);
static const System::Int8 GROP_DELETE = System::Int8(0x5);
static const System::Int8 GROP_COPYTOCLIPBOARD = System::Int8(0x6);
static const System::Int8 GROP_SHOWCOLUMNCUSTOMIZING = System::Int8(0x64);
static const System::Int8 GROP_SHOWGROUPINGPANEL = System::Int8(0x65);
static const System::Int8 GROP_SHOWINDICATOR = System::Int8(0x66);
static const System::Int8 GROP_INVERTSELECT = System::Int8(0x67);
static const System::Int8 GROP_SHOWHEADERS = System::Int8(0x68);
static const System::Int8 GROP_SHOWSUMMARYFOOTER = System::Int8(0x69);
static const System::Int8 GROP_SHOWBANDS = System::Int8(0x6a);
static const System::Int8 GROP_SHOWGRID = System::Int8(0x6b);
static const System::Int8 GROP_COLUMNAUTOWIDTH = System::Int8(0x6c);
static const System::Int8 GROP_SHOWPREVIEW = System::Int8(0x6d);
static const System::Int8 GROP_SHOWEDITBUTTONS = System::Int8(0x6e);
static const System::Int8 GROP_LAYOUTDIRECTION = System::Int8(0x6f);
extern PACKAGE void __fastcall RegisterGridViewOperationHelper(TcxCustomGridViewOperationHelperClass AGridViewOperationHelperClass);
extern PACKAGE void __fastcall UnregisterGridViewOperationHelper(TcxCustomGridViewOperationHelperClass AGridViewOperationHelperClass);
extern PACKAGE TcxCustomGridViewOperationHelper* __fastcall GetGridViewOperationHelperByGridViewClass(const Cxgridcustomview::TcxCustomGridViewClass AGridViewClass);
}	/* namespace Cxgriduihelper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDUIHELPER)
using namespace Cxgriduihelper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriduihelperHPP
