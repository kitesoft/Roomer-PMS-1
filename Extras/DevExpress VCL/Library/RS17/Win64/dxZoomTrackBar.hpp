// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxZoomTrackBar.pas' rev: 24.00 (Win64)

#ifndef DxzoomtrackbarHPP
#define DxzoomtrackbarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxTrackBar.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxzoomtrackbar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxZoomTrackBarRangeOptions;
class PASCALIMPLEMENTATION TdxZoomTrackBarRangeOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	int FFrequency;
	Cxexteditconsts::TcxNaturalNumber FLineSize;
	Cxexteditconsts::TcxNaturalNumber FPageSize;
	System::Classes::TNotifyEvent FOnChanged;
	void __fastcall DoChanged(void);
	void __fastcall SetFrequency(int Value);
	void __fastcall SetLineSize(Cxexteditconsts::TcxNaturalNumber Value);
	void __fastcall SetPageSize(Cxexteditconsts::TcxNaturalNumber Value);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TdxZoomTrackBarRangeOptions(System::Classes::TPersistent* AOwner);
	
__published:
	__property int Frequency = {read=FFrequency, write=SetFrequency, default=10};
	__property Cxexteditconsts::TcxNaturalNumber LineSize = {read=FLineSize, write=SetLineSize, default=10};
	__property Cxexteditconsts::TcxNaturalNumber PageSize = {read=FPageSize, write=SetPageSize, default=20};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxZoomTrackBarRangeOptions(void) { }
	
};


class DELPHICLASS TdxCustomZoomTrackBarViewData;
class DELPHICLASS TdxCustomZoomTrackBarProperties;
class PASCALIMPLEMENTATION TdxCustomZoomTrackBarViewData : public Cxtrackbar::TcxCustomTrackBarViewData
{
	typedef Cxtrackbar::TcxCustomTrackBarViewData inherited;
	
private:
	int __fastcall GetCenterPositionMaxDiff(void);
	int __fastcall GetMinCenterPositionDiff(void);
	HIDESBASE TdxCustomZoomTrackBarProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall CalculateTrackBarViewInfoProperties(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall CalculatePixelsPerPositionStep(Cxtrackbar::TcxCustomTrackBarViewInfo* AViewInfo);
	
public:
	__property TdxCustomZoomTrackBarProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TdxCustomZoomTrackBarViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxtrackbar::TcxCustomTrackBarViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomZoomTrackBarViewData(void) { }
	
};


class DELPHICLASS TdxCustomZoomTrackBarViewInfo;
class PASCALIMPLEMENTATION TdxCustomZoomTrackBarViewInfo : public Cxtrackbar::TcxCustomTrackBarViewInfo
{
	typedef Cxtrackbar::TcxCustomTrackBarViewInfo inherited;
	
protected:
	virtual void __fastcall PopulateMajorTicks(void);
	virtual bool __fastcall IsTickText(int ATickValue);
	virtual bool __fastcall NeedDrawTick(int AIndex);
	virtual void __fastcall PaintTrackBar(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetCalculatedPosition(int APosition, bool AIsInc, bool AIsLineSize, bool ANeedRound = false);
	virtual int __fastcall GetPositionAfterJump(int X, int Y);
	
public:
	int FrequencyLeft;
	int FrequencyRight;
	double PixelsPerPositionFirstRange;
	double PixelsPerPositionSecondRange;
	int __fastcall GetTrackRectSize(void);
	virtual int __fastcall GetOffset(int APosition);
	__property int TrackRectSize = {read=GetTrackRectSize, nodefault};
public:
	/* TcxCustomTrackBarViewInfo.Create */ inline __fastcall virtual TdxCustomZoomTrackBarViewInfo(void) : Cxtrackbar::TcxCustomTrackBarViewInfo() { }
	/* TcxCustomTrackBarViewInfo.Destroy */ inline __fastcall virtual ~TdxCustomZoomTrackBarViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxCustomZoomTrackBarProperties : public Cxtrackbar::TcxCustomTrackBarProperties
{
	typedef Cxtrackbar::TcxCustomTrackBarProperties inherited;
	
private:
	TdxZoomTrackBarRangeOptions* FFirstRange;
	TdxZoomTrackBarRangeOptions* FSecondRange;
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	void __fastcall SetFirstRange(TdxZoomTrackBarRangeOptions* Value);
	void __fastcall SetSecondRange(TdxZoomTrackBarRangeOptions* Value);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	void __fastcall RangePropertiesChanged(System::TObject* Sender);
	virtual void __fastcall SetMax(int Value);
	virtual void __fastcall SetMin(int Value);
	
public:
	__fastcall virtual TdxCustomZoomTrackBarProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxCustomZoomTrackBarProperties(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	__property TdxZoomTrackBarRangeOptions* FirstRange = {read=FFirstRange, write=SetFirstRange};
	__property Max = {default=500};
	__property Min = {default=10};
	__property TdxZoomTrackBarRangeOptions* SecondRange = {read=FSecondRange, write=SetSecondRange};
	__property ShowChangeButtons = {default=1};
	__property ShowTicks = {default=0};
	__property ThumbStep = {default=1};
	__property ThumbHeight = {default=20};
	__property ThumbWidth = {default=10};
	__property TrackSize = {default=10};
};


class DELPHICLASS TdxZoomTrackBarProperties;
class PASCALIMPLEMENTATION TdxZoomTrackBarProperties : public TdxCustomZoomTrackBarProperties
{
	typedef TdxCustomZoomTrackBarProperties inherited;
	
__published:
	__property AutoSize = {default=1};
	__property BorderWidth = {default=0};
	__property ClearKey = {default=0};
	__property FirstRange;
	__property Max = {default=500};
	__property Min = {default=10};
	__property Orientation = {default=0};
	__property ReverseDirection = {default=0};
	__property SecondRange;
	__property SelectionColor = {default=-16777203};
	__property SelectionEnd = {default=0};
	__property SelectionStart = {default=0};
	__property ShowChangeButtons = {default=1};
	__property ShowPositionHint = {default=0};
	__property ShowTicks = {default=0};
	__property ShowTrack = {default=1};
	__property TextOrientation = {default=0};
	__property ThumbColor = {default=-16777201};
	__property ThumbHeight = {default=20};
	__property ThumbHighlightColor = {default=12632256};
	__property ThumbStep = {default=1};
	__property ThumbType = {default=1};
	__property ThumbWidth = {default=10};
	__property TickColor = {default=-16777208};
	__property TickMarks = {default=2};
	__property TickSize = {default=3};
	__property TickType = {default=0};
	__property TrackColor = {default=-16777211};
	__property TrackSize = {default=10};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnGetPositionHint;
	__property OnDrawThumb;
	__property OnGetTickLabel;
	__property OnGetThumbRect;
	__property OnValidate;
public:
	/* TdxCustomZoomTrackBarProperties.Create */ inline __fastcall virtual TdxZoomTrackBarProperties(System::Classes::TPersistent* AOwner) : TdxCustomZoomTrackBarProperties(AOwner) { }
	/* TdxCustomZoomTrackBarProperties.Destroy */ inline __fastcall virtual ~TdxZoomTrackBarProperties(void) { }
	
};


class DELPHICLASS TdxCustomZoomTrackBar;
class PASCALIMPLEMENTATION TdxCustomZoomTrackBar : public Cxtrackbar::TcxCustomTrackBar
{
	typedef Cxtrackbar::TcxCustomTrackBar inherited;
	
private:
	bool FCanThumbJumpToCenter;
	HIDESBASE TdxCustomZoomTrackBarProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TdxCustomZoomTrackBarProperties* __fastcall GetProperties(void);
	HIDESBASE TdxCustomZoomTrackBarViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE void __fastcall SetProperties(TdxCustomZoomTrackBarProperties* Value);
	
protected:
	virtual int __fastcall GetPositionAfterSliding(int X, int Y);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__property TdxCustomZoomTrackBarViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxCustomZoomTrackBar(System::Classes::TComponent* AOwner)/* overload */;
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TdxCustomZoomTrackBarProperties* ActiveProperties = {read=GetActiveProperties};
	__property Position = {default=100};
	__property TdxCustomZoomTrackBarProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomTrackBar.Destroy */ inline __fastcall virtual ~TdxCustomZoomTrackBar(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxCustomZoomTrackBar(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxtrackbar::TcxCustomTrackBar(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomZoomTrackBar(HWND ParentWindow) : Cxtrackbar::TcxCustomTrackBar(ParentWindow) { }
	
};


class DELPHICLASS TdxZoomTrackBar;
class PASCALIMPLEMENTATION TdxZoomTrackBar : public TdxCustomZoomTrackBar
{
	typedef TdxCustomZoomTrackBar inherited;
	
private:
	HIDESBASE TdxZoomTrackBarProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TdxZoomTrackBarProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TdxZoomTrackBarProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TdxZoomTrackBarProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Position = {default=100};
	__property TdxZoomTrackBarProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Transparent = {default=0};
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TdxCustomZoomTrackBar.Create */ inline __fastcall virtual TdxZoomTrackBar(System::Classes::TComponent* AOwner)/* overload */ : TdxCustomZoomTrackBar(AOwner) { }
	
public:
	/* TcxCustomTrackBar.Destroy */ inline __fastcall virtual ~TdxZoomTrackBar(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxZoomTrackBar(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TdxCustomZoomTrackBar(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxZoomTrackBar(HWND ParentWindow) : TdxCustomZoomTrackBar(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxzoomtrackbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXZOOMTRACKBAR)
using namespace Dxzoomtrackbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxzoomtrackbarHPP
