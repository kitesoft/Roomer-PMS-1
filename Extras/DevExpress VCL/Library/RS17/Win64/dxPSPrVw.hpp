// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPrVw.pas' rev: 24.00 (Win64)

#ifndef DxpsprvwHPP
#define DxpsprvwHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPreVw.hpp>	// Pascal unit
#include <dxPSPrVwOpt.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxSplitter.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsprvw
{
//-- type declarations -------------------------------------------------------
enum TfmPreviewStatusSection : unsigned char { ssCurrentPage, ssPageCount, ssPaperSize, ssStatus };

typedef System::Set<TfmPreviewStatusSection, TfmPreviewStatusSection::ssCurrentPage, TfmPreviewStatusSection::ssStatus>  TfmPreviewStatusSections;

enum TdxPSExplorerVisibiltyState : unsigned char { evsUndefined, evsHidden, evsShown };

enum TdxPSThumbnailsVisibiltyState : unsigned char { tvsUndefined, tvsHidden, tvsShown };

enum TdxPSPageMarginsVisibilityState : unsigned char { mvsUndefined, mvsHidden, mvsShown };

enum TdxPSPreviewWindowStatusBarMode : unsigned char { psbmNormal, psbmProgress };

typedef void __fastcall (__closure *TdxPSPreviewWindowAddExplorerCommandEvent)(System::TObject* Sender, Dxpscore::TCustomdxPSExplorerContextCommand* ACommand);

typedef void __fastcall (__closure *TdxPSPreviewWindowAfterPrintReportEvent)(System::TObject* Sender, bool AShowDialog);

typedef void __fastcall (__closure *TdxPSPreviewWindowCanShowMarginHint)(System::TObject* Sender, bool &AAllow);

typedef void __fastcall (__closure *TdxPSPreviewWindowHFToolBarShow)(System::TObject* Sender, bool AShow);

class DELPHICLASS TdxPSExplorerToolBar;
class PASCALIMPLEMENTATION TdxPSExplorerToolBar : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
protected:
	virtual void __fastcall Paint(void);
	
public:
	__property Font;
public:
	/* TcxControl.Create */ inline __fastcall virtual TdxPSExplorerToolBar(System::Classes::TComponent* AOwner) : Cxcontrols::TcxControl(AOwner) { }
	/* TcxControl.Destroy */ inline __fastcall virtual ~TdxPSExplorerToolBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSExplorerToolBar(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TdxPSExplorerHostPanel;
class PASCALIMPLEMENTATION TdxPSExplorerHostPanel : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
protected:
	virtual void __fastcall Paint(void);
public:
	/* TcxControl.Create */ inline __fastcall virtual TdxPSExplorerHostPanel(System::Classes::TComponent* AOwner) : Cxcontrols::TcxControl(AOwner) { }
	/* TcxControl.Destroy */ inline __fastcall virtual ~TdxPSExplorerHostPanel(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSExplorerHostPanel(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TdxPSExplorerCloseButton;
class PASCALIMPLEMENTATION TdxPSExplorerCloseButton : public Vcl::Buttons::TSpeedButton
{
	typedef Vcl::Buttons::TSpeedButton inherited;
	
public:
	__fastcall virtual TdxPSExplorerCloseButton(System::Classes::TComponent* AOwner);
public:
	/* TSpeedButton.Destroy */ inline __fastcall virtual ~TdxPSExplorerCloseButton(void) { }
	
};


class DELPHICLASS TdxPSPreviewExplorerChangeNotifier;
class DELPHICLASS TdxPSPreviewWindow;
class PASCALIMPLEMENTATION TdxPSPreviewExplorerChangeNotifier : public Dxpscore::TdxPSExplorerChangeNotifierAdapter
{
	typedef Dxpscore::TdxPSExplorerChangeNotifierAdapter inherited;
	
private:
	TdxPSPreviewWindow* FPreview;
	
protected:
	virtual void __fastcall ItemDataLoaded(Dxpscore::TdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemDataUnloaded(Dxpscore::TdxPSExplorerItem* AnItem);
	
public:
	__fastcall TdxPSPreviewExplorerChangeNotifier(TdxPSPreviewWindow* APreview);
	__property TdxPSPreviewWindow* Preview = {read=FPreview};
public:
	/* TdxPSExplorerChangeNotifier.Destroy */ inline __fastcall virtual ~TdxPSPreviewExplorerChangeNotifier(void) { }
	
};


typedef void __fastcall (__closure *TdxPSPreviewWindowCustomHostOnSize)(System::TObject* Sender, int &AWidth, int &AHeight);

class DELPHICLASS TdxPSPreviewWindowCustomHost;
class PASCALIMPLEMENTATION TdxPSPreviewWindowCustomHost : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxPSPreviewWindowCustomHostOnSize FOnSizeChanging;
	
protected:
	virtual void __fastcall DoSizeChanging(int &AWidth, int &AHeight);
	virtual void __fastcall Paint(void);
	
public:
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property OnResize;
	__property TdxPSPreviewWindowCustomHostOnSize OnSizeChanging = {read=FOnSizeChanging, write=FOnSizeChanging};
public:
	/* TcxControl.Create */ inline __fastcall virtual TdxPSPreviewWindowCustomHost(System::Classes::TComponent* AOwner) : Cxcontrols::TcxControl(AOwner) { }
	/* TcxControl.Destroy */ inline __fastcall virtual ~TdxPSPreviewWindowCustomHost(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSPreviewWindowCustomHost(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TdxPSPreviewWindowLoadPropertiesEvent)(System::TObject* Sender, System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);

class DELPHICLASS TdxPSStatusBarPanel;
class DELPHICLASS TdxPSCustomStatusBar;
class PASCALIMPLEMENTATION TdxPSPreviewWindow : public Dxpscore::TdxPSCustomPreviewWindow
{
	typedef Dxpscore::TdxPSCustomPreviewWindow inherited;
	
private:
	Dxpsesys::TdxEventSubscriber* FBuildEventsSubscriber;
	int FCurrentProgressValue;
	Dxpscore::TdxPreviewEnableOptions FEnableOptions;
	int FFullPageCount;
	Dxprnpg::TdxPageTitlePart FHFEditPart;
	System::Classes::TStringList* FHFFunctionList;
	Dxpsesys::TdxEventSubscriber* FHFTextEntriesChangedSubscriber;
	int FLastOpCompleted;
	int FLastValidZoomFactor;
	bool FLockPageSelection;
	TdxPSPreviewWindowAddExplorerCommandEvent FOnAddExplorerCommand;
	TdxPSPreviewWindowAfterPrintReportEvent FOnAfterPrintReport;
	TdxPSPreviewWindowCanShowMarginHint FOnCanShowMarginHint;
	System::Classes::TNotifyEvent FOnCreationComplete;
	System::Classes::TNotifyEvent FOnHFTextEntriesChanged;
	TdxPSPreviewWindowHFToolBarShow FOnHFToolBarVisibleChanged;
	System::Classes::TNotifyEvent FOnInitContent;
	TdxPSPreviewWindowLoadPropertiesEvent FOnLoadProperties;
	System::Classes::TNotifyEvent FOnPreviewDblClick;
	TdxPSPreviewWindowLoadPropertiesEvent FOnSaveProperties;
	System::Classes::TNotifyEvent FOnStyleListChanged;
	System::Classes::TNotifyEvent FOnUpdateControls;
	System::Classes::TNotifyEvent FOnUpdateExplorerCommands;
	System::Classes::TNotifyEvent FOnZoomFactorChanged;
	System::Classes::TNotifyEvent FOnZoomModeChanged;
	System::Classes::TStringList* FPredefinedZooms;
	System::Classes::TComponent* FPreviewPopupMenu;
	Dxpsesys::TdxEventSubscriber* FPrintEventsSubscriber;
	Vcl::Comctrls::TProgressBar* FProgressBar;
	int FSaveExplorerPaneWidth;
	TdxPSExplorerVisibiltyState FSaveExplorerVisibility;
	TdxPSPageMarginsVisibilityState FSavePageMarginsVisibility;
	int FSaveThumbnailsPaneWidth;
	TdxPSThumbnailsVisibiltyState FSaveThumbnailsVisibility;
	bool FSaveZoomPosition;
	bool FShowExplorer;
	bool FShowMarginBar;
	bool FShowStatusBar;
	bool FShowThumbnails;
	Dxpscore::TdxPSPreviewState FState;
	Dxpsesys::TdxEventSubscriber* FStyleEventsSubscriber;
	Dxpscore::TdxPSThumbnailsSize FThumbnailsSize;
	int FUpdateCount;
	Dxpscore::TdxPreviewVisibleOptions FVisibleOptions;
	Dxpscore::TCustomdxPSExplorer* __fastcall GetExplorer(void);
	int __fastcall GetExplorerPaneWidth(void);
	bool __fastcall GetFlat(void);
	bool __fastcall GetIsExplorerAvailable(void);
	bool __fastcall GetIsExplorerMode(void);
	Dxprnpg::TdxPrinterPage* __fastcall GetPrinterPage(void);
	TdxPSStatusBarPanel* __fastcall GetProgressStatusPanel(void);
	bool __fastcall GetShowMarginBar(void);
	bool __fastcall GetShowPageMargins(void);
	bool __fastcall GetShowStatusBar(void);
	TdxPSStatusBarPanel* __fastcall GetStatusTextPanel(void);
	int __fastcall GetThumbnailsPaneWidth(void);
	bool __fastcall GetZoomOnClick(void);
	void __fastcall SetExplorerPaneWidth(int Value);
	void __fastcall SetPreviewPopupMenu(System::Classes::TComponent* AValue);
	void __fastcall SetShowMarginBar(bool Value);
	void __fastcall SetShowPageMargins(bool Value);
	void __fastcall SetShowStatusBar(bool Value);
	void __fastcall SetThumbnailsPaneWidth(int Value);
	void __fastcall SetZoomOnClick(bool AValue);
	Cxsplitter::TcxCustomSplitter* __fastcall CreateSplitter(Vcl::Controls::TAlign AAlign, const System::UnicodeString AName, int ALeft, Vcl::Controls::TWinControl* AParent, Vcl::Controls::TControl* AResizeControl, Cxsplitter::TCanResizeEvent OnCanResizeEvent);
	void __fastcall FillEffectsApply(System::TObject* Sender);
	void __fastcall ExplorerClose(System::TObject* Sender);
	void __fastcall ExplorerSplitterCanResize(System::TObject* Sender, int &NewSize, bool &Accept);
	void __fastcall ExplorerToolBarResize(System::TObject* Sender);
	void __fastcall MarginBarDblClick(System::TObject* Sender);
	void __fastcall MarginBarGetDrawParams(TdxPSCustomStatusBar* ASender, TdxPSStatusBarPanel* APanel, System::Uitypes::TColor &ABkgColor, System::Uitypes::TColor &ATextColor);
	void __fastcall PreviewAfterDragMargin(System::TObject* Sender, Dxprevw::TdxPreviewPageMargin* AMargin);
	void __fastcall PreviewBeforeDragMargin(System::TObject* Sender, Dxprevw::TdxPreviewPageMargin* AMargin);
	void __fastcall PreviewCalcPageCount(System::TObject* Sender);
	void __fastcall PreviewCanShowMarginHint(System::TObject* Sender, bool &ACanShowHint);
	void __fastcall PreviewDblClick(System::TObject* Sender);
	void __fastcall PreviewDragMargin(System::TObject* Sender, Dxprevw::TdxPreviewPageMargin* AMargin);
	void __fastcall PreviewMarginsChanged(System::TObject* Sender, Dxprevw::TdxPreviewPageMargin* AMargin);
	void __fastcall PreviewSelectedPageChanged(System::TObject* Sender, int APageIndex);
	void __fastcall PreviewZoomFactorChanged(System::TObject* Sender);
	void __fastcall PreviewZoomModeChanged(System::TObject* Sender);
	void __fastcall StatusBarDblClick(System::TObject* Sender);
	void __fastcall StatusBarMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ThumbnailsPreviewSelectedPageChanged(System::TObject* Sender, int APageIndex);
	void __fastcall ThumbnailsSplitterCanResize(System::TObject* Sender, int &NewSize, bool &Accept);
	void __fastcall EndGenerateReport(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink);
	void __fastcall GenerateReportProgress(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink, double APercentDone);
	void __fastcall StartGenerateReport(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink);
	void __fastcall EndPrint(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink);
	void __fastcall NewPage(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink, int APageIndex);
	void __fastcall StartPrint(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink, int FullPageCount);
	void __fastcall LoadZooms(void);
	void __fastcall UpdateMarginBar(void);
	void __fastcall UpdateStatusText(void);
	MESSAGE void __fastcall WMAppCommand(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMGetMinMaxInfo(Winapi::Messages::TWMGetMinMaxInfo &Message);
	MESSAGE void __fastcall WMSettingChange(Winapi::Messages::TWMSettingChange &Message);
	
protected:
	TdxPSPreviewExplorerChangeNotifier* FExplorerChangeNotifier;
	TdxPSExplorerCloseButton* FExplorerCloseButton;
	TdxPSPreviewWindowCustomHost* FExplorerPane;
	Cxsplitter::TcxCustomSplitter* FExplorerSplitter;
	TdxPSExplorerToolBar* FExplorerToolBar;
	Dxpscore::TCustomdxPSExplorerTreeContainer* FExplorerTree;
	TdxPSExplorerHostPanel* FExplorerTreeHost;
	TdxPSCustomStatusBar* FMarginBar;
	Dxprevw::TdxPreview* FPreview;
	TdxPSPreviewWindowCustomHost* FPreviewPane;
	TdxPSCustomStatusBar* FStatusBar;
	TdxPSPreviewWindowCustomHost* FThumbnailsPane;
	Dxprevw::TdxPreview* FThumbnailsPreview;
	Cxsplitter::TcxCustomSplitter* FThumbnailsSplitter;
	bool FAreMarginsValid;
	bool FReleased;
	int __fastcall CalculateStatusBarHeight(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &message);
	virtual int __fastcall GetActivePageIndex(void);
	virtual Dxbkgnd::TdxBackground* __fastcall GetBackground(void);
	virtual Dxpscore::TCustomdxPSExplorerTreeContainer* __fastcall GetExplorerTree(void);
	virtual Dxprnpg::TdxPageTitlePart __fastcall GetHFEditPart(void);
	virtual int __fastcall GetPageCount(void);
	virtual Dxpscore::TdxPreviewEnableOptions __fastcall GetPreviewEnableOptions(void);
	virtual Dxpscore::TdxPreviewVisibleOptions __fastcall GetPreviewVisibleOptions(void);
	virtual bool __fastcall GetSaveZoomPosition(void);
	virtual bool __fastcall GetShowExplorer(void);
	virtual bool __fastcall GetShowThumbnails(void);
	virtual Dxpscore::TdxPSPreviewState __fastcall GetState(void);
	virtual Dxpscore::TdxPSThumbnailsSize __fastcall GetThumbnailsSize(void);
	virtual System::Types::TPoint __fastcall GetVisiblePageSize(void);
	virtual int __fastcall GetZoomFactor(void);
	virtual void __fastcall SetActivePageIndex(int Value);
	virtual void __fastcall SetBackground(Dxbkgnd::TdxBackground* const Value);
	void __fastcall SetFocusToControl(Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall SetHFEditPart(const Dxprnpg::TdxPageTitlePart Value);
	virtual void __fastcall SetPageCount(int Value);
	virtual void __fastcall SetPreviewEnableOptions(const Dxpscore::TdxPreviewEnableOptions Value);
	virtual void __fastcall SetPreviewVisibleOptions(const Dxpscore::TdxPreviewVisibleOptions Value);
	virtual void __fastcall SetSaveZoomPosition(bool Value);
	virtual void __fastcall SetShowExplorer(bool Value);
	virtual void __fastcall SetShowThumbnails(bool Value);
	virtual void __fastcall SetState(const Dxpscore::TdxPSPreviewState Value);
	virtual void __fastcall SetThumbnailsSize(const Dxpscore::TdxPSThumbnailsSize Value);
	virtual void __fastcall SetZoomFactor(int Value);
	virtual void __fastcall AfterComponentPrinterChanged(void);
	virtual void __fastcall CreationComplete(void);
	void __fastcall InitializeControlLookAndFeel(Vcl::Controls::TControl* AControl);
	void __fastcall InitializePreviewWindowLayout(void);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall AddExplorerContextCommand(Dxpscore::TCustomdxPSExplorerContextCommand* ACommand);
	void __fastcall DoCreationComplete(void);
	virtual void __fastcall DoInitContent(void);
	void __fastcall DoUpdatePanesState(System::TObject* Sender);
	void __fastcall ExplorerPaneSizeChanging(System::TObject* Sender, int &AWidth, int &AHeight);
	void __fastcall ThumbnailsPreviewSizeChanging(System::TObject* Sender, int &AWidth, int &AHeight);
	void __fastcall UpdateThumbnailsSize(void);
	TdxPSStatusBarPanel* __fastcall MarginStatusPanel(Dxprevw::TdxPreviewPageMargin* AMargin);
	int __fastcall ProgressBarGetMaxValue(void);
	TdxPSStatusBarPanel* __fastcall SectionStatusPanel(TfmPreviewStatusSection AStatusSection);
	void __fastcall InvalidatePagesHeadersOrFooters(void);
	void __fastcall PrepareProgress(void);
	void __fastcall ProgressBarHide(void);
	void __fastcall ProgressBarPlace(void);
	void __fastcall ProgressBarRefresh(void);
	void __fastcall ProgressBarShow(void);
	void __fastcall RefreshMarginBar(Dxprevw::TdxPreviewPageMargin* AMargin);
	void __fastcall RefreshStatusBar(TfmPreviewStatusSections AStatusSections);
	void __fastcall SectionStatusPanelSetText(TfmPreviewStatusSection AStatusSection, const System::UnicodeString AText);
	void __fastcall UnprepareProgress(void);
	void __fastcall UpdateStatusBarPanelWidths(TdxPSCustomStatusBar* AStatusBar);
	void __fastcall LoadProperties(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SaveProperties(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SavePreferences(Dxpsprvwopt::TdxPreviewOptionsDlgData &AData);
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall CreateEventSubscribers(void);
	virtual void __fastcall CreateExplorerPane(void);
	virtual void __fastcall CreateExplorerSplitter(void);
	virtual void __fastcall CreateExplorerToolBar(void);
	virtual void __fastcall CreateExplorerTreeHost(void);
	virtual void __fastcall CreateMarginBar(void);
	virtual void __fastcall CreatePreview(void);
	virtual void __fastcall CreatePreviewPane(void);
	virtual void __fastcall CreateProgressBar(void);
	virtual void __fastcall CreateStatusBar(void);
	virtual void __fastcall CreateThumbnailsPane(void);
	virtual void __fastcall CreateThumbnailsPreview(void);
	virtual void __fastcall CreateThumbnailsSplitter(void);
	virtual void __fastcall RefreshStatusPanels(TdxPSPreviewWindowStatusBarMode AStatusBarMode);
	virtual void __fastcall DoAfterPrintReport(bool AShowDialog);
	void __fastcall DoLoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall DoPreviewAfterDragMargin(Dxprevw::TdxPreview* APreview, Dxprevw::TdxPreviewPageMargin* AMargin);
	virtual void __fastcall DoPreviewBeforeDragMargin(Dxprevw::TdxPreview* APreview, Dxprevw::TdxPreviewPageMargin* AMargin);
	virtual void __fastcall DoPreviewDblClick(Dxprevw::TdxPreview* APreview);
	virtual void __fastcall DoPreviewDragMargin(Dxprevw::TdxPreview* APreview, Dxprevw::TdxPreviewPageMargin* AMargin);
	virtual void __fastcall DoPreviewMarginChanged(Dxprevw::TdxPreview* APreview, Dxprevw::TdxPreviewPageMargin* AMargin);
	void __fastcall DoSaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall DoUpdateControls(void);
	virtual void __fastcall HFTextEntriesChanged(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall StyleListChanged(System::TObject* Sender);
	virtual bool __fastcall ValidateMargins(void);
	bool __fastcall IdxPSExplorerTreeContainerHost_GetFlat(void);
	Dxpscore::TBasedxReportLink* __fastcall IdxPSExplorerTreeContainerHost_GetReportLink(void);
	Vcl::Controls::TWinControl* __fastcall GetTreeContainerParent(void);
	void __fastcall UpdateState(void);
	
public:
	__fastcall virtual TdxPSPreviewWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPSPreviewWindow(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall GoToFirstPage(void);
	virtual void __fastcall GoToLastPage(void);
	virtual void __fastcall GoToNextPage(void);
	virtual void __fastcall GoToPrevPage(void);
	virtual void __fastcall InitContent(void);
	virtual void __fastcall InvalidateAllPages(void);
	virtual void __fastcall InvalidateContent(void);
	virtual void __fastcall InvalidatePage(int APageIndex);
	virtual void __fastcall InvalidatePagesContent(void);
	virtual void __fastcall InvalidatePagesFooterContent(void);
	virtual void __fastcall InvalidatePagesHeaderContent(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName)/* overload */;
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName)/* overload */;
	virtual void __fastcall UpdateControls(void);
	void __fastcall UpdateControlsPosition(void);
	virtual void __fastcall UpdateExplorerContextCommands(void);
	bool __fastcall CanChangeMargins(void);
	virtual bool __fastcall CanClosePreviewWindow(void);
	bool __fastcall CanDesign(void);
	bool __fastcall CanExport(void);
	bool __fastcall CanLoadReport(void);
	bool __fastcall CanPageSetup(void);
	bool __fastcall CanPrint(void);
	bool __fastcall CanPrintDialog(void);
	bool __fastcall CanPrintStyle(void);
	bool __fastcall CanRebuild(void);
	bool __fastcall CanSaveReport(void);
	bool __fastcall CanUnloadReport(void);
	bool __fastcall IsAutoHFTextEntriesAvailable(void);
	bool __fastcall IsBuilding(void);
	bool __fastcall IsCommandLoadReportVisible(void);
	bool __fastcall IsCommandSaveReportVisible(void);
	bool __fastcall IsCommandUnloadReportVisible(void);
	bool __fastcall IsEnabled(Dxpscore::TdxPreviewEnableOption AnOption);
	bool __fastcall IsMarginValueStatusPanel(TdxPSStatusBarPanel* APanel);
	bool __fastcall IsPrinting(void);
	bool __fastcall IsProgressState(void);
	bool __fastcall IsStatusTextPanel(TdxPSStatusBarPanel* APanel);
	bool __fastcall IsVisible(Dxpscore::TdxPreviewVisibleOption AnOption);
	void __fastcall DoActivePageChanged(int AValue);
	void __fastcall DoClearHF(void);
	void __fastcall DoDesignReport(void);
	void __fastcall DoExplorerButtonsPosUpdate(void);
	void __fastcall DoExplorerCreateNewFolder(void);
	void __fastcall DoExplorerCreateNewItem(void);
	void __fastcall DoExplorerDeleteItem(void);
	bool __fastcall DoExplorerItemShowPropertySheets(void);
	void __fastcall DoExplorerLoadItemData(void);
	void __fastcall DoExplorerShowToggled(bool Value);
	void __fastcall DoExplorerRenameItem(void);
	void __fastcall DoExplorerUnloadItemData(void);
	void __fastcall DoFormatFootnotes(void);
	void __fastcall DoFormatTitle(void);
	void __fastcall DoInsertHF(const System::UnicodeString S);
	void __fastcall DoInvokeHelp(void);
	void __fastcall DoLoadReportLinkDataFromFile(void);
	void __fastcall DoPageSetupReport(int APageIndex);
	void __fastcall DoPrintReport(bool AShowDialog);
	void __fastcall DoSaveReportLinkDataToFile(void);
	void __fastcall DoSetupZoomFactor(int AZoomFactor, int APageXCount, int APageYCount, Dxprevw::TdxPreviewZoomMode AZoomMode);
	void __fastcall DoShowFormatDateTimeDlg(void);
	void __fastcall DoShowFormatPageNumbersDlg(void);
	void __fastcall DoShowHFBackgroundDlg(const System::Types::TPoint Pt);
	virtual void __fastcall DoShowHFToolBar(bool Value);
	void __fastcall DoShowMultiplySelectPagesDlg(Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, const System::Types::TPoint Pt, int AYShift);
	void __fastcall DoShowOptionsDlg(void);
	void __fastcall DoShowPageBackgroundDlg(const System::Types::TPoint Pt);
	void __fastcall DoShowPageFooters(bool Value);
	void __fastcall DoShowPageHeaders(bool Value);
	void __fastcall DoShowZoomDlg(void);
	void __fastcall DoShrinkToPageWidth(bool Value);
	void __fastcall DoSyncPrintingPageBackground(void);
	void __fastcall DoThumbnailsToggleShow(bool Value);
	void __fastcall DoUnloadReportLinkData(void);
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall CancelUpdate(void);
	virtual void __fastcall EndUpdate(void);
	virtual bool __fastcall Locked(void);
	virtual void __fastcall FullRefresh(void);
	void __fastcall SetZoomFactorByText(const System::UnicodeString AText);
	__property Dxpscore::TCustomdxPSExplorer* Explorer = {read=GetExplorer};
	__property TdxPSExplorerCloseButton* ExplorerCloseButton = {read=FExplorerCloseButton};
	__property TdxPSPreviewWindowCustomHost* ExplorerPane = {read=FExplorerPane};
	__property int ExplorerPaneWidth = {read=GetExplorerPaneWidth, write=SetExplorerPaneWidth, nodefault};
	__property Cxsplitter::TcxCustomSplitter* ExplorerSplitter = {read=FExplorerSplitter};
	__property TdxPSExplorerToolBar* ExplorerToolBar = {read=FExplorerToolBar};
	__property TdxPSExplorerHostPanel* ExplorerTreeHost = {read=FExplorerTreeHost};
	__property bool Flat = {read=GetFlat, nodefault};
	__property System::Classes::TStringList* HFFunctionList = {read=FHFFunctionList};
	__property bool IsExplorerAvailable = {read=GetIsExplorerAvailable, nodefault};
	__property bool IsExplorerMode = {read=GetIsExplorerMode, nodefault};
	__property LookAndFeel;
	__property TdxPSCustomStatusBar* MarginBar = {read=FMarginBar};
	__property System::Classes::TStringList* PredefinedZooms = {read=FPredefinedZooms};
	__property Dxprevw::TdxPreview* Preview = {read=FPreview};
	__property TdxPSPreviewWindowCustomHost* PreviewPane = {read=FPreviewPane};
	__property Dxprnpg::TdxPrinterPage* PrinterPage = {read=GetPrinterPage};
	__property Vcl::Comctrls::TProgressBar* ProgressBar = {read=FProgressBar};
	__property TdxPSStatusBarPanel* ProgressStatusPanel = {read=GetProgressStatusPanel};
	__property bool ShowMarginBar = {read=GetShowMarginBar, write=SetShowMarginBar, nodefault};
	__property bool ShowPageMargins = {read=GetShowPageMargins, write=SetShowPageMargins, nodefault};
	__property bool ShowStatusBar = {read=GetShowStatusBar, write=SetShowStatusBar, nodefault};
	__property TdxPSCustomStatusBar* StatusBar = {read=FStatusBar};
	__property TdxPSStatusBarPanel* StatusTextPanel = {read=GetStatusTextPanel};
	__property TdxPSPreviewWindowCustomHost* ThumbnailsPane = {read=FThumbnailsPane};
	__property int ThumbnailsPaneWidth = {read=GetThumbnailsPaneWidth, write=SetThumbnailsPaneWidth, nodefault};
	__property Dxprevw::TdxPreview* ThumbnailsPreview = {read=FThumbnailsPreview};
	__property Cxsplitter::TcxCustomSplitter* ThumbnailsSplitter = {read=FThumbnailsSplitter};
	__property bool ZoomOnClick = {read=GetZoomOnClick, write=SetZoomOnClick, nodefault};
	
__published:
	__property Align = {default=0};
	__property TdxPSPreviewWindowAddExplorerCommandEvent OnAddExplorerCommand = {read=FOnAddExplorerCommand, write=FOnAddExplorerCommand};
	__property TdxPSPreviewWindowAfterPrintReportEvent OnAfterPrintReport = {read=FOnAfterPrintReport, write=FOnAfterPrintReport};
	__property TdxPSPreviewWindowCanShowMarginHint OnCanShowMarginHint = {read=FOnCanShowMarginHint, write=FOnCanShowMarginHint};
	__property System::Classes::TNotifyEvent OnCreationComplete = {read=FOnCreationComplete, write=FOnCreationComplete};
	__property System::Classes::TNotifyEvent OnHFTextEntriesChanged = {read=FOnHFTextEntriesChanged, write=FOnHFTextEntriesChanged};
	__property TdxPSPreviewWindowHFToolBarShow OnHFToolBarVisibleChanged = {read=FOnHFToolBarVisibleChanged, write=FOnHFToolBarVisibleChanged};
	__property System::Classes::TNotifyEvent OnInitContent = {read=FOnInitContent, write=FOnInitContent};
	__property TdxPSPreviewWindowLoadPropertiesEvent OnLoadProperties = {read=FOnLoadProperties, write=FOnLoadProperties};
	__property System::Classes::TNotifyEvent OnPreviewDblClick = {read=FOnPreviewDblClick, write=FOnPreviewDblClick};
	__property TdxPSPreviewWindowLoadPropertiesEvent OnSaveProperties = {read=FOnSaveProperties, write=FOnSaveProperties};
	__property System::Classes::TNotifyEvent OnStyleListChanged = {read=FOnStyleListChanged, write=FOnStyleListChanged};
	__property System::Classes::TNotifyEvent OnUpdateControls = {read=FOnUpdateControls, write=FOnUpdateControls};
	__property System::Classes::TNotifyEvent OnUpdateExplorerCommands = {read=FOnUpdateExplorerCommands, write=FOnUpdateExplorerCommands};
	__property System::Classes::TNotifyEvent OnZoomFactorChanged = {read=FOnZoomFactorChanged, write=FOnZoomFactorChanged};
	__property System::Classes::TNotifyEvent OnZoomModeChanged = {read=FOnZoomModeChanged, write=FOnZoomModeChanged};
	__property System::Classes::TComponent* PreviewPopupMenu = {read=FPreviewPopupMenu, write=SetPreviewPopupMenu};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSPreviewWindow(HWND ParentWindow) : Dxpscore::TdxPSCustomPreviewWindow(ParentWindow) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  LoadFromIniFile(const System::UnicodeString AFileName){ Dxpscore::TdxPSCustomPreviewWindow::LoadFromIniFile(AFileName); }
	inline void __fastcall  SaveToIniFile(const System::UnicodeString AFileName){ Dxpscore::TdxPSCustomPreviewWindow::SaveToIniFile(AFileName); }
	
private:
	void *__IdxPSExplorerTreeContainerHost;	/* Dxpscore::IdxPSExplorerTreeContainerHost */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E52E062-EDCF-4A58-8212-45EAE673F506}
	operator Dxpscore::_di_IdxPSExplorerTreeContainerHost()
	{
		Dxpscore::_di_IdxPSExplorerTreeContainerHost intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscore::IdxPSExplorerTreeContainerHost*(void) { return (Dxpscore::IdxPSExplorerTreeContainerHost*)&__IdxPSExplorerTreeContainerHost; }
	#endif
	
};


class DELPHICLASS TdxPSStatusBarViewInfo;
class PASCALIMPLEMENTATION TdxPSStatusBarViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TRect BorderWidths;
	System::Types::TRect Bounds;
	int SeparatorSize;
	System::Types::TSize SizeGripSize;
	int TextIndent;
public:
	/* TObject.Create */ inline __fastcall TdxPSStatusBarViewInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSStatusBarViewInfo(void) { }
	
};


enum TdxPSStatusBarPanelStyle : unsigned char { sbpsPanel, sbpsSeparator };

class PASCALIMPLEMENTATION TdxPSStatusBarPanel : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	System::Types::TRect FBounds;
	bool FShowBorders;
	TdxPSStatusBarPanelStyle FStyle;
	System::UnicodeString FText;
	System::Types::TRect FTextRect;
	int FWidth;
	void __fastcall SetAlignment(System::Classes::TAlignment AValue);
	void __fastcall SetShowBorders(bool AValue);
	void __fastcall SetStyle(TdxPSStatusBarPanelStyle AStyle);
	void __fastcall SetText(const System::UnicodeString AText);
	void __fastcall SetWidth(int AValue);
	
protected:
	virtual void __fastcall Calculate(TdxPSStatusBarViewInfo* AViewInfo);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::Types::TRect TextRect = {read=FTextRect};
	
public:
	__fastcall virtual TdxPSStatusBarPanel(System::Classes::TCollection* Collection);
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property bool ShowBorders = {read=FShowBorders, write=SetShowBorders, nodefault};
	__property TdxPSStatusBarPanelStyle Style = {read=FStyle, write=SetStyle, nodefault};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxPSStatusBarPanel(void) { }
	
};


class DELPHICLASS TdxPSStatusBarPanels;
class PASCALIMPLEMENTATION TdxPSStatusBarPanels : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxPSStatusBarPanel* operator[](int Index) { return Items[Index]; }
	
private:
	TdxPSCustomStatusBar* FStatusBar;
	HIDESBASE TdxPSStatusBarPanel* __fastcall GetItem(int Index);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TdxPSStatusBarPanels(TdxPSCustomStatusBar* AStatusBar);
	HIDESBASE TdxPSStatusBarPanel* __fastcall Add(void);
	TdxPSStatusBarPanel* __fastcall First(void);
	TdxPSStatusBarPanel* __fastcall Last(void);
	__property TdxPSStatusBarPanel* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxPSCustomStatusBar* StatusBar = {read=FStatusBar};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxPSStatusBarPanels(void) { }
	
};


typedef void __fastcall (__closure *TdxPSStatusBarPanelGetDrawParamsEvent)(TdxPSCustomStatusBar* ASender, TdxPSStatusBarPanel* APanel, System::Uitypes::TColor &ABkgColor, System::Uitypes::TColor &ATextColor);

class PASCALIMPLEMENTATION TdxPSCustomStatusBar : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxPSStatusBarPanelGetDrawParamsEvent FOnPanelGetDrawParams;
	TdxPSStatusBarPanels* FPanels;
	bool FSizeGrip;
	System::Types::TRect FSizeGripRect;
	int FUpdateCount;
	System::Types::TRect __fastcall GetContentRect(void);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	void __fastcall SetSizeGrip(bool AValue);
	
protected:
	bool __fastcall CanShowSizeGrip(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateSizeGripBounds(TdxPSStatusBarViewInfo* AViewInfo);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual TdxPSStatusBarViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall DoGetPanelDrawParams(TdxPSStatusBarPanel* APanel, System::Uitypes::TColor &ABkgColor, System::Uitypes::TColor &ATextColor);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawItem(Cxgraphics::TcxCanvas* ACanvas, TdxPSStatusBarPanel* APanel);
	virtual void __fastcall DrawPanelItem(Cxgraphics::TcxCanvas* ACanvas, TdxPSStatusBarPanel* APanel);
	virtual void __fastcall DrawPanelItemText(Cxgraphics::TcxCanvas* ACanvas, TdxPSStatusBarPanel* APanel, System::Uitypes::TColor ATextColor);
	virtual void __fastcall DrawSepartorItem(Cxgraphics::TcxCanvas* ACanvas, TdxPSStatusBarPanel* APanel);
	virtual void __fastcall DrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Recalculate(void);
	void __fastcall UpdateStateChanged(bool AUnlocked);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	__property System::Types::TRect ContentRect = {read=GetContentRect};
	__property System::Types::TRect SizeGripRect = {read=FSizeGripRect};
	
public:
	__fastcall virtual TdxPSCustomStatusBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPSCustomStatusBar(void);
	virtual bool __fastcall PanelFromPoint(System::Types::TPoint APoint, TdxPSStatusBarPanel* &APanel);
	virtual System::Types::TRect __fastcall PanelRect(int AIndex);
	virtual void __fastcall InvalidatePanel(int AIndex);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TdxPSStatusBarPanelGetDrawParamsEvent OnPanelGetDrawParams = {read=FOnPanelGetDrawParams, write=FOnPanelGetDrawParams};
	__property TdxPSStatusBarPanels* Panels = {read=FPanels};
	__property bool SizeGrip = {read=FSizeGrip, write=SetSizeGrip, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSCustomStatusBar(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TdxPSStatusBar;
class PASCALIMPLEMENTATION TdxPSStatusBar : public TdxPSCustomStatusBar
{
	typedef TdxPSCustomStatusBar inherited;
	
__published:
	__property OnPanelGetDrawParams;
	__property Panels;
	__property SizeGrip;
public:
	/* TdxPSCustomStatusBar.Create */ inline __fastcall virtual TdxPSStatusBar(System::Classes::TComponent* AOwner) : TdxPSCustomStatusBar(AOwner) { }
	/* TdxPSCustomStatusBar.Destroy */ inline __fastcall virtual ~TdxPSStatusBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSStatusBar(HWND ParentWindow) : TdxPSCustomStatusBar(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define sdxExplorerCloseButton L"ExplorerCloseButton"
#define sdxExplorerPane L"ExplorerPane"
#define sdxExplorerSplitter L"ExplorerSplitter"
#define sdxExplorerToolBar L"ExplorerToolBar"
#define sdxExplorerTreeHost L"ExplorerTreeHost"
#define sdxMarginBar L"MarginBar"
#define sdxPreviewControl L"PreviewControl"
#define sdxPreviewPane L"PreviewPane"
#define sdxProgressBar L"ProgressBar"
#define sdxStatusBar L"StatusBar"
#define sdxThumbnailsPane L"ThumbnailsPane"
#define sdxThumbnailsPreviewControl L"ThumbnailsPreview"
#define sdxThumbnailsSplitter L"ThumbnailsSplitter"
extern PACKAGE System::UnicodeString __fastcall GetCurrentPrinterAsHint(void);
extern PACKAGE TdxPSStatusBarPanel* __fastcall AddStatusPanel(TdxPSCustomStatusBar* AStatusBar, System::Classes::TAlignment AAlignment, bool AShowBorder, const System::UnicodeString AText, int AWidth, TdxPSStatusBarPanelStyle AStyle = (TdxPSStatusBarPanelStyle)(0x0));
}	/* namespace Dxpsprvw */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPRVW)
using namespace Dxpsprvw;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsprvwHPP
