// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridStructureNavigator.pas' rev: 24.00 (Win32)

#ifndef CxgridstructurenavigatorHPP
#define CxgridstructurenavigatorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxViewEditor.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridstructurenavigator
{
//-- type declarations -------------------------------------------------------
enum TcxGridColorIndex : unsigned char { ciGrid, ciLevel, ciView };

class DELPHICLASS TcxGridStructureControlRowViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridStructureControlRowViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TRect Bounds;
	System::Types::TRect LevelBounds;
	System::Types::TRect LevelContentBounds;
	bool LevelHighlighted;
	bool LevelSelected;
	System::UnicodeString LevelText;
	System::Types::TRect LevelTextArea;
	System::Types::TRect ViewBounds;
	System::Types::TRect ViewContentBounds;
	bool ViewHighlighted;
	bool ViewSelected;
	System::UnicodeString ViewText;
	System::Types::TRect ViewTextArea;
	int TreeLineVertCount;
	bool TreeLineIsParent;
	bool TreeLineIsLast;
public:
	/* TObject.Create */ inline __fastcall TcxGridStructureControlRowViewInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridStructureControlRowViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridStructureControlRowsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridStructureControlRowsViewInfo : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxGridStructureControlRowViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxGridStructureControlRowViewInfo* __fastcall GetItem(int Index);
	
public:
	__property TcxGridStructureControlRowViewInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxGridStructureControlRowsViewInfo(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxGridStructureControlRowsViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridStructureControlViewInfo;
class DELPHICLASS TcxGridStructureControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridStructureControlViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxGridStructureControl* FStructureControl;
	int FTextHeight;
	int FRowHeight;
	TcxGridStructureControlRowsViewInfo* FRows;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	Cxgrid::TcxCustomGrid* __fastcall GetGrid(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetLevelByIndex(int AIndex);
	void __fastcall GetLevelInfo(int AIndex, System::UnicodeString &ALevelText, System::UnicodeString &AViewText, int &ALevelIndex, bool &AIsParent, bool &AIsLast);
	int __fastcall GetRowCount(void);
	
public:
	System::Types::TRect Bounds;
	__fastcall TcxGridStructureControlViewInfo(TcxGridStructureControl* AStructureControl);
	__fastcall virtual ~TcxGridStructureControlViewInfo(void);
	void __fastcall Calculate(void);
	System::Uitypes::TColor __fastcall GetContentColor(void);
	Vcl::Graphics::TFont* __fastcall GetContentFont(void);
	System::Uitypes::TColor __fastcall GetContentFontColor(void);
	System::Uitypes::TColor __fastcall GetGridColor(bool AHighlighted);
	System::Uitypes::TColor __fastcall GetHighlightedFontColor(void);
	System::Uitypes::TColor __fastcall GetLevelColor(bool AHighlighted);
	System::Uitypes::TColor __fastcall GetRowBorderColor(TcxGridColorIndex AColorIndex, bool ASelected, bool AHighlighted);
	System::Uitypes::TColor __fastcall GetRowColor(TcxGridColorIndex AColorIndex, bool ASelected, bool AHighlighted);
	System::Uitypes::TColor __fastcall GetRowTextColor(TcxGridColorIndex AColorIndex, bool ASelected, bool AHighlighted);
	System::Uitypes::TColor __fastcall GetSelectedColor(bool AHighlighted);
	System::Uitypes::TColor __fastcall GetSelectedFontColor(void);
	System::Uitypes::TColor __fastcall GetViewColor(bool AHighlighted);
	void __fastcall Paint(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property Cxgrid::TcxCustomGrid* Grid = {read=GetGrid};
	__property TcxGridStructureControl* StructureControl = {read=FStructureControl};
	__property TcxGridStructureControlRowsViewInfo* Rows = {read=FRows};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridStructureControlSelectComponentEvent)(System::Classes::TPersistent* AObject, bool AClearSelection);

enum TcxGridStructureControlHitTest : unsigned char { htNowhere, htLevel, htView };

struct DECLSPEC_DRECORD TcxGridStructureControlHitInfo
{
public:
	TcxGridStructureControlHitTest HitTest;
	int RowIndex;
};


class PASCALIMPLEMENTATION TcxGridStructureControl : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Cxgrid::TcxCustomGrid* FGrid;
	TcxGridStructureControlHitInfo FHitInfo;
	int FLockCount;
	bool FMayFocused;
	TcxGridStructureControlHitInfo FMouseDownHitInfo;
	bool FMousePressed;
	bool FMultiSelect;
	TcxGridStructureControlViewInfo* FViewInfo;
	System::Classes::TNotifyEvent FOnDrawBackground;
	TcxGridStructureControlSelectComponentEvent FOnSelectComponent;
	System::Classes::TNotifyEvent FOnSelectionChanged;
	void __fastcall ClearSelection(void);
	void __fastcall SetGrid(Cxgrid::TcxCustomGrid* Value);
	void __fastcall SetMultiSelect(bool Value);
	
protected:
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	void __fastcall AddToSelection(System::Classes::TPersistent* AObject, bool AClearSelection);
	void __fastcall CancelPressed(const System::Types::TPoint &P);
	void __fastcall CheckMousePos(const System::Types::TPoint &P);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall DoDrawBackground(void);
	DYNAMIC void __fastcall FontChanged(void);
	System::Classes::TComponent* __fastcall GetComponentByHitInfo(const TcxGridStructureControlHitInfo &AHitInfo);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	DYNAMIC bool __fastcall MayFocus(void);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	void __fastcall SelectComponent(System::Classes::TPersistent* AObject, bool AClearSelection = true);
	virtual void __fastcall SelectionChanged(void);
	void __fastcall SetPressed(bool APressed);
	virtual void __fastcall UpdateContent(void);
	void __fastcall UpdateHighlighted(void);
	__property int LockCount = {read=FLockCount, nodefault};
	
public:
	__fastcall virtual TcxGridStructureControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridStructureControl(void);
	void __fastcall BeginUpdate(void);
	HIDESBASE void __fastcall Changed(void);
	void __fastcall EndUpdate(void);
	TcxGridStructureControlHitInfo __fastcall GetHitInfo(const System::Types::TPoint &P);
	Cxgridlevel::TcxGridLevel* __fastcall GetLevelByRowIndex(int ARowIndex);
	Cxgridlevel::TcxGridLevel* __fastcall GetSelectedLevel(void);
	void __fastcall GetSelection(System::Classes::TList* ASelectionList);
	void __fastcall GetSelectionLevels(System::Classes::TList* ASelectionList);
	int __fastcall GetSelectionLevelCount(void);
	void __fastcall GetSelectionViews(System::Classes::TList* ASelectionList);
	int __fastcall GetSelectionViewCount(void);
	void __fastcall SyncSelection(System::Classes::TList* ASelectionList);
	__property Cxgrid::TcxCustomGrid* Grid = {read=FGrid, write=SetGrid};
	__property Keys;
	__property bool MayFocused = {read=FMayFocused, write=FMayFocused, nodefault};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, nodefault};
	__property TcxGridStructureControlViewInfo* ViewInfo = {read=FViewInfo};
	__property OnKeyPress;
	__property System::Classes::TNotifyEvent OnDrawBackground = {read=FOnDrawBackground, write=FOnDrawBackground};
	__property TcxGridStructureControlSelectComponentEvent OnSelectComponent = {read=FOnSelectComponent, write=FOnSelectComponent};
	__property System::Classes::TNotifyEvent OnSelectionChanged = {read=FOnSelectionChanged, write=FOnSelectionChanged};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridStructureControl(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TcxGridLevelViewList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLevelViewList : public Cxvieweditor::TcxGridViewList
{
	typedef Cxvieweditor::TcxGridViewList inherited;
	
private:
	Cxgridlevel::TcxGridLevel* FLevel;
	
protected:
	virtual void __fastcall GetViewNames(void);
	
public:
	__fastcall TcxGridLevelViewList(Cxgridlevel::TcxGridLevel* ALevel);
	__property Cxgridlevel::TcxGridLevel* Level = {read=FLevel};
public:
	/* TcxGridViewList.Destroy */ inline __fastcall virtual ~TcxGridLevelViewList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridStructureHelper;
class PASCALIMPLEMENTATION TcxGridStructureHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Menus::TPopupMenu* FPopupMenu;
	Cxgridlevel::TcxGridLevel* FPopupMenuLevel;
	TcxGridStructureControl* FStructureControl;
	System::Classes::TNotifyEvent FOnUpdateDesigner;
	void __fastcall CreateLevelClick(System::TObject* Sender);
	void __fastcall CreateViewClick(System::TObject* Sender);
	void __fastcall SelectViewClick(System::TObject* Sender);
	void __fastcall DeleteLevelClick(System::TObject* Sender);
	void __fastcall MoveLevelClick(System::TObject* Sender);
	
protected:
	Cxgridcustomview::TcxCustomGridView* FPopupMenuView;
	Cxvieweditor::TcxCustomGridViewMenuProvider* FViewMenuProvider;
	bool __fastcall CanAddComponent(void);
	bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent);
	void __fastcall ExecuteLevelViewsMenuItem(Cxgridlevel::TcxGridLevel* ALevel, Vcl::Menus::TMenuItem* AMenuItem);
	void __fastcall FillLevelViewsMenu(Vcl::Menus::TMenuItem* AMenu, Cxgridlevel::TcxGridLevel* ALevel, System::Classes::TNotifyEvent AOnClick);
	void __fastcall StructureControlMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall UpdateDesigner(void);
	
public:
	__fastcall virtual TcxGridStructureHelper(TcxGridStructureControl* AStructureControl);
	__fastcall virtual ~TcxGridStructureHelper(void);
	__property TcxGridStructureControl* StructureControl = {read=FStructureControl};
	__property System::Classes::TNotifyEvent OnUpdateDesigner = {read=FOnUpdateDesigner, write=FOnUpdateDesigner};
};


class DELPHICLASS TcxGridStructureNavigator;
class PASCALIMPLEMENTATION TcxGridStructureNavigator : public Cxgrid::TcxCustomGridStructureNavigator
{
	typedef Cxgrid::TcxCustomGridStructureNavigator inherited;
	
private:
	Vcl::Buttons::TSpeedButton* FCloseButton;
	Vcl::Buttons::TSpeedButton* FCustomizeButton;
	Cxgridlevel::TcxGridLevel* FDefaultLevel;
	Cxgridcustomview::TcxCustomGridView* FDefaultView;
	Cxdesignwindows::TcxDesignHelper* FDesignHelper;
	bool FMakeSelectionVisible;
	System::Classes::TList* FSelection;
	Vcl::Extctrls::TBevel* FSeparator;
	TcxGridStructureControl* FStructureControl;
	TcxGridStructureHelper* FStructureHelper;
	void __fastcall CloseButtonClick(System::TObject* Sender);
	void __fastcall CustomizeButtonClick(System::TObject* Sender);
	void __fastcall UpdateDesigner(System::TObject* Sender);
	MESSAGE void __fastcall CMDeferUpdate(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall Paint(void);
	void __fastcall Calculate(void);
	virtual System::Types::TRect __fastcall CalculateBoundsRect(void);
	virtual void __fastcall Changed(void);
	void __fastcall CreateDefaultComponents(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawStructureControlBackground(System::TObject* Sender);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetDefaultViewClass(void);
	Designintf::_di_IDesigner __fastcall GetDesigner(void);
	void __fastcall SelectComponent(System::Classes::TPersistent* AObject, bool AClearSelection);
	__property bool MakeSelectionVisible = {read=FMakeSelectionVisible, write=FMakeSelectionVisible, nodefault};
	
public:
	__fastcall virtual TcxGridStructureNavigator(Cxgrid::TcxCustomGrid* AGrid);
	__fastcall virtual ~TcxGridStructureNavigator(void);
	virtual void __fastcall BeforeGridLoading(void);
	virtual bool __fastcall CanAddComponent(void);
	virtual bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent);
	virtual void __fastcall GetSelection(System::Classes::TList* AList);
	virtual bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject);
	virtual void __fastcall NotifyEditors(void);
	virtual void __fastcall SelectionChanged(System::Classes::TList* ASelection);
	virtual void __fastcall SelectObject(System::Classes::TPersistent* AObject, bool AClearSelection);
	virtual void __fastcall SelectObjects(System::Classes::TList* AObjects);
	virtual void __fastcall UnselectObject(System::Classes::TPersistent* AObject);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridStructureNavigator(HWND ParentWindow) : Cxgrid::TcxCustomGridStructureNavigator(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall GenLevelName(Cxgrid::TcxCustomGrid* AGrid, Cxgridlevel::TcxGridLevel* ALevel);
extern PACKAGE System::UnicodeString __fastcall GenViewName(System::Classes::TComponent* AOwnerComponent, Cxgridcustomview::TcxCustomGridView* AView);
extern PACKAGE void __fastcall FillRegisteredViewsMenu(Vcl::Menus::TMenuItem* AMenu, System::Classes::TNotifyEvent AOnClick);
}	/* namespace Cxgridstructurenavigator */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDSTRUCTURENAVIGATOR)
using namespace Cxgridstructurenavigator;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridstructurenavigatorHPP
