// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxThreading.pas' rev: 24.00 (Win64)

#ifndef DxthreadingHPP
#define DxthreadingHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SyncObjs.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxthreading
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TWorkItemObjectProc)(System::TObject* Sender, void * AContext);

typedef void __fastcall (*TWorkItemProc)(void * AContext);

class DELPHICLASS TdxThreadPoolHelper;
struct DECLSPEC_DRECORD TUserWorkItem
{
public:
	TdxThreadPoolHelper* ThreadPool;
	System::TObject* Sender;
	void *Context;
	TWorkItemObjectProc ObjectProc;
	TWorkItemProc Proc;
};


typedef System::StaticArray<TUserWorkItem, 32> TUserWorkItemArray;

class PASCALIMPLEMENTATION TdxThreadPoolHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCount;
	System::Sysutils::Exception* FException;
	int FIndex;
	System::Syncobjs::TSimpleEvent* FEvent;
	TUserWorkItemArray FWorkItems;
	void __fastcall DoneWorkItems(void);
	
protected:
	void __fastcall DoHandleException(void);
	void __fastcall HandleException(void);
	void __fastcall ResetException(void);
	void __fastcall SetException(void);
	
public:
	__fastcall TdxThreadPoolHelper(void);
	__fastcall virtual ~TdxThreadPoolHelper(void);
	void __fastcall CreateEvent(void);
	void __fastcall DestroyEvent(void);
	void __fastcall Initialize(int ANumThreads, bool ACreateEvent = false);
	void __fastcall QueueWorkItem(System::TObject* ASender, TWorkItemObjectProc AObjectProc, void * AContext)/* overload */;
	void __fastcall QueueWorkItem(System::TObject* ASender, TWorkItemObjectProc AObjectProc, void * AContext, unsigned AFlags)/* overload */;
	void __fastcall QueueWorkItem(TWorkItemProc AProc, void * AContext)/* overload */;
	void __fastcall QueueWorkItem(TWorkItemProc AProc, void * AContext, unsigned AFlags)/* overload */;
	void __fastcall WaitForThreads(bool ADestroyEvent = false);
};


class DELPHICLASS TdxMultithreadOperation;
class PASCALIMPLEMENTATION TdxMultithreadOperation : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FLocked;
	int FThreadCount;
	TdxThreadPoolHelper* FThreadPoolHelper;
	
protected:
	__property int ThreadCount = {read=FThreadCount, nodefault};
	__property TdxThreadPoolHelper* ThreadPoolHelper = {read=FThreadPoolHelper};
	
public:
	__fastcall virtual TdxMultithreadOperation(int AThreadCount)/* overload */;
	__fastcall virtual TdxMultithreadOperation(void)/* overload */;
	__fastcall virtual ~TdxMultithreadOperation(void);
	bool __fastcall Lock(void);
	void __fastcall Unlock(void);
};


struct DECLSPEC_DRECORD TSortWorkItem
{
public:
	Dxcoreclasses::TdxPointerList *List;
	int StartIndex;
	int EndIndex;
};


typedef TSortWorkItem *PSortWorkItem;

typedef System::StaticArray<TSortWorkItem, 32> TSortWorkItemArray;

struct DECLSPEC_DRECORD TMergeWorkItem
{
public:
	Dxcoreclasses::TdxPointerList *List;
	Dxcoreclasses::TdxPointerList *Temp;
	int StartIndex;
	int MiddleIndex;
	int EndIndex;
};


typedef TMergeWorkItem *PMergeWorkItem;

typedef System::StaticArray<TMergeWorkItem, 32> TMergeWorkItemArray;

class DELPHICLASS TdxMultithreadedSort;
class PASCALIMPLEMENTATION TdxMultithreadedSort : public TdxMultithreadOperation
{
	typedef TdxMultithreadOperation inherited;
	
private:
	Dxcoreclasses::TCompareItems FCompareClassFunc;
	System::Classes::TListSortCompare FCompareFunc;
	int FCount;
	int FSortChunkCount;
	TSortWorkItemArray FSortChunks;
	void __fastcall CalculateChunkCount(int AItemCount);
	void __fastcall Initialize(int ACount);
	void __fastcall MergeChunks(Dxcoreclasses::PdxPointerList AList);
	void __fastcall ParallelMerge(System::TObject* Sender, void * AContext);
	void __fastcall ParallelSort(System::TObject* Sender, void * AContext);
	void __fastcall SortListChunks(Dxcoreclasses::PdxPointerList AList);
	
public:
	__fastcall virtual TdxMultithreadedSort(int AThreadCount)/* overload */;
	void __fastcall Sort(Dxcoreclasses::PdxPointerList AList, int ACount, const Dxcoreclasses::TCompareItems ACompareFunc)/* overload */;
	void __fastcall Sort(Dxcoreclasses::TdxFastList* AList, const Dxcoreclasses::TCompareItems ACompareFunc)/* overload */;
	void __fastcall Sort(Dxcoreclasses::PdxPointerList AList, int ACount, const System::Classes::TListSortCompare ACompareFunc)/* overload */;
	void __fastcall Sort(Dxcoreclasses::TdxFastList* AList, const System::Classes::TListSortCompare ACompareFunc)/* overload */;
public:
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxMultithreadedSort(void)/* overload */ : TdxMultithreadOperation() { }
	/* TdxMultithreadOperation.Destroy */ inline __fastcall virtual ~TdxMultithreadedSort(void) { }
	
};


struct DECLSPEC_DRECORD TIterateChunkWorkItem
{
public:
	void *Context;
	int StartIndex;
	int EndIndex;
};


typedef TIterateChunkWorkItem *PIterateChunkWorkItem;

typedef System::StaticArray<TIterateChunkWorkItem, 32> TIterateChunkWorkItemArray;

class DELPHICLASS TdxCustomMultithreadedIterator;
class PASCALIMPLEMENTATION TdxCustomMultithreadedIterator : public TdxMultithreadOperation
{
	typedef TdxMultithreadOperation inherited;
	
private:
	int FCount;
	int FStartIndex;
	int FEndIndex;
	int FFinishedIndex;
	int FChunkCount;
	TIterateChunkWorkItemArray FChunks;
	
protected:
	virtual void * __fastcall GetChunkContext(int AChunkIndex, void * AContext);
	bool __fastcall Initialize(int AStartIndex, int AEndIndex);
	virtual void __fastcall InitializeChunksEnvironment(void);
	__property int ChunkCount = {read=FChunkCount, nodefault};
public:
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxCustomMultithreadedIterator(int AThreadCount)/* overload */ : TdxMultithreadOperation(AThreadCount) { }
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxCustomMultithreadedIterator(void)/* overload */ : TdxMultithreadOperation() { }
	/* TdxMultithreadOperation.Destroy */ inline __fastcall virtual ~TdxCustomMultithreadedIterator(void) { }
	
};


typedef bool __fastcall (__closure *TdxIterateItemFunc)(void * AContext, int AIndex);

class DELPHICLASS TdxMultithreadedIterator;
class PASCALIMPLEMENTATION TdxMultithreadedIterator : public TdxCustomMultithreadedIterator
{
	typedef TdxCustomMultithreadedIterator inherited;
	
private:
	TdxIterateItemFunc FItemFunc;
	
protected:
	void __fastcall ProcessChunk(System::TObject* AContext, void * AWorkItem);
	int __fastcall ProcessChunks(void * AContext, const TdxIterateItemFunc AItemFunc);
	
public:
	int __fastcall IterateItems(int AStartIndex, int AEndIndex, void * AContext, const TdxIterateItemFunc AItemFunc);
public:
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxMultithreadedIterator(int AThreadCount)/* overload */ : TdxCustomMultithreadedIterator(AThreadCount) { }
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxMultithreadedIterator(void)/* overload */ : TdxCustomMultithreadedIterator() { }
	/* TdxMultithreadOperation.Destroy */ inline __fastcall virtual ~TdxMultithreadedIterator(void) { }
	
};


typedef bool __fastcall (__closure *TdxIterateItemObjectFunc)(void * AContext, int AIndex);

class DELPHICLASS TdxMultithreadedClassMethodIterator;
class PASCALIMPLEMENTATION TdxMultithreadedClassMethodIterator : public TdxCustomMultithreadedIterator
{
	typedef TdxCustomMultithreadedIterator inherited;
	
private:
	TdxIterateItemObjectFunc FItemObjectFunc;
	
protected:
	void __fastcall ProcessChunk(System::TObject* AContext, void * AWorkItem);
	int __fastcall ProcessChunks(void * AContext, const TdxIterateItemObjectFunc AItemObjectFunc);
	
public:
	int __fastcall IterateItems(int AStartIndex, int AEndIndex, void * AContext, const TdxIterateItemObjectFunc AItemObjectFunc);
public:
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxMultithreadedClassMethodIterator(int AThreadCount)/* overload */ : TdxCustomMultithreadedIterator(AThreadCount) { }
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxMultithreadedClassMethodIterator(void)/* overload */ : TdxCustomMultithreadedIterator() { }
	/* TdxMultithreadOperation.Destroy */ inline __fastcall virtual ~TdxMultithreadedClassMethodIterator(void) { }
	
};


typedef bool __fastcall (__closure *TdxFastListItemFunc)(Dxcoreclasses::TdxFastList* AList, int AIndex);

typedef bool __fastcall (__closure *TdxListItemFunc)(System::Classes::TList* AList, int AIndex);

typedef bool __fastcall (__closure *TdxStringsListItemFunc)(System::Classes::TStrings* AStrings, int AIndex);

class DELPHICLASS TdxMultithreadedListIterator;
class PASCALIMPLEMENTATION TdxMultithreadedListIterator : public TdxMultithreadedClassMethodIterator
{
	typedef TdxMultithreadedClassMethodIterator inherited;
	
protected:
	int __fastcall DoIterate(int ACount, void * AContext, const TdxIterateItemObjectFunc AItemObjectFunc);
	
public:
	int __fastcall Iterate(void * AContext, int ACount, const TdxIterateItemObjectFunc AItemFunc)/* overload */;
	int __fastcall Iterate(Dxcoreclasses::TdxFastList* AList, const TdxFastListItemFunc AItemFunc)/* overload */;
	int __fastcall Iterate(System::Classes::TList* AList, const TdxListItemFunc AItemFunc)/* overload */;
	int __fastcall Iterate(System::Classes::TStrings* AStrings, const TdxStringsListItemFunc AItemFunc)/* overload */;
public:
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxMultithreadedListIterator(int AThreadCount)/* overload */ : TdxMultithreadedClassMethodIterator(AThreadCount) { }
	/* TdxMultithreadOperation.Create */ inline __fastcall virtual TdxMultithreadedListIterator(void)/* overload */ : TdxMultithreadedClassMethodIterator() { }
	/* TdxMultithreadOperation.Destroy */ inline __fastcall virtual ~TdxMultithreadedListIterator(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const unsigned WT_EXECUTEDEFAULT = unsigned(0x0);
static const unsigned WT_EXECUTEINIOTHREAD = unsigned(0x1);
static const unsigned WT_EXECUTEINUITHREAD = unsigned(0x2);
static const unsigned WT_EXECUTEINWAITTHREAD = unsigned(0x4);
static const unsigned WT_EXECUTEONLYONCE = unsigned(0x8);
static const unsigned WT_EXECUTEINTIMERTHREAD = unsigned(0x20);
static const unsigned WT_EXECUTELONGFUNCTION = unsigned(0x10);
static const unsigned WT_EXECUTEINPERSISTENTIOTHREAD = unsigned(0x40);
static const unsigned WT_EXECUTEINPERSISTENTTHREAD = unsigned(0x80);
static const unsigned WT_TRANSFER_IMPERSONATION = unsigned(0x100);
static const System::Int8 dxMaxUserWorkItems = System::Int8(0x20);
extern PACKAGE bool dxEnableMultiThreading;
extern PACKAGE TdxMultithreadedSort* dxSortHelper;
extern PACKAGE TdxMultithreadedListIterator* dxListIterator;
extern PACKAGE bool __fastcall dxCanUseMultiThreading(void);
}	/* namespace Dxthreading */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTHREADING)
using namespace Dxthreading;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxthreadingHPP
