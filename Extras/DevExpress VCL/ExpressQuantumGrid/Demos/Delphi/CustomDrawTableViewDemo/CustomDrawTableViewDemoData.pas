unit CustomDrawTableViewDemoData;

interface

uses
  SysUtils, Classes, DB, cxStyles, cxClasses, cxGridTableView, Forms, DBClient;

type
  TCustomDrawTableViewDemoMainDM = class(TDataModule)
    StyleRepository: TcxStyleRepository;
    dsCars: TDataSource;
    dsCustomers: TDataSource;
    dsOrders: TDataSource;
    GridTableViewStyleSheetDevExpress: TcxGridTableViewStyleSheet;
    cxStyle1: TcxStyle;
    cxStyle2: TcxStyle;
    cxStyle3: TcxStyle;
    cxStyle4: TcxStyle;
    cxStyle5: TcxStyle;
    cxStyle6: TcxStyle;
    cxStyle7: TcxStyle;
    cxStyle8: TcxStyle;
    cxStyle9: TcxStyle;
    cxStyle10: TcxStyle;
    cxStyle11: TcxStyle;
    cxStyle12: TcxStyle;
    cxStyle13: TcxStyle;
    cxStyle14: TcxStyle;
    cdsCars: TClientDataSet;
    cdsCustomers: TClientDataSet;
    cdsOrders: TClientDataSet;
    cdsCustomersID: TAutoIncField;
    cdsCustomersFirstName: TStringField;
    cdsCustomersLastName: TStringField;
    cdsCustomersCompany: TStringField;
    cdsCustomersPrefix: TStringField;
    cdsCustomersTitle: TStringField;
    cdsCustomersAddress: TStringField;
    cdsCustomersCity: TStringField;
    cdsCustomersState: TStringField;
    cdsCustomersZipCode: TStringField;
    cdsCustomersSource: TStringField;
    cdsCustomersCustomer: TStringField;
    cdsCustomersHomePhone: TStringField;
    cdsCustomersFaxPhone: TStringField;
    cdsCustomersSpouse: TStringField;
    cdsCustomersOccupation: TStringField;
    cdsCustomersDescription: TMemoField;
    cdsCustomersEmail: TStringField;
    cdsOrdersID: TAutoIncField;
    cdsOrdersCustomerID: TIntegerField;
    cdsOrdersProductID: TIntegerField;
    cdsOrdersPurchaseDate: TDateTimeField;
    cdsOrdersTime: TDateTimeField;
    cdsOrdersPaymentType: TStringField;
    cdsOrdersDescription: TMemoField;
    cdsOrdersQuantity: TIntegerField;
    cdsOrdersPaymentAmount: TCurrencyField;
    cdsCarsID: TAutoIncField;
    cdsCarsTrademark: TStringField;
    cdsCarsModel: TStringField;
    cdsCarsHP: TSmallintField;
    cdsCarsLiter: TFloatField;
    cdsCarsCyl: TSmallintField;
    cdsCarsTransmissSpeedCount: TSmallintField;
    cdsCarsTransmissAutomatic: TStringField;
    cdsCarsMPG_City: TSmallintField;
    cdsCarsMPG_Highway: TSmallintField;
    cdsCarsCategory: TStringField;
    cdsCarsDescription: TMemoField;
    cdsCarsHyperlink: TStringField;
    cdsCarsPicture: TBlobField;
    cdsCarsPrice: TFloatField;
    cdsCarsCar: TStringField;
    procedure DataModuleCreate(Sender: TObject);
  end;

var
  CustomDrawTableViewDemoMainDM: TCustomDrawTableViewDemoMainDM;

implementation

{$R *.dfm}

procedure TCustomDrawTableViewDemoMainDM.DataModuleCreate(Sender: TObject);
begin
  cdsCars.LoadFromFile('..\..\Data\Cars.xml');
  cdsCars.Open;
  cdsCustomers.LoadFromFile('..\..\Data\CustomDrawTableViewDemo_Customers.xml');
  cdsCustomers.Open;
  cdsOrders.LoadFromFile('..\..\Data\CustomDrawTableViewDemo_Orders.xml');
  cdsOrders.Open;
end;

end.
