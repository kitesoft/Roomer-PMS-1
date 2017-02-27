// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPropertiesConverters.pas' rev: 24.00 (Win32)

#ifndef CxpropertiesconvertersHPP
#define CxpropertiesconvertersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxCustomConverter.hpp>	// Pascal unit
#include <cxBlobEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxConverterUtils.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxCalc.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCurrencyEdit.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxDBLookupComboBox.hpp>	// Pascal unit
#include <cxHyperLinkEdit.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxMRUEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpropertiesconverters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomPropertiesConverter : public Cxcustomconverter::TcxCustomConverter
{
	typedef Cxcustomconverter::TcxCustomConverter inherited;
	
protected:
	Cximage::TcxImageTransparency __fastcall ConvertPictureTransparency(const System::UnicodeString AValue);
	Cxedit::TcxEditVertAlignment __fastcall ConvertVertAlignment(const System::UnicodeString AVertAlignment);
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxCustomPropertiesConverter(System::TObject* ADestination) : Cxcustomconverter::TcxCustomConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxBlobEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBlobEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxblobedit::TcxBlobEditKind __fastcall ConvertBlobEditKind(const System::UnicodeString AKind);
	Cxblobedit::TcxBlobPaintStyle __fastcall ConvertBlobPaintStyle(const System::UnicodeString AStyle);
	Cxblobedit::TcxBlobEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxblobedit::TcxBlobEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxBlobEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBlobEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxButtonEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxButtonEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxedit::TcxEditButtonKind __fastcall ConvertButtonKind(const System::UnicodeString AButtonKind);
	Cxbuttonedit::TcxButtonEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxbuttonedit::TcxButtonEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxButtonEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxButtonEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCalcEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCalcEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxcalc::TcxCalcEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxcalc::TcxCalcEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxCalcEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCalcEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCheckBoxPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCheckBoxPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxcheckbox::TcxCheckBoxNullValueShowingStyle __fastcall ConvertNullFieldStyle(const System::UnicodeString AValue);
	Cxcheckbox::TcxCheckBoxProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxcheckbox::TcxCheckBoxProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxCheckBoxPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCheckBoxPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxComboBoxPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxComboBoxPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxdropdownedit::TcxComboBoxProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxdropdownedit::TcxComboBoxProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxComboBoxPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxComboBoxPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCurrencyEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCurrencyEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxcurrencyedit::TcxCurrencyEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxcurrencyedit::TcxCurrencyEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxCurrencyEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCurrencyEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDateEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDateEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxcalendar::TcxDateEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxcalendar::TcxDateEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxDateEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDateEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxHyperLinkEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxHyperLinkEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxhyperlinkedit::TcxHyperLinkEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxhyperlinkedit::TcxHyperLinkEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxHyperLinkEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxHyperLinkEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxImagePropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImagePropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cximage::TcxImageProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cximage::TcxImageProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxImagePropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxImagePropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxImageComboBoxPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImageComboBoxPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cximagecombobox::TcxImageComboBoxProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cximagecombobox::TcxImageComboBoxProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxImageComboBoxPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxImageComboBoxPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxLookupComboBoxPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLookupComboBoxPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxdblookupcombobox::TcxLookupComboBoxProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxdblookupcombobox::TcxLookupComboBoxProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxLookupComboBoxPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxLookupComboBoxPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxMaskEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMaskEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxmaskedit::TcxMaskEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxmaskedit::TcxMaskEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxMaskEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxMaskEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxMemoPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMemoPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxmemo::TcxMemoProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxmemo::TcxMemoProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxMemoPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxMemoPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxMRUEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMRUEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxmruedit::TcxMRUEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxmruedit::TcxMRUEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxMRUEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxMRUEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPopupEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPopupEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxdropdownedit::TcxPopupEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxdropdownedit::TcxPopupEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxPopupEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPopupEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSpinEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSpinEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxspinedit::TcxSpinEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxspinedit::TcxSpinEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxSpinEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSpinEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTextEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTextEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxtextedit::TcxTextEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxtextedit::TcxTextEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxTextEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTextEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxTimeEditPropertiesConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTimeEditPropertiesConverter : public TcxCustomPropertiesConverter
{
	typedef TcxCustomPropertiesConverter inherited;
	
private:
	Cxtimeedit::TcxTimeEditTimeFormat __fastcall ConvertTimeFormat(const System::UnicodeString AFormat);
	Cxtimeedit::TcxTimeEditProperties* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	
public:
	__property Cxtimeedit::TcxTimeEditProperties* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxTimeEditPropertiesConverter(System::TObject* ADestination) : TcxCustomPropertiesConverter(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTimeEditPropertiesConverter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpropertiesconverters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPROPERTIESCONVERTERS)
using namespace Cxpropertiesconverters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpropertiesconvertersHPP
