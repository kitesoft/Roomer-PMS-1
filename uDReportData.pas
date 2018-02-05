unit uDReportData;

interface

uses
  System.SysUtils, System.Classes, Dialogs, Data.DB, kbmMemTable;

type
  TDReportData = class(TDataModule)
    kbmUnconfirmedInvoicelines_: TkbmMemTable;
    UnconfirmedInvoicelinesDS: TDataSource;
  private
    { Private declarations }
  public
    { Public declarations }
  end;


function DReportData: TDReportData;

implementation

uses
  VCL.Forms
  ;

var
  gReportData: TDReportData;

function DReportData: TDReportData;
begin
  if not assigned(gReportData) then
    gReportData := TDReportData.Create(Application);

  Result := gReportData;
end;

{%CLASSGROUP 'Vcl.Controls.TControl'}

{$R *.dfm}

end.
