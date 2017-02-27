// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutSelection.pas' rev: 24.00 (Win64)

#ifndef DxlayoutselectionHPP
#define DxlayoutselectionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutselection
{
//-- type declarations -------------------------------------------------------
enum TdxSelectionAction : unsigned char { saAdded, saChanged, saExtracted };

__interface IdxSelectionChanged;
typedef System::DelphiInterface<IdxSelectionChanged> _di_IdxSelectionChanged;
__interface  INTERFACE_UUID("{ECB1A3AE-1C91-4E5F-8ADC-34120676B1CA}") IdxSelectionChanged  : public System::IInterface 
{
	
public:
	virtual void __fastcall SelectionChanged(System::Classes::TList* ASelection, TdxSelectionAction AAction) = 0 ;
};

__interface IdxLayoutSelectableItem;
typedef System::DelphiInterface<IdxLayoutSelectableItem> _di_IdxLayoutSelectableItem;
__interface  INTERFACE_UUID("{2887168D-78EB-44A0-A440-E284B01BE407}") IdxLayoutSelectableItem  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanDelete(void) = 0 ;
	virtual bool __fastcall IsOwner(System::Classes::TComponent* AOwner) = 0 ;
	virtual void __fastcall MakeVisible(void) = 0 ;
	virtual void __fastcall SelectComponent(System::Classes::TShiftState AShift = System::Classes::TShiftState() ) = 0 ;
	virtual void __fastcall SelectParent(void) = 0 ;
	virtual void __fastcall SelectionChanged(void) = 0 ;
	virtual bool __fastcall IsVisible(void) = 0 ;
};

__interface IdxLayoutDesignerHelper;
typedef System::DelphiInterface<IdxLayoutDesignerHelper> _di_IdxLayoutDesignerHelper;
__interface  INTERFACE_UUID("{0FF95B61-5074-49E4-99C6-1A8BB34F1547}") IdxLayoutDesignerHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall AddSelectionChangedListener(System::Classes::TPersistent* AListener) = 0 ;
	virtual bool __fastcall IsActive(void) = 0 ;
	virtual bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent) = 0 ;
	virtual bool __fastcall CanModify(void) = 0 ;
	virtual bool __fastcall CanProcessKeyboard(void) = 0 ;
	virtual void __fastcall ClearSelection(void) = 0 ;
	virtual void __fastcall DeleteSelection(void) = 0 ;
	virtual void __fastcall GetSelection(System::Classes::TList* AList) = 0 ;
	virtual bool __fastcall IsComponentSelected(System::Classes::TPersistent* AComponent) = 0 ;
	virtual void __fastcall RemoveSelectionChangedListener(System::Classes::TPersistent* AListener) = 0 ;
	virtual void __fastcall SelectComponent(System::Classes::TPersistent* AComponent, System::Classes::TShiftState AShift = System::Classes::TShiftState() ) = 0 ;
	virtual void __fastcall SetSelection(System::Classes::TList* AList) = 0 ;
	virtual System::UnicodeString __fastcall UniqueName(const System::UnicodeString BaseName) = 0 ;
};

class DELPHICLASS TdxLayoutRunTimeSelectionHelper;
class PASCALIMPLEMENTATION TdxLayoutRunTimeSelectionHelper : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Classes::TList* FListeners;
	int FRefCount;
	Cxclasses::TcxComponentList* FSelectionList;
	System::Classes::TComponent* __fastcall GetComponent(void);
	void __fastcall SelectionListNotifyHandler(System::TObject* Sender, System::Classes::TComponent* AComponent, System::Classes::TListNotification AAction);
	void __fastcall SelectionListChangedHandler(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	
protected:
	System::Classes::TComponentClass __fastcall GetComponentClass(System::Classes::TComponent* AComponent);
	void __fastcall NotifyListeners(System::Classes::TList* AList, TdxSelectionAction AAction);
	void __fastcall SelectionListNotify(System::Classes::TComponent* AComponent, System::Classes::TListNotification AAction);
	virtual void __fastcall DoDeleteComponents(Cxclasses::TcxComponentList* AList);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	__property System::Classes::TComponent* Component = {read=GetComponent};
	__property System::Classes::TList* Listeners = {read=FListeners};
	__property Cxclasses::TcxComponentList* SelectionList = {read=FSelectionList};
	
public:
	__fastcall virtual TdxLayoutRunTimeSelectionHelper(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxLayoutRunTimeSelectionHelper(void);
	virtual void __fastcall AddSelectionChangedListener(System::Classes::TPersistent* AListener);
	virtual void __fastcall RemoveSelectionChangedListener(System::Classes::TPersistent* AListener);
	virtual bool __fastcall IsActive(void);
	virtual bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent);
	virtual bool __fastcall CanModify(void);
	virtual bool __fastcall CanProcessKeyboard(void);
	virtual void __fastcall ClearSelection(void);
	virtual void __fastcall DeleteSelection(void);
	virtual void __fastcall GetSelection(System::Classes::TList* AList);
	virtual bool __fastcall IsComponentSelected(System::Classes::TPersistent* AComponent);
	virtual void __fastcall SelectComponent(System::Classes::TPersistent* AComponent, System::Classes::TShiftState AShift = System::Classes::TShiftState() );
	virtual void __fastcall SetSelection(System::Classes::TList* AList);
	virtual System::UnicodeString __fastcall UniqueName(const System::UnicodeString BaseName);
private:
	void *__IdxLayoutDesignerHelper;	/* IdxLayoutDesignerHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0FF95B61-5074-49E4-99C6-1A8BB34F1547}
	operator _di_IdxLayoutDesignerHelper()
	{
		_di_IdxLayoutDesignerHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxLayoutDesignerHelper*(void) { return (IdxLayoutDesignerHelper*)&__IdxLayoutDesignerHelper; }
	#endif
	
};


typedef System::TMetaClass* TdxLayoutRunTimeSelectionHelperClass;

class DELPHICLASS TdxSelectionLayerInplaceEdit;
class DELPHICLASS TdxSelectionLayer;
class PASCALIMPLEMENTATION TdxSelectionLayerInplaceEdit : public Vcl::Stdctrls::TEdit
{
	typedef Vcl::Stdctrls::TEdit inherited;
	
private:
	int FClickTime;
	bool FHiding;
	TdxSelectionLayer* FSelectionLayer;
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	
protected:
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property TdxSelectionLayer* SelectionLayer = {read=FSelectionLayer};
	
public:
	__fastcall virtual TdxSelectionLayerInplaceEdit(TdxSelectionLayer* ASelectionLayer);
	HIDESBASE void __fastcall Hide(void);
	virtual void __fastcall SetFocus(void);
	HIDESBASE void __fastcall Show(const System::Types::TRect &ABounds, const System::UnicodeString AText);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxSelectionLayerInplaceEdit(HWND ParentWindow) : Vcl::Stdctrls::TEdit(ParentWindow) { }
	/* TWinControl.Destroy */ inline __fastcall virtual ~TdxSelectionLayerInplaceEdit(void) { }
	
};


typedef void __fastcall (__closure *TdxSelectionLayerHitTestEvent)(System::TObject* ASender, bool &AIsTransparent);

typedef void __fastcall (__closure *TdxSelectionLayerEndRenameEvent)(System::TObject* ASender, const System::UnicodeString AText, bool AAccept);

class PASCALIMPLEMENTATION TdxSelectionLayer : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	bool FEditorMode;
	System::Types::TRect FInplaceEditBounds;
	TdxSelectionLayerInplaceEdit* FInplaceEdit;
	Cxcontrols::TcxControl* FParentControl;
	System::Types::TPoint FStartOffset;
	Cxgraphics::TcxAlphaBitmap* FSelectionImage;
	Cxgraphics::TcxCanvas* FcxCanvas;
	TdxSelectionLayerEndRenameEvent FOnEndRename;
	System::Classes::TNotifyEvent FOnHide;
	TdxSelectionLayerHitTestEvent FOnHitTest;
	System::Classes::TNotifyEvent FOnShow;
	System::Classes::TNotifyEvent FOnUpdate;
	void __fastcall SetParentControl(Cxcontrols::TcxControl* AValue);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall CheckInplaceEditorPosition(void);
	virtual void __fastcall DoHide(void);
	virtual bool __fastcall DoHitTest(void);
	virtual void __fastcall DoShow(void);
	virtual void __fastcall DoUpdate(void);
	virtual void __fastcall DoEndRename(const System::UnicodeString AText, bool AAccept);
	System::Types::TPoint __fastcall GetParentOffset(void);
	__property Cxgraphics::TcxCanvas* cxCanvas = {read=FcxCanvas};
	
public:
	__fastcall virtual TdxSelectionLayer(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual TdxSelectionLayer(Cxcontrols::TcxControl* AParentControl, HWND AParentWindow)/* overload */;
	__fastcall virtual ~TdxSelectionLayer(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall InvalidateRect(const System::Types::TRect &R);
	void __fastcall MoveTo(const System::Types::TPoint P);
	HIDESBASE void __fastcall Hide(void);
	HIDESBASE void __fastcall Show(void);
	void __fastcall UpdateContent(void);
	void __fastcall BeginRename(const System::Types::TRect &ABounds, const System::UnicodeString AText, Vcl::Graphics::TFont* const AFont);
	void __fastcall EndRename(bool AAccept);
	__property bool EditorMode = {read=FEditorMode, nodefault};
	__property Cxgraphics::TcxAlphaBitmap* SelectionImage = {read=FSelectionImage};
	__property Cxcontrols::TcxControl* ParentControl = {read=FParentControl, write=SetParentControl};
	__property TdxSelectionLayerEndRenameEvent OnEndRename = {read=FOnEndRename, write=FOnEndRename};
	__property System::Classes::TNotifyEvent OnHide = {read=FOnHide, write=FOnHide};
	__property TdxSelectionLayerHitTestEvent OnHitTest = {read=FOnHitTest, write=FOnHitTest};
	__property System::Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	__property System::Classes::TNotifyEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxSelectionLayer(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


__interface IdxCustomizeControlsHelper;
typedef System::DelphiInterface<IdxCustomizeControlsHelper> _di_IdxCustomizeControlsHelper;
__interface  INTERFACE_UUID("{AD2130FB-EDA5-4034-A551-9C26A8DAAE41}") IdxCustomizeControlsHelper  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanProcessChildren(void) = 0 ;
};

typedef System::TMetaClass* TdxControlsDesignSelectorHelperClass;

class DELPHICLASS TdxControlsDesignSelectorHelper;
class PASCALIMPLEMENTATION TdxControlsDesignSelectorHelper : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	bool FChecked;
	Cxclasses::TcxComponentList* FChildren;
	TdxControlsDesignSelectorHelper* FParent;
	System::Types::TRect FSelectorBounds;
	Cxcontrols::TcxWindowProcLinkedObject* FWindowProcObject;
	NativeUInt __fastcall GetControlWnd(void);
	Vcl::Controls::TWinControl* __fastcall GetParentControl(void);
	bool __fastcall PointInSelectorBounds(const System::Types::TPoint P);
	void __fastcall SetSelectorBounds(const System::Types::TRect &AValue);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall CallDefaultWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall ControlWndProc(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall DoControlWndProc(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsHitTestTransparent(const System::Types::TPoint P);
	virtual void __fastcall CheckChildren(void);
	virtual void __fastcall DestroyChild(TdxControlsDesignSelectorHelper* AChild);
	virtual TdxControlsDesignSelectorHelperClass __fastcall GetChildClass(void);
	virtual void __fastcall PrepareChild(TdxControlsDesignSelectorHelper* AItem);
	System::Types::TRect __fastcall GetSelectorBoundsForChild(TdxControlsDesignSelectorHelper* AChild);
	System::Types::TPoint __fastcall ClientToScreen(const System::Types::TPoint P);
	System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint P);
	virtual bool __fastcall IsActiveDesignSelector(void);
	virtual bool __fastcall IsSelected(void);
	virtual bool __fastcall IsValid(void);
	bool __fastcall IsWinControl(void);
	Vcl::Controls::TWinControl* __fastcall ControlAsWinControl(void);
	virtual bool __fastcall CanDrawDesignSelector(void);
	virtual void __fastcall DoDrawDesignSelector(HDC DC);
	void __fastcall DrawDesignSelector(HDC DC);
	void __fastcall StoreWndProc(void);
	void __fastcall RestoreWndProc(void);
	__property Cxclasses::TcxComponentList* Children = {read=FChildren};
	__property NativeUInt ControlWnd = {read=GetControlWnd};
	__property TdxControlsDesignSelectorHelper* Parent = {read=FParent, write=FParent};
	__property Vcl::Controls::TWinControl* ParentControl = {read=GetParentControl};
	
public:
	__fastcall virtual TdxControlsDesignSelectorHelper(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxControlsDesignSelectorHelper(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Vcl::Controls::TControl* Control = {read=FControl};
	__property System::Types::TRect SelectorBounds = {read=FSelectorBounds, write=SetSelectorBounds};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Uitypes::TColor dxLayoutDragImageBackgroundColor;
extern PACKAGE System::Uitypes::TColor dxLayoutSelectionBackgroundColor;
extern PACKAGE System::Uitypes::TColor dxLayoutSelectionBorderColor;
extern PACKAGE System::Byte dxLayoutSelectionAlphaChannel;
extern PACKAGE System::Uitypes::TColor dxLayoutSelectionBorderMarkerBackgroundColor;
}	/* namespace Dxlayoutselection */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTSELECTION)
using namespace Dxlayoutselection;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutselectionHPP
