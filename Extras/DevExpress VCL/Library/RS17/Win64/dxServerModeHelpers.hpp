// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeHelpers.pas' rev: 24.00 (Win64)

#ifndef DxservermodehelpersHPP
#define DxservermodehelpersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodehelpers
{
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<double> TdxPackSample;

typedef System::DynamicArray<TdxPackSample> TdxPackSampleArray;

class DELPHICLASS TdxServerModeServerAndChannelModelBuilder;
class DELPHICLASS TdxSampleList;
class DELPHICLASS TdxServerModeServerAndChannelModel;
class DELPHICLASS TdxSample;
class DELPHICLASS TdxLinearLeastSquaresArgs;
class PASCALIMPLEMENTATION TdxServerModeServerAndChannelModelBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxSampleList* FSamples;
	
protected:
	bool __fastcall IsInvalid(TdxServerModeServerAndChannelModel* ASolution);
	TdxPackSample __fastcall PackSample(TdxSample* ASample, System::UnicodeString ACombination);
	TdxServerModeServerAndChannelModel* __fastcall UnpackSolution(double *ALlsResults, const int ALlsResults_Size, System::UnicodeString ACombination);
	double __fastcall Weight(Dxcoreclasses::TdxFastList* ASamples, TdxServerModeServerAndChannelModel* ASolution);
	__property TdxSampleList* Samples = {read=FSamples};
	
public:
	__fastcall TdxServerModeServerAndChannelModelBuilder(void);
	__fastcall virtual ~TdxServerModeServerAndChannelModelBuilder(void);
	int __fastcall GetMaxObservableTake(void);
	TdxPackSample __fastcall Linear(int AUnknowns, TdxPackSampleArray AData);
	TdxPackSample __fastcall LinearLeastSquares(TdxLinearLeastSquaresArgs* AArgs);
	TdxPackSampleArray __fastcall PackSamples(Dxcoreclasses::TdxFastList* ASamples, const System::UnicodeString ACombination);
	void __fastcall RegisterSample(int ATake, int AScan, double time);
	TdxServerModeServerAndChannelModel* __fastcall Resolve(Dxcoreclasses::TdxFastList* ASamples, const System::UnicodeString ACombination)/* overload */;
	TdxServerModeServerAndChannelModel* __fastcall Resolve(void)/* overload */;
};


class PASCALIMPLEMENTATION TdxServerModeServerAndChannelModel : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	double FConstantPart;
	double FScanCoeff;
	double FTakeCoeff;
	
public:
	__fastcall TdxServerModeServerAndChannelModel(double AConstPart, double ATakeCoeff, double AScanCoeff);
	TdxServerModeServerAndChannelModel* __fastcall Clone(void);
	virtual System::UnicodeString __fastcall ToString(void);
	__property double ConstantPart = {read=FConstantPart};
	__property double ScanCoeff = {read=FScanCoeff};
	__property double TakeCoeff = {read=FTakeCoeff};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeServerAndChannelModel(void) { }
	
};


class DELPHICLASS TdxServerModeOptimalFetchParam;
class PASCALIMPLEMENTATION TdxServerModeOptimalFetchParam : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FBaseCountTakeData;
	double FEdgeTimeMultiplier;
	double FFillTimeMultiplier;
	int FIndex;
	int FMaxAllowedTake;
	int FMaxIndex;
	double FMiddleTimeMultiplier;
	int FMinIndex;
	TdxServerModeServerAndChannelModel* FModel;
	int FTotalCount;
	
public:
	__fastcall TdxServerModeOptimalFetchParam(TdxServerModeServerAndChannelModel* AModel, int AIndex, int AMinIndex, int AMaxIndex, int ATotalCount, int ABaseCountTakeData, int AMaxAllowedTake, double AFillTimeMultiplier, double AEdgeTimeMultiplier, double AMiddleTimeMultiplier);
	int __fastcall ScanFromBottom(int ALastIndexToFetch);
	int __fastcall ScanFromTop(int ALastIndexToFetch);
	int __fastcall SkipFromBottom(int AFirstIndexToFetch);
	int __fastcall SkipFromTop(int AFirstIndexToFetch);
	virtual System::UnicodeString __fastcall ToString(void);
	__property int BaseCountTakeData = {read=FBaseCountTakeData, nodefault};
	__property double EdgeTimeMultiplier = {read=FEdgeTimeMultiplier};
	__property double FillTimeMultiplier = {read=FFillTimeMultiplier};
	__property int Index = {read=FIndex, nodefault};
	__property int MaxAllowedTake = {read=FMaxAllowedTake, nodefault};
	__property int MaxIndex = {read=FMaxIndex, nodefault};
	__property double MiddleTimeMultiplier = {read=FMiddleTimeMultiplier};
	__property int MinIndex = {read=FMinIndex, nodefault};
	__property TdxServerModeServerAndChannelModel* Model = {read=FModel};
	__property int TotalCount = {read=FTotalCount, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeOptimalFetchParam(void) { }
	
};


class DELPHICLASS TdxServerModeOptimalFetchHelper;
class DELPHICLASS TdxServerModeOptimalFetchResult;
class DELPHICLASS TdxSolution;
class PASCALIMPLEMENTATION TdxServerModeOptimalFetchHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod TdxServerModeOptimalFetchResult* __fastcall CalculateOptimalFetchResult(TdxServerModeOptimalFetchParam* AParam);
	__classmethod bool __fastcall CalculateTakeFromFixedTimeAndScan(TdxServerModeServerAndChannelModel* AModel, double ATargetTime, int AScan, /* out */ int &AValue);
	__classmethod bool __fastcall CalculateTakeFromFixedTimeAndSkip(TdxServerModeServerAndChannelModel* AModel, double ATargetTime, int ASkip, /* out */ int &AValue);
	__classmethod TdxSolution* __fastcall OptimalResultCore(TdxServerModeOptimalFetchParam* AParam);
public:
	/* TObject.Create */ inline __fastcall TdxServerModeOptimalFetchHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeOptimalFetchHelper(void) { }
	
};


class PASCALIMPLEMENTATION TdxLinearLeastSquaresArgs : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxPackSampleArray FData;
	int FUnknowns;
	
public:
	__fastcall TdxLinearLeastSquaresArgs(int AUnknowns, TdxPackSampleArray AData);
	__property TdxPackSampleArray Data = {read=FData};
	__property int Unknowns = {read=FUnknowns, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLinearLeastSquaresArgs(void) { }
	
};


class PASCALIMPLEMENTATION TdxServerModeOptimalFetchResult : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsFromEnd;
	int FSkip;
	int FTake;
	
public:
	__fastcall TdxServerModeOptimalFetchResult(bool AIsFromEnd, int ASkip, int ATake);
	__property bool IsFromEnd = {read=FIsFromEnd, nodefault};
	__property int Skip = {read=FSkip, nodefault};
	__property int Take = {read=FTake, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeOptimalFetchResult(void) { }
	
};


class PASCALIMPLEMENTATION TdxSolution : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsFromEnd;
	TdxServerModeOptimalFetchParam* FParams;
	int FSkip;
	int FTake;
	int __fastcall GetScan(void);
	double __fastcall GetTime(void);
	
public:
	__fastcall TdxSolution(int ASkip, int ATake, bool AIsFromEnd, TdxServerModeOptimalFetchParam* AParams);
	TdxSolution* __fastcall FromI1I2(TdxServerModeOptimalFetchParam* AParams, bool AIsFromEnd, int I1, int I2);
	__classmethod TdxSolution* __fastcall FromSkipTake(TdxServerModeOptimalFetchParam* AParams, bool AIsFromEnd, int ASkip, int ATake);
	__property bool IsFromEnd = {read=FIsFromEnd, nodefault};
	__property int Scan = {read=GetScan, nodefault};
	__property int Skip = {read=FSkip, nodefault};
	__property int Take = {read=FTake, nodefault};
	__property double Time = {read=GetTime};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSolution(void) { }
	
};


class DELPHICLASS TdxSolutionList;
class PASCALIMPLEMENTATION TdxSolutionList : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	TdxSolution* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSolution* __fastcall GetItem(int Index);
	
public:
	__property TdxSolution* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxFastObjectList.Create */ inline __fastcall TdxSolutionList(bool AOwnsObjects, int ACapacity) : Dxcoreclasses::TdxFastObjectList(AOwnsObjects, ACapacity) { }
	
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TdxSolutionList(void) { }
	
};


class PASCALIMPLEMENTATION TdxSample : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FScan;
	int FTake;
	double FTime;
	
public:
	__fastcall TdxSample(int ATake, int AScan, double ATime);
	__property int Scan = {read=FScan, nodefault};
	__property int Take = {read=FTake, nodefault};
	__property double Time = {read=FTime};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSample(void) { }
	
};


class PASCALIMPLEMENTATION TdxSampleList : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	TdxSample* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSample* __fastcall GetItem(int Index);
	
public:
	__property TdxSample* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxFastObjectList.Create */ inline __fastcall TdxSampleList(bool AOwnsObjects, int ACapacity) : Dxcoreclasses::TdxFastObjectList(AOwnsObjects, ACapacity) { }
	
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TdxSampleList(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxservermodehelpers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODEHELPERS)
using namespace Dxservermodehelpers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodehelpersHPP
