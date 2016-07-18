unit ufraDateSelection;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit,
  sComboBox, sGroupBox
  , uDateSelPreset
  ;

type
  TfraDateSelection = class(TFrame)
    gbxSelectMonths: TsGroupBox;
    cbxMonth: TsComboBox;
    cbxYear: TsComboBox;
    gbxSelectDates: TsGroupBox;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    gbxPresets: TsGroupBox;
    cbxPresets: TsComboBox;
    procedure cbxMonthChange(Sender: TObject);
    procedure cbxPresetsChange(Sender: TObject);
  private
    function GetFromDate: TDateTime;
    function GetToDate: TDateTime;
    procedure SetFromDate(const Value: TDateTime);
    procedure SetToDate(const Value: TDateTime);
    function GetPreset: TDateSelpreset;
    procedure SetPreset(const Value: TDateSelpreset);

  protected
  public
    { Public declarations }
    constructor Create(aOwner: TCOmponent); override;
    procedure UpdateControls;

    property Preset: TDateSelpreset read GetPreset write SetPreset;
    property FromDate: TDateTime read GetFromDate write SetFromDate;
    property ToDate: TDateTime read GetToDate write SetToDate;
  end;

implementation

uses
    uDateTimeHelper
  , DateUtils
  ;
{$R *.dfm}

procedure TfraDateSelection.cbxMonthChange(Sender: TObject);
begin
  inherited;

  dtDateFrom.Date := TDateTime.Create(StrToIntDef(cbxYear.Text, now.Year), cbxMonth.ItemIndex, 1);
  dtDateTo.Date := TDateTime.Create(StrToIntDef(cbxYear.Text, now.Year), cbxMonth.ItemIndex, 1).EndOfMonth;

  UpdateControls;
end;

procedure TfraDateSelection.cbxPresetsChange(Sender: TObject);
begin
  inherited;
//  if not UpdatingControls then
//  begin
    case TDateSelPreset.FromItemIndex(cbxPresets.itemIndex) of
      TDateSelPreset.Today:
                  begin
                    dtDateFrom.Date := now;
                    dtDateTo.Date := now;
                  end;
      TDateSelPreset.Tomorrow:
                  begin
                    dtDateFrom.Date := now+1;
                    dtDateTo.Date := now+1;
                  end;
      TDateSelPreset.Yesterday:
                  begin
                    dtDateFrom.Date := now-1;
                    dtDateTo.Date := now-1;
                  end;
      TDateSelPreset.ThisWeek:
                  begin
                    dtDateFrom.Date := now.StartOfWeek;
                    dtDateTo.Date := now.EndOfWeek;
                  end;
      TDateSelPreset.ThisMonth:
                  begin
                    dtDateFrom.Date := Now.StartOfMonth;
                    dtDateTo.Date := now.EndOfMonth;
                  end;
      TDateSelPreset.ThisYear:
                  begin
                    dtDateFrom.Date := now.StartOfYear;
                    dtDateTo.Date := now.EndOfYear;
                  end;
      TDateSelPreset.Manual:
                  begin
                    // leave them alone
                  end;
    end;
    UpdateControls;
//  end;

end;

constructor TfraDateSelection.Create(aOwner: TCOmponent);
begin
  inherited;
  TDateSelPreset.SetStrings(cbxPresets.Items);

  cbxPresets.ItemIndex := ord(TDateSelPreset.Today);
  cbxPresetsChange(Self);
  cbxMonth.ItemIndex := now.Month -1;
  cbxYear.ItemIndex := cbxYear.Items.IndexOf(IntToStr(now.Year));
end;

function TfraDateSelection.GetFromDate: TDateTime;
begin
  Result := dtDateFrom.Date;
end;

function TfraDateSelection.GetPreset: TDateSelpreset;
begin
  Result := TDateSelPreset.Fromitemindex(cbxPresets.itemIndex);
end;

function TfraDateSelection.GetToDate: TDateTime;
begin
  Result := dtDateTo.Date;
end;

procedure TfraDateSelection.SetFromDate(const Value: TDateTime);
begin
  dtDateFrom.Date := Value;
end;

procedure TfraDateSelection.SetPreset(const Value: TDateSelpreset);
begin
  cbxPresets.ItemIndex := ord(value);
end;

procedure TfraDateSelection.SetToDate(const Value: TDateTime);
begin
  dtDateTo.Date := Value;
end;

procedure TfraDateSelection.UpdateControls;
var
  lPreset: TDateSelPreset;
begin
  lPreset := TDateSelPreset.FromItemIndex(cbxPresets.ItemIndex);
  dtDateFrom.ReadOnly := lPreset <> TDateSelpreset.Manual;
  dtDateTo.ReadOnly := lPreset <> TDateSelpreset.Manual;
  gbxSelectMonths.Enabled := lPreset = TDateSelpreset.Manual;

  if lPreset <> TDateSelPreset.Manual then
  begin
    cbxMonth.ItemIndex := -1;
    cbxYear.ItemIndex := -1;
  end;

  Repaint;
end;

end.
