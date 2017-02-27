// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSTVLnk.pas' rev: 24.00 (Win64)

#ifndef DxpstvlnkHPP
#define DxpstvlnkHPP

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
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Shell.ShellCtrls.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSRes.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpstvlnk
{
//-- type declarations -------------------------------------------------------
enum TdxTreeViewPaintOption : unsigned char { tvpoBorder, tvpoGrid, tvpoStateImages, tvpoImages, tvpoTreeLines, tvpoButtons };

typedef System::Set<TdxTreeViewPaintOption, TdxTreeViewPaintOption::tvpoBorder, TdxTreeViewPaintOption::tvpoButtons>  TdxTreeViewPaintOptions;

class DELPHICLASS TCustomdxNativeTreeViewReportLink;
class PASCALIMPLEMENTATION TCustomdxNativeTreeViewReportLink : public Dxpscore::TBasedxReportLink
{
	typedef Dxpscore::TBasedxReportLink inherited;
	
private:
	int FActualWidth;
	bool FAutoNodesExpand;
	bool FAutoWidth;
	int FExpandLevel;
	bool FExplicitTreeViewExpand;
	System::Uitypes::TColor FGridLineColor;
	Vcl::Imglist::TCustomImageList* FImages;
	bool FIsWidthAssigned;
	bool FNodeAutoHeight;
	TdxTreeViewPaintOptions FOptions;
	Vcl::Imglist::TCustomImageList* FStateImages;
	System::Uitypes::TColor FTreeLineColor;
	int FWidth;
	TdxTreeViewPaintOptions __fastcall GetOptions(void);
	int __fastcall GetWidth(void);
	bool __fastcall IsWidthStored(void);
	void __fastcall SetAutoNodesExpand(bool Value);
	void __fastcall SetAutoWidth(bool Value);
	void __fastcall SetExpandLevel(int Value);
	void __fastcall SetExplicitTreeViewExpand(bool Value);
	void __fastcall SetGridLineColor(System::Uitypes::TColor Value);
	void __fastcall SetNodeAutoHeight(bool Value);
	void __fastcall SetOptions(TdxTreeViewPaintOptions Value);
	void __fastcall SetTreeLineColor(System::Uitypes::TColor Value);
	void __fastcall SetWidth(int Value);
	void __fastcall CalcNodesHeight(void);
	bool __fastcall CanDrawImages(void);
	bool __fastcall CanDrawStateImages(void);
	Dxpscore::TdxCellSides __fastcall GetCellSides(HTREEITEM ANode);
	int __fastcall GetNodeHeight(int Index);
	bool __fastcall IsDrawBorder(void);
	bool __fastcall IsDrawGrid(void);
	bool __fastcall IsDrawNodeImages(HTREEITEM ANode);
	bool __fastcall IsDrawNodeStateImages(HTREEITEM ANode);
	bool __fastcall IsFirstNode(HTREEITEM ANode);
	bool __fastcall IsLastNode(HTREEITEM ANode);
	bool __fastcall IsValidNodeImageIndex(HTREEITEM ANode);
	bool __fastcall IsValidNodeStateIndex(HTREEITEM ANode);
	
protected:
	int FIndent;
	int FNodeHeight;
	System::Classes::TList* FNodeHeights;
	System::Classes::TList* FNodeList;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* FScreenCanvas;
	virtual void __fastcall AssignData(HTREEITEM ANode, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual void __fastcall InitializeItem(HTREEITEM ANode, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall MakeDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	virtual void __fastcall PrepareContruct(void);
	virtual void __fastcall UnprepareContruct(void);
	bool __fastcall CheckImages(void);
	bool __fastcall CheckStateImages(void);
	virtual void __fastcall ClearImages(void);
	virtual void __fastcall CreateImages(void);
	virtual void __fastcall DeleteImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	virtual bool __fastcall HasImages(void);
	virtual bool __fastcall HasStateImages(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataClass(HTREEITEM ANode);
	virtual NativeUInt __fastcall GetTreeViewHandle(void) = 0 ;
	virtual void __fastcall SetTreeViewHandle(NativeUInt Value) = 0 ;
	virtual void __fastcall DoExplicitTreeViewExpand(int ALevel = 0xffffffff);
	virtual NativeUInt __fastcall GetNativeHandle(void);
	virtual void __fastcall SetNativeHandle(NativeUInt Value);
	bool __fastcall TV_IsNodeExpanded(HTREEITEM AItem);
	bool __fastcall TV_IsNodeParentExists(HTREEITEM AItem);
	bool __fastcall TV_IsNodeFirstChild(HTREEITEM AItem);
	bool __fastcall TV_IsNodeLastChild(HTREEITEM AItem);
	bool __fastcall TV_IsShowButtons(void);
	bool __fastcall TV_IsShowLines(void);
	bool __fastcall TV_IsShowRoot(void);
	int __fastcall TV_GetNodeCount(HTREEITEM AItem);
	bool __fastcall TV_GetNodeHasChildren(HTREEITEM AItem);
	int __fastcall TV_GetNodeImageIndex(HTREEITEM AItem);
	int __fastcall TV_GetNodeLevel(HTREEITEM AItem);
	HTREEITEM __fastcall TV_GetNodeParent(HTREEITEM AItem);
	HTREEITEM __fastcall TV_GetNodeParentAtLevel(HTREEITEM AItem, int ALevel);
	int __fastcall TV_GetNodeStateIndex(HTREEITEM AItem);
	System::UnicodeString __fastcall TV_GetNodeText(HTREEITEM AItem);
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=GetStateImages};
	__property NativeUInt TreeViewHandle = {read=GetTreeViewHandle, write=SetTreeViewHandle};
	
public:
	__fastcall virtual TCustomdxNativeTreeViewReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxNativeTreeViewReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
	virtual int __fastcall DefaultWidth(void);
	virtual void __fastcall Initialize(void);
	__property bool AutoNodesExpand = {read=FAutoNodesExpand, write=SetAutoNodesExpand, default=0};
	__property bool AutoWidth = {read=FAutoWidth, write=SetAutoWidth, default=1};
	__property Color = {default=16777215};
	__property int ExpandLevel = {read=FExpandLevel, write=SetExpandLevel, default=-1};
	__property bool ExplicitTreeViewExpand = {read=FExplicitTreeViewExpand, write=SetExplicitTreeViewExpand, default=0};
	__property Font;
	__property System::Uitypes::TColor GridLineColor = {read=FGridLineColor, write=SetGridLineColor, default=0};
	__property TdxTreeViewPaintOptions Options = {read=GetOptions, write=SetOptions, default=60};
	__property bool NodeAutoHeight = {read=FNodeAutoHeight, write=SetNodeAutoHeight, default=0};
	__property ScaleFonts = {default=1};
	__property Transparent = {default=1};
	__property System::Uitypes::TColor TreeLineColor = {read=FTreeLineColor, write=SetTreeLineColor, default=8421504};
	__property int Width = {read=GetWidth, write=SetWidth, stored=IsWidthStored, nodefault};
private:
	void *__IdxPSNativeWin32ControlHandleSupport;	/* Dxpscore::IdxPSNativeWin32ControlHandleSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4B649281-A283-4CAC-98D4-08E779A7F9C8}
	operator Dxpscore::_di_IdxPSNativeWin32ControlHandleSupport()
	{
		Dxpscore::_di_IdxPSNativeWin32ControlHandleSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscore::IdxPSNativeWin32ControlHandleSupport*(void) { return (Dxpscore::IdxPSNativeWin32ControlHandleSupport*)&__IdxPSNativeWin32ControlHandleSupport; }
	#endif
	
};


class DELPHICLASS TdxNativeTreeViewReportLink;
class PASCALIMPLEMENTATION TdxNativeTreeViewReportLink : public TCustomdxNativeTreeViewReportLink
{
	typedef TCustomdxNativeTreeViewReportLink inherited;
	
private:
	NativeUInt FTreeViewHandle;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual Dxpscore::TdxReportLinkDesignWindowClass __fastcall GetDesignerClass(void);
	virtual NativeUInt __fastcall GetTreeViewHandle(void);
	virtual void __fastcall SetTreeViewHandle(NativeUInt Value);
	
public:
	virtual bool __fastcall DataProviderPresent(void);
	__property TreeViewHandle;
	
__published:
	__property AutoNodesExpand = {default=0};
	__property AutoWidth = {default=1};
	__property Color = {default=16777215};
	__property ExpandLevel = {default=-1};
	__property ExplicitTreeViewExpand = {default=0};
	__property Font;
	__property GridLineColor = {default=0};
	__property Options = {default=60};
	__property NodeAutoHeight = {default=0};
	__property ScaleFonts = {default=1};
	__property Transparent = {default=1};
	__property TreeLineColor = {default=8421504};
	__property UseVertDelimiters = {default=1};
	__property Width;
public:
	/* TCustomdxNativeTreeViewReportLink.Create */ inline __fastcall virtual TdxNativeTreeViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxNativeTreeViewReportLink(AOwner) { }
	/* TCustomdxNativeTreeViewReportLink.Destroy */ inline __fastcall virtual ~TdxNativeTreeViewReportLink(void) { }
	
};


typedef void __fastcall (__closure *TdxTVInitializeNodeEvent)(Dxpscore::TBasedxReportLink* Sender, Vcl::Comctrls::TTreeNode* ANode, Dxpscore::TdxReportCellString* AnItem);

typedef void __fastcall (__closure *TdxTVCustomDrawNodeEvent)(Dxpscore::TBasedxReportLink* Sender, Vcl::Comctrls::TTreeNode* ANode, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, System::UnicodeString &AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, bool &ADone);

class DELPHICLASS TCustomdxTreeViewReportLink;
class PASCALIMPLEMENTATION TCustomdxTreeViewReportLink : public TCustomdxNativeTreeViewReportLink
{
	typedef TCustomdxNativeTreeViewReportLink inherited;
	
private:
	bool FCustomDrawFontChanged;
	Vcl::Graphics::TFont* FSaveFont;
	bool FSupportedCustomDraw;
	TdxTVCustomDrawNodeEvent FOnCustomDrawNode;
	TdxTVInitializeNodeEvent FOnInitializeNode;
	void __fastcall SetSupportedCustomDraw(bool Value);
	void __fastcall CustomDrawFontChanged(System::TObject* Sender);
	
protected:
	virtual void __fastcall InitializeItem(HTREEITEM ANode, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	virtual Vcl::Comctrls::TCustomTreeView* __fastcall GetCustomTreeView(void);
	virtual NativeUInt __fastcall GetTreeViewHandle(void);
	virtual void __fastcall SetTreeViewHandle(NativeUInt Value);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);
	virtual void __fastcall DoCustomDrawNode(Vcl::Comctrls::TTreeNode* ANode, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, System::UnicodeString &AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, Cxdrawtextutils::TcxTextAlignX &ATextAlignX, Cxdrawtextutils::TcxTextAlignY &ATextAlignY, bool &ADone);
	DYNAMIC void __fastcall DoInitializeNode(Vcl::Comctrls::TTreeNode* ANode, Dxpscore::TAbstractdxReportCellData* AnItem);
	__property Vcl::Comctrls::TCustomTreeView* CustomTreeView = {read=GetCustomTreeView};
	__property TdxTVCustomDrawNodeEvent OnCustomDrawNode = {read=FOnCustomDrawNode, write=FOnCustomDrawNode};
	__property TdxTVInitializeNodeEvent OnInitializeNode = {read=FOnInitializeNode, write=FOnInitializeNode};
	
public:
	__fastcall virtual TCustomdxTreeViewReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxTreeViewReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
	__property bool SupportedCustomDraw = {read=FSupportedCustomDraw, write=SetSupportedCustomDraw, default=0};
};


class DELPHICLASS TdxTreeViewReportLink;
class PASCALIMPLEMENTATION TdxTreeViewReportLink : public TCustomdxTreeViewReportLink
{
	typedef TCustomdxTreeViewReportLink inherited;
	
private:
	Vcl::Comctrls::TTreeView* __fastcall GetTreeView(void);
	
public:
	__property Vcl::Comctrls::TTreeView* TreeView = {read=GetTreeView};
	
__published:
	__property AutoNodesExpand = {default=0};
	__property AutoWidth = {default=1};
	__property Color = {default=16777215};
	__property ExpandLevel = {default=-1};
	__property ExplicitTreeViewExpand = {default=0};
	__property Font;
	__property GridLineColor = {default=0};
	__property Options = {default=60};
	__property ScaleFonts = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property TreeLineColor = {default=8421504};
	__property UseVertDelimiters = {default=1};
	__property Width;
	__property OnCustomDrawNode;
	__property OnInitializeNode;
public:
	/* TCustomdxTreeViewReportLink.Create */ inline __fastcall virtual TdxTreeViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxTreeViewReportLink(AOwner) { }
	/* TCustomdxTreeViewReportLink.Destroy */ inline __fastcall virtual ~TdxTreeViewReportLink(void) { }
	
};


class DELPHICLASS TCustomdxShellTreeViewReportLink;
class PASCALIMPLEMENTATION TCustomdxShellTreeViewReportLink : public TCustomdxTreeViewReportLink
{
	typedef TCustomdxTreeViewReportLink inherited;
	
private:
	Vcl::Shell::Shellctrls::TShellTreeView* __fastcall GetShellTreeView(void);
	
protected:
	virtual void __fastcall CreateImages(void);
	virtual void __fastcall DeleteImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	virtual bool __fastcall HasStateImages(void);
	__property Vcl::Shell::Shellctrls::TShellTreeView* ShellTreeView = {read=GetShellTreeView};
public:
	/* TCustomdxTreeViewReportLink.Create */ inline __fastcall virtual TCustomdxShellTreeViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxTreeViewReportLink(AOwner) { }
	/* TCustomdxTreeViewReportLink.Destroy */ inline __fastcall virtual ~TCustomdxShellTreeViewReportLink(void) { }
	
};


class DELPHICLASS TdxShellTreeViewReportLink;
class PASCALIMPLEMENTATION TdxShellTreeViewReportLink : public TCustomdxShellTreeViewReportLink
{
	typedef TCustomdxShellTreeViewReportLink inherited;
	
public:
	__property ShellTreeView;
	
__published:
	__property AutoNodesExpand = {default=0};
	__property AutoWidth = {default=1};
	__property Color = {default=16777215};
	__property ExpandLevel = {default=-1};
	__property ExplicitTreeViewExpand = {default=0};
	__property Font;
	__property GridLineColor = {default=0};
	__property Options = {default=60};
	__property ScaleFonts = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property TreeLineColor = {default=8421504};
	__property UseVertDelimiters = {default=1};
	__property Width;
	__property OnCustomDrawNode;
	__property OnInitializeNode;
public:
	/* TCustomdxTreeViewReportLink.Create */ inline __fastcall virtual TdxShellTreeViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxShellTreeViewReportLink(AOwner) { }
	/* TCustomdxTreeViewReportLink.Destroy */ inline __fastcall virtual ~TdxShellTreeViewReportLink(void) { }
	
};


class DELPHICLASS TdxfmTVReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxfmTVReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Cxpc::TcxTabSheet* tshColors;
	Cxpc::TcxTabSheet* tshFonts;
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxgraphics::TcxImageList* ilPreview;
	Cxpc::TcxTabSheet* tshBehaviors;
	Cxlabel::TcxLabel* Bevel2;
	Cxlabel::TcxLabel* Bevel3;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxShowButtons;
	Cxcheckbox::TcxCheckBox* chbxShowGrid;
	Cxcheckbox::TcxCheckBox* chbxShowImages;
	Cxcheckbox::TcxCheckBox* chbxShowStateImages;
	Cxcheckbox::TcxCheckBox* chbxShowTreeLines;
	Vcl::Extctrls::TImage* imgGrid;
	Cxlabel::TcxLabel* lblPreview;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* stTransparent;
	Cxlabel::TcxLabel* lblTreeLinesColor;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxlabel::TcxLabel* lblColor;
	Cxlabel::TcxLabel* cxLabel1;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxcolorcombobox::TcxColorComboBox* ccbxTreeLineColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxGridLineColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxtextedit::TcxTextEdit* edFont;
	Cxbuttons::TcxButton* btnFont;
	Cxspinedit::TcxSpinEdit* seExpandLevel;
	Cxlabel::TcxLabel* lblMiscellaneous;
	Cxlabel::TcxLabel* lblExpandLevel;
	Cxlabel::TcxLabel* lblExpanding;
	Vcl::Extctrls::TImage* Image5;
	Vcl::Extctrls::TImage* Image4;
	Cxcheckbox::TcxCheckBox* chbxNodeAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxcheckbox::TcxCheckBox* chbxAutoNodesExpand;
	void __fastcall btnFontClick(System::TObject* Sender);
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall chbxAutoNodesExpandClick(System::TObject* Sender);
	void __fastcall chbxAutoWidthClick(System::TObject* Sender);
	void __fastcall chbxNodeAutoHeightClick(System::TObject* Sender);
	void __fastcall chbxShowClick(System::TObject* Sender);
	void __fastcall chbxTransparentClick(System::TObject* Sender);
	void __fastcall ExpandLevelChange(System::TObject* Sender);
	void __fastcall lblColorClick(System::TObject* Sender);
	void __fastcall lblExpandLevelClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	
private:
	Vcl::Controls::TCustomControl* FPreviewBox;
	TCustomdxNativeTreeViewReportLink* __fastcall GetReportLink(void);
	void __fastcall CreateControls(void);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	
public:
	__fastcall virtual TdxfmTVReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__property TCustomdxNativeTreeViewReportLink* ReportLink = {read=GetReportLink};
public:
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TdxfmTVReportLinkDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmTVReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmTVReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxTreeViewPaintOptions dxDefaultTreeViewPaintOptions;
}	/* namespace Dxpstvlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSTVLNK)
using namespace Dxpstvlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpstvlnkHPP
