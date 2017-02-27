// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBreadcrumbEdit.pas' rev: 24.00 (Win32)

#ifndef DxbreadcrumbeditHPP
#define DxbreadcrumbeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCustomTree.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbreadcrumbedit
{
//-- type declarations -------------------------------------------------------
enum TdxBreadcrumbEditChange : unsigned char { bcecAnimation, bcecButtons, bcecLayout, bcecNodes, bcecPathEditor, bcecProgress, bcecSelection };

typedef System::Set<TdxBreadcrumbEditChange, TdxBreadcrumbEditChange::bcecAnimation, TdxBreadcrumbEditChange::bcecSelection>  TdxBreadcrumbEditChanges;

typedef void __fastcall (__closure *TdxBreadcrumbEditChangeEvent)(System::TObject* Sender, TdxBreadcrumbEditChanges AChanges);

__interface IdxBreadcrumbEdit;
typedef System::DelphiInterface<IdxBreadcrumbEdit> _di_IdxBreadcrumbEdit;
class DELPHICLASS TdxBreadcrumbEditController;
class DELPHICLASS TdxCustomBreadcrumbEditProperties;
class DELPHICLASS TdxBreadcrumbEditNode;
__interface  INTERFACE_UUID("{1F299DAA-9C6C-4EBA-B1C3-14E2DF2DEEEE}") IdxBreadcrumbEdit  : public Cxlookandfeels::IcxLookAndFeelContainer 
{
	
public:
	virtual Vcl::Controls::TWinControl* __fastcall GetContainer(void) = 0 ;
	virtual TdxBreadcrumbEditController* __fastcall GetController(void) = 0 ;
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void) = 0 ;
	virtual bool __fastcall GetIsEnabled(void) = 0 ;
	virtual bool __fastcall GetIsFocused(void) = 0 ;
	virtual TdxCustomBreadcrumbEditProperties* __fastcall GetProperties(void) = 0 ;
	virtual TdxBreadcrumbEditNode* __fastcall GetRoot(void) = 0 ;
	virtual bool __fastcall GetShowHint(void) = 0 ;
	virtual void __fastcall AdjustAutoSize(void) = 0 ;
};

__interface IdxBreadcrumbEditEvents;
typedef System::DelphiInterface<IdxBreadcrumbEditEvents> _di_IdxBreadcrumbEditEvents;
class DELPHICLASS TdxBreadcrumbEditButton;
__interface  INTERFACE_UUID("{58BB7C9A-21D2-4E8C-B95C-E20BC3768E28}") IdxBreadcrumbEditEvents  : public System::IInterface 
{
	
public:
	virtual void __fastcall NodeDropDownPopup(TdxBreadcrumbEditNode* ANode) = 0 ;
	virtual void __fastcall PathEntered(System::UnicodeString &ANewPath, bool &AHandled) = 0 ;
	virtual void __fastcall PathValidate(const System::UnicodeString APath, TdxBreadcrumbEditNode* &ANode, System::UnicodeString &AErrorText, bool &AError) = 0 ;
	virtual void __fastcall PopulateAutoCompleteSuggestions(const System::UnicodeString APath, System::Classes::TStringList* ASuggestions) = 0 ;
	virtual void __fastcall ProcessButtonClick(TdxBreadcrumbEditButton* AButton) = 0 ;
	virtual void __fastcall SelectionChanged(void) = 0 ;
};

class DELPHICLASS EdxBreadcrumbEditValidationError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxBreadcrumbEditValidationError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxBreadcrumbEditValidationError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxBreadcrumbEditValidationError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxBreadcrumbEditValidationError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxBreadcrumbEditValidationError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxBreadcrumbEditValidationError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxBreadcrumbEditValidationError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxBreadcrumbEditValidationError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxBreadcrumbEditValidationError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxBreadcrumbEditValidationError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxBreadcrumbEditValidationError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxBreadcrumbEditValidationError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxBreadcrumbEditValidationError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxBreadcrumbEditValidationError(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditNode : public Dxcustomtree::TdxTreeCustomNode
{
	typedef Dxcustomtree::TdxTreeCustomNode inherited;
	
public:
	TdxBreadcrumbEditNode* operator[](int Index) { return Items[Index]; }
	
private:
	bool FIsHidden;
	TdxBreadcrumbEditNode* __fastcall GetFirst(void);
	HIDESBASE TdxBreadcrumbEditNode* __fastcall GetItem(int AIndex);
	TdxBreadcrumbEditNode* __fastcall GetLast(void);
	TdxBreadcrumbEditNode* __fastcall GetNext(void);
	TdxBreadcrumbEditNode* __fastcall GetParent(void);
	TdxBreadcrumbEditNode* __fastcall GetPrev(void);
	HIDESBASE TdxBreadcrumbEditNode* __fastcall GetRoot(void);
	void __fastcall SetName(const System::UnicodeString AValue);
	
protected:
	System::UnicodeString FName;
	virtual System::UnicodeString __fastcall GetPath(void);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	__property bool IsHidden = {read=FIsHidden, write=FIsHidden, nodefault};
	
public:
	HIDESBASE TdxBreadcrumbEditNode* __fastcall AddChild(void)/* overload */;
	HIDESBASE TdxBreadcrumbEditNode* __fastcall AddChild(const System::UnicodeString AName, System::Uitypes::TImageIndex AImageIndex = (System::Uitypes::TImageIndex)(0xffffffff), void * AData = (void *)(0x0))/* overload */;
	HIDESBASE TdxBreadcrumbEditNode* __fastcall AddChildFirst(void);
	HIDESBASE TdxBreadcrumbEditNode* __fastcall AddNode(TdxBreadcrumbEditNode* ANode, TdxBreadcrumbEditNode* ARelative, void * AData, Dxcustomtree::TdxTreeNodeAttachMode AAttachMode);
	virtual bool __fastcall Compare(const System::UnicodeString AName);
	bool __fastcall FindNode(const System::UnicodeString AName, /* out */ TdxBreadcrumbEditNode* &ANode);
	void __fastcall Sort(void);
	__property TdxBreadcrumbEditNode* First = {read=GetFirst};
	__property TdxBreadcrumbEditNode* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxBreadcrumbEditNode* Last = {read=GetLast};
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property TdxBreadcrumbEditNode* Next = {read=GetNext};
	__property TdxBreadcrumbEditNode* Parent = {read=GetParent};
	__property System::UnicodeString Path = {read=GetPath};
	__property TdxBreadcrumbEditNode* Prev = {read=GetPrev};
	__property TdxBreadcrumbEditNode* Root = {read=GetRoot};
public:
	/* TdxTreeCustomNode.Create */ inline __fastcall virtual TdxBreadcrumbEditNode(Dxcustomtree::_di_IdxTreeOwner AOwner) : Dxcustomtree::TdxTreeCustomNode(AOwner) { }
	/* TdxTreeCustomNode.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditNode(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditViewItem;
class DELPHICLASS TdxBreadcrumbEditPartCustomViewInfo;
class DELPHICLASS TdxBreadcrumbEditHitTestInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditViewItem : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TdxBreadcrumbEditPartCustomViewInfo* FOwner;
	TdxBreadcrumbEditController* __fastcall GetController(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	bool __fastcall GetVisible(void);
	
protected:
	System::Types::TRect FBounds;
	int FHotPartIndex;
	bool FIsHot;
	bool FIsPressed;
	virtual int __fastcall CalculateAutoHeight(void);
	virtual Cxgraphics::TcxBitmap32* __fastcall CreateFadeImage(int AHotPartIndex, bool AIsHot, bool AIsPressed);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	virtual System::UnicodeString __fastcall GetHintText(void);
	virtual bool __fastcall GetIsEnabled(void);
	virtual bool __fastcall GetIsHot(void);
	virtual bool __fastcall GetIsPressed(void);
	virtual Cxlookandfeelpainters::TdxBreadcrumbEditButtonState __fastcall GetState(void);
	virtual bool __fastcall CanFade(void);
	void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	__property TdxBreadcrumbEditPartCustomViewInfo* Owner = {read=FOwner};
	
public:
	__fastcall TdxBreadcrumbEditViewItem(TdxBreadcrumbEditPartCustomViewInfo* AOwner);
	__fastcall virtual ~TdxBreadcrumbEditViewItem(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateHitTest(TdxBreadcrumbEditHitTestInfo* AHitTestInfo);
	virtual void __fastcall Click(int APart = 0x0);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Invalidate(void);
	void __fastcall UpdateStates(TdxBreadcrumbEditHitTestInfo* AHitTestInfo);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TdxBreadcrumbEditController* Controller = {read=GetController};
	__property System::UnicodeString HintText = {read=GetHintText};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property Cxlookandfeelpainters::TdxBreadcrumbEditButtonState State = {read=GetState, nodefault};
	__property bool Visible = {read=GetVisible, nodefault};
private:
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator Dxfading::_di_IdxFadingObject()
	{
		Dxfading::_di_IdxFadingObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObject*(void) { return (Dxfading::IdxFadingObject*)&__IdxFadingObject; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditButtonViewItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditButtonViewItem : public TdxBreadcrumbEditViewItem
{
	typedef TdxBreadcrumbEditViewItem inherited;
	
private:
	TdxBreadcrumbEditButton* FButton;
	System::Types::TSize __fastcall GetImageSize(void);
	bool __fastcall GetIsFirst(void);
	bool __fastcall GetIsLast(void);
	
protected:
	virtual int __fastcall CalculateAutoHeight(void);
	virtual int __fastcall CalculateAutoWidth(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	virtual System::UnicodeString __fastcall GetHintText(void);
	virtual bool __fastcall GetIsEnabled(void);
	
public:
	__fastcall virtual TdxBreadcrumbEditButtonViewItem(TdxBreadcrumbEditPartCustomViewInfo* AOwner, TdxBreadcrumbEditButton* AButton);
	virtual void __fastcall Click(int APart = 0x0);
	__property TdxBreadcrumbEditButton* Button = {read=FButton};
	__property System::Types::TRect ContentOffsets = {read=GetContentOffsets};
	__property System::Types::TSize ImageSize = {read=GetImageSize};
	__property bool IsFirst = {read=GetIsFirst, nodefault};
	__property bool IsLast = {read=GetIsLast, nodefault};
public:
	/* TdxBreadcrumbEditViewItem.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditButtonViewItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditNodeViewItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditNodeViewItem : public TdxBreadcrumbEditViewItem
{
	typedef TdxBreadcrumbEditViewItem inherited;
	
private:
	TdxBreadcrumbEditNode* FNode;
	System::Types::TRect __fastcall GetButtonRect(void);
	int __fastcall GetDelimiterSize(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	int __fastcall GetIndex(void);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	
protected:
	bool FCanHideNode;
	System::Types::TRect FDelimiterRect;
	int FMaxWidth;
	int FMinWidth;
	System::Types::TSize FTextSize;
	int FWidth;
	virtual int __fastcall CalculateAutoHeight(void);
	virtual Cxlookandfeelpainters::TdxBreadcrumbEditButtonState __fastcall GetDelimiterState(void);
	virtual bool __fastcall GetIsPressed(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawDelimiterGlyph(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxBreadcrumbEditNodeViewItem(TdxBreadcrumbEditPartCustomViewInfo* AOwner, TdxBreadcrumbEditNode* ANode);
	virtual void __fastcall BuildDropDownMenu(Cxlistbox::TdxCustomListBoxItems* AItems);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateHitTest(TdxBreadcrumbEditHitTestInfo* AHitTestInfo);
	virtual void __fastcall CalculateSizes(void);
	virtual void __fastcall Click(int APart = 0x0);
	__property System::Types::TRect ButtonRect = {read=GetButtonRect};
	__property bool CanHideNode = {read=FCanHideNode, nodefault};
	__property System::Types::TRect DelimiterRect = {read=FDelimiterRect};
	__property int DelimiterSize = {read=GetDelimiterSize, nodefault};
	__property Cxlookandfeelpainters::TdxBreadcrumbEditButtonState DelimiterState = {read=GetDelimiterState, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property int Index = {read=GetIndex, nodefault};
	__property int MaxWidth = {read=FMaxWidth, nodefault};
	__property int MinWidth = {read=FMinWidth, nodefault};
	__property TdxBreadcrumbEditNode* Node = {read=FNode};
	__property int Width = {read=FWidth, nodefault};
public:
	/* TdxBreadcrumbEditViewItem.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditNodeViewItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditRootNodeViewItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditRootNodeViewItem : public TdxBreadcrumbEditNodeViewItem
{
	typedef TdxBreadcrumbEditNodeViewItem inherited;
	
private:
	bool __fastcall GetIsLastNode(void);
	bool __fastcall GetIsNextNodeHidden(void);
	
protected:
	virtual void __fastcall DrawDelimiterGlyph(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxBreadcrumbEditRootNodeViewItem(TdxBreadcrumbEditPartCustomViewInfo* AOwner, TdxBreadcrumbEditNode* ANode);
	virtual void __fastcall BuildDropDownMenu(Cxlistbox::TdxCustomListBoxItems* AItems);
	virtual void __fastcall CalculateSizes(void);
	__property bool IsLastNode = {read=GetIsLastNode, nodefault};
	__property bool IsNextNodeHidden = {read=GetIsNextNodeHidden, nodefault};
public:
	/* TdxBreadcrumbEditViewItem.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditRootNodeViewItem(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditButton : public Cxedit::TcxCustomEditButton
{
	typedef Cxedit::TcxCustomEditButton inherited;
	
__published:
	__property Action;
	__property Enabled = {default=1};
	__property Glyph;
	__property Hint = {default=0};
	__property ImageIndex = {default=-1};
	__property Tag;
	__property Visible = {default=1};
	__property Width = {default=0};
public:
	/* TcxCustomEditButton.Create */ inline __fastcall virtual TdxBreadcrumbEditButton(System::Classes::TCollection* Collection) : Cxedit::TcxCustomEditButton(Collection) { }
	/* TcxCustomEditButton.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditButton(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditButtons;
class PASCALIMPLEMENTATION TdxBreadcrumbEditButtons : public Cxedit::TcxCustomEditButtons
{
	typedef Cxedit::TcxCustomEditButtons inherited;
	
public:
	TdxBreadcrumbEditButton* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxBreadcrumbEditButton* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxBreadcrumbEditButton* Value);
	
protected:
	__classmethod virtual Cxedit::TcxEditButtonClass __fastcall GetButtonClass();
	
public:
	HIDESBASE TdxBreadcrumbEditButton* __fastcall Add(void);
	__property TdxBreadcrumbEditButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxCustomEditButtons.Create */ inline __fastcall virtual TdxBreadcrumbEditButtons(System::Classes::TPersistent* AOwner, Cxedit::TcxEditButtonClass AButtonClass) : Cxedit::TcxCustomEditButtons(AOwner, AButtonClass) { }
	/* TcxCustomEditButtons.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditButtons(void) { }
	
};


class DELPHICLASS TdxBreadcrumbEditRecentPath;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditRecentPath : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Uitypes::TImageIndex FImageIndex;
	System::UnicodeString FPath;
	
public:
	__fastcall virtual TdxBreadcrumbEditRecentPath(System::Classes::TCollection* Collection);
	
__published:
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=FImageIndex, default=-1};
	__property System::UnicodeString Path = {read=FPath, write=FPath};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditRecentPath(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditRecentPaths;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditRecentPaths : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TdxBreadcrumbEditRecentPath* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxBreadcrumbEditRecentPath* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TdxBreadcrumbEditRecentPath* AValue);
	
public:
	__fastcall TdxBreadcrumbEditRecentPaths(System::Classes::TPersistent* AOwner);
	HIDESBASE TdxBreadcrumbEditRecentPath* __fastcall Add(void)/* overload */;
	HIDESBASE TdxBreadcrumbEditRecentPath* __fastcall Add(const System::UnicodeString APath, System::Uitypes::TImageIndex AImageIndex = (System::Uitypes::TImageIndex)(0xffffffff))/* overload */;
	int __fastcall IndexOfPath(const System::UnicodeString APath);
	__property TdxBreadcrumbEditRecentPath* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditRecentPaths(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditCustomPropertiesPersistent;
class PASCALIMPLEMENTATION TdxBreadcrumbEditCustomPropertiesPersistent : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TdxBreadcrumbEditChangeEvent FOnChange;
	
protected:
	virtual void __fastcall Changed(TdxBreadcrumbEditChanges AChanges);
	
public:
	__property TdxBreadcrumbEditChangeEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TdxBreadcrumbEditCustomPropertiesPersistent(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxOwnedPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditCustomPropertiesPersistent(void) { }
	
};


class DELPHICLASS TdxBreadcrumbEditPathEditorProperties;
class PASCALIMPLEMENTATION TdxBreadcrumbEditPathEditorProperties : public TdxBreadcrumbEditCustomPropertiesPersistent
{
	typedef TdxBreadcrumbEditCustomPropertiesPersistent inherited;
	
private:
	bool FAutoComplete;
	int FAutoCompleteDropDownRows;
	bool FEnabled;
	bool FReadOnly;
	TdxBreadcrumbEditRecentPaths* FRecentPaths;
	bool FRecentPathsAutoPopulate;
	int FRecentPathsDropDownRows;
	void __fastcall SetAutoComplete(bool AValue);
	void __fastcall SetAutoCompleteDropDownRows(int AValue);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetReadOnly(bool AValue);
	void __fastcall SetRecentPaths(TdxBreadcrumbEditRecentPaths* AValue);
	void __fastcall SetRecentPathsAutoPopulate(bool AValue);
	void __fastcall SetRecentPathsDropDownRows(int AValue);
	
public:
	__fastcall virtual TdxBreadcrumbEditPathEditorProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxBreadcrumbEditPathEditorProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AutoComplete = {read=FAutoComplete, write=SetAutoComplete, default=1};
	__property int AutoCompleteDropDownRows = {read=FAutoCompleteDropDownRows, write=SetAutoCompleteDropDownRows, default=16};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property TdxBreadcrumbEditRecentPaths* RecentPaths = {read=FRecentPaths, write=SetRecentPaths};
	__property bool RecentPathsAutoPopulate = {read=FRecentPathsAutoPopulate, write=SetRecentPathsAutoPopulate, default=1};
	__property int RecentPathsDropDownRows = {read=FRecentPathsDropDownRows, write=SetRecentPathsDropDownRows, default=14};
};


enum TdxBreadcrumbEditProgressBarCancelEffect : unsigned char { bpceNone, bpceFillAreaForward, bpceFillAreaBackward };

class DELPHICLASS TdxBreadcrumbEditProgressBarProperties;
class PASCALIMPLEMENTATION TdxBreadcrumbEditProgressBarProperties : public TdxBreadcrumbEditCustomPropertiesPersistent
{
	typedef TdxBreadcrumbEditCustomPropertiesPersistent inherited;
	
private:
	bool FAnimation;
	unsigned FAnimationRestartDelay;
	unsigned FAnimationSpeed;
	TdxBreadcrumbEditProgressBarCancelEffect FCancelEffect;
	int FMaxValue;
	int FMinValue;
	int FPosition;
	void __fastcall SetAnimation(bool AValue);
	void __fastcall SetAnimationRestartDelay(unsigned AValue);
	void __fastcall SetAnimationSpeed(unsigned AValue);
	void __fastcall SetCancelEffect(TdxBreadcrumbEditProgressBarCancelEffect AValue);
	void __fastcall SetMaxValue(int AValue);
	void __fastcall SetMinValue(int AValue);
	void __fastcall SetPosition(int AValue);
	
public:
	__fastcall virtual TdxBreadcrumbEditProgressBarProperties(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Animation = {read=FAnimation, write=SetAnimation, default=1};
	__property unsigned AnimationRestartDelay = {read=FAnimationRestartDelay, write=SetAnimationRestartDelay, default=500};
	__property unsigned AnimationSpeed = {read=FAnimationSpeed, write=SetAnimationSpeed, default=10};
	__property TdxBreadcrumbEditProgressBarCancelEffect CancelEffect = {read=FCancelEffect, write=SetCancelEffect, default=1};
	__property int MaxValue = {read=FMaxValue, write=SetMaxValue, default=100};
	__property int MinValue = {read=FMinValue, write=SetMinValue, default=0};
	__property int Position = {read=FPosition, write=SetPosition, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditProgressBarProperties(void) { }
	
};


class PASCALIMPLEMENTATION TdxCustomBreadcrumbEditProperties : public TdxBreadcrumbEditCustomPropertiesPersistent
{
	typedef TdxBreadcrumbEditCustomPropertiesPersistent inherited;
	
private:
	Cxgraphics::TcxBorders FBorders;
	TdxBreadcrumbEditButtons* FButtons;
	Vcl::Imglist::TCustomImageList* FButtonImages;
	Vcl::Imglist::TChangeLink* FButtonImagesChangeLink;
	int FDropDownRows;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImagesChangeLink;
	TdxBreadcrumbEditPathEditorProperties* FPathEditor;
	TdxBreadcrumbEditProgressBarProperties* FProgressBar;
	void __fastcall ButtonsChanged(System::TObject* Sender);
	void __fastcall ImageListChanged(System::TObject* Sender);
	void __fastcall PropertiesChanged(System::TObject* Sender, TdxBreadcrumbEditChanges AChanges);
	void __fastcall SetBorders(Cxgraphics::TcxBorders AValue);
	void __fastcall SetButtons(TdxBreadcrumbEditButtons* AValue);
	void __fastcall SetButtonImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetDropDownRows(int AValue);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetPathEditor(TdxBreadcrumbEditPathEditorProperties* AValue);
	void __fastcall SetProgressBar(TdxBreadcrumbEditProgressBarProperties* AValue);
	
protected:
	virtual TdxBreadcrumbEditButtons* __fastcall CreateButtons(void);
	virtual TdxBreadcrumbEditPathEditorProperties* __fastcall CreatePathEditorProperties(void);
	virtual TdxBreadcrumbEditProgressBarProperties* __fastcall CreateProgressBarProperties(void);
	virtual void __fastcall InitiateActions(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property Cxgraphics::TcxBorders Borders = {read=FBorders, write=SetBorders, default=15};
	__property TdxBreadcrumbEditButtons* Buttons = {read=FButtons, write=SetButtons};
	__property Vcl::Imglist::TCustomImageList* ButtonImages = {read=FButtonImages, write=SetButtonImages};
	__property int DropDownRows = {read=FDropDownRows, write=SetDropDownRows, default=18};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TdxBreadcrumbEditPathEditorProperties* PathEditor = {read=FPathEditor, write=SetPathEditor};
	__property TdxBreadcrumbEditProgressBarProperties* ProgressBar = {read=FProgressBar, write=SetProgressBar};
	
public:
	__fastcall virtual TdxCustomBreadcrumbEditProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxCustomBreadcrumbEditProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditHitTestInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TPoint Point;
	TdxBreadcrumbEditViewItem* ViewItem;
	int ViewItemPart;
	virtual void __fastcall Reset(void);
public:
	/* TObject.Create */ inline __fastcall TdxBreadcrumbEditHitTestInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditHitTestInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditPartCustomViewInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TdxBreadcrumbEditViewInfo* FOwner;
	_di_IdxBreadcrumbEdit __fastcall GetControl(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	TdxCustomBreadcrumbEditProperties* __fastcall GetProperties(void);
	TdxBreadcrumbEditViewItem* __fastcall GetViewItem(int Index);
	int __fastcall GetViewItemCount(void);
	
protected:
	System::Types::TRect FBounds;
	Cxclasses::TcxObjectList* FViewItemList;
	virtual bool __fastcall IsViewItemValid(TdxBreadcrumbEditViewItem* AItem);
	virtual void __fastcall InternalDraw(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxBreadcrumbEditPartCustomViewInfo(TdxBreadcrumbEditViewInfo* AOwner);
	__fastcall virtual ~TdxBreadcrumbEditPartCustomViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &R) = 0 ;
	virtual int __fastcall CalculateAutoHeight(void);
	virtual void __fastcall CalculateHitTest(TdxBreadcrumbEditHitTestInfo* AInfo);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Invalidate(const System::Types::TRect &R)/* overload */;
	void __fastcall Invalidate(void)/* overload */;
	virtual void __fastcall RecreateViewItems(void);
	virtual void __fastcall UpdateViewItemsState(TdxBreadcrumbEditHitTestInfo* AInfo);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property _di_IdxBreadcrumbEdit Control = {read=GetControl};
	__property TdxBreadcrumbEditViewInfo* Owner = {read=FOwner};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TdxCustomBreadcrumbEditProperties* Properties = {read=GetProperties};
	__property TdxBreadcrumbEditViewItem* ViewItems[int Index] = {read=GetViewItem};
	__property int ViewItemsCount = {read=GetViewItemCount, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditButtonsPartViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditButtonsPartViewInfo : public TdxBreadcrumbEditPartCustomViewInfo
{
	typedef TdxBreadcrumbEditPartCustomViewInfo inherited;
	
protected:
	System::Types::TRect FSeparatorRect;
	virtual TdxBreadcrumbEditButtonViewItem* __fastcall CreateViewItem(TdxBreadcrumbEditButton* AButton);
	virtual void __fastcall InternalDraw(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &R);
	virtual void __fastcall RecreateViewItems(void);
	__property System::Types::TRect SeparatorRect = {read=FSeparatorRect};
public:
	/* TdxBreadcrumbEditPartCustomViewInfo.Create */ inline __fastcall virtual TdxBreadcrumbEditButtonsPartViewInfo(TdxBreadcrumbEditViewInfo* AOwner) : TdxBreadcrumbEditPartCustomViewInfo(AOwner) { }
	/* TdxBreadcrumbEditPartCustomViewInfo.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditButtonsPartViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditDropDownButtonViewItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditDropDownButtonViewItem : public TdxBreadcrumbEditViewItem
{
	typedef TdxBreadcrumbEditViewItem inherited;
	
protected:
	virtual int __fastcall CalculateAutoHeight(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	virtual void __fastcall Click(int APart = 0x0);
public:
	/* TdxBreadcrumbEditViewItem.Create */ inline __fastcall TdxBreadcrumbEditDropDownButtonViewItem(TdxBreadcrumbEditPartCustomViewInfo* AOwner) : TdxBreadcrumbEditViewItem(AOwner) { }
	/* TdxBreadcrumbEditViewItem.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditDropDownButtonViewItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditNodesAreaPartViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditNodesAreaPartViewInfo : public TdxBreadcrumbEditPartCustomViewInfo
{
	typedef TdxBreadcrumbEditPartCustomViewInfo inherited;
	
private:
	TdxBreadcrumbEditViewItem* FDropDownButton;
	int __fastcall GetDropDownButtonWidth(void);
	TdxBreadcrumbEditNodeViewItem* __fastcall GetFirstViewItem(void);
	TdxBreadcrumbEditNodeViewItem* __fastcall GetSelectedNodeViewItem(void);
	HIDESBASE TdxBreadcrumbEditNodeViewItem* __fastcall GetViewItem(int Index);
	
protected:
	System::Types::TRect FImageRect;
	virtual TdxBreadcrumbEditViewItem* __fastcall CreateDropDownButton(void);
	virtual TdxBreadcrumbEditNodeViewItem* __fastcall CreateViewItem(TdxBreadcrumbEditNode* ANode);
	virtual int __fastcall GetDefaultImageHeight(void);
	virtual System::Types::TRect __fastcall GetPathEditorRect(void);
	virtual bool __fastcall IsViewItemValid(TdxBreadcrumbEditViewItem* AItem);
	virtual void __fastcall DrawImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TImageIndex AImageIndex);
	virtual void __fastcall InternalDraw(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxBreadcrumbEditNodesAreaPartViewInfo(TdxBreadcrumbEditViewInfo* AOwner);
	__fastcall virtual ~TdxBreadcrumbEditNodesAreaPartViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &R);
	virtual int __fastcall CalculateAutoHeight(void);
	virtual void __fastcall CalculateDropDownButton(System::Types::TRect &R);
	virtual void __fastcall CalculateHitTest(TdxBreadcrumbEditHitTestInfo* AInfo);
	virtual void __fastcall CalculateImageRect(System::Types::TRect &R);
	virtual void __fastcall CalculateNodesBounds(const System::Types::TRect &R);
	virtual void __fastcall CalculateNodesWidths(int AContentWidth);
	bool __fastcall FindViewItem(TdxBreadcrumbEditNode* ANode, /* out */ TdxBreadcrumbEditNodeViewItem* &AViewItem);
	virtual void __fastcall RecreateViewItems(void);
	virtual void __fastcall UpdateViewItemsState(TdxBreadcrumbEditHitTestInfo* AInfo);
	__property TdxBreadcrumbEditViewItem* DropDownButton = {read=FDropDownButton};
	__property TdxBreadcrumbEditNodeViewItem* FirstViewItem = {read=GetFirstViewItem};
	__property System::Types::TRect ImageRect = {read=FImageRect};
	__property System::Types::TRect PathEditorRect = {read=GetPathEditorRect};
	__property TdxBreadcrumbEditNodeViewItem* SelectedNodeViewItem = {read=GetSelectedNodeViewItem};
	__property TdxBreadcrumbEditNodeViewItem* ViewItems[int Index] = {read=GetViewItem};
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditProgressBarPartViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditProgressBarPartViewInfo : public TdxBreadcrumbEditPartCustomViewInfo
{
	typedef TdxBreadcrumbEditPartCustomViewInfo inherited;
	
private:
	System::Byte FOpacity;
	int FOverlayPosition;
	System::Types::TSize FOverlaySize;
	float FProgress;
	System::Types::TRect __fastcall GetChunkRect(void);
	System::Types::TRect __fastcall GetOverlayRect(void);
	void __fastcall SetProgress(float AValue);
	
protected:
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall InternalDraw(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Byte Opacity = {read=FOpacity, write=FOpacity, nodefault};
	__property float Progress = {read=FProgress, write=SetProgress};
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &R);
	void __fastcall ResetOverlayPosition(void);
	__property System::Types::TRect ChunkRect = {read=GetChunkRect};
	__property int OverlayPosition = {read=FOverlayPosition, write=FOverlayPosition, nodefault};
	__property System::Types::TRect OverlayRect = {read=GetOverlayRect};
	__property System::Types::TSize OverlaySize = {read=FOverlaySize};
public:
	/* TdxBreadcrumbEditPartCustomViewInfo.Create */ inline __fastcall virtual TdxBreadcrumbEditProgressBarPartViewInfo(TdxBreadcrumbEditViewInfo* AOwner) : TdxBreadcrumbEditPartCustomViewInfo(AOwner) { }
	/* TdxBreadcrumbEditPartCustomViewInfo.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditProgressBarPartViewInfo(void) { }
	
};

#pragma pack(pop)

enum TdxBreadcrumbEditProgressBarFadingState : unsigned char { bcpfsNone, bcpfsFadeIn, bcpfsFadeOut };

class DELPHICLASS TdxBreadcrumbEditProgressBarController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditProgressBarController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxTimer* FCancelEffectAnimationTimer;
	TdxBreadcrumbEditController* FController;
	TdxBreadcrumbEditProgressBarFadingState FFadingState;
	Cxclasses::TcxTimer* FFadingTimer;
	Cxclasses::TcxTimer* FOverlayAnimationTimer;
	float FProgress;
	bool __fastcall GetCancelEffectAnimationActive(void);
	System::Byte __fastcall GetFadingStageAlpha(void);
	bool __fastcall GetIsOverlayAnimationEnabled(void);
	int __fastcall GetOverlayAnimationOffset(void);
	unsigned __fastcall GetOverlayAnimationTimerInterval(void);
	TdxBreadcrumbEditProgressBarProperties* __fastcall GetProperties(void);
	TdxBreadcrumbEditProgressBarPartViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetProgress(float AValue);
	
protected:
	int FFadingFrameIndex;
	int FFadingFramesCount;
	int FOverlayAnimationRestartDelayCount;
	void __fastcall Fade(int AFramesCount, bool AFadeOut);
	void __fastcall FadeIn(void);
	void __fastcall FadeOut(void);
	virtual void __fastcall ProcessCancelEffectAnimationStep(System::TObject* Sender);
	virtual void __fastcall ProcessFadeStep(System::TObject* Sender);
	virtual void __fastcall ProcessOverlayAnimationStep(System::TObject* Sender);
	void __fastcall StartCancelEffectAnimation(void);
	void __fastcall StartOverlayAnimation(void);
	void __fastcall StopCancelEffectAnimation(void);
	void __fastcall StopFading(void);
	void __fastcall StopOverlayAnimation(void);
	__property bool CancelEffectAnimationActive = {read=GetCancelEffectAnimationActive, nodefault};
	__property Cxclasses::TcxTimer* CancelEffectAnimationTimer = {read=FCancelEffectAnimationTimer};
	__property System::Byte FadingStageAlpha = {read=GetFadingStageAlpha, nodefault};
	__property TdxBreadcrumbEditProgressBarFadingState FadingState = {read=FFadingState, nodefault};
	__property Cxclasses::TcxTimer* FadingTimer = {read=FFadingTimer};
	__property bool OverlayAnimationEnabled = {read=GetIsOverlayAnimationEnabled, nodefault};
	__property int OverlayAnimationOffset = {read=GetOverlayAnimationOffset, nodefault};
	__property Cxclasses::TcxTimer* OverlayAnimationTimer = {read=FOverlayAnimationTimer};
	__property unsigned OverlayAnimationTimerInterval = {read=GetOverlayAnimationTimerInterval, nodefault};
	__property float Progress = {read=FProgress, write=SetProgress};
	
public:
	__fastcall virtual TdxBreadcrumbEditProgressBarController(TdxBreadcrumbEditController* AController);
	__fastcall virtual ~TdxBreadcrumbEditProgressBarController(void);
	virtual void __fastcall UpdateOverlayAnimationState(void);
	virtual void __fastcall UpdateProgress(void);
	__property TdxBreadcrumbEditController* Controller = {read=FController};
	__property TdxBreadcrumbEditProgressBarProperties* Properties = {read=GetProperties};
	__property TdxBreadcrumbEditProgressBarPartViewInfo* ViewInfo = {read=GetViewInfo};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxBreadcrumbEditButtonsPartViewInfo* FButtonsViewInfo;
	_di_IdxBreadcrumbEdit FControl;
	TdxBreadcrumbEditHitTestInfo* FHitTestInfo;
	TdxBreadcrumbEditNodesAreaPartViewInfo* FNodesAreaViewInfo;
	TdxBreadcrumbEditProgressBarPartViewInfo* FProgressBarViewInfo;
	Cxlookandfeelpainters::TdxBreadcrumbEditState FState;
	System::Types::TRect __fastcall GetBordersWidth(void);
	System::Types::TRect __fastcall GetContentRect(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	TdxCustomBreadcrumbEditProperties* __fastcall GetProperties(void);
	void __fastcall SetState(Cxlookandfeelpainters::TdxBreadcrumbEditState AState);
	
protected:
	System::Types::TRect FBounds;
	virtual TdxBreadcrumbEditButtonsPartViewInfo* __fastcall CreateButtonsViewInfo(void);
	virtual TdxBreadcrumbEditHitTestInfo* __fastcall CreateHitTestInfo(void);
	virtual TdxBreadcrumbEditNodesAreaPartViewInfo* __fastcall CreateNodesAreaViewInfo(void);
	virtual TdxBreadcrumbEditProgressBarPartViewInfo* __fastcall CreateProgressBarViewInfo(void);
	virtual bool __fastcall IsViewItemValid(TdxBreadcrumbEditViewItem* AItem);
	virtual void __fastcall DoCalculateHitTest(TdxBreadcrumbEditHitTestInfo* AInfo);
	
public:
	__fastcall virtual TdxBreadcrumbEditViewInfo(const _di_IdxBreadcrumbEdit AControl);
	__fastcall virtual ~TdxBreadcrumbEditViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &R);
	virtual int __fastcall CalculateAutoHeight(void);
	void __fastcall CalculateHitTest(const System::Types::TPoint &P)/* overload */;
	void __fastcall CalculateHitTest(int X, int Y)/* overload */;
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall GetNavigationOrder(System::Classes::TList* AList);
	void __fastcall Invalidate(const System::Types::TRect &R)/* overload */;
	void __fastcall Invalidate(void)/* overload */;
	virtual void __fastcall UpdateViewItemStates(void);
	__property System::Types::TRect BordersWidth = {read=GetBordersWidth};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TdxBreadcrumbEditButtonsPartViewInfo* ButtonsViewInfo = {read=FButtonsViewInfo};
	__property System::Types::TRect ContentRect = {read=GetContentRect};
	__property _di_IdxBreadcrumbEdit Control = {read=FControl};
	__property TdxBreadcrumbEditHitTestInfo* HitTestInfo = {read=FHitTestInfo};
	__property TdxBreadcrumbEditNodesAreaPartViewInfo* NodesAreaViewInfo = {read=FNodesAreaViewInfo};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TdxBreadcrumbEditProgressBarPartViewInfo* ProgressBarViewInfo = {read=FProgressBarViewInfo};
	__property TdxCustomBreadcrumbEditProperties* Properties = {read=GetProperties};
	__property Cxlookandfeelpainters::TdxBreadcrumbEditState State = {read=FState, write=SetState, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditNodeDropDownMenu;
class PASCALIMPLEMENTATION TdxBreadcrumbEditNodeDropDownMenu : public Cxlistbox::TdxCustomDropDownListBox
{
	typedef Cxlistbox::TdxCustomDropDownListBox inherited;
	
private:
	TdxBreadcrumbEditController* FController;
	
protected:
	virtual void __fastcall DoCloseUp(bool AClosedViaKeyboard);
	virtual void __fastcall DoSelectItem(Cxlistbox::TdxCustomListBoxItem* AItem, bool ASelectedViaKeyboard);
	virtual void __fastcall InitInnerListBox(void);
	virtual void __fastcall InitPopup(void);
	__property TdxBreadcrumbEditController* Controller = {read=FController};
	
public:
	__fastcall virtual TdxBreadcrumbEditNodeDropDownMenu(TdxBreadcrumbEditController* AController);
	virtual void __fastcall Popup(void);
public:
	/* TdxCustomDropDownListBox.CreateEx */ inline __fastcall TdxBreadcrumbEditNodeDropDownMenu(Vcl::Controls::TWinControl* AOwnerControl, Cxcontrols::TcxControl* AOwnerParent) : Cxlistbox::TdxCustomDropDownListBox(AOwnerControl, AOwnerParent) { }
	/* TdxCustomDropDownListBox.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditNodeDropDownMenu(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBreadcrumbEditNodeDropDownMenu(System::Classes::TComponent* AOwner, int Dummy) : Cxlistbox::TdxCustomDropDownListBox(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBreadcrumbEditNodeDropDownMenu(HWND ParentWindow) : Cxlistbox::TdxCustomDropDownListBox(ParentWindow) { }
	
};


class DELPHICLASS TdxBreadcrumbEditAutoCompleteInnerListBoxSizeGrip;
class PASCALIMPLEMENTATION TdxBreadcrumbEditAutoCompleteInnerListBoxSizeGrip : public Cxcontrols::TcxSizeGrip
{
	typedef Cxcontrols::TcxSizeGrip inherited;
	
protected:
	virtual void __fastcall Paint(void);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
public:
	/* TcxSizeGrip.Create */ inline __fastcall virtual TdxBreadcrumbEditAutoCompleteInnerListBoxSizeGrip(System::Classes::TComponent* AOwner) : Cxcontrols::TcxSizeGrip(AOwner) { }
	/* TcxSizeGrip.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditAutoCompleteInnerListBoxSizeGrip(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBreadcrumbEditAutoCompleteInnerListBoxSizeGrip(HWND ParentWindow) : Cxcontrols::TcxSizeGrip(ParentWindow) { }
	
};


class DELPHICLASS TdxBreadcrumbEditAutoCompleteInnerListBox;
class PASCALIMPLEMENTATION TdxBreadcrumbEditAutoCompleteInnerListBox : public Cxlistbox::TdxCustomListBox
{
	typedef Cxlistbox::TdxCustomListBox inherited;
	
private:
	System::Classes::TNotifyEvent FOnSelectItem;
	System::Types::TPoint FPrevMouseCursor;
	void __fastcall DoSelectItem(void);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall DoLayoutChanged(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall ProcessNavigationKey(System::Word &Key, System::Classes::TShiftState Shift);
	virtual System::Types::TRect __fastcall GetSizeGripBounds(void);
	virtual Cxcontrols::TcxSizeGripClass __fastcall GetSizeGripClass(void);
	virtual System::Types::TRect __fastcall GetVScrollBarBounds(void);
	virtual bool __fastcall IsSizeGripVisible(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	
public:
	bool __fastcall PointInSizeGrip(const System::Types::TPoint &P);
	__property System::Classes::TNotifyEvent OnSelectItem = {read=FOnSelectItem, write=FOnSelectItem};
public:
	/* TdxCustomListBox.Create */ inline __fastcall virtual TdxBreadcrumbEditAutoCompleteInnerListBox(System::Classes::TComponent* AOwner) : Cxlistbox::TdxCustomListBox(AOwner) { }
	/* TdxCustomListBox.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditAutoCompleteInnerListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBreadcrumbEditAutoCompleteInnerListBox(HWND ParentWindow) : Cxlistbox::TdxCustomListBox(ParentWindow) { }
	
};


class DELPHICLASS TdxBreadcrumbEditAutoCompleteWindow;
class DELPHICLASS TdxBreadcrumbEditPathEditor;
class PASCALIMPLEMENTATION TdxBreadcrumbEditAutoCompleteWindow : public Cxcontainer::TcxCustomPopupWindow
{
	typedef Cxcontainer::TcxCustomPopupWindow inherited;
	
private:
	int FDisplayRowsCount;
	TdxBreadcrumbEditAutoCompleteInnerListBox* FInnerListBox;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TdxBreadcrumbEditPathEditor* FOwnerEditor;
	System::UnicodeString FPreviouslyEnteredText;
	System::UnicodeString __fastcall GetSelectedPath(void);
	void __fastcall SelectItemHandler(System::TObject* Sender);
	void __fastcall SetSelectedPath(const System::UnicodeString AValue);
	MESSAGE void __fastcall WMExitSizeMove(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual void __fastcall CalculateConstaints(void);
	virtual void __fastcall CalculateSize(void);
	virtual TdxBreadcrumbEditAutoCompleteInnerListBox* __fastcall CreateInnerListBox(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DoClosed(void);
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall Paint(void);
	void __fastcall ProcessNavigationKey(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall SynchronizeSuggestions(void);
	__property TdxBreadcrumbEditAutoCompleteInnerListBox* InnerListBox = {read=FInnerListBox};
	__property TdxBreadcrumbEditPathEditor* OwnerEditor = {read=FOwnerEditor};
	__property System::UnicodeString PreviouslyEnteredText = {read=FPreviouslyEnteredText};
	
public:
	__fastcall virtual TdxBreadcrumbEditAutoCompleteWindow(Vcl::Controls::TWinControl* AOwnerControl);
	__fastcall virtual ~TdxBreadcrumbEditAutoCompleteWindow(void);
	virtual void __fastcall Popup(Vcl::Controls::TWinControl* AFocusedControl);
	void __fastcall SetSize(int AWidth, int AHeight)/* overload */;
	void __fastcall SetSize(const System::Types::TSize &ASize)/* overload */;
	__property int DisplayRowsCount = {read=FDisplayRowsCount, write=FDisplayRowsCount, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel};
	__property System::UnicodeString SelectedPath = {read=GetSelectedPath, write=SetSelectedPath};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBreadcrumbEditAutoCompleteWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxcontainer::TcxCustomPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBreadcrumbEditAutoCompleteWindow(HWND ParentWindow) : Cxcontainer::TcxCustomPopupWindow(ParentWindow) { }
	
};


class DELPHICLASS TdxBreadcrumbEditPathInplaceEditorProperties;
class PASCALIMPLEMENTATION TdxBreadcrumbEditPathInplaceEditorProperties : public Cxdropdownedit::TcxCustomComboBoxProperties
{
	typedef Cxdropdownedit::TcxCustomComboBoxProperties inherited;
	
private:
	bool FAutoComplete;
	int FAutoCompleteDropDownRows;
	System::Uitypes::TImageIndex FImageIndex;
	void __fastcall SetAutoComplete(bool AValue);
	void __fastcall SetAutoCompleteDropDownRows(int AValue);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex AValue);
	
protected:
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall CanValidate(void);
	
public:
	__fastcall virtual TdxBreadcrumbEditPathInplaceEditorProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	__property bool AutoComplete = {read=FAutoComplete, write=SetAutoComplete, default=1};
	__property int AutoCompleteDropDownRows = {read=FAutoCompleteDropDownRows, write=SetAutoCompleteDropDownRows, default=16};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditPathInplaceEditorProperties(void) { }
	
};


class DELPHICLASS TdxBreadcrumbEditPathEditorListBox;
class PASCALIMPLEMENTATION TdxBreadcrumbEditPathEditorListBox : public Cxdropdownedit::TcxComboBoxListBox
{
	typedef Cxdropdownedit::TcxComboBoxListBox inherited;
	
private:
	System::Uitypes::TImageIndex __fastcall GetImageIndex(int AItemIndex);
	System::Types::TRect __fastcall GetImageRect(const System::Types::TRect &R);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	TdxBreadcrumbEditPathInplaceEditorProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall DrawItem(int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	__property System::Uitypes::TImageIndex ImageIndex[int AItemIndex] = {read=GetImageIndex};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	__property TdxBreadcrumbEditPathInplaceEditorProperties* Properties = {read=GetProperties};
	
public:
	virtual int __fastcall GetItemHeight(int AIndex = 0xffffffff);
public:
	/* TcxCustomComboBoxListBox.Create */ inline __fastcall virtual TdxBreadcrumbEditPathEditorListBox(System::Classes::TComponent* AOwner) : Cxdropdownedit::TcxComboBoxListBox(AOwner) { }
	
public:
	/* TcxCustomInnerListBox.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditPathEditorListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBreadcrumbEditPathEditorListBox(HWND ParentWindow) : Cxdropdownedit::TcxComboBoxListBox(ParentWindow) { }
	
};


class DELPHICLASS TdxBreadcrumbEditPathEditorDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditPathEditorDataBinding : public Cxedit::TcxEditDataBinding
{
	typedef Cxedit::TcxEditDataBinding inherited;
	
public:
	virtual bool __fastcall CanPostEditorValue(void);
public:
	/* TcxEditDataBinding.Create */ inline __fastcall virtual TdxBreadcrumbEditPathEditorDataBinding(Cxedit::TcxCustomEdit* AEdit) : Cxedit::TcxEditDataBinding(AEdit) { }
	/* TcxEditDataBinding.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditPathEditorDataBinding(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBreadcrumbEditPathEditorLookupData;
class PASCALIMPLEMENTATION TdxBreadcrumbEditPathEditorLookupData : public Cxdropdownedit::TcxComboBoxLookupData
{
	typedef Cxdropdownedit::TcxComboBoxLookupData inherited;
	
private:
	System::UnicodeString __fastcall GetCurrentValue(void);
	
protected:
	virtual Cxtextedit::TcxCustomEditListBoxClass __fastcall GetListBoxClass(void);
	
public:
	__property System::UnicodeString CurrentValue = {read=GetCurrentValue};
public:
	/* TcxCustomTextEditLookupData.Create */ inline __fastcall virtual TdxBreadcrumbEditPathEditorLookupData(System::Classes::TPersistent* AOwner) : Cxdropdownedit::TcxComboBoxLookupData(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditPathEditorLookupData(void) { }
	
};


class DELPHICLASS TdxBreadcrumbEditPathEditorViewInfo;
class PASCALIMPLEMENTATION TdxBreadcrumbEditPathEditorViewInfo : public Cxdropdownedit::TcxCustomComboBoxViewInfo
{
	typedef Cxdropdownedit::TcxCustomComboBoxViewInfo inherited;
	
protected:
	virtual void __fastcall DrawEditButton(Cxgraphics::TcxCanvas* ACanvas, int AButtonVisibleIndex);
	virtual void __fastcall GetColorSettingsByPainter(/* out */ System::Uitypes::TColor &ABackgroundColor, /* out */ System::Uitypes::TColor &ATextColor);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	System::Uitypes::TImageIndex ImageIndex;
	System::Types::TRect ImageRect;
	Vcl::Imglist::TCustomImageList* Images;
	virtual void __fastcall Offset(int DX, int DY);
public:
	/* TcxCustomComboBoxViewInfo.Create */ inline __fastcall virtual TdxBreadcrumbEditPathEditorViewInfo(void) : Cxdropdownedit::TcxCustomComboBoxViewInfo() { }
	
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditPathEditorViewInfo(void) { }
	
};


class DELPHICLASS TdxBreadcrumbEditPathEditorViewData;
class PASCALIMPLEMENTATION TdxBreadcrumbEditPathEditorViewData : public Cxdropdownedit::TcxCustomComboBoxViewData
{
	typedef Cxdropdownedit::TcxCustomComboBoxViewData inherited;
	
private:
	HIDESBASE TdxBreadcrumbEditPathInplaceEditorProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall CalculateButtonNativeInfo(Cxedit::TcxEditButtonViewInfo* AButtonViewInfo);
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* ViewInfo, bool AIsMouseEvent);
	__property TdxBreadcrumbEditPathInplaceEditorProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TdxBreadcrumbEditPathEditorViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxdropdownedit::TcxCustomComboBoxViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditPathEditorViewData(void) { }
	
};


typedef void __fastcall (__closure *TdxBreadcrumbEditPopulateAutoCompleteSuggestionsEvent)(System::TObject* Sender, const System::UnicodeString APath, System::Classes::TStringList* ASuggestions);

class PASCALIMPLEMENTATION TdxBreadcrumbEditPathEditor : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	System::Classes::TStringList* FAutoCompleteSuggestions;
	int FAutoCompleteSuggestionsUpdateLockCount;
	TdxBreadcrumbEditAutoCompleteWindow* FAutoCompleteWindow;
	System::Types::TSize FAutoCompleteWindowCustomizedSize;
	TdxBreadcrumbEditPopulateAutoCompleteSuggestionsEvent FOnPopulateAutoCompleteSuggestions;
	HIDESBASE TdxBreadcrumbEditPathInplaceEditorProperties* __fastcall GetActiveProperties(void);
	bool __fastcall GetIsAutoCompleteWindowCustomizedSizeAssigned(void);
	HIDESBASE TdxBreadcrumbEditPathEditorLookupData* __fastcall GetLookupData(void);
	HIDESBASE TdxBreadcrumbEditPathInplaceEditorProperties* __fastcall GetProperties(void);
	void __fastcall DoAutoCompleteSuggestionsChanged(System::TObject* Sender);
	void __fastcall DoGetDefaultButtonWidthEvent(Cxedit::TcxCustomEditViewData* Sender, int AIndex, int &ADefaultWidth);
	void __fastcall SetAutoCompleteSuggestions(System::Classes::TStringList* AValue);
	
protected:
	virtual bool __fastcall CanShowValidationErrorOnPostEditValue(void);
	virtual TdxBreadcrumbEditAutoCompleteWindow* __fastcall CreateAutoCompleteWindow(void);
	virtual Cxedit::TcxCustomEditViewData* __fastcall CreateViewData(void);
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	virtual bool __fastcall GetScrollLookupDataList(Cxtextedit::TcxEditScrollCause AScrollCause);
	virtual void __fastcall DoChange(void);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoPopulateAutoCompleteSuggestions(void);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	void __fastcall HideAutoCompleteWindow(void);
	void __fastcall PreviewEditValue(const System::UnicodeString AEditValue, bool ASelectAll);
	virtual void __fastcall RefreshAutoCompleteSuggestions(void);
	void __fastcall RefreshAutoCompleteWindow(void);
	virtual void __fastcall SetEditValue(const System::Variant &AValue);
	virtual void __fastcall StoreAutoCompleteWindowCustomizedSize(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property TdxBreadcrumbEditAutoCompleteWindow* AutoCompleteWindow = {read=FAutoCompleteWindow};
	__property System::Types::TSize AutoCompleteWindowCustomizedSize = {read=FAutoCompleteWindowCustomizedSize};
	__property bool AutoCompleteWindowCustomizedSizeAssigned = {read=GetIsAutoCompleteWindowCustomizedSizeAssigned, nodefault};
	
public:
	__fastcall virtual TdxBreadcrumbEditPathEditor(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TdxBreadcrumbEditPathEditor(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	void __fastcall SetFocusToParent(void);
	__property TdxBreadcrumbEditPathInplaceEditorProperties* ActiveProperties = {read=GetActiveProperties};
	__property System::Classes::TStringList* AutoCompleteSuggestions = {read=FAutoCompleteSuggestions, write=SetAutoCompleteSuggestions};
	__property TdxBreadcrumbEditPathEditorLookupData* LookupData = {read=GetLookupData};
	__property TdxBreadcrumbEditPathInplaceEditorProperties* Properties = {read=GetProperties};
	__property TdxBreadcrumbEditPopulateAutoCompleteSuggestionsEvent OnPopulateAutoCompleteSuggestions = {read=FOnPopulateAutoCompleteSuggestions, write=FOnPopulateAutoCompleteSuggestions};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxBreadcrumbEditPathEditor(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBreadcrumbEditPathEditor(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TdxBreadcrumbEditPathEditingController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditPathEditingController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxBreadcrumbEditController* FController;
	TdxBreadcrumbEditPathEditor* FPathEditor;
	_di_IdxBreadcrumbEdit __fastcall GetControl(void);
	bool __fastcall GetIsFocused(void);
	TdxBreadcrumbEditPathEditorProperties* __fastcall GetProperties(void);
	TdxBreadcrumbEditNode* __fastcall GetSelected(void);
	TdxBreadcrumbEditViewInfo* __fastcall GetViewInfo(void);
	void __fastcall PathEditorEnterHandler(System::TObject* Sender);
	void __fastcall PathEditorExitHandler(System::TObject* Sender);
	void __fastcall PathEditorPopulateAutoCompleteSuggestions(System::TObject* Sender, const System::UnicodeString APath, System::Classes::TStringList* ASuggestions);
	void __fastcall PathEditorPostEditValueHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall AddToRecentPaths(TdxBreadcrumbEditNode* ANode);
	virtual bool __fastcall DoPathEntered(System::UnicodeString &ANewPath);
	virtual void __fastcall PopulateRecentPaths(System::Classes::TStrings* AItems);
	virtual void __fastcall SetupPathEditorProperties(void);
	virtual void __fastcall SetupPathEditorStyles(void);
	void __fastcall AddSuggestion(const System::UnicodeString ACurrentPath, const System::UnicodeString ASuggestedPath, System::Classes::TStringList* ASuggestions);
	virtual bool __fastcall CanAddNodeToSuggestions(const System::UnicodeString ACurrentPath, TdxBreadcrumbEditNode* ANode);
	virtual bool __fastcall IsSubPath(const System::UnicodeString ABasePath, const System::UnicodeString APathForCheck);
	virtual void __fastcall PopulateCustomSuggestions(const System::UnicodeString APath, System::Classes::TStringList* ASuggestions);
	virtual void __fastcall PopulateSuggestions(const System::UnicodeString APath, System::Classes::TStringList* ASuggestions);
	
public:
	__fastcall virtual TdxBreadcrumbEditPathEditingController(TdxBreadcrumbEditController* AController);
	__fastcall virtual ~TdxBreadcrumbEditPathEditingController(void);
	void __fastcall ClosePathEditor(void);
	void __fastcall DropDown(void);
	void __fastcall OpenPathEditor(void);
	void __fastcall ReleasePathEditor(void);
	void __fastcall UpdatePathEditorBounds(void);
	__property _di_IdxBreadcrumbEdit Control = {read=GetControl};
	__property TdxBreadcrumbEditController* Controller = {read=FController};
	__property bool IsFocused = {read=GetIsFocused, nodefault};
	__property TdxBreadcrumbEditPathEditor* PathEditor = {read=FPathEditor};
	__property TdxBreadcrumbEditPathEditorProperties* Properties = {read=GetProperties};
	__property TdxBreadcrumbEditNode* Selected = {read=GetSelected};
	__property TdxBreadcrumbEditViewInfo* ViewInfo = {read=GetViewInfo};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBreadcrumbEditController : public Cxcontrols::TcxMessageWindow
{
	typedef Cxcontrols::TcxMessageWindow inherited;
	
private:
	bool FDestroying;
	TdxBreadcrumbEditNodeViewItem* FDropDownMenuOwner;
	TdxBreadcrumbEditNodeDropDownMenu* FDropDownMenuWindow;
	TdxBreadcrumbEditViewItem* FFocusedViewItem;
	bool FLockDropDownMenuWindowDestroying;
	bool FMouseInControl;
	TdxBreadcrumbEditPathEditingController* FPathEditingController;
	TdxBreadcrumbEditViewItem* FPressedViewItem;
	System::Types::TPoint FPrevMousePosition;
	TdxBreadcrumbEditProgressBarController* FProgressBarController;
	TdxBreadcrumbEditNode* FSelected;
	int FUpdateLockCount;
	TdxBreadcrumbEditViewInfo* FViewInfo;
	bool __fastcall CanClickAt(TdxBreadcrumbEditViewItem* AViewItem);
	_di_IdxBreadcrumbEdit __fastcall GetControl(void);
	Vcl::Controls::TWinControl* __fastcall GetControlContainer(void);
	TdxBreadcrumbEditHitTestInfo* __fastcall GetHitTestInfo(void);
	bool __fastcall GetIsFocused(void);
	bool __fastcall GetIsUpdateLocked(void);
	TdxBreadcrumbEditNode* __fastcall GetRoot(void);
	TdxBreadcrumbEditNodeViewItem* __fastcall GetSelectedNodeViewItem(void);
	System::UnicodeString __fastcall GetSelectedPath(void);
	void __fastcall SetDropDownMenuOwner(TdxBreadcrumbEditNodeViewItem* AValue);
	void __fastcall SetFocusedViewItem(TdxBreadcrumbEditViewItem* AValue);
	void __fastcall SetMouseInControl(bool AValue);
	void __fastcall SetPressedViewItem(TdxBreadcrumbEditViewItem* AValue);
	void __fastcall SetSelected(TdxBreadcrumbEditNode* AValue);
	
protected:
	TdxBreadcrumbEditChanges FChanges;
	virtual Cxlookandfeelpainters::TdxBreadcrumbEditState __fastcall CalculateState(void);
	virtual bool __fastcall CanOpenPathEditorOnEnter(void);
	virtual bool __fastcall CanSelectNode(TdxBreadcrumbEditNode* ANode);
	virtual TdxBreadcrumbEditNodeDropDownMenu* __fastcall CreateDropDownMenuWindow(void);
	virtual TdxBreadcrumbEditPathEditingController* __fastcall CreatePathEditingController(void);
	virtual TdxBreadcrumbEditProgressBarController* __fastcall CreateProgressBarController(void);
	virtual TdxBreadcrumbEditViewItem* __fastcall FindNextSelectableViewItem(TdxBreadcrumbEditViewItem* AItem);
	virtual TdxBreadcrumbEditViewItem* __fastcall FindPrevSelectableViewItem(TdxBreadcrumbEditViewItem* AItem);
	bool __fastcall FindRootNodeForPath(System::UnicodeString &APath, /* out */ TdxBreadcrumbEditNode* &ANode);
	virtual TdxBreadcrumbEditViewItem* __fastcall FindSelectableViewItem(TdxBreadcrumbEditViewItem* AItem, bool AGoForward);
	bool __fastcall ParsePath(System::UnicodeString &ANodeName, System::UnicodeString &ASubPath);
	virtual void __fastcall DoDeleteNode(TdxBreadcrumbEditNode* ANode);
	virtual void __fastcall ProcessChanges(const TdxBreadcrumbEditChanges AChanges);
	virtual void __fastcall SelectionChanged(void);
	void __fastcall ValidateItem(TdxBreadcrumbEditViewItem* &AItem);
	virtual void __fastcall ValidateItems(void);
	virtual void __fastcall ValidatePath(const System::UnicodeString APath, TdxBreadcrumbEditNode* &ANode);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall DoAfterSelect(void);
	virtual void __fastcall DoBeforeSelect(void);
	virtual void __fastcall DoNodeDropDownPopup(TdxBreadcrumbEditNode* ANode);
	virtual bool __fastcall DoSelectPath(const System::UnicodeString APath, TdxBreadcrumbEditNode* ANode);
	virtual void __fastcall DoValidatePath(const System::UnicodeString APath, TdxBreadcrumbEditNode* &ANode, System::UnicodeString &AErrorText, bool &AError);
	__property bool Destroying = {read=FDestroying, nodefault};
	__property TdxBreadcrumbEditNodeViewItem* DropDownMenuOwner = {read=FDropDownMenuOwner, write=SetDropDownMenuOwner};
	__property TdxBreadcrumbEditNodeDropDownMenu* DropDownMenuWindow = {read=FDropDownMenuWindow};
	__property TdxBreadcrumbEditViewItem* FocusedViewItem = {read=FFocusedViewItem, write=SetFocusedViewItem};
	__property bool IsUpdateLocked = {read=GetIsUpdateLocked, nodefault};
	__property bool MouseInControl = {read=FMouseInControl, write=SetMouseInControl, nodefault};
	__property TdxBreadcrumbEditViewItem* PressedViewItem = {read=FPressedViewItem, write=SetPressedViewItem};
	__property TdxBreadcrumbEditProgressBarController* ProgressBarController = {read=FProgressBarController};
	__property TdxBreadcrumbEditNode* Root = {read=GetRoot};
	__property TdxBreadcrumbEditNodeViewItem* SelectedNodeViewItem = {read=GetSelectedNodeViewItem};
	
public:
	__fastcall virtual TdxBreadcrumbEditController(TdxBreadcrumbEditViewInfo* AViewInfo);
	__fastcall virtual ~TdxBreadcrumbEditController(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual TdxBreadcrumbEditNode* __fastcall FindNodeByPath(System::UnicodeString APath);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall BoundsChanged(const System::Types::TRect &ARect);
	void __fastcall Changed(const TdxBreadcrumbEditChanges AChanges);
	virtual void __fastcall FocusChanged(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton AButton, const System::Types::TPoint &P, System::Classes::TShiftState AShift);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(const System::Types::TPoint &P, System::Classes::TShiftState AShift);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton AButton, const System::Types::TPoint &P, System::Classes::TShiftState AShift);
	virtual void __fastcall ProcessButtonClick(TdxBreadcrumbEditButton* AButton);
	void __fastcall UpdateHitTest(void);
	void __fastcall UpdateState(void);
	bool __fastcall SelectPath(TdxBreadcrumbEditNode* ANode)/* overload */;
	bool __fastcall SelectPath(const System::UnicodeString APath)/* overload */;
	void __fastcall SelectPathViaDropDownMenu(TdxBreadcrumbEditNode* AItem);
	virtual bool __fastcall IsNodeDropDownMenuWindowActive(void);
	void __fastcall HideNodeDropDownMenu(void);
	virtual void __fastcall ShowNodeDropDownMenu(TdxBreadcrumbEditNodeViewItem* ANodeViewItem);
	__property _di_IdxBreadcrumbEdit Control = {read=GetControl};
	__property Vcl::Controls::TWinControl* ControlContainer = {read=GetControlContainer};
	__property TdxBreadcrumbEditHitTestInfo* HitTestInfo = {read=GetHitTestInfo};
	__property bool IsFocused = {read=GetIsFocused, nodefault};
	__property TdxBreadcrumbEditPathEditingController* PathEditingController = {read=FPathEditingController};
	__property TdxBreadcrumbEditNode* Selected = {read=FSelected, write=SetSelected};
	__property System::UnicodeString SelectedPath = {read=GetSelectedPath};
	__property TdxBreadcrumbEditViewInfo* ViewInfo = {read=FViewInfo};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxBreadcrumbEditButtonClickEvent)(System::TObject* Sender, TdxBreadcrumbEditButton* AButton);

typedef void __fastcall (__closure *TdxBreadcrumbEditNodeEvent)(System::TObject* Sender, TdxBreadcrumbEditNode* ANode);

typedef void __fastcall (__closure *TdxBreadcrumbEditPathEnteredEvent)(System::TObject* Sender, System::UnicodeString &ANewPath, bool &AHandled);

typedef void __fastcall (__closure *TdxBreadcrumbEditPathValidateEvent)(System::TObject* Sender, const System::UnicodeString APath, TdxBreadcrumbEditNode* &ANode, System::UnicodeString &AErrorText, bool &AError);

class DELPHICLASS TdxCustomBreadcrumbEdit;
class PASCALIMPLEMENTATION TdxCustomBreadcrumbEdit : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxBreadcrumbEditController* FController;
	TdxCustomBreadcrumbEditProperties* FProperties;
	TdxBreadcrumbEditNode* FRoot;
	bool FTransparent;
	TdxBreadcrumbEditViewInfo* FViewInfo;
	TdxBreadcrumbEditButtonClickEvent FOnButtonClick;
	TdxBreadcrumbEditNodeEvent FOnDeleteNode;
	TdxBreadcrumbEditNodeEvent FOnNodeDropDownPopup;
	TdxBreadcrumbEditPathEnteredEvent FOnPathEntered;
	System::Classes::TNotifyEvent FOnPathSelected;
	TdxBreadcrumbEditPathValidateEvent FOnPathValidate;
	TdxBreadcrumbEditPopulateAutoCompleteSuggestionsEvent FOnPopulateAutoCompleteSuggestions;
	TdxBreadcrumbEditNodeEvent FOnPopulateChildren;
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	TdxBreadcrumbEditNode* __fastcall GetSelected(void);
	void __fastcall PropertiesChanged(System::TObject* Sender, TdxBreadcrumbEditChanges AChanges);
	void __fastcall SetProperties(TdxCustomBreadcrumbEditProperties* AValue);
	void __fastcall SetSelected(TdxBreadcrumbEditNode* AValue);
	void __fastcall SetTransparent(bool AValue);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	
protected:
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual TdxBreadcrumbEditController* __fastcall CreateController(void);
	virtual TdxCustomBreadcrumbEditProperties* __fastcall CreateProperties(void);
	virtual TdxBreadcrumbEditNode* __fastcall CreateRoot(void) = 0 ;
	virtual TdxBreadcrumbEditViewInfo* __fastcall CreateViewInfo(void);
	HIDESBASE virtual void __fastcall Changed(TdxBreadcrumbEditChanges AChanges);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	DYNAMIC void __fastcall FocusChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	virtual void __fastcall RecalculateViewInfo(void);
	DYNAMIC void __fastcall Resize(void);
	virtual System::UnicodeString __fastcall GetSelectedPath(void);
	virtual void __fastcall SetSelectedPath(const System::UnicodeString AValue);
	bool __fastcall CanCollapse(Dxcustomtree::TdxTreeCustomNode* ASender);
	bool __fastcall CanExpand(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall Collapsed(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall Expanded(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall BeforeDelete(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall DeleteNode(Dxcustomtree::TdxTreeCustomNode* ASender);
	Dxcustomtree::TdxTreeCustomNodeClass __fastcall GetNodeClass(Dxcustomtree::TdxTreeCustomNode* ARelativeNode);
	System::Classes::TPersistent* __fastcall GetTreeOwner(void);
	virtual void __fastcall LoadChildren(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall TreeNotification(Dxcustomtree::TdxTreeCustomNode* ASender, Dxcustomtree::TdxTreeNodeNotifications ANotification);
	Vcl::Controls::TWinControl* __fastcall GetContainer(void);
	TdxBreadcrumbEditController* __fastcall GetController(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	bool __fastcall GetIsEnabled(void);
	TdxCustomBreadcrumbEditProperties* __fastcall GetProperties(void);
	TdxBreadcrumbEditNode* __fastcall GetRoot(void);
	bool __fastcall GetShowHint(void);
	void __fastcall AdjustAutoSize(void);
	void __fastcall NodeDropDownPopup(TdxBreadcrumbEditNode* ANode);
	virtual void __fastcall PathEntered(System::UnicodeString &ANewPath, bool &AHandled);
	virtual void __fastcall PathValidate(const System::UnicodeString APath, TdxBreadcrumbEditNode* &ANode, System::UnicodeString &AErrorText, bool &AError);
	virtual void __fastcall PopulateAutoCompleteSuggestions(const System::UnicodeString APath, System::Classes::TStringList* ASuggestions);
	virtual void __fastcall ProcessButtonClick(TdxBreadcrumbEditButton* AButton);
	virtual void __fastcall SelectionChanged(void);
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	__property TdxBreadcrumbEditController* Controller = {read=FController};
	__property TdxBreadcrumbEditNode* Root = {read=GetRoot};
	__property TdxBreadcrumbEditViewInfo* ViewInfo = {read=FViewInfo};
	__property TdxBreadcrumbEditButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property TdxBreadcrumbEditNodeEvent OnDeleteNode = {read=FOnDeleteNode, write=FOnDeleteNode};
	__property TdxBreadcrumbEditNodeEvent OnNodeDropDownPopup = {read=FOnNodeDropDownPopup, write=FOnNodeDropDownPopup};
	__property TdxBreadcrumbEditPathEnteredEvent OnPathEntered = {read=FOnPathEntered, write=FOnPathEntered};
	__property System::Classes::TNotifyEvent OnPathSelected = {read=FOnPathSelected, write=FOnPathSelected};
	__property TdxBreadcrumbEditPathValidateEvent OnPathValidate = {read=FOnPathValidate, write=FOnPathValidate};
	__property TdxBreadcrumbEditPopulateAutoCompleteSuggestionsEvent OnPopulateAutoCompleteSuggestions = {read=FOnPopulateAutoCompleteSuggestions, write=FOnPopulateAutoCompleteSuggestions};
	__property TdxBreadcrumbEditNodeEvent OnPopulateChildren = {read=FOnPopulateChildren, write=FOnPopulateChildren};
	
public:
	__fastcall virtual TdxCustomBreadcrumbEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomBreadcrumbEdit(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BrowseParent(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall InitiateAction(void);
	__property AutoSize = {default=1};
	__property Color = {default=536870912};
	__property LookAndFeel;
	__property TdxCustomBreadcrumbEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property TdxBreadcrumbEditNode* Selected = {read=GetSelected, write=SetSelected};
	__property System::UnicodeString SelectedPath = {read=GetSelectedPath, write=SetSelectedPath};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomBreadcrumbEdit(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxBreadcrumbEditEvents;	/* IdxBreadcrumbEditEvents */
	void *__IdxBreadcrumbEdit;	/* IdxBreadcrumbEdit */
	void *__IdxTreeOwner;	/* Dxcustomtree::IdxTreeOwner */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {58BB7C9A-21D2-4E8C-B95C-E20BC3768E28}
	operator _di_IdxBreadcrumbEditEvents()
	{
		_di_IdxBreadcrumbEditEvents intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxBreadcrumbEditEvents*(void) { return (IdxBreadcrumbEditEvents*)&__IdxBreadcrumbEditEvents; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1F299DAA-9C6C-4EBA-B1C3-14E2DF2DEEEE}
	operator _di_IdxBreadcrumbEdit()
	{
		_di_IdxBreadcrumbEdit intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxBreadcrumbEdit*(void) { return (IdxBreadcrumbEdit*)&__IdxBreadcrumbEdit; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E5BD359F-E1D0-4ABC-9D9D-45A6516F2F8B}
	operator Dxcustomtree::_di_IdxTreeOwner()
	{
		Dxcustomtree::_di_IdxTreeOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomtree::IdxTreeOwner*(void) { return (Dxcustomtree::IdxTreeOwner*)&__IdxTreeOwner; }
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


class DELPHICLASS TdxBreadcrumbEditProperties;
class PASCALIMPLEMENTATION TdxBreadcrumbEditProperties : public TdxCustomBreadcrumbEditProperties
{
	typedef TdxCustomBreadcrumbEditProperties inherited;
	
__published:
	__property Borders = {default=15};
	__property Buttons;
	__property ButtonImages;
	__property DropDownRows = {default=18};
	__property Images;
	__property PathEditor;
	__property ProgressBar;
public:
	/* TdxCustomBreadcrumbEditProperties.Create */ inline __fastcall virtual TdxBreadcrumbEditProperties(System::Classes::TPersistent* AOwner) : TdxCustomBreadcrumbEditProperties(AOwner) { }
	/* TdxCustomBreadcrumbEditProperties.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditProperties(void) { }
	
};


class DELPHICLASS TdxBreadcrumbEdit;
class PASCALIMPLEMENTATION TdxBreadcrumbEdit : public TdxCustomBreadcrumbEdit
{
	typedef TdxCustomBreadcrumbEdit inherited;
	
private:
	System::UnicodeString FLoadedSelectedPath;
	HIDESBASE TdxBreadcrumbEditProperties* __fastcall GetProperties(void);
	bool __fastcall IsSelectedPathStored(void);
	HIDESBASE void __fastcall SetProperties(TdxBreadcrumbEditProperties* AValue);
	void __fastcall ReadData(System::Classes::TStream* AStream);
	void __fastcall WriteData(System::Classes::TStream* AStream);
	
protected:
	virtual TdxCustomBreadcrumbEditProperties* __fastcall CreateProperties(void);
	virtual TdxBreadcrumbEditNode* __fastcall CreateRoot(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual System::UnicodeString __fastcall GetSelectedPath(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetSelectedPath(const System::UnicodeString AValue);
	
public:
	__property Root;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property Color = {default=536870912};
	__property Enabled = {default=1};
	__property Font;
	__property LookAndFeel;
	__property ParentShowHint = {default=1};
	__property TdxBreadcrumbEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property SelectedPath = {stored=IsSelectedPathStored, default=0};
	__property ShowHint;
	__property Transparent = {default=0};
	__property OnButtonClick;
	__property OnDeleteNode;
	__property OnNodeDropDownPopup;
	__property OnPathEntered;
	__property OnPathSelected;
	__property OnPathValidate;
	__property OnPopulateAutoCompleteSuggestions;
	__property OnPopulateChildren;
public:
	/* TdxCustomBreadcrumbEdit.Create */ inline __fastcall virtual TdxBreadcrumbEdit(System::Classes::TComponent* AOwner) : TdxCustomBreadcrumbEdit(AOwner) { }
	/* TdxCustomBreadcrumbEdit.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBreadcrumbEdit(HWND ParentWindow) : TdxCustomBreadcrumbEdit(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 nvipNone = System::Int8(-1);
static const System::Int8 nvipControl = System::Int8(0x0);
static const System::Int8 nvipDelimiter = System::Int8(0x1);
static const System::Word dxBreadcrumbEditDefaultAnimationRestartDelay = System::Word(0x1f4);
static const System::Int8 dxBreadcrumbEditDefaultAnimationSpeed = System::Int8(0xa);
static const System::Int8 dxBreadcrumbEditDefaultAutoCompleteDropDownRows = System::Int8(0x10);
static const System::Int8 dxBreadcrumbEditDefaultDropDownRows = System::Int8(0x12);
static const System::Int8 dxBreadcrumbEditDefaultHeight = System::Int8(0x14);
static const System::Int8 dxBreadcrumbEditDefaultRecentPathsDropDownRows = System::Int8(0xe);
}	/* namespace Dxbreadcrumbedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBREADCRUMBEDIT)
using namespace Dxbreadcrumbedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbreadcrumbeditHPP
