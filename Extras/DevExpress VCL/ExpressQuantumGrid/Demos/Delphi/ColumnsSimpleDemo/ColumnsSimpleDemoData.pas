unit ColumnsSimpleDemoData;

interface

uses
  SysUtils, Classes, DB, cxStyles, ImgList, Controls, cxGridTableView,
  cxGridBandedTableView, cxClasses, Forms, DBClient;

type
  TColumnsSimpleDemoDataDM = class(TDataModule)
    dsCars: TDataSource;
    dsOrders: TDataSource;
    dsCustomers: TDataSource;
    tblCars: TClientDataSet;
    tblOrders: TClientDataSet;
    tblCustomers: TClientDataSet;
    tblCustomersID: TIntegerField;
    tblCustomersFirstName: TStringField;
    tblCustomersLastName: TStringField;
    tblCustomersCompany: TStringField;
    tblCustomersPrefix: TStringField;
    tblCustomersTitle: TStringField;
    tblCustomersAddress: TStringField;
    tblCustomersCity: TStringField;
    tblCustomersState: TStringField;
    tblCustomersZipCode: TStringField;
    tblCustomersSource: TStringField;
    tblCustomersCustomer: TStringField;
    tblCustomersHomePhone: TStringField;
    tblCustomersFaxPhone: TStringField;
    tblCustomersSpouse: TStringField;
    tblCustomersOccupation: TStringField;
    tblCustomersDescription: TMemoField;
    PaymentTypeImages: TImageList;
    tblOrdersID: TAutoIncField;
    tblOrdersCustomerID: TIntegerField;
    tblOrdersProductID: TIntegerField;
    tblOrdersPurchaseDate: TDateTimeField;
    tblOrdersTime: TDateTimeField;
    tblOrdersPaymentType: TStringField;
    tblOrdersDescription: TMemoField;
    tblOrdersQuantity: TIntegerField;
    tblOrdersPaymentAmount: TCurrencyField;
    dsCities: TDataSource;
    tblCities: TClientDataSet;
    tblCarsID: TAutoIncField;
    tblCarsTrademark: TStringField;
    tblCarsModel: TStringField;
    tblCarsHP: TSmallintField;
    tblCarsLiter: TFloatField;
    tblCarsCyl: TSmallintField;
    tblCarsTransmissSpeedCount: TSmallintField;
    tblCarsTransmissAutomatic: TStringField;
    tblCarsMPG_City: TSmallintField;
    tblCarsMPG_Highway: TSmallintField;
    tblCarsCategory: TStringField;
    tblCarsDescription: TMemoField;
    tblCarsHyperlink: TStringField;
    tblCarsPicture: TBlobField;
    tblCarsPrice: TFloatField;
    tblCarsCar: TStringField;
    procedure tblCarsCalcFields(DataSet: TDataSet);
    procedure DataModuleCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  ColumnsSimpleDemoDataDM: TColumnsSimpleDemoDataDM;

implementation

{$R *.dfm}

uses
  DemoUtils;

procedure TColumnsSimpleDemoDataDM.tblCarsCalcFields(DataSet: TDataSet);
begin
  SetStringFieldValue(tblCarsCar, tblCarsTrademark.AsString + ' ' +
    tblCarsModel.AsString);
end;

procedure TColumnsSimpleDemoDataDM.DataModuleCreate(Sender: TObject);
var
  APath: string;
begin
  APath := ExtractFilePath(Application.ExeName) + '..\..\Data\';
  tblCars.LoadFromFile(APath + 'Cars.xml');
  tblOrders.LoadFromFile(APath + 'Orders.xml');
  tblCustomers.LoadFromFile(APath + 'Customers.xml');
  tblCities.LoadFromFile(APath + 'Cities.xml');
end;

end.
