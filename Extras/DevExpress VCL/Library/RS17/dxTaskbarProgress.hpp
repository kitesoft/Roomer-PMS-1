// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxTaskbarProgress.pas' rev: 24.00 (Win32)

#ifndef DxtaskbarprogressHPP
#define DxtaskbarprogressHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.ShlObj.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <System.Win.ComObj.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <Vcl.AppEvnts.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxProgressBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxtaskbarprogress
{
//-- type declarations -------------------------------------------------------
enum TdxTaskbarProgressState : unsigned char { tbpsNoProgress, tbpsIndeterminate, tbpsNormal, tbpsError, tbpsPaused };

class DELPHICLASS TdxTaskbarCustomProgress;
class PASCALIMPLEMENTATION TdxTaskbarCustomProgress : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FActive;
	System::Classes::TComponent* FLinkedComponent;
	bool FIsLinkedComponentChangeLocked;
	Cxprogressbar::TcxProgressBarListener* FListener;
	bool FLoadedActive;
	System::Classes::TComponent* FLoadedLinkedComponent;
	__int64 FPosition;
	TdxTaskbarProgressState FState;
	__int64 FTotal;
	bool __fastcall IsTotalStored(void);
	Cxprogressbar::TcxCustomProgressBar* __fastcall GetProgressBar(void);
	Cxprogressbar::TcxCustomProgressBarProperties* __fastcall GetProgressBarProperties(void);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetLinkedComponent(System::Classes::TComponent* AValue);
	void __fastcall SetPosition(__int64 AValue);
	void __fastcall SetState(TdxTaskbarProgressState AValue);
	void __fastcall SetTotal(__int64 AValue);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall CheckUnique(void);
	void __fastcall CreateListener(void);
	void __fastcall DoLinkedComponentChanged(System::TObject* ASender);
	bool __fastcall IsActive(void);
	bool __fastcall IsComponentLinked(void);
	void __fastcall Refresh(void);
	void __fastcall RefreshPosition(void);
	void __fastcall RefreshState(void);
	void __fastcall RemoveListener(void);
	void __fastcall Reset(void);
	void __fastcall SynchronizeAndRefresh(void);
	void __fastcall SynchronizeLinkedComponent(void);
	
public:
	__fastcall virtual TdxTaskbarCustomProgress(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxTaskbarCustomProgress(void);
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property System::Classes::TComponent* LinkedComponent = {read=FLinkedComponent, write=SetLinkedComponent};
	__property __int64 Position = {read=FPosition, write=SetPosition};
	__property TdxTaskbarProgressState State = {read=FState, write=SetState, default=2};
	__property __int64 Total = {read=FTotal, write=SetTotal, stored=IsTotalStored};
};


class DELPHICLASS TdxTaskbarProgress;
class PASCALIMPLEMENTATION TdxTaskbarProgress : public TdxTaskbarCustomProgress
{
	typedef TdxTaskbarCustomProgress inherited;
	
__published:
	__property Active = {default=0};
	__property LinkedComponent;
	__property Position;
	__property State = {default=2};
	__property Total;
public:
	/* TdxTaskbarCustomProgress.Create */ inline __fastcall virtual TdxTaskbarProgress(System::Classes::TComponent* AOwner) : TdxTaskbarCustomProgress(AOwner) { }
	/* TdxTaskbarCustomProgress.Destroy */ inline __fastcall virtual ~TdxTaskbarProgress(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxtaskbarprogress */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTASKBARPROGRESS)
using namespace Dxtaskbarprogress;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxtaskbarprogressHPP
