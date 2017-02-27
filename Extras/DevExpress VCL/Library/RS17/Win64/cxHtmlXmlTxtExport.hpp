// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxHtmlXmlTxtExport.pas' rev: 24.00 (Win64)

#ifndef CxhtmlxmltxtexportHPP
#define CxhtmlxmltxtexportHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.FmtBcd.hpp>	// Pascal unit
#include <Data.SqlTimSt.hpp>	// Pascal unit
#include <cxExport.hpp>	// Pascal unit
#include <cxExportStrs.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxhtmlxmltxtexport
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomHtmlXmlTXTExportProvider;
class PASCALIMPLEMENTATION TcxCustomHtmlXmlTXTExportProvider : public Cxexport::TcxCustomExportProvider
{
	typedef Cxexport::TcxCustomExportProvider inherited;
	
private:
	typedef System::DynamicArray<Cxexport::TcxCacheItem> _TcxCustomHtmlXmlTXTExportProvider__1;
	
	typedef System::DynamicArray<System::DynamicArray<Cxexport::TcxCacheItem> > _TcxCustomHtmlXmlTXTExportProvider__2;
	
	typedef System::DynamicArray<int> _TcxCustomHtmlXmlTXTExportProvider__3;
	
	typedef System::DynamicArray<int> _TcxCustomHtmlXmlTXTExportProvider__4;
	
	
private:
	_TcxCustomHtmlXmlTXTExportProvider__2 FCache;
	_TcxCustomHtmlXmlTXTExportProvider__3 FColumns;
	Cxexport::TcxCacheCellStyle FDefaultStyle;
	System::Classes::TInterfaceList* FInternalCacheList;
	System::UnicodeString FName;
	_TcxCustomHtmlXmlTXTExportProvider__4 FRows;
	Cxexport::TcxExportStyleManager* FStyleManager;
	Cxexport::TcxCacheItem __fastcall GetCacheItem(int ACol, int ARow);
	int __fastcall GetCellHeight(int ACol, int ARow);
	int __fastcall GetCellWidth(int ACol, int ARow);
	int __fastcall GetColumns(int ACol);
	Cxexport::PcxCacheCellStyle __fastcall GetDefaultStyle(void);
	int __fastcall GetHeight(void);
	int __fastcall GetInternalCacheCount(void);
	Cxexport::_di_IcxCellInternalCache __fastcall GetInternalCacheItems(int AIndex);
	int __fastcall GetRows(int ARow);
	int __fastcall GetStyleCount(void);
	int __fastcall GetWidth(void);
	void __fastcall TestIndex(int ACol, int ARow);
	void __fastcall TestCol(int ACol);
	void __fastcall TestRow(int ARow);
	void __fastcall TestStyleIndex(int AStyleIndex);
	
protected:
	DYNAMIC void __fastcall Clear(void);
	bool __fastcall GetCellData(const int ACol, const int ARow, void *AData);
	void __fastcall SetData(const int ACol, const int ARow, const int ADataSize, const int ADataType, const void *AData);
	void __fastcall SetEmptyData(const int ACol, const int ARow, const int ADataType);
	DYNAMIC void __fastcall Commit(void);
	System::UnicodeString __fastcall GetCacheName(void);
	Cxexport::PcxCacheCellStyle __fastcall GetCellStyle(const int ACol, const int ARow);
	int __fastcall GetExportType(void);
	System::UnicodeString __fastcall GetExportName(void);
	Cxexport::PcxCacheCellStyle __fastcall GetStyle(int AStyleIndex);
	int __fastcall RegisterStyle(const Cxexport::TcxCacheCellStyle &AStyle);
	virtual void __fastcall SetCellDataString(const int ACol, const int ARow, const System::UnicodeString AText);
	virtual void __fastcall SetCellDataAnsiString(const int ACol, const int ARow, const System::AnsiString AText);
	void __fastcall SetCellDataBoolean(const int ACol, const int ARow, const bool AValue);
	void __fastcall SetCellDataCurrency(const int ACol, const int ARow, const System::Currency AValue);
	void __fastcall SetCellDataDateTime(const int ACol, const int ARow, const System::TDateTime AValue);
	virtual void __fastcall SetCellDataWideString(const int ACol, const int ARow, const System::WideString AText);
	virtual void __fastcall SetCellDataDouble(const int ACol, const int ARow, const double AValue);
	virtual void __fastcall SetCellDataInteger(const int ACol, const int ARow, const int AValue);
	virtual void __fastcall SetCellStyle(const int ACol, const int ARow, const int AStyleIndex)/* overload */;
	virtual void __fastcall SetCellStyle(const int ACol, const int ARow, const int AExampleCol, const int AExampleRow)/* overload */;
	virtual void __fastcall SetCellStyle(const int ACol, const int ARow, const Cxexport::TcxCacheCellStyle &AStyle)/* overload */;
	void __fastcall SetCellStyleEx(const int ACol, const int ARow, const int H, const int W, const int AStyleIndex);
	void __fastcall SetCellUnion(const int ACol, const int ARow, int H, int W);
	void __fastcall SetCellValue(const int ACol, const int ARow, const System::Variant &AValue);
	void __fastcall SetColumnWidth(const int ACol, const int AWidth);
	void __fastcall SetDefaultStyle(const Cxexport::TcxCacheCellStyle &AStyle);
	void __fastcall SetRange(const int AColCount, const int ARowCount, bool IsVisible = true);
	void __fastcall SetRowHeight(const int ARow, const int AHeight);
	void __fastcall SetCellDataGraphic(const int ACol, const int ARow, Vcl::Graphics::TGraphic* &AGraphic);
	void __fastcall SetCellPNGImage(const int ACol, const int ARow, System::TObject* APNGImage);
	virtual bool __fastcall SupportGraphic(void);
	__property Cxexport::TcxCacheItem Cache[int ACol][int ARow] = {read=GetCacheItem};
	__property int Columns[int ACol] = {read=GetColumns};
	__property Cxexport::PcxCacheCellStyle DefaultStyle = {read=GetDefaultStyle};
	__property int RowCount = {read=GetHeight, nodefault};
	__property int InternalCacheCount = {read=GetInternalCacheCount, nodefault};
	__property Cxexport::_di_IcxCellInternalCache InternalCacheItems[int AIndex] = {read=GetInternalCacheItems};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property int Rows[int ARow] = {read=GetRows};
	__property int StyleCount = {read=GetStyleCount, nodefault};
	__property Cxexport::PcxCacheCellStyle Styles[int AIndex] = {read=GetStyle};
	__property int CellHeight[int ACol][int ARow] = {read=GetCellHeight};
	__property int CellWidth[int ACol][int ARow] = {read=GetCellWidth};
	__property int ColCount = {read=GetWidth, nodefault};
	
public:
	__fastcall virtual TcxCustomHtmlXmlTXTExportProvider(const System::UnicodeString AFileName);
	__fastcall virtual ~TcxCustomHtmlXmlTXTExportProvider(void);
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


class DELPHICLASS TcxCustomExportProviderSupportedCellInternalChache;
class PASCALIMPLEMENTATION TcxCustomExportProviderSupportedCellInternalChache : public TcxCustomHtmlXmlTXTExportProvider
{
	typedef TcxCustomHtmlXmlTXTExportProvider inherited;
	
protected:
	virtual void __fastcall CommitCache(System::Classes::TStream* AStream, void * AParam);
	virtual void __fastcall CommitStyle(System::Classes::TStream* AStream, void * AParam);
	void __fastcall DeleteCacheFromCell(const int ACol, const int ARow);
	void __fastcall SetCacheIntoCell(const int ACol, const int ARow, Cxexport::_di_IcxCellInternalCache ACache);
	void __fastcall SetEmptyCellsStyle(void);
public:
	/* TcxCustomHtmlXmlTXTExportProvider.Create */ inline __fastcall virtual TcxCustomExportProviderSupportedCellInternalChache(const System::UnicodeString AFileName) : TcxCustomHtmlXmlTXTExportProvider(AFileName) { }
	/* TcxCustomHtmlXmlTXTExportProvider.Destroy */ inline __fastcall virtual ~TcxCustomExportProviderSupportedCellInternalChache(void) { }
	
private:
	void *__IcxCellInternalCache;	/* Cxexport::IcxCellInternalCache */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {DEF62C25-0B11-4BD0-AE25-BABF7EDD7883}
	operator Cxexport::_di_IcxCellInternalCache()
	{
		Cxexport::_di_IcxCellInternalCache intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxexport::IcxCellInternalCache*(void) { return (Cxexport::IcxCellInternalCache*)&__IcxCellInternalCache; }
	#endif
	
};


class DELPHICLASS TcxHTMLExportProvider;
class PASCALIMPLEMENTATION TcxHTMLExportProvider : public TcxCustomExportProviderSupportedCellInternalChache
{
	typedef TcxCustomExportProviderSupportedCellInternalChache inherited;
	
private:
	void __fastcall CommitHTML(System::Classes::TStream* AStream);
	HIDESBASE System::UnicodeString __fastcall GetStyle(Cxexport::TcxCacheCellStyle &AStyle);
	System::UnicodeString __fastcall GetScaleRow(void);
	
protected:
	virtual void __fastcall CommitCache(System::Classes::TStream* AStream, void * AParam);
	virtual void __fastcall CommitStyle(System::Classes::TStream* AStream, void * AParam);
	int __fastcall GetContentWidth(void);
	
public:
	DYNAMIC void __fastcall Commit(void);
	__classmethod virtual int __fastcall ExportType();
	__classmethod virtual System::UnicodeString __fastcall ExportName();
public:
	/* TcxCustomHtmlXmlTXTExportProvider.Create */ inline __fastcall virtual TcxHTMLExportProvider(const System::UnicodeString AFileName) : TcxCustomExportProviderSupportedCellInternalChache(AFileName) { }
	/* TcxCustomHtmlXmlTXTExportProvider.Destroy */ inline __fastcall virtual ~TcxHTMLExportProvider(void) { }
	
};


class DELPHICLASS TcxXMLExportProvider;
class PASCALIMPLEMENTATION TcxXMLExportProvider : public TcxCustomExportProviderSupportedCellInternalChache
{
	typedef TcxCustomExportProviderSupportedCellInternalChache inherited;
	
private:
	bool FHideDotsOn;
	System::WideString FXSLFileName;
	void __fastcall CommitXML(System::Classes::TStream* AStream);
	void __fastcall CommitXSL(System::Classes::TStream* AStream);
	System::UnicodeString __fastcall ConvertTextToXML(const System::UnicodeString AText, int ACol, int ARow);
	System::UnicodeString __fastcall GetBorderStyle(Cxexport::TcxCacheCellStyle &AStyle);
	System::UnicodeString __fastcall GetCellParams(int ACol, int ARow);
	System::UnicodeString __fastcall GetData(int ACol, int ARow);
	HIDESBASE System::UnicodeString __fastcall GetStyle(Cxexport::TcxCacheCellStyle &AStyle);
	void __fastcall HideDots(void);
	System::UnicodeString __fastcall GetScaleLine(void);
	
protected:
	virtual void __fastcall CommitCache(System::Classes::TStream* AStream, void * AParam);
	virtual void __fastcall CommitStyle(System::Classes::TStream* AStream, void * AParam);
	
public:
	__fastcall virtual TcxXMLExportProvider(const System::UnicodeString AFileName);
	DYNAMIC void __fastcall Commit(void);
	__classmethod virtual int __fastcall ExportType();
	__classmethod virtual System::UnicodeString __fastcall ExportName();
public:
	/* TcxCustomHtmlXmlTXTExportProvider.Destroy */ inline __fastcall virtual ~TcxXMLExportProvider(void) { }
	
};


class DELPHICLASS TcxTXTExportProvider;
class PASCALIMPLEMENTATION TcxTXTExportProvider : public TcxCustomExportProviderSupportedCellInternalChache
{
	typedef TcxCustomExportProviderSupportedCellInternalChache inherited;
	
private:
	typedef System::DynamicArray<int> _TcxTXTExportProvider__1;
	
	
private:
	System::UnicodeString FBeginString;
	_TcxTXTExportProvider__1 FColMaxWidth;
	System::UnicodeString FEndString;
	int FIndex;
	System::UnicodeString FSeparator;
	void __fastcall CalculateColMaxWidth(void);
	System::UnicodeString __fastcall GetData(int ACol, int ARow);
	
protected:
	void __fastcall AddSeparator(const System::UnicodeString ASeparator);
	virtual void __fastcall CommitCache(System::Classes::TStream* AStream, void * AParam);
	virtual bool __fastcall SupportGraphic(void);
	
public:
	__fastcall virtual TcxTXTExportProvider(const System::UnicodeString AFileName);
	DYNAMIC void __fastcall Commit(void);
	__classmethod virtual int __fastcall ExportType();
	__classmethod virtual System::UnicodeString __fastcall ExportName();
public:
	/* TcxCustomHtmlXmlTXTExportProvider.Destroy */ inline __fastcall virtual ~TcxTXTExportProvider(void) { }
	
private:
	void *__IcxExportWithSeparators;	/* Cxexport::IcxExportWithSeparators */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0E2919A6-8B49-49D7-B55B-B44B6DECF2E5}
	operator Cxexport::_di_IcxExportWithSeparators()
	{
		Cxexport::_di_IcxExportWithSeparators intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxexport::IcxExportWithSeparators*(void) { return (Cxexport::IcxExportWithSeparators*)&__IcxExportWithSeparators; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString CharsetTag;
extern PACKAGE System::UnicodeString EncodingTag;
static const System::WideChar cxXMLEmptyChar = (System::WideChar)(0x2e);
extern PACKAGE System::UnicodeString cxExportDefaultEmptyString;
}	/* namespace Cxhtmlxmltxtexport */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXHTMLXMLTXTEXPORT)
using namespace Cxhtmlxmltxtexport;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxhtmlxmltxtexportHPP
