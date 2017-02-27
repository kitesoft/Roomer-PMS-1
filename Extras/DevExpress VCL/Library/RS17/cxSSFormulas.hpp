// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSFormulas.pas' rev: 24.00 (Win32)

#ifndef CxssformulasHPP
#define CxssformulasHPP

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
#include <System.Math.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxSSData.hpp>	// Pascal unit
#include <cxSSUtils.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssformulas
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ECalculationError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION ECalculationError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ECalculationError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ECalculationError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ECalculationError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ECalculationError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ECalculationError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall ECalculationError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ECalculationError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ECalculationError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECalculationError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ECalculationError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECalculationError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ECalculationError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ECalculationError(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxFormulasCacheClass;

class DELPHICLASS TcxSSFormulasCache;
class DELPHICLASS TcxSSFunctionHandler;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSSFormulasCache : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Cxsstypes::TcxSSFuncRec operator[](int Index) { return FuncRec[Index]; }
	
private:
	bool FCalculationError;
	bool FCycled;
	Cxsstypes::TcxSSNamesDef FDefinedNames;
	Cxsstypes::TcxSSSheetsDef FDefinedSheets;
	bool FHandlerError;
	bool FIsLoading;
	System::Classes::TList* FFuncList;
	TcxSSFunctionHandler* FFuncHandler;
	System::TObject* FOwner;
	bool FRCRefStyle;
	bool FUpdating;
	Cxssdata::TcxSSDataStorage* __fastcall GetDataStorage(int APage);
	int __fastcall GetFuncCount(void);
	Cxsstypes::TcxSSFuncRec __fastcall GetFuncRec(int AIndex);
	System::TObject* __fastcall GetListener(void);
	bool __fastcall GetLock(void);
	void __fastcall SetCycled(const bool Value);
	void __fastcall SetLock(const bool Value);
	
protected:
	int FLockRef;
	bool __fastcall CalculationError(void);
	bool __fastcall CheckPageIndex(TcxSSFunctionHandler* Sender, int APage);
	TcxSSFunctionHandler* __fastcall CreateCalculator(void);
	void __fastcall DoRecalc(void);
	bool __fastcall GetCellValue(TcxSSFunctionHandler* Sender, System::Word APage, int ACol, int ARow, bool &AValue, bool &AIsBlank)/* overload */;
	bool __fastcall GetCellValue(TcxSSFunctionHandler* Sender, System::Word APage, int ACol, int ARow, double &AValue, bool &AIsBlank)/* overload */;
	bool __fastcall GetCellValue(TcxSSFunctionHandler* Sender, System::Word APage, int ACol, int ARow, System::UnicodeString &AValue, bool &AIsBlank)/* overload */;
	Cxsstypes::TcxSSNamesDef __fastcall GetNames(void);
	Cxsstypes::TcxSSSheetsDef __fastcall GetSheets(void);
	bool __fastcall RCReference(void);
	__property bool Cycled = {read=FCycled, write=SetCycled, nodefault};
	__property Cxssdata::TcxSSDataStorage* DataStorages[int APage] = {read=GetDataStorage};
	__property bool HandlerError = {read=FHandlerError, write=FHandlerError, nodefault};
	__property System::TObject* Listener = {read=GetListener};
	
public:
	__fastcall virtual TcxSSFormulasCache(System::TObject* AOwner);
	__fastcall virtual ~TcxSSFormulasCache(void);
	virtual void __fastcall Add(Cxsstypes::PcxSSFuncRec AFunction);
	virtual bool __fastcall AddFunction(Cxssdata::TcxSSDataStorage* ADataStorage, int ACol, int ARow);
	void __fastcall Clear(void);
	virtual Cxsstypes::PcxSSFuncRec __fastcall Clone(Cxsstypes::PcxSSFuncRec AFuncRecPtr);
	virtual bool __fastcall DeleteName(const System::UnicodeString AName);
	virtual int __fastcall DefineName(const System::UnicodeString AName, System::Word APage, const Cxsstypes::TRange &AArea, bool Validate = true);
	virtual void __fastcall DestroyFunction(Cxsstypes::PcxSSFuncRec AFuncRecPtr);
	virtual void __fastcall Evaluate(Cxsstypes::PcxSSFuncRec AFuncRecPtr);
	System::UnicodeString __fastcall FuncRecToDisplayText(Cxsstypes::PcxSSFuncRec AFuncRecPtr, System::Word &AColor, bool AHasFormat = true);
	System::Variant __fastcall GetFuncValue(Cxsstypes::PcxSSFuncRec AFuncRecPtr);
	virtual void __fastcall ReCalc(void);
	Cxsstypes::TcxStackItem __fastcall SpreadSheetTokensToExcelTokens(const Cxsstypes::PcxSSFuncRec AFunction);
	void __fastcall UpdateExternalLinks(Cxsstypes::PcxSSFuncRec AFuncRecPtr, int DR, int DC);
	virtual void __fastcall UpdateOnExchangeSheets(const int ASheet1, const int ASheet2);
	virtual void __fastcall UpdateOnDeleteSheet(const int ASheet);
	void __fastcall UpdateRef(const int ASheet, const System::Types::TRect &ARect, bool IsDelete, bool IsColumn);
	bool __fastcall ValidateRef(Cxsstypes::PcxSSFuncRec AFuncRecPtr);
	__property Cxsstypes::TcxSSNamesDef DefinedNames = {read=FDefinedNames};
	__property bool IsLoading = {read=FIsLoading, write=FIsLoading, nodefault};
	__property int FuncCount = {read=GetFuncCount, nodefault};
	__property TcxSSFunctionHandler* FuncHandler = {read=FFuncHandler};
	__property System::Classes::TList* FuncList = {read=FFuncList};
	__property Cxsstypes::TcxSSFuncRec FuncRec[int Index] = {read=GetFuncRec/*, default*/};
	__property bool Lock = {read=GetLock, write=SetLock, nodefault};
	__property Cxsstypes::TcxSSNamesDef Names = {read=GetNames};
	__property System::TObject* Owner = {read=FOwner};
	__property bool RCRefStyle = {read=FRCRefStyle, write=FRCRefStyle, nodefault};
	__property Cxsstypes::TcxSSSheetsDef Sheets = {read=GetSheets};
	__property bool Updating = {read=FUpdating, write=FUpdating, nodefault};
};

#pragma pack(pop)

typedef Cxsstypes::PcxSSFuncRec PcxSSFormulaRec;

typedef void __fastcall (*TcxSSFunction)(TcxSSFunctionHandler* Sender);

typedef TcxSSFunction *PcxSSFunction;

enum TcxValueType : unsigned char { vtString, vtFloat, vtBoolean };

typedef System::Set<TcxValueType, TcxValueType::vtString, TcxValueType::vtBoolean>  TcxValueTypes;

typedef void __fastcall (*TcxStringFuncCallBack)(TcxSSFunctionHandler* Sender, const System::UnicodeString Value);

typedef void __fastcall (*TcxFloatFuncCallBack)(TcxSSFunctionHandler* Sender, const double Value);

struct TcxFuncDefinition;
typedef TcxFuncDefinition *PcxFuncDefinition;

struct DECLSPEC_DRECORD TcxFuncDefinition
{
public:
	System::Word Token;
	System::UnicodeString Name;
	TcxSSFunction Definition;
	#pragma pack(push,1)
	
public:
	Cxexcelconst::TcxSSFuncParams Params;
	union
	{
		struct 
		{
			System::Byte ParamsCount;
		};
		
	};
	#pragma pack(pop)
};


enum TcxSSErrorCode : unsigned char { ecNone, ecNull, ecDivZero, ecValue, ecRefErr, ecName, ecNUM, ecNA };

typedef System::DynamicArray<Cxsstypes::TcxStackItem> TcxStackItems;

class DELPHICLASS TcxTokensStack;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTokensStack : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxStackItems FStackItems;
	int __fastcall GetItemsCount(void);
	
protected:
	Cxsstypes::TcxStackItem __fastcall StackCreateItem(const void *AData, int ASize);
	Cxsstypes::TcxStackItem __fastcall StackCreateTokenItem(System::Byte AToken, const void *AData, int ASize);
	Cxsstypes::TcxStackItem __fastcall StackGetBooleanItem(const bool AValue);
	Cxsstypes::TcxStackItem __fastcall StackGetByteItem(const System::Byte AValue);
	Cxsstypes::TcxStackItem __fastcall StackGetWordItem(const System::Word AValue);
	Cxsstypes::TcxStackItem __fastcall StackGetFloatItem(const double AValue);
	Cxsstypes::TcxStackItem __fastcall StackGetLongStringItem(const System::WideString AValue);
	Cxsstypes::TcxStackItem __fastcall StackGetStringItem(const System::UnicodeString AValue);
	Cxsstypes::TcxStackItem __fastcall StackItemAlloc(const int ASize);
	__classmethod void __fastcall StackItemEmpty(Cxsstypes::TcxStackItem &AStack);
	Cxsstypes::TcxStackItem __fastcall StackUnion(const Cxsstypes::TcxStackItem &ASrc1, const Cxsstypes::TcxStackItem &ASrc2);
	Cxsstypes::TcxStackItem __fastcall StackUnions(Cxsstypes::TcxStackItem const *AStackItems, const int AStackItems_Size);
	
public:
	__fastcall virtual TcxTokensStack(void);
	__fastcall virtual ~TcxTokensStack(void);
	void __fastcall Clear(void);
	__classmethod Cxsstypes::TcxStackItem __fastcall Clone(const Cxsstypes::TcxStackItem &AItem);
	void __fastcall Pop(void);
	void __fastcall StackAdd(const Cxsstypes::TcxStackItem &AItem);
	void __fastcall StackAddFuncItem(System::Word AFuncToken, int ABeginParams);
	void __fastcall StackCombine(int APos1, int APos2);
	void __fastcall StackCombineForward(void);
	void __fastcall StackCombines(int AFromPos)/* overload */;
	void __fastcall StackCombines(const int APosition, const int AItemsCount)/* overload */;
	Cxsstypes::TcxStackItem __fastcall StackGetItemAt(int APosition, bool NeedRemove = true);
	__classmethod void __fastcall StackItemClear(Cxsstypes::TcxStackItem &AStack);
	System::UnicodeString __fastcall StackTokensToStr(Cxsstypes::PByteArray ATokens);
	int __fastcall StackItemSize(const Cxsstypes::TcxStackItem &AStackItem);
	System::Byte __fastcall StackItemType(const Cxsstypes::TcxStackItem &AStackItem);
	Cxsstypes::TcxStackItem __fastcall StackPopItem(void)/* overload */;
	Cxsstypes::TcxStackItem __fastcall StackPopItem(Cxsstypes::TcxStackItem &AItem)/* overload */;
	Cxsstypes::TcxStackItem __fastcall StackPopItems(int ACount);
	Cxsstypes::TcxStackItem __fastcall StackTokensToItem(const Cxsstypes::PByteArray ATokens);
	virtual int __fastcall TokensSize(Cxsstypes::PByteArray ATokens);
	__property int ItemsCount = {read=GetItemsCount, nodefault};
	__property TcxStackItems StackItems = {read=FStackItems};
};

#pragma pack(pop)

class DELPHICLASS TcxStackItemObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStackItemObject : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Cxsstypes::TcxStackItem Item;
	int Priority;
	__fastcall virtual ~TcxStackItemObject(void);
public:
	/* TObject.Create */ inline __fastcall TcxStackItemObject(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSpreadSheetExpressionParser;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSpreadSheetExpressionParser : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TcxSSFunctionHandler* Handler;
	bool __fastcall CheckUnaryOperation(Cxsstypes::TcxStackItem &AItem, System::Byte &AToken, int APrevPriority, int APrevToken);
	Cxsstypes::TcxStackItem __fastcall CreateFuncItem(System::Byte AParamsCount, System::Word AFuncID);
	bool __fastcall IsArea(System::Byte ACode);
	Cxsstypes::TcxStackItem __fastcall PopAll(Cxclasses::TcxObjectList* AList);
	
public:
	__fastcall TcxSpreadSheetExpressionParser(TcxSSFunctionHandler* AHandler);
	Cxsstypes::TcxStackItem __fastcall DoParse(System::UnicodeString &AExpression, System::Byte &AParamsCount);
	System::Byte __fastcall GetNextItemFromString(System::UnicodeString &AString, System::UnicodeString &ASubExp, Cxsstypes::TcxStackItem &AItem);
	bool __fastcall CompareStackPriority(Cxclasses::TcxObjectList* AList, int APriority);
	int __fastcall Priority(System::Byte AToken);
	void __fastcall Push(Cxclasses::TcxObjectList* AList, const Cxsstypes::TcxStackItem &AItem, int APriority = 0xffffffff);
	Cxsstypes::TcxStackItem __fastcall Pop(Cxclasses::TcxObjectList* AList);
	void __fastcall PopAndPush(Cxclasses::TcxObjectList* ASource, Cxclasses::TcxObjectList* ADest);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSpreadSheetExpressionParser(void) { }
	
};

#pragma pack(pop)

enum TcxSSResultType : unsigned char { rtString, rtValue };

class PASCALIMPLEMENTATION TcxSSFunctionHandler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCallBackIndex;
	int FCol;
	TcxSSErrorCode FErrorCode;
	System::StaticArray<System::Byte, 15> FExtraChars;
	double FFloatValue;
	bool FFuncHasResult;
	Cxsstypes::TcxSSFuncRec *FFuncPtr;
	bool FIsBlankCell;
	bool FIsValueAssigned;
	TcxSSFormulasCache* FOwner;
	int FPage;
	int FParamsCount;
	TcxSSResultType FResultType;
	int FRow;
	System::UnicodeString FStringValue;
	TcxTokensStack* FStack;
	System::Classes::TStringList* FStringList;
	bool __fastcall IsArea(System::Byte ACode);
	bool __fastcall IsExtraChar(System::Byte ACode);
	bool __fastcall CheckColReference(System::UnicodeString &AString, int &ACol, bool &AbsCol);
	bool __fastcall CheckColRowReference(System::UnicodeString &AString, int &ACol, int &ARow, bool &AbsCol, bool &AbsRow);
	bool __fastcall CheckColumnAndRow(int ACol, int ARow, int AColOfs, int ARowOfs, bool AbsCol, bool AbsRow, int &Col, int &Row);
	bool __fastcall CheckNameReference(System::UnicodeString &AString, short &ANameIndex);
	System::Byte __fastcall CheckOrdinalOperation(const System::UnicodeString AString);
	bool __fastcall CheckRowReference(System::UnicodeString &AString, int &ARow, bool &AbsRow);
	void __fastcall EvaluateOrdinal(System::Byte AToken);
	void __fastcall EvaluateFunction(Cxsstypes::PByteArray ATokens);
	bool __fastcall GetColumnFromStr(System::UnicodeString &AString, int &AValue);
	bool __fastcall GetIntFromStr(System::UnicodeString &AString, int &AValue);
	System::UnicodeString __fastcall GetExtraChars(void);
	bool __fastcall GetError(void);
	bool __fastcall GetReferenceFromString(Cxsstypes::TcxStackItem &AReference, const System::UnicodeString AString);
	void __fastcall GetRefParams(Cxsstypes::PByteArray ATokens, int &APage, int &ACol, int &ARow);
	void __fastcall OrdinalBooleanEvaluate(const System::Byte AOperation);
	void __fastcall OrdinalIntersectEvaluate(void);
	void __fastcall OrdinalMainEvaluate(const System::Byte AOperation);
	System::UnicodeString __fastcall ptgRefToStr(System::Word AIndex)/* overload */;
	System::UnicodeString __fastcall ptgRefToStr(Cxsstypes::PBoolArray AIsAbsolute, Cxsstypes::PIntArray ATokens)/* overload */;
	System::UnicodeString __fastcall ptgRefToStr(System::Word ASheet, Cxsstypes::PBoolArray AIsAbsolute, Cxsstypes::PIntArray ATokens)/* overload */;
	System::UnicodeString __fastcall ptgRefToStr(System::Word ASheet, const bool AbsCol, const bool AbsRow, const int ACol, const int ARow)/* overload */;
	System::UnicodeString __fastcall ptgRefToStr(const bool AbsCol, const bool AbsRow, int ACol, int ARow)/* overload */;
	void __fastcall RestorePosition(void);
	void __fastcall SetAbsolutePosition(void);
	void __fastcall SetFloatValue(const double Value);
	void __fastcall SetFuncVarFromTokens(Cxsstypes::PByteArray ATokens);
	void __fastcall SetOrdinalFromTokens(Cxsstypes::PByteArray ATokens);
	void __fastcall SetReferenceFromTokens(Cxsstypes::PByteArray ATokens);
	void __fastcall SetStringFromTokens(Cxsstypes::PByteArray ATokens);
	void __fastcall SetStringValue(const System::UnicodeString Value);
	Cxsstypes::TcxStackItem __fastcall StackAreaToExcelTokens(Cxsstypes::PByteArray ATokens);
	void __fastcall StackTokensToArea(Cxsstypes::PByteArray ATokens, System::Word &APage, Cxsstypes::TRange &ARange);
	
protected:
	virtual void __fastcall CheckExtraChars(void);
	virtual bool __fastcall CheckString(const System::UnicodeString AString, System::UnicodeString &ACheckedString);
	System::Byte __fastcall CheckStringItem(const System::UnicodeString AString, Cxsstypes::TcxStackItem &AStackItem);
	virtual Cxsstypes::TcxStackItem __fastcall DoParse(System::UnicodeString &AString);
	virtual void __fastcall EnumCellsAreas(Cxsstypes::PByteArray ATokens, void * AFunc, TcxValueTypes AValueType);
	bool __fastcall GetAreaInfo(Cxsstypes::PByteArray ATokens, int &APage, Cxsstypes::TRange &ARange);
	virtual System::Byte __fastcall GetNextStackItemFromString(System::UnicodeString &AString, System::UnicodeString &ASubExp, Cxsstypes::TcxStackItem &AStackItem);
	System::UnicodeString __fastcall GetSubExpression(System::UnicodeString &AString);
	virtual System::UnicodeString __fastcall GetSubString(System::UnicodeString &AString);
	virtual System::Byte __fastcall GetUnknownItem(Cxsstypes::TcxStackItem &AStackItem, const System::UnicodeString AString);
	virtual void __fastcall Initialize(Cxsstypes::PcxSSFuncRec AFormulaPtr, bool ClearResult = true);
	void __fastcall ShowMessage(const System::UnicodeString AMessage);
	__classmethod System::UnicodeString __fastcall ValidSheetName(const System::UnicodeString ASheetName);
	__property System::UnicodeString ExtraChars = {read=GetExtraChars};
	__property bool FuncHasResult = {read=FFuncHasResult, write=FFuncHasResult, nodefault};
	__property TcxSSFormulasCache* Owner = {read=FOwner};
	__property TcxSSResultType ResultType = {read=FResultType, write=FResultType, nodefault};
	__property TcxTokensStack* Stack = {read=FStack};
	
public:
	__fastcall virtual TcxSSFunctionHandler(TcxSSFormulasCache* AOwner);
	__fastcall virtual ~TcxSSFunctionHandler(void);
	bool __fastcall CheckCondition(bool ACondition, TcxSSErrorCode AErrCode);
	virtual bool __fastcall GetBooleanParameter(void);
	virtual double __fastcall GetFloatParameter(void);
	virtual System::UnicodeString __fastcall GetStringParameter(void)/* overload */;
	virtual System::UnicodeString __fastcall GetStringParameter(System::Byte &AType)/* overload */;
	virtual void __fastcall EvaluateExpression(Cxsstypes::PcxSSFuncRec AFormulaPtr);
	virtual void __fastcall EnumParamValues(void * AFunc, TcxValueTypes AValueTypes);
	__classmethod System::UnicodeString __fastcall ErrorCodeToStr(TcxSSErrorCode ACode);
	void __fastcall SetBooleanResult(const bool Value);
	void __fastcall SetError(TcxSSErrorCode ACode);
	void __fastcall SetFloatResult(const double Value);
	void __fastcall SetStringResult(const System::UnicodeString Value);
	virtual void __fastcall StringToTokens(const System::UnicodeString AExpression, Cxsstypes::PcxSSFuncRec AFormulaPtr);
	virtual Cxsstypes::TcxStackItem __fastcall TokensToExcelFormat(Cxsstypes::PcxSSFuncRec AFormulaPtr);
	virtual System::UnicodeString __fastcall TokensToString(Cxsstypes::PcxSSFuncRec AFormulaPtr);
	__classmethod bool __fastcall FuncDefByToken(const System::Word AToken, TcxFuncDefinition &ADef);
	__classmethod bool __fastcall FuncDefByName(const System::UnicodeString AName, TcxFuncDefinition &ADef);
	__classmethod int __fastcall RegisterFunctions(TcxFuncDefinition const *AFuncList, const int AFuncList_Size);
	__property int CallBackIndex = {read=FCallBackIndex, nodefault};
	__property int Col = {read=FCol, nodefault};
	__property bool Error = {read=GetError, nodefault};
	__property TcxSSErrorCode ErrorCode = {read=FErrorCode, nodefault};
	__property double FloatValue = {read=FFloatValue, write=SetFloatValue};
	__property bool IsValueAssigned = {read=FIsValueAssigned, nodefault};
	__property bool IsBlankCell = {read=FIsBlankCell, nodefault};
	__property int Page = {read=FPage, nodefault};
	__property int ParamsCount = {read=FParamsCount, nodefault};
	__property int Row = {read=FRow, nodefault};
	__property System::UnicodeString StringValue = {read=FStringValue, write=SetStringValue};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxssformulas */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSFORMULAS)
using namespace Cxssformulas;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssformulasHPP
