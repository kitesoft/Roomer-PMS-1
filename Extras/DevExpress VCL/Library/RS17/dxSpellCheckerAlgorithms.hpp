// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerAlgorithms.pas' rev: 24.00 (Win32)

#ifndef DxspellcheckeralgorithmsHPP
#define DxspellcheckeralgorithmsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckeralgorithms
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDoubleMetaphone;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDoubleMetaphone : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsSlavoGermanic;
	bool FIsSlavoGermanicReady;
	System::WideChar *FLast;
	int FLength;
	System::WideChar *FPrimary;
	int FPrimaryLen;
	System::WideChar *FAlternate;
	int FAlternateLen;
	System::WideChar *FValue;
	System::WideString __fastcall GetAlternate(void);
	System::Word __fastcall GetAlternateKey(void);
	System::WideString __fastcall GetPrimary(void);
	System::Word __fastcall GetPrimaryKey(void);
	void __fastcall MetaphPrimaryAdd(System::WideChar AChar);
	void __fastcall MetaphAlternateAdd(System::WideChar AChar);
	void __fastcall ProcessB(void);
	void __fastcall ProcessC(void);
	void __fastcall ProcessD(void);
	void __fastcall ProcessF(void);
	void __fastcall ProcessG(void);
	void __fastcall ProcessH(void);
	void __fastcall ProcessJ(void);
	void __fastcall ProcessK(void);
	void __fastcall ProcessL(void);
	void __fastcall ProcessM(void);
	void __fastcall ProcessN(void);
	void __fastcall ProcessP(void);
	void __fastcall ProcessQ(void);
	void __fastcall ProcessR(void);
	void __fastcall ProcessS(void);
	void __fastcall ProcessT(void);
	void __fastcall ProcessV(void);
	void __fastcall ProcessW(void);
	void __fastcall ProcessX(void);
	void __fastcall ProcessZ(void);
	void __fastcall Reset(System::WideChar * P, int ALength);
	
protected:
	System::WideChar *Current;
	bool __fastcall AtEnd(void);
	bool __fastcall AtStart(void);
	bool __fastcall Contains(System::WideChar * AStart, int ALength, System::WideChar * APatterns);
	int __fastcall CurrentIndex(void);
	bool __fastcall IsSlavoGermanic(void);
	bool __fastcall IsVowel(System::WideChar * P);
	void __fastcall MetaphAdd(System::WideChar APrimary, System::WideChar AAlternate = (System::WideChar)(0x0));
	__property System::WideChar * Last = {read=FLast};
	__property int Length = {read=FLength, nodefault};
	__property System::WideChar * Value = {read=FValue, write=FValue};
	
public:
	__fastcall TdxDoubleMetaphone(void);
	__fastcall virtual ~TdxDoubleMetaphone(void);
	void __fastcall DoubleMetaphone(System::WideChar * P, int ALength);
	__property System::WideString Alternate = {read=GetAlternate};
	__property System::Word AlternateKey = {read=GetAlternateKey, nodefault};
	__property System::WideString Primary = {read=GetPrimary};
	__property System::Word PrimaryKey = {read=GetPrimaryKey, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxStringSimilarityCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStringSimilarityCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	int __fastcall DeleteCost(System::WideChar * S);
	int __fastcall InsertCost(System::WideChar * S);
	int __fastcall SubstitutionCost(System::WideChar * S1, System::WideChar * S2);
	
public:
	int __fastcall GetDistance(System::WideChar * AStr1, int ALen1, System::WideChar * AStr2, int ALen2);
	int __fastcall GetLongestCommonSubsequenceLength(System::WideChar * S1, System::WideChar * S2);
public:
	/* TObject.Create */ inline __fastcall TdxStringSimilarityCalculator(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStringSimilarityCalculator(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 MaxSoundLen = System::Int8(0x4);
}	/* namespace Dxspellcheckeralgorithms */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERALGORITHMS)
using namespace Dxspellcheckeralgorithms;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckeralgorithmsHPP
