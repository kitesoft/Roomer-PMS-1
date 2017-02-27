unit SimpleListDemoData;

interface

uses
  SysUtils, Classes, cxClasses, cxStyles, cxTL, DB, Forms, dxmdaset;

type
  TSimpleListDemoDataDM = class(TDataModule)
    dsCars: TDataSource;
    StyleRepository: TcxStyleRepository;
    TreeListStyleSheetDevExpress: TcxTreeListStyleSheet;
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
    mdCars: TdxMemData;
    mdCarsID: TAutoIncField;
    mdCarsTrademark: TStringField;
    mdCarsModel: TStringField;
    mdCarsHP: TSmallintField;
    mdCarsLiter: TFloatField;
    mdCarsCyl: TSmallintField;
    mdCarsTransmissSpeedCount: TSmallintField;
    mdCarsTransmissAutomatic: TStringField;
    mdCarsMPG_City: TSmallintField;
    mdCarsMPG_Highway: TSmallintField;
    mdCarsCategory: TStringField;
    mdCarsDescription: TMemoField;
    mdCarsHyperlink: TStringField;
    mdCarsPicture: TBlobField;
    mdCarsPrice: TCurrencyField;
    procedure DataModuleCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  SimpleListDemoDataDM: TSimpleListDemoDataDM;

implementation

{$R *.dfm}

procedure TSimpleListDemoDataDM.DataModuleCreate(Sender: TObject);
const
  DataPath = '..\..\Data\';
begin
  mdCars.LoadFromBinaryFile(DataPath + 'Cars.dat');
  mdCars.Open;
end;

end.
