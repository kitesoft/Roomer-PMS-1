// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarSkin.pas' rev: 24.00 (Win64)

#ifndef DxbarskinHPP
#define DxbarskinHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarskin
{
//-- type declarations -------------------------------------------------------
enum TcxSkinRectType : unsigned char { spt1x1, spt3x1, spt1x3, spt3x3 };

enum TdxSkinRectStretchMode : unsigned char { srsmStretch, srsmTile };

class DELPHICLASS TdxSkinnedRect;
class PASCALIMPLEMENTATION TdxSkinnedRect : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TSize FCalculatedSize;
	System::Types::TRect FFixedPartSize;
	void *FGPCacheBitmap;
	void *FGPImage;
	int FID;
	int FInterpolationMode;
	System::Types::TSize FLastSize;
	System::Types::TSize FMinSize;
	System::UnicodeString FName;
	Dxskinscore::TdxSkinElementPartBounds FPartsBounds;
	System::Types::TSize FSize;
	Dxskinscore::TdxSkinElementPartBounds FSourcePartsBounds;
	TdxSkinRectStretchMode FStretchMode;
	System::Types::TRect FTextOffset;
	void __fastcall CalculatePartBounds(void);
	void __fastcall CheckCachedImage(void);
	void __fastcall CheckCalculate(int AWidth, int AHeight);
	void __fastcall SetInterpolationMode(int Value);
	void __fastcall SetStretchMode(TdxSkinRectStretchMode AValue);
	void __fastcall UpdateCacheImage(void);
	void __fastcall UpdateSizes(void);
	
protected:
	virtual void __fastcall Calculate(int AWidth, int AHeight);
	virtual void __fastcall Clear(void);
	virtual void __fastcall DefaultDraw(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DoDraw(void * AGraphics, const System::Types::TRect &R, System::Byte AAlphaValue);
	__property System::Types::TSize CalculatedSize = {read=FCalculatedSize};
	
public:
	__fastcall TdxSkinnedRect(void);
	__fastcall virtual ~TdxSkinnedRect(void);
	void __fastcall Draw(HDC DC, const System::Types::TRect &R, System::Byte AAlphaValue = (System::Byte)(0xff));
	void __fastcall DrawEx(void * AGraphics, const System::Types::TRect &R, System::Byte AAlphaValue = (System::Byte)(0xff));
	void __fastcall DrawColored(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColoration, System::Byte AAlphaValue = (System::Byte)(0xff));
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(const int AWidth, const int AHeight, bool AUseAlphaChannel = false);
	virtual System::Types::TRect __fastcall GetTextBounds(const System::Types::TRect &R);
	void __fastcall LoadFromBitmap(void * ABitmap, const System::Types::TRect &ARect, const System::Types::TRect &AFixedPartSize);
	void __fastcall LoadFromFile(const System::UnicodeString AFileName, const System::Types::TRect &AFixedPartSize)/* overload */;
	void __fastcall LoadFromFile(const System::UnicodeString AFileName, const System::Types::TRect &ARect, const System::Types::TRect &AFixedPartSize)/* overload */;
	__property int ID = {read=FID, write=FID, nodefault};
	__property int InterpolationMode = {read=FInterpolationMode, write=SetInterpolationMode, default=0};
	__property System::Types::TSize MinSize = {read=FMinSize, write=FMinSize};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property System::Types::TSize Size = {read=FSize};
	__property TdxSkinRectStretchMode StretchMode = {read=FStretchMode, write=SetStretchMode, nodefault};
	__property System::Types::TRect TextOffset = {read=FTextOffset, write=FTextOffset};
};


class DELPHICLASS TdxCustomBarSkin;
class PASCALIMPLEMENTATION TdxCustomBarSkin : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TdxSkinnedRect* operator[](int Index) { return Parts[Index]; }
	
private:
	TdxSkinnedRect* __fastcall GetPart(int Index);
	
protected:
	virtual System::UnicodeString __fastcall GetName(void) = 0 ;
	
public:
	virtual void __fastcall Clear(void);
	HIDESBASE int __fastcall Add(TdxSkinnedRect* ASkinnedRect);
	int __fastcall AddPart1x1(void * ABitmap, const System::Types::TRect &R, int AID, const System::UnicodeString AName = System::UnicodeString(), int AInterpolationMode = 0x0);
	int __fastcall AddPart1x3(void * ABitmap, const System::Types::TRect &R, int ATop, int ABottom, int AID, const System::UnicodeString AName = System::UnicodeString(), int AInterpolationMode = 0x0);
	int __fastcall AddPart3x3(void * ABitmap, const System::Types::TRect &R, const System::Types::TRect &AFixedSize, int AID, const System::UnicodeString AName = System::UnicodeString(), int AInterpolationMode = 0x0);
	TdxSkinnedRect* __fastcall PartByName(const System::UnicodeString AName);
	TdxSkinnedRect* __fastcall PartByID(const int AID);
	__property System::UnicodeString Name = {read=GetName};
	__property TdxSkinnedRect* Parts[int Index] = {read=GetPart/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxCustomBarSkin(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxCustomBarSkin(void) : System::Classes::TList() { }
	
};


typedef System::TMetaClass* TdxCustomBarSkinClass;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxbarskin */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARSKIN)
using namespace Dxbarskin;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarskinHPP
