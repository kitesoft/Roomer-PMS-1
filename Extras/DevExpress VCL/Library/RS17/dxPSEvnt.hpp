// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSEvnt.pas' rev: 24.00 (Win32)

#ifndef DxpsevntHPP
#define DxpsevntHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsevnt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSMPageParamsChangedEvent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSMPageParamsChangedEvent : public Dxpsesys::TdxEvent
{
	typedef Dxpsesys::TdxEvent inherited;
	
private:
	Dxpgsdlg::TBasedxPrintStyle* FPrintStyle;
	Dxprnpg::TdxPrinterPageUpdateCodes FUpdateCodes;
	
public:
	__fastcall TdxSMPageParamsChangedEvent(System::TObject* ASender, Dxpgsdlg::TBasedxPrintStyle* APrintStyle, Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	__property Dxpgsdlg::TBasedxPrintStyle* PrintStyle = {read=FPrintStyle};
	__property Dxprnpg::TdxPrinterPageUpdateCodes UpdateCodes = {read=FUpdateCodes, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSMPageParamsChangedEvent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSMStyleListChangedEvent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSMStyleListChangedEvent : public Dxpsesys::TdxEvent
{
	typedef Dxpsesys::TdxEvent inherited;
	
public:
	/* TdxEvent.Create */ inline __fastcall TdxSMStyleListChangedEvent(System::TObject* ASender) : Dxpsesys::TdxEvent(ASender) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSMStyleListChangedEvent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxStyleListChangedSubscriber;
class PASCALIMPLEMENTATION TdxStyleListChangedSubscriber : public Dxpsesys::TdxEventSubscriber
{
	typedef Dxpsesys::TdxEventSubscriber inherited;
	
private:
	System::Classes::TNotifyEvent FOnStyleListChanged;
	
protected:
	virtual void __fastcall DoProcessEvent(void);
	
public:
	DYNAMIC void __fastcall StyleListChanged(System::TObject* Sender);
	__property System::Classes::TNotifyEvent OnStyleListChanged = {read=FOnStyleListChanged, write=FOnStyleListChanged};
public:
	/* TdxEventSubscriber.Create */ inline __fastcall TdxStyleListChangedSubscriber(Dxpsesys::TdxEventClass const *AEventClasses, const int AEventClasses_Size) : Dxpsesys::TdxEventSubscriber(AEventClasses, AEventClasses_Size) { }
	/* TdxEventSubscriber.Destroy */ inline __fastcall virtual ~TdxStyleListChangedSubscriber(void) { }
	
};


class DELPHICLASS TdxPageParamsChangedSubscriber;
class PASCALIMPLEMENTATION TdxPageParamsChangedSubscriber : public Dxpsesys::TdxEventSubscriber
{
	typedef Dxpsesys::TdxEventSubscriber inherited;
	
private:
	Dxpgsdlg::TdxPageParamsChangedEvent FOnPageParamsChanged;
	
protected:
	virtual void __fastcall DoProcessEvent(void);
	
public:
	DYNAMIC void __fastcall PageParamsChanged(System::TObject* Sender, Dxpgsdlg::TBasedxPrintStyle* AStyle, Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	__property Dxpgsdlg::TdxPageParamsChangedEvent OnPageParamsChanged = {read=FOnPageParamsChanged, write=FOnPageParamsChanged};
public:
	/* TdxEventSubscriber.Create */ inline __fastcall TdxPageParamsChangedSubscriber(Dxpsesys::TdxEventClass const *AEventClasses, const int AEventClasses_Size) : Dxpsesys::TdxEventSubscriber(AEventClasses, AEventClasses_Size) { }
	/* TdxEventSubscriber.Destroy */ inline __fastcall virtual ~TdxPageParamsChangedSubscriber(void) { }
	
};


class DELPHICLASS TdxComponentPrinterEvent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxComponentPrinterEvent : public Dxpsesys::TdxEvent
{
	typedef Dxpsesys::TdxEvent inherited;
	
private:
	Dxpscore::TdxComponentPrinter* __fastcall GetComponentPrinter(void);
	
public:
	__property Dxpscore::TdxComponentPrinter* ComponentPrinter = {read=GetComponentPrinter};
public:
	/* TdxEvent.Create */ inline __fastcall TdxComponentPrinterEvent(System::TObject* ASender) : Dxpsesys::TdxEvent(ASender) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxComponentPrinterEvent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSPrintEvent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPrintEvent : public TdxComponentPrinterEvent
{
	typedef TdxComponentPrinterEvent inherited;
	
private:
	int FPageCount;
	int FPageIndex;
	Dxpscore::TBasedxReportLink* FReportLink;
	Dxpscore::TdxPSPrintStage FStage;
	
public:
	__fastcall TdxPSPrintEvent(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink, int APageIndex, int APageCount, Dxpscore::TdxPSPrintStage AStage);
	__property int PageCount = {read=FPageCount, nodefault};
	__property int PageIndex = {read=FPageIndex, nodefault};
	__property Dxpscore::TBasedxReportLink* ReportLink = {read=FReportLink};
	__property Dxpscore::TdxPSPrintStage Stage = {read=FStage, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSPrintEvent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSBuildEvent;
class PASCALIMPLEMENTATION TdxPSBuildEvent : public TdxComponentPrinterEvent
{
	typedef TdxComponentPrinterEvent inherited;
	
private:
	double FPercentCompleted;
	Dxpscore::TBasedxReportLink* FReportLink;
	Dxpscore::TdxPSBuildStage FStage;
	
public:
	__fastcall TdxPSBuildEvent(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink, const double APercentCompleted, Dxpscore::TdxPSBuildStage AStage);
	__property double PercentCompleted = {read=FPercentCompleted};
	__property Dxpscore::TBasedxReportLink* ReportLink = {read=FReportLink};
	__property Dxpscore::TdxPSBuildStage Stage = {read=FStage, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSBuildEvent(void) { }
	
};


class DELPHICLASS TdxPSPrintReportSubscriber;
class PASCALIMPLEMENTATION TdxPSPrintReportSubscriber : public Dxpsesys::TdxEventSubscriber
{
	typedef Dxpsesys::TdxEventSubscriber inherited;
	
private:
	Dxpscore::TdxReportLinkNotifyEvent FOnEndPrint;
	Dxpscore::TdxNewPageEvent FOnProgressPrint;
	Dxpscore::TdxStartPrintEvent FOnStartPrint;
	
protected:
	virtual void __fastcall DoProcessEvent(void);
	
public:
	DYNAMIC void __fastcall EndPrint(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall ProgressPrint(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink, int APageIndex);
	DYNAMIC void __fastcall StartPrint(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink, int APageCount);
	__property Dxpscore::TdxReportLinkNotifyEvent OnEndPrint = {read=FOnEndPrint, write=FOnEndPrint};
	__property Dxpscore::TdxNewPageEvent OnProgressPrint = {read=FOnProgressPrint, write=FOnProgressPrint};
	__property Dxpscore::TdxStartPrintEvent OnStartPrint = {read=FOnStartPrint, write=FOnStartPrint};
public:
	/* TdxEventSubscriber.Create */ inline __fastcall TdxPSPrintReportSubscriber(Dxpsesys::TdxEventClass const *AEventClasses, const int AEventClasses_Size) : Dxpsesys::TdxEventSubscriber(AEventClasses, AEventClasses_Size) { }
	/* TdxEventSubscriber.Destroy */ inline __fastcall virtual ~TdxPSPrintReportSubscriber(void) { }
	
};


class DELPHICLASS TdxPSBuildReportSubscriber;
class PASCALIMPLEMENTATION TdxPSBuildReportSubscriber : public Dxpsesys::TdxEventSubscriber
{
	typedef Dxpsesys::TdxEventSubscriber inherited;
	
private:
	Dxpscore::TdxReportLinkNotifyEvent FOnEndGenerateReport;
	Dxpscore::TdxGenerateReportProgressEvent FOnGenerateReportProgress;
	Dxpscore::TdxReportLinkNotifyEvent FOnStartGenerateReport;
	
protected:
	virtual void __fastcall DoProcessEvent(void);
	
public:
	DYNAMIC void __fastcall EndBuild(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall ProgressBuild(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink, double APercentCompleted);
	DYNAMIC void __fastcall StartBuild(System::TObject* Sender, Dxpscore::TBasedxReportLink* AReportLink);
	__property Dxpscore::TdxReportLinkNotifyEvent OnEndGenerateReport = {read=FOnEndGenerateReport, write=FOnEndGenerateReport};
	__property Dxpscore::TdxGenerateReportProgressEvent OnGenerateReportProgress = {read=FOnGenerateReportProgress, write=FOnGenerateReportProgress};
	__property Dxpscore::TdxReportLinkNotifyEvent OnStartGenerateReport = {read=FOnStartGenerateReport, write=FOnStartGenerateReport};
public:
	/* TdxEventSubscriber.Create */ inline __fastcall TdxPSBuildReportSubscriber(Dxpsesys::TdxEventClass const *AEventClasses, const int AEventClasses_Size) : Dxpsesys::TdxEventSubscriber(AEventClasses, AEventClasses_Size) { }
	/* TdxEventSubscriber.Destroy */ inline __fastcall virtual ~TdxPSBuildReportSubscriber(void) { }
	
};


class DELPHICLASS TdxHFTextEntriesChangedEvent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFTextEntriesChangedEvent : public Dxpsesys::TdxEvent
{
	typedef Dxpsesys::TdxEvent inherited;
	
public:
	/* TdxEvent.Create */ inline __fastcall TdxHFTextEntriesChangedEvent(System::TObject* ASender) : Dxpsesys::TdxEvent(ASender) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFTextEntriesChangedEvent(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxNoParamsEvent)(void);

class DELPHICLASS TdxHFTextEntriesChangedSubscriber;
class PASCALIMPLEMENTATION TdxHFTextEntriesChangedSubscriber : public Dxpsesys::TdxEventSubscriber
{
	typedef Dxpsesys::TdxEventSubscriber inherited;
	
private:
	TdxNoParamsEvent FOnHFTextEntriesChanged;
	
protected:
	virtual void __fastcall DoProcessEvent(void);
	
public:
	__property TdxNoParamsEvent OnHFTextEntriesChanged = {read=FOnHFTextEntriesChanged, write=FOnHFTextEntriesChanged};
public:
	/* TdxEventSubscriber.Create */ inline __fastcall TdxHFTextEntriesChangedSubscriber(Dxpsesys::TdxEventClass const *AEventClasses, const int AEventClasses_Size) : Dxpsesys::TdxEventSubscriber(AEventClasses, AEventClasses_Size) { }
	/* TdxEventSubscriber.Destroy */ inline __fastcall virtual ~TdxHFTextEntriesChangedSubscriber(void) { }
	
};


class DELPHICLASS TdxHFTextEntryChooseEvent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHFTextEntryChooseEvent : public Dxpsesys::TdxEvent
{
	typedef Dxpsesys::TdxEvent inherited;
	
private:
	System::UnicodeString FEntry;
	
public:
	__fastcall TdxHFTextEntryChooseEvent(System::TObject* Sender, const System::UnicodeString AEntry);
	__property System::UnicodeString Entry = {read=FEntry};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHFTextEntryChooseEvent(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxHFTextEntryEvent)(System::TObject* Sender, const System::UnicodeString AEntry);

class DELPHICLASS TdxHFTextEntryChooseSubscriber;
class PASCALIMPLEMENTATION TdxHFTextEntryChooseSubscriber : public Dxpsesys::TdxEventSubscriber
{
	typedef Dxpsesys::TdxEventSubscriber inherited;
	
private:
	TdxHFTextEntryEvent FOnHFTextEntryChoose;
	
protected:
	virtual void __fastcall DoProcessEvent(void);
	
public:
	__property TdxHFTextEntryEvent OnHFTextEntryChoose = {read=FOnHFTextEntryChoose, write=FOnHFTextEntryChoose};
public:
	/* TdxEventSubscriber.Create */ inline __fastcall TdxHFTextEntryChooseSubscriber(Dxpsesys::TdxEventClass const *AEventClasses, const int AEventClasses_Size) : Dxpsesys::TdxEventSubscriber(AEventClasses, AEventClasses_Size) { }
	/* TdxEventSubscriber.Destroy */ inline __fastcall virtual ~TdxHFTextEntryChooseSubscriber(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsevnt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSEVNT)
using namespace Dxpsevnt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsevntHPP
