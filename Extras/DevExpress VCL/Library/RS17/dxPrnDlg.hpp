// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPrnDlg.pas' rev: 24.00 (Win32)

#ifndef DxprndlgHPP
#define DxprndlgHPP

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
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit
#include <dxPrnDev.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxprndlg
{
//-- type declarations -------------------------------------------------------
enum TdxPageNumbers : unsigned char { pnAll, pnEven, pnOdd };

enum TdxPageRanges : unsigned char { prAll, prCurrent, prRange, prSelection };

enum TdxPrintDlgButtonKind : unsigned char { pdbPrinterProperties, pdbNetwork, pdbPreview, pdbPageSetup, pdbDefineStyles, pdbStyleOptions, pdbHelp };

typedef System::Set<TdxPrintDlgButtonKind, TdxPrintDlgButtonKind::pdbPrinterProperties, TdxPrintDlgButtonKind::pdbHelp>  TdxPrintDlgButtons;

enum TdxPrintDlgOption : unsigned char { pdoPrintToFile, pdoAllPages, pdoCurrentPage, pdoSelection, pdoPageRange, pdoPrintStyles };

typedef System::Set<TdxPrintDlgOption, TdxPrintDlgOption::pdoPrintToFile, TdxPrintDlgOption::pdoPrintStyles>  TdxPrintDlgOptions;

typedef void __fastcall (__closure *TdxPageSetupEvent)(System::TObject* Sender, bool &ADone, System::PBoolean APreviewBtnClicked, System::PBoolean APrintBtnClicked);

struct TdxPrintDlgEvents;
typedef TdxPrintDlgEvents *PdxPrintDlgEvents;

struct DECLSPEC_DRECORD TdxPrintDlgEvents
{
public:
	System::Classes::TNotifyEvent OnClose;
	TdxPageSetupEvent OnPageSetup;
	System::Classes::TNotifyEvent OnShow;
};


struct TdxPrintDialogData;
typedef TdxPrintDialogData *PdxPrintDialogData;

struct DECLSPEC_DRECORD TdxPrintDialogData
{
public:
	int Copies;
	bool Collate;
	System::Classes::TStrings* FileList;
	System::UnicodeString FileName;
	int MaxRange;
	int MinRange;
	int PageCount;
	TdxPageNumbers PageNums;
	TdxPageRanges PageRanges;
	System::UnicodeString Pages;
	bool PrintToFile;
	Dxpgsdlg::TdxPrintStyleManager* StyleManager;
};


struct TdxPrintDlgData;
typedef TdxPrintDlgData *PdxPrintDlgData;

struct DECLSPEC_DRECORD TdxPrintDlgData
{
public:
	TdxPrintDialogData DialogData;
	System::UnicodeString Title;
	System::Classes::THelpContext HelpContext;
	TdxPrintDlgButtons ButtonsEnabled;
	TdxPrintDlgButtons ButtonsVisible;
	TdxPrintDlgOptions OptionsEnabled;
	TdxPrintDlgOptions OptionsVisible;
	TdxPrintDlgEvents Events;
	bool IsCheckUserInput;
	bool PreviewBtnClicked;
};


class DELPHICLASS TdxPrintDialog;
class PASCALIMPLEMENTATION TdxPrintDialog : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	TdxPrintDlgButtons FButtonsEnabled;
	TdxPrintDlgButtons FButtonsVisible;
	TdxPrintDialogData FDialogData;
	System::Classes::THelpContext FHelpContext;
	bool FIsTitleAssigned;
	TdxPrintDlgOptions FOptionsEnabled;
	TdxPrintDlgOptions FOptionsVisible;
	bool FPreviewBtnClicked;
	bool FPrintBtnClicked;
	System::UnicodeString FTitle;
	bool FUseFileList;
	System::Classes::TNotifyEvent FOnClose;
	TdxPageSetupEvent FOnPageSetup;
	System::Classes::TNotifyEvent FOnShow;
	bool __fastcall GetCollate(void);
	int __fastcall GetCopies(void);
	System::Classes::TStrings* __fastcall GetFileList(void);
	System::UnicodeString __fastcall GetFileName(void);
	int __fastcall GetMaxRange(void);
	int __fastcall GetMinRange(void);
	int __fastcall GetPageCount(void);
	TdxPageNumbers __fastcall GetPageNums(void);
	TdxPageRanges __fastcall GetPageRanges(void);
	System::UnicodeString __fastcall GetPages(void);
	bool __fastcall GetPrintToFile(void);
	Dxpgsdlg::TdxPrintStyleManager* __fastcall GetStyleManager(void);
	System::UnicodeString __fastcall GetTitle(void);
	bool __fastcall IsTitleStored(void);
	void __fastcall SetCollate(bool Value);
	void __fastcall SetCopies(int Value);
	void __fastcall SetFileList(System::Classes::TStrings* Value);
	void __fastcall SetFileName(const System::UnicodeString Value);
	void __fastcall SetMaxRange(int Value);
	void __fastcall SetMinRange(int Value);
	void __fastcall SetPageCount(int Value);
	void __fastcall SetPageNums(TdxPageNumbers Value);
	void __fastcall SetPageRanges(TdxPageRanges Value);
	void __fastcall SetPages(const System::UnicodeString Value);
	void __fastcall SetPrintToFile(bool Value);
	void __fastcall SetStyleManager(Dxpgsdlg::TdxPrintStyleManager* Value);
	void __fastcall SetTitle(const System::UnicodeString Value);
	void __fastcall ReadIsTitleAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteIsTitleAssigned(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TdxPrintDialog(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPrintDialog(void);
	virtual System::UnicodeString __fastcall DefaultTitle(void);
	bool __fastcall Execute(void);
	virtual void __fastcall RestoreDefaults(void);
	void __fastcall SetMinMaxRanges(int AMinRange, int AMaxRange);
	__property TdxPrintDialogData DialogData = {read=FDialogData};
	__property System::Classes::TStrings* FileList = {read=GetFileList, write=SetFileList};
	__property int PageCount = {read=GetPageCount, write=SetPageCount, nodefault};
	__property bool PreviewBtnClicked = {read=FPreviewBtnClicked, nodefault};
	__property bool PrintBtnClicked = {read=FPrintBtnClicked, nodefault};
	
__published:
	__property TdxPrintDlgButtons ButtonsEnabled = {read=FButtonsEnabled, write=FButtonsEnabled, default=63};
	__property TdxPrintDlgButtons ButtonsVisible = {read=FButtonsVisible, write=FButtonsVisible, default=63};
	__property bool Collate = {read=GetCollate, write=SetCollate, default=0};
	__property int Copies = {read=GetCopies, write=SetCopies, default=1};
	__property System::UnicodeString FileName = {read=GetFileName, write=SetFileName};
	__property System::Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, default=0};
	__property int MaxRange = {read=GetMaxRange, write=SetMaxRange, default=1};
	__property int MinRange = {read=GetMinRange, write=SetMinRange, default=1};
	__property TdxPrintDlgOptions OptionsEnabled = {read=FOptionsEnabled, write=FOptionsEnabled, default=19};
	__property TdxPrintDlgOptions OptionsVisible = {read=FOptionsVisible, write=FOptionsVisible, default=23};
	__property TdxPageNumbers PageNums = {read=GetPageNums, write=SetPageNums, default=0};
	__property TdxPageRanges PageRanges = {read=GetPageRanges, write=SetPageRanges, default=0};
	__property System::UnicodeString Pages = {read=GetPages, write=SetPages};
	__property bool PrintToFile = {read=GetPrintToFile, write=SetPrintToFile, default=0};
	__property Dxpgsdlg::TdxPrintStyleManager* StyleManager = {read=GetStyleManager, write=SetStyleManager};
	__property System::UnicodeString Title = {read=GetTitle, write=SetTitle, stored=IsTitleStored};
	__property bool UseFileList = {read=FUseFileList, write=FUseFileList, default=0};
	__property System::Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property TdxPageSetupEvent OnPageSetup = {read=FOnPageSetup, write=FOnPageSetup};
	__property System::Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
};


class DELPHICLASS TdxfmPrintDialog;
class PASCALIMPLEMENTATION TdxfmPrintDialog : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Vcl::Menus::TPopupMenu* pmPrintStyles;
	Vcl::Menus::TMenuItem* miPageSetup;
	Vcl::Menus::TMenuItem* miDefineStyles;
	Vcl::Menus::TMenuItem* miLine1;
	Cxgroupbox::TcxGroupBox* gbxPrinter;
	Cxlabel::TcxLabel* lblName;
	Cxlabel::TcxLabel* lblStatus;
	Cxlabel::TcxLabel* lblType;
	Cxlabel::TcxLabel* lblWhere;
	Cxlabel::TcxLabel* lblComment;
	Cxlabel::TcxLabel* lStatus;
	Cxlabel::TcxLabel* lType;
	Cxlabel::TcxLabel* lWhere;
	Cxlabel::TcxLabel* lComment;
	Cxbuttons::TcxButton* btnPrinterProperties;
	Cxbuttons::TcxButton* btnNetwork;
	Cxdropdownedit::TcxComboBox* cbxPrinters;
	Cxbuttons::TcxButton* btnBrowse;
	Cxdropdownedit::TcxComboBox* cbxFileName;
	Cxcheckbox::TcxCheckBox* chbxPrintToFile;
	Cxgraphics::TcxImageList* ilPrinters;
	Vcl::Extctrls::TPanel* pnlMain;
	Vcl::Extctrls::TPanel* pnlMiddle;
	Cxgroupbox::TcxGroupBox* gbxPageRange;
	Vcl::Extctrls::TBevel* bvlPRWarningHolder;
	Cxlabel::TcxLabel* lblDescription;
	Cxradiogroup::TcxRadioButton* rbtnAllPages;
	Cxradiogroup::TcxRadioButton* rbtnCurrentPage;
	Cxradiogroup::TcxRadioButton* rbtnPageRanges;
	Cxradiogroup::TcxRadioButton* rbtnSelection;
	Cxtextedit::TcxTextEdit* edPageRanges;
	Cxgroupbox::TcxGroupBox* gbxCopies;
	Vcl::Extctrls::TPaintBox* pbxCollate;
	Cxlabel::TcxLabel* lblNumberOfCopies;
	Cxlabel::TcxLabel* lblNumberOfPages;
	Cxcheckbox::TcxCheckBox* chbxCollate;
	Cxdropdownedit::TcxComboBox* cbxNumberOfPages;
	Cxspinedit::TcxSpinEdit* seCopies;
	Cxgroupbox::TcxGroupBox* gbxPrintStyles;
	Cxbuttons::TcxButton* btnPageSetup2;
	Cxbuttons::TcxButton* btnDefineStyles;
	Cxlistbox::TcxListBox* lbxPrintStyles;
	Cxbuttons::TcxButton* btnPageSetup;
	Cxbuttons::TcxButton* btnPreview;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnOK;
	void __fastcall chbxCollateClick(System::TObject* Sender);
	void __fastcall btnPrinterPropertiesClick(System::TObject* Sender);
	void __fastcall cbxPrintersChange(System::TObject* Sender);
	void __fastcall chbxPrintToFileClick(System::TObject* Sender);
	void __fastcall edPageRangesChange(System::TObject* Sender);
	void __fastcall cbxNumberOfPagesChange(System::TObject* Sender);
	void __fastcall rbtnPagesClick(System::TObject* Sender);
	void __fastcall btnBrowseClick(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall edPageRangesExit(System::TObject* Sender);
	void __fastcall btnPreviewClick(System::TObject* Sender);
	void __fastcall btnPageSetupClick(System::TObject* Sender);
	void __fastcall edPageRangesKeyPress(System::TObject* Sender, System::WideChar &KEY);
	void __fastcall lblNumberOfPagesClick(System::TObject* Sender);
	void __fastcall lblNumberOfCopiesClick(System::TObject* Sender);
	void __fastcall btnNetworkClick(System::TObject* Sender);
	void __fastcall seCopiesChange(System::TObject* Sender);
	void __fastcall seCopiesExit(System::TObject* Sender);
	void __fastcall PageSetup2Click(System::TObject* Sender);
	void __fastcall lbxPrintStylesClick(System::TObject* Sender);
	void __fastcall DefineStylesClick(System::TObject* Sender);
	void __fastcall pmPrintStylesPopup(System::TObject* Sender);
	void __fastcall cbxFileNameExit(System::TObject* Sender);
	void __fastcall pbxCollatePaint(System::TObject* Sender);
	void __fastcall pbxCollateDblClick(System::TObject* Sender);
	void __fastcall cbxPrintersPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall lbxPrintStylesDrawItem(Cxlistbox::TcxListBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall btnHelpClick(System::TObject* Sender);
	
private:
	bool FControlsUpdating;
	TdxPrintDialogData FDialogData;
	System::StaticArray<Vcl::Graphics::TBitmap*, 2> FGlyphs;
	bool FIsCheckUserInput;
	bool FModified;
	Dxpsesys::TdxEventSubscriber* FSubscriber;
	bool FPreviewBtnClicked;
	bool FPrintBtnClicked;
	TdxPrintDialogData FSaveDialogData;
	bool FPrintStylesVisibled;
	Dxextctrls::TdxPSWarningPane* FwpPageRanges;
	System::Classes::TNotifyEvent FOnClose;
	TdxPageSetupEvent FOnPageSetup;
	System::Classes::TNotifyEvent FOnShow;
	bool __fastcall CheckFileName(const System::UnicodeString FileName);
	void __fastcall CheckModified(void);
	bool __fastcall CheckPageRanges(void);
	bool __fastcall CheckUserInput(void);
	void __fastcall ConnectToPrinterDlg(void);
	void __fastcall CreateControls(void);
	void __fastcall DocumentPropertiesDlg(void);
	void __fastcall DrawCollatedPages(HDC DC, const System::Types::TRect &ADrawRect, bool ACollate);
	System::UnicodeString __fastcall GetFileName(const System::UnicodeString S);
	void __fastcall LoadStrings(void);
	void __fastcall RefreshPrinterList(void);
	void __fastcall RefreshStyleList(void);
	void __fastcall SavePrintDialogData(void);
	HIDESBASE void __fastcall SetActiveControl(void);
	void __fastcall SetupDialog(const TdxPrintDlgData &APrintDlgData);
	void __fastcall StartSettings(void);
	void __fastcall StyleListChanged(System::TObject* Sender);
	void __fastcall UpdateControlsState(void);
	void __fastcall UpdatePrinterInfos(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DoHide(void);
	DYNAMIC void __fastcall DoShow(void);
	DYNAMIC void __fastcall DoPageSetup(void);
	void __fastcall UpdatePrinters(void);
	
public:
	__fastcall virtual TdxfmPrintDialog(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmPrintDialog(void);
	bool __fastcall Execute(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall ShowPrintStyles(bool AShow);
	__property bool PreviewBtnClicked = {read=FPreviewBtnClicked, nodefault};
	__property TdxPageSetupEvent OnPageSetup = {read=FOnPageSetup, write=FOnPageSetup};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmPrintDialog(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmPrintDialog(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define pdbAll (System::Set<TdxPrintDlgButtonKind, TdxPrintDlgButtonKind::pdbPrinterProperties, TdxPrintDlgButtonKind::pdbHelp> () << TdxPrintDlgButtonKind::pdbPrinterProperties << TdxPrintDlgButtonKind::pdbNetwork << TdxPrintDlgButtonKind::pdbPreview << TdxPrintDlgButtonKind::pdbPageSetup << TdxPrintDlgButtonKind::pdbDefineStyles << TdxPrintDlgButtonKind::pdbStyleOptions << TdxPrintDlgButtonKind::pdbHelp )
#define pdbDefault (System::Set<TdxPrintDlgButtonKind, TdxPrintDlgButtonKind::pdbPrinterProperties, TdxPrintDlgButtonKind::pdbHelp> () << TdxPrintDlgButtonKind::pdbPrinterProperties << TdxPrintDlgButtonKind::pdbNetwork << TdxPrintDlgButtonKind::pdbPreview << TdxPrintDlgButtonKind::pdbPageSetup << TdxPrintDlgButtonKind::pdbDefineStyles << TdxPrintDlgButtonKind::pdbStyleOptions )
#define pdoAll (System::Set<TdxPrintDlgOption, TdxPrintDlgOption::pdoPrintToFile, TdxPrintDlgOption::pdoPrintStyles> () << TdxPrintDlgOption::pdoPrintToFile << TdxPrintDlgOption::pdoAllPages << TdxPrintDlgOption::pdoCurrentPage << TdxPrintDlgOption::pdoSelection << TdxPrintDlgOption::pdoPageRange << TdxPrintDlgOption::pdoPrintStyles )
#define pdoDefaultOptionsEnabled (System::Set<TdxPrintDlgOption, TdxPrintDlgOption::pdoPrintToFile, TdxPrintDlgOption::pdoPrintStyles> () << TdxPrintDlgOption::pdoPrintToFile << TdxPrintDlgOption::pdoAllPages << TdxPrintDlgOption::pdoPageRange )
#define pdoDefaultOptionsVisible (System::Set<TdxPrintDlgOption, TdxPrintDlgOption::pdoPrintToFile, TdxPrintDlgOption::pdoPrintStyles> () << TdxPrintDlgOption::pdoPrintToFile << TdxPrintDlgOption::pdoAllPages << TdxPrintDlgOption::pdoCurrentPage << TdxPrintDlgOption::pdoPageRange )
extern PACKAGE bool __fastcall dxPrintDialog(TdxPrintDlgData &AData);
}	/* namespace Dxprndlg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPRNDLG)
using namespace Dxprndlg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxprndlgHPP
