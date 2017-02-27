// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarStyles.pas' rev: 24.00 (Win32)

#ifndef DxnavbarstylesHPP
#define DxnavbarstylesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarstyles
{
//-- type declarations -------------------------------------------------------
enum TdxBarStyleHAlignment : unsigned char { haLeft, haCenter, haRight };

enum TdxBarStyleVAlignment : unsigned char { vaTop, vaCenter, vaBottom };

enum TdxBarStyleAssignedValue : unsigned char { savAlphaBlending, savAlphaBlending2, savBackColor, savBackColor2, savFont, savGradientMode, savHAlignment, savVAlignment, savImage };

typedef System::Set<TdxBarStyleAssignedValue, TdxBarStyleAssignedValue::savAlphaBlending, TdxBarStyleAssignedValue::savImage>  TdxBarStyleAssignedValues;

enum TdxBarStyleGradientMode : unsigned char { gmHorizontal, gmVertical, gmForwardDiagonal, gmBackwardDiagonal };

class DELPHICLASS TdxNavBarBaseStyle;
class PASCALIMPLEMENTATION TdxNavBarBaseStyle : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Byte FAlphaBlending;
	System::Byte FAlphaBlending2;
	TdxBarStyleAssignedValues FAssignedValues;
	System::Uitypes::TColor FBackColor;
	System::Uitypes::TColor FBackColor2;
	TdxBarStyleGradientMode FGradientMode;
	Vcl::Graphics::TFont* FFont;
	Vcl::Graphics::TPicture* FImage;
	TdxBarStyleHAlignment FHAlignment;
	TdxBarStyleVAlignment FVAlignment;
	Dxnavbarbase::TdxNavBarChangeEvent FOnChange;
	bool __fastcall IsAlphaBlendingStored(void);
	bool __fastcall IsAlphaBlending2Stored(void);
	bool __fastcall IsGradientModeStored(void);
	bool __fastcall IsHAlignmentStored(void);
	bool __fastcall IsVAlignmentStored(void);
	void __fastcall SetAlphaBlending(const System::Byte Value);
	void __fastcall SetAlphaBlending2(const System::Byte Value);
	void __fastcall SetAssignedValues(const TdxBarStyleAssignedValues Value);
	void __fastcall SetBackColor(const System::Uitypes::TColor Value);
	void __fastcall SetBackColor2(const System::Uitypes::TColor Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* const Value);
	void __fastcall SetGradientMode(const TdxBarStyleGradientMode Value);
	void __fastcall SetHAlignment(const TdxBarStyleHAlignment Value);
	void __fastcall SetImage(Vcl::Graphics::TPicture* const Value);
	void __fastcall SetVAlignment(const TdxBarStyleVAlignment Value);
	
protected:
	virtual bool __fastcall CanAssignValue(void);
	virtual void __fastcall Changed(Dxnavbarbase::TdxNavBarChangeType AType);
	void __fastcall FontChanged(System::TObject* Sender);
	void __fastcall ImageChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TdxNavBarBaseStyle(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxNavBarBaseStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ResetValues(void);
	__property TdxBarStyleAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property Dxnavbarbase::TdxNavBarChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property System::Byte AlphaBlending = {read=FAlphaBlending, write=SetAlphaBlending, stored=IsAlphaBlendingStored, nodefault};
	__property System::Byte AlphaBlending2 = {read=FAlphaBlending2, write=SetAlphaBlending2, stored=IsAlphaBlending2Stored, nodefault};
	__property System::Uitypes::TColor BackColor = {read=FBackColor, write=SetBackColor, nodefault};
	__property System::Uitypes::TColor BackColor2 = {read=FBackColor2, write=SetBackColor2, nodefault};
	__property TdxBarStyleGradientMode GradientMode = {read=FGradientMode, write=SetGradientMode, stored=IsGradientModeStored, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property Vcl::Graphics::TPicture* Image = {read=FImage, write=SetImage};
	__property TdxBarStyleHAlignment HAlignment = {read=FHAlignment, write=SetHAlignment, stored=IsHAlignmentStored, nodefault};
	__property TdxBarStyleVAlignment VAlignment = {read=FVAlignment, write=SetVAlignment, stored=IsVAlignmentStored, nodefault};
};


typedef void __fastcall (__closure *TdxNavBarDefaultStyleAssignProc)(void);

class DELPHICLASS TdxNavBarDefaultStyle;
class DELPHICLASS TdxNavBarDefaultStyles;
class PASCALIMPLEMENTATION TdxNavBarDefaultStyle : public TdxNavBarBaseStyle
{
	typedef TdxNavBarBaseStyle inherited;
	
private:
	bool FDefaultValues;
	TdxNavBarDefaultStyleAssignProc FDefaultValuesProc;
	TdxNavBarDefaultStyles* __fastcall GetCollection(void);
	
protected:
	virtual void __fastcall Changed(Dxnavbarbase::TdxNavBarChangeType AType);
	void __fastcall AssignDefaultValues(bool CheckDefault);
	__property TdxNavBarDefaultStyleAssignProc DefaultValuesProc = {read=FDefaultValuesProc, write=FDefaultValuesProc};
	
public:
	__fastcall virtual TdxNavBarDefaultStyle(System::Classes::TPersistent* AOwner);
	__property TdxNavBarDefaultStyles* Collection = {read=GetCollection};
	__property bool DefaultValues = {read=FDefaultValues, write=FDefaultValues, nodefault};
	
__published:
	__property AssignedValues = {default=0};
public:
	/* TdxNavBarBaseStyle.Destroy */ inline __fastcall virtual ~TdxNavBarDefaultStyle(void) { }
	
};


class PASCALIMPLEMENTATION TdxNavBarDefaultStyles : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Classes::TList* FDefaultStylesList;
	int FUpdateCount;
	Dxnavbarbase::TdxNavBarChangeEvent FOnChange;
	bool __fastcall IsDefaultStyleStored(int Index);
	int __fastcall GetDefaultStyleCount(void);
	TdxNavBarDefaultStyle* __fastcall GetDefaultStyle(int Index);
	void __fastcall SetDefaultStyle(int Index, TdxNavBarDefaultStyle* const Value);
	void __fastcall AssignDefaultBackgroundStyle(void);
	void __fastcall AssignDefaultButtonStyle(void);
	void __fastcall AssignDefaultButtonPressedStyle(void);
	void __fastcall AssignDefaultButtonHotTrackedStyle(void);
	void __fastcall AssignDefaultGroupBackgroundStyle(void);
	void __fastcall AssignDefaultGroupControlStyle(void);
	void __fastcall AssignDefaultGroupHeaderStyle(void);
	void __fastcall AssignDefaultGroupHeaderActiveStyle(void);
	void __fastcall AssignDefaultGroupHeaderActiveHotTrackedStyle(void);
	void __fastcall AssignDefaultGroupHeaderActivePressedStyle(void);
	void __fastcall AssignDefaultGroupHeaderHotTrackedStyle(void);
	void __fastcall AssignDefaultGroupHeaderPressedStyle(void);
	void __fastcall AssignDefaultHintStyle(void);
	void __fastcall AssignDefaultItemStyle(void);
	void __fastcall AssignDefaultItemDisabledStyle(void);
	void __fastcall AssignDefaultItemHotTrackedStyle(void);
	void __fastcall AssignDefaultItemPressedStyle(void);
	void __fastcall AssignDefaultDropTargetGroupStyle(void);
	void __fastcall AssignDefaultDropTargetLinkStyle(void);
	void __fastcall AssignDefaultNavigationPaneHeaderStyle(void);
	
protected:
	virtual void __fastcall CreateDefaultStyleList(void);
	virtual void __fastcall DestroyDefaultStyleList(void);
	void __fastcall OnStyleChange(System::TObject* Sender, Dxnavbarbase::TdxNavBarChangeType AType);
	
public:
	__fastcall virtual TdxNavBarDefaultStyles(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxNavBarDefaultStyles(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AssignDefaultValues(bool CheckDefault);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	__property int DefaultStyleCount = {read=GetDefaultStyleCount, nodefault};
	__property TdxNavBarDefaultStyle* DefaultStyles[int Index] = {read=GetDefaultStyle};
	__property Dxnavbarbase::TdxNavBarChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property TdxNavBarDefaultStyle* Background = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=0};
	__property TdxNavBarDefaultStyle* Button = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=1};
	__property TdxNavBarDefaultStyle* ButtonPressed = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=2};
	__property TdxNavBarDefaultStyle* ButtonHotTracked = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=3};
	__property TdxNavBarDefaultStyle* GroupBackground = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=4};
	__property TdxNavBarDefaultStyle* GroupControl = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=5};
	__property TdxNavBarDefaultStyle* GroupHeader = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=6};
	__property TdxNavBarDefaultStyle* GroupHeaderActive = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=7};
	__property TdxNavBarDefaultStyle* GroupHeaderActiveHotTracked = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=8};
	__property TdxNavBarDefaultStyle* GroupHeaderActivePressed = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=9};
	__property TdxNavBarDefaultStyle* GroupHeaderHotTracked = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=10};
	__property TdxNavBarDefaultStyle* GroupHeaderPressed = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=11};
	__property TdxNavBarDefaultStyle* Hint = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=12};
	__property TdxNavBarDefaultStyle* Item = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=13};
	__property TdxNavBarDefaultStyle* ItemDisabled = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=14};
	__property TdxNavBarDefaultStyle* ItemHotTracked = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=15};
	__property TdxNavBarDefaultStyle* ItemPressed = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=16};
	__property TdxNavBarDefaultStyle* DropTargetGroup = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=17};
	__property TdxNavBarDefaultStyle* DropTargetLink = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=18};
	__property TdxNavBarDefaultStyle* NavigationPaneHeader = {read=GetDefaultStyle, write=SetDefaultStyle, stored=IsDefaultStyleStored, index=19};
};


class DELPHICLASS TdxNavBarStyle;
class PASCALIMPLEMENTATION TdxNavBarStyle : public TdxNavBarBaseStyle
{
	typedef TdxNavBarBaseStyle inherited;
	
__published:
	__property AssignedValues = {default=0};
public:
	/* TdxNavBarBaseStyle.Create */ inline __fastcall virtual TdxNavBarStyle(System::Classes::TPersistent* AOwner) : TdxNavBarBaseStyle(AOwner) { }
	/* TdxNavBarBaseStyle.Destroy */ inline __fastcall virtual ~TdxNavBarStyle(void) { }
	
};


class DELPHICLASS TdxNavBarStyleItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarStyleItem : public Dxnavbarbase::TdxNavBarComponentCollectionItem
{
	typedef Dxnavbarbase::TdxNavBarComponentCollectionItem inherited;
	
private:
	Cxclasses::TcxEventHandlerCollection* FChangeStyleHandlers;
	TdxNavBarStyle* FStyle;
	void __fastcall SetStyle(TdxNavBarStyle* const Value);
	
protected:
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	void __fastcall OnStyleChange(System::TObject* Sender, Dxnavbarbase::TdxNavBarChangeType AType);
	void __fastcall RegisterChanges(Cxclasses::TcxEventHandler AValue);
	void __fastcall UnRegisterChanges(Cxclasses::TcxEventHandler AValue);
	
public:
	__fastcall virtual TdxNavBarStyleItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxNavBarStyleItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxNavBarStyle* Style = {read=FStyle, write=SetStyle};
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarStyleRepository;
class PASCALIMPLEMENTATION TdxNavBarStyleRepository : public Dxnavbarbase::TdxNavBarComponentCollection
{
	typedef Dxnavbarbase::TdxNavBarComponentCollection inherited;
	
public:
	TdxNavBarStyleItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TdxNavBarStyleItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxNavBarStyleItem* Value);
	virtual void __fastcall SetItemName(Cxclasses::TcxComponentCollectionItem* AItem);
	
public:
	HIDESBASE TdxNavBarStyleItem* __fastcall Add(void);
	__property TdxNavBarStyleItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxNavBarStyleRepository(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Dxnavbarbase::TdxNavBarComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxNavBarStyleRepository(void) { }
	
};


class DELPHICLASS TdxNavBarBaseCustomStyles;
class PASCALIMPLEMENTATION TdxNavBarBaseCustomStyles : public Dxnavbarbase::TdxNavBarNexusPersistent
{
	typedef Dxnavbarbase::TdxNavBarNexusPersistent inherited;
	
private:
	typedef System::DynamicArray<TdxNavBarStyleItem*> _TdxNavBarBaseCustomStyles__1;
	
	
private:
	_TdxNavBarBaseCustomStyles__1 FStyles;
	Dxnavbarbase::TdxNavBarChangeEvent FOnChange;
	void __fastcall InternalStyleChange(System::TObject* Sender, const void *AEventArgs);
	
protected:
	virtual void __fastcall AddNotificator(int AIndex);
	void __fastcall DoChange(void);
	TdxNavBarStyleItem* __fastcall GetStyle(int Index);
	void __fastcall SetStyle(int Index, TdxNavBarStyleItem* const Value);
	virtual int __fastcall GetStyleCount(void) = 0 ;
	virtual void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	virtual void __fastcall RemoveNotificator(int AIndex);
	
public:
	__fastcall virtual TdxNavBarBaseCustomStyles(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxNavBarBaseCustomStyles(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxNavBarStyleItem* Styles[int Index] = {read=GetStyle, write=SetStyle};
	__property Dxnavbarbase::TdxNavBarChangeEvent OnChange = {read=FOnChange, write=FOnChange};
};


class DELPHICLASS TdxNavBarCustomStyles;
class PASCALIMPLEMENTATION TdxNavBarCustomStyles : public TdxNavBarBaseCustomStyles
{
	typedef TdxNavBarBaseCustomStyles inherited;
	
protected:
	virtual int __fastcall GetStyleCount(void);
	
__published:
	__property TdxNavBarStyleItem* Background = {read=GetStyle, write=SetStyle, index=0};
	__property TdxNavBarStyleItem* Hint = {read=GetStyle, write=SetStyle, index=1};
	__property TdxNavBarStyleItem* DropTargetGroup = {read=GetStyle, write=SetStyle, index=2};
	__property TdxNavBarStyleItem* DropTargetLink = {read=GetStyle, write=SetStyle, index=3};
	__property TdxNavBarStyleItem* Button = {read=GetStyle, write=SetStyle, index=4};
	__property TdxNavBarStyleItem* ButtonHotTracked = {read=GetStyle, write=SetStyle, index=5};
	__property TdxNavBarStyleItem* ButtonPressed = {read=GetStyle, write=SetStyle, index=6};
	__property TdxNavBarStyleItem* NavigationPaneHeader = {read=GetStyle, write=SetStyle, index=7};
public:
	/* TdxNavBarBaseCustomStyles.Create */ inline __fastcall virtual TdxNavBarCustomStyles(System::Classes::TPersistent* AOwner) : TdxNavBarBaseCustomStyles(AOwner) { }
	/* TdxNavBarBaseCustomStyles.Destroy */ inline __fastcall virtual ~TdxNavBarCustomStyles(void) { }
	
};


class DELPHICLASS TdxNavBarGroupCustomStyles;
class PASCALIMPLEMENTATION TdxNavBarGroupCustomStyles : public TdxNavBarBaseCustomStyles
{
	typedef TdxNavBarBaseCustomStyles inherited;
	
protected:
	virtual int __fastcall GetStyleCount(void);
	
__published:
	__property TdxNavBarStyleItem* Background = {read=GetStyle, write=SetStyle, index=0};
	__property TdxNavBarStyleItem* Control = {read=GetStyle, write=SetStyle, index=1};
	__property TdxNavBarStyleItem* Header = {read=GetStyle, write=SetStyle, index=2};
	__property TdxNavBarStyleItem* HeaderActive = {read=GetStyle, write=SetStyle, index=3};
	__property TdxNavBarStyleItem* HeaderActiveHotTracked = {read=GetStyle, write=SetStyle, index=4};
	__property TdxNavBarStyleItem* HeaderActivePressed = {read=GetStyle, write=SetStyle, index=5};
	__property TdxNavBarStyleItem* HeaderHotTracked = {read=GetStyle, write=SetStyle, index=6};
	__property TdxNavBarStyleItem* HeaderPressed = {read=GetStyle, write=SetStyle, index=7};
public:
	/* TdxNavBarBaseCustomStyles.Create */ inline __fastcall virtual TdxNavBarGroupCustomStyles(System::Classes::TPersistent* AOwner) : TdxNavBarBaseCustomStyles(AOwner) { }
	/* TdxNavBarBaseCustomStyles.Destroy */ inline __fastcall virtual ~TdxNavBarGroupCustomStyles(void) { }
	
};


class DELPHICLASS TdxNavBarItemCustomStyles;
class PASCALIMPLEMENTATION TdxNavBarItemCustomStyles : public TdxNavBarBaseCustomStyles
{
	typedef TdxNavBarBaseCustomStyles inherited;
	
protected:
	virtual int __fastcall GetStyleCount(void);
	
__published:
	__property TdxNavBarStyleItem* Item = {read=GetStyle, write=SetStyle, index=0};
	__property TdxNavBarStyleItem* ItemDisabled = {read=GetStyle, write=SetStyle, index=1};
	__property TdxNavBarStyleItem* ItemHotTracked = {read=GetStyle, write=SetStyle, index=2};
	__property TdxNavBarStyleItem* ItemPressed = {read=GetStyle, write=SetStyle, index=3};
public:
	/* TdxNavBarBaseCustomStyles.Create */ inline __fastcall virtual TdxNavBarItemCustomStyles(System::Classes::TPersistent* AOwner) : TdxNavBarBaseCustomStyles(AOwner) { }
	/* TdxNavBarBaseCustomStyles.Destroy */ inline __fastcall virtual ~TdxNavBarItemCustomStyles(void) { }
	
};


class DELPHICLASS TdxNavBarStyleOptions;
class PASCALIMPLEMENTATION TdxNavBarStyleOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TdxNavBarDefaultStyles* FDefaultStyles;
	TdxNavBarCustomStyles* FCustomStyles;
	TdxNavBarStyleRepository* FCustomStyleRepository;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall CustomStylesChanged(System::TObject* Sender, Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall StyleChanged(System::TObject* Sender, Dxnavbarbase::TdxNavBarChangeType AType);
	void __fastcall SetCustomStyleRepository(TdxNavBarStyleRepository* Value);
	void __fastcall SetDefaultStyles(TdxNavBarDefaultStyles* Value);
	void __fastcall SetCustomStyles(TdxNavBarCustomStyles* Value);
	
public:
	__fastcall virtual TdxNavBarStyleOptions(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxNavBarStyleOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxNavBarDefaultStyles* DefaultStyles = {read=FDefaultStyles, write=SetDefaultStyles};
	__property TdxNavBarCustomStyles* CustomStyles = {read=FCustomStyles, write=SetCustomStyles};
	__property TdxNavBarStyleRepository* CustomStyleRepository = {read=FCustomStyleRepository, write=SetCustomStyleRepository};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbarstyles */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARSTYLES)
using namespace Dxnavbarstyles;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarstylesHPP
