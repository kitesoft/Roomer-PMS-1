// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxFEFDlg.pas' rev: 24.00 (Win32)

#ifndef DxfefdlgHPP
#define DxfefdlgHPP

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
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Grids.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Consts.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfefdlg
{
//-- type declarations -------------------------------------------------------
enum TdxFillAs : unsigned char { faNone, faTexture, faPattern, faPicture };

class DELPHICLASS TdxFEFDialog;
class PASCALIMPLEMENTATION TdxFEFDialog : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnApply;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnInvert;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnOtherTexture;
	Cxbuttons::TcxButton* btnPreview;
	Cxbuttons::TcxButton* btnSelectPicture;
	Cxcolorcombobox::TcxColorComboBox* cbxBackColor;
	Cxcolorcombobox::TcxColorComboBox* cbxForeColor;
	Cxdropdownedit::TcxComboBox* cbxPaintMode;
	Vcl::Grids::TDrawGrid* dgPattern;
	Vcl::Grids::TDrawGrid* dgTexture;
	Cxlabel::TcxLabel* lblBackground;
	Cxlabel::TcxLabel* lblForeground;
	Cxlabel::TcxLabel* lblPaintMode;
	Cxlabel::TcxLabel* lblSample;
	Vcl::Menus::TMenuItem* miCopy;
	Vcl::Menus::TMenuItem* miCut;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miLoad;
	Vcl::Menus::TMenuItem* miPaste;
	Vcl::Menus::TMenuItem* miPreview;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* N3;
	Cxpc::TcxPageControl* PageControl1;
	Vcl::Extctrls::TPaintBox* pbxPreview;
	Vcl::Menus::TPopupMenu* pmPicture;
	Cxlabel::TcxLabel* pnlPatternName;
	Cxlabel::TcxLabel* pnlPictureName;
	Cxgroupbox::TcxGroupBox* pnlPreview;
	Cxlabel::TcxLabel* pnlTextureName;
	Cxpc::TcxTabSheet* tshPattern;
	Cxpc::TcxTabSheet* tshPicture;
	Cxpc::TcxTabSheet* tshTexture;
	Vcl::Extctrls::TBevel* bvlPictureHolder;
	Cxgraphics::TcxImageList* ilMenu;
	void __fastcall dgTextureDrawCell(System::TObject* Sender, int Col, int Row, const System::Types::TRect &Rect, Vcl::Grids::TGridDrawState State);
	void __fastcall dgPatternDrawCell(System::TObject* Sender, int Col, int Row, const System::Types::TRect &Rect, Vcl::Grids::TGridDrawState State);
	void __fastcall btnApplyClick(System::TObject* Sender);
	void __fastcall btnInvertClick(System::TObject* Sender);
	void __fastcall btnOtherTextureClick(System::TObject* Sender);
	void __fastcall cbxColorChange(System::TObject* Sender);
	void __fastcall cbxPaintModeChange(System::TObject* Sender);
	void __fastcall dgPatternClick(System::TObject* Sender);
	void __fastcall dgPatternDblClick(System::TObject* Sender);
	void __fastcall dgPatternMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall dgTextureClick(System::TObject* Sender);
	void __fastcall dgTextureDblClick(System::TObject* Sender);
	void __fastcall dgTextureMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall lblShowCombo(System::TObject* Sender);
	void __fastcall miCopyClick(System::TObject* Sender);
	void __fastcall miCutClick(System::TObject* Sender);
	void __fastcall miDeleteClick(System::TObject* Sender);
	void __fastcall miPasteClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall pbxPicturePaint(System::TObject* Sender);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	void __fastcall PicturePreviewClick(System::TObject* Sender);
	void __fastcall pmPicturePopup(System::TObject* Sender);
	void __fastcall SelectPictureClick(System::TObject* Sender);
	
private:
	int FActivePage;
	bool FApplied;
	Dxbkgnd::TdxBackground* FBackground;
	Vcl::Graphics::TBitmap* FbmpPattern;
	Vcl::Graphics::TBitmap* FbmpCurrentPattern;
	Vcl::Graphics::TBitmap* FbmpTexture;
	bool FControlsUpdating;
	bool FFirstApplied;
	System::UnicodeString FInitialDir;
	bool FModified;
	Dxbkgnd::TdxBackground* FOriginalBackground;
	Vcl::Graphics::TGraphic* FOtherPicture;
	System::UnicodeString FOtherPictureName;
	Vcl::Graphics::TBitmap* FOtherTexture;
	System::UnicodeString FOtherTextureName;
	System::Classes::TStringList* FPatternNames;
	bool FPatternWasSelected;
	Vcl::Graphics::TGraphic* FPicture;
	bool FPictureExists;
	TdxFillAs FPreviewWhat;
	bool FTextureWasSelected;
	System::Classes::TStringList* FTextureNames;
	System::Classes::TNotifyEvent FOnApply;
	System::Uitypes::TColor __fastcall GetBackColor(void);
	System::Uitypes::TColor __fastcall GetForeColor(void);
	Vcl::Graphics::TGraphic* __fastcall GetOtherPicture(Vcl::Graphics::TGraphicClass AGraphicClass);
	Vcl::Graphics::TBitmap* __fastcall GetOtherTexture(void);
	Dxpsreportrendercanvas::TdxPicturePaintMode __fastcall GetPaintMode(void);
	Vcl::Graphics::TGraphic* __fastcall GetPicture(void);
	TdxFillAs __fastcall GetSelectWhat(void);
	void __fastcall SetBackColor(System::Uitypes::TColor Value);
	void __fastcall SetBackground(Dxbkgnd::TdxBackground* Value);
	void __fastcall SetForeColor(System::Uitypes::TColor Value);
	void __fastcall SetOtherTexture(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetPaintMode(Dxpsreportrendercanvas::TdxPicturePaintMode Value);
	void __fastcall SetPicture(Vcl::Graphics::TGraphic* Value);
	void __fastcall SetSelectWhat(TdxFillAs Value);
	void __fastcall AssignPicture(Vcl::Graphics::TGraphic* AImage);
	void __fastcall CheckModified(void);
	Vcl::Graphics::TBitmap* __fastcall CopyPattern(int I, int J);
	Vcl::Graphics::TBitmap* __fastcall CopyTexture(int I, int J);
	void __fastcall DrawSelectedFrame(Vcl::Grids::TDrawGrid* ADrawGrid, const System::Types::TRect &Rect);
	void __fastcall DoApply(void);
	void __fastcall DoInvertColors(void);
	void __fastcall DoPictureChanged(void);
	void __fastcall FreeAndNilResources(void);
	bool __fastcall InternalLoadImage(Vcl::Graphics::TGraphic* &AImage, const System::UnicodeString AFileName);
	void __fastcall LoadImage(Vcl::Graphics::TGraphic* &AImage, int AWhat);
	void __fastcall LoadResources(void);
	void __fastcall MapPatternColors(void);
	void __fastcall PaintPreview(void);
	void __fastcall SetupDialog(void);
	void __fastcall SetupDialogPatterns(void);
	void __fastcall SetupDialogTextures(void);
	void __fastcall StartSetting(void);
	void __fastcall UpdateControlsState(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Msg);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Msg);
	__property System::Uitypes::TColor BackColor = {read=GetBackColor, write=SetBackColor, nodefault};
	__property System::Uitypes::TColor ForeColor = {read=GetForeColor, write=SetForeColor, nodefault};
	__property Vcl::Graphics::TBitmap* OtherTexture = {read=GetOtherTexture, write=SetOtherTexture};
	__property Dxpsreportrendercanvas::TdxPicturePaintMode PaintMode = {read=GetPaintMode, write=SetPaintMode, nodefault};
	__property Vcl::Graphics::TGraphic* Picture = {read=GetPicture, write=SetPicture};
	__property TdxFillAs SelectWhat = {read=GetSelectWhat, write=SetSelectWhat, nodefault};
	
protected:
	Dxextctrls::TdxPSImageScrollBox* sbxPicture;
	virtual void __fastcall CreateInternalControls(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Loaded(void);
	
public:
	__fastcall virtual TdxFEFDialog(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxFEFDialog(void);
	bool __fastcall Execute(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property Dxbkgnd::TdxBackground* Background = {read=FBackground, write=SetBackground};
	__property System::Classes::TNotifyEvent OnApply = {read=FOnApply, write=FOnApply};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxFEFDialog(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxFEFDialog(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


typedef Vcl::Graphics::TGraphicClass __fastcall (*TdxGetGraphicClassProc)(const System::UnicodeString AFileName);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxGetGraphicClassProc GetGraphicClassProc;
extern PACKAGE bool __fastcall dxFEFDialog(Dxbkgnd::TdxBackground* ABackground);
extern PACKAGE Vcl::Graphics::TGraphicClass __fastcall StandardGetGraphicClassProc(const System::UnicodeString AFileName);
}	/* namespace Dxfefdlg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFEFDLG)
using namespace Dxfefdlg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfefdlgHPP
