// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxInplaceContainer.pas' rev: 24.00 (Win64)

#ifndef CxinplacecontainerHPP
#define CxinplacecontainerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLibraryConsts.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxEditDataRegisteredRepositoryItems.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <cxFilterControl.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxinplacecontainer
{
//-- type declarations -------------------------------------------------------
enum TcxDragSizingDirection : unsigned char { dsdHorz, dsdVert };

typedef void __fastcall (__closure *TcxGetEditPropertiesEvent)(System::TObject* Sender, void * AData, Cxedit::TcxCustomEditProperties* &AEditProperties);

typedef void __fastcall (__closure *TcxOnGetContentStyleEvent)(System::TObject* Sender, void * AData, /* out */ Cxstyles::TcxStyle* &AStyle);

typedef System::TMetaClass* TcxInplaceEditContainerClass;

typedef System::TMetaClass* TcxItemDataBindingClass;

typedef System::TMetaClass* TcxCustomControlDragAndDropObjectClass;

typedef System::TMetaClass* TcxEditingControllerClass;

typedef System::TMetaClass* TcxCustomEditStyleClass;

typedef System::TMetaClass* TcxCustomControlControllerClass;

typedef System::TMetaClass* TcxHotTrackControllerClass;

enum TcxEditItemShowEditButtons : unsigned char { eisbDefault, eisbNever, eisbAlways };

enum TcxEditingControlEditShowButtons : unsigned char { ecsbAlways, ecsbFocused, ecsbNever };

typedef System::TMetaClass* TcxCustomCellViewInfoClass;

typedef System::TMetaClass* TcxEditCellViewInfoClass;

typedef System::TMetaClass* TcxCustomNavigatorSiteViewInfoClass;

typedef __int64 TcxHitCode;

class DELPHICLASS TcxContainerItemDefaultValuesProvider;
class PASCALIMPLEMENTATION TcxContainerItemDefaultValuesProvider : public Cxedit::TcxCustomEditDefaultValuesProvider
{
	typedef Cxedit::TcxCustomEditDefaultValuesProvider inherited;
	
__published:
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
public:
	/* TcxCustomEditDefaultValuesProvider.Destroy */ inline __fastcall virtual ~TcxContainerItemDefaultValuesProvider(void) { }
	
public:
	/* TcxInterfacedPersistent.Create */ inline __fastcall virtual TcxContainerItemDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Cxedit::TcxCustomEditDefaultValuesProvider(AOwner) { }
	
};


class DELPHICLASS TcxCustomItemDataBinding;
class DELPHICLASS TcxCustomInplaceEditContainer;
class PASCALIMPLEMENTATION TcxCustomItemDataBinding : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	Cxedit::TcxCustomEditDefaultValuesProvider* FDefaultValuesProvider;
	void *FData;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	TcxCustomInplaceEditContainer* __fastcall GetEditContainer(void);
	
protected:
	virtual Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual System::UnicodeString __fastcall GetDefaultCaption(void);
	virtual Cxedit::_di_IcxEditDefaultValuesProvider __fastcall GetDefaultValuesProvider(Cxedit::TcxCustomEditProperties* AProperties);
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	virtual void __fastcall Init(void);
	bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
	virtual void __fastcall ValueTypeClassChanged(void);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property Cxedit::TcxCustomEditDefaultValuesProvider* DefaultValuesProvider = {read=FDefaultValuesProvider};
	__property TcxCustomInplaceEditContainer* EditContainer = {read=GetEditContainer};
	
public:
	__fastcall virtual TcxCustomItemDataBinding(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomItemDataBinding(void);
	__property void * Data = {read=FData, write=FData};
};


class DELPHICLASS TcxItemDataBinding;
class PASCALIMPLEMENTATION TcxItemDataBinding : public TcxCustomItemDataBinding
{
	typedef TcxCustomItemDataBinding inherited;
	
private:
	Cxdatastorage::TcxValueTypeClass FValueTypeClass;
	System::UnicodeString __fastcall GetValueType(void);
	void __fastcall SetValueType(const System::UnicodeString Value);
	void __fastcall SetValueTypeClass(Cxdatastorage::TcxValueTypeClass Value);
	
protected:
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	virtual bool __fastcall IsValueTypeStored(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Cxdatastorage::TcxValueTypeClass ValueTypeClass = {read=GetValueTypeClass, write=SetValueTypeClass};
	
__published:
	__property System::UnicodeString ValueType = {read=GetValueType, write=SetValueType, stored=IsValueTypeStored};
public:
	/* TcxCustomItemDataBinding.Create */ inline __fastcall virtual TcxItemDataBinding(System::Classes::TPersistent* AOwner) : TcxCustomItemDataBinding(AOwner) { }
	/* TcxCustomItemDataBinding.Destroy */ inline __fastcall virtual ~TcxItemDataBinding(void) { }
	
};


class DELPHICLASS TcxControlDataController;
class DELPHICLASS TcxEditingControl;
class PASCALIMPLEMENTATION TcxControlDataController : public Cxdata::TcxDataController
{
	typedef Cxdata::TcxDataController inherited;
	
private:
	TcxEditingControl* __fastcall GetControl(void);
	
protected:
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	
public:
	virtual System::TObject* __fastcall GetItem(int Index);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall UpdateItemIndexes(void);
public:
	/* TcxDataController.Create */ inline __fastcall virtual TcxControlDataController(System::Classes::TComponent* AOwner) : Cxdata::TcxDataController(AOwner) { }
	/* TcxDataController.Destroy */ inline __fastcall virtual ~TcxControlDataController(void) { }
	
};


typedef System::TMetaClass* TcxCustomEditContainerItemOptionsClass;

class DELPHICLASS TcxCustomEditContainerItemOptions;
class PASCALIMPLEMENTATION TcxCustomEditContainerItemOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FCustomizing;
	bool FEditing;
	bool FFiltering;
	bool FFocusing;
	bool FIncSearch;
	bool FMoving;
	TcxEditItemShowEditButtons FShowEditButtons;
	bool FSorting;
	bool FTabStop;
	TcxCustomInplaceEditContainer* __fastcall GetEditContainer(void);
	void __fastcall SetEditing(bool Value);
	void __fastcall SetFiltering(bool Value);
	void __fastcall SetFocusing(bool Value);
	void __fastcall SetIncSearch(bool Value);
	void __fastcall SetShowEditButtons(TcxEditItemShowEditButtons Value);
	
protected:
	virtual void __fastcall Changed(void);
	__property TcxCustomInplaceEditContainer* EditContainer = {read=GetEditContainer};
	__property bool Moving = {read=FMoving, write=FMoving, default=1};
	__property bool Customizing = {read=FCustomizing, write=FCustomizing, default=1};
	__property bool Sorting = {read=FSorting, write=FSorting, default=1};
	__property bool Editing = {read=FEditing, write=SetEditing, default=1};
	__property bool Filtering = {read=FFiltering, write=SetFiltering, default=1};
	__property bool Focusing = {read=FFocusing, write=SetFocusing, default=1};
	__property bool IncSearch = {read=FIncSearch, write=SetIncSearch, default=1};
	__property TcxEditItemShowEditButtons ShowEditButtons = {read=FShowEditButtons, write=SetShowEditButtons, default=0};
	__property bool TabStop = {read=FTabStop, write=FTabStop, default=1};
	
public:
	__fastcall virtual TcxCustomEditContainerItemOptions(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* AOwner);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomEditContainerItemOptions(void) { }
	
};


typedef System::TMetaClass* TcxControlOptionsViewClass;

class DELPHICLASS TcxControlOptionsView;
class PASCALIMPLEMENTATION TcxControlOptionsView : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FCellAutoHeight;
	bool FCellEndEllipsis;
	int FCellTextMaxLineCount;
	int FNavigatorOffset;
	TcxEditingControlEditShowButtons FShowEditButtons;
	TcxEditingControl* __fastcall GetEditingControl(void);
	System::Uitypes::TScrollStyle __fastcall GetScrollBars(void);
	void __fastcall SetCellAutoHeight(const bool Value);
	void __fastcall SetCellEndEllipsis(const bool Value);
	void __fastcall SetCellTextMaxLineCount(const int Value);
	void __fastcall SetNavigatorOffset(int AValue);
	void __fastcall SetScrollBars(const System::Uitypes::TScrollStyle Value);
	void __fastcall SetShowEditButtons(const TcxEditingControlEditShowButtons Value);
	bool __fastcall IsShowEditButtonsStored(void);
	
protected:
	virtual void __fastcall Changed(void);
	virtual TcxEditingControlEditShowButtons __fastcall GetDefaultShowEditButtons(void);
	__property TcxEditingControl* EditingControl = {read=GetEditingControl};
	__property int NavigatorOffset = {read=FNavigatorOffset, write=SetNavigatorOffset, default=50};
	
public:
	__fastcall virtual TcxControlOptionsView(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CellAutoHeight = {read=FCellAutoHeight, write=SetCellAutoHeight, default=0};
	__property bool CellEndEllipsis = {read=FCellEndEllipsis, write=SetCellEndEllipsis, default=0};
	__property int CellTextMaxLineCount = {read=FCellTextMaxLineCount, write=SetCellTextMaxLineCount, default=0};
	__property System::Uitypes::TScrollStyle ScrollBars = {read=GetScrollBars, write=SetScrollBars, default=3};
	__property TcxEditingControlEditShowButtons ShowEditButtons = {read=FShowEditButtons, write=SetShowEditButtons, stored=IsShowEditButtonsStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxControlOptionsView(void) { }
	
};


typedef System::TMetaClass* TcxControlOptionsDataClass;

class DELPHICLASS TcxControlOptionsData;
class PASCALIMPLEMENTATION TcxControlOptionsData : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FCancelOnExit;
	bool FEditing;
	TcxEditingControl* __fastcall GetEditingControl(void);
	void __fastcall SetEditing(bool Value);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TcxControlOptionsData(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxEditingControl* EditingControl = {read=GetEditingControl};
	
__published:
	__property bool CancelOnExit = {read=FCancelOnExit, write=FCancelOnExit, default=1};
	__property bool Editing = {read=FEditing, write=SetEditing, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxControlOptionsData(void) { }
	
};


typedef System::TMetaClass* TcxControlOptionsBehaviorClass;

class DELPHICLASS TcxControlOptionsBehavior;
class PASCALIMPLEMENTATION TcxControlOptionsBehavior : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FAlwaysShowEditor;
	bool FCellHints;
	bool FDragDropText;
	bool FFocusCellOnCycle;
	bool FFocusFirstCellOnNewRecord;
	int FHintHidePause;
	bool FGoToNextCellOnEnter;
	bool FGoToNextCellOnTab;
	bool FImmediateEditor;
	bool FIncSearch;
	TcxCustomInplaceEditContainer* FIncSearchItem;
	bool FNavigatorHints;
	TcxEditingControl* __fastcall GetEditingControl(void);
	void __fastcall SetAlwaysShowEditor(bool Value);
	void __fastcall SetCellHints(bool Value);
	void __fastcall SetFocusCellOnCycle(bool Value);
	void __fastcall SetFocusFirstCellOnNewRecord(bool Value);
	void __fastcall SetGoToNextCellOnEnter(bool Value);
	void __fastcall SetGoToNextCellOnTab(bool Value);
	void __fastcall SetImmediateEditor(bool Value);
	void __fastcall SetIncSearch(bool Value);
	void __fastcall SetIncSearchItem(TcxCustomInplaceEditContainer* Value);
	
protected:
	virtual void __fastcall Changed(void);
	__property bool DragDropText = {read=FDragDropText, write=FDragDropText, default=0};
	__property TcxEditingControl* EditingControl = {read=GetEditingControl};
	__property bool FocusCellOnCycle = {read=FFocusCellOnCycle, write=SetFocusCellOnCycle, default=0};
	__property bool FocusFirstCellOnNewRecord = {read=FFocusFirstCellOnNewRecord, write=SetFocusFirstCellOnNewRecord, default=0};
	__property bool IncSearch = {read=FIncSearch, write=SetIncSearch, default=0};
	__property TcxCustomInplaceEditContainer* IncSearchItem = {read=FIncSearchItem, write=SetIncSearchItem};
	__property bool NavigatorHints = {read=FNavigatorHints, write=FNavigatorHints, default=0};
	
public:
	__fastcall virtual TcxControlOptionsBehavior(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AlwaysShowEditor = {read=FAlwaysShowEditor, write=SetAlwaysShowEditor, default=0};
	__property bool CellHints = {read=FCellHints, write=SetCellHints, default=0};
	__property bool GoToNextCellOnEnter = {read=FGoToNextCellOnEnter, write=SetGoToNextCellOnEnter, default=0};
	__property bool GoToNextCellOnTab = {read=FGoToNextCellOnTab, write=SetGoToNextCellOnTab, default=0};
	__property int HintHidePause = {read=FHintHidePause, write=FHintHidePause, default=0};
	__property bool ImmediateEditor = {read=FImmediateEditor, write=SetImmediateEditor, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxControlOptionsBehavior(void) { }
	
};


class DELPHICLASS TcxExtEditingControlNavigatorButtons;
class DELPHICLASS TcxExtEditingControl;
class PASCALIMPLEMENTATION TcxExtEditingControlNavigatorButtons : public Cxnavigator::TcxNavigatorControlButtons
{
	typedef Cxnavigator::TcxNavigatorControlButtons inherited;
	
private:
	TcxExtEditingControl* FControl;
	
protected:
	virtual bool __fastcall IsButtonVisibleByDefault(int AIndex);
	
public:
	__fastcall virtual TcxExtEditingControlNavigatorButtons(TcxExtEditingControl* AControl);
	
__published:
	__property ConfirmDelete = {default=0};
public:
	/* TcxCustomNavigatorButtons.Destroy */ inline __fastcall virtual ~TcxExtEditingControlNavigatorButtons(void) { }
	
};


typedef System::TMetaClass* TcxExtEditingControlNavigatorButtonsClass;

class DELPHICLASS TcxControlNavigatorInfoPanel;
class PASCALIMPLEMENTATION TcxControlNavigatorInfoPanel : public Cxnavigator::TcxCustomNavigatorInfoPanel
{
	typedef Cxnavigator::TcxCustomNavigatorInfoPanel inherited;
	
private:
	TcxExtEditingControl* FControl;
	
protected:
	virtual Cxgraphics::TcxViewParams __fastcall GetViewParams(void);
	
public:
	__fastcall virtual TcxControlNavigatorInfoPanel(TcxExtEditingControl* AControl);
	__property TcxExtEditingControl* Control = {read=FControl};
	
__published:
	__property DisplayMask = {default=0};
	__property Visible = {default=0};
	__property Width = {default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxControlNavigatorInfoPanel(void) { }
	
};


typedef System::TMetaClass* TcxControlNavigatorInfoPanelClass;

class DELPHICLASS TcxControlNavigator;
class PASCALIMPLEMENTATION TcxControlNavigator : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TcxExtEditingControlNavigatorButtons* FButtons;
	TcxControlNavigatorInfoPanel* FInfoPanel;
	bool FVisible;
	TcxExtEditingControl* __fastcall GetControl(void);
	Cxnavigator::_di_IcxNavigatorRecordPosition __fastcall GetIRecordPosition(void);
	void __fastcall SetButtons(TcxExtEditingControlNavigatorButtons* Value);
	void __fastcall SetInfoPanel(TcxControlNavigatorInfoPanel* Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	virtual TcxControlNavigatorInfoPanelClass __fastcall GetInfoPanelClass(void);
	virtual TcxExtEditingControlNavigatorButtonsClass __fastcall GetNavigatorButtonsClass(void);
	
public:
	__fastcall virtual TcxControlNavigator(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxControlNavigator(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxExtEditingControl* Control = {read=GetControl};
	
__published:
	__property TcxExtEditingControlNavigatorButtons* Buttons = {read=FButtons, write=SetButtons};
	__property TcxControlNavigatorInfoPanel* InfoPanel = {read=FInfoPanel, write=SetInfoPanel};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
};


typedef System::TMetaClass* TcxControlNavigatorClass;

typedef System::TMetaClass* TcxEditContainerStylesClass;

class DELPHICLASS TcxEditContainerStyles;
class DELPHICLASS TcxCustomControlStyles;
class PASCALIMPLEMENTATION TcxEditContainerStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	TcxCustomInplaceEditContainer* __fastcall GetContainer(void);
	TcxEditingControl* __fastcall GetControl(void);
	TcxCustomControlStyles* __fastcall GetControlStyles(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomInplaceEditContainer* Container = {read=GetContainer};
	__property TcxEditingControl* Control = {read=GetControl};
	__property TcxCustomControlStyles* ControlStyles = {read=GetControlStyles};
	
__published:
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=0};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxEditContainerStyles(System::Classes::TPersistent* AOwner) : Cxstyles::TcxStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxEditContainerStyles(void) { }
	
};


__interface IcxEditorPropertiesContainer;
typedef System::DelphiInterface<IcxEditorPropertiesContainer> _di_IcxEditorPropertiesContainer;
__interface  INTERFACE_UUID("{9F0CD5D9-A3D1-44B7-82DC-CAEAC1367C5D}") IcxEditorPropertiesContainer  : public System::IInterface 
{
	
public:
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void) = 0 ;
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void) = 0 ;
	virtual void __fastcall SetPropertiesClass(Cxedit::TcxCustomEditPropertiesClass Value) = 0 ;
};

class DELPHICLASS TcxEditCellViewInfo;
class DELPHICLASS TcxCustomControlController;
class PASCALIMPLEMENTATION TcxCustomInplaceEditContainer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	void *FData;
	Cxedit::TcxCustomEditData* FEditData;
	TcxEditingControl* FEditingControl;
	Cxedit::TcxCustomEditViewData* FEditViewData;
	Cxdatautils::TcxDataEditValueSource FEditValueSource;
	int FItemIndex;
	Cxedit::TcxCustomEditProperties* FLastEditingProperties;
	TcxCustomEditContainerItemOptions* FOptions;
	Cxedit::TcxCustomEditProperties* FProperties;
	Cxedit::TcxCustomEditPropertiesClass FPropertiesClass;
	System::Classes::TNotifyEvent FPropertiesEvents;
	Cxedit::TcxCustomEditProperties* FPropertiesValue;
	Cxedit::TcxEditRepositoryItem* FRepositoryItem;
	TcxEditContainerStyles* FStyles;
	TcxGetEditPropertiesEvent FOnGetEditProperties;
	TcxGetEditPropertiesEvent FOnGetEditingProperties;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	bool __fastcall GetFocused(void);
	TcxEditCellViewInfo* __fastcall GetFocusedCellViewInfo(void);
	bool __fastcall GetIncSearching(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void);
	Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	System::UnicodeString __fastcall GetPropertiesClassName(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetPropertiesValue(void);
	void __fastcall SetDataBinding(TcxCustomItemDataBinding* Value);
	void __fastcall SetFocused(bool Value);
	void __fastcall SetOptions(TcxCustomEditContainerItemOptions* Value);
	void __fastcall SetProperties(Cxedit::TcxCustomEditProperties* Value);
	void __fastcall SetPropertiesClass(Cxedit::TcxCustomEditPropertiesClass Value);
	void __fastcall SetPropertiesClassName(const System::UnicodeString Value);
	void __fastcall SetRepositoryItem(Cxedit::TcxEditRepositoryItem* Value);
	void __fastcall SetStyles(TcxEditContainerStyles* Value);
	void __fastcall CreateProperties(void);
	void __fastcall DestroyProperties(void);
	void __fastcall RecreateProperties(void);
	void __fastcall RepositoryItemPropertiesChanged(Cxedit::TcxEditRepositoryItem* Sender);
	void __fastcall RepositoryItemRemoved(Cxedit::TcxEditRepositoryItem* Sender);
	
protected:
	TcxCustomItemDataBinding* FDataBinding;
	virtual void __fastcall CalculateEditViewInfo(const System::Variant &AValue, TcxEditCellViewInfo* AEditViewInfo, const System::Types::TPoint APoint);
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall CanFocus(void);
	void __fastcall CancelIncSearching(void);
	virtual bool __fastcall CanInitEditing(void);
	virtual bool __fastcall CanIncSearch(void);
	virtual bool __fastcall CanTabStop(void);
	virtual void __fastcall Changed(void);
	virtual Cxedit::TcxCustomEditViewData* __fastcall CreateEditViewData(Cxedit::TcxCustomEditProperties* AProperties, void * AEditStyleData);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DoGetDisplayText(NativeInt ARecordIndex, System::UnicodeString &AText);
	virtual Cxedit::TcxCustomEditProperties* __fastcall DoGetEditProperties(void * AData);
	virtual void __fastcall DoGetEditingProperties(void * AData, Cxedit::TcxCustomEditProperties* &AProperties);
	virtual Cxedit::TcxCustomEditProperties* __fastcall DoGetPropertiesFromEvent(TcxGetEditPropertiesEvent AEvent, void * AData, Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall DoOnPropertiesChanged(System::TObject* Sender);
	virtual void __fastcall EditViewDataGetDisplayTextHandler(Cxedit::TcxCustomEditViewData* Sender, System::UnicodeString &AText);
	virtual Cxgraphics::TcxCanvas* __fastcall GetControlCanvas(void);
	virtual TcxCustomControlController* __fastcall GetController(void);
	virtual System::Variant __fastcall GetCurrentValue(void);
	virtual TcxItemDataBindingClass __fastcall GetDataBindingClass(void);
	virtual System::UnicodeString __fastcall GetDefaultCaption(void);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetDefaultEditProperties(void);
	virtual System::Variant __fastcall GetDisplayValue(Cxedit::TcxCustomEditProperties* AProperties, int ARecordIndex);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetEditDataValueTypeClass(void);
	virtual int __fastcall GetEditDefaultHeight(Vcl::Graphics::TFont* AFont);
	virtual int __fastcall GetEditHeight(TcxEditCellViewInfo* AEditViewInfo);
	virtual bool __fastcall GetEditing(void);
	virtual Cxedit::TcxCustomEditStyle* __fastcall GetEditStyle(void * AData);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual int __fastcall GetEditWidth(TcxEditCellViewInfo* AEditViewInfo);
	virtual TcxCustomEditContainerItemOptionsClass __fastcall GetOptionsClass(void);
	virtual TcxEditContainerStylesClass __fastcall GetStylesClass(void);
	virtual System::Variant __fastcall GetValue(int ARecordIndex);
	virtual int __fastcall GetValueCount(void);
	virtual bool __fastcall HasDataTextHandler(void);
	virtual void __fastcall InitEditViewInfo(TcxEditCellViewInfo* AEditViewInfo);
	virtual void __fastcall InitProperties(Cxedit::TcxCustomEditProperties* AProperties);
	void __fastcall InternalPropertiesChanged(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsEditPartVisible(void);
	virtual void __fastcall PropertiesChanged(void);
	virtual void __fastcall SetCurrentValue(const System::Variant &Value);
	virtual void __fastcall SetEditing(bool Value);
	virtual void __fastcall SetEditingControl(TcxEditingControl* Value);
	virtual void __fastcall SetEditValue(const System::Variant &Value);
	virtual void __fastcall SetValue(int ARecordIndex, const System::Variant &Value);
	virtual void __fastcall ValidateDrawValue(const System::Variant &AValue, TcxEditCellViewInfo* AEditViewInfo);
	void __fastcall ValidateEditData(Cxedit::TcxCustomEditProperties* AEditProperties);
	__property TcxCustomControlController* Controller = {read=GetController};
	__property TcxCustomItemDataBinding* DataBinding = {read=FDataBinding, write=SetDataBinding};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property bool IncSearching = {read=GetIncSearching, nodefault};
	__property Cxedit::TcxCustomEditData* EditData = {read=FEditData};
	__property bool Editing = {read=GetEditing, write=SetEditing, nodefault};
	__property TcxEditingControl* EditingControl = {read=FEditingControl, write=SetEditingControl};
	__property System::Variant EditValue = {read=GetEditValue, write=SetEditValue};
	__property Cxdatautils::TcxDataEditValueSource EditValueSource = {read=FEditValueSource, nodefault};
	__property Cxedit::TcxCustomEditViewData* EditViewData = {read=FEditViewData};
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property TcxEditCellViewInfo* FocusedCellViewInfo = {read=GetFocusedCellViewInfo};
	__property TcxCustomEditContainerItemOptions* Options = {read=FOptions, write=SetOptions};
	__property Cxedit::TcxCustomEditProperties* PropertiesValue = {read=GetPropertiesValue};
	__property System::Variant Value = {read=GetCurrentValue, write=SetCurrentValue};
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property System::Variant Values[int ARecordIndex] = {read=GetValue, write=SetValue};
	__property TcxGetEditPropertiesEvent OnGetEditProperties = {read=FOnGetEditProperties, write=FOnGetEditProperties};
	__property TcxGetEditPropertiesEvent OnGetEditingProperties = {read=FOnGetEditingProperties, write=FOnGetEditingProperties};
	
public:
	__fastcall virtual TcxCustomInplaceEditContainer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInplaceEditContainer(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property void * Data = {read=FData, write=FData};
	__property int ItemIndex = {read=FItemIndex, nodefault};
	__property Cxedit::TcxCustomEditPropertiesClass PropertiesClass = {read=FPropertiesClass, write=SetPropertiesClass};
	
__published:
	__property System::UnicodeString PropertiesClassName = {read=GetPropertiesClassName, write=SetPropertiesClassName};
	__property Cxedit::TcxCustomEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FPropertiesEvents, write=FPropertiesEvents};
	__property Cxedit::TcxEditRepositoryItem* RepositoryItem = {read=FRepositoryItem, write=SetRepositoryItem};
	__property TcxEditContainerStyles* Styles = {read=FStyles, write=SetStyles};
private:
	void *__IcxEditorPropertiesContainer;	/* IcxEditorPropertiesContainer */
	void *__IcxEditRepositoryItemListener;	/* Cxedit::IcxEditRepositoryItemListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9F0CD5D9-A3D1-44B7-82DC-CAEAC1367C5D}
	operator _di_IcxEditorPropertiesContainer()
	{
		_di_IcxEditorPropertiesContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxEditorPropertiesContainer*(void) { return (IcxEditorPropertiesContainer*)&__IcxEditorPropertiesContainer; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator Cxedit::_di_IcxEditRepositoryItemListener()
	{
		Cxedit::_di_IcxEditRepositoryItemListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditRepositoryItemListener*(void) { return (Cxedit::IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxEditorPropertiesContainer; }
	#endif
	
};


__interface IcxHotTrackElement;
typedef System::DelphiInterface<IcxHotTrackElement> _di_IcxHotTrackElement;
__interface  INTERFACE_UUID("{E7171E58-276E-499B-9DDF-298D850883C9}") IcxHotTrackElement  : public System::IInterface 
{
	
public:
	virtual System::Types::TRect __fastcall GetHintBounds(void) = 0 ;
	virtual bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint) = 0 ;
	virtual void __fastcall UpdateHotTrackState(const System::Types::TPoint APoint) = 0 ;
};

class DELPHICLASS TcxInplaceContainerHintHelper;
class DELPHICLASS TcxHotTrackController;
class PASCALIMPLEMENTATION TcxInplaceContainerHintHelper : public Dxcustomhint::TcxControlHintHelper
{
	typedef Dxcustomhint::TcxControlHintHelper inherited;
	
private:
	TcxHotTrackController* FController;
	
protected:
	virtual void __fastcall CorrectHintWindowRect(System::Types::TRect &ARect);
	virtual int __fastcall GetHintHidePause(void);
	virtual Cxcontrols::TcxControl* __fastcall GetOwnerControl(void);
	
public:
	__fastcall virtual TcxInplaceContainerHintHelper(TcxHotTrackController* AController);
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TcxInplaceContainerHintHelper(void) { }
	
};


class PASCALIMPLEMENTATION TcxHotTrackController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxEditingControl* FControl;
	TcxInplaceContainerHintHelper* FHintHelper;
	bool FShowHint;
	
protected:
	System::TObject* HintElement;
	bool IsNeedOffsetHint;
	System::Types::TPoint PrevHitPoint;
	System::TObject* PrevElement;
	bool __fastcall CanShowHint(void);
	void __fastcall CheckDestroyingElement(System::TObject* AElement);
	void __fastcall CheckHint(void);
	
public:
	__fastcall virtual TcxHotTrackController(TcxEditingControl* AControl);
	__fastcall virtual ~TcxHotTrackController(void);
	void __fastcall CancelHint(void);
	void __fastcall Clear(void);
	void __fastcall SetHotElement(System::TObject* AElement, const System::Types::TPoint APoint);
	__property TcxEditingControl* Control = {read=FControl, write=FControl};
	__property bool ShowHint = {read=FShowHint, write=FShowHint, nodefault};
};


__interface IcxDragSizing;
typedef System::DelphiInterface<IcxDragSizing> _di_IcxDragSizing;
__interface  INTERFACE_UUID("{5EA02F4E-E367-4E4D-A26D-000B5E5CD434}") IcxDragSizing  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanSizing(TcxDragSizingDirection ADirection) = 0 ;
	virtual System::Types::TRect __fastcall GetSizingBoundsRect(TcxDragSizingDirection ADirection) = 0 ;
	virtual int __fastcall GetSizingIncrement(TcxDragSizingDirection ADirection) = 0 ;
	virtual bool __fastcall IsDynamicUpdate(void) = 0 ;
	virtual void __fastcall SetSizeDelta(TcxDragSizingDirection ADirection, int ADelta) = 0 ;
};

class DELPHICLASS TcxSizingDragAndDropObject;
class PASCALIMPLEMENTATION TcxSizingDragAndDropObject : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	int FDelta;
	TcxDragSizingDirection FDirection;
	System::Types::TRect FDragBounds;
	System::Types::TPoint FDragPos;
	bool FDynamicUpdate;
	System::Types::TPoint FStartPos;
	int FSizeDelta;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	TcxCustomControlController* __fastcall GetController(void);
	int __fastcall GetDragCoord(System::Types::TPoint APoint);
	System::TObject* __fastcall GetDragItem(void);
	_di_IcxDragSizing __fastcall GetDragSizing(void);
	bool __fastcall GetIsSizingKind(int Index);
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DirtyChanged(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual System::Types::TPoint __fastcall GetDragPos(const System::Types::TPoint APoint);
	virtual bool __fastcall GetImmediateStart(void);
	virtual System::Types::TRect __fastcall GetSizingMarkBounds(void);
	__property System::Types::TPoint StartPos = {read=FStartPos};
	__property TcxCustomControlController* Controller = {read=GetController};
	__property int Delta = {read=FDelta, nodefault};
	__property int DragCoord[System::Types::TPoint Point] = {read=GetDragCoord};
	__property System::Types::TPoint DragPos = {read=FDragPos};
	__property _di_IcxDragSizing DragSizing = {read=GetDragSizing};
	__property TcxDragSizingDirection Direction = {read=FDirection, nodefault};
	
public:
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property System::Types::TRect DragBounds = {read=FDragBounds};
	__property System::TObject* DragItem = {read=GetDragItem};
	__property bool DynamicUpdate = {read=FDynamicUpdate, nodefault};
	__property bool IsHorzSizing = {read=GetIsSizingKind, index=0, nodefault};
	__property bool IsVertSizing = {read=GetIsSizingKind, index=1, nodefault};
	__property int SizeDelta = {read=FSizeDelta, nodefault};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxSizingDragAndDropObject(Cxcontrols::TcxControl* AControl) : Cxcontrols::TcxDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSizingDragAndDropObject(void) { }
	
};


class DELPHICLASS TcxCustomAutoScrollingObject;
class PASCALIMPLEMENTATION TcxCustomAutoScrollingObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FArea;
	System::Uitypes::TScrollCode FCode;
	int FIncrement;
	Vcl::Forms::TScrollBarKind FKind;
	System::TObject* FOwner;
	Cxclasses::TcxTimer* FTimer;
	
protected:
	virtual void __fastcall DoScrollInspectingControl(void);
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	virtual bool __fastcall GetHasScrollBar(void);
	virtual Cxcontrols::_di_IcxControlScrollBar __fastcall GetScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall GetScrollBarParams(int &AMin, int &AMax, int &APos);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AKind, System::Uitypes::TScrollCode ACode, int &APosition);
	virtual void __fastcall TimerHandler(System::TObject* Sender);
	
public:
	__fastcall virtual TcxCustomAutoScrollingObject(System::TObject* AOwner);
	__fastcall virtual ~TcxCustomAutoScrollingObject(void);
	bool __fastcall Check(System::Types::TPoint APos);
	void __fastcall SetParams(const System::Types::TRect &Area, Vcl::Forms::TScrollBarKind AKind, System::Uitypes::TScrollCode ACode, int AIncrement);
	void __fastcall Stop(void);
	__property System::Uitypes::TScrollCode Code = {read=FCode, nodefault};
	__property Cxcontrols::TcxControl* Control = {read=GetControl};
	__property bool HasScrollBar = {read=GetHasScrollBar, nodefault};
	__property int Increment = {read=FIncrement, nodefault};
	__property Vcl::Forms::TScrollBarKind Kind = {read=FKind, nodefault};
	__property System::TObject* Owner = {read=FOwner};
	__property Cxclasses::TcxTimer* Timer = {read=FTimer};
};


class DELPHICLASS TcxAutoScrollingEditingControlObject;
class PASCALIMPLEMENTATION TcxAutoScrollingEditingControlObject : public TcxCustomAutoScrollingObject
{
	typedef TcxCustomAutoScrollingObject inherited;
	
protected:
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AKind, System::Uitypes::TScrollCode ACode, int &APosition);
public:
	/* TcxCustomAutoScrollingObject.Create */ inline __fastcall virtual TcxAutoScrollingEditingControlObject(System::TObject* AOwner) : TcxCustomAutoScrollingObject(AOwner) { }
	/* TcxCustomAutoScrollingObject.Destroy */ inline __fastcall virtual ~TcxAutoScrollingEditingControlObject(void) { }
	
};


class DELPHICLASS TcxDragDropObjectAutoScrollingObject;
class PASCALIMPLEMENTATION TcxDragDropObjectAutoScrollingObject : public TcxAutoScrollingEditingControlObject
{
	typedef TcxAutoScrollingEditingControlObject inherited;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
public:
	/* TcxCustomAutoScrollingObject.Create */ inline __fastcall virtual TcxDragDropObjectAutoScrollingObject(System::TObject* AOwner) : TcxAutoScrollingEditingControlObject(AOwner) { }
	/* TcxCustomAutoScrollingObject.Destroy */ inline __fastcall virtual ~TcxDragDropObjectAutoScrollingObject(void) { }
	
};


class DELPHICLASS TcxControllerAutoScrollingObject;
class PASCALIMPLEMENTATION TcxControllerAutoScrollingObject : public TcxAutoScrollingEditingControlObject
{
	typedef TcxAutoScrollingEditingControlObject inherited;
	
private:
	bool FBoundsMode;
	bool FCheckHorz;
	bool FCheckVert;
	Cxlookandfeelpainters::TcxNeighbors FDirections;
	
protected:
	virtual void __fastcall DoScrollInspectingControl(void);
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	
public:
	bool __fastcall CheckBounds(System::Types::TPoint APos);
	void __fastcall SetBoundsParams(const System::Types::TRect &AClientArea, bool ACheckHorz, bool ACheckVert, int AIncrement);
public:
	/* TcxCustomAutoScrollingObject.Create */ inline __fastcall virtual TcxControllerAutoScrollingObject(System::TObject* AOwner) : TcxAutoScrollingEditingControlObject(AOwner) { }
	/* TcxCustomAutoScrollingObject.Destroy */ inline __fastcall virtual ~TcxControllerAutoScrollingObject(void) { }
	
};


typedef System::TMetaClass* TcxCustomAutoScrollingObjectClass;

class DELPHICLASS TcxBaseDragAndDropObject;
class PASCALIMPLEMENTATION TcxBaseDragAndDropObject : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	TcxEditingControl* __fastcall GetEditingControl(void);
	
protected:
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	__property TcxEditingControl* EditingControl = {read=GetEditingControl};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxBaseDragAndDropObject(Cxcontrols::TcxControl* AControl) : Cxcontrols::TcxDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBaseDragAndDropObject(void) { }
	
};


class DELPHICLASS TcxDragImage;
class PASCALIMPLEMENTATION TcxDragImage : public Cxcontrols::TcxDragImage
{
	typedef Cxcontrols::TcxDragImage inherited;
	
public:
	__property Image;
	__property WindowCanvas;
public:
	/* TcxDragImage.Create */ inline __fastcall virtual TcxDragImage(void) : Cxcontrols::TcxDragImage() { }
	/* TcxDragImage.Destroy */ inline __fastcall virtual ~TcxDragImage(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxDragImage(System::Classes::TComponent* AOwner, int Dummy) : Cxcontrols::TcxDragImage(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDragImage(HWND ParentWindow) : Cxcontrols::TcxDragImage(ParentWindow) { }
	
};


class DELPHICLASS TcxPlaceArrows;
class PASCALIMPLEMENTATION TcxPlaceArrows : public TcxDragImage
{
	typedef TcxDragImage inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	System::Uitypes::TColor FColor;
	System::Types::TRect FPrevRect;
	Cxgraphics::TcxBorder FPrevSide;
	HRGN FWindowRegion;
	void __fastcall SetWindowRegion(HRGN ARegion);
	
protected:
	HRGN __fastcall CreateArrowsRgns(const System::Types::TRect &ARect, Cxgraphics::TcxBorder ASide);
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, nodefault};
	__property System::Uitypes::TColor Color = {read=FColor, nodefault};
	__property HRGN WindowRegion = {read=FWindowRegion, write=SetWindowRegion};
	
public:
	__fastcall virtual TcxPlaceArrows(System::Uitypes::TColor AColor, System::Uitypes::TColor ABorderColor);
	HIDESBASE bool __fastcall MoveTo(System::Types::TRect &ARect, Cxgraphics::TcxBorder ASide);
public:
	/* TcxDragImage.Create */ inline __fastcall virtual TcxPlaceArrows(void) : TcxDragImage() { }
	/* TcxDragImage.Destroy */ inline __fastcall virtual ~TcxPlaceArrows(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxPlaceArrows(System::Classes::TComponent* AOwner, int Dummy) : TcxDragImage(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPlaceArrows(HWND ParentWindow) : TcxDragImage(ParentWindow) { }
	
};


class DELPHICLASS TcxCustomControlDragAndDropObject;
class DELPHICLASS TcxCustomHitTestController;
class PASCALIMPLEMENTATION TcxCustomControlDragAndDropObject : public TcxBaseDragAndDropObject
{
	typedef TcxBaseDragAndDropObject inherited;
	
private:
	System::Classes::TList* FAutoScrollObjects;
	bool FCanDrop;
	TcxDragImage* FDragImage;
	System::Types::TPoint FHotSpot;
	System::Types::TPoint FOrgOffset;
	System::Types::TRect FPictureSize;
	bool __fastcall CheckScrolling(const System::Types::TPoint P);
	TcxCustomAutoScrollingObject* __fastcall GetAutoScrollObject(int Index);
	int __fastcall GetAutoScrollObjectCount(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	TcxCustomHitTestController* __fastcall GetHitTestController(void);
	
protected:
	void __fastcall AddAutoScrollingObject(const System::Types::TRect &ARect, Vcl::Forms::TScrollBarKind AKind, System::Uitypes::TScrollCode ACode);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall DrawDragImage(void);
	void __fastcall DrawImage(const System::Types::TPoint APoint);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual System::Types::TRect __fastcall GetAcceptedRect(void);
	virtual TcxCustomAutoScrollingObjectClass __fastcall GetAutoScrollingObjectClass(void);
	virtual System::Types::TRect __fastcall GetDisplayRect(void);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual int __fastcall GetHorzScrollInc(void);
	virtual int __fastcall GetVertScrollInc(void);
	virtual void __fastcall OwnerImageChanged(void);
	virtual void __fastcall OwnerImageChanging(void);
	virtual void __fastcall Paint(void);
	void __fastcall StopScrolling(void);
	__property System::Types::TRect AcceptedRect = {read=GetAcceptedRect};
	__property int AutoScrollObjectCount = {read=GetAutoScrollObjectCount, nodefault};
	__property TcxCustomAutoScrollingObject* AutoScrollObjects[int Index] = {read=GetAutoScrollObject};
	__property bool CanDrop = {read=FCanDrop, nodefault};
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property System::Types::TRect DisplayRect = {read=GetDisplayRect};
	__property TcxDragImage* DragImage = {read=FDragImage};
	__property TcxCustomHitTestController* HitTestController = {read=GetHitTestController};
	__property System::Types::TPoint HotSpot = {read=FHotSpot};
	__property System::Types::TPoint OrgOffset = {read=FOrgOffset, write=FOrgOffset};
	__property System::Types::TRect PictureSize = {read=FPictureSize};
	
public:
	__fastcall virtual TcxCustomControlDragAndDropObject(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TcxCustomControlDragAndDropObject(void);
};


typedef System::TMetaClass* TcxDragImageHelperClass;

class DELPHICLASS TcxDragImageHelper;
class PASCALIMPLEMENTATION TcxDragImageHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxEditingControl* FDragControl;
	bool FDragImageVisible;
	System::Types::TPoint FDragPos;
	System::Types::TRect __fastcall GetImageRect(void);
	void __fastcall SetDragImageVisible(bool Value);
	
protected:
	TcxDragImage* DragImage;
	System::Types::TPoint HotSpot;
	System::Types::TRect DragPictureBounds;
	System::Types::TPoint MousePos;
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P);
	virtual System::Types::TRect __fastcall GetDisplayRect(void);
	virtual void __fastcall InitDragImage(void);
	virtual void __fastcall DrawImage(const System::Types::TPoint APoint);
	
public:
	__fastcall virtual TcxDragImageHelper(TcxEditingControl* AControl, System::Types::TPoint ADragPos);
	__fastcall virtual ~TcxDragImageHelper(void);
	virtual void __fastcall Hide(void);
	virtual void __fastcall Show(void);
	__property TcxEditingControl* DragControl = {read=FDragControl};
	__property System::Types::TRect DragImageRect = {read=GetImageRect};
	__property bool DragImageVisible = {read=FDragImageVisible, write=SetDragImageVisible, nodefault};
};


typedef System::TMetaClass* TcxHitTestControllerClass;

class DELPHICLASS TcxCustomControlViewInfo;
class PASCALIMPLEMENTATION TcxCustomHitTestController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomControlController* FController;
	System::Types::TPoint FHitPoint;
	System::TObject* FHitTestItem;
	System::Classes::TShiftState FShift;
	TcxEditingControl* __fastcall GetControl(void);
	int __fastcall GetCoordinate(int AIndex);
	TcxEditCellViewInfo* __fastcall GetEditCellViewInfo(void);
	bool __fastcall GetHasCode(TcxHitCode Mask);
	TcxHotTrackController* __fastcall GetHotTrackController(void);
	bool __fastcall GetIsItemEditCell(void);
	bool __fastcall GetIsMouseEvent(void);
	TcxCustomControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetCoordinate(int AIndex, int Value);
	void __fastcall SetHasCode(TcxHitCode ACode, bool AValue);
	void __fastcall SetHitPoint(const System::Types::TPoint APoint);
	void __fastcall SetHitTestItem(System::TObject* AItem);
	void __fastcall SetIsMouseEvent(bool Value);
	
protected:
	TcxHitCode FHitState;
	virtual bool __fastcall AllowDesignMouseEvents(int X, int Y, System::Classes::TShiftState AShift);
	virtual bool __fastcall CanShowHint(System::TObject* AItem);
	void __fastcall ClearState(void);
	virtual void __fastcall DoCalculate(void);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(void);
	virtual bool __fastcall GetHitAtNavigator(void);
	virtual void __fastcall HitCodeChanged(int APrevCode);
	virtual void __fastcall HitTestItemChanged(System::TObject* APrevHitTestItem);
	void __fastcall RecalculateOnMouseEvent(int X, int Y, System::Classes::TShiftState AShift);
	__property TcxEditingControl* Control = {read=GetControl};
	__property TcxCustomControlController* Controller = {read=FController};
	__property TcxHotTrackController* HotTrackController = {read=GetHotTrackController};
	__property bool IsMouseEvent = {read=GetIsMouseEvent, write=SetIsMouseEvent, nodefault};
	__property System::Classes::TShiftState Shift = {read=FShift, nodefault};
	__property TcxCustomControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomHitTestController(TcxCustomControlController* AOwner);
	__fastcall virtual ~TcxCustomHitTestController(void);
	void __fastcall CheckDestroyingItem(System::TObject* AItem);
	void __fastcall ReCalculate(void)/* overload */;
	void __fastcall ReCalculate(const System::Types::TPoint APoint)/* overload */;
	__property TcxEditCellViewInfo* EditCellViewInfo = {read=GetEditCellViewInfo};
	__property bool HitAtNavigator = {read=GetHitAtNavigator, nodefault};
	__property System::Types::TPoint HitPoint = {read=FHitPoint, write=SetHitPoint};
	__property int HitX = {read=GetCoordinate, write=SetCoordinate, index=0, nodefault};
	__property int HitY = {read=GetCoordinate, write=SetCoordinate, index=1, nodefault};
	__property TcxHitCode HitState = {read=FHitState};
	__property bool HitCode[TcxHitCode ACode] = {read=GetHasCode, write=SetHasCode};
	__property System::TObject* HitTestItem = {read=FHitTestItem, write=SetHitTestItem};
	__property bool IsItemEditCell = {read=GetIsItemEditCell, nodefault};
};


class DELPHICLASS TcxCustomCellNavigator;
class PASCALIMPLEMENTATION TcxCustomCellNavigator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomControlController* FController;
	bool FEatKeyPress;
	bool FDownOnEnter;
	bool FDownOnTab;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	
protected:
	int RowCount;
	virtual TcxCustomInplaceEditContainer* __fastcall SelectCell(bool AForward, bool ANextRow, int &ARowIndex, int &ACellIndex);
	virtual void __fastcall CalcNextRow(bool AForward, int &ARowIndex, int &ACellIndex);
	virtual TcxCustomInplaceEditContainer* __fastcall GetCellContainer(int ARowIndex, int ACellIndex);
	virtual int __fastcall GetCount(int ARowIndex);
	virtual void __fastcall Init(int &ARowIndex, int &ACellIndex, int &ARowCount);
	virtual bool __fastcall MayFocusedEmptyRow(int ARowIndex);
	virtual void __fastcall SetFocusCell(int ARowIndex, int ACellIndex, System::Classes::TShiftState AShift);
	virtual void __fastcall DoKeyPress(System::WideChar &Key);
	__property bool DownOnEnter = {read=FDownOnEnter, write=FDownOnEnter, nodefault};
	__property bool DownOnTab = {read=FDownOnTab, write=FDownOnTab, nodefault};
	
public:
	__fastcall virtual TcxCustomCellNavigator(TcxCustomControlController* AController);
	virtual bool __fastcall FocusNextCell(bool AForward, bool ANextRow, System::Classes::TShiftState AShift = System::Classes::TShiftState() );
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Refresh(void);
	__property int Count[int ARowIndex] = {read=GetCount};
	__property TcxCustomControlController* Controller = {read=FController};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property bool EatKeyPress = {read=FEatKeyPress, write=FEatKeyPress, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomCellNavigator(void) { }
	
};


typedef System::TMetaClass* TcxCustomCellNavigatorClass;

class DELPHICLASS TcxCustomDesignSelectionHelper;
class PASCALIMPLEMENTATION TcxCustomDesignSelectionHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxEditingControl* FControl;
	TcxCustomControlController* __fastcall GetController(void);
	
protected:
	__property TcxEditingControl* Control = {read=FControl};
	__property TcxCustomControlController* Controller = {read=GetController};
	
public:
	__fastcall virtual TcxCustomDesignSelectionHelper(TcxEditingControl* AControl);
	virtual bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject) = 0 ;
	virtual void __fastcall Select(System::Classes::TPersistent* AObject, System::Classes::TShiftState AShift) = 0 ;
	virtual void __fastcall SetSelection(System::Classes::TList* AList) = 0 ;
	virtual void __fastcall UnselectObject(System::Classes::TPersistent* AObject) = 0 ;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomDesignSelectionHelper(void) { }
	
};


typedef System::TMetaClass* TcxCustomDesignSelectionHelperClass;

class DELPHICLASS TcxEditingController;
class PASCALIMPLEMENTATION TcxCustomControlController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FAllowCheckEdit;
	bool FBlockRecordKeyboardHandling;
	bool FCheckEditNeeded;
	bool FDisableCellsRefresh;
	bool FDragCancel;
	System::TObject* FDragItem;
	bool FEatKeyPress;
	bool FEditingBeforeDrag;
	TcxEditingController* FEditingController;
	TcxEditingControl* FEditingControl;
	bool FFocused;
	TcxCustomInplaceEditContainer* FFocusedItem;
	TcxCustomHitTestController* FHitTestController;
	TcxHotTrackController* FHotTrackController;
	bool FIsDblClick;
	bool FIsHandleTabStop;
	TcxCustomCellNavigator* FNavigator;
	bool FWasFocusedBeforeClick;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	TcxCustomDesignSelectionHelper* __fastcall GetDesignSelectionHelper(void);
	TcxCustomInplaceEditContainer* __fastcall GetEditingItem(void);
	bool __fastcall GetIsEditing(void);
	TcxCustomInplaceEditContainer* __fastcall GetItemForIncSearching(void);
	void __fastcall SetEditingItem(TcxCustomInplaceEditContainer* Value);
	void __fastcall SetIncSearchingText(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall MouseEnter(void);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeforeEditKeyDown(System::Word &Key, System::Classes::TShiftState &Shift);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall BeforePaint(void);
	virtual void __fastcall BeforeShowEdit(void);
	virtual void __fastcall BehaviorChanged(void);
	void __fastcall CancelCheckEditPost(void);
	virtual bool __fastcall CanHandleDeleteRecordKeys(void);
	virtual bool __fastcall CanFocusedRecordIndex(NativeInt AIndex);
	virtual bool __fastcall CanShowHint(void);
	virtual void __fastcall CheckEdit(void);
	virtual void __fastcall DoEditDblClick(System::TObject* Sender);
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoNextPage(bool AForward, System::Classes::TShiftState Shift);
	virtual TcxEditCellViewInfo* __fastcall GetEditingViewInfo(void);
	virtual bool __fastcall GetFocused(void);
	virtual TcxEditCellViewInfo* __fastcall GetFocusedCellViewInfo(TcxCustomInplaceEditContainer* AEditContainer);
	virtual NativeInt __fastcall GetFocusedRecordIndex(void);
	virtual TcxDragSizingDirection __fastcall GetResizeDirection(void);
	virtual void __fastcall FocusedItemChanged(TcxCustomInplaceEditContainer* APrevFocusedItem);
	virtual void __fastcall FocusedRecordChanged(int APrevFocusedRecordIndex, int AFocusedRecordIndex);
	virtual bool __fastcall HasFocusedControls(void);
	virtual void __fastcall HideHint(void);
	virtual System::Word __fastcall IncSearchKeyDown(System::Word AKey, System::Classes::TShiftState AShift);
	void __fastcall InternalSetFocusedItem(TcxCustomInplaceEditContainer* Value);
	virtual bool __fastcall IsImmediatePost(void);
	virtual bool __fastcall IsKeyForController(System::Word AKey, System::Classes::TShiftState AShift);
	void __fastcall PostCheckEdit(void);
	void __fastcall PostShowEdit(void);
	void __fastcall ProcessCheckEditPost(void);
	virtual void __fastcall RefreshFocusedCellViewInfo(TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall RefreshFocusedRecord(void);
	virtual void __fastcall SetFocused(bool Value);
	virtual void __fastcall SetFocusedItem(TcxCustomInplaceEditContainer* Value);
	virtual void __fastcall SetFocusedRecordIndex(NativeInt Value);
	virtual bool __fastcall GetAlwaysShowEditor(void);
	virtual bool __fastcall GetCancelEditingOnExit(void);
	virtual bool __fastcall GetFocusCellOnCycle(void);
	virtual bool __fastcall GetGoToNextCellOnEnter(void);
	virtual bool __fastcall GetGoToNextCellOnTab(void);
	virtual bool __fastcall GetImmediateEditor(void);
	virtual void __fastcall BeforeStartDrag(void);
	virtual bool __fastcall CanDrag(int X, int Y);
	virtual void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	TcxCustomControlDragAndDropObject* __fastcall GetDragAndDropObject(void);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual bool __fastcall GetIsDragging(void);
	virtual TcxCustomCellNavigatorClass __fastcall GetNavigatorClass(void);
	virtual void __fastcall StartDrag(Vcl::Controls::TDragObject* &DragObject);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall DoEnter(void);
	virtual void __fastcall DoExit(void);
	virtual bool __fastcall MayFocus(void);
	virtual void __fastcall FocusChanged(void);
	virtual void __fastcall RemoveFocus(void);
	virtual void __fastcall SetFocus(void);
	virtual void __fastcall CancelIncSearching(void);
	virtual TcxCustomInplaceEditContainer* __fastcall GetIncSearchingItem(void);
	virtual System::UnicodeString __fastcall GetIncSearchingText(void);
	virtual bool __fastcall GetIsIncSearching(void);
	virtual void __fastcall SearchLocate(TcxCustomInplaceEditContainer* AItem, const System::UnicodeString Value);
	virtual void __fastcall SearchLocateNext(TcxCustomInplaceEditContainer* AItem, bool AForward);
	virtual void __fastcall UpdateRecord(NativeInt ARecordIndex);
	virtual void __fastcall ViewInfoChanged(void);
	__property bool AllowCheckEdit = {read=FAllowCheckEdit, write=FAllowCheckEdit, nodefault};
	__property bool BlockRecordKeyboardHandling = {read=FBlockRecordKeyboardHandling, write=FBlockRecordKeyboardHandling, nodefault};
	__property TcxCustomDesignSelectionHelper* DesignSelectionHelper = {read=GetDesignSelectionHelper};
	__property bool DisableCellsRefresh = {read=FDisableCellsRefresh, write=FDisableCellsRefresh, nodefault};
	__property TcxCustomControlDragAndDropObject* DragAndDropObject = {read=GetDragAndDropObject};
	__property bool DragCancel = {read=FDragCancel, write=FDragCancel, nodefault};
	__property System::TObject* DragItem = {read=FDragItem, write=FDragItem};
	__property bool EatKeyPress = {read=FEatKeyPress, write=FEatKeyPress, nodefault};
	__property TcxEditingControl* EditingControl = {read=FEditingControl};
	__property TcxEditingController* EditingController = {read=FEditingController};
	__property TcxCustomInplaceEditContainer* EditingItem = {read=GetEditingItem, write=SetEditingItem};
	__property TcxEditCellViewInfo* EditingViewInfo = {read=GetEditingViewInfo};
	__property TcxHotTrackController* HotTrackController = {read=FHotTrackController};
	__property TcxCustomHitTestController* HitTestController = {read=FHitTestController};
	__property System::UnicodeString IncSearchingText = {read=GetIncSearchingText, write=SetIncSearchingText};
	__property TcxCustomInplaceEditContainer* IncSearchingItem = {read=GetIncSearchingItem};
	__property bool IsHandleTabStop = {read=FIsHandleTabStop, write=FIsHandleTabStop, nodefault};
	__property bool IsDragging = {read=GetIsDragging, nodefault};
	__property bool IsIncSearching = {read=GetIsIncSearching, nodefault};
	__property TcxCustomInplaceEditContainer* ItemForIncSearching = {read=GetItemForIncSearching};
	__property TcxCustomCellNavigator* Navigator = {read=FNavigator};
	__property bool WasFocusedBeforeClick = {read=FWasFocusedBeforeClick, write=FWasFocusedBeforeClick, nodefault};
	
public:
	__fastcall virtual TcxCustomControlController(TcxEditingControl* AOwner);
	__fastcall virtual ~TcxCustomControlController(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall ControlFocusChanged(void);
	virtual void __fastcall DblClick(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall Reset(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SetFocusedRecordItem(NativeInt ARecordIndex, TcxCustomInplaceEditContainer* AItem);
	void __fastcall SetScrollBarInfo(Vcl::Forms::TScrollBarKind AScrollBarKind, int AMin, int AMax, int AStep, int APage, int APos, bool AAllowShow, bool AAllowHide);
	virtual void __fastcall MakeFocusedItemVisible(void);
	virtual void __fastcall MakeFocusedRecordVisible(void);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property TcxCustomInplaceEditContainer* FocusedItem = {read=FFocusedItem, write=SetFocusedItem};
	__property NativeInt FocusedRecordIndex = {read=GetFocusedRecordIndex, write=SetFocusedRecordIndex};
	__property bool IsDblClick = {read=FIsDblClick, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
};


class PASCALIMPLEMENTATION TcxEditingController : public Cxedit::TcxCustomEditingController
{
	typedef Cxedit::TcxCustomEditingController inherited;
	
private:
	TcxCustomControlController* FController;
	TcxCustomInplaceEditContainer* FEditingItem;
	bool FEditingItemSetting;
	TcxCustomInplaceEditContainer* FEditShowingTimerItem;
	TcxEditCellViewInfo* __fastcall GetEditingCellViewInfo(void);
	TcxEditingControl* __fastcall GetEditingControl(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetEditingProperties(void);
	bool __fastcall GetIsDragging(void);
	void __fastcall SetEditingItem(TcxCustomInplaceEditContainer* Value);
	
protected:
	virtual bool __fastcall CanHideEdit(void);
	virtual bool __fastcall CanInitEditing(void);
	virtual bool __fastcall CanUpdateEditValue(void);
	virtual void __fastcall ClearEditingItem(void);
	virtual void __fastcall DoHideEdit(bool Accept);
	virtual void __fastcall DoUpdateEdit(void);
	virtual bool __fastcall GetCancelEditingOnExit(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetEditParent(void);
	virtual System::Types::TRect __fastcall GetFocusedCellBounds(void);
	virtual bool __fastcall GetHideEditOnExit(void);
	virtual bool __fastcall GetHideEditOnFocusedRecordChange(void);
	virtual bool __fastcall GetIsEditing(void);
	virtual void __fastcall HideInplaceEditor(void);
	virtual bool __fastcall PrepareEdit(TcxCustomInplaceEditContainer* AItem, bool AIsMouseEvent);
	virtual void __fastcall StartEditingByTimer(void);
	virtual void __fastcall UpdateInplaceParamsPosition(void);
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	virtual void __fastcall EditAfterKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditChanged(System::TObject* Sender);
	virtual void __fastcall EditDblClick(System::TObject* Sender);
	virtual void __fastcall EditExit(System::TObject* Sender);
	virtual void __fastcall EditFocusChanged(System::TObject* Sender);
	virtual void __fastcall EditKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditKeyPress(System::TObject* Sender, System::WideChar &Key);
	virtual void __fastcall EditKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditValueChanged(System::TObject* Sender);
	__property TcxCustomControlController* Controller = {read=FController};
	__property TcxEditCellViewInfo* EditingCellViewInfo = {read=GetEditingCellViewInfo};
	__property TcxEditingControl* EditingControl = {read=GetEditingControl};
	__property Cxedit::TcxCustomEditProperties* EditingProperties = {read=GetEditingProperties};
	__property bool HideEditOnFocusedRecordChange = {read=GetHideEditOnFocusedRecordChange, nodefault};
	
public:
	__fastcall virtual TcxEditingController(TcxCustomControlController* AController);
	virtual void __fastcall HideEdit(bool Accept);
	void __fastcall ShowEdit(TcxCustomInplaceEditContainer* AItem = (TcxCustomInplaceEditContainer*)(0x0))/* overload */;
	void __fastcall ShowEdit(TcxCustomInplaceEditContainer* AItem, System::WideChar Key)/* overload */;
	void __fastcall ShowEdit(TcxCustomInplaceEditContainer* AItem, System::Classes::TShiftState Shift, int X, int Y)/* overload */;
	HIDESBASE void __fastcall StartEditShowingTimer(TcxCustomInplaceEditContainer* AItem);
	__property TcxCustomInplaceEditContainer* EditingItem = {read=FEditingItem, write=SetEditingItem};
	__property bool IsDragging = {read=GetIsDragging, nodefault};
public:
	/* TcxCustomEditingController.Destroy */ inline __fastcall virtual ~TcxEditingController(void) { }
	
};


class DELPHICLASS TcxCustomControlPainter;
class PASCALIMPLEMENTATION TcxCustomControlViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxEditingControl* FControl;
	System::Types::TRect FClientRect;
	int FDefaultEditHeight;
	System::Classes::TList* FEditCellViewInfoList;
	TcxCustomControlPainter* FPainter;
	int FState;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	bool __fastcall GetState(int AMask);
	void __fastcall SetState(int AMask, bool Value);
	void __fastcall UpdateSelectionParams(void);
	
protected:
	Vcl::Graphics::TBrush* Brush;
	Vcl::Graphics::TBrush* SelectionBrush;
	Cxgraphics::TcxViewParams SelectionParams;
	TcxEditCellViewInfo* __fastcall AddEditCellViewInfo(TcxEditCellViewInfoClass AViewInfoClass, TcxCustomInplaceEditContainer* AEditContainer);
	virtual int __fastcall CalculateDefaultEditHeight(void);
	virtual void __fastcall CalculateDefaultHeights(void);
	void __fastcall ClearEditCellViewInfos(void);
	virtual void __fastcall CreatePainter(void);
	virtual void __fastcall DoCalculate(void);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint APoint);
	void __fastcall RemoveEditCellViewInfo(TcxEditCellViewInfo* AViewInfo);
	virtual void __fastcall SetFullPaintRegion(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall UpdateSelection(void);
	__property bool IsDirty = {read=GetState, write=SetState, index=1, nodefault};
	__property bool State[int AMask] = {read=GetState, write=SetState};
	
public:
	Cxgraphics::TcxViewParams ViewParams;
	__fastcall virtual TcxCustomControlViewInfo(TcxEditingControl* AOwner);
	__fastcall virtual ~TcxCustomControlViewInfo(void);
	void __fastcall Calculate(void);
	virtual void __fastcall Invalidate(bool ARecalculate = false);
	void __fastcall ValidateDirty(void);
	__property System::Types::TRect ClientRect = {read=FClientRect};
	__property TcxEditingControl* Control = {read=FControl};
	__property int DefaultEditHeight = {read=FDefaultEditHeight, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TcxCustomControlPainter* Painter = {read=FPainter, write=FPainter};
};


class DELPHICLASS TcxCustomViewInfoItem;
typedef void __fastcall (__closure *TcxCustomDrawCellEvent)(Cxgraphics::TcxCanvas* ACanvas, TcxCustomViewInfoItem* ACell, bool &ADone);

class DELPHICLASS TcxCustomControlCells;
class PASCALIMPLEMENTATION TcxCustomControlCells : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxCustomViewInfoItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxCustomViewInfoItem* __fastcall GetItem(int AIndex);
	
public:
	void __fastcall BeforePaint(void);
	bool __fastcall CalculateHitTest(TcxCustomHitTestController* AHitTest);
	virtual void __fastcall Clear(void);
	void __fastcall DeleteAll(void);
	void __fastcall ExcludeFromClipping(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas, TcxCustomDrawCellEvent AHandler);
	__property TcxCustomViewInfoItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxCustomControlCells(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxCustomControlCells(void) { }
	
};


typedef System::TMetaClass* TcxCustomControlViewInfoClass;

class DELPHICLASS TcxExtEditingControlViewInfo;
class DELPHICLASS TcxCustomNavigatorSiteViewInfo;
class PASCALIMPLEMENTATION TcxExtEditingControlViewInfo : public TcxCustomControlViewInfo
{
	typedef TcxCustomControlViewInfo inherited;
	
private:
	TcxCustomNavigatorSiteViewInfo* FNavigatorSiteViewInfo;
	TcxExtEditingControl* __fastcall GetControl(void);
	System::Types::TRect __fastcall GetNavigatorSiteVisibleRect(void);
	
protected:
	void __fastcall AddNavigatorSiteToPaintRegion(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall AdjustClientBounds(System::Types::TRect &ABounds);
	virtual void __fastcall CalculateNavigator(void);
	virtual bool __fastcall CanHScrollBarHide(void);
	virtual int __fastcall GetBottomNonClientHeight(void);
	virtual int __fastcall GetRightNonClientWidth(void);
	virtual void __fastcall GetHScrollBarBounds(System::Types::TRect &ABounds);
	virtual System::Types::TRect __fastcall GetNavigatorBounds(void);
	virtual bool __fastcall IsNavigatorSizeChanged(void);
	virtual bool __fastcall IsNavigatorVisible(void);
	virtual void __fastcall NavigatorInvalidate(void);
	virtual void __fastcall NavigatorStateChanged(void);
	virtual TcxCustomNavigatorSiteViewInfoClass __fastcall GetNavigatorSiteViewInfoClass(void);
	virtual bool __fastcall IsNavigatorSupported(void);
	virtual void __fastcall SetFullPaintRegion(Cxgraphics::TcxCanvas* ACanvas);
	__property TcxCustomNavigatorSiteViewInfo* NavigatorSiteViewInfo = {read=FNavigatorSiteViewInfo};
	__property System::Types::TRect NavigatorSiteVisibleRect = {read=GetNavigatorSiteVisibleRect};
	
public:
	__fastcall virtual TcxExtEditingControlViewInfo(TcxEditingControl* AOwner);
	__fastcall virtual ~TcxExtEditingControlViewInfo(void);
	virtual void __fastcall Invalidate(bool ARecalculate = false);
	__property TcxExtEditingControl* Control = {read=GetControl};
};


class PASCALIMPLEMENTATION TcxCustomViewInfoItem : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool FHasClipping;
	System::TObject* FOwner;
	bool FTransparent;
	bool FVisibleInfoCalculated;
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(void);
	TcxCustomControlViewInfo* __fastcall GetControlViewInfo(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	System::Types::TRect ClipRect;
	Cxgraphics::TcxCanvas* ControlCanvas;
	System::Types::TRect DisplayRect;
	Cxgraphics::TcxViewParams ItemViewParams;
	bool ItemVisible;
	System::Types::TRect VisibleBounds;
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall BeforeCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall CheckClipping(const System::Types::TRect &ADisplayRect, const System::Types::TRect &AAvailableRect)/* overload */;
	virtual void __fastcall CheckClipping(const System::Types::TRect &ADisplayRect)/* overload */;
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoHorzOffset(int AShift);
	virtual void __fastcall DoVertOffset(int AShift);
	bool __fastcall DrawBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual TcxEditingControl* __fastcall GetControl(void);
	virtual bool __fastcall GetHitTest(TcxCustomHitTestController* AHitTest);
	virtual bool __fastcall IsPersistent(void);
	virtual bool __fastcall IsTransparent(void);
	bool __fastcall ExcludeFromPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Scroll(const int DX, const int DY);
	void __fastcall UpdateEditRect(void);
	__property System::TObject* Owner = {read=FOwner};
	__property TcxCustomControlViewInfo* ControlViewInfo = {read=GetControlViewInfo};
	
public:
	__fastcall virtual TcxCustomViewInfoItem(System::TObject* AOwner);
	virtual void __fastcall Assign(TcxCustomViewInfoItem* Source);
	void __fastcall CheckVisibleInfo(void);
	__classmethod virtual int __fastcall CustomDrawID();
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Invalidate(bool ARecalculate = false)/* overload */;
	virtual void __fastcall Invalidate(const System::Types::TRect &R, bool AEraseBackground = false)/* overload */;
	__property Vcl::Graphics::TBitmap* Bitmap = {read=GetBitmap};
	__property System::Types::TRect BoundsRect = {read=DisplayRect};
	__property TcxEditingControl* Control = {read=GetControl};
	__property bool HasClipping = {read=FHasClipping, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainterClass = {read=GetPainter};
	__property bool Transparent = {read=FTransparent, write=FTransparent, nodefault};
	__property bool Visible = {read=ItemVisible, nodefault};
	__property bool VisibleInfoCalculated = {read=FVisibleInfoCalculated, write=FVisibleInfoCalculated, nodefault};
	__property System::Types::TRect VisibleRect = {read=ClipRect};
	__property Cxgraphics::TcxViewParams ViewParams = {read=ItemViewParams};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomViewInfoItem(void) { }
	
};


class PASCALIMPLEMENTATION TcxEditCellViewInfo : public TcxCustomViewInfoItem
{
	typedef TcxCustomViewInfoItem inherited;
	
private:
	bool __fastcall GetTransparent(void);
	void __fastcall SetTransparent(bool Value);
	
protected:
	Cxgraphics::TcxBorders CellBorders;
	System::Types::TRect CellContentRect;
	System::Types::TRect CellEditRect;
	int CellHeight;
	bool CellTransparent;
	System::Variant CellValue;
	bool IsViewDataCreated;
	Cxedit::TcxCustomEditProperties* Properties;
	Cxedit::TcxCustomEditViewInfo* ViewInfo;
	Cxedit::TcxCustomEditViewData* ViewData;
	virtual System::Types::TRect __fastcall GetHintBounds(void);
	virtual bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint);
	virtual void __fastcall UpdateHotTrackState(const System::Types::TPoint APoint);
	bool __fastcall HasHintPoint(const System::Types::TPoint P);
	bool __fastcall IsHintAtMousePos(void);
	bool __fastcall UseHintHidePause(void);
	Cxedit::TcxCustomEditViewData* __fastcall GetViewData(/* out */ bool &AIsViewDataCreated);
	void __fastcall EditOwnerInvalidate(const System::Types::TRect &R, bool AEraseBackground);
	int __fastcall CalculateEditHeight(void);
	int __fastcall CalculateEditWidth(void);
	virtual bool __fastcall ChangedHeight(int APrevHeight, int ANewHeight);
	virtual void __fastcall CheckClipping(const System::Types::TRect &ADisplayRect, const System::Types::TRect &AAvailableRect)/* overload */;
	virtual System::Types::TRect __fastcall ContentOffset(void);
	virtual System::Types::TPoint __fastcall CorrectHotTrackPoint(const System::Types::TPoint APoint);
	virtual void __fastcall DoCalculate(void);
	virtual Cxedit::TcxEditButtonTransparency __fastcall GetButtonTransparency(void);
	virtual System::Types::TPoint __fastcall GetCellOrg(void);
	virtual TcxEditingControl* __fastcall GetControl(void);
	virtual System::Variant __fastcall GetDisplayValue(void);
	virtual TcxCustomInplaceEditContainer* __fastcall GetEditContainer(void);
	virtual System::Types::TRect __fastcall GetEditRect(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetEditViewParams(void);
	virtual bool __fastcall GetFocused(void);
	Cxedit::TcxInplaceEditPosition __fastcall GetInplaceEditPosition(void);
	virtual int __fastcall GetMaxLineCount(void);
	virtual NativeInt __fastcall GetRecordIndex(void);
	virtual int __fastcall GetSelectedTextColor(void);
	virtual int __fastcall GetSelectedBKColor(void);
	virtual void * __fastcall GetViewInfoData(void);
	virtual bool __fastcall IsAutoHeight(void);
	virtual bool __fastcall IsEndEllipsis(void);
	virtual bool __fastcall IsSupportedHotTrack(void);
	void __fastcall SetBounds(const System::Types::TRect &ABounds, const System::Types::TRect &ADisplayRect);
	__property TcxCustomInplaceEditContainer* EditContainer = {read=GetEditContainer};
	__property System::Types::TRect EditRect = {read=GetEditRect};
	
public:
	__fastcall virtual ~TcxEditCellViewInfo(void);
	virtual void __fastcall Assign(TcxCustomViewInfoItem* Source);
	virtual bool __fastcall Refresh(bool ARecalculate);
	__property Cxgraphics::TcxBorders Borders = {read=CellBorders, nodefault};
	__property System::Types::TRect ContentRect = {read=CellContentRect};
	__property System::Variant DisplayValue = {read=CellValue};
	__property Cxedit::TcxCustomEditViewInfo* EditViewInfo = {read=ViewInfo};
	__property bool Focused = {read=GetFocused, nodefault};
	__property int MaxLineCount = {read=GetMaxLineCount, nodefault};
	__property NativeInt RecordIndex = {read=GetRecordIndex};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, nodefault};
	__property BoundsRect;
	__property Control;
	__property ViewParams;
	__property VisibleRect;
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxEditCellViewInfo(System::TObject* AOwner) : TcxCustomViewInfoItem(AOwner) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  CheckClipping(const System::Types::TRect &ADisplayRect){ TcxCustomViewInfoItem::CheckClipping(ADisplayRect); }
	
private:
	void *__IcxEditOwner;	/* Cxedit::IcxEditOwner */
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	void *__IcxHotTrackElement;	/* IcxHotTrackElement */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4129100C-7FC6-436E-8711-47A5C978CA73}
	operator Cxedit::_di_IcxEditOwner()
	{
		Cxedit::_di_IcxEditOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditOwner*(void) { return (Cxedit::IcxEditOwner*)&__IcxEditOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {228FF1F5-6D0C-40F0-9F7B-8C71CE12CEC8}
	operator Dxcustomhint::_di_IcxHintableObject()
	{
		Dxcustomhint::_di_IcxHintableObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomhint::IcxHintableObject*(void) { return (Dxcustomhint::IcxHintableObject*)&__IcxHintableObject; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E7171E58-276E-499B-9DDF-298D850883C9}
	operator _di_IcxHotTrackElement()
	{
		_di_IcxHotTrackElement intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxHotTrackElement*(void) { return (IcxHotTrackElement*)&__IcxHotTrackElement; }
	#endif
	
};


class DELPHICLASS TcxExtEditingControlNavigatorViewInfo;
class PASCALIMPLEMENTATION TcxExtEditingControlNavigatorViewInfo : public Cxnavigator::TcxInplaceNavigatorViewInfo
{
	typedef Cxnavigator::TcxInplaceNavigatorViewInfo inherited;
	
private:
	TcxExtEditingControl* FOwnerControl;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	virtual int __fastcall GetNavigatorOffset(void);
	virtual void __fastcall UpdateNavigatorSiteBounds(const System::Types::TRect &ABounds);
	
public:
	__fastcall virtual TcxExtEditingControlNavigatorViewInfo(TcxExtEditingControl* AOwnerControl);
public:
	/* TcxNavigatorViewInfo.Destroy */ inline __fastcall virtual ~TcxExtEditingControlNavigatorViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomNavigatorSiteViewInfo : public TcxCustomViewInfoItem
{
	typedef TcxCustomViewInfoItem inherited;
	
private:
	TcxExtEditingControlNavigatorViewInfo* FNavigatorViewInfo;
	TcxExtEditingControl* __fastcall GetOwnerControl(void);
	
protected:
	void __fastcall Calculate(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawEx(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxEditingControl* __fastcall GetControl(void);
	int __fastcall GetHeight(void);
	virtual bool __fastcall GetHitTest(TcxCustomHitTestController* AHitTest);
	System::Types::TRect __fastcall GetNavigatorBounds(void);
	int __fastcall GetWidth(void);
	bool __fastcall IsNavigatorSizeChanged(void);
	void __fastcall NavigatorStateChanged(void);
	void __fastcall UpdateBounds(const System::Types::TRect &ABounds);
	System::Types::TRect __fastcall GetHintBounds(void);
	bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint);
	void __fastcall UpdateHotTrackState(const System::Types::TPoint APoint);
	void __fastcall MouseDown(System::Uitypes::TMouseButton AButton, int X, int Y);
	void __fastcall MouseLeave(void);
	void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MouseUp(System::Uitypes::TMouseButton AButton, int X, int Y);
	__property TcxExtEditingControl* OwnerControl = {read=GetOwnerControl};
	
public:
	__fastcall virtual TcxCustomNavigatorSiteViewInfo(System::TObject* AOwner);
	__fastcall virtual ~TcxCustomNavigatorSiteViewInfo(void);
private:
	void *__IcxHotTrackElement;	/* IcxHotTrackElement */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E7171E58-276E-499B-9DDF-298D850883C9}
	operator _di_IcxHotTrackElement()
	{
		_di_IcxHotTrackElement intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxHotTrackElement*(void) { return (IcxHotTrackElement*)&__IcxHotTrackElement; }
	#endif
	
};


typedef void __fastcall (__closure *TcxCustomDrawViewInfoItemEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* Canvas, TcxCustomViewInfoItem* AViewInfo, bool &ADone);

class PASCALIMPLEMENTATION TcxCustomControlPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxEditingControl* FControl;
	Cxgraphics::TcxViewParams FSaveViewParams;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	TcxCustomControlViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AfterCustomDraw(TcxCustomViewInfoItem* AViewInfo)/* overload */;
	virtual void __fastcall BeforeCustomDraw(TcxCustomViewInfoItem* AViewInfo)/* overload */;
	bool __fastcall DoCustomDraw(TcxCustomViewInfoItem* AViewInfoItem, TcxCustomDrawViewInfoItemEvent AEvent);
	virtual void __fastcall DoPaintEditCell(TcxEditCellViewInfo* ACellViewInfo, bool AIsExcludeRect = true);
	virtual void __fastcall DoPaint(void);
	
public:
	__fastcall virtual TcxCustomControlPainter(TcxEditingControl* AOwner);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas, write=FCanvas};
	__property TcxEditingControl* Control = {read=FControl};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxCustomControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomControlPainter(void) { }
	
};


typedef System::TMetaClass* TcxCustomControlPainterClass;

class DELPHICLASS TcxExtEditingControlPainter;
class PASCALIMPLEMENTATION TcxExtEditingControlPainter : public TcxCustomControlPainter
{
	typedef TcxCustomControlPainter inherited;
	
private:
	HIDESBASE TcxExtEditingControlViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawNavigator(void);
	__property TcxExtEditingControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomControlPainter.Create */ inline __fastcall virtual TcxExtEditingControlPainter(TcxEditingControl* AOwner) : TcxCustomControlPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxExtEditingControlPainter(void) { }
	
};


typedef System::TMetaClass* TcxCustomControlStylesClass;

class PASCALIMPLEMENTATION TcxCustomControlStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	TcxOnGetContentStyleEvent FOnGetContentStyle;
	TcxEditingControl* __fastcall GetControl(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property Cxstyles::TcxStyle* Navigator = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* NavigatorInfoPanel = {read=GetValue, write=SetValue, index=5};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetBackgroundParams(void);
	Cxgraphics::TcxViewParams __fastcall GetSelectionParams(void);
	__property TcxEditingControl* Control = {read=GetControl};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetPainter};
	
__published:
	__property Cxstyles::TcxStyle* Background = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Inactive = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* Selection = {read=GetValue, write=SetValue, index=3};
	__property TcxOnGetContentStyleEvent OnGetContentStyle = {read=FOnGetContentStyle, write=FOnGetContentStyle};
	__property StyleSheet;
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxCustomControlStyles(System::Classes::TPersistent* AOwner) : Cxstyles::TcxStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxCustomControlStyles(void) { }
	
};


__interface IcxEditingControlOptions;
typedef System::DelphiInterface<IcxEditingControlOptions> _di_IcxEditingControlOptions;
__interface  INTERFACE_UUID("{6A041541-53E2-413B-8377-0D249356B5DF}") IcxEditingControlOptions  : public System::IInterface 
{
	
public:
	virtual TcxControlOptionsBehavior* __fastcall GetOptionsBehavior(void) = 0 ;
	virtual TcxControlOptionsData* __fastcall GetOptionsData(void) = 0 ;
	virtual TcxControlOptionsView* __fastcall GetOptionsView(void) = 0 ;
	__property TcxControlOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior};
	__property TcxControlOptionsData* OptionsData = {read=GetOptionsData};
	__property TcxControlOptionsView* OptionsView = {read=GetOptionsView};
};

typedef void __fastcall (__closure *TcxecEditingEvent)(System::TObject* Sender, System::TObject* AItem, bool &Allow);

typedef void __fastcall (__closure *TcxecInitEditEvent)(System::TObject* Sender, System::TObject* AItem, Cxedit::TcxCustomEdit* AEdit);

typedef void __fastcall (__closure *TcxecInitEditValueEvent)(System::TObject* Sender, System::TObject* AItem, Cxedit::TcxCustomEdit* AEdit, System::Variant &AValue);

typedef void __fastcall (__closure *TcxecItemEvent)(System::TObject* Sender, TcxCustomInplaceEditContainer* AItem);

class PASCALIMPLEMENTATION TcxEditingControl : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Cxgraphics::TcxBrushCache* FBrushCache;
	int FChangesCount;
	System::Classes::TList* FContainerList;
	TcxCustomDesignSelectionHelper* FDesignSelectionHelper;
	TcxDragImageHelper* FDragHelper;
	System::Types::TPoint FDragPos;
	Cxedit::TcxCustomEditStyle* FEditStyle;
	TcxCustomControlStyles* FStyles;
	bool FSubClassesCreated;
	TcxCustomControlViewInfo* FViewInfo;
	TcxCustomDrawViewInfoItemEvent FOnCustomDrawCell;
	TcxecItemEvent FOnEditChanged;
	TcxecItemEvent FOnEdited;
	TcxecEditingEvent FOnEditing;
	TcxecItemEvent FOnEditValueChanged;
	TcxecInitEditEvent FOnInitEdit;
	TcxecInitEditValueEvent FOnInitEditValue;
	bool __fastcall GetBufferedPaint(void);
	TcxCustomControlPainter* __fastcall GetPainter(void);
	void __fastcall DoMouseLeave(void);
	void __fastcall SetBufferedPaint(bool Value);
	void __fastcall SetEditStyle(Cxedit::TcxCustomEditStyle* Value);
	void __fastcall SetStyles(TcxCustomControlStyles* Value);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	
protected:
	TcxCustomControlController* FController;
	Cxcustomdata::TcxCustomDataController* FDataController;
	int FLockUpdate;
	virtual void __fastcall AfterLayoutChanged(void);
	DYNAMIC void __fastcall BeginAutoDrag(void);
	virtual void __fastcall BeforeUpdate(void);
	virtual void __fastcall CheckCreateDesignSelectionHelper(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall ControlUpdateData(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DataLayoutChanged(void);
	void __fastcall DestroyDesignSelectionHelper(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DoBeginUpdate(void);
	virtual void __fastcall DoEndUpdate(void);
	virtual void __fastcall DoEditChanged(TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoEdited(TcxCustomInplaceEditContainer* AItem);
	virtual bool __fastcall DoEditing(TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoEditValueChanged(TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoGetCellHint(System::TObject* ACell, System::UnicodeString &AText, bool &ANeedShow);
	virtual void __fastcall DoInitEdit(TcxCustomInplaceEditContainer* AItem, Cxedit::TcxCustomEdit* AEdit);
	virtual void __fastcall DoInitEditValue(TcxCustomInplaceEditContainer* AItem, Cxedit::TcxCustomEdit* AEdit, System::Variant &AValue);
	virtual void __fastcall DoInplaceEditContainerItemAdded(TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoInplaceEditContainerItemRemoved(TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoLayoutChanged(void);
	virtual TcxCustomControlControllerClass __fastcall GetControllerClass(void);
	virtual TcxCustomControlStylesClass __fastcall GetControlStylesClass(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual TcxDragImageHelperClass __fastcall GetDragImageHelperClass(void);
	virtual TcxCustomEditStyleClass __fastcall GetEditStyleClass(void);
	virtual TcxEditingControllerClass __fastcall GetEditingControllerClass(void);
	virtual TcxHitTestControllerClass __fastcall GetHitTestControllerClass(void);
	virtual TcxHotTrackControllerClass __fastcall GetHotTrackControllerClass(void);
	virtual TcxCustomControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual _di_IcxEditingControlOptions __fastcall GetOptions(void);
	virtual TcxCustomControlPainterClass __fastcall GetPainterClass(void);
	virtual int __fastcall GetHintHidePause(void);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	virtual bool __fastcall IsLocked(void);
	virtual void __fastcall RecreateViewInfo(void);
	virtual void __fastcall SelectionChanged(Cxcustomdata::TcxSelectionChangedInfo* AInfo);
	void __fastcall UpdateIndexes(void);
	void __fastcall UpdateViewStyles(void);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall FocusChanged(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall AfterMouseDown(System::Uitypes::TMouseButton AButton, int X, int Y);
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC bool __fastcall CanDrag(int X, int Y);
	DYNAMIC void __fastcall DoCancelMode(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual bool __fastcall GetIsFocused(void);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual void __fastcall InitControl(void);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint APoint);
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC bool __fastcall MayFocus(void);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual System::Types::TRect __fastcall DragDropImageDisplayRect(void);
	virtual void __fastcall DrawDragDropImage(Vcl::Graphics::TBitmap* ADragBitmap, Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall FinishDragImages(void);
	virtual bool __fastcall HasDragDropImages(void);
	virtual Cxcontrols::TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	DYNAMIC void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	DYNAMIC void __fastcall EndDragAndDrop(bool Accepted);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	__property Cxgraphics::TcxBrushCache* BrushCache = {read=FBrushCache};
	__property System::Classes::TList* ContainerList = {read=FContainerList};
	__property TcxCustomControlController* Controller = {read=FController};
	__property int ChangesCount = {read=FChangesCount, nodefault};
	__property System::Types::TPoint DragPos = {read=FDragPos, write=FDragPos};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=FDataController};
	__property TcxCustomDesignSelectionHelper* DesignSelectionHelper = {read=FDesignSelectionHelper};
	__property TcxDragImageHelper* DragHelper = {read=FDragHelper};
	__property Cxedit::TcxCustomEditStyle* EditStyle = {read=FEditStyle, write=SetEditStyle};
	__property _di_IcxEditingControlOptions Options = {read=GetOptions};
	__property TcxCustomControlPainter* Painter = {read=GetPainter};
	__property TcxCustomControlStyles* Styles = {read=FStyles, write=SetStyles};
	__property bool SubClassesCreated = {read=FSubClassesCreated, nodefault};
	__property TcxCustomControlViewInfo* ViewInfo = {read=FViewInfo, write=FViewInfo};
	__property TcxCustomDrawViewInfoItemEvent OnCustomDrawCell = {read=FOnCustomDrawCell, write=FOnCustomDrawCell};
	__property TcxecItemEvent OnEditChanged = {read=FOnEditChanged, write=FOnEditChanged};
	__property TcxecItemEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property TcxecEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property TcxecItemEvent OnEditValueChanged = {read=FOnEditValueChanged, write=FOnEditValueChanged};
	__property TcxecInitEditEvent OnInitEdit = {read=FOnInitEdit, write=FOnInitEdit};
	__property TcxecInitEditValueEvent OnInitEditValue = {read=FOnInitEditValue, write=FOnInitEditValue};
	
public:
	__fastcall virtual TcxEditingControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxEditingControl(void);
	void __fastcall BeginUpdate(void);
	DYNAMIC void __fastcall BeginDragAndDrop(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	void __fastcall LayoutChanged(void);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	__property bool BufferedPaint = {read=GetBufferedPaint, write=SetBufferedPaint, stored=false, nodefault};
	__property int LockUpdate = {read=FLockUpdate, nodefault};
	__property DragCursor = {default=0};
	__property TabStop = {default=1};
	
__published:
	__property BorderStyle = {default=1};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxEditingControl(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxExtEditingControl : public TcxEditingControl
{
	typedef TcxEditingControl inherited;
	
private:
	TcxControlNavigator* FNavigator;
	System::Classes::TNotifyEvent FNavigatorEvents;
	TcxControlOptionsBehavior* FOptionsBehavior;
	TcxControlOptionsData* FOptionsData;
	TcxControlOptionsView* FOptionsView;
	TcxControlOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TcxControlOptionsData* __fastcall GetOptionsData(void);
	TcxControlOptionsView* __fastcall GetOptionsView(void);
	TcxExtEditingControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetNavigator(TcxControlNavigator* Value);
	void __fastcall SetOptionsBehavior(TcxControlOptionsBehavior* Value);
	void __fastcall SetOptionsData(TcxControlOptionsData* Value);
	void __fastcall SetOptionsView(TcxControlOptionsView* Value);
	
protected:
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual System::Types::TRect __fastcall GetHScrollBarBounds(void);
	virtual Cxnavigator::_di_IcxNavigator __fastcall GetNavigatorButtonsControl(void);
	virtual void __fastcall SetPaintRegion(void);
	virtual void __fastcall NavigatorChanged(Cxnavigator::TcxNavigatorChangeType AChangeType);
	virtual System::Types::TRect __fastcall GetNavigatorBounds(void);
	virtual Cxnavigator::TcxCustomNavigatorButtons* __fastcall GetNavigatorButtons(void);
	virtual Vcl::Graphics::TCanvas* __fastcall GetNavigatorCanvas(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetNavigatorControl(void);
	virtual bool __fastcall GetNavigatorFocused(void);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetNavigatorLookAndFeel(void);
	virtual System::Classes::TComponent* __fastcall GetNavigatorOwner(void);
	virtual bool __fastcall GetNavigatorShowHint(void);
	virtual bool __fastcall GetNavigatorTabStop(void);
	virtual void __fastcall NavigatorStateChanged(void);
	virtual void __fastcall RefreshNavigator(void);
	virtual Cxnavigator::TcxCustomNavigatorInfoPanel* __fastcall GetNavigatorInfoPanel(void);
	virtual int __fastcall NavigatorGetRecordCount(void);
	virtual int __fastcall NavigatorGetRecordIndex(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual int __fastcall GetHintHidePause(void);
	virtual TcxControlNavigatorClass __fastcall GetNavigatorClass(void);
	virtual _di_IcxEditingControlOptions __fastcall GetOptions(void);
	virtual TcxControlOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual TcxControlOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual TcxControlOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual TcxCustomControlPainterClass __fastcall GetPainterClass(void);
	virtual TcxCustomControlViewInfoClass __fastcall GetViewInfoClass(void);
	__property TcxControlNavigator* Navigator = {read=FNavigator, write=SetNavigator};
	__property System::Classes::TNotifyEvent NavigatorEvents = {read=FNavigatorEvents, write=FNavigatorEvents};
	__property TcxControlOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxControlOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	__property TcxControlOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxExtEditingControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxEditingControl.Create */ inline __fastcall virtual TcxExtEditingControl(System::Classes::TComponent* AOwner) : TcxEditingControl(AOwner) { }
	/* TcxEditingControl.Destroy */ inline __fastcall virtual ~TcxExtEditingControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxExtEditingControl(HWND ParentWindow) : TcxEditingControl(ParentWindow) { }
	
private:
	void *__IcxNavigatorRecordPosition;	/* Cxnavigator::IcxNavigatorRecordPosition */
	void *__IcxNavigatorOwner2;	/* Cxnavigator::IcxNavigatorOwner2 */
	void *__IcxEditingControlOptions;	/* IcxEditingControlOptions */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {715C9E38-5BA0-4ED8-B35C-BB40EA739362}
	operator Cxnavigator::_di_IcxNavigatorRecordPosition()
	{
		Cxnavigator::_di_IcxNavigatorRecordPosition intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigatorRecordPosition*(void) { return (Cxnavigator::IcxNavigatorRecordPosition*)&__IcxNavigatorRecordPosition; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5AC3BE65-B332-40D4-9635-869F52634B17}
	operator Cxnavigator::_di_IcxNavigatorOwner2()
	{
		Cxnavigator::_di_IcxNavigatorOwner2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigatorOwner2*(void) { return (Cxnavigator::IcxNavigatorOwner2*)&__IcxNavigatorOwner2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {504B7F43-8847-46C5-B84A-C24F8E5E61A6}
	operator Cxnavigator::_di_IcxNavigatorOwner()
	{
		Cxnavigator::_di_IcxNavigatorOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigatorOwner*(void) { return (Cxnavigator::IcxNavigatorOwner*)&__IcxNavigatorOwner2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6A041541-53E2-413B-8377-0D249356B5DF}
	operator _di_IcxEditingControlOptions()
	{
		_di_IcxEditingControlOptions intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxEditingControlOptions*(void) { return (IcxEditingControlOptions*)&__IcxEditingControlOptions; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 ecs_Content = System::Int8(0x0);
static const System::Int8 ecs_Background = System::Int8(0x1);
static const System::Int8 ecs_Inactive = System::Int8(0x2);
static const System::Int8 ecs_Selection = System::Int8(0x3);
static const System::Int8 ecs_Navigator = System::Int8(0x4);
static const System::Int8 ecs_NavigatorInfoPanel = System::Int8(0x5);
static const System::Int8 ecs_EditContainerStylesMaxIndex = System::Int8(0x0);
static const System::Int8 ecs_EditingStylesMaxIndex = System::Int8(0x5);
static const System::Int8 echc_Empty = System::Int8(0x0);
static const System::Int8 echc_IsMouseEvent = System::Int8(0x1);
static const System::Int8 cvis_IsDirty = System::Int8(0x1);
static const System::Int8 cvis_StyleInvalid = System::Int8(0x2);
static const System::Int8 cxSizingMarkWidth = System::Int8(0x1);
static const System::Int8 cxScrollWidthDragInterval = System::Int8(0x32);
extern PACKAGE System::StaticArray<int, 2> cxIntOffs;
extern PACKAGE Cxedit::TcxEditSizeProperties cxDefaultEditSizeProp;
extern PACKAGE TcxCustomDesignSelectionHelperClass cxDesignSelectionHelperClass;
extern PACKAGE void __fastcall cxAssignEditStyle(TcxEditCellViewInfo* AViewInfo);
extern PACKAGE bool __fastcall cxPtInViewInfoItem(TcxCustomViewInfoItem* AItem, const System::Types::TPoint APoint);
extern PACKAGE bool __fastcall cxInRange(int Value, int AMin, int AMax);
extern PACKAGE bool __fastcall cxRange(int &Value, int AMin, int AMax);
extern PACKAGE int __fastcall cxSetValue(bool Condition, int ATrueValue, int AFalseValue);
extern PACKAGE bool __fastcall cxConfirmMessageBox(const System::UnicodeString AText, const System::UnicodeString ACaption);
}	/* namespace Cxinplacecontainer */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXINPLACECONTAINER)
using namespace Cxinplacecontainer;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxinplacecontainerHPP
