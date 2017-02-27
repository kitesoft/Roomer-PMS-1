// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExtEditRepositoryItems.pas' rev: 24.00 (Win64)

#ifndef CxexteditrepositoryitemsHPP
#define CxexteditrepositoryitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxCheckComboBox.hpp>	// Pascal unit
#include <cxCheckGroup.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxFontNameComboBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxProgressBar.hpp>	// Pascal unit
#include <cxRichEdit.hpp>	// Pascal unit
#include <cxSpinButton.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxTrackBar.hpp>	// Pascal unit
#include <dxColorEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexteditrepositoryitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxEditRepositoryLabel;
class PASCALIMPLEMENTATION TcxEditRepositoryLabel : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxlabel::TcxLabelProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxlabel::TcxLabelProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxlabel::TcxLabelProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryLabel(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryLabel(void) { }
	
};


class DELPHICLASS TcxEditRepositoryProgressBar;
class PASCALIMPLEMENTATION TcxEditRepositoryProgressBar : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxprogressbar::TcxProgressBarProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxprogressbar::TcxProgressBarProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxprogressbar::TcxProgressBarProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryProgressBar(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryProgressBar(void) { }
	
};


class DELPHICLASS TcxEditRepositoryFontNameComboBox;
class PASCALIMPLEMENTATION TcxEditRepositoryFontNameComboBox : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxfontnamecombobox::TcxFontNameComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxfontnamecombobox::TcxFontNameComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxfontnamecombobox::TcxFontNameComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryFontNameComboBox(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryFontNameComboBox(void) { }
	
};


class DELPHICLASS TcxEditRepositoryColorComboBox;
class PASCALIMPLEMENTATION TcxEditRepositoryColorComboBox : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxcolorcombobox::TcxColorComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxcolorcombobox::TcxColorComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxcolorcombobox::TcxColorComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryColorComboBox(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryColorComboBox(void) { }
	
};


class DELPHICLASS TcxEditRepositoryColorEdit;
class PASCALIMPLEMENTATION TcxEditRepositoryColorEdit : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Dxcoloredit::TdxColorEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Dxcoloredit::TdxColorEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Dxcoloredit::TdxColorEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryColorEdit(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryColorEdit(void) { }
	
};


class DELPHICLASS TcxEditRepositoryTrackBar;
class PASCALIMPLEMENTATION TcxEditRepositoryTrackBar : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxtrackbar::TcxTrackBarProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxtrackbar::TcxTrackBarProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxtrackbar::TcxTrackBarProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryTrackBar(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryTrackBar(void) { }
	
};


class DELPHICLASS TcxEditRepositoryCheckComboBox;
class PASCALIMPLEMENTATION TcxEditRepositoryCheckComboBox : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxcheckcombobox::TcxCheckComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxcheckcombobox::TcxCheckComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxcheckcombobox::TcxCheckComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryCheckComboBox(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryCheckComboBox(void) { }
	
};


class DELPHICLASS TcxEditRepositoryCheckGroupItem;
class PASCALIMPLEMENTATION TcxEditRepositoryCheckGroupItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxcheckgroup::TcxCheckGroupProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxcheckgroup::TcxCheckGroupProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxcheckgroup::TcxCheckGroupProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryCheckGroupItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryCheckGroupItem(void) { }
	
};


class DELPHICLASS TcxEditRepositoryRichItem;
class PASCALIMPLEMENTATION TcxEditRepositoryRichItem : public Cxedit::TcxEditRepositoryItem
{
	typedef Cxedit::TcxEditRepositoryItem inherited;
	
private:
	Cxrichedit::TcxRichEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Cxrichedit::TcxRichEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	
__published:
	__property Cxrichedit::TcxRichEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxEditRepositoryItem.Create */ inline __fastcall virtual TcxEditRepositoryRichItem(System::Classes::TComponent* AOwner) : Cxedit::TcxEditRepositoryItem(AOwner) { }
	/* TcxEditRepositoryItem.Destroy */ inline __fastcall virtual ~TcxEditRepositoryRichItem(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxexteditrepositoryitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXTEDITREPOSITORYITEMS)
using namespace Cxexteditrepositoryitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexteditrepositoryitemsHPP
