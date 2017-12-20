unit uFraLookupPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel,
  Data.DB;

type
  TfraLookupPanel = class;
  TLookupPanelSelectEvent = function(var aCode: string): boolean of object;
  TLookupPanelValidateEvent = function(Code: string): boolean of object;

  TfraLookupPanel = class(TFrame)
    pnlLookup: TsPanel;
    edCode: TsEdit;
    btnSelect: TsButton;
    lblDescription: TLabel;
    procedure edCodeChange(Sender: TObject);
    procedure btnSelectClick(Sender: TObject);
    procedure edCodeDblClick(Sender: TObject);
    procedure edCodeKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
  private
    FAllowEdit: boolean;
    FOnChange: TNotifyEvent;
    FOnChangedAndValid: TNotifyEvent;
    FDisableEventCount: integer;
    FIsValidCode: boolean;
    FRejectedCodes: TStringlist;
    FOnSelect: TLookupPanelSelectEvent;
    FOnValidate: TLookupPanelValidateEvent;
    FDataset: TDataset;
    FCodeField: string;
    FDescriptionField: string;
    procedure SetAllowEdit(const Value: boolean);
    function GetCode: string;
    procedure SetCode(const Value: string);
    function GetIsValid: boolean;
    function GetRejectedCodes: string;
    procedure SetRejectedCodes(const Value: string);
    procedure SetOnSelect(const Value: TLookupPanelSelectEvent);
    function ValidateInDataset(const aCode: string): boolean;
    function GetDescription(const aCode: string): string;
    { Private declarations }
  public
    constructor Create(aOwner: TCOmponent); override;
    destructor Destroy; override;
    procedure DisableEvents;
    procedure EnableEvents;
    function EventsEnabled: boolean;
    property IsValid: boolean read GetIsValid;
  published
    { Public declarations }
    property AllowEdit: boolean read FAllowEdit write SetAllowEdit;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnChangedAndValid: TNotifyEvent read FOnChangedAndValid write FOnChangedAndValid;
    property OnSelect: TLookupPanelSelectEvent read FOnSelect write SetOnSelect;
    property OnValidate: TLookupPanelValidateEvent read FOnValidate write FOnValidate;
    property Code: string read GetCode write SetCode;
    /// <summary>
    ///   A comma separated list of codes that are not accepted
    /// </summary>
    property RejectedCodes: string read GetRejectedCodes write SetRejectedCodes;
    property Dataset: TDataset read FDataset write FDataset;
    /// <summary>
    ///   Fieldname in Dataset used to locate the entered Code for validation
    /// </summary>
    property CodeField: string read FCodeField write FCodeField;
    property DescriptionField: string read FDescriptionField write FDescriptionField;
  end;

implementation

{$R *.dfm}

uses
  PrjConst
  , uAppGlobal
  , uCountries
  , Math
  ;

{ TfraLookupPanel }

procedure TfraLookupPanel.btnSelectClick(Sender: TObject);
var
  lCode: string;
begin
  if assigned(FOnSelect) then
  begin
    lCode := edCode.Text;
    if FOnSelect(lCode) then
      edCode.Text := lCode;
  end;
//  getCountry(edCountryCode, lblCountryName);
end;

constructor TfraLookupPanel.Create(aOwner: TCOmponent);
begin
  inherited;
  FRejectedCodes := TStringlist.Create;
  FRejectedCodes.Duplicates := dupIgnore;
  FRejectedCodes.CaseSensitive := false;

  btnSelect.Enabled := false;
end;

destructor TfraLookupPanel.Destroy;
begin
  FRejectedCodes.Free;
  inherited;
end;

procedure TfraLookupPanel.DisableEvents;
begin
  inc(FDisableEventCount);
end;

function TfraLookupPanel.ValidateInDataset(const aCode: string): boolean;
var
  bm: TBookmark;
const
  cActiveFieldName = 'active';
begin
  Result := False;
  if assigned(FDataset) and FDataset.Active and assigned(FDataset.FindField(FCodeField)) then
  begin
    bm := FDataset.Bookmark;
    FDataset.DisableControls;
    try
      if assigned(FDataset.FindField(cActiveFieldName)) then
        Result := FDataset.Locate(cActiveFieldName + ';' + FCodeField, VarArrayOf([1, aCode]), [loCaseInsensitive])
      else
        Result := FDataset.Locate(FCodeField, aCode, [loCaseInsensitive]);
    finally
      FDataset.Bookmark := bm;
      FDataset.EnableControls;
    end;
  end;
end;

function TfraLookupPanel.GetDescription(const aCode: string): string;
var
  bm: TBookmark;
begin
  Result := GetTranslatedText('shNotF_star');
  if assigned(FDataset) and FDataset.Active and assigned(FDataset.FindField(FDescriptionField)) then
  begin
    bm := FDataset.Bookmark;
    FDataset.DisableControls;
    try
      if FDataset.Locate(FCodeField, aCode, [loCaseInsensitive]) then
        Result := FDataset.FieldByName(FDescriptionField).AsString;
    finally
      FDataset.Bookmark := bm;
      FDataset.EnableControls;
    end;
  end;
end;


procedure TfraLookupPanel.edCodeChange(Sender: TObject);
var
  idx: integer;
begin
  FIsValidCode := not FRejectedCodes.Find(edCode.Text, idx);

  if assigned(FonValidate) then
    FIsValidCode := FIsValidCode and FOnValidate(edCode.Text)
  else
    FIsValidCode := FIsValidCode and (not assigned(FDataset) or ValidateInDataset(edCode.Text));


  if NOT FIsValidCode then
  begin
    lblDescription.Font.Color := clRed;
    lblDescription.caption := GetTranslatedText('shNotF_star');
  end
  else
  begin
    lblDescription.Font.Color := clWindowText;
    lblDescription.Caption := GetDescription(edCode.Text);
  end;

  if EventsEnabled and Assigned(FOnChange) then
    FOnChange(Self);

  if EventsEnabled and IsValid and Assigned(FOnChangedAndValid) then
    FOnChangedAndValid(Self);
end;

procedure TfraLookupPanel.edCodeDblClick(Sender: TObject);
begin
  btnSelect.Click;
end;

procedure TfraLookupPanel.edCodeKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_F2 then
  begin
    btnSelect.Click;
    Key := 0;
  end;
end;

procedure TfraLookupPanel.EnableEvents;
begin
  Dec(FDisableEventCount);
  FDisableEventCount := max(0, FDisableEventCount);
end;

function TfraLookupPanel.EventsEnabled: boolean;
begin
  Result := (FDisableEventCount <= 0);
end;

function TfraLookupPanel.GetCode: string;
begin
  Result := edCode.Text;
end;

function TfraLookupPanel.GetIsValid: boolean;
begin
  Result := FIsValidCode;
end;

function TfraLookupPanel.GetRejectedCodes: string;
begin
  Result := FRejectedCodes.CommaText;
end;

procedure TfraLookupPanel.SetAllowEdit(const Value: boolean);
begin
  FAllowEdit := Value;
  edCode.ReadOnly := not FAllowEdit;
  btnSelect.Visible := FAllowEdit;
end;

procedure TfraLookupPanel.SetCode(const Value: string);
begin
  if not Sametext(edCode.Text, Value) then
    edCode.Text := Value;
end;

procedure TfraLookupPanel.SetOnSelect(const Value: TLookupPanelSelectEvent);
begin
  FOnSelect := Value;
  btnSelect.Enabled := assigned(FOnSelect);
end;

procedure TfraLookupPanel.SetRejectedCodes(const Value: string);
begin
  FRejectedCodes.CommaText := Value;
  edCodeChange(Self);
end;

initialization

finalization

end.
