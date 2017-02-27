// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridHeaderPopupMenuItems.pas' rev: 24.00 (Win32)

#ifndef CxgridheaderpopupmenuitemsHPP
#define CxgridheaderpopupmenuitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGridMenuOperations.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridheaderpopupmenuitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridHeaderPopupMenuOperation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridHeaderPopupMenuOperation : public Cxgridmenuoperations::TcxGridTableColumnMenuOperation
{
	typedef Cxgridmenuoperations::TcxGridTableColumnMenuOperation inherited;
	
public:
	/* TcxGridPopupMenuOperation.Create */ inline __fastcall virtual TcxGridHeaderPopupMenuOperation(void) : Cxgridmenuoperations::TcxGridTableColumnMenuOperation() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridHeaderPopupMenuOperation(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridSortingMenuOperation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridSortingMenuOperation : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetVisible(void);
	bool __fastcall IsSorted(void);
public:
	/* TcxGridPopupMenuOperation.Create */ inline __fastcall virtual TcxGridSortingMenuOperation(void) : TcxGridHeaderPopupMenuOperation() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridSortingMenuOperation(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridSortColumn;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridSortColumn : public TcxGridSortingMenuOperation
{
	typedef TcxGridSortingMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetDown(void);
	virtual bool __fastcall GetEnabled(void);
public:
	/* TcxGridPopupMenuOperation.Create */ inline __fastcall virtual TcxGridSortColumn(void) : TcxGridSortingMenuOperation() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridSortColumn(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridSortColumnAsc;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridSortColumnAsc : public TcxGridSortColumn
{
	typedef TcxGridSortColumn inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	
public:
	__fastcall virtual TcxGridSortColumnAsc(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridSortColumnAsc(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridSortColumnDesc;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridSortColumnDesc : public TcxGridSortColumn
{
	typedef TcxGridSortColumn inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	
public:
	__fastcall virtual TcxGridSortColumnDesc(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridSortColumnDesc(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridClearSorting;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridClearSorting : public TcxGridSortingMenuOperation
{
	typedef TcxGridSortingMenuOperation inherited;
	
protected:
	virtual bool __fastcall GetEnabled(void);
	
public:
	__fastcall virtual TcxGridClearSorting(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridClearSorting(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridGroupByThisField;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridGroupByThisField : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual bool __fastcall GetEnabled(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TcxGridGroupByThisField(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupByThisField(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridGroupByBox;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridGroupByBox : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetDown(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TcxGridGroupByBox(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupByBox(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridAlignmentSubMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridAlignmentSubMenu : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TcxGridAlignmentSubMenu(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridAlignmentSubMenu(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridAlign;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridAlign : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetDown(void);
	virtual bool __fastcall GetEnabled(void);
	
public:
	__classmethod virtual Cxgridmenuoperations::TcxGridPopupMenuOperationClass __fastcall GetParentOperationClass();
public:
	/* TcxGridPopupMenuOperation.Create */ inline __fastcall virtual TcxGridAlign(void) : TcxGridHeaderPopupMenuOperation() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridAlign(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridAlignLeft;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridAlignLeft : public TcxGridAlign
{
	typedef TcxGridAlign inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	
public:
	__fastcall virtual TcxGridAlignLeft(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridAlignLeft(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridAlignRight;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridAlignRight : public TcxGridAlign
{
	typedef TcxGridAlign inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	
public:
	__fastcall virtual TcxGridAlignRight(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridAlignRight(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridAlignCenter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridAlignCenter : public TcxGridAlign
{
	typedef TcxGridAlign inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	
public:
	__fastcall virtual TcxGridAlignCenter(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridAlignCenter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBestFit;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBestFit : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetEnabled(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TcxGridBestFit(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBestFit(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBestFitAllColumns;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBestFitAllColumns : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TcxGridBestFitAllColumns(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridBestFitAllColumns(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridRemoveColumn;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridRemoveColumn : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TcxGridRemoveColumn(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridRemoveColumn(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFieldChooser;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFieldChooser : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetDown(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	
public:
	__fastcall virtual TcxGridFieldChooser(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFieldChooser(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridShowFooter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridShowFooter : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetDown(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	
public:
	__fastcall virtual TcxGridShowFooter(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridShowFooter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridShowGroupFooter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridShowGroupFooter : public TcxGridHeaderPopupMenuOperation
{
	typedef TcxGridHeaderPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetDown(void);
	virtual bool __fastcall GetEnabled(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TcxGridShowGroupFooter(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridShowGroupFooter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridHeaderPopupMenuOperations;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridHeaderPopupMenuOperations : public Cxgridmenuoperations::TcxGridPopupMenuOperations
{
	typedef Cxgridmenuoperations::TcxGridPopupMenuOperations inherited;
	
protected:
	virtual void __fastcall AddItems(void);
public:
	/* TcxGridPopupMenuOperations.Create */ inline __fastcall virtual TcxGridHeaderPopupMenuOperations(void) : Cxgridmenuoperations::TcxGridPopupMenuOperations() { }
	/* TcxGridPopupMenuOperations.Destroy */ inline __fastcall virtual ~TcxGridHeaderPopupMenuOperations(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridheaderpopupmenuitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDHEADERPOPUPMENUITEMS)
using namespace Cxgridheaderpopupmenuitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridheaderpopupmenuitemsHPP
