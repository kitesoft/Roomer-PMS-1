unit uFraHotelStatisticsFooter;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sComboBox, sLabel, Vcl.ExtCtrls, sPanel, Vcl.Mask,
  sMaskEdit, sCustomComboEdit, sCurrEdit, sCurrencyEdit
  , RoomerCurrencyEdit
  , uHotelStatistics
  ;

type
  TfraHotelStatisticsFooter = class(TFrame)
    pnlStatistics: TsPanel;
    edtOccupancy: TsCalcEdit;
    edtADR: TsCurrencyEdit;
    edtRevPar: TsCurrencyEdit;
    edtRoomsSold: TsCalcEdit;
    cbxStatDay: TsComboBox;
    lblOccupancy: TsLabel;
    lblStatAdr: TsLabel;
    lblStatRevPar: TsLabel;
    lblStatRoomsSold: TsLabel;
    procedure cbxStatDayChange(Sender: TObject);
  private
    FStats: THotelStatisticsList;
    FDate: TDateTime;
    function GetDate: TDate;
    procedure SetDate(const Value: TDate);
    procedure UpdateControls;
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    procedure RefreshStats;
    procedure SetBackgroundColor(aColor: TColor);
    procedure SetFontColor(aColor: TColor);
    property Date: TDate read GetDate write SetDate;
  end;

implementation

uses
  uHotelStatisticsAPI
  , uDateTimeHelper
  , uAppGlobal
  , uRoomerCurrencymanager;


{$R *.dfm}

procedure TfraHotelStatisticsFooter.cbxStatDayChange(Sender: TObject);
begin
  UpdateControls;
end;

constructor TfraHotelStatisticsFooter.Create(aOwner: TComponent);
begin
  inherited;
  FStats := THotelStatisticsList.Create;
end;

destructor TfraHotelStatisticsFooter.Destroy;
begin
  FStats.Free;
  inherited;
end;

function TfraHotelStatisticsFooter.GetDate: TDate;
begin
  Result := FDate;
end;

procedure TfraHotelStatisticsFooter.UpdateControls;
var
  lDayStats: TSingleDateStatistics;
begin
  lDayStats := FStats.StatisticsForDate[FDate + cbxStatDay.ItemIndex];
  if assigned(lDayStats) then
  begin
    edtOccupancy.Value := lDayStats.Statistic['OCCUPANCY'].Value;
    edtADR.CurrencyCode := RoomerCurrencyManager.DefaultCurrency;
    edtADR.VAlue := lDayStats.Statistic['ADR'].Value;
    edtRevPar.CurrencyCode := RoomerCurrencyManager.DefaultCurrency;
    edtRevPar.Value := lDayStats.Statistic['REVPAR'].Value;
    edtRoomsSold.Value := lDayStats.Statistic['ROOMS_SOLD'].Value;
  end
  else
  begin
    edtOccupancy.Value := 0;
    edtADR.VAlue := 0;
    edtRevPar.Value := 0;
    edtRoomsSold.Value := 0;
  end;
end;

procedure TfraHotelStatisticsFooter.RefreshStats;
var
  lMobileApi: THotelStatisticsMobileAPICaller;
begin
  lMobileApi := THotelStatisticsMobileAPICaller.Create();
  try
    lMobileApi.GetHotelStatistics(FDate, FDate.AddDays(1), FStats);
    UpdateControls;
  finally
    lMobileApi.Free;
  end;
end;


procedure TfraHotelStatisticsFooter.SetBackgroundColor(aColor: TColor);
begin
  Color := aColor;
  pnlStatistics.Color := aColor;
  lblOccupancy.Color := aColor;
  lblStatAdr.Color := aColor;
  lblStatRevPar.Color := aColor;
  lblStatRoomsSold.Font.Color := aColor;
  edtOccupancy.Color := aColor;
  edtADR.Color := aColor;
  edtRevPar.Color := aColor;
  edtRoomsSold.Color := aColor;
end;

procedure TfraHotelStatisticsFooter.SetDate(const Value: TDate);
begin
  if FDate <> Value then
  begin
    FDate := Value;
    RefreshStats;
  end;
end;

procedure TfraHotelStatisticsFooter.SetFontColor(aColor: TColor);
begin
  Font.Color := aColor;
  pnlStatistics.Font.Color := aColor;
  lblOccupancy.Font.Color := aColor;
  lblStatAdr.Font.Color := aColor;
  lblStatRevPar.Font.Color := aColor;
  lblStatRoomsSold.Font.Color := aColor;
  edtOccupancy.Font.Color := aColor;
  edtADR.Font.Color := aColor;
  edtRevPar.Font.Color := aColor;
  edtRoomsSold.Font.Color := aColor;
end;

end.
