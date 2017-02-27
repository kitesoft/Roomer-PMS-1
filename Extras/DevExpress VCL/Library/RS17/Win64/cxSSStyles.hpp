// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSStyles.pas' rev: 24.00 (Win64)

#ifndef CxssstylesHPP
#define CxssstylesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSPainterWrapper.hpp>	// Pascal unit
#include <cxSSIntf.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssstyles
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxSSStyleCacheClass;

class DELPHICLASS EStyleError;
class PASCALIMPLEMENTATION EStyleError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EStyleError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EStyleError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EStyleError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EStyleError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EStyleError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EStyleError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EStyleError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EStyleError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EStyleError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EStyleError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EStyleError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EStyleError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EStyleError(void) { }
	
};


enum TcxSSStyleInfoType : unsigned char { siAlign, siMerge, siReadOnly, siTextColor, siBrush, siBorder, siFont, siFormat, siAll };

typedef void __fastcall (__closure *TChangeStyleEvent)(System::TObject* Sender, TcxSSStyleInfoType AStyleType);

class DELPHICLASS TcxSSStyleCache;
class DELPHICLASS TcxSSDefaultStyle;
class DELPHICLASS TcxSSCellStyle;
class PASCALIMPLEMENTATION TcxSSStyleCache : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Cxsstypes::PcxSSCellStyleRec operator[](int AIndex) { return Styles[AIndex]; }
	
private:
	TcxSSDefaultStyle* FDefCellStyle;
	System::Classes::TList* FFontList;
	bool FIsChangeBorders;
	System::TObject* FOwner;
	System::Classes::TList* FStyles;
	int FLockCount;
	System::TObject* __fastcall GetListener(void);
	bool __fastcall GetLock(void);
	Cxexcelconst::PcxExcelPalette __fastcall GetPalette(void);
	Cxsstypes::PcxSSCellStyleRec __fastcall GetStyleFromList(int AIndex);
	void __fastcall SetLock(const bool Value);
	
protected:
	Cxsstypes::PcxSSCellStyleRec __fastcall AddCellStyleRec(const Cxsstypes::TcxSSCellStyleRec &ACellStyle);
	virtual void __fastcall DoOnChange(System::TObject* Sender, TcxSSStyleInfoType AStyleType);
	Cxsstypes::TcxSSCellStyleRec __fastcall GetCellStyleRecFromCellStyle(TcxSSCellStyle* ACellStyle);
	int __fastcall IndexOf(const Cxsstypes::TcxSSCellStyleRec &ACellStyle);
	__property System::TObject* Listener = {read=GetListener};
	__property Cxexcelconst::PcxExcelPalette Palette = {read=GetPalette};
	
public:
	__fastcall virtual TcxSSStyleCache(System::TObject* AOwner);
	__fastcall virtual ~TcxSSStyleCache(void);
	virtual Cxsstypes::PcxSSFontRec __fastcall AddFont(const System::UnicodeString AName, System::Uitypes::TFontStyles AStyle, System::Uitypes::TFontCharset ACharSet, short ASize, System::Byte AColor);
	virtual Cxsstypes::PcxSSFontRec __fastcall AddFontClone(Cxsstypes::PcxSSFontRec AFont);
	void __fastcall Clear(void);
	virtual Cxsstypes::PcxSSCellStyleRec __fastcall Clone(Cxsstypes::PcxSSCellStyleRec AStyle);
	TcxSSCellStyle* __fastcall GetCellStyle(System::TObject* ADataStorage, int ACol, int ARow);
	void __fastcall ReleaseRefCount(const int AIndex);
	__property Cxsstypes::PcxSSCellStyleRec Styles[int AIndex] = {read=GetStyleFromList/*, default*/};
	__property TcxSSDefaultStyle* DefaultStyle = {read=FDefCellStyle};
	__property System::TObject* Owner = {read=FOwner};
	__property System::Classes::TList* StyleList = {read=FStyles};
	__property System::Classes::TList* Fonts = {read=FFontList};
	__property bool Lock = {read=GetLock, write=SetLock, nodefault};
};


class DELPHICLASS TcxSSStyle;
class PASCALIMPLEMENTATION TcxSSStyle : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxSSStyleInfoType FInfoType;
	int FLockUpdate;
	System::Classes::TNotifyEvent FOnChange;
	TcxSSCellStyle* FOwner;
	bool __fastcall GetUpdate(void);
	void __fastcall SetUpdate(const bool Value);
	
protected:
	virtual void __fastcall DoOnChange(System::TObject* Sender);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	System::Word __fastcall ValidateColor(System::Word AColor, System::Word ADefault);
	__property TcxSSStyleInfoType InfoType = {read=FInfoType, write=FInfoType, nodefault};
	__property bool LockUpdate = {read=GetUpdate, write=SetUpdate, nodefault};
	__property TcxSSCellStyle* Owner = {read=FOwner, write=FOwner};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSSStyle(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSSStyle(void) : System::Classes::TPersistent() { }
	
};


class DELPHICLASS TcxSSFont;
class PASCALIMPLEMENTATION TcxSSFont : public TcxSSStyle
{
	typedef TcxSSStyle inherited;
	
private:
	System::Uitypes::TFontCharset __fastcall GetCharset(void);
	Cxsstypes::TcxSSColor __fastcall GetColor(void);
	System::Uitypes::TFontName __fastcall GetName(void);
	int __fastcall GetSize(void);
	System::Uitypes::TFontStyles __fastcall GetStyle(void);
	void __fastcall SetCharset(const System::Uitypes::TFontCharset Value);
	void __fastcall SetColor(const Cxsstypes::TcxSSColor Value);
	void __fastcall SetName(const System::Uitypes::TFontName Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetStyle(const System::Uitypes::TFontStyles Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignInfo(const System::UnicodeString AName, int ASize, System::Uitypes::TFontStyles AStyle, System::Uitypes::TFontCharset ACharset, System::Word AFontColor);
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	
__published:
	__property System::Uitypes::TFontName Name = {read=GetName, write=SetName};
	__property int Size = {read=GetSize, write=SetSize, default=8};
	__property System::Uitypes::TFontStyles Style = {read=GetStyle, write=SetStyle, default=0};
	__property System::Uitypes::TFontCharset Charset = {read=GetCharset, write=SetCharset, default=1};
	__property Cxsstypes::TcxSSColor FontColor = {read=GetColor, write=SetColor, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSSFont(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSSFont(void) : TcxSSStyle() { }
	
};


class DELPHICLASS TcxSSBrush;
class PASCALIMPLEMENTATION TcxSSBrush : public TcxSSStyle
{
	typedef TcxSSStyle inherited;
	
private:
	Cxsstypes::TcxSSColor __fastcall GetBkColor(void);
	Cxsstypes::TcxSSColor __fastcall GetFgColor(void);
	Cxsstypes::TcxSSFillStyle __fastcall GetStyle(void);
	void __fastcall SetBkColor(const Cxsstypes::TcxSSColor Value);
	void __fastcall SetFgColor(const Cxsstypes::TcxSSColor Value);
	void __fastcall SetStyle(const Cxsstypes::TcxSSFillStyle Value);
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignInfo(Cxsstypes::TcxSSFillStyle AStyle, const System::Word ABackgroundColor, const System::Word AForegroundColor);
	
__published:
	__property Cxsstypes::TcxSSFillStyle Style = {read=GetStyle, write=SetStyle, default=0};
	__property Cxsstypes::TcxSSColor BackgroundColor = {read=GetBkColor, write=SetBkColor, default=56};
	__property Cxsstypes::TcxSSColor ForegroundColor = {read=GetFgColor, write=SetFgColor, default=56};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSSBrush(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSSBrush(void) : TcxSSStyle() { }
	
};


class DELPHICLASS TcxSSEdgeStyle;
class PASCALIMPLEMENTATION TcxSSEdgeStyle : public TcxSSStyle
{
	typedef TcxSSStyle inherited;
	
private:
	Cxsstypes::TcxSSEdgeBorder FKind;
	Cxsstypes::TcxSSColor __fastcall GetColor(void);
	Cxsstypes::TcxSSEdgeLineStyle __fastcall GetStyle(void);
	void __fastcall SetColor(const Cxsstypes::TcxSSColor Value);
	void __fastcall SetStyle(const Cxsstypes::TcxSSEdgeLineStyle Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignRec(Cxsstypes::TcxSSEdgeStyleRec AData);
	virtual void __fastcall AssignInfo(Cxsstypes::TcxSSEdgeLineStyle AStyle, System::Word AColor);
	__property Cxsstypes::TcxSSEdgeBorder Kind = {read=FKind, nodefault};
	
__published:
	__property Cxsstypes::TcxSSColor Color = {read=GetColor, write=SetColor, default=57};
	__property Cxsstypes::TcxSSEdgeLineStyle Style = {read=GetStyle, write=SetStyle, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSSEdgeStyle(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSSEdgeStyle(void) : TcxSSStyle() { }
	
};


class DELPHICLASS TcxSSBorderStyle;
class PASCALIMPLEMENTATION TcxSSBorderStyle : public TcxSSStyle
{
	typedef TcxSSStyle inherited;
	
public:
	TcxSSEdgeStyle* operator[](Cxsstypes::TcxSSEdgeBorder Index) { return Edges[Index]; }
	
private:
	System::StaticArray<TcxSSEdgeStyle*, 4> FEdges;
	TcxSSEdgeStyle* __fastcall GetEdgeStyle(Cxsstypes::TcxSSEdgeBorder Index);
	TcxSSEdgeStyle* __fastcall GetEdgeStyleByIndex(int Index);
	void __fastcall SetEdgeStyleByIndex(int Index, TcxSSEdgeStyle* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BeforeDestruction(void);
	__property TcxSSEdgeStyle* Edges[Cxsstypes::TcxSSEdgeBorder Index] = {read=GetEdgeStyle/*, default*/};
	
__published:
	__property TcxSSEdgeStyle* Left = {read=GetEdgeStyleByIndex, write=SetEdgeStyleByIndex, index=0};
	__property TcxSSEdgeStyle* Top = {read=GetEdgeStyleByIndex, write=SetEdgeStyleByIndex, index=1};
	__property TcxSSEdgeStyle* Right = {read=GetEdgeStyleByIndex, write=SetEdgeStyleByIndex, index=2};
	__property TcxSSEdgeStyle* Bottom = {read=GetEdgeStyleByIndex, write=SetEdgeStyleByIndex, index=3};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSSBorderStyle(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSSBorderStyle(void) : TcxSSStyle() { }
	
};


class PASCALIMPLEMENTATION TcxSSCellStyle : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxSSBorderStyle* FBorderStyle;
	TcxSSBrush* FBrush;
	int FCol;
	TcxSSFont* FFont;
	int FLockCount;
	TcxSSStyleCache* FParent;
	TChangeStyleEvent FOnChangeStyle;
	System::TObject* FOwner;
	int FRow;
	Cxsstypes::TcxSSCellStyleRec *FStylePtr;
	TcxSSBorderStyle* __fastcall GetBorderStyle(void);
	TcxSSBrush* __fastcall GetBrush(void);
	TcxSSFont* __fastcall GetFont(void);
	Cxsstypes::TxlsDataFormat __fastcall GetFormat(void);
	bool __fastcall GetIsMain(void);
	bool __fastcall GetLockUpdate(void);
	bool __fastcall GetLocked(void);
	bool __fastcall GetMerge(void);
	bool __fastcall GetReadOnly(void);
	Cxsstypes::PcxSSCellStyleRec __fastcall GetStyleInfoPtr(void);
	Cxsstypes::TcxHorzTextAlign __fastcall GetTextHAlign(void);
	Cxsstypes::TcxVertTextAlign __fastcall GetTextVAlign(void);
	bool __fastcall GetWordBreak(void);
	void __fastcall SetBorderStyle(const Cxsstypes::TcxSSEdgeBorder ASide, Cxsstypes::TcxSSEdgeLineStyle AStyle, System::Byte AColor);
	void __fastcall SetCellStyle(const Cxsstypes::PcxSSCellStyleRec AStyle, bool ASetDefaultBorders = false);
	void __fastcall SetBordersProperty(TcxSSBorderStyle* Value);
	void __fastcall SetBrushProperty(TcxSSBrush* Value);
	void __fastcall SetFont(const Cxsstypes::TcxSSFontRec &AFont);
	void __fastcall SetFontProperty(TcxSSFont* Value);
	void __fastcall SetFillStyle(const Cxsstypes::TcxSSFillStyle AStyle, System::Byte AFgColor, System::Byte ABkColor);
	void __fastcall SetFormatStyle(const Cxsstypes::TxlsDataFormat Value);
	void __fastcall SetLockUpdate(const bool Value);
	void __fastcall SetLocked(const bool Value);
	void __fastcall SetMerge(const bool Value);
	void __fastcall SetReadOnly(const bool Value);
	void __fastcall SetStylePtr(const Cxsstypes::PcxSSCellStyleRec Value);
	void __fastcall SetTextHAlign(const Cxsstypes::TcxHorzTextAlign Value);
	void __fastcall SetTextVAlign(const Cxsstypes::TcxVertTextAlign Value);
	void __fastcall SetWordBreak(const bool Value);
	
protected:
	Cxsstypes::TcxSSCellStyleRec StyleInfo;
	virtual void __fastcall DoOnChange(System::TObject* Sender, TcxSSStyleInfoType AStyleType);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall ResizeExtents(const System::Types::TSize AExtent, const System::Types::TSize ANewExtent);
	void __fastcall SetState(Cxsstypes::TcxSSCellStates AState);
	__property bool LockUpdate = {read=GetLockUpdate, write=SetLockUpdate, nodefault};
	__property bool Merge = {read=GetMerge, write=SetMerge, nodefault};
	__property System::TObject* Owner = {read=FOwner};
	__property TcxSSStyleCache* Parent = {read=FParent};
	__property Cxsstypes::PcxSSCellStyleRec StylePtr = {read=FStylePtr, write=SetStylePtr};
	__property Cxsstypes::PcxSSCellStyleRec StyleInfoPtr = {read=GetStyleInfoPtr};
	
public:
	__fastcall TcxSSCellStyle(TcxSSStyleCache* AParent, System::TObject* AOwner, int ACol, int ARow)/* overload */;
	__fastcall virtual ~TcxSSCellStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool IsMain = {read=GetIsMain, nodefault};
	__property bool IsMerge = {read=GetMerge, nodefault};
	__property int Col = {read=FCol, nodefault};
	__property int Row = {read=FRow, nodefault};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, nodefault};
	
__published:
	__property bool Locked = {read=GetLocked, write=SetLocked, default=1};
	__property TcxSSBorderStyle* Borders = {read=GetBorderStyle, write=SetBordersProperty};
	__property TcxSSBrush* Brush = {read=GetBrush, write=SetBrushProperty};
	__property TcxSSFont* Font = {read=GetFont, write=SetFontProperty};
	__property Cxsstypes::TxlsDataFormat Format = {read=GetFormat, write=SetFormatStyle, default=0};
	__property Cxsstypes::TcxHorzTextAlign HorzTextAlign = {read=GetTextHAlign, write=SetTextHAlign, default=0};
	__property Cxsstypes::TcxVertTextAlign VertTextAlign = {read=GetTextVAlign, write=SetTextVAlign, default=1};
	__property bool WordBreak = {read=GetWordBreak, write=SetWordBreak, default=0};
private:
	void *__IcxSpreadSheetCellStyle;	/* Cxssintf::IcxSpreadSheetCellStyle */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A381E00-4311-49A2-816B-C79F4690AF96}
	operator Cxssintf::_di_IcxSpreadSheetCellStyle()
	{
		Cxssintf::_di_IcxSpreadSheetCellStyle intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxssintf::IcxSpreadSheetCellStyle*(void) { return (Cxssintf::IcxSpreadSheetCellStyle*)&__IcxSpreadSheetCellStyle; }
	#endif
	
};


class DELPHICLASS TcxSSDefaultBorders;
class PASCALIMPLEMENTATION TcxSSDefaultBorders : public TcxSSStyle
{
	typedef TcxSSStyle inherited;
	
private:
	System::StaticArray<TcxSSEdgeStyle*, 2> FBorders;
	TcxSSEdgeStyle* __fastcall GetEdgeStyleByIndex(int Index);
	void __fastcall SetEdgeStyleByIndex(int Index, TcxSSEdgeStyle* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BeforeDestruction(void);
	
__published:
	__property TcxSSEdgeStyle* HorizontalBorders = {read=GetEdgeStyleByIndex, write=SetEdgeStyleByIndex, index=1};
	__property TcxSSEdgeStyle* VerticalBorders = {read=GetEdgeStyleByIndex, write=SetEdgeStyleByIndex, index=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSSDefaultBorders(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSSDefaultBorders(void) : TcxSSStyle() { }
	
};


class PASCALIMPLEMENTATION TcxSSDefaultStyle : public TcxSSCellStyle
{
	typedef TcxSSCellStyle inherited;
	
private:
	TcxSSDefaultBorders* FBorders;
	TcxSSDefaultBorders* __fastcall GetBordersProperty(void);
	HIDESBASE void __fastcall SetBordersProperty(TcxSSDefaultBorders* Value);
	
__published:
	__fastcall virtual ~TcxSSDefaultStyle(void);
	__property TcxSSDefaultBorders* Borders = {read=GetBordersProperty, write=SetBordersProperty};
public:
	/* TcxSSCellStyle.Create */ inline __fastcall TcxSSDefaultStyle(TcxSSStyleCache* AParent, System::TObject* AOwner, int ACol, int ARow)/* overload */ : TcxSSCellStyle(AParent, AOwner, ACol, ARow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE HFONT __fastcall CreateFontHandle(Cxsstypes::PcxSSFontRec AFontRec);
}	/* namespace Cxssstyles */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSSTYLES)
using namespace Cxssstyles;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssstylesHPP
