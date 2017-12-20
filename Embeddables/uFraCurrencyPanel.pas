unit ufraCurrencyPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel,
  uRoomerCurrencyDefinition;

type
  TfraCurrencyPanel = class(TFrame)
    pnlCurrency: TsPanel;
    edCurrencyCode: TsEdit;
    btnGetCurrency: TsButton;
    lblCurrencyName: TsLabel;
    procedure edCurrencyCodeChange(Sender: TObject);
    procedure btnGetCurrencyClick(Sender: TObject);
  private
    FAllowEdit: boolean;
    FOnCurrencyChange: TNotifyEvent;
    FOnCurrencyChangeAndValid: TNotifyEvent;
    FDisableEventCount: integer;
    FValidCurrency: boolean;
    FShowCurrencyName: boolean;
    procedure SetAllowEdit(const Value: boolean);
    function GetCurrencyCode: string;
    function GetCurrencyName: string;
    procedure SetCurrencyCode(const Value: string);
    function GetIsValid: boolean;
    function GetCurrencyRate: double;
    procedure SetShowCurrencyName(const Value: boolean);
    function GetCurrencyDefinition: TRoomerCurrencyDefinition;
    procedure SetCurrencyDefinition(const Value: TRoomerCurrencyDefinition);
    { Private declarations }
  public
    constructor Create(aOwner: TComponent); override;
    procedure DisableEvents;
    procedure EnableEvents;
    function EventsEnabled: boolean;
    property CurrencyName: string read GetCurrencyName;
    property CurrencyRate: double read GetCurrencyRate;
    property IsValid: boolean read GetIsValid;
  published
    { Public declarations }
    property AllowEdit: boolean read FAllowEdit write SetAllowEdit;
    property ShowCurrencyName: boolean read FShowCurrencyName write SetShowCurrencyName;
    property OnCurrencyChange: TNotifyEvent read FOnCurrencyChange write FOnCurrencyChange;
    property OnCurrencyChangeAndValid: TNotifyEvent read FOnCurrencyChangeAndValid write FOnCurrencyChangeAndValid;
    property CurrencyCode: string read GetCurrencyCode write SetCurrencyCode;
    property CurrencyDefinition: TRoomerCurrencyDefinition read GetCurrencyDefinition write SetCurrencyDefinition;
  end;

implementation

{$R *.dfm}

uses
  PrjConst
  , uAppGlobal
  , Math
  , uCurrencies
  , hData, uRoomerCurrencymanager;

{ TfraCurrencyPanel }

procedure TfraCurrencyPanel.btnGetCurrencyClick(Sender: TObject);
var
  curr: string;
begin
  curr := edCurrencyCode.Text;
  if getCurrency(curr, lblCurrencyName) then
    edCurrencyCode.Text := curr;
end;

constructor TfraCurrencyPanel.Create(aOwner: TComponent);
begin
  inherited;
  FShowCurrencyName := True;
end;

procedure TfraCurrencyPanel.DisableEvents;
begin
  inc(FDisableEventCount);
end;

procedure TfraCurrencyPanel.edCurrencyCodeChange(Sender: TObject);
begin
  FValidCurrency := RoomerCurrencyManager.DefinitionExists(edCurrencyCode.Text); //CurrencyValidate(edCurrencyCode.text, lblCurrencyName);
  if NOT FValidCurrency then
  begin
    lblCurrencyName.Font.Color := clRed;
    lblCurrencyName.caption := GetTranslatedText('shNotF_star');
  end
  else
  begin
    lblCurrencyName.Font.Color := clWindowText;
    lblCurrencyName.caption := CurrencyDefinition.ShortDescription;
  end;

  if EventsEnabled and Assigned(FOnCurrencyChange) then
    FOnCurrencyChange(Self);

  if EventsEnabled and IsValid and Assigned(FOnCurrencyChangeAndValid) then
    FOnCurrencyChangeAndValid(Self);
end;

procedure TfraCurrencyPanel.EnableEvents;
begin
  Dec(FDisableEventCount);
  FDisableEventCount := max(0, FDisableEventCount);
end;

function TfraCurrencyPanel.EventsEnabled: boolean;
begin
  Result := (FDisableEventCount <= 0);
end;

function TfraCurrencyPanel.GetCurrencyCode: string;
begin
  Result := edCurrencyCode.Text;
end;

function TfraCurrencyPanel.GetCurrencyDefinition: TRoomerCurrencyDefinition;
begin
  if IsValid then
    Result := RoomerCurrencyManager[CurrencyCode]
  else
    Result := RoomerCurrencyManager.DefaultCurrencyDefinition;
end;

function TfraCurrencyPanel.GetCurrencyName: string;
begin
  Result := lblCurrencyName.Caption;
end;

function TfraCurrencyPanel.GetCurrencyRate: double;
begin
  if FValidCurrency then
    Result := GetRate(CurrencyCode)
  else
    Result := 1.0;
end;

function TfraCurrencyPanel.GetIsValid: boolean;
begin
  Result := FValidCurrency;
end;

procedure TfraCurrencyPanel.SetAllowEdit(const Value: boolean);
begin
  FAllowEdit := Value;
  edCurrencyCode.ReadOnly := not FAllowEdit;
  btnGetCurrency.Visible := FAllowEdit;
end;

procedure TfraCurrencyPanel.SetCurrencyCode(const Value: string);
begin
  if not Sametext(edCurrencyCode.Text, Value) then
    edCurrencyCode.Text := Value;
end;

procedure TfraCurrencyPanel.SetCurrencyDefinition(const Value: TRoomerCurrencyDefinition);
begin
  CurrencyCode := Value.CurrencyCode;
end;

procedure TfraCurrencyPanel.SetShowCurrencyName(const Value: boolean);
begin
  FShowCurrencyName := Value;
  lblCurrencyName.Visible := FShowCurrencyName;
end;

initialization

finalization

end.
