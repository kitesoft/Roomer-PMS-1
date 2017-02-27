// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExcelFormulas.pas' rev: 24.00 (Win64)

#ifndef CxexcelformulasHPP
#define CxexcelformulasHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxExcelAccess.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxSSUtils.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexcelformulas
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TTokenConverter)(void);

typedef System::StaticArray<TTokenConverter, 256> TTokensDefinition;

class DELPHICLASS TcxFormulaReader;
class PASCALIMPLEMENTATION TcxFormulaReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCol;
	bool FConstructBreak;
	int FDefinitionCount;
	System::Word FOffset;
	Cxexcelaccess::TcxExcelFileReader* FOwner;
	int FRow;
	System::Classes::TStringList* FStringList;
	System::Byte FToken;
	Cxsstypes::TByteArray *FTokens;
	System::Word FTokensCount;
	TTokensDefinition FTokensDefinition;
	bool FUnknownFunction;
	System::UnicodeString __fastcall GetLastString(void);
	void __fastcall SetLastString(const System::UnicodeString Value);
	void __fastcall RegistryFunctions(void);
	
protected:
	System::UnicodeString __fastcall AreaRefToStr(int ACol, int ARow);
	void __fastcall ConvertptgAdd_ptgPercent(void);
	void __fastcall ConvertptgArea(void);
	void __fastcall ConvertptgAreaN(void);
	void __fastcall ConvertptgArea3d(void);
	void __fastcall ConvertptgAreaErr3d(void);
	void __fastcall ConvertptgAttr(void);
	void __fastcall ConvertptgBool(void);
	void __fastcall ConvertptgExp(void);
	void __fastcall ConvertptgErr(void);
	void __fastcall ConvertptgFunc(void);
	void __fastcall ConvertptgFuncVar(void);
	void __fastcall ConvertptgInt(void);
	void __fastcall ConvertptgMemFunc(void);
	void __fastcall ConvertptgMissArg(void);
	void __fastcall ConvertptgName(void);
	void __fastcall ConvertptgNum(void);
	void __fastcall ConvertptgParen(void);
	void __fastcall ConvertptgRef(void);
	void __fastcall ConvertptgRefNV(void);
	void __fastcall ConvertptgRef3d(void);
	void __fastcall ConvertptgRef3dErr(void);
	void __fastcall ConvertptgStr(void);
	void __fastcall ConvertptgTable(void);
	virtual bool __fastcall DoHashedConvertion(System::Byte AHashedToken);
	System::UnicodeString __fastcall GetArguments(int ACount, const System::UnicodeString AddStr = System::UnicodeString());
	System::UnicodeString __fastcall SheetNameByRef(int APage);
	System::UnicodeString __fastcall StrByPosition(int ACol, int ARow, bool AColAbs, bool ARowAbs)/* overload */;
	System::UnicodeString __fastcall StrByPosition(int ACol, int ARow)/* overload */;
	__property System::Word CurrentOffset = {read=FOffset, nodefault};
	__property bool ConstructBreak = {read=FConstructBreak, write=FConstructBreak, nodefault};
	__property System::UnicodeString LastString = {read=GetLastString, write=SetLastString};
	__property System::Byte Token = {read=FToken, nodefault};
	__property Cxsstypes::PByteArray Tokens = {read=FTokens, write=FTokens};
	__property System::Word TokensCount = {read=FTokensCount, nodefault};
	__property System::Classes::TStringList* Strings = {read=FStringList};
	
public:
	__fastcall virtual TcxFormulaReader(Cxexcelaccess::TcxExcelFileReader* AOwner);
	__fastcall virtual ~TcxFormulaReader(void);
	virtual System::UnicodeString __fastcall ConvertFormulas(int ACol, int ARow, Cxsstypes::PByteArray ATokens, System::Word AParsedLen);
	virtual void __fastcall RegistryConverters(System::Byte AToken, TTokenConverter AConvertFunc);
	__property Cxexcelaccess::TcxExcelFileReader* Owner = {read=FOwner};
	__property bool UnknownFunction = {read=FUnknownFunction, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::WideChar __fastcall ListSeparatorEx(void);
}	/* namespace Cxexcelformulas */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXCELFORMULAS)
using namespace Cxexcelformulas;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexcelformulasHPP
