// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutLookAndFeels.pas' rev: 24.00 (Win32)

#ifndef DxlayoutlookandfeelsHPP
#define DxlayoutlookandfeelsHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxLayoutCommon.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutlookandfeels
{
//-- type declarations -------------------------------------------------------
__interface IdxLayoutLookAndFeelUser;
typedef System::DelphiInterface<IdxLayoutLookAndFeelUser> _di_IdxLayoutLookAndFeelUser;
__interface  INTERFACE_UUID("{651F19FE-CBCB-4C16-8615-BBD57ED7255A}") IdxLayoutLookAndFeelUser  : public System::IInterface 
{
	
public:
	virtual void __stdcall BeginLookAndFeelDestroying(void) = 0 ;
	virtual void __stdcall EndLookAndFeelDestroying(void) = 0 ;
	virtual void __stdcall LookAndFeelChanged(void) = 0 ;
	virtual void __stdcall LookAndFeelDestroyed(void) = 0 ;
};

class DELPHICLASS TdxCustomLayoutLookAndFeelPart;
class DELPHICLASS TdxCustomLayoutLookAndFeel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutLookAndFeelPart : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxCustomLayoutLookAndFeel* FLookAndFeel;
	
protected:
	virtual void __fastcall Changed(void);
	__property TdxCustomLayoutLookAndFeel* LookAndFeel = {read=FLookAndFeel};
	
public:
	__fastcall virtual TdxCustomLayoutLookAndFeelPart(TdxCustomLayoutLookAndFeel* ALookAndFeel);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomLayoutLookAndFeelPart(void) { }
	
};

#pragma pack(pop)

enum TdxLayoutHotTrackStyle : unsigned char { htsHandPoint, htsUnderlineCold, htsUnderlineHot };

typedef System::Set<TdxLayoutHotTrackStyle, TdxLayoutHotTrackStyle::htsHandPoint, TdxLayoutHotTrackStyle::htsUnderlineHot>  TdxLayoutHotTrackStyles;

typedef System::TMetaClass* TdxLayoutLookAndFeelCaptionOptionsClass;

class DELPHICLASS TdxLayoutLookAndFeelCaptionOptions;
class DELPHICLASS TdxCustomLayoutLookAndFeelOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLookAndFeelCaptionOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Vcl::Graphics::TFont* FFont;
	bool FHotTrack;
	TdxLayoutHotTrackStyles FHotTrackStyles;
	TdxCustomLayoutLookAndFeelOptions* FOptions;
	System::Uitypes::TColor FTextColor;
	System::Uitypes::TColor FTextDisabledColor;
	System::Uitypes::TColor FTextHotColor;
	bool FUseDefaultFont;
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetHotTrackStyles(TdxLayoutHotTrackStyles Value);
	void __fastcall SetTextColor(System::Uitypes::TColor Value);
	void __fastcall SetTextDisabledColor(System::Uitypes::TColor Value);
	void __fastcall SetTextHotColor(System::Uitypes::TColor Value);
	void __fastcall SetUseDefaultFont(bool Value);
	void __fastcall FontChanged(System::TObject* Sender);
	bool __fastcall IsFontStored(void);
	
protected:
	virtual void __fastcall Changed(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetDefaultTextDisabledColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextHotColor(void);
	virtual Vcl::Graphics::TFont* __fastcall GetDefaultFont(System::Classes::TComponent* AContainer);
	__property TdxCustomLayoutLookAndFeelOptions* Options = {read=FOptions};
	
public:
	__fastcall virtual TdxLayoutLookAndFeelCaptionOptions(TdxCustomLayoutLookAndFeelOptions* AOptions);
	__fastcall virtual ~TdxLayoutLookAndFeelCaptionOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::Uitypes::TColor __fastcall GetTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetTextDisabledColor(void);
	virtual System::Uitypes::TColor __fastcall GetTextHotColor(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(System::Classes::TComponent* AContainer);
	
__published:
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property bool HotTrack = {read=FHotTrack, write=SetHotTrack, default=0};
	__property TdxLayoutHotTrackStyles HotTrackStyles = {read=FHotTrackStyles, write=SetHotTrackStyles, default=5};
	__property System::Uitypes::TColor TextColor = {read=FTextColor, write=SetTextColor, default=536870912};
	__property System::Uitypes::TColor TextDisabledColor = {read=FTextDisabledColor, write=SetTextDisabledColor, default=536870912};
	__property System::Uitypes::TColor TextHotColor = {read=FTextHotColor, write=SetTextHotColor, default=536870912};
	__property bool UseDefaultFont = {read=FUseDefaultFont, write=SetUseDefaultFont, default=1};
};

#pragma pack(pop)

enum TdxLayoutPaddingAssignedValue : unsigned char { lpavBottom, lpavLeft, lpavRight, lpavTop };

typedef System::Set<TdxLayoutPaddingAssignedValue, TdxLayoutPaddingAssignedValue::lpavBottom, TdxLayoutPaddingAssignedValue::lpavTop>  TdxLayoutPaddingAssignedValues;

class DELPHICLASS TdxLayoutLookAndFeelPadding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLookAndFeelPadding : public TdxCustomLayoutLookAndFeelPart
{
	typedef TdxCustomLayoutLookAndFeelPart inherited;
	
private:
	TdxLayoutPaddingAssignedValues FAssignedValues;
	int FBottom;
	int FLeft;
	int FRight;
	int FTop;
	int __fastcall GetValue(int Index);
	bool __fastcall IsValueStored(int Index);
	void __fastcall SetAssignedValues(TdxLayoutPaddingAssignedValues Value);
	
protected:
	virtual int __fastcall GetDefaultValue(int Index);
	virtual void __fastcall SetValue(int Index, int Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::Types::TRect __fastcall GetPaddingRect(void);
	
__published:
	__property TdxLayoutPaddingAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property int Bottom = {read=GetValue, write=SetValue, stored=IsValueStored, index=1, nodefault};
	__property int Left = {read=GetValue, write=SetValue, stored=IsValueStored, index=2, nodefault};
	__property int Right = {read=GetValue, write=SetValue, stored=IsValueStored, index=3, nodefault};
	__property int Top = {read=GetValue, write=SetValue, stored=IsValueStored, index=4, nodefault};
public:
	/* TdxCustomLayoutLookAndFeelPart.Create */ inline __fastcall virtual TdxLayoutLookAndFeelPadding(TdxCustomLayoutLookAndFeel* ALookAndFeel) : TdxCustomLayoutLookAndFeelPart(ALookAndFeel) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutLookAndFeelPadding(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxLayoutLookAndFeelPaddingClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutLookAndFeelOptions : public TdxCustomLayoutLookAndFeelPart
{
	typedef TdxCustomLayoutLookAndFeelPart inherited;
	
private:
	TdxLayoutLookAndFeelCaptionOptions* FCaptionOptions;
	TdxLayoutLookAndFeelPadding* FPadding;
	void __fastcall SetCaptionOptions(TdxLayoutLookAndFeelCaptionOptions* Value);
	void __fastcall SetPadding(TdxLayoutLookAndFeelPadding* const Value);
	
protected:
	virtual TdxLayoutLookAndFeelCaptionOptionsClass __fastcall GetCaptionOptionsClass(void);
	virtual TdxLayoutLookAndFeelPaddingClass __fastcall GetPaddingClass(void);
	
public:
	__fastcall virtual TdxCustomLayoutLookAndFeelOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel);
	__fastcall virtual ~TdxCustomLayoutLookAndFeelOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxLayoutLookAndFeelCaptionOptions* CaptionOptions = {read=FCaptionOptions, write=SetCaptionOptions};
	__property TdxLayoutLookAndFeelPadding* Padding = {read=FPadding, write=SetPadding};
};

#pragma pack(pop)

typedef System::TMetaClass* TdxLayoutLookAndFeelGroupOptionsClass;

class DELPHICLASS TdxLayoutLookAndFeelGroupOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLookAndFeelGroupOptions : public TdxCustomLayoutLookAndFeelOptions
{
	typedef TdxCustomLayoutLookAndFeelOptions inherited;
	
private:
	System::Uitypes::TColor FColor;
	unsigned FSpaceBetweenButtons;
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetSpaceBetweenButtons(unsigned AValue);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultColor(void) = 0 ;
	
public:
	__fastcall virtual TdxLayoutLookAndFeelGroupOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property unsigned SpaceBetweenButtons = {read=FSpaceBetweenButtons, write=SetSpaceBetweenButtons, default=0};
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TdxLayoutLookAndFeelGroupOptions(void) { }
	
};

#pragma pack(pop)

enum TdxLayoutBorderStyle : unsigned char { lbsNone, lbsSingle, lbsFlat, lbsStandard };

typedef System::TMetaClass* TdxLayoutLookAndFeelItemOptionsClass;

class DELPHICLASS TdxLayoutLookAndFeelItemOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLookAndFeelItemOptions : public TdxCustomLayoutLookAndFeelOptions
{
	typedef TdxCustomLayoutLookAndFeelOptions inherited;
	
private:
	System::Uitypes::TColor FControlBorderColor;
	TdxLayoutBorderStyle FControlBorderStyle;
	void __fastcall SetControlBorderColor(System::Uitypes::TColor Value);
	void __fastcall SetControlBorderStyle(TdxLayoutBorderStyle Value);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultControlBorderColor(void);
	
public:
	__fastcall virtual TdxLayoutLookAndFeelItemOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::Uitypes::TColor __fastcall GetControlBorderColor(void);
	
__published:
	__property System::Uitypes::TColor ControlBorderColor = {read=FControlBorderColor, write=SetControlBorderColor, default=536870912};
	__property TdxLayoutBorderStyle ControlBorderStyle = {read=FControlBorderStyle, write=SetControlBorderStyle, default=3};
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TdxLayoutLookAndFeelItemOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxLayoutLookAndFeelOffsetsClass;

class DELPHICLASS TdxLayoutLookAndFeelOffsets;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLookAndFeelOffsets : public TdxCustomLayoutLookAndFeelPart
{
	typedef TdxCustomLayoutLookAndFeelPart inherited;
	
private:
	int FControlOffsetHorz;
	int FControlOffsetVert;
	int FItemOffset;
	int FItemsAreaOffsetHorz;
	int FItemsAreaOffsetVert;
	int FRootItemsAreaOffsetHorz;
	int FRootItemsAreaOffsetVert;
	
protected:
	virtual int __fastcall GetDefaultValue(int Index);
	virtual int __fastcall GetValue(int Index);
	bool __fastcall IsValueStored(int Index);
	virtual void __fastcall SetValue(int Index, int Value);
	
public:
	__fastcall virtual TdxLayoutLookAndFeelOffsets(TdxCustomLayoutLookAndFeel* ALookAndFeel);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int ControlOffsetHorz = {read=GetValue, write=SetValue, stored=IsValueStored, index=0, nodefault};
	__property int ControlOffsetVert = {read=GetValue, write=SetValue, stored=IsValueStored, index=1, nodefault};
	__property int ItemOffset = {read=GetValue, write=SetValue, stored=IsValueStored, index=2, nodefault};
	__property int ItemsAreaOffsetHorz = {read=GetValue, write=SetValue, stored=IsValueStored, index=3, nodefault};
	__property int ItemsAreaOffsetVert = {read=GetValue, write=SetValue, stored=IsValueStored, index=4, nodefault};
	__property int RootItemsAreaOffsetHorz = {read=GetValue, write=SetValue, stored=IsValueStored, index=5, nodefault};
	__property int RootItemsAreaOffsetVert = {read=GetValue, write=SetValue, stored=IsValueStored, index=6, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutLookAndFeelOffsets(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomLayoutLookAndFeelClass;

class DELPHICLASS TdxLayoutLookAndFeelList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutLookAndFeel : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TdxLayoutLookAndFeelGroupOptions* FGroupOptions;
	TdxLayoutLookAndFeelItemOptions* FItemOptions;
	TdxLayoutLookAndFeelList* FList;
	bool FNotifyingAboutDestroying;
	TdxLayoutLookAndFeelOffsets* FOffsets;
	System::Classes::TList* FUsers;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	bool __fastcall GetIsDesigning(void);
	_di_IdxLayoutLookAndFeelUser __fastcall GetUser(int Index);
	int __fastcall GetUserCount(void);
	void __fastcall SetGroupOptions(TdxLayoutLookAndFeelGroupOptions* Value);
	void __fastcall SetItemOptions(TdxLayoutLookAndFeelItemOptions* Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetOffsets(TdxLayoutLookAndFeelOffsets* Value);
	
protected:
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	void __fastcall Changed(void);
	__classmethod virtual System::UnicodeString __fastcall GetBaseName();
	void __fastcall GetTextMetric(Vcl::Graphics::TFont* AFont, tagTEXTMETRICW &ATextMetric);
	virtual int __fastcall GetFrameWidth(Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide);
	Vcl::Graphics::TFont* __fastcall GetGroupCaptionFont(System::Classes::TComponent* AContainer);
	Vcl::Graphics::TFont* __fastcall GetItemCaptionFont(System::Classes::TComponent* AContainer);
	virtual void __fastcall InitLookAndFeel(void);
	void __fastcall NotifyUsersAboutDestroying(void);
	virtual bool __fastcall DoesCxLookAndFeelHavePriority(void);
	virtual bool __fastcall IsGroupTransparent(void);
	virtual bool __fastcall IsNativeStyle(void);
	virtual bool __fastcall IsSkinPainterUsed(void);
	virtual TdxLayoutLookAndFeelGroupOptionsClass __fastcall GetGroupOptionsClass(void);
	virtual TdxLayoutLookAndFeelItemOptionsClass __fastcall GetItemOptionsClass(void);
	virtual TdxLayoutLookAndFeelOffsetsClass __fastcall GetOffsetsClass(void);
	virtual int __fastcall GetItemControlBorderWidth(Dxlayoutcommon::TdxLayoutSide ASide);
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property int UserCount = {read=GetUserCount, nodefault};
	__property _di_IdxLayoutLookAndFeelUser Users[int Index] = {read=GetUser};
	
public:
	__fastcall virtual TdxCustomLayoutLookAndFeel(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomLayoutLookAndFeel(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual bool __fastcall NeedDoubleBuffered(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual void __fastcall InitializeSubControlCxLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AcxLookAndFeel);
	void __fastcall AddUser(System::Classes::TComponent* AUser);
	void __fastcall RemoveUser(System::Classes::TComponent* AUser);
	__classmethod virtual System::UnicodeString __fastcall Description();
	int __fastcall DLUToPixels(Vcl::Graphics::TFont* AFont, int ADLU);
	int __fastcall HDLUToPixels(Vcl::Graphics::TFont* AFont, int ADLU);
	int __fastcall VDLUToPixels(Vcl::Graphics::TFont* AFont, int ADLU);
	virtual System::TClass __fastcall GetGroupPainterClass(void) = 0 ;
	virtual System::TClass __fastcall GetBasicItemPainterClass(void);
	virtual System::TClass __fastcall GetEmptySpaceItemPainterClass(void);
	virtual System::TClass __fastcall GetItemPainterClass(void);
	virtual System::TClass __fastcall GetLabeledItemPainterClass(void);
	virtual System::TClass __fastcall GetSeparatorItemPainterClass(void);
	virtual System::TClass __fastcall GetSplitterItemPainterClass(void);
	virtual System::TClass __fastcall GetGroupViewInfoClass(void);
	virtual System::TClass __fastcall GetItemViewInfoClass(void);
	virtual int __fastcall GetElementOffsetHorz(System::Classes::TComponent* AContainer);
	virtual int __fastcall GetElementOffsetVert(System::Classes::TComponent* AContainer);
	virtual int __fastcall GetGroupBorderOffset(System::Classes::TComponent* AContainer, Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide);
	virtual int __fastcall GetGroupBorderWidth(System::Classes::TComponent* AContainer, Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide, bool AHasCaption, bool AIsExpanded);
	virtual int __fastcall GetItemOffset(System::Classes::TComponent* AContainer);
	virtual int __fastcall GetItemsAreaOffsetHorz(System::Classes::TComponent* AContainer);
	virtual int __fastcall GetItemsAreaOffsetVert(System::Classes::TComponent* AContainer);
	virtual int __fastcall GetRootItemsAreaOffsetHorz(System::Classes::TComponent* AContainer);
	virtual int __fastcall GetRootItemsAreaOffsetVert(System::Classes::TComponent* AContainer);
	virtual int __fastcall GetSeparatorItemMinWidth(void);
	virtual System::Types::TSize __fastcall GetSplitterItemMinSize(void);
	virtual bool __fastcall IsButtonHotTrack(void);
	virtual void __fastcall DrawLayoutControlBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawItemControlBorder(Cxgraphics::TcxCanvas* ACanvas, TdxLayoutLookAndFeelItemOptions* AItemOptions, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetEmptyAreaColor(void);
	__property int FrameWidths[Dxlayoutcommon::TdxLayoutSide ASide][Dxlayoutcommon::TdxLayoutSide ACaptionSide] = {read=GetFrameWidth};
	__property int ItemControlBorderWidths[Dxlayoutcommon::TdxLayoutSide ASide] = {read=GetItemControlBorderWidth};
	__property TdxLayoutLookAndFeelList* List = {read=FList};
	
__published:
	__property TdxLayoutLookAndFeelGroupOptions* GroupOptions = {read=FGroupOptions, write=SetGroupOptions};
	__property TdxLayoutLookAndFeelItemOptions* ItemOptions = {read=FItemOptions, write=SetItemOptions};
	__property TdxLayoutLookAndFeelOffsets* Offsets = {read=FOffsets, write=SetOffsets};
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutStandardLookAndFeelGroupCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutStandardLookAndFeelGroupCaptionOptions : public TdxLayoutLookAndFeelCaptionOptions
{
	typedef TdxLayoutLookAndFeelCaptionOptions inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void);
public:
	/* TdxLayoutLookAndFeelCaptionOptions.Create */ inline __fastcall virtual TdxLayoutStandardLookAndFeelGroupCaptionOptions(TdxCustomLayoutLookAndFeelOptions* AOptions) : TdxLayoutLookAndFeelCaptionOptions(AOptions) { }
	/* TdxLayoutLookAndFeelCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutStandardLookAndFeelGroupCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutStandardLookAndFeelGroupOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutStandardLookAndFeelGroupOptions : public TdxLayoutLookAndFeelGroupOptions
{
	typedef TdxLayoutLookAndFeelGroupOptions inherited;
	
protected:
	virtual TdxLayoutLookAndFeelCaptionOptionsClass __fastcall GetCaptionOptionsClass(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultColor(void);
public:
	/* TdxLayoutLookAndFeelGroupOptions.Create */ inline __fastcall virtual TdxLayoutStandardLookAndFeelGroupOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel) : TdxLayoutLookAndFeelGroupOptions(ALookAndFeel) { }
	
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TdxLayoutStandardLookAndFeelGroupOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutStandardLookAndFeelItemCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutStandardLookAndFeelItemCaptionOptions : public TdxLayoutLookAndFeelCaptionOptions
{
	typedef TdxLayoutLookAndFeelCaptionOptions inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void);
public:
	/* TdxLayoutLookAndFeelCaptionOptions.Create */ inline __fastcall virtual TdxLayoutStandardLookAndFeelItemCaptionOptions(TdxCustomLayoutLookAndFeelOptions* AOptions) : TdxLayoutLookAndFeelCaptionOptions(AOptions) { }
	/* TdxLayoutLookAndFeelCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutStandardLookAndFeelItemCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutStandardLookAndFeelItemOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutStandardLookAndFeelItemOptions : public TdxLayoutLookAndFeelItemOptions
{
	typedef TdxLayoutLookAndFeelItemOptions inherited;
	
protected:
	virtual TdxLayoutLookAndFeelCaptionOptionsClass __fastcall GetCaptionOptionsClass(void);
public:
	/* TdxLayoutLookAndFeelItemOptions.Create */ inline __fastcall virtual TdxLayoutStandardLookAndFeelItemOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel) : TdxLayoutLookAndFeelItemOptions(ALookAndFeel) { }
	
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TdxLayoutStandardLookAndFeelItemOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutStandardLookAndFeel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutStandardLookAndFeel : public TdxCustomLayoutLookAndFeel
{
	typedef TdxCustomLayoutLookAndFeel inherited;
	
protected:
	virtual TdxLayoutLookAndFeelGroupOptionsClass __fastcall GetGroupOptionsClass(void);
	virtual TdxLayoutLookAndFeelItemOptionsClass __fastcall GetItemOptionsClass(void);
	virtual int __fastcall GetFrameWidth(Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide);
	virtual void __fastcall InitLookAndFeel(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Description();
	virtual System::TClass __fastcall GetGroupPainterClass(void);
	virtual System::TClass __fastcall GetGroupViewInfoClass(void);
	virtual int __fastcall GetGroupBorderWidth(System::Classes::TComponent* AContainer, Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide, bool AHasCaption, bool AIsExpanded);
public:
	/* TdxCustomLayoutLookAndFeel.Create */ inline __fastcall virtual TdxLayoutStandardLookAndFeel(System::Classes::TComponent* AOwner) : TdxCustomLayoutLookAndFeel(AOwner) { }
	/* TdxCustomLayoutLookAndFeel.Destroy */ inline __fastcall virtual ~TdxLayoutStandardLookAndFeel(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutOfficeLookAndFeel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutOfficeLookAndFeel : public TdxLayoutStandardLookAndFeel
{
	typedef TdxLayoutStandardLookAndFeel inherited;
	
protected:
	virtual int __fastcall GetFrameWidth(Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide);
	virtual void __fastcall InitLookAndFeel(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Description();
	virtual System::TClass __fastcall GetGroupPainterClass(void);
	virtual System::TClass __fastcall GetGroupViewInfoClass(void);
	virtual int __fastcall GetGroupBorderWidth(System::Classes::TComponent* AContainer, Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide, bool AHasCaption, bool AIsExpanded);
public:
	/* TdxCustomLayoutLookAndFeel.Create */ inline __fastcall virtual TdxLayoutOfficeLookAndFeel(System::Classes::TComponent* AOwner) : TdxLayoutStandardLookAndFeel(AOwner) { }
	/* TdxCustomLayoutLookAndFeel.Destroy */ inline __fastcall virtual ~TdxLayoutOfficeLookAndFeel(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutWebLookAndFeelGroupCaptionOptions;
class DELPHICLASS TdxLayoutWebLookAndFeelGroupOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutWebLookAndFeelGroupCaptionOptions : public TdxLayoutLookAndFeelCaptionOptions
{
	typedef TdxLayoutLookAndFeelCaptionOptions inherited;
	
private:
	System::Uitypes::TColor FColor;
	int FSeparatorWidth;
	TdxLayoutWebLookAndFeelGroupOptions* __fastcall GetOptions(void);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetSeparatorWidth(int Value);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void);
	virtual Vcl::Graphics::TFont* __fastcall GetDefaultFont(System::Classes::TComponent* AContainer);
	__property TdxLayoutWebLookAndFeelGroupOptions* Options = {read=GetOptions};
	
public:
	__fastcall virtual TdxLayoutWebLookAndFeelGroupCaptionOptions(TdxCustomLayoutLookAndFeelOptions* AOptions);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property int SeparatorWidth = {read=FSeparatorWidth, write=SetSeparatorWidth, default=0};
public:
	/* TdxLayoutLookAndFeelCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutWebLookAndFeelGroupCaptionOptions(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutWebLookAndFeelGroupOptions : public TdxLayoutLookAndFeelGroupOptions
{
	typedef TdxLayoutLookAndFeelGroupOptions inherited;
	
private:
	System::Uitypes::TColor FFrameColor;
	int FFrameWidth;
	bool FOffsetCaption;
	bool FOffsetItems;
	TdxLayoutWebLookAndFeelGroupCaptionOptions* __fastcall GetCaptionOptions(void);
	HIDESBASE void __fastcall SetCaptionOptions(TdxLayoutWebLookAndFeelGroupCaptionOptions* Value);
	void __fastcall SetFrameColor(System::Uitypes::TColor Value);
	void __fastcall SetFrameWidth(int Value);
	void __fastcall SetOffsetCaption(bool Value);
	void __fastcall SetOffsetItems(bool Value);
	
protected:
	virtual TdxLayoutLookAndFeelCaptionOptionsClass __fastcall GetCaptionOptionsClass(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultFrameColor(void);
	
public:
	__fastcall virtual TdxLayoutWebLookAndFeelGroupOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel);
	virtual System::Uitypes::TColor __fastcall GetFrameColor(void);
	bool __fastcall HasCaptionSeparator(bool AHasCaption);
	
__published:
	__property TdxLayoutWebLookAndFeelGroupCaptionOptions* CaptionOptions = {read=GetCaptionOptions, write=SetCaptionOptions};
	__property System::Uitypes::TColor FrameColor = {read=FFrameColor, write=SetFrameColor, default=536870912};
	__property int FrameWidth = {read=FFrameWidth, write=SetFrameWidth, default=1};
	__property bool OffsetCaption = {read=FOffsetCaption, write=SetOffsetCaption, default=1};
	__property bool OffsetItems = {read=FOffsetItems, write=SetOffsetItems, default=1};
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TdxLayoutWebLookAndFeelGroupOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutWebLookAndFeelItemCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutWebLookAndFeelItemCaptionOptions : public TdxLayoutLookAndFeelCaptionOptions
{
	typedef TdxLayoutLookAndFeelCaptionOptions inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void);
public:
	/* TdxLayoutLookAndFeelCaptionOptions.Create */ inline __fastcall virtual TdxLayoutWebLookAndFeelItemCaptionOptions(TdxCustomLayoutLookAndFeelOptions* AOptions) : TdxLayoutLookAndFeelCaptionOptions(AOptions) { }
	/* TdxLayoutLookAndFeelCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutWebLookAndFeelItemCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutWebLookAndFeelItemOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutWebLookAndFeelItemOptions : public TdxLayoutLookAndFeelItemOptions
{
	typedef TdxLayoutLookAndFeelItemOptions inherited;
	
protected:
	virtual TdxLayoutLookAndFeelCaptionOptionsClass __fastcall GetCaptionOptionsClass(void);
	
public:
	__fastcall virtual TdxLayoutWebLookAndFeelItemOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel);
	
__published:
	__property ControlBorderStyle = {default=1};
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TdxLayoutWebLookAndFeelItemOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutWebLookAndFeel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutWebLookAndFeel : public TdxCustomLayoutLookAndFeel
{
	typedef TdxCustomLayoutLookAndFeel inherited;
	
private:
	TdxLayoutWebLookAndFeelGroupOptions* __fastcall GetGroupOptions(void);
	HIDESBASE void __fastcall SetGroupOptions(TdxLayoutWebLookAndFeelGroupOptions* Value);
	
protected:
	virtual TdxLayoutLookAndFeelGroupOptionsClass __fastcall GetGroupOptionsClass(void);
	virtual TdxLayoutLookAndFeelItemOptionsClass __fastcall GetItemOptionsClass(void);
	virtual void __fastcall InitLookAndFeel(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Description();
	virtual System::TClass __fastcall GetGroupPainterClass(void);
	virtual System::TClass __fastcall GetGroupViewInfoClass(void);
	virtual int __fastcall GetGroupBorderOffset(System::Classes::TComponent* AContainer, Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide);
	virtual int __fastcall GetGroupBorderWidth(System::Classes::TComponent* AContainer, Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide, bool AHasCaption, bool AIsExpanded);
	
__published:
	__property TdxLayoutWebLookAndFeelGroupOptions* GroupOptions = {read=GetGroupOptions, write=SetGroupOptions};
public:
	/* TdxCustomLayoutLookAndFeel.Create */ inline __fastcall virtual TdxLayoutWebLookAndFeel(System::Classes::TComponent* AOwner) : TdxCustomLayoutLookAndFeel(AOwner) { }
	/* TdxCustomLayoutLookAndFeel.Destroy */ inline __fastcall virtual ~TdxLayoutWebLookAndFeel(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutCxLookAndFeelGroupOptions;
class DELPHICLASS TdxLayoutCxLookAndFeel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutCxLookAndFeelGroupOptions : public TdxLayoutStandardLookAndFeelGroupOptions
{
	typedef TdxLayoutStandardLookAndFeelGroupOptions inherited;
	
private:
	TdxLayoutCxLookAndFeel* __fastcall GetLookAndFeel(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultColor(void);
	virtual TdxLayoutLookAndFeelCaptionOptionsClass __fastcall GetCaptionOptionsClass(void);
	__property TdxLayoutCxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
public:
	/* TdxLayoutLookAndFeelGroupOptions.Create */ inline __fastcall virtual TdxLayoutCxLookAndFeelGroupOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel) : TdxLayoutStandardLookAndFeelGroupOptions(ALookAndFeel) { }
	
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TdxLayoutCxLookAndFeelGroupOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutCxLookAndFeelGroupCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutCxLookAndFeelGroupCaptionOptions : public TdxLayoutStandardLookAndFeelGroupCaptionOptions
{
	typedef TdxLayoutStandardLookAndFeelGroupCaptionOptions inherited;
	
private:
	TdxLayoutCxLookAndFeel* __fastcall GetLookAndFeel(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextDisabledColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextHotColor(void);
	__property TdxLayoutCxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
public:
	/* TdxLayoutLookAndFeelCaptionOptions.Create */ inline __fastcall virtual TdxLayoutCxLookAndFeelGroupCaptionOptions(TdxCustomLayoutLookAndFeelOptions* AOptions) : TdxLayoutStandardLookAndFeelGroupCaptionOptions(AOptions) { }
	/* TdxLayoutLookAndFeelCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutCxLookAndFeelGroupCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutCxLookAndFeelItemOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutCxLookAndFeelItemOptions : public TdxLayoutLookAndFeelItemOptions
{
	typedef TdxLayoutLookAndFeelItemOptions inherited;
	
protected:
	virtual TdxLayoutLookAndFeelCaptionOptionsClass __fastcall GetCaptionOptionsClass(void);
public:
	/* TdxLayoutLookAndFeelItemOptions.Create */ inline __fastcall virtual TdxLayoutCxLookAndFeelItemOptions(TdxCustomLayoutLookAndFeel* ALookAndFeel) : TdxLayoutLookAndFeelItemOptions(ALookAndFeel) { }
	
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TdxLayoutCxLookAndFeelItemOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutCxLookAndFeelItemCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutCxLookAndFeelItemCaptionOptions : public TdxLayoutLookAndFeelCaptionOptions
{
	typedef TdxLayoutLookAndFeelCaptionOptions inherited;
	
private:
	TdxLayoutCxLookAndFeel* __fastcall GetLookAndFeel(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetDefaultTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextDisabledColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultTextHotColor(void);
	__property TdxLayoutCxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
public:
	/* TdxLayoutLookAndFeelCaptionOptions.Create */ inline __fastcall virtual TdxLayoutCxLookAndFeelItemCaptionOptions(TdxCustomLayoutLookAndFeelOptions* AOptions) : TdxLayoutLookAndFeelCaptionOptions(AOptions) { }
	/* TdxLayoutLookAndFeelCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutCxLookAndFeelItemCaptionOptions(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutCxLookAndFeel : public TdxLayoutStandardLookAndFeel
{
	typedef TdxLayoutStandardLookAndFeel inherited;
	
private:
	int __fastcall InternalGetGroupBorderOffset(System::Classes::TComponent* AContainer, Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual bool __fastcall DoesCxLookAndFeelHavePriority(void);
	virtual bool __fastcall IsGroupTransparent(void);
	virtual bool __fastcall IsSkinPainterUsed(void);
	virtual int __fastcall GetFrameWidth(Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide);
	virtual TdxLayoutLookAndFeelGroupOptionsClass __fastcall GetGroupOptionsClass(void);
	virtual TdxLayoutLookAndFeelItemOptionsClass __fastcall GetItemOptionsClass(void);
	virtual void __fastcall InitLookAndFeel(void);
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	
public:
	__fastcall virtual TdxLayoutCxLookAndFeel(System::Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall Description();
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual int __fastcall GetGroupBorderWidth(System::Classes::TComponent* AContainer, Dxlayoutcommon::TdxLayoutSide ASide, Dxlayoutcommon::TdxLayoutSide ACaptionSide, bool AHasCaption, bool AIsExpanded);
	virtual int __fastcall GetItemControlBorderWidth(Dxlayoutcommon::TdxLayoutSide ASide);
	virtual void __fastcall DrawLayoutControlBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawItemControlBorder(Cxgraphics::TcxCanvas* ACanvas, TdxLayoutLookAndFeelItemOptions* AItemOptions, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetEmptyAreaColor(void);
	virtual System::TClass __fastcall GetGroupPainterClass(void);
	virtual System::TClass __fastcall GetGroupViewInfoClass(void);
	virtual System::TClass __fastcall GetItemViewInfoClass(void);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
__published:
	__property LookAndFeel;
public:
	/* TdxCustomLayoutLookAndFeel.Destroy */ inline __fastcall virtual ~TdxLayoutCxLookAndFeel(void) { }
	
private:
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
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

#pragma pack(pop)

class DELPHICLASS TdxLayoutSkinLookAndFeel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutSkinLookAndFeel : public TdxLayoutCxLookAndFeel
{
	typedef TdxLayoutCxLookAndFeel inherited;
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall ReadSkinName(System::Classes::TReader* Reader);
	void __fastcall ReadSkinNameAssigned(System::Classes::TReader* Reader);
	
public:
	__classmethod virtual System::UnicodeString __fastcall Description();
	virtual System::TClass __fastcall GetGroupViewInfoClass(void);
public:
	/* TdxLayoutCxLookAndFeel.Create */ inline __fastcall virtual TdxLayoutSkinLookAndFeel(System::Classes::TComponent* AOwner) : TdxLayoutCxLookAndFeel(AOwner) { }
	
public:
	/* TdxCustomLayoutLookAndFeel.Destroy */ inline __fastcall virtual ~TdxLayoutSkinLookAndFeel(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLookAndFeelList : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
public:
	TdxCustomLayoutLookAndFeel* operator[](int Index) { return Items[Index]; }
	
private:
	Cxclasses::TcxComponentList* FItems;
	int __fastcall GetCount(void);
	bool __fastcall GetIsDesigning(void);
	TdxCustomLayoutLookAndFeel* __fastcall GetItem(int Index);
	void __fastcall AddItem(TdxCustomLayoutLookAndFeel* AItem);
	void __fastcall RemoveItem(TdxCustomLayoutLookAndFeel* AItem);
	void __fastcall ItemListChanged(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	
protected:
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall Modified(void);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	
public:
	__fastcall virtual TdxLayoutLookAndFeelList(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxLayoutLookAndFeelList(void);
	TdxCustomLayoutLookAndFeel* __fastcall CreateItem(TdxCustomLayoutLookAndFeelClass AClass);
	__property int Count = {read=GetCount, nodefault};
	__property TdxCustomLayoutLookAndFeel* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutLookAndFeelDefs;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLookAndFeelDefs : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxCustomLayoutLookAndFeelClass operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TdxCustomLayoutLookAndFeelClass __fastcall GetItem(int Index);
	
public:
	__fastcall TdxLayoutLookAndFeelDefs(void);
	__fastcall virtual ~TdxLayoutLookAndFeelDefs(void);
	TdxCustomLayoutLookAndFeelClass __fastcall GetItemByDescription(const System::UnicodeString Value);
	void __fastcall Register(TdxCustomLayoutLookAndFeelClass AClass);
	void __fastcall Unregister(TdxCustomLayoutLookAndFeelClass AClass);
	__property int Count = {read=GetCount, nodefault};
	__property TdxCustomLayoutLookAndFeelClass Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

struct TdxLayoutTextMetric;
typedef TdxLayoutTextMetric *PdxLayoutTextMetric;

struct DECLSPEC_DRECORD TdxLayoutTextMetric
{
public:
	Vcl::Graphics::TFont* Font;
	tagTEXTMETRICW TextMetric;
};


class DELPHICLASS TdxLayoutTextMetrics;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutTextMetrics : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	PdxLayoutTextMetric __fastcall GetItem(int AIndex);
	void __fastcall DestroyItems(void);
	
protected:
	void __fastcall CalculateItem(int AIndex);
	void __fastcall Delete(int AIndex);
	int __fastcall IndexOf(Vcl::Graphics::TFont* AFont);
	__property int Count = {read=GetCount, nodefault};
	__property PdxLayoutTextMetric Items[int AIndex] = {read=GetItem};
	
public:
	__fastcall TdxLayoutTextMetrics(void);
	__fastcall virtual ~TdxLayoutTextMetrics(void);
	void __fastcall Get(Vcl::Graphics::TFont* AFont, tagTEXTMETRICW &ATextMetric);
	void __fastcall Unregister(Vcl::Graphics::TFont* AFont);
};

#pragma pack(pop)

__interface IdxLayoutLookAndFeelsDesigner;
typedef System::DelphiInterface<IdxLayoutLookAndFeelsDesigner> _di_IdxLayoutLookAndFeelsDesigner;
__interface  INTERFACE_UUID("{EA24F329-D483-4D4F-A72C-1F67EC4F7E21}") IdxLayoutLookAndFeelsDesigner  : public System::IInterface 
{
	
public:
	virtual void __fastcall ComponentNameChanged(TdxLayoutLookAndFeelList* ALookAndFeelList) = 0 ;
	virtual void __fastcall ItemsChanged(TdxLayoutLookAndFeelList* ALookAndFeelList) = 0 ;
	virtual void __fastcall Edit(TdxLayoutLookAndFeelList* ALookAndFeelList) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxLayoutTextMetrics* dxLayoutTextMetrics;
extern PACKAGE TdxLayoutLookAndFeelDefs* dxLayoutLookAndFeelDefs;
extern PACKAGE TdxCustomLayoutLookAndFeel* dxLayoutDefaultLookAndFeel;
extern PACKAGE _di_IdxLayoutLookAndFeelsDesigner dxLayoutLookAndFeelsDesigner;
}	/* namespace Dxlayoutlookandfeels */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTLOOKANDFEELS)
using namespace Dxlayoutlookandfeels;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutlookandfeelsHPP
