unit GridMenuViewsDemoData;

interface

uses

  Forms,

  SysUtils, Classes, DB, cxStyles, ImgList, Controls, cxClasses,
  cxGridTableView, DBClient;

type
  TGridMenuViewsDemoDataDM = class(TDataModule)
    dsCars: TDataSource;
    dsOrders: TDataSource;
    dsCustomers: TDataSource;
    PaymentTypeImages: TImageList;
    cdsCars: TClientDataSet;
    cdsOrders: TClientDataSet;
    cdsCustomers: TClientDataSet;
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
    cdsCarsCarName: TStringField;
    cdsOrdersPurchaseMonth: TStringField;
    procedure DataModuleCreate(Sender: TObject);
    procedure cdsOrdersCalcFields(DataSet: TDataSet);
    procedure cdsCarsCalcFields(DataSet: TDataSet);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  GridMenuViewsDemoDataDM: TGridMenuViewsDemoDataDM;

implementation

{$R *.dfm}

procedure TGridMenuViewsDemoDataDM.DataModuleCreate(Sender: TObject);
begin
  cdsCars.LoadFromFile('..\..\Data\Cars.xml');
  cdsCars.Open;
  cdsOrders.LoadFromFile('..\..\Data\Orders.xml');
  cdsOrders.Open;
  cdsCustomers.LoadFromFile('..\..\Data\Customers.xml');
  cdsCustomers.Open;
end;

procedure TGridMenuViewsDemoDataDM.cdsOrdersCalcFields(DataSet: TDataSet);
var
  S: string;
begin
  DateTimeToString(S, 'mmmm', cdsOrdersPurchaseDate.Value);
  cdsOrdersPurchaseMonth.AsString := S;
end;

procedure TGridMenuViewsDemoDataDM.cdsCarsCalcFields(DataSet: TDataSet);
begin
  cdsCarsCarName.AsString := cdsCarsTrademark.AsString + ' ' +
    cdsCarsModel.AsString;
end;

end.
