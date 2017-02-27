// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxXLSXExport.pas' rev: 24.00 (Win64)

#ifndef DxxlsxexportHPP
#define DxxlsxexportHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <cxExport.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.RTLConsts.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.FmtBcd.hpp>	// Pascal unit
#include <Data.SqlTimSt.hpp>	// Pascal unit
#include <System.ZLib.hpp>	// Pascal unit
#include <cxExportStrs.hpp>	// Pascal unit
#include <dxCustomTree.hpp>	// Pascal unit
#include <dxXMLDoc.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <System.AnsiStrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxxlsxexport
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EdxPackedStreamReader;
class PASCALIMPLEMENTATION EdxPackedStreamReader : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxPackedStreamReader(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxPackedStreamReader(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : System::Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxPackedStreamReader(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxPackedStreamReader(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPackedStreamReader(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPackedStreamReader(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxPackedStreamReader(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxPackedStreamReader(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPackedStreamReader(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPackedStreamReader(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPackedStreamReader(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPackedStreamReader(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxPackedStreamReader(void) { }
	
};


class DELPHICLASS EdxPackedStreamWriter;
class PASCALIMPLEMENTATION EdxPackedStreamWriter : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxPackedStreamWriter(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxPackedStreamWriter(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : System::Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxPackedStreamWriter(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxPackedStreamWriter(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPackedStreamWriter(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPackedStreamWriter(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxPackedStreamWriter(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxPackedStreamWriter(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPackedStreamWriter(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPackedStreamWriter(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPackedStreamWriter(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPackedStreamWriter(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxPackedStreamWriter(void) { }
	
};


struct TdxPackedFileEntry;
typedef TdxPackedFileEntry *PdxPackedFileEntry;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPackedFileEntry
{
public:
	int Sign;
	System::Word VersionToExtract;
	System::Word Flag;
	System::Word Method;
	unsigned DateTime;
	int CRC32;
	int PackedSize;
	int OriginalSize;
	System::Word NameLength;
	System::Word ExtraLength;
};
#pragma pack(pop)


struct TdxPackedDataDescriptor;
typedef TdxPackedDataDescriptor *PdxPackedDataDescriptor;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPackedDataDescriptor
{
public:
	int CRC32;
	int PackedSize;
	int OriginalSize;
};
#pragma pack(pop)


struct TdxPackedCentralDirEntry;
typedef TdxPackedCentralDirEntry *PdxPackedCentralDirEntry;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPackedCentralDirEntry
{
public:
	int Sign;
	System::Word Version;
	System::Word VersionToExtract;
	System::Word Flag;
	System::Word Method;
	unsigned DateTime;
	int CRC32;
	int PackedSize;
	int OriginalSize;
	System::Word NameLength;
	System::Word ExtraLength;
	System::Word CommentLength;
	System::Word DiskStart;
	System::Word IntAttributes;
	int ExtAttributes;
	int RelativeOffset;
};
#pragma pack(pop)


struct TdxPackedEndOfDir;
typedef TdxPackedEndOfDir *PdxPackedEndOfDir;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPackedEndOfDir
{
public:
	int Sign;
	System::Word DiskNumber;
	System::Word NumberOfDiskStart;
	System::Word DirStart;
	System::Word DirEntryCount;
	int DirSize;
	int DirOffset;
	System::Word CommentLength;
};
#pragma pack(pop)


class DELPHICLASS TdxPackedItem;
class PASCALIMPLEMENTATION TdxPackedItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FAttributes;
	unsigned FCRC32;
	System::Sysutils::TWordArray *FData;
	unsigned FDateTime;
	System::AnsiString FName;
	TdxPackedItem* FNext;
	int FPackedSize;
	int FRelativeOffset;
	int FSize;
	bool __fastcall GetIsDirectory(void);
	
public:
	__fastcall virtual TdxPackedItem(TdxPackedItem* APrev);
	__fastcall virtual ~TdxPackedItem(void);
	void __fastcall Pack(void);
	void __fastcall SaveTo(const System::UnicodeString APath);
	void __fastcall Unpack(void);
	__property int Attributes = {read=FAttributes, nodefault};
	__property unsigned CRC32 = {read=FCRC32, nodefault};
	__property System::Sysutils::PWordArray Data = {read=FData, write=FData};
	__property unsigned DateTime = {read=FDateTime, nodefault};
	__property bool IsDirectory = {read=GetIsDirectory, nodefault};
	__property System::AnsiString Name = {read=FName};
	__property TdxPackedItem* Next = {read=FNext};
	__property int PackedSize = {read=FPackedSize, nodefault};
	__property int RelativeOffset = {read=FRelativeOffset, nodefault};
	__property int Size = {read=FSize, nodefault};
};


typedef void __fastcall (__closure *TdxForEachMethod)(void);

class DELPHICLASS TdxPackedStream;
class PASCALIMPLEMENTATION TdxPackedStream : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxPackedItem* FCurrent;
	TdxPackedItem* FRoot;
	System::Classes::TStream* FStream;
	
protected:
	TdxPackedItem* __fastcall Add(void);
	void __fastcall ForEach(TdxForEachMethod AProc);
	virtual void __fastcall ReadItems(void);
	virtual void __fastcall WriteItems(void);
	
public:
	__fastcall virtual TdxPackedStream(System::Classes::TStream* AStream);
	__fastcall virtual ~TdxPackedStream(void);
	__property TdxPackedItem* Current = {read=FCurrent, write=FCurrent};
	__property System::Classes::TStream* Stream = {read=FStream};
	__property TdxPackedItem* Root = {read=FRoot};
};


class DELPHICLASS TdxPackedStreamReader;
class PASCALIMPLEMENTATION TdxPackedStreamReader : public TdxPackedStream
{
	typedef TdxPackedStream inherited;
	
protected:
	void __fastcall Check(bool AValue, const System::UnicodeString AMessage = System::UnicodeString());
	void __fastcall DoReadCentralDirectory(void);
	void __fastcall DoReadItem(void);
	void __fastcall InitializeItem(TdxPackedItem* AItem, const TdxPackedCentralDirEntry &ADirData);
	virtual void __fastcall ReadItems(void);
public:
	/* TdxPackedStream.Create */ inline __fastcall virtual TdxPackedStreamReader(System::Classes::TStream* AStream) : TdxPackedStream(AStream) { }
	/* TdxPackedStream.Destroy */ inline __fastcall virtual ~TdxPackedStreamReader(void) { }
	
};


class DELPHICLASS TdxPackedStreamWriter;
class DELPHICLASS TdxXLSXIntenalDocument;
class PASCALIMPLEMENTATION TdxPackedStreamWriter : public TdxPackedStream
{
	typedef TdxPackedStream inherited;
	
protected:
	virtual void __fastcall DoWriteCentralDirectory(void);
	virtual void __fastcall DoWriteItem(void);
	void __fastcall InitializeItem(TdxPackedItem* AItem, const System::AnsiString AName, System::Classes::TStream* AStream);
	virtual void __fastcall WriteItems(void);
	
public:
	void __fastcall AddDirectory(const System::AnsiString APath, const System::AnsiString ARelativeDir);
	void __fastcall AddFile(const System::AnsiString AFileName, const System::AnsiString ARelativeDir, System::Classes::TStream* AStream);
	void __fastcall AddImage(const System::AnsiString APath, Dxgdiplusclasses::TdxPNGImage* AImage, int AIndex);
	void __fastcall AddIntenalDocument(TdxXLSXIntenalDocument* ADocument);
public:
	/* TdxPackedStream.Create */ inline __fastcall virtual TdxPackedStreamWriter(System::Classes::TStream* AStream) : TdxPackedStream(AStream) { }
	/* TdxPackedStream.Destroy */ inline __fastcall virtual ~TdxPackedStreamWriter(void) { }
	
};


class DELPHICLASS TdxSharedObject;
class PASCALIMPLEMENTATION TdxSharedObject : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	unsigned Hash;
	int Index;
	TdxSharedObject* Next;
	TdxSharedObject* Prev;
	int RefCount;
	virtual bool __fastcall IsEqual(TdxSharedObject* const AObject);
public:
	/* TObject.Create */ inline __fastcall TdxSharedObject(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSharedObject(void) { }
	
};


typedef System::TMetaClass* TdxSharedObjectClass;

class DELPHICLASS TdxSharedObjectsList;
class PASCALIMPLEMENTATION TdxSharedObjectsList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCount;
	TdxSharedObject* FFirst;
	TdxSharedObject* FLast;
	int FUniqueCount;
	
protected:
	TdxSharedObject* __fastcall InsertItem(TdxSharedObject* AItem, TdxSharedObject* ANext);
	
public:
	__fastcall virtual ~TdxSharedObjectsList(void);
	TdxSharedObject* __fastcall Add(TdxSharedObject* ACandidate);
	void __fastcall Clear(void);
	void __fastcall Release(TdxSharedObject* AItem);
	__property int Count = {read=FCount, nodefault};
	__property TdxSharedObject* First = {read=FFirst};
	__property TdxSharedObject* Last = {read=FLast};
	__property int UniqueCount = {read=FUniqueCount, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxSharedObjectsList(void) : System::TObject() { }
	
};


class DELPHICLASS TdxSharedFont;
class PASCALIMPLEMENTATION TdxSharedFont : public TdxSharedObject
{
	typedef TdxSharedObject inherited;
	
public:
	Cxexport::TcxCacheCellStyle *Style;
	__fastcall TdxSharedFont(const Cxexport::PcxCacheCellStyle AStyle);
	int __fastcall DataSize(void);
	virtual bool __fastcall IsEqual(TdxSharedObject* const AObject);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSharedFont(void) { }
	
};


class DELPHICLASS TdxSharedBrush;
class PASCALIMPLEMENTATION TdxSharedBrush : public TdxSharedObject
{
	typedef TdxSharedObject inherited;
	
public:
	Cxexport::TcxBrushStyle Style;
	__fastcall TdxSharedBrush(const Cxexport::PcxCacheCellStyle AStyle);
	virtual bool __fastcall IsEqual(TdxSharedObject* const AObject);
	__property unsigned Color = {read=Hash, write=Hash, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSharedBrush(void) { }
	
};


class DELPHICLASS TdxSharedCellBorders;
class PASCALIMPLEMENTATION TdxSharedCellBorders : public TdxSharedObject
{
	typedef TdxSharedObject inherited;
	
public:
	Cxexport::TcxCacheCellStyle *Style;
	__fastcall TdxSharedCellBorders(const Cxexport::PcxCacheCellStyle AStyle);
	bool __fastcall IsEmpty(void);
	virtual bool __fastcall IsEqual(TdxSharedObject* const AObject);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSharedCellBorders(void) { }
	
};


class DELPHICLASS TdxSharedStyle;
class PASCALIMPLEMENTATION TdxSharedStyle : public TdxSharedObject
{
	typedef TdxSharedObject inherited;
	
public:
	TdxSharedObject* Font;
	TdxSharedObject* Borders;
	TdxSharedObject* Brush;
	int Format;
	Cxexport::TcxCacheCellStyle *Style;
	__fastcall TdxSharedStyle(Cxexport::PcxCacheCellStyle AStyle, TdxSharedObject* AFont, TdxSharedObject* ABrush, TdxSharedObject* ABorders);
	virtual bool __fastcall IsEqual(TdxSharedObject* const AObject);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSharedStyle(void) { }
	
};


class DELPHICLASS TdxSharedAnsiString;
class PASCALIMPLEMENTATION TdxSharedAnsiString : public TdxSharedObject
{
	typedef TdxSharedObject inherited;
	
public:
	System::AnsiString Text;
	__fastcall TdxSharedAnsiString(const System::AnsiString AText);
	virtual bool __fastcall IsEqual(TdxSharedObject* const AObject);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSharedAnsiString(void) { }
	
};


class DELPHICLASS TdxSharedUnicodeString;
class PASCALIMPLEMENTATION TdxSharedUnicodeString : public TdxSharedObject
{
	typedef TdxSharedObject inherited;
	
public:
	System::WideString Text;
	__fastcall TdxSharedUnicodeString(const System::WideString AText);
	virtual bool __fastcall IsEqual(TdxSharedObject* const AObject);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSharedUnicodeString(void) { }
	
};


class DELPHICLASS TdxSharedStringTable;
class PASCALIMPLEMENTATION TdxSharedStringTable : public TdxSharedObjectsList
{
	typedef TdxSharedObjectsList inherited;
	
public:
	TdxSharedObject* __fastcall AddAnsiString(const System::AnsiString S);
	TdxSharedObject* __fastcall AddUnicodeString(const System::WideString S);
public:
	/* TdxSharedObjectsList.Destroy */ inline __fastcall virtual ~TdxSharedStringTable(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxSharedStringTable(void) : TdxSharedObjectsList() { }
	
};


class DELPHICLASS TdxXLSXInternalXMLNode;
class PASCALIMPLEMENTATION TdxXLSXInternalXMLNode : public Dxxmldoc::TdxXMLNode
{
	typedef Dxxmldoc::TdxXMLNode inherited;
	
protected:
	virtual void __fastcall CheckEncodedText(Dxxmldoc::TdxXMLString &AText);
public:
	/* TdxXMLNode.Create */ inline __fastcall virtual TdxXLSXInternalXMLNode(Dxcustomtree::_di_IdxTreeOwner AOwner) : Dxxmldoc::TdxXMLNode(AOwner) { }
	/* TdxXMLNode.Destroy */ inline __fastcall virtual ~TdxXLSXInternalXMLNode(void) { }
	
};


class DELPHICLASS TdxXLSXInternalXMLDocument;
class PASCALIMPLEMENTATION TdxXLSXInternalXMLDocument : public Dxxmldoc::TdxXMLDocument
{
	typedef Dxxmldoc::TdxXMLDocument inherited;
	
public:
	virtual Dxcustomtree::TdxTreeCustomNodeClass __fastcall GetNodeClass(Dxcustomtree::TdxTreeCustomNode* ARelativeNode);
public:
	/* TdxXMLDocument.Create */ inline __fastcall virtual TdxXLSXInternalXMLDocument(System::Classes::TPersistent* AOwner) : Dxxmldoc::TdxXMLDocument(AOwner) { }
	/* TdxXMLDocument.Destroy */ inline __fastcall virtual ~TdxXLSXInternalXMLDocument(void) { }
	
};


class PASCALIMPLEMENTATION TdxXLSXIntenalDocument : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__fastcall TdxXLSXIntenalDocument(const System::AnsiString ADocName, const System::AnsiString ARelation, const System::AnsiString ANamespace, const System::AnsiString ARootName);
	
public:
	TdxXLSXInternalXMLDocument* Document;
	System::AnsiString DocumentName;
	System::AnsiString Namespace;
	Dxxmldoc::TdxXMLNode* Root;
	__fastcall virtual ~TdxXLSXIntenalDocument(void);
	Dxxmldoc::TdxXMLNode* __fastcall AddNode(Dxxmldoc::TdxXMLNode* AParent, const System::AnsiString AName, System::AnsiString const *AAttributes, const int AAttributes_Size, System::AnsiString const *AAttributesValues, const int AAttributesValues_Size)/* overload */;
	Dxxmldoc::TdxXMLNode* __fastcall AddNode(const System::AnsiString AName, System::AnsiString const *AAttributes, const int AAttributes_Size, System::AnsiString const *AAttributesValues, const int AAttributesValues_Size)/* overload */;
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TObject.Create */ inline __fastcall TdxXLSXIntenalDocument(void) : System::TObject() { }
	
};


class DELPHICLASS TdxXLSXRels;
class PASCALIMPLEMENTATION TdxXLSXRels : public TdxXLSXIntenalDocument
{
	typedef TdxXLSXIntenalDocument inherited;
	
private:
	int FCount;
	
public:
	__fastcall TdxXLSXRels(System::AnsiString ADocName);
	void __fastcall Add(const System::AnsiString AType, const System::AnsiString ATarget, System::AnsiString AIdPrefix = "rId");
protected:
	/* TdxXLSXIntenalDocument.CreateInstance */ inline __fastcall TdxXLSXRels(const System::AnsiString ADocName, const System::AnsiString ARelation, const System::AnsiString ANamespace, const System::AnsiString ARootName) : TdxXLSXIntenalDocument(ADocName, ARelation, ANamespace, ARootName) { }
	
public:
	/* TdxXLSXIntenalDocument.Destroy */ inline __fastcall virtual ~TdxXLSXRels(void) { }
	
};


class DELPHICLASS TdxXLSXContentTypes;
class PASCALIMPLEMENTATION TdxXLSXContentTypes : public TdxXLSXIntenalDocument
{
	typedef TdxXLSXIntenalDocument inherited;
	
public:
	__fastcall TdxXLSXContentTypes(void);
protected:
	/* TdxXLSXIntenalDocument.CreateInstance */ inline __fastcall TdxXLSXContentTypes(const System::AnsiString ADocName, const System::AnsiString ARelation, const System::AnsiString ANamespace, const System::AnsiString ARootName) : TdxXLSXIntenalDocument(ADocName, ARelation, ANamespace, ARootName) { }
	
public:
	/* TdxXLSXIntenalDocument.Destroy */ inline __fastcall virtual ~TdxXLSXContentTypes(void) { }
	
};


class DELPHICLASS TdxXLSXWorkbook;
class PASCALIMPLEMENTATION TdxXLSXWorkbook : public TdxXLSXIntenalDocument
{
	typedef TdxXLSXIntenalDocument inherited;
	
private:
	int FCount;
	Dxxmldoc::TdxXMLNode* FSheets;
	
public:
	__fastcall TdxXLSXWorkbook(void);
	void __fastcall AddSheet(System::WideString AName);
protected:
	/* TdxXLSXIntenalDocument.CreateInstance */ inline __fastcall TdxXLSXWorkbook(const System::AnsiString ADocName, const System::AnsiString ARelation, const System::AnsiString ANamespace, const System::AnsiString ARootName) : TdxXLSXIntenalDocument(ADocName, ARelation, ANamespace, ARootName) { }
	
public:
	/* TdxXLSXIntenalDocument.Destroy */ inline __fastcall virtual ~TdxXLSXWorkbook(void) { }
	
};


class DELPHICLASS TdxXLSXSharedStrings;
class PASCALIMPLEMENTATION TdxXLSXSharedStrings : public TdxXLSXIntenalDocument
{
	typedef TdxXLSXIntenalDocument inherited;
	
public:
	__fastcall TdxXLSXSharedStrings(const int ACount, const int AUniqueCount);
	void __fastcall Add(const System::WideString AValue);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
protected:
	/* TdxXLSXIntenalDocument.CreateInstance */ inline __fastcall TdxXLSXSharedStrings(const System::AnsiString ADocName, const System::AnsiString ARelation, const System::AnsiString ANamespace, const System::AnsiString ARootName) : TdxXLSXIntenalDocument(ADocName, ARelation, ANamespace, ARootName) { }
	
public:
	/* TdxXLSXIntenalDocument.Destroy */ inline __fastcall virtual ~TdxXLSXSharedStrings(void) { }
	
};


typedef bool __fastcall (__closure *TdxAddSharedObjectProc)(TdxSharedObject* const AObject);

class DELPHICLASS TdxXLSXStyles;
class PASCALIMPLEMENTATION TdxXLSXStyles : public TdxXLSXIntenalDocument
{
	typedef TdxXLSXIntenalDocument inherited;
	
private:
	Dxxmldoc::TdxXMLNode* FBorders;
	Dxxmldoc::TdxXMLNode* FFonts;
	Dxxmldoc::TdxXMLNode* FFormats;
	Dxxmldoc::TdxXMLNode* FNumFormats;
	int FNumFormatsCount;
	Dxxmldoc::TdxXMLNode* FPatterns;
	
protected:
	bool __fastcall AddCellBorders(TdxSharedObject* const AObject);
	bool __fastcall AddFont(TdxSharedObject* const AObject);
	int __fastcall AddNumFormat(const System::AnsiString AFormat, const System::Byte FormatID = (System::Byte)(0x0));
	bool __fastcall AddPattern(TdxSharedObject* const AObject);
	void __fastcall AddSharedObjects(Dxxmldoc::TdxXMLNode* ANode, TdxSharedObjectsList* AList, TdxAddSharedObjectProc AddProc, int ACount = 0x0);
	bool __fastcall AddStyle(TdxSharedObject* const AObject);
	void __fastcall Initialize(void);
	
public:
	__fastcall TdxXLSXStyles(void);
	void __fastcall AddBorders(TdxSharedObjectsList* ABorders);
	void __fastcall AddBrushes(TdxSharedObjectsList* ABrushes);
	void __fastcall AddFonts(TdxSharedObjectsList* AFonts);
	void __fastcall AddStyles(TdxSharedObjectsList* AStyles);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
protected:
	/* TdxXLSXIntenalDocument.CreateInstance */ inline __fastcall TdxXLSXStyles(const System::AnsiString ADocName, const System::AnsiString ARelation, const System::AnsiString ANamespace, const System::AnsiString ARootName) : TdxXLSXIntenalDocument(ADocName, ARelation, ANamespace, ARootName) { }
	
public:
	/* TdxXLSXIntenalDocument.Destroy */ inline __fastcall virtual ~TdxXLSXStyles(void) { }
	
};


class DELPHICLASS TdxXLSXDrawing;
class PASCALIMPLEMENTATION TdxXLSXDrawing : public TdxXLSXIntenalDocument
{
	typedef TdxXLSXIntenalDocument inherited;
	
private:
	int FIndex;
	TdxXLSXRels* FRels;
	
public:
	__fastcall TdxXLSXDrawing(TdxXLSXRels* ARels);
	void __fastcall AddImage(int ACol, int ARow, Dxgdiplusclasses::TdxPNGImage* AImage);
	__property int Index = {read=FIndex, nodefault};
protected:
	/* TdxXLSXIntenalDocument.CreateInstance */ inline __fastcall TdxXLSXDrawing(const System::AnsiString ADocName, const System::AnsiString ARelation, const System::AnsiString ANamespace, const System::AnsiString ARootName) : TdxXLSXIntenalDocument(ADocName, ARelation, ANamespace, ARootName) { }
	
public:
	/* TdxXLSXIntenalDocument.Destroy */ inline __fastcall virtual ~TdxXLSXDrawing(void) { }
	
};


class DELPHICLASS TdxXLSXSheet;
class PASCALIMPLEMENTATION TdxXLSXSheet : public TdxXLSXIntenalDocument
{
	typedef TdxXLSXIntenalDocument inherited;
	
private:
	int FColCount;
	Dxxmldoc::TdxXMLNode* FColumns;
	Dxxmldoc::TdxXMLNode* FData;
	int FRowCount;
	
public:
	__fastcall TdxXLSXSheet(const int ARowCount, const int AColCount, bool AGridlines);
	Dxxmldoc::TdxXMLNode* __fastcall AddCell(Dxxmldoc::TdxXMLNode* AParentRow, const int ARow, const int ACol, const int AStyleIndex);
	void __fastcall SetDataAsBoolean(Dxxmldoc::TdxXMLNode* ACell, const bool AValue);
	void __fastcall SetDataAsCurrency(Dxxmldoc::TdxXMLNode* ACell, const System::Currency AValue);
	void __fastcall SetDataAsFloat(Dxxmldoc::TdxXMLNode* ACell, const double AValue);
	void __fastcall SetDataAsInteger(Dxxmldoc::TdxXMLNode* ACell, const int AValue);
	void __fastcall SetDataAsString(Dxxmldoc::TdxXMLNode* ACell, const int ASSTIndex);
	void __fastcall AddMergeCells(System::Classes::TStringList* const ARefs);
	Dxxmldoc::TdxXMLNode* __fastcall AddRowHeight(const int ARow, const int AHeight);
	void __fastcall SetColumnWidth(const int AColumn, int AWidth);
protected:
	/* TdxXLSXIntenalDocument.CreateInstance */ inline __fastcall TdxXLSXSheet(const System::AnsiString ADocName, const System::AnsiString ARelation, const System::AnsiString ANamespace, const System::AnsiString ARootName) : TdxXLSXIntenalDocument(ADocName, ARelation, ANamespace, ARootName) { }
	
public:
	/* TdxXLSXIntenalDocument.Destroy */ inline __fastcall virtual ~TdxXLSXSheet(void) { }
	
};


enum TdxXLSXCellDataType : unsigned char { cdtNone, cdtBoolean, cdtInteger, cdtCurrency, cdtFloat, cdtDateTime, cdtString, cdtImage };

class DELPHICLASS TdxXLSXCell;
class PASCALIMPLEMENTATION TdxXLSXCell : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxXLSXCellDataType FDataType;
	int __fastcall GetDataTypeSize(TdxXLSXCellDataType ADataType);
	bool __fastcall NeedAllocate(TdxXLSXCellDataType ADataType);
	void __fastcall SetDataType(TdxXLSXCellDataType ADataType);
	
public:
	int Col;
	int Row;
	int Style;
	void *Data;
	__fastcall virtual ~TdxXLSXCell(void);
	void __fastcall Clear(void);
	__property TdxXLSXCellDataType DataType = {read=FDataType, write=SetDataType, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxXLSXCell(void) : System::TObject() { }
	
};


class DELPHICLASS TdxXLSXExportProvider;
class PASCALIMPLEMENTATION TdxXLSXExportProvider : public Cxexport::TcxCustomExportProvider
{
	typedef Cxexport::TcxCustomExportProvider inherited;
	
private:
	Cxclasses::TcxObjectList* FCells;
	int FColCount;
	System::Classes::TList* FCols;
	TdxXLSXContentTypes* FContentTypes;
	TdxXLSXDrawing* FDrawing;
	int FImagesCount;
	System::Classes::TStringList* FMergedCells;
	System::WideString FName;
	TdxXLSXRels* FRels;
	int FRowCount;
	System::Classes::TList* FRows;
	TdxXLSXSharedStrings* FSharedStrings;
	TdxXLSXSheet* FSheet;
	TdxSharedStringTable* FSST;
	System::Classes::TStream* FStream;
	Cxexport::TcxExportStyleManager* FStyleCache;
	TdxXLSXStyles* FStyles;
	TdxXLSXWorkbook* FWorkbook;
	TdxXLSXRels* FWorkbookRels;
	TdxPackedStreamWriter* FWriter;
	Cxclasses::TcxObjectList* FXMLItems;
	TdxXLSXCell* __fastcall GetCell(int ACol, int ARow);
	
protected:
	void __fastcall AddStructureItem(TdxXLSXIntenalDocument* AItem, void *Instance);
	void __fastcall Commit(void);
	bool __fastcall CheckPos(const int ACol, const int ARow);
	void __fastcall CreateXMLStructure(void);
	Cxexport::PcxCacheCellStyle __fastcall GetCellStyle(const int ACol, const int ARow);
	Cxexport::PcxCacheCellStyle __fastcall GetStyle(int AStyleIndex);
	TdxXLSXCell* __fastcall InitCellData(const int ACol, const int ARow, TdxXLSXCellDataType ADataType);
	void __fastcall InitializeProvider(void);
	int __fastcall RegisterStyle(const Cxexport::TcxCacheCellStyle &AStyle);
	void __fastcall SetCellDataBoolean(const int ACol, const int ARow, const bool AValue);
	void __fastcall SetCellDataCurrency(const int ACol, const int ARow, const System::Currency AValue);
	void __fastcall SetCellDataDateTime(const int ACol, const int ARow, const System::TDateTime AValue);
	void __fastcall SetCellDataDouble(const int ACol, const int ARow, const double AValue);
	void __fastcall SetCellDataInteger(const int ACol, const int ARow, const int AValue);
	void __fastcall SetCellDataString(const int ACol, const int ARow, const System::UnicodeString AText);
	void __fastcall SetCellDataWideString(const int ACol, const int ARow, const System::WideString AText);
	void __fastcall SetCellStyle(const int ACol, const int ARow, const int AStyleIndex)/* overload */;
	void __fastcall SetCellStyle(const int ACol, const int ARow, const int AExampleCol, const int AExampleRow)/* overload */;
	void __fastcall SetCellStyle(const int ACol, const int ARow, const Cxexport::TcxCacheCellStyle &AStyle)/* overload */;
	void __fastcall SetCellStyleEx(const int ACol, const int ARow, const int H, const int W, const int AStyleIndex);
	void __fastcall SetCellUnion(const int ACol, const int ARow, int H, int W);
	void __fastcall SetCellValue(const int ACol, const int ARow, const System::Variant &AValue);
	void __fastcall SetColumnWidth(const int ACol, const int AWidth);
	void __fastcall SetDefaultStyle(const Cxexport::TcxCacheCellStyle &AStyle);
	void __fastcall SetRange(const int AColCount, const int ARowCount, bool IsVisible = true);
	void __fastcall SetRowHeight(const int ARow, const int AHeight);
	void __fastcall ValidateNativeStyle(int &AStyleIndex, const TdxXLSXCellDataType ADataType, const void * Data);
	void __fastcall WriteData(void);
	void __fastcall WriteSharedStrings(void);
	void __fastcall WriteSheetLayout(void);
	void __fastcall WriteStyles(void);
	void __fastcall SetCellDataGraphic(const int ACol, const int ARow, Vcl::Graphics::TGraphic* &AGraphic);
	void __fastcall SetCellPNGImage(const int ACol, const int ARow, System::TObject* APNGImage);
	bool __fastcall SupportGraphic(void);
	__property TdxXLSXCell* Cells[int ACol][int ARow] = {read=GetCell};
	__property int ColCount = {read=FColCount, nodefault};
	__property System::Classes::TList* Cols = {read=FCols};
	__property TdxXLSXContentTypes* ContentTypes = {read=FContentTypes};
	__property TdxXLSXDrawing* Drawing = {read=FDrawing};
	__property int ImagesCount = {read=FImagesCount, nodefault};
	__property System::Classes::TStringList* MergedCells = {read=FMergedCells};
	__property System::WideString Name = {read=FName, write=FName};
	__property TdxXLSXRels* Rels = {read=FRels};
	__property int RowCount = {read=FRowCount, nodefault};
	__property System::Classes::TList* Rows = {read=FRows};
	__property TdxXLSXSharedStrings* SharedStrings = {read=FSharedStrings};
	__property TdxXLSXSheet* Sheet = {read=FSheet};
	__property TdxSharedStringTable* SST = {read=FSST};
	__property Cxexport::TcxExportStyleManager* StyleCache = {read=FStyleCache};
	__property TdxXLSXStyles* Styles = {read=FStyles};
	__property TdxXLSXWorkbook* Workbook = {read=FWorkbook};
	__property TdxXLSXRels* WorkbookRels = {read=FWorkbookRels};
	__property TdxPackedStreamWriter* Writer = {read=FWriter};
	__property Cxclasses::TcxObjectList* XMLItems = {read=FXMLItems};
	
public:
	__fastcall virtual TdxXLSXExportProvider(const System::UnicodeString AFileName);
	__fastcall virtual ~TdxXLSXExportProvider(void);
	__classmethod virtual int __fastcall ExportType();
	__classmethod virtual System::UnicodeString __fastcall ExportName();
private:
	void *__IcxExportProvider;	/* Cxexport::IcxExportProvider */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {442A08A8-CDDA-4FD6-8E15-9D8BD34554F6}
	operator Cxexport::_di_IcxExportProvider()
	{
		Cxexport::_di_IcxExportProvider intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxexport::IcxExportProvider*(void) { return (Cxexport::IcxExportProvider*)&__IcxExportProvider; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::AnsiString __fastcall dxColumnToString(int ACol);
extern PACKAGE System::AnsiString __fastcall dxRefToString(const int ACol, const int ARow);
}	/* namespace Dxxlsxexport */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXXLSXEXPORT)
using namespace Dxxlsxexport;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxxlsxexportHPP
