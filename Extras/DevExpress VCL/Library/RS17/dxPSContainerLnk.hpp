// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSContainerLnk.pas' rev: 24.00 (Win32)

#ifndef DxpscontainerlnkHPP
#define DxpscontainerlnkHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.TabNotBk.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxPSShapes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <dxPSStandardFillPatterns.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxScrollBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscontainerlnk
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxCustomContainerReportLinkOptionsItemPlaceClass;

typedef System::TMetaClass* TdxCustomContainerReportLinkOptionsPaginationClass;

typedef System::TMetaClass* TdxCustomContainerReportLinkOptionsTransparentClass;

class DELPHICLASS TdxReportWinControlHost;
class PASCALIMPLEMENTATION TdxReportWinControlHost : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
private:
	bool __fastcall GetHasControlItem(void);
	
protected:
	virtual void __fastcall BoundsChanged(void);
	virtual Dxpscore::TdxReportVisualItem* __fastcall GetControlItem(void);
	
public:
	virtual int __fastcall MeasureHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual int __fastcall MeasureWidth(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__property Dxpscore::TdxReportVisualItem* ControlItem = {read=GetControlItem};
	__property bool HasControlItem = {read=GetHasControlItem, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportWinControlHost(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportWinControlHost(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCell(AParent) { }
	
};


class DELPHICLASS TdxReportNativePrintableControlHost;
class PASCALIMPLEMENTATION TdxReportNativePrintableControlHost : public TdxReportWinControlHost
{
	typedef TdxReportWinControlHost inherited;
	
protected:
	virtual Dxpscore::TdxReportVisualItem* __fastcall GetControlItem(void);
	virtual void __fastcall BoundsChanged(void);
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportNativePrintableControlHost(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportNativePrintableControlHost(Dxpscore::TdxReportCell* AParent) : TdxReportWinControlHost(AParent) { }
	
};


typedef System::TMetaClass* TdxPSCustomContainerItemDefinitionClass;

class DELPHICLASS TdxPSCustomContainerItemDefinition;
class DELPHICLASS TdxCustomContainerReportLinkOptionsItemPlace;
class DELPHICLASS TdxCustomContainerReportLink;
class DELPHICLASS TdxCustomContainerReportLinkOptionsPagination;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomContainerItemDefinition : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TComponent* FComponent;
	TdxCustomContainerReportLinkOptionsItemPlace* FOptionsPlace;
	Dxpscore::TdxReportVisualItem* FReportItem;
	TdxCustomContainerReportLink* FReportLink;
	Vcl::Controls::TWinControl* __fastcall GetRootContainer(void);
	Vcl::Controls::TWinControl* __fastcall GetTopLevelRootContainer(void);
	
protected:
	virtual void __fastcall AddDelimitersHorz(System::Classes::TList* AList);
	virtual void __fastcall AddDelimitersVert(System::Classes::TList* AList);
	void __fastcall AddReportItemToDelimitersHorz(System::Classes::TList* AList);
	void __fastcall AddReportItemToDelimitersVert(System::Classes::TList* AList);
	virtual Dxpscore::TdxReportVisualItem* __fastcall GetSizeChangeReportItem(void);
	virtual Dxpscore::TdxReportVisualItem* __fastcall GetSizeMeasureReportItem(void);
	
public:
	__fastcall virtual TdxPSCustomContainerItemDefinition(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem);
	__fastcall virtual ~TdxPSCustomContainerItemDefinition(void);
	virtual TdxCustomContainerReportLinkOptionsPagination* __fastcall OptionsPagination(void)/* overload */;
	__property System::Classes::TComponent* Component = {read=FComponent, write=FComponent};
	__property TdxCustomContainerReportLinkOptionsItemPlace* OptionsPlace = {read=FOptionsPlace};
	__property Dxpscore::TdxReportVisualItem* ReportItem = {read=FReportItem, write=FReportItem};
	__property TdxCustomContainerReportLink* ReportLink = {read=FReportLink};
	__property Vcl::Controls::TWinControl* RootContainer = {read=GetRootContainer};
	__property Vcl::Controls::TWinControl* TopLevelRootContainer = {read=GetTopLevelRootContainer};
	__property Dxpscore::TdxReportVisualItem* SizeChangeReportItem = {read=GetSizeChangeReportItem};
	__property Dxpscore::TdxReportVisualItem* SizeMeasureReportItem = {read=GetSizeMeasureReportItem};
};

#pragma pack(pop)

class DELPHICLASS TdxPSContainerControlDefinition;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSContainerControlDefinition : public TdxPSCustomContainerItemDefinition
{
	typedef TdxPSCustomContainerItemDefinition inherited;
	
private:
	Vcl::Controls::TControl* __fastcall GetControl(void);
	void __fastcall SetControl(Vcl::Controls::TControl* Value);
	
protected:
	virtual void __fastcall AddDelimitersHorz(System::Classes::TList* AList);
	virtual void __fastcall AddDelimitersVert(System::Classes::TList* AList);
	
public:
	__property Vcl::Controls::TControl* Control = {read=GetControl, write=SetControl};
public:
	/* TdxPSCustomContainerItemDefinition.Create */ inline __fastcall virtual TdxPSContainerControlDefinition(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem) : TdxPSCustomContainerItemDefinition(AReportLink, AComponent, AReportItem) { }
	/* TdxPSCustomContainerItemDefinition.Destroy */ inline __fastcall virtual ~TdxPSContainerControlDefinition(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSNativePrintableControlDefinition;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSNativePrintableControlDefinition : public TdxPSContainerControlDefinition
{
	typedef TdxPSContainerControlDefinition inherited;
	
private:
	System::Classes::TList* FDelimitersHorz;
	System::Classes::TList* FDelimitersVert;
	System::Types::TPoint FReportDimension;
	System::Types::TPoint __fastcall GetDelimitersOffset(void);
	
protected:
	virtual void __fastcall AddDelimitersHorz(System::Classes::TList* AList);
	virtual void __fastcall AddDelimitersVert(System::Classes::TList* AList);
	void __fastcall GetData(Dxpscore::TBasedxReportLink* AReportLink);
	void __fastcall ShiftDelimiters(void);
	virtual Dxpscore::TdxReportVisualItem* __fastcall GetSizeChangeReportItem(void);
	__property System::Types::TPoint DelimitersOffset = {read=GetDelimitersOffset};
	__property System::Classes::TList* DelimitersHorz = {read=FDelimitersHorz};
	__property System::Classes::TList* DelimitersVert = {read=FDelimitersVert};
	__property System::Types::TPoint ReportDimension = {read=FReportDimension};
	
public:
	__fastcall virtual TdxPSNativePrintableControlDefinition(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem);
	__fastcall virtual ~TdxPSNativePrintableControlDefinition(void);
};

#pragma pack(pop)

class DELPHICLASS TdxPSContainerWinControlDefinition;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSContainerWinControlDefinition : public TdxPSContainerControlDefinition
{
	typedef TdxPSContainerControlDefinition inherited;
	
protected:
	virtual Dxpscore::TdxReportVisualItem* __fastcall GetSizeChangeReportItem(void);
public:
	/* TdxPSCustomContainerItemDefinition.Create */ inline __fastcall virtual TdxPSContainerWinControlDefinition(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem) : TdxPSContainerControlDefinition(AReportLink, AComponent, AReportItem) { }
	/* TdxPSCustomContainerItemDefinition.Destroy */ inline __fastcall virtual ~TdxPSContainerWinControlDefinition(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSContainerDefinition;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSContainerDefinition : public TdxPSContainerWinControlDefinition
{
	typedef TdxPSContainerWinControlDefinition inherited;
	
protected:
	virtual Dxpscore::TdxReportVisualItem* __fastcall GetSizeMeasureReportItem(void);
public:
	/* TdxPSCustomContainerItemDefinition.Create */ inline __fastcall virtual TdxPSContainerDefinition(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem) : TdxPSContainerWinControlDefinition(AReportLink, AComponent, AReportItem) { }
	/* TdxPSCustomContainerItemDefinition.Destroy */ inline __fastcall virtual ~TdxPSContainerDefinition(void) { }
	
};

#pragma pack(pop)

__interface IdxPSContainerIterator;
typedef System::DelphiInterface<IdxPSContainerIterator> _di_IdxPSContainerIterator;
__interface  INTERFACE_UUID("{B18A68C0-5505-42AC-9B8D-B96C79A2725E}") IdxPSContainerIterator  : public System::IInterface 
{
	
public:
	virtual Vcl::Controls::TControl* __fastcall GetControl(int Index) = 0 ;
	virtual int __fastcall GetControlCount(void) = 0 ;
	virtual void __fastcall GoBeforeBOF(void) = 0 ;
	virtual void __fastcall GoBeyondEOF(void) = 0 ;
	virtual bool __fastcall IsBOF(void) = 0 ;
	virtual bool __fastcall IsEOF(void) = 0 ;
	virtual Vcl::Controls::TControl* __fastcall Next(void) = 0 ;
	virtual Vcl::Controls::TControl* __fastcall Prev(void) = 0 ;
	__property int ControlCount = {read=GetControlCount};
	__property Vcl::Controls::TControl* Controls[int Index] = {read=GetControl};
};

typedef System::TMetaClass* TdxPSWinControlIteratorClass;

class DELPHICLASS TdxPSWinControlIterator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSWinControlIterator : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	Vcl::Controls::TWinControl* FControl;
	int FCounter;
	
protected:
	virtual Vcl::Controls::TControl* __fastcall GetControl(int Index);
	virtual int __fastcall GetControlCount(void);
	virtual void __fastcall GoBeforeBOF(void);
	virtual void __fastcall GoBeyondEOF(void);
	virtual bool __fastcall IsBOF(void);
	virtual bool __fastcall IsEOF(void);
	virtual Vcl::Controls::TControl* __fastcall Next(void);
	virtual Vcl::Controls::TControl* __fastcall Prev(void);
	__property int ControlCount = {read=GetControlCount, nodefault};
	__property Vcl::Controls::TControl* Controls[int Index] = {read=GetControl};
	
public:
	__fastcall virtual TdxPSWinControlIterator(Vcl::Controls::TWinControl* AControl);
	__classmethod virtual Vcl::Controls::TWinControlClass __fastcall ContainerClass();
	__property Vcl::Controls::TWinControl* Control = {read=FControl};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSWinControlIterator(void) { }
	
private:
	void *__IdxPSContainerIterator;	/* IdxPSContainerIterator */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B18A68C0-5505-42AC-9B8D-B96C79A2725E}
	operator _di_IdxPSContainerIterator()
	{
		_di_IdxPSContainerIterator intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxPSContainerIterator*(void) { return (IdxPSContainerIterator*)&__IdxPSContainerIterator; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxPSCustomProducerClass;

class DELPHICLASS TdxPSCustomProducer;
class DELPHICLASS TdxCustomContainerReportLinkOptionsTransparent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomProducer : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
private:
	System::Classes::TComponent* FProducingObject;
	TdxCustomContainerReportLink* FReportLink;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetCanvas(void);
	TdxPSCustomContainerItemDefinition* __fastcall GetDefinition(System::Classes::TComponent* Component);
	bool __fastcall GetIsDesigning(void);
	TdxPSCustomProducer* __fastcall GetProducer(System::Classes::TComponent* Component);
	
protected:
	__classmethod virtual TdxPSCustomProducerClass __fastcall BuddyClass();
	__classmethod virtual TdxPSCustomProducerClass __fastcall HelperProducer();
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	virtual int __fastcall GetScrollPosLeft(void);
	virtual int __fastcall GetScrollPosTop(void);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InitializeOptionsPlace(TdxCustomContainerReportLinkOptionsItemPlace* AnOptions);
	virtual void __fastcall DoReposition(void);
	virtual int __fastcall MeasureItemHeight(Dxpscore::TdxReportVisualItem* AItem);
	virtual int __fastcall MeasureItemWidth(Dxpscore::TdxReportVisualItem* AItem);
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
	virtual bool __fastcall ObjectShrinkHeight(void);
	virtual bool __fastcall ObjectShrinkWidth(void);
	virtual TdxCustomContainerReportLinkOptionsTransparent* __fastcall OptionsTransparent(void)/* overload */;
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* Canvas = {read=GetCanvas};
	__property TdxPSCustomContainerItemDefinition* Definitions[System::Classes::TComponent* Component] = {read=GetDefinition};
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property TdxPSCustomProducer* Producers[System::Classes::TComponent* Component] = {read=GetProducer};
	__property int ScrollPosLeft = {read=GetScrollPosLeft, nodefault};
	__property int ScrollPosTop = {read=GetScrollPosTop, nodefault};
	
public:
	__fastcall virtual TdxPSCustomProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject);
	__classmethod virtual bool __fastcall CanHasAvailableChildren();
	__classmethod virtual bool __fastcall HasNativeSupportForBorders();
	__classmethod virtual bool __fastcall Reenterable();
	virtual TdxPSCustomContainerItemDefinition* __fastcall Definition(void)/* overload */;
	__classmethod virtual TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
	virtual void __fastcall Initialize(System::Classes::TComponent* AnObject);
	virtual System::Classes::TComponent* __fastcall ProducingObject(void)/* overload */;
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
	virtual TdxCustomContainerReportLink* __fastcall ReportLink(void)/* overload */;
	virtual void __fastcall Reposition(void);
	virtual Vcl::Controls::TWinControl* __fastcall RootContainer(void)/* overload */;
	virtual Vcl::Controls::TWinControl* __fastcall TopLevelRootContainer(void)/* overload */;
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomProducer(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxPSCustomContainerItemProducerClass;

class DELPHICLASS TdxPSCustomContainerItemProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomContainerItemProducer : public TdxPSCustomProducer
{
	typedef TdxPSCustomProducer inherited;
	
private:
	System::Types::TRect __fastcall GetControlBounds(void);
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	virtual _di_IdxPSContainerIterator __fastcall CreateIterator(void);
	virtual System::Uitypes::TColor __fastcall GetContentColor(void);
	virtual System::Types::TRect __fastcall GetControlBoundsRect(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual System::Uitypes::TColor __fastcall GetFontColor(void);
	virtual int __fastcall GetFontIndex(void);
	virtual System::UnicodeString __fastcall GetFontName(void);
	virtual System::Uitypes::TFontStyles __fastcall GetFontStyle(void);
	virtual bool __fastcall IsFontSubstitutable(void);
	virtual Dxpscore::TdxReportCellClass __fastcall HostClass(void);
	virtual void __fastcall InitializeHost(Dxpscore::TdxReportCell* ACell);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	virtual Vcl::Controls::TControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	HIDESBASE TdxPSContainerControlDefinition* __fastcall Definition(void)/* overload */;
	__classmethod virtual TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
	__classmethod virtual System::TClass __fastcall PairClass();
	HIDESBASE Vcl::Controls::TControl* __fastcall ProducingObject(void)/* overload */;
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
	__property System::Uitypes::TColor ContentColor = {read=GetContentColor, nodefault};
	__property System::Types::TRect ControlBounds = {read=GetControlBounds};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property System::Uitypes::TColor FontColor = {read=GetFontColor, nodefault};
	__property int FontIndex = {read=GetFontIndex, nodefault};
	__property System::UnicodeString FontName = {read=GetFontName};
	__property System::Uitypes::TFontStyles FontStyle = {read=GetFontStyle, nodefault};
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomContainerItemProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomContainerItemProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomDelegateProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomDelegateProducer : public TdxPSCustomContainerItemProducer
{
	typedef TdxPSCustomContainerItemProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual TdxPSCustomContainerItemProducer* __fastcall Producer(void) = 0 ;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomDelegateProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomContainerItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomDelegateProducer(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxPSNativePrintableControlProducerClass;

class DELPHICLASS TdxPSNativePrintableControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSNativePrintableControlProducer : public TdxPSCustomContainerItemProducer
{
	typedef TdxPSCustomContainerItemProducer inherited;
	
private:
	bool FIsOuterLinkUsed;
	
protected:
	virtual void __fastcall AdjustItemBounds(Dxpscore::TdxReportVisualItem* AnItem);
	Dxpscore::TBasedxReportLink* __fastcall CreateControlReportLink(bool &AIsOuterLinkUsed);
	void __fastcall CreateNativePrintableControlData(Dxpscore::TdxReportVisualItem* AItem);
	virtual void __fastcall DeinitializeReportLink(Dxpscore::TBasedxReportLink* AControlReportLink);
	__classmethod Dxpscore::TdxReportLinkClass __fastcall GetLinkClass(System::TClass AClass);
	__classmethod bool __fastcall HasReportLink(System::Classes::TComponent* AComponent);
	virtual void __fastcall InitializeReportLink(Dxpscore::TBasedxReportLink* AControlReportLink);
	virtual Dxpscore::TdxReportCellClass __fastcall HostClass(void);
	virtual void __fastcall InitializeHost(Dxpscore::TdxReportCell* ACell);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall InitializeNativePrintableControlHost(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual int __fastcall MeasureItemHeight(Dxpscore::TdxReportVisualItem* AnItem);
	virtual int __fastcall MeasureItemWidth(Dxpscore::TdxReportVisualItem* AnItem);
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
	__property bool IsOuterLinkUsed = {read=FIsOuterLinkUsed, nodefault};
	
public:
	__classmethod virtual bool __fastcall Reenterable();
	HIDESBASE TdxPSNativePrintableControlDefinition* __fastcall Definition(void)/* overload */;
	__classmethod virtual TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
	__classmethod virtual bool __fastcall HasNativeSupportForBorders();
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSNativePrintableControlProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomContainerItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSNativePrintableControlProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSContainerControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSContainerControlProducer : public TdxPSCustomContainerItemProducer
{
	typedef TdxPSCustomContainerItemProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSContainerControlProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomContainerItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSContainerControlProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSControlAsMetafileProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSControlAsMetafileProducer : public TdxPSContainerControlProducer
{
	typedef TdxPSContainerControlProducer inherited;
	
protected:
	__classmethod virtual TdxPSCustomProducerClass __fastcall BuddyClass();
	virtual Vcl::Graphics::TGraphic* __fastcall CreateControlImage(Dxpscore::TdxReportVisualItem* AItem);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	virtual void __fastcall Reposition(void);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSControlAsMetafileProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSControlAsMetafileProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSBevelProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSBevelProducer : public TdxPSContainerControlProducer
{
	typedef TdxPSContainerControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Extctrls::TBevel* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSBevelProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSBevelProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSPaintBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPaintBoxProducer : public TdxPSContainerControlProducer
{
	typedef TdxPSContainerControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Extctrls::TPaintBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSPaintBoxProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSPaintBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSShapeProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSShapeProducer : public TdxPSContainerControlProducer
{
	typedef TdxPSContainerControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Extctrls::TShape* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSShapeProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSShapeProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomLabelProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomLabelProducer : public TdxPSContainerControlProducer
{
	typedef TdxPSContainerControlProducer inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetControlBoundsRect(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
	
public:
	HIDESBASE Vcl::Stdctrls::TCustomLabel* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomLabelProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomLabelProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSContainerCustomWinControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSContainerCustomWinControlProducer : public TdxPSContainerControlProducer
{
	typedef TdxPSContainerControlProducer inherited;
	
protected:
	virtual _di_IdxPSContainerIterator __fastcall CreateIterator(void);
	virtual Dxpscore::TdxReportCellClass __fastcall HostClass(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	__classmethod virtual TdxPSWinControlIteratorClass __fastcall IteratorClass();
	
public:
	HIDESBASE Vcl::Controls::TWinControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	__classmethod virtual TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSContainerCustomWinControlProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSContainerCustomWinControlProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSWinControlAsMetafileProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSWinControlAsMetafileProducer : public TdxPSContainerCustomWinControlProducer
{
	typedef TdxPSContainerCustomWinControlProducer inherited;
	
protected:
	__classmethod virtual TdxPSCustomProducerClass __fastcall BuddyClass();
	virtual Vcl::Graphics::TGraphic* __fastcall CreateControlImage(Dxpscore::TdxReportVisualItem* AItem);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	__classmethod virtual System::TClass __fastcall PairClass();
	virtual void __fastcall Reposition(void);
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSWinControlAsMetafileProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerCustomWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSWinControlAsMetafileProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSContainerWinControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSContainerWinControlProducer : public TdxPSContainerCustomWinControlProducer
{
	typedef TdxPSContainerCustomWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual bool __fastcall ObjectExpandHeight(void);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSContainerWinControlProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerCustomWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSContainerWinControlProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSDateTimePickerProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSDateTimePickerProducer : public TdxPSContainerWinControlProducer
{
	typedef TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Comctrls::TDateTimePicker* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSDateTimePickerProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSDateTimePickerProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomHotKeyProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomHotKeyProducer : public TdxPSContainerWinControlProducer
{
	typedef TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Vcl::Comctrls::TCustomHotKey* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomHotKeyProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomHotKeyProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomStaticTextProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomStaticTextProducer : public TdxPSContainerWinControlProducer
{
	typedef TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Vcl::Stdctrls::TCustomStaticText* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomStaticTextProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomStaticTextProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomEditProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomEditProducer : public TdxPSContainerWinControlProducer
{
	typedef TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Vcl::Stdctrls::TCustomEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomEditProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomEditProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomMemoProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomMemoProducer : public TdxPSCustomEditProducer
{
	typedef TdxPSCustomEditProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual bool __fastcall ObjectExpandHeight(void);
	
public:
	HIDESBASE Vcl::Stdctrls::TCustomMemo* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomMemoProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomMemoProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomComboBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomComboBoxProducer : public TdxPSContainerWinControlProducer
{
	typedef TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Vcl::Stdctrls::TCustomComboBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomComboBoxProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomComboBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomComboBoxExProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomComboBoxExProducer : public TdxPSContainerWinControlProducer
{
	typedef TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Comctrls::TCustomComboBoxEx* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomComboBoxExProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomComboBoxExProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomCheckBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomCheckBoxProducer : public TdxPSContainerWinControlProducer
{
	typedef TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Stdctrls::TCustomCheckBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomCheckBoxProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomCheckBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSRadioButtonProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSRadioButtonProducer : public TdxPSContainerWinControlProducer
{
	typedef TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Stdctrls::TRadioButton* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSRadioButtonProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSRadioButtonProducer(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxPSCustomContainerProducerClass;

class DELPHICLASS TdxPSCustomContainerProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomContainerProducer : public TdxPSContainerCustomWinControlProducer
{
	typedef TdxPSContainerCustomWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
	virtual bool __fastcall ObjectShrinkHeight(void);
	virtual bool __fastcall ObjectShrinkWidth(void);
	
public:
	__classmethod virtual bool __fastcall CanHasAvailableChildren();
	__classmethod virtual TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomContainerProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSContainerCustomWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomContainerProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomPanelProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomPanelProducer : public TdxPSCustomContainerProducer
{
	typedef TdxPSCustomContainerProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
	
public:
	HIDESBASE Vcl::Extctrls::TCustomPanel* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	__classmethod virtual bool __fastcall HasNativeSupportForBorders();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomPanelProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomPanelProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomGroupBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomGroupBoxProducer : public TdxPSCustomContainerProducer
{
	typedef TdxPSCustomContainerProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	void __fastcall InitializeLookAndFeel(Dxpscore::TdxReportVisualItem* AnItem, Dxpscore::TdxPSReportGroupLookAndFeel* ALookAndFeel);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	__classmethod virtual Dxpscore::TdxPSReportGroupLookAndFeelClass __fastcall LookAndFeelClass();
	
public:
	HIDESBASE Vcl::Stdctrls::TCustomGroupBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	__classmethod virtual bool __fastcall HasNativeSupportForBorders();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomGroupBoxProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomGroupBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomRadioGroupProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomRadioGroupProducer : public TdxPSCustomGroupBoxProducer
{
	typedef TdxPSCustomGroupBoxProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	void __fastcall CreateItems(Dxpscore::TdxReportRadioGroup* AReportRadioGroup);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall InitializeRadioItem(Dxpscore::TdxCustomReportCellRadio* AnItem, int AnIndex);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	
public:
	HIDESBASE Vcl::Extctrls::TCustomRadioGroup* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomRadioGroupProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomGroupBoxProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomRadioGroupProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSRootContainerProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSRootContainerProducer : public TdxPSCustomContainerProducer
{
	typedef TdxPSCustomContainerProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSRootContainerProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSRootContainerProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTabControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTabControlProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
public:
	HIDESBASE Vcl::Comctrls::TTabControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSTabControlProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTabControlProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSPageControlIterator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPageControlIterator : public TdxPSWinControlIterator
{
	typedef TdxPSWinControlIterator inherited;
	
private:
	Vcl::Comctrls::TPageControl* __fastcall GetPageControl(void);
	
protected:
	virtual Vcl::Controls::TControl* __fastcall GetControl(int Index);
	virtual int __fastcall GetControlCount(void);
	
public:
	__property Vcl::Comctrls::TPageControl* PageControl = {read=GetPageControl};
public:
	/* TdxPSWinControlIterator.Create */ inline __fastcall virtual TdxPSPageControlIterator(Vcl::Controls::TWinControl* AControl) : TdxPSWinControlIterator(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSPageControlIterator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTabSheetProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTabSheetProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
public:
	HIDESBASE Vcl::Comctrls::TTabSheet* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSTabSheetProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTabSheetProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSPageControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPageControlProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	__classmethod virtual TdxPSWinControlIteratorClass __fastcall IteratorClass();
	
public:
	HIDESBASE Vcl::Comctrls::TPageControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSPageControlProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSPageControlProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSNotebookIterator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSNotebookIterator : public TdxPSWinControlIterator
{
	typedef TdxPSWinControlIterator inherited;
	
private:
	Vcl::Extctrls::TNotebook* __fastcall GetNotebook(void);
	
protected:
	virtual Vcl::Controls::TControl* __fastcall GetControl(int Index);
	virtual int __fastcall GetControlCount(void);
	
public:
	__property Vcl::Extctrls::TNotebook* Notebook = {read=GetNotebook};
public:
	/* TdxPSWinControlIterator.Create */ inline __fastcall virtual TdxPSNotebookIterator(Vcl::Controls::TWinControl* AControl) : TdxPSWinControlIterator(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSNotebookIterator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSNotebookPageProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSNotebookPageProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
public:
	HIDESBASE Vcl::Extctrls::TPage* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSNotebookPageProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSNotebookPageProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSNotebookProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSNotebookProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	__classmethod virtual TdxPSWinControlIteratorClass __fastcall IteratorClass();
	
public:
	HIDESBASE Vcl::Extctrls::TNotebook* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSNotebookProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSNotebookProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTabbedNotebookIterator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTabbedNotebookIterator : public TdxPSWinControlIterator
{
	typedef TdxPSWinControlIterator inherited;
	
private:
	Vcl::Tabnotbk::TTabbedNotebook* __fastcall GetTabbedNotebook(void);
	
protected:
	virtual Vcl::Controls::TControl* __fastcall GetControl(int Index);
	virtual int __fastcall GetControlCount(void);
	
public:
	__property Vcl::Tabnotbk::TTabbedNotebook* TabbedNotebook = {read=GetTabbedNotebook};
public:
	/* TdxPSWinControlIterator.Create */ inline __fastcall virtual TdxPSTabbedNotebookIterator(Vcl::Controls::TWinControl* AControl) : TdxPSWinControlIterator(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTabbedNotebookIterator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTabbedNotebookPageProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTabbedNotebookPageProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
public:
	HIDESBASE Vcl::Tabnotbk::TTabPage* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSTabbedNotebookPageProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTabbedNotebookPageProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTabbedNotebookProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTabbedNotebookProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	__classmethod virtual TdxPSWinControlIteratorClass __fastcall IteratorClass();
	
public:
	HIDESBASE Vcl::Tabnotbk::TTabbedNotebook* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSTabbedNotebookProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTabbedNotebookProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSScrollingWinControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSScrollingWinControlProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
protected:
	virtual int __fastcall GetScrollBarPos(Vcl::Forms::TControlScrollBar* AScrollBar);
	virtual int __fastcall GetScrollPosLeft(void);
	virtual int __fastcall GetScrollPosTop(void);
	virtual void __fastcall InitializeHost(Dxpscore::TdxReportCell* ACell);
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
	
public:
	HIDESBASE Vcl::Forms::TScrollingWinControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSScrollingWinControlProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSScrollingWinControlProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxScrollBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxScrollBoxProducer : public TdxPSRootContainerProducer
{
	typedef TdxPSRootContainerProducer inherited;
	
protected:
	virtual int __fastcall GetScrollBarPos(Cxscrollbox::TcxScrollBoxScrollBarOptions* AScrollBar);
	virtual int __fastcall GetScrollPosLeft(void);
	virtual int __fastcall GetScrollPosTop(void);
	virtual void __fastcall InitializeHost(Dxpscore::TdxReportCell* ACell);
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
	
public:
	HIDESBASE Cxscrollbox::TcxCustomScrollBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxScrollBoxProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxScrollBoxProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomFrameProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomFrameProducer : public TdxPSScrollingWinControlProducer
{
	typedef TdxPSScrollingWinControlProducer inherited;
	
public:
	HIDESBASE Vcl::Forms::TCustomFrame* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomFrameProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSScrollingWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomFrameProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomFormProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomFormProducer : public TdxPSScrollingWinControlProducer
{
	typedef TdxPSScrollingWinControlProducer inherited;
	
public:
	HIDESBASE Vcl::Forms::TCustomForm* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomFormProducer(TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSScrollingWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomFormProducer(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxPSContainerBuilderClass;

class DELPHICLASS TdxPSContainerBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSContainerBuilder : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
private:
	Vcl::Controls::TWinControl* FContainer;
	Vcl::Controls::TControl* FCurrentControl;
	Dxpscore::TdxReportCell* FHost;
	TdxPSContainerBuilder* FParentBuilder;
	Dxpscore::TdxReportCell* FParentHost;
	TdxCustomContainerReportLink* FReportLink;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetCanvas(void);
	bool __fastcall GetIsRoot(void);
	TdxPSCustomContainerItemProducer* __fastcall GetProducer(Vcl::Controls::TControl* AControl);
	
protected:
	void __fastcall BuildNestedControls(void);
	virtual Dxpscore::TdxReportCell* __fastcall CreateHost(void);
	TdxPSCustomContainerItemDefinition* __fastcall CreateItemDefinition(System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AnItem);
	virtual _di_IdxPSContainerIterator __fastcall CreateNestedControlsIterator(void);
	virtual Dxpscore::TdxReportCell* __fastcall GetParentHost(void);
	virtual bool __fastcall HasAvailableChildren(Vcl::Controls::TControl* AControl);
	virtual void __fastcall InitializeHost(void);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	bool __fastcall IsAborted(void);
	void __fastcall Progress(const double APercentDone);
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* Canvas = {read=GetCanvas};
	__property Vcl::Controls::TControl* CurrentControl = {read=FCurrentControl};
	__property TdxPSCustomContainerItemProducer* Producers[Vcl::Controls::TControl* AControl] = {read=GetProducer};
	
public:
	__fastcall virtual TdxPSContainerBuilder(TdxCustomContainerReportLink* AReportLink, Vcl::Controls::TWinControl* AContainer, TdxPSContainerBuilder* AParentBuilder, Dxpscore::TdxReportCell* AParentHost);
	__fastcall virtual ~TdxPSContainerBuilder(void);
	virtual Dxpscore::TdxReportCell* __fastcall Build(void);
	Dxpscore::TdxReportVisualItem* __fastcall BuildControl(Vcl::Controls::TControl* AControl, Dxpscore::TdxReportCell* AParentHost = (Dxpscore::TdxReportCell*)(0x0));
	Dxpscore::TdxReportCell* __fastcall BuildNestedContainer(Vcl::Controls::TWinControl* AContainer, Dxpscore::TdxReportCell* AParentHost = (Dxpscore::TdxReportCell*)(0x0));
	__classmethod virtual Vcl::Controls::TWinControlClass __fastcall ContainerClass();
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__property Vcl::Controls::TWinControl* Container = {read=FContainer};
	__property Dxpscore::TdxReportCell* Host = {read=FHost};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property TdxPSContainerBuilder* ParentBuilder = {read=FParentBuilder};
	__property Dxpscore::TdxReportCell* ParentHost = {read=GetParentHost};
	__property TdxCustomContainerReportLink* ReportLink = {read=FReportLink};
};

#pragma pack(pop)

class DELPHICLASS TdxPSContainerReportLinkCustomCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSContainerReportLinkCustomCache : public Dxbase::TdxCustomCache
{
	typedef Dxbase::TdxCustomCache inherited;
	
private:
	TdxCustomContainerReportLink* FReportLink;
	
public:
	__fastcall virtual TdxPSContainerReportLinkCustomCache(TdxCustomContainerReportLink* AReportLink);
	virtual TdxCustomContainerReportLink* __fastcall ReportLink(void)/* overload */;
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TdxPSContainerReportLinkCustomCache(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCustomProducerCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCustomProducerCache : public TdxPSContainerReportLinkCustomCache
{
	typedef TdxPSContainerReportLinkCustomCache inherited;
	
private:
	HIDESBASE TdxPSCustomProducer* __fastcall GetItem(int Index);
	TdxPSCustomProducer* __fastcall GetProducer(TdxPSCustomProducerClass ProducerClass, System::Classes::TComponent* Component);
	
protected:
	__property TdxPSCustomProducer* Items[int Index] = {read=GetItem};
	
public:
	__property TdxPSCustomProducer* Producers[TdxPSCustomProducerClass ProducerClass][System::Classes::TComponent* Component] = {read=GetProducer/*, default*/};
public:
	/* TdxPSContainerReportLinkCustomCache.Create */ inline __fastcall virtual TdxPSCustomProducerCache(TdxCustomContainerReportLink* AReportLink) : TdxPSContainerReportLinkCustomCache(AReportLink) { }
	
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TdxPSCustomProducerCache(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomContainerReportLinkOptionsClass;

class DELPHICLASS TdxCustomContainerReportLinkOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomContainerReportLinkOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxCustomContainerReportLink* FReportLink;
	
protected:
	DYNAMIC void __fastcall Changed(void);
	
public:
	__fastcall virtual TdxCustomContainerReportLinkOptions(TdxCustomContainerReportLink* AReportLink);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TdxCustomContainerReportLink* ReportLink = {read=FReportLink};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomContainerReportLinkOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomContainerReportLinkOptionsBehaviorClass;

class DELPHICLASS TdxCustomContainerReportLinkOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomContainerReportLinkOptionsBehavior : public TdxCustomContainerReportLinkOptions
{
	typedef TdxCustomContainerReportLinkOptions inherited;
	
private:
	bool FConsumeExistingLinks;
	bool FLabelAutoHeight;
	void __fastcall SetConsumeExistingLinks(bool Value);
	void __fastcall SetLabelAutoHeight(bool AValue);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool ConsumeExistingLinks = {read=FConsumeExistingLinks, write=SetConsumeExistingLinks, default=1};
	__property bool LabelAutoHeight = {read=FLabelAutoHeight, write=SetLabelAutoHeight, default=1};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxCustomContainerReportLinkOptionsBehavior(TdxCustomContainerReportLink* AReportLink) : TdxCustomContainerReportLinkOptions(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomContainerReportLinkOptionsBehavior(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomContainerReportLinkOptionsDesignerTabsClass;

class DELPHICLASS TdxCustomContainerReportLinkOptionsDesignerTabs;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomContainerReportLinkOptionsDesignerTabs : public TdxCustomContainerReportLinkOptions
{
	typedef TdxCustomContainerReportLinkOptions inherited;
	
private:
	bool FAutoHideReportLinksIfEmpty;
	bool FBehaviors;
	bool FControls;
	bool FReportLinks;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool AutoHideReportLinksIfEmpty = {read=FAutoHideReportLinksIfEmpty, write=FAutoHideReportLinksIfEmpty, default=1};
	__property bool Behaviors = {read=FBehaviors, write=FBehaviors, default=0};
	__property bool Controls = {read=FControls, write=FControls, default=1};
	__property bool ReportLinks = {read=FReportLinks, write=FReportLinks, default=1};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxCustomContainerReportLinkOptionsDesignerTabs(TdxCustomContainerReportLink* AReportLink) : TdxCustomContainerReportLinkOptions(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomContainerReportLinkOptionsDesignerTabs(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomContainerReportLinkOptionsItemPlace : public TdxCustomContainerReportLinkOptions
{
	typedef TdxCustomContainerReportLinkOptions inherited;
	
private:
	bool FExpandHeight;
	bool FExpandWidth;
	bool FShrinkHeight;
	bool FShrinkWidth;
	
protected:
	virtual int __fastcall GetData(void);
	virtual void __fastcall SetData(int Value);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	bool __fastcall HasHorzResizing(void);
	bool __fastcall HasVertResizing(void);
	void __fastcall SetAll(void);
	void __fastcall UnsetAll(void);
	
__published:
	__property bool ExpandHeight = {read=FExpandHeight, write=FExpandHeight, default=0};
	__property bool ExpandWidth = {read=FExpandWidth, write=FExpandWidth, default=0};
	__property bool ShrinkHeight = {read=FShrinkHeight, write=FShrinkHeight, default=0};
	__property bool ShrinkWidth = {read=FShrinkWidth, write=FShrinkWidth, default=0};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxCustomContainerReportLinkOptionsItemPlace(TdxCustomContainerReportLink* AReportLink) : TdxCustomContainerReportLinkOptions(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomContainerReportLinkOptionsItemPlace(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomContainerReportLinkOptionsPagination : public TdxCustomContainerReportLinkOptions
{
	typedef TdxCustomContainerReportLinkOptions inherited;
	
private:
	bool FControlDetails;
	bool FControls;
	void __fastcall SetControlDetails(bool Value);
	void __fastcall SetControls(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool ControlDetails = {read=FControlDetails, write=SetControlDetails, default=1};
	__property bool Controls = {read=FControls, write=SetControls, default=1};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxCustomContainerReportLinkOptionsPagination(TdxCustomContainerReportLink* AReportLink) : TdxCustomContainerReportLinkOptions(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomContainerReportLinkOptionsPagination(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomContainerReportLinkOptionsRefinementsClass;

class DELPHICLASS TdxCustomContainerReportLinkOptionsRefinements;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomContainerReportLinkOptionsRefinements : public TdxCustomContainerReportLinkOptions
{
	typedef TdxCustomContainerReportLinkOptions inherited;
	
private:
	bool FRootBorders;
	void __fastcall SetRootBorders(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool RootBorders = {read=FRootBorders, write=SetRootBorders, default=0};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxCustomContainerReportLinkOptionsRefinements(TdxCustomContainerReportLink* AReportLink) : TdxCustomContainerReportLinkOptions(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomContainerReportLinkOptionsRefinements(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomContainerReportLinkOptionsTransparent : public TdxCustomContainerReportLinkOptions
{
	typedef TdxCustomContainerReportLinkOptions inherited;
	
private:
	bool FContainers;
	bool FControls;
	bool FGraphics;
	bool FRoot;
	void __fastcall SetContainters(bool Value);
	void __fastcall SetControls(bool Value);
	void __fastcall SetGraphics(bool Value);
	void __fastcall SetRoot(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool Containers = {read=FContainers, write=SetContainters, default=1};
	__property bool Controls = {read=FControls, write=SetControls, default=1};
	__property bool Graphics = {read=FGraphics, write=SetGraphics, default=0};
	__property bool Root = {read=FRoot, write=SetRoot, default=1};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxCustomContainerReportLinkOptionsTransparent(TdxCustomContainerReportLink* AReportLink) : TdxCustomContainerReportLinkOptions(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomContainerReportLinkOptionsTransparent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNodeObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNodeObject : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString Caption;
	System::Classes::TComponent* Component;
	Vcl::Stdctrls::TCheckBoxState State;
public:
	/* TObject.Create */ inline __fastcall TdxNodeObject(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNodeObject(void) { }
	
};

#pragma pack(pop)

enum TdxPSReportLinkProcessingStage : unsigned char { psBefore, psAfter };

typedef void __fastcall (__closure *TdxContainerReportLinkCustomDrawItemEvent)(TdxCustomContainerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TAbstractdxReportCellData* AnItem, System::Classes::TComponent* AComponent, bool &ADone);

typedef void __fastcall (__closure *TdxContainerReportLinkGetComponentReportLinkEvent)(TdxCustomContainerReportLink* Sender, System::Classes::TComponent* AComponent, Dxpscore::TBasedxReportLink* &AReportLink);

typedef void __fastcall (__closure *TdxContainerReportLinkGetComponentCaptionEvent)(TdxCustomContainerReportLink* Sender, System::Classes::TComponent* AComponent, System::UnicodeString &ACaption);

typedef void __fastcall (__closure *TdxContainerReportLinkInitializeItemEvent)(TdxCustomContainerReportLink* Sender, Dxpscore::TdxReportVisualItem* AnItem, System::Classes::TComponent* AComponent);

typedef void __fastcall (__closure *TdxContainerReportLinkInitializeItemOptionsPlaceEvent)(TdxCustomContainerReportLink* Sender, Dxpscore::TdxReportVisualItem* AnItem, System::Classes::TComponent* AComponent, TdxCustomContainerReportLinkOptionsItemPlace* AOptionsPlace);

typedef void __fastcall (__closure *TdxContainerReportLinkInitializeReportLinkEvent)(TdxCustomContainerReportLink* Sender, Dxpscore::TBasedxReportLink* AReportLink, TdxPSReportLinkProcessingStage AStage);

typedef void __fastcall (__closure *TdxContainerReportLinkIsComponentProcessedEvent)(TdxCustomContainerReportLink* Sender, System::Classes::TComponent* AComponent, bool &AIsProcessed);

class DELPHICLASS TdxfmCustomContainerDesignWindow;
class PASCALIMPLEMENTATION TdxCustomContainerReportLink : public Dxpscore::TBasedxReportLink
{
	typedef Dxpscore::TBasedxReportLink inherited;
	
private:
	TdxPSContainerBuilder* FActiveBuilder;
	System::Classes::TStrings* FAggregatedReportLinks;
	System::Classes::TList* FDefinitions;
	System::Classes::TList* FDelimitersHorz;
	System::Classes::TList* FDelimitersVert;
	System::Classes::TStrings* FExcludedComponents;
	System::Classes::TStrings* FHiddenComponents;
	TdxCustomContainerReportLinkOptionsBehavior* FOptionsBehavior;
	TdxCustomContainerReportLinkOptionsDesignerTabs* FOptionsDesignerTabs;
	TdxCustomContainerReportLinkOptionsPagination* FOptionsPagination;
	TdxCustomContainerReportLinkOptionsRefinements* FOptionsRefinements;
	TdxCustomContainerReportLinkOptionsTransparent* FOptionsTransparent;
	Vcl::Graphics::TFont* FPreparationFont;
	TdxPSCustomProducerCache* FProducerCache;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* FScreenCanvas;
	bool FSupportedCustomDraw;
	TdxContainerReportLinkCustomDrawItemEvent FOnCustomDrawItem;
	TdxContainerReportLinkGetComponentCaptionEvent FOnGetComponentCaption;
	TdxContainerReportLinkGetComponentReportLinkEvent FOnGetComponentReportLink;
	TdxContainerReportLinkInitializeItemEvent FOnInitializeItem;
	TdxContainerReportLinkInitializeItemOptionsPlaceEvent FOnInitializeItemOptionsPlace;
	TdxContainerReportLinkInitializeReportLinkEvent FOnInitializeReportLink;
	TdxContainerReportLinkIsComponentProcessedEvent FOnIsComponentProcessed;
	Dxpscore::TBasedxReportLink* __fastcall GetAggregatedReportLink(int Index);
	int __fastcall GetAggregatedReportLinkCount(void);
	Vcl::Controls::TWinControl* __fastcall GetContainer(void);
	TdxCustomContainerReportLink* __fastcall GetController(void);
	TdxPSCustomContainerItemDefinition* __fastcall GetDefinition(int Index);
	TdxPSCustomContainerItemDefinition* __fastcall GetDefinitionByContainerItem(System::Classes::TComponent* Component);
	TdxPSCustomContainerItemDefinition* __fastcall GetDefinitionByReportItem(Dxpscore::TdxReportVisualItem* Item);
	int __fastcall GetDefinitionCount(void);
	int __fastcall GetDelimitersHorzCount(void);
	int __fastcall GetDelimitersHorzItem(int Index);
	int __fastcall GetDelimitersVertCount(void);
	int __fastcall GetDelimitersVertItem(int Index);
	TdxfmCustomContainerDesignWindow* __fastcall GetDesignWindow(void);
	System::Classes::TComponent* __fastcall GetExcludedComponent(int Index);
	int __fastcall GetExcludedComponentCount(void);
	System::Classes::TComponent* __fastcall GetHiddenComponent(int Index);
	int __fastcall GetHiddenComponentCount(void);
	TdxPSCustomProducer* __fastcall GetProducerByClass(TdxPSCustomProducerClass ProducerClass, System::Classes::TComponent* Component);
	Dxpscore::TdxReportCell* __fastcall GetRootCell(void);
	Vcl::Controls::TWinControl* __fastcall GetTopLevelContainer(void);
	void __fastcall SetController(TdxCustomContainerReportLink* Value);
	void __fastcall SetOnCustomDrawItem(TdxContainerReportLinkCustomDrawItemEvent Value);
	void __fastcall SetOptionsBehavior(TdxCustomContainerReportLinkOptionsBehavior* Value);
	void __fastcall SetOptionsDesignerTabs(TdxCustomContainerReportLinkOptionsDesignerTabs* Value);
	void __fastcall SetOptionsPagination(TdxCustomContainerReportLinkOptionsPagination* Value);
	void __fastcall SetOptionsRefinements(TdxCustomContainerReportLinkOptionsRefinements* Value);
	void __fastcall SetOptionsTransparent(TdxCustomContainerReportLinkOptionsTransparent* Value);
	void __fastcall SetSupportedCustomDraw(bool Value);
	void __fastcall LoadAggregatedReportLinks(void);
	void __fastcall ReadAggregatedReportLinks(System::Classes::TStream* Stream);
	void __fastcall WriteAggregatedReportLinks(System::Classes::TStream* Stream);
	void __fastcall LoadExcludedComponents(void);
	void __fastcall ReadExcludedComponents(System::Classes::TStream* Stream);
	void __fastcall WriteExcludedComponents(System::Classes::TStream* Stream);
	void __fastcall LoadHiddenComponents(void);
	void __fastcall ReadHiddenComponents(System::Classes::TStream* Stream);
	void __fastcall WriteHiddenComponents(System::Classes::TStream* Stream);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall AfterDesignReport(bool ADone);
	virtual void __fastcall BeforeDesignReport(void);
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall ConvertCoords(void);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABoundsRect, const System::Types::TRect &AClientRect, bool &ADone);
	virtual void __fastcall DoApplyInDesigner(void);
	DYNAMIC void __fastcall DoChangeComponent(void);
	virtual Dxpscore::TdxReportLinkDesignWindowClass __fastcall GetDesignerClass(void);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	virtual void __fastcall MakeDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	Dxpscore::TdxReportCell* __fastcall BuildContainer(Vcl::Controls::TWinControl* AContainer, TdxPSContainerBuilder* AParentBuilder, Dxpscore::TdxReportCell* AParentHost = (Dxpscore::TdxReportCell*)(0x0));
	TdxPSContainerBuilder* __fastcall CreateBuilder(Vcl::Controls::TWinControl* AContainer, TdxPSContainerBuilder* AParentBuilder, Dxpscore::TdxReportCell* AParentHost = (Dxpscore::TdxReportCell*)(0x0));
	TdxPSCustomContainerItemDefinition* __fastcall CreateItemDefinition(System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AnItem);
	TdxPSCustomProducer* __fastcall GetProducer(System::Classes::TComponent* Component);
	virtual System::Types::TRect __fastcall GetControlSiteBounds(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall DoCustomDrawItem(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoGetComponentCaption(System::Classes::TComponent* AComponent, System::UnicodeString &ACaption);
	DYNAMIC Dxpscore::TBasedxReportLink* __fastcall DoGetReportLink(System::Classes::TComponent* AComponent);
	DYNAMIC void __fastcall DoInitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	DYNAMIC void __fastcall DoInitializeItemOptionsPlace(Dxpscore::TdxReportVisualItem* AnItem);
	DYNAMIC void __fastcall DoInitializeReportLink(Dxpscore::TBasedxReportLink* AReportLink, TdxPSReportLinkProcessingStage AStage);
	DYNAMIC bool __fastcall DoIsComponentProcessed(System::Classes::TComponent* AComponent);
	virtual void __fastcall PrepareConstruct(void);
	virtual void __fastcall UnprepareConstruct(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	DYNAMIC TdxCustomContainerReportLinkOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	DYNAMIC TdxCustomContainerReportLinkOptionsDesignerTabsClass __fastcall GetOptionsDesignerTabsClass(void);
	DYNAMIC TdxCustomContainerReportLinkOptionsItemPlaceClass __fastcall GetOptionsItemPlaceClass(void);
	DYNAMIC TdxCustomContainerReportLinkOptionsPaginationClass __fastcall GetOptionsPaginationClass(void);
	DYNAMIC TdxCustomContainerReportLinkOptionsRefinementsClass __fastcall GetOptionsRefinementsClass(void);
	DYNAMIC TdxCustomContainerReportLinkOptionsTransparentClass __fastcall GetOptionsTransparentClass(void);
	DYNAMIC void __fastcall OptionsModified(TdxCustomContainerReportLinkOptions* AnOptions);
	void __fastcall AddDefinition(TdxPSCustomContainerItemDefinition* ADefinition);
	void __fastcall ClearDefinitions(void);
	void __fastcall DeleteDefinition(int Index);
	bool __fastcall FindDefinition(System::Classes::TComponent* AComponent, /* out */ int &AnIndex)/* overload */;
	bool __fastcall FindDefinition(Dxpscore::TdxReportVisualItem* AnItem, /* out */ int &AnIndex)/* overload */;
	void __fastcall FreeAndNilDefinitions(void);
	void __fastcall AddControl(Vcl::Comctrls::TTreeView* ATreeView, Vcl::Comctrls::TTreeNode* AParent, Vcl::Controls::TControl* AControl);
	void __fastcall AddHiddenControl(Vcl::Comctrls::TTreeView* ATreeView, Vcl::Comctrls::TTreeNode* AParent, Vcl::Controls::TControl* AControl);
	Vcl::Comctrls::TTreeNode* __fastcall AddNode(Vcl::Comctrls::TTreeView* ATreeView, Vcl::Comctrls::TTreeNode* AParent, System::Classes::TComponent* AComponent, bool AChecked);
	virtual TdxNodeObject* __fastcall CreateNodeObject(System::Classes::TComponent* AComponent, bool AChecked);
	virtual bool __fastcall IsComponentEditable(System::Classes::TComponent* AComponent);
	virtual void __fastcall LoadControlsTree(Vcl::Comctrls::TTreeView* ATreeView);
	virtual void __fastcall LoadHiddenControlsTree(Vcl::Comctrls::TTreeView* ATreeView);
	void __fastcall InstallAggregatedReportLinksController(bool AnInstall);
	System::Classes::TComponent* __fastcall GetComponentByName(const System::UnicodeString AName);
	int __fastcall GetPreparedFontIndex(Vcl::Graphics::TFont* AFont)/* overload */;
	int __fastcall GetPreparedFontIndex(Vcl::Graphics::TFont* AFont, bool AnIsFontSubstitutable, const System::UnicodeString AFontName, System::Uitypes::TColor AFontColor, System::Uitypes::TFontStyles AFontStyle)/* overload */;
	bool __fastcall IsComponentProcessed(System::Classes::TComponent* AComponent);
	virtual void __fastcall AddDelimiters(void);
	virtual void __fastcall CreateRootLookAndFeel(void);
	virtual void __fastcall HideDesignerTabs(TdxfmCustomContainerDesignWindow* ADesignWindow);
	virtual void __fastcall PullReportItems(void);
	virtual void __fastcall RepositionControls(void);
	virtual bool __fastcall NeedTwoPassRendering(void);
	virtual bool __fastcall IsScaleGridLines(void);
	__property TdxPSContainerBuilder* ActiveBuilder = {read=FActiveBuilder};
	__property TdxCustomContainerReportLink* Controller = {read=GetController, write=SetController};
	__property int DefinitionCount = {read=GetDefinitionCount, nodefault};
	__property TdxPSCustomContainerItemDefinition* Definitions[int Index] = {read=GetDefinition};
	__property TdxPSCustomContainerItemDefinition* DefinitionsByContainerItem[System::Classes::TComponent* Component] = {read=GetDefinitionByContainerItem};
	__property TdxPSCustomContainerItemDefinition* DefinitionsByReportItem[Dxpscore::TdxReportVisualItem* Item] = {read=GetDefinitionByReportItem};
	__property System::Classes::TList* DelimitersHorz = {read=FDelimitersHorz};
	__property int DelimitersHorzCount = {read=GetDelimitersHorzCount, nodefault};
	__property int DelimitersHorzItems[int Index] = {read=GetDelimitersHorzItem};
	__property System::Classes::TList* DelimitersVert = {read=FDelimitersVert};
	__property int DelimitersVertCount = {read=GetDelimitersVertCount, nodefault};
	__property int DelimitersVertItems[int Index] = {read=GetDelimitersVertItem};
	__property Vcl::Graphics::TFont* PreparationFont = {read=FPreparationFont};
	__property TdxPSCustomProducerCache* ProducerCache = {read=FProducerCache};
	__property TdxPSCustomProducer* Producers[System::Classes::TComponent* Component] = {read=GetProducer};
	__property Dxpscore::TdxReportCell* RootCell = {read=GetRootCell};
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ScreenCanvas = {read=FScreenCanvas};
	
public:
	__fastcall virtual TdxCustomContainerReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomContainerReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
	bool __fastcall CanHideComponent(System::Classes::TComponent* AComponent);
	bool __fastcall CanHideComponentByName(const System::UnicodeString AName);
	void __fastcall HideComponent(System::Classes::TComponent* AComponent);
	void __fastcall HideComponentByName(const System::UnicodeString AName);
	void __fastcall HideComponents(System::Classes::TComponent* const *AComponents, const int AComponents_Size);
	void __fastcall HideComponentsByName(System::UnicodeString const *ANames, const int ANames_Size);
	bool __fastcall FindHiddenComponent(System::Classes::TComponent* AComponent, /* out */ int &AnIndex)/* overload */;
	bool __fastcall FindHiddenComponent(System::Classes::TComponent* AComponent)/* overload */;
	bool __fastcall FindHiddenComponentByName(const System::UnicodeString AName, /* out */ int &AnIndex)/* overload */;
	bool __fastcall FindHiddenComponentByName(const System::UnicodeString AName)/* overload */;
	void __fastcall UnhideAllComponents(void);
	void __fastcall UnhideComponent(System::Classes::TComponent* AComponent);
	void __fastcall UnhideComponentByName(const System::UnicodeString AName);
	void __fastcall UnhideComponents(System::Classes::TComponent* const *AComponents, const int AComponents_Size);
	void __fastcall UnhideComponentsByName(System::UnicodeString const *ANames, const int ANames_Size);
	void __fastcall HideStandardControls(void);
	void __fastcall UnhideStandardControls(void);
	bool __fastcall CanExcludeComponent(System::Classes::TComponent* AComponent);
	bool __fastcall CanExcludeComponentByName(const System::UnicodeString AName);
	void __fastcall ExcludeComponent(System::Classes::TComponent* AComponent);
	void __fastcall ExcludeComponentByName(const System::UnicodeString AName);
	void __fastcall ExcludeComponents(System::Classes::TComponent* const *AComponents, const int AComponents_Size);
	void __fastcall ExcludeComponentsByName(System::UnicodeString const *ANames, const int ANames_Size);
	bool __fastcall FindExcludedComponent(System::Classes::TComponent* AComponent, /* out */ int &AnIndex)/* overload */;
	bool __fastcall FindExcludedComponent(System::Classes::TComponent* AComponent)/* overload */;
	bool __fastcall FindExcludedComponentByName(const System::UnicodeString AName, /* out */ int &AnIndex)/* overload */;
	bool __fastcall FindExcludedComponentByName(const System::UnicodeString AName)/* overload */;
	void __fastcall UnexcludeAllComponents(void);
	void __fastcall UnexcludeComponent(System::Classes::TComponent* AComponent);
	void __fastcall UnexcludeComponentByName(const System::UnicodeString AName);
	void __fastcall UnexcludeComponents(System::Classes::TComponent* const *AComponents, const int AComponents_Size);
	void __fastcall UnexcludeComponentsByName(System::UnicodeString const *ANames, const int ANames_Size);
	void __fastcall AggregateLink(Dxpscore::TBasedxReportLink* AReportLink);
	void __fastcall DisaggregateAllLinks(void);
	void __fastcall DisaggregateInconsistentLinks(void);
	void __fastcall DisaggregateLink(Dxpscore::TBasedxReportLink* AReportLink);
	Dxpscore::TBasedxReportLink* __fastcall FindAggregatedLinkByComponent(System::Classes::TComponent* AComponent);
	bool __fastcall HasInconsistentlyAggregatedLinks(void);
	bool __fastcall IsLinkAggregable(Dxpscore::TBasedxReportLink* AReportLink);
	bool __fastcall IsLinkAggregated(Dxpscore::TBasedxReportLink* AReportLink);
	bool __fastcall IsLinkAggregatedConsistently(Dxpscore::TBasedxReportLink* AReportLink);
	__property int AggregatedReportLinkCount = {read=GetAggregatedReportLinkCount, nodefault};
	__property Dxpscore::TBasedxReportLink* AggregatedReportLinks[int Index] = {read=GetAggregatedReportLink};
	__property Vcl::Controls::TWinControl* Container = {read=GetContainer};
	__property TdxfmCustomContainerDesignWindow* DesignWindow = {read=GetDesignWindow};
	__property int ExcludedComponentCount = {read=GetExcludedComponentCount, nodefault};
	__property System::Classes::TComponent* ExcludedComponents[int Index] = {read=GetExcludedComponent};
	__property int HiddenComponentCount = {read=GetHiddenComponentCount, nodefault};
	__property System::Classes::TComponent* HiddenComponents[int Index] = {read=GetHiddenComponent};
	__property TdxPSCustomProducer* ProducersByClass[TdxPSCustomProducerClass ProducerClass][System::Classes::TComponent* Component] = {read=GetProducerByClass};
	__property Vcl::Controls::TWinControl* TopLevelContainer = {read=GetTopLevelContainer};
	
__published:
	__property Color = {default=16777215};
	__property Font;
	__property TdxCustomContainerReportLinkOptionsBehavior* OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior};
	__property TdxCustomContainerReportLinkOptionsDesignerTabs* OptionsDesignerTabs = {read=FOptionsDesignerTabs, write=SetOptionsDesignerTabs};
	__property TdxCustomContainerReportLinkOptionsPagination* OptionsPagination = {read=FOptionsPagination, write=SetOptionsPagination};
	__property TdxCustomContainerReportLinkOptionsRefinements* OptionsRefinements = {read=FOptionsRefinements, write=SetOptionsRefinements};
	__property TdxCustomContainerReportLinkOptionsTransparent* OptionsTransparent = {read=FOptionsTransparent, write=SetOptionsTransparent};
	__property ScaleFonts = {default=1};
	__property bool SupportedCustomDraw = {read=FSupportedCustomDraw, write=SetSupportedCustomDraw, default=0};
	__property TdxContainerReportLinkCustomDrawItemEvent OnCustomDrawItem = {read=FOnCustomDrawItem, write=SetOnCustomDrawItem};
	__property TdxContainerReportLinkGetComponentCaptionEvent OnGetComponentCaption = {read=FOnGetComponentCaption, write=FOnGetComponentCaption};
	__property TdxContainerReportLinkGetComponentReportLinkEvent OnGetComponentReportLink = {read=FOnGetComponentReportLink, write=FOnGetComponentReportLink};
	__property TdxContainerReportLinkInitializeItemEvent OnInitializeItem = {read=FOnInitializeItem, write=FOnInitializeItem};
	__property TdxContainerReportLinkInitializeItemOptionsPlaceEvent OnInitializeItemOptionsPlace = {read=FOnInitializeItemOptionsPlace, write=FOnInitializeItemOptionsPlace};
	__property TdxContainerReportLinkInitializeReportLinkEvent OnInitializeReportLink = {read=FOnInitializeReportLink, write=FOnInitializeReportLink};
	__property TdxContainerReportLinkIsComponentProcessedEvent OnIsComponentProcessed = {read=FOnIsComponentProcessed, write=FOnIsComponentProcessed};
private:
	void *__IdxReportLinkController;	/* Dxpscore::IdxReportLinkController */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {120F53E4-1B09-46EF-B42D-04AB8BBCC374}
	operator Dxpscore::_di_IdxReportLinkController()
	{
		Dxpscore::_di_IdxReportLinkController intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscore::IdxReportLinkController*(void) { return (Dxpscore::IdxReportLinkController*)&__IdxReportLinkController; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IdxReportLinkController; }
	#endif
	
};


class PASCALIMPLEMENTATION TdxfmCustomContainerDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Cxpc::TcxTabSheet* tshReportLinks;
	Cxpc::TcxTabSheet* tshControls;
	Vcl::Menus::TPopupMenu* pmControls;
	Vcl::Menus::TMenuItem* miControlsCheckAll;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Menus::TMenuItem* miControlsCheckAllChildren;
	Vcl::Menus::TMenuItem* miControlsUncheckAllChildren;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miControlsExpandAll;
	Vcl::Extctrls::TImage* imgExpanding;
	Vcl::Extctrls::TImage* imgPagination;
	Cxpc::TcxTabSheet* tshHiddenControls;
	Vcl::Menus::TMenuItem* miControlsUncheckStandardControls;
	Vcl::Menus::TMenuItem* miControlsCheckStandardControls;
	Vcl::Menus::TMenuItem* miLine3;
	Vcl::Extctrls::TImage* imgSize;
	Cxcheckbox::TcxCheckBox* chbxTransparentRoot;
	Cxcheckbox::TcxCheckBox* chbxTransparentControls;
	Cxcheckbox::TcxCheckBox* chbxTransparentContainers;
	Cxcheckbox::TcxCheckBox* chbxTransparentGraphics;
	Cxcheckbox::TcxCheckBox* chbxTransparentGroups;
	Cxcheckbox::TcxCheckBox* chbxTransparentItems;
	Cxcheckbox::TcxCheckBox* chbxPaginateByControlDetails;
	Cxcheckbox::TcxCheckBox* chbxPaginateByControls;
	Cxcheckbox::TcxCheckBox* chbxPaginateByGroups;
	Cxcheckbox::TcxCheckBox* chbxPaginateByItems;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxlabel::TcxLabel* lblTransparents;
	Cxlabel::TcxLabel* lblPagination;
	Cxlabel::TcxLabel* lblSize;
	Cxbuttons::TcxButton* btnControlsCheckAll;
	Cxbuttons::TcxButton* btnControlsExpandAll;
	Cxtreeview::TcxTreeView* tvControls;
	Cxtreeview::TcxTreeView* tvHiddenControls;
	Cxgroupbox::TcxGroupBox* pnlBtnSite;
	Cxbuttons::TcxButton* btnLinksDesign;
	Cxbuttons::TcxButton* btnLinksRemoveInconsistents;
	Cxgroupbox::TcxGroupBox* pnlLinkListsSite;
	Cxgroupbox::TcxGroupBox* pnlAvailableLinksSite;
	Cxlabel::TcxLabel* lblAvailableLinks;
	Cxlistbox::TcxListBox* lbxAvailableLinks;
	Cxgroupbox::TcxGroupBox* pnlMoveButtonsSite;
	Cxbuttons::TcxButton* sbtnAdd;
	Cxbuttons::TcxButton* sbtnRemove;
	Cxgroupbox::TcxGroupBox* pnlAggregatedLinksSite;
	Cxlabel::TcxLabel* lblAggregatedLinks;
	Cxlistbox::TcxListBox* lbxAggregatedLinks;
	Cxgraphics::TcxImageList* ilControlsPopup;
	Cxgraphics::TcxImageList* ilControls;
	Cxpc::TcxTabSheet* tshBehaviors;
	Vcl::Extctrls::TImage* Image1;
	Cxcheckbox::TcxCheckBox* chbxExpandedGroups;
	Cxcheckbox::TcxCheckBox* chbxSkipEmptyGroups;
	Cxlabel::TcxLabel* lbTabs;
	Cxcheckbox::TcxCheckBox* chbxUnwrapTabs;
	Cxcheckbox::TcxCheckBox* chbxRiseActiveTabOntoTop;
	Vcl::Extctrls::TImage* Image2;
	Cxlabel::TcxLabel* lbGroups;
	Cxgroupbox::TcxGroupBox* gbBtns;
	Cxgroupbox::TcxGroupBox* gbBtns2;
	Cxbuttons::TcxButton* btnHiddenControlsCheckAll;
	Cxbuttons::TcxButton* btnHiddenControlsExpandAll;
	void __fastcall TreeViewClick(System::TObject* Sender);
	void __fastcall TreeViewKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall TreeViewKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall TreeViewCheckAllChildrenClick(System::TObject* Sender);
	void __fastcall TreeViewCheckAllClick(System::TObject* Sender);
	void __fastcall TreeViewUncheckAllChildrenClick(System::TObject* Sender);
	void __fastcall TreeViewExpandAllClick(System::TObject* Sender);
	void __fastcall pmControlsPopup(System::TObject* Sender);
	void __fastcall TreeViewCustomDrawItem(Vcl::Comctrls::TCustomTreeView* Sender, Vcl::Comctrls::TTreeNode* Node, Vcl::Comctrls::TCustomDrawState State, bool &DefaultDraw);
	void __fastcall DesignClick(System::TObject* Sender);
	void __fastcall lbxAggregatedLinksClick(System::TObject* Sender);
	void __fastcall TreeViewChange(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall TransparentClick(System::TObject* Sender);
	void __fastcall PaginationClick(System::TObject* Sender);
	void __fastcall TreeViewMouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall HideStandardControlsClick(System::TObject* Sender);
	void __fastcall UnhideStandardControlsClick(System::TObject* Sender);
	void __fastcall SizeClick(System::TObject* Sender);
	void __fastcall sbtnAddClick(System::TObject* Sender);
	void __fastcall sbtnRemoveClick(System::TObject* Sender);
	void __fastcall tshReportLinksResize(System::TObject* Sender);
	void __fastcall lbxAvailableLinksKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall lbxAggregatedLinksKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall lbxAvailableLinksDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbxAvailableLinksDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall lbxAggregatedLinksDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbxAggregatedLinksDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall lbxAggregatedLinksDblClick(System::TObject* Sender);
	void __fastcall lbxAvailableLinksDblClick(System::TObject* Sender);
	void __fastcall btnLinksRemoveInconsistentsClick(System::TObject* Sender);
	void __fastcall lbxAvailableLinksDrawItem(Cxlistbox::TcxListBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall GroupsClick(System::TObject* Sender);
	void __fastcall TabsClick(System::TObject* Sender);
	
private:
	bool FAreHiddenControlsChanged;
	Cxpc::TcxTabSheet* FLastActiveTab;
	Dxpscore::TBasedxReportLink* __fastcall GetAggregatedLink(int Index);
	int __fastcall GetAggregatedLinkCount(void);
	bool __fastcall GetAggregatedLinkSelected(int Index);
	Dxpscore::TBasedxReportLink* __fastcall GetAvailableLink(int Index);
	int __fastcall GetAvailableLinkCount(void);
	bool __fastcall GetAvailableLinkSelected(int Index);
	Cxpc::TcxTabSheet* __fastcall GetBehaviorsTab(void);
	Cxpc::TcxTabSheet* __fastcall GetControlsTab(void);
	Cxpc::TcxTabSheet* __fastcall GetHiddenControlsTab(void);
	TdxCustomContainerReportLink* __fastcall GetReportLink(void);
	Cxpc::TcxTabSheet* __fastcall GetReportLinksTab(void);
	Dxpscore::TBasedxReportLink* __fastcall GetSelectedReportLink(void);
	void __fastcall DoCheckAllChildren(Vcl::Comctrls::TTreeNode* ANode, bool AChecked);
	void __fastcall DoToggleNodeState(Vcl::Comctrls::TTreeNode* ANode);
	bool __fastcall CanAggregate(void);
	bool __fastcall CanDesign(void);
	bool __fastcall CanDisaggregate(void);
	bool __fastcall CanRemoveInconsistents(void);
	void __fastcall DoAggregateSelectedLinks(void);
	void __fastcall DoDisaggregateSelectedLinks(void);
	void __fastcall DoSelectAll(Cxlistbox::TcxListBox* AListBox);
	void __fastcall RefreshAggregatedLinks(void);
	void __fastcall RefreshAvailableLinks(void);
	
protected:
	virtual void __fastcall BeforeConstruction(void);
	virtual void __fastcall DoInitialize(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual Cxtreeview::TcxTreeView* __fastcall GetActiveTreeView(void);
	virtual void __fastcall InitializeControlsTree(void);
	virtual void __fastcall InitializeHiddenControlsTree(void);
	virtual bool __fastcall IsBoldNode(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall RefreshControlsTree(void);
	void __fastcall RefreshHiddenControlsTree(void);
	void __fastcall RefreshReportLinksList(void);
	virtual void __fastcall SetOptionsGroupsByIndex(int AnIndex, bool AValue);
	virtual void __fastcall SetOptionsPaginationByIndex(int AnIndex, bool AValue);
	virtual void __fastcall SetOptionsSizeByIndex(int AnIndex, bool AValue);
	virtual void __fastcall SetOptionsTabsByIndex(int AnIndex, bool AValue);
	virtual void __fastcall SetOptionsTransparentByIndex(int AnIndex, bool AValue);
	void __fastcall TreeView_AdvancedCustomDrawItem(Vcl::Comctrls::TCustomTreeView* Sender, Vcl::Comctrls::TTreeNode* Node, Vcl::Comctrls::TCustomDrawState State, Vcl::Comctrls::TCustomDrawStage Stage, bool &PaintImages, bool &DefaultDraw);
	void __fastcall TreeView_BeginUpdate(void);
	void __fastcall TreeView_CheckAllChildren(Vcl::Comctrls::TTreeNode* ANode, bool AChecked);
	void __fastcall TreeView_EndUpdate(void);
	void __fastcall TreeView_FreeNodeObjects(Vcl::Comctrls::TTreeView* ATreeView);
	bool __fastcall TreeView_HasCheckedChildren(Vcl::Comctrls::TTreeNode* ANode);
	bool __fastcall TreeView_HasRoot(Vcl::Comctrls::TTreeView* ATreeView);
	bool __fastcall TreeView_HasUncheckedChildren(Vcl::Comctrls::TTreeNode* ANode);
	TdxNodeObject* __fastcall TreeView_GetNodeObject(Vcl::Comctrls::TTreeNode* ANode);
	Vcl::Comctrls::TTreeNode* __fastcall TreeView_getRoot(Vcl::Comctrls::TTreeView* ATreeView);
	bool __fastcall TreeView_IsNodeEditable(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall TreeView_NormalizeNode(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall TreeView_SetNodeState(Vcl::Comctrls::TTreeNode* ANode, Vcl::Stdctrls::TCheckBoxState AState);
	void __fastcall TreeView_ToggleNodeState(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall TreeView_UpdateNodeImage(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall TreeView_UpdateNodesState(Vcl::Comctrls::TTreeNode* ANode);
	__property Cxtreeview::TcxTreeView* ActiveTreeView = {read=GetActiveTreeView};
	__property Cxpc::TcxTabSheet* BehaviorsTab = {read=GetBehaviorsTab};
	__property Cxpc::TcxTabSheet* ControlsTab = {read=GetControlsTab};
	__property Cxpc::TcxTabSheet* HiddenControlsTab = {read=GetHiddenControlsTab};
	__property Cxpc::TcxTabSheet* ReportLinksTab = {read=GetReportLinksTab};
	__property Dxpscore::TBasedxReportLink* SelectedReportLink = {read=GetSelectedReportLink};
	__property int AggregatedLinkCount = {read=GetAggregatedLinkCount, nodefault};
	__property Dxpscore::TBasedxReportLink* AggregatedLinks[int Index] = {read=GetAggregatedLink};
	__property bool AggregatedLinkSelected[int Index] = {read=GetAggregatedLinkSelected};
	__property int AvailableLinkCount = {read=GetAvailableLinkCount, nodefault};
	__property Dxpscore::TBasedxReportLink* AvailableLinks[int Index] = {read=GetAvailableLink};
	__property bool AvailableLinkSelected[int Index] = {read=GetAvailableLinkSelected};
	
public:
	__fastcall virtual TdxfmCustomContainerDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmCustomContainerDesignWindow(void);
	__property TdxCustomContainerReportLink* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmCustomContainerDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmCustomContainerDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


typedef System::StaticArray<System::UnicodeString, 6> Dxpscontainerlnk__36;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::StaticArray<Dxpscore::TdxCellSides, 7> BevelShapeMap;
extern PACKAGE System::StaticArray<System::StaticArray<Dxpscore::TdxPSCellBorderClass, 7>, 2> BevelStyleMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxCellSides, 2> BorderStyleMap;
extern PACKAGE System::StaticArray<Dxpsfillpatterns::TdxPSFillPatternClass, 8> BrushStyleMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxCellCheckPos, 2> CheckAlignmentMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxPSCellBorderClass, 2> Ctl3DBorderClassMap;
extern PACKAGE System::StaticArray<System::StaticArray<Dxpscore::TdxPSCellBorderClass, 4>, 4> PanelBevelsMap;
extern PACKAGE System::StaticArray<Dxpscore::TdxPSCellBorderClass, 2> PanelSingleBorderMap;
extern PACKAGE System::StaticArray<Dxpsshapes::TdxReportCellShapeClass, 6> ShapeTypeMap;
extern PACKAGE int MaxCaptionLength;
static const System::Int8 ExpandHeightBit = System::Int8(0x1);
static const System::Int8 ExpandHeightOffset = System::Int8(0x0);
static const System::Int8 ExpandWidthBit = System::Int8(0x2);
static const System::Int8 ExpandWidthOffset = System::Int8(0x1);
static const System::Int8 ShrinkHeightBit = System::Int8(0x4);
static const System::Int8 ShrinkHeightOffset = System::Int8(0x2);
static const System::Int8 ShrinkWidthBit = System::Int8(0x8);
static const System::Int8 ShrinkWidthOffset = System::Int8(0x3);
static const System::Int8 StandardHiddenControlCount = System::Int8(0x6);
extern PACKAGE Dxpscontainerlnk__36 StandardHiddenControls;
extern PACKAGE System::UnicodeString __fastcall dxPSMakeFriendlyNameFromStrings(System::Classes::TStrings* AStrings);
extern PACKAGE bool __fastcall dxPSIsComponentContainer(System::TClass AComponentClass)/* overload */;
extern PACKAGE bool __fastcall dxPSIsComponentContainer(System::TObject* AComponent)/* overload */;
extern PACKAGE void __fastcall dxPSRegisterContainer(Vcl::Controls::TWinControlClass AContainerClass, Dxpscore::TdxReportLinkDesignWindowClass ADesignerClass = 0x0);
extern PACKAGE void __fastcall dxPSRegisterContainers(Vcl::Controls::TWinControlClass const *AContainerClasses, const int AContainerClasses_Size, Dxpscore::TdxReportLinkDesignWindowClass ADesignerClass = 0x0);
extern PACKAGE void __fastcall dxPSUnregisterContainer(Vcl::Controls::TWinControlClass AContainerClass, Dxpscore::TdxReportLinkDesignWindowClass ADesignerClass = 0x0);
extern PACKAGE void __fastcall dxPSUnregisterContainers(Vcl::Controls::TWinControlClass const *AContainerClasses, const int AContainerClasses_Size, Dxpscore::TdxReportLinkDesignWindowClass ADesignerClass = 0x0);
}	/* namespace Dxpscontainerlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCONTAINERLNK)
using namespace Dxpscontainerlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscontainerlnkHPP
