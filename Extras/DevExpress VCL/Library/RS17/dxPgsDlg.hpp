// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPgsDlg.pas' rev: 24.00 (Win32)

#ifndef DxpgsdlgHPP
#define DxpgsdlgHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <dxPreVw.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxfmClr.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPrnDev.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <dxPSHFToolBarBld.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpgsdlg
{
//-- type declarations -------------------------------------------------------
enum TdxPageSetupDlgButtonKind : unsigned char { psbHelp, psbStyleOptions, psbPreview, psbPrint };

typedef System::Set<TdxPageSetupDlgButtonKind, TdxPageSetupDlgButtonKind::psbHelp, TdxPageSetupDlgButtonKind::psbPrint>  TdxPageSetupDlgButtons;

enum TdxPageSetupDlgOption : unsigned char { psoCenterOnPage, psoMargins, psoPageOrder, psoShading, psoStyleCaption, psoHFAutoText, psoHFBackground, psoHFFont, psoHFText, psoHFFunctions, psoHFMargins, psoHFReverse, psoHFVertAlignment };

typedef System::Set<TdxPageSetupDlgOption, TdxPageSetupDlgOption::psoCenterOnPage, TdxPageSetupDlgOption::psoHFVertAlignment>  TdxPageSetupDlgOptions;

enum TdxHFMode : unsigned char { hfmThreeSections, hfmOneSection };

typedef System::TMetaClass* TdxPrintStyleClass;

typedef System::TMetaClass* TdxPrintStylePrinterPageClass;

class DELPHICLASS TdxPrintStylePrinterPage;
class DELPHICLASS TBasedxPrintStyle;
class PASCALIMPLEMENTATION TdxPrintStylePrinterPage : public Dxprnpg::TdxPrinterPage
{
	typedef Dxprnpg::TdxPrinterPage inherited;
	
private:
	TBasedxPrintStyle* FPrintStyle;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual bool __fastcall IsPageFooterTitleStored(int Index);
	virtual bool __fastcall IsPageHeaderTitleStored(int Index);
	virtual void __fastcall PageParamsChanged(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	
public:
	__property TBasedxPrintStyle* PrintStyle = {read=FPrintStyle};
protected:
	/* TdxPrinterPage.CreateInstance */ inline __fastcall TdxPrintStylePrinterPage(int Dummy) : Dxprnpg::TdxPrinterPage(Dummy) { }
	
public:
	/* TdxPrinterPage.Create */ inline __fastcall virtual TdxPrintStylePrinterPage(void) : Dxprnpg::TdxPrinterPage() { }
	/* TdxPrinterPage.Destroy */ inline __fastcall virtual ~TdxPrintStylePrinterPage(void) { }
	
};


enum TdxPrintStyleState : unsigned char { pssCopy, pssOptionsDialog };

typedef System::Set<TdxPrintStyleState, TdxPrintStyleState::pssCopy, TdxPrintStyleState::pssOptionsDialog>  TdxPrintStyleStates;

typedef void __fastcall (__closure *TdxPageParamsChangedEvent)(Dxprnpg::TdxPrinterPage* Sender, TBasedxPrintStyle* APrintStyle, Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);

typedef void __fastcall (__closure *TdxFilterPaperEvent)(TBasedxPrintStyle* Sender, Dxprndev::TdxPaperInfo* const APaper, bool &AIsSupported);

class DELPHICLASS TdxPrintStyleManager;
class PASCALIMPLEMENTATION TBasedxPrintStyle : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FAllowChangeHFText;
	bool FAllowChangeMargins;
	bool FAllowChangeOrientation;
	bool FAllowChangePaper;
	bool FAllowChangeScale;
	bool FAllowCustomPaperSizes;
	bool FBuiltIn;
	void *FData;
	Vcl::Graphics::TBitmap* FDefaultStyleGlyph;
	System::UnicodeString FDescription;
	int FImageIndex;
	bool FIsDescriptionAssigned;
	bool FIsStyleCaptionAssigned;
	bool FIsStyleGlyphAssigned;
	Dxprnpg::TdxPrinterPage* FPrinterPage;
	bool FShowPageSetupDlg;
	TdxPrintStyleStates FState;
	System::UnicodeString FStyleCaption;
	Vcl::Graphics::TBitmap* FStyleGlyph;
	TdxPrintStyleManager* FStyleManager;
	System::Classes::TNotifyEvent FOnDestroy;
	TdxFilterPaperEvent FOnFilterPaper;
	System::UnicodeString __fastcall GetDescription(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsCurrentStyle(void);
	System::UnicodeString __fastcall GetStyleCaption(void);
	Vcl::Graphics::TBitmap* __fastcall GetStyleGlyph(void);
	bool __fastcall IsDescriptionStored(void);
	bool __fastcall IsStyleCaptionStored(void);
	bool __fastcall IsStyleGlyphStored(void);
	void __fastcall SetBuiltIn(bool Value);
	void __fastcall SetDescription(const System::UnicodeString Value);
	void __fastcall SetImageIndex(int Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetIsCurrentStyle(bool Value);
	void __fastcall SetPrinterPage(Dxprnpg::TdxPrinterPage* Value);
	void __fastcall SetStyleCaption(const System::UnicodeString Value);
	void __fastcall SetStyleGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetStyleManager(TdxPrintStyleManager* Value);
	void __fastcall DesignerModified(void);
	void __fastcall DesignerUpdate(bool TheAll);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsLoading(void);
	void __fastcall ReadData(System::Classes::TReader* Reader);
	void __fastcall ReadIsDescriptionAssigned(System::Classes::TReader* Reader);
	void __fastcall ReadIsStyleCaptionAssigned(System::Classes::TReader* Reader);
	void __fastcall ReadIsStyleGlyphAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteData(System::Classes::TWriter* Writer);
	void __fastcall WriteIsDescriptionAssigned(System::Classes::TWriter* Writer);
	void __fastcall WriteIsStyleCaptionAssigned(System::Classes::TWriter* Writer);
	void __fastcall WriteIsStyleGlyphAssigned(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* AParent);
	virtual bool __fastcall GetAllowChangeHFText(void);
	virtual bool __fastcall GetAllowChangeMargins(void);
	virtual bool __fastcall GetAllowChangeOrientation(void);
	virtual bool __fastcall GetAllowChangePaper(void);
	virtual bool __fastcall GetAllowChangeScale(void);
	virtual bool __fastcall GetAllowCustomPaperSizes(void);
	virtual void __fastcall SetAllowChangeHFText(bool Value);
	virtual void __fastcall SetAllowChangeMargins(bool Value);
	virtual void __fastcall SetAllowChangeOrientation(bool Value);
	virtual void __fastcall SetAllowChangePaper(bool Value);
	virtual void __fastcall SetAllowChangeScale(bool Value);
	virtual void __fastcall SetAllowCustomPaperSizes(bool Value);
	virtual Dxprnpg::TdxPrinterPage* __fastcall CreatePrinterPage(void);
	virtual Dxprnpg::TdxPrinterPageClass __fastcall GetPrinterPageClass(void);
	virtual void __fastcall InitializePrinterPage(Dxprnpg::TdxPrinterPage* APrinterPage);
	DYNAMIC void __fastcall DoAfterPrinting(void);
	DYNAMIC void __fastcall DoBeforePrinting(void);
	DYNAMIC void __fastcall DoDestroy(void);
	DYNAMIC bool __fastcall IsSupportedPaper(Dxprndev::TdxPaperInfo* const APaper);
	DYNAMIC void __fastcall PageParamsChanged(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual void __fastcall InitializeDefaultStyleGlyph(Vcl::Graphics::TBitmap* ABitmap);
	virtual void __fastcall StyleGlyphChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TBasedxPrintStyle(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TBasedxPrintStyle(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	__classmethod TdxPrintStyleClass __fastcall StyleClass();
	virtual System::UnicodeString __fastcall DefaultDescription(void);
	virtual System::UnicodeString __fastcall DefaultPageFooterText(Dxprnpg::TdxPageTitlePart APart);
	virtual System::UnicodeString __fastcall DefaultPageHeaderText(Dxprnpg::TdxPageTitlePart APart);
	virtual System::UnicodeString __fastcall DefaultStyleCaption(void);
	virtual Vcl::Graphics::TBitmap* __fastcall DefaultStyleGlyph(void);
	void __fastcall AfterPrinting(void);
	void __fastcall BeforePrinting(void);
	void __fastcall GetFilteredPapers(System::Classes::TStrings* AStrings);
	bool __fastcall PageSetup(void)/* overload */;
	bool __fastcall PageSetup(int AnActivePageIndex, bool AShowPreviewBtn, bool AShowPrintBtn, /* out */ bool &APreviewBtnClicked, /* out */ bool &APrintBtnClicked)/* overload */;
	virtual bool __fastcall ShowStyleOptionsDlg(void);
	virtual bool __fastcall HasStyleOptionsDlg(void);
	virtual void __fastcall RestoreDefaultGlyph(void);
	virtual void __fastcall RestoreDefaults(void);
	__property bool BuiltIn = {read=FBuiltIn, write=SetBuiltIn, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property bool IsStyleGlyphAssigned = {read=FIsStyleGlyphAssigned, nodefault};
	__property TdxPrintStyleStates State = {read=FState, nodefault};
	__property TdxPrintStyleManager* StyleManager = {read=FStyleManager, write=SetStyleManager};
	
__published:
	__property bool AllowChangeHFText = {read=GetAllowChangeHFText, write=SetAllowChangeHFText, default=1};
	__property bool AllowChangeMargins = {read=GetAllowChangeMargins, write=SetAllowChangeMargins, default=1};
	__property bool AllowChangeOrientation = {read=GetAllowChangeOrientation, write=SetAllowChangeOrientation, default=1};
	__property bool AllowChangePaper = {read=GetAllowChangePaper, write=SetAllowChangePaper, default=1};
	__property bool AllowChangeScale = {read=GetAllowChangeScale, write=SetAllowChangeScale, default=1};
	__property bool AllowCustomPaperSizes = {read=GetAllowCustomPaperSizes, write=SetAllowCustomPaperSizes, default=1};
	__property System::UnicodeString Description = {read=GetDescription, write=SetDescription, stored=IsDescriptionStored};
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property int Index = {read=GetIndex, write=SetIndex, stored=false, nodefault};
	__property bool IsCurrentStyle = {read=GetIsCurrentStyle, write=SetIsCurrentStyle, stored=false, nodefault};
	__property Dxprnpg::TdxPrinterPage* PrinterPage = {read=FPrinterPage, write=SetPrinterPage};
	__property bool ShowPageSetupDlg = {read=FShowPageSetupDlg, write=FShowPageSetupDlg, stored=false, nodefault};
	__property System::UnicodeString StyleCaption = {read=GetStyleCaption, write=SetStyleCaption, stored=IsStyleCaptionStored};
	__property Vcl::Graphics::TBitmap* StyleGlyph = {read=GetStyleGlyph, write=SetStyleGlyph, stored=IsStyleGlyphStored};
	__property System::Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property TdxFilterPaperEvent OnFilterPaper = {read=FOnFilterPaper, write=FOnFilterPaper};
};


class DELPHICLASS TAbstractdxStyleManagerDesigner;
class DELPHICLASS TdxPageSetupDialog;
class PASCALIMPLEMENTATION TdxPrintStyleManager : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
public:
	TBasedxPrintStyle* operator[](int Index) { return Styles[Index]; }
	
private:
	bool FAlreadySaved;
	System::Classes::TStrings* FAutoHFTextEntries;
	bool FAutoSave;
	System::UnicodeString FCloneStyleCaptionPrefix;
	TBasedxPrintStyle* FCurrentStyle;
	TAbstractdxStyleManagerDesigner* FDesigner;
	System::Classes::THelpContext FHelpContext;
	Vcl::Controls::TImageList* FImages;
	bool FInternalStreaming;
	bool FIsCloneStyleCaptionPrefixAssigned;
	bool FIsTitleAssigned;
	System::Classes::TStringList* FLoadedExistingStyles;
	TdxPageSetupDialog* FPageSetupDialog;
	bool FPreviewBtnClicked;
	bool FPrintBtnClicked;
	System::UnicodeString FStorageName;
	System::Classes::TList* FStyles;
	System::UnicodeString FTitle;
	int FVersion;
	int FUpdateCount;
	HWND FWindowHandle;
	System::Classes::TNotifyEvent FOnChangeCurrentStyle;
	System::Classes::TNotifyEvent FOnStyleListChanged;
	System::UnicodeString __fastcall GetCloneStyleCaptionPrefix(void);
	int __fastcall GetCount(void);
	int __fastcall GetCurrentStyleIndex(void);
	System::UnicodeString __fastcall GetRegistryPath(void);
	TBasedxPrintStyle* __fastcall GetStyle(int Index);
	System::UnicodeString __fastcall GetTitle(void);
	bool __fastcall IsAutoHFTextEntriesStored(void);
	bool __fastcall IsCloneStyleCaptionPrefixStored(void);
	bool __fastcall IsTitleStored(void);
	void __fastcall SetAutoHFTextEntries(System::Classes::TStrings* Value);
	void __fastcall SetCloneStyleCaptionPrefix(const System::UnicodeString Value);
	void __fastcall SetCurrentStyle(TBasedxPrintStyle* Value);
	void __fastcall SetCurrentStyleIndex(int Value);
	void __fastcall SetImages(Vcl::Controls::TImageList* Value);
	void __fastcall SetNewStyleCaption(TBasedxPrintStyle* AStyle, int AIndex);
	void __fastcall SetPageSetupDialog(TdxPageSetupDialog* Value);
	void __fastcall SetStyle(int Index, TBasedxPrintStyle* Value);
	void __fastcall SetTitle(const System::UnicodeString Value);
	bool __fastcall AllowAutoSave(void);
	void __fastcall DesignerModified(void);
	void __fastcall DesignerUpdate(TBasedxPrintStyle* AStyle);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	void __fastcall FreeAndNilStyles(void);
	void __fastcall InsertStyle(TBasedxPrintStyle* Value);
	void __fastcall MoveStyle(int ACurIndex, int ANewIndex);
	void __fastcall RemoveStyle(TBasedxPrintStyle* Value);
	void __fastcall ResyncCurrentStyle(int AIndex);
	void __fastcall AutoHFTextEntriesChanged(System::TObject* Sender);
	void __fastcall OnAutoHFTextEntryClick(System::TObject* Sender);
	void __fastcall OnEditAutoHFTextEntriesClick(System::TObject* Sender);
	void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall SetNameHandler(System::Classes::TReader* Reader, System::Classes::TComponent* Component, System::UnicodeString &Name);
	void __fastcall ReadIsCloneStyleCaptionPrefixAssigned(System::Classes::TReader* Reader);
	void __fastcall ReadIsTitleAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteIsCloneStyleCaptionPrefixAssigned(System::Classes::TWriter* Writer);
	void __fastcall WriteIsTitleAssigned(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	virtual System::Classes::TStrings* __fastcall CreateAutoHFTextEntries(void);
	virtual void __fastcall DoRestoreDefaults(void);
	DYNAMIC void __fastcall ChangeCurrentStyle(void);
	DYNAMIC void __fastcall PageParamsChanged(TBasedxPrintStyle* APrintStyle, Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	DYNAMIC void __fastcall StyleListChanged(void);
	__property System::UnicodeString RegistryPath = {read=GetRegistryPath};
	
public:
	__fastcall virtual TdxPrintStyleManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPrintStyleManager(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TBasedxPrintStyle* __fastcall AddStyle(TdxPrintStyleClass AStyleClass);
	TBasedxPrintStyle* __fastcall AddStyleEx(TdxPrintStyleClass AStyleClass, System::Classes::TComponent* AOwner);
	void __fastcall AssignStyles(TdxPrintStyleManager* Source);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall DeleteNonBuiltIns(void);
	int __fastcall IndexOfStyle(TBasedxPrintStyle* Value);
	bool __fastcall NonBuiltInsExists(void);
	TBasedxPrintStyle* __fastcall StyleByCaption(const System::UnicodeString ACaption);
	TBasedxPrintStyle* __fastcall StyleByName(const System::UnicodeString AName);
	TBasedxPrintStyle* __fastcall BeginClone(int AIndex);
	void __fastcall EndClone(TBasedxPrintStyle* AStyle);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual System::UnicodeString __fastcall DefaultCloneStyleCaptionPrefix(void);
	virtual System::UnicodeString __fastcall DefaultTitle(void);
	void __fastcall BuildAutoHFTextEntriesMenu(System::Classes::TComponent* ARootItem, void * AData, bool AIncludeSetupAutoHFTextEntriesItem = true);
	void __fastcall RefreshAutoHFTextEntries(void);
	bool __fastcall ShowAutoHFTextEntriesDlg(void);
	void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall LoadFromRegistry(const System::UnicodeString APath);
	void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SaveToRegistry(const System::UnicodeString APath);
	void __fastcall DefinePrintStylesDlg(/* out */ bool &APreviewBtnClicked, /* out */ bool &APrintBtnClicked)/* overload */;
	void __fastcall RestoreDefaultAutoHFTextEntries(void);
	void __fastcall RestoreDefaults(void);
	void __fastcall RestoreDefaultStyles(void);
	void __fastcall LoadFromFile(const System::UnicodeString AName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::UnicodeString AName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property int Count = {read=GetCount, nodefault};
	__property int CurrentStyleIndex = {read=GetCurrentStyleIndex, write=SetCurrentStyleIndex, nodefault};
	__property TAbstractdxStyleManagerDesigner* Designer = {read=FDesigner};
	__property bool PreviewBtnClicked = {read=FPreviewBtnClicked, nodefault};
	__property bool PrintBtnClicked = {read=FPrintBtnClicked, nodefault};
	__property TBasedxPrintStyle* Styles[int Index] = {read=GetStyle, write=SetStyle/*, default*/};
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	
__published:
	__property System::Classes::TStrings* AutoHFTextEntries = {read=FAutoHFTextEntries, write=SetAutoHFTextEntries, stored=IsAutoHFTextEntriesStored};
	__property bool AutoSave = {read=FAutoSave, write=FAutoSave, default=0};
	__property System::UnicodeString CloneStyleCaptionPrefix = {read=GetCloneStyleCaptionPrefix, write=SetCloneStyleCaptionPrefix, stored=IsCloneStyleCaptionPrefixStored};
	__property TBasedxPrintStyle* CurrentStyle = {read=FCurrentStyle, write=SetCurrentStyle};
	__property System::Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, default=0};
	__property Vcl::Controls::TImageList* Images = {read=FImages, write=SetImages};
	__property TdxPageSetupDialog* PageSetupDialog = {read=FPageSetupDialog, write=SetPageSetupDialog};
	__property System::UnicodeString StorageName = {read=FStorageName, write=FStorageName};
	__property System::UnicodeString Title = {read=GetTitle, write=SetTitle, stored=IsTitleStored};
	__property int Version = {read=FVersion, write=FVersion, nodefault};
	__property System::Classes::TNotifyEvent OnChangeCurrentStyle = {read=FOnChangeCurrentStyle, write=FOnChangeCurrentStyle};
	__property System::Classes::TNotifyEvent OnStyleListChanged = {read=FOnStyleListChanged, write=FOnStyleListChanged};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TAbstractdxStyleManagerDesigner : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxPrintStyleManager* FStyleManager;
	
protected:
	virtual void __fastcall Modified(void) = 0 ;
	virtual void __fastcall Update(TBasedxPrintStyle* AItem) = 0 ;
	
public:
	__fastcall TAbstractdxStyleManagerDesigner(TdxPrintStyleManager* AStyleManager);
	__fastcall virtual ~TAbstractdxStyleManagerDesigner(void);
	virtual void __fastcall BeginUpdate(void) = 0 ;
	virtual void __fastcall CancelUpdate(void) = 0 ;
	virtual void __fastcall EndUpdate(void) = 0 ;
	__property TdxPrintStyleManager* StyleManager = {read=FStyleManager};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxCustomDrawPreviewEvent)(TBasedxPrintStyle* APrintStyle, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &APageRect, System::Types::TRect &AContentRect, System::Types::TRect &AHeaderRect, System::Types::TRect &AFooterRect);

struct DECLSPEC_DRECORD TdxPageSetupDlgEvents
{
public:
	System::Classes::TNotifyEvent OnClose;
	TdxCustomDrawPreviewEvent OnCustomDrawPreview;
	System::Classes::TNotifyEvent OnShow;
};


typedef TdxPageSetupDlgEvents *PdxPageSetupDlgEvents;

struct TdxPageSetupDlgData;
typedef TdxPageSetupDlgData *PdxPageSetupDlgData;

struct DECLSPEC_DRECORD TdxPageSetupDlgData
{
public:
	TBasedxPrintStyle* PrintStyle;
	int ActivePageIndex;
	System::UnicodeString Title;
	System::Classes::THelpContext HelpContext;
	TdxHFMode HFMode;
	TdxPageSetupDlgButtons ButtonsEnabled;
	TdxPageSetupDlgButtons ButtonsVisible;
	TdxPageSetupDlgOptions OptionsEnabled;
	TdxPageSetupDlgOptions OptionsVisible;
	TdxPageSetupDlgEvents Events;
	bool PreviewBtnClicked;
	bool PrintBtnClicked;
	int iReserved;
};


class PASCALIMPLEMENTATION TdxPageSetupDialog : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	int FActivePageIndex;
	TdxPageSetupDlgButtons FButtonsEnabled;
	TdxPageSetupDlgButtons FButtonsVisible;
	TdxHFMode FHFMode;
	System::Classes::THelpContext FHelpContext;
	bool FIsTitleAssigned;
	TdxPageSetupDlgOptions FOptionsEnabled;
	TdxPageSetupDlgOptions FOptionsVisible;
	bool FPreviewBtnClicked;
	bool FPrintBtnClicked;
	TBasedxPrintStyle* FPrintStyle;
	System::UnicodeString FTitle;
	System::Classes::TNotifyEvent FOnClose;
	TdxCustomDrawPreviewEvent FOnCustomDrawPreview;
	System::Classes::TNotifyEvent FOnShow;
	System::UnicodeString __fastcall GetTitle(void);
	bool __fastcall IsTitleStored(void);
	void __fastcall SetPrintStyle(TBasedxPrintStyle* Value);
	void __fastcall SetTitle(const System::UnicodeString Value);
	void __fastcall ReadIsTitleAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteIsTitleAssigned(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TdxPageSetupDialog(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultTitle(void);
	bool __fastcall Execute(void);
	System::UnicodeString __fastcall RealTitle(void);
	virtual void __fastcall RestoreDefaults(void);
	__property bool PreviewBtnClicked = {read=FPreviewBtnClicked, nodefault};
	__property bool PrintBtnClicked = {read=FPrintBtnClicked, nodefault};
	
__published:
	__property int ActivePageIndex = {read=FActivePageIndex, write=FActivePageIndex, default=0};
	__property TdxPageSetupDlgButtons ButtonsEnabled = {read=FButtonsEnabled, write=FButtonsEnabled, default=14};
	__property TdxPageSetupDlgButtons ButtonsVisible = {read=FButtonsVisible, write=FButtonsVisible, default=14};
	__property System::Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, default=0};
	__property TdxHFMode HFMode = {read=FHFMode, write=FHFMode, default=0};
	__property TdxPageSetupDlgOptions OptionsEnabled = {read=FOptionsEnabled, write=FOptionsEnabled, default=8191};
	__property TdxPageSetupDlgOptions OptionsVisible = {read=FOptionsVisible, write=FOptionsVisible, default=8191};
	__property TBasedxPrintStyle* PrintStyle = {read=FPrintStyle, write=SetPrintStyle};
	__property System::UnicodeString Title = {read=GetTitle, write=SetTitle, stored=IsTitleStored};
	__property System::Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property TdxCustomDrawPreviewEvent OnCustomDrawPreview = {read=FOnCustomDrawPreview, write=FOnCustomDrawPreview};
	__property System::Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TdxPageSetupDialog(void) { }
	
};


class DELPHICLASS TdxfmPageSetupDialog;
class PASCALIMPLEMENTATION TdxfmPageSetupDialog : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnOptions;
	Cxbuttons::TcxButton* btnPrint;
	Cxbuttons::TcxButton* btnPrintPreview;
	Vcl::Extctrls::TBevel* bvlMarginsWarningHolder;
	Vcl::Extctrls::TBevel* bvlPreviewHolder;
	Cxdropdownedit::TcxComboBox* cbxPaperSource;
	Cxtextedit::TcxTextEdit* edStyleName;
	Cxgroupbox::TcxGroupBox* gbxMargins;
	Cxgroupbox::TcxGroupBox* gbxPaper;
	Cxlabel::TcxLabel* lblPaperHeight;
	Cxlabel::TcxLabel* lblPaperWidth;
	Cxlabel::TcxLabel* lblPercentOfNormalSize;
	Cxlabel::TcxLabel* lblPreview;
	Cxlabel::TcxLabel* lblStyleName;
	Cxlistbox::TcxListBox* lbxPaperType;
	Vcl::Extctrls::TPanel* Panel4;
	Cxpc::TcxPageControl* pgctrlMain;
	Vcl::Extctrls::TPanel* pnlButtons;
	Vcl::Extctrls::TPanel* pnlStyleName;
	Cxradiogroup::TcxRadioButton* rbtnAdjustTo;
	Cxradiogroup::TcxRadioButton* rbtnFitTo;
	Cxspinedit::TcxSpinEdit* seAdjustTo;
	Cxspinedit::TcxSpinEdit* sePaperHeight;
	Cxspinedit::TcxSpinEdit* sePaperWidth;
	Cxpc::TcxTabSheet* tshHeaderFooter;
	Cxpc::TcxTabSheet* tshMargins;
	Cxpc::TcxTabSheet* tshPage;
	Cxpc::TcxTabSheet* tshScaling;
	Cxgroupbox::TcxGroupBox* pnlReverse;
	Cxcheckbox::TcxCheckBox* chbxReverseOnEvenPages;
	Cxgroupbox::TcxGroupBox* pnlMargins;
	Cxlabel::TcxLabel* lblMarginTop;
	Cxlabel::TcxLabel* lblMarginBottom;
	Cxlabel::TcxLabel* lblMarginLeft;
	Cxlabel::TcxLabel* lblMarginRight;
	Cxspinedit::TcxSpinEdit* seMarginTop;
	Cxspinedit::TcxSpinEdit* seMarginBottom;
	Cxspinedit::TcxSpinEdit* seMarginLeft;
	Cxspinedit::TcxSpinEdit* seMarginRight;
	Cxgroupbox::TcxGroupBox* pnlHFMargins;
	Cxlabel::TcxLabel* lblMarginHeader;
	Cxlabel::TcxLabel* lblMarginFooter;
	Cxspinedit::TcxSpinEdit* seMarginHeader;
	Cxspinedit::TcxSpinEdit* seMarginFooter;
	Cxgroupbox::TcxGroupBox* Panel3;
	Cxbuttons::TcxButton* btnFix;
	Cxbuttons::TcxButton* btnRestoreOriginalMargins;
	Cxgroupbox::TcxGroupBox* pnlHeader;
	Cxgroupbox::TcxGroupBox* pnlHeaderFont;
	Cxbuttons::TcxButton* btnHeaderFont;
	Cxbuttons::TcxButton* btnHeaderBackground;
	Cxtextedit::TcxTextEdit* edHeaderFontInfo;
	Cxgroupbox::TcxGroupBox* pnlHeaderMemos;
	Vcl::Extctrls::TBevel* bv3;
	Vcl::Extctrls::TBevel* bv4;
	Cxmemo::TcxMemo* memHeaderCenter;
	Cxmemo::TcxMemo* memHeaderRight;
	Cxmemo::TcxMemo* memHeaderLeft;
	Cxlabel::TcxLabel* lblHeader;
	Cxgroupbox::TcxGroupBox* pnlFooter;
	Cxgroupbox::TcxGroupBox* pnlFooterFont;
	Cxbuttons::TcxButton* btnFooterFont;
	Cxbuttons::TcxButton* btnFooterBackGround;
	Cxtextedit::TcxTextEdit* edFooterFontInfo;
	Cxgroupbox::TcxGroupBox* pnlFooterMemos;
	Vcl::Extctrls::TBevel* bv1;
	Vcl::Extctrls::TBevel* bv2;
	Cxmemo::TcxMemo* memFooterRight;
	Cxmemo::TcxMemo* memFooterLeft;
	Cxmemo::TcxMemo* memFooterCenter;
	Cxlabel::TcxLabel* lblFooter;
	Cxgroupbox::TcxGroupBox* pnlBottom;
	Cxgroupbox::TcxGroupBox* gbxFunctions;
	Cxgroupbox::TcxGroupBox* gbxVertAlignment;
	Cxbuttons::TcxButton* btnVertAlignTop;
	Cxbuttons::TcxButton* btnVertAlignCenter;
	Cxbuttons::TcxButton* btnVertAlignBottom;
	Vcl::Extctrls::TBevel* Bevel3;
	Cxgroupbox::TcxGroupBox* tbPredefined;
	Vcl::Extctrls::TBevel* Bevel4;
	Cxgroupbox::TcxGroupBox* Panel6;
	Vcl::Extctrls::TBevel* Bevel1;
	Cxgroupbox::TcxGroupBox* gbxOrientation;
	Vcl::Extctrls::TBevel* bvlOrientationHolder;
	Cxradiogroup::TcxRadioButton* rBtnLandscape;
	Cxradiogroup::TcxRadioButton* rBtnPortrait;
	Cxgroupbox::TcxGroupBox* gbxPrintOrder;
	Vcl::Extctrls::TPaintBox* pbxPageOrder;
	Cxradiogroup::TcxRadioButton* rbtnOverThenDown;
	Cxradiogroup::TcxRadioButton* rbtnDownThenOver;
	Cxgroupbox::TcxGroupBox* gbxShading;
	Cxcheckbox::TcxCheckBox* chbxShading;
	Cxcheckbox::TcxCheckBox* chbxCenterHorz;
	Cxcheckbox::TcxCheckBox* chbxCenterVert;
	Cxlabel::TcxLabel* lblCenterOnPage;
	Vcl::Extctrls::TBevel* Bevel5;
	Vcl::Extctrls::TBevel* Bevel6;
	Vcl::Extctrls::TBevel* Bevel7;
	Vcl::Extctrls::TBevel* Bevel2;
	Vcl::Extctrls::TBevel* Bevel8;
	Cxgraphics::TcxImageList* ilPaperTypes;
	Cxgraphics::TcxImageList* ilBins;
	Cxgraphics::TcxImageList* ilPapers;
	Cxgraphics::TcxImageList* ilPrintOrders;
	Cxlabel::TcxLabel* lblPaperSource;
	void __fastcall AdjustToExit(System::TObject* Sender);
	void __fastcall BackgroundClick(System::TObject* Sender);
	void __fastcall btnFixClick(System::TObject* Sender);
	void __fastcall btnHFFontClick(System::TObject* Sender);
	void __fastcall btnPrintClick(System::TObject* Sender);
	void __fastcall btnPrintPreviewClick(System::TObject* Sender);
	void __fastcall btnRestoreOriginalMarginsClick(System::TObject* Sender);
	void __fastcall cbxPaperSourceChange(System::TObject* Sender);
	void __fastcall CenterOnPageClick(System::TObject* Sender);
	void __fastcall chbxReverseOnEvenPagesClick(System::TObject* Sender);
	void __fastcall chbxShadingClick(System::TObject* Sender);
	void __fastcall edStyleNameChange(System::TObject* Sender);
	void __fastcall edStyleNameExit(System::TObject* Sender);
	void __fastcall FitToPageChange(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall lblMarginTopClick(System::TObject* Sender);
	void __fastcall lblPaperSourceClick(System::TObject* Sender);
	void __fastcall lbxPaperTypeClick(System::TObject* Sender);
	void __fastcall lbxPaperTypeDrawItem(Cxlistbox::TcxListBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall memHeaderLeftChange(System::TObject* Sender);
	void __fastcall MarginChange(System::TObject* Sender);
	void __fastcall MarginExit(System::TObject* Sender);
	void __fastcall MarginValueChanged(System::TObject* Sender);
	void __fastcall MemoChange(System::TObject* Sender);
	void __fastcall MemoEnter(System::TObject* Sender);
	void __fastcall MemoExit(System::TObject* Sender);
	void __fastcall OrientationClick(System::TObject* Sender);
	void __fastcall OrientationDblClick(System::TObject* Sender);
	void __fastcall PageOrderClick(System::TObject* Sender);
	void __fastcall PaperWidthHeightChange(System::TObject* Sender);
	void __fastcall PaperWidthHeightUpdateInfos(System::TObject* Sender);
	void __fastcall pbxPageOrderDblClick(System::TObject* Sender);
	void __fastcall pbxPageOrderPaint(System::TObject* Sender);
	void __fastcall pgctrlMainChange(System::TObject* Sender);
	void __fastcall pgctrlMainPageChanging(System::TObject* Sender, Cxpc::TcxTabSheet* NewPage, bool &AllowChange);
	void __fastcall ScaleChanged(System::TObject* Sender);
	void __fastcall ScalingClick(System::TObject* Sender);
	void __fastcall VertTextAlignClick(System::TObject* Sender);
	void __fastcall cbxPaperSourcePropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall memHeaderCenterPropertiesChange(System::TObject* Sender);
	void __fastcall btnOptionsClick(System::TObject* Sender);
	void __fastcall btnHelpClick(System::TObject* Sender);
	
private:
	Vcl::Graphics::TBitmap* FBmpArrow;
	bool FCanShowStyleOptionsDlg;
	bool FControlsUpdating;
	Vcl::Graphics::TBitmap* FFooterBkGndGlyph;
	Vcl::Graphics::TBitmap* FHeaderBkGndGlyph;
	System::Classes::TStringList* FHFFunctionList;
	Dxpshftoolbarbld::TdxPSHFToolBarHelper* FHFToolBarHelper;
	Vcl::Controls::TImageList* FilPredefined;
	bool FMarginsChanged;
	bool FMarginsChanging;
	bool FMarginsInvalid;
	bool FMarginsOutside;
	bool FModified;
	bool FOrientationChanging;
	Dxprevw::TdxPreview* FOrientationPreview;
	bool FPaperSizeLocked;
	Dxprevw::TdxPreview* FPreview;
	bool FPreviewBtnClicked;
	bool FPrintBtnClicked;
	TBasedxPrintStyle* FPrintStyle;
	TBasedxPrintStyle* FSavePrintStyle;
	TdxPrintStyleManager* FStyleManager;
	Dxextctrls::TdxPSWarningPane* FwpMargins;
	System::Classes::TNotifyEvent FOnClose;
	TdxCustomDrawPreviewEvent FOnCustomDrawPreview;
	System::Classes::TNotifyEvent FOnShow;
	void __fastcall AutoHFTextEntriesClick(System::TObject* Sender);
	void __fastcall ChangeBkgndGlyph(Vcl::Graphics::TBitmap* AGlyph, Dxbkgnd::TdxBackground* ABackground);
	void __fastcall DoInsertMacrosValue(System::TObject* Sender, const System::UnicodeString AMacrosValue);
	void __fastcall DrawBackgroundBitmapContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Dxbkgnd::TdxBackground* ABackground);
	void __fastcall OrientationPreviewCalcPageCount(System::TObject* Sender);
	void __fastcall PreviewCalcPageCount(System::TObject* Sender);
	void __fastcall PreviewDrawPageContent(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABounds, int APageIndex);
	void __fastcall PreviewAfterDragMargin(System::TObject* Sender, Dxprevw::TdxPreviewPageMargin* AMargin);
	void __fastcall CheckModified(void);
	void __fastcall CreateControls(void);
	void __fastcall EnabledMemoAttr(bool AEnabled);
	int __fastcall FindControlPageIndex(Vcl::Controls::TWinControl* AControl);
	void __fastcall FixupMargins(void);
	void __fastcall FixupMarginsOutside(void);
	Dxprndev::TdxPaperInfo* __fastcall GetCurrentPaperInfo(void);
	Dxprnpg::TdxPrinterPage* __fastcall GetPage(void);
	Dxprndev::TdxPaperInfo* __fastcall GetPaperInfo(int Index);
	int __fastcall GetPaperInfoCount(void);
	Dxprnpg::TCustomdxPageObject* __fastcall GetSelectedTitle(void);
	Dxprnpg::TdxPageTitlePart __fastcall GetSelectedTitlePart(void);
	Cxmemo::TcxCustomMemo* __fastcall GetSelectedTitlePartEditor(void);
	Cxdrawtextutils::TcxTextAlignY __fastcall GetSelectedTitlePartTextAlignY(void);
	Dxprnpg::TdxPageTitlePart __fastcall GetTitlePart(System::Classes::TComponent* AComponent);
	int __fastcall GetUnitsDenominator(void);
	void __fastcall LoadStrings(void);
	void __fastcall RestoreOriginalMargins(void);
	void __fastcall SaveMargins(void);
	void __fastcall SaveStyleCaption(void);
	void __fastcall SaveUserInput(void);
	void __fastcall SetMarginsInvalid(bool Value);
	void __fastcall SetMarginsOutside(bool Value);
	void __fastcall SetSelectedTitlePartTextAlignY(Cxdrawtextutils::TcxTextAlignY AAlign);
	void __fastcall SetupDialog(const TdxPageSetupDlgData &APageSetupDlgData);
	void __fastcall StartSetting(void);
	void __fastcall TrySetActiveControl(Vcl::Controls::TWinControl* AControl);
	void __fastcall UpdateControlsState(void);
	void __fastcall UpdateMarginsBounds(void);
	void __fastcall UpdateMarginsEdits(void);
	void __fastcall UpdatePageInfos(void);
	void __fastcall UpdatePreviewMargin(const System::Extended AValue, Dxprevw::TdxPreviewPageMargin* AMargin);
	void __fastcall UpdatePreviewMargins(void);
	void __fastcall UpdateVerticalAlignmentButtonsState(void);
	void __fastcall UpdateWarningPane(bool AValue, bool APairValue, const System::UnicodeString AHint, const System::UnicodeString APairHint);
	bool __fastcall ValidateMargins(/* out */ Vcl::Controls::TWinControl* &AInvalidMarginControl);
	bool __fastcall ValidateMarginsOutside(/* out */ Vcl::Controls::TWinControl* &AInvalidMarginControl);
	bool __fastcall ValidateStyleCaption(void);
	bool __fastcall ValidateUserInput(/* out */ Vcl::Controls::TWinControl* &AControl);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	__property bool MarginsInvalid = {read=FMarginsInvalid, write=SetMarginsInvalid, nodefault};
	__property bool MarginsOutside = {read=FMarginsOutside, write=SetMarginsOutside, nodefault};
	__property Dxprnpg::TCustomdxPageObject* SelectedTitle = {read=GetSelectedTitle};
	__property Dxprnpg::TdxPageTitlePart SelectedTitlePart = {read=GetSelectedTitlePart, nodefault};
	__property Cxmemo::TcxCustomMemo* SelectedTitlePartEditor = {read=GetSelectedTitlePartEditor};
	__property Cxdrawtextutils::TcxTextAlignY SelectedTitlePartTextAlignY = {read=GetSelectedTitlePartTextAlignY, write=SetSelectedTitlePartTextAlignY, nodefault};
	__property int UnitsDenominator = {read=GetUnitsDenominator, nodefault};
	
protected:
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DoHide(void);
	DYNAMIC void __fastcall DoShow(void);
	
public:
	__fastcall virtual TdxfmPageSetupDialog(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmPageSetupDialog(void);
	bool __fastcall Execute(void);
	void __fastcall SetPrintStyle(TBasedxPrintStyle* Value);
	__property Dxprndev::TdxPaperInfo* CurrentPaperInfo = {read=GetCurrentPaperInfo};
	__property bool Modified = {read=FModified, nodefault};
	__property Dxprnpg::TdxPrinterPage* Page = {read=GetPage};
	__property int PaperInfoCount = {read=GetPaperInfoCount, nodefault};
	__property Dxprndev::TdxPaperInfo* PaperInfos[int Index] = {read=GetPaperInfo};
	__property bool PreviewBtnClicked = {read=FPreviewBtnClicked, nodefault};
	__property bool PrintBtnClicked = {read=FPrintBtnClicked, nodefault};
	__property TBasedxPrintStyle* PrintStyle = {read=FPrintStyle};
	__property TdxCustomDrawPreviewEvent OnCustomDrawPreview = {read=FOnCustomDrawPreview, write=FOnCustomDrawPreview};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmPageSetupDialog(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmPageSetupDialog(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


typedef void __fastcall (*TdxGetDateTimeFormatsProc)(System::Classes::TStrings* AStrings);

typedef void __fastcall (*TdxGetAutoHFTextEntriesProc)(System::Classes::TStrings* AStrings);

//-- var, const, procedure ---------------------------------------------------
#define psbAll (System::Set<TdxPageSetupDlgButtonKind, TdxPageSetupDlgButtonKind::psbHelp, TdxPageSetupDlgButtonKind::psbPrint> () << TdxPageSetupDlgButtonKind::psbHelp << TdxPageSetupDlgButtonKind::psbStyleOptions << TdxPageSetupDlgButtonKind::psbPreview << TdxPageSetupDlgButtonKind::psbPrint )
#define psbDefault (System::Set<TdxPageSetupDlgButtonKind, TdxPageSetupDlgButtonKind::psbHelp, TdxPageSetupDlgButtonKind::psbPrint> () << TdxPageSetupDlgButtonKind::psbStyleOptions << TdxPageSetupDlgButtonKind::psbPreview << TdxPageSetupDlgButtonKind::psbPrint )
#define psoAll (System::Set<TdxPageSetupDlgOption, TdxPageSetupDlgOption::psoCenterOnPage, TdxPageSetupDlgOption::psoHFVertAlignment> () << TdxPageSetupDlgOption::psoCenterOnPage << TdxPageSetupDlgOption::psoMargins << TdxPageSetupDlgOption::psoPageOrder << TdxPageSetupDlgOption::psoShading << TdxPageSetupDlgOption::psoStyleCaption << TdxPageSetupDlgOption::psoHFAutoText << TdxPageSetupDlgOption::psoHFBackground << TdxPageSetupDlgOption::psoHFFont << TdxPageSetupDlgOption::psoHFText << TdxPageSetupDlgOption::psoHFFunctions << TdxPageSetupDlgOption::psoHFMargins << TdxPageSetupDlgOption::psoHFReverse << TdxPageSetupDlgOption::psoHFVertAlignment )
#define psoDefaultOptionsEnabled (System::Set<TdxPageSetupDlgOption, TdxPageSetupDlgOption::psoCenterOnPage, TdxPageSetupDlgOption::psoHFVertAlignment> () << TdxPageSetupDlgOption::psoCenterOnPage << TdxPageSetupDlgOption::psoMargins << TdxPageSetupDlgOption::psoPageOrder << TdxPageSetupDlgOption::psoShading << TdxPageSetupDlgOption::psoStyleCaption << TdxPageSetupDlgOption::psoHFAutoText << TdxPageSetupDlgOption::psoHFBackground << TdxPageSetupDlgOption::psoHFFont << TdxPageSetupDlgOption::psoHFText << TdxPageSetupDlgOption::psoHFFunctions << TdxPageSetupDlgOption::psoHFMargins << TdxPageSetupDlgOption::psoHFReverse << TdxPageSetupDlgOption::psoHFVertAlignment )
#define psoDefaultOptionsVisible (System::Set<TdxPageSetupDlgOption, TdxPageSetupDlgOption::psoCenterOnPage, TdxPageSetupDlgOption::psoHFVertAlignment> () << TdxPageSetupDlgOption::psoCenterOnPage << TdxPageSetupDlgOption::psoMargins << TdxPageSetupDlgOption::psoPageOrder << TdxPageSetupDlgOption::psoShading << TdxPageSetupDlgOption::psoStyleCaption << TdxPageSetupDlgOption::psoHFAutoText << TdxPageSetupDlgOption::psoHFBackground << TdxPageSetupDlgOption::psoHFFont << TdxPageSetupDlgOption::psoHFText << TdxPageSetupDlgOption::psoHFFunctions << TdxPageSetupDlgOption::psoHFMargins << TdxPageSetupDlgOption::psoHFReverse << TdxPageSetupDlgOption::psoHFVertAlignment )
static const System::Int8 dxMaxStyleCaption = System::Int8(0x1f);
extern PACKAGE TdxPrintStyleClass dxDefaultPrintStyleClass;
extern PACKAGE TdxGetDateTimeFormatsProc dxGetDateFormatsProc;
extern PACKAGE TdxGetDateTimeFormatsProc dxGetTimeFormatsProc;
extern PACKAGE TdxGetAutoHFTextEntriesProc dxGetAutoHFTextEntriesProc;
extern PACKAGE bool __fastcall dxPageSetupDialog(TdxPageSetupDlgData &APageSetupDlgData);
extern PACKAGE void __fastcall dxPSRegisterPrintStyle(TdxPrintStyleClass AStyleClass, bool AMakeAsDefault = false);
extern PACKAGE void __fastcall dxPSUnregisterPrintStyle(TdxPrintStyleClass AStyleClass);
extern PACKAGE void __fastcall dxPSGetRegisteredPrintStylesList(System::Classes::TStrings* AStrings);
extern PACKAGE void __fastcall dxPSDrawStyleItem(TBasedxPrintStyle* AStyle, Vcl::Stdctrls::TListBox* AListBox, int Index, Winapi::Windows::TOwnerDrawState State, const System::Types::TRect &ABounds, bool AMultiline, bool ABoldedCurrent);
extern PACKAGE void __fastcall dxPSDefaultDrawPagePreview(TBasedxPrintStyle* APrintStyle, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &APageBounds, const System::Types::TRect &AContentBounds, const System::Types::TRect &AHeaderBounds, const System::Types::TRect &AFooterBounds);
extern PACKAGE System::UnicodeString __fastcall dxPSPrintStyleUniqueName(TdxPrintStyleManager* AStyleController, System::Classes::TComponent* AComponent);
extern PACKAGE System::Classes::TStrings* __fastcall DateFormats(void);
extern PACKAGE System::Classes::TStrings* __fastcall TimeFormats(void);
extern PACKAGE void __fastcall RefreshDateFormats(void);
extern PACKAGE void __fastcall RefreshTimeFormats(void);
extern PACKAGE System::Classes::TStrings* __fastcall PageNumberFormats(void);
extern PACKAGE System::UnicodeString __fastcall GetFormatedDate(const System::TDateTime ADateTime, const System::UnicodeString AFormat);
extern PACKAGE System::UnicodeString __fastcall GetFormatedTime(const System::TDateTime ADateTime, const System::UnicodeString AFormat);
extern PACKAGE void __fastcall GetFormatedDateStrings(const System::TDateTime ADateTime, System::Classes::TStrings* ADateFormats, System::Classes::TStrings* AFormatedStrings);
extern PACKAGE void __fastcall GetFormatedTimeStrings(const System::TDateTime ADateTime, System::Classes::TStrings* ATimeFormats, System::Classes::TStrings* AFormatedStrings);
extern PACKAGE System::Classes::TStrings* __fastcall DefaultAutoHFTextEntries(void);
}	/* namespace Dxpgsdlg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPGSDLG)
using namespace Dxpgsdlg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpgsdlgHPP
