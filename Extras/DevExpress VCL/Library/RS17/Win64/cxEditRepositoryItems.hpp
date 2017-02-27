// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditRepositoryItems.pas' rev: 24.00 (Win64)

#ifndef CxeditrepositoryitemsHPP
#define CxeditrepositoryitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxCurrencyEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxBlobEdit.hpp>	// Pascal unit
#include <cxCalc.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxHyperLinkEdit.hpp>	// Pascal unit
#include <cxMRUEdit.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditrepositoryitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxEditRepositoryTextItem;
class PASCALIMPLEMENTATION TcxEditRepositoryTextItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxtextedit::TcxTextEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxtextedit::TcxTextEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxtextedit::TcxTextEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryTextItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryTextItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryButtonItem;
class PASCALIMPLEMENTATION TcxEditRepositoryButtonItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxbuttonedit::TcxButtonEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxbuttonedit::TcxButtonEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxbuttonedit::TcxButtonEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryButtonItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryButtonItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryImageItem;
class PASCALIMPLEMENTATION TcxEditRepositoryImageItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cximage::TcxImageProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cximage::TcxImageProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cximage::TcxImageProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryImageItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryImageItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryComboBoxItem;
class PASCALIMPLEMENTATION TcxEditRepositoryComboBoxItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxdropdownedit::TcxComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxdropdownedit::TcxComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxdropdownedit::TcxComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryComboBoxItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryComboBoxItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryMaskItem;
class PASCALIMPLEMENTATION TcxEditRepositoryMaskItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxmaskedit::TcxMaskEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxmaskedit::TcxMaskEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxmaskedit::TcxMaskEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryMaskItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryMaskItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryPopupItem;
class PASCALIMPLEMENTATION TcxEditRepositoryPopupItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxdropdownedit::TcxPopupEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxdropdownedit::TcxPopupEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxdropdownedit::TcxPopupEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryPopupItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryPopupItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryCalcItem;
class PASCALIMPLEMENTATION TcxEditRepositoryCalcItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxcalc::TcxCalcEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxcalc::TcxCalcEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxcalc::TcxCalcEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryCalcItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryCalcItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryDateItem;
class PASCALIMPLEMENTATION TcxEditRepositoryDateItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxcalendar::TcxDateEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxcalendar::TcxDateEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxcalendar::TcxDateEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryDateItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryDateItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryCurrencyItem;
class PASCALIMPLEMENTATION TcxEditRepositoryCurrencyItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxcurrencyedit::TcxCurrencyEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxcurrencyedit::TcxCurrencyEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxcurrencyedit::TcxCurrencyEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryCurrencyItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryCurrencyItem(void) { }
	
};


class DELPHICLASS TcxEditRepositorySpinItem;
class PASCALIMPLEMENTATION TcxEditRepositorySpinItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxspinedit::TcxSpinEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxspinedit::TcxSpinEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxspinedit::TcxSpinEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositorySpinItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositorySpinItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryMemoItem;
class PASCALIMPLEMENTATION TcxEditRepositoryMemoItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxmemo::TcxMemoProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxmemo::TcxMemoProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxmemo::TcxMemoProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryMemoItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryMemoItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryImageComboBoxItem;
class PASCALIMPLEMENTATION TcxEditRepositoryImageComboBoxItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cximagecombobox::TcxImageComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cximagecombobox::TcxImageComboBoxProperties* Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cximagecombobox::TcxImageComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryImageComboBoxItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryImageComboBoxItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryBlobItem;
class PASCALIMPLEMENTATION TcxEditRepositoryBlobItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxblobedit::TcxBlobEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxblobedit::TcxBlobEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxblobedit::TcxBlobEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryBlobItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryBlobItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryCheckBoxItem;
class PASCALIMPLEMENTATION TcxEditRepositoryCheckBoxItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxcheckbox::TcxCheckBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxcheckbox::TcxCheckBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxcheckbox::TcxCheckBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryCheckBoxItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryCheckBoxItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryTimeItem;
class PASCALIMPLEMENTATION TcxEditRepositoryTimeItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxtimeedit::TcxTimeEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxtimeedit::TcxTimeEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxtimeedit::TcxTimeEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryTimeItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryTimeItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryMRUItem;
class PASCALIMPLEMENTATION TcxEditRepositoryMRUItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxmruedit::TcxMRUEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxmruedit::TcxMRUEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxmruedit::TcxMRUEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryMRUItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryMRUItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryHyperLinkItem;
class PASCALIMPLEMENTATION TcxEditRepositoryHyperLinkItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxhyperlinkedit::TcxHyperLinkEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxhyperlinkedit::TcxHyperLinkEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxhyperlinkedit::TcxHyperLinkEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryHyperLinkItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryHyperLinkItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryRadioGroupItem;
class PASCALIMPLEMENTATION TcxEditRepositoryRadioGroupItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxradiogroup::TcxRadioGroupProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxradiogroup::TcxRadioGroupProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxradiogroup::TcxRadioGroupProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryRadioGroupItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryRadioGroupItem(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxeditrepositoryitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITREPOSITORYITEMS)
using namespace Cxeditrepositoryitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditrepositoryitemsHPP
