//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GridMenuViewsDemoData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma resource "*.dfm"
TGridMenuViewsDemoDataDM *GridMenuViewsDemoDataDM;
//---------------------------------------------------------------------------
__fastcall TGridMenuViewsDemoDataDM::TGridMenuViewsDemoDataDM(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TGridMenuViewsDemoDataDM::DataModuleCreate(TObject *Sender)
{
  cdsCustomers->LoadFromFile("..\\..\\Data\\Customers.xml");
  cdsCustomers->Open();
  cdsCars->LoadFromFile("..\\..\\Data\\Cars.xml");
  cdsCars->Open();
  cdsOrders->LoadFromFile("..\\..\\Data\\Orders.xml");
  cdsOrders->Open();
}
//---------------------------------------------------------------------------

void __fastcall TGridMenuViewsDemoDataDM::cdsCarsCalcFields(TDataSet *DataSet)
{
  cdsCarsCarName->AsString = cdsCarsTrademark->AsString + ' ' +
    cdsCarsModel->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TGridMenuViewsDemoDataDM::cdsOrdersCalcFields(TDataSet *DataSet)
{
  String s;
  DateTimeToString( s, "mmmm", cdsOrdersPurchaseDate->AsDateTime);
  cdsOrdersPurchaseMonth->AsString = s;
}
//---------------------------------------------------------------------------

