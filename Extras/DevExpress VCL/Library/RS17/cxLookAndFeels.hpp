// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLookAndFeels.pas' rev: 24.00 (Win32)

#ifndef CxlookandfeelsHPP
#define CxlookandfeelsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxOffice11.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlookandfeels
{
//-- type declarations -------------------------------------------------------
enum TcxLookAndFeelKind : unsigned char { lfFlat, lfStandard, lfUltraFlat, lfOffice11 };

enum TcxLookAndFeelValue : unsigned char { lfvKind, lfvNativeStyle, lfvSkinName };

typedef System::Set<TcxLookAndFeelValue, TcxLookAndFeelValue::lfvKind, TcxLookAndFeelValue::lfvSkinName>  TcxLookAndFeelValues;

__interface IcxLookAndFeelNotificationListener;
typedef System::DelphiInterface<IcxLookAndFeelNotificationListener> _di_IcxLookAndFeelNotificationListener;
class DELPHICLASS TcxLookAndFeel;
__interface  INTERFACE_UUID("{205538BF-F19E-4285-B11F-B182D9635881}") IcxLookAndFeelNotificationListener  : public System::IInterface 
{
	
public:
	virtual System::TObject* __fastcall GetObject(void) = 0 ;
	virtual void __fastcall MasterLookAndFeelChanged(TcxLookAndFeel* Sender, TcxLookAndFeelValues AChangedValues) = 0 ;
	virtual void __fastcall MasterLookAndFeelDestroying(TcxLookAndFeel* Sender) = 0 ;
};

__interface IcxLookAndFeelNotificationListener2;
typedef System::DelphiInterface<IcxLookAndFeelNotificationListener2> _di_IcxLookAndFeelNotificationListener2;
__interface  INTERFACE_UUID("{392FC2E2-3F2A-4885-B9E6-43982962F475}") IcxLookAndFeelNotificationListener2  : public System::IInterface 
{
	
public:
	virtual void __fastcall MasterLookAndFeelBeginChange(void) = 0 ;
	virtual void __fastcall MasterLookAndFeelEndChange(void) = 0 ;
};

__interface IdxSkinSupport;
typedef System::DelphiInterface<IdxSkinSupport> _di_IdxSkinSupport;
__interface  INTERFACE_UUID("{EF3FF483-9B69-46DF-95A4-D3A3810F63A5}") IdxSkinSupport  : public System::IInterface 
{
	
};

__interface IdxSkinSupport2;
typedef System::DelphiInterface<IdxSkinSupport2> _di_IdxSkinSupport2;
__interface  INTERFACE_UUID("{01C435BA-7DA1-44A4-BE8B-BCE9CE0562AB}") IdxSkinSupport2  : public IdxSkinSupport 
{
	
public:
	virtual bool __fastcall IsSkinnable(void) = 0 ;
};

__interface IcxLookAndFeelContainer;
typedef System::DelphiInterface<IcxLookAndFeelContainer> _di_IcxLookAndFeelContainer;
__interface  INTERFACE_UUID("{6065B58B-C557-4464-A67D-64183FD13F25}") IcxLookAndFeelContainer  : public System::IInterface 
{
	
public:
	virtual TcxLookAndFeel* __fastcall GetLookAndFeel(void) = 0 ;
};

typedef void __fastcall (__closure *TcxLookAndFeelChangedEvent)(TcxLookAndFeel* Sender, TcxLookAndFeelValues AChangedValues);

struct DECLSPEC_DRECORD TcxLookAndFeelData
{
public:
	TcxLookAndFeelKind Kind;
	bool NativeStyle;
	System::UnicodeString SkinName;
	bool UseSkins;
};


class DELPHICLASS TcxSystemPaletteChangedNotifier;
class PASCALIMPLEMENTATION TcxLookAndFeel : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxLookAndFeelValues FAssignedValues;
	TcxLookAndFeelValues FChangedValues;
	Cxclasses::TcxObjectList* FChangeListenerList;
	TcxLookAndFeelData FCurrentState;
	TcxLookAndFeelData FData;
	bool FIsDestruction;
	bool FIsRootLookAndFeel;
	TcxLookAndFeel* FMasterLookAndFeel;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FSkinPainter;
	TcxLookAndFeelData FPrevState;
	TcxSystemPaletteChangedNotifier* FSystemPaletteChangedNotifier;
	int FUpdateLockCount;
	TcxLookAndFeelChangedEvent FOnChanged;
	System::Classes::TNotifyEvent FOnMasterBeginChange;
	System::Classes::TNotifyEvent FOnMasterEndChange;
	Cxlookandfeelpainters::TcxLookAndFeelStyle __fastcall GetActiveStyle(void);
	TcxLookAndFeelKind __fastcall GetKind(void);
	TcxLookAndFeel* __fastcall GetMasterLookAndFeel(void);
	bool __fastcall GetNativeStyle(void);
	Cxclasses::TdxSkinName __fastcall GetSkinName(void);
	void __fastcall SetAssignedValues(TcxLookAndFeelValues Value);
	void __fastcall SetKind(TcxLookAndFeelKind Value);
	void __fastcall SetMasterLookAndFeel(TcxLookAndFeel* Value);
	void __fastcall SetNativeStyle(bool Value);
	void __fastcall SetSkinName(const Cxclasses::TdxSkinName Value);
	void __fastcall CheckStateChanges(void);
	TcxLookAndFeelKind __fastcall GetDefaultKind(void);
	bool __fastcall GetDefaultNativeStyle(void);
	System::UnicodeString __fastcall GetDefaultSkinName(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetDefaultSkinPainter(void);
	bool __fastcall IsKindStored(void);
	bool __fastcall IsNativeStyleStored(void);
	bool __fastcall IsSkinNameStored(void);
	void __fastcall ReadSkinName(System::Classes::TReader* Reader);
	void __fastcall SaveState(void);
	void __fastcall WriteSkinName(System::Classes::TWriter* Writer);
	
protected:
	void __fastcall Changed(TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall DoMasterLookAndFeelChanged(TcxLookAndFeelValues AChangedValues);
	void __fastcall DoMasterLookAndFeelDestroying(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetSkinPainter(const System::UnicodeString ASkinName);
	virtual void __fastcall InitializeCurrentState(void);
	virtual void __fastcall InitializePainter(void);
	virtual TcxLookAndFeelKind __fastcall InternalGetKind(void);
	virtual bool __fastcall InternalGetNativeStyle(void);
	virtual System::UnicodeString __fastcall InternalGetSkinName(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall InternalGetSkinPainter(void);
	void __fastcall NotifyChanged(void);
	virtual void __fastcall SystemPaletteChanged(void);
	System::TObject* __fastcall GetObject(void);
	void __fastcall MasterLookAndFeelBeginChange(void);
	void __fastcall MasterLookAndFeelChanged(TcxLookAndFeel* Sender, TcxLookAndFeelValues AChangedValues);
	void __fastcall MasterLookAndFeelEndChange(void);
	void __fastcall MasterLookAndFeelDestroying(TcxLookAndFeel* Sender);
	__property Cxclasses::TcxObjectList* ChangeListenerList = {read=FChangeListenerList};
	
public:
	__fastcall virtual TcxLookAndFeel(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxLookAndFeel(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetAvailablePainter(Dxthememanager::TdxThemedObjectType ANeededThemedObjectType)/* overload */;
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetAvailablePainter(Dxthememanager::TdxThemedObjectTypes ANeededThemedObjectTypes = Dxthememanager::TdxThemedObjectTypes() )/* overload */;
	void __fastcall Refresh(void);
	void __fastcall Reset(void);
	void __fastcall SetStyle(Cxlookandfeelpainters::TcxLookAndFeelStyle Value);
	void __fastcall AddChangeListener(System::TObject* AListener);
	void __fastcall RemoveChangeListener(System::TObject* AListener);
	__property Cxlookandfeelpainters::TcxLookAndFeelStyle ActiveStyle = {read=GetActiveStyle, nodefault};
	__property TcxLookAndFeel* MasterLookAndFeel = {read=GetMasterLookAndFeel, write=SetMasterLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=FPainter};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* SkinPainter = {read=FSkinPainter, write=FSkinPainter};
	__property TcxLookAndFeelChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	__property System::Classes::TNotifyEvent OnMasterBeginChange = {read=FOnMasterBeginChange, write=FOnMasterBeginChange};
	__property System::Classes::TNotifyEvent OnMasterEndChange = {read=FOnMasterEndChange, write=FOnMasterEndChange};
	
__published:
	__property TcxLookAndFeelValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, stored=false, nodefault};
	__property TcxLookAndFeelKind Kind = {read=GetKind, write=SetKind, stored=IsKindStored, nodefault};
	__property bool NativeStyle = {read=GetNativeStyle, write=SetNativeStyle, stored=IsNativeStyleStored, nodefault};
	__property Cxclasses::TdxSkinName SkinName = {read=GetSkinName, write=SetSkinName, stored=IsSkinNameStored};
private:
	void *__IcxLookAndFeelNotificationListener2;	/* IcxLookAndFeelNotificationListener2 */
	void *__IcxLookAndFeelNotificationListener;	/* IcxLookAndFeelNotificationListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {392FC2E2-3F2A-4885-B9E6-43982962F475}
	operator _di_IcxLookAndFeelNotificationListener2()
	{
		_di_IcxLookAndFeelNotificationListener2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxLookAndFeelNotificationListener2*(void) { return (IcxLookAndFeelNotificationListener2*)&__IcxLookAndFeelNotificationListener2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {205538BF-F19E-4285-B11F-B182D9635881}
	operator _di_IcxLookAndFeelNotificationListener()
	{
		_di_IcxLookAndFeelNotificationListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxLookAndFeelNotificationListener*(void) { return (IcxLookAndFeelNotificationListener*)&__IcxLookAndFeelNotificationListener; }
	#endif
	
};


class DELPHICLASS TcxLookAndFeelController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLookAndFeelController : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	TcxLookAndFeelKind __fastcall GetKind(void);
	bool __fastcall GetNativeStyle(void);
	Cxclasses::TdxSkinName __fastcall GetSkinName(void);
	bool __fastcall GetTouchMode(void);
	bool __fastcall IsSkinNameStored(void);
	void __fastcall SetKind(TcxLookAndFeelKind Value);
	void __fastcall SetNativeStyle(bool Value);
	void __fastcall SetSkinName(const Cxclasses::TdxSkinName Value);
	void __fastcall SetTouchMode(bool Value);
	void __fastcall Modified(void);
	
protected:
	System::TObject* __fastcall GetObject(void);
	virtual void __fastcall MasterLookAndFeelChanged(TcxLookAndFeel* Sender, TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall MasterLookAndFeelDestroying(TcxLookAndFeel* Sender);
	
public:
	__fastcall virtual TcxLookAndFeelController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxLookAndFeelController(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall Reset(void);
	
__published:
	__property TcxLookAndFeelKind Kind = {read=GetKind, write=SetKind, default=2};
	__property bool NativeStyle = {read=GetNativeStyle, write=SetNativeStyle, default=1};
	__property Cxclasses::TdxSkinName SkinName = {read=GetSkinName, write=SetSkinName, stored=IsSkinNameStored};
	__property bool TouchMode = {read=GetTouchMode, write=SetTouchMode, default=0};
private:
	void *__IcxLookAndFeelNotificationListener;	/* IcxLookAndFeelNotificationListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {205538BF-F19E-4285-B11F-B182D9635881}
	operator _di_IcxLookAndFeelNotificationListener()
	{
		_di_IcxLookAndFeelNotificationListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxLookAndFeelNotificationListener*(void) { return (IcxLookAndFeelNotificationListener*)&__IcxLookAndFeelNotificationListener; }
	#endif
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxSystemPaletteChangedEvent)(void);

class PASCALIMPLEMENTATION TcxSystemPaletteChangedNotifier : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsPrimary;
	TcxSystemPaletteChangedEvent FOnSystemPaletteChanged;
	
protected:
	virtual void __fastcall DoChanged(void);
	
public:
	__fastcall virtual TcxSystemPaletteChangedNotifier(bool AIsPrimary);
	__fastcall virtual ~TcxSystemPaletteChangedNotifier(void);
	__property TcxSystemPaletteChangedEvent OnSystemPaletteChanged = {read=FOnSystemPaletteChanged, write=FOnSystemPaletteChanged};
};


typedef bool __fastcall (*TdxClassSupportsSkinProc)(System::Classes::TPersistent* AClass);

//-- var, const, procedure ---------------------------------------------------
static const bool cxDefaultIsTouchModeEnabled = false;
static const TcxLookAndFeelKind cxDefaultLookAndFeelKind = (TcxLookAndFeelKind)(2);
static const bool cxDefaultLookAndFeelNativeStyle = true;
#define cxDefaultLookAndFeelSkinName L""
static const bool cxDefaultUseSkins = true;
extern PACKAGE bool cxIsTouchModeEnabled;
extern PACKAGE bool cxUseSkins;
extern PACKAGE System::StaticArray<TcxLookAndFeelKind, 6> cxLookAndFeelKindMap;
extern PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxLookAndFeelStyle, 4> cxLookAndFeelStyleMap;
extern PACKAGE TdxClassSupportsSkinProc ClassSupportsSkinProc;
extern PACKAGE void __fastcall SetControlLookAndFeel(Vcl::Controls::TControl* AControl, TcxLookAndFeel* AMasterLookAndFeel)/* overload */;
extern PACKAGE void __fastcall SetControlLookAndFeel(Vcl::Controls::TControl* AControl, TcxLookAndFeelKind AKind, bool ANativeStyle)/* overload */;
extern PACKAGE TcxLookAndFeel* __fastcall RootLookAndFeel(void);
}	/* namespace Cxlookandfeels */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLOOKANDFEELS)
using namespace Cxlookandfeels;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlookandfeelsHPP
