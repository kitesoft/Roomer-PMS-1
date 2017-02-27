//---------------------------------------------------------------------------

#ifndef SimpleVerticalGridDemoDataH
#define SimpleVerticalGridDemoDataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxClasses.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxVGrid.hpp"
#include "dxmdaset.hpp"
//---------------------------------------------------------------------------
class TSimpleVerticalGridDemoMainDM : public TDataModule
{
__published:	// IDE-managed Components
  TDataSource *dsCars;
  TcxStyleRepository *cxStyleRepository;
  TcxStyle *cxStyle1;
  TcxStyle *cxStyle2;
  TcxStyle *cxStyle3;
  TcxStyle *cxStyle4;
  TcxStyle *cxStyle5;
  TcxStyle *cxStyle6;
  TcxStyle *cxStyle7;
  TcxStyle *cxStyle8;
  TcxVerticalGridStyleSheet *cxVerticalGridStyleSheetDevExpress;
	TdxMemData *mdCars;
	TAutoIncField *mdCarsID;
	TStringField *mdCarsTrademark;
	TStringField *mdCarsModel;
	TSmallintField *mdCarsHP;
	TFloatField *mdCarsLiter;
	TSmallintField *mdCarsCyl;
	TSmallintField *mdCarsTransmissSpeedCount;
	TStringField *mdCarsTransmissAutomatic;
	TSmallintField *mdCarsMPG_City;
	TSmallintField *mdCarsMPG_Highway;
	TStringField *mdCarsCategory;
	TMemoField *mdCarsDescription;
	TStringField *mdCarsHyperlink;
	TBlobField *mdCarsPicture;
	TFloatField *mdCarsPrice;
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TSimpleVerticalGridDemoMainDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSimpleVerticalGridDemoMainDM *SimpleVerticalGridDemoMainDM;
//---------------------------------------------------------------------------
#endif
