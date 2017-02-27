// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSPainters.pas' rev: 24.00 (Win32)

#ifndef CxsspaintersHPP
#define CxsspaintersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxSSViewInfo.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSStyles.hpp>	// Pascal unit
#include <cxSSUtils.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxSSPainterWrapper.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxsspainters
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxSheetPainterClass;

typedef System::TMetaClass* TcxPageCaptionPainterClass;

class DELPHICLASS TcxPageCaptionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPageCaptionPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxsspainterwrapper::TcxCanvasWrapper* FCanvas;
	Cxssviewinfo::TcxSSBookCaptionViewInfo FViewInfo;
	
protected:
	virtual void __fastcall DrawCaptions(void);
	virtual void __fastcall DrawNavigatorBtn(void);
	__property Cxsspainterwrapper::TcxCanvasWrapper* Canvas = {read=FCanvas};
	__property Cxssviewinfo::TcxSSBookCaptionViewInfo ViewInfo = {read=FViewInfo};
	
public:
	virtual void __fastcall Paint(Cxsspainterwrapper::TcxCanvasWrapper* ACanvas, const Cxssviewinfo::TcxSSBookCaptionViewInfo &AViewInfo);
public:
	/* TObject.Create */ inline __fastcall TcxPageCaptionPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPageCaptionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSheetPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSheetPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FHideSelection;
	void *FPalette;
	Cxssviewinfo::TcxSSViewInfoData FViewInfo;
	Cxsspainterwrapper::TcxCanvasWrapper* FCanvas;
	Cxexcelconst::PcxExcelPalette __fastcall GetPalette(void);
	
protected:
	virtual void __fastcall DrawCells(void);
	virtual void __fastcall DrawHeaderBrick(int I, int J);
	virtual void __fastcall DrawSelection(void);
	__property Cxsspainterwrapper::TcxCanvasWrapper* Canvas = {read=FCanvas};
	__property Cxexcelconst::PcxExcelPalette Palette = {read=GetPalette};
	__property Cxssviewinfo::TcxSSViewInfoData ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual ~TcxSheetPainter(void);
	virtual void __fastcall Paint(Cxsspainterwrapper::TcxCanvasWrapper* ACanvas, const Cxssviewinfo::TcxSSViewInfoData &AInfoData);
	__property bool HideSelection = {read=FHideSelection, write=FHideSelection, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxSheetPainter(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxXPPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxXPPainter : public TcxSheetPainter
{
	typedef TcxSheetPainter inherited;
	
protected:
	virtual void __fastcall DrawHeaderBrick(int I, int J);
public:
	/* TcxSheetPainter.Destroy */ inline __fastcall virtual ~TcxXPPainter(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxXPPainter(void) : TcxSheetPainter() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxsspainters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSPAINTERS)
using namespace Cxsspainters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxsspaintersHPP
