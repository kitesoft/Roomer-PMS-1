// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeDataSourceEditor.pas' rev: 24.00 (Win32)

#ifndef DxservermodedatasourceeditorHPP
#define DxservermodedatasourceeditorHPP

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
#include <DesignIntf.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodedatasourceeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxServerModeDataSourceEditor;
class PASCALIMPLEMENTATION TdxServerModeDataSourceEditor : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Cxcontrols::TcxCustomizeListBox* lbMain;
	Vcl::Menus::TPopupMenu* pmMain;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miNew;
	Vcl::Menus::TMenuItem* miAddAll;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* miCut;
	Vcl::Menus::TMenuItem* miCopy;
	Vcl::Menus::TMenuItem* miPaste;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miSelectAll;
	void __fastcall lbMainClick(System::TObject* Sender);
	void __fastcall miSelectAllClick(System::TObject* Sender);
	void __fastcall miCutClick(System::TObject* Sender);
	void __fastcall miCopyClick(System::TObject* Sender);
	void __fastcall miPasteClick(System::TObject* Sender);
	void __fastcall miDeleteClick(System::TObject* Sender);
	void __fastcall miAddClick(System::TObject* Sender);
	void __fastcall miAddAllClick(System::TObject* Sender);
	void __fastcall lbMainDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbMainDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall lbMainEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall lbMainStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall miNewClick(System::TObject* Sender);
	
private:
	int FPrevDragIndex;
	void __fastcall AddFields(bool All);
	void __fastcall CheckFieldDelete(void);
	void __fastcall CheckFieldAdd(void);
	Data::Db::TField* __fastcall CreateFields(Vcl::Stdctrls::TListBox* AFieldsList);
	Data::Db::TField* __fastcall DoCreateField(const System::UnicodeString AFieldName);
	Data::Db::TField* __fastcall DoNewField(void);
	void __fastcall Reindex(System::Classes::TList* AList, int ANewIndex);
	void __fastcall Copy(void);
	void __fastcall Cut(void);
	void __fastcall Paste(void);
	void __fastcall Delete(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	Dxservermodedata::TdxServerModeCustomDataSource* __fastcall GetDataSource(void);
	
protected:
	virtual void __fastcall InitFormEditor(void);
	virtual void __fastcall UpdateContent(void);
	void __fastcall UpdateMenuState(void);
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	
public:
	virtual void __fastcall DoItemsModified(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	__property Dxservermodedata::TdxServerModeCustomDataSource* DataSource = {read=GetDataSource};
public:
	/* TcxDesignWindow.Create */ inline __fastcall virtual TdxServerModeDataSourceEditor(System::Classes::TComponent* AOwner) : Cxdesignwindows::TcxDesignFormEditor(AOwner) { }
	
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TdxServerModeDataSourceEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxServerModeDataSourceEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxServerModeDataSourceEditor(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxShowServerModeDataSourceEditor(Designintf::_di_IDesigner ADesigner, Dxservermodedata::TdxServerModeCustomDataSource* ADataSource);
}	/* namespace Dxservermodedatasourceeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODEDATASOURCEEDITOR)
using namespace Dxservermodedatasourceeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodedatasourceeditorHPP
