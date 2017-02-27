// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxWWGridConverter.pas' rev: 24.00 (Win32)

#ifndef CxwwgridconverterHPP
#define CxwwgridconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxConverterFactory.hpp>	// Pascal unit
#include <cxGridConverter.hpp>	// Pascal unit
#include <cxGridDBBandedTableView.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxHyperLinkEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBLookupComboBox.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxLookupDBGrid.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxMRUEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxConverterUtils.hpp>	// Pascal unit
#include <cxCustomConverter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxwwgridconverter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxWWGridConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxWWGridConverter : public Cxgridconverter::TcxCustomGridConverter
{
	typedef Cxgridconverter::TcxCustomGridConverter inherited;
	
private:
	int FColor;
	Vcl::Graphics::TFont* FFont;
	int FTitleColor;
	Vcl::Graphics::TFont* FTitleFont;
	int __fastcall ExtractData(const System::UnicodeString AData, System::UnicodeString &AResultData, int AStartIndex, System::WideChar ASeparator);
	System::Uitypes::TEditCharCase __fastcall GetCharCase(const System::UnicodeString ACharCase);
	HIDESBASE Cxgriddbbandedtableview::TcxGridDBBandedTableView* __fastcall GetcxGridView(void);
	void __fastcall GetFieldNames(System::Classes::TStringList* AList);
	int __fastcall GetFontWidth(Vcl::Graphics::TFont* AFont);
	void __fastcall ImportColumnCheckBox(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, const System::UnicodeString AColumnData, const bool AReadOnly);
	void __fastcall ImportColumnCustomEdit(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, const System::UnicodeString AColumnData);
	void __fastcall ImportColumnImage(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, const System::UnicodeString AColumnData, const bool AReadOnly);
	void __fastcall ImportColumnRichEdit(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, const System::UnicodeString AColumnData);
	void __fastcall ImportColumnText(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, const bool AReadOnly);
	void __fastcall ImportColumnUrlLink(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, const bool AReadOnly);
	void __fastcall ImportBands(void);
	void __fastcall ImportColumns(void);
	void __fastcall ImportGrid(void);
	void __fastcall ImportGridStyles(void);
	void __fastcall ImportWWCheckBox(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWComboBox(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWComboDlg(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWDateTimePicker(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWExpandButton(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWLookupCombo(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWLookupComboDlg(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWMonthCalendar(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWOptions(void);
	void __fastcall ImportWWRadioGroup(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWSpinEdit(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	void __fastcall ImportWWTextEdit(Cxgriddbbandedtableview::TcxGridDBBandedColumn* AcxColumn, System::Classes::TComponent* AComponent);
	System::UnicodeString __fastcall IsColumnDefault(const System::UnicodeString AFieldName);
	int __fastcall Pass(const System::UnicodeString AData, int AStartIndex, int AFieldCount, System::WideChar ASeparator);
	
protected:
	virtual void __fastcall DoRealImport(void);
	virtual void __fastcall DoImportStyles(void);
	virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetGridViewClass(void);
	__property Cxgriddbbandedtableview::TcxGridDBBandedTableView* cxGridView = {read=GetcxGridView};
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetSourceClassName();
public:
	/* TcxCustomGridConverter.Create */ inline __fastcall virtual TcxWWGridConverter(System::TObject* ADestination) : Cxgridconverter::TcxCustomGridConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWWGridConverter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxwwgridconverter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXWWGRIDCONVERTER)
using namespace Cxwwgridconverter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxwwgridconverterHPP
