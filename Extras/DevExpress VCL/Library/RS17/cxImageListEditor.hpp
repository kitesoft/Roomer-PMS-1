// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxImageListEditor.pas' rev: 24.00 (Win32)

#ifndef CximagelisteditorHPP
#define CximagelisteditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cximagelisteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxEditorImageInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditorImageInfo : public Cxgraphics::TcxImageInfo
{
	typedef Cxgraphics::TcxImageInfo inherited;
	
private:
	bool FAlphaUsed;
	
protected:
	virtual void __fastcall SetImage(Vcl::Graphics::TBitmap* Value);
	
public:
	__property bool AlphaUsed = {read=FAlphaUsed, nodefault};
public:
	/* TcxImageInfo.Create */ inline __fastcall TcxEditorImageInfo(void) : Cxgraphics::TcxImageInfo() { }
	/* TcxImageInfo.Destroy */ inline __fastcall virtual ~TcxEditorImageInfo(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxImageFileFormat
{
public:
	System::UnicodeString Name;
	System::UnicodeString Ext;
	Vcl::Graphics::TGraphicClass GraphicClass;
};


typedef System::DynamicArray<TcxImageFileFormat> TcxImageFileFormatList;

class DELPHICLASS TcxImageFileFormats;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImageFileFormats : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxImageFileFormatList FList;
	int __fastcall Count(void);
	TcxImageFileFormat __fastcall GetItem(int Index);
	__property TcxImageFileFormat Items[int Index] = {read=GetItem};
	
public:
	void __fastcall Register(const System::UnicodeString AName, const System::UnicodeString AExt, Vcl::Graphics::TGraphicClass AGraphicClass);
	Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(const System::UnicodeString AFileName);
	System::UnicodeString __fastcall GetFilter(void);
public:
	/* TObject.Create */ inline __fastcall TcxImageFileFormats(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxImageFileFormats(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomImageListEditorForm;
class DELPHICLASS TcxImageListEditor;
class PASCALIMPLEMENTATION TcxCustomImageListEditorForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
protected:
	TcxImageListEditor* FImageListEditor;
	void __fastcall DataChanged(System::TObject* Sender);
	virtual void __fastcall UpdateControls(void) = 0 ;
	virtual void __fastcall RestorePosition(void);
	virtual void __fastcall StorePosition(void);
	
public:
	__fastcall virtual TcxCustomImageListEditorForm(TcxImageListEditor* AImageListEditor);
	virtual Vcl::Comctrls::TListView* __fastcall GetVisualDataControl(void) = 0 ;
	virtual void __fastcall SetImportList(System::Classes::TStrings* AValue) = 0 ;
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomImageListEditorForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxCustomImageListEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomImageListEditorForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxCustomImageListEditorFormClass;

enum TcxImageListEditorAddMode : unsigned char { amAdd, amInsert, amReplace };

enum TcxImageType : unsigned char { itBitmap, itIco, itPNG };

class PASCALIMPLEMENTATION TcxImageListEditor : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FChanged;
	bool FImageListModified;
	Vcl::Comctrls::TListView* FDataControl;
	Cxgraphics::TcxImageList* FImageList;
	Cxgraphics::TcxImageList* FOriginalImageList;
	System::Classes::TStrings* FImportList;
	System::Classes::TStrings* FVisibleImportList;
	System::Uitypes::TModalResult FSplitBitmaps;
	int FUpdateCount;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall AddDataItems(Cxgraphics::TcxImageList* AImageList);
	void __fastcall AddImage(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, System::Uitypes::TColor AMaskColor, int &AInsertedImageIndex);
	void __fastcall Change(void);
	void __fastcall ClearSelection(void);
	void __fastcall DeleteDataItem(System::TObject* Sender, Vcl::Comctrls::TListItem* Item);
	void __fastcall DeleteImage(int AIndex);
	int __fastcall GetImagesCount(void);
	Vcl::Comctrls::TListItems* __fastcall GetDataItems(void);
	System::Uitypes::TColor __fastcall GetDefaultTransparentColor(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask);
	int __fastcall GetFocusedImageIndex(void);
	int __fastcall GetImageHeight(void);
	TcxEditorImageInfo* __fastcall GetImagesInfo(int Index);
	int __fastcall GetImageWidth(void);
	void __fastcall ImageListChanged(void);
	void __fastcall SelectDataItem(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, bool Selected);
	void __fastcall SetFocusedImageIndex(int AValue);
	void __fastcall SetImageList(Cxgraphics::TcxImageList* AValue);
	void __fastcall SetImagesInfo(int Index, TcxEditorImageInfo* AValue);
	void __fastcall SetImportList(System::Classes::TStrings* AValue);
	void __fastcall UpdateImageList(void);
	void __fastcall UpdateVisibleImportList(void);
	
protected:
	TcxCustomImageListEditorForm* FEditorForm;
	virtual TcxCustomImageListEditorFormClass __fastcall GetEditorFormClass(void);
	
public:
	__fastcall TcxImageListEditor(void);
	__fastcall virtual ~TcxImageListEditor(void);
	bool __fastcall Edit(Cxgraphics::TcxImageList* AImageList);
	void __fastcall ConvertTo32bit(void);
	void __fastcall AddImages(System::Classes::TStrings* AFiles, TcxImageListEditorAddMode AAddMode);
	void __fastcall ClearImages(void);
	void __fastcall DeleteSelectedImages(void);
	void __fastcall ExportImages(const System::UnicodeString AFileName, TcxImageType AFormat = (TcxImageType)(0x0));
	int __fastcall InternalAddImage(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, System::UnicodeString AFileName, int &AInsertedItemIndex, bool AMultiSelect);
	void __fastcall ImportImages(Vcl::Imglist::TCustomImageList* AImageList);
	void __fastcall MoveImage(int ASourceImageIndex, int ADestImageIndex);
	bool __fastcall IsAnyImageSelected(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	bool __fastcall IsUpdateLocked(void);
	void __fastcall ApplyChanges(void);
	bool __fastcall IsChanged(void);
	void __fastcall UpdateTransparentColor(System::Uitypes::TColor AColor);
	bool __fastcall ChangeImagesSize(const System::Types::TSize &AValue);
	void __fastcall SynchronizeData(int AStartIndex, int ACount);
	__property Vcl::Comctrls::TListView* DataControl = {read=FDataControl};
	__property Vcl::Comctrls::TListItems* DataItems = {read=GetDataItems};
	__property int FocusedImageIndex = {read=GetFocusedImageIndex, write=SetFocusedImageIndex, nodefault};
	__property int ImageHeight = {read=GetImageHeight, nodefault};
	__property Cxgraphics::TcxImageList* ImageList = {read=FImageList, write=SetImageList};
	__property bool ImageListModified = {read=FImageListModified, nodefault};
	__property int ImagesCount = {read=GetImagesCount, nodefault};
	__property TcxEditorImageInfo* ImagesInfo[int Index] = {read=GetImagesInfo, write=SetImagesInfo};
	__property int ImageWidth = {read=GetImageWidth, nodefault};
	__property System::Classes::TStrings* ImportList = {read=FImportList, write=SetImportList};
	__property Cxgraphics::TcxImageList* OriginalImageList = {read=FOriginalImageList};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxImageFileFormats* __fastcall cxImageFileFormats(void);
extern PACKAGE bool __fastcall cxEditImageList(Cxgraphics::TcxImageList* AImageList, System::Classes::TStrings* AImportList);
extern PACKAGE void __fastcall PngImageListTocxImageList(System::Classes::TComponent* APngImages, Cxgraphics::TcxImageList* AImages);
}	/* namespace Cximagelisteditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXIMAGELISTEDITOR)
using namespace Cximagelisteditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CximagelisteditorHPP
