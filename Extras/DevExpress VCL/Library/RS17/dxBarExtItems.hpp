// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarExtItems.pas' rev: 24.00 (Win32)

#ifndef DxbarextitemsHPP
#define DxbarextitemsHPP

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
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarAccessibility.hpp>	// Pascal unit
#include <dxCommon.hpp>	// Pascal unit
#include <dxBarSkinConsts.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarextitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarStatic;
class PASCALIMPLEMENTATION TdxBarStatic : public Dxbar::TdxBarItem
{
	typedef Dxbar::TdxBarItem inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	bool FAllowClick;
	Dxbar::TdxBarStaticBorderStyle FBorderStyle;
	int FHeight;
	int FLeftIndent;
	int FRightIndent;
	int FWidth;
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetBorderStyle(Dxbar::TdxBarStaticBorderStyle Value);
	void __fastcall SetSizeValue(int Index, int Value);
	
protected:
	virtual bool __fastcall CanClicked(void);
	virtual bool __fastcall HasAccel(Dxbar::TdxBarItemLink* AItemLink);
	virtual bool __fastcall IsStyleColorSupported(void);
	
public:
	__fastcall virtual TdxBarStatic(System::Classes::TComponent* AOwner);
	
__published:
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=2};
	__property bool AllowClick = {read=FAllowClick, write=FAllowClick, default=0};
	__property Dxbar::TdxBarStaticBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	__property Glyph;
	__property int Height = {read=FHeight, write=SetSizeValue, index=4, default=0};
	__property ImageIndex = {default=-1};
	__property int LeftIndent = {read=FLeftIndent, write=SetSizeValue, index=1, default=0};
	__property int RightIndent = {read=FRightIndent, write=SetSizeValue, index=2, default=0};
	__property ShowCaption = {default=1};
	__property int Width = {read=FWidth, write=SetSizeValue, index=3, default=0};
	__property OnClick;
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxBarStatic(void) { }
	
};


class DELPHICLASS TdxBarStaticControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarStaticControl : public Dxbar::TdxBarCustomStaticControl
{
	typedef Dxbar::TdxBarCustomStaticControl inherited;
	
private:
	Dxbar::TdxBarStaticBorderStyle __fastcall GetBorderStyle(void);
	System::Types::TRect __fastcall GetBorderOffsets(void);
	HIDESBASE TdxBarStatic* __fastcall GetItem(void);
	int __fastcall GetSizeValue(int Index);
	
protected:
	virtual void __fastcall CalcDrawParams(bool AFull = true);
	virtual bool __fastcall CanClicked(void);
	virtual bool __fastcall CanHaveZeroSize(void);
	virtual bool __fastcall CanMouseSelect(void);
	virtual void __fastcall CaptionChanged(void);
	virtual void __fastcall DoPaint(const System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	virtual void __fastcall DrawInterior(const System::Types::TRect &ARect);
	virtual System::Classes::TAlignment __fastcall GetAlignment(void);
	int __fastcall GetAutoHeight(int ADefaultButtonSize);
	int __fastcall GetAutoWidth(int ADefaultButtonSize);
	virtual int __fastcall GetDefaultHeight(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual int __fastcall InternalGetDefaultHeight(void);
	virtual int __fastcall InternalGetDefaultWidth(void);
	virtual bool __fastcall CanDestroyOnClick(void);
	__property System::Classes::TAlignment Alignment = {read=GetAlignment, nodefault};
	__property Dxbar::TdxBarStaticBorderStyle BorderStyle = {read=GetBorderStyle, nodefault};
	__property System::Types::TRect BorderOffsets = {read=GetBorderOffsets};
	__property int Height = {read=GetSizeValue, index=4, nodefault};
	__property int LeftIndent = {read=GetSizeValue, index=1, nodefault};
	__property int RightIndent = {read=GetSizeValue, index=2, nodefault};
	__property int Width = {read=GetSizeValue, index=3, nodefault};
	
public:
	__property TdxBarStatic* Item = {read=GetItem};
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxBarStaticControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarCustomStaticControl(AItemLink) { }
	/* TdxBarItemControl.Destroy */ inline __fastcall virtual ~TdxBarStaticControl(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarColorCombo;
class PASCALIMPLEMENTATION TdxBarColorCombo : public Dxbar::TdxBarCustomCombo
{
	typedef Dxbar::TdxBarCustomCombo inherited;
	
private:
	System::Uitypes::TColor FAutoColor;
	System::UnicodeString FAutoColorText;
	System::Uitypes::TColor FColor;
	System::UnicodeString FCustomColorText;
	System::Uitypes::TColor FExchangeColor;
	bool FHasExchangeColor;
	bool FInRefreshColorNames;
	bool FIsAutoColorTextAssigned;
	bool FIsCustomColorTextAssigned;
	bool FSettingColor;
	bool FShowAutoColor;
	bool FShowCustomColorButton;
	System::Uitypes::TColor __fastcall GetCurColor(void);
	void __fastcall SetAutoColor(System::Uitypes::TColor Value);
	void __fastcall SetAutoColorText(System::UnicodeString Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetCurColor(System::Uitypes::TColor Value);
	void __fastcall SetCustomColorText(System::UnicodeString Value);
	void __fastcall SetShowAutoColor(bool Value);
	void __fastcall SetShowCustomColorButton(bool Value);
	void __fastcall CreateItemsList(void);
	System::UnicodeString __fastcall DefaultAutoColorText(void);
	System::UnicodeString __fastcall DefaultCustomColorText(void);
	System::Uitypes::TColor __fastcall GetColorByIndex(int AIndex);
	int __fastcall GetIndexOfColor(System::Uitypes::TColor AColor);
	bool __fastcall IsAutoColorTextStored(void);
	bool __fastcall IsCustomColorTextStored(void);
	bool __fastcall IsDropDownCountStored(void);
	
protected:
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall DrawItem(Dxbar::TdxBarPainter* APainter, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall MeasureItem(int AIndex, int &AHeight);
	virtual void __fastcall MeasureItemWidth(int AIndex, int &AWidth);
	__property System::Uitypes::TColor ExchangeColor = {read=FExchangeColor, nodefault};
	__property bool HasExchangeColor = {read=FHasExchangeColor, nodefault};
	
public:
	__fastcall virtual TdxBarColorCombo(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarColorCombo(void);
	DYNAMIC void __fastcall DoClick(void);
	void __fastcall TranslationChanged(void);
	void __fastcall RefreshColorNames(void);
	__property System::Uitypes::TColor CurColor = {read=GetCurColor, write=SetCurColor, nodefault};
	
__published:
	__property System::Uitypes::TColor AutoColor = {read=FAutoColor, write=SetAutoColor, default=-16777208};
	__property System::UnicodeString AutoColorText = {read=FAutoColorText, write=SetAutoColorText, stored=IsAutoColorTextStored};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property System::UnicodeString CustomColorText = {read=FCustomColorText, write=SetCustomColorText, stored=IsCustomColorTextStored};
	__property DropDownCount = {stored=IsDropDownCountStored, default=8};
	__property bool ShowAutoColor = {read=FShowAutoColor, write=SetShowAutoColor, default=0};
	__property bool ShowCustomColorButton = {read=FShowCustomColorButton, write=SetShowCustomColorButton, default=0};
	__property ShowEditor = {default=0};
	__property Text = {stored=false, default=0};
private:
	void *__IdxLocalizerListener;	/* Dxcore::IdxLocalizerListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2E926681-1A56-4599-E8E0-B02D62740E56}
	operator Dxcore::_di_IdxLocalizerListener()
	{
		Dxcore::_di_IdxLocalizerListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcore::IdxLocalizerListener*(void) { return (Dxcore::IdxLocalizerListener*)&__IdxLocalizerListener; }
	#endif
	
};


class DELPHICLASS TdxBarColorComboControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarColorComboControl : public Dxbar::TdxBarComboControl
{
	typedef Dxbar::TdxBarComboControl inherited;
	
private:
	HIDESBASE Dxbar::TdxBarColorComboControlDrawParams* __fastcall GetDrawParams(void);
	HIDESBASE TdxBarColorCombo* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall CalcDrawParams(bool AFull = true);
	virtual void __fastcall CalcParts(void);
	virtual void __fastcall CorrectFrameRect(System::Types::TRect &ARect);
	virtual bool __fastcall DrawSelected(void);
	virtual void __fastcall DrawTextField(void);
	virtual Dxbar::TdxBarItemControlDrawParamsClass __fastcall GetDrawParamsClass(void);
	virtual int __fastcall GetPartCount(void);
	virtual void __fastcall PressedChanged(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property Dxbar::TdxBarColorComboControlDrawParams* DrawParams = {read=GetDrawParams};
	
public:
	__property TdxBarColorCombo* Item = {read=GetItem};
public:
	/* TCustomdxBarComboControl.Destroy */ inline __fastcall virtual ~TdxBarColorComboControl(void) { }
	
public:
	/* TdxBarEditControl.Create */ inline __fastcall virtual TdxBarColorComboControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarComboControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarFontNameCombo;
class PASCALIMPLEMENTATION TdxBarFontNameCombo : public Dxbar::TdxBarCustomCombo
{
	typedef Dxbar::TdxBarCustomCombo inherited;
	
protected:
	virtual void __fastcall DrawItem(Dxbar::TdxBarPainter* APainter, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall LoadFontNames(void);
	virtual void __fastcall MeasureItemWidth(int AIndex, int &AWidth);
	virtual void __fastcall SetText(System::UnicodeString Value);
	
public:
	__fastcall virtual TdxBarFontNameCombo(System::Classes::TComponent* AOwner);
	DYNAMIC void __fastcall DoClick(void);
	
__published:
	__property ShowEditor = {default=0};
public:
	/* TdxBarCustomCombo.Destroy */ inline __fastcall virtual ~TdxBarFontNameCombo(void) { }
	
};


enum TdxBarCalendarStyle : unsigned char { cs3D, csFlat, csUltraFlat };

class DELPHICLASS TdxBarCustomCalendar;
class PASCALIMPLEMENTATION TdxBarCustomCalendar : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	System::TDateTime FDragDate;
	System::TDateTime FFirstDate;
	System::TDateTime FSelStart;
	System::TDateTime FSelFinish;
	TdxBarCalendarStyle FStyle;
	System::Classes::TNotifyEvent FOnDateTimeChanged;
	bool __fastcall GetFlat(void);
	bool __fastcall GetUltraFlat(void);
	void __fastcall SetStyle(TdxBarCalendarStyle Value);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMCaptureChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	
protected:
	virtual TdxBarCalendarStyle __fastcall GetStyle(void);
	virtual System::TDateTime __fastcall GetRealFirstDate(void);
	virtual System::TDateTime __fastcall GetRealLastDate(void);
	virtual System::TDateTime __fastcall GetLastDate(void) = 0 ;
	virtual System::TDateTime __fastcall GetSelStart(void);
	virtual System::TDateTime __fastcall GetSelFinish(void);
	virtual void __fastcall SetFirstDate(System::TDateTime Value);
	virtual void __fastcall SetSelStart(System::TDateTime Value);
	virtual void __fastcall SetSelFinish(System::TDateTime Value);
	DYNAMIC void __fastcall CancelAll(void);
	virtual void __fastcall CheckFirstDate(void) = 0 ;
	DYNAMIC void __fastcall DoDateTimeChanged(void);
	void __fastcall DoInternalSelectPeriod(System::TDateTime ADate);
	virtual System::TDateTime __fastcall PosToDateTime(const System::Types::TPoint &P) = 0 ;
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	__property bool Flat = {read=GetFlat, nodefault};
	__property bool UltraFlat = {read=GetUltraFlat, nodefault};
	__property System::TDateTime RealFirstDate = {read=GetRealFirstDate};
	__property System::TDateTime RealLastDate = {read=GetRealLastDate};
	
public:
	__fastcall virtual TdxBarCustomCalendar(System::Classes::TComponent* AOwner);
	__property System::TDateTime FirstDate = {read=FFirstDate, write=SetFirstDate};
	__property System::TDateTime LastDate = {read=GetLastDate};
	__property System::TDateTime SelStart = {read=GetSelStart, write=SetSelStart};
	__property System::TDateTime SelFinish = {read=GetSelFinish, write=SetSelFinish};
	__property TdxBarCalendarStyle Style = {read=GetStyle, write=SetStyle, nodefault};
	__property System::Classes::TNotifyEvent OnDateTimeChanged = {read=FOnDateTimeChanged, write=FOnDateTimeChanged};
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TdxBarCustomCalendar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarCustomCalendar(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TdxBarDateNavigator;
class DELPHICLASS TdxBarDateCombo;
class PASCALIMPLEMENTATION TdxBarDateNavigator : public TdxBarCustomCalendar
{
	typedef TdxBarCustomCalendar inherited;
	
private:
	TdxBarDateCombo* FCombo;
	int FColCount;
	int FRowCount;
	int FColWidth;
	int FSideWidth;
	int FRowHeight;
	int FHeaderHeight;
	int FDaysOfWeekHeight;
	int FTodayButtonWidth;
	int FClearButtonWidth;
	int FButtonsOffset;
	int FButtonsHeight;
	int FButtonsRegionHeight;
	Vcl::Controls::TWinControl* FListBox;
	int FListBoxDelta;
	unsigned FTimer;
	bool FTodayButtonActive;
	bool FTodayButtonPressed;
	bool FClearButtonActive;
	bool FClearButtonPressed;
	void __fastcall CheckSelection(System::TDateTime MarginDate);
	int __fastcall ColOfDate(System::TDateTime ADate);
	System::Types::TRect __fastcall GetHeaderRect(void);
	System::Types::TRect __fastcall GetInternalRect(void);
	System::Types::TRect __fastcall GetLeftArrowRect(void);
	Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	System::Types::TRect __fastcall GetRightArrowRect(void);
	System::Types::TRect __fastcall GetMonthNameRect(void);
	System::Types::TRect __fastcall GetTodayButtonRect(void);
	System::Types::TRect __fastcall GetClearButtonRect(void);
	bool __fastcall GetShowButtonsArea(void);
	void __fastcall FreeTimer(void);
	void __fastcall RepaintTodayButton(void);
	void __fastcall RepaintClearButton(void);
	HIDESBASE MESSAGE void __fastcall WMDestroy(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	
protected:
	virtual TdxBarCalendarStyle __fastcall GetStyle(void);
	virtual System::TDateTime __fastcall GetRealFirstDate(void);
	virtual System::TDateTime __fastcall GetRealLastDate(void);
	virtual System::TDateTime __fastcall GetLastDate(void);
	virtual void __fastcall SetFirstDate(System::TDateTime Value);
	virtual void __fastcall SetSelFinish(System::TDateTime Value);
	void __fastcall StepToPast(void);
	void __fastcall StepToFuture(void);
	DYNAMIC void __fastcall CancelAll(void);
	virtual void __fastcall CheckFirstDate(void);
	void __fastcall DeactivateAll(void);
	virtual System::TDateTime __fastcall PosToDateTime(const System::Types::TPoint &P);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	__property Dxbar::TdxBarPainter* Painter = {read=GetPainter};
	__property bool ShowButtonsArea = {read=GetShowButtonsArea, nodefault};
	
public:
	bool IsPopup;
	bool ShowTodayButton;
	bool ShowClearButton;
	__fastcall virtual TdxBarDateNavigator(System::Classes::TComponent* AOwner);
	void __fastcall SetSize(void);
	int __fastcall GetWidth(void);
	int __fastcall GetHeight(void);
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TdxBarDateNavigator(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarDateNavigator(HWND ParentWindow) : TdxBarCustomCalendar(ParentWindow) { }
	
};


enum TdxBarDateOnStart : unsigned char { bdsToday, bdsNullDate, bdsCustom };

class PASCALIMPLEMENTATION TdxBarDateCombo : public Dxbar::TCustomdxBarCombo
{
	typedef Dxbar::TCustomdxBarCombo inherited;
	
private:
	TdxBarDateOnStart FDateOnStart;
	TdxBarDateNavigator* FDatePopup;
	TdxBarDateNavigator* FDateNavigator;
	Vcl::Stdctrls::TEdit* FDateEdit;
	Vcl::Forms::TForm* FForm;
	bool FInternalUpdate;
	System::TDateTime FMinDate;
	System::TDateTime FMaxDate;
	bool FShowDayText;
	bool FShowTodayButton;
	bool FShowClearButton;
	System::TDateTime __fastcall GetCurDate(void);
	System::TDateTime __fastcall GetDate(void);
	void __fastcall SetCurDate(System::TDateTime Value);
	void __fastcall SetDate(System::TDateTime Value);
	void __fastcall DateChanged(System::TObject* Sender);
	void __fastcall DialogClick(System::TObject* Sender);
	void __fastcall DialogDateChanged(System::TObject* Sender);
	void __fastcall DialogDateEditChange(System::TObject* Sender);
	System::TDateTime __fastcall GetDateOfText(System::UnicodeString AText);
	System::UnicodeString __fastcall GetDateText(System::TDateTime ADate);
	bool __fastcall IsMinDateStored(void);
	bool __fastcall IsMaxDateStored(void);
	bool __fastcall IsTextStored(void);
	void __fastcall SetDateOnStart(TdxBarDateOnStart Value);
	void __fastcall SetMinDate(System::TDateTime Value);
	void __fastcall SetMaxDate(System::TDateTime Value);
	void __fastcall SetShowDayText(bool Value);
	
protected:
	virtual void __fastcall Loaded(void);
	void __fastcall CheckDateOnStart(void);
	void __fastcall CheckRange(void);
	virtual bool __fastcall CheckKeyForDropDownWindow(System::Word Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall CloseUp(void);
	DYNAMIC void __fastcall DropDown(int X, int Y);
	virtual HWND __fastcall GetDropDownWindow(void);
	void __fastcall ResetDate(void);
	virtual void __fastcall SetText(System::UnicodeString Value);
	__property TdxBarDateNavigator* DatePopup = {read=FDatePopup};
	
public:
	__fastcall virtual TdxBarDateCombo(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarDateCombo(void);
	System::TDateTime __fastcall CheckDate(System::TDateTime ADate);
	DYNAMIC void __fastcall DoClick(void);
	__property System::TDateTime CurDate = {read=GetCurDate, write=SetCurDate};
	__property System::TDateTime Date = {read=GetDate, write=SetDate};
	
__published:
	__property TdxBarDateOnStart DateOnStart = {read=FDateOnStart, write=SetDateOnStart, default=0};
	__property System::TDateTime MaxDate = {read=FMaxDate, write=SetMaxDate, stored=IsMaxDateStored};
	__property System::TDateTime MinDate = {read=FMinDate, write=SetMinDate, stored=IsMinDateStored};
	__property bool ShowTodayButton = {read=FShowTodayButton, write=FShowTodayButton, default=1};
	__property bool ShowClearButton = {read=FShowClearButton, write=FShowClearButton, default=1};
	__property bool ShowDayText = {read=FShowDayText, write=SetShowDayText, default=1};
	__property Text = {stored=IsTextStored, default=0};
};


class DELPHICLASS TdxBarDateComboControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarDateComboControl : public Dxbar::TCustomdxBarComboControl
{
	typedef Dxbar::TCustomdxBarComboControl inherited;
	
private:
	System::TDateTime __fastcall GetDate(void);
	HIDESBASE TdxBarDateCombo* __fastcall GetItem(void);
	void __fastcall SetDate(const System::TDateTime Value);
	
protected:
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property System::TDateTime Date = {read=GetDate, write=SetDate};
	
public:
	__property TdxBarDateCombo* Item = {read=GetItem};
public:
	/* TCustomdxBarComboControl.Destroy */ inline __fastcall virtual ~TdxBarDateComboControl(void) { }
	
public:
	/* TdxBarEditControl.Create */ inline __fastcall virtual TdxBarDateComboControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TCustomdxBarComboControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarTreeView;
class DELPHICLASS TdxBarTreeViewCombo;
class PASCALIMPLEMENTATION TdxBarTreeView : public Vcl::Comctrls::TCustomTreeView
{
	typedef Vcl::Comctrls::TCustomTreeView inherited;
	
private:
	System::Types::TRect FCloseButtonRect;
	System::Types::TRect FGripRect;
	bool FCloseButtonIsTracking;
	TdxBarTreeViewCombo* FCombo;
	Dxcore::TdxCorner FCorner;
	bool FMouseAboveCloseButton;
	Vcl::Comctrls::THitTests FMouseDownHitTestInfo;
	Vcl::Comctrls::TTreeNode* __fastcall FindNode(const System::UnicodeString AText);
	Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	void __fastcall SaveAndHide(void);
	MESSAGE void __fastcall TVMSetImageList(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall TVMSetItem(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMCaptureChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetMinMaxInfo(Winapi::Messages::TWMGetMinMaxInfo &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDown(Winapi::Messages::TWMNCHitMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSysColorChange(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	
protected:
	DYNAMIC void __fastcall Change(Vcl::Comctrls::TTreeNode* Node);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall UpdateSizeGripCorner(const System::Types::TPoint &ADropDownPosition);
	__property Dxbar::TdxBarPainter* Painter = {read=GetPainter};
	
public:
	bool IsPopup;
	__fastcall virtual TdxBarTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarTreeView(void);
	virtual void __fastcall SetFocus(void);
	__property Items;
	__property OnDeletion;
	__property TdxBarTreeViewCombo* Combo = {read=FCombo};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarTreeView(HWND ParentWindow) : Vcl::Comctrls::TCustomTreeView(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TdxBarTreeViewComboCanSelectNodeEvent)(TdxBarTreeViewCombo* Sender, Vcl::Comctrls::TTreeNode* Node, bool &CanSelect);

class PASCALIMPLEMENTATION TdxBarTreeViewCombo : public Dxbar::TCustomdxBarCombo
{
	typedef Dxbar::TCustomdxBarCombo inherited;
	
private:
	bool FAllowResizing;
	Vcl::Stdctrls::TButton* FButtonOk;
	Vcl::Stdctrls::TButton* FButtonCancel;
	bool FChooseByDblClick;
	Vcl::Forms::TForm* FForm;
	TdxBarTreeView* FFormTreeView;
	TdxBarTreeView* FTreeView;
	bool FFullExpand;
	bool FInSelectedNodeChanged;
	System::UnicodeString FLoadedText;
	Vcl::Comctrls::TTreeNode* FSelectedNode;
	bool FShowImageInEdit;
	TdxBarTreeViewComboCanSelectNodeEvent FOnCanSelectNode;
	int __fastcall GetDropDownHeight(void);
	int __fastcall GetDropDownWidth(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	int __fastcall GetIndent(void);
	Vcl::Comctrls::TTreeNodes* __fastcall GetItems(void);
	bool __fastcall GetShowButtons(void);
	bool __fastcall GetShowLines(void);
	bool __fastcall GetShowRoot(void);
	Vcl::Comctrls::TSortType __fastcall GetSortType(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnExpanded(void);
	Vcl::Comctrls::TTVExpandingEvent __fastcall GetOnExpanding(void);
	Vcl::Comctrls::TTVChangingEvent __fastcall GetOnChanging(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnCollapsed(void);
	Vcl::Comctrls::TTVCollapsingEvent __fastcall GetOnCollapsing(void);
	Vcl::Comctrls::TTVCompareEvent __fastcall GetOnCompare(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnGetImageIndex(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnGetSelectedIndex(void);
	Vcl::Comctrls::TTVChangedEvent __fastcall GetOnTreeViewChange(void);
	void __fastcall SetDropDownHeight(int Value);
	void __fastcall SetDropDownWidth(int Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetIndent(int Value);
	void __fastcall SetItems(Vcl::Comctrls::TTreeNodes* Value);
	void __fastcall SetSelectedNode(Vcl::Comctrls::TTreeNode* Value);
	void __fastcall SetShowButtons(bool Value);
	void __fastcall SetShowImageInEdit(bool Value);
	void __fastcall SetShowLines(bool Value);
	void __fastcall SetShowRoot(bool Value);
	void __fastcall SetSortType(Vcl::Comctrls::TSortType Value);
	void __fastcall SetStateImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetOnExpanded(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnExpanding(Vcl::Comctrls::TTVExpandingEvent Value);
	void __fastcall SetOnChanging(Vcl::Comctrls::TTVChangingEvent Value);
	void __fastcall SetOnCollapsed(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnCollapsing(Vcl::Comctrls::TTVCollapsingEvent Value);
	void __fastcall SetOnCompare(Vcl::Comctrls::TTVCompareEvent Value);
	void __fastcall SetOnGetImageIndex(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnGetSelectedIndex(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnTreeViewChange(Vcl::Comctrls::TTVChangedEvent Value);
	void __fastcall FormSize(System::TObject* Sender);
	
protected:
	virtual void __fastcall CheckDropDownPoint(int &X, int &Y);
	virtual bool __fastcall CheckKeyForDropDownWindow(System::Word Key, System::Classes::TShiftState Shift);
	bool __fastcall DoCanSelectNode(void);
	virtual void __fastcall DoSelectedNodeChanged(void);
	virtual void __fastcall DrawInterior(Dxbar::TdxBarEditControl* ABarEditControl, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, Dxbar::TdxBarItemLink* ItemLink);
	DYNAMIC void __fastcall DropDown(int X, int Y);
	virtual HWND __fastcall GetDropDownWindow(void);
	bool __fastcall HasImageInEdit(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetText(System::UnicodeString Value);
	
public:
	__fastcall virtual TdxBarTreeViewCombo(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarTreeViewCombo(void);
	DYNAMIC void __fastcall DoClick(void);
	__property Vcl::Comctrls::TTreeNode* SelectedNode = {read=FSelectedNode, write=SetSelectedNode};
	__property TdxBarTreeView* TreeView = {read=FTreeView};
	
__published:
	__property bool AllowResizing = {read=FAllowResizing, write=FAllowResizing, default=1};
	__property bool ChooseByDblClick = {read=FChooseByDblClick, write=FChooseByDblClick, default=1};
	__property int DropDownHeight = {read=GetDropDownHeight, write=SetDropDownHeight, default=200};
	__property int DropDownWidth = {read=GetDropDownWidth, write=SetDropDownWidth, default=150};
	__property bool FullExpand = {read=FFullExpand, write=FFullExpand, default=0};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property int Indent = {read=GetIndent, write=SetIndent, nodefault};
	__property Vcl::Comctrls::TTreeNodes* Items = {read=GetItems, write=SetItems};
	__property bool ShowButtons = {read=GetShowButtons, write=SetShowButtons, nodefault};
	__property ShowEditor = {default=0};
	__property bool ShowImageInEdit = {read=FShowImageInEdit, write=SetShowImageInEdit, default=1};
	__property bool ShowLines = {read=GetShowLines, write=SetShowLines, nodefault};
	__property bool ShowRoot = {read=GetShowRoot, write=SetShowRoot, nodefault};
	__property Vcl::Comctrls::TSortType SortType = {read=GetSortType, write=SetSortType, nodefault};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=GetStateImages, write=SetStateImages};
	__property Vcl::Comctrls::TTVExpandedEvent OnExpanded = {read=GetOnExpanded, write=SetOnExpanded};
	__property Vcl::Comctrls::TTVExpandingEvent OnExpanding = {read=GetOnExpanding, write=SetOnExpanding};
	__property TdxBarTreeViewComboCanSelectNodeEvent OnCanSelectNode = {read=FOnCanSelectNode, write=FOnCanSelectNode};
	__property Vcl::Comctrls::TTVChangingEvent OnChanging = {read=GetOnChanging, write=SetOnChanging};
	__property Vcl::Comctrls::TTVExpandedEvent OnCollapsed = {read=GetOnCollapsed, write=SetOnCollapsed};
	__property Vcl::Comctrls::TTVCollapsingEvent OnCollapsing = {read=GetOnCollapsing, write=SetOnCollapsing};
	__property Vcl::Comctrls::TTVCompareEvent OnCompare = {read=GetOnCompare, write=SetOnCompare};
	__property Vcl::Comctrls::TTVExpandedEvent OnGetImageIndex = {read=GetOnGetImageIndex, write=SetOnGetImageIndex};
	__property Vcl::Comctrls::TTVExpandedEvent OnGetSelectedIndex = {read=GetOnGetSelectedIndex, write=SetOnGetSelectedIndex};
	__property Vcl::Comctrls::TTVChangedEvent OnTreeViewChange = {read=GetOnTreeViewChange, write=SetOnTreeViewChange};
};


class DELPHICLASS TdxBarTreeViewComboControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarTreeViewComboControl : public Dxbar::TCustomdxBarComboControl
{
	typedef Dxbar::TCustomdxBarComboControl inherited;
	
private:
	HIDESBASE TdxBarTreeViewCombo* __fastcall GetItem(void);
	
protected:
	virtual int __fastcall GetDefaultHeight(void);
	virtual void __fastcall SetFocused(bool Value);
	
public:
	__property TdxBarTreeViewCombo* Item = {read=GetItem};
public:
	/* TCustomdxBarComboControl.Destroy */ inline __fastcall virtual ~TdxBarTreeViewComboControl(void) { }
	
public:
	/* TdxBarEditControl.Create */ inline __fastcall virtual TdxBarTreeViewComboControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TCustomdxBarComboControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarImageCombo;
class PASCALIMPLEMENTATION TdxBarImageCombo : public Dxbar::TdxBarCustomCombo
{
	typedef Dxbar::TdxBarCustomCombo inherited;
	
private:
	Vcl::Stdctrls::TListBox* FDialogListBox;
	Vcl::Forms::TForm* FForm;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	Vcl::Imglist::TCustomImageList* FImages;
	bool FShowText;
	int __fastcall GetImageIndexes(int Index);
	void __fastcall SetImageIndexes(int Index, int Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetShowText(bool Value);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall ReadImageIndexes(System::Classes::TReader* Reader);
	void __fastcall WriteImageIndexes(System::Classes::TWriter* Writer);
	void __fastcall DialogListBoxDblClick(System::TObject* Sender);
	void __fastcall DialogListBoxDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall DialogListBoxMeasureItem(Vcl::Controls::TWinControl* Control, int Index, int &Height);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DrawItem(Dxbar::TdxBarPainter* APainter, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall ImagesChanged(void);
	virtual void __fastcall MeasureItem(int AIndex, int &AHeight);
	virtual void __fastcall MeasureItemWidth(int AIndex, int &AWidth);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TdxBarImageCombo(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarImageCombo(void);
	DYNAMIC void __fastcall DoClick(void);
	__property int ImageIndexes[int Index] = {read=GetImageIndexes, write=SetImageIndexes};
	
__published:
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property Items;
	__property ShowEditor = {default=0};
	__property Sorted = {default=0};
	__property ItemIndex;
	__property bool ShowText = {read=FShowText, write=SetShowText, default=1};
};


class DELPHICLASS TdxBarImageComboControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarImageComboControl : public Dxbar::TdxBarComboControl
{
	typedef Dxbar::TdxBarComboControl inherited;
	
protected:
	virtual int __fastcall GetDefaultHeight(void);
	virtual void __fastcall ImagesChanged(void);
public:
	/* TCustomdxBarComboControl.Destroy */ inline __fastcall virtual ~TdxBarImageComboControl(void) { }
	
public:
	/* TdxBarEditControl.Create */ inline __fastcall virtual TdxBarImageComboControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarComboControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarToolbarsListItem;
class PASCALIMPLEMENTATION TdxBarToolbarsListItem : public Dxbar::TCustomdxBarSubItem
{
	typedef Dxbar::TCustomdxBarSubItem inherited;
	
protected:
	virtual bool __fastcall InternalCanMergeWith(Dxbar::TdxBarItem* AItem);
	
__published:
	__property BarSize = {default=0};
	__property Detachable = {default=0};
	__property DetachingBar = {default=-1};
	__property Glyph;
	__property ImageIndex = {default=-1};
	__property LargeGlyph;
	__property LargeImageIndex = {default=-1};
	__property ShowCaption = {default=1};
	__property OnClick;
	__property OnDetaching;
	__property OnPaintBar;
public:
	/* TCustomdxBarSubItem.Create */ inline __fastcall virtual TdxBarToolbarsListItem(System::Classes::TComponent* AOwner) : Dxbar::TCustomdxBarSubItem(AOwner) { }
	/* TCustomdxBarSubItem.Destroy */ inline __fastcall virtual ~TdxBarToolbarsListItem(void) { }
	
};


class DELPHICLASS TdxBarToolbarsListItemControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarToolbarsListItemControl : public Dxbar::TdxBarSubItemControl
{
	typedef Dxbar::TdxBarSubItemControl inherited;
	
protected:
	virtual void __fastcall CreateSubMenuControl(void);
public:
	/* TdxBarSubItemControl.Destroy */ inline __fastcall virtual ~TdxBarToolbarsListItemControl(void) { }
	
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxBarToolbarsListItemControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarSubItemControl(AItemLink) { }
	
};

#pragma pack(pop)

enum TdxBarSpinEditValueType : unsigned char { svtInteger, svtFloat };

enum TdxBarSpinEditPrefixPlace : unsigned char { ppStart, ppEnd };

class DELPHICLASS TdxBarSpinEdit;
typedef void __fastcall (__closure *TdxBarSpinEditButtonClickEvent)(TdxBarSpinEdit* Sender, Dxbar::TdxBarSpinEditButton Button);

class PASCALIMPLEMENTATION TdxBarSpinEdit : public Dxbar::TdxBarEdit
{
	typedef Dxbar::TdxBarEdit inherited;
	
private:
	System::Extended FIncrement;
	System::Extended FMaxValue;
	System::Extended FMinValue;
	System::UnicodeString FPrefix;
	TdxBarSpinEditPrefixPlace FPrefixPlace;
	TdxBarSpinEditValueType FValueType;
	TdxBarSpinEditButtonClickEvent FOnButtonClick;
	System::Extended __fastcall GetCurValue(void);
	int __fastcall GetIntCurValue(void);
	int __fastcall GetIntValue(void);
	System::Extended __fastcall GetValue(void);
	void __fastcall SetCurValue(System::Extended Value);
	void __fastcall SetIncrement(System::Extended Value);
	void __fastcall SetIntCurValue(int Value);
	void __fastcall SetIntValue(int Value);
	void __fastcall SetMaxValue(System::Extended Value);
	void __fastcall SetMinValue(System::Extended Value);
	void __fastcall SetPrefix(const System::UnicodeString Value);
	void __fastcall SetPrefixPlace(TdxBarSpinEditPrefixPlace Value);
	void __fastcall SetValue(System::Extended Value);
	void __fastcall SetValueType(TdxBarSpinEditValueType Value);
	bool __fastcall IsIncrementStored(void);
	bool __fastcall IsMaxValueStored(void);
	bool __fastcall IsMinValueStored(void);
	bool __fastcall IsValueStored(void);
	void __fastcall AddPrefix(System::UnicodeString &Text);
	void __fastcall RemovePrefix(System::UnicodeString &Text);
	
protected:
	bool __fastcall CheckRange(void);
	void __fastcall DoButtonClick(Dxbar::TdxBarSpinEditButton Button);
	System::Extended __fastcall GetCheckedValue(System::Extended Value);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall PrepareValue(System::Extended &Value);
	System::Extended __fastcall TextToValue(System::UnicodeString Text);
	virtual void __fastcall SetText(System::UnicodeString Value);
	System::UnicodeString __fastcall ValueToText(System::Extended Value);
	
public:
	__fastcall virtual TdxBarSpinEdit(System::Classes::TComponent* AOwner);
	__property System::Extended CurValue = {read=GetCurValue, write=SetCurValue};
	__property int IntCurValue = {read=GetIntCurValue, write=SetIntCurValue, nodefault};
	__property int IntValue = {read=GetIntValue, write=SetIntValue, nodefault};
	
__published:
	__property TdxBarSpinEditValueType ValueType = {read=FValueType, write=SetValueType, default=0};
	__property System::Extended Increment = {read=FIncrement, write=SetIncrement, stored=IsIncrementStored};
	__property System::Extended MaxValue = {read=FMaxValue, write=SetMaxValue, stored=IsMaxValueStored};
	__property System::Extended MinValue = {read=FMinValue, write=SetMinValue, stored=IsMinValueStored};
	__property System::UnicodeString Prefix = {read=FPrefix, write=SetPrefix};
	__property TdxBarSpinEditPrefixPlace PrefixPlace = {read=FPrefixPlace, write=SetPrefixPlace, default=1};
	__property Text = {stored=false, default=0};
	__property System::Extended Value = {read=GetValue, write=SetValue, stored=IsValueStored};
	__property TdxBarSpinEditButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxBarSpinEdit(void) { }
	
};


class DELPHICLASS TdxBarSpinEditControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarSpinEditControl : public Dxbar::TdxBarEditControl
{
	typedef Dxbar::TdxBarEditControl inherited;
	
private:
	int FActiveButtonIndex;
	int FPressedButtonIndex;
	unsigned FTimerID;
	Dxbar::TdxBarSpinEditButton __fastcall GetActiveButton(void);
	bool __fastcall GetButtonPressed(void);
	HIDESBASE Dxbar::TdxBarSpinEditDrawParams* __fastcall GetDrawParams(void);
	HIDESBASE TdxBarSpinEdit* __fastcall GetItem(void);
	void __fastcall SetActiveButtonIndex(int Value);
	
protected:
	void __fastcall BreakProcess(void);
	virtual void __fastcall CalcDrawParams(bool AFull = true);
	virtual void __fastcall CalcParts(void);
	virtual void __fastcall CorrectFrameRect(System::Types::TRect &ARect);
	virtual void __fastcall DrawTextField(void);
	virtual Dxbar::TdxBarItemControlDrawParamsClass __fastcall GetDrawParamsClass(void);
	virtual int __fastcall GetPartCount(void);
	DYNAMIC void __fastcall KillFocus(NativeUInt AHandle);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property Dxbar::TdxBarSpinEditButton ActiveButton = {read=GetActiveButton, nodefault};
	__property int ActiveButtonIndex = {read=FActiveButtonIndex, write=SetActiveButtonIndex, nodefault};
	__property bool ButtonPressed = {read=GetButtonPressed, nodefault};
	__property Dxbar::TdxBarSpinEditDrawParams* DrawParams = {read=GetDrawParams};
	
public:
	__property TdxBarSpinEdit* Item = {read=GetItem};
public:
	/* TdxBarEditControl.Create */ inline __fastcall virtual TdxBarSpinEditControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarEditControl(AItemLink) { }
	/* TdxBarEditControl.Destroy */ inline __fastcall virtual ~TdxBarSpinEditControl(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarControlContainerItem;
class PASCALIMPLEMENTATION TdxBarControlContainerItem : public Dxbar::TdxBarItem
{
	typedef Dxbar::TdxBarItem inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	bool FIsControlRecreating;
	Vcl::Forms::TCustomForm* FPlace;
	System::Types::TPoint FPrevControlSize;
	Cxcontrols::TcxWindowProcLinkedObject* FWindowProcObject;
	bool __fastcall GetControlVisible(void);
	bool __fastcall GetInPlaceControl(void);
	void __fastcall SetControl(Vcl::Controls::TControl* Value);
	void __fastcall ControlWndProc(Winapi::Messages::TMessage &Message);
	bool __fastcall IsControlAssigned(Vcl::Controls::TControl* AControl);
	void __fastcall SaveControlSize(void);
	void __fastcall SetControlVisible(bool Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	virtual bool __fastcall CanClicked(void);
	virtual bool __fastcall GetHidden(void);
	virtual bool __fastcall HasAccel(Dxbar::TdxBarItemLink* AItemLink);
	virtual void __fastcall HideControl(Dxbar::TdxBarItemControl* AControl);
	virtual bool __fastcall NeedToBeHidden(void);
	__property bool ControlVisible = {read=GetControlVisible, write=SetControlVisible, nodefault};
	__property bool InPlaceControl = {read=GetInPlaceControl, nodefault};
	__property Vcl::Forms::TCustomForm* Place = {read=FPlace};
	
public:
	__fastcall virtual TdxBarControlContainerItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarControlContainerItem(void);
	
__published:
	__property Vcl::Controls::TControl* Control = {read=FControl, write=SetControl};
};


class DELPHICLASS TdxBarControlContainerControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarControlContainerControl : public Dxbar::TdxBarItemControl
{
	typedef Dxbar::TdxBarItemControl inherited;
	
private:
	bool FInPlaceControl;
	bool FPlacedControl;
	HIDESBASE TdxBarControlContainerItem* __fastcall GetItem(void);
	Vcl::Forms::TCustomForm* __fastcall GetPlace(void);
	void __fastcall InternalPaint(void);
	void __fastcall PlaceControl(void);
	
protected:
	virtual void __fastcall BeforeDestroyParentHandle(void);
	virtual void __fastcall CalcParts(void);
	virtual bool __fastcall CanClicked(void);
	virtual bool __fastcall CanSelect(void);
	virtual void __fastcall DoPaint(const System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	virtual Vcl::Controls::TControl* __fastcall GetControl(void);
	virtual int __fastcall GetDefaultHeight(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual bool __fastcall CanDestroyOnClick(void);
	bool __fastcall IsShowingControl(void);
	virtual bool __fastcall NeedCaptureMouse(void);
	virtual void __fastcall RealVisibleChanging(bool AVisible);
	bool __fastcall ShowsControl(void);
	__property bool InPlaceControl = {read=FInPlaceControl, nodefault};
	__property Vcl::Forms::TCustomForm* Place = {read=GetPlace};
	
public:
	__fastcall virtual ~TdxBarControlContainerControl(void);
	__property TdxBarControlContainerItem* Item = {read=GetItem};
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxBarControlContainerControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarItemControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarProgressItem;
class PASCALIMPLEMENTATION TdxBarProgressItem : public TdxBarStatic
{
	typedef TdxBarStatic inherited;
	
private:
	System::Uitypes::TColor FColor;
	int FMax;
	int FMin;
	int FPosition;
	bool FSmooth;
	int FStep;
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetMin(int Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetSmooth(bool Value);
	void __fastcall SetStep(int Value);
	
protected:
	void __fastcall UpdateBar(void);
	void __fastcall UpdateDifference(void);
	
public:
	__fastcall virtual TdxBarProgressItem(System::Classes::TComponent* AOwner);
	void __fastcall SetParams(int AMin, int AMax);
	void __fastcall StepBy(int Delta);
	void __fastcall StepIt(void);
	
__published:
	__property BorderStyle = {default=1};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property int Max = {read=FMax, write=SetMax, default=100};
	__property int Min = {read=FMin, write=SetMin, default=0};
	__property int Position = {read=FPosition, write=SetPosition, default=0};
	__property bool Smooth = {read=FSmooth, write=SetSmooth, default=0};
	__property int Step = {read=FStep, write=SetStep, default=10};
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxBarProgressItem(void) { }
	
};


class DELPHICLASS TdxBarProgressControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarProgressControl : public TdxBarStaticControl
{
	typedef TdxBarStaticControl inherited;
	
private:
	int FPrevPos;
	HIDESBASE Dxbar::TdxBarProgressControlDrawParams* __fastcall GetDrawParams(void);
	HIDESBASE TdxBarProgressItem* __fastcall GetItem(void);
	int __fastcall CalculateBandDrawPosition(const System::Types::TRect &ABandRect);
	
protected:
	virtual unsigned __fastcall BarBrushColor(void);
	int __fastcall BarHeight(void);
	System::Types::TRect __fastcall BarRect(void);
	int __fastcall BarWidth(void);
	virtual void __fastcall CalcDrawParams(bool AFull);
	virtual bool __fastcall CanHaveZeroSize(void);
	virtual void __fastcall DrawInterior(const System::Types::TRect &ARect);
	virtual System::Classes::TAlignment __fastcall GetAlignment(void);
	virtual Dxbar::TdxBarItemControlDrawParamsClass __fastcall GetDrawParamsClass(void);
	virtual Dxbar::TdxBarItemViewLevels __fastcall GetPossibleViewLevels(void);
	virtual int __fastcall InternalGetDefaultHeight(void);
	virtual int __fastcall InternalGetDefaultWidth(void);
	void __fastcall UpdateBar(void);
	void __fastcall UpdateDifference(void);
	__property Dxbar::TdxBarProgressControlDrawParams* DrawParams = {read=GetDrawParams};
	
public:
	__property TdxBarProgressItem* Item = {read=GetItem};
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxBarProgressControl(Dxbar::TdxBarItemLink* AItemLink) : TdxBarStaticControl(AItemLink) { }
	/* TdxBarItemControl.Destroy */ inline __fastcall virtual ~TdxBarProgressControl(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarMRUListItem;
class PASCALIMPLEMENTATION TdxBarMRUListItem : public Dxbar::TdxBarListItem
{
	typedef Dxbar::TdxBarListItem inherited;
	
private:
	int FMaxItemCount;
	bool FRemoveItemOnClick;
	void __fastcall SetMaxItemCount(int Value);
	
protected:
	void __fastcall CheckItemCount(void);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::UnicodeString AText)/* overload */;
	
public:
	__fastcall virtual TdxBarMRUListItem(System::Classes::TComponent* AOwner);
	DYNAMIC void __fastcall DirectClick(void);
	void __fastcall AddItem(const System::UnicodeString S, System::TObject* AObject);
	void __fastcall RemoveItem(const System::UnicodeString S, System::TObject* AObject);
	
__published:
	__property int MaxItemCount = {read=FMaxItemCount, write=SetMaxItemCount, default=5};
	__property bool RemoveItemOnClick = {read=FRemoveItemOnClick, write=FRemoveItemOnClick, default=0};
public:
	/* TdxBarListItem.Destroy */ inline __fastcall virtual ~TdxBarMRUListItem(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline System::UnicodeString __fastcall  GetDisplayText(int AItemIndex){ return Dxbar::TdxBarListItem::GetDisplayText(AItemIndex); }
	
};


class DELPHICLASS TdxBarInPlaceSubItem;
typedef void __fastcall (__closure *TdxBarInPlaceSubItemEvent)(TdxBarInPlaceSubItem* Sender, Dxbar::TdxBarItemLink* Link);

class PASCALIMPLEMENTATION TdxBarInPlaceSubItem : public Dxbar::TdxBarContainerItem
{
	typedef Dxbar::TdxBarContainerItem inherited;
	
private:
	bool FExpanded;
	bool FExpandedChanging;
	bool FKeepBeginGroupWhileExpanded;
	TdxBarInPlaceSubItemEvent FOnAfterExpand;
	TdxBarInPlaceSubItemEvent FOnBeforeCollapse;
	void __fastcall SetExpanded(bool Value);
	
protected:
	virtual void __fastcall DeleteListedItemLinks(System::TObject* ALinkData);
	virtual bool __fastcall HideWhenRun(void);
	virtual bool __fastcall InternalActuallyVisible(void);
	virtual bool __fastcall InternalCanMergeWith(Dxbar::TdxBarItem* AItem);
	virtual void __fastcall PopulateListedItemLinks(Dxbar::TdxBarItemLinks* AItemLinks, System::TObject* ALinkData, int AIndex);
	virtual void __fastcall PrepareListedItemLinks(void);
	void __fastcall ChangeNextItemLinkBeginGroup(Dxbar::TdxBarItemLink* ALink, bool Value);
	DYNAMIC void __fastcall DoAfterExpand(Dxbar::TdxBarItemLink* ALink);
	DYNAMIC void __fastcall DoBeforeCollapse(Dxbar::TdxBarItemLink* ALink);
	
__published:
	__property bool Expanded = {read=FExpanded, write=SetExpanded, default=0};
	__property bool KeepBeginGroupWhileExpanded = {read=FKeepBeginGroupWhileExpanded, write=FKeepBeginGroupWhileExpanded, nodefault};
	__property TdxBarInPlaceSubItemEvent OnAfterExpand = {read=FOnAfterExpand, write=FOnAfterExpand};
	__property TdxBarInPlaceSubItemEvent OnBeforeCollapse = {read=FOnBeforeCollapse, write=FOnBeforeCollapse};
public:
	/* TdxBarContainerItem.Create */ inline __fastcall virtual TdxBarInPlaceSubItem(System::Classes::TComponent* AOwner) : Dxbar::TdxBarContainerItem(AOwner) { }
	
public:
	/* TCustomdxBarSubItem.Destroy */ inline __fastcall virtual ~TdxBarInPlaceSubItem(void) { }
	
};


class DELPHICLASS TdxBarInPlaceSubItemControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarInPlaceSubItemControl : public Dxbar::TdxBarContainerItemControl
{
	typedef Dxbar::TdxBarContainerItemControl inherited;
	
private:
	HIDESBASE Dxbar::TdxBarInPlaceSubItemControlDrawParams* __fastcall GetDrawParams(void);
	HIDESBASE TdxBarInPlaceSubItem* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall CalcDrawParams(bool AFull = false);
	virtual void __fastcall ControlClick(bool AByMouse, System::WideChar AKey = (System::WideChar)(0x0));
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DoPaint(const System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual int __fastcall GetDefaultHeight(void);
	virtual int __fastcall GetDefaultWidth(void);
	virtual Dxbar::TdxBarItemControlDrawParamsClass __fastcall GetDrawParamsClass(void);
	virtual bool __fastcall HasSubMenu(void);
	virtual bool __fastcall IsExpandable(void);
	virtual bool __fastcall IsInvertTextColor(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall WantsKey(System::Word Key);
	__property Dxbar::TdxBarInPlaceSubItemControlDrawParams* DrawParams = {read=GetDrawParams};
	
public:
	__property TdxBarInPlaceSubItem* Item = {read=GetItem};
public:
	/* TdxBarSubItemControl.Destroy */ inline __fastcall virtual ~TdxBarInPlaceSubItemControl(void) { }
	
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxBarInPlaceSubItemControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarContainerItemControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarInPlaceSubItemControlAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarInPlaceSubItemControlAccessibilityHelper : public Dxbaraccessibility::TdxBarSubItemControlAccessibilityHelper
{
	typedef Dxbaraccessibility::TdxBarSubItemControlAccessibilityHelper inherited;
	
protected:
	virtual bool __fastcall ShowDropDownWindow(void);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarInPlaceSubItemControlAccessibilityHelper(System::TObject* AOwnerObject) : Dxbaraccessibility::TdxBarSubItemControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarInPlaceSubItemControlAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall sdxBarDatePopupToday(void);
extern PACKAGE System::UnicodeString __fastcall sdxBarDatePopupClear(void);
extern PACKAGE Vcl::Dialogs::TColorDialog* __fastcall dxBarColorDialog(void);
extern PACKAGE Vcl::Dialogs::TFontDialog* __fastcall dxBarFontDialog(void);
}	/* namespace Dxbarextitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBAREXTITEMS)
using namespace Dxbarextitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarextitemsHPP
