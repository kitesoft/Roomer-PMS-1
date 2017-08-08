unit uFraCountryPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel;

type
  TfraCountryPanel = class(TFrame)
    pnlCountry: TsPanel;
    edCountryCode: TsEdit;
    btnGetCountry: TsButton;
    lblCountryName: TLabel;
    procedure edCountryCodeChange(Sender: TObject);
    procedure btnGetCountryClick(Sender: TObject);
  private
    FAllowEdit: boolean;
    FOnCountryChange: TNotifyEvent;
    FDisableEventCount: integer;
    FValidCountry: boolean;
    FInvalidCountryCodes: TStringlist;
    procedure SetAllowEdit(const Value: boolean);
    function GetCountryCode: string;
    function GetCountryName: string;
    procedure SetCountryCode(const Value: string);
    function GetIsValid: boolean;
    function GetRejectCountryCodes: string;
    procedure SetRejectCountryCodes(const Value: string);
    { Private declarations }
  public
    constructor Create(aOwner: TCOmponent); override;
    destructor Destroy; override;
    procedure DisableEvents;
    procedure EnableEvents;
    property CountryName: string read GetCountryName;
    property IsValid: boolean read GetIsValid;
  published
    { Public declarations }
    property AllowEdit: boolean read FAllowEdit write SetAllowEdit;
    property OnCountryChange: TNotifyEvent read FOnCountryChange write FOnCountryChange;
    property CountryCode: string read GetCountryCode write SetCountryCode;
    /// <summary>
    ///   A comma separated list of country codes that are not accepted
    /// </summary>
    property RejectCountryCodes: string read GetRejectCountryCodes write SetRejectCountryCodes;
  end;

implementation

{$R *.dfm}

uses
  PrjConst
  , uAppGlobal
  , uCountries
  , Math
  ;

{ TfraCountryPanel }

procedure TfraCountryPanel.btnGetCountryClick(Sender: TObject);
begin
  getCountry(edCountryCode, lblCountryName);
end;

constructor TfraCountryPanel.Create(aOwner: TCOmponent);
begin
  inherited;
  FInvalidCountryCodes := TStringlist.Create;
  FInvalidCountryCodes.Duplicates := dupIgnore;
  FInvalidCountryCodes.CaseSensitive := false;
end;

destructor TfraCountryPanel.Destroy;
begin
  FInvalidCountryCodes.Free;
  inherited;
end;

procedure TfraCountryPanel.DisableEvents;
begin
  inc(FDisableEventCount);
end;

procedure TfraCountryPanel.edCountryCodeChange(Sender: TObject);
var
  idx: integer;
begin
  FValidCountry := not FInvalidCountryCodes.Find(edCountryCode.Text, idx) and CountryValidate(edCountryCode, lblCountryName);
  if NOT FValidCountry then
    lblCountryName.Font.Color := clRed
  else
    lblCountryName.Font.Color := clWindowText;
//  if FValidCountry then
    if (FDisableEventCount = 0) and  Assigned(FOnCountryChange) then
      FOnCountryChange(Self);
end;

procedure TfraCountryPanel.EnableEvents;
begin
  Dec(FDisableEventCount);
  FDisableEventCount := max(0, FDisableEventCount);
end;

function TfraCountryPanel.GetCountryCode: string;
begin
  Result := edCountryCode.Text;
end;

function TfraCountryPanel.GetCountryName: string;
begin
  Result := lblCountryName.Caption;
end;

function TfraCountryPanel.GetIsValid: boolean;
begin
  Result := FValidCountry;
end;

function TfraCountryPanel.GetRejectCountryCodes: string;
begin
  Result := FInvalidCountryCodes.CommaText;
end;

procedure TfraCountryPanel.SetAllowEdit(const Value: boolean);
begin
  FAllowEdit := Value;
  edCountryCode.ReadOnly := not FAllowEdit;
  btnGetCountry.Visible := FAllowEdit;
end;

procedure TfraCountryPanel.SetCountryCode(const Value: string);
begin
  if not Sametext(edCountryCode.Text, Value) then
    edCountryCode.Text := Value;
end;

procedure TfraCountryPanel.SetRejectCountryCodes(const Value: string);
begin
  FInvalidCountryCodes.CommaText := Value;
  edCountryCodeChange(Self);
end;

initialization

finalization

end.
