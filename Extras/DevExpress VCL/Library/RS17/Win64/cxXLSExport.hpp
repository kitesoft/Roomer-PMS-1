// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxXLSExport.pas' rev: 24.00 (Win64)

#ifndef CxxlsexportHPP
#define CxxlsexportHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxExport.hpp>	// Pascal unit
#include <cxExportStrs.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxxlsexport
{
//-- type declarations -------------------------------------------------------
enum TxlsExportOptimization : unsigned char { optBySize, optBySpeed };

enum TcxColorItemType : unsigned char { ciFontColor, ciBrushBKColor, ciBrushFGColor, ciBorderColor };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxMergeRect
{
public:
	System::Word Top;
	System::Word Bottom;
	System::Word Left;
	System::Word Right;
};
#pragma pack(pop)


struct TcxXLSCell;
typedef TcxXLSCell *PcxXLSCell;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxXLSCell
{
public:
	System::Word RecType;
	System::Word RecSize;
	System::Word Row;
	System::Word Col;
	System::Word XF;
	union
	{
		struct 
		{
			bool BoolErrValue;
			bool ErrFlag;
		};
		struct 
		{
			System::Word StrLen;bool StrType;
			union
			{
				struct 
				{
					System::StaticArray<System::WideChar, 128> StrDataW;
				};
				struct 
				{
					System::StaticArray<char, 256> StrDataA;
				};
				
			};
		};
		struct 
		{
			double Num;
		};
		struct 
		{
			int SSTIndex;
		};
		struct 
		{
			System::StaticArray<System::Byte, 65535> VarBytes;
		};
		struct 
		{
			System::StaticArray<System::Word, 32767> VarWords;
		};
		
	};
};
#pragma pack(pop)


typedef System::StaticArray<TcxMergeRect, 268435455> TcxUnionCellsArray;

typedef TcxUnionCellsArray *PcxUnionCellsArray;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSSTBlock
{
public:
	System::Word StringCount;
	System::Word StringOffset;
	System::Word RecType;
	System::Word DataSize;
	System::StaticArray<System::Byte, 8192> Data;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TExtSSTBlock
{
public:
	int StreamOffset;
	System::Word StringOffset;
	System::Word Reserved;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TExtSST
{
public:
	System::Word RecType;
	System::Word DataSize;
	System::Word StringPerBlock;
	System::StaticArray<TExtSSTBlock, 256> Data;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSSSTStringInfo
{
public:
	System::Word HashCode;
	System::Word StrSize;
	System::Word Block;
	System::Word Offset;
};
#pragma pack(pop)


typedef System::DynamicArray<TSSTBlock> TSSTList;

typedef System::DynamicArray<TSSSTStringInfo> TSSSTStringsInfo;

class DELPHICLASS TcxXLSSharedStringTable;
class PASCALIMPLEMENTATION TcxXLSSharedStringTable : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TExtSST FExtSST;
	TSSTList FSST;
	bool FOptimaze;
	TSSSTStringsInfo FStringsInfo;
	int __fastcall GetStringCount(void);
	int __fastcall GetUniqueStringCount(void);
	
protected:
	void __fastcall AddStringToBlock(void * ASource, TSSTBlock &ADest, System::Word ASize);
	void __fastcall CreateExtSST(int ASSTOffset);
	int __fastcall GetPackedSize(void);
	int __fastcall IndexOf(const System::WideString AString);
	void __fastcall InsertStr(const System::WideString AString);
	__property TExtSST ExtSST = {read=FExtSST};
	__property TSSTList SST = {read=FSST};
	__property TSSSTStringsInfo StringsInfo = {read=FStringsInfo};
	
public:
	__fastcall virtual TcxXLSSharedStringTable(void);
	__fastcall virtual ~TcxXLSSharedStringTable(void);
	int __fastcall Add(System::WideString AString);
	void __fastcall Clear(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream, int APosition = 0xffffffff);
	__property int PackedSize = {read=GetPackedSize, nodefault};
	__property int TotalStringCount = {read=GetStringCount, nodefault};
	__property int UniqueStringCount = {read=GetUniqueStringCount, nodefault};
};


struct TcxOLEFileHeader;
typedef TcxOLEFileHeader *PcxOLEFileHeader;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxOLEFileHeader
{
public:
	__int64 Signature;
	System::StaticArray<__int64, 2> CLSID;
	int OLEVersion;
	System::Word ByteOrder;
	System::Word SectorShift;
	System::Word MiniSectorShift;
	System::Word Reserved;
	int Reserved1;
	int Reserved2;
	int CountSectFAT;
	int SectDIRStart;
	int TransSignature;
	int MiniSectorCutOff;
	int SectMiniFATStart;
	int CountSectMiniFAT;
	int SectDIFStart;
	int CountSectDIF;
	System::StaticArray<int, 109> SectFAT;
};
#pragma pack(pop)


enum TcxOLEDIREntryType : unsigned char { ET_INVALID, ET_STORAGE, ET_STREAM, ET_LOCKBYTES, ET_PROPERTY, ET_ROOT };

struct TcxOLEDIREntry;
typedef TcxOLEDIREntry *PcxOLEDIREntry;

struct DECLSPEC_DRECORD TcxOLEDIREntry
{
public:
	System::StaticArray<System::Byte, 64> Name;
	System::Word NameLen;
	TcxOLEDIREntryType EntryType;
	System::Byte BFlag;
	unsigned LeftSib;
	unsigned RightSib;
	unsigned ChildSib;
	GUID Guid;
	int UserFlag;
	System::StaticArray<System::Sysutils::TTimeStamp, 2> C_M_Time;
	int StartSector;
	int Size;
	int Reserved;
};


typedef System::StaticArray<int, 128> TcxFATSector;

typedef TcxFATSector *PcxFATSector;

typedef System::StaticArray<System::StaticArray<int, 128>, 4194303> TcxFATSectors;

typedef TcxFATSectors *PcxFATSectors;

class DELPHICLASS TcxXLSWorkBookWriter;
class PASCALIMPLEMENTATION TcxXLSWorkBookWriter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::Sysutils::TByteArray *FBuffer;
	int FBufferSize;
	int FCapacity;
	int FFATBlockCount;
	bool FIsSmallFile;
	int FSectCount;
	int FStreamSize;
	void __fastcall CreateLocalFAT(void);
	PcxFATSector __fastcall GetDIFSector(int ASector);
	PcxOLEDIREntry __fastcall GetDIREntry(int AIndex);
	PcxOLEFileHeader __fastcall GetHeader(void);
	PcxFATSector __fastcall GetFATSector(int ASector);
	void __fastcall Check(bool ACondition);
	virtual void __fastcall CreateDIF(void);
	virtual void __fastcall CreateDIR(void);
	virtual void __fastcall CreateFAT(void);
	virtual void __fastcall CreateHeader(void);
	virtual void __fastcall CreateSmallFAT(void);
	void __fastcall ReallocBuffer(const int ASize);
	__property bool IsSmallFile = {read=FIsSmallFile, nodefault};
	__property PcxOLEDIREntry DIR[int AEntry] = {read=GetDIREntry};
	__property PcxFATSector DIF[int ASector] = {read=GetDIFSector};
	__property PcxFATSector FAT[int ASector] = {read=GetFATSector};
	__property PcxOLEFileHeader Header = {read=GetHeader};
	__property System::Sysutils::PByteArray Memory = {read=FBuffer};
	__property int Size = {read=FBufferSize, nodefault};
	
public:
	void __fastcall CreateOLEStream(int ADataSize, System::Classes::TStream* ADstStream);
public:
	/* TObject.Create */ inline __fastcall TcxXLSWorkBookWriter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxXLSWorkBookWriter(void) { }
	
};


class DELPHICLASS TcxXLSExportProvider;
class DELPHICLASS TcxXLSCellsData;
class DELPHICLASS TcxXLSRecordsList;
class PASCALIMPLEMENTATION TcxXLSExportProvider : public Cxexport::TcxCustomExportProvider
{
	typedef Cxexport::TcxCustomExportProvider inherited;
	
private:
	typedef System::DynamicArray<System::Byte> _TcxXLSExportProvider__1;
	
	
private:
	TcxXLSCellsData* FCells;
	TcxXLSRecordsList* FColStyles;
	TcxXLSRecordsList* FFonts;
	int FMaxCol;
	int FMaxRow;
	TcxXLSRecordsList* FStyles;
	Cxexport::TcxExportStyleManager* FStyleCache;
	TcxUnionCellsArray *FUnionCells;
	int FUnionCellsCapacity;
	int FUnionCellsCount;
	int FUsedColors;
	System::StaticArray<int, 56> FPalette;
	TcxXLSRecordsList* FRowStyles;
	System::WideString FSheetName;
	TcxXLSSharedStringTable* FSST;
	System::Classes::TStream* FStream;
	bool FVisibleGrid;
	TcxXLSWorkBookWriter* FWorkBookWriter;
	_TcxXLSExportProvider__1 FRangeNameBytes;
	System::AnsiString FRangeName;
	System::Types::TRect FNamedRange;
	
protected:
	virtual void __fastcall Commit(void);
	Cxexport::PcxCacheCellStyle __fastcall GetCellStyle(const int ACol, const int ARow);
	Cxexport::PcxCacheCellStyle __fastcall GetStyle(int AStyleIndex);
	bool __fastcall PlaceParsedString(const int ACol, const int ARow, const System::UnicodeString AText);
	int __fastcall RegisterStyle(const Cxexport::TcxCacheCellStyle &AStyle);
	virtual void __fastcall SetCellDataBoolean(const int ACol, const int ARow, const bool AValue);
	virtual void __fastcall SetCellDataCurrency(const int ACol, const int ARow, const System::Currency AValue);
	virtual void __fastcall SetCellDataDateTime(const int ACol, const int ARow, const System::TDateTime AValue);
	virtual void __fastcall SetCellDataDouble(const int ACol, const int ARow, const double AValue);
	virtual void __fastcall SetCellDataInteger(const int ACol, const int ARow, const int AValue);
	virtual void __fastcall SetCellDataString(const int ACol, const int ARow, const System::UnicodeString AText);
	virtual void __fastcall SetCellDataWideString(const int ACol, const int ARow, const System::WideString AText);
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
	void __fastcall SetCellDataGraphic(const int ACol, const int ARow, Vcl::Graphics::TGraphic* &AGraphic);
	void __fastcall SetCellPNGImage(const int ACol, const int ARow, System::TObject* APNGImage);
	bool __fastcall SupportGraphic(void);
	void __fastcall SetName(const System::UnicodeString AName);
	void __fastcall SetRangeName(const System::AnsiString AName, const System::Types::TRect &ARange);
	DYNAMIC int __fastcall CalculateStoredSize(void);
	System::Word __fastcall xlsCheckColor(const int AColor, TcxColorItemType AItemType);
	bool __fastcall xlsCheckPos(const int ACol, const int ARow);
	void __fastcall xlsCreateStyles(void);
	int __fastcall xlsRegisterFont(const Cxexport::TcxCacheCellStyle &AStyle);
	int __fastcall xlsRegisterStyle(const Cxexport::TcxCacheCellStyle &AStyle, System::Word &AType, bool IsMerge = false);
	void __fastcall xlsWriteBuf(System::Byte const *RecData, const int RecData_Size)/* overload */;
	void __fastcall xlsWriteBuf(const System::Word RecID, System::Byte const *RecData, const int RecData_Size)/* overload */;
	void __fastcall xlsWriteBuf(const System::Word RecID, const System::Word DataSize, System::Byte const *RecData, const int RecData_Size)/* overload */;
	void __fastcall xlsWriteBuffer(System::Word const *ARecData, const int ARecData_Size)/* overload */;
	void __fastcall xlsWriteBuffer(const System::Word RecID, const System::Word DataSize, const void *RecData)/* overload */;
	void __fastcall xlsWriteHeader(void);
	void __fastcall xlsWriteWorkBook(void);
	__property System::Classes::TStream* DataStream = {read=FStream};
	
public:
	__fastcall virtual TcxXLSExportProvider(const System::UnicodeString AFileName);
	__fastcall virtual ~TcxXLSExportProvider(void);
	__classmethod virtual int __fastcall ExportType();
	__classmethod virtual System::UnicodeString __fastcall ExportName();
private:
	void *__IcxNameExportProvider;	/* Cxexport::IcxNameExportProvider */
	void *__IcxExportProvider;	/* Cxexport::IcxExportProvider */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FC69194E-E3C7-41F4-98AE-5948813210AE}
	operator Cxexport::_di_IcxNameExportProvider()
	{
		Cxexport::_di_IcxNameExportProvider intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxexport::IcxNameExportProvider*(void) { return (Cxexport::IcxNameExportProvider*)&__IcxNameExportProvider; }
	#endif
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


class PASCALIMPLEMENTATION TcxXLSCellsData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<PcxXLSCell> _TcxXLSCellsData__1;
	
	
private:
	_TcxXLSCellsData__1 FCellsList;
	int FCellPerCol;
	int __fastcall GetFullSize(void);
	
protected:
	PcxXLSCell __fastcall GetCell(const int ACol, const int ARow);
	System::Word __fastcall PrepareCellStyle(System::Word &AType);
	PcxXLSCell __fastcall ReallocCellData(const int ACol, const int ARow, int AVarDataSize = 0x0);
	void __fastcall SetCellDataBoolean(const int ACol, const int ARow, const bool AValue);
	void __fastcall SetCellDataBlank(const int ACol, const int ARow);
	void __fastcall SetCellDataCurrency(const int ACol, const int ARow, const System::Currency AValue);
	void __fastcall SetCellDataDateTime(const int ACol, const int ARow, const System::TDateTime AValue);
	void __fastcall SetCellDataDouble(const int ACol, const int ARow, const double AValue);
	void __fastcall SetCellDataInteger(const int ACol, const int ARow, const int AValue);
	void __fastcall SetCellDataStringA(const int ACol, const int ARow, const System::UnicodeString AText);
	void __fastcall SetCellDataStringW(const int ACol, const int ARow, const System::WideString AText);
	void __fastcall SetCellDataSSTString(const int ACol, const int ARow, const int AIndex);
	void __fastcall SetRange(const int AColCount, const int ARowCount);
	__property int FullSize = {read=GetFullSize, nodefault};
	
public:
	__fastcall virtual ~TcxXLSCellsData(void);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TObject.Create */ inline __fastcall TcxXLSCellsData(void) : System::TObject() { }
	
};


class PASCALIMPLEMENTATION TcxXLSRecordsList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	System::Word FID;
	int __fastcall GetFullSize(void);
	void * __fastcall GetItem(int AIndex);
	int __fastcall GetItemSize(int AIndex);
	void * __fastcall GetRealItem(int AIndex);
	
public:
	__fastcall TcxXLSRecordsList(const System::Word RecordID);
	__fastcall virtual ~TcxXLSRecordsList(void);
	int __fastcall AddData(const void *AData, System::Word DataSize);
	int __fastcall AddUniqueData(System::Sysutils::PByteArray &AData);
	virtual void __fastcall Clear(void);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property void * Items[int AIndex] = {read=GetItem};
	__property int ItemSize[int AIndex] = {read=GetItemSize};
	__property int FullSize = {read=GetFullSize, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::StaticArray<System::Word, 4> NativeFormats;
static const System::Word XLS_Currency = System::Word(0x1003);
static const System::Word XLS_DateTime = System::Word(0x1000);
static const System::Word XLS_Date = System::Word(0x1001);
static const System::Word XLS_Time = System::Word(0x1002);
extern PACKAGE TxlsExportOptimization Optimization;
extern PACKAGE bool NeedStringParse;
extern PACKAGE System::Word __fastcall cxXlsGetDateTimeFormat(double &AValue);
}	/* namespace Cxxlsexport */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXXLSEXPORT)
using namespace Cxxlsexport;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxxlsexportHPP
