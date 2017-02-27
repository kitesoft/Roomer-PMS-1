// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxRichEdit.pas' rev: 24.00 (Win64)

#ifndef CxricheditHPP
#define CxricheditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <Winapi.OleDlg.hpp>	// Pascal unit
#include <Vcl.OleConst.hpp>	// Pascal unit
#include <Vcl.OleCtnrs.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.RichEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <cxRichEditUtils.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <dxDrawRichTextUtils.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
DECLARE_DINTERFACE_TYPE(IOleLink);

namespace Cxrichedit
{
//-- type declarations -------------------------------------------------------
enum TcxRichEditClass : unsigned char { recRichEdit10, recRichEdit20, recRichEdit41 };

enum TcxRichEditStreamMode : unsigned char { resmSelection, resmPlainRtf, resmRtfNoObjs, resmUnicode, resmTextIzed };

typedef System::Set<TcxRichEditStreamMode, TcxRichEditStreamMode::resmSelection, TcxRichEditStreamMode::resmTextIzed>  TcxRichEditStreamModes;

struct DECLSPEC_DRECORD TcxTextRange
{
public:
	CHARRANGE chrg;
	System::WideChar *lpstrText;
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TReObject
{
public:
	unsigned cbStruct;
	unsigned cp;
	GUID clsid;
	_di_IOleObject oleobj;
	_di_IStorage stg;
	_di_IOleClientSite olesite;
	System::Types::TSize sizel;
	unsigned dvaspect;
	unsigned dwFlags;
	unsigned dwUser;
};
#pragma pack(pop)


class DELPHICLASS TcxCustomRichEdit;
typedef void __fastcall (__closure *TcxRichEditURLClickEvent)(TcxCustomRichEdit* Sender, const System::UnicodeString URLText, System::Uitypes::TMouseButton Button);

typedef void __fastcall (__closure *TcxRichEditURLMoveEvent)(TcxCustomRichEdit* Sender, const System::UnicodeString URLText);

typedef void __fastcall (__closure *TcxRichEditQueryInsertObjectEvent)(TcxCustomRichEdit* Sender, bool &AAllowInsertObject, const GUID &ACLSID);

class DELPHICLASS TcxCustomRichEditViewInfo;
class PASCALIMPLEMENTATION TcxCustomRichEditViewInfo : public Cxmemo::TcxCustomMemoViewInfo
{
	typedef Cxmemo::TcxCustomMemoViewInfo inherited;
	
protected:
	virtual Cxedit::TcxEditBackgroundPaintingStyle __fastcall GetBackgroundPaintingStyle(void);
	
public:
	HBITMAP DrawBitmap;
	bool IsDrawBitmapDirty;
	System::Types::TSize PrevDrawBitmapSize;
	__fastcall virtual TcxCustomRichEditViewInfo(void);
	__fastcall virtual ~TcxCustomRichEditViewInfo(void);
	virtual void __fastcall DrawNativeStyleEditBackground(Cxgraphics::TcxCanvas* ACanvas, bool ADrawBackground, HBRUSH ABackgroundBrush);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(Cxcontainer::TcxContainerViewInfo* AViewInfo);
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
};


class DELPHICLASS TcxCustomRichEditViewData;
class DELPHICLASS TcxCustomRichEditProperties;
class PASCALIMPLEMENTATION TcxCustomRichEditViewData : public Cxmemo::TcxCustomMemoViewData
{
	typedef Cxmemo::TcxCustomMemoViewData inherited;
	
private:
	HIDESBASE TcxCustomRichEditProperties* __fastcall GetProperties(void);
	
protected:
	virtual System::Types::TSize __fastcall InternalGetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	__property TcxCustomRichEditProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomRichEditViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxmemo::TcxCustomMemoViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomRichEditViewData(void) { }
	
};


__interface IcxRichEditOleCallback;
typedef System::DelphiInterface<IcxRichEditOleCallback> _di_IcxRichEditOleCallback;
__interface  INTERFACE_UUID("{00020D00-0000-0000-C000-000000000046}") IcxRichEditOleCallback  : public System::IInterface 
{
	
public:
	virtual HRESULT __stdcall GetNewStorage(/* out */ _di_IStorage &stg) = 0 ;
	virtual HRESULT __stdcall GetInPlaceContext(/* out */ _di_IOleInPlaceFrame &Frame, /* out */ _di_IOleInPlaceUIWindow &Doc, Winapi::Activex::POleInPlaceFrameInfo lpFrameInfo) = 0 ;
	virtual HRESULT __stdcall ShowContainerUI(BOOL fShow) = 0 ;
	virtual HRESULT __stdcall QueryInsertObject(const GUID &clsid, _di_IStorage stg, int cp) = 0 ;
	virtual HRESULT __stdcall DeleteObject(_di_IOleObject oleobj) = 0 ;
	virtual HRESULT __stdcall QueryAcceptData(_di_IDataObject dataobj, System::Word &cfFormat, unsigned reco, BOOL fReally, NativeUInt hMetaPict) = 0 ;
	virtual HRESULT __stdcall ContextSensitiveHelp(BOOL fEnterMode) = 0 ;
	virtual HRESULT __stdcall GetClipboardData(const CHARRANGE chrg, unsigned reco, /* out */ _di_IDataObject &dataobj) = 0 ;
	virtual HRESULT __stdcall GetDragDropEffect(BOOL fDrag, unsigned grfKeyState, unsigned &dwEffect) = 0 ;
	virtual HRESULT __stdcall GetContextMenu(System::Word seltype, _di_IOleObject oleobj, const CHARRANGE chrg, HMENU &menu) = 0 ;
};

__interface IcxRichEditOle;
typedef System::DelphiInterface<IcxRichEditOle> _di_IcxRichEditOle;
__interface  INTERFACE_UUID("{00020D00-0000-0000-C000-000000000046}") IcxRichEditOle  : public System::IInterface 
{
	
public:
	virtual HRESULT __stdcall GetClientSite(/* out */ _di_IOleClientSite &clientSite) = 0 ;
	virtual HRESULT __stdcall GetObjectCount(void) = 0 ;
	virtual HRESULT __stdcall GetLinkCount(void) = 0 ;
	virtual HRESULT __stdcall GetObject(int iob, /* out */ TReObject &reobject, unsigned dwFlags) = 0 ;
	virtual HRESULT __stdcall InsertObject(TReObject &reobject) = 0 ;
	virtual HRESULT __stdcall ConvertObject(int iob, GUID rclsidNew, char * lpstrUserTypeNew) = 0 ;
	virtual HRESULT __stdcall ActivateAs(GUID rclsid, GUID rclsidAs) = 0 ;
	virtual HRESULT __stdcall SetHostNames(char * lpstrContainerApp, char * lpstrContainerObj) = 0 ;
	virtual HRESULT __stdcall SetLinkAvailable(int iob, BOOL fAvailable) = 0 ;
	virtual HRESULT __stdcall SetDvaspect(int iob, unsigned dvaspect) = 0 ;
	virtual HRESULT __stdcall HandsOffStorage(int iob) = 0 ;
	virtual HRESULT __stdcall SaveCompleted(int iob, const _di_IStorage stg) = 0 ;
	virtual HRESULT __stdcall InPlaceDeactivate(void) = 0 ;
	virtual HRESULT __stdcall ContextSensitiveHelp(BOOL fEnterMode) = 0 ;
	virtual HRESULT __stdcall GetClipboardData(CHARRANGE &chrg, unsigned reco, /* out */ _di_IDataObject &dataobj) = 0 ;
	virtual HRESULT __stdcall ImportDataObject(_di_IDataObject dataobj, System::Word cf, NativeUInt hMetaPict) = 0 ;
};

class DELPHICLASS TcxRichEditOleCallback;
class DELPHICLASS TcxRichInnerEdit;
class PASCALIMPLEMENTATION TcxRichEditOleCallback : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxRichInnerEdit* FEdit;
	Vcl::Olectnrs::_di_IVCLFrameForm FDocParentForm;
	Vcl::Olectnrs::_di_IVCLFrameForm FParentFrame;
	HACCEL FAccelTable;
	int FAccelCount;
	void __fastcall AssignParentFrame(void);
	void __fastcall CreateAccelTable(void);
	void __fastcall DestroyAccelTable(void);
	
protected:
	__property Vcl::Olectnrs::_di_IVCLFrameForm ParentFrame = {read=FParentFrame};
	__property Vcl::Olectnrs::_di_IVCLFrameForm DocParentForm = {read=FDocParentForm};
	
public:
	__fastcall TcxRichEditOleCallback(TcxRichInnerEdit* AOwner);
	HRESULT __stdcall ContextSensitiveHelp(BOOL fEnterMode);
	HRESULT __stdcall DeleteObject(_di_IOleObject oleobj);
	HRESULT __stdcall GetClipboardData(const CHARRANGE chrg, unsigned reco, /* out */ _di_IDataObject &dataobj);
	HRESULT __stdcall GetContextMenu(System::Word seltype, _di_IOleObject oleobj, const CHARRANGE chrg, HMENU &menu);
	HRESULT __stdcall GetDragDropEffect(BOOL fDrag, unsigned grfKeyState, unsigned &dwEffect);
	HRESULT __stdcall GetInPlaceContext(/* out */ _di_IOleInPlaceFrame &Frame, /* out */ _di_IOleInPlaceUIWindow &Doc, Winapi::Activex::POleInPlaceFrameInfo lpFrameInfo);
	HRESULT __stdcall GetNewStorage(/* out */ _di_IStorage &stg);
	HRESULT __stdcall QueryInsertObject(const GUID &clsid, _di_IStorage stg, int cp);
	HRESULT __stdcall QueryAcceptData(_di_IDataObject dataobj, System::Word &cfFormat, unsigned reco, BOOL fReally, NativeUInt hMetaPict);
	HRESULT __stdcall ShowContainerUI(BOOL fShow);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRichEditOleCallback(void) { }
	
private:
	void *__IcxRichEditOleCallback;	/* IcxRichEditOleCallback */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00020D00-0000-0000-C000-000000000046}
	operator _di_IcxRichEditOleCallback()
	{
		_di_IcxRichEditOleCallback intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxRichEditOleCallback*(void) { return (IcxRichEditOleCallback*)&__IcxRichEditOleCallback; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxCustomRichEditProperties : public Cxmemo::TcxCustomMemoProperties
{
	typedef Cxmemo::TcxCustomMemoProperties inherited;
	
private:
	bool FAdvancedTypography;
	bool FAllowObjects;
	bool FAutoURLDetect;
	bool FHideScrollBars;
	bool FMemoMode;
	bool FPlainText;
	bool FPlainTextChanged;
	TcxRichEditClass FRichEditClass;
	bool FSelectionBar;
	TcxRichEditStreamModes FStreamModes;
	double FZoomFactor;
	TcxRichEditQueryInsertObjectEvent FOnQueryInsertObject;
	Vcl::Comctrls::TRichEditProtectChange FOnProtectChange;
	Vcl::Comctrls::TRichEditResizeEvent FOnResizeRequest;
	Vcl::Comctrls::TRichEditSaveClipboard FOnSaveClipboard;
	System::Classes::TNotifyEvent FOnSelectionChange;
	TcxRichEditURLClickEvent FOnURLClick;
	TcxRichEditURLMoveEvent FOnURLMove;
	TcxRichEditStreamModes __fastcall GetStreamModes(void);
	bool __fastcall IsZoomFactorStored(void);
	void __fastcall SetAdvancedTypography(const bool Value);
	void __fastcall SetAllowObjects(const bool Value);
	void __fastcall SetAutoURLDetect(const bool Value);
	void __fastcall SetHideScrollBars(bool Value);
	void __fastcall SetMemoMode(bool Value);
	void __fastcall SetPlainText(bool Value);
	void __fastcall SetRichEditClass(TcxRichEditClass AValue);
	void __fastcall SetSelectionBar(bool Value);
	void __fastcall SetStreamModes(const TcxRichEditStreamModes Value);
	void __fastcall SetOnQueryInsertObject(TcxRichEditQueryInsertObjectEvent Value);
	void __fastcall SetZoomFactor(const double Value);
	
protected:
	virtual bool __fastcall CanValidate(void);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	__property bool PlainTextChanged = {read=FPlainTextChanged, nodefault};
	
public:
	__fastcall virtual TcxCustomRichEditProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Cxedit::TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsResetEditClass(void);
	__property bool AdvancedTypography = {read=FAdvancedTypography, write=SetAdvancedTypography, nodefault};
	__property bool AllowObjects = {read=FAllowObjects, write=SetAllowObjects, default=0};
	__property bool AutoURLDetect = {read=FAutoURLDetect, write=SetAutoURLDetect, default=0};
	__property bool PlainText = {read=FPlainText, write=SetPlainText, default=0};
	__property TcxRichEditClass RichEditClass = {read=FRichEditClass, write=SetRichEditClass, default=2};
	__property bool HideScrollBars = {read=FHideScrollBars, write=SetHideScrollBars, default=1};
	__property bool MemoMode = {read=FMemoMode, write=SetMemoMode, default=0};
	__property bool SelectionBar = {read=FSelectionBar, write=SetSelectionBar, default=0};
	__property TcxRichEditStreamModes StreamModes = {read=GetStreamModes, write=SetStreamModes, default=0};
	__property double ZoomFactor = {read=FZoomFactor, write=SetZoomFactor, stored=IsZoomFactorStored};
	__property TcxRichEditQueryInsertObjectEvent OnQueryInsertObject = {read=FOnQueryInsertObject, write=SetOnQueryInsertObject};
	__property Vcl::Comctrls::TRichEditProtectChange OnProtectChange = {read=FOnProtectChange, write=FOnProtectChange};
	__property Vcl::Comctrls::TRichEditResizeEvent OnResizeRequest = {read=FOnResizeRequest, write=FOnResizeRequest};
	__property Vcl::Comctrls::TRichEditSaveClipboard OnSaveClipboard = {read=FOnSaveClipboard, write=FOnSaveClipboard};
	__property System::Classes::TNotifyEvent OnSelectionChange = {read=FOnSelectionChange, write=FOnSelectionChange};
	__property TcxRichEditURLClickEvent OnURLClick = {read=FOnURLClick, write=FOnURLClick};
	__property TcxRichEditURLMoveEvent OnURLMove = {read=FOnURLMove, write=FOnURLMove};
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomRichEditProperties(void) { }
	
};


class DELPHICLASS TcxRichEditProperties;
class PASCALIMPLEMENTATION TcxRichEditProperties : public TcxCustomRichEditProperties
{
	typedef TcxCustomRichEditProperties inherited;
	
__published:
	__property Alignment;
	__property AllowObjects = {default=0};
	__property AssignedValues;
	__property AutoSelect = {default=0};
	__property AutoURLDetect = {default=0};
	__property ClearKey = {default=0};
	__property HideScrollBars = {default=1};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property MaxLength;
	__property MemoMode = {default=0};
	__property OEMConvert = {default=0};
	__property PlainText = {default=0};
	__property ReadOnly;
	__property RichEditClass = {default=2};
	__property ScrollBars = {default=0};
	__property SelectionBar = {default=0};
	__property StreamModes = {default=0};
	__property VisibleLineCount = {default=0};
	__property WantReturns = {default=1};
	__property WantTabs = {default=0};
	__property WordWrap = {default=1};
	__property ZoomFactor = {default=0};
	__property OnQueryInsertObject;
	__property OnChange;
	__property OnEditValueChanged;
	__property OnProtectChange;
	__property OnResizeRequest;
	__property OnSaveClipboard;
	__property OnSelectionChange;
	__property OnURLClick;
	__property OnURLMove;
public:
	/* TcxCustomRichEditProperties.Create */ inline __fastcall virtual TcxRichEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomRichEditProperties(AOwner) { }
	
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxRichEditProperties(void) { }
	
};


class DELPHICLASS TcxOleUILinkInfo;
class PASCALIMPLEMENTATION TcxOleUILinkInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxRichInnerEdit* FRichEdit;
	TReObject FReObject;
	_di_IOleLink FOleLink;
	
public:
	__fastcall TcxOleUILinkInfo(TcxRichInnerEdit* AOwner, TReObject &AReObject);
	__fastcall virtual ~TcxOleUILinkInfo(void);
	HRESULT __stdcall GetLastUpdate(int dwLink, _FILETIME &LastUpdate);
	int __stdcall GetNextLink(int dwLink);
	HRESULT __stdcall SetLinkUpdateOptions(int dwLink, int dwUpdateOpt);
	HRESULT __stdcall GetLinkUpdateOptions(int dwLink, int &dwUpdateOpt);
	HRESULT __stdcall SetLinkSource(int dwLink, System::WideChar * pszDisplayName, int lenFileName, int &chEaten, BOOL fValidateSource);
	HRESULT __stdcall GetLinkSource(int dwLink, System::WideChar * &pszDisplayName, int &lenFileName, System::WideChar * &pszFullLinkType, System::WideChar * &pszShortLinkType, BOOL &fSourceAvailable, BOOL &fIsSelected);
	HRESULT __stdcall OpenLinkSource(int dwLink);
	HRESULT __stdcall UpdateLink(int dwLink, BOOL fErrorMessage, BOOL fErrorAction);
	HRESULT __stdcall CancelLink(int dwLink);
private:
	void *__IOleUILinkInfo;	/* IOleUILinkInfo */
	
public:
	operator IOleUILinkInfo*(void) { return (IOleUILinkInfo*)&__IOleUILinkInfo; }
	
};


class DELPHICLASS TcxOleUIObjInfo;
class PASCALIMPLEMENTATION TcxOleUIObjInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxRichInnerEdit* FRichEdit;
	TReObject FReObject;
	int __fastcall GetObjectDataSize(void);
	
public:
	__fastcall TcxOleUIObjInfo(TcxRichInnerEdit* AOwner, TReObject &AReObject);
	HRESULT __stdcall GetObjectInfo(int dwObject, int &dwObjSize, System::WideChar * &lpszLabel, System::WideChar * &lpszType, System::WideChar * &lpszShortType, System::WideChar * &lpszLocation);
	HRESULT __stdcall GetConvertInfo(int dwObject, GUID &ClassID, System::Word &wFormat, GUID &ConvertDefaultClassID, System::PGUID &lpClsidExclude, int &cClsidExclude);
	HRESULT __stdcall ConvertObject(int dwObject, const GUID &clsidNew);
	HRESULT __stdcall GetViewInfo(int dwObject, NativeUInt &hMetaPict, int &dvAspect, int &nCurrentScale);
	HRESULT __stdcall SetViewInfo(int dwObject, NativeUInt hMetaPict, int dvAspect, int nCurrentScale, BOOL bRelativeToOrig);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxOleUIObjInfo(void) { }
	
private:
	void *__IOleUIObjInfo;	/* IOleUIObjInfo */
	
public:
	operator IOleUIObjInfo*(void) { return (IOleUIObjInfo*)&__IOleUIObjInfo; }
	
};


class PASCALIMPLEMENTATION TcxCustomRichEdit : public Cxmemo::TcxCustomMemo
{
	typedef Cxmemo::TcxCustomMemo inherited;
	
private:
	Cxricheditutils::TcxTextAttributes2* FDefAttributes2;
	System::Classes::TComponent* FEditPopupMenu;
	bool FIsNullEditValue;
	Cxricheditutils::TcxTextAttributes2* FSelAttributes2;
	int FLastLineCount;
	Cxricheditutils::TcxParaAttributes2* FParagraph2;
	bool FPropertiesChange;
	void __fastcall DoProtectChange(System::TObject* Sender, int AStartPos, int AEndPos, bool &AAllowChange);
	void __fastcall DoSaveClipboard(System::TObject* Sender, int ANumObjects, int ANumChars, bool &ASaveClipboard);
	void __fastcall EditPopupMenuClick(System::TObject* Sender);
	HIDESBASE System::Classes::TStrings* __fastcall GetLines(void);
	TcxRichInnerEdit* __fastcall GetInnerRich(void);
	HIDESBASE void __fastcall SetLines(System::Classes::TStrings* Value);
	HIDESBASE TcxCustomRichEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCustomRichEditProperties* __fastcall GetProperties(void);
	int __fastcall GetRichVersion(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomRichEditProperties* Value);
	bool __fastcall GetCanUndo(void);
	Vcl::Comctrls::TTextAttributes* __fastcall GetDefAttributes(void);
	Vcl::Comctrls::TConversionClass __fastcall GetDefaultConverter(void);
	System::Types::TRect __fastcall GetPageRect(void);
	Vcl::Comctrls::TParaAttributes* __fastcall GetParagraph(void);
	Vcl::Comctrls::TTextAttributes* __fastcall GetSelAttributes(void);
	void __fastcall RefreshScrollBars(void);
	void __fastcall SetDefAttributes(Vcl::Comctrls::TTextAttributes* const Value);
	void __fastcall SetDefAttributes2(Cxricheditutils::TcxTextAttributes2* const Value);
	void __fastcall SetDefaultConverter(Vcl::Comctrls::TConversionClass Value);
	void __fastcall SetPageRect(const System::Types::TRect &Value);
	void __fastcall SetSelAttributes2(Cxricheditutils::TcxTextAttributes2* Value);
	void __fastcall SetSelAttributes(Vcl::Comctrls::TTextAttributes* const Value);
	MESSAGE void __fastcall EMCanPaste(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMSetFont(Winapi::Messages::TWMSetFont &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall AdjustInnerEdit(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual bool __fastcall CanKeyDownModifyEdit(System::Word Key, System::Classes::TShiftState Shift);
	virtual void __fastcall ContainerStyleChanged(System::TObject* Sender);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* AMenu, int X, int Y);
	virtual void __fastcall DoSpellCheckerPostEditValue(void);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass(void);
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	virtual void __fastcall SelChange(System::TObject* Sender);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	bool __fastcall CanDeleteSelection(void);
	HIDESBASE void __fastcall Changed(System::TObject* Sender);
	void __fastcall DoOnResizeRequest(const System::Types::TRect &R);
	void __fastcall DoOnSelectionChange(void);
	virtual void __fastcall DoTextChanged(void);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall ResetEditValue(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall SynchronizeEditValue(void);
	virtual System::Classes::TComponent* __fastcall GetEditPopupMenuInstance(void);
	virtual bool __fastcall IsNavigationKey(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall UpdateContentOnFocusChanging(void);
	virtual void __fastcall UpdateEditPopupMenuItems(System::Classes::TComponent* APopupMenu);
	__property System::Classes::TComponent* EditPopupMenu = {read=FEditPopupMenu, write=FEditPopupMenu};
	__property TcxRichInnerEdit* InnerRich = {read=GetInnerRich};
	__property bool PropertiesChange = {read=FPropertiesChange, nodefault};
	
public:
	__fastcall virtual TcxCustomRichEdit(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TcxCustomRichEdit(void);
	virtual void __fastcall ClearSelection(void);
	virtual void __fastcall CutToClipboard(void);
	int __fastcall FindTexT(const System::UnicodeString ASearchStr, int AStartPos, int ALength, Vcl::Comctrls::TSearchTypes AOptions, bool AForward = true);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	void __fastcall InsertTable(int AColumnCount, int ARowCount, Cxricheditutils::TcxRichEditTableParams* AParams);
	virtual void __fastcall PasteFromClipboard(void);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall Print(const System::UnicodeString Caption);
	virtual void __fastcall SaveSelectionToStream(System::Classes::TStream* Stream);
	virtual void __fastcall Undo(void);
	bool __fastcall InsertObject(void);
	bool __fastcall PasteSpecial(void);
	bool __fastcall ShowObjectProperties(void);
	__classmethod void __fastcall RegisterConversionFormat(const System::UnicodeString AExtension, Vcl::Comctrls::TConversionClass AConversionClass);
	__property TcxCustomRichEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property bool CanUndo = {read=GetCanUndo, nodefault};
	__property Vcl::Comctrls::TTextAttributes* DefAttributes = {read=GetDefAttributes, write=SetDefAttributes};
	__property Cxricheditutils::TcxTextAttributes2* DefAttributes2 = {read=FDefAttributes2, write=SetDefAttributes2};
	__property Vcl::Comctrls::TConversionClass DefaultConverter = {read=GetDefaultConverter, write=SetDefaultConverter};
	__property System::Classes::TStrings* Lines = {read=GetLines, write=SetLines};
	__property System::Types::TRect PageRect = {read=GetPageRect, write=SetPageRect};
	__property Vcl::Comctrls::TParaAttributes* Paragraph = {read=GetParagraph};
	__property Cxricheditutils::TcxParaAttributes2* Paragraph2 = {read=FParagraph2};
	__property TcxCustomRichEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property int RichVersion = {read=GetRichVersion, nodefault};
	__property Vcl::Comctrls::TTextAttributes* SelAttributes = {read=GetSelAttributes, write=SetSelAttributes};
	__property Cxricheditutils::TcxTextAttributes2* SelAttributes2 = {read=FSelAttributes2, write=SetSelAttributes2};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomRichEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxmemo::TcxCustomMemo(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomRichEdit(HWND ParentWindow) : Cxmemo::TcxCustomMemo(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
};


class DELPHICLASS TcxRichEdit;
class PASCALIMPLEMENTATION TcxRichEdit : public TcxCustomRichEdit
{
	typedef TcxCustomRichEdit inherited;
	
private:
	HIDESBASE TcxRichEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxRichEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxRichEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxRichEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxRichEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Lines;
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomRichEdit.Create */ inline __fastcall virtual TcxRichEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomRichEdit(AOwner) { }
	/* TcxCustomRichEdit.Destroy */ inline __fastcall virtual ~TcxRichEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxRichEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomRichEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxRichEdit(HWND ParentWindow) : TcxCustomRichEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxRichInnerEditHelper;
class PASCALIMPLEMENTATION TcxRichInnerEditHelper : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxRichInnerEdit* FEdit;
	
protected:
	__property TcxRichInnerEdit* Edit = {read=FEdit};
	
public:
	__fastcall virtual TcxRichInnerEditHelper(TcxRichInnerEdit* AEdit);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	Vcl::Controls::TWinControl* __fastcall GetControl(void);
	NativeInt __fastcall CallDefWndProc(unsigned AMsg, NativeUInt WParam, NativeInt LParam);
	bool __fastcall CanProcessClipboardMessages(void);
	System::Variant __fastcall GetEditValue(void);
	System::Classes::TNotifyEvent __fastcall GetOnChange(void);
	void __fastcall LockBounds(bool ALock);
	void __fastcall SafelySetFocus(void);
	void __fastcall SetEditValue(const System::Variant &Value);
	void __fastcall SetParent(Vcl::Controls::TWinControl* Value);
	void __fastcall SetOnChange(System::Classes::TNotifyEvent Value);
	void __fastcall ClearSelection(void);
	void __fastcall CopyToClipboard(void);
	System::Classes::TAlignment __fastcall GetAlignment(void);
	bool __fastcall GetAutoSelect(void);
	System::Uitypes::TEditCharCase __fastcall GetCharCase(void);
	Cxtextedit::TcxEditEchoMode __fastcall GetEchoMode(void);
	int __fastcall GetFirstVisibleCharIndex(void);
	bool __fastcall GetHideSelection(void);
	System::WideChar __fastcall GetImeLastChar(void);
	Vcl::Controls::TImeMode __fastcall GetImeMode(void);
	Vcl::Controls::TImeName __fastcall GetImeName(void);
	bool __fastcall GetInternalUpdating(void);
	int __fastcall GetMaxLength(void);
	bool __fastcall GetMultiLine(void);
	bool __fastcall GetOEMConvert(void);
	System::Classes::TNotifyEvent __fastcall GetOnSelChange(void);
	System::WideChar __fastcall GetPasswordChar(void);
	bool __fastcall GetReadOnly(void);
	int __fastcall GetSelLength(void);
	int __fastcall GetSelStart(void);
	System::UnicodeString __fastcall GetSelText(void);
	bool __fastcall GetUseLeftAlignmentOnEditing(void);
	void __fastcall SelectAll(void);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetAutoSelect(bool Value);
	void __fastcall SetCharCase(System::Uitypes::TEditCharCase Value);
	void __fastcall SetEchoMode(Cxtextedit::TcxEditEchoMode Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetInternalUpdating(bool Value);
	void __fastcall SetImeMode(Vcl::Controls::TImeMode Value);
	void __fastcall SetImeName(const Vcl::Controls::TImeName Value);
	void __fastcall SetMaxLength(int Value);
	void __fastcall SetOEMConvert(bool Value);
	void __fastcall SetOnSelChange(System::Classes::TNotifyEvent Value);
	void __fastcall SetPasswordChar(System::WideChar Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetSelLength(int Value);
	void __fastcall SetSelStart(int Value);
	void __fastcall SetSelText(System::UnicodeString Value);
	void __fastcall SetUseLeftAlignmentOnEditing(bool Value);
	System::UnicodeString __fastcall GetTextHint(void);
	void __fastcall SetTextHint(System::UnicodeString Value);
	System::Types::TPoint __fastcall GetCaretPos(void);
	System::Classes::TStrings* __fastcall GetLines(void);
	System::Uitypes::TScrollStyle __fastcall GetScrollBars(void);
	bool __fastcall GetWantReturns(void);
	bool __fastcall GetWantTabs(void);
	bool __fastcall GetWordWrap(void);
	void __fastcall SetCaretPos(const System::Types::TPoint Value);
	void __fastcall SetScrollBars(System::Uitypes::TScrollStyle Value);
	void __fastcall SetWantReturns(bool Value);
	void __fastcall SetWantTabs(bool Value);
	void __fastcall SetWordWrap(bool Value);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxRichInnerEditHelper(void) { }
	
private:
	void *__IcxInnerMemo;	/* Cxmemo::IcxInnerMemo */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9D0DFE35-58DC-4C0C-9C98-65C5AAD757C9}
	operator Cxmemo::_di_IcxInnerMemo()
	{
		Cxmemo::_di_IcxInnerMemo intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxmemo::IcxInnerMemo*(void) { return (Cxmemo::IcxInnerMemo*)&__IcxInnerMemo; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {263EBB8D-1EA9-4CAC-8367-ADD74D2A9651}
	operator Cxtextedit::_di_IcxInnerTextEdit()
	{
		Cxtextedit::_di_IcxInnerTextEdit intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxtextedit::IcxInnerTextEdit*(void) { return (Cxtextedit::IcxInnerTextEdit*)&__IcxInnerMemo; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {468D21B5-48AA-4077-8ED5-4C6112D460B1}
	operator Cxedit::_di_IcxCustomInnerEdit()
	{
		Cxedit::_di_IcxCustomInnerEdit intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxCustomInnerEdit*(void) { return (Cxedit::IcxCustomInnerEdit*)&__IcxInnerMemo; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator Cxcontainer::_di_IcxContainerInnerControl()
	{
		Cxcontainer::_di_IcxContainerInnerControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxInnerMemo; }
	#endif
	
};


enum TcxRichEditStreamOperation : unsigned char { esoLoadFrom, esoSaveTo };

struct DECLSPEC_DRECORD TcxRichEditStreamOperationInfo
{
public:
	EDITSTREAM EditStream;
	Vcl::Comctrls::TRichEditStreamInfo StreamInfo;
	int TextType;
	System::Sysutils::TEncoding* Encoding;
};


class DELPHICLASS TcxRichEditStrings;
class PASCALIMPLEMENTATION TcxRichEditStrings : public System::Classes::TStrings
{
	typedef System::Classes::TStrings inherited;
	
private:
	Vcl::Comctrls::TConversion* FConverter;
	bool FIsModification;
	TcxRichInnerEdit* FRichEdit;
	int FTextType;
	int __fastcall CalcStreamTextType(TcxRichEditStreamOperation AStreamOperation, bool ACustom = false, TcxRichEditStreamModes ACustomStreamModes = TcxRichEditStreamModes() );
	TcxRichEditStreamModes __fastcall GetAllowStreamModesByStreamOperation(TcxRichEditStreamOperation AStreamOperation);
	TcxRichEditStreamModes __fastcall GetStreamModes(void);
	
protected:
	virtual System::UnicodeString __fastcall Get(int Index);
	virtual void __fastcall InitConverter(const System::UnicodeString AFileName);
	void __fastcall InitStreamOperation(System::Classes::TStream* AStream, TcxRichEditStreamOperationInfo &AStreamOperationInfo, TcxRichEditStreamOperation AStreamOperation, bool ACustom = false, TcxRichEditStreamModes ACustomStreamModes = TcxRichEditStreamModes() );
	virtual int __fastcall GetCount(void);
	virtual void __fastcall Put(int Index, const System::UnicodeString S);
	virtual void __fastcall SetUpdateState(bool Updating);
	virtual void __fastcall SetTextStr(const System::UnicodeString Value);
	virtual System::UnicodeString __fastcall GetLineBreakString(void);
	__property bool IsModification = {read=FIsModification, write=FIsModification, nodefault};
	__property TcxRichInnerEdit* RichEdit = {read=FRichEdit};
	
public:
	__fastcall virtual TcxRichEditStrings(TcxRichInnerEdit* ARichEdit);
	__fastcall virtual ~TcxRichEditStrings(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall AddStrings(System::Classes::TStrings* Strings)/* overload */;
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Insert(int Index, const System::UnicodeString S);
	virtual void __fastcall LoadFromFile(const System::UnicodeString FileName, System::Sysutils::TEncoding* Encoding)/* overload */;
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream, System::Sysutils::TEncoding* Encoding)/* overload */;
	virtual void __fastcall SaveToFile(const System::UnicodeString FileName, System::Sysutils::TEncoding* Encoding)/* overload */;
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream, System::Sysutils::TEncoding* Encoding)/* overload */;
/* Hoisted overloads: */
	
public:
	inline void __fastcall  AddStrings(const System::DynamicArray<System::UnicodeString> Strings){ System::Classes::TStrings::AddStrings(Strings); }
	inline void __fastcall  AddStrings(const System::DynamicArray<System::UnicodeString> Strings, const System::DynamicArray<System::TObject*> Objects){ System::Classes::TStrings::AddStrings(Strings, Objects); }
	inline void __fastcall  LoadFromFile(const System::UnicodeString FileName){ System::Classes::TStrings::LoadFromFile(FileName); }
	inline void __fastcall  LoadFromStream(System::Classes::TStream* Stream){ System::Classes::TStrings::LoadFromStream(Stream); }
	inline void __fastcall  SaveToFile(const System::UnicodeString FileName){ System::Classes::TStrings::SaveToFile(FileName); }
	inline void __fastcall  SaveToStream(System::Classes::TStream* Stream){ System::Classes::TStrings::SaveToStream(Stream); }
	
};


class PASCALIMPLEMENTATION TcxRichInnerEdit : public Vcl::Comctrls::TRichEdit
{
	typedef Vcl::Comctrls::TRichEdit inherited;
	
private:
	bool FAdvancedTypography;
	bool FAllowObjects;
	bool FAutoSelect;
	bool FAutoURLDetect;
	CHARRANGE FURLClickRange;
	System::Uitypes::TMouseButton FURLClickBtn;
	Cxtextedit::TcxEditEchoMode FEchoMode;
	bool FEscapePressed;
	TcxRichInnerEditHelper* FHelper;
	bool FInternalUpdating;
	bool FIsEraseBackgroundLocked;
	bool FKeyPressProcessed;
	int FLockBoundsCount;
	bool FMemoMode;
	TcxRichEditClass FRichEditClass;
	System::_di_IInterface FRichEditOle;
	System::TObject* FRichEditOleCallback;
	int FRichVersion;
	System::Variant FSavedEditValue;
	bool FSavedPlainText;
	bool FSelectionBar;
	TcxRichEditStreamModes FStreamModes;
	TcxRichEditStrings* FRichLines;
	double FZoomFactor;
	TcxRichEditQueryInsertObjectEvent FOnQueryInsertObject;
	void __fastcall CloseOleObjects(void);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	Cxedit::_di_IcxCustomInnerEdit __fastcall GetHelper(void);
	void __fastcall RestoreEditValue(void);
	void __fastcall StoreEditValue(void);
	bool __fastcall GetAdvancedTypography(void);
	bool __fastcall GetAutoURLDetect(void);
	TcxCustomRichEdit* __fastcall GetContainer(void);
	int __fastcall GetLineCount(void);
	int __fastcall GetLineIndex(int AIndex);
	int __fastcall GetLineLength(int AIndex);
	TcxRichEditStrings* __fastcall GetRichLines(void);
	_di_IcxRichEditOle __fastcall GetRichEditOle(void);
	TcxRichEditOleCallback* __fastcall GetRichEditOleCallBack(void);
	System::UnicodeString __fastcall GetTextRange(int AStartPos, int AEndPos);
	double __fastcall GetZoomFactor(void);
	void __fastcall InternalSetMemoMode(bool AForcedReload = false);
	void __fastcall SetAdvancedTypography(bool Value);
	void __fastcall SetAllowObjects(bool Value);
	void __fastcall SetAutoURLDetect(bool Value);
	void __fastcall SetMemoMode(bool Value);
	void __fastcall SetRichEditClass(TcxRichEditClass AValue);
	void __fastcall SetRichLines(TcxRichEditStrings* Value);
	void __fastcall SetSelectionBar(bool Value);
	void __fastcall SetOleControlActive(bool AActive);
	void __fastcall SetZoomFactor(const double Value);
	MESSAGE void __fastcall CMDocWindowActivate(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMChar(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall WMClear(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMCut(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMMButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	MESSAGE void __fastcall WMPaste(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFont(Winapi::Messages::TWMSetFont &Message);
	MESSAGE void __fastcall WMTimer(Winapi::Messages::TWMTimer &Message);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Winapi::Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Winapi::Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	MESSAGE void __fastcall EMReplaceSel(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMSetCharFormat(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMSetParaFormat(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall CNCommand(Winapi::Messages::TWMCommand &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall WMGetText(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetTextLength(Winapi::Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMSetText(Winapi::Messages::TWMSetText &Message);
	MESSAGE void __fastcall WMIMEComposition(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMExLineFromChar(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMLineLength(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPrintClient(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall BeforeInsertObject(bool &AAllowInsertObject, const GUID &ACLSID);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DestroyWindowHandle(void);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual System::UnicodeString __fastcall GetSelText(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall RequestAlign(void);
	virtual void __fastcall RequestSize(const System::Types::TRect &Rect);
	virtual void __fastcall RichCreateParams(Vcl::Controls::TCreateParams &Params, /* out */ int &ARichVersion);
	DYNAMIC void __fastcall URLClick(const System::UnicodeString AURLText, System::Uitypes::TMouseButton AButton);
	DYNAMIC void __fastcall URLMove(const System::UnicodeString AURLText);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	bool __fastcall CanPaste(void);
	void __fastcall CheckZoomFactor(void);
	virtual CHARRANGE __fastcall GetSelection(void);
	bool __fastcall AllowDrawEdgesAndBorders(void);
	__property bool AdvancedTypography = {read=GetAdvancedTypography, write=SetAdvancedTypography, default=0};
	__property bool AllowObjects = {read=FAllowObjects, write=SetAllowObjects, default=1};
	__property bool AutoSelect = {read=FAutoSelect, write=FAutoSelect, default=0};
	__property bool AutoURLDetect = {read=GetAutoURLDetect, write=SetAutoURLDetect, default=1};
	__property TcxCustomRichEdit* Container = {read=GetContainer};
	__property TcxRichInnerEditHelper* Helper = {read=FHelper};
	__property bool MemoMode = {read=FMemoMode, write=SetMemoMode, default=0};
	__property TcxRichEditClass RichEditClass = {read=FRichEditClass, write=SetRichEditClass, nodefault};
	__property _di_IcxRichEditOle RichEditOle = {read=GetRichEditOle};
	__property TcxRichEditOleCallback* RichEditOleCallBack = {read=GetRichEditOleCallBack};
	__property int RichVersion = {read=FRichVersion, write=FRichVersion, nodefault};
	__property bool SelectionBar = {read=FSelectionBar, write=SetSelectionBar, default=0};
	__property TcxRichEditStreamModes StreamModes = {read=FStreamModes, write=FStreamModes, default=0};
	__property double ZoomFactor = {read=GetZoomFactor, write=SetZoomFactor};
	__property TcxRichEditQueryInsertObjectEvent OnQueryInsertObject = {read=FOnQueryInsertObject, write=FOnQueryInsertObject};
	
public:
	__fastcall virtual TcxRichInnerEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxRichInnerEdit(void);
	virtual void __fastcall DefaultHandler(void *Message);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	HIDESBASE int __fastcall FindTexT(const System::UnicodeString ASearchStr, int AStartPos, int ALength, Vcl::Comctrls::TSearchTypes AOptions, bool AForward = true);
	bool __fastcall InsertObject(void);
	bool __fastcall ShowObjectProperties(void);
	bool __fastcall PasteSpecial(void);
	virtual void __fastcall Print(const System::UnicodeString Caption);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall CanFocus(void);
	virtual bool __fastcall CanRedo(void);
	virtual void __fastcall Redo(void);
	HIDESBASE virtual void __fastcall Undo(void);
	__property TcxRichEditStrings* RichLines = {read=GetRichLines, write=SetRichLines};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxRichInnerEdit(HWND ParentWindow) : Vcl::Comctrls::TRichEdit(ParentWindow) { }
	
private:
	void *__IcxPaintControlsHelper;	/* Cxgraphics::IcxPaintControlsHelper */
	void *__IcxInnerEditHelper;	/* Cxedit::IcxInnerEditHelper */
	void *__IcxContainerInnerControl;	/* Cxcontainer::IcxContainerInnerControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7EFAF634-E8D2-489D-9603-FCFC03ACA460}
	operator Cxgraphics::_di_IcxPaintControlsHelper()
	{
		Cxgraphics::_di_IcxPaintControlsHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgraphics::IcxPaintControlsHelper*(void) { return (Cxgraphics::IcxPaintControlsHelper*)&__IcxPaintControlsHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {35667555-6DC8-40D5-B705-B08D5697C621}
	operator Cxedit::_di_IcxInnerEditHelper()
	{
		Cxedit::_di_IcxInnerEditHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxInnerEditHelper*(void) { return (Cxedit::IcxInnerEditHelper*)&__IcxInnerEditHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator Cxcontainer::_di_IcxContainerInnerControl()
	{
		Cxcontainer::_di_IcxContainerInnerControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxContainerInnerControl; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxPaintControlsHelper; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
static const TcxRichEditClass cxMaxVersionRichEditClass = (TcxRichEditClass)(2);
static const TcxRichEditClass cxMinVersionRichEditClass = (TcxRichEditClass)(1);
extern PACKAGE int __fastcall AdjustRichLineBreaksW(System::WideChar * ADest, System::WideChar * ASource, bool AShortBreak = false);
extern PACKAGE int __fastcall AdjustRichLineBreaksA(char * ADest, char * ASource, bool AShortBreak = false);
extern PACKAGE int __fastcall AdjustRichLineBreaks(System::WideChar * ADest, System::WideChar * ASource, bool AShortBreak = false);
extern PACKAGE void __fastcall cxDrawRichEdit(HDC ADC, const System::Types::TRect &ARect, HWND ARichHandle, int AMinCharIndex, int AMaxCharIndex, bool ACalculateHeight, /* out */ int &AHeight)/* overload */;
extern PACKAGE void __fastcall cxDrawRichEdit(HDC ADC, const System::Types::TRect &ARect, const System::UnicodeString AText, TcxCustomRichEditProperties* AProperties, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor AColor, System::Uitypes::TColor ATextColor, bool ACalculateHeight, /* out */ int &AHeight)/* overload */;
extern PACKAGE void __fastcall cxDrawRichEdit(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, TcxRichEdit* ARichEdit, int AMinCharIndex, int AMaxCharIndex, bool ACalculateHeight, /* out */ int &AHeight)/* overload */;
extern PACKAGE System::AnsiString __fastcall dxBitmapToRTF(Vcl::Graphics::TBitmap* ABitmap);
extern PACKAGE void __fastcall SetRichEditText(Vcl::Comctrls::TRichEdit* ARichEdit, const System::Variant &AEditValue);
}	/* namespace Cxrichedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXRICHEDIT)
using namespace Cxrichedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxricheditHPP
