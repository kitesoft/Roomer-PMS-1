// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellDlgs.pas' rev: 24.00 (Win32)

#ifndef CxshelldlgsHPP
#define CxshelldlgsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxShellCommon.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxshelldlgs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDlgShellOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDlgShellOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FContextMenus;
	bool FShowFolders;
	bool FShowHidden;
	bool FShowNonFolders;
	bool FShowToolTip;
	bool FTrackShellChanges;
	
public:
	__fastcall TcxDlgShellOptions(void);
	
__published:
	__property bool ContextMenus = {read=FContextMenus, write=FContextMenus, default=1};
	__property bool ShowFolders = {read=FShowFolders, write=FShowFolders, default=1};
	__property bool ShowHidden = {read=FShowHidden, write=FShowHidden, default=0};
	__property bool ShowNonFolders = {read=FShowNonFolders, write=FShowNonFolders, default=0};
	__property bool ShowToolTip = {read=FShowToolTip, write=FShowToolTip, default=1};
	__property bool TrackShellChanges = {read=FTrackShellChanges, write=FTrackShellChanges, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDlgShellOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDlgShellRoot;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDlgShellRoot : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString fCustomPath;
	Cxshellcommon::TcxBrowseFolder fBroFold;
	
public:
	__fastcall TcxDlgShellRoot(void);
	
__published:
	__property Cxshellcommon::TcxBrowseFolder BrowseFolder = {read=fBroFold, write=fBroFold, default=11};
	__property System::UnicodeString CustomPath = {read=fCustomPath, write=fCustomPath};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDlgShellRoot(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxshelldlgs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLDLGS)
using namespace Cxshelldlgs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshelldlgsHPP
