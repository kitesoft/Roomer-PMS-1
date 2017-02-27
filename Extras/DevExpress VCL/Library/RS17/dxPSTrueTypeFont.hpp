// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSTrueTypeFont.pas' rev: 24.00 (Win32)

#ifndef DxpstruetypefontHPP
#define DxpstruetypefontHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpstruetypefont
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EdxPSTTFFileException;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxPSTTFFileException : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxPSTTFFileException(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxPSTTFFileException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxPSTTFFileException(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxPSTTFFileException(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPSTTFFileException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPSTTFFileException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxPSTTFFileException(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxPSTTFFileException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPSTTFFileException(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPSTTFFileException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPSTTFFileException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPSTTFFileException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxPSTTFFileException(void) { }
	
};

#pragma pack(pop)

typedef int TdxPSTTFSectionTag;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPSTTFTableEntryData
{
public:
	unsigned CheckSum;
	unsigned Length;
	unsigned Offset;
	int Tag;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPSTTFMapEntryInfo
{
public:
	System::Word Delta;
	System::Word EntryEnd;
	System::Word EntryStarts;
	System::Word RangeOffsets;
};
#pragma pack(pop)


typedef System::DynamicArray<TdxPSTTFMapEntryInfo> TdxPSTTFMapEntryInfoList;

class DELPHICLASS TdxPSTTFCharCacheListItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFCharCacheListItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Word FCharCode;
	System::Word FGlyphIndex;
	
public:
	__fastcall TdxPSTTFCharCacheListItem(System::Word ACharCode, System::Word AGlyphIndex);
	__property System::Word CharCode = {read=FCharCode, nodefault};
	__property System::Word GlyphIndex = {read=FGlyphIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTTFCharCacheListItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFCharCacheList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFCharCacheList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FList;
	TdxPSTTFCharCacheListItem* __fastcall GetCacheItem(int AIndex);
	int __fastcall GetCount(void);
	
public:
	__fastcall virtual TdxPSTTFCharCacheList(void);
	__fastcall virtual ~TdxPSTTFCharCacheList(void);
	void __fastcall Add(System::Word ACharCode, System::Word AGlyphIndex);
	int __fastcall IndexOf(System::Word ACharCode);
	void __fastcall SortByGlyphIndex(void);
	__property TdxPSTTFCharCacheListItem* CacheItem[int Index] = {read=GetCacheItem};
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFStream;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFStream : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TStream* FStream;
	__int64 __fastcall GetPosition(void);
	__int64 __fastcall GetSize(void);
	void __fastcall SetPosition(__int64 AValue);
	
protected:
	void __fastcall ReorderBytes(System::Sysutils::PByteArray ABuff, int ABuffSize);
	void __fastcall ReorderLong(unsigned &L);
	void __fastcall ReorderWord(System::Word &W);
	
public:
	__fastcall virtual TdxPSTTFStream(System::Classes::TStream* AStream);
	unsigned __fastcall CalculateCheckSum(unsigned AStartsPosition, unsigned ALength);
	__int64 __fastcall ReadDate(void);
	unsigned __fastcall ReadLong(void);
	System::Word __fastcall ReadWord(void);
	virtual void __fastcall ReadRaw(void *Buffer, int Count);
	void __fastcall Seek(int AOffset, System::Classes::TSeekOrigin AOrigin = (System::Classes::TSeekOrigin)(0x1));
	void __fastcall WriteDate(__int64 AValue);
	void __fastcall WriteLong(unsigned AValue);
	virtual void __fastcall WritePadding(void);
	virtual void __fastcall WriteRaw(void *Buffer, int Count);
	void __fastcall WriteWord(System::Word AValue);
	__property __int64 Position = {read=GetPosition, write=SetPosition};
	__property __int64 Size = {read=GetSize};
	__property System::Classes::TStream* Stream = {read=FStream};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTTFStream(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFCustomObject;
class DELPHICLASS TdxPSTTFFile;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFCustomObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxPSTTFFile* FOwner;
	
protected:
	virtual void __fastcall LoadFromStream(TdxPSTTFStream* Stream) = 0 ;
	virtual void __fastcall SaveToStream(TdxPSTTFStream* Stream) = 0 ;
	
public:
	__fastcall virtual TdxPSTTFCustomObject(TdxPSTTFFile* AOwner);
	__property TdxPSTTFFile* Owner = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTTFCustomObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFCustomSection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFCustomSection : public TdxPSTTFCustomObject
{
	typedef TdxPSTTFCustomObject inherited;
	
private:
	bool FExists;
	unsigned FVersion;
	TdxPSTTFTableEntryData FTableEntryData;
	int __fastcall GetSectionOffset(void);
	
protected:
	virtual int __fastcall GetSize(void);
	virtual void __fastcall LoadFromStream(TdxPSTTFStream* Stream);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	void __fastcall ReadDataFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall Reset(void);
	virtual void __fastcall SaveToStream(TdxPSTTFStream* Stream);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	__property bool Exists = {read=FExists, write=FExists, nodefault};
	__property int SectionOffset = {read=GetSectionOffset, nodefault};
	__property int Size = {read=GetSize, nodefault};
	__property TdxPSTTFTableEntryData TableEntryData = {read=FTableEntryData};
	
public:
	__classmethod virtual int __fastcall Tag();
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFCustomSection(TdxPSTTFFile* AOwner) : TdxPSTTFCustomObject(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTTFCustomSection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFHeadSection;
class PASCALIMPLEMENTATION TdxPSTTFHeadSection : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	unsigned FCheckSum;
	__int64 FCreated;
	unsigned FFlags;
	short FFontDirectionHint;
	unsigned FFontRevision;
	short FGlyphDataFormat;
	short FIndexToLocFormat;
	System::Word FLowestRecPPEM;
	System::Word FMacStyle;
	unsigned FMaginNumber;
	System::Types::TSize FMaxSize;
	System::Types::TSize FMinSize;
	__int64 FModified;
	unsigned FUnitsPerEm;
	
protected:
	virtual int __fastcall GetSize(void);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	void __fastcall WriteCheckSum(TdxPSTTFStream* Stream);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	
public:
	__classmethod virtual int __fastcall Tag();
	__property short IndexToLocFormat = {read=FIndexToLocFormat, nodefault};
	__property System::Types::TSize MaxSize = {read=FMaxSize};
	__property System::Types::TSize MinSize = {read=FMinSize};
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFHeadSection(TdxPSTTFFile* AOwner) : TdxPSTTFCustomSection(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTTFHeadSection(void) { }
	
};


class DELPHICLASS TdxPSTTFHHEASection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFHHEASection : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	System::Word FAdvanceWidthMax;
	short FAscender;
	short FCaretSlopeRise;
	short FCaretSlopeRun;
	short FDescender;
	short FLineGap;
	short FMaxExtentX;
	short FMetricDataFormat;
	short FMinLeftSideBearing;
	short FMinRightSideBearing;
	System::Word FNumberOfHMetrics;
	System::StaticArray<System::Word, 5> FReserved;
	
protected:
	virtual int __fastcall GetSize(void);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	
public:
	__classmethod virtual int __fastcall Tag();
	__property System::Word AdvanceWidthMax = {read=FAdvanceWidthMax, nodefault};
	__property short Ascender = {read=FAscender, nodefault};
	__property short CaretSlopeRise = {read=FCaretSlopeRise, nodefault};
	__property short CaretSlopeRun = {read=FCaretSlopeRun, nodefault};
	__property short Descender = {read=FDescender, nodefault};
	__property short LineGap = {read=FLineGap, nodefault};
	__property short MaxExtentX = {read=FMaxExtentX, nodefault};
	__property short MetricDataFormat = {read=FMetricDataFormat, nodefault};
	__property short MinLeftSideBearing = {read=FMinLeftSideBearing, nodefault};
	__property short MinRightSideBearing = {read=FMinRightSideBearing, nodefault};
	__property System::Word NumberOfHMetrics = {read=FNumberOfHMetrics, nodefault};
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFHHEASection(TdxPSTTFFile* AOwner) : TdxPSTTFCustomSection(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTTFHHEASection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFMaxPSection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFMaxPSection : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	System::Word FMaxComponentDepth;
	System::Word FMaxComponentElements;
	System::Word FMaxCompositeContours;
	System::Word FMaxCompositePoints;
	System::Word FMaxContours;
	System::Word FMaxFunctionDefs;
	System::Word FMaxInstructionDefs;
	System::Word FMaxPoints;
	System::Word FMaxSizeOfInstructions;
	System::Word FMaxStackElements;
	System::Word FMaxStorage;
	System::Word FMaxTwilightPoints;
	System::Word FMaxZones;
	System::Word FNumGlyphs;
	
protected:
	virtual int __fastcall GetSize(void);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	
public:
	__classmethod virtual int __fastcall Tag();
	__property System::Word NumGlyphs = {read=FNumGlyphs, nodefault};
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFMaxPSection(TdxPSTTFFile* AOwner) : TdxPSTTFCustomSection(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTTFMaxPSection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFCMapSection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFCMapSection : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	TdxPSTTFMapEntryInfoList FEntryInfoList;
	System::Word FID;
	System::StaticArray<System::Word, 65536> FMap;
	System::Word FVersion;
	System::Word __fastcall GetMap(System::Word Index);
	
protected:
	virtual int __fastcall GetSize(void);
	TdxPSTTFMapEntryInfoList __fastcall CalculateEntriesInfo(TdxPSTTFCharCacheList* ACharList);
	int __fastcall CalculateSegmentCount(TdxPSTTFCharCacheList* ACharList);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	void __fastcall ReadUnicodeTable(TdxPSTTFStream* Stream, int AUnicodeTableOffset);
	void __fastcall ReadUnicodeTableVersion4(TdxPSTTFStream* Stream);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	void __fastcall WriteGlyphIndexes(TdxPSTTFStream* Stream, const TdxPSTTFMapEntryInfoList AEntriesInfo);
	void __fastcall WriteUnicodeTable(TdxPSTTFStream* Stream, const TdxPSTTFMapEntryInfoList AEntriesInfo);
	
public:
	__fastcall virtual ~TdxPSTTFCMapSection(void);
	__classmethod virtual int __fastcall Tag();
	__property TdxPSTTFMapEntryInfoList EntryInfoList = {read=FEntryInfoList};
	__property System::Word ID = {read=FID, nodefault};
	__property System::Word Map[System::Word Index] = {read=GetMap};
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFCMapSection(TdxPSTTFFile* AOwner) : TdxPSTTFCustomSection(AOwner) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFOS2Section;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFOS2Section : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	System::Byte FFamilyClass;
	System::Byte FFamilySubClass;
	System::Word FFirstCharIndex;
	short FFontType;
	System::Word FLastCharIndex;
	tagPANOSE FPanose;
	System::StaticArray<char, 4> FVendor;
	
protected:
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	
public:
	__classmethod virtual int __fastcall Tag();
	__property System::Byte FamilyClass = {read=FFamilyClass, nodefault};
	__property System::Byte FamilySubClass = {read=FFamilySubClass, nodefault};
	__property short FontType = {read=FFontType, nodefault};
	__property tagPANOSE Panose = {read=FPanose};
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFOS2Section(TdxPSTTFFile* AOwner) : TdxPSTTFCustomSection(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTTFOS2Section(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPSTTFHMtxEntry
{
public:
	System::Word AdvanceWidth;
	short LeftSideBearing;
};
#pragma pack(pop)


class DELPHICLASS TdxPSTTFHMtxSection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFHMtxSection : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	typedef System::DynamicArray<TdxPSTTFHMtxEntry> _TdxPSTTFHMtxSection__1;
	
	
private:
	_TdxPSTTFHMtxSection__1 FEntries;
	TdxPSTTFHMtxEntry __fastcall GetEntry(int Index);
	int __fastcall GetEntryCount(void);
	TdxPSTTFHHEASection* __fastcall GetHHEASection(void);
	
protected:
	virtual int __fastcall GetSize(void);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	
public:
	__fastcall virtual ~TdxPSTTFHMtxSection(void);
	__classmethod virtual int __fastcall Tag();
	__property TdxPSTTFHMtxEntry Entry[int Index] = {read=GetEntry};
	__property int EntryCount = {read=GetEntryCount, nodefault};
	__property TdxPSTTFHHEASection* HHEASection = {read=GetHHEASection};
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFHMtxSection(TdxPSTTFFile* AOwner) : TdxPSTTFCustomSection(AOwner) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFLocaSection;
class DELPHICLASS TdxPSTTFGlyphSection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFLocaSection : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	typedef System::DynamicArray<int> _TdxPSTTFLocaSection__1;
	
	
private:
	_TdxPSTTFLocaSection__1 FOffsets;
	TdxPSTTFGlyphSection* __fastcall GetGlyphSection(void);
	int __fastcall GetIndexToLocFormat(void);
	int __fastcall GetOffset(int Index);
	
protected:
	void __fastcall CalculateOffsets(TdxPSTTFCharCacheList* ACharList);
	virtual int __fastcall GetSize(void);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	
public:
	__fastcall virtual ~TdxPSTTFLocaSection(void);
	__classmethod virtual int __fastcall Tag();
	void __fastcall Clear(void);
	__property TdxPSTTFGlyphSection* GlyphSection = {read=GetGlyphSection};
	__property int IndexToLocFormat = {read=GetIndexToLocFormat, nodefault};
	__property int Offset[int Index] = {read=GetOffset};
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFLocaSection(TdxPSTTFFile* AOwner) : TdxPSTTFCustomSection(AOwner) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFGlyphInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFGlyphInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FComponentGlyphs;
	void *FData;
	int FDataSize;
	int FIndex;
	int __fastcall GetComponentCount(void);
	System::Word __fastcall GetComponentGlyph(int Index);
	
public:
	__fastcall TdxPSTTFGlyphInfo(int AIndex, int ASize);
	__fastcall virtual ~TdxPSTTFGlyphInfo(void);
	void __fastcall ReadData(TdxPSTTFStream* Stream);
	void __fastcall WriteData(TdxPSTTFStream* Stream);
	__property System::Word ComponentGlyph[int Index] = {read=GetComponentGlyph};
	__property int ComponentCount = {read=GetComponentCount, nodefault};
	__property void * Data = {read=FData};
	__property int DataSize = {read=FDataSize, nodefault};
	__property int Index = {read=FIndex, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFGlyphSection : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	Cxclasses::TcxObjectList* FGlyphList;
	TdxPSTTFGlyphInfo* __fastcall GetGlyphInfo(int Index);
	int __fastcall GetGlyphInfoCount(void);
	TdxPSTTFLocaSection* __fastcall GetLocaSection(void);
	
protected:
	bool __fastcall GetGlyphInfoByGlyphIndex(int AGlyphIndex, /* out */ TdxPSTTFGlyphInfo* &AGlyphInfo);
	virtual int __fastcall GetSize(void);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	void __fastcall RemoveUnusedGlyphs(TdxPSTTFCharCacheList* ACharList);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	
public:
	__fastcall virtual TdxPSTTFGlyphSection(TdxPSTTFFile* AOwner);
	__fastcall virtual ~TdxPSTTFGlyphSection(void);
	__classmethod virtual int __fastcall Tag();
	__property TdxPSTTFGlyphInfo* GlyphInfo[int Index] = {read=GetGlyphInfo};
	__property int GlyphInfoCount = {read=GetGlyphInfoCount, nodefault};
	__property TdxPSTTFLocaSection* LocaSection = {read=GetLocaSection};
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFTableDirectory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFTableDirectory : public TdxPSTTFCustomObject
{
	typedef TdxPSTTFCustomObject inherited;
	
private:
	System::Word FEntrySelector;
	int FExistsSectionsCount;
	int FHeaderOffset;
	System::Word FRangeShift;
	System::Word FSearchRange;
	Cxclasses::TcxObjectList* FSections;
	unsigned FVersion;
	TdxPSTTFCustomSection* __fastcall GetSection(int AIndex);
	int __fastcall GetSectionCount(void);
	
protected:
	int __fastcall CalculateExistsSectionCount(void);
	TdxPSTTFCustomSection* __fastcall FindSection(const int ATag);
	bool __fastcall ReadSectionEntry(TdxPSTTFStream* Stream, TdxPSTTFCustomSection* ASection, int AEntriesCount, int AHeaderOffset);
	void __fastcall CalculateHeader(void);
	void __fastcall CalculateTableEntryDatas(int AHeaderSize);
	virtual void __fastcall LoadFromStream(TdxPSTTFStream* Stream);
	virtual void __fastcall SaveToStream(TdxPSTTFStream* Stream);
	
public:
	__fastcall virtual TdxPSTTFTableDirectory(TdxPSTTFFile* AOwner);
	__fastcall virtual ~TdxPSTTFTableDirectory(void);
	void __fastcall Register(TdxPSTTFCustomSection* ASection);
	__property int ExistsSectionsCount = {read=FExistsSectionsCount, nodefault};
	__property TdxPSTTFCustomSection* Section[int Index] = {read=GetSection};
	__property int SectionCount = {read=GetSectionCount, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFBinarySection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFBinarySection : public TdxPSTTFCustomSection
{
	typedef TdxPSTTFCustomSection inherited;
	
private:
	void *FData;
	int FDataSize;
	
protected:
	virtual int __fastcall GetSize(void);
	void __fastcall FreeBuffer(void);
	virtual void __fastcall ReadData(TdxPSTTFStream* Stream);
	virtual void __fastcall WriteData(TdxPSTTFStream* Stream);
	
public:
	__fastcall virtual ~TdxPSTTFBinarySection(void);
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFBinarySection(TdxPSTTFFile* AOwner) : TdxPSTTFCustomSection(AOwner) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFPrepSection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFPrepSection : public TdxPSTTFBinarySection
{
	typedef TdxPSTTFBinarySection inherited;
	
public:
	__classmethod virtual int __fastcall Tag();
public:
	/* TdxPSTTFBinarySection.Destroy */ inline __fastcall virtual ~TdxPSTTFPrepSection(void) { }
	
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFPrepSection(TdxPSTTFFile* AOwner) : TdxPSTTFBinarySection(AOwner) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFCvtSection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFCvtSection : public TdxPSTTFBinarySection
{
	typedef TdxPSTTFBinarySection inherited;
	
public:
	__classmethod virtual int __fastcall Tag();
public:
	/* TdxPSTTFBinarySection.Destroy */ inline __fastcall virtual ~TdxPSTTFCvtSection(void) { }
	
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFCvtSection(TdxPSTTFFile* AOwner) : TdxPSTTFBinarySection(AOwner) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSTTFFpgmSection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFFpgmSection : public TdxPSTTFBinarySection
{
	typedef TdxPSTTFBinarySection inherited;
	
public:
	__classmethod virtual int __fastcall Tag();
public:
	/* TdxPSTTFBinarySection.Destroy */ inline __fastcall virtual ~TdxPSTTFFpgmSection(void) { }
	
public:
	/* TdxPSTTFCustomObject.Create */ inline __fastcall virtual TdxPSTTFFpgmSection(TdxPSTTFFile* AOwner) : TdxPSTTFBinarySection(AOwner) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSTTFFile : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxPSTTFCMapSection* FCMapSection;
	TdxPSTTFBinarySection* FCvtSection;
	TdxPSTTFBinarySection* FFpgmSection;
	TdxPSTTFGlyphSection* FGlyphSection;
	TdxPSTTFHeadSection* FHeadSection;
	TdxPSTTFHHEASection* FHHEASection;
	TdxPSTTFHMtxSection* FHMtxSection;
	TdxPSTTFLocaSection* FLocaSection;
	TdxPSTTFMaxPSection* FMaxPSection;
	TdxPSTTFOS2Section* FOS2Section;
	TdxPSTTFBinarySection* FPrepSection;
	TdxPSTTFTableDirectory* FTableDirectory;
	System::Word __fastcall GetCharCodeByGlyphIndex(System::Word AGlyphIndex);
	int __fastcall GetCharWidthByCode(System::Word ACharCode);
	int __fastcall GetCharWidthByGlyphIndex(System::Word AGlyphIndex);
	System::Word __fastcall GetGlyphIndex(System::Word ACharCode);
	float __fastcall GetScaleFactor(void);
	
public:
	__fastcall virtual TdxPSTTFFile(void)/* overload */;
	__fastcall virtual TdxPSTTFFile(Vcl::Graphics::TFont* AFont)/* overload */;
	__fastcall virtual ~TdxPSTTFFile(void);
	void __fastcall Rebuild(TdxPSTTFCharCacheList* ACharList);
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromFont(Vcl::Graphics::TFont* AFont);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property System::Word CharCodeByGlyphIndex[System::Word AGlyphIndex] = {read=GetCharCodeByGlyphIndex};
	__property int CharWidthByCode[System::Word ACharCode] = {read=GetCharWidthByCode};
	__property int CharWidthByGlyphIndex[System::Word AIndex] = {read=GetCharWidthByGlyphIndex};
	__property System::Word GlyphIndex[System::Word ACharCode] = {read=GetGlyphIndex};
	__property float ScaleFactor = {read=GetScaleFactor};
	__property TdxPSTTFCMapSection* CMapSection = {read=FCMapSection};
	__property TdxPSTTFGlyphSection* GlyphSection = {read=FGlyphSection};
	__property TdxPSTTFHeadSection* HeadSection = {read=FHeadSection};
	__property TdxPSTTFHHEASection* HHEASection = {read=FHHEASection};
	__property TdxPSTTFHMtxSection* HMtxSection = {read=FHMtxSection};
	__property TdxPSTTFLocaSection* LocaSection = {read=FLocaSection};
	__property TdxPSTTFMaxPSection* MaxPSection = {read=FMaxPSection};
	__property TdxPSTTFOS2Section* OS2Section = {read=FOS2Section};
	__property TdxPSTTFTableDirectory* TableDirectory = {read=FTableDirectory};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxPSGetFontCharsMap(Vcl::Graphics::TFont* AFont, /* out */ TdxPSTTFCMapSection* &AMap);
extern PACKAGE bool __fastcall dxPSGetFontData(System::Classes::TMemoryStream* AStream, Vcl::Graphics::TFont* AFont, int ATable = 0x0);
}	/* namespace Dxpstruetypefont */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSTRUETYPEFONT)
using namespace Dxpstruetypefont;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpstruetypefontHPP
