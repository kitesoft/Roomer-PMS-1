// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSDesigner.pas' rev: 24.00 (Win64)

#ifndef CxssdesignerHPP
#define CxssdesignerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Grids.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxSSheet.hpp>	// Pascal unit
#include <cxSSStyles.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxSSCtrls.hpp>	// Pascal unit
#include <cxSSColorBox.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit
#include <cxSSPainterWrapper.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssdesigner
{
//-- type declarations -------------------------------------------------------
enum TChangeStyleItemType : unsigned char { itHorzAlign, itVertAlign, itWordWrap, itFont, itBorderNone, itBorderOutline, itBorderInside, itBorderTop, itBorderVCenter, itBorderBottom, itBorderLeft, itBorderHCenter, itBorderRight, itPatternColor, itPatternStyle, itStyle };

typedef System::Set<TChangeStyleItemType, TChangeStyleItemType::itHorzAlign, TChangeStyleItemType::itStyle>  TChangeStyleItemsType;

class DELPHICLASS TcxSSStyleDesigner;
class PASCALIMPLEMENTATION TcxSSStyleDesigner : public Cxssheet::TcxSSFormatDialog
{
	typedef Cxssheet::TcxSSFormatDialog inherited;
	
__published:
	Vcl::Stdctrls::TButton* btnOk;
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Stdctrls::TButton* btnFont;
	Vcl::Buttons::TBitBtn* btnTop;
	Vcl::Buttons::TBitBtn* btnVMiddle;
	Vcl::Buttons::TBitBtn* btnDown;
	Vcl::Buttons::TBitBtn* btnRight;
	Vcl::Buttons::TBitBtn* btnMiddle;
	Vcl::Buttons::TBitBtn* btnLeft;
	Vcl::Buttons::TBitBtn* btnNone;
	Vcl::Buttons::TBitBtn* btnOuter;
	Vcl::Buttons::TBitBtn* btnInner;
	Cxssctrls::TcxLabelBevel* bvlBorders;
	Cxssctrls::TcxLabelBevel* bvlTextAlignment;
	Cxssctrls::TcxLabelBevel* bvlTextControl;
	Cxssctrls::TcxLabelBevel* bvlItems;
	Cxssctrls::TcxLabelBevel* bvlCellShading;
	Cxsscolorbox::TcxSSColorComboBox* cbxBorderColor;
	Cxsscolorbox::TcxSSColorComboBox* cbxPattern;
	Vcl::Stdctrls::TComboBox* cbxHorzAlign;
	Vcl::Stdctrls::TComboBox* cbxVertAlign;
	Vcl::Stdctrls::TCheckBox* chxWordWrap;
	Cxsscolorbox::TcxSSColorPanel* cplPatColor;
	Vcl::Grids::TDrawGrid* drwgLineStyle;
	Vcl::Stdctrls::TGroupBox* gbPatSample;
	Vcl::Stdctrls::TGroupBox* gbFontSample;
	Vcl::Stdctrls::TGroupBox* gbBorderStyle;
	Vcl::Stdctrls::TLabel* lbNone;
	Vcl::Stdctrls::TLabel* lbOuter;
	Vcl::Stdctrls::TLabel* lbInner;
	Vcl::Stdctrls::TLabel* lbPatColor;
	Vcl::Stdctrls::TLabel* lbPattern;
	Vcl::Stdctrls::TLabel* lbStyle;
	Vcl::Stdctrls::TLabel* lbColor;
	Vcl::Stdctrls::TLabel* lbHorzAlign;
	Vcl::Stdctrls::TLabel* lbVertAlign;
	Vcl::Comctrls::TPageControl* pcSheets;
	Cxssctrls::TcxPaintPanel* ppFontPaint;
	Cxssctrls::TcxPaintPanel* ppPaintBorders;
	Cxssctrls::TcxPaintPanel* ppPattern;
	Vcl::Comctrls::TTabSheet* tbsCellStyle;
	Vcl::Comctrls::TTabSheet* tbsAlign;
	Vcl::Comctrls::TTabSheet* tbsBorder;
	Vcl::Comctrls::TTabSheet* tbsPatterns;
	Vcl::Dialogs::TFontDialog* FontDialog;
	Vcl::Stdctrls::TRadioButton* rbNumber;
	Vcl::Stdctrls::TRadioButton* rbDateTime;
	Vcl::Stdctrls::TRadioButton* rbText;
	Vcl::Stdctrls::TGroupBox* gbStyleSet;
	Vcl::Stdctrls::TRadioButton* rbCurrency;
	Vcl::Stdctrls::TLabel* lbStyleDescription;
	Cxssctrls::TcxSSStyleListBox* lbStyleTypes;
	Vcl::Stdctrls::TGroupBox* gbStyle;
	Vcl::Stdctrls::TRadioButton* rbGeneral;
	void __fastcall OnbtnFontClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall OnClickBorderButtons(System::TObject* Sender);
	void __fastcall ppPaintBordersPaint(Cxssctrls::TcxPaintPanel* Sender);
	void __fastcall ppPaintBordersMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall OnAlignmentChange(System::TObject* Sender);
	void __fastcall ppFontPaintPaint(Cxssctrls::TcxPaintPanel* Sender);
	void __fastcall drwgLineStyleDrawCell(System::TObject* Sender, int ACol, int ARow, System::Types::TRect &Rect, Vcl::Grids::TGridDrawState State);
	void __fastcall ppPatternPaint(Cxssctrls::TcxPaintPanel* Sender);
	void __fastcall OnPatternChange(System::TObject* Sender);
	void __fastcall drwgLineStyleSelectCell(System::TObject* Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall rbStyleTypeClick(System::TObject* Sender);
	
private:
	Cxsspainterwrapper::TcxCanvasWrapper* FCanvasWrapper;
	System::Types::TRect FCells;
	TChangeStyleItemsType FChangeItems;
	Cxsstypes::TcxSSEdgeLineStyle FCurrentLineStyle;
	int FCurrentStyle;
	bool FIsLoaded;
	int FHeightCellSize;
	System::StaticArray<Cxsstypes::TcxSSEdgeStyleRec, 3> FHorzBorders;
	int FHorzCount;
	System::StaticArray<System::Types::TRect, 3> FHorzVertex;
	Cxssheet::TcxSSBookSheet* FSheet;
	System::StaticArray<Cxsstypes::TcxSSEdgeStyleRec, 3> FVertBorders;
	int FVertCount;
	System::StaticArray<System::Types::TRect, 3> FVertVertex;
	int FWidthCellSize;
	bool __fastcall GetIsChange(TChangeStyleItemType AItem);
	void __fastcall SetStyleInfo(Cxssstyles::TcxSSCellStyle* AStyle);
	void __fastcall SetVertexInfo(void);
	
protected:
	void __fastcall AssignStyle(Cxssstyles::TcxSSCellStyle* AStyle, Cxssstyles::TcxSSCellStyle* AStyle2);
	void __fastcall Change(System::TObject* Sender);
	void __fastcall CheckChanges(void);
	void __fastcall CloseDesigner(void);
	void __fastcall FormatChanged(System::TObject* Sender, int StyleValue);
	void __fastcall InitializeInformation(Cxssstyles::TcxSSCellStyle* AStyle);
	virtual void __fastcall OnKeyDownHandler(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	HIDESBASE void __fastcall SetBorderStyle(System::Types::TRect &AVertex, Cxsstypes::TcxSSEdgeStyleRec &ABorder, Cxsstypes::TcxSSEdgeLineStyle AStyle, System::Word AColor, bool SetAlways = false);
	void __fastcall SetButtonState(bool IsMultiRow, bool IsMultiCol);
	__property bool IsChange[TChangeStyleItemType AItem] = {read=GetIsChange};
	__property bool IsLoaded = {read=FIsLoaded, write=FIsLoaded, nodefault};
	
public:
	__fastcall virtual TcxSSStyleDesigner(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSSStyleDesigner(void);
	HIDESBASE bool __fastcall Execute(Cxssstyles::TcxSSCellStyle* ADefaultStyle)/* overload */;
	virtual bool __fastcall Execute(const System::Types::TRect &ACells, Cxssheet::TcxSSBookSheet* ASheet)/* overload */;
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSSStyleDesigner(System::Classes::TComponent* AOwner, int Dummy) : Cxssheet::TcxSSFormatDialog(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSSStyleDesigner(HWND ParentWindow) : Cxssheet::TcxSSFormatDialog(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxssdesigner */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSDESIGNER)
using namespace Cxssdesigner;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssdesignerHPP
