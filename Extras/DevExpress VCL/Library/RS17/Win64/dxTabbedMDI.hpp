// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxTabbedMDI.pas' rev: 24.00 (Win64)

#ifndef DxtabbedmdiHPP
#define DxtabbedmdiHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <System.StrUtils.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <dxHooks.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxtabbedmdi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EdxTabbedMDIManagerException;
class PASCALIMPLEMENTATION EdxTabbedMDIManagerException : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxTabbedMDIManagerException(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxTabbedMDIManagerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxTabbedMDIManagerException(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxTabbedMDIManagerException(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxTabbedMDIManagerException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxTabbedMDIManagerException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxTabbedMDIManagerException(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxTabbedMDIManagerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxTabbedMDIManagerException(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxTabbedMDIManagerException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxTabbedMDIManagerException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxTabbedMDIManagerException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxTabbedMDIManagerException(void) { }
	
};


class DELPHICLASS TdxTabbedMDITabControlHintHelper;
class PASCALIMPLEMENTATION TdxTabbedMDITabControlHintHelper : public Cxpc::TcxCustomTabControlHintHelper
{
	typedef Cxpc::TcxCustomTabControlHintHelper inherited;
	
protected:
	virtual bool __fastcall CanShowHint(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerWinControl(void);
	virtual bool __fastcall PtInCaller(const System::Types::TPoint P);
public:
	/* TcxCustomTabControlHintHelper.Create */ inline __fastcall TdxTabbedMDITabControlHintHelper(Cxpc::TcxCustomTabControlController* AController) : Cxpc::TcxCustomTabControlHintHelper(AController) { }
	
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TdxTabbedMDITabControlHintHelper(void) { }
	
};


class DELPHICLASS TdxTabbedMDITabController;
class PASCALIMPLEMENTATION TdxTabbedMDITabController : public Cxpc::TcxCustomTabControlController
{
	typedef Cxpc::TcxCustomTabControlController inherited;
	
private:
	Cxcontrols::TcxControl* FMDITabControl;
	
protected:
	virtual NativeUInt __fastcall GetControlHandle(void);
	virtual System::Types::TPoint __fastcall GetClientToScreen(const System::Types::TPoint APoint);
	virtual Cxpc::TcxCustomTabControlHintHelperClass __fastcall GetHintHelperClass(void);
	virtual System::Types::TPoint __fastcall GetScreenToClient(const System::Types::TPoint APoint);
	
public:
	__fastcall virtual TdxTabbedMDITabController(System::TObject* AOwner);
public:
	/* TcxCustomTabControlController.Destroy */ inline __fastcall virtual ~TdxTabbedMDITabController(void) { }
	
};


typedef System::TMetaClass* TdxTabbedMDITabControllerClass;

class DELPHICLASS TdxTabbedMDITabControlViewInfo;
class PASCALIMPLEMENTATION TdxTabbedMDITabControlViewInfo : public Cxpc::TcxCustomTabControlViewInfo
{
	typedef Cxpc::TcxCustomTabControlViewInfo inherited;
	
protected:
	virtual bool __fastcall HasBorders(void);
public:
	/* TcxCustomTabControlViewInfo.Create */ inline __fastcall virtual TdxTabbedMDITabControlViewInfo(System::TObject* AOwner) : Cxpc::TcxCustomTabControlViewInfo(AOwner) { }
	/* TcxCustomTabControlViewInfo.Destroy */ inline __fastcall virtual ~TdxTabbedMDITabControlViewInfo(void) { }
	
};


typedef System::TMetaClass* TdxTabbedMDITabControlViewInfoClass;

class DELPHICLASS TdxTabbedMDIPage;
class DELPHICLASS TdxTabbedMDIManager;
class PASCALIMPLEMENTATION TdxTabbedMDIPage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TIcon* FIcon;
	Vcl::Forms::TForm* FForm;
	System::TObject* FPage;
	Cxpc::TcxTab* FTab;
	TdxTabbedMDIManager* FTabbedMDIManager;
	System::UnicodeString __fastcall GetCaption(void);
	NativeUInt __fastcall GetHandle(void);
	int __fastcall GetImageIndex(void);
	Vcl::Forms::TForm* __fastcall GetMDIChild(void);
	Cxpc::TcxTab* __fastcall GetTab(void);
	System::UnicodeString __fastcall GetTabCaptionFromForm(void);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetImageIndex(const int Value);
	int __fastcall GetIndex(void);
	
protected:
	void __fastcall DoMDIChildCreated(void);
	void __fastcall MDIChildDestroying(void);
	void __fastcall UpdateActiveCaption(void);
	void __fastcall UpdateBounds(void);
	void __fastcall UpdateIcon(void);
	void __fastcall UpdateCaption(void);
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption};
	__property NativeUInt Handle = {read=GetHandle};
	__property int ImageIndex = {read=GetImageIndex, write=SetImageIndex, nodefault};
	__property Cxpc::TcxTab* Tab = {read=GetTab};
	
public:
	__fastcall TdxTabbedMDIPage(TdxTabbedMDIManager* AMDIManager, NativeUInt AMDIChild);
	__fastcall virtual ~TdxTabbedMDIPage(void);
	__property int Index = {read=GetIndex, nodefault};
	__property Vcl::Forms::TForm* MDIChild = {read=GetMDIChild};
};


class DELPHICLASS TdxTabbedMDITabProperties;
class PASCALIMPLEMENTATION TdxTabbedMDITabProperties : public Cxpc::TcxCustomTabControlProperties
{
	typedef Cxpc::TcxCustomTabControlProperties inherited;
	
private:
	bool FFocusable;
	Cxgraphics::TcxImageList* FInternalImages;
	Vcl::Forms::TCloseEvent FOldMDIChildCloseEvent;
	System::Contnrs::TObjectList* FPages;
	TdxTabbedMDIManager* FTabbedMDIManager;
	TdxTabbedMDIPage* __fastcall GetActivePage(void);
	int __fastcall GetPageCount(void);
	TdxTabbedMDIPage* __fastcall GetPage(int AIndex);
	int __fastcall GetPageIndex(void);
	void __fastcall MDIChildClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall SetPageIndex(int AIndex);
	
protected:
	int __fastcall AddPage(NativeUInt AMdiChild);
	void __fastcall ClearPages(void);
	virtual void __fastcall CloseTab(int AIndex);
	void __fastcall DeletePage(int AIndex);
	int __fastcall GetPageIndexByHandle(NativeUInt AHandle);
	virtual Cxpc::_di_IcxTabControl __fastcall GetTabControl(void);
	virtual System::UnicodeString __fastcall InternalGetTabHint(Cxpc::TcxTab* ATab, bool &ACanShow);
	void __fastcall MDIChildDestroying(NativeUInt AHandle);
	virtual void __fastcall MoveTab(int ACurrentIntex, int ANewIndex);
	void __fastcall SetActivePageByHandle(NativeUInt AHandle);
	void __fastcall UpdateImages(void);
	
public:
	__fastcall virtual TdxTabbedMDITabProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxTabbedMDITabProperties(void);
	__property TdxTabbedMDIPage* ActivePage = {read=GetActivePage};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property int PageIndex = {read=GetPageIndex, write=SetPageIndex, nodefault};
	__property TdxTabbedMDIPage* Pages[int AIndex] = {read=GetPage};
	
__published:
	__property AllowTabDragDrop = {default=0};
	__property CloseButtonMode = {default=0};
	__property CloseTabWithMiddleClick = {default=0};
	__property CustomButtons;
	__property bool Focusable = {read=FFocusable, write=FFocusable, default=0};
	__property HideTabs = {default=0};
	__property HotTrack = {default=0};
	__property ImageBorder = {default=0};
	__property RotatedTabsMaxWidth = {default=0};
	__property MultiLine = {default=0};
	__property NavigatorPosition = {default=2};
	__property Options = {default=177};
	__property OwnerDraw = {default=0};
	__property RaggedRight = {default=0};
	__property Rotate = {default=0};
	__property ScrollOpposite = {default=0};
	__property ShowButtonHints = {default=0};
	__property ShowFrame = {default=0};
	__property ShowTabHints = {default=0};
	__property Style = {default=0};
	__property TabCaptionAlignment = {default=2};
	__property TabHeight = {default=0};
	__property TabPosition = {default=0};
	__property TabSlants;
	__property TabsScroll = {default=1};
	__property TabWidth = {default=0};
};


typedef System::TMetaClass* TdxTabbedMDITabPropertiesClass;

typedef void __fastcall (__closure *TdxTabbedMDIPageAddedEvent)(TdxTabbedMDIManager* Sender, TdxTabbedMDIPage* APage);

typedef void __fastcall (__closure *TdxTabbedMDIGetTabHintEvent)(TdxTabbedMDIManager* Sender, TdxTabbedMDIPage* APage, System::UnicodeString &AHint, bool &ACanShow);

class PASCALIMPLEMENTATION TdxTabbedMDIManager : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FActive;
	Vcl::Controls::TCaption FCaption;
	System::UnicodeString FCaptionFormat;
	Cxcontrols::TcxControl* FClientFakeControl;
	NativeUInt FClientHandle;
	Vcl::Forms::TForm* FForm;
	bool FIsClientWndDestroying;
	bool FLoadedActive;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	System::UnicodeString FFormCaptionMask;
	bool FMDIChildsMaximized;
	System::Classes::TList* FMinimizedMDIChilds;
	System::UnicodeString FStoredApplicationTitle;
	int FStoredExStyle;
	TdxTabbedMDITabProperties* FTabProperties;
	Cxcontrols::TcxWindowProcLinkedObject* FWindowProcObject;
	TdxTabbedMDIGetTabHintEvent FOnGetTabHint;
	TdxTabbedMDIPageAddedEvent FOnPageAdded;
	void __fastcall BuildFormatString(void);
	void __fastcall CheckUnique(Vcl::Forms::TForm* AOwner);
	TdxTabbedMDITabController* __fastcall GetController(void);
	System::UnicodeString __fastcall GetFormattedCaption(void);
	Cxpc::_di_IcxTabControl __fastcall GetTabbedControl(void);
	TdxTabbedMDITabControlViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall IsFormCaptionMaskStored(void);
	void __fastcall MainFormWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall SetActive(const bool Value);
	void __fastcall SetFormCaptionMask(const System::UnicodeString Value);
	void __fastcall SetForm(Vcl::Forms::TForm* Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* const Value);
	void __fastcall SetTabProperties(TdxTabbedMDITabProperties* const Value);
	void __fastcall SubscribeClient(void);
	void __fastcall SubscribeForm(void);
	void __fastcall UnSubscribeClient(void);
	void __fastcall UnSubscribeForm(void);
	void __fastcall UpdateCaption(void);
	void __fastcall UpdateScrollBarsArea(void);
	
protected:
	virtual void __fastcall Loaded(void);
	void __fastcall ClientWndDestroyingNotify(void);
	void __fastcall DoPageAdded(TdxTabbedMDIPage* APage);
	void __fastcall LookAndFeelChangeHandler(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall TabPropertiesChangedHandler(System::TObject* Sender, Cxpc::TcxCustomTabControlPropertiesChangedType AType);
	void __fastcall TabPropertiesGetTabHintHandler(System::TObject* Sender, int ATabIndex, System::UnicodeString &AHint, bool &ACanShow);
	void __fastcall TabPropertiesStyleChangedHandler(System::TObject* Sender);
	void __fastcall TabPropertiesTabIndexChangedHandler(System::TObject* Sender);
	virtual TdxTabbedMDITabControllerClass __fastcall GetControllerClass(void);
	virtual TdxTabbedMDITabPropertiesClass __fastcall GetPropertiesClass(void);
	virtual TdxTabbedMDITabControlViewInfoClass __fastcall GetViewInfoClass(void);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	__property NativeUInt ClientHandle = {read=FClientHandle};
	__property Vcl::Forms::TForm* Form = {read=FForm, write=SetForm};
	__property Cxpc::_di_IcxTabControl TabbedControl = {read=GetTabbedControl};
	
public:
	__fastcall virtual TdxTabbedMDIManager(System::Classes::TComponent* Owner);
	__fastcall virtual ~TdxTabbedMDIManager(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(bool AForceUpdate);
	__property TdxTabbedMDITabController* Controller = {read=GetController};
	__property TdxTabbedMDITabControlViewInfo* ViewInfo = {read=GetViewInfo};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel, write=SetLookAndFeel};
	__property System::UnicodeString FormCaptionMask = {read=FFormCaptionMask, write=SetFormCaptionMask, stored=IsFormCaptionMaskStored};
	__property TdxTabbedMDITabProperties* TabProperties = {read=FTabProperties, write=SetTabProperties};
	__property TdxTabbedMDIGetTabHintEvent OnGetTabHint = {read=FOnGetTabHint, write=FOnGetTabHint};
	__property TdxTabbedMDIPageAddedEvent OnPageAdded = {read=FOnPageAdded, write=FOnPageAdded};
private:
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxControlComponentState;	/* Cxcontrols::IcxControlComponentState */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E29BF582-E8C0-4868-A799-DB4C41AC3BC8}
	operator Cxcontrols::_di_IcxControlComponentState()
	{
		Cxcontrols::_di_IcxControlComponentState intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxControlComponentState*(void) { return (Cxcontrols::IcxControlComponentState*)&__IcxControlComponentState; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxtabbedmdi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTABBEDMDI)
using namespace Dxtabbedmdi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxtabbedmdiHPP
