// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridLevel.pas' rev: 24.00 (Win32)

#ifndef CxgridlevelHPP
#define CxgridlevelHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridlevel
{
//-- type declarations -------------------------------------------------------
enum TcxGridDetailTabsPosition : unsigned char { dtpNone, dtpLeft, dtpTop };

typedef System::TMetaClass* TcxGridLevelOptionsClass;

class DELPHICLASS TcxGridLevelOptions;
class DELPHICLASS TcxGridLevel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLevelOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Uitypes::TColor FDetailFrameColor;
	int FDetailFrameWidth;
	TcxGridDetailTabsPosition FDetailTabsPosition;
	TcxGridLevel* FLevel;
	bool FTabsForEmptyDetails;
	void __fastcall SetDetailFrameColor(System::Uitypes::TColor Value);
	void __fastcall SetDetailFrameWidth(int Value);
	void __fastcall SetDetailTabsPosition(TcxGridDetailTabsPosition Value);
	void __fastcall SetTabsForEmptyDetails(bool Value);
	
protected:
	void __fastcall Changed(bool AHardChange = true);
	__property TcxGridLevel* Level = {read=FLevel};
	
public:
	__fastcall virtual TcxGridLevelOptions(TcxGridLevel* ALevel);
	System::Uitypes::TColor __fastcall GetDetailFrameColor(void);
	
__published:
	__property System::Uitypes::TColor DetailFrameColor = {read=FDetailFrameColor, write=SetDetailFrameColor, default=536870912};
	__property int DetailFrameWidth = {read=FDetailFrameWidth, write=SetDetailFrameWidth, default=1};
	__property TcxGridDetailTabsPosition DetailTabsPosition = {read=FDetailTabsPosition, write=SetDetailTabsPosition, default=0};
	__property bool TabsForEmptyDetails = {read=FTabsForEmptyDetails, write=SetTabsForEmptyDetails, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridLevelOptions(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridLevelGetOwnTabStyleEvent)(TcxGridLevel* Sender, Cxgridcustomtableview::TcxCustomGridRecord* AMasterRecord, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxGridLevelGetTabStyleEvent)(TcxGridLevel* Sender, TcxGridLevel* ATabLevel, Cxstyles::TcxStyle* &AStyle);

typedef System::TMetaClass* TcxGridLevelStylesClass;

class DELPHICLASS TcxGridLevelStyles;
class PASCALIMPLEMENTATION TcxGridLevelStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	TcxGridLevelGetOwnTabStyleEvent FOnGetOwnTabStyle;
	TcxGridLevelGetTabStyleEvent FOnGetTabStyle;
	TcxGridLevel* __fastcall GetLevel(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall DoGetOwnTabStyle(Cxgridcustomtableview::TcxCustomGridRecord* AMasterRecord, Cxstyles::TcxStyle* &AStyle);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
public:
	__property TcxGridLevel* Level = {read=GetLevel};
	void __fastcall GetTabDefaultParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetTabParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, TcxGridLevel* ATabLevel, /* out */ Cxgraphics::TcxViewParams &AParams);
	
__published:
	__property Cxstyles::TcxStyle* Tab = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* TabsBackground = {read=GetValue, write=SetValue, index=1};
	__property TcxGridLevelGetOwnTabStyleEvent OnGetOwnTabStyle = {read=FOnGetOwnTabStyle, write=FOnGetOwnTabStyle};
	__property TcxGridLevelGetTabStyleEvent OnGetTabStyle = {read=FOnGetTabStyle, write=FOnGetTabStyle};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxGridLevelStyles(System::Classes::TPersistent* AOwner) : Cxstyles::TcxStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridLevelStyles(void) { }
	
};


typedef void __fastcall (__closure *TcxGridLevelGetGridViewEvent)(TcxGridLevel* Sender, Cxgridcustomtableview::TcxCustomGridRecord* AMasterRecord, Cxgridcustomview::TcxCustomGridView* &AGridView);

enum TcxGridLevelChangeKind : unsigned char { lcName, lcCaption, lcGridView, lcStructure, lcVisibility };

typedef System::TMetaClass* TcxGridLevelClass;

class PASCALIMPLEMENTATION TcxGridLevel : public Cxclasses::TcxComponent
{
	typedef Cxclasses::TcxComponent inherited;
	
public:
	TcxGridLevel* operator[](int Index) { return Items[Index]; }
	
private:
	System::UnicodeString FCaption;
	Cxcontrols::TcxControl* FControl;
	Cxcustomdata::TcxCustomDataRelation* FDataRelation;
	Cxgridcustomview::TcxCustomGridView* FGridView;
	System::Uitypes::TImageIndex FImageIndex;
	System::Classes::TList* FItems;
	int FMaxDetailHeight;
	TcxGridLevelOptions* FOptions;
	TcxGridLevel* FParent;
	TcxGridLevelStyles* FStyles;
	bool FVisible;
	System::Classes::TList* FVisibleItems;
	System::Classes::TNotifyEvent FSubClassEvents;
	TcxGridLevelGetGridViewEvent FOnGetGridView;
	bool __fastcall GetActive(void);
	bool __fastcall GetActuallyVisible(void);
	bool __fastcall GetCanBeVisible(void);
	int __fastcall GetCount(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIsMaster(void);
	bool __fastcall GetIsRoot(void);
	bool __fastcall GetIsTop(void);
	TcxGridLevel* __fastcall GetItem(int Index);
	int __fastcall GetLevel(void);
	int __fastcall GetVisibleCount(void);
	int __fastcall GetVisibleIndex(void);
	TcxGridLevel* __fastcall GetVisibleItem(int Index);
	void __fastcall SetActive(bool Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetGridView(Cxgridcustomview::TcxCustomGridView* Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetMaxDetailHeight(int Value);
	void __fastcall SetParent(TcxGridLevel* Value);
	void __fastcall SetStyles(TcxGridLevelStyles* Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall AddItem(TcxGridLevel* AItem);
	void __fastcall RemoveItem(TcxGridLevel* AItem);
	void __fastcall ChangeItemIndex(TcxGridLevel* AItem, int Value);
	int __fastcall GetItemIndex(TcxGridLevel* AItem);
	void __fastcall DestroyItems(void);
	void __fastcall RefreshVisibleItemsList(void);
	void __fastcall AddDataRelation(TcxGridLevel* AItem);
	void __fastcall MoveDataRelation(TcxGridLevel* AItem, int AIndex);
	void __fastcall RemoveDataRelation(TcxGridLevel* AItem);
	
protected:
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall CreateLinkObject(Cxcustomdata::TcxCustomDataRelation* ARelation, int ARecordIndex);
	virtual void __fastcall Changed(bool AHardChange = true);
	virtual void __fastcall CheckHeight(int &Value);
	virtual void __fastcall Deactivate(void);
	virtual System::UnicodeString __fastcall GetDisplayCaption(void);
	virtual TcxGridLevelClass __fastcall GetItemClass(void);
	virtual TcxGridLevelOptionsClass __fastcall GetOptionsClass(void);
	virtual TcxGridLevelStylesClass __fastcall GetStylesClass(void);
	virtual void __fastcall ItemVisibleChanged(TcxGridLevel* AItem);
	void __fastcall NotifyControl(TcxGridLevelChangeKind AChangeKind);
	void __fastcall SetupMasterRelation(bool AVisible, bool AIsPattern);
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	
public:
	__fastcall virtual TcxGridLevel(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridLevel(void);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	TcxGridLevel* __fastcall Add(void);
	TcxGridLevel* __fastcall GetAvailableItem(void);
	bool __fastcall HasAsChild(TcxGridLevel* ALevel);
	Cxgridcustomview::TcxCustomGridView* __fastcall MakeVisible(void);
	__property bool Active = {read=GetActive, write=SetActive, nodefault};
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property bool CanBeVisible = {read=GetCanBeVisible, nodefault};
	__property Cxcontrols::TcxControl* Control = {read=FControl, write=FControl};
	__property int Count = {read=GetCount, nodefault};
	__property Cxcustomdata::TcxCustomDataRelation* DataRelation = {read=FDataRelation};
	__property System::UnicodeString DisplayCaption = {read=GetDisplayCaption};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property bool IsMaster = {read=GetIsMaster, nodefault};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property bool IsTop = {read=GetIsTop, nodefault};
	__property TcxGridLevel* Items[int Index] = {read=GetItem/*, default*/};
	__property int Level = {read=GetLevel, nodefault};
	__property TcxGridLevel* Parent = {read=FParent, write=SetParent};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
	__property TcxGridLevel* VisibleItems[int Index] = {read=GetVisibleItem};
	
__published:
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property Cxgridcustomview::TcxCustomGridView* GridView = {read=FGridView, write=SetGridView};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property int MaxDetailHeight = {read=FMaxDetailHeight, write=SetMaxDetailHeight, default=0};
	__property TcxGridLevelOptions* Options = {read=FOptions, write=FOptions};
	__property TcxGridLevelStyles* Styles = {read=FStyles, write=SetStyles};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property System::Classes::TNotifyEvent StylesEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property TcxGridLevelGetGridViewEvent OnGetGridView = {read=FOnGetGridView, write=FOnGetGridView};
};


class DELPHICLASS TcxGridLevelAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLevelAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void __fastcall CheckHeight(TcxGridLevel* AInstance, int &Value);
	__classmethod Cxgridcustomview::TcxCustomGridView* __fastcall CreateLinkObject(TcxGridLevel* AInstance, Cxcustomdata::TcxCustomDataRelation* ARelation, int ARecordIndex);
	__classmethod void __fastcall Deactivate(TcxGridLevel* AInstance);
public:
	/* TObject.Create */ inline __fastcall TcxGridLevelAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLevelAccess(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxGridLevelDefaultDetailFrameWidth = System::Int8(0x1);
static const TcxGridDetailTabsPosition cxGridLevelDefaultDetailTabsPosition = (TcxGridDetailTabsPosition)(0);
static const System::Int8 lsFirst = System::Int8(0x0);
static const System::Int8 lsTab = System::Int8(0x0);
static const System::Int8 lsTabsBackground = System::Int8(0x1);
static const System::Int8 lsLast = System::Int8(0x1);
extern PACKAGE bool cxGridTabAccelSupport;
}	/* namespace Cxgridlevel */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDLEVEL)
using namespace Cxgridlevel;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridlevelHPP
