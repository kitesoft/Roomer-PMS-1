// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLibraryReg.pas' rev: 24.00 (Win32)

#ifndef CxlibraryregHPP
#define CxlibraryregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignConst.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <cxPropertiesStore.hpp>	// Pascal unit
#include <cxPropertiesStoreEditor.hpp>	// Pascal unit
#include <PicEdit.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxScreenTip.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxStyleRepositoryEditor.hpp>	// Pascal unit
#include <cxImageListEditor.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <dxGallery.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlibraryreg
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (*TdxSkinsRequiresAdditionalUnitsProc)(System::TClass AControlClass, System::Classes::TGetStrProc AProc);

class DELPHICLASS TcxDefaultEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDefaultEditor : public Designeditors::TDefaultEditor
{
	typedef Designeditors::TDefaultEditor inherited;
	
private:
	int __fastcall GetBaseVerbCount(void);
	
protected:
	virtual System::UnicodeString __fastcall GetProductVersion(void);
	virtual System::UnicodeString __fastcall GetProductName(void) = 0 ;
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	
public:
	virtual System::UnicodeString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	/* TComponentEditor.Create */ inline __fastcall virtual TcxDefaultEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TDefaultEditor(AComponent, ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDefaultEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxControlPopupMenuProperty;
class PASCALIMPLEMENTATION TcxControlPopupMenuProperty : public Designeditors::TComponentProperty
{
	typedef Designeditors::TComponentProperty inherited;
	
private:
	System::Classes::TGetStrProc FProc;
	void __fastcall CheckComponent(const System::UnicodeString Value);
	
public:
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxControlPopupMenuProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TComponentProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxControlPopupMenuProperty(void) { }
	
};


class DELPHICLASS TcxBitmapGraphicProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBitmapGraphicProperty : public Picedit::TGraphicProperty
{
	typedef Picedit::TGraphicProperty inherited;
	
private:
	Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(void);
	void __fastcall OnShowPicEdit(System::TObject* Sender);
	void __fastcall SetGraphic(Vcl::Graphics::TGraphic* AGraphic);
	
protected:
	virtual System::UnicodeString __fastcall BuildFilter(void);
	__property Vcl::Graphics::TGraphicClass GraphicClass = {read=GetGraphicClass};
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value)/* overload */;
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxBitmapGraphicProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Picedit::TGraphicProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxBitmapGraphicProperty(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetValue(const System::WideString Value){ Designeditors::TPropertyEditor::SetValue(Value); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSmartImageGraphicProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSmartImageGraphicProperty : public Picedit::TGraphicProperty
{
	typedef Picedit::TGraphicProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxSmartImageGraphicProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Picedit::TGraphicProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxSmartImageGraphicProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxBitmapProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBitmapProperty : public TcxBitmapGraphicProperty
{
	typedef TcxBitmapGraphicProperty inherited;
	
protected:
	virtual System::UnicodeString __fastcall BuildFilter(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxBitmapProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TcxBitmapGraphicProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxBitmapProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxFilenameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilenameProperty : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilter(void);
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxFilenameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxFilenameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxLocalizerFilenameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLocalizerFilenameProperty : public TcxFilenameProperty
{
	typedef TcxFilenameProperty inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFilter(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxLocalizerFilenameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TcxFilenameProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxLocalizerFilenameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryPropertyEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryPropertyEditor : public Designeditors::TPropertyEditor
{
	typedef Designeditors::TPropertyEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxGalleryPropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TPropertyEditor(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxGalleryPropertyEditor(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TMethodParam
{
public:
	System::Typinfo::TParamFlags Flags;
	System::ShortString Name;
	System::ShortString TypeName;
};


//-- var, const, procedure ---------------------------------------------------
#define dxLibraryProductPage L"DevExpress"
#define dxLibraryProductName L"ExpressLibrary"
#define cxLibraryUtilitiesProductPage L"Express Utilities"
extern PACKAGE TdxSkinsRequiresAdditionalUnitsProc FdxSkinsRequiresAdditionalUnits;
extern PACKAGE System::UnicodeString __fastcall BuildcxBitmapPropertyFilter(void);
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall cxGetAsBitmap(Vcl::Graphics::TGraphic* AGraphic);
extern PACKAGE void __fastcall dxSkinsRequiresAdditionalUnits(System::TClass AControlClass, System::Classes::TGetStrProc AProc);
extern PACKAGE void __fastcall ShowEventMethod(Designintf::_di_IDesigner ADesigner, System::TObject* AInstance, const System::UnicodeString AEventName, const System::UnicodeString AMethodName, TMethodParam const *AMethodParams, const int AMethodParams_Size);
extern PACKAGE void __fastcall HideClassProperties(System::TClass AClass, System::UnicodeString *APropertyNames, const int APropertyNames_Size);
extern PACKAGE void __fastcall Register(void);
}	/* namespace Cxlibraryreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLIBRARYREG)
using namespace Cxlibraryreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlibraryregHPP
