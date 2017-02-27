// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSLVLnk.pas' rev: 24.00 (Win64)

#ifndef DxpslvlnkHPP
#define DxpslvlnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Shell.ShellCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpslvlnk
{
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TListViewItemSize
{
public:
	System::Word Width;
	System::Word Height;
};


enum TdxListViewPaintOption : unsigned char { lvpoBorder, lvpoHorzLines, lvpoVertLines };

typedef System::Set<TdxListViewPaintOption, TdxListViewPaintOption::lvpoBorder, TdxListViewPaintOption::lvpoVertLines>  TdxListViewPaintOptions;

class DELPHICLASS TCustomdxNativeListViewReportLink;
class PASCALIMPLEMENTATION TCustomdxNativeListViewReportLink : public Dxpsbasegridlnk::TAbstractdxGridReportLink
{
	typedef Dxpsbasegridlnk::TAbstractdxGridReportLink inherited;
	
private:
	System::Classes::TList* FInternalItems;
	Vcl::Imglist::TCustomImageList* FLargeImages;
	TdxListViewPaintOptions FOptions;
	Vcl::Imglist::TCustomImageList* FSmallImages;
	Vcl::Imglist::TCustomImageList* FStateImages;
	System::Uitypes::TColor __fastcall GetHeaderColor(void);
	Vcl::Graphics::TFont* __fastcall GetHeaderFont(void);
	bool __fastcall GetHeaderTransparent(void);
	bool __fastcall GetIncludeHeaders(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	Dxpscore::TAbstractdxReportCellData* __fastcall GetInternalItem(int Index);
	int __fastcall GetInternalItemCount(void);
	TdxListViewPaintOptions __fastcall GetOptions(void);
	void __fastcall SetHeaderColor(System::Uitypes::TColor Value);
	void __fastcall SetHeaderFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetHeaderTransparent(bool Value);
	void __fastcall SetIncludeHeaders(bool Value);
	void __fastcall SetOptions(TdxListViewPaintOptions Value);
	
protected:
	int FColumnCount;
	System::Classes::TList* FColumnIndexes;
	int FColumnWidth;
	int FHeaderHeight;
	bool FInternalItemsCreating;
	int FItemSpaceHorz;
	int FItemSpaceVert;
	int FRowCount;
	int FRowHeight;
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual void __fastcall AssignData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual bool __fastcall CanCalculateColumnAutoWidths(void);
	virtual Dxpscore::TAbstractdxReportCellData* __fastcall CreateDataItem(Dxpscore::TdxReportCell* AParent, int ACol, int ARow, const System::Types::TRect &ABounds);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataItemClass(int ACol, int ARow = 0x0);
	virtual int __fastcall GetActualColIndex(int ACol);
	virtual System::Uitypes::TColor __fastcall GetCellColor(int ACol, int ARow);
	virtual int __fastcall GetCellFontIndex(int ACol, int ARow);
	virtual int __fastcall GetCellImageIndex(int ACol, int ARow);
	virtual Dxpscore::TdxImageLayout __fastcall GetCellImageLayout(int ACol, int ARow);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetCellImageList(int ACol, int ARow);
	virtual bool __fastcall GetCellMultiline(int ACol, int ARow);
	virtual Dxpscore::TdxCellSides __fastcall GetCellSides(int ACol, int ARow);
	virtual System::UnicodeString __fastcall GetCellText(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetCellTextAlignX(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetCellTextAlignY(int ACol, int ARow);
	virtual int __fastcall GetColCount(void);
	virtual Dxpscore::TdxCellSortOrder __fastcall GetColSortOrder(int ACol);
	virtual int __fastcall GetFixedRowCount(void);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall GetSelectedColCount(void);
	virtual int __fastcall GetSelectedRowCount(void);
	virtual int __fastcall GetSourceColWidth(int ACol);
	virtual int __fastcall GetSourceRowHeight(int ARow);
	virtual bool __fastcall HasColumnHeaderImage(int ACol);
	virtual bool __fastcall HasSelection(void);
	virtual bool __fastcall HasSelectionInRow(int ARow);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawFixedHorzLines(void);
	virtual bool __fastcall IsDrawFixedVertLines(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual bool __fastcall IsDrawVertLines(void);
	virtual bool __fastcall IsProcessedCol(int ACol);
	virtual bool __fastcall IsSelectedCell(int ACol, int ARow);
	virtual bool __fastcall IsSelectedRow(int ARow);
	virtual void __fastcall SetDrawMode(Dxpsbasegridlnk::TdxGridDrawMode Value);
	virtual void __fastcall PrepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall UnprepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	NativeUInt __fastcall GetNativeHandle(void);
	void __fastcall SetNativeHandle(NativeUInt Value);
	bool __fastcall LV_AreCheckBoxes(void);
	bool __fastcall LV_AreColumnHeadersClickable(void);
	bool __fastcall LV_AreGridLines(void);
	int __fastcall LV_GetColumnCount(void);
	int __fastcall LV_GetColumnHeaderImageIndex(int ACol);
	Dxpscore::TdxImageLayout __fastcall LV_GetColumnHeaderImageLayout(int ACol);
	Dxpscore::TdxCellSortOrder __fastcall LV_GetColumnHeaderSortOrder(int ACol);
	System::UnicodeString __fastcall LV_GetColumnHeaderText(int ACol);
	Cxdrawtextutils::TcxTextAlignX __fastcall LV_GetColumnHeaderTextAlignX(int ACol);
	int __fastcall LV_GetColumnWidth(int ACol);
	int __fastcall LV_GetHeaderHeight(void);
	NativeUInt __fastcall LV_GetHeaderWindow(void);
	Vcl::Comctrls::TIconArrangement __fastcall LV_GetIconArrangement(void);
	bool __fastcall LV_GetIsItemChecked(int AIndex);
	bool __fastcall LV_GetIsItemSelected(int AIndex);
	int __fastcall LV_GetItemCount(void);
	TListViewItemSize __fastcall LV_GetItemSpacing(void);
	int __fastcall LV_GetItemImageIndex(int ACol, int ARow);
	int __fastcall LV_GetItemStateIndex(int ACol, int ARow);
	System::UnicodeString __fastcall LV_GetItemText(int ACol, int ARow);
	int __fastcall LV_GetRowHeight(void);
	int __fastcall LV_GetSelectedCount(void);
	int __fastcall LV_GetSelectedIndex(void);
	bool __fastcall LV_HasColumnHeaderImage(int ACol);
	bool __fastcall LV_HasColumnHeaders(void);
	bool __fastcall LV_IsOwnerData(void);
	virtual NativeUInt __fastcall GetListViewHandle(void) = 0 ;
	virtual bool __fastcall GetShowColumnHeaders(void);
	virtual bool __fastcall HasSupportForInvisibledColumnHeaders(void);
	virtual void __fastcall SetListViewHandle(NativeUInt Value) = 0 ;
	virtual void __fastcall SetShowColumnHeaders(bool Value);
	virtual bool __fastcall CheckImages(void);
	virtual bool __fastcall CheckSmallImages(void);
	virtual bool __fastcall CheckStateImages(void);
	virtual void __fastcall ClearImages(void);
	virtual void __fastcall CreateImages(void);
	virtual void __fastcall DeleteImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetLargeImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetSmallImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	virtual bool __fastcall HasLargeImages(void);
	virtual bool __fastcall HasSmallImages(void);
	virtual bool __fastcall HasStateImages(void);
	void __fastcall AddExtraImage(Dxpscore::TdxReportCell* AParent, int ACol, int ARow, System::Types::TRect &R);
	virtual bool __fastcall IsExtraImageRequired(int ACol, int ARow);
	void __fastcall CalculateColumnIndexes(void);
	int __fastcall CalculateHeaderRowHeight(void);
	int __fastcall CalculateRowHeight(void);
	bool __fastcall CanHasStateImage(int ACol, int ARow);
	virtual bool __fastcall IsItemChecked(int ARow);
	virtual void __fastcall LoadAllOwnerData(void);
	void __fastcall CalculateInternalItemsViewInfo(void);
	void __fastcall CreateExtraInternalItems(Dxpscore::TdxReportCell* ATemporaryParent);
	void __fastcall CreateInternalItems(Dxpscore::TdxReportCell* ATemporaryParent);
	int __fastcall GetFlatInternalItemIndex(int ACol, int ARow);
	virtual void __fastcall InitializeInternalItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual Dxpscore::TAbstractdxReportCellData* __fastcall PlaceInternalItem(Dxpscore::TdxReportCell* AParent, int ACol, int ARow, System::Types::TRect &R);
	void __fastcall SetupInternalItemsCellSides(void);
	virtual bool __fastcall IsIconStyle(void);
	virtual bool __fastcall IsReportStyle(void);
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	__property int InternalItemCount = {read=GetInternalItemCount, nodefault};
	__property Dxpscore::TAbstractdxReportCellData* InternalItems[int Index] = {read=GetInternalItem};
	__property Vcl::Imglist::TCustomImageList* LargeImages = {read=GetLargeImages};
	__property NativeUInt ListViewHandle = {read=GetListViewHandle, write=SetListViewHandle};
	__property TdxListViewPaintOptions Options = {read=GetOptions, write=SetOptions, default=7};
	__property Vcl::Imglist::TCustomImageList* SmallImages = {read=GetSmallImages};
	__property bool ShowColumnHeaders = {read=GetShowColumnHeaders, write=SetShowColumnHeaders, default=1};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=GetStateImages};
	
public:
	__fastcall virtual TCustomdxNativeListViewReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxNativeListViewReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
	virtual void __fastcall Initialize(void);
	Vcl::Comctrls::TViewStyle __fastcall LV_GetViewStyle(void);
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property DrawMode = {write=SetDrawMode, default=0};
	__property Effects3D = {default=0};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property GridLineColor = {default=0};
	__property System::Uitypes::TColor HeaderColor = {read=GetHeaderColor, write=SetHeaderColor, default=-16777201};
	__property Vcl::Graphics::TFont* HeaderFont = {read=GetHeaderFont, write=SetHeaderFont, stored=IsFixedFontStored};
	__property HeadersOnEveryPage = {default=0};
	__property bool HeaderTransparent = {read=GetHeaderTransparent, write=SetHeaderTransparent, default=0};
	__property bool IncludeHeaders = {read=GetIncludeHeaders, write=SetIncludeHeaders, default=1};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property OnlySelected = {default=0};
	__property RowAutoHeight = {default=0};
	__property Soft3D = {default=1};
	__property Transparent = {default=1};
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


class DELPHICLASS TdxNativeListViewReportLink;
class PASCALIMPLEMENTATION TdxNativeListViewReportLink : public TCustomdxNativeListViewReportLink
{
	typedef TCustomdxNativeListViewReportLink inherited;
	
private:
	NativeUInt FListViewHandle;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual Dxpscore::TdxReportLinkDesignWindowClass __fastcall GetDesignerClass(void);
	virtual NativeUInt __fastcall GetListViewHandle(void);
	virtual void __fastcall SetListViewHandle(NativeUInt Value);
	
public:
	virtual bool __fastcall DataProviderPresent(void);
	__property ListViewHandle;
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property DrawMode = {write=SetDrawMode, default=0};
	__property Effects3D = {default=0};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property GridLineColor = {default=0};
	__property HeaderColor = {default=-16777201};
	__property HeaderFont;
	__property HeadersOnEveryPage = {default=0};
	__property HeaderTransparent = {default=0};
	__property OddColor = {default=16777215};
	__property OddFont;
	__property OnlySelected = {default=0};
	__property Options = {default=7};
	__property RowAutoHeight = {default=0};
	__property IncludeHeaders = {default=1};
	__property Soft3D = {default=1};
	__property Transparent = {default=1};
public:
	/* TCustomdxNativeListViewReportLink.Create */ inline __fastcall virtual TdxNativeListViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxNativeListViewReportLink(AOwner) { }
	/* TCustomdxNativeListViewReportLink.Destroy */ inline __fastcall virtual ~TdxNativeListViewReportLink(void) { }
	
};


typedef void __fastcall (__closure *TdxCustomDrawListViewHeaderEvent)(Dxpscore::TBasedxReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, int AHeaderIndex, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);

typedef void __fastcall (__closure *TdxCustomDrawListViewItemEvent)(Dxpscore::TBasedxReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Comctrls::TListItem* AListItem, int ASubItem, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);

struct DECLSPEC_DRECORD TdxListViewReportLinkCustomDrawInfo
{
public:
	int AttributeID;
	#pragma pack(push,1)
	union
	{
		struct 
		{
			unsigned:32;
			int HeaderIndex;
		};
		struct 
		{
			unsigned:32;
			Vcl::Comctrls::TListItem* ListItem;
			int SubItem;
		};
		
	};
	#pragma pack(pop)
};


class DELPHICLASS TCustomdxListViewReportLink;
class PASCALIMPLEMENTATION TCustomdxListViewReportLink : public TCustomdxNativeListViewReportLink
{
	typedef TCustomdxNativeListViewReportLink inherited;
	
private:
	bool FShowColumnHeaders;
	TdxCustomDrawListViewHeaderEvent FOnCustomDrawHeader;
	TdxCustomDrawListViewItemEvent FOnCustomDrawItem;
	Dxpsbasegridlnk::TdxCustomGridReportLinkInitializeItemEvent FOnInitializeHeader;
	void __fastcall SetOnCustomDrawHeader(TdxCustomDrawListViewHeaderEvent Value);
	void __fastcall SetOnCustomDrawItem(TdxCustomDrawListViewItemEvent Value);
	
protected:
	virtual void __fastcall AssignData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);
	DYNAMIC void __fastcall DoInitializeHeader(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	DYNAMIC void __fastcall DoInitializeItem(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall PrepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual NativeUInt __fastcall GetListViewHandle(void);
	virtual bool __fastcall GetShowColumnHeaders(void);
	virtual bool __fastcall HasSupportForInvisibledColumnHeaders(void);
	virtual void __fastcall InitializeInternalItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual bool __fastcall IsItemChecked(int ARow);
	virtual void __fastcall LoadAllOwnerData(void);
	virtual void __fastcall SetListViewHandle(NativeUInt Value);
	virtual void __fastcall SetShowColumnHeaders(bool Value);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetLargeImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetSmallImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	virtual Vcl::Comctrls::TCustomListView* __fastcall GetCustomListView(void);
	DYNAMIC void __fastcall DoCustomDrawHeader(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, int AHeaderIndex, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawItem(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Comctrls::TListItem* AListItem, int ASubItem, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);
	virtual void __fastcall GetCustomDrawInfo(Dxpscore::TAbstractdxReportCellData* AnItem, TdxListViewReportLinkCustomDrawInfo &ACustomDrawInfo);
	__property Vcl::Comctrls::TCustomListView* CustomListView = {read=GetCustomListView};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
	__property ShowColumnHeaders = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property TdxCustomDrawListViewHeaderEvent OnCustomDrawHeader = {read=FOnCustomDrawHeader, write=SetOnCustomDrawHeader};
	__property TdxCustomDrawListViewItemEvent OnCustomDrawItem = {read=FOnCustomDrawItem, write=SetOnCustomDrawItem};
	__property Dxpsbasegridlnk::TdxCustomGridReportLinkInitializeItemEvent OnInitializeHeader = {read=FOnInitializeHeader, write=FOnInitializeHeader};
public:
	/* TCustomdxNativeListViewReportLink.Create */ inline __fastcall virtual TCustomdxListViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxNativeListViewReportLink(AOwner) { }
	/* TCustomdxNativeListViewReportLink.Destroy */ inline __fastcall virtual ~TCustomdxListViewReportLink(void) { }
	
};


class DELPHICLASS TdxListViewReportLink;
class PASCALIMPLEMENTATION TdxListViewReportLink : public TCustomdxListViewReportLink
{
	typedef TCustomdxListViewReportLink inherited;
	
private:
	Vcl::Comctrls::TListView* __fastcall GetListView(void);
	
public:
	__property Vcl::Comctrls::TListView* ListView = {read=GetListView};
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property DrawMode = {write=SetDrawMode, default=0};
	__property Effects3D = {default=0};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property GridLineColor = {default=0};
	__property HeaderColor = {default=-16777201};
	__property HeaderFont;
	__property HeadersOnEveryPage = {default=0};
	__property HeaderTransparent = {default=0};
	__property OnlySelected = {default=0};
	__property Options = {default=7};
	__property RowAutoHeight = {default=0};
	__property IncludeHeaders = {default=1};
	__property ShowColumnHeaders = {default=1};
	__property Soft3D = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property OnCustomDrawHeader;
	__property OnCustomDrawItem;
	__property OnInitializeHeader;
	__property OnInitializeItem;
public:
	/* TCustomdxNativeListViewReportLink.Create */ inline __fastcall virtual TdxListViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxListViewReportLink(AOwner) { }
	/* TCustomdxNativeListViewReportLink.Destroy */ inline __fastcall virtual ~TdxListViewReportLink(void) { }
	
};


class DELPHICLASS TCustomdxShellListViewReportLink;
class PASCALIMPLEMENTATION TCustomdxShellListViewReportLink : public TCustomdxListViewReportLink
{
	typedef TCustomdxListViewReportLink inherited;
	
private:
	Vcl::Shell::Shellctrls::TShellListView* __fastcall GetShellListView(void);
	
protected:
	virtual bool __fastcall HasStateImages(void);
	virtual void __fastcall CreateImages(void);
	virtual void __fastcall DeleteImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetLargeImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetSmallImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	__property Vcl::Shell::Shellctrls::TShellListView* ShellListView = {read=GetShellListView};
public:
	/* TCustomdxNativeListViewReportLink.Create */ inline __fastcall virtual TCustomdxShellListViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxListViewReportLink(AOwner) { }
	/* TCustomdxNativeListViewReportLink.Destroy */ inline __fastcall virtual ~TCustomdxShellListViewReportLink(void) { }
	
};


class DELPHICLASS TdxShellListViewReportLink;
class PASCALIMPLEMENTATION TdxShellListViewReportLink : public TCustomdxShellListViewReportLink
{
	typedef TCustomdxShellListViewReportLink inherited;
	
public:
	__property ShellListView;
	
__published:
	__property AutoWidth = {default=0};
	__property Color = {default=16777215};
	__property DrawMode = {write=SetDrawMode, default=0};
	__property Effects3D = {default=0};
	__property EndEllipsis = {default=0};
	__property EvenColor = {default=16777215};
	__property EvenFont;
	__property Font;
	__property GridLineColor = {default=0};
	__property HeaderColor = {default=-16777201};
	__property HeaderFont;
	__property HeadersOnEveryPage = {default=0};
	__property HeaderTransparent = {default=0};
	__property OnlySelected = {default=0};
	__property Options = {default=7};
	__property RowAutoHeight = {default=0};
	__property IncludeHeaders = {default=1};
	__property ShowColumnHeaders = {default=1};
	__property Soft3D = {default=1};
	__property SupportedCustomDraw = {default=0};
	__property Transparent = {default=1};
	__property OnCustomDrawHeader;
	__property OnCustomDrawItem;
	__property OnInitializeHeader;
	__property OnInitializeItem;
public:
	/* TCustomdxNativeListViewReportLink.Create */ inline __fastcall virtual TdxShellListViewReportLink(System::Classes::TComponent* AOwner) : TCustomdxShellListViewReportLink(AOwner) { }
	/* TCustomdxNativeListViewReportLink.Destroy */ inline __fastcall virtual ~TdxShellListViewReportLink(void) { }
	
};


class DELPHICLASS TdxfmLVReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxfmLVReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Cxpc::TcxTabSheet* tshColor;
	Cxpc::TcxTabSheet* tshFont;
	Cxpc::TcxTabSheet* tshBehaviors;
	Vcl::Extctrls::TPanel* pnlPreview;
	Vcl::Extctrls::TPanel* pnlHint;
	Vcl::Extctrls::TImage* imgHint;
	Cxlabel::TcxLabel* lblHint;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblPreview;
	Cxlabel::TcxLabel* lblOnEveryPage;
	Vcl::Extctrls::TImage* imgGrid;
	Vcl::Extctrls::TImage* Image1;
	Cxcheckbox::TcxCheckBox* chbxShowVertLines;
	Cxcheckbox::TcxCheckBox* chbxShowHorzLines;
	Cxcheckbox::TcxCheckBox* chbxShowColumnHeaders;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxHeadersOnEveryPage;
	Cxlabel::TcxLabel* stTransparentHeaders;
	Cxlabel::TcxLabel* stTransparent;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxlabel::TcxLabel* lblDrawMode;
	Cxcheckbox::TcxCheckBox* chbxTransparentHeaders;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxtextedit::TcxTextEdit* edFont;
	Cxtextedit::TcxTextEdit* edFixedFont;
	Cxtextedit::TcxTextEdit* edEvenFont;
	Cxbuttons::TcxButton* btnHeadersFont;
	Cxbuttons::TcxButton* btnFont;
	Cxbuttons::TcxButton* btnEvenFont;
	Cxlabel::TcxLabel* lblSelection;
	Cxlabel::TcxLabel* lblMiscellaneous;
	Cxlabel::TcxLabel* lblLookAndFeel;
	Vcl::Extctrls::TImage* Image8;
	Vcl::Extctrls::TImage* Image5;
	Vcl::Extctrls::TImage* Image3;
	Cxcheckbox::TcxCheckBox* chbxUseSoft3D;
	Cxcheckbox::TcxCheckBox* chbxUse3DEffects;
	Cxcheckbox::TcxCheckBox* chbxRowAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxOnlySelected;
	Cxcheckbox::TcxCheckBox* chbxIncludeFixed;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxlabel::TcxLabel* Bevel1;
	Cxlabel::TcxLabel* lblColor;
	Cxlabel::TcxLabel* lblEvenColor;
	Cxlabel::TcxLabel* lblHeadersColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxEvenColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxHeadersColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxGridLineColor;
	Cxlabel::TcxLabel* cxLabel1;
	Cximagecombobox::TcxImageComboBox* cbxDrawMode;
	void __fastcall cbxDrawModeClick(System::TObject* Sender);
	void __fastcall chbxShowBordersClick(System::TObject* Sender);
	void __fastcall chbxRowAutoHeightClick(System::TObject* Sender);
	void __fastcall chbxTransparentClick(System::TObject* Sender);
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall btnFontClick(System::TObject* Sender);
	void __fastcall chbxHeadersOnEveryPageClick(System::TObject* Sender);
	void __fastcall chbxOnlySelectedClick(System::TObject* Sender);
	void __fastcall chbxIncludeFixedClick(System::TObject* Sender);
	void __fastcall chbxUse3DEffectsClick(System::TObject* Sender);
	void __fastcall chbxUseSoft3DClick(System::TObject* Sender);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	void __fastcall chbxShowColumnHeadersClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall chbxAutoWidthClick(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	void __fastcall stTransparentHeadersClick(System::TObject* Sender);
	
private:
	Dxextctrls::TdxPSPaintPanel* FPreviewBox;
	TCustomdxNativeListViewReportLink* __fastcall GetReportLink(void);
	void __fastcall CreateControls(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &message);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	
public:
	__fastcall virtual TdxfmLVReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__property TCustomdxNativeListViewReportLink* ReportLink = {read=GetReportLink};
public:
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TdxfmLVReportLinkDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmLVReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmLVReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxListViewAttributeIDBase = System::Int8(0x0);
static const System::Int8 dxListViewUnderfinedID = System::Int8(0x0);
static const System::Int8 dxListViewItemID = System::Int8(0x1);
static const System::Int8 dxListViewHeaderID = System::Int8(0x2);
#define dxDefaultListViewOptions (System::Set<TdxListViewPaintOption, TdxListViewPaintOption::lvpoBorder, TdxListViewPaintOption::lvpoVertLines> () << TdxListViewPaintOption::lvpoBorder << TdxListViewPaintOption::lvpoHorzLines << TdxListViewPaintOption::lvpoVertLines )
}	/* namespace Dxpslvlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSLVLNK)
using namespace Dxpslvlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpslvlnkHPP
