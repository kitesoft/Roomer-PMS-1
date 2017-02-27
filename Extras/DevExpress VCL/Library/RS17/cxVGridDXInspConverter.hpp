// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVGridDXInspConverter.pas' rev: 24.00 (Win32)

#ifndef CxvgriddxinspconverterHPP
#define CxvgriddxinspconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxConverterFactory.hpp>	// Pascal unit
#include <cxVGridConverter.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <cxDBVGrid.hpp>	// Pascal unit
#include <cxConverterUtils.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxCustomConverter.hpp>	// Pascal unit
#include <cxBlobEdit.hpp>	// Pascal unit
#include <cxPropertiesConverters.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <cxCalc.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCurrencyEdit.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxDBLookupComboBox.hpp>	// Pascal unit
#include <cxHyperLinkEdit.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxMRUEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxOI.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvgriddxinspconverter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomVerticalGridAccess;
class PASCALIMPLEMENTATION TcxCustomVerticalGridAccess : public Cxvgrid::TcxCustomVerticalGrid
{
	typedef Cxvgrid::TcxCustomVerticalGrid inherited;
	
public:
	/* TcxCustomVerticalGrid.Create */ inline __fastcall virtual TcxCustomVerticalGridAccess(System::Classes::TComponent* AOwner) : Cxvgrid::TcxCustomVerticalGrid(AOwner) { }
	/* TcxCustomVerticalGrid.Destroy */ inline __fastcall virtual ~TcxCustomVerticalGridAccess(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomVerticalGridAccess(HWND ParentWindow) : Cxvgrid::TcxCustomVerticalGrid(ParentWindow) { }
	
};


class DELPHICLASS TcxUnboundVerticalGridAccess;
class PASCALIMPLEMENTATION TcxUnboundVerticalGridAccess : public Cxvgrid::TcxUnboundVerticalGrid
{
	typedef Cxvgrid::TcxUnboundVerticalGrid inherited;
	
public:
	/* TcxUnboundVerticalGrid.Create */ inline __fastcall virtual TcxUnboundVerticalGridAccess(System::Classes::TComponent* AOwner) : Cxvgrid::TcxUnboundVerticalGrid(AOwner) { }
	
public:
	/* TcxCustomVerticalGrid.Destroy */ inline __fastcall virtual ~TcxUnboundVerticalGridAccess(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxUnboundVerticalGridAccess(HWND ParentWindow) : Cxvgrid::TcxUnboundVerticalGrid(ParentWindow) { }
	
};


class DELPHICLASS TcxCustomDXInspConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDXInspConverter : public Cxvgridconverter::TcxCustomVerticalGridConverter
{
	typedef Cxvgridconverter::TcxCustomVerticalGridConverter inherited;
	
private:
	System::Classes::TStringList* FcxRowCache;
	System::Classes::TStringList* FdxRowCache;
	int FDefaultRowHeight;
	System::UnicodeString FSeparatorString;
	TcxCustomVerticalGridAccess* __fastcall GetAccess(void);
	System::Classes::TComponent* __fastcall GetComponent(void);
	
protected:
	Cxvgrid::TcxCustomRow* __fastcall AddRow(Cxvgrid::TcxCustomRow* AcxRowParent, const System::UnicodeString AdxRowName);
	void __fastcall AssignCaptionProperties(System::TObject* AdxRow, Cxvgrid::TcxCaptionRowProperties* AProperties);
	virtual void __fastcall AssignEditorDataBinding(System::TObject* AdxRow, Cxvgrid::TcxCustomEditorRowProperties* AProperties);
	void __fastcall AssignEditorProperties(System::TObject* AdxRow, Cxvgrid::TcxCustomEditorRowProperties* AProperties);
	virtual void __fastcall AssignVerticalGrid(void);
	virtual void __fastcall AssignVerticalGridOptions(void);
	void __fastcall ConvertPaintStyle(void);
	virtual Cxvgrid::TcxCollectionItemEditorRowProperties* __fastcall CreateMultiEditorRowItem(Cxvgrid::TcxCustomRow* AcxRow);
	virtual void __fastcall DoRealImport(void);
	virtual int __fastcall GetConvertorIndex(System::TObject* AdxRow);
	virtual Cxvgrid::TcxCustomRowClass __fastcall GetRowClassType(System::TObject* AdxRow);
	void __fastcall ImportCategoryRow(System::TObject* AdxRow, Cxvgrid::TcxCustomRow* AcxRow);
	virtual void __fastcall ImportEditorRow(System::TObject* AdxRow, Cxvgrid::TcxCustomRow* AcxRow);
	void __fastcall ImportLayout(void);
	virtual void __fastcall ImportMultiEditorRow(System::TObject* AdxRow, Cxvgrid::TcxCustomRow* AcxRow);
	void __fastcall ImportRow(Cxvgrid::TcxCustomRow* AcxRow, System::TObject* AdxRow);
	virtual void __fastcall ImportRows(void);
	virtual void __fastcall SetRowName(Cxvgrid::TcxCustomRow* AcxRow);
	__property TcxCustomVerticalGridAccess* Access = {read=GetAccess};
	__property System::Classes::TComponent* Component = {read=GetComponent};
	
public:
	__fastcall virtual TcxCustomDXInspConverter(System::TObject* ADestination);
	__fastcall virtual ~TcxCustomDXInspConverter(void);
};

#pragma pack(pop)

class DELPHICLASS TcxDXInspConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDXInspConverter : public TcxCustomDXInspConverter
{
	typedef TcxCustomDXInspConverter inherited;
	
private:
	HIDESBASE TcxUnboundVerticalGridAccess* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall AssignEditorDataBinding(System::TObject* AdxRow, Cxvgrid::TcxCustomEditorRowProperties* AProperties);
	virtual void __fastcall AssignVerticalGridOptions(void);
	virtual Cxvgrid::TcxCollectionItemEditorRowProperties* __fastcall CreateMultiEditorRowItem(Cxvgrid::TcxCustomRow* AcxRow);
	virtual Cxvgrid::TcxCustomRowClass __fastcall GetRowClassType(System::TObject* AdxRow);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetSourceClassName();
	__property TcxUnboundVerticalGridAccess* Destination = {read=GetDestination};
public:
	/* TcxCustomDXInspConverter.Create */ inline __fastcall virtual TcxDXInspConverter(System::TObject* ADestination) : TcxCustomDXInspConverter(ADestination) { }
	/* TcxCustomDXInspConverter.Destroy */ inline __fastcall virtual ~TcxDXInspConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDXDBInspConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDXDBInspConverter : public TcxCustomDXInspConverter
{
	typedef TcxCustomDXInspConverter inherited;
	
private:
	HIDESBASE Cxdbvgrid::TcxDBVerticalGrid* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall AssignEditorDataBinding(System::TObject* AdxRow, Cxvgrid::TcxCustomEditorRowProperties* AProperties);
	virtual void __fastcall AssignVerticalGrid(void);
	virtual void __fastcall AssignVerticalGridOptions(void);
	virtual Cxvgrid::TcxCollectionItemEditorRowProperties* __fastcall CreateMultiEditorRowItem(Cxvgrid::TcxCustomRow* AcxRow);
	virtual int __fastcall GetConvertorIndex(System::TObject* AdxRow);
	virtual Cxvgrid::TcxCustomRowClass __fastcall GetRowClassType(System::TObject* AdxRow);
	virtual void __fastcall SetRowName(Cxvgrid::TcxCustomRow* AcxRow);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetSourceClassName();
	__property Cxdbvgrid::TcxDBVerticalGrid* Destination = {read=GetDestination};
public:
	/* TcxCustomDXInspConverter.Create */ inline __fastcall virtual TcxDXDBInspConverter(System::TObject* ADestination) : TcxCustomDXInspConverter(ADestination) { }
	/* TcxCustomDXInspConverter.Destroy */ inline __fastcall virtual ~TcxDXDBInspConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDXRTTIConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDXRTTIConverter : public TcxDXInspConverter
{
	typedef TcxDXInspConverter inherited;
	
protected:
	virtual void __fastcall DoRealImport(void);
	virtual void __fastcall ImportRows(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetSourceClassName();
public:
	/* TcxCustomDXInspConverter.Create */ inline __fastcall virtual TcxDXRTTIConverter(System::TObject* ADestination) : TcxDXInspConverter(ADestination) { }
	/* TcxCustomDXInspConverter.Destroy */ inline __fastcall virtual ~TcxDXRTTIConverter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxvgriddxinspconverter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVGRIDDXINSPCONVERTER)
using namespace Cxvgriddxinspconverter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvgriddxinspconverterHPP
