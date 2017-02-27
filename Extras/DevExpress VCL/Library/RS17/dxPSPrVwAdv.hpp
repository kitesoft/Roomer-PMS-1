// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPrVwAdv.pas' rev: 24.00 (Win32)

#ifndef DxpsprvwadvHPP
#define DxpsprvwadvHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPreVw.hpp>	// Pascal unit
#include <dxPSPrVw.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarPopupMenuEd.hpp>	// Pascal unit
#include <dxBarExtItems.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsprvwadv
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmPreviewWdxBar;
class PASCALIMPLEMENTATION TdxfmPreviewWdxBar : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Dxbar::TdxBarManager* dxBarManager;
	Dxbar::TdxBarSubItem* bbFile;
	Dxbar::TdxBarButton* bbToolsOptions;
	Dxbar::TdxBarButton* bbFileDesign;
	Dxbar::TdxBarButton* bbFilePrint;
	Dxbar::TdxBarButton* bbFilePrintDialog;
	Dxbar::TdxBarSubItem* bbView;
	Dxbar::TdxBarButton* bbZoomPercent100;
	Dxbar::TdxBarButton* bbZoomPageWidth;
	Dxbar::TdxBarButton* bbZoomWholePage;
	Dxbar::TdxBarButton* bbZoomTwoPages;
	Dxbar::TdxBarSubItem* bbGoToPage;
	Dxbar::TdxBarButton* bbGoToFirstPage;
	Dxbar::TdxBarButton* bbGoToPrevPage;
	Dxbar::TdxBarButton* bbGoToNextPage;
	Dxbar::TdxBarButton* bbGoToLastPage;
	Dxbar::TdxBarSubItem* bbHelp;
	Dxbar::TdxBarButton* bbHelpTopics;
	Dxbar::TdxBarButton* bbZoomFourPages;
	Dxbar::TdxBarButton* bbZoomWidenToSourceWidth;
	Dxbarextitems::TdxBarSpinEdit* seActivePage;
	Dxbar::TdxBarPopupMenu* pmPreview;
	Dxbarextitems::TdxBarToolbarsListItem* bbViewToolbars;
	Dxbar::TdxBarButton* bbZoomMultiplePages;
	Dxbarextitems::TdxBarImageCombo* cbxPredefinedZoom;
	Dxbar::TdxBarButton* bbZoomSetup;
	Dxbar::TdxBarButton* bbFileExit;
	Dxbar::TdxBarButton* bbFormatShrinkToPageWidth;
	Dxbar::TdxBarButton* bbViewMargins;
	Dxbar::TdxBarButton* bbViewMarginBar;
	Dxbar::TdxBarButton* bbViewStatusBar;
	Dxbar::TdxBarSubItem* bsiShortcutPreview;
	Dxbar::TdxBarSubItem* bsiInsertHFAutoText;
	Dxbar::TdxBarButton* bbInsertHFPageNumber;
	Dxbar::TdxBarButton* bbInsertHFTotalPages;
	Dxbar::TdxBarButton* bbInsertHFPageOfPages;
	Dxbar::TdxBarButton* bbInsertHFDate;
	Dxbar::TdxBarButton* bbInsertHFTime;
	Dxbar::TdxBarButton* bbInsertHFDateTime;
	Dxbar::TdxBarButton* bbViewHFSwitchHeaderFooter;
	Dxbar::TdxBarButton* bbInsertHFUserName;
	Dxbar::TdxBarButton* bbInsertHFMachineName;
	Dxbar::TdxBarButton* bbViewHFClose;
	Dxbar::TdxBarButton* bbFormatHeaderAndFooter;
	Dxbar::TdxBarButton* bbViewSwitchToLeftPart;
	Dxbar::TdxBarButton* bbViewSwitchToCenterPart;
	Dxbar::TdxBarButton* bbViewSwitchToRightPart;
	Dxbar::TdxBarButton* bbFormatHFClear;
	Dxbar::TdxBarSubItem* bbFormat;
	Dxbar::TdxBarSubItem* bbEdit;
	Dxbar::TdxBarButton* bbFilePageSetup;
	Dxbar::TdxBarListItem* bliInsertAutoTextEntries;
	Dxbar::TdxBarButton* bbInsertEditAutoText;
	Dxbar::TdxBarButton* bbFormatHFBackground;
	Dxbar::TdxBarButton* bbFormatDateTime;
	Dxbar::TdxBarButton* bbFormatPageNumbering;
	Dxbar::TdxBarButton* bbEditFind;
	Dxbar::TdxBarButton* bbEditFindNext;
	Dxbar::TdxBarButton* bbEditReplace;
	Dxbar::TdxBarButton* bbViewPageHeaders;
	Dxbar::TdxBarButton* bbViewPageFooters;
	Dxbar::TdxBarSubItem* bbViewPages;
	Dxbar::TdxBarButton* bbFormatPageBackground;
	Dxbar::TdxBarSubItem* bbViewZoom;
	Dxbar::TdxBarButton* bbToolsCustomize;
	Dxbar::TdxBarSubItem* bbTools;
	Dxbar::TdxBarButton* bbHelpAbout;
	Dxbar::TdxBarSubItem* bbInsert;
	Dxbar::TdxBarSubItem* bsiNewMenuNewMenu;
	Dxbar::TdxBarPopupMenu* pmPrintStyles;
	Dxbar::TdxBarListItem* bliPrintStyles;
	Dxbar::TdxBarButton* bbDefinePrintStyles;
	Dxbar::TdxBarSubItem* bsiInsertAutoText;
	Vcl::Extctrls::TTimer* TimerHint;
	Dxbar::TdxBarButton* bbFileLoad;
	Dxbar::TdxBarButton* bbExplorerCreateNewFolder;
	Dxbar::TdxBarButton* bbExplorerDelete;
	Dxbar::TdxBarButton* bbExplorerRename;
	Dxbar::TdxBarSubItem* bbExplorer;
	Dxbar::TdxBarButton* bbFileSave;
	Dxbar::TdxBarButton* bbViewExplorer;
	Dxbar::TdxBarPopupMenu* pmExplorer;
	Dxbar::TdxBarSubItem* bsiShortCutExplorer;
	Dxbar::TdxBarButton* bbFileClose;
	Dxbar::TdxBarButton* bbFormatTitle;
	Dxbar::TdxBarPopupMenu* pmThumbnails;
	Dxbar::TdxBarButton* bbViewThumbnails;
	Dxbar::TdxBarButton* bbThumbnailsSmall;
	Dxbar::TdxBarButton* bbThumbnailsLarge;
	Dxbar::TdxBarSubItem* bsiShortcutThumbnails;
	Dxbar::TdxBarButton* bbExplorerProperties;
	Dxbar::TdxBarButton* bbFileRebuild;
	Dxbar::TdxBarButton* bbExportToPDF;
	Dxpsprvw::TdxPSPreviewWindow* Preview;
	Cxgraphics::TcxImageList* ilToolBar;
	Dxbar::TdxBarButton* bbFormatFootnotes;
	void __fastcall PageSetupClick(System::TObject* Sender);
	void __fastcall ZoomClick(System::TObject* Sender);
	void __fastcall GoToPageClick(System::TObject* Sender);
	void __fastcall CloseClick(System::TObject* Sender);
	void __fastcall DesignClick(System::TObject* Sender);
	void __fastcall PageBackgroundClick(System::TObject* Sender);
	void __fastcall bbViewMarginsClick(System::TObject* Sender);
	void __fastcall HelpClick(System::TObject* Sender);
	void __fastcall bbViewMarginBarClick(System::TObject* Sender);
	void __fastcall bbViewStatusBarClick(System::TObject* Sender);
	void __fastcall seActivePageChange(System::TObject* Sender);
	void __fastcall cbxPredefinedZoomChange(System::TObject* Sender);
	void __fastcall seActivePageButtonClick(Dxbarextitems::TdxBarSpinEdit* Sender, Dxbar::TdxBarSpinEditButton Button);
	void __fastcall bbZoomMultiplePagesClick(System::TObject* Sender);
	void __fastcall bbZoomSetupClick(System::TObject* Sender);
	void __fastcall cbxPredefinedZoomClick(System::TObject* Sender);
	void __fastcall bbFormatShrinkToPageWidthClick(System::TObject* Sender);
	void __fastcall miCustomizePopupClick(System::TObject* Sender);
	void __fastcall dxBarManagerBarVisibleChange(Dxbar::TdxBarManager* Sender, Dxbar::TdxBar* ABar);
	void __fastcall bbViewHFCloseClick(System::TObject* Sender);
	void __fastcall bbFormatHeaderAndFooterClick(System::TObject* Sender);
	void __fastcall InsertHFClick(System::TObject* Sender);
	void __fastcall bbViewHFSwitchHeaderFooterClick(System::TObject* Sender);
	void __fastcall bbFormatDateTimeClick(System::TObject* Sender);
	void __fastcall SwitchPartClick(System::TObject* Sender);
	void __fastcall bbFormatHFClearClick(System::TObject* Sender);
	void __fastcall bbFormatHFBackgroundClick(System::TObject* Sender);
	void __fastcall PrintClick(System::TObject* Sender);
	void __fastcall bbFormatPageNumbersClick(System::TObject* Sender);
	void __fastcall bbViewPageHeadersClick(System::TObject* Sender);
	void __fastcall bbViewPageFootersClick(System::TObject* Sender);
	void __fastcall bbToolsCustomizeClick(System::TObject* Sender);
	void __fastcall dxBarManagerShowCustomizingForm(System::TObject* Sender);
	void __fastcall dxBarManagerHideCustomizingForm(System::TObject* Sender);
	void __fastcall bbToolsOptionsClick(System::TObject* Sender);
	void __fastcall TimerHintTimer(System::TObject* Sender);
	void __fastcall FileSaveClick(System::TObject* Sender);
	void __fastcall ExplorerLoadDataClick(System::TObject* Sender);
	void __fastcall ExplorerCreateNewFolderClick(System::TObject* Sender);
	void __fastcall ExplorerDeleteItemClick(System::TObject* Sender);
	void __fastcall ExplorerRenameItemClick(System::TObject* Sender);
	void __fastcall bbViewExplorerClick(System::TObject* Sender);
	void __fastcall pmExplorerPopup(System::TObject* Sender);
	void __fastcall bbFileCloseClick(System::TObject* Sender);
	void __fastcall bbFormatTitleClick(System::TObject* Sender);
	void __fastcall bbThumbnailsSizeClick(System::TObject* Sender);
	void __fastcall bbViewThumbnailsClick(System::TObject* Sender);
	void __fastcall bbExplorerPropertiesClick(System::TObject* Sender);
	void __fastcall bbFileRebuildClick(System::TObject* Sender);
	void __fastcall bbExportToPDFClick(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall PreviewAddExplorerCommand(System::TObject* Sender, Dxpscore::TCustomdxPSExplorerContextCommand* ACommand);
	void __fastcall PreviewAfterPrintReport(System::TObject* Sender, bool AShowDialog);
	void __fastcall PreviewCreationComplete(System::TObject* Sender);
	void __fastcall PreviewInitContent(System::TObject* Sender);
	void __fastcall PreviewStyleListChanged(System::TObject* Sender);
	void __fastcall PreviewUpdateControls(System::TObject* Sender);
	void __fastcall PreviewUpdateExplorerCommands(System::TObject* Sender);
	void __fastcall PreviewZoomFactorChanged(System::TObject* Sender);
	void __fastcall PreviewZoomModeChanged(System::TObject* Sender);
	void __fastcall PreviewCanShowMarginHint(System::TObject* Sender, bool &AAllow);
	void __fastcall PreviewHFTextEntriesChanged(System::TObject* Sender);
	void __fastcall PreviewPreviewDblClick(System::TObject* Sender);
	void __fastcall PreviewHFToolBarVisibleChanged(System::TObject* Sender, bool AShow);
	void __fastcall bbFormatFootnotesClick(System::TObject* Sender);
	void __fastcall PreviewLoadProperties(System::TObject* Sender, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall PreviewSaveProperties(System::TObject* Sender, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall bliPrintStylesGetData(System::TObject* Sender);
	
private:
	System::Classes::TList* FExplorerContextCommands;
	Dxpscore::TCustomdxPSExplorerContextCommand* __fastcall GetExplorerContextCommand(int Index);
	int __fastcall GetExplorerContextCommandCount(void);
	bool __fastcall GetLocked(void);
	Dxpscore::TBasedxReportLink* __fastcall GetReportLink(void);
	System::Types::TPoint __fastcall CalcWindowPos(System::TObject* Sender);
	void __fastcall DoShowExplorerPopup(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall EnableItemsWhileBuilding(bool Value);
	void __fastcall PostCreateFolderMessage(void);
	void __fastcall SetBarItemVisibility(Dxbar::TdxBarItem* Item, bool Value);
	Dxbar::TdxBar* __fastcall ShortcutBar(void);
	void __fastcall ShowShortCutBar(bool Value);
	Dxbar::TdxBar* __fastcall HFBar(void);
	void __fastcall EnabledHFItems(bool Value);
	void __fastcall ShowHFBar(bool Value);
	void __fastcall UpdateHFState(bool Value);
	void __fastcall LoadBarManagerDefaults(void);
	void __fastcall SaveBarManagerDefaults(void);
	void __fastcall LoadBarManager(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SaveBarManager(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	
protected:
	DYNAMIC void __fastcall Activate(void);
	virtual void __fastcall ExplorerContextCommandClick(System::TObject* Sender);
	void __fastcall LoadStrings(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property int ExplorerContextCommandCount = {read=GetExplorerContextCommandCount, nodefault};
	__property Dxpscore::TCustomdxPSExplorerContextCommand* ExplorerContextCommands[int Index] = {read=GetExplorerContextCommand};
	__property bool Locked = {read=GetLocked, nodefault};
	__property Dxpscore::TBasedxReportLink* ReportLink = {read=GetReportLink};
	
public:
	__fastcall virtual TdxfmPreviewWdxBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmPreviewWdxBar(void);
	virtual void __fastcall AfterConstruction(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmPreviewWdxBar(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmPreviewWdxBar(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsprvwadv */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPRVWADV)
using namespace Dxpsprvwadv;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsprvwadvHPP
