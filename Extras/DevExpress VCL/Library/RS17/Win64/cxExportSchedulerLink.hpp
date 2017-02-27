// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExportSchedulerLink.pas' rev: 24.00 (Win64)

#ifndef CxexportschedulerlinkHPP
#define CxexportschedulerlinkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxExport.hpp>	// Pascal unit
#include <cxXLSExport.hpp>	// Pascal unit
#include <dxXLSXExport.hpp>	// Pascal unit
#include <cxHtmlXmlTxtExport.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexportschedulerlink
{
//-- type declarations -------------------------------------------------------
__interface IcxNameExportProvider;
typedef System::DelphiInterface<IcxNameExportProvider> _di_IcxNameExportProvider;
__interface  INTERFACE_UUID("{FC69194E-E3C7-41F4-98AE-5948813210AE}") IcxNameExportProvider  : public System::IInterface 
{
	
public:
	virtual void __fastcall SetName(const System::UnicodeString AName) = 0 ;
	virtual void __fastcall SetRangeName(const System::UnicodeString AName, const System::Types::TRect &ARange) = 0 ;
};

class DELPHICLASS TcxSchedulerExportHelper;
class PASCALIMPLEMENTATION TcxSchedulerExportHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerFilteredEventList* FEvents;
	System::TDateTime FFinish;
	_di_IcxNameExportProvider FNameProvider;
	System::UnicodeString FHeader;
	Cxexport::_di_IcxExportProvider FProvider;
	System::TDateTime FStart;
	
protected:
	bool HasHeader;
	int CaptionStyle;
	Vcl::Graphics::TFont* Font;
	virtual void __fastcall CalculateLayout(void);
	virtual void __fastcall DoExport(void);
	virtual void __fastcall ExportEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, int AIndex, int &ARow);
	virtual void __fastcall ExportEvents(void);
	int __fastcall RegisterCellStyle(System::Uitypes::TColor AColor, System::Uitypes::TColor AFontColor, Cxexport::TcxFontStyles AFontStyle, Cxgraphics::TcxBorders ABorders, Cxgraphics::TcxBorders ABoldBorders, Cxexport::TcxAlignText AAlignText = (Cxexport::TcxAlignText)(0x0));
	
public:
	__fastcall virtual TcxSchedulerExportHelper(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, const System::TDateTime AStart, const System::TDateTime AFinish, int AExportType, const System::UnicodeString AFileName);
	__fastcall virtual ~TcxSchedulerExportHelper(void);
	__property Cxschedulerstorage::TcxSchedulerFilteredEventList* Events = {read=FEvents};
	__property System::TDateTime Finish = {read=FFinish};
	__property _di_IcxNameExportProvider NameProvider = {read=FNameProvider};
	__property Cxexport::_di_IcxExportProvider Provider = {read=FProvider};
	__property System::TDateTime Start = {read=FStart};
	__property System::UnicodeString Header = {read=FHeader};
};


class DELPHICLASS TcxSchedulerTableExportHelper;
class PASCALIMPLEMENTATION TcxSchedulerTableExportHelper : public TcxSchedulerExportHelper
{
	typedef TcxSchedulerExportHelper inherited;
	
protected:
	int Style;
	virtual void __fastcall CalculateLayout(void);
	virtual void __fastcall DoExport(void);
	virtual void __fastcall ExportEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, int AIndex, int &ARow);
public:
	/* TcxSchedulerExportHelper.Create */ inline __fastcall virtual TcxSchedulerTableExportHelper(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, const System::TDateTime AStart, const System::TDateTime AFinish, int AExportType, const System::UnicodeString AFileName) : TcxSchedulerExportHelper(AScheduler, AStart, AFinish, AExportType, AFileName) { }
	/* TcxSchedulerExportHelper.Destroy */ inline __fastcall virtual ~TcxSchedulerTableExportHelper(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerExportHelperClass;

class DELPHICLASS TfmExportRangeDialog;
class PASCALIMPLEMENTATION TfmExportRangeDialog : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	Cxlabel::TcxLabel* lbSetDateRange;
	Cxcalendar::TcxDateEdit* deStart;
	Cxcalendar::TcxDateEdit* deFinish;
	Cxlabel::TcxLabel* lbAnd;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall deDatePropertiesChange(System::TObject* Sender);
	
protected:
	DYNAMIC void __fastcall DoShow(void);
	virtual System::Uitypes::TColor __fastcall GetFormColor(void);
	bool __fastcall IsValid(void);
	virtual void __fastcall SetCaptions(void);
	
public:
	__fastcall virtual TfmExportRangeDialog(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, System::TDateTime AStart, System::TDateTime AFinish);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmExportRangeDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmExportRangeDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmExportRangeDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmExportRangeDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::StaticArray<TcxSchedulerExportHelperClass, 2> SchedulerExportHelpers;
extern PACKAGE System::StaticArray<void *, 2> YesNoStrs;
extern PACKAGE System::StaticArray<void *, 2> TrueFalseStrs;
extern PACKAGE System::StaticArray<void *, 4> States;
extern PACKAGE int MaxColumnWidth;
extern PACKAGE void __fastcall cxExportSchedulerToFile(System::UnicodeString AFileName, Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, bool AsTable, bool AShowDialog, const System::UnicodeString AHeader, System::TDateTime AStart, System::TDateTime AFinish, int AExportType, System::UnicodeString const *ASeparators, const int ASeparators_Size, const System::UnicodeString AFileExt);
extern PACKAGE void __fastcall cxExportSchedulerToHTML(const System::UnicodeString AFileName, Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, bool AsTable = false, bool AShowDialog = false, const System::UnicodeString AHeader = L"Event %d", const System::TDateTime AStart = -7.000000E+05, const System::TDateTime AFinish = -7.000000E+05, const System::UnicodeString AFileExt = L"html");
extern PACKAGE void __fastcall cxExportSchedulerToXML(const System::UnicodeString AFileName, Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, bool AsTable = false, bool AShowDialog = false, const System::UnicodeString AHeader = L"Event %d", const System::TDateTime AStart = -7.000000E+05, const System::TDateTime AFinish = -7.000000E+05, const System::UnicodeString AFileExt = L"xml");
extern PACKAGE void __fastcall cxExportSchedulerToExcel(const System::UnicodeString AFileName, Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, bool AsTable = false, bool AShowDialog = false, const System::UnicodeString AHeader = L"Event %d", const System::TDateTime AStart = -7.000000E+05, const System::TDateTime AFinish = -7.000000E+05, const System::UnicodeString AFileExt = L"xls");
extern PACKAGE void __fastcall cxExportSchedulerToXLSX(const System::UnicodeString AFileName, Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, bool AsTable = false, bool AShowDialog = false, const System::UnicodeString AHeader = L"Event %d", const System::TDateTime AStart = -7.000000E+05, const System::TDateTime AFinish = -7.000000E+05, const System::UnicodeString AFileExt = L"xlsx");
extern PACKAGE void __fastcall cxExportSchedulerToText(const System::UnicodeString AFileName, Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, bool AsTable = false, bool AShowDialog = false, const System::UnicodeString AHeader = L"Event %d", const System::TDateTime AStart = -7.000000E+05, const System::TDateTime AFinish = -7.000000E+05, const System::UnicodeString ASeparator = System::UnicodeString(), const System::UnicodeString ABeginString = System::UnicodeString(), const System::UnicodeString AEndString = System::UnicodeString(), const System::UnicodeString AFileExt = L"txt");
}	/* namespace Cxexportschedulerlink */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXPORTSCHEDULERLINK)
using namespace Cxexportschedulerlink;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexportschedulerlinkHPP
