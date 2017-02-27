//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ColumnsMultiEditorsDemoData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxStyles"
#pragma link "cxTL"
#pragma link "dxmdaset"
#pragma resource "*.dfm"
TColumnsMultiEditorsDemoDataDM *ColumnsMultiEditorsDemoDataDM;
//---------------------------------------------------------------------------
__fastcall TColumnsMultiEditorsDemoDataDM::TColumnsMultiEditorsDemoDataDM(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TColumnsMultiEditorsDemoDataDM::DataModuleCreate(TObject *Sender)

{
  mdPersons->LoadFromBinaryFile("..\\..\\Data\\Persons.dat");
  mdPersons->Open();
}
//---------------------------------------------------------------------------

