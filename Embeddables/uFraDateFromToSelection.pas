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
    FPropagateChanges: boolean;
    FOnDatesChanged: TNotifyEvent;
    function GetSelectedEndDate: TDate;
    function GetSelectedStartDate: TDate;
    procedure SetSelectedEndDate(const Value: TDate);
    procedure SetSelectedStartDate(const Value: TDate);
    function GetSelectedDayCount: integer;
    { Private declarations }
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    function IsFullMonthSelected: boolean;

    property OnDatesChanged: TNotifyEvent read FOnDatesChanged write FOnDatesChanged;
    property StartDate: TDate read GetSelectedStartDate write SetSelectedStartDate;
    property EndDate: TDate read GetSelectedEndDate write SetSelectedEndDate;
    property DayCount: integer read GetSelectedDayCount;
  end;

implementation

{$R *.dfm}

uses
  DateUtils
  , uDateTimeHelper
  , uAppGlobal
  ;

procedure TfraDateFromToSelection.cbxMonthChange(Sender: TObject);
var
  y, m : word;
begin
  if FUpdatingControls then
    Exit;

  if cbxYear.ItemIndex < 0 then
    exit;
  if cbxMonth.ItemIndex < 0 then
    exit;

  FPropagateChanges := false;
  try
    y := StrToInt(cbxYear.Items[cbxYear.ItemIndex]);
    m := cbxMonth.ItemIndex+1;

    dtDateFrom.Date := encodeDate(y, m, 1);
    dtDateTo.Date := dtDateFrom.Date.EndOfMonth;
  finally
    FPropagateChanges := true;
  end;
end;

constructor TfraDateFromToSelection.Create(aOwner: TComponent);
begin
  inherited;

  glb.fillListWithMonthsLong(cbxMonth.Items, 0);
  glb.fillListWithYears(cbxYear.Items, 0, False);

  FPropagateChanges := false;
  try
    cbxMonth.ItemIndex := Now.Month -1;
    cbxYear.ItemIndex := Now.Year - StrToInt(cbxYear.Items[0]);
    dtDateFrom.Date := Now.StartOfMonth;
    dtDateTo.Date := Now.EndOfMonth;
  finally
    FPropagateChanges := true;
  end;
end;

procedure TfraDateFromToSelection.dtDateChange(Sender: TObject);
begin
  FUpdatingControls := true;
  try
    if FPropagateChanges then
    begin
      if dtDateFrom.Date.Year = dtDateTo.Date.Year then
        cbxYear.ItemIndex := cbxYear.IndexOf(IntToStr(dtDateTo.Date.Year))
      else
        cbxYear.ItemIndex := -1;

      if (dtDateFrom.Date = dtDateFrom.Date.StartOfMonth.Date) and (dtDateTo.Date = dtDateFrom.Date.EndOfMonth.Date) then
        cbxMonth.ItemIndex := dtDateFrom.Date.Month -1
      else
        cbxMonth.ItemIndex := -1;

      if assigned(FOnDatesChanged) then
        FOnDatesChanged(self);
    end;
  finally
    FUpdatingControls := false;
  end;
end;

function TfraDateFromToSelection.GetSelectedDayCount: integer;
begin
  Result := dtDateFrom.Date.DaysBetween(dtDateTo.Date) + 1;
end;

function TfraDateFromToSelection.GetSelectedEndDate: TDate;
begin
  Result := dtDateTo.Date;
end;

function TfraDateFromToSelection.GetSelectedStartDate: TDate;
begin
  Result := dtDateFrom.Date;
end;

function TfraDateFromToSelection.IsFullMonthSelected: boolean;
begin
  Result := (cbxMonth.ItemIndex >=0) and (cbxYear.ItemIndex >=0);
end;


procedure TfraDateFromToSelection.SetSelectedEndDate(const Value: TDate);
begin
  dtDateTo.Date := Value;
end;

procedure TfraDateFromToSelection.SetSelectedStartDate(const Value: TDate);
begin
  dtDateFrom.Date := Value;
end;

end.
