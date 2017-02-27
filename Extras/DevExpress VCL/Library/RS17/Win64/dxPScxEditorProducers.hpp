// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxEditorProducers.pas' rev: 24.00 (Win64)

#ifndef DxpscxeditorproducersHPP
#define DxpscxeditorproducersHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <dxCheckGroupBox.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxBlobEdit.hpp>	// Pascal unit
#include <cxHyperLinkEdit.hpp>	// Pascal unit
#include <cxCurrencyEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit
#include <dxPSContainerLnk.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxeditorproducers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPScxControlProducer;
class PASCALIMPLEMENTATION TdxPScxControlProducer : public Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer
{
	typedef Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer inherited;
	
public:
	HIDESBASE Cxcontrols::TcxControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxControlProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxControlProducer(void) { }
	
};


class DELPHICLASS TdxPScxContainerProducer;
class PASCALIMPLEMENTATION TdxPScxContainerProducer : public Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer
{
	typedef Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer inherited;
	
private:
	bool __fastcall GetIsNativeStyle(void);
	Cxcontainer::TcxContainerStyle* __fastcall GetStyle(void);
	
protected:
	virtual Dxpscore::TdxPSCellBorderClass __fastcall GetBorderClass(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(void);
	virtual System::Uitypes::TColor __fastcall GetContentColor(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual System::Uitypes::TColor __fastcall GetFontColor(void);
	virtual System::Uitypes::TFontStyles __fastcall GetFontStyle(void);
	virtual System::Uitypes::TColor __fastcall GetThemedBorderColor(void);
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	virtual bool __fastcall CanUseNativeStyle(Dxthememanager::TdxThemedObjectType AThemedObjectType);
	virtual bool __fastcall ObjectExpandHeight(void);
	__property Dxpscore::TdxPSCellBorderClass BorderClass = {read=GetBorderClass};
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, nodefault};
	__property bool IsNativeStyle = {read=GetIsNativeStyle, nodefault};
	__property System::Uitypes::TColor ThemedBorderColor = {read=GetThemedBorderColor, nodefault};
	
public:
	HIDESBASE Cxcontainer::TcxContainer* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	__classmethod virtual bool __fastcall HasNativeSupportForBorders();
	__property Cxcontainer::TcxContainerStyle* Style = {read=GetStyle};
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxContainerProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSContainerCustomWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxContainerProducer(void) { }
	
};


class DELPHICLASS TdxPScxNativePrintableControlProducer;
class PASCALIMPLEMENTATION TdxPScxNativePrintableControlProducer : public Dxpscontainerlnk::TdxPSNativePrintableControlProducer
{
	typedef Dxpscontainerlnk::TdxPSNativePrintableControlProducer inherited;
	
private:
	System::Uitypes::TColor __fastcall GetBorderColor(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetContentColor(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual void __fastcall InitializeNativePrintableControlHost(Dxpscore::TdxReportVisualItem* AnItem);
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, nodefault};
	
public:
	HIDESBASE Cxcontainer::TcxContainer* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	virtual Cxcontainer::TcxContainerStyle* __fastcall Style(void)/* overload */;
	__classmethod virtual bool __fastcall HasNativeSupportForBorders();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxNativePrintableControlProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSNativePrintableControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxNativePrintableControlProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomEditProducer;
class PASCALIMPLEMENTATION TdxPScxCustomEditProducer : public TdxPScxContainerProducer
{
	typedef TdxPScxContainerProducer inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetControlBoundsRect(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual bool __fastcall ObjectShrinkHeight(void);
	
public:
	HIDESBASE Cxedit::TcxCustomEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	virtual Cxedit::TcxCustomEditProperties* __fastcall Properties(void);
	__property System::Uitypes::TColor FontColor = {read=GetFontColor, nodefault};
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomEditProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomTextEditProducer;
class PASCALIMPLEMENTATION TdxPScxCustomTextEditProducer : public TdxPScxCustomEditProducer
{
	typedef TdxPScxCustomEditProducer inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxtextedit::TcxCustomTextEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxtextedit::TcxCustomTextEditProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomTextEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomTextEditProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomMemoEditProducer;
class PASCALIMPLEMENTATION TdxPScxCustomMemoEditProducer : public TdxPScxCustomTextEditProducer
{
	typedef TdxPScxCustomTextEditProducer inherited;
	
protected:
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Cxmemo::TcxCustomMemo* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
	HIDESBASE Cxmemo::TcxCustomMemoProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomMemoEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomMemoEditProducer(void) { }
	
};


class DELPHICLASS TcxPScxCustomHyperLinkEditProducer;
class PASCALIMPLEMENTATION TcxPScxCustomHyperLinkEditProducer : public TdxPScxCustomTextEditProducer
{
	typedef TdxPScxCustomTextEditProducer inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetFontColor(void);
	virtual System::Uitypes::TFontStyles __fastcall GetFontStyle(void);
	
public:
	HIDESBASE Cxhyperlinkedit::TcxCustomHyperLinkEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxhyperlinkedit::TcxCustomHyperLinkEditProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TcxPScxCustomHyperLinkEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPScxCustomHyperLinkEditProducer(void) { }
	
};


class DELPHICLASS TcxPScxCustomCurrencyEditProducer;
class PASCALIMPLEMENTATION TcxPScxCustomCurrencyEditProducer : public TdxPScxCustomTextEditProducer
{
	typedef TdxPScxCustomTextEditProducer inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	
public:
	HIDESBASE Cxcurrencyedit::TcxCustomCurrencyEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxcurrencyedit::TcxCustomCurrencyEditProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TcxPScxCustomCurrencyEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPScxCustomCurrencyEditProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomComboBoxProducer;
class PASCALIMPLEMENTATION TdxPScxCustomComboBoxProducer : public TdxPScxCustomTextEditProducer
{
	typedef TdxPScxCustomTextEditProducer inherited;
	
public:
	HIDESBASE Cxdropdownedit::TcxCustomComboBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxdropdownedit::TcxCustomComboBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomComboBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomComboBoxProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomImageComboBoxProducer;
class PASCALIMPLEMENTATION TdxPScxCustomImageComboBoxProducer : public TdxPScxCustomComboBoxProducer
{
	typedef TdxPScxCustomComboBoxProducer inherited;
	
protected:
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cximagecombobox::TcxCustomImageComboBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cximagecombobox::TcxCustomImageComboBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomImageComboBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomComboBoxProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomImageComboBoxProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomCheckBoxProducer;
class PASCALIMPLEMENTATION TdxPScxCustomCheckBoxProducer : public TdxPScxCustomEditProducer
{
	typedef TdxPScxCustomEditProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxcheckbox::TcxCustomCheckBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxcheckbox::TcxCustomCheckBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomCheckBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomCheckBoxProducer(void) { }
	
};


class DELPHICLASS TdxPScxRadioButtonProducer;
class PASCALIMPLEMENTATION TdxPScxRadioButtonProducer : public Dxpscontainerlnk::TdxPSRadioButtonProducer
{
	typedef Dxpscontainerlnk::TdxPSRadioButtonProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxradiogroup::TcxRadioButton* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxRadioButtonProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSRadioButtonProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxRadioButtonProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomBlobEditProducer;
class PASCALIMPLEMENTATION TdxPScxCustomBlobEditProducer : public Dxpscontainerlnk::TdxPSCustomDelegateProducer
{
	typedef Dxpscontainerlnk::TdxPSCustomDelegateProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	virtual Dxpscore::TdxReportCellClass __fastcall HostClass(void);
	virtual Dxpscontainerlnk::TdxPSCustomContainerItemProducer* __fastcall Producer(void);
	
public:
	HIDESBASE Cxblobedit::TcxCustomBlobEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomBlobEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSCustomDelegateProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomBlobEditProducer(void) { }
	
};


class DELPHICLASS TdxPScxDefaultBlobEditProducer;
class PASCALIMPLEMENTATION TdxPScxDefaultBlobEditProducer : public TdxPScxCustomTextEditProducer
{
	typedef TdxPScxCustomTextEditProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Cxblobedit::TcxCustomBlobEdit* __fastcall Control(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxDefaultBlobEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxDefaultBlobEditProducer(void) { }
	
};


class DELPHICLASS TdxPScxPictureBlobProducer;
class PASCALIMPLEMENTATION TdxPScxPictureBlobProducer : public TdxPScxCustomEditProducer
{
	typedef TdxPScxCustomEditProducer inherited;
	
protected:
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxblobedit::TcxCustomBlobEdit* __fastcall Control(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxPictureBlobProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxPictureBlobProducer(void) { }
	
};


class DELPHICLASS TdxPScxTextBlobEditProducer;
class PASCALIMPLEMENTATION TdxPScxTextBlobEditProducer : public TdxPScxCustomTextEditProducer
{
	typedef TdxPScxCustomTextEditProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Cxblobedit::TcxCustomBlobEdit* __fastcall Control(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxTextBlobEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomTextEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxTextBlobEditProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomImageEditProducer;
class PASCALIMPLEMENTATION TdxPScxCustomImageEditProducer : public TdxPScxCustomEditProducer
{
	typedef TdxPScxCustomEditProducer inherited;
	
protected:
	virtual bool __fastcall GetHasImage(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall InitializeItemAsImage(Dxpscore::TdxReportCellGraphic* AnItem);
	virtual void __fastcall InitializeItemAsText(Dxpscore::TdxReportCellString* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual bool __fastcall ObjectShrinkHeight(void);
	virtual bool __fastcall ObjectExpandHeight(void);
	
public:
	HIDESBASE Cximage::TcxCustomImage* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cximage::TcxCustomImageProperties* __fastcall Properties(void)/* overload */;
	__property bool HasImage = {read=GetHasImage, nodefault};
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomImageEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomImageEditProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomGroupBoxProducer;
class PASCALIMPLEMENTATION TdxPScxCustomGroupBoxProducer : public TdxPScxCustomEditProducer
{
	typedef TdxPScxCustomEditProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall InitializeItemLookAndFeel(Dxpscore::TdxReportVisualItem* AnItem, Dxpscore::TdxPSReportGroupLookAndFeel* ALookAndFeel);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual Dxpscore::TdxPSReportGroupLookAndFeelClass __fastcall LookAndFeelClass(void);
	
public:
	__classmethod virtual bool __fastcall CanHasAvailableChildren();
	HIDESBASE Cxgroupbox::TcxCustomGroupBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxgroupbox::TcxCustomGroupBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomGroupBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomGroupBoxProducer(void) { }
	
};


class DELPHICLASS TdxPSdxCustomCheckGroupBoxProducer;
class PASCALIMPLEMENTATION TdxPSdxCustomCheckGroupBoxProducer : public TdxPScxCustomGroupBoxProducer
{
	typedef TdxPScxCustomGroupBoxProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Dxcheckgroupbox::TdxCustomCheckGroupBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Dxcheckgroupbox::TdxCheckGroupBoxProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSdxCustomCheckGroupBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomGroupBoxProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSdxCustomCheckGroupBoxProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomButtonGroupProducer;
class PASCALIMPLEMENTATION TdxPScxCustomButtonGroupProducer : public TdxPScxCustomGroupBoxProducer
{
	typedef TdxPScxCustomGroupBoxProducer inherited;
	
protected:
	virtual void __fastcall CreateItems(Dxpscore::TdxCustomReportButtonGroup* AButtonGroup);
	virtual void __fastcall InitializeButton(Dxpscore::TdxCustomReportButtonGroup* AGroup, Dxpscore::TdxCustomReportCellCheck* AButton, int AnIndex);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall InitializeItemLookAndFeel(Dxpscore::TdxReportVisualItem* AnItem, Dxpscore::TdxPSReportGroupLookAndFeel* ALookAndFeel);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxgroupbox::TcxCustomButtonGroup* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxgroupbox::TcxCustomButtonGroupProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomButtonGroupProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomGroupBoxProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomButtonGroupProducer(void) { }
	
};


class DELPHICLASS TdxPScxCustomRadioGroupProducer;
class PASCALIMPLEMENTATION TdxPScxCustomRadioGroupProducer : public TdxPScxCustomButtonGroupProducer
{
	typedef TdxPScxCustomButtonGroupProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	virtual void __fastcall InitializeButton(Dxpscore::TdxCustomReportButtonGroup* AGroup, Dxpscore::TdxCustomReportCellCheck* AButton, int AnIndex);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Cxradiogroup::TcxCustomRadioGroup* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE Cxradiogroup::TcxRadioGroupProperties* __fastcall Properties(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxCustomRadioGroupProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPScxCustomButtonGroupProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxCustomRadioGroupProducer(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::StaticArray<Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle, 7> CheckBorderStyleMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxCellCheckPos, 3> CheckPosMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxPSCellBorderClass, 7> ContainerBorderStyleMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxPSCellBorderClass, 7> EditBorderStyleMap;
extern PACKAGE System::StaticArray<Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle, 4> RadioLookAndFeelKindMap;
extern PACKAGE System::StaticArray<Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle, 7> RadioBorderStyleMap;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignX, 13> GroupBoxCaptionAlignmentMap;
extern PACKAGE Dxpscore::TdxCellSides __fastcall cxBordersMap(Cxgraphics::TcxBorders ABorders);
}	/* namespace Dxpscxeditorproducers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXEDITORPRODUCERS)
using namespace Dxpscxeditorproducers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxeditorproducersHPP
