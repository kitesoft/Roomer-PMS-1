unit SummaryFooterDemoData;

interface

uses
  Forms,
  SysUtils, Classes, DB, cxStyles, ImgList, Controls, cxClasses,
  cxGridTableView, DemoUtils, DBClient;

type
  TSummaryFooterDemoDataDM = class(TDataModule)
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
    tblCustomersName: TStringField;
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
    procedure tblCustomersCalcFields(DataSet: TDataSet);
    procedure DataModuleCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  SummaryFooterDemoDataDM: TSummaryFooterDemoDataDM;

implementation

{$R *.dfm}

procedure TSummaryFooterDemoDataDM.tblCustomersCalcFields(DataSet: TDataSet);
begin
  SetStringFieldValue(tblCustomersName,
    tblCustomersFirstName.Value + ' ' + tblCustomersLastName.Value);
end;

procedure TSummaryFooterDemoDataDM.DataModuleCreate(Sender: TObject);
var
  APath: string;
begin
  APath := ExtractFilePath(Application.ExeName) + '..\..\Data\';
  tblCars.LoadFromFile(APath + 'Cars.xml');
  tblCustomers.LoadFromFile(APath + 'Customers.xml');
  tblOrders.LoadFromFile(APath + 'Orders.xml');
end;

end.
