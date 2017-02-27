// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFilterControl.pas' rev: 24.00 (Win64)

#ifndef CxfiltercontrolHPP
#define CxfiltercontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxFormats.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxfiltercontrol
{
//-- type declarations -------------------------------------------------------
__interface IcxFilterControl;
typedef System::DelphiInterface<IcxFilterControl> _di_IcxFilterControl;
__interface  INTERFACE_UUID("{B9890E09-5400-428D-8F72-1FF8FD15937C}") IcxFilterControl  : public System::IInterface 
{
	
public:
	virtual System::UnicodeString __fastcall GetCaption(int Index) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	virtual Cxfilter::TcxFilterCriteria* __fastcall GetCriteria(void) = 0 ;
	virtual System::TObject* __fastcall GetItemLink(int Index) = 0 ;
	virtual int __fastcall GetItemLinkID(int Index) = 0 ;
	virtual System::UnicodeString __fastcall GetItemLinkName(int Index) = 0 ;
	virtual System::UnicodeString __fastcall GetFieldName(int Index) = 0 ;
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetProperties(int Index) = 0 ;
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueType(int Index) = 0 ;
	__property System::UnicodeString Captions[int Index] = {read=GetCaption};
	__property int Count = {read=GetCount};
	__property Cxfilter::TcxFilterCriteria* Criteria = {read=GetCriteria};
	__property System::UnicodeString ItemLinkNames[int Index] = {read=GetItemLinkName};
	__property int ItemLinkIDs[int Index] = {read=GetItemLinkID};
	__property System::TObject* ItemLinks[int Index] = {read=GetItemLink};
	__property System::UnicodeString FieldNames[int Index] = {read=GetFieldName};
	__property Cxedit::TcxCustomEditProperties* Properties[int Index] = {read=GetProperties};
	__property Cxdatastorage::TcxValueTypeClass ValueTypes[int Index] = {read=GetValueType};
};

__interface IcxFilterControlDialog;
typedef System::DelphiInterface<IcxFilterControlDialog> _di_IcxFilterControlDialog;
__interface  INTERFACE_UUID("{D2369F8D-3B22-41A8-881E-B01BEB624B7D}") IcxFilterControlDialog  : public System::IInterface 
{
	
public:
	virtual void __fastcall SetDialogLinkComponent(System::Classes::TComponent* ALink) = 0 ;
};

typedef System::TMetaClass* TcxCustomFilterControlClass;

typedef System::TMetaClass* TcxFilterControlViewInfoClass;

class DELPHICLASS TcxFilterControlCriteriaItem;
class DELPHICLASS TcxFilterControlCriteria;
class PASCALIMPLEMENTATION TcxFilterControlCriteriaItem : public Cxfilter::TcxFilterCriteriaItem
{
	typedef Cxfilter::TcxFilterCriteriaItem inherited;
	
private:
	TcxFilterControlCriteria* __fastcall GetFilterControlCriteria(void);
	_di_IcxFilterControl __fastcall GetFilter(void);
	int __fastcall GetItemIndex(void);
	bool __fastcall ValidItem(void);
	
protected:
	virtual System::Variant __fastcall GetDataValue(System::TObject* AData);
	virtual System::UnicodeString __fastcall GetFieldCaption(void);
	virtual System::UnicodeString __fastcall GetFieldName(void);
	virtual Cxfilter::TcxFilterOperatorClass __fastcall GetFilterOperatorClass(void);
	__property int ItemIndex = {read=GetItemIndex, nodefault};
	
public:
	__property _di_IcxFilterControl Filter = {read=GetFilter};
	__property TcxFilterControlCriteria* Criteria = {read=GetFilterControlCriteria};
public:
	/* TcxFilterCriteriaItem.Create */ inline __fastcall virtual TcxFilterControlCriteriaItem(Cxfilter::TcxFilterCriteriaItemList* AOwner, System::TObject* AItemLink, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue) : Cxfilter::TcxFilterCriteriaItem(AOwner, AItemLink, AOperatorKind, AValue, ADisplayValue) { }
	/* TcxFilterCriteriaItem.Destroy */ inline __fastcall virtual ~TcxFilterControlCriteriaItem(void) { }
	
};


class DELPHICLASS TcxCustomFilterControl;
class PASCALIMPLEMENTATION TcxFilterControlCriteria : public Cxfilter::TcxFilterCriteria
{
	typedef Cxfilter::TcxFilterCriteria inherited;
	
private:
	TcxCustomFilterControl* FControl;
	
protected:
	virtual int __fastcall GetIDByItemLink(System::TObject* AItemLink);
	virtual Cxfilter::TcxFilterCriteriaItemClass __fastcall GetItemClass(void);
	virtual System::TObject* __fastcall GetItemLinkByID(int AID);
	virtual System::UnicodeString __fastcall GetNameByItemLink(System::TObject* AItemLink);
	virtual System::TObject* __fastcall GetItemLinkByName(const System::UnicodeString AName);
	__property TcxCustomFilterControl* Control = {read=FControl};
	
public:
	__fastcall virtual TcxFilterControlCriteria(TcxCustomFilterControl* AOwner);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
public:
	/* TcxFilterCriteria.Destroy */ inline __fastcall virtual ~TcxFilterControlCriteria(void) { }
	
};


typedef System::TMetaClass* TcxFilterControlCriteriaClass;

enum TcxFilterControlHitTest : unsigned char { fhtNone, fhtButton, fhtBoolOperator, fhtItem, fhtOperator, fhtValue, fhtAddCondition, fhtAddValue };

class DELPHICLASS TcxCustomRowViewInfo;
struct DECLSPEC_DRECORD TcxFilterControlHitTestInfo
{
public:
	TcxFilterControlHitTest HitTest;
	System::Types::TPoint Mouse;
	System::Classes::TShiftState Shift;
	TcxCustomRowViewInfo* Row;
	int ValueIndex;
};


class DELPHICLASS TcxConditionViewInfo;
class DELPHICLASS TcxGroupViewInfo;
class PASCALIMPLEMENTATION TcxCustomRowViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FButtonText;
	System::Types::TRect FButtonRect;
	Cxlookandfeelpainters::TcxButtonState FButtonState;
	TcxCustomFilterControl* FControl;
	Cxfilter::TcxCustomFilterCriteriaItem* FCriteriaItem;
	int FLevel;
	int FIndent;
	TcxCustomRowViewInfo* FParent;
	System::Types::TRect FRowRect;
	TcxConditionViewInfo* __fastcall GetCondition(void);
	bool __fastcall GetFocused(void);
	TcxGroupViewInfo* __fastcall GetGroup(void);
	void __fastcall GetInternal(void);
	
protected:
	virtual int __fastcall GetWidth(void);
	bool __fastcall IsLast(void);
	
public:
	__fastcall virtual TcxCustomRowViewInfo(TcxCustomFilterControl* AControl, TcxCustomRowViewInfo* AParent, Cxfilter::TcxCustomFilterCriteriaItem* ACriteriaItem);
	__fastcall virtual ~TcxCustomRowViewInfo(void);
	virtual void __fastcall Calc(const System::Types::TRect &ARowRect);
	virtual void __fastcall GetHitTestInfo(const System::Types::TPoint P, TcxFilterControlHitTestInfo &HitInfo);
	virtual bool __fastcall Ready(void);
	__property System::Types::TRect ButtonRect = {read=FButtonRect, write=FButtonRect};
	__property Cxlookandfeelpainters::TcxButtonState ButtonState = {read=FButtonState, write=FButtonState, nodefault};
	__property System::UnicodeString ButtonText = {read=FButtonText, write=FButtonText};
	__property TcxConditionViewInfo* Condition = {read=GetCondition};
	__property TcxCustomFilterControl* Control = {read=FControl};
	__property Cxfilter::TcxCustomFilterCriteriaItem* CriteriaItem = {read=FCriteriaItem};
	__property bool Focused = {read=GetFocused, nodefault};
	__property TcxGroupViewInfo* Group = {read=GetGroup};
	__property int Indent = {read=FIndent, nodefault};
	__property int Level = {read=FLevel, nodefault};
	__property TcxCustomRowViewInfo* Parent = {read=FParent};
	__property System::Types::TRect RowRect = {read=FRowRect, write=FRowRect};
	__property int Width = {read=GetWidth, nodefault};
};


class PASCALIMPLEMENTATION TcxGroupViewInfo : public TcxCustomRowViewInfo
{
	typedef TcxCustomRowViewInfo inherited;
	
private:
	Cxfilter::TcxFilterBoolOperatorKind FBoolOperator;
	System::UnicodeString FBoolOperatorText;
	System::Types::TRect FBoolOperatorRect;
	System::UnicodeString FCaption;
	System::Types::TRect FCaptionRect;
	System::Classes::TList* FRows;
	TcxCustomRowViewInfo* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	void __fastcall SetRow(int Index, TcxCustomRowViewInfo* const Value);
	
protected:
	virtual int __fastcall GetWidth(void);
	
public:
	__fastcall virtual TcxGroupViewInfo(TcxCustomFilterControl* AControl, TcxCustomRowViewInfo* AParent, Cxfilter::TcxCustomFilterCriteriaItem* ACriteriaItem);
	__fastcall virtual ~TcxGroupViewInfo(void);
	void __fastcall Add(TcxCustomRowViewInfo* ARow);
	void __fastcall Remove(TcxCustomRowViewInfo* ARow);
	virtual void __fastcall Calc(const System::Types::TRect &ARowRect);
	virtual void __fastcall GetHitTestInfo(const System::Types::TPoint P, TcxFilterControlHitTestInfo &HitInfo);
	__property Cxfilter::TcxFilterBoolOperatorKind BoolOperator = {read=FBoolOperator, write=FBoolOperator, nodefault};
	__property System::UnicodeString BoolOperatorText = {read=FBoolOperatorText, write=FBoolOperatorText};
	__property System::Types::TRect BoolOperatorRect = {read=FBoolOperatorRect};
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxCustomRowViewInfo* Rows[int Index] = {read=GetRow, write=SetRow};
};


class DELPHICLASS TcxValueInfo;
class PASCALIMPLEMENTATION TcxValueInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Variant FValue;
	Vcl::Controls::TCaption FValueText;
	System::Types::TRect FValueRect;
	Cxedit::TcxCustomEditViewInfo* FValueViewInfo;
	void __fastcall SetValueViewInfo(Cxedit::TcxCustomEditViewInfo* const Value);
	
public:
	__fastcall TcxValueInfo(void);
	__fastcall virtual ~TcxValueInfo(void);
	__property System::Variant Value = {read=FValue, write=FValue};
	__property Vcl::Controls::TCaption ValueText = {read=FValueText, write=FValueText};
	__property System::Types::TRect ValueRect = {read=FValueRect, write=FValueRect};
	__property Cxedit::TcxCustomEditViewInfo* ValueViewInfo = {read=FValueViewInfo, write=SetValueViewInfo};
};


class DELPHICLASS TcxValuesViewInfo;
class PASCALIMPLEMENTATION TcxValuesViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxValueInfo* operator[](int Index) { return Values[Index]; }
	
private:
	System::Types::TRect FAddButtonRect;
	Cxlookandfeelpainters::TcxButtonState FAddButtonState;
	TcxConditionViewInfo* FCondition;
	System::Classes::TList* FList;
	System::UnicodeString FSeparator;
	TcxCustomFilterControl* __fastcall GetControl(void);
	TcxValueInfo* __fastcall GetValue(int Index);
	int __fastcall GetWidth(void);
	
protected:
	int __fastcall GetCount(void);
	void __fastcall UpdateEditorStyle(Cxedit::TcxCustomEditStyle* AStyle, bool AHightlited, bool AEnabled);
	
public:
	__fastcall TcxValuesViewInfo(TcxConditionViewInfo* ACondition);
	__fastcall virtual ~TcxValuesViewInfo(void);
	void __fastcall AddValue(void);
	void __fastcall Calc(void);
	void __fastcall Clear(void);
	virtual void __fastcall GetHitTestInfo(const System::Types::TPoint P, TcxFilterControlHitTestInfo &HitInfo);
	void __fastcall RemoveValue(int AIndex);
	__property System::Types::TRect AddButtonRect = {read=FAddButtonRect};
	__property Cxlookandfeelpainters::TcxButtonState AddButtonState = {read=FAddButtonState, nodefault};
	__property TcxConditionViewInfo* Condition = {read=FCondition};
	__property TcxCustomFilterControl* Control = {read=GetControl};
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString Separator = {read=FSeparator};
	__property TcxValueInfo* Values[int Index] = {read=GetValue/*, default*/};
	__property int Width = {read=GetWidth, nodefault};
};


class PASCALIMPLEMENTATION TcxConditionViewInfo : public TcxCustomRowViewInfo
{
	typedef TcxCustomRowViewInfo inherited;
	
private:
	Cxfiltercontrolutils::TcxFilterControlOperator FOperator;
	System::Types::TRect FOperatorRect;
	System::UnicodeString FOperatorText;
	int FItemIndex;
	System::TObject* FItemLink;
	System::Types::TRect FItemRect;
	System::UnicodeString FItemText;
	Cxfiltercontrolutils::TcxCustomFilterEditHelperClass FEditorHelper;
	Cxedit::TcxCustomEditProperties* FEditorProperties;
	Cxfiltercontrolutils::TcxFilterControlOperators FSupportedOperators;
	Cxdatastorage::TcxValueTypeClass FValueType;
	TcxValuesViewInfo* FValues;
	int __fastcall GetItemIndex(void);
	
protected:
	Cxedit::TcxCustomEditData* ValueEditorData;
	void __fastcall AddValue(void);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall HasDisplayValues(void);
	void __fastcall InitValues(bool ASaveValue);
	virtual void __fastcall InternalInit(void);
	void __fastcall SetItem(int AIndex);
	void __fastcall ValidateConditions(void);
	
public:
	__fastcall virtual TcxConditionViewInfo(TcxCustomFilterControl* AControl, TcxCustomRowViewInfo* AParent, Cxfilter::TcxCustomFilterCriteriaItem* ACriteriaItem);
	__fastcall virtual ~TcxConditionViewInfo(void);
	virtual void __fastcall Calc(const System::Types::TRect &ARowRect);
	virtual void __fastcall GetHitTestInfo(const System::Types::TPoint P, TcxFilterControlHitTestInfo &HitInfo);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void);
	virtual bool __fastcall Ready(void);
	__property Cxfiltercontrolutils::TcxCustomFilterEditHelperClass EditorHelper = {read=FEditorHelper};
	__property Cxedit::TcxCustomEditProperties* EditorProperties = {read=FEditorProperties};
	__property System::TObject* ItemLink = {read=FItemLink};
	__property int ItemIndex = {read=FItemIndex, nodefault};
	__property System::Types::TRect ItemRect = {read=FItemRect};
	__property System::UnicodeString ItemText = {read=FItemText, write=FItemText};
	__property Cxfiltercontrolutils::TcxFilterControlOperator Operator = {read=FOperator, write=FOperator, nodefault};
	__property System::Types::TRect OperatorRect = {read=FOperatorRect};
	__property System::UnicodeString OperatorText = {read=FOperatorText, write=FOperatorText};
	__property Cxfiltercontrolutils::TcxFilterControlOperators SupportedOperators = {read=FSupportedOperators};
	__property Cxdatastorage::TcxValueTypeClass ValueType = {read=FValueType};
	__property TcxValuesViewInfo* Values = {read=FValues};
};


class DELPHICLASS TcxFilterControlDropDownMenuInnerListBox;
class PASCALIMPLEMENTATION TcxFilterControlDropDownMenuInnerListBox : public Cxlistbox::TdxCustomDropDownInnerListBox
{
	typedef Cxlistbox::TdxCustomDropDownInnerListBox inherited;
	
private:
	bool FShowShortCut;
	bool __fastcall CheckAccelerators(System::Word AKey);
	
protected:
	virtual void __fastcall ClearIncrementalSearch(void);
	virtual bool __fastcall DoIncrementalSearch(System::WideChar &Key);
	virtual void __fastcall DrawItemText(const System::Types::TRect &R, Cxlistbox::TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual int __fastcall GetTextFlags(void);
	bool __fastcall IsIncSearch(void);
	virtual bool __fastcall IsIncSearchChar(System::WideChar AChar);
	virtual bool __fastcall ProcessKeyPress(System::WideChar &Key);
	virtual bool __fastcall ProcessNavigationKey(System::Word &Key, System::Classes::TShiftState Shift);
	
public:
	__property bool ShowShortCut = {read=FShowShortCut, write=FShowShortCut, nodefault};
public:
	/* TdxCustomDropDownInnerListBox.Create */ inline __fastcall virtual TcxFilterControlDropDownMenuInnerListBox(System::Classes::TComponent* AOwner) : Cxlistbox::TdxCustomDropDownInnerListBox(AOwner) { }
	
public:
	/* TdxCustomListBox.Destroy */ inline __fastcall virtual ~TcxFilterControlDropDownMenuInnerListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxFilterControlDropDownMenuInnerListBox(HWND ParentWindow) : Cxlistbox::TdxCustomDropDownInnerListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterControlDropDownMenu;
class PASCALIMPLEMENTATION TcxFilterControlDropDownMenu : public Cxlistbox::TdxCustomDropDownListBox
{
	typedef Cxlistbox::TdxCustomDropDownListBox inherited;
	
private:
	TcxCustomFilterControl* FControl;
	TcxFilterControlHitTestInfo FDroppedInfo;
	TcxFilterControlDropDownMenuInnerListBox* __fastcall GetInnerListBox(void);
	void __fastcall SaveDroppedInfo(void);
	
protected:
	virtual Cxlistbox::TdxCustomDropDownInnerListBox* __fastcall CreateInnerListBox(void);
	virtual void __fastcall DoCloseUp(bool AClosedViaKeyboard);
	virtual void __fastcall DoSelectItem(Cxlistbox::TdxCustomListBoxItem* AItem, bool ASelectedViaKeyboard);
	void __fastcall ClearDroppedInfo(void);
	void __fastcall CreateActionMenu(void);
	void __fastcall CreateItemList(System::Classes::TStrings* AList);
	void __fastcall CreateBoolOperatorList(void);
	void __fastcall CreateConditionList(System::Classes::TStrings* AList);
	bool __fastcall IsSameDroppedInfo(TcxFilterControlHitTestInfo &AInfo);
	__property TcxCustomFilterControl* Control = {read=FControl};
	__property TcxFilterControlDropDownMenuInnerListBox* InnerListBox = {read=GetInnerListBox};
	
public:
	__fastcall virtual TcxFilterControlDropDownMenu(TcxCustomFilterControl* AControl);
	HIDESBASE void __fastcall Popup(const System::Types::TRect &ABounds, const System::UnicodeString ACaption = System::UnicodeString(), System::WideChar AKey = (System::WideChar)(0x0));
public:
	/* TdxCustomDropDownListBox.CreateEx */ inline __fastcall TcxFilterControlDropDownMenu(Vcl::Controls::TWinControl* AOwnerControl, Cxcontrols::TcxControl* AOwnerParent) : Cxlistbox::TdxCustomDropDownListBox(AOwnerControl, AOwnerParent) { }
	/* TdxCustomDropDownListBox.Destroy */ inline __fastcall virtual ~TcxFilterControlDropDownMenu(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxFilterControlDropDownMenu(System::Classes::TComponent* AOwner, int Dummy) : Cxlistbox::TdxCustomDropDownListBox(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxFilterControlDropDownMenu(HWND ParentWindow) : Cxlistbox::TdxCustomDropDownListBox(ParentWindow) { }
	
};


enum TFilterControlState : unsigned char { fcsNormal, fcsSelectingAction, fcsSelectingItem, fcsSelectingBoolOperator, fcsSelectingCondition, fcsSelectingValue };

enum TcxFilterControlFont : unsigned char { fcfBoolOperator, fcfItem, fcfCondition, fcfValue };

typedef System::Set<TcxFilterControlFont, TcxFilterControlFont::fcfBoolOperator, TcxFilterControlFont::fcfValue>  TcxFilterControlFonts;

enum TcxActivateValueEditKind : unsigned char { aveEnter, aveKey, aveMouse };

class DELPHICLASS TcxFilterControlViewInfo;
class PASCALIMPLEMENTATION TcxCustomFilterControl : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TcxFilterControlFonts FAssignedFonts;
	TcxFilterControlCriteria* FCriteria;
	TcxFilterControlDropDownMenu* FDropDownMenu;
	TcxFilterControlHitTestInfo FFocusedInfo;
	System::StaticArray<Vcl::Graphics::TFont*, 4> FFonts;
	TcxFilterControlHitTestInfo FHotTrack;
	Cxedit::TcxInplaceEditList* FInplaceEditors;
	bool FIsFontsChangedLocked;
	int FLeftOffset;
	int FLockCount;
	TcxCustomRowViewInfo* FRoot;
	System::Classes::TList* FRows;
	bool FSortItems;
	TFilterControlState FState;
	Cxtextedit::TcxTextEditProperties* FTextEditProperties;
	int FTopVisibleRow;
	Cxedit::TcxCustomEdit* FValueEditor;
	Cxedit::TcxCustomEditStyle* FValueEditorStyle;
	TcxFilterControlViewInfo* FViewInfo;
	bool FHotTrackOnUnfocused;
	System::UnicodeString FNullstring;
	bool FShowLevelLines;
	bool FWantTabs;
	bool FWasError;
	System::Classes::TNotifyEvent FOnApplyFilter;
	void __fastcall CreateFonts(void);
	void __fastcall DoFontChanged(System::TObject* Sender);
	Vcl::Graphics::TFont* __fastcall GetFont(int Index);
	HIDESBASE bool __fastcall IsFontStored(int Index);
	HIDESBASE void __fastcall SetFont(int Index, Vcl::Graphics::TFont* const Value);
	int __fastcall FocusedRowIndex(void);
	TcxCustomRowViewInfo* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	TcxCustomRowViewInfo* __fastcall GetFocusedRow(void);
	void __fastcall DropDownMenuItemClick(int AIndex);
	void __fastcall SetFocusedRow(TcxCustomRowViewInfo* ARow);
	void __fastcall ActionMenuClick(int AIndex);
	bool __fastcall IsNullstringStored(void);
	void __fastcall ProcessHitTest(TcxFilterControlHitTest AHitTest, System::WideChar AKey);
	void __fastcall ReadData(System::Classes::TStream* AStream);
	void __fastcall RecalcRows(void);
	void __fastcall RefreshFonts(void);
	void __fastcall SetAssignedFonts(const TcxFilterControlFonts Value);
	void __fastcall SetLeftOffset(int Value);
	void __fastcall SetNullstring(const System::UnicodeString Value);
	void __fastcall SetTopVisibleRow(int Value);
	void __fastcall SetShowLevelLines(const bool Value);
	void __fastcall SetWantTabs(const bool Value);
	void __fastcall ValidateEditorPos(const System::Types::TRect &ABounds);
	void __fastcall ValueEditorInit(void);
	void __fastcall ValueEditorAfterKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ValueEditorExit(System::TObject* Sender);
	void __fastcall ValueEditorKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall WriteData(System::Classes::TStream* AStream);
	MESSAGE void __fastcall WMDropDownMenuClosed(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall DoLayoutChange(void);
	DYNAMIC void __fastcall FocusChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual int __fastcall GetBorderSize(void);
	virtual void __fastcall InitControl(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall AddCondition(TcxCustomRowViewInfo* ARow);
	void __fastcall AddGroup(void);
	void __fastcall AddValue(void);
	void __fastcall ClearRows(void);
	HIDESBASE void __fastcall Remove(void);
	void __fastcall RemoveRow(void);
	void __fastcall RemoveValue(void);
	void __fastcall FocusNext(bool ATab);
	void __fastcall FocusPrev(bool ATab);
	void __fastcall FocusUp(bool ATab);
	void __fastcall FocusDown(bool ATab);
	void __fastcall RowNavigate(TcxFilterControlHitTest AElement, int ACellIndex = 0xffffffff);
	void __fastcall ValueEditorHide(bool AAccept);
	void __fastcall Recalculate(void);
	void __fastcall EnsureRowVisible(void);
	void __fastcall RefreshProperties(void);
	virtual void __fastcall BuildFromCriteria(void);
	void __fastcall BuildFromRows(void);
	virtual void __fastcall CreateInternalControls(void);
	virtual void __fastcall DestroyInternalControls(void);
	virtual void __fastcall DoApplyFilter(void);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetDefaultProperties(void);
	Cxedit::TcxCustomEditViewInfo* __fastcall GetDefaultPropertiesViewInfo(void);
	virtual TcxFilterControlCriteriaClass __fastcall GetFilterControlCriteriaClass(void);
	virtual TcxFilterControlViewInfoClass __fastcall GetViewInfoClass(void);
	bool __fastcall HasFocus(void);
	bool __fastcall HasHotTrack(void);
	virtual void __fastcall FillFilterItemList(System::Classes::TStrings* AStrings);
	virtual void __fastcall FillConditionList(System::Classes::TStrings* AStrings);
	virtual void __fastcall ValidateConditions(Cxfiltercontrolutils::TcxFilterControlOperators &SupportedOperations);
	virtual void __fastcall CorrectOperatorClass(Cxfilter::TcxFilterOperatorClass &AOperatorClass);
	virtual System::UnicodeString __fastcall GetFilterCaption(void);
	virtual _di_IcxFilterControl __fastcall GetFilterLink(void);
	virtual System::UnicodeString __fastcall GetFilterText(void);
	virtual void __fastcall SelectAction(void);
	virtual void __fastcall SelectBoolOperator(System::WideChar AKey);
	virtual void __fastcall SelectCondition(System::WideChar AKey);
	virtual void __fastcall SelectItem(System::WideChar AKey);
	virtual void __fastcall SelectValue(TcxActivateValueEditKind AActivateKind, System::WideChar AKey);
	void __fastcall DoMouseLeave(void);
	void __fastcall FormatChanged(void);
	__property TcxFilterControlCriteria* Criteria = {read=FCriteria};
	__property TcxFilterControlDropDownMenu* DropDownMenu = {read=FDropDownMenu};
	__property _di_IcxFilterControl FilterLink = {read=GetFilterLink};
	__property TcxFilterControlHitTestInfo FocusedInfo = {read=FFocusedInfo};
	__property TcxCustomRowViewInfo* FocusedRow = {read=GetFocusedRow, write=SetFocusedRow};
	__property int LeftOffset = {read=FLeftOffset, write=SetLeftOffset, nodefault};
	__property System::UnicodeString Nullstring = {read=FNullstring, write=SetNullstring, stored=IsNullstringStored};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxCustomRowViewInfo* Rows[int Index] = {read=GetRow};
	__property TFilterControlState State = {read=FState, write=FState, nodefault};
	__property int TopVisibleRow = {read=FTopVisibleRow, write=SetTopVisibleRow, nodefault};
	__property TcxFilterControlViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxCustomFilterControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomFilterControl(void);
	void __fastcall ApplyFilter(void);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall Clear(void);
	void __fastcall EndUpdate(void);
	bool __fastcall IsNeedSynchronize(void);
	virtual bool __fastcall IsValid(void);
	bool __fastcall HasItems(void);
	void __fastcall LayoutChanged(void);
	void __fastcall Localize(void);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	virtual void __fastcall TranslationChanged(void);
	__property TcxFilterControlFonts AssignedFonts = {read=FAssignedFonts, write=SetAssignedFonts, default=0};
	__property Color = {default=-16777201};
	__property System::UnicodeString FilterCaption = {read=GetFilterCaption};
	__property System::UnicodeString FilterText = {read=GetFilterText};
	__property Vcl::Graphics::TFont* FontBoolOperator = {read=GetFont, write=SetFont, stored=IsFontStored, index=0};
	__property Vcl::Graphics::TFont* FontCondition = {read=GetFont, write=SetFont, stored=IsFontStored, index=2};
	__property Vcl::Graphics::TFont* FontItem = {read=GetFont, write=SetFont, stored=IsFontStored, index=1};
	__property Vcl::Graphics::TFont* FontValue = {read=GetFont, write=SetFont, stored=IsFontStored, index=3};
	__property bool HotTrackOnUnfocused = {read=FHotTrackOnUnfocused, write=FHotTrackOnUnfocused, default=1};
	__property LookAndFeel;
	__property ParentColor = {default=0};
	__property bool ShowLevelLines = {read=FShowLevelLines, write=SetShowLevelLines, default=1};
	__property bool SortItems = {read=FSortItems, write=FSortItems, default=0};
	__property bool WantTabs = {read=FWantTabs, write=SetWantTabs, default=0};
	__property System::Classes::TNotifyEvent OnApplyFilter = {read=FOnApplyFilter, write=FOnApplyFilter};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomFilterControl(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxFormatControllerListener;	/* Cxformats::IcxFormatControllerListener */
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A7F2F6D3-1A7D-4295-A6E6-9297BD83D0DE}
	operator Cxformats::_di_IcxFormatControllerListener()
	{
		Cxformats::_di_IcxFormatControllerListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener*(void) { return (Cxformats::IcxFormatControllerListener*)&__IcxFormatControllerListener; }
	#endif
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


class DELPHICLASS TcxFilterControlPainter;
class PASCALIMPLEMENTATION TcxFilterControlPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomFilterControl* FControl;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	TcxFilterControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall DrawGroup(TcxGroupViewInfo* ARow);
	void __fastcall DrawCondition(TcxConditionViewInfo* ARow);
	void __fastcall DrawValues(TcxConditionViewInfo* ARow);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetContentColor(void);
	void __fastcall DrawBorder(void);
	void __fastcall DrawDotLine(const System::Types::TRect &R);
	virtual void __fastcall DrawRow(TcxCustomRowViewInfo* ARow);
	void __fastcall TextDraw(int X, int Y, const System::UnicodeString AText);
	
public:
	__fastcall virtual TcxFilterControlPainter(TcxCustomFilterControl* AOwner);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property System::Uitypes::TColor ContentColor = {read=GetContentColor, nodefault};
	__property TcxCustomFilterControl* Control = {read=FControl};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxFilterControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterControlPainter(void) { }
	
};


typedef System::TMetaClass* TcxFilterControlPainterClass;

class PASCALIMPLEMENTATION TcxFilterControlViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomFilterControl* FControl;
	System::Types::TRect FAddConditionRect;
	System::UnicodeString FAddConditionCaption;
	Vcl::Graphics::TBitmap* FBitmap;
	Cxgraphics::TcxCanvas* FBitmapCanvas;
	Cxlookandfeelpainters::TcxButtonState FButtonState;
	System::Types::TRect FFocusRect;
	int FMaxRowWidth;
	TcxFilterControlPainter* FPainter;
	int FRowHeight;
	int FMinValueWidth;
	int FContentWidth;
	bool FEnabled;
	void __fastcall CalcButtonState(void);
	void __fastcall CheckBitmap(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	int __fastcall GetEditHeight(void);
	
protected:
	virtual void __fastcall CalcFocusRect(void);
	virtual TcxFilterControlPainterClass __fastcall GetPainterClass(void);
	void __fastcall ResetContentWidth(void);
	
public:
	__fastcall virtual TcxFilterControlViewInfo(TcxCustomFilterControl* AOwner);
	__fastcall virtual ~TcxFilterControlViewInfo(void);
	void __fastcall Calc(void);
	virtual void __fastcall GetHitTestInfo(System::Classes::TShiftState AShift, const System::Types::TPoint P, TcxFilterControlHitTestInfo &HitInfo);
	void __fastcall Paint(void);
	void __fastcall InvalidateRow(TcxCustomRowViewInfo* ARow);
	void __fastcall Update(void);
	__property System::UnicodeString AddConditionCaption = {read=FAddConditionCaption};
	__property System::Types::TRect AddConditionRect = {read=FAddConditionRect};
	__property Cxlookandfeelpainters::TcxButtonState ButtonState = {read=FButtonState, nodefault};
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property TcxCustomFilterControl* Control = {read=FControl};
	__property int ContentWidth = {read=FContentWidth, nodefault};
	__property bool Enabled = {read=FEnabled, nodefault};
	__property int MinValueWidth = {read=FMinValueWidth, nodefault};
	__property TcxFilterControlPainter* Painter = {read=FPainter};
	__property int RowHeight = {read=FRowHeight, nodefault};
};


class DELPHICLASS TcxFilterControl;
class PASCALIMPLEMENTATION TcxFilterControl : public TcxCustomFilterControl
{
	typedef TcxCustomFilterControl inherited;
	
private:
	System::Classes::TComponent* FLinkComponent;
	System::Classes::TComponent* __fastcall GetLinkComponent(void);
	void __fastcall SetLinkComponent(System::Classes::TComponent* Value);
	
protected:
	virtual _di_IcxFilterControl __fastcall GetFilterLink(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	void __fastcall UpdateFilter(void);
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AssignedFonts = {default=0};
	__property Color = {default=-16777201};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property FontBoolOperator;
	__property FontCondition;
	__property FontItem;
	__property FontValue;
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property HelpType = {default=1};
	__property Hint = {default=0};
	__property HotTrackOnUnfocused = {default=1};
	__property System::Classes::TComponent* LinkComponent = {read=GetLinkComponent, write=SetLinkComponent};
	__property LookAndFeel;
	__property Nullstring = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property ShowLevelLines = {default=1};
	__property SortItems = {default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property WantTabs = {default=0};
	__property OnApplyFilter;
	__property OnClick;
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomFilterControl.Create */ inline __fastcall virtual TcxFilterControl(System::Classes::TComponent* AOwner) : TcxCustomFilterControl(AOwner) { }
	/* TcxCustomFilterControl.Destroy */ inline __fastcall virtual ~TcxFilterControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxFilterControl(HWND ParentWindow) : TcxCustomFilterControl(ParentWindow) { }
	
private:
	void *__IcxFilterControlDialog;	/* IcxFilterControlDialog */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D2369F8D-3B22-41A8-881E-B01BEB624B7D}
	operator _di_IcxFilterControlDialog()
	{
		_di_IcxFilterControlDialog intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxFilterControlDialog*(void) { return (IcxFilterControlDialog*)&__IcxFilterControlDialog; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxFilterControlMaxDropDownRows = System::Int8(0xc);
extern PACKAGE int cxFilterControlIncSearchDelay;
extern PACKAGE System::UnicodeString __fastcall cxGetConditionText(Cxfiltercontrolutils::TcxFilterControlOperator AOperator);
extern PACKAGE bool __fastcall IsSupportFiltering(Cxedit::TcxCustomEditPropertiesClass AClass);
}	/* namespace Cxfiltercontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFILTERCONTROL)
using namespace Cxfiltercontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxfiltercontrolHPP
