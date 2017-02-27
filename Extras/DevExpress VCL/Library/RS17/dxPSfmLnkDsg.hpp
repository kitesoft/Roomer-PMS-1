// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmLnkDsg.pas' rev: 24.00 (Win32)

#ifndef DxpsfmlnkdsgHPP
#define DxpsfmlnkdsgHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSfmLnkAdd.hpp>	// Pascal unit
#include <dxPSDsgProxies.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmlnkdsg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxfmReportLinkDesignWindow : public Designwindows::TDesignWindow
{
	typedef Designwindows::TDesignWindow inherited;
	
__published:
	Vcl::Menus::TPopupMenu* pmLinks;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Menus::TMenuItem* miShowDesigner;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miSelectAll;
	Vcl::Menus::TMenuItem* miChangeComponent;
	Vcl::Menus::TMenuItem* miPrintPreview;
	Vcl::Menus::TMenuItem* miPrint;
	Vcl::Menus::TMenuItem* miPageSetup;
	Vcl::Menus::TMenuItem* miLine3;
	Vcl::Menus::TMenuItem* miCopy;
	Vcl::Menus::TMenuItem* miCut;
	Vcl::Menus::TMenuItem* miPaste;
	Vcl::Menus::TMenuItem* miRestoreDefaults;
	Vcl::Menus::TMenuItem* miLine;
	Vcl::Menus::TMenuItem* miShowButtons;
	Vcl::Menus::TMenuItem* miLine5;
	Vcl::Menus::TMenuItem* miMoveUp;
	Vcl::Menus::TMenuItem* miMoveDown;
	Vcl::Menus::TMenuItem* miBackgroundEffects;
	Vcl::Menus::TMenuItem* miAddStandard;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* miBackgroundClear;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* miRestoreOriginal;
	Vcl::Menus::TMenuItem* miSetAsCurrent;
	Vcl::Menus::TMenuItem* miEdit;
	Vcl::Menus::TMenuItem* N3;
	Vcl::Menus::TMenuItem* miBackground;
	Vcl::Menus::TMenuItem* miAddExisting;
	Vcl::Menus::TPopupMenu* pmAdd;
	Vcl::Menus::TMenuItem* miAdd1;
	Vcl::Menus::TMenuItem* miAddStandard1;
	Vcl::Menus::TMenuItem* miAddExisting1;
	Vcl::Menus::TMenuItem* miLine6;
	Vcl::Menus::TMenuItem* miAddComposition1;
	Vcl::Menus::TMenuItem* miAddComposition;
	Vcl::Menus::TMenuItem* miLine7;
	Cxlistbox::TcxListBox* lbxLinks;
	Cxgroupbox::TcxGroupBox* pnlButtons;
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnDelete;
	Cxbuttons::TcxButton* btnShowDesigner;
	Cxbuttons::TcxButton* btnSelectAll;
	Cxbuttons::TcxButton* btnRestoreOriginal;
	Cxbuttons::TcxButton* btnChangeComponent;
	Cxbuttons::TcxButton* btnPrintPreview;
	Cxbuttons::TcxButton* btnPrint;
	Cxbuttons::TcxButton* btnPageSetup;
	Cxbuttons::TcxButton* btnMoveUp;
	Cxbuttons::TcxButton* btnMoveDown;
	Cxbuttons::TcxButton* btnRestoreDefaults;
	Cxgraphics::TcxImageList* ilLinks;
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall AddClick(System::TObject* Sender);
	void __fastcall AddStandardClick(System::TObject* Sender);
	void __fastcall AddExistingClick(System::TObject* Sender);
	void __fastcall lbxLinksClick(System::TObject* Sender);
	void __fastcall LinkDesignClick(System::TObject* Sender);
	void __fastcall SetAsCurrentClick(System::TObject* Sender);
	void __fastcall LinkChangeComponentClick(System::TObject* Sender);
	void __fastcall RestoreDefaultsClick(System::TObject* Sender);
	void __fastcall RestoreOriginalClick(System::TObject* Sender);
	void __fastcall PageSetupClick(System::TObject* Sender);
	void __fastcall PrintPreviewClick(System::TObject* Sender);
	void __fastcall PrintClick(System::TObject* Sender);
	void __fastcall lbxLinksDblClick(System::TObject* Sender);
	void __fastcall lbxLinksStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall lbxLinksEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall lbxLinksDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbxLinksDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall lbxLinksKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall EditClick(System::TObject* Sender);
	void __fastcall MoveUpClick(System::TObject* Sender);
	void __fastcall MoveDownClick(System::TObject* Sender);
	void __fastcall BackgroundClick(System::TObject* Sender);
	void __fastcall ClearBackgroundClick(System::TObject* Sender);
	void __fastcall pmLinksPopup(System::TObject* Sender);
	void __fastcall ShowButtonsClick(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall AddCompositionClick(System::TObject* Sender);
	void __fastcall lbxLinksDrawItem(Cxlistbox::TcxListBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall lbxLinksMeasureItem(Cxlistbox::TcxListBox* AControl, int AIndex, int &Height);
	
private:
	Dxpscore::TCustomdxComponentPrinter* FController;
	System::Uitypes::TCursor FSaveCursor;
	int FSaveDragIndex;
	Dxpscore::TAbstractdxReportLinkDesigner* __fastcall GetControllerDesigner(void);
	Dxpscore::TBasedxReportLink* __fastcall GetCurrentLink(void);
	Dxpscore::TBasedxReportLink* __fastcall GetLink(int Index);
	int __fastcall GetLinkCount(void);
	System::UnicodeString __fastcall GetLinkDescription(int Index);
	System::UnicodeString __fastcall GetRegistryPath(void);
	bool __fastcall GetSelected(int Index);
	int __fastcall GetSelectedCount(void);
	void __fastcall SetController(Dxpscore::TCustomdxComponentPrinter* Value);
	void __fastcall SetSelected(int Index, bool Value);
	int __fastcall CalculateLinkCaptionWidth(void);
	int __fastcall CalculateLinkDescriptionOffset(void);
	int __fastcall CalculateLinkDescriptionWidth(void);
	int __fastcall CalculateLinkMaxRowWidth(void);
	bool __fastcall CanAdd(void);
	bool __fastcall CanAddExisting(void);
	bool __fastcall CanBackgroundClear(void);
	bool __fastcall CanBackgroundEffects(void);
	bool __fastcall CanChangeComponent(void);
	bool __fastcall CanCopy(void);
	bool __fastcall CanCut(void);
	bool __fastcall CanDelete(void);
	bool __fastcall CanMoveDown(void);
	bool __fastcall CanMoveUp(void);
	bool __fastcall CanPaste(void);
	bool __fastcall CanPageSetup(void);
	bool __fastcall CanPrint(void);
	bool __fastcall CanPrintPreview(void);
	bool __fastcall CanRestoreDefaults(void);
	bool __fastcall CanRestoreOriginal(void);
	bool __fastcall CanSelectAll(void);
	bool __fastcall CanSetAsCurrent(void);
	bool __fastcall CanShowDesigner(void);
	void __fastcall CheckAddLink(void);
	void __fastcall CheckDeleteLink(void);
	void __fastcall Copy(void);
	void __fastcall Cut(void);
	void __fastcall Delete(void);
	void __fastcall DeleteItem(Dxpscore::TBasedxReportLink* AItem);
	void __fastcall DrawDragRect(void);
	System::Types::TPoint __fastcall GetMinWindowSize(void);
	void __fastcall GetSelections(const Designintf::_di_IDesignerSelections ASelections);
	int __fastcall IndexOf(Dxpscore::TBasedxReportLink* AItem);
	void __fastcall InternalAddLink(Dxpscore::TdxReportLinkClass ALinkClass, System::Classes::TComponent* AComponent, const System::UnicodeString AName, const System::UnicodeString ACaption, const System::UnicodeString ACreator, const System::UnicodeString ADescription, bool AShowDesigner);
	void __fastcall MakeLinkable(System::Classes::TComponent* AComponent);
	void __fastcall MoveSelection(int ADelta);
	void __fastcall Paste(void);
	void __fastcall PrepareAddExistingItem(Vcl::Menus::TMenuItem* AMenuItem);
	void __fastcall RefreshList(void);
	void __fastcall RestoreLayout(void);
	void __fastcall SaveLayout(void);
	void __fastcall Select(System::Classes::TPersistent* AItem, bool AddToSelection);
	void __fastcall SelectAll(void);
	void __fastcall SelectController(void);
	void __fastcall StartWait(void);
	void __fastcall StopWait(void);
	void __fastcall UpdateCaption(void);
	void __fastcall UpdateControlsState(void);
	void __fastcall UpdateHScrollBar(void);
	void __fastcall UpdateItem(Dxpscore::TBasedxReportLink* AItem);
	void __fastcall UpdateMenuState(void);
	void __fastcall UpdateSelections(const Designintf::_di_IDesignerSelections ASelections);
	MESSAGE void __fastcall WMAppCommand(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMGetMinMaxInfo(Winapi::Messages::TWMGetMinMaxInfo &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCreate(Winapi::Messages::TWMNCCreate &Message);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Winapi::Messages::TWMNCCreate &Message);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual System::UnicodeString __fastcall UniqueName(System::Classes::TComponent* Comp);
	__property System::UnicodeString LinkDescriptions[int Index] = {read=GetLinkDescription};
	
public:
	__fastcall virtual TdxfmReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmReportLinkDesignWindow(void);
	virtual bool __fastcall EditAction(Designintf::TEditAction Action);
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, System::Classes::TPersistent* Item);
	virtual void __fastcall ItemsModified(const Designintf::_di_IDesigner Designer);
	virtual void __fastcall SelectionChanged(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignerSelections ASelection);
	virtual Designintf::TEditState __fastcall GetEditState(void);
	__property Dxpscore::TCustomdxComponentPrinter* Controller = {read=FController, write=SetController};
	__property Dxpscore::TAbstractdxReportLinkDesigner* ControllerDesigner = {read=GetControllerDesigner};
	__property Dxpscore::TBasedxReportLink* CurrentLink = {read=GetCurrentLink};
	__property int LinkCount = {read=GetLinkCount, nodefault};
	__property Dxpscore::TBasedxReportLink* Links[int Index] = {read=GetLink};
	__property System::UnicodeString RegistryPath = {read=GetRegistryPath};
	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	__property int SelectedCount = {read=GetSelectedCount, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Designwindows::TDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmReportLinkDesignWindow(HWND ParentWindow) : Designwindows::TDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxShowReportLinkDesigner(Dxpscore::TCustomdxComponentPrinter* AComponentPrinter, Designintf::_di_IDesigner AFormDesigner);
extern PACKAGE System::UnicodeString __fastcall dxReportLinkUniqueName(Dxpscore::TCustomdxComponentPrinter* AComponentPrinter, System::Classes::TComponent* AComponent);
}	/* namespace Dxpsfmlnkdsg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMLNKDSG)
using namespace Dxpsfmlnkdsg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmlnkdsgHPP
