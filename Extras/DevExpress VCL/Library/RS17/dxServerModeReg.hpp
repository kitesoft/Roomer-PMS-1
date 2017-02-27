// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeReg.pas' rev: 24.00 (Win32)

#ifndef DxservermoderegHPP
#define DxservermoderegHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <TreeIntf.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <dxServerModeSQLAdapters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodereg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxServerModeCustomDataSourceEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxServerModeCustomDataSourceEditor : public Dxcorereg::TdxComponentEditor
{
	typedef Dxcorereg::TdxComponentEditor inherited;
	
private:
	Dxservermodedata::TdxServerModeCustomDataSource* __fastcall GetDataSource(void);
	
protected:
	virtual System::UnicodeString __fastcall GetProductName(void);
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
	void __fastcall ExecuteFieldsEditor(void);
	
public:
	__property Dxservermodedata::TdxServerModeCustomDataSource* DataSource = {read=GetDataSource};
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxServerModeCustomDataSourceEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxcorereg::TdxComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxServerModeCustomDataSourceEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxServerModeCustomDataSourceSprig;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxServerModeCustomDataSourceSprig : public Treeintf::TComponentSprig
{
	typedef Treeintf::TComponentSprig inherited;
	
protected:
	void __fastcall ConnectionFigureParent(Data::Db::TCustomConnection* AConnection);
	virtual System::UnicodeString __fastcall GetImpliedConnectionString(void);
	
public:
	virtual void __fastcall FigureParent(void);
	virtual bool __fastcall AnyProblems(void);
	virtual System::UnicodeString __fastcall Caption(void);
public:
	/* TComponentSprig.Create */ inline __fastcall virtual TdxServerModeCustomDataSourceSprig(System::Classes::TPersistent* AItem)/* overload */ : Treeintf::TComponentSprig(AItem) { }
	/* TComponentSprig.Create */ inline __fastcall TdxServerModeCustomDataSourceSprig(System::Classes::TPersistent* AItem, Treeintf::TSprig* AOwner)/* overload */ : Treeintf::TComponentSprig(AItem, AOwner) { }
	
public:
	/* TSprig.Destroy */ inline __fastcall virtual ~TdxServerModeCustomDataSourceSprig(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxServerModeDataSourceSprig;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxServerModeDataSourceSprig : public TdxServerModeCustomDataSourceSprig
{
	typedef TdxServerModeCustomDataSourceSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual System::UnicodeString __fastcall Caption(void);
public:
	/* TComponentSprig.Create */ inline __fastcall virtual TdxServerModeDataSourceSprig(System::Classes::TPersistent* AItem)/* overload */ : TdxServerModeCustomDataSourceSprig(AItem) { }
	/* TComponentSprig.Create */ inline __fastcall TdxServerModeDataSourceSprig(System::Classes::TPersistent* AItem, Treeintf::TSprig* AOwner)/* overload */ : TdxServerModeCustomDataSourceSprig(AItem, AOwner) { }
	
public:
	/* TSprig.Destroy */ inline __fastcall virtual ~TdxServerModeDataSourceSprig(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxServerModeQueryDataSourceSprig;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxServerModeQueryDataSourceSprig : public TdxServerModeCustomDataSourceSprig
{
	typedef TdxServerModeCustomDataSourceSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
public:
	/* TComponentSprig.Create */ inline __fastcall virtual TdxServerModeQueryDataSourceSprig(System::Classes::TPersistent* AItem)/* overload */ : TdxServerModeCustomDataSourceSprig(AItem) { }
	/* TComponentSprig.Create */ inline __fastcall TdxServerModeQueryDataSourceSprig(System::Classes::TPersistent* AItem, Treeintf::TSprig* AOwner)/* overload */ : TdxServerModeCustomDataSourceSprig(AItem, AOwner) { }
	
public:
	/* TSprig.Destroy */ inline __fastcall virtual ~TdxServerModeQueryDataSourceSprig(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxservermodereg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODEREG)
using namespace Dxservermodereg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermoderegHPP
