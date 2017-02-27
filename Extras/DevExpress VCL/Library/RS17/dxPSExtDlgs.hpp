// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSExtDlgs.pas' rev: 24.00 (Win32)

#ifndef DxpsextdlgsHPP
#define DxpsextdlgsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsextdlgs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSOpenReportDialog;
class PASCALIMPLEMENTATION TdxPSOpenReportDialog : public Vcl::Dialogs::TOpenDialog
{
	typedef Vcl::Dialogs::TOpenDialog inherited;
	
private:
	Cxbuttons::TcxButton* btnPreview;
	System::UnicodeString FPrevFileName;
	System::Types::TRect FPreviewRect;
	Dxpscore::TdxPSReportDocument* FReportDocument;
	Vcl::Stdctrls::TLabel* lblPreview;
	Vcl::Extctrls::TPanel* pnlPicture;
	Vcl::Extctrls::TPanel* pnlToolBar;
	Dxextctrls::TdxPSImageScrollBox* sbxPreview;
	Vcl::Graphics::TGraphic* __fastcall GetGraphic(void);
	bool __fastcall GetHasDocument(void);
	bool __fastcall GetIsDocumentValid(void);
	void __fastcall PreviewClick(System::TObject* Sender);
	
protected:
	virtual bool __fastcall IsSelectedFileValid(void);
	virtual BOOL __fastcall TaskModalDialog(void * DialogFunc, void *DialogData);
	virtual void __fastcall CreateControls(void);
	DYNAMIC void __fastcall DoClose(void);
	DYNAMIC void __fastcall DoSelectionChange(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual void __fastcall Initialize(void);
	void __fastcall LoadReportDocument(void);
	virtual void __fastcall LoadStrings(void);
	void __fastcall PlacePreviewPanelInitial(void);
	void __fastcall PrepareToExecute(void);
	virtual void __fastcall UpdateControls(void);
	__property Vcl::Graphics::TGraphic* Graphic = {read=GetGraphic};
	__property bool HasDocument = {read=GetHasDocument, nodefault};
	__property bool IsDocumentValid = {read=GetIsDocumentValid, nodefault};
	__property System::Types::TRect PreviewRect = {read=FPreviewRect};
	__property Dxpscore::TdxPSReportDocument* ReportDocument = {read=FReportDocument};
	
public:
	__fastcall virtual TdxPSOpenReportDialog(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPSOpenReportDialog(void);
	virtual bool __fastcall Execute(void)/* overload */;
/* Hoisted overloads: */
	
public:
	inline bool __fastcall  Execute(HWND ParentWnd){ return Vcl::Dialogs::TOpenDialog::Execute(ParentWnd); }
	
};


class DELPHICLASS TdxPSSaveReportDialog;
class PASCALIMPLEMENTATION TdxPSSaveReportDialog : public TdxPSOpenReportDialog
{
	typedef TdxPSOpenReportDialog inherited;
	
public:
	__fastcall virtual TdxPSSaveReportDialog(System::Classes::TComponent* AOwner);
	virtual bool __fastcall Execute(void)/* overload */;
public:
	/* TdxPSOpenReportDialog.Destroy */ inline __fastcall virtual ~TdxPSSaveReportDialog(void) { }
	
/* Hoisted overloads: */
	
public:
	inline bool __fastcall  Execute(HWND ParentWnd){ return Vcl::Dialogs::TOpenDialog::Execute(ParentWnd); }
	
};


//-- var, const, procedure ---------------------------------------------------
#define sdxPicturePanel L"pnlPicture"
#define sdxPreviewButton L"btnPreview"
#define sdxPreviewLabel L"lblPreview"
#define sdxPreviewScrollBox L"sbxPreview"
#define sdxPreviewToolBar L"pnlToolBar"
}	/* namespace Dxpsextdlgs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSEXTDLGS)
using namespace Dxpsextdlgs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsextdlgsHPP
