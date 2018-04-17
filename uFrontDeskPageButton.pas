unit uFrontDeskPageButton;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, acImage, Vcl.StdCtrls, sLabel, sPanel, Vcl.ImgList, PngImageList, AdvUtil, Vcl.Grids, AdvObj, BaseGrid,
  AdvGrid, cmpRoomerDataSet, uRoomerThreadedRequest
  , uHotelStatistics
  ;

type
  TFrmFrontDeskPageButton = class(TForm)
    PngImageList1: TPngImageList;
    pnlContainer: TsPanel;
    sPanel1: TsPanel;
    lblTxtArrivals: TsLabel;
    sPanel2: TsPanel;
    sImage1: TsImage;
    lblArrivals: TsLabel;
    sPanel3: TsPanel;
    lbTxtlDepartures: TsLabel;
    sPanel4: TsPanel;
    sImage2: TsImage;
    lblDepartures: TsLabel;
    sPanel5: TsPanel;
    lblTxtTomArrivals: TsLabel;
    sPanel6: TsPanel;
    sImage3: TsImage;
    lblTomArrivals: TsLabel;
    sPanel7: TsPanel;
    lblTxlTomDepartures: TsLabel;
    sPanel8: TsPanel;
    sImage4: TsImage;
    lblTomDepartures: TsLabel;
    sPanel9: TsPanel;
    lblTxtNewReservation: TsLabel;
    sPanel10: TsPanel;
    sImage5: TsImage;
    sPanel11: TsPanel;
    lblTxtInHouse: TsLabel;
    sPanel12: TsPanel;
    sImage6: TsImage;
    lblInHouse: TsLabel;
    sPanel13: TsPanel;
    lblTxtCalendar: TsLabel;
    sPanel14: TsPanel;
    sImage7: TsImage;
    sPanel15: TsPanel;
    lblTxtHousekeepingStatus: TsLabel;
    sPanel16: TsPanel;
    sImage8: TsImage;
    StatGrid: TAdvStringGrid;
    Shape2: TShape;
    Shape3: TShape;
    Shape4: TShape;
    Shape5: TShape;
    Shape6: TShape;
    Shape7: TShape;
    Shape8: TShape;
    Shape1: TShape;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    procedure sPanel1MouseEnter(Sender: TObject);
    procedure sPanel1MouseLeave(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure StatGridGetAlignment(Sender: TObject; ARow, ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
    procedure StatGridGetCellColor(Sender: TObject; ARow, ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure sPanel1MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Shape2MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Shape5MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Shape7MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Shape6MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Shape3MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Shape4MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure sPanel15MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure FormKeyPress(Sender: TObject; var Key: Char);
    procedure FormKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure panelOnPaint(Sender: TObject; Canvas: TCanvas);
  private
    FShowFromDate: TDate;
    procedure SetShowFromDate(const Value: TDate);
    { Private declarations }
  private
    ThreadedDataGetter : TGetSQLDataThreaded;
    function GetSenderAsPanel(Sender: TObject): TsPanel;
    function GetShapeComponentOfButton(Sender: TObject): TShape;
    procedure DrawDateRow;
    procedure PrepareGridText;
    procedure UpdateGridFromStats(aStatsList: THotelStatisticsList);
  public
    { Public declarations }
    procedure RefreshDisplay;
    property ShowFromDate : TDate read FShowFromDate write SetShowFromDate;
  end;

var
  FrmFrontDeskPageButton: TFrmFrontDeskPageButton;

procedure PrepareFrontDeskPage(EmbedOn : TWinControl);
procedure FreeFrontDeskPage;


implementation

{$R *.dfm}

uses uD,
     hData,
     _Glob,
     uAppGlobal,
     uRoomerLanguage,
     uUtils,
     uG,
     uDateUtils,
     uRptArrivals,
     uRptDepartures,
     uRptInHouse,
     uMain,
     PrjConst
    , uHotelStatisticsAPI
    , DateUtils
    , uDateTimeHelper;

const

   ROW_DAY          = 0;
   ROW_DATE         = 1;

   ROW_ARRIVALS     = 2;
   ROW_DEPARTURES   = 3;
   ROW_LEFT_TO_SELL = 4;
   ROW_OCCUPANCY    = 5;
   ROW_BAR          = 6;

   COL_START        = 1;


procedure PrepareFrontDeskPage(EmbedOn : TWinControl);
begin
  FrmFrontDeskPageButton := TFrmFrontDeskPageButton.Create(nil);
  FrmFrontDeskPageButton.FShowFromDate := Trunc(Now);
  FrmFrontDeskPageButton.pnlContainer.Parent := EmbedOn;
end;

procedure FreeFrontDeskPage;
begin
  FrmFrontDeskPageButton.pnlContainer.Parent := FrmFrontDeskPageButton;
  FrmFrontDeskPageButton.Free;
end;

{ TFrmFrontDeskPageButton }


procedure TFrmFrontDeskPageButton.RefreshDisplay;
begin
  THotelStatisticsMobileAPICallerThreaded.GetHotelStatistics(ShowFromDate, TDateTime(ShowFromDate).AddDays(6), UpdateGridFromStats);
end;

procedure TFrmFrontDeskPageButton.Shape2MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  ShowDeparturesReport(FShowFromDate, true);
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.Shape3MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  ShowArrivalsReport(TDateTime(FShowFromDate).AddDays(1), true);
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.Shape4MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  ShowDeparturesReport(TDateTime(FShowFromDate).AddDays(1), true);
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.Shape5MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  frmMain.CreateQuickReservation(false);
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.Shape6MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  ShowInHouseReport(true);
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.Shape7MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  frmMain.tabsView.TabIndex := 1;
  frmMain.tabsViewChange(nil);
end;

procedure TFrmFrontDeskPageButton.UpdateGridFromStats(aStatsList: THotelStatisticsList);
var
  lDate: TDate;
  i: integer;
  lStats: TSingleDateStatistics;
begin
  DrawDateRow;
  for i := 0 to StatGrid.ColCount-2 do
  begin
    lDate := TDateTime(FShowFromDate).AddDays(i);
    lStats := aStatsList.StatisticsForDate[lDate];
    if assigned(lStats) then
    begin

      if (lDate = FSHowFromDate) then
      begin
        lblArrivals.Caption := lStats.Statistic['REMAINING_ARRIVALS'].FormattedValue;
        lblDepartures.Caption := lStats.Statistic['REMAINING_DEPARTURES'].FormattedValue;
        lblInHouse.Caption := lStats.Statistic['IN_HOUSE'].FormattedValue;
      end;

      if (lDate = TDateTime(FSHowFromDate).AddDays(1)) then
      begin
        lblTomArrivals.Caption := lStats.Statistic['REMAINING_ARRIVALS'].FormattedValue;
        lblTomDepartures.Caption := lStats.Statistic['REMAINING_DEPARTURES'].FormattedValue;
      end;

      StatGrid.Cells[i+1, ROW_ARRIVALS]     := lStats.Statistic['EXPECTED_ARRIVALS'].FormattedValue;
      StatGrid.Cells[i+1, ROW_DEPARTURES]   := lStats.Statistic['EXPECTED_DEPARTURES'].FormattedValue;
      StatGrid.Cells[i+1, ROW_LEFT_TO_SELL] := lStats.Statistic['LEFT_TO_SELL'].FormattedValue;
      StatGrid.Cells[i+1, ROW_OCCUPANCY]    := lStats.Statistic['OCCUPANCY'].FormattedValue;
      StatGrid.Cells[i+1, ROW_BAR]          := lStats.Statistic['BAR'].FormattedValue;
    end;
  end;


end;

procedure TFrmFrontDeskPageButton.SetShowFromDate(const Value: TDate);
begin
  FShowFromDate := Value;
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.sPanel15MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  frmMain.btnSimpleHouseKeepingClick(frmMain.btnSimpleHouseKeeping);
end;

procedure TFrmFrontDeskPageButton.sPanel1MouseEnter(Sender: TObject);
begin
  GetShapeComponentOfButton(Sender).Brush.Style := bsSolid;
  GetShapeComponentOfButton(Sender).Brush.Color := $00EEEEDD;
end;

procedure TFrmFrontDeskPageButton.sPanel1MouseLeave(Sender: TObject);
begin
  GetShapeComponentOfButton(Sender).Brush.Style := bsClear;
end;

procedure TFrmFrontDeskPageButton.sPanel1MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  ShowArrivalsReport(FShowFromDate, True);
  RefreshDisplay;
end;

procedure TFrmFrontDeskPageButton.panelOnPaint(Sender: TObject; Canvas: TCanvas);
var
  lParent: TWinControl;
  i: integer;
begin
  lParent := Sender as TWinControl;
  for i := 0 to lParent.ControlCount-1 do
    if lParent.COntrols[i] is TImage then
      lParent.Controls[i].Invalidate;
end;

procedure TFrmFrontDeskPageButton.StatGridGetAlignment(Sender: TObject; ARow, ACol: Integer; var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  if ACol > 0 then
    HAlign := taCenter
  else
    HAlign := taLeftJustify;
end;

procedure TFrmFrontDeskPageButton.StatGridGetCellColor(Sender: TObject; ARow, ACol: Integer; AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
begin
  if ARow < 1 then
    ABrush.Color := $00FFBF3C
  else
  if (ARow < 2) OR (ACol < 1) then
    ABrush.Color := $00FFDD95
  else
    ABrush.Color := clWhite;

  AFont.Name := 'Segoe UI';
  AFont.Color := clBlack;
  if ARow < 2 then
    AFont.Size := 14
  else
  if (ARow > 3) AND (ACol > 0) then
    AFont.Size := 10
  else
    AFont.Size := 10;
  if (ARow = 0) AND (StatGrid.Cells[ACol, ARow] = 'TODAY') then
      AFont.Style := [fsBold];
end;

procedure TFrmFrontDeskPageButton.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);

  PrepareGridText;
end;

procedure TFrmFrontDeskPageButton.FormDestroy(Sender: TObject);
begin
  try
    ThreadedDataGetter.Free;
  except end;
end;

procedure TFrmFrontDeskPageButton.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  frmMain.FormKeyDown(Sender, Key, Shift);
end;

procedure TFrmFrontDeskPageButton.FormKeyPress(Sender: TObject; var Key: Char);
begin
  frmMain.FormKeyPress(Sender, Key);
end;

procedure TFrmFrontDeskPageButton.FormKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  frmMain.FormKeyUp(Sender, Key, Shift);
end;

/////////////////////////////  HELPERS   //////////////////////////////////////


procedure TFrmFrontDeskPageButton.DrawDateRow;
var
  i: Integer;
begin
  for i := TRUNC(ShowFromDate) to TRUNC(ShowFromDate + 6) do
  begin
    if i = TRUNC(Now) then
      StatGrid.Cells[i - TRUNC(ShowFromDate) + 1, ROW_DAY] := 'TODAY'
    else
      StatGrid.Cells[i - TRUNC(ShowFromDate) + 1, ROW_DAY] := FormatDateTime('ddd', i);
    StatGrid.Cells[i - TRUNC(ShowFromDate) + 1, ROW_DATE] := FormatDateTime('dd mmm', i);
  end;
end;

function TFrmFrontDeskPageButton.GetSenderAsPanel(Sender: TObject) : TsPanel;
begin
  if (Sender IS TsPanel) AND
     ((Sender AS TsPanel).Tag > 0) then
    result := Sender AS TsPanel
  else
  if (Sender AS TControl).Parent.Tag > 0 then
     result := (Sender AS TControl).Parent AS TsPanel
  else
     result := (Sender AS TControl).Parent.Parent AS TsPanel;
end;

function TFrmFrontDeskPageButton.GetShapeComponentOfButton(Sender: TObject) : TShape;
begin
  result := FindComponent('Shape' + inttostr(GetSenderAsPanel(Sender).Tag)) AS TShape;
end;


procedure TFrmFrontDeskPageButton.PrepareGridText;
begin
  StatGrid.Cells[0, ROW_ARRIVALS]     := GetTranslatedText('FrontDeskPage_Arrivals');
  StatGrid.Cells[0, ROW_DEPARTURES]   := GetTranslatedText('FrontDeskPage_Departures');
  StatGrid.Cells[0, ROW_LEFT_TO_SELL] := GetTranslatedText('FrontDeskPage_LeftToSell');
  StatGrid.Cells[0, ROW_OCCUPANCY]    := GetTranslatedText('FrontDeskPage_Occupancy');
  StatGrid.Cells[0, ROW_BAR]          := GetTranslatedText('FrontDeskPage_BAR');
end;

end.
