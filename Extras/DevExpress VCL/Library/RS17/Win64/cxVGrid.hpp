// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVGrid.pas' rev: 24.00 (Win64)

#ifndef CxvgridHPP
#define CxvgridHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <cxFilterControl.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxVGridUtils.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvgrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxVerticalGridError;
class PASCALIMPLEMENTATION EcxVerticalGridError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxVerticalGridError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxVerticalGridError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxVerticalGridError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxVerticalGridError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxVerticalGridError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxVerticalGridError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxVerticalGridError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxVerticalGridError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxVerticalGridError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxVerticalGridError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxVerticalGridError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxVerticalGridError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxVerticalGridError(void) { }
	
};


typedef System::TMetaClass* TcxRowValueInfoClass;

typedef System::TMetaClass* TcxVerticalGridCustomizingClass;

typedef System::TMetaClass* TcxvgCustomRowStylesClass;

typedef System::TMetaClass* TcxvgCustomPaintStyleCalcHelperClass;

class DELPHICLASS TcxvgOptionsBehavior;
class PASCALIMPLEMENTATION TcxvgOptionsBehavior : public Cxinplacecontainer::TcxControlOptionsBehavior
{
	typedef Cxinplacecontainer::TcxControlOptionsBehavior inherited;
	
private:
	bool FAlwaysShowEditorAssigned;
	bool FBandSizing;
	bool FHeaderSizing;
	bool FRowSizing;
	bool FRowTracking;
	bool __fastcall GetAlwaysShowEditor(void);
	HIDESBASE void __fastcall SetAlwaysShowEditor(bool Value);
	
protected:
	void __fastcall InternalSetAlwaysShowEditor(bool Value);
	
public:
	__fastcall virtual TcxvgOptionsBehavior(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool AlwaysShowEditor = {read=GetAlwaysShowEditor, write=SetAlwaysShowEditor, stored=FAlwaysShowEditorAssigned, nodefault};
	__property bool BandSizing = {read=FBandSizing, write=FBandSizing, default=1};
	__property CellHints = {default=1};
	__property FocusCellOnCycle = {default=0};
	__property bool HeaderSizing = {read=FHeaderSizing, write=FHeaderSizing, default=1};
	__property bool RowSizing = {read=FRowSizing, write=FRowSizing, default=0};
	__property bool RowTracking = {read=FRowTracking, write=FRowTracking, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxvgOptionsBehavior(void) { }
	
};


class DELPHICLASS TcxvgMultiRecordsOptionsBehavior;
class DELPHICLASS TcxCustomEditorRow;
class PASCALIMPLEMENTATION TcxvgMultiRecordsOptionsBehavior : public TcxvgOptionsBehavior
{
	typedef TcxvgOptionsBehavior inherited;
	
private:
	bool FAllowChangeRecord;
	TcxCustomEditorRow* __fastcall GetIncSearchItem(void);
	void __fastcall SetAllowChangeRecord(bool Value);
	HIDESBASE void __fastcall SetIncSearchItem(TcxCustomEditorRow* Value);
	
public:
	__fastcall virtual TcxvgMultiRecordsOptionsBehavior(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AllowChangeRecord = {read=FAllowChangeRecord, write=SetAllowChangeRecord, default=1};
	__property FocusFirstCellOnNewRecord = {default=0};
	__property IncSearch = {default=0};
	__property TcxCustomEditorRow* IncSearchItem = {read=GetIncSearchItem, write=SetIncSearchItem};
	__property NavigatorHints = {default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxvgMultiRecordsOptionsBehavior(void) { }
	
};


class DELPHICLASS TcxvgMultiRecordsOptionsData;
class DELPHICLASS TcxVirtualVerticalGrid;
class PASCALIMPLEMENTATION TcxvgMultiRecordsOptionsData : public Cxinplacecontainer::TcxControlOptionsData
{
	typedef Cxinplacecontainer::TcxControlOptionsData inherited;
	
private:
	bool FAppending;
	bool FDeleting;
	bool FInserting;
	bool FDeletingConfirmation;
	Dxcore::TdxDefaultBoolean FMultiThreadedFiltering;
	void __fastcall SetAppending(bool Value);
	void __fastcall SetDeleting(bool Value);
	void __fastcall SetInserting(bool Value);
	Dxcore::TdxDefaultBoolean __fastcall GetMultiThreadedFiltering(void);
	void __fastcall SetMultiThreadedFiltering(const Dxcore::TdxDefaultBoolean Value);
	TcxVirtualVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual void __fastcall Changed(void);
	__property TcxVirtualVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__fastcall virtual TcxvgMultiRecordsOptionsData(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Appending = {read=FAppending, write=SetAppending, default=1};
	__property bool Deleting = {read=FDeleting, write=SetDeleting, default=1};
	__property bool DeletingConfirmation = {read=FDeletingConfirmation, write=FDeletingConfirmation, default=1};
	__property bool Inserting = {read=FInserting, write=SetInserting, default=1};
	__property Dxcore::TdxDefaultBoolean MultiThreadedFiltering = {read=GetMultiThreadedFiltering, write=SetMultiThreadedFiltering, default=2};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxvgMultiRecordsOptionsData(void) { }
	
};


enum TcxvgPaintStyle : unsigned char { psdotNet, psDelphi };

enum TcxvgGridLines : unsigned char { vglNone, vglHorizontal, vglVertical, vglBoth };

class DELPHICLASS TcxvgOptionsView;
class DELPHICLASS TcxCustomVerticalGrid;
class PASCALIMPLEMENTATION TcxvgOptionsView : public Cxinplacecontainer::TcxControlOptionsView
{
	typedef Cxinplacecontainer::TcxControlOptionsView inherited;
	
private:
	bool FAutoScaleBands;
	int FBandsInterval;
	bool FCategoryExplorerStyle;
	System::Uitypes::TColor FGridLineColor;
	bool FGridLineColorAssigned;
	int FValueWidth;
	TcxvgPaintStyle FPaintStyle;
	int FRowHeaderMinWidth;
	int FRowHeaderWidth;
	int FRowHeight;
	bool FShowButtons;
	bool FShowHeaders;
	bool FShowEmptyRowImage;
	TcxvgGridLines FGridLines;
	int FValueMinWidth;
	System::Uitypes::TColor __fastcall GetGridLineColor(void);
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	bool __fastcall IsPaintStyleStored(void);
	void __fastcall SetAutoScaleBands(bool Value);
	void __fastcall SetBandsInterval(int Value);
	void __fastcall SetCategoryExplorerStyle(bool Value);
	void __fastcall SetGridLineColor(System::Uitypes::TColor Value);
	void __fastcall SetPaintStyle(TcxvgPaintStyle Value);
	void __fastcall SetRowHeaderMinWidth(int Value);
	void __fastcall SetRowHeaderWidth(int Value);
	void __fastcall SetRowHeight(int Value);
	void __fastcall SetShowButtons(bool Value);
	void __fastcall SetShowEmptyRowImage(bool Value);
	void __fastcall SetShowHeaders(bool Value);
	void __fastcall SetGridLines(TcxvgGridLines Value);
	void __fastcall SetValueMinWidth(int Value);
	void __fastcall SetValueWidth(int Value);
	
protected:
	virtual void __fastcall Changed(void);
	virtual TcxvgPaintStyle __fastcall GetDefaultPaintStyle(void);
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__fastcall virtual TcxvgOptionsView(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool AutoScaleBands = {read=FAutoScaleBands, write=SetAutoScaleBands, default=1};
	__property int BandsInterval = {read=FBandsInterval, write=SetBandsInterval, default=2};
	__property bool CategoryExplorerStyle = {read=FCategoryExplorerStyle, write=SetCategoryExplorerStyle, default=0};
	__property TcxvgPaintStyle PaintStyle = {read=FPaintStyle, write=SetPaintStyle, stored=IsPaintStyleStored, nodefault};
	__property System::Uitypes::TColor GridLineColor = {read=GetGridLineColor, write=SetGridLineColor, stored=FGridLineColorAssigned, nodefault};
	__property int RowHeaderMinWidth = {read=FRowHeaderMinWidth, write=SetRowHeaderMinWidth, default=24};
	__property int RowHeaderWidth = {read=FRowHeaderWidth, write=SetRowHeaderWidth, default=100};
	__property int RowHeight = {read=FRowHeight, write=SetRowHeight, default=-1};
	__property bool ShowButtons = {read=FShowButtons, write=SetShowButtons, default=1};
	__property ShowEditButtons;
	__property bool ShowEmptyRowImage = {read=FShowEmptyRowImage, write=SetShowEmptyRowImage, default=0};
	__property bool ShowHeaders = {read=FShowHeaders, write=SetShowHeaders, default=1};
	__property TcxvgGridLines GridLines = {read=FGridLines, write=SetGridLines, default=3};
	__property int ValueWidth = {read=FValueWidth, write=SetValueWidth, default=100};
	__property int ValueMinWidth = {read=FValueMinWidth, write=SetValueMinWidth, default=40};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxvgOptionsView(void) { }
	
};


class DELPHICLASS TcxvgMultiRecordsOptionsView;
class PASCALIMPLEMENTATION TcxvgMultiRecordsOptionsView : public TcxvgOptionsView
{
	typedef TcxvgOptionsView inherited;
	
private:
	int FRecordsInterval;
	void __fastcall SetRecordsInterval(int Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property NavigatorOffset = {default=50};
	__property int RecordsInterval = {read=FRecordsInterval, write=SetRecordsInterval, default=0};
public:
	/* TcxvgOptionsView.Create */ inline __fastcall virtual TcxvgMultiRecordsOptionsView(System::Classes::TPersistent* AOwner) : TcxvgOptionsView(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxvgMultiRecordsOptionsView(void) { }
	
};


class DELPHICLASS TcxCustomRowProperties;
class DELPHICLASS TcxCustomRow;
class PASCALIMPLEMENTATION TcxCustomRowProperties : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
private:
	System::Classes::TCollection* FCollection;
	bool FLocked;
	TcxCustomRow* FRow;
	
protected:
	HIDESBASE virtual void __fastcall Changed(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	__property bool Locked = {read=FLocked, nodefault};
	
public:
	__fastcall virtual TcxCustomRowProperties(System::Classes::TCollection* Collection);
	__fastcall virtual TcxCustomRowProperties(TcxCustomRow* ARow);
	__property TcxCustomRow* Row = {read=FRow};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxCustomRowProperties(void) { }
	
};


typedef System::TMetaClass* TcxRowPropertiesClass;

class DELPHICLASS TcxCaptionRowProperties;
class PASCALIMPLEMENTATION TcxCaptionRowProperties : public TcxCustomRowProperties
{
	typedef TcxCustomRowProperties inherited;
	
private:
	System::Classes::TAlignment FHeaderAlignmentHorz;
	Cxclasses::TcxAlignmentVert FHeaderAlignmentVert;
	bool FIsCaptionAssigned;
	Vcl::Controls::TCaption FCaption;
	System::Uitypes::TImageIndex FImageIndex;
	System::UnicodeString FHint;
	Vcl::Controls::TCaption __fastcall GetCaption(void);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsHeaderAlignmentVertStored(void);
	void __fastcall SetCaption(const Vcl::Controls::TCaption Value);
	void __fastcall SetImageIndex(const System::Uitypes::TImageIndex Value);
	void __fastcall SetHeaderAlignmentHorz(const System::Classes::TAlignment Value);
	void __fastcall SetHeaderAlignmentVert(const Cxclasses::TcxAlignmentVert Value);
	
protected:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual void __fastcall RestoreDefaults(void);
	
public:
	__fastcall virtual TcxCaptionRowProperties(TcxCustomRow* ARow);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Controls::TCaption Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property System::Classes::TAlignment HeaderAlignmentHorz = {read=FHeaderAlignmentHorz, write=SetHeaderAlignmentHorz, default=0};
	__property Cxclasses::TcxAlignmentVert HeaderAlignmentVert = {read=FHeaderAlignmentVert, write=SetHeaderAlignmentVert, stored=IsHeaderAlignmentVertStored, nodefault};
	__property System::UnicodeString Hint = {read=FHint, write=FHint};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxCaptionRowProperties(System::Classes::TCollection* Collection) : TcxCustomRowProperties(Collection) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxCaptionRowProperties(void) { }
	
};


class DELPHICLASS TcxRowOptions;
class PASCALIMPLEMENTATION TcxRowOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FCanAutoHeight;
	bool FCanMovedToCustomizationForm;
	bool FCanResized;
	bool FFocusing;
	bool FMoving;
	TcxCustomRow* FRow;
	bool FShowExpandButton;
	bool FShowInCustomizationForm;
	bool FTabStop;
	void __fastcall SetCanAutoHeight(bool Value);
	void __fastcall SetFocusing(bool Value);
	void __fastcall SetShowExpandButton(bool Value);
	void __fastcall SetShowInCustomizationForm(bool Value);
	
protected:
	virtual void __fastcall Changed(void);
	__property TcxCustomRow* Row = {read=FRow};
	
public:
	__fastcall virtual TcxRowOptions(TcxCustomRow* ARow);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool CanAutoHeight = {read=FCanAutoHeight, write=SetCanAutoHeight, default=1};
	__property bool CanMovedToCustomizationForm = {read=FCanMovedToCustomizationForm, write=FCanMovedToCustomizationForm, default=1};
	__property bool CanResized = {read=FCanResized, write=FCanResized, default=1};
	__property bool Focusing = {read=FFocusing, write=SetFocusing, default=1};
	__property bool Moving = {read=FMoving, write=FMoving, default=1};
	__property bool ShowExpandButton = {read=FShowExpandButton, write=SetShowExpandButton, default=1};
	__property bool ShowInCustomizationForm = {read=FShowInCustomizationForm, write=SetShowInCustomizationForm, default=1};
	__property bool TabStop = {read=FTabStop, write=FTabStop, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxRowOptions(void) { }
	
};


typedef System::TMetaClass* TcxRowOptionsClass;

class DELPHICLASS TcxRowList;
class PASCALIMPLEMENTATION TcxRowList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	TcxCustomRow* FOwner;
	
protected:
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	void __fastcall UpdateIndexes(void);
	__property TcxCustomRow* Owner = {read=FOwner};
	
public:
	__fastcall TcxRowList(TcxCustomRow* AOwner);
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxRowList(void) { }
	
};


class DELPHICLASS TcxvgCustomRowStyles;
class DELPHICLASS TcxCustomRowViewInfo;
class DELPHICLASS TcxVerticalGridRows;
class DELPHICLASS TcxCustomRowHeaderInfo;
class DELPHICLASS TcxCellEdit;
class PASCALIMPLEMENTATION TcxCustomRow : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FExpanded;
	int FHeight;
	int FID;
	int FIndex;
	int FLoadedID;
	int FLoadedIndex;
	int FLoadedParentID;
	int FLoadingIndex;
	System::UnicodeString FLoadingParent;
	TcxRowOptions* FOptions;
	TcxCustomRow* FParent;
	TcxRowList* FRows;
	TcxvgCustomRowStyles* FStyles;
	int FVersion;
	TcxCustomVerticalGrid* FVerticalGrid;
	TcxCustomRowViewInfo* FViewInfo;
	bool FVisible;
	int FVisibleIndex;
	int __fastcall GetAbsoluteIndex(void);
	int __fastcall GetCount(void);
	bool __fastcall GetFocused(void);
	int __fastcall GetLevel(void);
	TcxVerticalGridRows* __fastcall GetOwnerRows(void);
	TcxCustomRow* __fastcall GetParent(void);
	TcxCustomRow* __fastcall GetRow(int Index);
	TcxCustomRowViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetExpanded(bool Value);
	void __fastcall SetFocused(bool Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetOptions(TcxRowOptions* Value);
	void __fastcall SetParent(TcxCustomRow* Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall ReadID(System::Classes::TReader* Reader);
	void __fastcall ReadLoadedIndex(System::Classes::TReader* Reader);
	void __fastcall ReadLoadedParentID(System::Classes::TReader* Reader);
	void __fastcall ReadVersion(System::Classes::TReader* Reader);
	void __fastcall WriteID(System::Classes::TWriter* Writer);
	void __fastcall WriteLoadedIndex(System::Classes::TWriter* Writer);
	void __fastcall WriteLoadedParentID(System::Classes::TWriter* Writer);
	void __fastcall WriteVersion(System::Classes::TWriter* Writer);
	
protected:
	TcxCustomRowProperties* FProperties;
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	void __fastcall Add(TcxCustomRow* ARow);
	virtual bool __fastcall CanFocus(void);
	bool __fastcall CanNavigate(void);
	virtual bool __fastcall CanTabStop(void);
	virtual void __fastcall Changed(bool ARebuild = false);
	virtual TcxCustomRowHeaderInfo* __fastcall CreateHeaderInfo(void) = 0 ;
	virtual TcxCustomRowViewInfo* __fastcall CreateViewInfo(void) = 0 ;
	void __fastcall Delete(int AIndex);
	virtual int __fastcall GetDefaultHeight(void);
	virtual TcxCellEdit* __fastcall GetEditContainer(int ACellIndex);
	virtual int __fastcall GetEditContainerCount(void);
	virtual TcxRowPropertiesClass __fastcall GetPropertiesClass(void);
	virtual int __fastcall GetRealHeight(void);
	virtual TcxRowOptionsClass __fastcall GetOptionsClass(void);
	virtual TcxvgCustomRowStylesClass __fastcall GetStylesClass(void);
	HIDESBASE void __fastcall Insert(int AIndex, TcxCustomRow* ARow);
	bool __fastcall IsHeightAssigned(void);
	void __fastcall Refresh(void);
	HIDESBASE void __fastcall Remove(TcxCustomRow* ARow);
	void __fastcall RemoveAll(void);
	void __fastcall RemoveChildren(void);
	void __fastcall ResetOwnerCount(void);
	void __fastcall RestoreIndex(void);
	void __fastcall RestoreParent(void);
	virtual void __fastcall SetVerticalGrid(TcxCustomVerticalGrid* Value);
	__property int ID = {read=FID, nodefault};
	__property TcxVerticalGridRows* OwnerRows = {read=GetOwnerRows};
	__property TcxvgCustomRowStyles* Styles = {read=FStyles, write=FStyles};
	
public:
	__fastcall virtual TcxCustomRow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomRow(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	void __fastcall Collapse(bool ARecurse);
	void __fastcall Expand(bool ARecurse);
	TcxCustomRow* __fastcall GetFirstVisibleChild(void);
	TcxCustomRow* __fastcall GetLastVisibleChild(void);
	bool __fastcall HasChildren(void);
	bool __fastcall HasVisibleChildren(void);
	int __fastcall IndexOf(TcxCustomRow* ARow);
	bool __fastcall IsChild(TcxCustomRow* ARow);
	bool __fastcall IsFirst(void);
	bool __fastcall IsFirstVisible(void);
	bool __fastcall IsLast(void);
	bool __fastcall IsLastVisible(void);
	bool __fastcall IsRootLevel(void);
	bool __fastcall IsParent(TcxCustomRow* ARow);
	void __fastcall MakeVisible(void);
	void __fastcall RestoreDefaults(void);
	__property int AbsoluteIndex = {read=GetAbsoluteIndex, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property bool Expanded = {read=FExpanded, write=SetExpanded, default=1};
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, default=-1};
	__property int Index = {read=FIndex, write=SetIndex, nodefault};
	__property int Level = {read=GetLevel, nodefault};
	__property TcxRowOptions* Options = {read=FOptions, write=SetOptions};
	__property TcxCustomRow* Parent = {read=GetParent, write=SetParent};
	__property TcxCustomRow* Rows[int Index] = {read=GetRow};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=FVerticalGrid, write=SetVerticalGrid};
	__property TcxCustomRowViewInfo* ViewInfo = {read=GetViewInfo};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int VisibleIndex = {read=FVisibleIndex, nodefault};
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};


typedef System::TMetaClass* TcxCustomRowClass;

class DELPHICLASS TcxCategoryRow;
class DELPHICLASS TcxCategoryRowStyles;
class PASCALIMPLEMENTATION TcxCategoryRow : public TcxCustomRow
{
	typedef TcxCustomRow inherited;
	
private:
	TcxCaptionRowProperties* __fastcall GetProperties(void);
	TcxCategoryRowStyles* __fastcall GetStyles(void);
	void __fastcall SetProperties(TcxCaptionRowProperties* Value);
	void __fastcall SetStyles(TcxCategoryRowStyles* Value);
	
protected:
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual int __fastcall GetDefaultHeight(void);
	virtual TcxvgCustomRowStylesClass __fastcall GetStylesClass(void);
	
public:
	virtual TcxCustomRowHeaderInfo* __fastcall CreateHeaderInfo(void);
	virtual TcxCustomRowViewInfo* __fastcall CreateViewInfo(void);
	
__published:
	__property Expanded = {default=1};
	__property Height = {default=-1};
	__property Options;
	__property TcxCaptionRowProperties* Properties = {read=GetProperties, write=SetProperties};
	__property TcxCategoryRowStyles* Styles = {read=GetStyles, write=SetStyles};
	__property Visible = {default=1};
public:
	/* TcxCustomRow.Create */ inline __fastcall virtual TcxCategoryRow(System::Classes::TComponent* AOwner) : TcxCustomRow(AOwner) { }
	/* TcxCustomRow.Destroy */ inline __fastcall virtual ~TcxCategoryRow(void) { }
	
};


class DELPHICLASS TcxEditorRowPropertiesOptions;
class PASCALIMPLEMENTATION TcxEditorRowPropertiesOptions : public Cxinplacecontainer::TcxCustomEditContainerItemOptions
{
	typedef Cxinplacecontainer::TcxCustomEditContainerItemOptions inherited;
	
__published:
	__property Editing = {default=1};
	__property Filtering = {default=1};
	__property IncSearch = {default=1};
	__property ShowEditButtons = {default=0};
public:
	/* TcxCustomEditContainerItemOptions.Create */ inline __fastcall virtual TcxEditorRowPropertiesOptions(System::Classes::TPersistent* AOwner) : Cxinplacecontainer::TcxCustomEditContainerItemOptions(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxEditorRowPropertiesOptions(void) { }
	
};


class DELPHICLASS TcxCustomEditorRowProperties;
class DELPHICLASS TcxRowValueInfo;
class PASCALIMPLEMENTATION TcxCellEdit : public Cxinplacecontainer::TcxCustomInplaceEditContainer
{
	typedef Cxinplacecontainer::TcxCustomInplaceEditContainer inherited;
	
private:
	bool FCalculating;
	TcxCustomEditorRowProperties* FEditRowProperties;
	TcxCustomRow* FRow;
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	TcxCustomRowViewInfo* __fastcall GetViewInfo(void);
	
protected:
	int FCellIndex;
	void __fastcall Calculate(TcxRowValueInfo* ACellViewInfo);
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanInitEditing(void);
	virtual bool __fastcall CanTabStop(void);
	virtual void __fastcall DoGetDisplayText(NativeInt ARecordIndex, System::UnicodeString &AText);
	virtual Cxedit::TcxCustomEditProperties* __fastcall DoGetPropertiesFromEvent(Cxinplacecontainer::TcxGetEditPropertiesEvent AEvent, void * AData, Cxedit::TcxCustomEditProperties* AProperties);
	virtual System::Variant __fastcall GetCurrentValue(void);
	virtual Cxinplacecontainer::TcxItemDataBindingClass __fastcall GetDataBindingClass(void);
	virtual System::Variant __fastcall GetDisplayValue(Cxedit::TcxCustomEditProperties* AProperties, int ARecordIndex);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual Cxinplacecontainer::TcxCustomEditContainerItemOptionsClass __fastcall GetOptionsClass(void);
	virtual System::Variant __fastcall GetValue(int ARecordIndex);
	virtual int __fastcall GetValueCount(void);
	virtual bool __fastcall HasDataTextHandler(void);
	virtual void __fastcall SetCurrentValue(const System::Variant &Value);
	virtual void __fastcall SetValue(int ARecordIndex, const System::Variant &Value);
	virtual void __fastcall ValidateDrawValue(const System::Variant &Value, Cxinplacecontainer::TcxEditCellViewInfo* AEditViewInfo);
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__fastcall virtual TcxCellEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCellEdit(void);
	__property int CellIndex = {read=FCellIndex, nodefault};
	__property TcxCustomEditorRowProperties* EditRowProperties = {read=FEditRowProperties};
	__property Options;
	__property TcxCustomRow* Row = {read=FRow};
	__property TcxCustomRowViewInfo* ViewInfo = {read=GetViewInfo};
};


typedef System::TMetaClass* TcxCellEditClass;

typedef void __fastcall (__closure *TcxVerticalGridGetDisplayTextEvent)(TcxCustomEditorRowProperties* Sender, int ARecord, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxVerticalGridGetEditPropertiesEvent)(TcxCustomEditorRowProperties* Sender, int ARecordIndex, Cxedit::TcxCustomEditProperties* &AProperties);

typedef void __fastcall (__closure *TcxVerticalGridValidateDrawValueEvent)(TcxCustomEditorRowProperties* Sender, int ARecordIndex, const System::Variant &AValue, Cxedit::TcxEditValidateInfo* AData);

class PASCALIMPLEMENTATION TcxCustomEditorRowProperties : public TcxCaptionRowProperties
{
	typedef TcxCaptionRowProperties inherited;
	
private:
	TcxCellEdit* FEditContainer;
	TcxVerticalGridGetDisplayTextEvent FOnGetDisplayText;
	TcxVerticalGridValidateDrawValueEvent FOnValidateDrawValue;
	Cxinplacecontainer::TcxItemDataBinding* __fastcall GetDataBinding(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetDisplayEditProperty(int Index);
	System::UnicodeString __fastcall GetDisplayText(int Index);
	Cxedit::TcxCustomEditViewData* __fastcall GetEditViewData(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetEditProperties(void);
	Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass(void);
	System::UnicodeString __fastcall GetEditPropertiesClassName(void);
	Cxinplacecontainer::_di_IcxEditorPropertiesContainer __fastcall GetIEditorPropertiesContainer(void);
	int __fastcall GetItemIndex(void);
	System::TObject* __fastcall GetItemLink(void);
	TcxEditorRowPropertiesOptions* __fastcall GetOptions(void);
	Cxedit::TcxEditRepositoryItem* __fastcall GetRepositoryItem(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetPropertiesValue(void);
	System::Variant __fastcall GetValue(void);
	System::Variant __fastcall GetValueByIndex(int Index);
	void __fastcall SetDataBinding(Cxinplacecontainer::TcxItemDataBinding* Value);
	void __fastcall SetEditProperties(Cxedit::TcxCustomEditProperties* Value);
	void __fastcall SetEditPropertiesClass(Cxedit::TcxCustomEditPropertiesClass Value);
	void __fastcall SetEditPropertiesClassName(const System::UnicodeString Value);
	void __fastcall SetOptions(TcxEditorRowPropertiesOptions* Value);
	void __fastcall SetRepositoryItem(Cxedit::TcxEditRepositoryItem* Value);
	void __fastcall SetValue(const System::Variant &Value);
	TcxVerticalGridGetEditPropertiesEvent __fastcall GetOnGetEditingProperties(void);
	TcxVerticalGridGetEditPropertiesEvent __fastcall GetOnGetEditProperties(void);
	void __fastcall SetOnGetEditingProperties(TcxVerticalGridGetEditPropertiesEvent Value);
	void __fastcall SetOnGetEditProperties(TcxVerticalGridGetEditPropertiesEvent Value);
	
protected:
	virtual TcxCellEditClass __fastcall GetInplaceEditContainerClass(void);
	virtual void __fastcall DoGetDisplayTextEvent(int ARecordIndex, System::UnicodeString &Text);
	virtual void __fastcall DoValidateDrawValue(const System::Variant &Value, int ARecordIndex, Cxedit::TcxEditValidateInfo* AData);
	__property TcxCellEdit* EditContainer = {read=FEditContainer};
	__property Cxedit::TcxCustomEditViewData* EditViewData = {read=GetEditViewData};
	__property Cxinplacecontainer::_di_IcxEditorPropertiesContainer IEditorPropertiesContainer = {read=GetIEditorPropertiesContainer};
	__property Cxinplacecontainer::TcxItemDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property TcxEditorRowPropertiesOptions* Options = {read=GetOptions, write=SetOptions};
	__property System::Variant Value = {read=GetValue, write=SetValue};
	__property TcxVerticalGridGetDisplayTextEvent OnGetDisplayText = {read=FOnGetDisplayText, write=FOnGetDisplayText};
	__property TcxVerticalGridGetEditPropertiesEvent OnGetEditProperties = {read=GetOnGetEditProperties, write=SetOnGetEditProperties};
	__property TcxVerticalGridGetEditPropertiesEvent OnGetEditingProperties = {read=GetOnGetEditingProperties, write=SetOnGetEditingProperties};
	__property TcxVerticalGridValidateDrawValueEvent OnValidateDrawValue = {read=FOnValidateDrawValue, write=FOnValidateDrawValue};
	
public:
	__fastcall virtual TcxCustomEditorRowProperties(TcxCustomRow* ARow);
	__fastcall virtual ~TcxCustomEditorRowProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Cxedit::TcxCustomEditProperties* DisplayEditProperties[int Index] = {read=GetDisplayEditProperty};
	__property System::UnicodeString DisplayTexts[int Index] = {read=GetDisplayText};
	__property Cxedit::TcxCustomEditPropertiesClass EditPropertiesClass = {read=GetEditPropertiesClass, write=SetEditPropertiesClass};
	__property int ItemIndex = {read=GetItemIndex, nodefault};
	__property System::TObject* ItemLink = {read=GetItemLink};
	__property Cxedit::TcxCustomEditProperties* PropertiesValue = {read=GetPropertiesValue};
	__property System::Variant Values[int Index] = {read=GetValueByIndex};
	
__published:
	__property System::UnicodeString EditPropertiesClassName = {read=GetEditPropertiesClassName, write=SetEditPropertiesClassName};
	__property Cxedit::TcxCustomEditProperties* EditProperties = {read=GetEditProperties, write=SetEditProperties};
	__property Cxedit::TcxEditRepositoryItem* RepositoryItem = {read=GetRepositoryItem, write=SetRepositoryItem};
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxCustomEditorRowProperties(System::Classes::TCollection* Collection) : TcxCaptionRowProperties(Collection) { }
	
private:
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9F0CD5D9-A3D1-44B7-82DC-CAEAC1367C5D}
	operator Cxinplacecontainer::_di_IcxEditorPropertiesContainer() { return IEditorPropertiesContainer; }
	#else
	operator Cxinplacecontainer::IcxEditorPropertiesContainer*(void) { return (Cxinplacecontainer::IcxEditorPropertiesContainer*)IEditorPropertiesContainer; }
	#endif
	
};


typedef System::TMetaClass* TcxEditorRowPropertiesClass;

class DELPHICLASS TcxEditorRowProperties;
class PASCALIMPLEMENTATION TcxEditorRowProperties : public TcxCustomEditorRowProperties
{
	typedef TcxCustomEditorRowProperties inherited;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property DataBinding;
	__property Options;
	__property Value = {default=0};
	__property OnGetDisplayText;
	__property OnGetEditProperties;
	__property OnGetEditingProperties;
	__property OnValidateDrawValue;
public:
	/* TcxCustomEditorRowProperties.CreateEx */ inline __fastcall virtual TcxEditorRowProperties(TcxCustomRow* ARow) : TcxCustomEditorRowProperties(ARow) { }
	/* TcxCustomEditorRowProperties.Destroy */ inline __fastcall virtual ~TcxEditorRowProperties(void) { }
	
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxEditorRowProperties(System::Classes::TCollection* Collection) : TcxCustomEditorRowProperties(Collection) { }
	
};


class DELPHICLASS TcxEditorRowStyles;
class PASCALIMPLEMENTATION TcxCustomEditorRow : public TcxCustomRow
{
	typedef TcxCustomRow inherited;
	
private:
	System::Classes::TNotifyEvent FEditPropertiesEvents;
	System::Classes::TNotifyEvent FPropertiesEvents;
	TcxCustomEditorRowProperties* __fastcall GetProperties(void);
	TcxEditorRowStyles* __fastcall GetStyles(void);
	void __fastcall SetProperties(TcxCustomEditorRowProperties* Value);
	void __fastcall SetStyles(TcxEditorRowStyles* Value);
	
protected:
	virtual bool __fastcall CanFocus(void);
	TcxCellEdit* __fastcall EditContainer(void);
	virtual int __fastcall GetDefaultHeight(void);
	virtual TcxCellEdit* __fastcall GetEditContainer(int ACellIndex);
	virtual int __fastcall GetEditContainerCount(void);
	virtual TcxRowPropertiesClass __fastcall GetPropertiesClass(void);
	virtual TcxvgCustomRowStylesClass __fastcall GetStylesClass(void);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	virtual void __fastcall SetVerticalGrid(TcxCustomVerticalGrid* Value);
	__property TcxEditorRowStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxCustomEditorRowProperties* Properties = {read=GetProperties, write=SetProperties};
	
public:
	virtual TcxCustomRowHeaderInfo* __fastcall CreateHeaderInfo(void);
	virtual TcxCustomRowViewInfo* __fastcall CreateViewInfo(void);
	
__published:
	__property System::Classes::TNotifyEvent EditPropertiesEvents = {read=FEditPropertiesEvents, write=FEditPropertiesEvents};
	__property Options;
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FPropertiesEvents, write=FPropertiesEvents};
public:
	/* TcxCustomRow.Create */ inline __fastcall virtual TcxCustomEditorRow(System::Classes::TComponent* AOwner) : TcxCustomRow(AOwner) { }
	/* TcxCustomRow.Destroy */ inline __fastcall virtual ~TcxCustomEditorRow(void) { }
	
};


class DELPHICLASS TcxEditorRow;
class PASCALIMPLEMENTATION TcxEditorRow : public TcxCustomEditorRow
{
	typedef TcxCustomEditorRow inherited;
	
private:
	HIDESBASE TcxEditorRowProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxEditorRowProperties* Value);
	
protected:
	virtual TcxRowPropertiesClass __fastcall GetPropertiesClass(void);
	
__published:
	__property Expanded = {default=1};
	__property Height = {default=-1};
	__property Options;
	__property TcxEditorRowProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Styles;
	__property Visible = {default=1};
public:
	/* TcxCustomRow.Create */ inline __fastcall virtual TcxEditorRow(System::Classes::TComponent* AOwner) : TcxCustomEditorRow(AOwner) { }
	/* TcxCustomRow.Destroy */ inline __fastcall virtual ~TcxEditorRow(void) { }
	
};


enum TSeparatorKind : unsigned char { skVertLine, skString };

struct DECLSPEC_DRECORD TSeparatorInfo
{
public:
	int Width;
	TSeparatorKind Kind;
	System::UnicodeString Caption;
	int TextFlags;
	Cxgraphics::TcxViewParams ViewParams;
};


class DELPHICLASS TcxMultiEditorRowPropertiesOptions;
class PASCALIMPLEMENTATION TcxMultiEditorRowPropertiesOptions : public Cxinplacecontainer::TcxCustomEditContainerItemOptions
{
	typedef Cxinplacecontainer::TcxCustomEditContainerItemOptions inherited;
	
__published:
	__property Editing = {default=1};
	__property Filtering = {default=1};
	__property Focusing = {default=1};
	__property IncSearch = {default=1};
	__property ShowEditButtons = {default=0};
	__property TabStop = {default=1};
public:
	/* TcxCustomEditContainerItemOptions.Create */ inline __fastcall virtual TcxMultiEditorRowPropertiesOptions(System::Classes::TPersistent* AOwner) : Cxinplacecontainer::TcxCustomEditContainerItemOptions(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxMultiEditorRowPropertiesOptions(void) { }
	
};


class DELPHICLASS TcxCollectionItemEditorRowProperties;
class PASCALIMPLEMENTATION TcxCollectionItemEditorRowProperties : public TcxCustomEditorRowProperties
{
	typedef TcxCustomEditorRowProperties inherited;
	
private:
	System::Classes::TNotifyEvent FEditPropertiesEvents;
	int FWidth;
	HIDESBASE TcxMultiEditorRowPropertiesOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetOptions(TcxMultiEditorRowPropertiesOptions* Value);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	__property TcxMultiEditorRowPropertiesOptions* Options = {read=GetOptions, write=SetOptions};
	
public:
	__fastcall virtual TcxCollectionItemEditorRowProperties(TcxCustomRow* ARow);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Classes::TNotifyEvent EditPropertiesEvents = {read=FEditPropertiesEvents, write=FEditPropertiesEvents};
	__property int Width = {read=FWidth, write=SetWidth, default=50};
public:
	/* TcxCustomEditorRowProperties.Destroy */ inline __fastcall virtual ~TcxCollectionItemEditorRowProperties(void) { }
	
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxCollectionItemEditorRowProperties(System::Classes::TCollection* Collection) : TcxCustomEditorRowProperties(Collection) { }
	
};


class DELPHICLASS TcxEditorRowItemProperties;
class PASCALIMPLEMENTATION TcxEditorRowItemProperties : public TcxCollectionItemEditorRowProperties
{
	typedef TcxCollectionItemEditorRowProperties inherited;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property DataBinding;
	__property Options;
	__property Value = {default=0};
	__property OnGetDisplayText;
	__property OnGetEditProperties;
	__property OnGetEditingProperties;
	__property OnValidateDrawValue;
public:
	/* TcxCollectionItemEditorRowProperties.CreateEx */ inline __fastcall virtual TcxEditorRowItemProperties(TcxCustomRow* ARow) : TcxCollectionItemEditorRowProperties(ARow) { }
	
public:
	/* TcxCustomEditorRowProperties.Destroy */ inline __fastcall virtual ~TcxEditorRowItemProperties(void) { }
	
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxEditorRowItemProperties(System::Classes::TCollection* Collection) : TcxCollectionItemEditorRowProperties(Collection) { }
	
};


class DELPHICLASS TcxEditorPropertiesCollection;
class DELPHICLASS TcxCustomMultiEditorRow;
class PASCALIMPLEMENTATION TcxEditorPropertiesCollection : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxEditorRowItemProperties* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomMultiEditorRow* FRow;
	HIDESBASE TcxEditorRowItemProperties* __fastcall GetItem(int Index);
	
protected:
	virtual System::Classes::TCollectionItemClass __fastcall GetCollectionItemClass(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Notify(System::Classes::TCollectionItem* Item, System::Classes::TCollectionNotification Action);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TcxEditorPropertiesCollection(TcxCustomMultiEditorRow* ARow);
	HIDESBASE TcxEditorRowItemProperties* __fastcall Add(void);
	DYNAMIC System::UnicodeString __fastcall GetNamePath(void);
	__property TcxEditorRowItemProperties* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxCustomMultiEditorRow* Row = {read=FRow};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxEditorPropertiesCollection(void) { }
	
};


typedef System::TMetaClass* TcxEditorPropertiesCollectionClass;

class DELPHICLASS TcxMultiEditorRowProperties;
class PASCALIMPLEMENTATION TcxMultiEditorRowProperties : public TcxCustomRowProperties
{
	typedef TcxCustomRowProperties inherited;
	
private:
	bool FFixed;
	TcxEditorPropertiesCollection* FEditors;
	Cxclasses::TcxAlignmentVert FSeparatorAlignmentVert;
	TSeparatorKind FSeparatorKind;
	System::UnicodeString FSeparatorString;
	void __fastcall SetFixed(bool Value);
	void __fastcall SetSeparatorAlignmentVert(Cxclasses::TcxAlignmentVert Value);
	void __fastcall SetSeparatorKind(TSeparatorKind Value);
	void __fastcall SetSeparatorString(const System::UnicodeString Value);
	
protected:
	virtual TcxEditorPropertiesCollectionClass __fastcall GetCollectionClass(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxMultiEditorRowProperties(TcxCustomRow* ARow);
	__fastcall virtual ~TcxMultiEditorRowProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxEditorPropertiesCollection* Editors = {read=FEditors, write=FEditors};
	__property bool Fixed = {read=FFixed, write=SetFixed, default=0};
	__property Cxclasses::TcxAlignmentVert SeparatorAlignmentVert = {read=FSeparatorAlignmentVert, write=SetSeparatorAlignmentVert, default=0};
	__property TSeparatorKind SeparatorKind = {read=FSeparatorKind, write=SetSeparatorKind, default=0};
	__property System::UnicodeString SeparatorString = {read=FSeparatorString, write=SetSeparatorString};
public:
	/* TcxCustomRowProperties.Create */ inline __fastcall virtual TcxMultiEditorRowProperties(System::Classes::TCollection* Collection) : TcxCustomRowProperties(Collection) { }
	
};


class PASCALIMPLEMENTATION TcxCustomMultiEditorRow : public TcxCustomRow
{
	typedef TcxCustomRow inherited;
	
private:
	TcxMultiEditorRowProperties* __fastcall GetProperties(void);
	TcxEditorRowStyles* __fastcall GetStyles(void);
	void __fastcall SetProperties(TcxMultiEditorRowProperties* const Value);
	void __fastcall SetStyles(TcxEditorRowStyles* Value);
	
protected:
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanTabStop(void);
	virtual void __fastcall EditorsChanged(void);
	virtual int __fastcall GetDefaultHeight(void);
	virtual TcxCellEdit* __fastcall GetEditContainer(int ACellIndex);
	virtual int __fastcall GetEditContainerCount(void);
	virtual TcxRowPropertiesClass __fastcall GetPropertiesClass(void);
	virtual TcxvgCustomRowStylesClass __fastcall GetStylesClass(void);
	__property TcxEditorRowStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxMultiEditorRowProperties* Properties = {read=GetProperties, write=SetProperties};
	
public:
	virtual TcxCustomRowHeaderInfo* __fastcall CreateHeaderInfo(void);
	virtual TcxCustomRowViewInfo* __fastcall CreateViewInfo(void);
public:
	/* TcxCustomRow.Create */ inline __fastcall virtual TcxCustomMultiEditorRow(System::Classes::TComponent* AOwner) : TcxCustomRow(AOwner) { }
	/* TcxCustomRow.Destroy */ inline __fastcall virtual ~TcxCustomMultiEditorRow(void) { }
	
};


class DELPHICLASS TcxMultiEditorRow;
class PASCALIMPLEMENTATION TcxMultiEditorRow : public TcxCustomMultiEditorRow
{
	typedef TcxCustomMultiEditorRow inherited;
	
__published:
	__property Expanded = {default=1};
	__property Height = {default=-1};
	__property Options;
	__property Properties;
	__property Styles;
	__property Visible = {default=1};
public:
	/* TcxCustomRow.Create */ inline __fastcall virtual TcxMultiEditorRow(System::Classes::TComponent* AOwner) : TcxCustomMultiEditorRow(AOwner) { }
	/* TcxCustomRow.Destroy */ inline __fastcall virtual ~TcxMultiEditorRow(void) { }
	
};


class PASCALIMPLEMENTATION TcxVerticalGridRows : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomRow* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FList;
	int FLockCount;
	int FNextID;
	TcxCustomVerticalGrid* FOwner;
	int FCount;
	int FMaxVisibleLevel;
	System::Classes::TList* FVisibleRows;
	int __fastcall GetCount(void);
	TcxCustomRow* __fastcall GetRoot(void);
	TcxCustomRow* __fastcall GetRow(int Index);
	int __fastcall GetVisibleRowCount(void);
	TcxCustomRow* __fastcall GetVisibleRow(int Index);
	void __fastcall SetRow(int Index, TcxCustomRow* const Value);
	
protected:
	void __fastcall Add(TcxCustomRow* ARow);
	void __fastcall AddChild(TcxCustomRow* AParent, TcxCustomRow* ARow);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall Changed(bool ARebuild = false);
	void __fastcall CheckList(void);
	void __fastcall Clear(void);
	void __fastcall EndUpdate(void);
	TcxCustomRow* __fastcall FindLoadedParent(int AID);
	TcxCustomRow* __fastcall FindRowByID(int AID);
	TcxCustomRow* __fastcall FindRowByStoredName(const System::UnicodeString AName);
	int __fastcall GetNextID(void);
	bool __fastcall IsRowVisible(TcxCustomRow* ARow);
	void __fastcall PrepareList(void);
	void __fastcall Remove(TcxCustomRow* ARow);
	void __fastcall RestoreDefaults(void);
	void __fastcall UnprepareList(void);
	void __fastcall UpdateVisibleRows(void);
	__property int MaxVisibleLevel = {read=FMaxVisibleLevel, nodefault};
	__property TcxCustomRow* Root = {read=GetRoot};
	__property TcxCustomVerticalGrid* Owner = {read=FOwner};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	__property TcxCustomRow* VisibleRows[int Index] = {read=GetVisibleRow};
	
public:
	__fastcall TcxVerticalGridRows(TcxCustomVerticalGrid* AOwner);
	__fastcall virtual ~TcxVerticalGridRows(void);
	void __fastcall AssignRows(TcxVerticalGridRows* Source);
	int __fastcall IndexOf(TcxCustomRow* ARow);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomRow* Items[int Index] = {read=GetRow, write=SetRow/*, default*/};
};


enum TcxvgUnboundLayoutStyle : unsigned char { ulsBandsView, ulsSingleRecordView };

enum TcxvgLayoutStyle : unsigned char { lsBandsView, lsSingleRecordView, lsMultiRecordView };

struct DECLSPEC_DRECORD TBandInfo
{
public:
	int BandIndex;
	int RowsCount;
	int BandHeight;
	TcxCustomRow* FirstRow;
};


class DELPHICLASS TBandInfoList;
class PASCALIMPLEMENTATION TBandInfoList : public Cxvgridutils::TcxDataList
{
	typedef Cxvgridutils::TcxDataList inherited;
	
public:
	TBandInfo operator[](int Index) { return Items[Index]; }
	
private:
	TBandInfo __fastcall GetItem(int Index);
	
public:
	__fastcall TBandInfoList(void);
	int __fastcall Add(int ABandIndex, int ARowsCount, int ABandHeight, TcxCustomRow* AFirstRow);
	__property TBandInfo Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxDataList.Destroy */ inline __fastcall virtual ~TBandInfoList(void) { }
	
};


class DELPHICLASS TcxvgCustomScrollStrategy;
class DELPHICLASS TcxvgScroller;
class DELPHICLASS TcxvgController;
class DELPHICLASS TcxvgCustomViewInfo;
class PASCALIMPLEMENTATION TcxvgCustomScrollStrategy : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TBandInfoList* FBandsInfo;
	bool FCheckingCoordinate;
	int FLeftVisibleRecord;
	TcxvgScroller* FScroller;
	int FTopVisibleRowIndex;
	TcxvgController* __fastcall GetController(void);
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	int __fastcall GetScrollBarPos(void);
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	TcxvgCustomViewInfo* __fastcall GetViewInfo(void);
	int __fastcall GetVisibleRowCount(void);
	void __fastcall SetScrollBarPos(int Value);
	void __fastcall SetTopVisibleRowIndex(int Value);
	
protected:
	virtual bool __fastcall CanContinueForward(int Index);
	virtual bool __fastcall CanContinueBackward(int Index);
	virtual bool __fastcall CanCalcRowsOnTheNextBand(int ALeft, int ANextBandIndex);
	virtual void __fastcall CheckLeftVisibleRecord(int &AValue);
	virtual int __fastcall GetBandInterval(void) = 0 ;
	int __fastcall GetBandWidth(void);
	TcxCustomRow* __fastcall GetBottomVisibleChild(TcxCustomRow* ARow);
	int __fastcall GetFullRowHeight(TcxCustomRow* ARow, /* out */ int &ChildCount);
	virtual int __fastcall GetLeftVisibleBand(void) = 0 ;
	virtual int __fastcall GetScrollBarOffsetBegin(void);
	virtual int __fastcall GetScrollBarOffsetEnd(void);
	virtual int __fastcall GetVisibleBandCount(void) = 0 ;
	virtual int __fastcall GetVisibleCount(int ABeginIndex, int AAreaHeight, int AStep, bool AForward);
	virtual int __fastcall GetVisibleValueCount(void) = 0 ;
	bool __fastcall IsBehindRightClientEdge(int X);
	virtual bool __fastcall IsHideHScrollBar(void);
	virtual bool __fastcall IsHideVScrollBar(void);
	virtual bool __fastcall IsRecordsScrollMode(void);
	virtual void __fastcall ScrollH(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall ScrollV(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SetLeftVisibleBand(int Value) = 0 ;
	virtual void __fastcall SetLeftVisibleRecord(int Value);
	void __fastcall SetTopVisibleRowIndexAndBand(int Index);
	__property TcxvgScroller* Scroller = {read=FScroller};
	__property int ScrollBarPos = {read=GetScrollBarPos, write=SetScrollBarPos, nodefault};
	
public:
	__fastcall virtual TcxvgCustomScrollStrategy(TcxvgScroller* AScroller);
	__fastcall virtual ~TcxvgCustomScrollStrategy(void);
	virtual void __fastcall CheckDecreaseLeftIndex(void);
	virtual void __fastcall CheckDecreaseTopIndex(int AScrollRectHeight);
	virtual int __fastcall CheckTopVisibleIndex(int AIndex, int AStep);
	bool __fastcall FindNextCustomItem(int AFocusedItemIndex, int AItemCount, bool AGoForward, int &AItemIndex);
	int __fastcall FindNextRecord(int AFocusedRecordIndex, bool AGoForward);
	bool __fastcall FocusNextRecord(int AFocusedRecordIndex, bool AGoForward);
	virtual int __fastcall GetBandIndexByRowIndex(int ARowIndex) = 0 ;
	int __fastcall GetVisibleCountFromBottom(int ABottomIndex, int AHeight);
	int __fastcall GetVisibleCountFromTop(int ATopIndex, int AHeight);
	virtual TcxCustomRow* __fastcall GetFirstRowByBandIndex(int ABandIndex);
	virtual void __fastcall InitHScrollBarParameters(void);
	virtual void __fastcall InitVScrollBarParameters(void);
	virtual void __fastcall RecalcBandsInfo(void);
	void __fastcall ScrollRecords(bool AForward, int ACount);
	virtual void __fastcall SetRowMaxVisible(TcxCustomRow* ARow);
	__property int BandInterval = {read=GetBandInterval, nodefault};
	__property int BandWidth = {read=GetBandWidth, nodefault};
	__property TBandInfoList* BandsInfo = {read=FBandsInfo};
	__property TcxvgController* Controller = {read=GetController};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property int LeftVisibleBand = {read=GetLeftVisibleBand, write=SetLeftVisibleBand, nodefault};
	__property int LeftVisibleRecord = {read=FLeftVisibleRecord, write=SetLeftVisibleRecord, nodefault};
	__property int ScrollBarOffsetBegin = {read=GetScrollBarOffsetBegin, nodefault};
	__property int ScrollBarOffsetEnd = {read=GetScrollBarOffsetEnd, nodefault};
	__property int TopVisibleRowIndex = {read=FTopVisibleRowIndex, write=SetTopVisibleRowIndex, nodefault};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	__property TcxvgCustomViewInfo* ViewInfo = {read=GetViewInfo};
	__property int VisibleBandCount = {read=GetVisibleBandCount, nodefault};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	__property int VisibleValueCount = {read=GetVisibleValueCount, nodefault};
};


typedef System::TMetaClass* TcxvgCustomScrollStrategyClass;

class DELPHICLASS TcxvgSingleRecordScrollStrategy;
class PASCALIMPLEMENTATION TcxvgSingleRecordScrollStrategy : public TcxvgCustomScrollStrategy
{
	typedef TcxvgCustomScrollStrategy inherited;
	
protected:
	virtual int __fastcall GetBandInterval(void);
	virtual int __fastcall GetLeftVisibleBand(void);
	virtual int __fastcall GetVisibleBandCount(void);
	virtual int __fastcall GetVisibleValueCount(void);
	virtual void __fastcall SetLeftVisibleBand(int Value);
	
public:
	virtual int __fastcall GetBandIndexByRowIndex(int ARowIndex);
public:
	/* TcxvgCustomScrollStrategy.Create */ inline __fastcall virtual TcxvgSingleRecordScrollStrategy(TcxvgScroller* AScroller) : TcxvgCustomScrollStrategy(AScroller) { }
	/* TcxvgCustomScrollStrategy.Destroy */ inline __fastcall virtual ~TcxvgSingleRecordScrollStrategy(void) { }
	
};


class DELPHICLASS TcxvgMultiRecordsScrollStrategy;
class PASCALIMPLEMENTATION TcxvgMultiRecordsScrollStrategy : public TcxvgCustomScrollStrategy
{
	typedef TcxvgCustomScrollStrategy inherited;
	
private:
	int __fastcall GetRecordsInterval(void);
	
protected:
	virtual int __fastcall GetBandInterval(void);
	virtual int __fastcall GetLeftVisibleBand(void);
	virtual int __fastcall GetVisibleBandCount(void);
	virtual int __fastcall GetVisibleValueCount(void);
	virtual void __fastcall SetLeftVisibleBand(int Value);
	__property int RecordsInterval = {read=GetRecordsInterval, nodefault};
	
public:
	virtual void __fastcall CheckDecreaseLeftIndex(void);
	virtual int __fastcall GetBandIndexByRowIndex(int ARowIndex);
public:
	/* TcxvgCustomScrollStrategy.Create */ inline __fastcall virtual TcxvgMultiRecordsScrollStrategy(TcxvgScroller* AScroller) : TcxvgCustomScrollStrategy(AScroller) { }
	/* TcxvgCustomScrollStrategy.Destroy */ inline __fastcall virtual ~TcxvgMultiRecordsScrollStrategy(void) { }
	
};


class DELPHICLASS TcxvgBandsScrollStrategy;
class PASCALIMPLEMENTATION TcxvgBandsScrollStrategy : public TcxvgCustomScrollStrategy
{
	typedef TcxvgCustomScrollStrategy inherited;
	
private:
	int FLeftVisibleBand;
	
protected:
	virtual bool __fastcall CanCalcRowsOnTheNextBand(int ALeft, int ANextBandIndex);
	virtual int __fastcall GetBandInterval(void);
	int __fastcall GetBandViewRowMaxVisibleTopIndex(TcxCustomRow* ARow);
	virtual int __fastcall GetLeftVisibleBand(void);
	virtual int __fastcall GetVisibleBandCount(void);
	virtual int __fastcall GetVisibleValueCount(void);
	virtual bool __fastcall IsRecordsScrollMode(void);
	bool __fastcall InternalSetLeftVisibleBand(int ABandIndex, bool ACheckTopVisibleRow);
	virtual void __fastcall SetLeftVisibleBand(int Value);
	void __fastcall CheckTopVisibleRowIndex(void);
	
public:
	virtual void __fastcall CheckDecreaseTopIndex(int AScrollRectHeight);
	virtual int __fastcall CheckTopVisibleIndex(int AIndex, int AStep);
	virtual int __fastcall GetBandIndexByRowIndex(int ARowIndex);
	virtual void __fastcall InitHScrollBarParameters(void);
	virtual bool __fastcall IsHideVScrollBar(void);
	virtual void __fastcall RecalcBandsInfo(void);
	virtual void __fastcall SetRowMaxVisible(TcxCustomRow* ARow);
public:
	/* TcxvgCustomScrollStrategy.Create */ inline __fastcall virtual TcxvgBandsScrollStrategy(TcxvgScroller* AScroller) : TcxvgCustomScrollStrategy(AScroller) { }
	/* TcxvgCustomScrollStrategy.Destroy */ inline __fastcall virtual ~TcxvgBandsScrollStrategy(void) { }
	
};


class PASCALIMPLEMENTATION TcxvgScroller : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FCheckDecreaseLeftIndex;
	bool FCheckDecreaseTopIndex;
	int FSaveLeftVisibleBand;
	int FSaveLeftVisibleRecord;
	int FSaveTopVisibleRowIndex;
	TcxvgCustomScrollStrategy* FScrollStrategy;
	TcxCustomVerticalGrid* FVerticalGrid;
	void __fastcall CheckDecreaseLeftIndex(void);
	void __fastcall CheckDecreaseTopIndex(void);
	TBandInfoList* __fastcall GetBandsInfo(void);
	bool __fastcall GetCheckDecrease(void);
	int __fastcall GetFocusedRecordIndex(void);
	int __fastcall GetLeftVisibleBand(void);
	int __fastcall GetLeftVisibleRecord(void);
	int __fastcall GetTopVisibleRowIndex(void);
	TcxvgCustomViewInfo* __fastcall GetViewInfo(void);
	int __fastcall GetVisibleCountFromBottom(int ARowIndex);
	int __fastcall GetVisibleRowCount(void);
	int __fastcall GetVisibleValueCount(void);
	void __fastcall SetCheckDecrease(bool Value);
	void __fastcall SetLeftVisibleBand(int Value);
	void __fastcall SetLeftVisibleRecord(int Value);
	void __fastcall SetTopVisibleRowIndex(int Value);
	
protected:
	virtual TcxvgCustomScrollStrategy* __fastcall CreateScrollStrategy(TcxvgScroller* AScroller);
	void __fastcall LayoutStyleChanged(void);
	virtual void __fastcall RestoreLayout(void);
	virtual void __fastcall SaveLayout(void);
	__property int FocusedRecordIndex = {read=GetFocusedRecordIndex, nodefault};
	__property int SaveLeftVisibleBand = {read=FSaveLeftVisibleBand, nodefault};
	__property int SaveLeftVisibleRecord = {read=FSaveLeftVisibleRecord, nodefault};
	__property int SaveTopRowIndex = {read=FSaveTopVisibleRowIndex, nodefault};
	__property TcxvgCustomScrollStrategy* ScrollStrategy = {read=FScrollStrategy};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=FVerticalGrid};
	__property TcxvgCustomViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxvgScroller(TcxCustomVerticalGrid* AVerticalGrid);
	__fastcall virtual ~TcxvgScroller(void);
	bool __fastcall GoToFirst(void);
	bool __fastcall GoToLast(void);
	bool __fastcall GoToNext(void);
	bool __fastcall GoToPrev(void);
	int __fastcall GetBandIndexByRowIndex(int ARowIndex);
	virtual void __fastcall InitScrollBarsParameters(void);
	void __fastcall RecalcBandsInfo(void);
	void __fastcall RecreateScrollStrategy(void);
	void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual bool __fastcall SetRecordVisible(int ARecordIndex);
	virtual void __fastcall SetRowVisible(TcxCustomRow* ARow);
	void __fastcall SetRowMaxVisible(TcxCustomRow* ARow);
	__property TBandInfoList* BandsInfo = {read=GetBandsInfo};
	__property bool CheckDecrease = {read=GetCheckDecrease, write=SetCheckDecrease, nodefault};
	__property int LeftVisibleBand = {read=GetLeftVisibleBand, write=SetLeftVisibleBand, nodefault};
	__property int LeftVisibleRecord = {read=GetLeftVisibleRecord, write=SetLeftVisibleRecord, nodefault};
	__property int TopVisibleRowIndex = {read=GetTopVisibleRowIndex, write=SetTopVisibleRowIndex, nodefault};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	__property int VisibleValueCount = {read=GetVisibleValueCount, nodefault};
};


class DELPHICLASS TcxvgHitTest;
class PASCALIMPLEMENTATION TcxvgHitTest : public Cxinplacecontainer::TcxCustomHitTestController
{
	typedef Cxinplacecontainer::TcxCustomHitTestController inherited;
	
private:
	bool FHitInControl;
	int FHitBandIndex;
	TcxCustomRow* FHitRow;
	int FHitCellIndex;
	bool __fastcall GetHitAtRowHeader(void);
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	System::TObject* FNewHitTestItem;
	virtual bool __fastcall AllowDesignMouseEvents(int X, int Y, System::Classes::TShiftState AShift);
	virtual void __fastcall CalcBandsHitTest(TcxvgCustomViewInfo* AViewInfo);
	virtual bool __fastcall CalcCustomizingHitTest(void);
	bool __fastcall CalcNavigatorHitTest(void);
	virtual bool __fastcall CalcRowHeaderHitTest(TcxCustomRowHeaderInfo* AHeaderInfo);
	bool __fastcall CalcRowHitTest(TcxCustomRowViewInfo* ARowViewInfo);
	virtual void __fastcall CalcRowValuesHitTest(TcxCustomRowViewInfo* ARowViewInfo);
	void __fastcall CalcRowsHitTest(TcxvgCustomViewInfo* AViewInfo);
	virtual bool __fastcall CanMoving(void);
	bool __fastcall CanSizing(void)/* overload */;
	virtual bool __fastcall CanSizing(Cxinplacecontainer::TcxDragSizingDirection &ASizeDirection)/* overload */;
	bool __fastcall Check(const System::Types::TRect &ARect);
	virtual void __fastcall DoCalculate(void);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(void);
	virtual bool __fastcall GetHitAtNavigator(void);
	bool __fastcall GetState(int Index);
	void __fastcall SetHitState(int Index, bool Value);
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__property bool HitAtBandSizing = {read=GetState, index=4, nodefault};
	__property bool HitAtButton = {read=GetState, index=5, nodefault};
	__property bool HitAtCaption = {read=GetState, index=6, nodefault};
	__property bool HitAtCustomize = {read=GetState, index=13, nodefault};
	__property bool HitAtDivider = {read=GetState, index=7, nodefault};
	__property bool HitAtEmpty = {read=GetState, index=8, nodefault};
	__property bool HitAtImage = {read=GetState, index=9, nodefault};
	__property bool HitAtIndent = {read=GetState, index=10, nodefault};
	__property bool HitAtRowHeader = {read=GetHitAtRowHeader, nodefault};
	__property bool HitAtRowSizing = {read=GetState, index=11, nodefault};
	__property bool HitAtValue = {read=GetState, index=12, nodefault};
	__property int HitBandIndex = {read=FHitBandIndex, nodefault};
	__property bool HitInControl = {read=FHitInControl, nodefault};
	__property TcxCustomRow* HitRow = {read=FHitRow};
	__property int HitCellIndex = {read=FHitCellIndex, nodefault};
public:
	/* TcxCustomHitTestController.Create */ inline __fastcall virtual TcxvgHitTest(Cxinplacecontainer::TcxCustomControlController* AOwner) : Cxinplacecontainer::TcxCustomHitTestController(AOwner) { }
	/* TcxCustomHitTestController.Destroy */ inline __fastcall virtual ~TcxvgHitTest(void) { }
	
};


class DELPHICLASS TcxvgCellNavigator;
class PASCALIMPLEMENTATION TcxvgCellNavigator : public Cxinplacecontainer::TcxCustomCellNavigator
{
	typedef Cxinplacecontainer::TcxCustomCellNavigator inherited;
	
private:
	TcxvgController* __fastcall GetController(void);
	int __fastcall GetRecordCount(void);
	TcxCustomRow* __fastcall GetRow(int Index);
	
protected:
	bool __fastcall FindNextRecord(bool AForward);
	HIDESBASE bool __fastcall FocusNextCell(bool AForward, bool ANextRow, bool ATabStopNavigation);
	void __fastcall FocusRecordRowCell(int ARecordIndex, TcxCustomRow* ARow, int ACellIndex);
	int __fastcall GetContainerCount(int ARowIndex);
	int __fastcall GetCellIndexForNextRow(bool AForward, TcxCustomRow* ANextRow);
	TcxCustomRow* __fastcall GetRowForNextRecord(bool AForward);
	bool __fastcall NavigateHorizontal(bool AForward);
	bool __fastcall NavigateMultiEditorRow(TcxCustomRow* ARow, bool AForward);
	bool __fastcall NavigateVertical(bool AForward, bool AForceNextRow);
	bool __fastcall ValidateNextCell(TcxCustomRow* ARow, bool AForward, int &ACellIndex);
	
public:
	__fastcall virtual TcxvgCellNavigator(Cxinplacecontainer::TcxCustomControlController* AController);
	bool __fastcall FindNextRow(TcxCustomRow* &ARow, int &ACellIndex, bool AForward);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	__property TcxvgController* Controller = {read=GetController};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property TcxCustomRow* Rows[int Index] = {read=GetRow};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxvgCellNavigator(void) { }
	
};


class DELPHICLASS TcxvgDragImageHelper;
class PASCALIMPLEMENTATION TcxvgDragImageHelper : public Cxinplacecontainer::TcxDragImageHelper
{
	typedef Cxinplacecontainer::TcxDragImageHelper inherited;
	
protected:
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P);
public:
	/* TcxDragImageHelper.Create */ inline __fastcall virtual TcxvgDragImageHelper(Cxinplacecontainer::TcxEditingControl* AControl, System::Types::TPoint ADragPos) : Cxinplacecontainer::TcxDragImageHelper(AControl, ADragPos) { }
	/* TcxDragImageHelper.Destroy */ inline __fastcall virtual ~TcxvgDragImageHelper(void) { }
	
};


class DELPHICLASS TcxvgDragRowObject;
class PASCALIMPLEMENTATION TcxvgDragRowObject : public Cxcontrols::TcxDragControlObject
{
	typedef Cxcontrols::TcxDragControlObject inherited;
	
private:
	TcxCustomRow* __fastcall GetRow(void);
	
protected:
	virtual System::Uitypes::TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	
public:
	__property TcxCustomRow* Row = {read=GetRow};
public:
	/* TBaseDragControlObject.Create */ inline __fastcall virtual TcxvgDragRowObject(Vcl::Controls::TControl* AControl) : Cxcontrols::TcxDragControlObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxvgDragRowObject(void) { }
	
};


enum TcxvgResizeKind : unsigned char { rkNone, rkRowSizing, rkDivider, rkBandSizing };

class PASCALIMPLEMENTATION TcxvgController : public Cxinplacecontainer::TcxCustomControlController
{
	typedef Cxinplacecontainer::TcxCustomControlController inherited;
	
private:
	Cxinplacecontainer::TcxControllerAutoScrollingObject* FAutoScrollObject;
	int FCellIndex;
	bool FDragFromCustomizingForm;
	TcxCustomRow* FDragRow;
	bool FForceShowEditor;
	TcxCustomRow* FFocusedRow;
	bool FLockIncSearch;
	bool FProcessMultiEditorRow;
	TcxvgResizeKind FResizeKind;
	TcxCustomRow* FSaveFocusedRow;
	int FSaveSeparatorPos;
	bool FScrollDown;
	TcxvgScroller* FScroller;
	Vcl::Extctrls::TTimer* FScrollTimer;
	TcxCustomRow* FSizingRow;
	int FSizingValue;
	bool FTrackingEnabled;
	bool FWasScroll;
	void __fastcall CheckMoveToCustomizationForm(void);
	TcxCellEdit* __fastcall GetFocusedItem(void);
	TcxvgHitTest* __fastcall GetHitTest(void);
	TcxvgCellNavigator* __fastcall GetNavigator(void);
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	TcxvgCustomViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetFocusedItemInternal(TcxCellEdit* Value);
	void __fastcall SetFocusedRow(TcxCustomRow* Value);
	void __fastcall SetResizeKind(TcxvgResizeKind Value);
	void __fastcall OnScrollTimer(System::TObject* Sender);
	void __fastcall StartScrollTimer(void);
	void __fastcall StopScrollTimer(void);
	
protected:
	bool FLockUpdate;
	Cxinplacecontainer::TcxDragSizingDirection ResizeDirection;
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual bool __fastcall CanSizing(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual System::Types::TRect __fastcall GetSizingBoundsRect(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual int __fastcall GetSizingIncrement(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual bool __fastcall IsDynamicUpdate(void);
	virtual void __fastcall SetSizeDelta(Cxinplacecontainer::TcxDragSizingDirection ADirection, int ADelta);
	virtual void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall StartDrag(Vcl::Controls::TDragObject* &DragObject);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall BehaviorChanged(void);
	virtual bool __fastcall CanAppend(bool ACheckOptions);
	virtual bool __fastcall CanChangeRecord(void);
	virtual bool __fastcall CanDelete(bool ACheckOptions);
	virtual bool __fastcall CanInsert(bool ACheckOptions);
	virtual bool __fastcall CanTrack(const System::Classes::TShiftState AShift);
	void __fastcall CheckPostData(void);
	void __fastcall CheckRowTracking(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoNextPage(bool AForward, System::Classes::TShiftState Shift);
	virtual void __fastcall DoUpdateRowAndCell(TcxCustomRow* ANewRow, int ANewCellIndex);
	virtual void __fastcall FocusedItemChanged(Cxinplacecontainer::TcxCustomInplaceEditContainer* APrevFocusedItem);
	virtual bool __fastcall GetCancelEditingOnExit(void);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual Cxinplacecontainer::TcxEditCellViewInfo* __fastcall GetFocusedCellViewInfo(Cxinplacecontainer::TcxCustomInplaceEditContainer* AEditContainer);
	virtual bool __fastcall GetImmediateEditor(void);
	virtual Cxinplacecontainer::TcxCustomCellNavigatorClass __fastcall GetNavigatorClass(void);
	virtual bool __fastcall GetPostDataOnChangeItem(void);
	virtual Cxinplacecontainer::TcxDragSizingDirection __fastcall GetResizeDirection(void);
	void __fastcall InternalSetRowAndCell(TcxCustomRow* ARow, int ACellIndex);
	virtual bool __fastcall IsImmediatePost(void);
	bool __fastcall IsInternalDragging(System::TObject* ADragObject);
	virtual bool __fastcall IsKeyForController(System::Word AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall RefreshFocusedRow(void);
	void __fastcall SetFocusedCellEdit(TcxCellEdit* ACellEdit);
	virtual void __fastcall SetFocusedRowAndCell(TcxCustomRow* Value, int ACellIndex);
	virtual void __fastcall UpdatePaintStyle(void);
	virtual void __fastcall UpdateRecord(NativeInt ARecordIndex);
	__property TcxCustomRow* DragRow = {read=FDragRow};
	__property bool DragFromCustomizingForm = {read=FDragFromCustomizingForm, nodefault};
	__property TcxCellEdit* FocusedItem = {read=GetFocusedItem, write=SetFocusedItemInternal};
	__property bool ForceShowEditor = {read=FForceShowEditor, nodefault};
	__property bool ProcessMultiEditorRow = {read=FProcessMultiEditorRow, nodefault};
	__property TcxvgResizeKind ResizeKind = {read=FResizeKind, write=SetResizeKind, nodefault};
	__property TcxCustomRow* SaveFocusedRow = {read=FSaveFocusedRow};
	__property int SaveSeparatorPos = {read=FSaveSeparatorPos, nodefault};
	
public:
	__fastcall virtual TcxvgController(Cxinplacecontainer::TcxEditingControl* AOwner);
	__fastcall virtual ~TcxvgController(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	virtual void __fastcall Clear(void);
	virtual void __fastcall ControlFocusChanged(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MakeFocusedItemVisible(void);
	virtual void __fastcall MakeFocusedRecordVisible(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall CanDrag(int X, int Y);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall RestoreLayout(void);
	virtual void __fastcall SaveLayout(void);
	virtual void __fastcall AppendRecord(void);
	virtual void __fastcall DeleteSelection(void);
	virtual void __fastcall InsertRecord(void);
	virtual void __fastcall MakeRowVisible(TcxCustomRow* ARow);
	virtual bool __fastcall MakeRecordVisible(int AIndex);
	__property int CellIndex = {read=FCellIndex, nodefault};
	__property TcxCustomRow* FocusedRow = {read=FFocusedRow, write=SetFocusedRow};
	__property TcxvgHitTest* HitTest = {read=GetHitTest};
	__property TcxvgCellNavigator* Navigator = {read=GetNavigator};
	__property TcxvgScroller* Scroller = {read=FScroller};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	__property TcxvgCustomViewInfo* ViewInfo = {read=GetViewInfo};
private:
	void *__IcxDragSizing;	/* Cxinplacecontainer::IcxDragSizing */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5EA02F4E-E367-4E4D-A26D-000B5E5CD434}
	operator Cxinplacecontainer::_di_IcxDragSizing()
	{
		Cxinplacecontainer::_di_IcxDragSizing intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxinplacecontainer::IcxDragSizing*(void) { return (Cxinplacecontainer::IcxDragSizing*)&__IcxDragSizing; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxDragSizing; }
	#endif
	
};


class DELPHICLASS TcxvgMultiRecordsController;
class PASCALIMPLEMENTATION TcxvgMultiRecordsController : public TcxvgController
{
	typedef TcxvgController inherited;
	
private:
	TcxvgMultiRecordsOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TcxvgMultiRecordsOptionsData* __fastcall GetOptionsData(void);
	HIDESBASE TcxVirtualVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual bool __fastcall CanAppend(bool ACheckOptions);
	virtual bool __fastcall CanChangeRecord(void);
	virtual bool __fastcall CanDelete(bool ACheckOptions);
	virtual bool __fastcall CanHandleDeleteRecordKeys(void);
	virtual bool __fastcall CanInsert(bool ACheckOptions);
	virtual void __fastcall FocusedRecordChanged(int APrevFocusedRowIndex, int AFocusedRowIndex);
	virtual bool __fastcall GetCancelEditingOnExit(void);
	virtual NativeInt __fastcall GetFocusedRecordIndex(void);
	virtual bool __fastcall GetPostDataOnChangeItem(void);
	virtual System::Word __fastcall IncSearchKeyDown(System::Word AKey, System::Classes::TShiftState AShift);
	virtual bool __fastcall IsImmediatePost(void);
	virtual void __fastcall RefreshIncSearchItem(void);
	virtual void __fastcall SetFocusedRecordIndex(NativeInt Value);
	__property TcxvgMultiRecordsOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior};
	__property TcxvgMultiRecordsOptionsData* OptionsData = {read=GetOptionsData};
	__property TcxVirtualVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	virtual void __fastcall DeleteSelection(void);
public:
	/* TcxvgController.Create */ inline __fastcall virtual TcxvgMultiRecordsController(Cxinplacecontainer::TcxEditingControl* AOwner) : TcxvgController(AOwner) { }
	/* TcxvgController.Destroy */ inline __fastcall virtual ~TcxvgMultiRecordsController(void) { }
	
};


class DELPHICLASS TcxvgPainter;
typedef void __fastcall (__closure *TcxVerticalGridDrawHeaderEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxvgPainter* APainter, TcxCustomRowHeaderInfo* AHeaderViewInfo, bool &Done);

typedef void __fastcall (__closure *TcxVerticalGridDrawValueEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxvgPainter* APainter, TcxRowValueInfo* AValueInfo, bool &Done);

typedef void __fastcall (__closure *TcxVerticalGridDrawBackgroundEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool &Done);

typedef void __fastcall (__closure *TcxVerticalGridEditingEvent)(System::TObject* Sender, TcxCustomEditorRowProperties* ARowProperties, bool &Allow);

typedef void __fastcall (__closure *TcxVerticalGridChangedEvent)(System::TObject* Sender, TcxCustomEditorRowProperties* ARowProperties);

typedef void __fastcall (__closure *TcxVerticalGridItemChangedEvent)(System::TObject* Sender, TcxCustomRow* AOldRow, int AOldCellIndex);

class DELPHICLASS TcxVerticalGridCustomizing;
class DELPHICLASS TcxVerticalGridStyles;
class PASCALIMPLEMENTATION TcxCustomVerticalGrid : public Cxinplacecontainer::TcxExtEditingControl
{
	typedef Cxinplacecontainer::TcxExtEditingControl inherited;
	
private:
	Vcl::Graphics::TFont* FCategoryFont;
	bool FClearingRows;
	TcxVerticalGridCustomizing* FCustomizing;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	Vcl::Imglist::TCustomImageList* FImages;
	bool FNewLoadMode;
	TcxCustomRow* FRootRow;
	TcxVerticalGridRows* FRows;
	System::Uitypes::TDragMode FSaveDragMode;
	System::Uitypes::TCursor FSaveDragCursor;
	System::UnicodeString FStoringName;
	System::Classes::TNotifyEvent FStylesEvents;
	int FVersion;
	System::Classes::TNotifyEvent FOnCustomizationVisibleChanged;
	TcxVerticalGridDrawBackgroundEvent FOnDrawBackground;
	TcxVerticalGridDrawHeaderEvent FOnDrawRowHeader;
	TcxVerticalGridDrawValueEvent FOnDrawValue;
	TcxVerticalGridChangedEvent FOnEdited;
	TcxVerticalGridEditingEvent FOnEditing;
	TcxVerticalGridChangedEvent FOnEditValueChanged;
	TcxVerticalGridItemChangedEvent FOnItemChanged;
	System::Classes::TNotifyEvent FOnLayoutChanged;
	System::Classes::TNotifyEvent FOnLeftVisibleBandIndexChanged;
	System::Classes::TNotifyEvent FOnLeftVisibleRecordIndexChanged;
	System::Classes::TNotifyEvent FOnTopRowIndexChanged;
	void __fastcall CategoryFontChanged(System::TObject* Sender);
	TcxvgController* __fastcall GetController(void);
	TcxCustomRowHeaderInfo* __fastcall GetDragHeaderInfo(void);
	TcxCustomRow* __fastcall GetFocusedRow(void);
	TcxvgHitTest* __fastcall GetHitTest(void);
	Cxedit::TcxCustomEdit* __fastcall GetInplaceEditor(void);
	bool __fastcall GetIsEditing(void);
	int __fastcall GetLeftVisibleBand(void);
	int __fastcall GetLeftVisibleRecord(void);
	HIDESBASE TcxvgOptionsBehavior* __fastcall GetOptionsBehavior(void);
	HIDESBASE TcxvgOptionsView* __fastcall GetOptionsView(void);
	HIDESBASE TcxvgPainter* __fastcall GetPainter(void);
	int __fastcall GetRecordCount(void);
	TcxVerticalGridStyles* __fastcall GetStyles(void);
	int __fastcall GetTopVisibleRowIndex(void);
	HIDESBASE TcxvgCustomViewInfo* __fastcall GetViewInfo(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetFocusedRow(TcxCustomRow* Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetLeftVisibleBand(int Value);
	void __fastcall SetLeftVisibleRecord(int Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxvgOptionsBehavior* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxvgOptionsView* Value);
	HIDESBASE void __fastcall SetStyles(TcxVerticalGridStyles* Value);
	void __fastcall SetTopVisibleRowIndex(int Value);
	void __fastcall ReadVersion(System::Classes::TReader* Reader);
	void __fastcall WriteVersion(System::Classes::TWriter* Writer);
	
protected:
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual void __fastcall InitControl(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC Cxcontrols::TDragControlObjectClass __fastcall GetDragObjectClass(void);
	virtual void __fastcall AfterLayoutChanged(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DoEdited(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	virtual bool __fastcall DoEditing(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoEditValueChanged(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoInplaceEditContainerItemRemoved(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoLayoutChanged(void);
	virtual System::Types::TRect __fastcall DragDropImageDisplayRect(void);
	virtual void __fastcall DrawDragDropImage(Vcl::Graphics::TBitmap* ADragBitmap, Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxinplacecontainer::TcxCustomControlControllerClass __fastcall GetControllerClass(void);
	virtual Cxinplacecontainer::TcxCustomControlStylesClass __fastcall GetControlStylesClass(void);
	virtual Cxinplacecontainer::TcxDragImageHelperClass __fastcall GetDragImageHelperClass(void);
	virtual Cxinplacecontainer::TcxItemDataBindingClass __fastcall GetEditCellDataBindingClass(void);
	virtual Cxinplacecontainer::TcxHitTestControllerClass __fastcall GetHitTestControllerClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxinplacecontainer::TcxCustomControlPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall HasDragDropImages(void);
	virtual bool __fastcall IsLocked(void);
	virtual void __fastcall RecreateViewInfo(void);
	void __fastcall RestoreLayout(void);
	void __fastcall AfterLoadedRows(void);
	void __fastcall BeforeLoadedRows(void);
	virtual bool __fastcall CanBandSizing(void);
	virtual void __fastcall CheckRowClass(TcxCustomRowClass ARowClass);
	void __fastcall CheckGridModeBufferCount(void);
	void __fastcall CheckLayoutRealign(void);
	void __fastcall FreeRowsViewInfo(void);
	virtual void __fastcall DoCustomizationVisibleChanged(void);
	virtual bool __fastcall DoDrawBackgroundPart(const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams);
	virtual bool __fastcall DoDrawRowHeader(TcxCustomRowHeaderInfo* AHeaderViewInfo);
	virtual bool __fastcall DoDrawValue(TcxRowValueInfo* AValueInfo);
	virtual void __fastcall DoItemChanged(TcxCustomRow* AOldRow, int AOldCellIndex);
	virtual void __fastcall DoLeftVisibleBandIndexChanged(void);
	virtual void __fastcall DoLeftVisibleRecordIndexChanged(void);
	virtual void __fastcall DoTopRowIndexChanged(void);
	virtual TcxvgCustomPaintStyleCalcHelperClass __fastcall GetCalcHelperClass(void);
	virtual bool __fastcall GetCellAutoHeight(void);
	virtual TcxVerticalGridCustomizingClass __fastcall GetCustomizingClass(void);
	virtual TcxCustomRowClass __fastcall GetEditorRowClass(void);
	virtual TcxCustomRowClass __fastcall GetMultiEditorRowClass(void);
	virtual int __fastcall GetRowContentStyleIndex(TcxCustomEditorRowProperties* AProperties, int ARecordIndex);
	virtual TcxvgCustomScrollStrategyClass __fastcall GetScrollStrategyClass(void) = 0 ;
	virtual void __fastcall InitDataController(void);
	void __fastcall PaintStyleChanged(void);
	void __fastcall RemoveRowFromVerticalGrid(TcxCustomRow* ARow);
	virtual void __fastcall RowsChanged(void);
	void __fastcall SetCustomization(bool AActive);
	virtual void __fastcall UpdateDesignEditor(void);
	void __fastcall ValidateFocusedRow(void);
	__property Vcl::Graphics::TFont* CategoryFont = {read=FCategoryFont};
	__property TcxvgController* Controller = {read=GetController};
	__property TcxVerticalGridCustomizing* Customizing = {read=FCustomizing, write=FCustomizing};
	__property TcxCustomRowHeaderInfo* DragHeaderInfo = {read=GetDragHeaderInfo};
	__property int LeftVisibleRecord = {read=GetLeftVisibleRecord, write=SetLeftVisibleRecord, nodefault};
	__property TcxvgPainter* Painter = {read=GetPainter};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property TcxCustomRow* RootRow = {read=FRootRow};
	__property System::Classes::TNotifyEvent OnCustomizationFormVisibleChanged = {read=FOnCustomizationVisibleChanged, write=FOnCustomizationVisibleChanged};
	__property TcxVerticalGridDrawBackgroundEvent OnDrawBackground = {read=FOnDrawBackground, write=FOnDrawBackground};
	__property TcxVerticalGridDrawHeaderEvent OnDrawRowHeader = {read=FOnDrawRowHeader, write=FOnDrawRowHeader};
	__property TcxVerticalGridDrawValueEvent OnDrawValue = {read=FOnDrawValue, write=FOnDrawValue};
	__property TcxVerticalGridChangedEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property TcxVerticalGridEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property TcxVerticalGridChangedEvent OnEditValueChanged = {read=FOnEditValueChanged, write=FOnEditValueChanged};
	__property TcxVerticalGridItemChangedEvent OnItemChanged = {read=FOnItemChanged, write=FOnItemChanged};
	__property System::Classes::TNotifyEvent OnLayoutChanged = {read=FOnLayoutChanged, write=FOnLayoutChanged};
	__property System::Classes::TNotifyEvent OnLeftVisibleBandIndexChanged = {read=FOnLeftVisibleBandIndexChanged, write=FOnLeftVisibleBandIndexChanged};
	__property System::Classes::TNotifyEvent OnLeftVisibleRecordIndexChanged = {read=FOnLeftVisibleRecordIndexChanged, write=FOnLeftVisibleRecordIndexChanged};
	__property System::Classes::TNotifyEvent OnTopRowIndexChanged = {read=FOnTopRowIndexChanged, write=FOnTopRowIndexChanged};
	
public:
	__fastcall virtual TcxCustomVerticalGrid(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomVerticalGrid(void);
	virtual void __fastcall Update(void);
	TcxCustomRow* __fastcall Add(TcxCustomRowClass ARowClass);
	TcxCustomRow* __fastcall AddChild(TcxCustomRow* AParent, TcxCustomRowClass ARowClass);
	virtual void __fastcall AssignRows(TcxCustomVerticalGrid* Source);
	void __fastcall ClearRows(void);
	TcxCustomRow* __fastcall FirstRow(void);
	TcxCustomRow* __fastcall FirstVisibleRow(void);
	void __fastcall FocusRow(TcxCustomRow* ARow, int ACellIndex = 0x0);
	void __fastcall FullCollapse(void);
	void __fastcall FullExpand(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	bool __fastcall HasRows(void);
	bool __fastcall HasVisibleRows(void);
	bool __fastcall IsInternalDragging(System::TObject* ADragObject);
	bool __fastcall IsRowVisible(TcxCustomRow* ARow);
	TcxCustomRow* __fastcall LastRow(void);
	TcxCustomRow* __fastcall LastVisibleRow(void);
	TcxCustomRow* __fastcall NextRow(TcxCustomRow* ARow);
	TcxCustomRow* __fastcall NextVisibleRow(TcxCustomRow* ARow);
	TcxCustomRow* __fastcall PrevRow(TcxCustomRow* ARow);
	TcxCustomRow* __fastcall PrevVisibleRow(TcxCustomRow* ARow);
	HIDESBASE void __fastcall Remove(TcxCustomRow* ARow);
	TcxCustomRow* __fastcall RowByCaption(const System::UnicodeString ACaption);
	TcxCustomRow* __fastcall RowByName(const System::UnicodeString AName);
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName);
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName);
	void __fastcall RestoreFromStream(System::Classes::TStream* AStream);
	void __fastcall StoreToIniFile(const System::UnicodeString AStorageName, bool AReCreate = true);
	void __fastcall StoreToRegistry(const System::UnicodeString AStorageName, bool AReCreate = true);
	void __fastcall StoreToStream(System::Classes::TStream* AStream);
	void __fastcall CancelEdit(void);
	void __fastcall HideEdit(void);
	void __fastcall ShowEdit(void);
	void __fastcall ShowEditByKey(System::WideChar AKey);
	void __fastcall ShowEditByMouse(int X, int Y, System::Classes::TShiftState AShift);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxCustomRow* FocusedRow = {read=GetFocusedRow, write=SetFocusedRow};
	__property TcxvgHitTest* HitTest = {read=GetHitTest};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property Cxedit::TcxCustomEdit* InplaceEditor = {read=GetInplaceEditor};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property int LeftVisibleBand = {read=GetLeftVisibleBand, write=SetLeftVisibleBand, nodefault};
	__property LookAndFeel;
	__property TcxvgOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property OptionsData;
	__property TcxvgOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxVerticalGridRows* Rows = {read=FRows, write=FRows};
	__property System::UnicodeString StoringName = {read=FStoringName, write=FStoringName};
	__property TcxVerticalGridStyles* Styles = {read=GetStyles, write=SetStyles};
	__property int TopVisibleRowIndex = {read=GetTopVisibleRowIndex, write=SetTopVisibleRowIndex, nodefault};
	__property TcxvgCustomViewInfo* ViewInfo = {read=GetViewInfo};
	
__published:
	__property System::Classes::TNotifyEvent StylesEvents = {read=FStylesEvents, write=FStylesEvents};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomVerticalGrid(HWND ParentWindow) : Cxinplacecontainer::TcxExtEditingControl(ParentWindow) { }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
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
	// {6AF48CD0-3A0B-4BEC-AC88-5D323432A686}
	operator Cxstorage::_di_IcxStoredParent()
	{
		Cxstorage::_di_IcxStoredParent intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredParent*(void) { return (Cxstorage::IcxStoredParent*)&__IcxStoredParent; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	
};


class DELPHICLASS TcxUnboundVerticalGrid;
class PASCALIMPLEMENTATION TcxUnboundVerticalGrid : public TcxCustomVerticalGrid
{
	typedef TcxCustomVerticalGrid inherited;
	
private:
	TcxvgUnboundLayoutStyle FLayoutStyle;
	void __fastcall SetLayoutStyle(TcxvgUnboundLayoutStyle Value);
	
protected:
	virtual bool __fastcall CanBandSizing(void);
	virtual TcxvgCustomScrollStrategyClass __fastcall GetScrollStrategyClass(void);
	virtual Cxinplacecontainer::TcxCustomControlViewInfoClass __fastcall GetViewInfoClass(void);
	__property TcxvgUnboundLayoutStyle LayoutStyle = {read=FLayoutStyle, write=SetLayoutStyle, default=1};
	
public:
	__fastcall virtual TcxUnboundVerticalGrid(System::Classes::TComponent* AOwner);
public:
	/* TcxCustomVerticalGrid.Destroy */ inline __fastcall virtual ~TcxUnboundVerticalGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxUnboundVerticalGrid(HWND ParentWindow) : TcxCustomVerticalGrid(ParentWindow) { }
	
};


__interface IcxVGridDesignerRows;
typedef System::DelphiInterface<IcxVGridDesignerRows> _di_IcxVGridDesignerRows;
__interface  INTERFACE_UUID("{D77CC392-984F-4C1E-A41C-A341FEAC93EB}") IcxVGridDesignerRows  : public System::IInterface 
{
	
public:
	virtual TcxCustomRowClass __fastcall GetEditorRowClass(void) = 0 ;
	virtual TcxCustomRowClass __fastcall GetMultiEditorRowClass(void) = 0 ;
};

class DELPHICLASS TcxVerticalGrid;
class PASCALIMPLEMENTATION TcxVerticalGrid : public TcxUnboundVerticalGrid
{
	typedef TcxUnboundVerticalGrid inherited;
	
public:
	__property Customizing;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=0};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Images;
	__property LayoutStyle = {default=1};
	__property LookAndFeel;
	__property OptionsView;
	__property OptionsBehavior;
	__property OptionsData;
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnCustomizationFormVisibleChanged;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawBackground;
	__property OnDrawRowHeader;
	__property OnDrawValue;
	__property OnEdited;
	__property OnEditing;
	__property OnEditValueChanged;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnInitEdit;
	__property OnInitEditValue;
	__property OnItemChanged;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnLayoutChanged;
	__property OnLeftVisibleBandIndexChanged;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnTopRowIndexChanged;
public:
	/* TcxUnboundVerticalGrid.Create */ inline __fastcall virtual TcxVerticalGrid(System::Classes::TComponent* AOwner) : TcxUnboundVerticalGrid(AOwner) { }
	
public:
	/* TcxCustomVerticalGrid.Destroy */ inline __fastcall virtual ~TcxVerticalGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxVerticalGrid(HWND ParentWindow) : TcxUnboundVerticalGrid(ParentWindow) { }
	
private:
	void *__IcxVGridDesignerRows;	/* IcxVGridDesignerRows */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D77CC392-984F-4C1E-A41C-A341FEAC93EB}
	operator _di_IcxVGridDesignerRows()
	{
		_di_IcxVGridDesignerRows intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxVGridDesignerRows*(void) { return (IcxVGridDesignerRows*)&__IcxVGridDesignerRows; }
	#endif
	
};


typedef void __fastcall (__closure *TcxVerticalGridFocusedRecordChangedEvent)(TcxVirtualVerticalGrid* Sender, int APrevFocusedRecord, int AFocusedRecord);

__interface IcxVerticalGridDBDataContoller;
typedef System::DelphiInterface<IcxVerticalGridDBDataContoller> _di_IcxVerticalGridDBDataContoller;
__interface  INTERFACE_UUID("{947072DE-3531-4010-8C44-D243FD289FDF}") IcxVerticalGridDBDataContoller  : public System::IInterface 
{
	
public:
	virtual void __fastcall CheckGridModeBufferCount(void) = 0 ;
	virtual bool __fastcall DoScroll(bool AForward) = 0 ;
	virtual int __fastcall GetDataSetRecordCount(void) = 0 ;
	virtual int __fastcall GetScrollBarPos(void) = 0 ;
	virtual int __fastcall GetScrollBarRecordCount(void) = 0 ;
	virtual bool __fastcall SetScrollBarPos(int APos) = 0 ;
};

class PASCALIMPLEMENTATION TcxVirtualVerticalGrid : public TcxCustomVerticalGrid
{
	typedef TcxCustomVerticalGrid inherited;
	
private:
	Cxnavigator::TcxNavigatorControlNotifier* FNavigatorNotifier;
	TcxvgLayoutStyle FLayoutStyle;
	System::Classes::TNotifyEvent FOnFilterControlDialogShow;
	TcxVerticalGridFocusedRecordChangedEvent FOnFocusedRecordChanged;
	void __fastcall ApplyFilter(System::TObject* Sender);
	TcxCustomEditorRowProperties* __fastcall GetFilterElementProperties(int AIndex);
	Cxcustomdata::TcxDataFilterRecordEvent __fastcall GetFilterRecordEvent(void);
	int __fastcall GetFocusedRecordIndex(void);
	HIDESBASE TcxvgMultiRecordsController* __fastcall GetController(void);
	HIDESBASE TcxvgMultiRecordsOptionsBehavior* __fastcall GetOptionsBehavior(void);
	HIDESBASE TcxvgMultiRecordsOptionsData* __fastcall GetOptionsData(void);
	HIDESBASE TcxvgMultiRecordsOptionsView* __fastcall GetOptionsView(void);
	void __fastcall SetFilterRecordEvent(Cxcustomdata::TcxDataFilterRecordEvent Value);
	void __fastcall SetFocusedRecordIndex(int Value);
	void __fastcall SetLayoutStyle(TcxvgLayoutStyle Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxvgMultiRecordsOptionsBehavior* Value);
	HIDESBASE void __fastcall SetOptionsData(TcxvgMultiRecordsOptionsData* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxvgMultiRecordsOptionsView* Value);
	
protected:
	System::UnicodeString __fastcall GetFilterCaption(int Index);
	int __fastcall GetFilterCount(void);
	Cxfilter::TcxFilterCriteria* __fastcall GetFilterCriteria(void);
	System::UnicodeString __fastcall GetFilterFieldName(int Index);
	System::TObject* __fastcall GetFilterItemLink(int Index);
	int __fastcall GetFilterItemLinkID(int Index);
	System::UnicodeString __fastcall GetItemLinkName(int Index);
	Cxedit::TcxCustomEditProperties* __fastcall GetFilterProperties(int Index);
	Cxdatastorage::TcxValueTypeClass __fastcall GetFilterValueType(int Index);
	virtual int __fastcall NavigatorGetRecordCount(void);
	virtual int __fastcall NavigatorGetRecordIndex(void);
	bool __fastcall NavigatorCanAppend(void);
	bool __fastcall NavigatorCanDelete(void);
	bool __fastcall NavigatorCanEdit(void);
	bool __fastcall NavigatorCanInsert(void);
	bool __fastcall NavigatorIsActive(void);
	bool __fastcall NavigatorIsBof(void);
	bool __fastcall NavigatorIsBookmarkAvailable(void);
	bool __fastcall NavigatorIsEditing(void);
	bool __fastcall NavigatorIsEof(void);
	void __fastcall NavigatorClearBookmark(void);
	void __fastcall NavigatorDoAction(int AButtonIndex);
	Cxnavigator::TcxNavigatorControlNotifier* __fastcall NavigatorGetNotifier(void);
	bool __fastcall NavigatorIsActionSupported(int AButtonIndex);
	void __fastcall RefreshNavigators(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual bool __fastcall CanBandSizing(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual void __fastcall ControlUpdateData(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual void __fastcall DoFilterDialog(void);
	virtual void __fastcall DoFocusedRecordChanged(int APrevFocusedRecord, int AFocusedRecord);
	virtual bool __fastcall GetCellAutoHeight(void);
	virtual Cxinplacecontainer::TcxCustomControlControllerClass __fastcall GetControllerClass(void);
	virtual Cxnavigator::_di_IcxNavigator __fastcall GetNavigatorButtonsControl(void);
	virtual Cxinplacecontainer::TcxControlOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual TcxvgCustomScrollStrategyClass __fastcall GetScrollStrategyClass(void);
	virtual Cxinplacecontainer::TcxCustomControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall InitDataController(void);
	virtual void __fastcall DataLayoutChanged(void);
	__property TcxvgMultiRecordsController* Controller = {read=GetController};
	
public:
	__fastcall virtual TcxVirtualVerticalGrid(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Customizing;
	__property DataController;
	__property LeftVisibleRecord;
	__property int FocusedRecordIndex = {read=GetFocusedRecordIndex, write=SetFocusedRecordIndex, nodefault};
	__property RecordCount;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=0};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Images;
	__property TcxvgLayoutStyle LayoutStyle = {read=FLayoutStyle, write=SetLayoutStyle, default=1};
	__property LookAndFeel;
	__property TcxvgMultiRecordsOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxvgMultiRecordsOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxvgMultiRecordsOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	__property Navigator;
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property NavigatorEvents;
	__property OnClick;
	__property OnContextPopup;
	__property OnCustomizationFormVisibleChanged;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawBackground;
	__property OnDrawRowHeader;
	__property OnDrawValue;
	__property OnEdited;
	__property OnEditing;
	__property OnEditValueChanged;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property System::Classes::TNotifyEvent OnFilterControlDialogShow = {read=FOnFilterControlDialogShow, write=FOnFilterControlDialogShow};
	__property Cxcustomdata::TcxDataFilterRecordEvent OnFilterRecord = {read=GetFilterRecordEvent, write=SetFilterRecordEvent};
	__property TcxVerticalGridFocusedRecordChangedEvent OnFocusedRecordChanged = {read=FOnFocusedRecordChanged, write=FOnFocusedRecordChanged};
	__property OnInitEdit;
	__property OnInitEditValue;
	__property OnItemChanged;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnLayoutChanged;
	__property OnLeftVisibleBandIndexChanged;
	__property OnLeftVisibleRecordIndexChanged;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnTopRowIndexChanged;
public:
	/* TcxCustomVerticalGrid.Destroy */ inline __fastcall virtual ~TcxVirtualVerticalGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxVirtualVerticalGrid(HWND ParentWindow) : TcxCustomVerticalGrid(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
private:
	void *__IcxFilterControl;	/* Cxfiltercontrol::IcxFilterControl */
	void *__IcxNavigator;	/* Cxnavigator::IcxNavigator */
	void *__IcxVGridDesignerRows;	/* IcxVGridDesignerRows */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B9890E09-5400-428D-8F72-1FF8FD15937C}
	operator Cxfiltercontrol::_di_IcxFilterControl()
	{
		Cxfiltercontrol::_di_IcxFilterControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxfiltercontrol::IcxFilterControl*(void) { return (Cxfiltercontrol::IcxFilterControl*)&__IcxFilterControl; }
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D77CC392-984F-4C1E-A41C-A341FEAC93EB}
	operator _di_IcxVGridDesignerRows()
	{
		_di_IcxVGridDesignerRows intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxVGridDesignerRows*(void) { return (IcxVGridDesignerRows*)&__IcxVGridDesignerRows; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxRowValueInfo : public Cxinplacecontainer::TcxEditCellViewInfo
{
	typedef Cxinplacecontainer::TcxEditCellViewInfo inherited;
	
private:
	System::Types::TRect FFocusRect;
	TcxCustomRow* FRow;
	int FRowCellIndex;
	int FRecordIndex;
	TcxCustomEditorRowProperties* __fastcall GetEditorRowProperties(void);
	
protected:
	virtual void __fastcall DoCalculate(void);
	HIDESBASE TcxCellEdit* __fastcall EditContainer(void);
	virtual Cxedit::TcxEditButtonTransparency __fastcall GetButtonTransparency(void);
	virtual System::Variant __fastcall GetDisplayValue(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetEditViewParams(void);
	virtual bool __fastcall GetFocused(void);
	virtual NativeInt __fastcall GetRecordIndex(void);
	virtual int __fastcall GetSelectedTextColor(void);
	virtual int __fastcall GetSelectedBKColor(void);
	Cxgraphics::TcxViewParams __fastcall IncSearchParams(void);
	virtual bool __fastcall IsAutoHeight(void);
	__property TcxCustomEditorRowProperties* EditorRowProperties = {read=GetEditorRowProperties};
	
public:
	int __fastcall GetHeight(int AContentWidth);
	__property Focused;
	__property System::Types::TRect FocusRect = {read=FFocusRect, write=FFocusRect};
	__property TcxCustomRow* Row = {read=FRow};
	__property int RowCellIndex = {read=FRowCellIndex, nodefault};
	__property ViewParams;
public:
	/* TcxEditCellViewInfo.Destroy */ inline __fastcall virtual ~TcxRowValueInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxRowValueInfo(System::TObject* AOwner) : Cxinplacecontainer::TcxEditCellViewInfo(AOwner) { }
	
};


class DELPHICLASS TcxRowCaptionInfo;
class PASCALIMPLEMENTATION TcxRowCaptionInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FCaption;
	System::Types::TRect FCaptionRect;
	System::Types::TRect FCaptionTextRect;
	bool FFocused;
	int FImageIndex;
	System::Types::TRect FImageRect;
	Vcl::Imglist::TCustomImageList* FImages;
	TcxCustomRow* FRow;
	int FRowCellIndex;
	Cxgraphics::TcxViewParams FViewParams;
	int FTextFlags;
	System::UnicodeString __fastcall FindPropertiesHint(const System::Types::TPoint P);
	
protected:
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual System::Types::TRect __fastcall GetHintBounds(void);
	virtual bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint);
	void __fastcall UpdateHotTrackState(const System::Types::TPoint APoint);
	bool __fastcall HasHintPoint(const System::Types::TPoint P);
	bool __fastcall IsHintAtMousePos(void);
	bool __fastcall UseHintHidePause(void);
	
public:
	__fastcall virtual TcxRowCaptionInfo(void);
	__fastcall virtual ~TcxRowCaptionInfo(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property System::Types::TRect CaptionTextRect = {read=FCaptionTextRect};
	__property bool Focused = {read=FFocused, nodefault};
	__property int ImageIndex = {read=FImageIndex, nodefault};
	__property System::Types::TRect ImageRect = {read=FImageRect};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages};
	__property TcxCustomRow* Row = {read=FRow};
	__property int RowCellIndex = {read=FRowCellIndex, write=FRowCellIndex, nodefault};
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams};
	__property int TextFlags = {read=FTextFlags, nodefault};
private:
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	void *__IcxHotTrackElement;	/* Cxinplacecontainer::IcxHotTrackElement */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {228FF1F5-6D0C-40F0-9F7B-8C71CE12CEC8}
	operator Dxcustomhint::_di_IcxHintableObject()
	{
		Dxcustomhint::_di_IcxHintableObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomhint::IcxHintableObject*(void) { return (Dxcustomhint::IcxHintableObject*)&__IcxHintableObject; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E7171E58-276E-499B-9DDF-298D850883C9}
	operator Cxinplacecontainer::_di_IcxHotTrackElement()
	{
		Cxinplacecontainer::_di_IcxHotTrackElement intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxinplacecontainer::IcxHotTrackElement*(void) { return (Cxinplacecontainer::IcxHotTrackElement*)&__IcxHotTrackElement; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxHintableObject; }
	#endif
	
};


class DELPHICLASS TcxCaptionInfoList;
class PASCALIMPLEMENTATION TcxCaptionInfoList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxRowCaptionInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxRowCaptionInfo* __fastcall GetItem(int Index);
	
public:
	__property TcxRowCaptionInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxCaptionInfoList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxCaptionInfoList(void) { }
	
};


class DELPHICLASS TcxValueInfoList;
class PASCALIMPLEMENTATION TcxValueInfoList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxRowValueInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxvgCustomViewInfo* FViewInfo;
	HIDESBASE TcxRowValueInfo* __fastcall GetItem(int Index);
	
public:
	__fastcall TcxValueInfoList(TcxvgCustomViewInfo* AViewInfo);
	__fastcall virtual ~TcxValueInfoList(void);
	__property TcxRowValueInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxvgCustomViewInfo* ViewInfo = {read=FViewInfo};
};


class PASCALIMPLEMENTATION TcxCustomRowHeaderInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCaptionInfoList* FCaptionsInfo;
	Cxvgridutils::TIndentInfoList* FCategoryIndents;
	System::Types::TRect FFocusRect;
	Cxvgridutils::TLineInfoList* FLinesInfo;
	Cxvgridutils::TIndentInfoList* FRowIndents;
	bool FTransparent;
	TcxvgCustomViewInfo* FViewInfo;
	TcxvgPaintStyle __fastcall GetPaintStyle(void);
	bool __fastcall GetSelected(void);
	bool __fastcall GetShowButton(void);
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	System::Types::TRect FButtonAreaBounds;
	System::Types::TRect FButtonRect;
	System::Uitypes::TColor FButtonColor;
	bool FFocused;
	System::Types::TRect FHeaderCellsRect;
	System::Types::TRect FHeaderRect;
	System::Types::TRect FIndentBounds;
	Cxgraphics::TcxViewParams FIndentViewParams;
	TcxCustomRow* FRow;
	Cxgraphics::TcxViewParams FViewParams;
	virtual void __fastcall AddBottomHorzLine(const System::Types::TRect &R);
	virtual void __fastcall AddBoundHeaderLines(void);
	void __fastcall AddNextIndentInfo(const System::Types::TRect &ABounds, const Cxgraphics::TcxViewParams &AViewParams, bool AToCategories, bool AUnderline, bool AAddVertLine);
	virtual void __fastcall AddRightVertLine(const System::Types::TRect &R);
	void __fastcall Calc(const System::Types::TRect &AHeaderRect, TcxvgCustomViewInfo* AViewInfo, TcxCustomRow* ANextRow, bool ACalcBounds);
	TcxRowCaptionInfo* __fastcall CalcCaptionInfo(TcxCaptionRowProperties* ARowProperties, const System::Types::TRect &R);
	virtual void __fastcall CalcIndentBounds(TcxCustomRow* ANextRow, bool ACalculate);
	virtual Cxvgridutils::TIndentRectInfoList* __fastcall CalcIndentsInfo(int ALevelCount, TcxCustomRow* ANextRow);
	void __fastcall CalcExpandButton(void);
	virtual void __fastcall CalcRowCaptionsInfo(void);
	virtual void __fastcall CalcViewParams(bool AAllowFocus);
	virtual void __fastcall Clear(void);
	virtual void __fastcall DoCalcExpandButton(void);
	virtual int __fastcall GetButtonPlaceBackgroundWidth(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetCaptionViewParams(void);
	virtual System::Uitypes::TColor __fastcall GetButtonColor(void);
	virtual System::Types::TRect __fastcall GetFocusRect(void);
	int __fastcall GetTopCentralPoint(int AHeight, const System::Types::TRect &R);
	virtual bool __fastcall IncreaseBoundsByLastVertLine(void);
	virtual int __fastcall LeftViewPoint(void);
	void __fastcall Recalculate(TcxCustomRow* ANextRow, bool ACalcBounds);
	__property Cxgraphics::TcxViewParams IndentViewParams = {read=FIndentViewParams};
	__property TcxvgPaintStyle PaintStyle = {read=GetPaintStyle, nodefault};
	__property bool Selected = {read=GetSelected, nodefault};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	__property TcxvgCustomViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxCustomRowHeaderInfo(TcxCustomRow* ARow);
	__fastcall virtual ~TcxCustomRowHeaderInfo(void);
	__property TcxCaptionInfoList* CaptionsInfo = {read=FCaptionsInfo};
	__property Cxvgridutils::TIndentInfoList* CategoryIndents = {read=FCategoryIndents};
	__property System::Types::TRect ButtonAreaBounds = {read=FButtonAreaBounds};
	__property System::Types::TRect ButtonRect = {read=FButtonRect};
	__property System::Uitypes::TColor ButtonColor = {read=FButtonColor, nodefault};
	__property bool Focused = {read=FFocused, nodefault};
	__property System::Types::TRect FocusRect = {read=FFocusRect, write=FFocusRect};
	__property System::Types::TRect HeaderCellsRect = {read=FHeaderCellsRect};
	__property System::Types::TRect HeaderRect = {read=FHeaderRect, write=FHeaderRect};
	__property System::Types::TRect IndentBounds = {read=FIndentBounds};
	__property Cxvgridutils::TLineInfoList* LinesInfo = {read=FLinesInfo};
	__property TcxCustomRow* Row = {read=FRow};
	__property Cxvgridutils::TIndentInfoList* RowIndents = {read=FRowIndents};
	__property bool ShowButton = {read=GetShowButton, nodefault};
	__property bool Transparent = {read=FTransparent, write=FTransparent, nodefault};
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams, write=FViewParams};
};


class PASCALIMPLEMENTATION TcxCustomRowViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FBandIndex;
	int FBandRowIndex;
	int FCalculatedHeight;
	TcxCustomRowHeaderInfo* FHeaderInfo;
	bool FInitialized;
	TcxCustomRow* FRow;
	System::Types::TRect FRowRect;
	TcxValueInfoList* FValuesInfo;
	Cxvgridutils::TLineInfoList* FValuesLinesInfo;
	System::Types::TRect FValuesRect;
	int __fastcall GetCalculatedHeight(void);
	TcxRowValueInfo* __fastcall GetRowValueInfo(int ARecordIndex, int ACellIndex);
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	TcxvgCustomViewInfo* __fastcall GetViewInfo(void);
	
protected:
	void __fastcall AddRectValueLines(System::Types::TRect &R, bool ALast, bool ABottomLineNeeded);
	TcxRowValueInfo* __fastcall AddValueInfo(int ARecordIndex, int ACellIndex);
	virtual void __fastcall CalculateHeight(int ABandWidth);
	virtual void __fastcall CalcValuesInfo(void);
	virtual void __fastcall CalcRowHeaderInfo(TcxCustomRow* ANextRow);
	virtual void __fastcall CalcPaintViewParamsLines(TcxCustomRow* ANextRow);
	void __fastcall ClearValuesInfo(void);
	int __fastcall GetEditContainerCount(void);
	virtual TcxRowValueInfoClass __fastcall GetRowValueInfoClass(void);
	virtual int __fastcall GetValuesHeight(int ABandWidth, TcxvgCustomViewInfo* AViewInfo);
	void __fastcall InitValuesInfo(void);
	__property TcxValueInfoList* ValuesInfo = {read=FValuesInfo};
	__property TcxvgCustomViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomRowViewInfo(TcxCustomRow* ARow);
	__fastcall virtual ~TcxCustomRowViewInfo(void);
	void __fastcall Calc(const System::Types::TRect &ARowRect, TcxvgCustomViewInfo* AViewInfo, TcxCustomRow* ANextRow);
	void __fastcall Recalculate(TcxCustomRow* ANextRow);
	void __fastcall Update(void);
	void __fastcall UpdateRecord(int ARecordIndex);
	__property int BandIndex = {read=FBandIndex, write=FBandIndex, nodefault};
	__property int BandRowIndex = {read=FBandRowIndex, write=FBandRowIndex, nodefault};
	__property int CalculatedHeight = {read=GetCalculatedHeight, write=FCalculatedHeight, nodefault};
	__property TcxCustomRowHeaderInfo* HeaderInfo = {read=FHeaderInfo};
	__property TcxCustomRow* Row = {read=FRow};
	__property System::Types::TRect RowRect = {read=FRowRect};
	__property TcxRowValueInfo* RowValueInfo[int ARecordIndex][int ACellIndex] = {read=GetRowValueInfo};
	__property Cxvgridutils::TLineInfoList* ValuesLinesInfo = {read=FValuesLinesInfo};
	__property System::Types::TRect ValuesRect = {read=FValuesRect, write=FValuesRect};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
};


class DELPHICLASS TcxRowViewInfoList;
class PASCALIMPLEMENTATION TcxRowViewInfoList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TcxCustomRowViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomRowViewInfo* __fastcall GetItem(int Index);
	
public:
	__fastcall TcxRowViewInfoList(void);
	TcxCustomRowViewInfo* __fastcall Find(TcxCustomRow* ARow);
	__property TcxCustomRowViewInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxRowViewInfoList(void) { }
	
};


class DELPHICLASS TcxvgCustomPaintStyleCalcHelper;
class PASCALIMPLEMENTATION TcxvgCustomViewInfo : public Cxinplacecontainer::TcxExtEditingControlViewInfo
{
	typedef Cxinplacecontainer::TcxExtEditingControlViewInfo inherited;
	
private:
	System::Uitypes::TColor FBandBorderColor;
	int FBandMinWidth;
	int FBandsInterval;
	int FButtonAreaSize;
	int FButtonSize;
	TcxvgCustomPaintStyleCalcHelper* FCalcHelper;
	System::Types::TRect FClipRect;
	int FDividerWidth;
	System::Types::TSize FExplorerButtonAreaSize;
	System::Types::TSize FExplorerButtonSize;
	bool FUseCategoryExplorerStyle;
	Cxvgridutils::TLineInfoList* FFocusLinesInfo;
	int FFullHeaderWidth;
	Vcl::Graphics::TBrush* FHorzLineBrush;
	int FHorzLineWidth;
	System::Types::TSize FImageSize;
	int FLevelWidth;
	Cxvgridutils::TLineInfoList* FLinesInfo;
	bool FLockDividerPos;
	int FRowHeaderMinWidth;
	int FRowIndentWidth;
	TcxRowViewInfoList* FRowsViewInfo;
	bool FShowHeaders;
	TcxCustomVerticalGrid* FVerticalGrid;
	Vcl::Graphics::TBrush* FVertLineBrush;
	int FVertLineWidth;
	int FViewBandWidth;
	int FViewHeaderWidth;
	int FViewValueWidth;
	Cxvgridutils::TViewRects* FViewRects;
	void __fastcall ClearLinesAndRows(void);
	TBandInfoList* __fastcall GetBandInfo(void);
	int __fastcall GetFirstVisibleRecordIndex(void);
	int __fastcall GetMinRowHeight(void);
	TcxvgPainter* __fastcall GetPainter(void);
	TcxvgScroller* __fastcall GetScroller(void);
	TcxCustomRow* __fastcall GetVisibleRow(int Index);
	int __fastcall GetVisibleRowCount(void);
	void __fastcall UpdateScroller(void);
	int __fastcall GetMaxVisibleLevel(void);
	
protected:
	virtual int __fastcall CalculateDefaultEditHeight(void);
	virtual void __fastcall DoCalculate(void);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint APoint);
	virtual void __fastcall UpdateSelection(void);
	virtual void __fastcall AddBandRowsLines(const System::Types::TRect &R);
	void __fastcall AddBottomValueSide(TcxCustomRowViewInfo* ARowViewInfo, const System::Types::TRect &R);
	virtual void __fastcall AddEmptyRects(void) = 0 ;
	virtual void __fastcall AddRightValueSide(TcxCustomRowViewInfo* ARowViewInfo, const System::Types::TRect &R, bool ALast);
	virtual void __fastcall CalcBandRects(void);
	virtual void __fastcall CalcBandRowsViewInfo(int &AFirstRowIndex, const System::Types::TRect &ABandRect, int ABandIndex, int ABandRowCount);
	virtual void __fastcall CalcBandWidth(void);
	virtual void __fastcall CalculateBandsInfo(void);
	virtual void __fastcall CalcEmpty(void);
	void __fastcall CalcCategoryExplorerStyle(void);
	virtual void __fastcall CalcLayoutGeneral(void);
	void __fastcall CalcRowsHeight(void);
	virtual void __fastcall CalcRowRects(TcxCustomRowViewInfo* ARowViewInfo);
	virtual void __fastcall CalcRowsViewInfo(void);
	virtual void __fastcall CalcViewRects(void);
	virtual bool __fastcall CanAddRowToBand(const System::Types::TRect &ARowRect, const System::Types::TRect &ABandRect, int ABandRowIndex);
	virtual void __fastcall CheckMaxRowHeaderWidth(int &Value, int AValueMinWidth);
	void __fastcall CheckRowHeaderWidth(void);
	bool __fastcall CheckShowRowHeader(TcxCustomRowViewInfo* ARowViewInfo);
	virtual void __fastcall Clear(void);
	void __fastcall ClearValuesInfo(void);
	virtual void __fastcall CreateBand(int ABandHeight, int ABandWidth);
	virtual void __fastcall CreateBrushes(void);
	virtual TcxvgCustomPaintStyleCalcHelper* __fastcall CreateCalcHelper(void);
	virtual void __fastcall DestroyBrushes(void);
	virtual System::Types::TRect __fastcall GetBandSizeableRect(const System::Types::TRect &ABandRect);
	virtual bool __fastcall GetRowAutoHeight(TcxCustomRow* ARow);
	virtual int __fastcall GetViewBandWidth(void);
	virtual int __fastcall GetViewHeaderWidth(void);
	virtual int __fastcall GetViewMinHeaderWidth(void);
	virtual int __fastcall GetViewValueWidth(void);
	virtual int __fastcall GetVisibleValueCount(void) = 0 ;
	void __fastcall LayoutStyleChanged(void);
	void __fastcall PrepareCalculateBandsInfo(void);
	virtual void __fastcall Reset(void);
	virtual Cxvgridutils::TRectScaler* __fastcall ScaleRowRects(TcxCustomRowViewInfo* ARowViewInfo);
	virtual void __fastcall SetDividerPos(int APos);
	virtual void __fastcall SetValueWidth(int AWidth);
	__property TcxvgScroller* Scroller = {read=GetScroller};
	__property bool LockDividerPos = {read=FLockDividerPos, nodefault};
	__property int MaxVisibleLevel = {read=GetMaxVisibleLevel, nodefault};
	__property int ViewBandWidth = {read=FViewBandWidth, write=FViewBandWidth, nodefault};
	__property int ViewHeaderWidth = {read=FViewHeaderWidth, write=FViewHeaderWidth, nodefault};
	
public:
	__fastcall virtual TcxvgCustomViewInfo(Cxinplacecontainer::TcxEditingControl* AOwner);
	__fastcall virtual ~TcxvgCustomViewInfo(void);
	virtual void __fastcall CalcEditCell(const System::Types::TRect &ABounds, TcxRowValueInfo* ARowValueInfo);
	int __fastcall CalcRowHeight(TcxCustomRow* ARow);
	virtual void __fastcall ChangeFocusedRow(TcxCustomRow* ANewFocus, TcxCustomRow* AOldFocus);
	virtual int __fastcall GetDefaultGridModeBufferCount(void);
	TcxCustomRowViewInfo* __fastcall GetRowViewInfo(TcxCustomRow* ARow);
	virtual System::Types::TRect __fastcall GetValueRect(int AValueIndex, TcxCustomRowViewInfo* ARowViewInfo);
	virtual System::Types::TRect __fastcall GetValuesRect(TcxCustomRowViewInfo* ARowViewInfo);
	virtual void __fastcall UpdateRecord(int ARecordIndex);
	__property System::Uitypes::TColor BandBorderColor = {read=FBandBorderColor, write=FBandBorderColor, nodefault};
	__property int BandMinWidth = {read=FBandMinWidth, nodefault};
	__property TBandInfoList* BandInfo = {read=GetBandInfo};
	__property int BandsInterval = {read=FBandsInterval, nodefault};
	__property int ButtonAreaSize = {read=FButtonAreaSize, write=FButtonAreaSize, nodefault};
	__property int ButtonSize = {read=FButtonSize, write=FButtonSize, nodefault};
	__property TcxvgCustomPaintStyleCalcHelper* CalcHelper = {read=FCalcHelper};
	__property System::Types::TRect ClipRect = {read=FClipRect};
	__property int DividerWidth = {read=FDividerWidth, write=FDividerWidth, nodefault};
	__property System::Types::TSize ExplorerButtonAreaSize = {read=FExplorerButtonAreaSize};
	__property System::Types::TSize ExplorerButtonSize = {read=FExplorerButtonSize};
	__property bool UseCategoryExplorerStyle = {read=FUseCategoryExplorerStyle, nodefault};
	__property int FirstVisibleRecordIndex = {read=GetFirstVisibleRecordIndex, nodefault};
	__property Cxvgridutils::TLineInfoList* FocusLinesInfo = {read=FFocusLinesInfo};
	__property int FullHeaderWidth = {read=FFullHeaderWidth, nodefault};
	__property Vcl::Graphics::TBrush* HorzLineBrush = {read=FHorzLineBrush, write=FHorzLineBrush};
	__property int HorzLineWidth = {read=FHorzLineWidth, nodefault};
	__property System::Types::TSize ImageSize = {read=FImageSize, write=FImageSize};
	__property int LevelWidth = {read=FLevelWidth, write=FLevelWidth, nodefault};
	__property Cxvgridutils::TLineInfoList* LinesInfo = {read=FLinesInfo, write=FLinesInfo};
	__property TcxvgPainter* Painter = {read=GetPainter};
	__property int RowHeaderMinWidth = {read=FRowHeaderMinWidth, nodefault};
	__property int RowIndentWidth = {read=FRowIndentWidth, nodefault};
	__property TcxRowViewInfoList* RowsViewInfo = {read=FRowsViewInfo};
	__property bool ShowHeaders = {read=FShowHeaders, nodefault};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=FVerticalGrid};
	__property Vcl::Graphics::TBrush* VertLineBrush = {read=FVertLineBrush, write=FVertLineBrush};
	__property int VertLineWidth = {read=FVertLineWidth, write=FVertLineWidth, nodefault};
	__property Cxvgridutils::TViewRects* ViewRects = {read=FViewRects};
	__property int ViewValueWidth = {read=FViewValueWidth, write=FViewValueWidth, nodefault};
	__property TcxCustomRow* VisibleRows[int Index] = {read=GetVisibleRow};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	__property int VisibleValueCount = {read=GetVisibleValueCount, nodefault};
};


class PASCALIMPLEMENTATION TcxvgCustomPaintStyleCalcHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxvgScroller* FScroller;
	TcxvgCustomViewInfo* FViewInfo;
	TcxCustomVerticalGrid* FVerticalGrid;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	virtual Vcl::Graphics::TBrush* __fastcall CreateHorzLineBrush(void) = 0 ;
	virtual Vcl::Graphics::TBrush* __fastcall CreateVertLineBrush(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetBandBorderColor(void);
	virtual int __fastcall GetDividerWidth(void) = 0 ;
	virtual int __fastcall GetIndentWidth(void) = 0 ;
	
public:
	__fastcall virtual TcxvgCustomPaintStyleCalcHelper(TcxvgCustomViewInfo* AViewInfo);
	virtual void __fastcall AddBoundHeaderLines(TcxCustomRowHeaderInfo* ARowHeaderInfo) = 0 ;
	virtual void __fastcall AddDivider(Cxvgridutils::TLineInfoList* ALinesInfo, const System::Types::TRect &R, System::Uitypes::TColor AColor, bool AIsSeparator) = 0 ;
	virtual void __fastcall AddHeaderIndentLines(TcxCustomRowHeaderInfo* ARowHeaderInfo, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AToCategories, bool AUnderline, bool AAddVertLine) = 0 ;
	virtual void __fastcall CalcPaintViewParamsLines(TcxCustomRowViewInfo* ARowViewInfo, TcxCustomRow* ANextRow) = 0 ;
	virtual System::Types::TRect __fastcall ChangeFocusedRow(TcxCustomRow* ANewFocus, TcxCustomRow* AOldFocus) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetCategoryColor(void) = 0 ;
	virtual System::Types::TRect __fastcall GetCategoryFocusRect(TcxCustomRowHeaderInfo* ARowHeaderInfo) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetCategoryTextColor(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetContentColor(bool AFocused) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetContentTextColor(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetContentEvenColor(bool AFocused);
	virtual System::Uitypes::TColor __fastcall GetContentEvenTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetContentOddColor(bool AFocused);
	virtual System::Uitypes::TColor __fastcall GetContentOddTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderColor(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetHeaderTextColor(void) = 0 ;
	virtual Cxgraphics::TcxViewParams __fastcall GetIndentViewParams(TcxCustomRow* ARow, TcxCustomRow* AParentIndentRow) = 0 ;
	virtual bool __fastcall IsBottomLineNeeded(TcxCustomRow* ANextRow);
	virtual bool __fastcall IsDrawValueFocusRect(void) = 0 ;
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxvgScroller* Scroller = {read=FScroller};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=FVerticalGrid};
	__property TcxvgCustomViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxvgCustomPaintStyleCalcHelper(void) { }
	
};


class DELPHICLASS TcxvgDotNetStyleCalcHelper;
class PASCALIMPLEMENTATION TcxvgDotNetStyleCalcHelper : public TcxvgCustomPaintStyleCalcHelper
{
	typedef TcxvgCustomPaintStyleCalcHelper inherited;
	
protected:
	virtual Vcl::Graphics::TBrush* __fastcall CreateHorzLineBrush(void);
	virtual Vcl::Graphics::TBrush* __fastcall CreateVertLineBrush(void);
	virtual int __fastcall GetDividerWidth(void);
	virtual int __fastcall GetIndentWidth(void);
	
public:
	virtual void __fastcall AddBoundHeaderLines(TcxCustomRowHeaderInfo* ARowHeaderInfo);
	virtual void __fastcall AddDivider(Cxvgridutils::TLineInfoList* ALinesInfo, const System::Types::TRect &R, System::Uitypes::TColor AColor, bool AIsSeparator);
	virtual void __fastcall AddHeaderIndentLines(TcxCustomRowHeaderInfo* ARowHeaderInfo, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AToCategories, bool AUnderline, bool AAddVertLine);
	virtual void __fastcall CalcPaintViewParamsLines(TcxCustomRowViewInfo* ARowViewInfo, TcxCustomRow* ANextRow);
	virtual System::Types::TRect __fastcall ChangeFocusedRow(TcxCustomRow* ANewFocus, TcxCustomRow* AOldFocus);
	virtual System::Uitypes::TColor __fastcall GetCategoryColor(void);
	virtual System::Types::TRect __fastcall GetCategoryFocusRect(TcxCustomRowHeaderInfo* ARowHeaderInfo);
	virtual System::Uitypes::TColor __fastcall GetCategoryTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetContentColor(bool AFocused);
	virtual System::Uitypes::TColor __fastcall GetContentTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderTextColor(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetIndentViewParams(TcxCustomRow* ARow, TcxCustomRow* AParentIndentRow);
	virtual bool __fastcall IsDrawValueFocusRect(void);
public:
	/* TcxvgCustomPaintStyleCalcHelper.Create */ inline __fastcall virtual TcxvgDotNetStyleCalcHelper(TcxvgCustomViewInfo* AViewInfo) : TcxvgCustomPaintStyleCalcHelper(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxvgDotNetStyleCalcHelper(void) { }
	
};


class DELPHICLASS TcxvgStyle3DCalcHelper;
class PASCALIMPLEMENTATION TcxvgStyle3DCalcHelper : public TcxvgCustomPaintStyleCalcHelper
{
	typedef TcxvgCustomPaintStyleCalcHelper inherited;
	
protected:
	virtual Vcl::Graphics::TBrush* __fastcall CreateHorzLineBrush(void);
	virtual Vcl::Graphics::TBrush* __fastcall CreateVertLineBrush(void);
	virtual int __fastcall GetDividerWidth(void);
	virtual int __fastcall GetIndentWidth(void);
	
public:
	virtual void __fastcall AddBoundHeaderLines(TcxCustomRowHeaderInfo* ARowHeaderInfo);
	virtual void __fastcall AddHeaderIndentLines(TcxCustomRowHeaderInfo* ARowHeaderInfo, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AToCategories, bool AUnderline, bool AAddVertLine);
	virtual void __fastcall AddDivider(Cxvgridutils::TLineInfoList* ALinesInfo, const System::Types::TRect &R, System::Uitypes::TColor AColor, bool AIsSeparator);
	virtual void __fastcall CalcPaintViewParamsLines(TcxCustomRowViewInfo* ARowViewInfo, TcxCustomRow* ANextRow);
	virtual System::Types::TRect __fastcall ChangeFocusedRow(TcxCustomRow* ANewFocus, TcxCustomRow* AOldFocus);
	virtual System::Uitypes::TColor __fastcall GetCategoryColor(void);
	virtual System::Types::TRect __fastcall GetCategoryFocusRect(TcxCustomRowHeaderInfo* ARowHeaderInfo);
	virtual System::Uitypes::TColor __fastcall GetCategoryTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetContentColor(bool AFocused);
	virtual System::Uitypes::TColor __fastcall GetContentTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderTextColor(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetIndentViewParams(TcxCustomRow* ARow, TcxCustomRow* AParentIndentRow);
	virtual bool __fastcall IsDrawValueFocusRect(void);
public:
	/* TcxvgCustomPaintStyleCalcHelper.Create */ inline __fastcall virtual TcxvgStyle3DCalcHelper(TcxvgCustomViewInfo* AViewInfo) : TcxvgCustomPaintStyleCalcHelper(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxvgStyle3DCalcHelper(void) { }
	
};


class DELPHICLASS TcxvgSkinCalcHelper;
class PASCALIMPLEMENTATION TcxvgSkinCalcHelper : public TcxvgDotNetStyleCalcHelper
{
	typedef TcxvgDotNetStyleCalcHelper inherited;
	
protected:
	virtual Vcl::Graphics::TBrush* __fastcall CreateHorzLineBrush(void);
	virtual Vcl::Graphics::TBrush* __fastcall CreateVertLineBrush(void);
	virtual System::Uitypes::TColor __fastcall GetBandBorderColor(void);
	
public:
	virtual void __fastcall AddBoundHeaderLines(TcxCustomRowHeaderInfo* ARowHeaderInfo);
	virtual void __fastcall AddHeaderIndentLines(TcxCustomRowHeaderInfo* ARowHeaderInfo, const System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AToCategories, bool AUnderline, bool AAddVertLine);
	virtual System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetCategoryColor(void);
	virtual System::Uitypes::TColor __fastcall GetCategoryTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetContentEvenColor(bool AFocused);
	virtual System::Uitypes::TColor __fastcall GetContentOddColor(bool AFocused);
	virtual System::Uitypes::TColor __fastcall GetHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderTextColor(void);
	virtual bool __fastcall IsBottomLineNeeded(TcxCustomRow* ANextRow);
public:
	/* TcxvgCustomPaintStyleCalcHelper.Create */ inline __fastcall virtual TcxvgSkinCalcHelper(TcxvgCustomViewInfo* AViewInfo) : TcxvgDotNetStyleCalcHelper(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxvgSkinCalcHelper(void) { }
	
};


class PASCALIMPLEMENTATION TcxvgPainter : public Cxinplacecontainer::TcxExtEditingControlPainter
{
	typedef Cxinplacecontainer::TcxExtEditingControlPainter inherited;
	
private:
	HIDESBASE TcxvgCustomViewInfo* __fastcall GetViewInfo(void);
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual void __fastcall DoPaint(void);
	void __fastcall DrawRows(void);
	virtual void __fastcall DrawStyleFeatures(void);
	bool __fastcall IsExplorerStyleCategory(/* out */ NativeUInt &ATheme);
	bool __fastcall IsNeedPaintValue(TcxRowValueInfo* AValueInfo);
	
public:
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawButton(TcxCustomRowHeaderInfo* ARowHeader);
	virtual void __fastcall DrawCategoryExplorerStyleRowHeader(TcxCustomRowHeaderInfo* ARowHeader, NativeUInt ATheme);
	virtual void __fastcall DrawCategoryRowHeader(TcxCustomRowHeaderInfo* ARowHeader);
	virtual void __fastcall DrawCategoryRowIndent(TcxCustomRowHeaderInfo* ARowHeader);
	virtual void __fastcall DrawHeaderDragImage(TcxCustomRowHeaderInfo* ARowHeader);
	virtual void __fastcall DrawHeaderSeparators(TcxCustomRowHeaderInfo* ARowHeader);
	virtual void __fastcall DrawImage(TcxRowCaptionInfo* ACaptionInfo);
	virtual void __fastcall DrawLines(Cxvgridutils::TLineInfoList* ALinesInfo, System::Types::TRect &R);
	virtual void __fastcall DrawRow(TcxCustomRowViewInfo* ARowViewInfo);
	virtual void __fastcall DrawRowHeader(TcxCustomRowHeaderInfo* ARowHeader);
	virtual void __fastcall DrawRowHeaderCell(TcxRowCaptionInfo* ACaptionInfo, bool ATransparent);
	virtual void __fastcall DrawRowIndent(TcxCustomRowHeaderInfo* ARowHeader);
	virtual void __fastcall DrawRowValueCell(TcxRowValueInfo* AValueInfo);
	virtual void __fastcall DrawRowValues(TcxCustomRowViewInfo* ARowViewInfo);
	virtual void __fastcall DrawValuesSeparators(TcxCustomRowViewInfo* ARowViewInfo);
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	__property TcxvgCustomViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomControlPainter.Create */ inline __fastcall virtual TcxvgPainter(Cxinplacecontainer::TcxEditingControl* AOwner) : Cxinplacecontainer::TcxExtEditingControlPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxvgPainter(void) { }
	
};


class DELPHICLASS TcxStyle3DPainter;
class PASCALIMPLEMENTATION TcxStyle3DPainter : public TcxvgPainter
{
	typedef TcxvgPainter inherited;
	
protected:
	virtual void __fastcall DrawStyleFeatures(void);
public:
	/* TcxCustomControlPainter.Create */ inline __fastcall virtual TcxStyle3DPainter(Cxinplacecontainer::TcxEditingControl* AOwner) : TcxvgPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStyle3DPainter(void) { }
	
};


struct TcxvgContentParamsData;
typedef TcxvgContentParamsData *PcxvgContentParamsData;

struct DECLSPEC_DRECORD TcxvgContentParamsData
{
public:
	TcxCustomEditorRowProperties* EditorRowProperties;
	bool Focused;
	int Index;
};


typedef void __fastcall (__closure *TcxvgOnGetItemStyleEvent)(System::TObject* Sender, TcxCustomRow* ARow, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxvgOnGetContentStyleEvent)(System::TObject* Sender, TcxCustomEditorRowProperties* AEditProp, bool AFocused, int ARecordIndex, Cxstyles::TcxStyle* &AStyle);

class PASCALIMPLEMENTATION TcxvgCustomRowStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__fastcall virtual TcxvgCustomRowStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetHeaderParams(TcxCustomRow* ARow);
	
__published:
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=0};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxvgCustomRowStyles(void) { }
	
};


class PASCALIMPLEMENTATION TcxCategoryRowStyles : public TcxvgCustomRowStyles
{
	typedef TcxvgCustomRowStyles inherited;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
public:
	/* TcxvgCustomRowStyles.Create */ inline __fastcall virtual TcxCategoryRowStyles(System::Classes::TPersistent* AOwner) : TcxvgCustomRowStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxCategoryRowStyles(void) { }
	
};


class PASCALIMPLEMENTATION TcxEditorRowStyles : public TcxCategoryRowStyles
{
	typedef TcxCategoryRowStyles inherited;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetContentParams(TcxCustomEditorRowProperties* AEditorRowProperties, bool AFocused, int ARecordIndex);
	
__published:
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=1};
	__property Header;
public:
	/* TcxvgCustomRowStyles.Create */ inline __fastcall virtual TcxEditorRowStyles(System::Classes::TPersistent* AOwner) : TcxCategoryRowStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxEditorRowStyles(void) { }
	
};


class DELPHICLASS TcxVerticalGridStyleSheet;
class PASCALIMPLEMENTATION TcxVerticalGridStyleSheet : public Cxstyles::TcxCustomStyleSheet
{
	typedef Cxstyles::TcxCustomStyleSheet inherited;
	
private:
	TcxVerticalGridStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxVerticalGridStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxVerticalGridStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxVerticalGridStyleSheet(System::Classes::TComponent* AOwner) : Cxstyles::TcxCustomStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxVerticalGridStyleSheet(void) { }
	
};


class PASCALIMPLEMENTATION TcxVerticalGridStyles : public Cxinplacecontainer::TcxCustomControlStyles
{
	typedef Cxinplacecontainer::TcxCustomControlStyles inherited;
	
private:
	TcxvgOnGetItemStyleEvent FOnGetCategoryStyle;
	TcxvgOnGetItemStyleEvent FOnGetHeaderStyle;
	TcxvgOnGetContentStyleEvent FOnGetContentStyle;
	TcxvgCustomPaintStyleCalcHelper* __fastcall GetCalcHelper(void);
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxvgCustomPaintStyleCalcHelper* CalcHelper = {read=GetCalcHelper};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__fastcall virtual TcxVerticalGridStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Cxgraphics::TcxViewParams __fastcall GetCategoryParams(TcxCustomRow* ARow);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(TcxCustomEditorRowProperties* AEditorRowProperties, bool AFocused, int ARecordIndex);
	virtual Cxgraphics::TcxViewParams __fastcall GetHeaderParams(TcxCustomRow* ARow);
	Cxgraphics::TcxViewParams __fastcall GetIncSearchParams(void);
	Cxgraphics::TcxViewParams __fastcall GetSelectedHeaderParams(TcxCustomRow* ARow);
	
__published:
	__property Cxstyles::TcxStyle* Category = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* ContentEven = {read=GetValue, write=SetValue, index=9};
	__property Cxstyles::TcxStyle* ContentOdd = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=7};
	__property Cxstyles::TcxStyle* IncSearch = {read=GetValue, write=SetValue, index=8};
	__property TcxvgOnGetItemStyleEvent OnGetCategoryStyle = {read=FOnGetCategoryStyle, write=FOnGetCategoryStyle};
	__property TcxvgOnGetItemStyleEvent OnGetHeaderStyle = {read=FOnGetHeaderStyle, write=FOnGetHeaderStyle};
	__property TcxvgOnGetContentStyleEvent OnGetContentStyle = {read=FOnGetContentStyle, write=FOnGetContentStyle};
	__property Background;
	__property Content;
	__property Inactive;
	__property Navigator;
	__property NavigatorInfoPanel;
	__property Selection;
	__property StyleSheet;
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxVerticalGridStyles(void) { }
	
};


class DELPHICLASS TcxVerticalGridItemsCustomizeListBox;
class PASCALIMPLEMENTATION TcxVerticalGridItemsCustomizeListBox : public Cxcontrols::TcxCustomizeListBox
{
	typedef Cxcontrols::TcxCustomizeListBox inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	bool FDragging;
	bool FIsCategoryListBox;
	TcxCustomVerticalGrid* FVerticalGrid;
	int FDragAndDropItemIndex;
	System::Types::TPoint FMouseDownPos;
	System::Types::TPoint FOffset;
	TcxCustomRow* __fastcall GetDragRow(void);
	TcxvgPainter* __fastcall GetPainter(void);
	HIDESBASE MESSAGE void __fastcall CNDrawItem(Winapi::Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TMessage &Message);
	
protected:
	bool IsPaint;
	virtual void __fastcall CalcHeaderViewInfo(const System::Types::TRect &R, TcxCustomRowHeaderInfo* AHeaderInfo);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DrawItem(int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	virtual void __fastcall InitDragAndDropObject(void);
	bool __fastcall IsOwnerDragDrop(System::TObject* ADragObject);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall RefreshList(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property TcxCustomRow* DragRow = {read=GetDragRow};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=FVerticalGrid};
	__property TcxvgPainter* Painter = {read=GetPainter};
	
public:
	__fastcall TcxVerticalGridItemsCustomizeListBox(System::Classes::TComponent* AOwner, TcxCustomVerticalGrid* AVerticalGrid, bool IsCategoryListBox);
	__fastcall virtual ~TcxVerticalGridItemsCustomizeListBox(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
public:
	/* TcxCustomizeListBox.Create */ inline __fastcall virtual TcxVerticalGridItemsCustomizeListBox(System::Classes::TComponent* AOwner) : Cxcontrols::TcxCustomizeListBox(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxVerticalGridItemsCustomizeListBox(HWND ParentWindow) : Cxcontrols::TcxCustomizeListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxVerticalGridCustomizationForm;
class PASCALIMPLEMENTATION TcxVerticalGridCustomizationForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TcxVerticalGridCustomizing* FOwner;
	Cxclasses::TcxTimer* FHookTimer;
	TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	void __fastcall HookTimerHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoClose(System::Uitypes::TCloseAction &Action);
	__property TcxVerticalGridCustomizing* Customizing = {read=FOwner};
	__property Cxclasses::TcxTimer* HookTimer = {read=FHookTimer};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__fastcall TcxVerticalGridCustomizationForm(TcxVerticalGridCustomizing* AOwner);
	__fastcall virtual ~TcxVerticalGridCustomizationForm(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxVerticalGridCustomizationForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxVerticalGridCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxVerticalGridCustomizationForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxVerticalGridCustomizing : public Dxcoreclasses::TcxOwnedInterfacedPersistent
{
	typedef Dxcoreclasses::TcxOwnedInterfacedPersistent inherited;
	
private:
	TcxVerticalGridItemsCustomizeListBox* FCategoryListBox;
	TcxVerticalGridCustomizationForm* FForm;
	TcxVerticalGridItemsCustomizeListBox* FRowListBox;
	int FLastBandIndex;
	int FLastHeaderIndex;
	System::Types::TPoint FLastPosition;
	int FLineHeight;
	Vcl::Comctrls::TPageControl* FPageControl;
	Vcl::Extctrls::TPanel* FPanel;
	Cxbuttons::TcxButton* FButtonNew;
	Cxbuttons::TcxButton* FButtonDelete;
	int FRowCount;
	bool FShowCategoryButtons;
	bool FShowCategoryTab;
	Vcl::Comctrls::TTabSheet* FTabSheetCategories;
	Vcl::Comctrls::TTabSheet* FTabSheetRows;
	TcxCustomVerticalGrid* FVerticalGrid;
	void __fastcall CreateCategoryClick(System::TObject* Sender);
	void __fastcall DeleteCategoryClick(System::TObject* Sender);
	bool __fastcall GetVisible(void);
	void __fastcall SetRowCount(int Value);
	void __fastcall SetShowCategoryButtons(const bool Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall UpdateButtons(System::TObject* Sender);
	
protected:
	virtual void __fastcall AdjustControls(void);
	virtual bool __fastcall CanDrop(const System::Types::TPoint P);
	void __fastcall CreateCategoryPanel(void);
	virtual void __fastcall CreateCategoryRow(void);
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall FinishCustomizing(const System::Types::TRect &ABounds);
	void __fastcall CreateCustomizingForm(void);
	void __fastcall DisplayCustomizingForm(void);
	void __fastcall HideCustomizingForm(void);
	void __fastcall ShowCustomizingForm(void);
	virtual void __fastcall LookAndFeelChanged(void);
	void __fastcall SetControlParent(Vcl::Controls::TWinControl* AControl, Vcl::Controls::TWinControl* AParent);
	virtual System::Types::TSize __fastcall SizeDelta(void);
	void __fastcall ValidateListBox(TcxVerticalGridItemsCustomizeListBox* AListBox, int AIndex);
	virtual void __fastcall Update(void);
	virtual void __fastcall ComponentRemoved(System::TObject* Sender);
	virtual void __fastcall Modified(void);
	__property TcxVerticalGridItemsCustomizeListBox* CategoryListBox = {read=FCategoryListBox};
	__property System::Types::TPoint CustomizingPos = {read=FLastPosition, write=FLastPosition};
	__property TcxVerticalGridItemsCustomizeListBox* RowListBox = {read=FRowListBox};
	__property TcxCustomVerticalGrid* VerticalGrid = {read=FVerticalGrid};
	
public:
	__fastcall virtual TcxVerticalGridCustomizing(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxVerticalGridCustomizing(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall MakeCategorySheetVisible(void);
	void __fastcall MakeRowSheetVisible(void);
	__property TcxVerticalGridCustomizationForm* Form = {read=FForm};
	__property int RowCount = {read=FRowCount, write=SetRowCount, default=10};
	__property bool ShowCategoryButtons = {read=FShowCategoryButtons, write=SetShowCategoryButtons, nodefault};
	__property bool ShowCategoryTab = {read=FShowCategoryTab, write=FShowCategoryTab, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxvgMinValueWidth = System::Int8(0x14);
static const System::Int8 vgrs_Header = System::Int8(0x0);
static const System::Int8 vgrs_Content = System::Int8(0x1);
static const System::Int8 vgs_Content = System::Int8(0x0);
static const System::Int8 vgs_Selection = System::Int8(0x3);
static const System::Int8 vgs_Category = System::Int8(0x6);
static const System::Int8 vgs_Header = System::Int8(0x7);
static const System::Int8 vgs_IncSearch = System::Int8(0x8);
static const System::Int8 vgs_ContentEven = System::Int8(0x9);
static const System::Int8 vgs_ContentOdd = System::Int8(0xa);
static const System::Int8 vgs_MaxIndex = System::Int8(0xa);
static const System::Int8 cxvgMaxControlStyleIndex = System::Int8(0x8);
static const System::Int8 cxvgMaxRowStyleIndex = System::Int8(0x1);
static const System::Int8 vghc_Base = System::Int8(0x4);
static const System::Int8 vghc_HitAtBandSizing = System::Int8(0x4);
static const System::Int8 vghc_HitAtButton = System::Int8(0x5);
static const System::Int8 vghc_HitAtCaption = System::Int8(0x6);
static const System::Int8 vghc_HitAtDivider = System::Int8(0x7);
static const System::Int8 vghc_HitAtEmpty = System::Int8(0x8);
static const System::Int8 vghc_HitAtImage = System::Int8(0x9);
static const System::Int8 vghc_HitAtIndent = System::Int8(0xa);
static const System::Int8 vghc_HitAtRowSizing = System::Int8(0xb);
static const System::Int8 vghc_HitAtValue = System::Int8(0xc);
static const System::Int8 vghc_HitAtCustomize = System::Int8(0xd);
static const System::Int8 vghc_HitAtSeparator = System::Int8(0xe);
static const System::Int8 vghc_HitAtNavigator = System::Int8(0xf);
extern PACKAGE int __fastcall GetTextAligmentFlags(TcxCaptionRowProperties* AProperties)/* overload */;
extern PACKAGE int __fastcall GetTextAligmentFlags(System::Classes::TAlignment AHorz, Cxclasses::TcxAlignmentVert AVert)/* overload */;
extern PACKAGE void __fastcall cxVerticalGridError(const System::UnicodeString Msg);
}	/* namespace Cxvgrid */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVGRID)
using namespace Cxvgrid;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvgridHPP
