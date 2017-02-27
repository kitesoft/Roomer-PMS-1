// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxImageListEditorView.pas' rev: 24.00 (Win32)

#ifndef CximagelisteditorviewHPP
#define CximagelisteditorviewHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxImageListEditor.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cximagelisteditorview
{
//-- type declarations -------------------------------------------------------
enum TcxImageListEditorFormInternalState : unsigned char { eisSelectingTransparentColor };

typedef System::Set<TcxImageListEditorFormInternalState, TcxImageListEditorFormInternalState::eisSelectingTransparentColor, TcxImageListEditorFormInternalState::eisSelectingTransparentColor>  TcxImageListEditorFormInternalStates;

class DELPHICLASS TcxImageListEditorForm;
class PASCALIMPLEMENTATION TcxImageListEditorForm : public Cximagelisteditor::TcxCustomImageListEditorForm
{
	typedef Cximagelisteditor::TcxCustomImageListEditorForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Stdctrls::TButton* btnApply;
	Vcl::Stdctrls::TGroupBox* gbSelectedImage;
	Vcl::Extctrls::TPaintBox* pbPreview;
	Vcl::Stdctrls::TLabel* lbTransparentColor;
	Vcl::Stdctrls::TComboBox* cbTransparentColor;
	Vcl::Stdctrls::TGroupBox* gbImages;
	Vcl::Comctrls::TListView* lvImages;
	Vcl::Extctrls::TPanel* pnlToolBarSubstrate;
	Vcl::Comctrls::TToolBar* tbCommands;
	Vcl::Comctrls::TToolButton* tbbAdd;
	Vcl::Comctrls::TToolButton* tbbDelete;
	Vcl::Comctrls::TToolButton* tbbClear;
	Vcl::Comctrls::TToolButton* tbbExport;
	Vcl::Comctrls::TToolButton* tbbReplace;
	Vcl::Comctrls::TToolButton* tbbImport;
	Vcl::Comctrls::TToolButton* tbbConvertTo32bit;
	Vcl::Menus::TPopupMenu* pmImageLists;
	Vcl::Menus::TPopupMenu* pmCommands;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miReplace;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miClear;
	Vcl::Menus::TMenuItem* miExport;
	Vcl::Menus::TMenuItem* miImport;
	Vcl::Menus::TMenuItem* AsBitmap1;
	Vcl::Menus::TMenuItem* AsPNG1;
	Vcl::Menus::TMenuItem* AsBitmap2;
	Vcl::Menus::TMenuItem* AsPNG2;
	Vcl::Menus::TMenuItem* miConvertTo32bit;
	Vcl::Stdctrls::TLabel* lblManifestWarning;
	Vcl::Extctrls::TImage* imgWarning;
	Cxgraphics::TcxImageList* imglSmall;
	Vcl::Extdlgs::TSavePictureDialog* spdSave;
	Vcl::Actnlist::TActionList* actlCommands;
	Vcl::Actnlist::TAction* actAdd;
	Vcl::Actnlist::TAction* actInsert;
	Vcl::Actnlist::TAction* actReplace;
	Vcl::Actnlist::TAction* actDelete;
	Vcl::Actnlist::TAction* actClear;
	Vcl::Actnlist::TAction* actImport;
	Vcl::Actnlist::TAction* actApply;
	Vcl::Actnlist::TAction* actOK;
	Vcl::Actnlist::TAction* actExport;
	Vcl::Actnlist::TAction* actConvertTo32bit;
	Vcl::Actnlist::TAction* actExportAsBitmap;
	Vcl::Actnlist::TAction* actExportAsPNG;
	Vcl::Extdlgs::TOpenPictureDialog* opdOpen;
	Vcl::Stdctrls::TComboBox* cbImagesSize;
	Vcl::Menus::TPopupMenu* pmExport;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall cbImagesSizeChange(System::TObject* Sender);
	void __fastcall cbTransparentColorChange(System::TObject* Sender);
	void __fastcall cbTransparentColorExit(System::TObject* Sender);
	void __fastcall lvImagesChange(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemChange Change);
	void __fastcall lvImagesDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lvImagesEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall lvImagesStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall lvImagesKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall pbPreviewMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall pbPreviewMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall pbPreviewMouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall pbPreviewPaint(System::TObject* Sender);
	void __fastcall actAddExecute(System::TObject* Sender);
	void __fastcall actInsertExecute(System::TObject* Sender);
	void __fastcall actReplaceExecute(System::TObject* Sender);
	void __fastcall actDeleteExecute(System::TObject* Sender);
	void __fastcall actClearExecute(System::TObject* Sender);
	void __fastcall actImportExecute(System::TObject* Sender);
	void __fastcall actApplyExecute(System::TObject* Sender);
	void __fastcall actOKExecute(System::TObject* Sender);
	void __fastcall actExportAsBitmapExecute(System::TObject* Sender);
	void __fastcall actExportAsPNGExecute(System::TObject* Sender);
	void __fastcall actExportExecute(System::TObject* Sender);
	void __fastcall actConvertTo32bitExecute(System::TObject* Sender);
	
private:
	System::Classes::TStrings* FImportList;
	int FDragImageIndex;
	Cxgraphics::TcxImageList* FPreviewImageList;
	TcxImageListEditorFormInternalStates FInternalState;
	void __fastcall AddColor(const System::UnicodeString AColor);
	bool __fastcall ChangeImagesSize(void);
	void __fastcall DrawFocusedItem(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	System::Uitypes::TColor __fastcall GetColorFromCursorPos(int X, int Y);
	int __fastcall GetFocusedImageIndex(void);
	bool __fastcall IsValidImagesSize(System::UnicodeString ADisplayImagesSizeValue, /* out */ System::Types::TSize &ASize);
	void __fastcall SetFocusedImageIndex(int AValue);
	void __fastcall AddImages(Cximagelisteditor::TcxImageListEditorAddMode AAddMode);
	void __fastcall ImportImageList(System::TObject* Sender);
	void __fastcall PopulateImportItems(void);
	HIDESBASE void __fastcall UpdateActions(void);
	void __fastcall UpdateImagesSizeIndicator(void);
	void __fastcall UpdateTransparentColor(System::Uitypes::TColor AColor)/* overload */;
	void __fastcall UpdateTransparentColor(int X, int Y)/* overload */;
	void __fastcall UpdateTransparentColorIndicator(System::Uitypes::TColor AColor);
	MESSAGE void __fastcall WMDropFiles(Winapi::Messages::TWMDropFiles &Message);
	
protected:
	virtual void __fastcall UpdateControls(void);
	virtual void __fastcall RestorePosition(void);
	virtual void __fastcall StorePosition(void);
	__property int FocusedImageIndex = {read=GetFocusedImageIndex, write=SetFocusedImageIndex, nodefault};
	
public:
	__fastcall virtual TcxImageListEditorForm(Cximagelisteditor::TcxImageListEditor* AImageListEditor);
	__fastcall virtual ~TcxImageListEditorForm(void);
	virtual Vcl::Comctrls::TListView* __fastcall GetVisualDataControl(void);
	virtual void __fastcall SetImportList(System::Classes::TStrings* AValue);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxImageListEditorForm(System::Classes::TComponent* AOwner, int Dummy) : Cximagelisteditor::TcxCustomImageListEditorForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxImageListEditorForm(HWND ParentWindow) : Cximagelisteditor::TcxCustomImageListEditorForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cximagelisteditorview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXIMAGELISTEDITORVIEW)
using namespace Cximagelisteditorview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CximagelisteditorviewHPP
