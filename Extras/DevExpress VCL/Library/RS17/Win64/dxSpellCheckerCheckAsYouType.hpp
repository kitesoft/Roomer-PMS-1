// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerCheckAsYouType.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckercheckasyoutypeHPP
#define DxspellcheckercheckasyoutypeHPP

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
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxSpellCheckerRules.hpp>	// Pascal unit
#include <dxSpellCheckerAlgorithms.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxSpellChecker.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckercheckasyoutype
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxSpellCheckerCheckAsYouTypeCurrentWordInfo
{
public:
	System::Types::TRect Bounds;
	bool IsMisspelled;
};
#pragma pack(pop)


class DELPHICLASS TdxSpellCheckerSpelledWord;
class PASCALIMPLEMENTATION TdxSpellCheckerSpelledWord : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FChecked;
	int FPosition;
	System::WideString FWord;
	int __fastcall GetEndPosition(void);
	
public:
	__fastcall virtual TdxSpellCheckerSpelledWord(int APosition, const System::WideString AWord);
	virtual void __fastcall Assign(TdxSpellCheckerSpelledWord* AWord);
	__property bool Checked = {read=FChecked, write=FChecked, nodefault};
	__property int EndPosition = {read=GetEndPosition, nodefault};
	__property int Position = {read=FPosition, write=FPosition, nodefault};
	__property System::WideString Word = {read=FWord};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerSpelledWord(void) { }
	
};


typedef System::TMetaClass* TdxSpellCheckerSpelledWordClass;

class DELPHICLASS TdxSpellCheckerSpelledWordList;
class PASCALIMPLEMENTATION TdxSpellCheckerSpelledWordList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSpellCheckerSpelledWord* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSpellCheckerSpelledWord* __fastcall GetItem(int AIndex);
	
protected:
	virtual TdxSpellCheckerSpelledWordClass __fastcall GetSpellCheckerWordClass(void);
	
public:
	TdxSpellCheckerSpelledWord* __fastcall AddWord(int APos, const System::WideString AWord);
	void __fastcall DropCheckedFlag(void);
	bool __fastcall FindWord(const System::WideString AWord, bool AUncheckedOnly, /* out */ TdxSpellCheckerSpelledWord* &AItem);
	HIDESBASE virtual void __fastcall RemoveItem(TdxSpellCheckerSpelledWord* AItem);
	void __fastcall RemoveUncheckedItems(void);
	__property TdxSpellCheckerSpelledWord* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxSpellCheckerSpelledWordList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerSpelledWordList(void) { }
	
};


class DELPHICLASS TdxSpellCheckerMisspelledWord;
class PASCALIMPLEMENTATION TdxSpellCheckerMisspelledWord : public TdxSpellCheckerSpelledWord
{
	typedef TdxSpellCheckerSpelledWord inherited;
	
private:
	typedef System::DynamicArray<System::Types::TRect> _TdxSpellCheckerMisspelledWord__1;
	
	
private:
	_TdxSpellCheckerMisspelledWord__1 FBounds;
	bool FShowSquiggle;
	Dxspellcheckerrules::TdxSpellCheckerSpellingCode FSpellingCode;
	System::Types::TRect __fastcall GetUnderlineRect(int Index);
	int __fastcall GetUnderlineRectCount(void);
	
public:
	__fastcall virtual TdxSpellCheckerMisspelledWord(int APosition, const System::WideString AWord);
	__fastcall virtual ~TdxSpellCheckerMisspelledWord(void);
	void __fastcall AddRect(const System::Types::TRect &R);
	virtual void __fastcall Assign(TdxSpellCheckerSpelledWord* AWord);
	bool __fastcall Contains(const System::Types::TPoint APoint);
	void __fastcall DeleteUnderlineRects(void);
	__property bool ShowSquiggle = {read=FShowSquiggle, write=FShowSquiggle, nodefault};
	__property Dxspellcheckerrules::TdxSpellCheckerSpellingCode SpellingCode = {read=FSpellingCode, nodefault};
	__property System::Types::TRect UnderlineRect[int Index] = {read=GetUnderlineRect};
	__property int UnderlineRectCount = {read=GetUnderlineRectCount, nodefault};
};


class DELPHICLASS TdxSpellCheckerMisspelledWordList;
class PASCALIMPLEMENTATION TdxSpellCheckerMisspelledWordList : public TdxSpellCheckerSpelledWordList
{
	typedef TdxSpellCheckerSpelledWordList inherited;
	
public:
	TdxSpellCheckerMisspelledWord* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSpellCheckerMisspelledWord* __fastcall GetItem(int AIndex);
	
protected:
	virtual TdxSpellCheckerSpelledWordClass __fastcall GetSpellCheckerWordClass(void);
	
public:
	HIDESBASE TdxSpellCheckerMisspelledWord* __fastcall AddWord(int APos, const System::WideString AWord);
	HIDESBASE bool __fastcall FindWord(const System::WideString AWord, bool AUncheckedOnly, /* out */ TdxSpellCheckerMisspelledWord* &AItem);
	bool __fastcall ItemAtIndex(int AIndex, /* out */ TdxSpellCheckerMisspelledWord* &AWord);
	bool __fastcall ItemAtPos(const System::Types::TPoint APoint, /* out */ TdxSpellCheckerMisspelledWord* &AWord);
	__property TdxSpellCheckerMisspelledWord* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxSpellCheckerMisspelledWordList(bool AOwnObjects) : TdxSpellCheckerSpelledWordList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerMisspelledWordList(void) { }
	
};


class DELPHICLASS TdxSpellCheckerPainter;
class PASCALIMPLEMENTATION TdxSpellCheckerPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FLineColor;
	Dxspellchecker::TdxSpellCheckerUnderlineStyle FLineStyle;
	void __fastcall SetLineColor(const System::Uitypes::TColor Value);
	
protected:
	void __fastcall Draw(HDC DC, const System::Types::TRect &R, bool ALineStyleNeeded);
	virtual void __fastcall DrawLine(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawWavyLine(HDC DC, const System::Types::TRect &R);
	
public:
	__fastcall TdxSpellCheckerPainter(System::Uitypes::TColor ALineColor);
	void __fastcall DrawWord(HDC DC, bool ALineStyleNeeded, TdxSpellCheckerMisspelledWord* AWord);
	__property System::Uitypes::TColor LineColor = {read=FLineColor, write=SetLineColor, nodefault};
	__property Dxspellchecker::TdxSpellCheckerUnderlineStyle LineStyle = {read=FLineStyle, write=FLineStyle, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerPainter(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCheckAsYouTypeTextParser;
class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeTextParser : public Dxspellchecker::TdxSpellCheckerTextParser
{
	typedef Dxspellchecker::TdxSpellCheckerTextParser inherited;
	
private:
	int FVisibleEndIndex;
	int FVisibleStartIndex;
	
protected:
	virtual void __fastcall UpdateTextInfo(Dxspellchecker::TdxSpellCheckerCustomEditAdapter* AAdapter);
	
public:
	virtual System::WideString __fastcall GetNextWord(int &AStart, int &ALength, /* out */ System::WideString &ADelimiters);
	bool __fastcall IsCharVisible(int APosition);
	bool __fastcall IsWordVisible(int APosition, int AWordLength);
	__property int VisibleEndIndex = {read=FVisibleEndIndex, nodefault};
	__property int VisibleStartIndex = {read=FVisibleStartIndex, nodefault};
public:
	/* TdxSpellCheckerTextParser.Create */ inline __fastcall virtual TdxSpellCheckerCheckAsYouTypeTextParser(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker) : Dxspellchecker::TdxSpellCheckerTextParser(ASpellChecker) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCheckAsYouTypeTextParser(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCheckAsYouTypeThread;
class DELPHICLASS TdxSpellCheckerCheckAsYouTypeMode;
class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeThread : public Cxclasses::TcxThread
{
	typedef Cxclasses::TcxThread inherited;
	
private:
	TdxSpellCheckerCheckAsYouTypeMode* FCheckMode;
	bool FTextChanged;
	_RTL_CRITICAL_SECTION FTextChangedLock;
	bool __fastcall CanContinue(void);
	bool __fastcall GetTextChanged(void);
	void __fastcall SetTextChanged(bool AValue);
	
protected:
	virtual void __fastcall Execute(void);
	
public:
	__fastcall TdxSpellCheckerCheckAsYouTypeThread(TdxSpellCheckerCheckAsYouTypeMode* ACheckMode);
	__fastcall virtual ~TdxSpellCheckerCheckAsYouTypeThread(void);
	__property TdxSpellCheckerCheckAsYouTypeMode* CheckMode = {read=FCheckMode};
	__property bool TextChanged = {read=GetTextChanged, write=SetTextChanged, nodefault};
};


class DELPHICLASS TdxSpellCheckerCheckAsYouTypeEditAdapter;
class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeEditAdapter : public Dxspellchecker::TdxSpellCheckerEditAdapter
{
	typedef Dxspellchecker::TdxSpellCheckerEditAdapter inherited;
	
private:
	bool FIsLineDrawStyleNeeded;
	int FLineHeight;
	bool __fastcall GetIsMultiLine(void);
	
protected:
	virtual int __fastcall GetCharIndex(const System::Types::TPoint APoint);
	virtual System::Types::TPoint __fastcall GetCharPosition(int ACharIndex);
	virtual int __fastcall GetFirstCharIndexInLine(int ALineIndex);
	virtual int __fastcall GetFirstVisibleLineIndex(void);
	virtual int __fastcall GetLineIndex(int ACharIndex);
	virtual int __fastcall GetLineLength(int ALineIndex);
	virtual int __fastcall GetSpellingStartPosition(void);
	virtual System::Types::TRect __fastcall GetTextAreaRect(void);
	virtual System::Types::TRect __fastcall GetUnderlineRect(int APosition, int ALength);
	virtual void __fastcall GetVisibleTextBounds(/* out */ int &AStartIndex, /* out */ int &AEndIndex);
	virtual int __fastcall InternalGetLineHeightByFont(int ALineIndex);
	
public:
	virtual void __fastcall RefreshParams(void);
	__property bool IsLineDrawStyleNeeded = {read=FIsLineDrawStyleNeeded, nodefault};
	__property bool IsMultiLine = {read=GetIsMultiLine, nodefault};
	__property System::Types::TRect TextAreaRect = {read=GetTextAreaRect};
public:
	/* TdxSpellCheckerCustomEditAdapter.Create */ inline __fastcall virtual TdxSpellCheckerCheckAsYouTypeEditAdapter(Vcl::Controls::TWinControl* AEdit) : Dxspellchecker::TdxSpellCheckerEditAdapter(AEdit) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCheckAsYouTypeEditAdapter(void) { }
	
};


typedef System::TMetaClass* TdxSpellCheckerCheckAsYouTypeEditAdapterClass;

class DELPHICLASS TdxSpellCheckerCheckAsYouTypeViewInfoItem;
class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeViewInfoItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	bool FExcludeFromRegion;
	
public:
	__fastcall TdxSpellCheckerCheckAsYouTypeViewInfoItem(const System::Types::TRect &ABounds);
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property bool ExcludeFromRegion = {read=FExcludeFromRegion, write=FExcludeFromRegion, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCheckAsYouTypeViewInfoItem(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCheckAsYouTypeViewInfoList;
class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeViewInfoList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
private:
	HIDESBASE TdxSpellCheckerCheckAsYouTypeViewInfoItem* __fastcall GetItem(int Index);
	
public:
	void __fastcall AddItem(const System::Types::TRect &R);
	HRGN __fastcall CreateUpdateRegion(void);
	bool __fastcall FindItem(const System::Types::TRect &R, /* out */ TdxSpellCheckerCheckAsYouTypeViewInfoItem* &AItem);
	__property TdxSpellCheckerCheckAsYouTypeViewInfoItem* Items[int Index] = {read=GetItem};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxSpellCheckerCheckAsYouTypeViewInfoList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCheckAsYouTypeViewInfoList(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCheckAsYouTypeViewInfo;
class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxSpellCheckerCheckAsYouTypeViewInfoList* FRectsToDraw;
	TdxSpellCheckerCheckAsYouTypeViewInfoList* FRectsToErase;
	HRGN FUpdateRgn;
	void __fastcall AddWordToList(TdxSpellCheckerCheckAsYouTypeViewInfoList* AList, TdxSpellCheckerMisspelledWord* AWord);
	HRGN __fastcall GetUpdateRegion(void);
	
protected:
	void __fastcall DoChanged(void);
	void __fastcall FreeRegionHandle(void);
	
public:
	__fastcall virtual TdxSpellCheckerCheckAsYouTypeViewInfo(void);
	__fastcall virtual ~TdxSpellCheckerCheckAsYouTypeViewInfo(void);
	void __fastcall AddToDrawRegion(TdxSpellCheckerMisspelledWordList* const AList);
	void __fastcall AddToEraseRegion(TdxSpellCheckerMisspelledWordList* const AList);
	void __fastcall ClearRegions(void);
	__property TdxSpellCheckerCheckAsYouTypeViewInfoList* RectsToDraw = {read=FRectsToDraw};
	__property TdxSpellCheckerCheckAsYouTypeViewInfoList* RectsToErase = {read=FRectsToErase};
	__property HRGN UpdateRegion = {read=GetUpdateRegion};
};


class DELPHICLASS TdxSpellCheckerCheckAsYouTypeManager;
class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeMode : public Dxspellchecker::TdxSpellCheckerCustomCheckMode
{
	typedef Dxspellchecker::TdxSpellCheckerCustomCheckMode inherited;
	
private:
	TdxSpellCheckerCheckAsYouTypeThread* FCheckThread;
	TdxSpellCheckerSpelledWordList* FCorrectWords;
	TdxSpellCheckerCheckAsYouTypeCurrentWordInfo FCurrentWordInfo;
	int FCursorPosition;
	Vcl::Extctrls::TTimer* FDelayTimer;
	_RTL_CRITICAL_SECTION FLock;
	TdxSpellCheckerCheckAsYouTypeManager* FManager;
	TdxSpellCheckerMisspelledWordList* FMisspelledWords;
	int FSelectionLength;
	int FTypingPosition;
	TdxSpellCheckerCheckAsYouTypeViewInfo* FViewInfo;
	TdxSpellCheckerCheckAsYouTypeEditAdapter* __fastcall GetAdapter(void);
	TdxSpellCheckerPainter* __fastcall GetPainter(void);
	
protected:
	void __fastcall AddMisspelledWord(const System::WideString AWord);
	void __fastcall CalculateBounds(TdxSpellCheckerMisspelledWord* AWord);
	virtual bool __fastcall CanStartSpellingThread(void);
	virtual void __fastcall Changed(bool AFullRefresh);
	virtual Dxspellchecker::TdxSpellCheckerTextParserClass __fastcall GetParserClass(void);
	bool __fastcall GetSelectedMisspelledWord(/* out */ TdxSpellCheckerMisspelledWord* &AWord);
	virtual bool __fastcall InternalProcessWord(const System::WideString AWord);
	bool __fastcall IsInCurrentWordBounds(int APosition);
	virtual bool __fastcall IsValidWord(const System::WideString AWord);
	void __fastcall DelayTimerEvent(System::TObject* Sender);
	void __fastcall SelectionChanged(void);
	void __fastcall SetMisspelledWordInfo(TdxSpellCheckerMisspelledWord* AWord);
	void __fastcall StartSpellingThread(bool ADelayed)/* overload */;
	virtual void __fastcall StartSpellingThread(void)/* overload */;
	void __fastcall TextChanged(void);
	virtual void __fastcall UpdateByDictionary(Dxspellchecker::TdxCustomSpellCheckerDictionary* ADictionary);
	__property int CursorPosition = {read=FCursorPosition, nodefault};
	__property Vcl::Extctrls::TTimer* DelayTimer = {read=FDelayTimer};
	__property int SelectionLength = {read=FSelectionLength, nodefault};
	__property int TypingPosition = {read=FTypingPosition, nodefault};
	
public:
	__fastcall virtual TdxSpellCheckerCheckAsYouTypeMode(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker, Dxspellchecker::TdxSpellCheckerCustomEditAdapter* AAdapter);
	__fastcall virtual ~TdxSpellCheckerCheckAsYouTypeMode(void);
	virtual void __fastcall Add(void);
	virtual void __fastcall Change(const System::WideString AWord);
	virtual void __fastcall Delete(void);
	void __fastcall Draw(HDC DC);
	virtual void __fastcall IgnoreAll(void);
	void __fastcall InvalidateEditor(void);
	void __fastcall Lock(void);
	void __fastcall SpellingBegin(void);
	void __fastcall SpellingDone(bool AAborted);
	void __fastcall Unlock(void);
	__property TdxSpellCheckerCheckAsYouTypeEditAdapter* Adapter = {read=GetAdapter};
	__property TdxSpellCheckerCheckAsYouTypeThread* CheckThread = {read=FCheckThread};
	__property TdxSpellCheckerSpelledWordList* CorrectWords = {read=FCorrectWords};
	__property TdxSpellCheckerCheckAsYouTypeManager* Manager = {read=FManager};
	__property TdxSpellCheckerMisspelledWordList* MisspelledWords = {read=FMisspelledWords};
	__property TdxSpellCheckerPainter* Painter = {read=GetPainter};
	__property TdxSpellCheckerCheckAsYouTypeViewInfo* ViewInfo = {read=FViewInfo};
};


class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeManager : public Dxspellchecker::TdxSpellCheckerCustomCheckAsYouTypeManager
{
	typedef Dxspellchecker::TdxSpellCheckerCustomCheckAsYouTypeManager inherited;
	
private:
	Vcl::Menus::TPopupMenu* FInternalPopupMenu;
	TdxSpellCheckerMisspelledWord* FMisspelledItem;
	TdxSpellCheckerPainter* FPainter;
	TdxSpellCheckerCheckAsYouTypeEditAdapter* __fastcall GetAdapter(void);
	TdxSpellCheckerCheckAsYouTypeMode* __fastcall GetCheckMode(void);
	void __fastcall SetMisspelledItem(TdxSpellCheckerMisspelledWord* AValue);
	
protected:
	virtual bool __fastcall CanPopup(const System::Types::TPoint P);
	virtual void __fastcall CreateInternalPopupMenu(void);
	virtual void __fastcall CreateItems(Vcl::Menus::TPopupMenu* APopup, Cxclasses::TcxObjectList* AList);
	virtual void __fastcall DoActiveChanged(void);
	virtual void __fastcall DoFinalizeController(void);
	virtual void __fastcall DoOptionsChanged(void);
	virtual Dxspellchecker::TdxSpellCheckerCustomEditAdapterClass __fastcall GetAdapterClass(Vcl::Controls::TWinControl* AControl);
	virtual Dxspellchecker::TdxSpellCheckerCustomCheckModeClass __fastcall GetCheckModeClass(void);
	void __fastcall MenuItemClickHandler(System::TObject* ASender);
	void __fastcall RedrawEditor(void);
	virtual void __fastcall Reset(void);
	virtual void __fastcall SpellingOptionsChanged(void);
	virtual void __fastcall ValidateAdapter(void);
	__property Vcl::Menus::TPopupMenu* InternalPopupMenu = {read=FInternalPopupMenu, write=FInternalPopupMenu};
	
public:
	__fastcall virtual TdxSpellCheckerCheckAsYouTypeManager(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker);
	__fastcall virtual ~TdxSpellCheckerCheckAsYouTypeManager(void);
	virtual void __fastcall Refresh(bool AFullRefresh = false);
	virtual void __fastcall DrawMisspellings(Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall LayoutChanged(Vcl::Controls::TWinControl* AControl);
	virtual bool __fastcall QueryPopup(System::Classes::TComponent* APopup, const System::Types::TPoint P);
	virtual void __fastcall SelectionChanged(Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall TextChanged(Vcl::Controls::TWinControl* AControl);
	__property TdxSpellCheckerCheckAsYouTypeEditAdapter* Adapter = {read=GetAdapter};
	__property TdxSpellCheckerCheckAsYouTypeMode* CheckMode = {read=GetCheckMode};
	__property TdxSpellCheckerMisspelledWord* MisspelledItem = {read=FMisspelledItem, write=SetMisspelledItem};
	__property TdxSpellCheckerPainter* Painter = {read=FPainter};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckercheckasyoutype */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERCHECKASYOUTYPE)
using namespace Dxspellcheckercheckasyoutype;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckercheckasyoutypeHPP
