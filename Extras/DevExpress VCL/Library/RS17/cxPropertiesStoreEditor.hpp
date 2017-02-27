// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPropertiesStoreEditor.pas' rev: 24.00 (Win32)

#ifndef CxpropertiesstoreeditorHPP
#define CxpropertiesstoreeditorHPP

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
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxPropertiesStore.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpropertiesstoreeditor
{
//-- type declarations -------------------------------------------------------
enum TfrmPropertiesStoreFilter : unsigned char { psfNone, psfStored, psfUnStored };

enum TfrmPropertiesStoreGrouping : unsigned char { psgComponents, psgProperties };

class DELPHICLASS TcxPropertiesStoreNode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPropertiesStoreNode : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxPropertiesStoreNode* operator[](int Index) { return Nodes[Index]; }
	
private:
	System::UnicodeString FName;
	TcxPropertiesStoreNode* FParent;
	System::Classes::TPersistent* FPersistent;
	System::UnicodeString FPropertyName;
	Cxclasses::TcxObjectList* FSubNodes;
	Vcl::Comctrls::TTreeNode* FTreeNode;
	Cxlookandfeelpainters::TcxCheckBoxState FCheckState;
	bool __fastcall GetIsPartOfComponent(void);
	TcxPropertiesStoreNode* __fastcall GetNode(int Index);
	int __fastcall GetNodesCount(void);
	int __fastcall GetStateIndex(void);
	void __fastcall SetCheckState(Cxlookandfeelpainters::TcxCheckBoxState Value);
	bool __fastcall GetIsFullStored(void);
	bool __fastcall GetIsStored(void);
	
public:
	__fastcall virtual ~TcxPropertiesStoreNode(void);
	TcxPropertiesStoreNode* __fastcall Add(const System::UnicodeString AName, System::Classes::TPersistent* APersistent)/* overload */;
	TcxPropertiesStoreNode* __fastcall Add(const System::UnicodeString AName, const System::UnicodeString APropertyName, System::Classes::TPersistent* APersistent)/* overload */;
	bool __fastcall Find(const System::UnicodeString AName, /* out */ TcxPropertiesStoreNode* &ANode)/* overload */;
	bool __fastcall Find(const System::UnicodeString AName, int &AIndex)/* overload */;
	bool __fastcall FindPersistent(System::Classes::TPersistent* APersistent, /* out */ TcxPropertiesStoreNode* &ANode, bool ACanBePartOfComponent = true);
	void __fastcall Clear(void);
	void __fastcall CheckStoredValue(void);
	void __fastcall SetCheckValue(Cxlookandfeelpainters::TcxCheckBoxState AValue, bool AWithChildren, bool AWithParents);
	void __fastcall SetStoredValue(bool AValue, bool AWithChildren, bool AWithParents);
	__property bool IsPartOfComponent = {read=GetIsPartOfComponent, nodefault};
	__property System::UnicodeString Name = {read=FName};
	__property TcxPropertiesStoreNode* Nodes[int Index] = {read=GetNode/*, default*/};
	__property int NodesCount = {read=GetNodesCount, nodefault};
	__property TcxPropertiesStoreNode* Parent = {read=FParent};
	__property System::Classes::TPersistent* Persistent = {read=FPersistent};
	__property System::UnicodeString PropertyName = {read=FPropertyName};
	__property bool IsFullStored = {read=GetIsFullStored, nodefault};
	__property bool IsStored = {read=GetIsStored, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxPropertiesStoreNode(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TfrmPropertiesStoreEditor;
class PASCALIMPLEMENTATION TfrmPropertiesStoreEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlClient;
	Vcl::Comctrls::TToolBar* ToolBar;
	Vcl::Extctrls::TPanel* pnlLeftTree;
	Vcl::Extctrls::TPanel* pnlLeftTreeTop;
	Vcl::Comctrls::TTreeView* Tree;
	Vcl::Stdctrls::TLabel* lblFindComponent;
	Vcl::Stdctrls::TEdit* edFindComponent;
	Vcl::Comctrls::TToolButton* btnGroupByComponents;
	Vcl::Comctrls::TToolButton* btnGroupByProperties;
	Vcl::Comctrls::TToolButton* ToolButton3;
	Vcl::Comctrls::TToolButton* btnReset;
	Vcl::Comctrls::TToolButton* btnCheckAll;
	Vcl::Comctrls::TToolButton* btnUncheckAll;
	Vcl::Actnlist::TActionList* ActionList1;
	Vcl::Actnlist::TAction* actGroupByComponents;
	Vcl::Actnlist::TAction* actGroupByProperties;
	Cxgraphics::TcxImageList* cxImageList1;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Stdctrls::TButton* btnCancel;
	Cxgraphics::TcxImageList* cxImageList2;
	void __fastcall actGroupByComponentsExecute(System::TObject* Sender);
	void __fastcall actGroupByPropertiesExecute(System::TObject* Sender);
	void __fastcall btnCheckAllClick(System::TObject* Sender);
	void __fastcall btnResetClick(System::TObject* Sender);
	void __fastcall btnUncheckAllClick(System::TObject* Sender);
	void __fastcall edFindComponentKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall TreeExpanding(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowExpansion);
	void __fastcall TreeMouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall TreeKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall TreeKeyPress(System::TObject* Sender, System::WideChar &Key);
	
private:
	TfrmPropertiesStoreFilter FFilter;
	TfrmPropertiesStoreGrouping FGrouping;
	System::Classes::TComponent* FOwnerComponent;
	Cxpropertiesstore::TcxPropertiesStore* FPropertiesStore;
	TcxPropertiesStoreNode* FStructure;
	void __fastcall SetOwnerComponent(System::Classes::TComponent* const Value);
	void __fastcall SetFilter(const TfrmPropertiesStoreFilter Value);
	void __fastcall SetGrouping(const TfrmPropertiesStoreGrouping Value);
	void __fastcall SetFindText(void);
	void __fastcall LoadFromPropertiesStore(Cxpropertiesstore::TcxPropertiesStore* AStore);
	void __fastcall SaveToPropertiesStore(Cxpropertiesstore::TcxPropertiesStore* AStore);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	Vcl::Comctrls::TTreeNode* __fastcall FindNode(const System::UnicodeString AText);
	void __fastcall Reset(void);
	void __fastcall CheckUncheckAll(bool AChecked);
	void __fastcall ToggleCheckState(Vcl::Comctrls::TTreeNode* ATreeNode);
	
protected:
	void __fastcall RefreshTree(void);
	void __fastcall SynchronizeTreeView(void);
	void __fastcall SynchronizeTreeViewNode(Vcl::Comctrls::TTreeNode* ATreeNode, TcxPropertiesStoreNode* ANode);
	__property TcxPropertiesStoreNode* Structure = {read=FStructure};
	
public:
	__fastcall virtual TfrmPropertiesStoreEditor(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TfrmPropertiesStoreEditor(void);
	__property TfrmPropertiesStoreFilter Filter = {read=FFilter, write=SetFilter, nodefault};
	__property TfrmPropertiesStoreGrouping Grouping = {read=FGrouping, write=SetGrouping, nodefault};
	__property System::Classes::TComponent* OwnerComponent = {read=FOwnerComponent, write=SetOwnerComponent};
	__property Cxpropertiesstore::TcxPropertiesStore* PropertiesStore = {read=FPropertiesStore, write=FPropertiesStore};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmPropertiesStoreEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmPropertiesStoreEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define scxFindComponent L"Find Component:"
#define scxFindProperty L"Find Property:"
extern PACKAGE void __fastcall ShowPropertiesStoreEditor(Cxpropertiesstore::TcxPropertiesStore* APropertiesStore, System::Classes::TComponent* AOwnerComponent);
}	/* namespace Cxpropertiesstoreeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPROPERTIESSTOREEDITOR)
using namespace Cxpropertiesstoreeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpropertiesstoreeditorHPP
