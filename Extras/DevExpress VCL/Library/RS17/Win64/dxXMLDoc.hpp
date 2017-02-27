// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxXMLDoc.pas' rev: 24.00 (Win64)

#ifndef DxxmldocHPP
#define DxxmldocHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCustomTree.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.StrUtils.hpp>	// Pascal unit
#include <System.AnsiStrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxxmldoc
{
//-- type declarations -------------------------------------------------------
typedef System::AnsiString TdxXMLString;

typedef System::UnicodeString TdxXMLValueType;

class DELPHICLASS TdxXMLNodeAttribute;
class PASCALIMPLEMENTATION TdxXMLNodeAttribute : public Dxcoreclasses::TcxDoublyLinkedObject
{
	typedef Dxcoreclasses::TcxDoublyLinkedObject inherited;
	
private:
	TdxXMLString FName;
	TdxXMLString FValue;
	
public:
	int __fastcall GetDataSize(void);
	TdxXMLString __fastcall ToAnsiString(void);
	__property TdxXMLString Name = {read=FName, write=FName};
	__property TdxXMLString Value = {read=FValue, write=FValue};
public:
	/* TObject.Create */ inline __fastcall TdxXMLNodeAttribute(void) : Dxcoreclasses::TcxDoublyLinkedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxXMLNodeAttribute(void) { }
	
};


class DELPHICLASS TdxXMLNodeAttributes;
class DELPHICLASS TdxXMLNode;
class PASCALIMPLEMENTATION TdxXMLNodeAttributes : public Dxcoreclasses::TcxDoublyLinkedObjectList
{
	typedef Dxcoreclasses::TcxDoublyLinkedObjectList inherited;
	
private:
	int FCount;
	TdxXMLNodeAttribute* FFirst;
	TdxXMLNode* FNode;
	TdxXMLNodeAttribute* __fastcall GetLast(void);
	
protected:
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall CreateLinkedObject(void);
	TdxXMLString __fastcall GetAsText(void);
	
public:
	virtual Dxcoreclasses::TcxDoublyLinkedObject* __fastcall Add(void)/* overload */;
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName, const TdxXMLString AValue)/* overload */;
	HIDESBASE TdxXMLNodeAttribute* __fastcall Add(const TdxXMLString AttrName, const System::UnicodeString AValue)/* overload */;
	virtual void __fastcall Remove(Dxcoreclasses::TcxDoublyLinkedObject* &ALinkedObject);
	__property int Count = {read=FCount, nodefault};
	__property TdxXMLNodeAttribute* First = {read=FFirst};
	__property TdxXMLNodeAttribute* Last = {read=GetLast};
	__property TdxXMLNode* Node = {read=FNode};
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TdxXMLNodeAttributes(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxXMLNodeAttributes(void) : Dxcoreclasses::TcxDoublyLinkedObjectList() { }
	
};


class DELPHICLASS TdxXMLDocument;
class PASCALIMPLEMENTATION TdxXMLNode : public Dxcustomtree::TdxTreeCustomNode
{
	typedef Dxcustomtree::TdxTreeCustomNode inherited;
	
private:
	TdxXMLNodeAttributes* FAttributes;
	TdxXMLString FAttributesAsText;
	TdxXMLString FName;
	TdxXMLString FNamespaceURI;
	TdxXMLString FText;
	TdxXMLString __fastcall GetAttributesAsText(void);
	TdxXMLDocument* __fastcall GetDocument(void);
	void __fastcall SetText(const TdxXMLString AValue);
	
protected:
	virtual void __fastcall CheckEncodedText(TdxXMLString &AText);
	virtual int __fastcall GetAttributesSize(void);
	virtual int __fastcall GetChildrenSize(void);
	virtual int __fastcall GetDataSize(void);
	bool __fastcall HasData(void);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteAttributes(System::Classes::TStream* AStream);
	virtual void __fastcall WriteChildren(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	void __fastcall WriteString(System::Classes::TStream* AStream, const TdxXMLString AString);
	
public:
	__fastcall virtual TdxXMLNode(Dxcustomtree::_di_IdxTreeOwner AOwner);
	__fastcall virtual ~TdxXMLNode(void);
	HIDESBASE TdxXMLNode* __fastcall AddChild(const TdxXMLString ATagName)/* overload */;
	HIDESBASE TdxXMLNode* __fastcall AddChild(const TdxXMLString ATagName, const TdxXMLString ANamespaceURI)/* overload */;
	void __fastcall AddAttribute(const TdxXMLString AttrName, const System::WideString AValue);
	void __fastcall SetAttribute(const TdxXMLString AttrName, const System::Variant &AValue);
	__property TdxXMLNodeAttributes* Attributes = {read=FAttributes};
	__property TdxXMLString AttributesAsText = {read=GetAttributesAsText};
	__property TdxXMLDocument* Document = {read=GetDocument};
	__property TdxXMLString Name = {read=FName};
	__property TdxXMLString NamespaceURI = {read=FNamespaceURI};
	__property TdxXMLString Text = {read=FText, write=SetText};
};


class DELPHICLASS TdxXMLRootNode;
class PASCALIMPLEMENTATION TdxXMLRootNode : public TdxXMLNode
{
	typedef TdxXMLNode inherited;
	
protected:
	virtual int __fastcall GetDataSize(void);
	TdxXMLString __fastcall GetHeaderText(void);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
public:
	/* TdxXMLNode.Create */ inline __fastcall virtual TdxXMLRootNode(Dxcustomtree::_di_IdxTreeOwner AOwner) : TdxXMLNode(AOwner) { }
	/* TdxXMLNode.Destroy */ inline __fastcall virtual ~TdxXMLRootNode(void) { }
	
};


class PASCALIMPLEMENTATION TdxXMLDocument : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TdxXMLString FEncoding;
	TdxXMLNode* FRoot;
	TdxXMLString FStandAlone;
	TdxXMLString FVersion;
	
protected:
	void __fastcall BeforeDelete(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall BeginUpdate(void);
	bool __fastcall CanCollapse(Dxcustomtree::TdxTreeCustomNode* ASender);
	bool __fastcall CanExpand(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall Collapsed(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall DeleteNode(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall EndUpdate(void);
	void __fastcall Expanded(Dxcustomtree::TdxTreeCustomNode* ASender);
	virtual Dxcustomtree::TdxTreeCustomNodeClass __fastcall GetNodeClass(Dxcustomtree::TdxTreeCustomNode* ARelativeNode);
	System::Classes::TPersistent* __fastcall GetNodesOwner(void);
	void __fastcall LoadChildren(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall TreeNotification(Dxcustomtree::TdxTreeCustomNode* ASender, Dxcustomtree::TdxTreeNodeNotifications ANotification);
	
public:
	__fastcall virtual TdxXMLDocument(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxXMLDocument(void);
	TdxXMLNode* __fastcall AddChild(const TdxXMLString ATagName)/* overload */;
	TdxXMLNode* __fastcall AddChild(const TdxXMLString ATagName, const TdxXMLString ANamespaceURI)/* overload */;
	void __fastcall SaveToFile(const System::Sysutils::TFileName AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property TdxXMLString Encoding = {read=FEncoding, write=FEncoding};
	__property TdxXMLNode* Root = {read=FRoot};
	__property TdxXMLString Standalone = {read=FStandAlone, write=FStandAlone};
	__property TdxXMLString Version = {read=FVersion, write=FVersion};
private:
	void *__IdxTreeOwner;	/* Dxcustomtree::IdxTreeOwner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E5BD359F-E1D0-4ABC-9D9D-45A6516F2F8B}
	operator Dxcustomtree::_di_IdxTreeOwner()
	{
		Dxcustomtree::_di_IdxTreeOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomtree::IdxTreeOwner*(void) { return (Dxcustomtree::IdxTreeOwner*)&__IdxTreeOwner; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::AnsiString __fastcall dxXMLCheckValueText(const System::AnsiString AValue);
}	/* namespace Dxxmldoc */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXXMLDOC)
using namespace Dxxmldoc;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxxmldocHPP
