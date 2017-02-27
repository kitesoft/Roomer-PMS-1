// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxStandardMask.pas' rev: 24.00 (Win32)

#ifndef CxstandardmaskHPP
#define CxstandardmaskHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxstandardmask
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxStandardMaskCustomItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMaskCustomItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AChar) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxStandardMaskCustomItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStandardMaskCustomItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStandardMaskLiteralItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMaskLiteralItem : public TcxStandardMaskCustomItem
{
	typedef TcxStandardMaskCustomItem inherited;
	
private:
	System::WideChar FLiteral;
	
public:
	__fastcall TcxStandardMaskLiteralItem(System::WideChar ALiteral);
	virtual bool __fastcall Check(System::WideChar &AChar);
	__property System::WideChar Literal = {read=FLiteral, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStandardMaskLiteralItem(void) { }
	
};

#pragma pack(pop)

enum TcxCaseControl : unsigned char { ccUpperCase, ccLowerCase, ccUserCase };

class DELPHICLASS TcxStandardMaskManyItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMaskManyItem : public TcxStandardMaskCustomItem
{
	typedef TcxStandardMaskCustomItem inherited;
	
private:
	TcxCaseControl FCaseControl;
	bool FOptional;
	
protected:
	void __fastcall DoCaseControl(System::WideChar &AChar);
	
public:
	__fastcall TcxStandardMaskManyItem(bool AOptional, TcxCaseControl ACaseControl);
	__property bool Optional = {read=FOptional, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStandardMaskManyItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStandardMaskAlphaItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMaskAlphaItem : public TcxStandardMaskManyItem
{
	typedef TcxStandardMaskManyItem inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AChar);
public:
	/* TcxStandardMaskManyItem.Create */ inline __fastcall TcxStandardMaskAlphaItem(bool AOptional, TcxCaseControl ACaseControl) : TcxStandardMaskManyItem(AOptional, ACaseControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStandardMaskAlphaItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStandardMaskAlphaNumericItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMaskAlphaNumericItem : public TcxStandardMaskManyItem
{
	typedef TcxStandardMaskManyItem inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AChar);
public:
	/* TcxStandardMaskManyItem.Create */ inline __fastcall TcxStandardMaskAlphaNumericItem(bool AOptional, TcxCaseControl ACaseControl) : TcxStandardMaskManyItem(AOptional, ACaseControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStandardMaskAlphaNumericItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStandardMaskASCIIItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMaskASCIIItem : public TcxStandardMaskManyItem
{
	typedef TcxStandardMaskManyItem inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AChar);
public:
	/* TcxStandardMaskManyItem.Create */ inline __fastcall TcxStandardMaskASCIIItem(bool AOptional, TcxCaseControl ACaseControl) : TcxStandardMaskManyItem(AOptional, ACaseControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStandardMaskASCIIItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStandardMaskNumericItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMaskNumericItem : public TcxStandardMaskManyItem
{
	typedef TcxStandardMaskManyItem inherited;
	
public:
	virtual bool __fastcall Check(System::WideChar &AChar);
public:
	/* TcxStandardMaskManyItem.Create */ inline __fastcall TcxStandardMaskNumericItem(bool AOptional, TcxCaseControl ACaseControl) : TcxStandardMaskManyItem(AOptional, ACaseControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStandardMaskNumericItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStandardMaskNumericSymbolItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMaskNumericSymbolItem : public TcxStandardMaskManyItem
{
	typedef TcxStandardMaskManyItem inherited;
	
public:
	__fastcall TcxStandardMaskNumericSymbolItem(bool AOptional, TcxCaseControl ACaseControl);
	virtual bool __fastcall Check(System::WideChar &AChar);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStandardMaskNumericSymbolItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxStandardMask;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStandardMask : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::WideChar FBlank;
	System::Classes::TList* FItems;
	bool FLeading;
	bool FSaveLiteralCharacters;
	System::UnicodeString FMask;
	void __fastcall Clear(void);
	void __fastcall DoCompileBody(const System::UnicodeString AMask);
	void __fastcall DoCompileHead(System::UnicodeString &AMask);
	int __fastcall GetCount(void);
	System::UnicodeString __fastcall GetEmptyString(void);
	System::UnicodeString __fastcall GetFullEmptyString(void);
	TcxStandardMaskCustomItem* __fastcall GetItems(int AIndex);
	
public:
	__fastcall TcxStandardMask(void);
	__fastcall virtual ~TcxStandardMask(void);
	void __fastcall Compile(System::UnicodeString AMask);
	void __fastcall Format(System::UnicodeString &AText, bool AChangeCharCase = true, bool AMatchForBlanksAndLiterals = true);
	void __fastcall Format2(System::UnicodeString &AText);
	bool __fastcall IsFullValid(System::UnicodeString &AText);
	bool __fastcall IsValid(System::UnicodeString &AText);
	__property System::WideChar Blank = {read=FBlank, write=FBlank, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString EmptyString = {read=GetEmptyString};
	__property System::UnicodeString FullEmptyString = {read=GetFullEmptyString};
	__property TcxStandardMaskCustomItem* Items[int AIndex] = {read=GetItems};
	__property System::UnicodeString Mask = {read=FMask};
	__property bool SaveLiteralCharacters = {read=FSaveLiteralCharacters, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::WideChar cxDefaultBlank = (System::WideChar)(0x5f);
extern PACKAGE System::UnicodeString __fastcall EmptyString(const System::UnicodeString AMask, const System::WideChar ABlank = (System::WideChar)(0x0));
extern PACKAGE System::UnicodeString __fastcall FormatText(const System::UnicodeString AText, const System::UnicodeString AMask, const System::WideChar ABlank = (System::WideChar)(0x0));
extern PACKAGE bool __fastcall IsTextFullValid(const System::UnicodeString AText, const System::UnicodeString AMask);
extern PACKAGE bool __fastcall IsTextValid(const System::UnicodeString AText, const System::UnicodeString AMask);
extern PACKAGE System::WideChar __fastcall MaskBlank(const System::UnicodeString AMask);
extern PACKAGE bool __fastcall SaveLiteralChars(const System::UnicodeString AMask);
}	/* namespace Cxstandardmask */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSTANDARDMASK)
using namespace Cxstandardmask;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxstandardmaskHPP
