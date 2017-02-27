// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSForm.pas' rev: 24.00 (Win32)

#ifndef DxpsformHPP
#define DxpsformHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsform
{
//-- type declarations -------------------------------------------------------
enum TdxPSFormOption : unsigned char { foSizeableDialog };

typedef System::Set<TdxPSFormOption, TdxPSFormOption::foSizeableDialog, TdxPSFormOption::foSizeableDialog>  TdxPSFormOptions;

typedef System::TMetaClass* TdxPSFormClass;

class DELPHICLASS TCustomdxPSForm;
class PASCALIMPLEMENTATION TCustomdxPSForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TdxPSFormOptions FOptions;
	System::Uitypes::TColor __fastcall GetGripperBackgroundColor(void);
	System::Types::TRect __fastcall GetGripperBounds(void);
	bool __fastcall GetIsSizeableDialog(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	HIDESBASE MESSAGE void __fastcall WMNCCreate(Winapi::Messages::TWMNCCreate &message);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Winapi::Messages::TWMNCCreate &message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &message);
	
protected:
	virtual void __fastcall BeforeConstruction(void);
	virtual bool __fastcall IsFormSizeable(void);
	bool __fastcall PtInGripperBounds(const System::Types::TPoint &Pt);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall LoadDefaultSettings(void);
	DYNAMIC void __fastcall Paint(void);
	void __fastcall SaveDefaultSettings(void);
	void __fastcall SetupHelpEventHandler(void);
	__property System::Uitypes::TColor GripperBackgroundColor = {read=GetGripperBackgroundColor, nodefault};
	__property System::Types::TRect GripperBounds = {read=GetGripperBounds};
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall LoadFromRegistry(const System::UnicodeString APath);
	void __fastcall SaveToRegistry(const System::UnicodeString APath);
	__property bool IsSizeableDialog = {read=GetIsSizeableDialog, nodefault};
	__property TdxPSFormOptions Options = {read=FOptions, write=FOptions, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TCustomdxPSForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCustomdxPSForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCustomdxPSForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomdxPSForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall dxPSFormGetActualSectionName(Vcl::Forms::TCustomForm* AForm, const System::UnicodeString ABaseSection = System::UnicodeString());
extern PACKAGE bool __fastcall dxPSFormLoadPositionFromIniFile(Vcl::Forms::TCustomForm* AForm, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName, bool AIsFormSizeable = true);
extern PACKAGE void __fastcall dxPSFormSavePositionToIniFile(Vcl::Forms::TCustomForm* AForm, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName, bool AIsFormSizeable = true);
}	/* namespace Dxpsform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFORM)
using namespace Dxpsform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsformHPP
