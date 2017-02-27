// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsDesignHelper.pas' rev: 24.00 (Win32)

#ifndef DxskinsdesignhelperHPP
#define DxskinsdesignhelperHPP

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
#include <ToolsAPI.hpp>	// Pascal unit
#include <Vcl.CheckLst.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdesignhelper
{
//-- type declarations -------------------------------------------------------
enum TdxSkinsUnitsState : unsigned char { susDisabled, susEnabled, susUndefined };

class DELPHICLASS TdxSkinsUnitStateListItem;
class DELPHICLASS TdxSkinsUnitStateList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinsUnitStateListItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FName;
	TdxSkinsUnitStateList* FOwner;
	System::UnicodeString FSkinUnitName;
	TdxSkinsUnitsState FState;
	bool __fastcall GetEnabled(void);
	void __fastcall SetState(TdxSkinsUnitsState AState);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall TdxSkinsUnitStateListItem(TdxSkinsUnitStateList* AOwner, const System::UnicodeString ASkinUnitName, const System::UnicodeString AName);
	void __fastcall LoadFromIni(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	void __fastcall SaveToIni(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property System::UnicodeString Name = {read=FName};
	__property TdxSkinsUnitStateList* Owner = {read=FOwner};
	__property System::UnicodeString SkinUnitName = {read=FSkinUnitName};
	__property TdxSkinsUnitsState State = {read=FState, write=SetState, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinsUnitStateListItem(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxSkinsUnitStateList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FList;
	System::Classes::TNotifyEvent FOnChanged;
	int __fastcall GetCount(void);
	bool __fastcall GetHasItemsWithState(TdxSkinsUnitsState AState);
	TdxSkinsUnitStateListItem* __fastcall GetItem(int AIndex);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TdxSkinsUnitStateList(void);
	__fastcall virtual ~TdxSkinsUnitStateList(void);
	TdxSkinsUnitStateListItem* __fastcall AddItem(const System::UnicodeString AUnitName, const System::UnicodeString AName);
	bool __fastcall FindItemByName(const System::UnicodeString AName, TdxSkinsUnitStateListItem* &AItem);
	void __fastcall Clear(void);
	void __fastcall Reset(void);
	void __fastcall LoadSettings(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	void __fastcall SaveSettings(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	__property int Count = {read=GetCount, nodefault};
	__property bool HasDisabledItems = {read=GetHasItemsWithState, index=0, nodefault};
	__property bool HasEnabledItems = {read=GetHasItemsWithState, index=1, nodefault};
	__property bool HasUndefinedItems = {read=GetHasItemsWithState, index=2, nodefault};
	__property TdxSkinsUnitStateListItem* Item[int Index] = {read=GetItem};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
};


class DELPHICLASS TdxSkinsProjectSettings;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinsProjectSettings : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool FCheckDefaultSettingsNeeded;
	bool FEnabled;
	bool FInitialized;
	bool FIsDefaultSettings;
	bool FShowNotification;
	TdxSkinsUnitStateList* FUnitStateList;
	System::UnicodeString __fastcall GetCurrentProjectFileName(void);
	bool __fastcall GetHasDefaultSettings(void);
	bool __fastcall GetIsCurrentProjectExists(void);
	bool __fastcall GetIsDefaultSettings(void);
	bool __fastcall GetNeedShowConfirmation(void);
	System::UnicodeString __fastcall GetSkinsConfigFileName(void);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetShowNotification(bool AValue);
	
protected:
	bool __fastcall CalcIsDefaultSettings(void);
	bool __fastcall CheckDefaultsForUndefinedItems(void);
	System::Win::Registry::TRegistryIniFile* __fastcall CreateRegIniFile(void);
	void __fastcall ActiveProjectChanged(void);
	void __fastcall DoUnitStateListChanged(System::TObject* Sender);
	void __fastcall InternalLoadSettings(System::Inifiles::TCustomIniFile* AConfig, const System::UnicodeString ASection);
	void __fastcall InternalSaveSettings(System::Inifiles::TCustomIniFile* AConfig, const System::UnicodeString ASection);
	void __fastcall SettingsChanged(void);
	void __fastcall PainterChanged(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter);
	
public:
	__fastcall virtual TdxSkinsProjectSettings(void);
	__fastcall virtual ~TdxSkinsProjectSettings(void);
	void __fastcall Finalize(void);
	void __fastcall Initialize(void);
	void __fastcall LoadSettings(void);
	void __fastcall ReloadUnitsList(void);
	void __fastcall SaveSettings(void);
	void __fastcall UpdateActiveProjectSettings(void);
	void __fastcall LoadDefaultSettings(void);
	void __fastcall RemoveDefaultSettings(void);
	void __fastcall SaveDefaultSettings(void);
	__property System::UnicodeString CurrentProjectFileName = {read=GetCurrentProjectFileName};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, nodefault};
	__property bool HasDefaultSettings = {read=GetHasDefaultSettings, nodefault};
	__property bool Initialized = {read=FInitialized, nodefault};
	__property bool IsCurrentProjectExists = {read=GetIsCurrentProjectExists, nodefault};
	__property bool IsDefaultSettings = {read=GetIsDefaultSettings, nodefault};
	__property bool NeedShowConfirmation = {read=GetNeedShowConfirmation, nodefault};
	__property bool ShowNotification = {read=FShowNotification, write=SetShowNotification, nodefault};
	__property System::UnicodeString SkinsConfigFileName = {read=GetSkinsConfigFileName};
	__property TdxSkinsUnitStateList* UnitStateList = {read=FUnitStateList};
private:
	void *__IcxLookAndFeelPainterListener;	/* Cxlookandfeelpainters::IcxLookAndFeelPainterListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {766FE270-2C4B-48B9-C9C7-882A62128A0C}
	operator Cxlookandfeelpainters::_di_IcxLookAndFeelPainterListener()
	{
		Cxlookandfeelpainters::_di_IcxLookAndFeelPainterListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeelpainters::IcxLookAndFeelPainterListener*(void) { return (Cxlookandfeelpainters::IcxLookAndFeelPainterListener*)&__IcxLookAndFeelPainterListener; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxSkinsProjectOptionsMenuExpert;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinsProjectOptionsMenuExpert : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Menus::TMenuItem* FMenuItem;
	Vcl::Menus::TMenuItem* __fastcall GetProjectMenuItem(void);
	void __fastcall DoMenuItemClick(System::TObject* Sender);
	
protected:
	int __fastcall CalcMenuItemPosition(Vcl::Menus::TMenuItem* AParent);
	Vcl::Menus::TMenuItem* __fastcall CreateMenuItem(Vcl::Menus::TMenuItem* AParent);
	Vcl::Menus::TMenuItem* __fastcall FindMenuItemByName(Vcl::Menus::TMenuItem* AParent, const System::UnicodeString AName);
	
public:
	__fastcall virtual TdxSkinsProjectOptionsMenuExpert(void);
	__fastcall virtual ~TdxSkinsProjectOptionsMenuExpert(void);
	__property Vcl::Menus::TMenuItem* MenuItem = {read=FMenuItem};
	__property Vcl::Menus::TMenuItem* ProjectMenuItem = {read=GetProjectMenuItem};
};

#pragma pack(pop)

class DELPHICLASS TdxSkinsDesignHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinsDesignHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Toolsapi::_di_IOTAProject FActiveProject;
	int FActiveProjectNotifierID;
	TdxSkinsProjectOptionsMenuExpert* FMenuExpert;
	int FServicesNotifierID;
	void __fastcall SetActiveProject(Toolsapi::_di_IOTAProject AProject);
	
protected:
	int __fastcall RegisterModuleNotifier(Toolsapi::_di_IOTAModule AModule);
	void __fastcall RegisterIDENotifier(void);
	void __fastcall UnregisterIDENotifier(void);
	void __fastcall UnregisterModuleNotifier(Toolsapi::_di_IOTAModule AModule, int ID);
	void __fastcall UpdateMenuItemState(void);
	bool __fastcall CheckOverwrite(void);
	void __fastcall ModuleRenamed(const System::UnicodeString NewName);
	void __fastcall AfterSave(void);
	void __fastcall BeforeSave(void);
	void __fastcall Destroyed(void);
	void __fastcall Modified(void);
	void __fastcall AfterCompile(bool Succeeded);
	void __fastcall BeforeCompile(const Toolsapi::_di_IOTAProject Project, bool &Cancel);
	void __fastcall FileNotification(Toolsapi::TOTAFileNotification NotifyCode, const System::UnicodeString FileName, bool &Cancel);
	
public:
	__fastcall virtual TdxSkinsDesignHelper(void);
	__fastcall virtual ~TdxSkinsDesignHelper(void);
	__property Toolsapi::_di_IOTAProject ActiveProject = {read=FActiveProject, write=SetActiveProject};
	__property TdxSkinsProjectOptionsMenuExpert* MenuExpert = {read=FMenuExpert};
private:
	void *__IOTAIDENotifier;	/* Toolsapi::IOTAIDENotifier */
	void *__IOTAModuleNotifier;	/* Toolsapi::IOTAModuleNotifier */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E052204F-ECE9-11D1-AB19-00C04FB16FB3}
	operator Toolsapi::_di_IOTAIDENotifier()
	{
		Toolsapi::_di_IOTAIDENotifier intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAIDENotifier*(void) { return (Toolsapi::IOTAIDENotifier*)&__IOTAIDENotifier; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F17A7BCF-E07D-11D1-AB0B-00C04FB16FB3}
	operator Toolsapi::_di_IOTANotifier()
	{
		Toolsapi::_di_IOTANotifier intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTANotifier*(void) { return (Toolsapi::IOTANotifier*)&__IOTAIDENotifier; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F17A7BCE-E07D-11D1-AB0B-00C04FB16FB3}
	operator Toolsapi::_di_IOTAModuleNotifier()
	{
		Toolsapi::_di_IOTAModuleNotifier intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAModuleNotifier*(void) { return (Toolsapi::IOTAModuleNotifier*)&__IOTAModuleNotifier; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxSkinsDesignHelperForm;
class PASCALIMPLEMENTATION TdxSkinsDesignHelperForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* bCancel;
	Vcl::Stdctrls::TButton* bOk;
	Vcl::Stdctrls::TButton* bSelectAll;
	Vcl::Stdctrls::TButton* bSelectNone;
	Vcl::Extctrls::TBevel* bvFrame;
	Vcl::Stdctrls::TCheckBox* cbSkinsAutoFilling;
	Vcl::Extctrls::TBevel* CheckListBoxHolder;
	Vcl::Extctrls::TImage* Image;
	Vcl::Stdctrls::TLabel* lbNotes;
	Vcl::Stdctrls::TLabel* lbSkins;
	Vcl::Extctrls::TPaintBox* pbFrame;
	Vcl::Extctrls::TPanel* plNotes;
	Vcl::Stdctrls::TCheckBox* cbDefault;
	Vcl::Stdctrls::TCheckBox* cbShowNotifications;
	void __fastcall bSelectAllClick(System::TObject* Sender);
	void __fastcall cbSkinsAutoFillingClick(System::TObject* Sender);
	void __fastcall pbFramePaint(System::TObject* Sender);
	void __fastcall cbShowNotificationsClick(System::TObject* Sender);
	
private:
	Vcl::Checklst::TCheckListBox* CheckListBox;
	bool FIsDefaultSettings;
	bool __fastcall GetHasChanges(void);
	void __fastcall ApplySettings(bool ADropToDefault);
	void __fastcall DoCheckListBoxClickCheck(System::TObject* Sender);
	void __fastcall PopulateList(void);
	void __fastcall UpdateDefaultCheckBoxState(void);
	
public:
	__fastcall virtual TdxSkinsDesignHelperForm(System::Classes::TComponent* AOwner);
	__classmethod void __fastcall Execute();
	DYNAMIC bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	__property bool HasChanges = {read=GetHasChanges, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxSkinsDesignHelperForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxSkinsDesignHelperForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxSkinsDesignHelperForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxSkinsProjectSettings* __fastcall dxSkinsProjectSettings(void);
extern PACKAGE void __fastcall dxSkinsShowProjectOptionsDialog(void);
extern PACKAGE bool __fastcall dxSkinsListFilter(const System::UnicodeString ASkinName);
}	/* namespace Dxskinsdesignhelper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDESIGNHELPER)
using namespace Dxskinsdesignhelper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdesignhelperHPP
