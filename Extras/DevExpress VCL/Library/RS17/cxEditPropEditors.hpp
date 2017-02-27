// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditPropEditors.pas' rev: 24.00 (Win32)

#ifndef CxeditpropeditorsHPP
#define CxeditpropeditorsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DBReg.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.WideStrings.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditRepositoryItems.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <cxLibraryReg.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <dxAlertWindow.hpp>	// Pascal unit
#include <dxBreadcrumbEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditpropeditors
{
//-- type declarations -------------------------------------------------------
typedef System::Classes::TStrings TdxValues;

typedef System::Classes::TStringList TdxValueList;

class DELPHICLASS TDBStringProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TDBStringProperty : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValueList(System::Classes::TStrings* AList);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TDBStringProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDBStringProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDataFieldProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFieldProperty : public Dbreg::TDataFieldProperty
{
	typedef Dbreg::TDataFieldProperty inherited;
	
public:
	virtual void __fastcall GetValueList(System::Classes::TStrings* List);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxDataFieldProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Dbreg::TDataFieldProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxDataFieldProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDateProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDateProperty : public Designeditors::TDateProperty
{
	typedef Designeditors::TDateProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GetValue(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxDateProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TDateProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxDateProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxValueTypeProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueTypeProperty : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
protected:
	virtual bool __fastcall IsValueTypeClassValid(Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxValueTypeProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxValueTypeProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TFieldNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TFieldNameProperty : public TDBStringProperty
{
	typedef TDBStringProperty inherited;
	
public:
	virtual Data::Db::TDataSource* __fastcall GetDataSource(void);
	virtual System::UnicodeString __fastcall GetDataSourcePropName(void);
	virtual void __fastcall GetValueList(System::Classes::TStrings* AList);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TFieldNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TDBStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFieldNameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomEditorsLibraryComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditorsLibraryComponentEditor : public Dxcorereg::TdxComponentEditor
{
	typedef Dxcorereg::TdxComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetProductName(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxCustomEditorsLibraryComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxcorereg::TdxComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxCustomEditorsLibraryComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditComponentEditor : public TcxCustomEditorsLibraryComponentEditor
{
	typedef TcxCustomEditorsLibraryComponentEditor inherited;
	
private:
	Cxedit::TcxCustomEdit* __fastcall GetEdit(void);
	
protected:
	virtual System::UnicodeString __fastcall InternalGetVerb(int Index);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
	
public:
	virtual void __fastcall Edit(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxEditComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxCustomEditorsLibraryComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxEditComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditRepositoryItemProperty;
class PASCALIMPLEMENTATION TcxEditRepositoryItemProperty : public Designeditors::TComponentProperty
{
	typedef Designeditors::TComponentProperty inherited;
	
private:
	System::Classes::TGetStrProc FStrProc;
	void __fastcall StrProc(const System::UnicodeString S);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxEditRepositoryItemProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TComponentProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxEditRepositoryItemProperty(void) { }
	
};


class DELPHICLASS TcxLookupEditListSourceProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLookupEditListSourceProperty : public TcxDataFieldProperty
{
	typedef TcxDataFieldProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GetDataSourcePropName(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxLookupEditListSourceProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TcxDataFieldProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxLookupEditListSourceProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditPropertiesEventEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditPropertiesEventEditor : public Cxpropeditors::TcxNestedEventProperty
{
	typedef Cxpropeditors::TcxNestedEventProperty inherited;
	
protected:
	virtual System::Classes::TPersistent* __fastcall GetInstance(void);
	
public:
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxEditPropertiesEventEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TcxNestedEventProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxEditPropertiesEventEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditRepositoryItemPropertiesEventEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditRepositoryItemPropertiesEventEditor : public Cxpropeditors::TcxNestedEventProperty
{
	typedef Cxpropeditors::TcxNestedEventProperty inherited;
	
protected:
	virtual System::Classes::TPersistent* __fastcall GetInstance(void);
	
public:
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxEditRepositoryItemPropertiesEventEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TcxNestedEventProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxEditRepositoryItemPropertiesEventEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxNavigatorButtonsEventEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNavigatorButtonsEventEditor : public Cxpropeditors::TcxNestedEventProperty
{
	typedef Cxpropeditors::TcxNestedEventProperty inherited;
	
protected:
	virtual System::Classes::TPersistent* __fastcall GetInstance(void);
	
public:
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxNavigatorButtonsEventEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TcxNestedEventProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxNavigatorButtonsEventEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxNavigatorInfoPanelEventEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNavigatorInfoPanelEventEditor : public Cxpropeditors::TcxNestedEventProperty
{
	typedef Cxpropeditors::TcxNestedEventProperty inherited;
	
protected:
	virtual System::Classes::TPersistent* __fastcall GetInstance(void);
	
public:
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxNavigatorInfoPanelEventEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TcxNestedEventProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxNavigatorInfoPanelEventEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGetPropertiesImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGetPropertiesImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxGetPropertiesImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxGetPropertiesImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGetItemImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGetItemImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxGetItemImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxGetItemImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlItemImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlItemImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxGalleryControlItemImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxGalleryControlItemImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditorsLibraryComponentEditorEx;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditorsLibraryComponentEditorEx : public TcxCustomEditorsLibraryComponentEditor
{
	typedef TcxCustomEditorsLibraryComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetEditItemCaption(void);
	virtual void __fastcall ExecuteEditAction(void) = 0 ;
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxEditorsLibraryComponentEditorEx(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxCustomEditorsLibraryComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxEditorsLibraryComponentEditorEx(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditRepositoryComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditRepositoryComponentEditor : public TcxEditorsLibraryComponentEditorEx
{
	typedef TcxEditorsLibraryComponentEditorEx inherited;
	
private:
	Cxedit::TcxEditRepository* __fastcall GetEditRepository(void);
	
protected:
	virtual void __fastcall ExecuteEditAction(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxEditRepositoryComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentEditorEx(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxEditRepositoryComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditMaskProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditMaskProperty : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall Edit(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxEditMaskProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxEditMaskProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTextProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTextProperty : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
private:
	bool __fastcall CanShowDialog(void);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall Edit(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxTextProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxTextProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TGraphicClassNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TGraphicClassNameProperty : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TGraphicClassNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TGraphicClassNameProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxControlSelectionEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlSelectionEditor : public Designeditors::TSelectionEditor
{
	typedef Designeditors::TSelectionEditor inherited;
	
public:
	virtual void __fastcall RequiresUnits(System::Classes::TGetStrProc Proc);
public:
	/* TSelectionEditor.Create */ inline __fastcall virtual TcxControlSelectionEditor(const Designintf::_di_IDesigner ADesigner) : Designeditors::TSelectionEditor(ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxControlSelectionEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomEditSelectionEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditSelectionEditor : public Designeditors::TSelectionEditor
{
	typedef Designeditors::TSelectionEditor inherited;
	
public:
	virtual void __fastcall RequiresUnits(System::Classes::TGetStrProc Proc);
public:
	/* TSelectionEditor.Create */ inline __fastcall virtual TcxCustomEditSelectionEditor(const Designintf::_di_IDesigner ADesigner) : Designeditors::TSelectionEditor(ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomEditSelectionEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxButtonSelectionEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxButtonSelectionEditor : public Designeditors::TSelectionEditor
{
	typedef Designeditors::TSelectionEditor inherited;
	
public:
	virtual void __fastcall RequiresUnits(System::Classes::TGetStrProc Proc);
public:
	/* TSelectionEditor.Create */ inline __fastcall virtual TcxButtonSelectionEditor(const Designintf::_di_IDesigner ADesigner) : Designeditors::TSelectionEditor(ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxButtonSelectionEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxFilterControlComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterControlComponentEditor : public Cxlibraryreg::TcxDefaultEditor
{
	typedef Cxlibraryreg::TcxDefaultEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetProductName(void);
public:
	/* TComponentEditor.Create */ inline __fastcall virtual TcxFilterControlComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Cxlibraryreg::TcxDefaultEditor(AComponent, ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterControlComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxNavigatorControlProperty;
class PASCALIMPLEMENTATION TcxNavigatorControlProperty : public Designeditors::TComponentProperty
{
	typedef Designeditors::TComponentProperty inherited;
	
private:
	System::Classes::TGetStrProc FStrProc;
	void __fastcall StrProc(const System::UnicodeString S);
	
public:
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxNavigatorControlProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TComponentProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxNavigatorControlProperty(void) { }
	
};


class DELPHICLASS TcxEditorsLibraryComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditorsLibraryComponentEditor : public TcxEditorsLibraryComponentEditorEx
{
	typedef TcxEditorsLibraryComponentEditorEx inherited;
	
public:
	virtual void __fastcall Edit(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxEditorsLibraryComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentEditorEx(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxEditorsLibraryComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditorsLibraryComponentWithStylesEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditorsLibraryComponentWithStylesEditor : public TcxEditorsLibraryComponentEditor
{
	typedef TcxEditorsLibraryComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetEditItemCaption(void);
	virtual void __fastcall ExecuteEditAction(void);
	virtual void __fastcall RestoreStyles(void) = 0 ;
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxEditorsLibraryComponentWithStylesEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxEditorsLibraryComponentWithStylesEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditorsLibraryComponentWithoutStylesEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditorsLibraryComponentWithoutStylesEditor : public TcxEditorsLibraryComponentEditor
{
	typedef TcxEditorsLibraryComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetEditItemCaption(void);
	virtual void __fastcall ExecuteEditAction(void);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void) = 0 ;
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxEditorsLibraryComponentWithoutStylesEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxEditorsLibraryComponentWithoutStylesEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditorsLibraryCXControlComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditorsLibraryCXControlComponentEditor : public TcxEditorsLibraryComponentWithoutStylesEditor
{
	typedef TcxEditorsLibraryComponentWithoutStylesEditor inherited;
	
protected:
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxEditorsLibraryCXControlComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentWithoutStylesEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxEditorsLibraryCXControlComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxBreadcrumbEditComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBreadcrumbEditComponentEditor : public TcxEditorsLibraryCXControlComponentEditor
{
	typedef TcxEditorsLibraryCXControlComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
	
public:
	virtual void __fastcall Edit(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxBreadcrumbEditComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryCXControlComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxBreadcrumbEditComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditSelectedPathPropertyEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditSelectedPathPropertyEditor : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBreadcrumbEditSelectedPathPropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditSelectedPathPropertyEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBevelComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBevelComponentEditor : public TcxEditorsLibraryComponentWithoutStylesEditor
{
	typedef TcxEditorsLibraryComponentWithoutStylesEditor inherited;
	
protected:
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxBevelComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentWithoutStylesEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxBevelComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditStyleControllerEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditStyleControllerEditor : public TcxEditorsLibraryComponentWithStylesEditor
{
	typedef TcxEditorsLibraryComponentWithStylesEditor inherited;
	
protected:
	virtual void __fastcall RestoreStyles(void);
	
public:
	virtual void __fastcall Edit(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxEditStyleControllerEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentWithStylesEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxEditStyleControllerEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDefaultEditStyleControllerEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDefaultEditStyleControllerEditor : public TcxEditorsLibraryComponentWithStylesEditor
{
	typedef TcxEditorsLibraryComponentWithStylesEditor inherited;
	
protected:
	virtual void __fastcall RestoreStyles(void);
	
public:
	virtual void __fastcall Edit(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxDefaultEditStyleControllerEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentWithStylesEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxDefaultEditStyleControllerEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomButtonComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomButtonComponentEditor : public TcxEditorsLibraryComponentWithoutStylesEditor
{
	typedef TcxEditorsLibraryComponentWithoutStylesEditor inherited;
	
protected:
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxCustomButtonComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentWithoutStylesEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxCustomButtonComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowComponentEditor : public TcxEditorsLibraryComponentWithoutStylesEditor
{
	typedef TcxEditorsLibraryComponentWithoutStylesEditor inherited;
	
protected:
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxAlertWindowComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentWithoutStylesEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxAlertWindowComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRadioButtonComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRadioButtonComponentEditor : public TcxEditorsLibraryComponentWithoutStylesEditor
{
	typedef TcxEditorsLibraryComponentWithoutStylesEditor inherited;
	
protected:
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxRadioButtonComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentWithoutStylesEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxRadioButtonComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxContainerComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxContainerComponentEditor : public TcxEditorsLibraryComponentWithStylesEditor
{
	typedef TcxEditorsLibraryComponentWithStylesEditor inherited;
	
protected:
	virtual void __fastcall RestoreStyles(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxContainerComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentWithStylesEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxContainerComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomNavigatorComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomNavigatorComponentEditor : public TcxEditorsLibraryCXControlComponentEditor
{
	typedef TcxEditorsLibraryCXControlComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
	
public:
	virtual void __fastcall Edit(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxCustomNavigatorComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryCXControlComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxCustomNavigatorComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlComponentEditor : public TcxEditorsLibraryComponentEditorEx
{
	typedef TcxEditorsLibraryComponentEditorEx inherited;
	
protected:
	virtual void __fastcall ExecuteEditAction(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxGalleryControlComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryComponentEditorEx(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxGalleryControlComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSliderImageComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSliderImageComponentEditor : public TcxEditorsLibraryCXControlComponentEditor
{
	typedef TcxEditorsLibraryCXControlComponentEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxSliderImageComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TcxEditorsLibraryCXControlComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxSliderImageComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomImagePropertiesProperty;
class PASCALIMPLEMENTATION TcxCustomImagePropertiesProperty : public TcxEditPropertiesEventEditor
{
	typedef TcxEditPropertiesEventEditor inherited;
	
private:
	Designintf::TGetPropProc FProc;
	void __fastcall GetPropProc(const Designintf::_di_IProperty Prop);
	
public:
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxCustomImagePropertiesProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TcxEditPropertiesEventEditor(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxCustomImagePropertiesProperty(void) { }
	
};


class DELPHICLASS TcxEditPropertiesAssignedValuesProperty;
class PASCALIMPLEMENTATION TcxEditPropertiesAssignedValuesProperty : public Designeditors::TClassProperty
{
	typedef Designeditors::TClassProperty inherited;
	
private:
	Designintf::TGetPropProc FProc;
	void __fastcall GetPropProc(const Designintf::_di_IProperty Prop);
	bool __fastcall IsVisibleProperty(const System::UnicodeString APropertyName);
	
public:
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
	virtual System::UnicodeString __fastcall GetValue(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxEditPropertiesAssignedValuesProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxEditPropertiesAssignedValuesProperty(void) { }
	
};


class DELPHICLASS TcxDefaultEditStyleControllerStyleProperty;
class PASCALIMPLEMENTATION TcxDefaultEditStyleControllerStyleProperty : public Cxpropeditors::TcxStyleControllerStyleProperty
{
	typedef Cxpropeditors::TcxStyleControllerStyleProperty inherited;
	
protected:
	virtual Cxcontainer::TcxContainerStyle* __fastcall GetStyle(void);
	virtual bool __fastcall IsPropertyVisible(const System::UnicodeString APropertyName);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxDefaultEditStyleControllerStyleProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TcxStyleControllerStyleProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxDefaultEditStyleControllerStyleProperty(void) { }
	
};


class DELPHICLASS TcxNavigatorButtonImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNavigatorButtonImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxNavigatorButtonImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxNavigatorButtonImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxNavigatorCustomButtonImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNavigatorCustomButtonImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxNavigatorCustomButtonImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxNavigatorCustomButtonImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditButtonImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditButtonImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxEditButtonImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxEditButtonImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxButtonImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxButtonImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxButtonImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxButtonImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAlertWindowButtonImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAlertWindowButtonImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxAlertWindowButtonImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxAlertWindowButtonImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditButtonImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditButtonImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBreadcrumbEditButtonImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditButtonImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditRecentPathImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditRecentPathImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	Dxbreadcrumbedit::TdxBreadcrumbEditPathEditorProperties* __fastcall GetPathEditorProperties(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBreadcrumbEditRecentPathImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditRecentPathImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditGuidelines;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditGuidelines : public Vcleditors::TWinControlGuidelines
{
	typedef Vcleditors::TWinControlGuidelines inherited;
	
private:
	Cxedit::TcxCustomEdit* __fastcall GetEdit(void);
	
protected:
	virtual int __fastcall GetCount(void);
	virtual int __fastcall GetDesignerGuideOffset(int Index);
	virtual Designintf::TDesignerGuideType __fastcall GetDesignerGuideType(int Index);
	__property Cxedit::TcxCustomEdit* Edit = {read=GetEdit};
public:
	/* TBaseComponentGuidelines.Create */ inline __fastcall virtual TcxEditGuidelines(const Designintf::_di_IDesigner ADesigner) : Vcleditors::TWinControlGuidelines(ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEditGuidelines(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxDataControllerMultithreadedSortingPropertyEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDataControllerMultithreadedSortingPropertyEditor : public Dxcorereg::TdxDefaultBooleanPropertyEditor
{
	typedef Dxcorereg::TdxDefaultBooleanPropertyEditor inherited;
	
protected:
	virtual bool __fastcall GetDefaultValue(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxDataControllerMultithreadedSortingPropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Dxcorereg::TdxDefaultBooleanPropertyEditor(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxDataControllerMultithreadedSortingPropertyEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxDataControllerMultithreadedFilteringPropertyEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDataControllerMultithreadedFilteringPropertyEditor : public Dxcorereg::TdxDefaultBooleanPropertyEditor
{
	typedef Dxcorereg::TdxDefaultBooleanPropertyEditor inherited;
	
protected:
	virtual bool __fastcall GetDefaultValue(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxDataControllerMultithreadedFilteringPropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Dxcorereg::TdxDefaultBooleanPropertyEditor(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxDataControllerMultithreadedFilteringPropertyEditor(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define cxEditorsLibraryProductName L"ExpressEditors Library"
#define cxEditorsLibraryProductPage L"Express Editors"
#define cxEditorsDBLibraryProductPage L"Express DBEditors"
#define cxEditorsUtilitiesProductPage L"Express Utilities"
}	/* namespace Cxeditpropeditors */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITPROPEDITORS)
using namespace Cxeditpropeditors;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditpropeditorsHPP
