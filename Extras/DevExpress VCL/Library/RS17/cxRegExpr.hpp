// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxRegExpr.pas' rev: 24.00 (Win32)

#ifndef CxregexprHPP
#define CxregexprHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxregexpr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxRegExprError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprError : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FChar;
	int FLine;
	System::UnicodeString FMessage;
	System::UnicodeString __fastcall GetFullMessage(void);
	
public:
	__fastcall TcxRegExprError(int ALine, int AChar, System::UnicodeString AMessage);
	TcxRegExprError* __fastcall Clone(void);
	__property int Char = {read=FChar, nodefault};
	__property System::UnicodeString FullMessage = {read=GetFullMessage};
	__property int Line = {read=FLine, nodefault};
	__property System::UnicodeString Message = {read=FMessage};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprError(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprErrors;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprErrors : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxRegExprError* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FErrors;
	int __fastcall GetCount(void);
	TcxRegExprError* __fastcall GetItems(int Index);
	
public:
	__fastcall TcxRegExprErrors(void);
	__fastcall virtual ~TcxRegExprErrors(void);
	void __fastcall Add(TcxRegExprError* AError);
	void __fastcall Clear(void);
	TcxRegExprErrors* __fastcall Clone(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxRegExprError* Items[int Index] = {read=GetItems/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS EcxRegExprError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxRegExprError : public Cxedit::EcxEditError
{
	typedef Cxedit::EcxEditError inherited;
	
private:
	TcxRegExprErrors* FErrors;
	
public:
	__fastcall EcxRegExprError(TcxRegExprErrors* AErrors);
	__property TcxRegExprErrors* Errors = {read=FErrors};
public:
	/* Exception.CreateFmt */ inline __fastcall EcxRegExprError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Cxedit::EcxEditError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxRegExprError(NativeUInt Ident)/* overload */ : Cxedit::EcxEditError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxRegExprError(System::PResStringRec ResStringRec)/* overload */ : Cxedit::EcxEditError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxRegExprError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Cxedit::EcxEditError(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxRegExprError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Cxedit::EcxEditError(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxRegExprError(const System::UnicodeString Msg, int AHelpContext) : Cxedit::EcxEditError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxRegExprError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Cxedit::EcxEditError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxRegExprError(NativeUInt Ident, int AHelpContext)/* overload */ : Cxedit::EcxEditError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxRegExprError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Cxedit::EcxEditError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxRegExprError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Cxedit::EcxEditError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxRegExprError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Cxedit::EcxEditError(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxRegExprError(void) { }
	
};

#pragma pack(pop)

enum TcxRegExprLexemCode : unsigned char { relcSymbol, relcSpecial, relcInteger, relcAll, relcId, relcNotId, relcDigit, relcNotDigit, relcSpace, relcNotSpace, relcReference, relcDateSeparator, relcTimeSeparator };

struct DECLSPEC_DRECORD TcxLexem
{
public:
	int Char;
	TcxRegExprLexemCode Code;
	int Line;
	System::UnicodeString Value;
};


typedef TcxLexem *PcxLexem;

class DELPHICLASS TcxLexems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLexems : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxLexem operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FLexems;
	int __fastcall GetCount(void);
	TcxLexem __fastcall GetItems(int Index);
	
public:
	__fastcall TcxLexems(void);
	__fastcall virtual ~TcxLexems(void);
	void __fastcall Add(const TcxLexem &ALexem);
	void __fastcall Clear(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxLexem Items[int Index] = {read=GetItems/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase) = 0 ;
	virtual TcxRegExprItem* __fastcall Clone(void) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxRegExprItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprSymbol;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprSymbol : public TcxRegExprItem
{
	typedef TcxRegExprItem inherited;
	
private:
	System::WideChar FValue;
	
public:
	__fastcall TcxRegExprSymbol(System::WideChar AValue);
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprSymbol(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprTimeSeparator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprTimeSeparator : public TcxRegExprItem
{
	typedef TcxRegExprItem inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
	System::WideChar __fastcall Value(void);
public:
	/* TObject.Create */ inline __fastcall TcxRegExprTimeSeparator(void) : TcxRegExprItem() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprTimeSeparator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprDateSeparator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprDateSeparator : public TcxRegExprItem
{
	typedef TcxRegExprItem inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
	System::WideChar __fastcall Value(void);
public:
	/* TObject.Create */ inline __fastcall TcxRegExprDateSeparator(void) : TcxRegExprItem() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprDateSeparator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprSubrange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprSubrange : public TcxRegExprItem
{
	typedef TcxRegExprItem inherited;
	
private:
	System::WideChar FStartValue;
	System::WideChar FFinishValue;
	
public:
	__fastcall TcxRegExprSubrange(System::WideChar AStartValue, System::WideChar AFinishValue);
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprSubrange(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprEnumeration;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprEnumeration : public TcxRegExprItem
{
	typedef TcxRegExprItem inherited;
	
private:
	bool FInverse;
	
public:
	__fastcall TcxRegExprEnumeration(bool AInverse);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprEnumeration(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprUserEnumeration;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprUserEnumeration : public TcxRegExprEnumeration
{
	typedef TcxRegExprEnumeration inherited;
	
private:
	System::Classes::TList* FItems;
	TcxRegExprItem* __fastcall Item(int AIndex);
	
public:
	__fastcall TcxRegExprUserEnumeration(bool AInverse);
	__fastcall virtual ~TcxRegExprUserEnumeration(void);
	void __fastcall Add(TcxRegExprItem* AItem);
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprDigit;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprDigit : public TcxRegExprEnumeration
{
	typedef TcxRegExprEnumeration inherited;
	
public:
	__fastcall TcxRegExprDigit(bool AInverse);
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprDigit(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprIdLetter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprIdLetter : public TcxRegExprEnumeration
{
	typedef TcxRegExprEnumeration inherited;
	
public:
	__fastcall TcxRegExprIdLetter(bool AInverse);
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprIdLetter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprSpace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprSpace : public TcxRegExprEnumeration
{
	typedef TcxRegExprEnumeration inherited;
	
public:
	__fastcall TcxRegExprSpace(bool AInverse);
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprSpace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprAll;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprAll : public TcxRegExprItem
{
	typedef TcxRegExprItem inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprItem* __fastcall Clone(void);
public:
	/* TObject.Create */ inline __fastcall TcxRegExprAll(void) : TcxRegExprItem() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprAll(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprState;
class DELPHICLASS TcxRegExprStates;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprState : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TcxRegExprStates* FStates;
	
public:
	__fastcall TcxRegExprState(void);
	__fastcall virtual ~TcxRegExprState(void);
	void __fastcall Add(TcxRegExprState* AState)/* overload */;
	void __fastcall Add(TcxRegExprStates* AStates)/* overload */;
	virtual TcxRegExprStates* __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprState* __fastcall Clone(void);
	TcxRegExprStates* __fastcall GetAllNextStates(void);
	virtual TcxRegExprStates* __fastcall GetSelf(void);
	TcxRegExprStates* __fastcall Next(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	__property TcxRegExprStates* States = {read=FStates};
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprSimpleState;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprSimpleState : public TcxRegExprState
{
	typedef TcxRegExprState inherited;
	
private:
	bool FIsFinal;
	TcxRegExprItem* FValue;
	
public:
	__fastcall TcxRegExprSimpleState(TcxRegExprItem* AValue);
	__fastcall virtual ~TcxRegExprSimpleState(void);
	virtual TcxRegExprStates* __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprState* __fastcall Clone(void);
	virtual TcxRegExprStates* __fastcall GetSelf(void);
	void __fastcall SetFinal(void);
	__property bool IsFinal = {read=FIsFinal, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprBlockState;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprBlockState : public TcxRegExprState
{
	typedef TcxRegExprState inherited;
	
public:
	virtual TcxRegExprStates* __fastcall Check(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	virtual TcxRegExprState* __fastcall Clone(void);
	virtual TcxRegExprStates* __fastcall GetSelf(void);
public:
	/* TcxRegExprState.Create */ inline __fastcall TcxRegExprBlockState(void) : TcxRegExprState() { }
	/* TcxRegExprState.Destroy */ inline __fastcall virtual ~TcxRegExprBlockState(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprStates : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxRegExprState* operator[](int AIndex) { return State[AIndex]; }
	
private:
	System::Classes::TList* FStates;
	int __fastcall GetCount(void);
	TcxRegExprState* __fastcall GetState(int AIndex);
	
public:
	__fastcall TcxRegExprStates(void);
	__fastcall virtual ~TcxRegExprStates(void);
	void __fastcall Add(TcxRegExprState* AState)/* overload */;
	void __fastcall Add(TcxRegExprStates* AStates)/* overload */;
	void __fastcall Clear(void);
	bool __fastcall Equ(System::WideChar &ASymbol);
	TcxRegExprStates* __fastcall GetAllNextStates(void);
	bool __fastcall IsFinal(void);
	TcxRegExprStates* __fastcall Next(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	__property int Count = {read=GetCount, nodefault};
	__property TcxRegExprState* State[int AIndex] = {read=GetState/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprAutomat;
class DELPHICLASS TcxRegExprParserAlts;
class DELPHICLASS TcxRegExpr;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprAutomat : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxRegExprStates* FCurrentStates;
	TcxRegExprParserAlts* FExpr;
	System::Classes::TList* FHistory;
	TcxRegExpr* FOwner;
	TcxRegExprSimpleState* FStartState;
	TcxRegExprStates* __fastcall GetAllNextStates(void);
	TcxRegExprStates* __fastcall Pop(void);
	void __fastcall Push(TcxRegExprStates* AStates);
	
public:
	__fastcall TcxRegExprAutomat(TcxRegExprParserAlts* AExpr, TcxRegExpr* AOwner);
	__fastcall virtual ~TcxRegExprAutomat(void);
	bool __fastcall IsFinal(void);
	bool __fastcall IsStart(void);
	bool __fastcall Next(System::WideChar &AToken, bool ACaseInsensitive, bool ACanChangeCase);
	bool __fastcall Prev(void);
	System::UnicodeString __fastcall Print(void);
	void __fastcall Reset(void);
	void __fastcall ReUpdate(void);
	void __fastcall Update(void);
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprQuantifier;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprQuantifier : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual bool __fastcall CanMissing(void) = 0 ;
	virtual bool __fastcall CanRepeat(void) = 0 ;
	virtual TcxRegExprQuantifier* __fastcall Clone(void) = 0 ;
	virtual System::UnicodeString __fastcall Print(void) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxRegExprQuantifier(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprQuantifier(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprSimpleQuantifier;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprSimpleQuantifier : public TcxRegExprQuantifier
{
	typedef TcxRegExprQuantifier inherited;
	
public:
	virtual bool __fastcall CanMissing(void);
	virtual bool __fastcall CanRepeat(void);
	virtual TcxRegExprQuantifier* __fastcall Clone(void);
	virtual System::UnicodeString __fastcall Print(void);
public:
	/* TObject.Create */ inline __fastcall TcxRegExprSimpleQuantifier(void) : TcxRegExprQuantifier() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprSimpleQuantifier(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprQuestionQuantifier;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprQuestionQuantifier : public TcxRegExprQuantifier
{
	typedef TcxRegExprQuantifier inherited;
	
public:
	virtual bool __fastcall CanMissing(void);
	virtual bool __fastcall CanRepeat(void);
	virtual TcxRegExprQuantifier* __fastcall Clone(void);
	virtual System::UnicodeString __fastcall Print(void);
public:
	/* TObject.Create */ inline __fastcall TcxRegExprQuestionQuantifier(void) : TcxRegExprQuantifier() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprQuestionQuantifier(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprStarQuantifier;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprStarQuantifier : public TcxRegExprQuantifier
{
	typedef TcxRegExprQuantifier inherited;
	
public:
	virtual bool __fastcall CanMissing(void);
	virtual bool __fastcall CanRepeat(void);
	virtual TcxRegExprQuantifier* __fastcall Clone(void);
	virtual System::UnicodeString __fastcall Print(void);
public:
	/* TObject.Create */ inline __fastcall TcxRegExprStarQuantifier(void) : TcxRegExprQuantifier() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprStarQuantifier(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprPlusQuantifier;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprPlusQuantifier : public TcxRegExprQuantifier
{
	typedef TcxRegExprQuantifier inherited;
	
public:
	virtual bool __fastcall CanMissing(void);
	virtual bool __fastcall CanRepeat(void);
	virtual TcxRegExprQuantifier* __fastcall Clone(void);
	virtual System::UnicodeString __fastcall Print(void);
public:
	/* TObject.Create */ inline __fastcall TcxRegExprPlusQuantifier(void) : TcxRegExprQuantifier() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegExprPlusQuantifier(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprParserItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprParserItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxRegExprQuantifier* FQuantifier;
	
public:
	__fastcall TcxRegExprParserItem(TcxRegExprQuantifier* AQuantifier);
	__fastcall virtual ~TcxRegExprParserItem(void);
	virtual bool __fastcall CanEmpty(void) = 0 ;
	bool __fastcall CanMissing(void);
	bool __fastcall CanRepeat(void);
	virtual TcxRegExprParserItem* __fastcall Clone(void) = 0 ;
	bool __fastcall NotQuantifier(void);
	virtual System::UnicodeString __fastcall Print(void) = 0 ;
	virtual void __fastcall SetFinal(void) = 0 ;
	void __fastcall SetQuantifier(TcxRegExprQuantifier* AQuantifier);
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprParserSimpleItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprParserSimpleItem : public TcxRegExprParserItem
{
	typedef TcxRegExprParserItem inherited;
	
private:
	TcxRegExprState* FState;
	
public:
	__fastcall TcxRegExprParserSimpleItem(TcxRegExprState* AState, TcxRegExprQuantifier* AQuantifier);
	__fastcall virtual ~TcxRegExprParserSimpleItem(void);
	virtual bool __fastcall CanEmpty(void);
	virtual TcxRegExprParserItem* __fastcall Clone(void);
	virtual System::UnicodeString __fastcall Print(void);
	virtual void __fastcall SetFinal(void);
	__property TcxRegExprState* State = {read=FState};
};

#pragma pack(pop)

class DELPHICLASS TcxRegExprParserBlockItem;
class DELPHICLASS TcxRegExprParserAlt;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprParserBlockItem : public TcxRegExprParserItem
{
	typedef TcxRegExprParserItem inherited;
	
private:
	TcxRegExprParserAlts* FAlts;
	TcxRegExprState* FFinishState;
	TcxRegExprState* FStartState;
	
public:
	__fastcall TcxRegExprParserBlockItem(TcxRegExprQuantifier* AQuantifier);
	__fastcall virtual ~TcxRegExprParserBlockItem(void);
	virtual bool __fastcall CanEmpty(void);
	void __fastcall CreateConnections(void);
	void __fastcall AddAlt(TcxRegExprParserAlt* AAlt);
	void __fastcall AddAlts(TcxRegExprParserAlts* AAlts);
	virtual TcxRegExprParserItem* __fastcall Clone(void);
	virtual System::UnicodeString __fastcall Print(void);
	virtual void __fastcall SetFinal(void);
	__property TcxRegExprParserAlts* Alts = {read=FAlts};
	__property TcxRegExprState* FinishState = {read=FFinishState};
	__property TcxRegExprState* StartState = {read=FStartState};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprParserAlt : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxRegExprParserItem* operator[](int AIndex) { return Item[AIndex]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxRegExprParserItem* __fastcall GetFirstItem(void);
	TcxRegExprParserItem* __fastcall GetItem(int AIndex);
	TcxRegExprParserItem* __fastcall GetLastItem(void);
	void __fastcall SetLastItem(TcxRegExprParserItem* AItem);
	
public:
	__fastcall TcxRegExprParserAlt(void);
	__fastcall virtual ~TcxRegExprParserAlt(void);
	void __fastcall Add(TcxRegExprParserItem* AItem);
	bool __fastcall CanEmpty(void);
	bool __fastcall CanMissing(void);
	TcxRegExprParserAlt* __fastcall Clone(void);
	void __fastcall CreateConnections(void);
	void __fastcall CreateFinalStates(void);
	TcxRegExprStates* __fastcall GetStartConnections(void);
	System::UnicodeString __fastcall Print(void);
	void __fastcall SetFinishConnection(TcxRegExprState* AFinishState);
	__property int Count = {read=GetCount, nodefault};
	__property TcxRegExprParserItem* FirstItem = {read=GetFirstItem};
	__property TcxRegExprParserItem* Item[int AIndex] = {read=GetItem/*, default*/};
	__property TcxRegExprParserItem* LastItem = {read=GetLastItem, write=SetLastItem};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegExprParserAlts : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxRegExprParserAlt* operator[](int AIndex) { return Alt[AIndex]; }
	
private:
	System::Classes::TList* FAlts;
	TcxRegExprParserAlt* __fastcall GetAlt(int AIndex);
	int __fastcall GetCount(void);
	TcxRegExprParserAlt* __fastcall GetLastAlt(void);
	
public:
	__fastcall TcxRegExprParserAlts(void);
	__fastcall virtual ~TcxRegExprParserAlts(void);
	void __fastcall Add(TcxRegExprParserAlt* AAlt);
	void __fastcall AddAlt(void);
	bool __fastcall CanEmpty(void);
	void __fastcall CreateConnections(void);
	void __fastcall CreateFinalStates(void);
	TcxRegExprParserAlts* __fastcall Clone(void);
	TcxRegExprStates* __fastcall GetStartConnections(void);
	System::UnicodeString __fastcall Print(void);
	void __fastcall SetFinishConnections(TcxRegExprState* AFinishState);
	bool __fastcall StartStateIsFinal(void);
	bool __fastcall ThereIsEmptyAlt(void);
	__property TcxRegExprParserAlt* Alt[int AIndex] = {read=GetAlt/*, default*/};
	__property int Count = {read=GetCount, nodefault};
	__property TcxRegExprParserAlt* LastAlt = {read=GetLastAlt};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxSymbolDeleteEvent)(void);

typedef void __fastcall (__closure *TcxSymbolUpdateEvent)(System::WideChar ASymbol);

class PASCALIMPLEMENTATION TcxRegExpr : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxRegExprAutomat* FAutomat;
	System::Classes::TList* FBlocks;
	int FChar;
	bool FCaseInsensitive;
	bool FCompiled;
	TcxRegExprErrors* FErrors;
	bool FFirstExpr;
	int FIndex;
	int FLexemIndex;
	TcxLexems* FLexems;
	int FLine;
	TcxSymbolDeleteEvent FOnSymbolDelete;
	TcxSymbolUpdateEvent FOnSymbolUpdate;
	System::Classes::TStringStream* FStream;
	bool FUpdateOn;
	void __fastcall Clear(void);
	bool __fastcall Decimal(System::WideChar AToken);
	bool __fastcall EmptyStream(void);
	TcxLexem __fastcall CreateLexem(int ALine, int AChar, TcxRegExprLexemCode ACode, System::UnicodeString AValue);
	bool __fastcall GetLexem(TcxLexem &ALexem);
	bool __fastcall GetToken(/* out */ System::WideChar &AToken);
	System::Classes::TStream* __fastcall GetStream(void);
	bool __fastcall Hexadecimal(System::WideChar AToken);
	bool __fastcall LookToken(/* out */ System::WideChar &AToken, int APtr);
	bool __fastcall ParseAlt(TcxRegExprParserAlt* AAlt, bool Global = true);
	TcxRegExprParserBlockItem* __fastcall ParseBlock(void);
	TcxRegExprParserSimpleItem* __fastcall ParseEnumeration(void);
	void __fastcall ParseExpr(void);
	void __fastcall ParseQuantifier(int &A, int &B);
	void __fastcall ScanASCII(int ALine, int AChar);
	void __fastcall ScanClass(void);
	void __fastcall ScanExpr(void);
	void __fastcall ScanEscape(int ALine, int AChar);
	bool __fastcall ScanInteger(int ALine, int AChar, System::WideChar &AToken);
	void __fastcall ScanQuantifier(void);
	void __fastcall ScanString(void);
	void __fastcall SetUpdateOn(bool AUpdateOn);
	bool __fastcall Space(System::WideChar AToken);
	void __fastcall SymbolDelete(void);
	void __fastcall SymbolUpdate(System::WideChar ASymbol);
	void __fastcall TestCompiledStatus(void);
	
public:
	__fastcall TcxRegExpr(void);
	__fastcall virtual ~TcxRegExpr(void);
	void __fastcall Compile(System::Classes::TStream* AStream);
	bool __fastcall IsCompiled(void);
	bool __fastcall IsFinal(void);
	bool __fastcall IsStart(void);
	bool __fastcall Next(System::WideChar &AToken);
	System::UnicodeString __fastcall NextEx(const System::UnicodeString AString);
	bool __fastcall Prev(void);
	System::UnicodeString __fastcall Print(void);
	void __fastcall Reset(void);
	__property bool CaseInsensitive = {read=FCaseInsensitive, write=FCaseInsensitive, nodefault};
	__property System::Classes::TStream* Stream = {read=GetStream};
	__property bool UpdateOn = {read=FUpdateOn, write=SetUpdateOn, nodefault};
	__property TcxSymbolDeleteEvent OnSymbolDelete = {read=FOnSymbolDelete, write=FOnSymbolDelete};
	__property TcxSymbolUpdateEvent OnSymbolUpdate = {read=FOnSymbolUpdate, write=FOnSymbolUpdate};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IsTextFullValid(const System::UnicodeString AText, const System::UnicodeString AMask);
extern PACKAGE bool __fastcall IsTextValid(const System::UnicodeString AText, const System::UnicodeString AMask);
}	/* namespace Cxregexpr */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXREGEXPR)
using namespace Cxregexpr;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxregexprHPP
