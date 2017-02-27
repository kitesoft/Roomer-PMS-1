// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridOLAPConnectionDesigner.pas' rev: 24.00 (Win32)

#ifndef CxpivotgridolapconnectiondesignerHPP
#define CxpivotgridolapconnectiondesignerHPP

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
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxPivotGridStrs.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Data.Win.ADODB.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridolapconnectiondesigner
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxPivotGridOLAPConnectionDesignerClass;

class DELPHICLASS TfrmConnectionDesigner;
class PASCALIMPLEMENTATION TfrmConnectionDesigner : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	Cxgroupbox::TcxGroupBox* gbSite;
	Cxlabel::TcxLabel* lbConnectType;
	Cxradiogroup::TcxRadioButton* rbAnalysisServer;
	Cxradiogroup::TcxRadioButton* rbCubeFile;
	Cxbuttonedit::TcxButtonEdit* edtServer;
	Cxdropdownedit::TcxComboBox* edtDatabase;
	Cxlabel::TcxLabel* lbServer;
	Cxlabel::TcxLabel* lbDatabase;
	Cxlabel::TcxLabel* lbCube;
	Cxdropdownedit::TcxComboBox* edtCube;
	Vcl::Dialogs::TOpenDialog* dlgOpen;
	void __fastcall rbCubeFileClick(System::TObject* Sender);
	void __fastcall rbAnalysisServerClick(System::TObject* Sender);
	void __fastcall edtServerPropertiesButtonClick(System::TObject* Sender, int AButtonIndex);
	void __fastcall edtDatabaseChanged(System::TObject* Sender);
	void __fastcall edtServerChanged(System::TObject* Sender);
	
private:
	bool __fastcall IsDataValid(void);
	void __fastcall SelectConnectionType(bool AUseServer);
	
protected:
	Data::Win::Adodb::TADOConnection* __fastcall CreateServerConnection(void);
	DYNAMIC void __fastcall DoShow(void);
	void __fastcall FillComboByDataSet(Cxdropdownedit::TcxComboBox* AComboBox, Data::Db::TDataSet* ADataSet, Data::Db::TField* AField);
	virtual System::WideString __fastcall GetConnectionString(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializeCatalogList(void);
	virtual void __fastcall InitializeCubeList(void);
	void __fastcall Validate(void);
	
public:
	__property System::WideString ConnectionString = {read=GetConnectionString};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmConnectionDesigner(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmConnectionDesigner(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmConnectionDesigner(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmConnectionDesigner(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxPivotGridOLAPConnectionDesignerClass ConnectionDesignerClass;
extern PACKAGE System::WideString __fastcall cxPivotGridOLAPCreateConnectionString(System::WideString &ACube, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0));
}	/* namespace Cxpivotgridolapconnectiondesigner */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDOLAPCONNECTIONDESIGNER)
using namespace Cxpivotgridolapconnectiondesigner;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridolapconnectiondesignerHPP
