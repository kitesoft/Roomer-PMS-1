// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxExtEditorProducers.pas' rev: 24.00 (Win32)

#ifndef DxpscxexteditorproducersHPP
#define DxpscxexteditorproducersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxFontNameComboBox.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxCheckComboBox.hpp>	// Pascal unit
#include <cxShellComboBox.hpp>	// Pascal unit
#include <cxSpinButton.hpp>	// Pascal unit
#include <cxCheckGroup.hpp>	// Pascal unit
#include <cxRichEdit.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxPSContainerLnk.hpp>	// Pascal unit
#include <dxPScxExtCommon.hpp>	// Pascal unit
#include <dxPScxEditorProducers.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxexteditorproducers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPScxCustomColorComboBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxCustomColorComboBoxProducer : public Dxpscxeditorproducers::TdxPScxCustomTextEditProducer
{
	typedef Dxpscxeditorproducers::TdxPScxCustomTextEditProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxcolorcombobox::TcxCustomColorComboBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxcolorcombobox::TcxCustomColorComboBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomColorComboBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscxeditorproducers::TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomColorComboBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxCustomShellComboBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxCustomShellComboBoxProducer : public Dxpscxeditorproducers::TdxPScxCustomTextEditProducer
{
	typedef Dxpscxeditorproducers::TdxPScxCustomTextEditProducer inherited;
	
protected:
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxshellcombobox::TcxCustomShellComboBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxshellcombobox::TcxCustomShellComboBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomShellComboBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscxeditorproducers::TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomShellComboBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxCustomFontNameComboBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxCustomFontNameComboBoxProducer : public Dxpscxeditorproducers::TdxPScxCustomComboBoxProducer
{
	typedef Dxpscxeditorproducers::TdxPScxCustomComboBoxProducer inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetFontName(void);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual bool __fastcall IsFontSubstitutable(void);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxfontnamecombobox::TcxCustomFontNameComboBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxfontnamecombobox::TcxCustomFontNameComboBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomFontNameComboBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscxeditorproducers::TdxPScxCustomComboBoxProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomFontNameComboBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxCustomCheckComboBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxCustomCheckComboBoxProducer : public Dxpscxeditorproducers::TdxPScxCustomComboBoxProducer
{
	typedef Dxpscxeditorproducers::TdxPScxCustomComboBoxProducer inherited;
	
public:
	HIDESBASE Cxcheckcombobox::TcxCustomCheckComboBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxcheckcombobox::TcxCustomCheckComboBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomCheckComboBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscxeditorproducers::TdxPScxCustomComboBoxProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomCheckComboBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxCustomSpinButtonAsMetafileProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxCustomSpinButtonAsMetafileProducer : public Dxpscontainerlnk::TdxPSWinControlAsMetafileProducer
{
	typedef Dxpscontainerlnk::TdxPSWinControlAsMetafileProducer inherited;
	
protected:
	__classmethod virtual Dxpscontainerlnk::TdxPSCustomProducerClass __fastcall BuddyClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomSpinButtonAsMetafileProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSWinControlAsMetafileProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomSpinButtonAsMetafileProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxCustomSpinButtonProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxCustomSpinButtonProducer : public Dxpscxeditorproducers::TdxPScxCustomTextEditProducer
{
	typedef Dxpscxeditorproducers::TdxPScxCustomTextEditProducer inherited;
	
public:
	HIDESBASE Cxspinbutton::TcxCustomSpinButton* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomSpinButtonProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscxeditorproducers::TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomSpinButtonProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxCustomCheckGroupProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxCustomCheckGroupProducer : public Dxpscxeditorproducers::TdxPScxCustomButtonGroupProducer
{
	typedef Dxpscxeditorproducers::TdxPScxCustomButtonGroupProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	virtual void __fastcall InitializeButton(Dxpscore::TdxCustomReportButtonGroup* AGroup, Dxpscore::TdxCustomReportCellCheck* AButton, int AnIndex);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxcheckgroup::TcxCustomCheckGroup* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxcheckgroup::TcxCustomCheckGroupProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomCheckGroupProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscxeditorproducers::TdxPScxCustomButtonGroupProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomCheckGroupProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxCustomRichEditProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxCustomRichEditProducer : public Dxpscxeditorproducers::TdxPScxContainerProducer
{
	typedef Dxpscxeditorproducers::TdxPScxContainerProducer inherited;
	
protected:
	virtual Vcl::Graphics::TGraphic* __fastcall CreateImage(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual bool __fastcall ObjectExpandHeight(void);
	
public:
	HIDESBASE Cxrichedit::TcxCustomRichEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomRichEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscxeditorproducers::TdxPScxContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomRichEditProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPScxCustomLabelProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPScxCustomLabelProducer : public Dxpscxeditorproducers::TdxPScxCustomEditProducer
{
	typedef Dxpscxeditorproducers::TdxPScxCustomEditProducer inherited;
	
protected:
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AItem);
	
public:
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxlabel::TcxCustomLabel* __fastcall Control(void)/* overload */;
	HIDESBASE Cxlabel::TcxCustomLabelProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TcxPScxCustomLabelProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscxeditorproducers::TdxPScxCustomEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPScxCustomLabelProducer(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxexteditorproducers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXEXTEDITORPRODUCERS)
using namespace Dxpscxexteditorproducers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxexteditorproducersHPP
