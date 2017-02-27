// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxProgressBar.pas' rev: 24.00 (Win64)

#ifndef CxprogressbarHPP
#define CxprogressbarHPP

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
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxprogressbar
{
//-- type declarations -------------------------------------------------------
typedef System::Word TcxBorderWidth;

typedef System::Int8 TcxProgressBarAnimationSpeed;

enum TcxProgressBarBevelOuter : unsigned char { cxbvNone, cxbvLowered, cxbvRaised };

enum TcxProgressBarOrientation : unsigned char { cxorHorizontal, cxorVertical };

enum TcxProgressBarTextStyle : unsigned char { cxtsPercent, cxtsPosition, cxtsText };

enum TcxProgressBarBarStyle : unsigned char { cxbsSolid, cxbsLEDs, cxbsGradient, cxbsGradientLEDs, cxbsBitmap, cxbsBitmapLEDs, cxbsAnimation, cxbsAnimationLEDs };

enum TcxProgressBarAnimationPath : unsigned char { cxapCycle, cxapPingPong };

class DELPHICLASS TcxCustomProgressBarViewInfo;
class PASCALIMPLEMENTATION TcxCustomProgressBarViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
private:
	TcxProgressBarAnimationPath FAnimationPath;
	unsigned FAnimationRestartDelay;
	int FAnimationPosition;
	int FAnimationDirection;
	unsigned FAnimationSpeed;
	Cxclasses::TcxTimer* FAnimationTimer;
	Cxclasses::TcxTimer* FAnimationRestartDelayTimer;
	System::Uitypes::TColor FBeginColor;
	TcxProgressBarBevelOuter FBarBevelOuter;
	Cxgraphics::TcxBitmap* FUsualBitmap;
	Cxgraphics::TcxBitmap* FPainterBitmap;
	System::Uitypes::TColor FEndColor;
	bool FMarquee;
	double FMax;
	double FMin;
	Vcl::Graphics::TBitmap* FNativeBitmap;
	double FPosition;
	Vcl::Graphics::TBitmap* FForegroundImage;
	TcxProgressBarOrientation FOrientation;
	bool FShowText;
	TcxProgressBarTextStyle FShowTextStyle;
	TcxProgressBarOrientation FTextOrientation;
	bool FSolidTextColor;
	TcxProgressBarBarStyle FBarStyle;
	double FOverloadValue;
	System::Uitypes::TColor FOverloadBeginColor;
	System::Uitypes::TColor FOverloadEndColor;
	bool FShowOverload;
	double FPeakValue;
	System::Uitypes::TColor FPeakColor;
	Cxexteditconsts::TcxNaturalNumber FPeakSize;
	bool FShowPeak;
	bool FRealShowOverload;
	bool FRealShowPeak;
	bool FPropTransparent;
	void __fastcall CalcDrawingParams(/* out */ System::Types::TRect &ADrawProgressBarRect, /* out */ System::Types::TRect &ADrawOverloadBarRect, /* out */ System::Types::TRect &ADrawPeakBarRect, /* out */ System::Types::TRect &ADrawAnimationBarRect, /* out */ System::Types::TRect &ASolidRect, /* out */ int &ALEDsWidth);
	bool __fastcall CanAnimationBarShow(void);
	void __fastcall CreateBarBmp(void);
	void __fastcall CreateNativeBitmap(const System::Types::TSize ASize);
	void __fastcall CreatePainterBitmap(void);
	void __fastcall ExcludeRects(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	void __fastcall ExcludeLEDRects(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	double __fastcall GetMaxMinDiff(void);
	double __fastcall GetRelativeOverloadValue(void);
	double __fastcall GetRelativePeakValue(void);
	double __fastcall GetRelativePosition(void);
	bool __fastcall IsLEDStyle(void);
	HIDESBASE void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, Cxgraphics::TcxCanvas* const ACanvasParent, const System::Types::TRect &ABounds);
	int __fastcall GetDrawDelta(void);
	System::UnicodeString __fastcall GetDrawText(void);
	bool __fastcall GetIsDoubleBuffered(void);
	void __fastcall DrawBarCaption(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall PaintBarBevelOuter(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ABBORect);
	void __fastcall DrawBarBitmap(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect);
	void __fastcall DrawGradientBar(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ANormalRect, const System::Types::TRect &AOverloadRect, const System::Types::TRect &ABarRect);
	void __fastcall DrawSolidBar(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ANormalRect, const System::Types::TRect &AOverloadRect);
	void __fastcall DrawAnimationBar(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABar, const System::Types::TRect &ASolidRect);
	void __fastcall DrawAnimationBarBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ASolidRect, System::Uitypes::TColor ASolidColor, bool ADrawBar);
	int __fastcall CalcLEDsWidth(void);
	void __fastcall AdjustForLEDsBarBounds(System::Types::TRect &ABarRect, System::Types::TRect &AOverloadBarRect, const int ALEDsWidth);
	void __fastcall DrawPeak(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &APeakRect);
	void __fastcall DrawBorderLEDs(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABarRect, int ALEDsWidth);
	void __fastcall SetBarStyle(TcxProgressBarBarStyle AValue);
	void __fastcall SetOrientation(TcxProgressBarOrientation AValue);
	void __fastcall SetMarquee(bool AValue);
	int __fastcall GetAnimationLength(void);
	unsigned __fastcall GetAnimationTimerInterval(void);
	int __fastcall GetAnimationOffset(void);
	System::Types::TRect __fastcall GetCorrectAnimationBarRect(void);
	void __fastcall CalcAnimationCurrentPosition(void);
	void __fastcall DoAnimationTimer(System::TObject* Sender);
	void __fastcall DoAnimationRestartDelayTimer(System::TObject* Sender);
	void __fastcall StartAnimationTimer(void);
	void __fastcall StartAnimationRestartDelayTimer(void);
	void __fastcall StopAnimationTimer(void);
	void __fastcall StopAnimationRestartDelayTimer(void);
	void __fastcall SetAnimationFirstPosition(void);
	void __fastcall SetAnimationPath(TcxProgressBarAnimationPath AValue);
	void __fastcall SetAnimationSpeed(unsigned AValue);
	
protected:
	bool FIsBoundsChanged;
	bool FIsBarRectChanged;
	System::Types::TRect BarRect;
	System::Types::TRect ProgressBarRect;
	System::Types::TRect OverloadBarRect;
	System::Types::TRect PeakBarRect;
	void __fastcall PaintProgressBarByPainter(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetAnimationBarDimension(void);
	virtual int __fastcall GetAnimationDerection(void);
	__property TcxProgressBarAnimationPath AnimationPath = {read=FAnimationPath, write=SetAnimationPath, nodefault};
	__property unsigned AnimationRestartDelay = {read=FAnimationRestartDelay, write=FAnimationRestartDelay, nodefault};
	__property unsigned AnimationSpeed = {read=FAnimationSpeed, write=SetAnimationSpeed, nodefault};
	__property System::Uitypes::TColor BeginColor = {read=FBeginColor, write=FBeginColor, nodefault};
	__property TcxProgressBarBevelOuter BarBevelOuter = {read=FBarBevelOuter, write=FBarBevelOuter, nodefault};
	__property System::Uitypes::TColor EndColor = {read=FEndColor, write=FEndColor, nodefault};
	__property bool Marquee = {read=FMarquee, write=SetMarquee, nodefault};
	__property double Min = {read=FMin, write=FMin};
	__property double Max = {read=FMax, write=FMax};
	__property double MaxMinDiff = {read=GetMaxMinDiff};
	__property double OverloadValue = {read=FOverloadValue, write=FOverloadValue};
	__property double PeakValue = {read=FPeakValue, write=FPeakValue};
	__property double Position = {read=FPosition, write=FPosition};
	__property double RelativePeakValue = {read=GetRelativePeakValue};
	__property double RelativeOverloadValue = {read=GetRelativeOverloadValue};
	__property double RelativePosition = {read=GetRelativePosition};
	__property TcxProgressBarBarStyle BarStyle = {read=FBarStyle, write=SetBarStyle, nodefault};
	__property Vcl::Graphics::TBitmap* ForegroundImage = {read=FForegroundImage, write=FForegroundImage};
	__property bool IsDoubleBuffered = {read=GetIsDoubleBuffered, nodefault};
	__property TcxProgressBarOrientation Orientation = {read=FOrientation, write=SetOrientation, nodefault};
	__property System::Uitypes::TColor OverloadBeginColor = {read=FOverloadBeginColor, write=FOverloadBeginColor, nodefault};
	__property System::Uitypes::TColor OverloadEndColor = {read=FOverloadEndColor, write=FOverloadEndColor, nodefault};
	__property System::Uitypes::TColor PeakColor = {read=FPeakColor, write=FPeakColor, nodefault};
	__property Cxexteditconsts::TcxNaturalNumber PeakSize = {read=FPeakSize, write=FPeakSize, nodefault};
	__property bool ShowOverload = {read=FShowOverload, write=FShowOverload, nodefault};
	__property bool ShowPeak = {read=FShowPeak, write=FShowPeak, nodefault};
	__property bool ShowText = {read=FShowText, write=FShowText, nodefault};
	__property TcxProgressBarTextStyle ShowTextStyle = {read=FShowTextStyle, write=FShowTextStyle, nodefault};
	__property bool SolidTextColor = {read=FSolidTextColor, write=FSolidTextColor, nodefault};
	__property TcxProgressBarOrientation TextOrientation = {read=FTextOrientation, write=FTextOrientation, nodefault};
	
public:
	System::Types::TRect FocusRect;
	bool HasForegroundImage;
	__fastcall virtual TcxCustomProgressBarViewInfo(void);
	__fastcall virtual ~TcxCustomProgressBarViewInfo(void);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	int __fastcall GetPercentDone(void);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(Cxcontainer::TcxContainerViewInfo* AViewInfo);
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintProgressBar(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Offset(int DX, int DY);
};


class DELPHICLASS TcxCustomProgressBarViewData;
class DELPHICLASS TcxCustomProgressBarProperties;
class PASCALIMPLEMENTATION TcxCustomProgressBarViewData : public Cxedit::TcxCustomEditViewData
{
	typedef Cxedit::TcxCustomEditViewData inherited;
	
private:
	TcxCustomProgressBarProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall CalculateViewInfoProperties(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual int __fastcall GetDrawTextFlags(void);
	bool __fastcall GetIsEditClass(void);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CalculateButtonsViewInfo(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TRect __fastcall GetBorderExtentByPainter(void);
	__property TcxCustomProgressBarProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomProgressBarViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxedit::TcxCustomEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomProgressBarViewData(void) { }
	
};


class DELPHICLASS TcxProgressBarPropertiesValues;
class PASCALIMPLEMENTATION TcxProgressBarPropertiesValues : public Cxedit::TcxCustomEditPropertiesValues
{
	typedef Cxedit::TcxCustomEditPropertiesValues inherited;
	
private:
	bool __fastcall GetMax(void);
	bool __fastcall GetMin(void);
	bool __fastcall IsMaxStored(void);
	bool __fastcall IsMinStored(void);
	void __fastcall SetMax(bool Value);
	void __fastcall SetMin(bool Value);
	
__published:
	__property bool Max = {read=GetMax, write=SetMax, stored=IsMaxStored, nodefault};
	__property bool Min = {read=GetMin, write=SetMin, stored=IsMinStored, nodefault};
public:
	/* TcxCustomEditPropertiesValues.Create */ inline __fastcall virtual TcxProgressBarPropertiesValues(System::Classes::TPersistent* AOwner) : Cxedit::TcxCustomEditPropertiesValues(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxProgressBarPropertiesValues(void) { }
	
};


class DELPHICLASS TcxProgressBarListener;
class DELPHICLASS TcxCustomProgressBar;
class PASCALIMPLEMENTATION TcxProgressBarListener : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TNotifyEvent FOnChanged;
	TcxCustomProgressBar* FProgressBar;
	
protected:
	void __fastcall DoChanged(void);
	
public:
	__fastcall TcxProgressBarListener(TcxCustomProgressBar* AOwner);
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxProgressBarListener(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomProgressBarProperties : public Cxedit::TcxCustomEditProperties
{
	typedef Cxedit::TcxCustomEditProperties inherited;
	
private:
	TcxProgressBarAnimationPath FAnimationPath;
	unsigned FAnimationRestartDelay;
	TcxProgressBarAnimationSpeed FAnimationSpeed;
	System::Uitypes::TColor FBeginColor;
	TcxProgressBarBevelOuter FBarBevelOuter;
	bool FIsForegroundImageChanged;
	bool FIsPositionChanged;
	System::Uitypes::TColor FEndColor;
	Vcl::Graphics::TBitmap* FForegroundImage;
	bool FMarquee;
	TcxProgressBarOrientation FOrientation;
	bool FShowText;
	TcxProgressBarTextStyle FShowTextStyle;
	System::UnicodeString FText;
	TcxProgressBarOrientation FTextOrientation;
	bool FSolidTextColor;
	TcxProgressBarBarStyle FBarStyle;
	bool FTransparentImage;
	TcxBorderWidth FBorderWidth;
	double FOverloadValue;
	bool FShowOverload;
	System::Uitypes::TColor FOverloadBeginColor;
	System::Uitypes::TColor FOverloadEndColor;
	double FPeakValue;
	bool FShowPeak;
	System::Uitypes::TColor FPeakColor;
	Cxexteditconsts::TcxNaturalNumber FPeakSize;
	TcxProgressBarPropertiesValues* __fastcall GetAssignedValues(void);
	void __fastcall ForegroundImageChanged(System::TObject* Sender);
	double __fastcall GetMax(void);
	double __fastcall GetMin(void);
	bool __fastcall GetOverloadValueStored(void);
	bool __fastcall GetPeakValueStored(void);
	double __fastcall GetRealPeakValue(double APosition);
	bool __fastcall IsMaxStored(void);
	bool __fastcall IsMinStored(void);
	bool __fastcall IsShowTextStyleStored(void);
	void __fastcall SetAnimationPath(TcxProgressBarAnimationPath AValue);
	void __fastcall SetAnimationRestartDelay(unsigned AValue);
	void __fastcall SetAnimationSpeed(TcxProgressBarAnimationSpeed AValue);
	HIDESBASE void __fastcall SetAssignedValues(TcxProgressBarPropertiesValues* Value);
	void __fastcall SetBeginColor(System::Uitypes::TColor Value);
	void __fastcall SetBarBevelOuter(TcxProgressBarBevelOuter Value);
	void __fastcall SetColorVista(void);
	void __fastcall SetEndColor(System::Uitypes::TColor Value);
	void __fastcall SetForegroundImage(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetMarquee(bool Value);
	void __fastcall SetMax(double Value);
	void __fastcall SetMin(double Value);
	void __fastcall SetOrientation(TcxProgressBarOrientation Value);
	void __fastcall SetShowText(bool Value);
	void __fastcall SetShowTextStyle(TcxProgressBarTextStyle Value);
	void __fastcall SetTextOrientation(TcxProgressBarOrientation Value);
	void __fastcall SetSolidTextColor(bool Value);
	void __fastcall SetBarStyle(TcxProgressBarBarStyle Value);
	void __fastcall SetText(const System::UnicodeString AValue);
	void __fastcall SetTransparentImage(bool Value);
	void __fastcall SetBorderWidth(TcxBorderWidth Value);
	void __fastcall SetOverloadValue(double Value);
	void __fastcall SetShowOverload(bool Value);
	void __fastcall SetOverloadBeginColor(System::Uitypes::TColor Value);
	void __fastcall SetOverloadEndColor(System::Uitypes::TColor Value);
	void __fastcall SetPeakValue(double Value);
	void __fastcall SetShowPeak(bool Value);
	void __fastcall SetPeakColor(System::Uitypes::TColor Value);
	void __fastcall SetPeakSize(Cxexteditconsts::TcxNaturalNumber Value);
	void __fastcall PostMinValue(void);
	void __fastcall PostMaxValue(void);
	void __fastcall PostOverloadValue(void);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	virtual double __fastcall GetMaxValue(void);
	virtual double __fastcall GetMinValue(void);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	virtual void __fastcall CorrectPositionWithMaxMin(TcxCustomProgressBarViewInfo* AViewInfo);
	virtual System::WideString __fastcall InternalGetDisplayText(const System::Variant &AEditValue, bool AMarquee, TcxProgressBarTextStyle AShowTextStyle, bool AFullText = false, bool AIsInplace = true);
	__property TcxProgressBarPropertiesValues* AssignedValues = {read=GetAssignedValues, write=SetAssignedValues};
	__property bool IsForegroundImageChanged = {read=FIsForegroundImageChanged, write=FIsForegroundImageChanged, nodefault};
	__property bool IsPositionChanged = {read=FIsPositionChanged, write=FIsPositionChanged, nodefault};
	
public:
	__fastcall virtual TcxCustomProgressBarProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomProgressBarProperties(void);
	virtual bool __fastcall CanCompareEditValue(void);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	__property TcxProgressBarAnimationPath AnimationPath = {read=FAnimationPath, write=SetAnimationPath, default=0};
	__property unsigned AnimationRestartDelay = {read=FAnimationRestartDelay, write=SetAnimationRestartDelay, default=0};
	__property TcxProgressBarAnimationSpeed AnimationSpeed = {read=FAnimationSpeed, write=SetAnimationSpeed, default=10};
	__property TcxProgressBarBevelOuter BarBevelOuter = {read=FBarBevelOuter, write=SetBarBevelOuter, default=0};
	__property TcxProgressBarBarStyle BarStyle = {read=FBarStyle, write=SetBarStyle, default=0};
	__property System::Uitypes::TColor BeginColor = {read=FBeginColor, write=SetBeginColor, default=8388608};
	__property TcxBorderWidth BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property System::Uitypes::TColor EndColor = {read=FEndColor, write=SetEndColor, default=16777215};
	__property Vcl::Graphics::TBitmap* ForegroundImage = {read=FForegroundImage, write=SetForegroundImage};
	__property bool Marquee = {read=FMarquee, write=SetMarquee, default=0};
	__property double Max = {read=GetMax, write=SetMax, stored=IsMaxStored};
	__property double Min = {read=GetMin, write=SetMin, stored=IsMinStored};
	__property TcxProgressBarOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	__property System::Uitypes::TColor OverloadBeginColor = {read=FOverloadBeginColor, write=SetOverloadBeginColor, default=8421631};
	__property System::Uitypes::TColor OverloadEndColor = {read=FOverloadEndColor, write=SetOverloadEndColor, default=16711935};
	__property double OverloadValue = {read=FOverloadValue, write=SetOverloadValue, stored=GetOverloadValueStored};
	__property System::Uitypes::TColor PeakColor = {read=FPeakColor, write=SetPeakColor, default=255};
	__property Cxexteditconsts::TcxNaturalNumber PeakSize = {read=FPeakSize, write=SetPeakSize, default=2};
	__property double PeakValue = {read=FPeakValue, write=SetPeakValue, stored=GetPeakValueStored};
	__property bool ShowOverload = {read=FShowOverload, write=SetShowOverload, default=0};
	__property bool ShowPeak = {read=FShowPeak, write=SetShowPeak, default=0};
	__property bool ShowText = {read=FShowText, write=SetShowText, default=1};
	__property TcxProgressBarTextStyle ShowTextStyle = {read=FShowTextStyle, write=SetShowTextStyle, stored=IsShowTextStyleStored, nodefault};
	__property bool SolidTextColor = {read=FSolidTextColor, write=SetSolidTextColor, default=0};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property TcxProgressBarOrientation TextOrientation = {read=FTextOrientation, write=SetTextOrientation, default=0};
	__property Transparent;
	__property bool TransparentImage = {read=FTransparentImage, write=SetTransparentImage, default=1};
};


class DELPHICLASS TcxProgressBarProperties;
class PASCALIMPLEMENTATION TcxProgressBarProperties : public TcxCustomProgressBarProperties
{
	typedef TcxCustomProgressBarProperties inherited;
	
__published:
	__property AnimationPath = {default=0};
	__property AnimationRestartDelay = {default=0};
	__property AnimationSpeed = {default=10};
	__property AssignedValues;
	__property BarBevelOuter = {default=0};
	__property BarStyle = {default=0};
	__property BeginColor = {default=8388608};
	__property BorderWidth = {default=0};
	__property EndColor = {default=16777215};
	__property ForegroundImage;
	__property Marquee = {default=0};
	__property Max = {default=0};
	__property Min = {default=0};
	__property Orientation = {default=0};
	__property OverloadBeginColor = {default=8421631};
	__property OverloadEndColor = {default=16711935};
	__property OverloadValue = {default=0};
	__property PeakColor = {default=255};
	__property PeakSize = {default=2};
	__property PeakValue = {default=0};
	__property ShowOverload = {default=0};
	__property ShowPeak = {default=0};
	__property ShowText = {default=1};
	__property ShowTextStyle;
	__property SolidTextColor = {default=0};
	__property Text = {default=0};
	__property TextOrientation = {default=0};
	__property Transparent;
	__property TransparentImage = {default=1};
public:
	/* TcxCustomProgressBarProperties.Create */ inline __fastcall virtual TcxProgressBarProperties(System::Classes::TPersistent* AOwner) : TcxCustomProgressBarProperties(AOwner) { }
	/* TcxCustomProgressBarProperties.Destroy */ inline __fastcall virtual ~TcxProgressBarProperties(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomProgressBar : public Cxedit::TcxCustomEdit
{
	typedef Cxedit::TcxCustomEdit inherited;
	
private:
	System::Classes::TList* FListeners;
	int __fastcall GetPercentDone(void);
	double __fastcall GetPosition(void);
	bool __fastcall GetPositionStored(void);
	TcxCustomProgressBarProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomProgressBarProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCustomProgressBarViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomProgressBarProperties* Value);
	void __fastcall SetPosition(double Value);
	
protected:
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual void __fastcall CheckEditorValueBounds(void);
	virtual void __fastcall CheckEditValue(void);
	virtual bool __fastcall DefaultParentColor(void);
	void __fastcall DoNotifyListeners(void);
	virtual bool __fastcall FadingCanFadeBackground(void);
	virtual void __fastcall PopulateSizeProperties(Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	virtual void __fastcall Initialize(void);
	virtual Cxcontainer::TcxContainerStyleValues __fastcall InternalGetNotPublishedStyleValues(void);
	virtual Cxlookandfeelpainters::TcxEditStateColorKind __fastcall GetEditStateColorKind(void);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	__property TcxCustomProgressBarViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomProgressBar(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TcxCustomProgressBar(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	DYNAMIC bool __fastcall CanFocus(void);
	void __fastcall RegisterListener(TcxProgressBarListener* AValue);
	void __fastcall UnRegisterListener(TcxProgressBarListener* AValue);
	__property TcxCustomProgressBarProperties* ActiveProperties = {read=GetActiveProperties};
	__property int PercentDone = {read=GetPercentDone, nodefault};
	__property double Position = {read=GetPosition, write=SetPosition, stored=GetPositionStored};
	__property TcxCustomProgressBarProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Transparent = {default=0};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomProgressBar(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxedit::TcxCustomEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomProgressBar(HWND ParentWindow) : Cxedit::TcxCustomEdit(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
};


class DELPHICLASS TcxProgressBar;
class PASCALIMPLEMENTATION TcxProgressBar : public TcxCustomProgressBar
{
	typedef TcxCustomProgressBar inherited;
	
private:
	HIDESBASE TcxProgressBarProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxProgressBarProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxProgressBarProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxProgressBarProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
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
	__property TcxProgressBarProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomProgressBar.Create */ inline __fastcall virtual TcxProgressBar(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomProgressBar(AOwner) { }
	/* TcxCustomProgressBar.Destroy */ inline __fastcall virtual ~TcxProgressBar(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxProgressBar(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomProgressBar(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxProgressBar(HWND ParentWindow) : TcxCustomProgressBar(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxProgressBarDefaultAnimationSpeed = System::Int8(0xa);
static const System::Int8 cxProgressBarDefaultAnimationRestartDelay = System::Int8(0x0);
static const TcxProgressBarTextStyle cxDefaultShowTextStyle = (TcxProgressBarTextStyle)(0);
}	/* namespace Cxprogressbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPROGRESSBAR)
using namespace Cxprogressbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxprogressbarHPP
