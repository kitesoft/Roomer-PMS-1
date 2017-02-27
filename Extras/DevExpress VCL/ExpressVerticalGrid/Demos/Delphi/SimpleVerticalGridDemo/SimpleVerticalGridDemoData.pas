unit SimpleVerticalGridDemoData;

interface

uses
  SysUtils, Classes, DB, cxStyles, cxClasses, cxVGrid, Forms, dxmdaset;

type
  TSimpleVerticalGridDemoMainDM = class(TDataModule)
    dsCars: TDataSource;
    cxStyleRepository: TcxStyleRepository;
    cxVerticalGridStyleSheetDevExpress: TcxVerticalGridStyleSheet;
    cxStyle1: TcxStyle;
    cxStyle2: TcxStyle;
    cxStyle3: TcxStyle;
    cxStyle4: TcxStyle;
    cxStyle5: TcxStyle;
    cxStyle6: TcxStyle;
    cxStyle7: TcxStyle;
    cxStyle8: TcxStyle;
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
    mdCarsPrice: TFloatField;
    procedure DataModuleCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  SimpleVerticalGridDemoMainDM: TSimpleVerticalGridDemoMainDM;

implementation

{$R *.dfm}

procedure TSimpleVerticalGridDemoMainDM.DataModuleCreate(Sender: TObject);
begin
  mdCars.LoadFromBinaryFile('..\..\Data\Cars.dat');
  mdCars.Open;
end;

end.
