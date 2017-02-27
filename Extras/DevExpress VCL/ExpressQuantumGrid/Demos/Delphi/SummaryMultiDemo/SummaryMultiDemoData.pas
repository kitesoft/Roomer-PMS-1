unit SummaryMultiDemoData;

interface

uses
  Forms, SysUtils, Classes, DB, cxStyles, ImgList, Controls, DemoUtils, cxClasses, DBClient;

type
  TSummaryMultiDemoDataDM = class(TDataModule)
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
    StyleRepository: TcxStyleRepository;
    styleGold: TcxStyle;
    styleBlueLight: TcxStyle;
    styleYellowLight: TcxStyle;
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
    tblCarsID: TAutoIncField;
    tblCarsTrademark: TStringField;
    tblCarsModel: TStringField;
    tblCarshp: TSmallintField;
    tblCarsliter: TFloatField;
    tblCarscyl: TSmallintField;
    tblCarsTransmissSpeedCount: TSmallintField;
    tblCarsTransmissAutomatic: TStringField;
    tblCarsMPG_City: TSmallintField;
    tblCarsMPG_Highway: TSmallintField;
    tblCarsCategory: TStringField;
    tblCarsDescription: TMemoField;
    tblCarsHyperlink: TStringField;
    tblCarsPicture: TBlobField;
    tblCarsPrice: TFloatField;
    tblCarsCarName: TStringField;
    styleBlue: TcxStyle;
    styleRed: TcxStyle;
    styleNormal: TcxStyle;
    styleSortedSummary: TcxStyle;
    procedure tblCarsCalcFields(DataSet: TDataSet);
    procedure DataModuleCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }     
  end;

var
  SummaryMultiDemoDataDM: TSummaryMultiDemoDataDM;

implementation

{$R *.dfm}

procedure TSummaryMultiDemoDataDM.tblCarsCalcFields(DataSet: TDataSet);
begin
  SetStringFieldValue(tblCarsCarName,
    tblCarsTrademark.Value + ' ' + tblCarsModel.Value);
end;

procedure TSummaryMultiDemoDataDM.DataModuleCreate(Sender: TObject);
var
  APath: string;
begin
  APath := ExtractFilePath(Application.ExeName) + '..\..\Data\';
  tblCars.LoadFromFile(APath + 'Cars.xml');
  tblCustomers.LoadFromFile(APath + 'Customers.xml');
  tblOrders.LoadFromFile(APath + 'Orders.xml');
end;

end.
