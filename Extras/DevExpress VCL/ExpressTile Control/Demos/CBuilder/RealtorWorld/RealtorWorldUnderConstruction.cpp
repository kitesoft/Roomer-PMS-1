//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RealtorWorldUnderConstruction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RealtorWorldBaseFrame"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxImage"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxGDIPlusClasses"
#pragma resource "*.dfm"
TfrmUnderConstruction *frmUnderConstruction;
//---------------------------------------------------------------------------
__fastcall TfrmUnderConstruction::TfrmUnderConstruction(TComponent* Owner)
	: TfrmBase(Owner)
{
}
//---------------------------------------------------------------------------
