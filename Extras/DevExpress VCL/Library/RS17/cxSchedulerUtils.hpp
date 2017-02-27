// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerUtils.pas' rev: 24.00 (Win32)

#ifndef CxschedulerutilsHPP
#define CxschedulerutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxOffice11.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerutils
{
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD Cxschedulerutils__1
{
public:
	void *P;
	int M;
};


enum TcxStartOfWeek : unsigned char { swSystem, swSunday, swMonday, swTuesday, swWednesday, swThursday, swFriday, swSaturday };

class DELPHICLASS EcxScheduler;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxScheduler : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxScheduler(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxScheduler(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxScheduler(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxScheduler(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxScheduler(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxScheduler(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxScheduler(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxScheduler(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxScheduler(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxScheduler(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxScheduler(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxScheduler(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxScheduler(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxTZIField
{
public:
	int Bias;
	int StandardBias;
	int DaylightBias;
	_SYSTEMTIME StandardDate;
	_SYSTEMTIME DaylightDate;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxDSTInfo
{
public:
	System::Word Year;
	System::TDateTime DaylightDate;
	System::TDateTime StandardDate;
};
#pragma pack(pop)


struct DECLSPEC_DRECORD TcxTimeZoneInformation
{
private:
	typedef System::DynamicArray<TcxDSTInfo> _TcxTimeZoneInformation__1;
	
	
public:
	System::WideString Display;
	System::WideString StandardName;
	System::WideString DaylightName;
	int Index;
	System::UnicodeString MapId;
	TcxTZIField TZI;
	_TcxTimeZoneInformation__1 DynamicDST;
};


enum TSchedulerResourceColor : unsigned char { srcMinorNonWorkTimeSeparator, srcMajorNonWorkTimeSeparator, srcMinorWorkTimeSeparator, srcMajorWorkTimeSeparator, srcNonWorkTime, srcWorkTime };

typedef System::StaticArray<System::Uitypes::TColor, 6> TcxSchedulerResourceColors;

class DELPHICLASS TcxSchedulerDateTimeHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateTimeHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod int __fastcall CheckTimeIndex(const int AIndex);
	__classmethod _TIME_ZONE_INFORMATION __fastcall cxTZInfoToTZInfo(const TcxTimeZoneInformation &AInfo);
	__classmethod TcxTimeZoneInformation __fastcall TZInfoTocxTZInfo(const _TIME_ZONE_INFORMATION &AInfo);
	__classmethod virtual bool __fastcall GetIs24HourTimeFormat();
	__classmethod void __fastcall InitTimeZoneInformation();
	__classmethod void __fastcall ReadTimeZoneInfoFromRegistry(System::Win::Registry::TRegistry* ARegistry, /* out */ TcxTimeZoneInformation &AInfo);
	__classmethod void __fastcall RefreshDateInformation();
	__classmethod void __fastcall RetrieveStartOfWeek();
	__classmethod virtual void __fastcall InitSchedulerDateTimeSystem();
	__classmethod virtual void __fastcall DoneSchedulerDateSystem();
	
public:
	__classmethod int __fastcall AddDSTInfo(TcxTimeZoneInformation &ATimeZoneInfo, const int AYear, const _SYSTEMTIME &AStandardDate, const _SYSTEMTIME &ADaylightDate)/* overload */;
	__classmethod int __fastcall AddDSTInfo(TcxTimeZoneInformation &ATimeZoneInfo, const int AYear, const System::TDateTime AStandardDate, const System::TDateTime ADaylightDate)/* overload */;
	__classmethod int __fastcall AddDSTInfo(const int ATimeZone, const int AYear, const System::TDateTime AStandardDate, const System::TDateTime ADaylightDate)/* overload */;
	__classmethod System::TDateTime __fastcall CalculateTransitionDate(const System::Word AYear, const _SYSTEMTIME &ADSTDateTime);
	__classmethod System::TDateTime __fastcall ConvertToAnotherTimeZone(const System::TDateTime ADateTime, int ATimeZone, int ANextTimeZone);
	__classmethod virtual System::TDateTime __fastcall ConvertToGlobalTime(const System::TDateTime ADateTime, int ATimeZone = 0xffffffff);
	__classmethod virtual System::TDateTime __fastcall ConvertToLocalTime(const System::TDateTime ADateTime, int ATimeZone = 0xffffffff);
	__classmethod virtual int __fastcall CurrentTimeZone();
	__classmethod virtual double __fastcall CurrentTimeZoneBias();
	__classmethod bool __fastcall IsDaylightDateTime(int ATimeZone, System::TDateTime ADateTime);
	__classmethod virtual System::TDateTime __fastcall TimeZoneBias(int AIndex);
	__classmethod virtual System::TDateTime __fastcall TimeZoneBiasDelta(int AIndex);
	__classmethod virtual int __fastcall TimeZoneCount();
	__classmethod virtual int __fastcall TimeZoneDaylightBias(System::TDateTime ADateTime, int ATimeZone);
	__classmethod virtual TcxTimeZoneInformation __fastcall TimeZoneInfo(int AIndex);
	__classmethod virtual System::UnicodeString __fastcall DateToLongDateStr(System::TDateTime ADate);
	__classmethod virtual System::UnicodeString __fastcall DayToStr(const System::TDateTime ADate, int AFormat, bool ACompressed);
	__classmethod virtual int __fastcall DayToStrFormatCount();
	__classmethod virtual System::UnicodeString __fastcall HourToStr(const System::TDateTime ATime);
	__classmethod virtual System::UnicodeString __fastcall MonthYearToStr(int AMonth, int AYear);
	__classmethod virtual System::UnicodeString __fastcall TimeToStr(const System::TDateTime ATime);
	__classmethod virtual void __fastcall Refresh();
	__classmethod virtual void __fastcall FillAdvanceStrings(System::Classes::TStrings* AStrings);
	__classmethod virtual int __fastcall StartOfWeek();
	__classmethod virtual Cxdateutils::TDays __fastcall WorkDays();
	__classmethod virtual System::TDateTime __fastcall WorkFinish();
	__classmethod virtual System::TDateTime __fastcall WorkStart();
	__classmethod virtual System::UnicodeString __fastcall TimeAMString();
	__classmethod virtual System::UnicodeString __fastcall TimePMString();
	__classmethod void __fastcall IncMonth(System::Word &AYear, System::Word &AMonth, System::Word &ADay, int ANumberOfMonths = 0x1);
	__classmethod bool __fastcall Intersect(const System::TDateTime AStart, const System::TDateTime AFinish, const System::TDateTime AStart1, const System::TDateTime AFinish1);
	__classmethod bool __fastcall IsFreeTime(const System::TDateTime ADateTime, Cxdateutils::TDays AWorkDays, const System::TDateTime AWorkStart, const System::TDateTime AWorkFinish);
	__classmethod bool __fastcall IsOddMonth(const System::TDateTime ADate);
	__classmethod bool __fastcall IsWeekEnd(const System::TDateTime ADate, Cxdateutils::TDays AWorkDays);
	__classmethod bool __fastcall IsWeeksFull(const System::TDateTime AStartDate, const System::TDateTime AEndDate);
	__classmethod virtual System::TDateTime __fastcall RoundTime(const System::TDateTime ADateTime);
	__classmethod int __fastcall WeekCount(const System::TDateTime AStart, const System::TDateTime AFinish);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerDateTimeHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDateTimeHelper(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSchedulerDateTimeHelperClass;

class DELPHICLASS TcxSchedulerPainterHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerPainterHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod void __fastcall CreateStateBrushes();
	__classmethod void __fastcall DrawClockLine(Cxgraphics::TcxCanvas* ACanvas, const int ATime, const int ATimePerCircle, const int ARadius, const int XC, const int YC);
	__classmethod void __fastcall FreeStateBrushes();
	__classmethod virtual System::Uitypes::TColor __fastcall GetColorValue(System::Uitypes::TColor AColor, int ALightValue);
	__classmethod virtual void __fastcall GetResourceColors(System::Uitypes::TColor AColor, /* out */ System::Uitypes::TColor *AResourceColors);
	__classmethod System::Classes::TMemoryStream* __fastcall GetResourceStream(const System::UnicodeString AResName);
	__classmethod virtual void __fastcall InitCachedColors(System::Uitypes::TColor AColor, /* out */ System::Uitypes::TColor *AColors);
	__classmethod virtual void __fastcall InitSchedulerGraphics();
	__classmethod virtual void __fastcall FreeSchedulerGraphics();
	
public:
	__classmethod void __fastcall DrawClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Word AHour, System::Word AMinute, const Cxgraphics::TcxViewParams &AViewParams)/* overload */;
	__classmethod void __fastcall DrawClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ATime, const Cxgraphics::TcxViewParams &AViewParams)/* overload */;
	__classmethod void __fastcall DrawGradientRect(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor AStartColor, const System::Types::TRect &ARect);
	__classmethod void __fastcall DrawIcon(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int AIndex)/* overload */;
	__classmethod void __fastcall DrawIcon(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int AIndex, const Cxgraphics::TcxViewParams &AViewParams, bool AIsTransparent)/* overload */;
	__classmethod virtual void __fastcall DrawShadow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds);
	__classmethod void __fastcall DrawState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int AState, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x0));
	__classmethod virtual void __fastcall DrawTransparentImage(Cxgraphics::TcxCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImages, int X, int Y, int AIndex);
	__classmethod System::Types::TRect __fastcall ExcludeBorders(const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, int ABorderSize = 0x1);
	__classmethod System::Uitypes::TColor __fastcall GetContentColor(int AResourceColor, bool AIsWorkTime);
	__classmethod System::Uitypes::TColor __fastcall GetResourceContentColor(int AResourceIndex);
	__classmethod System::Uitypes::TColor __fastcall GetSeparatorColor(const int AResourceColor, bool AIsHourSeparator, bool AIsWorkTime);
	__classmethod int __fastcall IconsWidth();
	__classmethod int __fastcall IconsHeight();
	__classmethod System::Types::TRect __fastcall IncludeBorders(const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, int ABorderSize = 0x1);
	__classmethod void __fastcall InitStyle(Cxstyles::TcxStyle* AStyle, const System::UnicodeString AResName, Vcl::Graphics::TGraphicClass AGraphicClass);
	__classmethod bool __fastcall LoadGraphic(Vcl::Graphics::TBitmap* ABitmap, const System::UnicodeString AResName, Vcl::Graphics::TGraphicClass AGraphicClass);
	__classmethod Vcl::Controls::TImageList* __fastcall LoadImages(int AWidth, int AHeight, const System::UnicodeString AResName, bool AHasPalette = false, bool AHasTransparent = true);
	__classmethod int __fastcall MoreButtonHeight();
	__classmethod int __fastcall MoreButtonWidth();
	__classmethod int __fastcall ShadowSize();
	__classmethod int __fastcall TextHeight(Vcl::Graphics::TFont* AFont);
	__classmethod int __fastcall TextWidth(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerPainterHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerPainterHelper(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSchedulerPainterHelperClass;

class DELPHICLASS TcxSchedulerHelpersFactory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerHelpersFactory : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall Done();
	__classmethod virtual void __fastcall Init();
	__classmethod void __fastcall LoadCursors();
	
public:
	__classmethod virtual TcxSchedulerPainterHelperClass __fastcall PainterHelperClass();
	__classmethod virtual TcxSchedulerDateTimeHelperClass __fastcall DateTimeHelperClass();
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerHelpersFactory(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerHelpersFactory(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSchedulerHelpersFactoryClass;

class DELPHICLASS TcxSchedulerObjectList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerObjectList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	System::TObject* __fastcall GetItem(int AIndex);
	
public:
	__fastcall virtual ~TcxSchedulerObjectList(void);
	virtual void __fastcall Clear(void);
	__property System::TObject* Items[int Index] = {read=GetItem};
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerObjectList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerDateList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	System::TDateTime operator[](int Index) { return Items[Index]; }
	
private:
	bool FChanged;
	bool __fastcall GetChanged(void);
	System::TDateTime __fastcall GetItem(int AIndex);
	void __fastcall SetItem(int AIndex, const System::TDateTime AValue);
	
protected:
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	
public:
	HIDESBASE int __fastcall Add(System::TDateTime ADate);
	int __fastcall AddEx(System::TDateTime ADate);
	bool __fastcall ExistDate(System::TDateTime ADate);
	HIDESBASE int __fastcall IndexOf(System::TDateTime ADate);
	void __fastcall ShiftPeriod(System::TDateTime ADelta);
	__property System::TDateTime Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property bool Changed = {read=GetChanged, write=FChanged, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxSchedulerDateList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerDateList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerTimeRange;
class PASCALIMPLEMENTATION TcxSchedulerTimeRange : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
protected:
	System::TDateTime FFinish;
	System::TDateTime FStart;
	System::TDateTime __fastcall GetDuration(void);
	
public:
	__property System::TDateTime Duration = {read=GetDuration};
	__property System::TDateTime Finish = {read=FFinish};
	__property System::TDateTime Start = {read=FStart};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxSchedulerTimeRange(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeRange(void) { }
	
};


class DELPHICLASS TcxSchedulerTimeRanges;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTimeRanges : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxSchedulerTimeRange* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxSchedulerTimeRange* __fastcall GetItem(int AIndex);
	
protected:
	System::TObject* FOwner;
	
public:
	__fastcall TcxSchedulerTimeRanges(System::TObject* AOwner);
	HIDESBASE TcxSchedulerTimeRange* __fastcall Add(const System::TDateTime AStart, const System::TDateTime AFinish);
	__property TcxSchedulerTimeRange* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TCollection.Create */ inline __fastcall TcxSchedulerTimeRanges(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeRanges(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerEventLabel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerEventLabel : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FCaption;
	System::Uitypes::TColor FColor;
	int FOriginalIndex;
	System::UnicodeString __fastcall GetCaption(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	
public:
	__fastcall virtual TcxSchedulerEventLabel(System::Classes::TCollection* Collection);
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption};
	__property System::Uitypes::TColor Color = {read=GetColor, write=SetColor, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxSchedulerEventLabel(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerEventLabels;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerEventLabels : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxSchedulerEventLabel* operator[](int Index) { return Items[Index]; }
	
private:
	Vcl::Controls::TImageList* FImages;
	HIDESBASE TcxSchedulerEventLabel* __fastcall GetItem(int AIndex);
	
protected:
	void __fastcall CreateDefaultItems(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	void __fastcall UpdateImageList(void);
	
public:
	__fastcall TcxSchedulerEventLabels(void);
	__fastcall virtual ~TcxSchedulerEventLabels(void);
	HIDESBASE TcxSchedulerEventLabel* __fastcall Add(System::Uitypes::TColor AColor, const System::UnicodeString ACaption);
	int __fastcall IndexOfColor(System::Uitypes::TColor AColor);
	__property TcxSchedulerEventLabel* Items[int Index] = {read=GetItem/*, default*/};
	__property Vcl::Controls::TImageList* Images = {read=FImages};
};

#pragma pack(pop)

typedef System::UnicodeString __fastcall (*TcxMinutesToTextProc)(int AMinutes);

typedef bool __fastcall (*TcxTextToMinutesProc)(const System::UnicodeString AText, /* out */ int &AMinutes);

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 rcClockIndex = System::Int8(0x0);
static const System::Int8 rcRecurrenceIndex = System::Int8(0x2);
static const System::Int8 rcBellIndex = System::Int8(0x4);
extern PACKAGE bool Is24HourTimeFormat;
static const System::Extended HourToTime = 4.166667E-02;
static const System::Extended MinuteToTime = 6.944444E-04;
static const System::Extended SecondToTime = 1.157407E-05;
static const System::Extended MSecsToTime = 1.157407E-08;
static const System::Extended cxHalfHour = 2.083333E-02;
static const System::Extended cxTime8AM = 3.333333E-01;
static const System::Word MinsPerWeek = System::Word(0x2760);
extern PACKAGE System::StaticArray<System::Uitypes::TColor, 11> EventLabelColors;
extern PACKAGE System::StaticArray<Cxschedulerutils__1, 25> ComboBoxTimeIntervals;
extern PACKAGE System::StaticArray<void *, 2> sMinutePluralNames;
extern PACKAGE System::StaticArray<void *, 2> sHourPluralNames;
extern PACKAGE System::StaticArray<void *, 2> sDayPluralNames;
extern PACKAGE System::StaticArray<void *, 2> sWeekPluralNames;
static const System::Int8 cxEventImagesGap = System::Int8(0x1);
extern PACKAGE TcxSchedulerDateTimeHelperClass DateTimeHelper;
extern PACKAGE TcxMinutesToTextProc cxMinutesToTextProc;
extern PACKAGE TcxTextToMinutesProc cxTextToMinutesProc;
extern PACKAGE System::StaticArray<System::StaticArray<System::Uitypes::TColor, 6>, 12> PredefinedResourceColors;
extern PACKAGE System::StaticArray<int, 6> ResourceColorIntensityValues;
extern PACKAGE Vcl::Imglist::TCustomImageList* EventImages;
extern PACKAGE Vcl::Imglist::TCustomImageList* MenuImages;
extern PACKAGE Vcl::Imglist::TCustomImageList* MoreEventButtonGlyphs;
extern PACKAGE Vcl::Imglist::TCustomImageList* TimeLinePatterns;
extern PACKAGE System::StaticArray<Vcl::Graphics::TBrush*, 8> StateBrushes;
extern PACKAGE TcxSchedulerHelpersFactoryClass SchedulerHelpersFactory;
extern PACKAGE TcxSchedulerEventLabels* EventLabels;
extern PACKAGE TcxTimeZoneInformation DefaultTimeZoneInfo;
extern PACKAGE int __fastcall GetNearestDivider(int ANum, int ADenom, int AMinDenom, int AMaxDenom);
extern PACKAGE int __fastcall cxCompareDates(void * Item1, void * Item2);
extern PACKAGE void __fastcall cxSchedulerError(const System::UnicodeString ADescription)/* overload */;
extern PACKAGE void __fastcall cxSchedulerError(const System::UnicodeString ADescription, System::TVarRec *Args, const int Args_Size)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxMinutesToText(int AMinutes);
extern PACKAGE bool __fastcall cxTextToMinutes(const System::UnicodeString AText, /* out */ int &AMinutes);
}	/* namespace Cxschedulerutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERUTILS)
using namespace Cxschedulerutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerutilsHPP
