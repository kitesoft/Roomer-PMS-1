// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridCustomPopupMenu.pas' rev: 24.00 (Win32)

#ifndef CxgridcustompopupmenuHPP
#define CxgridcustompopupmenuHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridcustompopupmenu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxGridPopupMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxGridPopupMenu : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxGridPopupMenu(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxGridPopupMenu(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxGridPopupMenu(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxGridPopupMenu(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxGridPopupMenu(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxGridPopupMenu(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxGridPopupMenu(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxGridPopupMenu(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxGridPopupMenu(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxGridPopupMenu(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxGridPopupMenu(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxGridPopupMenu(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxGridPopupMenu(void) { }
	
};

#pragma pack(pop)

enum TcxGridViewHitType : unsigned char { gvhtGridNone, gvhtGridTab, gvhtNone, gvhtTab, gvhtCell, gvhtExpandButton, gvhtRecord, gvhtNavigator, gvhtPreview, gvhtColumnHeader, gvhtColumnHeaderFilterButton, gvhtFilter, gvhtFooter, gvhtFooterCell, gvhtGroupFooter, gvhtGroupFooterCell, gvhtGroupByBox, gvhtIndicator, gvhtIndicatorHeader, gvhtIndicatorBandHeader, gvhtRowIndicator, gvhtRowLevelIndent, gvhtBand, gvhtBandHeader, gvhtRowCaption, gvhtSeparator, gvhtGroupSummary };

typedef System::Set<TcxGridViewHitType, TcxGridViewHitType::gvhtGridNone, TcxGridViewHitType::gvhtGroupSummary>  TcxGridViewHitTypes;

typedef void __fastcall (__closure *TcxGridBeforePopupProc)(System::Classes::TComponent* ASenderMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, int X, int Y, bool &AllowPopup);

typedef void __fastcall (__closure *TcxGridOnPopupProc)(System::Classes::TComponent* ASenderMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, int X, int Y);

typedef void __fastcall (__closure *TcxGridPopupMenuItemClickProc)(System::TObject* ASender, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TNotifyEvent &AHandler, System::Classes::TList* AParams, bool &AHandled);

__interface IDoPopup;
typedef System::DelphiInterface<IDoPopup> _di_IDoPopup;
__interface  INTERFACE_UUID("{41999EDE-B9D9-4808-9D01-61B09DF700FA}") IDoPopup  : public System::IInterface 
{
	
public:
	virtual TcxGridOnPopupProc __fastcall GetPopupHandler(void) = 0 ;
};

__interface IcxGridPopupMenu;
typedef System::DelphiInterface<IcxGridPopupMenu> _di_IcxGridPopupMenu;
__interface  INTERFACE_UUID("{302C3B32-D753-43A6-BAE2-F513EB4F9399}") IcxGridPopupMenu  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanPopup(Cxgridcustomview::TcxCustomGridHitTest* AHitTest) = 0 ;
};

class DELPHICLASS TcxPopupMenuInfo;
class PASCALIMPLEMENTATION TcxPopupMenuInfo : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Classes::TComponent* FPopupMenu;
	TcxGridOnPopupProc FPopupProc;
	TcxGridViewHitTypes FHitTypes;
	bool FLocked;
	Cxgridcustomview::TcxCustomGridView* FView;
	Cxgridcustomview::TcxCustomGridViewClass FViewClass;
	System::Classes::TComponent* __fastcall FindCorrectComponent(System::Classes::TComponent* const AComponent);
	void __fastcall SetPopupMenu(System::Classes::TComponent* const AValue);
	void __fastcall SetView(Cxgridcustomview::TcxCustomGridView* const AValue);
	void __fastcall SetViewClass(const Cxgridcustomview::TcxCustomGridViewClass Value);
	
protected:
	bool FIsBuiltIn;
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall EndUpdate(void);
	bool __fastcall CanPopup(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall DoChanged(System::Classes::TComponent* const APopupMenu, Cxgridcustomview::TcxCustomGridView* const AView, Cxgridcustomview::TcxCustomGridViewClass AViewClass);
	__property Cxgridcustomview::TcxCustomGridViewClass GridViewClass = {read=FViewClass, write=SetViewClass};
	
public:
	__fastcall virtual ~TcxPopupMenuInfo(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool IsBuiltIn = {read=FIsBuiltIn, nodefault};
	
__published:
	__property Cxgridcustomview::TcxCustomGridView* GridView = {read=FView, write=SetView};
	__property TcxGridViewHitTypes HitTypes = {read=FHitTypes, write=FHitTypes, nodefault};
	__property Index;
	__property TcxGridOnPopupProc OnPopup = {read=FPopupProc, write=FPopupProc};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxPopupMenuInfo(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	
};


class DELPHICLASS TcxPopupMenuInfos;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPopupMenuInfos : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxPopupMenuInfo* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	System::Classes::TComponent* FOwner;
	HIDESBASE TcxPopupMenuInfo* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxPopupMenuInfo* const AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual bool __fastcall IsMenuInfoShortCut(TcxPopupMenuInfo* AMenuInfo, Winapi::Messages::TWMKey &Message);
	virtual bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	virtual void __fastcall Notify(System::Classes::TCollectionItem* Item, System::Classes::TCollectionNotification Action);
	
public:
	__fastcall virtual TcxPopupMenuInfos(System::Classes::TComponent* AOwner);
	int __fastcall GetSameMenuCount(System::Classes::TComponent* const AMenu);
	__property TcxPopupMenuInfo* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxPopupMenuInfos(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridPopupMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridPopupMenu : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
public:
	TcxPopupMenuInfo* operator[](int AIndex) { return MenuInfos[AIndex]; }
	
private:
	TcxPopupMenuInfos* FPopupMenuInfos;
	TcxPopupMenuInfo* __fastcall GetMenuInfo(int AIndex);
	int __fastcall GetMenuInfoCount(void);
	void __fastcall SetPopupMenuInfos(TcxPopupMenuInfos* const AValue);
	
protected:
	void __fastcall AddMenuInfo(System::Classes::TComponent* const AMenu, TcxGridViewHitTypes AHitTypes, TcxGridOnPopupProc ADoPopupProc, Cxgridcustomview::TcxCustomGridViewClass AViewClass = 0x0, Cxgridcustomview::TcxCustomGridView* const AView = (Cxgridcustomview::TcxCustomGridView*)(0x0), bool AIsBuiltIn = false);
	void __fastcall AdjustMenuInfo(TcxPopupMenuInfo* AMenuInfo, System::Classes::TComponent* const AMenu, TcxGridViewHitTypes AHitTypes, TcxGridOnPopupProc ADoPopupProc, Cxgridcustomview::TcxCustomGridViewClass AViewClass = 0x0, Cxgridcustomview::TcxCustomGridView* const AView = (Cxgridcustomview::TcxCustomGridView*)(0x0), bool AIsBuiltIn = false);
	void __fastcall ClearMenuInfosGridView(Cxgridcustomview::TcxCustomGridView* const AView = (Cxgridcustomview::TcxCustomGridView*)(0x0));
	virtual TcxPopupMenuInfo* __fastcall GetPopupMenuInfo(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridView* const AView, bool ASearchDefault = true)/* overload */;
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property TcxPopupMenuInfos* PopupMenuInfos = {read=FPopupMenuInfos, write=SetPopupMenuInfos};
	__property TcxPopupMenuInfo* MenuInfos[int AIndex] = {read=GetMenuInfo/*, default*/};
	
public:
	__fastcall virtual TcxCustomGridPopupMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomGridPopupMenu(void);
	virtual bool __fastcall CheckShortCuts(Winapi::Messages::TWMKey &Message);
	virtual TcxPopupMenuInfo* __fastcall FindPopupMenuInfo(Cxgridcustomview::TcxCustomGridView* const AView, TcxGridViewHitType AHitType, Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual TcxPopupMenuInfo* __fastcall GetPopupMenuInfo(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridViewClass AViewClass, bool ASearchDefault = true)/* overload */;
	__property int Count = {read=GetMenuInfoCount, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxGridDefaultPopupMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDefaultPopupMenu : public TcxCustomGridPopupMenu
{
	typedef TcxCustomGridPopupMenu inherited;
	
protected:
	virtual TcxPopupMenuInfo* __fastcall GetPopupMenuInfo(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridView* const AView, bool ASearchDefault = true)/* overload */;
	virtual void __fastcall InternalRegisterPopupMenu(System::Classes::TComponent* const AMenu, TcxGridViewHitTypes AHitTypes, TcxGridOnPopupProc ADoPopupProc, Cxgridcustomview::TcxCustomGridViewClass AViewClass, bool AIsBuiltIn = false);
	
public:
	virtual TcxPopupMenuInfo* __fastcall GetPopupMenuInfo(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridViewClass AViewClass, bool ASearchDefault = true)/* overload */;
	virtual void __fastcall RegisterPopupMenu(System::Classes::TComponent* const AMenu, TcxGridViewHitTypes AHitTypes, TcxGridOnPopupProc ADoPopupProc, Cxgridcustomview::TcxCustomGridViewClass AViewClass);
	virtual void __fastcall UnRegisterPopupMenu(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridViewClass AViewClass, TcxGridViewHitTypes AHitTypes = TcxGridViewHitTypes() );
	__property MenuInfos;
public:
	/* TcxCustomGridPopupMenu.Create */ inline __fastcall virtual TcxGridDefaultPopupMenu(System::Classes::TComponent* AOwner) : TcxCustomGridPopupMenu(AOwner) { }
	/* TcxCustomGridPopupMenu.Destroy */ inline __fastcall virtual ~TcxGridDefaultPopupMenu(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxPopupMenuClass;

class DELPHICLASS TcxPopupMenuClassInfoRec;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPopupMenuClassInfoRec : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxPopupMenuClass MenuClass;
	TcxGridViewHitTypes HitTypes;
	Cxgridcustomview::TcxCustomGridViewClass ViewClass;
	__fastcall TcxPopupMenuClassInfoRec(TcxPopupMenuClass AMenuClass, TcxGridViewHitTypes AHitTypes, Cxgridcustomview::TcxCustomGridViewClass AViewClass);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPopupMenuClassInfoRec(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxBuiltInPopupMenus;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBuiltInPopupMenus : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxPopupMenuClassInfoRec* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	System::Classes::TList* FInfoRecs;
	int __fastcall GetCount(void);
	TcxPopupMenuClassInfoRec* __fastcall GetItem(int AIndex);
	
protected:
	TcxPopupMenuClassInfoRec* __fastcall Add(TcxPopupMenuClass AMenuClass, TcxGridViewHitTypes AHitTypes, Cxgridcustomview::TcxCustomGridViewClass AViewClass);
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	void __fastcall RegisterItemTo(TcxGridDefaultPopupMenu* ADefaultPopupMenu, int AItemIndex);
	void __fastcall Remove(TcxPopupMenuClass APopupMenuClass);
	__property int Count = {read=GetCount, nodefault};
	__property TcxPopupMenuClassInfoRec* Items[int AIndex] = {read=GetItem/*, default*/};
	
public:
	__fastcall TcxBuiltInPopupMenus(void);
	__fastcall virtual ~TcxBuiltInPopupMenus(void);
	void __fastcall RegisterItemsTo(TcxGridDefaultPopupMenu* ADefaultPopupMenu);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Word cxhtGridBase = System::Word(0x3e8);
extern PACKAGE TcxBuiltInPopupMenus* BuiltInPopupMenuList;
extern PACKAGE TcxGridViewHitType __fastcall GetHitTypeByHitCode(int AHitCode);
extern PACKAGE void __fastcall RegisterPopupMenuClass(TcxPopupMenuClass APopupMenuClass, TcxGridViewHitTypes AHitTypes, Cxgridcustomview::TcxCustomGridViewClass AViewClass);
extern PACKAGE void __fastcall UnregisterPopupMenuClass(TcxPopupMenuClass APopupMenuClass);
}	/* namespace Cxgridcustompopupmenu */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDCUSTOMPOPUPMENU)
using namespace Cxgridcustompopupmenu;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridcustompopupmenuHPP
