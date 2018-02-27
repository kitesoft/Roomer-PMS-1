unit uFraLookupPanel;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sButton, sEdit, sLabel, Vcl.ExtCtrls, sPanel,
  Data.DB;

type
  TLookupPanelSelectEvent = function(var aCode: string): boolean of object;
  TLookupPanelValidateEvent = function(const aCode: string): boolean of object;

  /// <summary>
  ///  Generic frame to select one item from a dataset
  ///  </summary>
  ///  <example>
  ///    with fraLookupPriceCode do
  ///      begin
  ///        Dataset := glb.TblpricecodesSet;
  ///        CodeField := 'pccode';
  ///        DescriptionField := 'pcdescription';
  ///        OnChange := evtLookupOnChange;
  ///        OnSelect := evtSelectPriceCode;
  ///      end;
  ///  </example>
  TfraCustomLookupPanel = class(TFrame)
    pnlLookup: TsPanel;
    edCode: TsEdit;
    btnSelect: TsButton;
    lblDescription: TsLabel;
    procedure btnSelectClick(Sender: TObject);
    procedure edCodeChange(Sender: TObject);
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
    FAllowEmpty: boolean;
    procedure SetAllowEdit(const Value: boolean);
    function GetCode: string;
    procedure SetCode(const Value: string);
    function GetIsValid: boolean;
    function GetRejectedCodes: string;
    procedure SetRejectedCodes(const Value: string);
    procedure SetOnSelect(const Value: TLookupPanelSelectEvent);
    function ValidateInDataset(const aCode: string): boolean;
    procedure SetAllowEmpty(const Value: boolean);
    function GetDescription: string;
    { Private declarations }
  protected
    procedure DoInternalSelect(); virtual;
    function ValidateCode(const aCode: string): boolean; virtual;
    function ReadDescription(const aCode: string): string; virtual;
    procedure SetFocus; override;
  public
    constructor Create(aOwner: TCOmponent); override;
    destructor Destroy; override;
    procedure DisableEvents;
    procedure EnableEvents;
    function EventsEnabled: boolean;
    property IsValid: boolean read GetIsValid;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;

  protected
    { Public declarations }
    property OnSelect: TLookupPanelSelectEvent read FOnSelect write SetOnSelect;
    property OnValidate: TLookupPanelValidateEvent read FOnValidate write FOnValidate;

    /// <summary>
    ///   Dataset used to locate the entered Code for validation, if assigned and active
    /// </summary>
    property Dataset: TDataset read FDataset write FDataset;
    /// <summary>
    ///   Fieldname in Dataset used to locate the entered Code for validation
    /// </summary>
    property CodeField: string read FCodeField write FCodeField;
    /// <summary>
    ///   Fieldname in Dataset used to retrieve the description of a selected item
    /// </summary>
    property DescriptionField: string read FDescriptionField write FDescriptionField;
  published
    property Code: string read GetCode write SetCode;
    property Description: string read GetDescription;
    /// <summary>
    ///   A comma separated list of codes that are not accepted
    /// </summary>
    property RejectedCodes: string read GetRejectedCodes write SetRejectedCodes;
    property AllowEdit: boolean read FAllowEdit write SetAllowEdit;
    property AllowEmpty: boolean read FAllowEmpty write SetAllowEmpty;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnChangedAndValid: TNotifyEvent read FOnChangedAndValid write FOnChangedAndValid;
  end;

  TfraLookupPanel = class(TfraCustomLookupPanel)
  public
    property OnSelect;
    property OnValidate;
    property Dataset;
    property CodeField;
    property DescriptionField;
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

procedure TfraCustomLookupPanel.DoInternalSelect;
begin
end;


procedure TfraCustomLookupPanel.btnSelectClick(Sender: TObject);
var
  lCode: string;
begin
  if assigned(FOnSelect) then
  begin
    lCode := edCode.Text;
    if FOnSelect(lCode) then
      edCode.Text := lCode;
  end
  else
    DoInternalSelect;
end;

constructor TfraCustomLookupPanel.Create(aOwner: TCOmponent);
begin
  FRejectedCodes := TStringlist.Create;
  FRejectedCodes.Duplicates := dupIgnore;
  FRejectedCodes.CaseSensitive := false;

  inherited;
end;

destructor TfraCustomLookupPanel.Destroy;
begin
  FRejectedCodes.Free;
  inherited;
end;

procedure TfraCustomLookupPanel.DisableEvents;
begin
  inc(FDisableEventCount);
end;

function TfraCustomLookupPanel.ValidateInDataset(const aCode: string): boolean;
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

function TfraCustomLookupPanel.ReadDescription(const aCode: string): string;
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

function TfraCustomLookupPanel.ValidateCode(const aCode: string): boolean;
var
  idx: integer;
begin
  Result := not FRejectedCodes.Find(aCode, idx);

  if assigned(FonValidate) then
    Result := Result and FOnValidate(aCode)
  else
    result := Result and (not assigned(FDataset) or ValidateInDataset(aCode));
end;

procedure TfraCustomLookupPanel.edCodeChange(Sender: TObject);
begin
  FIsValidCode := (FAllowEmpty and (trim(edCode.Text) = '')) or ValidateCode(edCode.Text);

  if NOT FIsValidCode then
  begin
    lblDescription.UseSkinColor := false;
    lblDescription.Font.Color := clRed;
    lblDescription.caption := GetTranslatedText('shNotF_star');
  end
  else
  begin
    lblDescription.UseSkinColor := true;
    lblDescription.Font.Color := clWindowText;
    lblDescription.Caption := ReadDescription(edCode.Text);
  end;

  if EventsEnabled and Assigned(FOnChange) then
    FOnChange(Self);

  if EventsEnabled and IsValid and Assigned(FOnChangedAndValid) then
    FOnChangedAndValid(Self);
end;

procedure TfraCustomLookupPanel.edCodeDblClick(Sender: TObject);
begin
  btnSelect.Click;
end;

procedure TfraCustomLookupPanel.edCodeKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_F2 then
  begin
    btnSelect.Click;
    Key := 0;
  end;
end;

procedure TfraCustomLookupPanel.EnableEvents;
begin
  Dec(FDisableEventCount);
  FDisableEventCount := max(0, FDisableEventCount);
end;

function TfraCustomLookupPanel.EventsEnabled: boolean;
begin
  Result := (FDisableEventCount <= 0);
end;

procedure TfraCustomLookupPanel.GetChildren(Proc: TGetChildProc; Root: TComponent);
begin
//  inherited;

end;

function TfraCustomLookupPanel.GetCode: string;
begin
  Result := edCode.Text;
end;

function TfraCustomLookupPanel.GetDescription: string;
begin
  Result := '';
  if IsValid then
    Result := lblDescription.Caption;
end;

function TfraCustomLookupPanel.GetIsValid: boolean;
begin
  Result := FIsValidCode;
end;

function TfraCustomLookupPanel.GetRejectedCodes: string;
begin
  Result := FRejectedCodes.CommaText;
end;

procedure TfraCustomLookupPanel.SetAllowEdit(const Value: boolean);
begin
  FAllowEdit := Value;
  edCode.ReadOnly := not FAllowEdit;
  btnSelect.Visible := FAllowEdit;
end;

procedure TfraCustomLookupPanel.SetAllowEmpty(const Value: boolean);
begin
  FAllowEmpty := Value;
  edCodeChange(self);
end;

procedure TfraCustomLookupPanel.SetCode(const Value: string);
begin
  if edCode.Text <> Value then
    edCode.Text := Value;
end;

procedure TfraCustomLookupPanel.SetFocus;
begin
//  inherited;
  edCode.SetFocus;
end;

procedure TfraCustomLookupPanel.SetOnSelect(const Value: TLookupPanelSelectEvent);
begin
  FOnSelect := Value;
end;

procedure TfraCustomLookupPanel.SetRejectedCodes(const Value: string);
begin
  FRejectedCodes.CommaText := Value;
  edCodeChange(Self);
end;

initialization

finalization

end.
