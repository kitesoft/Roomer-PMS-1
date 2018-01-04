unit ufraCurrencyPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel,
  uRoomerCurrencyDefinition
  , ufraLookupPanel;

type
  TfraCurrencyPanel = class(TfraLookupPanel)
  private
    FShowCurrencyName: boolean;
    function GetCurrencyRate: double;
    procedure SetShowCurrencyName(const Value: boolean);
    function GetCurrencyDefinition: TRoomerCurrencyDefinition;
    procedure SetCurrencyDefinition(const Value: TRoomerCurrencyDefinition);
  protected
    procedure DoInternalSelect; override;
    function ValidateCode(const aCode: string): boolean; override;
    function GetDescription(const aCode: string): string; override;
  public
    constructor Create(aOwner: TComponent); override;
    property CurrencyRate: double read GetCurrencyRate;
  published
    { Public declarations }
    property ShowCurrencyName: boolean read FShowCurrencyName write SetShowCurrencyName;
    property CurrencyDefinition: TRoomerCurrencyDefinition read GetCurrencyDefinition write SetCurrencyDefinition;
  end;

implementation

{$R *.dfm}

uses
  PrjConst
  , uAppGlobal
  , Math
  , uCurrencies
  , hData
  , uRoomerCurrencymanager
  , uG;

{ TfraCurrencyPanel }

procedure TfraCurrencyPanel.DoInternalSelect;
var
  theData: recCurrencyHolder;
begin
  theData.Currency := edCode.Text;
  if currencies(actLookup, theData) then
    edCode.Text := theData.Currency;
end;

constructor TfraCurrencyPanel.Create(aOwner: TComponent);
begin
  inherited;
  FShowCurrencyName := True;
end;

function TfraCurrencyPanel.ValidateCode(const aCode: string): boolean;
begin
  Result := RoomerCurrencyManager.DefinitionExists(aCode);
end;

function TfraCurrencyPanel.GetCurrencyDefinition: TRoomerCurrencyDefinition;
begin
  if IsValid then
    Result := RoomerCurrencyManager[Code]
  else
    Result := RoomerCurrencyManager.DefaultCurrencyDefinition;
end;

function TfraCurrencyPanel.GetCurrencyRate: double;
begin
  if IsValid then
    Result := GetRate(Code)
  else
    Result := 1.0;
end;

function TfraCurrencyPanel.GetDescription(const aCode: string): string;
begin
  Result := RoomerCurrencyManager[aCode].Description;
end;

procedure TfraCurrencyPanel.SetCurrencyDefinition(const Value: TRoomerCurrencyDefinition);
begin
  Code := Value.CurrencyCode;
end;

procedure TfraCurrencyPanel.SetShowCurrencyName(const Value: boolean);
begin
  FShowCurrencyName := Value;
  lblDescription.Visible := FShowCurrencyName;
end;

initialization

finalization

end.
