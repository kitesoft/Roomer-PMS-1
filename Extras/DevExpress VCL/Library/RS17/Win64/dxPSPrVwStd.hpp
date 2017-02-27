// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPrVwStd.pas' rev: 24.00 (Win64)

#ifndef DxpsprvwstdHPP
#define DxpsprvwstdHPP

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
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxPreVw.hpp>	// Pascal unit
#include <dxPSPrVw.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsprvwstd
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmStdPreview;
class PASCALIMPLEMENTATION TdxfmStdPreview : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxdropdownedit::TcxComboBox* cbxPredefinedZoom;
	Vcl::Menus::TMainMenu* MainMenu1;
	Vcl::Menus::TMenuItem* miEdit;
	Vcl::Menus::TMenuItem* miEditFind;
	Vcl::Menus::TMenuItem* miEditFindNext;
	Vcl::Menus::TMenuItem* miEditReplace;
	Vcl::Menus::TMenuItem* miExplorer;
	Vcl::Menus::TMenuItem* miExplorerCreateNewFolder;
	Vcl::Menus::TMenuItem* miExplorerDelete;
	Vcl::Menus::TMenuItem* miExplorerProperties;
	Vcl::Menus::TMenuItem* miExplorerRename;
	Vcl::Menus::TMenuItem* miFile;
	Vcl::Menus::TMenuItem* miFileClose;
	Vcl::Menus::TMenuItem* miFileDesign;
	Vcl::Menus::TMenuItem* miFileExit;
	Vcl::Menus::TMenuItem* miFileLoad;
	Vcl::Menus::TMenuItem* miFilePageSetup;
	Vcl::Menus::TMenuItem* miFilePreferences;
	Vcl::Menus::TMenuItem* miFilePrint;
	Vcl::Menus::TMenuItem* miFilePrintStyles;
	Vcl::Menus::TMenuItem* miFileRebuild;
	Vcl::Menus::TMenuItem* miFileSave;
	Vcl::Menus::TMenuItem* miFormat;
	Vcl::Menus::TMenuItem* miFormatAutoText;
	Vcl::Menus::TMenuItem* miFormatDateTime;
	Vcl::Menus::TMenuItem* miFormatPageBackground;
	Vcl::Menus::TMenuItem* miFormatPageNumbering;
	Vcl::Menus::TMenuItem* miFormatShrinkToPageWidth;
	Vcl::Menus::TMenuItem* miFormatTitle;
	Vcl::Menus::TMenuItem* miGoToFirstPage;
	Vcl::Menus::TMenuItem* miGoToLastPage;
	Vcl::Menus::TMenuItem* miGoToNextPage;
	Vcl::Menus::TMenuItem* miGoToPage;
	Vcl::Menus::TMenuItem* miGoToPrevPage;
	Vcl::Menus::TMenuItem* miHelp;
	Vcl::Menus::TMenuItem* miHelpAbout;
	Vcl::Menus::TMenuItem* miHelpTopics;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Menus::TMenuItem* miLine10;
	Vcl::Menus::TMenuItem* miLine11;
	Vcl::Menus::TMenuItem* miLine12;
	Vcl::Menus::TMenuItem* miLine13;
	Vcl::Menus::TMenuItem* miLine14;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miLine20;
	Vcl::Menus::TMenuItem* miLine3;
	Vcl::Menus::TMenuItem* miLine30;
	Vcl::Menus::TMenuItem* miLine31;
	Vcl::Menus::TMenuItem* miLine32;
	Vcl::Menus::TMenuItem* miLine33;
	Vcl::Menus::TMenuItem* miLine34;
	Vcl::Menus::TMenuItem* miLine39;
	Vcl::Menus::TMenuItem* miLine4;
	Vcl::Menus::TMenuItem* miLine40;
	Vcl::Menus::TMenuItem* miLine5;
	Vcl::Menus::TMenuItem* miLine6;
	Vcl::Menus::TMenuItem* miLine7;
	Vcl::Menus::TMenuItem* miLine8;
	Vcl::Menus::TMenuItem* miLine9;
	Vcl::Menus::TMenuItem* miView;
	Vcl::Menus::TMenuItem* miViewExplorer;
	Vcl::Menus::TMenuItem* miViewFlatTBtns;
	Vcl::Menus::TMenuItem* miViewLargeTBtns;
	Vcl::Menus::TMenuItem* miViewMarginBar;
	Vcl::Menus::TMenuItem* miViewMargins;
	Vcl::Menus::TMenuItem* miViewPageFooters;
	Vcl::Menus::TMenuItem* miViewPageHeaders;
	Vcl::Menus::TMenuItem* miViewStatusBar;
	Vcl::Menus::TMenuItem* miViewThumbnails;
	Vcl::Menus::TMenuItem* miViewToolBar;
	Vcl::Menus::TMenuItem* miViewZoom;
	Vcl::Menus::TMenuItem* miZoomFourPages;
	Vcl::Menus::TMenuItem* miZoomPageWidth;
	Vcl::Menus::TMenuItem* miZoomPercent100;
	Vcl::Menus::TMenuItem* miZoomSetup;
	Vcl::Menus::TMenuItem* miZoomTwoPages;
	Vcl::Menus::TMenuItem* miZoomWholePage;
	Vcl::Menus::TMenuItem* miZoomWidenToSourceWidth;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* N3;
	Vcl::Menus::TMenuItem* N4;
	Vcl::Menus::TMenuItem* N5;
	Vcl::Menus::TMenuItem* N6;
	Vcl::Menus::TMenuItem* N7;
	Vcl::Menus::TPopupMenu* pmDesigners;
	Vcl::Menus::TPopupMenu* pmExplorer;
	Vcl::Menus::TMenuItem* pmiExplorerCreateFolder;
	Vcl::Menus::TMenuItem* pmiExplorerDelete;
	Vcl::Menus::TMenuItem* pmiExplorerLoadData;
	Vcl::Menus::TMenuItem* pmiExplorerProperties;
	Vcl::Menus::TMenuItem* pmiExplorerRename;
	Vcl::Menus::TMenuItem* pmiExplorerUnloadData;
	Vcl::Menus::TMenuItem* pmiFilePrintStyles;
	Vcl::Menus::TMenuItem* pmiFlatBtns;
	Vcl::Menus::TMenuItem* pmiGoToFirstPage;
	Vcl::Menus::TMenuItem* pmiGoToLastPage;
	Vcl::Menus::TMenuItem* pmiGoToNextPage;
	Vcl::Menus::TMenuItem* pmiGoToPrevPage;
	Vcl::Menus::TMenuItem* pmiLargeBtns;
	Vcl::Menus::TMenuItem* pmiLargeThumbnails;
	Vcl::Menus::TMenuItem* pmiPageSetup;
	Vcl::Menus::TMenuItem* pmiReportDesign;
	Vcl::Menus::TMenuItem* pmiReportShrinkToPageWidth;
	Vcl::Menus::TMenuItem* pmiSmallThumbnails;
	Vcl::Menus::TMenuItem* pmiZoom;
	Vcl::Menus::TMenuItem* pmiZoomFourPages;
	Vcl::Menus::TMenuItem* pmiZoomPageWidth;
	Vcl::Menus::TMenuItem* pmiZoomPercent100;
	Vcl::Menus::TMenuItem* pmiZoomTwoPages;
	Vcl::Menus::TMenuItem* pmiZoomWholePage;
	Vcl::Menus::TMenuItem* pmiZoomWidenToSourceWidth;
	Vcl::Menus::TPopupMenu* pmPreview;
	Vcl::Menus::TPopupMenu* pmPrintStyles;
	Vcl::Menus::TPopupMenu* pmThumbnails;
	Vcl::Menus::TPopupMenu* pmToolBar;
	Cxgroupbox::TcxGroupBox* pnlActivePage;
	Cxgroupbox::TcxGroupBox* pnlPredefinedZoom;
	Cxspinedit::TcxSpinEdit* seActivePage;
	Vcl::Comctrls::TToolButton* tbClose;
	Vcl::Comctrls::TToolButton* tbFileLoad;
	Vcl::Comctrls::TToolButton* tbFileSave;
	Vcl::Comctrls::TToolButton* tbFileUnload;
	Vcl::Comctrls::TToolButton* tbFourPage;
	Vcl::Comctrls::TToolButton* tbGotoFirstPage;
	Vcl::Comctrls::TToolButton* tbGotoLastPage;
	Vcl::Comctrls::TToolButton* tbGotoNextPage;
	Vcl::Comctrls::TToolButton* tbGotoPrevPage;
	Vcl::Comctrls::TToolButton* tbHelp;
	Vcl::Comctrls::TToolButton* tbMultiplePages;
	Vcl::Comctrls::TToolButton* tbOnePage;
	Vcl::Comctrls::TToolButton* tbPageBackground;
	Vcl::Comctrls::TToolButton* tbPageSetup;
	Vcl::Comctrls::TToolButton* tbPageWidth;
	Vcl::Comctrls::TToolButton* tbPercent100;
	Vcl::Comctrls::TToolButton* tbPrint;
	Vcl::Comctrls::TToolButton* tbPrintDialog;
	Vcl::Comctrls::TToolButton* tbReportDesigner;
	Vcl::Comctrls::TToolButton* tbSeparator1;
	Vcl::Comctrls::TToolButton* tbSeparator2;
	Vcl::Comctrls::TToolButton* tbSeparator3;
	Vcl::Comctrls::TToolButton* tbSeparator4;
	Vcl::Comctrls::TToolButton* tbSeparator5;
	Vcl::Comctrls::TToolButton* tbSeparator8;
	Vcl::Comctrls::TToolButton* tbShrinkToPageWidth;
	Vcl::Comctrls::TToolButton* tbTwoPage;
	Vcl::Comctrls::TToolButton* tbViewExplorer;
	Vcl::Comctrls::TToolButton* tbViewThumbnails;
	Vcl::Comctrls::TToolButton* tbWidenToSourceWidth;
	Vcl::Extctrls::TTimer* Timer1;
	Vcl::Comctrls::TToolBar* ToolBar;
	Vcl::Comctrls::TToolButton* ToolButton1;
	Vcl::Comctrls::TToolButton* ToolButton2;
	Vcl::Comctrls::TToolButton* ToolButton5;
	Vcl::Comctrls::TToolButton* tbExportToPDF;
	Vcl::Menus::TMenuItem* miLine21;
	Vcl::Menus::TMenuItem* miExportToPDF;
	Dxpsprvw::TdxPSPreviewWindow* Preview;
	Vcl::Menus::TMenuItem* miFormatFootnotes;
	Cxgraphics::TcxImageList* ilToolBarSmall;
	Cxgraphics::TcxImageList* ilStub;
	void __fastcall pmiFlatBtnsClick(System::TObject* Sender);
	void __fastcall pmiLargeBtnsClick(System::TObject* Sender);
	void __fastcall PageSetupClick(System::TObject* Sender);
	void __fastcall PrintClick(System::TObject* Sender);
	void __fastcall ZoomClick(System::TObject* Sender);
	void __fastcall GoToPageClick(System::TObject* Sender);
	void __fastcall CloseClick(System::TObject* Sender);
	void __fastcall cbxPredefinedZoomClick(System::TObject* Sender);
	void __fastcall cbxPredefinedZoomKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall seActivePageExit(System::TObject* Sender);
	void __fastcall seKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall DesignClick(System::TObject* Sender);
	void __fastcall PageBackgroundClick(System::TObject* Sender);
	void __fastcall OptionsClick(System::TObject* Sender);
	void __fastcall miViewMarginsClick(System::TObject* Sender);
	void __fastcall HelpClick(System::TObject* Sender);
	void __fastcall miViewMarginBarClick(System::TObject* Sender);
	void __fastcall miViewStatusBarClick(System::TObject* Sender);
	void __fastcall pmToolBarPopup(System::TObject* Sender);
	void __fastcall pmPreviewPopup(System::TObject* Sender);
	void __fastcall tbMultiplePagesClick(System::TObject* Sender);
	void __fastcall miZoomSetupClick(System::TObject* Sender);
	void __fastcall ShrinkToPageWidthClick(System::TObject* Sender);
	void __fastcall miFormatDateTimeClick(System::TObject* Sender);
	void __fastcall miFormatPageNumberingClick(System::TObject* Sender);
	void __fastcall miViewPageHeadersClick(System::TObject* Sender);
	void __fastcall miViewPageFootersClick(System::TObject* Sender);
	void __fastcall pmPrintStylesPopup(System::TObject* Sender);
	void __fastcall miFormatAutoTextClick(System::TObject* Sender);
	void __fastcall Timer1Timer(System::TObject* Sender);
	void __fastcall ViewExplorerClick(System::TObject* Sender);
	void __fastcall ExplorerCreateNewFolderClick(System::TObject* Sender);
	void __fastcall FileSaveClick(System::TObject* Sender);
	void __fastcall ExplorerDeleteClick(System::TObject* Sender);
	void __fastcall ExplorerRenameClick(System::TObject* Sender);
	void __fastcall FileLoadClick(System::TObject* Sender);
	void __fastcall pmExplorerPopup(System::TObject* Sender);
	void __fastcall FileCloseClick(System::TObject* Sender);
	void __fastcall miFormatTitleClick(System::TObject* Sender);
	void __fastcall ViewThumbnailsClick(System::TObject* Sender);
	void __fastcall pmiThumbnailsSizeClick(System::TObject* Sender);
	void __fastcall pmThumbnailsPopup(System::TObject* Sender);
	void __fastcall ExplorerPropertiesClick(System::TObject* Sender);
	void __fastcall miFileRebuildClick(System::TObject* Sender);
	void __fastcall cbxPredefinedZoomPropertiesCloseUp(System::TObject* Sender);
	void __fastcall cbxPredefinedZoomPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall miExportToPDFClick(System::TObject* Sender);
	void __fastcall PreviewAddExplorerCommand(System::TObject* Sender, Dxpscore::TCustomdxPSExplorerContextCommand* ACommand);
	void __fastcall PreviewAfterPrintReport(System::TObject* Sender, bool AShowDialog);
	void __fastcall PreviewCreationComplete(System::TObject* Sender);
	void __fastcall PreviewInitContent(System::TObject* Sender);
	void __fastcall PreviewStyleListChanged(System::TObject* Sender);
	void __fastcall PreviewUpdateControls(System::TObject* Sender);
	void __fastcall PreviewUpdateExplorerCommands(System::TObject* Sender);
	void __fastcall PreviewZoomFactorChanged(System::TObject* Sender);
	void __fastcall PreviewZoomModeChanged(System::TObject* Sender);
	void __fastcall miFormatFootnotesClick(System::TObject* Sender);
	void __fastcall PreviewLoadProperties(System::TObject* Sender, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall PreviewSaveProperties(System::TObject* Sender, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	
private:
	System::Classes::TList* FExplorerContextCommandMenuItems;
	System::Classes::TList* FExplorerContextCommandPopupMenuItems;
	System::Classes::TList* FExplorerContextCommandToolButtons;
	bool FFlatCtrls;
	Vcl::Controls::TImageList* FilToolBarLarge;
	bool FLargeBtns;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	Vcl::Menus::TMenuItem* __fastcall GetExplorerContextCommandMenuItem(int Index);
	int __fastcall GetExplorerContextCommandMenuItemCount(void);
	Vcl::Menus::TMenuItem* __fastcall GetExplorerContextCommandPopupMenuItem(int Index);
	int __fastcall GetExplorerContextCommandPopupMenuItemCount(void);
	Vcl::Comctrls::TToolButton* __fastcall GetExplorerContextCommandToolButton(int Index);
	int __fastcall GetExplorerContextCommandToolButtonCount(void);
	bool __fastcall GetLocked(void);
	Dxpscore::TBasedxReportLink* __fastcall GetReportLink(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetToolBarImageList(void);
	void __fastcall SetFlatCtrls(bool Value);
	void __fastcall SetLargeBtns(bool Value);
	void __fastcall PreviewAfterCreateControls(void);
	void __fastcall UpdateControls(void);
	void __fastcall LoadDefaultProperties(void);
	void __fastcall SaveDefaultProperties(void);
	void __fastcall LoadProperties(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SaveProperties(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	System::Types::TPoint __fastcall CalculateWindowPos(System::TObject* Sender);
	Vcl::Controls::TImageList* __fastcall CreateLargeImages(Vcl::Imglist::TCustomImageList* ASource);
	void __fastcall ArrangeToolBarCtrls(void);
	void __fastcall AssignToolBarImages(void);
	void __fastcall CheckItem(Vcl::Menus::TMenuItem* AParent);
	void __fastcall DoShowExplorerPopup(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall SetupFlatCtrls(void);
	MESSAGE void __fastcall WMInitMenu(Winapi::Messages::TWMInitMenu &Message);
	
protected:
	DYNAMIC void __fastcall Activate(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual void __fastcall ExplorerContextCommandClick(System::TObject* Sender);
	void __fastcall InitializeLookAndFeel(void);
	virtual void __fastcall InitializeZoomComboBox(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall LoadStrings(void);
	__property int ExplorerContextCommandMenuItemCount = {read=GetExplorerContextCommandMenuItemCount, nodefault};
	__property Vcl::Menus::TMenuItem* ExplorerContextCommandMenuItems[int Index] = {read=GetExplorerContextCommandMenuItem};
	__property int ExplorerContextCommandPopupMenuItemCount = {read=GetExplorerContextCommandPopupMenuItemCount, nodefault};
	__property Vcl::Menus::TMenuItem* ExplorerContextCommandPopupMenuItems[int Index] = {read=GetExplorerContextCommandPopupMenuItem};
	__property int ExplorerContextCommandToolButtonCount = {read=GetExplorerContextCommandToolButtonCount, nodefault};
	__property Vcl::Comctrls::TToolButton* ExplorerContextCommandToolButtons[int Index] = {read=GetExplorerContextCommandToolButton};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel};
	
public:
	__fastcall virtual TdxfmStdPreview(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmStdPreview(void);
	virtual void __fastcall AfterConstruction(void);
	__property bool FlatCtrls = {read=FFlatCtrls, write=SetFlatCtrls, nodefault};
	__property bool LargeBtns = {read=FLargeBtns, write=SetLargeBtns, nodefault};
	__property bool Locked = {read=GetLocked, nodefault};
	__property Dxpscore::TBasedxReportLink* ReportLink = {read=GetReportLink};
	__property Vcl::Imglist::TCustomImageList* ToolBarImageList = {read=GetToolBarImageList};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmStdPreview(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmStdPreview(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsprvwstd */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPRVWSTD)
using namespace Dxpsprvwstd;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsprvwstdHPP
