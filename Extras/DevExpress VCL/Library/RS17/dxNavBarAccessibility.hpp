// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarAccessibility.pas' rev: 24.00 (Win32)

#ifndef DxnavbaraccessibilityHPP
#define DxnavbaraccessibilityHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbaraccessibility
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	Dxnavbar::TdxCustomNavBar* __fastcall GetNavBar(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsContainer(void);
	__property Dxnavbar::TdxCustomNavBar* NavBar = {read=GetNavBar};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarGroupAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarGroupAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroup(void);
	Dxnavbar::TdxNavBarGroupViewInfo* __fastcall GetGroupViewInfo(void);
	Dxnavbar::TdxCustomNavBar* __fastcall GetNavBar(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsContainer(void);
	__property Dxnavbarcollns::TdxNavBarGroup* Group = {read=GetGroup};
	__property Dxnavbar::TdxNavBarGroupViewInfo* GroupViewInfo = {read=GetGroupViewInfo};
	__property Dxnavbar::TdxCustomNavBar* NavBar = {read=GetNavBar};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarGroupAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarGroupAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarGroupCaptionPanelAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarGroupCaptionPanelAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroup(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall CanBeFocusedByDefault(void);
	virtual void __fastcall Click(System::Word AKey);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsClickKey(System::Word AKey);
	virtual bool __fastcall IsContainer(void);
	virtual void __fastcall MakeVisible(void);
	__property Dxnavbarcollns::TdxNavBarGroup* Group = {read=GetGroup};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarGroupCaptionPanelAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarGroupCaptionPanelAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarItemLinkContainerAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarItemLinkContainerAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroup(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsContainer(void);
	virtual bool __fastcall IsScrollable(/* out */ int &AInvisiblePartHeight, /* out */ int &AChildMinTopScreenBound);
	__property Dxnavbarcollns::TdxNavBarGroup* Group = {read=GetGroup};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarItemLinkContainerAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarItemLinkContainerAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarItemLinkAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarItemLinkAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetLink(void);
	Dxnavbar::TdxNavBarLinkViewInfo* __fastcall GetLinkViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual void __fastcall RemoveFocus(void);
	virtual bool __fastcall CanBeFocusedByDefault(void);
	virtual void __fastcall Click(System::Word AKey);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsClickKey(System::Word AKey);
	virtual bool __fastcall IsContainer(void);
	virtual void __fastcall MakeVisible(void);
	__property Dxnavbarcollns::TdxNavBarItemLink* Link = {read=GetLink};
	__property Dxnavbar::TdxNavBarLinkViewInfo* LinkViewInfo = {read=GetLinkViewInfo};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarItemLinkAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarItemLinkAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbaraccessibility */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARACCESSIBILITY)
using namespace Dxnavbaraccessibility;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbaraccessibilityHPP
