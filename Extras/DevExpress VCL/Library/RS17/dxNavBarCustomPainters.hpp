// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarCustomPainters.pas' rev: 24.00 (Win32)

#ifndef DxnavbarcustompaintersHPP
#define DxnavbarcustompaintersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarcustompainters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarCustomImagePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomImagePainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod unsigned __fastcall GetRGBColor(System::Uitypes::TColor Value);
	__classmethod virtual void __fastcall InternalDrawImage(Vcl::Graphics::TCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, const System::Types::TRect &ARect, bool AEnabled);
	
public:
	__classmethod void __fastcall DrawImage(Vcl::Graphics::TCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, const System::Types::TRect &ARect, bool AEnabled = true);
	__classmethod bool __fastcall IsValidImage(Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomImagePainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomImagePainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomImagePainterClass;

class DELPHICLASS TdxNavBarCustomSelectionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomSelectionPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall GetColors(Dxnavbar::TdxNavBarObjectStates AState, System::Uitypes::TColor ABackColor, /* out */ System::Uitypes::TColor &AFillColor, /* out */ System::Uitypes::TColor &ATopLeftOuterColor, /* out */ System::Uitypes::TColor &ABottomRightOuterColor, /* out */ System::Uitypes::TColor &ATopLeftInnerColor, /* out */ System::Uitypes::TColor &ABottomRightInnerColor);
	__classmethod virtual void __fastcall InternalDrawSelection(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackColor, Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual bool __fastcall IsPressed(Dxnavbar::TdxNavBarObjectStates AState);
	
public:
	__classmethod void __fastcall DrawSelection(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomSelectionPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomSelectionPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomSelectionPainterClass;

class DELPHICLASS TdxNavBarUltraFlatSelectionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarUltraFlatSelectionPainter : public TdxNavBarCustomSelectionPainter
{
	typedef TdxNavBarCustomSelectionPainter inherited;
	
protected:
	__classmethod virtual void __fastcall GetColors(Dxnavbar::TdxNavBarObjectStates AState, System::Uitypes::TColor ABackColor, /* out */ System::Uitypes::TColor &AFillColor, /* out */ System::Uitypes::TColor &ATopLeftOuterColor, /* out */ System::Uitypes::TColor &ABottomRightOuterColor, /* out */ System::Uitypes::TColor &ATopLeftInnerColor, /* out */ System::Uitypes::TColor &ABottomRightInnerColor);
	__classmethod virtual bool __fastcall IsPressed(Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarUltraFlatSelectionPainter(void) : TdxNavBarCustomSelectionPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarUltraFlatSelectionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarCustomBackgroundPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomBackgroundPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	__classmethod void __fastcall InternalDrawGradientBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, bool AEraseBackground, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
	
protected:
	__classmethod void __fastcall DrawPicture(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture);
	__classmethod void __fastcall FillGradientRect(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
	__classmethod virtual void __fastcall InternalDrawBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, bool AEraseBackground, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
	
public:
	__classmethod void __fastcall DrawBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, bool AEraseBackground, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomBackgroundPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomBackgroundPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomBackgroundPainterClass;

class DELPHICLASS TdxNavBarCustomGroupBackgroundPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomGroupBackgroundPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
	
public:
	__classmethod void __fastcall DrawBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomGroupBackgroundPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomGroupBackgroundPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomGroupBackgroundPainterClass;

class DELPHICLASS TdxNavBarCustomGroupBorderPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomGroupBorderPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawBorder(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor, bool AWithCaption);
	
public:
	__classmethod void __fastcall DrawBorder(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor, bool AWithCaption);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomGroupBorderPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomGroupBorderPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomGroupBorderPainterClass;

class DELPHICLASS TdxNavBarCustomSignPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomSignPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawSign(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
	
public:
	__classmethod void __fastcall DrawSign(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomSignPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomSignPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomSignPainterClass;

class DELPHICLASS TdxNavBarCustomHintPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomHintPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawHint(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::UnicodeString AHint, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, Vcl::Graphics::TFont* AFont);
	
public:
	__classmethod void __fastcall DrawHint(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::UnicodeString AHint, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, Vcl::Graphics::TFont* AFont);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomHintPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomHintPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomHintPainterClass;

class DELPHICLASS TdxNavBarCustomButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomButtonPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
	
public:
	__classmethod void __fastcall DrawButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomButtonPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomButtonPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomButtonPainterClass;

class DELPHICLASS TdxNavBarCustomScrollButtonsPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomScrollButtonsPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawBottomButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, TdxNavBarCustomButtonPainterClass AButtonPainterClass, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual void __fastcall InternalDrawTopButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, TdxNavBarCustomButtonPainterClass AButtonPainterClass, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
	
public:
	__classmethod void __fastcall DrawBottomButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, TdxNavBarCustomButtonPainterClass AButtonPainterClass, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod void __fastcall DrawTopButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, TdxNavBarCustomButtonPainterClass AButtonPainterClass, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomScrollButtonsPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomScrollButtonsPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomScrollButtonsPainterClass;

class DELPHICLASS TdxNavBarCustomDropTargetLinkPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomDropTargetLinkPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawTargetLink(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TPoint &pt1, const System::Types::TPoint &pt2, const System::Types::TPoint &pt3, const System::Types::TPoint &pt4, const System::Types::TPoint &pt5, const System::Types::TPoint &pt6, System::Uitypes::TColor AColor);
	
public:
	__classmethod void __fastcall DrawTargetLink(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TPoint &pt1, const System::Types::TPoint &pt2, const System::Types::TPoint &pt3, const System::Types::TPoint &pt4, const System::Types::TPoint &pt5, const System::Types::TPoint &pt6, System::Uitypes::TColor AColor);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomDropTargetLinkPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomDropTargetLinkPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomDropTargetLinkPainterClass;

class DELPHICLASS TdxNavBarCustomDropTargetGroupPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarCustomDropTargetGroupPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawTargetGroup(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
	
public:
	__classmethod void __fastcall DrawTargetGroup(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomDropTargetGroupPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomDropTargetGroupPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarCustomDropTargetGroupPainterClass;

class DELPHICLASS TdxNavBarViewInfoAccess;
class PASCALIMPLEMENTATION TdxNavBarViewInfoAccess : public Dxnavbar::TdxNavBarViewInfo
{
	typedef Dxnavbar::TdxNavBarViewInfo inherited;
	
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarViewInfoAccess(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbar::TdxNavBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarViewInfoAccess(void) { }
	
};


class DELPHICLASS TdxNavBarLinkViewInfoAccess;
class PASCALIMPLEMENTATION TdxNavBarLinkViewInfoAccess : public Dxnavbar::TdxNavBarLinkViewInfo
{
	typedef Dxnavbar::TdxNavBarLinkViewInfo inherited;
	
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarLinkViewInfoAccess(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbar::TdxNavBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarLinkViewInfoAccess(void) { }
	
};


class DELPHICLASS TdxNavBarElementPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarElementPainter : public Dxnavbar::TdxNavBarPainter
{
	typedef Dxnavbar::TdxNavBarPainter inherited;
	
protected:
	virtual void __fastcall DoDrawDropTargetLinkSelection(Dxnavbar::TdxNavBarGroupViewInfo* AItemGroup, Dxnavbar::TdxNavBarLinkViewInfo* AItem1, Dxnavbar::TdxNavBarLinkViewInfo* AItem2);
	virtual void __fastcall DoDrawHint(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	__classmethod virtual TdxNavBarCustomBackgroundPainterClass __fastcall BackgroundPainterClass();
	__classmethod virtual TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual TdxNavBarCustomDropTargetGroupPainterClass __fastcall DropTargetGroupPainterClass();
	__classmethod virtual TdxNavBarCustomDropTargetLinkPainterClass __fastcall DropTargetLinkPainterClass();
	__classmethod virtual TdxNavBarCustomGroupBackgroundPainterClass __fastcall GroupBackgroundPainterClass();
	__classmethod virtual TdxNavBarCustomGroupBorderPainterClass __fastcall GroupBorderPainterClass();
	__classmethod virtual TdxNavBarCustomImagePainterClass __fastcall ImagePainterClass();
	__classmethod virtual TdxNavBarCustomScrollButtonsPainterClass __fastcall ScrollButtonsPainterClass();
	__classmethod virtual TdxNavBarCustomSelectionPainterClass __fastcall SelectionPainterClass();
	__classmethod virtual TdxNavBarCustomSignPainterClass __fastcall SignPainterClass();
	
public:
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawDropTargetGroupSelection(void);
	virtual void __fastcall DrawDropTargetLinkSelection(void);
	virtual void __fastcall DrawGroupBackground(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupBorder(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionButton(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionImage(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionSign(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupControl(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawItemImage(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawItemSelection(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawBottomScrollButton(void);
	virtual void __fastcall DrawTopScrollButton(void);
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarElementPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbar::TdxNavBarPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarElementPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbarcustompainters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARCUSTOMPAINTERS)
using namespace Dxnavbarcustompainters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarcustompaintersHPP
