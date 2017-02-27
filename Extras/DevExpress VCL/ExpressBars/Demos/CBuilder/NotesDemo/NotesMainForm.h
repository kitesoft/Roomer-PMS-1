//---------------------------------------------------------------------------

#ifndef NotesMainFormH
#define NotesMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Clipbrd.hpp>
#include "cxBarEditItem.hpp"
#include "cxClasses.hpp"
#include "cxDropDownEdit.hpp"
#include "cxFontNameComboBox.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxPC.hpp"
#include "cxPCdxBarPopupMenu.hpp"
#include "dxBar.hpp"
#include "dxRibbonGallery.hpp"
#include "dxRibbonRadialMenu.hpp"
#include "dxSkinChooserGallery.hpp"
#include "dxTabbedMDI.hpp"
#include "NotepadMainForm.h"
#include <ActnList.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
const UM_SHOWMENU = WM_USER + 2;
//---------------------------------------------------------------------------
class TfmNotesMainForm : public TfrmNotepadMain
{
__published:	// IDE-managed Components
	TdxRibbonRadialMenu *rmFileRadialMenu;
	TdxRibbonRadialMenu *rmSelection;
	TdxRibbonRadialMenu *rmBasic;
	TOpenPictureDialog *OpenPictureDialog2;
	TdxBarButton *bbCloseActiveChild;
	TdxBarButton *bbClearFormat;
	TdxBarSubItem *bsiSymbol;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bbCloseActiveChildClick(TObject *Sender);
	void __fastcall dxBarButton19Click(TObject *Sender);
	void __fastcall dxBarButton20Click(TObject *Sender);
	void __fastcall bsiSymbolClick(TObject *Sender);
	void __fastcall bbClearFormatClick(TObject *Sender);
	void __fastcall acUnderlineExecute(TObject *Sender);
	void __fastcall acBoldExecute(TObject *Sender);
	void __fastcall acItalicExecute(TObject *Sender);
	void __fastcall rmFileRadialMenuCloseUp(TObject *Sender);

private:	// User declarations
	TdxRibbonRadialMenu *FActiveRadialMenu;
	TPoint FRadialMenuPos;
	int FLockMenuUpdate;

	TdxRibbonRadialMenu* GetMenuForShow();
	TPoint GetMenuPopupPoint(const TPoint &P);
	void CheckActiveMenu();
	void HideActiveMenu();
	void ShowEditorMenu(TdxRibbonRadialMenu *ARadialMenu, const TPoint &APoint);
	void PostponedShowMenu(TdxRibbonRadialMenu *ARadialMenu, const TPoint &APoint);
	void __fastcall EditorContextPopup(TObject *Sender, const TPoint &AMousePos, bool &AHandled);
	void __fastcall EditorMouseUp(TObject *Sender, TMouseButton Button, TShiftState AShift, int X, int Y);
	void __fastcall MainFormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void PopulateSymbols();
	void AddSymbolItem(int ACode);
	void InsertSymbol(WideChar AChar);

	void UMShowMenu(TMessage &AMessage);
	void NCLButtonDown(TMessage &AMessage);

  BEGIN_MESSAGE_MAP
	VCL_MESSAGE_HANDLER(UM_SHOWMENU, TMessage, UMShowMenu)
	VCL_MESSAGE_HANDLER(WM_NCLBUTTONDOWN, TMessage, NCLButtonDown)
  END_MESSAGE_MAP(TForm)
protected:
   virtual TfrmNotepadChild* CreateChildForm();
   virtual void DoUpdateControls(TfrmNotepadChild *AActiveChild);
public:		// User declarations
	__fastcall TfmNotesMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmNotesMainForm *fmNotesMainForm;
//---------------------------------------------------------------------------
#endif
