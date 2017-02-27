// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxGalleryControl.pas' rev: 24.00 (Win32)

#ifndef DxgallerycontrolHPP
#define DxgallerycontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxGallery.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxgallerycontrol
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxGalleryControlPainterClass;

class DELPHICLASS TdxGalleryControlItem;
typedef void __fastcall (__closure *TdxGalleryControlItemEvent)(System::TObject* Sender, TdxGalleryControlItem* AItem);

typedef System::DynamicArray<TdxGalleryControlItem*> Dxgallerycontrol__1;

typedef System::DynamicArray<System::DynamicArray<TdxGalleryControlItem*> > TdxGalleryControlItemMatrix;

class DELPHICLASS TdxGalleryPersistent;
class DELPHICLASS TdxCustomGalleryControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryPersistent : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TdxCustomGalleryControl* __fastcall GetOwnerControl(void);
	
protected:
	__property TdxCustomGalleryControl* Owner = {read=GetOwnerControl};
	
public:
	__fastcall virtual TdxGalleryPersistent(TdxCustomGalleryControl* AOwner);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxGalleryPersistent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryCustomViewInfo;
class DELPHICLASS TdxGalleryControlOptionsItemImage;
class DELPHICLASS TdxGalleryControlOptionsItemText;
class DELPHICLASS TdxGalleryControlOptionsView;
class DELPHICLASS TdxGalleryControlPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryCustomViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect __fastcall GetContentOffset(void);
	System::Types::TRect __fastcall GetContentOffsetGroups(void);
	System::Types::TRect __fastcall GetContentOffsetItems(void);
	TdxGalleryControlOptionsItemImage* __fastcall GetOptionsItemImage(void);
	TdxGalleryControlOptionsItemText* __fastcall GetOptionsItemText(void);
	TdxGalleryControlOptionsView* __fastcall GetOptionsView(void);
	TdxGalleryControlPainter* __fastcall GetPainter(void);
	
protected:
	System::Types::TRect FBounds;
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	virtual TdxCustomGalleryControl* __fastcall GetGalleryControl(void) = 0 ;
	
public:
	virtual void __fastcall Calculate(Cxcontrols::TdxChangeType AType, const System::Types::TRect &ABounds) = 0 ;
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::Types::TRect ContentOffset = {read=GetContentOffset};
	__property System::Types::TRect ContentOffsetGroups = {read=GetContentOffsetGroups};
	__property System::Types::TRect ContentOffsetItems = {read=GetContentOffsetItems};
	__property TdxCustomGalleryControl* GalleryControl = {read=GetGalleryControl};
	__property TdxGalleryControlOptionsItemImage* OptionsItemImage = {read=GetOptionsItemImage};
	__property TdxGalleryControlOptionsItemText* OptionsItemText = {read=GetOptionsItemText};
	__property TdxGalleryControlOptionsView* OptionsView = {read=GetOptionsView};
	__property TdxGalleryControlPainter* Painter = {read=GetPainter};
public:
	/* TObject.Create */ inline __fastcall TdxGalleryCustomViewInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGalleryCustomViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryItemViewInfo : public TdxGalleryCustomViewInfo
{
	typedef TdxGalleryCustomViewInfo inherited;
	
private:
	Cxgraphics::TcxBitmap32* FCacheGlyph;
	TdxGalleryControlItem* FItem;
	Cxgraphics::TcxBitmap32* __fastcall GetCacheGlyph(void);
	System::UnicodeString __fastcall GetCaption(void);
	System::UnicodeString __fastcall GetDescription(void);
	System::Types::TSize __fastcall GetGlyphSize(void);
	
protected:
	System::Types::TRect FCaptionRect;
	System::Types::TSize FCaptionSize;
	System::Types::TPoint FCellPositionInGroup;
	System::Types::TRect FContentBounds;
	System::Types::TRect FDescriptionRect;
	System::Types::TSize FDescriptionSize;
	System::Types::TRect FGlyphFrameRect;
	System::Types::TRect FGlyphRect;
	Cxlookandfeelpainters::TdxGalleryItemViewState FState;
	System::Types::TRect FTextArea;
	virtual void __fastcall CalculateGlyphArea(const System::Types::TSize &AGlyphSize);
	virtual void __fastcall CalculateTextArea(const System::Types::TSize &ATextAreaSize);
	virtual void __fastcall CalculateTextAreaContent(const System::Types::TRect &ABounds);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetDescriptionOffset(void);
	virtual TdxCustomGalleryControl* __fastcall GetGalleryControl(void);
	virtual System::Types::TSize __fastcall GetTextAreaSize(void);
	virtual void __fastcall ResetCache(void);
	
public:
	__fastcall virtual TdxGalleryItemViewInfo(TdxGalleryControlItem* AItem);
	__fastcall virtual ~TdxGalleryItemViewInfo(void);
	virtual void __fastcall Calculate(Cxcontrols::TdxChangeType AType, const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateTextAreaSizeLimitedByRowCount(Cxgraphics::TcxCanvas* ACanvas, int ARowCount);
	virtual void __fastcall CalculateTextAreaSizeLimitedByWidth(Cxgraphics::TcxCanvas* ACanvas, int AMaxWidth);
	__property Cxgraphics::TcxBitmap32* CacheGlyph = {read=GetCacheGlyph};
	__property System::UnicodeString Caption = {read=GetCaption};
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property System::Types::TSize CaptionSize = {read=FCaptionSize};
	__property System::Types::TPoint CellPositionInGroup = {read=FCellPositionInGroup};
	__property System::Types::TRect ContentBounds = {read=FContentBounds};
	__property System::UnicodeString Description = {read=GetDescription};
	__property int DescriptionOffset = {read=GetDescriptionOffset, nodefault};
	__property System::Types::TRect DescriptionRect = {read=FDescriptionRect};
	__property System::Types::TSize DescriptionSize = {read=FDescriptionSize};
	__property System::Types::TRect GlyphFrameRect = {read=FGlyphFrameRect};
	__property System::Types::TRect GlyphRect = {read=FGlyphRect};
	__property System::Types::TSize GlyphSize = {read=GetGlyphSize};
	__property TdxGalleryControlItem* Item = {read=FItem};
	__property Cxlookandfeelpainters::TdxGalleryItemViewState State = {read=FState};
	__property System::Types::TRect TextArea = {read=FTextArea};
	__property System::Types::TSize TextAreaSize = {read=GetTextAreaSize};
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlGroup;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlItem : public Dxgallery::TdxGalleryItem
{
	typedef Dxgallery::TdxGalleryItem inherited;
	
private:
	TdxGalleryItemViewInfo* FViewInfo;
	HIDESBASE TdxGalleryControlGroup* __fastcall GetGroup(void);
	TdxCustomGalleryControl* __fastcall GetGalleryControl(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	
protected:
	virtual TdxGalleryItemViewInfo* __fastcall CreateViewInfo(void);
	__property TdxCustomGalleryControl* GalleryControl = {read=GetGalleryControl};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	__property TdxGalleryItemViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TdxGalleryControlItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxGalleryControlItem(void);
	__property TdxGalleryControlGroup* Group = {read=GetGroup};
	
__published:
	__property Caption = {default=0};
	__property Checked = {default=0};
	__property Description = {default=0};
	__property Enabled = {default=1};
	__property Glyph;
	__property Hint = {default=0};
	__property ImageIndex = {default=-1};
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlItems;
class PASCALIMPLEMENTATION TdxGalleryControlItems : public Dxgallery::TdxGalleryItems
{
	typedef Dxgallery::TdxGalleryItems inherited;
	
public:
	TdxGalleryControlItem* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	HIDESBASE TdxGalleryControlItem* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TdxGalleryControlItem* AValue);
	
public:
	HIDESBASE TdxGalleryControlItem* __fastcall Add(void);
	TdxGalleryControlItem* __fastcall GetItemAtPos(const System::Types::TPoint &P);
	__property TdxGalleryControlItem* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxGalleryControlItems(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Dxgallery::TdxGalleryItems(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxGalleryControlItems(void) { }
	
};


class DELPHICLASS TdxGalleryGroupViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryGroupViewInfo : public TdxGalleryCustomViewInfo
{
	typedef TdxGalleryCustomViewInfo inherited;
	
private:
	TdxGalleryControlGroup* FGroup;
	System::UnicodeString __fastcall GetCaption(void);
	System::Types::TSize __fastcall GetSize(void);
	
protected:
	System::Types::TRect FCaptionRect;
	System::Types::TRect FCaptionTextRect;
	int FColumnCount;
	System::Types::TRect FItemsRect;
	int FRowCount;
	virtual void __fastcall CalculateCaption(void);
	virtual void __fastcall CalculateItems(Cxcontrols::TdxChangeType AType);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetCaptionHeight(void);
	virtual System::Types::TRect __fastcall GetCaptionTextOffsets(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual TdxCustomGalleryControl* __fastcall GetGalleryControl(void);
	void __fastcall PlaceItem(TdxGalleryControlItem* AItem, Cxcontrols::TdxChangeType AChangeType, const System::Types::TRect &AItemsArea, int ACellIndex);
	
public:
	__fastcall virtual TdxGalleryGroupViewInfo(TdxGalleryControlGroup* AGroup);
	virtual void __fastcall Calculate(Cxcontrols::TdxChangeType AType, const System::Types::TRect &ABounds);
	virtual int __fastcall GetMaxColumnCount(void);
	__property System::UnicodeString Caption = {read=GetCaption};
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property System::Types::TRect CaptionTextOffsets = {read=GetCaptionTextOffsets};
	__property System::Types::TRect CaptionTextRect = {read=FCaptionTextRect};
	__property int ColumnCount = {read=FColumnCount, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property TdxGalleryControlGroup* Group = {read=FGroup};
	__property System::Types::TSize ItemSize = {read=GetSize};
	__property System::Types::TRect ItemsRect = {read=FItemsRect};
	__property int RowCount = {read=FRowCount, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGalleryGroupViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlGroup : public Dxgallery::TdxGalleryGroup
{
	typedef Dxgallery::TdxGalleryGroup inherited;
	
private:
	TdxGalleryGroupViewInfo* FViewInfo;
	TdxCustomGalleryControl* __fastcall GetGalleryControl(void);
	TdxGalleryControlItems* __fastcall GetItems(void);
	
protected:
	virtual TdxGalleryGroupViewInfo* __fastcall CreateViewInfo(void);
	virtual Dxgallery::TdxGalleryItemClass __fastcall GetGalleryItemClass(void);
	virtual Dxgallery::TdxGalleryItemsClass __fastcall GetGalleryItemsClass(void);
	__property TdxCustomGalleryControl* GalleryControl = {read=GetGalleryControl};
	__property TdxGalleryGroupViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TdxGalleryControlGroup(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxGalleryControlGroup(void);
	__property TdxGalleryControlItems* Items = {read=GetItems};
	
__published:
	__property Caption = {default=0};
	__property ShowCaption = {default=1};
	__property Visible = {default=1};
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlGroups;
class PASCALIMPLEMENTATION TdxGalleryControlGroups : public Dxgallery::TdxGalleryGroups
{
	typedef Dxgallery::TdxGalleryGroups inherited;
	
public:
	TdxGalleryControlGroup* operator[](int AIndex) { return Groups[AIndex]; }
	
private:
	HIDESBASE TdxGalleryControlGroup* __fastcall GetGroup(int AIndex);
	HIDESBASE void __fastcall SetGroup(int AIndex, TdxGalleryControlGroup* AValue);
	
public:
	HIDESBASE TdxGalleryControlGroup* __fastcall Add(void);
	HIDESBASE bool __fastcall FindByCaption(const System::UnicodeString ACaption, /* out */ TdxGalleryControlGroup* &AGroup);
	TdxGalleryControlItem* __fastcall GetItemAtPos(const System::Types::TPoint &P);
	__property TdxGalleryControlGroup* Groups[int AIndex] = {read=GetGroup, write=SetGroup/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxGalleryControlGroups(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Dxgallery::TdxGalleryGroups(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxGalleryControlGroups(void) { }
	
};


class DELPHICLASS TdxGalleryControlStructure;
class PASCALIMPLEMENTATION TdxGalleryControlStructure : public Dxgallery::TdxGallery
{
	typedef Dxgallery::TdxGallery inherited;
	
private:
	HIDESBASE TdxGalleryControlGroups* __fastcall GetGroups(void);
	
protected:
	virtual Dxgallery::TdxGalleryGroupClass __fastcall GetGroupClass(void);
	virtual Dxgallery::TdxGalleryGroupsClass __fastcall GetGroupsClass(void);
	
public:
	HIDESBASE TdxGalleryControlItem* __fastcall GetCheckedItem(void);
	HIDESBASE TdxGalleryControlItem* __fastcall GetFirstItem(void);
	__property TdxGalleryControlGroups* Groups = {read=GetGroups};
public:
	/* TdxCustomGallery.Create */ inline __fastcall virtual TdxGalleryControlStructure(System::Classes::TPersistent* AOwner) : Dxgallery::TdxGallery(AOwner) { }
	/* TdxCustomGallery.Destroy */ inline __fastcall virtual ~TdxGalleryControlStructure(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlPainter : public TdxGalleryPersistent
{
	typedef TdxGalleryPersistent inherited;
	
private:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual bool __fastcall DrawItemSelectionFirst(void);
	virtual System::Uitypes::TColor __fastcall GetGroupCaptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetItemCaptionTextColor(const Cxlookandfeelpainters::TdxGalleryItemViewState &AState);
	virtual System::Uitypes::TColor __fastcall GetItemDescriptionTextColor(const Cxlookandfeelpainters::TdxGalleryItemViewState &AState);
	
public:
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawGroupHeader(Cxgraphics::TcxCanvas* ACanvas, TdxGalleryGroupViewInfo* const AViewInfo);
	virtual void __fastcall DrawGroupHeaderText(Cxgraphics::TcxCanvas* ACanvas, TdxGalleryGroupViewInfo* const AViewInfo);
	virtual System::Types::TRect __fastcall GetGroupHeaderContentOffsets(void);
	virtual void __fastcall DrawItem(Cxgraphics::TcxCanvas* ACanvas, TdxGalleryItemViewInfo* AViewInfo);
	virtual void __fastcall DrawItemImage(Cxgraphics::TcxCanvas* ACanvas, TdxGalleryItemViewInfo* AViewInfo);
	virtual void __fastcall DrawItemSelection(Cxgraphics::TcxCanvas* ACanvas, TdxGalleryItemViewInfo* AViewInfo);
	virtual void __fastcall DrawItemText(Cxgraphics::TcxCanvas* ACanvas, TdxGalleryItemViewInfo* AViewInfo);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
public:
	/* TdxGalleryPersistent.Create */ inline __fastcall virtual TdxGalleryControlPainter(TdxCustomGalleryControl* AOwner) : TdxGalleryPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxGalleryControlPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlViewInfo : public TdxGalleryCustomViewInfo
{
	typedef TdxGalleryCustomViewInfo inherited;
	
private:
	TdxCustomGalleryControl* FGalleryControl;
	bool __fastcall GetAutoHeight(void);
	bool __fastcall GetAutoWidth(void);
	bool __fastcall GetColumnAutoWidth(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	TdxGalleryControlGroups* __fastcall GetGroups(void);
	int __fastcall GetMaxColumnCount(void);
	int __fastcall GetRowCount(void);
	
protected:
	int FColumnCount;
	System::Types::TRect FContentBounds;
	System::Types::TSize FImageSize;
	System::Types::TSize FItemSize;
	System::Types::TSize FTextAreaSize;
	virtual void __fastcall CalculateColumnCount(void);
	virtual void __fastcall CalculateContentBounds(Cxcontrols::TdxChangeType AType);
	virtual void __fastcall CalculateItemSize(void);
	virtual System::Types::TSize __fastcall CalculateMaxItemImageSize(void);
	virtual System::Types::TSize __fastcall CalculateMaxItemTextAreaSize(const System::Types::TSize &AImageSize);
	virtual System::Types::TSize __fastcall CalculateMaxItemTextAreaSizeLimitedByRowCount(int ARowCount);
	virtual System::Types::TSize __fastcall CalculateMaxItemTextAreaSizeLimitedByWidth(int AMaxWidth);
	virtual System::Types::TSize __fastcall DoCalculateItemSize(void);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetAvailableGroupsAreaWidth(void);
	virtual System::Types::TRect __fastcall GetBorderWidths(void);
	virtual TdxCustomGalleryControl* __fastcall GetGalleryControl(void);
	virtual int __fastcall GetTextAreaMaxRowCount(const System::Types::TSize &AImageSize);
	virtual int __fastcall GetTextAreaMaxWidth(const System::Types::TSize &AImageSize);
	
public:
	__fastcall virtual TdxGalleryControlViewInfo(TdxCustomGalleryControl* AGalleryControl);
	virtual void __fastcall Calculate(Cxcontrols::TdxChangeType AType, const System::Types::TRect &ABounds);
	__property bool AutoHeight = {read=GetAutoHeight, nodefault};
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property System::Types::TRect BorderWidths = {read=GetBorderWidths};
	__property bool ColumnAutoWidth = {read=GetColumnAutoWidth, nodefault};
	__property int ColumnCount = {read=FColumnCount, nodefault};
	__property System::Types::TRect ContentBounds = {read=FContentBounds};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property TdxGalleryControlGroups* Groups = {read=GetGroups};
	__property System::Types::TSize ImageSize = {read=FImageSize};
	__property System::Types::TSize ItemSize = {read=FItemSize};
	__property int MaxColumnCount = {read=GetMaxColumnCount, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property System::Types::TSize TextAreaSize = {read=FTextAreaSize};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGalleryControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlNavigationMatrix;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlNavigationMatrix : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FColumnCount;
	int FRowCount;
	TdxGalleryControlItemMatrix FValues;
	TdxGalleryControlItem* __fastcall GetValue(int ACol, int ARow);
	void __fastcall SetValue(int ACol, int ARow, TdxGalleryControlItem* const AValue);
	
protected:
	virtual void __fastcall Populate(TdxGalleryControlViewInfo* AViewInfo);
	
public:
	__fastcall TdxGalleryControlNavigationMatrix(TdxGalleryControlViewInfo* AViewInfo);
	__fastcall virtual ~TdxGalleryControlNavigationMatrix(void);
	int __fastcall GetRightMostItemIndex(int ARow);
	__property int ColumnCount = {read=FColumnCount, nodefault};
	__property int RowCount = {read=FRowCount, nodefault};
	__property TdxGalleryControlItem* Values[int ACol][int ARow] = {read=GetValue, write=SetValue};
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlController : public TdxGalleryPersistent
{
	typedef TdxGalleryPersistent inherited;
	
private:
	bool FKeyPressed;
	TdxGalleryControlItem* FKeySelectedItem;
	TdxGalleryControlItem* FMouseHoveredItem;
	bool FMousePressed;
	TdxGalleryControlNavigationMatrix* FNavigationMatrix;
	TdxGalleryControlStructure* __fastcall GetGallery(void);
	TdxGalleryControlNavigationMatrix* __fastcall GetNavigationMatrix(void);
	TdxGalleryControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetKeyPressed(bool AValue);
	void __fastcall SetKeySelectedItem(TdxGalleryControlItem* AItem);
	void __fastcall SetMouseHoveredItem(TdxGalleryControlItem* AItem);
	void __fastcall SetMousePressed(bool AValue);
	
protected:
	TdxGalleryControlItem* __fastcall GetItemAtPos(const System::Types::TPoint &P);
	virtual System::Types::TPoint __fastcall GetItemPosition(TdxGalleryControlItem* AItem);
	Cxlookandfeelpainters::TdxGalleryItemViewState __fastcall GetItemViewState(TdxGalleryControlItem* AItem);
	void __fastcall InvalidateItem(TdxGalleryControlItem* AItem);
	virtual void __fastcall MakeItemVisible(TdxGalleryControlItem* AItem);
	void __fastcall UpdateItemViewState(TdxGalleryControlItem* AItem);
	virtual void __fastcall UpdateMouseHoveredItem(const System::Types::TPoint &P);
	virtual TdxGalleryControlNavigationMatrix* __fastcall CreateNavigationMatrix(void);
	virtual void __fastcall GetNextItem(System::Types::TPoint &AItemPos, int ADirectionX, int ADirectionY);
	virtual TdxGalleryControlItem* __fastcall GetStartItemForKeyboardNavigation(void);
	virtual void __fastcall SelectNextItem(TdxGalleryControlItem* AItem, int ADirectionX, int ADirectionY);
	virtual void __fastcall ProcessItemClick(TdxGalleryControlItem* AItem, int X, int Y);
	
public:
	virtual void __fastcall CheckSelectedItem(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall FocusEnter(void);
	virtual void __fastcall FocusLeave(void);
	virtual void __fastcall KeyDown(System::Word AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall KeyUp(System::Word AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__property TdxGalleryControlStructure* Gallery = {read=GetGallery};
	__property bool KeyPressed = {read=FKeyPressed, write=SetKeyPressed, nodefault};
	__property TdxGalleryControlItem* KeySelectedItem = {read=FKeySelectedItem, write=SetKeySelectedItem};
	__property TdxGalleryControlItem* MouseHoveredItem = {read=FMouseHoveredItem, write=SetMouseHoveredItem};
	__property bool MousePressed = {read=FMousePressed, write=SetMousePressed, nodefault};
	__property TdxGalleryControlNavigationMatrix* NavigationMatrix = {read=GetNavigationMatrix};
	__property TdxGalleryControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxGalleryPersistent.Create */ inline __fastcall virtual TdxGalleryControlController(TdxCustomGalleryControl* AOwner) : TdxGalleryPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxGalleryControlController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlCustomOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlCustomOptions : public TdxGalleryPersistent
{
	typedef TdxGalleryPersistent inherited;
	
protected:
	void __fastcall Changed(Cxcontrols::TdxChangeType AType = (Cxcontrols::TdxChangeType)(0x2));
public:
	/* TdxGalleryPersistent.Create */ inline __fastcall virtual TdxGalleryControlCustomOptions(TdxCustomGalleryControl* AOwner) : TdxGalleryPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxGalleryControlCustomOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlOptionsBehavior : public TdxGalleryControlCustomOptions
{
	typedef TdxGalleryControlCustomOptions inherited;
	
private:
	bool FItemShowHint;
	Dxgallery::TdxGalleryItemCheckMode __fastcall GetItemCheckMode(void);
	void __fastcall SetItemCheckMode(const Dxgallery::TdxGalleryItemCheckMode Value);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
__published:
	__property Dxgallery::TdxGalleryItemCheckMode ItemCheckMode = {read=GetItemCheckMode, write=SetItemCheckMode, default=0};
	__property bool ItemShowHint = {read=FItemShowHint, write=FItemShowHint, default=0};
public:
	/* TdxGalleryPersistent.Create */ inline __fastcall virtual TdxGalleryControlOptionsBehavior(TdxCustomGalleryControl* AOwner) : TdxGalleryControlCustomOptions(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxGalleryControlOptionsBehavior(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlOptionsItemImage : public TdxGalleryControlCustomOptions
{
	typedef TdxGalleryControlCustomOptions inherited;
	
private:
	bool FShowFrame;
	Cxgeometry::TcxSize* FSize;
	void __fastcall ChangeHandler(System::TObject* Sender);
	void __fastcall SetShowFrame(const bool Value);
	void __fastcall SetSize(Cxgeometry::TcxSize* const Value);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxGalleryControlOptionsItemImage(TdxCustomGalleryControl* AOwner);
	__fastcall virtual ~TdxGalleryControlOptionsItemImage(void);
	
__published:
	__property bool ShowFrame = {read=FShowFrame, write=SetShowFrame, default=1};
	__property Cxgeometry::TcxSize* Size = {read=FSize, write=SetSize};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlOptionsItemText : public TdxGalleryControlCustomOptions
{
	typedef TdxGalleryControlCustomOptions inherited;
	
private:
	System::Classes::TAlignment FAlignHorz;
	Cxclasses::TcxAlignmentVert FAlignVert;
	Cxclasses::TcxPosition FPosition;
	bool FWordWrap;
	void __fastcall SetAlignHorz(const System::Classes::TAlignment Value);
	void __fastcall SetAlignVert(const Cxclasses::TcxAlignmentVert Value);
	void __fastcall SetPosition(const Cxclasses::TcxPosition Value);
	void __fastcall SetWordWrap(const bool Value);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxGalleryControlOptionsItemText(TdxCustomGalleryControl* AOwner);
	
__published:
	__property System::Classes::TAlignment AlignHorz = {read=FAlignHorz, write=SetAlignHorz, default=2};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=FAlignVert, write=SetAlignVert, default=0};
	__property Cxclasses::TcxPosition Position = {read=FPosition, write=SetPosition, default=0};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxGalleryControlOptionsItemText(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryControlOptionsItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlOptionsItem : public TdxGalleryControlCustomOptions
{
	typedef TdxGalleryControlCustomOptions inherited;
	
private:
	TdxGalleryControlOptionsItemImage* FImage;
	TdxGalleryControlOptionsItemText* FText;
	void __fastcall SetImage(TdxGalleryControlOptionsItemImage* AValue);
	void __fastcall SetText(TdxGalleryControlOptionsItemText* AValue);
	
protected:
	virtual TdxGalleryControlOptionsItemImage* __fastcall CreateImage(void);
	virtual TdxGalleryControlOptionsItemText* __fastcall CreateText(void);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxGalleryControlOptionsItem(TdxCustomGalleryControl* AOwner);
	__fastcall virtual ~TdxGalleryControlOptionsItem(void);
	
__published:
	__property TdxGalleryControlOptionsItemImage* Image = {read=FImage, write=SetImage};
	__property TdxGalleryControlOptionsItemText* Text = {read=FText, write=SetText};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryControlOptionsView : public TdxGalleryControlCustomOptions
{
	typedef TdxGalleryControlCustomOptions inherited;
	
private:
	bool FColumnAutoWidth;
	int FColumnCount;
	Cxgeometry::TcxMargin* FContentOffset;
	Cxgeometry::TcxMargin* FContentOffsetGroups;
	Cxgeometry::TcxMargin* FContentOffsetItems;
	TdxGalleryControlOptionsItem* FItem;
	void __fastcall ChangeHandler(System::TObject* Sender);
	void __fastcall SetColumnAutoWidth(bool AValue);
	void __fastcall SetColumnCount(int AValue);
	void __fastcall SetContentOffset(Cxgeometry::TcxMargin* const Value);
	void __fastcall SetContentOffsetGroups(Cxgeometry::TcxMargin* const Value);
	void __fastcall SetContentOffsetItems(Cxgeometry::TcxMargin* const Value);
	void __fastcall SetItem(TdxGalleryControlOptionsItem* const Value);
	
protected:
	virtual TdxGalleryControlOptionsItem* __fastcall CreateItem(void);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxGalleryControlOptionsView(TdxCustomGalleryControl* AOwner);
	__fastcall virtual ~TdxGalleryControlOptionsView(void);
	
__published:
	__property bool ColumnAutoWidth = {read=FColumnAutoWidth, write=SetColumnAutoWidth, default=0};
	__property int ColumnCount = {read=FColumnCount, write=SetColumnCount, default=0};
	__property Cxgeometry::TcxMargin* ContentOffset = {read=FContentOffset, write=SetContentOffset};
	__property Cxgeometry::TcxMargin* ContentOffsetGroups = {read=FContentOffsetGroups, write=SetContentOffsetGroups};
	__property Cxgeometry::TcxMargin* ContentOffsetItems = {read=FContentOffsetItems, write=SetContentOffsetItems};
	__property TdxGalleryControlOptionsItem* Item = {read=FItem, write=SetItem};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxCustomGalleryControl : public Cxcontrols::TcxScrollingControl
{
	typedef Cxcontrols::TcxScrollingControl inherited;
	
private:
	TdxGalleryControlController* FController;
	TdxGalleryControlStructure* FGallery;
	Vcl::Imglist::TCustomImageList* FImages;
	int FLockCount;
	TdxGalleryControlOptionsBehavior* FOptionsBehavior;
	TdxGalleryControlOptionsView* FOptionsView;
	TdxGalleryControlPainter* FPainter;
	TdxGalleryControlViewInfo* FViewInfo;
	TdxGalleryControlItemEvent FOnItemClick;
	int __fastcall GetColumnCount(void);
	Cxgeometry::TcxMargin* __fastcall GetContentOffset(void);
	Cxgeometry::TcxMargin* __fastcall GetContentOffsetGroups(void);
	Cxgeometry::TcxMargin* __fastcall GetContentOffsetItems(void);
	Dxgallery::TdxGalleryItemCheckMode __fastcall GetItemCheckMode(void);
	int __fastcall GetItemCount(void);
	Cxgeometry::TcxSize* __fastcall GetItemImageSize(void);
	bool __fastcall GetItemShowHint(void);
	bool __fastcall GetItemShowImageFrame(void);
	Cxclasses::TcxPosition __fastcall GetItemTextPosition(void);
	void __fastcall SetColumnCount(int AValue);
	void __fastcall SetContentOffset(Cxgeometry::TcxMargin* AValue);
	void __fastcall SetContentOffsetGroups(Cxgeometry::TcxMargin* AValue);
	void __fastcall SetContentOffsetItems(Cxgeometry::TcxMargin* AValue);
	void __fastcall SetGallery(TdxGalleryControlStructure* AValue);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetItemCheckMode(Dxgallery::TdxGalleryItemCheckMode AValue);
	void __fastcall SetItemImageSize(Cxgeometry::TcxSize* AValue);
	void __fastcall SetItemShowHint(const bool Value);
	void __fastcall SetItemShowImageFrame(bool AValue);
	void __fastcall SetItemTextPosition(Cxclasses::TcxPosition AValue);
	void __fastcall SetOptionsBehavior(TdxGalleryControlOptionsBehavior* const Value);
	void __fastcall SetOptionsView(TdxGalleryControlOptionsView* const Value);
	void __fastcall GalleryChangeHandler(System::TObject* ASender, Dxgallery::TdxGalleryChangeType AChangeType);
	void __fastcall GalleryItemClickHandler(System::TObject* ASender, Dxgallery::TdxGalleryItem* AItem);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	
protected:
	virtual TdxGalleryControlController* __fastcall CreateController(void);
	virtual TdxGalleryControlStructure* __fastcall CreateGallery(void);
	virtual TdxGalleryControlOptionsBehavior* __fastcall CreateOptionsBehavior(void);
	virtual TdxGalleryControlOptionsView* __fastcall CreateOptionsView(void);
	virtual TdxGalleryControlPainter* __fastcall CreatePainter(void);
	virtual TdxGalleryControlViewInfo* __fastcall CreateViewInfo(void);
	DYNAMIC void __fastcall FocusEnter(void);
	DYNAMIC void __fastcall FocusLeave(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	virtual System::Types::TSize __fastcall GetContentSize(void);
	virtual void __fastcall Calculate(Cxcontrols::TdxChangeType AType);
	virtual void __fastcall LayoutChanged(Cxcontrols::TdxChangeType AType = (Cxcontrols::TdxChangeType)(0x2));
	virtual void __fastcall SetAutoSizeMode(Cxcontrols::TdxAutoSizeMode AValue);
	virtual void __fastcall DoClickItem(Dxgallery::TdxGalleryItem* AItem);
	TdxGalleryControlItem* __fastcall GetItemAtPos(const System::Types::TPoint &P);
	bool __fastcall IsUpdateLocked(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	Dxgallery::_di_IdxGallery __fastcall GetGallery(void);
	__property TdxGalleryControlController* Controller = {read=FController};
	__property TdxGalleryControlPainter* Painter = {read=FPainter};
	__property TdxGalleryControlViewInfo* ViewInfo = {read=FViewInfo};
	__property TdxGalleryControlStructure* Gallery = {read=FGallery, write=SetGallery};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TdxGalleryControlOptionsBehavior* OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior};
	__property TdxGalleryControlOptionsView* OptionsView = {read=FOptionsView, write=SetOptionsView};
	__property int ColumnCount = {read=GetColumnCount, write=SetColumnCount, nodefault};
	__property Cxgeometry::TcxMargin* ContentOffset = {read=GetContentOffset, write=SetContentOffset};
	__property Cxgeometry::TcxMargin* ContentOffsetGroups = {read=GetContentOffsetGroups, write=SetContentOffsetGroups};
	__property Cxgeometry::TcxMargin* ContentOffsetItems = {read=GetContentOffsetItems, write=SetContentOffsetItems};
	__property Dxgallery::TdxGalleryItemCheckMode ItemCheckMode = {read=GetItemCheckMode, write=SetItemCheckMode, nodefault};
	__property Cxgeometry::TcxSize* ItemImageSize = {read=GetItemImageSize, write=SetItemImageSize};
	__property bool ItemShowHint = {read=GetItemShowHint, write=SetItemShowHint, nodefault};
	__property bool ItemShowImageFrame = {read=GetItemShowImageFrame, write=SetItemShowImageFrame, nodefault};
	__property Cxclasses::TcxPosition ItemTextPosition = {read=GetItemTextPosition, write=SetItemTextPosition, nodefault};
	__property TdxGalleryControlItemEvent OnItemClick = {read=FOnItemClick, write=FOnItemClick};
	
public:
	__fastcall virtual TdxCustomGalleryControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomGalleryControl(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomGalleryControl(HWND ParentWindow) : Cxcontrols::TcxScrollingControl(ParentWindow) { }
	
private:
	void *__IdxGalleryOwner;	/* Dxgallery::IdxGalleryOwner */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9E2F64DD-D370-4B24-8FF3-7E4FE08A15F1}
	operator Dxgallery::_di_IdxGalleryOwner()
	{
		Dxgallery::_di_IdxGalleryOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxgallery::IdxGalleryOwner*(void) { return (Dxgallery::IdxGalleryOwner*)&__IdxGalleryOwner; }
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


class DELPHICLASS TdxGalleryControl;
class PASCALIMPLEMENTATION TdxGalleryControl : public TdxCustomGalleryControl
{
	typedef TdxCustomGalleryControl inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Enabled = {default=1};
	__property Font;
	__property PopupMenu;
	__property Visible = {default=1};
	__property AutoSizeMode = {default=0};
	__property BorderStyle = {default=1};
	__property Gallery;
	__property Images;
	__property LookAndFeel;
	__property OptionsBehavior;
	__property OptionsView;
	__property ColumnCount = {stored=false};
	__property ContentOffset = {stored=false};
	__property ContentOffsetGroups = {stored=false};
	__property ContentOffsetItems = {stored=false};
	__property ItemCheckMode = {stored=false};
	__property ItemImageSize = {stored=false};
	__property ItemShowHint = {stored=false};
	__property ItemShowImageFrame = {stored=false};
	__property ItemTextPosition = {stored=false};
	__property OnClick;
	__property OnDblClick;
	__property OnContextPopup;
	__property OnItemClick;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TdxCustomGalleryControl.Create */ inline __fastcall virtual TdxGalleryControl(System::Classes::TComponent* AOwner) : TdxCustomGalleryControl(AOwner) { }
	/* TdxCustomGalleryControl.Destroy */ inline __fastcall virtual ~TdxGalleryControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxGalleryControl(HWND ParentWindow) : TdxCustomGalleryControl(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxgallerycontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXGALLERYCONTROL)
using namespace Dxgallerycontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxgallerycontrolHPP
