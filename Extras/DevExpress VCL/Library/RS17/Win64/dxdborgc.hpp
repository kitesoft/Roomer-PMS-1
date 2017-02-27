// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxdborgc.pas' rev: 24.00 (Win64)

#ifndef DxdborgcHPP
#define DxdborgcHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxorgchr.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdborgc
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TdxOcNewKeyEvent)(System::TObject* Sender, System::Variant &MaxValue, System::Variant &KeyValue);

class DELPHICLASS TdxOcDataLink;
class DELPHICLASS TdxDbOrgChart;
class PASCALIMPLEMENTATION TdxOcDataLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	TdxDbOrgChart* FTree;
	bool FFiltered;
	System::UnicodeString FFilter;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
public:
	/* TDataLink.Create */ inline __fastcall TdxOcDataLink(void) : Data::Db::TDataLink() { }
	/* TDataLink.Destroy */ inline __fastcall virtual ~TdxOcDataLink(void) { }
	
};


class DELPHICLASS TdxDbOcNode;
class PASCALIMPLEMENTATION TdxDbOcNode : public Dxorgchr::TdxOcNode
{
	typedef Dxorgchr::TdxOcNode inherited;
	
private:
	System::Variant FKey;
	System::Variant FParentKey;
	System::Variant FOrder;
	int FRecNum;
	bool FRefreshed;
	
protected:
	virtual void __fastcall SetText(const System::UnicodeString Value);
	virtual void __fastcall ReadData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TdxDbOcNode(Dxorgchr::TdxCustomOrgChart* AOwner);
	TdxDbOrgChart* __fastcall DbOwner(void);
	__property System::Variant Key = {read=FKey};
	__property System::Variant ParentKey = {read=FParentKey};
public:
	/* TdxOcNode.Destroy */ inline __fastcall virtual ~TdxDbOcNode(void) { }
	
};


class PASCALIMPLEMENTATION TdxDbOrgChart : public Dxorgchr::TdxCustomOrgChart
{
	typedef Dxorgchr::TdxCustomOrgChart inherited;
	
private:
	TdxOcDataLink* FLink;
	System::UnicodeString FKeyFieldName;
	System::UnicodeString FParentFieldName;
	System::UnicodeString FTextFieldName;
	System::UnicodeString FOrderFieldName;
	System::UnicodeString FWidthFieldName;
	System::UnicodeString FHeightFieldName;
	System::UnicodeString FColorFieldName;
	System::UnicodeString FShapeFieldName;
	System::UnicodeString FChAlignFieldName;
	System::UnicodeString FImIndexFieldName;
	System::UnicodeString FImAlignFieldName;
	Data::Db::TField* FKeyField;
	Data::Db::TField* FParentField;
	Data::Db::TField* FTextField;
	Data::Db::TField* FOrderField;
	Data::Db::TField* FWidthField;
	Data::Db::TField* FHeightField;
	Data::Db::TField* FColorField;
	Data::Db::TField* FShapeField;
	Data::Db::TField* FChAlignField;
	Data::Db::TField* FImIndexField;
	Data::Db::TField* FImAlignField;
	System::Classes::TList* FKeyList;
	System::Variant FMaxKey;
	int FCurRec;
	int FRecCount;
	TdxOcNewKeyEvent FOnNewKey;
	Dxorgchr::TdxOcEvent FOnLoadNode;
	bool FEnableDB;
	bool FKeyOrder;
	void __fastcall AssignFields(void);
	void __fastcall RefreshItems(void);
	void __fastcall RefreshRecord(void);
	void __fastcall RefreshParents(void);
	void __fastcall BeginRefresh(void);
	void __fastcall EndRefresh(void);
	bool __fastcall FindNearest(System::Variant &AKey, int &AIndex);
	TdxDbOcNode* __fastcall GetNodeByKey(System::Variant &AKey);
	void __fastcall AddToKeyList(TdxDbOcNode* ANode);
	void __fastcall DelFromKeyList(TdxDbOcNode* ANode);
	int __fastcall FindIndex(System::Variant &AKey, TdxDbOcNode* AParent);
	bool __fastcall LocateToNode(TdxDbOcNode* ANode);
	void __fastcall SetParentNode(TdxDbOcNode* ANode);
	void __fastcall CheckKeys(TdxDbOcNode* ANode);
	void __fastcall CheckRec(TdxDbOcNode* ANode);
	System::Variant __fastcall NewKey(void);
	TdxDbOcNode* __fastcall CreateDBNode(System::Variant &AKey, TdxDbOcNode* AParent);
	void __fastcall MoveDBNode(TdxDbOcNode* ANode, TdxDbOcNode* AParent);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	void __fastcall ActiveChanged(void);
	void __fastcall DataChanged(void);
	void __fastcall DoScroll(int Dist);
	void __fastcall RecordChanged(Data::Db::TField* Field);
	void __fastcall SetBookmark(int ABookmark);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetKeyFieldName(const System::UnicodeString Value);
	void __fastcall SetParentFieldName(const System::UnicodeString Value);
	void __fastcall SetTextFieldName(const System::UnicodeString Value);
	void __fastcall SetOrderFieldName(const System::UnicodeString Value);
	void __fastcall SetWidthFieldName(const System::UnicodeString Value);
	void __fastcall SetHeightFieldName(const System::UnicodeString Value);
	void __fastcall SetColorFieldName(const System::UnicodeString Value);
	void __fastcall SetShapeFieldName(const System::UnicodeString Value);
	void __fastcall SetChAlignFieldName(const System::UnicodeString Value);
	void __fastcall SetImIndexFieldName(const System::UnicodeString Value);
	void __fastcall SetImAlignFieldName(const System::UnicodeString Value);
	
protected:
	virtual Dxorgchr::TdxOcInplaceEdit* __fastcall CreateEditor(void);
	virtual Dxorgchr::TdxOcNode* __fastcall InternalAdd(Dxorgchr::TdxOcNode* AParent, void * Data, int Idx);
	virtual void __fastcall InternalMoveTo(Dxorgchr::TdxOcNode* AParent, Dxorgchr::TdxOcNode* ANode, int Idx);
	virtual void __fastcall NodeChanged(Dxorgchr::TdxOcNode* ANode);
	virtual void __fastcall DoChange(Dxorgchr::TdxOcNode* Node);
	virtual void __fastcall DoChanging(Dxorgchr::TdxOcNode* Node, bool &Allow);
	virtual Dxorgchr::TdxOcNodeClass __fastcall GetNodeClass(void);
	
public:
	__fastcall virtual TdxDbOrgChart(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDbOrgChart(void);
	virtual void __fastcall Delete(Dxorgchr::TdxOcNode* ANode);
	virtual void __fastcall ShowEditor(void);
	bool __fastcall Active(void);
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property Data::Db::TField* KeyField = {read=FKeyField};
	__property Data::Db::TField* ParentField = {read=FParentField};
	__property Data::Db::TField* TextField = {read=FTextField};
	__property Data::Db::TField* OrderField = {read=FOrderField};
	__property Data::Db::TField* WidthField = {read=FWidthField};
	__property Data::Db::TField* HeightField = {read=FHeightField};
	__property Data::Db::TField* ColorField = {read=FColorField};
	__property Data::Db::TField* ShapeField = {read=FShapeField};
	__property Data::Db::TField* ChAlignField = {read=FChAlignField};
	__property Data::Db::TField* ImageField = {read=FImIndexField};
	__property Data::Db::TField* ImAlignField = {read=FImAlignField};
	__property System::UnicodeString WidthFieldName = {read=FWidthFieldName, write=SetWidthFieldName};
	__property System::UnicodeString HeightFieldName = {read=FHeightFieldName, write=SetHeightFieldName};
	__property System::UnicodeString ColorFieldName = {read=FColorFieldName, write=SetColorFieldName};
	__property System::UnicodeString ShapeFieldName = {read=FShapeFieldName, write=SetShapeFieldName};
	__property System::UnicodeString ChAlignFieldName = {read=FChAlignFieldName, write=SetChAlignFieldName};
	__property System::UnicodeString ImAlignFieldName = {read=FImAlignFieldName, write=SetImAlignFieldName};
	
__published:
	__property Anchors = {default=3};
	__property Antialiasing = {default=0};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property System::UnicodeString KeyFieldName = {read=FKeyFieldName, write=SetKeyFieldName};
	__property System::UnicodeString ParentFieldName = {read=FParentFieldName, write=SetParentFieldName};
	__property System::UnicodeString TextFieldName = {read=FTextFieldName, write=SetTextFieldName};
	__property System::UnicodeString OrderFieldName = {read=FOrderFieldName, write=SetOrderFieldName};
	__property System::UnicodeString ImageFieldName = {read=FImIndexFieldName, write=SetImIndexFieldName};
	__property bool KeyOrder = {read=FKeyOrder, write=FKeyOrder, default=0};
	__property TdxOcNewKeyEvent OnNewKey = {read=FOnNewKey, write=FOnNewKey};
	__property Dxorgchr::TdxOcEvent OnLoadNode = {read=FOnLoadNode, write=FOnLoadNode};
	__property LookAndFeel;
	__property LineColor = {default=536870912};
	__property LineWidth = {default=1};
	__property SelectedNodeColor = {default=536870912};
	__property SelectedNodeTextColor = {default=536870912};
	__property DefaultNodeWidth = {default=64};
	__property DefaultNodeHeight = {default=40};
	__property IndentX = {default=16};
	__property IndentY = {default=16};
	__property Options;
	__property EditMode = {default=16};
	__property Images;
	__property DefaultImageAlign = {default=0};
	__property BorderStyle = {default=1};
	__property Rotated = {default=0};
	__property Zoom = {default=0};
	__property OnCreateNode;
	__property OnChange;
	__property OnChanging;
	__property OnCollapsed;
	__property OnCollapsing;
	__property OnDeletion;
	__property OnExpanded;
	__property OnExpansion;
	__property OnEditing;
	__property OnEdited;
	__property OnSetFont;
	__property OnDrawNode;
	__property OnGetText;
	__property OnSetText;
	__property Align = {default=0};
	__property Ctl3D;
	__property Color = {default=-16777211};
	__property Enabled = {default=1};
	__property Font;
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnDblClick;
	__property OnEnter;
	__property OnExit;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnStartDrag;
	__property OnEndDrag;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property PopupMenu;
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property ShowHint;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDbOrgChart(HWND ParentWindow) : Dxorgchr::TdxCustomOrgChart(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdborgc */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDBORGC)
using namespace Dxdborgc;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdborgcHPP
