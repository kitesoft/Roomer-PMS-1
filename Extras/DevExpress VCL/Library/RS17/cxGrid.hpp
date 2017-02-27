// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGrid.pas' rev: 24.00 (Win32)

#ifndef CxgridHPP
#define CxgridHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridDetailsSite.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridLayoutChange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLayoutChange : public Cxgridcustomview::TcxCustomGridViewChange
{
	typedef Cxgridcustomview::TcxCustomGridViewChange inherited;
	
public:
	virtual void __fastcall Execute(void);
	virtual bool __fastcall IsCompatibleWith(Cxgridcommon::TcxCustomGridChange* AChange);
public:
	/* TcxCustomGridViewChange.Create */ inline __fastcall virtual TcxGridLayoutChange(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridViewChange(AGridView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutChange(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridSizeChange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridSizeChange : public Cxgridcustomview::TcxCustomGridViewChange
{
	typedef Cxgridcustomview::TcxCustomGridViewChange inherited;
	
private:
	bool FKeepMaster;
	bool FUpdateGridViewOnly;
	
public:
	__fastcall virtual TcxGridSizeChange(Cxgridcustomview::TcxCustomGridView* AGridView, bool AUpdateGridViewOnly, bool AKeepMaster);
	virtual void __fastcall Execute(void);
	virtual bool __fastcall IsCompatibleWith(Cxgridcommon::TcxCustomGridChange* AChange);
	virtual bool __fastcall IsEqual(Cxgridcommon::TcxCustomGridChange* AChange);
	__property bool KeepMaster = {read=FKeepMaster, nodefault};
	__property bool UpdateGridViewOnly = {read=FUpdateGridViewOnly, write=FUpdateGridViewOnly, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridSizeChange(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridViewChange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewChange : public Cxgridcustomview::TcxCustomGridViewChange
{
	typedef Cxgridcustomview::TcxCustomGridViewChange inherited;
	
private:
	System::Types::TRect FUpdateBounds;
	Cxgraphics::TcxRegion* FUpdateRegion;
	
public:
	__fastcall virtual TcxGridViewChange(Cxgridcustomview::TcxCustomGridView* AGridView, const System::Types::TRect &AUpdateBounds)/* overload */;
	__fastcall virtual TcxGridViewChange(Cxgridcustomview::TcxCustomGridView* AGridView, Cxgraphics::TcxRegion* const AUpdateRegion)/* overload */;
	__fastcall TcxGridViewChange(Cxgridcustomview::TcxCustomGridView* AGridView)/* overload */;
	__fastcall virtual ~TcxGridViewChange(void);
	virtual void __fastcall Execute(void);
	virtual bool __fastcall IsCompatibleWith(Cxgridcommon::TcxCustomGridChange* AChange);
	virtual bool __fastcall IsEqual(Cxgridcommon::TcxCustomGridChange* AChange);
	__property System::Types::TRect UpdateBounds = {read=FUpdateBounds};
	__property Cxgraphics::TcxRegion* UpdateRegion = {read=FUpdateRegion};
};

#pragma pack(pop)

enum TcxGridNotificationKind : unsigned char { gnkFocusedViewChanged, gnkFocusedRecordChanged, gnkRecordCountChanged, gnkContextMenu, gnkCustomization, gnkKeyDown };

typedef System::Set<TcxGridNotificationKind, TcxGridNotificationKind::gnkFocusedViewChanged, TcxGridNotificationKind::gnkKeyDown>  TcxGridNotificationKinds;

class DELPHICLASS TcxCustomGridNotification;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridNotification : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual TcxGridNotificationKinds __fastcall NotificationKinds(void) = 0 ;
	virtual void __fastcall Notify(TcxGridNotificationKind AKind, System::TObject* AData, bool &AHandled) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridNotification(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridNotification(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridStructureNavigatorClass;

class DELPHICLASS TcxCustomGridStructureNavigator;
class DELPHICLASS TcxCustomGrid;
class PASCALIMPLEMENTATION TcxCustomGridStructureNavigator : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TcxCustomGrid* FGrid;
	
protected:
	HIDESBASE virtual void __fastcall Changed(void);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC bool __fastcall MayFocus(void);
	virtual System::Types::TRect __fastcall CalculateBoundsRect(void) = 0 ;
	
public:
	__fastcall virtual TcxCustomGridStructureNavigator(TcxCustomGrid* AGrid);
	virtual void __fastcall BeforeGridLoading(void);
	virtual bool __fastcall CanAddComponent(void) = 0 ;
	virtual bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent) = 0 ;
	virtual void __fastcall GetSelection(System::Classes::TList* AList) = 0 ;
	virtual bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject) = 0 ;
	virtual void __fastcall NotifyEditors(void) = 0 ;
	virtual void __fastcall SelectionChanged(System::Classes::TList* ASelection) = 0 ;
	virtual void __fastcall SelectObject(System::Classes::TPersistent* AObject, bool AClearSelection) = 0 ;
	virtual void __fastcall SelectObjects(System::Classes::TList* AObjects) = 0 ;
	virtual void __fastcall UnselectObject(System::Classes::TPersistent* AObject) = 0 ;
	__property TcxCustomGrid* Grid = {read=FGrid};
public:
	/* TcxControl.Destroy */ inline __fastcall virtual ~TcxCustomGridStructureNavigator(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridStructureNavigator(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TcxCustomGridHandler;
class DELPHICLASS TcxGridViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridHandler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomGrid* FControl;
	Cxgridcustomview::TcxCustomGridController* __fastcall GetActiveController(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveGridView(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	TcxGridViewInfo* __fastcall GetViewInfo(void);
	
protected:
	__property Cxgridcustomview::TcxCustomGridController* ActiveController = {read=GetActiveController};
	__property Cxgridcustomview::TcxCustomGridView* ActiveGridView = {read=GetActiveGridView};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TcxGridViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomGridHandler(TcxCustomGrid* AControl);
	__property TcxCustomGrid* Control = {read=FControl};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridHandler(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridDesignControllerClass;

class DELPHICLASS TcxGridDesignController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDesignController : public Cxgridcustomview::TcxCustomGridDesignController
{
	typedef Cxgridcustomview::TcxCustomGridDesignController inherited;
	
private:
	TcxCustomGrid* FControl;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	
public:
	__fastcall virtual TcxGridDesignController(TcxCustomGrid* AControl);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDesignController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridDragOpenInfoTab;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDragOpenInfoTab : public Cxgridcommon::TcxCustomGridDragOpenInfo
{
	typedef Cxgridcommon::TcxCustomGridDragOpenInfo inherited;
	
public:
	Cxgridlevel::TcxGridLevel* Level;
	__fastcall virtual TcxGridDragOpenInfoTab(Cxgridlevel::TcxGridLevel* ALevel);
	virtual bool __fastcall Equals(Cxgridcommon::TcxCustomGridDragOpenInfo* AInfo);
	virtual void __fastcall Run(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDragOpenInfoTab(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridControllerClass;

class DELPHICLASS TcxGridController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridController : public TcxCustomGridHandler
{
	typedef TcxCustomGridHandler inherited;
	
private:
	TcxGridDesignController* FDesignController;
	Cxgridcommon::TcxCustomGridDragOpenInfo* FDragOpenInfo;
	Cxclasses::TcxTimer* FDragOpenTimer;
	TcxGridDesignController* __fastcall GetDesignController(void);
	void __fastcall DragOpenTimerHandler(System::TObject* Sender);
	
protected:
	virtual TcxGridDesignControllerClass __fastcall GetDesignControllerClass(void);
	
public:
	__fastcall virtual ~TcxGridController(void);
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall FocusChanged(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall StartDrag(Vcl::Controls::TDragObject* &DragObject);
	virtual Cxgridcommon::TcxCustomGridDragOpenInfo* __fastcall GetDragOpenInfo(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	bool __fastcall IsDragOpenHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, /* out */ Cxgridcommon::TcxCustomGridDragOpenInfo* &ADragOpenInfo);
	void __fastcall StartDragOpen(Cxgridcommon::TcxCustomGridDragOpenInfo* ADragOpenInfo);
	void __fastcall StopDragOpen(void);
	__property Cxgridcommon::TcxCustomGridDragOpenInfo* DragOpenInfo = {read=FDragOpenInfo};
	__property TcxGridDesignController* DesignController = {read=GetDesignController};
public:
	/* TcxCustomGridHandler.Create */ inline __fastcall virtual TcxGridController(TcxCustomGrid* AControl) : TcxCustomGridHandler(AControl) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridPainterClass;

class DELPHICLASS TcxGridPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridPainter : public TcxCustomGridHandler
{
	typedef TcxCustomGridHandler inherited;
	
private:
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	
protected:
	virtual void __fastcall DrawDetailsSite(void);
	
public:
	virtual void __fastcall Invalidate(bool AInvalidateDetails)/* overload */;
	virtual void __fastcall Invalidate(const System::Types::TRect &R)/* overload */;
	virtual void __fastcall Paint(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
public:
	/* TcxCustomGridHandler.Create */ inline __fastcall virtual TcxGridPainter(TcxCustomGrid* AControl) : TcxCustomGridHandler(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridTopDetailsSiteViewInfoClass;

class DELPHICLASS TcxGridTopDetailsSiteViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTopDetailsSiteViewInfo : public Cxgriddetailssite::TcxCustomGridDetailsSiteViewInfo
{
	typedef Cxgriddetailssite::TcxCustomGridDetailsSiteViewInfo inherited;
	
private:
	HIDESBASE TcxCustomGrid* __fastcall GetControl(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveGridView(void);
	virtual Cxgridlevel::TcxGridLevel* __fastcall GetActiveLevel(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual Cxcontrols::TcxControl* __fastcall GetContainer(void);
	virtual Cxgridcustomview::TcxCustomGridDesignController* __fastcall GetDesignController(void);
	virtual System::TObject* __fastcall GetMasterRecord(void);
	virtual int __fastcall GetMaxHeight(void);
	virtual int __fastcall GetMaxWidth(void);
	virtual void __fastcall InitTabHitTest(Cxgriddetailssite::TcxGridDetailsSiteTabHitTest* AHitTest);
	__property TcxCustomGrid* Control = {read=GetControl};
	
public:
	virtual void __fastcall ChangeActiveTab(Cxgridlevel::TcxGridLevel* ALevel, bool AFocusView = false);
	virtual bool __fastcall DetailHasData(Cxgridlevel::TcxGridLevel* ALevel);
	virtual bool __fastcall SupportsTabAccelerators(void);
	virtual void __fastcall VisibilityChanged(bool AVisible);
public:
	/* TcxCustomGridDetailsSiteViewInfo.Create */ inline __fastcall virtual TcxGridTopDetailsSiteViewInfo(Cxgridlevel::TcxGridLevel* ALevel) : Cxgriddetailssite::TcxCustomGridDetailsSiteViewInfo(ALevel) { }
	/* TcxCustomGridDetailsSiteViewInfo.Destroy */ inline __fastcall virtual ~TcxGridTopDetailsSiteViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewInfo : public TcxCustomGridHandler
{
	typedef TcxCustomGridHandler inherited;
	
private:
	TcxGridTopDetailsSiteViewInfo* FDetailsSiteViewInfo;
	Cxgriddetailssite::TcxCustomGridDetailsSiteViewInfoCachedInfo* FDetailsSiteViewInfoCachedInfo;
	bool FIsCalculating;
	System::Types::TRect __fastcall GetBounds(void);
	System::Types::TRect __fastcall GetClientBounds(void);
	System::Uitypes::TColor __fastcall GetEmptyAreaColor(void);
	
protected:
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(void);
	virtual TcxGridTopDetailsSiteViewInfoClass __fastcall GetDetailsSiteViewInfoClass(void);
	void __fastcall RecreateViewInfos(void);
	virtual void __fastcall Calculate(void);
	
public:
	__fastcall virtual TcxGridViewInfo(TcxCustomGrid* AControl);
	__fastcall virtual ~TcxGridViewInfo(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(int X, int Y);
	void __fastcall MainCalculate(void);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property TcxGridTopDetailsSiteViewInfo* DetailsSiteViewInfo = {read=FDetailsSiteViewInfo};
	__property System::Uitypes::TColor EmptyAreaColor = {read=GetEmptyAreaColor, nodefault};
	__property bool IsCalculating = {read=FIsCalculating, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridLevelTabsClass;

class DELPHICLASS TcxGridLevelTabs;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLevelTabs : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TAlignment FCaptionAlignment;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	int FImageBorder;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImagesChangeLink;
	TcxCustomGrid* FOwner;
	Cxpc::TcxTabSlants* FSlants;
	Cxpc::TcxPCStyleID FStyle;
	void __fastcall SetCaptionAlignment(System::Classes::TAlignment Value);
	void __fastcall SetImageBorder(int Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetSlants(Cxpc::TcxTabSlants* Value);
	void __fastcall SetStyle(Cxpc::TcxPCStyleID Value);
	void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	void __fastcall ImagesChanged(System::TObject* Sender);
	void __fastcall SlantsChanged(System::TObject* Sender);
	
protected:
	void __fastcall Changed(void);
	
public:
	__fastcall virtual TcxGridLevelTabs(TcxCustomGrid* AOwner);
	__fastcall virtual ~TcxGridLevelTabs(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	__property TcxCustomGrid* Owner = {read=FOwner};
	
__published:
	__property System::Classes::TAlignment CaptionAlignment = {read=FCaptionAlignment, write=SetCaptionAlignment, default=2};
	__property int ImageBorder = {read=FImageBorder, write=SetImageBorder, default=0};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property Cxpc::TcxTabSlants* Slants = {read=FSlants, write=SetSlants};
	__property Cxpc::TcxPCStyleID Style = {read=FStyle, write=SetStyle, default=0};
};

#pragma pack(pop)

class DELPHICLASS TcxGridRootLevelOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridRootLevelOptions : public Cxgridlevel::TcxGridLevelOptions
{
	typedef Cxgridlevel::TcxGridLevelOptions inherited;
	
public:
	__fastcall virtual TcxGridRootLevelOptions(Cxgridlevel::TcxGridLevel* ALevel);
	
__published:
	__property DetailFrameWidth = {default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridRootLevelOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridRootLevel;
class PASCALIMPLEMENTATION TcxGridRootLevel : public Cxgridlevel::TcxGridLevel
{
	typedef Cxgridlevel::TcxGridLevel inherited;
	
protected:
	virtual Cxgridlevel::TcxGridLevelOptionsClass __fastcall GetOptionsClass(void);
public:
	/* TcxGridLevel.Create */ inline __fastcall virtual TcxGridRootLevel(System::Classes::TComponent* AOwner) : Cxgridlevel::TcxGridLevel(AOwner) { }
	/* TcxGridLevel.Destroy */ inline __fastcall virtual ~TcxGridRootLevel(void) { }
	
};


class DELPHICLASS TcxGridLockedStateImageOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLockedStateImageOptions : public Cxcontrols::TcxLockedStateImageOptions
{
	typedef Cxcontrols::TcxLockedStateImageOptions inherited;
	
private:
	TcxCustomGrid* FGrid;
	
protected:
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual bool __fastcall IsTextStored(void);
	__property TcxCustomGrid* Grid = {read=FGrid};
	
public:
	__fastcall virtual TcxGridLockedStateImageOptions(TcxCustomGrid* AGrid);
	
__published:
	__property AssignedValues = {default=0};
	__property Color = {default=536870911};
	__property Effect = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ShowText = {default=0};
	__property Text = {default=0};
public:
	/* TcxLockedStateImageOptions.Destroy */ inline __fastcall virtual ~TcxGridLockedStateImageOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridLockedStateImageOptionsClass;

class DELPHICLASS TcxGridLockedStatePaintHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLockedStatePaintHelper : public Cxcontrols::TcxLockedStatePaintHelper
{
	typedef Cxcontrols::TcxLockedStatePaintHelper inherited;
	
private:
	TcxCustomGrid* __fastcall GetGrid(void);
	
protected:
	virtual bool __fastcall CanCreateLockedImage(void);
	virtual bool __fastcall DoPrepareImage(void);
	virtual Cxcontrols::TcxLockedStateImageOptions* __fastcall GetOptions(void);
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	__property TcxCustomGrid* Grid = {read=GetGrid};
public:
	/* TcxLockedStatePaintHelper.Create */ inline __fastcall virtual TcxGridLockedStatePaintHelper(System::Classes::TComponent* AOwner) : Cxcontrols::TcxLockedStatePaintHelper(AOwner) { }
	/* TcxLockedStatePaintHelper.Destroy */ inline __fastcall virtual ~TcxGridLockedStatePaintHelper(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridLockedStatePaintHelperClass;

typedef void __fastcall (__closure *TcxGridActiveTabChangedEvent)(TcxCustomGrid* Sender, Cxgridlevel::TcxGridLevel* ALevel);

typedef void __fastcall (__closure *TcxGridFocusedViewChangedEvent)(TcxCustomGrid* Sender, Cxgridcustomview::TcxCustomGridView* APrevFocusedView, Cxgridcustomview::TcxCustomGridView* AFocusedView);

typedef void __fastcall (__closure *TcxGridLayoutChangedEvent)(TcxCustomGrid* Sender, Cxgridcustomview::TcxCustomGridView* AGridView);

typedef void __fastcall (__closure *TcxGridPrepareLockedStateImageEvent)(TcxCustomGrid* Sender, Cxgraphics::TcxBitmap32* AImage, bool &ADone);

class PASCALIMPLEMENTATION TcxCustomGrid : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Cxgridlevel::TcxGridLevel* FActiveLevel;
	System::Classes::TList* FChanges;
	TcxGridController* FController;
	bool FCreatingStructureNavigator;
	bool FDragOpening;
	int FDragOpeningWaitTime;
	Cxgridcustomview::TcxCustomGridView* FFocusedView;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	bool FIsExportMode;
	bool FIsPopupControl;
	bool FLastFocused;
	Cxgridlevel::TcxGridLevel* FLevels;
	TcxGridLevelTabs* FLevelTabs;
	TcxGridLockedStatePaintHelper* FLockedStatePaintHelper;
	TcxGridLockedStateImageOptions* FLockedStateImageOptions;
	Cxnavigator::TcxNavigatorControlNotifier* FNavigatorNotifier;
	System::Classes::TList* FNotifications;
	TcxGridPainter* FPainter;
	TcxCustomGridStructureNavigator* FStructureNavigator;
	bool FTabStop;
	System::TObject* FTag;
	int FUpdateCount;
	int FUpdateLockCount;
	TcxGridViewInfo* FViewInfo;
	System::Classes::TList* FViews;
	TcxGridActiveTabChangedEvent FOnActiveTabChanged;
	TcxGridFocusedViewChangedEvent FOnFocusedViewChanged;
	TcxGridLayoutChangedEvent FOnLayoutChanged;
	TcxGridPrepareLockedStateImageEvent FOnPrepareLockedStateImage;
	System::Classes::TNotifyEvent FSubClassEvents;
	Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveView(void);
	Cxnavigator::_di_IcxNavigator __fastcall GetFocusedViewNavigator(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetView(int Index);
	int __fastcall GetViewCount(void);
	Cxgridlevel::TcxGridLevelOptions* __fastcall GetRootLevelOptions(void);
	Cxgridlevel::TcxGridLevelStyles* __fastcall GetRootLevelStyles(void);
	TcxCustomGridStructureNavigator* __fastcall GetStructureNavigator(void);
	bool __fastcall GetUpdateLocked(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetActiveLevel(Cxgridlevel::TcxGridLevel* Value);
	void __fastcall SetDragOpeningWaitTime(int Value);
	void __fastcall SetFocusedView(Cxgridcustomview::TcxCustomGridView* Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetLevels(Cxgridlevel::TcxGridLevel* Value);
	void __fastcall SetLevelTabs(TcxGridLevelTabs* Value);
	void __fastcall SetLockedStateImageOptions(TcxGridLockedStateImageOptions* Value);
	void __fastcall SetRootLevelOptions(Cxgridlevel::TcxGridLevelOptions* Value);
	void __fastcall SetRootLevelStyles(Cxgridlevel::TcxGridLevelStyles* Value);
	HIDESBASE void __fastcall SetTabStop(bool Value);
	void __fastcall AddView(Cxgridcustomview::TcxCustomGridView* AView);
	void __fastcall RemoveView(Cxgridcustomview::TcxCustomGridView* AView);
	void __fastcall DestroyViews(void);
	void __fastcall DestroyChanges(System::Classes::TList* AChanges);
	void __fastcall DestroyViewChanges(Cxgridcustomview::TcxCustomGridView* AView);
	void __fastcall CreateStructureNavigator(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	bool __fastcall NavigatorIsActive(void);
	bool __fastcall NavigatorIsBof(void);
	bool __fastcall NavigatorIsEof(void);
	bool __fastcall NavigatorCanAppend(void);
	bool __fastcall NavigatorCanEdit(void);
	bool __fastcall NavigatorCanDelete(void);
	bool __fastcall NavigatorCanInsert(void);
	bool __fastcall NavigatorIsEditing(void);
	void __fastcall NavigatorClearBookmark(void);
	bool __fastcall NavigatorIsBookmarkAvailable(void);
	void __fastcall NavigatorDoAction(int AButtonIndex);
	Cxnavigator::TcxNavigatorControlNotifier* __fastcall NavigatorGetNotifier(void);
	bool __fastcall NavigatorIsActionSupported(int AButtonIndex);
	int __fastcall NavigatorGetRecordCount(void);
	int __fastcall NavigatorGetRecordIndex(void);
	Cxgraphics::TcxBitmap32* __fastcall GetLockedStateImage(void);
	Cxcontrols::TcxControl* __fastcall GetLockedStateTopmostControl(void);
	void __fastcall UpdateLockedStateFont(Vcl::Graphics::TFont* AFont);
	virtual Dxtouch::_di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint &APoint);
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd);
	DYNAMIC void __fastcall AddChildComponent(Cxcontrols::TcxControlChildComponent* AComponent);
	DYNAMIC void __fastcall RemoveChildComponent(Cxcontrols::TcxControlChildComponent* AComponent);
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC void __fastcall DoCancelMode(void);
	DYNAMIC void __fastcall DoContextPopup(const System::Types::TPoint &MousePos, bool &Handled);
	virtual void __fastcall DoPaint(void);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual bool __fastcall GetIsFocused(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC bool __fastcall MayFocus(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall CreateHandlers(void);
	virtual void __fastcall DestroyHandlers(void);
	virtual bool __fastcall DoPrepareLockedStateImage(void);
	virtual TcxGridLockedStatePaintHelperClass __fastcall GetLockedStatePaintHelperClass(void);
	virtual TcxGridLockedStateImageOptionsClass __fastcall GetLockedStateImageOptionsClass(void);
	__property TcxGridLockedStatePaintHelper* LockedStatePaintHelper = {read=FLockedStatePaintHelper};
	__property TcxGridPrepareLockedStateImageEvent OnPrepareLockedStateImage = {read=FOnPrepareLockedStateImage, write=FOnPrepareLockedStateImage};
	virtual void __fastcall DoActiveTabChanged(Cxgridlevel::TcxGridLevel* ALevel);
	void __fastcall DoChange(Cxgridcommon::TcxCustomGridChange* AGridChange);
	virtual void __fastcall DoLayoutChanged(Cxgridcustomview::TcxCustomGridView* AGridView);
	void __fastcall DoUpdate(System::Classes::TList* AChanges);
	virtual void __fastcall FocusedViewChanged(Cxgridcustomview::TcxCustomGridView* APrevFocusedView, Cxgridcustomview::TcxCustomGridView* AFocusedView);
	virtual TcxGridControllerClass __fastcall GetControllerClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetDefaultViewClass(void);
	virtual Cxgridlevel::TcxGridLevelClass __fastcall GetLevelsClass(void);
	virtual TcxGridLevelTabsClass __fastcall GetLevelTabsClass(void);
	virtual TcxGridPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridViewInfoClass __fastcall GetViewInfoClass(void);
	bool __fastcall IsUpdating(void);
	void __fastcall LevelChanged(Cxgridlevel::TcxGridLevel* ALevel, Cxgridlevel::TcxGridLevelChangeKind AChangeKind);
	void __fastcall RefreshNavigators(void);
	void __fastcall StructureNavigatorChanged(void);
	virtual bool __fastcall UpdateOnRootViewDataChange(void);
	void __fastcall ViewChanged(Cxgridcustomview::TcxCustomGridView* AView, Cxgridcustomview::TcxGridViewChangeNotificationKind AChangeKind);
	void __fastcall UpdateFocusing(bool AChildFocused);
	__property bool LastFocused = {read=FLastFocused, nodefault};
	__property Cxnavigator::_di_IcxNavigator FocusedViewNavigator = {read=GetFocusedViewNavigator};
	__property bool IsExportMode = {read=FIsExportMode, nodefault};
	__property bool IsPopupControl = {read=FIsPopupControl, write=FIsPopupControl, nodefault};
	__property Cxnavigator::TcxNavigatorControlNotifier* NavigatorNotifier = {read=FNavigatorNotifier};
	
public:
	__fastcall virtual TcxCustomGrid(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomGrid(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	HIDESBASE void __fastcall Invalidate(bool AHardUpdate = false);
	HIDESBASE void __fastcall RemoveFocus(bool AGoForward);
	void __fastcall BeginLockedStatePaint(Cxgridcustomview::TcxGridShowLockedStateImageMode AMode);
	void __fastcall EndLockedStatePaint(void);
	void __fastcall BeginUpdate(Cxgridcustomview::TcxGridShowLockedStateImageMode AMode = (Cxgridcustomview::TcxGridShowLockedStateImageMode)(0x0));
	void __fastcall CancelUpdate(void);
	void __fastcall BeginExport(void);
	void __fastcall EndExport(void);
	HIDESBASE void __fastcall Changed(Cxgridcommon::TcxCustomGridChange* AGridChange);
	void __fastcall CheckFocusedView(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall SizeChanged(void);
	__property bool UpdateLocked = {read=GetUpdateLocked, nodefault};
	Cxgridcustomview::TcxCustomGridView* __fastcall CreateView(Cxgridcustomview::TcxCustomGridViewClass AViewClass);
	bool __fastcall ViewExists(Cxgridcustomview::TcxCustomGridView* AView);
	void __fastcall RegisterNotification(TcxCustomGridNotification* ANotification);
	void __fastcall UnregisterNotification(TcxCustomGridNotification* ANotification);
	bool __fastcall SendNotifications(TcxGridNotificationKind AKind, System::TObject* AData = (System::TObject*)(0x0));
	virtual void __fastcall RootViewDataChanged(Cxgridcustomview::TcxCustomGridView* AView);
	virtual void __fastcall TranslationChanged(void);
	__property Cxgridcustomview::TcxCustomGridView* ActiveView = {read=GetActiveView};
	__property Cxgridlevel::TcxGridLevel* ActiveLevel = {read=FActiveLevel, write=SetActiveLevel};
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property TcxGridController* Controller = {read=FController};
	__property bool DragOpening = {read=FDragOpening, write=FDragOpening, default=1};
	__property int DragOpeningWaitTime = {read=FDragOpeningWaitTime, write=SetDragOpeningWaitTime, default=800};
	__property Cxgridcustomview::TcxCustomGridView* FocusedView = {read=FFocusedView, write=SetFocusedView};
	__property Font;
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property Cxgridlevel::TcxGridLevel* Levels = {read=FLevels, write=SetLevels};
	__property TcxGridLevelTabs* LevelTabs = {read=FLevelTabs, write=SetLevelTabs};
	__property TcxGridLockedStateImageOptions* LockedStateImageOptions = {read=FLockedStateImageOptions, write=SetLockedStateImageOptions};
	__property LookAndFeel;
	__property LookAndFeelPainter;
	__property TcxGridPainter* Painter = {read=FPainter};
	__property Cxgridlevel::TcxGridLevelOptions* RootLevelOptions = {read=GetRootLevelOptions, write=SetRootLevelOptions};
	__property Cxgridlevel::TcxGridLevelStyles* RootLevelStyles = {read=GetRootLevelStyles, write=SetRootLevelStyles};
	__property TcxCustomGridStructureNavigator* StructureNavigator = {read=GetStructureNavigator};
	__property bool TabStop = {read=FTabStop, write=SetTabStop, default=1};
	__property int ViewCount = {read=GetViewCount, nodefault};
	__property TcxGridViewInfo* ViewInfo = {read=FViewInfo};
	__property Cxgridcustomview::TcxCustomGridView* Views[int Index] = {read=GetView};
	__property TcxGridActiveTabChangedEvent OnActiveTabChanged = {read=FOnActiveTabChanged, write=FOnActiveTabChanged};
	__property TcxGridFocusedViewChangedEvent OnFocusedViewChanged = {read=FOnFocusedViewChanged, write=FOnFocusedViewChanged};
	__property TcxGridLayoutChangedEvent OnLayoutChanged = {read=FOnLayoutChanged, write=FOnLayoutChanged};
	
__published:
	__property System::Classes::TNotifyEvent RootLevelStylesEvents = {read=FSubClassEvents, write=FSubClassEvents};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGrid(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IcxLockedStateFontChanged;	/* Cxcontrols::IcxLockedStateFontChanged */
	void *__IcxLockedStatePaint;	/* Cxcontrols::IcxLockedStatePaint */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxNavigatorRecordPosition;	/* Cxnavigator::IcxNavigatorRecordPosition */
	void *__IcxNavigator;	/* Cxnavigator::IcxNavigator */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {825BFA90-77C6-4725-BE95-B0A1EA8F934D}
	operator Cxcontrols::_di_IcxLockedStateFontChanged()
	{
		Cxcontrols::_di_IcxLockedStateFontChanged intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxLockedStateFontChanged*(void) { return (Cxcontrols::IcxLockedStateFontChanged*)&__IcxLockedStateFontChanged; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EB45AB76-3681-4838-BDA8-7D0081B4C184}
	operator Cxcontrols::_di_IcxLockedStatePaint()
	{
		Cxcontrols::_di_IcxLockedStatePaint intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxLockedStatePaint*(void) { return (Cxcontrols::IcxLockedStatePaint*)&__IcxLockedStatePaint; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {715C9E38-5BA0-4ED8-B35C-BB40EA739362}
	operator Cxnavigator::_di_IcxNavigatorRecordPosition()
	{
		Cxnavigator::_di_IcxNavigatorRecordPosition intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigatorRecordPosition*(void) { return (Cxnavigator::IcxNavigatorRecordPosition*)&__IcxNavigatorRecordPosition; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A15F80CA-DE56-47CB-B0EB-035D0BF90E9D}
	operator Cxnavigator::_di_IcxNavigator()
	{
		Cxnavigator::_di_IcxNavigator intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigator*(void) { return (Cxnavigator::IcxNavigator*)&__IcxNavigator; }
	#endif
	
};


class DELPHICLASS TcxGrid;
class PASCALIMPLEMENTATION TcxGrid : public TcxCustomGrid
{
	typedef TcxCustomGrid inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BorderWidth = {default=0};
	__property BorderStyle = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Images;
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property DragOpening = {default=1};
	__property DragOpeningWaitTime = {default=800};
	__property LevelTabs;
	__property LockedStateImageOptions;
	__property LookAndFeel;
	__property RootLevelOptions;
	__property RootLevelStyles;
	__property OnActiveTabChanged;
	__property OnFocusedViewChanged;
	__property OnLayoutChanged;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnPrepareLockedStateImage;
public:
	/* TcxCustomGrid.Create */ inline __fastcall virtual TcxGrid(System::Classes::TComponent* AOwner) : TcxCustomGrid(AOwner) { }
	/* TcxCustomGrid.Destroy */ inline __fastcall virtual ~TcxGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGrid(HWND ParentWindow) : TcxCustomGrid(ParentWindow) { }
	
};


class DELPHICLASS TcxGridViewRepository;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewRepository : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
public:
	Cxgridcustomview::TcxCustomGridView* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetItem(int Index);
	void __fastcall DestroyItems(void);
	
protected:
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall AddItem(Cxgridcustomview::TcxCustomGridView* AItem);
	void __fastcall RemoveItem(Cxgridcustomview::TcxCustomGridView* AItem);
	
public:
	__fastcall virtual TcxGridViewRepository(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridViewRepository(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall CreateItem(Cxgridcustomview::TcxCustomGridViewClass AItemClass);
	__property int Count = {read=GetCount, nodefault};
	__property Cxgridcustomview::TcxCustomGridView* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Classes::TAlignment cxGridLevelTabsDefaultCaptionAlignment = (System::Classes::TAlignment)(2);
static const System::Int8 cxGridLevelTabsDefaultImageBorder = System::Int8(0x0);
static const System::Int8 cxGridRootLevelDefaultDetailFrameWidth = System::Int8(0x0);
static const System::Word cxGridDefaultDragOpeningWaitTime = System::Word(0x320);
extern PACKAGE TcxCustomGridStructureNavigatorClass cxGridStructureNavigatorClass;
extern PACKAGE TcxCustomGrid* __fastcall GetParentGrid(Vcl::Controls::TControl* AControl);
}	/* namespace Cxgrid */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRID)
using namespace Cxgrid;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridHPP
