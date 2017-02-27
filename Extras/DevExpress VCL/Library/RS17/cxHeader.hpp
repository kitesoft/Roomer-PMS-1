// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxHeader.pas' rev: 24.00 (Win32)

#ifndef CxheaderHPP
#define CxheaderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditUtils.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxExtEditUtils.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxheader
{
//-- type declarations -------------------------------------------------------
typedef Dxcore::TdxSortOrder TcxHeaderSortOrder;

enum TcxSectionTrackState : unsigned char { tsTrackBegin, tsTrackMove, tsTrackEnd, tsTrackNone };

typedef System::DynamicArray<System::Types::TRect> TcxHeaderSectionRects;

typedef System::DynamicArray<int> TcxHeaderSectionWidths;

enum TcxHeaderState : unsigned char { hsNone, hsSized, hsDragged, hsPressed };

struct DECLSPEC_DRECORD THeaderItemInfo
{
public:
	int ImageIndex;
	System::Types::TRect Rect;
	System::Classes::TAlignment SectionAlignment;
	Dxcore::TdxSortOrder SortOrder;
	Cxlookandfeelpainters::TcxButtonState State;
	System::UnicodeString Text;
};


typedef THeaderItemInfo *PHeaderItemInfo;

class DELPHICLASS TcxCustomHeader;
class DELPHICLASS TcxHeaderSection;
typedef void __fastcall (__closure *TcxDrawSectionEvent)(TcxCustomHeader* HeaderControl, TcxHeaderSection* Section, const System::Types::TRect &ARect, bool Pressed);

typedef void __fastcall (__closure *TcxSectionNotifyEvent)(TcxCustomHeader* HeaderControl, TcxHeaderSection* Section);

typedef void __fastcall (__closure *TcxSectionTrackEvent)(TcxCustomHeader* HeaderControl, TcxHeaderSection* Section, int Width, TcxSectionTrackState State);

typedef void __fastcall (__closure *TcxSectionDragEvent)(System::TObject* Sender, TcxHeaderSection* FromSection, TcxHeaderSection* ToSection, bool &AllowDrag);

typedef void __fastcall (__closure *TcxSectionChangingSortOrderEvent)(System::TObject* Sender, TcxHeaderSection* const Section, const Dxcore::TdxSortOrder AOldSortOrder, Dxcore::TdxSortOrder &ANewSortOrder, bool &AllowChange);

typedef void __fastcall (__closure *TcxSectionChangedSortOrderEvent)(System::TObject* Sender, TcxHeaderSection* const Section, const Dxcore::TdxSortOrder ASortOrder);

struct DECLSPEC_DRECORD TDXMHeaderItemInfo
{
public:
	unsigned Msg;
	NativeInt Index;
	THeaderItemInfo *HeaderItemInfo;
	NativeInt Result;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxHeaderSection : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	bool FAllowClick;
	bool FAllowResize;
	bool FAutoSize;
	System::Classes::TBiDiMode FBiDiMode;
	int FDataIndex;
	System::Uitypes::TImageIndex FImageIndex;
	Cxexteditconsts::TcxNaturalNumber FMaxWidth;
	Cxexteditconsts::TcxNaturalNumber FMinWidth;
	bool FParentBiDiMode;
	Dxcore::TdxSortOrder FSortOrder;
	Cxlookandfeelpainters::TcxButtonState FState;
	System::UnicodeString FText;
	int FWidth;
	int __fastcall GetLeft(void);
	int __fastcall GetRight(void);
	bool __fastcall IsBiDiModeStored(void);
	bool __fastcall IsDataIndexStored(void);
	TcxCustomHeader* __fastcall GetHeaderControl(void);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetAutoSize(bool Value);
	void __fastcall SetBiDiMode(System::Classes::TBiDiMode Value);
	void __fastcall SetDataIndex(int Value);
	void __fastcall SetMaxWidth(Cxexteditconsts::TcxNaturalNumber Value);
	void __fastcall SetMinWidth(Cxexteditconsts::TcxNaturalNumber Value);
	void __fastcall SetParentBiDiMode(bool Value);
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState Value);
	void __fastcall SetText(const System::UnicodeString Value);
	void __fastcall SetWidth(int Value);
	void __fastcall SetImageIndex(const System::Uitypes::TImageIndex Value);
	void __fastcall SetSortOrder(Dxcore::TdxSortOrder Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
	
public:
	__fastcall virtual TcxHeaderSection(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ParentBiDiModeChanged(void);
	bool __fastcall UseRightToLeftAlignment(void);
	bool __fastcall UseRightToLeftReading(void);
	__property int Left = {read=GetLeft, nodefault};
	__property int Right = {read=GetRight, nodefault};
	__property TcxCustomHeader* HeaderControl = {read=GetHeaderControl};
	
__published:
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AllowClick = {read=FAllowClick, write=FAllowClick, default=0};
	__property bool AllowResize = {read=FAllowResize, write=FAllowResize, default=1};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property System::Classes::TBiDiMode BiDiMode = {read=FBiDiMode, write=SetBiDiMode, stored=IsBiDiModeStored, nodefault};
	__property int DataIndex = {read=FDataIndex, write=SetDataIndex, stored=IsDataIndexStored, nodefault};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property Cxexteditconsts::TcxNaturalNumber MaxWidth = {read=FMaxWidth, write=SetMaxWidth, default=1000};
	__property Cxexteditconsts::TcxNaturalNumber MinWidth = {read=FMinWidth, write=SetMinWidth, default=30};
	__property bool ParentBiDiMode = {read=FParentBiDiMode, write=SetParentBiDiMode, default=1};
	__property Dxcore::TdxSortOrder SortOrder = {read=FSortOrder, write=SetSortOrder, default=0};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property int Width = {read=FWidth, write=SetWidth, default=50};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxHeaderSection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxHeaderSections;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxHeaderSections : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxHeaderSection* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomHeader* FHeaderControl;
	HIDESBASE TcxHeaderSection* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxHeaderSection* Value);
	TcxHeaderSection* __fastcall GetFirstSortedSection(void);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	TcxHeaderSection* __fastcall GetSortedSection(int AIndexFrom);
	
public:
	__fastcall TcxHeaderSections(TcxCustomHeader* HeaderControl);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HIDESBASE TcxHeaderSection* __fastcall Add(void);
	HIDESBASE TcxHeaderSection* __fastcall Insert(int Index);
	__property TcxHeaderSection* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxHeaderSection* FirstSortedSection = {read=GetFirstSortedSection};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxHeaderSections(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomHeader : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	bool FAllowMultiSort;
	bool FAllowSort;
	Vcl::Graphics::TBrush* FBrush;
	bool FDragReorder;
	int FHotSectionIndex;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImagesChangeLink;
	int FLastDrawPosOnMove;
	HDC FLineDC;
	bool FLineVisible;
	bool FMouseOnSizer;
	HBRUSH FPrevBrush;
	int FPrevMousePos;
	bool FResizeUpdate;
	System::Uitypes::TCursor FScreenCursor;
	bool FScreenCursorSaved;
	bool FSectionDragged;
	TcxHeaderSections* FSections;
	System::Classes::TMemoryStream* FSectionStream;
	int FSelectedSectionIndex;
	int FSizedSectionIndex;
	TcxHeaderState FState;
	int FUnderMouseSectionIndex;
	bool FSectionsFitCalculating;
	bool FSortingChanging;
	TcxSectionNotifyEvent FOnSectionClick;
	TcxSectionNotifyEvent FOnSectionResize;
	TcxSectionNotifyEvent FOnSectionEndResize;
	TcxSectionTrackEvent FOnSectionTrack;
	TcxDrawSectionEvent FOnDrawSection;
	System::Classes::TNotifyEvent FOnSectionEndDrag;
	TcxSectionDragEvent FOnSectionDrag;
	TcxSectionChangingSortOrderEvent FOnSectionChangingSortOrder;
	TcxSectionChangedSortOrderEvent FOnSectionChangedSortOrder;
	System::Classes::TNotifyEvent FOnSectionChange;
	System::Classes::TNotifyEvent FOnSectionsChange;
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall RestoreScreenCursor(void);
	void __fastcall SetScreenCursor(System::Uitypes::TCursor ACursor);
	void __fastcall SetSections(TcxHeaderSections* Value);
	void __fastcall UpdateSection(int Index);
	void __fastcall UpdateSections(void);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetAllowMultiSort(bool Value);
	void __fastcall SetAllowSort(bool Value);
	int __fastcall GetSectionIndexAtPos(int X, int Y, bool AIncludeNonSectionPart = false);
	TcxHeaderSection* __fastcall GetSelectedSection(void);
	TcxHeaderSection* __fastcall GetSizedSection(void);
	TcxHeaderSection* __fastcall GetUnderMouseSection(void);
	bool __fastcall IsSectionIndex(int AIndex);
	void __fastcall HeaderMouseLeave(void);
	void __fastcall SetHotSectionIndex(int Value);
	void __fastcall SetMouseOnSizer(bool Value);
	void __fastcall SetSectionState(int AIndex, Cxlookandfeelpainters::TcxButtonState AState);
	void __fastcall SetSelectedSectionIndex(int Value);
	void __fastcall SetSizedSectionIndex(int Value);
	void __fastcall SetUnderMouseSectionIndex(int Value);
	void __fastcall UpdateDraggedSection(void);
	void __fastcall UpdatePressedSection(void);
	void __fastcall UpdateSizedSection(void);
	void __fastcall UpdateUnderMouseSection(void);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMCaptureChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	MESSAGE void __fastcall HDMGetItemCount(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall HDMGetItemInfo(TDXMHeaderItemInfo &Message);
	void __fastcall AllocateSplitLineDC(void);
	void __fastcall ReleaseSplitLine(void);
	void __fastcall DrawSplitLine(int XPos);
	void __fastcall InitResize(int XPos);
	__property int HotSectionIndex = {read=FHotSectionIndex, write=SetHotSectionIndex, nodefault};
	__property bool MouseOnSizer = {read=FMouseOnSizer, write=SetMouseOnSizer, nodefault};
	__property TcxHeaderSection* SelectedSection = {read=GetSelectedSection};
	__property int SelectedSectionIndex = {read=FSelectedSectionIndex, write=SetSelectedSectionIndex, nodefault};
	__property TcxHeaderSection* SizedSection = {read=GetSizedSection};
	__property int SizedSectionIndex = {read=FSizedSectionIndex, write=SetSizedSectionIndex, nodefault};
	__property TcxHeaderSection* UnderMouseSection = {read=GetUnderMouseSection};
	__property int UnderMouseSectionIndex = {read=FUnderMouseSectionIndex, write=SetUnderMouseSectionIndex, nodefault};
	
protected:
	DYNAMIC void __fastcall ChangeSectionSortOrder(TcxHeaderSection* ASection, Dxcore::TdxSortOrder ANewSortOrder, bool ADeleteOtherSorting);
	bool __fastcall DoSectionChangingSortOrder(TcxHeaderSection* ASection, Dxcore::TdxSortOrder &ANewSortOrder);
	void __fastcall DoSectionChangedSortOrder(TcxHeaderSection* ASection);
	virtual bool __fastcall DoSectionDrag(TcxHeaderSection* FromSection, TcxHeaderSection* ToSection);
	virtual void __fastcall DoSectionEndDrag(void);
	System::Types::TRect __fastcall GetSectionRect(int Index);
	virtual System::Types::TRect __fastcall GetSectionRectBySectionWidths(int AHeaderWidth, const TcxHeaderSectionWidths ASectionWidths, int AIndex);
	virtual TcxHeaderSection* __fastcall CreateSection(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	DYNAMIC void __fastcall DrawSection(int SectionIndex);
	DYNAMIC void __fastcall DoSectionClickEvent(TcxHeaderSection* Section);
	void __fastcall DoSectionChange(void);
	void __fastcall DoSectionsChange(void);
	DYNAMIC void __fastcall DoSectionDragEvent(TcxHeaderSection* FromSection, TcxHeaderSection* ToSection, bool &AllowDrag);
	DYNAMIC void __fastcall DoSectionEndDragEvent(void);
	DYNAMIC void __fastcall DoSectionResizeEvent(TcxHeaderSection* Section);
	DYNAMIC void __fastcall DoSectionEndResizeEvent(TcxHeaderSection* Section);
	DYNAMIC void __fastcall DoSectionTrackEvent(TcxHeaderSection* Section, int Width, TcxSectionTrackState State);
	virtual void __fastcall DisableSort(TcxHeaderSection* AExceptSection = (TcxHeaderSection*)(0x0));
	void __fastcall FitToClientWidth(void);
	virtual System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	System::Types::TRect __fastcall GetSectionContentBounds(const System::Types::TRect &ASectionBounds, Cxlookandfeelpainters::TcxButtonState AState);
	virtual int __fastcall GetSplitLineOffset(void);
	virtual System::Uitypes::TColor __fastcall GetTextColor(void);
	virtual bool __fastcall IsInnerControl(void);
	virtual void __fastcall Paint(void);
	__property System::Classes::TNotifyEvent OnSectionsChange = {read=FOnSectionsChange, write=FOnSectionsChange};
	
public:
	__fastcall virtual TcxCustomHeader(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomHeader(void);
	virtual void __fastcall CalcSectionWidths(int AHeaderWidth, /* out */ TcxHeaderSectionWidths &AWidths);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	int __fastcall GetAutoHeight(void);
	__property bool AllowMultiSort = {read=FAllowMultiSort, write=SetAllowMultiSort, default=1};
	__property bool AllowSort = {read=FAllowSort, write=SetAllowSort, default=1};
	__property bool DragReorder = {read=FDragReorder, write=FDragReorder, default=0};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property LookAndFeel;
	__property bool ResizeUpdate = {read=FResizeUpdate, write=FResizeUpdate, default=1};
	__property TcxHeaderSections* Sections = {read=FSections, write=SetSections};
	__property TcxDrawSectionEvent OnDrawSection = {read=FOnDrawSection, write=FOnDrawSection};
	__property System::Classes::TNotifyEvent OnSectionChange = {read=FOnSectionChange, write=FOnSectionChange};
	__property TcxSectionChangedSortOrderEvent OnSectionChangedSortOrder = {read=FOnSectionChangedSortOrder, write=FOnSectionChangedSortOrder};
	__property TcxSectionChangingSortOrderEvent OnSectionChangingSortOrder = {read=FOnSectionChangingSortOrder, write=FOnSectionChangingSortOrder};
	__property TcxSectionNotifyEvent OnSectionClick = {read=FOnSectionClick, write=FOnSectionClick};
	__property TcxSectionDragEvent OnSectionDrag = {read=FOnSectionDrag, write=FOnSectionDrag};
	__property System::Classes::TNotifyEvent OnSectionEndDrag = {read=FOnSectionEndDrag, write=FOnSectionEndDrag};
	__property TcxSectionNotifyEvent OnSectionEndResize = {read=FOnSectionEndResize, write=FOnSectionEndResize};
	__property TcxSectionNotifyEvent OnSectionResize = {read=FOnSectionResize, write=FOnSectionResize};
	__property TcxSectionTrackEvent OnSectionTrack = {read=FOnSectionTrack, write=FOnSectionTrack};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomHeader(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	
};


class DELPHICLASS TcxHeader;
class PASCALIMPLEMENTATION TcxHeader : public TcxCustomHeader
{
	typedef TcxCustomHeader inherited;
	
__published:
	__property Align = {default=0};
	__property AllowSort = {default=1};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Color = {default=-16777211};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property DragReorder = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Images;
	__property LookAndFeel;
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ResizeUpdate = {default=1};
	__property Sections;
	__property ShowHint;
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawSection;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnSectionChange;
	__property OnSectionChangedSortOrder;
	__property OnSectionChangingSortOrder;
	__property OnSectionClick;
	__property OnSectionDrag;
	__property OnSectionEndDrag;
	__property OnSectionEndResize;
	__property OnSectionResize;
	__property OnSectionTrack;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomHeader.Create */ inline __fastcall virtual TcxHeader(System::Classes::TComponent* AOwner) : TcxCustomHeader(AOwner) { }
	/* TcxCustomHeader.Destroy */ inline __fastcall virtual ~TcxHeader(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxHeader(HWND ParentWindow) : TcxCustomHeader(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall DrawHeaderSection(HWND AHeaderHandle, int AIndex, Cxgraphics::TcxCanvas* ACanvas, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, Vcl::Imglist::TCustomImageList* AImages = (Vcl::Imglist::TCustomImageList*)(0x0));
}	/* namespace Cxheader */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXHEADER)
using namespace Cxheader;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxheaderHPP
