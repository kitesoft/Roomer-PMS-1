// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTrackBar.pas' rev: 24.00 (Win32)

#ifndef CxtrackbarHPP
#define CxtrackbarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtrackbar
{
//-- type declarations -------------------------------------------------------
enum TcxTrackBarOrientation : unsigned char { tboHorizontal, tboVertical };

enum TcxTrackBarTextOrientation : unsigned char { tbtoHorizontal, tbtoVertical };

enum TcxTrackBarTickMarks : unsigned char { cxtmBoth, cxtmTopLeft, cxtmBottomRight };

enum TcxTrackBarTickType : unsigned char { tbttTicks, tbttNumbers, tbttValueNumber, tbttTicksAndNumbers };

enum TcxTrackBarMouseState : unsigned char { tbmpInControl, tbmpUnderThumb, tbmpSliding };

typedef System::Set<TcxTrackBarMouseState, TcxTrackBarMouseState::tbmpInControl, TcxTrackBarMouseState::tbmpSliding>  TcxTrackBarMouseStates;

enum TcxTrackBarSlideState : unsigned char { tbksNormal, tbksIncludeSelection };

enum TcxTrackBarThumbType : unsigned char { cxttNone, cxttRegular, cxttCustom };

enum TcxTrackBarThumbStep : unsigned char { cxtsNormal, cxtsJump };

typedef void __fastcall (__closure *TcxTrackBarGetCustomTextEvent)(System::TObject* Sender, const int APosition, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxTrackBarGetCustomHintEvent)(System::TObject* Sender, const int APosition, System::UnicodeString &AHintText, bool &ACanShow, bool &AIsHintMultiLine);

typedef void __fastcall (__closure *TcxGetThumbRectEvent)(System::TObject* Sender, System::Types::TRect &ARect);

typedef void __fastcall (__closure *TcxDrawThumbEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);

class DELPHICLASS TcxTrackBarStyle;
class PASCALIMPLEMENTATION TcxTrackBarStyle : public Cxedit::TcxEditStyle
{
	typedef Cxedit::TcxEditStyle inherited;
	
protected:
	virtual Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall DefaultBorderStyle(void);
	virtual bool __fastcall DefaultHotTrack(void);
public:
	/* TcxCustomEditStyle.Create */ inline __fastcall virtual TcxTrackBarStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, Cxcontainer::TcxContainerStyle* AParentStyle, Cxcontainer::TcxContainerStateItem AState) : Cxedit::TcxEditStyle(AOwner, ADirectAccessMode, AParentStyle, AState) { }
	
public:
	/* TcxContainerStyle.Destroy */ inline __fastcall virtual ~TcxTrackBarStyle(void) { }
	
};


class DELPHICLASS TcxCustomTrackBarFadingHelper;
class DELPHICLASS TcxCustomTrackBarViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomTrackBarFadingHelper : public Cxedit::TcxCustomEditFadingHelper
{
	typedef Cxedit::TcxCustomEditFadingHelper inherited;
	
private:
	TcxCustomTrackBarViewInfo* FViewInfo;
	
protected:
	virtual Cxedit::TcxCustomEditViewInfo* __fastcall GetEditViewInfo(void);
	
public:
	__fastcall virtual TcxCustomTrackBarFadingHelper(TcxCustomTrackBarViewInfo* AViewInfo);
	__property TcxCustomTrackBarViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxCustomTrackBarFadingHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTrackBarCustomButtonFadingHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTrackBarCustomButtonFadingHelper : public TcxCustomTrackBarFadingHelper
{
	typedef TcxCustomTrackBarFadingHelper inherited;
	
protected:
	virtual bool __fastcall CanFade(void);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState) = 0 ;
	virtual System::Types::TRect __fastcall GetButtonBounds(void) = 0 ;
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	
public:
	virtual void __fastcall Invalidate(void)/* overload */;
	__property System::Types::TRect ButtonBounds = {read=GetButtonBounds};
public:
	/* TcxCustomTrackBarFadingHelper.Create */ inline __fastcall virtual TcxTrackBarCustomButtonFadingHelper(TcxCustomTrackBarViewInfo* AViewInfo) : TcxCustomTrackBarFadingHelper(AViewInfo) { }
	
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxTrackBarCustomButtonFadingHelper(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Invalidate(const System::Types::TRect &R, bool AEraseBackground){ Cxedit::TcxCustomEditFadingHelper::Invalidate(R, AEraseBackground); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTrackBarLeftButtonFadingHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTrackBarLeftButtonFadingHelper : public TcxTrackBarCustomButtonFadingHelper
{
	typedef TcxTrackBarCustomButtonFadingHelper inherited;
	
protected:
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Types::TRect __fastcall GetButtonBounds(void);
public:
	/* TcxCustomTrackBarFadingHelper.Create */ inline __fastcall virtual TcxTrackBarLeftButtonFadingHelper(TcxCustomTrackBarViewInfo* AViewInfo) : TcxTrackBarCustomButtonFadingHelper(AViewInfo) { }
	
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxTrackBarLeftButtonFadingHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTrackBarRightButtonFadingHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTrackBarRightButtonFadingHelper : public TcxTrackBarCustomButtonFadingHelper
{
	typedef TcxTrackBarCustomButtonFadingHelper inherited;
	
protected:
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Types::TRect __fastcall GetButtonBounds(void);
public:
	/* TcxCustomTrackBarFadingHelper.Create */ inline __fastcall virtual TcxTrackBarRightButtonFadingHelper(TcxCustomTrackBarViewInfo* AViewInfo) : TcxTrackBarCustomButtonFadingHelper(AViewInfo) { }
	
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxTrackBarRightButtonFadingHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTrackBarThumbFadingHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTrackBarThumbFadingHelper : public TcxCustomTrackBarFadingHelper
{
	typedef TcxCustomTrackBarFadingHelper inherited;
	
protected:
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	
public:
	virtual void __fastcall Invalidate(void)/* overload */;
public:
	/* TcxCustomTrackBarFadingHelper.Create */ inline __fastcall virtual TcxTrackBarThumbFadingHelper(TcxCustomTrackBarViewInfo* AViewInfo) : TcxCustomTrackBarFadingHelper(AViewInfo) { }
	
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxTrackBarThumbFadingHelper(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Invalidate(const System::Types::TRect &R, bool AEraseBackground){ Cxedit::TcxCustomEditFadingHelper::Invalidate(R, AEraseBackground); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxHorizontalTrackBarViewInfoHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxHorizontalTrackBarViewInfoHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomTrackBarViewInfo* FViewInfo;
	
protected:
	virtual int __fastcall GetCurrentMousePos(int X, int Y);
	virtual int __fastcall GetMouseDownPos(void);
	virtual void __fastcall CalculateCustomThumbSize(const System::Types::TRect &ACustomRect, /* out */ int &AThumbSize, /* out */ int &AThumbLargeSize);
	void __fastcall DrawTick(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &P1, const System::Types::TPoint &P2);
	virtual void __fastcall DrawTickAsLineBottomRight(Cxgraphics::TcxCanvas* ACanvas, int ATickPosition, int ATickSize);
	virtual void __fastcall DrawTickAsLineTopLeft(Cxgraphics::TcxCanvas* ACanvas, int ATickPosition, int ATickSize);
	virtual System::Types::TRect __fastcall GetClientRect(void);
	virtual System::Types::TRect __fastcall GetLeftButtonRect(void);
	virtual System::Types::TRect __fastcall GetPositionHintTextRect(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString AHintText, bool AIsHintMultiLine);
	virtual int __fastcall GetPositionHintSize(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString AHintText);
	virtual System::Types::TRect __fastcall GetRightButtonRect(void);
	virtual System::Types::TRect __fastcall GetSelectionRect(void);
	virtual System::Types::TRect __fastcall GetTextTopRect(int ATickPosition, int ATextWidth, int ATextHeight, int ADelta);
	virtual System::Types::TRect __fastcall GetTextBottomRect(int ATickPosition, int ATextWidth, int ATextHeight, int ADelta);
	virtual System::Types::TRect __fastcall GetThumbRect(void);
	virtual System::Types::TRect __fastcall GetTrackBarRect(void);
	virtual System::Types::TRect __fastcall GetTrackBounds(void);
	virtual System::Types::TRect __fastcall GetTrackZoneRect(void);
	virtual System::Types::TRect __fastcall GetTrackRect(void);
	virtual System::Types::TRect __fastcall GetVisibleThumbRect(void);
	virtual void __fastcall InflateTrackRect(System::Types::TRect &ARect);
	__property TcxCustomTrackBarViewInfo* ViewInfo = {read=FViewInfo, write=FViewInfo};
	
public:
	__fastcall TcxHorizontalTrackBarViewInfoHelper(TcxCustomTrackBarViewInfo* AViewInfo);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxHorizontalTrackBarViewInfoHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalTrackBarViewInfoHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalTrackBarViewInfoHelper : public TcxHorizontalTrackBarViewInfoHelper
{
	typedef TcxHorizontalTrackBarViewInfoHelper inherited;
	
protected:
	virtual int __fastcall GetCurrentMousePos(int X, int Y);
	virtual int __fastcall GetMouseDownPos(void);
	virtual void __fastcall CalculateCustomThumbSize(const System::Types::TRect &ACustomRect, /* out */ int &AThumbSize, /* out */ int &AThumbLargeSize);
	virtual void __fastcall DrawTickAsLineBottomRight(Cxgraphics::TcxCanvas* ACanvas, int ATickPosition, int ATickSize);
	virtual void __fastcall DrawTickAsLineTopLeft(Cxgraphics::TcxCanvas* ACanvas, int ATickPosition, int ATickSize);
	virtual System::Types::TRect __fastcall GetClientRect(void);
	virtual System::Types::TRect __fastcall GetLeftButtonRect(void);
	virtual System::Types::TRect __fastcall GetPositionHintTextRect(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString AHintText, bool AIsHintMultiLine);
	virtual int __fastcall GetPositionHintSize(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString AHintText);
	virtual System::Types::TRect __fastcall GetRightButtonRect(void);
	virtual System::Types::TRect __fastcall GetSelectionRect(void);
	virtual System::Types::TRect __fastcall GetTextTopRect(int ATickPosition, int ATextWidth, int ATextHeight, int ADelta);
	virtual System::Types::TRect __fastcall GetTextBottomRect(int ATickPosition, int ATextWidth, int ATextHeight, int ADelta);
	virtual System::Types::TRect __fastcall GetThumbRect(void);
	virtual System::Types::TRect __fastcall GetTrackBarRect(void);
	virtual System::Types::TRect __fastcall GetTrackBounds(void);
	virtual System::Types::TRect __fastcall GetTrackZoneRect(void);
	virtual System::Types::TRect __fastcall GetTrackRect(void);
	virtual System::Types::TRect __fastcall GetVisibleThumbRect(void);
	virtual void __fastcall InflateTrackRect(System::Types::TRect &ARect);
	System::Types::TRect __fastcall GetRotatedRect(const System::Types::TRect &ARect);
public:
	/* TcxHorizontalTrackBarViewInfoHelper.Create */ inline __fastcall TcxVerticalTrackBarViewInfoHelper(TcxCustomTrackBarViewInfo* AViewInfo) : TcxHorizontalTrackBarViewInfoHelper(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalTrackBarViewInfoHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTrackBarPositionHintHelper;
class DELPHICLASS TcxCustomTrackBar;
class DELPHICLASS TcxCustomTrackBarProperties;
class PASCALIMPLEMENTATION TcxCustomTrackBarViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
private:
	TcxTrackBarLeftButtonFadingHelper* FButtonLeftFadingHelper;
	Cxlookandfeelpainters::TcxButtonState FButtonLeftState;
	TcxTrackBarRightButtonFadingHelper* FButtonRightFadingHelper;
	Cxlookandfeelpainters::TcxButtonState FButtonRightState;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TcxHorizontalTrackBarViewInfoHelper* FOrientationHelper;
	int FPosition;
	TcxTrackBarPositionHintHelper* FPositionHintHelper;
	System::Classes::TList* FMajorTicks;
	System::Classes::TList* FMinorTicks;
	bool FPropTransparent;
	int FSelectionEnd;
	int FSelectionStart;
	bool FShowSelection;
	Cxgraphics::TcxBitmap* FTBBitmap;
	TcxTrackBarThumbFadingHelper* FThumbFadingHelper;
	int FThumbHeight;
	int FThumbWidth;
	int FTrackBarState;
	int FTrackSize;
	TcxCustomTrackBar* __fastcall GetEdit(void);
	System::Types::TSize __fastcall GetLeftButtonSize(void);
	System::Types::TSize __fastcall GetRightButtonSize(void);
	TcxCustomTrackBarProperties* __fastcall GetTrackBarProperties(void);
	bool __fastcall IsMajorTick(int AIndex);
	void __fastcall SetButtonLeftState(Cxlookandfeelpainters::TcxButtonState Value);
	void __fastcall SetButtonRightState(Cxlookandfeelpainters::TcxButtonState Value);
	void __fastcall SetChangeButtonsState(int Value);
	void __fastcall SetTrackBarState(int AValue);
	
protected:
	System::Types::TRect LeftButtonRect;
	System::Types::TRect RealTrackBarRect;
	System::Types::TRect RightButtonRect;
	System::Types::TRect SelectionRect;
	System::Types::TRect ThumbRect;
	System::Types::TRect TrackBarRect;
	System::Types::TRect TrackRect;
	System::Types::TRect TrackZoneRect;
	virtual void __fastcall PopulateMajorTicks(void);
	virtual void __fastcall PopulateMinorTicks(void);
	HIDESBASE void __fastcall DrawButtons(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawButtonLeft(Cxgraphics::TcxCanvas* ACanvas)/* overload */;
	void __fastcall DrawButtonLeft(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState)/* overload */;
	void __fastcall DrawButtonRight(Cxgraphics::TcxCanvas* ACanvas)/* overload */;
	void __fastcall DrawButtonRight(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState)/* overload */;
	virtual void __fastcall DrawTrack(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawSelection(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawTickAsLine(Cxgraphics::TcxCanvas* ACanvas, int AIndex, int ATickPosition);
	void __fastcall DrawTickAsText(Cxgraphics::TcxCanvas* ACanvas, int AIndex, int ATickPosition);
	virtual void __fastcall DrawTicks(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawThumb(Cxgraphics::TcxCanvas* ACanvas)/* overload */;
	virtual void __fastcall DrawThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int AState)/* overload */;
	virtual System::Types::TRect __fastcall DrawingThumbRectToRealThumbRect(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetCoordinate(int APosition);
	virtual int __fastcall GetOffset(int APosition);
	virtual bool __fastcall IsTickText(int ATickValue);
	virtual bool __fastcall NeedDrawTick(int AIndex);
	virtual int __fastcall GetCalculatedPosition(int APosition, bool AIsInc, bool AIsLineSize, bool ANeedRound = false);
	int __fastcall GetMouseDelta(int X, int Y, const System::Types::TPoint &AMouseDownPos);
	int __fastcall GetNewPosition(int X, int Y);
	virtual int __fastcall GetPositionAfterJump(int X, int Y);
	System::UnicodeString __fastcall GetPositionHintText(bool &ACanShow, bool &AIsHintMultiLine);
	void __fastcall HidePositionHint(void);
	void __fastcall MouseMove(int X, int Y);
	void __fastcall ProcessPositionHint(void);
	void __fastcall CreateOrientationHelper(void);
	int __fastcall GetCurrentMousePos(int X, int Y);
	int __fastcall GetMouseDownPos(void);
	void __fastcall CalculateCustomThumbSize(const System::Types::TRect &ACustomRect, /* out */ int &AThumbSize, /* out */ int &AThumbLargeSize);
	void __fastcall DrawTickAsLineBottomRight(Cxgraphics::TcxCanvas* ACanvas, int ATickPosition, int ATickSize);
	void __fastcall DrawTickAsLineTopLeft(Cxgraphics::TcxCanvas* ACanvas, int ATickPosition, int ATickSize);
	System::Types::TRect __fastcall GetClientRect(void);
	System::Types::TRect __fastcall GetLeftButtonRect(void);
	System::Types::TRect __fastcall GetPositionHintTextRect(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString AHintText, bool AIsHintMultiLine);
	System::Types::TRect __fastcall GetRightButtonRect(void);
	System::Types::TRect __fastcall GetSelectionRect(void);
	System::Types::TRect __fastcall GetTextTopRect(int ATickPosition, int ATextWidth, int ATextHeight, int ADelta);
	System::Types::TRect __fastcall GetTextBottomRect(int ATickPosition, int ATextWidth, int ATextHeight, int ADelta);
	System::Types::TRect __fastcall GetThumbRect(void);
	System::Types::TRect __fastcall GetTrackBarRect(void);
	System::Types::TRect __fastcall GetTrackBounds(void);
	System::Types::TRect __fastcall GetTrackRect(void);
	System::Types::TRect __fastcall GetVisibleThumbRect(void);
	virtual void __fastcall PaintTrackBar(Cxgraphics::TcxCanvas* ACanvas);
	__property TcxTrackBarThumbFadingHelper* ThumbFadingHelper = {read=FThumbFadingHelper};
	__property System::Classes::TList* MajorTicks = {read=FMajorTicks};
	__property System::Classes::TList* MinorTicks = {read=FMinorTicks};
	
public:
	System::Types::TRect FocusRect;
	bool ReverseDirection;
	bool ShowChangeButtons;
	System::Types::TRect VisibleThumbRect;
	bool HasForegroundImage;
	TcxTrackBarMouseStates MouseStates;
	int Min;
	int Max;
	int Frequency;
	int ThumbLargeSize;
	int ThumbSize;
	System::Uitypes::TColor TickColor;
	TcxTrackBarTickMarks TickMarks;
	double PixelsPerPositionStep;
	TcxTrackBarTickType TickType;
	int TickSize;
	int TrackRectDelta;
	int TrackBarBorderWidth;
	int TrackHeight;
	int TrackWidth;
	TcxTrackBarOrientation Orientation;
	TcxTrackBarTextOrientation TextOrientation;
	__fastcall virtual TcxCustomTrackBarViewInfo(void);
	__fastcall virtual ~TcxCustomTrackBarViewInfo(void);
	virtual void __fastcall Assign(System::TObject* Source);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(Cxcontainer::TcxContainerViewInfo* AViewInfo);
	virtual bool __fastcall IsHotTrack(void)/* overload */;
	virtual bool __fastcall IsHotTrack(const System::Types::TPoint &P)/* overload */;
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property TcxCustomTrackBar* Edit = {read=GetEdit};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=FLookAndFeel};
	__property TcxTrackBarLeftButtonFadingHelper* ButtonLeftFadingHelper = {read=FButtonLeftFadingHelper};
	__property Cxlookandfeelpainters::TcxButtonState ButtonLeftState = {read=FButtonLeftState, write=SetButtonLeftState, nodefault};
	__property TcxTrackBarRightButtonFadingHelper* ButtonRightFadingHelper = {read=FButtonRightFadingHelper};
	__property Cxlookandfeelpainters::TcxButtonState ButtonRightState = {read=FButtonRightState, write=SetButtonRightState, nodefault};
	__property System::Types::TSize LeftButtonSize = {read=GetLeftButtonSize};
	__property TcxHorizontalTrackBarViewInfoHelper* OrientationHelper = {read=FOrientationHelper};
	__property int Position = {read=FPosition, write=FPosition, nodefault};
	__property TcxTrackBarPositionHintHelper* PositionHintHelper = {read=FPositionHintHelper};
	__property System::Types::TSize RightButtonSize = {read=GetRightButtonSize};
	__property int SelectionEnd = {read=FSelectionEnd, write=FSelectionEnd, nodefault};
	__property int SelectionStart = {read=FSelectionStart, write=FSelectionStart, nodefault};
	__property int ThumbHeight = {read=FThumbHeight, write=FThumbHeight, nodefault};
	__property int ThumbWidth = {read=FThumbWidth, write=FThumbWidth, nodefault};
	__property TcxCustomTrackBarProperties* TrackBarProperties = {read=GetTrackBarProperties};
	__property int TrackBarState = {read=FTrackBarState, write=SetTrackBarState, nodefault};
	__property int TrackSize = {read=FTrackSize, write=FTrackSize, nodefault};
};


class DELPHICLASS TcxCustomTrackBarViewData;
class PASCALIMPLEMENTATION TcxCustomTrackBarViewData : public Cxedit::TcxCustomEditViewData
{
	typedef Cxedit::TcxCustomEditViewData inherited;
	
private:
	void __fastcall GetCustomRealTrackZoneSize(int &ARealTrackZoneSize);
	void __fastcall GetOnGetThumbRect(/* out */ TcxGetThumbRectEvent &AValue);
	TcxCustomTrackBarProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall CalculateCustomTrackBarRects(Cxgraphics::TcxCanvas* ACanvas, TcxCustomTrackBarViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual int __fastcall CalculateTickSize(Cxgraphics::TcxCanvas* ACanvas, TcxCustomTrackBarViewInfo* AViewInfo, bool ALeftTop);
	virtual void __fastcall CalculateTrackBarViewInfoProperties(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	int __fastcall ThumbHalfSize(TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculateButtonLeftRect(TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculateButtonRightRect(TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculatePixelsPerPositionStep(TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculateSelectionRect(TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculateThumbSize(TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculateThumbRect(Cxgraphics::TcxCanvas* ACanvas, TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculateTrackBarRect(TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculateTrackRect(TcxCustomTrackBarViewInfo* AViewInfo);
	virtual void __fastcall CalculateTrackSize(TcxCustomTrackBarViewInfo* AViewInfo, int ARealTrackZoneSize);
	virtual void __fastcall CalculateTrackZoneRect(Cxgraphics::TcxCanvas* ACanvas, TcxCustomTrackBarViewInfo* AViewInfo, /* out */ int &ARealTrackZoneSize);
	void __fastcall DoOnGetThumbRect(System::Types::TRect &ARect);
	bool __fastcall IsOnGetThumbRectEventAssigned(void);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TcxCustomTrackBarProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomTrackBarViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxedit::TcxCustomEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomTrackBarViewData(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomTrackBarProperties : public Cxedit::TcxCustomEditProperties
{
	typedef Cxedit::TcxCustomEditProperties inherited;
	
private:
	bool FAutoSize;
	int FBorderWidth;
	bool FReverseDirection;
	int FFrequency;
	Cxexteditconsts::TcxNaturalNumber FLineSize;
	TcxTrackBarOrientation FOrientation;
	TcxTrackBarTextOrientation FTextOrientation;
	Cxexteditconsts::TcxNaturalNumber FPageSize;
	int FSelectionStart;
	int FSelectionEnd;
	System::Uitypes::TColor FSelectionColor;
	bool FShowPositionHint;
	bool FShowTrack;
	TcxTrackBarThumbType FThumbType;
	System::Uitypes::TColor FTickColor;
	TcxTrackBarTickType FTickType;
	TcxTrackBarTickMarks FTickMarks;
	Cxexteditconsts::TcxNaturalNumber FTickSize;
	System::Uitypes::TColor FTrackColor;
	System::Uitypes::TColor FThumbColor;
	System::Uitypes::TColor FThumbHighlightColor;
	TcxTrackBarThumbStep FThumbStep;
	TcxTrackBarGetCustomHintEvent FOnGetPositionHint;
	TcxTrackBarGetCustomTextEvent FOnGetTickLabel;
	TcxGetThumbRectEvent FOnGetThumbRect;
	TcxDrawThumbEvent FOnDrawThumb;
	void __fastcall SetAutoSize(bool Value);
	void __fastcall SetBorderWidth(int Value);
	void __fastcall SetReverseDirection(bool Value);
	void __fastcall SetFrequency(int Value);
	void __fastcall SetLineSize(Cxexteditconsts::TcxNaturalNumber Value);
	void __fastcall SetOrientation(TcxTrackBarOrientation Value);
	void __fastcall SetTextOrientation(TcxTrackBarTextOrientation Value);
	void __fastcall SetPageSize(Cxexteditconsts::TcxNaturalNumber Value);
	void __fastcall SetSelectionStart(int Value);
	void __fastcall SetSelectionEnd(int Value);
	void __fastcall SetSelectionColor(System::Uitypes::TColor Value);
	void __fastcall SetShowTicks(bool Value);
	void __fastcall SetThumbType(TcxTrackBarThumbType Value);
	void __fastcall SetShowChangeButtons(bool Value);
	void __fastcall SetShowPositionHint(bool Value);
	void __fastcall SetShowTrack(bool Value);
	void __fastcall SetTickColor(System::Uitypes::TColor Value);
	void __fastcall SetTickType(TcxTrackBarTickType Value);
	void __fastcall SetTickMarks(TcxTrackBarTickMarks Value);
	void __fastcall SetTickSize(Cxexteditconsts::TcxNaturalNumber Value);
	void __fastcall SetTrackColor(System::Uitypes::TColor Value);
	void __fastcall SetTrackSize(int Value);
	void __fastcall SetThumbHeight(int Value);
	void __fastcall SetThumbWidth(int Value);
	void __fastcall SetThumbColor(System::Uitypes::TColor Value);
	void __fastcall SetThumbHighlightColor(System::Uitypes::TColor Value);
	void __fastcall DoDrawThumb(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	
protected:
	int FMin;
	int FMax;
	bool FShowChangeButtons;
	bool FShowTicks;
	int FThumbHeight;
	int FThumbWidth;
	int FTrackSize;
	virtual bool __fastcall CanValidate(void);
	virtual System::UnicodeString __fastcall GetValidateErrorText(int AErrorKind);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual bool __fastcall HasDisplayValue(void);
	virtual int __fastcall FixPosition(const int APosition);
	int __fastcall EditValueToPosition(const System::Variant &AEditValue);
	virtual void __fastcall SetMin(int Value);
	virtual void __fastcall SetMax(int Value);
	
public:
	__fastcall virtual TcxCustomTrackBarProperties(System::Classes::TPersistent* AOwner);
	virtual bool __fastcall CanCompareEditValue(void);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	__classmethod virtual Cxedit::TcxCustomEditStyleClass __fastcall GetStyleClass();
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property int BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property bool ReverseDirection = {read=FReverseDirection, write=SetReverseDirection, default=0};
	__property int Frequency = {read=FFrequency, write=SetFrequency, default=1};
	__property Cxexteditconsts::TcxNaturalNumber LineSize = {read=FLineSize, write=SetLineSize, default=1};
	__property int Max = {read=FMax, write=SetMax, default=10};
	__property int Min = {read=FMin, write=SetMin, default=0};
	__property TcxTrackBarOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	__property Cxexteditconsts::TcxNaturalNumber PageSize = {read=FPageSize, write=SetPageSize, default=2};
	__property System::Uitypes::TColor SelectionColor = {read=FSelectionColor, write=SetSelectionColor, default=-16777203};
	__property int SelectionEnd = {read=FSelectionEnd, write=SetSelectionEnd, default=0};
	__property int SelectionStart = {read=FSelectionStart, write=SetSelectionStart, default=0};
	__property bool ShowChangeButtons = {read=FShowChangeButtons, write=SetShowChangeButtons, default=0};
	__property bool ShowPositionHint = {read=FShowPositionHint, write=SetShowPositionHint, default=0};
	__property bool ShowTicks = {read=FShowTicks, write=SetShowTicks, default=1};
	__property bool ShowTrack = {read=FShowTrack, write=SetShowTrack, default=1};
	__property TcxTrackBarTextOrientation TextOrientation = {read=FTextOrientation, write=SetTextOrientation, default=0};
	__property System::Uitypes::TColor ThumbColor = {read=FThumbColor, write=SetThumbColor, default=-16777201};
	__property int ThumbHeight = {read=FThumbHeight, write=SetThumbHeight, default=12};
	__property System::Uitypes::TColor ThumbHighlightColor = {read=FThumbHighlightColor, write=SetThumbHighlightColor, default=12632256};
	__property TcxTrackBarThumbStep ThumbStep = {read=FThumbStep, write=FThumbStep, default=0};
	__property TcxTrackBarThumbType ThumbType = {read=FThumbType, write=SetThumbType, default=1};
	__property int ThumbWidth = {read=FThumbWidth, write=SetThumbWidth, default=7};
	__property System::Uitypes::TColor TickColor = {read=FTickColor, write=SetTickColor, default=-16777208};
	__property TcxTrackBarTickMarks TickMarks = {read=FTickMarks, write=SetTickMarks, default=2};
	__property Cxexteditconsts::TcxNaturalNumber TickSize = {read=FTickSize, write=SetTickSize, default=3};
	__property TcxTrackBarTickType TickType = {read=FTickType, write=SetTickType, default=0};
	__property System::Uitypes::TColor TrackColor = {read=FTrackColor, write=SetTrackColor, default=-16777211};
	__property int TrackSize = {read=FTrackSize, write=SetTrackSize, default=5};
	__property TcxTrackBarGetCustomHintEvent OnGetPositionHint = {read=FOnGetPositionHint, write=FOnGetPositionHint};
	__property TcxTrackBarGetCustomTextEvent OnGetTickLabel = {read=FOnGetTickLabel, write=FOnGetTickLabel};
	__property TcxDrawThumbEvent OnDrawThumb = {read=FOnDrawThumb, write=FOnDrawThumb};
	__property TcxGetThumbRectEvent OnGetThumbRect = {read=FOnGetThumbRect, write=FOnGetThumbRect};
public:
	/* TcxCustomEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomTrackBarProperties(void) { }
	
};


class DELPHICLASS TcxTrackBarProperties;
class PASCALIMPLEMENTATION TcxTrackBarProperties : public TcxCustomTrackBarProperties
{
	typedef TcxCustomTrackBarProperties inherited;
	
__published:
	__property AutoSize = {default=1};
	__property BorderWidth = {default=0};
	__property ClearKey = {default=0};
	__property Frequency = {default=1};
	__property LineSize = {default=1};
	__property Max = {default=10};
	__property Min = {default=0};
	__property Orientation = {default=0};
	__property PageSize = {default=2};
	__property ReverseDirection = {default=0};
	__property SelectionColor = {default=-16777203};
	__property SelectionEnd = {default=0};
	__property SelectionStart = {default=0};
	__property ShowChangeButtons = {default=0};
	__property ShowPositionHint = {default=0};
	__property ShowTicks = {default=1};
	__property ShowTrack = {default=1};
	__property TextOrientation = {default=0};
	__property ThumbColor = {default=-16777201};
	__property ThumbHeight = {default=12};
	__property ThumbHighlightColor = {default=12632256};
	__property ThumbStep = {default=0};
	__property ThumbType = {default=1};
	__property ThumbWidth = {default=7};
	__property TickColor = {default=-16777208};
	__property TickMarks = {default=2};
	__property TickSize = {default=3};
	__property TickType = {default=0};
	__property TrackColor = {default=-16777211};
	__property TrackSize = {default=5};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnGetPositionHint;
	__property OnDrawThumb;
	__property OnGetTickLabel;
	__property OnGetThumbRect;
	__property OnValidate;
public:
	/* TcxCustomTrackBarProperties.Create */ inline __fastcall virtual TcxTrackBarProperties(System::Classes::TPersistent* AOwner) : TcxCustomTrackBarProperties(AOwner) { }
	
public:
	/* TcxCustomEditProperties.Destroy */ inline __fastcall virtual ~TcxTrackBarProperties(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTrackBarPositionHintHelper : public Dxcustomhint::TcxControlHintHelper
{
	typedef Dxcustomhint::TcxControlHintHelper inherited;
	
private:
	Cxclasses::TcxTimer* FPositionHintHidingTimer;
	TcxCustomTrackBarViewInfo* FTrackBarViewInfo;
	void __fastcall PositionHintHidingTimerHandler(System::TObject* Sender);
	
protected:
	virtual bool __fastcall CanShowHint(void);
	virtual void __fastcall CorrectHintWindowRect(System::Types::TRect &ARect);
	virtual Cxcontrols::TcxControl* __fastcall GetOwnerControl(void);
	virtual void __fastcall MouseLeave(void);
	
public:
	__fastcall TcxTrackBarPositionHintHelper(TcxCustomTrackBarViewInfo* AViewInfo);
	__fastcall virtual ~TcxTrackBarPositionHintHelper(void);
	void __fastcall DisableTimer(void);
	void __fastcall HidePositionHint(void);
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomTrackBar : public Cxedit::TcxCustomEdit
{
	typedef Cxedit::TcxCustomEdit inherited;
	
private:
	bool FIsMouseDownOnLeftButton;
	bool FIsMouseDownOnRightButton;
	TcxTrackBarSlideState FSlideState;
	int FStartSelectionPosition;
	int FStoredPosition;
	Cxclasses::TcxTimer* FTimer;
	void __fastcall CreateTimer(void);
	void __fastcall DestroyTimer(void);
	HIDESBASE TcxTrackBarStyle* __fastcall GetStyle(void);
	HIDESBASE void __fastcall SetStyle(TcxTrackBarStyle* Value);
	void __fastcall SetNewSelectionPosition(const int ANewPosition);
	int __fastcall GetPosition(void);
	void __fastcall SetPosition(int Value);
	TcxCustomTrackBarProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomTrackBarProperties* __fastcall GetActiveProperties(void);
	void __fastcall GetOnGetThumbRect(/* out */ TcxGetThumbRectEvent &AValue);
	HIDESBASE TcxCustomTrackBarViewInfo* __fastcall GetViewInfo(void);
	void __fastcall HandleTimer(System::TObject* Sender);
	int __fastcall PressButton(bool AIsInc);
	void __fastcall ProcessButtons(int &ANewPosition, int X, int Y);
	HIDESBASE void __fastcall SetProperties(TcxCustomTrackBarProperties* Value);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	
protected:
	virtual bool __fastcall DefaultParentColor(void);
	virtual void __fastcall DoValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError);
	virtual System::UnicodeString __fastcall GetDisplayValue(void);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InternalSetDisplayValue(const System::Variant &Value);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall PopulateSizeProperties(Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	virtual void __fastcall SetInternalDisplayValue(const System::Variant &Value);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual bool __fastcall WantNavigationKeys(void);
	virtual int __fastcall GetPositionAfterSliding(int X, int Y);
	void __fastcall InternalSetPosition(int Value);
	__property int StoredPosition = {read=FStoredPosition, write=FStoredPosition, nodefault};
	__property TcxCustomTrackBarViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual ~TcxCustomTrackBar(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxCustomTrackBarProperties* ActiveProperties = {read=GetActiveProperties};
	__property int Position = {read=GetPosition, write=SetPosition, default=0};
	__property TcxCustomTrackBarProperties* Properties = {read=GetProperties, write=SetProperties};
	__property TcxTrackBarStyle* Style = {read=GetStyle, write=SetStyle};
	__property Transparent = {default=0};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomTrackBar(System::Classes::TComponent* AOwner)/* overload */ : Cxedit::TcxCustomEdit(AOwner) { }
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomTrackBar(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxedit::TcxCustomEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomTrackBar(HWND ParentWindow) : Cxedit::TcxCustomEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxTrackBar;
class PASCALIMPLEMENTATION TcxTrackBar : public TcxCustomTrackBar
{
	typedef TcxCustomTrackBar inherited;
	
private:
	HIDESBASE TcxTrackBarProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxTrackBarProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxTrackBarProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxTrackBarProperties* ActiveProperties = {read=GetActiveProperties};
	
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
	__property Position = {default=0};
	__property TcxTrackBarProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomTrackBar.Destroy */ inline __fastcall virtual ~TcxTrackBar(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxTrackBar(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomTrackBar(AOwner) { }
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxTrackBar(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomTrackBar(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTrackBar(HWND ParentWindow) : TcxCustomTrackBar(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxtrackbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTRACKBAR)
using namespace Cxtrackbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtrackbarHPP
