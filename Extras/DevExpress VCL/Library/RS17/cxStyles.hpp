// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxStyles.pas' rev: 24.00 (Win32)

#ifndef CxstylesHPP
#define CxstylesHPP

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
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxstyles
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxCustomStylesClass;

__interface IcxStyleChangeListener;
typedef System::DelphiInterface<IcxStyleChangeListener> _di_IcxStyleChangeListener;
class DELPHICLASS TcxCustomStyle;
__interface  INTERFACE_UUID("{E25A5395-C1E8-4311-A281-9575F79DE862}") IcxStyleChangeListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall StyleChanged(TcxCustomStyle* AStyle) = 0 ;
	virtual void __fastcall StyleRemoved(TcxCustomStyle* AStyle) = 0 ;
};

class DELPHICLASS TcxStyleRepository;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomStyle : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TList* FListeners;
	TcxStyleRepository* FStyleRepository;
	int __fastcall GetIndex(void);
	void __fastcall SetStyleRepository(TcxStyleRepository* Value);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall ChangeScale(int M, int D);
	
public:
	__fastcall virtual TcxCustomStyle(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomStyle(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall AddListener(_di_IcxStyleChangeListener AListener);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual void __fastcall RemoveListener(_di_IcxStyleChangeListener AListener);
	virtual void __fastcall RestoreDefaults(void);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* AParent);
	__property int Index = {read=GetIndex, nodefault};
	__property TcxStyleRepository* StyleRepository = {read=FStyleRepository, write=SetStyleRepository};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomStyleSheet;
class DELPHICLASS TcxCustomStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomStyleSheet : public Cxclasses::TcxComponent
{
	typedef Cxclasses::TcxComponent inherited;
	
private:
	bool FBuiltIn;
	System::UnicodeString FCaption;
	TcxCustomStyles* FStyles;
	System::Classes::TList* FStylesList;
	TcxStyleRepository* FStyleRepository;
	bool __fastcall GetCaptionStored(void);
	System::UnicodeString __fastcall GetCaption(void);
	int __fastcall GetIndex(void);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetStyleRepository(TcxStyleRepository* Value);
	void __fastcall ReadBuiltIn(System::Classes::TReader* AReader);
	void __fastcall WriteBuiltIn(System::Classes::TWriter* AWriter);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* AFiler);
	void __fastcall DoStyleChanged(int AIndex);
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	
public:
	__fastcall virtual TcxCustomStyleSheet(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomStyleSheet(void);
	void __fastcall AddStyles(TcxCustomStyles* AStyles);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall CopyFrom(TcxCustomStyleSheet* AStyleSheet);
	__classmethod virtual TcxCustomStylesClass __fastcall GetStylesClass();
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	TcxCustomStyles* __fastcall GetStyles(void);
	void __fastcall RemoveStyles(TcxCustomStyles* AStyles);
	void __fastcall SetStyles(TcxCustomStyles* const Value);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* AParent);
	__property bool BuiltIn = {read=FBuiltIn, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property TcxStyleRepository* StyleRepository = {read=FStyleRepository, write=SetStyleRepository};
	
__published:
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=GetCaptionStored};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomStyleClass;

typedef System::TMetaClass* TcxCustomStyleSheetClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStyleRepository : public Cxclasses::TcxScalableComponent
{
	typedef Cxclasses::TcxScalableComponent inherited;
	
public:
	TcxCustomStyle* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	System::Classes::TList* FStyleSheets;
	int __fastcall GetCount(void);
	TcxCustomStyle* __fastcall GetItem(int Index);
	int __fastcall GetStyleSheetCount(void);
	TcxCustomStyleSheet* __fastcall GetStyleSheet(int Index);
	
protected:
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual void __fastcall ChangeScale(int M, int D);
	void __fastcall AddItem(TcxCustomStyle* AItem);
	void __fastcall AddStyleSheet(TcxCustomStyleSheet* AStyleSheet);
	void __fastcall RemoveItem(TcxCustomStyle* AItem);
	void __fastcall RemoveStyleSheet(TcxCustomStyleSheet* AStyleSheet);
	
public:
	__fastcall virtual TcxStyleRepository(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxStyleRepository(void);
	void __fastcall Clear(void);
	void __fastcall ClearStyleSheets(void);
	virtual TcxCustomStyle* __fastcall CreateItem(TcxCustomStyleClass AStyleClass);
	virtual TcxCustomStyle* __fastcall CreateItemEx(TcxCustomStyleClass AStyleClass, System::Classes::TComponent* AOwner);
	virtual TcxCustomStyleSheet* __fastcall CreateStyleSheet(TcxCustomStyleSheetClass AStyleSheetClass);
	virtual TcxCustomStyleSheet* __fastcall CreateStyleSheetEx(TcxCustomStyleSheetClass AStyleSheetClass, System::Classes::TComponent* AOwner);
	int __fastcall StyleIndexOf(TcxCustomStyle* AStyle);
	int __fastcall StyleSheetIndexOf(TcxCustomStyleSheet* AStyleSheet);
	__property int Count = {read=GetCount, nodefault};
	__property int StyleSheetCount = {read=GetStyleSheetCount, nodefault};
	__property TcxCustomStyle* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxCustomStyleSheet* StyleSheets[int Index] = {read=GetStyleSheet};
	
__published:
	__property Scalable = {default=0};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomStylesItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomStylesItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int Index;
	TcxCustomStyle* Item;
	__fastcall TcxCustomStylesItem(int AIndex, TcxCustomStyle* AItem);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomStylesItem(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomStyles : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	bool FDestroying;
	System::Classes::TList* FItems;
	TcxCustomStyleSheet* FStyleSheet;
	TcxCustomStyleSheet* FOwnerStyleSheet;
	int __fastcall GetCount(void);
	TcxCustomStylesItem* __fastcall GetItem(int Index);
	void __fastcall SetStyleSheet(TcxCustomStyleSheet* const Value);
	
protected:
	void __fastcall StyleChanged(TcxCustomStyle* Sender);
	void __fastcall StyleRemoved(TcxCustomStyle* Sender);
	virtual void __fastcall Changed(int AIndex);
	void __fastcall Clear(void);
	void __fastcall Delete(int AItemIndex);
	virtual void __fastcall DoChanged(int AIndex);
	bool __fastcall Find(int AIndex, int &AItemIndex);
	TcxCustomStyle* __fastcall GetValue(int Index);
	void __fastcall SetValue(int Index, TcxCustomStyle* Value);
	__property int Count = {read=GetCount, nodefault};
	__property bool Destroying = {read=FDestroying, nodefault};
	__property TcxCustomStylesItem* Items[int Index] = {read=GetItem};
	__property TcxCustomStyleSheet* OwnerStyleSheet = {read=FOwnerStyleSheet};
	__property TcxCustomStyleSheet* StyleSheet = {read=FStyleSheet, write=SetStyleSheet};
	
public:
	__fastcall virtual TcxCustomStyles(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomStyles(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsValidStyleSheet(TcxCustomStyleSheet* AStyleSheet);
	void __fastcall ResetStyles(void);
	__property TcxCustomStyle* Values[int Index] = {read=GetValue, write=SetValue};
private:
	void *__IcxStyleChangeListener;	/* IcxStyleChangeListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E25A5395-C1E8-4311-A281-9575F79DE862}
	operator _di_IcxStyleChangeListener()
	{
		_di_IcxStyleChangeListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxStyleChangeListener*(void) { return (IcxStyleChangeListener*)&__IcxStyleChangeListener; }
	#endif
	
};

#pragma pack(pop)

enum TcxStyleValue : unsigned char { svBitmap, svColor, svFont, svTextColor };

typedef System::Set<TcxStyleValue, TcxStyleValue::svBitmap, TcxStyleValue::svTextColor>  TcxStyleValues;

class DELPHICLASS TcxStyle;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStyle : public TcxCustomStyle
{
	typedef TcxCustomStyle inherited;
	
private:
	TcxStyleValues FAssignedValues;
	Vcl::Graphics::TBitmap* FBitmap;
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FFont;
	System::Uitypes::TColor FTextColor;
	void __fastcall SetAssignedValues(TcxStyleValues Value);
	void __fastcall SetBitmap(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetTextColor(System::Uitypes::TColor Value);
	void __fastcall BitmapChanged(System::TObject* Sender);
	void __fastcall FontChanged(System::TObject* Sender);
	bool __fastcall IsBitmapStored(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsTextColorStored(void);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	
public:
	__fastcall virtual TcxStyle(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property TcxStyleValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, stored=IsColorStored, nodefault};
	__property Vcl::Graphics::TBitmap* Bitmap = {read=FBitmap, write=SetBitmap, stored=IsBitmapStored};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property System::Uitypes::TColor TextColor = {read=FTextColor, write=SetTextColor, stored=IsTextColorStored, nodefault};
};

#pragma pack(pop)

typedef System::UnicodeString __fastcall (__closure *TcxStyleGetName)(TcxStyle* AStyle);

class DELPHICLASS TcxStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStyles : public TcxCustomStyles
{
	typedef TcxCustomStyles inherited;
	
private:
	int FMaxDefaultViewParamsIndex;
	
protected:
	bool BitmapInViewParams;
	void __fastcall DefaultFontChanged(System::TObject* Sender, Vcl::Graphics::TFont* AFont);
	HIDESBASE TcxStyle* __fastcall GetValue(int Index);
	HIDESBASE void __fastcall SetValue(int Index, TcxStyle* Value);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	void __fastcall InternalGetViewParams(int Index, System::TObject* AData, TcxStyle* AStyle, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall IsDefaultFont(int Index);
	__property int MaxDefaultViewParamsIndex = {read=FMaxDefaultViewParamsIndex, nodefault};
	
public:
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(int Index);
	void __fastcall GetViewParams(int Index, System::TObject* AData, TcxStyle* AStyle, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property Count;
	__property StyleSheet;
	__property TcxStyle* Values[int Index] = {read=GetValue, write=SetValue};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxStyles(System::Classes::TPersistent* AOwner) : TcxCustomStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxStyles(void) { }
	
private:
	void *__IcxFontListener;	/* Cxgraphics::IcxFontListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B144DD7E-0B27-439A-B908-FC3ACFE6A2D3}
	operator Cxgraphics::_di_IcxFontListener()
	{
		Cxgraphics::_di_IcxFontListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgraphics::IcxFontListener*(void) { return (Cxgraphics::IcxFontListener*)&__IcxFontListener; }
	#endif
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall UseStyle(TcxStyle* AStyle, TcxStyleValue AStyleValue);
extern PACKAGE TcxStyleValues __fastcall CombineParamsWithStyle(TcxStyle* AStyle, TcxStyleValues AHasValues, Cxgraphics::TcxViewParams &AParams);
extern PACKAGE void __fastcall CreateStyleSheetStyles(TcxCustomStyleSheet* ADestStyleSheet, TcxCustomStyleSheet* ASourceStyleSheet, TcxStyleGetName AStyleGetName = 0x0);
extern PACKAGE void __fastcall RegisterStyleSheetClass(TcxCustomStyleSheetClass AStyleSheetClass);
extern PACKAGE void __fastcall UnregisterStyleSheetClass(TcxCustomStyleSheetClass AStyleSheetClass);
extern PACKAGE void __fastcall GetRegisteredStyleSheetClasses(System::Classes::TList* AList);
extern PACKAGE void __fastcall SaveStyleSheetsToIniFile(const System::UnicodeString AIniFileName, System::Classes::TList* const AList);
extern PACKAGE void __fastcall LoadStyleSheetsFromIniFile(const System::UnicodeString AIniFileName, TcxStyleRepository* AStyleRepository, TcxCustomStyleSheetClass AStyleSheetClass, System::Classes::TStrings* const AStyleSheetNames = (System::Classes::TStrings*)(0x0), System::Classes::TComponent* AOwner = (System::Classes::TComponent*)(0x0), System::Classes::TList* const AStyleSheetList = (System::Classes::TList*)(0x0), TcxStyleGetName AStyleGetName = 0x0);
}	/* namespace Cxstyles */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSTYLES)
using namespace Cxstyles;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxstylesHPP
