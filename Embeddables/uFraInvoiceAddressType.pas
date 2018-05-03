unit uFraInvoiceAddressType;

interface

uses
  System.Classes
  , WinAPI.Messages
  , Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sGroupBox
  , uInvoiceDefinitions
  ;

type
  TfraInvoiceAddressType = class(TFrame)
    rgrInvoiceAddressType: TsRadioGroup;
    procedure rgrInvoiceAddressTypeChange(Sender: TObject);
  private
    FOnAddressTypeChanged: TNotifyEvent;
    function GetInvoiceAddressType: TInvoiceAddressType;
    procedure SetInvoiceAddresstype(const Value: TInvoiceAddressType);
  protected
    { Private declarations }
  public
    { Public declarations }
    procedure Initialize;
    property AddressType: TInvoiceAddressType read GetInvoiceAddressType write SetInvoiceAddresstype;
    property OnAddressTypeChanged: TNotifyEvent read FOnAddressTypeChanged write FOnAddressTypeChanged;
  end;

implementation

{$R *.dfm}

uses uAppGlobal;

{ TfraInvoiceAddressType }

function TfraInvoiceAddressType.GetInvoiceAddressType: TInvoiceAddressType;
begin
  Result := TInvoiceAddressType.FromItemIndex(rgrInvoiceAddressType.ItemIndex);
end;

procedure TfraInvoiceAddressType.Initialize;
begin
  TInvoiceAddressType.AsStrings(rgrInvoiceAddressType.Items);
  AddressType := glb.PMSSettings.InvoiceSettings.DefaultInvoiceAddressType;
end;

procedure TfraInvoiceAddressType.rgrInvoiceAddressTypeChange(Sender: TObject);
begin
  if assigned(OnAddressTypeChanged) then
    OnAddressTypeChanged(self);
end;

procedure TfraInvoiceAddressType.SetInvoiceAddresstype(const Value: TInvoiceAddressType);
begin
  rgrInvoiceAddressType.ItemIndex := Value.ToItemIndex;
end;

end.
