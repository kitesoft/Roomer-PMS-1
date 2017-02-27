// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPDFExportCore.pas' rev: 24.00 (Win64)

#ifndef DxpspdfexportcoreHPP
#define DxpspdfexportcoreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.ZLib.hpp>	// Pascal unit
#include <Vcl.Imaging.jpeg.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxPSPDFStrings.hpp>	// Pascal unit
#include <dxPSPDFCrypt.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpspdfexportcore
{
//-- type declarations -------------------------------------------------------
enum TdxPSPDFPageContentClipMode : unsigned char { pcmAdd, pcmDiff };

enum TdxPSPDFStreamEncoding : unsigned char { pseFlate, pseDCT };

enum TdxPSPDFStreamType : unsigned char { pstNone, pstText, pstImage };

class DELPHICLASS EdxPSPDFException;
class PASCALIMPLEMENTATION EdxPSPDFException : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxPSPDFException(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxPSPDFException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxPSPDFException(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxPSPDFException(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPSPDFException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxPSPDFException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxPSPDFException(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxPSPDFException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPSPDFException(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxPSPDFException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPSPDFException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxPSPDFException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxPSPDFException(void) { }
	
};


class DELPHICLASS TdxPSPDFWriter;
class DELPHICLASS TdxPSPDFCustomObject;
class DELPHICLASS TdxPSPDFEncryptCustomHelper;
class PASCALIMPLEMENTATION TdxPSPDFWriter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FCompressStreams;
	TdxPSPDFCustomObject* FCurrentObject;
	System::Classes::TStream* FCurrentStream;
	TdxPSPDFEncryptCustomHelper* FEncryptHelper;
	int FJPEGQuality;
	System::Classes::TList* FObjectsOffsets;
	System::Classes::TStream* FStream;
	System::Classes::TMemoryStream* FTempBufferStream;
	bool FUseJPEGCompression;
	void __fastcall AddObjectOffset(int AOffset);
	
protected:
	TdxPSPDFCustomObject* Catalog;
	TdxPSPDFCustomObject* DocumentInfo;
	TdxPSPDFCustomObject* EncryptInfo;
	void __fastcall BeginDocument(void);
	void __fastcall BeginObject(TdxPSPDFCustomObject* AObject);
	void __fastcall BeginStream(TdxPSPDFStreamType AStreamType);
	void __fastcall EndDocument(void);
	void __fastcall EndObject(void);
	void __fastcall EndStream(void);
	void __fastcall WriteStreamHeader(TdxPSPDFStreamType AStreamType);
	void __fastcall WriteTrailerSection(void);
	void __fastcall WriteXRefSection(void);
	__property bool CompressStreams = {read=FCompressStreams, nodefault};
	__property TdxPSPDFEncryptCustomHelper* EncryptHelper = {read=FEncryptHelper};
	__property int JPEGQuality = {read=FJPEGQuality, nodefault};
	__property System::Classes::TList* ObjectsOffsets = {read=FObjectsOffsets};
	__property System::Classes::TStream* Stream = {read=FStream};
	__property System::Classes::TMemoryStream* TempBufferStream = {read=FTempBufferStream};
	__property bool UseJPEGCompression = {read=FUseJPEGCompression, nodefault};
	
public:
	__fastcall virtual TdxPSPDFWriter(System::Classes::TStream* AStream, TdxPSPDFEncryptCustomHelper* AEncryptHelper, bool ACompressStreams, bool AUseJPEGCompression, int AJPEGQuality);
	__fastcall virtual ~TdxPSPDFWriter(void);
	System::UnicodeString __fastcall EncodeString(const System::UnicodeString S, bool AHexArray = true);
	TdxPSPDFStreamEncoding __fastcall GetStreamEncoding(TdxPSPDFStreamType AStreamType);
	System::UnicodeString __fastcall MakeLinkToObject(TdxPSPDFCustomObject* AObject);
	void __fastcall BeginParamsSet(void);
	void __fastcall EndParamsSet(void);
	void __fastcall WriteBitmap(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall WriteStream(System::Classes::TStream* AStream);
	void __fastcall WriteString(const System::UnicodeString S, bool AWriteCrLf = true);
	__property TdxPSPDFCustomObject* CurrentObject = {read=FCurrentObject};
	__property System::Classes::TStream* CurrentStream = {read=FCurrentStream};
};


class DELPHICLASS TdxPSPDFLength;
class DELPHICLASS TdxPSPDFObjectList;
class PASCALIMPLEMENTATION TdxPSPDFCustomObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxPSPDFLength* FContentStreamLength;
	int FIndex;
	
protected:
	virtual TdxPSPDFStreamType __fastcall GetContentStreamType(void);
	virtual void __fastcall BeginSave(TdxPSPDFWriter* AWriter);
	virtual void __fastcall EndSave(TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteContentStream(TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	__property TdxPSPDFLength* ContentStreamLength = {read=FContentStreamLength};
	__property TdxPSPDFStreamType ContentStreamType = {read=GetContentStreamType, nodefault};
	__property int Index = {read=FIndex, write=FIndex, nodefault};
	
public:
	__fastcall virtual ~TdxPSPDFCustomObject(void);
	virtual void __fastcall PopulateExportList(TdxPSPDFObjectList* AList);
	virtual void __fastcall SaveTo(TdxPSPDFWriter* AWriter);
public:
	/* TObject.Create */ inline __fastcall TdxPSPDFCustomObject(void) : System::TObject() { }
	
};


class DELPHICLASS TdxPSPDFObject;
class PASCALIMPLEMENTATION TdxPSPDFObject : public TdxPSPDFCustomObject
{
	typedef TdxPSPDFCustomObject inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetSubType();
	__classmethod virtual System::UnicodeString __fastcall GetType();
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFObject(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSPDFObject(void) : TdxPSPDFCustomObject() { }
	
};


class DELPHICLASS TdxPSPDFDocumentInfo;
class PASCALIMPLEMENTATION TdxPSPDFDocumentInfo : public TdxPSPDFCustomObject
{
	typedef TdxPSPDFCustomObject inherited;
	
private:
	System::UnicodeString FAuthor;
	System::UnicodeString FCreator;
	System::UnicodeString FKeywords;
	System::UnicodeString FProducer;
	System::UnicodeString FSubject;
	System::UnicodeString FTitle;
	
protected:
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	
public:
	__property System::UnicodeString Author = {read=FAuthor, write=FAuthor};
	__property System::UnicodeString Creator = {read=FCreator, write=FCreator};
	__property System::UnicodeString Keywords = {read=FKeywords, write=FKeywords};
	__property System::UnicodeString Producer = {read=FProducer, write=FProducer};
	__property System::UnicodeString Subject = {read=FSubject, write=FSubject};
	__property System::UnicodeString Title = {read=FTitle, write=FTitle};
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFDocumentInfo(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSPDFDocumentInfo(void) : TdxPSPDFCustomObject() { }
	
};


class PASCALIMPLEMENTATION TdxPSPDFObjectList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
private:
	HIDESBASE TdxPSPDFCustomObject* __fastcall GetItem(int Index);
	
public:
	virtual void __fastcall PopulateExportList(TdxPSPDFObjectList* AList);
	void __fastcall SaveTo(TdxPSPDFWriter* AWriter);
	__property TdxPSPDFCustomObject* Items[int Index] = {read=GetItem};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxPSPDFObjectList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxPSPDFObjectList(void) { }
	
};


class DELPHICLASS TdxPSPDFPageContent;
class DELPHICLASS TdxPSPDFCustomFont;
class DELPHICLASS TdxPSPDFPage;
class DELPHICLASS TdxPSPDFPatternList;
class DELPHICLASS TdxPSPDFCustomPattern;
class PASCALIMPLEMENTATION TdxPSPDFPageContent : public TdxPSPDFCustomObject
{
	typedef TdxPSPDFCustomObject inherited;
	
private:
	System::Classes::TMemoryStream* FContentStream;
	float FCoordsConversionFactor;
	TdxPSPDFCustomFont* FFont;
	System::Uitypes::TColor FFontColor;
	double FFontSize;
	System::Uitypes::TColor FForeColor;
	TdxPSPDFPage* FParent;
	int __fastcall AddBitmap(Vcl::Graphics::TBitmap* ABitmap);
	bool __fastcall CheckColor(System::Uitypes::TColor &AColor);
	Vcl::Graphics::TBitmap* __fastcall CreateBitmap(Vcl::Graphics::TGraphic* AGraphic, bool &ANeedDestroy);
	double __fastcall GetPageHeight(void);
	double __fastcall GetPageWidth(void);
	TdxPSPDFPatternList* __fastcall GetPatternList(void);
	void __fastcall SetCoordsConversionFactor(float AValue);
	void __fastcall SetFontColor(System::Uitypes::TColor AValue);
	
protected:
	virtual TdxPSPDFStreamType __fastcall GetContentStreamType(void);
	void __fastcall SelectFonT(TdxPSPDFCustomFont* AFont);
	virtual void __fastcall WriteContentStream(TdxPSPDFWriter* AWriter);
	void __fastcall RestoreGraphicState(void);
	void __fastcall SaveGraphicState(void);
	__property System::Classes::TMemoryStream* ContentStream = {read=FContentStream};
	__property System::Uitypes::TColor ForeColor = {read=FForeColor, nodefault};
	
public:
	__fastcall virtual TdxPSPDFPageContent(TdxPSPDFPage* APage);
	__fastcall virtual ~TdxPSPDFPageContent(void);
	void __fastcall BeginPaint(HRGN AClipRegion = (HRGN)(0ULL))/* overload */;
	void __fastcall BeginPaint(const System::Types::TPoint AWindowOrg, HRGN AClipRegion)/* overload */;
	void __fastcall EndPaint(void);
	void __fastcall AdjustFontSize(const System::WideString AText, const double ATextWidth);
	void __fastcall DrawEllipseFrame(const System::Types::TRect &R, System::Uitypes::TColor AColor, int AThickness);
	void __fastcall DrawFrame(const System::Types::TRect &R, int ABorderWidth, System::Uitypes::TColor ABorderColor, Cxgraphics::TcxBorders ABorders)/* overload */;
	void __fastcall DrawFrame(const System::Types::TRect &R, int ABorderWidth, System::Uitypes::TColor ATopLeftBorderColor, System::Uitypes::TColor ARightBottomBorderColor, Cxgraphics::TcxBorders ABorders)/* overload */;
	void __fastcall DrawGraphic(const System::Types::TRect &R, Vcl::Graphics::TGraphic* AGraphic);
	void __fastcall DrawRoundFrame(const System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor AColor, int AThickness);
	void __fastcall DrawText(System::Types::TRect &ARect, const System::WideString AText, Cxgraphics::TcxRotationAngle ADirection = (Cxgraphics::TcxRotationAngle)(0x0), double ACharsSpacing = 0.000000E+00, double AWordSpacing = 0.000000E+00);
	void __fastcall Fill(void);
	void __fastcall FillPolygon(System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ABackgroundColor = (System::Uitypes::TColor)(0x1fffffff), int AFillMode = 0x1);
	void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall FillRectByBrush(const System::Types::TRect &R, System::Uitypes::TColor AColor, Vcl::Graphics::TBrushStyle AStyle = (Vcl::Graphics::TBrushStyle)(0x0));
	void __fastcall FillRectByGraphic(const System::Types::TRect &R, int AWidth, int AHeight, Vcl::Graphics::TGraphic* AGraphic);
	void __fastcall FillRectByPattern(const System::Types::TRect &R, TdxPSPDFCustomPattern* APattern);
	void __fastcall LineTo(const System::Types::TPoint P)/* overload */;
	void __fastcall LineTo(double X, double Y)/* overload */;
	void __fastcall MoveTo(const System::Types::TPoint P)/* overload */;
	void __fastcall MoveTo(double X, double Y)/* overload */;
	void __fastcall Pie(const System::Types::TRect &R, const System::Types::TPoint APoint1, const System::Types::TPoint APoint2, System::Uitypes::TColor AColor);
	void __fastcall Polygon(System::Types::TPoint const *APoints, const int APoints_Size, int ALineWidth, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ABackgroundColor = (System::Uitypes::TColor)(0x1fffffff), int AFillMode = 0x1);
	void __fastcall Polyline(System::Types::TPoint const *APoints, const int APoints_Size, int ALineWidth, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall Clip(TdxPSPDFPageContentClipMode AClipMode = (TdxPSPDFPageContentClipMode)(0x0));
	void __fastcall ModifyWorldTransform(const tagXFORM &ATransform);
	void __fastcall SelectBackColor(System::Uitypes::TColor AColor);
	void __fastcall SelectClipRect(const System::Types::TRect &R);
	void __fastcall SelectClipRegion(HRGN ARegion);
	void __fastcall SelectForeColor(System::Uitypes::TColor AColor);
	void __fastcall SelectLineWidth(const double ALineWidth);
	virtual double __fastcall AbsoluteTextWidth(const System::WideString AText);
	virtual double __fastcall TextWidth(const System::WideString AText);
	void __fastcall TextOut(const System::WideString AText, const double X, const double Y, const double ACharsSpacing, const double AWordSpacing);
	void __fastcall WriteCommand(const System::UnicodeString S, bool ANewLine = true);
	void __fastcall WriteCurveTo(double X1, double Y1, double X2, double Y2, double X3, double Y3);
	void __fastcall WriteEllipse(const System::Types::TRect &R)/* overload */;
	void __fastcall WriteEllipse(const double X, const double Y, const double W, const double H)/* overload */;
	void __fastcall WritePie(const System::Types::TRect &R, const System::Types::TPoint P1, const System::Types::TPoint P2)/* overload */;
	void __fastcall WritePie(const double X1, const double Y1, const double X2, const double Y2, const double X3, const double Y3, const double X4, const double Y4)/* overload */;
	void __fastcall WritePoints(System::Types::TPoint const *APoints, const int APoints_Size);
	void __fastcall WriteRectangle(const System::Types::TRect &R);
	void __fastcall WriteRoundRect(const System::Types::TRect &R, const double AEllipseWidth, const double AEllipseHeight);
	void __fastcall WriteText(const System::WideString AText);
	void __fastcall WriteTextOffset(const double X, const double Y);
	__property float CoordsConversionFactor = {read=FCoordsConversionFactor, write=SetCoordsConversionFactor};
	__property TdxPSPDFCustomFont* Font = {read=FFont, write=FFont};
	__property System::Uitypes::TColor FontColor = {read=FFontColor, write=SetFontColor, nodefault};
	__property double FontSize = {read=FFontSize, write=FFontSize};
	__property double PageHeight = {read=GetPageHeight};
	__property double PageWidth = {read=GetPageWidth};
	__property TdxPSPDFPage* Parent = {read=FParent};
	__property TdxPSPDFPatternList* PatternList = {read=GetPatternList};
};


class DELPHICLASS TdxPSPDFPageList;
class DELPHICLASS TdxPSPDFResources;
class PASCALIMPLEMENTATION TdxPSPDFPage : public TdxPSPDFObject
{
	typedef TdxPSPDFObject inherited;
	
private:
	TdxPSPDFPageContent* FContent;
	int FPageHeight;
	int FPageWidth;
	TdxPSPDFPageList* FParent;
	System::Types::TRect __fastcall GetPageBounds(void);
	TdxPSPDFResources* __fastcall GetPageResources(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetType();
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	
public:
	__fastcall TdxPSPDFPage(TdxPSPDFPageList* AParent);
	__fastcall virtual ~TdxPSPDFPage(void);
	virtual void __fastcall PopulateExportList(TdxPSPDFObjectList* AList);
	__property TdxPSPDFPageContent* Content = {read=FContent};
	__property System::Types::TRect PageBounds = {read=GetPageBounds};
	__property int PageHeight = {read=FPageHeight, write=FPageHeight, nodefault};
	__property TdxPSPDFResources* PageResources = {read=GetPageResources};
	__property int PageWidth = {read=FPageWidth, write=FPageWidth, nodefault};
	__property TdxPSPDFPageList* Parent = {read=FParent};
};


class PASCALIMPLEMENTATION TdxPSPDFCustomPattern : public TdxPSPDFObject
{
	typedef TdxPSPDFObject inherited;
	
private:
	TdxPSPDFPatternList* FOwner;
	double FPatternHeight;
	double FPatternWidth;
	System::UnicodeString __fastcall GetName(void);
	int __fastcall GetPatternIndex(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetType();
	virtual System::UnicodeString __fastcall GetContentData(void);
	virtual TdxPSPDFStreamType __fastcall GetContentStreamType(void);
	virtual void __fastcall WriteContentStream(TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	virtual void __fastcall WritePatternResources(TdxPSPDFWriter* AWriter);
	
public:
	__fastcall TdxPSPDFCustomPattern(TdxPSPDFPatternList* AOwner, double APatternWidth, double APatternHeight);
	virtual bool __fastcall Compare(TdxPSPDFCustomPattern* APattern);
	__property System::UnicodeString ContentData = {read=GetContentData};
	__property System::UnicodeString Name = {read=GetName};
	__property TdxPSPDFPatternList* Owner = {read=FOwner};
	__property double PatternHeight = {read=FPatternHeight};
	__property int PatternIndex = {read=GetPatternIndex, nodefault};
	__property double PatternWidth = {read=FPatternWidth};
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFCustomPattern(void) { }
	
};


class DELPHICLASS TdxPSPDFBrushPattern;
class PASCALIMPLEMENTATION TdxPSPDFBrushPattern : public TdxPSPDFCustomPattern
{
	typedef TdxPSPDFCustomPattern inherited;
	
private:
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TBrushStyle FStyle;
	
public:
	virtual System::UnicodeString __fastcall GetContentData(void);
	__fastcall TdxPSPDFBrushPattern(TdxPSPDFPatternList* AOwner, Vcl::Graphics::TBrushStyle AStyle, System::Uitypes::TColor AColor);
	virtual bool __fastcall Compare(TdxPSPDFCustomPattern* APattern);
	__property System::Uitypes::TColor Color = {read=FColor, nodefault};
	__property Vcl::Graphics::TBrushStyle Style = {read=FStyle, nodefault};
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFBrushPattern(void) { }
	
};


class DELPHICLASS TdxPSPDFImagePattern;
class DELPHICLASS TdxPSPDFImage;
class PASCALIMPLEMENTATION TdxPSPDFImagePattern : public TdxPSPDFCustomPattern
{
	typedef TdxPSPDFCustomPattern inherited;
	
private:
	int FImageIndex;
	TdxPSPDFImage* __fastcall GetImage(void);
	
protected:
	virtual System::UnicodeString __fastcall GetContentData(void);
	virtual void __fastcall WritePatternResources(TdxPSPDFWriter* AWriter);
	
public:
	__fastcall TdxPSPDFImagePattern(TdxPSPDFPatternList* AOwner, double APatternWidth, double APatternHeight, int AImageIndex);
	virtual bool __fastcall Compare(TdxPSPDFCustomPattern* APattern);
	__property TdxPSPDFImage* Image = {read=GetImage};
	__property int ImageIndex = {read=FImageIndex, nodefault};
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFImagePattern(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSPDFPatternList : public TdxPSPDFObjectList
{
	typedef TdxPSPDFObjectList inherited;
	
public:
	TdxPSPDFCustomPattern* operator[](int Index) { return Items[Index]; }
	
private:
	TdxPSPDFResources* FResources;
	HIDESBASE TdxPSPDFCustomPattern* __fastcall GetItem(int Index);
	
public:
	__fastcall virtual TdxPSPDFPatternList(TdxPSPDFResources* AResources);
	TdxPSPDFCustomPattern* __fastcall AddPattern(Vcl::Graphics::TBrushStyle ABrushStyle, System::Uitypes::TColor AColor)/* overload */;
	TdxPSPDFCustomPattern* __fastcall AddPattern(int AImageIndex, double APatternWidth, double APatternHeight)/* overload */;
	TdxPSPDFCustomPattern* __fastcall AddPattern(TdxPSPDFCustomPattern* APattern)/* overload */;
	virtual int __fastcall FindPattern(TdxPSPDFCustomPattern* APattern);
	__property TdxPSPDFCustomPattern* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxPSPDFResources* Resources = {read=FResources};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxPSPDFPatternList(void) { }
	
};


class DELPHICLASS TdxPSPDFCatalog;
class PASCALIMPLEMENTATION TdxPSPDFPageList : public TdxPSPDFObject
{
	typedef TdxPSPDFObject inherited;
	
private:
	TdxPSPDFCatalog* FCatalog;
	TdxPSPDFObjectList* FList;
	TdxPSPDFPage* __fastcall GetPage(int Index);
	int __fastcall GetPageCount(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetType();
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFPageList(TdxPSPDFCatalog* ACatalog);
	__fastcall virtual ~TdxPSPDFPageList(void);
	TdxPSPDFPage* __fastcall AddPage(void);
	void __fastcall Clear(void);
	virtual void __fastcall PopulateExportList(TdxPSPDFObjectList* AList);
	__property TdxPSPDFCatalog* Catalog = {read=FCatalog};
	__property TdxPSPDFPage* Page[int Index] = {read=GetPage};
	__property int PageCount = {read=GetPageCount, nodefault};
};


class DELPHICLASS TdxPSPDFFontList;
class DELPHICLASS TdxPSPDFImageList;
class PASCALIMPLEMENTATION TdxPSPDFResources : public TdxPSPDFCustomObject
{
	typedef TdxPSPDFCustomObject inherited;
	
private:
	TdxPSPDFCatalog* FCatalog;
	TdxPSPDFFontList* FFontList;
	TdxPSPDFImageList* FImageList;
	TdxPSPDFPatternList* FPatterns;
	
protected:
	System::UnicodeString __fastcall GetUsedFontsLinks(TdxPSPDFWriter* AWriter);
	System::UnicodeString __fastcall GetUsedImageLinks(TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	void __fastcall WritePatternsHeader(TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFResources(TdxPSPDFCatalog* ACatalog);
	__fastcall virtual ~TdxPSPDFResources(void);
	int __fastcall AddBitmap(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall Clear(void);
	virtual void __fastcall PopulateExportList(TdxPSPDFObjectList* AList);
	__property TdxPSPDFCatalog* Catalog = {read=FCatalog};
	__property TdxPSPDFFontList* FontList = {read=FFontList};
	__property TdxPSPDFImageList* ImageList = {read=FImageList};
	__property TdxPSPDFPatternList* Patterns = {read=FPatterns};
};


class DELPHICLASS TdxPSPDFFile;
class PASCALIMPLEMENTATION TdxPSPDFCatalog : public TdxPSPDFObject
{
	typedef TdxPSPDFObject inherited;
	
private:
	TdxPSPDFPageList* FPageList;
	TdxPSPDFFile* FParent;
	TdxPSPDFResources* FResources;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetType();
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFCatalog(TdxPSPDFFile* AParent);
	__fastcall virtual ~TdxPSPDFCatalog(void);
	void __fastcall Clear(void);
	virtual void __fastcall PopulateExportList(TdxPSPDFObjectList* AList);
	__property TdxPSPDFPageList* PageList = {read=FPageList};
	__property TdxPSPDFFile* Parent = {read=FParent};
	__property TdxPSPDFResources* Resources = {read=FResources};
};


class PASCALIMPLEMENTATION TdxPSPDFCustomFont : public TdxPSPDFObject
{
	typedef TdxPSPDFObject inherited;
	
private:
	int FCharset;
	bool FEmbed;
	System::UnicodeString FFamilyName;
	System::UnicodeString FName;
	TdxPSPDFFontList* FOwner;
	System::Uitypes::TFontStyles FStyle;
	bool FUsed;
	int __fastcall GetCodePage(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetType();
	int __fastcall GetFontCharset(Vcl::Graphics::TFont* AFont);
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	__property bool Used = {read=FUsed, write=FUsed, nodefault};
	
public:
	__fastcall virtual TdxPSPDFCustomFont(TdxPSPDFFontList* AOwner, bool AEmbed, Vcl::Graphics::TFont* AFont);
	virtual bool __fastcall CanEncodeText(const System::WideString S) = 0 ;
	virtual bool __fastcall Compare(Vcl::Graphics::TFont* AFont);
	virtual Vcl::Graphics::TFont* __fastcall CreateFont(void);
	virtual System::UnicodeString __fastcall EncodeFontName(void);
	virtual System::AnsiString __fastcall EncodeText(const System::WideString S) = 0 ;
	virtual int __fastcall TextWidth(const System::WideString S) = 0 ;
	__property int Charset = {read=FCharset, nodefault};
	__property int CodePage = {read=GetCodePage, nodefault};
	__property bool Embed = {read=FEmbed, nodefault};
	__property System::UnicodeString FamilyName = {read=FFamilyName};
	__property System::UnicodeString Name = {read=FName};
	__property TdxPSPDFFontList* Owner = {read=FOwner};
	__property System::Uitypes::TFontStyles Style = {read=FStyle, nodefault};
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFCustomFont(void) { }
	
};


typedef System::TMetaClass* TdxPSPDFCustomFontClass;

class PASCALIMPLEMENTATION TdxPSPDFFontList : public TdxPSPDFObjectList
{
	typedef TdxPSPDFObjectList inherited;
	
public:
	TdxPSPDFCustomFont* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxPSPDFCustomFont* __fastcall GetItem(int Index);
	
public:
	HIDESBASE int __fastcall Add(Vcl::Graphics::TFont* AFont, bool ACanUseCID, bool AEmbedFont);
	int __fastcall FindFont(Vcl::Graphics::TFont* AFont);
	void __fastcall RemoveUnusedFonts(void);
	__property TdxPSPDFCustomFont* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxPSPDFFontList(bool AOwnObjects) : TdxPSPDFObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxPSPDFFontList(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSPDFLength : public TdxPSPDFCustomObject
{
	typedef TdxPSPDFCustomObject inherited;
	
private:
	int FLength;
	
public:
	virtual void __fastcall SaveTo(TdxPSPDFWriter* AWriter);
	__property int Length = {read=FLength, write=FLength, nodefault};
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFLength(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSPDFLength(void) : TdxPSPDFCustomObject() { }
	
};


class PASCALIMPLEMENTATION TdxPSPDFImage : public TdxPSPDFObject
{
	typedef TdxPSPDFObject inherited;
	
private:
	Vcl::Graphics::TBitmap* FBitmap;
	TdxPSPDFImageList* FOwner;
	int __fastcall GetImageIndex(void);
	System::UnicodeString __fastcall GetName(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetSubType();
	__classmethod virtual System::UnicodeString __fastcall GetType();
	virtual TdxPSPDFStreamType __fastcall GetContentStreamType(void);
	virtual void __fastcall WriteContentStream(TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFImage(TdxPSPDFImageList* AOwner, Vcl::Graphics::TBitmap* ABitmap);
	__fastcall virtual ~TdxPSPDFImage(void);
	bool __fastcall Compare(Vcl::Graphics::TBitmap* ABitmap);
	__property Vcl::Graphics::TBitmap* Bitmap = {read=FBitmap};
	__property int ImageIndex = {read=GetImageIndex, nodefault};
	__property System::UnicodeString Name = {read=GetName};
	__property TdxPSPDFImageList* Owner = {read=FOwner};
};


class PASCALIMPLEMENTATION TdxPSPDFImageList : public TdxPSPDFObjectList
{
	typedef TdxPSPDFObjectList inherited;
	
private:
	HIDESBASE TdxPSPDFImage* __fastcall GetItem(int Index);
	
public:
	int __fastcall AddBitmap(Vcl::Graphics::TBitmap* ABitmap);
	int __fastcall FindBitmap(Vcl::Graphics::TBitmap* ABitmap);
	__property TdxPSPDFImage* Items[int Index] = {read=GetItem};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxPSPDFImageList(bool AOwnObjects) : TdxPSPDFObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxPSPDFImageList(void) { }
	
};


enum TdxPSPDFDocumentAction : unsigned char { pdaPrint, pdaContentCopy, pdaContentEdit, pdaComment, pdaPrintHighResolution, pdaDocumentAssemble };

typedef System::Set<TdxPSPDFDocumentAction, TdxPSPDFDocumentAction::pdaPrint, TdxPSPDFDocumentAction::pdaDocumentAssemble>  TdxPSPDFDocumentActions;

typedef System::StaticArray<System::Byte, 5> TdxPSPDFEncrypt40BitKey;

typedef System::StaticArray<System::Byte, 16> TdxPSPDFEncrypt128BitKey;

enum TdxPSPDFEncryptKeyLength : unsigned char { pekl40, pekl128 };

class DELPHICLASS TdxPSPDFSecurityOptions;
class PASCALIMPLEMENTATION TdxPSPDFSecurityOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxPSPDFDocumentActions FAllowActions;
	bool FEnabled;
	TdxPSPDFEncryptKeyLength FKeyLength;
	System::UnicodeString FOwnerPassword;
	System::UnicodeString FUserPassword;
	bool __fastcall GetIsAllowActionsStored(void);
	
public:
	__fastcall virtual TdxPSPDFSecurityOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxPSPDFDocumentActions AllowActions = {read=FAllowActions, write=FAllowActions, stored=GetIsAllowActionsStored, nodefault};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=0};
	__property TdxPSPDFEncryptKeyLength KeyLength = {read=FKeyLength, write=FKeyLength, default=1};
	__property System::UnicodeString OwnerPassword = {read=FOwnerPassword, write=FOwnerPassword};
	__property System::UnicodeString UserPassword = {read=FUserPassword, write=FUserPassword};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSPDFSecurityOptions(void) { }
	
};


class DELPHICLASS TdxPSPDFEncryptCustomInfo;
class PASCALIMPLEMENTATION TdxPSPDFEncryptCustomInfo : public TdxPSPDFCustomObject
{
	typedef TdxPSPDFCustomObject inherited;
	
private:
	TdxPSPDFEncryptCustomHelper* FEncryptHelper;
	
protected:
	virtual void __fastcall WriteHeader(TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFEncryptCustomInfo(TdxPSPDFEncryptCustomHelper* AEncryptHelper);
	__property TdxPSPDFEncryptCustomHelper* EncryptHelper = {read=FEncryptHelper};
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFEncryptCustomInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSPDFEncryptCustomHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FEnabled;
	int FEncryptionFlags;
	System::AnsiString FFileID;
	TdxPSPDFEncrypt128BitKey FFileKey;
	TdxPSPDFEncryptCustomInfo* FInfo;
	System::AnsiString FOwnerKey;
	System::AnsiString FUserKey;
	
protected:
	virtual int __fastcall CalculateEncryptionFlags(TdxPSPDFDocumentActions AAllowActions) = 0 ;
	virtual System::AnsiString __fastcall CalculateOwnerKey(TdxPSPDFSecurityOptions* AOptions) = 0 ;
	virtual System::AnsiString __fastcall CalculateUserKey(TdxPSPDFSecurityOptions* AOptions) = 0 ;
	virtual TdxPSPDFEncryptCustomInfo* __fastcall CreateEncryptInfo(void) = 0 ;
	virtual void __fastcall CalculateFileKey(void);
	virtual void __fastcall CalculateKey(TdxPSPDFSecurityOptions* AOptions) = 0 ;
	void __fastcall CalculateKeyMD5(TdxPSPDFSecurityOptions* AOptions, /* out */ System::Byte *ADigest);
	
public:
	__fastcall virtual TdxPSPDFEncryptCustomHelper(TdxPSPDFSecurityOptions* AOptions);
	__fastcall virtual ~TdxPSPDFEncryptCustomHelper(void);
	virtual void __fastcall EncryptBuffer(System::Sysutils::PByteArray ABuffer, int ABufferSize, int AObjectIndex) = 0 ;
	void __fastcall EncryptStream(System::Classes::TMemoryStream* AStream, int AObjectIndex);
	virtual void __fastcall PopulateExportList(TdxPSPDFObjectList* AList);
	__property bool Enabled = {read=FEnabled, nodefault};
	__property int EncryptionFlags = {read=FEncryptionFlags, nodefault};
	__property System::AnsiString FileID = {read=FFileID};
	__property System::AnsiString OwnerKey = {read=FOwnerKey};
	__property System::AnsiString UserKey = {read=FUserKey};
};


typedef System::TMetaClass* TdxPSPDFEncryptCustomHelperClass;

class PASCALIMPLEMENTATION TdxPSPDFFile : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxPSPDFCatalog* FCatalog;
	bool FCompressStreams;
	TdxPSPDFDocumentInfo* FDocumentInfo;
	bool FEmbedFonts;
	int FJPEGQuality;
	TdxPSPDFSecurityOptions* FSecurityOptions;
	bool FUseCIDFonts;
	bool FUseJPEGCompression;
	TdxPSPDFFontList* __fastcall GetFontList(void);
	void __fastcall SetJPEGQuality(int AValue);
	void __fastcall SetSecurityOptions(TdxPSPDFSecurityOptions* AValue);
	
protected:
	virtual TdxPSPDFEncryptCustomHelper* __fastcall CreateEncryptHelper(void);
	virtual TdxPSPDFObjectList* __fastcall CreateExportList(void);
	virtual TdxPSPDFWriter* __fastcall CreateWriter(System::Classes::TStream* AOutStream, TdxPSPDFEncryptCustomHelper* AEncryptHelper);
	virtual TdxPSPDFCustomFontClass __fastcall GetFontClass(void);
	virtual void __fastcall CalculateObjectsIndexes(TdxPSPDFObjectList* AList, TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFFile(void);
	__fastcall virtual ~TdxPSPDFFile(void);
	TdxPSPDFCustomFont* __fastcall AddFont(Vcl::Graphics::TFont* AFont);
	TdxPSPDFPage* __fastcall AddPage(void);
	void __fastcall Reset(void);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property TdxPSPDFCatalog* Catalog = {read=FCatalog};
	__property bool CompressStreams = {read=FCompressStreams, write=FCompressStreams, nodefault};
	__property TdxPSPDFDocumentInfo* DocumentInfo = {read=FDocumentInfo};
	__property bool EmbedFonts = {read=FEmbedFonts, write=FEmbedFonts, nodefault};
	__property TdxPSPDFFontList* FontList = {read=GetFontList};
	__property int JPEGQuality = {read=FJPEGQuality, write=SetJPEGQuality, nodefault};
	__property TdxPSPDFSecurityOptions* SecurityOptions = {read=FSecurityOptions, write=SetSecurityOptions};
	__property bool UseCIDFonts = {read=FUseCIDFonts, write=FUseCIDFonts, nodefault};
	__property bool UseJPEGCompression = {read=FUseJPEGCompression, write=FUseJPEGCompression, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool dxPDFCanCompositeFonts;
static const bool dxPDFCanCompressStreams = true;
static const bool dxPDFCanUseJPEGCompression = true;
#define sdxPDFExt L".pdf"
#define dxPSPDFDefaultAllowedActions (System::Set<TdxPSPDFDocumentAction, TdxPSPDFDocumentAction::pdaPrint, TdxPSPDFDocumentAction::pdaDocumentAssemble> () << TdxPSPDFDocumentAction::pdaPrint << TdxPSPDFDocumentAction::pdaContentCopy << TdxPSPDFDocumentAction::pdaContentEdit << TdxPSPDFDocumentAction::pdaComment << TdxPSPDFDocumentAction::pdaPrintHighResolution << TdxPSPDFDocumentAction::pdaDocumentAssemble )
extern PACKAGE tagXFORM __fastcall dxPDFMakeTransform(const float M11, const float M22, const float DX, const float DY);
extern PACKAGE System::UnicodeString __fastcall dxPDFEncodeFloat(double AFloat);
extern PACKAGE System::UnicodeString __fastcall dxPDFEncodeBounds(const System::Types::TRect &R, double AHeight);
extern PACKAGE System::UnicodeString __fastcall dxPDFEncodeColor(System::Uitypes::TColor AColor);
}	/* namespace Dxpspdfexportcore */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPDFEXPORTCORE)
using namespace Dxpspdfexportcore;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpspdfexportcoreHPP
