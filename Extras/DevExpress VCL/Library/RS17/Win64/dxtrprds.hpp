// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxtrprds.pas' rev: 24.00 (Win64)

#ifndef DxtrprdsHPP
#define DxtrprdsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxmdaset.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxtrprds
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDBTreePrintDataLink;
class DELPHICLASS TdxDBTreePrintData;
class PASCALIMPLEMENTATION TdxDBTreePrintDataLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	TdxDBTreePrintData* FPrintData;
	
protected:
	virtual void __fastcall ActiveChanged(void);
public:
	/* TDataLink.Create */ inline __fastcall TdxDBTreePrintDataLink(void) : Data::Db::TDataLink() { }
	/* TDataLink.Destroy */ inline __fastcall virtual ~TdxDBTreePrintDataLink(void) { }
	
};


class PASCALIMPLEMENTATION TdxDBTreePrintData : public Dxmdaset::TdxMemData
{
	typedef Dxmdaset::TdxMemData inherited;
	
private:
	TdxDBTreePrintDataLink* FDataLink;
	System::UnicodeString FKeyFieldName;
	System::UnicodeString FParentFieldName;
	int FLevelCount;
	System::Variant FRootValue;
	System::UnicodeString FRootStrValue;
	int FMaxLevelCount;
	Data::Db::TDataSource* __fastcall GetTreeDataSource(void);
	void __fastcall SetTreeDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetKeyFieldName(System::UnicodeString Value);
	void __fastcall SetLevelCount(int Value);
	void __fastcall SetParentFieldName(System::UnicodeString Value);
	void __fastcall SetRootStrValue(System::UnicodeString Value);
	void __fastcall RefreshStructure(void);
	
protected:
	void __fastcall CopyStructure(Data::Db::TDataSet* ASource);
	virtual void __fastcall DoAfterOpen(void);
	__property TdxDBTreePrintDataLink* DataLink = {read=FDataLink};
	
public:
	__fastcall virtual TdxDBTreePrintData(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDBTreePrintData(void);
	virtual void __fastcall Loaded(void);
	__property int MaxLevelCount = {read=FMaxLevelCount, nodefault};
	
__published:
	__property DataSource = {read=GetTreeDataSource, write=SetTreeDataSource};
	__property System::UnicodeString KeyField = {read=FKeyFieldName, write=SetKeyFieldName};
	__property int LevelCount = {read=FLevelCount, write=SetLevelCount, nodefault};
	__property System::UnicodeString ParentField = {read=FParentFieldName, write=SetParentFieldName};
	__property System::UnicodeString RootValue = {read=FRootStrValue, write=SetRootStrValue};
};


//-- var, const, procedure ---------------------------------------------------
#define cDBTreeLevelFieldName L"dx$level"
#define cDBTreeRecNoFieldName L"dx$recno"
#define cDBTreeHasChildrenFieldName L"dx$haschildren"
extern PACKAGE void __fastcall FillDBTreePrintedDataSet(TdxDBTreePrintData* ds1, Data::Db::TDataSet* ds2);
}	/* namespace Dxtrprds */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTRPRDS)
using namespace Dxtrprds;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxtrprdsHPP
