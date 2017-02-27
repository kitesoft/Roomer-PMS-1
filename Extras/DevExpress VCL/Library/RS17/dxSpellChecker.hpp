// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellChecker.pas' rev: 24.00 (Win32)

#ifndef DxspellcheckerHPP
#define DxspellcheckerHPP

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
#include <Winapi.RichEdit.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxRichEdit.hpp>	// Pascal unit
#include <dxSpellCheckerRules.hpp>	// Pascal unit
#include <dxSpellCheckerAlgorithms.hpp>	// Pascal unit
#include <dxHunspellTypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellchecker
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EdxSpellCheckerException;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxSpellCheckerException : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxSpellCheckerException(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxSpellCheckerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxSpellCheckerException(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxSpellCheckerException(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxSpellCheckerException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxSpellCheckerException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxSpellCheckerException(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxSpellCheckerException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxSpellCheckerException(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxSpellCheckerException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxSpellCheckerException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxSpellCheckerException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxSpellCheckerException(void) { }
	
};

#pragma pack(pop)

struct TdxSpellCheckerWordStruct;
typedef TdxSpellCheckerWordStruct *PdxSpellCheckerWordStruct;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxSpellCheckerWordStruct
{
public:
	unsigned Size;
	void *NextMetaphone;
	void *Next;
	unsigned Length;
};
#pragma pack(pop)


class DELPHICLASS TdxSpellCheckerPersistent;
class DELPHICLASS TdxCustomSpellChecker;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxCustomSpellChecker* FSpellChecker;
	
public:
	__fastcall virtual TdxSpellCheckerPersistent(TdxCustomSpellChecker* ASpellChecker);
	__property TdxCustomSpellChecker* SpellChecker = {read=FSpellChecker};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSpellCheckerPersistent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerSuggestion;
class DELPHICLASS TdxCustomSpellCheckerDictionary;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerSuggestion : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomSpellCheckerDictionary* FDictionary;
	int FDistance;
	System::WideString FWord;
	int FOrder;
	
public:
	__fastcall TdxSpellCheckerSuggestion(const System::WideString AWord, TdxCustomSpellCheckerDictionary* ADictionary, int ADistance);
	__property TdxCustomSpellCheckerDictionary* Dictionary = {read=FDictionary};
	__property int Distance = {read=FDistance, nodefault};
	__property System::WideString Word = {read=FWord, write=FWord};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerSuggestion(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerSuggestionList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerSuggestionList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSpellCheckerSuggestion* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSpellCheckerSuggestion* __fastcall GetItem(int Index);
	
public:
	HIDESBASE void __fastcall Add(const System::WideString AWord, TdxCustomSpellCheckerDictionary* ADictionary, int ADistance);
	HIDESBASE void __fastcall Assign(TdxSpellCheckerSuggestionList* ASuggestions);
	HIDESBASE void __fastcall Delete(int AIndex);
	void __fastcall FixCapitalization(const System::WideString AMask);
	HIDESBASE void __fastcall Insert(int AIndex, const System::WideString AWord, TdxCustomSpellCheckerDictionary* ADictionary, int ADistance);
	void __fastcall RemoveDuplicates(void);
	void __fastcall SortByDistance(void);
	void __fastcall SortByWord(void);
	void __fastcall SaveToStrings(System::Classes::TStrings* AStrings);
	__property TdxSpellCheckerSuggestion* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxSpellCheckerSuggestionList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerSuggestionList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerSuggestionCacheItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerSuggestionCacheItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FRefCount;
	System::WideString FWord;
	TdxSpellCheckerSuggestionList* FSuggestions;
	
protected:
	__property int RefCount = {read=FRefCount, nodefault};
	__property System::WideString Word = {read=FWord};
	
public:
	__fastcall TdxSpellCheckerSuggestionCacheItem(const System::WideString AWord, TdxSpellCheckerSuggestionList* ASuggestions);
	__fastcall virtual ~TdxSpellCheckerSuggestionCacheItem(void);
	void __fastcall GetSuggestions(TdxSpellCheckerSuggestionList* ASuggestions);
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerSuggestionCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerSuggestionCache : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSpellCheckerSuggestionCacheItem* operator[](int Index) { return Items[Index]; }
	
private:
	int FMaxCapacity;
	HIDESBASE TdxSpellCheckerSuggestionCacheItem* __fastcall GetItem(int Index);
	int __fastcall GetRareItemIndex(void);
	
protected:
	TdxSpellCheckerSuggestionCacheItem* __fastcall Find(const System::WideString AWord);
	
public:
	__fastcall TdxSpellCheckerSuggestionCache(int AMaxCapacity);
	HIDESBASE void __fastcall Add(const System::WideString AWord, TdxSpellCheckerSuggestionList* ASuggestions);
	bool __fastcall GetSuggestions(const System::WideString AWord, TdxSpellCheckerSuggestionList* ASuggestions);
	void __fastcall Reset(void);
	__property TdxSpellCheckerSuggestionCacheItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerSuggestionCache(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerReplacement;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerReplacement : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::WideString FReplacement;
	System::WideString FText;
	
public:
	__fastcall TdxSpellCheckerReplacement(const System::WideString AText, const System::WideString AReplacement);
	void __fastcall ChangeReplacement(const System::WideString S);
	__property System::WideString Replacement = {read=FReplacement};
	__property System::WideString Text = {read=FText};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerReplacement(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerReplacementList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerReplacementList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSpellCheckerReplacement* operator[](int Index) { return Items[Index]; }
	
private:
	bool FAllowDuplicates;
	HIDESBASE TdxSpellCheckerReplacement* __fastcall GetItem(int Index);
	
public:
	__fastcall TdxSpellCheckerReplacementList(bool AllowDuplicates);
	HIDESBASE void __fastcall Add(const System::WideString AText, const System::WideString AReplacement);
	TdxSpellCheckerReplacement* __fastcall FindReplacement(const System::WideString AText);
	void __fastcall SortByText(void);
	__property TdxSpellCheckerReplacement* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerReplacementList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerCustomEditAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomEditAdapter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	Vcl::Controls::TWinControl* FEdit;
	bool FNeedImmediatePost;
	int FSelStart;
	int FSelLength;
	System::WideString FText;
	bool __fastcall EditorHandleAllocated(void);
	virtual NativeUInt __fastcall GetEditorHandle(void);
	virtual bool __fastcall GetHideSelection(void) = 0 ;
	virtual bool __fastcall GetReadOnly(void) = 0 ;
	virtual int __fastcall GetSelLength(void) = 0 ;
	virtual int __fastcall GetSelStart(void) = 0 ;
	virtual System::UnicodeString __fastcall GetSelText(void) = 0 ;
	virtual System::WideString __fastcall GetText(void);
	virtual void __fastcall Post(bool AUpdateValue = true);
	virtual void __fastcall SetHideSelection(bool AValue) = 0 ;
	virtual void __fastcall SetSelLength(int AValue) = 0 ;
	virtual void __fastcall SetSelStart(int AValue) = 0 ;
	virtual void __fastcall SetSelText(const System::UnicodeString AValue) = 0 ;
	bool __fastcall IsInplace(void);
	
public:
	__fastcall virtual TdxSpellCheckerCustomEditAdapter(Vcl::Controls::TWinControl* AEdit);
	virtual void __fastcall ClearSelection(void);
	virtual void __fastcall GetSpellingBounds(/* out */ int &ASpellingStart, /* out */ int &ASpellingEnd);
	__property Vcl::Controls::TWinControl* Edit = {read=FEdit};
	__property NativeUInt EditorHandle = {read=GetEditorHandle, nodefault};
	__property bool HideSelection = {read=GetHideSelection, write=SetHideSelection, nodefault};
	__property bool ReadOnly = {read=GetReadOnly, nodefault};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property System::UnicodeString SelText = {read=GetSelText, write=SetSelText};
	__property System::WideString Text = {read=GetText};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCustomEditAdapter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxSpellCheckerCustomEditAdapterClass;

class DELPHICLASS TdxSpellCheckercxTextEditAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckercxTextEditAdapter : public TdxSpellCheckerCustomEditAdapter
{
	typedef TdxSpellCheckerCustomEditAdapter inherited;
	
private:
	Cxtextedit::TcxCustomTextEdit* __fastcall GetEdit(void);
	
protected:
	virtual bool __fastcall GetHideSelection(void);
	virtual bool __fastcall GetReadOnly(void);
	virtual int __fastcall GetSelLength(void);
	virtual int __fastcall GetSelStart(void);
	virtual System::UnicodeString __fastcall GetSelText(void);
	virtual void __fastcall SetHideSelection(bool AValue);
	virtual void __fastcall SetSelLength(int AValue);
	virtual void __fastcall SetSelStart(int AValue);
	virtual void __fastcall SetSelText(const System::UnicodeString AValue);
	__property Cxtextedit::TcxCustomTextEdit* Edit = {read=GetEdit};
public:
	/* TdxSpellCheckerCustomEditAdapter.Create */ inline __fastcall virtual TdxSpellCheckercxTextEditAdapter(Vcl::Controls::TWinControl* AEdit) : TdxSpellCheckerCustomEditAdapter(AEdit) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckercxTextEditAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckercxRichEditAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckercxRichEditAdapter : public TdxSpellCheckercxTextEditAdapter
{
	typedef TdxSpellCheckercxTextEditAdapter inherited;
	
protected:
	virtual System::WideString __fastcall GetText(void);
public:
	/* TdxSpellCheckerCustomEditAdapter.Create */ inline __fastcall virtual TdxSpellCheckercxRichEditAdapter(Vcl::Controls::TWinControl* AEdit) : TdxSpellCheckercxTextEditAdapter(AEdit) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckercxRichEditAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerEditAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerEditAdapter : public TdxSpellCheckerCustomEditAdapter
{
	typedef TdxSpellCheckerCustomEditAdapter inherited;
	
private:
	Vcl::Stdctrls::TCustomEdit* __fastcall GetEdit(void);
	
protected:
	virtual bool __fastcall GetHideSelection(void);
	virtual bool __fastcall GetReadOnly(void);
	virtual int __fastcall GetSelLength(void);
	virtual int __fastcall GetSelStart(void);
	virtual System::UnicodeString __fastcall GetSelText(void);
	virtual void __fastcall SetHideSelection(bool AValue);
	virtual void __fastcall SetSelLength(int AValue);
	virtual void __fastcall SetSelStart(int AValue);
	virtual void __fastcall SetSelText(const System::UnicodeString AValue);
	__property Vcl::Stdctrls::TCustomEdit* Edit = {read=GetEdit};
public:
	/* TdxSpellCheckerCustomEditAdapter.Create */ inline __fastcall virtual TdxSpellCheckerEditAdapter(Vcl::Controls::TWinControl* AEdit) : TdxSpellCheckerCustomEditAdapter(AEdit) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerEditAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerRichEditAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerRichEditAdapter : public TdxSpellCheckerEditAdapter
{
	typedef TdxSpellCheckerEditAdapter inherited;
	
protected:
	virtual System::WideString __fastcall GetText(void);
public:
	/* TdxSpellCheckerCustomEditAdapter.Create */ inline __fastcall virtual TdxSpellCheckerRichEditAdapter(Vcl::Controls::TWinControl* AEdit) : TdxSpellCheckerEditAdapter(AEdit) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerRichEditAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerTextAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerTextAdapter : public TdxSpellCheckerEditAdapter
{
	typedef TdxSpellCheckerEditAdapter inherited;
	
public:
	__fastcall virtual TdxSpellCheckerTextAdapter(const System::WideString AText);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerTextAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerSingleWordParser;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerSingleWordParser : public Dxspellcheckerrules::TdxCustomSpellCheckerTextHelper
{
	typedef Dxspellcheckerrules::TdxCustomSpellCheckerTextHelper inherited;
	
private:
	TdxCustomSpellChecker* FSpellChecker;
	
protected:
	__property TdxCustomSpellChecker* SpellChecker = {read=FSpellChecker};
	
public:
	__fastcall virtual TdxSpellCheckerSingleWordParser(TdxCustomSpellChecker* ASpellChecker);
	virtual System::WideString __fastcall GetPrevWord(void);
	virtual bool __fastcall WordExists(const System::WideString AWord);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerSingleWordParser(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TdxSpellCheckerSentence
{
public:
	int StartTextPosition;
	int StartWordPosition;
	System::WideString Text;
};


class DELPHICLASS TdxSpellCheckerTextParser;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerTextParser : public TdxSpellCheckerSingleWordParser
{
	typedef TdxSpellCheckerSingleWordParser inherited;
	
private:
	bool __fastcall LastWideCharIsSpace(const System::WideString S);
	
protected:
	System::WideString FDelimiters;
	System::WideString FMeaningfulCharacters;
	System::WideString FPrevWord;
	int FSpellingEnd;
	int FSpellingStart;
	System::WideString FText;
	System::WideString FUrlDelimiters;
	bool __fastcall IsDelimiter(System::WideChar AChar);
	bool __fastcall IsMeaningfulCharacters(System::WideChar AChar);
	bool __fastcall IsUrlDelimiter(System::WideChar AChar);
	virtual void __fastcall UpdateTextInfo(TdxSpellCheckerCustomEditAdapter* AAdapter);
	
public:
	__fastcall virtual TdxSpellCheckerTextParser(TdxCustomSpellChecker* ASpellChecker);
	virtual System::WideString __fastcall GetNextWord(int &AStart, int &ALength, /* out */ System::WideString &ADelimiters);
	virtual System::WideString __fastcall GetPrevWord(void);
	bool __fastcall GetNextDelimiterPosition(int &AStart, int ADirection);
	virtual TdxSpellCheckerSentence __fastcall GetSentence(int APos);
	virtual TdxSpellCheckerSuggestionList* __fastcall GetSuggestions(const System::WideString AWord);
	void __fastcall UpdateMeaningfulCharacters(void);
	__property System::WideString Delimiters = {read=FDelimiters, write=FDelimiters};
	__property System::WideString MeaningfulCharacters = {read=FMeaningfulCharacters};
	__property System::WideString Text = {read=FText};
	__property System::WideString UrlDelimiters = {read=FUrlDelimiters, write=FUrlDelimiters};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerTextParser(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxSpellCheckerTextParserClass;

class DELPHICLASS TdxSpellCheckerUndoItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerUndoItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::WideString FMisspelledWord;
	int FMisspelledWordPosition;
	System::WideString FPrevWord;
	System::WideString FReplacement;
	
public:
	__fastcall TdxSpellCheckerUndoItem(const System::WideString AMisspelledWord, const System::WideString AReplacement, const System::WideString APrevWord, int AMisspelledWordPosition);
	__property System::WideString MisspelledWord = {read=FMisspelledWord};
	__property int MisspelledWordPosition = {read=FMisspelledWordPosition, nodefault};
	__property System::WideString PrevWord = {read=FPrevWord};
	__property System::WideString Replacement = {read=FReplacement};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerUndoItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerUndoManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerUndoManager : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TdxSpellCheckerUndoItem* operator[](int Index) { return Items[Index]; }
	
private:
	Cxclasses::TcxObjectList* FUndoList;
	int __fastcall GetCount(void);
	TdxSpellCheckerUndoItem* __fastcall GetItem(int Index);
	TdxSpellCheckerUndoItem* __fastcall GetLast(void);
	
public:
	__fastcall TdxSpellCheckerUndoManager(void);
	__fastcall virtual ~TdxSpellCheckerUndoManager(void);
	void __fastcall Add(const System::WideString AMisspelledWord, const System::WideString AReplacement, const System::WideString APrevWord, int AMisspelledWordPosition);
	void __fastcall UndoLast(void);
	__property int Count = {read=GetCount, nodefault};
	__property TdxSpellCheckerUndoItem* Last = {read=GetLast};
	__property TdxSpellCheckerUndoItem* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerCustomCheckMode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomCheckMode : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxSpellCheckerCustomEditAdapter* FAdapter;
	TdxSpellCheckerTextParser* FParser;
	TdxCustomSpellChecker* FSpellChecker;
	int FSpellingEnd;
	int FSpellingStart;
	System::WideString __fastcall GetPrevWord(void);
	void __fastcall SetPrevWord(const System::WideString AValue);
	void __fastcall SetSpellingEnd(const int AValue);
	void __fastcall SetSpellingStart(const int AValue);
	
protected:
	Dxspellcheckerrules::TdxSpellCheckerSpellingCode FLastCode;
	int FMisspellingLen;
	int FMisspellingStart;
	System::WideString FMisspelledWord;
	virtual Dxspellcheckerrules::TdxSpellCheckerSpellingCode __fastcall CheckWord(const System::WideString AWord);
	virtual void __fastcall CreateParser(void);
	virtual bool __fastcall GetNextWord(/* out */ System::WideString &AWord);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual TdxSpellCheckerTextParserClass __fastcall GetParserClass(void);
	virtual Dxspellcheckerrules::TdxSpellCheckerSpellingCode __fastcall InternalCheckWord(System::WideString &AWord);
	virtual bool __fastcall InternalProcessWord(const System::WideString AWord);
	virtual bool __fastcall IsNeedChangeWord(const System::WideString AWord, /* out */ System::WideString &AReplacement);
	virtual bool __fastcall IsNeedDeleteWord(const System::WideString AWord);
	virtual bool __fastcall IsNeedIgnoreWord(const System::WideString AWord);
	virtual bool __fastcall IsValidWord(const System::WideString AWord);
	virtual void __fastcall RestoreSelection(void);
	virtual void __fastcall StoreSelection(void);
	virtual void __fastcall SelectMisspelledWord(void);
	virtual void __fastcall SelectMisspelledWordAfterUndo(void);
	virtual void __fastcall UpdateByDictionary(TdxCustomSpellCheckerDictionary* ADictionary);
	virtual void __fastcall UpdateSpellingBounds(int ADelta);
	virtual void __fastcall UpdateTextInfo(void);
	virtual void __fastcall ValidateSpellingBounds(void);
	__property System::WideString PrevWord = {read=GetPrevWord, write=SetPrevWord};
	__property int SpellingEnd = {read=FSpellingEnd, write=SetSpellingEnd, nodefault};
	__property int SpellingStart = {read=FSpellingStart, write=SetSpellingStart, nodefault};
	
public:
	__fastcall virtual TdxSpellCheckerCustomCheckMode(TdxCustomSpellChecker* AOwner, TdxSpellCheckerCustomEditAdapter* AAdapter);
	__fastcall virtual ~TdxSpellCheckerCustomCheckMode(void);
	virtual void __fastcall Add(void);
	virtual bool __fastcall CanUndo(void);
	virtual void __fastcall Change(const System::WideString AWord);
	virtual void __fastcall ChangeAll(const System::WideString AWord);
	virtual void __fastcall Delete(void);
	virtual void __fastcall DeleteAll(void);
	virtual TdxSpellCheckerSuggestionList* __fastcall GetSuggestions(const System::WideString AWord);
	virtual bool __fastcall GetNextMisspelledWord(void);
	virtual void __fastcall Ignore(void);
	virtual void __fastcall IgnoreAll(void);
	virtual void __fastcall UndoLast(void);
	__property TdxSpellCheckerCustomEditAdapter* Adapter = {read=FAdapter};
	__property Dxspellcheckerrules::TdxSpellCheckerSpellingCode LastCode = {read=FLastCode, nodefault};
	__property System::WideString MisspelledWord = {read=FMisspelledWord};
	__property TdxSpellCheckerTextParser* Parser = {read=FParser};
	__property TdxCustomSpellChecker* SpellChecker = {read=FSpellChecker};
};

#pragma pack(pop)

typedef System::TMetaClass* TdxSpellCheckerCustomCheckModeClass;

class DELPHICLASS TdxSpellCheckerDialogCheckMode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerDialogCheckMode : public TdxSpellCheckerCustomCheckMode
{
	typedef TdxSpellCheckerCustomCheckMode inherited;
	
private:
	int FCheckedRange;
	bool FSaveHideSelection;
	int FSaveSelLength;
	int FSaveSelStart;
	bool FSelectionChecked;
	TdxSpellCheckerUndoManager* FUndoManager;
	
protected:
	virtual void __fastcall CreateParser(void);
	virtual bool __fastcall IsCheckingSelectedText(void);
	virtual void __fastcall RestoreSelection(void);
	virtual void __fastcall StoreSelection(void);
	virtual void __fastcall ValidateSpellingBounds(void);
	void __fastcall ValidateSpellingBoundsAfterUndo(void);
	__property TdxSpellCheckerUndoManager* UndoManager = {read=FUndoManager};
	
public:
	__fastcall virtual TdxSpellCheckerDialogCheckMode(TdxCustomSpellChecker* AOwner, TdxSpellCheckerCustomEditAdapter* AAdapter);
	__fastcall virtual ~TdxSpellCheckerDialogCheckMode(void);
	virtual bool __fastcall CanUndo(void);
	virtual void __fastcall Change(const System::WideString AWord);
	virtual void __fastcall Delete(void);
	virtual void __fastcall Ignore(void);
	virtual int __fastcall ShowDialog(void);
	virtual void __fastcall UndoLast(void);
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerOutlookCheckMode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerOutlookCheckMode : public TdxSpellCheckerDialogCheckMode
{
	typedef TdxSpellCheckerDialogCheckMode inherited;
	
protected:
	virtual void __fastcall SelectMisspelledWordAfterUndo(void);
	
public:
	virtual int __fastcall ShowDialog(void);
public:
	/* TdxSpellCheckerDialogCheckMode.Create */ inline __fastcall virtual TdxSpellCheckerOutlookCheckMode(TdxCustomSpellChecker* AOwner, TdxSpellCheckerCustomEditAdapter* AAdapter) : TdxSpellCheckerDialogCheckMode(AOwner, AAdapter) { }
	/* TdxSpellCheckerDialogCheckMode.Destroy */ inline __fastcall virtual ~TdxSpellCheckerOutlookCheckMode(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerWordCheckMode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerWordCheckMode : public TdxSpellCheckerDialogCheckMode
{
	typedef TdxSpellCheckerDialogCheckMode inherited;
	
private:
	TdxSpellCheckerSentence __fastcall GetMisspelledSentence(void);
	
protected:
	virtual void __fastcall SelectMisspelledWordAfterUndo(void);
	
public:
	virtual void __fastcall ChangeSentence(const System::WideString ASentence);
	virtual int __fastcall ShowDialog(void);
	__property TdxSpellCheckerSentence MisspelledSentence = {read=GetMisspelledSentence};
public:
	/* TdxSpellCheckerDialogCheckMode.Create */ inline __fastcall virtual TdxSpellCheckerWordCheckMode(TdxCustomSpellChecker* AOwner, TdxSpellCheckerCustomEditAdapter* AAdapter) : TdxSpellCheckerDialogCheckMode(AOwner, AAdapter) { }
	/* TdxSpellCheckerDialogCheckMode.Destroy */ inline __fastcall virtual ~TdxSpellCheckerWordCheckMode(void) { }
	
};

#pragma pack(pop)

typedef System::StaticArray<System::WideChar *, 65536> TdxMetaphoneTable;

typedef TdxMetaphoneTable *PdxMetaphoneTable;

class DELPHICLASS TdxSpellCheckerWordList;
class DELPHICLASS TdxSpellCheckerSuggestionBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerWordList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCount;
	bool FFindMostValidCapitalizationInDuplicates;
	unsigned FLangID;
	_RTL_CRITICAL_SECTION FLock;
	Dxspellcheckeralgorithms::TdxDoubleMetaphone* FMetaphone;
	TdxMetaphoneTable *FMetaphoneTable;
	Dxhunspelltypes::TdxPWideCharArray *FTable;
	int FTableSize;
	System::StaticArray<System::WideChar, 257> FUpperCaseBuffer;
	bool FUseDoubleMetaphone;
	unsigned __fastcall GetCodePage(void);
	void * __fastcall GetWordStruct(System::WideChar * AWord);
	void __fastcall InitMetaphoneTable(void);
	void __fastcall SetUseDoubleMetaphone(bool AValue);
	void __fastcall UpdateMetaphoneInfo(System::WideChar * ANewWord, int ALength);
	void __fastcall UpdateWordsMetaphone(void);
	
protected:
	int __fastcall ElfHash(System::WideChar * P, int ALength);
	System::WideChar * __fastcall FindWord(const System::WideString S);
	System::WideChar * __fastcall NewWord(System::WideChar * S, int ALength);
	System::WideChar * __fastcall AllocWord(unsigned ACharCount);
	void __fastcall DisposeWord(System::WideChar * AWord);
	void * __fastcall GetNextMetaphoneWord(System::WideChar * AWord);
	void * __fastcall GetNextWord(System::WideChar * AWord);
	void __fastcall SetNextMetaphoneWord(System::WideChar * AWord, void * AValue);
	void __fastcall SetNextWord(System::WideChar * AWord, void * AValue);
	int __fastcall WordLength(System::WideChar * AWord);
	__property unsigned CodePage = {read=GetCodePage, nodefault};
	
public:
	__fastcall TdxSpellCheckerWordList(unsigned ALangID, int ATableSize);
	__fastcall virtual ~TdxSpellCheckerWordList(void);
	void __fastcall Add(const System::WideString S);
	void __fastcall Clear(void);
	bool __fastcall Find(const System::WideString S);
	void __fastcall LoadFromStrings(System::Classes::TStrings* AStrings);
	void __fastcall PopulateMetaphoneSuggestions(TdxSpellCheckerSuggestionBuilder* ASuggestionBuilder, const System::WideString AWord);
	void __fastcall SaveToStrings(System::Classes::TStrings* AStrings);
	__property int Count = {read=FCount, nodefault};
	__property bool FindMostValidCapitalizationInDuplicates = {read=FFindMostValidCapitalizationInDuplicates, write=FFindMostValidCapitalizationInDuplicates, nodefault};
	__property unsigned LangID = {read=FLangID, write=FLangID, nodefault};
	__property bool UseDoubleMetaphone = {read=FUseDoubleMetaphone, write=SetUseDoubleMetaphone, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerSuggestionBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FStartTicks;
	System::WideString FAlphabet;
	TdxCustomSpellCheckerDictionary* FDictionary;
	TdxSpellCheckerSuggestionList* FSuggestions;
	System::WideString FWord;
	System::WideString FOriginalWord;
	unsigned __fastcall GetTimeout(void);
	void __fastcall SetAlphabet(const System::WideString AValue);
	int __fastcall GetMaxDistance(void);
	Dxspellcheckeralgorithms::TdxStringSimilarityCalculator* __fastcall GetSimilarity(void);
	
protected:
	virtual bool __fastcall CanAddToSuggestions(const System::WideString ATestWord);
	void __fastcall CheckAddMetaphoneSuggestion(System::WideChar * ATestWord, System::WideChar * AUpperWord1, int AUpperWordLen1, System::WideChar * AUpperWord2, int AUpperWordLen2);
	void __fastcall PopulateCapitalizationSuggestions(void);
	virtual void __fastcall DoAddMetaphoneSuggestions(void);
	virtual void __fastcall DoAddSuggestions(void);
	virtual bool __fastcall IsCaseSensitive(void);
	bool __fastcall IsTimeOut(void);
	virtual System::WideString __fastcall PrepareWord(const System::WideString AWord);
	__property System::WideString Alphabet = {read=FAlphabet, write=SetAlphabet};
	__property TdxCustomSpellCheckerDictionary* Dictionary = {read=FDictionary};
	__property int MaxDistance = {read=GetMaxDistance, nodefault};
	__property Dxspellcheckeralgorithms::TdxStringSimilarityCalculator* Similarity = {read=GetSimilarity};
	__property TdxSpellCheckerSuggestionList* Suggestions = {read=FSuggestions, write=FSuggestions};
	__property unsigned Timeout = {read=GetTimeout, nodefault};
	__property System::WideString Word = {read=FWord, write=FWord};
	
public:
	__fastcall virtual TdxSpellCheckerSuggestionBuilder(TdxCustomSpellCheckerDictionary* ADictionary);
	virtual void __fastcall AddSuggestions(const System::WideString AWord, TdxSpellCheckerSuggestionList* ASuggestions);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerSuggestionBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNearMissStrategy;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNearMissStrategy : public TdxSpellCheckerSuggestionBuilder
{
	typedef TdxSpellCheckerSuggestionBuilder inherited;
	
protected:
	void __fastcall CheckAddToSuggestions(const System::WideString ATestWord);
	void __fastcall CheckChangeOneLetter(void);
	void __fastcall CheckDeleteLetter(void);
	void __fastcall CheckDoubleTwoChars(void);
	void __fastcall CheckInsertLetter(void);
	void __fastcall CheckInsertSpace(void);
	void __fastcall CheckMoveChar(void);
	virtual void __fastcall DoAddSuggestions(void);
	void __fastcall InterchangeTwoLetters(void);
	void __fastcall LongInterchangeTwoLetters(void);
public:
	/* TdxSpellCheckerSuggestionBuilder.Create */ inline __fastcall virtual TdxNearMissStrategy(TdxCustomSpellCheckerDictionary* ADictionary) : TdxSpellCheckerSuggestionBuilder(ADictionary) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNearMissStrategy(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxDictionaryLoadThread;
class PASCALIMPLEMENTATION TdxDictionaryLoadThread : public Cxclasses::TcxThread
{
	typedef Cxclasses::TcxThread inherited;
	
private:
	TdxCustomSpellCheckerDictionary* FDictionary;
	bool FFinished;
	
protected:
	virtual void __fastcall Execute(void);
	__property TdxCustomSpellCheckerDictionary* Dictionary = {read=FDictionary};
	
public:
	__fastcall TdxDictionaryLoadThread(TdxCustomSpellCheckerDictionary* ADictionary);
	bool __fastcall IsLoadComplete(void);
	__property bool Finished = {read=FFinished, nodefault};
public:
	/* TcxThread.Destroy */ inline __fastcall virtual ~TdxDictionaryLoadThread(void) { }
	
};


typedef void __fastcall (__closure *TdxSpellCheckerDictionaryLoadingEvent)(TdxCustomSpellCheckerDictionary* Sender, bool &AHandled);

typedef void __fastcall (__closure *TdxSpellCheckerDictionaryLoadedEvent)(TdxCustomSpellCheckerDictionary* Sender);

enum TdxSpellCheckerDictionaryLoadMode : unsigned char { dlmDefault, dlmDirectLoad, dlmThreadedLoad };

class PASCALIMPLEMENTATION TdxCustomSpellCheckerDictionary : public TdxSpellCheckerPersistent
{
	typedef TdxSpellCheckerPersistent inherited;
	
private:
	System::WideString FAlphabet;
	unsigned FCodePage;
	bool FEnabled;
	unsigned FLanguage;
	bool FLoaded;
	TdxDictionaryLoadThread* FLoadThread;
	bool FTerminated;
	unsigned FTimeout;
	TdxSpellCheckerDictionaryLoadingEvent FOnLoading;
	TdxSpellCheckerDictionaryLoadedEvent FOnLoaded;
	bool __fastcall GetActive(void);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetCodePage(unsigned AValue);
	void __fastcall SetLanguage(const unsigned AValue);
	
protected:
	virtual bool __fastcall CanLoad(void);
	virtual bool __fastcall CanUseDoubleMetaphone(void);
	virtual void __fastcall Cleanup(void);
	virtual TdxSpellCheckerSuggestionBuilder* __fastcall CreateSuggestionBuilder(void);
	virtual void __fastcall DirectLoad(void);
	virtual void __fastcall DoActivate(void);
	virtual bool __fastcall DoLoad(void);
	virtual void __fastcall DoLoadedEvent(void);
	virtual bool __fastcall DoLoadingEvent(void);
	virtual bool __fastcall DoUnload(void);
	virtual void __fastcall FreeContent(void);
	virtual System::WideString __fastcall GetActiveAlphabet(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual void __fastcall InitializeContent(void);
	bool __fastcall IsEnglishLanguage(void);
	virtual void __fastcall LanguageChanged(void);
	virtual void __fastcall LoadingComplete(void);
	bool __fastcall LoadingTerminated(void);
	virtual void __fastcall LoadUsingThread(void);
	virtual void __fastcall PopulateCapitalizationSuggestions(TdxSpellCheckerSuggestionBuilder* ASuggestionBuilder, const System::WideString AWord);
	virtual void __fastcall PopulateMetaphoneSuggestions(TdxSpellCheckerSuggestionBuilder* ASuggestionBuilder, const System::WideString AWord);
	void __fastcall Reload(void);
	void __fastcall Terminate(void);
	virtual void __fastcall ThreadDone(System::TObject* Sender);
	virtual void __fastcall Update(void);
	void __fastcall UpdateLoadedOnLoadEvent(void);
	virtual void __fastcall UpdateUsingMetaphone(void);
	virtual void __fastcall UpdateWordChars(System::WideString &AWordChars);
	__property TdxDictionaryLoadThread* LoadThread = {read=FLoadThread};
	__property unsigned Timeout = {read=FTimeout, write=FTimeout, nodefault};
	
public:
	__fastcall virtual TdxCustomSpellCheckerDictionary(TdxCustomSpellChecker* ASpellChecker);
	__fastcall virtual ~TdxCustomSpellCheckerDictionary(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Activate(void);
	virtual bool __fastcall HasWord(const System::WideString AWord);
	void __fastcall Clear(void);
	void __fastcall Load(TdxSpellCheckerDictionaryLoadMode AMode = (TdxSpellCheckerDictionaryLoadMode)(0x0));
	void __fastcall Unload(void);
	__property bool Active = {read=GetActive, nodefault};
	__property System::WideString Alphabet = {read=FAlphabet, write=FAlphabet};
	__property unsigned CodePage = {read=FCodePage, write=SetCodePage, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property unsigned Language = {read=FLanguage, write=SetLanguage, default=0};
	__property bool Loaded = {read=FLoaded, nodefault};
	__property TdxSpellCheckerDictionaryLoadedEvent OnLoaded = {read=FOnLoaded, write=FOnLoaded};
	__property TdxSpellCheckerDictionaryLoadingEvent OnLoading = {read=FOnLoading, write=FOnLoading};
};


typedef System::TMetaClass* TdxCustomSpellCheckerDictionaryClass;

class DELPHICLASS TdxSpellCheckerDictionary;
class PASCALIMPLEMENTATION TdxSpellCheckerDictionary : public TdxCustomSpellCheckerDictionary
{
	typedef TdxCustomSpellCheckerDictionary inherited;
	
private:
	bool FCheckCapitalization;
	TdxSpellCheckerWordList* FWords;
	int __fastcall GetWordCount(void);
	void __fastcall SetCheckCapitalization(bool AValue);
	
protected:
	virtual bool __fastcall CanUseDoubleMetaphone(void);
	virtual void __fastcall Cleanup(void);
	virtual bool __fastcall DoUnload(void);
	virtual void __fastcall FreeContent(void);
	virtual void __fastcall InitializeContent(void);
	virtual bool __fastcall IsCorrectCapitalization(const System::WideString AWord, const System::WideString APattern);
	virtual void __fastcall LanguageChanged(void);
	virtual void __fastcall PopulateCapitalizationSuggestions(TdxSpellCheckerSuggestionBuilder* ASuggestionBuilder, const System::WideString AWord);
	virtual void __fastcall PopulateMetaphoneSuggestions(TdxSpellCheckerSuggestionBuilder* ASuggestionBuilder, const System::WideString AWord);
	virtual void __fastcall UpdateUsingMetaphone(void);
	__property TdxSpellCheckerWordList* Words = {read=FWords};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall HasWord(const System::WideString AWord);
	__property Active;
	__property Alphabet = {default=0};
	__property bool CheckCapitalization = {read=FCheckCapitalization, write=SetCheckCapitalization, default=0};
	__property CodePage = {default=0};
	__property Enabled = {default=1};
	__property Language = {default=0};
	__property Loaded;
	__property int WordCount = {read=GetWordCount, nodefault};
	__property OnLoaded;
	__property OnLoading;
public:
	/* TdxCustomSpellCheckerDictionary.Create */ inline __fastcall virtual TdxSpellCheckerDictionary(TdxCustomSpellChecker* ASpellChecker) : TdxCustomSpellCheckerDictionary(ASpellChecker) { }
	/* TdxCustomSpellCheckerDictionary.Destroy */ inline __fastcall virtual ~TdxSpellCheckerDictionary(void) { }
	
};


enum TdxUserSpellCheckerDictionaryOption : unsigned char { udFileMustExist, udSaveOnUnload };

typedef System::Set<TdxUserSpellCheckerDictionaryOption, TdxUserSpellCheckerDictionaryOption::udFileMustExist, TdxUserSpellCheckerDictionaryOption::udSaveOnUnload>  TdxUserSpellCheckerDictionaryOptions;

class DELPHICLASS TdxUserSpellCheckerDictionary;
class PASCALIMPLEMENTATION TdxUserSpellCheckerDictionary : public TdxSpellCheckerDictionary
{
	typedef TdxSpellCheckerDictionary inherited;
	
private:
	System::Sysutils::TFileName FDictionaryPath;
	TdxUserSpellCheckerDictionaryOptions FOptions;
	
protected:
	virtual bool __fastcall DoLoad(void);
	virtual bool __fastcall DoUnload(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	
public:
	__fastcall virtual TdxUserSpellCheckerDictionary(TdxCustomSpellChecker* ASpellChecker);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddWord(const System::WideString AWord);
	void __fastcall LoadFromStrings(System::Classes::TStrings* AStrings);
	void __fastcall SaveToStrings(System::Classes::TStrings* AStrings);
	
__published:
	__property Alphabet = {default=0};
	__property CheckCapitalization = {default=0};
	__property CodePage = {default=0};
	__property Enabled = {default=1};
	__property System::Sysutils::TFileName DictionaryPath = {read=FDictionaryPath, write=FDictionaryPath};
	__property TdxUserSpellCheckerDictionaryOptions Options = {read=FOptions, write=FOptions, default=2};
	__property OnLoaded;
	__property OnLoading;
public:
	/* TdxCustomSpellCheckerDictionary.Destroy */ inline __fastcall virtual ~TdxUserSpellCheckerDictionary(void) { }
	
};


class DELPHICLASS TdxSpellCheckerDictionaryItem;
class DELPHICLASS TdxSpellCheckerDictionaries;
class PASCALIMPLEMENTATION TdxSpellCheckerDictionaryItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TdxCustomSpellCheckerDictionary* FDictionaryType;
	TdxCustomSpellCheckerDictionaryClass FDictionaryTypeClass;
	System::Classes::TNotifyEvent FDictionaryEvents;
	TdxSpellCheckerDictionaries* __fastcall GetCollection(void);
	System::UnicodeString __fastcall GetDictionaryTypeClassName(void);
	void __fastcall SetDictionaryType(TdxCustomSpellCheckerDictionary* AValue);
	void __fastcall SetDictionaryTypeClassName(const System::UnicodeString AValue);
	void __fastcall SetDictionaryTypeClass(TdxCustomSpellCheckerDictionaryClass AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	void __fastcall RecreateDictionaryType(void);
	
public:
	__fastcall virtual ~TdxSpellCheckerDictionaryItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxSpellCheckerDictionaries* Collection = {read=GetCollection};
	__property TdxCustomSpellCheckerDictionaryClass DictionaryTypeClass = {read=FDictionaryTypeClass, write=SetDictionaryTypeClass};
	
__published:
	__property System::UnicodeString DictionaryTypeClassName = {read=GetDictionaryTypeClassName, write=SetDictionaryTypeClassName};
	__property TdxCustomSpellCheckerDictionary* DictionaryType = {read=FDictionaryType, write=SetDictionaryType};
	__property System::Classes::TNotifyEvent DictionaryEvents = {read=FDictionaryEvents, write=FDictionaryEvents};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TdxSpellCheckerDictionaryItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerDictionaries : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxSpellCheckerDictionaryItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxCustomSpellChecker* FSpellChecker;
	HIDESBASE TdxSpellCheckerDictionaryItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxSpellCheckerDictionaryItem* AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	__property TdxCustomSpellChecker* SpellChecker = {read=FSpellChecker};
	
public:
	__fastcall TdxSpellCheckerDictionaries(TdxCustomSpellChecker* ASpellChecker);
	HIDESBASE TdxSpellCheckerDictionaryItem* __fastcall Add(void);
	DYNAMIC System::UnicodeString __fastcall GetNamePath(void);
	__property TdxSpellCheckerDictionaryItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxSpellCheckerDictionaries(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerCustomOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomOptions : public TdxSpellCheckerPersistent
{
	typedef TdxSpellCheckerPersistent inherited;
	
protected:
	virtual void __fastcall InitializeOptions(void);
	
public:
	__fastcall virtual TdxSpellCheckerCustomOptions(TdxCustomSpellChecker* ASpellChecker);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCustomOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerAutoCorrectExceptions;
typedef void __fastcall (__closure *TdxSpellCheckerAutoCorrectExceptionAddEvent)(TdxSpellCheckerAutoCorrectExceptions* Sender, System::WideString &AException, bool &AAllow);

typedef void __fastcall (__closure *TdxSpellCheckerAutoCorrectExceptionDeleteEvent)(TdxSpellCheckerAutoCorrectExceptions* Sender, const System::WideString AException, bool &AAllow);

class DELPHICLASS TdxSpellCheckerAutoCorrectOptions;
class PASCALIMPLEMENTATION TdxSpellCheckerAutoCorrectExceptions : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::WideString operator[](int Index) { return Exceptions[Index]; }
	
private:
	bool FAutoInclude;
	int FCount;
	Dxhunspelltypes::TdxPWideCharArray *FList;
	_RTL_CRITICAL_SECTION FLock;
	TdxSpellCheckerAutoCorrectOptions* FOptions;
	TdxSpellCheckerAutoCorrectExceptionAddEvent FOnAdd;
	TdxSpellCheckerAutoCorrectExceptionDeleteEvent FOnDelete;
	System::WideString __fastcall GetException(int Index);
	
protected:
	void __fastcall DisposeException(System::WideChar * AException);
	bool __fastcall DoAdd(System::WideString &AException);
	bool __fastcall DoDelete(const System::WideString AException);
	virtual void __fastcall SetCount(int AValue);
	__property TdxSpellCheckerAutoCorrectExceptionAddEvent OnAdd = {read=FOnAdd, write=FOnAdd};
	__property TdxSpellCheckerAutoCorrectExceptionDeleteEvent OnDelete = {read=FOnDelete, write=FOnDelete};
	
public:
	__fastcall virtual TdxSpellCheckerAutoCorrectExceptions(TdxSpellCheckerAutoCorrectOptions* AOptions);
	__fastcall virtual ~TdxSpellCheckerAutoCorrectExceptions(void);
	int __fastcall Add(const System::WideString AException);
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex)/* overload */;
	void __fastcall Delete(const System::WideString AException)/* overload */;
	int __fastcall Find(const System::WideString AException);
	void __fastcall LoadFromFile(const System::WideString AFileName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall PopulateExceptions(System::Classes::TStrings* AList);
	void __fastcall SaveToFile(const System::WideString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property bool AutoInclude = {read=FAutoInclude, write=FAutoInclude, nodefault};
	__property int Count = {read=FCount, nodefault};
	__property System::WideString Exceptions[int Index] = {read=GetException/*, default*/};
};


class DELPHICLASS TdxSpellCheckerAutoCorrectReplacementList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerAutoCorrectReplacementList : public TdxSpellCheckerReplacementList
{
	typedef TdxSpellCheckerReplacementList inherited;
	
public:
	void __fastcall LoadFromFile(const System::WideString AFileName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::WideString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxSpellCheckerReplacementList.Create */ inline __fastcall TdxSpellCheckerAutoCorrectReplacementList(bool AllowDuplicates) : TdxSpellCheckerReplacementList(AllowDuplicates) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerAutoCorrectReplacementList(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxSpellCheckerAutoCorrectOptionsChangedEvent)(TdxSpellCheckerAutoCorrectOptions* Sender);

class PASCALIMPLEMENTATION TdxSpellCheckerAutoCorrectOptions : public TdxSpellCheckerCustomOptions
{
	typedef TdxSpellCheckerCustomOptions inherited;
	
private:
	bool FActive;
	bool FAutomaticallyUseSuggestions;
	bool FCorrectCapsLock;
	bool FCorrectInitialCaps;
	bool FCorrectSentenceCaps;
	bool FDisableCapsLock;
	TdxSpellCheckerAutoCorrectExceptions* FFirstLetterExceptions;
	TdxSpellCheckerAutoCorrectExceptions* FInitialCapsExceptions;
	TdxSpellCheckerAutoCorrectReplacementList* FReplacements;
	bool FReplaceTextAsYouType;
	TdxSpellCheckerAutoCorrectOptionsChangedEvent FOnChanged;
	void __fastcall FirstLetterExceptionAddHandler(TdxSpellCheckerAutoCorrectExceptions* Sender, System::WideString &AException, bool &AAllow);
	void __fastcall InitialCapsExceptionAddHandler(TdxSpellCheckerAutoCorrectExceptions* Sender, System::WideString &AException, bool &AAllow);
	void __fastcall SetActive(const bool AValue);
	void __fastcall SetAutomaticallyUseSuggestions(const bool AValue);
	void __fastcall SetCorrectCapsLock(const bool AValue);
	void __fastcall SetCorrectInitialCaps(const bool AValue);
	void __fastcall SetCorrectSentenceCaps(const bool AValue);
	void __fastcall SetDisableCapsLock(const bool AValue);
	void __fastcall SetReplaceTextAsYouType(const bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall DoChanged(void);
	virtual void __fastcall InitializeOptions(void);
	
public:
	__fastcall virtual ~TdxSpellCheckerAutoCorrectOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall GetReplacement(const System::WideString AText, /* out */ System::WideString &AReplacement);
	__property TdxSpellCheckerAutoCorrectExceptions* FirstLetterExceptions = {read=FFirstLetterExceptions};
	__property TdxSpellCheckerAutoCorrectExceptions* InitialCapsExceptions = {read=FInitialCapsExceptions};
	__property TdxSpellCheckerAutoCorrectReplacementList* Replacements = {read=FReplacements};
	__property TdxSpellCheckerAutoCorrectOptionsChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool AutomaticallyUseSuggestions = {read=FAutomaticallyUseSuggestions, write=SetAutomaticallyUseSuggestions, default=1};
	__property bool CorrectCapsLock = {read=FCorrectCapsLock, write=SetCorrectCapsLock, default=1};
	__property bool CorrectInitialCaps = {read=FCorrectInitialCaps, write=SetCorrectInitialCaps, default=1};
	__property bool CorrectSentenceCaps = {read=FCorrectSentenceCaps, write=SetCorrectSentenceCaps, default=1};
	__property bool DisableCapsLock = {read=FDisableCapsLock, write=SetDisableCapsLock, default=0};
	__property bool ReplaceTextAsYouType = {read=FReplaceTextAsYouType, write=SetReplaceTextAsYouType, default=1};
public:
	/* TdxSpellCheckerCustomOptions.Create */ inline __fastcall virtual TdxSpellCheckerAutoCorrectOptions(TdxCustomSpellChecker* ASpellChecker) : TdxSpellCheckerCustomOptions(ASpellChecker) { }
	
};


class DELPHICLASS TdxSpellCheckerSpellingOptions;
typedef void __fastcall (__closure *TdxSpellCheckerSpellingOptionsChangedEvent)(TdxSpellCheckerSpellingOptions* Sender);

class PASCALIMPLEMENTATION TdxSpellCheckerSpellingOptions : public TdxSpellCheckerCustomOptions
{
	typedef TdxSpellCheckerCustomOptions inherited;
	
private:
	bool FIgnoreMixedCaseWords;
	bool FIgnoreUpperCaseWords;
	bool FIgnoreMarkupTags;
	bool FIgnoreRepeatedWords;
	bool FCheckSelectedTextFirst;
	bool FIgnoreUrls;
	bool FCheckFromCursorPos;
	bool FIgnoreEmails;
	bool FIgnoreWordsWithNumbers;
	TdxSpellCheckerSpellingOptionsChangedEvent FOnChanged;
	void __fastcall SetCheckFromCursorPos(bool AValue);
	void __fastcall SetCheckSelectedTextFirst(bool AValue);
	void __fastcall SetIgnoreEmails(bool AValue);
	void __fastcall SetIgnoreMarkupTags(bool AValue);
	void __fastcall SetIgnoreMixedCaseWords(bool AValue);
	void __fastcall SetIgnoreRepeatedWords(bool AValue);
	void __fastcall SetIgnoreUpperCaseWords(bool AValue);
	void __fastcall SetIgnoreUrls(bool AValue);
	void __fastcall SetIgnoreWordsWithNumbers(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall DoChanged(void);
	virtual void __fastcall InitializeOptions(void);
	virtual void __fastcall PopulateRules(Dxspellcheckerrules::TdxSpellCheckerRules* ARules, Dxspellcheckerrules::TdxCustomSpellCheckerTextHelper* AParser);
	__property bool IgnoreMarkupTags = {read=FIgnoreMarkupTags, write=SetIgnoreMarkupTags, default=1};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxSpellCheckerSpellingOptionsChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property bool CheckFromCursorPos = {read=FCheckFromCursorPos, write=SetCheckFromCursorPos, default=0};
	__property bool CheckSelectedTextFirst = {read=FCheckSelectedTextFirst, write=SetCheckSelectedTextFirst, default=1};
	__property bool IgnoreEmails = {read=FIgnoreEmails, write=SetIgnoreEmails, default=1};
	__property bool IgnoreMixedCaseWords = {read=FIgnoreMixedCaseWords, write=SetIgnoreMixedCaseWords, default=1};
	__property bool IgnoreRepeatedWords = {read=FIgnoreRepeatedWords, write=SetIgnoreRepeatedWords, default=0};
	__property bool IgnoreUpperCaseWords = {read=FIgnoreUpperCaseWords, write=SetIgnoreUpperCaseWords, default=1};
	__property bool IgnoreUrls = {read=FIgnoreUrls, write=SetIgnoreUrls, default=1};
	__property bool IgnoreWordsWithNumbers = {read=FIgnoreWordsWithNumbers, write=SetIgnoreWordsWithNumbers, default=1};
public:
	/* TdxSpellCheckerCustomOptions.Create */ inline __fastcall virtual TdxSpellCheckerSpellingOptions(TdxCustomSpellChecker* ASpellChecker) : TdxSpellCheckerCustomOptions(ASpellChecker) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSpellCheckerSpellingOptions(void) { }
	
};


enum TdxSpellCheckerUnderlineStyle : unsigned char { usAuto, usWavyLine, usLine };

enum TdxSpellCheckerPopupMenuItem : unsigned char { scmiAddToDictionary, scmiAutoCorrect, scmiDelete, scmiIgnoreAll, scmiSpelling, scmiSuggestions };

typedef System::Set<TdxSpellCheckerPopupMenuItem, TdxSpellCheckerPopupMenuItem::scmiAddToDictionary, TdxSpellCheckerPopupMenuItem::scmiSuggestions>  TdxSpellCheckerPopupMenuItems;

class DELPHICLASS TdxSpellCheckerCheckAsYouTypeOptions;
typedef void __fastcall (__closure *TdxSpellCheckerCheckAsYouTypeOptionsChangedEvent)(TdxSpellCheckerCheckAsYouTypeOptions* ASender);

class PASCALIMPLEMENTATION TdxSpellCheckerCheckAsYouTypeOptions : public TdxSpellCheckerCustomOptions
{
	typedef TdxSpellCheckerCustomOptions inherited;
	
private:
	bool FActive;
	bool FModifyControlPopupMenu;
	System::Classes::TComponent* FPopupMenu;
	TdxSpellCheckerPopupMenuItems FPopupMenuItems;
	int FSuggestionCount;
	System::Uitypes::TColor FUnderlineColor;
	TdxSpellCheckerUnderlineStyle FUnderlineStyle;
	TdxSpellCheckerCheckAsYouTypeOptionsChangedEvent FOnChanged;
	void __fastcall SetActive(bool AValue);
	void __fastcall SetPopupMenu(System::Classes::TComponent* AValue);
	void __fastcall SetModifyControlPopupMenu(bool AValue);
	void __fastcall SetPopupMenuItems(TdxSpellCheckerPopupMenuItems AValue);
	void __fastcall SetSuggestionCount(int AValue);
	void __fastcall SetUnderlineColor(System::Uitypes::TColor AValue);
	void __fastcall SetUnderlineStyle(TdxSpellCheckerUnderlineStyle AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall DoChanged(void);
	virtual void __fastcall InitializeOptions(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxSpellCheckerCheckAsYouTypeOptionsChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool ModifyControlPopupMenu = {read=FModifyControlPopupMenu, write=SetModifyControlPopupMenu, default=1};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property TdxSpellCheckerPopupMenuItems PopupMenuItems = {read=FPopupMenuItems, write=SetPopupMenuItems, default=63};
	__property int SuggestionCount = {read=FSuggestionCount, write=SetSuggestionCount, default=5};
	__property System::Uitypes::TColor UnderlineColor = {read=FUnderlineColor, write=SetUnderlineColor, default=255};
	__property TdxSpellCheckerUnderlineStyle UnderlineStyle = {read=FUnderlineStyle, write=SetUnderlineStyle, default=0};
public:
	/* TdxSpellCheckerCustomOptions.Create */ inline __fastcall virtual TdxSpellCheckerCheckAsYouTypeOptions(TdxCustomSpellChecker* ASpellChecker) : TdxSpellCheckerCustomOptions(ASpellChecker) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCheckAsYouTypeOptions(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCustomManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomManager : public TdxSpellCheckerPersistent
{
	typedef TdxSpellCheckerPersistent inherited;
	
private:
	TdxSpellCheckerCustomCheckMode* FCheckMode;
	Cxedit::TcxCustomEdit* FContainer;
	Vcl::Controls::TWinControl* __fastcall GetEdit(void);
	void __fastcall SetEdit(Vcl::Controls::TWinControl* const AValue);
	
protected:
	TdxSpellCheckerCustomEditAdapter* FAdapter;
	virtual void __fastcall CreateAdapter(TdxSpellCheckerCustomEditAdapterClass AAdapterClass, Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall DoActiveChanged(void) = 0 ;
	virtual void __fastcall DoFinalizeController(void);
	virtual void __fastcall DoFinish(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall DoOptionsChanged(void) = 0 ;
	virtual bool __fastcall DoStart(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual bool __fastcall GetActive(void);
	virtual TdxSpellCheckerCustomEditAdapterClass __fastcall GetAdapterClass(Vcl::Controls::TWinControl* AControl);
	virtual TdxSpellCheckerCustomCheckModeClass __fastcall GetCheckModeClass(void);
	virtual void __fastcall FinalizeController(void);
	virtual void __fastcall InitializeController(Vcl::Controls::TWinControl* AControl);
	__classmethod bool __fastcall IsCheckSupported(Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall ValidateAdapter(void);
	__property Cxedit::TcxCustomEdit* Container = {read=FContainer};
	
public:
	__fastcall virtual TdxSpellCheckerCustomManager(TdxCustomSpellChecker* ASpellChecker);
	virtual void __fastcall CheckFinish(void);
	virtual void __fastcall CheckStart(Vcl::Controls::TWinControl* AControl);
	__property bool Active = {read=GetActive, nodefault};
	__property TdxSpellCheckerCustomEditAdapter* Adapter = {read=FAdapter};
	__property TdxSpellCheckerCustomCheckMode* CheckMode = {read=FCheckMode};
	__property Vcl::Controls::TWinControl* Edit = {read=GetEdit, write=SetEdit};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCustomManager(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerAutoCorrectCustomRule;
class DELPHICLASS TdxSpellCheckerCustomAutoCorrectManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerAutoCorrectCustomRule : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxSpellCheckerCustomAutoCorrectManager* FManager;
	System::WideString FWordDelimiters;
	System::WideChar __fastcall GetLastKey(void);
	TdxSpellCheckerAutoCorrectOptions* __fastcall GetOptions(void);
	
protected:
	virtual bool __fastcall GetActive(void);
	virtual void __fastcall InitializeDelimiters(void) = 0 ;
	void __fastcall SetWordDelimiters(const System::WideString AWordDelimiters);
	System::WideString __fastcall WideCapitalizeCase(const System::WideString AWord);
	__property System::WideChar LastKey = {read=GetLastKey, nodefault};
	
public:
	__fastcall virtual TdxSpellCheckerAutoCorrectCustomRule(TdxSpellCheckerCustomAutoCorrectManager* AManager);
	virtual void __fastcall AfterCorrect(void);
	virtual void __fastcall BeforeCorrect(void);
	virtual bool __fastcall IsCheckWord(const System::WideString AText, int &AStart, int &ALength, System::WideString &AWord) = 0 ;
	virtual bool __fastcall IsTerminating(void);
	bool __fastcall IsWordDelimiter(System::WideChar AChar);
	virtual void __fastcall Undo(void);
	__property bool Active = {read=GetActive, nodefault};
	__property TdxSpellCheckerCustomAutoCorrectManager* Manager = {read=FManager};
	__property TdxSpellCheckerAutoCorrectOptions* Options = {read=GetOptions};
	__property System::WideString WordDelimiters = {read=FWordDelimiters};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerAutoCorrectCustomRule(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomAutoCorrectManager : public TdxSpellCheckerCustomManager
{
	typedef TdxSpellCheckerCustomManager inherited;
	
private:
	System::WideChar FLastKey;
	TdxSpellCheckerAutoCorrectOptions* __fastcall GetOptions(void);
	
protected:
	virtual void __fastcall CreateAdapter(TdxSpellCheckerCustomEditAdapterClass AAdapterClass, Vcl::Controls::TWinControl* AControl);
	virtual bool __fastcall DoAutoCorrect(TdxSpellCheckerAutoCorrectCustomRule* ARule, Cxcontrols::TdxSpellCheckerAutoCorrectWordRange &AWordRange);
	virtual void __fastcall DoFinish(Vcl::Controls::TWinControl* AControl);
	virtual bool __fastcall DoStart(Vcl::Controls::TWinControl* AControl);
	virtual bool __fastcall GetActive(void);
	virtual TdxSpellCheckerCustomEditAdapterClass __fastcall GetAdapterClass(Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall Undo(void);
	System::WideString __fastcall WideCapitalizeCase(const System::WideString AWord);
	__property System::WideChar LastKey = {read=FLastKey, nodefault};
	
public:
	virtual void __fastcall KeyPress(System::WideChar AKey);
	__property TdxSpellCheckerAutoCorrectOptions* Options = {read=GetOptions};
public:
	/* TdxSpellCheckerCustomManager.Create */ inline __fastcall virtual TdxSpellCheckerCustomAutoCorrectManager(TdxCustomSpellChecker* ASpellChecker) : TdxSpellCheckerCustomManager(ASpellChecker) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCustomAutoCorrectManager(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSpellCheckerCustomCheckAsYouTypeManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSpellCheckerCustomCheckAsYouTypeManager : public TdxSpellCheckerCustomManager
{
	typedef TdxSpellCheckerCustomManager inherited;
	
private:
	int FManualCheckCount;
	bool __fastcall GetIsManualCheckingActive(void);
	bool __fastcall GetIsSpellCheckerReady(void);
	TdxSpellCheckerCheckAsYouTypeOptions* __fastcall GetOptions(void);
	
protected:
	virtual void __fastcall DoFinish(Vcl::Controls::TWinControl* AControl);
	virtual bool __fastcall DoStart(Vcl::Controls::TWinControl* AControl);
	virtual bool __fastcall GetActive(void);
	void __fastcall InnerShowPopupMenu(System::Classes::TComponent* APopup, const System::Types::TPoint &P);
	virtual void __fastcall Reset(void);
	virtual void __fastcall SpellingOptionsChanged(void);
	virtual void __fastcall StartManualSpelling(TdxSpellCheckerCustomEditAdapter* AAdapter);
	virtual void __fastcall ValidateRules(TdxSpellCheckerTextParser* AParser);
	
public:
	virtual void __fastcall BeginManualCheck(void);
	virtual void __fastcall CheckFinish(void);
	virtual void __fastcall CheckStart(Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall EndManualCheck(void);
	virtual void __fastcall KeyDown(System::Word AKey, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyUp(System::Word AKey, System::Classes::TShiftState Shift);
	virtual void __fastcall Refresh(bool AFullRefresh = false) = 0 ;
	virtual void __fastcall DrawMisspellings(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall LayoutChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual bool __fastcall QueryPopup(System::Classes::TComponent* APopup, const System::Types::TPoint &P) = 0 ;
	virtual void __fastcall SelectionChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	virtual void __fastcall TextChanged(Vcl::Controls::TWinControl* AControl) = 0 ;
	__property bool IsManualCheckingActive = {read=GetIsManualCheckingActive, nodefault};
	__property bool IsSpellCheckerReady = {read=GetIsSpellCheckerReady, nodefault};
	__property TdxSpellCheckerCheckAsYouTypeOptions* Options = {read=GetOptions};
public:
	/* TdxSpellCheckerCustomManager.Create */ inline __fastcall virtual TdxSpellCheckerCustomCheckAsYouTypeManager(TdxCustomSpellChecker* ASpellChecker) : TdxSpellCheckerCustomManager(ASpellChecker) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCustomCheckAsYouTypeManager(void) { }
	
};

#pragma pack(pop)

enum TdxSpellCheckerSpellingFormType : unsigned char { sftOutlook, sftWord };

typedef void __fastcall (__closure *TdxSpellCheckerEvent)(TdxCustomSpellChecker* Sender);

typedef void __fastcall (__closure *TdxSpellCheckerCheckWordEvent)(TdxCustomSpellChecker* Sender, const System::WideString AWord, /* out */ bool &AValid, bool &AHandled);

typedef void __fastcall (__closure *TdxSpellCheckerAddWordEvent)(TdxUserSpellCheckerDictionary* AUserDictionary, const System::WideString AWord, bool &AHandled);

typedef void __fastcall (__closure *TdxSpellCheckerAutoCorrectEvent)(TdxCustomSpellChecker* Sender, TdxSpellCheckerAutoCorrectCustomRule* ARule, Cxcontrols::TdxSpellCheckerAutoCorrectWordRange &AWordRange, bool &AAllow);

typedef void __fastcall (__closure *TdxSpellCheckerEnabledDictionariesLoadedEvent)(TdxCustomSpellChecker* Sender, const System::WideString AWord, bool &AHandled);

typedef void __fastcall (__closure *TdxSpellCheckerSpellingComplete)(TdxCustomSpellChecker* Sender, bool &AHandled);

typedef void __fastcall (__closure *TdxSpellCheckerCheckFinishEvent)(TdxCustomSpellChecker* Sender, Vcl::Controls::TWinControl* AControl);

typedef void __fastcall (__closure *TdxSpellCheckerCheckStartEvent)(TdxCustomSpellChecker* Sender, Vcl::Controls::TWinControl* AControl, bool &AAllow);

typedef void __fastcall (__closure *TdxSpellCheckerCheckAsYouTypePopupEvent)(TdxCustomSpellChecker* ASender, System::Classes::TComponent* APopupMenu, bool &AHandled);

typedef void __fastcall (__closure *TdxSpellCheckerCheckControlInContainerEvent)(TdxCustomSpellChecker* Sender, Vcl::Controls::TWinControl* AControl, bool &AAllow, bool &AContinue);

typedef void __fastcall (__closure *TdxSpellCheckerGetSuggestionsEvent)(TdxCustomSpellChecker* Sender, const System::WideString AWord, TdxSpellCheckerSuggestionList* ASuggestions);

class PASCALIMPLEMENTATION TdxCustomSpellChecker : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	TdxSpellCheckerCustomAutoCorrectManager* FAutoCorrectManager;
	TdxSpellCheckerAutoCorrectOptions* FAutoCorrectOptions;
	bool FAutoLoadDictionaries;
	TdxSpellCheckerReplacementList* FChangeList;
	TdxSpellCheckerCustomCheckAsYouTypeManager* FCheckAsYouTypeManager;
	TdxSpellCheckerCheckAsYouTypeOptions* FCheckAsYouTypeOptions;
	bool FCheckGroupMode;
	bool FCheckingContainer;
	TdxSpellCheckerCustomCheckMode* FCheckMode;
	bool FCreating;
	TdxSpellCheckerWordList* FDeleteList;
	Cxlookandfeels::TcxLookAndFeel* FDialogLookAndFeel;
	TdxSpellCheckerDictionaries* FDictionaryItems;
	TdxSpellCheckerWordList* FIgnoreList;
	int FLastDialogResult;
	int FMetaphoneDistance;
	Dxspellcheckerrules::TdxSpellCheckerRules* FRules;
	Dxspellcheckeralgorithms::TdxStringSimilarityCalculator* FSimilarity;
	TdxSpellCheckerSpellingFormType FSpellingFormType;
	TdxSpellCheckerSpellingOptions* FSpellingOptions;
	TdxSpellCheckerSuggestionCache* FSuggestionCache;
	System::Classes::TThreadPriority FThreadedLoadPriority;
	bool FUseThreadedLoad;
	TdxSpellCheckerAddWordEvent FOnAddWord;
	TdxSpellCheckerEvent FOnAfterCheck;
	TdxSpellCheckerAutoCorrectEvent FOnAutoCorrect;
	TdxSpellCheckerCheckFinishEvent FOnAutoCorrectFinish;
	TdxSpellCheckerCheckStartEvent FOnAutoCorrectStart;
	TdxSpellCheckerEvent FOnBeforeCheck;
	TdxSpellCheckerCheckFinishEvent FOnCheckAsYouTypeFinish;
	TdxSpellCheckerCheckStartEvent FOnCheckAsYouTypeStart;
	TdxSpellCheckerCheckControlInContainerEvent FOnCheckControlInContainer;
	TdxSpellCheckerCheckWordEvent FOnCheckWord;
	TdxSpellCheckerEvent FOnEnabledDictionariesLoaded;
	TdxSpellCheckerGetSuggestionsEvent FOnGetSuggestions;
	TdxSpellCheckerCheckAsYouTypePopupEvent FOnCheckAsYouTypePopup;
	TdxSpellCheckerSpellingComplete FOnSpellingComplete;
	TdxCustomSpellCheckerDictionary* __fastcall GetActiveDictionary(int Index);
	int __fastcall GetActiveDictionaryCount(void);
	TdxSpellCheckerCustomCheckMode* __fastcall GetCheckMode(void);
	TdxCustomSpellCheckerDictionary* __fastcall GetDictionary(int Index);
	int __fastcall GetDictionaryCount(void);
	TdxCustomSpellCheckerDictionary* __fastcall GetEnabledDictionary(int Index);
	int __fastcall GetEnabledDictionaryCount(void);
	TdxUserSpellCheckerDictionary* __fastcall GetUserDictionary(int Index);
	int __fastcall GetUserDictionaryCount(void);
	void __fastcall SetAutoCorrectOptions(TdxSpellCheckerAutoCorrectOptions* AValue);
	void __fastcall SetCheckAsYouTypeOptions(TdxSpellCheckerCheckAsYouTypeOptions* AValue);
	void __fastcall SetDialogLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetDictionaryItems(TdxSpellCheckerDictionaries* AValue);
	void __fastcall SetMetaphoneDistance(int AValue);
	void __fastcall SetSpellingOptions(TdxSpellCheckerSpellingOptions* AValue);
	
protected:
	virtual void __fastcall AddToIgnoreList(const System::WideString AWord);
	virtual bool __fastcall CanCheckControlInContainer(Vcl::Controls::TControl* AControl);
	void __fastcall CheckCallEnabledDictionariesLoaded(void);
	virtual void __fastcall CheckControlInContainer(Vcl::Controls::TWinControl* AControl);
	virtual TdxSpellCheckerCustomAutoCorrectManager* __fastcall CreateAutoCorrectManager(void);
	virtual TdxSpellCheckerAutoCorrectOptions* __fastcall CreateAutoCorrectOptions(void);
	virtual TdxSpellCheckerCustomCheckAsYouTypeManager* __fastcall CreateCheckAsYouTypeManager(void);
	virtual TdxSpellCheckerCheckAsYouTypeOptions* __fastcall CreateCheckAsYouTypeOptions(void);
	virtual Dxspellcheckeralgorithms::TdxStringSimilarityCalculator* __fastcall CreateSimilarity(void);
	virtual TdxSpellCheckerSingleWordParser* __fastcall CreateSingleWordParser(void);
	virtual TdxSpellCheckerSpellingOptions* __fastcall CreateSpellingOptions(void);
	virtual bool __fastcall DoAddWord(TdxUserSpellCheckerDictionary* AUserDictionary, const System::WideString AWord);
	virtual void __fastcall DoAfterCheck(void);
	virtual bool __fastcall DoAutoCorrect(TdxSpellCheckerAutoCorrectCustomRule* ARule, Cxcontrols::TdxSpellCheckerAutoCorrectWordRange &AWordRange);
	virtual void __fastcall DoAutoCorrectFinish(Vcl::Controls::TWinControl* AControl);
	virtual bool __fastcall DoAutoCorrectStart(Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall DoBeforeCheck(void);
	virtual void __fastcall DoCheck(TdxSpellCheckerDialogCheckMode* ADialogCheckMode);
	virtual void __fastcall DoCheckAsYouTypeFinish(Vcl::Controls::TWinControl* AControl);
	virtual bool __fastcall DoCheckAsYouTypePopup(System::Classes::TComponent* APopup);
	virtual bool __fastcall DoCheckAsYouTypeStart(Vcl::Controls::TWinControl* AControl);
	virtual void __fastcall DoCheckContainer(Vcl::Controls::TWinControl* AContainer, bool ARecursive);
	virtual bool __fastcall DoCheckControlInContainer(Vcl::Controls::TWinControl* AControl, bool &AContinue);
	virtual bool __fastcall DoCheckWord(const System::WideString AWord, bool &AValid);
	virtual void __fastcall DoEnabledDictionariesLoaded(void);
	virtual void __fastcall DoGetSuggestions(const System::WideString AWord, TdxSpellCheckerSuggestionList* ASuggestions);
	virtual bool __fastcall DoSpellingComplete(void);
	void __fastcall BeginManualCheck(void);
	void __fastcall EndManualCheck(void);
	virtual TdxSpellCheckerCustomCheckModeClass __fastcall GetDialogCheckModeClass(void);
	virtual System::WideString __fastcall GetWordChars(void);
	virtual void __fastcall InternalCheck(TdxSpellCheckerCustomEditAdapter* AAdapter);
	virtual bool __fastcall InternalIsValidWord(const System::WideString AWord);
	virtual void __fastcall LoadDictionariesDirect(bool AIgnoreDisabled = true);
	virtual void __fastcall LoadDictionariesUsingThread(bool AIgnoreDisabled = true);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SpellingComplete(void);
	virtual void __fastcall SpellingOptionsChanged(void);
	virtual void __fastcall ValidateRules(Dxspellcheckerrules::TdxCustomSpellCheckerTextHelper* AParser);
	virtual void __fastcall UpdateByDictionary(TdxCustomSpellCheckerDictionary* ADictionary);
	void __fastcall CheckFinish(void);
	void __fastcall CheckStart(Vcl::Controls::TWinControl* AControl);
	void __fastcall DrawMisspellings(Vcl::Controls::TWinControl* AControl);
	bool __fastcall IsSpellCheckerDialogControl(NativeUInt AWnd);
	void __fastcall KeyPress(System::WideChar AKey);
	bool __fastcall QueryPopup(System::Classes::TComponent* APopup, const System::Types::TPoint &P);
	void __fastcall LayoutChanged(Vcl::Controls::TWinControl* AControl);
	void __fastcall SelectionChanged(Vcl::Controls::TWinControl* AControl);
	void __fastcall TextChanged(Vcl::Controls::TWinControl* AControl);
	void __fastcall Undo(void);
	void __fastcall KeyDown(System::Word AKey, System::Classes::TShiftState Shift);
	void __fastcall KeyUp(System::Word AKey, System::Classes::TShiftState Shift);
	__property TdxSpellCheckerCustomAutoCorrectManager* AutoCorrectManager = {read=FAutoCorrectManager};
	__property TdxSpellCheckerReplacementList* ChangeList = {read=FChangeList};
	__property TdxSpellCheckerCustomCheckAsYouTypeManager* CheckAsYouTypeManager = {read=FCheckAsYouTypeManager};
	__property bool CheckingContainer = {read=FCheckingContainer, nodefault};
	__property TdxSpellCheckerWordList* DeleteList = {read=FDeleteList};
	__property TdxSpellCheckerWordList* IgnoreList = {read=FIgnoreList};
	__property Dxspellcheckeralgorithms::TdxStringSimilarityCalculator* Similarity = {read=FSimilarity};
	__property TdxSpellCheckerSuggestionCache* SuggestionCache = {read=FSuggestionCache};
	__property TdxSpellCheckerAddWordEvent OnAddWord = {read=FOnAddWord, write=FOnAddWord};
	__property TdxSpellCheckerEvent OnAfterCheck = {read=FOnAfterCheck, write=FOnAfterCheck};
	__property TdxSpellCheckerAutoCorrectEvent OnAutoCorrect = {read=FOnAutoCorrect, write=FOnAutoCorrect};
	__property TdxSpellCheckerCheckFinishEvent OnAutoCorrectFinish = {read=FOnAutoCorrectFinish, write=FOnAutoCorrectFinish};
	__property TdxSpellCheckerCheckStartEvent OnAutoCorrectStart = {read=FOnAutoCorrectStart, write=FOnAutoCorrectStart};
	__property TdxSpellCheckerEvent OnBeforeCheck = {read=FOnBeforeCheck, write=FOnBeforeCheck};
	__property TdxSpellCheckerCheckFinishEvent OnCheckAsYouTypeFinish = {read=FOnCheckAsYouTypeFinish, write=FOnCheckAsYouTypeFinish};
	__property TdxSpellCheckerCheckAsYouTypePopupEvent OnCheckAsYouTypePopup = {read=FOnCheckAsYouTypePopup, write=FOnCheckAsYouTypePopup};
	__property TdxSpellCheckerCheckStartEvent OnCheckAsYouTypeStart = {read=FOnCheckAsYouTypeStart, write=FOnCheckAsYouTypeStart};
	__property TdxSpellCheckerCheckControlInContainerEvent OnCheckControlInContainer = {read=FOnCheckControlInContainer, write=FOnCheckControlInContainer};
	__property TdxSpellCheckerCheckWordEvent OnCheckWord = {read=FOnCheckWord, write=FOnCheckWord};
	__property TdxSpellCheckerEvent OnEnabledDictionariesLoaded = {read=FOnEnabledDictionariesLoaded, write=FOnEnabledDictionariesLoaded};
	__property TdxSpellCheckerGetSuggestionsEvent OnGetSuggestions = {read=FOnGetSuggestions, write=FOnGetSuggestions};
	__property TdxSpellCheckerSpellingComplete OnSpellingComplete = {read=FOnSpellingComplete, write=FOnSpellingComplete};
	
public:
	__fastcall virtual TdxCustomSpellChecker(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomSpellChecker(void);
	void __fastcall Check(System::AnsiString &AText)/* overload */;
	void __fastcall Check(System::WideString &AText)/* overload */;
	void __fastcall Check(Vcl::Stdctrls::TCustomEdit* AEdit)/* overload */;
	void __fastcall Check(Cxtextedit::TcxCustomTextEdit* AEdit)/* overload */;
	void __fastcall CheckContainer(Vcl::Controls::TWinControl* AContainer, bool ARecursive);
	void __fastcall AddWordToUserDictionary(const System::WideString AWord);
	TdxCustomSpellCheckerDictionary* __fastcall FindDictionaryByWord(const System::WideString AWord);
	TdxUserSpellCheckerDictionary* __fastcall FindFirstEnabledUserDictionary(void);
	TdxSpellCheckerSuggestionList* __fastcall GetSuggestions(const System::WideString AWord);
	bool __fastcall HasWordInDictionaries(const System::WideString AWord);
	bool __fastcall HasEnabledUserDictionary(void);
	bool __fastcall IsValidWord(const System::WideString AWord)/* overload */;
	bool __fastcall IsValidWord(const System::AnsiString AWord)/* overload */;
	void __fastcall PopulateLanguages(System::Classes::TStrings* AList);
	virtual void __fastcall ShowSpellingCompleteMessage(void);
	void __fastcall LoadDictionaries(bool AIgnoreDisabled = true);
	void __fastcall UnloadDictionaries(void);
	int __fastcall GetTwoWordsDistance(const System::WideString AWord1, const System::WideString AWord2);
	__property TdxCustomSpellCheckerDictionary* ActiveDictionaries[int Index] = {read=GetActiveDictionary};
	__property int ActiveDictionaryCount = {read=GetActiveDictionaryCount, nodefault};
	__property TdxSpellCheckerAutoCorrectOptions* AutoCorrectOptions = {read=FAutoCorrectOptions, write=SetAutoCorrectOptions};
	__property bool AutoLoadDictionaries = {read=FAutoLoadDictionaries, write=FAutoLoadDictionaries, default=0};
	__property TdxSpellCheckerCustomCheckMode* CheckMode = {read=GetCheckMode};
	__property TdxSpellCheckerCheckAsYouTypeOptions* CheckAsYouTypeOptions = {read=FCheckAsYouTypeOptions, write=SetCheckAsYouTypeOptions};
	__property Cxlookandfeels::TcxLookAndFeel* DialogLookAndFeel = {read=FDialogLookAndFeel, write=SetDialogLookAndFeel};
	__property TdxCustomSpellCheckerDictionary* Dictionaries[int Index] = {read=GetDictionary};
	__property int DictionaryCount = {read=GetDictionaryCount, nodefault};
	__property TdxSpellCheckerDictionaries* DictionaryItems = {read=FDictionaryItems, write=SetDictionaryItems};
	__property TdxCustomSpellCheckerDictionary* EnabledDictionaries[int Index] = {read=GetEnabledDictionary};
	__property int EnabledDictionaryCount = {read=GetEnabledDictionaryCount, nodefault};
	__property int MetaphoneDistance = {read=FMetaphoneDistance, write=SetMetaphoneDistance, default=3};
	__property Dxspellcheckerrules::TdxSpellCheckerRules* Rules = {read=FRules};
	__property TdxSpellCheckerSpellingFormType SpellingFormType = {read=FSpellingFormType, write=FSpellingFormType, default=0};
	__property TdxSpellCheckerSpellingOptions* SpellingOptions = {read=FSpellingOptions, write=SetSpellingOptions};
	__property System::Classes::TThreadPriority ThreadedLoadPriority = {read=FThreadedLoadPriority, write=FThreadedLoadPriority, default=2};
	__property TdxUserSpellCheckerDictionary* UserDictionaries[int Index] = {read=GetUserDictionary};
	__property int UserDictionaryCount = {read=GetUserDictionaryCount, nodefault};
	__property bool UseThreadedLoad = {read=FUseThreadedLoad, write=FUseThreadedLoad, default=0};
private:
	void *__IdxSpellChecker2;	/* Cxcontrols::IdxSpellChecker2 */
	void *__IdxSpellChecker;	/* Cxcontrols::IdxSpellChecker */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0480D25C-94DA-449D-BBE6-B771C76D0BB1}
	operator Cxcontrols::_di_IdxSpellChecker2()
	{
		Cxcontrols::_di_IdxSpellChecker2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IdxSpellChecker2*(void) { return (Cxcontrols::IdxSpellChecker2*)&__IdxSpellChecker2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4515FCEE-2D09-4709-A170-E29C556355BF}
	operator Cxcontrols::_di_IdxSpellChecker()
	{
		Cxcontrols::_di_IdxSpellChecker intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IdxSpellChecker*(void) { return (Cxcontrols::IdxSpellChecker*)&__IdxSpellChecker; }
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


class DELPHICLASS TdxSpellChecker;
class PASCALIMPLEMENTATION TdxSpellChecker : public TdxCustomSpellChecker
{
	typedef TdxCustomSpellChecker inherited;
	
__published:
	__property AutoCorrectOptions;
	__property AutoLoadDictionaries = {default=0};
	__property CheckAsYouTypeOptions;
	__property DialogLookAndFeel;
	__property DictionaryItems;
	__property MetaphoneDistance = {default=3};
	__property SpellingFormType = {default=0};
	__property SpellingOptions;
	__property ThreadedLoadPriority = {default=2};
	__property UseThreadedLoad = {default=0};
	__property OnAddWord;
	__property OnAfterCheck;
	__property OnAutoCorrect;
	__property OnAutoCorrectFinish;
	__property OnAutoCorrectStart;
	__property OnBeforeCheck;
	__property OnCheckAsYouTypeFinish;
	__property OnCheckAsYouTypePopup;
	__property OnCheckAsYouTypeStart;
	__property OnCheckControlInContainer;
	__property OnCheckWord;
	__property OnEnabledDictionariesLoaded;
	__property OnGetSuggestions;
	__property OnSpellingComplete;
public:
	/* TdxCustomSpellChecker.Create */ inline __fastcall virtual TdxSpellChecker(System::Classes::TComponent* AOwner) : TdxCustomSpellChecker(AOwner) { }
	/* TdxCustomSpellChecker.Destroy */ inline __fastcall virtual ~TdxSpellChecker(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Byte dxDefaultSuggestionsTimeout = System::Byte(0xfa);
extern PACKAGE Cxclasses::TcxRegisteredClasses* __fastcall GetRegisteredDictionaryTypes(void);
}	/* namespace Dxspellchecker */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKER)
using namespace Dxspellchecker;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerHPP
