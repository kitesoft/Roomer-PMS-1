// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxFcEdit.pas' rev: 24.00 (Win64)

#ifndef DxfceditHPP
#define DxfceditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <dxflchrt.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Winapi.ShellAPI.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfcedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChart;
class PASCALIMPLEMENTATION TChart : public Dxflchrt::TdxFlowChart
{
	typedef Dxflchrt::TdxFlowChart inherited;
	
public:
	/* TdxCustomFlowChart.Create */ inline __fastcall virtual TChart(System::Classes::TComponent* AOwner) : Dxflchrt::TdxFlowChart(AOwner) { }
	/* TdxCustomFlowChart.Destroy */ inline __fastcall virtual ~TChart(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TChart(HWND ParentWindow) : Dxflchrt::TdxFlowChart(ParentWindow) { }
	
};


class DELPHICLASS TConnection;
class PASCALIMPLEMENTATION TConnection : public Dxflchrt::TdxFcConnection
{
	typedef Dxflchrt::TdxFcConnection inherited;
	
public:
	/* TdxFcConnection.Create */ inline __fastcall TConnection(Dxflchrt::TdxCustomFlowChart* AOwner) : Dxflchrt::TdxFcConnection(AOwner) { }
	/* TdxFcConnection.Destroy */ inline __fastcall virtual ~TConnection(void) { }
	
};


enum TItemType : unsigned char { iObject, iConnection };

class DELPHICLASS TBuferItem;
class PASCALIMPLEMENTATION TBuferItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TObject* FObject;
	TItemType FObjectType;
	void __fastcall SetObject(System::TObject* Value);
	void __fastcall SetObjectType(TItemType Value);
	__property System::TObject* Obj = {read=FObject, write=SetObject};
	__property TItemType ObjType = {read=FObjectType, write=SetObjectType, nodefault};
public:
	/* TObject.Create */ inline __fastcall TBuferItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBuferItem(void) { }
	
};


class DELPHICLASS TUndoManager;
class PASCALIMPLEMENTATION TUndoManager : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Classes::TMemoryStream* FStream;
	Dxflchrt::TdxFlowChart* FChart;
	int FUndoSteps;
	bool FCanUndo;
	int FStep;
	System::StaticArray<int, 200> FLength;
	void __fastcall SetChart(Dxflchrt::TdxFlowChart* Value);
	void __fastcall SetUndoSteps(int Value);
	__fastcall TUndoManager(void);
	__fastcall virtual ~TUndoManager(void);
	__property int UndoSteps = {read=FUndoSteps, write=SetUndoSteps, nodefault};
	__property Dxflchrt::TdxFlowChart* Chart = {read=FChart, write=SetChart};
	__property bool CanUndo = {read=FCanUndo, nodefault};
	void __fastcall Store(void);
	void __fastcall Undo(void);
};


class DELPHICLASS TFChartEditor;
class PASCALIMPLEMENTATION TFChartEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TBevel* Bevel1;
	Vcl::Extctrls::TBevel* Bevel2;
	Vcl::Extctrls::TBevel* Bevel3;
	Vcl::Extctrls::TBevel* Bevel4;
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Buttons::TSpeedButton* btnCreateConnect;
	Vcl::Buttons::TSpeedButton* btnCreateObject;
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Extctrls::TBevel* bvlSpace1;
	Vcl::Extctrls::TBevel* bvlSpace2;
	Vcl::Extctrls::TBevel* bvlSpace3;
	Vcl::Extctrls::TBevel* bvlSpace4;
	Dxflchrt::TdxFlowChart* Chart;
	Vcl::Menus::TPopupMenu* ChartPopupMenu;
	Vcl::Dialogs::TColorDialog* ColorDialog;
	Vcl::Menus::TMenuItem* Contens1;
	Vcl::Menus::TPopupMenu* DArrowSizePopupMenu;
	Vcl::Menus::TPopupMenu* DestArrowPopupMenu;
	Vcl::Menus::TPopupMenu* DPointPopupMenu;
	Vcl::Dialogs::TFontDialog* FontDialog;
	Vcl::Menus::TMenuItem* i10p;
	Vcl::Menus::TMenuItem* i1p;
	Vcl::Menus::TMenuItem* i2p;
	Vcl::Menus::TMenuItem* i3p;
	Vcl::Menus::TMenuItem* i4p;
	Vcl::Menus::TMenuItem* i5p;
	Vcl::Menus::TMenuItem* i6p;
	Vcl::Menus::TMenuItem* i7p;
	Vcl::Menus::TMenuItem* i8p;
	Vcl::Menus::TMenuItem* i9p;
	Vcl::Menus::TMenuItem* iAddToUnion;
	Vcl::Menus::TMenuItem* iBringToFront;
	Vcl::Menus::TMenuItem* iClearAllUnions;
	Vcl::Menus::TMenuItem* iClearSelection;
	Vcl::Menus::TMenuItem* iClearUnion;
	Vcl::Menus::TMenuItem* iCopy;
	Vcl::Menus::TMenuItem* iCurved;
	Vcl::Menus::TMenuItem* iCut;
	Vcl::Menus::TMenuItem* iD10;
	Vcl::Menus::TMenuItem* iD20;
	Vcl::Menus::TMenuItem* iD30;
	Vcl::Menus::TMenuItem* iD40;
	Vcl::Menus::TMenuItem* iD50;
	Vcl::Menus::TMenuItem* iDArrow;
	Vcl::Menus::TMenuItem* iDelete;
	Vcl::Menus::TMenuItem* iDiamond;
	Vcl::Menus::TMenuItem* iDNone;
	Vcl::Menus::TMenuItem* iDOvalArrow;
	Vcl::Menus::TMenuItem* iDP1;
	Vcl::Menus::TMenuItem* iDP10;
	Vcl::Menus::TMenuItem* iDP11;
	Vcl::Menus::TMenuItem* iDP12;
	Vcl::Menus::TMenuItem* iDP13;
	Vcl::Menus::TMenuItem* iDP14;
	Vcl::Menus::TMenuItem* iDP15;
	Vcl::Menus::TMenuItem* iDP16;
	Vcl::Menus::TMenuItem* iDP2;
	Vcl::Menus::TMenuItem* iDP3;
	Vcl::Menus::TMenuItem* iDP4;
	Vcl::Menus::TMenuItem* iDP5;
	Vcl::Menus::TMenuItem* iDP6;
	Vcl::Menus::TMenuItem* iDP7;
	Vcl::Menus::TMenuItem* iDP8;
	Vcl::Menus::TMenuItem* iDP9;
	Vcl::Menus::TMenuItem* iDRectArrow;
	Vcl::Menus::TMenuItem* iEdit;
	Vcl::Menus::TMenuItem* iEllipse;
	Vcl::Menus::TMenuItem* iImageBottom;
	Vcl::Menus::TMenuItem* iImageBottomLeft;
	Vcl::Menus::TMenuItem* iImageBottomRight;
	Vcl::Menus::TMenuItem* iImageCenter;
	Vcl::Menus::TMenuItem* iImageLeft;
	Vcl::Menus::TMenuItem* iImageRight;
	Vcl::Menus::TMenuItem* iImageTop;
	Vcl::Menus::TMenuItem* iImageTopLeft;
	Vcl::Menus::TMenuItem* iImageTopRight;
	Vcl::Menus::TPopupMenu* ImagePositionPopupMenu;
	Vcl::Menus::TMenuItem* iNewUnion;
	Vcl::Menus::TMenuItem* iNone;
	Vcl::Menus::TMenuItem* iNorthTriangle;
	Vcl::Menus::TMenuItem* iPaste;
	Vcl::Menus::TMenuItem* iRectangle;
	Vcl::Menus::TMenuItem* iRectHorizontal;
	Vcl::Menus::TMenuItem* iRectVertical;
	Vcl::Menus::TMenuItem* iRemoveFromUnion;
	Vcl::Menus::TMenuItem* iRemovePoint;
	Vcl::Menus::TMenuItem* iRoundRect;
	Vcl::Menus::TMenuItem* iS10;
	Vcl::Menus::TMenuItem* iS20;
	Vcl::Menus::TMenuItem* iS30;
	Vcl::Menus::TMenuItem* iS40;
	Vcl::Menus::TMenuItem* iS50;
	Vcl::Menus::TMenuItem* iSArrow;
	Vcl::Menus::TMenuItem* iSelectAll;
	Vcl::Menus::TMenuItem* iSendToBack;
	Vcl::Menus::TMenuItem* iSNone;
	Vcl::Menus::TMenuItem* iSOvalArrow;
	Vcl::Menus::TMenuItem* iSP1;
	Vcl::Menus::TMenuItem* iSP10;
	Vcl::Menus::TMenuItem* iSP11;
	Vcl::Menus::TMenuItem* iSP12;
	Vcl::Menus::TMenuItem* iSP13;
	Vcl::Menus::TMenuItem* iSP14;
	Vcl::Menus::TMenuItem* iSP15;
	Vcl::Menus::TMenuItem* iSP16;
	Vcl::Menus::TMenuItem* iSP2;
	Vcl::Menus::TMenuItem* iSP3;
	Vcl::Menus::TMenuItem* iSP4;
	Vcl::Menus::TMenuItem* iSP5;
	Vcl::Menus::TMenuItem* iSP6;
	Vcl::Menus::TMenuItem* iSP7;
	Vcl::Menus::TMenuItem* iSP8;
	Vcl::Menus::TMenuItem* iSP9;
	Vcl::Menus::TMenuItem* iSRectArrow;
	Vcl::Menus::TMenuItem* iStraight;
	Vcl::Menus::TMenuItem* itEastTriangle;
	Vcl::Menus::TMenuItem* iTextBottom;
	Vcl::Menus::TMenuItem* iTextBottomLeft;
	Vcl::Menus::TMenuItem* iTextBottomRight;
	Vcl::Menus::TMenuItem* iTextCenter;
	Vcl::Menus::TMenuItem* iTextLeft;
	Vcl::Menus::TMenuItem* iTextRight;
	Vcl::Menus::TMenuItem* iTextTop;
	Vcl::Menus::TMenuItem* iTextTopLeft;
	Vcl::Menus::TMenuItem* iTextTopRight;
	Vcl::Menus::TMenuItem* itHexagon;
	Vcl::Menus::TMenuItem* itSouthTriangle;
	Vcl::Menus::TMenuItem* itWestTriangle;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Controls::TImageList* LargeImages;
	Vcl::Menus::TPopupMenu* LinePopupMenu;
	Vcl::Menus::TMainMenu* MainMenu;
	Vcl::Menus::TMenuItem* miActualSize;
	Vcl::Menus::TMenuItem* miAddToUnion;
	Vcl::Menus::TMenuItem* miAntialiasing;
	Vcl::Menus::TMenuItem* miBringToFront;
	Vcl::Menus::TMenuItem* miClearAllUnions;
	Vcl::Menus::TMenuItem* miClearSelection;
	Vcl::Menus::TMenuItem* miClearUnion;
	Vcl::Menus::TMenuItem* miCopy;
	Vcl::Menus::TMenuItem* miCut;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miDynamicMoving;
	Vcl::Menus::TMenuItem* miDynamicSizing;
	Vcl::Menus::TMenuItem* miEdit;
	Vcl::Menus::TMenuItem* miFile;
	Vcl::Menus::TMenuItem* miFit;
	Vcl::Menus::TMenuItem* miHelp;
	Vcl::Menus::TMenuItem* miNewUnion;
	Vcl::Menus::TMenuItem* miOpen;
	Vcl::Menus::TMenuItem* miOptions;
	Vcl::Menus::TMenuItem* miPaste;
	Vcl::Menus::TMenuItem* miRemoveFromUnion;
	Vcl::Menus::TMenuItem* miSaveAs;
	Vcl::Menus::TMenuItem* miSelectAll;
	Vcl::Menus::TMenuItem* miSendToBack;
	Vcl::Menus::TMenuItem* miUndo;
	Vcl::Menus::TMenuItem* miUnions;
	Vcl::Menus::TMenuItem* miZoomIn;
	Vcl::Menus::TMenuItem* miZoomOut;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* N10;
	Vcl::Menus::TMenuItem* N11;
	Vcl::Menus::TMenuItem* N12;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* N6;
	Vcl::Menus::TMenuItem* N7;
	Vcl::Menus::TMenuItem* N8;
	Vcl::Menus::TMenuItem* N9;
	Vcl::Dialogs::TOpenDialog* OpenDialog;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel4;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Extctrls::TPanel* Panel6;
	Vcl::Extctrls::TPanel* pAqua;
	Vcl::Extctrls::TPanel* pBk;
	Vcl::Extctrls::TPanel* pBkColor;
	Vcl::Extctrls::TPanel* pBlack;
	Vcl::Extctrls::TPanel* pBlue;
	Vcl::Extctrls::TPanel* pColor;
	Vcl::Extctrls::TPanel* pConnect;
	Vcl::Extctrls::TPanel* pFuchsia;
	Vcl::Extctrls::TPanel* pGray;
	Vcl::Extctrls::TPanel* pGreen;
	Vcl::Extctrls::TPanel* pLime;
	Vcl::Extctrls::TPanel* plPalette;
	Vcl::Extctrls::TPanel* pMarron;
	Vcl::Extctrls::TPanel* pNavy;
	Vcl::Extctrls::TPanel* pObject;
	Vcl::Extctrls::TPanel* pOlive;
	Vcl::Extctrls::TPanel* pPurple;
	Vcl::Extctrls::TPanel* pRed;
	Vcl::Extctrls::TPanel* pTeal;
	Vcl::Extctrls::TPanel* pWhite;
	Vcl::Extctrls::TPanel* pYellow;
	Vcl::Menus::TPopupMenu* SArrowSizePopupMenu;
	Vcl::Dialogs::TSaveDialog* SaveDialog;
	Vcl::Buttons::TSpeedButton* sbConnectFont;
	Vcl::Buttons::TSpeedButton* sbDArrowSize;
	Vcl::Buttons::TSpeedButton* sbDestArrow;
	Vcl::Buttons::TSpeedButton* sbDPoint;
	Vcl::Buttons::TSpeedButton* sbFit;
	Vcl::Buttons::TSpeedButton* sbImagePosition;
	Vcl::Buttons::TSpeedButton* sbLine;
	Vcl::Buttons::TSpeedButton* sbObjectFont;
	Vcl::Buttons::TSpeedButton* sbSArrowSize;
	Vcl::Buttons::TSpeedButton* sbShape;
	Vcl::Buttons::TSpeedButton* sbSourceArrow;
	Vcl::Buttons::TSpeedButton* sbSPoint;
	Vcl::Buttons::TSpeedButton* sbStyle;
	Vcl::Buttons::TSpeedButton* sbTextPosition;
	Vcl::Buttons::TSpeedButton* sbZoom;
	Vcl::Menus::TPopupMenu* ShapePopupMenu;
	Vcl::Controls::TImageList* SmallImages;
	Vcl::Menus::TPopupMenu* SourceArrowPopupMenu;
	Vcl::Menus::TPopupMenu* SPointPopupMenu;
	Vcl::Menus::TPopupMenu* StylePopupMenu;
	Vcl::Menus::TPopupMenu* TextPositionPopupMenu;
	Vcl::Menus::TMenuItem* View1;
	void __fastcall btnCreateConnectClick(System::TObject* Sender);
	void __fastcall btnCreateObjectClick(System::TObject* Sender);
	void __fastcall ChartChange(Dxflchrt::TdxCustomFlowChart* Sender, Dxflchrt::TdxFcItem* Item);
	void __fastcall ChartDblClick(System::TObject* Sender);
	void __fastcall ChartKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ChartKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ChartMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ChartMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ChartMouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ChartPopupMenuPopup(System::TObject* Sender);
	void __fastcall ChartSelected(Dxflchrt::TdxCustomFlowChart* Sender, Dxflchrt::TdxFcItem* Item);
	void __fastcall ChartSelection(Dxflchrt::TdxCustomFlowChart* Sender, Dxflchrt::TdxFcItem* Item, bool &Allow);
	void __fastcall Contens1Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall iAddToUnionClick(System::TObject* Sender);
	void __fastcall iBringToFrontClick(System::TObject* Sender);
	void __fastcall iClearAllUnionsClick(System::TObject* Sender);
	void __fastcall iClearSelectionClick(System::TObject* Sender);
	void __fastcall iClearUnionClick(System::TObject* Sender);
	void __fastcall iCopyClick(System::TObject* Sender);
	void __fastcall iCutClick(System::TObject* Sender);
	void __fastcall iDeleteClick(System::TObject* Sender);
	void __fastcall iEditClick(System::TObject* Sender);
	void __fastcall iNewUnionClick(System::TObject* Sender);
	void __fastcall iPasteClick(System::TObject* Sender);
	void __fastcall iRectangleClick(System::TObject* Sender);
	void __fastcall iRemoveFromUnionClick(System::TObject* Sender);
	void __fastcall iRemovePointClick(System::TObject* Sender);
	void __fastcall iSelectAllClick(System::TObject* Sender);
	void __fastcall iSendToBackClick(System::TObject* Sender);
	void __fastcall miActualSizeClick(System::TObject* Sender);
	void __fastcall miAntialiasingClick(System::TObject* Sender);
	void __fastcall miDynamicMovingClick(System::TObject* Sender);
	void __fastcall miDynamicSizingClick(System::TObject* Sender);
	void __fastcall miFitClick(System::TObject* Sender);
	void __fastcall miOpenClick(System::TObject* Sender);
	void __fastcall miSaveAsClick(System::TObject* Sender);
	void __fastcall miUndoClick(System::TObject* Sender);
	void __fastcall miZoomInClick(System::TObject* Sender);
	void __fastcall miZoomOutClick(System::TObject* Sender);
	void __fastcall pBlackMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall pColorClick(System::TObject* Sender);
	void __fastcall pColorDblClick(System::TObject* Sender);
	void __fastcall sbConnectFontClick(System::TObject* Sender);
	void __fastcall sbFitClick(System::TObject* Sender);
	void __fastcall sbObjectFontClick(System::TObject* Sender);
	void __fastcall sbShapeClick(System::TObject* Sender);
	void __fastcall sbZoomClick(System::TObject* Sender);
	
private:
	System::Classes::TList* Buf;
	Dxflchrt::TdxFlowChart* BufChart;
	System::Types::TPoint DownPoint;
	bool FChange;
	bool FNewObject;
	bool FPE;
	bool FSelect;
	bool FStore;
	TUndoManager* FUndo;
	Dxflchrt::TdxFcObject* LastObj;
	int OldHintHidePause;
	System::Types::TPoint OldPoint;
	int __fastcall GetImageIndexByMenuItem(Vcl::Menus::TMenuItem* Item);
	void __fastcall ChangeConnections(int Mode);
	void __fastcall ChangeObjects(int Mode);
	void __fastcall ClearBuf(void);
	void __fastcall ConAssign(Dxflchrt::TdxFcConnection* Source, Dxflchrt::TdxFcConnection* Dest);
	void __fastcall CopyToBuf(void);
	void __fastcall DrawDrag(System::Types::TPoint P1, System::Types::TPoint P2, int Mode);
	void __fastcall InitializeMenuImageIndexes(void);
	void __fastcall MultiSelect(bool ResetOldSelected, System::Types::TRect &SelectRect);
	void __fastcall ObjAssign(Dxflchrt::TdxFcObject* Source, Dxflchrt::TdxFcObject* Dest);
	void __fastcall PasteFromBuf(void);
	void __fastcall SelectLastConnect(void);
	void __fastcall SelectLastObject(void);
	void __fastcall SetGlyph(Vcl::Buttons::TSpeedButton* SB, Vcl::Menus::TPopupMenu* PM);
	void __fastcall LoadLocalizations(void);
	void __fastcall LocalizeArrowStyleMenu(Vcl::Menus::TPopupMenu* AMenu);
	void __fastcall LocalizeIndexesMenu(Vcl::Menus::TPopupMenu* AMenu, const System::UnicodeString AFormatString);
	void __fastcall LocalizeLayoutMenu(Vcl::Menus::TPopupMenu* AMenu);
	void __fastcall LocalizeShapeMenu(void);
	void __fastcall LocalizeStyleMenu(void);
	void __fastcall Changing(void);
	HIDESBASE void __fastcall Changed(void);
	
public:
	bool __fastcall CanKeyEnter(Vcl::Stdctrls::TEdit* Edit, System::WideChar Key, int MinValue, int MaxValue);
	bool __fastcall ChartHasUnions(Dxflchrt::TdxFlowChart* AChart);
	Dxflchrt::TdxFcObject* __fastcall FindAllUnions(Dxflchrt::TdxFlowChart* AChart, Dxflchrt::TdxFcObject* FromUnion);
	Dxflchrt::TdxFcObject* __fastcall FindUnions(Dxflchrt::TdxFlowChart* AChart, Dxflchrt::TdxFcObject* FromUnion, Dxflchrt::TdxFcObject* Obj);
	Dxflchrt::TdxFcObject* __fastcall GetMainItemInUnion(Dxflchrt::TdxFlowChart* AChart, Dxflchrt::TdxFcObject* Obj);
	int __fastcall GetNumberByUnion(Dxflchrt::TdxFlowChart* AChart, Dxflchrt::TdxFcObject* Obj);
	Dxflchrt::TdxFcObject* __fastcall GetUnionByNumber(Dxflchrt::TdxFlowChart* AChart, int Number);
	int __fastcall IntegerToStr(System::UnicodeString S);
	bool __fastcall IsChildItemInUnion(Dxflchrt::TdxFlowChart* AChart, Dxflchrt::TdxFcObject* Obj);
	bool __fastcall IsMainItemInUnion(Dxflchrt::TdxFcObject* Obj);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TFChartEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFChartEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFChartEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TFChartEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Word crFlChartZoomIn = System::Word(0x7d1);
static const System::Word crFlChartZoomOut = System::Word(0x7d2);
extern PACKAGE TFChartEditor* FChartEditor;
extern PACKAGE bool __fastcall ShowFlowChartEditor(Dxflchrt::TdxFlowChart* AChart, System::UnicodeString EditorCaption);
}	/* namespace Dxfcedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFCEDIT)
using namespace Dxfcedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfceditHPP
