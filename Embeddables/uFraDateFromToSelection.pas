unit uFraDateFromToSelection;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sComboBox, Vcl.Mask, sMaskEdit, sCustomComboEdit,
  sToolEdit, sGroupBox;

type
  TfraDateFromToSelection = class(TFrame)
    gbxSelectDates: TsGroupBox;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    gbxSelectMonth: TsGroupBox;
    cbxMonth: TsComboBox;
    cbxYear: TsComboBox;
    procedure cbxMonthChange(Sender: TObject);
    procedure dtDateChange(Sender: TObject);
  private
    FUpdatingControls: boolean;
    FOnDatesChanged: TNotifyEvent;
    function GetSelectedEndDate: TDateTime;
    function GetSelectedStartDate: TDateTime;
    procedure SetSelectedEndDate(const Value: TDateTime);
    procedure SetSelectedStartDate(const Value: TDateTIme);
    function GetSelectedDayCount: integer;
    procedure DateChanged;
  protected
    procedure Loaded; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    function IsFullMonthSelected: boolean;

    property OnDatesChanged: TNotifyEvent read FOnDatesChanged write FOnDatesChanged;
    property StartDate: TDateTime read GetSelectedStartDate write SetSelectedStartDate;
    property EndDate: TDateTime read GetSelectedEndDate write SetSelectedEndDate;
    property DayCount: integer read GetSelectedDayCount;
  end;

implementation

{$R *.dfm}

uses
  DateUtils
  , uDateTimeHelper
  , uAppGlobal
  ;

procedure TfraDateFromToSelection.DateChanged;
begin
  if assigned(FOnDatesChanged) then
    FOnDatesChanged(self);
end;

procedure TfraDateFromToSelection.cbxMonthChange(Sender: TObject);
var
  y, m : word;
begin
  if FUpdatingControls then
    Exit;

  FUpdatingControls := true;
  try
    if cbxYear.ItemIndex < 0 then
      exit;
    if cbxMonth.ItemIndex < 0 then
      exit;

    y := StrToInt(cbxYear.Items[cbxYear.ItemIndex]);
    m := cbxMonth.ItemIndex+1;

    dtDateFrom.Date := encodeDate(y, m, 1);
    dtDateTo.Date := dtDateFrom.Date.EndOfMonth;

    DateChanged;
  finally
    FUpdatingControls := False;
  end;
end;

constructor TfraDateFromToSelection.Create(aOwner: TComponent);
begin
  inherited;

  glb.fillListWithMonthsLong(cbxMonth.Items, 0);
  glb.fillListWithYears(cbxYear.Items, 0, False);
end;

procedure TfraDateFromToSelection.dtDateChange(Sender: TObject);
begin
  if FUpdatingControls then
    Exit;

  FUpdatingControls := true;
  try
    if dtDateFrom.Date.Year = dtDateTo.Date.Year then
      cbxYear.ItemIndex := cbxYear.IndexOf(IntToStr(dtDateTo.Date.Year))
    else
      cbxYear.ItemIndex := -1;

    if (dtDateFrom.Date = dtDateFrom.Date.StartOfMonth.Date) and (dtDateTo.Date = dtDateFrom.Date.EndOfMonth.Date) then
      cbxMonth.ItemIndex := dtDateFrom.Date.Month -1
    else
      cbxMonth.ItemIndex := -1;

    DateChanged;
  finally
    FUpdatingControls := false;
  end;
end;

function TfraDateFromToSelection.GetSelectedDayCount: integer;
begin
  Result := dtDateFrom.Date.DaysBetween(dtDateTo.Date) + 1;
end;

function TfraDateFromToSelection.GetSelectedEndDate: TDateTime;
begin
  Result := dtDateTo.Date;
end;

function TfraDateFromToSelection.GetSelectedStartDate: TDateTime;
begin
  Result := dtDateFrom.Date;
end;

function TfraDateFromToSelection.IsFullMonthSelected: boolean;
begin
  Result := (cbxMonth.ItemIndex >=0) and (cbxYear.ItemIndex >=0);
end;

procedure TfraDateFromToSelection.Loaded;
begin
  inherited;
  cbxMonth.ItemIndex := Now.Month -1;
  cbxYear.ItemIndex := Now.Year - StrToInt(cbxYear.Items[0]);
  dtDateFrom.Date := Now.StartOfMonth;
  dtDateTo.Date := Now.EndOfMonth;
end;

procedure TfraDateFromToSelection.SetSelectedEndDate(const Value: TDateTime);
begin
  dtDateTo.Date := Value;
end;

procedure TfraDateFromToSelection.SetSelectedStartDate(const Value: TDateTime);
begin
  dtDateFrom.Date := Value;
end;

end.
