// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dximctrl.pas' rev: 24.00 (Win64)

#ifndef DximctrlHPP
#define DximctrlHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dximctrl
{
//-- type declarations -------------------------------------------------------
enum TdxImageAlign : unsigned char { dxliLeft, dxliRight };

enum TVertAlignment : unsigned char { tvaTop, tvaCenter, tvaBottom };

typedef void __fastcall (__closure *TdxImageDrawItemEvent)(System::TObject* Sender, int Index, System::Types::TRect &Rect);

class DELPHICLASS TdxCustomImageListBox;
class PASCALIMPLEMENTATION TdxCustomImageListBox : public Vcl::Stdctrls::TCustomListBox
{
	typedef Vcl::Stdctrls::TCustomListBox inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FImageList;
	Vcl::Imglist::TChangeLink* FChangeLink;
	System::Classes::TAlignment FAlignment;
	TVertAlignment FVertAlignment;
	TdxImageAlign FImageAlign;
	bool FMultiLines;
	int FItemHeight;
	TdxImageDrawItemEvent FOnDrawItem;
	int FDrawEdgeIndex;
	bool FDrawImageOnly;
	System::UnicodeString FDeletedSt;
	int FDeletedIndex;
	Vcl::Controls::THintWindow* FHintWindow;
	bool FHintWindowShowing;
	int FHintIndex;
	int FItemTextHeight;
	int __fastcall GetImageIndex(int Index);
	System::UnicodeString __fastcall GetValue(int Index);
	void __fastcall SetImageIndex(int Index, int Value);
	void __fastcall SetImageList(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetImageAlign(TdxImageAlign Value);
	HIDESBASE void __fastcall SetItemHeight(int Value);
	void __fastcall SetMultiLines(bool Value);
	void __fastcall SetVertAlignment(TVertAlignment Value);
	void __fastcall SetValue(int Index, const System::UnicodeString Value);
	void __fastcall StringsRead(System::Classes::TReader* Reader);
	void __fastcall StringsWrite(System::Classes::TWriter* Writer);
	void __fastcall SetInheritedItemHeight(void);
	void __fastcall OnChangeLink(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNDrawItem(Winapi::Messages::TWMDrawItem &Message);
	System::Types::TRect __fastcall GetImageRect(int ItemIndex);
	void __fastcall DrawImageFocus(int Index);
	
protected:
	System::Classes::TStrings* FStrings;
	virtual void __fastcall DrawItem(int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	int __fastcall ValuesIndexOf(System::UnicodeString Text);
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property TdxImageAlign ImageAlign = {read=FImageAlign, write=SetImageAlign, nodefault};
	__property int ItemHeight = {read=FItemHeight, write=SetItemHeight, nodefault};
	__property Vcl::Imglist::TCustomImageList* ImageList = {read=FImageList, write=SetImageList};
	__property bool MultiLines = {read=FMultiLines, write=SetMultiLines, nodefault};
	__property TVertAlignment VertAlignment = {read=FVertAlignment, write=SetVertAlignment, nodefault};
	__property TdxImageDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	
public:
	__fastcall virtual TdxCustomImageListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomImageListBox(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HIDESBASE void __fastcall AddItem(System::UnicodeString St, int ImageIndex);
	void __fastcall InsertItem(int Index, System::UnicodeString St, int ImageIndex);
	void __fastcall ExchangeItems(int Index1, int Index2);
	void __fastcall MoveItem(int CurIndex, int NewIndex);
	__property int ImageIndexes[int Index] = {read=GetImageIndex, write=SetImageIndex};
	__property System::UnicodeString Values[int Index] = {read=GetValue, write=SetValue};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomImageListBox(HWND ParentWindow) : Vcl::Stdctrls::TCustomListBox(ParentWindow) { }
	
};


class DELPHICLASS TdxImageListBox;
class PASCALIMPLEMENTATION TdxImageListBox : public TdxCustomImageListBox
{
	typedef TdxCustomImageListBox inherited;
	
__published:
	__property Alignment;
	__property ImageAlign;
	__property ItemHeight;
	__property ImageList;
	__property MultiLines;
	__property VertAlignment;
	__property OnDrawItem;
	__property ExtendedSelect = {default=1};
	__property MultiSelect = {default=0};
	__property Align = {default=0};
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property Columns = {default=0};
	__property Ctl3D;
	__property DragCursor = {default=-12};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property IntegralHeight = {default=0};
	__property Items;
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property Sorted = {default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property TabWidth = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property Anchors = {default=3};
	__property Constraints;
	__property OnStartDock;
	__property OnEndDock;
public:
	/* TdxCustomImageListBox.Create */ inline __fastcall virtual TdxImageListBox(System::Classes::TComponent* AOwner) : TdxCustomImageListBox(AOwner) { }
	/* TdxCustomImageListBox.Destroy */ inline __fastcall virtual ~TdxImageListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxImageListBox(HWND ParentWindow) : TdxCustomImageListBox(ParentWindow) { }
	
};


class DELPHICLASS TdxCustomImageComboBox;
class PASCALIMPLEMENTATION TdxCustomImageComboBox : public Vcl::Stdctrls::TCustomComboBox
{
	typedef Vcl::Stdctrls::TCustomComboBox inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FImageList;
	Vcl::Imglist::TChangeLink* FChangeLink;
	System::Classes::TAlignment FAlignment;
	TVertAlignment FVertAlignment;
	TdxImageAlign FImageAlign;
	bool FMultiLines;
	int FItemHeight;
	TdxImageDrawItemEvent FOnDrawItem;
	System::UnicodeString FDeletedSt;
	int FDeletedIndex;
	int __fastcall GetImageIndex(int Index);
	System::UnicodeString __fastcall GetValue(int INdex);
	void __fastcall SetImageIndex(int Index, int Value);
	void __fastcall SetImageList(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetImageAlign(TdxImageAlign Value);
	void __fastcall SetInternalItemHeight(int Value);
	void __fastcall SetMultiLines(bool Value);
	void __fastcall SetVertAlignment(TVertAlignment Value);
	void __fastcall SetValue(int Index, const System::UnicodeString Value);
	void __fastcall StringsRead(System::Classes::TReader* Reader);
	void __fastcall StringsWrite(System::Classes::TWriter* Writer);
	void __fastcall SetInheritedItemHeight(void);
	void __fastcall OnChangeLink(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	
protected:
	System::Classes::TStrings* FStrings;
	virtual void __fastcall DrawItem(int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	int __fastcall ValuesIndexOf(System::UnicodeString Text);
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property TdxImageAlign ImageAlign = {read=FImageAlign, write=SetImageAlign, nodefault};
	__property int ItemHeight = {read=FItemHeight, write=SetInternalItemHeight, nodefault};
	__property Vcl::Imglist::TCustomImageList* ImageList = {read=FImageList, write=SetImageList};
	__property bool MultiLines = {read=FMultiLines, write=SetMultiLines, nodefault};
	__property TVertAlignment VertAlignment = {read=FVertAlignment, write=SetVertAlignment, nodefault};
	__property TdxImageDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	
public:
	__fastcall virtual TdxCustomImageComboBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomImageComboBox(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HIDESBASE void __fastcall AddItem(System::UnicodeString St, int ImageIndex);
	void __fastcall InsertItem(int Index, System::UnicodeString St, int ImageIndex);
	void __fastcall ExchangeItems(int Index1, int Index2);
	void __fastcall MoveItem(int CurIndex, int NewIndex);
	__property System::UnicodeString Values[int Index] = {read=GetValue, write=SetValue};
	__property int ImageIndexes[int Index] = {read=GetImageIndex, write=SetImageIndex};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomImageComboBox(HWND ParentWindow) : Vcl::Stdctrls::TCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TdxImageComboBox;
class PASCALIMPLEMENTATION TdxImageComboBox : public TdxCustomImageComboBox
{
	typedef TdxCustomImageComboBox inherited;
	
__published:
	__property Alignment;
	__property ImageAlign;
	__property ItemHeight;
	__property ImageList;
	__property MultiLines;
	__property VertAlignment;
	__property OnDrawItem;
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property DragMode = {default=0};
	__property DragCursor = {default=-12};
	__property DropDownCount = {default=8};
	__property Enabled = {default=1};
	__property Font;
	__property Items;
	__property MaxLength = {default=0};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property Sorted = {default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnChange;
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDropDown;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnStartDrag;
	__property Anchors = {default=3};
	__property Constraints;
	__property OnStartDock;
	__property OnEndDock;
public:
	/* TdxCustomImageComboBox.Create */ inline __fastcall virtual TdxImageComboBox(System::Classes::TComponent* AOwner) : TdxCustomImageComboBox(AOwner) { }
	/* TdxCustomImageComboBox.Destroy */ inline __fastcall virtual ~TdxImageComboBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxImageComboBox(HWND ParentWindow) : TdxCustomImageComboBox(ParentWindow) { }
	
};


enum TdxUpDownAlign : unsigned char { udaBottom, udaLeft, udaRight, udaTop };

enum TdxHSpinImageAlign : unsigned char { hsiLeft, hsiCenter, hsiRight };

enum TdxVSpinImageAlign : unsigned char { vsiTop, vsiCenter, vsiBottom };

class DELPHICLASS TdxSpinImageItem;
class DELPHICLASS TdxSpinImageItems;
class PASCALIMPLEMENTATION TdxSpinImageItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TdxSpinImageItems* Owner;
	int FImageIndex;
	System::UnicodeString FValue;
	System::UnicodeString FHint;
	void __fastcall SetImageIndex(int Value);
	void __fastcall SetValue(System::UnicodeString Value);
	void __fastcall SetHint(System::UnicodeString Value);
	
public:
	__fastcall virtual TdxSpinImageItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property System::UnicodeString Hint = {read=FHint, write=SetHint};
	__property System::UnicodeString Value = {read=FValue, write=SetValue};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxSpinImageItem(void) { }
	
};


class DELPHICLASS TdxCustomSpinImage;
class PASCALIMPLEMENTATION TdxSpinImageItems : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxSpinImageItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxCustomSpinImage* Owner;
	HIDESBASE TdxSpinImageItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxSpinImageItem* Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TdxSpinImageItems(TdxCustomSpinImage* AOwner);
	HIDESBASE TdxSpinImageItem* __fastcall Add(void);
	int __fastcall IndexOf(System::UnicodeString Value);
	__property TdxSpinImageItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxSpinImageItems(void) { }
	
};


typedef void __fastcall (__closure *TdxSIChange)(System::TObject* Sender, int ItemIndex);

enum TdxsiOrientation : unsigned char { siHorizontal, siVertical };

class PASCALIMPLEMENTATION TdxCustomSpinImage : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	Vcl::Extctrls::TTimer* FTimer;
	int FScrollTimerCount;
	bool FAutoSize;
	bool FDefaultImages;
	Vcl::Forms::TFormBorderStyle FBorderStyle;
	Vcl::Imglist::TChangeLink* FChangeLink;
	int FItemIndex;
	Vcl::Imglist::TCustomImageList* FImageList;
	TdxHSpinImageAlign FImageHAlign;
	TdxVSpinImageAlign FImageVAlign;
	TdxSpinImageItems* FItems;
	TdxSIChange FOnChange;
	bool FReadOnly;
	bool FUseDblClick;
	bool FStretch;
	TdxUpDownAlign FUpDownAlign;
	TdxsiOrientation FUpDownOrientation;
	int FUpDownWidth;
	int FNCSide;
	bool FUpPress;
	bool FDownPress;
	System::Types::TRect FUpButtonRect;
	System::Types::TRect FDownButtonRect;
	bool FUpButtonEnabled;
	bool FDownButtonEnabled;
	void __fastcall SetInternalAutoSize(bool Value);
	void __fastcall SetBorderStyle(Vcl::Forms::TBorderStyle Value);
	void __fastcall SetDefaultImages(bool Value);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetImageList(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetImageHAlign(TdxHSpinImageAlign Value);
	void __fastcall SetImageVAlign(TdxVSpinImageAlign Value);
	void __fastcall SetItems(TdxSpinImageItems* Value);
	void __fastcall SetStretch(bool Value);
	void __fastcall SetUpDownAlign(TdxUpDownAlign Value);
	void __fastcall SetUpDownOrientation(TdxsiOrientation Value);
	void __fastcall SetUpDownWidth(int Value);
	HIDESBASE MESSAGE void __fastcall CMEnter(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	MESSAGE void __fastcall WMNCLButtonDblClk(Winapi::Messages::TWMNCHitMessage &Message);
	MESSAGE void __fastcall WMNCMouseDown(Winapi::Messages::TWMNCHitMessage &Message);
	MESSAGE void __fastcall WMNCMouseUp(Winapi::Messages::TWMNCHitMessage &Message);
	MESSAGE void __fastcall WMMouseUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	void __fastcall UpDownClick(System::Word AKey);
	void __fastcall OnChangeLink(System::TObject* Sender);
	void __fastcall MakeAutoSize(void);
	void __fastcall SetNextItem(void);
	bool __fastcall IsLastItem(void);
	void __fastcall UpdateNCRegion(void);
	void __fastcall NCMouseDown(int X, int Y);
	void __fastcall DoTimerScroll(System::TObject* Sender);
	
protected:
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Change(void);
	virtual bool __fastcall CanChange(void);
	virtual void __fastcall UpdateItems(void);
	__property bool AutoSize = {read=FAutoSize, write=SetInternalAutoSize, nodefault};
	__property Vcl::Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, nodefault};
	__property bool DefaultImages = {read=FDefaultImages, write=SetDefaultImages, nodefault};
	__property TdxHSpinImageAlign ImageHAlign = {read=FImageHAlign, write=SetImageHAlign, nodefault};
	__property TdxVSpinImageAlign ImageVAlign = {read=FImageVAlign, write=SetImageVAlign, nodefault};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, nodefault};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, nodefault};
	__property bool Stretch = {read=FStretch, write=SetStretch, nodefault};
	__property TdxUpDownAlign UpDownAlign = {read=FUpDownAlign, write=SetUpDownAlign, nodefault};
	__property TdxsiOrientation UpDownOrientation = {read=FUpDownOrientation, write=SetUpDownOrientation, nodefault};
	__property int UpDownWidth = {read=FUpDownWidth, write=SetUpDownWidth, nodefault};
	__property bool UseDblClick = {read=FUseDblClick, write=FUseDblClick, nodefault};
	__property TdxSIChange OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TdxCustomSpinImage(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomSpinImage(void);
	__property Vcl::Imglist::TCustomImageList* ImageList = {read=FImageList, write=SetImageList};
	__property TdxSpinImageItems* Items = {read=FItems, write=SetItems};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomSpinImage(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TdxSpinImage;
class PASCALIMPLEMENTATION TdxSpinImage : public TdxCustomSpinImage
{
	typedef TdxCustomSpinImage inherited;
	
__published:
	__property Anchors = {default=3};
	__property AutoSize;
	__property BorderStyle;
	__property Constraints;
	__property DefaultImages;
	__property ImageList;
	__property ImageHAlign;
	__property ImageVAlign;
	__property Items;
	__property ItemIndex;
	__property ReadOnly;
	__property Stretch;
	__property UpDownAlign;
	__property UpDownOrientation;
	__property UpDownWidth;
	__property UseDblClick;
	__property OnChange;
	__property Align = {default=0};
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property DragCursor = {default=-12};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property OnStartDock;
	__property OnEndDock;
public:
	/* TdxCustomSpinImage.Create */ inline __fastcall virtual TdxSpinImage(System::Classes::TComponent* AOwner) : TdxCustomSpinImage(AOwner) { }
	/* TdxCustomSpinImage.Destroy */ inline __fastcall virtual ~TdxSpinImage(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxSpinImage(HWND ParentWindow) : TdxCustomSpinImage(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dximctrl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXIMCTRL)
using namespace Dximctrl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DximctrlHPP
