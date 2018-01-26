unit uFraCustomerPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uFraLookupPanel, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel;

type
  TfraCustomerPanel = class(TfraCustomLookupPanel)
    btnLast: TsButton;
    procedure btnLastClick(Sender: TObject);
  private
    function GetCountryCode: string;
    function GetCurrencyCode: string;
    function GetPriceCode: string;
    procedure LoadCustomerFromLastReservation;
  protected
    { Private declarations }
    procedure DoInternalSelect; override;
    procedure AlignControls(AControl: TControl; var ARect: TRect); override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    property PriceCode: string read GetPriceCode;
    property CurrencyCode: string read GetCurrencyCode;
    property CountryCode: string read GetCountryCode;
  end;


implementation

{$R *.dfm}

uses
  hData
  , uAppGlobal
  , uG
  , uCustomers2
  , cmpRoomerDataSet
  , uD
  ;

{ TfraCustomerPanel }

procedure TfraCustomerPanel.AlignControls(AControl: TControl; var ARect: TRect);
begin
  btnLast.Left := btnSelect.Left + btnSelect.Width + btnSelect.Margins.Right + btnLast.Margins.left;
  inherited;
end;

procedure TfraCustomerPanel.btnLastClick(Sender: TObject);
begin
  LoadCustomerFromLastReservation;
end;

constructor TfraCustomerPanel.Create(aOwner: TComponent);
begin
  inherited;
  Dataset := glb.CustomersSet;
  CodeField := 'customer';
  DescriptionField := 'surname';
end;

procedure TfraCustomerPanel.DoInternalSelect;
var
  theData: recCustomerHolder;
begin
  inherited;
  theData.Customer := Code;
  if OpenCustomers(actLookup, true, theData) then
    Code := theData.Customer;
end;

function TfraCustomerPanel.GetCountryCode: string;
begin
  result := '';
  if IsValid then
    glb.LocateSpecificRecordAndGetValue('customers', 'customer', Code, 'country', result);
end;

function TfraCustomerPanel.GetCurrencyCode: string;
begin
  result := '';
  if IsValid then
    glb.LocateSpecificRecordAndGetValue('customers', 'customer', Code, 'currency', result);
end;

function TfraCustomerPanel.GetPriceCode: string;
var
  lRateplanId: integer;
begin
  result := '';
  if IsValid and glb.LocateSpecificRecordAndGetValue('customers', 'customer', Code, 'rateplanid', lRateplanId) then
    glb.LocateSpecificRecordAndGetValue('channels', 'id', lRateplanId, 'channelmanagerid', Result);
end;

procedure TfraCustomerPanel.LoadCustomerFromLastReservation;
var
  s: string;
  rSet: TRoomerDataSet;
begin
  rSet := createNewDataSet;
  try
    s := 'Select customer FROM reservations Order by reservation desc Limit 1';
    if rSet_bySQL(rSet, s) then
      Code := rSet.FieldByName('customer').AsString;
  finally
    rSet.Free;
  end;
end;

end.
