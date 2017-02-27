// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinChooserGallery.pas' rev: 24.00 (Win64)

#ifndef DxskinchoosergalleryHPP
#define DxskinchoosergalleryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxRibbonGallery.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinchoosergallery
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinChooserGalleryOptions;
class PASCALIMPLEMENTATION TdxSkinChooserGalleryOptions : public Dxribbongallery::TdxCustomRibbonGalleryOptions
{
	typedef Dxribbongallery::TdxCustomRibbonGalleryOptions inherited;
	
protected:
	virtual bool __fastcall IsItemImagePositionStored(void);
	
public:
	__fastcall virtual TdxSkinChooserGalleryOptions(Dxribbongallery::TdxCustomRibbonGalleryItem* AOwner)/* overload */;
	
__published:
	__property ColumnCount = {default=5};
	__property ItemAllowDeselect = {default=0};
	__property ItemImagePosition;
	__property ItemImageSize;
	__property ShowItemHint = {default=1};
	__property SpaceAfterGroupHeader;
	__property SpaceBetweenGroups = {default=0};
	__property SpaceBetweenItemCaptionAndDescription;
	__property SpaceBetweenItemImageAndText;
	__property SpaceBetweenItemsAndBorder = {default=1};
	__property SpaceBetweenItemsHorizontally;
	__property SpaceBetweenItemsVertically;
public:
	/* TdxRibbonGalleryBaseOptions.Destroy */ inline __fastcall virtual ~TdxSkinChooserGalleryOptions(void) { }
	
};


class DELPHICLASS TdxSkinChooserGalleryGroupItem;
class PASCALIMPLEMENTATION TdxSkinChooserGalleryGroupItem : public Dxribbongallery::TdxRibbonGalleryGroupItem
{
	typedef Dxribbongallery::TdxRibbonGalleryGroupItem inherited;
	
private:
	Cxlookandfeelpainters::TcxLookAndFeelStyle FLookAndFeelStyle;
	System::UnicodeString FSkinName;
	NativeUInt FSkinResInstance;
	System::UnicodeString FSkinResName;
	
public:
	__fastcall virtual TdxSkinChooserGalleryGroupItem(System::Classes::TComponent* AOwner);
	void __fastcall ApplyToLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	void __fastcall ApplyToRootLookAndFeel(void);
	__property GlyphInDropDown;
	__property Cxlookandfeelpainters::TcxLookAndFeelStyle LookAndFeelStyle = {read=FLookAndFeelStyle, write=FLookAndFeelStyle, nodefault};
	__property System::UnicodeString SkinName = {read=FSkinName, write=FSkinName};
	__property NativeUInt SkinResInstance = {read=FSkinResInstance, write=FSkinResInstance};
	__property System::UnicodeString SkinResName = {read=FSkinResName, write=FSkinResName};
public:
	/* TdxRibbonGalleryGroupItem.Destroy */ inline __fastcall virtual ~TdxSkinChooserGalleryGroupItem(void) { }
	
};


typedef void __fastcall (__closure *TdxSkinChooserGallerySkinChangedEvent)(System::TObject* Sender, const System::UnicodeString ASkinName);

class DELPHICLASS TdxSkinChooserGalleryItem;
class PASCALIMPLEMENTATION TdxSkinChooserGalleryItem : public Dxribbongallery::TdxCustomRibbonGalleryItem
{
	typedef Dxribbongallery::TdxCustomRibbonGalleryItem inherited;
	
private:
	Dxskinscore::TdxSkinIconSize FSkinIconSize;
	Dxskinscore::TdxSkinIconSize FSkinIconSizeInDropDown;
	Cxlookandfeelpainters::TcxLookAndFeelStyles FVisibleLookAndFeelStyles;
	System::Classes::TNotifyEvent FOnPopulate;
	TdxSkinChooserGallerySkinChangedEvent FOnSkinChanged;
	TdxSkinChooserGalleryOptions* __fastcall GetGalleryOptions(void);
	int __fastcall GetGroupIndex(const System::UnicodeString AName);
	bool __fastcall GetIsInternalSkin(Dxskinscore::TdxSkinDetails* ASkinDetails);
	TdxSkinChooserGalleryGroupItem* __fastcall GetSelectedGroupItem(void);
	System::UnicodeString __fastcall GetSelectedSkinName(void);
	bool __fastcall IsSkinIconSizeInDropDownStored(void);
	bool __fastcall IsSkinIconSizeStored(void);
	HIDESBASE void __fastcall SetGalleryOptions(TdxSkinChooserGalleryOptions* AValue);
	HIDESBASE void __fastcall SetSelectedGroupItem(TdxSkinChooserGalleryGroupItem* AValue);
	void __fastcall SetSelectedSkinName(const System::UnicodeString AValue);
	void __fastcall SetSkinIconSize(Dxskinscore::TdxSkinIconSize AValue);
	void __fastcall SetSkinIconSizeInDropDown(Dxskinscore::TdxSkinIconSize AValue);
	void __fastcall SetVisibleLookAndFeelStyles(Cxlookandfeelpainters::TcxLookAndFeelStyles AValue);
	
protected:
	virtual void __fastcall DoGroupItemClick(Dxribbongallery::TdxRibbonGalleryGroupItem* AItem);
	virtual void __fastcall DoSkinChanged(const System::UnicodeString ASkinName);
	virtual System::UnicodeString __fastcall GetErrorCanPlaceText(void);
	virtual Dxribbongallery::TdxRibbonGalleryGroupItemClass __fastcall GetGroupItemClass(void);
	virtual Dxribbongallery::TCustomdxRibbonGalleryOptionsClass __fastcall GetGalleryOptionsClass(void);
	__classmethod virtual System::UnicodeString __fastcall GetNewCaption();
	virtual void __fastcall Loaded(void);
	void __fastcall PainterChanged(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter);
	
public:
	__fastcall virtual TdxSkinChooserGalleryItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxSkinChooserGalleryItem(void);
	TdxSkinChooserGalleryGroupItem* __fastcall AddSkin(Dxskinscore::TdxSkinDetails* ASkinDetails)/* overload */;
	TdxSkinChooserGalleryGroupItem* __fastcall AddSkin(const System::UnicodeString ASkinName, const System::UnicodeString AGroupName)/* overload */;
	void __fastcall AddSkinsFromFile(const System::UnicodeString AFileName);
	void __fastcall AddSkinsFromResource(NativeUInt AInstance, const System::UnicodeString AResourceName);
	void __fastcall AddSkinsFromResources(NativeUInt AInstance);
	void __fastcall AddSkinsFromStream(System::Classes::TStream* AStream, const System::UnicodeString ASkinResName, NativeUInt ASkinResInstance);
	bool __fastcall FindSkin(const System::UnicodeString ASkinName, /* out */ TdxSkinChooserGalleryGroupItem* &AItem);
	void __fastcall PopulateGallery(void);
	__property TdxSkinChooserGalleryGroupItem* SelectedGroupItem = {read=GetSelectedGroupItem, write=SetSelectedGroupItem};
	__property System::UnicodeString SelectedSkinName = {read=GetSelectedSkinName, write=SetSelectedSkinName};
	
__published:
	__property Glyph;
	__property ImageIndex = {default=-1};
	__property LargeGlyph;
	__property LargeImageIndex = {default=-1};
	__property ShowCaption = {default=1};
	__property OnClick;
	__property TdxSkinChooserGalleryOptions* GalleryOptions = {read=GetGalleryOptions, write=SetGalleryOptions};
	__property GalleryInRibbonOptions;
	__property GalleryInMenuOptions;
	__property ItemLinks;
	__property ItemOptions;
	__property Dxskinscore::TdxSkinIconSize SkinIconSize = {read=FSkinIconSize, write=SetSkinIconSize, stored=IsSkinIconSizeStored, nodefault};
	__property Dxskinscore::TdxSkinIconSize SkinIconSizeInDropDown = {read=FSkinIconSizeInDropDown, write=SetSkinIconSizeInDropDown, stored=IsSkinIconSizeInDropDownStored, nodefault};
	__property Cxlookandfeelpainters::TcxLookAndFeelStyles VisibleLookAndFeelStyles = {read=FVisibleLookAndFeelStyles, write=SetVisibleLookAndFeelStyles, default=32};
	__property OnCloseUp;
	__property OnHotTrackedItemChanged;
	__property System::Classes::TNotifyEvent OnPopulate = {read=FOnPopulate, write=FOnPopulate};
	__property OnPopup;
	__property TdxSkinChooserGallerySkinChangedEvent OnSkinChanged = {read=FOnSkinChanged, write=FOnSkinChanged};
private:
	void *__IcxLookAndFeelPainterListener;	/* Cxlookandfeelpainters::IcxLookAndFeelPainterListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {766FE270-2C4B-48B9-C9C7-882A62128A0C}
	operator Cxlookandfeelpainters::_di_IcxLookAndFeelPainterListener()
	{
		Cxlookandfeelpainters::_di_IcxLookAndFeelPainterListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeelpainters::IcxLookAndFeelPainterListener*(void) { return (Cxlookandfeelpainters::IcxLookAndFeelPainterListener*)&__IcxLookAndFeelPainterListener; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinchoosergallery */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINCHOOSERGALLERY)
using namespace Dxskinchoosergallery;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinchoosergalleryHPP
