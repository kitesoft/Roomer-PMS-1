//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RealtorWorldBaseFrame.h"
#include "RealtorWorldAgents.h"
#include "RealtorWorldListing.h"
#include "RealtorWorldLoanCalculator.h"
#include "RealtorWorldMortgageRate.h"
#include "RealtorWorldResearch.h"
#include "RealtorWorldStatistic.h"
#include "RealtorWorldSystemInformation.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBase *frmBase;

const  IDFirst = 0;
const  IDPhotos = IDFirst;
const  IDResearch = 1;
const  IDAgents = 2;
const  IDStatistic = 3;
const  IDMortgageRate = 4;
const  IDLoanCalculator = 5;
const  IDSystemInformation = 6;
const  IDLast = IDSystemInformation;
//---------------------------------------------------------------------------
__fastcall TfrmBase::TfrmBase(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmBase::SelectItem(int APhotoID, int AAgentID)
{
}
//---------------------------------------------------------------------------
TfrmBase* __fastcall CreateFrameByID(TComponent* AOwner, int AID)
{
  TfrmBase* AFrame;
  switch (AID)
  {
		case IDPhotos:
		{
			AFrame = new TfrmListing(AOwner);
			break;
		}
		case IDResearch:
		{
			AFrame = new TfrmResearch(AOwner);
			break;
		}
		case IDAgents:
		{
			AFrame = new TfrmAgents(AOwner);
			break;
		}
		case IDStatistic:
		{
			AFrame = new TfrmStatistic(AOwner);
			break;
		}
		case IDMortgageRate:
		{
			AFrame = new TfrmMortgageRate(AOwner);
			break;
		}
		case IDLoanCalculator:
		{
			AFrame = new TfrmLoanCalculator(AOwner);
			break;
		}
		case IDSystemInformation:
		{
			AFrame = new TfrmSystemInformation(AOwner);
			break;
		}
  }
  return AFrame;
}
