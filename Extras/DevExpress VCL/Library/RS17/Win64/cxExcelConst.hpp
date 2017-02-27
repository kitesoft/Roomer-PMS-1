// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExcelConst.pas' rev: 24.00 (Win64)

#ifndef CxexcelconstHPP
#define CxexcelconstHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexcelconst
{
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<System::Uitypes::TColor, 56> TcxExcelPalette;

typedef TcxExcelPalette *PcxExcelPalette;

struct TBiffRecHeader;
typedef TBiffRecHeader *PBiffRecHeader;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TBiffRecHeader
{
public:
	System::Word RecType;
	System::Word RecSize;
	System::StaticArray<System::Byte, 2147483643> RecData;
};
#pragma pack(pop)


struct TxlsTreeNode;
typedef TxlsTreeNode *PxlsTreeNode;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TxlsFileStorage
{
public:
	TxlsTreeNode *LinkToSST;
	TxlsTreeNode *RootHeader;
	TxlsTreeNode *Pages;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TxlsSheetInfo
{
public:
	System::Word SheetId;
	TxlsTreeNode *LinkToBoundSheet;
	TxlsTreeNode *LinkToWindow2;
	TxlsTreeNode *LinkToDimension;
	TxlsTreeNode *LinkToIndex;
	TxlsTreeNode *LinkToMergedCells;
	System::StaticArray<System::Byte, 20> BOF;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TxlsTreeNode
{
public:
	TxlsTreeNode *Next;
	TxlsTreeNode *Prev;
	union
	{
		struct 
		{
			System::StaticArray<int, 2055> IntData;
		};
		struct 
		{
			System::StaticArray<System::Word, 4110> WordData;
		};
		struct 
		{
			System::StaticArray<System::Byte, 8220> ByteData;
		};
		struct 
		{
			System::Word RecType;
			System::Word RecSize;
		};
		struct 
		{
			TxlsSheetInfo SheetInfo;
			TxlsTreeNode *SheetNodesList;
		};
		
	};
};
#pragma pack(pop)


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


typedef System::DynamicArray<TSSTBlock> TSSTList;

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


typedef System::DynamicArray<TSSSTStringInfo> TSSSTStringsInfo;

enum TcxSSFuncParams : unsigned char { fpVariable, fpFixed, fpNone };

typedef void __fastcall (*TcxProc)(void);

struct TcxExcelFuncDefinition;
typedef TcxExcelFuncDefinition *PcxExcelFuncDefinition;

struct DECLSPEC_DRECORD TcxExcelFuncDefinition
{
public:
	System::Word Token;
	System::UnicodeString Name;
	TcxProc Definition;
	#pragma pack(push,1)
	
public:
	TcxSSFuncParams Params;
	union
	{
		struct 
		{
			System::Byte ParamsCount;
		};
		
	};
	#pragma pack(pop)
};


typedef System::StaticArray<TcxExcelFuncDefinition, 81> Cxexcelconst__1;

typedef System::StaticArray<System::UnicodeString, 50> Cxexcelconst__2;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 brc1904 = System::Int8(0x22);
static const System::Byte brcADDIN = System::Byte(0x87);
static const System::Byte brcADDMENU = System::Byte(0xc2);
static const System::Word brcARRAY = System::Word(0x221);
static const System::Byte brcAUTOFILTER = System::Byte(0x9e);
static const System::Byte brcAUTOFILTERINFO = System::Byte(0x9d);
static const System::Int8 brcBACKUP = System::Int8(0x40);
static const System::Word brcBLANK = System::Word(0x201);
static const System::Word brcBOF = System::Word(0x809);
static const System::Byte brcBOOKBOOL = System::Byte(0xda);
static const System::Word brcBOOLERR = System::Word(0x205);
static const System::Int8 brcBOTTOMMARGIN = System::Int8(0x29);
static const System::Byte brcBOUNDSHEET = System::Byte(0x85);
static const System::Int8 brcCALCCOUNT = System::Int8(0xc);
static const System::Int8 brcCALCMODE = System::Int8(0xd);
static const System::Word brcCF = System::Word(0x1b1);
static const System::Int8 brcCODENAME = System::Int8(0x42);
static const System::Int8 brcCODEPAGE = System::Int8(0x42);
static const System::Int8 brcCOLINFO = System::Int8(0x7d);
static const System::Word brcCONDFMT = System::Word(0x1b0);
static const System::Int8 brcCONTINUE = System::Int8(0x3c);
static const System::Word brcCONTINUEFRT = System::Word(0x812);
static const System::Byte brcCOORDLIST = System::Byte(0xa9);
static const System::Byte brcCOUNTRY = System::Byte(0x8c);
static const System::Int8 brcCRN = System::Int8(0x5a);
static const System::Byte brcDBCELL = System::Byte(0xd7);
static const System::Word brcDBQUERYEXT = System::Word(0x803);
static const System::Int8 brcDCON = System::Int8(0x50);
static const System::Word brcDCONBIN = System::Word(0x1b5);
static const System::Int8 brcDCONNAME = System::Int8(0x52);
static const System::Int8 brcDCONREF = System::Int8(0x51);
static const System::Word brcDEFAULTROWHEIGHT = System::Word(0x225);
static const System::Int8 brcDEFCOLWIDTH = System::Int8(0x55);
static const System::Byte brcDELMENU = System::Byte(0xc3);
static const System::Int8 brcDELTA = System::Int8(0x10);
static const System::Word brcDIMENSIONS = System::Word(0x200);
static const System::Byte brcDOCROUTE = System::Byte(0xb8);
static const System::Word brcDSF = System::Word(0x161);
static const System::Word brcDV = System::Word(0x1be);
static const System::Word brcDVAL = System::Word(0x1b2);
static const System::Byte brcEDG = System::Byte(0x88);
static const System::Int8 brcEOF = System::Int8(0xa);
static const System::Word brcEXCEL9FILE = System::Word(0x1c0);
static const System::Int8 brcEXTERNCOUNT = System::Int8(0x16);
static const System::Int8 brcEXTERNNAME = System::Int8(0x23);
static const System::Int8 brcEXTERNSHEET = System::Int8(0x17);
static const System::Byte brcEXTSST = System::Byte(0xff);
static const System::Word brcEXTSTRING = System::Word(0x804);
static const System::Int8 brcFILEPASS = System::Int8(0x2f);
static const System::Int8 brcFILESHARING = System::Int8(0x5b);
static const System::Word brcFILESHARING2 = System::Word(0x1a5);
static const System::Byte brcFILTERMODE = System::Byte(0x9b);
static const System::Byte brcFNGROUPCOUNT = System::Byte(0x9c);
static const System::Byte brcFNGROUPNAME = System::Byte(0x9a);
static const System::Int8 brcFONT = System::Int8(0x31);
static const System::Int8 brcFOOTER = System::Int8(0x15);
static const System::Word brcFORMAT = System::Word(0x41e);
static const System::Int8 brcFORMULA = System::Int8(0x6);
static const System::Byte brcGCW = System::Byte(0xab);
static const System::Byte brcGRIDSET = System::Byte(0x82);
static const System::Byte brcGUTS = System::Byte(0x80);
static const System::Byte brcHCENTER = System::Byte(0x83);
static const System::Int8 brcHEADER = System::Int8(0x14);
static const System::Byte brcHIDEOBJ = System::Byte(0x8d);
static const System::Word brcHLINK = System::Word(0x1b8);
static const System::Word brcHLINKTOOLTIP = System::Word(0x800);
static const System::Int8 brcHORIZONTALPAGEBREAKS = System::Int8(0x1b);
static const System::Int8 brcIMDATA = System::Int8(0x7f);
static const System::Word brcINDEX = System::Word(0x20b);
static const System::Byte brcINTERFACEEND = System::Byte(0xe2);
static const System::Byte brcINTERFACEHDR = System::Byte(0xe1);
static const System::Int8 brcITERATION = System::Int8(0x11);
static const System::Word brcLABEL = System::Word(0x204);
static const System::Byte brcLABELSST = System::Byte(0xfd);
static const System::Int8 brcLEFTMARGIN = System::Int8(0x26);
static const System::Byte brcLHNGRAPH = System::Byte(0x95);
static const System::Byte brcLHRECORD = System::Byte(0x94);
static const System::Byte brcLPR = System::Byte(0x98);
static const System::Byte brcMERGECELLS = System::Byte(0xe5);
static const System::Byte brcMMS = System::Byte(0xc1);
static const System::Byte brcMSODRAWING = System::Byte(0xec);
static const System::Byte brcMSODRAWINGGROUP = System::Byte(0xed);
static const System::Byte brcMSODRAWINGSELECTION = System::Byte(0xed);
static const System::Byte brcMULBLANK = System::Byte(0xbe);
static const System::Byte brcMULRK = System::Byte(0xbd);
static const System::Int8 brcNAME = System::Int8(0x18);
static const System::Int8 brcNOTE = System::Int8(0x1c);
static const System::Word brcNUMBER = System::Word(0x203);
static const System::Int8 brcOBJ = System::Int8(0x5d);
static const System::Int8 brcOBJPROTECT = System::Int8(0x63);
static const System::Byte brcOBPROJ = System::Byte(0xd3);
static const System::Word brcOLEDBCONN = System::Word(0x80a);
static const System::Byte brcOLESIZE = System::Byte(0xde);
static const System::Byte brcPALETTE = System::Byte(0x92);
static const System::Int8 brcPANE = System::Int8(0x41);
static const System::Byte brcPARAMQRY = System::Byte(0xdc);
static const System::Int8 brcPASSWORD = System::Int8(0x13);
static const System::Int8 brcPLS = System::Int8(0x4d);
static const System::Int8 brcPRECISION = System::Int8(0xe);
static const System::Int8 brcPRINTGRIDLINES = System::Int8(0x2b);
static const System::Int8 brcPRINTHEADERS = System::Int8(0x2a);
static const System::Int8 brcPROTECT = System::Int8(0x12);
static const System::Word brcPROT4REV = System::Word(0x1af);
static const System::Word brcQSI = System::Word(0x1ad);
static const System::Word brcQSIF = System::Word(0x807);
static const System::Word brcQSIR = System::Word(0x806);
static const System::Word brcQSISXTAG = System::Word(0x802);
static const System::Word brcRECALCID = System::Word(0x1c1);
static const System::Byte brcRECIPNAME = System::Byte(0xb9);
static const System::Int8 brcREFMODE = System::Int8(0xf);
static const System::Word brcREFRESHALL = System::Word(0x1b7);
static const System::Int8 brcRIGHTMARGIN = System::Int8(0x27);
static const System::Word brcRK = System::Word(0x27e);
static const System::Word brcROW = System::Word(0x208);
static const System::Byte brcRSTRING = System::Byte(0xd6);
static const System::Int8 brcSAVERECALC = System::Int8(0x5f);
static const System::Byte brcSCENARIO = System::Byte(0xaf);
static const System::Byte brcSCENMAN = System::Byte(0xae);
static const System::Byte brcSCENPROTECT = System::Byte(0xdd);
static const System::Byte brcSCL = System::Byte(0xa0);
static const System::Int8 brcSELECTION = System::Int8(0x1d);
static const System::Byte brcSETUP = System::Byte(0xa1);
static const System::Word brcSHRFMLA = System::Word(0x4bc);
static const System::Byte brcSORT = System::Byte(0x90);
static const System::Byte brcSOUND = System::Byte(0x96);
static const System::Byte brcSST = System::Byte(0xfc);
static const System::Byte brcSTANDARDWIDTH = System::Byte(0x99);
static const System::Word brcSTRING = System::Word(0x207);
static const System::Word brcSTYLE = System::Word(0x293);
static const System::Byte brcSUB = System::Byte(0x91);
static const System::Word brcSUPBOOK = System::Word(0x1ae);
static const System::Byte brcSXDB = System::Byte(0xc6);
static const System::Word brcSXDBEX = System::Word(0x122);
static const System::Byte brcSXDI = System::Byte(0xc5);
static const System::Byte brcSXEX = System::Byte(0xf1);
static const System::Byte brcSXEXT = System::Byte(0xdc);
static const System::Word brcSXFDBTYPE = System::Word(0x1bb);
static const System::Byte brcSXFILT = System::Byte(0xf2);
static const System::Byte brcSXFORMAT = System::Byte(0xfb);
static const System::Word brcSXFORMULA = System::Word(0x103);
static const System::Byte brcSXFMLA = System::Byte(0xf9);
static const System::Byte brcSXIDSTM = System::Byte(0xd5);
static const System::Byte brcSXIVD = System::Byte(0xb4);
static const System::Byte brcSXLI = System::Byte(0xb5);
static const System::Byte brcSXNAME = System::Byte(0xf6);
static const System::Byte brcSXPAIR = System::Byte(0xf8);
static const System::Byte brcSXPI = System::Byte(0xb6);
static const System::Word brcSXPIEX = System::Word(0x80e);
static const System::Byte brcSXRULE = System::Byte(0xf0);
static const System::Byte brcSXSTRING = System::Byte(0xcd);
static const System::Byte brcSXSELECT = System::Byte(0xf7);
static const System::Byte brcSXTBL = System::Byte(0xd0);
static const System::Byte brcSXTBPG = System::Byte(0xd2);
static const System::Byte brcSXTBRGIITM = System::Byte(0xd1);
static const System::Word brcSXTH = System::Word(0x80d);
static const System::Byte brcSXVD = System::Byte(0xb1);
static const System::Word brcSXVDEX = System::Word(0x100);
static const System::Word brcSXVDTEX = System::Word(0x80f);
static const System::Byte brcSXVI = System::Byte(0xb2);
static const System::Byte brcSXVIEW = System::Byte(0xb0);
static const System::Word brcSXVIEWEX = System::Word(0x80c);
static const System::Word brcSXVIEWEX9 = System::Word(0x810);
static const System::Byte brcSXVS = System::Byte(0xe3);
static const System::Word brcTABID = System::Word(0x13d);
static const System::Byte brcTABIDCONF = System::Byte(0xea);
static const System::Word brcTABLE = System::Word(0x236);
static const System::Int8 brcTEMPLATE = System::Int8(0x60);
static const System::Int8 brcTOPMARGIN = System::Int8(0x28);
static const System::Word brcTXO = System::Word(0x1b6);
static const System::Byte brcUDDESC = System::Byte(0xdf);
static const System::Int8 brcUNCALCED = System::Int8(0x5e);
static const System::Word brcUSERBVIEW = System::Word(0x1a9);
static const System::Word brcUSERSVIEWBEGIN = System::Word(0x1aa);
static const System::Word brcUSERSVIEWEND = System::Word(0x1ab);
static const System::Word brcUSESELFS = System::Word(0x160);
static const System::Byte brcVCENTER = System::Byte(0x84);
static const System::Int8 brcVERTICALPAGEBREAKS = System::Int8(0x1a);
static const System::Int8 brcWINDOW1 = System::Int8(0x3d);
static const System::Word brcWINDOW2 = System::Word(0x23e);
static const System::Int8 brcWINDOWPROTECT = System::Int8(0x19);
static const System::Word brcWOPT = System::Word(0x80b);
static const System::Int8 brcWRITEACCESS = System::Int8(0x5c);
static const System::Byte brcWRITEPROT = System::Byte(0x86);
static const System::Byte brcWSBOOL = System::Byte(0x81);
static const System::Int8 brcXCT = System::Int8(0x59);
static const System::Byte brcXF = System::Byte(0xe0);
static const System::Word brcXL5MODIFY = System::Word(0x162);
static const System::Word brcnCF = System::Word(0x1b1);
static const System::Word brcnCODENAME = System::Word(0x1ba);
static const System::Word brcnCONDFMT = System::Word(0x11b0);
static const System::Word brcnDCONBIN = System::Word(0x11b5);
static const System::Word brcnDSF = System::Word(0x1161);
static const System::Word brcnDV = System::Word(0x11be);
static const System::Word brcnDVAL = System::Word(0x11b2);
static const System::Word brcnEXCEL9FILE = System::Word(0x11c0);
static const System::Word brcnEXTSST = System::Word(0x1ff);
static const System::Word brcnHLINK = System::Word(0x11b8);
static const System::Word brcnLABELSST = System::Word(0x1fd);
static const System::Word brcnMERGECELLS = System::Word(0x1e5);
static const System::Word brcnMSODRAWING = System::Word(0x1ec);
static const System::Word brcnMSODRAWINGGROUP = System::Word(0x1eb);
static const System::Word brcnMSODRAWINGSELECTION = System::Word(0x1ed);
static const System::Word brcnPARAMQRY = System::Word(0x1dc);
static const System::Word brcnPROT4REV = System::Word(0x11af);
static const System::Word brcnPROT4REVPASS = System::Word(0x1bc);
static const System::Word brcnQSI = System::Word(0x11ad);
static const System::Word brcnRECALCID = System::Word(0x11c1);
static const System::Word brcnREFRESHALL = System::Word(0x11b7);
static const System::Word brcnSST = System::Word(0x1fc);
static const System::Word brcnSUPBOOK = System::Word(0x11ae);
static const System::Word brcnSXDB = System::Word(0x1c6);
static const System::Word brcnSXDBEX = System::Word(0x1122);
static const System::Word brcnSXEX = System::Word(0x1f1);
static const System::Word brcnSXFDBTYPE = System::Word(0x11bb);
static const System::Word brcnSXFILT = System::Word(0x1f2);
static const System::Word brcnSXFMLA = System::Word(0x1f9);
static const System::Word brcnSXFORMAT = System::Word(0x1fb);
static const System::Word brcnSXFORMULA = System::Word(0x1103);
static const System::Word brcnSXNAME = System::Word(0x1f6);
static const System::Word brcnSXPAIR = System::Word(0x1f8);
static const System::Word brcnSXRULE = System::Word(0x1f0);
static const System::Word brcnSXSELECT = System::Word(0x1f7);
static const System::Word brcnSXVDEX = System::Word(0x1100);
static const System::Word brcnTXO = System::Word(0x11b6);
static const System::Word brcnUSERBVIEW = System::Word(0x11a9);
static const System::Word brcnUSERSVIEWBEGIN = System::Word(0x11aa);
static const System::Word brcnUSERSVIEWEND = System::Word(0x11ab);
static const System::Word brcnUSESELFS = System::Word(0x1160);
static const System::Word brcnXL5MODIFY = System::Word(0x1162);
static const System::Int8 ptgExp = System::Int8(0x1);
static const System::Int8 ptgTbl = System::Int8(0x2);
static const System::Int8 ptgAdd = System::Int8(0x3);
static const System::Int8 ptgSub = System::Int8(0x4);
static const System::Int8 ptgMul = System::Int8(0x5);
static const System::Int8 ptgDiv = System::Int8(0x6);
static const System::Int8 ptgPower = System::Int8(0x7);
static const System::Int8 ptgConcat = System::Int8(0x8);
static const System::Int8 ptgLT = System::Int8(0x9);
static const System::Int8 ptgLE = System::Int8(0xa);
static const System::Int8 ptgEQ = System::Int8(0xb);
static const System::Int8 ptgGE = System::Int8(0xc);
static const System::Int8 ptgGT = System::Int8(0xd);
static const System::Int8 ptgNE = System::Int8(0xe);
static const System::Int8 ptgIsect = System::Int8(0xf);
static const System::Int8 ptgUnion = System::Int8(0x10);
static const System::Int8 ptgRange = System::Int8(0x11);
static const System::Int8 ptgUplus = System::Int8(0x12);
static const System::Int8 ptgUminus = System::Int8(0x13);
static const System::Int8 ptgPercent = System::Int8(0x14);
static const System::Int8 ptgParen = System::Int8(0x15);
static const System::Int8 ptgMissArg = System::Int8(0x16);
static const System::Int8 ptgStr = System::Int8(0x17);
static const System::Int8 ptgExtend = System::Int8(0x18);
static const System::Int8 ptgAttr = System::Int8(0x19);
static const System::Int8 ptgSheet = System::Int8(0x1a);
static const System::Int8 ptgEndSheet = System::Int8(0x1b);
static const System::Int8 ptgErr = System::Int8(0x1c);
static const System::Int8 ptgBool = System::Int8(0x1d);
static const System::Int8 ptgInt = System::Int8(0x1e);
static const System::Int8 ptgNum = System::Int8(0x1f);
static const System::Int8 ptgArray = System::Int8(0x20);
static const System::Int8 ptgFunc = System::Int8(0x21);
static const System::Int8 ptgFuncVar = System::Int8(0x22);
static const System::Int8 ptgName = System::Int8(0x23);
static const System::Int8 ptgRef = System::Int8(0x24);
static const System::Int8 ptgArea = System::Int8(0x25);
static const System::Int8 ptgMemArea = System::Int8(0x26);
static const System::Int8 ptgMemErr = System::Int8(0x27);
static const System::Int8 ptgMemNoMem = System::Int8(0x28);
static const System::Int8 ptgMemFunc = System::Int8(0x29);
static const System::Int8 ptgRefErr = System::Int8(0x2a);
static const System::Int8 ptgAreaErr = System::Int8(0x2b);
static const System::Int8 ptgRefN = System::Int8(0x2c);
static const System::Int8 ptgAreaN = System::Int8(0x2d);
static const System::Int8 ptgMemAreaN = System::Int8(0x2e);
static const System::Int8 ptgMemNoMemN = System::Int8(0x2f);
static const System::Int8 ptgNameX = System::Int8(0x39);
static const System::Int8 ptgRef3d = System::Int8(0x3a);
static const System::Int8 ptgArea3d = System::Int8(0x3b);
static const System::Int8 ptgRefErr3d = System::Int8(0x3c);
static const System::Int8 ptgAreaErr3d = System::Int8(0x3d);
static const System::Int8 ptgArrayV = System::Int8(0x40);
static const System::Int8 ptgFuncV = System::Int8(0x41);
static const System::Int8 ptgFuncVarV = System::Int8(0x42);
static const System::Int8 ptgNameV = System::Int8(0x43);
static const System::Int8 ptgRefV = System::Int8(0x44);
static const System::Int8 ptgAreaV = System::Int8(0x45);
static const System::Int8 ptgMemAreaV = System::Int8(0x46);
static const System::Int8 ptgMemErrV = System::Int8(0x47);
static const System::Int8 ptgMemNoMemV = System::Int8(0x48);
static const System::Int8 ptgMemFuncV = System::Int8(0x49);
static const System::Int8 ptgRefErrV = System::Int8(0x4a);
static const System::Int8 ptgAreaErrV = System::Int8(0x4b);
static const System::Int8 ptgRefNV = System::Int8(0x4c);
static const System::Int8 ptgAreaNV = System::Int8(0x4d);
static const System::Int8 ptgMemAreaNV = System::Int8(0x4e);
static const System::Int8 ptgMemNoMemNV = System::Int8(0x4f);
static const System::Int8 ptgFuncCEV = System::Int8(0x58);
static const System::Int8 ptgNameXV = System::Int8(0x59);
static const System::Int8 ptgRef3dV = System::Int8(0x5a);
static const System::Int8 ptgArea3dV = System::Int8(0x5b);
static const System::Int8 ptgRefErr3dV = System::Int8(0x5c);
static const System::Int8 ptgAreaErr3dV = System::Int8(0x5d);
static const System::Int8 ptgArrayA = System::Int8(0x60);
static const System::Int8 ptgFuncA = System::Int8(0x61);
static const System::Int8 ptgFuncVarA = System::Int8(0x62);
static const System::Int8 ptgNameA = System::Int8(0x63);
static const System::Int8 ptgRefA = System::Int8(0x64);
static const System::Int8 ptgAreaA = System::Int8(0x65);
static const System::Int8 ptgMemAreaA = System::Int8(0x66);
static const System::Int8 ptgMemErrA = System::Int8(0x67);
static const System::Int8 ptgMemNoMemA = System::Int8(0x68);
static const System::Int8 ptgMemFuncA = System::Int8(0x69);
static const System::Int8 ptgRefErrA = System::Int8(0x6a);
static const System::Int8 ptgAreaErrA = System::Int8(0x6b);
static const System::Int8 ptgRefNA = System::Int8(0x6c);
static const System::Int8 ptgAreaNA = System::Int8(0x6d);
static const System::Int8 ptgMemAreaNA = System::Int8(0x6e);
static const System::Int8 ptgMemNoMemNA = System::Int8(0x6f);
static const System::Int8 ptgFuncCEA = System::Int8(0x78);
static const System::Int8 ptgNameXA = System::Int8(0x79);
static const System::Int8 ptgRef3dA = System::Int8(0x7a);
static const System::Int8 ptgArea3dA = System::Int8(0x7b);
static const System::Int8 ptgRefErr3dA = System::Int8(0x7c);
static const System::Int8 ptgAreaErr3dA = System::Int8(0x7d);
extern PACKAGE Cxexcelconst__1 DefaultXLSFunctions;
extern PACKAGE System::StaticArray<System::Byte, 16> BOF;
extern PACKAGE System::StaticArray<System::Byte, 18> WINDOW1;
extern PACKAGE System::StaticArray<System::Word, 2> EOF_REC;
extern PACKAGE System::StaticArray<System::StaticArray<System::Byte, 20>, 17> DefaultStylesTable;
extern PACKAGE System::StaticArray<System::Word, 13> DefaultFont;
extern PACKAGE TcxExcelPalette cxExcelStdColors;
extern PACKAGE System::StaticArray<System::Word, 59> ExcelColorIndexes;
extern PACKAGE Cxexcelconst__2 ExcelDefaultFormats;
static const System::Int8 IsUnicodeStr = System::Int8(0x1);
static const System::Int8 IsRichStr = System::Int8(0x8);
static const System::Int8 cxSSDefaultColorValue = System::Int8(0x39);
extern PACKAGE System::Set<System::Byte, 0, 255>  DateTimeFormats;
extern PACKAGE System::Set<System::Byte, 0, 255>  CurrencyFormats;
extern PACKAGE System::Set<System::Byte, 0, 255>  NumberFormats;
extern PACKAGE void __fastcall CheckFormat(const System::UnicodeString Format, System::Word &Index);
extern PACKAGE bool __fastcall FormatIsCurrency(const int AIndex)/* overload */;
extern PACKAGE bool __fastcall FormatIsCurrency(const System::UnicodeString Format, int &AIndex)/* overload */;
extern PACKAGE bool __fastcall FormatIsDateTime(const int AIndex)/* overload */;
extern PACKAGE bool __fastcall FormatIsDateTime(const System::UnicodeString Format, int &AIndex)/* overload */;
extern PACKAGE bool __fastcall FormatIsNumber(const int AIndex)/* overload */;
extern PACKAGE bool __fastcall FormatIsNumber(const System::UnicodeString Format, int &AIndex)/* overload */;
extern PACKAGE bool __fastcall FormatIsRegistered(const int AIndex);
extern PACKAGE bool __fastcall FuncArgByToken(const int AToken, int &ACount);
extern PACKAGE PcxExcelFuncDefinition __fastcall FuncDefByToken(const int AToken);
extern PACKAGE PcxExcelFuncDefinition __fastcall FuncDefByName(const System::UnicodeString AName);
extern PACKAGE bool __fastcall FuncNameByToken(const int AToken, System::UnicodeString &AName);
extern PACKAGE PcxExcelFuncDefinition __fastcall RegisterFunction(const System::UnicodeString AName, const int AToken, const int MinArgs);
extern PACKAGE System::Word __fastcall xlsSetColor(System::Uitypes::TColor AColor, PcxExcelPalette APalette, System::Word ADefault);
}	/* namespace Cxexcelconst */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXCELCONST)
using namespace Cxexcelconst;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexcelconstHPP
