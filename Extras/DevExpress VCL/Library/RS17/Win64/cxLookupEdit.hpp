// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLookupEdit.pas' rev: 24.00 (Win64)

#ifndef CxlookupeditHPP
#define CxlookupeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlookupedit
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TcxLookupGridCloseUpEvent)(System::TObject* Sender, bool AAccept);

class DELPHICLASS TcxCustomLookupEditLookupData;
class DELPHICLASS TcxCustomLookupEdit;
class DELPHICLASS TcxCustomLookupEditProperties;
class PASCALIMPLEMENTATION TcxCustomLookupEditLookupData : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	bool FVisible;
	System::Classes::TNotifyEvent FOnCurrentKeyChanged;
	System::Classes::TNotifyEvent FOnSelectItem;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	TcxCustomLookupEdit* __fastcall GetEdit(void);
	int __fastcall GetFocusedRecordIndex(void);
	int __fastcall GetListIndex(void);
	TcxCustomLookupEditProperties* __fastcall GetProperties(void);
	
protected:
	System::Variant FCurrentKey;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual bool __fastcall CanResizeVisualArea(System::Types::TSize &NewSize, int AMaxHeight = 0x0, int AMaxWidth = 0x0);
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall Deinitialize(void);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall DroppedDown(const System::UnicodeString AFindStr);
	virtual bool __fastcall Find(const System::UnicodeString AText);
	Vcl::Controls::TControl* __fastcall GetActiveControl(void);
	virtual System::Variant __fastcall GetCurrentKey(void);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::Variant &AKey);
	System::Classes::TNotifyEvent __fastcall GetOnCurrentKeyChanged(void);
	System::Classes::TNotifyEvent __fastcall GetOnSelectItem(void);
	virtual int __fastcall GetSelectedItem(void);
	System::Types::TSize __fastcall GetVisualAreaPreferredSize(int AMaxHeight, int AWidth = 0x0);
	virtual void __fastcall Go(Cxtextedit::TcxEditLookupDataGoDirection ADirection, bool ACircular);
	void __fastcall Initialize(Vcl::Controls::TWinControl* AVisualControlsParent);
	virtual bool __fastcall IsEmpty(void);
	bool __fastcall IsMouseOverList(const System::Types::TPoint P);
	virtual bool __fastcall Locate(System::UnicodeString &AText, System::UnicodeString &ATail, bool ANext);
	void __fastcall PositionVisualArea(const System::Types::TRect &AClientRect);
	virtual void __fastcall PropertiesChanged(void);
	virtual void __fastcall SelectItem(void);
	virtual void __fastcall SetCurrentKey(const System::Variant &AKey);
	void __fastcall SetOnCurrentKeyChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnSelectItem(System::Classes::TNotifyEvent Value);
	virtual void __fastcall SetSelectedItem(int Value);
	virtual void __fastcall TextChanged(void);
	virtual void __fastcall DoCurrentKeyChanged(void);
	virtual void __fastcall DoSelectItem(void);
	virtual void __fastcall DoSetCurrentKey(int ARecordIndex);
	void __fastcall DoSetKeySelection(bool AKeySelected);
	virtual void __fastcall DoSyncGrid(void);
	virtual void __fastcall GridClick(System::TObject* Sender);
	virtual void __fastcall GridCloseUp(System::TObject* Sender, bool AAccept);
	virtual void __fastcall GridFocusedRowChanged(System::TObject* Sender);
	virtual bool __fastcall IsKeySelected(void);
	virtual bool __fastcall LocateText(const System::UnicodeString AText);
	virtual void __fastcall ResetIncrementalFilter(void);
	virtual void __fastcall SyncGrid(void);
	virtual void __fastcall SyncSelected(void);
	virtual void __fastcall UpdateDropDownCount(void);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxCustomLookupEdit* Edit = {read=GetEdit};
	__property int FocusedRecordIndex = {read=GetFocusedRecordIndex, nodefault};
	__property TcxCustomLookupEditProperties* Properties = {read=GetProperties};
	
public:
	__fastcall virtual TcxCustomLookupEditLookupData(System::Classes::TPersistent* AOwner);
	void __fastcall DisableChanging(void);
	void __fastcall EnableChanging(void);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomLookupEditLookupData(void) { }
	
private:
	void *__IcxTextEditLookupData;	/* Cxtextedit::IcxTextEditLookupData */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F49C5F08-7758-4362-A360-1DF02354E708}
	operator Cxtextedit::_di_IcxTextEditLookupData()
	{
		Cxtextedit::_di_IcxTextEditLookupData intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxtextedit::IcxTextEditLookupData*(void) { return (Cxtextedit::IcxTextEditLookupData*)&__IcxTextEditLookupData; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxTextEditLookupData; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxCustomLookupEditProperties : public Cxdropdownedit::TcxCustomComboBoxProperties
{
	typedef Cxdropdownedit::TcxCustomComboBoxProperties inherited;
	
private:
	int FDisplayColumnIndex;
	int FLockCount;
	bool FImmediateUpdateText;
	bool FInGridDataChanged;
	bool FIncrementalFiltering;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	bool __fastcall GetDropDownAutoSize(void);
	int __fastcall GetDropDownHeight(void);
	HIDESBASE bool __fastcall GetDropDownSizeable(void);
	HIDESBASE int __fastcall GetDropDownWidth(void);
	void __fastcall SetDropDownAutoSize(bool Value);
	void __fastcall SetDropDownHeight(int Value);
	HIDESBASE void __fastcall SetDropDownSizeable(bool Value);
	HIDESBASE void __fastcall SetDropDownWidth(int Value);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual Vcl::Controls::TWinControl* __fastcall GetLookupGridActiveControl(void);
	virtual bool __fastcall GetLookupGridCanResize(void);
	virtual int __fastcall GetLookupGridColumnCount(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetLookupGridControl(void);
	virtual Cxcustomdata::TcxCustomDataController* __fastcall GetLookupGridDataController(void);
	virtual int __fastcall GetLookupGridVisualAreaPreferredWidth(void);
	virtual int __fastcall GetLookupGridNearestPopupHeight(int AHeight);
	virtual int __fastcall GetLookupGridPopupHeight(int ADropDownRowCount);
	virtual bool __fastcall IsLookupGridMouseOverList(const System::Types::TPoint P);
	virtual void __fastcall LookupGridDeinitialize(void);
	virtual void __fastcall LookupGridDroppedDown(const System::UnicodeString AFindStr);
	virtual void __fastcall LookupGridInitEvents(System::Classes::TNotifyEvent AOnClick, System::Classes::TNotifyEvent AOnFocusedRowChanged, TcxLookupGridCloseUpEvent AOnCloseUp);
	virtual void __fastcall LookupGridInitialize(void);
	virtual void __fastcall LookupGridInitLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, System::Uitypes::TColor AColor, Vcl::Graphics::TFont* AFont);
	virtual void __fastcall LookupGridLockMouseMove(void);
	virtual void __fastcall LookupGridMakeFocusedRowVisible(void);
	virtual void __fastcall LookupGridUnlockMouseMove(void);
	void __fastcall CheckDisplayColumnIndex(void);
	virtual void __fastcall DeinitializeDataController(void);
	virtual int __fastcall FindByText(int AItemIndex, const System::UnicodeString AText, bool APartialCompare);
	virtual bool __fastcall FindLookupText(const System::UnicodeString AText);
	virtual int __fastcall GetDisplayColumnIndex(void);
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	virtual System::UnicodeString __fastcall GetDisplayLookupText(const System::Variant &AKey);
	virtual bool __fastcall GetIncrementalFiltering(void);
	virtual int __fastcall GetListIndex(void);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	virtual System::Variant __fastcall GetNullKey(void);
	virtual void __fastcall GridDataChanged(System::TObject* Sender);
	virtual void __fastcall InitializeDataController(void);
	virtual bool __fastcall IsChangeLocked(void);
	virtual bool __fastcall IsDataChangedPostponed(void);
	virtual bool __fastcall IsEditValueConversionDependOnFocused(void);
	virtual bool __fastcall IsPickMode(void);
	virtual bool __fastcall IsPopupKey(System::Word Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LockDataChanged(void);
	virtual void __fastcall SetDisplayColumnIndex(int Value);
	virtual void __fastcall UnlockDataChanged(void);
	virtual void __fastcall UnlinkLookupGridControlParent(void);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property int DisplayColumnIndex = {read=GetDisplayColumnIndex, write=SetDisplayColumnIndex, default=0};
	__property bool ImmediateUpdateText = {read=FImmediateUpdateText, write=FImmediateUpdateText, default=0};
	
public:
	__fastcall virtual TcxCustomLookupEditProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	virtual bool __fastcall IsDefinedByLookup(void);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual bool __fastcall IsLookupField(void);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	__property bool DropDownAutoSize = {read=GetDropDownAutoSize, write=SetDropDownAutoSize, default=0};
	__property int DropDownHeight = {read=GetDropDownHeight, write=SetDropDownHeight, default=0};
	__property DropDownListStyle = {default=0};
	__property bool DropDownSizeable = {read=GetDropDownSizeable, write=SetDropDownSizeable, default=0};
	__property int DropDownWidth = {read=GetDropDownWidth, write=SetDropDownWidth, default=0};
	__property bool IncrementalFiltering = {read=FIncrementalFiltering, write=FIncrementalFiltering, default=1};
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomLookupEditProperties(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomLookupEdit : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	HIDESBASE Cxtextedit::_di_IcxTextEditLookupData __fastcall GetILookupData(void);
	HIDESBASE TcxCustomLookupEditLookupData* __fastcall GetLookupData(void);
	HIDESBASE TcxCustomLookupEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomLookupEditProperties* __fastcall GetActiveProperties(void);
	void __fastcall SetLookupData(TcxCustomLookupEditLookupData* Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomLookupEditProperties* Value);
	
protected:
	virtual void __fastcall AfterPosting(void);
	virtual void __fastcall BeforePosting(void);
	virtual void __fastcall DoShowEdit(void);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall Initialize(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	virtual bool __fastcall NeedResetInvalidTextWhenPropertiesChanged(void);
	virtual void __fastcall PrepareEditForInplaceActivation(void);
	virtual void __fastcall RepositoryItemAssigning(void);
	virtual bool __fastcall SupportsSpelling(void);
	virtual void __fastcall SynchronizeDisplayValue(void);
	__property Cxtextedit::_di_IcxTextEditLookupData ILookupData = {read=GetILookupData};
	__property TcxCustomLookupEditLookupData* LookupData = {read=GetLookupData, write=SetLookupData};
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomLookupEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomLookupEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxCustomLookupEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomLookupEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomLookupEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomLookupEdit(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxlookupedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLOOKUPEDIT)
using namespace Cxlookupedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlookupeditHPP
