// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxOICollectionEd.pas' rev: 24.00 (Win32)

#ifndef CxoicollectionedHPP
#define CxoicollectionedHPP

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
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxOI.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxoicollectioned
{
//-- type declarations -------------------------------------------------------
enum TcxColOption : unsigned char { coAdd, coDelete, coMove };

typedef System::Set<TcxColOption, TcxColOption::coAdd, TcxColOption::coMove>  TcxColOptions;

class DELPHICLASS TcxCollectionEditor;
class PASCALIMPLEMENTATION TcxCollectionEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Actnlist::TAction* acAdd;
	Vcl::Actnlist::TAction* acDelete;
	Vcl::Actnlist::TAction* acMoveDown;
	Vcl::Actnlist::TAction* acMoveUp;
	Vcl::Actnlist::TAction* acSelectAll;
	Vcl::Actnlist::TAction* acTextLabels;
	Vcl::Actnlist::TAction* acToolbar;
	Vcl::Controls::TImageList* ImageList;
	Vcl::Comctrls::TListView* ListView1;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miMoveDown;
	Vcl::Menus::TMenuItem* miMoveUp;
	Vcl::Menus::TMenuItem* miTextLabels;
	Vcl::Menus::TMenuItem* miToolbar;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Extctrls::TPanel* Panel;
	Vcl::Menus::TPopupMenu* PopupMenu1;
	Vcl::Menus::TPopupMenu* PopupMenu2;
	Vcl::Comctrls::TToolBar* Toolbar1;
	Vcl::Comctrls::TToolButton* ToolButton1;
	Vcl::Comctrls::TToolButton* ToolButton2;
	Vcl::Comctrls::TToolButton* ToolButton3;
	Vcl::Comctrls::TToolButton* ToolButton4;
	Vcl::Comctrls::TToolButton* ToolButton5;
	Vcl::Actnlist::TActionList* ActionList;
	void __fastcall acAddExecute(System::TObject* Sender);
	void __fastcall acDeleteExecute(System::TObject* Sender);
	void __fastcall acMoveDownExecute(System::TObject* Sender);
	void __fastcall acMoveUpExecute(System::TObject* Sender);
	void __fastcall acSelectAllExecute(System::TObject* Sender);
	void __fastcall acTextLabelsExecute(System::TObject* Sender);
	void __fastcall acToolbarExecute(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall FormKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ListView1Change(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemChange Change);
	void __fastcall ListView1DragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall ListView1DragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall ListView1KeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ListView1KeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall SelectAllCommandUpdate(System::TObject* Sender);
	void __fastcall SelectionUpdate(System::TObject* Sender);
	
private:
	bool FClosing;
	System::UnicodeString FCollectionPropertyName;
	int FStateLock;
	System::Classes::TList* FItemIDList;
	System::UnicodeString FCollectionClassName;
	bool FSelectionError;
	TcxColOptions FColOptions;
	Cxoi::TcxCustomRTTIInspector* FInspector;
	System::UnicodeString __fastcall GetRegKey(void);
	void __fastcall SetCollectionPropertyName(const System::UnicodeString Value);
	MESSAGE void __fastcall AMDeferUpdate(Winapi::Messages::TMessage &Msg);
	void __fastcall SetColOptions(TcxColOptions Value);
	void __fastcall CloseEditor(void);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &Message);
	
protected:
	void __fastcall CloseNonModal(Cxoi::TcxCustomRTTIInspector* AInspector);
	void __fastcall PropertyChanged(Cxoi::TcxCustomRTTIInspector* AInspector);
	virtual bool __fastcall CanAdd(int Index);
	virtual void __fastcall Localize(void);
	void __fastcall LockState(void);
	void __fastcall UnlockState(void);
	__property int StateLock = {read=FStateLock, nodefault};
	void __fastcall SelectAll(bool DoUpdate = true);
	void __fastcall SelectNone(bool DoUpdate = true);
	
public:
	System::Classes::TCollection* Collection;
	System::Classes::TComponent* Component;
	__property TcxColOptions Options = {read=FColOptions, write=SetColOptions, nodefault};
	virtual void __fastcall ItemsModified(Cxoi::TcxCustomRTTIInspector* AInspector);
	System::UnicodeString __fastcall GetItemName(int Index, int ItemIndex);
	void __fastcall GetSelection(void);
	void __fastcall SetSelection(void);
	void __fastcall UpdateListbox(void);
	__property System::UnicodeString CollectionPropertyName = {read=FCollectionPropertyName, write=SetCollectionPropertyName};
	__property Cxoi::TcxCustomRTTIInspector* Inspector = {read=FInspector};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxCollectionEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCollectionEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxCollectionEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCollectionEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
private:
	void *__IcxRTTIInspectorHelper;	/* Cxoi::IcxRTTIInspectorHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EA7182FA-139D-4525-9C5F-4D8BBAB5FEEE}
	operator Cxoi::_di_IcxRTTIInspectorHelper()
	{
		Cxoi::_di_IcxRTTIInspectorHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxoi::IcxRTTIInspectorHelper*(void) { return (Cxoi::IcxRTTIInspectorHelper*)&__IcxRTTIInspectorHelper; }
	#endif
	
};


typedef System::TMetaClass* TcxCollectionEditorClass;

class DELPHICLASS TcxCollectionProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCollectionProperty : public Cxoi::TcxClassProperty
{
	typedef Cxoi::TcxClassProperty inherited;
	
public:
	__fastcall virtual ~TcxCollectionProperty(void);
	virtual void __fastcall Edit(void);
	virtual Cxoi::TcxPropertyAttributes __fastcall GetAttributes(void);
	virtual TcxCollectionEditorClass __fastcall GetEditorClass(void);
	virtual TcxColOptions __fastcall GetColOptions(void);
	virtual bool __fastcall IsDefaultValue(void);
public:
	/* TcxPropertyEditor.Create */ inline __fastcall TcxCollectionProperty(System::Classes::TComponent* AOwner, Cxoi::TcxCustomRTTIInspector* AInspector, int APropCount) : Cxoi::TcxClassProperty(AOwner, AInspector, APropCount) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxCollectionEditor* __fastcall cxShowCollectionEditorClass(Cxoi::TcxCustomRTTIInspector* AInspector, TcxCollectionEditorClass CollectionEditorClass, System::Classes::TComponent* AComponent, System::Classes::TCollection* ACollection, const System::UnicodeString PropertyName, TcxColOptions ColOptions = (TcxColOptions() << TcxColOption::coAdd << TcxColOption::coDelete << TcxColOption::coMove ));
extern PACKAGE void __fastcall cxShowCollectionEditor(Cxoi::TcxCustomRTTIInspector* AInspector, System::Classes::TComponent* AComponent, System::Classes::TCollection* ACollection, const System::UnicodeString PropertyName);
}	/* namespace Cxoicollectioned */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXOICOLLECTIONED)
using namespace Cxoicollectioned;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxoicollectionedHPP
