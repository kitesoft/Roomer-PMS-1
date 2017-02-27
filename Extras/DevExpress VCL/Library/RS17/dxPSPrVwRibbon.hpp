// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPrVwRibbon.pas' rev: 24.00 (Win32)

#ifndef DxpsprvwribbonHPP
#define DxpsprvwribbonHPP

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
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPreVw.hpp>	// Pascal unit
#include <dxPSPrVw.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarPopupMenuEd.hpp>	// Pascal unit
#include <dxBarExtItems.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxRibbonForm.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxRibbonGallery.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <dxBarApplicationMenu.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsprvwribbon
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxRibbonPrintPreviewForm;
class PASCALIMPLEMENTATION TdxRibbonPrintPreviewForm : public Dxribbonform::TdxRibbonForm
{
	typedef Dxribbonform::TdxRibbonForm inherited;
	
__published:
	Dxbar::TdxBarSubItem* bbAutoText;
	Dxbar::TdxBarLargeButton* bbCloseHeaderAndFooter;
	Dxbar::TdxBarButton* bbDefinePrintStyles;
	Dxbar::TdxBarSubItem* bbEdit;
	Dxbar::TdxBarButton* bbEditFind;
	Dxbar::TdxBarButton* bbEditFindNext;
	Dxbar::TdxBarButton* bbEditReplace;
	Dxbar::TdxBarButton* bbExplorerCreateNewFolder;
	Dxbar::TdxBarButton* bbExplorerDelete;
	Dxbar::TdxBarButton* bbExplorerRename;
	Dxbar::TdxBarButton* bbExportToPDF;
	Dxbar::TdxBarButton* bbFileClose;
	Dxbar::TdxBarButton* bbFileExit;
	Dxbar::TdxBarButton* bbFileLoad;
	Dxbar::TdxBarButton* bbFilePageSetup;
	Dxbar::TdxBarButton* bbFilePrint;
	Dxbar::TdxBarButton* bbFilePrintDialog;
	Dxbar::TdxBarButton* bbFileSave;
	Dxbar::TdxBarButton* bbFormatDateTime;
	Dxbar::TdxBarButton* bbFormatHFBackground;
	Dxbar::TdxBarButton* bbFormatHFClear;
	Dxbar::TdxBarButton* bbFormatPageNumbering;
	Dxbar::TdxBarButton* bbFormatTitle;
	Dxbar::TdxBarButton* bbGoToFirstPage;
	Dxbar::TdxBarButton* bbGoToLastPage;
	Dxbar::TdxBarButton* bbGoToNextPage;
	Dxbar::TdxBarButton* bbGoToPrevPage;
	Dxbar::TdxBarButton* bbInsertEditAutoText;
	Dxbar::TdxBarButton* bbInsertHFDate;
	Dxbar::TdxBarButton* bbInsertHFDateTime;
	Dxbar::TdxBarButton* bbInsertHFMachineName;
	Dxbar::TdxBarButton* bbInsertHFPageNumber;
	Dxbar::TdxBarButton* bbInsertHFPageOfPages;
	Dxbar::TdxBarButton* bbInsertHFTime;
	Dxbar::TdxBarButton* bbInsertHFTotalPages;
	Dxbar::TdxBarButton* bbInsertHFUserName;
	Dxbar::TdxBarButton* bbThumbnailsLarge;
	Dxbar::TdxBarButton* bbThumbnailsSmall;
	Dxbar::TdxBarButton* bbViewExplorer;
	Dxbar::TdxBarButton* bbViewHFClose;
	Dxbar::TdxBarButton* bbViewMarginBar;
	Dxbar::TdxBarButton* bbViewMargins;
	Dxbar::TdxBarButton* bbViewPageFooters;
	Dxbar::TdxBarButton* bbViewPageHeaders;
	Dxbar::TdxBarButton* bbViewStatusBar;
	Dxbar::TdxBarButton* bbViewSwitchToCenterPart;
	Dxbar::TdxBarButton* bbViewSwitchToLeftPart;
	Dxbar::TdxBarButton* bbViewSwitchToRightPart;
	Dxbar::TdxBarButton* bbViewThumbnails;
	Dxbar::TdxBarSubItem* bbZoom;
	Dxbar::TdxBarButton* bbZoomFourPages;
	Dxbar::TdxBarButton* bbZoomMultiplePages;
	Dxbar::TdxBarButton* bbZoomPageWidth;
	Dxbar::TdxBarButton* bbZoomPercent100;
	Dxbar::TdxBarButton* bbZoomSetup;
	Dxbar::TdxBarButton* bbZoomTwoPages;
	Dxbar::TdxBarButton* bbZoomWholePage;
	Dxbar::TdxBarButton* bbZoomWidenToSourceWidth;
	Dxbar::TdxBarListItem* bliInsertAutoTextEntries;
	Dxbar::TdxBarListItem* bliPrintStyles;
	Dxbar::TdxBarSubItem* bsiInsertAutoText;
	Dxbarextitems::TdxBarImageCombo* cbxPredefinedZoom;
	Dxbar::TdxBar* dxBarExplorer;
	Dxbar::TdxBar* dxBarFormat;
	Dxbar::TdxBar* dxBarHeaderAndFooterParts;
	Dxbar::TdxBar* dxBarHeaderAndFooterClose;
	Dxbar::TdxBar* dxBarInsertAutoText;
	Dxbar::TdxBar* dxBarInsertDateTime;
	Dxbar::TdxBar* dxBarInsertName;
	Dxbar::TdxBar* dxBarInsertPageNumber;
	Dxbar::TdxBarManager* dxBarManager;
	Dxbar::TdxBarButton* dxBarMorePages;
	Dxbar::TdxBar* dxBarNavigation;
	Dxbar::TdxBar* dxBarQuickAccess;
	Dxbar::TdxBar* dxBarReport;
	Dxbar::TdxBar* dxBarZoom;
	Dxribbon::TdxRibbon* dxRibbon;
	Dxribbon::TdxRibbonTab* rtHeader;
	Dxribbon::TdxRibbonTab* rtMain;
	Dxbarextitems::TdxBarSpinEdit* seActivePage;
	Vcl::Extctrls::TTimer* TimerHint;
	Dxpsprvw::TdxPSPreviewWindow* Preview;
	Dxribbon::TdxBarApplicationMenu* ApplicationMenu;
	Dxbar::TdxBarSubItem* bbNavigation;
	Dxribbon::TdxRibbonTab* rtExplorer;
	Dxbar::TdxBarLargeButton* bbReportProperties;
	Dxbar::TdxBar* dxBarView;
	Dxbar::TdxBarLargeButton* bbExplorer;
	Dxbar::TdxBarLargeButton* bbThumbnails;
	Dxbar::TdxBarLargeButton* bbClosePreview;
	Dxbar::TdxBarLargeButton* bbHeaderAndFooter;
	Cxgraphics::TcxImageList* ilSmallImages;
	Cxgraphics::TcxImageList* ilLargeImages;
	Dxbar::TdxBar* dxBarExplorerReport;
	Dxbar::TdxBarLargeButton* bbBarExplorerClose;
	Dxbar::TdxBarButton* bbFormatFootnotes;
	Dxribbon::TdxRibbonPopupMenu* pmPrintStyles;
	Dxribbon::TdxRibbonPopupMenu* pmExplorer;
	Dxribbon::TdxRibbonPopupMenu* pmThumbnails;
	Dxribbon::TdxRibbonPopupMenu* dxBarPagesPopup;
	Dxribbon::TdxRibbonPopupMenu* pmPreview;
	Dxbar::TdxBarLargeButton* bbFileDesign;
	Dxbar::TdxBarLargeButton* bbFileRebuild;
	Dxribbon::TdxRibbonTab* rtFooter;
	Dxbar::TdxBar* dxBarPageSetup;
	Dxbar::TdxBarLargeButton* bbPageSetup;
	Dxribbongallery::TdxRibbonGalleryItem* rgiBackgroundColor;
	Dxbar::TdxBarSubItem* bbFormatSubItem;
	Dxbar::TdxBarButton* bbBackgroundNoFill;
	Dxbar::TdxBarButton* bbBackgroundMoreColors;
	Dxbar::TdxBarButton* bbBackgroundFillEffects;
	Dxbar::TdxBarLargeButton* bbFormatShrinkToPageWidth;
	Dxbar::TdxBar* dxBarOutput;
	Dxbar::TdxBarLargeButton* bbLargePrint;
	Dxbar::TdxBarLargeButton* bbLargePrintDialog;
	Dxbar::TdxBarLargeButton* bbLargeExportToPDF;
	Dxbar::TdxBarLargeButton* bbLargePageSetup;
	Dxbar::TdxBarSubItem* bbView;
	Dxbar::TdxBarButton* bbOptions;
	void __fastcall bbExplorerPropertiesClick(System::TObject* Sender);
	void __fastcall bbExportToPDFClick(System::TObject* Sender);
	void __fastcall bbFileCloseClick(System::TObject* Sender);
	void __fastcall bbFileRebuildClick(System::TObject* Sender);
	void __fastcall bbFormatDateTimeClick(System::TObject* Sender);
	void __fastcall bbFormatHeaderAndFooterClick(System::TObject* Sender);
	void __fastcall bbFormatHFBackgroundClick(System::TObject* Sender);
	void __fastcall bbFormatHFClearClick(System::TObject* Sender);
	void __fastcall bbFormatPageNumbersClick(System::TObject* Sender);
	void __fastcall bbFormatShrinkToPageWidthClick(System::TObject* Sender);
	void __fastcall bbFormatTitleClick(System::TObject* Sender);
	void __fastcall bbThumbnailsSizeClick(System::TObject* Sender);
	void __fastcall bbToolsCustomizeClick(System::TObject* Sender);
	void __fastcall bbViewExplorerClick(System::TObject* Sender);
	void __fastcall bbViewHFCloseClick(System::TObject* Sender);
	void __fastcall bbViewMarginBarClick(System::TObject* Sender);
	void __fastcall bbViewMarginsClick(System::TObject* Sender);
	void __fastcall bbViewPageFootersClick(System::TObject* Sender);
	void __fastcall bbViewPageHeadersClick(System::TObject* Sender);
	void __fastcall bbViewStatusBarClick(System::TObject* Sender);
	void __fastcall bbViewThumbnailsClick(System::TObject* Sender);
	void __fastcall bbZoomMultiplePagesClick(System::TObject* Sender);
	void __fastcall bbZoomSetupClick(System::TObject* Sender);
	void __fastcall cbxPredefinedZoomChange(System::TObject* Sender);
	void __fastcall cbxPredefinedZoomClick(System::TObject* Sender);
	void __fastcall CloseClick(System::TObject* Sender);
	void __fastcall DesignClick(System::TObject* Sender);
	void __fastcall dxRibbonHelpButtonClick(Dxribbon::TdxCustomRibbon* Sender);
	void __fastcall ExplorerCreateNewFolderClick(System::TObject* Sender);
	void __fastcall ExplorerDeleteItemClick(System::TObject* Sender);
	void __fastcall ExplorerLoadDataClick(System::TObject* Sender);
	void __fastcall ExplorerRenameItemClick(System::TObject* Sender);
	void __fastcall FileSaveClick(System::TObject* Sender);
	void __fastcall GoToPageClick(System::TObject* Sender);
	void __fastcall HelpClick(System::TObject* Sender);
	void __fastcall InsertHFClick(System::TObject* Sender);
	void __fastcall PageBackgroundClick(System::TObject* Sender);
	void __fastcall PageSetupClick(System::TObject* Sender);
	void __fastcall pmExplorerPopup(System::TObject* Sender);
	void __fastcall PrintClick(System::TObject* Sender);
	void __fastcall seActivePageButtonClick(Dxbarextitems::TdxBarSpinEdit* Sender, Dxbar::TdxBarSpinEditButton Button);
	void __fastcall seActivePageChange(System::TObject* Sender);
	void __fastcall SwitchPartClick(System::TObject* Sender);
	void __fastcall TimerHintTimer(System::TObject* Sender);
	void __fastcall ZoomClick(System::TObject* Sender);
	void __fastcall PreviewInitContent(System::TObject* Sender);
	void __fastcall PreviewCanShowMarginHint(System::TObject* Sender, bool &AAllow);
	void __fastcall PreviewAddExplorerCommand(System::TObject* Sender, Dxpscore::TCustomdxPSExplorerContextCommand* ACommand);
	void __fastcall PreviewAfterPrintReport(System::TObject* Sender, bool AShowDialog);
	void __fastcall PreviewPreviewDblClick(System::TObject* Sender);
	void __fastcall PreviewZoomFactorChanged(System::TObject* Sender);
	void __fastcall PreviewZoomModeChanged(System::TObject* Sender);
	void __fastcall PreviewHFToolBarVisibleChanged(System::TObject* Sender, bool AShow);
	void __fastcall PreviewStyleListChanged(System::TObject* Sender);
	void __fastcall PreviewHFTextEntriesChanged(System::TObject* Sender);
	void __fastcall PreviewUpdateExplorerCommands(System::TObject* Sender);
	void __fastcall PreviewCreationComplete(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall PreviewUpdateControls(System::TObject* Sender);
	void __fastcall bbClosePreviewClick(System::TObject* Sender);
	void __fastcall bbExplorerClick(System::TObject* Sender);
	void __fastcall bbThumbnailsClick(System::TObject* Sender);
	void __fastcall bbHeaderAndFooterClick(System::TObject* Sender);
	void __fastcall bbCloseHeaderAndFooterClick(System::TObject* Sender);
	void __fastcall bbBarExplorerCloseClick(System::TObject* Sender);
	void __fastcall bbFormatFootnotesClick(System::TObject* Sender);
	void __fastcall dxRibbonTabChanged(Dxribbon::TdxCustomRibbon* Sender);
	void __fastcall bbPageSetupClick(System::TObject* Sender);
	void __fastcall bbBackgroundNoFillClick(System::TObject* Sender);
	void __fastcall bbBackgroundMoreColorsClick(System::TObject* Sender);
	void __fastcall bbBackgroundFillEffectsClick(System::TObject* Sender);
	void __fastcall PreviewLoadProperties(System::TObject* Sender, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall PreviewSaveProperties(System::TObject* Sender, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall bliPrintStylesGetData(System::TObject* Sender);
	void __fastcall bbOptionsClick(System::TObject* Sender);
	
private:
	System::Classes::TList* FExplorerContextCommands;
	bool FHeaderAndFooterContextVisible;
	Dxpscore::TCustomdxPSExplorerContextCommand* __fastcall GetExplorerContextCommand(int Index);
	int __fastcall GetExplorerContextCommandCount(void);
	Dxpscore::TCustomdxPSExplorerTreeContainer* __fastcall GetExplorerTree(void);
	bool __fastcall GetIsExplorerAvailable(void);
	bool __fastcall GetIsPrinting(void);
	bool __fastcall GetLocked(void);
	Dxpscore::TBasedxReportLink* __fastcall GetReportLink(void);
	int __fastcall GetZoomFactor(void);
	System::Types::TPoint __fastcall CalcWindowPos(System::TObject* Sender);
	void __fastcall DoGalleryColorItemClick(System::TObject* Sender);
	void __fastcall DoPageSetupReport(int APageIndex);
	void __fastcall DoSelectBackgroundColor(System::Uitypes::TColor AColor);
	void __fastcall DoShowExplorerPopup(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall EnableItemsWhileBuilding(bool Value);
	void __fastcall InitializeBackgroundColorsGallery(void);
	void __fastcall PostCreateFolderMessage(void);
	void __fastcall SetBarItemVisibility(Dxbar::TdxBarItem* Item, bool Value);
	void __fastcall EnabledHFItems(bool Value);
	void __fastcall UpdateHFState(bool Value);
	
protected:
	DYNAMIC void __fastcall Activate(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall AddExplorerContextCommand(Dxpscore::TCustomdxPSExplorerContextCommand* ACommand);
	virtual void __fastcall DoAfterPrintReport(bool AShowDialog);
	virtual void __fastcall DoShowHFToolBar(bool Value);
	virtual void __fastcall ExplorerContextCommandClick(System::TObject* Sender);
	void __fastcall InitializeRibbonLookAndFeel(void);
	virtual void __fastcall LoadStrings(void);
	void __fastcall UpdateBackgroundColorsGallerySelection(void);
	virtual void __fastcall UpdateExplorerContextCommands(void);
	virtual void __fastcall UpdateRibbonHelpButton(void);
	void __fastcall LoadBarManagerDefaults(void);
	void __fastcall SaveBarManagerDefaults(void);
	void __fastcall LoadBarManager(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SaveBarManager(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property int ExplorerContextCommandCount = {read=GetExplorerContextCommandCount, nodefault};
	__property Dxpscore::TCustomdxPSExplorerContextCommand* ExplorerContextCommands[int Index] = {read=GetExplorerContextCommand};
	__property Dxpscore::TCustomdxPSExplorerTreeContainer* ExplorerTree = {read=GetExplorerTree};
	__property bool HeaderAndFooterContextVisible = {read=FHeaderAndFooterContextVisible, nodefault};
	__property bool IsExplorerAvailable = {read=GetIsExplorerAvailable, nodefault};
	__property bool IsPrinting = {read=GetIsPrinting, nodefault};
	__property bool Locked = {read=GetLocked, nodefault};
	__property Dxpscore::TBasedxReportLink* ReportLink = {read=GetReportLink};
	__property int ZoomFactor = {read=GetZoomFactor, nodefault};
	
public:
	__fastcall virtual TdxRibbonPrintPreviewForm(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonPrintPreviewForm(void);
	virtual void __fastcall AfterConstruction(void);
	void __fastcall InitContent(void);
	void __fastcall UpdateContexts(void);
	void __fastcall UpdateControls(void);
public:
	/* TdxCustomRibbonForm.CreateNew */ inline __fastcall virtual TdxRibbonPrintPreviewForm(System::Classes::TComponent* AOwner, int Dummy) : Dxribbonform::TdxRibbonForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonPrintPreviewForm(HWND ParentWindow) : Dxribbonform::TdxRibbonForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsprvwribbon */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPRVWRIBBON)
using namespace Dxpsprvwribbon;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsprvwribbonHPP
