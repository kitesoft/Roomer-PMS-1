// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxOI.pas' rev: 24.00 (Win32)

#ifndef CxoiHPP
#define CxoiHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <System.RTLConsts.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxoi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxComponentList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxComponentList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Classes::TPersistent* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FList;
	System::Classes::TPersistent* __fastcall GetItem(int Index);
	int __fastcall GetCount(void);
	
public:
	__fastcall TcxComponentList(void);
	__fastcall virtual ~TcxComponentList(void);
	int __fastcall Add(System::Classes::TPersistent* Item);
	HIDESBASE bool __fastcall Equals(TcxComponentList* List);
	__property int Count = {read=GetCount, nodefault};
	__property System::Classes::TPersistent* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

enum TcxPropertyAttribute : unsigned char { ipaValueList, ipaSubProperties, ipaDialog, ipaMultiSelect, ipaAutoUpdate, ipaSortList, ipaReadOnly, ipaRevertable };

typedef System::Set<TcxPropertyAttribute, TcxPropertyAttribute::ipaValueList, TcxPropertyAttribute::ipaRevertable>  TcxPropertyAttributes;

struct DECLSPEC_DRECORD TcxInstProp
{
public:
	System::Classes::TPersistent* Instance;
	System::Typinfo::TPropInfo *PropInfo;
};


typedef System::StaticArray<TcxInstProp, 1024> TcxInstPropList;

typedef TcxInstPropList *PcxInstPropList;

class DELPHICLASS TcxPropertyEditor;
typedef void __fastcall (__closure *TcxGetPropEditProc)(TcxPropertyEditor* APropertyEditor);

class DELPHICLASS TcxCustomRTTIInspector;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPropertyEditor : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomRTTIInspector* FInspector;
	System::Classes::TList* FAncestorList;
	int FPropCount;
	TcxInstPropList *FPropList;
	System::Classes::TComponent* FOwner;
	System::Classes::TComponent* FRoot;
	System::Classes::TPersistent* FAncestor;
	System::Classes::TComponent* FRootAncestor;
	System::Classes::TComponent* FLookingFor;
	bool FDoneLooking;
	void __fastcall AddAncestor(System::Classes::TComponent* Component);
	void __fastcall GetLookupInfo(System::Classes::TPersistent* &Ancestor, System::Classes::TComponent* &Root, System::Classes::TComponent* &LookupRoot, System::Classes::TComponent* &RootAncestor);
	void __fastcall SetPropEntry(int Index, System::Classes::TPersistent* AInstance, System::Typinfo::PPropInfo APropInfo);
	void __fastcall WriteComponentSimulation(System::Classes::TComponent* Component);
	
protected:
	virtual void __fastcall AdjustInnerEditProperties(Cxedit::TcxCustomEditProperties* AProperties);
	System::Extended __fastcall GetFloatValue(void);
	System::Extended __fastcall GetFloatValueAt(int Index);
	__int64 __fastcall GetInt64Value(void);
	__int64 __fastcall GetInt64ValueAt(int Index);
	NativeInt __fastcall GetOrdValue(void);
	NativeInt __fastcall GetOrdValueAt(int Index);
	System::Typinfo::PPropInfo __fastcall GetPropInfo(void);
	System::UnicodeString __fastcall GetStrValue(void);
	System::UnicodeString __fastcall GetStrValueAt(int Index);
	System::Variant __fastcall GetVarValue(void);
	System::Variant __fastcall GetVarValueAt(int Index);
	System::Classes::TComponent* __fastcall FindRoot(void);
	void __fastcall PostChangedNotification(void);
	void __fastcall SetFloatValue(System::Extended Value);
	void __fastcall SetInt64Value(__int64 Value);
	void __fastcall SetOrdValue(const NativeInt Value);
	void __fastcall SetStrValue(const System::UnicodeString Value);
	void __fastcall SetVarValue(const System::Variant &Value);
	__property TcxCustomRTTIInspector* Inspector = {read=FInspector};
	__property PcxInstPropList PropList = {read=FPropList};
	
public:
	__fastcall TcxPropertyEditor(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount);
	__fastcall virtual ~TcxPropertyEditor(void);
	virtual bool __fastcall AllEqual(void);
	virtual bool __fastcall AutoFill(void);
	virtual void __fastcall Edit(void);
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	System::Classes::TPersistent* __fastcall GetComponent(int Index);
	virtual int __fastcall GetEditLimit(void);
	virtual System::UnicodeString __fastcall GetName(void);
	virtual void __fastcall GetProperties(System::Classes::TComponent* AOwner, TcxGetPropEditProc Proc);
	System::Typinfo::PTypeInfo __fastcall GetPropType(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
	virtual bool __fastcall IsDefaultValue(void);
	bool __fastcall ValueAvailable(void);
	__property int PropCount = {read=FPropCount, nodefault};
	__property System::UnicodeString Value = {read=GetValue, write=SetValue};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxPropertyEditorClass;

class DELPHICLASS TcxOrdinalProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxOrdinalProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual int __fastcall GetEditLimit(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxOrdinalProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxOrdinalProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxIntegerProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxIntegerProperty : public TcxOrdinalProperty
{
	typedef TcxOrdinalProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxIntegerProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxOrdinalProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxIntegerProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCharProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCharProperty : public TcxOrdinalProperty
{
	typedef TcxOrdinalProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxCharProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxOrdinalProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxCharProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEnumProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEnumProperty : public TcxOrdinalProperty
{
	typedef TcxOrdinalProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxEnumProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxOrdinalProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxEnumProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxBoolProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBoolProperty _DEPRECATED_ATTRIBUTE0  : public TcxEnumProperty
{
	typedef TcxEnumProperty inherited;
	
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxBoolProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxEnumProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxBoolProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxFloatProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFloatProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxFloatProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxFloatProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxInt64Property;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInt64Property : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual int __fastcall GetEditLimit(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxInt64Property(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxInt64Property(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStringProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStringProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual int __fastcall GetEditLimit(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxStringProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxStringProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSetElementProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSetElementProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
private:
	int FElement;
	
protected:
	__fastcall TcxSetElementProperty(PcxInstPropList APropList, int APropCount, int AElement);
	__property int Element = {read=FElement, nodefault};
	
public:
	__fastcall virtual ~TcxSetElementProperty(void);
	virtual bool __fastcall AllEqual(void);
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetName(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
	virtual bool __fastcall IsDefaultValue(void);
};

#pragma pack(pop)

class DELPHICLASS TcxSetProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSetProperty : public TcxOrdinalProperty
{
	typedef TcxOrdinalProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(System::Classes::TComponent* AOwner, TcxGetPropEditProc Proc);
	virtual System::UnicodeString __fastcall GetValue(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxSetProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxOrdinalProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxSetProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxClassProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxClassProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(System::Classes::TComponent* AOwner, TcxGetPropEditProc Proc);
	virtual System::UnicodeString __fastcall GetValue(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxClassProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxClassProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxComponentProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxComponentProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
private:
	System::UnicodeString __fastcall GetFullName(System::Classes::TComponent* AComponent);
	
protected:
	virtual System::Classes::TComponent* __fastcall GetComponentReference(void);
	virtual bool __fastcall IsValidComponent(System::Classes::TComponent* AComponent);
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(System::Classes::TComponent* AOwner, TcxGetPropEditProc Proc);
	virtual int __fastcall GetEditLimit(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxComponentProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxComponentProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxComponentNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxComponentNameProperty : public TcxStringProperty
{
	typedef TcxStringProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual int __fastcall GetEditLimit(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxComponentNameProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxStringProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxComponentNameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxFontNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFontNameProperty : public TcxStringProperty
{
	typedef TcxStringProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxFontNameProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxStringProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxFontNameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxFontCharsetProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFontCharsetProperty : public TcxIntegerProperty
{
	typedef TcxIntegerProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxFontCharsetProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxIntegerProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxFontCharsetProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxImeNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImeNameProperty : public TcxStringProperty
{
	typedef TcxStringProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxImeNameProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxStringProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxImeNameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxColorProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxColorProperty : public TcxIntegerProperty
{
	typedef TcxIntegerProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxColorProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxIntegerProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxColorProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCursorProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCursorProperty : public TcxIntegerProperty
{
	typedef TcxIntegerProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxCursorProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxIntegerProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxCursorProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxFontProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFontProperty : public TcxClassProperty
{
	typedef TcxClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxFontProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxClassProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxFontProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStringsProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStringsProperty : public TcxClassProperty
{
	typedef TcxClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxStringsProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxClassProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxStringsProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGraphicProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGraphicProperty : public TcxClassProperty
{
	typedef TcxClassProperty inherited;
	
private:
	bool __fastcall HasGraphic(void);
	
protected:
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(void);
	virtual void __fastcall SetGraphic(Vcl::Graphics::TGraphic* Value);
	virtual System::Word __fastcall GetClipboardFormat(void);
	virtual System::UnicodeString __fastcall GetGraphicFilter(void);
	Vcl::Graphics::TGraphicClass __fastcall GraphicClass(void);
	
public:
	virtual void __fastcall Edit(void);
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxGraphicProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxClassProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxGraphicProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPictureProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPictureProperty : public TcxGraphicProperty
{
	typedef TcxGraphicProperty inherited;
	
protected:
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(void);
	virtual void __fastcall SetGraphic(Vcl::Graphics::TGraphic* Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxPictureProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxGraphicProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxPictureProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxModalResultProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxModalResultProperty : public TcxIntegerProperty
{
	typedef TcxIntegerProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxModalResultProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxIntegerProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxModalResultProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxShortCutProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxShortCutProperty : public TcxOrdinalProperty
{
	typedef TcxOrdinalProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxShortCutProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxOrdinalProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxShortCutProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxMPFilenameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMPFilenameProperty : public TcxStringProperty
{
	typedef TcxStringProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxMPFilenameProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxStringProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxMPFilenameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTabOrderProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTabOrderProperty : public TcxIntegerProperty
{
	typedef TcxIntegerProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxTabOrderProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxIntegerProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxTabOrderProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCaptionProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCaptionProperty : public TcxStringProperty
{
	typedef TcxStringProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxCaptionProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxStringProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxCaptionProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDateProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDateProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxDateProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxDateProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTimeProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTimeProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxTimeProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxTimeProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDateTimeProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDateTimeProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxDateTimeProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxDateTimeProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVariantProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVariantProperty : public TcxPropertyEditor
{
	typedef TcxPropertyEditor inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(System::Classes::TComponent* AOwner, TcxGetPropEditProc Proc);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxVariantProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxPropertyEditor(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxVariantProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditPropertiesProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditPropertiesProperty : public TcxClassProperty
{
	typedef TcxClassProperty inherited;
	
protected:
	virtual bool __fastcall HasSubProperties(void);
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxEditPropertiesProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxClassProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxEditPropertiesProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSkinNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSkinNameProperty : public TcxStringProperty
{
	typedef TcxStringProperty inherited;
	
public:
	virtual TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxSkinNameProperty(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, int APropCount) : TcxStringProperty(AOwner, AInspector, APropCount) { }
	/* TcxPropertyEditor.Destroy */ inline __fastcall virtual ~TcxSkinNameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS EcxPropertyError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxPropertyError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxPropertyError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxPropertyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxPropertyError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxPropertyError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxPropertyError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxPropertyError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxPropertyError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxPropertyError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxPropertyError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxPropertyError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxPropertyError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxPropertyError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxPropertyError(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPropertyRow;
class PASCALIMPLEMENTATION TcxPropertyRow : public Cxvgrid::TcxEditorRow
{
	typedef Cxvgrid::TcxEditorRow inherited;
	
private:
	bool FIsDefaultValue;
	TcxPropertyEditor* FPropertyEditor;
	
public:
	__property bool IsDefaultValue = {read=FIsDefaultValue, nodefault};
	__property TcxPropertyEditor* PropertyEditor = {read=FPropertyEditor};
public:
	/* TcxCustomRow.Create */ inline __fastcall virtual TcxPropertyRow(System::Classes::TComponent* AOwner) : Cxvgrid::TcxEditorRow(AOwner) { }
	/* TcxCustomRow.Destroy */ inline __fastcall virtual ~TcxPropertyRow(void) { }
	
};


class DELPHICLASS TcxRTTIInspectorEditingController;
class DELPHICLASS TcxRTTIInspectorController;
class PASCALIMPLEMENTATION TcxRTTIInspectorEditingController : public Cxinplacecontainer::TcxEditingController
{
	typedef Cxinplacecontainer::TcxEditingController inherited;
	
private:
	bool FDeactivating;
	TcxRTTIInspectorController* __fastcall GetController(void);
	TcxCustomRTTIInspector* __fastcall GetInspector(void);
	
protected:
	virtual void __fastcall DoHideEdit(bool Accept);
	__property TcxRTTIInspectorController* Controller = {read=GetController};
	__property bool Deactivating = {read=FDeactivating, nodefault};
	__property TcxCustomRTTIInspector* Inspector = {read=GetInspector};
public:
	/* TcxEditingController.Create */ inline __fastcall virtual TcxRTTIInspectorEditingController(Cxinplacecontainer::TcxCustomControlController* AController) : Cxinplacecontainer::TcxEditingController(AController) { }
	
public:
	/* TcxCustomEditingController.Destroy */ inline __fastcall virtual ~TcxRTTIInspectorEditingController(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRTTIInspectorController : public Cxvgrid::TcxvgController
{
	typedef Cxvgrid::TcxvgController inherited;
	
private:
	bool FFocusChanging;
	bool FNeedValidate;
	TcxRTTIInspectorEditingController* __fastcall GetEditingController(void);
	TcxCustomRTTIInspector* __fastcall GetInspector(void);
	int __fastcall GetRowAbsoluteIndex(Cxvgrid::TcxCustomRow* ARow);
	int __fastcall GetRowAbsoluteIndexFromCellEdit(Cxinplacecontainer::TcxCustomInplaceEditContainer* Value);
	System::UnicodeString __fastcall GetRowPropertyPathFromCellEdit(Cxinplacecontainer::TcxCustomInplaceEditContainer* Value);
	
protected:
	virtual void __fastcall BeforeEditKeyDown(System::Word &Key, System::Classes::TShiftState &Shift);
	virtual void __fastcall DoEditDblClick(System::TObject* Sender);
	virtual void __fastcall DoUpdateRowAndCell(Cxvgrid::TcxCustomRow* ANewRow, int ANewCellIndex);
	virtual void __fastcall FocusChanged(void);
	virtual bool __fastcall IsKeyForController(System::Word AKey, System::Classes::TShiftState AShift);
	void __fastcall PostValidateFocusedItem(void);
	virtual void __fastcall SetFocusedItem(Cxinplacecontainer::TcxCustomInplaceEditContainer* Value);
	virtual void __fastcall SetFocusedRowAndCell(Cxvgrid::TcxCustomRow* Value, int ACellIndex);
	void __fastcall ValidateFocusingItem(Cxinplacecontainer::TcxCustomInplaceEditContainer* &AItem);
	
public:
	virtual void __fastcall SetFocusedRecordItem(NativeInt ARecordIndex, Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	__property TcxRTTIInspectorEditingController* EditingController = {read=GetEditingController};
	__property TcxCustomRTTIInspector* Inspector = {read=GetInspector};
public:
	/* TcxvgController.Create */ inline __fastcall virtual TcxRTTIInspectorController(Cxinplacecontainer::TcxEditingControl* AOwner) : Cxvgrid::TcxvgController(AOwner) { }
	/* TcxvgController.Destroy */ inline __fastcall virtual ~TcxRTTIInspectorController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRTTIInspectorOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRTTIInspectorOptionsView : public Cxvgrid::TcxvgOptionsView
{
	typedef Cxvgrid::TcxvgOptionsView inherited;
	
private:
	bool FShowReadOnlyProperties;
	bool FSorted;
	void __fastcall SetSorted(const bool Value);
	void __fastcall SetShowReadOnlyProperties(const bool Value);
	TcxCustomRTTIInspector* __fastcall GetInspector(void);
	
protected:
	virtual Cxvgrid::TcxvgPaintStyle __fastcall GetDefaultPaintStyle(void);
	virtual Cxinplacecontainer::TcxEditingControlEditShowButtons __fastcall GetDefaultShowEditButtons(void);
	
public:
	__fastcall virtual TcxRTTIInspectorOptionsView(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomRTTIInspector* Inspector = {read=GetInspector};
	
__published:
	__property bool ShowReadOnlyProperties = {read=FShowReadOnlyProperties, write=SetShowReadOnlyProperties, default=0};
	__property bool Sorted = {read=FSorted, write=SetSorted, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxRTTIInspectorOptionsView(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRTTIInspectorOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRTTIInspectorOptionsBehavior : public Cxvgrid::TcxvgOptionsBehavior
{
	typedef Cxvgrid::TcxvgOptionsBehavior inherited;
	
public:
	__fastcall virtual TcxRTTIInspectorOptionsBehavior(System::Classes::TPersistent* AOwner);
	
__published:
	__property AlwaysShowEditor = {default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxRTTIInspectorOptionsBehavior(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRTTIInspectorStyles;
class PASCALIMPLEMENTATION TcxRTTIInspectorStyles : public Cxvgrid::TcxVerticalGridStyles
{
	typedef Cxvgrid::TcxVerticalGridStyles inherited;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
public:
	/* TcxVerticalGridStyles.Create */ inline __fastcall virtual TcxRTTIInspectorStyles(System::Classes::TPersistent* AOwner) : Cxvgrid::TcxVerticalGridStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxRTTIInspectorStyles(void) { }
	
};


__interface IcxRTTIInspectorHelper;
typedef System::DelphiInterface<IcxRTTIInspectorHelper> _di_IcxRTTIInspectorHelper;
__interface  INTERFACE_UUID("{EA7182FA-139D-4525-9C5F-4D8BBAB5FEEE}") IcxRTTIInspectorHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall CloseNonModal(TcxCustomRTTIInspector* AInspector) = 0 ;
	virtual void __fastcall PropertyChanged(TcxCustomRTTIInspector* AInspector) = 0 ;
};

typedef void __fastcall (__closure *TcxFilterPropertyEvent)(System::TObject* Sender, const System::UnicodeString PropertyName, bool &Accept);

class PASCALIMPLEMENTATION TcxCustomRTTIInspector : public Cxvgrid::TcxUnboundVerticalGrid
{
	typedef Cxvgrid::TcxUnboundVerticalGrid inherited;
	
private:
	Vcl::Graphics::TFont* FBoldFont;
	TcxPropertyRow* FCurrentRow;
	System::Classes::TList* FListeners;
	bool FLockRefresh;
	int FInspectedLevel;
	System::Classes::TPersistent* FInspectedObject;
	Cxvgrid::TcxCustomRow* FParentRow;
	bool FSettingValue;
	TcxFilterPropertyEvent FOnFilterProperty;
	TcxFilterPropertyEvent FOnFilterPropertyEx;
	System::Classes::TNotifyEvent FOnPropertyChanged;
	bool __fastcall CanInvokePropertyEditorDlg(void);
	MESSAGE void __fastcall CNPropertyChanged(tagMSG &AMessage);
	void __fastcall CreatePropertyRows(System::Classes::TPersistent* AOldInspectedObject);
	void __fastcall CreateRows(TcxPropertyEditor* APropertyEditor);
	void __fastcall GetComponentsProperties(System::Classes::TPersistent* const *AInstances, const int AInstances_Size);
	HIDESBASE TcxRTTIInspectorController* __fastcall GetController(void);
	HIDESBASE TcxRTTIInspectorOptionsView* __fastcall GetOptionsView(void);
	TcxPropertyEditor* __fastcall GetPropertyEditor(void);
	void __fastcall GetStrProc(const System::UnicodeString S);
	void __fastcall ReleaseComponentProperties(void);
	void __fastcall RowButtonClick(System::TObject* Sender, int AbsoluteIndex);
	void __fastcall SetInspectedObject(System::Classes::TPersistent* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxRTTIInspectorOptionsView* const Value);
	void __fastcall TryInvokePropertyEditorDlg(void);
	bool __fastcall TrySetValue(Cxedit::TcxCustomEdit* AEdit, bool AUseText);
	
protected:
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall InternalMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall IsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	virtual void __fastcall DataChanged(void);
	void __fastcall DoPropertyChanged(void);
	void __fastcall EditChange(System::TObject* Sender);
	void __fastcall EditValueChanged(System::TObject* Sender);
	virtual Cxinplacecontainer::TcxCustomControlControllerClass __fastcall GetControllerClass(void);
	virtual Cxinplacecontainer::TcxCustomControlStylesClass __fastcall GetControlStylesClass(void);
	virtual Cxinplacecontainer::TcxEditingControllerClass __fastcall GetEditingControllerClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall BeginLevel(void);
	void __fastcall EndLevel(void);
	virtual bool __fastcall FilterProperty(const System::UnicodeString APropertyName);
	virtual bool __fastcall FilterPropertyEx(const System::UnicodeString AFullPropertyName);
	TcxPropertyRow* __fastcall FindRowByPropertyName(const System::UnicodeString APropertyName);
	TcxPropertyRow* __fastcall FindRowByPropertyPath(System::UnicodeString APropertyPath, bool AExactMatch);
	void __fastcall FocusRowByPropertyName(const System::UnicodeString APropertyName);
	void __fastcall FocusRowByPropertyPath(System::UnicodeString APropertyPath);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass(TcxPropertyEditor* APropertyEditor);
	System::UnicodeString __fastcall GetRowPropertyPath(Cxvgrid::TcxCustomRow* ARow);
	void __fastcall PostChangedNotification(void);
	virtual void __fastcall PrepareEditProperties(Cxedit::TcxCustomEditProperties* AProperties, TcxPropertyEditor* APropertyEditor);
	bool __fastcall Sorted(void);
	__property TcxRTTIInspectorController* Controller = {read=GetController};
	__property int InspectedLevel = {read=FInspectedLevel, nodefault};
	__property bool LockRefresh = {read=FLockRefresh, nodefault};
	__property TcxPropertyEditor* PropertyEditor = {read=GetPropertyEditor};
	
public:
	__fastcall virtual TcxCustomRTTIInspector(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomRTTIInspector(void);
	void __fastcall AddListener(System::Classes::TPersistent* AListener);
	void __fastcall CloseNonModalEditors(void);
	void __fastcall RefreshInspectedProperties(void);
	void __fastcall RemoveListener(System::Classes::TPersistent* AListener);
	__property TcxRTTIInspectorOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property System::Classes::TPersistent* InspectedObject = {read=FInspectedObject, write=SetInspectedObject};
	__property TcxFilterPropertyEvent OnFilterProperty = {read=FOnFilterProperty, write=FOnFilterProperty};
	__property TcxFilterPropertyEvent OnFilterPropertyEx = {read=FOnFilterPropertyEx, write=FOnFilterPropertyEx};
	__property System::Classes::TNotifyEvent OnPropertyChanged = {read=FOnPropertyChanged, write=FOnPropertyChanged};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomRTTIInspector(HWND ParentWindow) : Cxvgrid::TcxUnboundVerticalGrid(ParentWindow) { }
	
};


class DELPHICLASS TcxRTTIInspector;
class PASCALIMPLEMENTATION TcxRTTIInspector : public TcxCustomRTTIInspector
{
	typedef TcxCustomRTTIInspector inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=0};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Images;
	__property InspectedObject;
	__property LayoutStyle = {default=1};
	__property LookAndFeel;
	__property OptionsView;
	__property OptionsBehavior;
	__property OptionsData;
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawBackground;
	__property OnDrawRowHeader;
	__property OnDrawValue;
	__property OnEdited;
	__property OnEditing;
	__property OnEditValueChanged;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnFilterProperty;
	__property OnFilterPropertyEx;
	__property OnItemChanged;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnLayoutChanged;
	__property OnLeftVisibleBandIndexChanged;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnPropertyChanged;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnTopRowIndexChanged;
public:
	/* TcxCustomRTTIInspector.Create */ inline __fastcall virtual TcxRTTIInspector(System::Classes::TComponent* AOwner) : TcxCustomRTTIInspector(AOwner) { }
	/* TcxCustomRTTIInspector.Destroy */ inline __fastcall virtual ~TcxRTTIInspector(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxRTTIInspector(HWND ParentWindow) : TcxCustomRTTIInspector(ParentWindow) { }
	
};


typedef TcxPropertyEditorClass __fastcall (*TcxPropertyMapperFunc)(System::Classes::TPersistent* Obj, System::Typinfo::PPropInfo PropInfo);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Uitypes::TColor cxComponentPropertyRowTextColor;
extern PACKAGE System::Uitypes::TColor cxSubComponentPropertyRowTextColor;
extern PACKAGE System::ResourceString _SInvalidInteger;
#define Cxoi_SInvalidInteger System::LoadResourceString(&Cxoi::_SInvalidInteger)
extern PACKAGE bool __fastcall HasProperty(System::TClass AClass, const System::UnicodeString APropertyName);
extern PACKAGE bool __fastcall IsUniquePropertyRelativeTo(System::TClass AClass, System::TClass ARelativeClass, const System::UnicodeString APropertyName);
extern PACKAGE bool __fastcall IsUniquePropertyRelativeParent(System::TClass AClass, const System::UnicodeString APropertyName);
extern PACKAGE bool __fastcall IsValidInspectedObject(System::Classes::TPersistent* AObject, TcxCustomRTTIInspector* AInspector);
extern PACKAGE Cxedit::TcxCustomEditPropertiesClass __fastcall cxGetPropertiesClassByEditor(TcxPropertyEditor* APropertyEditor);
extern PACKAGE void __fastcall cxRegisterEditPropertiesClass(TcxPropertyEditorClass AEditorClass, Cxedit::TcxCustomEditPropertiesClass AEditPropertiesClass);
extern PACKAGE void __fastcall cxRegisterPropertyEditor(System::Typinfo::PTypeInfo APropertyType, System::TClass AComponentClass, const System::UnicodeString APropertyName, TcxPropertyEditorClass AEditorClass);
extern PACKAGE void __fastcall cxRegisterPropertyMapper(TcxPropertyMapperFunc AMapper);
extern PACKAGE void __fastcall cxGetComponentProperties(System::Classes::TComponent* AOwner, TcxCustomRTTIInspector* AInspector, TcxComponentList* AComponents, System::Typinfo::TTypeKinds AFilter, TcxGetPropEditProc AProc);
extern PACKAGE void __fastcall cxDotNetInspectObject(System::Classes::TPersistent* AObject, TcxRTTIInspector* AInspector);
}	/* namespace Cxoi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXOI)
using namespace Cxoi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxoiHPP
