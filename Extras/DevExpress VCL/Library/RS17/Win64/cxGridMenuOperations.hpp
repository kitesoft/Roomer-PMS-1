// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridMenuOperations.pas' rev: 24.00 (Win64)

#ifndef CxgridmenuoperationsHPP
#define CxgridmenuoperationsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxGridCustomPopupMenu.hpp>	// Pascal unit
#include <cxGridPopupMenu.hpp>	// Pascal unit
#include <cxGridUIHelper.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridmenuoperations
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridPopupMenuOperationClass;

enum TcxGridPopupMenuOperationState : unsigned char { pmoDefault, pmoTrue, pmoFalse };

typedef bool __fastcall (__closure *TcxGetStateFunc)(void);

class DELPHICLASS TcxGridPopupMenuOperation;
class PASCALIMPLEMENTATION TcxGridPopupMenuOperation : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FBeginGroup;
	TcxGridPopupMenuOperationState FDownState;
	TcxGridPopupMenuOperationState FEnabledState;
	int FImageIndex;
	System::Classes::TList* FParams;
	void *FResCaption;
	int FTag;
	TcxGridPopupMenuOperationState FVisibleState;
	Cxgriduihelper::TcxGridOperationHelper* __fastcall GetGridOperationHelper(void);
	Cxgridpopupmenu::TcxGridPopupMenu* __fastcall GetGridPopupMenu(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetHitGridView(void);
	bool __fastcall GetState(TcxGridPopupMenuOperationState AState, TcxGetStateFunc AGetFunc);
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual NativeUInt __fastcall GetInstance(void);
	virtual int __fastcall GetImageIndex(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	void __fastcall UpdateImage(void);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual bool __fastcall GetDown(void);
	virtual bool __fastcall GetCheckedState(void);
	virtual bool __fastcall GetEnabled(void);
	virtual bool __fastcall GetEnabledState(void);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall GetVisibleState(void);
	__property Cxgriduihelper::TcxGridOperationHelper* GridOperationHelper = {read=GetGridOperationHelper};
	__property System::Classes::TList* Params = {read=FParams};
	__property void * ResCaption = {read=FResCaption, write=FResCaption};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	
public:
	__fastcall virtual TcxGridPopupMenuOperation(void);
	void __fastcall DoExecute(System::TObject* Sender);
	__classmethod virtual TcxGridPopupMenuOperationClass __fastcall GetParentOperationClass();
	__property bool BeginGroup = {read=FBeginGroup, write=FBeginGroup, nodefault};
	__property System::UnicodeString Caption = {read=GetCaption};
	__property bool Down = {read=GetCheckedState, nodefault};
	__property bool Enabled = {read=GetEnabledState, nodefault};
	__property int ImageIndex = {read=FImageIndex, write=FImageIndex, nodefault};
	__property bool Visible = {read=GetVisibleState, nodefault};
	__property TcxGridPopupMenuOperationState DownState = {read=FDownState, write=FDownState, default=0};
	__property TcxGridPopupMenuOperationState EnabledState = {read=FEnabledState, write=FEnabledState, default=0};
	__property Cxgridcustomview::TcxCustomGridView* HitGridView = {read=GetHitGridView};
	__property Cxgridpopupmenu::TcxGridPopupMenu* GridPopupMenu = {read=GetGridPopupMenu};
	__property TcxGridPopupMenuOperationState VisibleState = {read=FVisibleState, write=FVisibleState, default=0};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridPopupMenuOperation(void) { }
	
};


class DELPHICLASS TcxGridTablePopupMenuOperation;
class PASCALIMPLEMENTATION TcxGridTablePopupMenuOperation : public TcxGridPopupMenuOperation
{
	typedef TcxGridPopupMenuOperation inherited;
	
private:
	HIDESBASE Cxgridtableview::TcxGridTableView* __fastcall GetHitGridView(void);
	
public:
	__property Cxgridtableview::TcxGridTableView* HitGridView = {read=GetHitGridView};
public:
	/* TcxGridPopupMenuOperation.Create */ inline __fastcall virtual TcxGridTablePopupMenuOperation(void) : TcxGridPopupMenuOperation() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridTablePopupMenuOperation(void) { }
	
};


class DELPHICLASS TcxGridTableColumnMenuOperation;
class PASCALIMPLEMENTATION TcxGridTableColumnMenuOperation : public TcxGridTablePopupMenuOperation
{
	typedef TcxGridTablePopupMenuOperation inherited;
	
private:
	Cxgridtableview::TcxGridColumn* __fastcall GetHitColumn(void);
	
public:
	__property Cxgridtableview::TcxGridColumn* HitColumn = {read=GetHitColumn};
public:
	/* TcxGridPopupMenuOperation.Create */ inline __fastcall virtual TcxGridTableColumnMenuOperation(void) : TcxGridTablePopupMenuOperation() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridTableColumnMenuOperation(void) { }
	
};


typedef System::TMetaClass* TcxGridPopupMenuOperationsClass;

class DELPHICLASS TcxGridPopupMenuOperations;
class PASCALIMPLEMENTATION TcxGridPopupMenuOperations : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridPopupMenuOperation* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxGridPopupMenuOperation* __fastcall GetItem(int Index);
	
protected:
	TcxGridPopupMenuOperation* __fastcall AddItem(TcxGridPopupMenuOperationClass AItemClass);
	virtual void __fastcall AddItems(void) = 0 ;
	void __fastcall ClearItems(void);
	void __fastcall RecreateItems(void);
	
public:
	__fastcall virtual TcxGridPopupMenuOperations(void);
	__fastcall virtual ~TcxGridPopupMenuOperations(void);
	virtual bool __fastcall CanProcess(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridPopupMenuOperation* Items[int Index] = {read=GetItem/*, default*/};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Vcl::Imglist::TCustomImageList* cxGridPopupMenuImages;
extern PACKAGE System::UnicodeString __fastcall GetSummaryImageResourceName(Cxcustomdata::TcxSummaryKind ASummaryKind);
}	/* namespace Cxgridmenuoperations */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDMENUOPERATIONS)
using namespace Cxgridmenuoperations;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridmenuoperationsHPP
