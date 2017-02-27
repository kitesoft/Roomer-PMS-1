// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExcelAccess.pas' rev: 24.00 (Win32)

#ifndef CxexcelaccessHPP
#define CxexcelaccessHPP

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
#include <System.Math.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxSSUtils.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxSSIntf.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexcelaccess
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxExcelDataReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxExcelDataReader : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxExcelDataReader(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxExcelDataReader(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxExcelDataReader(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxExcelDataReader(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxExcelDataReader(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxExcelDataReader(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxExcelDataReader(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxExcelDataReader(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxExcelDataReader(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxExcelDataReader(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxExcelDataReader(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxExcelDataReader(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxExcelDataReader(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS EcxExcelDataWriter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxExcelDataWriter : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxExcelDataWriter(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxExcelDataWriter(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxExcelDataWriter(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxExcelDataWriter(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxExcelDataWriter(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxExcelDataWriter(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxExcelDataWriter(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxExcelDataWriter(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxExcelDataWriter(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxExcelDataWriter(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxExcelDataWriter(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxExcelDataWriter(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxExcelDataWriter(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxProgressEvent)(System::TObject* Sender, System::Byte APercent);

class DELPHICLASS TcxExcelFileReader;
class PASCALIMPLEMENTATION TcxExcelFileReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<Cxsstypes::TcxSSFontRec> _TcxExcelFileReader__1;
	
	typedef System::DynamicArray<System::Word> _TcxExcelFileReader__2;
	
	typedef System::DynamicArray<Cxsstypes::TcxSSCellStyleRec> _TcxExcelFileReader__3;
	
	
private:
	System::Classes::TStringList* FBoundSheets;
	Cxssintf::_di_IcxBookSheet FCurrentSheet;
	int FCurrentPage;
	int FExtRecordSize;
	_TcxExcelFileReader__1 FFontArray;
	System::TObject* FFuncConverter;
	bool FHasUnknownFunction;
	System::TStringDynArray FNames;
	TcxProgressEvent FOnProgress;
	Cxssintf::_di_IcxSpreadSheetBook FOwner;
	int FPixelsPerInch;
	int FProgress;
	System::TObject* FReader;
	System::Classes::TStringList* FSharedStringTable;
	System::Classes::TStringList* FStyleList;
	_TcxExcelFileReader__2 FSheetXlt;
	int FStandardColWidth;
	_TcxExcelFileReader__3 FXFRecords;
	Cxsstypes::TcxSSFillStyle __fastcall ConvertBrushStyles(System::Byte ABrushStyle);
	int __fastcall GetDataSize(void);
	void * __fastcall GetMemoryData(void);
	
protected:
	virtual void __fastcall DoReadRecords(void);
	virtual void __fastcall DoReadUnknownRecord(Cxexcelconst::TBiffRecHeader &ARec);
	void __fastcall ProgressUpdate(void * APos);
	System::Word __fastcall XltPage(const System::Word APage);
	__property System::Classes::TStringList* BoundSheets = {read=FBoundSheets};
	__property Cxssintf::_di_IcxBookSheet CurrentSheet = {read=FCurrentSheet};
	__property int DataSize = {read=GetDataSize, nodefault};
	__property void * MemoryData = {read=GetMemoryData};
	__property System::TStringDynArray Names = {read=FNames};
	__property Cxssintf::_di_IcxSpreadSheetBook Owner = {read=FOwner};
	__property int StandardColWidth = {read=FStandardColWidth, nodefault};
	__property System::Classes::TStringList* Styles = {read=FStyleList};
	
public:
	__fastcall virtual TcxExcelFileReader(System::TObject* AOwner);
	__fastcall virtual ~TcxExcelFileReader(void);
	bool __fastcall AssignStream(System::Classes::TStream* AStream);
	void __fastcall OpenStream(void);
	__property int PixelsPerInch = {read=FPixelsPerInch, write=FPixelsPerInch, nodefault};
	__property bool HasUnknownFunction = {read=FHasUnknownFunction, nodefault};
	__property TcxProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
};


class DELPHICLASS TcxExcelFileWriter;
class DELPHICLASS TSSTStringTable;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxExcelFileWriter : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Word FCurrentFont;
	Cxsstypes::TxlsDataFormat FCurrentFormat;
	System::Word FCurrentStyle;
	Cxexcelconst::TxlsTreeNode *FCurrentStylePtr;
	System::Classes::TList* FFontsList;
	int FPageCount;
	Cxexcelconst::TcxExcelPalette FPalette;
	int FPixelsPerInch;
	Cxexcelconst::TxlsFileStorage FStorage;
	System::Classes::TList* FStylesList;
	TSSTStringTable* FSST;
	void __fastcall CreateDefaultFonts(void);
	void __fastcall CreateDefaultStyles(void);
	void __fastcall SetBlank(System::Word ACol, System::Word ARow);
	void __fastcall SetBoolErr(System::Word ACol, System::Word ARow, bool ABoolValue);
	void __fastcall SetDouble(System::Word ACol, System::Word ARow, double ADoubleValue);
	void __fastcall SetSSTString(System::Word ACol, System::Word ARow, const System::WideString AStringValue);
	void __fastcall SetWString(System::Word ACol, System::Word ARow, const System::WideString AStringValue);
	
protected:
	int DefUnLockStyle;
	int __fastcall CalculateNodeSize(Cxexcelconst::PxlsTreeNode ANode, bool IsRoot = false);
	virtual void __fastcall ClearSheets(Cxexcelconst::PxlsTreeNode &APage);
	virtual void __fastcall ClearStorage(void);
	virtual void __fastcall ClearTree(Cxexcelconst::PxlsTreeNode &ANode);
	virtual bool __fastcall CompareXlsNodes(Cxexcelconst::PxlsTreeNode ANode1, Cxexcelconst::PxlsTreeNode ANode2);
	void __fastcall CreateFont(Cxsstypes::PcxSSFontRec AFont);
	virtual void __fastcall CreateStorage(void);
	void __fastcall CreateStyle(Cxsstypes::PcxSSCellStyleRec AStyle);
	Cxexcelconst::PxlsTreeNode __fastcall CreateXlsListNode(const System::Word AType, const System::Word ASize, const Cxexcelconst::PxlsTreeNode APrevNode = (Cxexcelconst::PxlsTreeNode)(0x0));
	virtual Cxexcelconst::PxlsTreeNode __fastcall FindNode(Cxexcelconst::PxlsTreeNode ANode, System::Word AType);
	virtual void __fastcall FreeData(void);
	Cxexcelconst::PxlsTreeNode __fastcall GetEnd(Cxexcelconst::PxlsTreeNode ANode);
	Cxexcelconst::PxlsTreeNode __fastcall GetRoot(Cxexcelconst::PxlsTreeNode ANode);
	void __fastcall SelectPage(System::Word APage);
	void __fastcall SetPageDimension(Cxexcelconst::PxlsTreeNode APage, const int AMaxCol, const int AMaxRow);
	void __fastcall StoreTreeNode(System::Classes::TStream* AStream, Cxexcelconst::PxlsTreeNode ANode, const bool IsRoot = false);
	virtual Cxexcelconst::PxlsTreeNode __fastcall UnionNodes(Cxexcelconst::PxlsTreeNode AFirstNode, Cxexcelconst::PxlsTreeNode ALastNode);
	__property System::Word CurrentStyle = {read=FCurrentStyle, nodefault};
	__property System::Word CurrentFont = {read=FCurrentFont, nodefault};
	__property Cxsstypes::TxlsDataFormat CurrentFormat = {read=FCurrentFormat, nodefault};
	__property System::Classes::TList* FontsList = {read=FFontsList};
	__property System::Classes::TList* StylesList = {read=FStylesList};
	
public:
	__fastcall virtual TcxExcelFileWriter(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxExcelFileWriter(void);
	virtual void __fastcall AddSheet(const System::WideString ACaption, bool VisibleGrid = true, bool Visible = true);
	void __fastcall Clear(void);
	virtual void __fastcall DefineName(Cxsstypes::PcxSSNameDefinition APName);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall SetCellFunction(System::Word APage, System::Word ACol, System::Word ARow, const Cxsstypes::TcxStackItem &Value, System::Word AExprSize, const Cxsstypes::PByteArray AParsedExpr);
	void __fastcall SetCellValue(System::Word APage, System::Word ACol, System::Word ARow, const System::Variant &AValue, bool IsText = false);
	virtual void __fastcall SetColStyle(System::Word APage, System::Word ACol, System::Word AWidth, int AOriginalSize, bool IsLocked, bool IsHidden = false);
	void __fastcall SetDefaultColWidth(System::Word APage, System::Word ASize);
	void __fastcall SetDefaultRowHeight(System::Word APage, System::Word ASize);
	void __fastcall SetDefaultStyle(Cxsstypes::PcxSSCellStyleRec AStyle);
	void __fastcall SetMergedCells(System::Word APage, System::Types::TRect const *ARects, const int ARects_Size);
	void __fastcall SetProtection(int APage, bool IsProtect);
	void __fastcall SetPalette(Cxexcelconst::PcxExcelPalette APalette);
	virtual void __fastcall SetRowStyle(System::Word APage, System::Word ARow, System::Word AHeight, int AOriginalSize, bool IsHidden = false);
	virtual void __fastcall SelectStyle(Cxsstypes::PcxSSCellStyleRec AStyle);
	__property int PageCount = {read=FPageCount, write=FPageCount, nodefault};
	__property int PixelsPerInch = {read=FPixelsPerInch, write=FPixelsPerInch, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSSTStringTable : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxexcelconst::TExtSST FExtSST;
	Cxexcelconst::TSSTList FSST;
	Cxexcelconst::TSSSTStringsInfo FStringsInfo;
	int __fastcall GetStringCount(void);
	int __fastcall GetUniqueStringCount(void);
	
protected:
	virtual void __fastcall CreateExtSST(int ASSTOffset);
	virtual int __fastcall GetPackedSize(void);
	virtual int __fastcall IndexOf(const System::WideString AString);
	virtual void __fastcall InsertStr(const System::WideString AString);
	__property Cxexcelconst::TExtSST ExtSST = {read=FExtSST};
	__property Cxexcelconst::TSSTList SST = {read=FSST};
	__property Cxexcelconst::TSSSTStringsInfo StringsInfo = {read=FStringsInfo};
	
public:
	__fastcall virtual TSSTStringTable(void);
	__fastcall virtual ~TSSTStringTable(void);
	int __fastcall Add(const System::WideString AString);
	void __fastcall Clear(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream, int APosition = 0xffffffff);
	__property int PackedSize = {read=GetPackedSize, nodefault};
	__property int TotalStringCount = {read=GetStringCount, nodefault};
	__property int UniqueStringCount = {read=GetUniqueStringCount, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxexcelaccess */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXCELACCESS)
using namespace Cxexcelaccess;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexcelaccessHPP
