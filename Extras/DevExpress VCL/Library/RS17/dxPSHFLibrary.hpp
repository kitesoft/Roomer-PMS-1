// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSHFLibrary.pas' rev: 24.00 (Win32)

#ifndef DxpshflibraryHPP
#define DxpshflibraryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSUtl.hpp>	// Pascal unit
#include <dxPSImgs.hpp>	// Pascal unit
#include <dxPSRes.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpshflibrary
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxHFFunctionFormatObjectClass;

class DELPHICLASS TdxHFFunctionFormatObject;
class PASCALIMPLEMENTATION TdxHFFunctionFormatObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCurrentPage;
	System::UnicodeString FDateFormat;
	System::TDateTime FDateTime;
	System::UnicodeString FMachineName;
	Dxpsglbl::TdxPageNumberFormat FPageNumberFormat;
	int FStartPageIndex;
	System::UnicodeString FTimeFormat;
	int FTotalPages;
	System::UnicodeString FUserName;
	
protected:
	virtual void __fastcall Initialize(void);
	
public:
	__fastcall virtual TdxHFFunctionFormatObject(void);
	__property int CurrentPage = {read=FCurrentPage, write=FCurrentPage, nodefault};
	__property System::UnicodeString DateFormat = {read=FDateFormat, write=FDateFormat};
	__property System::TDateTime DateTime = {read=FDateTime, write=FDateTime};
	__property System::UnicodeString MachineName = {read=FMachineName, write=FMachineName};
	__property Dxpsglbl::TdxPageNumberFormat PageNumberFormat = {read=FPageNumberFormat, write=FPageNumberFormat, nodefault};
	__property int StartPageIndex = {read=FStartPageIndex, write=FStartPageIndex, nodefault};
	__property System::UnicodeString TimeFormat = {read=FTimeFormat, write=FTimeFormat};
	__property int TotalPages = {read=FTotalPages, write=FTotalPages, nodefault};
	__property System::UnicodeString UserName = {read=FUserName, write=FUserName};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFFunctionFormatObject(void) { }
	
};


class DELPHICLASS TdxHFFunctionCustomCategory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFFunctionCustomCategory : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxHFFunctionCustomCategory(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFFunctionCustomCategory(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxHFFunctionCustomCategoryClass;

class DELPHICLASS TdxHFFunctionAuthenticationCategory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFFunctionAuthenticationCategory : public TdxHFFunctionCustomCategory
{
	typedef TdxHFFunctionCustomCategory inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxHFFunctionAuthenticationCategory(void) : TdxHFFunctionCustomCategory() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFFunctionAuthenticationCategory(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFFunctionDateTimeCategory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFFunctionDateTimeCategory : public TdxHFFunctionCustomCategory
{
	typedef TdxHFFunctionCustomCategory inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxHFFunctionDateTimeCategory(void) : TdxHFFunctionCustomCategory() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFFunctionDateTimeCategory(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFFunctionImagesCategory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFFunctionImagesCategory : public TdxHFFunctionCustomCategory
{
	typedef TdxHFFunctionCustomCategory inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxHFFunctionImagesCategory(void) : TdxHFFunctionCustomCategory() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFFunctionImagesCategory(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFFunctionPagesCategory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFFunctionPagesCategory : public TdxHFFunctionCustomCategory
{
	typedef TdxHFFunctionCustomCategory inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxHFFunctionPagesCategory(void) : TdxHFFunctionCustomCategory() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFFunctionPagesCategory(void) { }
	
};

#pragma pack(pop)

typedef System::UnicodeString __fastcall (*TdxHFConvertFunction)(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);

typedef System::TMetaClass* TdxHFCustomFunctionClass;

class DELPHICLASS TdxHFCustomFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFCustomFunction : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Cxgraphics::TcxBitmap* FGlyph;
	System::UnicodeString FHint;
	bool FIsHintAssigned;
	bool FIsTemplateStringAssigned;
	System::UnicodeString FTemplateString;
	System::UnicodeString __fastcall GetHint(void);
	System::UnicodeString __fastcall GetTemplateString(void);
	void __fastcall SetGlyph(Cxgraphics::TcxBitmap* Value);
	void __fastcall SetTemplateString(const System::UnicodeString Value);
	void __fastcall SetHint(const System::UnicodeString Value);
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFCustomFunction(void);
	__fastcall virtual ~TdxHFCustomFunction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DoProcess(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	__classmethod TdxHFCustomFunctionClass __fastcall FunctionClass();
	__classmethod virtual TdxHFFunctionCustomCategoryClass __fastcall GetCategory();
	__classmethod virtual System::UnicodeString __fastcall GetName();
	__property Cxgraphics::TcxBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property System::UnicodeString Hint = {read=GetHint, write=SetHint};
	__property System::UnicodeString TemplateString = {read=GetTemplateString, write=SetTemplateString};
};

#pragma pack(pop)

class DELPHICLASS TdxHFPagesFunctions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFPagesFunctions : public TdxHFCustomFunction
{
	typedef TdxHFCustomFunction inherited;
	
public:
	__classmethod virtual TdxHFFunctionCustomCategoryClass __fastcall GetCategory();
public:
	/* TdxHFCustomFunction.Create */ inline __fastcall virtual TdxHFPagesFunctions(void) : TdxHFCustomFunction() { }
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFPagesFunctions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFPageNumberFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFPageNumberFunction : public TdxHFPagesFunctions
{
	typedef TdxHFPagesFunctions inherited;
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFPageNumberFunction(void);
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFPageNumberFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFTotalPagesFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFTotalPagesFunction : public TdxHFPagesFunctions
{
	typedef TdxHFPagesFunctions inherited;
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFTotalPagesFunction(void);
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFTotalPagesFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFPageOfPagesFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFPageOfPagesFunction : public TdxHFPagesFunctions
{
	typedef TdxHFPagesFunctions inherited;
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFPageOfPagesFunction(void);
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFPageOfPagesFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFAuthenticationFunctions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFAuthenticationFunctions : public TdxHFCustomFunction
{
	typedef TdxHFCustomFunction inherited;
	
public:
	__classmethod virtual TdxHFFunctionCustomCategoryClass __fastcall GetCategory();
public:
	/* TdxHFCustomFunction.Create */ inline __fastcall virtual TdxHFAuthenticationFunctions(void) : TdxHFCustomFunction() { }
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFAuthenticationFunctions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFMachineNameFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFMachineNameFunction : public TdxHFAuthenticationFunctions
{
	typedef TdxHFAuthenticationFunctions inherited;
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFMachineNameFunction(void);
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFMachineNameFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFUserNameFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFUserNameFunction : public TdxHFAuthenticationFunctions
{
	typedef TdxHFAuthenticationFunctions inherited;
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFUserNameFunction(void);
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFUserNameFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFDateTimeFunctions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFDateTimeFunctions : public TdxHFCustomFunction
{
	typedef TdxHFCustomFunction inherited;
	
public:
	__classmethod virtual TdxHFFunctionCustomCategoryClass __fastcall GetCategory();
public:
	/* TdxHFCustomFunction.Create */ inline __fastcall virtual TdxHFDateTimeFunctions(void) : TdxHFCustomFunction() { }
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFDateTimeFunctions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFDateTimeFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFDateTimeFunction : public TdxHFDateTimeFunctions
{
	typedef TdxHFDateTimeFunctions inherited;
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFDateTimeFunction(void);
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFDateTimeFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFDateFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFDateFunction : public TdxHFDateTimeFunctions
{
	typedef TdxHFDateTimeFunctions inherited;
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFDateFunction(void);
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFDateFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFTimeFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFTimeFunction : public TdxHFDateTimeFunctions
{
	typedef TdxHFDateTimeFunctions inherited;
	
protected:
	virtual System::UnicodeString __fastcall ConvertFunc(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFTimeFunction(void);
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFTimeFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFImageFunction;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFImageFunction : public TdxHFCustomFunction
{
	typedef TdxHFCustomFunction inherited;
	
protected:
	virtual System::UnicodeString __fastcall DefaultHintValue(void);
	virtual System::UnicodeString __fastcall DefaultTemplateStringValue(void);
	
public:
	__fastcall virtual TdxHFImageFunction(void);
	__classmethod virtual TdxHFFunctionCustomCategoryClass __fastcall GetCategory();
	__classmethod virtual System::UnicodeString __fastcall GetName();
public:
	/* TdxHFCustomFunction.Destroy */ inline __fastcall virtual ~TdxHFImageFunction(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHFFunctionLibrary;
typedef void __fastcall (__closure *TdxHFFunctionEnumProc)(TdxHFFunctionLibrary* Sender, TdxHFCustomFunction* const AHFFunction);

typedef System::TMetaClass* TdxHFFunctionLibraryClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFFunctionLibrary : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TdxHFCustomFunction* operator[](int Index) { return Funcs[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TdxHFCustomFunction* __fastcall GetFunction(int Index);
	TdxHFCustomFunction* __fastcall GetFunctionByClass(TdxHFCustomFunctionClass FunctionClass);
	void __fastcall SetFunction(int Index, TdxHFCustomFunction* Value);
	void __fastcall SetFunctionByClass(TdxHFCustomFunctionClass FunctionClass, TdxHFCustomFunction* Value);
	
public:
	__fastcall virtual TdxHFFunctionLibrary(void);
	__fastcall virtual ~TdxHFFunctionLibrary(void);
	TdxHFCustomFunction* __fastcall Add(TdxHFCustomFunctionClass AFunctionClass);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	virtual void __fastcall Enumerate(TdxHFFunctionEnumProc AProc);
	void __fastcall GetFunctions(System::Classes::TStrings* AStrings);
	void __fastcall GetFunctionsByCategory(TdxHFFunctionCustomCategoryClass ACategory, System::Classes::TStrings* AStrings);
	virtual int __fastcall IndexOf(const System::UnicodeString ATemplateString);
	int __fastcall IndexOfByName(const System::UnicodeString AFunctionName);
	int __fastcall IndexOfByClass(TdxHFCustomFunctionClass AFunctionClass);
	virtual System::UnicodeString __fastcall ProcessString(const System::UnicodeString Source, TdxHFFunctionFormatObject* const AFormatObject);
	__property int Count = {read=GetCount, nodefault};
	__property TdxHFCustomFunction* Funcs[int Index] = {read=GetFunction, write=SetFunction/*, default*/};
	__property TdxHFCustomFunction* FuncsByClass[TdxHFCustomFunctionClass FunctionClass] = {read=GetFunctionByClass, write=SetFunctionByClass};
};

#pragma pack(pop)

class DELPHICLASS TdxHFReportCellBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFReportCellBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	void __fastcall AlignDataItems(Dxpscore::TdxReportCell* ACell, Cxdrawtextutils::TcxTextAlignY AAlignment);
	void __fastcall CalculateTitlePartSize(Dxpscore::TdxReportCell* ACell, Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	
public:
	virtual void __fastcall Build(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxReportCells* AHost, const System::Types::TRect &R, Dxprnpg::TdxPageTitleParts ATitleParts, Dxprnpg::TCustomdxPageObject* APageObject, bool AReverseTitles);
	void __fastcall PlaceTitleParts(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxReportCell* AHostCell, const System::Types::TRect &R, Dxprnpg::TCustomdxPageObject* APageObject);
	void __fastcall PopulateCells(Dxpscore::TdxReportCell* AParentCell, Dxpscore::TdxReportCells* AHost, Cxdrawtextutils::TcxTextAlignX ATextAlignX, Dxprnpg::TdxPageTitlePart ATitlePart, Dxprnpg::TCustomdxPageObject* APageObject)/* overload */;
	virtual void __fastcall PopulateCells(Dxpscore::TdxReportCell* AParentCell, Dxpscore::TdxReportCells* AHost, const System::UnicodeString Source, Cxdrawtextutils::TcxTextAlignX ATextAlignX, Cxdrawtextutils::TcxTextAlignY ATextAlignY, Dxprnpg::TCustomdxPageObject* APageObject, TdxHFFunctionFormatObject* AFormatObject)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TdxHFReportCellBuilder(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFReportCellBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxStandardHFFunctionLibrary;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStandardHFFunctionLibrary : public TdxHFFunctionLibrary
{
	typedef TdxHFFunctionLibrary inherited;
	
protected:
	virtual void __fastcall AddStandardFunctions(void);
	
public:
	__fastcall virtual TdxStandardHFFunctionLibrary(void);
public:
	/* TdxHFFunctionLibrary.Destroy */ inline __fastcall virtual ~TdxStandardHFFunctionLibrary(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::StaticArray<System::WideChar, 2> dxFunctionDelimiters;
static const System::WideChar dxFunctionIndexSeparator = (System::WideChar)(0x3d);
static const System::WideChar dxHFFunctionSeparator = (System::WideChar)(0x2c);
extern PACKAGE TdxHFFunctionLibrary* dxHFFunctionLibrary;
extern PACKAGE TdxHFFunctionFormatObject* dxHFFormatObject;
extern PACKAGE void __fastcall dxPSSplitAutoHFTextEntry(System::UnicodeString Source, System::UnicodeString &APart1, System::UnicodeString &APart2, System::UnicodeString &APart3);
extern PACKAGE System::UnicodeString __fastcall dxProcessHFString(const System::UnicodeString Source);
extern PACKAGE void __fastcall dxGetHFFunctionsList(System::Classes::TStrings* AStrings);
extern PACKAGE void __fastcall dxGetHFFunctionsListByCategory(TdxHFFunctionCustomCategoryClass ACategory, System::Classes::TStrings* AStrings);
}	/* namespace Dxpshflibrary */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSHFLIBRARY)
using namespace Dxpshflibrary;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpshflibraryHPP
