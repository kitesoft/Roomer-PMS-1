//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NotepadMainForm.h"
#include "NotepadChildForm.h"
#include "NotesMainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxBarEditItem"
#pragma link "cxClasses"
#pragma link "cxDropDownEdit"
#pragma link "cxFontNameComboBox"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma link "cxPC"
#pragma link "cxPCdxBarPopupMenu"
#pragma link "dxBar"
#pragma link "dxRibbonGallery"
#pragma link "dxRibbonRadialMenu"
#pragma link "dxSkinChooserGallery"
#pragma link "dxTabbedMDI"
#pragma link "NotepadMainForm"
#pragma resource "*.dfm"
TfmNotesMainForm *fmNotesMainForm;
//---------------------------------------------------------------------------
__fastcall TfmNotesMainForm::TfmNotesMainForm(TComponent* Owner)
	: TfrmNotepadMain(Owner)
{
}
//---------------------------------------------------------------------------
TfrmNotepadChild* TfmNotesMainForm::CreateChildForm()
{
  TfrmNotepadChild *Result;
  Result = TfrmNotepadMain::CreateChildForm();
  Result->Editor->OnMouseUp = EditorMouseUp;
  Result->Editor->OnContextPopup = (TContextPopupEvent)(&EditorContextPopup);

  Editor->Properties->AllowObjects = true;

  return Result;
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::DoUpdateControls(TfrmNotepadChild *AActiveChild)
{
  TfrmNotepadMain::DoUpdateControls(AActiveChild);
  bbCloseActiveChild->Enabled = ActiveChild != NULL;
  bbClearFormat->Enabled = (AActiveChild != NULL) && (AActiveChild->Editor->SelLength > 0);

  if (FLockMenuUpdate == 0)
	CheckActiveMenu();
}
//---------------------------------------------------------------------------
void __fastcall TfmNotesMainForm::FormShow(TObject *Sender)
{
  TfrmNotepadMain::FormShow(Sender);

  TForm *AChild;
  AChild = MDIChildren[0];
  AChild->WindowState = wsMaximized;
}
//---------------------------------------------------------------------------

void __fastcall TfmNotesMainForm::FormCreate(TObject *Sender)
{
  TfrmNotepadMain::FormCreate(Sender);
  PopulateSymbols();
  OnMouseUp = MainFormMouseUp;
}
//---------------------------------------------------------------------------

void __fastcall TfmNotesMainForm::bbCloseActiveChildClick(TObject *Sender)
{
  if (ActiveChild != NULL)
    ActiveChild->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfmNotesMainForm::dxBarButton19Click(TObject *Sender)
{
  TcxRichEditTableParams *ATable;

  ATable = new TcxRichEditTableParams;
  try
  {
	Editor->InsertTable(3, 3, ATable);
  }
  __finally
  {
	ATable->Free();
  }
}
//---------------------------------------------------------------------------
void cxRichEditInsertBitmap(TcxRichEdit *ARichEdit, Graphics::TBitmap *ABitmap)
{
  TStream *AStream;
  TcxRichEditStreamModes AStreamModes;
  String ARTF = dxBitmapToRTF(ABitmap);

  AStream = new TStringStream(ARTF);
  try
  {
	AStreamModes = ARichEdit->ActiveProperties->StreamModes;
	try
	{
	  ARichEdit->ActiveProperties->StreamModes = ARichEdit->ActiveProperties->StreamModes << resmSelection;
	  AStream->Position = 0;
	  ARichEdit->Lines->LoadFromStream(AStream);
	}
	__finally
	{
	  ARichEdit->ActiveProperties->StreamModes = AStreamModes;
	}
  }
  __finally
  {
	AStream->Free();
  }
}
//---------------------------------------------------------------------------
void __fastcall TfmNotesMainForm::dxBarButton20Click(TObject *Sender)
{
  Graphics::TBitmap *ABitmap;
  TdxSmartImage *AImage;

  if (OpenPictureDialog2->Execute())
  {
	AImage = new TdxSmartImage;
	try
	{
	  AImage->LoadFromFile(OpenPictureDialog2->FileName);
	  ABitmap = AImage->GetAsBitmap();
	  try
	  {
		cxRichEditInsertBitmap(Editor, ABitmap);
	  }
	  __finally
	  {
		ABitmap->Free();
	  }
	}
	__finally
	{
	  AImage->Free();
	};
  }
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::InsertSymbol(WideChar AChar)
{
  Clipboard()->Open();
  try
  {
	Clipboard()->AsText = AChar;
  }
  __finally
  {
	Clipboard()->Close();
  }
	Editor->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TfmNotesMainForm::bsiSymbolClick(TObject *Sender)
{
  FLockMenuUpdate++;
  try
  {
	InsertSymbol(WideChar(((TdxBarButton*)Sender)->Tag));
  }
  __finally
  {
	FLockMenuUpdate--;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfmNotesMainForm::bbClearFormatClick(TObject *Sender)
{
  Editor->SelAttributes->Assign(Editor->DefAttributes);
}
//---------------------------------------------------------------------------

void __fastcall TfmNotesMainForm::acUnderlineExecute(TObject *Sender)
{
  FLockMenuUpdate++;
  try
  {
	TfrmNotepadMain::acUnderlineExecute(Sender);
  }
  __finally
  {
	FLockMenuUpdate--;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfmNotesMainForm::acBoldExecute(TObject *Sender)
{
  FLockMenuUpdate++;
  try
  {
	TfrmNotepadMain::acBoldExecute(Sender);
  }
  __finally
  {
	FLockMenuUpdate--;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfmNotesMainForm::acItalicExecute(TObject *Sender)
{
  FLockMenuUpdate++;
  try
  {
	TfrmNotepadMain::acItalicExecute(Sender);
  }
  __finally
  {
	FLockMenuUpdate--;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfmNotesMainForm::rmFileRadialMenuCloseUp(TObject *Sender)
{
  CheckActiveMenu();
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::UMShowMenu(TMessage &AMessage)
{
  dxMessagesController()->KillMessages(unsigned(Handle), UM_SHOWMENU);
  ShowEditorMenu((TdxRibbonRadialMenu*)(AMessage.WParam), dxLParamToPoint(AMessage.LParam));
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::NCLButtonDown(TMessage &AMessage)
{
  TPoint P;

  if (FActiveRadialMenu != NULL)
  {
	P = ScreenToClient(FRadialMenuPos);
	FActiveRadialMenu->Hide();
  }
  DefaultHandler(&AMessage);
  if (FActiveRadialMenu != NULL)
  {
	FRadialMenuPos = ClientToScreen(P);
	FActiveRadialMenu->Show(FRadialMenuPos.x, FRadialMenuPos.y);
  }
}
//---------------------------------------------------------------------------
TdxRibbonRadialMenu* TfmNotesMainForm::GetMenuForShow()
{
  if (Editor->SelLength != 0)
	return rmSelection;
  else
	return rmBasic;
}
//---------------------------------------------------------------------------
TPoint TfmNotesMainForm::GetMenuPopupPoint(const TPoint &P)
{
  TPoint Result;
  Result = ClientToScreen(P);
  Result.x = Result.x + 200;
  return Result;
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::CheckActiveMenu()
{
  TPoint P;
  if (ActiveChild == NULL)
	HideActiveMenu();
  else
  {
	GetCaretPos(&P);
	PostponedShowMenu(GetMenuForShow(), P);
  };
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::HideActiveMenu()
{
  ShowEditorMenu(NULL, cxInvalidPoint);
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::ShowEditorMenu(TdxRibbonRadialMenu *ARadialMenu, const TPoint &APoint)
{
  TPoint P = GetMenuPopupPoint(APoint);
  if ((FActiveRadialMenu != ARadialMenu) || !(cxPointIsEqual(P, FRadialMenuPos)))
  {
	if (FActiveRadialMenu != NULL)
	  FActiveRadialMenu->Hide();
	FActiveRadialMenu = ARadialMenu;
	FRadialMenuPos = P;
	if (FActiveRadialMenu != NULL)
	  FActiveRadialMenu->Show(P.x, P.y);
  };
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::PostponedShowMenu(TdxRibbonRadialMenu *ARadialMenu, const TPoint &APoint)
{
  PostMessage(Handle, UM_SHOWMENU, WPARAM(ARadialMenu), dxPointToLParam(APoint));
}
//---------------------------------------------------------------------------
void __fastcall TfmNotesMainForm::EditorContextPopup(TObject *Sender, const TPoint &AMousePos, bool &AHandled)
{
  AHandled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfmNotesMainForm::EditorMouseUp(TObject *Sender, TMouseButton Button, TShiftState AShift, int X, int Y)
{
  TPoint P;
  if (Button == mbRight)
  {
	HideActiveMenu();
	P = GetMenuPopupPoint(Point(X, Y));
	rmFileRadialMenu->Popup(P.x, P.y);
  }
  else
	CheckActiveMenu();
}
//---------------------------------------------------------------------------
void __fastcall TfmNotesMainForm::MainFormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  TPoint P;
  if (Button == mbRight)
  {
	P = ClientToScreen(Point(X, Y));
	rmFileRadialMenu->Popup(P.x, P.y);
  };
}
//---------------------------------------------------------------------------
TcxAlphaBitmap* CreateBitmap(const String AFont, WideChar AChar)
{
  int AGlyphSize;
  TRect R;
  TcxAlphaBitmap *Result;

  AGlyphSize = 24;
  R = Rect(0, 0, AGlyphSize, AGlyphSize);
  Result = new TcxAlphaBitmap(AGlyphSize, AGlyphSize);
  Result->Canvas->Font->Name = AFont;
  Result->Canvas->Font->Color = (TColor)0x5C534C;
  Result->Canvas->Font->Size = 16;
  DrawTextW(Result->Canvas->Handle, &AChar, 1, &R, DT_CENTER || DT_VCENTER || DT_SINGLELINE);
  Result->TransformBitmap(btmSetOpaque);

  return Result;
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::AddSymbolItem(int ACode)
{
	TdxBarButton *AItem;
	TdxBarItemLink *AItemLink;
	String AFont;
	TcxAlphaBitmap *ABitmap;

	AItemLink = bsiSymbol->ItemLinks->AddItem(__classid(TdxBarButton));
	AItem = (TdxBarButton*)AItemLink->Item;
	AFont = "Times New Roman";
	AItem->Description = AFont;
	AItem->CloseSubMenuOnClick = false;
	AItem->Tag = ACode;
	AItem->OnClick = bsiSymbolClick;

	ABitmap = CreateBitmap(AFont, WideChar(ACode));
	try
	{
	  AItem->Glyph = ABitmap;
    }
	__finally
	{
	  ABitmap->Free();
	}
}
//---------------------------------------------------------------------------
void TfmNotesMainForm::PopulateSymbols()
{
  const
	int AMathMap[] = {0xB1, 0x2260, 0x2264, 0x2265, 0xF7, 0xD7, 0x221E, 0x2211};
	int AGreekMap[] = {0x03B1, 0x03B2, 0x03B3, 0x03B4, 0x03B5, 0x03B6, 0x03B7, 0x03B8, 0x03B9, 0x03BA};
	int ASymbolMap[] = {0xA9, 0xAE, 0x2122};
	int ACurrencyMap[] = {0x20AC, 0x24, 0xA3, 0xA5, 0x20A3};

  int I;

  for (I = 0; I < 8; I++)
	AddSymbolItem(AMathMap[I]);
  for (I = 0; I < 10; I++)
	AddSymbolItem(AGreekMap[I]);
  for (I = 0; I < 3; I++)
	AddSymbolItem(ASymbolMap[I]);
  for (I = 0; I < 5; I++)
	AddSymbolItem(ACurrencyMap[I]);
}
//---------------------------------------------------------------------------


