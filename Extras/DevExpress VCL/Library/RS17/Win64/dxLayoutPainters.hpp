// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutPainters.pas' rev: 24.00 (Win64)

#ifndef DxlayoutpaintersHPP
#define DxlayoutpaintersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxLayoutCommon.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutpainters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxLayoutGroupStandardPainter;
class DELPHICLASS TdxLayoutGroupStandardViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroupStandardPainter : public Dxlayoutcontainer::TdxLayoutGroupPainter
{
	typedef Dxlayoutcontainer::TdxLayoutGroupPainter inherited;
	
private:
	HIDESBASE TdxLayoutGroupStandardViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void);
	virtual void __fastcall DoDrawBorders(void);
	virtual void __fastcall DrawFrame(void);
	__property TdxLayoutGroupStandardViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupStandardPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : Dxlayoutcontainer::TdxLayoutGroupPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupStandardPainter(void) { }
	
};


class DELPHICLASS TdxLayoutGroupOfficePainter;
class PASCALIMPLEMENTATION TdxLayoutGroupOfficePainter : public TdxLayoutGroupStandardPainter
{
	typedef TdxLayoutGroupStandardPainter inherited;
	
protected:
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void);
	virtual void __fastcall DrawFrame(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupOfficePainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutGroupStandardPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupOfficePainter(void) { }
	
};


class DELPHICLASS TdxLayoutGroupWebPainter;
class DELPHICLASS TdxLayoutGroupWebViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroupWebPainter : public Dxlayoutcontainer::TdxLayoutGroupPainter
{
	typedef Dxlayoutcontainer::TdxLayoutGroupPainter inherited;
	
private:
	HIDESBASE Dxlayoutlookandfeels::TdxLayoutWebLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	HIDESBASE TdxLayoutGroupWebViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoDrawBorders(void);
	virtual bool __fastcall HasCaptionBackground(void);
	virtual bool __fastcall CanDrawCaptionSeparator(void);
	virtual void __fastcall DoDrawCaptionSeparator(void);
	void __fastcall DrawCaptionSeparator(void);
	virtual void __fastcall DrawFrame(void);
	__property Dxlayoutlookandfeels::TdxLayoutWebLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
	__property TdxLayoutGroupWebViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupWebPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : Dxlayoutcontainer::TdxLayoutGroupPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupWebPainter(void) { }
	
};


class DELPHICLASS TdxLayoutGroupCaptionStandardPainter;
class DELPHICLASS TdxLayoutGroupCaptionStandardViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroupCaptionStandardPainter : public Dxlayoutcontainer::TdxLayoutGroupCaptionPainter
{
	typedef Dxlayoutcontainer::TdxLayoutGroupCaptionPainter inherited;
	
private:
	HIDESBASE TdxLayoutGroupCaptionStandardViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall DrawEnabled(void);
	virtual void __fastcall DoDrawText(void);
	virtual bool __fastcall DrawVCLThemesEnabled(void);
	__property TdxLayoutGroupCaptionStandardViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupCaptionStandardPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : Dxlayoutcontainer::TdxLayoutGroupCaptionPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionStandardPainter(void) { }
	
};


class PASCALIMPLEMENTATION TdxLayoutGroupCaptionStandardViewInfo : public Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo inherited;
	
private:
	TdxLayoutGroupStandardViewInfo* __fastcall GetItemViewInfo(void);
	
protected:
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	__property TdxLayoutGroupStandardViewInfo* ItemViewInfo = {read=GetItemViewInfo};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupCaptionStandardViewInfo(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AItemViewInfo) : Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionStandardViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxLayoutGroupStandardViewInfo : public Dxlayoutcontainer::TdxLayoutGroupViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutGroupViewInfo inherited;
	
private:
	HIDESBASE TdxLayoutGroupCaptionStandardViewInfo* __fastcall GetCaptionViewInfo(void);
	Dxlayoutlookandfeels::TdxLayoutStandardLookAndFeel* __fastcall GetStandardLookAndFeel(void);
	
protected:
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual int __fastcall GetMinVisibleHeight(void);
	virtual int __fastcall GetMinVisibleWidth(void);
	virtual int __fastcall GetButtonsViewInfoOffset(void);
	virtual int __fastcall GetCaptionViewInfoOffset(void);
	virtual System::Types::TRect __fastcall GetFrameBounds(void);
	__property int CaptionViewInfoOffset = {read=GetCaptionViewInfoOffset, nodefault};
	__property Dxlayoutlookandfeels::TdxLayoutStandardLookAndFeel* LayoutLookAndFeel = {read=GetStandardLookAndFeel};
	
public:
	__property TdxLayoutGroupCaptionStandardViewInfo* CaptionViewInfo = {read=GetCaptionViewInfo};
	__property System::Types::TRect FrameBounds = {read=GetFrameBounds};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupStandardViewInfo(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AContainerViewInfo, Dxlayoutcontainer::TdxLayoutGroupViewInfo* AParentViewInfo, Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : Dxlayoutcontainer::TdxLayoutGroupViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupStandardViewInfo(void) { }
	
};


class DELPHICLASS TdxLayoutGroupCaptionOfficeViewInfo;
class DELPHICLASS TdxLayoutGroupOfficeViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroupCaptionOfficeViewInfo : public Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo inherited;
	
private:
	HIDESBASE TdxLayoutGroupOfficeViewInfo* __fastcall GetGroupViewInfo(void);
	
protected:
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	
public:
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	__property TdxLayoutGroupOfficeViewInfo* GroupViewInfo = {read=GetGroupViewInfo};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupCaptionOfficeViewInfo(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AItemViewInfo) : Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionOfficeViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxLayoutGroupOfficeViewInfo : public TdxLayoutGroupStandardViewInfo
{
	typedef TdxLayoutGroupStandardViewInfo inherited;
	
protected:
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual int __fastcall GetCaptionViewInfoOffset(void);
	virtual System::Types::TRect __fastcall GetFrameBounds(void);
	virtual int __fastcall GetMinVisibleHeight(void);
	virtual int __fastcall GetMinVisibleWidth(void);
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupOfficeViewInfo(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AContainerViewInfo, Dxlayoutcontainer::TdxLayoutGroupViewInfo* AParentViewInfo, Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : TdxLayoutGroupStandardViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupOfficeViewInfo(void) { }
	
};


class DELPHICLASS TdxLayoutGroupCaptionWebViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroupCaptionWebViewInfo : public Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo inherited;
	
private:
	TdxLayoutGroupWebViewInfo* __fastcall GetItemViewInfo(void);
	Dxlayoutlookandfeels::TdxLayoutWebLookAndFeel* __fastcall GetWebLookAndFeel(void);
	Dxlayoutlookandfeels::TdxLayoutWebLookAndFeelGroupCaptionOptions* __fastcall GetOptionsEx(void);
	int __fastcall GetSeparatorWidth(void);
	
protected:
	virtual System::Classes::TAlignment __fastcall GetAlignHorz(void);
	virtual Dxlayoutcontainer::TdxAlignmentVert __fastcall GetAlignVert(void);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	virtual bool __fastcall IsDefaultColor(void);
	__property TdxLayoutGroupWebViewInfo* ItemViewInfo = {read=GetItemViewInfo};
	__property Dxlayoutlookandfeels::TdxLayoutWebLookAndFeel* LookAndFeel = {read=GetWebLookAndFeel};
	__property Dxlayoutlookandfeels::TdxLayoutWebLookAndFeelGroupCaptionOptions* Options = {read=GetOptionsEx};
	
public:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	__property int SeparatorWidth = {read=GetSeparatorWidth, nodefault};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupCaptionWebViewInfo(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AItemViewInfo) : Dxlayoutcontainer::TdxLayoutGroupCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionWebViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxLayoutGroupWebViewInfo : public Dxlayoutcontainer::TdxLayoutGroupViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutGroupViewInfo inherited;
	
private:
	HIDESBASE TdxLayoutGroupCaptionWebViewInfo* __fastcall GetCaptionViewInfo(void);
	Dxlayoutlookandfeels::TdxLayoutWebLookAndFeel* __fastcall GetWebLookAndFeel(void);
	HIDESBASE Dxlayoutlookandfeels::TdxLayoutWebLookAndFeelGroupOptions* __fastcall GetOptionsEx(void);
	
protected:
	virtual void __fastcall CalculateButtonsViewInfoBounds(void);
	virtual void __fastcall CalculateCaptionViewInfoBounds(void);
	virtual bool __fastcall CanDrawSpecificBackground(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual int __fastcall GetCaptionViewInfoOffset(void);
	virtual int __fastcall GetMinVisibleHeight(void);
	virtual int __fastcall GetMinVisibleWidth(void);
	virtual System::Types::TRect __fastcall GetRestSpaceBounds(void);
	virtual System::Types::TRect __fastcall GetCaptionSeparatorAreaBounds(void);
	virtual System::Types::TRect __fastcall GetCaptionSeparatorBounds(void);
	bool __fastcall HasCaptionSeparator(void);
	__property Dxlayoutlookandfeels::TdxLayoutWebLookAndFeel* LookAndFeel = {read=GetWebLookAndFeel};
	__property Dxlayoutlookandfeels::TdxLayoutWebLookAndFeelGroupOptions* Options = {read=GetOptionsEx};
	
public:
	__property System::Types::TRect CaptionSeparatorAreaBounds = {read=GetCaptionSeparatorAreaBounds};
	__property System::Types::TRect CaptionSeparatorBounds = {read=GetCaptionSeparatorBounds};
	__property TdxLayoutGroupCaptionWebViewInfo* CaptionViewInfo = {read=GetCaptionViewInfo};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupWebViewInfo(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AContainerViewInfo, Dxlayoutcontainer::TdxLayoutGroupViewInfo* AParentViewInfo, Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : Dxlayoutcontainer::TdxLayoutGroupViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupWebViewInfo(void) { }
	
};


class DELPHICLASS TdxLayoutGroupCaptionCxLookAndFeelViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroupCaptionCxLookAndFeelViewInfo : public TdxLayoutGroupCaptionStandardViewInfo
{
	typedef TdxLayoutGroupCaptionStandardViewInfo inherited;
	
private:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	
public:
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupCaptionCxLookAndFeelViewInfo(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxLayoutGroupCaptionStandardViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionCxLookAndFeelViewInfo(void) { }
	
};


class DELPHICLASS TdxLayoutGroupCxLookAndFeelViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroupCxLookAndFeelViewInfo : public TdxLayoutGroupStandardViewInfo
{
	typedef TdxLayoutGroupStandardViewInfo inherited;
	
private:
	Dxlayoutlookandfeels::TdxLayoutCxLookAndFeel* __fastcall GetCXLookAndFeel(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	HIDESBASE TdxLayoutGroupCaptionCxLookAndFeelViewInfo* __fastcall GetCaptionViewInfo(void);
	
protected:
	virtual bool __fastcall CanDrawBackground(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual System::Types::TRect __fastcall GetFrameBounds(void);
	virtual bool __fastcall IsTransparent(void);
	__property Dxlayoutlookandfeels::TdxLayoutCxLookAndFeel* LayoutLookAndFeel = {read=GetCXLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
public:
	__property TdxLayoutGroupCaptionCxLookAndFeelViewInfo* CaptionViewInfo = {read=GetCaptionViewInfo};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupCxLookAndFeelViewInfo(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AContainerViewInfo, Dxlayoutcontainer::TdxLayoutGroupViewInfo* AParentViewInfo, Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : TdxLayoutGroupStandardViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCxLookAndFeelViewInfo(void) { }
	
};


class DELPHICLASS TdxLayoutGroupCaptionCxLookAndFeelPainter;
class PASCALIMPLEMENTATION TdxLayoutGroupCaptionCxLookAndFeelPainter : public Dxlayoutcontainer::TdxLayoutGroupCaptionPainter
{
	typedef Dxlayoutcontainer::TdxLayoutGroupCaptionPainter inherited;
	
private:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
public:
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupCaptionCxLookAndFeelPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : Dxlayoutcontainer::TdxLayoutGroupCaptionPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionCxLookAndFeelPainter(void) { }
	
};


class DELPHICLASS TdxLayoutGroupCxLookAndFeelPainter;
class PASCALIMPLEMENTATION TdxLayoutGroupCxLookAndFeelPainter : public TdxLayoutGroupStandardPainter
{
	typedef TdxLayoutGroupStandardPainter inherited;
	
private:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual bool __fastcall CanDrawBackground(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void);
	virtual bool __fastcall HasCaptionBackground(void);
	virtual void __fastcall DrawFrame(void);
	
public:
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupCxLookAndFeelPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutGroupStandardPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCxLookAndFeelPainter(void) { }
	
};


class DELPHICLASS TdxLayoutItemCaptionCxLookAndFeelViewInfo;
class PASCALIMPLEMENTATION TdxLayoutItemCaptionCxLookAndFeelViewInfo : public Dxlayoutcontainer::TdxLayoutItemCaptionViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutItemCaptionViewInfo inherited;
	
private:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
public:
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutItemCaptionCxLookAndFeelViewInfo(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AItemViewInfo) : Dxlayoutcontainer::TdxLayoutItemCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutItemCaptionCxLookAndFeelViewInfo(void) { }
	
};


class DELPHICLASS TdxLayoutItemCxLookAndFeelViewInfo;
class PASCALIMPLEMENTATION TdxLayoutItemCxLookAndFeelViewInfo : public Dxlayoutcontainer::TdxLayoutItemViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutItemViewInfo inherited;
	
protected:
	virtual bool __fastcall CanDrawBackground(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutItemCxLookAndFeelViewInfo(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AContainerViewInfo, Dxlayoutcontainer::TdxLayoutGroupViewInfo* AParentViewInfo, Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : Dxlayoutcontainer::TdxLayoutItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutItemCxLookAndFeelViewInfo(void) { }
	
};


class DELPHICLASS TdxLayoutGroupSkinLookAndFeelViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroupSkinLookAndFeelViewInfo : public TdxLayoutGroupCxLookAndFeelViewInfo
{
	typedef TdxLayoutGroupCxLookAndFeelViewInfo inherited;
	
protected:
	virtual int __fastcall GetBorderWidth(Dxlayoutcommon::TdxLayoutSide ASide);
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupSkinLookAndFeelViewInfo(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AContainerViewInfo, Dxlayoutcontainer::TdxLayoutGroupViewInfo* AParentViewInfo, Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : TdxLayoutGroupCxLookAndFeelViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupSkinLookAndFeelViewInfo(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxlayoutpainters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTPAINTERS)
using namespace Dxlayoutpainters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutpaintersHPP
