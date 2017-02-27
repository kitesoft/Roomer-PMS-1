// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxWizardControlForm.pas' rev: 24.00 (Win32)

#ifndef DxwizardcontrolformHPP
#define DxwizardcontrolformHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxCustomWizardControl.hpp>	// Pascal unit
#include <dxWizardControlViewStyleAero.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxwizardcontrolform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxWizardControlFormHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlFormHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Vcl::Forms::TForm* FForm;
	bool FIsGlassFrameExtended;
	int FGlassFrameTopExtend;
	Dxcustomwizardcontrol::TdxCustomWizardControl* FWizardControl;
	bool __fastcall GetIsDesigning(void);
	Dxcustomwizardcontrol::TdxWizardControlCustomTitleViewInfo* __fastcall GetWizardControlTitleViewInfo(void);
	void __fastcall SetGlassFrameTopExtend(int AValue);
	void __fastcall SetWizardControl(Dxcustomwizardcontrol::TdxCustomWizardControl* AValue);
	
protected:
	virtual bool __fastcall CanExtendGlassFrame(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	void __fastcall NotifyGlassFrameChanged(void);
	virtual bool __fastcall HitAtExtendedCaptionArea(const System::Types::TPoint &AScreenPoint)/* overload */;
	bool __fastcall HitAtExtendedCaptionArea(const System::Types::TSmallPoint AScreenPoint)/* overload */;
	virtual void __fastcall ProcessHitTest(Winapi::Messages::TWMNCHitTest &Message);
	virtual void __fastcall ProcessWindowPosChanging(Winapi::Windows::PWindowPos AWindowPos);
	virtual void __fastcall UpdateGlassFrame(void);
	void __fastcall UpdateViewInfo(void);
	void __fastcall LayoutChanged(void);
	bool __fastcall ProcessChildHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
public:
	__fastcall TdxWizardControlFormHelper(Vcl::Forms::TForm* AForm);
	__fastcall virtual ~TdxWizardControlFormHelper(void);
	void __fastcall UpdateGlassFrameExtends(void);
	__property Vcl::Forms::TForm* Form = {read=FForm};
	__property int GlassFrameTopExtend = {read=FGlassFrameTopExtend, write=SetGlassFrameTopExtend, nodefault};
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property bool IsGlassFrameExtended = {read=FIsGlassFrameExtended, nodefault};
	__property Dxcustomwizardcontrol::TdxCustomWizardControl* WizardControl = {read=FWizardControl, write=SetWizardControl};
	__property Dxcustomwizardcontrol::TdxWizardControlCustomTitleViewInfo* WizardControlTitleViewInfo = {read=GetWizardControlTitleViewInfo};
private:
	void *__IdxWizardControlFormHelper;	/* Dxcustomwizardcontrol::IdxWizardControlFormHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7DA6D67B-F19A-4D53-A6CB-C55EF65245D7}
	operator Dxcustomwizardcontrol::_di_IdxWizardControlFormHelper()
	{
		Dxcustomwizardcontrol::_di_IdxWizardControlFormHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomwizardcontrol::IdxWizardControlFormHelper*(void) { return (Dxcustomwizardcontrol::IdxWizardControlFormHelper*)&__IdxWizardControlFormHelper; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlForm;
class PASCALIMPLEMENTATION TdxWizardControlForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TdxWizardControlFormHelper* FHelper;
	MESSAGE void __fastcall CMControlChange(Vcl::Controls::TCMControlChange &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	
protected:
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &ARect);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall InitializeNewForm(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	virtual void __fastcall PaintWindow(HDC DC);
	virtual void __fastcall SetAutoSize(bool AValue);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property TdxWizardControlFormHelper* Helper = {read=FHelper};
	
public:
	__fastcall virtual TdxWizardControlForm(System::Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TdxWizardControlForm(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxWizardControlForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxWizardControlForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxwizardcontrolform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXWIZARDCONTROLFORM)
using namespace Dxwizardcontrolform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxwizardcontrolformHPP
