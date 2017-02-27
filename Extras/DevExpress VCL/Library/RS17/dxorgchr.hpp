// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxorgchr.pas' rev: 24.00 (Win32)

#ifndef DxorgchrHPP
#define DxorgchrHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxorgchr
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxOcNodeClass;

enum TdxOcNodeAlign : unsigned char { caLeft, caCenter, caRight };

enum TdxOcImageAlign : unsigned char { iaNone, iaLT, iaLC, iaLB, iaRT, iaRC, iaRB, iaTL, iaTC, iaTR, iaBL, iaBC, iaBR };

enum TdxOcIvFlags : unsigned char { ivWidth, ivHeight, ivBoth };

enum TdxOcShape : unsigned char { shRectangle, shRoundRect, shEllipse, shDiamond };

enum TdxOcNodeAttachMode : unsigned char { naAdd, naAddFirst, naAddChild, naAddChildFirst, naInsert };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxOcNodeInfo
{
public:
	System::Word Width;
	System::Word Height;
	System::Uitypes::TColor Color;
	TdxOcNodeAlign Align;
	TdxOcShape Shape;
	short Index;
	TdxOcImageAlign IAlign;
};
#pragma pack(pop)


class DELPHICLASS TdxOcInplaceEdit;
class DELPHICLASS TdxCustomOrgChart;
class PASCALIMPLEMENTATION TdxOcInplaceEdit : public Vcl::Stdctrls::TCustomEdit
{
	typedef Vcl::Stdctrls::TCustomEdit inherited;
	
private:
	int FMinW;
	int FMaxW;
	int FMinH;
	int FMaxH;
	void __fastcall AdjustBounds(void);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Msg);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Msg);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	
public:
	__fastcall virtual TdxOcInplaceEdit(System::Classes::TComponent* AOwner);
	TdxCustomOrgChart* __fastcall Tree(void);
	__property MaxLength = {default=0};
	__property OEMConvert = {default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxOcInplaceEdit(HWND ParentWindow) : Vcl::Stdctrls::TCustomEdit(ParentWindow) { }
	/* TWinControl.Destroy */ inline __fastcall virtual ~TdxOcInplaceEdit(void) { }
	
};


typedef void * TdxOcNodeData;

class DELPHICLASS TdxOcNode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOcNode : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxOcNode* operator[](int Index) { return Items[Index]; }
	
private:
	TdxCustomOrgChart* FOwner;
	TdxOcNode* FParent;
	System::Classes::TList* FList;
	int FIndex;
	void *FData;
	System::Word FWidth;
	System::Word FHeight;
	int FChildrenWidth;
	int FChildrenHeight;
	bool FExpanded;
	bool FDeleting;
	TdxOcNodeAlign FChildAlign;
	TdxOcShape FShape;
	System::Uitypes::TColor FColor;
	System::UnicodeString FText;
	int FAnimX;
	int FAnimY;
	int FAnimX0;
	int FAnimY0;
	short FImageIndex;
	TdxOcImageAlign FImageAlign;
	bool FDraw;
	void __fastcall InvalidateSize(TdxOcIvFlags Flags);
	void __fastcall Enumerate(int Value);
	void __fastcall AdjustSizes(const System::UnicodeString S);
	System::Types::TRect __fastcall FullRect(void);
	int __fastcall Radius(void);
	bool __fastcall Is3D(void);
	void __fastcall FullToDisplay(System::Types::TRect &Rect);
	void __fastcall DisplayToClient(System::Types::TRect &Rect);
	System::Types::TPoint __fastcall ClientToText(System::Types::TRect &Rect);
	int __fastcall GetAbsoluteCount(void);
	TdxOcNode* __fastcall GetAbsoluteItem(int Index);
	int __fastcall GetCount(void);
	bool __fastcall GetChildren(void);
	bool __fastcall GetVisible(void);
	TdxOcNode* __fastcall GetItem(int Index);
	int __fastcall GetLevel(void);
	TdxOcNode* __fastcall GetParent(void);
	bool __fastcall GetSelected(void);
	System::Word __fastcall GetWidth(void);
	System::Word __fastcall GetHeight(void);
	void __fastcall SetExpanded(bool Value);
	void __fastcall SetChildren(bool Value);
	void __fastcall SetAlign(TdxOcNodeAlign Value);
	void __fastcall SetWidth(System::Word Value);
	void __fastcall SetHeight(System::Word Value);
	void __fastcall SetSelected(bool Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetShape(TdxOcShape Value);
	void __fastcall SetImageIndex(short Value);
	void __fastcall SetImageAlign(TdxOcImageAlign Value);
	void __fastcall InternalSetText(const System::UnicodeString Value);
	void __fastcall SetAnimXY(int LeftX, int TopY, const System::Types::TRect &Clip, bool First);
	System::Word __fastcall ExtWidth(void);
	System::Word __fastcall ExtHeight(void);
	int __fastcall ChildOffset(void);
	void __fastcall ReadChildren(System::Classes::TStream* Stream);
	void __fastcall WriteChildren(System::Classes::TStream* Stream);
	
protected:
	virtual void __fastcall SetData(void * Value);
	virtual void __fastcall SetFont(Vcl::Graphics::TFont* Font);
	virtual void __fastcall ReadData(System::Classes::TStream* Stream);
	virtual void __fastcall WriteData(System::Classes::TStream* Stream);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall SetText(const System::UnicodeString Value);
	
public:
	__fastcall virtual TdxOcNode(TdxCustomOrgChart* AOwner);
	__fastcall virtual ~TdxOcNode(void);
	void __fastcall DeleteChildren(void);
	void __fastcall Collapse(bool Recurse);
	void __fastcall Expand(bool Recurse);
	TdxOcNode* __fastcall GetFirstChild(void);
	TdxOcNode* __fastcall GetLastChild(void);
	TdxOcNode* __fastcall GetNextChild(TdxOcNode* Value);
	TdxOcNode* __fastcall GetPrevChild(TdxOcNode* Value);
	TdxOcNode* __fastcall GetNext(void);
	TdxOcNode* __fastcall GetPrev(void);
	TdxOcNode* __fastcall getNextSibling(void);
	TdxOcNode* __fastcall getPrevSibling(void);
	TdxOcNode* __fastcall GetNextVisible(void);
	TdxOcNode* __fastcall GetPrevVisible(void);
	bool __fastcall HasAsParent(TdxOcNode* Value);
	int __fastcall IndexOf(TdxOcNode* Value);
	bool __fastcall Focused(void);
	int __fastcall FullWidth(void);
	int __fastcall FullHeight(void);
	int __fastcall ChildrenWidth(void);
	int __fastcall ChildrenHeight(void);
	void __fastcall MakeVisible(void);
	void __fastcall MoveTo(TdxOcNode* Dest, TdxOcNodeAttachMode Mode);
	System::Types::TRect __fastcall DisplayRect(void);
	System::Types::TRect __fastcall ClientRect(void);
	bool __fastcall IsParentRoot(void);
	void __fastcall GetNodeInfo(TdxOcNodeInfo &AInfo);
	__property int AbsoluteCount = {read=GetAbsoluteCount, nodefault};
	__property TdxOcNode* AbsoluteItems[int Index] = {read=GetAbsoluteItem};
	__property int Count = {read=GetCount, nodefault};
	__property void * Data = {read=FData, write=SetData};
	__property bool Expanded = {read=FExpanded, write=SetExpanded, nodefault};
	__property bool HasChildren = {read=GetChildren, write=SetChildren, nodefault};
	__property int Index = {read=FIndex, nodefault};
	__property bool IsVisible = {read=GetVisible, nodefault};
	__property TdxOcNode* Items[int Index] = {read=GetItem/*, default*/};
	__property int Level = {read=GetLevel, nodefault};
	__property TdxCustomOrgChart* Owner = {read=FOwner};
	__property TdxOcNode* Parent = {read=GetParent};
	__property bool Selected = {read=GetSelected, write=SetSelected, nodefault};
	__property TdxOcNodeAlign ChildAlign = {read=FChildAlign, write=SetAlign, nodefault};
	__property System::Word Width = {read=GetWidth, write=SetWidth, nodefault};
	__property System::Word Height = {read=GetHeight, write=SetHeight, nodefault};
	__property bool Deleting = {read=FDeleting, nodefault};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property TdxOcShape Shape = {read=FShape, write=SetShape, nodefault};
	__property System::UnicodeString Text = {read=GetText, write=InternalSetText};
	__property short ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property TdxOcImageAlign ImageAlign = {read=FImageAlign, write=SetImageAlign, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxOrgChartCustomPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOrgChartCustomPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomOrgChart* FChart;
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
public:
	__fastcall virtual TdxOrgChartCustomPainter(TdxCustomOrgChart* AChart);
	virtual System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetLineColor(void);
	virtual System::Uitypes::TColor __fastcall GetNodeColor(System::Uitypes::TColor ACurrectColor, bool ASelected);
	virtual System::Uitypes::TColor __fastcall GetNodeTextColor(bool ASelected);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawFrame(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R);
	virtual void __fastcall DrawFrameDiamond(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R);
	virtual void __fastcall DrawFrameEllipse(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R);
	virtual void __fastcall DrawFrameRectangle(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R, bool ARect3D);
	virtual void __fastcall DrawFrameRoundRect(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R, int ARadius);
	virtual void __fastcall DrawLine(Cxgraphics::TcxCanvas* ACanvas, int X1, int Y1, int X2, int Y2, float AWidth);
	__property TdxCustomOrgChart* Chart = {read=FChart};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOrgChartCustomPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxOrgChartGdiPlusPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOrgChartGdiPlusPainter : public TdxOrgChartCustomPainter
{
	typedef TdxOrgChartCustomPainter inherited;
	
private:
	System::Uitypes::TColor __fastcall GetBrushColor(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	virtual void __fastcall DrawFrameDiamond(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R);
	virtual void __fastcall DrawFrameEllipse(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R);
	virtual void __fastcall DrawFrameRectangle(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R, bool ARect3D);
	virtual void __fastcall DrawFrameRoundRect(Cxgraphics::TcxCanvas* ACanvas, TdxOcNode* ANode, const System::Types::TRect &R, int ARadius);
	virtual void __fastcall DrawLine(Cxgraphics::TcxCanvas* ACanvas, int X1, int Y1, int X2, int Y2, float AWidth);
public:
	/* TdxOrgChartCustomPainter.Create */ inline __fastcall virtual TdxOrgChartGdiPlusPainter(TdxCustomOrgChart* AChart) : TdxOrgChartCustomPainter(AChart) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOrgChartGdiPlusPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxOrgChartAnimationThread;
class PASCALIMPLEMENTATION TdxOrgChartAnimationThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	TdxCustomOrgChart* FChart;
	
protected:
	void __fastcall AnimationDone(void);
	void __fastcall AnimationStep(void);
	virtual void __fastcall Execute(void);
	
public:
	__fastcall TdxOrgChartAnimationThread(TdxCustomOrgChart* AChart);
	__property TdxCustomOrgChart* Chart = {read=FChart};
public:
	/* TThread.Destroy */ inline __fastcall virtual ~TdxOrgChartAnimationThread(void) { }
	
};


typedef void __fastcall (__closure *TdxOcEvent)(System::TObject* Sender, TdxOcNode* Node);

typedef void __fastcall (__closure *TdxOcAllowEvent)(System::TObject* Sender, TdxOcNode* Node, bool &Allow);

typedef void __fastcall (__closure *TdxOcFontEvent)(System::TObject* Sender, TdxOcNode* Node, Vcl::Graphics::TFont* Font);

typedef void __fastcall (__closure *TdxOcDrawEvent)(System::TObject* Sender, TdxOcNode* Node, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &Rect);

typedef void __fastcall (__closure *TdxOcGetTextEvent)(System::TObject* Sender, TdxOcNode* Node, System::UnicodeString &Text);

typedef void __fastcall (__closure *TdxOcSetTextEvent)(System::TObject* Sender, TdxOcNode* Node, const System::UnicodeString Text);

typedef TdxOcNode* __fastcall (*TdxOcNodeFunc)(TdxOcNode* Value);

enum Dxorgchr__6 : unsigned char { emLeft, emCenter, emRight, emVCenter, emWrap, emUpper, emLower, emGrow };

typedef System::Set<Dxorgchr__6, Dxorgchr__6::emLeft, Dxorgchr__6::emGrow>  TdxOcEditMode;

enum Dxorgchr__7 : unsigned char { ocSelect, ocFocus, ocButtons, ocDblClick, ocEdit, ocCanDrag, ocShowDrag, ocInsDel, ocRect3D, ocAnimate, ocImageFiltering };

typedef System::Set<Dxorgchr__7, Dxorgchr__7::ocSelect, Dxorgchr__7::ocImageFiltering>  TdxOcOptions;

enum TdxOcHitTest : unsigned char { htNowhere, htOnLeftIndentX, htOnRightIndentX, htOnIndentY, htUnder, htOnRect, htOnShape, htOnButton };

typedef System::Set<TdxOcHitTest, TdxOcHitTest::htNowhere, TdxOcHitTest::htOnButton>  TdxOcHitTests;

enum TdxOcNavigate : unsigned char { ocnLineLeft, ocnLineUp, ocnLineRight, ocnLineDown, ocnPageLeft, ocnPageUp, ocnPageRight, ocnPageDown, ocnLeft, ocnTop, ocnRight, ocnBottom, ocnLeftPosition, ocnTopPosition, ocnSelectNextLeft, ocnSelectNextUp, ocnSelectNextRight, ocnSelectNextDown };

class PASCALIMPLEMENTATION TdxCustomOrgChart : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
public:
	TdxOcNode* operator[](int Index) { return Items[Index]; }
	
private:
	int FAnimationStep;
	System::Classes::TThread* FAnimationThread;
	bool FAntialiasing;
	Vcl::Forms::TFormBorderStyle FBorderStyle;
	TdxOcNode* FCollapsed;
	int FCount;
	TdxOcImageAlign FDefaultImageAlign;
	System::Word FDefaultNodeHeight;
	System::Word FDefaultNodeWidth;
	bool FDrag;
	TdxOcNode* FDragParent;
	int FDragX0;
	int FDragX1;
	int FDragY0;
	int FDragY1;
	TdxOcEditMode FEditMode;
	TdxOcInplaceEdit* FEditor;
	TdxOcHitTests FHitTests;
	int FHitX;
	int FHitY;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImagesChangeLink;
	System::Word FIndentX;
	System::Word FIndentY;
	bool FIsUnicode;
	int FLeftEdge;
	System::Uitypes::TColor FLineColor;
	System::Word FLineWidth;
	bool FNoAnim;
	TdxOcNode* FNodeAt;
	bool FNoScroll;
	TdxOcOptions FOptions;
	TdxOrgChartCustomPainter* FPainter;
	TdxOcNode* FRoot;
	bool FRotated;
	short FScrollX;
	short FScrollY;
	TdxOcNode* FSelected;
	System::Uitypes::TColor FSelectedNodeColor;
	System::Uitypes::TColor FSelectedNodeTextColor;
	bool FSizeChanged;
	Vcl::Extctrls::TTimer* FTimer;
	int FTopEdge;
	int FUpdate;
	bool FUpdated;
	int FZoom;
	int FZoomHi;
	int FZoomLo;
	TdxOcEvent FOnChange;
	TdxOcAllowEvent FOnChanging;
	TdxOcEvent FOnCollapsed;
	TdxOcAllowEvent FOnCollapsing;
	TdxOcEvent FOnCreateNode;
	TdxOcEvent FOnDeletion;
	TdxOcDrawEvent FOnDrawNode;
	TdxOcGetTextEvent FOnEdited;
	TdxOcAllowEvent FOnEditing;
	TdxOcEvent FOnExpanded;
	TdxOcAllowEvent FOnExpansion;
	TdxOcGetTextEvent FOnGetText;
	TdxOcFontEvent FOnSetFont;
	TdxOcSetTextEvent FOnSetText;
	void __fastcall ImageListChange(System::TObject* Sender);
	TdxOcNode* __fastcall GetAbsoluteItem(int Index);
	int __fastcall GetClientBoundsHeight(void);
	int __fastcall GetClientBoundsWidth(void);
	bool __fastcall GetEditing(void);
	System::Types::TRect __fastcall GetFullRect(void);
	System::Word __fastcall GetIndentX(void);
	System::Word __fastcall GetIndentY(void);
	TdxOcNode* __fastcall GetItem(int Index);
	int __fastcall GetLeftEdge(void);
	System::Word __fastcall GetLineWidth(void);
	int __fastcall GetRootCount(void);
	int __fastcall GetTopEdge(void);
	bool __fastcall GetZoom(void);
	void __fastcall InvalidateSizes(TdxOcIvFlags Flags);
	bool __fastcall InvalidateNode(TdxOcNode* Value);
	bool __fastcall InvalidateSel(void);
	bool __fastcall IsUpdated(void);
	bool __fastcall IsMyNode(TdxOcNode* Value);
	bool __fastcall HasButton(TdxOcNode* Node);
	bool __fastcall CanSelect(TdxOcNode* Node);
	TdxOcNode* __fastcall NextSel(TdxOcNodeFunc Get);
	System::Types::TPoint __fastcall MinSizes(void);
	void __fastcall DoAdd(TdxOcNode* AParent, TdxOcNode* ANode, int AIndex);
	void __fastcall HitTestsAt(int X, int Y);
	void __fastcall ChangeSize(void);
	void __fastcall RecalcSizes(void);
	void __fastcall SetTimeScroll(void);
	void __fastcall KillTimeScroll(void);
	void __fastcall TimeScroll(void);
	void __fastcall DoTimerScrolling(System::TObject* Sender);
	bool __fastcall InitAnimate(TdxOcNode* Node);
	void __fastcall StopAnimation(void);
	bool __fastcall DragScroll(int X, int Y, System::Uitypes::TDragState St);
	void __fastcall DragDraw(TdxCustomOrgChart* Source);
	void __fastcall DoDrawText(HDC Handle, System::UnicodeString Text, System::Types::TRect &Rect, int Flags);
	void __fastcall SetAntialiasing(bool AValue);
	void __fastcall SetLeftEdge(int Value);
	void __fastcall SetTopEdge(int Value);
	void __fastcall SetLineColor(System::Uitypes::TColor Value);
	void __fastcall SetLineWidth(System::Word Value);
	void __fastcall SetSelectedNodeColor(System::Uitypes::TColor Value);
	void __fastcall SetSelectedNodeTextColor(System::Uitypes::TColor Value);
	void __fastcall SetNodeWidth(System::Word Value);
	void __fastcall SetNodeHeight(System::Word Value);
	void __fastcall SetIndentX(System::Word Value);
	void __fastcall SetIndentY(System::Word Value);
	void __fastcall SetSelected(TdxOcNode* Value);
	void __fastcall SetZoom(bool Value);
	void __fastcall SetZoomRatio(void);
	void __fastcall SetEditing(bool Value);
	void __fastcall SetEditMode(TdxOcEditMode Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetRotated(bool Value);
	HIDESBASE void __fastcall SetBorderStyle(Vcl::Forms::TBorderStyle Value);
	void __fastcall SetOptions(TdxOcOptions Value);
	System::Types::TRect __fastcall RotateRect(const System::Types::TRect &Rect);
	void __fastcall RotatePoint(int &X, int &Y);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Msg);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Msg);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Msg);
	MESSAGE void __fastcall WMDblClk(Winapi::Messages::TWMMouse &Msg);
	MESSAGE void __fastcall WMErase(Winapi::Messages::TWMEraseBkgnd &Msg);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Msg);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateHandle(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC bool __fastcall DoMouseWheelDown(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	virtual bool __fastcall GetIsCopyDragDrop(void);
	DYNAMIC void __fastcall DragCanceled(void);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual bool __fastcall IsDefaultGesture(int AGestureID);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall Rotate(double AAngle, bool &AHandled);
	virtual void __fastcall Paint(void);
	void __fastcall PaintContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &AClipRect);
	System::Types::TPoint __fastcall PaintNode(Cxgraphics::TcxCanvas* ACanvas, Vcl::Graphics::TFont* AFont, TdxOcNode* ANode, const System::Types::TRect &AUpdateRect);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall NodeChanged(TdxOcNode* Node);
	virtual TdxOcInplaceEdit* __fastcall CreateEditor(void);
	virtual TdxOcNode* __fastcall CreateNode(void);
	virtual TdxOrgChartCustomPainter* __fastcall CreatePainter(void);
	virtual void __fastcall DoChange(TdxOcNode* Node);
	virtual void __fastcall DoChanging(TdxOcNode* Node, bool &Allow);
	void __fastcall DoNavigate(TdxOcNavigate ANavigateCode, int AValue = 0x0);
	virtual void __fastcall DrawNode(TdxOcNode* Node, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Rect);
	virtual TdxOcNodeClass __fastcall GetNodeClass(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual TdxOcNode* __fastcall InternalAdd(TdxOcNode* ParentNode, void * Data, int Idx);
	virtual void __fastcall InternalMoveTo(TdxOcNode* ParentNode, TdxOcNode* Node, int Idx);
	void __fastcall SelectNode(TdxOcNode* ANode);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	__property int AnimationStep = {read=FAnimationStep, nodefault};
	__property bool Antialiasing = {read=FAntialiasing, write=SetAntialiasing, default=0};
	__property Vcl::Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property int ClientBoundsHeight = {read=GetClientBoundsHeight, nodefault};
	__property int ClientBoundsWidth = {read=GetClientBoundsWidth, nodefault};
	__property TdxOcImageAlign DefaultImageAlign = {read=FDefaultImageAlign, write=FDefaultImageAlign, default=0};
	__property System::Word DefaultNodeHeight = {read=FDefaultNodeHeight, write=SetNodeHeight, default=40};
	__property System::Word DefaultNodeWidth = {read=FDefaultNodeWidth, write=SetNodeWidth, default=64};
	__property TdxOcEditMode EditMode = {read=FEditMode, write=SetEditMode, default=16};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property System::Word IndentX = {read=GetIndentX, write=SetIndentX, default=16};
	__property System::Word IndentY = {read=GetIndentY, write=SetIndentY, default=16};
	__property bool IsUnicode = {read=FIsUnicode, write=FIsUnicode, nodefault};
	__property System::Uitypes::TColor LineColor = {read=FLineColor, write=SetLineColor, default=536870912};
	__property System::Word LineWidth = {read=GetLineWidth, write=SetLineWidth, default=1};
	__property TdxOcOptions Options = {read=FOptions, write=SetOptions, nodefault};
	__property TdxOrgChartCustomPainter* Painter = {read=FPainter};
	__property bool Rotated = {read=FRotated, write=SetRotated, default=0};
	__property System::Uitypes::TColor SelectedNodeColor = {read=FSelectedNodeColor, write=SetSelectedNodeColor, default=536870912};
	__property System::Uitypes::TColor SelectedNodeTextColor = {read=FSelectedNodeTextColor, write=SetSelectedNodeTextColor, default=536870912};
	__property TdxOcEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TdxOcAllowEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TdxOcEvent OnCollapsed = {read=FOnCollapsed, write=FOnCollapsed};
	__property TdxOcAllowEvent OnCollapsing = {read=FOnCollapsing, write=FOnCollapsing};
	__property TdxOcEvent OnCreateNode = {read=FOnCreateNode, write=FOnCreateNode};
	__property TdxOcEvent OnDeletion = {read=FOnDeletion, write=FOnDeletion};
	__property TdxOcDrawEvent OnDrawNode = {read=FOnDrawNode, write=FOnDrawNode};
	__property TdxOcGetTextEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property TdxOcAllowEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property TdxOcEvent OnExpanded = {read=FOnExpanded, write=FOnExpanded};
	__property TdxOcAllowEvent OnExpansion = {read=FOnExpansion, write=FOnExpansion};
	__property TdxOcGetTextEvent OnGetText = {read=FOnGetText, write=FOnGetText};
	__property TdxOcFontEvent OnSetFont = {read=FOnSetFont, write=FOnSetFont};
	__property TdxOcSetTextEvent OnSetText = {read=FOnSetText, write=FOnSetText};
	
public:
	__fastcall virtual TdxCustomOrgChart(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomOrgChart(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall Invalidate(void);
	void __fastcall PaintContentTo(Vcl::Graphics::TCanvas* ACanvas, int X, int Y);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	TdxOcNode* __fastcall Add(TdxOcNode* Node, void * Data);
	TdxOcNode* __fastcall AddChild(TdxOcNode* Node, void * Data);
	TdxOcNode* __fastcall AddFirst(TdxOcNode* Node, void * Data);
	TdxOcNode* __fastcall AddChildFirst(TdxOcNode* Node, void * Data);
	void __fastcall Clear(void);
	virtual void __fastcall Delete(TdxOcNode* Node);
	HIDESBASE TdxOcNode* __fastcall Insert(TdxOcNode* Node, void * Data);
	TdxOcNode* __fastcall GetFirstNode(void);
	void __fastcall FullExpand(void);
	void __fastcall FullCollapse(void);
	int __fastcall FullWidth(void);
	int __fastcall FullHeight(void);
	bool __fastcall IsZoomed(void);
	TdxOcNode* __fastcall GetNodeAt(int X, int Y);
	TdxOcHitTests __fastcall GetHitTestsAt(int X, int Y);
	int __fastcall DoZoom(int Value);
	void __fastcall SetLeftTop(int ALeft, int ATop);
	void __fastcall DefaultDrawNode(TdxOcNode* Node, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall AssignData(TdxCustomOrgChart* Source);
	virtual void __fastcall ShowEditor(void);
	void __fastcall HideEditor(bool Save);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property TdxOcNode* AbsoluteItems[int Index] = {read=GetAbsoluteItem};
	__property int Count = {read=FCount, nodefault};
	__property TdxOcNode* DragParent = {read=FDragParent};
	__property bool Editing = {read=GetEditing, write=SetEditing, nodefault};
	__property System::Types::TRect FullRect = {read=GetFullRect};
	__property TdxOcNode* Items[int Index] = {read=GetItem/*, default*/};
	__property int LeftEdge = {read=GetLeftEdge, write=SetLeftEdge, nodefault};
	__property int RootCount = {read=GetRootCount, nodefault};
	__property TdxOcNode* RootNode = {read=FRoot};
	__property TdxOcNode* Selected = {read=FSelected, write=SetSelected};
	__property int TopEdge = {read=GetTopEdge, write=SetTopEdge, nodefault};
	__property bool Zoom = {read=GetZoom, write=SetZoom, default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomOrgChart(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxRotateClient;	/* Dxtouch::IdxRotateClient */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EAC9BA3A-C2C3-42E2-8CA8-8CEA85821CAE}
	operator Dxtouch::_di_IdxRotateClient()
	{
		Dxtouch::_di_IdxRotateClient intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxRotateClient*(void) { return (Dxtouch::IdxRotateClient*)&__IdxRotateClient; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	
};


class DELPHICLASS TdxOrgChart;
class PASCALIMPLEMENTATION TdxOrgChart : public TdxCustomOrgChart
{
	typedef TdxCustomOrgChart inherited;
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	
__published:
	__property Anchors = {default=3};
	__property Antialiasing = {default=0};
	__property BorderStyle = {default=1};
	__property DefaultImageAlign = {default=0};
	__property DefaultNodeHeight = {default=40};
	__property DefaultNodeWidth = {default=64};
	__property EditMode = {default=16};
	__property Images;
	__property IndentX = {default=16};
	__property IndentY = {default=16};
	__property LineColor = {default=536870912};
	__property LineWidth = {default=1};
	__property LookAndFeel;
	__property Rotated = {default=0};
	__property SelectedNodeColor = {default=536870912};
	__property SelectedNodeTextColor = {default=536870912};
	__property Zoom = {default=0};
	__property Options;
	__property Align = {default=0};
	__property Ctl3D;
	__property Color = {default=536870912};
	__property Enabled = {default=1};
	__property Font;
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
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
	__property ParentFont = {default=0};
	__property ParentShowHint = {default=1};
	__property ShowHint;
public:
	/* TdxCustomOrgChart.Create */ inline __fastcall virtual TdxOrgChart(System::Classes::TComponent* AOwner) : TdxCustomOrgChart(AOwner) { }
	/* TdxCustomOrgChart.Destroy */ inline __fastcall virtual ~TdxOrgChart(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxOrgChart(HWND ParentWindow) : TdxCustomOrgChart(ParentWindow) { }
	
};


class DELPHICLASS TdxOrgChartCustomCustomizeForm;
class PASCALIMPLEMENTATION TdxOrgChartCustomCustomizeForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
protected:
	TdxOcNodeInfo NodeInfo;
	virtual System::Types::TRect __fastcall CalculateFormPosition(TdxCustomOrgChart* AOrgChart);
	virtual TdxCustomOrgChart* __fastcall GetPreviewOrgChart(void) = 0 ;
	TdxOcNode* __fastcall InsertNode(void);
	TdxOcNode* __fastcall InsertSubNode(void);
	virtual void __fastcall PreparePreview(TdxCustomOrgChart* APreview, TdxCustomOrgChart* ASource);
	void __fastcall SaveChanges(TdxCustomOrgChart* AOrgChart);
	__property TdxCustomOrgChart* PreviewOrgChart = {read=GetPreviewOrgChart};
	
public:
	virtual bool __fastcall Execute(TdxCustomOrgChart* AOrgChart);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxOrgChartCustomCustomizeForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxOrgChartCustomCustomizeForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxOrgChartCustomCustomizeForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxOrgChartCustomCustomizeForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxOrgChartCustomCustomizeFormClass;

class DELPHICLASS TdxOrgChartCustomizeFormManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOrgChartCustomizeFormManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FList;
	
public:
	__fastcall virtual TdxOrgChartCustomizeFormManager(void);
	__fastcall virtual ~TdxOrgChartCustomizeFormManager(void);
	bool __fastcall Customize(TdxCustomOrgChart* AOrgChart);
	void __fastcall Register(TdxOrgChartCustomCustomizeFormClass AClass);
	void __fastcall Unregister(TdxOrgChartCustomCustomizeFormClass AClass);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 OtMaxAnimFrames = System::Int8(0x10);
static const System::Int8 OtScrollUnit = System::Int8(0x10);
extern PACKAGE TdxOrgChartCustomizeFormManager* dxOrgChartCustomizeFormManager;
extern PACKAGE bool __fastcall ShowOrgChartEditor(TdxCustomOrgChart* ATree);
}	/* namespace Dxorgchr */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXORGCHR)
using namespace Dxorgchr;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxorgchrHPP
