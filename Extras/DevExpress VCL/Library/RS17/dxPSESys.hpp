// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSESys.pas' rev: 24.00 (Win32)

#ifndef DxpsesysHPP
#define DxpsesysHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsesys
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxEventClass;

class DELPHICLASS TdxPSEventSystem;
class DELPHICLASS TdxEventSubscriber;
class DELPHICLASS TdxEvent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSEventSystem : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
private:
	Dxbase::TdxClassList* FEventClasses;
	System::Classes::TList* FSubscribers;
	TdxEventClass __fastcall GetEventClass(int Index);
	int __fastcall GetEventCount(void);
	TdxEventSubscriber* __fastcall GetSubscriber(int Index);
	int __fastcall GetSubscriberCount(void);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	void __fastcall MoveSubscriber(int ACurIndex, int ANewIndex);
	
public:
	__classmethod TdxPSEventSystem* __fastcall Instance()/* overload */;
	void __fastcall ProcessEvent(TdxEvent* &AEvent);
	int __fastcall IndexOfEventClass(TdxEventClass AEventClass);
	void __fastcall RegisterEventClass(TdxEventClass AEventClass);
	void __fastcall UnregisterEventClass(TdxEventClass AEventClass);
	int __fastcall IndexOfSubscriber(TdxEventSubscriber* ASubscriber);
	void __fastcall RegisterSubscriber(TdxEventSubscriber* ASubscriber);
	void __fastcall UnregisterSubscriber(TdxEventSubscriber* ASubscriber);
	__property TdxEventClass EventClasses[int Index] = {read=GetEventClass};
	__property int EventCount = {read=GetEventCount, nodefault};
	__property int SubscriberCount = {read=GetSubscriberCount, nodefault};
	__property TdxEventSubscriber* Subscribers[int Index] = {read=GetSubscriber};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSEventSystem(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSEventSystem(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSEventSystem(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxEventSubscriber : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxEvent* FActiveEvent;
	bool FEnabled;
	Dxbase::TdxClassList* FEventClasses;
	bool FRegistered;
	TdxEventClass __fastcall GetEventClass(int Index);
	int __fastcall GetEventCount(void);
	int __fastcall GetIndex(void);
	void __fastcall SetIndex(int Value);
	void __fastcall SetRegistered(bool Value);
	void __fastcall ProcessEvent(TdxEvent* AEvent);
	
protected:
	virtual void __fastcall DoProcessEvent(void) = 0 ;
	
public:
	__fastcall TdxEventSubscriber(TdxEventClass const *AEventClasses, const int AEventClasses_Size);
	__fastcall virtual ~TdxEventSubscriber(void);
	void __fastcall Add(TdxEventClass AEventClass);
	void __fastcall Remove(TdxEventClass AEventClass);
	bool __fastcall SupportsEventClass(TdxEventClass AEventClass);
	__property TdxEvent* ActiveEvent = {read=FActiveEvent};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property TdxEventClass EventClasses[int Index] = {read=GetEventClass};
	__property int EventCount = {read=GetEventCount, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property bool Registered = {read=FRegistered, write=SetRegistered, default=1};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxEvent : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FBreak;
	bool FRegistered;
	System::TObject* FSender;
	void __fastcall SetRegistered(bool Value);
	
public:
	__fastcall TdxEvent(System::TObject* ASender);
	TdxEventClass __fastcall EventClass(void);
	__property bool Break = {read=FBreak, write=FBreak, nodefault};
	__property bool Registered = {read=FRegistered, write=SetRegistered, nodefault};
	__property System::TObject* Sender = {read=FSender};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxEvent(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxPSEventSystem* __fastcall dxPSEventSystem(void);
extern PACKAGE void __fastcall dxPSProcessEvent(TdxEvent* &AEvent);
}	/* namespace Dxpsesys */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSESYS)
using namespace Dxpsesys;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsesysHPP
