// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerTaskDependencyEditor.pas' rev: 24.00 (Win64)

#ifndef CxschedulertaskdependencyeditorHPP
#define CxschedulertaskdependencyeditorHPP

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
#include <cxClasses.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulertaskdependencyeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmSchedulerTaskDependencyEditor;
class PASCALIMPLEMENTATION TfmSchedulerTaskDependencyEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxlabel::TcxLabel* lbFrom;
	Cxlabel::TcxLabel* lbTo;
	Cxlabel::TcxLabel* lbType;
	Cxdropdownedit::TcxComboBox* cbTypeRelation;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnDelete;
	Cxlabel::TcxLabel* lbFromName;
	Cxlabel::TcxLabel* lbToName;
	Cxgroupbox::TcxGroupBox* cxGroupBox1;
	void __fastcall cbTypeRelationPropertiesChange(System::TObject* Sender);
	void __fastcall btnDeleteClick(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	bool FIsDelete;
	Cxschedulerstorage::TcxSchedulerEvent* FEventFrom;
	Cxschedulerstorage::TcxSchedulerEvent* FEventTo;
	bool FIsModified;
	Cxschedulerstorage::TcxSchedulerEventRelation FLinkRelation;
	void __fastcall CheckButtonState(void);
	void __fastcall SetLinkRelation(Cxschedulerstorage::TcxSchedulerEventRelation AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetEventStr(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	virtual void __fastcall InitControls(void);
	void __fastcall SetCaptions(void);
	
public:
	virtual int __fastcall ShowModal(void);
	__property bool IsDelete = {read=FIsDelete, nodefault};
	__property Cxschedulerstorage::TcxSchedulerEvent* EventFrom = {read=FEventFrom, write=FEventFrom};
	__property Cxschedulerstorage::TcxSchedulerEvent* EventTo = {read=FEventTo, write=FEventTo};
	__property bool IsModified = {read=FIsModified, nodefault};
	__property Cxschedulerstorage::TcxSchedulerEventRelation LinkRelation = {read=FLinkRelation, write=SetLinkRelation, nodefault};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmSchedulerTaskDependencyEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmSchedulerTaskDependencyEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmSchedulerTaskDependencyEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmSchedulerTaskDependencyEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef TfmSchedulerTaskDependencyEditor TcxSchedulerTaskDependencyEditor;

typedef System::TMetaClass* TcxSchedulerTaskDependencyEditorClass;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulertaskdependencyeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERTASKDEPENDENCYEDITOR)
using namespace Cxschedulertaskdependencyeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulertaskdependencyeditorHPP
