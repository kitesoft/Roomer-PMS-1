// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFontNameComboBox.pas' rev: 24.00 (Win32)

#ifndef CxfontnamecomboboxHPP
#define CxfontnamecomboboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Printers.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxEditUtils.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxExtEditUtils.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxfontnamecombobox
{
//-- type declarations -------------------------------------------------------
enum TcxFontType : unsigned char { cxftTTF, cxftRaster, cxftDevice, cxftFixed, cxftSymbol };

typedef System::Set<TcxFontType, TcxFontType::cxftTTF, TcxFontType::cxftSymbol>  TcxFontTypes;

enum TcxShowFontIconType : unsigned char { ftiShowInCombo, ftiShowInList };

typedef System::Set<TcxShowFontIconType, TcxShowFontIconType::ftiShowInCombo, TcxShowFontIconType::ftiShowInList>  TcxShowFontIconTypes;

enum TcxMRUFontNameAction : unsigned char { mfaInvalidFontName, mfaNone, mfaMoved, mfaAdded, mfaDeleted };

enum TcxFontPreviewType : unsigned char { cxfpFontName, cxfpCustom, cxfpFullAlphabet };

typedef void __fastcall (__closure *TcxDeleteMRUFontEvent)(System::TObject* Sender, const System::UnicodeString DeletedMRUFontName);

class DELPHICLASS TcxMRUFontNameItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMRUFontNameItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Uitypes::TFontName FFontName;
	int FTag;
	bool __fastcall IsTagStored(void);
	void __fastcall SetFontName(const System::Uitypes::TFontName Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Uitypes::TFontName FontName = {read=FFontName, write=SetFontName};
	__property int Tag = {read=FTag, write=FTag, stored=IsTagStored, nodefault};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxMRUFontNameItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxMRUFontNameItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxMRUFontNameItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMRUFontNameItems : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TcxMRUFontNameItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxMRUFontNameItem* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, TcxMRUFontNameItem* const Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	HIDESBASE TcxMRUFontNameItem* __fastcall Add(void);
	HIDESBASE TcxMRUFontNameItem* __fastcall Insert(int Index);
	virtual TcxMRUFontNameItem* __fastcall AddMRUFontName(const System::Uitypes::TFontName AFontName);
	virtual TcxMRUFontNameItem* __fastcall InsertMRUFontName(int Index, const System::Uitypes::TFontName AFontName);
	virtual void __fastcall Move(int CurIndex, int NewIndex);
	
public:
	__fastcall TcxMRUFontNameItems(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass);
	__fastcall virtual ~TcxMRUFontNameItems(void);
	__property TcxMRUFontNameItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
	virtual TcxMRUFontNameItem* __fastcall FindFontName(const System::Uitypes::TFontName AFontName);
};

#pragma pack(pop)

class DELPHICLASS TcxFontLoader;
class PASCALIMPLEMENTATION TcxFontLoader : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	TcxFontTypes FFontTypes;
	void __fastcall DoCompleteEvent(void);
	void __fastcall DoDestroyEvent(void);
	
protected:
	virtual void __fastcall Execute(void);
	
public:
	System::Classes::TNotifyEvent OnCompleteThread;
	System::Classes::TNotifyEvent OnDestroyThread;
	System::Classes::TStringList* FontList;
	__fastcall virtual TcxFontLoader(const TcxFontTypes AFontTypes);
	__fastcall virtual ~TcxFontLoader(void);
};


enum TcxFontButtonType : unsigned char { cxfbtBold, cxfbtItalic, cxfbtUnderline, cxfbtStrikeOut };

typedef void __fastcall (__closure *TcxFontButtonClickEvent)(System::TObject* Sender, TcxFontButtonType ButtonType);

class DELPHICLASS TcxFontPreview;
class PASCALIMPLEMENTATION TcxFontPreview : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	int FUpdateCount;
	System::Classes::TNotifyEvent FOnChanged;
	System::Uitypes::TFontStyles FFontStyle;
	bool FModified;
	bool FIsDestroying;
	bool FVisible;
	TcxFontPreviewType FPreviewType;
	Vcl::Controls::TCaption FPreviewText;
	System::Classes::TAlignment FAlignment;
	bool FShowEndEllipsis;
	System::Uitypes::TColor FColor;
	bool FWordWrap;
	bool FShowButtons;
	TcxFontButtonClickEvent FOnButtonClick;
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	bool __fastcall IsDestroying(void);
	void __fastcall SetFontStyle(System::Uitypes::TFontStyles Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetPreviewType(TcxFontPreviewType Value);
	void __fastcall SetPreviewText(Vcl::Controls::TCaption Value);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetShowEndEllipsis(bool Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetWordWrap(bool Value);
	void __fastcall SetShowButtons(bool Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TcxFontPreview(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxFontPreview(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Uitypes::TFontStyles FontStyle = {read=FFontStyle, write=SetFontStyle, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property TcxFontPreviewType PreviewType = {read=FPreviewType, write=SetPreviewType, default=0};
	__property Vcl::Controls::TCaption PreviewText = {read=FPreviewText, write=SetPreviewText};
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=2};
	__property bool ShowButtons = {read=FShowButtons, write=SetShowButtons, default=1};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=SetShowEndEllipsis, default=1};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=-16777211};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
	__property TcxFontButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
};


class DELPHICLASS TcxFontPanelButton;
class PASCALIMPLEMENTATION TcxFontPanelButton : public Cxbuttons::TcxButton
{
	typedef Cxbuttons::TcxButton inherited;
	
protected:
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
public:
	/* TcxCustomButton.Create */ inline __fastcall virtual TcxFontPanelButton(System::Classes::TComponent* AOwner) : Cxbuttons::TcxButton(AOwner) { }
	/* TcxCustomButton.Destroy */ inline __fastcall virtual ~TcxFontPanelButton(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxFontPanelButton(HWND ParentWindow) : Cxbuttons::TcxButton(ParentWindow) { }
	
};


class DELPHICLASS TFontPreviewPanel;
class PASCALIMPLEMENTATION TFontPreviewPanel : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	bool FLocked;
	Cxgraphics::TcxCanvas* FcxCanvas;
	System::Uitypes::TFontStyles FFontStyle;
	System::Classes::TAlignment FAlignment;
	bool FShowEndEllipsis;
	Cxgraphics::TcxBorders FEdges;
	System::Uitypes::TColor FBorderColor;
	System::UnicodeString FFontName;
	bool FWordWrap;
	bool FShowButtons;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TcxFontPanelButton* FBoldButton;
	TcxFontPanelButton* FItalicButton;
	TcxFontPanelButton* FUnderLineButton;
	TcxFontPanelButton* FStrikeOutButton;
	void __fastcall SetLocked(bool Value);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetShowEndEllipsis(bool Value);
	void __fastcall SetEdges(Cxgraphics::TcxBorders Value);
	void __fastcall SetFontName(System::UnicodeString Value);
	void __fastcall SetFontStyle(System::Uitypes::TFontStyles Value);
	void __fastcall SetWordWrap(bool Value);
	void __fastcall SetShowButtons(bool Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	int __fastcall GetTextFlag(const int AStartFlag);
	void __fastcall CreateButtons(void);
	void __fastcall SetFontStyleButtonsState(void);
	void __fastcall FontButtonsClickHandler(System::TObject* Sender);
	
protected:
	TcxFontPreview* FontPreview;
	virtual void __fastcall Paint(void);
	virtual void __fastcall CalculateFont(const System::Types::TRect &ARect);
	virtual System::Uitypes::TFontStyles __fastcall CalculateFontStyle(void);
	__property Cxgraphics::TcxCanvas* cxCanvas = {read=FcxCanvas, write=FcxCanvas};
	__property bool Locked = {read=FLocked, write=SetLocked, default=0};
	
public:
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property Color = {default=-16777211};
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=2};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=SetShowEndEllipsis, default=1};
	__property Cxgraphics::TcxBorders Edges = {read=FEdges, write=SetEdges, default=15};
	__property System::Uitypes::TFontStyles FontStyle = {read=FFontStyle, write=SetFontStyle, default=0};
	__property System::UnicodeString FontName = {read=FFontName, write=SetFontName};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
	__property bool ShowButtons = {read=FShowButtons, write=SetShowButtons, default=1};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__fastcall virtual TFontPreviewPanel(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TFontPreviewPanel(void);
	void __fastcall RealignButtons(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TFontPreviewPanel(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TcxCustomFontNameComboBoxViewInfo;
class PASCALIMPLEMENTATION TcxCustomFontNameComboBoxViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
private:
	int FCurrentIndex;
	bool FIsTrueTypeFont;
	System::Types::TRect ImageRect;
	TcxShowFontIconTypes FShowFontTypeIcon;
	
protected:
	System::Types::TRect SaveClient;
	__property bool IsTrueTypeFont = {read=FIsTrueTypeFont, write=FIsTrueTypeFont, nodefault};
	__property TcxShowFontIconTypes ShowFontTypeIcon = {read=FShowFontTypeIcon, write=FShowFontTypeIcon, nodefault};
	
public:
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Offset(int DX, int DY);
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxCustomFontNameComboBoxViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxCustomFontNameComboBoxViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


class DELPHICLASS TcxCustomFontNameComboBoxViewData;
class DELPHICLASS TcxCustomFontNameComboBoxProperties;
class PASCALIMPLEMENTATION TcxCustomFontNameComboBoxViewData : public Cxdropdownedit::TcxCustomDropDownEditViewData
{
	typedef Cxdropdownedit::TcxCustomDropDownEditViewData inherited;
	
private:
	HIDESBASE TcxCustomFontNameComboBoxProperties* __fastcall GetProperties(void);
	
protected:
	virtual bool __fastcall IsComboBoxStyle(void);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall DisplayValueToDrawValue(const System::Variant &ADisplayValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall GetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	__property TcxCustomFontNameComboBoxProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomFontNameComboBoxViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxdropdownedit::TcxCustomDropDownEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomFontNameComboBoxViewData(void) { }
	
};


class DELPHICLASS TcxFontNameComboBoxListBox;
class DELPHICLASS TcxCustomFontNameComboBox;
class PASCALIMPLEMENTATION TcxFontNameComboBoxListBox : public Cxdropdownedit::TcxCustomComboBoxListBox
{
	typedef Cxdropdownedit::TcxCustomComboBoxListBox inherited;
	
private:
	HIDESBASE TcxCustomFontNameComboBox* __fastcall GetEdit(void);
	bool __fastcall IsSymbolFontType(int AItemIndex);
	
protected:
	virtual System::UnicodeString __fastcall GetItem(int Index);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DrawItem(int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	__property TcxCustomFontNameComboBox* Edit = {read=GetEdit};
	
public:
	virtual int __fastcall GetItemHeight(int AIndex = 0xffffffff);
	virtual int __fastcall GetItemWidth(int AIndex);
public:
	/* TcxCustomComboBoxListBox.Create */ inline __fastcall virtual TcxFontNameComboBoxListBox(System::Classes::TComponent* AOwner) : Cxdropdownedit::TcxCustomComboBoxListBox(AOwner) { }
	
public:
	/* TcxCustomInnerListBox.Destroy */ inline __fastcall virtual ~TcxFontNameComboBoxListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxFontNameComboBoxListBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBoxListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFontNameComboBoxLookupData;
class PASCALIMPLEMENTATION TcxFontNameComboBoxLookupData : public Cxdropdownedit::TcxComboBoxLookupData
{
	typedef Cxdropdownedit::TcxComboBoxLookupData inherited;
	
private:
	TFontPreviewPanel* FPanel;
	System::UnicodeString __fastcall GetFontName(void);
	System::UnicodeString __fastcall GetPreviewText(void);
	
protected:
	virtual Cxtextedit::TcxCustomEditListBoxClass __fastcall GetListBoxClass(void);
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	virtual void __fastcall InternalChangeCurrentMRUFontNamePosition(void);
	
public:
	__fastcall virtual ~TcxFontNameComboBoxLookupData(void);
	virtual bool __fastcall CanResizeVisualArea(System::Types::TSize &NewSize, int AMaxHeight = 0x0, int AMaxWidth = 0x0);
	virtual System::Types::TSize __fastcall GetVisualAreaPreferredSize(int AMaxHeight, int AWidth = 0x0);
	virtual void __fastcall Initialize(Vcl::Controls::TWinControl* AVisualControlsParent);
	virtual void __fastcall PositionVisualArea(const System::Types::TRect &AClientRect);
public:
	/* TcxCustomTextEditLookupData.Create */ inline __fastcall virtual TcxFontNameComboBoxLookupData(System::Classes::TPersistent* AOwner) : Cxdropdownedit::TcxComboBoxLookupData(AOwner) { }
	
};


class PASCALIMPLEMENTATION TcxCustomFontNameComboBoxProperties : public Cxdropdownedit::TcxCustomComboBoxProperties
{
	typedef Cxdropdownedit::TcxCustomComboBoxProperties inherited;
	
private:
	TcxFontLoader* FFontLoader;
	TcxFontPreview* FFontPreview;
	TcxFontTypes FFontTypes;
	bool FLoadFontComplete;
	System::Byte FMaxMRUFonts;
	TcxMRUFontNameItems* FMRUFontNames;
	TcxShowFontIconTypes FShowFontTypeIcon;
	bool FUseOwnFont;
	System::Classes::TNotifyEvent FOnAddedMRUFont;
	TcxDeleteMRUFontEvent FOnDeletedMRUFont;
	System::Classes::TNotifyEvent FOnInternalLoadFontComplete;
	System::Classes::TNotifyEvent FOnLoadFontComplete;
	System::Classes::TNotifyEvent FOnMovedMRUFont;
	System::Classes::TStrings* __fastcall GetFontItems(void);
	TcxFontTypes __fastcall GetFontTypes(void);
	bool __fastcall GetUseOwnFont(void);
	void __fastcall SetMaxMRUFonts(System::Byte Value);
	void __fastcall SetFontTypes(TcxFontTypes Value);
	void __fastcall SetUseOwnFont(bool Value);
	void __fastcall SetShowFontTypeIcon(TcxShowFontIconTypes Value);
	int __fastcall FindItemByValue(const System::Variant &AEditValue);
	void __fastcall DeleteOverMRUFonts(void);
	void __fastcall FontLoaderCompleteHandler(System::TObject* Sender);
	void __fastcall FontLoaderDestroyHandler(System::TObject* Sender);
	TcxFontTypes __fastcall GetItemTypes(int Index);
	void __fastcall SetFontPreview(TcxFontPreview* Value);
	void __fastcall ShutDownFontLoader(void);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual bool __fastcall FindLookupText(const System::UnicodeString AText);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual TcxMRUFontNameAction __fastcall AddMRUFontName(const System::Uitypes::TFontName AFontName);
	virtual TcxMRUFontNameAction __fastcall DelMRUFontName(const System::Uitypes::TFontName AFontName);
	__property TcxFontTypes ItemTypes[int Index] = {read=GetItemTypes};
	
public:
	__fastcall virtual TcxCustomFontNameComboBoxProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomFontNameComboBoxProperties(void);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	void __fastcall GetFontNameComboBoxDisplayValue(const System::Variant &AEditValue, /* out */ int &AItemIndex, /* out */ System::UnicodeString &AText);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	__property bool LoadFontComplete = {read=FLoadFontComplete, nodefault};
	virtual void __fastcall LoadFontNames(void);
	virtual void __fastcall Update(Cxedit::TcxCustomEditProperties* AProperties);
	__property System::Classes::TStrings* FontItems = {read=GetFontItems};
	__property TcxMRUFontNameItems* MRUFontNames = {read=FMRUFontNames};
	__property TcxFontPreview* FontPreview = {read=FFontPreview, write=SetFontPreview};
	__property TcxFontTypes FontTypes = {read=GetFontTypes, write=SetFontTypes, default=31};
	__property System::Byte MaxMRUFonts = {read=FMaxMRUFonts, write=SetMaxMRUFonts, default=10};
	__property TcxShowFontIconTypes ShowFontTypeIcon = {read=FShowFontTypeIcon, write=SetShowFontTypeIcon, default=3};
	__property bool UseOwnFont = {read=GetUseOwnFont, write=SetUseOwnFont, default=0};
	__property System::Classes::TNotifyEvent OnAddedMRUFont = {read=FOnAddedMRUFont, write=FOnAddedMRUFont};
	__property TcxDeleteMRUFontEvent OnDeletedMRUFont = {read=FOnDeletedMRUFont, write=FOnDeletedMRUFont};
	__property System::Classes::TNotifyEvent OnLoadFontComplete = {read=FOnLoadFontComplete, write=FOnLoadFontComplete};
	__property System::Classes::TNotifyEvent OnMovedMRUFont = {read=FOnMovedMRUFont, write=FOnMovedMRUFont};
};


class DELPHICLASS TcxFontNameComboBoxProperties;
class PASCALIMPLEMENTATION TcxFontNameComboBoxProperties : public TcxCustomFontNameComboBoxProperties
{
	typedef TcxCustomFontNameComboBoxProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property BeepOnError = {default=0};
	__property ButtonGlyph;
	__property CharCase = {default=0};
	__property ClearKey = {default=0};
	__property DropDownAutoWidth = {default=1};
	__property DropDownRows = {default=8};
	__property DropDownSizeable = {default=0};
	__property DropDownWidth = {default=0};
	__property FontPreview;
	__property FontTypes = {default=31};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=1};
	__property ImmediatePost = {default=0};
	__property ImmediateUpdateText = {default=0};
	__property ItemHeight = {default=0};
	__property MaxMRUFonts = {default=10};
	__property OEMConvert = {default=0};
	__property PopupAlignment = {default=0};
	__property PostPopupValueOnTab = {default=0};
	__property ReadOnly;
	__property ShowFontTypeIcon = {default=3};
	__property UseOwnFont = {default=0};
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property OnAddedMRUFont;
	__property OnChange;
	__property OnCloseUp;
	__property OnDeletedMRUFont;
	__property OnDrawItem;
	__property OnEditValueChanged;
	__property OnInitPopup;
	__property OnLoadFontComplete;
	__property OnMeasureItem;
	__property OnMovedMRUFont;
	__property OnNewLookupDisplayText;
	__property OnPopup;
	__property OnValidate;
public:
	/* TcxCustomFontNameComboBoxProperties.Create */ inline __fastcall virtual TcxFontNameComboBoxProperties(System::Classes::TPersistent* AOwner) : TcxCustomFontNameComboBoxProperties(AOwner) { }
	/* TcxCustomFontNameComboBoxProperties.Destroy */ inline __fastcall virtual ~TcxFontNameComboBoxProperties(void) { }
	
};


class DELPHICLASS TcxCustomFontNameComboBoxInnerEdit;
class PASCALIMPLEMENTATION TcxCustomFontNameComboBoxInnerEdit : public Cxdropdownedit::TcxCustomComboBoxInnerEdit
{
	typedef Cxdropdownedit::TcxCustomComboBoxInnerEdit inherited;
	
public:
	/* TcxCustomInnerTextEdit.Create */ inline __fastcall virtual TcxCustomFontNameComboBoxInnerEdit(System::Classes::TComponent* AOwner) : Cxdropdownedit::TcxCustomComboBoxInnerEdit(AOwner) { }
	/* TcxCustomInnerTextEdit.Destroy */ inline __fastcall virtual ~TcxCustomFontNameComboBoxInnerEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomFontNameComboBoxInnerEdit(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBoxInnerEdit(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomFontNameComboBox : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	bool FDontCheckModifiedWhenUpdatingMRUList;
	System::UnicodeString FFontNameQueue;
	bool FNeedsUpdateMRUList;
	System::UnicodeString __fastcall GetFontName(void);
	void __fastcall SetFontName(System::UnicodeString Value);
	HIDESBASE TcxFontNameComboBoxLookupData* __fastcall GetLookupData(void);
	HIDESBASE TcxCustomFontNameComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomFontNameComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomFontNameComboBoxProperties* Value);
	void __fastcall InternalLoadFontCompleteHandler(System::TObject* Sender);
	void __fastcall UpdateMRUList(void);
	
protected:
	virtual void __fastcall AfterPosting(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass(void);
	virtual System::Types::TSize __fastcall GetPopupWindowClientPreferredSize(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializePopupWindow(void);
	virtual void __fastcall CloseUp(Cxedit::TcxEditCloseUpReason AReason);
	virtual void __fastcall SetItemIndex(int Value);
	__property TcxFontNameComboBoxLookupData* LookupData = {read=GetLookupData};
	
public:
	__fastcall virtual TcxCustomFontNameComboBox(System::Classes::TComponent* AOwner)/* overload */;
	virtual bool __fastcall Deactivate(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	TcxMRUFontNameAction __fastcall AddMRUFontName(const System::Uitypes::TFontName AFontName);
	TcxMRUFontNameAction __fastcall DelMRUFontName(const System::Uitypes::TFontName AFontName);
	__property TcxCustomFontNameComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property System::UnicodeString FontName = {read=GetFontName, write=SetFontName};
	__property TcxCustomFontNameComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxCustomFontNameComboBox(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomFontNameComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomFontNameComboBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFontNameComboBox;
class PASCALIMPLEMENTATION TcxFontNameComboBox : public TcxCustomFontNameComboBox
{
	typedef TcxCustomFontNameComboBox inherited;
	
private:
	HIDESBASE TcxFontNameComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxFontNameComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxFontNameComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxFontNameComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxFontNameComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomFontNameComboBox.Create */ inline __fastcall virtual TcxFontNameComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomFontNameComboBox(AOwner) { }
	
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxFontNameComboBox(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxFontNameComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomFontNameComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxFontNameComboBox(HWND ParentWindow) : TcxCustomFontNameComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterFontNameComboBoxHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterFontNameComboBoxHelper : public Cxdropdownedit::TcxFilterComboBoxHelper
{
	typedef Cxdropdownedit::TcxFilterComboBoxHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
public:
	/* TObject.Create */ inline __fastcall TcxFilterFontNameComboBoxHelper(void) : Cxdropdownedit::TcxFilterComboBoxHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterFontNameComboBoxHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Word FIXEDPITCH_FONTTYPE = System::Word(0x200);
extern PACKAGE Vcl::Graphics::TBitmap* FTrueTypeFontBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* FNonTrueTypeFontBitmap;
extern PACKAGE TcxFontTypes __fastcall RealFontTypeToCxTypes(const int AFontType);
extern PACKAGE TcxFontTypes __fastcall GetFontTypes(const System::UnicodeString AFontName);
extern PACKAGE void __fastcall GetFontSizes(const System::UnicodeString AFontName, System::Classes::TStrings* AFontSizes);
}	/* namespace Cxfontnamecombobox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFONTNAMECOMBOBOX)
using namespace Cxfontnamecombobox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxfontnamecomboboxHPP
