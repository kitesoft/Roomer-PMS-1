//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RealtorWorldStatistic.h"
#include "RealtorWorldDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RealtorWorldBaseFrame"
#pragma link "RealtorWorldHomePhotosBase"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridChartView"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBChartView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxSplitter"
#pragma link "cxStyles"
#pragma link "dxCustomTileControl"
#pragma link "dxTileControl"
#pragma resource "*.dfm"
TfrmStatistic *frmStatistic;
//---------------------------------------------------------------------------
__fastcall TfrmStatistic::TfrmStatistic(TComponent* Owner)
	: TfrmHomePhotosBase(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmStatistic::cxSplitter2BeforeClose(TObject *Sender, bool &AllowClose)

{
  AllowClose = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmStatistic::OnItemClick(TdxTileControlItem *Sender)
{
  int AHousesID = Sender->Tag;
  DMRealtorWorld->clHouseRating->Filter = "HouseID = " + IntToStr(AHousesID);
  DMRealtorWorld->clHousePrice->Filter = "HouseID = " + IntToStr(AHousesID);
  UpdateGridHousePrice();
  DMRealtorWorld->clHousesSimular->Filter = "HouseID = " + IntToStr(AHousesID);
}
//---------------------------------------------------------------------------
void __fastcall TfrmStatistic::UpdateGridHousePrice()
{
}
//---------------------------------------------------------------------------
