// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPpAttr.pas' rev: 24.00 (Win32)

#ifndef DxppattrHPP
#define DxppattrHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxppattr
{
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TFloatSize
{
public:
	System::Extended cx;
	System::Extended cy;
};


class DELPHICLASS TdxPaper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPaper : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FName;
	System::UnicodeString FShortName;
	System::Types::TPoint FSize;
	int FDMPaper;
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(int Value);
	void __fastcall SetWidth(int Value);
	
public:
	__fastcall TdxPaper(const System::UnicodeString AName, const System::UnicodeString AShortName, int AWidth, int AHeight, int ADMPaper);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TdxPaper* __fastcall Clone(void);
	__property int DMPaper = {read=FDMPaper, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property System::UnicodeString Name = {read=FName};
	__property System::UnicodeString ShortName = {read=FShortName};
	__property System::Types::TPoint Size = {read=FSize, write=FSize};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPaper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPapers;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPapers : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TdxPaper* operator[](int Index) { return Papers[Index]; }
	
private:
	System::Classes::TList* FPapers;
	int __fastcall GetCount(void);
	TdxPaper* __fastcall GetPaper(int Index);
	
protected:
	virtual void __fastcall AddPapers(void);
	
public:
	__fastcall virtual TdxPapers(void);
	__fastcall virtual ~TdxPapers(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	int __fastcall FindByDMPaper(int ADMPaper);
	int __fastcall FindByName(const System::UnicodeString AName);
	int __fastcall FindByShortName(const System::UnicodeString AShortName);
	int __fastcall FindBySize(int AWidth, int AHeight);
	void __fastcall Refresh(void);
	__property int Count = {read=GetCount, nodefault};
	__property TdxPaper* Papers[int Index] = {read=GetPaper/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TdxBin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBin : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FName;
	int FValue;
	
public:
	__fastcall virtual TdxBin(int AValue, const System::UnicodeString AName);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::UnicodeString Name = {read=FName};
	__property int Value = {read=FValue, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxBin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBins;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBins : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TdxBin* operator[](int Index) { return Bins[Index]; }
	
private:
	System::Classes::TList* FBins;
	TdxBin* __fastcall GetBin(int Index);
	int __fastcall GetCount(void);
	
protected:
	virtual void __fastcall AddBins(void);
	
public:
	__fastcall virtual TdxBins(void);
	__fastcall virtual ~TdxBins(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	int __fastcall FindByName(const System::UnicodeString AName);
	int __fastcall FindByValue(int AValue);
	int __fastcall IndexOf(TdxBin* ABin);
	void __fastcall Refresh(void);
	__property TdxBin* Bins[int Index] = {read=GetBin/*, default*/};
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxBins* __fastcall Bins(void);
extern PACKAGE TdxPapers* __fastcall Papers(void);
extern PACKAGE TdxBins* __fastcall SetBins(TdxBins* Value);
extern PACKAGE TdxPapers* __fastcall SetPapers(TdxPapers* Value);
}	/* namespace Dxppattr */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPPATTR)
using namespace Dxppattr;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxppattrHPP
